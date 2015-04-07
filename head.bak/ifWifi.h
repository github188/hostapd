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
 /* 算出加权平均的接收速率，选择最接近的接收速率，上报给系统控制模块，上报后刷新接收速率统计 */
 unsigned long totalSendDataRate;
 /* 算出加权平均的发送速率，选择最接近的发送速率，上报给系统控制模块，上报后刷新发送速率统计 */
 unsigned long totalTxPower;
 /* 发射功率的算术平均，可能在我看来是固定的 */
 unsigned long totalSnr;
 /* Snr的算术平均 */
 unsigned long neighborNumber;
 /* 邻区数目 */
} T_adhocPm_i;

/* adhoc邻区列表 */
typedef struct adhocNeighborEntry_s_i
{
 long adhocNeighborIndex;
 unsigned char adhocNeighborMac[6];
 unsigned char adhocNeighborIp[4];
 /* 最新的接收速率 */
 unsigned long recvDataRate;
 /* 最新的发送速率 */
 unsigned long sendDataRate;
 /* 最新的发送功率 */
 unsigned long txPower;
 /* 最新的接收信噪比 */
 unsigned long rssi;
 /* 平均接收信噪比*/
 unsigned long avgrssi;
} T_adhocNeighborEntry_i;

typedef struct snrEntry_s_i
{
 long snrChannel;
 /* 使用1..11 149..153标识,0代表无效的信道 */
 long snrValue;
 /* 扫描得到的信噪比 */
} T_snrEntry_i;

typedef struct accessDenyEntry_s_i
{
 unsigned long accessDenyIndex;
 unsigned char accessDenyMac[6];
 unsigned char accessDenyReason[32];

 /* 使用jiffies作为单位 */
 unsigned long accessDenyTime;
} T_accessDenyEntry_i;

