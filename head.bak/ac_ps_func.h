#ifndef AC_PS_FUNC_H
#define AC_PS_FUNC_H

#define LOG_EMERG       0   /* �����¼���Ϣ */
#define LOG_ALERT       1   /* ������Ϣ */
#define LOG_CRIT        2   /* �ٽ����� */
#define LOG_ERROR       3   /* ������Ϣ */
#define LOG_WARN        4   /* ������Ϣ */
#define LOG_NOTICE      5   /* ������Ϣ */
#define LOG_INFO        6   /* ��ʾ��Ϣ */
#define LOG_DEBUG       7   /* ������Ϣ */

#define PS_VER              0x32303161   //v2.0.1a

#define PS_WEB_PORT         13108

#define AUTH_SUCCESS        0
#define AUTH_FAILED         1

#define LOGOUT_SUCCESS      0
#define LOGOUT_FAILED       1

#define SEND_OK             1
#define SEND_FAIL           -1
#define SEND_TIMEOUT        0

typedef struct
{
    UINT16  usACPort;
    UINT16  usListenPort;
    UINT8   ucDefaultAuthType;

    UINT8   ucRunAsDaemon;
    UINT32  ulMaxUserNum;           /* ������������û� */

    UINT8   ucLogToStdout;
    UINT8   ucLogToFile;

    UINT16  usTimeout;              /* portal agentӦ��ʱʱ�� */
}PS_CONFIG_T;

typedef struct
{
    CHAR    acName[256];
    UINT8   aucIP[4];
}PS_AC_INFO_T;

#define PS_MAX_AC_NUM   128
typedef struct
{
    UINT32          ulNum;
    PS_AC_INFO_T    astAcInfo[PS_MAX_AC_NUM];
}PS_AC_INFOS_T;

typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucACIP[4];
}PS_USER_INFO_T;

#define PS_MAX_USER_NUM   64*1024
typedef struct
{
    UINT32              ulNum;
    PS_USER_INFO_T      astUser[PS_MAX_USER_NUM];
}PS_USER_INFOS_T;

#define PS_INNER_MSG_AUTH_REQ       0xa1
#define PS_INNER_MSG_AUTH_ACK       0xa2

#define PS_INNER_MSG_LOGOUT_REQ     0xa3
#define PS_INNER_MSG_LOGOUT_ACK     0xa4

/* PS-WEB��PS֮����ڲ���Ϣͷ */
typedef struct
{
    UINT8       aucHead[3];     // �ڲ���Ϣ��ǰ�����ֽڶ���0xff
    UINT8       ucMsgID;

    UINT32      ulVer;  /* v1.2.3a = 0x31323361*/
    UINT32      ulSn;   /* ���к� */
}PS_INNER_HEAD_T;

typedef struct
{
    PS_INNER_HEAD_T stHead;

    UINT8           aucUserIP[4];
    CHAR            acACName[128];
    CHAR            acUser[256];
    CHAR            acPwd[256];
}PS_AUTH_REQ_T;

typedef struct
{
    PS_INNER_HEAD_T stHead;

    UINT8   aucUserIP[4];
    INT32   iRet;
}PS_AUTH_ACK_T;

typedef struct
{
    PS_INNER_HEAD_T stHead;

    UINT8           aucUserIP[4];
}PS_LOGOUT_REQ_T;

typedef struct
{
    PS_INNER_HEAD_T stHead;

    UINT8   aucUserIP[4];
    INT32   iRet;
}PS_LOGOUT_ACK_T;

typedef union
{
    PS_AUTH_REQ_T       stAuthReq;
    PS_LOGOUT_REQ_T     stLogoutReq;
}PS_INNER_REQ_MSG_U;

typedef union
{
    PS_AUTH_ACK_T       stAuthAck;
    PS_LOGOUT_ACK_T     stLogoutAck;
}PS_INNER_ACK_MSG_U;

typedef struct
{
    SOCKET      stLocalSocket;
    SOCKADDR    stRemoteAddr;
    INT32       iRemoteAddrLen;
}PS_MSG_SOCKET_T;

VOID    ps_log(INT32 iLogLevel, CHAR *szFormat, ...);
INT32   ps_recv_from(SOCKET stSock, VOID *pMsgBuf, UINT32 ulMsgBufLen, SOCKADDR *pstPsWebAddr, INT32 *piAddrLen, UINT32 ulTimeout);
BOOL    ps_listen_portal_msg(UINT16 usPort);
BOOL    ps_get_local_config(VOID);

#endif

