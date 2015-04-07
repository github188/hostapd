/*
 * hostapd / Initialization and configuration
 * Copyright (c) 2002-2008, Jouni Malinen <j@w1.fi>
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
//#include "ac_db_kernel.h"
//#include "ac_db_table.h"
#include "ac_db_public.h"
#include "ac_devm_public.h"
#include "ac_usrm_public.h"
#include "ac_acm_public.h"
#include "ac_oma_public.h"
//#include "ac_db_proc.h"

#ifndef CONFIG_NATIVE_WINDOWS
#include <syslog.h>
#endif /* CONFIG_NATIVE_WINDOWS */

#include "eloop.h"
#include "wireless_copy.h"
#include "hostapd.h"
/* #include "ieee802_1x.h" */
#include "ieee802_11.h"
#include "beacon.h"
#include "hw_features.h"
#include "accounting.h"
#include "eapol_sm.h"
#include "iapp.h"
#include "ap.h"
#include "ap_list.h"
#include "sta_info.h"
#include "driver.h"
#include "radius.h"
#include "radius_client.h"
#include "radius_server.h"
#include "ieee802_11_auth.h"
#include "wpa.h"
#include "preauth.h"
#include "wme.h"
#include "vlan_init.h"
#include "ctrl_iface.h"
#include "tls.h"
#include "eap_sim_db.h"
#include "eap.h"
#include "version.h"
#include "net80211/_ieee80211.h"
#include "HostapdSocket.h"
#include "l2_packet.h"
#include "version.h"
#include "radius_alive.h"
#include "ac_pa_public.h"
#include "ppp.h"
#include "hostapd_test.h"
/*begin TASK #476 fangz 2013.2.25 log*/
#include "syslog_public.h"
#include "syslogu.h"
/*end TASK #476 fangz 2013.2.25 log*/


#if 0
struct hapd_interfaces {
	u16 usWtpId ;	/*同设备管理模块中WTP的ID定义*/
	struct hostapd_iface * iface[MAX_INTERFACES] ;
};
#endif

/*WtpId为1，对应pstWtpTable[0]*/
struct hapd_interfaces * g_pstWtpTable[MAX_WTPS] = {0} ;
struct hostapd_radius_servers g_stRadiusServers = {0} ;
struct hostapd_radius_servers * g_pstRadiusServerSet = NULL;

struct hostapd_stats g_stStats = {0};
extern int g_ulStaRoam;
extern UINT32 g_ulDeUserName;
extern UINT32	 g_ulMacAddrFmt;
extern UINT32    g_ulMacAddrStyle;
extern UINT32    g_ulAliveCheck;

unsigned char rfc1042_header[6] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };


extern int wpa_debug_level;
extern int wpa_debug_show_keys;
extern int wpa_debug_timestamp;

static Boolean WtpAdd(AC_DEVM_WTP_CONFIG_T * pstWtpConfig) ;
static Boolean WtpDelete(u16 usWtpId) ;
static Boolean InterfaceAdd(AC_DEVM_IF_CONFIG_T * pstInterfaceConfig) ;
static Boolean InterfaceDelete(u16 usWtpId, u32 ulInterfaceId) ;
static Boolean VapAdd(AC_DEVM_VAP_CONFIG_T * pstVapConfig) ;
static Boolean VapDelete(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId) ;
static void VapStartTimeout(void *eloop_ctx, void *timeout_ctx);

static Boolean VapLoadConfig(struct hostapd_data * pstBss, AC_DEVM_VAP_CONFIG_T * pstVapCfg);
static Boolean InterfaceLoadConfig(struct hostapd_iface * pstInterface, AC_DEVM_IF_CONFIG_T * pstIfConfig);
static Boolean VapDelete(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId);
static BOOL VapLoadMac(AC_DEVM_VAP_MAC_CHG_IND_MSG_T * pstVapMac);
static Boolean VapStart(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId);
static BOOL NotifyVapAdd(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId);
static BOOL NotifyVapDelete(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId);


/* add by leijie */
extern void rsn_preauth_receive(void *ctx, const u8 *src_addr, const u8 *buf, size_t len);

extern void ieee802_1x_new_station(struct hostapd_data *hapd, struct sta_info *sta);
extern void ieee802_1x_deinit(struct hostapd_data *hapd);
extern void ieee802_1x_notify_port_enabled(struct eapol_state_machine *sm,
				    int enabled);
extern void ieee802_1x_notify_port_valid(struct eapol_state_machine *sm,
				  int valid);
extern void ieee802_1x_set_sta_authorized(struct hostapd_data *hapd,
				   struct sta_info *sta, int authorized);
extern u8 * ieee802_1x_get_key_crypt(struct eapol_state_machine *sm, size_t *len);
extern int ieee802_1x_init(struct hostapd_data *hapd);
extern int radius_client_pool_init(struct radius_client_data ** radius_client_pool, struct hostapd_radius_servers *conf, int setid);
extern int radius_client_pool_deinit(struct radius_client_data ** radius_client_pool);
extern int radius_client_pools_add(struct hostapd_radius_servers * conf);
extern int hostapd_radius_ppp_add(struct hostapd_radius_servers *conf);
extern int radius_client_pools_del(struct hostapd_radius_servers * conf);
extern int hostapd_radius_ppp_del(struct hostapd_radius_servers *conf);
extern int radius_client_pools_update(struct hostapd_radius_servers * conf);
extern int hostapd_radius_ppp_update(struct hostapd_radius_servers *conf);
extern int radius_client_pools_reset_all(VOID);
extern int hostapd_radius_ppp_reset_all(VOID);
extern struct hostapd_config * hostapd_config_defaults(void);
extern int hostapd_config_check(struct hostapd_config *conf);
extern void hostapd_config_free_bss(struct hostapd_bss_config *conf);
extern void hostapd_config_defaults_bss(struct hostapd_bss_config *bss);
extern int hostapd_config_bss_read_wep(struct hostapd_wep_keys *wep, int keyidx,
				   char *val, u32 format);
extern int hostapd_config_check_bss(struct hostapd_bss_config *bss,
				    struct hostapd_config *conf);
extern int madwifi_del_sta(struct madwifi_driver_data *drv, u8 addr[ETH_ALEN], u16 usReason);
extern int madwifi_new_sta(struct madwifi_driver_data *drv, u8 * pbData, u_int16_t usReassoc, u_int16_t usAssocId);
extern void madwifi_wireless_event_wireless_custom(struct madwifi_driver_data *drv, char *custom);
extern void handle_read(void *ctx, const u8 *src_addr, const u8 *buf, size_t len);
extern struct radius_client_data * hostapd_radius_ppp_get(u32 setid);
int hostapd_authstat_inc(u8 *addr, u32 ulStatType, u32 ulWtpId, u32 ulVapId)	/* BugId=269,  chary, 2011-11-24   */
{
	AC_USRM_INC_AUTHSTAT_REQ_T stAuthStatReq = {0};
	AC_USRM_INC_AUTHSTAT_RSP_T stAuthStatResp = {0};
	UINT32 ulOutLength = 0;

	if(addr == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, point is NULL.\n", __func__) ;
		return -1;
	}

	stAuthStatReq.ulAuthType =AC_CERT_TYPE_WPA;
	os_memcpy(stAuthStatReq.aucMac, addr, 6);
	stAuthStatReq.ulStatType = ulStatType;
	stAuthStatReq.ulWtpId = ulWtpId;	/* BugId=269,  chary, 2011-11-24   */
	stAuthStatReq.ulVapId = ulVapId;	/* BugId=269,  chary, 2011-11-24   */
	ac_db_access(AC_USRM_INC_AUTHSTAT_MSG, (UINT8 *)&stAuthStatReq, sizeof(stAuthStatReq), (UINT8 *)&stAuthStatResp, &ulOutLength);
	if(stAuthStatResp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, addr("MACSTR"), StatType(%d), ac_db_access failed.\n",
			__func__, MAC2STR(addr), ulStatType);
		return -1;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
					"%s, the authstat is : auth TYPE = %d, auth STAT = %d, from ap%d, vap%d. \n",
					__func__,
					stAuthStatReq.ulAuthType,
					stAuthStatReq.ulStatType,
					stAuthStatReq.ulWtpId,
					stAuthStatReq.ulVapId);
	return 0;
}


/* 2008/07/31 雷杰 将inet_aton函数改名为hostapd_inet_aton，以避免与linux系统中定义的函数原型产生冲突 */
int hostapd_inet_aton(const char *cp, u_int32_t * addr)
{
    unsigned int val;
    int base, n;
    char c;
    u_int parts[4];
    u_int *pp = parts;

    for (;;)
    {

        //Collect number up to ``.''. Values are specified as for C:
        // 0x=hex, 0=octal, other=decimal.

        val = 0;
        base = 10;
        if (*cp == '0')
        {
            if (*++cp == 'x' || *cp == 'X')
                base = 16, cp++;
            else
                base = 8;
        }
        while ((c = *cp) != '\0')
        {
            if (isascii(c) && isdigit(c))
            {
                val = (val * base) + (c - '0');
                cp++;
                continue;

            }
            if (base == 16 && isascii(c) && isxdigit(c))
            {
                val = (val << 4) + (c + 10 - (islower(c) ? 'a' : 'A'));
                cp++;
                continue;
            }
            break;
        }
        if (*cp == '.')
        {
            // Internet format: a.b.c.d a.b.c       (with c treated as
            // 16-bits) a.b         (with b treated as 24 bits)

            if (pp >= parts + 3 || val > 0xff)
                return (0);
            *pp++ = val, cp++;
        } else
            break;
    }

    // Check for trailing characters.

    if (*cp && (!isascii(*cp) || !isspace(*cp)))
        return (0);


    // Concoct the address according to the number of parts specified.

    n = pp - parts + 1;
    switch (n)
    {

    case 1:                    // a -- 32 bits
        break;

    case 2:                    //a.b -- 8.24 bits
        if (val > 0xffffff)
            return (0);
        val |= parts[0] << 24;
        break;

    case 3:                    //a.b.c -- 8.8.16 bits
        if (val > 0xffff)
            return (0);
        val |= (parts[0] << 24) | (parts[1] << 16);
        break;

    case 4:                    // a.b.c.d -- 8.8.8.8 bits
        if (val > 0xff)
            return (0);
        val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
        break;
    }
    if (addr)
        *addr = htonl(val);
    return (1);
}

void hostapd_logger(struct hostapd_data *hapd, const u8 *addr,
		    unsigned int module, int level, const char *fmt, ...)
{
	char *format, *module_str;
	int maxlen;
	va_list ap;
	
#ifndef OSS_LOG
	int conf_syslog_level, conf_stdout_level;
	unsigned int conf_syslog, conf_stdout;
#else
	int level_map[] = {
		APP_DETAIL ,	/*HOSTAPD_LEVEL_DEBUG_VERBOSE*/
		APP_DETAIL , /*HOSTAPD_LEVEL_DEBUG*/
		APP_MSG , 	/*HOSTAPD_LEVEL_INFO*/
		APP_WARN , 	/*HOSTAPD_LEVEL_NOTICE*/
		APP_ERROR 	/*HOSTAPD_LEVEL_WARNING*/
	} ;
#endif

	maxlen = strlen(fmt) + 100;
	format = VM_MALLOC(maxlen);
	if (!format)
		return;

#ifndef OSS_LOG
	if (hapd && hapd->conf) {
		conf_syslog_level = hapd->conf->logger_syslog_level;
		conf_stdout_level = hapd->conf->logger_stdout_level;
		conf_syslog = hapd->conf->logger_syslog;
		conf_stdout = hapd->conf->logger_stdout;
	} else {
		conf_syslog_level = conf_stdout_level = 0;
		conf_syslog = conf_stdout = (unsigned int) -1;
	}
#endif

	switch (module) {
	case HOSTAPD_MODULE_IEEE80211:
		module_str = "IEEE 802.11";
		break;
	case HOSTAPD_MODULE_IEEE8021X:
		module_str = "IEEE 802.1X";
		break;
	case HOSTAPD_MODULE_RADIUS:
		module_str = "RADIUS";
		break;
	case HOSTAPD_MODULE_WPA:
		module_str = "WPA";
		break;
	case HOSTAPD_MODULE_DRIVER:
		module_str = "DRIVER";
		break;
	case HOSTAPD_MODULE_IAPP:
		module_str = "IAPP";
		break;
	case HOSTAPD_MODULE_MLME:
		module_str = "MLME";
		break;
	default:
		module_str = NULL;
		break;
	}

	if (hapd && hapd->conf && addr)
		snprintf(format, maxlen, "%s: STA " MACSTR "%s%s: %s",
			 hapd->conf->iface, MAC2STR(addr),
			 module_str ? " " : "", module_str, fmt);
	else if (hapd && hapd->conf)
		snprintf(format, maxlen, "%s:%s%s %s",
			 hapd->conf->iface, module_str ? " " : "",
			 module_str, fmt);
	else if (addr)
		snprintf(format, maxlen, "STA " MACSTR "%s%s: %s",
			 MAC2STR(addr), module_str ? " " : "",
			 module_str, fmt);
	else
		snprintf(format, maxlen, "%s%s%s",
			 module_str, module_str ? ": " : "", fmt);

#ifndef	OSS_LOG
	if ((conf_stdout & module) && level >= conf_stdout_level) {
		wpa_debug_print_timestamp();
		va_start(ap, fmt);
		vprintf(format, ap);
		va_end(ap);
		printf("\n");
	}

#ifndef CONFIG_NATIVE_WINDOWS
	if ((conf_syslog & module) && level >= conf_syslog_level) {
		int priority;
		switch (level) {
		case HOSTAPD_LEVEL_DEBUG_VERBOSE:
		case HOSTAPD_LEVEL_DEBUG:
			priority = LOG_DEBUG;
			break;
		case HOSTAPD_LEVEL_INFO:
			priority = LOG_INFO;
			break;
		case HOSTAPD_LEVEL_NOTICE:
			priority = LOG_NOTICE;
			break;
		case HOSTAPD_LEVEL_WARNING:
			priority = LOG_WARNING;
			break;
		default:
			priority = LOG_INFO;
			break;
		}
		va_start(ap, fmt);
		vsyslog(priority, format, ap);
		va_end(ap);
	}
#endif /* CONFIG_NATIVE_WINDOWS */

#else	/*OSS_LOG*/
{
	char buf[1024] = {0} ;
	int count ;
	
	va_start(ap, fmt) ;
	count = vsnprintf(buf, sizeof(buf), format, ap) ;
	va_end(ap) ;

	if(count < 0 || count >= sizeof(buf)){
		VM_FREE(format) ;
		return ;
	}
	
	ModuleLogMsg(APP_MODULE_HOSTAPD, level_map[level],"%s", buf) ;
}
#endif	/*OSS_LOG*/

	VM_FREE(format);
}


const char * hostapd_ip_txt(const struct hostapd_ip_addr *addr, char *buf,
			    size_t buflen)
{
	if (buflen == 0 || addr == NULL)
		return NULL;

	if (addr->af == AF_INET) {
		snprintf(buf, buflen, "%s", inet_ntoa(addr->u.v4));
	} else {
		buf[0] = '\0';
	}
#ifdef CONFIG_IPV6
	if (addr->af == AF_INET6) {
		if (inet_ntop(AF_INET6, &addr->u.v6, buf, buflen) == NULL)
			buf[0] = '\0';
	}
#endif /* CONFIG_IPV6 */

	return buf;
}


int hostapd_ip_diff(struct hostapd_ip_addr *a, struct hostapd_ip_addr *b)
{
	if (a == NULL && b == NULL)
		return 0;
	if (a == NULL || b == NULL)
		return 1;

	switch (a->af) {
	case AF_INET:
		if (a->u.v4.s_addr != b->u.v4.s_addr)
			return 1;
		break;
#ifdef CONFIG_IPV6
	case AF_INET6:
		if (memcpy(&a->u.v6, &b->u.v6, sizeof(a->u.v6))
		    != 0)
			return 1;
		break;
#endif /* CONFIG_IPV6 */
	}

	return 0;
}


static void hostapd_deauth_all_stas(struct hostapd_data *hapd)
{
#if 0
	u8 addr[ETH_ALEN];

	memset(addr, 0xff, ETH_ALEN);
	hostapd_sta_deauth(hapd, addr, WLAN_REASON_PREV_AUTH_NOT_VALID);
#else
	/* New Prism2.5/3 STA firmware versions seem to have issues with this
	 * broadcast deauth frame. This gets the firmware in odd state where
	 * nothing works correctly, so let's skip sending this for a while
	 * until the issue has been resolved. */
#endif
}

#if 0
/**
 * hostapd_prune_associations - Remove extraneous associations
 * @hapd: Pointer to BSS data for the most recent association
 * @sta: Pointer to the associated STA data
 *
 * This function looks through all radios and BSS's for previous
 * (stale) associations of STA. If any are found they are removed.
 */
static void hostapd_prune_associations(struct hostapd_data *hapd,
				       struct sta_info *sta)
{
	struct sta_info *osta;
	struct hostapd_data *ohapd;
	size_t i, j;
	struct hapd_interfaces *interfaces = hapd->iface->pstWtp ;

	for (i = 0; i < MAX_INTERFACES ; i++) {
		if(interfaces->iface[i] == NULL)
			continue ;

		for (j = 0; j < MAX_BSSES; j++) {
			ohapd = interfaces->iface[i]->bss[j];
			if (ohapd == NULL || ohapd == hapd)
				continue;
			osta = ap_get_sta(ohapd, sta->addr);
			if (!osta)
				continue;

			ap_sta_disassociate(ohapd, osta,
					    WLAN_REASON_UNSPECIFIED);
		}
	}
}
#endif

/**
 * hostapd_new_assoc_sta - Notify that a new station associated with the AP
 * @hapd: Pointer to BSS data
 * @sta: Pointer to the associated STA data
 * @reassoc: 1 to indicate this was a re-association; 0 = first association
 *
 * This function will be called whenever a station associates with the AP. It
 * can be called for ieee802_11.c for drivers that export MLME to hostapd and
 * from driver_*.c for drivers that take care of management frames (IEEE 802.11
 * authentication and association) internally.
 */
void hostapd_new_assoc_sta(struct hostapd_data *hapd, struct sta_info *sta,
			   int reassoc)
{
	/* add by gwx 2014-6-26 for SSID级用户接入控制*/
	AC_USRM_GET_USERACCESSPERMIT_REQ_T	stReq;
	AC_USRM_GET_USERACCESSPERMIT_RSP_T	stRsp;
	u32 	ulOutLen = 0;
	u32	ulNotAllowAccess = 0;
	
	if (hapd->tkip_countermeasures) {
		hostapd_sta_deauth(hapd, sta->addr,
				   WLAN_REASON_MICHAEL_MIC_FAILURE);
		return;
	}

#if 0	/* instead func named global_sta_handover */
	hostapd_prune_associations(hapd, sta);
#endif

	/* add by gwx 2014-6-26 for SSID级用户接入控制*/
	memset( &stReq, 0, sizeof(stReq) );
	memset( &stRsp, 0, sizeof(stRsp) );
	memcpy( stReq.aucUserMac, sta->addr, 6 );
	memcpy( stReq.acSsidName, sta->ssid->ssid, 32);
	ac_db_access( AC_USRM_GET_USERACCESSPERMIT_MSG, 
					(u8 *)&stReq,
					sizeof(stReq), 
					(u8 *)&stRsp,
					&ulOutLen);
	if( stRsp.ulRet == AC_OK &&
		AC_USRM_NOT_ALLOW_USERACCESS == stRsp.ulAccessPermit )
	{
		ulNotAllowAccess = 1;
	}

	/* IEEE 802.11F (IAPP) */
	if (hapd->conf->ieee802_11f)
		iapp_new_station(hapd->iapp, sta);

	/* Start accounting here, if IEEE 802.1X and WPA are not used.
	 * IEEE 802.1X/WPA code will start accounting after the station has
	 * been authorized. */
	if (!hapd->conf->ieee802_1x && !hapd->conf->wpa && (sta->flags & WLAN_STA_AUTHORIZED_MAC)){
		AC_VAPID_T stVapId = {0} ;
		/* int bPortalAuth = 0 ; */
		
		stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
		stVapId.ulVDevId = hapd->iface->gdev_id ;
		stVapId.ulIfId = hapd->iface->interface_id ;
		stVapId.ulVapId = hapd->vap_id ;
		
		/*负荷均衡/接纳控制*/
		if(ac_acm_is_admit(& stVapId, & sta->user_qos, 0) != AC_OK || ulNotAllowAccess ){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, not permit sta("MACSTR") access vap(%d/%d/%d).\n", 
				__func__, MAC2STR(sta->addr), stVapId.ulWtpId, stVapId.ulIfId, stVapId.ulVapId) ;

			hostapd_sta_disassoc(hapd, sta->addr, WLAN_REASON_DISASSOC_AP_BUSY) ;
			return ;
		}

#if 1
		if(! hapd->conf->wapi &&
			(! notify_sta_add(hapd, sta) || ! notify_sta_info(hapd, sta))){
			hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_USERDB_REGISTER_FAILED | WLAN_REASON_UNSPECIFIED) ;
			return ;
		}

		//accounting_sta_start(hapd, sta);/*add 2013.11.22 for powerac reboot*/
#else
		bPortalAuth = hostapd_portal_auth(hapd, sta->addr) ;
		if(! hapd->conf->wapi &&
			(! notify_sta_add(hapd, sta) ||
			(! bPortalAuth && ! notify_sta_info(hapd, sta)))){
			hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_USERDB_REGISTER_FAILED | WLAN_REASON_UNSPECIFIED) ;
			return ;
		}

		if(! bPortalAuth || hostapd_sta_portal_authorized(hapd, sta->addr))/*wapi??*/
			accounting_sta_start(hapd, sta);
#endif
	}

	hostapd_wme_sta_config(hapd, sta);

	/* Start IEEE 802.1X authentication process for new stations */
	ieee802_1x_new_station(hapd, sta);
	if (reassoc)
		wpa_auth_sm_event(sta->wpa_sm, WPA_REAUTH);
	else
		wpa_auth_sta_associated(hapd->wpa_auth, sta->wpa_sm);
}


#ifdef EAP_SERVER
static int hostapd_sim_db_cb_sta(struct hostapd_data *hapd,
				 struct sta_info *sta, void *ctx)
{
	if (eapol_sm_eap_pending_cb(sta->eapol_sm, ctx) == 0)
		return 1;
	return 0;
}


static void hostapd_sim_db_cb(void *ctx, void *session_ctx)
{
	struct hostapd_data *hapd = ctx;
	if (ap_for_each_sta(hapd, hostapd_sim_db_cb_sta, session_ctx) == 0)
		radius_server_eap_pending_cb(hapd->radius_srv, session_ctx);
}
#endif /* EAP_SERVER */


 void handle_term(int sig, void *eloop_ctx, void *signal_ctx)
{
	printf("Signal %d received - terminating\n", sig);
	eloop_terminate();
}


static void hostapd_wpa_auth_conf(struct hostapd_bss_config *conf,
				  struct wpa_auth_config *wconf)
{
	wconf->wpa = conf->wpa;
	wconf->wpa_key_mgmt = conf->wpa_key_mgmt;
	wconf->wpa_pairwise = conf->wpa_pairwise;
	wconf->wpa_group = conf->wpa_group;
	wconf->wpa_group_rekey = conf->wpa_group_rekey;
	wconf->wpa_strict_rekey = conf->wpa_strict_rekey;
	wconf->wpa_gmk_rekey = conf->wpa_gmk_rekey;
	wconf->rsn_preauth = conf->rsn_preauth;
	wconf->eapol_version = conf->eapol_version;
	wconf->peerkey = conf->peerkey;
	wconf->wme_enabled = conf->wme_enabled;
#ifdef CONFIG_IEEE80211W
	wconf->ieee80211w = conf->ieee80211w;
#endif /* CONFIG_IEEE80211W */
}


#ifndef CONFIG_NATIVE_WINDOWS
 void handle_reload(int sig, void *eloop_ctx, void *signal_ctx)
{
#if 0
	struct hapd_interfaces *hapds = (struct hapd_interfaces *) eloop_ctx;
	struct hostapd_config *newconf;
	size_t i;
	struct wpa_auth_config wpa_auth_conf;

	printf("Signal %d received - reloading configuration\n", sig);

	for (i = 0; i < MAX_INTERFACES ; i++) {
		struct hostapd_data *hapd = NULL ;

		if(hapds->iface[i] == NULL)
			continue ;

		hapd = hapds->iface[i]->bss[0];
		if(! hapd)
			return ;
		newconf = hostapd_config_read(hapds->iface[i]->config_fname);
		if (newconf == NULL) {
			printf("Failed to read new configuration file - "
			       "continuing with old.\n");
			continue;
		}
		/* TODO: update dynamic data based on changed configuration
		 * items (e.g., open/close sockets, remove stations added to
		 * deny list, etc.) */
		radius_client_flush(hapd->radius, 0);
		hostapd_config_free(hapd->iconf);

		hostapd_wpa_auth_conf(&newconf->bss[0], &wpa_auth_conf);
		wpa_reconfig(hapd->wpa_auth, &wpa_auth_conf);

		hapd->iconf = newconf;
		hapd->conf = &newconf->bss[0];
		hapds->iface[i]->conf = newconf;

		if (hostapd_setup_wpa_psk(hapd->conf)) {
			wpa_printf(MSG_ERROR, "Failed to re-configure WPA PSK "
				   "after reloading configuration");
		}
	}
#else
	printf("NULL function.\n") ;
#endif
}


#ifdef HOSTAPD_DUMP_STATE
static void hostapd_dump_state(struct hostapd_data *hapd)
{
	FILE *f;
	time_t now;
	struct sta_info *sta;
	int i;
	char *buf;

	if (!hapd->conf->dump_log_name) {
		printf("Dump file not defined - ignoring dump request\n");
		return;
	}

	printf("Dumping hostapd state to '%s'\n", hapd->conf->dump_log_name);
	f = fopen(hapd->conf->dump_log_name, "w");
	if (f == NULL) {
		printf("Could not open dump file '%s' for writing.\n",
		       hapd->conf->dump_log_name);
		return;
	}

	time(&now);
	fprintf(f, "hostapd state dump - %s", ctime(&now));
	fprintf(f, "num_sta=%d num_sta_non_erp=%d "
		"num_sta_no_short_slot_time=%d\n"
		"num_sta_no_short_preamble=%d\n",
		hapd->num_sta, hapd->iface->num_sta_non_erp,
		hapd->iface->num_sta_no_short_slot_time,
		hapd->iface->num_sta_no_short_preamble);

	for (sta = hapd->sta_list; sta != NULL; sta = sta->next) {
		fprintf(f, "\nSTA=" MACSTR "\n", MAC2STR(sta->addr));

		fprintf(f,
			"  AID=%d flags=0x%x %s%s%s%s%s%s%s%s%s%s\n"
			"  capability=0x%x listen_interval=%d\n",
			sta->aid,
			sta->flags,
			(sta->flags & WLAN_STA_AUTH ? "[AUTH]" : ""),
			(sta->flags & WLAN_STA_ASSOC ? "[ASSOC]" : ""),
			(sta->flags & WLAN_STA_PS ? "[PS]" : ""),
			(sta->flags & WLAN_STA_TIM ? "[TIM]" : ""),
			(sta->flags & WLAN_STA_PERM ? "[PERM]" : ""),
			(sta->flags & WLAN_STA_AUTHORIZED ? "[AUTHORIZED]" :
			 ""),
			(sta->flags & WLAN_STA_PENDING_POLL ? "[PENDING_POLL" :
			 ""),
			(sta->flags & WLAN_STA_SHORT_PREAMBLE ?
			 "[SHORT_PREAMBLE]" : ""),
			(sta->flags & WLAN_STA_PREAUTH ? "[PREAUTH]" : ""),
			(sta->flags & WLAN_STA_NONERP ? "[NonERP]" : ""),
			sta->capability,
			sta->listen_interval);

		fprintf(f, "  supported_rates=");
		for (i = 0; i < sta->supported_rates_len; i++)
			fprintf(f, "%02x ", sta->supported_rates[i]);
		fprintf(f, "\n");

		fprintf(f,
			"  timeout_next=%s\n",
			(sta->timeout_next == STA_NULLFUNC ? "NULLFUNC POLL" :
			 (sta->timeout_next == STA_DISASSOC ? "DISASSOC" :
			  "DEAUTH")));

		ieee802_1x_dump_state(f, "  ", sta);
	}

	buf = VM_MALLOC(4096);
	if (buf) {
		int count = radius_client_get_mib(hapd->radius, buf, 4096);
		if (count < 0)
			count = 0;
		else if (count > 4095)
			count = 4095;
		buf[count] = '\0';
		fprintf(f, "%s", buf);

		count = radius_server_get_mib(hapd->radius_srv, buf, 4096);
		if (count < 0)
			count = 0;
		else if (count > 4095)
			count = 4095;
		buf[count] = '\0';
		fprintf(f, "%s", buf);
		VM_FREE(buf);
	}
	fclose(f);
}
#endif /* HOSTAPD_DUMP_STATE */

#if 0
static void handle_dump_state(int sig, void *eloop_ctx, void *signal_ctx)
{
#ifdef HOSTAPD_DUMP_STATE
	struct hapd_interfaces *hapds = (struct hapd_interfaces *) eloop_ctx;
	size_t i, j;

	for (i = 0; i < MAX_INTERFACES ; i++) {
		struct hostapd_iface *hapd_iface = NULL ;

		if(hapds->iface[i] == NULL)
			continue ;

		hapd_iface = hapds->iface[i];
		for (j = 0; j < MAX_BSSES; j++)
			if(hapd_iface->bss[j])
				hostapd_dump_state(hapd_iface->bss[j]);
	}
#endif /* HOSTAPD_DUMP_STATE */
}
#endif /* CONFIG_NATIVE_WINDOWS */
#endif
static void hostapd_broadcast_key_clear_iface(struct hostapd_data *hapd,
					      char *ifname)
{
	int i;

	for (i = 0; i < NUM_WEP_KEYS; i++) {
		if (hostapd_set_encryption(ifname, hapd, "none", NULL, i, NULL,
					   0, i == 0 ? 1 : 0)) {
			printf("Failed to clear default encryption keys "
			       "(ifname=%s keyidx=%d)\n", ifname, i);
		}
	}
}


