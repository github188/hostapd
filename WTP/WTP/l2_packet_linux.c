/*
 * WPA Supplicant - Layer2 packet handling with Linux packet sockets
 * Copyright (c) 2003-2005, Jouni Malinen <j@w1.fi>
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
#include "common.h"

#ifndef _MSC_VER
#include <sys/ioctl.h>
#include <netpacket/packet.h>
#include <net/if.h>
#endif

#include "common.h"
#include "eloop.h"
#include "hostapd_wtp.h"
#include "wireless_copy.h"
#include "l2_packet.h"
#include "HostapdSocket.h"
#include "hostapd_wtp_stats.h"

#define IEEE80211_WEP_NKID 4

int l2_packet_get_own_addr(struct l2_packet_data *l2, u8 *addr)
{
	os_memcpy(addr, l2->own_addr, ETH_ALEN);
	return 0;
}


int l2_packet_send(struct l2_packet_data *l2, const u8 *dst_addr, u16 proto,
		   const u8 *buf, size_t len)
{
	int ret = 0 ;

#if 0
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
	
#ifndef _MSC_VER
	if (l2 == NULL)
		return -1;
	if (l2->l2_hdr) {
		ret = send(l2->fd, buf, len, 0);
		if (ret < 0)
			perror("l2_packet_send - send");
	} else {
		struct sockaddr_ll ll;
		os_memset(&ll, 0, sizeof(ll));
		ll.sll_family = AF_PACKET;
		ll.sll_ifindex = l2->ifindex;
		ll.sll_protocol = htons(proto);
		ll.sll_halen = ETH_ALEN;
		os_memcpy(ll.sll_addr, dst_addr, ETH_ALEN);
		ret = sendto(l2->fd, buf, len, 0, (struct sockaddr *) &ll,
			     sizeof(ll));
		if (ret < 0)
			perror("l2_packet_send - sendto");
	}
#endif

	return ret;
}

static void l2_packet_receive(int sock, void *eloop_ctx, void *sock_ctx)
{
#define L2_LEN_RESERVE	(sizeof(HOSTAPD_HEAD_T)+sizeof(HOSTAPD_ELEM_T) + sizeof(eloop_ctx) + sizeof(HOSTAPD_ELEM_T) + sizeof(sock_ctx) + sizeof(HOSTAPD_ELEM_T) + ETH_ALEN + sizeof(HOSTAPD_ELEM_T) + sizeof(u16) + sizeof(HOSTAPD_ELEM_T))
#define L2_LEN_RESERVE4	(((L2_LEN_RESERVE-1)/4 + 1)*4)
	u8 buf[L2_LEN_RESERVE4+2300] = {0} ;
	int res = 0;
#ifndef _MSC_VER
	struct sockaddr_ll ll;
#else
	u8 mac[6] = {0} ;
#endif
	socklen_t fromlen;
	struct hostapd_data * hapd = NULL ;
	struct l2_packet_data * l2 = NULL ;
	HOSTAPD_HEAD_T * pHead = NULL ;
	HOSTAPD_ELEM_T * pElem = NULL ;
	TPID tReceiver = {0} ;

	if((l2 = (struct l2_packet_data *)eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point(eloop_ctx) is NULL.\n", __func__) ;
		return ;
	}

	switch(l2->protocol){
	case ETH_P_EAPOL :{
		struct madwifi_driver_data * pstDriver = NULL ;

		if((pstDriver = l2->rx_callback_ctx) == NULL
			|| (hapd = pstDriver->hapd) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, point(EAPOL) is NULL.\n", __func__) ;
			return ;
		}
		break ;
	}
	case ETH_P_PREAUTH :{
		struct rsn_preauth_interface * pstPreauth = NULL ;

		if((pstPreauth = l2->rx_callback_ctx) == NULL
			|| (hapd = pstPreauth->hapd) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, point(PREAUTH) is NULL.\n", __func__) ;
			return ;
		}
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, l2->protocol(%d).\n", __func__, l2->protocol) ;
		return ;
	}

#ifndef _MSC_VER
	os_memset(&ll, 0, sizeof(ll));
	fromlen = sizeof(ll);
	res = recvfrom(sock, buf+L2_LEN_RESERVE, sizeof(buf)-L2_LEN_RESERVE, 0, (struct sockaddr *) &ll,
		       &fromlen);
	if (res < 0) {
		perror("l2_packet_receive - recvfrom");
		return;
	}

#if 0
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
		"%s, recv data: %d.\n", __func__, res) ;
#endif
#endif
	hostapd_bss_stats_inc(hapd->iface->interfaceindex, hapd->bssindex, RecvDriverL2);

	/*设置头*/
	pHead = (HOSTAPD_HEAD_T *)buf ;
	pHead->ucToInterface = pHead->ucFromInterface = hapd->iface->interfaceindex ;
	pHead->ucToBss = pHead->ucFromBss = hapd->bssindex ;

	/*设置eloop_ctx地址*/
	pElem = (unsigned char *)pHead + sizeof(HOSTAPD_HEAD_T) ;
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_ELOOP ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + sizeof(eloop_ctx) ;
	* ((unsigned long *)(pElem + 1)) = eloop_ctx ;

	/*设置sock_ctx*/
	pElem = (unsigned char *)pElem + pElem->dwLength ;
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_USER ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + sizeof(sock_ctx) ;
	* ((unsigned long *)(pElem + 1)) = sock_ctx ;

	/*设置源MAC*/
	pElem = (unsigned char *)pElem + pElem->dwLength ;
	pElem->dwElemId = HOSTAPD_ELEMID_COMMON_MAC ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + ETH_ALEN ;
