#include "includes.h"
#include "radius.h"
#include "radius_client.h"
#include "radius_alive.h"
#include "hostapd.h"
#include "ppp.h"

#include "OssApi.h"
#include "ac_public.h"
#include "ac_devm_public.h"
#include "ac_oma_public.h"


#define RADIUS_ALIVE_TIMEOUT	1		/*心跳检测周期，seconds*/

#define RADIUS_ALIVE_PERIOD	60		/*seconds*/
#define RADIUS_ALIVE_NUM		1

#define RADIUS_SERVER_NUM	2
#define RADIUS_SERVER_ID_INVALID	-1


typedef enum{
	ALARM_ACTION_CLEAR,
	ALARM_ACTION_REPORT
}ALARM_ACTION_E ;


struct radius_alive{
	struct radius_client_data * radius ;
	unsigned char addr[6] ;

	int auth_id ;		/*保活认证服务器ID号，0为主用*/
	int auth_alarm ;	/*1：已上报告警；0：未上报告警*/
	int auth_alive_period ;	/*认证服务器保活探测周期，单位：秒*/
	int auth_alive_num ;		/*认证服务器保活探测次数*/
	struct os_time auth_last_probe ;
	struct os_time auth_last_recv ;

	int acct_id ;
	int acct_alarm ;
	int acct_alive_period ;
	int acct_alive_num ;
	struct os_time acct_last_probe ;
	struct os_time acct_last_recv ;
	time_t acct_session_start ;
} ;


static struct radius_alive * g_pstRadiusAlive[RADIUS_SERVER_NUM] = {NULL} ;
extern VOID ac_db_access(UINT32 ulMsgId, UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern VOID ac_db_oam_report_alarm (UINT32 ulAlarmId,
                             UINT32 ulAlarmReasonId,
                             UINT32 ulAlarmLevel,
                             UINT32 ulMOC,
                             UINT8	aucMOI[AC_MOI_LEN],
                             UINT32 ulCommonInfo);
extern VOID ac_db_oam_clear_alarm (UINT32 ulAlarmId,
                            UINT32 ulMOC,
                            UINT8  aucMOI[AC_MOI_LEN]);
typedef void (*eloop_timeout_handler)(void *eloop_data, void *user_ctx);
extern int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data);
extern int eloop_cancel_timeout(eloop_timeout_handler handler,
			 void *eloop_data, void *user_data);

#if 1
static struct radius_msg * radius_alive_accounting_msg(struct radius_alive *alive, int status_type)
{
	struct radius_msg *msg;
	char buf[128];

	if(alive == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return NULL ;
	}

	msg = radius_msg_new(RADIUS_CODE_ACCOUNTING_REQUEST,
			     radius_client_get_id(alive->radius));
	if (msg == NULL) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, new radius msg failed.\n", __func__) ;
		return NULL;
	}

	radius_msg_make_authenticator(msg, alive->addr, sizeof(alive->addr));

	snprintf(buf, sizeof(buf), "%08X-%08X",0, alive->acct_id);
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_ACCT_SESSION_ID, (u8 *) buf, strlen(buf))) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Session-Id.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_STATUS_TYPE, status_type)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Status-Type.\n", __func__) ;
		goto fail;
	}

	snprintf(buf, sizeof(buf), RADIUS_ADDR_FORMAT, MAC2STR(alive->addr));
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_USER_NAME, buf, strlen(buf))) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Name.\n", __func__) ;
		goto fail;
	}

	return msg;

 fail:
	radius_msg_free(msg);
	VM_FREE(msg);
	return NULL;
}


