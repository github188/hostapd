/******************************************************************************
ģ����      : IPCDRV
�ļ���      : OssIpcDrv.h
����ļ�    :
ʵ�ֹ���    : IPCDRV �ӿ�����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSIPCDRV_H_
#define _OSSIPCDRV_H_


#define	INET_ADDR_LEN          18

#ifdef _LINUX_
#define INVALID_SOCKET          (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#define closesocket             close
#define ioctlsocket(a, b, c)    ioctl(a, b, (INT)c)
#define GetSockErr()            errno
#define SetSockErr(err)			{errno = err;}

typedef unsigned int            SOCKET;
typedef struct sockaddr_in      SOCKADDR_IN;
typedef struct timeval          TIMEVAL;
typedef struct sockaddr			SOCKADDR;

/* shutdown ѡ�� */
#define SD_RECEIVE              (INT) 0
#define SD_SEND                 (INT) 1
#define SD_BOTH                 (INT) 2

#define SENOTINITIALISED        0    /* ��������, vxworks�������ʼ�� */
#define SEWOULDBLOCK            EWOULDBLOCK
#define SEINPROGRESS            EINPROGRESS
#define SEALREADY               EALREADY
#define SENOTSOCK               ENOTSOCK
#define SEDESTADDRREQ           EDESTADDRREQ
#define SEMSGSIZE               EMSGSIZE
#define SEPROTOTYPE             EPROTOTYPE
#define SENOPROTOOPT            ENOPROTOOPT
#define SEPROTONOSUPPORT        EPROTONOSUPPORT
#define SESOCKTNOSUPPORT        ESOCKTNOSUPPORT
#define SEOPNOTSUPP             EOPNOTSUPP
#define SEPFNOSUPPORT           EPFNOSUPPORT
#define SEAFNOSUPPORT           EAFNOSUPPORT
#define SEADDRINUSE             EADDRINUSE
#define SEADDRNOTAVAIL          EADDRNOTAVAIL
#define SENETDOWN               ENETDOWN
#define SENETUNREACH            ENETUNREACH
#define SENETRESET              ENETRESET
#define SECONNABORTED           ECONNABORTED
#define SECONNRESET             ECONNRESET
#define SENOBUFS                ENOBUFS
#define SEISCONN                EISCONN
#define SENOTCONN               ENOTCONN
#define SESHUTDOWN              ESHUTDOWN
#define SETOOMANYREFS           ETOOMANYREFS
#define SETIMEDOUT              ETIMEDOUT
#define SECONNREFUSED           ECONNREFUSED
#define SELOOP                  ELOOP
#define SEHOSTDOWN              EHOSTDOWN
#define SEHOSTUNREACH           EHOSTUNREACH
#define SEPROCLIM               EPROCLIM
#define SEUSERS                 EUSERS
#define SEDQUOT                 EDQUOT
#define SESTALE                 ESTALE
#define SEREMOTE                EREMOTE
#define SEFAULT                 EFAULT
#define SEINVAL                 EINVAL
#define SEINVALFD               ENOTSOCK
#endif /* _LINUX_ */

