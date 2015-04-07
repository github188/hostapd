/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ���ݿ�ͳһ�ӿڹ���ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_DB_PROC_H
#define  _AC_DB_PROC_H

/* ��׼�ӿں������� */
typedef VOID (*DBIF)(UINT8*, UINT32, UINT8*, UINT32*);
typedef VOID (*DBPERF)(VOID);

/* AC�豸������Ϣ*/
typedef struct
{
	CHAR	acAcDevSN[6];			/* �豸���к�*/
	CHAR	acRsv[2];				/* ����ֽ�*/
	CHAR	acAcDevType[32];		/* �豸�ͺ�*/
	CHAR	acAcSwVersion[32];		/* �豸����汾��*/
	CHAR	acAcHwVersion[32];		/* �豸Ӳ���汾��*/
	CHAR	acAcManufacturer[128];	/* �豸������*/
	CHAR	acAcSwDeveloper[128];	/* �豸���������*/
} AC_DB_DEVICE_ACPRODUCE_T;

typedef struct
{
	UINT32   ulAcId;               		 	//AC ID
     	CHAR      acAcDevName[32];      	//AC NAME
	CHAR     acAcDevType[32];        	//�豸�ͺ�
    	CHAR     acAcDevSN[6];           		//�豸���кţ�λ�� /etc/gb
     	UINT8    aucResv1[2]; 
    	CHAR     acAcSwVersion[32];     	//�豸����汾
    	CHAR     acAcHwVersion[32];		//�豸Ӳ���汾

    	UINT8   aucFitLanIp[4];   		/* FIT-LAN IP */
	UINT8   aucFitLanMask[4];  	/* FIT-LAN MASK */
	
    	UINT8   aucFatLanIp[4];   		/* FAT-LAN IP */
	UINT8   aucFatLanMask[4];   	/* FAT-LAN MASK */

    	UINT8   aucL2WanIp[4];   		/* L2-WAN IP */
    	UINT8   aucL2WanMask[4];   	/* L2-WAN MASK */
    	
    	UINT8   aucL3WanIp[4];   		/* L3-WAN IP */
    	UINT8   aucL3WanMask[4];   	/* L3-WAN MASK */

    	UINT8    aucDefaultGw[4];			/* ȱʡ����*/
	UINT8    aucPrimaryDns[4];             /* ����DNS������*/
     	UINT8    aucSecondaryDns[4];         /* ����DNS������*/
} AC_DB_DEVICE_ABSTRACT_T;


/******************************��ʱ����غ궨��start ******************************/
/* ��ʱ��ʱ��: ��λΪ100ms*/
#define AC_DB_TIMERLEN_DYN_REPORT			100		/* �ϱ�AC�����¼���ʱ��ʱ��*/
#define AC_DB_TIMERLEN_CHECK_PAYLOAD			1800	/* �����Լ�鸺�ɶ�ʱ��ʱ��*/
/* 2008-11-8 pyy: ����ȡ�����޸�Ϊ1����*/
#define AC_DB_TIMERLEN_GET_VAPSTAT			600		/* AP�����Ի�ȡVAP����ͳ�ƶ�ʱ��ʱ��*/
#define AC_DB_TIMERLEN_CHECK_DYNEVENT_TBL	18000	/* �����Լ���¼���¼��ʱ��ʱ��*/
/* 2009-10-28 pyy ��30���޸�Ϊ1����*/
#define AC_DB_TIMERLEN_GET_ONLINEUSERSTAT	600		/* �����û���ͳ�ƶ�ʱ��ʱ��
														    AC��С���Ƚ���ͳ�ƣ� ͳ��ƽ�����ϱ���OMC */
/* pyyL 2009-6-13 �޸�Ϊ5����*/														    
#define AC_DB_TIMERLEN_PRD_DYNREPORT			3000	/* �������ϱ���̬���ݶ�ʱ��ʱ��
														   5����*/   
														   
#define AC_DB_TIMERLEN_WTPASSO_ALARM		1800	/* AP����״̬�澯��鶨ʱ�� ʱ��*/
#define AC_DB_TIMERLEN_CHECK_VLANUSER_TBL	100		/* �û�VLAN״̬������鶨ʱ��ʱ��*/
#define AC_DB_TIMERLEN_CHECK_IDSUSER_TBL		1800	/* IDS�����û����鶨ʱ��ʱ��*/

#define AC_DB_TIMERLEN_CHECK_DATSAVEFLAG		3000		/* 2011-5-19 pyy����: �����Լ����̱��λ*/

