#ifndef IEEE80211_CONFIG_COMMON_H
#define IEEE80211_CONFIG_COMMON_H

typedef struct apBasicSetup_s_i
{
/* AP_MODE_MIXED和AP_MODE_GONLY需要由ieee80211_ioctl_setparam设置
   IEEE80211_PARAM_PUREG来实现, BONLY需要由ieee80211_ioctl_setmode
   设置模式为11B模式, AP_MODE_DISABLE由系统控制模块关闭ath0设备来实现 */
 long apMode;  
#define AP_MODE_DISABLE_I 1
#define AP_MODE_MIXED_I 2
#define AP_MODE_GONLY_I 3
#define AP_MODE_BONLY_I 4

/* 暂时不实现 */
 long apStartupMode;
#define AP_STARTUP_MODE_MASTER_I 1
#define AP_STARTUP_MODE_STANDBY_I 2 

/*ieee80211_ioctl_siwessid和ieee80211_ioctl_giwessid可以设置和获取ESSID*/
 unsigned char apSsid[32];

/* ieee80211_ioctl_siwfreq和ieee80211_ioctl_giwfreq可以设置和获取Channel, 目前
   不允许设置Auto模式 */ 
 long apChannel;
#define AP_CHANNEL_CH1_I 1
#define AP_CHANNEL_CH2_I 2
#define AP_CHANNEL_CH3_I 3
#define AP_CHANNEL_CH4_I 4
#define AP_CHANNEL_CH5_I 5
#define AP_CHANNEL_CH6_I 6
#define AP_CHANNEL_CH7_I 7 
#define AP_CHANNEL_CH8_I 8
#define AP_CHANNEL_CH9_I 9
#define AP_CHANNEL_CH10_I 10
#define AP_CHANNEL_CH11_I 11
#define AP_CHANNEL_CH12_I 12
#define AP_CHANNEL_CH13_I 13
#define AP_CHANNEL_AUTO_I 14

/* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，使用
  IEEE80211_F_HIDESSID参数 */ 
 long apBroadcastSsid; 
#define AP_BROADCAST_SSID_DISABLE_I 1
#define AP_BROADCAST_SSID_ENABLE_I 2

 long apLogOption;
#define LOG_OPTION_OFF_I 1
#define LOG_OPTION_ON_I 2
} T_apBasicSetup_i;
 

typedef struct apAdvancedSetup_s_i
{
/* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，使用
  IEEE80211_PARAM_BEACON_INTERVAL参数
  有效范围25-500(TU) ???? */
 unsigned long apBeaconInterval;

/* 通过ieee80211_ioctl_siwrts和ieee80211_ioctl_giwrts设置和获取RTS门限 */
 unsigned long apRtsThreshold;

/* 通过ieee80211_ioctl_siwfrag和ieee80211_ioctl_giwfrag设置Fragment门限 */
 unsigned long apFragmentationThreshold;

/* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，使用
   IEEE80211_PARAM_DTIM_PERIOD参数
   有效范围1-15(Beacon Period) */
 unsigned long apDtimInterval;

/* 通过ieee80211_ioctl_siwrate和ieee80211_ioctl_giwrate设置和获取来实现，建议最好
  使用Auto，如果配置固定速率，需要由专业人士指导
  系统控制模块传入的apTxRate参数的单位是bps(例如速率为1Mbps，入参是1000000)
  如果0xFFFF == apTxRate，认为速率是Auto模式  */
 unsigned long apTxRate;
 #define TXRATE_AUTO_SELECTION_I  0xFFFF

/* 不支持配置和获取 */
 long apPreambleType; 
#define AP_PREAMBLE_AUTO_I 1
#define AP_PREAMBLE_SHORT_I 2
#define AP_PREAMBLE_LONG_I 3

/* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，
   使用IEEE80211_PARAM_AUTHMODE参数，AUTO == BOTH ???? */
 long apAuthenticationType;
#define AP_AUTHENTICATION_BOTH_I 1
#define AP_AUTHENTICATION_OPENSYSTEM_I 2
#define AP_AUTHENTICATION_SHAREDKEY_I 3
#define AP_AUTHENTICATION_WPAPRESHAREDKEY_I 4


/* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，
   使用IEEE80211_PARAM_PROTMODE参数 */
 long apCtsProtectionMode;
#define AP_CTSPROTECTION_MODE_DISABLE_I 1
#define AP_CTSPROTECTION_MODE_ENABLE_I 2

} T_apAdvancedSetup_i; 
 

