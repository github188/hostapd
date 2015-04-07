/*
 * hostapd / Station table
 * Copyright (c) 2002-2006, Jouni Malinen <j@w1.fi>
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

#include "ac_db_public.h"
#include "ac_db_kernel.h"
#include "ac_db_table.h"
#include "ac_devm_public.h"
#include "ac_usrm_public.h"

#include "hostapd.h"
#include "ap.h"
#include "sta_info.h"
#include "eloop.h"
#include "accounting.h"
#include "ieee802_1x.h"
#include "ieee802_11.h"
#include "radius.h"
#include "eapol_sm.h"
#include "wpa.h"
#include "preauth.h"
#include "radius_client.h"
#include "driver.h"
#include "beacon.h"
#include "hw_features.h"
#include "mlme.h"
#include "vlan_init.h"
/*begin TASK #476 fangz 2013.2.25 log*/
#include "syslog_public.h"
#include "syslogu.h"
/*end TASK #476 fangz 2013.2.25 log*/


static struct sta_info * g_pstStaTable[STA_HASH_SIZE] = {0} ;	/*全局STA HASH表*/

static int ap_sta_in_other_bss(struct hostapd_data *hapd,
			       struct sta_info *sta, u32 flags);
static void ap_handle_session_timer(void *eloop_ctx, void *timeout_ctx);
extern struct radius_client_data * radius_client_pool_get_byvapid(struct hostapd_data *hapd, int index);

/*用户退出时，通知至用户管理模块*/
static void notify_sta_del(struct hostapd_data *hapd, struct sta_info *sta)
{
	AC_USRM_DEL_USER_REQ_T  stReq = {0} ;
	AC_USRM_DEL_USER_RSP_T  stRsp ;
	u32 ulOutLen ;

	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	if(! sta->registered)
		return ;

	if(sta->acct_terminate_cause != RADIUS_ACCT_TERMINATE_CAUSE_USER_REQUEST
		&& sta->acct_terminate_cause != RADIUS_ACCT_TERMINATE_CAUSE_IDLE_TIMEOUT
		&& sta->acct_terminate_cause != RADIUS_ACCT_TERMINATE_CAUSE_SESSION_TIMEOUT
		&& sta->acct_terminate_cause != RADIUS_ACCT_TERMINATE_CAUSE_ADMIN_RESET)
		sta->acct_terminate_cause = RADIUS_ACCT_TERMINATE_CAUSE_USER_REQUEST;
	
	/*通知用户管理模块*/
	os_memcpy(stReq.aucMac, sta->addr, ETH_ALEN) ;
	stReq.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
	stReq.stVapId.ulIfId = hapd->iface->interface_id ;
	stReq.stVapId.ulVapId = hapd->vap_id ;
	stReq.ulAcctTermCause = sta->acct_terminate_cause;
	ac_db_access(AC_USRM_DEL_USER_MSG, (u8 *)& stReq, sizeof(stReq), (u8 *)& stRsp, & ulOutLen) ;
	if(stRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, del sta("MACSTR") from vap(%u/%u/%u): notify failed, leave reason(0x%x, %d).\n",
			__func__, MAC2STR(stReq.aucMac), stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->leave_reason, stReq.ulAcctTermCause) ;
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, del sta("MACSTR") from vap(%u/%u/%u): notify success, leave reason(0x%x, %d).\n",
			__func__, MAC2STR(stReq.aucMac), stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->leave_reason, stReq.ulAcctTermCause) ;

		sta->registered = 0 ;
	}
}

/*
功能：用户无线层接入成功后，通知用户管理模块增加该用户
返回值：
	成功：1
	失败：0
*/
int notify_sta_add(struct hostapd_data *hapd, struct sta_info *sta)
{
	AC_USRM_ADD_USER_REQ_T  stReq = {0} ;
	AC_USRM_ADD_USER_RSP_T  stRsp ;
	u32 ulOutLen ;

	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return 0 ;
	}

	if(sta->registered)
		return 1 ;
	
	/*通知用户管理模块：新增用户*/
	os_memcpy(stReq.aucMac, sta->addr, ETH_ALEN) ;
	stReq.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
	stReq.stVapId.ulIfId = hapd->iface->interface_id ;
	stReq.stVapId.ulVapId = hapd->vap_id ;
	stReq.ulType = AC_USER_TYPE_WIRELESS ;
	stReq.ulIfId = 0 ;
	stReq.ulAssocId = sta->aid ;
	/*begin add by fangz for 802.1x vlan to sta*/
	stReq.ulVlanId = sta->vlan_id;
	/*end add by fangz for 802.1x vlan to sta*/
	ac_db_access(AC_USRM_ADD_USER_MSG, (u8 *)& stReq, sizeof(stReq), (u8 *)& stRsp, & ulOutLen) ;
	if(stRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, new sta("MACSTR", %d) from vap(%u/%u/%u): notify failed, access reason(%d).802.1x:vlan(%d)\n",
			__func__, MAC2STR(stReq.aucMac), stReq.ulAssocId, stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->access_reason, stReq.ulVlanId) ;
		return 0 ;
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, new sta("MACSTR", %d) from vap(%u/%u/%u): notify success, access reason(%d). 802.1x:vlan(%d)\n",
		__func__, MAC2STR(stReq.aucMac), stReq.ulAssocId, stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->access_reason, stReq.ulVlanId) ;

		sta->registered = 1 ;
	}

	return 1 ;
}

