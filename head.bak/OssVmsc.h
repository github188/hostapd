/******************************************************************************
ģ����      : VMSC
�ļ���      : OssVmsc.h
����ļ�    :
ʵ�ֹ���    : VMSC ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/
#ifndef _OSSVMSC_H_
#define _OSSVMSC_H_


/* �궨�� */
#define VMSC_BLOCK                  (BYTE) 1            /* ����״̬: ���� */
#define VMSC_READY                  (BYTE) 2            /* ����״̬: ���� */
#define VMSC_RUNING                 (BYTE) 3            /* ����״̬: ���� */

#define VMSC_NOT_WAIT               (BYTE) 0            /* δ����ͬ���ȴ� */
#define VMSC_SYN_WAIT               (BYTE) 2            /* �ȴ�ͬ��Ӧ����Ϣ */

#define VMSC_PCB_NUM                (WORD16) 50        /* ������Ŀ */
#define VMSC_TIMER_NUM              (WORD16) 32         /* ÿ��ʵ����������ʱ���� */
#define VMSC_SAVED_MSG_NUM          (WORD16) 50         /* ÿ��ʵ��������Ϣ�����������Ϣ��Ŀ */

#define VMSC_MAIN_TASK_NO           (BYTE)0x88          /* ������� */

#define VMSC_SCHEDULE_TASK          (BYTE)0x01          /* ��������: �������� */
#define VMSC_EXTRA_TASK             (BYTE)0x02          /* ��������: �������� */

#define VM_INVALID_PNO              (WORD16)0xFFFF      /* ��Ч���̺� */
#define VM_INVALID_INO              (WORD16)0xFFFF      /* ��Чʵ���� */
#define VM_DEFAULT_INST             (WORD16)0xFFFE      /* ȱʡʵ��, ������ */
#define VM_PROC_STATE_IDLE          (WORD16)0           /* ���̳�ʼ״̬ */
#define VM_PROC_STATE_INVALID       (WORD16)0xFFFF      /* ������Ч״̬ */
#define VM_INST_STATE_IDLE          (WORD16)0           /* ʵ����ʼ״̬ */
#define VM_INST_STATE_INVALID       (WORD16)0xFFFD      /* ʵ����Ч״̬ */

#define VM_INVALID_CELL_TYPE        (BYTE)0xFF          /* ��Ч����Ԫ���� */

#define VMSC_FILL_VALUE             (BYTE)0xCC          /* ����ջ�ĳ�ʼ���ֵ */

#define VM_PROC_INFO_MAXNEEDSAVE    (BYTE)3             /* ���������Ҫ��������״̬���� */

#define VMSC_ICB_FREE               (BYTE)0             /* ��� ICB Ϊ���� */
#define VMSC_ICB_USED               (BYTE)1             /* ��� ICB Ϊռ�� */

/* ���Ȼص������Ĳ����������� */
#define VM_STAGE_BEFORE_SCHEDULE    (BYTE)0x00          /* ָʾ���ȹ���Ŀǰ���ڵ���ǰ */
#define VM_STAGE_AFTER_SCHEDULE     (BYTE)0x01          /* ָʾ���ȹ���Ŀǰ���ڵ��Ⱥ� */

typedef VOID (*InstInitProto) (BYTE*);                  /* ʵ����ʼ��ԭ�� */
typedef VOID (*InstEntryProto) (WORD16 wEvent,          /* ʵ�����ԭ�� */
                                LPBYTE lpbyIn,
                                WORD16 wInLen,
                                LPBYTE lpbyAck,
                                WORD16 wAckLen,
                                LPBYTE lpbyData
                               );

typedef VOID (*ProcEntryProto) (WORD16 wEvent,          /* �������ԭ�� */
                                LPBYTE lpbyIn,
                                WORD16 wInLen,
                                LPBYTE lpbyAck,
                                WORD16 wAckLen,
                                LPBYTE lpbyData 
                               );

typedef VOID (*ProcInitProto) (BYTE*);                  /* ���̳�ʼ��ԭ�� */