static void radius_alive_accounting_start(struct radius_alive * alive)
{
	struct radius_msg *msg;

	if(alive == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if (alive->acct_id == RADIUS_SERVER_ID_INVALID){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, alive's acct_id is invalid.\n", __func__) ;
		return ;
	}

	time(& alive->acct_session_start) ;

	msg = radius_alive_accounting_msg(alive, RADIUS_ACCT_STATUS_TYPE_START);
	if (msg)
		radius_client_send(alive->radius, msg, RADIUS_ACCT, alive->addr);
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not create RADIUS Accounting message for alive(%d).\n", __func__, alive->acct_id) ;
	return ;
}


static void radius_alive_accounting_report(struct radius_alive * alive, int stop)
{
	struct radius_msg *msg;

	if(alive == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if (alive->acct_id == RADIUS_SERVER_ID_INVALID){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, alive's acct_id is invalid.\n", __func__) ;
		return ;
	}

	msg = radius_alive_accounting_msg(alive, 
			     stop ? RADIUS_ACCT_STATUS_TYPE_STOP :
			     RADIUS_ACCT_STATUS_TYPE_INTERIM_UPDATE);
	if (!msg) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not create RADIUS Accounting message.\n", __func__) ;
		return;
	}

	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_SESSION_TIME,
				       time(NULL) - alive->acct_session_start)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Session-Time.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_INPUT_PACKETS, 0)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Input-Packets.\n", __func__) ;
		goto fail;
	}
 	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_OUTPUT_PACKETS, 0)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Output-Packets.\n", __func__) ;
		goto fail;
	}
	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_INPUT_OCTETS, 0)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Input-Octets.\n", __func__) ;
		goto fail;
	}
	
	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_OUTPUT_OCTETS, 0)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Output-Octets.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_EVENT_TIMESTAMP, time(NULL))) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Event-Timestamp.\n", __func__) ;
		goto fail;
	}

	if (stop && !radius_msg_add_attr_int32(msg, RADIUS_ATTR_ACCT_TERMINATE_CAUSE,
				       RADIUS_ACCT_TERMINATE_CAUSE_NAS_REQUEST)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Acct-Terminate-Cause.\n", __func__) ;
		goto fail;
	}

	radius_client_send(alive->radius, msg,
			   stop ? RADIUS_ACCT : RADIUS_ACCT_INTERIM,
			   alive->addr);
	return;

 fail:
	radius_msg_free(msg);
	VM_FREE(msg);
}


static void radius_alive_accounting_interim(struct radius_alive * alive)
{
	radius_alive_accounting_report(alive, 0);
}


static void radius_alive_accounting_stop(struct radius_alive * alive)
{
	radius_alive_accounting_report(alive, 1);
}
#else
static void radius_alive_accounting_start(struct radius_alive * alive)
{
	return ;
}

static void radius_alive_accounting_interim(struct radius_alive * alive)
{
	return ;
}


static void radius_alive_accounting_stop(struct radius_alive * alive)
{
	return ;
}
#endif


static int radius_alive_auth_probe(struct radius_alive * pstRadiusAlive)
{
	struct radius_client_data * radius_client = NULL ;
	struct radius_msg *msg;
	char buf[128];

	if(pstRadiusAlive == NULL
		|| (radius_client = pstRadiusAlive->radius) == NULL
		|| radius_client->conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	if(pstRadiusAlive->auth_id == RADIUS_SERVER_ID_INVALID){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, alive's auth_id is invalid.\n", __func__) ;
		return 0 ;
	}
	
	msg = radius_msg_new(RADIUS_CODE_ACCESS_REQUEST, radius_client_get_id(radius_client)) ;
	if (msg == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, new radius msg failed.\n", __func__) ;
		return -1;
	}

	radius_msg_make_authenticator(msg, pstRadiusAlive->addr, ETH_ALEN);

	snprintf(buf, sizeof(buf), "00000000");
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_USER_NAME, (u8 *) buf,
				 strlen(buf))) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Name.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr_user_password(
		msg, (u8 *) buf, strlen(buf),
		radius_client->conf->auth_servers[pstRadiusAlive->auth_id].shared_secret,
		radius_client->conf->auth_servers[pstRadiusAlive->auth_id].shared_secret_len)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Password.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_NAS_PORT_TYPE, RADIUS_NAS_PORT_TYPE_ETHERNET)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-Port-Type.\n", __func__) ;
		goto fail;
	}

	snprintf(buf, sizeof(buf), "radius alive probe auth server");
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_CONNECT_INFO, (u8 *) buf, strlen(buf))) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Connect-Info.\n", __func__) ;
		goto fail;
	}

	radius_client_send(radius_client, msg, RADIUS_AUTH, pstRadiusAlive->addr) ;
	return 0;

 fail:
	radius_msg_free(msg);
	VM_FREE(msg);
	return -1;
}


