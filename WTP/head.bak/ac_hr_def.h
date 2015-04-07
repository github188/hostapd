#ifndef AC_HR_DEF_H
#define AC_HR_DEF_H

#if 0

#ifndef WIN32
#include "syslog_public.h"
#include "syslogu.h"
#endif

#if defined (WIN32)
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <direct.h>
#include <winbase.h>

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
#include <sys/param.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include <sys/times.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#endif

#if defined (WIN32)
typedef DWORD64	UINT64;
#else
typedef unsigned long long UINT64;
#endif

typedef int             BOOL;
typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned int    UINT32;

typedef char    CHAR;
typedef char    INT8;
typedef short   INT16;
typedef int     INT32;

#ifndef WIN32
typedef int INT;
typedef int LONG32, *PLONG32;
typedef char *PSTR;
typedef char *PCHAR;
typedef char *LPSTR;
typedef char *LPTSTR;
typedef unsigned char *PBYTE;
typedef unsigned char * LPBYTE;
typedef short SHORT;
typedef unsigned short *PWORD;
typedef unsigned short  *LPWORD;
typedef long LONG;
typedef unsigned long *PDWORD;
typedef unsigned long * LPDWORD;
typedef void  *LPVOID;
typedef unsigned char BYTE;
typedef void *HANDLE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef float FLOAT;
typedef double DOUBLE;
#define DIR_SEPARATOR '/'
#endif

#ifndef VOID
#define VOID void
#endif

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

#define TRUE    1
#define FALSE   0

#define VM_MALLOC(size)		        malloc(size)

#define VM_ZALLOC(size)		        calloc(1, size)

#define VM_REALLOC(ptr, size)       realloc(ptr, size)

#define VM_FREE(ptr)						\
do											\
{											\
	if (ptr)								\
	{										\
		free(ptr);							\
		(ptr) = NULL;						\
	}										\
}while(0)

#endif

/* socket */
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

#define SOCKET                  int
#define SOCKADDR                struct sockaddr
#define SOCKADDR_IN             struct sockaddr_in

//#define FD_SET                  fd_set
#define TIMEVAL                 struct timeval

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
typedef int socklen_t;
#endif

#ifndef EINTR
#define EINTR 4
#endif

#ifndef NOFILE
#define NOFILE 64
#endif

#ifdef WIN32
#define sleep(x)        Sleep(x*1000)
#define strcasecmp      stricmp
#define strncasecmp     strnicmp
#define vsnprintf       _vsnprintf
#endif

//#define IP_FMT	"%d.%d.%d.%d"
//#define IP_ARG(x)	((UINT8*)(x))[0],((UINT8*)(x))[1],((UINT8*)(x))[2],((UINT8*)(x))[3]

#define IS_VALID_IP(x) (*((UINT32*)(x)) != 0 && *((UINT32*)(x)) != 0xffffffff)

#endif
