#ifndef UP_VER_H
#define UP_VER_H

#include "agent_type.h"

#define FLASH_ERASE_SIZE    131072
#define FLAG_POS_HIGH       65536

#define DEVICE_MAX_NUM	256
#define DEVICE_SERIAL_LEN 6

#define FILE_SYSTEM_RAMDISK			0
#define FILE_SYSTEM_JFFS            1

#define UPDATE_IDLE               0
#define UPDATE_IN_PROGRESS        1
#define UPDATE_START              2
#define UPDATE_FAIL               3
#define UPDATE_SUCCESS            4

#define AP_MISC_SUCCESS           0
//#define AP_MISC_FAIL             1
#define AP_MISC_ERROR            -1

#define AP_MISC_INVALID_IP        0

#define FILE_SYSTEM_VER_PATH        "/etc/versionflag"

typedef struct sockaddr_in      SOCKADDR_IN;
typedef struct sockaddr         SOCKADDR;
typedef struct timeval          TIMEVAL;
typedef struct exist_info 
{
	char            acFunc[32];
	char			acIp[32];									/* 设备IP */
	char			acMac[32];									/* 设备MAC */
	char			acDvId[32];				                    /* 设备ID */
}OMA_DEV_LOCATE_INFO_T;

typedef struct update_info
{
    unsigned char   ucNum;
	char			acDvId[DEVICE_SERIAL_LEN+1];
}OMA_DEV_UPDATE_INFO_T;

/* 批量操作设备需要的信息 */
typedef struct patch_opt_info 
{
	char			        acFunc[32];
	char			        acName[32];
	char			        acPwd[32];
    OMA_DEV_UPDATE_INFO_T	astDevUpdateInfo[DEVICE_MAX_NUM];
}OMA_DEV_PATCH_OPT_INFO_T;


typedef struct sysBasicSetup_s_v1_8_7a
{
	long			sysDeviceType;
#define sysDeviceType_A210i 3						/* A210i */
#define sysDeviceType_A210e 4						/* A210e */
	unsigned char	sysDeviceId[6];					/* 6个16进制字符 */
	char			sysHwVersion[32];				/* 字符串 */
	char			sysUbootVersion[32];			/* Uboot版本 */
	char			sysSwVersion[32];				/* 字符串 */
	char			sysDeviceName[32];				/* 字符串 */
	long			dDeviceTemperature;				/* 设备温度 */
	struct tm		sysDateTime;					/* 年月日时分秒 */
	unsigned long	sysUpTime;						/* 系统上电到现在的秒数 */
	unsigned long	sysCountryCode;					/* 国家码 */
	unsigned long	ulRunMode;						/* 运行模式 */
#define RUN_MODE_AUTO		0
#define RUN_MODE_FAT_AP		2
#define RUN_MODE_FIT_AP		1
	/* added by laiyongxing at 2009-1-9 */
	unsigned char        ucSysNetId;                                  /* NET ID used to identify rogue ap*/
	int				iRsv[4];						/* 预留位 */
} T_sysBasicSetupV1_8_7a;

typedef struct wifiDeviceBasicSetup_s_v1_8_7a 
{
	unsigned long	wifiDeviceIndex;						/* 设备编号 */
	char			wifiDeviceInfo[32];						/* 设备描述 */
	unsigned long	wifiDeviceType;							/* 设备类型 */
	unsigned long	wifiModuleId[wifiModule_SIZE];			/* 模块ID列表 */
	unsigned long	wifiModuleType[wifiModule_SIZE];		/* 模块类型列表 */
	unsigned long	wifiModuleAbgMode[wifiModule_SIZE];		/* A/B/G模式列表 */
	unsigned long	wifiModuleMaxTxRate[wifiModule_SIZE];	/* 最大发送速率列表 */
	unsigned long	wifiModuleMinTxRate[wifiModule_SIZE];	/* 最小发送速率列表 */
	unsigned long	wifiModuleMaxTxPower[wifiModule_SIZE];	/* 最大发射功率列表 */
	unsigned long	wifiModuleMinTxPower[wifiModule_SIZE];	/* 最小发射功率列表 */
	unsigned long	wifiModuleLimitTxPower[wifiModule_SIZE];/* 发射功率的最大值列表 */
	unsigned long	wifiModuleChannelMode[wifiModule_SIZE];	/* 工作信道模式 */
	unsigned long	wifiModuleChannelList[wifiModule_SIZE][channel_SIZE];	/* 信道列表 */
	unsigned long	wifiModuleABGModeType[wifiModule_SIZE];	/* A/B/G列表类型 */
	int				iRsv[4];						/* 预留位 */

	/* add by yzl 2009-1-14 begin*/
	unsigned long	ulMgmTrate[wifiModule_SIZE];	/* 优选管理帧发送速率  */
	unsigned long	ulMcasTrate[wifiModule_SIZE];	/* 优选广播发送速率  */
	unsigned long	ulMgmtRetrys[wifiModule_SIZE];	/* 管理帧重传次数  */
	unsigned long	ulRsv[wifiModule_SIZE][4];		/* 每张卡预留4字节 */
	/* add by yzl 2009-1-14 end*/
} T_wifiDeviceBasicSetupV1_8_7a;

