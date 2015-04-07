#ifndef IFWIFI_H
#define IFWIFI_H

#ifndef WIN32
#define	__packed	__attribute__((__packed__))
#endif

#include "../ifCommon.h"
#include "wireless_copy.h"
#include "ieee80211.h"
#include "ieee80211_crypto.h"
#include "ieee80211_ioctl.h"

#include "../agent_type.h"

typedef struct adhocPm_s_i
{
 unsigned long totalRecvDataRate;
 /* �����Ȩƽ���Ľ������ʣ�ѡ����ӽ��Ľ������ʣ��ϱ���ϵͳ����ģ�飬�ϱ���ˢ�½�������ͳ�� */
 unsigned long totalSendDataRate;
 /* �����Ȩƽ���ķ������ʣ�ѡ����ӽ��ķ������ʣ��ϱ���ϵͳ����ģ�飬�ϱ���ˢ�·�������ͳ�� */
 unsigned long totalTxPower;
 /* ���书�ʵ�����ƽ�����������ҿ����ǹ̶��� */
 unsigned long totalSnr;
 /* Snr������ƽ�� */
 unsigned long neighborNumber;
 /* ������Ŀ */
} T_adhocPm_i;

/* adhoc�����б� */
typedef struct adhocNeighborEntry_s_i
{
 long adhocNeighborIndex;
 unsigned char adhocNeighborMac[6];
 unsigned char adhocNeighborIp[4];
 /* ���µĽ������� */
 unsigned long recvDataRate;
 /* ���µķ������� */
 unsigned long sendDataRate;
 /* ���µķ��͹��� */
 unsigned long txPower;
 /* ���µĽ�������� */
 unsigned long rssi;
 /* ƽ�����������*/
 unsigned long avgrssi;
} T_adhocNeighborEntry_i;

typedef struct snrEntry_s_i
{
 long snrChannel;
 /* ʹ��1..11 149..153��ʶ,0������Ч���ŵ� */
 long snrValue;
 /* ɨ��õ�������� */
} T_snrEntry_i;

typedef struct accessDenyEntry_s_i
{
 unsigned long accessDenyIndex;
 unsigned char accessDenyMac[6];
 unsigned char accessDenyReason[32];

 /* ʹ��jiffies��Ϊ��λ */
 unsigned long accessDenyTime;
} T_accessDenyEntry_i;

typedef struct
{
	char			accessDenyReason[32];		//ԭ��
	unsigned long	ulDenyNum;					//����
	unsigned long	ulWifiIndex;				//ģ���
} T_accessDenyReason_i;

typedef struct wifiState_s_i
{
	enum {
		N_endUserTable_I = 0,
		N_accessDenyTable_I,
		N_snrTable_I,
		N_adhocNeighborTable_I,
		N_adhocPm_I,
		N_accessDenyReasonTable_I,
		N_Sta_Stats_I
	} m;
/*
#define MAX_ENDUSER_ENTRY_I 128
#define MAX_ACCESSDENY_ENTRY_I 10
#define MAX_SNR_ENTRY_I 8
#define MAX_ADHOCNEIGHBOR_ENTRY_I 10
*/
	union {
		T_apEndUser				endUserEntry;
		OMA_STA_ASSOCIATE_T		stStaAssociate;
		T_accessDenyEntry_i		accessDenyEntry[MAX_ACCESSDENY_ENTRY_I];
		T_snrEntry_i			snrEntry[MAX_SNR_ENTRY_I];
		T_adhocNeighborEntry_i	adhocNeighborEntry[MAX_ADHOCNEIGHBOR_ENTRY_I];
		T_adhocPm_i				adhocPm;
		T_accessDenyReason_i	stAcceDenyReasonEntry[MAX_ACCESSDENY_ENTRY_I];
	} u;
} T_wifiState_i;

/*-------------------------------------- filter stat -----------------------------------------*/
/* mac filter ���Ͷ��� */
typedef struct
{
	u_int8_t	aucMac[IEEE80211_ADDR_LEN];	/* MAC��ַ */
	u_int32_t   ulDenyDiscards; /* ������ͳ�� */
}DENY_FILTER_STAT_T;

typedef struct
{
	u_int32_t    ulAllowPks; /* �����ĸ��� */
#define IOCTL_MAC_FILTER_MAXNUM 64
	DENY_FILTER_STAT_T aucDenyStat[IOCTL_MAC_FILTER_MAXNUM]; /* �ܾ�ͳ����Ϣ */
}IEEE80211_FILTER_STAT_T;

