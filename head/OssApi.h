/******************************************************************************
模块名      : OSS
文件名      : OssApi.h
相关文件    :
实现功能    : OSS模块的接口
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
2008/05/29	李贤平		打印接口修改为ModuleLogMsg
2008/07/31	雷杰  		增加SH_DENYWR等相关宏定义（暂时未找到这些宏定义的标准头文件）
******************************************************************************/
#ifndef _OSSAPI_H_
#define _OSSAPI_H_


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

#pragma warning (disable : 4115 4200 4244) /* rpcasync.h(45) : warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses */
#define _WIN32_WINNT 0x0400 /* 定义 NT 版本, 会影响 SOCKET 的一些定义 */
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
#pragma warning(disable : 4100 4102 4127 4206 4214 4505)
#pragma warning(disable : 4996) /* To disable deprecation */
#pragma warning(disable : 4100) /* warning C4100: unreferenced formal parameter */
#pragma warning(disable : 4201)
#elif OSS_WARNING_LEVEL == 36 /* 告警级别为 3.6 级 */
#pragma warning(disable : 4102 4206 4214)
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
#endif /* _LINUX_ */

#include "OssModule.h"

/*以下类型在UCLINUX和WINNT下都未定义*/
#ifndef WORD16
#define WORD16 unsigned short
#endif

#ifndef WORD32
#define WORD32 unsigned long
#endif

/*
typedef unsigned short WORD16;
typedef unsigned long WORD32;
*/

/*以下类型和宏在LINUX下未定义*/
#if defined(_LINUX_)
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

#define _mkdir    mkdir
#define WINAPI
#define DIR_SEPARATOR '/'
#define VOID void

#define WLC_BIN_DIR               "bin/"
#define WLC_WORK_DIR              "etc/"   /* 工作目录名*/
#define WLC_CONFIG_DIR            "config/"
#define WLC_CONFIG_LICENSE_DIR    "license/"
#define WLC_VERSION_DIR           "version/"
#define WLC_FACTORY_DIR           ".factory/"
#define WLC_FACTORY_SET_DIR       "setting/"
#define WLC_TMP_WEB_DIR           "web/"

#define WLC_CONFIG_BAK_DIR        "bak/"
#define WLC_LOG_DFT_FILE          "messages"
#define WLC_LOG_KERN_FILE         "kern.log"

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


WORD32 VmCurrentTick (VOID);
WORD32 VmCreateLock(VOID);
BOOL VmDeleteLock (WORD32);
BOOL VmLock (WORD32, WORD32);
BOOL VmUnLock (WORD32);

/* 日志级别 */
#define APP_DETAIL          (BYTE) 0
#define APP_MSG             (BYTE) 1
#define APP_WARN            (BYTE) 2
#define APP_ERROR           (BYTE) 3
#define APP_FAIL            (BYTE) 4
#define APP_FATAL           (BYTE) 5


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

#ifdef _LINUX_
VOID    ModulePrint (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...)
            __attribute__ ((format (printf, 3, 4)));
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif /* _LINUX_ */

#ifdef _OSWIN32_
VOID    ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif /* _OSWIN32_ */


