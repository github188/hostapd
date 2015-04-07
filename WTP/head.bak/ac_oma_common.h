#ifndef AC_OMA_COMMON_H
#define AC_OMA_COMMON_H

/**************************** 宏定义 ***************************/
#define GET_INT(a)		(*((UINT32*)(a)))
#define SET_INT(a, b)	(*((UINT32*)(a)) = (UINT32)(b))

/* 合法标志 */
#define AC_OMA_VALID		1
#define AC_OMA_INVALID		0

/* 进程状态 */
#define AC_PROC_STATE_IDLE          (VM_PROC_STATE_IDLE)
#define AC_PROC_STATE_WORK          (VM_PROC_STATE_IDLE+1)

/* 消息队列类型 */
#define AC_OMA_QUEUE_TYPE_ALARM				((UINT32)1)
#define AC_OMA_QUEUE_TYPE_EVENT				((UINT32)2)
#define AC_OMA_QUEUE_TYPE_PERF 				((UINT32)3)

/* 增加活跃告警（未被清除的告警）消息队列 */
#define AC_OMA_QUEUE_TYPE_ACTIVEALARM       ((UINT32)4)

/* 增加采样性能数据统计消息队列 */
#define AC_OMA_QUEUE_TYPE_STAT              ((UINT32)5)

/* 每次扫描消息队列时发送的消息上限 */
#define AC_OMA_MAX_ALARM_SEND_RATE          ((UINT32)16)
#define AC_OMA_MAX_EVENT_SEND_RATE          ((UINT32)16)
#define AC_OMA_MAX_PERF_SEND_RATE           ((UINT32)24)

/* 2010-12-4 pyy 按照大容量修改*/
#if 0
/* 消息队列容量 */
#define AC_OMA_ALARM_QUEUE_NUM              ((UINT32)1024)
#define AC_OMA_EVENT_QUEUE_NUM              ((UINT32)1024)
#define AC_OMA_PERF_QUEUE_NUM               ((UINT32)2048)

/* 增加活跃告警消息队列容量 */
#define AC_OMA_ACTIVEALARM_QUEUE_NUM        ((UINT32)1024)
#else
/* 消息队列容量 */
#define AC_OMA_ALARM_QUEUE_NUM              ((UINT32)AC_DB_WTP_NUM_MAX*2)
#define AC_OMA_EVENT_QUEUE_NUM              ((UINT32)AC_DB_WTP_NUM_MAX*2)
#define AC_OMA_PERF_QUEUE_NUM               ((UINT32)AC_DB_WTP_NUM_MAX*4)

/* 增加活跃告警消息队列容量 */
#define AC_OMA_ACTIVEALARM_QUEUE_NUM        ((UINT32)AC_DB_WTP_NUM_MAX*2)

#endif

/* 增加统计队列容量 */
#define AC_OMA_STAT_QUEUE_NUM                AC_DB_WTP_NUM_MAX


/* 2010-12-4 pyy 扫描周期改成60秒 */
#ifdef BIG_AC
/* 扫描消息队列周期(单位:秒) */
#define AC_OMA_SCAN_QUEUE_PERIOD            ((UINT32)60)
#else
/* 扫描消息队列周期(单位:秒) */
#define AC_OMA_SCAN_QUEUE_PERIOD            ((UINT32)1)
#endif


/* 扫描消息队列时，连续发送若干消息失败后，中止本次扫描 */
#define AC_OMA_MAX_SEND_FAIL_NUM            ((UINT32)3)

/* 消息队列中消息超时重发时间间隔(单位:秒) */
#define AC_OMA_QUEUE_MSG_RESEND_PERIOD      ((UINT32)120)

/* 发送网元重启最大限制时间(单位:秒) */
#define AC_OMA_NESTART_TIMEOUT              ((UINT32)600)

/* 系统命令最大长度 */
#define MAX_COMMAND_LEN         (1024-1)

/* 告警、事件扩展信息连接符 */
#define AC_OMA_EXTINFO_SPLIT            '&'

/* OMA函数返回值 */
#define AC_OMA_NO_PERFREPORT        ((AC_RET)10000)   /* 不需要性能上报 */
#define AC_OMA_QUEUE_NODE_NOT_EXIST ((AC_RET)10001)   /* 队列节点不存在 */

/* 定时器 */
#define TIMER_AC_OMA_SCAN_QUEUE                 (TIMER0)
#define EV_AC_OMA_SCAN_QUEUE_TIMER_MSG          (EV_TIMER0)

#define TIMER_AC_OMA_PERF_REPORT                (TIMER1)
#define EV_AC_OMA_PERF_REPORT_TIMER_MSG         (EV_TIMER1)

/* 增加AC定时获取WTP版本信息的定时器  */
#define TIMER_AC_OMA_WTPINFO_GET                (TIMER2)
#define EV_AC_OMA_WTPINFO_GET_TIMER_MSG         (EV_TIMER2)