typedef struct{
	u_int32_t ulType;
#define IOCTL_SET_MAC_FILTER_LIST     0
#define IOCTL_DEL_MAC_FILTER_LIST     1
#define IOCTL_GET_MAC_FILTER_LIST     2
#define IOCTL_SET_MAC_FILTER_MODE     3
#define IOCTL_GET_MAC_FILTER_STAT     4
	u_int32_t ulMode;
#define MAC_FILTER_DENY        0x00
#define MAC_FILTER_ALLOW       0x01
	union{
		u_int8_t aucMacList[IOCTL_MAC_FILTER_MAXNUM][IEEE80211_ADDR_LEN];
		IEEE80211_FILTER_STAT_T stFilterStat;
	}u;
#define aucList	u.aucMacList
#define stStat u.stFilterStat
} IOCTL_MAC_FILTER_T;

/*---------------------------------------- adhoc authority -----------------------------------------------*/
/* adhoc ��Ȩ�����Ͷ��� */
typedef struct
{
	u_int8_t ucIbssAuthmode; /* Ad-hocģʽ��Ȩ��ʽ*/
#define IOCTL_IBSS_AUTH_MODE_SHARED    ((u_int8_t) 0) /*����ʽ*/
#define IOCTL_IBSS_AUTH_MODE_OPEN      ((u_int8_t) 1) /*����ʽ*/
	u_int8_t ucIbssAutTryNum; /* Ad-hocģʽ��Ȩʧ�ܺ����³��ԵĴ���*/
	u_int8_t ucIbssAuthTimer; /* Ad-hocģʽ��Ȩ��ʱ��ʱ��*/
	u_int8_t ucIbssAuthDataEncrypt; /* Ad-hocģʽ������֡�Ƿ����*/
#define IOCTL_IBSS_AUTH_DATA_NOT_ENCRYPT    ((u_int8_t) 0) /*������*/
#define IOCTL_IBSS_AUTH_DATA_ENCRYPT       ((u_int8_t) 1) /*����*/
} IOCTL_IBSS_AUTH_T;

/*--------------------------------------------- wifiDevice -----------------------------------------------*/
typedef enum
{
	ADD_WIFI_DEVICE,			/* ���������豸*/
	DEL_WIFI_DEVICE,			/* ɾ�������豸*/
	EDIT_WIFI_DEVICE			/* �޸������豸*/
}WIFI_DEVICE_SET_TYPE_E;

#define WIFIMODULE_SIZE				4
typedef struct
{
	unsigned long	ulWifiDeviceId;							/* �����豸���*/
	unsigned long	ulWifiDeviceType;						/* �豸����*/
#define WIFIDEVICETYPE_NONE			0XFFFFFFFF
#define WIFIDEVICETYPE_ALONEAP		0						/* �����Ľ���ģ�� */
#define WIFIDEVICETYPE_BINDAP		1						/* ����Ľ���ģ�� */
#define WIFIDEVICETYPE_ALONEADHOC	2						/* �����Ļش�ģ�� */
#define WIFIDEVICETYPE_BINDADHOC	3						/* ����Ļش�ģ�� */
#define WIFIDEVICETYPE_APADHOC		4						/* ����ӻش�ģ�� */
	unsigned long	ulWifiModuleNum;						/* ģ���б��б�ʹ�õĸ���*/
	char			acWifiModuleName[WIFIMODULE_SIZE][8];	/* ģ�������б�*/
	unsigned long	ulWifiModuleRole[WIFIMODULE_SIZE];		/* ģ���ɫ�б� */
}WIFI_DEVICE_T;

typedef struct
{
	WIFI_DEVICE_SET_TYPE_E	enSetType;						/* ��������*/
	WIFI_DEVICE_T stWifiDevice;
}WIFI_DEVICE_SET_T;

/*----------------------------------- vap set with wifiDevice ------------------------------------------*/
typedef enum
{
	ADD_VAP_2_WIFI_DEVICE,									/* �������豸������VAP */
	DEL_VAP_FROM_WIFI_DEVICE								/* �������豸��ɾ��VAP */
}VAP_SET_TYPE_E;

typedef struct
{
	char			acVapName[32];							/* VAP�豸��*/
	unsigned long	ulWifiDeviceId; 						/* �����豸���*/
	unsigned long	ulVapRole;								/* �豸�Ľ�ɫ*/
#define	INDIE_VAP				0							/* ������VAP */
#define	MAIN_VAP				1							/* ��VAP */
#define	SLAVE_VAP				2							/* ��VAP */
	char			acMainVapName[32];						/* ֪ͨ���߲�ô�AP��Ӧ����AP������VAPΪ��VAPʱ�������ø�ֵ */
}VAP_MANAGE_T;

