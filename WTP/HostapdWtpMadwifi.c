/******************************************************************************
ģ����      : HOSTAPD
�ļ���      : HostapdWtpMadwifi.c
����ļ�    :
ʵ�ֹ���    : WTP���HOSTAPD���̣߳�������������Ϣ��EVENT��L2����������Ӧ����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/29  Ҷ����      ����
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