typedef struct tagICB
{
    BYTE            byFlag;
    WORD16          wInst;                  /* ʵ���� */
    WORD16          wInstPrev;
    WORD16          wInstNext;
    BYTE*           pDataArea;
    WORD16          wCurState;              /* ʵ��״̬ */
    WORD16          wDelayTid;              /* ͬ����ʱID */
    WORD16          wTimerNum;              /* �첽��ʱ��Ŀ */
    WORD16          awTid[VMSC_TIMER_NUM];  /* �첽��ʱ��ID */
    TPID            pidCreator;
    TPID            pidKiller;    
    WORD16          wSMsgNum;               /* ������Ϣ��Ŀ */
    TMsgStruc       *lptSMsgHead;           /* ������Ϣ����ͷָ�� */
    TMsgStruc       *lptSMsgTail;           /* ������Ϣ����βָ�� */    
} TICBStruc, *LPTICB;


/* lixp, 2001-11-07, (1) ������Ա˳��; (2) ɾ��tSelfPid��Ա */
/* �����Ҫ�޸ĸýṹ�Ķ��壬�����أ���Ӱ��ջ���� */
typedef struct tagPCB
{
    BYTE                byUse;              /* ʹ�ñ�־ */

    BYTE                byTno;              /* ����� */
    WORD16              wPno;
    WORD32              dwTaskSP;           /* ����ջƫ�� */
    WORD32              dwProcessSP;        /* ����ջƫ��ָ�� */
    WORD32              dwTaskSS;           /* ����ջ�Ķ�ָ�� */
    WORD32              dwProcessSS;        /* ����ջ��ָ�� */
    LPBYTE              lpbyTaskSS;
    LPBYTE              lpbyProcessSS;      /* ջָ�� */
    WORD32              dwStackSize;        /* ����ջ��С*/
    LPBYTE              lpbySwitchStack;    /* ��ջָ�� */

    LPSTR               lpszName;           /* ������ */
    TICBStruc           tProcessICB;        /* ����ȱʡ��ICB */
    WORD16              wProcDataSize;      /* ������������С */
    ProcEntryProto      pfProcEntry;        /* ������ڵ�ַ */
	ProcInitProto		pfDataAreaInit;     /* ������������ʼ������ */

    WORD16              wInst;              /* ���̵�ǰʵ���� */
    WORD16              wInstMax;           /* ������ʵ���� */    
    WORD16              wInstAlive;         /* ������ʵ���� */    
    WORD16              wInstDataSize;      /* ����ʵ����������С */
    InstEntryProto      pfInstEntry;        /* ʵ�����*/
    InstInitProto       pfInstDataInit;     /* ʵ�����ݳ�ʼ����� */
    TICBStruc           *atICBTab;          /* ʵ��ICB���� */
    TICBStruc           *lptUsedICBHead;    /* ռ�õ�ICB����ͷ */
    TICBStruc           *lptUsedICBTail;    /* ռ�õ�ICB����β */
    TICBStruc           *lptFreeICBHead;    /* ���е�ICB����ͷ */
    TICBStruc           *lptFreeICBTail;    /* ���е�ICB����β */

    BYTE                byWait;             /*ͬ���ȴ���־*/
    BYTE                byOSState;          /* ����״̬ */    
    BYTE                bySaved;            /* ��ǰ��Ϣ�Ƿ񱻱��� */    
    TPID                tCurSender;         /* ��ǰ��Ϣ������ */
    WORD16              wCurSendEvent;      /* ��ǰ���͵��¼� */    
    TPID                tCurReceiver;       /* ��ǰ��Ϣ������ */
    WORD16              wCurEvent;          /* ��ǰ���յ��¼� */    
    TMsgStruc           *lptCurMsg;         /* ��ǰ��Ϣָ�� */
    WORD16              wMsgNum;            /* ��Ϣ��Ŀ */
    TMsgStruc           *lptMsgHead;        /* ��Ϣ����ͷָ�� */
    TMsgStruc           *lptMsgTail;        /* ��Ϣ����βָ�� */

    BYTE                byNormalRet;        /* �Ƿ��������ر�־ */
    WORD32              dwRunNum;           /* ���̱����ȵĴ��� */
    WORD32              dwLastRunNum;       /* ����ǰ�α����ȵĴ��� */
    WORD32              dwSendMsgCount;     /* ���͵���Ϣ�� */
    WORD32              dwSendByteCount;    /* ���͵���Ϣ�ֽ��� */
    WORD32              dwBeginTick;        /* ���̿�ʼ���е�tickֵ */
    WORD32              dwCurRunTick;       /* ���̱������е�tickֵ */
    WORD32              dwMaxRunTick;       /* �������е����tickֵ */
    WORD32              dwIpcTrace;         /* ����IPC����ѡ�� */
    WORD32              dwLogLevel;         /* ����LOGѡ�� */
    BYTE                byLogLevel;         /* ǰ̨��ӡ���ƣ��д����� */

    WORD16              wPrev;              /* ǰ��ָ�� */
    WORD16              wNextPCB;           /* ����ָ�� */
    WORD32              dwReserve;
}TPCBStruc;

