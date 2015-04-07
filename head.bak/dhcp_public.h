#ifndef __DHCP_PUBLIC_H__
#define __DHCP_PUBLIC_H__

#define DHCP_GET_USERIP_TYPE	50000 

typedef struct DHCP_GET_USERIP_TYPE_REQ_S {
       UINT8    aucIp[4];
} DHCP_GET_USERIP_TYPE_REQ_T;

typedef struct DHCP_GET_USERIP_TYPE_RSP_S {

       UINT32  ulRet;      /*   0：用户IP地址是本AC所述的地址池中的有效地址，且已经分配给用户

                        			1：用户IP地址不是本AC所述的地址池中的有效地址

                        			2：用户IP地址是本AC所述的地址池中的有效地址，但这个地址目前还未分配给用户

						3：调用失败 */
	UINT8 aucHwAddr[6];

} DHCP_GET_USERIP_TYPE_RSP_T;

extern void dhdb_get_userip_type(UINT8 *pucIn, UINT16 ulInLen, UINT8 *pucOut, UINT16*pulOutLen);

#endif
/*end bug#1926 cmcc test fangz 2013.2.20*/
