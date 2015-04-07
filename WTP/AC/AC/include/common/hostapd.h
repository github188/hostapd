/*
 * hostapd / Initialization and configuration
 * Host AP kernel driver
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

#ifndef HOSTAPD_H
#define HOSTAPD_H

#include "hostapd_ac_stats.h"

#ifndef ETH_P_PAE
#define ETH_P_PAE 0x888E /* Port Access Entity (IEEE 802.1X) */
#endif /* ETH_P_PAE */

#ifndef BIT
#define BIT(x) (1 << (x))
#endif

/*begin TASK #476 fangz 2013.2.25 log*/
#ifndef MAC2STR
#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#undef MACSTR
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"
#endif
/*end TASK #476 fangz 2013.2.25 log*/

/*begin TASK #476 fangz 2013.2.25 log*/
#ifndef MAC_FMT
#define MAC_FMT "%02X%02X-%02X%02X-%02X%02X"
#define MAC_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], \
     ((UINT8*)(x))[3], ((UINT8*)(x))[4], ((UINT8*)(x))[5]
#endif
/*end TASK #476 fangz 2013.2.25 log*/


#ifndef IP2STR
#define IP2STR(a)	(a)[0], (a)[1], (a)[2], (a)[3]
#define IPSTR 		"%u.%u.%u.%u"
#endif

#ifndef IEEE80211_WEP_NKID
#define IEEE80211_WEP_NKID 4
#endif

#ifndef WPA_KEY_RSC_LEN
#define WPA_KEY_RSC_LEN 8
#endif

#include "config.h"

/* 2010-1-12 pyy 修改 */
/*add by fangz 2013.11.25 for powerac segment fault*/
#define MAX_EXPNUM        4096
#define MAX_WTPS		MAX_EXPNUM


#define MAX_INTERFACES	4
#define MAX_BSSES		16

/* The first and the last (range) */
#ifndef SIOCIWFIRST
#define SIOCIWFIRST	0x8B00
#endif

#ifndef SIOCIWLAST	
#define SIOCIWLAST	0x8BFF		/* 0x8BFF */
#endif

#define RADIUS_CLIENT_SET_SIZE		AC_DEVM_AUTHSERVERS_NUM_MAX

/*IOCTL状态数目*/
#define IOCTL_STATE_BEGIN		SIOCIWFIRST
#define IOCTL_STATE_END		    SIOCIWLAST
#define IOCTL_STATES			(IOCTL_STATE_END-IOCTL_STATE_BEGIN+1)
#define IOCTL_STATE_BYTES		((IOCTL_STATES+7) >> 3)

#define PROFILE_HOSTAPD	"hostapd.conf"

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif /* _MSC_VER */

#define MAX_VLAN_ID 4094

struct ieee8023_hdr {
	u8 dest[6];
	u8 src[6];
	u16 ethertype;
} STRUCT_PACKED;


struct ieee80211_hdr {
	u16 frame_control;
	u16 duration_id;
	u8 addr1[6];
	u8 addr2[6];
	u8 addr3[6];
	u16 seq_ctrl;
	/* followed by 'u8 addr4[6];' if ToDS and FromDS is set in data frame
	 */
} STRUCT_PACKED;

#ifdef _MSC_VER
#pragma pack(pop)
#endif /* _MSC_VER */

#define IEEE80211_DA_FROMDS addr1
#define IEEE80211_BSSID_FROMDS addr2
#define IEEE80211_SA_FROMDS addr3

#define IEEE80211_HDRLEN (sizeof(struct ieee80211_hdr))

#define IEEE80211_FC(type, stype) host_to_le16((type << 2) | (stype << 4))

/* MTU to be set for the wlan#ap device; this is mainly needed for IEEE 802.1X
 * frames that might be longer than normal default MTU and they are not
 * fragmented */
#define HOSTAPD_MTU 2290

extern unsigned char rfc1042_header[6];

struct hostap_sta_driver_data {
	unsigned long rx_packets, tx_packets, rx_bytes, tx_bytes;
	unsigned long current_tx_rate;
	unsigned long inactive_msec;
	unsigned long flags;
	unsigned long num_ps_buf_frames;
	unsigned long tx_retry_failed;
	unsigned long tx_retry_count;
	int last_rssi;
	int last_ack_rssi;
};

struct driver_ops;
struct wpa_ctrl_dst;
struct radius_server_data;