#define AC_DB_TIMER_DYN_REPORT          			TIMER1	/* �ϱ�AC�����¼���ʱ��*/
#define AC_DB_TIMER_CHECK_PAYLOAD			TIMER3	/* �����Լ�鸺�ɶ�ʱ��*/
#define AC_DB_TIMER_GET_VAPSTAT				TIMER4	/* AP�����Ի�ȡVAP����ͳ�ƶ�ʱ�� */
#define AC_DB_TIMER_CHECK_DYNEVNET_TBL		TIMER5	/* �����Լ���¼���¼��ʱ��*/
#define AC_DB_TIMER_GET_ONLINEUSERSTAT		TIMER6	/* �����û���ͳ�ƶ�ʱ�� */
#define AC_DB_TIMER_PRD_DYNREPORT			TIMER7	/* �������ϱ���̬���ݶ�ʱ��*/
#define AC_DB_TIMER_WTPASSO_ALARM			TIMER8	/* AP����״̬��鶨ʱ��*/
#define AC_DB_TIMER_CHECK_VLANUSER_TBL		TIMER9	/* �û�VLAN״̬������鶨ʱ��*/
#define AC_DB_TIMER_CHECK_IDSUSER_TBL		TIMER10	/* IDS�����û���鶨ʱ��*/
#define AC_DB_TIMER_CHECK_DATSAVEFLAG		TIMER11	/* 2011-5-19 pyy����: �����Լ����̱��λ��ʱ��*/


#define AC_DB_TIMEROUT_DYN_REPORT_MSG   			EV_TIMER1
#define AC_DB_TIMEROUT_CHECK_PAYLOAD_MSG		EV_TIMER3
#define AC_DB_TIMEROUT_GET_VAPSTAT_MSG			EV_TIMER4
#define AC_DB_TIMEROUT_CHECK_DYNEVENT_TBL_MSG	EV_TIMER5
#define AC_DB_TIMEROUT_GET_ONLINEUSERSTAT_MSG	EV_TIMER6
#define AC_DB_TIMEROUT_PRD_DYNREPORT				EV_TIMER7
#define AC_DB_TIMEROUT_WTPASSO_ALARM_MSG		EV_TIMER8
#define AC_DB_TIMEROUT_CHECK_VLANUSER_TBL_MSG	EV_TIMER9
#define AC_DB_TIMEROUT_CHECK_IDSUSER_TBL_MSG	EV_TIMER10
#define AC_DB_TIMEROUT_CHECK_DATSAVEFLAG_MSG	EV_TIMER11	/* 2011-5-19 pyy����: �����Լ����̱��λ��ʱ��*/

/* add by gwx 2012-11-1 for �û�������׼ȷ*/
#define AC_USRM_TIMER_START_USERTRAFFIC		TIMER12
#define AC_USRM_TIMER_STOP_USERTRAFFIC		TIMER13
#define	AC_USRM_TIMER_WAIT_ACCOUNT_STOPGET	TIMER14

#define AC_USRM_TIMEOUT_START_USERTRAFFIC	EV_TIMER12
#define AC_USRM_TIMEOUT_STOP_USERTRAFFIC	EV_TIMER13
#define AC_USRM_TIMEOUT_WAIT_ACCOUNT_STOPGET	EV_TIMER14
#define	AC_USRM_TIMER_USERTRAFFIC_LEN	50		/* ��λ100ms */
#define	AC_USRM_TIMER_WAIT_ACCOUNT_STOPGET_LEN	200	/* ��λ100ms */
/* ��ʱ��ID���� */
#define AC_USRM_TIMER_GET_USERTRAFFIC		TIMER21		/* ��ȡ�û�����ͳ����Ϣ�Ķ�ʱ��*/
#define AC_USRM_TIMER_CHECK_USERTRAFFIC		TIMER22		/* ����û�������ʱ��: �����ָ��ʱ�����û���������AC��Ϊ�û�����*/
#define AC_USRM_TIMER_CHECK_SESSIONTIMEOUT	TIMER23		/* ����û�session timeout ��ʱ��*/
#define AC_USRM_TIMER_CHECK_MACUSER			TIMER24
#define AC_USRM_TIMER_CHECK_USERFLOWCTRL	TIMER25		/* ���ڼ���û����ر�ʱ��*/
#define AC_USRM_TIMER_SYNAP_USERFLOWCTRL	TIMER26		/* ������APͬ���û��������ö�ʱ��*/

/* ��ʱ����ʱ��Ϣ����*/
#define AC_USRM_TIMEOUT_GET_USERTRAFFIC			EV_TIMER21
#define AC_USRM_TIMEOUT_CHECK_USERTRAFFIC		EV_TIMER22
#define AC_USRM_TIMEOUT_CHECK_SESSIONTIMEOUT	EV_TIMER23
#define AC_USRM_TIMEOUT_CHECK_MACUSER			EV_TIMER24
#define AC_USRM_TIMEOUT_CHECK_USERFLOWCTRL		EV_TIMER25
#define AC_USRM_TIMEOUT_SYNAP_USERFLOWCTRL		EV_TIMER26

/* ��ʱ��ʱ������*/
#define AC_USRM_TIMER_GET_USERTRAFFIC_LEN		300		/* ��λ100ms */
#define AC_USRM_TIMER_CHECK_USERTRAFFIC_LEN		600
#define AC_USRM_TIMER_CHECK_SESSIONTIMEOUT_LEN	600
#define AC_USRM_TIMER_CHECK_MACUSER_LEN			100

#define AC_USRM_GET_USERTRAFFIC_NUM_MAX			100
#define AC_USRM_CHECK_USERTRAFFIC_NUM_MAX		100
#define AC_USRM_CHECK_SESSIONTIMEOUT_NUM_MAX	500
#define AC_USRM_CHECK_USERFLOWCTRL_NUM_MAX		100