#ifndef _MSC_VER
	os_memcpy(pElem + 1, ll.sll_addr, ETH_ALEN) ;
#else
	os_memcpy(pElem + 1, mac, ETH_ALEN) ;
#endif

	/*设置报文协议类型*/
	pElem = (unsigned char *)pElem + pElem->dwLength ;
	pElem->dwElemId = HOSTAPD_ELEMID_COMMON_PROTO ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + sizeof(l2->protocol) ;
	* ((u16 *)(pElem + 1)) = l2->protocol ;
#if 0
{
	int i ;

	for(i = 1 ; i <= L2_LEN_RESERVE ; i ++){
		printf("%02x.", buf[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
	printf("\n") ;
}
#endif

	/*设置网络数据包*/
	pElem = (unsigned char *)pElem + pElem->dwLength ;
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_DATA ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + res ;

	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, get local pid failed.\n", __func__) ;
		return  ;
	}
	
	if(! VmASend(EV_HOSTAPD_SOCKET_L2, buf, L2_LEN_RESERVE+res,  tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, send socket_radius failed.\n", __func__) ;
		return ;
	}
	hostapd_bss_stats_inc(hapd->iface->interfaceindex, hapd->bssindex, SendLocalL2);

	return ;
#undef L2_LEN_RESERVE4
#undef L2_LEN_RESERVE	
}

void l2_packet_receiveA(void *eloop_ctx, void *sock_ctx, u8 * pbMac, u8 * pbL2Data, int iL2DataLen)
{
	struct l2_packet_data *l2 = eloop_ctx;
	u8 buf[2300];
	int res = 0;
	BYTE * pbOut = NULL , * pbFrame = NULL ;
	WORD32 dwOutLen = 0 ;
	struct hostapd_data * pstBssFrom = NULL ;
	
#if 0
	os_memset(&ll, 0, sizeof(ll));
	fromlen = sizeof(ll);
	res = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *) &ll,
		       &fromlen);
	if (res < 0) {
		perror("l2_packet_receive - recvfrom");
		return;
	}
#else
	if(pbMac == NULL || pbL2Data == NULL || iL2DataLen < 0 || iL2DataLen > sizeof(buf))
		return ;

	os_memcpy(buf, pbL2Data, iL2DataLen) ;
	res = iL2DataLen ;
#endif

#if 0
{
	unsigned long i ;
	
	printf("%s, type: %s, from "MACSTR", len(%u).\n", 
		__func__, l2->protocol == ETH_P_EAPOL ? "EAPOL" : "PREAUTH/OTHER", MAC2STR(ll.sll_addr), res) ;
	for(i = 1 ; i <= res ; i ++){
		printf("%02x.",  buf[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
	printf("\n") ;
}	
#endif

	switch(l2->protocol){
	case ETH_P_EAPOL :{
		struct madwifi_driver_data * pstDriver = NULL ;
		unsigned long key_index = 0, offset = 0 ;
		u8 rsc[IEEE80211_WEP_NKID][WPA_KEY_RSC_LEN] = {0} ;

		if((pstDriver = l2->rx_callback_ctx) == NULL
			|| (pstBssFrom = pstDriver->hapd) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), point is NULL.\n", __func__, __LINE__) ;
			return ;
		}

		/*获取RSC*/
		for(key_index = 0; key_index < IEEE80211_WEP_NKID; key_index ++)
			madwifi_get_seqnum(NULL, pstDriver, NULL, key_index, rsc[key_index]) ;

		/*转发至AC*/
		dwOutLen = sizeof(HOSTAPD_ELEM_T) + ETH_ALEN 
				+ sizeof(HOSTAPD_ELEM_T) + res
				+ sizeof(HOSTAPD_ELEM_T) + IEEE80211_WEP_NKID*WPA_KEY_RSC_LEN ;/*32: 4个key_rsc长度*/
		pbFrame = pbOut = os_zalloc(dwOutLen) ;
		if(pbOut == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
					"%s(%d), no memory.\n", __func__, __LINE__) ;
			return ;
		}

		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_MAC, pbMac, ETH_ALEN) ;
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_DATA, buf , res) ;
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EAPOL_KEYRSC, rsc, IEEE80211_WEP_NKID*WPA_KEY_RSC_LEN) ;

		if(! HostapdSend(pstBssFrom, NULL, EV_HOSTAPD_SOCKET_EAPOL, pbOut, dwOutLen)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), call HostapdSend failed.\n", __func__, __LINE__) ;
			goto bad ;
		}
		hostapd_bss_stats_inc(pstBssFrom->iface->interfaceindex, pstBssFrom->bssindex, SendAcEapol);
		
		break ;
	}
	case ETH_P_PREAUTH :{
		struct rsn_preauth_interface * pstPreauth = NULL ;

		if((pstPreauth = l2->rx_callback_ctx) == NULL
			|| (pstBssFrom = pstPreauth->hapd) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), point is NULL.\n", __func__, __LINE__) ;
			return ;
		}

		/*转发至AC*/
		dwOutLen = sizeof(HOSTAPD_ELEM_T) + ETH_ALEN 
				+ sizeof(HOSTAPD_ELEM_T) + res 
				+ sizeof(HOSTAPD_ELEM_T) + os_strlen(l2->ifname) ;
		pbFrame = pbOut = os_zalloc(dwOutLen) ;
		if(pbOut == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
					"%s(%d), no memory.\n", __func__, __LINE__) ;
			return ;
		}

		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_MAC, pbMac, ETH_ALEN) ;
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_DATA, buf , res) ;
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_DEVICENAME, l2->ifname, os_strlen(l2->ifname)) ;

		if(! HostapdSend(pstBssFrom, NULL, EV_HOSTAPD_SOCKET_PREAUTH, pbOut, dwOutLen)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), call HostapdSend failed.\n", __func__, __LINE__) ;
			goto bad ;
		}
		hostapd_bss_stats_inc(pstBssFrom->iface->interfaceindex, pstBssFrom->bssindex, SendAcPreauth);
		
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, unknown protocol(0x%x).\n", __func__, l2->protocol) ;
		goto bad ;
	}
	
