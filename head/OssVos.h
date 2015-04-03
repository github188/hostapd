/******************************************************************************
ģ����      : VOS
�ļ���      : OssVos.h
����ļ�    :
ʵ�ֹ���    : VOS��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSVOS_H_
#define _OSSVOS_H_

#ifdef _OSWIN32_
#define VOS_VALLOC_RESERVE          MEM_RESERVE     /* �����ڴ����ѡ�� */
#define VOS_VALLOC_COMMIT           MEM_COMMIT
#define VOS_VFREE_DECOMMIT          MEM_DECOMMIT
#define VOS_VFREE_RELEASE           MEM_RELEASE

#define VOS_PROTECT_STATE_NOACCESS  PAGE_NOACCESS   /* ҳ������� */
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

#define TCB_NUM                     (BYTE) 30       /* ������Ŀ         */
#define INVALID_TNO                 (BYTE) 0xFF     /* ��Ч�����       */
#define INVALID_TASK_TOKEN          (OSTOKEN) 0x0     /* ��Ч�����       */
#define TASK_NAME_LENGTH            (BYTE) 17       /* �������Ƶĳ���   */
#define PROC_NAME_LENGTH            (BYTE) 33       /* �������Ƶĳ���   */

/* �ź������� */
#define SEM_COUNT                   0       /* �����ź��� */
#define SEM_SYNC                    1       /* ͬ���ź��� */
#define SEM_MUTEX                   2       /* �����ź��� */

/* 2009-10-23 pyy �޸�: �������д�С*/
/* ���������С*/
/* 2010-3-8: pyy �Ŵ�2��s*/
#ifdef APP_PROJ_AC
#define OSS_MSG_QUE_SIZE			5000*20
#define OSS_MSG_QUE_HIGH_THRESH	4500*20
#else
#define OSS_MSG_QUE_SIZE			200
#define OSS_MSG_QUE_HIGH_THRESH	160
#endif

typedef VOID (*RtProcProto) (VOID);         /* ʵʱ������� */
typedef VOID (*TaskEntryProto) (VOID*);     /* ������� */

typedef struct _TCBTABLE
{
    BYTE                byUse;                          /* ʹ�ñ�־ */
    BYTE                abyName[TASK_NAME_LENGTH];      /* ������ */
    BYTE                byPriority;                     /* �������ȼ� */
    WORD32              dwStacksize;                    /* ջ��С */    
    TaskEntryProto      tEntry;                         /* �������ָ�� */
    WORD32              dwQueueSize;                    /* ���д�С */
    OSTOKEN             tTask;                          /* ����ID */
	HANDLE				tHandle;						/* ������ */
	OSTOKEN				tSem;						/* ������ */
}TTcbTable;



BOOL    OsSuspendTask       (VOID);                     /* �������� */
BOOL    OsSuspendTaskEx     (BYTE byTno);            /* ����ָ������ */
BOOL    OsResumeTask        (BYTE byTno);            /* �ָ�ָ������ */
BOOL    OsSetPriority       (BYTE, BYTE);               /* �����������ȼ� */
VOID    OsDelay             (WORD32);                   /* ͬ����ʱ(ϵͳ�ṩ) */
WORD32  GetTick             (VOID);                     /* ȡ�õ�ǰTick(ϵͳ�ṩ) */
LPBYTE  OsGetTaskName       (BYTE);                     /* ȡ��ǰ������ */
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
BOOL    VosInit             (VOID);                 /* Vos ��ʼ�� */
BOOL    VosStart            (VOID);                 /* Vos ���� */
VOID    OsReset             (VOID);
VOID    OsReboot            (VOID);
BOOL    OsInitMmuPhyAddr    (WORD32  dwSize);

VOID    OsTaskLock          (VOID);
VOID    OsTaskUnlock        (VOID);

#endif /* _OSSVOS_H_ */