/* ���� WINNT �µ� socket �ӿ� */
#ifdef _OSWIN32_
#define socklen_t				INT						
#define GetSockErr              WSAGetLastError
#define SetSockErr				WSASetLastError
#define SEWOULDBLOCK            WSAEWOULDBLOCK
#define SEINPROGRESS            WSAEINPROGRESS
#define SEALREADY               WSAEALREADY
#define SENOTSOCK               WSAENOTSOCK
#define SEDESTADDRREQ           WSAEDESTADDRREQ
#define SEMSGSIZE               WSAEMSGSIZE
#define SEPROTOTYPE             WSAEPROTOTYPE
#define SENOPROTOOPT            WSAENOPROTOOPT
#define SEPROTONOSUPPORT        WSAEPROTONOSUPPORT
#define SESOCKTNOSUPPORT        WSAESOCKTNOSUPPORT
#define SEOPNOTSUPP             WSAEOPNOTSUPP
#define SEPFNOSUPPORT           WSAEPFNOSUPPORT
#define SEAFNOSUPPORT           WSAEAFNOSUPPORT
#define SEADDRINUSE             WSAEADDRINUSE
#define SEADDRNOTAVAIL          WSAEADDRNOTAVAIL
#define SENETDOWN               WSAENETDOWN
#define SENETUNREACH            WSAENETUNREACH
#define SENETRESET              WSAENETRESET
#define SECONNABORTED           WSAECONNABORTED
#define SECONNRESET             WSAECONNRESET
#define SENOBUFS                WSAENOBUFS
#define SEISCONN                WSAEISCONN
#define SENOTCONN               WSAENOTCONN
#define SESHUTDOWN              WSAESHUTDOWN
#define SETOOMANYREFS           WSAETOOMANYREFS
#define SETIMEDOUT              WSAETIMEDOUT
#define SECONNREFUSED           WSAECONNREFUSED
#define SELOOP                  WSAELOOP
#define SEHOSTDOWN              WSAEHOSTDOWN
#define SEHOSTUNREACH           WSAEHOSTUNREACH
#define SEPROCLIM               WSAEPROCLIM
#define SEUSERS                 WSAEUSERS
#define SEDQUOT                 WSAEDQUOT
#define SESTALE                 WSAESTALE
#define SEREMOTE                WSAEREMOTE
#define SEFAULT                 WSAEFAULT
#define SEINVAL                 WSAEINVAL
#define SENOTINITIALISED        WSANOTINITIALISED
#define SEINVALFD               WSAENOTSOCK
#endif  /* _OSWIN32_ */

/* �Զ���Ĵ���� */
#define SELENMISMATCH           ((INT) -10)

/* TCP/UDP �������Ͽ� */
#define TCP_SERVER_PORT         	(WORD16) 5001
#define UDP_SERVER_PORT         	(WORD16) 5002
#define UDP_NB_SERVER_PORT      	(WORD16) 5003
#define TCP_MS_SERVER_PORT       (WORD16) 5004
#define TCP_WEB_SERVER_PORT	(WORD16) 5005
#define UDP_MS_SERVER_PORT	(WORD16)5006		/* 2011-6-21AC ������ͨ�Ŷ˿�*/

/* �鲥�궨�� */
#define VMIPC_GROUP_NUM         3 /* ����С�� 255 */
#define VMIPC_GROUP_ALL         0 /* ���� CPU, �㲥�� */
#define VMIPC_GROUP_AC          1 
#define VMIPC_GROUP_AP          2 

/* �������ӿ��Ƶĺ� */
/* pyy 2009-10-22 �����������40�޸�Ϊ512 */
#ifdef APP_PROJ_AC
#define MAX_CONN            (WORD32) 512                         	 	/* ��������� */
#else
#define MAX_CONN            (WORD32) 40                         	 		/* ��������� */
#endif

/* mod by gwx 2012-12-17 for AP/VAP�����أ������û����ر��·�AP��VmASend��Ϣ��������*/
#if 0 
#define MAX_MSG_LENGTH      (WORD16) 48*1024                      	/* ��������Ϣ�ĳ������� */
#else
#define MAX_MSG_LENGTH      (WORD16) 52*1024                      	/* ��������Ϣ�ĳ������� */
#endif
#define LINE_BUF_SIZE       (WORD16) (MAX_MSG_LENGTH + 32)       /* ��������С,32ΪTMsgStruc�Ĵ�С */
#define CONN_QUEUE_SIZE     (WORD32) 10                          		/* ����TCP����Ķ��г��� */

#define CONN_NONE           (BYTE) 0
#define CONN_ACTIVE         (BYTE) 1
#define CONN_CLOSED         (BYTE) 2

#define IPCTRACE_MSGSIZE_DISTRIBUTION  ((BYTE) 9)  /* IPC�������շ��İ����ļ�طֶη�ʽ(��: <1k,1k - 2k,..., >8k) */

typedef struct
{
	WORD wAcId;
	WORD wApId;
}TLogicAddr; /* logic board */

/* the class B IP address,netmask is 255.255.0.0 */
typedef struct
{
    BYTE byNet1; /* �����ַ */
    BYTE byNet2; /* �����ַ */
    BYTE byNode1; /* �ڵ��ַ */
    BYTE byNode2; /* �ڵ��ַ */
}TIPAddr;