/*
功能：用户接入成功后，通知用户管理模块更新用户信息（用户名、QOS）
返回值：
	成功：1
	失败：0
*/
int notify_sta_info(struct hostapd_data *hapd, struct sta_info *sta)
{
	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return 0 ;
	}

	if(! sta->registered){
		AC_USRM_ADD_USER_REQ_T  stReq = {0} ;
		AC_USRM_ADD_USER_RSP_T  stRsp ;
		u32 ulOutLen ;

		/*通知用户管理模块：新增用户*/
		os_memcpy(stReq.aucMac, sta->addr, ETH_ALEN) ;
		stReq.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
		stReq.stVapId.ulIfId = hapd->iface->interface_id ;
		stReq.stVapId.ulVapId = hapd->vap_id ;
		stReq.ulType = AC_USER_TYPE_WIRELESS ;
		stReq.ulIfId = 0 ;
		stReq.ulAssocId = sta->aid ;
		ac_db_access(AC_USRM_ADD_USER_MSG, (u8 *)& stReq, sizeof(stReq), (u8 *)& stRsp, & ulOutLen) ;
		if(stRsp.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, new sta("MACSTR") from vap(%u/%u/%u): notify failed, access reason(%d).\n",
				__func__, MAC2STR(stReq.aucMac), stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->access_reason) ;
			return 0 ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, new sta("MACSTR") from vap(%u/%u/%u): notify success, access reason(%d).\n",
			__func__, MAC2STR(stReq.aucMac), stReq.stVapId.ulWtpId, stReq.stVapId.ulIfId, stReq.stVapId.ulVapId, sta->access_reason) ;

			sta->registered = 1 ;
		}
	}

	/*通知用户管理模块：用户信息，如用户名，用户QOS等*/
#if 0
	if(sta->eapol_sm 
		&& sta->eapol_sm->identity 
		&& sta->eapol_sm->identity_len){
		AC_USRM_UPDATE_USER_SUBINFO_REQ_T   stUpdateReq = {0} ;
		AC_USRM_UPDATE_USER_SUBINFO_RSP_T   stUpdateRsp = {0} ;
		u32 ulOutLen ;
		
		/*通知用户*/
		memset(&stUpdateReq, 0, sizeof(stUpdateReq));
	    	memcpy(stUpdateReq.aucMac, sta->addr, 6);
		memcpy(stUpdateReq.acUserName, sta->eapol_sm->identity, sta->eapol_sm->identity_len < 32 ? (sta->eapol_sm->identity_len+1) : 31);
		stUpdateReq.acUserName[31] = '\0' ;
	    	ac_db_access(AC_USRM_UPDATE_USER_SUBINFO_MSG, (UINT8*)&stUpdateReq, sizeof(stUpdateReq), (UINT8*)&stUpdateRsp, &ulOutLen);
	    	if (stUpdateRsp.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		        	"%s, sta(%u/%u/%u/"MACSTR") notify(update user subinfo) failed.\n", 
		        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
			return 0 ;
	    	}
	    	else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		        	"%s, sta(%u/%u/%u/"MACSTR") notify(update user subinfo) success.\n", 
		        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
	    	}
	}
#else
	if(sta->eapol_sm &&
		sta->eapol_sm->identity &&
		sta->eapol_sm->identity_len){
		VM_FREE(sta->identity) ;
		sta->identity = os_strdup(sta->eapol_sm->identity) ;
	}
#if 0
	if(! sta->identity){
		sta->identity = os_strdup("gbcom_user") ;
	}
