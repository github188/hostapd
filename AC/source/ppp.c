#include "OssApi.h"
#include "ac_public.h"
#include "ac_devm_public.h"
#include "ac_usrm_public.h"
#include "ac_pa_public.h"

#include "includes.h"
#include "common.h"
#include "hostapd.h"
#include "ieee802_11.h"
#include "radius.h"
#include "radius_client.h"
#include "accounting.h"
#include "ieee802_11_auth.h"
#include "eloop.h"
#include "ap.h"
#include "sta_info.h"
#include "driver.h"
#include "ppp.h"

#include "syslog_public.h"
#include "syslog_common.h"




#define RADIUS_PPP_TIMEOUT		10



struct hostapd_ppp_auth_data {
	macaddr addr ;
	u8 radius_id ;

	u8 user_name[255] ;		/*以'\0'结束*/
	u8 password[255] ;		
	u8 password_len ;
	u8 chap_id ;				/*only for chap*/
	u8 chap_challenge[16] ;	/*only for chap/md5*/

	u8 nas_ip[4] ;
	u8 nas_id[256] ;
	u8 framed_ip[4];    /* 为了添加framed-ip ， chary  , 2011.5.4 */

	macaddr bssid ;
	u8 ssid[34] ;
	
	u16 usAssocId ;
	u32 ulVlanId;
    u32 ulUserSuffix;  /*选择是否携带用户后缀名*/

	u32 ulSessionTimeout ;
	u32 ulAcctInterimInterval ;
    u32 ulIdleTimeout; 

	AC_USR_QOS_T user_qos;

	void * ctx ;				/*认证上下文，此处为PORTAL认证请求包*/
	time_t timestamp ;		
	struct hostapd_ppp_auth_data *next ;	/*队列头为最新认证请求帧*/
	u32 radius_setid;
	u8 acUserGroupName[128];/*add for user qos 20131015*/
};


struct radius_client_data * g_pstRadiusPpp = NULL ;
struct radius_client_data * g_pstRadiusPppSet[RADIUS_PPP_POOLS_SIZE] = {NULL};
static struct hostapd_ppp_auth_data * g_pstPppAuth = NULL ;
UINT32 g_ulDeUserName = 0;
UINT32 g_ulMacAddrFmt = 0;
UINT32 g_ulMacAddrStyle = 0;
UINT32 g_ulAliveCheck = 0;


