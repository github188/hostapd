/*
 * hostapd / RADIUS client
 * Copyright (c) 2002-2005, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#include "includes.h"

#include "OssApi.h"
#include "ac_public.h"
#include "ac_devm_public.h"
#include "ac_oma_public.h"
#include "ac_db_proc.h"

#include "hostapd.h"
#include "radius.h"
#include "radius_client.h"
#include "eloop.h"
#include "HostapdSocket.h"
#include "radius_alive.h"
#include "ap.h"
#include "sta_info.h"


/* Defaults for RADIUS retransmit values (exponential backoff) */
#define RADIUS_CLIENT_FIRST_WAIT 2 /* seconds */
#define RADIUS_CLIENT_MAX_WAIT 128 /* seconds */
#define RADIUS_CLIENT_MAX_RETRIES 3 /* maximum number of retransmit attempts
				      * before entry is removed from retransmit
				      * list */
#define RADIUS_CLIENT_MAX_ENTRIES 192 /* maximum number of entries in retransmit
				      * list (oldest will be removed, if this
				      * limit is exceeded) */
#define RADIUS_CLIENT_NUM_FAILOVER 2 /* try to change RADIUS server after this
				      * many failed retry attempts */

/*当g_pstRadiusClient及g_pstRadiusClientSet在应用程序初始化时赋值，在运行过程中其指针值不再被改变*/
struct radius_client_data * g_pstRadiusClient[RADIUS_CLIENT_MAX] = {0} ;
struct radius_client_data * g_pstRadiusClientSet[RADIUS_CLIENT_SET_SIZE][RADIUS_CLIENT_MAX] = {{0}};

u8 g_aucNasIp[4] = {0};
#if 0
/*0：表示未上报告警，或上报告警恢复；1：表示已上报告警*/
static int g_bAlarmMAuth = 0 ;
static int g_bAlarmMAcct = 0 ;
#endif

#if 0
struct radius_rx_handler {
	RadiusRxResult (*handler)(struct radius_msg *msg,
				  struct radius_msg *req,
				  u8 *shared_secret, size_t shared_secret_len,
				  void *data);
	void *data;
};

/* RADIUS message retransmit list */
struct radius_msg_list {
	u8 addr[ETH_ALEN]; /* STA/client address; used to find RADIUS messages
			    * for the same STA. */
	struct radius_msg *msg;
	RadiusType msg_type;
	os_time_t first_try;
	os_time_t next_try;
	int attempts;
	int next_wait;
	struct os_time last_attempt;

	u8 *shared_secret;
	size_t shared_secret_len;

	/* TODO: server config with failover to backup server(s) */

	struct radius_msg_list *next;
};

struct radius_client_data {
	void *ctx;
	struct hostapd_radius_servers *conf;

	int auth_serv_sock; /* socket for authentication RADIUS messages */
	int acct_serv_sock; /* socket for accounting RADIUS messages */
	int auth_serv_sock6;
	int acct_serv_sock6;
	int auth_sock; /* currently used socket */
	int acct_sock; /* currently used socket */

	struct radius_rx_handler *auth_handlers;
	size_t num_auth_handlers;
	struct radius_rx_handler *acct_handlers;
	size_t num_acct_handlers;

	struct radius_msg_list *msgs;
	size_t num_msgs;

	u8 next_radius_identifier;
};
#endif

extern RadiusRxResult hostapd_acl_recv_radius(struct radius_msg *msg, struct radius_msg *req,
			u8 *shared_secret, size_t shared_secret_len,
			void *data) ;
extern RadiusRxResult ieee802_1x_receive_auth(struct radius_msg *msg, struct radius_msg *req,
			u8 *shared_secret, size_t shared_secret_len,
			void *data) ;
extern int can_bind_nasip(VOID);
extern BOOL VmGetLocalPid (CHAR *lpbyPName, TPID *lptPid);
extern VOID ac_db_access(UINT32 ulMsgId, UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
int radius_client_pools_getsetid(AC_DEVM_GET_SSIDRADIUSSERVERS_RSP_T* pstRadiusResp);

static void radius_client_msg_free(struct radius_msg_list *req)
{
	radius_msg_free(req->msg);
	os_free(req->msg);
	os_free(req);
}


int radius_client_register(struct radius_client_data *radius,
			   RadiusType msg_type,
			   RadiusRxResult (*handler)(struct radius_msg *msg,
						     struct radius_msg *req,
						     u8 *shared_secret,
						     size_t shared_secret_len,
						     void *data),
			   void *data)
{
	struct radius_rx_handler **handlers, *newh;
	size_t *num;

	if (msg_type == RADIUS_ACCT) {
		handlers = &radius->acct_handlers;
		num = &radius->num_acct_handlers;
	} else {
		handlers = &radius->auth_handlers;
		num = &radius->num_auth_handlers;
	}

	newh = os_realloc(*handlers,
			  (*num + 1) * sizeof(struct radius_rx_handler));
	if (newh == NULL)
		return -1;

	newh[*num].handler = handler;
	newh[*num].data = data;
	(*num)++;
	*handlers = newh;

	return 0;
}


static int radius_client_handle_send_error(struct radius_client_data *radius,
					    int s, RadiusType msg_type)
{
#ifndef CONFIG_NATIVE_WINDOWS
	int _errno = errno;
	perror("send[RADIUS]");
	if (_errno == ENOTCONN || _errno == EDESTADDRREQ || _errno == EINVAL ||
	    _errno == EBADF) {
		hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_INFO,
			       "Send failed - maybe interface status changed -"
			       " try to connect again");

		if (msg_type == RADIUS_ACCT || msg_type == RADIUS_ACCT_INTERIM)
			radius_client_init_acct(radius, 1);
		else
			radius_client_init_auth(radius, 1);

		return 1 ;
	}
#endif /* CONFIG_NATIVE_WINDOWS */

	return 0 ;
}


/*
返回值：
	0：重传成功；
	1：调用者需删除本entry；
	2：调用者不能再访问radius->msgs链表中的元素；
*/
static int radius_client_retransmit(struct radius_client_data *radius,
				    struct radius_msg_list *entry,
				    os_time_t now)
{
	struct hostapd_radius_servers *conf = NULL ;
	int s, radius_id;

	if((conf = radius->conf) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, no radius servers configued.\n", __func__) ;
		return 1 ;
	}
	
	if (entry->msg_type == RADIUS_ACCT ||
	    entry->msg_type == RADIUS_ACCT_INTERIM) {
		s = radius->acct_sock;
		if (entry->attempts == 0)
			conf->acct_server->requests++;
		else {
			conf->acct_server->timeouts++;
			conf->acct_server->retransmissions++;
		}
		radius_id = radius->acct_id ;
	} else {
		s = radius->auth_sock;
		if (entry->attempts == 0)
			conf->auth_server->requests++;
		else {
			conf->auth_server->timeouts++;
			conf->auth_server->retransmissions++;
		}
		radius_id = radius->auth_id ;
	}

	/* retransmit; remove entry if too many attempts */
	entry->attempts++;
	hostapd_logger(radius->ctx, entry->addr, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "Resending RADIUS message (id=%d)",
		       entry->msg->hdr->identifier);

	os_get_time(&entry->last_attempt);

	entry->next_try = now + entry->next_wait;
#if 1
	entry->next_wait *= 2;
#endif
	if (entry->next_wait > RADIUS_CLIENT_MAX_WAIT)
		entry->next_wait = RADIUS_CLIENT_MAX_WAIT;
	if (entry->attempts >= RADIUS_CLIENT_MAX_RETRIES) {
		printf("Removing un-ACKed RADIUS message due to too many "
		       "failed retransmit attempts\n");
		return 1;
	}

	radius_alive_event(radius_id, entry->msg_type, RADIUS_ALIVE_EVENT_SEND) ;

	if(/*s >= 0 &&*/
		send(s, entry->msg->buf, entry->msg->buf_used, 0) < 0 &&
		radius_client_handle_send_error(radius, s, entry->msg_type)){
		return 2 ;
	}

	//g_stStats.ulRadiusAuthReq++;       /* 2011.4.7 */

	return 0;
}