typedef struct
{
	char			accessDenyReason[32];		//原因
	unsigned long	ulDenyNum;					//个数
	unsigned long	ulWifiIndex;				//模块号
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
/* mac filter 类型定义 */
typedef struct
{
	u_int8_t	aucMac[IEEE80211_ADDR_LEN];	/* MAC地址 */
	u_int32_t   ulDenyDiscards; /* 丢弃包统计 */
}DENY_FILTER_STAT_T;

typedef struct
{
	u_int32_t    ulAllowPks; /* 允许报文个数 */
#define IOCTL_MAC_FILTER_MAXNUM 64
	DENY_FILTER_STAT_T aucDenyStat[IOCTL_MAC_FILTER_MAXNUM]; /* 拒绝统计信息 */
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
/* adhoc 鉴权的类型定义 */
typedef struct
{
	u_int8_t ucIbssAuthmode; /* Ad-hoc模式鉴权方式*/
#define IOCTL_IBSS_AUTH_MODE_SHARED    ((u_int8_t) 0) /*共享式*/
#define IOCTL_IBSS_AUTH_MODE_OPEN      ((u_int8_t) 1) /*开放式*/
	u_int8_t ucIbssAutTryNum; /* Ad-hoc模式鉴权失败后重新尝试的次数*/
	u_int8_t ucIbssAuthTimer; /* Ad-hoc模式鉴权定时器时长*/
	u_int8_t ucIbssAuthDataEncrypt; /* Ad-hoc模式下数据帧是否加密*/
#define IOCTL_IBSS_AUTH_DATA_NOT_ENCRYPT    ((u_int8_t) 0) /*不加密*/
#define IOCTL_IBSS_AUTH_DATA_ENCRYPT       ((u_int8_t) 1) /*加密*/
} IOCTL_IBSS_AUTH_T;

/*--------------------------------------------- wifiDevice -----------------------------------------------*/
typedef enum
{
	ADD_WIFI_DEVICE,			/* 增加无线设备*/
	DEL_WIFI_DEVICE,			/* 删除无线设备*/
	EDIT_WIFI_DEVICE			/* 修改无线设备*/
}WIFI_DEVICE_SET_TYPE_E;

#define WIFIMODULE_SIZE				4
typedef struct
{
	unsigned long	ulWifiDeviceId;							/* 无线设备编号*/
	unsigned long	ulWifiDeviceType;						/* 设备类型*/
#define WIFIDEVICETYPE_NONE			0XFFFFFFFF
#define WIFIDEVICETYPE_ALONEAP		0						/* 独立的接入模块 */
#define WIFIDEVICETYPE_BINDAP		1						/* 捆绑的接入模块 */
#define WIFIDEVICETYPE_ALONEADHOC	2						/* 独立的回传模块 */
#define WIFIDEVICETYPE_BINDADHOC	3						/* 捆绑的回传模块 */
#define WIFIDEVICETYPE_APADHOC		4						/* 接入加回传模块 */
	unsigned long	ulWifiModuleNum;						/* 模块列表中被使用的个数*/
	char			acWifiModuleName[WIFIMODULE_SIZE][8];	/* 模块名称列表*/
	unsigned long	ulWifiModuleRole[WIFIMODULE_SIZE];		/* 模块角色列表 */
}WIFI_DEVICE_T;

typedef struct
{
	WIFI_DEVICE_SET_TYPE_E	enSetType;						/* 操作类型*/
	WIFI_DEVICE_T stWifiDevice;
}WIFI_DEVICE_SET_T;

/*----------------------------------- vap set with wifiDevice ------------------------------------------*/
typedef enum
{
	ADD_VAP_2_WIFI_DEVICE,									/* 从无线设备中增加VAP */
	DEL_VAP_FROM_WIFI_DEVICE								/* 从无线设备中删除VAP */
}VAP_SET_TYPE_E;

typedef struct
{
	char			acVapName[32];							/* VAP设备名*/
	unsigned long	ulWifiDeviceId; 						/* 无线设备编号*/
	unsigned long	ulVapRole;								/* 设备的角色*/
#define	INDIE_VAP				0							/* 独立的VAP */
#define	MAIN_VAP				1							/* 主VAP */
#define	SLAVE_VAP				2							/* 从VAP */
	char			acMainVapName[32];						/* 通知无线层该从AP对应的主AP。当该VAP为从VAP时，才设置该值 */
}VAP_MANAGE_T;

typedef struct
{
	VAP_SET_TYPE_E	enSetType;								/* 操作类型*/
	VAP_MANAGE_T	stVapManage;
}VAP_ASSIGN_T;

/*---------------------------------------- auto channel list -------------------------------------------*/
#define	CHANNEL_LIST_MAX_NUM	16
typedef struct
{
	unsigned long	ulWifiDeviceId;							/* 无线设备编号*/
	unsigned long	ulChannelNum;							/* 信道列表中被使用的个数 */
	unsigned long	aulChannelList[CHANNEL_LIST_MAX_NUM];	/* 信道列表*/
}AUTO_CHANNEL_LIST_SET_T;

/*--------------------------------------- wifi algorithm para ------------------------------------------*/

/*独立的接入模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEAP_PARA_T;

/*捆绑的接入模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_BINDAP_PARA_T;

/*独立的回传模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEADHOC_PARA_T;

/*接入加回传模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_APADHOC_PARA_T;

/*捆绑回传模块的参数*/
typedef struct
{
	unsigned long ulScanTimerMinIntvl;	/*扫描定时器的最小时长-单位ms*/
	unsigned long ulScanTimerIntvl;		/*扫描定时器的时长-单位ms */
	unsigned long ulKeepRunMsgIntvl;	/*收到保活消息的时间间隔-单位ms */
	unsigned long ulMaxSendProbeNum;	/*发送的最大Probe 消息的数目*/
	unsigned long ulAcceptRssi;			/*可以接受的信号强度-单位dBm*/
	unsigned long ulMinScanPauseIntvl;	/*扫描间歇期最小时长-单位ms */
	unsigned long ulScanPauseIntvl;		/*扫描间歇期时长-单位ms */
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
		WIFI_DEVICE_BINDADHOC_PARA_T     stBindAdhocPara;             /*捆绑的回传模块*/
		WIFI_DEVICE_APADHOC_PARA_T       stApAdhocPara;
	}unAlgorithmPara;
}WIFI_DEVICE_ALGORITHM_PARA_T;

/*------------------------------------------ adhoc link stat ---------------------------------------------*/
#define IVALID_DATA        0xFFFFFFFF

#define RATE_PKT_INFO_MAX_NUM			15
//各速率上的收/发包数
typedef struct
{
	unsigned long	ulRate;						//速率
	unsigned long	ulRecvPkt;					//接收包数
	unsigned long	ulSendPkt;					//发送包数
}RATE_PKT_INFO_T;
typedef RATE_PKT_INFO_T		RATE_PKT_STAT_T[RATE_PKT_INFO_MAX_NUM];

//各功率上的发送包数
#define POWER_SEND_PKT_INFO_MAX_NUM		30
typedef struct
{
	unsigned long	ulTxPower;					//功率
	unsigned long	ulSendPkt;					//发送包数
}POWER_SEND_PKT_INFO_T;
typedef POWER_SEND_PKT_INFO_T	POWER_SEND_PKT_STAT_T[POWER_SEND_PKT_INFO_MAX_NUM];

//各RSSI的接收包数
#define RSSI_RECV_PKT_INFO_MAX_NUM		10
typedef struct
{
	unsigned long	ulRssi;						//RSSI
	unsigned long	ulRecvPkt;					//接收包数
}RSSI_RECV_PKT_INFO_T;
typedef RSSI_RECV_PKT_INFO_T	RSSI_RECV_PKT_STAT_T[RSSI_RECV_PKT_INFO_MAX_NUM];

//各信令丢包数、信令收/发包数
#define SIGNAL_PKT_INFO_MAX_NUM			20
typedef struct
{
	unsigned long	ulSignal;					//信令
	unsigned long	ulLossPkt;					//丢包数
	unsigned long	ulRecvPkt;					//接收包数
	unsigned long	ulSendPkt;					//发送包数
}SIGNAL_PKT_INFO_T;
typedef SIGNAL_PKT_INFO_T	SIGNAL_PKT_STAT_T[SIGNAL_PKT_INFO_MAX_NUM];

#define ANTENNA_NUM ((u_int8_t)2)				/*天线的数目*/

/*天线统计信息*/
typedef struct
{
	unsigned long  aulResvUCastNum[ANTENNA_NUM]; /*每个天线接收的单播包的数目*/
	unsigned long  aulSendUCastNum[ANTENNA_NUM]; /*每个天线发送的单播包的数目*/
}ANTENNA_STAT_T;

//链路统计
#define ADHOC_LINK_STAT_LIST_MAX_NUM	20
typedef struct
{
	unsigned long			ulBusinessLossPkt;	//业务丢包数
	unsigned long			ulBusinessRecvPkt;	//业务收包数
	unsigned long			ulBusinessSendPkt;	//业务发包数
	unsigned long			ulBroadcastRecvPkt;	//广播收包数
	unsigned long			ulBroadcastSendPkt;	//广播发包数
	unsigned long			ulRssi;				//RSSI
	unsigned long			ulChannel;			//工作信道
    long					lNoiseFloor;		//底噪
    unsigned char			ucWifiModuleName[32];//模块号
	char					acPeerMac[6];		//对端MAC
	RATE_PKT_STAT_T			stcRatePktStat;		//各速率上的收/发包数
	ANTENNA_STAT_T			stAntennaStat;      //天线信息
	POWER_SEND_PKT_STAT_T	stcPowerSendPktStat;//各功率上的发送包数
	RSSI_RECV_PKT_STAT_T	stcRssiRecvPktStat;	//各RSSI的接收包数
	SIGNAL_PKT_STAT_T		stcSignalPktStat;	//各信令丢包数、信令收/发包数
}ADHOC_LINK_STAT_T;

typedef struct
{
	unsigned long			ulValidNum;
	ADHOC_LINK_STAT_T		stcAdhocLinkStat;
}ADHOC_LINK_STAT_LIST_T;

typedef struct
{
    UINT32                  ulRxucNum;          /*接收点播包数目*/
    UINT32                  ulRxmcNum;          /*接收广播包数目*/
    UINT32                  ulTxucNum;          /*发送点播包数目*/
    UINT32                  ulTxmcNum;          /*发送广播包数目*/
    UINT32                  ulTxAirLostNum;     /*空口丢包数*/
    UINT32                  ulTxActLostNum;     /*主动丢包数*/
    UINT32                  ulTxReNum;          /*重传次数，只点播报文重传*/
    UINT32                  ulUserNum;          /*AP：即时接入用户个数*/
    INT32                   iNoise;             /*底噪*/
}VAP_STATS_T ;

typedef struct
{
    UINT32                  ulRxucNum;          /*接收点播包数目*/
    UINT32                  ulRxmcNum;          /*接收广播包数目*/
    UINT32                  ulTxucNum;          /*发送点播包数目*/
    UINT32                  ulTxmcNum;          /*发送广播包数目*/
    UINT32                  ulTxAirLostNum;     /*空口丢包数*/
    UINT32                  ulTxActLostNum;     /*主动丢包数*/
    UINT32                  ulTxReNum;          /*重传次数，只点播报文重传*/
    UINT32                  ulNeiNum;           /*ADHOC：即时邻居个数*/
    INT32                   iNoise;             /*底噪*/
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
		OMA_IC_STAT_INFO_T	stIcStat;	/* 2010-4-11 pyy 辽宁电信网管测试新增*/
	}unStats;
}BSS_STATS_T;