static struct radius_client_data * hostapd_radius_ppp_get_bymac(struct hostapd_ppp_auth_data * ppp, UINT8 *UserName, UINT32 ulLenUserName); /* 不同用户名，不同server，chary，2011-11-11 */
extern VOID ac_db_access(UINT32 ulMsgId, UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern void syslogu(int iLogModule, int iLogLevel, const char *szLogFormat, ...);
extern void radius_msg_get_qos_info(struct radius_msg * msg, AC_USR_QOS_T * pstQos);

static void hostapd_ppp_free(struct hostapd_ppp_auth_data * ppp)
{
	if(ppp){
		VM_FREE(ppp->ctx) ;
		ppp->ctx = NULL ;
	}
}


#if 0
int hostapd_radius_portal_logon(BYTE * notify, UINT16 len)
{
	AC_PA_HOSTAPD_AUTH_OVER_NTF_T * logon = NULL ;
	struct sta_info * sta = NULL ;
	
	if((logon = (AC_PA_HOSTAPD_AUTH_OVER_NTF_T *)notify) == NULL ||
		len != sizeof(AC_PA_HOSTAPD_AUTH_OVER_NTF_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, point is NULL, or len(%d) != sizeof(AC_PA_HOSTAPD_AUTH_OVER_NTF_T)(%d).\n", 
			__func__, len, sizeof(AC_PA_HOSTAPD_AUTH_OVER_NTF_T)) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, portal user(No.%u, "IPSTR", "MACSTR"), log on.\n", 
		__func__, logon->usSerialNo, IP2STR(logon->aucUserIP), MAC2STR(logon->aucUserMac)) ;

	if((sta = global_sta_get(logon->aucUserMac)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, can not find user("MACSTR").\n", 
			__func__, MAC2STR(logon->aucUserMac)) ;
		return 0 ;
	}

	/*开始计费*/
	accounting_sta_start(sta->ctx, sta) ;
	
	return 0 ;
}


int hostapd_radius_portal_logoff(BYTE * notify, UINT16 len)
{
	AC_PA_HOSTAPD_LOGOUT_NTF_T * logoff = NULL ;
	struct sta_info * sta = NULL ;
	
	if((logoff = (AC_PA_HOSTAPD_LOGOUT_NTF_T *)notify) == NULL ||
		len != sizeof(AC_PA_HOSTAPD_LOGOUT_NTF_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, point is NULL, or len(%d) != sizeof(AC_PA_HOSTAPD_LOGOUT_NTF_T)(%d).\n", 
			__func__, len, sizeof(AC_PA_HOSTAPD_LOGOUT_NTF_T)) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, portal user(No.%u, "IPSTR", "MACSTR"), log off.\n", 
		__func__, logoff->usSerialNo, IP2STR(logoff->aucUserIP), MAC2STR(logoff->aucUserMac)) ;

	if((sta = global_sta_get(logoff->aucUserMac)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, can not find user("MACSTR").\n", 
			__func__, MAC2STR(logoff->aucUserMac)) ;
		return 0 ;
	}

	/*停止计费*/
	accounting_sta_stop(sta->ctx, sta) ;
	
	return 0 ;
}
#endif

#if 0
static int hostapd_get_associd(u_int8_t * mac, u_int16_t * assoc_id)
{
	AC_USRM_GET_USERINFO_REQ_T stReq = {{0}} ;
	AC_USRM_GET_USERINFO_RSP_T stRsp = {0} ;
	UINT32 ulLen = 0 ;
	
	if(mac == NULL ||
		assoc_id == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	os_memcpy(stReq.aucMac, mac, 6) ;
	ac_db_access(AC_USRM_GET_USERINFO_MSG, (UINT8 *)& stReq, sizeof(stReq), (UINT8 *)& stRsp, & ulLen) ;
	if(stRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, "MACSTR", db access failed.\n", __func__, MAC2STR(stReq.aucMac)) ;
		return -2 ;
	}

	* assoc_id = stRsp.stUserInfo.stAcctInfo.ulAssocId ;
	
	return 0 ;
}
#endif

static int hostapd_get_info(struct hostapd_ppp_auth_data * ppp)
{
	AC_USRM_GET_USERINFO_REQ_T stReq = {{0}} ;
	AC_USRM_GET_USERINFO_RSP_T stRsp = {0} ;
	UINT32 ulLen = 0 ;
	
	if(ppp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	os_memcpy(stReq.aucMac, ppp->addr, 6) ;
	ac_db_access(AC_USRM_GET_USERINFO_MSG, (UINT8 *)& stReq, sizeof(stReq), (UINT8 *)& stRsp, & ulLen) ;
	if(stRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, "MACSTR", db access failed.\n", __func__, MAC2STR(stReq.aucMac)) ;
		return -2 ;
	}

	os_memcpy(ppp->bssid, stRsp.stUserInfo.stAcctInfo.aucVapMac, 6) ;
	os_memcpy(ppp->ssid, stRsp.stUserInfo.stAcctInfo.acVapSsid, sizeof(stRsp.stUserInfo.stAcctInfo.acVapSsid)) ;
	ppp->usAssocId = stRsp.stUserInfo.stAcctInfo.ulAssocId ;
	
	return 0 ;
}


static int hostapd_radius_pap_auth(struct hostapd_ppp_auth_data * pap)
{
	struct radius_client_data * radius = NULL;
	struct radius_msg *msg;
	char buf[128], bssid_zero[6] = {0} ;
	UINT8 framed_ip_zero[4]={0};
    UINT32 ulUserNameLen = 0;
    CHAR *pcEnd =  NULL;
	if(pap == NULL ||
		g_pstRadiusPpp == NULL ||
		g_pstRadiusPpp->conf == NULL ||
		g_pstRadiusPpp->conf->auth_server == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, sta("MACSTR") request for pap auth, name(%s), time(%u)",
		__func__, MAC2STR(pap->addr), pap->user_name, pap->timestamp) ;

    ulUserNameLen = strlen(pap->user_name);

	/* 不同用户名，不同server，chary，2011-11-11 */
	radius = hostapd_radius_ppp_get_bymac(pap,pap->user_name, ulUserNameLen);

	pap->radius_setid = radius->radius_setid;
	pap->radius_id = radius_client_get_id(radius);
	msg = radius_msg_new(RADIUS_CODE_ACCESS_REQUEST, pap->radius_id);
	if (msg == NULL)
		return -1;

	radius_msg_make_authenticator(msg, pap->addr, ETH_ALEN);


    if(pap->ulUserSuffix != 0  && (pcEnd = os_strchr(pap->user_name, '@')) != NULL){   
		*pcEnd = '\0';
    }
    if(os_strlen(pap->user_name) > 0 ){
            ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, sta("MACSTR") request for pap auth, name(%s),take_suffix =%d",
		__func__, MAC2STR(pap->addr), pap->user_name,pap->ulUserSuffix) ;

    }

    
	if(!radius_msg_add_attr(msg, RADIUS_ATTR_USER_NAME, (u8 *)pap->user_name, os_strlen(pap->user_name))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Name.\n", __func__) ;
		goto fail;
	}

	if(!radius_msg_add_attr_user_password(
		msg, (u8 *)pap->password, pap->password_len,
		radius->conf->auth_server->shared_secret,
		radius->conf->auth_server->shared_secret_len)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Password.\n", __func__) ;
		goto fail;
	}

	if (!radius_msg_add_attr(msg, RADIUS_ATTR_NAS_IP_ADDRESS, pap->nas_ip, 4)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-IP-Address.\n", __func__) ;
		goto fail;
	}

	if (os_strlen(pap->nas_id) != 0 &&
		!radius_msg_add_attr(msg, RADIUS_ATTR_NAS_IDENTIFIER, pap->nas_id, os_strlen(pap->nas_id))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-Identifier.\n", __func__) ;
		goto fail;
	}


	/*  移动特定MAC格式，chary，2011-11-15*/
	if(1 == g_ulMacAddrFmt)
		snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_OEM_FORMAT":%s", MAC2STR(pap->bssid), pap->ssid);
	else
		snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_FORMAT":%s", MAC2STR(pap->bssid), pap->ssid) ;
	
	if(os_memcmp(pap->bssid, bssid_zero, sizeof(bssid_zero)) != 0 &&
		os_strlen(pap->ssid) != 0 &&
		! radius_msg_add_attr(msg, RADIUS_ATTR_CALLED_STATION_ID, (u8 *)buf, os_strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Called-Station-Id.\n", __func__) ;
		goto fail;
	}

	/*  移动特定MAC格式，chary，2011-11-15*/
	if(1 == g_ulMacAddrFmt)
		snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_OEM_FORMAT, MAC2STR(pap->addr));
	else
		snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_FORMAT, MAC2STR(pap->addr));
	
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_CALLING_STATION_ID, (u8 *) buf, os_strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Calling-Station-Id.\n", __func__) ;
		goto fail;
	}