#endif
	if(1/*sta->identity*/){
		AC_USRM_UPDATE_USER_SUBINFO_REQ_T   stUpdateReq;
		AC_USRM_UPDATE_USER_SUBINFO_RSP_T   stUpdateRsp;
		u32 ulOutLen ;
		
		os_memset(&stUpdateRsp, 0, sizeof(stUpdateRsp));
		/*通知用户*/
		os_memset(&stUpdateReq, 0, sizeof(stUpdateReq));
	    	os_memcpy(stUpdateReq.aucMac, sta->addr, 6);
		if(sta->identity)
			os_strncpy(stUpdateReq.acUserName, sta->identity, sizeof(stUpdateReq.acUserName)-1) ;
		os_memcpy(stUpdateReq.aucNasIp, sta->nas_ip, sizeof(sta->nas_ip)) ;
		if(sta->nas_id)
			os_strncpy(stUpdateReq.acNasId, sta->nas_id, sizeof(stUpdateReq.acNasId)-1) ;
		os_memcpy(& stUpdateReq.stQos, & sta->user_qos, sizeof(sta->user_qos)) ;

        stUpdateReq.ulAcctInterimInterval =  sta->acct_interim_interval;
        stUpdateReq.ulIdleTimeout = sta->acct_idle_time;
        stUpdateReq.ulSessionTimeout = sta->acct_session_timeout;
		os_strncpy(stUpdateReq.acUserGroupName, sta->acUserGroupName, sizeof(stUpdateReq.acUserGroupName)-1) ;/*add for filterid*/

        ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,/*modify for filterid*/
        	"%s,sta(%u/%u/%u/"MACSTR") get info[AcctInterimInterval :%d,IdleTimeout =%d,session_timeout%d,usergroupname=%s]from radius server\n", 
        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr),sta->acct_interim_interval,sta->acct_idle_time,sta->acct_session_timeout,sta->acUserGroupName) ;
        
	    	ac_db_access(AC_USRM_UPDATE_USER_SUBINFO_MSG, (UINT8*)&stUpdateReq, sizeof(stUpdateReq), (UINT8*)&stUpdateRsp, &ulOutLen);
	    	if (stUpdateRsp.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		        	"%s, sta(%u/%u/%u/"MACSTR") notify(update user subinfo) failed, p(%d), up[%d, %d], down[%d, %d], unit(kbps), due to call ac_db_access failed.\n", 
		        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr),
		        	stUpdateReq.stQos.ulPriority, stUpdateReq.stQos.ulUpBandMin, stUpdateReq.stQos.ulUpBandMax, stUpdateReq.stQos.ulDownBandMin, stUpdateReq.stQos.ulDownBandMax) ;
			return 0 ;
	    	}
	    	else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		        	"%s, sta(%u/%u/%u/"MACSTR") notify(update user subinfo) success, p(%d), up[%d, %d], down[%d, %d], unit(kbps).\n", 
		        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr), 
		        	stUpdateReq.stQos.ulPriority, stUpdateReq.stQos.ulUpBandMin, stUpdateReq.stQos.ulUpBandMax, stUpdateReq.stQos.ulDownBandMin, stUpdateReq.stQos.ulDownBandMax) ;
	    	}
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
	        	"%s, sta(%u/%u/%u/"MACSTR") notify(update user subinfo) failed, due to its identity is NULL.\n", 
	        	__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
		return 0 ;
	}
#endif

	return 1 ;
}

/*deauth and free sta immediately*/
 void ap_sta_deauthenticate_imm(struct hostapd_data * hapd, struct sta_info * sta, u32 reason)
{
	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	mlme_deauthenticate_indication(hapd, sta, reason);
	if(!sta->acct_terminate_cause)
		sta->acct_terminate_cause = RADIUS_ACCT_TERMINATE_CAUSE_USER_REQUEST ;
	hostapd_sta_deauth(hapd, sta->addr, reason);
	ap_free_sta(hapd, sta);

	return ;
}

/*在全局STA HASH列表g_pstStaTable中查找指定MAC地址的STA*/
struct sta_info * global_sta_get(const u8 * addr)
{
	struct sta_info * sta = NULL ;
	
	if(addr == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return NULL ;
	}

	sta = g_pstStaTable[STA_HASH(addr)] ;
	while(sta != NULL && os_memcmp(sta->addr, addr, sizeof(sta->addr)) != 0)
		sta = sta->ghnext ;
	
	return sta ;
}