/* 定时器的编号，因为需要与定时事件号关联，其值不能修改 */
#define TIMER0              (BYTE)0     /* 定时器0 */
#define TIMER1              (BYTE)1     /* 定时器1 */
#define TIMER2              (BYTE)2     /* 定时器2 */
#define TIMER3              (BYTE)3     /* 定时器3 */
#define TIMER4              (BYTE)4     /* 定时器4 */
#define TIMER5              (BYTE)5     /* 定时器5 */
#define TIMER6              (BYTE)6     /* 定时器6 */
#define TIMER7              (BYTE)7     /* 定时器7 */
#define TIMER8              (BYTE)8     /* 定时器8 */
#define TIMER9              (BYTE)9     /* 定时器9 */
#define TIMER10             (BYTE)10    /* 定时器10 */
#define TIMER11             (BYTE)11    /* 定时器11 */
#define TIMER12             (BYTE)12    /* 定时器12 */
#define TIMER13             (BYTE)13    /* 定时器13 */
#define TIMER14             (BYTE)14    /* 定时器14 */
#define TIMER15             (BYTE)15    /* 定时器15 */
#define TIMER16             (BYTE)16    /* 定时器16 */
#define TIMER17             (BYTE)17    /* 定时器17 */
#define TIMER18             (BYTE)18    /* 定时器18 */
#define TIMER19             (BYTE)19    /* 定时器19 */
#define TIMER20             (BYTE)20    /* 定时器20 */
#define TIMER21             (BYTE)21    /* 定时器21 */
#define TIMER22             (BYTE)22    /* 定时器22 */
#define TIMER23             (BYTE)23    /* 定时器23 */
#define TIMER24             (BYTE)24    /* 定时器24 */
#define TIMER25             (BYTE)25    /* 定时器25 */
#define TIMER26             (BYTE)26    /* 定时器26 */
#define TIMER27             (BYTE)27    /* 定时器27 */
#define TIMER28             (BYTE)28    /* 定时器28 */
#define TIMER29             (BYTE)29    /* 定时器29 */
#define TIMER30             (BYTE)30    /* 定时器30 */
#define TIMER31             (BYTE)31    /* 定时器31 */
#define TID_ERROR           (WORD16) 0xFFFF /* 出错TID值 */


/* 重启原因 */
#define VM_RESET_NORMAL             (INT)0              /* RESET原因，正常重起 */
#define VM_RESET_POWERON_FAILURE    (INT)4              /* RESET原因, 基本进程上电失败 */
#define VM_RESET_INVALID_VERSION    (INT)5              /* RESET原因，无效版本 */
#define VM_RESET_DATA_SYNC_FAIL     (INT)6              /* RESET原因，数据同步失败 */
#define VM_RESET_BY_OMCR            (INT)7              /* RESET原因，后台请求重起 */
#define VM_RESET_UPLINK_BREAK       (INT)8              /* RESET原因, 检测不到上层CPU */
#define VM_RESET_ADDR_MISSED        (INT)9              /* RESET原因, 自身地址不在地址表中 */
#define VM_RESET_UPCPU_POWERON      (INT)10             /* RESET原因, 上级CPU重启 */
#define VM_RESET_BY_CPUBLOCK        (INT)12             /* RESET原因, CPU被闭塞 */
#define VM_RESET_SELFOFFLINE        (INT)13             /* RESET原因, 本板通讯断 */
#define VM_RESET_PROC_CHECK_FAIL	(INT)14		/* RESET原因, 应用进程保活失败*/

/****************************************
 * 定时器消息                           *
 ****************************************/