#if 0
	snprintf(buf, sizeof(buf), "%u", pap->usAssocId) ;
	if(pap->usAssocId != 0 &&
		! radius_msg_add_attr(msg, RADIUS_ATTR_NAS_PORT_ID, (u8 *)buf, strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Nas-Port-Id.\n", __func__);
		goto fail;
	}
#else
	snprintf(buf, sizeof(buf), "000000%04d", pap->ulVlanId) ;
	if(! radius_msg_add_attr(msg, RADIUS_ATTR_NAS_PORT_ID, (u8 *)buf, strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Nas-Port-Id.\n", __func__);
		goto fail;
	}
#endif
  
       if ((os_memcmp(pap->framed_ip, framed_ip_zero, 4)!=0)&&(!radius_msg_add_attr(msg, RADIUS_ATTR_FRAMED_IP_ADDRESS, (const u8 *)&(pap->framed_ip), 4))){         /* 给framed-ip属性添加属性名, chary, 2011.4.29 */
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,                                                        /****************************************************/
			"%s, Could not add Framed-IP-Address.\n", __func__) ;                                        /****************************************************/
		goto fail;
	}
	   
	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_NAS_PORT_TYPE, RADIUS_NAS_PORT_TYPE_IEEE_802_11)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-Port-Type.\n", __func__) ;
		goto fail;
	}

    /*print ACC-AUTH for PPP-CHAP*/
    
	syslogu(LM_BUSINESS,LOG_EMERG,"Radius Message:Access-Request/PAP,"
		"UserName:%s, UserIP:"IP_FMT",UserMac:"MAC_FMT","
		"SSID:%s, BSSID:"MAC_FMT","	
		"NASIP("IP_FMT"),NASID(%s).",
		pap->user_name, IP_ARG(pap->framed_ip), MAC_ARG(pap->addr),
		pap->ssid, MAC_ARG(pap->bssid),	
		IP_ARG(pap->nas_ip),pap->nas_id);
   /*end*/
	radius_client_send(radius, msg, RADIUS_AUTH, pap->addr) ;
	return 0;

 fail:
	radius_msg_free(msg);
	VM_FREE(msg);
	
	return -1;
}