static int radius_alive_acct_probe(struct radius_alive * alive)
{
	if(alive == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	if (alive->acct_id == RADIUS_SERVER_ID_INVALID){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, alive's acct_id is invalid.\n", __func__) ;
		return -1 ;
	}
	
	radius_alive_accounting_interim(alive) ;
	
	return 0 ;
}


static RadiusRxResult radius_alive_recv(struct radius_msg *msg, struct radius_msg *req,
			u8 *shared_secret, size_t shared_secret_len,
			void *data)
{
	return RADIUS_RX_PROCESSED ;
}


static int radius_alive_alarm(unsigned long alarm_id, unsigned long alarm_reason, ALARM_ACTION_E alarm_action)
{
	AC_DEVM_GET_AC_MOID_RSP_T stRsp = {0} ;
	UINT32 ulLength = 0 ;
	
	ac_db_access(AC_DEVM_GET_AC_MOID_MSG, NULL, 0, (UINT8 *)& stRsp, & ulLength) ;
	if(stRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, %s alarm(%u) failed, get ac's MOID failed.\n", 
			__func__, alarm_action == ALARM_ACTION_REPORT ? "report" : "clear", alarm_id) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, %s alarm(%u/%u) success.\n", 
		__func__, alarm_action == ALARM_ACTION_REPORT ? "report" : "clear", alarm_id, alarm_reason) ;
	
	if(alarm_action == ALARM_ACTION_REPORT){
		ac_db_oam_report_alarm(alarm_id, 
			alarm_reason, 
			AC_OMA_ALARM_LEVEL_FATAL,
			stRsp.stAcMoid.ulMOC,
			stRsp.stAcMoid.aucMOI,
			0) ;
	}
	else{
		ac_db_oam_clear_alarm(alarm_id, stRsp.stAcMoid.ulMOC, stRsp.stAcMoid.aucMOI) ;
	}

	return 0 ;
}


/*从ID号开始查找连接状态正常的RADIUS SERVER, SERVER类型为auth*/
static struct hostapd_radius_server * find_normal_radius(unsigned long id, int auth)
{
	struct hostapd_radius_servers * radius_conf = NULL ;
	unsigned long i ;

	for(i = id; i < id + RADIUS_SERVER_NUM; i ++){
		unsigned long index = i % RADIUS_SERVER_NUM ;

		if(g_pstRadiusAlive[index] == NULL
			|| g_pstRadiusAlive[index]->radius == NULL
			|| (radius_conf = g_pstRadiusAlive[index]->radius->conf) == NULL)
			continue ;

		if(auth){
			if(g_pstRadiusAlive[index]->auth_id != RADIUS_SERVER_ID_INVALID
				&& ! g_pstRadiusAlive[index]->auth_alarm
				&& index < radius_conf->num_auth_servers)
				return (radius_conf->auth_servers + index) ;
		}
		else{
			if(g_pstRadiusAlive[index]->acct_id != RADIUS_SERVER_ID_INVALID
				&& ! g_pstRadiusAlive[index]->acct_alarm
				&& index < radius_conf->num_acct_servers)
				return (radius_conf->acct_servers + index) ;
		}	
	}

	return NULL ;
}


