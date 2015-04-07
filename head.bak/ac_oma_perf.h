#ifndef OMA_PERF_H
#define OMA_PERF_H

/************************************ 无线部分 *******************************/

#define MAX_PERF_TASK_CG_NUM       100     /* 性能计数器组个数 */

#define MAX_PERF_COUNTERGROUP_DESTPNAME_LEN    32

#define AC_OMA_PERF_ENTRY_MAXNUM 100

/* 计数器组信息（静态信息，除了上次上报时间为动态信息） */
typedef struct
{
    UINT32              ulPerfCounterGroupID;   /* 计数器组ID */
    UINT32              ulStatus;               /* 计数器状态，0:无效(不上报) 1:有效 */
    UINT32              ulPerfReportInterval;   /* 上报周期, 单位:秒 */
	UINT32				ulRealtimeQuery;		/* 实时查询, 0:不支持，1:支持 */
    UINT32              ulPerfCounterNum;       /* 计数器组包括的计数器个数 */
    UINT32              ulLastReportTime;       /* 上次上报时间 */
    CHAR                acDestPName[MAX_PERF_COUNTERGROUP_DESTPNAME_LEN];
}AC_OMA_PERF_COUNTERGROUP_INFO_T;

/* 性能采集任务结构体定义 */
typedef struct
{
    UINT32       ulPerfCounterGroupID;		/* 计数器组ID */
    UINT32       ulStatus;					/* 计数器状态, 0:无效(不上报) 1:有效 */
    UINT32       ulPerfReportInterval;		/* 上报周期, 单位:秒 */
	UINT32       ulRealtimeQuery;			/* 实时查询, 0:不支持，1:支持 */
}OMA_PERF_TASK_CG_T;

/* 性能采集任务 */
typedef struct
{
    UINT32                 ulPerfCgNum;          /* 性能计数器组个数 */
    OMA_PERF_TASK_CG_T     astPerfCgInfo[MAX_PERF_TASK_CG_NUM];
}OMC_PERF_TASK_T;


/* 修改性能采集任务请求消息 */
typedef struct
{
    UINT32					ulSn;           /* 同步请求消息序列号 */
    OMC_PERF_TASK_T			stReqMsg;		/* 修改内容 */
}AC_OMC_SET_PERF_TASK_REQ_MSG_T;


/* 修改性能采集任务应答消息 */
typedef struct
{
    UINT32					ulSn;           /* 同步应答消息序列号 */
    UINT32					ulRetCode;		/* 修改结果, 0:成功 1:失败 */
}AC_OMC_SET_PERF_TASK_RSP_MSG_T;

typedef struct
{
    UINT32                  ulNo;
    UINT32                  ulPeriod;
    UINT32                  ulStatus;
}AC_OMA_PERF_ENTRY_SETTING_T;

typedef struct
{
    UINT32                  ulNum;
    AC_OMA_PERF_ENTRY_SETTING_T astSetting[AC_OMA_PERF_ENTRY_MAXNUM];
}AC_OMA_PERF_SETTING_T;

/********************************AP-OMA<->AC-OMA**************************/
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

/******************************** 函数定义 *******************************/
AC_RET  ac_oma_init_perf_report_queue(UINT32 nodeNum);
BOOL    ac_oma_is_same_perf(VOID *source, VOID *dest);

/* new add */
UINT32  ac_oma_calc_hash_key_perf(const CHAR * msg, UINT32 ulNodeNum);

AC_RET  ac_oma_add_perf_msg_to_queue(const AC_OMC_PERF_INFO_T *msg);
AC_RET  ac_oma_remove_perf_msg_from_queue(AC_OMC_REPORT_PERF_RSP_MSG_T *msg);

AC_RET  ac_oma_resend_perf_queue_msg(VOID);
AC_RET  ac_oma_send_perf_report_msg(const CHAR* msg);

AC_OMA_PERF_COUNTERGROUP_INFO_T* ac_oma_get_perf_countergroup_info(UINT32 ulPerfCounterGroupID);
AC_RET  ac_oma_set_perf_task_countergroup(const OMA_PERF_TASK_CG_T* pstPerfTaskCounterGroup);

AC_RET  ac_oma_init_omc_perf_info(UINT32 ulPerfCounterGroupID, AC_OMC_PERF_INFO_T* pstOmcPerfMsg);
AC_RET  ac_omc_report_perf_rsp_msg(VOID* req, UINT32 len);
VOID    ac_oma_check_perf_report(VOID);

extern AC_RET ac_oma_perf_report_req_msg(VOID);

AC_RET ac_oma_send_perf_msg_batch(UINT32 ulNum, AC_OMA_QUEUE_NODE_T **ppstNode);

/* 应用模块应答OMA获取性能上报的消息 */
extern AC_RET ac_oma_report_perf_rsp_msg(const UINT8 *pucMsg, UINT16 usMsgLen);

/* OMC设置性能统计任务 */
extern AC_RET ac_omc_set_perf_task_req_msg(VOID* req, UINT32 len);

AC_RET ac_oma_send_wtp_perf_rsp_msg(AC_OMC_REPORT_PERF_RSP_MSG_T *pstRsp);

/* 2009-09-03 fengjing add */
AC_RET ac_oma_ap_report_perf_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
BOOL ac_oma_is_wtp_perf(UINT32 ulPerfCounterGroupId);

#endif /* OMA_PERF_H */
