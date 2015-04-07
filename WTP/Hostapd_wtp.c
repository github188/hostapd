#ifndef _MSC_VER
#include <sys/socket.h>
#endif
#include "includes.h"
#include "common.h"
#include "OssApi.h"
#include "hostapd_wtp.h"
#include "wireless_copy.h"
#include "priv_netlink.h"
#include "HostapdSocket.h"
#include "compat.h"
#include "net80211/ieee80211.h"
#include "net80211/ieee80211_ioctl.h"
#include "l2_packet.h"
#include "hostapd_wtp_stats.h"

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif


typedef enum
{
	IOCTL_GET_STA_ASSOCID = 211,
}IOCTL_TYPE_E;

typedef struct
{
	IOCTL_TYPE_E enIoctlType;
	union
	{
		char buf[128] ;
		
		struct{
			u_int8_t ucMac[6] ;
			u_int16_t usAssocId ;
		}stGetAssocId ;
	}unData;
}IOCTL_DATA_T;

struct ieee802_1x_hdr {
	u8 version;
	u8 type;
	u16 length;
	/* followed by length octets of data */
} STRUCT_PACKED;

struct wpa_eapol_key {
	u8 type;
	u16 key_info;
	u16 key_length;
	u8 replay_counter[WPA_REPLAY_COUNTER_LEN];
	u8 key_nonce[WPA_NONCE_LEN];
	u8 key_iv[16];
	u8 key_rsc[WPA_KEY_RSC_LEN];
	u8 key_id[8]; /* Reserved */
	u8 key_mic[16];
	u16 key_data_length;
	/* followed by key_data_length bytes of key_data */
} STRUCT_PACKED;

/* bit4..5 is used in WPA, but is reserved in IEEE 802.11i/RSN */
#define WPA_KEY_INFO_KEY_INDEX_MASK (BIT(4) | BIT(5))
#define WPA_KEY_INFO_KEY_INDEX_SHIFT 4

enum {
	EAPOL_KEY_TYPE_RC4 = 1, 
	EAPOL_KEY_TYPE_RSN = 2,
	EAPOL_KEY_TYPE_WPA = 254 
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

struct hapd_interfaces g_stWtp = {-1, {0}};

#ifdef _MSC_VER
int ioctl(void * wandev, unsigned cmd, unsigned long arg)
{
	return 0 ;
}
#endif

void DumpDevices()
{
	int i, j ,k ;

	ModuleLogMsg(APP_MODULE_HOSTAPD, 
			APP_MSG, 
			"Device List:\n");
			
	for(i = 0; i < MAX_INTERFACES; i ++){
		struct hostapd_iface * pstIf = NULL ;

		if((pstIf = g_stWtp.iface[i]) == NULL)
			continue ;

		ModuleLogMsg(APP_MODULE_HOSTAPD, 
			APP_MSG, 
			"--interface %u: %u.\n", 
			i, 
			pstIf->interfaceindex);
			
		for(j = 0; j < MAX_BSSES; j ++){
			struct hostapd_data * pstVap = NULL ;

			if((pstVap = pstIf->bss[j]) == NULL)
				continue ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, 
				APP_MSG, 
				"----vap %u: %u, name: %s.\n", 
				j , 
				pstVap->bssindex, 
				pstVap->ifacename) ;
		}
	}
}

/*根据INTERFACE INDEX，VAP INDEX查找单卡*/
struct hostapd_data * FindVap(u32 ulIfIndex, u32 ulVapIndex)
{
	struct hostapd_iface * pstInterface = NULL ;
	
	if(ulIfIndex >= MAX_INTERFACES
		|| ulVapIndex >= MAX_BSSES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, ulIfIndex(%d)/ulVapIndex(%d).\n", __func__, ulIfIndex, ulVapIndex) ;
		return NULL ;
	}

	if((pstInterface = g_stWtp.iface[ulIfIndex]) == NULL)
		return NULL ;

	return pstInterface->bss[ulVapIndex] ;
}

BOOL VapAdd(BYTE bInterfaceIndex , BYTE bBssIndex , char * pcDeviceName , DWORD dwDeviceNameLen)
{
	struct hostapd_iface * pHostapdInterface = NULL ;
	struct hostapd_data * pHostapdBss = NULL ;
	struct madwifi_driver_data * pstDriver = NULL ;
	struct ifreq ifr ;
	BOOL bAddInterface = FALSE ;

	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES
		|| pcDeviceName == NULL
		|| dwDeviceNameLen <= 0
		|| dwDeviceNameLen > IFNAMSIZ){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point(%p) is NULL, or bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u), or dwDeviceNameLen(%u) is over(%u).\n", __func__ , pcDeviceName, bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES, dwDeviceNameLen, IFNAMSIZ) ;
		return FALSE ;
	}

	pHostapdInterface = g_stWtp.iface[bInterfaceIndex] ;
	if(pHostapdInterface == NULL){/*如果INTERFACE不存在，则添加INTERFACE数据*/
		pHostapdInterface = os_zalloc(sizeof(struct hostapd_iface)) ;
		if(pHostapdInterface == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), no memory.\n", __func__, __LINE__) ;
			return FALSE ;
		}
		
		pHostapdInterface->interfaceindex = bInterfaceIndex ;
		pHostapdInterface->wtp = & g_stWtp ;

		g_stWtp.iface[bInterfaceIndex] = pHostapdInterface ;
		bAddInterface = TRUE ;
	}

	if(pHostapdInterface->bss[bBssIndex] != NULL){/*该位置已经存在VAP*/
		char buf[IFNAMSIZ+1] = {0} ;
		
		os_memcpy(buf, pcDeviceName, dwDeviceNameLen) ;
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, iface[%u]/bss[%u] has been exist , add %s failed.\n", __func__ , bInterfaceIndex, bBssIndex, buf) ;
		return FALSE ;
	}

	/*添加VAP数据*/
	pHostapdBss = os_zalloc(sizeof(struct hostapd_data)) ;
	if(pHostapdBss == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), no memory.\n", __func__, __LINE__) ;
		goto bad ;
	}
	
	pHostapdBss->bssindex = bBssIndex ;
	pHostapdBss->iface = pHostapdInterface ;
	os_memcpy(pHostapdBss->ifacename, pcDeviceName, dwDeviceNameLen) ;
	pHostapdBss->ifacename[dwDeviceNameLen] = '\0' ;

	/*初始化driver*/
	pstDriver = os_zalloc(sizeof(struct madwifi_driver_data)) ;
	if(pstDriver == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s(%d), no memory.\n", __func__, __LINE__) ;
		goto bad ;
	}
	pstDriver->wext_sock = -1 ;

	pstDriver->hapd = pHostapdBss ;
	memcpy(pstDriver->iface, pHostapdBss->ifacename, sizeof(pstDriver->iface)) ;
