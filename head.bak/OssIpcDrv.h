/******************************************************************************
模块名      : IPCDRV
文件名      : OssIpcDrv.h
相关文件    :
实现功能    : IPCDRV 接口声明
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
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

/* shutdown 选项 */
#define SD_RECEIVE              (INT) 0
#define SD_SEND                 (INT) 1
#define SD_BOTH                 (INT) 2

#define SENOTINITIALISED        0    /* 用于适配, vxworks下无需初始化 */
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

/* 适配 WINNT 下的 socket 接口 */
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

/* 自定义的错误号 */
#define SELENMISMATCH           ((INT) -10)

/* TCP/UDP 服务器断口 */
#define TCP_SERVER_PORT         	(WORD16) 5001
#define UDP_SERVER_PORT         	(WORD16) 5002
#define UDP_NB_SERVER_PORT      	(WORD16) 5003
#define TCP_MS_SERVER_PORT       (WORD16) 5004
#define TCP_WEB_SERVER_PORT	(WORD16) 5005
#define UDP_MS_SERVER_PORT	(WORD16)5006		/* 2011-6-21AC 主备间通信端口*/

/* 组播宏定义 */
#define VMIPC_GROUP_NUM         3 /* 必需小于 255 */
#define VMIPC_GROUP_ALL         0 /* 所有 CPU, 广播组 */
#define VMIPC_GROUP_AC          1 
#define VMIPC_GROUP_AP          2 

/* 用于连接控制的宏 */
/* pyy 2009-10-22 最大连接数由40修改为512 */
#ifdef APP_PROJ_AC
#define MAX_CONN            (WORD32) 512                         	 	/* 最大连接数 */
#else
#define MAX_CONN            (WORD32) 40                         	 		/* 最大连接数 */
#endif

/* mod by gwx 2012-12-17 for AP/VAP级流控，新增用户流控表下发AP，VmASend消息长度扩容*/
#if 0 
#define MAX_MSG_LENGTH      (WORD16) 48*1024                      	/* 非主备消息的长度限制 */
#else
#define MAX_MSG_LENGTH      (WORD16) 52*1024                      	/* 非主备消息的长度限制 */
#endif
#define LINE_BUF_SIZE       (WORD16) (MAX_MSG_LENGTH + 32)       /* 缓冲区大小,32为TMsgStruc的大小 */
#define CONN_QUEUE_SIZE     (WORD32) 10                          		/* 请求TCP服务的队列长度 */

#define CONN_NONE           (BYTE) 0
#define CONN_ACTIVE         (BYTE) 1
#define CONN_CLOSED         (BYTE) 2

#define IPCTRACE_MSGSIZE_DISTRIBUTION  ((BYTE) 9)  /* IPC连接上收发的包长的监控分段方式(如: <1k,1k - 2k,..., >8k) */

typedef struct
{
	WORD wAcId;
	WORD wApId;
}TLogicAddr; /* logic board */

/* the class B IP address,netmask is 255.255.0.0 */
typedef struct
{
    BYTE byNet1; /* 网络地址 */
    BYTE byNet2; /* 网络地址 */
    BYTE byNode1; /* 节点地址 */
    BYTE byNode2; /* 节点地址 */
}TIPAddr;

typedef struct
{    
    BYTE        byUse;       /* 是否有效 */
    TLogicAddr  tLogicAddr;  /* 逻辑地址 */
    TIPAddr     tIPAddr;     /* 对应IP地址 */
    WORD32	dwCommPort;		/* 通信端口号 add by gwx 2013-4-7 for task668*/
    TIPAddr	tCommAddr;		/* 通信IP地址 add by gwx 2013-4-7 for task668*/	
} TAddrMapTable;