typedef struct
{
	VAP_SET_TYPE_E	enSetType;								/* ��������*/
	VAP_MANAGE_T	stVapManage;
}VAP_ASSIGN_T;

/*---------------------------------------- auto channel list -------------------------------------------*/
#define	CHANNEL_LIST_MAX_NUM	16
typedef struct
{
	unsigned long	ulWifiDeviceId;							/* �����豸���*/
	unsigned long	ulChannelNum;							/* �ŵ��б��б�ʹ�õĸ��� */
	unsigned long	aulChannelList[CHANNEL_LIST_MAX_NUM];	/* �ŵ��б�*/
}AUTO_CHANNEL_LIST_SET_T;

/*--------------------------------------- wifi algorithm para ------------------------------------------*/

/*�����Ľ���ģ��Ĳ���*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEAP_PARA_T;

/*����Ľ���ģ��Ĳ���*/
typedef struct
{
    int resv;
}WIFI_DEVICE_BINDAP_PARA_T;

/*�����Ļش�ģ��Ĳ���*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEADHOC_PARA_T;

/*����ӻش�ģ��Ĳ���*/
typedef struct
{
    int resv;
}WIFI_DEVICE_APADHOC_PARA_T;

/*����ش�ģ��Ĳ���*/
typedef struct
{
	unsigned long ulScanTimerMinIntvl;	/*ɨ�趨ʱ������Сʱ��-��λms*/
	unsigned long ulScanTimerIntvl;		/*ɨ�趨ʱ����ʱ��-��λms */
	unsigned long ulKeepRunMsgIntvl;	/*�յ�������Ϣ��ʱ����-��λms */
	unsigned long ulMaxSendProbeNum;	/*���͵����Probe ��Ϣ����Ŀ*/
	unsigned long ulAcceptRssi;			/*���Խ��ܵ��ź�ǿ��-��λdBm*/
	unsigned long ulMinScanPauseIntvl;	/*ɨ���Ъ����Сʱ��-��λms */
	unsigned long ulScanPauseIntvl;		/*ɨ���Ъ��ʱ��-��λms */
}WIFI_DEVICE_BINDADHOC_PARA_T;

typedef struct
{
	unsigned long      ulWifiDeviceId;
	unsigned long      ulWifiDeviceType;

	union
	{
		WIFI_DEVICE_ALONEAP_PARA_T       stAloneApPara;
		WIFI_DEVICE_BINDAP_PARA_T        stBindApPara;
		WIFI_DEVICE_ALONEADHOC_PARA_T    stAloneAdhocPara;
		WIFI_DEVICE_BINDADHOC_PARA_T     stBindAdhocPara;             /*����Ļش�ģ��*/
		WIFI_DEVICE_APADHOC_PARA_T       stApAdhocPara;
	}unAlgorithmPara;
}WIFI_DEVICE_ALGORITHM_PARA_T;

/*------------------------------------------ adhoc link stat ---------------------------------------------*/
#define IVALID_DATA        0xFFFFFFFF

#define RATE_PKT_INFO_MAX_NUM			15
//�������ϵ���/������
typedef struct
{
	unsigned long	ulRate;						//����
	unsigned long	ulRecvPkt;					//���հ���
	unsigned long	ulSendPkt;					//���Ͱ���
}RATE_PKT_INFO_T;
typedef RATE_PKT_INFO_T		RATE_PKT_STAT_T[RATE_PKT_INFO_MAX_NUM];

//�������ϵķ��Ͱ���
#define POWER_SEND_PKT_INFO_MAX_NUM		30
typedef struct
{
	unsigned long	ulTxPower;					//����
	unsigned long	ulSendPkt;					//���Ͱ���
}POWER_SEND_PKT_INFO_T;
typedef POWER_SEND_PKT_INFO_T	POWER_SEND_PKT_STAT_T[POWER_SEND_PKT_INFO_MAX_NUM];

//��RSSI�Ľ��հ���
#define RSSI_RECV_PKT_INFO_MAX_NUM		10
typedef struct
{
	unsigned long	ulRssi;						//RSSI
	unsigned long	ulRecvPkt;					//���հ���
}RSSI_RECV_PKT_INFO_T;
typedef RSSI_RECV_PKT_INFO_T	RSSI_RECV_PKT_STAT_T[RSSI_RECV_PKT_INFO_MAX_NUM];