#ifndef _MSC_VER	
	/*init ioctl_sock*/
	pstDriver->ioctl_sock = socket(PF_INET, SOCK_DGRAM, 0) ;
	if (pstDriver->ioctl_sock < 0) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, socket[PF_INET,SOCK_DGRAM].\n", __func__);
		goto bad;
	}

	memset(&ifr, 0, sizeof(ifr));
	snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", pstDriver->iface);
	if (ioctl(pstDriver->ioctl_sock, SIOCGIFINDEX, &ifr) != 0) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, ioctl(SIOCGIFINDEX).\n", __func__) ;
		close(pstDriver->ioctl_sock) ;
		pstDriver->ioctl_sock = -1 ;
		goto bad;
	}
	pstDriver->ifindex = ifr.ifr_ifindex;
#endif
	pHostapdBss->driver = pstDriver ;

	/*注册BSS*/
	pHostapdInterface->bss[bBssIndex] =  pHostapdBss ;
	
	return TRUE ;

bad :
	if(pstDriver){
		os_free(pstDriver) ;
		pstDriver = NULL ;
		pHostapdBss->driver = NULL ;
	}
	if(pHostapdBss){
		os_free(pHostapdBss) ;
		pHostapdBss = NULL ;
		pHostapdInterface->bss[bBssIndex] = NULL ;
	}
	if(bAddInterface){
		os_free(pHostapdInterface) ;
		pHostapdInterface = NULL ;
		g_stWtp.iface[bInterfaceIndex] = NULL ;
	}
		
	return FALSE ;
}

BOOL VapDelete(BYTE bInterfaceIndex , BYTE bBssIndex)
{
	struct hostapd_iface * pHostapdInterface = NULL ;
	struct hostapd_data * pHostapdBss = NULL ;
	struct madwifi_driver_data * pstDriver = NULL ;
	BOOL bNoVapOnIface = TRUE ;
	int i = 0 ;

	if((pHostapdInterface = g_stWtp.iface[bInterfaceIndex]) == NULL
		|| (pHostapdBss = pHostapdInterface->bss[bBssIndex]) == NULL
		|| (pstDriver = pHostapdBss->driver) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, iface[%u]/bss[%u] has been delete.\n", __func__, bInterfaceIndex, bBssIndex) ;
		return FALSE ;
	}

	/*停止VAP运作*/
	if (! MadwifiDeinit(bInterfaceIndex, bBssIndex)
		|| ! rsn_preauth_iface_deinit(bInterfaceIndex, bBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, stop vap(%u/%u) failed.\n", __func__, bInterfaceIndex, bBssIndex) ;
	}
	
#ifndef _MSC_VER
	if (pstDriver->ioctl_sock >= 0)
		close(pstDriver->ioctl_sock) ;
#endif

	os_free(pstDriver) ;
	pstDriver = NULL ;
	pHostapdBss->driver = NULL ;

	os_free(pHostapdBss) ;
	pHostapdBss = NULL ;

	/*注销BSS*/
	pHostapdInterface->bss[bBssIndex] = NULL ;

	/*如果当前接口卡上已没有VAP，则需删除当前接口卡*/
	for(i = 0 ; i < MAX_BSSES ; i ++){
		if(pHostapdInterface->bss[i]){
			bNoVapOnIface = FALSE ;
			break ;
		}
	}

	if(bNoVapOnIface){
		os_free(pHostapdInterface) ;
		pHostapdInterface = NULL ;
		g_stWtp.iface[bInterfaceIndex] = NULL ;
	}
	
	return TRUE ;
}

static BOOL NotifyEvent(struct madwifi_driver_data *drv, u16 usCmd, char * pcData, u16 usDataLen, u16 usReason, u16 usAssocId, u8 *pucMacList, int iMacListNum)
{
	char * pbOut = NULL , * pbFrame = NULL ;
	u16 usOutLen = 0 ;
	BOOL bRet ;

	usOutLen = sizeof(HOSTAPD_ELEM_T) + sizeof(usCmd)	/*HOSTAPD_ELEMID_EVENT_CMD*/
		+ sizeof(HOSTAPD_ELEM_T) + usDataLen			/*HOSTAPD_ELEMID_EVENT_DATA*/
		+ sizeof(HOSTAPD_ELEM_T) + sizeof(usReason)	/*HOSTAPD_ELEMID_REASON*/
		+ sizeof(HOSTAPD_ELEM_T) + sizeof(usAssocId) ;	/*HOSTAPD_ELEMID_EVENT_ASSOCID*/
	if(iMacListNum >= 0)
		usOutLen += sizeof(HOSTAPD_ELEM_T) + 6*iMacListNum;
		
	pbFrame = pbOut = os_zalloc(usOutLen) ;
	if(pbOut == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, no memory.\n", __func__) ;
		return FALSE ;
	}

	usCmd = htons(usCmd) ;
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EVENT_CMD, & usCmd, sizeof(usCmd)) ;
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EVENT_DATA, pcData, usDataLen) ;
	usReason = htons(usReason);
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EVENT_REASON, &usReason, sizeof(usReason));
	usAssocId =htons(usAssocId) ;
	pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_EVENT_ASSOCID, & usAssocId, sizeof(usAssocId)) ;
	if(iMacListNum >= 0)
		pbFrame = AddElem(pbFrame, HOSTAPD_ELEMID_COMMON_MACLIST, pucMacList, 6*iMacListNum);

	bRet = HostapdSend(drv->hapd, NULL, EV_HOSTAPD_SOCKET_EVENT, pbOut, usOutLen) ;
	if(bRet == TRUE)
		hostapd_bss_stats_inc(drv->hapd->iface->interfaceindex, drv->hapd->bssindex, SendAcEvent);

	os_free(pbOut) ;

	return bRet ;
}