/*向全局STA HASH列表g_pstStaTable增加STA*/
static void global_sta_hash_add(struct sta_info * sta)
{
	if(sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if(global_sta_get(sta->addr)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, exist sta"MACSTR" in global sta hash list.\n", __func__, MAC2STR(sta->addr)) ;
	}
	
	sta->ghnext= g_pstStaTable[STA_HASH(sta->addr)] ;
	g_pstStaTable[STA_HASH(sta->addr)] = sta ;

	return ;
}

/*从全局STA HASH列表g_pstStaTable中删除STA*/
static void global_sta_hash_del(struct sta_info * sta)
{
	struct sta_info * s = NULL ;
	
	if(sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if((s = g_pstStaTable[STA_HASH(sta->addr)]) == NULL){
		return ;
	}

	if(s == sta){
		g_pstStaTable[STA_HASH(sta->addr)] = s->ghnext ;
		return ;
	}

	while(s->ghnext != NULL
		&& s->ghnext != sta){
		s = s->ghnext ;
	}

	if(s->ghnext != NULL){
		s->ghnext = s->ghnext->ghnext ;
	}

	return ;
}


/*
	功能：STA在同一AC中切换处理
	返回 值：
		0，表示未发生切换
		>=1，表示切换时，踢相同MAC地址的终端个数；
		-1，表示欺骗攻击；
		
*/
int global_sta_handover(struct hostapd_data * newhapd, const u8 * addr, void * user_qos)
{
	struct sta_info * sta = NULL ;
	int num = 0 ;
	
	if(newhapd == NULL
		|| addr == NULL
		|| user_qos == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return num ;
	}

	while((sta = global_sta_get(addr)) != NULL && sta->ctx != newhapd){
#if 0/*防冒攻击定义：发送去鉴权帧，源地址为未接入终端的MAC*/
		AC_DEVM_GET_VDEV_BYID_REQ_T stVdevReq = {0} ;
		AC_DEVM_GET_VDEV_BYID_RSP_T stVdevRsp = {0} ;
		UINT32 ulLength = 0 ;

		stVdevReq.ulWtpId = newhapd->iface->pstWtp->usWtpId ;
		stVdevReq.ulVDevId = newhapd->iface->gdev_id ;
		ac_db_access(AC_DEVM_GET_VDEV_BYID_MSG, & stVdevReq, sizeof(stVdevReq), & stVdevRsp, & ulLength) ;
		if(stVdevRsp.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, get vdev config by id(%d/%d) failed.\n", __func__, stVdevReq.ulWtpId, stVdevReq.ulVDevId) ;
		}
		else if(stVdevRsp.stCfg.stVdevWidsCfg.ulSpoofAttackDetectSwitch){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, detect spoof attack from sta(%d/%d/%d/"MACSTR"), then disauth it .\n",
				__func__, newhapd->iface->pstWtp->usWtpId, newhapd->iface->interface_id, newhapd->vap_id, MAC2STR(addr)) ;
			hostapd_sta_deauth(newhapd, addr, WLAN_REASON_PREV_AUTH_NOT_VALID) ;
			return -1 ;
		}
#endif
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, sta("MACSTR") handover from bss(%d/%d/%d) to bss(%d/%d/%d).\n", 
			__func__, MAC2STR(addr),((struct hostapd_data *)(sta->ctx))->iface->pstWtp->usWtpId, ((struct hostapd_data *)(sta->ctx))->iface->interface_id, ((struct hostapd_data *)(sta->ctx))->vap_id, newhapd->iface->pstWtp->usWtpId, newhapd->iface->interface_id, newhapd->vap_id) ;
/*begin TASK #476 fangz 2013.2.26 log*/
		syslogu(LM_BUSINESS, LOG_EMERG,
			"%s, STA("MAC_LOG_FMT") handover from BSS(%d/%d/%d)SSID(%s) to BSS(%d/%d/%d)SSID(%s),NASID(%s),RoamingType(AC Internal)", 
			__func__, MAC2STR(addr),((struct hostapd_data *)(sta->ctx))->iface->pstWtp->usWtpId, 
			((struct hostapd_data *)(sta->ctx))->iface->interface_id, 
			((struct hostapd_data *)(sta->ctx))->vap_id,
			((struct hostapd_data *)(sta->ctx))->conf->ssid.ssid, 
			newhapd->iface->pstWtp->usWtpId, 
			newhapd->iface->interface_id, 
			newhapd->vap_id,
			newhapd->conf->ssid.ssid,newhapd->conf->nas_identifier);
/*end TASK #476 fangz 2013.2.26 log*/

		
		os_memcpy(user_qos, & sta->user_qos, sizeof(AC_USR_QOS_T)) ;
		if(sta->registered){
			num ++ ;
			g_stStats.ulInterAcRoaming ++;
		}
		
		ap_sta_deauthenticate_imm(sta->ctx, sta, WLAN_REASON_HANDOVER | WLAN_REASON_UNSPECIFIED) ;
	}

	return num ;
}


int ap_for_each_sta(struct hostapd_data *hapd,
		    int (*cb)(struct hostapd_data *hapd, struct sta_info *sta,
			      void *ctx),
		    void *ctx)
{
	struct sta_info *sta;

	for (sta = hapd->sta_list; sta; sta = sta->next) {
		if (cb(hapd, sta, ctx))
			return 1;
	}

	return 0;
}


struct sta_info * ap_get_sta(struct hostapd_data *hapd, const u8 *sta)
{
	struct sta_info *s;

	s = hapd->sta_hash[STA_HASH(sta)];
	while (s != NULL && memcmp(s->addr, sta, 6) != 0)
		s = s->hnext;
	return s;
}


static void ap_sta_list_del(struct hostapd_data *hapd, struct sta_info *sta)
{
	struct sta_info *tmp;

	if (hapd->sta_list == sta) {
		hapd->sta_list = sta->next;
		return;
	}

	tmp = hapd->sta_list;
	while (tmp != NULL && tmp->next != sta)
		tmp = tmp->next;
	if (tmp == NULL) {
		printf("Could not remove STA " MACSTR " from list.\n",
		       MAC2STR(sta->addr));
	} else
		tmp->next = sta->next;
}


void ap_sta_hash_add(struct hostapd_data *hapd, struct sta_info *sta)
{
	sta->hnext = hapd->sta_hash[STA_HASH(sta->addr)];
	hapd->sta_hash[STA_HASH(sta->addr)] = sta;
}


static void ap_sta_hash_del(struct hostapd_data *hapd, struct sta_info *sta)
{
	struct sta_info *s;

	s = hapd->sta_hash[STA_HASH(sta->addr)];
	if (s == NULL) return;
	if (memcmp(s->addr, sta->addr, 6) == 0) {
		hapd->sta_hash[STA_HASH(sta->addr)] = s->hnext;
		return;
	}

	while (s->hnext != NULL && memcmp(s->hnext->addr, sta->addr, 6) != 0)
		s = s->hnext;
	if (s->hnext != NULL){
		s->hnext = s->hnext->hnext;
	}
	else
		printf("AP: could not remove STA " MACSTR " from hash table\n",
		       MAC2STR(sta->addr));
}