#ifdef CONFIG_FULL_DYNAMIC_VLAN
struct full_dynamic_vlan;
#endif /* CONFIG_FULL_DYNAMIC_VLAN */

#define	QOS_UNABLE	0	/*AP流控，chary，2011-11-9，  用户QOS参数值为0*/
struct bss_stats{
	u_int32_t access ;
	
	u_int32_t auth_8021x_req ;
	u_int32_t auth_8021x_req_reauth ;
	u_int32_t auth_8021x_success ;
	u_int32_t auth_8021x_failed ;

	u_int32_t wpa_req ;
	u_int32_t wpa_success ;
	u_int32_t wpa_failed ;
} ;

/**
 * struct hostapd_data - hostapd per-BSS data structure
 */
struct hostapd_data {
	struct hostapd_iface *iface;
	struct hostapd_config *iconf;
	struct hostapd_bss_config *conf;
	int interface_added; /* virtual interface added for this BSS */

	u8 own_addr[ETH_ALEN];

	int num_sta; /* number of entries in sta_list */
	struct sta_info *sta_list; /* STA info list head */
	struct sta_info *sta_hash[STA_HASH_SIZE];

	/* pointers to STA info; based on allocated AID or NULL if AID free
	 * AID is in the range 1-2007, so sta_aid[0] corresponders to AID 1
	 * and so on
	 */
	struct sta_info *sta_aid[MAX_AID_TABLE_SIZE];

	struct driver_ops *driver;

	u8 *default_wep_key;
	u8 default_wep_key_idx;

	struct radius_client_data *radius;
	int radius_client_reconfigured;
	u32 acct_session_id_hi, acct_session_id_lo;

	struct iapp_data *iapp;

	enum { DO_NOT_ASSOC = 0, WAIT_BEACON, AUTHENTICATE, ASSOCIATE,
	       ASSOCIATED } assoc_ap_state;
	char assoc_ap_ssid[33];
	int assoc_ap_ssid_len;
	u16 assoc_ap_aid;

	struct hostapd_cached_radius_acl *acl_cache;
	struct hostapd_acl_query_data *acl_queries;

	struct wpa_authenticator *wpa_auth;

	struct rsn_preauth_interface *preauth_iface;
	time_t michael_mic_failure;
	int michael_mic_failures;
	int tkip_countermeasures;

	int ctrl_sock;
	struct wpa_ctrl_dst *ctrl_dst;

	void *ssl_ctx;
	void *eap_sim_db_priv;
	struct radius_server_data *radius_srv;

	int parameter_set_count;

#ifdef CONFIG_FULL_DYNAMIC_VLAN
	struct full_dynamic_vlan *full_dynamic_vlan;
#endif /* CONFIG_FULL_DYNAMIC_VLAN */

	u32 vap_id ;		/*设备管理模块：VAP编址*/
	u8 vap_index ;	/*HOSTAPD内部编址，0~MAX_BSSES-1，在hostapd_iface::bss[]中的索引号*/
	u8 ioctl_state[IOCTL_STATE_BYTES] ;	/*ioctl_state[0]的0位为最低位*/
	u8 wtp_vap_added ;
	u8 setuped ;		/*0: not setup, 1: setup*/
	u8 key_rsc[IEEE80211_WEP_NKID][WPA_KEY_RSC_LEN] ;
	u32 state ;		/*0: 可用, 1: vap故障*/
	struct bss_stats stats ;
	u8 ioctl_packet ;		/*1：IOCTL打包发送；0：IOCTL即时发送*/

	struct hostapd_ppp_auth_data * ppp_auth ;

	u32 timeout_vapstart;
	struct hostapd_acbss_stats vap_stats;
};


/**
 * hostapd_iface_cb - Generic callback type for per-iface asynchronous requests
 * @iface: the interface the event occured on.
 * @status: 0 if the request succeeded; -1 if the request failed.
 */
typedef void (*hostapd_iface_cb)(struct hostapd_iface *iface, int status);


struct hostapd_config_change;

struct hapd_interfaces {
	u16 usWtpId ;	/*同设备管理模块中WTP的ID定义*/
	char * nas_identifier ;
	struct hostapd_iface * iface[MAX_INTERFACES] ;
	u32 state ;		/*0: 可用, 1: WTP故障*/
};

extern struct hapd_interfaces * g_pstWtpTable[MAX_WTPS] ;


struct hostapd_stats{
	u32 ulInterAcRoaming;	/*AC内部切换成功次数*/
	u32 ulExterAcRoamingIn;	/*跨控制域切入次数*/
	u32 ulExterAcRoaningOut;/*跨控制域切出次数*/