static int hostapd_broadcast_wep_clear(struct hostapd_data *hapd)
{
	hostapd_broadcast_key_clear_iface(hapd, hapd->conf->iface);
	return 0;
}


static int hostapd_broadcast_wep_set(struct hostapd_data *hapd)
{
	int errors = 0, idx;
	struct hostapd_ssid *ssid = &hapd->conf->ssid;

	idx = ssid->wep.idx;
	if (! ssid->wep.default_len
		&& ssid->wep.key[idx]
	    	&& hostapd_set_encryption(hapd->conf->iface,
				   hapd, "WEP", NULL, idx,
			 	   ssid->wep.key[idx],
			 	   ssid->wep.len[idx],
				   idx == ssid->wep.idx)) {
		printf("Could not set WEP encryption.\n");
		errors++;
	}

	if (ssid->dyn_vlan_keys) {
		size_t i;
		for (i = 0; i <= ssid->max_dyn_vlan_keys; i++) {
			const char *ifname;
			struct hostapd_wep_keys *key = ssid->dyn_vlan_keys[i];
			if (key == NULL)
				continue;
			ifname = hostapd_get_vlan_id_ifname(hapd->conf->vlan,
							    i);
			if (ifname == NULL)
				continue;

			idx = key->idx;
			if (hostapd_set_encryption(ifname, hapd, "WEP", NULL,
						   idx, key->key[idx],
						   key->len[idx],
						   idx == key->idx)) {
				printf("Could not set dynamic VLAN WEP "
				       "encryption.\n");
				errors++;
			}
		}
	}

	return errors;
}

/**
 * hostapd_cleanup - Per-BSS cleanup (deinitialization)
 * @hapd: Pointer to BSS data
 *
 * This function is used to free all per-BSS data structures and resources.
 * This gets called in a loop for each BSS between calls to
 * hostapd_cleanup_iface_pre() and hostapd_cleanup_iface() when an interface
 * is deinitialized. Most of the modules that are initialized in
 * hostapd_setup_bss() are deinitialized here.
 */
static void hostapd_cleanup(struct hostapd_data *hapd)
{
	hapd->setuped = 0 ;

	IoctlBegin(hapd) ;
	hostapd_ctrl_iface_deinit(hapd);

	hostapd_free_stas(hapd) ;
	VM_FREE(hapd->default_wep_key);
	hapd->default_wep_key = NULL;
	iapp_deinit(hapd->iapp);
	hapd->iapp = NULL;
#ifdef __ACCOUNTING_ON__
	accounting_deinit(hapd);
#endif
	rsn_preauth_iface_deinit(hapd);
	if (hapd->wpa_auth) {
		wpa_deinit(hapd->wpa_auth);
		hapd->wpa_auth = NULL;
#if 0
		if (hostapd_set_privacy(hapd, 0)) {
			wpa_printf(MSG_DEBUG, "Could not disable "
				   "PrivacyInvoked for interface %s",
				   hapd->conf->iface);
		}
#endif
		if (hostapd_set_generic_elem(hapd, (u8 *) "", 0)) {
			wpa_printf(MSG_DEBUG, "Could not remove generic "
				   "information element from interface %s",
				   hapd->conf->iface);
		}
	}
#if 0
	hostapd_radius_ppp_deinit(hapd) ;
#endif
	ieee802_1x_deinit(hapd);
	vlan_deinit(hapd);
	hostapd_acl_deinit(hapd);
#if 0
	radius_client_deinit(hapd->radius);
	hapd->radius = NULL;
#endif
	radius_server_deinit(hapd->radius_srv);
	hapd->radius_srv = NULL;

	hostapd_wireless_event_deinit(hapd);

#ifdef EAP_TLS_FUNCS
	if (hapd->ssl_ctx) {
		tls_deinit(hapd->ssl_ctx);
		hapd->ssl_ctx = NULL;
	}
#endif /* EAP_TLS_FUNCS */

#ifdef EAP_SERVER
	if (hapd->eap_sim_db_priv) {
		eap_sim_db_deinit(hapd->eap_sim_db_priv);
		hapd->eap_sim_db_priv = NULL;
	}
#endif /* EAP_SERVER */

	if (hapd->interface_added &&
	    hostapd_bss_remove(hapd, hapd->conf->iface)) {
		printf("Failed to remove BSS interface %s\n",
		       hapd->conf->iface);
	}

	IoctlEnd(hapd) ;

	hostapd_driver_deinit(hapd) ;
}
#if 0
/**
 * hostapd_cleanup_iface_pre - Preliminary per-interface cleanup
 * @iface: Pointer to interface data
 *
 * This function is called before per-BSS data structures are deinitialized
 * with hostapd_cleanup().
 */
static void hostapd_cleanup_iface_pre(struct hostapd_iface *iface)
{
}


/**
 * hostapd_cleanup_iface - Complete per-interface cleanup
 * @iface: Pointer to interface data
 *
 * This function is called after per-BSS data structures are deinitialized
 * with hostapd_cleanup().
 */
static void hostapd_cleanup_iface(struct hostapd_iface *iface)
{
	hostapd_free_hw_features(iface->hw_features, iface->num_hw_features);
	iface->hw_features = NULL;
	VM_FREE(iface->current_rates);
	iface->current_rates = NULL;
	ap_list_deinit(iface);
	hostapd_config_free(iface->conf);
	iface->conf = NULL;

	VM_FREE(iface->config_fname);
	//VM_FREE(iface->bss);
	VM_FREE(iface);
}
#endif

static int hostapd_setup_encryption(char *iface, struct hostapd_data *hapd)
{
	int i;

	hostapd_broadcast_wep_set(hapd);

	if (hapd->conf->ssid.wep.default_len)
		return 0;

	for (i = 0; i < 4; i++) {
		if (hapd->conf->ssid.wep.key[i] &&
		    hostapd_set_encryption(iface, hapd, "WEP", NULL,
					   i, hapd->conf->ssid.wep.key[i],
					   hapd->conf->ssid.wep.len[i],
					   i == hapd->conf->ssid.wep.idx)) {
			printf("Could not set WEP encryption.\n");
			return -1;
		}
		if (hapd->conf->ssid.wep.key[i]
			&& i == hapd->conf->ssid.wep.idx)
			hostapd_set_privacy(hapd, 1);
	}

	return 0;
}


static int hostapd_flush_old_stations(struct hostapd_data *hapd)
{
	int ret = 0;

	wpa_printf(MSG_DEBUG, "Flushing old station entries");
	if (hostapd_flush(hapd)) {
		printf("Could not connect to kernel driver.\n");
		ret = -1;
	}
	wpa_printf(MSG_DEBUG, "Deauthenticate all stations");
	hostapd_deauth_all_stas(hapd);

	return ret;
}


static void hostapd_wpa_auth_logger(void *ctx, const u8 *addr,
				    logger_level level, const char *txt)
{
	struct hostapd_data *hapd = ctx;
	int hlevel;

	switch (level) {
	case LOGGER_WARNING:
		hlevel = HOSTAPD_LEVEL_WARNING;
		break;
	case LOGGER_INFO:
		hlevel = HOSTAPD_LEVEL_INFO;
		break;
	case LOGGER_DEBUG:
	default:
		hlevel = HOSTAPD_LEVEL_DEBUG;
		break;
	}

	hostapd_logger(hapd, addr, HOSTAPD_MODULE_WPA, hlevel, "%s", txt);
}


static void hostapd_wpa_auth_disconnect(void *ctx, const u8 *addr,
					u16 reason)
{
	struct hostapd_data *hapd = ctx;
	struct sta_info *sta;

	wpa_printf(MSG_DEBUG, "%s: WPA authenticator requests disconnect: "
		   "STA " MACSTR " reason %d",
		   __func__, MAC2STR(addr), reason);

	sta = ap_get_sta(hapd, addr);
	hostapd_sta_deauth(hapd, addr, reason);
	if (sta == NULL)
		return;
	sta->flags &= ~(WLAN_STA_AUTH | WLAN_STA_ASSOC | WLAN_STA_AUTHORIZED | WLAN_STA_AUTHORIZED_MAC);
	eloop_cancel_timeout(ap_handle_timer, hapd, sta);
	eloop_register_timeout(0, 0, ap_handle_timer, hapd, sta);
	sta->timeout_next = STA_REMOVE;
}


static void hostapd_wpa_auth_mic_failure_report(void *ctx, const u8 *addr)
{
	struct hostapd_data *hapd = ctx;
	ieee80211_michael_mic_failure(hapd, addr, 0);
}


static void hostapd_wpa_auth_set_eapol(void *ctx, const u8 *addr,
				       wpa_eapol_variable var, int value)
{
	struct hostapd_data *hapd = ctx;
	struct sta_info *sta = ap_get_sta(hapd, addr);
	if (sta == NULL)
		return;
	switch (var) {
	case WPA_EAPOL_portEnabled:
		ieee802_1x_notify_port_enabled(sta->eapol_sm, value);
		break;
	case WPA_EAPOL_portValid:
		ieee802_1x_notify_port_valid(sta->eapol_sm, value);
		break;
	case WPA_EAPOL_authorized:
		ieee802_1x_set_sta_authorized(hapd, sta, value);
		break;
	case WPA_EAPOL_portControl_Auto:
		if (sta->eapol_sm)
			sta->eapol_sm->portControl = Auto;
		break;
	case WPA_EAPOL_keyRun:
		if (sta->eapol_sm)
			sta->eapol_sm->keyRun = value ? TRUE : FALSE;
		break;
	case WPA_EAPOL_keyAvailable:
		if (sta->eapol_sm)
			sta->eapol_sm->keyAvailable = value ? TRUE : FALSE;
		break;
	case WPA_EAPOL_keyDone:
		if (sta->eapol_sm)
			sta->eapol_sm->keyDone = value ? TRUE : FALSE;
		break;
	case WPA_EAPOL_inc_EapolFramesTx:
		if (sta->eapol_sm)
			sta->eapol_sm->dot1xAuthEapolFramesTx++;
		break;
	}
}


static int hostapd_wpa_auth_get_eapol(void *ctx, const u8 *addr,
				      wpa_eapol_variable var)
{
	struct hostapd_data *hapd = ctx;
	struct sta_info *sta = ap_get_sta(hapd, addr);
	if (sta == NULL || sta->eapol_sm == NULL)
		return -1;
	switch (var) {
	case WPA_EAPOL_keyRun:
		return sta->eapol_sm->keyRun;
	case WPA_EAPOL_keyAvailable:
		return sta->eapol_sm->keyAvailable;
	default:
		return -1;
	}
}


static const u8 * hostapd_wpa_auth_get_psk(void *ctx, const u8 *addr,
					   const u8 *prev_psk)
{
	struct hostapd_data *hapd = ctx;
	return hostapd_get_psk(hapd->conf, addr, prev_psk);
}


static int hostapd_wpa_auth_get_pmk(void *ctx, const u8 *addr, u8 *pmk,
				    size_t *len)
{
	struct hostapd_data *hapd = ctx;
	u8 *key;
	size_t keylen;
	struct sta_info *sta;

	sta = ap_get_sta(hapd, addr);
	if (sta == NULL)
		return -1;

	key = ieee802_1x_get_key_crypt(sta->eapol_sm, &keylen);
	if (key == NULL)
		return -1;

	if (keylen > *len)
		keylen = WPA_PMK_LEN;
	memcpy(pmk, key, keylen);
	*len = keylen;
	return 0;
}


static int hostapd_wpa_auth_set_key(void *ctx, int vlan_id, const char *alg,
				    const u8 *addr, int idx, u8 *key,
				    size_t key_len)
{
	struct hostapd_data *hapd = ctx;
	const char *ifname = hapd->conf->iface;

	if (vlan_id > 0) {
		ifname = hostapd_get_vlan_id_ifname(hapd->conf->vlan, vlan_id);
		if (ifname == NULL)
			return -1;
	}

	return hostapd_set_encryption(ifname, hapd, alg, addr, idx,
				      key, key_len, 1);
}


static int hostapd_wpa_auth_get_seqnum(void *ctx, const u8 *addr, int idx,
				       u8 *seq)
{
	struct hostapd_data *hapd = ctx;
	return hostapd_get_seqnum(hapd->conf->iface, hapd, addr, idx, seq);
}


static int hostapd_wpa_auth_get_seqnum_igtk(void *ctx, const u8 *addr, int idx,
					    u8 *seq)
{
	struct hostapd_data *hapd = ctx;
	return hostapd_get_seqnum_igtk(hapd->conf->iface, hapd, addr, idx,
				       seq);
}


static int hostapd_wpa_auth_send_eapol(void *ctx, const u8 *addr,
				       const u8 *data, size_t data_len,
				       int encrypt)
{
	struct hostapd_data *hapd = ctx;
	return hostapd_send_eapol(hapd, addr, data, data_len, encrypt);
}


static int hostapd_wpa_auth_for_each_sta(
	void *ctx, int (*cb)(struct wpa_state_machine *sm, void *ctx),
	void *cb_ctx)
{
	struct hostapd_data *hapd = ctx;
	struct sta_info *sta;

	for (sta = hapd->sta_list; sta; sta = sta->next) {
		if (sta->wpa_sm && cb(sta->wpa_sm, cb_ctx))
			return 1;
	}
	return 0;
}


void hostapd_set_sta_authorized(struct hostapd_data *hapd,
				   struct sta_info *sta, int authorized)
{
	int res = 0 ;

	if(authorized){
		int on = 1 ;
				
		if((sta->flags & WLAN_STA_AUTHORIZED_MAC) == 0)
			on = 0 ;
		
		if((hapd->conf->ieee802_1x || hapd->conf->wpa) 
			&& (sta->flags & WLAN_STA_AUTHORIZED) == 0)
			on = 0 ;

		if(on){
			AC_VAPID_T stVapId = {0} ;
			/* int bPortalAuth = 0 ; */
		
			stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
			stVapId.ulVDevId = hapd->iface->gdev_id ;
			stVapId.ulIfId = hapd->iface->interface_id ;
			stVapId.ulVapId = hapd->vap_id ;
			
			/*负荷均衡/接纳控制*/
			if(ac_acm_is_admit(& stVapId, & sta->user_qos, 0) != AC_OK){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, not permit sta("MACSTR") access vap(%d/%d/%d).\n", 
					__func__, MAC2STR(sta->addr), stVapId.ulWtpId, stVapId.ulIfId, stVapId.ulVapId) ;

				hostapd_sta_disassoc(hapd, sta->addr, WLAN_REASON_DISASSOC_AP_BUSY) ;
				return ;
			}
		
			res = hostapd_sta_set_flags(hapd, sta->addr, WLAN_STA_AUTHORIZED, ~0);

#if 1
			if(! notify_sta_add(hapd, sta) || ! notify_sta_info(hapd, sta)){
				hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_USERDB_REGISTER_FAILED | WLAN_REASON_UNSPECIFIED) ;
				return ;
			}

			accounting_sta_start(hapd, sta);
#else
			bPortalAuth = hostapd_portal_auth(hapd, sta->addr) ;
			if(! notify_sta_add(hapd, sta) ||
				(! bPortalAuth && ! notify_sta_info(hapd, sta))){
				hostapd_sta_deauth(hapd, sta->addr, WLAN_REASON_USERDB_REGISTER_FAILED | WLAN_REASON_UNSPECIFIED) ;
				return ;
			}

			if(! bPortalAuth || hostapd_sta_portal_authorized(hapd, sta->addr))
				accounting_sta_start(hapd, sta);
#endif
			if(hapd->conf->wpa)								/* BugId=269,  chary, 2011-11-24   */
				hostapd_authstat_inc(sta->addr, AC_USRM_AUTHSTATTYPE_AUTHSUCC, hapd->iface->pstWtp->usWtpId, hapd->vap_id);
		}
	}
	else {
		res = hostapd_sta_set_flags(hapd, sta->addr, 0, ~WLAN_STA_AUTHORIZED);
	}
	
#if 0
	if (res && errno != ENOENT) {
		printf("Could not set station " MACSTR " flags for kernel "
		       "driver (errno=%d).\n", MAC2STR(sta->addr), errno);
	}
#endif
}


/**
 * hostapd_validate_bssid_configuration - Validate BSSID configuration
 * @iface: Pointer to interface data
 * Returns: 0 on success, -1 on failure
 *
 * This function is used to validate that the configured BSSIDs are valid.
 */
static int hostapd_validate_bssid_configuration(struct hostapd_iface *iface)
{
#if 0
	u8 mask[ETH_ALEN] = { 0 };
	struct hostapd_data *hapd = iface->bss[0];
	unsigned int i = iface->conf->num_bss, bits = 0, j;
	int res;

	if(! hapd)
		return -1 ;
	/* Generate BSSID mask that is large enough to cover the BSSIDs. */

	/* Determine the bits necessary to cover the number of BSSIDs. */
	for (i--; i; i >>= 1)
		bits++;

	/* Determine the bits necessary to any configured BSSIDs,
	   if they are higher than the number of BSSIDs. */
	for (j = 0; j < iface->conf->num_bss; j++) {
		if (hostapd_mac_comp_empty(iface->conf->bss[j].bssid) == 0)
			continue;

		for (i = 0; i < ETH_ALEN; i++) {
			mask[i] |=
				iface->conf->bss[j].bssid[i] ^
				hapd->own_addr[i];
		}
	}

	for (i = 0; i < ETH_ALEN && mask[i] == 0; i++)
		;
	j = 0;
	if (i < ETH_ALEN) {
		j = (5 - i) * 8;

		while (mask[i] != 0) {
			mask[i] >>= 1;
			j++;
		}
	}

	if (bits < j)
		bits = j;

	if (bits > 40)
		return -1;

	memset(mask, 0xff, ETH_ALEN);
	j = bits / 8;
	for (i = 5; i > 5 - j; i--)
		mask[i] = 0;
	j = bits % 8;
	while (j--)
		mask[i] <<= 1;

	HOSTAPD_DEBUG(HOSTAPD_DEBUG_MINIMAL, "BSS count %lu, BSSID mask "
		      MACSTR " (%d bits)\n",
		      (unsigned long) iface->conf->num_bss, MAC2STR(mask),
		      bits);

	res = hostapd_valid_bss_mask(hapd, hapd->own_addr, mask);
	if (res == 0)
		return 0;

	if (res < 0) {
		printf("Driver did not accept BSSID mask " MACSTR " for start "
		       "address " MACSTR ".\n",
		       MAC2STR(mask), MAC2STR(hapd->own_addr));
		return -1;
	}

	for (i = 0; i < ETH_ALEN; i++) {
		if ((hapd->own_addr[i] & mask[i]) != hapd->own_addr[i]) {
			printf("Invalid BSSID mask " MACSTR " for start "
			       "address " MACSTR ".\n"
			       "Start address must be the first address in the"
			       " block (i.e., addr AND mask == addr).\n",
			       MAC2STR(mask), MAC2STR(hapd->own_addr));
			return -1;
		}
	}
#else
	printf("%s, this function is invalid, because madwifi driver do not need bssid validating.\n", __func__) ;
#endif

	return 0;
}


static int mac_in_conf(struct hostapd_config *conf, const void *a)
{
#if 0
	size_t i;

	for (i = 0; i < conf->num_bss; i++) {
		if (hostapd_mac_comp(conf->bss[i].bssid, a) == 0) {
			return 1;
		}
	}
#else
	printf("%s, NULL function.\n", __func__) ;
#endif
	return 0;
}


/**
 * hostapd_setup_bss - Per-BSS setup (initialization)
 * @hapd: Pointer to BSS data
 * @first: Whether this BSS is the first BSS of an interface
 *
 * This function is used to initialize all per-BSS data structures and
 * resources. This gets called in a loop for each BSS when an interface is
 * initialized. Most of the modules that are initialized here will be
 * deinitialized in hostapd_cleanup().
 */
static int hostapd_setup_bss(struct hostapd_data *hapd, int first)
{
	struct hostapd_bss_config *conf = hapd->conf;
	/* u8 ssid[HOSTAPD_MAX_SSID_LEN + 1]; */
	int set_ssid = 0 ;

	IoctlBegin(hapd) ;
	if (hostapd_driver_init(hapd)) {
		printf("%s driver initialization failed.\n",
			hapd->driver ? hapd->driver->name : "Unknown");
		hapd->driver = NULL;
		return -1;
	}

	/* TODO: merge with hostapd_driver_init() ? */
	if (hostapd_wireless_event_init(hapd) < 0)
		return -1;

	/*set authmode*/
	if(conf->auth_algs & HOSTAPD_AUTH_OPEN)
		hostapd_set_authmode(hapd->conf->iface, hapd, IEEE80211_AUTH_OPEN) ;
	if(conf->auth_algs & HOSTAPD_AUTH_SHARED_KEY)
		hostapd_set_authmode(hapd->conf->iface, hapd, IEEE80211_AUTH_SHARED) ;

	hostapd_flush_old_stations(hapd);
	hostapd_set_privacy(hapd, 0);

	hostapd_broadcast_wep_clear(hapd);
	if (hostapd_setup_encryption(hapd->conf->iface, hapd))
		return -1;

	if (!first) {
		if (hostapd_mac_comp_empty(hapd->conf->bssid) == 0) {
			/* Allocate the next available BSSID. */
			do {
				inc_byte_array(hapd->own_addr, ETH_ALEN);
			} while (mac_in_conf(hapd->iconf, hapd->own_addr));
		} else {
			/* Allocate the configured BSSID. */
			memcpy(hapd->own_addr, hapd->conf->bssid, ETH_ALEN);
#if 0
			if (hostapd_mac_comp(hapd->own_addr,
					     hapd->iface->bss[0]->own_addr) ==
			    0) {
				printf("BSS '%s' may not have BSSID "
				       "set to the MAC address of the radio\n",
				       hapd->conf->iface);
				return -1;
			}
#endif
		}

		hapd->interface_added = 1;
#if 0
		if (hostapd_bss_add(hapd->iface->bss[0], hapd->conf->iface,
				    hapd->own_addr)) {
			printf("Failed to add BSS (BSSID=" MACSTR ")\n",
			       MAC2STR(hapd->own_addr));
			return -1;
		}
#endif
	}

	/*
	 * Fetch the SSID from the system and use it or,
	 * if one was specified in the config file, verify they
	 * match.
	 */
#if 0
	ssid_len = hostapd_get_ssid(hapd, ssid, sizeof(ssid));
	if (ssid_len < 0) {
		printf("Could not read SSID from system\n");
		return -1;
	}
	if (conf->ssid.ssid_set) {
		/*
		 * If SSID is specified in the config file and it differs
		 * from what is being used then force installation of the
		 * new SSID.
		 */
		set_ssid = (conf->ssid.ssid_len != (size_t) ssid_len ||
			    memcmp(conf->ssid.ssid, ssid, ssid_len) != 0);
	} else {
		/*
		 * No SSID in the config file; just use the one we got
		 * from the system.
		 */
		set_ssid = 0;
		conf->ssid.ssid_len = ssid_len;
		memcpy(conf->ssid.ssid, ssid, conf->ssid.ssid_len);
		conf->ssid.ssid[conf->ssid.ssid_len] = '\0';
	}

	printf("Using interface %s with hwaddr " MACSTR " and ssid '%s'\n",
	       hapd->conf->iface, MAC2STR(hapd->own_addr),
	       hapd->conf->ssid.ssid);
#endif
	if (hostapd_setup_wpa_psk(conf)) {
		printf("WPA-PSK setup failed.\n");
		return -1;
	}

	/* Set flag for whether SSID is broadcast in beacons */
	if (hostapd_set_broadcast_ssid(hapd,
				       !!hapd->conf->ignore_broadcast_ssid)) {
		printf("Could not set broadcast SSID flag for kernel "
		       "driver\n");
		return -1;
	}

	if (hostapd_set_dtim_period(hapd, hapd->conf->dtim_period)) {
		printf("Could not set DTIM period for kernel driver\n");
		return -1;
	}

	/* Set SSID for the kernel driver (to be used in beacon and probe
	 * response frames) */
	if (set_ssid && hostapd_set_ssid(hapd, (u8 *) conf->ssid.ssid,
					 conf->ssid.ssid_len)) {
		printf("Could not set SSID for kernel driver\n");
		return -1;
	}

#ifndef OSS_LOG
	if (HOSTAPD_DEBUG_COND(HOSTAPD_DEBUG_MSGDUMPS))
		conf->radius->msg_dumps = 1;
#endif

#if 0
	hapd->radius = radius_client_init(hapd, conf->radius, RADIUS_TYPE_FOR_VAP);
	if (hapd->radius == NULL) {
		printf("RADIUS client initialization failed.\n");
		return -1;
	}
#endif

	if (hostapd_acl_init(hapd)) {
		printf("ACL initialization failed.\n");
		return -1;
	}
	if (ieee802_1x_init(hapd)) {
		printf("IEEE 802.1X initialization failed.\n");
		return -1;
	}

#if 0
	if(hostapd_radius_ppp_init(hapd)){
		printf("ppp initialization failed.\n");
		return -1;
	}
#endif

	if (hapd->conf->wpa) {
		struct wpa_auth_config _conf;
		struct wpa_auth_callbacks cb;
		const u8 *wpa_ie;
		size_t wpa_ie_len;

		hostapd_wpa_auth_conf(hapd->conf, &_conf);
		memset(&cb, 0, sizeof(cb));
		cb.ctx = hapd;
		cb.logger = hostapd_wpa_auth_logger;
		cb.disconnect = hostapd_wpa_auth_disconnect;
		cb.mic_failure_report = hostapd_wpa_auth_mic_failure_report;
		cb.set_eapol = hostapd_wpa_auth_set_eapol;
		cb.get_eapol = hostapd_wpa_auth_get_eapol;
		cb.get_psk = hostapd_wpa_auth_get_psk;
		cb.get_pmk = hostapd_wpa_auth_get_pmk;
		cb.set_key = hostapd_wpa_auth_set_key;
		cb.get_seqnum = hostapd_wpa_auth_get_seqnum;
		cb.get_seqnum_igtk = hostapd_wpa_auth_get_seqnum_igtk;
		cb.send_eapol = hostapd_wpa_auth_send_eapol;
		cb.for_each_sta = hostapd_wpa_auth_for_each_sta;
		hapd->wpa_auth = wpa_init(hapd->own_addr, &_conf, &cb);
		if (hapd->wpa_auth == NULL) {
			printf("WPA initialization failed.\n");
			return -1;
		}

		if (hostapd_set_privacy(hapd, 1)) {
			wpa_printf(MSG_ERROR, "Could not set PrivacyInvoked "
				   "for interface %s", hapd->conf->iface);
			return -1;
		}

		wpa_ie = wpa_auth_get_wpa_ie(hapd->wpa_auth, &wpa_ie_len);
		if (hostapd_set_generic_elem(hapd, wpa_ie, wpa_ie_len)) {
			wpa_printf(MSG_ERROR, "Failed to configure WPA IE for "
				   "the kernel driver.");
			return -1;
		}

		if (rsn_preauth_iface_init(hapd)) {
			printf("Initialization of RSN pre-authentication "
			       "failed.\n");
			return -1;
		}
	}

#ifdef __ACCOUNTING_ON__
	if (accounting_init(hapd)) {
		printf("Accounting initialization failed.\n");
		return -1;
	}
#endif

	if (hapd->conf->ieee802_11f &&
	    (hapd->iapp = iapp_init(hapd, hapd->conf->iapp_iface)) == NULL) {
		printf("IEEE 802.11F (IAPP) initialization failed.\n");
		return -1;
	}

	if (hostapd_ctrl_iface_init(hapd)) {
		printf("Failed to setup control interface\n");
		return -1;
	}

	ieee802_11_set_beacon(hapd);

	if (vlan_init(hapd)) {
		printf("VLAN initialization failed.\n");
		return -1;
	}

	if (hostapd_driver_commit(hapd) < 0) {
		wpa_printf(MSG_ERROR, "%s: Failed to commit driver "
			   "configuration", __func__);
		return -1;
	}
	IoctlEnd(hapd) ;

	hapd->setuped = 1 ;

	return 0;
}


/**
 * setup_interface2 - Setup (initialize) an interface (part 2)
 * @iface: Pointer to interface data.
 * Returns: 0 on success; -1 on failure.
 *
 * Flushes old stations, sets the channel, DFS parameters, encryption,
 * beacons, and WDS links based on the configuration.
 */
static int setup_interface2(struct hostapd_iface *iface)
{
	struct hostapd_data *hapd = iface->bss[0];
	int freq;
	size_t j;
	int ret = 0;
	u8 *prev_addr;

	if(! hapd)
		return -1;
#if 0
	hostapd_flush_old_stations(hapd);
	hostapd_set_privacy(hapd, 0);
#endif
	if (hapd->iconf->channel) {
		freq = hostapd_hw_get_freq(hapd, hapd->iconf->channel);
		printf("Mode: %s  Channel: %d  Frequency: %d MHz\n",
		       hostapd_hw_mode_txt(hapd->iconf->hw_mode),
		       hapd->iconf->channel, freq);

		if (hostapd_set_freq(hapd, hapd->iconf->hw_mode, freq)) {
			printf("Could not set channel for kernel driver\n");
			return -1;
		}
	}
#if 0
	hostapd_broadcast_wep_clear(hapd);
	if (hostapd_setup_encryption(hapd->conf->iface, hapd))
		return -1;
#endif
	hostapd_set_beacon_int(hapd, hapd->iconf->beacon_int);
	ieee802_11_set_beacon(hapd);

	if (hapd->iconf->rts_threshold > -1 &&
	    hostapd_set_rts(hapd, hapd->iconf->rts_threshold)) {
		printf("Could not set RTS threshold for kernel driver\n");
		return -1;
	}

	if (hapd->iconf->fragm_threshold > -1 &&
	    hostapd_set_frag(hapd, hapd->iconf->fragm_threshold)) {
		printf("Could not set fragmentation threshold for kernel "
		       "driver\n");
		return -1;
	}

	prev_addr = hapd->own_addr;

	for (j = 0; j < MAX_BSSES; j++) {
		hapd = iface->bss[j];
		if(hapd == NULL)
			continue ;

		if (j)
			memcpy(hapd->own_addr, prev_addr, ETH_ALEN);
		if (hostapd_setup_bss(hapd, j == 0))
			return -1;
		if (hostapd_mac_comp_empty(hapd->conf->bssid) == 0)
			prev_addr = hapd->own_addr;
	}

	ap_list_init(iface);
#if 0
	if (hostapd_driver_commit(hapd) < 0) {
		wpa_printf(MSG_ERROR, "%s: Failed to commit driver "
			   "configuration", __func__);
		return -1;
	}
#endif
	return ret;
}