typedef struct
{    
    BYTE        byUse;       /* �Ƿ���Ч */
    TLogicAddr  tLogicAddr;  /* �߼���ַ */
    TIPAddr     tIPAddr;     /* ��ӦIP��ַ */
    WORD32	dwCommPort;		/* ͨ�Ŷ˿ں� add by gwx 2013-4-7 for task668*/
    TIPAddr	tCommAddr;		/* ͨ��IP��ַ add by gwx 2013-4-7 for task668*/	
} TAddrMapTable;

/* ������Ϣ�� */
typedef struct
{
    BYTE      byStatus;                  /* CCB��־: CONN_ACTIVE, CONN_NONE,CONN_CLOSED */
    SOCKET    tConnSock;                 /* �����Ӷ�Ӧ��socket */
    WORD32    dwPeerAddr;                /* �����Ӷ�Ӧ�ĶԶ�IP��ַ(�����ֽ���) */
    WORD16    wPeerPort;                 /* �����Ӷ�Ӧ�ĶԶ�port��(�����ֽ���) */
    BOOL      bConnFromMe;               /* �Ƿ��Ǳ��ط��𽨵����� */
    WORD32    dwConnSetupTick;           /* �����Ӵ������ʱ��tick�� (��Ϊ���ӽ���ʱ��)*/
    WORD32    dwSequSEWOULDBLOCKErrCount;/* ��������SEWOULDBLOCK����Ĵ��� */
    WORD32    dwSuccSendMsgCount;        /* �����Ϸ��ͳɹ�����Ϣ��Ŀ */
    WORD32    dwErrSendMsgCount;         /* �����Ϸ���ʧ�ܵ���Ϣ��Ŀ */
    WORD32    dwSuccRecvMsgCount;        /* �����Ͻ��ճɹ�����Ϣ��Ŀ */
    WORD32    dwErrRecvMsgCount;         /* �����Ͻ���ʧ�ܵ���Ϣ��Ŀ */
} TCCBStruct;

typedef struct tagConnTable
{
    OSTOKEN     tSem;                       /* ���������ӱ���ź��� */
    BYTE        byConnCount;                /* ���ӵĸ��� */
    TIPAddr     tLocalIPAddr;               /* ����IP��ַ */
    TCCBStruct  atConnect[MAX_CONN];        /* ���ӱ� */

    BOOL        bIfTraceSend;               /* �Ƿ���з������ͳ�� */
    BOOL        bIfTraceRecv;               /* �Ƿ���н������ͳ�� */
} TConnTable;

/* ��ͨTCPͨ�Ž���buffer */
typedef struct
{
    BYTE        abyBuffer[LINE_BUF_SIZE];
    WORD32      dwUsedBufSize;
} TPreMsgBufStruct;

/* ����TCPͨ�Ž���buffer */
typedef struct
{
    SOCKET      tSock;
    BYTE        abyBuffer[LINE_BUF_SIZE];
    WORD32      dwUsedBufSize;
} TMsPreMsgBufStruct;

/* ��ӡ��Ϣ���ƽṹ���Ա���� */
typedef struct tagVmipcDebugConf
{
    BOOL    bIfPrintOn; /* �Ƿ�����ӡ */
    WORD16  wRecvPno; /* Ҫ�鿴�Ľ����߽��� */
    WORD16  wEvent; /* Ҫ�鿴���¼� */
}TVmipcDebugConf;

/* IP �鲥�ṹ */
typedef struct ip_mreq    TIpMultiReq;

#define    EUM_MSG_HEAD_INCOMPLETE      (WORD32) 1
#define    EUM_MSG_LEN_MISMATCH         (WORD32) 2
#define    EUM_MSG_ONLINE_REPORT        (WORD32) 4
#define    EUM_MSG_PARSE_ERROR          (WORD32) 8
#define    EUM_MSG_EXTRACT_SUCCESS      (WORD32) 16

#define    ETM_MSG_HEAD_INCOMPLETE      (WORD32) 1
#define    ETM_MSG_LEN_ERROR            (WORD32) 2
#define    ETM_MSG_INCOMPLETE           (WORD32) 4
#define    ETM_MSG_PARSE_ERROR          (WORD32) 8
#define    ETM_MSG_EXTRACT_SUCCESS      (WORD32) 16

