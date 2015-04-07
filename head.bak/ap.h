/*
 * hostapd / Station table data structures
 * Copyright (c) 2002-2004, Jouni Malinen <j@w1.fi>
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

#ifndef AP_H
#define AP_H

#include "common.h"
#include "ac_usrm_public.h"

/* STA flags */
#define WLAN_STA_AUTH BIT(0)
#define WLAN_STA_ASSOC BIT(1)
#define WLAN_STA_PS BIT(2)
#define WLAN_STA_TIM BIT(3)
#define WLAN_STA_PERM BIT(4)
#define WLAN_STA_AUTHORIZED BIT(5)
#define WLAN_STA_PENDING_POLL BIT(6) /* pending activity poll not ACKed */
#define WLAN_STA_SHORT_PREAMBLE BIT(7)
#define WLAN_STA_PREAUTH BIT(8)
#define WLAN_STA_WME BIT(9)
#define WLAN_STA_NONERP BIT(31)
#define WLAN_STA_AUTHORIZED_MAC BIT(30)

/* Maximum number of supported rates (from both Supported Rates and Extended
 * Supported Rates IEs). */
#define WLAN_SUPP_RATES_MAX 32

struct radius_client_data ;

struct sta_info {
	struct sta_info *next; /* next entry in sta list */
	struct sta_info *hnext; /* next entry in hash table list */
	struct sta_info *ghnext ; /*next entry in global hash table list*/
	u8 addr[6];
	u16 aid; /* STA's unique AID (1 .. 2007) or 0 if not yet assigned */
	u32 flags;
	u16 capability;
	u16 listen_interval; /* or beacon_int for APs */
	u8 supported_rates[WLAN_SUPP_RATES_MAX];
	int supported_rates_len;

	unsigned int nonerp_set:1;
	unsigned int no_short_slot_time_set:1;
	unsigned int no_short_preamble_set:1;

	u16 auth_alg;
	u8 previous_ap[6];

	enum {
		STA_NULLFUNC = 0, STA_DISASSOC, STA_DEAUTH, STA_REMOVE
	} timeout_next;

	/* IEEE 802.1X related data */
	struct eapol_state_machine *eapol_sm;

	/* IEEE 802.11f (IAPP) related data */
	struct ieee80211_mgmt *last_assoc_req;

	u32 acct_session_id_hi;
	u32 acct_session_id_lo;
	time_t acct_session_start;
	int acct_session_started;
	int acct_terminate_cause; /* Acct-Terminate-Cause */
	int acct_interim_interval; /* Acct-Interim-Interval */
    int acct_idle_time;       /*IdleTimeOut: Attribute Value: 28: RFC2865*/
    int acct_session_timeout ;   /*Sessiontimeout: Attribute Value: 27: RFC2865*/

	unsigned long last_rx_bytes;
	unsigned long last_tx_bytes;
	u32 acct_input_gigawords; /* Acct-Input-Gigawords */
	u32 acct_output_gigawords; /* Acct-Output-Gigawords */

	u8 *challenge; /* IEEE 802.11 Shared Key Authentication Challenge */

	struct wpa_state_machine *wpa_sm;
	struct rsn_preauth_interface *preauth_iface;

	struct hostapd_ssid *ssid; /* SSID selection based on (Re)AssocReq */
	struct hostapd_ssid *ssid_probe; /* SSID selection based on ProbeReq */

	int vlan_id;

	u8 ioctl_state[IOCTL_STATE_BYTES] ;
	int registered ;	/*1：已通知用户管理模块新增用户；0：未通知或已通知用户管理模块删除用户；*/
	int leave ;	/*1：表示网络或终端用户发起去关联/去鉴权*/

	void * ctx ;	/*指向当前关联的VAP*/
	u32 access_reason ;	/*接入原因*/
	u32 leave_reason ;	/*离线原因*/

	u8 * identity ;	/*用户名，字符串格式，以'\0'结尾*/
	AC_USR_QOS_T user_qos ;
	u8 nas_ip[4] ;
	u8 * nas_id ;
	struct radius_client_data * radius ;	/*从RADIUS CLIENT POOL中分配的RADIUS*/
	u8 radius_ip[4];
	u8 acUserGroupName[128];/*add for filterid*/
};


/* Default value for maximum station inactivity. After AP_MAX_INACTIVITY has
 * passed since last received frame from the station, a nullfunc data frame is
 * sent to the station. If this frame is not acknowledged and no other frames
 * have been received, the station will be disassociated after
 * AP_DISASSOC_DELAY seconds. Similarily, the station will be deauthenticated
 * after AP_DEAUTH_DELAY seconds has passed after disassociation. */
#define AP_MAX_INACTIVITY (5 * 60)
#define AP_DISASSOC_DELAY (1)
#define AP_DEAUTH_DELAY (1)
/* Number of seconds to keep STA entry with Authenticated flag after it has
 * been disassociated. */
#define AP_MAX_INACTIVITY_AFTER_DISASSOC (1 * 30)
/* Number of seconds to keep STA entry after it has been deauthenticated. */
#define AP_MAX_INACTIVITY_AFTER_DEAUTH (1 * 5)

#endif /* AP_H */
