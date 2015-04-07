/******************************************************************************
ģ����      : OSS
�ļ���      : OssApi.h
����ļ�    :
ʵ�ֹ���    : OSSģ��Ľӿ�
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
2008/05/29	����ƽ		��ӡ�ӿ��޸�ΪModuleLogMsg
2008/07/31	�׽�  		����SH_DENYWR����غ궨�壨��ʱδ�ҵ���Щ�궨��ı�׼ͷ�ļ���
******************************************************************************/
#ifndef _OSSAPI_H_
#define _OSSAPI_H_


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

#pragma warning (disable : 4115 4200 4244) /* rpcasync.h(45) : warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses */
#define _WIN32_WINNT 0x0400 /* ���� NT �汾, ��Ӱ�� SOCKET ��һЩ���� */
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
#pragma warning(disable : 4100 4102 4127 4206 4214 4505)
#pragma warning(disable : 4996) /* To disable deprecation */
#pragma warning(disable : 4100) /* warning C4100: unreferenced formal parameter */
#pragma warning(disable : 4201)
#elif OSS_WARNING_LEVEL == 36 /* �澯����Ϊ 3.6 �� */
#pragma warning(disable : 4102 4206 4214)
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

/*����������UCLINUX��WINNT�¶�δ����*/
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

/*�������ͺͺ���LINUX��δ����*/
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
#define WLC_WORK_DIR              "etc/"   /* ����Ŀ¼��*/
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


WORD32 VmCurrentTick (VOID);
WORD32 VmCreateLock(VOID);
BOOL VmDeleteLock (WORD32);
BOOL VmLock (WORD32, WORD32);
BOOL VmUnLock (WORD32);

/* ��־���� */
#define APP_DETAIL          (BYTE) 0
#define APP_MSG             (BYTE) 1
#define APP_WARN            (BYTE) 2
#define APP_ERROR           (BYTE) 3
#define APP_FAIL            (BYTE) 4
#define APP_FATAL           (BYTE) 5


#define MSG_TYPE_ASYNC      (BYTE) 0 		/* �����첽��Ϣ */
#define MSG_TYPE_SYNC       (BYTE) 1 		/* ����ͬ����Ϣ */
#define MSG_TYPE_ASYNCTIMER (BYTE) 2 	/* �첽��ʱ��Ϣ */
#define MSG_TYPE_MULTICAST  (BYTE) 7 	/* ����鲥��Ϣ */
#define MSG_TYPE_MATE		(BYTE)8		/* ���Ӽ���Ϣ*/
#define MSG_TYPE_OMCR       (BYTE) 9 		/* ǰ��̨��Ϣ */
#define MSG_TYPE_BROAD      (BYTE) 10 		/* CPU�ڲ��㲥��Ϣ */
#define MSG_TYPE_BYTCP      (BYTE) 11 		/* ͨ��TCP���͵İ����Ϣ */
#define MSG_TYPE_BYUDP      (BYTE) 12 		/* ͨ��UDP���͵İ����Ϣ */
#define MSG_TYPE_WEB		(BYTE)13			/* AC-WEB <-> AC����Ϣ*/
#define MSG_TYPE_INVALID    (BYTE) 0xff 		/* ��Ч��Ϣ���� */

#ifdef _LINUX_
VOID    ModulePrint (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...)
            __attribute__ ((format (printf, 3, 4)));
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif /* _LINUX_ */

#ifdef _OSWIN32_
VOID    ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif /* _OSWIN32_ */


/* ��ʱ���ı�ţ���Ϊ��Ҫ�붨ʱ�¼��Ź�������ֵ�����޸� */
#define TIMER0              (BYTE)0     /* ��ʱ��0 */
#define TIMER1              (BYTE)1     /* ��ʱ��1 */
#define TIMER2              (BYTE)2     /* ��ʱ��2 */
#define TIMER3              (BYTE)3     /* ��ʱ��3 */
#define TIMER4              (BYTE)4     /* ��ʱ��4 */
#define TIMER5              (BYTE)5     /* ��ʱ��5 */
#define TIMER6              (BYTE)6     /* ��ʱ��6 */
#define TIMER7              (BYTE)7     /* ��ʱ��7 */
#define TIMER8              (BYTE)8     /* ��ʱ��8 */
#define TIMER9              (BYTE)9     /* ��ʱ��9 */
#define TIMER10             (BYTE)10    /* ��ʱ��10 */
#define TIMER11             (BYTE)11    /* ��ʱ��11 */
#define TIMER12             (BYTE)12    /* ��ʱ��12 */
#define TIMER13             (BYTE)13    /* ��ʱ��13 */
#define TIMER14             (BYTE)14    /* ��ʱ��14 */
#define TIMER15             (BYTE)15    /* ��ʱ��15 */
#define TIMER16             (BYTE)16    /* ��ʱ��16 */
#define TIMER17             (BYTE)17    /* ��ʱ��17 */
#define TIMER18             (BYTE)18    /* ��ʱ��18 */
#define TIMER19             (BYTE)19    /* ��ʱ��19 */
#define TIMER20             (BYTE)20    /* ��ʱ��20 */
#define TIMER21             (BYTE)21    /* ��ʱ��21 */
#define TIMER22             (BYTE)22    /* ��ʱ��22 */
#define TIMER23             (BYTE)23    /* ��ʱ��23 */
#define TIMER24             (BYTE)24    /* ��ʱ��24 */
#define TIMER25             (BYTE)25    /* ��ʱ��25 */
#define TIMER26             (BYTE)26    /* ��ʱ��26 */
#define TIMER27             (BYTE)27    /* ��ʱ��27 */
#define TIMER28             (BYTE)28    /* ��ʱ��28 */
#define TIMER29             (BYTE)29    /* ��ʱ��29 */
#define TIMER30             (BYTE)30    /* ��ʱ��30 */
#define TIMER31             (BYTE)31    /* ��ʱ��31 */
#define TID_ERROR           (WORD16) 0xFFFF /* ����TIDֵ */


