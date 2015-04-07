#ifndef AC_OMA_CONFIG_H
#define AC_OMA_CONFIG_H

/************************************************************************/
/*                                                                      */
/************************************************************************/
#define AC_OMA_DELAY_TYPE_GET_SYNC    ((UINT32)1)
#define AC_OMA_DELAY_TYPE_SET_SYNC    ((UINT32)2)
#define AC_OMA_DELAY_TYPE_GET_ASYNC   ((UINT32)3)

#define AC_OMA_WTP_MAXNUM        ((UINT32)100)

#define AC_OMA_AC_TBLNAME_BASICSETUP   "acBasicSetup"

/* 2010-08-29 fengjing add */
#define AC_OMA_AC_TBLNAME_STADHCPDYNAMICSETUP "acStaDhcpDynamicIpAddrSetup"
#define AC_OMA_AC_TBLNAME_APDHCPDYNAMICSETUP  "acApDhcpDynamicIpAddrSetup"

#define AC_OMA_WTP_TBLNAME_BASICSETUP  "sysBasicSetup"
#define AC_OMA_WTP_TBLNAME_IPSETUP     "sysIpSetup"

/* 2010-08-27 fengjing add */
#define AC_OMA_WTP_TBLNAME_APBASICSETUP "apBasicSetup"

#define AC_OMA_AC_TBLNAME_ALARMINFO    "acAlarmFilterSetup"
#define AC_OMA_AC_TBLNAME_PERFINFO     "acPerfCounterGroupInfoSetup"
#define AC_OMA_WTP_TBLNAME_ALARMINFO   "apAlarmFilterSetup"
#define AC_OMA_WTP_TBLNAME_PERFINFO    "perfCounterGroupInfoSetup"

/* 2010/05/18 fengjing add */
#define AC_OMA_AC_TBLNAME_ALARMTHRESHOLD "acAlarmThresholdSetup"

#define AC_OMA_WTP_DEFAULT_COMMUNITY   "www.gbcom.com.cn"

#define AC_OMA_COMMANDRELAY_FROM_OMC   ((UINT32)1)
#define AC_OMA_COMMANDRELAY_FROM_WEB   ((UINT32)2)

#define AC_OMA_COMMANDRELAY_TYPE_OTHER     ((UINT32)0)
#define AC_OMA_COMMANDRELAY_TYPE_CFGCHANGE ((UINT32)10)
#define AC_OMA_COMMANDRELAY_TYPE_SWUPGRADE ((UINT32)11)

#define AC_OMA_GET_NECFGVERSION_ERRCODE_OK                 ((UINT32)0)
#define AC_OMA_GET_NECFGVERSION_ERRCODE_GETVERSIONFAIL     ((UINT32)1)
#define AC_OMA_GET_NECFGVERSION_ERRCODE_GETACBASICRECFAIL  ((UINT32)2)
#define AC_OMA_GET_NECFGVERSION_ERRCODE_GETAPBASICRECFAIL  ((UINT32)3)

/************************************************************************/
/*                                                                      */
/************************************************************************/
typedef struct
{
    UINT8      aucWtpIpAddr[4];
    UINT32     ulWtpId;
    CHAR       acWtpSwVersion[32];
    UINT32     ulWtpDeviceType;
    UINT32     ulWtpCfgDataVersion;
    UINT32     ulCheckWtpId;
    CHAR       acCheckWtpSwVersion[32];
    UINT32     ulCheckWtpDeviceType;
    UINT32     ulCheckWtpCfgDataVersion;
    /* ���ܻ���������Ϣ������Ԫ����ʱ�䡢��Ԫ�¶ȵȶ�̬��Ϣ */
}AC_OMA_WTP_INFO_T;

typedef struct wtpIndex
{
    UINT32              ulWtpId;
    UINT8               aucWtpIpAddr[4];
    UINT8               ulIndex;
    struct wtpIndex     *pstIdHashNext;
    struct wtpIndex     *pstIpHashNext;
}AC_OMA_WTP_INDEX_T;

typedef struct 
{
    UINT32             ulAcId;
    CHAR               acSwVersion[32];     /* AC��Ԫ����汾 */
    UINT32             ulAcCfgDataVersion;  /* AC�������ݰ汾 */
    UINT32             ulWtpNum;            /* WTP��Ԫ��Ŀ */
    AC_OMA_WTP_INFO_T  astWtpInfo[AC_OMA_WTP_MAXNUM];
    AC_OMA_WTP_INDEX_T astWtpIndex[AC_OMA_WTP_MAXNUM];
    AC_OMA_WTP_INDEX_T *apstIdIndex[AC_OMA_WTP_MAXNUM];
    AC_OMA_WTP_INDEX_T *apstIpIndex[AC_OMA_WTP_MAXNUM];
}AC_OMC_NE_INFO_T;