//�����������������/������
#define SIGNAL_PKT_INFO_MAX_NUM			20
typedef struct
{
	unsigned long	ulSignal;					//����
	unsigned long	ulLossPkt;					//������
	unsigned long	ulRecvPkt;					//���հ���
	unsigned long	ulSendPkt;					//���Ͱ���
}SIGNAL_PKT_INFO_T;
typedef SIGNAL_PKT_INFO_T	SIGNAL_PKT_STAT_T[SIGNAL_PKT_INFO_MAX_NUM];

#define ANTENNA_NUM ((u_int8_t)2)				/*���ߵ���Ŀ*/

/*����ͳ����Ϣ*/
typedef struct
{
	unsigned long  aulResvUCastNum[ANTENNA_NUM]; /*ÿ�����߽��յĵ���������Ŀ*/
	unsigned long  aulSendUCastNum[ANTENNA_NUM]; /*ÿ�����߷��͵ĵ���������Ŀ*/
}ANTENNA_STAT_T;

//��·ͳ��
#define ADHOC_LINK_STAT_LIST_MAX_NUM	20
typedef struct
{
	unsigned long			ulBusinessLossPkt;	//ҵ�񶪰���
	unsigned long			ulBusinessRecvPkt;	//ҵ���հ���
	unsigned long			ulBusinessSendPkt;	//ҵ�񷢰���
	unsigned long			ulBroadcastRecvPkt;	//�㲥�հ���
	unsigned long			ulBroadcastSendPkt;	//�㲥������
	unsigned long			ulRssi;				//RSSI
	unsigned long			ulChannel;			//�����ŵ�
    long					lNoiseFloor;		//����
    unsigned char			ucWifiModuleName[32];//ģ���
	char					acPeerMac[6];		//�Զ�MAC
	RATE_PKT_STAT_T			stcRatePktStat;		//�������ϵ���/������
	ANTENNA_STAT_T			stAntennaStat;      //������Ϣ
	POWER_SEND_PKT_STAT_T	stcPowerSendPktStat;//�������ϵķ��Ͱ���
	RSSI_RECV_PKT_STAT_T	stcRssiRecvPktStat;	//��RSSI�Ľ��հ���
	SIGNAL_PKT_STAT_T		stcSignalPktStat;	//�����������������/������
}ADHOC_LINK_STAT_T;

typedef struct
{
	unsigned long			ulValidNum;
	ADHOC_LINK_STAT_T		stcAdhocLinkStat;
}ADHOC_LINK_STAT_LIST_T;

typedef struct
{
    UINT32                  ulRxucNum;          /*���յ㲥����Ŀ*/
    UINT32                  ulRxmcNum;          /*���չ㲥����Ŀ*/
    UINT32                  ulTxucNum;          /*���͵㲥����Ŀ*/
    UINT32                  ulTxmcNum;          /*���͹㲥����Ŀ*/
    UINT32                  ulTxAirLostNum;     /*�տڶ�����*/
    UINT32                  ulTxActLostNum;     /*����������*/
    UINT32                  ulTxReNum;          /*�ش�������ֻ�㲥�����ش�*/
    UINT32                  ulUserNum;          /*AP����ʱ�����û�����*/
    INT32                   iNoise;             /*����*/
}VAP_STATS_T ;

typedef struct
{
    UINT32                  ulRxucNum;          /*���յ㲥����Ŀ*/
    UINT32                  ulRxmcNum;          /*���չ㲥����Ŀ*/
    UINT32                  ulTxucNum;          /*���͵㲥����Ŀ*/
    UINT32                  ulTxmcNum;          /*���͹㲥����Ŀ*/
    UINT32                  ulTxAirLostNum;     /*�տڶ�����*/
    UINT32                  ulTxActLostNum;     /*����������*/
    UINT32                  ulTxReNum;          /*�ش�������ֻ�㲥�����ش�*/
    UINT32                  ulNeiNum;           /*ADHOC����ʱ�ھӸ���*/
    INT32                   iNoise;             /*����*/
}ADHOC_STATS_T ;

typedef struct
{
	u_int32_t ulStaDelIntvl;
	u_int32_t ulHighRssi;
	u_int32_t ulLowRssi;
}AP_DEL_STA_PARA_T;

typedef enum
{
	BSS_STAT_GROBE,
	BSS_STAT_AIR,
	BSS_STAT_NEIGH_LINK,
	BSS_STAT_ASSOC,
	IC_STAT,
	BSS_STAT_MGT
}BSS_STAT_CMD_T;

