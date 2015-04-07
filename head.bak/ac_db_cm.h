/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��������ͷ�ļ�
* �޸���ʷ:
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_DB_CM_H
#define  _AC_DB_CM_H

/* ��ʱ��ID���� */
#define AC_DB_TIMER_WAIT_CFG_DOWNLOAD_REQ		TIMER0	     /* �ȴ�����cfg download req��ʱ�� */
#define AC_DB_TIMER_WAIT_COMMIT_REQ        			TIMER1       /* �ȴ�����commit req��ʱ�� */
#define AC_DB_TIMER_WAIT_CW_CFG_RSP        			TIMER2       /* �ȴ�CAPWAP���ø�����Ӧ��ʱ��*/
#define AC_DB_TIMER_CFG_VERSION_IND				TIMER11		 /* �������ϱ��������ݰ汾�Ŷ�ʱ��*/
#define AC_DB_TIMER_OMCHEARTBEAT					TIMER12		/* ��OMC֮�����������*/


/* ��ʱ����ʱ��Ϣ����*/
#define AC_DB_TIMEOUT_WAIT_CFG_DOWNLOAD_REQ		EV_TIMER0
#define AC_DB_TIMEOUT_WAIT_COMMIT_REQ     			EV_TIMER1
#define AC_DB_TIMEOUT_WAIT_CW_CFG_RSP    				EV_TIMER2
#define AC_DB_TIMEOUT_CFG_VERSION_IND				EV_TIMER11
#define AC_DB_TIMEOUT_OMCHEARTBEAT					EV_TIMER12

/* ��ʱ��ʱ������*/
#define AC_DB_TIMER_WAIT_CFG_DOWNLOAD_REQ_LEN		100		/* ��λ100ms */
#define AC_DB_TIMER_WAIT_COMMIT_REQ_LEN             		600     	/* ��λ100ms */
#define AC_DB_TIMER_WAIT_CW_CFG_RSP_LEN             		1200    	/* ��λ100ms */
#define AC_DB_TIMER_CFG_VERSION_IND_LEN				600		/* ��λ100ms */	/* 2010-3-26 pyy �ϱ�����10s->60s */
#define AC_DB_TIMER_OMCHEARTBEAT_LEN					100		/* ��λ100ms */

/*  ������������ */
#define AC_DB_INC_OPR_INSERT    	'I'    		/* insert */
#define AC_DB_INC_OPR_UPDATE    	'U'    	/* update */
#define AC_DB_INC_OPR_DELETE    	'D'    	/* delete */

/* MSG ID���壬������֮�����Ϣ�ӿ� */
#define AC_DB_CFG_REQ_MSG           					(EV_DB_BEGIN+1)     	/* �����޸�����*/
#define AC_DB_CFG_RSP_MSG           					(EV_DB_BEGIN+2)     	/* �����޸� ��Ӧ*/
#define AC_DB_CFG_DOWNLOAD_REQ_MSG				(EV_DB_BEGIN+3)		/* ������������*/
#define AC_DB_CFG_DOWNLOAD_RSP_MSG				(EV_DB_BEGIN+4)		/* ����������Ӧ*/
#define AC_DB_COMMIT_REQ_MSG        				(EV_DB_BEGIN+5)    	/* �����ύ����*/
#define AC_DB_COMMIT_RSP_MSG        				(EV_DB_BEGIN+6)    	/* �����޸���Ӧ*/
#define AC_DB_ROLLBACK_REQ_MSG      				(EV_DB_BEGIN+7)    	/* ���ûع�����*/
#define AC_DB_DYNREPORT_REQ_MSG					(EV_DB_BEGIN+8)		/* �����ϱ���̬��������, ��OMC����*/
#define AC_DB_AC_RESET_REQ_MSG					(EV_DB_BEGIN+9)		/* AC��������, ��OMC����*/
#define AC_DB_AC_RESET_RSP_MSG					(EV_DB_BEGIN+10)		/* AC����Ӧ��, ����OMC */

#define AC_DB_CFG_VERSION_IND_MSG				(EV_DB_BEGIN+11)		/* �������ݰ汾��֪ͨ��Ϣ*/

/* 2008-12-1 pyy add start */
#define AC_DB_PRDDYN_STATE_REPORT_MSG   			(EV_DB_BEGIN+12)  	/* ������״̬��Ϣ�ϱ���Ϣ */
#define AC_DB_PRDDYN_USERINFO_REPORT_MSG  		(EV_DB_BEGIN+13)  	/* �������û���Ϣ�ϱ���Ϣ */
/* 2008-12-1 pyy add end */

