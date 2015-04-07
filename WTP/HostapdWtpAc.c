/******************************************************************************
模块名      : HOSTAPD
文件名      : HostapdWtpAc.c
相关文件    :
实现功能    : WTP侧的HOSTAPD主线程：接收AC侧消息，并作相应处理
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/29  叶恩云      创建
******************************************************************************/

#include "includes.h"
#include "common.h"
#include "OssApi.h"
#include "ac_public.h"
#include "hostapd_wtp.h"
#include "HostapdSocket.h"
#include "compat.h"
#include "net80211/ieee80211_ioctl.h"
#include "l2_packet.h"
#include "wireless_copy.h"
#include "hostapd_wtp_stats.h"

static BOOL OnWtpInit() ;
static BOOL OnStartVap(BYTE * pbData, WORD16 wLength);
static BOOL OnStopVap(BYTE * pbData, WORD16 wLength);

/*消息接收处理，其中的pbData 包括HOSTAPD_HEAD*/
static BOOL OnIoctl(BYTE * pbData , WORD16 wLength) ;
static BOOL OnEapol(BYTE * pbData , WORD16 wLength) ;
static BOOL OnPreauth(BYTE * pbData , WORD16 wLength) ;
static BOOL OnCreateVap(BYTE * pbData, WORD16 wLength) ;
static BOOL OnDestroyVap(BYTE * pbData, WORD16 wLength) ;
static BOOL OnEvent(BYTE * pbData, WORD16 wLength) ;
static BOOL OnL2(BYTE * pbData, WORD16 wLength) ;
static BOOL SendMsgAck(HOSTAPD_HEAD_T * pstHead, WORD16 wEvent);

static BOOL OnAddUser(BYTE * pbData, WORD16 wLength);

void ProcEntryHostapdWtpAc(WORD16 wEvent, BYTE *pbyBody, WORD16 wLen, BYTE *pbyResv, WORD16 wResv, BYTE *pbyProcData)
{
	TPID	stPid;
	HOSTAPD_HEAD_T * pstHead = NULL;
	long i ;
	
	if(pbyBody == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", pbyBody) ;
		return ;
	}
#if 0
	printf("receivce event(%u), len(%u): \n", wEvent, wLen) ;
	for(i = 1 ; i <= wLen ; i ++){
		printf("%02x.", pbyBody[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
#endif
	switch(VmProcState()){
	case AC_PROC_IDLE :
		switch(wEvent){
		case EV_MASTER_POWERON :
			/*获取当前子设备ID*/
			g_stWtp.sub_id = VmIsMaster() ? 0 : 1 ;
			
			VmProcUpdateState(AC_PROC_WORK);
			VmPowerOnAck(TRUE) ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, hostapd power on success.\n", __func__) ;
			break ;
		default :
			break ;
		}
		break ;
	case AC_PROC_WORK :
		if((HostapdTransmit(wEvent, pbyBody, wLen, pbyResv, wResv, pbyProcData)) == TRUE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
				"%s, transmit message(%d), len(%d).\n", __func__, wEvent, wLen) ;
			break ;
		}
		
		switch(wEvent){
		case EV_HOSTAPD_WTP_INIT :
		case EV_HOSTAPD_WTP_SLAVE_INIT :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): init %s wtp.\n", __func__, wEvent, wEvent == EV_HOSTAPD_WTP_INIT ? "main" : "slave") ;

			if((g_stWtp.sub_id == 0 && wEvent == EV_HOSTAPD_WTP_SLAVE_INIT)
				|| (g_stWtp.sub_id != 0 && wEvent == EV_HOSTAPD_WTP_INIT)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, %s wtp recv wrong event(%d).\n", __func__, g_stWtp.sub_id == 0 ? "main" : "slave", wEvent) ;
				break ;
			}
			
			if(! OnWtpInit()){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnWtpInit failed.\n", __func__) ;
			}

			SendMsgAck(NULL, wEvent);
			break ;
		case EV_HOSTAPD_VAP_CREATE :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): create vap.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnCreateVap(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnCreateVap failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			DumpDevices() ;
			break ;
		case EV_HOSTAPD_VAP_DESTROY :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): destroy vap.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnDestroyVap(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnDestroyVap failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			DumpDevices() ;
			break ;
		case EV_HOSTAPD_VAP_START :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): start vap.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnStartVap(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnStartVap failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			break ;
		case EV_HOSTAPD_VAP_STOP :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): stop vap.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnStopVap(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnStopVap failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			break ;

		/*  AP流控，chary，2011-11-8  */
		case EV_HOSTAPD_ADD_USER:
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): add QOS user.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnAddUser(pbyBody, wLen))
				{
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
									"%s, call OnAddUser failed.\n", __func__) ;
				}
			break ;
		/********************************/
		
		case EV_HOSTAPD_SOCKET_IOCTL :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): ioctl.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnIoctl(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnIoctl failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			break ;
		case EV_HOSTAPD_SOCKET_EAPOL :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): eapol.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnEapol(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnEapol failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			break ;
		case EV_HOSTAPD_SOCKET_PREAUTH :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, receive wEvent(%u): preauth.\n", __func__, wEvent) ;

			pstHead = pbyBody; 
			if(! OnPreauth(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnPreauth failed.\n", __func__) ;
			}
			SendMsgAck(pstHead, wEvent);
			
			break ;
		case EV_HOSTAPD_SOCKET_EVENT_WTP :
			if(! OnEvent(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnIoctlWtp failed.\n", __func__) ;
			}
			break ;
		case EV_HOSTAPD_SOCKET_L2 :
			if(! OnL2(pbyBody, wLen)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, call OnL2 failed.\n", __func__) ;
			}
			break ;

		/* 2008-10-31 pyy add: 增加线程保活报文处理*/
		case EV_PROC_ECHO_REQ:
			VmSender(&stPid);
			VmASend(EV_PROC_ECHO_RSP, NULL, 0, stPid);
			print_stats_all();
			break;
			
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN, 
				"%s, unknown event: %u.\n", __func__ , wEvent) ;
			break ;
		}

		
		break ;
	default :
		break ;
	}
}