static void setup_interface_start(void *eloop_data, void *user_ctx);
static void setup_interface2_handler(void *eloop_data, void *user_ctx);

/**
 * setup_interface_finalize - Finish setup interface & call the callback
 * @iface: Pointer to interface data.
 * @status: Status of the setup interface (0 on success; -1 on failure).
 * Returns: 0 on success; -1 on failure (e.g., was not in progress).
 */
static int setup_interface_finalize(struct hostapd_iface *iface, int status)
{
	hostapd_iface_cb cb;

	if (!iface->setup_cb)
		return -1;

	eloop_cancel_timeout(setup_interface_start, iface, NULL);
	eloop_cancel_timeout(setup_interface2_handler, iface, NULL);
	hostapd_select_hw_mode_stop(iface);

	cb = iface->setup_cb;

	iface->setup_cb = NULL;

	cb(iface, status);

	return 0;
}


/**
 * setup_interface2_wrapper - Wrapper for setup_interface2()
 * @iface: Pointer to interface data.
 * @status: Status of the hw mode select.
 *
 * Wrapper for setup_interface2() to calls finalize function upon completion.
 */
static void setup_interface2_wrapper(struct hostapd_iface *iface, int status)
{
	int ret = status;
	if (ret)
		printf("Could not select hw_mode and channel. (%d)\n", ret);
	else
		ret = setup_interface2(iface);

	setup_interface_finalize(iface, ret);
}


/**
 * setup_interface2_handler - Used for immediate call of setup_interface2
 * @eloop_data: Stores the struct hostapd_iface * for the interface.
 * @user_ctx: Unused.
 */
static void setup_interface2_handler(void *eloop_data, void *user_ctx)
{
	struct hostapd_iface *iface = eloop_data;

	setup_interface2_wrapper(iface, 0);
}


/**
 * setup_interface1 - Setup (initialize) an interface (part 1)
 * @iface: Pointer to interface data
 * Returns: 0 on success, -1 on failure
 *
 * Initializes the driver interface, validates the configuration,
 * and sets driver parameters based on the configuration.
 * Schedules setup_interface2() to be called immediately or after
 * hardware mode setup takes place.
 */
static int setup_interface1(struct hostapd_iface *iface)
{
	struct hostapd_data *hapd = iface->bss[0];
	struct hostapd_bss_config *conf = hapd->conf;
	/* size_t i; */
	char country[4];

	if(! hapd)
		return -1;

	/*
	 * Initialize the driver interface and make sure that all BSSes get
	 * configured with a pointer to this driver interface.
	 */
#if 0
	if (hostapd_driver_init(hapd)) {
		printf("%s driver initialization failed.\n",
			hapd->driver ? hapd->driver->name : "Unknown");
		hapd->driver = NULL;
		return -1;
	}
	for (i = 0; i < iface->num_bss; i++)
		iface->bss[i]->driver = hapd->driver;
#endif
	if (hostapd_validate_bssid_configuration(iface))
		return -1;

	memcpy(country, hapd->iconf->country, 3);
	country[3] = '\0';
	if (hostapd_set_country(hapd, country) < 0) {
		printf("Failed to set country code\n");
		return -1;
	}

	if (hapd->iconf->ieee80211d || hapd->iconf->ieee80211h) {
		if (hostapd_set_ieee80211d(hapd, 1) < 0) {
			printf("Failed to set ieee80211d (%d)\n",
			       hapd->iconf->ieee80211d);
			return -1;
		}
	}

	if (hapd->iconf->bridge_packets != INTERNAL_BRIDGE_DO_NOT_CONTROL &&
	    hostapd_set_internal_bridge(hapd, hapd->iconf->bridge_packets)) {
		printf("Failed to set bridge_packets for kernel driver\n");
		return -1;
	}

	if (conf->radius_server_clients) {
		struct radius_server_conf srv;
		memset(&srv, 0, sizeof(srv));
		srv.client_file = conf->radius_server_clients;
		srv.auth_port = conf->radius_server_auth_port;
		srv.hostapd_conf = conf;
		srv.eap_sim_db_priv = hapd->eap_sim_db_priv;
		srv.ssl_ctx = hapd->ssl_ctx;
		srv.ipv6 = conf->radius_server_ipv6;
		hapd->radius_srv = radius_server_init(&srv);
		if (hapd->radius_srv == NULL) {
			printf("RADIUS server initialization failed.\n");
			return -1;
		}
	}
#if 0
	/* TODO: merge with hostapd_driver_init() ? */
	if (hostapd_wireless_event_init(hapd) < 0)
		return -1;
#endif
	if (hostapd_get_hw_features(iface)) {
		/* Not all drivers support this yet, so continue without hw
		 * feature data. */
	} else {
		return hostapd_select_hw_mode_start(iface,
						    setup_interface2_wrapper);
	}

	eloop_register_timeout(0, 0, setup_interface2_handler, iface, NULL);
	return 0;
}


/**
 * setup_interface_start - Handler to start setup interface
 * @eloop_data: Stores the struct hostapd_iface * for the interface.
 * @user_ctx: Unused.
 *
 * An eloop handler is used so that all errors can be processed by the
 * callback without introducing stack recursion.
 */
static void setup_interface_start(void *eloop_data, void *user_ctx)
{
	struct hostapd_iface *iface = eloop_data;

	int ret;

	ret = setup_interface1(iface);
	if (ret)
		setup_interface_finalize(iface, ret);
}


/**
 * hostapd_setup_interface_start - Start the setup of an interface
 * @iface: Pointer to interface data.
 * @cb: The function to callback when done.
 * Returns:  0 if it starts successfully; cb will be called when done.
 *          -1 on failure; cb will not be called.
 *
 * Initializes the driver interface, validates the configuration,
 * and sets driver parameters based on the configuration.
 * Flushes old stations, sets the channel, DFS parameters, encryption,
 * beacons, and WDS links based on the configuration.
 */
int hostapd_setup_interface_start(struct hostapd_iface *iface,
				  hostapd_iface_cb cb)
{
	if (iface->setup_cb) {
#if 0
		wpa_printf(MSG_DEBUG,
			   "%s: Interface setup already in progress.\n",
			   iface->bss[0]->conf->iface);
#endif
		return -1;
	}

	iface->setup_cb = cb;

	eloop_register_timeout(0, 0, setup_interface_start, iface, NULL);

	return 0;
}


/**
 * hostapd_setup_interace_stop - Stops the setup of an interface
 * @iface: Pointer to interface data
 * Returns:  0 if successfully stopped;
 *          -1 on failure (i.e., was not in progress)
 */
int hostapd_setup_interface_stop(struct hostapd_iface *iface)
{
	return setup_interface_finalize(iface, -1);
}


struct driver {
	struct driver *next;
	char *name;
	const struct driver_ops *ops;
};
static struct driver *drivers = NULL;

void driver_register(const char *name, const struct driver_ops *ops)
{
	struct driver *d;

	d = VM_MALLOC(sizeof(struct driver));
	if (d == NULL) {
		printf("Failed to register driver %s!\n", name);
		return;
	}
	d->name = VM_STRDUP(name);
	if (d->name == NULL) {
		printf("Failed to register driver %s!\n", name);
		VM_FREE(d);
		return;
	}
	d->ops = ops;

	d->next = drivers;
	drivers = d;
}


void driver_unregister(const char *name)
{
	struct driver *p, **pp;

	for (pp = &drivers; (p = *pp) != NULL; pp = &p->next) {
		if (strcasecmp(p->name, name) == 0) {
			*pp = p->next;
			p->next = NULL;
			VM_FREE(p->name);
			VM_FREE(p);
			break;
		}
	}
}

#if 0
static void driver_unregister_all(void)
{
	struct driver *p, *pp;
	p = drivers;
	drivers = NULL;
	while (p) {
		pp = p;
		p = p->next;
		VM_FREE(pp->name);
		VM_FREE(pp);
	}
}
#endif

const struct driver_ops * driver_lookup(const char *name)
{
	struct driver *p;

	if (strcmp(name, "default") == 0) {
		p = drivers;
		while (p && p->next)
			p = p->next;
		return p->ops;
	}

	for (p = drivers; p != NULL; p = p->next) {
		if (strcasecmp(p->name, name) == 0)
			return p->ops;
	}

	return NULL;
}

//#define HOSTAPD_VERSION_STR "0.5.10"
static void show_version(void)
{
	fprintf(stderr,
		"hostapd v %s \n"
		"User space daemon for IEEE 802.11 AP management,\n"
		"IEEE 802.1X/WPA/WPA2/EAP/RADIUS Authenticator\n"
		"Copyright (c) 2002-2008, Jouni Malinen <j@w1.fi> "
		"and contributors\n",
		HOSTAPD_VERSION_STR);
}


 void usage(void)
{
	show_version();
	fprintf(stderr,
		"\n"
		"usage: hostapd [-hdBKtv] [-P <PID file>] "
		"<configuration file(s)>\n"
		"\n"
		"options:\n"
		"   -h   show this usage\n"
		"   -d   show more debug messages (-dd for even more)\n"
		"   -B   run daemon in the background\n"
		"   -P   PID file\n"
		"   -K   include key data in debug messages\n"
		"   -t   include timestamps in some debug messages\n"
		"   -v   show hostapd version\n");

	exit(1);
}

#if 0
/**
 * hostapd_alloc_bss_data - Allocate and initialize per-BSS data
 * @hapd_iface: Pointer to interface data
 * @conf: Pointer to per-interface configuration
 * @bss: Pointer to per-BSS configuration for this BSS
 * Returns: Pointer to allocated BSS data
 *
 * This function is used to allocate per-BSS data structure. This data will be
 * freed after hostapd_cleanup() is called for it during interface
 * deinitialization.
 */
static struct hostapd_data *
hostapd_alloc_bss_data(struct hostapd_iface *hapd_iface,
		       struct hostapd_config *conf,
		       struct hostapd_bss_config *bss)
{
	struct hostapd_data *hapd;

	hapd = wpa_zalloc(sizeof(*hapd));
	if (hapd == NULL)
		return NULL;

	hapd->iconf = conf;
	hapd->conf = bss;
	hapd->iface = hapd_iface;

	if (hapd->conf->individual_wep_key_len > 0) {
		/* use key0 in individual key and key1 in broadcast key */
		hapd->default_wep_key_idx = 1;
	}

#ifdef EAP_TLS_FUNCS
	if (hapd->conf->eap_server &&
	    (hapd->conf->ca_cert || hapd->conf->server_cert)) {
		struct tls_connection_params params;

		hapd->ssl_ctx = tls_init(NULL);
		if (hapd->ssl_ctx == NULL) {
			printf("Failed to initialize TLS\n");
			goto fail;
		}

		memset(&params, 0, sizeof(params));
		params.ca_cert = hapd->conf->ca_cert;
		params.client_cert = hapd->conf->server_cert;
		params.private_key = hapd->conf->private_key;
		params.private_key_passwd = hapd->conf->private_key_passwd;

		if (tls_global_set_params(hapd->ssl_ctx, &params)) {
			printf("Failed to set TLS parameters\n");
			goto fail;
		}

		if (tls_global_set_verify(hapd->ssl_ctx,
					  hapd->conf->check_crl)) {
			printf("Failed to enable check_crl\n");
			goto fail;
		}
	}
#endif /* EAP_TLS_FUNCS */

#ifdef EAP_SERVER
	if (hapd->conf->eap_sim_db) {
		hapd->eap_sim_db_priv =
			eap_sim_db_init(hapd->conf->eap_sim_db,
					hostapd_sim_db_cb, hapd);
		if (hapd->eap_sim_db_priv == NULL) {
			printf("Failed to initialize EAP-SIM database "
			       "interface\n");
			goto fail;
		}
	}
#endif /* EAP_SERVER */

	if (hapd->conf->assoc_ap)
		hapd->assoc_ap_state = WAIT_BEACON;

	/* FIX: need to fix this const vs. not */
	hapd->driver = (struct driver_ops *) hapd->iconf->driver;

	return hapd;

#if defined(EAP_TLS_FUNCS) || defined(EAP_SERVER)
fail:
#endif
	/* TODO: cleanup allocated resources(?) */
	VM_FREE(hapd);
	return NULL;
}
#endif

/**
 * hostapd_init - Allocate and initialize per-interface data
 * @config_file: Path to the configuration file
 * Returns: Pointer to the allocated interface data or %NULL on failure
 *
 * This function is used to allocate main data structures for per-interface
 * data. The allocated data buffer will be freed by calling
 * hostapd_cleanup_iface().
 */
 #if 0
static struct hostapd_iface * hostapd_init(const char *config_file)
{
	struct hostapd_iface *hapd_iface = NULL;
	struct hostapd_config *conf = NULL;
	struct hostapd_data *hapd;
	size_t i;

	hapd_iface = wpa_zalloc(sizeof(*hapd_iface));
	if (hapd_iface == NULL)
		goto fail;

	hapd_iface->config_fname = strdup(config_file);
	if (hapd_iface->config_fname == NULL)
		goto fail;

	conf = hostapd_config_read(hapd_iface->config_fname);
	if (conf == NULL)
		goto fail;
	hapd_iface->conf = conf;
#if 0
	hapd_iface->num_bss = conf->num_bss;
#endif
	hapd_iface->bss = wpa_zalloc(conf->num_bss *
				     sizeof(struct hostapd_data *));
	if (hapd_iface->bss == NULL)
		goto fail;

	for (i = 0; i < conf->num_bss; i++) {
		hapd = hapd_iface->bss[i] =
			hostapd_alloc_bss_data(hapd_iface, conf,
					       &conf->bss[i]);
		if (hapd == NULL)
			goto fail;
	}

	return hapd_iface;

fail:
	if (conf)
		hostapd_config_free(conf);
	if (hapd_iface) {
		for (i = 0; hapd_iface->bss && i < MAX_BSSES; i++) {
			hapd = hapd_iface->bss[i];
			if (hapd && hapd->ssl_ctx)
				tls_deinit(hapd->ssl_ctx);
		}

		VM_FREE(hapd_iface->config_fname);
		VM_FREE(hapd_iface->bss);
		VM_FREE(hapd_iface);
	}
	return NULL;
}
#endif

/**
 * register_drivers - Register driver interfaces
 *
 * This function is generated by Makefile (into driver_conf.c) to call all
 * configured driver interfaces to register them to core hostapd.
 */
void register_drivers(void);

#if 0
/**
 * setup_interface_done - Callback when an interface is done being setup.
 * @iface: Pointer to interface data.
 * @status: Status of the interface setup (0 on success; -1 on failure).
 */
static void setup_interface_done(struct hostapd_iface *iface, int status)
{
	if (status) {
#if 0
		wpa_printf(MSG_DEBUG, "%s: Unable to setup interface.",
			   iface->bss[0]->conf->iface);
#endif
		eloop_terminate();
	} else{
#if 0
		wpa_printf(MSG_DEBUG, "%s: Setup of interface done.",
			   iface->bss[0]->conf->iface);
#endif
	}
}
#endif
#if 0
void HOSTAPD_DEBUG(int level, const char * args, ...)
{
	va_list hapd ;

	va_start(hapd, args) ;
	vprintf(args, hapd) ;
	va_end(hapd) ;
}
#endif

#if 0
int main(int argc, char *argv[])
{
	struct hapd_interfaces interfaces;
	int ret = 1, k;
	size_t i, j;
	int c, debug = 0, daemonize = 0;
	const char *pid_file = NULL;

	for (;;) {
		c = getopt(argc, argv, "BdhKP:tv");
		if (c < 0)
			break;
		switch (c) {
		case 'h':
			usage();
			break;
		case 'd':
			debug++;
			if (wpa_debug_level > 0)
				wpa_debug_level--;
			break;
		case 'B':
			daemonize++;
			break;
		case 'K':
			wpa_debug_show_keys++;
			break;
		case 'P':
			pid_file = optarg;
			break;
		case 't':
			wpa_debug_timestamp++;
			break;
		case 'v':
			show_version();
			exit(1);
			break;

		default:
			usage();
			break;
		}
	}

	if (optind == argc)
		usage();

	register_drivers();		/* NB: generated by Makefile */

	if (eap_server_register_methods()) {
		wpa_printf(MSG_ERROR, "Failed to register EAP methods");
		return -1;
	}

	interfaces.count = argc - optind;

	interfaces.iface = VM_MALLOC(interfaces.count *
				  sizeof(struct hostapd_iface *));
	if (interfaces.iface == NULL) {
		printf("malloc failed\n");
		exit(1);
	}

	if (eloop_init(&interfaces)) {
		wpa_printf(MSG_ERROR, "Failed to initialize event loop");
		return -1;
	}

#ifndef CONFIG_NATIVE_WINDOWS
	eloop_register_signal(SIGHUP, handle_reload, NULL);
	eloop_register_signal(SIGUSR1, handle_dump_state, NULL);
#endif /* CONFIG_NATIVE_WINDOWS */
	eloop_register_signal_terminate(handle_term, NULL);

	/* Initialize interfaces */
	for (i = 0; i < interfaces.count; i++) {
		printf("Configuration file: %s\n", argv[optind + i]);
		interfaces.iface[i] = hostapd_init(argv[optind + i]);
		if (!interfaces.iface[i])
			goto out;
		for (k = 0; k < debug; k++) {
			if (interfaces.iface[i]->bss[0]->conf->
			    logger_stdout_level > 0)
				interfaces.iface[i]->bss[0]->conf->
					logger_stdout_level--;
			interfaces.iface[i]->bss[0]->conf->debug++;
		}

		ret = hostapd_setup_interface_start(interfaces.iface[i],
						    setup_interface_done);
		if (ret)
			goto out;
	}

	if (daemonize && os_daemonize(pid_file)) {
		perror("daemon");
		goto out;
	}

#ifndef CONFIG_NATIVE_WINDOWS
	openlog("hostapd", 0, LOG_DAEMON);
#endif /* CONFIG_NATIVE_WINDOWS */

	eloop_run();

	/* Disconnect associated stations from all interfaces and BSSes */
	for (i = 0; i < interfaces.count; i++) {
		for (j = 0; j < interfaces.iface[i]->num_bss; j++) {
			struct hostapd_data *hapd =
				interfaces.iface[i]->bss[j];
			hostapd_free_stas(hapd);
			hostapd_flush_old_stations(hapd);
		}
	}

	ret = 0;

 out:
	/* Deinitialize all interfaces */
	for (i = 0; i < interfaces.count; i++) {
		if (!interfaces.iface[i])
			continue;
		hostapd_setup_interface_stop(interfaces.iface[i]);
		hostapd_cleanup_iface_pre(interfaces.iface[i]);
		for (j = 0; j < interfaces.iface[i]->num_bss; j++) {
			struct hostapd_data *hapd =
				interfaces.iface[i]->bss[j];
			hostapd_cleanup(hapd);
			if (j == interfaces.iface[i]->num_bss - 1 &&
			    hapd->driver)
				hostapd_driver_deinit(hapd);
		}
		for (j = 0; j < interfaces.iface[i]->num_bss; j++)
			VM_FREE(interfaces.iface[i]->bss[j]);
		hostapd_cleanup_iface(interfaces.iface[i]);
	}
	VM_FREE(interfaces.iface);

	eloop_destroy();

#ifndef CONFIG_NATIVE_WINDOWS
	closelog();
#endif /* CONFIG_NATIVE_WINDOWS */

	eap_server_unregister_methods();

	driver_unregister_all();

	os_daemonize_terminate(pid_file);

	return ret;
}
#endif


static void radius_config_free(struct hostapd_radius_servers *conf)
{
	int i;
	
	if(!conf)
		return;

	if(conf->auth_servers){
		for(i = 0; i < conf->num_auth_servers; i ++)
			os_free(conf->auth_servers[i].shared_secret);
		os_free(conf->auth_servers);
	}

	if(conf->acct_servers){
		for(i = 0; i < conf->num_acct_servers; i ++)
			os_free(conf->acct_servers[i].shared_secret);
		os_free(conf->acct_servers);
	}

	os_memset(conf, sizeof(*conf), 0);

	return;
}

static void DumpRadiusServersInfo(AC_DEVM_RADIUS_SERVERS_T * pstRadiusServersCfg)
{
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, radius servers:\n"
		"--master auth server:\n"
		"----ip:\t\t"IPSTR".\n"
		"----port:\t%u.\n"
		"----secret:\t%s.\n"
		"--slave auth server:\n"
		"----ip:\t\t"IPSTR".\n"
		"----port:\t%u.\n"
		"----secret:\t%s.\n"
		"--master acct server:\n"
		"----ip:\t\t"IPSTR".\n"
		"----port:\t%u.\n"
		"----secret:\t%s.\n"
		"--slave acct server:\n"
		"----ip:\t\t"IPSTR".\n"
		"----port:\t%u.\n"
		"----secret:\t%s.\n"
		"--retry primary interval(s):\t%u.\n"
		"--acct interim interval(s):\t%u.\n"
		"--auth alive interval(s):\t%u.\n",
		__func__,
		IP2STR(pstRadiusServersCfg->stAuthSrvMaster.aucIp), pstRadiusServersCfg->stAuthSrvMaster.ulPort, pstRadiusServersCfg->stAuthSrvMaster.acSecret,
		IP2STR(pstRadiusServersCfg->stAuthSrvSlave.aucIp), pstRadiusServersCfg->stAuthSrvSlave.ulPort, pstRadiusServersCfg->stAuthSrvSlave.acSecret,
		IP2STR(pstRadiusServersCfg->stAcctSrvMaster.aucIp), pstRadiusServersCfg->stAcctSrvMaster.ulPort, pstRadiusServersCfg->stAcctSrvMaster.acSecret,
		IP2STR(pstRadiusServersCfg->stAcctSrvSlave.aucIp), pstRadiusServersCfg->stAcctSrvSlave.ulPort, pstRadiusServersCfg->stAcctSrvSlave.acSecret,
		pstRadiusServersCfg->ulRetryPrimaryInterval, pstRadiusServersCfg->ulAcctInterimInterval, pstRadiusServersCfg->ulAuthEchoInterval) ;
}

/*设置一个RADIUS SERVER*/
static BOOL SetRadiusServer(struct hostapd_radius_server * pstRadiusServerTo, AC_DEVM_RADIUS_SERVER_T * pstRadiusServerFrom)
{
	if(pstRadiusServerTo == NULL
		|| pstRadiusServerFrom == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL .\n", __func__) ;
		return FALSE ;
	}

	os_memcpy(& pstRadiusServerTo->addr.u.v4, pstRadiusServerFrom->aucIp, 4) ;
	pstRadiusServerTo->addr.af = AF_INET ;
	pstRadiusServerTo->port = pstRadiusServerFrom->ulPort ;
	if(os_strlen(pstRadiusServerFrom->acSecret)){
		pstRadiusServerTo->shared_secret = (u8 *)os_strdup(pstRadiusServerFrom->acSecret) ;
		pstRadiusServerTo->shared_secret_len = os_strlen(pstRadiusServerFrom->acSecret) ;
	}
	else{
		pstRadiusServerTo->shared_secret = NULL ;
		pstRadiusServerTo->shared_secret_len = 0 ;
	}

	return TRUE ;
}