#define EV_VMTM_BEGIN               (WORD16)1000
/* 以下定时事件号的定义需要与 TIMER0... 关联上 */
#define EV_TIMER0             (WORD16)(EV_VMTM_BEGIN + 0)  /* 定时器0事件 */
#define EV_TIMER1             (WORD16)(EV_VMTM_BEGIN + 1)  /* 定时器1事件 */
#define EV_TIMER2             (WORD16)(EV_VMTM_BEGIN + 2)  /* 定时器2事件 */
#define EV_TIMER3             (WORD16)(EV_VMTM_BEGIN + 3)  /* 定时器3事件 */
#define EV_TIMER4             (WORD16)(EV_VMTM_BEGIN + 4)  /* 定时器4事件 */
#define EV_TIMER5             (WORD16)(EV_VMTM_BEGIN + 5)  /* 定时器5事件 */
#define EV_TIMER6             (WORD16)(EV_VMTM_BEGIN + 6)  /* 定时器6事件 */
#define EV_TIMER7             (WORD16)(EV_VMTM_BEGIN + 7)  /* 定时器7事件 */
#define EV_TIMER8             (WORD16)(EV_VMTM_BEGIN + 8)  /* 定时器8事件 */
#define EV_TIMER9             (WORD16)(EV_VMTM_BEGIN + 9)  /* 定时器9事件 */
#define EV_TIMER10            (WORD16)(EV_VMTM_BEGIN + 10) /* 定时器10事件 */
#define EV_TIMER11            (WORD16)(EV_VMTM_BEGIN + 11) /* 定时器11事件 */
#define EV_TIMER12            (WORD16)(EV_VMTM_BEGIN + 12) /* 定时器12事件 */
#define EV_TIMER13            (WORD16)(EV_VMTM_BEGIN + 13) /* 定时器13事件 */
#define EV_TIMER14            (WORD16)(EV_VMTM_BEGIN + 14) /* 定时器14事件 */
#define EV_TIMER15            (WORD16)(EV_VMTM_BEGIN + 15) /* 定时器15事件 */
#define EV_TIMER16            (WORD16)(EV_VMTM_BEGIN + 16) /* 定时器16事件 */
#define EV_TIMER17            (WORD16)(EV_VMTM_BEGIN + 17) /* 定时器17事件 */
#define EV_TIMER18            (WORD16)(EV_VMTM_BEGIN + 18) /* 定时器18事件 */
#define EV_TIMER19            (WORD16)(EV_VMTM_BEGIN + 19) /* 定时器19事件 */
#define EV_TIMER20            (WORD16)(EV_VMTM_BEGIN + 20) /* 定时器20事件 */
#define EV_TIMER21            (WORD16)(EV_VMTM_BEGIN + 21) /* 定时器21事件 */
#define EV_TIMER22            (WORD16)(EV_VMTM_BEGIN + 22) /* 定时器22事件 */
#define EV_TIMER23            (WORD16)(EV_VMTM_BEGIN + 23) /* 定时器23事件 */
#define EV_TIMER24            (WORD16)(EV_VMTM_BEGIN + 24) /* 定时器24事件 */
#define EV_TIMER25            (WORD16)(EV_VMTM_BEGIN + 25) /* 定时器25事件 */
#define EV_TIMER26            (WORD16)(EV_VMTM_BEGIN + 26) /* 定时器26事件 */
#define EV_TIMER27            (WORD16)(EV_VMTM_BEGIN + 27) /* 定时器27事件 */
#define EV_TIMER28            (WORD16)(EV_VMTM_BEGIN + 28) /* 定时器28事件 */
#define EV_TIMER29            (WORD16)(EV_VMTM_BEGIN + 29) /* 定时器29事件 */
#define EV_TIMER30            (WORD16)(EV_VMTM_BEGIN + 30) /* 定时器30事件 */
#define EV_TIMER31            (WORD16)(EV_VMTM_BEGIN + 31) /* 定时器30事件 */

WORD16  VmSetTimer      (WORD32 dwCount100ms, BYTE byTimerNo);
BOOL    VmKillTimer     (BYTE byTimerNo);

WORD16  VmSetTimerEx    (WORD32 dwCount100ms,
                         BYTE byTimerNo,
                         WORD32 dwExtra
                        );
BOOL    VmKillTimerEx   (WORD16 wTid);



#define INVALID_WTP_ID  (WORD16)0
#define INVALID_AC_ID  	(WORD16)0


typedef struct tagPID
{
    WORD16  wAcId; /* AC编号，1开始 */
    WORD16  wWtpId; /* WTP编号，1开始 */

    WORD16  wPno;
    WORD16  wResv;
} TPID;

/* 2010-1-21 AC N+1备份功能新增*/
typedef struct
{
	WORD32	dwOldBakAcId;	/* 原接管AC ID */
	WORD32	dwNewBakAcId;	/* 当前接管AC ID */
} EV_BAKACID_CHG_IND_MSG_T;		/*  接管AC ID变化通知消息*/


//VOID ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);