typedef struct
{
	unsigned long on;			                /* 0：禁用；1：启用；缺省为禁用*/
#define SCAN_ROGUE_SSID_OFF			0
#define SCAN_ROGUE_SSID_ON			1
	unsigned long flag;							/* flag&0x01:监听相同SSID的ROGUE AP；flag&0x02:监听隐藏
	                                             * 的SSID的ROGUE AP；flag标志位可组合使用，缺省值为0x01 */
#define MONITOR_SAME_ROGUE_SSID		0x1
#define MONITOR_HIDDEN_ROGUE_SSID	0x2
#define MONITOR_COM_ROUGE_SSID		0x1 | 0x2
	struct ieee80211_scan_ssid rogue_ssid;
	unsigned char bssid[6];						/* 指定BSSID的AP，全1无效 */
	unsigned char oui[3];						/* 指定厂商的AP，全1无效 */
	unsigned char aucRsv[3];
}WIFI_WIDS_T;

typedef struct
{
    UINT32  on;                         /* 1: 启用；0：禁用 */
    UINT32  flags;                      /* ROGUE AP定义：比特位表示法，如下宏所示 */
#define ROGUE_LOCAL_SSID    0x01        /* 本地相同SSID的AP */
#define ROGUE_HIDE_SSID     0x02        /* 隐藏SSID的AP */

    struct ieee80211_scan_ssid ssid;    /* 指定SSID的AP，允许通配符'*'，缺省为空，即全0 */
    UINT8    bssid[6];                  /* 指定BSSID的AP，全f无效 */
    UINT8    oui[3];                    /* 指定厂商的AP，全f无效 */
    UINT8    pad[3];
}ROGUE_AP_DEF_T ;