void ap_free_sta(struct hostapd_data *hapd, struct sta_info *sta)
{
	int set_beacon = 0;

	accounting_sta_stop(hapd, sta);

	if (!ap_sta_in_other_bss(hapd, sta, WLAN_STA_ASSOC) &&
	    !(sta->flags & WLAN_STA_PREAUTH))
		hostapd_sta_remove(hapd, sta->addr);

	notify_sta_del(hapd, sta) ;
	global_sta_hash_del(sta) ;
	ap_sta_hash_del(hapd, sta);
	ap_sta_list_del(hapd, sta);

	if (sta->aid > 0)
		hapd->sta_aid[sta->aid - 1] = NULL;

	hapd->num_sta--;
	if (sta->nonerp_set) {
		sta->nonerp_set = 0;
		hapd->iface->num_sta_non_erp--;
		if (hapd->iface->num_sta_non_erp == 0)
			set_beacon++;
	}

	if (sta->no_short_slot_time_set) {
		sta->no_short_slot_time_set = 0;
		hapd->iface->num_sta_no_short_slot_time--;
		if (hapd->iface->current_mode->mode == HOSTAPD_MODE_IEEE80211G
		    && hapd->iface->num_sta_no_short_slot_time == 0)
			set_beacon++;
	}

	if (sta->no_short_preamble_set) {
		sta->no_short_preamble_set = 0;
		hapd->iface->num_sta_no_short_preamble--;
		if (hapd->iface->current_mode->mode == HOSTAPD_MODE_IEEE80211G
		    && hapd->iface->num_sta_no_short_preamble == 0)
			set_beacon++;
	}

	if (set_beacon)
		ieee802_11_set_beacons(hapd->iface);

	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_cancel_timeout(ap_handle_session_timer, hapd, sta);

	ieee802_1x_free_station(sta);
	wpa_auth_sta_deinit(sta->wpa_sm);
	rsn_preauth_free_station(hapd, sta);
#if 0
	radius_client_flush_auth(hapd->radius, sta->addr);
#else
	radius_client_flush_auth(sta->radius, sta->addr);
#endif

	eloop_cancel_timeout(OnWaitStaIoctlTimer, hapd, sta) ;

	if (sta->last_assoc_req)
		VM_FREE(sta->last_assoc_req);

	VM_FREE(sta->nas_id) ;
	VM_FREE(sta->challenge);
	VM_FREE(sta->identity) ;

	VM_FREE(sta);
}


void hostapd_free_stas(struct hostapd_data *hapd)
{
	struct sta_info *sta, *prev;

	sta = hapd->sta_list;

	while (sta) {
		prev = sta;
		if (sta->flags & WLAN_STA_AUTH) {
			mlme_deauthenticate_indication(
				hapd, sta, WLAN_REASON_UNSPECIFIED);
		}
		sta = sta->next;
		printf("Removing station " MACSTR "\n", MAC2STR(prev->addr));
		ap_free_sta(hapd, prev);
	}
}


void ap_handle_timer(void *eloop_ctx, void *timeout_ctx)
{
	struct hostapd_data *hapd = eloop_ctx;
	struct sta_info *sta = timeout_ctx;
	unsigned long next_time = 0;

	if (sta->timeout_next == STA_REMOVE) {
		hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
			       HOSTAPD_LEVEL_INFO, "deauthenticated due to "
			       "local deauth request");
		ap_free_sta(hapd, sta);
		return;
	}

	if ((sta->flags & WLAN_STA_ASSOC) &&
	    (sta->timeout_next == STA_NULLFUNC ||
	     sta->timeout_next == STA_DISASSOC)) {
		int inactive_sec;
		HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL,
			      "Checking STA " MACSTR " inactivity:\n",
			      MAC2STR(sta->addr));
		inactive_sec = hostapd_get_inact_sec(hapd, sta->addr);
		if (inactive_sec == -1) {
			printf("  Could not get station info from kernel "
			       "driver for " MACSTR ".\n",
			       MAC2STR(sta->addr));
		} else if (inactive_sec < hapd->conf->ap_max_inactivity &&
			   sta->flags & WLAN_STA_ASSOC) {
			/* station activity detected; reset timeout state */
			HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL,
				      "  Station has been active\n");
			sta->timeout_next = STA_NULLFUNC;
			next_time = hapd->conf->ap_max_inactivity -
				inactive_sec;
		}
	}

	if ((sta->flags & WLAN_STA_ASSOC) &&
	    sta->timeout_next == STA_DISASSOC &&
	    !(sta->flags & WLAN_STA_PENDING_POLL)) {
		HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL,
			      "  Station has ACKed data poll\n");
		/* data nullfunc frame poll did not produce TX errors; assume
		 * station ACKed it */
		sta->timeout_next = STA_NULLFUNC;
		next_time = hapd->conf->ap_max_inactivity;
	}

	if (next_time) {
		eloop_register_timeout(next_time, 0, ap_handle_timer, hapd,
				       sta);
		return;
	}

	if (sta->timeout_next == STA_NULLFUNC &&
	    (sta->flags & WLAN_STA_ASSOC)) {
		/* send data frame to poll STA and check whether this frame
		 * is ACKed */
		struct ieee80211_hdr hdr;

		HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL,
			      "  Polling STA with data frame\n");
		sta->flags |= WLAN_STA_PENDING_POLL;