static int madwifi_get_wpa_ie(struct madwifi_driver_data *drv, struct ieee80211req_wpaie * ie)
{
	if(drv == NULL
		|| ie == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	os_memset(ie->wpa_ie, 0, IEEE80211_MAX_OPT_IE) ;
	os_memset(ie->rsn_ie, 0, IEEE80211_MAX_OPT_IE) ;

	if (set80211priv(drv, IEEE80211_IOCTL_GETWPAIE, ie, sizeof(* ie))) {
		wpa_printf(MSG_ERROR, "%s: Failed to get WPA/RSN IE",
			   __func__);
		printf("Failed to get WPA/RSN information element.\n");
		return -1;		/* XXX not right */
	}

	return 0 ;
}


static int madwifi_get_associd(struct madwifi_driver_data * drv, u_int8_t * mac, u_int16_t * associd)
{
	IOCTL_DATA_T ioctl_data = {0} ;
	
	if(drv == NULL ||
		mac == NULL ||
		associd == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return -1 ;
	}

	ioctl_data.enIoctlType = IOCTL_GET_STA_ASSOCID ;
	os_memcpy(ioctl_data.unData.stGetAssocId.ucMac, mac, 6) ;
	if(set80211priv(drv, IEEE80211_IOCTL_COMMON, & ioctl_data, sizeof(IOCTL_DATA_T))){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, "MACSTR", get associd failed.\n", __func__, MAC2STR(mac)) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, "MACSTR", assoc id: %u.\n", 
		__func__, MAC2STR(ioctl_data.unData.stGetAssocId.ucMac), ioctl_data.unData.stGetAssocId.usAssocId) ;
	* associd = ioctl_data.unData.stGetAssocId.usAssocId ;
	
	return 0 ;
}


/************   为了获取每个VAP下的用户MAC列表，生成该函数，chary，2011.7.6   *********/
static int madwifi_get_user_list(struct madwifi_driver_data * drv, u_int8_t *pucMac, u_int32_t *pulMacNum)
{
	static u_int8_t buf[24*1024] = {0};
	struct iwreq iwr={0};
	uint8_t *cp;
	int len, mac_size, mac_num;

	if(drv == NULL
		|| pucMac == NULL
		|| pulMacNum == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point(%p, %p, %p) is NULL.\n", __func__, drv, pucMac, pulMacNum) ;
		return -1;
	}

	mac_size = *pulMacNum;
	os_memset(pucMac, 0, 6*mac_size);
	*pulMacNum = 0;

	os_memset(&iwr, 0, sizeof(iwr));
	os_strncpy(iwr.ifr_name, drv->iface, sizeof(iwr.ifr_name));
	
	os_memset(buf, 0, sizeof(buf));
	iwr.u.data.pointer = (void *) buf;
	iwr.u.data.length = sizeof(buf);
	if(ioctl(drv->ioctl_sock, IEEE80211_IOCTL_STA_INFO, &iwr) < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, %s: get sta info failed.\n", __func__, drv->iface);
		return -2;
	}
	
	len = iwr.u.data.length;
	if(len < sizeof(struct ieee80211req_sta_info))
		return 0;

	mac_num = 0;
	cp = buf;
	do{
		struct ieee80211req_sta_info *si = (struct ieee80211req_sta_info *) cp;

		if(mac_num >= mac_size){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, too many station.\n", __func__);
			return -3;
		}

		os_memcpy(pucMac+6*mac_num, si->isi_macaddr, 6);
		mac_num++;
		
		cp += si->isi_len;
		len -= si->isi_len;
	}while (len >= sizeof(struct ieee80211req_sta_info));

	*pulMacNum = mac_num;
  
	return 0;
}


static void
madwifi_wireless_event_wireless(struct madwifi_driver_data *drv,
					    char *data, int len)
{
	struct hostapd_data *hapd = drv->hapd;
	struct iw_event iwe_buf, *iwe = &iwe_buf;
	char *pos, *end, *custom, *buf;
	u16 reason = 0;
	static u8 mac_list[128][6] = {0};
	int mac_num = sizeof(mac_list)/6;

	pos = data;
	end = data + len;

	while (pos + IW_EV_LCP_LEN <= end) {
		/* Event data may be unaligned, so make a local, aligned copy
		 * before processing. */
		memcpy(&iwe_buf, pos, IW_EV_LCP_LEN);
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
					"cmd=0x%x len=%d\n", iwe->cmd, iwe->len) ;
		if (iwe->len <= IW_EV_LCP_LEN)
			return;

		custom = pos + IW_EV_POINT_LEN;
		if (drv->we_version > 18 &&
		    (iwe->cmd == IWEVMICHAELMICFAILURE ||
		     iwe->cmd == IWEVCUSTOM)) {
			/* WE-19 removed the pointer from struct iw_point */
			char *dpos = (char *) &iwe_buf.u.data.length;
			int dlen = dpos - (char *) &iwe_buf;
			memcpy(dpos, pos + IW_EV_LCP_LEN,
			       sizeof(struct iw_event) - dlen);
		} else {
			memcpy(&iwe_buf, pos, sizeof(struct iw_event));
			custom += IW_EV_POINT_OFF;
		}

		os_memset(mac_list, 0, sizeof(mac_list));
              if(madwifi_get_user_list(drv, mac_list, &mac_num) == 0){
			int i;
			
		  	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
				"%s, vap(%d/%d), mac_num(%d).", __func__, hapd->iface->interfaceindex, hapd->bssindex, mac_num);
			for(i = 0; i < mac_num; i++)
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
					"%s, sta%d:"MACSTR".", __func__, i, MAC2STR(mac_list[i]));
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, vap(%d/%d), madwifi_get_user_list failed.\n", __func__, hapd->iface->interfaceindex, hapd->bssindex) ;
			mac_num = -1;
		}
             
		switch (iwe->cmd) {
		case IWEVEXPIRED:
			reason = iwe->u.addr.sa_data[6];
			struct flow_ctl_ref	stFlowCtl = {0};	/*   AP流控，chary，2011-11-8  */
			BOOL ret = FALSE;
			
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, sta("MACSTR") expired, timeout: %d.\n", __func__, MAC2STR(iwe->u.addr.sa_data), reason) ;

			if(! NotifyEvent(drv, IWEVEXPIRED, (u8 *) iwe->u.addr.sa_data, ETH_ALEN, reason, 0, mac_list, mac_num))
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call NotifyStaDel failed.\n", __func__) ;
			
			/*   AP流控，chary，2011-11-8  */
			stFlowCtl.radio_id = hapd->iface->interfaceindex;
			stFlowCtl.vap_id = hapd->bssindex;
			memcpy(stFlowCtl.sta_mac, iwe->u.addr.sa_data, 6);

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
							"%s, the flow ctrl refrence is below: \n"
							"the sta("MACSTR") is from radio %d , vap %d. \n",
							__func__,
							MAC2STR(stFlowCtl.sta_mac),
							stFlowCtl.radio_id,
							stFlowCtl.vap_id);
			
			ret = SubmitOrder2Drv(&stFlowCtl, sizeof(struct flow_ctl_ref), ORDER_STA_DEL);
			
			if(FALSE == ret)
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, submit order to drv FAILED. \n", __func__);

			else
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s, submit order to drv SUCC. \n", __func__);

			/*********************************/
			break;
		case IWEVREGISTERED:{
			struct ieee80211req_wpaie ie = {0} ;
			u_int16_t associd = 0 ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, sta("MACSTR") registered, reassoc: %d.\n", __func__, MAC2STR(iwe->u.addr.sa_data), iwe->u.addr.sa_data[6]) ;

			os_memcpy(ie.wpa_macaddr, iwe->u.addr.sa_data, ETH_ALEN) ;
			if(madwifi_get_wpa_ie(drv, & ie) ||
				madwifi_get_associd(drv, iwe->u.addr.sa_data, & associd)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call madwifi_get_wpa_ie failed, or get associd failed.\n", __func__) ;
				break ;
			}
			
			reason = iwe->u.addr.sa_data[6];
			if(! NotifyEvent(drv, IWEVREGISTERED, & ie, sizeof(ie), reason, associd, mac_list, mac_num)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call NotifyStaAdd failed.\n", __func__) ;
				break ;
			}
			
			break;
		}
		case IWEVCUSTOM:
			if (custom + iwe->u.data.length > end)
				return;
			buf = VM_MALLOC(iwe->u.data.length + 1);
			if (buf == NULL)
				return;		/* XXX */
			memcpy(buf, custom, iwe->u.data.length);
			buf[iwe->u.data.length] = '\0';
			if(! NotifyEvent(drv, IWEVCUSTOM, buf, strlen(buf) + 1, 0, 0, mac_list, -1))
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call NotifyEventCustom failed.\n", __func__) ;
			VM_FREE(buf);
			break;
		}

		pos += iwe->len;
	}
}