/* �������еı�����Ϣ */
typedef struct
{
    WORD16      wInst;          /* ��ǰ���е�ʵ���� */
    TMsgStruc   tCurMsgHead;    /* �������д������Ϣ����Ϣͷ */
    WORD32      dwRunBeginTick; /* �������еĿ�ʼTickֵ */
    WORD32      dwRunEndTick;   /* �������еĽ���Tickֵ */
    BYTE        byLastOSState;  /* �ڱ�������ǰ�Ľ���״̬ */
}TProcInfoUnit;

/* ����������3�ε�������Ϣ */
typedef struct 
{
    BYTE           byCurIndex;  /* ��Ϣ�ı����±� */
    TProcInfoUnit  atProcInfo[VM_PROC_INFO_MAXNEEDSAVE]; /* ��������״̬������Ϣ */
}TProcInfoStruc;

typedef struct
{
    BYTE            byType;         /* �������� */
    
    WORD32          dwRunNum;       /* �������д��� */
    WORD32          dwLastRunNum;   /* �ϴ����д��� */
    
    OSTOKEN         tMbox;          /* ��������� */
    
    WORD16          wBlock;         /* ������� */    
    WORD16          wReady;         /* �������� */    
    WORD16          wRun;           /* ���ж��� */    
    
    WORD16          wReadyNum;      /* ����������Ŀ */
    WORD16          wBlockNum;      /* ���������Ŀ */
    
    WORD32          dwRetEIP;       /* ���ص�IPֵ */
    
    WORD32          dwBeginTick;    /* ��ʼ����tickֵ */
    WORD32          dwCurRunTick;   /* ��ǰ����tickֵ */
    WORD32          dwMaxRunTick;   /* �������tickֵ */
    
    BYTE            byPhaseName;    /* �������еĽ׶� */
    BYTE            byPhaseDepth;   /* �׶��ڵĲ�� */
    BOOL            bIsReady;       /* �����Ƿ��ڴ�����Ϣ */
    
}TTCBStruc;

/* 2008-10-27 pyy add start */
typedef struct 
{
	WORD32	dwUsed;
	WORD32	dwTaskId;			/* �����ڲ���ϵͳ�е������*/
	WORD32	dwPid;				/* ���̺� */
	WORD32	dwTaskScheNum;	/* ���񱻵��ȵ��Ĵ���*/
	WORD32	dwMsgNum;			/* ���������е���Ϣ����*/
	WORD32	dwWhileNum;		/* ����whileѭ���Ĵ���*/
} TTCBDebugStruc;

typedef struct 
{
	WORD32		dwUsed;
	WORD32		dwTaskNo;				/* ���������������*/
	WORD32		dwProcScheNum;		/* ���̱����ȵ��Ĵ���*/
	LPSTR             lpszName;           		/* ������ */
} TPCBDebugStruc;
/* 2008-10-27 pyy add end */

typedef struct tagTHookParam
{
	INT		iPara1;
	INT		iPara2;
	INT		iPara3;
	INT		iPara4;
	INT		iPara5;
	INT		iPara6;
} THookParam, *PTHookParam;

