/******************************************************************************
模块名      : VOS
文件名      : OssVos.h
相关文件    :
实现功能    : VOS基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSVOS_H_
#define _OSSVOS_H_

#ifdef _OSWIN32_
#define VOS_VALLOC_RESERVE          MEM_RESERVE     /* 虚拟内存分配选项 */
#define VOS_VALLOC_COMMIT           MEM_COMMIT
#define VOS_VFREE_DECOMMIT          MEM_DECOMMIT
#define VOS_VFREE_RELEASE           MEM_RELEASE

#define VOS_PROTECT_STATE_NOACCESS  PAGE_NOACCESS   /* 页保护标记 */
#define VOS_PROTECT_STATE_READONLY  PAGE_READONLY
#define VOS_PROTECT_STATE_READWRITE PAGE_READWRITE
#endif

#ifdef _LINUX_
#define VOS_VALLOC_RESERVE          0
#define VOS_VALLOC_COMMIT           0
#define VOS_VFREE_DECOMMIT          0
#define VOS_VFREE_RELEASE           0

#define VOS_MMU_STATE_MASK_VWC      0
#define VOS_MMU_STATE_WRITABLE      0
#define VOS_MMU_STATE_WRITABLE_NOT  0

#define VOS_PROTECT_STATE_NOACCESS  0
#define VOS_PROTECT_STATE_READONLY  0
#define VOS_PROTECT_STATE_READWRITE 0
#endif

#define TCB_NUM                     (BYTE) 30       /* 任务数目         */
#define INVALID_TNO                 (BYTE) 0xFF     /* 无效任务号       */
#define INVALID_TASK_TOKEN          (OSTOKEN) 0x0     /* 无效任务号       */
#define TASK_NAME_LENGTH            (BYTE) 17       /* 任务名称的长度   */
#define PROC_NAME_LENGTH            (BYTE) 33       /* 进程名称的长度   */

/* 信号量类型 */
#define SEM_COUNT                   0       /* 计数信号量 */
#define SEM_SYNC                    1       /* 同步信号量 */
#define SEM_MUTEX                   2       /* 互斥信号量 */

/* 2009-10-23 pyy 修改: 新增队列大小*/
/* 任务邮箱大小*/
/* 2010-3-8: pyy 放大2倍s*/
#ifdef APP_PROJ_AC
#define OSS_MSG_QUE_SIZE			5000*20
#define OSS_MSG_QUE_HIGH_THRESH	4500*20
#else
#define OSS_MSG_QUE_SIZE			200
#define OSS_MSG_QUE_HIGH_THRESH	160
#endif

typedef VOID (*RtProcProto) (VOID);         /* 实时任务入口 */
typedef VOID (*TaskEntryProto) (VOID*);     /* 任务入口 */

typedef struct _TCBTABLE
{
    BYTE                byUse;                          /* 使用标志 */
    BYTE                abyName[TASK_NAME_LENGTH];      /* 任务名 */
    BYTE                byPriority;                     /* 任务优先级 */
    WORD32              dwStacksize;                    /* 栈大小 */    
    TaskEntryProto      tEntry;                         /* 任务入口指针 */
    WORD32              dwQueueSize;                    /* 队列大小 */
    OSTOKEN             tTask;                          /* 任务ID */
	HANDLE				tHandle;						/* 任务句柄 */
	OSTOKEN				tSem;						/* 任务句柄 */
}TTcbTable;



BOOL    OsSuspendTask       (VOID);                     /* 挂起任务 */
BOOL    OsSuspendTaskEx     (BYTE byTno);            /* 挂起指定任务 */
BOOL    OsResumeTask        (BYTE byTno);            /* 恢复指定任务 */
BOOL    OsSetPriority       (BYTE, BYTE);               /* 设置任务优先级 */
VOID    OsDelay             (WORD32);                   /* 同步延时(系统提供) */
WORD32  GetTick             (VOID);                     /* 取得当前Tick(系统提供) */
LPBYTE  OsGetTaskName       (BYTE);                     /* 取当前任务名 */
VOID    OsSetTaskName       (BYTE, CHAR*);
BOOL    OsGetClock          (TClockStruc *pSoftClock);
BOOL    OsSetClock          (TClockStruc *pSoftClock);
BYTE    OsGetTaskNo         (VOID);
BYTE    OsRegisterTask      (LPBYTE          szName,
                             TaskEntryProto  tEntry,    
                             BYTE            byPriority,
                             WORD32          dwStackSize,
                             WORD32          dwMsgQueueSize
                            );
BOOL    OsCreateMailbox     (LPBYTE lpName,
                             WORD32 dwCount,
                             WORD32 dwMsgSize,
                             OSTOKEN *tID
                            );
BOOL    OsSendMessage       (OSTOKEN tQueueID, 
                             WORD32 dwTimeout, 
                             LPVOID *lpMsgBuf, 
                             WORD32 len
                            );
INT     OsReceiveMessage    (OSTOKEN tQueueID,
                             WORD32  dwTimeout,
                             LPVOID lpMsgBuf, 
                             WORD32 len
                            );

BOOL    OsCreateSemaphore   (LPBYTE lpName,
                             WORD32 dwInitVal,
                             WORD32 dwMaxVal,
                             WORD32 dwFlag,
                             OSTOKEN *tSmID
                            );
BOOL    OsCloseSemaphore    (OSTOKEN tSmID);
BOOL    OsSemaphoreP        (OSTOKEN tSmID, WORD32 dwTimeOut, WORD32 dwCount);
BOOL    OsSemaphoreV        (OSTOKEN tSmID, WORD32 dwCount);
VOID    *OsVirtualAlloc     (VOID        *lpAddress,
                             WORD32      dwSize,
                             WORD32      dwAllocationType,
                             WORD32      dwProtect
                            );
BOOL    OsVirtualFree       (VOID*     lpAddress,
                             WORD32     dwSize,
                             WORD32     dwFreeType
                            );
WORD32  OsGetPageSize       (VOID);
VOID    *OsStackMemAlloc    (WORD32 dwSize);
VOID    *OsMemAlloc         (WORD32 dwSize);
VOID    OsMemFree           (LPVOID lpPtr);
BOOL    OsPageProtect       (VOID    *lpAddress,
                             WORD32  dwSize,
                             WORD32  dwMask,
                             WORD32  dwProtect
                            );
VOID    OsSetMmuEnableCtrl  (BOOL bSetState);                            
BOOL    VosInit             (VOID);                 /* Vos 初始化 */
BOOL    VosStart            (VOID);                 /* Vos 启动 */
VOID    OsReset             (VOID);
VOID    OsReboot            (VOID);
BOOL    OsInitMmuPhyAddr    (WORD32  dwSize);

VOID    OsTaskLock          (VOID);
VOID    OsTaskUnlock        (VOID);

#endif /* _OSSVOS_H_ */