#define    INVALID_INDEX                (WORD16)0xffff

/* extern OSTOKEN              gtSendSem; */
extern fd_set               gtFdSet;                /* ���������õ���socket���� */
extern TConnTable           gtConnTable;            /* ���ӱ� */
extern TPreMsgBufStruct     *gaptPreMsgBuffer[];
extern BYTE                 gabyRecvBuf[];
extern SOCKET               gtUdpSock;
extern SOCKET               gtUdpMsSock;
extern WORD32               gadwGroupIpAddr[];
extern OSTOKEN              gtConnTaskMbox;
extern SOCKET               gtBkConnSock;          	/* �ͺ�̨������ */
extern SOCKET		   gtWebConnSock;		/* ��AC-WEB֮�����ӵ�socket */
extern SOCKET               gtCurRcvSock;           	/* ��ǰ���ڽ��н��մ����socket */

BOOL        InitSock                (VOID);                     /* ��ʼ���׽��� */
BOOL        InitConnTable           (VOID);                     /* ��ʼ�����ӱ� */
BOOL        InitIPCMoni             (VOID);                     /* ��ʼ��IPC�ļ����Ϣ */
WORD32      SaveConnect             (SOCKET, WORD32, WORD16, BOOL);   /* �����ӱ��в��ҿ��е����ӿ��ƿ�,Ȼ�󱣴��µ����� */
VOID        CloseConnect            (SOCKET, BOOL);                   /* �ر����� */
VOID		CloseAllConnect			(VOID);
VOID		CloseConnectByIpAddr	(TIPAddr tIpAddr);
WORD32      GetPreMsgBufIndex       (SOCKET tSock);
VOID        RetPreMsgBuf            (WORD32 dwIndex);
BOOL        LogicAddr2IpAddr        (TLogicAddr, TIPAddr*);     /* ��TPID�е��߼���ַת��ΪIP��ַ */
BOOL        LogicAddr2IpAddrAndPort        (TLogicAddr, TIPAddr*,WORD32*);     /* �����߼���ַ��ȡĿ��Ip�Ͷ˿� add by gwx 2013-4-7 for task668*/
VOID        DispSockErr             (INT);
BOOL        GetIfIpAddr             (CHAR *szIfName, TIPAddr *ptIpAddr);
WORD32      GetConnBySock           (SOCKET);                   /* ͨ��SOCKET������Ӧ�����Ӻ� */
WORD32      GetConnByIPAddr         (WORD32 dwIPAddr);
SOCKET      ConnectTcp              (const CHAR*, WORD16);
WORD32      TcpSend                 (SOCKET s, BYTE* buf, WORD32 SendLen);
INT         UdpSend                 (SOCKET s, BYTE *buf, WORD32 dwLength, WORD32 dwIpAddr, WORD16 wPort);
WORD32      GetFdCount              (fd_set*);
SOCKET      GetSockFromFds          (fd_set*, WORD32);

VOID        UdpRecvMsg              (SOCKET);
VOID        IPAddr2Str              (TIPAddr, CHAR *);
#if 0 /* mod by gwx 2013-4-7 for task668 */
SOCKET      CreateUdpSock           (VOID);
#else
SOCKET      CreateUdpSock           (WORD16 udpPort);
#endif
WORD32      GetConnByIPAddrStr      (const CHAR *pIPAddr);
BOOL        IpAddr2LogicAddr        (TIPAddr tIpAddr, TLogicAddr *ptLogicBoard);
INT			ConnectWithTimeout		(SOCKET tSock, SOCKADDR *ptSockAddr, INT iAddrLen);
BOOL        GetSelfIpAddr           (TIPAddr *ptIpAddr);
VOID        ResetAddrHashTable      (VOID);
VOID        InetAddr2Str            (struct in_addr, CHAR *);
WORD16      GetAddrTabIndex         (WORD wAcId, WORD wApId);
WORD32      GetSockFreeSendBuffSize (SOCKET tSock);
#endif /* _OSSIPCDRV_H_ */