/* ����ԭ�� */
#define VM_RESET_NORMAL             (INT)0              /* RESETԭ���������� */
#define VM_RESET_POWERON_FAILURE    (INT)4              /* RESETԭ��, ���������ϵ�ʧ�� */
#define VM_RESET_INVALID_VERSION    (INT)5              /* RESETԭ����Ч�汾 */
#define VM_RESET_DATA_SYNC_FAIL     (INT)6              /* RESETԭ������ͬ��ʧ�� */
#define VM_RESET_BY_OMCR            (INT)7              /* RESETԭ�򣬺�̨�������� */
#define VM_RESET_UPLINK_BREAK       (INT)8              /* RESETԭ��, ��ⲻ���ϲ�CPU */
#define VM_RESET_ADDR_MISSED        (INT)9              /* RESETԭ��, �����ַ���ڵ�ַ���� */
#define VM_RESET_UPCPU_POWERON      (INT)10             /* RESETԭ��, �ϼ�CPU���� */
#define VM_RESET_BY_CPUBLOCK        (INT)12             /* RESETԭ��, CPU������ */
#define VM_RESET_SELFOFFLINE        (INT)13             /* RESETԭ��, ����ͨѶ�� */
#define VM_RESET_PROC_CHECK_FAIL	(INT)14		/* RESETԭ��, Ӧ�ý��̱���ʧ��*/

/****************************************
 * ��ʱ����Ϣ                           *
 ****************************************/
#define EV_VMTM_BEGIN               (WORD16)1000
/* ���¶�ʱ�¼��ŵĶ�����Ҫ�� TIMER0... ������ */
#define EV_TIMER0             (WORD16)(EV_VMTM_BEGIN + 0)  /* ��ʱ��0�¼� */
#define EV_TIMER1             (WORD16)(EV_VMTM_BEGIN + 1)  /* ��ʱ��1�¼� */
#define EV_TIMER2             (WORD16)(EV_VMTM_BEGIN + 2)  /* ��ʱ��2�¼� */
#define EV_TIMER3             (WORD16)(EV_VMTM_BEGIN + 3)  /* ��ʱ��3�¼� */
#define EV_TIMER4             (WORD16)(EV_VMTM_BEGIN + 4)  /* ��ʱ��4�¼� */
#define EV_TIMER5             (WORD16)(EV_VMTM_BEGIN + 5)  /* ��ʱ��5�¼� */
#define EV_TIMER6             (WORD16)(EV_VMTM_BEGIN + 6)  /* ��ʱ��6�¼� */
#define EV_TIMER7             (WORD16)(EV_VMTM_BEGIN + 7)  /* ��ʱ��7�¼� */
#define EV_TIMER8             (WORD16)(EV_VMTM_BEGIN + 8)  /* ��ʱ��8�¼� */
#define EV_TIMER9             (WORD16)(EV_VMTM_BEGIN + 9)  /* ��ʱ��9�¼� */
#define EV_TIMER10            (WORD16)(EV_VMTM_BEGIN + 10) /* ��ʱ��10�¼� */
#define EV_TIMER11            (WORD16)(EV_VMTM_BEGIN + 11) /* ��ʱ��11�¼� */
#define EV_TIMER12            (WORD16)(EV_VMTM_BEGIN + 12) /* ��ʱ��12�¼� */
#define EV_TIMER13            (WORD16)(EV_VMTM_BEGIN + 13) /* ��ʱ��13�¼� */
#define EV_TIMER14            (WORD16)(EV_VMTM_BEGIN + 14) /* ��ʱ��14�¼� */
#define EV_TIMER15            (WORD16)(EV_VMTM_BEGIN + 15) /* ��ʱ��15�¼� */
#define EV_TIMER16            (WORD16)(EV_VMTM_BEGIN + 16) /* ��ʱ��16�¼� */
#define EV_TIMER17            (WORD16)(EV_VMTM_BEGIN + 17) /* ��ʱ��17�¼� */
#define EV_TIMER18            (WORD16)(EV_VMTM_BEGIN + 18) /* ��ʱ��18�¼� */
#define EV_TIMER19            (WORD16)(EV_VMTM_BEGIN + 19) /* ��ʱ��19�¼� */
#define EV_TIMER20            (WORD16)(EV_VMTM_BEGIN + 20) /* ��ʱ��20�¼� */
#define EV_TIMER21            (WORD16)(EV_VMTM_BEGIN + 21) /* ��ʱ��21�¼� */
#define EV_TIMER22            (WORD16)(EV_VMTM_BEGIN + 22) /* ��ʱ��22�¼� */
#define EV_TIMER23            (WORD16)(EV_VMTM_BEGIN + 23) /* ��ʱ��23�¼� */
#define EV_TIMER24            (WORD16)(EV_VMTM_BEGIN + 24) /* ��ʱ��24�¼� */
#define EV_TIMER25            (WORD16)(EV_VMTM_BEGIN + 25) /* ��ʱ��25�¼� */
#define EV_TIMER26            (WORD16)(EV_VMTM_BEGIN + 26) /* ��ʱ��26�¼� */
#define EV_TIMER27            (WORD16)(EV_VMTM_BEGIN + 27) /* ��ʱ��27�¼� */
#define EV_TIMER28            (WORD16)(EV_VMTM_BEGIN + 28) /* ��ʱ��28�¼� */
#define EV_TIMER29            (WORD16)(EV_VMTM_BEGIN + 29) /* ��ʱ��29�¼� */
#define EV_TIMER30            (WORD16)(EV_VMTM_BEGIN + 30) /* ��ʱ��30�¼� */
#define EV_TIMER31            (WORD16)(EV_VMTM_BEGIN + 31) /* ��ʱ��30�¼� */

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
    WORD16  wAcId; /* AC��ţ�1��ʼ */
    WORD16  wWtpId; /* WTP��ţ�1��ʼ */

    WORD16  wPno;
    WORD16  wResv;
} TPID;