bad :
	if(pbOut)
		os_free(pbOut) ;

	return ;
}


struct l2_packet_data * l2_packet_init(
	const char *ifname, const u8 *own_addr, unsigned short protocol,
	void (*rx_callback)(void *ctx, const u8 *src_addr,
			    const u8 *buf, size_t len),
	void *rx_callback_ctx, int l2_hdr)
{
	struct l2_packet_data *l2;
	struct ifreq ifr;
#ifndef _MSC_VER
	struct sockaddr_ll ll;
#endif

	l2 = os_zalloc(sizeof(struct l2_packet_data));
	if (l2 == NULL)
		return NULL;
	
	os_strncpy(l2->ifname, ifname, sizeof(l2->ifname));
	l2->rx_callback = rx_callback;
	l2->rx_callback_ctx = rx_callback_ctx;
	l2->l2_hdr = l2_hdr;
	l2->protocol = protocol ;

#ifndef _MSC_VER
	l2->fd = socket(PF_PACKET, l2_hdr ? SOCK_RAW : SOCK_DGRAM,
			htons(protocol));
	if (l2->fd < 0) {
		perror("socket(PF_PACKET)");
		os_free(l2);
		return NULL;
	}
	
	os_strncpy(ifr.ifr_name, l2->ifname, sizeof(ifr.ifr_name));
	if (ioctl(l2->fd, SIOCGIFINDEX, &ifr) < 0) {
		perror("ioctl[SIOCGIFINDEX]");
		close(l2->fd);
		os_free(l2);
		return NULL;
	}
	l2->ifindex = ifr.ifr_ifindex;

	os_memset(&ll, 0, sizeof(ll));
	ll.sll_family = PF_PACKET;
	ll.sll_ifindex = ifr.ifr_ifindex;
	ll.sll_protocol = htons(protocol);
	if (bind(l2->fd, (struct sockaddr *) &ll, sizeof(ll)) < 0) {
		perror("bind[PF_PACKET]");
		close(l2->fd);
		os_free(l2);
		return NULL;
	}

	if (ioctl(l2->fd, SIOCGIFHWADDR, &ifr) < 0) {
		perror("ioctl[SIOCGIFHWADDR]");
		close(l2->fd);
		os_free(l2);
		return NULL;
	}
	os_memcpy(l2->own_addr, ifr.ifr_hwaddr.sa_data, ETH_ALEN);

	eloop_register_read_sock(l2->fd, l2_packet_receive, l2, NULL);
#endif

	return l2;
}