static void
madwifi_wireless_event_rtm_newlink(struct madwifi_driver_data *drv,
					       struct nlmsghdr *h, int len)
{
	struct ifinfomsg *ifi;
	int attrlen, nlmsg_len, rta_len;
	struct rtattr * attr;

	if (len < (int) sizeof(*ifi))
		return;

	ifi = NLMSG_DATA(h);

	if (ifi->ifi_index != drv->ifindex)
		return;

	nlmsg_len = NLMSG_ALIGN(sizeof(struct ifinfomsg));

	attrlen = h->nlmsg_len - nlmsg_len;
	if (attrlen < 0)
		return;

	attr = (struct rtattr *) (((char *) ifi) + nlmsg_len);

	rta_len = RTA_ALIGN(sizeof(struct rtattr));
	while (RTA_OK(attr, attrlen)) {
		if (attr->rta_type == IFLA_WIRELESS) {
			madwifi_wireless_event_wireless(
				drv, ((char *) attr) + rta_len,
				attr->rta_len - rta_len);
		}
		attr = RTA_NEXT(attr, attrlen);
	}
}

static void
madwifi_wireless_event_receive(int sock, void *eloop_ctx, void *sock_ctx)
{
#define EVENT_LEN_RESERVE (sizeof(HOSTAPD_HEAD_T)+sizeof(HOSTAPD_ELEM_T)+sizeof(eloop_ctx)+sizeof(HOSTAPD_ELEM_T)+sizeof(sock_ctx)+sizeof(HOSTAPD_ELEM_T))
	char buf[EVENT_LEN_RESERVE+256];
	int left;
	struct sockaddr_nl from;
	socklen_t fromlen;
	HOSTAPD_HEAD_T * pHead = NULL ;
	HOSTAPD_ELEM_T * pElem = NULL ;
	TPID tReceiver = {0} ;
	struct hostapd_data * hapd = NULL ;

	if(eloop_ctx == NULL
		|| (hapd = ((struct madwifi_driver_data *)eloop_ctx)->hapd) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
		
	fromlen = sizeof(from);
	left = recvfrom(sock, buf+EVENT_LEN_RESERVE, sizeof(buf)-EVENT_LEN_RESERVE, MSG_DONTWAIT,
			(struct sockaddr *) &from, &fromlen);
	if (left < 0) {
		if (errno != EINTR && errno != EAGAIN)
			perror("recvfrom(netlink)");
		return;
	}

#if 0
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
		"%s, recv data: %d.\n", __func__, left) ;
#endif
	hostapd_bss_stats_inc(hapd->iface->interfaceindex, hapd->bssindex, RecvDriverEvent);

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

	/*设置网络数据包*/
	pElem = (unsigned char *)pElem + pElem->dwLength ;
	pElem->dwElemId = HOSTAPD_ELEMID_SOCKET_DATA ;
	pElem->dwLength = sizeof(HOSTAPD_ELEM_T) + left ;

	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, get local pid failed.\n", __func__) ;
		return  ;
	}

	if(! VmASend(EV_HOSTAPD_SOCKET_EVENT_WTP, buf, EVENT_LEN_RESERVE+left,  tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, send socket_radius failed.\n", __func__) ;
		return ;
	}
	hostapd_bss_stats_inc(hapd->iface->interfaceindex, hapd->bssindex, SendLocalEvent);

	return ;
#undef EVENT_LEN_RESERVE
}

void
madwifi_wireless_event_receiveA(void *eloop_ctx, void *sock_ctx, u8 * data, int data_len)
{
	char buf[256];
	int left;
	struct nlmsghdr *h;
	struct madwifi_driver_data *drv = eloop_ctx;

#if 0
	fromlen = sizeof(from);
	left = recvfrom(sock, buf, sizeof(buf), MSG_DONTWAIT,
			(struct sockaddr *) &from, &fromlen);
	if (left < 0) {
		if (errno != EINTR && errno != EAGAIN)
			perror("recvfrom(netlink)");
		return;
	}
#else
	if(data == NULL || data_len < 0 || data_len > sizeof(buf))
		return ;

	os_memcpy(buf, data, data_len) ;
	left = data_len ;
#endif
	h = (struct nlmsghdr *) buf;
	while (left >= (int) sizeof(*h)) {
		int len, plen;

		len = h->nlmsg_len;
		plen = len - sizeof(*h);
		if (len > left || plen < 0) {
			printf("Malformed netlink message: "
			       "len=%d left=%d plen=%d\n",
			       len, left, plen);
			break;
		}

		switch (h->nlmsg_type) {
		case RTM_NEWLINK:
			madwifi_wireless_event_rtm_newlink(drv, h, plen);
			break;
		}

		len = NLMSG_ALIGN(len);
		left -= len;
		h = (struct nlmsghdr *) ((char *) h + len);
	}

	if (left > 0) {
		printf("%d extra bytes in the end of netlink message\n", left);
	}
}

