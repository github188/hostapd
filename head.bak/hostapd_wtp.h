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

#include "common.h"

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif
#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif
#ifndef ETH_P_ALL
#define ETH_P_ALL 0x0003
#endif
#ifndef ETH_P_PAE
#define ETH_P_PAE 0x888E /* Port Access Entity (IEEE 802.1X) */
#endif /* ETH_P_PAE */

#ifndef BIT
#define BIT(x) (1 << (x))
#endif

#ifndef MAC2STR
#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"
#endif

#define WPA_REPLAY_COUNTER_LEN 8
#define WPA_NONCE_LEN 32
#define WPA_KEY_RSC_LEN 8

#define MAX_INTERFACES	4
#define MAX_BSSES		16

/*  AP流控，chary，2011-11-8 */
#define	ORDER_STA_ADD		1	/*  添加STA命令    */
#define	ORDER_STA_DEL		2	/*   删除STA 命令   */
#define	ORDER_VAP_ADD		3	/*   添加VAP命令   */
#define	ORDER_VAP_DEL		4	/*    删除VAP命令  */


struct madwifi_driver_data {
	struct hostapd_data *hapd;		/* back pointer */

	char	iface[IFNAMSIZ + 1];
	int     ifindex;
	struct l2_packet_data *sock_xmit;	/* raw packet xmit socket */
	struct l2_packet_data *sock_recv;	/* raw packet recv socket */
	int	ioctl_sock;			/* socket for ioctl() use */
	int	wext_sock;			/* socket for wireless events */
	int	we_version;
};

struct rsn_preauth_interface {
	struct rsn_preauth_interface *next;
	struct hostapd_data *hapd;
	struct l2_packet_data *l2;
	char ifname[IFNAMSIZ + 1];
	int ifindex;
};

/**
 * struct hostapd_data - hostapd per-BSS data structure
 */
struct hostapd_data {
	struct hostapd_iface * iface ;	/* back pointer */

	u8 bssindex ;				/*HOSTAPD内部编址，0~MAX_BSSES-1，在hostapd_iface::bss[]中的索引号*/
	char ifacename[IFNAMSIZ + 1] ;
	struct madwifi_driver_data *driver;
	struct rsn_preauth_interface *preauth_iface ;
	u8 own_addr[ETH_ALEN];
};

/**
 * struct hostapd_iface - hostapd per-interface data structure
 */
struct hostapd_iface {
	struct hapd_interfaces * wtp ;	/* back pointer */

	u8 interfaceindex ;			/*HOSTAPD内部编址，0~MAX_INTERFACES-1，在hapd_interfaces::iface[]中的索引号*/
	struct hostapd_data * bss[MAX_BSSES] ;
};

/**
 * struct hapd_interfaces - hostapd per-wtp data structure
 */
struct hapd_interfaces {
	int sub_id ;	/*子设备ID，0为主设备*/
	struct hostapd_iface * iface[MAX_INTERFACES] ;
};


/*  AP流控，chary，2011-11-8 */
struct	flow_ctl_ref
{
	WORD32	radio_id;		/*    RADIO-ID  */
	WORD32	vap_id;			/*   VAP-ID   */
	BYTE	sta_mac[6];		/*    终端的MAC  */
	WORD32	up_rate;		/*   上行速率   */
	WORD32	down_rate;		/*    下行速率  */
	WORD32	burst_size;		/*    突发流量字节数  */	
};



extern struct hapd_interfaces g_stWtp ;

void ProcEntryHostapdWtpAc(WORD16 wEvent, 
						BYTE *pbyBody, 
						WORD16 wLen, 
						BYTE *pbyResv, 
						WORD16 wResv, 
						BYTE *pbyProcData) ;

void ProcEntryHostapdWtpMadwifi(WORD16 wEvent, 
						BYTE *pbyBody, 
						WORD16 wLen, 
						BYTE *pbyResv, 
						WORD16 wResv, 
						BYTE *pbyProcData) ;

struct hostapd_data * FindVap(u32 ulIfIndex, u32 ulVapIndex) ;
BOOL VapAdd(BYTE bInterfaceIndex , BYTE bBssIndex , char * pcDeviceName , DWORD dwDeviceNameLen) ;
BOOL VapDelete(BYTE bInterfaceIndex , BYTE bBssIndex) ;

BOOL MadwifiInit(BYTE bInterfaceIndex , BYTE bBssIndex , char * pcBridge, DWORD dwBridgeLen) ;
BOOL MadwifiDeinit(BYTE bInterfaceIndex , BYTE bBssIndex) ;

BOOL rsn_preauth_iface_init(BYTE bInterfaceIndex , BYTE bBssIndex, char * pcInterfaces , WORD32 dwInterfacesLen) ;
BOOL rsn_preauth_iface_deinit(BYTE bInterfaceIndex , BYTE bBssIndex) ;

BOOL SubmitOrder2Drv(struct flow_ctl_ref *pstFlowCtl, WORD16 wLength, BYTE	order);

int madwifi_get_seqnum(const char *ifname, void *priv, const u8 *addr, int idx, u8 *seq) ;

int set80211priv(struct madwifi_driver_data *drv, int op, void *data, int len) ;
int set80211param(struct madwifi_driver_data *drv, int op, int arg) ;

void madwifi_wireless_event_receiveA(void *eloop_ctx, void *sock_ctx, u8 * data, int data_len) ;

void DumpDevices() ;

/*SOCKET数据转发*/
BOOL HostapdSend(struct hostapd_data * from ,
				struct hostapd_data * to ,
				WORD16 wEvent, 		/*定义如"EV_HOSTAPD_SOCKET_*"*/
                         	BYTE *lpbyIn, 		/*消息源数据，未包括HOSTAPD_HEAD_T*/	
                        	WORD16 wInLen) ;

BOOL HostapdTransmit(WORD16 wEvent, BYTE *pbyBody, WORD16 wLen, BYTE *pbyResv, WORD16 wResv, BYTE *pbyProcData) ;

#endif /* HOSTAPD_H */
