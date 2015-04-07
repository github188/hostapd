#ifndef __DHCP_PUBLIC_H__
#define __DHCP_PUBLIC_H__

#define DHCP_GET_USERIP_TYPE	50000 

typedef struct DHCP_GET_USERIP_TYPE_REQ_S {
       UINT8    aucIp[4];
} DHCP_GET_USERIP_TYPE_REQ_T;

typedef struct DHCP_GET_USERIP_TYPE_RSP_S {

       UINT32  ulRet;      /*   0���û�IP��ַ�Ǳ�AC�����ĵ�ַ���е���Ч��ַ�����Ѿ�������û�

                        			1���û�IP��ַ���Ǳ�AC�����ĵ�ַ���е���Ч��ַ

                        			2���û�IP��ַ�Ǳ�AC�����ĵ�ַ���е���Ч��ַ���������ַĿǰ��δ������û�

						3������ʧ�� */
	UINT8 aucHwAddr[6];

} DHCP_GET_USERIP_TYPE_RSP_T;

extern void dhdb_get_userip_type(UINT8 *pucIn, UINT16 ulInLen, UINT8 *pucOut, UINT16*pulOutLen);

#endif
/*end bug#1926 cmcc test fangz 2013.2.20*/
