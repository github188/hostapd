#ifndef OMA_PERF_H
#define OMA_PERF_H

/************************************ 无线部分 *******************************/

#define MIN_PERFTRAPMSG_NUM     256

/* 性能计数器组包含的最大计数器个数 */
#define MAX_PERFCOUNTER_NUM     20

typedef struct
{
    unsigned long       ulPerfCounterGroupID;   /* 计数器编号 */
    unsigned long       ulPerfReportTime;       /* 上报时间 */
    char                acPerfObjectID[MAX_OID_LEN];   /* 统计对象OID */
} T_perfKey;

/* 性能上报消息 */
typedef struct
{
    T_perfKey           stPerfKey;
    
    unsigned long       ulPerfReportInterval;

    unsigned long       ulPerfCounterNum;
    double              adPerfCounterValues[MAX_PERFCOUNTER_NUM];
} T_perfTrapMsg;

#define MAX_PERF_ENTRY_NUM  200
typedef struct 
{
    UINT32              ulValidNum;
    T_perfTrapMsg       astPerfMsg[MAX_PERF_ENTRY_NUM];
}OMA_PERFMSG_ENTRY_T;

/* 性能上报应答消息 */
typedef T_perfKey T_perfAckMsg;

typedef int (*GET_NEW_PERF_FUNC)(OMA_PERFMSG_ENTRY_T* dest);
typedef int (*PERF_REPORT_FUNC)(void* pstPerfData);

typedef struct
{
    unsigned long       ulPerfCounterGroupID;   /* 计数器组ID */
    //unsigned long       ulStatus;               /* 计数器状态，0:无效(不上报) 1:有效 */

    //unsigned long       ulPerfReportInterval;   /* 上报周期, 单位:秒 */

    unsigned long       ulPerfCounterNum;       /* 计数器组包括的计数器个数 */

    GET_NEW_PERF_FUNC   getNewPerfFunc;         /* 获取新的性能统计函数 */

    unsigned long       lastReportTime;         /* 上次上报时间 */

    //OMA_PERF_CFG_T      *pstPerfCfg;
}T_perfCounterInfo;


/* 函数定义 */
int initPerfReportQueue(unsigned long nodeNum);
int comparePerf(void *source, void *dest);
int addPerfTrapMsgToQueue(T_perfTrapMsg *msg);
int removePerfTrapMsgFromQueue(T_perfAckMsg *msg);
int resendPerfQueueMsg(void);
int omaSendPerfTrapMsg(char* msg);
T_perfCounterInfo* getPerfCounterInfo(unsigned long perfCounterGroupID);
OMA_PERF_CFG_T* getPerfCfg(unsigned long perfCounterGroupID);

int initPerfTrapInfo(unsigned long perfCounterGroupID, T_perfTrapMsg* perfTrapMsg);

int getNewFlowStat(OMA_PERFMSG_ENTRY_T* pstTrapMsg);
int getNewVapStat(OMA_PERFMSG_ENTRY_T* pstTrapMsg);
int getNewAdhocStat(OMA_PERFMSG_ENTRY_T* pstTrapMsg);

void oma_check_perf_report(void);

#endif /* OMA_PERF_H */