#define AC_USRM_CHECK_USERFLOWCTRL_LEN		600
#define AC_USRM_SYNAP_USERFLOWCTRL_LEN		3000

/* AC��⵽���û�����:�û�������ʱ����������ֵ��Ϊ�û�����*/
#define AC_USRM_NOTRAFFIC_TIMELEN_MAX			6000	/*��λ:��*/


/******************************��ʱ����غ궨��end ******************************/


/******************************����ά��������غ궨��start ******************************/
/* WTP�û������޶���*/
#define AC_WTP_USERNUM_LOW_THRESHOLD	20		/* 20% */
#define AC_WTP_USERNUM_HIGH_THRESHOLD	80		/* 80% */

/* AC CPU�������޶���*/
#define AC_CPULOAD_LOW_THRESHOLD		20		/* 20% */
#define AC_CPULOAD_HIGH_THRESHOLD	    80		/* 80% */
#define AC_CPULOAD_THRESHOLD_RANGE	    5		/* 5% */

/* AC�û������޶��� */
#define AC_AC_USERNUM_LOW_THRESHLOD		20		/* 20% */
#define AC_AC_USERNUM_HIGH_THRESHLOD	80		/* 80% */

/* �����Լ��AC�豸���û�����������5��������AC���û�������������ʱ���ϱ��澯 */
/* �����Լ��AC�豸���û�����������5��������WTP���û�������������ʱ���ϱ��澯 */
/* ĳ���������û����������ޣ���֮ǰ�����ϱ����澯�����ϱ��澯��� */
/* �����Լ��WTP�豸���û�����������5��������WTP���û�������������ʱ���ϱ��澯  */
#define AC_USERLOAD_RECORD_NUM		10
#define AC_USERLOAD_HIGH_THRESHOLD_NUM		5
#define AC_USERLOAD_LOW_THRESHOLD_NUM		5

#define AC_CPULOAD_RECORD_NUM		        	10
#define AC_CPULOAD_HIGH_THRESHOLD_NUM		5

/* �Ƿ�WTP�����¼��ϱ�Ƶ��*/
#define AC_EVENT_RPT_PRD_WTP_ACCESS_DENY	1800	/* 1800�룬��30����*/

/* add by gwx 2014-8-14 */
#ifdef BIG_AC
#define OSS_CPU_NUM             (WORD16) (1050*4)
#else
#define OSS_CPU_NUM             (WORD16) 1050
#endif




/******************************����ά��������غ궨��end ******************************/

/******************************����ά��������ؽṹ�嶨��start ******************************/

/******************************����ά��������ؽṹ�嶨��end ******************************/

/******************************����ԭ��start ******************************/
extern VOID ac_db_init_pid(VOID);
extern UINT32  ac_db_init (VOID);
extern VOID    ac_db_recv_join_succ (UINT8 *pucMsg);
extern VOID ac_db_report_dyninfo(UINT8 ucMsgType);
extern VOID ac_db_report_apdyninfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID    ac_db_report_dyn_data(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apip (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_acip (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_msinfo (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apsn (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apswver(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_vdevmaxpower(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_vapmac(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_adhocmac(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_vdevinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_vapinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_adhocinfo(UINT8 ucMsgType, UINT32 ulWtpId);

extern VOID ac_db_check_load (VOID);
extern VOID ac_db_check_dynevent_tbl(VOID);
extern VOID ac_db_report_perf (UINT8 *pucMsg);
extern VOID ac_db_recv_join_succ (UINT8 *pucMsg);
extern VOID ac_db_vapstat_init (VOID);
extern VOID ac_db_wtpdyninfo_init (VOID);
extern VOID ac_db_report_ac_reboot_event (VOID);
extern VOID ac_db_oam_init (VOID);
extern UINT32 ac_db_oam_get_acmoid (AC_OMA_MO_T *pstAcMOID);
extern VOID ac_db_oam_report_event (UINT32 ulEventId,
                                    UINT32 ulEventReasonId,
                                    UINT32 ulMOC,
                                    UINT8	aucMOI[AC_MOI_LEN],
                                    UINT32 ulCommonInfo);
extern VOID ac_db_oam_report_alarm (UINT32 ulAlarmId,
                             UINT32 ulAlarmReasonId,
                             UINT32 ulAlarmLevel,
                             UINT32 ulMOC,
                             UINT8	aucMOI[AC_MOI_LEN],
                             UINT32 ulCommonInfo);

extern VOID ac_db_get_ap_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_wtpunregister_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_user_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_acif_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_useripinfo(UINT8 *pucMsg);
extern VOID ac_db_get_ac_vapwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_vapuseraccstat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_ifwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_ssidwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_vap_portalinfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_apuserstat (UINT8 *pucRcvMsg);

extern UINT32 ac_db_make_default_cfg(UINT32 ulAcId);
extern VOID ac_db_check_datsaveflag(VOID);

/******************************����ԭ��end ******************************/

#endif /* _AC_DB_PROC_H */
/******************************* ͷ�ļ����� **********************************/



