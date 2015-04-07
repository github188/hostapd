#ifndef OMA_PERF_H
#define OMA_PERF_H

/************************************ ���߲��� *******************************/

#define MIN_PERFTRAPMSG_NUM     256

/* ���ܼ������������������������ */
#define MAX_PERFCOUNTER_NUM     20

typedef struct
{
    unsigned long       ulPerfCounterGroupID;   /* ��������� */
    unsigned long       ulPerfReportTime;       /* �ϱ�ʱ�� */
    char                acPerfObjectID[MAX_OID_LEN];   /* ͳ�ƶ���OID */
} T_perfKey;

/* �����ϱ���Ϣ */
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

/* �����ϱ�Ӧ����Ϣ */
typedef T_perfKey T_perfAckMsg;

typedef int (*GET_NEW_PERF_FUNC)(OMA_PERFMSG_ENTRY_T* dest);
typedef int (*PERF_REPORT_FUNC)(void* pstPerfData);

typedef struct
{
    unsigned long       ulPerfCounterGroupID;   /* ��������ID */
    //unsigned long       ulStatus;               /* ������״̬��0:��Ч(���ϱ�) 1:��Ч */

    //unsigned long       ulPerfReportInterval;   /* �ϱ�����, ��λ:�� */

    unsigned long       ulPerfCounterNum;       /* ������������ļ��������� */

    GET_NEW_PERF_FUNC   getNewPerfFunc;         /* ��ȡ�µ�����ͳ�ƺ��� */

    unsigned long       lastReportTime;         /* �ϴ��ϱ�ʱ�� */

    //OMA_PERF_CFG_T      *pstPerfCfg;
}T_perfCounterInfo;


/* �������� */
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