static int
madwifi_get_we_version(struct madwifi_driver_data *drv)
{
	struct iw_range *range;
	struct iwreq iwr;
	int minlen;
	size_t buflen;

	drv->we_version = 0;

	/*
	 * Use larger buffer than struct iw_range in order to allow the
	 * structure to grow in the future.
	 */
	buflen = sizeof(struct iw_range) + 500;
	range = wpa_zalloc(buflen);
	if (range == NULL)
		return -1;

	memset(&iwr, 0, sizeof(iwr));
	strncpy(iwr.ifr_name, drv->iface, IFNAMSIZ);
	iwr.u.data.pointer = (caddr_t) range;
	iwr.u.data.length = buflen;

	minlen = ((char *) &range->enc_capa) - (char *) range +
		sizeof(range->enc_capa);

	if (ioctl(drv->ioctl_sock, SIOCGIWRANGE, &iwr) < 0) {
		perror("ioctl[SIOCGIWRANGE]");
		VM_FREE(range);
		return -1;
	} else if (iwr.u.data.length >= minlen &&
		   range->we_version_compiled >= 18) {
		wpa_printf(MSG_DEBUG, "SIOCGIWRANGE: WE(compiled)=%d "
			   "WE(source)=%d enc_capa=0x%x",
			   range->we_version_compiled,
			   range->we_version_source,
			   range->enc_capa);
		drv->we_version = range->we_version_compiled;
	}

	VM_FREE(range);
	return 0;
}

/*
 功能：IOCTL返回值封装
*/
BYTE * IoctlReturnAdd(BYTE * pbFrame, DWORD dwIoctlId, int iIoctlRet, BYTE * pbMac)
{
	BYTE abIoctlData[sizeof(int) + ETH_ALEN] = {0} ;

	if(pbFrame == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, point is NULL.\n", __func__) ;
		return NULL ;
	}

	iIoctlRet = htonl(iIoctlRet) ;
	os_memcpy(abIoctlData, & iIoctlRet, sizeof(int)) ;
	if(pbMac)
		os_memcpy(abIoctlData + sizeof(int), pbMac, ETH_ALEN) ;

	return AddElem(pbFrame, dwIoctlId, abIoctlData, sizeof(int) + ETH_ALEN) ;
}




BOOL SubmitOrder2Drv(struct flow_ctl_ref *pstFlowCtl, WORD16 wLength, BYTE	order)
{
	WORD32	ulRadioId = 0;
	WORD32	ulVapId = 0;
	char		cmd[256];
	BYTE	zero_mac[6] = {0};
	int	call_ret = 0;
	
	/*   入参合法性检查   */
	if((NULL == pstFlowCtl))
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the flow-ctl msg is invalid. \n", __func__);
			return	FALSE;
		}

	if((order != ORDER_STA_ADD) &&
		(order != ORDER_STA_DEL) &&
		(order != ORDER_VAP_ADD)&&
		(order != ORDER_VAP_DEL))
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the oder is incorrect. it's %d.\n", __func__, order);
			return	FALSE;
		}

	ulRadioId = pstFlowCtl->radio_id;
	ulVapId = pstFlowCtl->vap_id;

	if(ulRadioId > MAX_INTERFACES)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the radio-id is out of range. \n", __func__);
			return	FALSE;
		}

	if(ulVapId > MAX_BSSES)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the vap-id is out of range. \n", __func__);
			return	FALSE;
		}

	memset(cmd, 0 , sizeof(cmd));
	memset(zero_mac, 0, sizeof(zero_mac));
	
	switch(order)
	{
		case	ORDER_STA_ADD:
			if(!memcmp(zero_mac, pstFlowCtl->sta_mac, 6))
				{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the sta mac is invalid. \n", __func__);
					return	FALSE;
				}
			
			else
				{
					sprintf(cmd, "flowctrl addsta %d %d "MACSTR" %d %d %d",
							ulRadioId, 
							ulVapId, 
							MAC2STR(pstFlowCtl->sta_mac),
							pstFlowCtl->up_rate,
							pstFlowCtl->down_rate,
							pstFlowCtl->burst_size);						
				}
			break;

		case	ORDER_STA_DEL:
			if(!memcmp(zero_mac, pstFlowCtl->sta_mac, 6))
				{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, the sta mac is invalid. \n", __func__);
					return	FALSE;
				}
			else
				{
					sprintf(cmd, "flowctrl delsta %d %d "MACSTR"",
							ulRadioId, 
							ulVapId, 
							MAC2STR(pstFlowCtl->sta_mac));
				}
			break;

		case	ORDER_VAP_ADD:
			sprintf(cmd, "flowctrl addvap %d %d %d %d %d",
					ulRadioId, 
					ulVapId, 
					pstFlowCtl->up_rate,
					pstFlowCtl->down_rate,
					pstFlowCtl->burst_size);
			
			break;

		case	ORDER_VAP_DEL:
			sprintf(cmd, "flowctrl delvap %d %d",
					ulRadioId, 
					ulVapId);
			
			break;

		default:
			break;		

	}

	call_ret = system(cmd);
	if(call_ret !=0 )
	{
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, execute shell(%s) FAILED. \n", __func__, cmd);
		return	FALSE;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s, execute shell(%s) SUCC. \n", __func__, cmd);
	return	TRUE;
}





