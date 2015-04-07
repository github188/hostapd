#ifndef AC_OMA_STAT_H
#define AC_OMA__STAT_H

#define AC_OMA_STAT_CACHE_NUM  ((UINT32)5)

#define AC_OMA_STAT_TYPE_SAMPLE         1 /* ͳ����Ϣ���� */
#define AC_OMA_STAT_TYPE_ABSTRACT       10 /* AP��Ҫ��Ϣ */
#define AC_OMA_STAT_TYPE_ASSOCIATE      11 /* AP����ͳ��,���� */
#define AC_OMA_STAT_TYPE_TOTAL          12 /* �û�����ͳ��,��SSID���� */
#define AC_OMA_STAT_TYPE_ENDUSER        13 /* �ն�ͳ�� */
#define AC_OMA_STAT_TYPE_SSID           14 /* �տ�ͳ�� */
#define AC_OMA_STAT_TYPE_IF             15 /* ���߲�ͳ�� */
#define AC_OMA_STAT_TYPE_ROGUEAP        16 /* �Ƿ�AP */
#define AC_OMA_STAT_TYPE_ROGUESTA       17 /* �����ն� */
#define AC_OMA_STAT_TYPE_IC             18 /* ���߶˿�ͳ�� */
#define AC_OMA_STAT_TYPE_MGT            19 /* ����ͳ�� */

#define AC_OMA_SAMPLE_TYPE_SYS          1
#define AC_OMA_SAMPLE_TYPE_ASSO         2
#define AC_OMA_SAMPLE_TYPE_IF           3
#define AC_OMA_SAMPLE_TYPE_SSID         4
#define AC_OMA_SAMPLE_TYPE_WIFI         5
#define AC_OMA_SAMPLE_TYPE_ENDUSER      6

// ���AP��ʵʱ�ɼ����ش򿪣���AC��AP������������ʵʱ�ɼ����ڽ��вɼ�
// ϵͳ����ͳ��
typedef struct
{
	UINT32 ulCPURTUsage;
	UINT32 ulMemRTUsage;
}AC_OMA_COLLECT_AP_SYS_T;

typedef struct
{	    
	CHAR     acSsid[32];	
    UINT32    ulAssocTimes;
    UINT32    ulAssocFailTimes;
    UINT32    ulReassocTimes;
	UINT32    ulApRspAssocTimes;
	UINT32    ulAssocSuccTimes;
}AC_OMA_COLLECT_AP_ASSOC_ENTRY_T;

