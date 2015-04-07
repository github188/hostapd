#include "includes.h"

#include "OssApi.h"
#include "ac_public.h"
#include "ac_db_public.h"
#include "ac_usrm_public.h"
#include "ac_devm_public.h"

#include "hostapd.h"
#include "sta_info.h"
#include "ap.h"
#include "ieee802_11.h"
#include "radius.h"
#include "radius_client.h"
#include "ieee802_11_auth.h"
#include "driver.h"
#include "mac_auth.h"

typedef void (*eloop_timeout_handler)(void *eloop_data, void *user_ctx);
extern int eloop_cancel_timeout(eloop_timeout_handler handler, void *eloop_data, void *user_data);
extern int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data);
static void mac_auth_update_sta_identity(struct hostapd_data *hapd, struct sta_info * sta)
{
	char buf[30] = {0} ;
	
	if(sta == NULL ||
		hapd == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	return ;	/*MAC认证不记录用户名*/

	snprintf(buf, sizeof(buf), RADIUS_ADDR_FORMAT, MAC2STR(sta->addr)) ;
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, vap(%d/%d/%d), old identity '%s' updated with User-Name from Mac-Accept '%s'",
		__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, sta->identity ? (char *) sta->identity : "N/A", buf) ;
	
	os_free(sta->identity) ;
	sta->identity = os_strdup(buf) ;

	return ;
}


static void mac_auth_update_sta_info(struct hostapd_data *hapd, struct sta_info * sta, AC_USER_DATA_QOS_T * user_qos)
{
	AC_USER_DATA_QOS_T radius_user_qos_invalid = {0} ;
	AC_USR_QOS_T user_qos_invalid = {0} ;

	if(hapd == NULL
		|| sta == NULL
		|| user_qos == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if(os_memcmp(user_qos, & radius_user_qos_invalid, sizeof(radius_user_qos_invalid)) != 0){/*采用AAA数据库配置*/
		sta->user_qos.ulPriority = user_qos->ulOutPriority ;
		sta->user_qos.ulUpBandMax = user_qos->ulOutMaxULBand ;
		sta->user_qos.ulUpBandMin = user_qos->ulOutMinULBand ;
		sta->user_qos.ulDownBandMax = user_qos->ulOutMaxDLBand ;
		sta->user_qos.ulDownBandMin = user_qos->ulOutMinDLBand ;
	}
	else if(os_memcmp(& sta->user_qos, & user_qos_invalid, sizeof(user_qos_invalid)) == 0){/*采用系统缺省配置*/
		AC_VAPID_T stVapId = {0} ;
		AC_USRM_GET_USERQOS_REQ_T stQosReq = {{0}} ;
		AC_USRM_GET_USERQOS_RSP_T stQosResp = {0} ;
		UINT32 ulLength = 0 ;

		stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
		stVapId.ulVDevId = hapd->iface->gdev_id ;
		stVapId.ulIfId = hapd->iface->interface_id ;
		stVapId.ulVapId = hapd->vap_id ;
		os_memcpy(& stQosReq.stVapId, & stVapId, sizeof(stVapId)) ;
		os_memcpy(stQosReq.aucMac, sta->addr, sizeof(sta->addr)) ;
		ac_db_access(AC_USRM_GET_USERQOS_MSG, (BYTE *)& stQosReq, sizeof(stQosReq), (BYTE *)& stQosResp, & ulLength) ;
		if(stQosResp.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, vap(%d/%d/%d), get user("MACSTR") qos failed.\n", 
				__func__, stVapId.ulWtpId, stVapId.ulIfId, stVapId.ulVapId, MAC2STR(sta->addr)) ;
			return ;
		}

		memcpy(& sta->user_qos, & stQosResp.stQos, sizeof(AC_USR_QOS_T)) ;
	}

	return ;
}