/*心跳检测，检测周期为RADIUS_ALIVE_TIMEOUT*/
static void radius_alive_timeout(void *eloop_ctx, void *timeout_ctx)
{
	struct radius_alive * alive = NULL ;
	struct radius_client_data * radius = NULL ;
	struct hostapd_radius_servers * radius_conf = NULL ;
	struct os_time now = {0} ;
	char buf1[50], buf2[50] ;
	unsigned long probe_time = 0, alive_time = 0, alarm_id = 0, alarm_reason = 0 ;

	if((alive = eloop_ctx) == NULL
		|| (radius = alive->radius) == NULL
		|| (radius_conf = radius->conf) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	os_get_time(& now) ;
	
	/*认证服务器保活处理*/
	if(alive->auth_id != RADIUS_SERVER_ID_INVALID){
		struct hostapd_radius_server * auth_conf = NULL ;

		if(alive->auth_id >= radius_conf->num_auth_servers
			|| radius_conf->auth_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, auth_id(%d) is over(%d), or point is NULL.\n", 
				__func__, alive->auth_id, radius_conf->num_auth_servers) ;
			return ;
		}

		auth_conf = radius_conf->auth_servers + alive->auth_id ;

		/*发送认证请求探测包*/
		probe_time = alive->auth_alive_period/2 ;
		if(! probe_time)
			probe_time = 1 ;
		if(now.sec - alive->auth_last_probe.sec >= probe_time){
			if(radius_alive_auth_probe(alive) != 0){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, probe auth server faild.\n", __func__) ;
			}
		}

		/*上报告警，或清除告警*/
		alive_time = alive->auth_alive_period * alive->auth_alive_num ;
		if(alive->auth_id == 0){
			alarm_id = AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE ;
			alarm_reason = AC_OMA_REASON_MAUTHSRV_OFFLINE ;
		}
		else{
			alarm_id = AC_OMA_ALARM_ID_SAUTHSRV_OFFLINE ;
			alarm_reason = AC_OMA_REASON_SAUTHSRV_OFFLINE ;
		}

		if(now.sec - alive->auth_last_recv.sec > alive_time
			&& ! alive->auth_alarm){
			struct hostapd_radius_server * nserv = NULL ;

			alive->auth_alarm = 1 ;

			/*上报告警*/
			radius_alive_alarm(alarm_id, alarm_reason, ALARM_ACTION_REPORT) ;
				
			/*更改认证服务器*/
			if(radius_conf->auth_server
				&& radius_conf->auth_server->index == alive->auth_id
				&& (nserv = find_normal_radius(alive->auth_id, 1)) != NULL){
				int error ;

#if 0
				error = hostapd_radius_ppp_change(nserv, radius_conf->auth_server, 1) || 
					radius_change_server_global(nserv, radius_conf->auth_server, 1) ;
#else
				error = hostapd_radius_ppp_change(g_pstRadiusPpp, nserv, radius_conf->auth_server, 1) || 
					radius_client_pool_change(g_pstRadiusClient, nserv, radius_conf->auth_server, 1) ;
#endif
				if(error){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
						"%s, change auth server from %s:%u to %s:%u failed(%u).\n", 
						__func__, hostapd_ip_txt(& radius_conf->auth_server->addr, buf1, sizeof(buf1)), radius_conf->auth_server->port, 
						hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port, error) ;
				}
				else{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, change auth server from %s:%u to %s:%u success.\n", 
						__func__, hostapd_ip_txt(& radius_conf->auth_server->addr, buf1, sizeof(buf1)), radius_conf->auth_server->port, 
						hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port) ;
				}

				radius_conf->auth_server = nserv ;
			}
		}
		else if(now.sec - alive->auth_last_recv.sec <= alive_time
			&& alive->auth_alarm){
			int all_fault = 0 ;

			if(! find_normal_radius(alive->auth_id, 1))
				all_fault = 1 ;
				
			alive->auth_alarm = 0 ;

			/*清除告警*/
			radius_alive_alarm(alarm_id, alarm_reason, ALARM_ACTION_CLEAR) ;

			/*更改认证服务器*/
			if(all_fault
				&& radius_conf->auth_server
				&& alive->auth_id != radius_conf->auth_server->index){
				int error ;

#if 0
				error = hostapd_radius_ppp_change(auth_conf, radius_conf->auth_server, 1) || 
					radius_change_server_global(auth_conf, radius_conf->auth_server, 1) ;
#else
				error = hostapd_radius_ppp_change(g_pstRadiusPpp, auth_conf, radius_conf->auth_server, 1) || 
					radius_client_pool_change(g_pstRadiusClient, auth_conf, radius_conf->auth_server, 1) ;
#endif
				if(error){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
						"%s, change auth server from %s:%u to %s:%u failed(%u).\n", 
						__func__, hostapd_ip_txt(& radius_conf->auth_server->addr, buf1, sizeof(buf1)), radius_conf->auth_server->port, 
						hostapd_ip_txt(& auth_conf->addr, buf2, sizeof(buf2)), auth_conf->port, error) ;
				}
				else{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, change auth server from %s:%u to %s:%u success.\n", 
						__func__, hostapd_ip_txt(& radius_conf->auth_server->addr, buf1, sizeof(buf1)), radius_conf->auth_server->port, 
						hostapd_ip_txt(& auth_conf->addr, buf2, sizeof(buf2)), auth_conf->port) ;
				}

				radius_conf->auth_server = auth_conf ;
			}
		}
	}

	/*计费服务器保活处理*/
	if(alive->acct_id != RADIUS_SERVER_ID_INVALID){
		struct hostapd_radius_server * acct_conf = NULL ;

		if(alive->acct_id >= radius_conf->num_acct_servers
			|| radius_conf->acct_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, acct_id(%d) is over(%d), or point is NULL.\n", 
				__func__, alive->acct_id, radius_conf->num_acct_servers) ;
			return ;
		}

		acct_conf = radius_conf->acct_servers + alive->acct_id ;

		/*发送计费请求探测包*/
		probe_time = alive->acct_alive_period/2 ;
		if(! probe_time)
			probe_time = 1 ;
		if(now.sec - alive->acct_last_probe.sec >= probe_time){
			if(radius_alive_acct_probe(alive) != 0){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, probe acct server faild.\n", __func__) ;
			}
		}

		/*上报告警，或清除告警*/
		if(alive->acct_last_probe.sec == 0)
			alive_time = 0xffffffff ;
		else
			alive_time = alive->acct_alive_period * alive->acct_alive_num ;
		
		if(alive->acct_id == 0){
			alarm_id = AC_OMA_ALARM_ID_MACCTSRV_OFFLINE ;
			alarm_reason = AC_OMA_REASON_MACCTSRV_OFFLINE ;
		}
		else{
			alarm_id = AC_OMA_ALARM_ID_SACCTSRV_OFFLINE ;
			alarm_reason = AC_OMA_REASON_SACCTSRV_OFFLINE ;
		}
		
		if(now.sec - alive->acct_last_recv.sec > alive_time
			&& ! alive->acct_alarm){
			struct hostapd_radius_server * nserv = NULL ;
			
			alive->acct_alarm = 1 ;

			/*上报告警*/
			radius_alive_alarm(alarm_id, alarm_reason, ALARM_ACTION_REPORT) ;

			/*更改计费服务器*/
			if(radius_conf->acct_server
				&& alive->acct_id == radius_conf->acct_server->index
				&& (nserv = find_normal_radius(alive->acct_id, 0)) != NULL){
				int error ;

#if 0
				error = radius_change_server_global(nserv, radius_conf->acct_server, 0) ;
#else
				error = radius_client_pool_change(g_pstRadiusClient, nserv, radius_conf->acct_server, 0) ;
#endif
				if(error){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
						"%s, change acct server from %s:%u to %s:%u failed(%u).\n", 
						__func__, hostapd_ip_txt(& radius_conf->acct_server->addr, buf1, sizeof(buf1)), radius_conf->acct_server->port,
						hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port, error) ;
				}
				else{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, change acct server from %s:%u to %s:%u success.\n", 
						__func__, hostapd_ip_txt(& radius_conf->acct_server->addr, buf1, sizeof(buf1)), radius_conf->acct_server->port,
						hostapd_ip_txt(& nserv->addr, buf2, sizeof(buf2)), nserv->port) ;
				}

				radius_conf->acct_server = nserv ;
			}
		}
		else if(now.sec - alive->acct_last_recv.sec <= alive_time
			&& alive->acct_alarm){
			int all_fault = 0 ;

			if(! find_normal_radius(alive->acct_id, 0))
				all_fault = 1 ;
			
			alive->acct_alarm = 0 ;

			/*清除告警*/	
			radius_alive_alarm(alarm_id, alarm_reason, ALARM_ACTION_CLEAR) ;

			/*更改计费服务器*/
			if(all_fault
				&& radius_conf->acct_server
				&& radius_conf->acct_server->index != alive->acct_id){
				int error ;

#if 0
				error = radius_change_server_global(acct_conf, radius_conf->acct_server, 0) ;
#else
				error = radius_client_pool_change(g_pstRadiusClient, acct_conf, radius_conf->acct_server, 0) ;
#endif
				if(error){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
						"%s, change acct server from %s:%u to %s:%u failed(%u).\n", 
						__func__, hostapd_ip_txt(& radius_conf->acct_server->addr, buf1, sizeof(buf1)), radius_conf->acct_server->port,
						hostapd_ip_txt(& acct_conf->addr, buf2, sizeof(buf2)), acct_conf->port, error) ;
				}
				else{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, change acct server from %s:%u to %s:%u success.\n", 
						__func__, hostapd_ip_txt(& radius_conf->acct_server->addr, buf1, sizeof(buf1)), radius_conf->acct_server->port,
						hostapd_ip_txt(& acct_conf->addr, buf2, sizeof(buf2)), acct_conf->port) ;
				}

				radius_conf->acct_server = acct_conf ;
			}
		}
	}

	eloop_register_timeout(RADIUS_ALIVE_TIMEOUT, 0, radius_alive_timeout, alive, NULL) ;
}