static void radius_client_timer(void *eloop_ctx, void *timeout_ctx)
{
	struct radius_client_data *radius = eloop_ctx;
	/* struct hostapd_radius_servers *conf = radius->conf; */
	struct os_time now;
	os_time_t first;
	struct radius_msg_list *entry, *prev, *tmp;
	int auth_failover = 0, acct_failover = 0, ret = 0 ;
	/* char abuf[50]; */

	entry = radius->msgs;
	if (!entry)
		return;

	os_get_time(&now);
	first = 0;

	prev = NULL;
	while (entry) {
		if (now.sec >= entry->next_try &&
		    (ret = radius_client_retransmit(radius, entry, now.sec))) {
			if(ret == 2)
				break ;
			
			if (prev)
				prev->next = entry->next;
			else
				radius->msgs = entry->next;

			tmp = entry;
			entry = entry->next;
			radius_client_msg_free(tmp);
			radius->num_msgs--;
			continue;
		}

		if (entry->attempts > RADIUS_CLIENT_NUM_FAILOVER) {
			if (entry->msg_type == RADIUS_ACCT ||
			    entry->msg_type == RADIUS_ACCT_INTERIM)
				acct_failover++;
			else
				auth_failover++;
		}

		if (first == 0 || entry->next_try < first)
			first = entry->next_try;

		prev = entry;
		entry = entry->next;
	}

	if (radius->msgs) {
		if (first < now.sec)
			first = now.sec;
		eloop_cancel_timeout(radius_client_timer, radius, NULL) ;
		eloop_register_timeout(first - now.sec, 0,
				       radius_client_timer, radius, NULL);
		hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_DEBUG, "Next RADIUS client "
			       "retransmit in %ld seconds",
			       (long int) (first - now.sec));
	}
	
#if 0
	if(auth_failover
		&& g_bAlarmMAuth == 0
		&& radius->auth_id == 0){/*上报主用认证服务器断链告警*/
		AC_OMA_MO_T stAcMOID = {0} ;
		
		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, report alarm: master auth server offline.\n", __func__) ;
			ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE, 
				AC_OMA_REASON_AUTHSRV_OFFLINE, 
				AC_OMA_ALARM_LEVEL_FATAL,
				stAcMOID.ulMOC,
				stAcMOID.aucMOI,
				0) ;
			g_bAlarmMAuth = 1 ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, report auth alarm failed: get ac's MOID failed.\n", __func__) ;
		}
	}

	if(acct_failover
		&& g_bAlarmMAcct == 0
		&& radius->acct_id == 0){/*上报主用计费服务器断链告警*/
		AC_OMA_MO_T stAcMOID = {0} ;

		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, report alarm: master acct server offline.\n", __func__) ;
			ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MACCTSRV_OFFLINE, 
				AC_OMA_REASON_MACCTSRV_OFFLINE,
				AC_OMA_ALARM_LEVEL_FATAL,
				stAcMOID.ulMOC,
				stAcMOID.aucMOI,
				0) ;
			g_bAlarmMAcct = 1 ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, report acct alarm failed: get ac's MOID failed.\n", __func__) ;
		}
	}
#endif

#if 0
	if (auth_failover && conf->num_auth_servers > 1) {
		struct hostapd_radius_server *next, *old;
#if 0
		old = conf->auth_server;
#else
		if(radius->auth_id < 0 || radius->auth_id >= conf->num_auth_servers){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, wrong auth_id(%d).\n", __func__, radius->auth_id) ;
			return ;
		}
		old = & (conf->auth_servers[radius->auth_id]) ;
#endif
		hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_NOTICE,
			       "No response from Authentication server "
			       "%s:%d - failover",
			       hostapd_ip_txt(&old->addr, abuf, sizeof(abuf)),
			       old->port);

		for (entry = radius->msgs; entry; entry = entry->next) {
			if (entry->msg_type == RADIUS_AUTH)
				old->timeouts++;
		}

		next = old + 1;
		if (next > &(conf->auth_servers[conf->num_auth_servers - 1]))
			next = conf->auth_servers;
		conf->auth_server = next;
		if(radius_change_server(radius, next, old,
				     radius->auth_serv_sock,
				     radius->auth_serv_sock6, 1) == 0){
			radius->auth_id = (radius->auth_id + 1) % conf->num_auth_servers ;
		}
	}

	if (acct_failover && conf->num_acct_servers > 1) {
		struct hostapd_radius_server *next, *old;
#if 0
		old = conf->acct_server;
#else
		if(radius->acct_id < 0 || radius->acct_id >= conf->num_acct_servers){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, wrong acct_id(%d).\n", __func__, radius->acct_id) ;
			return ;
		}
		old = &(conf->acct_servers[radius->acct_id]) ;
#endif
		hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_NOTICE,
			       "No response from Accounting server "
			       "%s:%d - failover",
			       hostapd_ip_txt(&old->addr, abuf, sizeof(abuf)),
			       old->port);

		for (entry = radius->msgs; entry; entry = entry->next) {
			if (entry->msg_type == RADIUS_ACCT ||
			    entry->msg_type == RADIUS_ACCT_INTERIM)
				old->timeouts++;
		}

		next = old + 1;
		if (next > &conf->acct_servers[conf->num_acct_servers - 1])
			next = conf->acct_servers;
		conf->acct_server = next;
		if(radius_change_server(radius, next, old,
				     radius->acct_serv_sock,
				     radius->acct_serv_sock6, 0) == 0){
			radius->acct_id = (radius->acct_id + 1) % conf->num_acct_servers ;
		}
	}
#endif
}


static void radius_client_update_timeout(struct radius_client_data *radius)
{
	struct os_time now;
	os_time_t first;
	struct radius_msg_list *entry;

	eloop_cancel_timeout(radius_client_timer, radius, NULL);

	if (radius->msgs == NULL) {
		return;
	}

	first = 0;
	for (entry = radius->msgs; entry; entry = entry->next) {
		if (first == 0 || entry->next_try < first)
			first = entry->next_try;
	}

	os_get_time(&now);
	if (first < now.sec)
		first = now.sec;
	eloop_register_timeout(first - now.sec, 0, radius_client_timer, radius,
			       NULL);
	hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "Next RADIUS client retransmit in"
		       " %ld seconds\n", (long int) (first - now.sec));
}


static void radius_client_list_add(struct radius_client_data *radius,
				   struct radius_msg *msg,
				   RadiusType msg_type, u8 *shared_secret,
				   size_t shared_secret_len, const u8 *addr)
{
	struct radius_msg_list *entry, *prev;

	if (eloop_terminated()) {
		/* No point in adding entries to retransmit queue since event
		 * loop has already been terminated. */
		radius_msg_free(msg);
		os_free(msg);
		return;
	}

	entry = wpa_zalloc(sizeof(*entry));
	if (entry == NULL) {
		printf("Failed to add RADIUS packet into retransmit list\n");
		radius_msg_free(msg);
		os_free(msg);
		return;
	}

	if (addr)
		os_memcpy(entry->addr, addr, ETH_ALEN);
	entry->msg = msg;
	entry->msg_type = msg_type;
	entry->shared_secret = shared_secret;
	entry->shared_secret_len = shared_secret_len;
	os_get_time(&entry->last_attempt);
	entry->first_try = entry->last_attempt.sec;
	entry->next_try = entry->first_try + RADIUS_CLIENT_FIRST_WAIT;
	entry->attempts = 1;
#if 1
	entry->next_wait = RADIUS_CLIENT_FIRST_WAIT * 2;
#else
	entry->next_wait = RADIUS_CLIENT_FIRST_WAIT ;
#endif
	entry->next = radius->msgs;
	radius->msgs = entry;
	radius_client_update_timeout(radius);

	if (radius->num_msgs >= RADIUS_CLIENT_MAX_ENTRIES) {
		printf("Removing the oldest un-ACKed RADIUS packet due to "
		       "retransmit list limits.\n");
		prev = NULL;
		while (entry->next) {
			prev = entry;
			entry = entry->next;
		}
		if (prev) {
			prev->next = NULL;
			radius_client_msg_free(entry);
		}
	} else
		radius->num_msgs++;
}


static void radius_client_list_del(struct radius_client_data *radius,
				   RadiusType msg_type, const u8 *addr)
{
	struct radius_msg_list *entry, *prev, *tmp;

	if (addr == NULL)
		return;

	entry = radius->msgs;
	prev = NULL;
	while (entry) {
		if (entry->msg_type == msg_type &&
		    os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
			if (prev)
				prev->next = entry->next;
			else
				radius->msgs = entry->next;
			tmp = entry;
			entry = entry->next;
			hostapd_logger(radius->ctx, addr,
				       HOSTAPD_MODULE_RADIUS,
				       HOSTAPD_LEVEL_DEBUG,
				       "Removing matching RADIUS message");
			radius_client_msg_free(tmp);
			radius->num_msgs--;
			continue;
		}
		prev = entry;
		entry = entry->next;
	}
}


