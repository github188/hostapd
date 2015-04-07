#ifndef AC_OMA_COMMON_H
#define AC_OMA_COMMON_H

/**************************** �궨�� ***************************/
#define GET_INT(a)		(*((UINT32*)(a)))
#define SET_INT(a, b)	(*((UINT32*)(a)) = (UINT32)(b))

/* �Ϸ���־ */
#define AC_OMA_VALID		1
#define AC_OMA_INVALID		0

/* ����״̬ */
#define AC_PROC_STATE_IDLE          (VM_PROC_STATE_IDLE)
#define AC_PROC_STATE_WORK          (VM_PROC_STATE_IDLE+1)

/* ��Ϣ�������� */
#define AC_OMA_QUEUE_TYPE_ALARM				((UINT32)1)
#define AC_OMA_QUEUE_TYPE_EVENT				((UINT32)2)
#define AC_OMA_QUEUE_TYPE_PERF 				((UINT32)3)

/* ���ӻ�Ծ�澯��δ������ĸ澯����Ϣ���� */
#define AC_OMA_QUEUE_TYPE_ACTIVEALARM       ((UINT32)4)

/* ���Ӳ�����������ͳ����Ϣ���� */
#define AC_OMA_QUEUE_TYPE_STAT              ((UINT32)5)

/* ÿ��ɨ����Ϣ����ʱ���͵���Ϣ���� */
#define AC_OMA_MAX_ALARM_SEND_RATE          ((UINT32)16)
#define AC_OMA_MAX_EVENT_SEND_RATE          ((UINT32)16)
#define AC_OMA_MAX_PERF_SEND_RATE           ((UINT32)24)

/* 2010-12-4 pyy ���մ������޸�*/
#if 0
/* ��Ϣ�������� */
#define AC_OMA_ALARM_QUEUE_NUM              ((UINT32)1024)
#define AC_OMA_EVENT_QUEUE_NUM              ((UINT32)1024)
#define AC_OMA_PERF_QUEUE_NUM               ((UINT32)2048)

/* ���ӻ�Ծ�澯��Ϣ�������� */
#define AC_OMA_ACTIVEALARM_QUEUE_NUM        ((UINT32)1024)
#else
/* ��Ϣ�������� */
#define AC_OMA_ALARM_QUEUE_NUM              ((UINT32)AC_DB_WTP_NUM_MAX*2)
#define AC_OMA_EVENT_QUEUE_NUM              ((UINT32)AC_DB_WTP_NUM_MAX*2)
#define AC_OMA_PERF_QUEUE_NUM               ((UINT32)AC_DB_WTP_NUM_MAX*4)

/* ���ӻ�Ծ�澯��Ϣ�������� */
#define AC_OMA_ACTIVEALARM_QUEUE_NUM        ((UINT32)AC_DB_WTP_NUM_MAX*2)

#endif

/* ����ͳ�ƶ������� */
#define AC_OMA_STAT_QUEUE_NUM                AC_DB_WTP_NUM_MAX


/* 2010-12-4 pyy ɨ�����ڸĳ�60�� */
#ifdef BIG_AC
/* ɨ����Ϣ��������(��λ:��) */
#define AC_OMA_SCAN_QUEUE_PERIOD            ((UINT32)60)
#else
/* ɨ����Ϣ��������(��λ:��) */
#define AC_OMA_SCAN_QUEUE_PERIOD            ((UINT32)1)
#endif


/* ɨ����Ϣ����ʱ����������������Ϣʧ�ܺ���ֹ����ɨ�� */
#define AC_OMA_MAX_SEND_FAIL_NUM            ((UINT32)3)

/* ��Ϣ��������Ϣ��ʱ�ط�ʱ����(��λ:��) */
#define AC_OMA_QUEUE_MSG_RESEND_PERIOD      ((UINT32)120)

/* ������Ԫ�����������ʱ��(��λ:��) */
#define AC_OMA_NESTART_TIMEOUT              ((UINT32)600)

/* ϵͳ������󳤶� */
#define MAX_COMMAND_LEN         (1024-1)

/* �澯���¼���չ��Ϣ���ӷ� */
#define AC_OMA_EXTINFO_SPLIT            '&'

/* OMA��������ֵ */
#define AC_OMA_NO_PERFREPORT        ((AC_RET)10000)   /* ����Ҫ�����ϱ� */
#define AC_OMA_QUEUE_NODE_NOT_EXIST ((AC_RET)10001)   /* ���нڵ㲻���� */

/* ��ʱ�� */
#define TIMER_AC_OMA_SCAN_QUEUE                 (TIMER0)
#define EV_AC_OMA_SCAN_QUEUE_TIMER_MSG          (EV_TIMER0)

#define TIMER_AC_OMA_PERF_REPORT                (TIMER1)
#define EV_AC_OMA_PERF_REPORT_TIMER_MSG         (EV_TIMER1)