static int hostapd_radius_chap_auth(struct hostapd_ppp_auth_data * chap)
{
	struct radius_client_data * radius = NULL;
	struct radius_msg *msg;
	char buf[256], bssid_zero[6] = {0} ;
	UINT8  framed_ip_zero[4]={0};
    UINT32 ulUserNameLen = 0;
    char * pcEnd = NULL;

	if(chap == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, sta("MACSTR") request for chap auth, name(%s), id(%d), time(%u)",
		__func__, MAC2STR(chap->addr), chap->user_name, chap->chap_id, chap->timestamp) ;

    ulUserNameLen = strlen(chap->user_name);

	/* 不同用户名，不同server，chary，2011-11-11 */
	radius = hostapd_radius_ppp_get_bymac(chap, chap->user_name, ulUserNameLen);
	
	chap->radius_setid = radius->radius_setid;
	chap->radius_id = radius_client_get_id(radius);
	msg = radius_msg_new(RADIUS_CODE_ACCESS_REQUEST, chap->radius_id);
	if (msg == NULL)
		return -1;

	radius_msg_make_authenticator(msg, chap->addr, ETH_ALEN);


	if(chap->ulUserSuffix != 0  && (pcEnd = os_strchr(chap->user_name, '@')) != NULL){   
		*pcEnd = '\0';
    }
    if(os_strlen(chap->user_name) > 0){
    	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
			"%s, sta("MACSTR") request for pap auth, name(%s),take_suffix = %d",
			__func__, MAC2STR(chap->addr), chap->user_name,chap->ulUserSuffix) ;
    }
    
	if(!radius_msg_add_attr(msg, RADIUS_ATTR_USER_NAME, (u8 *)chap->user_name, os_strlen(chap->user_name))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add User-Name.\n", __func__) ;
		goto fail;
	}

	buf[0] = chap->chap_id ;
	os_memcpy(& buf[1], chap->password, chap->password_len) ;
	if(! radius_msg_add_attr(msg, RADIUS_ATTR_CHAP_PASSWORD, (u8 *)buf, chap->password_len+1)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Chap-Password.\n", __func__) ;
		goto fail ;
	}

	if(! radius_msg_add_attr(msg, RADIUS_ATTR_CHAP_CHALLENGE, (u8 *)chap->chap_challenge, sizeof(chap->chap_challenge))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Chap-Password.\n", __func__) ;
		goto fail ;
	}

	if (!radius_msg_add_attr(msg, RADIUS_ATTR_NAS_IP_ADDRESS, chap->nas_ip, 4)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-IP-Address.\n", __func__) ;
		goto fail;
	}

	if (os_strlen(chap->nas_id) != 0 &&
	    !radius_msg_add_attr(msg, RADIUS_ATTR_NAS_IDENTIFIER, chap->nas_id, os_strlen(chap->nas_id))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-Identifier.\n", __func__) ;
		goto fail;
	}

	/*  移动特定MAC格式，chary，2011-11-15*/
	if(1 == g_ulMacAddrFmt){

			snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_OEM_FORMAT":%s", MAC2STR(chap->bssid), chap->ssid);
    }
	else{

			snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_FORMAT":%s", MAC2STR(chap->bssid), chap->ssid) ;
    }
	
	if(os_memcmp(chap->bssid, bssid_zero, sizeof(bssid_zero)) != 0 &&
		os_strlen(chap->ssid) != 0 &&
		! radius_msg_add_attr(msg, RADIUS_ATTR_CALLED_STATION_ID, (u8 *)buf, os_strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Called-Station-Id.\n", __func__) ;
		goto fail;
	}

	/*  移动特定MAC格式，chary，2011-11-15*/
	if(1 == g_ulMacAddrFmt){
        if(g_ulMacAddrStyle)
        {
			snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_OEM_LITTLE_FORMAT, MAC2STR(chap->addr));
        }else{        
       		snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_OEM_FORMAT, MAC2STR(chap->addr));
        }
    }
	else{
        if(g_ulMacAddrStyle){
			snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_LITTLE_FORMAT, MAC2STR(chap->addr));
        }else{
			snprintf(buf, sizeof(buf), RADIUS_802_1X_ADDR_FORMAT, MAC2STR(chap->addr));
        }

    }
	
	if (!radius_msg_add_attr(msg, RADIUS_ATTR_CALLING_STATION_ID, (u8 *) buf, os_strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Calling-Station-Id.\n", __func__) ;
		goto fail;
	}

#if 0
	snprintf(buf, sizeof(buf), "%u", chap->usAssocId) ;
	if(! radius_msg_add_attr(msg, RADIUS_ATTR_NAS_PORT_ID, (u8 *)buf, strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Nas-Port-Id.\n", __func__);
		goto fail;
	}
#else
	snprintf(buf, sizeof(buf), "000000%04d", chap->ulVlanId) ;
	if(! radius_msg_add_attr(msg, RADIUS_ATTR_NAS_PORT_ID, (u8 *)buf, strlen(buf))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add Nas-Port-Id.\n", __func__);
		goto fail;
	}
#endif


       if ((os_memcmp(chap->framed_ip, framed_ip_zero, 4)!=0)&&(!radius_msg_add_attr(msg, RADIUS_ATTR_FRAMED_IP_ADDRESS, (const u8 *)&(chap->framed_ip), 4))){         /* 给framed-ip属性添加属性名, chary, 2011.4.29 */
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,                                                        /****************************************************/
			"%s, Could not add Framed-IP-Address.\n", __func__) ;                                        /****************************************************/
		goto fail;
	}

	   
	if (!radius_msg_add_attr_int32(msg, RADIUS_ATTR_NAS_PORT_TYPE, RADIUS_NAS_PORT_TYPE_IEEE_802_11)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Could not add NAS-Port-Type.\n", __func__) ;
		goto fail;
	}

   /*print ACC-AUTH for PPP-CHAP*/
	syslogu(LM_BUSINESS,LOG_EMERG,"Radius Message:Access-Request/CHAP,"
		"UserName:%s, UserIP:"IP_FMT",UserMac:"MAC_FMT","
		"SSID:%s, BSSID:"MAC_FMT","	
		"NASIP("IP_FMT"),NASID(%s).",
		chap->user_name, IP_ARG(chap->framed_ip), MAC_ARG(chap->addr),
		chap->ssid, MAC_ARG(chap->bssid),	
		IP_ARG(chap->nas_ip),chap->nas_id);
   /*end*/
	
	radius_client_send(radius, msg, RADIUS_AUTH, chap->addr) ;
	return 0;

 fail:
	radius_msg_free(msg);
	VM_FREE(msg);
	
	return -1;
}


int hostapd_radius_ppp_req(BYTE * req, UINT16 len)
{
	AC_PA_HOSTAPD_AUTH_REQ_T * auth_req = NULL ;
	struct hostapd_ppp_auth_data * ppp = NULL ;
	/* UINT8	UserName[256] = {0}; */
	/* UINT32	ulLenUserName = 0; */
	/* char * pcEnd = NULL; */
	
	if((auth_req = (AC_PA_HOSTAPD_AUTH_REQ_T *)req) == NULL
		|| len != sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, point is NULL, or len(%d) != sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)(%d).\n", 
			__func__, len, sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)) ;
		return -1 ;	
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, user(NO.%u,"IPSTR","MACSTR") req ppp auth(type: %d), name(%s), vlanid(%d).",
		__func__, auth_req->usSerialNo, IP2STR(auth_req->aucUserIP), MAC2STR(auth_req->aucUserMac), auth_req->ucAuthType, auth_req->acUserName, auth_req->ulVlanId) ;

	if(g_pstRadiusPpp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, g_pstRadiusPpp is not init.\n", __func__) ;
		return 0 ;
	}

	/*即使已存在相同终端的PPP认证请求帧，也代理该终端发送认证请求帧*/
	
	if((ppp = VM_ZALLOC(sizeof(struct hostapd_ppp_auth_data))) == NULL ||
		(ppp->ctx = VM_ZALLOC(sizeof(AC_PA_HOSTAPD_AUTH_REQ_T))) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, zalloc failed.\n", __func__) ;
		goto fail ;
	}
		 
        os_memcpy(ppp->framed_ip , auth_req->aucUserIP, 4);             /*  将framed-ip添加到消息中， chary , 2011.5.4 */
        ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,  "Add  the framed-ip into the ppp-MSG successfully");		

	os_memcpy(ppp->addr, auth_req->aucUserMac, sizeof(auth_req->aucUserMac)) ;
	os_strncpy(ppp->user_name, auth_req->acUserName, sizeof(ppp->user_name)-1) ;

	ppp->password_len = auth_req->ucPasswordLen ;
	os_memcpy(ppp->password, auth_req->acPassword, ppp->password_len) ;
	ppp->chap_id = auth_req->ucChallengeID ;
	os_memcpy(ppp->chap_challenge, auth_req->aucChallenge, sizeof(auth_req->aucChallenge)) ;
	os_memcpy(ppp->nas_ip, auth_req->aucNasIp, sizeof(auth_req->aucNasIp)) ;
	os_strncpy(ppp->nas_id, auth_req->acNasId, sizeof(ppp->nas_id)-1) ;
	ppp->ulVlanId = auth_req->ulVlanId;