typedef struct
{
	BSS_STAT_CMD_T enStatCmd;
	union {
		OMA_GLOBAL_STAT_INFO stGlobeStats;
		OMA_AIR_STATS_INFO_DRV stAirStates;
		OMA_ADHOC_LINK_STATS_ENTRY stNeighLinkStats;
		BSS_STAT_ASSOC_T stAssocStats ;
		OMA_MGT_STAT_INFO_T stMgtStats;
		OMA_IC_STAT_INFO_T	stIcStat;	/* 2010-4-11 pyy �����������ܲ�������*/
	}unStats;
}BSS_STATS_T;

typedef struct
{
	unsigned long on;			                /* 0�����ã�1�����ã�ȱʡΪ����*/
#define SCAN_ROGUE_SSID_OFF			0
#define SCAN_ROGUE_SSID_ON			1
	unsigned long flag;							/* flag&0x01:������ͬSSID��ROGUE AP��flag&0x02:��������
	                                             * ��SSID��ROGUE AP��flag��־λ�����ʹ�ã�ȱʡֵΪ0x01 */
#define MONITOR_SAME_ROGUE_SSID		0x1
#define MONITOR_HIDDEN_ROGUE_SSID	0x2
#define MONITOR_COM_ROUGE_SSID		0x1 | 0x2
	struct ieee80211_scan_ssid rogue_ssid;
	unsigned char bssid[6];						/* ָ��BSSID��AP��ȫ1��Ч */
	unsigned char oui[3];						/* ָ�����̵�AP��ȫ1��Ч */
	unsigned char aucRsv[3];
}WIFI_WIDS_T;

typedef struct
{
    UINT32  on;                         /* 1: ���ã�0������ */
    UINT32  flags;                      /* ROGUE AP���壺����λ��ʾ�������º���ʾ */
#define ROGUE_LOCAL_SSID    0x01        /* ������ͬSSID��AP */
#define ROGUE_HIDE_SSID     0x02        /* ����SSID��AP */

    struct ieee80211_scan_ssid ssid;    /* ָ��SSID��AP������ͨ���'*'��ȱʡΪ�գ���ȫ0 */
    UINT8    bssid[6];                  /* ָ��BSSID��AP��ȫf��Ч */
    UINT8    oui[3];                    /* ָ�����̵�AP��ȫf��Ч */
    UINT8    pad[3];
}ROGUE_AP_DEF_T ;


typedef struct
{
    UINT32  period;                 /* �ŵ�ɨ�����ڣ��Է���Ϊ��λ����ÿ15����ɨ�������ŵ�����СֵΪ5���� */
    UINT32  dwell;                  /* �ŵ�ͣ��ɨ��ʱ�䣬�Ժ���Ϊ��λ��[20��1000] */
}BGSCAN_CONFIG_T;

/*ֻ��Ƶ������ΪAUTOʱ��������������������*/
typedef struct 
{
	unsigned long	ulFrequPointQualitySwitch;		/* �ŵ���ѡ���� */
	unsigned long	ulRssiThreshold;				/* �ŵ���ѡRSSI���� */
	long			lNoiseThreshold;				/* �ŵ���ѡ�������� */
}CHANNEL_REELECT_T;


