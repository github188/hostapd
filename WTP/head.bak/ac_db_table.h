/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  关系表方法头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
* 2009-3-3	  潘妍艳		     新增AC2.0功能
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DB_TABLE_H
#define  _AC_DB_TABLE_H

/******************************************************************************/

/*AC 关系表容量宏定义开始*/
/* 系统配置*/
#define AC_DB_ACBASICSETUP_CAPACITY				((UINT32)1)			/* AC 基本配置表表容量*/
#define AC_DB_ACWTPASSOCIATESETUP_CAPACITY		AC_WTP_NUM_MAX	/* AC WTP关联配置表表容量*/
#define AC_DB_ACKEEPERSETUP_CAPACITY				((UINT32)1)		/* AC 上行链路检查配置表表容量*/
#define AC_DB_ACNEIGHBORSETUP_CAPACITY			((UINT32)1024)	/* AC 邻居关系配置表表容量*/
#define AC_DB_ACSYSSNMPV2SETUP_CAPACITY			((UINT32)4)		/* AC SNMP V2配置表表容量*/
#define AC_DB_ACSYSSNMPV3SETUP_CAPACITY			((UINT32)4)		/* AC SNMP V3配置表表容量*/
#define AC_DB_ACSYSTRAPSVRSETUP_CAPACITY		((UINT32)4)		/* AC SNMP TRAP 配置表表容量*/
#define AC_DB_ACSNTPGLOBALSETUP_CAPACITY		((UINT32)1)		/* AC SNTP全局配置表表容量*/
#define AC_DB_ACLOGSETUP_CAPACITY				((UINT32)1)		/* AC LOG管理配置表表容量*/
#define AC_DB_ACLOGSERVERSETUP_CAPACITY			((UINT32)1)		/* AC LOG服务器配置表表容量*/
#define AC_DB_ACASSOCSWVERSETUP_CAPACITY		((UINT32)1)		/* AC支持的AP软件版本列表配置表容量*/

/* 物理端口和IP配置*/
#define AC_DB_ACIFSETUP_CAPACITY					((UINT32)16)		/* AC物理端口配置表表容量*/
#define AC_DB_ACIPSETUP_CAPACITY					((UINT32)1)		/* AC端口IP地址配置表容量*/

/* 2011-5-20 pyy: 地址池数量32--->256 */
/* 用户级DHCP服务配置*/
#define AC_DB_ACSTADHCPGLOBALSETUP_CAPACITY			((UINT32)1)		/* DHCP for STA功能配置表表容量*/
#define AC_DB_ACSTADHCPSTATICIPADDRSETUP_CAPACITY		((UINT32)256)	/* DHCP for STA 静态绑定IP配置表表容量*/
#define AC_DB_ACSTADHCPDYNAMICIPADDRSETUP_CAPACITY	((UINT32)256)		/* DHCP for STA 动态IP地址池配置表表容量*/

/* AP级DHCP 服务配置*/
#define AC_DB_ACAPDHCPGLOBALSETUP_CAPACITY				((UINT32)1)		/* DHCP for AP功能配置表表容量*/
#define AC_DB_ACAPDHCPSTATICIPADDRSETUP_CAPACITY		((UINT32)256)	/* DHCP for AP 静态绑定IP配置表表容量*/
#define AC_DB_ACAPDHCPDYNAMICIPADDRSETUP_CAPACITY		((UINT32)256)		/* DHCP for AP 动态IP地址池配置表表容量*/

/* VLAN管理*/
#define AC_DB_ACVLANGLOBALSETUP_CAPACITY			((UINT32)1)		/* AC VLAN 全局配置表容量*/
#define AC_DB_ACVLANSETUP_CAPACITY					((UINT32)1024)	/* AC VLAN配置表表容量*/
#define AC_DB_ACAPIPVLANMAPPINGSETUP_CAPACITY		((UINT32)256)	/* AP IP网段-VLAN映射配置表表容量*/
#define AC_DB_ACSSIDVLANMAPPINGSETUP_CAPACITY		((UINT32)16)		/* SSID-VLAN映射配置表表容量*/
/* mod by gwx 2012-5-31 change 1024 to 4096 for bug1089 */
#define AC_DB_ACIFVLANMAPPINGSETUP_CAPACITY			((UINT32)4096)	/* AC 端口-VLAN映射配置表表容量*/
#define AC_DB_ACMACVLANMAPPINGSETUP_CAPACITY		((UINT32)1024)	/* AC MAC-VLAN映射配置表表容量*/

/* WAPI配置*/
#define AC_DB_ACWAPIASSETUP_CAPACITY				((UINT32)1)		/* AC AS服务器配置表表容量*/
#define AC_DB_ACWAPISETUP_CAPACITY				((UINT32)4)		/* AC WAPI参数配置表表容量*/
#define AC_DB_ACWAPICERTFILESETUP_CAPACITY		((UINT32)256)	/* AC WAPI证书配置表表容量*/

/* AAA配置*/
#define AC_DB_ACAAASETUP_CAPACITY				((UINT32)1)		/* AC AAA配置表表容量*/

/* 免认证配置*/
#define AC_DB_ACFREEGLOBALSETUP_CAPACITY		((UINT32)1)		/*AC 免认证全局配置表表容量*/
#define AC_DB_ACFREEIPSETUP_CAPACITY				((UINT32)256)	/* AC免认证IP 地址列表表容量*/
#define AC_DB_ACFREEMACSETUP_CAPACITY			((UINT32)256)	/* AC免认证MAC列表表容量*/
#define AC_DB_ACFREESSIDSETUP_CAPACITY			((UINT32)256)	/* AC免认证SSID列表表容量*/
#define AC_DB_ACFREEVLANSETUP_CAPACITY			((UINT32)256)	/* AC免认证VLAN列表表容量*/

#define AC_DB_ACMACSERVERSETUP_CAPACITY			((UINT32)1)		/* MAC认证全局配置表表容量*/

/* WEB认证配置*/
#define AC_DB_ACPORTALSETUP_CAPACITY				((UINT32)1)		/* AC 强制Portal配置表表容量*/
#define AC_DB_ACWHILTELISTSETUP_CAPACITY			((UINT32)32)		/* AC Portal白名单配置表表容量*/
#define AC_DB_ACWHITEURLLISTSETUP_CAPACITY		((UINT32)64)		/* AC Portal白名单URL配置表表容量*/
#define AC_DB_ACUSERADDRBINDSETUP_CAPACITY		((UINT32)64)		/* AC 用户名地址绑定配置表表容量*/
#define AC_DB_ACSSIDAUTHSETUP_CAPACITY			((UINT32)128)	/* SSID 认证配置表容量*/

/* PPPoE认证配置*/
#define AC_DB_ACPPPOESETUP_CAPACITY				((UINT32)1)		/* AC PPPoE配置表表容量*/

/* 路由配置*/
#if 0	/* mod by gwx 2014-4-10 for bug1024 */
#define AC_DB_ACSTATICROUTESETUP_CAPACITY		((UINT32)128)	/* 静态路由配置表表容量*/
#else
#define AC_DB_ACSTATICROUTESETUP_CAPACITY		((UINT32)1024)	/* 静态路由配置表表容量*/
#endif
#define AC_DB_ACRIPGLOBALSETUP_CAPACITY			((UINT32)1)		/* RIP全局配置表表容量*/
#define AC_DB_ACRIPANNOUNCENETSETUP_CAPACITY	((UINT32)16)		/* RIP通告网段配置表表容量*/

/* NAT配置*/
#define AC_DB_ACNATGLOBALSETUP_CAPACITY			((UINT32)1)		/* NAT 全局配置表表容量*/
#define AC_DB_ACNATSETUP_CAPACITY				((UINT32)32)		/* NAT规则配置表表容量*/

/* MAC地址过滤配置*/
#define AC_DB_ACVLANACCESSMACPOLICYSETUP_CAPACITY	((UINT32)1024)	/* AC VLAN MAC地址过滤策略表容量*/
#define AC_DB_ACVLANACCESSMACLISTSETUP_CAPACITY	((UINT32)1024)	/* AC VLAN MAC地址列表容量*/

/* ACL配置*/
#define AC_DB_ACFIREWALLGLOBALSETUP_CAPACITY	((UINT32)1)		/* 防火墙全局配置表表容量*/
#define AC_DB_ACFIREWALLRULEBASICSETUP_CAPACITY	((UINT32)512*4)	/* 防火墙规则基本配置表表容量*/

/* IDS配置*/
#define AC_DB_ACIDSRULESETUP_CAPACITY				((UINT32)1)		/* IDS规则配置表表容量*/
#define AC_DB_ACIDSSTRATEGYSETUP_CAPACITY			((UINT32)1)		/* IDS策略配置表表容量*/

/* P2P配置*/
#define AC_DB_ACFIREWALLL7MATCHSETUP_CAPACITY		((UINT32)1)		/* 防火墙P2P流量限制配置表表容量*/

/* QoS配置*/
#define AC_DB_ACQOSGLOBALSETUP_CAPACITY				((UINT32)1)		/* QOS全局配置表表容量*/
#define AC_DB_ACQOSUSERDEFAULTSETUP_CAPACITY		((UINT32)1)		/* 用户QOS缺省配置表表容量*/
#define AC_DB_ACUSERQOSSETUP_CAPACITY				((UINT32)256)	/* 用户QOS配置表表容量*/
#define AC_DB_ACVLANQOSSETUP_CAPACITY				((UINT32)128)	/* VLAN QOS配置表表容量*/
#define AC_DB_ACSSIDQOSSETUP_CAPACITY				((UINT32)128)	/* SSID QOS配置表表容量*/
#define AC_DB_ACVAPQOSSETUP_CAPACITY				((UINT32)4096*16)	/* VAP QOS配置表表容量*/
#define AC_DB_ACAPQOSSETUP_CAPACITY				((UINT32)4096)	/* AP QOS配置表表容量*/

/* IGMP配置*/
#define AC_DB_ACIGMPSNOOPSETUP_CAPACITY			((UINT32)1)		/* AC IGMP Snooping配置表表容量*/
#define AC_DB_ACIGMPPROXYSETUP_CAPACITY			((UINT32)1)		/* AC IGMP Proxy配置表表容量*/

/* 2010-1-18 pyy 新增 */
/* 主备配置 */
#define AC_DB_ACMSSETUP_CAPACITY                ((UINT32)1)     /* AC主备配置 */

/* 网管参数配置*/
#define AC_DB_ACALARMFILTERSETUP_CAPACITY				((UINT32)128)	/* 告警过滤配置表表容量*/
#define AC_DB_ACALARMTHRESHOLDSETUP_CAPACITY			((UINT32)1)		/* 告警门限配置表表容量*/
#define AC_DB_ACPERFCOUNTERGROUPINFOSETUP_CAPACITY	((UINT32)128)	/* 性能计数器组配置表表容量*/

#define AC_DB_ACAPACLSETUP_CAPACITY               		 		((UINT32)1)		/* AP访问策略配置表*/
#define AC_DB_ACAPIDNASSETUP_CAPACITY					((UINT32)256)	/* AP设备ID段-NAS ID映射表*/
#define AC_DB_ACAPIPNASSETUP_CAPACITY					((UINT32)256)	/* AP IP网段-NAS ID映射表*/

#define AC_DB_ACNASIDSETUP_CAPACITY						((UINT32)128)		/* NASID配置表容量*/
#define AC_DB_ACSSIDMACSERVERSETUP_CAPACITY				((UINT32)128)		/* ssidmac服务配置表*/
/* add by gwx 2013-10-11 for task1076 企业网用户组流控需求*/
#define AC_DB_ACUSERGROUPSETUP_CAPACITY					((UINT32)8)	/* 用户组流控配置表*/

/* add by gwx 2014-6-25 for SSID级用户控制接入begin*/
#define AC_DB_ACSSIDACCESSSETUP_CAPACITY				((UINT32)32)	/* SSID级用户接入控制模式配置表*/
#define AC_DB_ACSSIDACCESSSLISTETUP_CAPACITY			((UINT32)1024)	/* SSID级用户接入控制列表配置表*/
/* add by gwx 2014-6-25 for SSID级用户控制接入end*/
#define AC_DB_ACLINKIPLISTETUP_CAPACITY			((UINT32)32)	/*AC连接IP 列表配置表*/

/* 以下为动态表*/
/* mod by gwx 2012-7-4 for bug1303 用户表容量扩大16倍*/
#if 1 /* mod by gwx for 企业网测试*/
#define AC_DB_ACUSER_CAPACITY							((UINT32)4096*16)	/* 在线用户表容量*/
#else
#define AC_DB_ACUSER_CAPACITY							((UINT32)4096*4)	/* 在线用户表容量*/
#endif
#define AC_DB_ACUSERVLAN_CAPACITY					((UINT32)4096)	/* 用户VLAN缓存表容量*/
#define AC_DB_ACDYNEVENT_CAPACITY					((UINT32)1000)	/* 事件表容量*/
#define AC_DB_ACIDSUSER_CAPACITY						((UINT32)1000)	/* IDS黑名单用户表容量*/
/* mod by gwx 2012-7-4 for bug1303 用户Portal认证缓存表扩大4倍*/
#define AC_DB_ACPORTALUSER_CAPACITY					((UINT32)4096*16)	/* 用户Portal认证缓存表容量*/
#define AC_DB_ACUSERACCINFO_CAPACITY					((UINT32)4096)	/* 历史终端接入信息表表容量*/
#define AC_DB_ACUSERIPINFO_CAPACITY					((UINT32)4096)	/* 终端IP分配信息关系表表容量*/
/* 2011-1-12 pyy add */
#define AC_DB_ACHISTORYUSER_CAPACITY					(AC_DB_ACUSER_CAPACITY*4)	/* 历史用户表 */

/* add by gwx 2011-11-2 for 广东移动*/
#define AC_DB_ACAUTHSTAT_CAPACITY					((UINT32)1)	/* AC认证统计表容量*/

/* add by gwx 2012-11-2 for用户流量不准确*/
#define AC_DB_ACUSERTIMER_CAPACITY					((UINT32)4096*16)	/* 用户定时器表容量*/


