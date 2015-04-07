/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  关系表方法头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
* 2009-3-3	  潘妍艳		     新增AP2.0功能
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AP_DB_TABLE_H
#define  _AP_DB_TABLE_H

/******************************************************************************/
#ifdef APP_PROJ_AC
#define AC_DB_WTP_NUM_MAX		(AC_WTP_NUM_MAX)	
#else
#define AC_DB_WTP_NUM_MAX		((UINT32)1)	
#endif


/*AP 关系表容量宏定义开始*/
#define AC_DB_WTPSYSBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP基本配置表表容量*/
#define AC_DB_WTPDYNINFO_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP状态信息表*/
#define AC_DB_WTPROGUE_CAPACITY						(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* AC检测到的未注册AP列表*/
#define AC_DB_WTPSYSIPSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP IP配置表表容量*/
#define AC_DB_WTPSYSLOADBALANCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP 负载均衡配置表表容量*/
#define AC_DB_WTPSYSLOGSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP 日志管理配置表表容量*/
#define AC_DB_WTPSYSSWSERVERSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP 软件服务器配置表表容量*/
#define AC_DB_WTPSYSSNTPSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP  SNTP参数配置表表容量*/

#ifdef BIG_AC
#define AC_DB_WTPWIFIDEVICEBASICSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备基本配置表表容量*/
#define AC_DB_WTPWIFIDEVICECHANNELSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备无线信道配置表表容量*/
#define AC_DB_WTPWIFIDEVICERATESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备无线速率配置表表容量*/
#define AC_DB_WTPWIFIDEVICEPOWERSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备无线功率配置表表容量*/ 
#define AC_DB_WTPWIFIDEVICEADVANCEDSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备无线高级配置表表容量*/
#define AC_DB_WTPWIFIDEVICEWIDSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备WIDS配置表表容量*/
#define AC_DB_WTPWIFIDEVICERESOURCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 无线设备无线资源管理配置表表容量*/
#else
#define AC_DB_WTPWIFIDEVICEBASICSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备基本配置表表容量*/
#define AC_DB_WTPWIFIDEVICECHANNELSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备无线信道配置表表容量*/
#define AC_DB_WTPWIFIDEVICERATESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备无线速率配置表表容量*/
#define AC_DB_WTPWIFIDEVICEPOWERSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备无线功率配置表表容量*/ 
#define AC_DB_WTPWIFIDEVICEADVANCEDSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备无线高级配置表表容量*/
#define AC_DB_WTPWIFIDEVICEWIDSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备WIDS配置表表容量*/
#define AC_DB_WTPWIFIDEVICERESOURCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP 无线设备无线资源管理配置表表容量*/
#endif

#define AC_DB_WTPAPBASICSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP基本配置表表容量*/ 
#define AC_DB_WTPAPSECURITYSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP安全配置表表容量*/
#define AC_DB_WTPAPADVANCEDSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP高级配置表表容量*/

#ifdef BIG_AC
#define AC_DB_WTPADHOCBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ADHOC基本配置表表容量*/
#define AC_DB_WTPADHOCSECURITYSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ADHOC安全配置表表容量*/
#else
#define AC_DB_WTPADHOCBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP ADHOC基本配置表表容量*/
#define AC_DB_WTPADHOCSECURITYSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP ADHOC安全配置表表容量*/
#endif

#define AC_DB_WTPENETBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP 以太网口配置表表容量*/

#define AC_DB_WTPROUTEBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP路由基本配置表表容量*/
#define AC_DB_WTPROUTENEIGHBORSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP路由邻居管理配置表表容量*/
#define AC_DB_WTPROUTEHANDOVERSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP路由切换管理配置表表容量*/
#define AC_DB_WTPROUTEDEVICEMSCSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP路由设备主从管理配置表表容量*/

#define AC_DB_WTPCAPWAPSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP CAPWAP配置表表容量*/

#ifdef BIG_AC
#define AC_DB_WTPALARMFILTERSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)64)	/* 告警过滤配置表表容量*/
#define AC_DB_WTPALARMTHRESHOLDSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)		/* 告警门限配置表表容量*/
#define AC_DB_WTPPERFCOUNTERGROUPINFOSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* 计数器组配置表表容量*/
#else
#define AC_DB_WTPALARMFILTERSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)128)	/* 告警过滤配置表表容量*/
#define AC_DB_WTPALARMTHRESHOLDSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)		/* 告警门限配置表表容量*/
#define AC_DB_WTPPERFCOUNTERGROUPINFOSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)128)	/* 计数器组配置表表容量*/
#endif

/* add by gwx 2012-11-29 for AP/VAP流控*/
#define AC_DB_WTPAPVAPMACFLOWCTRLSETUP_CAPACITY		(4096*16)		/* VAP-MAC用户流控表表容量*/

/* add by gwx 2013-10-11 for task1076 企业网流控需求*/
#define AC_DB_WTPAPUSERGROUPQOSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)9)	/* WTP VAP基本配置表表容量*/ 
/* add by gwx 2013-11-27 for task1153 */
#define AC_DB_WTPSYSLOCATORSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* AP定位服务配置表容量*/

/*AP 关系表容量宏定义结束*/
/******************************************************************************/

/******************************************************************************/
/* AP 关系表结构体定义开始*/
/* WTP基本配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	CHAR	acWtpNEId[32];	/* AP 网元编码*/
	UINT32	ulDeviceType  ;
	UINT8	aucDeviceId[6];	/* 设备序列号*/
	UINT8	aucResv[2];

	CHAR	acContact[64];	/*	设备维护联系人*/
	CHAR	acLocation[64];	/*	设备所在位置*/
	CHAR	acCounty[64];	/* add by gwx 2011-12-9 设备所在区县*/

	UINT32	ulMaxStaNum;	/* 最大允许接入的用户数 */
	CHAR	acHwVersion[32];
	CHAR	acUbootVersion[32];
	CHAR	acSwVersion[32];
	CHAR	acDeviceName[64];
	UINT32	ulCountryCode;
	UINT32	ulRunMode;		/* 0:自适应	1:集中转发	2:本地转发*/
	UINT32	ulApTrafficVlan;	/* 0~4094 	
								0:表示不打VLAN 
								其它:表示打相应的VLAN Tag */
	
	UINT32	ulLegalId;

	/* 2010/05/12 fengjing add */	
	UINT32	ulCollectSwitch;	/* 2010-4-10 pyy 新增: 实时采集开关*/
	/* add by gwx 2013-1-8 for task368本地转发时AP离线也不广播业务SSID */
	UINT32 	ulDisSsidSwitch;  /* AP离线关闭SSID开关0禁用，1开启默认开启*/
	/* add by gwx 2013-3-27 for bug2242 */
	UINT32 	ulLinkOffRestartTime;		/* AP断链重启时间，默认3600s，最小值300s */
	UINT32 	ulRptUserTrafficTime; 	/* AP上报用户流量时间间隔，单位秒*/
	/* add by gwx 2012-11-29 for AP/VAP级流控*/
	UINT32	ulFlowCtrlLevel;		/*带宽控制级别,0:sta, 1:VAP, 2:AP */
	UINT32	ulTotalUpBandMax;	/* 上行总带宽控制(kpbs) */
	UINT32	ulTotalDownBandMax;	/* 下行总带宽控制(kpbs) */
	/* add by gwx 2013-11-27 for task1143 */
	UINT32	ulL2EnableIsolate;	/* 用户二层隔离开关*/
	/* add by gwx 2013-11-26 for task1150 */
	UINT32	ulApCapwapMode;	/* capwap包分片模式配置*/
	UINT32	ulApUserEthVlan;		/* add by gwx 2014-6-5 AP下联有线口vlan*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
	UINT32	ulCurAcId;
	UINT32	ulCfgVersion;	/* 配置数据版本号*/
}AC_DB_TBL_WTPSYSBASICSETUP_T;