static BOOL OnAddUser(BYTE * pbData, WORD16 wLength)
{
	struct flow_ctl_ref  stFlowCtl ={0};
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;

	BYTE	*pucStaMac = NULL;
	BYTE	*ptrFlowCtlRef = NULL;
	BYTE	elem_counter = 0;
	
	long lLength = 0 ;
	BYTE *pElem = NULL ;
	BOOL  ret = FALSE;
	
	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}


	/**********************************   解码，填充流控参数结构体  ******************************/
	pstHostapdHead = (HOSTAPD_HEAD_T *)pbData ;
	stFlowCtl.radio_id = pstHostapdHead->ucToInterface ;
	stFlowCtl.vap_id = pstHostapdHead->ucToBss ;

	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	memset(&stFlowCtl, 0 , sizeof(stFlowCtl));

	while(lLength > 0 && lLength < wLength){	/*  不断读取参数，直至消息完结 */
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
						"%s, left data(%d) elem_id(%u), elem_len(%u).\n", 
						__func__, 
						lLength, 
						pstHostapdElem->dwElemId, 
						pstHostapdElem->dwLength) ;
		
	switch(pstHostapdElem->dwElemId)
		{
			case	HOSTAPD_ELEMID_COMMON_MAC:
				pucStaMac = (BYTE *)(pstHostapdElem) + sizeof(HOSTAPD_ELEM_T);
				memcpy(stFlowCtl.sta_mac, pucStaMac, 6);
				elem_counter++;
				break;
		
			case	HOSTAPD_ELEMID_FC_UPRATE:
				ptrFlowCtlRef = (BYTE *)(pstHostapdElem) + sizeof(HOSTAPD_ELEM_T);
				memcpy(&(stFlowCtl.up_rate), ptrFlowCtlRef, sizeof(WORD32));
				stFlowCtl.up_rate = ntohl(stFlowCtl.up_rate);
				elem_counter++;
				break;

			case	HOSTAPD_ELEMID_FC_DOWNRATE:
				ptrFlowCtlRef = (BYTE *)(pstHostapdElem) + sizeof(HOSTAPD_ELEM_T);
				memcpy(&(stFlowCtl.down_rate), ptrFlowCtlRef, sizeof(WORD32));
				stFlowCtl.down_rate = ntohl(stFlowCtl.down_rate);
				elem_counter++;
				break;

			case	HOSTAPD_ELEMID_FC_BURSTSIZE:
				ptrFlowCtlRef = (BYTE *)(pstHostapdElem) + sizeof(HOSTAPD_ELEM_T);
				memcpy(&(stFlowCtl.burst_size), ptrFlowCtlRef, sizeof(WORD32));
				stFlowCtl.burst_size = ntohl(stFlowCtl.burst_size);
				elem_counter++;
				break;

			default:
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
								"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
				break;

		}

		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, 
					"%s, the flow ctrl refrence is below: \n"
					"the sta("MACSTR") is from radio %d , vap %d. \n"
					"uprate = %dkbps \n"
					"downrate = %dkbps \n"
					"burst_buf = %dKB \n",
					__func__,
					MAC2STR(stFlowCtl.sta_mac),
					stFlowCtl.radio_id,
					stFlowCtl.vap_id,
					stFlowCtl.up_rate,
					stFlowCtl.down_rate,
					stFlowCtl.burst_size);

	/*   下发指令 */
	if(elem_counter < 4)
		{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s , the elem_counter is NOT 4 in ORDER_STA_ADD, invalid order. \n", __func__);
			memset(&stFlowCtl, 0, sizeof(stFlowCtl));
		}


		ret = SubmitOrder2Drv(&stFlowCtl, sizeof(stFlowCtl), ORDER_STA_ADD);

	return	ret;
}



BOOL OnWtpInit()
{
	long i , j ;
	char		cmd[256];	/*  AP流控，初始化调用， chary，2011-11-10  */
	int	call_ret = 0;		/*  AP流控，初始化调用， chary，2011-11-10  */

	system("pkill hostapd") ;

	for(i = 0 ; i < MAX_INTERFACES ; i ++){
		if(! g_stWtp.iface[i])
			continue ;
		
		for(j = 0 ; j < MAX_BSSES && g_stWtp.iface[i] ; j ++){
			if(! g_stWtp.iface[i]->bss[j])
				continue ;
				
			if(! VapDelete(i, j))
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, delete vap(%u/%u) failed.\n", __func__, i , j) ;
			else
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s, delete vap(%u/%u) success.\n", __func__, i , j) ;
		}
	}

	/*  AP流控，初始化调用， chary，2011-11-10  */
	memset(cmd, 0, sizeof(cmd));
	sprintf(cmd, "flowctrl flushsta");
	call_ret = system(cmd);

	if(0 == call_ret)
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG, "%s, execute shell(%s) SUCC. \n", __func__, cmd);
	else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, "%s, execute shell(%s) FAILED. \n", __func__, cmd);
	/*******************************************************/
	
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, init %s wtp end.\n", __func__, g_stWtp.sub_id == 0 ? "main" : "slave") ;
				
	return TRUE ;
}

