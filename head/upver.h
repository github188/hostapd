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
	char			acIp[32];									/* �豸IP */
	char			acMac[32];									/* �豸MAC */
	char			acDvId[32];				                    /* �豸ID */
}OMA_DEV_LOCATE_INFO_T;

typedef struct update_info
{
    unsigned char   ucNum;
	char			acDvId[DEVICE_SERIAL_LEN+1];
}OMA_DEV_UPDATE_INFO_T;

/* ���������豸��Ҫ����Ϣ */
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
	unsigned char	sysDeviceId[6];					/* 6��16�����ַ� */
	char			sysHwVersion[32];				/* �ַ��� */
	char			sysUbootVersion[32];			/* Uboot�汾 */
	char			sysSwVersion[32];				/* �ַ��� */
	char			sysDeviceName[32];				/* �ַ��� */
	long			dDeviceTemperature;				/* �豸�¶� */
	struct tm		sysDateTime;					/* ������ʱ���� */
	unsigned long	sysUpTime;						/* ϵͳ�ϵ絽���ڵ����� */
	unsigned long	sysCountryCode;					/* ������ */
	unsigned long	ulRunMode;						/* ����ģʽ */
#define RUN_MODE_AUTO		0
#define RUN_MODE_FAT_AP		2
#define RUN_MODE_FIT_AP		1
	/* added by laiyongxing at 2009-1-9 */
	unsigned char        ucSysNetId;                                  /* NET ID used to identify rogue ap*/
	int				iRsv[4];						/* Ԥ��λ */
} T_sysBasicSetupV1_8_7a;

typedef struct wifiDeviceBasicSetup_s_v1_8_7a 
{
	unsigned long	wifiDeviceIndex;						/* �豸��� */
	char			wifiDeviceInfo[32];						/* �豸���� */
	unsigned long	wifiDeviceType;							/* �豸���� */
	unsigned long	wifiModuleId[wifiModule_SIZE];			/* ģ��ID�б� */
	unsigned long	wifiModuleType[wifiModule_SIZE];		/* ģ�������б� */
	unsigned long	wifiModuleAbgMode[wifiModule_SIZE];		/* A/B/Gģʽ�б� */
	unsigned long	wifiModuleMaxTxRate[wifiModule_SIZE];	/* ����������б� */
	unsigned long	wifiModuleMinTxRate[wifiModule_SIZE];	/* ��С���������б� */
	unsigned long	wifiModuleMaxTxPower[wifiModule_SIZE];	/* ����书���б� */
	unsigned long	wifiModuleMinTxPower[wifiModule_SIZE];	/* ��С���书���б� */
	unsigned long	wifiModuleLimitTxPower[wifiModule_SIZE];/* ���书�ʵ����ֵ�б� */
	unsigned long	wifiModuleChannelMode[wifiModule_SIZE];	/* �����ŵ�ģʽ */
	unsigned long	wifiModuleChannelList[wifiModule_SIZE][channel_SIZE];	/* �ŵ��б� */
	unsigned long	wifiModuleABGModeType[wifiModule_SIZE];	/* A/B/G�б����� */
	int				iRsv[4];						/* Ԥ��λ */

	/* add by yzl 2009-1-14 begin*/
	unsigned long	ulMgmTrate[wifiModule_SIZE];	/* ��ѡ����֡��������  */
	unsigned long	ulMcasTrate[wifiModule_SIZE];	/* ��ѡ�㲥��������  */
	unsigned long	ulMgmtRetrys[wifiModule_SIZE];	/* ����֡�ش�����  */
	unsigned long	ulRsv[wifiModule_SIZE][4];		/* ÿ�ſ�Ԥ��4�ֽ� */
	/* add by yzl 2009-1-14 end*/
} T_wifiDeviceBasicSetupV1_8_7a;

typedef struct wifiDeviceAdvancedSetup_s_v1_8_7a
{
	unsigned long	wifiBeaconInterval;			/* BEACON��� */
	unsigned long	wifiDtimInterval;			/* DTIM��� */
	unsigned long	wifiPreambleType;			/* ǰ������ */
	unsigned long	wifFragmentationThreshold;	/* ��Ƭ���� */
	unsigned long	wifiRtsThreshold;			/* RTS���� */
	unsigned long	wifiCtsProtectionMode;		/* CTS����ģʽ */
	unsigned long	wifiMaxRetransmitCount;		/* ����ش����� */

	/* ��1.8��Ϣģ�͵Ļ������¼������������ֶΡ�ռ����2��Ԥ��λ add by yzl 2009-1-12 */
	unsigned long	ulTxDistOptSwitch;			/* ������뿪�� */
	unsigned long	ulMaxTxDistance;			/* �������� */
	int				iRsv[2];					/* Ԥ��λ */
} T_wifiDeviceAdvancedSetupV1_8_7a;

/* �㲥ת������ */
typedef struct aclBroadcastPolicy_s_v1_8_7a
{
	unsigned long ulMulticastSwitch;		/* ����ಥ�� */
#define MULTICAST_SWITCH_DISABLE		0	/* ��ȱʡΪ��*/
#define MULTICAST_SWITCH_ENABLE			1	/* �� */
	unsigned long ulBroadcastSwitch;		/* ����㲥����ARP��DHCP�� */
#define BROADCAST_SWITCH_DISABLE		0	/* ��ȱʡΪ��*/
#define BROADCAST_SWITCH_ENABLE			1	/* �� */
	unsigned long ulBMRateLimitSwitch;		/* �㲥/�ಥ���� */
#define BM_RATE_LIMIT_SWITCH_DISABLE	0	/* �� */
#define BM_RATE_LIMIT_SWITCH_ENABLE		1	/* �ǣ�ȱʡΪ��*/
	unsigned long ulMaxRate;				/* ������ʣ���/�룻ȱʡΪ50 */
} T_aclBroadcastPolicyV1_8_7a;

typedef struct wifiDeviceEntry_s_v1_8_7a
{
	unsigned long						wifiDeviceId;				/* �豸ID */
	T_wifiDeviceBasicSetupV1_8_7a		wifiDeviceBasicSetup;		/* ���߻������� */
	T_wifiDeviceAdvancedSetupV1_8_7a	wifiDeviceAdvancedSetup;	/* ���߸߼����� */
	WIDS_CONFIG_T                              stWifiDeviceWidsSetup;         /* WIDS�������� */  
	int									iRsv[4];					/* Ԥ��λ */
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
