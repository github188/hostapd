#ifndef AC_PS_DEF_H
#define AC_PS_DEF_H

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

#endif