typedef struct 
{	
	UINT32	ulWtpId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32	ulCommPort;	/* 通讯端口号 add by gwx 2013-4-7 fot task668*/
	UINT8	aucCommIp[4];		/* 通讯IP  add by gwx 2013-4-7 fot task668 */
	UINT32	ulState;			/* 0: 空闲1: 正在初始化2: 正常服务中*/
							/* 0: 离线 1: 连接中 2:在线 */
	UINT32	ulAssoState;		/* AP-AC关联状态
								NORMAL				0	 关联状态正常
								NODISCOVERY			1	 没有收到发现请求
								NOJOIN				2	没有收到连接请求
								CONNAUTHFAIL		3	 鉴权失败
								OTHER				4	 其它原因
								*/
	UINT32	ulAcLanId;		/* AP 连接的AC端口号*/
	UINT32	ulVlanId;		/* 2009-12-14 pyy 新增: AP接入的VLAN ID */
	UINT32	ulBeginTime;		/* 本状态开始时间*/

	UINT32	ulRegisterTime;			/*		注册时间	，首次连接到AC的时间*/
	UINT32	ulLastConnTime;			/*		上次启动时间，最后一次关联AC的时间*/
	UINT32	ulLastVerUpdateTime;	/*		上次升级版本时间	Oma通知dbs */
	UINT32	ulLastCfgUpdateTime;	/*		上次更新配置时间	Oma通知dbs */

	UINT32	ulOfflineNum;			/* 累计离线次数*/

	CHAR     	acSwVersion[32];		//AP 当前软件版本号
     	CHAR	acTargetVersion[32];   // AP设备目标软件版本号

     	/* 2010-12-9 pyy 新增*/
     	UINT32	ulLastOnlineTime;		/* 最近一次上线的时间点*/
     	UINT32	ulLastOfflineTime;		/* 最近一次离线的时间点*/
     	UINT32	ulTotalOfflineTime;		/* 运营状态AP退服时长(分钟),在线后离线的时长（应该去除版本升级时间） */
     	UINT32	ulTotalOnlineTime;		/* 运营状态AP总时长(分钟)（在线总时长）,累计时长 */   
#if 0 
		CHAR	acCurChannelList[32];	/* add by gwx 2014-8-7 AP当前使用信道列表*/
#else
	CHAR	acWifi0Channel[32];
	CHAR	acWifi1Channel[32];
#endif
} AC_DB_TBL_WTPDYNINFO_T;


/* AC检测到的未注册AP列表*/
typedef struct
{
	UINT32  	ulWtpId;      			//AP设备ID
     	UINT8    	aucWtpIp[4];  		/* AP 设备IP */
		UINT8	aucSrcIp[4];			/* add by gwx 2014-10-17 通信IP */
		UINT32	ulSrcPort;				/* add by gwx 2014-10-17 通信端口*/
     	UINT32   ulIpOrigin;   			// AP IP配置方式  
     	UINT8    	aucMac[6];         		/* AP 设备MAC */
     	UINT8    	aucResv0[2];  		/* 填充字节*/
     	UINT32  	ulWtpModel;   		//AP设备型号
     	UINT8   	aucWtpSn[6];  		//AP设备序列号
     	UINT8    	aucResv[2];
     	UINT32   ulDisType;    			// AC发现方式
     	CHAR     	acSwVersion[32];		//AP 当前软件版本号
     	CHAR	acTargetVersion[32];   // AP设备目标软件版本号
     	UINT32  	ulWtpState;   		//AP设备状态
     	UINT32	ulRejectReason;		/* 拒绝接入原因 */
			                                 /*
			                                 1:设备ID不一致
			                                 2:密码不一致
			                                 3:设备型号不一致
			                                 4:设备序列号不一致
			                                 */
	UINT32   ulAcLanId;    /* AC 端口
                       0-16，显示LANx
                       >=16，则显示N/A*/
	UINT32	ulVlanId;		/* 2009-12-14 pyy 新增: AP接入的VLAN ID */
    	UINT32  ulBeginTime;        		//该状态开始时间
    	UINT32  ulStatePeriod;      		//该状态持续时间
     	UINT32  ulStaNum;           			//当前接入用户数
     	UINT32   ulStaAccNum;  			/* 用户接入次数*/
    	UINT32  ulStaOnlineTime;    		/* 用户总在线时长, 单位：秒 */
     	UINT32   ulRegisterTime;			/*       注册时间 ，首次连接到AC的时间*/
     	UINT32   ulLastConnTime;			/*       上次启动时间，最后一次关联AC的时间*/
     	UINT32   ulLastVerUpdateTime;   	/*       上次升级版本时间   Oma通知dbs*/
     	UINT32   ulLastCfgUpdateTime;   	/*       上次更新配置时间   Oma通知dbs */
	/* add by gwx 2014-3-26 for AP一键注册begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for AP一键注册end*/
     	
} AC_DB_TBL_WTPROGUEAP_T;


