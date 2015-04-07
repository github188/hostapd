/******************************************************************************
模块名      : VMSC
文件名      : OssVmsc.h
相关文件    :
实现功能    : VMSC 基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/
#ifndef _OSSVMSC_H_
#define _OSSVMSC_H_


/* 宏定义 */
#define VMSC_BLOCK                  (BYTE) 1            /* 调度状态: 阻塞 */
#define VMSC_READY                  (BYTE) 2            /* 调度状态: 就绪 */
#define VMSC_RUNING                 (BYTE) 3            /* 调度状态: 运行 */

#define VMSC_NOT_WAIT               (BYTE) 0            /* 未处于同步等待 */
#define VMSC_SYN_WAIT               (BYTE) 2            /* 等待同步应答消息 */

#define VMSC_PCB_NUM                (WORD16) 50        /* 进程数目 */
#define VMSC_TIMER_NUM              (WORD16) 32         /* 每个实例能设的最大定时器数 */
#define VMSC_SAVED_MSG_NUM          (WORD16) 50         /* 每个实例保存消息队列中最大消息数目 */

#define VMSC_MAIN_TASK_NO           (BYTE)0x88          /* 主任务号 */

#define VMSC_SCHEDULE_TASK          (BYTE)0x01          /* 任务类型: 调度任务 */
#define VMSC_EXTRA_TASK             (BYTE)0x02          /* 任务类型: 特殊任务 */

#define VM_INVALID_PNO              (WORD16)0xFFFF      /* 无效进程号 */
#define VM_INVALID_INO              (WORD16)0xFFFF      /* 无效实例号 */
#define VM_DEFAULT_INST             (WORD16)0xFFFE      /* 缺省实例, 即进程 */
#define VM_PROC_STATE_IDLE          (WORD16)0           /* 进程初始状态 */
#define VM_PROC_STATE_INVALID       (WORD16)0xFFFF      /* 进程无效状态 */
#define VM_INST_STATE_IDLE          (WORD16)0           /* 实例初始状态 */
#define VM_INST_STATE_INVALID       (WORD16)0xFFFD      /* 实例无效状态 */

#define VM_INVALID_CELL_TYPE        (BYTE)0xFF          /* 无效的网元类型 */

#define VMSC_FILL_VALUE             (BYTE)0xCC          /* 进程栈的初始填充值 */

#define VM_PROC_INFO_MAXNEEDSAVE    (BYTE)3             /* 进程最多需要最近保存的状态个数 */

#define VMSC_ICB_FREE               (BYTE)0             /* 标记 ICB 为空闲 */
#define VMSC_ICB_USED               (BYTE)1             /* 标记 ICB 为占用 */

/* 调度回调函数的参数类型申明 */
#define VM_STAGE_BEFORE_SCHEDULE    (BYTE)0x00          /* 指示调度钩子目前是在调度前 */
#define VM_STAGE_AFTER_SCHEDULE     (BYTE)0x01          /* 指示调度钩子目前是在调度后 */

typedef VOID (*InstInitProto) (BYTE*);                  /* 实例初始化原型 */
typedef VOID (*InstEntryProto) (WORD16 wEvent,          /* 实例入口原型 */
                                LPBYTE lpbyIn,
                                WORD16 wInLen,
                                LPBYTE lpbyAck,
                                WORD16 wAckLen,
                                LPBYTE lpbyData
                               );

typedef VOID (*ProcEntryProto) (WORD16 wEvent,          /* 进程入口原型 */
                                LPBYTE lpbyIn,
                                WORD16 wInLen,
                                LPBYTE lpbyAck,
                                WORD16 wAckLen,
                                LPBYTE lpbyData 
                               );

typedef VOID (*ProcInitProto) (BYTE*);                  /* 进程初始化原型 */