typedef struct wifiDeviceAdvancedSetup_s_v1_8_7a
{
	unsigned long	wifiBeaconInterval;			/* BEACON间隔 */
	unsigned long	wifiDtimInterval;			/* DTIM间隔 */
	unsigned long	wifiPreambleType;			/* 前导类型 */
	unsigned long	wifFragmentationThreshold;	/* 分片门限 */
	unsigned long	wifiRtsThreshold;			/* RTS门限 */
	unsigned long	wifiCtsProtectionMode;		/* CTS保护模式 */
	unsigned long	wifiMaxRetransmitCount;		/* 最大重传次数 */

	/* 在1.8信息模型的基础上新加了以下两个字段。占用了2个预留位 add by yzl 2009-1-12 */
	unsigned long	ulTxDistOptSwitch;			/* 传输距离开关 */
	unsigned long	ulMaxTxDistance;			/* 最大传输距离 */
	int				iRsv[2];					/* 预留位 */
} T_wifiDeviceAdvancedSetupV1_8_7a;

/* 广播转发流控 */
typedef struct aclBroadcastPolicy_s_v1_8_7a
{
	unsigned long ulMulticastSwitch;		/* 允许多播组 */
#define MULTICAST_SWITCH_DISABLE		0	/* 否：缺省为否*/
#define MULTICAST_SWITCH_ENABLE			1	/* 是 */
	unsigned long ulBroadcastSwitch;		/* 允许广播（除ARP，DHCP） */
#define BROADCAST_SWITCH_DISABLE		0	/* 否：缺省为否*/
#define BROADCAST_SWITCH_ENABLE			1	/* 是 */
	unsigned long ulBMRateLimitSwitch;		/* 广播/多播限速 */
#define BM_RATE_LIMIT_SWITCH_DISABLE	0	/* 否 */
#define BM_RATE_LIMIT_SWITCH_ENABLE		1	/* 是：缺省为是*/
	unsigned long ulMaxRate;				/* 最大速率：个/秒；缺省为50 */
} T_aclBroadcastPolicyV1_8_7a;

typedef struct wifiDeviceEntry_s_v1_8_7a
{
	unsigned long						wifiDeviceId;				/* 设备ID */
	T_wifiDeviceBasicSetupV1_8_7a		wifiDeviceBasicSetup;		/* 无线基本配置 */
	T_wifiDeviceAdvancedSetupV1_8_7a	wifiDeviceAdvancedSetup;	/* 无线高级配置 */
	WIDS_CONFIG_T                              stWifiDeviceWidsSetup;         /* WIDS参数配置 */  
	int									iRsv[4];					/* 预留位 */
} T_wifiDeviceEntryV1_8_7a;

typedef T_wifiDeviceEntryV1_8_7a T_wifiDeviceTableV1_8_7a[wifiDeviceTable_SIZE];

/*
* config file format:
*/
typedef struct configFileData_s_v1_8_7a
{
	T_configFileHeader		configFileHeader;
	T_sysBasicSetup			sysBasicSetup;
	T_sysIpSetup			sysIpSetup;
	T_sysKeeperSetup		sysKeeperSetup;
	T_sysSwServerSetup		sysServerSetup;
	T_sysSnmpSetup			sysSnmpSetup;
	T_sysVersionSetup		sysVersionSetup;
	T_sysPasswordChange		sysPasswordChange;
	T_sysPeriodOfValidity	sysPeriodOfValidity;
	char					acAppendScript[4096];
	T_sysAppendCode			sysAppendCode;
	T_wifiDeviceTableV1_8_7a		wifiDeviceTable;
	T_apVapTableRw			apVapTableRw;
	T_adhocVapTableRw		adhocVapTableRw;
	T_enetInfTable			stEnetInfTable;
	T_aclPolicySwitch		aclPolicySwitch;
	T_fclBasicSetup			stFclBasicSetup;
	T_routeBasicSetup		routerNodeSetup;
	T_routerNeighSetup		routerNeighSetup;
	T_routerHandoverSetup	routerHandoverSetup;
	T_routerMscSetup		routerMscSetup;
	T_vlanSwitch			vlanSwitch;
	T_vlanSetupList			vlanSetupList;
	T_configInforce			configInforce;
	T_capWapSetup			stCapWapSetup;
	OMA_PERF_CFG_T			stPerfCfg[PERF_COUNT];
} T_configFileDataV1_8_7a;

#endif /* UP_VER_H */
