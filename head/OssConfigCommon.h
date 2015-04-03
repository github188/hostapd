/******************************************************************************
模块名      : SYSCFG
文件名      : OssConfigCommon.h
相关文件    :
实现功能    : 所有工程的系统配置
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSCONFIGCOMMON_H_
#define _OSSCONFIGCOMMON_H_

/*------------------------------------------------------------*/
/* 调度管理 */
#define MAX_ISR_FUNC_NUM        (BYTE) 10       /* 系统辅助时钟 ISR 回调函数最大个数 */
#define MAX_REALTIME_TASK_NUM   (BYTE) 10       /* 实时任务最大个数 */

#define PROC_NUM_OSS            (WORD16) 10     /* OSS 进程数目 */
#define PROC_NUM_APP            (WORD16) 30     /* APP 进程数目 */


/* IPC 配置 */
#ifdef BIG_AC
#define OSS_CPU_NUM             (WORD16) (1050*4)
#else
#define OSS_CPU_NUM             (WORD16) 1050
#endif
#define MSG_QNODE_SIZE          (WORD16) 4      /* 消息长度 */


/* 内存管理 */
#define UB_SPAN                 (WORD16) 64     /* UB_POOL间的大小 */
#define VMMM_POOL_NUM           (WORD16) 18     /* UB_POOL的大小 */    

#ifdef APP_PROJ_AC
//#ifdef BIG_AC
/* 2010-12-1 pyy 支持4096 ap 修改 */
//#define TMCB_NUM                (WORD16) (2000*10)  /* 定时器数目 */
//#else
#define TMCB_NUM                (WORD16) 20000  /* 定时器数目 */
//#endif
#else
#define TMCB_NUM                (WORD16) 2000  /* 定时器数目 */
#endif

/*-------------------------------------------------------------*/
typedef struct  TagPAT
{
    BYTE            byUse;                      /* 使用标志 */
    BYTE            abyPName[PROC_NAME_LENGTH]; /* 进程名 */
    BYTE            byTno;                      /* 任务号 */
    ProcEntryProto  lptEntry;                   /* 进程入口 */
    WORD16          wProcDataSize;              /* 进程数据大小 */
    WORD32          dwStackSize;                /* 私有栈大小 */
	ProcInitProto	lptDataAreaInit;            /* 进程数据区初始化函数 */
}TPATStruc;

typedef struct{
    BYTE    byInUse;
    CHAR    lpName[PROC_NAME_LENGTH];
    WORD32    wTimeout;
    BYTE    byOption;
} TBaseProcStruct;

typedef struct{
    BYTE    byInUse;
    CHAR    lpName[PROC_NAME_LENGTH];
} TLastProcStruct;

/* 辅助定时任务回调函数 */
typedef struct
{
    RtProcProto     tAuxtimeTask;               /* 时钟级任务 */
    WORD16          wTimeSpan;                  /* 时长(10ms为单位) */
}TRealtimeTaskTable;

/* UB大小控制 */
typedef struct
{
    WORD32          dwSize;                     /* 大小 */
    WORD32          wTotal;                     /* 总数 */
}TUBSizeStruc;


/*-------------------------------------------------------------*/

extern  TPATStruc           atPAT_OSS[];
extern  TPATStruc           atPAT_APP[];
extern  TPATStruc           atPAT[];
extern  TTcbTable           aTaskTable[];

extern  TUBSizeStruc        atUBSize[];
extern  TUBSizeStruc        atOldUBSize[];
extern  TUBSizeStruc        atNewUBSize[];
extern  WORD16              awReservePool[];

extern  TRealtimeTaskTable  atRealtimeTaskTable[];
extern  TBaseProcStruct     atBaseProcTab[];
extern  TLastProcStruct     atLastProcTab[];
extern  TAddrMapTable       atAddrMapTable[];

extern  BOOL                gbGetAddrTableFromDbs;

extern  WORD                gwAcId;
extern  WORD                gwApId;

extern  CHAR                * gstrLogSvrAddr;
extern  WORD16              gwLogSvrPort;

extern  TIPAddr             gtCnIpAddr;

extern  TIPAddr             gtNodeBIpAddr;
extern  WORD16              gwNodeBUdpPort;
extern  CHAR                * gszNbMsgRecvProc;

#endif /* _OSSCONFIGCOMMON_H_ */