typedef struct
{		   	
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_ASSOC_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_ASSOC_T;

typedef struct
{	
	UINT64    ulRecvBytes;
	UINT64    ulSendBytes;
	UINT32    ulRecvDiscardFrameNum;
}__attribute__ ((packed)) AC_OMA_COLLECT_AP_IF_ENTRY_T;

typedef struct
{		   	
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_IF_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_IF_T;

typedef struct
{
	CHAR     acSsid[32];	
	INT32 	 apSnrBSSIDAverageSignalStrength; 	 /*AP  ���ź�ƽ��ǿ��*/
	INT32	 apSnrBSSIDHighestRxSignalStrength;   /*AP  ������ź�ǿ��*/
	INT32 	 apSnrBSSIDLowestRxSignalStrength;    /*AP  ������ź�ǿ��*/
	UINT32   ulSendFrameNum; /* ���͵�����֡�� */
	UINT32   ulRecvFrameNum; /* ���յ�����֡�� */
	/* 2010/07/26 fengjing cmcc test */
	UINT32   ulRecvPackets;  /* ���͵����ݰ��� */
	UINT32   ulSendPackets;  /* ���յ����ݰ��� */
	UINT32   ulSendRetransFrame; /* �����ش�������֡�� */
	/* 2010/07/26 fengjing cmcc test */
	UINT32   ulSendRetransDataPackets;  /* �����ش������ݰ��� */
	UINT64   ulRecvBytes;
	UINT64   ulSendBytes;
}__attribute__ ((packed)) AC_OMA_COLLECT_AP_SSID_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_SSID_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_SSID_T;

typedef struct
{	
	UINT32  ulRecvErrPackets;        /* ���յĴ������ݰ��� */
    UINT32  ulRecvErrPhy;			/* �ŵ����յ���������� */
	UINT32  ulRecvErr;              /* ���յĴ�֡�� */
}AC_OMA_COLLECT_AP_WIFI_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_WIFI_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_WIFI_T;

typedef struct
{
	UINT8   aucEndUserMac[6];
	UINT8	acResv[2];
	UINT32  ulSendByteNum;	/* �����ֽ��� */
	UINT32  ulRecvByteNum;	/* �����ֽ��� */
}AC_OMA_COLLECT_AP_ENDUSER_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_ENDUSER_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_ENDUSER_T;

typedef struct
{
	UINT32                      ulApId;
	
	AC_OMA_COLLECT_AP_SYS_T     stSys;
	AC_OMA_COLLECT_AP_ASSOC_T   stAsso;
	AC_OMA_COLLECT_AP_IF_T      stIf;
	AC_OMA_COLLECT_AP_SSID_T    stSsid;
	AC_OMA_COLLECT_AP_WIFI_T    stWifi;
	AC_OMA_COLLECT_AP_ENDUSER_T stStation;

	//UINT8  aucResv[5];
}AC_OMA_COLLECT_AP_INFO_T;


typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulRet;            //������:0-�ɹ�
	UINT32   ulFinish;         //�Ƿ����:0-δ���� 1-����
}AC_OMA_DYNAINFO_HEAD_T;

typedef struct
{	
	UINT32  ulApId;	

	// 2010/05/25 fengjing add
	OSTOKEN semStat;	

	BOOL  bSampleFlag;
	BOOL  bAbstractFlag;
	BOOL  bAssociateFlag;
	BOOL  bTotalFlag;
	BOOL  bEndUserFlag;
	BOOL  bSsidFlag;
	BOOL  bIfFlag;
	BOOL  bRogueApFlag;
	BOOL  bRogueStaFlag;
	BOOL  bIcFlag;
	BOOL  bMgtFlag;

	UINT32  ulSampleNum;
	
	UINT32  ulIndex; // �α�
	UINT8*  apstApSampleInfo[AC_OMA_STAT_CACHE_NUM];	

	/* 2010/08/18 fengjing modify */
	UINT32  aulMallocSize[AC_OMA_STAT_CACHE_NUM];

	AC_OMA_DYNAINFO_HEAD_T stHead1;
	// APժҪ��Ϣ
	DEVICE_ABSTRACT_INFO_T stApAbstract;

	AC_OMA_DYNAINFO_HEAD_T stHead2;
	// AP����ͳ��
	OMA_ASSOC_STA_STAT_ENTRY stApAssociateStat;

	AC_OMA_DYNAINFO_HEAD_T stHead3;
	// APȫ��ͳ��
	OMA_GLOBAL_STAT_ENTRY stApTotalStat;

	UINT32 ulMallocSize;
	UINT32 ulValidDataSize;
	// AP�ն�ͳ��
	UINT8 *pstApEndUser;

	AC_OMA_DYNAINFO_HEAD_T stHead4;
	// AP�տ�ͳ��
	OMA_AIR_STATS_ENTRY stApSsidStat;

	AC_OMA_DYNAINFO_HEAD_T stHead5;
	// AP���߲�ͳ��
	NET_INFO_T stApIfStat;

	AC_OMA_DYNAINFO_HEAD_T stHead6;
	// AP ����AP
	ROGUE_AP_INFO_T stApRogueApInfo;

	AC_OMA_DYNAINFO_HEAD_T stHead7;
	// AP �����ն�
	ROGUE_STA_LIST_T stApRogueStaInfo;

	AC_OMA_DYNAINFO_HEAD_T stHead8;
	// AP ����ͳ��
	OMA_IC_STAT_ENTRY stApIcStatInfo;	

	AC_OMA_DYNAINFO_HEAD_T stHead9;
	// AP ����ͳ��
	OMA_MGT_STAT_ENTRY stApMgtStatInfo;
}AC_OMA_AP_STAT_INFO_T;

typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulSampleType;
}AC_OMC_GET_SAMPLE_REQ_MSG_T;

typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulRet;             //������:0-�ɹ�
	UINT32   ulFinish;          //�Ƿ����:0-δ���� 1-����
	UINT8    aucRsp[32*1024];   //�����ֽ���
}AC_OMC_GET_SAMPLE_RSP_MSG_T;

AC_RET  ac_oma_init_stat_report_queue(UINT32 ulNodeNum);
BOOL ac_oma_is_same_stat(const VOID *source, const VOID *dest);
UINT32  ac_oma_calc_hash_key_stat(const CHAR *msg, UINT32 ulNodeNum);

AC_RET ac_oma_add_stat_msg_to_queue(const AC_OMA_AP_STAT_INFO_T *msg);

// ���յ�ĳ��AP�ϱ���ͳ����Ϣʱ����ӵ���Ϣ������
AC_RET  ac_oma_add_stat_msg(UINT32 ulApId, UINT32 ulMsgType, UINT8 *pucMsg, UINT32 ulMsgLen);

#if 0
// ��AP��ɾ��ʱ����Ҫ�Ӷ�����ɾ����AP��Ԫ��ͳ����Ϣ������
AC_RET  ac_oma_remove_stat_msg_from_queue(UINT32 *msg);

// AC-OMA���յ�AP�ϱ��Ĳ�����̬����
AC_RET ac_oma_ap_report_statsample_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);

AC_RET ac_oma_check_ap_stat_msg(UINT32 ulApId, UINT32 ulSn, UINT32 ulMsgType);

AC_RET ac_oma_get_sample_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
#endif

AC_RET ac_oma_start_stat_report(UINT32 ulStatType);
AC_RET ac_oma_check_stat_report(VOID);

AC_RET ac_oma_config_init_acbasic_config(VOID);
AC_RET ac_db_acbasicsetup_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);

#endif