void l2_packet_deinit(struct l2_packet_data *l2)
{
	if (l2 == NULL)
		return;

	if (l2->fd >= 0) {
		eloop_unregister_read_sock(l2->fd);

#ifndef _MSC_VER
		close(l2->fd);
#endif

		l2->fd = -1 ;
	}
		
	os_free(l2);
}


int l2_packet_get_ip_addr(struct l2_packet_data *l2, char *buf, size_t len)
{
#ifndef _MSC_VER
	int s;
	struct ifreq ifr;
	struct sockaddr_in *saddr;

	s = socket(PF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
		perror("socket");
		return -1;
	}
	os_memset(&ifr, 0, sizeof(ifr));
	os_strncpy(ifr.ifr_name, l2->ifname, sizeof(ifr.ifr_name));
	if (ioctl(s, SIOCGIFADDR, &ifr) < 0) {
		if (errno != EADDRNOTAVAIL)
			perror("ioctl[SIOCGIFADDR]");
		close(s);
		return -1;
	}
	close(s);
	saddr = (struct sockaddr_in *) &ifr.ifr_addr;
	if (saddr->sin_family != AF_INET)
		return -1;
	os_snprintf(buf, len, "%s", inet_ntoa(saddr->sin_addr));
#endif
	return 0;
}


void l2_packet_notify_auth_start(struct l2_packet_data *l2)
{
}