/* WTP IP配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulIpOrigin;
	UINT8	aucIpAddr[4];
	UINT8	aucNetMask[4];
	UINT8	aucDefaultGw[4];
	UINT8	aucPrimaryDns[4];	/*	主DNS服务器	*/
	UINT8	aucSecondaryDns[4];	/*	从DNS服务器	*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSIPSETUP_T;

/* WTP 负载均衡配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulLbUserNumSwitch;	/*	用户数均衡控制开关*/
	UINT32	ulUserNumPermitted;	/*	用户数均衡启动门限*/
	UINT32	ulUserNumOffsetThreshold;/*	用户数偏差门限*/
	UINT32	ulUserNumDynamic;		/* 用户数动态负荷均衡*/
	UINT32	ulLbUserQosSwitch;		/*流量均衡控制开关*/
	UINT32	ulUserQosPermitted;		/*	流量均衡启动门限*/
	UINT32	ulUserQosOffsetThreshold;	/*	流量偏差门限*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSLOADBALANCESETUP_T;

/* WTP LOG管理配置表*/
typedef struct {
	UINT32	ulWtpId;		/* 设备ID */

	UINT32	ulLogLevel;		/*	级别开关	*/
	UINT32	ulLogModule;	/*	模块开关	*/
	UINT32	ulLogToStdOut;	/*	是否打印到标准输出	*/
	UINT32	ulLogToServer;	/*	是否发送到日志服务器	*/
	UINT8	aucLogSvrIp[4];	/*	日志服务器IP地址	*/
	UINT32	ulLogSvrPort;	/*	日志服务器端口号	*/
	UINT32	ulLogTransType;	/*	日志传输类型	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_WTPSYSLOGSETUP_T;

/* WTP软件服务器配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT8	aucFtpServerIpAddr[4];
	UINT32	ulFtpServerPort;
	CHAR	acFtpUserName[32];	/*	FTP用户名	*/
	CHAR	acFtpPassword[32];	/*	FTP密码	*/
	CHAR	acSwFileName[128];	/*	文件名	*/

	CHAR	acSpecificSwVersion[32];
	UINT32	ulUpgradeStrategy;
	UINT32	ulActivationPolicy;	/* 生效方式:
								0：立即重启生效
								1：手工重启生效
								2：延迟生效
								*/
	UINT32	ulActivationTime;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSSWSERVERSETUP_T;

/* WTP SNTP配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulEnableSntp;
	UINT8	aucSntpServerIp[4];
	UINT32	ulPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSSNTPSETUP_T;

typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulEnableSntp;
	UINT8	aucSntpServerIp[4];
	UINT32	ulPeriod;
	CHAR	acUserName[32];
	CHAR	acNetworkName[32];
	CHAR	acPassword[32];
	UINT32	ulDnsMode;
	CHAR	acServiceName[32];
	CHAR	acAcName[32];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSPPPOESETUP_T;

/* WTP 无线设备基本配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	CHAR	acWifiDeviceInfo[32];
	UINT32	ulWifiDeviceType;
	UINT32	ulMaxStaNum;
	
	UINT32	ulWifiDeviceRunMode;
	UINT32	ulWifiModuleNum;
	UINT32	aulWifiModuleId[4];
	UINT32	aulWifiModuleType[4];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
}AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T;

/* WTP无线设备无线信道配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiAbgMode;
	UINT32	ulWifiChannelMode;
	UINT32	ulWifiTurboMode;
	UINT32	ulWifiChannelType;
	UINT32	aulWifiChannel[16];

	UINT32	ulFrequPointQualitySwitch;	/*	信道重选周期	*/
	UINT32	ulRssiThreshold;				/*	信道重选RSSI门限	*/
	UINT32	ulNoiseThreshold;			/*	信道重选底噪门限	*/

	UINT32	ulWifiAbgModeType;


	UINT32	ulBand;	/* 频宽 	1：20MHz
								2：20/40MHz（自动）
 								1：20MHz
					*/
	UINT32	ulRFNum;	/*  空间流数量 1~4 */
	UINT32	ulShortGI;	/* SGI功能开关
 							0：禁用
							1：启用*/
	UINT32	ulAMPDU;	/* A-MPDU功能开关
 							0：禁用
							1：启用
						*/
	UINT32	ulAMSDU;	/* A-MSDU功能开关
 						 0：禁用
						1：启用
						*/
 	UINT32	ulOnly11n;	/* 仅11n用户接入功能
 							 0：禁用
							1：启用
							 启用时，只有11n终端可以关联，非11n终端无法关联
						*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T;

/* WTP无线设备无线速率配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	/* add by gwx 2012-12-26 for task336 无线速率优化*/
	UINT32	ulStaUpRateMin;
	UINT32 	ulStaDownRateMin;
	
	//UINT32	ulWifiMaxTxRate;
	UINT32	ulWifiMgmTrate;
	UINT32	ulWifiMcasTrate;
	UINT32	ulWifiMgmtRetrys;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICERATESETUP_T;

/* WTP无线设备无线功率配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiLimitTxPower;	/* 最大发射功率*/
	UINT32	ulWifiMaxTxPower;	/* 功率衰减配置 */

	UINT32	ulInterfereDetectSwitch;	/*	发射功率自动调整		0：禁用1：启用*/
	UINT32	ulInterfereDetectPeriod;	/*	功率调整周期		1~60 */
	UINT32	ulMaxInterferePermitted;	/*	功率调整的目标RSSI		>0 */
	UINT32	ulRssiWaveRange;		/*	目标RSSI波动范围		3～10 */
	UINT32	ulPowerCompensationSwitch;	/*	相邻覆盖补偿功能		0：禁用1：启用*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulDynPower;
}AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T;


/* WTP 无线设备无线高级配置*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiBeaconInterval;
	UINT32	ulWifiDtimInterval;
	UINT32	ulWifiPreambleType;
	UINT32	ulWifiFragmThreshold;
	UINT32	ulWifiRtsThreshold;
	UINT32	ulLongRtsThreshold;	/* 长帧重传门限*/
	UINT32	ulShortRtsThreshold;	/* 短帧重传门限*/
	UINT32	ulCacheTime;		/*	接收数据包生存期*/

	UINT32	ulWifiCtsProtectionMode;
	UINT32	ulTxDistOptSwitch;
	UINT32	ulMaxTxDistance;

	/* add by gwx 2014-7-30 */
	UINT32	ul11nHigherPri;		/* 11n接入优先开关0关闭1开启，默认关闭*/
	UINT32	ul5GHigherPri;		/* 5G接入优先开关0关闭1开启，默认关闭*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T;

/* WTP 无线设备WIDS配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;


	/* 可疑终端*/
	UINT32	ulDosAttackDetectSwitch;
	UINT32	ulDosAttackPeriod;		/*	泛洪攻击统计周期		>0	60	秒*/
	UINT32	ulDosAttackThreshold;	/*	泛洪攻击判定门限		>0	30	*/

	UINT32	ulDosAttackDefenseSwitch;
	UINT32	ulInvalidTerminalAgeingTime;

	UINT32	ulSpoofAttackDetectSwitch;	/* Spoof攻击检测开关*/
	UINT32	ulWeekIVAttackDetectSwitch;	/* Week IV检测开关*/
 	UINT32	ulStaDisturbDetectSwitch;		/* 终端干扰检测开关*/
	UINT32	ulStaDisturbLimit;			/* 终端干扰门限,包速率:pps */

	/* 2010/07/01 fengjing cmcc test */
    UINT32  ulAPInterfNumThreshhd;      /* AP干扰告警门限 */
	UINT32  ulStaInterfNumThreshhd;     /* 终端干扰告警门限 */
	INT32   lAPCoInterfThreshhd;        /* AP同频干扰告警门限 */  
	INT32   lAPNeiborInterfThreshhd;    /* AP邻频干扰告警门限 */
	
	UINT32	ulMacNum;					/* 合法终端MAC数目*/
	UINT8 	aaucMac[16][8];				/* 合法终端MAC列表*/

	/* 恶意AP */
	UINT32	ulInvalidApDetectSwitch;		/* 可疑AP检测*/
	
	UINT32	ulSsidNum;					/* 合法AP SSID数目*/
 	UINT8	aaucSsid[16][32];				/* 合法 AP SSID列表*/ 
	UINT32	ulBssidNum;					/* 合法 AP BSSID数目*/
 	UINT8	aaucBssid[16][8];			 /*合法AP BSSID列表*/ 
	UINT32	ulListOuiNum;				/* 合法AP OUI数目*/
 	UINT8	aaucOui[16][4];				/*合法AP OUI列表*/
 
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T;

/* WTP 无线设备无线资源管理配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulMoniMode;					/* 无线环境监测模式 
										1：提供WLAN接入服务
										2：监视无线环境
										3：空闲时监视无线环境
										*/
										
	UINT32	aulDiffScanChannelList[16];
	UINT32	ulDiffScanInterval;
	UINT32	ulDiffScanResidenceTime;

	/* 同频扫描*/
	UINT32	ulSameScanInterval;
	UINT32	ulNeighAutoScanSwitch;	/*	启用邻居自动扫描	*/
	UINT32	ulNeighRssiMin;			/*	邻居信号强度最小门限	*/
	UINT32	ulNeighRssiWave;		/*	邻居信号强度波动范围	*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T;
 
/* WTP VAP基本配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulRunMode;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	CHAR	acSsid[32];
	UINT32	ulBroadcastSsid;
	UINT32	ulMaxSimultUsers;	/*	最大允许接入的用户数	*/
	UINT32	ulMaxSimultTraffic;		/*	最大流量	*/

	/* add by gwx 2012-11-29 for AP/VAP 级流控*/
	UINT32	ulTotalUpBandMax;		/* 上行总带宽控制(kbps) */
	UINT32	ulTotalDownBandMax;	/* 下行总带宽控制(kbps) */
	/* 2010-4-19 pyy 新增*/
	UINT32	ulTrafficMode;		/* 业务转发模式	1:集中转发 2:本地转发*/
	UINT32	ulApTrafficVlan;		/* 业务VLAN  0~4094 */
	UINT32	ulPrdOff;			/* 是否定期关闭*/
	UINT32	ulStartTime;			/*	起始时间*/
	UINT32	ulEndTime;			/*	结束时间*/
	/* add by gwx 2013-1-8 for task369瘦AP需去除管理SSID“management”*/
	UINT32 	ulWifiEnable;	/* ssid becon开关0:关闭1:开启,默认开启*/
	/* add by gwx 2013-12-10 for task1170 */
	UINT32	ulMacFilterType;		/* 用户接入策略0:无策略1:白名单2:黑名单3:白名单OUI 4:黑名单OUI */
	UINT32	ulUserMacNum;		/* MAC地址数目*/
	UINT8	aaucUserMac[32][6];	/* MAC地址*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
}AC_DB_TBL_WTPAPBASICSETUP_T;


/* WTP VAP安全配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulAuthenticationType;
	UINT32	ulSecurityMode;
	UINT32	ulWapiSetupId;	/*	WAPI协议配置		来自acWapiSetup表	表中第一个	*/
	UINT32	ulCertFileId;		/*	WAPI证书		来自acWapiCertFile表	表中第一个	*/
	CHAR	acWapiPsk[64];	/*	WAPI PSK口令			wapi_psk_password	长度：8 -- 64*/

	CHAR	acWpaKey[64];
	UINT32	ulWpaKeyRenewal;
	UINT32	ulWepKeyLen;
	UINT32	ulWepKeyFormat;
	CHAR	acWepKey[26];
	UINT8	aucResv[2];
	UINT32	ulWepKeyIndex;
	UINT32	ul8021xMode;
	UINT32	ulEapolVer;
	UINT32	ulEapAuthPeriod;
	UINT32	ulWepBroadcastKeyLen;
	UINT32	ulWepUnicastKeyLen;
	UINT32	ulWepRekeyPeriod;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPSECURITYSETUP_T;

/* WTP VAP高级配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulPrivCap;
	UINT32	ulPowerCtrl;
	UINT32	ulEndUserTime;
	UINT32	ulWmmQos;
	UINT32	ulQosType;
	UINT32	ulAcLowLimit;
	UINT32	ulAcUpLimit;
	UINT32 	ulRxRateLimit;	/* add by gwx 2012-11-27 用户接入AP下行速率限制*/
	UINT32	ulTxRateLimit;	/* add by gwx 2012-11-27 用户接入AP上行速率限制*/
	UINT32	ulAcInterval;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPADVANCEDSETUP_T;

/* WTP VAP MAC过滤策略配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulMacFilterSwitch;
	UINT32	ulMacFilterDefaultPolicy;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPMACFILTERSETUP_T;

/* WTP VAP MAC过滤列表配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT8	aucMacAddr[6];
	UINT8	aucResv[2];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPMACFILTERLISTSETUP_T;

/* WTP VAP统计关系表结构体定义 : 动态表*/
typedef struct {
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;
    
    	UINT32  ulOnlineTime;   /* 统计间隔内VAP上所有用户的在线时间之和, 单位: s */
    	UINT32  ulUpTraffic;    /* 统计间隔内VAP上行速率, 单位:Kbps */
    	UINT32  ulDownTraffic;  /* 统计间隔内VAP下行速率, 单位Kbps */

    	UINT32  ulStatCounter;      /* 在线用户数统计次数 */
    	UINT32  ulOnlineUserNum;    /* 当前实时在线用户数 */

	UINT32	ulUserNum;		/* 在线用户数统计值 */
	UINT32	ulUserInNum;	/* 用户接入次数*/
	UINT32	ulUserOutNum;	/* 用户离开次数*/
#if 0
	/* 2010-12-9 pyy: 新增WEB认证相关统计*/
	UINT32 	ulOfflineUserNum;   	/* WEB认证用户异常下线次数*/
    	UINT32 	ulAuthReq;			/* WEB认证请求数 */
    	UINT32 	ulAuthSucc;			/* WEB认证成功数  */
    	
    	/* 2011-1-12 pyy add */
    	UINT32	ulWebOnlineTime;	/* VAP下所有用户的累计WEB认证在线时长(用户在线时间) , 单位:秒 */
#endif
#if 0
	/* 在线用户数 */
	UINT32 	ulPortalOnlineUserNum;    		/*当前通过WEB认证的在线用户数*/
	UINT32 	ulFreeOnlineUserNum;    		/*当前免认证的在线用户数*/
	UINT32 	ulAssociateOnlineUserNum;    	/*当前通过关联认证的在线用户数*/
	UINT32 	ulMacOnlineUserNum;    		/*当前通过MAC认证的在线用户数*/
#endif
	
	/* 异常下线次数 */
	UINT32 	ulPortalOfflineUserNum;   		/*Portal认证用户异常下线次数*/
	UINT32 	ulFreeOfflineUserNum;   		/*免认证用户异常下线次数*/
	UINT32 	ulAssociateOfflineUserNum;   	/*关联认证用户异常下线次数*/
	UINT32 	ulMacOfflineUserNum;   		/*MAC认证用户异常下线次数*/
	
	/* 认证请求数 */
	UINT32 	ulPortalAuthReq;          		/*Portal认证请求数*/
	UINT32 	ulAssociateAuthReq;          	/*关联认证请求数*/
	UINT32 	ulMacAuthReq;          		/*MAC认证请求数*/
	
	/* 认证成功数 */
	UINT32 	ulPortalAuthSucc;         		/*Portal认证成功数*/
	UINT32 	ulAssociateAuthSucc;         	/*关联认证成功数*/
	UINT32 	ulMacAuthSucc;         		/*MAC认证成功数*/
#if 0
	UINT32 	ulPortalAuthFail;         		/*Portal认证失败数*/
	UINT32 	ulAssociateAuthFail;         	/*关联认证失败数*/
	UINT32 	ulMacAuthFail;         		/*MAC认证失败数*/
#endif	
	/* 用户总在线时长 */
	UINT32 	ulPortalTotalOnlineTime;  		/*Portal认证用户总在线时长*/
	UINT32	ulFreeTotalOnlineTime;  		/*免认证用户总在线时长*/
	UINT32 	ulAssociateTotalOnlineTime;  	/*关联认证用户总在线时长*/
	UINT32 	ulMacTotalOnlineTime;  		/*MAC认证用户总在线时长*/

	/* add by gwx 2014-6-23 */
	UINT32	ulCurUserNum;	/* 当前用户接入数for 用户组流控*/
		
    	UINT32  ulMOC;
    	UINT8   aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPSTAT_T;


/* VAP用户连接统计/空口收发统计信息*/
typedef struct
{	
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;

    	/* 空口收发统计*/
	UINT32	ulUpByte;				/*	上行总流量*/
	UINT32	ulDownByte;				/*	下行总流量*/
	UINT32	ulUpFrame;				/*	上行总帧数*/
	UINT32	ulUpErrFrame;			/*	上行错误帧数*/
	UINT32	ulUpDiscardFrame;		/*	上行丢帧数*/
	UINT32	ulUpRetransFrame;		/*	上行重传帧数*/
	UINT32	ulDownFrame;			/*	下行总帧数*/
	UINT32	ulDownErrFrame;			/*	下行错误帧数*/
	UINT32	ulDownDiscardFrame;	/*	下行丢帧数*/
	UINT32	ulDownRetransFrame;	/*	下行重传帧数*/
	UINT32	ulUpAssoFrame;			/* 上行关联帧数*/
	UINT32	ulDownAssoFrame;		/* 下行关联帧数*/

	/* 用户连接统计*/
	UINT32	ulAccessTimes;		/*	AP的无线用户链接次数*/
	UINT32	ulAccessFailTimes;	/*	AP的无线用户链接失败次数*/
	UINT32	ulAccessRetryTimes;	/*	AP的无线用户重链接次数*/
	UINT32	ulAccessDenyTimes;	/*	AP的无线用户链接拒绝次数*/
	UINT32	ulAccessOutTimes1;	/*	因用户离开而导致解关联的次数*/
	UINT32	ulAccessOutTimes2;	/*	因AP能力不足而导致解关联的次数*/
	UINT32	ulAccessOutTimes3;	/*	因异常情况而导致解关联的次数*/
	UINT32	ulAccessOutTimes4;	/*	其它原因导致解关联的次数*/
} AC_DB_TBL_WTPAPWIFISTAT_T;


/* WTP ADHOC基本配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulAdhocId;
	UINT32	ulRunMode;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	CHAR	acSsid[32];
	UINT32	ulBroadcastSsid;
	UINT32	ulWifiArithmeticMode;
	UINT32	ulAntennaMode;
	UINT32	ulMeshType;
	UINT32	ulWmmQos;
	UINT32	ulQosType;
	UINT32	ulPrivCap;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPADHOCBASICSETUP_T;


/* WTP ADHOC安全配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulAdhocId;
	UINT32	ulAuthenticationType;
	UINT32	ulWepKeyLen;
	CHAR	acWepKey[32];
	UINT32	ulDataEncrypt;
	UINT32	ulAuthenticationTimeout;
	UINT32	ulAuthenticationRetry;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPADHOCSECURITYSETUP_T;


/* WTP 以太网口配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulEnetPortId;
	UINT32	ulEnetRunMode;
	UINT32	ulSpeedUplex;
	UINT32	ulEnetState;
	UINT32	ulPrivCap;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPENETBASICSETUP_T;

/* WTP路由基本配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulNodeGwRunMode;
	UINT32	ulNetDiameter;
	UINT8	aucRouteFavorFatherMac[6];
	UINT8	aucResv1[2];	
	
	UINT32	ulRouteFavorMinCost;
	UINT8	aucDeviceId[6];
	UINT8	aucResv2[2];	

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEBASICSETUP_T;

/* WTP路由邻居管理配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteMinNeighborPathcost;
	UINT32	ulRouteHelloInterval;
	UINT32	ulRouteHelloCombine;
	UINT32	ulRouteNeighScanThreshold;
	UINT32	ulRouteNeighScanInterval;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTENEIGHBORSETUP_T;

/* WTP路由切换管理配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteHigh4father;
	UINT32	ulRouteLow4father;
	UINT32	ulRouteHoldQuality;
	UINT32	ulRouteHoldTime;
	UINT32	ulRouteDuxPathCost;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEHANDOVERSETUP_T;

/* WTP路由设备主从管理配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteMsRunMode;
	UINT32	ulRouteMsDeviceName;
	UINT32	ulRouteDataDeviceName;
	UINT32	ulRouteMsRole;
	UINT32	ulRouteForwardForbidden;
	UINT32	ulRouteMaxMsQueryLoss;
	UINT32	ulRouteMinimalAirbandQual;
	UINT32	ulRouteWifiAdhocBandWidth;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T;

/* WTP CAPWAP配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	CHAR	acSecret[32];
	UINT32	ulDisType;
	CHAR	acAcURL[64];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

}AC_DB_TBL_WTPCAPWAPSETUP_T;
 
/* 告警配置表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulAlarmNo;
	CHAR	acAlarmName[32];
	UINT32	ulAlarmIsValid;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPALARMIFILTERSETUP_T;

typedef struct
{
	UINT32	ulAlarmNo;
	UINT32	ulAlarmIsValid;
} AC_DB_ALARMIFILTER_T;

/* AP  告警门限配置表*/
typedef struct {
	UINT32	ulWtpId;					/* 设备ID */
	
	UINT32  ulCpuLoadPeriod;    	/*		CPU负荷采样周期 */
	UINT32  ulCpuLoadCount;     	/*		CPU负荷持续次数 */
	UINT32  ulCpuLoadHigh;		/*      CPU负荷告警产生门限 */
	UINT32  ulCpuLoadLow;       	/*      CPU负荷告警消除门限 */
			
	UINT32  ulMemLoadPeriod;    	/*  	内存利用率采样周期 */
	UINT32  ulMemLoadCount;     	/*  	内存利用率持续次数 */
	UINT32  ulMemLoadHigh;      	/*  	内存利用率告警产生门限 */
	UINT32  ulMemLoadLow;       	/*      内存利用率告警消除门限 */
			
	UINT32  ulTempPeriod;       	/*	设备温度采样周期 */
	UINT32  ulTempCount;        	/*	设备温度持续次数 */
	UINT32  ulTempHigh;        	 	/*	设备温度告警产生门限 */
	UINT32  ulTempLow;          	/*	设备温度告警消除门限 */
	UINT32	ulLowTempHigh;		/*		设备低温告警产生门限	－50～0	－30	℃*/
	UINT32	ulLowTempLow;		/*		设备低温告警消除门限	－50～0	－20	℃*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T;

/* 计数器组配置表表*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulCounterGroupId;
	UINT32	ulCounterGroupIsInvalid	;
	UINT32	ulCounterGroupPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T;

/* add by gwx 2012-11-29 for AP/VAP级流控,
VAP-MAC用户流控表*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	
	UINT32	ulUserUpBandMax;
	UINT32	ulUserDownBandMax;

	UINT32	ulAddFlag;
	UINT32	ulAddRspFlag;
	UINT32	ulDelFlag;
	UINT32	ulDelRspFlag;	
}AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T;


/* add by gwx 2013-10-11 for task1076 企业网用户组流控*/
/* 用户组流控配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulUserGroupId;
	UINT32	ulUserGroupUpBandMax;
	UINT32	ulUserGroupDownBandMax;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];	
}AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T;

/* add by gwx 2013-11-27 for task1153 */
/* AP定位服务配置表*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulLocatorSwitch;		/* 定位功能开关*/
	UINT32	ulReportInterval;	/* 发送报告时间间隔,单位s*/
	UINT32	ulTypeName;		/* 需要扫描的无线设备类型*/
	UINT8	aucServerIp[4];		/*  定位服务器IP*/
	UINT32	ulServerPort;		/* 定位服务器端口号*/
	UINT32	ulFilterSwitch;		/* 获取MAC地址过滤开关*/
	UINT32 	aulFilterMacLen[5];		/* MAC地址匹配长度*/
	UINT8	aaucFilterMac[5][6];		/* MAC地址匹配规则*/
	UINT8	aucRsv[2];			/* 保留字段*/
	/* add by gwx 2014-7-21 for 定位功能扩展*/
	UINT32	ulLocatorEngine;	/* 定位引擎厂家*/
	UINT8	aucLocatorChannel[16];	/* 扫描信道配置*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];	
}AC_DB_TBL_WTPSYSLOCATORSETUP_T;

/* AP 关系表结构体定义结束*/
/******************************************************************************/


/******************************************************************************/
/* 变量声明开始*/
/* 基本配置表*/
extern DBHANDLE	ghWtpSysBasicSetup;
extern DBHANDLE	gidxWtpSysBasicSetup1;
extern DBHANDLE	gidxWtpSysBasicSetup10;

/* AP 动态信息表*/
extern DBHANDLE	ghWtpDynInfo;
extern DBHANDLE	gidxWtpDynInfo1;
extern DBHANDLE	gidxWtpDynInfo2;

/* AC检测到的未关联AP列表*/
extern DBHANDLE	ghWtpRogueAp;
extern DBHANDLE	gidxWtpRogueAp1;

/* IP配置表*/
extern DBHANDLE	ghWtpSysIpSetup;
extern DBHANDLE	gidxWtpSysIpSetup1;
//extern DBHANDLE	gidxWtpSysIpSetup2;
extern DBHANDLE	gidxWtpSysIpSetup10;

/* 负荷均衡配置表*/
extern DBHANDLE	ghWtpSysLoadBalanceSetup;
extern DBHANDLE	gidxWtpSysLoadBalanceSetup1;
extern DBHANDLE	gidxWtpSysLoadBalanceSetup10;

/* 日志配置表*/
extern DBHANDLE	ghWtpSysLogSetup;
extern DBHANDLE	gidxWtpSysLogSetup1;
extern DBHANDLE	gidxWtpSysLogSetup10;

/* 软件版本配置表*/
extern DBHANDLE	ghWtpSysSwServerSetup;
extern DBHANDLE	gidxWtpSysSwServerSetup1;
extern DBHANDLE	gidxWtpSysSwServerSetup10;

/* SNTP客户端配置表*/
extern DBHANDLE	ghWtpSysSntpSetup;
extern DBHANDLE	gidxWtpSysSntpSetup1;
extern DBHANDLE	gidxWtpSysSntpSetup10;

/* 无线设备基本配置表*/
extern DBHANDLE	ghWtpWifiDeviceBasicSetup;
extern DBHANDLE	gidxWtpWifiDeviceBasicSetup1;
extern DBHANDLE	gidxWtpWifiDeviceBasicSetup10;

/* 无线设备信道配置表*/
extern DBHANDLE	ghWtpWifiDeviceChannelSetup;
extern DBHANDLE	gidxWtpWifiDeviceChannelSetup1;
extern DBHANDLE	gidxWtpWifiDeviceChannelSetup10;

/* 无线设备速率配置表*/
extern DBHANDLE	ghWtpWifiDeviceRateSetup;
extern DBHANDLE	gidxWtpWifiDeviceRateSetup1;
extern DBHANDLE	gidxWtpWifiDeviceRateSetup10;

/* 无线设备功率配置表*/
extern DBHANDLE	ghWtpWifiDevicePowerSetup;
extern DBHANDLE	gidxWtpWifiDevicePowerSetup1;
extern DBHANDLE	gidxWtpWifiDevicePowerSetup10;

/* 无线设备高级配置表*/
extern DBHANDLE	ghWtpWifiDeviceAdvancedSetup;
extern DBHANDLE	gidxWtpWifiDeviceAdvancedSetup1;
extern DBHANDLE	gidxWtpWifiDeviceAdvancedSetup10;

/* 无线设备WIDS配置表*/
extern DBHANDLE	ghWtpWifiDeviceWidsSetup;
extern DBHANDLE	gidxWtpWifiDeviceWidsSetup1;
extern DBHANDLE	gidxWtpWifiDeviceWidsSetup10;

/* 无线设备无线环境监测配置表*/
extern DBHANDLE	ghWtpWifiDeviceResourceSetup;
extern DBHANDLE	gidxWtpWifiDeviceResourceSetup1;
extern DBHANDLE	gidxWtpWifiDeviceResourceSetup10;

/* VAP基本配置表*/
extern DBHANDLE	ghWtpApBasicSetup;
extern DBHANDLE	gidxWtpApBasicSetup1;
extern DBHANDLE	gidxWtpApBasicSetup2;
extern DBHANDLE	gidxWtpApBasicSetup3;
extern DBHANDLE	gidxWtpApBasicSetup4;
extern DBHANDLE	gidxWtpApBasicSetup10;

/* VAP安全配置表*/
extern DBHANDLE	ghWtpApSecuritySetup;
extern DBHANDLE	gidxWtpApSecuritySetup1;
extern DBHANDLE	gidxWtpApSecuritySetup2;
extern DBHANDLE	gidxWtpApSecuritySetup3;
extern DBHANDLE	gidxWtpApSecuritySetup10;

/* VAP高级配置表*/
extern DBHANDLE	ghWtpApAdvancedSetup;
extern DBHANDLE	gidxWtpApAdvancedSetup1;
extern DBHANDLE	gidxWtpApAdvancedSetup10;

/* VAP动态统计信息表*/
extern DBHANDLE	ghWtpApStat;
extern DBHANDLE	gidxWtpApStat1;
extern DBHANDLE	gidxWtpApStat2;
extern DBHANDLE	gidxWtpApStat10;

extern DBHANDLE	ghWtpApWifiStat;
extern DBHANDLE	gidxWtpApWifiStat1;
extern DBHANDLE	gidxWtpApWifiStat2;

/* ADHOC基本配置表*/
extern DBHANDLE	ghWtpAdhocBasicSetup;
extern DBHANDLE	gidxWtpAdhocBasicSetup1;
extern DBHANDLE	gidxWtpAdhocBasicSetup10;

/* ADHOC安全配置表*/
extern DBHANDLE	ghWtpAdhocSecuritySetup;
extern DBHANDLE	gidxWtpAdhocSecuritySetup1;
extern DBHANDLE	gidxWtpAdhocSecuritySetup10;

/* 以太网口配置表*/
extern DBHANDLE	ghWtpEnetBasicSetup;
extern DBHANDLE	gidxWtpEnetBasicSetup1;
extern DBHANDLE	gidxWtpEnetBasicSetup10;

/* 路由基本配置表*/
extern DBHANDLE	ghWtpRouteBasicSetup;
extern DBHANDLE	gidxWtpRouteBasicSetup1;
extern DBHANDLE	gidxWtpRouteBasicSetup10;

/* 路由邻居管理配置表*/
extern DBHANDLE	ghWtpRouteNeighborSetup;
extern DBHANDLE	gidxWtpRouteNeighborSetup1;
extern DBHANDLE	gidxWtpRouteNeighborSetup10;

/* 路由切换管理配置表*/
extern DBHANDLE	ghWtpRouteHandoverSetup;
extern DBHANDLE	gidxWtpRouteHandoverSetup1;
extern DBHANDLE	gidxWtpRouteHandoverSetup10;

/* 路由设备主从配置表*/
extern DBHANDLE	ghWtpRouteDeviceMscSetup;
extern DBHANDLE	gidxWtpRouteDeviceMscSetup1;
extern DBHANDLE	gidxWtpRouteDeviceMscSetup10;

/* AC关联配置表*/
extern DBHANDLE	ghWtpCapWapSetup;
extern DBHANDLE	gidxWtpCapWapSetup1;
extern DBHANDLE	gidxWtpCapWapSetup10;

/* 高级过滤配置表*/
extern DBHANDLE	ghWtpAlarmFilterSetup;
extern DBHANDLE	gidxWtpAlarmFilterSetup1;
extern DBHANDLE	gidxWtpAlarmFilterSetup10;

/* 告警门限配置表*/
extern DBHANDLE	ghWtpAlarmThresholdSetup;
extern DBHANDLE	gidxWtpAlarmThresholdSetup1;
extern DBHANDLE	gidxWtpAlarmThresholdSetup10;

/* 性能计数器组配置表*/
extern DBHANDLE	ghWtpPerfCounterGroupInfoSetup;
extern DBHANDLE	gidxWtpPerfCounterGroupInfoSetup1;
extern DBHANDLE	gidxWtpPerfCounterGroupInfoSetup10;

/* VAP-MAC用户流控表*/
extern DBHANDLE	ghWtpApVapMacFlowCtrlSetup;
extern DBHANDLE	gidxWtpApVapMacFlowCtrlSetup1;

/* 用户组流控配置表*/
/* add by gwx 2013-10-11 for task1076 企业网用户组流控需求*/
extern DBHANDLE	ghWtpApUserGroupQosSetup;
extern DBHANDLE	gidxWtpApUserGroupQosSetup1;
extern DBHANDLE	gidxWtpApUserGroupQosSetup10;

/* AP 定位服务配置表*/
/* add by gwx 2013-11-27 for task1153 */
extern DBHANDLE	ghWtpSysLocatorSetup;
extern DBHANDLE	gidxWtpSysLocatorSetup1;
extern DBHANDLE	gidxWtpSysLocatorSetup10;

extern DBHANDLE	gahCwTblList[64];
extern UINT32		gulCwTblNum;
/* 变量声明结束*/
/******************************************************************************/

/******************************************************************************/
/* 函数声明开始*/
extern UINT32    ac_db_aptable_init (VOID);
extern UINT32	  ac_db_tbl_wtpmergekey (UINT8 *pucKey, DBHANDLE hTbl, UINT32 ulWtpId, DBHANDLE *phIdx);

extern UINT32    ac_db_table_wtpsysbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpsysbasicsetup_check (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_preinsert (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_predelete (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_preupdate (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern VOID ac_db_table_wtpsysbasicsetup_mergekey2 (UINT8 *pucKey,  UINT8 *pucDeviceId);
extern UINT32    ac_db_table_wtpsysbasicsetup_setdyndata (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_trigger (UINT8 ucModType);
extern UINT32	 ac_db_table_wtpsysbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpdyninfo_create (VOID);
extern VOID ac_db_table_wtpdyninfo_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
#if 0 /* mod by gwx 2013-4-7 for task668 */
extern VOID ac_db_table_wtpdyninfo_mergekey2 (UINT8 *pucKey, UINT32	ulAcLanId, UINT32 ulWtpId);
#else
extern VOID ac_db_table_wtpdyninfo_mergekey2 (UINT8 *pucKey, UINT32 ulCommPort, UINT8* aucCommIp, UINT32 ulWtpId);
#endif
extern UINT32	ac_db_table_wtpdyninfo_delcfg(UINT32 ulWtpId);

extern UINT32		ac_db_table_wtprogueap_create(VOID);
extern VOID		ac_db_table_wtprogueap_mergekey1(UINT8 *pucKey, UINT8 *pucDeviceId);

extern UINT32    ac_db_table_wtpsysipsetup_create (VOID);
extern UINT32    ac_db_table_wtpsysipsetup_check (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_preinsert (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_predelete (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_preupdate (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysipsetup_setdyndata (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysipsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysipsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysipsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsysloadbalancesetup_create (VOID);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_check (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_preinsert (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_predelete (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_preupdate (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysloadbalancesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysloadbalancesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysloadbalancesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysloadbalancesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsyslogsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyslogsetup_check (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_preinsert (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_predelete (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_preupdate (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyslogsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsyslogsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyslogsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyslogsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyslogsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsysswserversetup_create (VOID);
extern UINT32    ac_db_table_wtpsysswserversetup_check (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_preinsert (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_predelete (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_preupdate (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysswserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysswserversetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysswserversetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysswserversetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysswserversetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsyssntpsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyssntpsetup_check (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_preinsert (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_predelete (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_preupdate (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyssntpsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsyssntpsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyssntpsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyssntpsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyssntpsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicebasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_check (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_predelete (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_setdyndata (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicebasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicebasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicebasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicechannelsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_check (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_predelete (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicechannelsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicechannelsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicechannelsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicechannelsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifideviceratesetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceratesetup_check (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_preinsert (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_predelete (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_preupdate (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceratesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceratesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceratesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceratesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceratesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicepowersetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_check (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_predelete (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicepowersetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_setdyndata (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicepowersetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicepowersetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicepowersetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
 
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_check (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_predelete (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceadvancedsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceadvancedsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceadvancedsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceadvancedsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicewidssetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_check (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_predelete (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicewidssetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicewidssetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicewidssetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicewidssetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifideviceresourcesetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_check (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_preinsert (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_predelete (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_preupdate (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceresourcesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceresourcesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceresourcesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceresourcesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpapbasicsetup_check (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_preinsert (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_predelete (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_preupdate (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapbasicsetup_mergekey2 (UINT8 *pucKey,UINT8* pucBssid);
extern VOID ac_db_table_wtpapbasicsetup_mergekey3 (UINT8 *pucKey,UINT32 ulWtpId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapbasicsetup_mergekey4 (UINT8 *pucKey,CHAR *pcSsid, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapbasicsetup_setdyndata (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
 
extern UINT32    ac_db_table_wtpapsecuritysetup_create (VOID);
extern UINT32    ac_db_table_wtpapsecuritysetup_check (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_preinsert (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_predelete (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_preupdate (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey2 (UINT8 *pucKey, 
															UINT32 ulWapiSetupId, 
															UINT32 ulWtpId, 
															UINT32 ulVdevId, 
															UINT32 ulVapId);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey3 (UINT8 *pucKey, 
															UINT32 ulCertFileId, 
															UINT32 ulWtpId, 
															UINT32 ulVdevId, 
															UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapsecuritysetup_trigger (UINT8 ucModType);	
extern UINT32	ac_db_table_wtpapsecuritysetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapsecuritysetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapsecuritysetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapadvancedsetup_create (VOID);
extern UINT32    ac_db_table_wtpapadvancedsetup_check (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_preinsert (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_predelete (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_preupdate (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapadvancedsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapadvancedsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapadvancedsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapadvancedsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapadvancedsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapstat_create (VOID);
extern VOID ac_db_table_wtpapstat_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVDevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapstat_mergekey2 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32	ac_db_table_wtpapstat_delcfg(UINT32 ulWtpId);

extern UINT32		ac_db_table_wtpapwifistat_create(VOID);
extern VOID ac_db_table_wtpapwifistat_mergekey1(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32	ac_db_table_wtpapwifistat_delcfg(UINT32 ulWtpId);

extern UINT32    ac_db_table_wtpadhocbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpadhocbasicsetup_check (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_preinsert (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_predelete (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_preupdate (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpadhocbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulAdhocId);
extern UINT32    ac_db_table_wtpadhocbasicsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_wtpadhocbasicsetup_setdyndata (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32	ac_db_table_wtpadhocbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpadhocbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpadhocbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpadhocsecuritysetup_create (VOID);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_check (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_preinsert (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_predelete (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_preupdate (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern VOID ac_db_table_wtpadhocsecuritysetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulAdhocId);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpadhocsecuritysetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpadhocsecuritysetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpadhocsecuritysetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpenetbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpenetbasicsetup_check (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_preinsert (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_predelete (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_preupdate (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpenetbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulEnetPortId);
extern UINT32    ac_db_table_wtpenetbasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpenetbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpenetbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpenetbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutebasicsetup_create (VOID);
extern UINT32    ac_db_table_wtproutebasicsetup_check (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_preinsert (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_predelete (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_preupdate (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutebasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutebasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutebasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutebasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtprouteneighborsetup_create (VOID);
extern UINT32    ac_db_table_wtprouteneighborsetup_check (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_preinsert (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_predelete (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_preupdate (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern VOID ac_db_table_wtprouteneighborsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtprouteneighborsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtprouteneighborsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtprouteneighborsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtprouteneighborsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutehandoversetup_create (VOID);
extern UINT32    ac_db_table_wtproutehandoversetup_check (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_preinsert (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_predelete (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_preupdate (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutehandoversetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutehandoversetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutehandoversetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutehandoversetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutehandoversetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutedevicemscsetup_create (VOID);
extern UINT32    ac_db_table_wtproutedevicemscsetup_check (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_preinsert (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_predelete (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_preupdate (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutedevicemscsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutedevicemscsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutedevicemscsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutedevicemscsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutedevicemscsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpcapwapsetup_create (VOID);
extern UINT32    ac_db_table_wtpcapwapsetup_check (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_preinsert (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_predelete (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_preupdate (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpcapwapsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpcapwapsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpcapwapsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpcapwapsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpcapwapsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpalarmfiltersetup_create (VOID);
extern UINT32    ac_db_table_wtpalarmfiltersetup_check (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_preinsert (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_predelete (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_preupdate (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpalarmfiltersetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulAlarmNo);
extern UINT32    ac_db_table_wtpalarmfiltersetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpalarmfiltersetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpalarmfiltersetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpalarmfiltersetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);


extern UINT32    ac_db_table_wtpalarmthresholdsetup_create (VOID);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_check (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_preinsert (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_predelete (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_preupdate (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpalarmthresholdsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpalarmthresholdsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpalarmthresholdsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpalarmthresholdsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_create (VOID);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_check (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_preinsert (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_predelete (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_preupdate (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern VOID ac_db_table_wtpperfcountergroupinfosetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulCounterGroupId);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpperfcountergroupinfosetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpperfcountergroupinfosetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpperfcountergroupinfosetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

/* add by gwx 2012-11-29 for AP/VAP级流控*/
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_create (VOID);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_check (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_preinsert (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_predelete (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_preupdate (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapvapmacflowctrlsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulWifiDeviceId, UINT32 ulVapId,UINT8* pucMac );


/* add by gwx 2013-10-11 for task1076 企业网用户组流控begin */
extern UINT32    ac_db_table_wtpapusergroupqossetup_create (VOID);
extern UINT32    ac_db_table_wtpapusergroupqossetup_check (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_preinsert (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_predelete (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_preupdate (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapusergroupqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulUserGroupId);
extern UINT32    ac_db_table_wtpapusergroupqossetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapusergroupqossetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapusergroupqossetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapusergroupqossetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
/* add by gwx 2013-10-11 for task1076 企业网用户组流控end */


/* add by gwx 2013-11-27 for task1153 begin*/
extern UINT32    ac_db_table_wtpsyslocatorsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyslocatorsetup_check (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_preinsert (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_predelete (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_preupdate (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyslocatorsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId );
extern UINT32    ac_db_table_wtpsyslocatorsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyslocatorsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyslocatorsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyslocatorsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
/* add by gwx 2013-11-27 for task1153 end*/
/* 函数声明结束*/
/******************************************************************************/
	

#endif /* _AP_DB_TABLE_H */
/******************************* 头文件结束 **********************************/