#if 0
/*设置系统全部RADIUS SERVER*/
static BOOL SetRadiusServers(AC_DEVM_RADIUS_SERVERS_T * pstRadius)
{
	AC_DEVM_GET_RADIUS_SERVERS_RSP_T stRadiusServers = {0} ;
	AC_OMA_MO_T stAcMOID = {0} ;
	
	if(ac_db_oam_get_acmoid(&stAcMOID) == AC_FAIL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, get ac's MOID failed.\n", __func__) ;
		return TRUE ;
	}

	/*初始化上报告警*/
	ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE, 
		AC_OMA_REASON_AUTHSRV_OFFLINE, 
		AC_OMA_ALARM_LEVEL_MAIN,
		stAcMOID.ulMOC,
		stAcMOID.aucMOI,
		0) ;

	ac_db_oam_report_alarm(AC_OMA_ALARM_ID_MACCTSRV_OFFLINE, 
		AC_OMA_REASON_MACCTSRV_OFFLINE,
		AC_OMA_ALARM_LEVEL_MAIN,
		stAcMOID.ulMOC,
		stAcMOID.aucMOI,
		0) ;

	/*获取RADIUS SERVER 配置*/
	if(pstRadius == NULL){
		UINT32 dwLen ;
	
		//ac_devm_get_radius_servers(NULL, 0, & stRadiusServers, & dwLen) ;
		ac_db_access(AC_DEVM_GET_RADIUS_CONFIG_MSG, NULL, 0, & stRadiusServers, & dwLen) ;
		if(stRadiusServers.ulRet != AC_OK){/*允许RADIUS 未配置*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, get NULL radius servers .\n", __func__) ;
			return TRUE ;
		}
	}
	else
		os_memcpy(& stRadiusServers.stRadiusServers, pstRadius, sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;

	DumpRadiusServersInfo(& stRadiusServers.stRadiusServers) ;

	/*申请鉴权服务器及计费用务器实例*/
	if(g_stRadiusServers.auth_servers == NULL){
		g_stRadiusServers.num_auth_servers = 2 ;
		g_stRadiusServers.auth_servers = os_zalloc(2 * sizeof(struct hostapd_radius_server)) ;
		if(g_stRadiusServers.auth_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, auth_servers is NULL .\n", __func__) ;
			return FALSE ;
		}
		g_stRadiusServers.auth_server= g_stRadiusServers.auth_servers ;
	}
	else{/*本函数只允许调用一次，不允许过程中再次修改RADIUS配置*/
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, auth_servers is not NULL .\n", __func__) ;
		return FALSE ;
	}
	
	if(g_stRadiusServers.acct_servers == NULL){
		g_stRadiusServers.num_acct_servers = 2 ;
		g_stRadiusServers.acct_servers = os_zalloc(2 * sizeof(struct hostapd_radius_server)) ;
		if(g_stRadiusServers.acct_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, acct_servers is NULL .\n", __func__) ;
			os_free(g_stRadiusServers.auth_servers) ;
			return FALSE ;
		}
		g_stRadiusServers.acct_server = g_stRadiusServers.acct_servers ;
	}
	else{/*本函数只允许调用一次，不允许过程中再次修改RADIUS配置*/
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, acct_servers is not NULL .\n", __func__) ;
		return FALSE ;
	}

	/*配置*/
	if(! SetRadiusServer(& g_stRadiusServers.auth_servers[0], & stRadiusServers.stRadiusServers.stAuthSrvMaster)
		|| ! SetRadiusServer(& g_stRadiusServers.auth_servers[1], & stRadiusServers.stRadiusServers.stAuthSrvSlave)
		|| ! SetRadiusServer(& g_stRadiusServers.acct_servers[0], & stRadiusServers.stRadiusServers.stAcctSrvMaster)
		|| ! SetRadiusServer(& g_stRadiusServers.acct_servers[1], & stRadiusServers.stRadiusServers.stAcctSrvSlave)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, config radius server failed .\n", __func__) ;
		return FALSE ;
	}

	g_stRadiusServers.retry_primary_interval = stRadiusServers.stRadiusServers.ulRetryPrimaryInterval ;
	g_stRadiusServers.acct_interim_interval = stRadiusServers.stRadiusServers.ulAcctInterimInterval ;

	return TRUE ;
}
#else

/*设置系统全部RADIUS SERVER*/
static BOOL SetRadiusServers(AC_DEVM_RADIUS_SERVERS_T * pstRadius)
{
	AC_DEVM_GET_RADIUS_SERVERS_RSP_T stRadiusServers = {0} ;
	AC_DEVM_RADIUS_SERVERS_T * pstRadiusCfg = NULL ;
	struct hostapd_radius_servers stNewRadiusServers = {0} , stOldRadiusServers = {0} ;
	/* struct radius_client_data * pstRadiusClient = NULL ; */
	UINT8 aucIPNull[4] = {0}, aucIPDefault[4] = {127, 0, 0, 1} ;
	int i, start_retry = 0 ;
	
	if(pstRadius == NULL){/*线程初始化*/
		UINT32 dwLen ;
	
		ac_db_access(AC_DEVM_GET_RADIUS_CONFIG_MSG, NULL, 0, (UINT8 *)& stRadiusServers, & dwLen) ;
		if(stRadiusServers.ulRet != AC_OK){/*允许RADIUS 未配置，支持零配置*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, radius servers is not config.\n", __func__) ;
			os_memcpy(stRadiusServers.stRadiusServers.stAuthSrvMaster.aucIp, aucIPDefault, sizeof(aucIPDefault)) ;
			stRadiusServers.stRadiusServers.stAuthSrvMaster.ulPort = 1812 ;
			os_memcpy(stRadiusServers.stRadiusServers.stAuthSrvMaster.acSecret, "123456", 6) ;
		}
	}
	else{/*运行过程中，修改AAA服务器配置*/
		os_memcpy(& stRadiusServers.stRadiusServers, pstRadius, sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;
	}
	pstRadiusCfg = & stRadiusServers.stRadiusServers ;

	/*合法性检测：若主用认证服务器为空，自动转化为127.0.0.1*/
	if(os_memcmp(pstRadiusCfg->stAuthSrvMaster.aucIp, aucIPNull, sizeof(aucIPNull)) == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, master auth server is null.\n", __func__) ;
		os_memcpy(stRadiusServers.stRadiusServers.stAuthSrvMaster.aucIp, aucIPDefault, sizeof(aucIPDefault)) ;
		stRadiusServers.stRadiusServers.stAuthSrvMaster.ulPort = 1812 ;
		os_memcpy(stRadiusServers.stRadiusServers.stAuthSrvMaster.acSecret, "123456", 6) ;
	}
	
	DumpRadiusServersInfo(pstRadiusCfg) ;

	/*获取配置数据*/
	os_memset(& stNewRadiusServers, 0, sizeof(stNewRadiusServers)) ;
	stNewRadiusServers.num_auth_servers += 1 ;
	if(os_memcmp(pstRadiusCfg->stAuthSrvSlave.aucIp, aucIPNull, sizeof(aucIPNull)) != 0)
		stNewRadiusServers.num_auth_servers += 1 ;

#ifdef __ACCOUNTING_ON__
	if(os_memcmp(pstRadiusCfg->stAcctSrvMaster.aucIp, aucIPNull, sizeof(aucIPNull)) != 0)
		stNewRadiusServers.num_acct_servers += 1 ;
	if(os_memcmp(pstRadiusCfg->stAcctSrvSlave.aucIp, aucIPNull, sizeof(aucIPNull)) != 0)
		stNewRadiusServers.num_acct_servers += 1 ;
#endif

	if(stNewRadiusServers.num_auth_servers){
		stNewRadiusServers.auth_servers = os_zalloc(stNewRadiusServers.num_auth_servers * sizeof(struct hostapd_radius_server)) ;
		if(stNewRadiusServers.auth_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, os_zalloc failed, stNewRadiusServers.auth_servers is null.\n", __func__) ;
			goto bad ;
		}
		
		for(i = 0; i < stNewRadiusServers.num_auth_servers; i ++)
			stNewRadiusServers.auth_servers[i].index = i ;
		
		stNewRadiusServers.auth_server = stNewRadiusServers.auth_servers ;
	}

#ifdef __ACCOUNTING_ON__
	if(stNewRadiusServers.num_acct_servers){
		stNewRadiusServers.acct_servers = os_zalloc(stNewRadiusServers.num_acct_servers * sizeof(struct hostapd_radius_server)) ;
		if(stNewRadiusServers.acct_servers == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, os_zalloc, stNewRadiusServers.acct_servers is null.\n", __func__) ;
			goto bad ;
		}

		for(i = 0; i < stNewRadiusServers.num_acct_servers; i ++)
			stNewRadiusServers.acct_servers[i].index = i ;
		
		stNewRadiusServers.acct_server = stNewRadiusServers.acct_servers ;
	}
#endif
	
	if(stNewRadiusServers.num_auth_servers >= 1
		&& ! SetRadiusServer(& stNewRadiusServers.auth_servers[0], & pstRadiusCfg->stAuthSrvMaster)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, config master auth radius server failed .\n", __func__) ;
		goto bad ;
	}

	if(stNewRadiusServers.num_auth_servers >= 2
		&& ! SetRadiusServer(& stNewRadiusServers.auth_servers[1], & pstRadiusCfg->stAuthSrvSlave)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, config slave auth radius server failed .\n", __func__) ;
		goto bad ;
	}

#ifdef __ACCOUNTING_ON__
	if(stNewRadiusServers.num_acct_servers >= 1
		&& ! SetRadiusServer(& stNewRadiusServers.acct_servers[0], & pstRadiusCfg->stAcctSrvMaster)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, config master acct radius server failed .\n", __func__) ;
		goto bad ;
	}

	if(stNewRadiusServers.num_acct_servers >= 2
		&& ! SetRadiusServer(& stNewRadiusServers.acct_servers[1], & pstRadiusCfg->stAcctSrvSlave)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, config slave acct radius server failed .\n", __func__) ;
		goto bad ;
	}
#endif

	stNewRadiusServers.retry_primary_interval = pstRadiusCfg->ulRetryPrimaryInterval ;
	stNewRadiusServers.acct_interim_interval = pstRadiusCfg->ulAcctInterimInterval ;
	stNewRadiusServers.auth_alive_interval = pstRadiusCfg->ulAuthEchoInterval ;

	/*使配置数据生效*/
	os_memcpy(& stOldRadiusServers, & g_stRadiusServers, sizeof(g_stRadiusServers)) ;
	os_memcpy(& g_stRadiusServers, & stNewRadiusServers, sizeof(stNewRadiusServers)) ;
	os_memset(& stNewRadiusServers, 0, sizeof(stNewRadiusServers)) ;
	
	if(stOldRadiusServers.retry_primary_interval == 0
		&& g_stRadiusServers.retry_primary_interval != 0)/*是否需加载重试主用服务器定时器*/
		start_retry = 1 ;

#if 0
	if(stOldRadiusServers.auth_servers){
		os_free(stOldRadiusServers.auth_servers) ;
		stOldRadiusServers.auth_server = stOldRadiusServers.auth_servers = NULL ;
	}
	if(stOldRadiusServers.acct_servers){
		os_free(stOldRadiusServers.acct_servers) ;
		stOldRadiusServers.acct_server = stOldRadiusServers.acct_servers = NULL ;
	}
#else
	radius_config_free(&stOldRadiusServers);
#endif

#if 0
	for(i = 0 ; i < MAX_WTPS ; i ++)
		for(j = 0 ; g_pstWtpTable[i] && j < MAX_INTERFACES ; j ++)
			for(k = 0 ; g_pstWtpTable[i]->iface[j] && k < MAX_BSSES ; k ++){
				if(g_pstWtpTable[i]->iface[j]->bss[k] == NULL)
					continue ;

				pstRadiusClient = g_pstWtpTable[i]->iface[j]->bss[k]->radius ;
				if(pstRadiusClient == NULL){
					continue ;
				}

				/*使认证配置生效*/
				if(g_stRadiusServers.auth_servers){/*RESET*/
					if(radius_client_init_auth(pstRadiusClient, 0)){
						ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
							"%s, vap(%d/%d/%d) radius_client_init_auth failed.\n", 
							__func__, g_pstWtpTable[i]->usWtpId, g_pstWtpTable[i]->iface[j]->interface_id, g_pstWtpTable[i]->iface[j]->bss[k]->vap_id) ;
						continue ;
					}
				}
				else{/*DESTROY*/
					if(pstRadiusClient->auth_serv_sock >= 0){
						eloop_unregister_read_sock(pstRadiusClient->auth_serv_sock) ;
						close(pstRadiusClient->auth_serv_sock) ;
						pstRadiusClient->auth_sock = pstRadiusClient->auth_serv_sock = -1 ;
					}
					radius_client_flush(pstRadiusClient, 1) ;
				}

				/*使计费配置生效*/
				if(g_stRadiusServers.acct_servers){/*RESET*/
					if(radius_client_init_acct(pstRadiusClient, 0)){
						ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
							"%s, vap(%d/%d/%d) radius_client_init_acct failed.\n", 
							__func__, g_pstWtpTable[i]->usWtpId, g_pstWtpTable[i]->iface[j]->interface_id, g_pstWtpTable[i]->iface[j]->bss[k]->vap_id) ;
						continue ;
					}
				}
				else{/*DESTROY*/
					if(pstRadiusClient->acct_serv_sock >= 0){
						eloop_unregister_read_sock(pstRadiusClient->acct_serv_sock) ;
						close(pstRadiusClient->acct_serv_sock) ;
						pstRadiusClient->acct_sock = pstRadiusClient->acct_serv_sock = -1 ;
					}
					radius_client_flush(pstRadiusClient, 0) ;
				}

				/*加载重试主用服务器定时器*/
				if(start_retry){
					eloop_cancel_timeout(radius_retry_primary_timer, pstRadiusClient, NULL) ;
					eloop_register_timeout(g_stRadiusServers.retry_primary_interval, 0, radius_retry_primary_timer, pstRadiusClient, NULL) ;
				}
			}
#else
	//radius_client_pool_reset(& g_stRadiusServers) ;
	if(pstRadius == NULL){
		if(radius_client_pool_init(g_pstRadiusClient, &g_stRadiusServers, RADIUS_CLIENT_SET_SIZE) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, radius client pool init failed.\n", __func__);
			radius_client_pool_deinit(g_pstRadiusClient);
		}

		if(hostapd_radius_ppp_init(&g_pstRadiusPpp, &g_stRadiusServers, RADIUS_PPP_POOLS_SIZE) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, radius ppp init failed.\n", __func__);
			hostapd_radius_ppp_deinit(&g_pstRadiusPpp);
		}
	}
	else{
		radius_client_pool_reset(g_pstRadiusClient);
		hostapd_radius_ppp_reset(g_pstRadiusPpp);
	}
#endif

if(1 == g_ulAliveCheck){
	radius_alive_global_init(& g_stRadiusServers) ;
}
	return TRUE ;

bad :
	if(stNewRadiusServers.auth_servers)
		os_free(stNewRadiusServers.auth_servers) ;
	if(stNewRadiusServers.acct_servers)
		os_free(stNewRadiusServers.acct_servers) ;
	
	return FALSE ;
}
#endif


#define DumpRadiusServersInfo2(pstRadiusServersCfg)	\
{	\
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,	\
		"%s, radius servers:\n"	\
		"--master auth server:\n"	\
		"----ip:\t\t"IPSTR".\n"	\
		"----port:\t%u.\n"	\
		"----secret:\t%s.\n"	\
		"--slave auth server:\n"	\
		"----ip:\t\t"IPSTR".\n"	\
		"----port:\t%u.\n"	\
		"----secret:\t%s.\n"	\
		"--retry primary interval(s):\t%u.\n"	\
		"--acct interim interval(s):\t%u.\n"	\
		"--auth alive interval(s):\t%u.\n",	\
		__func__,	\
		IP2STR((pstRadiusServersCfg)->stAuthSrvMaster.aucIp), (pstRadiusServersCfg)->stAuthSrvMaster.ulPort, (pstRadiusServersCfg)->stAuthSrvMaster.acSecret,	\
		IP2STR((pstRadiusServersCfg)->stAuthSrvSlave.aucIp), (pstRadiusServersCfg)->stAuthSrvSlave.ulPort, (pstRadiusServersCfg)->stAuthSrvSlave.acSecret,	\
		(pstRadiusServersCfg)->ulRetryPrimaryInterval, (pstRadiusServersCfg)->ulAcctInterimInterval, (pstRadiusServersCfg)->ulAuthEchoInterval) ;	\
}


static BOOL OnRadiusAdd(BYTE * pbyBody, WORD16 wLen)
{
	AC_DEVM_RADIUS_AUTHSERVERS_T *pstRadiusAdd = NULL;
	struct hostapd_radius_servers * pstRadiusConf = NULL;
	UINT32 i;
	UINT8 aucIpNull[4] = {0};
	
	if((pstRadiusAdd = (AC_DEVM_RADIUS_AUTHSERVERS_T *)pbyBody) == NULL ||
		wLen != sizeof(AC_DEVM_AUTHSERVERS_ADD_IND_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point(%p) is NULL, or wLen(%d, %d) is wrong.\n", 
			__func__ , pbyBody, wLen, sizeof(AC_DEVM_AUTHSERVERS_ADD_IND_MSG_T)) ;
		return FALSE;
	}

	DumpRadiusServersInfo2(pstRadiusAdd);
	
	if(os_memcmp(pstRadiusAdd->stAuthSrvMaster.aucIp, aucIpNull, sizeof(aucIpNull)) == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, IP("IPSTR") is invalid.\n", __func__, IP2STR(pstRadiusAdd->stAuthSrvMaster.aucIp));
		return FALSE;
	}

	/*若已存在，则不处理*/
	pstRadiusConf = g_pstRadiusServerSet;
	while(pstRadiusConf){
		if((os_memcmp(&pstRadiusConf->auth_servers[0].addr.u.v4, pstRadiusAdd->stAuthSrvMaster.aucIp, 4) == 0) &&
            (pstRadiusConf->auth_servers[0].port  == pstRadiusAdd->stAuthSrvMaster.ulPort))
			break;

		pstRadiusConf = pstRadiusConf->next;
	}
	if(pstRadiusConf){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, exist this auth server("IPSTR").\n", __func__, IP2STR(pstRadiusAdd->stAuthSrvMaster.aucIp));
		return TRUE;
	}

	if((pstRadiusConf = os_zalloc(sizeof(struct hostapd_radius_servers))) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s(%u), os_zalloc failed.\n", __func__, __LINE__);
		return FALSE;
	}

	pstRadiusConf->num_auth_servers = 2;
	pstRadiusConf->auth_servers = os_zalloc(sizeof(struct hostapd_radius_server) * pstRadiusConf->num_auth_servers);
	if(pstRadiusConf->auth_servers == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s(%u), os_zalloc failed.\n", __func__, __LINE__);
		goto fail;
	}
	pstRadiusConf->auth_server = pstRadiusConf->auth_servers;

	for(i = 0; i < pstRadiusConf->num_auth_servers; i ++)
		pstRadiusConf->auth_servers[i].index = i;

	SetRadiusServer(&pstRadiusConf->auth_servers[0], &pstRadiusAdd->stAuthSrvMaster);
	if(pstRadiusConf->num_auth_servers >= 2)
		SetRadiusServer(&pstRadiusConf->auth_servers[1], &pstRadiusAdd->stAuthSrvSlave);

	pstRadiusConf->retry_primary_interval = pstRadiusAdd->ulRetryPrimaryInterval;
	pstRadiusConf->acct_interim_interval = pstRadiusAdd->ulAcctInterimInterval;
	pstRadiusConf->auth_alive_interval = pstRadiusAdd->ulAuthEchoInterval;

	if(radius_client_pools_add(pstRadiusConf) != 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, radius client pools add failed.\n", __func__);
		goto fail;
	}

	if(hostapd_radius_ppp_add(pstRadiusConf) != 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, ppp add failed.\n", __func__);
	}

	pstRadiusConf->next = g_pstRadiusServerSet;
	g_pstRadiusServerSet = pstRadiusConf;
	
	return TRUE;
	
fail:
	if(pstRadiusConf){
		radius_config_free(pstRadiusConf);
		os_free(pstRadiusConf);
	}

	return FALSE;
}


static BOOL OnRadiusDel(BYTE * pbyBody, WORD16 wLen)
{
	AC_DEVM_RADIUS_AUTHSERVERS_T *pstRadiusDel = NULL;
	struct hostapd_radius_servers *pstRadius = NULL, *pstRadiusPrev = NULL;
	
	if((pstRadiusDel = (AC_DEVM_RADIUS_AUTHSERVERS_T *)pbyBody) == NULL ||
		wLen != sizeof(AC_DEVM_AUTHSERVERS_DEL_IND_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point(%p) is NULL, or wLen(%d, %d) is wrong.\n", 
			__func__ , pbyBody, wLen, sizeof(AC_DEVM_AUTHSERVERS_DEL_IND_MSG_T)) ;
		return FALSE;
	}

	DumpRadiusServersInfo2(pstRadiusDel);

	pstRadiusPrev = NULL;
	pstRadius = g_pstRadiusServerSet;
	while(pstRadius){
		if((os_memcmp(&pstRadius->auth_servers[0].addr.u.v4, pstRadiusDel->stAuthSrvMaster.aucIp, 4) == 0) &&
            (pstRadius->auth_servers[0].port == pstRadiusDel->stAuthSrvMaster.ulPort)){
			if(pstRadiusPrev)
				pstRadiusPrev->next = pstRadius->next;
			else
				g_pstRadiusServerSet = pstRadius->next;
			
			break;
		}

		pstRadiusPrev = pstRadius;
		pstRadius = pstRadius->next;
	}

	if(pstRadius){
		if(radius_client_pools_del(pstRadius) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, radius client pools del failed.\n", __func__);
		}

		if(hostapd_radius_ppp_del(pstRadius) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, ppp del failed.\n", __func__);
		}
		
		radius_config_free(pstRadius);
		os_free(pstRadius);
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, not exist.\n", __func__);
	}
	
	return TRUE;
}


static BOOL OnRadiusUpdate(BYTE * pbyBody, WORD16 wLen)
{
	AC_DEVM_RADIUS_AUTHSERVERS_T *pstRadiusUpdate = NULL;
	struct hostapd_radius_servers *pstRadius = NULL, *pstRadiusPrev = NULL;
	
	if((pstRadiusUpdate = (AC_DEVM_RADIUS_AUTHSERVERS_T *)pbyBody) == NULL ||
		wLen != sizeof(AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point(%p) is NULL, or wLen(%d, %d) is wrong.\n", 
			__func__ , pbyBody, wLen, sizeof(AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG_T)) ;
		return FALSE;
	}

	DumpRadiusServersInfo2(pstRadiusUpdate);

	pstRadiusPrev = NULL;
	pstRadius = g_pstRadiusServerSet;
	while(pstRadius){
		if((os_memcmp(&pstRadius->auth_servers[0].addr.u.v4, pstRadiusUpdate->stAuthSrvMaster.aucIp, 4) == 0)  &&
            (pstRadius->auth_servers[0].port == pstRadiusUpdate->stAuthSrvMaster.ulPort))
        {
			SetRadiusServer(&pstRadius->auth_servers[0], &pstRadiusUpdate->stAuthSrvMaster);
			SetRadiusServer(&pstRadius->auth_servers[1], &pstRadiusUpdate->stAuthSrvSlave);

			pstRadius->retry_primary_interval = pstRadiusUpdate->ulRetryPrimaryInterval;
			pstRadius->acct_interim_interval = pstRadiusUpdate->ulAcctInterimInterval;
			pstRadius->auth_alive_interval = pstRadiusUpdate->ulAuthEchoInterval;
			
			break;
		}

		pstRadiusPrev = pstRadius;
		pstRadius = pstRadius->next;
	}

	if(pstRadius){
		if(radius_client_pools_update(pstRadius) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, radius client pools update failed.\n", __func__);
		}

		if(hostapd_radius_ppp_update(pstRadius) != 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, ppp update failed.\n", __func__);
		}
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, not exist.\n", __func__);
	}
	
	return TRUE;
}


static BOOL OnRadiusPowerOn(VOID)
{
	AC_DEVM_GET_AUTHSERVERS_RSP_T stAuthRadiusRsp = {0};
	UINT32 i, dwLen ;
	
	ac_db_access(AC_DEVM_GET_AUTHSERVERS_MSG, NULL, 0, (UINT8 *)&stAuthRadiusRsp, & dwLen) ;
	if(stAuthRadiusRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, get auth servers failed.\n", __func__) ;
		return FALSE;
	}

	for(i = 0; i < stAuthRadiusRsp.ulNum && i < AC_DEVM_AUTHSERVERS_NUM_MAX; i ++){
		if(OnRadiusAdd((BYTE *)&stAuthRadiusRsp.astAuthServers[i], sizeof(stAuthRadiusRsp.astAuthServers[i])) != TRUE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, %d, add failed.\n", __func__, i);
		}
	}
	
	return TRUE;
}


static BOOL OnNasIpUpdate(BYTE * pbyBody, WORD16 wLen)
{
	AC_USRM_NASIP_UPDATE_IND_MSG_T * pstNasIp = NULL;
	/* int i; */
	
	if((pstNasIp = (AC_USRM_NASIP_UPDATE_IND_MSG_T *)pbyBody) == NULL
		|| wLen != sizeof(AC_USRM_NASIP_UPDATE_IND_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point(%p) is NULL, or wLen(%d, %d) is wrong.\n", 
			__func__, pbyBody, wLen, sizeof(AC_USRM_NASIP_UPDATE_IND_MSG_T));
		return FALSE;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, nas ip: "IPSTR".\n", __func__, IP2STR(pstNasIp->aucNasIp));
	if(os_memcmp(g_aucNasIp, pstNasIp->aucNasIp, 4) == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, nas ip is the same as old nas ip("IPSTR").\n", 
			__func__, IP2STR(g_aucNasIp));
		return TRUE;
	}

	os_memcpy(g_aucNasIp, pstNasIp->aucNasIp, 4);
	if(radius_client_pools_reset_all())
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, radius_client_pools_reset_all failed.\n", __func__);

	if(hostapd_radius_ppp_reset_all())
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, hostapd_radius_ppp_reset_all failed.\n", __func__);
	
	return TRUE;
}


/*根据WTP ID 查找WTP设备*/
static struct hapd_interfaces * FindWtp(WORD16 usWtpId)
{
	if(usWtpId < AC_WTPID_MIN
		|| usWtpId > AC_WTPID_MAX){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, usWtpId(%u) is invalid.\n", __func__ , usWtpId) ;
		return NULL ;
	}

	return g_pstWtpTable[usWtpId - 1] ;
}

