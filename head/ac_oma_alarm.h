#ifndef AC_OMA_ALARM_H
#define AC_OMA_ALARM_H

/* �澯��չ��Ϣ����ַ��� */
/*2011-11-29 ldm modify  */
#define MAX_ALARMEXTINFO_LEN    200
#define MAX_EVENTEXTINFO_LEN    200

#define AC_OMA_ALARM_ENTRY_MAXNUM 100

/* �澯���� */
typedef struct 
{
	UINT32	            ulAlarmCode;				    /* �澯��� */
    UINT32              ulMOC;                          /* �������� */
    UINT8               aucMOI[AC_MOI_LEN];             /* ����ʵ�� */

    UINT32	            ulAlarmStatus;					/* �澯״̬ */
    UINT32	            ulAlarmChangeTime;				/* �澯����/��������ʱ�䣨�ϲ���ʱ�䣩����λ���� */
    UINT32     	        ulAlarmSn;                      /* �澯��ˮ�� */    
} AC_OMC_ALARM_KEY_T;

/* omc alarm msg */
typedef struct
{
    AC_OMC_ALARM_KEY_T  stAlarmKey;

    UINT32	    		ulAlarmReasonID;				/* �澯ԭ���� */	
    UINT32	    		ulAlarmLevel;					/* �澯���� */
    
    UINT32      		ulAlarmRaiseTime;				/* �澯��������ʱ��(time()�����ķ���ֵ)����λ���� */
    UINT32	    		ulAlarmUptime;					/* �澯����/�����ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */
    UINT32	    		ulAlarmClearTime;				/* �澯�������ʱ�� */
/*2011-10-28 ldm add  */
    UINT32			ulAlarmSendTimes;			/* �澯���ʹ��� */
    UINT32			ulAlarmLastSendTime;			/* �澯�ϴη���ʱ�� */
	
    CHAR                		acAlarmExtInfo[MAX_ALARMEXTINFO_LEN];
} AC_OMC_ALARM_INFO_T;

/* �¼����� */
typedef struct 
{
	UINT32	            ulEventCode;				    /* �¼���� */
    UINT32              ulMOC;                          /* �������� */
    UINT8               aucMOI[16];                     /* ����ʵ�� */

    UINT32              ulEventRaiseTime;				/* �¼���������ʱ��(time()�����ķ���ֵ)����λ���� */
    UINT32              ulEventSn;                      /* �¼���ˮ�� */
} AC_OMC_EVENT_KEY_T;

typedef struct
{
    AC_OMC_EVENT_KEY_T  stEventKey;

    UINT32	    		ulEventReasonID;				/* �¼�ԭ���� */
    UINT32	    		ulEventUptime;					/* �¼�������ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */
/*2011-10-28 ldm add  */
    UINT32			ulEventSendTimes;				/* �¼��ط�����*/
    UINT32			ulEventLastSendTime;				/* �¼��ϴη���ʱ�� */
	
    CHAR        		acEventExtInfo[MAX_EVENTEXTINFO_LEN];
} AC_OMC_EVENT_INFO_T;

/* �澯�������ϱ�������Ϣ */ 
typedef AC_OMC_ALARM_INFO_T     AC_OMC_REPORT_ALARM_REQ_MSG_T;
typedef AC_OMC_EVENT_INFO_T  	AC_OMC_REPORT_EVENT_REQ_MSG_T;

/* �澯�������ϱ�Ӧ����Ϣ */
typedef AC_OMC_ALARM_KEY_T		AC_OMC_REPORT_ALARM_RSP_MSG_T;
typedef AC_OMC_EVENT_KEY_T      AC_OMC_REPORT_EVENT_RSP_MSG_T;

/* �����ϱ��澯 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_ALARM_INFO_T astAlarmInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_ALARM_BATCH_REQ_MSG_T;

/* ����Ӧ��澯 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_ALARM_KEY_T astAlarmKey[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_ALARM_BATCH_RSP_MSG_T;

/* �����ϱ��¼� */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_EVENT_INFO_T astEventInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_EVENT_BATCH_REQ_MSG_T;