typedef struct tagICB
{
    BYTE            byFlag;
    WORD16          wInst;                  /* 实例号 */
    WORD16          wInstPrev;
    WORD16          wInstNext;
    BYTE*           pDataArea;
    WORD16          wCurState;              /* 实例状态 */
    WORD16          wDelayTid;              /* 同步定时ID */
    WORD16          wTimerNum;              /* 异步定时数目 */
    WORD16          awTid[VMSC_TIMER_NUM];  /* 异步定时器ID */
    TPID            pidCreator;
    TPID            pidKiller;    
    WORD16          wSMsgNum;               /* 保存消息数目 */
    TMsgStruc       *lptSMsgHead;           /* 保存消息队列头指针 */
    TMsgStruc       *lptSMsgTail;           /* 保存消息队列尾指针 */    
} TICBStruc, *LPTICB;


/* lixp, 2001-11-07, (1) 调整成员顺序; (2) 删除tSelfPid成员 */
/* 如果需要修改该结构的定义，请慎重，会影响栈操作 */
typedef struct tagPCB
{
    BYTE                byUse;              /* 使用标志 */

    BYTE                byTno;              /* 任务号 */
    WORD16              wPno;
    WORD32              dwTaskSP;           /* 任务栈偏移 */
    WORD32              dwProcessSP;        /* 进程栈偏移指针 */
    WORD32              dwTaskSS;           /* 任务栈的段指针 */
    WORD32              dwProcessSS;        /* 进程栈段指针 */
    LPBYTE              lpbyTaskSS;
    LPBYTE              lpbyProcessSS;      /* 栈指针 */
    WORD32              dwStackSize;        /* 进程栈大小*/
    LPBYTE              lpbySwitchStack;    /* 换栈指针 */

    LPSTR               lpszName;           /* 进程名 */
    TICBStruc           tProcessICB;        /* 进程缺省的ICB */
    WORD16              wProcDataSize;      /* 共享数据区大小 */
    ProcEntryProto      pfProcEntry;        /* 进程入口地址 */
	ProcInitProto		pfDataAreaInit;     /* 进程数据区初始化函数 */

    WORD16              wInst;              /* 进程当前实例号 */
    WORD16              wInstMax;           /* 最大进程实例数 */    
    WORD16              wInstAlive;         /* 存活进程实例数 */    
    WORD16              wInstDataSize;      /* 进程实例数据区大小 */
    InstEntryProto      pfInstEntry;        /* 实例入口*/
    InstInitProto       pfInstDataInit;     /* 实例数据初始化入口 */
    TICBStruc           *atICBTab;          /* 实例ICB数组 */
    TICBStruc           *lptUsedICBHead;    /* 占用的ICB队列头 */
    TICBStruc           *lptUsedICBTail;    /* 占用的ICB队列尾 */
    TICBStruc           *lptFreeICBHead;    /* 空闲的ICB队列头 */
    TICBStruc           *lptFreeICBTail;    /* 空闲的ICB队列尾 */

    BYTE                byWait;             /*同步等待标志*/
    BYTE                byOSState;          /* 进程状态 */    
    BYTE                bySaved;            /* 当前消息是否被保存 */    
    TPID                tCurSender;         /* 当前消息发送者 */
    WORD16              wCurSendEvent;      /* 当前发送的事件 */    
    TPID                tCurReceiver;       /* 当前消息接收者 */
    WORD16              wCurEvent;          /* 当前接收的事件 */    
    TMsgStruc           *lptCurMsg;         /* 当前消息指针 */
    WORD16              wMsgNum;            /* 消息数目 */
    TMsgStruc           *lptMsgHead;        /* 消息队列头指针 */
    TMsgStruc           *lptMsgTail;        /* 消息队列尾指针 */

    BYTE                byNormalRet;        /* 是否正常返回标志 */
    WORD32              dwRunNum;           /* 进程被调度的次数 */
    WORD32              dwLastRunNum;       /* 进程前次被调度的次数 */
    WORD32              dwSendMsgCount;     /* 发送的消息数 */
    WORD32              dwSendByteCount;    /* 发送的消息字节数 */
    WORD32              dwBeginTick;        /* 进程开始运行的tick值 */
    WORD32              dwCurRunTick;       /* 进程本次运行的tick值 */
    WORD32              dwMaxRunTick;       /* 进程运行的最大tick值 */
    WORD32              dwIpcTrace;         /* 进程IPC跟踪选项 */
    WORD32              dwLogLevel;         /* 进程LOG选项 */
    BYTE                byLogLevel;         /* 前台打印控制，有待调整 */

    WORD16              wPrev;              /* 前向指针 */
    WORD16              wNextPCB;           /* 后向指针 */
    WORD32              dwReserve;
}TPCBStruc;