typedef struct apSecuritySetup_s_i
{
 long apSecurity;
 /* 通过ieee80211_ioctl_setparam和ieee80211_ioctl_getparam设置和获取来实现，
   使用IEEE80211_PARAM_PRIVACY参数；
 私密性和鉴权存在关联关系，当私密性关闭时，除了OPEN，其它模式的鉴权不能生效 */
#define AP_SECURITY_DISABLE_I 1 
#define AP_SECURITY_ENABLE_I 2


 long apWpaAlgorithms;
#define AP_ALGORITHMS_WEP_I     0 /* ???? */
#define AP_WPA_ALGORITHMS_TKIP_I 1
#define AP_WPA_ALGORITHMS_AES_I  2
/* 私密性算法和鉴权模式存在关联，OPEN和SHAREKEY鉴权，只能使用WEP私密算法；
AES算法使用AES_CCM */
 long  keylen;
 unsigned char apWepKey[32];
/* 以上参数通过ieee80211_ioctl_siwencodeext和ieee80211_ioctl_giwencodeext设置和获取来实现 */ 
 
 unsigned long apKeyRenewal;
 /* 该参数不配置，Key不更新，只有WPA鉴权模式下该参数才会生效 */
} T_apSecuritySetup_i; 

 

typedef struct endUserEntry_s_i
{
 unsigned long endUserIndex;
#define INVALID_INDEX_I 0
 unsigned char endUserMac[6];
 unsigned long endUserLiveTime;

 /* 包数目 */
 unsigned long pktSendToUser;

 /* 包数目 */
 unsigned long pktRecvFromUser;
} T_endUserEntry_i;

typedef struct accessDenyEntry_s_i
{
 unsigned long accessDenyIndex;
 unsigned char accessDenyMac[6];
 unsigned char accessDenyReason[32];

 /* 使用jiffies作为单位 */
 unsigned long accessDenyTime;
} T_accessDenyEntry_i; 


typedef struct adhocBasicSetup_s_i
{
 long adhocMode;
#define ADHOC_MODE_DISABLE_I 5
#define ADHOC_MODE_AONLY_I 6
 unsigned char adhocMac[6];
 unsigned char adhocSsid[32];
 
 /* 缺少Auth设置，默认使用OPENSYSTEM  */
 
 long adhocSecurity;
#define ADHOC_SECURITY_DISABLE_I 1 
#define ADHOC_SECURITY_ENABLE_I 2

	/* 缺少私密性算法设置，固定设置为WEP ????wep key为什么？*/
 long keylen;
 unsigned char adhocWepKey[64];
 long adhocLogOptionAth;
 long adhocLogOptionWlan;
 long adhocLogOptionSecurity;
 long adhocLogOptionScan;
} T_adhocBasicSetup_i; 

typedef struct adhocAdvancedSetup_s_i
{
 long adhocChannel;
#define ADHOC_CHANNEL_CH149_I 149 
#define ADHOC_CHANNEL_CH153_I 153
#define ADHOC_CHANNEL_CH157_I 157
#define ADHOC_CHANNEL_CH161_I 161

 unsigned long adhocMaxTxPower;
 /*
    使用ieee80211_ioctl_siwtxpow设置发送功率，只有在固定功率发送情况下，才会设置最大发送功率，
    最好不要设置  ???? 不要设置怎么实现
    功率单位是dbm    
    */
  
 unsigned long adhocMinTxPower;
 /* 目前不配置 */ 
 
 /* 缺少RTS/CTS标志设置，默认设置为打开 */
 unsigned long adhocRtsThreshold;
 
 unsigned long adhocFragmentationThreshold;
 
 unsigned long adhocMaxRetransmitCount;
} T_adhocAdvancedSetup_i;