/* ����Ӧ���¼� */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_EVENT_KEY_T astEventKey[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_EVENT_BATCH_RSP_MSG_T;

/* WTP�澯Ӧ����Ϣ */
typedef struct  
{
	UINT32	            ulAlarmCode;				    /* �澯��� */
	CHAR                acAlarmObjectId[128];
    UINT32	            ulAlarmStatus;					/* �澯״̬ */
    UINT32	            ulAlarmChangeTime;				/* �澯����/��������ʱ�䣨�ϲ���ʱ�䣩����λ���� */
    UINT32     	        ulAlarmSn;                      /* �澯��ˮ�� */   
}AC_WTP_ALARM_RSP_MSG_T;

/* WTP�¼�Ӧ����Ϣ */
typedef struct  
{
	UINT32	            ulEventCode;				    /* �¼���� */
	CHAR                acEventObjectId[128];
    UINT32              ulEventRaiseTime;				/* �¼���������ʱ��(time()�����ķ���ֵ)����λ���� */
    UINT32              ulEventSn;                      /* �¼���ˮ�� */
}AC_WTP_EVENT_RSP_MSG_T;

typedef struct 
{
    UINT32          ulNo;     /* alarm or event code */
    UINT32          ulStatus; /* 1:��Ч 0:��Ч */
}AC_OMA_ALARM_ENTRY_SETTING_T;

typedef struct 
{
    UINT32          ulNum;    /* num */
    AC_OMA_ALARM_ENTRY_SETTING_T astSetting[AC_OMA_ALARM_ENTRY_MAXNUM];
}AC_OMA_ALARM_SETTING_T;

/*******************************************AP-OMA<->AC-OMA********************/
#ifndef MAX_OID_LEN
#define MAX_OID_LEN     128
#endif

/* �澯��չ��Ϣ����ַ��� */
/* AP�ඨ��Ϊ200,���� */
//#define MAX_ALARMEXTINFO_LEN    200
//#define MAX_EVENTEXTINFO_LEN    200

/* �澯���� */
typedef struct
{
     unsigned long     ulAlarmCode;                      /* �澯��� */
	 char              acAlarmObjectID[MAX_OID_LEN];     /* �澯����OID */
     unsigned long     ulAlarmStatus;                    /* �澯״̬ */
     unsigned long     ulAlarmChangeTime;                /* �澯����/��������ʱ�䣨�ϲ���ʱ�䣩����λ���� */
     unsigned long     ulAlarmSn;                        /* �澯��ˮ�� */
} T_alarmKey;

/* alarm trap msg */
typedef struct
{
    T_alarmKey          stAlarmKey;
    unsigned long       ulAlarmReasonID;                 /* �澯ԭ���� */
    unsigned long       ulAlarmLevel;                    /* �澯���� */
    unsigned long       ulAlarmRaiseTime;                /* �澯����/�������ʱ��(time()�����ķ���ֵ)����λ���� */
    unsigned long       ulAlarmUptime;                   /* �澯����/�����ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */
    char                acAlarmExtInfo[200+4];
} T_alarmTrapMsg;

/* �¼����� */
typedef struct
{
	unsigned long       ulEventCode;                     /* �¼���� */
    char                acEventObjectID[MAX_OID_LEN];    /* �¼�����OID */
    unsigned long       ulEventRaiseTime;                /* �¼���������ʱ��(time()�����ķ���ֵ)����λ���� */
    unsigned long       ulEventSn;                       /* �¼���ˮ�� */
} T_eventKey; 

typedef struct
{
    T_eventKey          stEventKey;
    unsigned long       ulEventReasonID;                 /* �¼�ԭ���� */
    unsigned long       ulEventUptime;                   /* �¼�������ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */
    char                acEventExtInfo[200+4];
} T_eventTrapMsg;


/************************************ �澯������� ************************************/
#define AC_OMA_ALARM_FILTER_MAX_NUM   AC_OMA_ACTIVEALARM_QUEUE_NUM
typedef struct
{
	UINT32 ulNeId;
	UINT32 ulAlarmCode;
}AC_OMA_ALARM_FILTER_ENTRY_T;

typedef struct
{
	UINT32 ulNum;
	AC_OMA_ALARM_FILTER_ENTRY_T astInfo[AC_OMA_ALARM_FILTER_MAX_NUM];
}AC_OMA_ALARM_FILTER_T;

/************************************ ���� ************************************/
AC_RET  ac_oma_init_alarm_report_queue(UINT32 ulNodeNum);
AC_RET  ac_oma_init_event_report_queue(UINT32 ulNodeNum);

/* add init active alarm cache queue */
AC_RET  ac_oma_init_activealarm_cache_quue(UINT32 ulNodeNum);

BOOL    ac_oma_is_same_alarm(const VOID *source, const VOID *dest);
BOOL    ac_oma_is_same_event(const VOID *source, const VOID *dest);

/* new add */
UINT32  ac_oma_calc_hash_key_alarm(const CHAR *msg, UINT32 ulNodeNum);
UINT32  ac_oma_calc_hash_key_event(const CHAR *msg, UINT32 ulNodeNum);

/* new add */
BOOL    ac_oma_is_same_active_alarm(const VOID *source, const VOID *dest);
UINT32  ac_oma_calc_hash_key_active_alarm(const CHAR *msg, UINT32 ulNodeNum);

AC_RET  ac_oma_add_alarm_msg_to_queue(const AC_OMC_ALARM_INFO_T *pstMsg);
VOID*   ac_oma_locate_alarm_msg(const AC_OMC_ALARM_INFO_T *msg);

/* add active alarm  */
AC_RET  ac_oma_add_activealarm_msg_queue(const AC_OMC_ALARM_INFO_T *pstMsg);
VOID*   ac_oma_locate_activealarm_msg(const AC_OMC_ALARM_INFO_T *msg);

AC_RET  ac_oma_add_event_msg_to_queue(const AC_OMC_EVENT_INFO_T *pstMsg);

/* 2008/09/19 �뾲 ���� */
VOID*   ac_oma_locate_event_msg(const AC_OMC_EVENT_INFO_T *msg);

AC_RET  ac_oma_remove_alarm_msg_from_queue(AC_OMC_ALARM_KEY_T *pstMsg);
AC_RET  ac_oma_remove_event_msg_from_queue(AC_OMC_EVENT_KEY_T *pstMsg);

/* remove active alarm from queue */
AC_RET  ac_oma_remove_activealarm_msg_from_queue(AC_OMC_ALARM_KEY_T *pstMsg);

AC_RET  ac_oma_resend_alarm_queue_msg(VOID);
AC_RET  ac_oma_resend_event_queue_msg(VOID);

AC_RET  ac_oma_send_alarm_msg(const CHAR* szMsg);
AC_RET  ac_oma_send_event_msg(const CHAR* szMsg);

VOID    ac_oma_print_alarm_key(BYTE byLevel, AC_OMC_ALARM_KEY_T *msg);
VOID    ac_oma_set_alarm_ext_info(const AC_OMA_ALARM_INFO_T *pstEventInfo, CHAR *szExtInfo);
VOID    ac_oma_set_event_ext_info(const AC_OMA_EVENT_INFO_T *pstEventInfo, CHAR *szExtInfo);

AC_RET  ac_oma_convert_alarm_msg(const AC_OMA_ALARM_INFO_T *pstOmaAlarmInfo, AC_OMC_ALARM_INFO_T *pstOmcAlarmInfo);
AC_RET  ac_oma_convert_alarm_clear_msg(const AC_OMA_ALARM_CLEAR_INFO_T *pstOmaAlarmInfo, AC_OMC_ALARM_INFO_T *pstOmcAlarmInfo);
AC_RET  ac_oma_convert_event_msg(const AC_OMA_EVENT_INFO_T *pstOmaEventInfo, AC_OMC_EVENT_INFO_T *pstOmcEventInfo);

UINT32  ac_oma_generate_alarm_sn(VOID);
VOID    ac_oma_check_alarm_report(VOID);

extern AC_RET ac_oma_report_alarm_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_clear_alarm_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_report_alarm_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

extern AC_RET ac_oma_report_event_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_report_event_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

extern AC_RET ac_omc_report_alarm_clear_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);
AC_RET  ac_oma_convert_omc_alarm_clear_msg(const AC_OMC_ALARM_CLEAR_INFO_T *pstOmcClearAlarmInfo, AC_OMC_ALARM_INFO_T *pstOmcAlarmInfo);