	u32 ulRadiusAuthReq;		/*AC发向RADIUS的认证请求包数*/
	//u32 ulRadiusAuthResp;	/*RADIUS响应包数，含挑战、接入成功、接入失败*/
	//u32 ulRadiusAuthReq2;	/*AC发向RADIUS的认证次数 */
	u32 ulRadiusAuthSucc;	/*RADIUS响应成功的认证次数*/

	u32 ulRadiusAuthReqFailed;    /*  2011.4.6 */
	u32 ulRadiusAuthReject;          /*  2011.4.6 */
};
extern struct hostapd_stats g_stStats ;

/**
 * struct hostapd_iface - hostapd per-interface data structure
 */
struct hostapd_iface {
	char *config_fname;
	struct hostapd_config *conf;

	hostapd_iface_cb setup_cb;
#if 0
	size_t num_bss;
#endif
	struct hostapd_data *bss[MAX_BSSES];

	int num_ap; /* number of entries in ap_list */
	struct ap_info *ap_list; /* AP info list head */
	struct ap_info *ap_hash[STA_HASH_SIZE];
	struct ap_info *ap_iter_list;

	struct hostapd_hw_modes *hw_features;
	int num_hw_features;
	struct hostapd_hw_modes *current_mode;
	/* Rates that are currently used (i.e., filtered copy of
	 * current_mode->channels */
	int num_rates;
	struct hostapd_rate_data *current_rates;
	hostapd_iface_cb hw_mode_sel_cb;

	u16 hw_flags;

	/* Number of associated Non-ERP stations (i.e., stations using 802.11b
	 * in 802.11g BSS) */
	int num_sta_non_erp;

	/* Number of associated stations that do not support Short Slot Time */
	int num_sta_no_short_slot_time;

	/* Number of associated stations that do not support Short Preamble */
	int num_sta_no_short_preamble;

	int olbc; /* Overlapping Legacy BSS Condition */

	int dfs_enable;
	u8 pwr_const;
	unsigned int tx_power;
	unsigned int sta_max_power;

	unsigned int channel_switch;

	struct hostapd_config_change *change;
	hostapd_iface_cb reload_iface_cb;
	hostapd_iface_cb config_reload_cb;

	u32 gdev_id ;		/*设备管理模块：组设备编址*/
	u32 interface_id ;	/*设备管理模块：单卡编址*/
	u8 interface_index ;	/*HOSTAPD内部编址，0~MAX_INTERFACES-1，在hapd_interfaces::iface[]中的索引号*/
	struct hapd_interfaces * pstWtp ;
};

void hostapd_set_sta_authorized(struct hostapd_data *hapd,
				   struct sta_info *sta, int authorized) ;
void hostapd_new_assoc_sta(struct hostapd_data *hapd, struct sta_info *sta,
			   int reassoc);
void hostapd_logger(struct hostapd_data *hapd, const u8 *addr,
		    unsigned int module, int level, const char *fmt,
		    ...) PRINTF_FORMAT(5, 6);


#if 0//ifndef _MSC_VER
#define HOSTAPD_DEBUG(level, args...) \
do { \
	if (hapd->conf == NULL || hapd->conf->debug >= (level)) \
		printf(args); \
} while (0)
#else
static inline void HOSTAPD_DEBUG(int level, const char * args, ...)
{
	va_list hapd ;
	char format[1024] = {0} ;
	int count ;
	int level_map[] = {
		0 ,				/*none*/
		APP_DETAIL , 		/*HOSTAPD_DEBUG_MINIMAL*/
		APP_DETAIL , 		/*HOSTAPD_DEBUG_VERBOSE*/
		APP_MSG , 		/*HOSTAPD_DEBUG_MSGDUMPS*/
		APP_WARN		/*HOSTAPD_DEBUG_EXCESSIVE*/
	} ;

	va_start(hapd, args) ;
	count = vsnprintf(format, sizeof(format), args, hapd) ;
	va_end(hapd) ;

	if(count < 0 || count >= sizeof(format))
		return ;
	
	ModuleLogMsg(APP_MODULE_HOSTAPD, level_map[level], "%s",format) ;
}
#endif /* _MSC_VER */

#define HOSTAPD_DEBUG_COND(level) (hapd->conf->debug >= (level))

const char * hostapd_ip_txt(const struct hostapd_ip_addr *addr, char *buf,
			    size_t buflen);