BOOL OnIoctl(BYTE * pbData , WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstVap = NULL ;
	struct madwifi_driver_data * pstDriver = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	void * pIoctlData = NULL ;
	int iIoctlDataLen = 0 ;
	BYTE abIoctlRet[2048] = {0} , * pbIoctlRet = abIoctlRet ;
	int iIoctlRet = 0 ;
	BYTE * pbMac = NULL ;
	struct ieee80211req_mlme stMlmeReq = {0} ;
	struct ieee80211req_key stKeyReq = {0} ;
	struct ieee80211req_del_key stKeyDelReq = {0} ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcIoctl);
	
	if((pstVap = FindVap(ucInterfaceIndex, ucBssIndex)) == NULL
		|| (pstDriver = pstVap->driver) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(%u/%u) is not exist, or point is NULL.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		return FALSE ;	
	}
	
	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;
	
	/*获取消息体内容，并作字节序转化处理*/
	while(lLength > 0 && lLength < wLength){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		pIoctlData = (void *)((BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T)) ;
		iIoctlDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;

		/*IOCTL返回值置初值*/
		iIoctlRet = -1 ;
		pbMac = NULL ;

		/*根据不同的IOCTL，分别作字节序转化处理*/
		switch(pstHostapdElem->dwElemId){
		case SIOCSIWCOMMIT :
			goto next ;
		case SIOCSIWSENS	:
			goto next ;
		case SIOCGIWSENS	:
			goto next ;
		case SIOCSIWRANGE	:
			goto next ;
		case SIOCGIWRANGE	:
			goto next ;
		case SIOCSIWPRIV	:
			goto next ;
		case SIOCGIWPRIV	:
			goto next ;
		case SIOCSIWSTATS	:
			goto next ;
		case SIOCGIWSTATS	:
			goto next ;
		case SIOCSIWSPY		:
			goto next ;
		case SIOCGIWSPY	:
			goto next ;
		case SIOCSIWTHRSPY	:
			goto next ;
		case SIOCGIWTHRSPY	:
			goto next ;
		case SIOCSIWAP		:
			goto next ;
		case SIOCGIWAP    	:
			goto next ;
		case SIOCSIWMLME	:
			goto next ;
		case SIOCGIWAPLIST	:
			goto next ;
		case SIOCSIWSCAN	:
			goto next ;
		case SIOCGIWSCAN	:
			goto next ;
		case SIOCSIWESSID	:
			goto next ;
		case SIOCGIWESSID	:
			goto next ;
		case SIOCSIWNICKN	:
			goto next ;
		case SIOCGIWNICKN	:
			goto next ;
		case SIOCSIWRATE	:
			goto next ;
		case SIOCGIWRATE	:
			goto next ;
		case SIOCSIWRTS	:
			goto next ;
		case SIOCGIWRTS	:
			goto next ;
		case SIOCSIWFRAG	:
			goto next ;
		case SIOCGIWFRAG	:
			goto next ;
		case SIOCSIWTXPOW	:
			goto next ;
		case SIOCGIWTXPOW	:
			goto next ;
		case SIOCSIWRETRY	:
			goto next ;
		case SIOCGIWRETRY	:
			goto next ;
		case SIOCSIWENCODE	:
			goto next ;
		case SIOCGIWENCODE	:
			goto next ;
		case SIOCSIWPOWER	:
			goto next ;
		case SIOCGIWPOWER	:
			goto next ;
		case SIOCSIWGENIE	:
			goto next ;
		case SIOCGIWGENIE	:
			goto next ;
		case SIOCSIWAUTH	:
			goto next ;
		case SIOCGIWAUTH	:
			goto next ;
		case SIOCSIWENCODEEXT :
			goto next ;
		case SIOCGIWENCODEEXT :
			goto next ;
		case SIOCSIWPMKSA	:
			goto next ;
		case IEEE80211_IOCTL_SETPARAM :{
			int op , arg ;

			if(iIoctlDataLen != sizeof(int) + sizeof(int)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, IOCTL(%u): data len(%u) is not correct.\n", __func__ , pstHostapdElem->dwElemId, iIoctlDataLen) ;
				goto next ;
			}

			op = * ((int *)pIoctlData) ;
			op = ntohl(op) ;

			arg = * ((int *)((BYTE *)pIoctlData + sizeof(int))) ;
			arg = ntohl(arg) ;

			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
				"%s, ioctl/set80211param: op(%u), arp(%u).\n", __func__, op, arg) ;

			iIoctlRet = set80211param(pstDriver, op, arg) ;

			pbIoctlRet = IoctlReturnAdd(pbIoctlRet, pstHostapdElem->dwElemId, iIoctlRet, pbMac) ;
			if(pbIoctlRet == NULL 
				|| pbIoctlRet - abIoctlRet > 2048){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, call IoctlReturnAdd failed.\n", __func__) ;
				return FALSE ;
			}
			
			goto next ;
		}
		case IEEE80211_IOCTL_GETPARAM	    :   
			goto next ;
		case IEEE80211_IOCTL_SETMODE	    :   
			goto next ;
		case IEEE80211_IOCTL_GETMODE	    :   
			goto next ;
		case IEEE80211_IOCTL_SETWMMPARAMS :   
			goto next ;
		case IEEE80211_IOCTL_GETWMMPARAMS :   
			goto next ;
		case IEEE80211_IOCTL_SETCHANLIST	:   
			goto next ;
		case IEEE80211_IOCTL_GETCHANLIST	:   
			goto next ;
		case IEEE80211_IOCTL_CHANSWITCH	:   
			goto next ;
		case SIOCIWFIRSTPRIV+9 :              
			goto next ;
		case SIOCIWFIRSTPRIV+10 :             
			goto next ;
		case SIOCIWFIRSTPRIV+11 :             
			goto next ;
		case SIOCIWFIRSTPRIV+12 :             
			goto next ;
		case IEEE80211_IOCTL_GETCHANINFO :	  
			goto next ;
		case IEEE80211_IOCTL_SETOPTIE	  :    
			goto next ;
		case IEEE80211_IOCTL_GETOPTIE	  :    
			goto next ;
		case IEEE80211_IOCTL_SETMLME :{
			struct ieee80211req_mlme_pack * pstMlme = (struct ieee80211req_mlme_pack  * )(pIoctlData) ;

			if(iIoctlDataLen != sizeof(struct ieee80211req_mlme_pack)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, IOCTL(%u): len(%d) is not equal to(%d).\n", __func__ , pstHostapdElem->dwElemId, iIoctlDataLen, sizeof(struct ieee80211req_mlme_pack)) ;
				goto next ;
			}
			
			pstMlme->im_reason = ntohs(pstMlme->im_reason) ;

			/*网络PACKED包转化本机数据包，pIoctlData/iIoctlDataLen重赋值*/
			stMlmeReq.im_op = pstMlme->im_op ;
			stMlmeReq.im_ssid_len = pstMlme->im_ssid_len ;
			stMlmeReq.im_reason = pstMlme->im_reason ;
			os_memcpy(stMlmeReq.im_macaddr, pstMlme->im_macaddr, IEEE80211_ADDR_LEN) ;
			os_memcpy(stMlmeReq.im_ssid, pstMlme->im_macaddr, IEEE80211_NWID_LEN) ;

			pIoctlData = & stMlmeReq ;
			iIoctlDataLen = sizeof(stMlmeReq) ;

			pbMac = stMlmeReq.im_macaddr;
			break ;
		}
		case SIOCIWFIRSTPRIV+17 :             
			goto next ;
		case IEEE80211_IOCTL_SETKEY	:{
			struct ieee80211req_key_pack * pstKey = (struct ieee80211req_key_pack *)pIoctlData ;

			if(iIoctlDataLen != sizeof(struct ieee80211req_key_pack)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, IOCTL(%u): len(%d) is not equal to(%d).\n", __func__ , pstHostapdElem->dwElemId, iIoctlDataLen, sizeof(struct ieee80211req_key_pack)) ;
				goto next ;
			}

			pstKey->ik_keyix = ntohs(pstKey->ik_keyix) ;
			pstKey->ik_keyrsc = be_to_host64(pstKey->ik_keyrsc) ;
			pstKey->ik_keytsc = be_to_host64(pstKey->ik_keytsc) ;

			/*网络PACKED包转化本机数据包，pIoctlData/iIoctlDataLen重赋值*/
			stKeyReq.ik_type = pstKey->ik_type ;
			stKeyReq.ik_pad = pstKey->ik_pad ;
			stKeyReq.ik_keyix = pstKey->ik_keyix ;
			stKeyReq.ik_keylen = pstKey->ik_keylen ;
			stKeyReq.ik_flags = pstKey->ik_flags ;
			os_memcpy(stKeyReq.ik_macaddr, pstKey->ik_macaddr, sizeof(stKeyReq.ik_macaddr)) ;
			stKeyReq.ik_keyrsc = pstKey->ik_keyrsc ;
			stKeyReq.ik_keytsc = pstKey->ik_keytsc ;
			os_memcpy(stKeyReq.ik_keydata, pstKey->ik_keydata, sizeof(stKeyReq.ik_keydata)) ;

			pIoctlData = & stKeyReq ;
			iIoctlDataLen = sizeof(stKeyReq) ;

			pbMac = stKeyReq.ik_macaddr ;
			break ;
		}
		case SIOCIWFIRSTPRIV+19 :             
			goto next ;
		case IEEE80211_IOCTL_DELKEY : {
			/*ieee80211req_del_key数据项类型皆为BYTE，故无需作字节序处理*/
			struct ieee80211req_del_key_pack * pstKey = (struct ieee80211req_del_key_pack *)pIoctlData ;

			if(iIoctlDataLen != sizeof(struct ieee80211req_del_key_pack)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
					"%s, IOCTL(%u): len(%d) is not equal to (%d).\n", __func__ , pstHostapdElem->dwElemId, iIoctlDataLen, sizeof(struct ieee80211req_del_key_pack)) ;
				goto next ;
			}

			/*网络PACKED包转化本机数据包，pIoctlData/iIoctlDataLen重赋值*/
			stKeyDelReq.idk_keyix = pstKey->idk_keyix ;
			os_memcpy(stKeyDelReq.idk_macaddr, pstKey->idk_macaddr, IEEE80211_ADDR_LEN) ;

			pIoctlData = & stKeyDelReq ;
			iIoctlDataLen = sizeof(stKeyDelReq) ;
			
			pbMac = stKeyDelReq.idk_macaddr ;			
			break ;
		}
		case SIOCIWFIRSTPRIV+21 :             
			goto next ;
		case IEEE80211_IOCTL_ADDMAC :         
			goto next ;
		case SIOCIWFIRSTPRIV+23 :             
			goto next ;
		case IEEE80211_IOCTL_DELMAC :         
			goto next ;
		case SIOCIWFIRSTPRIV+25 :             
			goto next ;
		case IEEE80211_IOCTL_WDSADDMAC :      
			goto next ;
		case SIOCIWFIRSTPRIV+27 :             
			goto next ;
		case IEEE80211_IOCTL_WDSDELMAC :      
			goto next ;
		case SIOCIWFIRSTPRIV+29 :             
			goto next ;
		case IEEE80211_IOCTL_KICKMAC :        
			goto next ;
		case SIOCIWFIRSTPRIV+31 :             
			goto next ;
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, unknown op: 0x%x.\n", __func__ , pstHostapdElem->dwElemId) ;
			goto next ;
		}

		iIoctlRet = set80211priv(pstDriver, pstHostapdElem->dwElemId, pIoctlData, iIoctlDataLen) ;

		/*保存IOCTL返回值*/
		pbIoctlRet = IoctlReturnAdd(pbIoctlRet, pstHostapdElem->dwElemId, iIoctlRet, pbMac) ;
		if(pbIoctlRet == NULL 
			|| pbIoctlRet - abIoctlRet > 2048){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, call IoctlReturnAdd failed, or pbIoctlRet is over.\n", __func__) ;
			return FALSE ;
		}