#if 1
	if(hostapd_get_info(ppp) != 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, user(%s: "MACSTR"), get user info failed.\n",
			__func__, ppp->user_name, MAC2STR(ppp->addr)) ;
	}
#else
	if(hostapd_get_associd(ppp->addr, & ppp->usAssocId) != 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, user(%s: "MACSTR"), get assoc id failed.\n",
			__func__, ppp->user_name, MAC2STR(ppp->addr)) ;
		//goto fail ;
	}
#endif
	os_memcpy(ppp->ctx, auth_req, sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)) ;
	time(& ppp->timestamp) ;

	switch(auth_req->ucAuthType){
	case PORTAL_AUTH_TYPE_PAP:
		if(hostapd_radius_pap_auth(ppp) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, user(%s: "MACSTR"), pap_auth request failed.\n",
				__func__, ppp->user_name, MAC2STR(ppp->addr)) ;
			goto fail ;
		}
		break ;
	case PORTAL_AUTH_TYPE_CHAP:
		if(hostapd_radius_chap_auth(ppp) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, sta(%s: "MACSTR"), chap_auth request failed.\n",
				__func__, ppp->user_name, MAC2STR(ppp->addr)) ;
			goto fail ;
		}
		break ;
	default:
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, sta(%s: "MACSTR"), unknown authtype(%d).\n",
			__func__, ppp->user_name, MAC2STR(ppp->addr), auth_req->ucAuthType) ;
		goto fail ;
	}

	ppp->next = g_pstPppAuth ;
	g_pstPppAuth = ppp ;

	//g_stStats.ulRadiusAuthReq2++;            /* change the attribute to the next line, 2011.4.6 , chary */
       g_stStats.ulRadiusAuthReq++;              /***********************************************/

	return 0 ;

fail:
	hostapd_ppp_free(ppp) ;
	VM_FREE(ppp) ;

	return -1 ;
}


