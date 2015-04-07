#ifndef AC_PS_COMM_H
#define AC_PS_COMM_H

#ifdef WIN32
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

#else

#define INVALID_SOCKET          (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#define closesocket             close
#define ioctlsocket(a, b, c)    ioctl(a, b, (INT)c)
#define GetSockErr()            errno
#define SetSockErr(err)			{errno = err;}

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
#endif

#ifdef WIN32
#define sleep(x)    Sleep(x*1000)
#endif

#define IP_FMT  "%d.%d.%d.%d"
#define IP_ARG(x)   ((UINT8*)x)[0],((UINT8*)x)[1],((UINT8*)x)[2],((UINT8*)x)[3]

#define HTONL(a)        (htonl((a)))
#define HTONL_IT(a)     ((a) = HTONL((a)))

#define HTONS(a)        (htons((a)))
#define HTONS_IT(a)     ((a) = HTONS((a)))

#define NTOHL(a)        (ntohl((a)))
#define NTOHL_IT(a)     ((a) = NTOHL((a)))

#define NTOHS(a)        (ntohs((a)))
#define NTOHS_IT(a)     ((a) = NTOHS((a)))

#ifndef WIN32
#define WINAPI
#endif

typedef unsigned long WINAPI ThreadEntry(VOID *);

typedef struct 
{
    CHAR            acThreadName[32];

    UINT32          ulThreadID;
#ifdef WIN32
	HANDLE          tTaskHandle;
#endif

    ThreadEntry     *ptThreadEnrty;

}THREAD_INFO_T;

BOOL    ps_init_socket(VOID);
CHAR*   ps_get_socket_err(VOID);
BOOL    ps_get_byte_ip(CHAR* szIP, UINT8* pucIP);
UINT32  ps_gen_rand(VOID);
UINT16  ps_gen_sn(VOID);
VOID    ps_portal_msg_ntoh(VOID *pstMsg);
VOID    ps_portal_msg_hton(VOID *pstMsg);
VOID    ps_challenge_pwd(CHAR* szPwd, UINT8 chap_id, UINT8* chap_challenge, BYTE *pucChallengedPwd);
BOOL    ps_get_root_path(CHAR *szPath);
CHAR*   ps_get_text_time(VOID);
CHAR*   ps_trim_left(CHAR *szIn);
CHAR*   ps_trim_right(CHAR *szIn);
BOOL    ps_run_as_daemon(VOID);
BOOL    ps_is_proc_running(VOID);
BOOL    create_thread(CHAR *szThreadName, ThreadEntry *pThreadEntry);

#endif