/* 消息发送接口 */
BOOL    VmASend         (WORD16 wEvent,
                         BYTE *lpbyIn,
                         WORD16 wInLen,
                         TPID tReceiver
                        );
BOOL    VmSSend         (WORD16 wEvent,
                         BYTE *lpbyIn,
                         WORD16 wInLen,
                         BYTE *lpbyAck,
                         WORD16 wAckLen,
                         TPID tReceiver
                        );
BOOL    VmUSend        (WORD16 wEvent,
                         BYTE *pMsgSent,
                         WORD16 wMsgLen,
                         TPID tReceiver
                        );

BOOL    VmBSend         (WORD16 wEvent,
                         BYTE *pbyData,
                         WORD16 wLen,
                          BYTE byMsgType
                        );

BOOL    VmBroadCast     (WORD16 wEvent,
                         BYTE *pbyData,
                         WORD16 wLen,
                         WORD16 wPno
                        );

BOOL  VmMSend(WORD16 wEvent, 
				BYTE *lpbyIn, 
				WORD16 wInLen, 
				WORD16 wPno);

BOOL VmIsMsMode(VOID);
BOOL VmIsMaster (VOID);
BOOL VmIsMateOnline (VOID);

BOOL VmIsInBakAc(VOID);
WORD VmGetBakAcId(VOID);

BOOL VmIsIfMaster(WORD32	dwIfId);
BOOL VmIsIfOwn(WORD32	dwIfId);

BOOL VmIsActive(VOID);


#define APP_PNO_BEGIN           	20
#define APP_DB_PNO             		(WORD16)(APP_PNO_BEGIN + 0)
#define APP_DEVM_PNO             	(WORD16)(APP_PNO_BEGIN + 1)
#define APP_USRM_PNO             	(WORD16)(APP_PNO_BEGIN + 2)
#define APP_OMA_PNO             	(WORD16)(APP_PNO_BEGIN + 3)
#define APP_CW_PNO             		(WORD16)(APP_PNO_BEGIN + 4)
#define APP_HOSTAPD_PNO            	(WORD16)(APP_PNO_BEGIN + 5)
#define APP_HOSTAPD_BK_PNO          (WORD16)(APP_PNO_BEGIN + 6)
#define APP_LCS_PNO             	(WORD16)(APP_PNO_BEGIN + 7)
#define APP_ACM_PNO             	(WORD16)(APP_PNO_BEGIN + 8)

typedef VOID (*ProcEntryProto) (WORD16 wEvent,          /* 进程入口原型 */
                                BYTE *pbyBody,
                                WORD16 wLen,
			                    BYTE *pbyResv,
			                    WORD16 wResv,
                                BYTE *pbyProcData
                               );


#define VM_PROC_STATE_IDLE          (WORD16)0           /* 进程初始状态 */
WORD16      VmProcState             (VOID);
VOID        VmProcUpdateState       (WORD16 byProcState);

WORD16      VmEvent                 (VOID);
WORD16      VmLength                (VOID);
VOID        VmSender                (TPID *ptPid);
VOID	    VmBSMsgType             (BYTE *pbyMsgType);

BYTE*       VmGetProcData           (VOID); /* 获得进程数据区 */

VOID        VmSelfPid               (TPID *ptPid);
WORD16      VmSelfPno               (VOID);
BOOL        VmGetPid                (CHAR *lpbyPName, TPID  *lptPid);
BOOL        VmGetLocalPidByPno      (WORD16  wPno, TPID  *ptPid); /* 获得本机上进程的PID */
BOOL        VmGetSacPidByPno      	(WORD16  wPno, TPID  *ptPid); /* 获得serving ac上进程的PID */
BOOL        VmGetPacPidByPno      	(WORD16  wPno, TPID  *ptPid); /* 获得primary ac上进程的PID */