/* OMC-AC�ָ�����������Ϣ*/
/* �ָ�ACȱʡ���� */
#define AC_DB_AC_RESET_DEFAULT_CFG_REQ_MSG  	(EV_DB_BEGIN+15)
#define AC_DB_AC_RESET_DEFAULT_CFG_RSP_MSG  		(EV_DB_BEGIN+16)

/* �ָ�APȱʡ���� */
#define AC_DB_AP_RESET_DEFAULT_CFG_REQ_MSG  	(EV_DB_BEGIN+17)
#define AC_DB_AP_RESET_DEFAULT_CFG_RSP_MSG  		(EV_DB_BEGIN+18)

/* AP�����ļ�����*/
#define AC_DB_AP_CFGUPDATE_REQ_MSG 				(EV_DB_BEGIN+19)
#define AC_DB_AP_CFGUPDATE_RSP_MSG 				(EV_DB_BEGIN+20)

/* ��CAPWAP֮�����Ϣ�ӿ�*/
#define AC_DB_CFG_UPDATE_REQ_MSG    				(EV_DB_BEGIN+21)    	/* CM��CAPWAP�������ø�������*/
#define AC_DB_CFG_UPDATE_RSP_MSG   				(EV_DB_BEGIN+22)    	/* CAPWAP���������ݷַ�����WTP����CM�������ø�����Ӧ */
#define AC_DB_ACRESET_IND_MSG						(EV_DB_BEGIN+23)		/* AC����ָʾ��Ϣ*/

/* OMC�����ȡָ��AP�����ж�̬��Ϣ*/
#define AC_DB_AP_DYNAINFO_REPORT_REQ_MSG   		(EV_DB_BEGIN+24)   	/* 2010-6-28 pyy �޸�: �ظ� �޸�Ϊ10024 */
#define AC_DB_APCFG_REFRESH_REQ_MSG				(EV_DB_BEGIN+25)		/* 2010-6-28 pyy ����: ˢ��AP����, �ֶ�ǿ���·�AP������*/
#define AC_DB_APCFG_REFRESH_RSP_MSG				(EV_DB_BEGIN+26)	

/* 2010/05/26 fengjing add */
/* AP�����ļ����� */
#define AC_DB_AP_CFGBACKUP_REQ_MSG               (EV_DB_BEGIN+27)
#define AC_DB_AP_CFGBACKUP_RSP_MSG               (EV_DB_BEGIN+28)

/* 2009-10-27 fengjing add begin */
#define AC_DB_PRDDYN_DYNPOWER_REPORT_MSG          	(EV_DB_BEGIN + 30)     /*�������ϱ�����AP�Ŀ���ǰ���� */
#define AC_DB_PRDDYN_MAXPOWER_REPORT_MSG          	(EV_DB_BEGIN + 31)     /* �������ϱ�����AP�Ŀ������ */
#define AC_DB_PRDDYN_VAPMAC_REPORT_MSG               	(EV_DB_BEGIN + 32)     /* �������ϱ�����AP��VAP MAC */
#define AC_DB_PRDDYN_ADHOCMAC_REPORT_MSG          	(EV_DB_BEGIN + 33)     /* �������ϱ�����AP��ADHOC MAC */
#define AC_DB_PRDDYN_APDYNIP_REPORT_MSG             		(EV_DB_BEGIN + 34)     /* �������ϱ�����AP��IP���� */
#define AC_DB_PRDDYN_APDYNSN_REPORT_MSG            		(EV_DB_BEGIN + 35)     /* �������ϱ�����AP��SN */
#define AC_DB_PRDDYN_APDYNSWVER_REPORT_MSG      		(EV_DB_BEGIN + 36)    /* �������ϱ�����AP�ĵ�ǰ����汾 */
/* 2009-10-27 fengjing add end */

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
/* ̽���ȡ��ϵ�����Ͷ�Ӧ������ */
#define AC_PROBE_GETTABLES_REQ_MSG      (UINT16)(EV_DB_BEGIN + 101)
#define AC_PROBE_GETTABLES_RSP_MSG      (UINT16)(EV_DB_BEGIN + 101)
/* ̽���ȡѡ��Ĺ�ϵ���������ݺͶ�Ӧ������ */
#define AC_PROBE_GETTUPLES_REQ_MSG      (UINT16)(EV_DB_BEGIN + 102)
#define AC_PROBE_GETTUPLES_RSP_MSG      (UINT16)(EV_DB_BEGIN + 102)
/* ̽���޸�ǰ̨�������� */
#define AC_PROBE_ACCESSRECORD_REQ_MSG   (UINT16)(EV_DB_BEGIN + 103)
#define AC_PROBE_ACCESSRECORD_RSP_MSG   (UINT16)(EV_DB_BEGIN + 103)
/* ʵ��̽�뷢��Ĵ��̹��� */
#define AC_PROBE_SAVEDATA_REQ_MSG       (UINT16)(EV_DB_BEGIN + 104)
#define AC_PROBE_SAVEDATA_RSP_MSG       (UINT16)(EV_DB_BEGIN + 104)
/* ��������Ӧ����� */
#define AC_PROBE_NOTIFY_REQ_MSG         (UINT16)(EV_DB_BEGIN + 105)
#define AC_PROBE_NOTIFY_RSP_MSG         (UINT16)(EV_DB_BEGIN + 105)
/* ���ر��������ļ� */
#define AC_PROBE_LOADDATA_REQ_MSG       (UINT16)(EV_DB_BEGIN + 106)
#define AC_PROBE_LOADDATA_RSP_MSG       (UINT16)(EV_DB_BEGIN + 106)
/* ���ݹؼ��ּ�������¼���� */
#define AC_PROBE_GETINDEX_REQ_MSG       (UINT16)(EV_DB_BEGIN + 107)
#define AC_PROBE_GETINDEX_RSP_MSG       (UINT16)(EV_DB_BEGIN + 107)