/*-------------------------------------- �Զ���ioctl�ӿڵ����Ͷ��� -------------------------------------------*/
#define   IEEE80211_IOCTL_COMMON      	(SIOCDEVPRIVATE + 15)
typedef enum
{
	IOCTL_MAC_FILTER = 0,							/* MAC��ַ���� */
	IOCTL_IBSS_AUTH,								/* IBSS��Ȩ */
	IOCTL_WIFIDEVICESET,            				/* �����豸���� */
	IOCTL_VAPSET,                   				/* VAP���� */
	IOCTL_AUTOCHANNELLISTSET,       				/* ����Ӧ�ŵ����� */
	IOCTL_ALGORITHM_PARA, 							/* �㷨���� */
	IOCTL_LINK_STAT,								/* �ش���·ͳ�� */
	IOCTL_EVENT_LIST, 								/* ��ȡ�¼��б� */
	IOCTL_SET_USER_MAXNUM = 8,                               /*VAP���������û���Ŀ����*/
	IOCTL_GET_ENDUSER,   							/* TC��ȡ�û���Ϣ */
	IOCTL_QOSMAP_SET = 11,
	IOCTL_QOSMAP_GET = 12,
	IOCTL_GET_CHANNEL_NO = 15,						/* ��ȡ�豸��ǰ�ŵ��� */

    /* hc modified for cmcc test 2009-7-18 */  
    IOCTL_SET_USER_MAXNUM_CARD = 17,                /*�����豸���������û���Ŀ����*/
    IOCTL_SET_USER_MAXNUM_GLOBAL = 18,              /* APϵͳ���������û���Ŀ����*/

	IOCTL_NETID_SET = 20 ,             				/* ���úϷ���־ */
	IOCTL_NETID_GET = 21,              				/* ��ȡ�Ϸ���־ */
	IOCTL_WIDS_SET = 22,              		        /* WIDS���ò������� */
	IOCTL_WIDS_GET = 23,              		        /* WIDS���ò�����ȡ */

	IOCTL_ROGUE_GET = 24,              				/* �ϱ��Ƿ�AP��Ϣ */
	IOCTL_SET_AP_DEL_STA_PARA = 25,					/* ɾ���ն����� */
    IOCTL_VAP_STATS_GET = 30,                       /* ��ȡVAPͳ����Ϣ */
	IOCTL_WIFI_POWER_CTRL_SET = 31,					/* ���ʿ������� */
	IOCTL_BSS_STATS = 32,							/* ���߶�̬��Ϣ��ȡ */
	IOCTL_CHANNEL_REELECT_SET = 33,					/* Ƶ����ѡ���� */

    /* hc modified for telecom test 2009-7-6 */
    IOCTL_ROGUE_STA_GET = 40, 
    IOCTL_CLEAR_ILLEGAL_DEVICE_HISTORY = 41,
    IOCTL_CLEAR_ATTACK_HISTORY = 42,
    IOCTL_CLEAR_ATTACK_STAT = 43,

	/* 2010/08/26 fengjing add,for get ap neighbor ap list */
	IOCTL_NEIGHBORAP_GET = 54,

	IOCTL_POWERMIN_SET = 60,						/* ��С�������� */
    IOCTL_SCAN_NEIGHBOR = 64,                       /* �ھ��Զ�ɨ�迪�� */
       
    /* hc modified for telecom test 2009-7-6 */
    IOCTL_WIDS_CONFIG_SET = 70,                     /* ���ö���AP���� */
    IOCTL_WIDS_CONFIG_GET = 71,                     /* ��ȡ����AP���� */
    IOCTL_BGSCAN_SET = 72,                          /* ����ɨ����� */
    IOCTL_BGSCAN_GET = 73,                          /* ��ȡɨ����� */

     	IOCTL_WORKMODE_SET = 75,			/* ����AP����ģʽ*/
	IOCTL_WORKMODE_GET = 76,			/* ��ȡAP����ģʽ*/


	IOCTL_GET_CHANNEL_NOSCAN_FLAG = 124,
	IOCTL_GET_DESIRED_BSSID = 128,					/* �󶨵�BSSID */
	IOCTL_GET_ROAM_STAT = 129,						/* ��ʷ������Ϣ */
	IOCTL_GET_RELAY_CLIENT = 140, 					/* �����ն���Ϣ */
	IOCTL_SET_WMM_QOS_SWITCH = 178					/* WMM���ܿ������� */
}IOCTL_COMMON_TYPE_E;