static Boolean WtpAdd(AC_DEVM_WTP_CONFIG_T * pstWtpConfig)
{
	struct hapd_interfaces * pstWtp = NULL ;
	WORD16 usWtpId = 0 ;

	if(pstWtpConfig == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	usWtpId = pstWtpConfig->stWtpBasic.stWtpId.ulWtpId ;
	if(usWtpId < AC_WTPID_MIN
		|| usWtpId > AC_WTPID_MAX){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, usWtpId(%u) is invalid.\n", __func__ , usWtpId) ;
		return FALSE ;
	}

	if(FindWtp(usWtpId)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, usWtpId(%u) has been exist.\n", __func__, usWtpId) ;
		return FALSE ;
	}

	pstWtp = os_zalloc(sizeof(struct hapd_interfaces)) ;
	if(pstWtp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s(%d), no memory.\n", __func__, __LINE__) ;
		return FALSE ;
	}
	pstWtp->usWtpId = usWtpId ;
	pstWtp->state = AC_OPSTATE_FAULT ;

	/*注册WTP设备*/
	g_pstWtpTable[usWtpId - 1] = pstWtp ;

	return TRUE ;
}

static Boolean WtpDelete(u16 usWtpId)
{
	struct hapd_interfaces * pstWtp = NULL ;
	Boolean ret = TRUE ;
	int i ;

	/*查找usWtpId所索引的WTP*/
	if((pstWtp = FindWtp(usWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, usWtpId(%u) is not exist.\n", __func__, usWtpId) ;
		return TRUE ;
	}

	/*删除当前WTP下的全部单卡*/
	for(i = 0 ; i < MAX_INTERFACES ; i ++){
		if(pstWtp->iface[i]
			&& ! InterfaceDelete(usWtpId, pstWtp->iface[i]->interface_id)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, Call interfaceDelete failed(%d, %d).\n", __func__, usWtpId, i) ;
			ret = FALSE ;
		}
	}

	/*注销WTP设备*/
	g_pstWtpTable[usWtpId - 1] = NULL ;

	os_free(pstWtp) ;

	return TRUE ;
}

/*根据WTP ID及INTERFACE ID查找单卡*/
static struct hostapd_iface * FindInterface(u16 usWtpId, u32 ulInterfaceId)
{
	struct hapd_interfaces * pstWtp = NULL ;
	/* struct hostapd_iface * pstInterface = NULL ; */
	/* int i ; */

	if((pstWtp = FindWtp(usWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, cannot find wtp(%u).\n", __func__, usWtpId) ;
		return NULL ;
	}

#if 0/*pstInterface->interface_id与pstInterface->interface_index作相同处理*/
	for(i = 0 ; i < MAX_INTERFACES ; i ++){
		if(pstWtp->iface[i]
			&& pstWtp->iface[i]->interface_id == ulInterfaceId){
			pstInterface = pstWtp->iface[i] ;
			break ;
		}
	}

	return pstInterface ;
#else
	if(ulInterfaceId < 0 || ulInterfaceId >= MAX_INTERFACES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, interface id(%d) is invalid.\n", __func__, ulInterfaceId) ;
		return NULL ;
	}
	
	return pstWtp->iface[ulInterfaceId] ;
#endif
}

static Boolean InterfaceAdd(AC_DEVM_IF_CONFIG_T * pstInterfaceConfig)
{
	struct hapd_interfaces * pstWtp = NULL ;
	struct hostapd_iface * pstInterface = NULL ;
	u16 usWtpId = 0 ;
	u32 ulGdevId = 0, ulInterfaceId = 0 ;
	/* int i ; */

	if(pstInterfaceConfig == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	usWtpId = pstInterfaceConfig->stIfId.ulWtpId ;
	ulGdevId = pstInterfaceConfig->stIfId.ulVDevId ;
	ulInterfaceId = pstInterfaceConfig->stIfId.ulIfId ;

	/*检测是否已存在WTP设备*/
	if((pstWtp = FindWtp(usWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, WTP %u is not exist.\n ", __func__, usWtpId) ;
		return FALSE ;
	}

	/*检测IF ID有效性*/
	if(ulInterfaceId < 0 || ulInterfaceId >= MAX_INTERFACES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, interface id(%d) is invalid.\n", __func__, ulInterfaceId) ;
		return FALSE ;
	}

	/*检测WTP上是否已存在编号为ulInterfaceId的单卡*/
	if(FindInterface(usWtpId, ulInterfaceId)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, interface %u/%u has been exist.\n ", __func__, usWtpId, ulInterfaceId) ;
		return FALSE ;
	}

#if 0/*pstInterface->interface_id与pstInterface->interface_index作相同处理*/
	/*寻找空存储位置*/
	for(i = 0 ; i < MAX_INTERFACES ; i ++){
		if(pstWtp->iface[i] == NULL)
			break ;
	}
	if(i >= MAX_INTERFACES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wtp %d have been full.\n ", __func__ , usWtpId) ;
		return FALSE ;
	}
#endif

	/*申请并保存配置*/
	pstInterface = os_zalloc(sizeof(struct hostapd_iface)) ;
	if(pstInterface == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"InterfaceAdd, no memory.\n") ;
		return FALSE ;
	}
	pstInterface->gdev_id = ulGdevId ;
	pstInterface->interface_id = ulInterfaceId ;
	/* pstInterface->interface_index = i ; */
	pstInterface->interface_index = ulInterfaceId;
	pstInterface->pstWtp = pstWtp ;
	if(! InterfaceLoadConfig(pstInterface, pstInterfaceConfig)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call InteraceLoadConfig failed.\n", __func__) ;
		goto bad ;
	}

	/*注册单卡*/
	pstWtp->iface[pstInterface->interface_index] = pstInterface ;

	return TRUE ;

bad :
	if(pstInterface)
		os_free(pstInterface) ;

	return FALSE ;
}

static Boolean InterfaceDelete(u16 usWtpId, u32 ulInterfaceId)
{
	struct hapd_interfaces * pstWtp = NULL ;
	struct hostapd_iface * pstInterface = NULL ;
	int i ;

	if((pstWtp = FindWtp(usWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"InterfaceDelete, WTP %u is not exist.\n", usWtpId) ;
		return FALSE ;
	}

	if((pstInterface = FindInterface(usWtpId, ulInterfaceId)) == NULL){
#if 0
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"InterfaceDelete, interface %u is not exist.\n", ulInterfaceId) ;
#endif
		return TRUE ;
	}

	/*删除当前单卡下的所有VAP*/
	for(i = 0 ; i < MAX_BSSES ; i ++){
		if(pstInterface->bss[i]
			&& ! VapDelete(usWtpId, ulInterfaceId, pstInterface->bss[i]->vap_id)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"InterfaceDelete, call VapDelete failed.\n") ;
			return FALSE ;
		}
	}

	/*注销单卡*/
	pstWtp->iface[pstInterface->interface_index] = NULL ;

	/*删除配置*/
	if(pstInterface->conf){
		hostapd_config_free(pstInterface->conf) ;
		pstInterface->conf = NULL ;
	}

	os_free(pstInterface) ;

	return TRUE ;
}

/*
 功能：为单卡pstInterface重新导入单卡配置pstIfConfig，两者ID号必须一致；
 		   如果pstInterface为空，则需根据pstIfConfig中的ID号自动查找pstInterface；
*/
static Boolean InterfaceLoadConfig(struct hostapd_iface * pstInterface, AC_DEVM_IF_CONFIG_T * pstIfConfig)
{
	if(pstIfConfig == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	if(pstInterface == NULL){/*根据pstIfConfig中的ID号查找pstInterface*/
		if((pstInterface = FindInterface(pstIfConfig->stIfId.ulWtpId, pstIfConfig->stIfId.ulIfId)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, can not find interface(%u/%u).\n", __func__, pstIfConfig->stIfId.ulWtpId, pstIfConfig->stIfId.ulIfId) ;
			return FALSE ;
		}
	}
	else if(pstInterface->pstWtp->usWtpId != pstIfConfig->stIfId.ulWtpId
		|| pstInterface->interface_id != pstIfConfig->stIfId.ulIfId){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, ID is diffient[WTP: %u/%u, IF: %u/%u].\n", __func__, pstInterface->pstWtp->usWtpId, pstIfConfig->stIfId.ulWtpId, pstInterface->interface_id, pstIfConfig->stIfId.ulIfId) ;
		return FALSE ;
	}

	/*删除旧配置*/
	if(pstInterface->conf){
		hostapd_config_free(pstInterface->conf) ;
		pstInterface->conf = NULL ;
	}

	/*导入默认配置*/
	if((pstInterface->conf = hostapd_config_defaults()) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, load default config of interface(%u/%u) failed.\n", __func__, pstInterface->pstWtp->usWtpId, pstInterface->interface_id) ;
		return FALSE ;
	}

	/*根据pstIfConfig重新配置*/
	/*???*/

	/*配置合法性检测*/
	if(hostapd_config_check(pstInterface->conf)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, config of interface(%u/%u) is invalid.\n", __func__, pstInterface->pstWtp->usWtpId, pstInterface->interface_id) ;
		return FALSE ;
	}

	return TRUE ;
}

/*根据WTP ID，INTERFACE ID，VAP ID查找单卡*/
struct hostapd_data * FindVap(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_iface * pstInterface = NULL ;
	struct hostapd_data * pstBss = NULL ;
	int i ;

	if((pstInterface = FindInterface(usWtpId, ulInterfaceId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, cannot find interface(%u/%u).\n", __func__, usWtpId, ulInterfaceId) ;
		return NULL ;
	}

	for(i = 0 ; i < MAX_BSSES ; i ++){
		if(pstInterface->bss[i]
			&& pstInterface->bss[i]->vap_id == ulVapId){
			pstBss = pstInterface->bss[i] ;
			break ;
		}
	}

	return pstBss ;
}

/*根据WTP ID，INTERFACE INDEX，VAP INDEX查找单卡*/
struct hostapd_data * FindVapByIndex(u16 usWtpId, u32 ulIfIndex, u32 ulVapIndex)
{
	struct hapd_interfaces * pstWtp = NULL ;
	struct hostapd_iface * pstInterface = NULL ;

	if(usWtpId < AC_WTPID_MIN
		|| usWtpId > AC_WTPID_MAX
		|| ulIfIndex >= MAX_INTERFACES
		|| ulVapIndex >= MAX_BSSES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, usWtpId(%d)/ulIfIndex(%d)/ulVapIndex(%d).\n", __func__, usWtpId, ulIfIndex, ulVapIndex) ;
		return NULL ;
	}

	if((pstWtp = g_pstWtpTable[usWtpId-1]) == NULL
		|| (pstInterface = pstWtp->iface[ulIfIndex]) == NULL)
		return NULL ;

	return pstInterface->bss[ulVapIndex] ;
}

static Boolean VapAdd(AC_DEVM_VAP_CONFIG_T * pstVapConfig)
{
	struct hostapd_iface * pstInterface = NULL ;
	struct hostapd_data * pstBss = NULL ;
	u16 usWtpId ;
	u32 ulInterfaceId, ulVapId ;
	/* int i ; */

	if(pstVapConfig == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	usWtpId = pstVapConfig->stVapId.ulWtpId ;
	ulInterfaceId = pstVapConfig->stVapId.ulIfId ;
	ulVapId = pstVapConfig->stVapId.ulVapId ;

	/*查找单卡*/
	if((pstInterface = FindInterface(usWtpId, ulInterfaceId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, cannot find interface(%u/%u).\n", __func__, usWtpId, ulInterfaceId) ;
		return FALSE ;
	}

	/*检测是否已存在编号为ulVapId的VAP*/
	if(FindVap(usWtpId, ulInterfaceId, ulVapId)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, vap(%u/%u/%u) has been exist.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

    if(pstInterface->bss[ulVapId] != NULL)
    {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
	         "%s, pstInterface(%u/%u) has been exist,return.\n", __func__, usWtpId, ulInterfaceId) ;
	  	return FALSE ;   
    
    }

	/*申请并保存配置*/
	pstBss = os_zalloc(sizeof(struct hostapd_data)) ;
	if(pstBss == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}

	pstBss->vap_index = pstBss->vap_id = ulVapId;
	pstBss->wtp_vap_added = 0 ;
	pstBss->iface = pstInterface ;
	pstBss->iconf = pstInterface->conf ;
	pstBss->driver = (struct driver_ops *)pstInterface->conf->driver ;
	pstBss->state = AC_OPSTATE_FAULT ;

	if(! VapLoadConfig(pstBss, pstVapConfig)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call VapLoadConfig failed.\n", __func__) ;
		goto bad ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) load config success.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;

	/*注册VAP*/
	pstInterface->bss[pstBss->vap_index] = pstBss ;

	return TRUE ;

bad :
	if(pstBss)
		os_free(pstBss) ;

	return FALSE ;
}

static Boolean VapDelete(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_iface * pstInterface = NULL ;
	struct hostapd_data * pstBss = NULL ;
	/* int i ; */

	if(usWtpId < AC_WTPID_MIN
		|| usWtpId > AC_WTPID_MAX){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, usWtpId(%u) is invalid.\n", __func__ , usWtpId) ;
		return FALSE ;
	}

	/*查找单卡*/
	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
#if 0 
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
#endif
		return TRUE ;
	}
	pstInterface = pstBss->iface ;

	/*停止VAP运作：使VAP数据无效*/
	if(pstBss->setuped)
		hostapd_cleanup(pstBss) ;

	/*通知WTP侧*/
	if(pstBss->wtp_vap_added){
		if(! NotifyVapDelete(usWtpId, ulInterfaceId, ulVapId)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call NotifyVapDelete failed.\n", __func__) ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, call NotifyVapDelete success.\n", __func__) ;
			pstBss->wtp_vap_added = 0 ;
		}
	}

	/*删除配置*/
	if(pstBss->conf){
		hostapd_config_free_bss(pstBss->conf) ;
		os_free(pstBss->conf) ;
		pstBss->conf = NULL ;
	}

	/*注销VAP*/
	pstInterface->bss[pstBss->vap_index] = NULL ;
	eloop_cancel_timeout(OnWaitVapIoctlTimer, pstBss, NULL) ;
	eloop_cancel_timeout(VapStartTimeout, pstBss, ELOOP_ALL_CTX);
	
	os_free(pstBss) ;

	return TRUE ;
}

#define DumpVapCfg(func, level, pVapCfg)	\
ModuleLogMsg(APP_MODULE_HOSTAPD, (level),	\
					"%s, vap[%u/%u/%u] :\n"	\
					"--interface name:\t%s.\n"	\
					"--bssid:\t\t"MACSTR".\n"	\
					"--ssid:\t\t\t%s.\n"		\
					"--ssid not hide:\t%u.\n"	\
					"--auth(bit0: open, bit1: shared, bit2: wpa, bit3: wpa-psk, bit4: mac):\t0x%x.\n"	\
					"--encypt(bit0: none, bit1: wep, bit2: TKIP, bit3: CCMP):\t0x%x.\n"		\
					"--wpa key:\t\t%s.\n"			\
					"--wpa rekey period(s):\t%u.\n"	\
					"--wep key len(1: 64bit, 2: 128bit):\t\t%u.\n"		\
					"--wep key input format(1: hex, 2: ASCII):\t%u.\n"	\
					"--wep key:\t\t%s.\n"			\
					"--wep key index:\t%u.\n"		\
					"--use 8021x:\t\t%u.\n"		\
					"--EAP Version:\t\t%u.\n"		\
					"--EAP Auth Period(s):\t%u.\n"	\
					"--dynamic wep broadcast key len(1: 64bit, 2: 128bit):\t%u.\n" 	\
					"--dynamic wep unicast key len(1: 64bit, 2: 128bit):\t%u.\n"		\
					"--wep rekey period(s):\t%u.\n",	\
					(func), 						\
					(pVapCfg)->stVapId.ulWtpId, (pVapCfg)->stVapId.ulIfId, (pVapCfg)->stVapId.ulVapId, 	\
					(pVapCfg)->acIfName, MAC2STR((pVapCfg)->aucBssid), (pVapCfg)->acSsid,					\
					(pVapCfg)->ulSsidBroadcast, \
					(pVapCfg)->ulAuth, (pVapCfg)->ulEncrypt,						\
					(pVapCfg)->acWpaKey, (pVapCfg)->ulWpaRekeyPeriod, (pVapCfg)->ulWepKeyLen,				\
					(pVapCfg)->ulInputFormat, (pVapCfg)->acWepKey, 										\
					(pVapCfg)->ulWepKeyIndex, (pVapCfg)->ul8021x, (pVapCfg)->ulEapolVer,(pVapCfg)->ulEapAuthPeriod, \
					(pVapCfg)->ulWepBroadcastKeyLen, (pVapCfg)->ulWepUnicastKeyLen, (pVapCfg)->ulWepRekeyPeriod)

/*对配置作合法性检查*/
static Boolean ConfigCheck(AC_DEVM_VAP_CONFIG_T * pstVapCfg)
{	
	/*设备名长度检查*/
	if(! os_strlen(pstVapCfg->acIfName)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, device name is NULL.", __func__) ;
		return FALSE ;
	}
		
	/*鉴权方式只能属于'OPEN/SHARED/WPA/WPA-PSK/MAC'中的一种*/
	if(pstVapCfg->ulAuth != 1
		&& pstVapCfg->ulAuth != 2
		&& pstVapCfg->ulAuth != 4
		&& pstVapCfg->ulAuth != 8
		&& pstVapCfg->ulAuth != 16
		&& pstVapCfg->ulAuth != 32){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Auth(%d) is not available.", __func__, pstVapCfg->ulAuth) ;
		return FALSE ;
	}

	/*加密方式只能属于'禁用/WEP/TKIP/CCMP'中的一种*/
	if(pstVapCfg->ulEncrypt != 1
		&& pstVapCfg->ulEncrypt != 2
		&& pstVapCfg->ulEncrypt != 4
		&& pstVapCfg->ulEncrypt != 8
		&& pstVapCfg->ulEncrypt != 16){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Encrypt(%d) is not available.", __func__, pstVapCfg->ulEncrypt) ;
		return FALSE ;
	}

	/*SHARED/WEP：静态WEP密钥长度检测*/
	if(! pstVapCfg->ul8021x
		&& (pstVapCfg->ulAuth & 2 || pstVapCfg->ulEncrypt & 2)){
		int iWepKeyLen = 0 ;
		
		if(pstVapCfg->ulWepKeyLen == 1 && pstVapCfg->ulInputFormat == 1)
			iWepKeyLen = 10 ;
		else if(pstVapCfg->ulWepKeyLen == 1 && pstVapCfg->ulInputFormat == 2)
			iWepKeyLen = 5 ;
		else if(pstVapCfg->ulWepKeyLen == 2 && pstVapCfg->ulInputFormat == 1)
			iWepKeyLen = 26 ;
		else if(pstVapCfg->ulWepKeyLen == 2 && pstVapCfg->ulInputFormat == 2)
			iWepKeyLen = 13 ;
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, static wep key len(%d, %d) is not available.\n", __func__, pstVapCfg->ulWepKeyLen, pstVapCfg->ulInputFormat) ;
			return FALSE ;
		}

		if(os_strlen(pstVapCfg->acWepKey) != iWepKeyLen){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, static wep key len(%d, %d, %d) is not available.\n", __func__, pstVapCfg->ulWepKeyLen, pstVapCfg->ulInputFormat, os_strlen(pstVapCfg->acWepKey)) ;
			return FALSE ;
		}
	}

	/*检测：配置了WPA，但未配置TKIP或CCMP加密机制*/
	if((pstVapCfg->ulAuth & 12)
		&& ! (pstVapCfg->ulEncrypt & 12)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, enable WPA/WPA-PSK, but not enable TKIP/CCMP, then change to TKIP.\n", __func__) ;
		pstVapCfg->ulEncrypt = 4 ;
	}

	/*WPA-PSK密钥长度检查*/
	if((pstVapCfg->ulAuth & 8)
		&& (os_strlen(pstVapCfg->acWpaKey) < 8 || os_strlen(pstVapCfg->acWpaKey) > 63)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, wpa-psk key len(%d) is not available.\n", __func__, os_strlen(pstVapCfg->acWpaKey)) ;
		return FALSE ;
	}

	/*检测：配置了WPA，但未配置8021X*/
	if((pstVapCfg->ulAuth & 4)
		&& ! pstVapCfg->ul8021x){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, enable wpa, but not enable 8021X.\n", __func__) ;
		return FALSE ;
	}

	/*检测：配置8021X，则必须配置WPA或者OPEN/WEP*/
	if(pstVapCfg->ul8021x
		&& ! (pstVapCfg->ulAuth & 4)
		&& ! ((pstVapCfg->ulAuth & 1) && (pstVapCfg->ulEncrypt & 2))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, enable 8021x, but not enable wpa/wep.\n", __func__) ;
		return FALSE ;
	}

	/*8021X/EAPOL版本号检测*/
	if(pstVapCfg->ul8021x
		&& pstVapCfg->ulEapolVer != 1
		&& pstVapCfg->ulEapolVer != 2){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, Eapol Version(%d) is not available, then change to v2.\n", __func__, pstVapCfg->ulEapolVer) ;
		pstVapCfg->ulEapolVer = 2 ;
	}

	/*动态WEP参数合法性检测*/
	if(pstVapCfg->ul8021x
		&& ((pstVapCfg->ulAuth & 1) && (pstVapCfg->ulEncrypt & 2))){
		if(pstVapCfg->ulWepBroadcastKeyLen != 1 && pstVapCfg->ulWepBroadcastKeyLen != 2){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, WepBroadcastKeyLen is not available, then change to 5.", __func__) ;
			pstVapCfg->ulWepBroadcastKeyLen = 1 ;
		}
		if(pstVapCfg->ulWepUnicastKeyLen != 1 && pstVapCfg->ulWepUnicastKeyLen != 2){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, WepUnicastKeyLen is not available, then change to 5.", __func__) ;
			pstVapCfg->ulWepUnicastKeyLen = 1 ;
		}
	}

	return TRUE ;
}
/*
 功能：为VAP pstBss重新导入单卡配置pstVapCfg，两者ID号必须一致；
 		   如果pstBss为空，则需根据pstVapCfg中的ID号自动查找pstInterface；
*/
static Boolean VapLoadConfig(struct hostapd_data * pstBss, AC_DEVM_VAP_CONFIG_T * pstVapCfg)
{
	u16 usWtpId ;
	u32 ulInterfaceId , ulVapId ;
	struct hostapd_bss_config * pstBssCfg = NULL ;
	/* char acNasId[32] = {0} ; */

	if(pstVapCfg == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	DumpVapCfg(__func__, APP_MSG, pstVapCfg) ;

	usWtpId = pstVapCfg->stVapId.ulWtpId ;
	ulInterfaceId = pstVapCfg->stVapId.ulIfId ;
	ulVapId = pstVapCfg->stVapId.ulVapId ;

	if(! ConfigCheck(pstVapCfg)){/*检测配置*/
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, vap(%u/%u/%u) config is not available.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) config is available.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;

	if(g_stRadiusServers.num_auth_servers== 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, no radius configued.\n", __func__) ;
		return FALSE ;
	}
	
	if(pstBss == NULL){
		if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
			return FALSE ;
		}
	}
	else if(pstBss->iface->pstWtp->usWtpId != pstVapCfg->stVapId.ulWtpId
		|| pstBss->iface->interface_id != pstVapCfg->stVapId.ulIfId
		|| pstBss->vap_id != pstVapCfg->stVapId.ulVapId){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, ID is diffient[VAP:%u/%u/%u, %u/%u/%u].\n", __func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	/*清除旧配置*/
	if(pstBss->conf){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u): free old config.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		hostapd_config_free_bss(pstBss->conf) ;
	}
	else if((pstBss->conf = wpa_zalloc(sizeof(struct hostapd_bss_config))) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	pstBssCfg = pstBss->conf ;

	/*导入默认配置*/
	hostapd_config_defaults_bss(pstBssCfg) ;

	/*鉴权服务器配置*/
	pstBssCfg->radius = & g_stRadiusServers ;

	/*基本配置*/
	os_memcpy(pstBssCfg->iface, pstVapCfg->acIfName, os_strlen(pstVapCfg->acIfName)) ;
	os_memcpy(pstBssCfg->bssid, pstVapCfg->aucBssid, ETH_ALEN) ; 

	if(os_strlen(pstVapCfg->acSsid) < 1 || os_strlen(pstVapCfg->acSsid) > HOSTAPD_MAX_SSID_LEN){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, ssid len(%d) is not available.\n", __func__, os_strlen(pstVapCfg->acSsid)) ;
		/* goto bad ; */
	}
	else{
		pstBssCfg->ssid.ssid_len = os_strlen(pstVapCfg->acSsid) ;
		os_memcpy(pstBssCfg->ssid.ssid, pstVapCfg->acSsid, pstBssCfg->ssid.ssid_len) ;
		pstBssCfg->ssid.ssid[pstBssCfg->ssid.ssid_len] = '\0' ;
		pstBssCfg->ssid.ssid_set = 1 ;
	}

#if 0
	/*NAS-ID配置*/
	memcpy(acNasId, pstVapCfg->acNasId, sizeof(pstVapCfg->acNasId)) ;
	pstBssCfg->nas_identifier = os_strdup(acNasId) ;
#endif

	/*鉴权配置*/
	pstBssCfg->auth_algs = 0 ;
	if(pstVapCfg->ulAuth & 1)/*OPEN*/
		pstBssCfg->auth_algs |= HOSTAPD_AUTH_OPEN ;
	if(pstVapCfg->ulAuth & 2)/*SHARED*/
		pstBssCfg->auth_algs |= HOSTAPD_AUTH_SHARED_KEY ;
	if(pstVapCfg->ulAuth & 16){/*MAC=OPEN+PAP*/
		pstBssCfg->auth_algs |= HOSTAPD_AUTH_OPEN ;
		pstBssCfg->macaddr_acl = USE_EXTERNAL_RADIUS_AUTH ;
	}
	if(pstVapCfg->ulAuth & 32)/*WAPI*/
		pstBssCfg->wapi = 1 ;

	/*WPA配置*/
	if(pstVapCfg->ulAuth & 12){/*WPA*/
		pstBssCfg->wpa = HOSTAPD_WPA_VERSION_WPA |HOSTAPD_WPA_VERSION_WPA2 ;

		pstBssCfg->wpa_key_mgmt = 0 ;
		if(pstVapCfg->ulAuth & 4)/*支持WPA_8021X*/
			pstBssCfg->wpa_key_mgmt |= WPA_KEY_MGMT_IEEE8021X ;
		if(pstVapCfg->ulAuth & 8)/*支持WPA_PSK*/
			pstBssCfg->wpa_key_mgmt |= WPA_KEY_MGMT_PSK ;

		pstBssCfg->wpa_pairwise = 0 ;
		if(pstVapCfg->ulEncrypt & 4)/*支持TKIP*/
			pstBssCfg->wpa_pairwise |= WPA_CIPHER_TKIP ;
		if(pstVapCfg->ulEncrypt & 8)/*支持CCMP*/
			pstBssCfg->wpa_pairwise |= WPA_CIPHER_CCMP ;
		if((pstVapCfg->ulEncrypt & 12) == 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, invalid configuration(no encrypt configured) .\n", __func__) ;
			pstBssCfg->wpa_pairwise |= WPA_CIPHER_TKIP ;
		}

		pstBssCfg->wpa_group = 0 ;
		if (pstBssCfg->wpa_pairwise & WPA_CIPHER_TKIP)
			pstBssCfg->wpa_group = WPA_CIPHER_TKIP;
		else
			pstBssCfg->wpa_group = WPA_CIPHER_CCMP;

		pstBssCfg->wpa_group_rekey = pstVapCfg->ulWpaRekeyPeriod ;

		if(pstVapCfg->ulAuth & 4){/*WPA-802.1x*/
			VM_FREE(pstBssCfg->ssid.wpa_passphrase) ;
			pstBssCfg->ssid.wpa_passphrase = NULL ;
		}
		else{/*WPA-PSK*/
			if (os_strlen(pstVapCfg->acWpaKey) < 8 || os_strlen(pstVapCfg->acWpaKey) > 63){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, wpa key len(%d) is not available.\n", __func__, os_strlen(pstVapCfg->acWpaKey)) ;
				goto bad ;
			}
			else {
				VM_FREE(pstBssCfg->ssid.wpa_passphrase);
				pstBssCfg->ssid.wpa_passphrase = VM_STRDUP(pstVapCfg->acWpaKey);
			}
		}
	}

	/*80211x配置*/
	if(pstVapCfg->ul8021x){
		pstBssCfg->ieee802_1x = pstVapCfg->ul8021x ;

		if(pstVapCfg->ulEapolVer < 1 || pstVapCfg->ulEapolVer > 2){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, eapol version(%d) is not available.\n", __func__, pstVapCfg->ulEapolVer) ;
			goto bad ;
		}
		else
			pstBssCfg->eapol_version = pstVapCfg->ulEapolVer ;

		pstBssCfg->eap_reauth_period = pstVapCfg->ulEapAuthPeriod ;

		if(! (pstVapCfg->ulAuth & 12)){/*未打开WPA，下述配置方有效*/
			if(pstVapCfg->ulWepBroadcastKeyLen == 1)/*64BIT*/
				pstBssCfg->default_wep_key_len = 5 ;
			else if(pstVapCfg->ulWepBroadcastKeyLen == 2)/*128BIT*/
				pstBssCfg->default_wep_key_len = 13 ;
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, broadcast wep key len(%d) is not available, auto change to 5.\n", __func__, pstVapCfg->ulWepBroadcastKeyLen) ;
				pstBssCfg->default_wep_key_len = 5 ;
			}

			if(pstVapCfg->ulWepUnicastKeyLen == 1)/*64BIT*/
				pstBssCfg->individual_wep_key_len = 5 ;
			else if(pstVapCfg->ulWepUnicastKeyLen == 2)/*128BIT*/
				pstBssCfg->individual_wep_key_len = 13 ;
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, broadcast wep key len(%d) is not available, auto change to 5.\n", __func__, pstVapCfg->ulWepUnicastKeyLen) ;
				pstBssCfg->individual_wep_key_len = 5 ;
			}

			pstBssCfg->wep_rekeying_period = pstVapCfg->ulWepRekeyPeriod ;
			pstBssCfg->eapol_key_index_workaround = 1 ;
		}
	}

	/*WEP 密钥配置*/
	if(! pstVapCfg->ul8021x
		&& (pstVapCfg->ulAuth & 2 || pstVapCfg->ulEncrypt & 2)
		&& os_strlen(pstVapCfg->acWepKey)){
		int iWepKeyLen = 0 ;

		/*保证pstVapCfg->acWepKey以'\0'结束*/
		if(pstVapCfg->ulWepKeyLen == 1 && pstVapCfg->ulInputFormat == 1)
			iWepKeyLen = 10 ;
		else if(pstVapCfg->ulWepKeyLen == 1 && pstVapCfg->ulInputFormat == 2)
			iWepKeyLen = 5 ;
		else if(pstVapCfg->ulWepKeyLen == 2 && pstVapCfg->ulInputFormat == 1)
			iWepKeyLen = 26 ;
		else if(pstVapCfg->ulWepKeyLen == 2 && pstVapCfg->ulInputFormat == 2)
			iWepKeyLen = 13 ;
		else
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, static wep key len(%d, %d) is not available.\n", __func__, pstVapCfg->ulWepKeyLen, pstVapCfg->ulInputFormat) ;

		if(iWepKeyLen)
			pstVapCfg->acWepKey[iWepKeyLen] = '\0' ;

		if(hostapd_config_bss_read_wep(& pstBssCfg->ssid.wep, pstVapCfg->ulWepKeyIndex - 1, pstVapCfg->acWepKey, pstVapCfg->ulInputFormat) == 0){
			pstBssCfg->ssid.wep.idx = pstVapCfg->ulWepKeyIndex - 1 ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, read wep failed.\n", __func__) ;
			goto bad ;
		}
	}

	/*配置安全策略*/
	if (pstBssCfg->wpa && pstBssCfg->ieee802_1x) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: WPA.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		pstBssCfg->ssid.security_policy = SECURITY_WPA;
	} else if (pstBssCfg->wpa) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: WPA-PSK.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		pstBssCfg->ssid.security_policy = SECURITY_WPA_PSK;
	} else if (pstBssCfg->ieee802_1x) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: 802.1x.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		pstBssCfg->ssid.security_policy = SECURITY_IEEE_802_1X;
		pstBssCfg->ssid.wep.default_len = pstBssCfg->default_wep_key_len;
	} else if (pstBssCfg->ssid.wep.keys_set){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: WEP.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		pstBssCfg->ssid.security_policy = SECURITY_STATIC_WEP;
	}
	else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: PLAINTEXT.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		pstBssCfg->ssid.security_policy = SECURITY_PLAINTEXT;
	}

	if(pstBssCfg->macaddr_acl == USE_EXTERNAL_RADIUS_AUTH){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: MAC.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
	}

	if(pstBssCfg->wapi){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) security policy: WAPI.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
	}

	if (hostapd_config_check_bss(pstBssCfg, NULL)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call hostapd_config_check failed.\n", __func__) ;
		goto bad ;
	}

	return TRUE ;

bad :
	hostapd_config_free_bss(pstBss->conf) ;

	return FALSE ;
}

static BOOL VapLoadMac(AC_DEVM_VAP_MAC_CHG_IND_MSG_T * pstVapMac)
{
	u16 usWtpId ;
	u32 ulInterfaceId , ulVapId ;
	struct hostapd_data * pstBss = NULL ;
	u8 zeromac[ETH_ALEN] = {0} ;

	if(pstVapMac == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	usWtpId = pstVapMac->stVapId.ulWtpId ;
	ulInterfaceId = pstVapMac->stVapId.ulIfId ;
	ulVapId = pstVapMac->stVapId.ulVapId ;

	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, load vap(%u/%u/%u) mac: "MACSTR".\n", __func__, usWtpId, ulInterfaceId, ulVapId, MAC2STR(pstVapMac->aucBssid)) ;
	if(os_memcmp(pstVapMac->aucBssid, zeromac, ETH_ALEN) == 0
		|| os_memcmp(pstVapMac->aucBssid, pstBss->conf->bssid, ETH_ALEN) == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, new mac is null, or it is equal to old mac.\n", __func__) ;
		return TRUE ;
	}
	
	os_memcpy(pstBss->conf->bssid, pstVapMac->aucBssid, ETH_ALEN) ;
	hostapd_acbss_stats_inc(pstBss, ulVapStartMacUpdate);
	
	if(pstBss->state != AC_OPSTATE_NORMAL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u)'s opstate is not noraml.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return TRUE;
	}
	
	pstBss->timeout_vapstart=1;
	if(!VapStart(usWtpId, ulInterfaceId, ulVapId)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call VapStart failed after load vap(%u/%u/%u) mac.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	return TRUE ;
}

/*AC与VAP链路通时响应函数，使配置数据生效*/
static Boolean VapStart(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_data * pstBss = NULL ;
	BYTE * pbOut = NULL, * pbFrame = NULL, * pbBridgeName = NULL, * pbPreauthIfName = NULL ;
	WORD32 dwOutLen = 0 ;
	BOOL bRet = TRUE ;

	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	if(pstBss->conf->wapi){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(%u/%u/%u), wapi donot need start hostapd.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return TRUE ;
	}

	if (pstBss->state != AC_OPSTATE_NORMAL
		|| hostapd_mac_comp_empty(pstBss->conf->bssid) == 0) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) is not normal(%d), or bssid is empty.\n", 
			__func__, usWtpId, ulInterfaceId, ulVapId, pstBss->state) ;
		return TRUE ;
	}

	hostapd_acbss_stats_inc(pstBss, ulVapStart);

	/*第一次启动VAP，则需通知WTP侧添加本VAP*/

	if( ! NotifyVapAdd(usWtpId, ulInterfaceId, ulVapId)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call NotifyVapAdd failed.\n", __func__) ;
		
	}else{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, starting vap(%u/%u/%u) is notified success.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
			pstBss->wtp_vap_added = 1 ;
   }


	/*如果启动单卡上的第一个VAP，则需先启动单卡*/
	/*NONE*/

	/*停止VAP运作，使配置数据无效*/
	if(pstBss->setuped)
		hostapd_cleanup(pstBss) ;

	/*使VAP配置数据生效*/
	if(hostapd_setup_bss(pstBss, 0)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, setup vap(%u/%u/%u) failed.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		hostapd_cleanup(pstBss) ;
		return  FALSE ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, setup vap(%u/%u/%u) success.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;

	/*通知WTP侧: init madwifi(eapol socket, event socket), init preauth socket*/
	if((pbBridgeName = (BYTE *)pstBss->conf->bridge) != NULL
		&& os_strlen((char *)pbBridgeName))
		dwOutLen += sizeof(HOSTAPD_ELEM_T) + os_strlen((char *)pbBridgeName) ;
	if((pbPreauthIfName = (BYTE *)pstBss->conf->rsn_preauth_interfaces) != NULL)
		dwOutLen += sizeof(HOSTAPD_ELEM_T) + os_strlen((char *)pbPreauthIfName) ;

	if(dwOutLen
		&& (pbOut = os_zalloc(dwOutLen)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}

	pbFrame = pbOut ;
	if(pbBridgeName && os_strlen((char *)pbBridgeName))
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_BRIDGE, pbBridgeName, os_strlen((char *)pbBridgeName)) ;
	if(pbPreauthIfName)
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_PREAUTH_NAMES, pbPreauthIfName, os_strlen((char *)pbPreauthIfName)) ;

	bRet =  HostapdSend(NULL, pstBss, EV_HOSTAPD_VAP_START, pbOut, dwOutLen) ;
	if(bRet)
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, starting vap(%u/%u/%u) is notified success.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, starting vap(%u/%u/%u) is notified failed.\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;

#if 0
{
	u8 from[6] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66} ;
	u8 to[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06} ;
	u8 data[10] = {0x11, 0x12, 0x13} ;

	hostapd_send_eapol(pstBss, to, data, 10,  0, from) ;
}
#endif

	os_free(pbOut) ;

	eloop_cancel_timeout(VapStartTimeout, pstBss, ELOOP_ALL_CTX);
	eloop_register_timeout(300, pstBss->conf->bssid[5]*100000, VapStartTimeout, pstBss, (void *)EV_HOSTAPD_VAP_START);

	return bRet ;
}
#if 0
/*AC与VAP链路断时响应函数，使数据无效*/
static Boolean VapStop(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_data * pstBss = NULL ;

	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	/*使VAP数据无效*/
	hostapd_cleanup(pstBss) ;

	/*如果当前单卡上已停止所有VAP，则需停止单卡*/
	/*NONE*/

	return TRUE ;
}
#endif

/*
 功能：通知WTP中的HOSTAPD进程：创建VAP消息
 参数说明：
	usWtpId, ulInterfaceId, ulVapId都为设备管理模块中的ID编号
 返回值：
	成功返回TRUE，失败返回FALSE ；
*/
static BOOL NotifyVapAdd(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_data * pstBss = NULL ;
	char * pcDeviceName = NULL ;
	BYTE * pbOut = NULL ;
	WORD32 dwOutLen = 0 ;
	BOOL bRet = TRUE ;

	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	pcDeviceName = pstBss->conf->iface ;

	dwOutLen = sizeof(HOSTAPD_ELEM_T) + os_strlen(pcDeviceName) ;
	pbOut = os_zalloc(dwOutLen) ;
	if(pbOut == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}

	AddElem(pbOut, HOSTAPD_ELEMID_COMMON_DEVICENAME, (BYTE *)pcDeviceName, os_strlen(pcDeviceName)) ;

	bRet = HostapdSend(NULL, pstBss, EV_HOSTAPD_VAP_CREATE, pbOut , dwOutLen) ;

	os_free(pbOut) ;

	return bRet ;
}

/*
 功能：通知WTP中的HOSTAPD进程：删除VAP消息
 参数说明：
	usWtpId, ulInterfaceId, ulVapId都为设备管理模块中的ID编号
 返回值：
	成功返回TRUE，失败返回FALSE ；
*/
static BOOL NotifyVapDelete(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId)
{
	struct hostapd_data * pstBss = NULL ;

	if((pstBss = FindVap(usWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, usWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	return HostapdSend(NULL, pstBss, EV_HOSTAPD_VAP_DESTROY, NULL, 0) ;
}

/*层二数据转发*/
int l2_packet_transmit(void * tx_ctx, const u8 *dst_addr, u16 proto, const u8 *buf, size_t len)
{
	struct madwifi_driver_data * pstDriver = NULL ;
	struct rsn_preauth_interface * pstPreauthIf = NULL ;
	struct hostapd_data * pstBss = NULL ;
	u8 * pbOut = NULL , * pbFrame = NULL ;
	WORD16 usOutLen = 0 , wEvent =  0 ;
	int iRet ;

#if 1
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, type: %s, to "MACSTR", len(%u).\n",
		__func__, proto == ETH_P_EAPOL ? "EAPOL" : "PREAUTH/OTHER", MAC2STR(dst_addr), len) ;
#else
{
	unsigned long i ;

	printf("%s, type: %s, to "MACSTR", len(%u).\n",
		__func__, proto == ETH_P_EAPOL ? "EAPOL" : "PREAUTH/OTHER", MAC2STR(dst_addr), len) ;
	for(i = 1 ; i <= len ; i ++){
		printf("%02x.", buf[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
	printf("\n") ;
}
#endif

	switch(proto){
	case ETH_P_EAPOL :
		pstDriver = (struct madwifi_driver_data *)tx_ctx ;
		pstBss = pstDriver->hapd ;
		wEvent = EV_HOSTAPD_SOCKET_EAPOL ;
		break ;
	case ETH_P_RSN_PREAUTH :
		pstPreauthIf = (struct rsn_preauth_interface *)tx_ctx ;
		pstBss = pstPreauthIf->hapd ;
		wEvent = EV_HOSTAPD_SOCKET_PREAUTH ;
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, unknown proto(0x%x).\n", __func__, proto) ;
		return -1 ;
	}

	usOutLen = sizeof(HOSTAPD_ELEM_T) + ETH_ALEN
			+ sizeof(HOSTAPD_ELEM_T) + len ;
	if(proto == ETH_P_RSN_PREAUTH)
		usOutLen += sizeof(HOSTAPD_ELEM_T) + os_strlen(pstPreauthIf->ifname) ;

	pbOut = os_zalloc(usOutLen) ;
	if(pbOut == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return -1 ;
	}

	pbFrame = pbOut ;
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_MAC, (BYTE *)dst_addr, ETH_ALEN) ;
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_DATA, (BYTE *)buf, len) ;
	if(proto == ETH_P_RSN_PREAUTH)
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_DEVICENAME, (BYTE *)pstPreauthIf->ifname, os_strlen(pstPreauthIf->ifname)) ;

	if(HostapdSend(NULL, pstBss, wEvent, pbOut , usOutLen))
		iRet = len ;
	else
		iRet = -1 ;

	os_free(pbOut) ;

	return iRet ;
}

/*从AC发送给AP时，入参from须为NULL，
   从AC发送给本地AC时，入参from和to都须为NULL，
   从AP发送给AC时，入参to须为NULL，
   从AP发送给本地AP时，入参from和to都不能为NULL
*/
BOOL HostapdSend(struct hostapd_data * from ,
				struct hostapd_data * to ,
				WORD16 wEvent,
                         	BYTE *lpbyIn,
                        	WORD16 wInLen)
{
	HOSTAPD_HEAD_T stHostapdHead = {0} ;
	BYTE * pbOut = NULL ;
	WORD16 wOutLen = 0 ;
	TPID tReceiver = {0} ;
	BOOL bRet = FALSE ;

	VmSelfPid(& tReceiver) ;
	
	os_memset(& stHostapdHead, 0xff, sizeof(stHostapdHead)) ;
	if(from){
		stHostapdHead.ucFromInterface = from->iface->interface_index ;
		stHostapdHead.ucFromBss = from->vap_index ;
	}
	if(to){/*发送给AP*/
		tReceiver.wWtpId = to->iface->pstWtp->usWtpId ;
		stHostapdHead.ucToInterface = to->iface->interface_index ;
		stHostapdHead.ucToBss = to->vap_index ;
		if(to->state != AC_OPSTATE_NORMAL
			|| to->iface->pstWtp->state != AC_OPSTATE_NORMAL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, vap(%u/%u/%u: %d) or wtp(%u: %d) is not normal.\n",
				__func__, to->iface->pstWtp->usWtpId, to->iface->interface_id, to->vap_id, to->state, to->iface->pstWtp->usWtpId, to->iface->pstWtp->state) ;
			return FALSE ;
		}
	}
	else{/*发送给AC本地*/
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, not support.due to wrong TPID::wPno.\n", __func__) ;
		return FALSE ;
	}

	wOutLen = sizeof(HOSTAPD_HEAD_T) + wInLen ;
	pbOut = os_zalloc(wOutLen) ;
	if(pbOut == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s(%d), no memory.\n", __func__, __LINE__) ;
		bRet = FALSE ;
		goto bad ;
	}
	os_memcpy(pbOut, & stHostapdHead, sizeof(HOSTAPD_HEAD_T)) ;
	if(lpbyIn)
		os_memcpy(pbOut + sizeof(HOSTAPD_HEAD_T), lpbyIn, wInLen) ;

  	bRet = VmASend(wEvent, pbOut, wOutLen,  tReceiver) ;
	if(to && bRet == TRUE){
		switch(wEvent){
		case EV_HOSTAPD_VAP_CREATE:
			hostapd_acbss_stats_inc(to, ulSendApVapCreate);
			break;
		case EV_HOSTAPD_VAP_DESTROY:
			hostapd_acbss_stats_inc(to, ulSendApVapDestroy);
			break;
		case EV_HOSTAPD_VAP_START:
			hostapd_acbss_stats_inc(to, ulSendApVapStart);
			break;
		case EV_HOSTAPD_VAP_STOP:
			hostapd_acbss_stats_inc(to, ulSendApVapStop);
			break;
		case EV_HOSTAPD_SOCKET_IOCTL:
			hostapd_acbss_stats_inc(to, ulSendApIoctl);
			break;
		case EV_HOSTAPD_SOCKET_EAPOL:
			hostapd_acbss_stats_inc(to, ulSendApEapol);
			break;
		case EV_HOSTAPD_SOCKET_PREAUTH:
			hostapd_acbss_stats_inc(to, ulSendApPreauth);
			break;
		default:
			hostapd_acbss_stats_inc(to, ulSendApOther);
			break;
		}
	}
	else if(to){
		hostapd_acbss_stats_inc(to, ulSendApFailed);
	}
	
#if 0
	if(bRet){
		int i ;
		printf(" -->vap(%u/%u/%u), event(%u), len(%u).\n",
			tReceiver.wWtpId, stHostapdHead.ucToInterface, stHostapdHead.ucToBss, wEvent, wOutLen) ;
		for(i = 1 ; i <= wOutLen ; i ++){
			printf("%02x.", pbOut[i-1]) ;
			if(i % 10 == 0)
				printf("\n") ;
		}
	}
#endif

bad :
	if(pbOut){
		os_free(pbOut) ;
		pbOut = NULL ;
	}

	return bRet ;
}


int FindMac(u8 *pucMac, u8 *pucMacList, u32 ulMacListNum)
{
	int i;
	
	if(pucMac == NULL
		|| pucMacList == NULL)
		return 0;

	for(i = 0; i < ulMacListNum; i++){
		if(os_memcmp(pucMac, pucMacList+6*i, 6) == 0)
			return 1;
	}

	return 0;
}


void  CompareStaList(struct hostapd_data *pstBss, u8 *pucMacList, u32 ulMacListNum)
{
	struct sta_info *sta = NULL, *sta_next = NULL;
	int i = 0;
		
 	if(pstBss == NULL
		|| pucMacList == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point(%p, %p) is NULL.\n", __func__, pstBss, pucMacList);
		return;
	}

	/*打印AP/AC终端列表*/
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, ap/vap(%d/%d/%d), station-list num(%d).", 
		__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, ulMacListNum);
	for(i = 0; i < ulMacListNum; i++){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
			"%s, ap/vap(%d/%d/%d), station%d:"MACSTR".", 
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, i, MAC2STR(pucMacList+6*i));
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, ac/vap(%d/%d/%d), station-list num(%d).", 
		__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, pstBss->num_sta);
	for(sta = pstBss->sta_list, i = 0; sta != NULL; sta = sta->next){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
			"%s, ac/vap(%d/%d/%d), station%d:"MACSTR".", 
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, i, MAC2STR(sta->addr));
		i++;
	}

	/*由于大部分情况，AP/AC两侧一致，下述命中率高，提高比较性能*/
	if(ulMacListNum == pstBss->num_sta){
		int diff = 0;
			
		for(i = 0; i < ulMacListNum; i++){
			u_int8_t *pucMac = pucMacList + 6*i;

			if(ap_get_sta(pstBss, pucMac) == NULL){	/*终端在AP侧，但不在AC侧*/
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
					"%s, vap(%d/%d/%d), station("MACSTR") not exist on ac. deauth it...\n", 
					__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pucMac));

				/*从AP上删除终端*/
				hostapd_sta_deauth(pstBss, pucMac, WLAN_REASON_DEAUTH_LEAVING);
				hostapd_acbss_stats_inc(pstBss, ulStaDiffAp);
				
				diff++;
			}
		}

		if(!diff){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, vap(%d/%d/%d), AP(user list)==AC(user list).\n", 
				__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id);
			return;
		}

		/*寻找在AC侧，但不在AP侧的终端*/
		for(sta = pstBss->sta_list; sta != NULL; sta = sta_next){
			sta_next = sta->next;
			
			if(FindMac(sta->addr, pucMacList, ulMacListNum) == 0){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
					"%s, vap(%d/%d/%d), station("MACSTR") not exist on ap. del it...\n", 
					__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(sta->addr));
				
				/*从AC上删除终端*/
				madwifi_del_sta((struct madwifi_driver_data *)pstBss->driver, sta->addr, 0);
				hostapd_acbss_stats_inc(pstBss, ulStaDiffAc);
			}
		}

		return;
	}

	/*终端在AC侧，但不在AP侧*/
	for(sta = pstBss->sta_list; sta != NULL; sta = sta_next){
		sta_next = sta->next;
		
		if(FindMac(sta->addr, pucMacList, ulMacListNum) == 0){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, vap(%d/%d/%d), station("MACSTR") not exist on ap. del it......\n", 
				__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(sta->addr));
			
			/*从AC上删除终端*/
			madwifi_del_sta((struct madwifi_driver_data *)pstBss->driver, sta->addr, 0);
			hostapd_acbss_stats_inc(pstBss, ulStaDiffAc);
		}
	}

	/*终端在AP侧，但不在AC侧*/
	for(i = 0; i < ulMacListNum; i++){
		u_int8_t *pucMac = pucMacList + 6*i;

		if(ap_get_sta(pstBss, pucMac) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, vap(%d/%d/%d), station("MACSTR") not exist on ac. deauth it......\n", 
				__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pucMac));

			/*从AP上删除终端*/
			hostapd_sta_deauth(pstBss, pucMac, WLAN_REASON_DEAUTH_LEAVING);
			hostapd_acbss_stats_inc(pstBss, ulStaDiffAp);
		}
	}
}


