#ifndef AC_OMA_ALARM_H
#define AC_OMA_ALARM_H

/* 告警扩展信息最大字符数 */
/*2011-11-29 ldm modify  */
#define MAX_ALARMEXTINFO_LEN    200
#define MAX_EVENTEXTINFO_LEN    200

#define AC_OMA_ALARM_ENTRY_MAXNUM 100

/* 告警主键 */
typedef struct 
{
	UINT32	            ulAlarmCode;				    /* 告警编号 */
    UINT32              ulMOC;                          /* 对象类型 */
    UINT8               aucMOI[AC_MOI_LEN];             /* 对象实例 */

    UINT32	            ulAlarmStatus;					/* 告警状态 */
    UINT32	            ulAlarmChangeTime;				/* 告警产生/清除最后发生时间（合并后时间），单位：秒 */
    UINT32     	        ulAlarmSn;                      /* 告警流水号 */    
} AC_OMC_ALARM_KEY_T;

/* omc alarm msg */
typedef struct
{
    AC_OMC_ALARM_KEY_T  stAlarmKey;

    UINT32	    		ulAlarmReasonID;				/* 告警原因编号 */	
    UINT32	    		ulAlarmLevel;					/* 告警级别 */
    
    UINT32      		ulAlarmRaiseTime;				/* 告警产生绝对时间(time()函数的返回值)，单位：秒 */
    UINT32	    		ulAlarmUptime;					/* 告警产生/清除相对（上电）时间，tick值，单位：秒 */
    UINT32	    		ulAlarmClearTime;				/* 告警清除绝对时间 */
/*2011-10-28 ldm add  */
    UINT32			ulAlarmSendTimes;			/* 告警发送次数 */
    UINT32			ulAlarmLastSendTime;			/* 告警上次发送时间 */
	
    CHAR                		acAlarmExtInfo[MAX_ALARMEXTINFO_LEN];
} AC_OMC_ALARM_INFO_T;

/* 事件主键 */
typedef struct 
{
	UINT32	            ulEventCode;				    /* 事件编号 */
    UINT32              ulMOC;                          /* 对象类型 */
    UINT8               aucMOI[16];                     /* 对象实例 */

    UINT32              ulEventRaiseTime;				/* 事件产生绝对时间(time()函数的返回值)，单位：秒 */
    UINT32              ulEventSn;                      /* 事件流水号 */
} AC_OMC_EVENT_KEY_T;

typedef struct
{
    AC_OMC_EVENT_KEY_T  stEventKey;

    UINT32	    		ulEventReasonID;				/* 事件原因编号 */
    UINT32	    		ulEventUptime;					/* 事件产生相对（上电）时间，tick值，单位：秒 */
/*2011-10-28 ldm add  */
    UINT32			ulEventSendTimes;				/* 事件重发次数*/
    UINT32			ulEventLastSendTime;				/* 事件上次发送时间 */
	
    CHAR        		acEventExtInfo[MAX_EVENTEXTINFO_LEN];
} AC_OMC_EVENT_INFO_T;

/* 告警、性能上报请求消息 */ 
typedef AC_OMC_ALARM_INFO_T     AC_OMC_REPORT_ALARM_REQ_MSG_T;
typedef AC_OMC_EVENT_INFO_T  	AC_OMC_REPORT_EVENT_REQ_MSG_T;

/* 告警、性能上报应答消息 */
typedef AC_OMC_ALARM_KEY_T		AC_OMC_REPORT_ALARM_RSP_MSG_T;
typedef AC_OMC_EVENT_KEY_T      AC_OMC_REPORT_EVENT_RSP_MSG_T;

/* 批量上报告警 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_ALARM_INFO_T astAlarmInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_ALARM_BATCH_REQ_MSG_T;

/* 批量应答告警 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_ALARM_KEY_T astAlarmKey[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_ALARM_BATCH_RSP_MSG_T;

/* 批量上报事件 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_EVENT_INFO_T astEventInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_EVENT_BATCH_REQ_MSG_T;

/* 批量应答事件 */
typedef struct
{
	UINT32  ulNum;
	AC_OMC_EVENT_KEY_T astEventKey[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_EVENT_BATCH_RSP_MSG_T;

/* WTP告警应答消息 */
typedef struct  
{
	UINT32	            ulAlarmCode;				    /* 告警编号 */
	CHAR                acAlarmObjectId[128];
    UINT32	            ulAlarmStatus;					/* 告警状态 */
    UINT32	            ulAlarmChangeTime;				/* 告警产生/清除最后发生时间（合并后时间），单位：秒 */
    UINT32     	        ulAlarmSn;                      /* 告警流水号 */   
}AC_WTP_ALARM_RSP_MSG_T;

/* WTP事件应答消息 */
typedef struct  
{
	UINT32	            ulEventCode;				    /* 事件编号 */
	CHAR                acEventObjectId[128];
    UINT32              ulEventRaiseTime;				/* 事件产生绝对时间(time()函数的返回值)，单位：秒 */
    UINT32              ulEventSn;                      /* 事件流水号 */
}AC_WTP_EVENT_RSP_MSG_T;

typedef struct 
{
    UINT32          ulNo;     /* alarm or event code */
    UINT32          ulStatus; /* 1:有效 0:无效 */
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

/* 告警扩展信息最大字符数 */
/* AP侧定义为200,待定 */
//#define MAX_ALARMEXTINFO_LEN    200
//#define MAX_EVENTEXTINFO_LEN    200

/* 告警主键 */
typedef struct
{
     unsigned long     ulAlarmCode;                      /* 告警编号 */
	 char              acAlarmObjectID[MAX_OID_LEN];     /* 告警对象OID */
     unsigned long     ulAlarmStatus;                    /* 告警状态 */
     unsigned long     ulAlarmChangeTime;                /* 告警产生/清除最后发生时间（合并后时间），单位：秒 */
     unsigned long     ulAlarmSn;                        /* 告警流水号 */
} T_alarmKey;

/* alarm trap msg */
typedef struct
{
    T_alarmKey          stAlarmKey;
    unsigned long       ulAlarmReasonID;                 /* 告警原因编号 */
    unsigned long       ulAlarmLevel;                    /* 告警级别 */
    unsigned long       ulAlarmRaiseTime;                /* 告警产生/清除绝对时间(time()函数的返回值)，单位：秒 */
    unsigned long       ulAlarmUptime;                   /* 告警产生/清除相对（上电）时间，tick值，单位：秒 */
    char                acAlarmExtInfo[200+4];
} T_alarmTrapMsg;

/* 事件主键 */
typedef struct
{
	unsigned long       ulEventCode;                     /* 事件编号 */
    char                acEventObjectID[MAX_OID_LEN];    /* 事件对象OID */
    unsigned long       ulEventRaiseTime;                /* 事件产生绝对时间(time()函数的返回值)，单位：秒 */
    unsigned long       ulEventSn;                       /* 事件流水号 */
} T_eventKey; 

typedef struct
{
    T_eventKey          stEventKey;
    unsigned long       ulEventReasonID;                 /* 事件原因编号 */
    unsigned long       ulEventUptime;                   /* 事件产生相对（上电）时间，tick值，单位：秒 */
    char                acEventExtInfo[200+4];
} T_eventTrapMsg;


/************************************ 告警过滤相关 ************************************/
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

/************************************ 函数 ************************************/
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

/* 2008/09/19 冯静 增加 */
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