/*向PA线程响应PPP认证消息*/
static int hostapd_radius_ppp_resp(struct hostapd_ppp_auth_data * ppp, int fail)
{
	AC_PA_HOSTAPD_AUTH_REQ_T * req = NULL ;
	AC_PA_HOSTAPD_AUTH_ACK_T resp = {{0}} ;
	TPID stReceiver = {0} ;
	
	if(ppp == NULL ||
		(req = ppp->ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	syslogu(LM_BUSINESS,LOG_EMERG,"Radius Message:Access-%s,"
		"UserName:%s, UserIP:"IP_FMT",UserMac:"MAC_FMT","
		"SSID:%s, BSSID:"MAC_FMT","	
		"NASIP("IP_FMT"),NASID(%s).",
		fail?"Reject":"Accept",
		ppp->user_name, IP_ARG(ppp->framed_ip), MAC_ARG(ppp->addr),
		ppp->ssid, MAC_ARG(ppp->bssid),	
		IP_ARG(ppp->nas_ip),ppp->nas_id);
		
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, user(NO.%u,"IPSTR","MACSTR") resp ppp auth(type: %d), name(%s), %s," 
		"session_timeout(%d s), acct_interim_interval(%d s) idle-timeout (%d s)."
		"qos(priority: %d, up: [%d, %d]kbps, down: [%d, %d]kbps).",
		__func__, req->usSerialNo, IP2STR(req->aucUserIP), MAC2STR(req->aucUserMac), req->ucAuthType, req->acUserName, fail ? "FAIL" : "SUCCESS", 
		ppp->ulSessionTimeout, ppp->ulAcctInterimInterval,ppp->ulIdleTimeout,
		ppp->user_qos.ulPriority, ppp->user_qos.ulUpBandMin, ppp->user_qos.ulUpBandMax, ppp->user_qos.ulDownBandMin, ppp->user_qos.ulDownBandMax) ;

	os_memcpy(resp.aucUserIP, req->aucUserIP, sizeof(req->aucUserIP)) ;
	os_memcpy(resp.aucUserMac, req->aucUserMac, sizeof(req->aucUserMac)) ;
	resp.usSerialNo = req->usSerialNo ;
/*begin bug#1928 cmcc test fangz 2013.2.20*/
	resp.ulAuthResult = fail ;
/*end bug#1928 cmcc test fangz 2013.2.20*/
	resp.ulAcctInterimInterval = ppp->ulAcctInterimInterval;
	resp.ulSessionTimeout = ppp->ulSessionTimeout ;
    resp.ulIdleTimeOut = ppp->ulIdleTimeout;
	os_memcpy(&resp.stQos, &ppp->user_qos, sizeof(ppp->user_qos));
	strncpy(resp.acUserGroupName, ppp->acUserGroupName, strlen(ppp->acUserGroupName));/*add for filterID 20131015*/
		
	VmGetPid("AppPaProc", & stReceiver) ;
	if(! VmASend(EV_AC_PA_HOSTAPD_AUTH_ACK_MSG, (BYTE *)& resp, sizeof(resp), stReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, hostapd-->pa, send EV_AC_PA_HOSTAPD_AUTH_ACK_MSG faild for sta("MACSTR").\n",
			__func__, MAC2STR(req->aucUserMac)) ;
		return -2 ;
	}
	
	return 0 ;
}


/* Return 0 if RADIUS message was a reply to ppp query (and was processed here)
 * or -1 if not. */
static RadiusRxResult
hostapd_radius_ppp_recv_radius(struct radius_msg *msg, struct radius_msg *req,
			u8 *shared_secret, size_t shared_secret_len,
			void *data)
{
	struct radius_client_data * radius = NULL;
	struct hostapd_ppp_auth_data * auth, * prev ;

	if(msg == NULL ||
		req == NULL ||
		shared_secret == NULL ||
		(radius = data) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	auth = g_pstPppAuth ;
	prev = NULL ;
	while(auth){
		if(auth->radius_setid == radius->radius_setid
			&& auth->radius_id == msg->hdr->identifier)
			break ;

		prev = auth ;
		auth = auth->next ;
	}
	if(auth == NULL)
		return RADIUS_RX_UNKNOWN ;
	
	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "PPP: Found matching Access-Request "
		      "for RADIUS message (id=%d)\n", auth->radius_id);

	if (radius_msg_verify(msg, shared_secret, shared_secret_len, req, 0)) {
		printf("Incoming RADIUS packet did not have correct "
		       "authenticator - dropped\n");
		return RADIUS_RX_INVALID_AUTHENTICATOR;
	}

	if (msg->hdr->code != RADIUS_CODE_ACCESS_ACCEPT &&
	    msg->hdr->code != RADIUS_CODE_ACCESS_REJECT) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, Unknown RADIUS message code %d to ACL query\n", __func__, msg->hdr->code) ;
		return RADIUS_RX_UNKNOWN;
	}

	if (msg->hdr->code == RADIUS_CODE_ACCESS_ACCEPT){
		/* AC_USER_DATA_QOS_T user_info = {0} ; */
		u_int32_t session_timeout = 0,  acct_interim_interval = 0 ,idle_timeout = 0;
		/* int len ; */
		/*begin add by fangz 20131010 for qos lever*/
		CHAR acFilterId[128];
		memset( acFilterId, 0, sizeof(acFilterId) );
		if(radius_msg_get_attr(msg, RADIUS_ATTR_FILTER_ID, acFilterId, sizeof(acFilterId)) > 0)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
					"%s, user(%s: "MACSTR"), Filter id :%s.\n", 
					__func__, auth->user_name, MAC2STR(auth->addr), acFilterId) ;
			strncpy(auth->acUserGroupName, acFilterId, strlen(acFilterId));
		}
		/*end add by fangz 20131010 for qos lever*/
		if (radius_msg_get_attr_int32(msg, RADIUS_ATTR_SESSION_TIMEOUT, &session_timeout) == 0)
			auth->ulSessionTimeout = session_timeout ;

		if (radius_msg_get_attr_int32(msg, RADIUS_ATTR_ACCT_INTERIM_INTERVAL, & acct_interim_interval) == 0 &&
			acct_interim_interval != 0){
			if(acct_interim_interval < 60)
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
					"%s, user(%s: "MACSTR"), ignored too small Acct-Interim-Interval %d.\n", 
					__func__, auth->user_name, MAC2STR(auth->addr), acct_interim_interval) ;
			else
				auth->ulAcctInterimInterval = acct_interim_interval ;
		}
        if((radius_msg_get_attr_int32(msg,RADIUS_ATTR_IDLE_TIMEOUT, &idle_timeout) == 0) && idle_timeout >= 0)
        {
            auth->ulIdleTimeout =  idle_timeout;
            ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
					"%s, user(%s: "MACSTR"), idle_timeout :%d.\n", 
					__func__, auth->user_name, MAC2STR(auth->addr), idle_timeout) ;
        }

        radius_msg_get_qos_info(msg, &auth->user_qos);
		
              g_stStats.ulRadiusAuthSucc++;  /*  2011.4.6,  chary */

#if 1
		hostapd_radius_ppp_resp(auth, 0) ;
#else
		if(notify_sta_info(hapd, sta)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, sta(%d/%d/%d/"MACSTR"), register success.\n", 
				__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(auth->addr)) ;
			hostapd_radius_ppp_resp(auth->ctx, 0) ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, sta(%d/%d/%d/"MACSTR"), register failed.\n", 
				__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(auth->addr)) ;
			hostapd_radius_ppp_resp(auth->ctx, 1) ;
			hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_USERDB_REGISTER_FAILED | WLAN_REASON_UNSPECIFIED) ;			
		}