static void radius_alive_dump(VOID)
{
	struct radius_alive * alive ;
	time_t now ;
	char buf[500] = {0} ;
	int len = 0, i ;

	time(& now) ;

	for(i = 0; i < RADIUS_SERVER_NUM; i ++){
		if((alive = g_pstRadiusAlive[i]) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,	
				"radius_alive(%d) is not configued.\n", i) ;
			continue ;
		}

		if(alive->radius == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,	
				"%s, radius_alive(%d)'s radius is NULL\n", __func__, i) ;
			continue ;
		}
		
		os_memset(buf, 0, sizeof(buf)) ;
		len = 0 ;
		
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "radius_alive(%d):\n", i) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--radius:\t0x%p.\n", alive->radius) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--radius->auth_id:\t%d.\n", alive->radius->auth_id) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--radius->acct_id:\t%d.\n", alive->radius->acct_id) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--addr:\t"MACSTR".\n", MAC2STR(alive->addr)) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_id:\t%d.\n", alive->auth_id) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_alarm:\t%d.\n", alive->auth_alarm) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_alive_probe_period:\t%d s.\n", alive->auth_alive_period) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_alive_probe_num:\t%d.\n", alive->auth_alive_num) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_last_probe:\t%lu s.\n", alive->auth_last_probe.sec) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--auth_last_recv:\t%lu s.\n", alive->auth_last_recv.sec) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_id:\t%d.\n", alive->acct_id) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_alarm:\t%d.\n", alive->acct_alarm) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_alive_probe_period:\t%d s.\n", alive->acct_alive_period) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_alive_probe_num:\t%d.\n", alive->acct_alive_num) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_last_probe:\t%lu s.\n", alive->acct_last_probe.sec) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_last_recv:\t%lu s.\n", alive->acct_last_recv.sec) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--acct_session_start:\t%lu s.\n", alive->acct_session_start) ;
		len += os_snprintf(buf+len, sizeof(buf)-len-1, "--now:\t%lu s.\n", now) ;
		
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,	"%s", buf) ;
	}
	
	return ;
}