typedef struct
{
	IOCTL_COMMON_TYPE_E  enCommIoctlType;
	union
	{
		IOCTL_MAC_FILTER_T				stFilterList;
		IOCTL_IBSS_AUTH_T				stIbssAuth;
		WIFI_DEVICE_SET_T               stWifiDeviceSet;
		VAP_ASSIGN_T                    stVapSet;
		AUTO_CHANNEL_LIST_SET_T			aulChannelListSet;
		WIFI_DEVICE_ALGORITHM_PARA_T	stAlgorithmPara; 	/* �㷨���� */
		ADHOC_LINK_STAT_LIST_T			stAdhocLinkStat;	/* �ش���·ͳ�� */
		EVENT_TRAP_MSG_LIST_T			stEventList;		/* ��ȡ�¼��б� */
		unsigned char					aaucEndUserMac[MAX_END_USER][IEEE80211_ADDR_LEN];
		unsigned char					aucQosmap[WME_NUM_AC];
		unsigned long                   ulNetId;            /* ����ʶ��Ƿ�����IP */
		WIFI_WIDS_T                     stWids;             /* WID���ò��� */
		ROGUE_AP_INFO_T                 stRogueApInfo;
		ROGUE_AP_DEF_T                  stRogueApDef;       /* ���ö���AP���� */
		BGSCAN_CONFIG_T                 stBgScanConfig;     /* ����ɨ����� */

        /* hc modified for telecom test 2009-7-6 */
		WIDS_CONFIG_T                   stWidsCfg ;
        ROGUE_STA_LIST_T                rogue_sta_list ;

        VAP_STATS_T                     stVapStats;
        ADHOC_STATS_T                   stAdhocStats;
		CHAN_SCAN_INFO_T				astGetChanScanInfo[MAX_CHAN_NUM];
		u_int8_t						aaucGetDesBssid[MAX_DES_BSSID][IEEE80211_ADDR_LEN];
		ROAM_STAT_T						stRoamStat;
		RELAY_CLIENT_T					astRelayClients[RELAY_CLIENT_MAX];
		AP_DEL_STA_PARA_T				stApDelStaPara;
		u_int32_t						ulPowerCtrlSet;		/*0:�ر�,1:����*/
		u_int32_t						ulWmmQosCtrlSet;	/*0:�ر�,1:����*/
		BSS_STATS_T						stBssStats;
		
		NEIGHBOR_AP_LIST_T              stNeighborAp; /* 2010/08/26 fengjing ����:��ȡ�ھ�AP */
		
		unsigned char					ucChannNo;			/* �ŵ� added at 3-17 */
		u_int32_t						ulPowerMin;			/* ��С���书�� */

		/* hc modified for cmcc test 2009-7-18 */
		u_int16_t                       usMaxUserNum;       /* VAP���������û���Ŀ����*/
        u_int32_t                       ulUserMaxCard ;     /* �����豸���������û���Ŀ����*/
        u_int32_t                       ulUserMaxGlobal ;   /* APϵͳ���������û���Ŀ����*/
        u_int32_t                       ulScanNeighbor ;    /* 0�����ã�1������*/
        CHANNEL_REELECT_T				stChannelReselect;

        	u_int32_t		ulMoniMode;					/* 1���ṩWLAN�������
												2���������߻���
												3������ʱ�������߻���*/

	}unData;
}IOCTL_COMMON_DATA_T;

int wifi_mac_get(char *dev, unsigned char *padhocMac);

int wifi_bssid_get(char *dev, unsigned char *pbssid);

int wifi_txpower_get(char *dev, unsigned long *pmaxTxPower);

int wifi_max_txpower_get(char *dev, unsigned long *pmaxTxPower);

int wifi_mode_set(unsigned long wifiDeviceId, char *dev, long apmode);

int wifi_modebit_set(char *dev, long apmode);

int wifi_channel_set(unsigned long wifiDeviceId, char *dev, long apchannel);

int wifi_active_channel_set(char *dev, unsigned long aulChannelList[], unsigned char ucType);

int wifi_ssid_set(char *dev, char *ptssid);

int wifi_broadcastssid_set(char *dev, long apBroadcastSsid);

int wifi_beaconinterval_set(char *dev, long apBeaconInterval);

int wifi_dtiminterval_set(char *dev, long apDtimInterval);

int wifi_fragmentationthreshold_set (char *dev, long apFragmentationThreshold);

int wifi_rtsthreshold_set(char *dev, long apRtsThreshold);

int wifi_ctsprotectionmode_set(char *dev, long apCtsProtectionMode);

int wifi_preambletype_set(char *dev, long apPreambleType);

int wifi_authenticationtype_set(char *dev, long apAuthenticationType);

int wifi_txrate_set(char *dev,
					unsigned long ulWifiId,
					unsigned long apTxRate,
					unsigned long ulMgmTrate,
					unsigned long ulMcasTrate,
					unsigned long ulMgmtRetrys);

int wifi_security_set(char *dev, long apSecurity);

int wifi_wepkey_set (char *dev, unsigned char *key, unsigned int keyLen, unsigned long keyIndex);

int wifi_txpower_set(char *dev, unsigned long txpow);

int wifi_min_txpower_set(char *dev, unsigned long txpow);

int wifi_maxretransmitcount_set(char *dev, unsigned long retrynum);

int wifi_adhocsecurity_set(char *dev, T_adhocSecuritySetup *security);

int wifi_macfilter_clear(char *dev);

int wifi_macfilter_set(char *dev, T_apMacFilterSetup *filter);

int wifi_macfilterstat_get (char *devName, T_apMacFilterStat *stat);

int wifi_state_get (char *dev, T_wifiState_i *ptState);

int wifi_device_set( char *dev, WIFI_DEVICE_SET_T *stWifiDevice, int iFlag );

int wifi_vap_assign( char *dev, VAP_ASSIGN_T *stVapAssign, int iFlag  );

int wifi_channel_list_set( char *dev, AUTO_CHANNEL_LIST_SET_T *stChannelList );

int wifi_device_algorithm_set( char *dev, WIFI_DEVICE_ALGORITHM_PARA_T * p_wifiDeviceAlgorithmPara );