void HostapdReadProfile(VOID)
{
	UINT32      ulKeyNum;
    char        acFile[256];

	VM_PROPERTY_DESC_T stDesc[] = {
		{"de_user_name",     PROPERTY_INT, 0, (UINT32)0, &g_ulDeUserName},
		{"mac_format", PROPERTY_INT, 0, (UINT32)0, &g_ulMacAddrFmt},
        {"mac_style", PROPERTY_INT, 0, (UINT32)0, &g_ulMacAddrStyle},
        {"alive_check",PROPERTY_INT,0,(UINT32)0, &g_ulAliveCheck}
	};

	ulKeyNum = sizeof(stDesc)/sizeof(stDesc[0]);

	/* 配置文件 */
    memset(acFile,0,sizeof(acFile));
    sprintf(acFile,"%s%s%s",VmGetUsrRootPath(),WLC_CONFIG_DIR,PROFILE_HOSTAPD);
	VmReadProperty(PROFILE_HOSTAPD, ulKeyNum, &stDesc[0]);	
	
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, de_user_name=%d.\n", __func__, g_ulDeUserName);	

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, mac_addr_format=%d,g_ulMacAddrStyle=%d.\n", __func__, g_ulMacAddrFmt,g_ulMacAddrStyle);	
}


#if 1
static BOOL OnMasterPowerOn(VOID)
{
	AC_USRM_GET_NASIP_RSP_T stNasIpRsp = {0};
	AC_DEVM_GET_WTP_CONFIG_REQ_T stWtpTableReq = {0} ;
	AC_DEVM_GET_WTP_CONFIG_RSP_T stWtpTable = {0} ;
	AC_DEVM_GET_IF_CONFIG_REQ_T stIfCfgReq = {0} ;
	AC_DEVM_GET_IF_CONFIG_RSP_T stIfTable = {0} ;
	AC_DEVM_GET_VAP_CONFIG_REQ_T stVapCfgReq = {{0}} ;
	AC_DEVM_GET_VAP_CONFIG_RSP_T stVapTable = {0} ;
	UINT32 ulWtpTableLen, ulIfTableLen, ulVapTableLen, ulLen ;
	BOOL bRet = TRUE ;
	int i, j, k;

	/* NB: generated by Makefile */
	register_drivers();

	HostapdReadProfile();

	/*获取NASIP*/
	ac_db_access(AC_USRM_GET_NASIP_MSG, NULL, 0, (UINT8 *)&stNasIpRsp, &ulLen);
	if(stNasIpRsp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, get nasip failed.\n", __func__) ;
	}
	os_memcpy(g_aucNasIp, stNasIpRsp.aucNasIp, 4);

	/*设置RADIUS服务器配置*/
	if(! SetRadiusServers(NULL)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call SetRadiusServers failed.\n", __func__) ;
		return FALSE ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, set radius servers success.\n", __func__) ;

	/*获取RADIUS服务器列表*/
	if(OnRadiusPowerOn() != TRUE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OnRadiusPowerOn failed.\n", __func__) ;
		return FALSE ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, call OnRadiusPowerOn success.\n", __func__) ;

	/*获取WTP设备集*/
	stWtpTableReq.ulStartRec = 0 ;
	do{
		os_memset(& stWtpTable, 0, sizeof(stWtpTable)) ;
		ac_db_access(AC_DEVM_GET_WTP_CONFIG_MSG, (UINT8 *)& stWtpTableReq, sizeof(stWtpTableReq), (UINT8 *)& stWtpTable, & ulWtpTableLen) ;
		if(stWtpTable.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, load wtp-table config failed, start(%d).\n", __func__, stWtpTableReq.ulStartRec) ;
			return FALSE ;
		}
		stWtpTableReq.ulStartRec += stWtpTable.ulWtpNum ;

		for(i = 0 ; i < stWtpTable.ulWtpNum ; i ++)
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, WTP[%u]: %s\n--IP: "IPSTR".\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId, stWtpTable.astWtp[i].stWtpBasic.acWtpName, IP2STR(stWtpTable.astWtp[i].stWtpIp.aucIp)) ;

		for(i = 0 ; i < stWtpTable.ulWtpNum ; i ++){
			if(! WtpAdd(& stWtpTable.astWtp[i])){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, add wtp(%u) failed.\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId.ulWtpId) ;
				continue ;
			}

			/*加载当前WTP下的所有单卡设备*/
			os_memcpy(& stIfCfgReq, & stWtpTable.astWtp[i].stWtpBasic.stWtpId, sizeof(stIfCfgReq)) ;
			os_memset(& stIfTable, 0, sizeof(stIfTable)) ;
			ac_db_access(AC_DEVM_GET_IF_CONFIG_MSG, (UINT8 *)& stIfCfgReq, sizeof(stIfCfgReq), (UINT8 *)& stIfTable, & ulIfTableLen) ;
			if(stIfTable.ulRet != AC_OK){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, load interface-table on wtp(%u) failed.\n", __func__, stIfCfgReq.ulWtpId) ;
				return FALSE ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, total interfaces on wtp(%u): %u.\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId.ulWtpId, stIfTable.ulIfNum) ;
			for(j = 0 ;  j < stIfTable.ulIfNum; j ++)
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, interface[%u/%u].\n", __func__,stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId) ;

			for(j = 0 ; j < stIfTable.ulIfNum ; j ++){
				if(! InterfaceAdd(& stIfTable.astIf[j])){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
						"%s, add interface(%u/%u) failed.\n", __func__, stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId) ;
					continue ;
				}

				/*加载当前单卡下的所有VAP设备*/
				os_memcpy(& stVapCfgReq.stIfId, & stIfTable.astIf[j].stIfId, sizeof(stIfTable.astIf[j].stIfId)) ;
				stVapCfgReq.ulStartRec = 0 ;
				do{
					os_memset(& stVapTable, 0, sizeof(stVapTable)) ;
					ac_db_access(AC_DEVM_GET_VAP_CONFIG_MSG, (UINT8 *)& stVapCfgReq, sizeof(stVapCfgReq), (UINT8 *)& stVapTable, & ulVapTableLen) ;
					if(stVapTable.ulRet != AC_OK){
						ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
							"%s, load vap-table on interface(%u/%u) failed, start(%d).\n", 
							__func__, stVapCfgReq.stIfId.ulWtpId, stVapCfgReq.stIfId.ulIfId, stVapCfgReq.ulStartRec) ;
						return FALSE ;
					}
					stVapCfgReq.ulStartRec += stVapTable.ulVapNum ;

					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, get vaps on interface(%u/%u): %u.\n", __func__, stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId, stVapTable.ulVapNum) ;

					for(k = 0 ; k < stVapTable.ulVapNum ; k ++){
						if(! VapAdd(& stVapTable.astVap[k])){
							ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
								"%s, add vap(%u/%u/%u) failed.\n", __func__, stVapTable.astVap[k].stVapId.ulWtpId, stVapTable.astVap[k].stVapId.ulIfId, stVapTable.astVap[k].stVapId.ulVapId) ;
							/* bRet = FALSE ; */
							continue ;
						}
						else
							ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
								"%s, add vap(%u/%u/%u) success.\n", __func__, stVapTable.astVap[k].stVapId.ulWtpId, stVapTable.astVap[k].stVapId.ulIfId, stVapTable.astVap[k].stVapId.ulVapId) ;
					}
				}while(stVapTable.ulFinish != AC_DB_TABLE_READ_FINISH) ;
			}
		}
	}while(stWtpTable.ulFinish != AC_DB_TABLE_READ_FINISH) ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
		"%s, total wtp(%d).\n", __func__, stWtpTableReq.ulStartRec) ;

	return bRet ;
}
#else
static BOOL OnMasterPowerOn()
{
	AC_DEVM_GET_WTP_CONFIG_REQ_T stWtpTableReq = {0} ;
	AC_DEVM_GET_WTP_CONFIG_RSP_T stWtpTable = {0} ;
	AC_DEVM_GET_IF_CONFIG_REQ_T stIfCfgReq = {0} ;
	AC_DEVM_GET_IF_CONFIG_RSP_T stIfTable = {0} ;
	AC_DEVM_GET_VAP_CONFIG_REQ_T stVapCfgReq = {0} ;
	AC_DEVM_GET_VAP_CONFIG_RSP_T stVapTable = {0} ;
	UINT32 ulWtpTableLen, ulIfTableLen, ulVapTableLen, ulWtpStartRec = 0;
	BOOL bRet = TRUE ;
	int i, j, k;

	/* NB: generated by Makefile */
	register_drivers();

	/*设置RADIUS服务器配置*/
	if(! SetRadiusServers(NULL)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call SetRadiusServers failed.\n", __func__) ;
		return FALSE ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, set radius servers success.\n", __func__) ;

	do{
#if 0		
		/*加载所有WTP设备*/
		os_memset(& stWtpTable, 0, sizeof(stWtpTable)) ;
		//ac_devm_get_wtp_config(NULL, 0, & stWtpTable, & ulWtpTableLen) ;
		ac_db_access(AC_DEVM_GET_WTP_CONFIG_MSG, NULL, 0, & stWtpTable, & ulWtpTableLen) ;
		if(stWtpTable.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, load wtp-table config failed.\n", __func__) ;
			return FALSE ;
		}

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, total wtp: %d.\n", __func__, stWtpTable.ulWtpNum) ;
#else
		stWtpTableReq.ulStartRec = ulWtpStartRec ;
		os_memset(& stWtpTable, 0, sizeof(stWtpTable)) ;
		ac_db_access(AC_DEVM_GET_WTP_CONFIG_MSG, & stWtpTableReq, sizeof(stWtpTableReq), & stWtpTable, & ulWtpTableLen) ;
		if(stWtpTable.ulRet != AC_OK){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, load wtp-table config failed, start(%d).\n", __func__, stWtpTableReq.ulStartRec) ;
			return FALSE ;
		}

		ulWtpStartRec += stWtpTable.ulWtpNum ;
#endif
		for(i = 0 ; i < stWtpTable.ulWtpNum ; i ++)
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, WTP[%u]: %s\n--IP: "IPSTR".\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId, stWtpTable.astWtp[i].stWtpBasic.acWtpName, IP2STR(stWtpTable.astWtp[i].stWtpIp.aucIp)) ;

		for(i = 0 ; i < stWtpTable.ulWtpNum ; i ++){
			if(! WtpAdd(& stWtpTable.astWtp[i])){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, add wtp(%u) failed.\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId.ulWtpId) ;
				bRet = FALSE ;
				continue ;
			}

			/*加载当前WTP下的所有单卡设备*/
			os_memcpy(& stIfCfgReq, & stWtpTable.astWtp[i].stWtpBasic.stWtpId, sizeof(stIfCfgReq)) ;
			os_memset(& stIfTable, 0, sizeof(stIfTable)) ;
			//ac_devm_get_if_config(& stIfCfgReq, sizeof(stIfCfgReq), & stIfTable, & ulIfTableLen) ;
			ac_db_access(AC_DEVM_GET_IF_CONFIG_MSG, & stIfCfgReq, sizeof(stIfCfgReq), & stIfTable, & ulIfTableLen) ;
			if(stIfTable.ulRet != AC_OK){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, load interface-table on wtp(%u) failed.\n", __func__, stIfCfgReq.ulWtpId) ;
				bRet = FALSE ;
				continue ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, total interfaces on wtp(%u): %u.\n", __func__, stWtpTable.astWtp[i].stWtpBasic.stWtpId.ulWtpId, stIfTable.ulIfNum) ;
			for(j = 0 ;  j < stIfTable.ulIfNum; j ++)
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, interface[%u/%u].\n", __func__,stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId) ;

			for(j = 0 ; j < stIfTable.ulIfNum ; j ++){
				if(! InterfaceAdd(& stIfTable.astIf[j])){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
						"%s, add interface(%u/%u) failed.\n", __func__, stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId) ;
					bRet = FALSE ;
					continue ;
				}

				/*加载当前单卡下的所有VAP设备*/
				os_memcpy(& stVapCfgReq, & stIfTable.astIf[j].stIfId, sizeof(stVapCfgReq)) ;
				os_memset(& stVapTable, 0, sizeof(stVapTable)) ;
				//ac_devm_get_vap_config(& stVapCfgReq, sizeof(stVapCfgReq), & stVapTable, & ulVapTableLen) ;
				ac_db_access(AC_DEVM_GET_VAP_CONFIG_MSG, & stVapCfgReq, sizeof(stVapCfgReq), & stVapTable, & ulVapTableLen) ;
				if(stVapTable.ulRet != AC_OK){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
						"%s, load vap-table on interface(%u/%u) failed.\n", __func__, stVapCfgReq.ulWtpId, stVapCfgReq.ulIfId) ;
					bRet = FALSE ;
					continue ;
				}

				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, total vaps on interface(%u/%u): %u.\n", __func__, stIfTable.astIf[j].stIfId.ulWtpId, stIfTable.astIf[j].stIfId.ulIfId, stVapTable.ulVapNum) ;
	/*
				for(k = 0 ; k < stVapTable.ulVapNum ; k ++)
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, vap[%u/%u/%u] :\n"
						"--interface name:\t%s.\n"
						"--bssid:\t\t"MACSTR".\n"
						"--ssid:\t\t\t%s.\n"
						"--ssid not hide:\t%u.\n"
						"--auth(bit0: open, bit1: shared, bit2: wpa, bit3: wpa-psk):\t0x%x.\n"
						"--encypt(bit0: none, bit1: wep, bit2: TKIP, bit3: CCMP):\t0x%x.\n"
						"--wpa key:\t\t%s.\n"
						"--wpa rekey period(s):\t%u.\n"
						"--wep key len(1: 64bit, 2: 128bit):\t\t%u.\n"
						"--wep key input format(1: hex, 2: ASCII):\t%u.\n"
						"--wep key:\t\t%s.\n"
						"--wep rekey period(s):\t%u.\n"
						"--wep key index:\t%u.\n"
						"--use 8021x:\t\t%u.\n"
						"--EAP Version:\t\t%u.\n"
						"--EAP Auth Period(s):\t%u.\n",
						__func__,
						stVapTable.astVap[k].stVapId.ulWtpId, stVapTable.astVap[k].stVapId.ulIfId, stVapTable.astVap[k].stVapId.ulVapId,
						stVapTable.astVap[k].acIfName, MAC2STR(stVapTable.astVap[k].aucBssid), stVapTable.astVap[k].acSsid,
						stVapTable.astVap[k].ulSsidBroadcast, stVapTable.astVap[k].ulAuth, stVapTable.astVap[k].ulEncrypt,
						stVapTable.astVap[k].acWpaKey, stVapTable.astVap[k].ulWpaRekeyPeriod, stVapTable.astVap[k].ulWepKeyLen,
						stVapTable.astVap[k].ulInputFormat, stVapTable.astVap[k].acWepKey, stVapTable.astVap[k].ulWepRekeyPeriod,
						stVapTable.astVap[k].ulWepKeyIndex, stVapTable.astVap[k].ul8021x, stVapTable.astVap[k].ulEapolVer,stVapTable.astVap[k].ulEapAuthPeriod) ;
	*/
				for(k = 0 ; k < stVapTable.ulVapNum ; k ++){
					if(! VapAdd(& stVapTable.astVap[k])){
						ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
							"%s, add vap(%u/%u/%u) failed.\n", __func__, stVapTable.astVap[k].stVapId.ulWtpId, stVapTable.astVap[k].stVapId.ulIfId, stVapTable.astVap[k].stVapId.ulVapId) ;
						/* bRet = FALSE ; */
						continue ;
					}
					else
						ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
							"%s, add vap(%u/%u/%u) success.\n", __func__, stVapTable.astVap[k].stVapId.ulWtpId, stVapTable.astVap[k].stVapId.ulIfId, stVapTable.astVap[k].stVapId.ulVapId) ;
				}
			}
		}
	}while(stWtpTable.ulFinish != AC_DB_TABLE_READ_FINISH) ;

	ModuleLogMsg(APP_MODULE_RRM, APP_MSG, 
		"%s, total wtp(%d).\n", __func__, ulWtpStartRec) ;

	return bRet ;
}
#endif



void	eap_user_force_down(AC_USRM_EAPUSEROFFLINE_REQ_MSG_T *pstReq, WORD16	wLen)
{
	struct	hostapd_data *pstBss = NULL;
	struct	sta_info		*pstSta = NULL;
	
	if(NULL == pstReq)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the msg we received is valid. \n", __func__);
			return ;
		}

	pstBss = FindVap(pstReq->stVapId.ulWtpId, pstReq->stVapId.ulIfId, pstReq->stVapId.ulVapId);
	if(NULL == pstBss)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
				"%s, the ap%d, radio%d,vap%d is NOT exist. \n",
				__func__,
				pstReq->stVapId.ulWtpId,
				pstReq->stVapId.ulIfId,
				pstReq->stVapId.ulVapId);
			return ;
		}

	pstSta = ap_get_sta(pstBss, pstReq->aucMac);
	if(NULL == pstSta)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, can NOT find the sta("MACSTR"). \n",
							__func__, MAC2STR(pstReq->aucMac));
			return ;
		}

	ap_sta_deauthenticate_imm(pstBss, pstSta, WLAN_REASON_UNSPECIFIED);

	return ;
}

static BOOL OnVapIoctlFailed(struct hostapd_data *  pstBss, WORD32 ulIoctl)
{
	if(pstBss == NULL
		|| pstBss->iface == NULL
		|| pstBss->iface->pstWtp == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		"%s, vap(%u/%u/%u), ioctl(0x%x) failed.\n", __func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, ulIoctl) ;

	/*删除所有用户*/
	hostapd_free_stas(pstBss) ;

	return TRUE ;
}

