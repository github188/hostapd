/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��������ͷ�ļ�
* �޸���ʷ: 
* 2012-1-5     ���             �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_LICENSE_PROC_H
#define  _AC_LICENSE_PROC_H



/*****************************LICENSEģ����Ϣ�Ŷ���*****************************/

/******************************************************************************/


#define AC_LICENSE_TIMER_GET_STATE              TIMER27	     	/*  	�������ϱ�License��ʹ�������ʱ�� */
#define AC_LICENSE_TIMEOUT_GET_STATE			EV_TIMER27
#define AC_LICENSE_TIMER_GET_STATE_LEN			36000		/* ��λ100ms 60���� */

#define AC_LICENSE_TIMER_REPORT_STATE			TIMER26	     	/*  	�������ϱ�License��ʹ�������ʱ����ʱ */
#define AC_LICENSE_TIMEOUT_REPORT_STATE			EV_TIMER26
#define AC_LICENSE_TIMER_REPORT_STATE_LEN       30000		/* ��λ100ms 50���� */
/******************************************************************************/

#define send_port			(WORD16)(7868)      /* ���Ͷ˿ں� */
#define listen_port			(WORD16)(7868)      /* �����˿ں� */


#define AC_LICENSE_WTPMAC_BEGIN_END_NUM		(UINT32)(10)
typedef struct {
    CHAR    ucApSerialNum[LICENSE_OMC_APSERIALNUM];
    UINT32	ulMacSum;        /* ��ʾ��mac����Чmac��Ŀ  */
    UINT8 	ucApBeginMac[6];
    UINT8 	ucResv1[2];
    UINT8 	ucApEndMac[6];
    UINT8 	ucResv2[2];
} AC_LICENSE_WTPMAC_T;

/* AC��CAPWAP����license�����������ṹ�嶨��*/
typedef struct {
    /* ac function option */
    UINT32  ulWebStat;            /* web��ʾ״̬ */
    UINT32  ulWtpEnable;          /* ac�ܹ�����ap�������� 0-�� 1-�� */
    UINT32  ulMaxWtp;             /* �����������WTP����*/
    UINT32  ulStaEnable;          /* ac�ܹ�����sta�������� 0-�� 1-�� */
    UINT32  ulMaxSta;             /* �����������STA����*/
    UINT32  ulMaxAuthorTime;      /* ���ʣ����������AP��STA��ʱ�䵥λS */
    UINT32	ulTrafficMode;		  /* ��ʾ�Ƿ�֧�ּ���ת��ģʽ 0-�� 1-�� */
    UINT32	ulWtpMacEnable;		  /* ��ʾ��ac�Ƿ�֧��apmac��� 0-�� 1-��  */
    UINT32	ulWtpMacSum;		  /* ��ʾ��ac��Чmac��Ŀ  */
    UINT32	ulWtpMacNum;		  /* ��ʾ��ac��Чmac��Χ��  */
    AC_LICENSE_WTPMAC_T astWtpMac[AC_LICENSE_WTPMAC_BEGIN_END_NUM]; /* ʵ����ʼ�ͽ���mac��Χ��  */
} AC_CW_LICENSE_CTRL_T;


extern AC_CW_LICENSE_CTRL_T gstAcLicenseCtl;
extern AC_LICENSE_OMC_T gstAcLicenseOmcInfo;


/******************************************************************************/
extern UINT32	ac_license_init_scan_timer(VOID);
extern UINT32 ac_license_init_report_timer(VOID);
extern UINT32	ac_license_reinit_scan_timer(VOID);
extern UINT32 ac_license_reinit_report_timer(VOID);
extern UINT32 ac_license_reinit_report_timeout(VOID);
extern UINT32	ac_license_init_so(VOID);
extern UINT32	ac_license_proc_init(VOID);
extern UINT32    ac_license_init (VOID);
extern UINT32    ac_license_if_reg (UINT32    ulMsgId, DBIF pfFunc);
extern UINT32  ac_license_get_if_outlen(UINT32 ulMsgId, UINT32 *pulOutLen);
extern VOID ac_license_check_verify(VOID);
extern VOID ac_license_report_info(VOID);
extern VOID ac_license_report_info_timeout(VOID);
extern UINT32 ac_license_check_function(UINT32 ulFunctionId);
extern VOID ac_license_disenable(VOID);
extern VOID ac_license_disenable_wtpnum(UINT32 ulWtpNum);
extern VOID ac_license_disenable_wtp(UINT32 ulWtpId);

extern UINT32	ac_license_bk_init(VOID);
extern VOID ac_license_bk_run(VOID);
extern VOID ac_license_bk_destroy(VOID);
extern VOID ac_license_bk_msg_handle(UINT32 ulMsgId, UINT32 ulMsgLen, VOID *pvMsg);
extern UINT32	ac_license_msg_send_ip(UINT16 usEvent, CHAR *pcMsg, UINT32 usMsgLen, UINT16 usPno, UINT8 *pucIp);


#endif /* _AC_LICENSE_PROC_H */
/******************************* ͷ�ļ����� **********************************/

