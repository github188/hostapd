#ifndef OMA_PERF_H
#define OMA_PERF_H

/************************************ ���߲��� *******************************/

#define MAX_PERF_TASK_CG_NUM       100     /* ���ܼ���������� */

#define MAX_PERF_COUNTERGROUP_DESTPNAME_LEN    32

#define AC_OMA_PERF_ENTRY_MAXNUM 100

/* ����������Ϣ����̬��Ϣ�������ϴ��ϱ�ʱ��Ϊ��̬��Ϣ�� */
typedef struct
{
    UINT32              ulPerfCounterGroupID;   /* ��������ID */
    UINT32              ulStatus;               /* ������״̬��0:��Ч(���ϱ�) 1:��Ч */
    UINT32              ulPerfReportInterval;   /* �ϱ�����, ��λ:�� */
	UINT32				ulRealtimeQuery;		/* ʵʱ��ѯ, 0:��֧�֣�1:֧�� */
    UINT32              ulPerfCounterNum;       /* ������������ļ��������� */
    UINT32              ulLastReportTime;       /* �ϴ��ϱ�ʱ�� */
    CHAR                acDestPName[MAX_PERF_COUNTERGROUP_DESTPNAME_LEN];
}AC_OMA_PERF_COUNTERGROUP_INFO_T;

/* ���ܲɼ�����ṹ�嶨�� */
typedef struct
{
    UINT32       ulPerfCounterGroupID;		/* ��������ID */
    UINT32       ulStatus;					/* ������״̬, 0:��Ч(���ϱ�) 1:��Ч */
    UINT32       ulPerfReportInterval;		/* �ϱ�����, ��λ:�� */
	UINT32       ulRealtimeQuery;			/* ʵʱ��ѯ, 0:��֧�֣�1:֧�� */
}OMA_PERF_TASK_CG_T;

/* ���ܲɼ����� */
typedef struct
{
    UINT32                 ulPerfCgNum;          /* ���ܼ���������� */
    OMA_PERF_TASK_CG_T     astPerfCgInfo[MAX_PERF_TASK_CG_NUM];
}OMC_PERF_TASK_T;


/* �޸����ܲɼ�����������Ϣ */
typedef struct
{
    UINT32					ulSn;           /* ͬ��������Ϣ���к� */
    OMC_PERF_TASK_T			stReqMsg;		/* �޸����� */
}AC_OMC_SET_PERF_TASK_REQ_MSG_T;


/* �޸����ܲɼ�����Ӧ����Ϣ */
typedef struct
{
    UINT32					ulSn;           /* ͬ��Ӧ����Ϣ���к� */
    UINT32					ulRetCode;		/* �޸Ľ��, 0:�ɹ� 1:ʧ�� */
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

/******************************** �������� *******************************/
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

/* Ӧ��ģ��Ӧ��OMA��ȡ�����ϱ�����Ϣ */
extern AC_RET ac_oma_report_perf_rsp_msg(const UINT8 *pucMsg, UINT16 usMsgLen);

/* OMC��������ͳ������ */
extern AC_RET ac_omc_set_perf_task_req_msg(VOID* req, UINT32 len);

AC_RET ac_oma_send_wtp_perf_rsp_msg(AC_OMC_REPORT_PERF_RSP_MSG_T *pstRsp);

/* 2009-09-03 fengjing add */
AC_RET ac_oma_ap_report_perf_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
BOOL ac_oma_is_wtp_perf(UINT32 ulPerfCounterGroupId);

#endif /* OMA_PERF_H */