int radius_client_send(struct radius_client_data *radius,
		       struct radius_msg *msg, RadiusType msg_type,
		       const u8 *addr)
{
	struct hostapd_radius_servers *conf = NULL;
	u8 *shared_secret;
	size_t shared_secret_len;
	char *name;
	int s, res = -1 , radius_id;

    if(radius == NULL)
    {
        ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
                    "%s,radius is NULL", __func__) ;
        return -1;


    }
    if((conf = radius->conf) == NULL)
    {
        ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
                           "%s,conf is NULL", __func__) ;

        return  -1;

    }

	if(!radius->auth_bind
		&& can_bind_nasip() == 0)
		radius_client_init_auth(radius, 1);

	if (msg_type == RADIUS_ACCT_INTERIM) {
		/* Remove any pending interim acct update for the same STA. */
		radius_client_list_del(radius, msg_type, addr);
	}

	if (msg_type == RADIUS_ACCT || msg_type == RADIUS_ACCT_INTERIM) {
		if (conf->acct_server == NULL) {
			hostapd_logger(radius->ctx, NULL,
				       HOSTAPD_MODULE_RADIUS,
				       HOSTAPD_LEVEL_INFO,
				       "No accounting server configured");
			return -1;
		}
		shared_secret = conf->acct_server->shared_secret;
		shared_secret_len = conf->acct_server->shared_secret_len;
		radius_msg_finish_acct(msg, shared_secret, shared_secret_len);
		name = "accounting";
		s = radius->acct_sock;
		conf->acct_server->requests++;
		radius_id = radius->acct_id ;
	} else {
		if (conf->auth_server == NULL) {
			hostapd_logger(radius->ctx, NULL,
				       HOSTAPD_MODULE_RADIUS,
				       HOSTAPD_LEVEL_INFO,
				       "No authentication server configured");
			return -1;
		}
		shared_secret = conf->auth_server->shared_secret;
		shared_secret_len = conf->auth_server->shared_secret_len;
		if(radius->radius_type == RADIUS_TYPE_FOR_PPP)
			radius_msg_finish(msg, NULL, 0);
		else
			radius_msg_finish(msg, shared_secret, shared_secret_len);
		name = "authentication";
		s = radius->auth_sock;
		conf->auth_server->requests++;
		//if(radius->radius_type != RADIUS_TYPE_FOR_ALIVE)     /*2011.4.7*/
		//	g_stStats.ulRadiusAuthReq ++;
		radius_id = radius->auth_id ;
	}

	hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "Sending RADIUS message to %s "
		       "server", name);
#ifndef OSS_LOG
	if (conf->msg_dumps)
		radius_msg_dump(msg);
#else
	radius_msg_dump(msg);
#endif

	//if(s >= 0){
		res = send(s, msg->buf, msg->buf_used, 0);
		if (res < 0)
			radius_client_handle_send_error(radius, s, msg_type);
	//}

	radius_client_list_add(radius, msg, msg_type, shared_secret,
			       shared_secret_len, addr);

	radius_alive_event(radius_id, msg_type, RADIUS_ALIVE_EVENT_SEND) ;
	
	return res;
}

static void radius_client_receive(int sock, void *eloop_ctx, void *sock_ctx)
{
#define RECEIVE_LEN_RESERVE (6*(sizeof(HOSTAPD_ELEM_T)+sizeof(u32))+sizeof(HOSTAPD_ELEM_T))
	unsigned char buf[RECEIVE_LEN_RESERVE+3000] = {0} ;
	int len = 0;
	HOSTAPD_ELEM_T * pElem = NULL ;
	TPID tReceiver = {0} ;
	struct radius_client_data *radius = NULL;
	struct hostapd_data * pstBss = NULL ;

	if((radius = eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, radius is NULL.\n", __func__) ;
		return ;
	}
    

	pElem = (HOSTAPD_ELEM_T *)buf ;

	/*设置网络数据包*/
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_DATA ;
	len = recv(sock, & pElem[1], 3000, MSG_DONTWAIT);
	if (len < 0) {
		perror("recv[RADIUS]");
		return;
	}
#if 0
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
		"%s, recv data: %d.\n", __func__, len) ;
#endif
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + len ;
	pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
	
	/*设置eloop_ctx地址*/
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_ELOOP ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + sizeof(eloop_ctx) ;
	* ((unsigned long *)(pElem + 1)) = (unsigned long)eloop_ctx ;
	pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;

	/*设置sock_ctx*/
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_USER ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + sizeof(sock_ctx) ;
	* ((unsigned long *)(pElem + 1)) = (unsigned long)sock_ctx ;
	pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;

	/*设置RADIUS CLIENT TYPE*/
	pElem->dwElemId = HOSTAPD_ELEMID_COMMON_RADIUSTYPE ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
	* ((unsigned long *)(pElem + 1)) = radius->radius_type ;
	pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
	
	switch(radius->radius_type){
	case RADIUS_TYPE_FOR_VAP:
		if((pstBss = radius->ctx) == NULL ||
			pstBss->iface == NULL ||
			pstBss->iface->pstWtp == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
				"%s, raiuds->ctx, point is NULL.\n", __func__) ;
			return ;
		}
			
		/*设置WTP ID,if wtp_id == 0, then radius client is radius alive*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_WTPID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		* ((unsigned long *)(pElem + 1)) = (unsigned long)(pstBss->iface->pstWtp->usWtpId) ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
		
		/*设置IF ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_IFID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		* ((unsigned long *)(pElem + 1)) = pstBss->iface->interface_id ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;

		/*设置VAP ID */
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_VAPID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		* ((unsigned long *)(pElem + 1)) = pstBss->vap_id ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
		
		break ;
	case RADIUS_TYPE_FOR_ALIVE:
		/*设置RADIUS AUTH ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_AUTHID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		* ((long *)(pElem + 1)) = radius->auth_id ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;

		/*设置RADIUS ACCT ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_ACCTID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		* ((long *)(pElem + 1)) = radius->acct_id ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
	
		break ;
	case RADIUS_TYPE_FOR_PPP:
		/*设置RADIUS SET ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_RADIUSSETID;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4;
		os_memcpy(&pElem[1], &radius->radius_setid, 4);
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength);
		
		break ;
	case RADIUS_TYPE_FOR_POOL:
		/*设置RADIUS SET ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_RADIUSSETID;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4;
		os_memcpy(&pElem[1], &radius->radius_setid, 4);
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength);
		
		/*设置RADIUS POOL ID*/
		pElem->dwElemId = HOSTAPD_ELEMID_COMMON_RADIUSPOOLID ;
		pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + 4 ;
		os_memcpy(& pElem[1], & radius->radius_poolid, 4) ;
		pElem = (HOSTAPD_ELEM_T *)((unsigned char *)pElem + pElem->dwLength) ;
		
		break ;
	default:
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN, 
			"%s, unknown radius_type(%d).\n", __func__, radius->radius_type) ;
		return ;
	}

	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
			"%s, get local pid failed.\n", __func__) ;
		return  ;
	}

	if(pstBss && ! pstBss->setuped){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
			"%s, vap(%u/%u/%u) is being cleaned up\n", 
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;
		return ;
	}
		
	if(! VmASend(EV_HOSTAPD_SOCKET_RADIUS, buf, (unsigned char *)pElem-buf,  tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
			"%s, send socket_radius failed.\n", __func__) ;
		return ;
	}

	return ;
#undef RECEIVE_LEN_RESERVE
}

void radius_client_receiveA(void *eloop_ctx, void *sock_ctx, u8 * pRadiusData, int iRadiusDataLen)
{
	struct radius_client_data *radius = NULL ;
	struct hostapd_radius_servers *conf = NULL ;
	RadiusType msg_type = (RadiusType) sock_ctx;
	int roundtrip;
	struct radius_msg *msg;
	struct radius_rx_handler *handlers;
	size_t num_handlers, i;
	struct radius_msg_list *req, *prev_req;
	struct os_time now;
	struct hostapd_radius_server *rconf;
	int invalid_authenticator = 0, radius_id;
	void * data = NULL ;

	if((radius = eloop_ctx) == NULL
		|| (conf = radius->conf) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	if (msg_type == RADIUS_ACCT) {
		handlers = radius->acct_handlers;
		num_handlers = radius->num_acct_handlers;
		rconf = conf->acct_server;
		radius_id = radius->acct_id ;
	} else {
		handlers = radius->auth_handlers;
		num_handlers = radius->num_auth_handlers;
		rconf = conf->auth_server;
		radius_id = radius->auth_id ;
	}

	if(rconf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, no radius server(%d) configued.\n", __func__, msg_type) ;
		return ;
	}
	
#if 0
	len = recv(sock, buf, sizeof(buf), MSG_DONTWAIT);
	if (len < 0) {
		perror("recv[RADIUS]");
		return;
	}
#else
	if(pRadiusData == NULL || iRadiusDataLen < 0 || iRadiusDataLen >= 3000){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point(%p) is NULL, or iRadiusDataLen(%d) is invalid.\n", 
			__func__, pRadiusData, iRadiusDataLen) ;
		return ;
	}
#endif

	hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "Received %d bytes from RADIUS "
		       "server", iRadiusDataLen);

	msg = radius_msg_parse(pRadiusData, iRadiusDataLen);
	if (msg == NULL) {
		printf("Parsing incoming RADIUS frame failed\n");
		rconf->malformed_responses++;
		return;
	}

	hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "Received RADIUS message");
#ifndef OSS_LOG
	if (conf->msg_dumps)
		radius_msg_dump(msg);
#else
	radius_msg_dump(msg);