/*端口控制*/
static void mac_auth_set_sta_authorized(struct hostapd_data *hapd, struct sta_info *sta, int authorized)
{
	if(hapd == NULL
		|| hapd->iface == NULL
		|| hapd->iface->pstWtp == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	if (authorized) {
		sta->flags |= WLAN_STA_AUTHORIZED_MAC;
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
			"%s, sta(%u/%u/%u/"MACSTR"): authorizing port.\n", 
			__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
	} 
	else {
		sta->flags &= ~WLAN_STA_AUTHORIZED_MAC;
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
			"%s, sta(%u/%u/%u/"MACSTR"): unauthorizing port.\n", 
			__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
	}

	hostapd_set_sta_authorized(hapd, sta, authorized) ;
}


static void mac_auth_disconnect(struct hostapd_data * hapd, struct sta_info * sta)
{
	if(hapd == NULL
		|| hapd->iface == NULL
		|| hapd->iface->pstWtp == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, sta(%u/%u/%u/"MACSTR"): disconnect.\n", 
		__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;

	hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_MAC_AUTH_FAILED | WLAN_REASON_UNSPECIFIED) ;
	sta->flags &= ~(WLAN_STA_AUTH | WLAN_STA_ASSOC | WLAN_STA_AUTHORIZED | WLAN_STA_AUTHORIZED_MAC);
	
	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_register_timeout(0, 0, ap_handle_timer, hapd, sta);
	sta->timeout_next = STA_REMOVE;
}


/*AC代理终端发起MAC认证请求*/
static void mac_auth_req(struct hostapd_data * hapd, struct sta_info * sta)
{
	AC_USER_DATA_QOS_T user_qos = {0} ;
	u32 session_timeout =0, acct_interim_interval = 0 ;
	int res ;
		
	if(hapd == NULL
		|| hapd->iface == NULL
		|| hapd->iface->pstWtp == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	res = hostapd_allowed_address(hapd, sta->addr, NULL, 0, & session_timeout, & acct_interim_interval, NULL, & user_qos) ;	
	switch(res){
	case HOSTAPD_ACL_REJECT :{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, sta(%u/%u/%u/"MACSTR") is not allowed to authenticate.\n", 
			__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
		mac_auth_disconnect(hapd, sta) ;
		return ;
	}
	case HOSTAPD_ACL_PENDING :{
		if(sta->access_reason == WLAN_REASON_ACCESS_HANDOVER){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, sta(%u/%u/%u/"MACSTR") is allowed to authenticate, due to handover.\n", 
				__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
			sta->flags |= WLAN_STA_AUTHORIZED_MAC ;

			if(! hapd->conf->ieee802_1x){
				mac_auth_update_sta_identity(hapd, sta) ;
				/*QOS信息在切换时，从OLD STA拷贝，故此处无需获取QOS信息*/
			}
			
			return ;	
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, sta(%u/%u/%u/"MACSTR") waiting for external authentication.\n", 
				__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr)) ;
			mac_auth_set_sta_authorized(hapd, sta, 0) ;
			return ;
		}
	}
	case HOSTAPD_ACL_ACCEPT_TIMEOUT: {
		ap_sta_session_timeout(hapd, sta, session_timeout) ;

		/*follow on*/
	}
	case HOSTAPD_ACL_ACCEPT :{
		if (acct_interim_interval > 60){
			sta->acct_interim_interval = acct_interim_interval;
		}

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, sta(%u/%u/%u/"MACSTR") is allowed to authenticate, due to it's in accept_mac_list or acl_cache (%s).\n", 
			__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(sta->addr), res == HOSTAPD_ACL_ACCEPT_TIMEOUT ? "accept timeout" : "accept") ;
		sta->flags |= WLAN_STA_AUTHORIZED_MAC ;

		mac_auth_update_sta_identity(hapd, sta) ;
		mac_auth_update_sta_info(hapd, sta, & user_qos) ;
		
		return  ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, unknown res(%d).\n", __func__, res) ;
		return ;
	}

	return ;
}

/*MAC认证：允许接入*/
static void mac_auth_ack(struct hostapd_data * hapd, struct sta_info * sta, void * ext)
{
	if(hapd == NULL
		|| sta == NULL
		|| ext == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	mac_auth_update_sta_identity(hapd, sta) ;
	mac_auth_update_sta_info(hapd, sta, ext) ;

	mac_auth_set_sta_authorized(hapd, sta, 1) ;
}


/*MAC认证：拒绝接入*/
static void mac_auth_nack(struct hostapd_data * hapd, struct sta_info * sta)
{
	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	mac_auth_disconnect(hapd, sta) ;
}


/*MAC认证：请求超时*/
static void mac_auth_timeout(struct hostapd_data * hapd, struct sta_info * sta)
{
	if(hapd == NULL
		|| sta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	mac_auth_disconnect(hapd, sta) ;
}

/*MAC认证事件分发*/
void mac_auth_event(struct hostapd_data * hapd, u8 * addr, u32 event, void * ext)
{
	struct sta_info * sta = NULL ;
	
	if(hapd == NULL
		|| hapd->iface == NULL
		|| hapd->iface->pstWtp == NULL
		|| addr == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	if((sta = ap_get_sta(hapd, addr)) == NULL)
		return ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
		"%s, sta(%u/%u/%u/"MACSTR") recv mac auth event(%d).\n", 
		__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(addr), event) ;
	switch(event){
	case MAC_AUTH_EVENT_REQ :
		mac_auth_req(hapd, sta) ;
		break ;
	case MAC_AUTH_EVENT_ACK :
		mac_auth_ack(hapd, sta, ext) ;
		break ;
	case MAC_AUTH_EVENT_NACK :
		mac_auth_nack(hapd, sta) ;
		break ;
	case MAC_AUTH_EVENT_REQ_TIMEOUT :
		mac_auth_timeout(hapd, sta) ;
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, unknown event(%u).\n", __func__, event) ;
		break ;
	}
}