/*AC 关系表容量宏定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 2009-3-3 AC2.0 add */
/* AC 关系表结构体定义开始*/
/* AC基本配置表*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	CHAR	acAcNEId[32];		/* 设备网元编码*/
	CHAR	acDomainName[64];	/*	AC主机名*/
	CHAR	acContact[64];		/* 设备维护联系人*/
	CHAR	acLocation[64];		/* 设备所在位置*/
	
	UINT32	ulMaxWtpNum;		/* 最大允许接入的WTP数*/
	UINT32	ulMaxStaSwitch;		/* 2010-7-20 新增: 最大用户数限制 0:禁用 1:启用*/
	UINT32	ulMaxStaNum;		/* 最大允许接入的用户数*/
	UINT32	ulMaxPortalStaNum;	/*	最大允许接入的Portal用户数	*/
	UINT32	ulMaxPPPoEStaNum;	/*	最大允许接入的PPPoE用户数	*/

	/* 2010-4-10 pyy 新增*/
	UINT32	ulHeartbeatOnOff;	/* 心跳检测开关0:禁用 1:启用*/
	
	UINT32	ulHeartbeatPeriod;	/* 心跳周期*/
    UINT8   aucManageIpAddr[4]; /* 管理IP地址*/
	UINT32	ulStatisticsTime;		/* 性能统计统计时长	>0	60	单位：秒*/
	UINT32	ulSampleTime;		/* 性能统计抽样时长	>0	10	单位：秒*/

	/* 2010-4-10 pyy 新增*/
	UINT32	ulNormalCollectCycle;	/* AP常规采集周期 单位:秒 10~120 */
	UINT32	ulRtCollectCycle;			/* AP实时采集周期 单位:秒 2~5 */

	/* 2010-10-21 fengjing add */
	UINT32    ulCollectSwitch;         /* 统计采集开关 */

	UINT32    ulAllAPMonitorMode;      /* AP无线监视模式 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
	
	UINT32	ulCfgVersion;	
} AC_DB_TBL_ACBASICSETUP_T;

/* AC关联配置*/
typedef struct {
	UINT32	ulAcId;				/*	设备ID */

	UINT32	ulWtpId;				/*  WTP设备ID */
	UINT32	ulAssociatePrio;		/*	关联优先级*/
	UINT32	ulWtpAuthManner;	/*	WTP关联认证方式*/
	CHAR	acSecret[32];		/*	WTP设备接入密码*/
	UINT8	aucWtpSn[6];		/* WTP设备序列号*/
	UINT8	aucResv[2];			/* Padding */
    UINT8   aucWtpMac[6];
    UINT8   aucResv1[2];
	UINT32  	ulEchoInterval;
	UINT32  	ulMaxRetransmit;
	UINT32 	ulWtpProductType;	/* add by gwx 2014-2-25 for task1265 AP产品类型*/
	CHAR	acModelName[64];	/* add by gwx 2014-6-20 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWTPASSOCIATESETUP_T;

/* AC 上行链路检查配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulKeepSwitch;		/*	是否启用		0=关闭1=启用*/
	UINT8	aucKeeperIp0[4];		/*	检查IP地址1		有效的IP地址*/
	UINT8	aucKeeperIp1[4];		/*	检查IP地址2		有效的IP地址*/
	UINT32	ulKeepInterval;		/*	检查间隔		>=0 */
	UINT32	ulKeepCount;			/*	超时次数		>=0 */
	UINT32	ulToStandby;			/* 2011-6-20 pyy 新增: 检测到上行链路故障后的操作
									切换到standby 状态0:禁用 1:启用*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACKEEPERSETUP_T;


/* AC邻居关系配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */
	
	UINT32	ulNeighId;			/*		邻居关系ID*/
	UINT32	ulNeighType;			/*		邻居类型*/
	UINT32	ulWtpId;				/*		AP标识*/
	UINT32	ulWifiDeviceId;		/*		AP无线设备ID*/
	UINT32	ulNeighWtpId;		/*		相邻AP标识*/
	UINT32	ulNeighWifiDeviceId;	/*		相邻AP无线设备ID*/
	UINT32	ulNeighRelation;		/*		邻居关系*/
	UINT32	ulLoadNeigh;			/*		是否负荷均衡邻居*/
	UINT32	ulCoverageNeigh;	/*		是否覆盖补偿邻居*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACNEIGHBORSETUP_T;

/* AC SNMP V2配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulCommunityId;			/* 共同体ID */
	CHAR	acReadCommunity[32];	/* 读共同体 */
	CHAR	acWriteCommunity[32];	/* 写共同体 */
	UINT32	ulRfc1213Flag;			/* RFC1213标准MIB访问权限 */
	UINT32	ulRfc1573Flag;			/* RFC1573标准MIB访问权限 */
	UINT32	ulRfc1643Flag;			/* RFC1643标准MIB访问权限 */
	UINT32	ulIeee8021PAEFlag;		/* Ieee8021PAE标准MIB访问权限 */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot标准MIB访问权限 */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI标准MIB访问权限 */
	UINT32	ulPrivateFlag;			/* 私有MIB访问权限 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSYSSNMPV2SETUP_T;

/* AC SNMP V3配置*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulUserId;			/* 用户ID */
	CHAR	acUserName [32];	/* 用户名 */
	UINT32	ulAuthProtocol;		/* 鉴权协议 */
	CHAR	acAuthKey[32];		/* 鉴权密钥 */
	UINT32	ulPrivProtocol;		/* 加密协议 */
	CHAR	acPrivKey[32];		/* 加密密钥 */
	UINT32	ulRfc1213Flag;		/* RFC1213标准MIB访问权限 */
	UINT32	ulRfc1573Flag;		/* RFC1573标准MIB访问权限 */
	UINT32	ulRfc1643Flag;		/* RFC1643标准MIB访问权限 */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE标准MIB访问权限 */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot标准MIB访问权限 */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI标准MIB访问权限 */
	UINT32	ulPrivateFlag;			/* 私有MIB访问权限 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSYSSNMPV3SETUP_T;

/* AC SNMP TRAP 配置表*/
typedef struct {
	UINT32	ulAcId;					/*	AC设备ID	*/

	UINT32	ulTrapSvrId;
	UINT8	aucTrapIp[4];
	UINT32	ulTrapPort;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSYSTRAPSVRSETUP_T;

/* AC SNTP服务器配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulSntpSwitch;			/* 启用SNTP服务器功能 */
	UINT32	ulUpdatePeriod;			/* 时间更新周期*/

	UINT8	aucUpperSntpSvr1[4];	/*	上级SNTP服务器1*/
	UINT8	aucUpperSntpSvr2[4];	/*	上级SNTP服务器2*/
	UINT8	aucUpperSntpSvr3[4];	/*	上级SNTP服务器3*/
	UINT8	aucUpperSntpSvr4[4];	/*	上级SNTP服务器4*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSNTPGLOBALSETUP_T;

/* AC LOG管理配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */

	UINT8	aucLogModule[64];	/*	模块开关	*/
	UINT32	ulLogToStdOut;		/*	是否打印到标准输出	*/
	UINT32	ulLogSvrNum;		/* 远程日志服务器数目*/
	UINT8	aaucLogSvrIp[4][4];	/*	日志服务器IP地址	*/
	UINT32	aulLogSvrPort[4];	/*	日志服务器端口号	*/
	UINT32	ulLogTransType;		/*	日志传输类型	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACLOGSETUP_T;

/* AC LOG服务器配置表*/
typedef struct {
	UINT32	ulAcId;		/* 设备ID */

	UINT32	ulLogSvrSwitch;	/*	日志服务器开关	*/
	UINT8	aucLogSvrIp[4];	/*	日志服务器绑定IP地址	*/
	UINT32	ulLogSvrPort;	/*	日志服务器绑定端口	*/
	UINT32	ulLogBakDay;	/*	日志保存天数	*/
	UINT32	ulLogFileSize;	/*	日志文件大小	*/
	UINT32	ulLogCompress;	/*	是否压缩	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACLOGSERVERSETUP_T;

/* AC支持的AP软件版本列表配置表*/
typedef struct {
	UINT32	ulAcId;

	CHAR	acDftApSwVersion[32];		/* 缺省AP软件版本*/
	
	CHAR	acSwVersion1[32];			/* AP软件版本1 */
	CHAR	acSwVersion2[32];			/* AP软件版本2 */
	CHAR	acSwVersion3[32];			/* AP软件版本3 */
	CHAR	acSwVersion4[32];			/* AP软件版本4 */
	CHAR	acSwVersion5[32];			/* AP软件版本5 */
	CHAR	acSwVersion6[32];			/* AP软件版本6 */
	CHAR	acSwVersion7[32];			/* AP软件版本7 */
	CHAR	acSwVersion8[32];			/* AP软件版本8 */
	CHAR	acSwVersion9[32];			/* AP软件版本9 */
	CHAR	acSwVersion10[32];			/* AP软件版本10 */
	CHAR	acSwVersion11[32];			/* AP软件版本11 */
	CHAR	acSwVersion12[32];			/* AP软件版本12 */
	CHAR	acSwVersion13[32];			/* AP软件版本13 */
	CHAR	acSwVersion14[32];			/* AP软件版本14 */
	CHAR	acSwVersion15[32];			/* AP软件版本15 */
	CHAR	acSwVersion16[32];			/* AP软件版本16 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACASSOCSWVERSETUP_T;

/* AC物理端口配置表*/
typedef struct {
	UINT32	ulAcId;		/* 设备ID */
	
	UINT32	ulIfId;	/* 端口号 */
	CHAR	acIfName[32];	/* 端口名称 */
	UINT32	ulIfType;		/* 端口类型*/
	UINT32	ulRunMode;		/* 是否启用 */
	UINT32	ulSpeedUplex;	/* 速率/双工模式 */
	UINT32	ulMtu;			/* 是否为信任端口 */
	UINT32	ulVlanType;		/* VLAN属性: 0:VLAN终结 1:VLAN透传 2:VLAN封装*/
	UINT32	ulCapVlanId;		/* 封装VLAN ID */
	CHAR	acDesc[64];	/* 端口描述信息*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIFSETUP_T;

/*端口IP地址配置表*/
typedef struct {
	UINT32	ulAcId;

	UINT32	ulFitLanIpNum;				/* FIT-LAN端口的IP地址数目*/
	UINT8	aaucFitLanIp[8][4];			/* FIT-LAN IP地址*/
	UINT8	aaucFitLanNetMask[8][4];		/* FIT-LAN IP子网掩码*/

	UINT32	ulFatLanIpNum;					/* FAT-LAN端口的IP地址数目*/
	UINT8	aaucFatLanIp[32][4];				/* FAT-LAN IP地址*/
	UINT8	aaucFatLanNetMask[32][4];		/* FAT-LAN IP子网掩码*/

	UINT32	ulL2WanIpNum;					/* L2-WAN端口的IP地址数目*/
	UINT8	aaucL2WanIp[8][4];				/* L2-WAN IP地址*/
	UINT8	aaucL2WanMask[8][4];		/* L2-WAN IP子网掩码*/

	UINT32	ulL3WanIpNum;					/* L3-WAN端口的IP地址数目*/
	UINT8	aaucL3WanIp[8][4];				/* L3-WAN IP地址*/
	UINT8	aaucL3WanMask[8][4];		/* L3-WAN IP子网掩码*/

	/* 2011-6-2 pyy 主备修改*/
	UINT32	ulMsIpNum;					/* 主备通信IP地址数目*/
	UINT8	aaucMsIp[8][4];				/* 主备IP地址*/
	UINT8	aaucMsMask[8][4];			/* 掩码*/

	UINT8	aucDefaultGw[4];					/* 缺省网关*/
	UINT8	aucPrimaryDns[4];				/* 主用DNS服务器*/
	UINT8	aucSecondaryDns[4];				/* 备用DNS服务器*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIPSETUP_T;

/* AC DHCP for STA 功能配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulEnableDhcpServer;			/*	DHCP功能角色*/		
	UINT32	ulEnableDhcpSnooping;		/*	启用DHCP Snooping功能*/
	UINT32	ulEnableOption60;		/* add by gwx 2013-3-12 for task532 option 60开关，0:关闭1:开启*/
	UINT8	aucDhcpServerMaster[4];		/*	主DHCP中继服务器地址*/
	UINT8	aucDhcpServerSlave[4];		/*	备DHCP中继服务器地址*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPGLOBALSETUP_T;

/* AC DHCP for STA 静态绑定IP配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	CHAR	acDescr[32];				/* 用于标识主机*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T;

/* AC DHCP for STA 动态IP地址池配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulId ;						/* 地址池编号 */
	CHAR    	acIpPoolNAme[32]	    	;   	/* 名称                     */
	UINT8   	aucBeginIp[4]	        		;   	/* 起始地址                 */
	UINT8   	aucEndIp[4]	            		;   	/* 结束地址                 */
	UINT8   	aucMask[4]	            		;   	/* 掩码                     */
	UINT8	aucReservedIp1[4];				/* 保留IP地址1 */
	UINT8	aucReservedIp2[4];				/* 保留IP地址2 */
	UINT8	aucReservedIp3[4];				/* 保留IP地址3 */	
	UINT8	aucReservedIp4[4];				/* 保留IP地址4 */	
	UINT32  	ulLease                 		;   		/* 租约期限 单位：分        */
	CHAR    	acDomainName[256]	    	;   		/* 域名后缀                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* 主用DNS服务器IP地址      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* 主用网关IP地址           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* 备用DNS服务器IP地址      */
	UINT8   	aucGatewayIpSlave[4]    	;  		/* 备用网关IP地址           */

	CHAR	acVendorName[64];		/* add by gwx 2013-3-12 for task532 制造商信息*/
	UINT32	ulVlanId1;						/* 绑定VLAN 1: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId2;						/* 绑定VLAN 2: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId3;						/* 绑定VLAN 3: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId4;						/* 绑定VLAN 4: 0~4094 0表示适用于所有VLAN */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T;

/* AC DHCP for AP 功能配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulEnableDhcpServer;			/*	DHCP功能角色*/		
	UINT32	ulEnableDhcpSnooping;		/*	启用DHCP Snooping功能*/
	UINT32	ulEnableOption43;			/*	启用Option 43功能*/
	UINT32	ulEnableOption60;		/* add by gwx 2013-3-12 for task532 option 60开关，0:关闭1:开启*/
	UINT8	aucDhcpServerMaster[4];		/*	主DHCP中继服务器地址*/
	UINT8	aucDhcpServerSlave[4];		/*	备DHCP中继服务器地址*/
	UINT8	aucAcIpMaster[4];			/*	主AC地址*/
	UINT8	aucAcIpSlave[4];				/*	备AC地址*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPGLOBALSETUP_T;

/* AC DHCP for AP 静态绑定IP配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	CHAR	acDescr[32];				/* 描述信息*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T;

/* AC DHCP for AP 动态IP地址池配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulId ;						/* 地址池编号 */
	CHAR    	acIpPoolNAme[32]	    	;   	/* 名称                     */
	UINT8   	aucBeginIp[4]	        		;   	/* 起始地址                 */
	UINT8   	aucEndIp[4]	            		;   	/* 结束地址                 */
	UINT8   	aucMask[4]	            		;   	/* 掩码                     */
	UINT8	aucReservedIp1[4];				/* 保留IP地址1 */
	UINT8	aucReservedIp2[4];				/* 保留IP地址2 */
	UINT8	aucReservedIp3[4];				/* 保留IP地址3 */	
	UINT8	aucReservedIp4[4];				/* 保留IP地址4 */	
	UINT32  	ulLease                 		;   		/* 租约期限 单位：分        */
	CHAR    	acDomainName[256]	    	;   		/* 域名后缀                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* 主用DNS服务器IP地址      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* 主用网关IP地址           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* 备用DNS服务器IP地址      */
	CHAR	acVendorName[64];		/* add by gwx 2013-3-12 for task532 制造商信息*/

	UINT32	ulVlanId1;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId2;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId3;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId4;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	/* add by gwx 2012-9-12 汉铭辽宁联通的外场需求，
	使用一台AC作为DHCP server，为多台AC的AP分配地址*/
	UINT8	aucAcIpMaster[4];			/*	主AC地址*/
	UINT8	aucAcIpSlave[4];				/*	备AC地址*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T;

/* VLAN 全局配置表*/
typedef struct 
{
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulRoamSwitch;			/* VLAN 漫游开关*/
	UINT32	ulTime;					/* VLAN漫游老化时间*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANGLOBALSETUP_T;

/* AC VLAN配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulVlanId;				/* VLAN ID */
	CHAR	acVlanName[32];			/* VLAN名称*/
	UINT32	ulVlanEnable;			/* add by gwx 2014-7-11 for dlink, vlan启用开关关*/
	UINT32	ulVlanForFitLan;			/*	FIT-LAN端口上启用	*/
	UINT32	ulVlanForFatLan;			/*	FAT-LAN端口上启用	*/
	UINT32	ulVlanForL2Wan;			/*	L2-WAN端口上启用	*/
	UINT32	ulVlanForL3Wan;			/*	L3-WAN端口上启用	*/
	UINT32	ulEnableIsolate;			/* 用户隔离 */
	UINT32	ulVlanPrio;				/* VLAN优先级*/
	CHAR	acNasId[32];				/* 热点IP */
	CHAR	acDefaultSsid[32];		/* 默认SSID */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANSETUP_T;

/* AP IP网段-VLAN映射配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT8	aucIp[4];				/*	IP地址*/
	UINT8	aucMask[4];				/* 	掩码	*/

	UINT32	ulVlanId;				/* VLAN ID */
		
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T;

/* SSID-VLAN映射配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	CHAR	acSsid[32];				/* SSID */
	UINT32	ulVlanId;				/* VLAN ID */
		
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T;

/*AC  端口-VLAN映射配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulDevId;				/* 设备ID */
	UINT32	ulIfId;				/* 端口ID */
	UINT32	ulVlanId;			/* VLAN ID */
	UINT32	ulVlanIfType;		/* VLAN端口类型*/
	UINT32	ulNestVlanId;		/*add by gwx 2014-7-11 for dlink, 外层vlan id */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIFVLANMAPPINGSETUP_T;

/* AC MAC-VLAN映射配置表*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */
	
	UINT8	aucMac[6];			/* MAC地址 */
	UINT8	aucRsv[2];			/* 填充字段 */
	UINT32	ulVlanId;				/* VLAN ID */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACMACVLANMAPPINGSETUP_T;


/* WAPI AS服务器配置*/
typedef struct 
{
	UINT32	ulAcId;				/* 设备ID */
	
	UINT8   acAsIp[4]; 				/*	AS服务器IP  */
	UINT32  ulAsPort;   				/*	AS服务器Port	*/
	UINT32  ulAsAuthCert;   			/*		AS证书验证	0：禁用 1：启用*/
	UINT32  ulCertFileSize; 			/*		AS证书文件大小	*/
	UINT8   aucCertFileContent[4096];  /*	AS证书文件内容	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPIASSETUP_T;

/* WAPI 参数配置*/
typedef struct 
{
	UINT32	ulAcId;				/* 设备ID */
	
	UINT32  ulWapiSetupId;  				/*		WAPI配置ID	0～15 */
	CHAR    acWapiSetupName[32];     		/*	    WAPI配置名称	*/
	UINT32  ulWapiCertAkm; 			 	/*		证书型AKM	0：禁用 1：启用 */
	UINT32  ulWapiPskAkm;   				/*		预共享密钥AKM	0：禁用 1：启用 */
	UINT32  ulWapiPreAuth; 				/*		WAPI预鉴权	0：禁用 1：启用 */
	UINT32  ulUnicastCipher;    			/*		单播加密套件	1：SMS4 */
	UINT32  ulUnicastKeyLen;    			/*		单播密钥长度	256 */
	UINT32  ulUnicastKeyUpdateManner;   	/*		单播密钥更新机制	1：不更新
						                                    2：基于时间
						                                    3：基于包数
						                                    4：基于时间和包数
						                                    */
	UINT32  ulUnicastKeyValidity;       		/*		单播密钥更新周期	>0 */
	UINT32  ulUnicastKeyPkgs;       		/*	    单播密钥更新包数目	>0 */
	UINT32  ulMulticastCipher;         		 /*		组播加密套件	1：SMS4 */
	UINT32  ulMulticastKeyLen;          		/*		组播密钥长度	256 */
	UINT32  ulMulticastKeyUpdateManner; 	/*		组播密钥更新机制	1：不更新
					                                            2：基于时间
					                                            3：基于包数
					                                            4：基于时间和包数
					                                    */
	UINT32  ulMulticastKeyValidity;     		/*		组播密钥有效时间	>0 */
	UINT32  ulMulticastKeyPkgs;     		/*	    组播密钥有效包数	>0 */
	UINT32  ulMulticastRekeyStrict; 		/*  	STA离开BSS后更新组播密钥	0：禁用 1：启用 */
	UINT32  ulAuthRetryTimes;		    	/*      鉴权握手协议重试次数	>0 */
	UINT32  ulMulticastRekeyRetryTimes;	/*		组播密钥握手协议重试次数	>0 */
	UINT32  ulUnicastRekeyRetryTimes;   	/*		单播密钥握手协议重试次数	>0 */
	UINT32  ulBasicKeyValidity;     			/*	    基密钥有效期	>0  */
	UINT32  ulBasicKeyReAuthThreshold;  	/*		基密钥重新鉴权的门限时间	0-100 */
	UINT32  ulSecAssociateTimeout;		/*      安全关联的超时时间	>0 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPISETUP_T;

/* WAPI 证书配置*/
typedef struct 
{
	UINT32	ulAcId;						/* 设备ID */
	
	UINT32  	ulCertId;           				/*	证书ID */
	CHAR    	acCertDesc[128];    			/*	证书描述 */
	UINT32  	ulCertFileSize; 				/*	证书文件大小 */
	UINT8   	aucCertFileContent[4096];   	/*	证书文件内容 */
	UINT8   	aucBindMac[6];  	        		/* 证书绑定的MAC地址 */
	UINT8   	aucRsv[2];                  		/* 填充字节 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPICERTFILESETUP_T;


/* AC AAA配置表*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	UINT8   	aucAuthSrvAddrMaster[4];
    	UINT32  	ulAuthSrvPortMaster;
    	CHAR    	acAuthSrvSecretMaster[32];
    	UINT8   	aucAuthSrvAddrSlave[4];
    	UINT32    ulAuthSrvPortSlave;
    	CHAR      acAuthSrvSecretSlave[32];
    	UINT8     aucAcctSrvAddrMaster[4];
    	UINT32    ulAcctSrvPortMaster;
    	CHAR      acAcctSrvSecretMaster[32];
    	UINT8     aucAcctSrvAddrSlave[4];
    	UINT32    ulAcctSrvPortSlave;
    	CHAR      acAcctSrvSecretSlave[32];
    	UINT32    ulRetryPrimaryInterval;
    	UINT32    ulAcctInterimInterval;    
	UINT32	ulAuthEchoInterval;
	UINT8	aucNasIp[4];					/* NAS IP */
	UINT32	acIsIncludeSuffix;		/* radius是否包含用户名后缀开关0:包含1:不包含*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAAASETUP_T;

/* 免认证全局配置*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulFreeSwitch;		/* 全局免认证开关 0:禁用 1:启用 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACFREEGLOBALSETUP_T;

/* 免认证IP地址列表配置*/
typedef struct {
	UINT32	ulAcId;	/*	设备ID	*/

	UINT8	aucIp[4];	/*	用户IP地址	*/
	UINT8	aucMask[4];	/*	掩码*/
	
	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
}AC_DB_TBL_ACFREEIPSETUP_T;

/* 免认证MAC列表配置*/
typedef struct {
	UINT32	ulAcId;	/*	设备ID	*/

	UINT8	aucMac[6];		/*	用户MAC地址	*/
	UINT8	aucRsv[2];		/*	reserve	*/
	
	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
}AC_DB_TBL_ACFREEMACSETUP_T;

/* 免认证SSID列表*/
typedef struct {
	UINT32	ulAcId;	/*	设备ID	*/

	CHAR	acSsid[32];	
	
	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
}AC_DB_TBL_ACFREESSIDSETUP_T;

/* 免认证VLAN列表*/
typedef struct {
	UINT32	ulAcId;	/*	设备ID	*/

	UINT32	ulVlan;
		
	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
}AC_DB_TBL_ACFREEVLANSETUP_T;

/* 2011-8-8 pyy add MAC认证全局配置*/
typedef struct
{
	UINT32	ulAcId;				/*	设备ID */
	UINT32	ulMacSwitch;			/*	MAC认证开关*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	UINT32	ulTrafficTime;			/*	MAC认证触发时间*/
	UINT32	ulTrafficThresh;		/*	MAC认证触发流量*/
	UINT32	ulMOC;				/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	对象实例标识*/
} AC_DB_TBL_ACMACSERVERSETUP_T;

/* WEB认证全局配置*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulPortalEnable;		/* 强制WEB认证 0:禁用 1:启用 */
	UINT8	aucPortalIp[4];		/* Portal服务器IP */
	CHAR	acPortalURL[64];		/* Portal服务器URL */
	UINT32	ulPortalPort;			/* Portal服务端口号*/
	UINT32	ulConcurrentAuthMaxNum;		/*		最大并发认证数目*/
	UINT32	ulReauthTimeout;				/* 重认证超时 单位:秒*/
	UINT32	ulNoTrafficTime;					/* 会话保留时长	单位:分*/
	UINT32	ulTrafficMin;			/* add by gwx 2011-10-31 for 广东移动，会话保留流量门限*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACPORTALSETUP_T;

/* Portal白名单配置*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulWhiteId;			/*	白名单ID */
	UINT8	aucWhiteIp[4];		/* IP地址*/
	UINT8	aucWhiteIpMask[4];	/*	掩码*/
	UINT16	usWhiteProto;		/*	协议*/
	UINT16	usWhitePort;			/* 端口*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWHILTELISTSETUP_T;

/* 白名单URL配置表*/
typedef struct {		
	UINT32	ulAcId;				/* 设备ID */

	UINT32	ulWhiteId;			/*	白名单ID */
	UINT8	aucWhiteUrl[64];		/* 白名单URL */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWHITEURLLISTSETUP_T;


/* 用户名地址绑定配置*/
typedef struct {
	UINT32	ulAcId;				/*	设备ID	*/
	UINT32	ulIndex;				/*	索引号	*/
	CHAR	acUserName[64];		/*	用户名	*/
	UINT8	aucUserIp[4];		/*	用户IP地址	*/
	UINT8	aucUserMac[6];		/*	用户MAC地址	*/
	UINT8	aucRsv[2];			/*	reserve	*/
	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
} AC_DB_TBL_ACUSERADDRBINDSETUP_T;





/* SSID认证配置*/
typedef struct {
	UINT32	ulAcId;

	CHAR	acSsid[32];		/* SSID */
	CHAR	acUserNameSuffix[64];	/* add by gwx 2011-11-11用户名后缀*/
	UINT32	acIsIncludeSuffix;		/* radius是否包含用户名后缀开关0:包含1:不包含*/
	UINT8	aucPortalIp[4];	/* Portal服务器IP地址*/
	CHAR	acPortalURL[64];	/* Portal服务器URL */
	UINT32	ulPortalPort;		/* Portal服务器端口*/

	UINT8   	aucAuthSrvAddrMaster[4];
    	UINT32  	ulAuthSrvPortMaster;
    	CHAR    	acAuthSrvSecretMaster[32];
    	UINT8   	aucAuthSrvAddrSlave[4];
    	UINT32    ulAuthSrvPortSlave;
    	CHAR      acAuthSrvSecretSlave[32];
    	UINT8     aucAcctSrvAddrMaster[4];
    	UINT32    ulAcctSrvPortMaster;
    	CHAR      acAcctSrvSecretMaster[32];
    	UINT8     aucAcctSrvAddrSlave[4];
    	UINT32    ulAcctSrvPortSlave;
    	CHAR      acAcctSrvSecretSlave[32];
    	UINT32    ulRetryPrimaryInterval;
    	UINT32    ulAcctInterimInterval;    
	UINT32	ulAuthEchoInterval;
	UINT8	aucNasIp[4];					/* NAS IP */
	/*add by gwx 2011-10-31 for 广东移动begin */
	UINT32	ulNoTrafficTime;		/* 会话保留时长 */
	UINT32	ulTrafficMin;			/* 会话保留流量门限	*/
	/*add by gwx 2011-10-31 for 广东移动end */

	UINT32	ulMOC;				/*	对象类标识	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 对象实例标识	*/
} AC_DB_TBL_ACSSIDAUTHSETUP_T;

/* AC PPPoE配置表*/
typedef struct {
	UINT32	ulAcId;		/* 设备ID */
	
	UINT32	ulEnablePPPoEServer;	/* 	启用PPPoE服务器功能*/
	CHAR	acPPPoEServerName[32];	/* 	PPPoE服务器名称	*/
	UINT8	aucPPPLocalIp[4];		/*	PPP连接的本端IP	*/
	UINT8	aucIpPoolStartIP[4];		/*	地址池起始地址	*/
	UINT8	aucIpPoolEndIP[4];		/*	地址池起始地址	*/
	UINT8	aucPrimaryDNS[4];		/*	主用DNS 服务器地址	*/
	UINT8	aucSlaveDNS[4];			/*	备用DNS 服务器地址	*/
	UINT32	ulAuthMode;				/*	鉴权方式	*/
	UINT32	ulPPPMtu;				/* PPP连接的发送单元大小*/
	UINT32	ulPPPMru;				/*	PPP连接的接收单元大小	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACPPPOESETUP_T;

/* AC静态路由配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32	ulRouteId;
	
	UINT8	aucDestIp[4];	/* 目标IP网段 */
	UINT8	aucNetMask[4];	/* 掩码*/
	UINT8	aucGw[4];		/* 网关 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTATICROUTESETUP_T;

/* AC RIP协议配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulRipSwitch ;				/* 是否启用RIP协议 */
	UINT32	ulIfType;				/*	被动模式		0：否1：是*/
	UINT32	ulAuthType;				/*	鉴权模式		0：不采用鉴权
															1：text明文模式
															2：MD5模式
															*/
	CHAR	acKey[72];				/*	密钥*/
	UINT32	ulSendVersion;			/*	发送版本号
									0：V1/V2模式发送
									1：V1模式发送
									2：V2模式发送*/
	UINT32	ulRecvVersion;			/*	接收版本号
									0：V1/V2模式接收
									1：V1模式接收
									2：V2模式接收
									*/

	UINT32	ulSplitHorizonOn ;		/* 是否启用水平分割 */
	UINT32	ulRedistributeStatic ; 	/* 是否重分发静态路由 */
	UINT32	ulRedistributeKernal ;	/* 是否重分发本地路由 */
	UINT32	ulUpdate ;				/* Update定时器 */
	UINT32	ulTimeout ; 				/* Timeout定时器 */
	UINT32	ulGarbage ; 				/* Garbage定时器 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACRIPGLOBALSETUP_T;

/* AC RIP的通告网段*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT8	aucNetIp[4];			/* IP网段 */
	UINT8	aucNetMask[4];		/* 掩码*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACRIPANNOUNCENETSETUP_T;


/* AC NAT全局配置表*/
typedef struct {
	UINT32	ulAcId;		/*	设备ID	1~32*/
	UINT32	ulNatSwitch;	/*	NAT开关		0：禁用1：启用*/
	UINT32	ulNatDefaultRuleOn;	/*	是否启用缺省NAT规则		0：禁用1：启用*/
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNATGLOBALSETUP_T;

/* AC NAT配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32   ulNatId;                  
	UINT32	ulNatAction;		/*	NAT类型
							0-2
							0：基本NAT
							1：端口NAT
							2：公网IP透传*/
	/* add by gwx 2013-12-10 for task1173 */
	UINT32	ulNatOutIfType;	/*NAT出端口类型0:br0 2:br2*/
							
	UINT8	aucSrcIp[4];			/*	内网IP 地址		无*/
	UINT8	aucSrcIpMask[4];		/*	内网IP掩码		无*/
	UINT8	aucNatIpBegin[4];	/*	起始外网IP地址		无*/
	UINT8	aucNatIpEnd[4];		/*	结束外网IP地址		无*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNATSETUP_T;

/* AC  MAC地址过滤策略 */
typedef struct {
	UINT32	ulAcId;				/* 设备ID */
	
	UINT32	ulVlanId;				/* VLAN ID */
	UINT32	ulMacFilterSwitch;		/* MAC过滤功能开关*/
	UINT32	ulMacFilterType;			/* MAC过滤类型*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T;

/* AC  MAC地址列表 */
typedef struct {
	UINT32	ulAcId;				/* 设备ID */
	
	UINT32	ulVlanId;				/* VLAN ID */
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T;

/* ACL全局配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32	ulAclSwitch;				/* ACL开关: 0禁用 1启用*/
	UINT32	ulAclDefaultAction;		/* ACL默认策略0丢弃 1接受*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLGLOBALSETUP_T;


/* ACL规则基本配置表*/
typedef struct {
	UINT32		ulAcId;					/* 设备ID */

	/* 匹配原则*/
	UINT32		ulRuleId				;	/* 规则号				*/
	UINT32		ulChildRuleId;			/* 规则子序号*/
	CHAR		acComment[32]		;	/* 对该服务规则的解释	*/
	UINT32		ulRuleOn;				/* 规则是否启用*/
	UINT32  		ulChainId			;	/* 规则类型0:本机访问规则 1:转发规则 */

	UINT32  		ulSrcIpMatchType	;	/* 源IP匹配策略 0:不匹配 1:正向匹配 2:反向匹配*/
	UINT8		aucSrcIp[4]			;	/* 源IP地址			    */
	UINT8		aucSrcIpMask[4]		;	/* 源IP地址的掩码		*/
	UINT32  		ulDstIpMatchType	;	/* 目的IP匹配策略 0:不匹配 1:正向匹配 2:反向匹配*/
	UINT8		aucDstIp[4]			;	/* 目的IP地址			*/
	UINT8		aucDstIpMask[4]		;	/* 目的IP地址的掩码	    */

	UINT32		ulIfMatchType;			/* 接口匹配策略
										0: 不匹配 1:入接口匹配 2:出接口匹配 3:同时匹配*/
	
	UINT32  		ulInIfId				;	/* 入接口				*/
	UINT32  		ulOutIfId			;	/* 出接口				*/



	UINT32	ulRuleProtocol;	/*	传输协议匹配		
								0：所有协议     
								1：ICMP   
								2：IGMP  
								6：TCP    
								17：UDP  
								47：GRE  
								94：IPIP  
								115：L2TP
								132：SCTP
								*/

	UINT32	ulSrcPortMatchPolicy;	/*	源端口匹配策略		0：不匹配
								1：正向匹配
								2：反向匹配
								*/
	UINT32	ulSrcPortBegin;		/*	起始源端口		1-65535 */
	UINT32	ulSrcPortEnd;		/*	结束源端口		1-65535 */
	UINT32	ulDstPortMatchPolicy;	/*	目的端口匹配策略		
									0：不匹配
									1：正向匹配
									2：反向匹配
									*/
	UINT32	ulDstPortBegin;		/*起始目的端口		1-65535*/
	UINT32	ulDstPortEnd;		/*结束目的端口		1-65535*/
	CHAR	acSsid[32];			/* 匹配SSID */
	CHAR	acUrl[64];			/* 匹配URL */
	UINT32	ulMarkMatch;		/*	匹配标记值	*/

	/*匹配动作*/
	UINT32	ulAction;		/*	规则执行的动作	
								0：丢弃
								1：接受
								2：设置标记值
								*/
	UINT32	ulLogSet;		/*	规则执行日志	
								0：关闭
								1：打开
								*/
	UINT32	ulSetMark;		/*	设置标记*/
		
	UINT32		ulMOC;
	UINT8		aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T;

/* AC IDS规则配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32  	ulIcmpFlooding	        ;   /* ICMP泛洪防护		*/   
	UINT32  	ulIcmpStatInterval	;	        /* ICMP统计间隔	 */
	UINT32 	ulIcmpFloodingThreshold;    	/* ICMP泛洪门限	*/
	
	UINT32  	ulArpFlooding	        ;   /* ARP泛洪防护 		*/   
	UINT32  ulArpStatInterval;  	/* ARP统计间隔 */
	UINT32  ulArpFloodingThreshold;	/* ARP泛洪门限 */

	UINT32  	ulUDPFlooding	        ;   /* Udp泛洪防护	    		*/   
	UINT32  ulUDPStatInterval;	        /* UDP统计间隔	 */
	UINT32  ulUDPFloodingThreshold;    /* UDP泛洪门限	*/

	UINT32  	ulTcpSynFlooding	    ;   /* TCPSYN 泛洪防护 	*/	
	UINT32  ulTcpSynStatInterval;	        /* TCP SYN统计间隔	 */
	UINT32  ulTcpSynFloodingThreshold;    /* TCP SYN 泛洪门限	*/


	UINT32  	ulDetectUdpScan	    ;   /* UDP 扫描检测		*/   
	UINT32  	ulDetectTcpScan	    ;   /* TCP 扫描检测		*/   
	UINT32  	ulDetectInvalidMac	    ;   /* 非法MAC检测	    	*/   
	UINT32  	ulDetectInvalidProto	;   /* 非法协议检测		*/   
	UINT32  	ulDetectInvalidLength	;   /* 非法报文长度检测	*/	
	UINT32  ulDetectInvalidStatInterval;	/* 非法报文统计间隔	*/
	UINT32  ulDetectInvalidThreshold;	    /* 非法报文攻击门限	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIDSRULESETUP_T;

/* AC IDS策略配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32  	ulGenEvent	        		;   /* 入侵告警			*/   
	UINT32  	ulDisableAccess	        	;   /* 禁止入侵者接入 		*/
	UINT32	ulLetOffPeriod;				/*  解禁时间*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIDSSTRATEGYSETUP_T;

/* AC P2P过滤配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32	ulP2PSwitch;		/*	P2P限制		0：禁用1：启用*/
	UINT32	ulBtCfg;			/*	BT限制		0：禁用1：启用*/
	UINT32	uleDonkeyCfg;	/*	eDonkey限制	0：禁用1：启用*/
	UINT32	ulAresCfg;		/*	Ares限制	 	0：禁用1：启用*/
	UINT32	ulFasttrackCfg;	/*	Fasttrack限制	0：禁用1：启用*/
	UINT32	ulGnutellaCfg;	/*	Gnutella限制	0：禁用1：启用*/
	UINT32	ulApplejuiceCfg;	/*	Applejuice限制	0：禁用1：启用*/
	UINT32	ulXunleiCfg;		/*	Xunlei限制	 	0：禁用1：启用*/
	UINT32	ulMuteCfg;		/*	Mute限制		0：禁用1：启用*/
	UINT32	ulSoulseak;		/*	Soulseek限制	0：禁用1：启用*/
	UINT32	ulPpliveCfg;		/*	PPLive限制		0：禁用1：启用*/
	UINT32	ulPpstreamCfg;	/*	PPStream限制	0：禁用1：启用*/
	UINT32	ulFreenetCfg;	/*	Freenet限制	0：禁用1：启用*/
	UINT32	ul100baoCfg;	/*	100bao限制 	0：禁用1：启用*/
	UINT32	ulHotLineCfg;	/*	Hotline限制	0：禁用1：启用*/
	UINT32	ulGoboogyCfg;	/*	Goboogy限制	0：禁用1：启用*/
	UINT32	ulKugooCfg;		/*	Kugoo限制		0：禁用1：启用*/
	UINT32	ulPocoCfg;		/*	Poco限制	 	0：禁用1：启用*/
	UINT32	ulTeslaCfg;		/*	Tesla限制		0：禁用1：启用*/
	UINT32	ulSoribadaCfg;	/*	Soribada限制	0：禁用1：启用*/
	UINT32	ulMsnCfg;		/*	MSN限制		0：禁用1：启用*/
	UINT32	ulQQCfg;		/*	QQ限制	 	0：禁用1：启用*/
	UINT32	ulYahooCfg;		/*	Yahoo Messager限制		0：禁用1：启用*/
	UINT32	ulSkypeCfg;		/*	Skype限制	 	0：禁用1：启用*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T;

/* AC QOS全局配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulQosSwitch;				/* QOS流控功能开关: 0/1  禁用/启用*/
	/* add by gwx 2014-6-5 for ticket52 */
	UINT32	ulUserGroupSwitch;	/* 用户组流控开关0:禁用1启用*/
	UINT32	ulQosPrioSwitch;			/* QOS优先级功能开关：0/1  禁用/启用 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACQOSGLOBALSETUP_T;

/* AC用户QOS缺省配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T;

/* 用户QOS配置*/
typedef struct 
{
	UINT32	ulAcId;

	UINT8	aucMac[6];					/* 用户MAC */
	UINT8	aucRsv[2];					/* 填充字段*/
	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACUSERQOSSETUP_T;

/* AC VLAN QOS配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulVlanId ;
	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANQOSSETUP_T;

/* AC SSID QOS配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulId ;
	CHAR	acSsid[32];
	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSSIDQOSSETUP_T;

/* AC VAP QOS配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulWtpId;
	UINT32	ulVapId;
	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVAPQOSSETUP_T;

/* AC AP QOS配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulWtpId;
	UINT32	ulUserPri;					/* 用户优先级 */
	UINT32	ulUpBand;					/* 用户上行保证带宽*/
	UINT32	ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32	ulDownBand;					/* 用户下行保证带宽*/
	UINT32	ulDownBandMax;				/* 用户下行最大带宽*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPQOSSETUP_T;
/* AC IGMP SNOOPING 配置*/
typedef struct {
	UINT32	ulAcId;				/* 设备ID */
	
	UINT32	ulIgmpSnoopSwitch;			/* 是否生效 */
	UINT32	ulRtPortTimer;				/* 路由器端口老化定时器 */
	UINT32	ulMemberPortTimer;			/* 成员端口老化定时器 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIGMPSNOOPSETUP_T;

/* AC IGMP PROXY 配置*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */
	
	UINT32	ulIgmpProxy;			/* 是否生效 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIGMPPROXYSETUP_T;

/* 2010-1-18 pyy 新增: AC 主备配置表*/
typedef struct {
	UINT32	ulAcId;		/*		设备ID	1~32*/
	UINT32	ulMsMode;	/*		工作模式	0：独立设备
								1：主机
								2：备机
								*/
	UINT32	ulEchoInterval;	/*		保活间隔
									单位：秒	1~60*/
	UINT32	ulEchoNum;		/*		保活超时次数	1~60 */
	UINT32	ulBakAcNum;	/*		备份AC数目	0～3*/
	UINT32	ulPeerAcId1;		/*		备份设备1 ID	1~32*/
	UINT8	aucPeerAcIp1[4];	/*		备份设备1 IP	无*/
	UINT8	aucPeerAcGw1[4];	/* 备份设备1缺省网关*/
	UINT8	aucPeerAcMngIp1[4];		/* add by gwx 2011-10-28 for 广州移动，备份设备1管理IP */
	UINT32	ulPeerAcState1;	/*		备份设备1状态	0:正常 1:故障 */

	UINT32	ulPeerAcId2;		/*		备份设备2 ID	1~32*/
	UINT8	aucPeerAcIp2[4];	/*		备份设备2 IP	无*/
	UINT8	aucPeerAcGw2[4];	/* 备份设备2缺省网关*/
	UINT8	aucPeerAcMngIp2[4];		/* add by gwx 2011-10-28 for 广州移动，备份设备2管理IP */
	UINT32	ulPeerAcState2;	/*		备份设备2状态	0:正常 1:故障 */
	
	UINT32	ulPeerAcId3;		/*		备份设备3 ID	1~32*/
	UINT8	aucPeerAcIp3[4];	/*		备份设备3 IP	无*/
	UINT8	aucPeerAcGw3[4];	/* 备份设备3缺省网关*/
	UINT8	aucPeerAcMngIp3[4];		/* add by gwx 2011-10-28 for 广州移动，备份设备3管理IP */
	UINT32	ulPeerAcState3;	/*		备份设备3状态	0:正常 1:故障 */
	
	UINT32	ulCurBakAcId;	/*		当前接管的AC ID	0：无效值
									1~32 */

	UINT32	ulEnableVrrp;		/*		VRRP开关*/
	UINT8	aucVrrpIp1[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp2[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp3[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp4[4];		/*	虚拟IP4 */
	UINT8	aucVrrpIp5[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp6[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp7[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp8[4];		/*	虚拟IP4 */
	UINT8	aucVrrpIp9[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp10[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp11[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp12[4];		/*	虚拟IP4 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACMSSETUP_T;


/* AC  告警过滤配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulAlarmNo;
	CHAR	acAlarmName[32];
	UINT32	ulAlarmIsValid;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACALARMFILTERSETUP_T;

/* AC  告警门限配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32  ulAlarmResendWaitingTime;		/* 告警重发等待时间 */
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

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACALARMTHRESHOLDSETUP_T;


/* AC性能计数器组配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT32	ulCounterGroupId;
	UINT32	ulCounterGroupIsInvalid;
    UINT32	ulCounterGroupPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T;

/* AP访问策略配置表*/
typedef struct
{
	UINT32	ulAcId;			/* 设备ID */

	UINT32	ulFtp;
	UINT32	ulTelnet;
	UINT32	ulWeb;
	CHAR	acPasswd[32];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPACLSETUP_T;

/* AP设备ID段-NAS ID映射配置表*/
typedef struct
{
	UINT32	ulAcId;			/* 设备ID */

	UINT32	ulApIdStart;		/*	起始AP设备ID	*/
	UINT32	ulApIdEnd;		/*	结束AP设备ID	*/
	CHAR	acSsid[32];		/*	SSID	*/
	CHAR	acNasId[256];	/*	热点ID	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPIDNASSETUP_T;

/* AP IP网段-NAS ID映射配置表*/
typedef struct
{
	UINT32	ulAcId;			/* 设备ID */

	UINT8	aucIp[4];		/*	IP地址	*/
	UINT8	aucMask[4];		/*	掩码	*/
	CHAR	acSsid[32];		/*	SSID	*/
	CHAR	acNasId[256];	/*	热点ID	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPIPNASSETUP_T;


/* 以下为动态表*/
/* 用户表关系表结构体定义*/	
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];
    	CHAR    	acUserName[256];
    	UINT8    	aucIp[4];
    	UINT32	ulUserType;			/* 用户类型*/
    	UINT32	ulPriority;			/* 用户优先级 */
	UINT32	ulUpBandMax;		/* 用户最大上行带宽 */
	UINT32	ulUpBandMin;		/* 用户保证上行带宽 */
	UINT32	ulDownBandMax;		/* 用户最大下行带宽 */
	UINT32	ulDownBandMin;		/* 用户保证下行带宽 */
    
    	UINT32	ulWtpId;
    	UINT32	ulVDevId;
    	UINT32	ulIfId;
	UINT32	ulVapId;
	UINT8	aucVapMac[6];		/* 当前接入的VAP MAC */
	UINT8	aucRsv1[2];			/* 填充字节*/
	CHAR	acVapSsid[32];		/* 当前接入的VAP SSID */

	UINT8	aucNasIp[4];				/* NAS IP */
	CHAR	acNasId[256];			/* NAS ID */
	UINT32	ulAcctInterimInterval;	/* 计费信息上报间隔*/
	UINT32	ulSessionTimeout;		/* 会话超时时间*/
	UINT32	ulIdleTimeout;			/* add by gwx 2012-6-4 for bug1101 无流量下线时间*/
	UINT32    ulAssocId ;  			
        
    	UINT32	ulPosX;
    	UINT32	ulPosY;

	UINT32	ulCertType;		/* 认证类型*/
    	UINT32	ulCertState;		/* 认证状态*/
    	UINT32	ulCertStateOkTime;	/* 认证状态变为已认证的时间点*/
    	UINT32	ulVlanId;		/* 用户归属的VLAN ID */

    	UINT32	ulHandover;		/* 0:未切换	1:切换 */

    	UINT32	ulCreateTime;   	/* 该用户创建时间 */
    	UINT32  	ulUpdateTime;   	/* 用户占用时间统计最后更新时间 */

    	UINT32	ulSessionStartTime;	/* 会话起始时间: 用于检查session timeout */

	/* 流量统计信息*/
    	UINT32	ulRxBytes;		/* 当前获取到:接收包数*/
    	UINT32	ulTxBytes;		/* 当前获取到:发送包数*/
    	UINT32	ulCheckTime;		/* 会话保留时长计时基准时间*/
	UINT32	ulNoTrafficTime;		/* 该用户的会话保留时长单位为分钟*/
	UINT32	ulTrafficMin;			/* 用户会话保留时长内的流量门限*/
	UINT32	ulWpaOffTag;		/* 1:无流量异常下线0:初始化值add by gwx 2012-2-2*/

    	/* 2011-8-9 pyy add: MAC认证功能*/
    	UINT32	ulMacState;			/* MAC认证状态: 未认证/已认证*/
    	CHAR	acUserAgent[256];		/* User Agent */
    	UINT32	ulCurRxBytes;		/* 接收字节数*/
    	UINT32	ulCurTxBytes;		/* 发送字节数*/

    	UINT32	ulLastStatRxBytes;	/* 最后一个MAC认证触发周期的接收字节数*/
    	UINT32	ulLastStatTxBytes;	/* 最后一个MAC认证触发周期的发送字节数*/
    	UINT32	ulLastStatTime;		/* 最后一个MAC认证触发周期的字节数更新时间*/

	/* add by gwx 2012-10-31 for 用户流量不准确*/
	UINT32	ulUserRxPkts;		/* 用户的下行包数*/
	UINT32	ulUserTxPkts;		/* 用户的上行包数*/
	UINT32	ulUserCurRx4GB;		/* 用户下行流量进制位*/
	UINT32	ulUserCurRxBytes;	/* 用户下行流量*/
	UINT32	ulUserCurTx4GB;		/* 用户上行流量进制位*/
	UINT32	ulUserCurTxBytes;	/* 用户上行流量*/
	/* add by gwx 2011-11-2 */
	UINT32	ulAuthType;			/* 用户验证类型*/
	/* add by gwx 2013-10-14 for task1076 企业网用户组流控*/
#if 0
	UINT32	ulUserGroupId;		/* 用户组ID */
#else
	CHAR	acUserGroupName[128];	/* 用户组名*/
#endif
	/* add by gwx 2014-5-13 for 锐捷，AP上报用户信息*/
	UINT32	ulUserRssi;
	/* add by gwx 2014-9-3 添加终端设备类型*/
	CHAR	acStaType[32];
    	
}AC_DB_TBL_ACUSER_T;

/* 用户VLAN 漫游表*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

    	UINT32	ulWtpId;
    	UINT32	ulVDevId;
    	UINT32	ulIfId;
	UINT32	ulVapId;
	CHAR	acSsid[32];
	
    	UINT32	ulVlanId;		/* 缓存VLAN ID */
    	UINT32	ulCreateTime;   	/* 缓存起始时间*/
}AC_DB_TBL_ACUSERVLAN_T;

/* 上报事件记录关系表结构体定义*/
typedef struct {
	UINT32 	ulEventId;
	UINT32	ulEventReasonId;
	UINT32 	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
	UINT32 	ulCommonInfo;
	UINT32	ulEventRaiseTime;
} AC_DB_TBL_ACDYNEVENT_T;

/* IDS黑名单用户关系表结构体定义*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

    	UINT32	ulCreateTime;   	/* 该用户创建时间 */
    	UINT32	ulUpdateTime;	/* 用户更新时间*/
    	UINT32	ulReason;		/* 该用户加入黑名单的原因*/
} AC_DB_TBL_ACIDSUSER_T;

/* 用户Portal 认证状态关系表结构体定义*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

	UINT32	ulCertType;
    	UINT32	ulPortalState;		/* Portal认证状态*/
    	UINT32	ulMacState;	
    	UINT32	ulCreateTime;   	/* 缓存起始时间*/

    	CHAR    	acUserName[256];	/* 2009-11-17 pyy 缓存用户名*/
    	CHAR	acSsid[32];
	UINT32   ulSessionTimeout;    /**  为了使用户的session-timeout消息可以被继承，chary，2011.6.20   **/
	UINT32 	ulIdleTimeout; 	/* add by gwx 2012-6-4 for bug1101 无流量空闲时长*/
	/* add by gwx 2011-11-16 */
	UINT32   ulWtpId;
	UINT32   ulDevId;
	UINT32   ulVapId;
	UINT32   ulCertStateOkTime;
	
	UINT32	ulAuthType;			/* add by gwx 2012-3-21 for 移动自动认证需求*/
#if 0
	UINT32	ulUserGroupId;		/* add by gwx 2013-10-18 for task1076 企业网用户组流控*/
#else
	CHAR	acUserGroupName[128];
#endif
	UINT8	aucUserIp[4];	/* add by gwx 2014-4-15 for bug5293 */
} AC_DB_TBL_ACPORTALUSER_T;
/* 历史终端接入信息关系表结构体定义*/
/* 关键字为Mac+WtpId+VapId */
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32	ulWtpId;
	UINT32	ulVapId;
	UINT32	ulOnlineTime;
} AC_DB_TBL_ACUSERACCINFO_T;

/* 终端IP分配信息关系表结构体定义*/
/* 关键字为aucIp */
typedef struct
{
	UINT8	aucIp[4];	/* IP */
	UINT8	aucMac[6];	/* 最近一次分配到这个IP地址的终端的MAC地址*/
	UINT8	aucRsv[2];	/* 填充字节*/
	UINT32	ulWtpId;		/* 最近一次分配到这个IP地址的终端接入的AP设备ID */
	UINT32	ulVapId;		/* 最近一次分配到这个IP地址的终端接入的VAP ID */
	CHAR	acVapSsid[32];
	UINT32	ulTime;		/* 最近一次这个IP地址被分配的时间点*/
	UINT32	ulAcLanId;	/* AC 端口 0~15 显示LANx >=16 则显示N/A*/
} AC_DB_TBL_ACUSERIPINFO_T;

/* 2011-1-12 pyy add : 历史终端表*/
typedef struct
{
	UINT32	ulWtpId;
	UINT8	aucMac[6];	/* 最近一次分配到这个IP地址的终端的MAC地址*/
	UINT8	aucRsv[2];	/* 填充字节*/
} AC_DB_TBL_ACHISTORYUSER_T;

/* add by gwx  2011-9-29 end*/
typedef	struct
{
	UINT32	ulAcId;			/*设备ID */
	CHAR	acNasId[32];		/*热点ID*/
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNASIDSETUP_T;
/* ssidMAC服务配置表*/
typedef struct 
{
	UINT32	ulAcId;			/*设备ID */
	CHAR	acSsid[32];			/*SSID*/
	UINT32	ulMacSwitch;			/*	MAC认证开关*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	UINT32	ulTrafficTime;			/*	MAC认证触发时间*/
	UINT32	ulTrafficThresh;		/*	MAC认证触发流量*/
	UINT32	ulMOC;				/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	对象实例标识*/
}AC_DB_TBL_ACSSIDMACSERVERSETUP_T;

/* add by gwx 2013-10-11 for task1076 企业网用户组流控需求*/
typedef struct 
{
	UINT32	ulAcId;					/*设备ID */
	UINT32	ulUserGroupId;			/* 用户组ID */
	CHAR	acUserGroupName[128];	/* 用户组名*/
	/* add by gwx 2014-6-5 for ticket52 begin */
	UINT32	ulPriority;	/*用户组接入优先级1-3 */
	UINT32	ulUserGroupUpBandMax;		/*用户组上行带宽控制*/
	UINT32	ulUserGroupDownBandMax;	/* 用户组下行带宽控制*/
	/* add by gwx 2014-6-5 for ticket52 end */
	
	UINT32	ulMOC;					/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	对象实例标识*/
}AC_DB_TBL_ACUSERGROUPSETUP_T;


/* add by gwx 2014-6-25 for SSID级用户控制接入begin */
typedef struct 
{
	UINT32	ulAcId;					/*设备ID */
	UINT32	ulId;					/* 记录ID */
	CHAR	acSsidName[32];			/* SSID 名称*/
	UINT32	ulUserAccessCtrlType;	/* 接入控制模式配置,黑1/白0名单模式*/
	
	UINT32	ulMOC;					/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	对象实例标识*/
}AC_DB_TBL_ACSSIDACCESSSETUP_T;

typedef struct 
{
	UINT32	ulAcId;					/*设备ID */
	UINT32	ulId;					/* 记录ID */
	UINT8	aucUserMac[6];			/* 用户MAC(OUI) */
	UINT8	aucRsv[2];				/*  保留字段*/
	CHAR	acSsidName[32];			/* SSID 名称*/
	UINT32	ulOuiSwitch;				/* OUI模式启用开关0禁用1启用*/
	UINT32	ulOuiLen;				/* OUI长度匹配*/
	
	UINT32	ulMOC;					/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	对象实例标识*/
}AC_DB_TBL_ACSSIDACCESSLISTSETUP_T;

/* add by gwx 2014-6-25 for SSID级用户控制接入end */

/* add by gwx 2011-11-2 for 广东移动，新增AC认证统计表*/
typedef struct
{
	UINT32	ulAcId;				/* 设备ID */
	UINT32 ulPortalAuthTime;			/*Portal认证终端鉴权次数*/
	UINT32 ulAssociateAuthTime;         	/*关联认证终端鉴权次数*/
	UINT32 ulMacAuthTime;				/*MAC认证终端鉴权次数*/
#if 0
	UINT32 ulPortalAuthFailTime;        	 /*Portal认证终端鉴权失败次数*/
	UINT32 ulAssociateAuthFailTime;		/*关联认证终端鉴权失败次数*/
	UINT32 ulMacAuthFailTime;             /*MAC认证终端鉴权失败次数*/
#endif
	UINT32 ulPortalAuthSuccNum;	        /*Portal认证终端鉴权成功次数*/
	UINT32 ulAssociateAuthSuccNum;	 	/*关联认证终端鉴权成功次数*/
	UINT32 ulMacAuthSuccNum;	        /*MAC认证终端鉴权成功次数*/
	UINT32 ulPortalOfflineUserNum;          	/*Portal认证用户异常下线次数*/
	UINT32 ulFreeOfflineUserNum;            	/*免认证用户异常下线次数*/
	UINT32 ulAssociateOfflineUserNum;   		/*关联认证用户异常下线次数*/
	UINT32 ulMacOfflineUserNum; 				/*MAC认证用户异常下线次数*/
}AC_DB_TBL_ACAUTHSTAT_T;


/* add by gwx 2012-11-2 for 用户流量不准确
新增用户定时器表*/
typedef struct
{
	UINT8	aucMac[6];						/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32 	ulWtpId;
	UINT32	ulDelRecTag;					/* 记录删除标记*/
	UINT32	ulStartTrafficTimerId;			/* 开始统计流量的定时器TimerId */
	UINT32 	ulStopTrafficTimerId;			/* 停止统计流量的定时器TimerId */
	UINT32	ulStartTrafficMsgSendTimes;		/* 开始统计流量消息的重传次数 */
	UINT32 	ulStopTrafficMsgSendTimes;		/* 停止统计流量消息的重传次数 */
	/* add by gwx 2013-1-10 for task359 */
	UINT32	ulWaitStopGetTimerId;			/*  等待account  获取stop流量定时器*/
	UINT32	ulVlan;
	
	UINT32 	ulUserRxPkts;					/* 用户下行包数 */
	UINT32	ulUserTxPkts;					/* 用户上行包数 */
	UINT32	ulUserRx4GB;					/* 超过字段类型范围的进制位 */
	UINT32	ulUserTxBytes;					/* 用户当前的上行流量 */
	UINT32	ulUserTx4GB;					/* 超过字段类型范围的进制位 */
	UINT32	ulUserRxBytes;					/* 用户当前的下行流量 */

	UINT32 	ulUserHistoryRxPkts;					/* 用户历史下行包数 */
	UINT32	ulUserHistoryTxPkts;					/* 用户历史上行包数 */
	UINT32	ulUserHistoryRx4GB;					/* 超过字段类型范围的进制位 */
	UINT32	ulUserHistoryTxBytes;				/* 用户历史上行流量 */
	UINT32	ulUserHistoryTx4GB;					/* 超过字段类型范围的进制位 */
	UINT32	ulUserHistoryRxBytes;				/* 用户历史下行流量 */

	/* add by gwx 2013-3-27 for bug2244 begin*/
	UINT32 	ulLastUserRxPkts;					/*AP上一次上报的 用户下行包数 */
	UINT32	ulLastUserTxPkts;					/*AP上一次上报的 用户上行包数 */
	UINT32	ulLastUserRx4GB;					/*AP上一次上报的 超过字段类型范围的进制位 */
	UINT32	ulLastUserTxBytes;					/*AP上一次上报的 用户当前的上行流量 */
	UINT32	ulLastUserTx4GB;					/* AP上一次上报的超过字段类型范围的进制位 */
	UINT32	ulLastUserRxBytes;					/* AP上一次上报的用户当前的下行流量 */

	UINT32 	ulBasicUserRxPkts;					/* 用户下行包数(基础值) */
	UINT32	ulBasicUserTxPkts;					/* 用户上行包数(基础值) */
	UINT32	ulBasicUserRx4GB;					/* 超过字段类型范围的进制位(基础值) */
	UINT32	ulBasicUserTxBytes;					/* 用户当前的上行流量 (基础值)*/
	UINT32	ulBasicUserTx4GB;					/* 超过字段类型范围的进制位 (基础值)*/
	UINT32	ulBasicUserRxBytes;					/* 用户当前的下行流量澹(基础值) */
	/* add by gwx 2013-3-27 for bug2244 end*/

}AC_DB_TBL_ACUSERTIMER_T;

/* AC  连接配置表*/
typedef struct {
	UINT32	ulAcId;					/* 设备ID */

	UINT8	aucAcLinkIp[4];
    UINT8   aucAcMappingIp[4];
    
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACLINKIPLISTSETUP_T;
/* AC 关系表结构体定义结束*/
/******************************************************************************/


/******************************************************************************/
/* 变量声明开始*/
/* AC基本配置表*/
extern DBHANDLE	ghAcBasicSetup;
extern DBHANDLE	gidxAcBasicSetup1;
extern DBHANDLE	gidxAcBasicSetup10;

/* AC关联配置表*/
extern DBHANDLE	ghAcWtpAssociateSetup;
extern DBHANDLE	gidxAcWtpAssociateSetup1;
extern DBHANDLE	gidxAcWtpAssociateSetup2;
extern DBHANDLE	gidxAcWtpAssociateSetup10;

/* 上行链路检查配置表*/
extern DBHANDLE	ghAcKeeperSetup;
extern DBHANDLE	gidxAcKeeperSetup1;
extern DBHANDLE	gidxAcKeeperSetup10;

/* 邻居关系配置表*/
extern DBHANDLE	ghAcNeighborSetup;
extern DBHANDLE	gidxAcNeighborSetup1;
extern DBHANDLE	gidxAcNeighborSetup2;
extern DBHANDLE	gidxAcNeighborSetup10;

/* SNMP V2配置*/
extern DBHANDLE	ghAcSysSnmpV2Setup;
extern DBHANDLE	gidxAcSysSnmpV2Setup1;
extern DBHANDLE	gidxAcSysSnmpV2Setup10;

/* SNMP V3配置*/
extern DBHANDLE	ghAcSysSnmpV3Setup;
extern DBHANDLE	gidxAcSysSnmpV3Setup1;
extern DBHANDLE	gidxAcSysSnmpV3Setup10;

/* SNMP TRAP 配置*/
extern DBHANDLE	ghAcSysTrapSvrSetup;
extern DBHANDLE	gidxAcSysTrapSvrSetup1;
extern DBHANDLE	gidxAcSysTrapSvrSetup10;

/* SNTP服务器配置*/
extern DBHANDLE	ghAcSntpGlobalSetup;
extern DBHANDLE	gidxAcSntpGlobalSetup1;
extern DBHANDLE	gidxAcSntpGlobalSetup10;

/* 日志配置*/
extern DBHANDLE	ghAcLogSetup;
extern DBHANDLE	gidxAcLogSetup1;
extern DBHANDLE	gidxAcLogSetup10;

/* 日志服务器配置*/
extern DBHANDLE	ghAcLogServerSetup;
extern DBHANDLE	gidxAcLogServerSetup1;
extern DBHANDLE	gidxAcLogServerSetup10;

/* AC支持的AP软件版本列表配置*/
extern DBHANDLE	ghAcAssocSwVerSetup;
extern DBHANDLE	gidxAcAssocSwVerSetup1;
extern DBHANDLE	gidxAcAssocSwVerSetup10;

/* 物理端口配置*/
extern DBHANDLE	ghAcIfSetup;
extern DBHANDLE	gidxAcIfSetup1;
extern DBHANDLE	gidxAcIfSetup2;
extern DBHANDLE	gidxAcIfSetup10;

/* 端口IP地址配置*/
extern DBHANDLE	ghAcIpSetup;
extern DBHANDLE	gidxAcIpSetup1;
extern DBHANDLE	gidxAcIpSetup10;

/* 用户级DHCP服务配置*/
extern DBHANDLE	ghAcStaDhcpGlobalSetup;
extern DBHANDLE	gidxAcStaDhcpGlobalSetup1;
extern DBHANDLE	gidxAcStaDhcpGlobalSetup10;

extern DBHANDLE	ghAcStaDhcpStaticIpAddrSetup;
extern DBHANDLE	gidxAcStaDhcpStaticIpAddrSetup1;
extern DBHANDLE	gidxAcStaDhcpStaticIpAddrSetup10;

extern DBHANDLE	ghAcStaDhcpDynamicIpAddrSetup;
extern DBHANDLE	gidxAcStaDhcpDynamicIpAddrSetup1;
extern DBHANDLE	gidxAcStaDhcpDynamicIpAddrSetup10;

/* AP级DHCP服务配置*/
extern DBHANDLE	ghAcApDhcpGlobalSetup;
extern DBHANDLE	gidxAcApDhcpGlobalSetup1;
extern DBHANDLE	gidxAcApDhcpGlobalSetup10;

extern DBHANDLE	ghAcApDhcpStaticIpAddrSetup;
extern DBHANDLE	gidxAcApDhcpStaticIpAddrSetup1;
extern DBHANDLE	gidxAcApDhcpStaticIpAddrSetup10;

extern DBHANDLE	ghAcApDhcpDynamicIpAddrSetup;
extern DBHANDLE	gidxAcApDhcpDynamicIpAddrSetup1;
extern DBHANDLE	gidxAcApDhcpDynamicIpAddrSetup10;

/* VLAN全局配置*/
extern DBHANDLE	ghAcVlanGlobalSetup;
extern DBHANDLE	gidxAcVlanGlobalSetup1;
extern DBHANDLE	gidxAcVlanGlobalSetup10;

/* VLAN配置表*/
extern DBHANDLE	ghAcVlanSetup;
extern DBHANDLE	gidxAcVlanSetup1;
extern DBHANDLE	gidxAcVlanSetup10;

/* AP IP网段-VLAN映射配置表*/
extern DBHANDLE	ghAcApIpVlanMappingSetup;
extern DBHANDLE	gidxAcApIpVlanMappingSetup1;
extern DBHANDLE	gidxAcApIpVlanMappingSetup10;

/* SSID-VLAN映射配置表*/
extern DBHANDLE	ghAcSsidVlanMappingSetup;
extern DBHANDLE	gidxAcSsidVlanMappingSetup1;
extern DBHANDLE	gidxAcSsidVlanMappingSetup10;

/* 端口-VLAN映射配置表*/
extern DBHANDLE	ghAcIfVlanMappingSetup;
extern DBHANDLE	gidxAcIfVlanMappingSetup1;
extern DBHANDLE	gidxAcIfVlanMappingSetup10;

/* MAC-VLAN映射配置表*/
extern DBHANDLE	ghAcMacVlanMappingSetup;
extern DBHANDLE	gidxAcMacVlanMappingSetup1;
extern DBHANDLE	gidxAcMacVlanMappingSetup10;

/* AS服务器配置表*/
extern DBHANDLE	ghAcWapiAsSetup;
extern DBHANDLE	gidxAcWapiAsSetup1;
extern DBHANDLE	gidxAcWapiAsSetup10;

/* WAPI参数配置表*/
extern DBHANDLE	ghAcWapiSetup;
extern DBHANDLE	gidxAcWapiSetup1;
extern DBHANDLE	gidxAcWapiSetup10;

/* WAPI证书配置表*/
extern DBHANDLE	ghAcWapiCertFileSetup;
extern DBHANDLE	gidxAcWapiCertFileSetup1;
extern DBHANDLE	gidxAcWapiCertFileSetup10;

/* AAA服务器配置表*/
extern DBHANDLE	ghAcAAASetup;
extern DBHANDLE	gidxAcAAASetup1;
extern DBHANDLE	gidxAcAAASetup10;

/* 免认证全局配置*/
extern DBHANDLE	ghAcFreeGlobalSetup;
extern DBHANDLE	gidxcFreeGlobalSetup1;
extern DBHANDLE	gidxcFreeGlobalSetup10;

/* 免认证IP配置*/
extern DBHANDLE	ghAcFreeIpSetup;
extern DBHANDLE	gidxAcFreeIpSetup1;
extern DBHANDLE	gidxAcFreeIpSetup10;

/* 免认证MAC配置*/
extern DBHANDLE	ghAcFreeMacSetup;
extern DBHANDLE	gidxAcFreeMacSetup1;
extern DBHANDLE	gidxAcFreeMacSetup10;

/* 免认证SSID列表*/
extern DBHANDLE	ghAcFreeSsidSetup;
extern DBHANDLE	gidxAcFreeSsidSetup1;
extern DBHANDLE	gidxAcFreeSsidSetup10;

/* 免认证VLAN列表*/
extern DBHANDLE	ghAcFreeVlanSetup;
extern DBHANDLE	gidxAcFreeVlanSetup1;
extern DBHANDLE	gidxAcFreeVlanSetup10;

/* WEB认证全局配置*/
extern DBHANDLE	ghAcPortalSetup;
extern DBHANDLE	gidxAcPortalSetup1;
extern DBHANDLE	gidxAcPortalSetup10;

/* MAC认证全局配置*/
extern DBHANDLE	ghAcMacServerSetup;
extern DBHANDLE	gidxAcMacServerSetup1;
extern DBHANDLE	gidxAcMacServerSetup10;

/* 白名单配置*/
extern DBHANDLE	ghAcWhilteListSetup;
extern DBHANDLE	gidxAcWhilteListSetup1;
extern DBHANDLE	gidxAcWhilteListSetup10;

/* 白名单URL 配置*/
extern DBHANDLE	ghAcWhiteUrlListSetup;
extern DBHANDLE	gidxAcWhiteUrlListSetup1;
extern DBHANDLE	gidxAcWhiteUrlListSetup10;

/* 用户名地址绑定配置*/
extern DBHANDLE	ghAcUserAddrBindSetup;
extern DBHANDLE	gidxAcUserAddrBindSetup1;
extern DBHANDLE	gidxAcUserAddrBindSetup2;
extern DBHANDLE	gidxAcUserAddrBindSetup10;

/* SSID认证配置*/
extern DBHANDLE	ghAcSsidAuthSetup;
extern DBHANDLE	gidxAcSsidAuthSetup1;
extern DBHANDLE	gidxAcSsidAuthSetup10;

/* PPPoE认证配置*/
extern DBHANDLE	ghAcPPPoESetup;
extern DBHANDLE	gidxAcPPPoESetup1;
extern DBHANDLE	gidxAcPPPoESetup10;

/* 静态路由配置*/
extern DBHANDLE	ghAcStaticRouteSetup;
extern DBHANDLE	gidxAcStaticRouteSetup1;
extern DBHANDLE	gidxAcStaticRouteSetup2;
extern DBHANDLE	gidxAcStaticRouteSetup10;

/* RIP协议配置*/
extern DBHANDLE	ghAcRipGlobalSetup;
extern DBHANDLE	gidxAcRipGlobalSetup1;
extern DBHANDLE	gidxAcRipGlobalSetup10;

/* RIP通告网段配置*/
extern DBHANDLE	ghAcRipAnnounceNetSetup;
extern DBHANDLE	gidxAcRipAnnounceNetSetup1;
extern DBHANDLE	gidxAcRipAnnounceNetSetup10;

/* NAT全局配置*/
extern DBHANDLE	ghAcNatGlobalSetup;
extern DBHANDLE	gidxAcNatGlobalSetup1;
extern DBHANDLE	gidxAcNatGlobalSetup10;

/* NAT规则配置*/
extern DBHANDLE	ghAcNatSetup;
extern DBHANDLE	gidxAcNatSetup1;
extern DBHANDLE	gidxAcNatSetup10;

/* MAC地址过滤策略*/
extern DBHANDLE	ghAcVlanAccessMacPolicySetup;
extern DBHANDLE	gidxAcVlanAccessMacPolicySetup1;
extern DBHANDLE	gidxAcVlanAccessMacPolicySetup10;

/* MAC地址过滤列表*/
extern DBHANDLE	ghAcVlanAccessMacListSetup;
extern DBHANDLE	gidxAcVlanAccessMacListSetup1;
extern DBHANDLE	gidxAcVlanAccessMacListSetup10;

/* ACL全局配置*/
extern DBHANDLE	ghAcFirewallGlobalSetup;
extern DBHANDLE	gidxAcFirewallGlobalSetup1;
extern DBHANDLE	gidxAcFirewallGlobalSetup10;

/* ACL规则配置*/
extern DBHANDLE	ghAcFirewallRuleBasicSetup;
extern DBHANDLE	gidxAcFirewallRuleBasicSetup1;
extern DBHANDLE	gidxAcFirewallRuleBasicSetup10;

/* IDS规则配置*/
extern DBHANDLE	ghAcIdsRuleSetup;
extern DBHANDLE	gidxAcIdsRuleSetup1;
extern DBHANDLE	gidxAcIdsRuleSetup10;

/* IDS策略配置*/
extern DBHANDLE	ghAcIdsStrategySetup;
extern DBHANDLE	gidxAcIdsStrategySetup1;
extern DBHANDLE	gidxAcIdsStrategySetup10;

/* P2P过滤配置*/
extern DBHANDLE	ghAcFirewallL7MatchSetup;
extern DBHANDLE	gidxAcFirewallL7MatchSetup1;
extern DBHANDLE	gidxAcFirewallL7MatchSetup10;

/* QoS全局配置*/
extern DBHANDLE	ghAcQosGlobalSetup;
extern DBHANDLE	gidxAcQosGlobalSetup1;
extern DBHANDLE	gidxAcQosGlobalSetup10;

/* 默认的用户QoS配置*/
extern DBHANDLE	ghAcQosUserDefaultSetup;
extern DBHANDLE	gidxAcQosUserDefaultSetup1;
extern DBHANDLE	gidxAcQosUserDefaultSetup10;

/* 用户QoS配置*/
extern DBHANDLE	ghAcUserQosSetup;
extern DBHANDLE	gidxAcUserQosSetup1;
extern DBHANDLE	gidxAcUserQosSetup10;

/* VLAN域用户QoS配置*/
extern DBHANDLE	ghAcVlanQosSetup;
extern DBHANDLE	gidxAcVlanQosSetup1;
extern DBHANDLE	gidxAcVlanQosSetup10;

/* SSID域用户QoS配置 */
extern DBHANDLE	ghAcSsidQosSetup;
extern DBHANDLE	gidxAcSsidQosSetup1;
extern DBHANDLE	gidxAcSsidQosSetup2;
extern DBHANDLE	gidxAcSsidQosSetup10;

/* VAP域用户QoS配置 */
extern DBHANDLE	ghAcVapQosSetup;
extern DBHANDLE	gidxAcVapQosSetup1;
extern DBHANDLE	gidxAcVapQosSetup10;

/* AP域用户QoS配置 */
extern DBHANDLE	ghAcApQosSetup;
extern DBHANDLE	gidxAcApQosSetup1;
extern DBHANDLE	gidxAcApQosSetup10;
/* IGMP Snoop配置*/
extern DBHANDLE	ghAcIgmpSnoopSetup;
extern DBHANDLE	gidxAcIgmpSnoopSetup1;
extern DBHANDLE	gidxAcIgmpSnoopSetup10;

/* IGMP Proxy配置*/
extern DBHANDLE	ghAcIgmpProxySetup;
extern DBHANDLE	gidxAcIgmpProxySetup1;
extern DBHANDLE	gidxAcIgmpProxySetup10;

/* 2010-1-18 pyy 新增*/
/* 主备配置*/
extern DBHANDLE	ghAcMsSetup;
extern DBHANDLE	gidxAcMsSetup1;
extern DBHANDLE	gidxAcMsSetup10;

/* 告警过滤配置*/
extern DBHANDLE	ghAcAlarmFilterSetup;
extern DBHANDLE	gidxAcAlarmFilterSetup1;
extern DBHANDLE	gidxAcAlarmFilterSetup10;

/* 告警门限配置*/
extern DBHANDLE	ghAcAlarmThresholdSetup;
extern DBHANDLE	gidxAcAlarmThresholdSetup1;
extern DBHANDLE	gidxAcAlarmThresholdSetup10;

/* 性能计数器组配置*/
extern DBHANDLE	ghAcPerfCounterGroupInfoSetup;
extern DBHANDLE	gidxAcPerfCounterGroupInfoSetup1;
extern DBHANDLE	gidxAcPerfCounterGroupInfoSetup10;

/* 2010-6-24 pyy 新增*/
extern DBHANDLE	ghAcApAclSetup;
extern DBHANDLE	gidxAcApAclSetup1;
extern DBHANDLE	gidxAcApAclSetup10;

extern DBHANDLE	ghAcApIdNasSetup;
extern DBHANDLE	gidxAcApIdNasSetup1;
extern DBHANDLE	gidxAcApIdNasSetup10;

extern DBHANDLE	ghAcApIpNasSetup;
extern DBHANDLE	gidxAcApIpNasSetup1;
extern DBHANDLE	gidxAcApIpNasSetup10;

extern DBHANDLE	ghAcUser;
extern DBHANDLE	gidxAcUser1;
extern DBHANDLE	gidxAcUser2;
extern DBHANDLE	gidxAcUser3;
extern DBHANDLE	gidxAcUser4;

extern DBHANDLE	ghAcUserVlan;
extern DBHANDLE	gidxAcUserVlan1;

extern DBHANDLE	ghAcDynEvent;
extern DBHANDLE	gidxAcDynEvent1;

extern DBHANDLE	ghAcIdsUser;
extern DBHANDLE	gidxAcIdsUser1;

extern DBHANDLE	ghAcPortalUser;
extern DBHANDLE	gidxAcPortalUser1;
extern DBHANDLE	gidxAcPortalUser2;

extern DBHANDLE	ghAcUserAccInfo;
extern DBHANDLE	gidxAcUserAccInfo1;
extern DBHANDLE	gidxAcUserAccInfo2;

extern DBHANDLE	ghAcUserIpInfo;
extern DBHANDLE	gidxAcUserIpInfo1;

/* 2011-1-12 pyy add */
extern DBHANDLE	ghAcHistoryUser;
extern DBHANDLE	gidxAcHistoryUser1;

/*nasid表*/
extern DBHANDLE	ghAcNasIdSetup;
extern DBHANDLE	gidxAcNasIdSetup1;
extern DBHANDLE	gidxAcNasIdSetup10;

/* acssidmacserversetup表*/
extern DBHANDLE	ghAcSsidMacServerSetup;
extern DBHANDLE	gidxAcSsidMacServerSetup1;
extern DBHANDLE	gidxAcSsidMacServerSetup10;

/* add by gwx 2013-10-11 for task1076 企业网用户组流控*/
extern DBHANDLE	ghAcUserGroupSetup;
extern DBHANDLE	gidxAcUserGroupSetup1;
extern DBHANDLE	gidxAcUserGroupSetup10;

/* add by gwx 2014-6-25 for SSID级用户接入控制begin*/
extern DBHANDLE	ghAcSsidAccessSetup;
extern DBHANDLE	gidxAcSsidAccessSetup1;
extern DBHANDLE	gidxAcSsidAccessSetup10;

extern DBHANDLE	ghAcSsidAccessListSetup;
extern DBHANDLE	gidxAcSsidAccessListSetup1;
extern DBHANDLE	gidxAcSsidAccessListSetup2;
extern DBHANDLE	gidxAcSsidAccessListSetup10;
/* add by gwx 2014-6-25 for SSID级用户接入控制end*/

/* add by gwx 2011-11-2 */
extern DBHANDLE	ghAcAuthStat;
extern DBHANDLE	gidxAcAuthStat1;

extern DBHANDLE	ghAcUserTimer;
extern DBHANDLE	gidxAcUserTimer1;

extern DBHANDLE	ghAcLinkIpListSetup;
extern DBHANDLE	gidxAcLinkIpListSetup1;
extern DBHANDLE	gidxAcLinkIpListSetup10;
/* 变量声明结束*/
/******************************************************************************/

/******************************************************************************/
/* 函数声明开始*/
extern UINT32    ac_db_actable_init (VOID);
extern VOID ac_db_table_mergekey_mo (UINT8 *pucKey, UINT32 ulMOC, UINT8 *pucMOI);

/* 基本配置表*/
extern UINT32    ac_db_table_acbasicsetup_create (VOID);
extern UINT32    ac_db_table_acbasicsetup_check (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_preinsert (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_predelete (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_preupdate (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern VOID ac_db_table_acbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acbasicsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acbasicsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acbasicsetup_default(UINT32 ulAcId);

/* AC关联配置表*/
extern UINT32    	ac_db_table_acwtpassociatesetup_create (VOID);
extern UINT32    	ac_db_table_acwtpassociatesetup_check (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_preinsert (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_predelete (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_preupdate (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern VOID 		ac_db_table_acwtpassociatesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId);
extern VOID 		ac_db_table_acwtpassociatesetup_mergekey2 (UINT8 *pucKey, UINT8 *pucSn, UINT32 ulWtpId);
extern UINT32		ac_db_table_acwtpassociatesetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwtpassociatesetup_setdyndata (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwtpassociatesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwtpassociatesetup_default(UINT32 ulAcId,UINT32 ulWtpId);

/* 上行链路检查配置表*/
extern UINT32    ac_db_table_ackeepersetup_create (VOID);
extern UINT32    ac_db_table_ackeepersetup_check (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_preinsert (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_predelete (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_preupdate (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern VOID ac_db_table_ackeepersetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_ackeepersetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_ackeepersetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_ackeepersetup_default(UINT32 ulAcId);

/* 邻居关系配置*/
extern UINT32    ac_db_table_acneighborsetup_create (VOID);
extern UINT32    ac_db_table_acneighborsetup_check (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_preinsert (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_predelete (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_preupdate (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern VOID ac_db_table_acneighborsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulNeighId);
extern VOID ac_db_table_acneighborsetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId, UINT32 ulNeighId);
extern UINT32    ac_db_table_acneighborsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acneighborsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP V2 配置表*/
extern UINT32    ac_db_table_acsyssnmpv2setup_create (VOID);
extern UINT32    ac_db_table_acsyssnmpv2setup_check (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_preinsert (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_predelete (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_preupdate (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern VOID ac_db_table_acsyssnmpv2setup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulCommunityId);
extern UINT32    ac_db_table_acsyssnmpv2setup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsyssnmpv2setup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP V3配置表*/
extern UINT32    ac_db_table_acsyssnmpv3setup_create (VOID);
extern UINT32    ac_db_table_acsyssnmpv3setup_check (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_preinsert (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_predelete (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_preupdate (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern VOID ac_db_table_acsyssnmpv3setup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulUserId);
extern UINT32    ac_db_table_acsyssnmpv3setup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsyssnmpv3setup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP TRAP 配置表*/
extern UINT32    ac_db_table_acsystrapsvrsetup_create (VOID);
extern UINT32    ac_db_table_acsystrapsvrsetup_check (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_preinsert (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_predelete (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_preupdate (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern VOID ac_db_table_acsystrapsvrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulTrapSrvId);
extern UINT32 ac_db_table_acsystrapsvrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsystrapsvrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNTP服务器配置表*/
extern UINT32    ac_db_table_acsntpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acsntpglobalsetup_check (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_preinsert (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_predelete (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_preupdate (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acsntpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acsntpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acsntpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acsntpglobalsetup_default(UINT32 ulAcId);

/* 日志配置*/
extern UINT32    ac_db_table_aclogsetup_create (VOID);
extern UINT32    ac_db_table_aclogsetup_check (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_preinsert (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_predelete (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_preupdate (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern VOID ac_db_table_aclogsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_aclogsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_aclogsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_aclogsetup_default(UINT32 ulAcId);


/* 日志服务器配置*/
extern UINT32    ac_db_table_aclogserversetup_create (VOID);
extern UINT32    ac_db_table_aclogserversetup_check (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_preinsert (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_predelete (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_preupdate (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern VOID ac_db_table_aclogserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_aclogserversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_aclogserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_aclogserversetup_default(UINT32 ulAcId);

/* AC支持的AP软件版本列表配置*/
extern UINT32	ac_db_table_acassocswversetup_create(VOID);
extern UINT32    ac_db_table_acassocswversetup_check (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_preinsert (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_predelete (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_preupdate (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern VOID ac_db_table_acassocswversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32		ac_db_table_acassocswversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acassocswversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acassocswversetup_default(UINT32 ulAcId);

/* 物理端口配置*/
extern UINT32    ac_db_table_acifsetup_create (VOID);
extern UINT32    ac_db_table_acifsetup_check (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_preinsert (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_predelete (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_preupdate (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern VOID ac_db_table_acifsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulIfId);
extern VOID ac_db_table_acifsetup_mergekey2 (UINT8 *pucKey, CHAR *pacIfName);
extern UINT32    ac_db_table_acifsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acifsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acifsetup_default(UINT32 ulAcId);

/* 端口IP地址配置表*/
extern UINT32    ac_db_table_acipsetup_create (VOID);
extern UINT32    ac_db_table_acipsetup_check (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_preinsert (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_predelete (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_preupdate (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern VOID ac_db_table_acipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acipsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acipsetup_setdyndata (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32 ac_db_table_acipsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acipsetup_default(UINT32 ulAcId);

/* 用户级DHCP功能配置*/
extern UINT32    ac_db_table_acstadhcpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpglobalsetup_check (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_preinsert (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_predelete (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_preupdate (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acstadhcpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acstadhcpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acstadhcpglobalsetup_default(UINT32 ulAcId);

/* 用户级DHCP MAC-IP地址绑定*/
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_check (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_preinsert (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_predelete (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_preupdate (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpstaticipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 用户级DHCP IP地址池*/
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_check (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_preinsert (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_predelete (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_preupdate (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpdynamicipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP级DHCP功能配置*/
extern UINT32    ac_db_table_acapdhcpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpglobalsetup_check (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_preinsert (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_predelete (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_preupdate (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acapdhcpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acapdhcpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acapdhcpglobalsetup_default(UINT32 ulAcId);

/* AP级DHCP MAC-IP地址绑定*/
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_check (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_preinsert (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_predelete (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_preupdate (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpstaticipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP级DHCP IP地址池*/
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_check (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_preinsert (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_predelete (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_preupdate (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpdynamicipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VLAN全局配置*/
extern UINT32    ac_db_table_acvlanglobalsetup_create (VOID);
extern UINT32    ac_db_table_acvlanglobalsetup_check (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_preinsert (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_predelete (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_preupdate (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acvlanglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acvlanglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acvlanglobalsetup_default(UINT32 ulAcId);

/* VLAN配置*/
extern UINT32    ac_db_table_acvlansetup_create (VOID);
extern UINT32    ac_db_table_acvlansetup_check (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_preinsert (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_predelete (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_preupdate (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern VOID ac_db_table_acvlansetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlansetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acvlansetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acvlansetup_default(UINT32 ulAcId);

/* AP IP网段-VLAN映射配置表*/
extern UINT32    ac_db_table_acapipvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acapipvlanmappingsetup_check (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_preinsert (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_predelete (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_preupdate (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32 ac_db_table_acapipvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern VOID ac_db_table_acapipvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucIp, UINT8 *pucMask, UINT32 ulVlanId);
extern UINT32    ac_db_table_acapipvlanmappingsetup_trigger (UINT8 ucModType);


/* SSID-VLAN映射配置*/
extern UINT32    ac_db_table_acssidvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acssidvlanmappingsetup_check (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_preinsert (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_predelete (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_preupdate (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acssidvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid, UINT32 ulVlanId);
extern UINT32    ac_db_table_acssidvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acssidvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 端口-VLAN映射配置*/
extern UINT32    ac_db_table_acifvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acifvlanmappingsetup_check (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_preinsert (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_predelete (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_preupdate (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acifvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulDevId, UINT32 ulIfId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acifvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acifvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC-VLAN映射配置表*/
extern UINT32    ac_db_table_acmacvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acmacvlanmappingsetup_check (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_preinsert (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_predelete (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_preupdate (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acmacvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac, UINT32 ulVlanId);
extern UINT32    ac_db_table_acmacvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acmacvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AS服务器配置*/
extern UINT32    ac_db_table_acwapiassetup_create (VOID);
extern UINT32    ac_db_table_acwapiassetup_check (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_preinsert (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_predelete (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_preupdate (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern VOID ac_db_table_acwapiassetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acwapiassetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapiassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapiassetup_default(UINT32 ulAcId);

/* WAPI 参数配置*/
extern UINT32    ac_db_table_acwapisetup_create (VOID);
extern UINT32    ac_db_table_acwapisetup_check (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_preinsert (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_predelete (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_preupdate (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern VOID ac_db_table_acwapisetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32  ulWapiSetupId);
extern UINT32    ac_db_table_acwapisetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapisetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapisetup_default(UINT32 ulAcId);

/* WAPI证书配置*/
extern UINT32    ac_db_table_acwapicertfilesetup_create (VOID);
extern UINT32    ac_db_table_acwapicertfilesetup_check (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_preinsert (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_predelete (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_preupdate (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern VOID ac_db_table_acwapicertfilesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32  ulCertId);
extern UINT32    ac_db_table_acwapicertfilesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapicertfilesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapicertfilesetup_default(UINT32 ulAcId);

/* AAA 配置*/
extern UINT32    ac_db_table_acaaasetup_create (VOID);
extern UINT32    ac_db_table_acaaasetup_check (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_preinsert (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_predelete (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_preupdate (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern VOID ac_db_table_acaaasetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acaaasetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acaaasetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acaaasetup_default(UINT32 ulAcId);

/* 免认证 配置*/
extern UINT32    ac_db_table_acfreeglobalsetup_create (VOID);
extern UINT32    ac_db_table_acfreeglobalsetup_check (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_preinsert (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_predelete (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_preupdate (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acfreeglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfreeglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreeglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreeglobalsetup_default(UINT32 ulAcId);

/* 免认证IP配置*/
extern UINT32    ac_db_table_acfreeipsetup_create (VOID);
extern UINT32    ac_db_table_acfreeipsetup_check (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_preinsert (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_predelete (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_preupdate (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern VOID ac_db_table_acfreeipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucIp, UINT8 *pucMask);
extern UINT32    ac_db_table_acfreeipsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfreeipsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 免认证MAC列表配置*/
extern UINT32    ac_db_table_acfreemacsetup_create (VOID);
extern UINT32    ac_db_table_acfreemacsetup_check (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_preinsert (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_predelete (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_preupdate (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern VOID ac_db_table_acfreemacsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acfreemacsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfreemacsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 免认证SSID列表配置*/
extern UINT32    ac_db_table_acfreessidsetup_create (VOID);
extern UINT32    ac_db_table_acfreessidsetup_check (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_preinsert (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_predelete (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_preupdate (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern VOID ac_db_table_acfreessidsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid);
extern UINT32    ac_db_table_acfreessidsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreessidsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreessidsetup_default(UINT32 ulAcId);

/* 免认证VLAN列表配置*/
extern UINT32    ac_db_table_acfreevlansetup_create (VOID);
extern UINT32    ac_db_table_acfreevlansetup_check (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_preinsert (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_predelete (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_preupdate (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern VOID ac_db_table_acfreevlansetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acfreevlansetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreevlansetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreevlansetup_default(UINT32 ulAcId);

/* MAC认证全局配置*/
extern UINT32    ac_db_table_acmacserversetup_create(VOID);
extern UINT32    ac_db_table_acmacserversetup_check (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_preinsert (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_predelete (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_preupdate (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern VOID 	ac_db_table_acmacserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acmacserversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acmacserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acmacserversetup_default(UINT32 ulAcId);

/* WEB认证全局配置*/
extern UINT32    ac_db_table_acportalsetup_create (VOID);
extern UINT32    ac_db_table_acportalsetup_check (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_preinsert (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_predelete (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_preupdate (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern VOID ac_db_table_acportalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acportalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acportalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acportalsetup_default(UINT32 ulAcId);

/* 白名单配置*/
extern UINT32    ac_db_table_acwhiltelistsetup_create (VOID);
extern UINT32    ac_db_table_acwhiltelistsetup_check (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_preinsert (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_predelete (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_preupdate (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern VOID ac_db_table_acwhiltelistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWhiteId);
extern UINT32    ac_db_table_acwhiltelistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwhiltelistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 白名单URL 配置*/
extern UINT32    ac_db_table_acwhiteurllistsetup_create (VOID);
extern UINT32    ac_db_table_acwhiteurllistsetup_check (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_preinsert (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_predelete (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_preupdate (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern VOID ac_db_table_acwhiteurllistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWhiteId);
extern UINT32    ac_db_table_acwhiteurllistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwhiteurllistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);


/* 用户名地址绑定配置*/
extern UINT32    ac_db_table_acuseraddrbindsetup_create (VOID);
extern UINT32    ac_db_table_acuseraddrbindsetup_check (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_preinsert (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_predelete (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_preupdate (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern VOID ac_db_table_acuseraddrbindsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulIndex);
extern VOID ac_db_table_acuseraddrbindsetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcUserName);
extern UINT32    ac_db_table_acuseraddrbindsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acuseraddrbindsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

extern UINT32    ac_db_table_acssidauthsetup_create (VOID);
extern UINT32    ac_db_table_acssidauthsetup_check (AC_DB_TBL_ACSSIDAUTHSETUP_T	*pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_preinsert (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_predelete (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_preupdate (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern VOID ac_db_table_acssidauthsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid, CHAR *pcUserNameSuffix);
extern UINT32	 ac_db_table_acssidauthsetup_trigger(UINT8 ucModType);
extern UINT32    ac_db_table_acssidauthsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);


/* PPPoE认证配置*/
extern UINT32    ac_db_table_acpppoesetup_create (VOID);
extern UINT32    ac_db_table_acpppoesetup_check (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_preinsert (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_predelete (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_preupdate (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acpppoesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acpppoesetup_default(UINT32 ulAcId);

/* 静态路由配置*/
extern UINT32    ac_db_table_acstaticroutesetup_create (VOID);
extern UINT32    ac_db_table_acstaticroutesetup_check (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_preinsert (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_predelete (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_preupdate (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern VOID ac_db_table_acstaticroutesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulRouteId);
extern VOID ac_db_table_acstaticroutesetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucDestIp, UINT8 *pucNetMask, UINT8 *pucGw);
extern UINT32    ac_db_table_acstaticroutesetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstaticroutesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* RIP协议配置*/
extern UINT32    ac_db_table_acripglobalsetup_create (VOID);
extern UINT32    ac_db_table_acripglobalsetup_check (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_preinsert (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_predelete (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_preupdate (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acripglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acripglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acripglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acripglobalsetup_default(UINT32 ulAcId);

/* RIP通告网段配置*/
extern UINT32    ac_db_table_acripannouncenetsetup_create (VOID);
extern UINT32    ac_db_table_acripannouncenetsetup_check (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_preinsert (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_predelete (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_preupdate (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern VOID ac_db_table_acripannouncenetsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucNetIp, UINT8 *pucNetMask);
extern UINT32    ac_db_table_acripannouncenetsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acripannouncenetsetup_dftblk(UINT32 ulAcId, UINT8* pucRecord);

/* NAT全局配置*/
extern UINT32    ac_db_table_acnatglobalsetup_create (VOID);
extern UINT32    ac_db_table_acnatglobalsetup_check (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_preinsert (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_predelete (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_preupdate (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acnatglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acnatglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acnatglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acnatglobalsetup_default(UINT32 ulAcId);

/* NAT规则配置*/
extern UINT32    ac_db_table_acnatsetup_create (VOID);
extern UINT32    ac_db_table_acnatsetup_check (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_preinsert (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_predelete (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_preupdate (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern VOID ac_db_table_acnatsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulNatId);
extern UINT32    ac_db_table_acnatsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acnatsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC地址过滤策略*/
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_create (VOID);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_check (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_preinsert (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_predelete (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_preupdate (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanaccessmacpolicysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC地址过滤列表*/
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_create (VOID);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_check (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_preinsert (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_predelete (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_preupdate (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanaccessmaclistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId, UINT8 *pucMac);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* ACL全局配置*/
extern UINT32    ac_db_table_acfirewallglobalsetup_create (VOID);
extern UINT32    ac_db_table_acfirewallglobalsetup_check (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_preinsert (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_predelete (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_preupdate (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewallglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfirewallglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfirewallglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfirewallglobalsetup_default(UINT32 ulAcId);

/* ACL规则配置*/
extern UINT32    ac_db_table_acfirewallrulebasicsetup_create (VOID);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_check (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_preinsert (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_predelete (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_preupdate (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewallrulebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulRuleId, UINT32 ulChildRuleId);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* IDS规则配置*/
extern UINT32    ac_db_table_acidsrulesetup_create (VOID);
extern UINT32    ac_db_table_acidsrulesetup_check (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_preinsert (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_predelete (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_preupdate (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern VOID ac_db_table_acidsrulesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acidsrulesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acidsrulesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acidsrulesetup_default(UINT32 ulAcId);

/* IDS策略配置*/
extern UINT32    ac_db_table_acidsstrategysetup_create (VOID);
extern UINT32    ac_db_table_acidsstrategysetup_check (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_preinsert (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_predelete (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_preupdate (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern VOID ac_db_table_acidsstrategysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acidsstrategysetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acidsstrategysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acidsstrategysetup_default(UINT32 ulAcId);

/* P2P过滤配置*/
extern UINT32    ac_db_table_acfirewalll7matchsetup_create (VOID);
extern UINT32    ac_db_table_acfirewalll7matchsetup_check (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_preinsert (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_predelete (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_preupdate (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewalll7matchsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfirewalll7matchsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfirewalll7matchsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfirewalll7matchsetup_default(UINT32 ulAcId);

/* QoS全局配置*/
extern UINT32    ac_db_table_acqosglobalsetup_create (VOID);
extern UINT32    ac_db_table_acqosglobalsetup_check (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_preinsert (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_predelete (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_preupdate (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acqosglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acqosglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acqosglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acqosglobalsetup_default(UINT32 ulAcId);

/* 默认的用户QoS配置*/
extern UINT32    ac_db_table_acqosuserdefaultsetup_create (VOID);
extern UINT32    ac_db_table_acqosuserdefaultsetup_check (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_preinsert (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_predelete (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_preupdate (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern VOID ac_db_table_acqosuserdefaultsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acqosuserdefaultsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acqosuserdefaultsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acqosuserdefaultsetup_default(UINT32 ulAcId);

extern UINT32    ac_db_table_acuserqossetup_create (VOID);
extern UINT32    ac_db_table_acuserqossetup_check (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_preinsert (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_predelete (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_preupdate (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acuserqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acuserqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acuserqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VLAN域用户QoS配置*/
extern UINT32    ac_db_table_acvlanqossetup_create (VOID);
extern UINT32    ac_db_table_acvlanqossetup_check (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_preinsert (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_predelete (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_preupdate (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlanqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SSID域用户QoS配置*/
extern UINT32    ac_db_table_acssidqossetup_create (VOID);
extern UINT32    ac_db_table_acssidqossetup_check (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_preinsert (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_predelete (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_preupdate (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acssidqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern VOID ac_db_table_acssidqossetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid);
extern UINT32    ac_db_table_acssidqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acssidqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VAP域用户QoS配置*/
extern UINT32    ac_db_table_acvapqossetup_create (VOID);
extern UINT32    ac_db_table_acvapqossetup_check (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_preinsert (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_predelete (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_preupdate (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acvapqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32    ac_db_table_acvapqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvapqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP域用户QoS配置*/
extern UINT32    ac_db_table_acapqossetup_create (VOID);
extern UINT32    ac_db_table_acapqossetup_check (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_preinsert (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_predelete (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_preupdate (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acapqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId);
extern UINT32    ac_db_table_acapqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
/* IGMP Snoop配置*/
extern UINT32    ac_db_table_acigmpsnoopsetup_create (VOID);
extern UINT32    ac_db_table_acigmpsnoopsetup_check (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_preinsert (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_predelete (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_preupdate (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern VOID ac_db_table_acigmpsnoopsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpsnoopsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acigmpsnoopsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acigmpsnoopsetup_default(UINT32 ulAcId);

/* IGMP Proxy配置*/
extern UINT32    ac_db_table_acigmpproxysetup_create (VOID);
extern UINT32    ac_db_table_acigmpproxysetup_check (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_preinsert (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_predelete (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_preupdate (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern VOID ac_db_table_acigmpproxysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpproxysetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acigmpproxysetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpproxysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 2010-1-18 pyy 新增*/
/* AC主备配置 */
extern UINT32    ac_db_table_acmssetup_create (VOID);
extern UINT32    ac_db_table_acmssetup_check (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_preinsert (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_predelete (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_preupdate (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern VOID ac_db_table_acmssetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acmssetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acmssetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acmssetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acmssetup_setdyndata (AC_DB_TBL_ACMSSETUP_T *pstRecord);


/* 告警过滤配置*/
extern UINT32    ac_db_table_acalarmfiltersetup_create (VOID);
extern UINT32    ac_db_table_acalarmfiltersetup_check (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_preinsert (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_predelete (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_preupdate (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern VOID ac_db_table_acalarmfiltersetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulAlarmNo);
extern UINT32    ac_db_table_acalarmfiltersetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acalarmfiltersetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_default(UINT32 ulAcId);

/* 告警门限配置*/
extern UINT32    ac_db_table_acalarmthresholdsetup_create (VOID);
extern UINT32    ac_db_table_acalarmthresholdsetup_check (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_preinsert (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_predelete (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_preupdate (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern VOID ac_db_table_acalarmthresholdsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acalarmthresholdsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acalarmthresholdsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acalarmthresholdsetup_default(UINT32 ulAcId);

/* 性能计数器组配置*/
extern UINT32    ac_db_table_acperfcountergroupinfosetup_create (VOID);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_check (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_preinsert (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_predelete (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_preupdate (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern VOID ac_db_table_acperfcountergroupinfosetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulCounterGroupId);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acperfcountergroupinfosetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acperfcountergroupinfosetup_default(UINT32 ulAcId);

extern UINT32    ac_db_table_acapaclsetup_create (VOID);
extern UINT32    ac_db_table_acapaclsetup_check (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_preinsert (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_predelete (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_preupdate (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern VOID ac_db_table_acapaclsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32 ac_db_table_acapaclsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acapaclsetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acapaclsetup_trigger (UINT8 ucModType);


extern UINT32    ac_db_table_acapidnassetup_create (VOID);
extern UINT32    ac_db_table_acapidnassetup_check (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_preinsert (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_predelete (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_preupdate (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern VOID ac_db_table_acapidnassetup_mergekey1 (UINT8 *pucKey, 
														UINT32 ulAcId, 
														UINT32 ulApIdStart, 
														UINT32 ulApIdEnd, 
														CHAR	*pcSsid
														);
extern UINT32 ac_db_table_acapidnassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acapidnassetup_trigger (UINT8 ucModType);


extern UINT32    ac_db_table_acapipnassetup_create (VOID);
extern UINT32    ac_db_table_acapipnassetup_check (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_preinsert (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_predelete (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_preupdate (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern VOID ac_db_table_acapipnassetup_mergekey1 (UINT8 *pucKey, 
														UINT32 ulAcId, 
														UINT8 	*pucIp, 
														UINT32 	*pucMask, 
														CHAR	*pcSsid
														);
extern UINT32 ac_db_table_acapipnassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acapipnassetup_trigger (UINT8 ucModType);


extern UINT32		ac_db_table_acuser_create (VOID);
extern VOID    	ac_db_table_acuser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey2(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulIfId, UINT32 ulVapId, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey3(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId, UINT32 ulIfId, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey4(UINT8 *pucKey, UINT8 *pucIp, UINT8 *pucMac);

extern UINT32		ac_db_table_acuservlan_create (VOID);
extern VOID    	ac_db_table_acuservlan_mergekey1(UINT8 *pucKey, UINT8 *pucMac);


extern UINT32		ac_db_table_acdynevent_create (VOID);
extern VOID 		ac_db_table_acdynevent_mergekey1 (UINT8 *pucKey, 
											UINT32 	ulEventId, 
											UINT32	ulEventReasonId, 
											UINT32 	ulMOC, 
											UINT8	aucMOI[AC_MOI_LEN], 
											UINT32 	ulCommonInfo);

extern UINT32		ac_db_table_acidsuser_create (VOID);
extern VOID    	ac_db_table_acidsuser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);											

extern UINT32		ac_db_table_acportaluser_create (VOID);
extern VOID    	ac_db_table_acportaluser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);	
extern VOID    	ac_db_table_acportaluser_mergekey2(UINT8 *pucKey, UINT32 pucWtpId, UINT32 pucDevId,UINT32 pucVapId, UINT32 puCertType,UINT8 *pucMac);	
extern UINT32		ac_db_table_acuseraccinfo_create(VOID);
extern VOID		ac_db_table_acuseraccinfo_mergekey1(UINT8 *pucKey, UINT8 *pucMac, UINT32 ulWtpId, UINT32 ulVapId);	
extern VOID    	ac_db_table_acuseraccinfo_mergekey2(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId, UINT8 *pucMac);

extern UINT32		ac_db_table_acuseripinfo_create(VOID);
extern VOID		ac_db_table_acuseripinfo_mergekey1(UINT8 *pucKey, UINT8 *pucIp);	

/* 2011-1-12 pyy add */
extern UINT32		ac_db_table_achistoryuser_create(VOID);
extern VOID		ac_db_table_achistoryuser_mergekey1(UINT8 *pucKey, UINT32 ulWtpId, UINT8 *pucMac);

extern UINT32    	ac_db_table_acnasidsetup_create(VOID);
extern UINT32    	ac_db_table_acnasidsetup_check (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acnasidsetup_preinsert (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acnasidsetup_predelete (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acnasidsetup_preupdate (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern VOID 		ac_db_table_acnasidsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* acNasId);
extern UINT32    	ac_db_table_acnasidsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acnasidsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acnasidsetup_default(UINT32 ulAcId);

extern UINT32    	ac_db_table_acssidmacserversetup_create(VOID);
extern UINT32    	ac_db_table_acssidmacserversetup_check (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidmacserversetup_preinsert (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidmacserversetup_predelete (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidmacserversetup_preupdate (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidmacserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR*acSsid);
extern UINT32    	ac_db_table_acssidmacserversetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidmacserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidmacserversetup_default(UINT32 ulAcId);

/* add by gwx 2013-10-11 for task 1076 企业网用户组流控需求begin */
extern UINT32    	ac_db_table_acusergroupsetup_create(VOID);
extern UINT32    	ac_db_table_acusergroupsetup_check (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acusergroupsetup_preinsert (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acusergroupsetup_predelete (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acusergroupsetup_preupdate (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern VOID 		ac_db_table_acusergroupsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR*acUserGroupName);
extern UINT32    	ac_db_table_acusergroupsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acusergroupsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acusergroupsetup_default(UINT32 ulAcId);
/* add by gwx 2013-10-11 for task 1076 企业网用户组流控需求end */

/* add by gwx 2014-6-25 for SSID级用户接入控制begin*/
extern UINT32    	ac_db_table_acssidaccesssetup_create(VOID);
extern UINT32    	ac_db_table_acssidaccesssetup_check (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesssetup_preinsert (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesssetup_predelete (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidaccesssetup_preupdate (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidaccesssetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* pcSsidName);
extern UINT32    	ac_db_table_acssidaccesssetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidaccesssetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidaccesssetup_default(UINT32 ulAcId);

extern UINT32    	ac_db_table_acssidaccesslistsetup_create(VOID);
extern UINT32    	ac_db_table_acssidaccesslistsetup_check (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesslistsetup_preinsert (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesslistsetup_predelete (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidaccesslistsetup_preupdate (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidaccesslistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* pcSsidName, UINT8* pcUserMac);
extern VOID ac_db_table_acssidaccesslistsetup_mergekey2(UINT8 *pucKey, 
														UINT32	ulOuiSwtich,
														UINT32 ulAcId, 
														CHAR* pcSsidName,
														UINT8* pucUserMac
														);
extern UINT32    	ac_db_table_acssidaccesslistsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidaccesslistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidaccesslistsetup_default(UINT32 ulAcId);
/* add by gwx 2014-6-25 for SSID级用户接入控制end*/

extern UINT32    	ac_db_table_aclinkiplistsetup_create(VOID);
extern UINT32    	ac_db_table_aclinkiplistsetup_check (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_aclinkiplistsetup_preinsert (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_aclinkiplistsetup_predelete (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32   	ac_db_table_aclinkiplistsetup_preupdate (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern VOID 		ac_db_table_aclinkiplistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8* pucAcLinkIp);
extern UINT32    	ac_db_table_aclinkiplistsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_aclinkiplistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_aclinkiplistsetup_default(UINT32 ulAcId);

/* add by gwx 2011-11-2 */
extern UINT32		ac_db_table_acauthstat_create(VOID);

/* add by gwx 2012-11-2 for 用户流量不准确*/
extern UINT32 	ac_db_table_acusertimer_create(VOID);
extern VOID		ac_db_table_acusertimer_mergekey1( UINT8 *pucKey, UINT8 *pucMac);
/* 函数声明结束*/
/******************************************************************************/
	

#endif /* _AC_DB_TABLE_H */
/******************************* 头文件结束 **********************************/