#endif

	switch (msg->hdr->code) {
	case RADIUS_CODE_ACCESS_ACCEPT:
		rconf->access_accepts++;
		break;
	case RADIUS_CODE_ACCESS_REJECT:
		rconf->access_rejects++;
		break;
	case RADIUS_CODE_ACCESS_CHALLENGE:
		rconf->access_challenges++;
		break;
	case RADIUS_CODE_ACCOUNTING_RESPONSE:
		rconf->responses++;
		break;
	}

	prev_req = NULL;
	req = radius->msgs;
	while (req) {
		/* TODO: also match by src addr:port of the packet when using
		 * alternative RADIUS servers (?) */
		if ((req->msg_type == msg_type ||
		     (req->msg_type == RADIUS_ACCT_INTERIM &&
		      msg_type == RADIUS_ACCT)) &&
		    req->msg->hdr->identifier == msg->hdr->identifier)
			break;

		prev_req = req;
		req = req->next;
	}

	if (req == NULL) {
		hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_DEBUG,
			       "No matching RADIUS request found (type=%d "
			       "id=%d) - dropping packet",
			       msg_type, msg->hdr->identifier);
		goto fail;
	}

   /****************************************************************

	if(msg->hdr->code != RADIUS_CODE_ACCOUNTING_RESPONSE
		&& radius->radius_type != RADIUS_TYPE_FOR_ALIVE){
		g_stStats.ulRadiusAuthResp ++;    
		if(msg->hdr->code == RADIUS_CODE_ACCESS_ACCEPT)
			g_stStats.ulRadiusAuthSucc ++;
	}

            2011.4.6 , chary, 浙江移动MIB测试
*******************************************************************/
	
#if 0
	if(g_bAlarmMAuth == 1
		&& msg_type == RADIUS_AUTH
		&& radius->auth_id == 0
		&& ! req->server_changed){/*主用认证服务器断链告警恢复*/
		AC_OMA_MO_T stAcMOID = {0} ;

		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, clear alarm: master auth server offline.\n", __func__) ;
			ac_db_oam_clear_alarm(AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE, stAcMOID.ulMOC, stAcMOID.aucMOI) ;	
			g_bAlarmMAuth = 0 ;
			
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, clear auth alarm failed: get ac's MOID failed.\n", __func__) ;
		}
	}

	if(g_bAlarmMAcct == 1
		&& msg_type != RADIUS_AUTH
		&& radius->acct_id == 0
		&& ! req->server_changed){/*主用计费服务器断链告警恢复*/
		AC_OMA_MO_T stAcMOID = {0} ;

		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, clear alarm: master acct server offline.\n", __func__) ;
			ac_db_oam_clear_alarm(AC_OMA_ALARM_ID_MACCTSRV_OFFLINE, stAcMOID.ulMOC, stAcMOID.aucMOI) ;
			g_bAlarmMAcct = 0 ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, clear acct alarm failed: get ac's MOID failed.\n", __func__) ;
		}
	}
#else
	radius_alive_event(radius_id, msg_type, RADIUS_ALIVE_EVENT_RECV) ;
#endif

	os_get_time(&now);
	roundtrip = (now.sec - req->last_attempt.sec) * 100 +
		(now.usec - req->last_attempt.usec) / 10000;
	hostapd_logger(radius->ctx, req->addr, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG,
		       "Received RADIUS packet matched with a pending "
		       "request, round trip time %d.%02d sec",
		       roundtrip / 100, roundtrip % 100);
	rconf->round_trip_time = roundtrip;

	/* Remove ACKed RADIUS packet from retransmit list */
	if (prev_req)
		prev_req->next = req->next;
	else
		radius->msgs = req->next;
	radius->num_msgs--;

	if(radius->radius_type == RADIUS_TYPE_FOR_POOL){
		struct sta_info * sta = NULL ;

		if((sta = global_sta_get(req->addr)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
				"%s, can not find sta("MACSTR") for radius req msg(%d).\n", 
				__func__, MAC2STR(req->addr), req->msg->hdr->identifier) ;
			radius_client_msg_free(req);
			goto fail ; 
		}

		data = sta->ctx ;
	}
	for (i = 0; i < num_handlers; i++) {
		RadiusRxResult res;
		res = handlers[i].handler(msg, req->msg, req->shared_secret,
					  req->shared_secret_len,
					  radius->radius_type == RADIUS_TYPE_FOR_POOL ? data : handlers[i].data);
		switch (res) {
		case RADIUS_RX_PROCESSED:
			radius_msg_free(msg);
			os_free(msg);
			/* continue */
		case RADIUS_RX_QUEUED:
			radius_client_msg_free(req);
			return;
		case RADIUS_RX_INVALID_AUTHENTICATOR:
			invalid_authenticator++;
			/* continue */
		case RADIUS_RX_UNKNOWN:
			/* continue with next handler */
			break;
		}
	}

	if (invalid_authenticator)
		rconf->bad_authenticators++;
	else
		rconf->unknown_types++;
	hostapd_logger(radius->ctx, req->addr, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_DEBUG, "No RADIUS RX handler found "
		       "(type=%d code=%d id=%d)%s - dropping packet",
		       msg_type, msg->hdr->code, msg->hdr->identifier,
		       invalid_authenticator ? " [INVALID AUTHENTICATOR]" :
		       "");
	radius_client_msg_free(req);

 fail:
	radius_msg_free(msg);
	os_free(msg);
}


u8 radius_client_get_id(struct radius_client_data *radius)
{
	struct radius_msg_list *entry, *prev, *_remove;
	u8 id = radius->next_radius_identifier++;

	/* remove entries with matching id from retransmit list to avoid
	 * using new reply from the RADIUS server with an old request */
	entry = radius->msgs;
	prev = NULL;
	while (entry) {
		if (entry->msg->hdr->identifier == id) {
			hostapd_logger(radius->ctx, entry->addr,
				       HOSTAPD_MODULE_RADIUS,
				       HOSTAPD_LEVEL_DEBUG,
				       "Removing pending RADIUS message, "
				       "since its id (%d) is reused", id);
			if (prev)
				prev->next = entry->next;
			else
				radius->msgs = entry->next;
			_remove = entry;
		} else {
			_remove = NULL;
			prev = entry;
		}
		entry = entry->next;

		if (_remove)
			radius_client_msg_free(_remove);
	}

	return id;
}


void radius_client_flush(struct radius_client_data *radius, int only_auth)
{
	struct radius_msg_list *entry, *prev, *tmp;

	if (!radius)
		return;

	prev = NULL;
	entry = radius->msgs;

	while (entry) {
		if (!only_auth || entry->msg_type == RADIUS_AUTH) {
			if (prev)
				prev->next = entry->next;
			else
				radius->msgs = entry->next;

			tmp = entry;
			entry = entry->next;
			radius_client_msg_free(tmp);
			radius->num_msgs--;
		} else {
			prev = entry;
			entry = entry->next;
		}
	}

	if (radius->msgs == NULL)
		eloop_cancel_timeout(radius_client_timer, radius, NULL);
}


void radius_client_update_acct_msgs(struct radius_client_data *radius,
				    u8 *shared_secret,
				    size_t shared_secret_len)
{
	struct radius_msg_list *entry;

	if (!radius)
		return;

	for (entry = radius->msgs; entry; entry = entry->next) {
		if (entry->msg_type == RADIUS_ACCT) {
			entry->shared_secret = shared_secret;
			entry->shared_secret_len = shared_secret_len;
			radius_msg_finish_acct(entry->msg, shared_secret,
					       shared_secret_len);
		}
	}
}


