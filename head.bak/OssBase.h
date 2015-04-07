/******************************************************************************
ģ����      : VOS
�ļ���      : OssBase.h
����ļ�    :
ʵ�ֹ���    : ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
2008/07/31  �׽�        �޸ģ����sys/param.h
******************************************************************************/

#ifndef _OSSBASE_H_
#define _OSSBASE_H_

/* ��������Ԥ�����ĺϷ��� */
#if defined (APP_PROJ_AC) || \
    defined (APP_PROJ_AP)
#else
#error Fatal error, need a valid predefined macro of APP_PROJ_XXX !
#endif

/* �ײ� OS �꿪�� */
#ifndef _OSWIN32_
#ifndef _LINUX_

#ifdef WIN32
#define _OSWIN32_
#else
#define _LINUX_
#endif

#endif
#endif

/* ���ݲ�ͬƽ̨������ͬ��ϵͳͷ�ļ� */
#if defined (_OSWIN32_) /* NT40 */

#pragma warning(disable : 4996) /* To disable deprecation */

/*
 * �رո澯4115, ���� WINDOWS ϵͳͷ�ļ����ָ澯
 * rpcasync.h(45) : warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses
 */
#pragma warning (disable : 4115)

#define _WIN32_WINNT 0x0300 /* ���� NT �汾, ��Ӱ�� SOCKET ��һЩ���� */
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <io.h>
#include <time.h>
#include <errno.h>
#include <direct.h>
#include <winbase.h>

#pragma warning (default : 4115) /* �ָ����� 4115 */

/*
 * ���� VC 4 ���澯̫��, ���Ƽ����澯����:
 * 1) OSS_WARNING_LEVEL = 35: ���뾯�漶�� 3.5, �رմ��� 4 �����뾯��
 * 2) OSS_WARNING_LEVEL = 36: ���뾯�漶�� 3.6, �ر����� 4 �����뾯��
 * 3) OSS_WARNING_LEVEL = 40: ���뾯�漶�� 4.0, ������ 4 �����뾯��
 */
#define OSS_WARNING_LEVEL 35

/*
 * ���Ʊ��뾯�漶��, ������� #include "*.h" ֮�����Ч.
 * C4214: nonstandard extension used : bit field types other than int
 * C4100: 'lpPara' : unreferenced formal parameter
 * C4127: conditional expression is constant
 * C4206: nonstandard extension used : translation unit is empty
 * C4102: 'SUFFIX_ADDR' : unreferenced label
 */

/* ��C4700��������Ϊ����:
 * warning C4700: local variable 'ptAskData' used without having been initialized
 */
#pragma warning (error: 4700)

#if OSS_WARNING_LEVEL == 35 /* �澯����Ϊ 3.5 �� */
#pragma warning (disable : 4100 4102 4127 4206 4214 4505)
#elif OSS_WARNING_LEVEL == 36 /* �澯����Ϊ 3.6 �� */
#pragma warning (disable : 4102 4206 4214)
#elif OSS_WARNING_LEVEL == 40 /* �澯����Ϊ 4.0 �� */
#else /* ��Ч���� */
#pragma error Invalid OSS_WARNING_LEVEL
#endif

#elif defined (_LINUX_) /* LINUX */

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
#include <netinet/in.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <semaphore.h>
#include <sys/sysinfo.h>
#include <sys/times.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
//int sem_timedwait(sem_t * sem, struct timespec * abs_timeout);
#endif /* _LINUX_ */


/*����������UCLINUX��WINNT�¶�δ����*/
/*
typedef unsigned short WORD16;
typedef unsigned long WORD32;
*/
#ifndef WORD16
#define WORD16 unsigned short
#endif

#ifndef WORD32
#define WORD32 unsigned long
#endif

/*�������ͺͺ���LINUX��δ����*/
#if defined(_LINUX_)
/*
typedef int BOOL;
typedef int INT;
typedef int LONG32, *PLONG32;
typedef char CHAR;
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
*/
#ifndef BOOL
#define BOOL int
#endif

#ifndef INT
#define INT int
#endif

#ifndef LONG32
#define LONG32 int
#endif

#ifndef PLONG32
#define PLONG32 int *
#endif

#ifndef CHAR
#define CHAR char
#endif

#ifndef PSTR
#define PSTR char *
#endif

#ifndef PCHAR
#define PCHAR char *
#endif

#ifndef LPSTR
#define LPSTR char *
#endif

#ifndef LPTSTR
#define LPTSTR char *
#endif

#ifndef PBYTE
#define PBYTE unsigned char *
#endif

#ifndef LPBYTE
#define LPBYTE unsigned char *
#endif

#ifndef SHORT
#define SHORT short
#endif

#ifndef PWORD
#define PWORD unsigned short *
#endif

#ifndef LPWORD
#define LPWORD unsigned short *
#endif

#ifndef LONG
#define LONG long
#endif

#ifndef PDWORD
#define PDWORD unsigned long *
#endif

#ifndef LPDWORD
#define LPDWORD unsigned long *
#endif

#ifndef LPVOID
#define LPVOID void *
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef HANDLE
#define HANDLE void *
#endif

#ifndef WORD
#define WORD unsigned short
#endif

#ifndef DWORD
#define DWORD unsigned long
#endif

#ifndef FLOAT
#define FLOAT float
#endif

#ifndef DOUBLE
#define DOUBLE double
#endif

#define _mkdir    mkdir
#define WINAPI
#define DIR_SEPARATOR '/'
#define VOID void

#define WLC_ROOT            "WLCROOT"
#define CMS_ROOT            "CMSROOT"
#define USR_ROOT            "USRROOT"
#define LOG_ROOT            "/var/log/"
#define TMP_ROOT            "/tmp/"

#define WLC_WORK_DIR              "etc/"   /* ����Ŀ¼��*/
#define WLC_CONFIG_DIR            "config/"  
#define WLC_FACTORY_DIR           ".factory/"
#define WLC_CONFIG_BAK_DIR        "bak/"
#define WLC_TMP_WEB_DIR               "web/"

#define AC_DB_DATA_FILE_NAME    "ac.dat"
#define WLC_LOG_DFT_FILE            "messages"
#define WLC_LOG_KERN_FILE           "kern.log"

#define AC_BR_NAME_BEAR		    "br0"			/* AC����������*/
#define AC_BR_NAME_FATLAN		"br1:8"			/* AC L2-WAN ������*/
#define AC_BR_NAME_L2WAN		"br1"			/* AC L2-WAN ������*/
#define AC_BR_NAME_L3WAN		"br2"			/* AC L3-WAN ������*/

#endif /* _LINUX_ */

/*�������ͺͺ��� nt ��δ����*/
#ifdef _OSWIN32_
#define DIR_SEPARATOR    '\\'
#endif /*_OSWIN32_ */

#define WAIT_FOREVER    0xFFFFFFFF  /* Infinite timeout */
#define NO_WAIT         (WORD32)0   /* don't wait */

#define OSTOKEN WORD32
#define FHANDLE    INT

#ifdef TRUE
#undef TRUE
#define TRUE 1
#else
#define TRUE 1
#endif

#ifdef FALSE
#undef FALSE
#define FALSE 0
#else
#define FALSE 0
#endif

#define OSS_DEBUG

#ifdef OSS_DEBUG
#define PRIVATE
#else
#define PRIVATE    static
#endif

#endif /* end of _OSSBASE_H_ */