typedef struct tagTScheduleInfo
{
	BYTE	byTno; 
	WORD16	wPno;
	WORD16	wIno;
	WORD16	wCurState;
	WORD16  wEvent;
	BYTE	byStage;        /* ָʾ���ڵ���(DoSchedule)ǰ�������ڵ��Ⱥ� */
	THookParam	HookParam;  /* �û��ṩ�Ļص��������� */
} TScheduleInfo, *PTScheduleInfo;

/* ��������ص�������ԭ�� */
typedef BOOL (*ScheduleHookProto) (TScheduleInfo *);

typedef TTCBStruc TExtraTcbStruc;
typedef TTCBStruc TTCBUnionStruc;

extern  TTCBStruc      *lptTCB;
extern  TPCBStruc      *lptGlobalPCB;
extern  TProcInfoStruc *lptGlobalProcInfoSave;

TPCBStruc*  GetCurPCB (VOID);
TICBStruc*  VmGetCurICB (VOID);
TPCBStruc*  ScGetPCB (WORD16);
VOID        ScheTaskEntry (LPVOID lpIn);

BOOL        VmInstSelfUpdateState (WORD16 wState);
WORD16      VmInstSelfState (VOID);
BOOL        VmInstUpdateState (WORD16 wINo, WORD16 wState);
BOOL        VmInstUpdateStateEx (WORD16 wPno, WORD16 wINo, WORD16 wState);
BYTE        VmGetTno (WORD16);
BYTE        VmSelfTno (VOID);

TICBStruc*  ScGetICB (TPCBStruc *lptPCBPtr, WORD16 wInst);
VOID        ScKillMsg (VOID * lptMsgHook);

BOOL        OsTaskIsReady (BYTE byTask);
CHAR*       VmGetProcName (WORD16 wPno);
CHAR*       VmSelfProcName (VOID);
BYTE*       VmInstDataPtr (WORD16 wPno,WORD16 wInstNo);
VOID        DelPCBFromBlockQue (WORD16 wPno);
VOID        AddPCBToReadyQue (WORD16 wPno);
VOID        AddPCBToBlockQue (WORD16 wPno);
VOID        VmNextState (WORD16 wState);
WORD16      VmState (VOID);
WORD16      VmInstState (VOID);
LPBYTE      VmGetProcData (VOID);
VOID        VmSelfPid (TPID *lptPid);

WORD16      VmEvent (VOID);
WORD16      VmLength (VOID);
VOID        VmSender (TPID *lptPid);
VOID	  VmBSMsgType (BYTE *pbyMsgType);
WORD16      VmAckLen (VOID);
BOOL        VmIsSynEvent (VOID);
BYTE        VmMsgCellType (VOID);

BOOL        VmGetPid (CHAR *lpbyPName, TPID  *lptPid);
BOOL        VmGetLocalPid (CHAR *lpbyPName, TPID  *lptPid);
BOOL        VmGetLocalPidByPno (WORD16  wPno, TPID  *lptPid);
WORD16      VmSelfPno (VOID);
BOOL        VmUpdateState (WORD16 wState , WORD16 wINo);
WORD16      VmSelfIno (VOID);
BOOL        VmIsInstAlive (WORD16 wProc, WORD16 wInst);
WORD16      VmSelfPno (VOID);
WORD16      VmGetPno (CHAR  *lpbyPName);

BOOL        VmInitOfApp (WORD16 wInstDataSize,
                             WORD16 wInstMax,
                             InstEntryProto pfInstEntry,
                             InstInitProto pfInstDataInit
                            );

WORD16      VmProcState (VOID);
VOID        VmProcUpdateState (WORD16 byProcState);
VOID        VmProcNextState (WORD16 wProcState);
WORD16      VmInstStateEx (WORD16 wPno, WORD16 wInstNo);
VOID        VmInstNextState (WORD16 wState);

/* ������Ϣ�ӿں��� */
BOOL        VmSaveMsg (VOID);
BOOL        VmUnsaveMsg (VOID);
BOOL        VmUnsaveAllMsg (VOID);
WORD16      VmGetSavedMsgNum (VOID);
BOOL        VmClearAllSavedMsg (VOID);


CHAR* VmGetWlcRootPath(VOID);
CHAR* VmGetUsrRootPath(VOID);
CHAR* VmGetLogRootPath(VOID);
#endif /* _OSSVMSC_H_ */