/* END: Added by wubin, 2012/4/25   BUG:000 */

/*2011-01-06 ght add*/
/*�������ʧ��AP֪ͨ��Ϣ*/
#define AC_DB_DEL_UNREGWTP_IND_MSG      		(EV_DB_BEGIN + 51)  
/*ght add end*/

/* ��������*/
#define AC_DB_CFG_TYPE_WHOLE        ((UINT32)1)        /* �������� */
#define AC_DB_CFG_TYPE_INC          	((UINT32)2)        /* �������� */

/* ���ù���״̬*/
#define AC_DB_CFG_STATE_IDLE        	((UINT32)0)    /* IDLE */
#define AC_DB_CFG_STATE_WORK        ((UINT32)1)    /* WORK */
#define AC_DB_CFG_STATE_LOAD		((UINT32)2)	   /* �����ļ��Ѽ���*/
#define AC_DB_CFG_STATE_ERROR       ((UINT32)3)    /* ERROR */
#define AC_DB_CFG_STATE_LOCKED    	((UINT32)4)    /* LOCKED״̬����ʾAC���ڽ��������ݷַ�����WTP */


/* �����붨�� */
#define AC_DB_CFG_ECODE_IDLE_STATE          		((UINT32)1)    /* ���ù���ǰ����IDLE ״̬*/
#define AC_DB_CFG_ECODE_WORK_STATE          	((UINT32)2)    /* ���ù���ǰ����WORK ״̬*/
#define AC_DB_CFG_ECODE_ERROR_STATE         	((UINT32)3)    /* ���ù���ǰ����ERROR ״̬*/
#define AC_DB_CFG_ECODE_CFG_TYPE_INVALID    	((UINT32)4)    /* �������ͷǷ�*/
#define AC_DB_CFG_ECODE_TSEQNUM_INVALID     	((UINT32)5)    /* ����Ų�һ��*/
#define AC_DB_CFG_ECODE_FTP_FAIL            		((UINT32)6)    /* FTP ����ʧ��*/
#define AC_DB_CFG_ECODE_LOADFILE_FAIL       	((UINT32)7)    /* �����ļ�����ʧ��*/
/* 2008-10-21 pyy add start */
#define AC_DB_CFG_ECODE_LOCKED_STATE       	((UINT32)8)    /* ���ù���ǰ����LOCKED״̬����AC������AP������������ͬ��*/
/* 2008-10-21 pyy add end */
/* 2010-1-21 ����*/
#define AC_DB_CFG_ECODE_INBAKAC				((UINT32)9)	/* ������ǰ�ӹ���һ̨��AC, ����������*/


#define AC_DB_CFG_INVALID_VERSION		0xFFFFFFFF
/* ���ù���������Ϣ*/
typedef struct 
{
	UINT32	ulHeartbeatPeriod;		/*��OMC֮��� ��������, ��λ:��*/
} AC_DB_CMCFG_T;