/* 连接消息表 */
typedef struct
{
    BYTE      byStatus;                  /* CCB标志: CONN_ACTIVE, CONN_NONE,CONN_CLOSED */
    SOCKET    tConnSock;                 /* 该连接对应的socket */
    WORD32    dwPeerAddr;                /* 该连接对应的对端IP地址(网络字节序) */
    WORD16    wPeerPort;                 /* 该连接对应的对端port号(网络字节序) */
    BOOL      bConnFromMe;               /* 是否是本地发起建的连接 */
    WORD32    dwConnSetupTick;           /* 本连接创建完成时的tick数 (即为连接建成时间)*/
    WORD32    dwSequSEWOULDBLOCKErrCount;/* 连续发生SEWOULDBLOCK错误的次数 */
    WORD32    dwSuccSendMsgCount;        /* 连接上发送成功的消息数目 */
    WORD32    dwErrSendMsgCount;         /* 连接上发送失败的消息数目 */
    WORD32    dwSuccRecvMsgCount;        /* 连接上接收成功的消息数目 */
    WORD32    dwErrRecvMsgCount;         /* 连接上接收失败的消息数目 */
} TCCBStruct;

typedef struct tagConnTable
{
    OSTOKEN     tSem;                       /* 保护该连接表的信号量 */
    BYTE        byConnCount;                /* 连接的个数 */
    TIPAddr     tLocalIPAddr;               /* 本地IP地址 */
    TCCBStruct  atConnect[MAX_CONN];        /* 连接表 */

    BOOL        bIfTraceSend;               /* 是否进行发送情况统计 */
    BOOL        bIfTraceRecv;               /* 是否进行接收情况统计 */
} TConnTable;

/* 普通TCP通信接收buffer */
typedef struct
{
    BYTE        abyBuffer[LINE_BUF_SIZE];
    WORD32      dwUsedBufSize;
} TPreMsgBufStruct;

/* 主备TCP通信接收buffer */
typedef struct
{
    SOCKET      tSock;
    BYTE        abyBuffer[LINE_BUF_SIZE];
    WORD32      dwUsedBufSize;
} TMsPreMsgBufStruct;

/* 打印信息控制结构，以便调试 */
typedef struct tagVmipcDebugConf
{
    BOOL    bIfPrintOn; /* 是否开启打印 */
    WORD16  wRecvPno; /* 要查看的接收者进程 */
    WORD16  wEvent; /* 要查看的事件 */
}TVmipcDebugConf;

/* IP 组播结构 */
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
extern fd_set               gtFdSet;                /* 所有连接用到的socket集合 */
extern TConnTable           gtConnTable;            /* 连接表 */
extern TPreMsgBufStruct     *gaptPreMsgBuffer[];
extern BYTE                 gabyRecvBuf[];
extern SOCKET               gtUdpSock;
extern SOCKET               gtUdpMsSock;
extern WORD32               gadwGroupIpAddr[];
extern OSTOKEN              gtConnTaskMbox;
extern SOCKET               gtBkConnSock;          	/* 和后台的连接 */
extern SOCKET		   gtWebConnSock;		/* 和AC-WEB之间连接的socket */
extern SOCKET               gtCurRcvSock;           	/* 当前正在进行接收处理的socket */

BOOL        InitSock                (VOID);                     /* 初始化套接字 */
BOOL        InitConnTable           (VOID);                     /* 初始化连接表 */
BOOL        InitIPCMoni             (VOID);                     /* 初始化IPC的监控信息 */
WORD32      SaveConnect             (SOCKET, WORD32, WORD16, BOOL);   /* 在连接表中查找空闲的连接控制块,然后保存新的连接 */
VOID        CloseConnect            (SOCKET, BOOL);                   /* 关闭连接 */
VOID		CloseAllConnect			(VOID);
VOID		CloseConnectByIpAddr	(TIPAddr tIpAddr);
WORD32      GetPreMsgBufIndex       (SOCKET tSock);
VOID        RetPreMsgBuf            (WORD32 dwIndex);
BOOL        LogicAddr2IpAddr        (TLogicAddr, TIPAddr*);     /* 将TPID中的逻辑地址转换为IP地址 */
BOOL        LogicAddr2IpAddrAndPort        (TLogicAddr, TIPAddr*,WORD32*);     /* 根据逻辑地址获取目标Ip和端口 add by gwx 2013-4-7 for task668*/
VOID        DispSockErr             (INT);
BOOL        GetIfIpAddr             (CHAR *szIfName, TIPAddr *ptIpAddr);
WORD32      GetConnBySock           (SOCKET);                   /* 通过SOCKET查找相应的连接号 */
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