#endif
/*begin bug#1928 cmcc test fangz 2013.2.20*/
	} 
	else
	{
		u8 *ucCMCCReply = NULL;
		size_t ulCMCCReplyLen = 0;
		int reason_code = 255;
		radius_msg_get_attr_ptr(msg, RADIUS_ATTR_REPLY_MESSAGE, &ucCMCCReply, &ulCMCCReplyLen, NULL);
		
		if(ucCMCCReply && ulCMCCReplyLen)
		{
			char szReply[256] = {0}, *pch = NULL;
			os_memcpy(szReply, ucCMCCReply, ulCMCCReplyLen);
			pch = os_strchr(szReply, ';');
			if(pch)
			{
				*pch = '\0'; 
				reason_code = atoi(szReply);
			}
	    }
		hostapd_radius_ppp_resp(auth, reason_code) ;
		/*hostapd_radius_ppp_resp(auth, 1) ; */      
        g_stStats.ulRadiusAuthReject++;             /*   add the statistic of reject , 2011.4.6,  chary*/	                                                                                   	                                                                                          
	}
/*end bug#1928 cmcc test fangz 2013.2.20*/
 /* done: */
	if(prev == NULL)
		g_pstPppAuth = auth->next ;
	else
		prev->next = auth->next ;

	hostapd_ppp_free(auth) ;
	VM_FREE(auth) ;

	return RADIUS_RX_PROCESSED;
}


static void hostapd_radius_ppp_auth_expire(void *eloop_ctx, void *timeout_ctx)
{
	struct radius_client_data * radius = NULL;
	struct hostapd_ppp_auth_data * ppp = NULL, * prev = NULL, * next = NULL ;
	time_t now;

	if((radius = eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return;
	}
	
	time(&now);
	
	/*查找第一个超时认证请求帧，该表按时间排序，表头为最新认证请求帧*/
	for(ppp = g_pstPppAuth; ppp && now-ppp->timestamp < RADIUS_PPP_TIMEOUT; prev = ppp, ppp = ppp->next) ;

	while(ppp){
		if(ppp->radius_setid == radius->radius_setid){
			 g_stStats.ulRadiusAuthReqFailed++;         /*  2011.4.6 ,chary*/

			/*begin bug#2249 portal auth fail for much fangz 2013.5.15*/
			hostapd_radius_ppp_resp(ppp, 201);
			/*end bug#2249 portal auth fail for much fangz 2013.5.15*/
			if(prev == NULL)
				g_pstPppAuth = ppp->next;
			else
				prev->next = ppp->next;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
				"%s, user(%s: "MACSTR"), ppp auth req timeout.\n", 
				__func__, ppp->user_name, MAC2STR(ppp->addr)) ;
			next = ppp->next;
			hostapd_ppp_free(ppp) ;
			VM_FREE(ppp) ;
			
			ppp = next ;
			continue;
		}

		prev = ppp;
		ppp = ppp->next;
	}

	eloop_register_timeout(RADIUS_PPP_TIMEOUT, 0, hostapd_radius_ppp_auth_expire, eloop_ctx, timeout_ctx) ;
}


int hostapd_radius_ppp_init(struct radius_client_data ** ppp, struct hostapd_radius_servers * pstRadiusCfg, u32 setid)
{
	if(ppp == NULL
		|| pstRadiusCfg == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	(*ppp) = radius_client_init(NULL, pstRadiusCfg, RADIUS_TYPE_FOR_PPP) ;
	if((*ppp) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, g_stRadiusPpp: radius_client_init failed.\n", __func__) ;
		return -2 ;
	}
	
	if (radius_client_register(*ppp, RADIUS_AUTH, hostapd_radius_ppp_recv_radius, *ppp)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, register ppp auth handle failed.\n", __func__) ;
		return -1 ;
	}

	(*ppp)->radius_setid = setid;

	eloop_register_timeout(RADIUS_PPP_TIMEOUT, 0, hostapd_radius_ppp_auth_expire, *ppp, NULL) ;

	return 0;
}


void hostapd_radius_ppp_deinit(struct radius_client_data ** ppp)
{
	struct hostapd_ppp_auth_data * auth = NULL, *prev = NULL, *next = NULL ;
	
	eloop_cancel_timeout(hostapd_radius_ppp_auth_expire, *ppp, NULL) ;

	auth = g_pstPppAuth;
	while(auth){
		if(auth->radius_setid == (*ppp)->radius_setid){
			if(prev == NULL)
				g_pstPppAuth = auth->next;
			else
				prev->next = auth->next;

			next = auth->next;
			hostapd_ppp_free(auth) ;
			VM_FREE(auth) ;

			auth = next;

			continue;
		}

		prev = auth;
		auth = auth->next;
	}

	radius_client_deinit(*ppp) ;

	return ;
}


int hostapd_radius_ppp_reset(struct radius_client_data *ppp)
{
	if(ppp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}
		
	/*使认证配置生效*/
	if(radius_client_init_auth(ppp, 0)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, g_pstRadiusPpp: radius_client_init_auth failed.\n", __func__) ;
		return -2 ;
	}

	return 0 ;
}


int hostapd_radius_ppp_reset_all(VOID)
{
	int i ;
	
	hostapd_radius_ppp_reset(g_pstRadiusPpp);
	for(i = 0; i < RADIUS_PPP_POOLS_SIZE; i ++)
		if(g_pstRadiusPppSet[i]
			&& g_pstRadiusPppSet[i]->conf)
			hostapd_radius_ppp_reset(g_pstRadiusPppSet[i]);

	return 0;
}


int hostapd_radius_ppp_change(struct radius_client_data *ppp, struct hostapd_radius_server *nserv, struct hostapd_radius_server *oserv, int auth)
{
	if(ppp == NULL ||
		ppp->auth_serv_sock < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, or socket is invalid.\n", __func__) ;
		return -1 ;
	}
		
	return radius_change_server(ppp, nserv, oserv, ppp->auth_serv_sock, ppp->auth_serv_sock6, auth) ;
}


int hostapd_radius_ppp_add(struct hostapd_radius_servers *conf)
{
	int i;
	
	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1;
	}

	for(i = 0; i < RADIUS_PPP_POOLS_SIZE; i ++)
		if(g_pstRadiusPppSet[i] == NULL
			|| g_pstRadiusPppSet[i]->conf == NULL)
			break;
	if(i == RADIUS_PPP_POOLS_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, pools is full(%d).\n", __func__, i) ;
		return 1;
	}

	if(g_pstRadiusPppSet[i] == NULL){
		return hostapd_radius_ppp_init(&g_pstRadiusPppSet[i], conf, i);
	}
	else{
		g_pstRadiusPppSet[i]->conf = conf;
		return hostapd_radius_ppp_reset(g_pstRadiusPppSet[i]);
	}

	return 0;
}