/* ����AC��ʱ��ȡWTP�汾��Ϣ�Ķ�ʱ��  */
#define TIMER_AC_OMA_WTPINFO_GET                (TIMER2)
#define EV_AC_OMA_WTPINFO_GET_TIMER_MSG         (EV_TIMER2)

/* ����AC��ʱ�ϱ���Ԫ�汾��Ϣ�Ķ�ʱ�� */
#define TIMER_AC_OMA_NEINFO_REPORT              (TIMER3)
#define EV_AC_OMA_NEINFO_REPORT_TIMER_MSG       (EV_TIMER3)

/* ����AC��ʱ�����Ķ�ʱ�� */
#define TIMER_AC_OMA_RELAY_RESET                (TIMER4)
#define EV_AC_OMA_RELAY_RESET_TIMER_MSG         (EV_TIMER4)

/* 2010/05/18 fengjing ����AC��ʱ����Ծ�澯�Ƿ���Ҫ�ط��Ķ�ʱ�� */
#define TIMER_AC_OMA_ACTIVEALARM_RESEND         (TIMER5)
#define EV_AC_OMA_ACTIVEALARM_RESEND_TIMER_MSG  (EV_TIMER5)

/* 2010/05/33 fengjing ����AC��ʱ�ϱ�AP��Ԫͳ����Ϣ��Agent */
#define TIMER_AC_OMA_STAT_REPORT                (TIMER6)
#define EV_AC_OMA_STAT_REPORT_TIMER_MSG         (EV_TIMER6)

/**************************** �ṹ���� ***************************/
typedef struct
{
    BOOL        bInitAlarmReportQueue;  /* ��ʼ���澯�ϱ���Ϣ���� */

    /* add active alarm queue definition */
    BOOL        bInitActiveAlarmCacheQueue; /* ��ʼ����Ծ�澯������Ϣ���� */

    BOOL        bInitEventReportQueue;  /* ��ʼ���¼��ϱ���Ϣ���� */
    BOOL        bInitPerfReportQueue;   /* ��ʼ�������ϱ���Ϣ���� */
    BOOL        bInitQueueScanTimer;    /* ��ʼ������ɨ�趨ʱ�� */
	BOOL        bInitPerfReportTimer;   /* ��ʼ����ȡ����ͳ�����ݵĶ�ʱ�� */

	/* 2010/05/07 fengjing add */
	BOOL        bInitStatReportQueue;   /* ��ʼ������ͳ�����ݵĶ�ʱ�� */

	/* 2010/05/18 fengjing ���Ӷ�ʱ����Ծ�澯�Ƿ���Ҫ�ط��Ķ�ʱ�� */
	BOOL        bInitActiveAlarmResendTimer;

	/* 2020/05/23 fengjing ���Ӷ�ʱ����Ƿ���Ҫ�ϱ�����ͳ����Ϣ��Agent */
	BOOL        bInitStatReportTimer;
	
    /* ���ӣ���ʼ����ȡWTP��Ϣ�Ķ�ʱ�� */
    //BOOL        bInitWtpInfoGetTimer;

    /* ���ӣ���ʼ���ϱ���Ԫ��Ϣ�Ķ�ʱ�� */
    BOOL        bInitNeInfoReportTimer;

    /* ���ӣ���ʼ����Ԫ��Ϣ */
    BOOL        bInitNeInfoCheck;

	/* ���ӣ���ʼ������汾����Ϣ */
	BOOL        bInitSwVerLib;
}AC_OMA_INIT_STATE_T;

/**************************** �������� ***************************/
extern AC_RET ac_oma_init(VOID);

extern AC_RET ac_oma_init_queue_scan_timer(VOID);

extern AC_RET ac_oma_scan_queue_timer_msg(VOID);

extern AC_RET ac_oma_reinit_queue_scan_timer(VOID);

extern AC_RET ac_oma_update_perf_counter_group_info(VOID);

extern AC_RET ac_oma_init_perf_report_timer(VOID);
extern AC_RET ac_oma_reinit_perf_report_timer(VOID);

/* 2010/05/18 fengjing ���� ���ö�ʱ����Ծ�澯�Ƿ���Ҫ�ط������� */
extern AC_RET ac_oma_init_activealarm_resend_timer(VOID);
extern AC_RET ac_oma_reinit_activealarm_resend_timer(VOID);
extern AC_RET ac_oma_activealarm_resend_timer_msg(VOID);

/* 2010/05/22 fengjing �����嶨ʱ�ϱ�AP��̬��Ϣ��Agent�� */
extern AC_RET ac_oma_init_stat_report_timer(VOID);
extern AC_RET ac_oma_reinit_stat_report_timer(VOID);
extern AC_RET ac_oma_stat_report_timer_msg(VOID);

extern AC_RET ac_oma_perf_report_timer_msg(VOID);

/* ���ӳ�ʼ����ȡWTP��Ϣ�Ķ�ʱ�������ӳ�ʼ���ϱ���Ԫ��Ϣ�Ķ�ʱ�� */
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