#ifndef CONFIG_NATIVE_WINDOWS
		/* FIX: WLAN_FC_STYPE_NULLFUNC would be more appropriate, but
		 * it is apparently not retried so TX Exc events are not
		 * received for it */
		memset(&hdr, 0, sizeof(hdr));
		hdr.frame_control =
			IEEE80211_FC(WLAN_FC_TYPE_DATA, WLAN_FC_STYPE_DATA);
		hdr.frame_control |= host_to_le16(BIT(1));
		hdr.frame_control |= host_to_le16(WLAN_FC_FROMDS);
		memcpy(hdr.IEEE80211_DA_FROMDS, sta->addr, ETH_ALEN);
		memcpy(hdr.IEEE80211_BSSID_FROMDS, hapd->own_addr, ETH_ALEN);
		memcpy(hdr.IEEE80211_SA_FROMDS, hapd->own_addr, ETH_ALEN);

		if (hostapd_send_mgmt_frame(hapd, &hdr, sizeof(hdr), 0) < 0)
			perror("ap_handle_timer: send");
#endif /* CONFIG_NATIVE_WINDOWS */
	} else if (sta->timeout_next != STA_REMOVE) {
		int deauth = sta->timeout_next == STA_DEAUTH;

		printf("  Sending %s info to STA " MACSTR "\n",
		       deauth ? "deauthentication" : "disassociation",
		       MAC2STR(sta->addr));

		if (deauth) {
			hostapd_sta_deauth(hapd, sta->addr,
					   WLAN_REASON_PREV_AUTH_NOT_VALID);
		} else {
			hostapd_sta_disassoc(
				hapd, sta->addr,
				WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY);
		}
	}

	switch (sta->timeout_next) {
	case STA_NULLFUNC:
		sta->timeout_next = STA_DISASSOC;
		eloop_register_timeout(AP_DISASSOC_DELAY, 0, ap_handle_timer,
				       hapd, sta);
		break;
	case STA_DISASSOC:
		sta->flags &= ~WLAN_STA_ASSOC;
		ieee802_1x_notify_port_enabled(sta->eapol_sm, 0);
		if (!sta->acct_terminate_cause)
			sta->acct_terminate_cause =
				RADIUS_ACCT_TERMINATE_CAUSE_IDLE_TIMEOUT;
		accounting_sta_stop(hapd, sta);
		ieee802_1x_free_station(sta);
		hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
			       HOSTAPD_LEVEL_INFO, "disassociated due to "
			       "inactivity");
		sta->timeout_next = STA_DEAUTH;
		eloop_register_timeout(AP_DEAUTH_DELAY, 0, ap_handle_timer,
				       hapd, sta);
		mlme_disassociate_indication(
			hapd, sta, WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY);
		break;
	case STA_DEAUTH:
	case STA_REMOVE:
		hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
			       HOSTAPD_LEVEL_INFO, "deauthenticated due to "
			       "inactivity");
		if (!sta->acct_terminate_cause)
			sta->acct_terminate_cause =
				RADIUS_ACCT_TERMINATE_CAUSE_IDLE_TIMEOUT;
		mlme_deauthenticate_indication(
			hapd, sta,
			WLAN_REASON_PREV_AUTH_NOT_VALID);
		ap_free_sta(hapd, sta);
		break;
	}
}


static void ap_handle_session_timer(void *eloop_ctx, void *timeout_ctx)
{
	struct hostapd_data *hapd = eloop_ctx;
	struct sta_info *sta = timeout_ctx;
	u8 addr[ETH_ALEN];

	if (!(sta->flags & WLAN_STA_AUTH))
		return;

	mlme_deauthenticate_indication(hapd, sta,
				       WLAN_REASON_PREV_AUTH_NOT_VALID);
	hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
		       HOSTAPD_LEVEL_INFO, "deauthenticated due to "
		       "session timeout");
	sta->acct_terminate_cause =
		RADIUS_ACCT_TERMINATE_CAUSE_SESSION_TIMEOUT;
	memcpy(addr, sta->addr, ETH_ALEN);
	hostapd_sta_deauth(hapd, addr, WLAN_REASON_PREV_AUTH_NOT_VALID);
	ap_free_sta(hapd, sta);
}


void ap_sta_session_timeout(struct hostapd_data *hapd, struct sta_info *sta,
			    u32 session_timeout)
{
	hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
		       HOSTAPD_LEVEL_DEBUG, "setting session timeout to %d "
		       "seconds", session_timeout);
	eloop_cancel_timeout(ap_handle_session_timer, hapd, sta);
	eloop_register_timeout(session_timeout, 0, ap_handle_session_timer,
			       hapd, sta);
}


void ap_sta_no_session_timeout(struct hostapd_data *hapd, struct sta_info *sta)
{
	eloop_cancel_timeout(ap_handle_session_timer, hapd, sta);
}

struct sta_info * ap_sta_add(struct hostapd_data *hapd, const u8 *addr)
{
	struct sta_info *sta;
	//AC_USR_QOS_T user_qos;
	u32 access_reason = WLAN_REASON_ACCESS_NORMAL ;
	AC_USRM_GET_NASINFO_REQ_T stNasReq;
	AC_USRM_GET_NASINFO_RSP_T stNasRsp ;
	UINT32 ulLength = 0;
	