CHAR*       VmGetTmpRootPath(VOID);
CHAR*       VmGetLogRootPath(VOID);
CHAR*       VmGetUsrRootPath(VOID);
CHAR*       VmGetWlcRootPath(VOID);
BOOL        VmGetAcConfig           (WORD32 *pwAcId, BYTE *pucAcIp);
INT			VmGetCpuUsage           (VOID);
INT			VmGetCpu                (VOID);
VOID        VmSleep                 (DWORD ulSecond);
VOID        VmGetMemInfo            (DWORD *pdwTotal, DWORD *pdwFree);
VOID        VmGetDiskInfo           (DWORD *pdwTotal, DWORD *pdwFree);
WORD32      VmGetUpTime             (VOID);
WORD32      VmGetUptime100ms        (VOID);

BOOL		VmDeleteFile			(CHAR *szFile);
BOOL		VmFileExists			(CHAR* szFile);
BOOL		VmCreateDirEx			(CHAR* szDir, DWORD dwMode);
BOOL		VmCreateDir			    (CHAR* szDir);
BOOL		VmCreateReDirEx			(CHAR* szDir, DWORD dwMode);
BOOL		VmCreateReDir			(CHAR* szDir);
INT			VmFileSize				(const CHAR* szFileName);
BOOL        VmRenameFile            (CHAR* szOldFile, CHAR* szNewFile);
VOID        VmFormatPath            (CHAR *szPath);

#define  VmGetUB(dwSize)                TRACE_VmGetUB (dwSize)
#define  VmRetUB(lpbyPointer)           TRACE_VmRetUB (lpbyPointer)


/* 2010-1-9 pyy 新增: 串行话文件操作接口*/
FILE * VmFSafeOpen(const char *path, const char *mode);
int VmFSafeClose(FILE *stream);

/* 2010-2-3 pyy 新增: 根据进程号获取进程被调度次数*/
WORD32	VmGetRunTime(WORD16 wPno);


/****************************************
 * 系统控制的事件定义            *
 ****************************************/
#define EV_SYSCTRL_BEGIN            (WORD16)100

/* 上电控制 */
#define EV_MASTER_POWERON           (WORD16)(EV_SYSCTRL_BEGIN + 0)

BOOL VmPowerOnAck (BOOL bState);


/* 链路监测 */
#define EV_SYSCTRL_CONN_BEGIN       (WORD16)(EV_SYSCTRL_BEGIN + 40)

/* 2008-10-31 pyy add start */
#define EV_PROC_ECHO_REQ			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 15)
#define EV_PROC_ECHO_RSP			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 16)
/* 2008-10-31 pyy add end */

/* 2008-12-2 pyy add start */
#define EV_MS_MATE_ONLINE			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 19)
#define EV_MS_MATE_OFFLINE		    (WORD16)(EV_SYSCTRL_CONN_BEGIN + 20)
/* 2008-12-2 pyy add start */
#define EV_BK_LNK_SETUP             (WORD16)(EV_SYSCTRL_CONN_BEGIN + 21)
#define EV_BK_LNK_BREAK             (WORD16)(EV_SYSCTRL_CONN_BEGIN + 22)

#define EV_WEB_LNK_SETUP		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 23)
#define EV_WEB_LNK_BREAK 		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 24)

/* 2010-1-21 新增*/
#define EV_BAKACID_CHG_IND		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 52)	/* 接管AC ID 变化通知*/


/****************************************
 * 上层应用的消息号分段                 *
 ****************************************/
/* 各模块消息号按照以上分段进行定义
 * 消息号宏定义以EV_开头
 * 对于模块间的接口事件，应按照“谁提供服务，谁定义消息”
 * #define EV_HOSTAPD_XXX            (WORD16)(HOSTAPD_EVENT_BEGIN + 1)
 */