void OnWaitVapIoctlTimer(void *eloop_ctx, void *timeout_ctx)
{
	struct hostapd_data * pstBss = NULL ;
	unsigned long ulIoctl = 0, i = 0, j = 0 ;

	if((pstBss = eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	for(i = 0 ; i < IOCTL_STATE_BYTES ; i ++){
		if(! pstBss->ioctl_state[i])
			continue ;

		for(j = 0 ; j < 8 ; j ++){
			if(! (pstBss->ioctl_state[i] & 1 << j))
				continue ;

			ulIoctl = IOCTL_STATE_BEGIN + 8 * i + j ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, vap(%u/%u/%u), ioctl(0x%x) timeout.\n", __func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, ulIoctl) ;

			IOCTL_STATE_RESET(pstBss->ioctl_state, ulIoctl) ;
		}
	}

	if(ulIoctl){
		hostapd_acbss_stats_inc(pstBss, ulIoctlTimeoutVap);
		OnVapIoctlFailed(pstBss, 0) ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u), all ioctl success.\n",
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;

	return ;
}

static BOOL OnStaIoctlFailed(struct hostapd_data *  pstBss, struct sta_info * pstSta, WORD32 ulIoctl)
{
	if(pstBss == NULL
		|| pstSta == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		"%s, sta(%u/%u/%u/"MACSTR"), ioctl(0x%x) failed.\n",
		__func__, pstBss->iface->pstWtp->usWtpId,  pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pstSta->addr), ulIoctl) ;

	/*删除用户*/
	if(pstSta->flags & WLAN_STA_ASSOC)
		ap_sta_disassociate(pstBss, pstSta, 1) ;

	return TRUE ;
}

void OnWaitStaIoctlTimer(void *eloop_ctx, void *timeout_ctx)
{
	struct hostapd_data * pstBss = NULL ;
	struct sta_info * pstSta = NULL ;
	unsigned long ulIoctl = 0, i = 0, j = 0 ;

	if((pstBss = eloop_ctx) == NULL
		|| (pstSta = timeout_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}

	for(i = 0 ; i < IOCTL_STATE_BYTES ; i ++){
		if(! pstSta->ioctl_state[i])
			continue ;

		for(j = 0 ; j < 8 ; j ++){
			if(! (pstSta->ioctl_state[i] & 1 << j))
				continue ;

			ulIoctl = IOCTL_STATE_BEGIN + 8 * i + j ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, sta(%u/%u/%u/"MACSTR"), ioctl(0x%x) timeout.\n",
				__func__, pstBss->iface->pstWtp->usWtpId,  pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pstSta->addr), ulIoctl) ;

			IOCTL_STATE_RESET(pstSta->ioctl_state, ulIoctl) ;
		}
	}

	if(ulIoctl){
		hostapd_acbss_stats_inc(pstBss, ulIoctlTimeoutSta);
		OnStaIoctlFailed(pstBss, pstSta, 0) ;
	}
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, sta(%u/%u/%u/"MACSTR"), all ioctl success.\n",
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pstSta->addr)) ;

	return ;
}

/*
 功能：处理IOCTL返回值
 消息格式：IOCTL_ID + LEN + IOCTL_CTX(IOCTL_RETURN[ACK(0) || NACK(-1)] + USER_MAC)
*/
static BOOL OnIoctl(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	int * piIoctlRet = NULL ;
	BYTE * pbMac = NULL , abMacNull[ETH_ALEN] = {0} , abMacAll1[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff} ;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;
	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}
	hostapd_acbss_stats_inc(pstBss, ulRecvApIoctl);

	if(! pstBss->setuped){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) is not setup.\n", __func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;
		return TRUE ;
	}

	pElem = pbyBody + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLen - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		piIoctlRet = (int *)((BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T)) ;
		pbMac = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) + sizeof(int) ;

		(* piIoctlRet) = ntohl(* piIoctlRet) ;

		if(* piIoctlRet)
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, ioctl(0x%x) on vap(%u/%u/%u), ret %s, from "MACSTR".\n",
				__func__, pstHostapdElem->dwElemId, wWtpId, pstBss->iface->interface_id, pstBss->vap_id, (* piIoctlRet) ? "NACK" : "ACK", MAC2STR(pbMac)) ;

		if(os_memcmp(pbMac, abMacNull, ETH_ALEN) == 0
			|| os_memcmp(pbMac, abMacAll1, ETH_ALEN) == 0){/*AP IOCTL 处理*/
			if(! ioctl_state_get(pstBss->ioctl_state, pstHostapdElem->dwElemId))
				goto next ;

			IOCTL_STATE_RESET(pstBss->ioctl_state, pstHostapdElem->dwElemId) ;

			if(* piIoctlRet){/*NACK处理*/
				OnVapIoctlFailed(pstBss, pstHostapdElem->dwElemId) ;
			}
		}
		else{/*用户IOCTL处理*/
			struct sta_info * pstSta = ap_get_sta(pstBss, pbMac) ;

			if(pstSta== NULL){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, not exist sta: "MACSTR", ioctl(0x%x).\n", __func__, MAC2STR(pbMac), pstHostapdElem->dwElemId) ;
				goto next;
			}

			if(! ioctl_state_get(pstSta->ioctl_state, pstHostapdElem->dwElemId))
				goto next ;

			IOCTL_STATE_RESET(pstSta->ioctl_state, pstHostapdElem->dwElemId) ;

			if(* piIoctlRet){/*NACK处理*/
				OnStaIoctlFailed(pstBss, pstSta, pstHostapdElem->dwElemId) ;
			}
		}
next :
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct.\n", __func__, lLength) ;
		return FALSE ;
	}

	return TRUE ;
}

static BOOL SendEventAck(WORD16 wWtpId, WORD32 wInterfaceId, WORD32 wVapId,UINT32 wEventId)
{
    struct hostapd_data * pstBss = NULL ;
	char * pcDeviceName = NULL ;
	BYTE *pbFrame = NULL,*pbOut = NULL;
	WORD32 dwOutLen = 0 ;
    UINT32 ulEventId = 0;
	BOOL bRet = TRUE ;

	if((pstBss = FindVapByIndex(wWtpId, wInterfaceId, wVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, wWtpId, wInterfaceId, wVapId) ;
		return FALSE ;
	}

	pcDeviceName = pstBss->conf->iface ;

	dwOutLen = sizeof(HOSTAPD_ELEM_T) + os_strlen(pcDeviceName) ;
	pbFrame = os_zalloc(dwOutLen) ;
	if(pbFrame == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}
    pbOut = pbFrame;
    ulEventId = HTONL(wEventId);
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EVENT_ID, (BYTE *)&ulEventId, sizeof(ulEventId)) ;

	bRet = HostapdSend(NULL, pstBss, EV_HOSTAPD_SOCKET_EVENTACK, pbOut , dwOutLen) ;

    if(bRet){
    	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s,HostapdSend event_id:%u success \n", __func__,wEventId) ;

    }
    os_free(pbOut);
	return bRet ;

}

static BOOL OnAddUser(BYTE * pbyBody, WORD16 wLen)
{
	AC_USRM_USER_ADD_IND_MSG_T	*pstAddUser = NULL;
	
	struct	hostapd_data	*pstBss = NULL;
	struct	sta_info		*pstSta = NULL;
	BYTE * pbOut = NULL, * pbFrame = NULL ;
	WORD32	dwOutLen = 0;
	
	UINT32	ulUpRate = 0;
	UINT32	ulDownRate = 0;
	UINT32	ulBurstBuf = 0;
	BOOL 	bRet = TRUE;

	if((NULL == pbyBody)||(wLen < sizeof(AC_USRM_USER_ADD_IND_MSG_T)))
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the msg we received is invalid. \n", __func__);
			return FALSE ;
		}

	pstAddUser = (AC_USRM_USER_ADD_IND_MSG_T *)pbyBody;

	/*     查找对应的AP-ID, RADIO-ID, VAP-ID    */
	pstBss = FindVap(pstAddUser->stVapId.ulWtpId, pstAddUser->stVapId.ulIfId, pstAddUser->stVapId.ulVapId);
	if(NULL == pstBss)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, we can NOT find the ap %d, radio %d, vap %d. \n",
							__func__, 
							pstAddUser->stVapId.ulWtpId, 
							pstAddUser->stVapId.ulIfId, 
							pstAddUser->stVapId.ulVapId);
			return FALSE;
		}

	/*  查找此STA是否在hostapd模块记录过   */
	pstSta = ap_get_sta(pstBss, pstAddUser->aucMac);
	if(NULL == pstSta)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, can NOT find the sta("MACSTR"). \n",
							__func__, MAC2STR(pstAddUser->aucMac));
			return FALSE;
		}

      /*  获取流控参数 */
	  ulUpRate = pstAddUser->stQos.ulUpBandMin;		/* 单位kb  */
	  ulDownRate = pstAddUser->stQos.ulDownBandMin;	/*  单位kb  */
	  ulBurstBuf = ulDownRate/4;
	  if(ulBurstBuf == 0)
	  	ulBurstBuf = ulUpRate/4;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
					"%s, the flow ctrl refrence is below: \n"
					"sta mac = "MACSTR"\n"
					"uprate = %dkbps \n"
					"downrate = %dkbps \n"
					"burstbuf = %dKB \n"
					"ap-id = %d \n"
					"radio-id = %d \n"
					"vap-id = %d \n",
					__func__,
					MAC2STR(pstAddUser->aucMac),
					ulUpRate,
					ulDownRate,
					ulBurstBuf,
					pstAddUser->stVapId.ulWtpId,
					pstAddUser->stVapId.ulIfId,
					pstAddUser->stVapId.ulVapId);

	/*  获取添加参数后的消息总长度  */
	dwOutLen = sizeof(HOSTAPD_ELEM_T) + sizeof(ulUpRate) 	/*  AP流控，上行限速chary，2011-11-8 */
			+ sizeof(HOSTAPD_ELEM_T) + sizeof(ulDownRate) 	/*  AP流控，下行限速chary，2011-11-8 */
			+ sizeof(HOSTAPD_ELEM_T) + sizeof(ulBurstBuf) 	/*  AP流控，突发字节chary，2011-11-8 */
			+ sizeof(HOSTAPD_ELEM_T) + sizeof(pstAddUser->aucMac);	/*  AP流控，STA的MAC地址chary，2011-11-8 */

	/*  为将发向hostapd-AP的消息分配空间  */
	if(dwOutLen
		&& (pbFrame = os_zalloc(dwOutLen)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}

	pbOut = pbFrame;	/*  保护消息地址，下面操作会改变pbFrame 的值  */

	/*  在消息中添加信元*/
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_MAC, pstAddUser->aucMac, 6) ;
	
	ulUpRate = HTONL(ulUpRate);
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_FC_UPRATE, (BYTE *)&ulUpRate, sizeof(ulUpRate)) ;

	ulDownRate = HTONL(ulDownRate);
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_FC_DOWNRATE, (BYTE *)&ulDownRate, sizeof(ulDownRate)) ;

	ulBurstBuf = HTONL(ulBurstBuf);
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_FC_BURSTSIZE, (BYTE *)&ulBurstBuf, sizeof(ulBurstBuf)) ;

	/*  发送消息去hostapd-AP模块  */
	bRet= HostapdSend(NULL, pstBss, EV_HOSTAPD_ADD_USER, pbOut, dwOutLen);

	/*  释放所申请的内存  */
	os_free(pbOut);

	if(bRet)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s, send USER-ADD msg to AP Successful. \n", __func__);
			return TRUE;
		}

	else
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, send USER-ADD msg to AP Failed. \n", __func__);
			return FALSE;
		}
	
}




static BOOL OnEvent(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	BYTE * pElem = NULL ;
	long lLength = 0, lMacListNum = -1 ;
	u_int16_t usCmd = 0, usAssocId = 0, usReason = 0;
	BYTE * pbData = NULL, *pucMacList = NULL ;
	WORD32 dwDataLen = 0;
	u32 *pulEventId = NULL;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;
	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}
	hostapd_acbss_stats_inc(pstBss, ulRecvApEvent);

	if(! pstBss->setuped){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) is not setup.\n", __func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;
		return TRUE ;
	}

	pElem = pbyBody + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLen - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_EVENT_CMD :
			usCmd = * (WORD16 *)((BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T)) ;
			usCmd = ntohs(usCmd) ;
			break ;
		case HOSTAPD_ELEMID_EVENT_DATA :
			pbData = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_EVENT_ASSOCID :
			os_memcpy(& usAssocId, & pstHostapdElem[1], sizeof(usAssocId)) ;
			usAssocId = ntohs(usAssocId) ;
			break ;
		case HOSTAPD_ELEMID_EVENT_REASON:
			os_memcpy(&usReason, &pstHostapdElem[1], sizeof(usReason));
			usReason = ntohs(usReason);
			break;
		case HOSTAPD_ELEMID_COMMON_MACLIST:
			pucMacList = (BYTE *)&pstHostapdElem[1];
			lMacListNum = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T);
			if((lMacListNum%6) == 0){
				lMacListNum /= 6;
			}
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, vap(%d/%d/%d), mac list, length(%d) is invalid.\n", 
					__func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id, pstHostapdElem->dwLength) ;
				lMacListNum = -1;
			}
			break;
		case HOSTAPD_ELEMID_EVENT_ID:            
			pulEventId  = (u32 *)((BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T)) ;
			*pulEventId  = NTOHL(*pulEventId);
             ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event_id :%u\n", __func__, *pulEventId) ;
            break;
            
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, unknown dwElemId: %lu,dwLength:%ld.\n", 
				__func__, pstHostapdElem->dwElemId,pstHostapdElem->dwLength) ;
			return  FALSE;
		}
	    /*add by dhsong,bug 2769,2013-6-4,cpu 利用率达到100%*/	
            if(sizeof(HOSTAPD_ELEM_T)>=pstHostapdElem->dwLength){
                    ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
        				"%s, dwElemId: %lu.dwLength:%ld.\n", 
        				__func__, pstHostapdElem->dwElemId,pstHostapdElem->dwLength) ;
                   return FALSE ;
            }
            /*add by dhsong,bug 2769,2013-6-4,cpu 利用率达到100%*/	
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0
		|| usCmd == 0
		|| pbData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct.\n", __func__, lLength) ;
		return FALSE ;
	}

	/*解析不同的CMD*/
	switch(usCmd){
	case IWEVEXPIRED :{
		struct sta_info * sta = NULL ;
		
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u), receive event/iwevexpired: "MACSTR", time out: %d.\n",
			__func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pbData), usReason) ;
		/*begin TASK #476 fangz 2013.2.26 log*/
		syslogu(LM_BUSINESS,LOG_EMERG,"Message:(disassociated)"
		"%s,vap(%u/%u/%u),STA("MAC_LOG_FMT"),SSID(%s),Time out:%d.",
		__func__,wWtpId, pstBss->iface->interface_id, pstBss->vap_id,
		MAC2STR(pbData),pstBss->conf->ssid.ssid,usReason
		);
		/*end TASK #476 fangz 2013.2.26 log*/
		hostapd_acbss_stats_inc(pstBss, ulRecvApEventLogout);

		if((sta = ap_get_sta(pstBss, pbData)) != NULL){
			if(! sta->leave){
				//sta->leave_reason = ?? ;
				sta->leave = 1 ;
			}
			
			if(usReason)
				sta->acct_terminate_cause = RADIUS_ACCT_TERMINATE_CAUSE_IDLE_TIMEOUT;
			madwifi_del_sta((struct madwifi_driver_data *)pstBss->driver, pbData, usReason) ;
		}
		
		break ;
	}
	case IWEVREGISTERED :{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u), receive event/iwevregistered: "MACSTR", associd(%u), reassoc(%d).\n",
			__func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id, MAC2STR(pbData), usAssocId, usReason) ;
		hostapd_acbss_stats_inc(pstBss, ulRecvApEventLogin);
		/*begin TASK #476 fangz 2013.2.26 log*/
		syslogu(LM_BUSINESS,LOG_EMERG,"Message:(associated)"
		"%s,vap(%u/%u/%u),STA("MAC_LOG_FMT"),associd(%u),SSID(%s),reassoc(%d).",
		__func__,wWtpId, pstBss->iface->interface_id, pstBss->vap_id,
		MAC2STR(pbData),usAssocId, pstBss->conf->ssid.ssid, usReason
		);
		/*end TASK #476 fangz 2013.2.26 log*/
		pstBss->stats.access ++ ;
		madwifi_new_sta((struct madwifi_driver_data *)pstBss->driver, pbData, usReason, usAssocId) ;

		break ;
	}
	case IWEVCUSTOM :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, receive event/iwevcustom.\n", __func__) ;

		madwifi_wireless_event_wireless_custom((struct madwifi_driver_data *)pstBss->driver, (char *)pbData) ;
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, unknown cmd(0x%x).\n", __func__, usCmd) ;
		break ;
	}

	if(lMacListNum >= 0)
		CompareStaList(pstBss, pucMacList, lMacListNum);

	if(pulEventId)
		SendEventAck(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, *pulEventId);
	
	return TRUE ;
}

static BOOL OnEapol(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	BYTE * pabMac = NULL, * pbData = NULL ;
	WORD32 dwDataLen = 0 ;
	BYTE * pbKeyRsc = NULL ;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;
	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}
	hostapd_acbss_stats_inc(pstBss, ulRecvApEapol);

	if(! pstBss->setuped ||
		(pstBss->conf && pstBss->conf->wapi)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) is setuped(%d), wapi(%d).\n", 
			__func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id, pstBss->setuped, pstBss->conf ? pstBss->conf->wapi : 0) ;
		return TRUE ;
	}

	pElem = pbyBody + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLen - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_MAC :
			pabMac = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			if(ETH_ALEN != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, invalic mac len(%u).\n", __func__, pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)) ;
				pabMac = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_DATA :
			pbData = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_EAPOL_KEYRSC :
			pbKeyRsc = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			if(IEEE80211_WEP_NKID*WPA_KEY_RSC_LEN != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, invalic key_rsc len(%u).\n", __func__, pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)) ;
				pbKeyRsc = NULL ;
			}
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			 break;
		}
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0
		|| pabMac == NULL
		|| pbData == NULL
		|| pbKeyRsc == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct.\n", __func__, lLength) ;
		return FALSE ;
	}

#if 0
{
	int i ;

	printf("receive eapol(%u) from "MACSTR" :\n", dwDataLen, MAC2STR(pabMac)) ;
	for(i = 1; i <= dwDataLen ; i ++){
		printf("%02x.", pbData[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
	printf("\n") ;
}
#endif

	/*保存KEY_RSC*/
	os_memcpy(pstBss->key_rsc, pbKeyRsc, IEEE80211_WEP_NKID*WPA_KEY_RSC_LEN) ;

	handle_read(pstBss->driver, pabMac, pbData, dwDataLen) ;

	return TRUE ;
}

static BOOL OnPreauth(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	struct rsn_preauth_interface * pstPreauth = NULL ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	BYTE * pabMac = NULL, * pbData = NULL, * pbDeviceName = NULL , pbPreauthName[IFNAMSIZ+1] ;
	WORD32 dwDataLen = 0 , dwDeviceNameLen = 0 ;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;
	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}
	hostapd_acbss_stats_inc(pstBss, ulRecvApPreauth);

	if(! pstBss->setuped){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%u/%u/%u) is not setup.\n", __func__, wWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;
		return TRUE ;
	}

	pElem = pbyBody + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLen - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_MAC :
			pabMac = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_COMMON_DATA :
			pbData = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_COMMON_DEVICENAME :
			pbDeviceName = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwDeviceNameLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			break ;
		}

		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0
		|| pabMac == NULL
		|| pbData == NULL
		|| pbDeviceName == NULL
		|| dwDeviceNameLen > IFNAMSIZ){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct.\n", __func__, lLength) ;
		return FALSE ;
	}

	os_memcpy(pbPreauthName, pbDeviceName, dwDeviceNameLen) ;
	pbPreauthName[dwDeviceNameLen] = '\0' ;

	/*根据PREAUTH设备名在当前VAP设备中查找PREAUTH设备*/
	for(pstPreauth = pstBss->preauth_iface ; pstPreauth ; pstPreauth = pstPreauth->next)
		if(os_strcmp(pstPreauth->ifname, (char *)pbPreauthName) == 0)
			break ;
	if(pstPreauth == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, preauth interface %s is not exist on vap %s.\n", __func__, pbPreauthName, pstBss->conf->iface) ;
		return FALSE ;
	}

	rsn_preauth_receive(pstPreauth, pabMac, pbData, dwDataLen) ;

	return TRUE ;
}

static void VapStartTimeout(void *eloop_ctx, void *timeout_ctx)
{
	struct hostapd_data * pstBss = NULL ;
	
	if((pstBss = eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__);
		return;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, start vap(%u/%u/%u).\n", 
		__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id) ;
	
	pstBss->timeout_vapstart++;
	if(pstBss->timeout_vapstart > 3){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, start vap(%u/%u/%u), timeout(%d).\n", 
			__func__, pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id, pstBss->timeout_vapstart) ;
		return;
	}

	hostapd_acbss_stats_inc(pstBss, ulVapStartTimeout);
	VapStart(pstBss->iface->pstWtp->usWtpId, pstBss->iface->interface_id, pstBss->vap_id);
	
	return;
}

static BOOL OnCreateVapNack(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	struct hostapd_data * pstBss = NULL ;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;
	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
		"%s, receive nack from vap(index: %u/%u/%u).\n", 
		__func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
	hostapd_acbss_stats_inc(pstBss, ulRecvApVapCreateNack);

	
	return TRUE;
}


