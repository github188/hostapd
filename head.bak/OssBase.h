/******************************************************************************
模块名      : VOS
文件名      : OssBase.h
相关文件    :
实现功能    : 基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
2008/07/31  雷杰        修改：添加sys/param.h
******************************************************************************/

#ifndef _OSSBASE_H_
#define _OSSBASE_H_

/* 工程类型预编译宏的合法性 */
#if defined (APP_PROJ_AC) || \
    defined (APP_PROJ_AP)
#else
#error Fatal error, need a valid predefined macro of APP_PROJ_XXX !
#endif

/* 底层 OS 宏开关 */
#ifndef _OSWIN32_
#ifndef _LINUX_

#ifdef WIN32
#define _OSWIN32_
#else
#define _LINUX_
#endif

#endif
#endif

/* 根据不同平台包含不同的系统头文件 */
#if defined (_OSWIN32_) /* NT40 */

#pragma warning(disable : 4996) /* To disable deprecation */

/*
 * 关闭告警4115, 避免 WINDOWS 系统头文件出现告警
 * rpcasync.h(45) : warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses
 */
#pragma warning (disable : 4115)

#define _WIN32_WINNT 0x0300 /* 定义 NT 版本, 会影响 SOCKET 的一些定义 */
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

#pragma warning (default : 4115) /* 恢复警告 4115 */

/*
 * 由于 VC 4 级告警太多, 定制几个告警级别:
 * 1) OSS_WARNING_LEVEL = 35: 编译警告级别 3.5, 关闭大量 4 级编译警告
 * 2) OSS_WARNING_LEVEL = 36: 编译警告级别 3.6, 关闭少量 4 级编译警告
 * 3) OSS_WARNING_LEVEL = 40: 编译警告级别 4.0, 打开所有 4 级编译警告
 */
#define OSS_WARNING_LEVEL 35

/*
 * 定制编译警告级别, 必须放在 #include "*.h" 之后才生效.
 * C4214: nonstandard extension used : bit field types other than int
 * C4100: 'lpPara' : unreferenced formal parameter
 * C4127: conditional expression is constant
 * C4206: nonstandard extension used : translation unit is empty
 * C4102: 'SUFFIX_ADDR' : unreferenced label
 */

/* 把C4700警告设置为错误:
 * warning C4700: local variable 'ptAskData' used without having been initialized
 */
#pragma warning (error: 4700)

#if OSS_WARNING_LEVEL == 35 /* 告警级别为 3.5 级 */
#pragma warning (disable : 4100 4102 4127 4206 4214 4505)
#elif OSS_WARNING_LEVEL == 36 /* 告警级别为 3.6 级 */
#pragma warning (disable : 4102 4206 4214)
#elif OSS_WARNING_LEVEL == 40 /* 告警级别为 4.0 级 */
#else /* 无效级别 */
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


/*以下类型在UCLINUX和WINNT下都未定义*/
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

/*以下类型和宏在LINUX下未定义*/
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

#define WLC_WORK_DIR              "etc/"   /* 工作目录名*/
#define WLC_CONFIG_DIR            "config/"  
#define WLC_FACTORY_DIR           ".factory/"
#define WLC_CONFIG_BAK_DIR        "bak/"
#define WLC_TMP_WEB_DIR               "web/"

#define AC_DB_DATA_FILE_NAME    "ac.dat"
#define WLC_LOG_DFT_FILE            "messages"
#define WLC_LOG_KERN_FILE           "kern.log"

#define AC_BR_NAME_BEAR		    "br0"			/* AC承载桥名称*/
#define AC_BR_NAME_FATLAN		"br1:8"			/* AC L2-WAN 桥名称*/
#define AC_BR_NAME_L2WAN		"br1"			/* AC L2-WAN 桥名称*/
#define AC_BR_NAME_L3WAN		"br2"			/* AC L3-WAN 桥名称*/

#endif /* _LINUX_ */

/*以下类型和宏在 nt 下未定义*/
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
