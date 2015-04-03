/******************************************************************************
模块名      : HOSTAPD
文件名      : HostapdWtpMadwifi.c
相关文件    :
实现功能    : WTP侧的HOSTAPD主线程：接收驱动层消息（EVENT，L2），并作相应处理
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/29  叶恩云      创建
******************************************************************************/
#include "includes.h"
#include "OssApi.h"
#include "eloop.h"
#include "hostapd_wtp.h"

void ProcEntryHostapdWtpMadwifi(WORD16 wEvent, BYTE *pbyBody, WORD16 wLen, BYTE *pbyResv, WORD16 wResv, BYTE *pbyProcData)
{
	switch(wEvent){
	case EV_MASTER_POWERON :
		VmPowerOnAck(TRUE) ;
		break ;
	default :
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR,
			"%s, unknonw event(%u)\n", __func__, wEvent) ;
		return ;
	}		
	
	if (eloop_init(& g_stWtp)) {
		wpa_printf(MSG_ERROR, "Failed to initialize event loop") ;
		return ;
	}

	eloop_run();

	eloop_destroy();

	return ;
}