int hostapd_radius_ppp_del(struct hostapd_radius_servers *conf)
{
	int i;
	
	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1;
	}

	for(i = 0; i < RADIUS_PPP_POOLS_SIZE; i ++)
		if(g_pstRadiusPppSet[i]
			&& g_pstRadiusPppSet[i]->conf == conf)
			break;
	if(i == RADIUS_PPP_POOLS_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, can not find this radius client.\n", __func__) ;
		return 0;
	}

	g_pstRadiusPppSet[i]->conf = NULL;
		
	return 0;
}


int hostapd_radius_ppp_update(struct hostapd_radius_servers *conf)
{
	int i;
	
	if(conf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return -1;
	}

	for(i = 0; i < RADIUS_PPP_POOLS_SIZE; i ++)
		if(g_pstRadiusPppSet[i]
			&& g_pstRadiusPppSet[i]->conf == conf)
			break;
	if(i == RADIUS_PPP_POOLS_SIZE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, can not find this radius client.\n", __func__) ;
		return 0;
	}

	return hostapd_radius_ppp_reset(g_pstRadiusPppSet[i]);
}


struct radius_client_data * hostapd_radius_ppp_get(u32 setid)
{
	if(setid >= 0 && setid < RADIUS_PPP_POOLS_SIZE)
		return g_pstRadiusPppSet[setid];
	return g_pstRadiusPpp;
}


static struct radius_client_data * hostapd_radius_ppp_get_bymac(struct hostapd_ppp_auth_data * ppp, UINT8 *UserName, UINT32 ulUserNamelen)
{
	AC_DEVM_GET_STARADIUSSERVERS_REQ_T stRadiusReq = {{0}};
	AC_DEVM_GET_STARADIUSSERVERS_RSP_T stRadiusRsp = {0};
	u32 ulLength, i;

	if(ppp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, pap is NULL.\n", __func__) ;
		return g_pstRadiusPpp;
	}
	os_memcpy(stRadiusReq.aucMac, ppp->addr, 6);

	 /* 不同用户名，不同server，chary，2011-11-11 */
	 if((UserName != NULL) && (ulUserNamelen != 0))
	 {
		memset(stRadiusReq.aucUserName, 0, sizeof(stRadiusReq.aucUserName));
		os_strncpy(stRadiusReq.aucUserName, UserName, sizeof(stRadiusReq.aucUserName));
	 }

	 else
	 {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, "%s, the call-in user-name is valid. \n", __func__);
		goto end;
	 }
	
	ac_db_access(AC_DEVM_GET_STARADIUSSERVERS_MSG, (UINT8 *)&stRadiusReq, sizeof(stRadiusReq), (UINT8 *)&stRadiusRsp, &ulLength);
	if(stRadiusRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, get radius servers by mac+username failed.\n", __func__) ;
		goto end;
	}
    /*获取是否携带User@后缀名功能*/
    ppp->ulUserSuffix = stRadiusRsp.stAAAServers.acIsIncludeSuffix;

    if(ppp->ulUserSuffix != 0 && ppp->ulUserSuffix != 1)
    {
        ppp->ulUserSuffix = 0;
    }
    
	/* 不同用户名，不同server，打印DEVM获取结果，chary，2011-11-11 */
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s, the user_name (%s) is mapping to the radius server "IPSTR",port =%d,take_suffix =%d \n",
	             __func__,UserName,IP2STR(stRadiusRsp.stAAAServers.stAuthSrvMaster.aucIp),stRadiusRsp.stAAAServers.stAuthSrvMaster.ulPort,ppp->ulUserSuffix);
	             

	for(i = 0; i < RADIUS_PPP_POOLS_SIZE; i ++){
        
   		if(g_pstRadiusPppSet[i]
			&& g_pstRadiusPppSet[i]->conf
			&&( (os_memcmp(stRadiusRsp.stAAAServers.stAuthSrvMaster.aucIp, &g_pstRadiusPppSet[i]->conf->auth_servers[0].addr.u.v4, 4) == 0) && 
			  (stRadiusRsp.stAAAServers.stAuthSrvMaster.ulPort == g_pstRadiusPppSet[i]->conf->auth_servers[0].port)))
	   {

          	return g_pstRadiusPppSet[i];

       }
    }

end:
    
	return g_pstRadiusPpp;
}