int
set80211priv(struct madwifi_driver_data *drv, int op, void *data, int len)
{
	struct iwreq iwr;

	memset(&iwr, 0, sizeof(iwr));
	strncpy(iwr.ifr_name, drv->iface, IFNAMSIZ);
	if (len < IFNAMSIZ) {
		/*
		 * Argument data fits inline; put it there.
		 */
		memcpy(iwr.u.name, data, len);
	} else {
		/*
		 * Argument data too big for inline transfer; setup a
		 * parameter block instead; the kernel will transfer
		 * the data for the driver.
		 */
		iwr.u.data.pointer = data;
		iwr.u.data.length = len;
	}

	if (ioctl(drv->ioctl_sock, op, &iwr) < 0) {
#ifdef MADWIFI_NG
		int first = IEEE80211_IOCTL_SETPARAM;
		static const char *opnames[] = {
			"ioctl[IEEE80211_IOCTL_SETPARAM]",
			"ioctl[IEEE80211_IOCTL_GETPARAM]",
			"ioctl[IEEE80211_IOCTL_SETMODE]",
			"ioctl[IEEE80211_IOCTL_GETMODE]",
			"ioctl[IEEE80211_IOCTL_SETWMMPARAMS]",
			"ioctl[IEEE80211_IOCTL_GETWMMPARAMS]",
			"ioctl[IEEE80211_IOCTL_SETCHANLIST]",
			"ioctl[IEEE80211_IOCTL_GETCHANLIST]",
			"ioctl[IEEE80211_IOCTL_CHANSWITCH]",
			"ioctl[IEEE80211_IOCTL_GET_APPIEBUF]",
			"ioctl[IEEE80211_IOCTL_SET_APPIEBUF]",
			"ioctl[IEEE80211_IOCTL_GETSCANRESULTS]",
			"ioctl[IEEE80211_IOCTL_FILTERFRAME]",
			"ioctl[IEEE80211_IOCTL_GETCHANINFO]",
			"ioctl[IEEE80211_IOCTL_SETOPTIE]",
			"ioctl[IEEE80211_IOCTL_GETOPTIE]",
			"ioctl[IEEE80211_IOCTL_SETMLME]",
			NULL,
			"ioctl[IEEE80211_IOCTL_SETKEY]",
			NULL,
			"ioctl[IEEE80211_IOCTL_DELKEY]",
			NULL,
			"ioctl[IEEE80211_IOCTL_ADDMAC]",
			NULL,
			"ioctl[IEEE80211_IOCTL_DELMAC]",
			NULL,
			"ioctl[IEEE80211_IOCTL_WDSMAC]",
			NULL,
			"ioctl[IEEE80211_IOCTL_WDSDELMAC]",
			NULL,
			"ioctl[IEEE80211_IOCTL_KICKMAC]",
		};
#else /* MADWIFI_NG */
		int first = IEEE80211_IOCTL_SETPARAM;
		static const char *opnames[] = {
			"ioctl[IEEE80211_IOCTL_SETPARAM]",
			"ioctl[IEEE80211_IOCTL_GETPARAM]",
			"ioctl[IEEE80211_IOCTL_SETKEY]",
			"ioctl[SIOCIWFIRSTPRIV+3]",
			"ioctl[IEEE80211_IOCTL_DELKEY]",
			"ioctl[SIOCIWFIRSTPRIV+5]",
			"ioctl[IEEE80211_IOCTL_SETMLME]",
			"ioctl[SIOCIWFIRSTPRIV+7]",
			"ioctl[IEEE80211_IOCTL_SETOPTIE]",
			"ioctl[IEEE80211_IOCTL_GETOPTIE]",
			"ioctl[IEEE80211_IOCTL_ADDMAC]",
			"ioctl[SIOCIWFIRSTPRIV+11]",
			"ioctl[IEEE80211_IOCTL_DELMAC]",
			"ioctl[SIOCIWFIRSTPRIV+13]",
			"ioctl[IEEE80211_IOCTL_CHANLIST]",
			"ioctl[SIOCIWFIRSTPRIV+15]",
			"ioctl[IEEE80211_IOCTL_GETRSN]",
			"ioctl[SIOCIWFIRSTPRIV+17]",
			"ioctl[IEEE80211_IOCTL_GETKEY]",
		};
#endif /* MADWIFI_NG */
		int idx = op - first;
		if (first <= op &&
		    idx < (int) (sizeof(opnames) / sizeof(opnames[0])) &&
		    opnames[idx])
			perror(opnames[idx]);
		else
			perror("ioctl[unknown???]");

		return -1;
	}
	return 0;
}

int
set80211param(struct madwifi_driver_data *drv, int op, int arg)
{
	struct iwreq iwr;

	memset(&iwr, 0, sizeof(iwr));
	strncpy(iwr.ifr_name, drv->iface, IFNAMSIZ);
	iwr.u.mode = op;
	memcpy(iwr.u.name+sizeof(__u32), &arg, sizeof(arg));

	if (ioctl(drv->ioctl_sock, IEEE80211_IOCTL_SETPARAM, &iwr) < 0) {
		perror("ioctl[IEEE80211_IOCTL_SETPARAM]");
		wpa_printf(MSG_DEBUG, "%s: Failed to set parameter (op %d "
			   "arg %d)", __func__, op, arg);
		return -1;
	}
	return 0;
}

BOOL MadwifiInit(BYTE bInterfaceIndex , BYTE bBssIndex , char * pcBridge, DWORD dwBridgeLen)
{
	struct hostapd_data * hapd = NULL ;
	struct madwifi_driver_data * pstDriver = NULL ;
	struct ifreq ifr ;
	struct sockaddr_nl local ;
	int s = -1 ;

	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES
		|| dwBridgeLen > IFNAMSIZ){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u), or dwDeviceNameLen(%u) is over(%u).\n", __func__ , bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES, dwBridgeLen, IFNAMSIZ) ;
		return FALSE ;
	}
	
	if(g_stWtp.iface[bInterfaceIndex] == NULL
		|| (hapd = g_stWtp.iface[bInterfaceIndex]->bss[bBssIndex]) == NULL
		|| (pstDriver = hapd->driver) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	if(! MadwifiDeinit(bInterfaceIndex, bBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, call MadwifiDeinit failed.\n", __func__) ;
		return FALSE ;
	}

	/*init sock_xmit*/
	pstDriver->sock_xmit = l2_packet_init(pstDriver->iface, NULL, ETH_P_EAPOL,
					NULL, pstDriver, 1);
	if (pstDriver->sock_xmit == NULL)
		goto bad;

	if (l2_packet_get_own_addr(pstDriver->sock_xmit, hapd->own_addr))
		goto bad;

	/*init sock_recv*/
	if (pcBridge && dwBridgeLen){
		char pcBridgeName[IFNAMSIZ+1] ;

		os_memcpy(pcBridgeName, pcBridge, dwBridgeLen) ;
		pcBridgeName[dwBridgeLen] = '\0' ;
		
		pstDriver->sock_recv = l2_packet_init(pcBridgeName, NULL,
						ETH_P_EAPOL, NULL, pstDriver,1);
		
		if (pstDriver->sock_recv == NULL)
			goto bad;
	}
	else{
		pstDriver->sock_recv = pstDriver->sock_xmit;
	}
	
#ifndef 	_MSC_VER
	/*init wext_sock*/
	madwifi_get_we_version(pstDriver) ; 

	pstDriver->wext_sock = -1;

	s = socket(PF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
	if (s < 0) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, socket(PF_NETLINK,SOCK_RAW,NETLINK_ROUTE).\n", __func__) ;
		goto bad ;
	}

	memset(&local, 0, sizeof(local));
	local.nl_family = AF_NETLINK;
	local.nl_groups = RTMGRP_LINK;
	if (bind(s, (struct sockaddr *) &local, sizeof(local)) < 0) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bind(netlink).\n", __func__) ;
		close(s);
		goto bad ;
	}

	eloop_register_read_sock(s, madwifi_wireless_event_receive, pstDriver, NULL);
#endif

	pstDriver->wext_sock = s;

	return TRUE ;

bad :
	if(pstDriver->wext_sock >= 0){
		eloop_unregister_read_sock(pstDriver->wext_sock) ;
		close(pstDriver->wext_sock) ;
		pstDriver->wext_sock = -1 ;
	}
	if(pstDriver->sock_recv != NULL && pstDriver->sock_recv != pstDriver->sock_xmit){
		l2_packet_deinit(pstDriver->sock_recv) ;
		pstDriver->sock_recv = NULL ;
	}
	if (pstDriver->sock_xmit != NULL){
		l2_packet_deinit(pstDriver->sock_xmit);
		pstDriver->sock_xmit = pstDriver->sock_recv = NULL ;
	}
	
	return FALSE ;
}