next :
	
#if 0
{
		int i ;

		printf("ioctl(0x%x) on vap(%s), data len(%u):\n", pstHostapdElem->dwElemId, pstVap->ifacename, iIoctlDataLen) ;
		for(i = 1; i <= iIoctlDataLen ; i ++){
			printf("%02x.", ((BYTE *)pIoctlData)[i-1]) ;
			if(i % 10 == 0)
				printf("\n") ;
		}
		printf("\n") ;
}
#else
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, ioctl(0x%x) on vap(%s) %s.\n", __func__, pstHostapdElem->dwElemId, pstVap->ifacename, iIoctlRet == 0 ? "success" : "failed or unsupport") ;
#endif
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	/*发送IOCTL返回值*/
	if(! HostapdSend(pstVap, NULL, EV_HOSTAPD_SOCKET_IOCTL, abIoctlRet, pbIoctlRet - abIoctlRet)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, call HostapdSend failed.\n", __func__) ;
		return FALSE ;
	}
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, SendAcIoctl);

	if(lLength < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV is not correct.\n", __func__) ;
		return FALSE ;
	}
	
	return TRUE ;
}

BOOL OnEapol(BYTE * pbData , WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL , * pabMac = NULL, * pbEapolData = NULL ;
	long lLength = 0 ;
	WORD32 ulEapolDataLen = 0 ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcEapol);
	
	if((pstBss = FindVap(ucInterfaceIndex, ucBssIndex)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(%u/%u) is not exist.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		return FALSE ;
	}
	
	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLength){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;
		
		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_MAC :
			pabMac = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_COMMON_DATA :
			pbEapolData = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			ulEapolDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
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
		|| pbEapolData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV is not correct.\n", __func__) ;
		return FALSE ;
	}