int wifi_net_id_set(char *dev,  unsigned long netId);

/* hc modified for telecom test 2009-7-6 */
int wifi_wids_set(char *dev,  WIDS_CONFIG_T *p_stWid);

/**
int wifi_net_id_get(char *dev,  unsigned char *p_netId);

int wifi_wids_get(char *dev,  WIDS_T *p_stWid);
*/

int wifi_rogue_ap_get(char *dev, ROGUE_AP_INFO_T *p_stRogueData)
/* hc modified for telecom test 2009-7-6  */;
int wifi_rogue_sta_get(char *dev, ROGUE_STA_LIST_T *p_stRogueStaData);

/************************************************************************/
/*
* ��������: wifi_adhoc_link_stat_get
* ��    ��: ��ȡ�ش���·��ͳ����Ϣ
* ��    ��:
* ��������			   ����/���				����
* p_adhocLinkStatInfo      OUT             �ش���·��ͳ����Ϣ
* ��������: 0�����ȡ�ɹ���-1�����ȡʧ��
* ˵    ��:
*/
/************************************************************************/
int wifi_adhoc_link_stat_get( char *dev, IOCTL_COMMON_DATA_T * pstIoctlData );
int wifi_vap_adhoc_stat_get( char *dev, IOCTL_COMMON_DATA_T * pstIoctlData );


/************************************************************************/
/*
* ��������: wifi_event_list_get
* ��    ��: ��ȡ�����¼��б�
* ��    ��:
* ��������			   ����/���				����
* p_eventTrapMsgInfo      OUT             �����¼��б���Ϣ
* ��������: 0�����ȡ�ɹ���-1�����ȡʧ��
* ˵    ��:
*/
/************************************************************************/
int wifi_event_list_get( char *dev, EVENT_TRAP_MSG_LIST_T * p_eventTrapMsgList );

int wifi_max_end_user_num_set_vap(char *dev, int maxEndUserNum);
/* hc modified for cmcc test */
int wifi_max_end_user_num_set_card(char *dev, int maxEndUserNum);

int wifi_max_end_user_num_set_global(char *dev, int maxEndUserNum);

int wifi_end_user_list_get(char *dev, T_endUserMac *pEndUserMacList);

int wifi_qos_map_set(char *dev, unsigned long aucQosmap[]);

/* ��ȡ�����ն���Ϣ */
int wifi_relay_clients_get(char *dev, RELAY_CLIENT_ENTRY_T *stat);

/* ��ȡ��ʷ������Ϣ */
int wifi_roam_stat_get(char *dev, ROAM_STAT_T *stat);

/* ��ȡ�󶨵�BSSID */
int wifi_bind_bssid_get(char *dev, BIND_BSSID_ENTRY *stat);

/* ��ȡ�ŵ�ɨ����Ϣ */
int wifi_chan_scan_info_get(char *dev, CHAN_SCAN_INFO_ENTRY_T *stat);

void wifi_list_scan(STA_SCAN_INFO_T *p_scanList);

int wifi_ap_del_sta_para_set(char *dev,  AP_DEL_STA_PARA_T *p_stApPara);

int wifi_power_ctl_set(char *dev, unsigned long ulPowerCtrlSet);

int wifi_wmm_qos_ctl_set(char *dev, unsigned long ulWmmQosCtrlSet);

int wifi_global_stat_get(char *dev, OMA_GLOBAL_STAT_INFO *stat);

int wifi_air_stat_get(char *dev, OMA_AIR_STATS_INFO_DRV *stat);

/* 2010/05/15 fengjing add */
int wifi_mgt_stat_get(char *dev, OMA_MGT_STAT_INFO_T *stat);

int wifi_AssocSta_stat_get(char *dev, BSS_STAT_ASSOC_T *stat);

int wifi_adhoc_stat_get(char *dev, OMA_ADHOC_LINK_STATS_ENTRY *stat);

int wifi_device_channel_get(char *dev, unsigned long *ulChl);

int wifi_res_set(char *dev,  T_wifiDeviceResourceSetup * pstRes);
/* hc modified for telecom test 2009-7-6 */
int wifi_clear_ilegal_dev_history_set (char *dev);

int wifi_clear_attack_history_set (char *dev);

int wifi_clear_attack_stat_set (char *dev);

int wifi_channel_reselect_set(char *dev, T_wifiDeviceChanSetup *p_stWifiChan);

/* 2010/08/26 fengjing add */
int wifi_neigbor_ap_get(char *dev, NEIGHBOR_AP_LIST_T *pstNeighborAp);

#endif