BOOL MadwifiDeinit(BYTE bInterfaceIndex , BYTE bBssIndex)
{
	struct hostapd_data * hapd = NULL ;
	struct madwifi_driver_data * pstDriver = NULL ;
		
	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u).\n", __func__ , bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES) ;
		return FALSE ;
	}
	
	if(g_stWtp.iface[bInterfaceIndex] == NULL
		|| (hapd = g_stWtp.iface[bInterfaceIndex]->bss[bBssIndex]) == NULL
		|| (pstDriver = hapd->driver) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	/*deinit wext_sock*/
	if(pstDriver->wext_sock >= 0){
		eloop_unregister_read_sock(pstDriver->wext_sock);
		close(pstDriver->wext_sock);
		pstDriver->wext_sock = -1 ;
	}

	/*deinit sock_xmit, sock_recv*/
	if (pstDriver->sock_recv != NULL && pstDriver->sock_recv != pstDriver->sock_xmit){
		l2_packet_deinit(pstDriver->sock_recv) ;
		pstDriver->sock_recv = NULL ;
	}
	if (pstDriver->sock_xmit != NULL){
		l2_packet_deinit(pstDriver->sock_xmit) ;
		pstDriver->sock_xmit = pstDriver->sock_recv = NULL ;
	}

	return TRUE ;
}

int
madwifi_get_seqnum(const char *ifname, void *priv, const u8 *addr, int idx,
		   u8 *seq)
{
	struct madwifi_driver_data *drv = priv;
	struct hostapd_data *hapd = drv->hapd;
	struct ieee80211req_key wk;

	memset(&wk, 0, sizeof(wk));
	if (addr == NULL)
		memset(wk.ik_macaddr, 0xff, IEEE80211_ADDR_LEN);
	else
		memcpy(wk.ik_macaddr, addr, IEEE80211_ADDR_LEN);
	wk.ik_keyix = idx;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
		"%s: addr="MACSTR", idx=%d\n", __func__, MAC2STR(wk.ik_macaddr), wk.ik_keyix) ;

	if (set80211priv(priv, IEEE80211_IOCTL_GETKEY, &wk, sizeof(wk))) {
		wpa_printf(MSG_DEBUG, "%s: Failed to get encryption data "
			   "(addr " MACSTR " key_idx %d)",
			   __func__, MAC2STR(wk.ik_macaddr), idx);
		return -1;
	}

#ifdef WORDS_BIGENDIAN
	{
		/*
		 * wk.ik_keytsc is in host byte order (big endian), need to
		 * swap it to match with the byte order used in WPA.
		 */
		int i;
		u8 tmp[WPA_KEY_RSC_LEN];
		memcpy(tmp, &wk.ik_keytsc, sizeof(wk.ik_keytsc));
		for (i = 0; i < WPA_KEY_RSC_LEN; i++) {
			seq[i] = tmp[WPA_KEY_RSC_LEN - i - 1];
		}
	}
#else /* WORDS_BIGENDIAN */
	memcpy(seq, &wk.ik_keytsc, sizeof(wk.ik_keytsc));
#endif /* WORDS_BIGENDIAN */
	return 0;
}

/*字符串pcIfaceName，以'\0'结束*/
static BOOL rsn_preauth_iface_add(BYTE bInterfaceIndex , BYTE bBssIndex, char * pcIfaceName)
{
	struct hostapd_data * hapd = NULL ; 
	struct rsn_preauth_interface *piface;

	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES
		|| pcIfaceName == NULL
		|| os_strlen(pcIfaceName) > IFNAMSIZ){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u), point(%p) is NULL, bIfaceNameLen(%u) is over(%u).\n", __func__ , bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES, pcIfaceName, os_strlen(pcIfaceName), IFNAMSIZ) ;
		return FALSE ;
	}
	
	if(g_stWtp.iface[bInterfaceIndex] == NULL
		||(hapd = g_stWtp.iface[bInterfaceIndex]->bss[bBssIndex]) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	piface = os_zalloc(sizeof(struct rsn_preauth_interface));
	if (piface == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s(%d), no memory.\n", __func__, __LINE__) ;
		goto bad;
	}
	piface->hapd = hapd;
	os_memcpy(piface->ifname, pcIfaceName, os_strlen(pcIfaceName)+1) ;

	piface->l2 = l2_packet_init(piface->ifname, NULL, ETH_P_PREAUTH,
				    NULL, piface, 1);
	if (piface->l2 == NULL) {
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, Failed to open register layer 2 access to ETH_P_PREAUTH.\n", __func__);
		goto bad;
	}

	piface->next = hapd->preauth_iface;
	hapd->preauth_iface = piface;
	
	return TRUE ;

bad:
	if(piface)
		VM_FREE(piface);
	
	return FALSE;
}


BOOL rsn_preauth_iface_deinit(BYTE bInterfaceIndex , BYTE bBssIndex)
{
	struct hostapd_data *hapd = NULL ;
	struct rsn_preauth_interface *piface, *prev;

	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES
		|| g_stWtp.iface[bInterfaceIndex] == NULL
		||(hapd = g_stWtp.iface[bInterfaceIndex]->bss[bBssIndex]) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u), or poin is NULL.\n", __func__ , bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES) ;
		return FALSE ;
	}

	piface = hapd->preauth_iface;
	hapd->preauth_iface = NULL;
	while (piface) {
		prev = piface;
		piface = piface->next;
		l2_packet_deinit(prev->l2);
		prev->l2 = NULL ;
		VM_FREE(prev);
	}

	return TRUE ;
}