/*清除单个AAA服务器保活实例*/
static void radius_alive_deinit(struct radius_alive * alive)
{
	unsigned long alarm_id ;
	
	if(alive == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	eloop_cancel_timeout(radius_alive_timeout, alive, NULL) ;

	if(alive->auth_id != RADIUS_SERVER_ID_INVALID
		&& alive->auth_alarm){
		if(alive->auth_id == 0)
			alarm_id = AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE ;
		else
			alarm_id = AC_OMA_ALARM_ID_SAUTHSRV_OFFLINE ;
		if(radius_alive_alarm(alarm_id, 0, ALARM_ACTION_CLEAR) == 0)
			alive->auth_alarm = 0 ;
	}

	if(alive->acct_id != RADIUS_SERVER_ID_INVALID
		&& alive->acct_alarm){
		radius_alive_accounting_stop(alive) ;
		
		if(alive->acct_id == 0)
			alarm_id = AC_OMA_ALARM_ID_MACCTSRV_OFFLINE ;
		else
			alarm_id = AC_OMA_ALARM_ID_SACCTSRV_OFFLINE ;
		if(radius_alive_alarm(alarm_id, 0, ALARM_ACTION_CLEAR) == 0)
			alive->acct_alarm = 0 ;
	}

	if(alive->radius){
		radius_client_deinit(alive->radius) ;
		alive->radius = NULL ;
	}

	os_memset(alive, 0, sizeof(struct radius_alive)) ;
	alive->auth_id = alive->acct_id = RADIUS_SERVER_ID_INVALID ;

	return ;
}


/*初始化单个AAA服务的保活实例*/
static int radius_alive_init(struct radius_alive * alive, struct hostapd_radius_servers * radius_conf, int radius_id)
{
	u8 addr[6] = {0x02, 0x47, 0x42, 0x43, 0x4f, 0x4d} ;/*ASCII:GBCOM*/
	char buf[50] ; 
	
	if(alive == NULL
		|| radius_conf == NULL
		|| radius_id < 0
		|| radius_id >= RADIUS_SERVER_NUM){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, or radius_id(%d) is over [%d, %d).\n", __func__, radius_id, 0, RADIUS_SERVER_NUM) ;
		return -1 ;
	}

	if(radius_id >= radius_conf->num_auth_servers && radius_id >= radius_conf->num_acct_servers){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, radius(%d) config is not exist, num_auth(%d), num_acct(%d).\n", 
			__func__, radius_id, radius_conf->num_auth_servers, radius_conf->num_acct_servers) ;
		return -1 ;
	}

	radius_alive_deinit(alive) ;
	
	if((alive->radius = radius_client_init(NULL, radius_conf, RADIUS_TYPE_FOR_ALIVE)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, radius client init failed.\n", __func__) ;
		return -1 ;
	}

	os_memcpy(alive->addr, addr, sizeof(addr)) ;

	/*初始化认证服务器保活数据*/
	if(radius_id < radius_conf->num_auth_servers){
		struct hostapd_radius_server * auth_conf = NULL ;
		
		if(radius_conf->auth_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, point is NULL.\n", __func__) ;
			goto bad ;
		}

		auth_conf = radius_conf->auth_servers + radius_id ;

		if((radius_change_server(alive->radius, auth_conf, NULL, alive->radius->auth_serv_sock, alive->radius->auth_serv_sock6, 1)) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, change to auth server(%d.%s:%d) failed.\n", __func__, radius_id, hostapd_ip_txt(& auth_conf->addr, buf, sizeof(buf)), auth_conf->port) ;
			//goto bad ;
		}
		else
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, change to auth server(No.%d %s:%d) success.\n", 
				__func__, radius_id, hostapd_ip_txt(& auth_conf->addr, buf, sizeof(buf)), auth_conf->port) ;

		alive->auth_id = radius_id ;
		if(radius_conf->auth_alive_interval)
			alive->auth_alive_period = radius_conf->auth_alive_interval ;
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, alive->auth_alive_probe_period is turn to %d s.\n", __func__, RADIUS_ALIVE_PERIOD) ;
			alive->auth_alive_period = RADIUS_ALIVE_PERIOD ; 
		}
		alive->auth_alive_num = RADIUS_ALIVE_NUM ;
		os_get_time(& alive->auth_last_recv) ;

		if(radius_client_register(alive->radius, RADIUS_AUTH, radius_alive_recv, alive) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, register radius client(type: AUTH) failed.\n", __func__) ;
			goto bad ;
		}
	}

	/*初始化计费服务器保活数据*/
	if(radius_id < radius_conf->num_acct_servers){
		struct hostapd_radius_server * acct_conf = NULL ;
		
		if(radius_conf->acct_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, point is NULL.\n", __func__) ;
			goto bad ;
		}

		acct_conf = radius_conf->acct_servers + radius_id ;

		if((radius_change_server(alive->radius, acct_conf, NULL, alive->radius->acct_serv_sock, alive->radius->acct_serv_sock6, 0)) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, change to acct server(%d.%s:%d) failed.\n", __func__, radius_id, hostapd_ip_txt(& acct_conf->addr, buf, sizeof(buf)), acct_conf->port) ;
			//goto bad ;
		}
		else
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, change to acct server(No.%d %s:%d) success.\n", __func__, radius_id, hostapd_ip_txt(& acct_conf->addr, buf, sizeof(buf)), acct_conf->port) ;

		alive->acct_id = radius_id ;
		if(radius_conf->auth_alive_interval)
			alive->acct_alive_period = radius_conf->auth_alive_interval ;
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, alive->acct_alive_probe_period is turn to %d s.\n", __func__, RADIUS_ALIVE_PERIOD) ;
			alive->acct_alive_period = RADIUS_ALIVE_PERIOD ;
		}
		alive->acct_alive_num = RADIUS_ALIVE_NUM ;
		os_get_time(& alive->acct_last_recv) ;

		if(radius_client_register(alive->radius, RADIUS_ACCT, radius_alive_recv, alive) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, register radius client(type: ACCT) failed.\n", __func__) ;
			goto bad ;
		}

		radius_alive_accounting_start(alive) ;
	}

	if(eloop_register_timeout(RADIUS_ALIVE_TIMEOUT, 0, radius_alive_timeout, alive, NULL) != 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, register timeout failed.\n", __func__) ;
		goto bad ;
	}

	return 0 ;

