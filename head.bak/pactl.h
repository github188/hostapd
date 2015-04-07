#ifndef PACTL_H
#define PACTL_H

#ifdef APP_PROJ_AC
#undef APP_PROJ_AC
#endif

#ifdef WIN32
#include <winsock2.h>
#include <direct.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#else

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include <sys/times.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/param.h>

#endif

#define UINT8   unsigned char
#define UINT16  unsigned short
#define UINT32  unsigned long

#define INT8    char
#define INT16   short
#define INT32   int

#define INT     INT32

#define CHAR    char
#define VOID    void
#define BOOL    int

#define BYTE    UINT8

#define DWORD   UINT32

#define TRUE    1
#define FALSE   0

#ifdef WIN32
#define socklen_t				INT
#else

typedef unsigned int            SOCKET;
typedef struct sockaddr_in      SOCKADDR_IN;
typedef struct timeval          TIMEVAL;
typedef struct sockaddr			SOCKADDR;
#endif

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
#define FILE_SPLIT  '\\'
#else
#define FILE_SPLIT  '/'
#endif

#ifdef WIN32
#define sleep(x)    Sleep(x*1000)
#endif

#define IP_FMT  "%d.%d.%d.%d"
#define IP_ARG(x)   ((UINT8*)x)[0],((UINT8*)x)[1],((UINT8*)x)[2],((UINT8*)x)[3]

#define MAC_FMT  "%02X-%02X-%02X-%02X-%02X-%02X"
#define MAC_ARG(x)   ((UINT8*)x)[0],((UINT8*)x)[1],((UINT8*)x)[2],((UINT8*)x)[3],((UINT8*)x)[4],((UINT8*)x)[5]

#define HTONL(a)        (htonl((a)))
#define HTONL_IT(a)     ((a) = HTONL((a)))

#define HTONS(a)        (htons((a)))
#define HTONS_IT(a)     ((a) = HTONS((a)))

#define NTOHL(a)        (ntohl((a)))
#define NTOHL_IT(a)     ((a) = NTOHL((a)))

#define NTOHS(a)        (ntohs((a)))
#define NTOHS_IT(a)     ((a) = NTOHS((a)))

typedef struct
{
    UINT8   aucPaIP[4];

    UINT16  usPaPort;
    UINT16  usTimeout;
}PA_LOCAL_CFG_T;


#endif