#if 0
{
	long i ;
	
	printf("send ETH_P_EAPOL(%u) to "MACSTR".\n", ulEapolDataLen, MAC2STR(pabMac)) ;
	for(i = 1 ; i <= ulEapolDataLen; i ++){
		printf("%02x.", pbEapolData[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
}	
#endif

	if(pstBss->driver == NULL
		|| pstBss->driver->sock_xmit == NULL)
		return FALSE ;

	if(l2_packet_send(pstBss->driver->sock_xmit, pabMac, ETH_P_EAPOL, pbEapolData, ulEapolDataLen) < 0)
		return FALSE ;
		
	return TRUE ;
}

BOOL OnPreauth(BYTE * pbData , WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * pstBss = NULL ;
	struct rsn_preauth_interface * pstPreauthIf = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL , * pabMac = NULL, * pbDataCtt = NULL, * pbPreauthIf = NULL , pbDeviceName[IFNAMSIZ+1] ;
	long lLength = 0 ;
	WORD32 ulDataLen = 0, ulPreauthIfLen = 0 ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcPreauth);
	
	if((pstBss = FindVap(ucInterfaceIndex, ucBssIndex)) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, vap(%u/%u) is not exist.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		return FALSE ;
	}
	
	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLength){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;
		
		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_MAC :
			pabMac = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_COMMON_DATA :
			pbDataCtt = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			ulDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_COMMON_DEVICENAME :
			pbPreauthIf = (BYTE *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			ulPreauthIfLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
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
		|| pbDataCtt == NULL
		|| pbPreauthIf == NULL
		|| ulPreauthIfLen > IFNAMSIZ){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV is not correct.\n", __func__) ;
		return FALSE ;
	}

	/*在当前VAP中查找设备名为pbPreauthIf的PREAUTH接口*/
	os_memcpy(pbDeviceName, pbPreauthIf, ulPreauthIfLen) ;
	pbDeviceName[ulPreauthIfLen] = '\0' ;
	for(pstPreauthIf = pstBss->preauth_iface; pstPreauthIf ; pstPreauthIf = pstPreauthIf->next)
		if(os_strcmp(pstPreauthIf->ifname, pbDeviceName) == 0)
			break ;
	if(pstPreauthIf == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, cannot find PREAUTH interface: %s.\n", __func__, pbDeviceName) ;
		return FALSE ;
	}

	if(l2_packet_send(pstPreauthIf, pabMac, ETH_P_PREAUTH, pbDataCtt, ulDataLen) < 0)
		return FALSE ;
	
	return TRUE ;
}

static BOOL OnCreateVap(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	char * pcDeviceName = NULL ;
	DWORD dwDeviceNameLen ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcVapCreate);
	
	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLength){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, left data(%d) elem_id(%u), elem_len(%u).\n", __func__, lLength, pstHostapdElem->dwElemId, pstHostapdElem->dwLength) ;
		
		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_DEVICENAME :{
			pcDeviceName = (char *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwDeviceNameLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;

			if(! VapAdd(ucInterfaceIndex, ucBssIndex, pcDeviceName, dwDeviceNameLen)){
				HOSTAPD_HEAD_T stHostapdHead = {0} ;
				TPID tReceiver = {0} ;
				
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s,  Call VapAdd fail.\n", __func__) ;

				os_memset(& stHostapdHead, 0xff, sizeof(stHostapdHead)) ;
				stHostapdHead.ucFromInterface = ucInterfaceIndex ;
				stHostapdHead.ucFromBss = ucBssIndex ;

				if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
						"%s, call VmGetLocalPid failed.\n", __func__) ;
					return FALSE ;
				}
				tReceiver.wWtpId = 0;

				if(! VmASend(EV_HOSTAPD_VAP_CREATE_NACK, &stHostapdHead, sizeof(stHostapdHead), tReceiver) != TRUE){
					ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
						"%s, send EV_HOSTAPD_VAP_CREATE_NACK failed.\n", __func__) ;
					return FALSE;
				}

				hostapd_bss_stats_inc(stHostapdHead.ucFromInterface, stHostapdHead.ucFromBss, SendAcVapCreateNack);
				
				return FALSE ;
			}
			else
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
					"%s,  Call VapAdd success.\n", __func__) ;
			break ;
		}
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			break ;
		}
		
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV is not correct.\n", __func__) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, create vap(%u/%u) success.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
			
	
	return TRUE ;
}

