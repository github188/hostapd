/******************************************************************************
ģ����      : MAC AUTH
�ļ���      : mac_auth.h
����ļ�    :
ʵ�ֹ���    : MAC��֤
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2009/02/23  Ҷ����      ����
******************************************************************************/

#ifndef MAC_AUTH_H
#define MAC_AUTH_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAC_AUTH_EVENT_REQ	1
#define MAC_AUTH_EVENT_ACK	2
#define MAC_AUTH_EVENT_NACK	3
#define MAC_AUTH_EVENT_REQ_TIMEOUT	4

void mac_auth_event(struct hostapd_data * hapd, u8 * addr, u32 event, void * ext) ;

#ifdef __cplusplus
}
#endif

#endif
