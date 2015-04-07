/******************************************************************************
模块名      : VMIPC
文件名      : OssVmipc.h
相关文件    :
实现功能    : VMIPC 基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSVMIPC_H_
#define _OSSVMIPC_H_


/****************************************************************/
/*    VMIPC模块的宏定义                                         */
/****************************************************************/

/* 用于消息收发跟踪的宏 */
#define ST_INNERSEND        (BYTE) 1        /* UDP发送的消息 */
#define ST_TCPSEND          (BYTE) 2        /* TCP发送的消息 */
#define ST_UDPSEND          (BYTE) 3        /* 异步消息 */
#define ST_BROADCAST        (BYTE) 4        /* 板内广播消息 */
#define ST_BROADCAST_EX     (BYTE) 5        /* udp广播消息 */
#define ST_BSEND            (BYTE) 6        /* 发往后台的消息 */
#define ST_CSEND            (BYTE) 7        /* 发往cn的消息 */

#define MSG_TYPE_ASYNC      (BYTE) 0 		/* 板内异步消息 */
#define MSG_TYPE_SYNC       (BYTE) 1 		/* 板内同步消息 */
#define MSG_TYPE_ASYNCTIMER (BYTE) 2 	/* 异步定时消息 */
#define MSG_TYPE_MULTICAST  (BYTE) 7 	/* 板间组播消息 */
#define MSG_TYPE_MATE		(BYTE)8		/* 主从间消息*/
#define MSG_TYPE_OMCR       (BYTE) 9 		/* 前后台消息 */
#define MSG_TYPE_BROAD      (BYTE) 10 		/* CPU内部广播消息 */
#define MSG_TYPE_BYTCP      (BYTE) 11 		/* 通过TCP发送的板间消息 */
#define MSG_TYPE_BYUDP      (BYTE) 12 		/* 通过UDP发送的板间消息 */
#define MSG_TYPE_WEB		(BYTE)13			/* AC-WEB <-> AC间消息*/
#define MSG_TYPE_INVALID    (BYTE) 0xff 		/* 无效消息类型 */

#define MAX_AC_ID           (WORD)33
#define MAX_AP_ID           (WORD)1025

/****************************************************************/
/*    vmipc模块的基本类型定义                                   */
/****************************************************************/
typedef struct MsgTag
{
    TPID            tSender;    /* 发送方 */
    TPID            tReceiver;  /* 接收方 */
    WORD16          wEvent;     /* 消息号 */
    WORD16          wLen;       /* 消息长度 */
    BYTE            byMsgType;  /* 消息类型 */
    BYTE            byCellType; /* 网元类型 */    
    WORD16          wAckLen;    /* 消息应答长度 */
    BYTE            *lpbyAck;   /* 消息应答 */
    struct MsgTag   *lptNext;   /* 下一消息 */
} TMsgStruc;

extern BOOL  UdpSendMsg (TMsgStruc *lptMsgPtr);
VOID htonm (TMsgStruc *ptMsg);
VOID ntohm (TMsgStruc *ptMsg);
BOOL IpcSysInit (VOID);
BOOL IpcSysReset (VOID);

TMsgStruc * SysSend (WORD16, LPVOID, WORD16, TPID, BYTE, TPID, WORD32);
WORD32 ExtractUdpMsg (BYTE *pbyData, WORD32 dwLen);
WORD32 ExtractTcpMsg (BYTE *pbyData, WORD32 dwLen, WORD32 *pdwMsgSize);

/* 消息发送接口 */
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