int hostapd_ip_diff(struct hostapd_ip_addr *a, struct hostapd_ip_addr *b);

void ProcEntryHostapdAc(WORD16 wEvent,
						BYTE *pbyBody,
						WORD16 wLen,
						BYTE *pbyResv,
						WORD16 wResv,
						BYTE *pbyProcData) ;
void ProcEntryHostapdAcDaemon(WORD16 wEvent,
						BYTE *pbyBody,
						WORD16 wLen,
						BYTE *pbyResv,
						WORD16 wResv,
						BYTE *pbyProcData) ;

/*SOCKET数据转发*/
BOOL HostapdSend(struct hostapd_data * from ,
				struct hostapd_data * to ,
				WORD16 wEvent, 		/*定义如"EV_HOSTAPD_SOCKET_*"*/
                         	BYTE *lpbyIn, 		/*消息源数据，未包括HOSTAPD_HEAD_T*/
                        	WORD16 wInLen) ;

/*层二数据转发*/
int l2_packet_send(void * tx_ctx, const u8 *dst_addr, u16 proto, const u8 *buf, size_t len) ;


/*
  功能：获取IOCTL状态表ioctl_state_table中，命令ioctl_id所对应的标志位
*/
#define IW_IOCTL_IDX(cmd)	((cmd) - SIOCIWFIRST)
static  inline u8 ioctl_state_get(u8 * ioctl_state_table, u32 ioctl_id)
{
	if(ioctl_state_table && ioctl_id >=  IOCTL_STATE_BEGIN && ioctl_id <= IOCTL_STATE_END){
		u8 iIndex = (u8)(IW_IOCTL_IDX(ioctl_id));
		u8 iByte = (u8)(iIndex >> 3);
		u8 iBit = (u8)(iIndex & 0x07);

		return  (u8)(ioctl_state_table[iByte] & (1 << iBit));
	}
	return 0 ;
}

/*
  功能：设置IOCTL状态表ioctl_state_table中，命令ioctl_id对应的标志位为1
*/
#define IOCTL_STATE_SET(ioctl_state_table, ioctl_id)	\
{	\
	if(ioctl_id >=  IOCTL_STATE_BEGIN && ioctl_id <= IOCTL_STATE_END){	\
		u8 iIndex = IW_IOCTL_IDX(ioctl_id) ;	\
		u8 iByte = iIndex >> 3 ;	\
		u8 iBit = iIndex & 0x07 ;	\
	\
		ioctl_state_table[iByte] |= (1 << iBit) ;	\
	}	\
}

/*
  功能：设置IOCTL状态表ioctl_state_table中，命令ioctl_id对应的标志位为0
*/
#define IOCTL_STATE_RESET(ioctl_state_table, ioctl_id)	\
{	\
	if(ioctl_id >=  IOCTL_STATE_BEGIN && ioctl_id <= IOCTL_STATE_END){	\
		u8 iIndex = IW_IOCTL_IDX(ioctl_id) ;	\
		u8 iByte = iIndex >> 3 ;	\
		u8 iBit = iIndex & 0x07 ;	\
	\
		ioctl_state_table[iByte] &= ~(1 << iBit) ;	\
	}	\
}

/*
	type: 1, pObj: struct hostapd_data
	type: 2, pObj: struct hostapd_iface
	type: 3, pObj: 
	type: 4, pObj: struct hapd_interfaces
*/
int hostapd_report_event(void * pObj, int type, u_int32_t ulEventId, u_int32_t ulReasonId, void * pstExt) ;

void OnWaitVapIoctlTimer(void *eloop_ctx, void *timeout_ctx) ;
void OnWaitStaIoctlTimer(void *eloop_ctx, void *timeout_ctx) ;

int hostapd_portal_auth(struct hostapd_data * hapd, u8 * mac) ;
int hostapd_sta_portal_authorized(struct hostapd_data * hapd, u8 * mac) ;

struct hostapd_data * FindVapByIndex(u16 usWtpId, u32 ulIfIndex, u32 ulVapIndex);
int hostapd_authstat_inc(u8 *addr, u32 ulStatType, u32 ulWtpId, u32 ulVapId);  /* BugId=269,  chary, 2011-11-24   */

#define TIME_WAIT_IOCTL	30		/*s*/

/*定时器资源*/
#define TIMER_HOSTAPD		TIMER31
#define EV_TIMER_HOSTAPD	EV_TIMER31

#endif /* HOSTAPD_H */