	sta = ap_get_sta(hapd, addr);
	os_memset( &stNasReq, 0, sizeof(stNasReq));
	os_memset( &stNasRsp, 0, sizeof(stNasRsp));
	os_memcpy(stNasReq.aucMac, addr, 6) ;
	stNasReq.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
	stNasReq.stVapId.ulVDevId = hapd->iface->gdev_id ;
	stNasReq.stVapId.ulIfId = hapd->iface->interface_id ;
	stNasReq.stVapId.ulVapId = hapd->vap_id ;
	ac_db_access(AC_USRM_GET_NASINFO_MSG, (UINT8 *)& stNasReq, sizeof(stNasReq), (UINT8 * )& stNasRsp, & ulLength) ;
	
	if (sta){
		sta->access_reason = WLAN_REASON_ACCESS_AGAIN ;
		os_memset(& sta->user_qos, 0, sizeof(sta->user_qos)) ;

		if(stNasRsp.ulRet == AC_OK){
			os_memcpy(sta->nas_ip, stNasRsp.aucNasIp, 4) ;
			VM_FREE(sta->nas_id) ;
			sta->nas_id = os_strdup(stNasRsp.acNasId) ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, sta(%u/%u/%u/"MACSTR") : get nas failed.\n",
				__func__, stNasReq.stVapId.ulWtpId, stNasReq.stVapId.ulIfId, stNasReq.stVapId.ulVapId, MAC2STR(stNasReq.aucMac)) ;
		}
	
		return sta;
	}

	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "  New STA\n");
	if (hapd->num_sta >= hapd->conf->max_num_sta) {
		/* FIX: might try to remove some old STAs first? */
		printf("  no more room for new STAs (%d/%d)\n",
		       hapd->num_sta, hapd->conf->max_num_sta);
		return NULL;
	}

	sta = wpa_zalloc(sizeof(struct sta_info));
	if (sta == NULL) {
		printf("  malloc failed\n");
		return NULL;
	}

	if(stNasRsp.ulRet == AC_OK){
		os_memcpy(sta->nas_ip, stNasRsp.aucNasIp, 4) ;
		sta->nas_id = os_strdup(stNasRsp.acNasId) ;
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, sta(%u/%u/%u/"MACSTR") : get nas failed.\n",
			__func__, stNasReq.stVapId.ulWtpId, stNasReq.stVapId.ulIfId, stNasReq.stVapId.ulVapId, MAC2STR(stNasReq.aucMac)) ;
	}

	/*sta->acct_interim_interval = hapd->conf->radius->acct_interim_interval;*/

	/* initialize STA info data */
	eloop_register_timeout(hapd->conf->ap_max_inactivity, 0,
			       ap_handle_timer, hapd, sta);
	memcpy(sta->addr, addr, ETH_ALEN);
	sta->next = hapd->sta_list;
	hapd->sta_list = sta;
	hapd->num_sta++;
	ap_sta_hash_add(hapd, sta);
	global_sta_hash_add(sta) ;
	sta->ssid = &hapd->conf->ssid;
	sta->ctx = hapd ;
	sta->access_reason = access_reason ;
	sta->radius = radius_client_pool_get_byvapid(hapd, (int)addr[5]);
	os_memcpy(sta->radius_ip, &sta->radius->conf->auth_servers[0].addr.u.v4, 4);

	return sta;
}


static int ap_sta_remove(struct hostapd_data *hapd, struct sta_info *sta)
{
	ieee802_1x_notify_port_enabled(sta->eapol_sm, 0);

	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "Removing STA " MACSTR
		      " from kernel driver\n", MAC2STR(sta->addr));
	if (hostapd_sta_remove(hapd, sta->addr) &&
	    sta->flags & WLAN_STA_ASSOC) {
		printf("Could not remove station " MACSTR " from kernel "
		       "driver.\n", MAC2STR(sta->addr));
		return -1;
	}
	return 0;
}


static int ap_sta_in_other_bss(struct hostapd_data *hapd,
			       struct sta_info *sta, u32 flags)
{
	struct hostapd_iface *iface = hapd->iface;
	size_t i;

	for (i = 0; i < MAX_BSSES; i++) {
		struct hostapd_data *bss = iface->bss[i];
		struct sta_info *sta2;
		/* bss should always be set during operation, but it may be
		 * NULL during reconfiguration. Assume the STA is not
		 * associated to another BSS in that case to avoid NULL pointer
		 * dereferences. */
		if (bss == hapd || bss == NULL)
			continue;
		sta2 = ap_get_sta(bss, sta->addr);
		if (sta2 && ((sta2->flags & flags) == flags))
			return 1;
	}

	return 0;
}


void ap_sta_disassociate(struct hostapd_data *hapd, struct sta_info *sta,
			 u16 reason)
{
	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "%s: disassociate STA " MACSTR
		      "\n", hapd->conf->iface, MAC2STR(sta->addr));
	sta->flags &= ~WLAN_STA_ASSOC;
	if (!ap_sta_in_other_bss(hapd, sta, WLAN_STA_ASSOC))
		ap_sta_remove(hapd, sta);
	sta->timeout_next = STA_DEAUTH;
	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_register_timeout(AP_MAX_INACTIVITY_AFTER_DISASSOC, 0,
			       ap_handle_timer, hapd, sta);
	accounting_sta_stop(hapd, sta);
	ieee802_1x_free_station(sta);

	mlme_disassociate_indication(hapd, sta, reason);
}


