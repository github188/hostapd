/******************************************************************************
ģ����      : VMIPC
�ļ���      : OssVmipc.h
����ļ�    :
ʵ�ֹ���    : VMIPC ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSVMIPC_H_
#define _OSSVMIPC_H_


/****************************************************************/
/*    VMIPCģ��ĺ궨��                                         */
/****************************************************************/

/* ������Ϣ�շ����ٵĺ� */
#define ST_INNERSEND        (BYTE) 1        /* UDP���͵���Ϣ */
#define ST_TCPSEND          (BYTE) 2        /* TCP���͵���Ϣ */
#define ST_UDPSEND          (BYTE) 3        /* �첽��Ϣ */
#define ST_BROADCAST        (BYTE) 4        /* ���ڹ㲥��Ϣ */
#define ST_BROADCAST_EX     (BYTE) 5        /* udp�㲥��Ϣ */
#define ST_BSEND            (BYTE) 6        /* ������̨����Ϣ */
#define ST_CSEND            (BYTE) 7        /* ����cn����Ϣ */

#define MSG_TYPE_ASYNC      (BYTE) 0 		/* �����첽��Ϣ */
#define MSG_TYPE_SYNC       (BYTE) 1 		/* ����ͬ����Ϣ */
#define MSG_TYPE_ASYNCTIMER (BYTE) 2 	/* �첽��ʱ��Ϣ */
#define MSG_TYPE_MULTICAST  (BYTE) 7 	/* ����鲥��Ϣ */
#define MSG_TYPE_MATE		(BYTE)8		/* ���Ӽ���Ϣ*/
#define MSG_TYPE_OMCR       (BYTE) 9 		/* ǰ��̨��Ϣ */
#define MSG_TYPE_BROAD      (BYTE) 10 		/* CPU�ڲ��㲥��Ϣ */
#define MSG_TYPE_BYTCP      (BYTE) 11 		/* ͨ��TCP���͵İ����Ϣ */
#define MSG_TYPE_BYUDP      (BYTE) 12 		/* ͨ��UDP���͵İ����Ϣ */
#define MSG_TYPE_WEB		(BYTE)13			/* AC-WEB <-> AC����Ϣ*/
#define MSG_TYPE_INVALID    (BYTE) 0xff 		/* ��Ч��Ϣ���� */

#define MAX_AC_ID           (WORD)33
#define MAX_AP_ID           (WORD)1025

/****************************************************************/
/*    vmipcģ��Ļ������Ͷ���                                   */
/****************************************************************/
typedef struct MsgTag
{
    TPID            tSender;    /* ���ͷ� */
    TPID            tReceiver;  /* ���շ� */
    WORD16          wEvent;     /* ��Ϣ�� */
    WORD16          wLen;       /* ��Ϣ���� */
    BYTE            byMsgType;  /* ��Ϣ���� */
    BYTE            byCellType; /* ��Ԫ���� */    
    WORD16          wAckLen;    /* ��ϢӦ�𳤶� */
    BYTE            *lpbyAck;   /* ��ϢӦ�� */
    struct MsgTag   *lptNext;   /* ��һ��Ϣ */
} TMsgStruc;

extern BOOL  UdpSendMsg (TMsgStruc *lptMsgPtr);
VOID htonm (TMsgStruc *ptMsg);
VOID ntohm (TMsgStruc *ptMsg);
BOOL IpcSysInit (VOID);
BOOL IpcSysReset (VOID);

TMsgStruc * SysSend (WORD16, LPVOID, WORD16, TPID, BYTE, TPID, WORD32);
WORD32 ExtractUdpMsg (BYTE *pbyData, WORD32 dwLen);
WORD32 ExtractTcpMsg (BYTE *pbyData, WORD32 dwLen, WORD32 *pdwMsgSize);

/* ��Ϣ���ͽӿ� */
BOOL    VmASend     (WORD16 wEvent, 
                         BYTE *lpbyIn, 
                         WORD16 wInLen, 
                         TPID tReceiver
                        );

BOOL    VmSSend     (WORD16 wEvent, 
                         BYTE *lpbyIn, 
                         WORD16 wInLen, 
                         BYTE *lpbyAck, 
                         WORD16 wAckLen, 
                         TPID tReceiver
                        );

BOOL    VmUSend     (WORD16 wEvent, 
                         BYTE *pMsgSent, 
                         WORD16 wMsgLen, 
                         TPID tReceiver
                        );

BOOL    VmBSend     (WORD16 wEvent, 
                         BYTE *pbyData, 
                         WORD16 wLen,
                          BYTE byMsgType
                        );

BOOL    VmBroadCastMsg  (WORD16 wEvent, 
                         LPVOID lpIn, 
                         WORD16 wLength
                        );

BOOL    VmBroadCast   (WORD16 wEvent, 
                         LPBYTE lpbyIn,
                         WORD16 wLength, 
                         WORD16 wPno
                        );

BOOL VmUSendIp (WORD16 wEvent, 
                  BYTE *lpbyIn, 
                  WORD16 wInLen, 
                  WORD16 wPno,
                  BYTE *pucIp
                 );
                 
BOOL    VmGroupSend     (WORD16 wEvent, 
                         BYTE *lpbyIn, 
                         WORD16 wInLen, 
                         WORD32 dwGroup, 
                         WORD16 wPno
                        );

BOOL VmMSend(WORD16 wEvent, 
	BYTE *lpbyIn, 
	WORD16 wInLen, 
	WORD16 wPno);

#ifdef OSS_DEBUG
#define VmASendTrace VmASend_T
#else
#define VmASendTrace (a, b, c, d, e) VmASend_I (b, c, d, e)
#endif

VOID    ShowIpTable     (VOID);

#endif /* _OSSVMIPC_H_ */