int
radius_change_server(struct radius_client_data *radius,
		     struct hostapd_radius_server *nserv,
		     struct hostapd_radius_server *oserv,
		     int sock, int sock6, int auth)
{
	struct sockaddr_in serv;
#ifdef CONFIG_IPV6
	struct sockaddr_in6 serv6;
#endif /* CONFIG_IPV6 */
	struct sockaddr *addr;
	socklen_t addrlen;
	char abuf[50];
	int sel_sock;
	struct radius_msg_list *entry;

    
    if(radius == NULL)
    {
       ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
                 "%s,radius is NULL,return\n", __func__) ;
        return -1;
    }
    if(nserv == NULL)
    {
        ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
                      "%s,nserv is NULL,return\n", __func__) ;
    
        return -1;
    
    }

	hostapd_logger(radius->ctx, NULL, HOSTAPD_MODULE_RADIUS,
		       HOSTAPD_LEVEL_INFO,
		       "%s server %s:%d",
		       auth ? "Authentication" : "Accounting",
		       hostapd_ip_txt(&nserv->addr, abuf, sizeof(abuf)),
		       nserv->port);

	if (!oserv || nserv->shared_secret_len != oserv->shared_secret_len ||
	    os_memcmp(nserv->shared_secret, oserv->shared_secret,
		      nserv->shared_secret_len) != 0) {
		/* Pending RADIUS packets used different shared secret, so
		 * they need to be modified. Update accounting message
		 * authenticators here. Authentication messages are removed
		 * since they would require more changes and the new RADIUS
		 * server may not be prepared to receive them anyway due to
		 * missing state information. Client will likely retry
		 * authentication, so this should not be an issue. */
		if (auth)
			radius_client_flush(radius, 1);
		else {
			radius_client_update_acct_msgs(
				radius, nserv->shared_secret,
				nserv->shared_secret_len);
		}
	}

	/* Reset retry counters for the new server */
	for (entry = radius->msgs; entry; entry = entry->next) {
		if ((auth && entry->msg_type != RADIUS_AUTH) ||
		    (!auth && entry->msg_type != RADIUS_ACCT))
			continue;
		//entry->next_try = entry->first_try + RADIUS_CLIENT_FIRST_WAIT;
		entry->attempts = 0;
#if 1
		entry->next_wait = RADIUS_CLIENT_FIRST_WAIT * 2;
#else
		entry->next_wait = RADIUS_CLIENT_FIRST_WAIT ;
#endif
		entry->server_changed = 1 ;
	}

	if (radius->msgs) {
		eloop_cancel_timeout(radius_client_timer, radius, NULL);
		eloop_register_timeout(RADIUS_CLIENT_FIRST_WAIT, 0,
				       radius_client_timer, radius, NULL);
	}

	if(auth)
		radius->auth_id = nserv->index ;
	else
		radius->acct_id = nserv->index ;

	switch (nserv->addr.af) {
	case AF_INET:
		os_memset(&serv, 0, sizeof(serv));
		serv.sin_family = AF_INET;
		serv.sin_addr.s_addr = nserv->addr.u.v4.s_addr;
		serv.sin_port = htons(nserv->port);
		addr = (struct sockaddr *) &serv;
		addrlen = sizeof(serv);
		sel_sock = sock;
		break;
#ifdef CONFIG_IPV6
	case AF_INET6:
		os_memset(&serv6, 0, sizeof(serv6));
		serv6.sin6_family = AF_INET6;
		os_memcpy(&serv6.sin6_addr, &nserv->addr.u.v6,
			  sizeof(struct in6_addr));
		serv6.sin6_port = htons(nserv->port);
		addr = (struct sockaddr *) &serv6;
		addrlen = sizeof(serv6);
		sel_sock = sock6;
		break;
#endif /* CONFIG_IPV6 */
	default:
		return -1;
	}

	if (connect(sel_sock, addr, addrlen) < 0) {
		perror("connect[radius]");

		if(auth)
			radius->auth_sock = -1;
		else
			radius->acct_sock = -1;
	
		return -1;
	}

#if 0
	if (auth){
		AC_OMA_MO_T stAcMOID = {0} ;
		
		radius->auth_sock = sel_sock;
		
		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_FAIL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, get ac's MOID failed.\n", __func__) ;
			return -1 ;
		}

		if(nserv == radius->conf->auth_servers
			&& g_bAlarmMAuth == 1){/*与主用认证服务器断链告警恢复*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, clear alarm: master auth server offline.\n", __func__) ;
			g_bAlarmMAuth = 0 ;
			ac_db_oam_clear_alarm(AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE, stAcMOID.ulMOC, stAcMOID.aucMOI) ;		
		}
		else if(nserv != radius->conf->auth_servers
			&& g_bAlarmMAuth == 0){/*与主用认证服务器断链告警产生*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, report alarm: master auth server offline.\n", __func__) ;
			g_bAlarmMAuth = 1 ;
			ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE, 
				AC_OMA_REASON_AUTHSRV_OFFLINE, 
				AC_OMA_ALARM_LEVEL_MAIN,
				stAcMOID.ulMOC,
				stAcMOID.aucMOI,
				0) ;
			
		}
	}
	else{
		AC_OMA_MO_T stAcMOID = {0} ;
		
		radius->acct_sock = sel_sock;

		if(ac_db_oam_get_acmoid(&stAcMOID) == AC_FAIL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, get ac's MOID failed.\n", __func__) ;
			return -1 ;
		}
		
		if(nserv == radius->conf->acct_servers
			&& g_bAlarmMAcct == 1){/*与主用计费服务器断链告警恢复*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, clear alarm: master acct server offline.\n", __func__) ;
			g_bAlarmMAcct = 0 ;
			ac_db_oam_clear_alarm(AC_OMA_ALARM_ID_MACCTSRV_OFFLINE, stAcMOID.ulMOC, stAcMOID.aucMOI) ;
		}
		else if(nserv != radius->conf->acct_servers
			&& g_bAlarmMAcct == 0){/*与主用计费服务器断链告警产生*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, report alarm: master acct server offline.\n", __func__) ;
			g_bAlarmMAcct = 1 ;
			ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MACCTSRV_OFFLINE, 
				AC_OMA_REASON_MACCTSRV_OFFLINE,
				AC_OMA_ALARM_LEVEL_MAIN,
				stAcMOID.ulMOC,
				stAcMOID.aucMOI,
				0) ;
		}
	}
#else
	if(auth){
		radius->auth_sock = sel_sock;
	}
	else{
		radius->acct_sock = sel_sock;
	}
#endif

	return 0;
}


int radius_change_server_global(struct hostapd_radius_server *nserv, struct hostapd_radius_server *oserv,int auth)
{
	struct radius_client_data * pstRadiusClient = NULL ;
	char buf1[50], buf2[50] ;
	int sock, sock6, i, j, k, error = 0 ;

	if(nserv == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	for(i = 0 ; i < MAX_WTPS ; i ++)
		for(j = 0 ; g_pstWtpTable[i] && j < MAX_INTERFACES ; j ++)
			for(k = 0 ; g_pstWtpTable[i]->iface[j] && k < MAX_BSSES ; k ++){
				if(g_pstWtpTable[i]->iface[j]->bss[k] == NULL
					|| (pstRadiusClient = g_pstWtpTable[i]->iface[j]->bss[k]->radius) == NULL)
					continue ;

				if(auth){
					sock = pstRadiusClient->auth_serv_sock ;
					sock6 = pstRadiusClient->auth_serv_sock6 ;
				}
				else{
					sock = pstRadiusClient->acct_serv_sock ;
					sock6 = pstRadiusClient->acct_serv_sock6 ;
				}
				
				if(radius_change_server(pstRadiusClient, nserv, oserv, sock, sock6, auth) != 0){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
						"%s, change %s server from %s:%u to %s:%u for vap(%u/%u/%u) failed.\n",
						__func__, auth ? "AUTH" : "ACCT",  
						oserv ? hostapd_ip_txt(& oserv->addr, buf1, sizeof(buf1)) : "NULL", oserv ? oserv->port : 0, 
						hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port,
						g_pstWtpTable[i]->usWtpId, g_pstWtpTable[i]->iface[j]->interface_id, g_pstWtpTable[i]->iface[j]->bss[k]->vap_id) ;
					error ++ ;
				}
#if 0
				else{
					if(auth)
						pstRadiusClient->auth_id = nserv->index ;
					else
						pstRadiusClient->acct_id = nserv->index ;
				}	
#endif
			}

	return error ;
}


#if 0
void radius_retry_primary_timer(void *eloop_ctx, void *timeout_ctx)
{
	struct radius_client_data *radius = eloop_ctx;
	struct hostapd_radius_servers *conf = radius->conf;
	struct hostapd_radius_server *oserv;

	if (radius->auth_sock >= 0 && conf->auth_servers &&
	    conf->auth_server != conf->auth_servers) {
		oserv = conf->auth_server;
		conf->auth_server = conf->auth_servers;
		radius_change_server(radius, conf->auth_server, oserv,
				     radius->auth_serv_sock,
				     radius->auth_serv_sock6, 1);
	}

	if (radius->acct_sock >= 0 && conf->acct_servers &&
	    conf->acct_server != conf->acct_servers) {
		oserv = conf->acct_server;
		conf->acct_server = conf->acct_servers;
		radius_change_server(radius, conf->acct_server, oserv,
				     radius->acct_serv_sock,
				     radius->acct_serv_sock6, 0);
	}

	if (conf->retry_primary_interval)
		eloop_register_timeout(conf->retry_primary_interval, 0,
				       radius_retry_primary_timer, radius,
				       NULL);
}
#else
void radius_retry_primary_timer(void *eloop_ctx, void *timeout_ctx)
{
#if 0
	struct radius_client_data *radius = eloop_ctx;
	struct hostapd_radius_servers *conf = radius->conf;
	struct hostapd_radius_server *oserv;

	if (radius->auth_sock >= 0 && conf->auth_servers && radius->auth_id != 0) {
		oserv = conf->auth_server;
		conf->auth_server = conf->auth_servers;
		if(radius_change_server(radius, conf->auth_server, oserv,
				     radius->auth_serv_sock,
				     radius->auth_serv_sock6, 1) == 0){
			radius->auth_id = 0 ;
		}
	}

	if (radius->acct_sock >= 0 && conf->acct_servers && radius->acct_id != 0) {
		oserv = conf->acct_server;
		conf->acct_server = conf->acct_servers;
		if(radius_change_server(radius, conf->acct_server, oserv,
				     radius->acct_serv_sock,
				     radius->acct_serv_sock6, 0) == 0){
			radius->acct_id = 0 ;
		}
	}

	if (conf->retry_primary_interval)
		eloop_register_timeout(conf->retry_primary_interval, 0,
				       radius_retry_primary_timer, radius,
				       NULL);
#endif
}
#endif


int can_bind_nasip()
{
	struct sockaddr_in nas_addr = {0};
	struct sockaddr * addr = (struct sockaddr *)&nas_addr;
	int s = -1, ret;

	s = socket(PF_INET, SOCK_DGRAM, 0);
	if(s < 0)
		return -1;

	nas_addr.sin_family = AF_INET;
	os_memcpy(&nas_addr.sin_addr, g_aucNasIp, sizeof(g_aucNasIp));
	ret = bind(s, addr, sizeof(struct sockaddr));
	
	close(s);

	return ret;
}

int radius_client_bind(struct radius_client_data *radius)
{	
	struct sockaddr_in nas_addr = {0};
	struct sockaddr * addr = (struct sockaddr *)&nas_addr;
	int ret = 0;

	if(radius == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__);
		return -1;
	}

	if(radius->auth_bind)
		return 0;
	
	nas_addr.sin_family = AF_INET;
	os_memcpy(&nas_addr.sin_addr, g_aucNasIp, sizeof(g_aucNasIp));
	ret = bind(radius->auth_serv_sock, addr, sizeof(struct sockaddr));
	if(ret == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
			"%s, bind "IPSTR" success.\n", __func__, IP2STR(g_aucNasIp));
		radius->auth_bind = 1;
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, bind "IPSTR" failed.\n", __func__, IP2STR(g_aucNasIp));
	}

	return ret;
}


int radius_client_init_auth(struct radius_client_data *radius, int keep_old)
{
	struct hostapd_radius_servers *conf = radius->conf;
	int ok = 0, auth_id_old = -1 ;

	if(conf == NULL)
		return -1;
	
	if(keep_old)
		auth_id_old = radius->auth_id ;

	radius->auth_bind = 0;
	if(radius->auth_serv_sock >= 0){
		eloop_unregister_read_sock(radius->auth_serv_sock) ;
		close(radius->auth_serv_sock) ;
		radius->auth_sock = radius->auth_serv_sock = -1 ;
		radius->auth_id = -1 ;
	}
	
	radius->auth_serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (radius->auth_serv_sock < 0)
		perror("socket[PF_INET,SOCK_DGRAM]");
	else
		ok++;

#ifdef CONFIG_IPV6
	if(radius->auth_serv_sock6 >= 0){
		eloop_unregister_read_sock(radius->auth_serv_sock6) ;
		close(radius->auth_serv_sock6) ;
		radius->auth_sock = radius->auth_serv_sock6 = -1 ;
		radius->auth_id = -1 ;
	}

	radius->auth_serv_sock6 = socket(PF_INET6, SOCK_DGRAM, 0);
	if (radius->auth_serv_sock6 < 0)
		perror("socket[PF_INET6,SOCK_DGRAM]");
	else
		ok++;
#endif /* CONFIG_IPV6 */

	if (ok == 0)
		return -1;

	radius_client_bind(radius);
#if 0
	if(radius_change_server(radius, conf->auth_server, NULL,
			     radius->auth_serv_sock, radius->auth_serv_sock6,
			     1) == 0){
		radius->auth_id = 0 ;
	}
#else
	if(keep_old && 
		auth_id_old != -1 && auth_id_old < conf->num_auth_servers)
		radius_change_server(radius, & conf->auth_servers[auth_id_old], NULL, radius->auth_serv_sock, radius->auth_serv_sock6, 1) ;
	else
		radius_change_server(radius, conf->auth_server, NULL, radius->auth_serv_sock, radius->auth_serv_sock6, 1) ;
#endif

	if (radius->auth_serv_sock >= 0 &&
	    eloop_register_read_sock(radius->auth_serv_sock,
				     radius_client_receive, radius,
				     (void *) RADIUS_AUTH)) {
		printf("Could not register read socket for authentication "
		       "server\n");
		close(radius->auth_serv_sock) ;
		radius->auth_sock = radius->auth_serv_sock = -1 ;
		radius->auth_id = -1 ;
		return -1;
	}

#ifdef CONFIG_IPV6
	if (radius->auth_serv_sock6 >= 0 &&
	    eloop_register_read_sock(radius->auth_serv_sock6,
				     radius_client_receive, radius,
				     (void *) RADIUS_AUTH)) {
		printf("Could not register read socket for authentication "
		       "server\n");
		close(radius->auth_serv_sock) ;
		radius->auth_sock = radius->auth_serv_sock = -1 ;
		radius->auth_id = -1 ;
		return -1;
	}
#endif /* CONFIG_IPV6 */

	return 0;
}