/* ���ù���������*/
typedef struct {
    UINT32    ulState;          /* ���ù���ǰ״̬ IDLE��WORK��ERROR */
    UINT32    ulTSeqNum;        /* ��ǰ�����ʶ������ʱΪ0 */
    UINT32    ulCfgType;        /* ��ǰ�������ͣ�������������� */
    UINT32	ulWCDTimerId;	/* �ȴ�cfg download req ��ʱ��ID */
    UINT32    ulWCRTimerId;     /* �ȴ�commit req��ʱ��ID */
    UINT32    ulWCCRTimerId;    /* �ȴ�capwap cfg update rsp ��ʱ��ID */
} AC_DB_CFG_DATA_T;

/* �ṹ�嶨�� */
typedef struct {
    UINT32    ulMsgId;      /* ��Ϣ���� */
    UINT32    ulSerialNo;   /* ��Ϣ��ˮ�� */
    UINT32    ulLen;        /* ��Ϣ����Ч���� */
} AC_MSG_HDR_T;

/* �����޸�����ṹ��*/
typedef struct {
    UINT32    ulTSeqNum;    /* �����, ������Ϣ�ж�Я���������, ���ڱ�ʶһ���������� */
    UINT32    ulCfgType;    /* ��������: ��������� */
} AC_DB_CFG_REQ_MSG_T;

/* �����޸���Ӧ�ṹ��*/
typedef struct {
    UINT32    ulTSeqNum;    /* ����� */
    UINT32    ulResult;    /* ��Ӧ��� */
    CHAR      acResultDesc[128];    /* ����������Ϣ */
} AC_DB_CFG_RSP_MSG_T;

/* �����޸�����ṹ��*/
typedef struct {
    UINT32    ulTSeqNum;    /* �����*/
    UINT8    aucFtpSrvIp[4];    /* FTP������IP��ַ */
    UINT32    ulFtpSrvPort;    /* FTP�������˿ں� */
    CHAR    acDirName[64];    /* ·����*/
    CHAR    acFileName[64];    /* �����ļ��� */
    CHAR    acUserName[32];    /* �û��� */
    CHAR    acPassword[32];    /* ���� */
} AC_DB_CFG_DOWNLOAD_REQ_MSG_T;

/* �����޸���Ӧ�ṹ��*/
typedef AC_DB_CFG_RSP_MSG_T AC_DB_CFG_DOWNLOAD_RSP_MSG_T;

/* �����ύ����ṹ��*/
typedef struct {
	UINT32	ulTSeqNum;	/* �����*/
} AC_DB_COMMIT_REQ_MSG_T;

/* �����ύ��Ӧ�ṹ��*/
typedef AC_DB_CFG_RSP_MSG_T AC_DB_COMMIT_RSP_MSG_T;

/* ���ûع�����ṹ��*/
typedef AC_DB_COMMIT_REQ_MSG_T AC_DB_ROLLBACK_REQ_MSG_T;

/* �������ݰ汾��֪ͨ��Ϣ�ṹ��*/
typedef struct {
	UINT32	ulAcId;			/* AC�豸ID */
	CHAR	acSwVersion[32];	/* AC ����汾*/
	UINT32	ulCfgVersion;	/* ���������ļ��汾��*/
	UINT32	ulOnlineTime;	/* �豸����ʱ��, ��λ:�� */
	UINT16  	usCfgModVer;  	/* ������Ϣģ�Ͱ汾�� */
	UINT8    	aucRsv[2];          /* ����ֽ� */
}AC_DB_CFG_VERSION_IND_MSG_T;

/* 2008-11-7 pyy add start */
/* AC����������Ϣ�ṹ��*/
typedef struct {
	UINT32    ulSeqNum;    /* �����*/
}AC_DB_AC_RESET_REQ_MSG_T;

/* AC������Ӧ��Ϣ�ṹ��*/
typedef struct {
	UINT32    ulSeqNum;    /* �����*/
	UINT32    ulResult;    	/* ��Ӧ��� */
}AC_DB_AC_RESET_RSP_MSG_T;
/* 2008-11-7 pyy add end */

#define AC_DB_CFGRESET_ECODE_WORK_STATE		((UINT32)1)	/* ��ǰ���ڽ�����������ͬ��, ������ָ�ȱʡ���ò���*/
#define AC_DB_CFGRESET_ECODE_FAIL				((UINT32)2)	/* �ָ�ȱʡ���ò���ʧ��*/
#define AC_DB_CFGRESET_ECODE_INVALIDAP		((UINT32)3)	/* ָ��AP������*/
#define AC_DB_CFGRESET_ECODE_INVALIDMODE	((UINT32)4)	/* ��Ч�Ļָ�����*/
#define AC_DB_CFGRESET_ECODE_INBAKAC			((UINT32)5)	/* ������ǰ���ӹ���һ̨��AC */