typedef struct 
{
    UINT32              ulCheckWtpDeviceType;     /* �豸���� */
	CHAR                acCheckImVersion[16];     /* ��Ϣģ�Ͱ汾 */
    UINT32              ulCheckWtpCfgDataVersion; /* �������ݰ汾 */
	CHAR                acCheckAlarmVersion[16];  /* �澯��Ϣģ�Ͱ汾 */
	CHAR                acCheckPerfVersion[16];   /* ������Ϣģ�Ͱ汾 */
    UINT32              ulCheckWtpId;             /* ��ԪID */
    CHAR                acCheckWtpSwVersion[32];  /* ��Ԫ����汾 */
	UINT32              aulReserved[4];
}AC_OMA_WTP_NEINFO_RSP_MSG_T;

/* 2009-09-03 fengjing add */
typedef struct
{	
	UINT32                      ulStartTime; /* ��1970-01-01 00:00:00������ */
}T_startTrapMsg;

typedef struct 
{
    UINT32  ulNeId;                   /* ����0 */
    CHAR    acImVersion[32];   /* ��Ϣģ�Ͱ汾 */
    CHAR    acSwVersion[32];  /* ����汾 */
    UINT32  ulDeviceType;      /* �豸���� */
    UINT32  ulWtpId;                /* ��ԪID */
    UINT32  ulCfgVersion;      /* �������ݰ汾�� */
	UINT32 ulSysTime;        /* ϵͳʱ�� */
       UINT32 ulUpTime;         /* �豸����ʱ�� */
	UINT32 ulConnTime;      /* AP��AC�����ϵ�ʱ�� */
}T_versionTrapMsg;

/************************************************************************/
/* ��������                                                             */
/************************************************************************/
extern AC_RET ac_oma_config_init_ne_info_check(VOID);

extern AC_RET ac_oma_config_calculate_id_hash_key(UINT32 ulId, UINT32 ulTblSize, UINT32 *pulHashKey);
extern AC_RET ac_oma_config_calculate_ip_hash_key(UINT8 *pucIpAddr, UINT32 ulIpAddrLen, UINT32 ulTblSize, UINT32 *pulHashKey);

extern AC_RET ac_oma_config_report_neinfo_ind_msg(VOID);

extern AC_RET ac_oma_wtpinfo_get_timer_msg(VOID);
extern AC_RET ac_oma_neinfo_report_timer_msg(VOID);

extern AC_RET ac_db_wtp_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);
extern AC_RET ac_db_alarm_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);
extern AC_RET ac_db_perf_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);
/* 2010/05/18 fengjing add */
extern AC_RET ac_db_alarmthreshold_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);
extern AC_RET ac_oma_config_init_alarmthreshold_setting(VOID);

extern AC_RET ac_oma_config_init_perf_setting(VOID);

extern AC_RET ac_oma_convert_ip_str2array(CHAR *ip, UINT8 *pucIp);

/* ����ͨ��WTP ID��ѯWTP�豸IP��ַ */
extern AC_RET ac_oma_get_ipaddr_by_wtpid(UINT32 ulWtpId, UINT8 *aucWtpIpAddr);

/* OMC/WEB����λ */
extern AC_RET ac_oma_reset_req_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);

extern AC_RET ac_oma_notify_wtp_cfgchange(UINT32 ulWtpId);
extern AC_RET ac_oma_notify_wtp_swupgrade(UINT32 ulWtpId);

/* OMC/WEB�����ȡ������Ԫ���������ݰ汾����Ϣ */
extern AC_RET ac_omc_get_necfgversion_req_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);

/* 2009-08-21 fengjing add begin */
extern AC_RET ac_omc_ap_reboot_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_reboot_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_pingtest_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_pingtest_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_pingsummary_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_pingsummary_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_settime_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_settime_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_sethbperiod_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_sethbperiod_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_clearillegaldevhistory_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_clearillegaldevhistory_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_clearattackhistory_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_clearattackhistory_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_clearattackstatic_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_clearattackstatic_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* 2009-08-21 fengjing add end */

/* 2009-09-03 fengjing add */
extern AC_RET ac_oma_ap_report_reboot_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_report_version_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2009-09-07 fengjing add */
extern AC_RET ac_omc_ap_gettotalcfg_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_gettotalcfg_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2011-06-09 fengjing add*/
extern AC_RET ac_oma_ap_get_collectparam_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_report_apreportlevel_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);
//extern AC_RET ac_oma_check_activealarm_clear(AC_OMA_ALARM_FILTER_T *pstAlarmFilter);

#endif /*AC_OMA_CONFIG_H*/