/* 进程运行的保存信息 */
typedef struct
{
    WORD16      wInst;          /* 当前运行的实例号 */
    TMsgStruc   tCurMsgHead;    /* 本次运行处理的消息的消息头 */
    WORD32      dwRunBeginTick; /* 本次运行的开始Tick值 */
    WORD32      dwRunEndTick;   /* 本次运行的结束Tick值 */
    BYTE        byLastOSState;  /* 在本次运行前的进程状态 */
}TProcInfoUnit;

/* 保存进程最近3次的运行信息 */
typedef struct 
{
    BYTE           byCurIndex;  /* 信息的保存下标 */
    TProcInfoUnit  atProcInfo[VM_PROC_INFO_MAXNEEDSAVE]; /* 进程运行状态保存信息 */
}TProcInfoStruc;

typedef struct
{
    BYTE            byType;         /* 任务类型 */
    
    WORD32          dwRunNum;       /* 任务运行次数 */
    WORD32          dwLastRunNum;   /* 上次运行次数 */
    
    OSTOKEN         tMbox;          /* 任务的信箱 */
    
    WORD16          wBlock;         /* 挂起队列 */    
    WORD16          wReady;         /* 就绪队列 */    
    WORD16          wRun;           /* 运行队列 */    
    
    WORD16          wReadyNum;      /* 就绪队列数目 */
    WORD16          wBlockNum;      /* 挂起队列数目 */
    
    WORD32          dwRetEIP;       /* 返回的IP值 */
    
    WORD32          dwBeginTick;    /* 开始运行tick值 */
    WORD32          dwCurRunTick;   /* 当前运行tick值 */
    WORD32          dwMaxRunTick;   /* 最大运行tick值 */
    
    BYTE            byPhaseName;    /* 任务运行的阶段 */
    BYTE            byPhaseDepth;   /* 阶段内的层次 */
    BOOL            bIsReady;       /* 任务是否在处理消息 */
    
}TTCBStruc;

/* 2008-10-27 pyy add start */
typedef struct 
{
	WORD32	dwUsed;
	WORD32	dwTaskId;			/* 任务在操作系统中的任务号*/
	WORD32	dwPid;				/* 进程号 */
	WORD32	dwTaskScheNum;	/* 任务被调度到的次数*/
	WORD32	dwMsgNum;			/* 任务邮箱中的消息数量*/
	WORD32	dwWhileNum;		/* 任务while循环的次数*/
} TTCBDebugStruc;

typedef struct 
{
	WORD32		dwUsed;
	WORD32		dwTaskNo;				/* 进程所属的任务号*/
	WORD32		dwProcScheNum;		/* 进程被调度到的次数*/
	LPSTR             lpszName;           		/* 进程名 */
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
	BYTE	byStage;        /* 指示是在调度(DoSchedule)前，还是在调度后 */
	THookParam	HookParam;  /* 用户提供的回调函数参数 */
} TScheduleInfo, *PTScheduleInfo;

/* 调度任务回调函数的原型 */
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

/* 保存消息接口函数 */
BOOL        VmSaveMsg (VOID);
BOOL        VmUnsaveMsg (VOID);
BOOL        VmUnsaveAllMsg (VOID);
WORD16      VmGetSavedMsgNum (VOID);
BOOL        VmClearAllSavedMsg (VOID);


CHAR* VmGetWlcRootPath(VOID);
CHAR* VmGetUsrRootPath(VOID);
CHAR* VmGetLogRootPath(VOID);
#endif /* _OSSVMSC_H_ */