static BOOL OnMsgAck(WORD16 wWtpId, BYTE * pbyBody, WORD16 wLen)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	/* struct rsn_preauth_interface * pstPreauth = NULL ; */
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	WORD32 dwMsgId = 0 ;

	/*获取消息头内容*/
	if(wWtpId < AC_WTPID_MIN
		|| wWtpId > AC_WTPID_MAX
		||pbyBody == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, wWtpId is over(%d), or point is NULL , or length(%d) is too short.\n", __func__, wWtpId, wLen) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T * )pbyBody ;

	pElem = pbyBody + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLen - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_MSGID :
			if(pstHostapdElem->dwLength != sizeof(HOSTAPD_ELEM_T) + sizeof(WORD32)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, invalid msg len(%d).\n", __func__, pstHostapdElem->dwLength);
				break;
			}
			os_memcpy(&dwMsgId, &pstHostapdElem[1], sizeof(WORD32));
			dwMsgId = NTOHL(dwMsgId);
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			break ;
		}

		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0
		|| dwMsgId == 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct, or dwMsgId(%d) is invalid.\n", __func__, lLength, dwMsgId) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, receive msg(%u) ack from vap(index: %u/%u/%u).\n", 
		__func__, dwMsgId, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;

	if(dwMsgId == EV_HOSTAPD_WTP_INIT
		|| dwMsgId == EV_HOSTAPD_WTP_SLAVE_INIT){
		return TRUE;
	}

	if((pstBss = FindVapByIndex(wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(index: %u/%u/%u) is not exist.\n", __func__, wWtpId, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss) ;
		return FALSE ;
	}
		
	switch(dwMsgId){
	case EV_HOSTAPD_VAP_CREATE:
		hostapd_acbss_stats_inc(pstBss, ulRecvApVapCreateAck);
		break;
	case EV_HOSTAPD_VAP_DESTROY:
		hostapd_acbss_stats_inc(pstBss, ulRecvApVapDestroyAck);
		break;
	case EV_HOSTAPD_VAP_START:
		hostapd_acbss_stats_inc(pstBss, ulRecvApVapStartAck);
		eloop_cancel_timeout(VapStartTimeout, pstBss, (void *)dwMsgId);
		break;
	case EV_HOSTAPD_VAP_STOP:
		hostapd_acbss_stats_inc(pstBss, ulRecvApVapStopAck);
		break;
	case EV_HOSTAPD_SOCKET_IOCTL:
		hostapd_acbss_stats_inc(pstBss, ulRecvApIoctlAck);
		break;
	case EV_HOSTAPD_SOCKET_EAPOL:
		hostapd_acbss_stats_inc(pstBss, ulRecvApEapolAck);
		break;
	case EV_HOSTAPD_SOCKET_PREAUTH:
		hostapd_acbss_stats_inc(pstBss, ulRecvApPreauthAck);
		break;
	default:
		hostapd_acbss_stats_inc(pstBss, ulRecvApOtherAck);
		break;
	}
		
	return TRUE;
}


static BOOL OnVapUpdate(BYTE * pbyBody, WORD16 wLen)
{
	AC_DEVM_VAP_CONFIG_T * pstVapCfg = NULL ;
	u16 wWtpId = 0 ;
	u32 ulInterfaceId = 0, ulVapId = 0 ;
	struct hostapd_data * pstBss = NULL ;

	if((pstVapCfg = (AC_DEVM_VAP_CONFIG_T *)pbyBody) == NULL
		|| wLen < sizeof(AC_DEVM_VAP_CONFIG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, or wLen(%u) is wrong(%u).\n", __func__, wLen, sizeof(AC_DEVM_VAP_CONFIG_T)) ;
		return FALSE ;
	}

	wWtpId = pstVapCfg->stVapId.ulWtpId ;
	ulInterfaceId = pstVapCfg->stVapId.ulIfId ;
	ulVapId = pstVapCfg->stVapId.ulVapId ;

	if((pstBss = FindVap(wWtpId, ulInterfaceId, ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, not exist vap(%u/%u/%u).\n", __func__, wWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	/*停止VAP运作，使配置数据无效*/
	if(pstBss->setuped)
		hostapd_cleanup(pstBss) ;

	if(! VapLoadConfig(NULL, (AC_DEVM_VAP_CONFIG_T *)pbyBody)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, load vap(%u/%u/%u) config failed.\n", __func__, wWtpId, ulInterfaceId, ulVapId) ;
		return FALSE ;
	}

	/*if(pstBss->setuped){*/
	if(pstBss->state == AC_OPSTATE_NORMAL){
		hostapd_acbss_stats_inc(pstBss, ulVapStartCfgUpdate);
		
		pstBss->timeout_vapstart=1;
		if(! VapStart(wWtpId, ulInterfaceId, ulVapId)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, restart vap(%u/%u/%u) failed.\n", __func__, wWtpId, ulInterfaceId, ulVapId) ;
			return FALSE ;
		}
		else
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, restart vap(%u/%u/%u) success.\n", __func__, wWtpId, ulInterfaceId, ulVapId) ;
	}

	return TRUE ;
}

/*WTP状态响应函数*/
static BOOL OnWtpOpState(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T *pstWtpOpstate)
{
	struct hapd_interfaces * pstWtp = NULL ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
		"%s, change opstate of wtp(%u) to state(%s), due to reason %u.\n",
		__func__, pstWtpOpstate->stWtpId.ulWtpId, pstWtpOpstate->ulOpState == AC_OPSTATE_NORMAL ? "normal" : "fault", pstWtpOpstate->ulReason) ;

	if((pstWtp = FindWtp(pstWtpOpstate->stWtpId.ulWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, cannot find wtp %u.\n", __func__, pstWtpOpstate->stWtpId.ulWtpId) ;
		return FALSE ;
	}

	pstWtp->state = pstWtpOpstate->ulOpState ;

	switch(pstWtpOpstate->ulOpState){
	case AC_OPSTATE_NORMAL :{
		TPID tReceiver ;
		/* BOOL bRet = FALSE ; */
		long i , j ;

		/*发送WTP INIT消息至WTP侧：使删除WTP侧VAP数据*/
		VmSelfPid(& tReceiver) ;
		tReceiver.wWtpId = pstWtpOpstate->stWtpId.ulWtpId;

	  	if(! VmASend(EV_HOSTAPD_WTP_INIT, NULL, 0, tReceiver)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, nofity wtp(%u) failed.\n", __func__, pstWtpOpstate->stWtpId.ulWtpId) ;
			return FALSE ;
		}

		/*清除本地标志*/
		for(i = 0 ; i < MAX_INTERFACES ; i ++){
			if(! pstWtp->iface[i])
				continue ;

			for(j = 0 ; j < MAX_BSSES ; j ++){
				if(! pstWtp->iface[i]->bss[j])
					continue ;

				pstWtp->iface[i]->bss[j]->wtp_vap_added = 0 ;
			}
		}
		break ;
	}
	case AC_OPSTATE_FAULT :{
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, unknown optate(%u).\n", __func__, pstWtpOpstate->ulOpState) ;
		break ;
	}

	return TRUE ;
}

/*从设备状态更新响应函数*/
static BOOL OnSlaveWtpOpState(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T *pstSlaveWtpOpstate)
{
	struct hapd_interfaces * pstWtp = NULL ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, change opstate of slave wtp(%u) to state(%s), due to reason %u.\n",
		__func__, pstSlaveWtpOpstate->stWtpId.ulWtpId, pstSlaveWtpOpstate->ulOpState == AC_OPSTATE_NORMAL ? "normal" : "fault", pstSlaveWtpOpstate->ulReason) ;

	if((pstWtp = FindWtp(pstSlaveWtpOpstate->stWtpId.ulWtpId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, cannot find wtp %u.\n", __func__, pstSlaveWtpOpstate->stWtpId.ulWtpId) ;
		return FALSE ;
	}

	switch(pstSlaveWtpOpstate->ulOpState){
	case AC_OPSTATE_NORMAL :{
		TPID tReceiver ;
		/* BOOL bRet = FALSE ; */
		long i , j ;

		/*发送WTP INIT消息至WTP侧：使删除WTP侧VAP数据*/
		VmSelfPid(& tReceiver) ;
		tReceiver.wWtpId = pstSlaveWtpOpstate->stWtpId.ulWtpId;

	  	if(! VmASend(EV_HOSTAPD_WTP_SLAVE_INIT, NULL, 0, tReceiver)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, nofity slave wtp(%u) failed.\n", __func__, pstSlaveWtpOpstate->stWtpId.ulWtpId) ;
			return FALSE ;
		}

		/*清除从设备上的VAP的本地标志*/
		for(i = 0 ; i < MAX_INTERFACES ; i ++){
			if(! pstWtp->iface[i] || VmIsIfMaster(pstWtp->iface[i]->interface_id))
				continue ;

			for(j = 0 ; j < MAX_BSSES ; j ++){
				if(! pstWtp->iface[i]->bss[j])
					continue ;

				pstWtp->iface[i]->bss[j]->wtp_vap_added = 0 ;
			}
		}
		break ;
	}
	case AC_OPSTATE_FAULT :{
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, unknown optate(%u).\n", __func__, pstSlaveWtpOpstate->ulOpState) ;
		break ;
	}
	
	return TRUE ;
}

/*VAP状态响应函数*/
static BOOL OnVapOpState(BYTE * pbyBody, WORD16 wLen)
{
	AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T * pstVapOpstate = NULL ;
	struct hostapd_data * pstBss = NULL ;

	if((pstVapOpstate = (AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T *)pbyBody) == NULL
		|| wLen < sizeof(AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
		return FALSE ;
	}

	if((pstBss = FindVap(pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, cannot find vap(%u/%u/%u).\n", __func__, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;
		return FALSE ;
	}

	if(pstVapOpstate->ulReason == AC_VAPSTATE_REASON_ADMIN)
		return TRUE ;

	pstBss->state = pstVapOpstate->ulOpState ;

	if(pstBss->state == AC_OPSTATE_NORMAL
		&& pstBss->iface->pstWtp->state != AC_OPSTATE_NORMAL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(%u/%u/%u) is normal, but the wtp is not normal.\n",
			__func__, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;
	}

	switch(pstVapOpstate->ulOpState){
	case AC_OPSTATE_NORMAL :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, receive event: vap(%u/%u/%u) opstate normal.\n", __func__, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;
		hostapd_acbss_stats_inc(pstBss, ulVapStartLinkNormal);

		pstBss->timeout_vapstart=1;
		if(! VapStart(pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call VapStart failed.\n", __func__, wLen) ;
			return FALSE ;
		}
		break ;
	case AC_OPSTATE_FAULT :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, receive event: vap(%u/%u/%u) opstate fault.\n", __func__, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;

		eloop_cancel_timeout(VapStartTimeout, pstBss, ELOOP_ALL_CTX);
		hostapd_free_stas(pstBss) ;
/*
		if(! VapStop(pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call VapStop failed.\n", __func__, wLen) ;
			return FALSE ;
		}
*/
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, unknown optate(%u).\n", __func__, pstVapOpstate->ulOpState) ;
		return FALSE ;
	}

	return TRUE ;
}

/*本地另一线程接收数据包响应*/
static BOOL OnRadius(BYTE * pbyBody, WORD16 wLen)
{
#define HOSTAPD_INVALID_ID 	0xffffffff
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE * pElem = NULL ;
	long lLength = 0, auth_id = -1 , acct_id = -1 ;
	void * eloop_ctx = NULL, * user_ctx = NULL ;
	BYTE * pRadiusData = NULL ;
	WORD32 dwRadiusDataLen = 0, dwType = RADIUS_TYPE_MAX, dwWtpId = HOSTAPD_INVALID_ID, dwIfId = HOSTAPD_INVALID_ID, dwVapId = HOSTAPD_INVALID_ID, dwSetId = RADIUS_CLIENT_SET_SIZE, dwPoolId = RADIUS_CLIENT_MAX ;
	struct hostapd_data * hapd = NULL ;

	if(pbyBody == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	pElem = pbyBody ;
	lLength = wLen ;

	while(lLength > 0 && lLength <= wLen){
		pstHostapdElem = (HOSTAPD_ELEM_T *)pElem ;

		if(pstHostapdElem->dwLength < sizeof(HOSTAPD_ELEM_T)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, unknown dwElemId: %u, invalid length: %u.\n", 
				__func__, pstHostapdElem->dwElemId, pstHostapdElem->dwLength) ;
			break ;
		}

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_RADIUSTYPE:
			dwType = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwType) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, dwType len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwType = RADIUS_TYPE_MAX ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_RADIUSSETID:
			dwSetId = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwPoolId) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, dwPoolId len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwSetId = RADIUS_CLIENT_SET_SIZE ;
			}
			break;
		case HOSTAPD_ELEMID_COMMON_RADIUSPOOLID:
			dwPoolId = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwPoolId) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, dwPoolId len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwPoolId = RADIUS_CLIENT_MAX ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_WTPID :
			dwWtpId = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwWtpId) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, wtpid len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwWtpId = HOSTAPD_INVALID_ID ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_IFID :
			dwIfId = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwIfId) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, ifid len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwIfId = HOSTAPD_INVALID_ID ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_VAPID :
			dwVapId = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(dwVapId) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, vapid len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				dwVapId = HOSTAPD_INVALID_ID ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_AUTHID :
			auth_id = * ((long *)(pstHostapdElem + 1)) ;
			if(sizeof(auth_id) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, auth_id len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				auth_id = -1 ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_ACCTID :
			acct_id = * ((long *)(pstHostapdElem + 1)) ;
			if(sizeof(acct_id) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, acct_id len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				acct_id = -1 ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_ELOOP :
			eloop_ctx = (void *)(* (unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(eloop_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, eloop len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				eloop_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_USER :
			user_ctx = (void *)(*(unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(user_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, user len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				user_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_DATA :
			pRadiusData = (BYTE *)(pstHostapdElem + 1) ;
			dwRadiusDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			break ;
		}
		
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0
		|| eloop_ctx == NULL
		|| pRadiusData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct, or point is NULL.\n", __func__, lLength) ;
		return FALSE ;
	}

	switch(dwType){
	case RADIUS_TYPE_FOR_VAP:
		if((hapd = FindVap(dwWtpId, dwIfId, dwVapId)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, vap(%u/%u/%u) has been delete.\n", __func__, dwWtpId, dwIfId, dwVapId) ;
			return TRUE ;
		}

		if(hapd->radius != eloop_ctx){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, vap(%u/%u/%u) has been realloced.\n", __func__, dwWtpId, dwIfId, dwVapId) ;
			return TRUE ;
		}
		
		break ;
	case RADIUS_TYPE_FOR_ALIVE:{
		struct radius_client_data * radius = NULL ;

		if((radius = radius_alive_client_find(auth_id, acct_id)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, radius_alive(auth_id: %d, acct_id: %d) has been delete.\n", 
				__func__, auth_id, acct_id) ;
			return TRUE ;
		}

		if(radius != eloop_ctx){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, radius_alive(auth_id: %d, acct_id: %d) has been realloced.\n", __func__, auth_id, acct_id) ;
			return TRUE ;
		}
		
		break ;
	}
	case RADIUS_TYPE_FOR_PPP:{
		struct radius_client_data * radius = NULL;

		if((radius = (struct radius_client_data *)hostapd_radius_ppp_get(dwSetId)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, can not find the radius client(%u).\n", __func__, dwSetId) ;
			return FALSE;
		}
		
		if(radius != eloop_ctx){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, radius_ppp has been realloced.\n", __func__) ;
			return TRUE ;
		}
		break ;
	}
	case RADIUS_TYPE_FOR_POOL:{
		struct radius_client_data * radius = NULL ;
		
		if(dwPoolId >= RADIUS_CLIENT_MAX ||
			(radius = radius_client_pool_get(dwSetId, dwPoolId)) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, invalid dwPoolId: %u, or can not find the radius client(%u).\n", __func__, dwPoolId, dwSetId) ;
			return FALSE ;
		}

		if(radius != eloop_ctx){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, radius client(%u) has been realloced.\n", __func__, dwPoolId) ;
			return TRUE ;
		}
		
		break ;
	}
	default:
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, unknown type(%d).\n", __func__, dwType) ;
		return FALSE ;
	}

	radius_client_receiveA(eloop_ctx, user_ctx, pRadiusData, dwRadiusDataLen) ;

	return TRUE ;
#undef HOSTAPD_INVALID_ID
}

int OnHostapdGetStat(BYTE * pbyBody, WORD16 wLen)
{
	TPID stTpidReq = {0};
	AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T *req = NULL;
	AC_OMA_GET_AC_DYNAINFO_RSP_MSG_T rsp = {0};
	AC_OMA_HOSTAPDSTAT_T * stat = NULL;
	
	if((req = (AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T *)pbyBody) == NULL
		|| wLen < sizeof(AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL, or wLen(%d) is too short.\n", __func__, wLen) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
		"%s, report hostapd stat:\n"
		"\tInAcRoamingSuccTimes: %d.\n"
		"\tAcRoamingIn: %d.\n"
		"\tAcRoamingOut: %d.\n"
		"\tRadiusAuthReq: %d.\n"
		"\tRadiusAuthReqFailed: %d.\n"
		"\tRadiusAuthSucc: %d.\n"
              "\tRadiusAuthReject: %d.\n",
		__func__, g_stStats.ulInterAcRoaming, g_stStats.ulExterAcRoamingIn, g_stStats.ulExterAcRoaningOut,
		g_stStats.ulRadiusAuthReq, g_stStats.ulRadiusAuthReqFailed , g_stStats.ulRadiusAuthSucc, g_stStats.ulRadiusAuthReject);

	rsp.ulMsgType = req->ulMsgType;
	rsp.ulSn = req->ulSn;

	stat = (AC_OMA_HOSTAPDSTAT_T *)rsp.aucRsp;
	stat->ulInAcRoamingSuccTimes = HTONL(g_stStats.ulInterAcRoaming);
	stat->ulAcRoamingIn = HTONL(g_stStats.ulExterAcRoamingIn);
	stat->ulAcRoamingOut = HTONL(g_stStats.ulExterAcRoaningOut);
	stat->ulRadiusAuthReq = HTONL(g_stStats.ulRadiusAuthReq);
	stat->ulRadiusAuthResp = HTONL(g_stStats.ulRadiusAuthSucc+g_stStats.ulRadiusAuthReject);           /* 2011.4.6 , chary*/
	stat->ulRadiusAuthReq2 = HTONL(g_stStats.ulRadiusAuthReq);                                                   /* 2011.4.6 , chary*/
	stat->ulRadiusAuthSucc = HTONL(g_stStats.ulRadiusAuthSucc);
       stat->ulRadiusAuthReject = HTONL(g_stStats.ulRadiusAuthReject);                                            /* 2011.4.6 , chary*/
	stat->ulRadiusAuthReqFailed = HTONL(g_stStats.ulRadiusAuthReqFailed);                                   /* 2011.4.6 , chary*/
	

	rsp.ulFinish = HTONL(1);
	rsp.ulRet = HTONL(0);

	VmSender(& stTpidReq);
	if(TRUE != VmASend(EV_AC_OMA_GET_AC_ROAMINGSTAT_RSP_MSG, (BYTE *)&rsp, (unsigned long)(&stat[1]) - (unsigned long)(&rsp), stTpidReq)) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, send hostapd stat msg failed.\n", __func__);
		return FALSE;
	}
	
	return TRUE;
}

int hostapd_report_event(void * pObj, int type, u_int32_t ulEventId, u_int32_t ulReasonId, void * pstExt)
{
	AC_OMA_EVENT_INFO_T event = {0} ;
	AC_OMA_MO_T moid = {0} ;
	u_int32_t len ;
		
	if(pObj == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}
	
	switch(type){
	case 1 :{
		struct hostapd_data * hapd = (struct hostapd_data *)pObj ;
		AC_DEVM_GET_VAP_MOID_REQ_T vap_id = {0} ;
		AC_DEVM_GET_VAP_MOID_RSP_T vap_rsp = {0} ;
		
		vap_id.ulWtpId = hapd->iface->pstWtp->usWtpId ;
		vap_id.ulIfId = hapd->iface->interface_id ;
		vap_id.ulVapId = hapd->vap_id ;
		
		ac_db_access(AC_DEVM_GET_VAP_MOID_MSG, (UINT8 *)& vap_id, sizeof(vap_id), (UINT8 *)& vap_rsp, & len) ;
		if(vap_rsp.ulRet == AC_OK)
			os_memcpy(& moid, & vap_rsp.stVapMoid, sizeof(AC_OMA_MO_T)) ;
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
				"%s, get vap moid failed.\n", __func__) ;
			return -3 ;
		}
		break ;
	}
	case 2 :{
		break ;
	}
	case 3 :{
		break ;
	}
	case 4 :{
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, invalid object type(%d).\n", __func__, type) ;
		return -2 ;
	}

	event.ulEventId = ulEventId ;
	event.ulEventReasonId = ulReasonId ;
	event.ulMOC = moid.ulMOC ;
	os_memcpy(event.aucMOI, moid.aucMOI, AC_MOI_LEN) ;
	if(pstExt)
		os_memcpy(& event.unEventExtInfo, pstExt, sizeof(AC_OMA_EVENT_EXT_INFO_U)) ;
	
	return ac_oma_report_event(& event) == AC_OK ? 0 : -4 ;
}


/*
功能：判断VAP/MAC是否需要PORTAL认证；
返回：
	1：需要PORTAL认证；
	0：不需要PORTAL认证；
*/
int hostapd_portal_auth(struct hostapd_data * hapd, u8 * mac)
{
	AC_USRM_GET_USERPORTALSWITCH_REQ_T req = {{0}} ;
	AC_USRM_GET_USERPORTALSWITCH_RSP_T resp = {0} ;
	UINT32 ulLength = 0 ;

	if(hapd == NULL ||
		mac == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return 0 ;
	}

	req.stVapId.ulWtpId = hapd->iface->pstWtp->usWtpId ;
	req.stVapId.ulVDevId = hapd->iface->gdev_id ;
	req.stVapId.ulIfId = hapd->iface->interface_id ;
	req.stVapId.ulVapId = hapd->vap_id ;
	memcpy(req.aucMac, mac, 6) ;

	ac_db_access(AC_USRM_GET_USERPORTALSWITCH_MSG, (UINT8 *)& req, sizeof(req), (UINT8 *)& resp, & ulLength) ;
	if(resp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, sta(%d/%d/%d/"MACSTR") get portal swtich failed.\n", 
			__func__, req.stVapId.ulWtpId, req.stVapId.ulIfId, req.stVapId.ulVapId, MAC2STR(req.aucMac)) ;
		return 0 ;
	}
		
	return resp.ulPortalSwitch == AC_PORTAL_SWITCH_ENABLE ? 1 : 0 ;
}


/*
功能：判断终端是否已通过PORTAL认证；
返回：
	1：已通过PORTAL认证；
	0：未通过PORTAL认证；
*/
int hostapd_sta_portal_authorized(struct hostapd_data * hapd, u8 * mac)
{
	AC_USRM_GET_USERPORTALSTATE_REQ_T req = {{0}} ;
	AC_USRM_GET_USERPORTALSTATE_RSP_T resp = {0} ;
	UINT32 ulLength = 0 ;

	if(hapd == NULL ||
		mac == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return 0 ;
	}

	memcpy(req.aucMac, mac, 6) ;
	
	ac_db_access(AC_USRM_GET_USERPORTALSTATE_MSG, (UINT8 *)& req, sizeof(req), (UINT8 *)& resp, & ulLength) ;
	if(resp.ulRet != AC_OK){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, sta(%d/%d/%d/"MACSTR") get portal state failed.\n", 
			__func__, hapd->iface->pstWtp->usWtpId, hapd->iface->interface_id, hapd->vap_id, MAC2STR(req.aucMac)) ;
		return 0 ;
	}
	
	return resp.ulPortalState == AC_PORTAL_STATE_FINISH ? 1 : 0 ;
}


static void DumpDevices(VOID)
{
	char message[1024] = {0} ;
	unsigned long i, j, k ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,	"Devices:\n") ;
	for(i = 0 ; i < MAX_WTPS ; i ++){
		struct hapd_interfaces * pstWtp = g_pstWtpTable[i] ;

		if(pstWtp == NULL)
			continue ;

		os_memset(message, 0, sizeof(message)) ;
		os_snprintf(message, sizeof(message), 
			"WTP %lu: %u.\n", i, pstWtp->usWtpId) ;
		for(j = 0 ; j < MAX_INTERFACES ; j ++){
			struct hostapd_iface * pstIf = pstWtp->iface[j] ;

			if(pstIf == NULL)
				continue ;

			os_snprintf(message+os_strlen(message), sizeof(message)-os_strlen(message),
				"--IF %lu(%u): %u.\n", j, pstIf->interface_index, pstIf->interface_id) ;
			for(k = 0 ; k < MAX_BSSES ; k ++){
				struct hostapd_data * pstVap = pstIf->bss[k] ;

				if(pstVap == NULL)
					continue ;

				os_snprintf(message+os_strlen(message), sizeof(message)-os_strlen(message), 
					"----VAP %lu(%u): %u.\n", k, pstVap->vap_index, pstVap->vap_id) ;
			}
		}

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,	"%s",message) ;
	}
}

void ProcEntryHostapdAc(WORD16 wEvent,
						BYTE *pbyBody,
						WORD16 wLen,
						BYTE *pbyResv,
						WORD16 wResv,
						BYTE *pbyProcData)
{
	TPID	stPid;
    /* u16 usWtpId ; */
	
	switch(VmProcState()){
	case AC_PROC_IDLE :
		switch(wEvent){
		case EV_MASTER_POWERON :/*初始化：获取所有设备配置信息，存储处理*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): EV_MASTER_POWERON.\n", __func__, wEvent) ;

			if(! OnMasterPowerOn()){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, power on failed.\n", __func__) ;
				VmPowerOnAck(FALSE) ;
			}
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, power on success.\n", __func__) ;
				VmProcUpdateState(AC_PROC_WORK);
				VmPowerOnAck(TRUE) ;
			}
			DumpDevices() ;

			HostapdTest() ;

			return ;
		default :
			break ;
		}
		break ;
	case AC_PROC_WORK :
		switch(wEvent){
		case AC_DEVM_RADIUS_CONFIG_UPDATE_IND_MSG :{
			AC_DEVM_RADIUS_SERVERS_T * pstRadius = NULL ;
			
			if((pstRadius = (AC_DEVM_RADIUS_SERVERS_T *)pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_RADIUS_SERVERS_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): update radius .\n", __func__, wEvent) ;

			if(! SetRadiusServers(pstRadius)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call SetRadiusServers failed.\n", __func__) ;
			}
				
			return ;
		}
		case AC_DEVM_WTP_ADD_IND_MSG :{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_WTP_ADD_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): add wtp(%u).\n", __func__, wEvent, ((AC_DEVM_WTP_ADD_IND_MSG_T *)pbyBody)->stWtpBasic.stWtpId.ulWtpId) ;

			if(! WtpAdd((AC_DEVM_WTP_ADD_IND_MSG_T *)pbyBody)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call WtpAdd failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_WTP_DEL_IND_MSG :{
			AC_DEVM_WTP_DEL_IND_MSG_T * pstWtpDelCfg = NULL ;

			if((pstWtpDelCfg = (AC_DEVM_WTP_DEL_IND_MSG_T *)pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_WTP_DEL_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): del wtp(%u).\n", __func__, wEvent, pstWtpDelCfg->ulWtpId) ;

			if(! WtpDelete(pstWtpDelCfg->ulWtpId)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call WtpDelete failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_WTP_UPDATE_IND_MSG :
			break ;
		case AC_DEVM_WTP_OPSTATE_CHG_IND_MSG  :{
			AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T * pstWtpOpstate = NULL ;

			if((pstWtpOpstate = (AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T *)pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): change opstate of wtp.\n", __func__, wEvent) ;

			if(! OnWtpOpState(pstWtpOpstate)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnWtpOpstate failed.\n", __func__) ;
			}

			break ;
		}
		case AC_DEVM_WTP_MATE_OPSTATE_CHG_IND_MSG :{
			AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T * pstSlaveWtpOpstate = NULL ;

			if((pstSlaveWtpOpstate = (AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T *)pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): change opstate of slave wtp.\n", __func__, wEvent) ;

			if(! OnSlaveWtpOpState(pstSlaveWtpOpstate)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnSlaveWtpOpState failed.\n", __func__) ;
			}
			break ;
		}
		case AC_DEVM_IF_ADD_IND_MSG :{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_IF_ADD_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, or wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): add interface(%u/%u).\n", __func__, wEvent, ((AC_DEVM_IF_ADD_IND_MSG_T *)pbyBody)->stIfId.ulWtpId, ((AC_DEVM_IF_ADD_IND_MSG_T *)pbyBody)->stIfId.ulIfId) ;

			if(! InterfaceAdd((AC_DEVM_IF_ADD_IND_MSG_T *)pbyBody)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call InterfaceAdd failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_IF_DEL_IND_MSG :{
			AC_DEVM_IF_DEL_IND_MSG_T * pstIfDelCfg = NULL ;

			if((pstIfDelCfg = (AC_DEVM_IF_DEL_IND_MSG_T * )pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_IF_DEL_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): del interface(%u/%u).\n", __func__, wEvent, pstIfDelCfg->ulWtpId, pstIfDelCfg->ulIfId) ;

			if(! InterfaceDelete(pstIfDelCfg->ulWtpId, pstIfDelCfg->ulIfId)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call InterfaceDelete failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_IF_UPDATE_IND_MSG	 :
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_IF_UPDATE_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): update interface(%u/%u).\n", __func__, wEvent, ((AC_DEVM_IF_ADD_IND_MSG_T *)pbyBody)->stIfId.ulWtpId, ((AC_DEVM_IF_ADD_IND_MSG_T *)pbyBody)->stIfId.ulIfId) ;

			/*
			if(! InterfaceLoadConfig(NULL, (AC_DEVM_IF_UPDATE_IND_MSG_T *)pbyBody)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call InteraceLoadConfig failed.\n", __func__) ;
			}
			*/
			return ;
		case AC_DEVM_VAP_ADD_IND_MSG :{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): add vap(%u/%u/%u).\n", __func__, wEvent, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulWtpId, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulIfId, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulVapId) ;

			if(! VapAdd((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call VapAdd failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_VAP_DEL_IND_MSG :{
			AC_DEVM_VAP_DEL_IND_MSG_T * pstVapDelCfg = NULL ;

			if((pstVapDelCfg = (AC_DEVM_VAP_DEL_IND_MSG_T * )pbyBody) == NULL
				|| wLen < sizeof(AC_DEVM_VAP_DEL_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): delete vap(%u/%u/%u).\n", __func__, wEvent, pstVapDelCfg->ulWtpId, pstVapDelCfg->ulIfId, pstVapDelCfg->ulVapId) ;

			if(! VapDelete(pstVapDelCfg->ulWtpId, pstVapDelCfg->ulIfId, pstVapDelCfg->ulVapId)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call VapDelete failed.\n", __func__) ;
			}
			DumpDevices() ;

			return ;
		}
		case AC_DEVM_VAP_UPDATE_IND_MSG :{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_VAP_UPDATE_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): update vap(%u/%u/%u).\n", __func__, wEvent, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulWtpId, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulIfId, ((AC_DEVM_VAP_ADD_IND_MSG_T *)pbyBody)->stVapId.ulVapId) ;

			if(! OnVapUpdate(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call VapLoadConfig failed.\n", __func__) ;
			}
			return ;
		}
		case AC_DEVM_VAP_BSSID_CHG_IND_MSG:{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_VAP_MAC_CHG_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): update mac of vap.\n", __func__, wEvent) ;

			if(! VapLoadMac((AC_DEVM_VAP_MAC_CHG_IND_MSG_T *)pbyBody)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call VapLoadMac failed.\n", __func__) ;
			}
			return ;
		}
		case AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG :
			break ;
		case AC_DEVM_VAP_OPSTATE_CHG_IND_MSG :{
			if(pbyBody == NULL
				|| wLen < sizeof(AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, point is NULL, wLen(%u) is too short.\n", __func__, wLen) ;
				return ;
			}

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive event(%u): change opstate of vap.\n", __func__, wEvent) ;

			if(! OnVapOpState(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnVapOpState failed.\n", __func__) ;
			}
#if 0
			if(pstVapOpstate->ulReason == AC_VAPSTATE_REASON_ADMIN)
				return ;

			switch(pstVapOpstate->ulOpState){
			case AC_OPSTATE_NORMAL :
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, receive event(%u): vap(%u/%u/%u) opstate normal.\n", __func__, wEvent, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;

				if(! VapStart(pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId)){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
						"%s, call VapStart failed.\n", __func__, wLen) ;
				}
				break ;
			case AC_OPSTATE_FAULT :
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, receive event(%u): vap(%u/%u/%u) opstate fault.\n", __func__, wEvent, pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId) ;

				if(! VapStop(pstVapOpstate->stVapId.ulWtpId, pstVapOpstate->stVapId.ulIfId, pstVapOpstate->stVapId.ulVapId)){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
						"%s, call VapStop failed.\n", __func__, wLen) ;
				}
				break ;
			default :
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, unknown optate(%u).\n", __func__, pstVapOpstate->ulOpState) ;
				break ;
			}
#endif
			return ;
		}

		case AC_USRM_EAPUSEROFFLINE_REQ_MSG:{
			if((NULL == pbyBody) ||(wLen < sizeof(AC_USRM_EAPUSEROFFLINE_REQ_MSG_T)))
				{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the msg we received is valid. \n", __func__);
					return ;
				}
			
			eap_user_force_down((AC_USRM_EAPUSEROFFLINE_REQ_MSG_T *)pbyBody, wLen);
			return;
		}
		case EV_HOSTAPD_SOCKET_IOCTL :{
			TPID stTpid ;

			VmSender(& stTpid) ;
			if(! OnIoctl(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnIoctl failed.\n", __func__) ;
			}
			return ;
		}
		case EV_HOSTAPD_SOCKET_EVENT :{
			TPID stTpid ;

			VmSender(& stTpid) ;
			if(! OnEvent(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnEvent failed.\n", __func__) ;
			}
			return ;
		}
		case EV_HOSTAPD_SOCKET_EAPOL :{
			TPID stTpid ;

			VmSender(& stTpid) ;
			if(! OnEapol(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnEapol failed.\n", __func__) ;
			}
			return ;
		}
		case EV_HOSTAPD_SOCKET_PREAUTH :{
			TPID stTpid ;

			VmSender(& stTpid) ;
			if(! OnPreauth(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnPreauth failed.\n", __func__) ;
			}
			return ;
		}
		case EV_HOSTAPD_VAP_CREATE_NACK:{
			TPID stTpid;

			VmSender(&stTpid);
			if(! OnCreateVapNack(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnCreateVapNack failed.\n", __func__) ;
			}
			return ;
		}
		case EV_HOSTAPD_MSG_ACK:{
			TPID stTpid;
			
			VmSender(&stTpid);
			if(!OnMsgAck(stTpid.wWtpId, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnMsgAck failed.\n", __func__) ;
			}
			return;
		}
		case EV_HOSTAPD_TIMER :
		case EV_TIMER_HOSTAPD :
			if(OnHostapdTimer(wEvent, pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, call OnHostapdTimer failed.\n", __func__) ;
			}

			return ;
		case EV_HOSTAPD_SOCKET_RADIUS :
			if(! OnRadius(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, call OnRadius failed.\n", __func__) ;
			}
			break ;
		case AC_DEVM_AUTHSERVERS_ADD_IND_MSG:
			if(!OnRadiusAdd(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, call OnRadiusAdd failed.\n", __func__) ;
			}
			break;
		case AC_DEVM_AUTHSERVERS_DEL_IND_MSG:
			if(!OnRadiusDel(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
					"%s, call OnRadiusDel failed.\n", __func__) ;
			}
			break;
		case AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG:
			if(!OnRadiusUpdate(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call OnRadiusUpdate failed.\n", __func__) ;
			}
			break;
		case AC_USRM_NASIP_UPDATE_IND_MSG:
			if(OnNasIpUpdate(pbyBody, wLen) != TRUE){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, OnNasIpUpdate failed.\n", __func__);
			}
			break;
			
		/*   AP流控，chary，2011-11-8   */
		case AC_USRM_USER_ADD_IND_MSG:
			if(!OnAddUser(pbyBody, wLen))
				{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
									"%s, OnAddUser failed, user QOS failed. \n", __func__);
				}
			break;
		/**********************************/
		
		case EV_AC_PA_HOSTAPD_AUTH_REQ_MSG:
			hostapd_radius_ppp_req(pbyBody, wLen) ;
			break ;
#if 0
		case EV_AC_PA_HOSTAPD_AUTH_OVER_NTF_MSG:
			hostapd_radius_portal_logon(pbyBody, wLen) ;
			break ;
		case EV_AC_PA_HOSTAPD_LOGOUT_NTF_MSG:
			hostapd_radius_portal_logoff(pbyBody, wLen) ;
			break ;
#endif			
		case EV_AC_OMA_GET_AC_ROAMINGSTAT_REQ_MSG:
			OnHostapdGetStat(pbyBody, wLen);
			break;
		/* 2008-10-31 pyy add: 增加线程保活报文处理*/
		case EV_PROC_ECHO_REQ:
			VmSender(&stPid);
			VmASend(EV_PROC_ECHO_RSP, NULL, 0, stPid);
			print_stats_all();
			break;
		
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
				"%s, unknonw event(%u)\n", __func__, wEvent) ;
			break ;
		}
		break ;
	default :
		break ;
	}

	return ;
}

void ProcEntryHostapdAcDaemon(WORD16 wEvent,
						BYTE *pbyBody,
						WORD16 wLen,
						BYTE *pbyResv,
						WORD16 wResv,
						BYTE *pbyProcData)
{
	switch(wEvent){
	case EV_MASTER_POWERON :
		VmProcUpdateState(AC_PROC_WORK);
		VmPowerOnAck(TRUE) ;
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, unknonw event(%u)\n", __func__, wEvent) ;
		return ;
	}

	if (eloop_init(NULL)) {
		wpa_printf(MSG_ERROR, "Failed to initialize event loop") ;
		return ;
	}

	eloop_run();

	eloop_destroy();

	return ;
}