#define EV_APP_BEGIN             	(WORD16)(10000)
#define EV_DB_BEGIN             	(WORD16)(EV_APP_BEGIN + 0000)
#define EV_DEVM_BEGIN             	(WORD16)(EV_APP_BEGIN + 1000)
#define EV_USRM_BEGIN             	(WORD16)(EV_APP_BEGIN + 2000)
#define EV_OMA_BEGIN             	(WORD16)(EV_APP_BEGIN + 3000)
#define EV_CW_BEGIN             	(WORD16)(EV_APP_BEGIN + 4000)
#define EV_HOSTAPD_BEGIN            (WORD16)(EV_APP_BEGIN + 5000)
#define EV_LCS_BEGIN             	(WORD16)(EV_APP_BEGIN + 6000)
#define EV_ACM_BEGIN             	(WORD16)(EV_APP_BEGIN + 7000)
#define EV_RRM_BEGIN			    (WORD16)(EV_APP_BEGIN + 8000)
#define EV_PA_BEGIN             	(WORD16)(EV_APP_BEGIN + 9000)

#define EV_WAPIAPD_BEGIN            (WORD16)(EV_APP_BEGIN + 10000)
#define EV_SYSM_BEGIN             	(WORD16)(EV_APP_BEGIN + 11000)

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
#define EV_LICENSE_BEGIN             	(WORD16)(EV_APP_BEGIN + 12000)
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */

#ifdef _LINUX_
    #ifndef SH_COMPAT
    #define SH_COMPAT   0x0000
    #endif

    #ifndef SH_DENYRW
    #define SH_DENYRW   0x0010
    #endif

    #ifndef SH_DENYWR
    #define SH_DENYWR   0x0020
    #endif

    #ifndef SH_DENYRD
    #define SH_DENYRD   0x0030
    #endif

    #ifndef SH_DENYNONE
    #define SH_DENYNONE 0x0040
    #endif
#endif

#ifdef DEBUG_MEM
    VOID *OsMalloc(CHAR* szFile, INT iLine, INT iSize);
    VOID *OsZalloc(CHAR* szFile, INT iLine, INT iSize);
    VOID *OsRealloc(CHAR* szFile, INT iLine, VOID* ptr, INT iSize);
    VOID OsFree(CHAR* szFile, INT iLine, VOID *ptr);
    char* OsStrdup(CHAR* szFile, INT iLine, const char *ptr);

	#define VM_MALLOC(size)		        OsMalloc(__FILE__, __LINE__, size)

    #define VM_ZALLOC(size)		        OsZalloc(__FILE__, __LINE__, size)

	#define VM_REALLOC(ptr, size)		OsRealloc(__FILE__, __LINE__, ptr, size)

	#define VM_FREE(ptr)						\
	do											\
	{											\
		if (ptr)								\
		{										\
			OsFree(__FILE__, __LINE__, ptr);	\
			(ptr) = NULL;						\
		}										\
	}while(0)

	#define VM_STRDUP(ptr)	OsStrdup(__FILE__, __LINE__,ptr)

#else

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

	#define VM_STRDUP(ptr)	strdup(ptr)
#endif


#ifdef _OSWIN32_
#define snprintf _snprintf
#endif

#ifndef ONE_MB
#define ONE_MB  (1024*1024)
#endif

/* 字节序转换 */
#define HTONL(a)        (htonl((a)))
#define HTONL_IT(a)     ((a) = HTONL((a)))

#define HTONS(a)        (htons((a)))
#define HTONS_IT(a)     ((a) = HTONS((a)))

#define NTOHL(a)        (ntohl((a)))
#define NTOHL_IT(a)     ((a) = NTOHL((a)))

#define NTOHS(a)        (ntohs((a)))
#define NTOHS_IT(a)     ((a) = NTOHS((a)))

#ifdef _OSWIN32_
#define FILE_ACCESS_MODE_ALL    0
#else
#define FILE_ACCESS_MODE_ALL    (S_IRWXU | S_IRWXG | S_IRWXO)
#endif 

#define AC_RUNMODE_STANDALONE   0
#define AC_RUNMODE_MASTER       1
#define AC_RUNMODE_SLAVE        2

#endif