static BOOL OnDestroyVap(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcVapDestroy);

	if(! VapDelete(ucInterfaceIndex, ucBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s,  Call VapDelete fail.\n", __func__) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, destroy vap(%u/%u) success.\n", __func__, ucInterfaceIndex, ucBssIndex) ;

	return TRUE ;
}

/*AC与VAP链路通时响应函数*/
static BOOL OnStartVap(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	char * pcBridgeName = NULL , * pcPreauthInteraces = NULL ;
	WORD32 dwBridgeNameLen = 0 , dwPreauthInterfacesLen = 0 ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcVapStart);
	
	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	/*获取消息体内容，并作相应处理*/
	while(lLength > 0 && lLength < wLength){
		pstHostapdElem = (HOSTAPD_ELEM_T * )pElem ;
		pstHostapdElem->dwElemId = ntohl(pstHostapdElem->dwElemId) ;
		pstHostapdElem->dwLength = ntohl(pstHostapdElem->dwLength) ;

		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, left data(%d) elem_id(%u), elem_len(%u).\n", __func__, lLength, pstHostapdElem->dwElemId, pstHostapdElem->dwLength) ;
		
		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_COMMON_BRIDGE :
			pcBridgeName = (char *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwBridgeNameLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		case HOSTAPD_ELEMID_PREAUTH_NAMES :{
			pcPreauthInteraces = (char *)pstHostapdElem + sizeof(HOSTAPD_ELEM_T) ;
			dwPreauthInterfacesLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
			break ;
		}
		default :
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, unknown dwElemId: %u.\n", __func__, pstHostapdElem->dwElemId) ;
			break ;
		}
		
		pElem += pstHostapdElem->dwLength ;
		lLength -= pstHostapdElem->dwLength ;
	}

	if(lLength < 0){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV is not correct.\n", __func__) ;
		return FALSE ;
	}

	if(! MadwifiInit(ucInterfaceIndex, ucBssIndex, pcBridgeName, dwBridgeNameLen)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, call MadwifiInit failed.\n", __func__) ;
		return FALSE ;
	}

	if(! rsn_preauth_iface_init(ucInterfaceIndex, ucBssIndex, pcPreauthInteraces, dwPreauthInterfacesLen)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, call MadwifiInit failed.\n", __func__) ;
		if(! MadwifiDeinit(ucInterfaceIndex, ucBssIndex))
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
				"%s, call MadwifiDeinit failed.\n", __func__) ;
		return FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		"%s, start vap(%u/%u) success.\n", 
		__func__, ucInterfaceIndex, ucBssIndex) ;
	
	return TRUE ;
}