BOOL rsn_preauth_iface_init(BYTE bInterfaceIndex , BYTE bBssIndex, char * pcInterfaces , WORD32 dwInterfacesLen)
{
	struct hostapd_data *hapd = NULL ;
	char *tmp, *start, *end;

	if(bInterfaceIndex >= MAX_INTERFACES
		|| bBssIndex >= MAX_BSSES
		|| g_stWtp.iface[bInterfaceIndex] == NULL
		||(hapd = g_stWtp.iface[bInterfaceIndex]->bss[bBssIndex]) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, bInterfaceIndex(%u) is over(%u), or bBssIndex(%u) is over(%u), or poin is NULL.\n", __func__ , bInterfaceIndex, MAX_INTERFACES, bBssIndex, MAX_BSSES) ;
		return FALSE ;
	}

	if(! rsn_preauth_iface_deinit(bInterfaceIndex, bBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, call rsn_preauth_iface_deinit failed.\n", __func__) ;
		return FALSE ;
	}

#if 0
{
	char acData[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06} ;
	u16 usDataLen = 6 ;
	
	NotifyEvent(hapd->driver, IWEVEXPIRED, acData, usDataLen) ;

	acData[0] = 0x11 ;
	NotifyEvent(hapd->driver, IWEVREGISTERED, acData, usDataLen) ;

	acData[0] = 0x21 ;
	NotifyEvent(hapd->driver, IWEVCUSTOM, acData, usDataLen) ;
}
#endif

	if (pcInterfaces == NULL || dwInterfacesLen == 0)
		return TRUE ;

	if((tmp = os_zalloc(dwInterfacesLen+1)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, poin is NULL.\n", __func__) ;
		return FALSE ;
	}
	os_memcpy(tmp, pcInterfaces, dwInterfacesLen) ;
	tmp[dwInterfacesLen] = '\0' ;

	start = tmp;
	for (;;) {
		while (*start == ' ')
			start++;
		if (*start == '\0')
			break;
		end = strchr(start, ' ');
		if (end)
			*end = '\0';

		if (rsn_preauth_iface_add(bInterfaceIndex, bBssIndex, start)) {
			rsn_preauth_iface_deinit(bInterfaceIndex, bBssIndex) ;
			os_free(tmp) ;
			return FALSE ;
		}

		if (end)
			start = end + 1;
		else
			break;
	}

	os_free(tmp) ;

	return TRUE ;
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
	WORD16 wOutLen = NULL ;
	TPID tReceiver = {0} ;
	BOOL bRet = FALSE ;

	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, call VmGetLocalPid failed.\n", __func__) ;
		return FALSE ;
	}

	os_memset(& stHostapdHead, 0xff, sizeof(stHostapdHead)) ;
	if(from){
		stHostapdHead.ucFromInterface = from->iface->interfaceindex ;
		stHostapdHead.ucFromBss = from->bssindex ;
	}
	if(to){/*发送至本地AP*/
		stHostapdHead.ucToInterface = to->iface->interfaceindex ;
		stHostapdHead.ucToBss = to->bssindex ;
	}
	else{/*发送至AC*/
		tReceiver.wWtpId= 0;
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

	if(g_stWtp.sub_id == 0){
		/*
		if(! VmGetSacPidByPno(APP_HOSTAPD_PNO, & tReceiver)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, get hostapd pid of server AC failed .\n", __func__) ;
			bRet = FALSE ;
			goto bad ;
		}
		*/

	  	bRet = VmASend(wEvent, pbOut, wOutLen,  tReceiver) ;
	}
	else{/*发送给主设备，再由主设备转发至AC*/
		if(! (bRet = VmMSend(wEvent, pbOut, wOutLen, tReceiver.wPno))){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
				"%s, call VmMSend failed.\n", __func__) ;
		}
	}

bad :
	if(pbOut){
		os_free(pbOut) ;
		pbOut = NULL ;
	}

	return bRet ;
}

/*转发处理：若不需本地处理，则返回TRUE；若需本地处理，返回FALSE；*/
BOOL HostapdTransmit(WORD16 wEvent, BYTE *pbyBody, WORD16 wLen, BYTE *pbyResv, WORD16 wResv, BYTE *pbyProcData)
{
#define IS_IF_VALID(_IF) ((_IF == 0xff) || (_IF >= 0 && _IF < MAX_INTERFACES))
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	TPID tReceiver = {0} ;

	/*不转发非HOSTAPD消息*/
	if(! (wEvent >= EV_HOSTAPD_BEGIN && wEvent < EV_HOSTAPD_BEGIN+1000))
		return FALSE ;
	
	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, call VmGetLocalPid failed, event(%u).\n", __func__, wEvent) ;
		return FALSE ;
	}
	
	if(wEvent == EV_HOSTAPD_WTP_INIT){
		if(g_stWtp.sub_id == 0){
			return FALSE ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
				"%s, slave wtp recv wrong event(%u): EV_HOSTAPD_WTP_INIT.\n", __func__, wEvent) ;
			return TRUE ;
		}
	}
	else if(wEvent == EV_HOSTAPD_WTP_SLAVE_INIT){
		if(g_stWtp.sub_id == 0){
			if(! VmMSend(wEvent, pbyBody, wLen, tReceiver.wPno)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
					"%s, call VmMSend failed, event(%u).\n", __func__, wEvent) ;
			}
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
					"%s, transmit down-event(%u) success.\n", __func__, wEvent) ;
			}
			return TRUE ;
		}
		else{
			return FALSE ;
		}
	}

	if((pstHostapdHead = pbyBody) == NULL
		|| wLen < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point(%p) is NULL, or len(%d) is too short, event(%u).\n", __func__, pstHostapdHead, wLen, wEvent) ;
		return FALSE ;
	}

	if(! IS_IF_VALID(pstHostapdHead->ucToInterface)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, to_interface error, (%d, %d)-->(%d, %d), event(%u).\n", 
			__func__, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, pstHostapdHead->ucToInterface, pstHostapdHead->ucToBss, wEvent) ;
		return FALSE ;
	}

	if(pstHostapdHead->ucToInterface == 0xff){/*上行包转发处理*/
		tReceiver.wWtpId= 0;
		
		if(g_stWtp.sub_id != 0){/*非主设备不具备上行包转发能力*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
				"%s, this wtp can not transmit up-packet, (%d, %d)-->(%d, %d), event(%u).\n", 
				__func__, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, pstHostapdHead->ucToInterface, pstHostapdHead->ucToBss, wEvent) ;
			return FALSE ;
		}
		
		/*转发至AC*/
		if(! VmASend(wEvent, pbyBody, wLen, tReceiver)){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
				"%s, call VmASend failed, event(%u).\n", __func__, wEvent) ;
		}
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
				"%s, transmit up-event(%u) success.\n", __func__, wEvent) ;
		}
		
		return TRUE ;
	}
	else{/*下行包转发处理*/
		int to_sub_wtp = -1 ;

		/*获取目的设备子设备号*/
		to_sub_wtp = VmIsIfMaster(pstHostapdHead->ucToInterface) ? 0 : 1 ;

		if(to_sub_wtp != g_stWtp.sub_id){/*目的子设备并非本子设备，需转发*/
			if(g_stWtp.sub_id != 0){/*非主设备不具备下行包转发能力*/
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
					"%s, this wtp can not transmit down-packet, (%d, %d)-->(%d, %d), event(%u).\n", 
					__func__, pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, pstHostapdHead->ucToInterface, pstHostapdHead->ucToBss, wEvent) ;
				return FALSE ;
			}
			
			/*转发至从设备*/
			if(! VmMSend(wEvent, pbyBody, wLen, tReceiver.wPno)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
					"%s, call VmMSend failed, event(%u).\n", __func__, wEvent) ;
			}
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
					"%s, transmit down-event(%u) success.\n", __func__, wEvent) ;
			}
			
			return TRUE ;
		}
	}

	return FALSE ;
#undef IS_IF_VALID
}