/* 2010-1-21 AC N+1���ݹ�������*/
typedef struct
{
	WORD32	dwOldBakAcId;	/* ԭ�ӹ�AC ID */
	WORD32	dwNewBakAcId;	/* ��ǰ�ӹ�AC ID */
} EV_BAKACID_CHG_IND_MSG_T;		/*  �ӹ�AC ID�仯֪ͨ��Ϣ*/


//VOID ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);

/* ��Ϣ���ͽӿ� */
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

typedef VOID (*ProcEntryProto) (WORD16 wEvent,          /* �������ԭ�� */
                                BYTE *pbyBody,
                                WORD16 wLen,
			                    BYTE *pbyResv,
			                    WORD16 wResv,
                                BYTE *pbyProcData
                               );


#define VM_PROC_STATE_IDLE          (WORD16)0           /* ���̳�ʼ״̬ */
WORD16      VmProcState             (VOID);
VOID        VmProcUpdateState       (WORD16 byProcState);

WORD16      VmEvent                 (VOID);
WORD16      VmLength                (VOID);
VOID        VmSender                (TPID *ptPid);
VOID	    VmBSMsgType             (BYTE *pbyMsgType);

BYTE*       VmGetProcData           (VOID); /* ��ý��������� */

VOID        VmSelfPid               (TPID *ptPid);
WORD16      VmSelfPno               (VOID);
BOOL        VmGetPid                (CHAR *lpbyPName, TPID  *lptPid);
BOOL        VmGetLocalPidByPno      (WORD16  wPno, TPID  *ptPid); /* ��ñ����Ͻ��̵�PID */
BOOL        VmGetSacPidByPno      	(WORD16  wPno, TPID  *ptPid); /* ���serving ac�Ͻ��̵�PID */
BOOL        VmGetPacPidByPno      	(WORD16  wPno, TPID  *ptPid); /* ���primary ac�Ͻ��̵�PID */

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


/* 2010-1-9 pyy ����: ���л��ļ������ӿ�*/
FILE * VmFSafeOpen(const char *path, const char *mode);
int VmFSafeClose(FILE *stream);

/* 2010-2-3 pyy ����: ���ݽ��̺Ż�ȡ���̱����ȴ���*/
WORD32	VmGetRunTime(WORD16 wPno);


/****************************************
 * ϵͳ���Ƶ��¼�����            *
 ****************************************/
#define EV_SYSCTRL_BEGIN            (WORD16)100

/* �ϵ���� */
#define EV_MASTER_POWERON           (WORD16)(EV_SYSCTRL_BEGIN + 0)

BOOL VmPowerOnAck (BOOL bState);


/* ��·��� */
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

/* 2010-1-21 ����*/
#define EV_BAKACID_CHG_IND		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 52)	/* �ӹ�AC ID �仯֪ͨ*/


/****************************************
 * �ϲ�Ӧ�õ���Ϣ�ŷֶ�                 *
 ****************************************/
/* ��ģ����Ϣ�Ű������Ϸֶν��ж���
 * ��Ϣ�ź궨����EV_��ͷ
 * ����ģ���Ľӿ��¼���Ӧ���ա�˭�ṩ����˭������Ϣ��
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

/* BEGIN: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */
#define EV_LICENSE_BEGIN             	(WORD16)(EV_APP_BEGIN + 12000)
/* END: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */

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

/* �ֽ���ת�� */
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