AC_RET ac_oma_send_wtp_alarm_rsp_msg(AC_OMC_REPORT_ALARM_RSP_MSG_T *pstRsp);
AC_RET ac_oma_send_wtp_event_rsp_msg(AC_OMC_REPORT_EVENT_RSP_MSG_T *pstRsp);

/* 2009-09-03 fengjing add */
AC_RET ac_oma_ap_report_alarm_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
AC_RET ac_oma_ap_report_event_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2009-11-03 fengjing add */
AC_RET ac_oma_send_alarm_msg_batch(UINT32 ulNum, AC_OMA_QUEUE_NODE_T **ppstNode);
AC_RET ac_oma_send_event_msg_batch(UINT32 ulNum, AC_OMA_QUEUE_NODE_T **ppstNode);
AC_RET ac_omc_report_alarm_batch_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
AC_RET ac_omc_report_event_batch_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2010-05-18 fengjing add */
AC_RET ac_oma_check_activealarm_resend(VOID);
VOID ac_oma_inner_report_alarm (UINT32 ulAlarmId,
                             UINT32 ulAlarmReasonId,
                             UINT32 ulAlarmLevel,
                             UINT32 ulMOC,
                             UINT8	aucMOI[AC_MOI_LEN],
                             UINT32 ulCommonInfo);
BOOL ac_oma_is_wtp_alarm(UINT32 ulAlarmCode);
AC_RET ac_oma_check_activealarm_clear(AC_OMA_ALARM_FILTER_T *pstAlarmFilter);
AC_RET ac_oma_update_alarm_msg(AC_OMC_ALARM_KEY_T *pstAlarmKey, UINT32 ulAlarmStatus);
#endif /* AC_OMA_ALARM_H */