/* �ָ�ACȱʡ���� */
typedef struct  
{
	UINT32    ulSn;
}AC_DB_AC_RESET_DEFAULT_CFG_REQ_MSG_T;

typedef struct  
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AC_RESET_DEFAULT_CFG_RSP_MSG_T;

/* �ָ�APȱʡ���� */
#define AC_DB_AP_RESET_DEFAULT_MODE_TOTAL  		((UINT32)0)   	/* ȫ���ָ� */
#define AC_DB_AP_RESET_DEFAULT_MODE_PARTIAL 		((UINT32)1)   	/* ���ָֻ� */

typedef struct  
{
	UINT32	ulSn;
	UINT32	ulWtpId;
	UINT32	ulMode;	/* �ָ�ģʽ	0:ȫ���ָ� 1:���ָֻ�*/
}AC_DB_AP_RESET_DEFAULT_CFG_REQ_MSG_T;

typedef struct  
{
	UINT32    ulSn;
	UINT32    ulRet;
	CHAR      acResultDesc[128];
}AC_DB_AP_RESET_DEFAULT_CFG_RSP_MSG_T;

/* 2009-09-09 fengjing add */

#define AC_DB_CFGUPDATE_ECODE_WORK_STATE    ((UINT32)1)	/* ��ǰ���ڽ�����������ͬ��, ���������ø���*/
#define AC_DB_CFGUPDATE_ECODE_FAIL          ((UINT32)2)	/* ���ø��²���ʧ��*/
#define AC_DB_CFGUPDATE_ECODE_INVALIDAP		((UINT32)3)	/* ָ��AP������*/

/* AP�����ļ����� */

typedef struct  
{
         UINT32    ulSn;
         UINT32    ulWtpId;
         CHAR      acFileName[128];      /* �����ļ�·�� */
         UINT8     aucServerIp[4];         /* IP��ַ */
         UINT32    ulServerPort;           /* �˿� */
         CHAR      acServerUserName[32]; /* �û��� */
         CHAR      acServerPassword[32]; /* ���� */
}AC_DB_AP_CFGUPDATE_REQ_MSG_T;

 
typedef struct  
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AP_CFGUPDATE_RSP_MSG_T;

#define AC_DB_CFGBACKUP_ECODE_WORK_STATE    ((UINT32)1)	/* ��ǰ���ڽ�����������ͬ��, ���������ñ���*/
#define AC_DB_CFGBACKUP_ECODE_FAIL          ((UINT32)2)	/* ���ñ���ʧ��*/
#define AC_DB_CFGBACKUP_ECODE_INVALIDAP		((UINT32)3)	/* ָ��AP������*/
/* 2010/05/26 fengjing add */
typedef struct
{
         UINT32    ulSn;
         UINT32    ulWtpId;
         CHAR      acFileName[128];      /* �����ļ�·�� */
         UINT8     aucServerIp[4];         /* IP��ַ */
         UINT32    ulServerPort;           /* �˿� */
         CHAR      acServerUserName[32]; /* �û��� */
         CHAR      acServerPassword[32]; /* ���� */
}AC_DB_AP_CFGBACKUP_REQ_MSG_T;

typedef struct
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AP_CFGBACKUP_RSP_MSG_T;

/* 2009-09-09 fengjing end */

/* OMC����AC�ϱ�ָ��AP�����ж�̬����*/
typedef struct  
{
	UINT32	ulWtpId;
}AC_DB_AP_DYNAINFO_REPORT_REQ_MSG_T;

/* 2010-6-28 pyy ����: ˢ��AP����, �ֶ�ǿ��AC �·�AP������*/
typedef struct
{
	UINT32	ulSn;
	UINT32	ulWtpIdStart;
	UINT32	ulWtpIdEnd;
} AC_DB_APCFG_REFRESH_REQ_MSG_T;

typedef struct
{
	UINT32    ulSn;	
	UINT32    ulRet;	/* 0: ��ʾ�ɹ�*/
} AC_DB_APCFG_REFRESH_RSP_MSG_T;