void ap_sta_deauthenticate(struct hostapd_data *hapd, struct sta_info *sta,
			   u16 reason)
{
	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "%s: deauthenticate STA " MACSTR
		      "\n", hapd->conf->iface, MAC2STR(sta->addr));
	sta->flags &= ~(WLAN_STA_AUTH | WLAN_STA_ASSOC);
	if (!ap_sta_in_other_bss(hapd, sta, WLAN_STA_ASSOC))
		ap_sta_remove(hapd, sta);
	sta->timeout_next = STA_REMOVE;
	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_register_timeout(AP_MAX_INACTIVITY_AFTER_DEAUTH, 0,
			       ap_handle_timer, hapd, sta);
	accounting_sta_stop(hapd, sta);
	ieee802_1x_free_station(sta);

	mlme_deauthenticate_indication(hapd, sta, reason);
}


int ap_sta_bind_vlan(struct hostapd_data *hapd, struct sta_info *sta,
		     int old_vlanid)
{
	const char *iface;
	struct hostapd_vlan *vlan = NULL;

	/*
	 * Do not proceed furthur if the vlan id remains same. We do not want
	 * duplicate dynamic vlan entries.
	 */
	if (sta->vlan_id == old_vlanid)
		return 0;

	/*
	 * During 1x reauth, if the vlan id changes, then remove the old id and
	 * proceed furthur to add the new one.
	 */
	if (old_vlanid > 0)
		vlan_remove_dynamic(hapd, old_vlanid);

	iface = hapd->conf->iface;
	if (sta->ssid->vlan[0])
		iface = sta->ssid->vlan;

	if (sta->ssid->dynamic_vlan == DYNAMIC_VLAN_DISABLED)
		sta->vlan_id = 0;
	else if (sta->vlan_id > 0) {
		vlan = hapd->conf->vlan;
		while (vlan) {
			if (vlan->vlan_id == sta->vlan_id ||
			    vlan->vlan_id == VLAN_ID_WILDCARD) {
				iface = vlan->ifname;
				break;
			}
			vlan = vlan->next;
		}
	}

	if (sta->vlan_id > 0 && vlan == NULL) {
		hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
			       HOSTAPD_LEVEL_DEBUG, "could not find VLAN for "
			       "binding station to (vlan_id=%d)",
			       sta->vlan_id);
		return -1;
	} else if (sta->vlan_id > 0 && vlan->vlan_id == VLAN_ID_WILDCARD) {
		vlan = vlan_add_dynamic(hapd, vlan, sta->vlan_id);
		if (vlan == NULL) {
			hostapd_logger(hapd, sta->addr,
				       HOSTAPD_MODULE_IEEE80211,
				       HOSTAPD_LEVEL_DEBUG, "could not add "
				       "dynamic VLAN interface for vlan_id=%d",
				       sta->vlan_id);
			return -1;
		}

		iface = vlan->ifname;
		if (vlan_setup_encryption_dyn(hapd, sta->ssid, iface) != 0) {
			hostapd_logger(hapd, sta->addr,
				       HOSTAPD_MODULE_IEEE80211,
				       HOSTAPD_LEVEL_DEBUG, "could not "
				       "configure encryption for dynamic VLAN "
				       "interface for vlan_id=%d",
				       sta->vlan_id);
		}

		hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
			       HOSTAPD_LEVEL_DEBUG, "added new dynamic VLAN "
			       "interface '%s'", iface);
	} else if (vlan && vlan->vlan_id == sta->vlan_id) {
		if (sta->vlan_id > 0) {
			vlan->dynamic_vlan++;
			hostapd_logger(hapd, sta->addr,
				       HOSTAPD_MODULE_IEEE80211,
				       HOSTAPD_LEVEL_DEBUG, "updated existing "
				       "dynamic VLAN interface '%s'", iface);
		}

		/*
		 * Update encryption configuration for statically generated
		 * VLAN interface. This is only used for static WEP
		 * configuration for the case where hostapd did not yet know
		 * which keys are to be used when the interface was added.
		 */
		if (vlan_setup_encryption_dyn(hapd, sta->ssid, iface) != 0) {
			hostapd_logger(hapd, sta->addr,
				       HOSTAPD_MODULE_IEEE80211,
				       HOSTAPD_LEVEL_DEBUG, "could not "
				       "configure encryption for VLAN "
				       "interface for vlan_id=%d",
				       sta->vlan_id);
		}
	}

	hostapd_logger(hapd, sta->addr, HOSTAPD_MODULE_IEEE80211,
		       HOSTAPD_LEVEL_DEBUG, "binding station to interface "
		       "'%s'", iface);

	if (wpa_auth_sta_set_vlan(sta->wpa_sm, sta->vlan_id) < 0)
		wpa_printf(MSG_INFO, "Failed to update VLAN-ID for WPA");

	return hostapd_set_sta_vlan(iface, hapd, sta->addr, sta->vlan_id);
}
