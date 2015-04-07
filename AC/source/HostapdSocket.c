#include "includes.h"
#include "common.h"
#include "HostapdSocket.h"

BYTE * AddElem(BYTE * pbFrame, DWORD dwElemId, BYTE * pbData, DWORD dwDataLen)
{
	HOSTAPD_ELEM_T stHostapdElem ;

	if(pbFrame == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, poing is NULL.\n", __func__) ;
		return NULL ;
	}

#if 0
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, add elem_id(0x%x), elem_len(%u).\n", __func__, dwElemId, dwDataLen) ;
#endif

	stHostapdElem.dwElemId = htonl(dwElemId) ;
	stHostapdElem.dwLength = htonl(sizeof(HOSTAPD_ELEM_T) + dwDataLen) ;

	os_memcpy(pbFrame, & stHostapdElem, sizeof(HOSTAPD_ELEM_T)) ;
	pbFrame += sizeof(HOSTAPD_ELEM_T) ;

	if(pbData){
		os_memcpy(pbFrame, pbData, dwDataLen) ;
		pbFrame +=dwDataLen ;
	}

	return pbFrame ;
}