int radius_client_init_acct(struct radius_client_data *radius, int keep_old)
{
	struct hostapd_radius_servers *conf = radius->conf;
	int ok = 0, acct_id_old = -1;

	if(keep_old)
		acct_id_old = radius->acct_id ;

	if(radius->acct_serv_sock >= 0){
		eloop_unregister_read_sock(radius->acct_serv_sock) ;
		close(radius->acct_serv_sock) ;
		radius->acct_sock = radius->acct_serv_sock = -1 ;
		radius->acct_id = -1 ;
	}
	
	radius->acct_serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (radius->acct_serv_sock < 0)
		perror("socket[PF_INET,SOCK_DGRAM]");
	else
		ok++;

#ifdef CONFIG_IPV6
	if(radius->acct_serv_sock6 >= 0){
		eloop_unregister_read_sock(radius->acct_serv_sock6) ;
		close(radius->acct_serv_sock6) ;
		radius->acct_sock = radius->acct_serv_sock6 = -1 ;
		radius->acct_id = -1 ;
	}
	
	radius->acct_serv_sock6 = socket(PF_INET6, SOCK_DGRAM, 0);
	if (radius->acct_serv_sock6 < 0)
		perror("socket[PF_INET6,SOCK_DGRAM]");
	else
		ok++;
#endif /* CONFIG_IPV6 */

	if (ok == 0)
		return -1;
#if 0
	if(radius_change_server(radius, conf->acct_server, NULL,
			     radius->acct_serv_sock, radius->acct_serv_sock6,
			     0) == 0){
		radius->acct_id = 0 ;
	}
#else
	if(keep_old &&
		acct_id_old != -1 && acct_id_old < conf->num_acct_servers)
		radius_change_server(radius, & conf->acct_servers[acct_id_old], NULL, radius->acct_serv_sock, radius->acct_serv_sock6, 0) ;
	else
		radius_change_server(radius, conf->acct_server, NULL, radius->acct_serv_sock, radius->acct_serv_sock6, 0) ;
#endif

	if (radius->acct_serv_sock >= 0 &&
	    eloop_register_read_sock(radius->acct_serv_sock,
				     radius_client_receive, radius,
				     (void *) RADIUS_ACCT)) {
		printf("Could not register read socket for accounting "
		       "server\n");
		close(radius->acct_serv_sock) ;
		radius->acct_sock = radius->acct_serv_sock = -1 ;
		radius->acct_id = -1 ;
		return -1;
	}

#ifdef CONFIG_IPV6
	if (radius->acct_serv_sock6 >= 0 &&
	    eloop_register_read_sock(radius->acct_serv_sock6,
				     radius_client_receive, radius,
				     (void *) RADIUS_ACCT)) {
		printf("Could not register read socket for accounting "
		       "server\n");
		close(radius->acct_serv_sock6) ;
		radius->acct_sock = radius->acct_serv_sock6 = -1 ;
		radius->acct_id = -1 ;
		return -1;
	}
#endif /* CONFIG_IPV6 */

	return 0;
}


struct radius_client_data *
radius_client_init(void *ctx, struct hostapd_radius_servers *conf, u32 type)
{
	struct radius_client_data *radius;

	if(conf == NULL ||
		type >= RADIUS_TYPE_MAX){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, or type(%d) is invalid.\n.\n", __func__, type) ;
		return NULL ;
	}
	
	radius = wpa_zalloc(sizeof(struct radius_client_data));
	if (radius == NULL)
		return NULL;

	radius->ctx = ctx;
	radius->conf = conf;
	radius->auth_serv_sock = radius->acct_serv_sock =
		radius->auth_serv_sock6 = radius->acct_serv_sock6 =
		radius->auth_sock = radius->acct_sock = -1;
	radius->auth_id = radius->acct_id = -1 ;
	radius->radius_type = type ;

	if (conf->auth_server && radius_client_init_auth(radius, 0)) {
		radius_client_deinit(radius);
		return NULL;
	}

	if (conf->acct_server && radius_client_init_acct(radius, 0)) {
		radius_client_deinit(radius);
		return NULL;
	}

	if (conf->retry_primary_interval)
		eloop_register_timeout(conf->retry_primary_interval, 0,
				       radius_retry_primary_timer, radius,
				       NULL);

	return radius;
}