/* 邻区s/n列表 */
/* 由系统控制模块触发，进行阻塞操作，延迟1s左右，只对adhoc使用 */
typedef struct snrEntry_s_i
{
 long snrChannel;
 /* 使用1..11 149..153标识,0代表无效的信道 */
 long snrValue;
 /* 扫描得到的信噪比 */
} T_snrEntry_i; 

/* adhoc邻区列表 */
typedef struct adhocNeighborEntry_s_i
{
 long adhocNeighborIndex;
 unsigned char adhocNeighborMac[6];
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

/* ????拓扑中power level需要通过ap查询 */
/*
typedef struct meshTopology_s_r
{
	long seedNode;
#define SEED_NODE_NO_R 1
#define SEED_NODE_YES_R 2
	long powerLevel;
#define POWER_LEVEL_WEAK_R 1
#define POWER_LEVEL_MIDDLE_R 2
#define POWER_LEVEL_STRONG_R 3
	T_connEntry connEntry[MAX_CONN_ENTRY];
} T_meshTopology_r;
*/
 
typedef struct tagsysConfig
{
	enum {
		N_apBasicSetup_I = 0,
		N_apAdvancedSetup_I,
		N_apSecuritySetup_I,
		N_adhocBasicSetup_I,
		N_adhocAdvancedSetup_I
	} m;
	union {
		T_apBasicSetup_i     tapBscSetup;
		T_apAdvancedSetup_i  tapAdvSetup;
		T_apSecuritySetup_i  tapScuSetup;
		T_adhocBasicSetup_i  tadhBscSetup;
		T_adhocAdvancedSetup_i  tadhAdvSetup;
	} u;
} T_wifiConfig_i;


typedef struct wifiState_s_i
{
	enum {
		N_endUserTable_I = 0,
		N_accessDenyTable_I,
		N_snrTable_I,
		N_adhocNeighborTable_I,
		N_adhocPm_I 
	} m;
#define MAX_ENDUSER_ENTRY_I 128
#define MAX_ACCESSDENY_ENTRY_I 10
#define MAX_SNR_ENTRY_I 8
#define MAX_ADHOCNEIGHBOR_ENTRY_I 10
	union {
		T_endUserEntry_i endUserEntry[MAX_ENDUSER_ENTRY_I];
		T_accessDenyEntry_i accessDenyEntry[MAX_ACCESSDENY_ENTRY_I]; 
		T_snrEntry_i snrEntry[MAX_SNR_ENTRY_I]; 
		T_adhocNeighborEntry_i adhocNeighborEntry[MAX_ADHOCNEIGHBOR_ENTRY_I]; 
		T_adhocPm_i adhocPm; 
	} u;
} T_wifiState_i;

typedef struct{
	u_int32_t ulNum;
#define IOCTL_MAX_DENYNUM 10	
	u_int8_t   maclist[IOCTL_MAX_DENYNUM][6];
} TmacDenyList;


/* 接口函数 */

/* 当无线模块加载成功后，系统控制模块调用此初始化函数，
    必须在参数配置和查询之前完成该调用 */
int ieee80211_paratbl_init(void);

/* 系统参数配置函数
  dev: 字符串，设备名
  ptsysConfig: 系统配置参数
 */
int ieee80211_setcfg(char *dev, T_wifiConfig_i *ptConfig);

/* 系统参数查询函数
  dev: 字符串，设备名
  ptsysConfig: 系统查询参数
 */
int ieee80211_getcfg(char *dev, T_wifiConfig_i *ptConfig);

int denyListClr(char *dev);
int denyListAdd(char *dev, TmacDenyList *ptList);

/* 获得统计信息、状态信息 */
int ieee80211_state_get(char *dev, T_wifiState_i *ptState);


#endif