/*AC与VAP链路断时响应函数*/
static BOOL OnStopVap(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BOOL bRet = TRUE ;

	/*获取消息头内容*/
	if(pbData == NULL
		|| wLength < sizeof(HOSTAPD_HEAD_T)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL or length(%d) is too short.\n", __func__, wLength) ;
		return FALSE ;
	}
	pstHostapdHead = (HOSTAPD_HEAD_T * )pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvAcVapStop);

	if(! MadwifiDeinit(ucInterfaceIndex, ucBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, call MadwifiDeinit failed.\n", __func__) ;
		bRet = FALSE ;
	}

	if(! rsn_preauth_iface_deinit(ucInterfaceIndex, ucBssIndex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, call rsn_preauth_iface_deinit failed.\n", __func__) ;
		bRet = FALSE ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
		"%s, stop vap(%u/%u) success.\n", __func__, ucInterfaceIndex, ucBssIndex) ;

	return bRet ;
}

/*接收本地另一线程的EVENT数据包*/
static BOOL OnEvent(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	void * eloop_ctx = NULL, * user_ctx = NULL ;
	BYTE * pbEventData = NULL ;
	WORD32 dwEventDataLen = 0 ;

	if(pbData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}

	pstHostapdHead = (HOSTAPD_HEAD_T *)pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvLocalEvent);
	
	if(ucInterfaceIndex >= MAX_INTERFACES
		|| ucBssIndex >= MAX_BSSES
		|| g_stWtp.iface[ucInterfaceIndex] == NULL
		|| g_stWtp.iface[ucInterfaceIndex]->bss[ucBssIndex] == NULL
		|| g_stWtp.iface[ucInterfaceIndex]->bss[ucBssIndex]->driver == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%d/%d) is not exist.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		return TRUE ;
	}

	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	while(lLength > 0 && lLength <= wLength){
		pstHostapdElem = pElem ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_SOCKET_ELOOP :
			eloop_ctx = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(eloop_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, eloop len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				eloop_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_USER :
			user_ctx = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(user_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, user len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				user_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_DATA :
			pbEventData = pstHostapdElem + 1 ;
			dwEventDataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
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
		|| eloop_ctx == NULL
		|| pbEventData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct, or point is NULL.\n", __func__, lLength) ;
		return FALSE ;
	}

	if(g_stWtp.iface[ucInterfaceIndex]->bss[ucBssIndex]->driver != eloop_ctx)
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%d/%d) has been realloced.\n", __func__, ucInterfaceIndex, ucBssIndex) ;		

	madwifi_wireless_event_receiveA(g_stWtp.iface[ucInterfaceIndex]->bss[ucBssIndex]->driver, user_ctx, pbEventData, dwEventDataLen) ;

	return TRUE ;
}