bad :
	radius_alive_deinit(alive) ;
	
	return -1 ;
}


/*清除所有AAA服务器保活实例*/
void radius_alive_global_deinit()
{
	int i ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, deinit begin...\n", __func__) ;
	
	radius_alive_dump() ;
	
	for(i = 0; i < RADIUS_SERVER_NUM && g_pstRadiusAlive[i] ; i ++){
		radius_alive_deinit(g_pstRadiusAlive[i]) ;
		
		os_free(g_pstRadiusAlive[i]) ;
		g_pstRadiusAlive[i] = NULL ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, deinit end.\n", __func__) ;
}


/*初始化所有AAA服务器的保活实例*/
int radius_alive_global_init(struct hostapd_radius_servers * pstRadiusCfg)
{
	int i ;
	
	if(pstRadiusCfg == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, init begin...\n", __func__) ;
	
	radius_alive_global_deinit() ;
	
	/*初始化RADIUS 保活实例*/
	for(i = 0; i < RADIUS_SERVER_NUM && (i < pstRadiusCfg->num_auth_servers || i < pstRadiusCfg->num_acct_servers); i ++){
		if((g_pstRadiusAlive[i] = os_zalloc(sizeof(struct radius_alive))) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, memory zalloc(%d) failed.\n", __func__, sizeof(struct radius_alive)) ;
			goto bad ;
		}
		
		if((radius_alive_init(g_pstRadiusAlive[i], pstRadiusCfg, i)) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, radius(%d) alive init failed.\n", __func__, i) ;
			goto bad ;
		}
	}

	radius_alive_dump() ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, init end.\n", __func__) ;

	return 0 ;

bad:
	radius_alive_global_deinit() ;
	return -1 ;
	
}



/*更新RADIUS ALIVE实体最近收发时戳*/
void radius_alive_event(int radius_id, RadiusType msg_type, RADIUS_ALIVE_EVENT_E event)
{
	struct radius_alive * alive = NULL ;
	struct os_time now ;
	
	if(radius_id < 0
		|| radius_id >= RADIUS_SERVER_NUM){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, radius_id(%d) is over[%d, %d), or point is NULL.\n", __func__, radius_id, 0, RADIUS_SERVER_NUM) ;
		return ;
	}
	
	if((alive = g_pstRadiusAlive[radius_id]) == NULL){
#if 0
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, radius_alive(%d) is not exist.\n", __func__, radius_id) ;
#endif
		return ;
	}

	os_get_time(& now) ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, now(%d.%06d), radius_alive(%d) %s(%d) %s msg(%d).\n", 
		__func__, now.sec, now.usec, radius_id, event == RADIUS_ALIVE_EVENT_SEND ? "SEND" : "RECV", event, msg_type == RADIUS_AUTH ? "AUTH" : "ACCT", msg_type) ;

	switch(msg_type){
	case RADIUS_AUTH: {
		if(alive->auth_id == RADIUS_SERVER_ID_INVALID){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, radius_alive(%d)'s auth_id is invalid.\n", __func__, radius_id) ;
			return ;
		}

		switch(event){
		case RADIUS_ALIVE_EVENT_SEND :
			alive->auth_last_probe = now ;
			break ;
		case RADIUS_ALIVE_EVENT_RECV :
			alive->auth_last_recv = now ;
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, event(%d) is invalid.\n", __func__, event) ;
			break ;
		}

		break ;
	}
	case RADIUS_ACCT:
	case RADIUS_ACCT_INTERIM: {
		if(alive->acct_id == RADIUS_SERVER_ID_INVALID){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, radius_alive(%d)'s acct_id is invalid.\n", __func__, radius_id) ;
			return ;
		}

		switch(event){
		case RADIUS_ALIVE_EVENT_SEND:
			alive->acct_last_probe = now ;
			break ;
		case RADIUS_ALIVE_EVENT_RECV:
			alive->acct_last_recv = now ;
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, event(%d) is invalid.\n", __func__, event) ;
			break ;
		}

		break ;
	}
	default:
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, msg_type(%d) is invalid.\n", __func__, msg_type) ;
		break ;
	}

	return ;
}

struct radius_client_data * radius_alive_client_find(int auth_id, int acct_id)
{
	int i ;

	for(i = 0; i < RADIUS_SERVER_NUM; i ++){
		if(! g_pstRadiusAlive[i])
			continue ;

		if(g_pstRadiusAlive[i]->radius->auth_id == auth_id &&
			g_pstRadiusAlive[i]->radius->acct_id == acct_id)
			return g_pstRadiusAlive[i]->radius ;
	}

	return NULL ;
}