/* 增加AC定时上报网元版本信息的定时器 */
#define TIMER_AC_OMA_NEINFO_REPORT              (TIMER3)
#define EV_AC_OMA_NEINFO_REPORT_TIMER_MSG       (EV_TIMER3)

/* 增加AC定时重启的定时器 */
#define TIMER_AC_OMA_RELAY_RESET                (TIMER4)
#define EV_AC_OMA_RELAY_RESET_TIMER_MSG         (EV_TIMER4)

/* 2010/05/18 fengjing 增加AC定时检查活跃告警是否需要重发的定时器 */
#define TIMER_AC_OMA_ACTIVEALARM_RESEND         (TIMER5)
#define EV_AC_OMA_ACTIVEALARM_RESEND_TIMER_MSG  (EV_TIMER5)

/* 2010/05/33 fengjing 增加AC定时上报AP网元统计信息到Agent */
#define TIMER_AC_OMA_STAT_REPORT                (TIMER6)
#define EV_AC_OMA_STAT_REPORT_TIMER_MSG         (EV_TIMER6)

/**************************** 结构定义 ***************************/
typedef struct
{
    BOOL        bInitAlarmReportQueue;  /* 初始化告警上报消息队列 */

    /* add active alarm queue definition */
    BOOL        bInitActiveAlarmCacheQueue; /* 初始化活跃告警缓存消息队列 */

    BOOL        bInitEventReportQueue;  /* 初始化事件上报消息队列 */
    BOOL        bInitPerfReportQueue;   /* 初始化性能上报消息队列 */
    BOOL        bInitQueueScanTimer;    /* 初始化队列扫描定时器 */
	BOOL        bInitPerfReportTimer;   /* 初始化获取性能统计数据的定时器 */

	/* 2010/05/07 fengjing add */
	BOOL        bInitStatReportQueue;   /* 初始化性能统计数据的定时器 */

	/* 2010/05/18 fengjing 增加定时检查活跃告警是否需要重发的定时器 */
	BOOL        bInitActiveAlarmResendTimer;

	/* 2020/05/23 fengjing 增加定时检查是否需要上报性能统计信息到Agent */
	BOOL        bInitStatReportTimer;
	
    /* 增加：初始化获取WTP信息的定时器 */
    //BOOL        bInitWtpInfoGetTimer;

    /* 增加：初始化上报网元信息的定时器 */
    BOOL        bInitNeInfoReportTimer;

    /* 增加：初始化网元信息 */
    BOOL        bInitNeInfoCheck;

	/* 增加：初始化软件版本库信息 */
	BOOL        bInitSwVerLib;
}AC_OMA_INIT_STATE_T;

/**************************** 函数声明 ***************************/
extern AC_RET ac_oma_init(VOID);

extern AC_RET ac_oma_init_queue_scan_timer(VOID);

extern AC_RET ac_oma_scan_queue_timer_msg(VOID);

extern AC_RET ac_oma_reinit_queue_scan_timer(VOID);

extern AC_RET ac_oma_update_perf_counter_group_info(VOID);

extern AC_RET ac_oma_init_perf_report_timer(VOID);
extern AC_RET ac_oma_reinit_perf_report_timer(VOID);

/* 2010/05/18 fengjing 增加 设置定时检查活跃告警是否需要重发的任务 */
extern AC_RET ac_oma_init_activealarm_resend_timer(VOID);
extern AC_RET ac_oma_reinit_activealarm_resend_timer(VOID);
extern AC_RET ac_oma_activealarm_resend_timer_msg(VOID);

/* 2010/05/22 fengjing 增加邋定时上报AP动态信息到Agent侧 */
extern AC_RET ac_oma_init_stat_report_timer(VOID);
extern AC_RET ac_oma_reinit_stat_report_timer(VOID);
extern AC_RET ac_oma_stat_report_timer_msg(VOID);

extern AC_RET ac_oma_perf_report_timer_msg(VOID);

/* 增加初始化获取WTP信息的定时器、增加初始化上报网元信息的定时器 */
extern AC_RET ac_oma_init_wtpinfo_get_timer(VOID);
extern AC_RET ac_oma_init_neinfo_report_timer(VOID);

extern AC_RET ac_oma_reinit_wtpinfo_get_timer(VOID);
extern AC_RET ac_oma_reinit_neinfo_report_timer(VOID);

extern VOID ac_get_text_ip(UINT8 *pucIP, CHAR *szIP);
extern VOID ac_get_text_mac(UINT8 *pucMAC, CHAR *szMAC);

extern AC_RET ac_oma_send_wtp_reboot_rsp_msg(AC_OMC_NESTART_T *pstNeStart);
extern AC_RET ac_omc_report_reboot_rsp_msg(VOID* req, UINT32 len);

extern AC_RET ac_omc_admin_log_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_update_perf_counter_group_info(VOID);

#endif /* AC_OMA_COMMON_H */