/*接收本地另一线程L2数据包*/
static BOOL OnL2(BYTE * pbData, WORD16 wLength)
{
	HOSTAPD_HEAD_T * pstHostapdHead = NULL ;
	HOSTAPD_ELEM_T * pstHostapdElem = NULL ;
	struct hostapd_data * hapd = NULL ;
	BYTE ucInterfaceIndex = 0xFF , ucBssIndex = 0xFF ;
	BYTE * pElem = NULL ;
	long lLength = 0 ;
	void * eloop_ctx = NULL, * user_ctx = NULL ;
	u16 protocol = 0 ; 
	BYTE * pbMac = NULL, * pbL2Data = NULL ;
	WORD32 dwL2DataLen = 0 ;

	if(pbData == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return FALSE ;
	}
#if 0
{
	int i ;

	printf("pbData: %p, wLength: %u.\n", pbData, wLength) ;
	for(i = 1 ; i <= wLength ; i ++){
		printf("%02x.", pbData[i-1]) ;
		if(i % 10 == 0)
			printf("\n") ;
	}
	printf("\n") ;
}
#endif
	pstHostapdHead = (HOSTAPD_HEAD_T *)pbData ;
	ucInterfaceIndex = pstHostapdHead->ucToInterface ;
	ucBssIndex = pstHostapdHead->ucToBss ;
	hostapd_bss_stats_inc(ucInterfaceIndex, ucBssIndex, RecvLocalL2);
	
	if(ucInterfaceIndex >= MAX_INTERFACES
		|| ucBssIndex >= MAX_BSSES
		|| g_stWtp.iface[ucInterfaceIndex] == NULL
		|| (hapd = g_stWtp.iface[ucInterfaceIndex]->bss[ucBssIndex]) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
			"%s, vap(%d/%d) is not exist.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		return TRUE ;
	}

	pElem = pbData + sizeof(HOSTAPD_HEAD_T) ;
	lLength = wLength - sizeof(HOSTAPD_HEAD_T) ;

	while(lLength > 0 && lLength <= wLength){
		pstHostapdElem = pElem ;

		switch(pstHostapdElem->dwElemId){
		case HOSTAPD_ELEMID_SOCKET_ELOOP :
			eloop_ctx = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(eloop_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, eloop len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				eloop_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_USER :
			user_ctx = * ((unsigned long *)(pstHostapdElem + 1)) ;
			if(sizeof(user_ctx) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, user len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				user_ctx = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_MAC :
			pbMac = pstHostapdElem + 1 ;
			if(ETH_ALEN != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, mac len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				pbMac = NULL ;
			}
			break ;
		case HOSTAPD_ELEMID_COMMON_PROTO :
			protocol = * ((u16 *)(pstHostapdElem + 1)) ;
			if(sizeof(protocol) != pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T)){
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
					"%s, protocol len(%u) is not correct.\n", __func__, pstHostapdElem->dwLength) ;
				protocol = 0 ;
			}
			break ;
		case HOSTAPD_ELEMID_SOCKET_DATA :
			pbL2Data = pstHostapdElem + 1 ;
			dwL2DataLen = pstHostapdElem->dwLength - sizeof(HOSTAPD_ELEM_T) ;
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
		|| eloop_ctx == NULL
		|| pbMac == NULL
		|| pbL2Data == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, TLV(%u) is not correct, or point is NULL.\n", __func__, lLength) ;
		return FALSE ;
	}

	switch(protocol){
	case ETH_P_EAPOL :{
		if(hapd->driver == NULL
			|| hapd->driver->sock_xmit == NULL
			|| hapd->driver->sock_recv == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, point(ETH_P_EAPOL) is NULL.\n", __func__) ;
			return FALSE;
		}
		
		if(eloop_ctx != hapd->driver->sock_xmit
			&& eloop_ctx != hapd->driver->sock_recv)
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, vap(%d/%d) has been realloced.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
		
		l2_packet_receiveA(hapd->driver->sock_xmit, user_ctx, pbMac, pbL2Data, dwL2DataLen) ;
		
		break ;
	}
	case ETH_P_PREAUTH :{
		struct rsn_preauth_interface * preauth = NULL ;
		
		if((preauth = hapd->preauth_iface) == NULL){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, point(ETH_P_PREAUTH) is NULL.\n", __func__) ;
			return FALSE;	
		}

		while(preauth && preauth->l2 != eloop_ctx){
			preauth = preauth->next ;
		}

		if(preauth == NULL){/*找不到预认证接口*/
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"%s, vap(%d/%d) has been realloced.\n", __func__, ucInterfaceIndex, ucBssIndex) ;
			return TRUE ;
		}

		l2_packet_receiveA(preauth->l2, user_ctx, pbMac, pbL2Data, dwL2DataLen) ;
		
		break ;
	}
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, unknown protocol(%d).\n", __func__, protocol) ;
		break ;
	}
	
	
	return TRUE ;
}


static BOOL SendMsgAck(HOSTAPD_HEAD_T * pstHead, WORD16 wEvent)
{
	CHAR acOut[32] = {0}, *pcOut = NULL;
	HOSTAPD_HEAD_T *pstHostapdHead = NULL;
	TPID stTpid = {0};
	UINT32 ulMsg;
	
	if(wEvent < EV_HOSTAPD_BEGIN
		|| wEvent >= (EV_HOSTAPD_BEGIN+1000))
		return TRUE;

	pstHostapdHead = pcOut = acOut;
	os_memset(pstHostapdHead, 0xff, sizeof(HOSTAPD_HEAD_T));
	if(pstHead){
		pstHostapdHead->ucFromInterface = pstHead->ucToInterface;
		pstHostapdHead->ucFromBss = pstHead->ucToBss;
	}
	pcOut += sizeof(HOSTAPD_HEAD_T);

	ulMsg = wEvent;
	ulMsg = HTONL(ulMsg);
	pcOut = AddElem(pcOut, HOSTAPD_ELEMID_COMMON_MSGID, &ulMsg, sizeof(ulMsg));
	
	if(! VmGetLocalPid("AppHostapdProc", &stTpid)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, call VmGetLocalPid failed.\n", __func__) ;
		return FALSE ;
	}
	stTpid.wWtpId = 0;

	if(VmASend(EV_HOSTAPD_MSG_ACK, acOut, pcOut-acOut, stTpid) != TRUE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s, send EV_HOSTAPD_VAP_CREATE_NACK failed.\n", __func__) ;
		return FALSE;
	}

	if(pstHead){
		switch(wEvent){
		case EV_HOSTAPD_VAP_CREATE:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcVapCreateAck);
			break;
		case EV_HOSTAPD_VAP_DESTROY:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcVapDestroyAck);
			break;
		case EV_HOSTAPD_VAP_START:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcVapStartAck);
			break;
		case EV_HOSTAPD_VAP_STOP:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcVapStopAck);
			break;
		case EV_HOSTAPD_SOCKET_IOCTL:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcIoctlAck);
			break;
		case EV_HOSTAPD_SOCKET_EAPOL:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcEapolAck);
			break;
		case EV_HOSTAPD_SOCKET_PREAUTH:
			hostapd_bss_stats_inc(pstHostapdHead->ucFromInterface, pstHostapdHead->ucFromBss, SendAcPreauthAck);
			break;
		}
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
		"%s, vap(%u/%u): send msg(%u) ack.\n", 
		__func__, pstHostapdHead->ucFromInterface, pstHostapdHead->ucToBss, wEvent);
	
	return TRUE;
}