typedef struct
{
    UINT32  period;                 /* 信道扫描周期，以分钟为单位，如每15分钟扫描所有信道，最小值为5分钟 */
    UINT32  dwell;                  /* 信道停留扫描时间，以毫秒为单位，[20，1000] */
}BGSCAN_CONFIG_T;

/*只当频点配置为AUTO时，才允许配置下述参数*/
typedef struct 
{
	unsigned long	ulFrequPointQualitySwitch;		/* 信道重选周期 */
	unsigned long	ulRssiThreshold;				/* 信道重选RSSI门限 */
	long			lNoiseThreshold;				/* 信道重选底噪门限 */
}CHANNEL_REELECT_T;


/*-------------------------------------- 自定义ioctl接口的类型定义 -------------------------------------------*/
#define   IEEE80211_IOCTL_COMMON      	(SIOCDEVPRIVATE + 15)
typedef enum
{
	IOCTL_MAC_FILTER = 0,							/* MAC地址过滤 */
	IOCTL_IBSS_AUTH,								/* IBSS鉴权 */
	IOCTL_WIFIDEVICESET,            				/* 无线设备配置 */
	IOCTL_VAPSET,                   				/* VAP配置 */
	IOCTL_AUTOCHANNELLISTSET,       				/* 自适应信道配置 */
	IOCTL_ALGORITHM_PARA, 							/* 算法参数 */
	IOCTL_LINK_STAT,								/* 回传链路统计 */
	IOCTL_EVENT_LIST, 								/* 获取事件列表 */
	IOCTL_SET_USER_MAXNUM = 8,                               /*VAP级最大接入用户数目配置*/
	IOCTL_GET_ENDUSER,   							/* TC获取用户信息 */
	IOCTL_QOSMAP_SET = 11,
	IOCTL_QOSMAP_GET = 12,
	IOCTL_GET_CHANNEL_NO = 15,						/* 获取设备当前信道号 */

    /* hc modified for cmcc test 2009-7-18 */  
    IOCTL_SET_USER_MAXNUM_CARD = 17,                /*无线设备级最大接入用户数目配置*/
    IOCTL_SET_USER_MAXNUM_GLOBAL = 18,              /* AP系统级最大接入用户数目配置*/

	IOCTL_NETID_SET = 20 ,             				/* 设置合法标志 */
	IOCTL_NETID_GET = 21,              				/* 获取合法标志 */
	IOCTL_WIDS_SET = 22,              		        /* WIDS配置参数设置 */
	IOCTL_WIDS_GET = 23,              		        /* WIDS配置参数获取 */

	IOCTL_ROGUE_GET = 24,              				/* 上报非法AP信息 */
	IOCTL_SET_AP_DEL_STA_PARA = 25,					/* 删除终端配置 */
    IOCTL_VAP_STATS_GET = 30,                       /* 获取VAP统计信息 */
	IOCTL_WIFI_POWER_CTRL_SET = 31,					/* 功率控制设置 */
	IOCTL_BSS_STATS = 32,							/* 无线动态信息获取 */
	IOCTL_CHANNEL_REELECT_SET = 33,					/* 频点重选配置 */

    /* hc modified for telecom test 2009-7-6 */
    IOCTL_ROGUE_STA_GET = 40, 
    IOCTL_CLEAR_ILLEGAL_DEVICE_HISTORY = 41,
    IOCTL_CLEAR_ATTACK_HISTORY = 42,
    IOCTL_CLEAR_ATTACK_STAT = 43,

	/* 2010/08/26 fengjing add,for get ap neighbor ap list */
	IOCTL_NEIGHBORAP_GET = 54,

	IOCTL_POWERMIN_SET = 60,						/* 最小功率配置 */
    IOCTL_SCAN_NEIGHBOR = 64,                       /* 邻居自动扫描开关 */
       
    /* hc modified for telecom test 2009-7-6 */
    IOCTL_WIDS_CONFIG_SET = 70,                     /* 设置恶意AP定义 */
    IOCTL_WIDS_CONFIG_GET = 71,                     /* 获取恶意AP定义 */
    IOCTL_BGSCAN_SET = 72,                          /* 设置扫描参数 */
    IOCTL_BGSCAN_GET = 73,                          /* 获取扫描参数 */

     	IOCTL_WORKMODE_SET = 75,			/* 设置AP工作模式*/
	IOCTL_WORKMODE_GET = 76,			/* 获取AP工作模式*/


	IOCTL_GET_CHANNEL_NOSCAN_FLAG = 124,
	IOCTL_GET_DESIRED_BSSID = 128,					/* 绑定的BSSID */
	IOCTL_GET_ROAM_STAT = 129,						/* 历史关联信息 */
	IOCTL_GET_RELAY_CLIENT = 140, 					/* 代理终端信息 */
	IOCTL_SET_WMM_QOS_SWITCH = 178					/* WMM功能开关配置 */
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
		WIFI_DEVICE_ALGORITHM_PARA_T	stAlgorithmPara; 	/* 算法参数 */
		ADHOC_LINK_STAT_LIST_T			stAdhocLinkStat;	/* 回传链路统计 */
		EVENT_TRAP_MSG_LIST_T			stEventList;		/* 获取事件列表 */
		unsigned char					aaucEndUserMac[MAX_END_USER][IEEE80211_ADDR_LEN];
		unsigned char					aucQosmap[WME_NUM_AC];
		unsigned long                   ulNetId;            /* 用于识别非法接入IP */
		WIFI_WIDS_T                     stWids;             /* WID配置参数 */
		ROGUE_AP_INFO_T                 stRogueApInfo;
		ROGUE_AP_DEF_T                  stRogueApDef;       /* 设置恶意AP定义 */
		BGSCAN_CONFIG_T                 stBgScanConfig;     /* 设置扫描参数 */

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
		u_int32_t						ulPowerCtrlSet;		/*0:关闭,1:开启*/
		u_int32_t						ulWmmQosCtrlSet;	/*0:关闭,1:开启*/
		BSS_STATS_T						stBssStats;
		
		NEIGHBOR_AP_LIST_T              stNeighborAp; /* 2010/08/26 fengjing 增加:获取邻居AP */
		
		unsigned char					ucChannNo;			/* 信道 added at 3-17 */
		u_int32_t						ulPowerMin;			/* 最小发射功率 */

		/* hc modified for cmcc test 2009-7-18 */
		u_int16_t                       usMaxUserNum;       /* VAP级最大接入用户数目配置*/
        u_int32_t                       ulUserMaxCard ;     /* 无线设备级最大接入用户数目配置*/
        u_int32_t                       ulUserMaxGlobal ;   /* AP系统级最大接入用户数目配置*/
        u_int32_t                       ulScanNeighbor ;    /* 0：禁用，1：启用*/
        CHANNEL_REELECT_T				stChannelReselect;

        	u_int32_t		ulMoniMode;					/* 1：提供WLAN接入服务
												2：监视无线环境
												3：空闲时监视无线环境*/

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
* 函数名称: wifi_adhoc_link_stat_get
* 功    能: 获取回传链路层统计信息
* 参    数:
* 参数名称			   输入/输出				描述
* p_adhocLinkStatInfo      OUT             回传链路层统计信息
* 函数返回: 0代表获取成功，-1代表获取失败
* 说    明:
*/
/************************************************************************/
int wifi_adhoc_link_stat_get( char *dev, IOCTL_COMMON_DATA_T * pstIoctlData );
int wifi_vap_adhoc_stat_get( char *dev, IOCTL_COMMON_DATA_T * pstIoctlData );


/************************************************************************/
/*
* 函数名称: wifi_event_list_get
* 功    能: 获取无线事件列表
* 参    数:
* 参数名称			   输入/输出				描述
* p_eventTrapMsgInfo      OUT             无线事件列表信息
* 函数返回: 0代表获取成功，-1代表获取失败
* 说    明:
*/
/************************************************************************/
int wifi_event_list_get( char *dev, EVENT_TRAP_MSG_LIST_T * p_eventTrapMsgList );

int wifi_max_end_user_num_set_vap(char *dev, int maxEndUserNum);
/* hc modified for cmcc test */
int wifi_max_end_user_num_set_card(char *dev, int maxEndUserNum);

int wifi_max_end_user_num_set_global(char *dev, int maxEndUserNum);

int wifi_end_user_list_get(char *dev, T_endUserMac *pEndUserMacList);

int wifi_qos_map_set(char *dev, unsigned long aucQosmap[]);

/* 获取代理终端信息 */
int wifi_relay_clients_get(char *dev, RELAY_CLIENT_ENTRY_T *stat);

/* 获取历史关联信息 */
int wifi_roam_stat_get(char *dev, ROAM_STAT_T *stat);

/* 获取绑定的BSSID */
int wifi_bind_bssid_get(char *dev, BIND_BSSID_ENTRY *stat);

/* 获取信道扫描信息 */
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