void radius_client_deinit(struct radius_client_data *radius)
{
	if (!radius)
		return;

	if (radius->auth_serv_sock >= 0){
		eloop_unregister_read_sock(radius->auth_serv_sock);
		close(radius->auth_serv_sock) ;
		radius->auth_sock = radius->auth_serv_sock = -1 ;
	}
	if (radius->acct_serv_sock >= 0){
		eloop_unregister_read_sock(radius->acct_serv_sock);
		close(radius->acct_serv_sock) ;
		radius->acct_sock = radius->acct_serv_sock = -1 ;
	}

#ifdef CONFIG_IPV6
	if(radius->auth_serv_sock6 >= 0){
		eloop_unregister_read_sock(radius->auth_serv_sock6) ;
		close(radius->auth_serv_sock6) ;
		radius->auth_sock = radius->auth_serv_sock6 = -1 ;
	}
	if(radius->acct_serv_sock6 >= 0){
		eloop_unregister_read_sock(radius->acct_serv_sock6) ;
		close(radius->acct_serv_sock6) ;
		radius->acct_sock = radius->acct_serv_sock6 = -1 ;
	}
#endif

	eloop_cancel_timeout(radius_retry_primary_timer, radius, NULL);

	radius_client_flush(radius, 0);
	os_free(radius->auth_handlers);
	os_free(radius->acct_handlers);
	os_free(radius);
}


void radius_client_flush_auth(struct radius_client_data *radius, u8 *addr)
{
	struct radius_msg_list *entry, *prev, *tmp;

	prev = NULL;
	entry = radius->msgs;
	while (entry) {
		if (entry->msg_type == RADIUS_AUTH &&
		    os_memcmp(entry->addr, addr, ETH_ALEN) == 0) {
			hostapd_logger(radius->ctx, addr,
				       HOSTAPD_MODULE_RADIUS,
				       HOSTAPD_LEVEL_DEBUG,
				       "Removing pending RADIUS authentication"
				       " message for removed client");

			if (prev)
				prev->next = entry->next;
			else
				radius->msgs = entry->next;

			tmp = entry;
			entry = entry->next;
			radius_client_msg_free(tmp);
			radius->num_msgs--;
			continue;
		}

		prev = entry;
		entry = entry->next;
	}
}


static int radius_client_dump_auth_server(char *buf, size_t buflen,
					  struct hostapd_radius_server *serv,
					  struct radius_client_data *cli)
{
	int pending = 0;
	struct radius_msg_list *msg;
	char abuf[50];

	if (cli) {
		for (msg = cli->msgs; msg; msg = msg->next) {
			if (msg->msg_type == RADIUS_AUTH)
				pending++;
		}
	}

	return os_snprintf(buf, buflen,
			   "radiusAuthServerIndex=%d\n"
			   "radiusAuthServerAddress=%s\n"
			   "radiusAuthClientServerPortNumber=%d\n"
			   "radiusAuthClientRoundTripTime=%d\n"
			   "radiusAuthClientAccessRequests=%u\n"
			   "radiusAuthClientAccessRetransmissions=%u\n"
			   "radiusAuthClientAccessAccepts=%u\n"
			   "radiusAuthClientAccessRejects=%u\n"
			   "radiusAuthClientAccessChallenges=%u\n"
			   "radiusAuthClientMalformedAccessResponses=%u\n"
			   "radiusAuthClientBadAuthenticators=%u\n"
			   "radiusAuthClientPendingRequests=%u\n"
			   "radiusAuthClientTimeouts=%u\n"
			   "radiusAuthClientUnknownTypes=%u\n"
			   "radiusAuthClientPacketsDropped=%u\n",
			   serv->index,
			   hostapd_ip_txt(&serv->addr, abuf, sizeof(abuf)),
			   serv->port,
			   serv->round_trip_time,
			   serv->requests,
			   serv->retransmissions,
			   serv->access_accepts,
			   serv->access_rejects,
			   serv->access_challenges,
			   serv->malformed_responses,
			   serv->bad_authenticators,
			   pending,
			   serv->timeouts,
			   serv->unknown_types,
			   serv->packets_dropped);
}


static int radius_client_dump_acct_server(char *buf, size_t buflen,
					  struct hostapd_radius_server *serv,
					  struct radius_client_data *cli)
{
	int pending = 0;
	struct radius_msg_list *msg;
	char abuf[50];

	if (cli) {
		for (msg = cli->msgs; msg; msg = msg->next) {
			if (msg->msg_type == RADIUS_ACCT ||
			    msg->msg_type == RADIUS_ACCT_INTERIM)
				pending++;
		}
	}

	return os_snprintf(buf, buflen,
			   "radiusAccServerIndex=%d\n"
			   "radiusAccServerAddress=%s\n"
			   "radiusAccClientServerPortNumber=%d\n"
			   "radiusAccClientRoundTripTime=%d\n"
			   "radiusAccClientRequests=%u\n"
			   "radiusAccClientRetransmissions=%u\n"
			   "radiusAccClientResponses=%u\n"
			   "radiusAccClientMalformedResponses=%u\n"
			   "radiusAccClientBadAuthenticators=%u\n"
			   "radiusAccClientPendingRequests=%u\n"
			   "radiusAccClientTimeouts=%u\n"
			   "radiusAccClientUnknownTypes=%u\n"
			   "radiusAccClientPacketsDropped=%u\n",
			   serv->index,
			   hostapd_ip_txt(&serv->addr, abuf, sizeof(abuf)),
			   serv->port,
			   serv->round_trip_time,
			   serv->requests,
			   serv->retransmissions,
			   serv->responses,
			   serv->malformed_responses,
			   serv->bad_authenticators,
			   pending,
			   serv->timeouts,
			   serv->unknown_types,
			   serv->packets_dropped);
}


int radius_client_get_mib(struct radius_client_data *radius, char *buf,
			  size_t buflen)
{
	struct hostapd_radius_servers *conf = radius->conf;
	int i;
	struct hostapd_radius_server *serv;
	int count = 0;

	if (conf->auth_servers) {
		for (i = 0; i < conf->num_auth_servers; i++) {
			serv = &conf->auth_servers[i];
			count += radius_client_dump_auth_server(
				buf + count, buflen - count, serv,
				serv == conf->auth_server ?
				radius : NULL);
		}
	}

	if (conf->acct_servers) {
		for (i = 0; i < conf->num_acct_servers; i++) {
			serv = &conf->acct_servers[i];
			count += radius_client_dump_acct_server(
				buf + count, buflen - count, serv,
				serv == conf->acct_server ?
				radius : NULL);
		}
	}

	return count;
}


static int radius_servers_diff(struct hostapd_radius_server *nserv,
			       struct hostapd_radius_server *oserv,
			       int num)
{
	int i;

	for (i = 0; i < num; i++) {
		if (hostapd_ip_diff(&nserv[i].addr, &oserv[i].addr) ||
		    nserv[i].port != oserv[i].port ||
		    nserv[i].shared_secret_len != oserv[i].shared_secret_len ||
		    memcmp(nserv[i].shared_secret, oserv[i].shared_secret,
			   nserv[i].shared_secret_len) != 0)
			return 1;
	}

	return 0;
}


struct radius_client_data *
radius_client_reconfig(struct radius_client_data *old, void *ctx,
		       struct hostapd_radius_servers *oldconf,
		       struct hostapd_radius_servers *newconf)
{
	radius_client_flush(old, 0);

	if (newconf->retry_primary_interval !=
	    oldconf->retry_primary_interval ||
	    newconf->num_auth_servers != oldconf->num_auth_servers ||
	    newconf->num_acct_servers != oldconf->num_acct_servers ||
	    radius_servers_diff(newconf->auth_servers, oldconf->auth_servers,
				newconf->num_auth_servers) ||
	    radius_servers_diff(newconf->acct_servers, oldconf->acct_servers,
				newconf->num_acct_servers)) {
		hostapd_logger(ctx, NULL, HOSTAPD_MODULE_RADIUS,
			       HOSTAPD_LEVEL_DEBUG,
			       "Reconfiguring RADIUS client");
		radius_client_deinit(old);
		return radius_client_init(ctx, newconf, RADIUS_TYPE_FOR_VAP);
	}

	return old;
}