/*�������ʧ��AP֪ͨ*/
typedef struct
{
	UINT8   	aucWtpSn[6]; 	/* AP�豸���к� */
	UINT8    	aucResv[2];		/* ����ֽ� */
} AC_DB_WTPROUGAPSN_T;
#define AC_DB_CLEAR_UNREGWTP_MAX_NUM ((UINT32)100)
typedef struct
{
	UINT32	ulNum;
	AC_DB_WTPROUGAPSN_T astWtp[AC_DB_CLEAR_UNREGWTP_MAX_NUM];
} AC_DB_CLEAR_UNREGWTP_IND_T;


extern UINT32   ac_db_cm_init (VOID);
extern UINT32 	ac_db_cm_cfg_update(UINT8 *pucMsg);
extern UINT32		ac_db_cm_cfg_init(VOID);
extern UINT32   ac_db_cm_check_msg_len(UINT32 ulMsgId, UINT32 ulMsgLen);
extern VOID     ac_db_cm_cfg_req (AC_DB_CFG_REQ_MSG_T *pstCfgReq);
extern VOID	  ac_db_cm_cfg_download_req(AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstCfgDownloadReq);
extern VOID     ac_db_cm_commit_req (AC_DB_COMMIT_REQ_MSG_T *pstCommitReq);
extern UINT32   ac_db_cm_whole_table_cfg(VOID);
extern UINT32   ac_db_cm_inc_cfg(VOID);
extern UINT32		ac_db_cm_pretrigger(VOID);
extern UINT32   ac_db_cm_trigger(VOID);
extern VOID     ac_db_cm_rollback_req (AC_DB_ROLLBACK_REQ_MSG_T *pstRollbackReq);
extern VOID     ac_db_cm_recv_cfg_update_rsp(VOID);
extern VOID 	ac_db_cm_timeout_wait_cfg_download_req (VOID);
extern VOID     ac_db_cm_timeout_wait_commit_req (VOID);
extern VOID     ac_db_cm_timeout_wait_cfg_update_rsp(VOID);

extern VOID 	ac_db_cm_report_cfg_version_ind (VOID);
extern VOID ac_db_cm_report_heartbeat(VOID);
extern VOID ac_db_cm_recv_dynreport_req (VOID);
extern VOID ac_db_cm_recv_apdynreport_req(UINT8* pucMsg);
extern VOID ac_db_cm_recv_acreset_req(AC_DB_AC_RESET_REQ_MSG_T *pstResetReq);

extern VOID	ac_db_cm_ac_reset_cfg(UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_reset_cfg(UINT8 *pucMsg);
extern VOID ac_db_cm_apcfg_refresh (UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_update_cfg(UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_backup_cfg(UINT8 *pucMsg);

extern VOID ac_db_cm_ap_add_cfg(UINT8 *pucMsg);
extern VOID ac_db_cm_ap_del_cfg(UINT8 *pucMsg);
extern UINT32   ac_db_cm_cfg_req_net_to_host (AC_DB_CFG_REQ_MSG_T *pstNetCfgReq,
                                              AC_DB_CFG_REQ_MSG_T *pstHostCfgReq);
extern UINT32	   ac_db_cm_cfg_download_req_net_to_host (AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstNetCfgDownloadReq,
						AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstHostCfgDownloadReq);
extern UINT32   ac_db_cm_commit_req_net_to_host (AC_DB_COMMIT_REQ_MSG_T *pstNetCommitReq,
                                                 AC_DB_COMMIT_REQ_MSG_T *pstHostCommitReq);
extern UINT32   ac_db_cm_rollback_req_net_to_host (AC_DB_ROLLBACK_REQ_MSG_T *pstNetRollbackReq,
                                                   AC_DB_ROLLBACK_REQ_MSG_T *pstHostRollbackReq);
extern UINT32   ac_db_cm_rsp_host_to_net (AC_DB_CFG_RSP_MSG_T *pstHostRsp,
                                          AC_DB_CFG_RSP_MSG_T *pstNetRsp);

UINT32 VmFsFtp(VM_FTP_REQ_MSG_T* pstFTPReqMsg, UINT32 ulDstPid);

extern VOID ac_db_cm_recv_inc_update_req(UINT8 *pucMsg, UINT32 ulByteOrder);
extern VOID ac_db_cm_recv_inc_batchupdate_req(UINT8 *pucMsg, UINT32 ulByteOrder);

extern UINT32 ac_db_cm_bakacid_chg(UINT8 *pucMsg);

extern VOID ac_db_cm_clear_unregwtp (UINT8 *pucMsg);

#endif /* _AC_DB_CM_H */
/******************************* ͷ�ļ����� **********************************/