int radius_client_pool_init(struct radius_client_data ** radius_client_pool, struct hostapd_radius_servers *conf, int setid)
{
	int i ;

	if(radius_client_pool == NULL
		|| conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	for(i = 0; i < RADIUS_CLIENT_MAX; i ++){
		radius_client_pool[i] = radius_client_init(NULL, conf, RADIUS_TYPE_FOR_POOL) ;
		if(radius_client_pool[i] == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, radius client init failed.\n", __func__) ;
			return -1 ;
		}

		/*下述handle(hostapd_acl_recv_radius及ieee802_1x_receive_auth)，的DATA入参为hapd*/
		if(radius_client_register(radius_client_pool[i], RADIUS_AUTH, hostapd_acl_recv_radius, NULL)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, ACL register failed.\n", __func__);
			return -1;
		}
		
		if(radius_client_register(radius_client_pool[i], RADIUS_AUTH, ieee802_1x_receive_auth, NULL)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, IEEE 802.1X register failed.\n", __func__);
			return -1;
		}

#ifdef __ACCOUNTING_ON__
		/*???*/
#endif
		radius_client_pool[i]->radius_setid = setid;
		radius_client_pool[i]->radius_poolid = i ;
	}	
	
	return 0 ;
}


int radius_client_pool_deinit(struct radius_client_data ** radius_client_pool)
{
	int i ;

	if(radius_client_pool == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	for(i = 0; i < RADIUS_CLIENT_MAX; i ++){
		if(! radius_client_pool[i])
			continue ;

		radius_client_deinit(radius_client_pool[i]) ;
		radius_client_pool[i] = NULL ;
	}
	
	return 0 ;
}


int radius_client_pool_reset(struct radius_client_data ** radius_client_pool)
{
	int i, err = 0 ;

	if(radius_client_pool == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	for(i = 0; i < RADIUS_CLIENT_MAX; i ++){
		if(! radius_client_pool[i])
			continue ;

		if(radius_client_init_auth(radius_client_pool[i], 0) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, radius_client_init_auth failed.\n", __func__) ;
			err ++ ;
		}
	}
	
	return err ;
}


int radius_client_pool_change(struct radius_client_data ** radius_client_pool, struct hostapd_radius_server *nserv, struct hostapd_radius_server *oserv,int auth)
{
	struct radius_client_data * pstRadiusClient = NULL ;
	char buf1[50], buf2[50] ;
	int sock, sock6, i, error = 0 ;

	if(nserv == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	for(i = 0 ; i < RADIUS_CLIENT_MAX ; i ++){
		if((pstRadiusClient = radius_client_pool[i]) == NULL)
			continue ;

		if(auth){
			sock = pstRadiusClient->auth_serv_sock ;
			sock6 = pstRadiusClient->auth_serv_sock6 ;
		}
		else{
			sock = pstRadiusClient->acct_serv_sock ;
			sock6 = pstRadiusClient->acct_serv_sock6 ;
		}
		
		if(radius_change_server(pstRadiusClient, nserv, oserv, sock, sock6, auth) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, radius client pool[%d], change %s server from %s:%u to %s:%u failed.\n",
				__func__, i, auth ? "AUTH" : "ACCT",  
				oserv ? hostapd_ip_txt(& oserv->addr, buf1, sizeof(buf1)) : "NULL", oserv ? oserv->port : 0, 
				hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port) ;
			error ++ ;
		}
	}

	return error ;
}


struct radius_client_data * radius_client_pool_get(int setid, int index)
{
	if(setid >= 0 && setid < RADIUS_CLIENT_SET_SIZE)
		return g_pstRadiusClientSet[setid][index%RADIUS_CLIENT_MAX];
	
	return g_pstRadiusClient[index%RADIUS_CLIENT_MAX] ;
}


struct radius_client_data * radius_client_pool_get_byvapid(struct hostapd_data *hapd, int index)
{
	AC_DEVM_GET_SSIDRADIUSSERVERS_REQ_T stRadiusReq = {{0}};
	AC_DEVM_GET_SSIDRADIUSSERVERS_RSP_T stRadiusRsp = {0};
	UINT32 ulLength = 0, ulRadiusSetId = RADIUS_CLIENT_SET_SIZE;

	stRadiusReq.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
	stRadiusReq.stVapId.ulVDevId = hapd->iface->gdev_id ;
	stRadiusReq.stVapId.ulIfId = hapd->iface->interface_id ;
	stRadiusReq.stVapId.ulVapId = hapd->vap_id ;
	ac_db_access(AC_DEVM_GET_SSIDRADIUSSERVERS_MSG, (UINT8 *)&stRadiusReq, sizeof(stRadiusReq), (UINT8 *)&stRadiusRsp, &ulLength);
	if(stRadiusRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, sta(%u/%u/%u) : get radius config failed.\n",
			__func__, stRadiusReq.stVapId.ulWtpId, stRadiusReq.stVapId.ulIfId, stRadiusReq.stVapId.ulVapId) ;
		ulRadiusSetId = RADIUS_CLIENT_SET_SIZE;
	}
	ulRadiusSetId = radius_client_pools_getsetid(&stRadiusRsp);
	
	return radius_client_pool_get(ulRadiusSetId, index);
}


int radius_client_pools_add(struct hostapd_radius_servers * conf)
{
	struct radius_client_data ** pstRadiusClientPool = NULL; 
	int i;

	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__);
		return -1;
	}

	for(i = 0; i < RADIUS_CLIENT_SET_SIZE; i ++)
		if(g_pstRadiusClientSet[i][0] == NULL
			|| g_pstRadiusClientSet[i][0]->conf == NULL)
			break;

	if(i == RADIUS_CLIENT_SET_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, no empty radius client pool(%d).\n", __func__, i);
		return 1;
	}
	pstRadiusClientPool = g_pstRadiusClientSet[i];

	if(pstRadiusClientPool[i] == NULL){
		if(radius_client_pool_init(pstRadiusClientPool, conf, i) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, radius client pool init failed.\n", __func__);
			radius_client_pool_deinit(pstRadiusClientPool);
			return 2;
		}
	}
	else{
		for(i = 0; i < RADIUS_CLIENT_MAX; i ++)
			pstRadiusClientPool[i]->conf = conf;

		if(radius_client_pool_reset(pstRadiusClientPool) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, radius client pool reset failed.\n", __func__);
			return 3;
		}
	}
	
	return 0;
}


int radius_client_pools_del(struct hostapd_radius_servers * conf)
{
	struct radius_client_data ** pstRadiusClientPool = NULL;
	int i;

	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__);
		return -1;
	}

	for(i = 0; i < RADIUS_CLIENT_SET_SIZE; i ++){
		if(g_pstRadiusClientSet[i][0] 
			&& g_pstRadiusClientSet[i][0]->conf == conf)
			break;
	}

	if(i == RADIUS_CLIENT_SET_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, can not find this radius client.\n", __func__);
		return 0;
	}
	pstRadiusClientPool = g_pstRadiusClientSet[i];

	for(i = 0; i < RADIUS_CLIENT_MAX; i ++)
		pstRadiusClientPool[i]->conf = NULL;
	
	return 0;
}


int radius_client_pools_update(struct hostapd_radius_servers * conf)
{
	struct radius_client_data ** pstRadiusClientPool = NULL;
	int i;

	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__);
		return -1;
	}

	for(i = 0; i < RADIUS_CLIENT_SET_SIZE; i ++){
		if(g_pstRadiusClientSet[i][0] 
			&& g_pstRadiusClientSet[i][0]->conf == conf)
			break;
	}

	if(i == RADIUS_CLIENT_SET_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, can not find this radius client.\n", __func__);
		return 1;
	}
	pstRadiusClientPool = g_pstRadiusClientSet[i];

	return radius_client_pool_reset(pstRadiusClientPool);
}


int radius_client_pools_getsetid(AC_DEVM_GET_SSIDRADIUSSERVERS_RSP_T* pstRadiusResp)
{
	int i;
    u8 ip[4] = {0};
    int port = 0;

    if(NULL == pstRadiusResp)
    {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s,pstRadiusRsp is null, using default aaa server \n", __func__);
		goto end;
    }	

    os_memcpy(ip,pstRadiusResp->stAAAServers.stAuthSrvMaster.aucIp,sizeof(ip));
    port= pstRadiusResp->stAAAServers.stAuthSrvMaster.ulPort;
    
	for(i = 0; i < RADIUS_CLIENT_SET_SIZE; i++)
		if(g_pstRadiusClientSet[i][0]
			&& g_pstRadiusClientSet[i][0]->conf
			&& ((os_memcmp(&g_pstRadiusClientSet[i][0]->conf->auth_servers[0].addr.u.v4, ip, 4) == 0) && 
			    (g_pstRadiusClientSet[i][0]->conf->auth_servers[0].port == port)))
			return i;

end:
    return  RADIUS_CLIENT_SET_SIZE;
}


int radius_client_pools_reset_all(VOID)
{
	int i, err = 0;
	
	err = radius_client_pool_reset(g_pstRadiusClient);
	for(i = 0; i < RADIUS_CLIENT_SET_SIZE; i ++)
		err += radius_client_pool_reset(g_pstRadiusClientSet[i]);
	
	return err;
}
