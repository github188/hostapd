/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: 数据库管理模块公共头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DB_PUBLIC_H
#define  _AC_DB_PUBLIC_H

/******************************************************************************/
/* AC关系表MOC宏定义开始*/
/* 系统配置*/
#define AC_DB_MOC_ACBASICSETUP				((UINT32)0x02000001)		/* AC 基本配置表MOC*/
#define AC_DB_MOC_ACWTPASSOCIATESETUP		((UINT32)0x02000112)		/* AC WTP关联配置表MOC*/
#define AC_DB_MOC_ACKEEPERSETUP				((UINT32)0x02000105)		/* AC 上行链路检查配置表MOC*/
#define AC_DB_MOC_ACNEIGHBORSETUP			((UINT32)0x02000118)		/* AC 邻居关系配置表MOC*/
#define AC_DB_MOC_ACSYSSNMPV2SETUP			((UINT32)0x0200010A)		/* AC SNMP V2配置表MOC*/
#define AC_DB_MOC_ACSYSSNMPV3SETUP			((UINT32)0x0200010B)		/* AC SNMP V3配置表MOC*/
#define AC_DB_MOC_ACSYSTRAPSVRSETUP			((UINT32)0x0200011A)		/* AC SNMP TRAP 配置表MOC*/
#define AC_DB_MOC_ACSNTPGLOBALSETUP			((UINT32)0x02000110)		/* AC SNTP全局配置表MOC*/
#define AC_DB_MOC_ACLOGSETUP					((UINT32)0x02000111)		/* AC LOG管理配置表MOC*/
#define AC_DB_MOC_ACLOGSERVERSETUP			((UINT32)0x02000113)		/* AC LOG服务器配置表MOC*/
#define AC_DB_MOC_ACASSOCSWVERSETUP		((UINT32)0x0200010F)		/* AC支持的AP软件版本列表配置MOC*/

/* 物理端口和IP配置*/
#define AC_DB_MOC_ACIFSETUP					((UINT32)0x02000202)		/* AC物理端口配置表MOC*/
#define AC_DB_MOC_ACIPSETUP					((UINT32)0x02000203)		/* AC端口IP地址配置MOC*/

/* 用户级DHCP服务配置*/
#define AC_DB_MOC_ACSTADHCPGLOBALSETUP				((UINT32)0x0200080F)		/* DHCP for STA功能配置表MOC*/
#define AC_DB_MOC_ACSTADHCPSTATICIPADDRSETUP		((UINT32)0x02000811)		/* DHCP for STA 静态绑定IP配置表MOC*/
#define AC_DB_MOC_ACSTADHCPDYNAMICIPADDRSETUP		((UINT32)0x02000813)		/* DHCP for STA 动态IP地址池配置表MOC*/

/* AP级DHCP 服务配置*/
#define AC_DB_MOC_ACAPDHCPGLOBALSETUP				((UINT32)0x02000802)		/* DHCP for AP功能配置表MOC*/
#define AC_DB_MOC_ACAPDHCPSTATICIPADDRSETUP		((UINT32)0x02000805)		/* DHCP for AP 静态绑定IP配置表MOC*/
#define AC_DB_MOC_ACAPDHCPDYNAMICIPADDRSETUP		((UINT32)0x02000807)		/* DHCP for AP 动态IP地址池配置表MOC*/

/* VLAN管理*/
#define AC_DB_MOC_ACVLANGLOBALSETUP					((UINT32)0x02000402)		/* AC VLAN 全局配置MOC*/
#define AC_DB_MOC_ACVLANSETUP						((UINT32)0x02000407)		/* AC VLAN配置表MOC*/
#define AC_DB_MOC_ACSSIDVLANMAPPINGSETUP			((UINT32)0x02000411)		/* SSID-VLAN映射配置表MOC*/
#define AC_DB_MOC_ACIFVLANMAPPINGSETUP				((UINT32)0x02000408)		/* AC 端口-VLAN映射配置表MOC*/
#define AC_DB_MOC_ACMACVLANMAPPINGSETUP			((UINT32)0x02000409)		/* AC MAC-VLAN映射配置表MOC*/

/* WAPI配置*/
#define AC_DB_MOC_ACWAPIASSETUP				((UINT32)0x0200011C)		/* AC AS服务器配置表MOC*/
#define AC_DB_MOC_ACWAPISETUP				((UINT32)0x0200011D)		/* AC WAPI参数配置表MOC*/
#define AC_DB_MOC_ACWAPICERTFILESETUP		((UINT32)0x0200011E)		/* AC WAPI证书配置表MOC*/

/* AAA配置*/
#define AC_DB_MOC_ACAAASETUP					((UINT32)0x02000302)		/* AC AAA配置表MOC*/

/* 免认证配置*/
#define AC_DB_MOC_ACFREEGLOBALSETUP			((UINT32)0x02000305)		/* AC全局免认证MOC*/
#define AC_DB_MOC_ACFREEIPSETUP				((UINT32)0x02000307)		/* AC免认证IP列表MOC*/
#define AC_DB_MOC_ACFREEMACSETUP			((UINT32)0x02000309)		/* AC免认证MAC列表MOC*/
#define AC_DB_MOC_ACFREESSIDSETUP			((UINT32)0x02000127)		/* AC免认证SSID列表MOC*/
#define AC_DB_MOC_ACFREEVLANSETUP			((UINT32)0x02000128)		/* AC免认证VLAN列表MOC*/

/* MAC认证配置*/
#define AC_DB_MOC_ACMACSERVERSETUP			((UINT32)0x02000413)		/* MAC认证配置表MOC */

/* WEB认证配置*/
#define AC_DB_MOC_ACPORTALSETUP				((UINT32)0x02000114)		/* AC 强制Portal配置表MOC*/
#define AC_DB_MOC_ACWHILTELISTSETUP			((UINT32)0x02000115)		/* AC Portal白名单IP 配置表MOC*/
#define AC_DB_MOC_ACWHITEURLLISTSETUP		((UINT32)0x02000A16)		/* AC Portal白名单URL配置表MOC*/
#define AC_DB_MOC_ACUSERADDRBINDSETUP		((UINT32)0x02000124)		/* AC 用户名地址绑定配置表MOC*/
#define AC_DB_MOC_ACSSIDAUTHSETUP			((UINT32)0x0200012A)		/* SSID 认证配置MOC*/

/* PPP认证配置*/
#define AC_DB_MOC_ACPPPOESETUP				((UINT32)0x0200040A)		/* AC PPPoE配置表MOC*/

/* 路由配置*/
#define AC_DB_MOC_ACSTATICROUTESETUP		((UINT32)0x02000606)		/* 静态路由配置表MOC*/
#define AC_DB_MOC_ACRIPGLOBALSETUP			((UINT32)0x02000608)		/* RIP全局配置表MOC*/
#define AC_DB_MOC_ACRIPANNOUNCENETSETUP		((UINT32)0x0200060C)		/* RIP通告网段配置表MOC*/

/* NAT配置*/
#define AC_DB_MOC_ACNATGLOBALSETUP			((UINT32)0x0200070C)		/* NAT 全局配置表MOC*/
#define AC_DB_MOC_ACNATSETUP					((UINT32)0x0200070D)		/* NAT规则配置表MOC*/

/* MAC地址过滤配置*/
#define AC_DB_MOC_ACVLANACCESSMACPOLICYSETUP	((UINT32)0x0200040D)	/* AC VLAN MAC地址过滤策略MOC*/
#define AC_DB_MOC_ACVLANACCESSMACLISTSETUP		((UINT32)0x0200040F)	/* AC VLAN MAC地址列MOC*/

/* ACL配置*/
#define AC_DB_MOC_ACFIREWALLGLOBALSETUP		((UINT32)0x02000702)		/* 防火墙全局配置表MOC*/
#define AC_DB_MOC_ACFIREWALLRULEBASICSETUP	((UINT32)0x02000709)		/* 防火墙规则基本配置表MOC*/

/* IDS配置*/
#define AC_DB_MOC_ACIDSRULESETUP				((UINT32)0x0200070F)		/* IDS规则配置表MOC*/
#define AC_DB_MOC_ACIDSSTRATEGYSETUP			((UINT32)0x02000710)		/* IDS策略配置表MOC*/

/* P2P配置*/
#define AC_DB_MOC_ACFIREWALLL7MATCHSETUP		((UINT32)0x02000712)		/* 防火墙P2P流量限制配置表MOC*/

/* QoS配置*/
#define AC_DB_MOC_ACQOSGLOBALSETUP				((UINT32)0x02000902)		/* QOS全局配置表MOC*/
#define AC_DB_MOC_ACQOSUSERDEFAULTSETUP		((UINT32)0x02000905)		/* 用户QOS缺省配置表MOC*/
#define AC_DB_MOC_ACVLANQOSSETUP				((UINT32)0x02000907)		/* VLAN QOS配置表MOC*/
#define AC_DB_MOC_ACSSIDQOSSETUP					((UINT32)0x02000909)		/* SSID QOS配置表MOC*/
#define AC_DB_MOC_ACUSERQOSSETUP				((UINT32)0x0200090B)		/* 用户QOS配置表MOC*/
/* add by gwx 2012-12-5 for AP/VAP流控*/
#define AC_DB_MOC_ACVAPQOSSETUP			((UINT32)0x02000914)		/* VAP QOS配置表MOC */
#define AC_DB_MOC_ACAPQOSSETUP			((UINT32)0x02000913)		/* AP QOS配置表MOC */

/* IGMP配置*/
#define AC_DB_MOC_ACIGMPSNOOPSETUP				((UINT32)0x02000502)		/* AC IGMP Snooping配置表MOC*/
#define AC_DB_MOC_ACIGMPPROXYSETUP				((UINT32)0x02000503)		/* AC IGMP Proxy配置表MOC*/

/* AC主备配置*/
#define AC_DB_MOC_ACMSSETUP						((UINT32)0x02000912)		/* AC主备配置表MOC */

/* 网管参数配置*/
#define AC_DB_MOC_ACALARMFILTERSETUP				((UINT32)0x02000A03)		/* 告警过滤配置表MOC*/
#define AC_DB_MOC_ACALARMTHRESHOLDSETUP		((UINT32)0x02000A06)		/* 告警门限配置表MOC*/
#define AC_DB_MOC_ACPERFCOUNTERGROUPINFOSETUP	((UINT32)0x02000A05)		/* 性能计数器组配置表MOC*/

#define AC_DB_MOC_ACAPACLSETUP					((UINT32)0x02000A10)		/* AP访问策略配置表MOC*/
#define AC_DB_MOC_ACAPIDNASSETUP					((UINT32)0x02000A13)		/* AP设备ID段-NAS ID 映射配置表MOC*/
#define AC_DB_MOC_ACAPIPNASSETUP					((UINT32)0x02000A14)		/* AP 设备IP网段-NAS ID 映射配置表MOC*/
#define AC_DB_MOC_ACAPIPVLANMAPPINGSETUP		((UINT32)0x02000A15)		/* AP 设备IP网段-VLAN  映射配置表MOC*/

#define AC_DB_MOC_WTPSYSBASICSETUP				((UINT32)0x01000001)	/* WTP基本配置表MOC*/
#define AC_DB_MOC_WTPSYSIPSETUP					((UINT32)0x01000103)	/* WTP IP配置表MOC*/
#define AC_DB_MOC_WTPSYSLOADBALANCESETUP		((UINT32)0x0100010F)	/* WTP 负载均衡配置表MOC*/
#define AC_DB_MOC_WTPSYSLOGSETUP				((UINT32)0x01000112)	/* WTP 日志管理配置表MOC*/
#define AC_DB_MOC_WTPSYSSWSERVERSETUP			((UINT32)0x01000105)	/* WTP 软件服务器配置表MOC*/
#define AC_DB_MOC_WTPSYSSNTPSETUP				((UINT32)0x0100010C)	/* WTP  SNTP参数配置表MOC*/

#define AC_DB_MOC_WTPWIFIDEVICEBASICSETUP		((UINT32)0x01000202)	/* WTP 无线设备基本配置表MOC*/
#define AC_DB_MOC_WTPWIFIDEVICECHANNELSETUP	((UINT32)0x01000204)	/* WTP 无线设备无线信道配置表MOC*/
#define AC_DB_MOC_WTPWIFIDEVICERATESETUP		((UINT32)0x01000205)	/* WTP 无线设备无线速率配置表MOC*/
#define AC_DB_MOC_WTPWIFIDEVICEPOWERSETUP		((UINT32)0x01000206)	/* WTP 无线设备无线功率配置表MOC*/ 
#define AC_DB_MOC_WTPWIFIDEVICEADVANCEDSETUP		((UINT32)0x01000207)	/* WTP 无线设备无线高级配置表MOC*/
#define AC_DB_MOC_WTPWIFIDEVICEWIDSSETUP			((UINT32)0x01000208)	/* WTP 无线设备WIDS配置表MOC*/
#define AC_DB_MOC_WTPWIFIDEVICERESOURCESETUP		((UINT32)0x0100020A)	/* WTP 无线设备无线资源管理配置表MOC*/

#define AC_DB_MOC_WTPAPBASICSETUP					((UINT32)0x01000303)	/* WTP VAP基本配置表MOC*/ 
#define AC_DB_MOC_WTPAPSECURITYSETUP				((UINT32)0x01000306)	/* WTP VAP安全配置表MOC*/
#define AC_DB_MOC_WTPAPADVANCEDSETUP				((UINT32)0x01000307)	/* WTP VAP高级配置表MOC*/

#define AC_DB_MOC_WTPADHOCBASICSETUP				((UINT32)0x01000402)	/* WTP ADHOC基本配置表MOC*/
#define AC_DB_MOC_WTPADHOCSECURITYSETUP			((UINT32)0x01000404)	/* WTP ADHOC安全配置表MOC*/

#define AC_DB_MOC_WTPENETBASICSETUP					((UINT32)0x01000602)	/* WTP 以太网口配置表MOC*/

#define AC_DB_MOC_WTPROUTEBASICSETUP				((UINT32)0x01000702)	/* WTP路由基本配置表MOC*/
#define AC_DB_MOC_WTPROUTENEIGHBORSETUP			((UINT32)0x01000703)	/* WTP路由邻居管理配置表MOC*/
#define AC_DB_MOC_WTPROUTEHANDOVERSETUP			((UINT32)0x01000704)	/* WTP路由切换管理配置表MOC*/
#define AC_DB_MOC_WTPROUTEDEVICEMSCSETUP			((UINT32)0x01000705)	/* WTP路由设备主从管理配置表MOC*/

#define AC_DB_MOC_WTPCAPWAPSETUP					((UINT32)0x01000901)	/* WTP CAPWAP配置表MOC*/

#define AC_DB_MOC_WTPALARMFILTERSETUP				((UINT32)0x01000F03)		/* 告警过滤配置表MOC*/
#define AC_DB_MOC_WTPALARMTHRESHOLDSETUP			((UINT32)0x01000F06)		/* 告警门限配置表MOC*/
#define AC_DB_MOC_WTPPERFCOUNTERGROUPINFOSETUP	((UINT32)0x01000F04)		/* 计数器组配置表MOC*/

#define AC_DB_MOC_ACNASIDSETUP						((UINT32)0x02000A17)		/* nasid配置表MOC*/
#define AC_DB_MOC_ACSSIDMACSERVERSETUP				((UINT32)0x02000414)		/* ssidMAC服务配置表MOC*/
/* add by gwx 2013-10-12 for task1076 企业网用户组流控需求*/
#define AC_DB_MOC_ACUSERGROUPSETUP				((UINT32)0x02000A6C)	/*用户 组配置表*/
#define AC_DB_MOC_WTPAPUSERGROUPQOSSETUP		((UINT32)0x01000F07)	/* 用户组流控配置表*/
#define AC_DB_MOC_WTPSYSLOCATORSETUP		((UINT32)0x01000F08)	/* AP定位服务配置表*/

/* add by gwx 2014-6-25 for SSID用户接入控制begin*/
#define AC_DB_MOC_ACSSIDACCESSSETUP				( (UINT32)0x02000A6D)		/* SSID 级用户接入控制模式配置表MOC*/
#define AC_DB_MOC_ACSSIDACCESSLISTSETUP			( (UINT32)0x02000A6E)		/* SSID 级用户接入控制列表配置表MOC*/
/* add by gwx 2014-6-25 for SSID用户接入控制end*/

#define AC_DB_MOC_ACLINKIPLISTSETUP ((UINT32)0x02000A6F)        /*AP 接入IP 配置表*/

/******************************************************************************/

#define AC_DB_IF_MAX	50
#define EV_DBIF_BEGIN	(EV_DB_BEGIN+200)

#define AC_DB_GET_TABLE_ALLRECORDHOST_MSG	(EV_DBIF_BEGIN+1)
#define AC_DB_GET_TABLE_ONERECORDHOST_MSG	(EV_DBIF_BEGIN+2)
#define AC_DB_GET_TABLE_WTPRECORDHOST_MSG	(EV_DBIF_BEGIN+3)
#define AC_DB_GET_TABLE_ALLRECORDNET_MSG	(EV_DBIF_BEGIN+4)
#define AC_DB_GET_TABLE_ONERECORDNET_MSG	(EV_DBIF_BEGIN+5)
#define AC_DB_GET_TABLE_WTPRECORDNET_MSG	(EV_DBIF_BEGIN+6)

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
#define AC_DB_GET_TABLE_ALLRECORDNET_PROBE_MSG	(EV_DBIF_BEGIN+7)
/* END: Added by wubin, 2012/4/25   BUG:000 */

#define AC_DB_SHOW_TABLE_MSG					(EV_DBIF_BEGIN+31)

#define AC_DB_TABLE_CHANGE_IND_MSG			(EV_DBIF_BEGIN+51)

/* 增量配置请求/响应*/
#define AC_DB_CFG_INC_UPDATE_HOST_REQ_MSG		(EV_DBIF_BEGIN+61)		/* 增量配置请求: 主机序*/
#define AC_DB_CFG_INC_UPDATE_HOST_RSP_MSG		(EV_DBIF_BEGIN+62)		/* 增量配置相应: 主机序*/
#define AC_DB_CFG_INC_UPDATE_NET_REQ_MSG		(EV_DBIF_BEGIN+63)		/* 增量配置请求: 网络序*/
#define AC_DB_CFG_INC_UPDATE_NET_RSP_MSG		(EV_DBIF_BEGIN+64)		/* 增量配置相应: 网络序*/

//2009/11/17 fengjing add increment batch update
#define AC_DB_CFG_INC_BATCHUPDATE_HOST_REQ_MSG (EV_DBIF_BEGIN + 71)      /* 增量批量配置请求: 主机序*/
#define AC_DB_CFG_INC_BATCHUPDATE_HOST_RSP_MSG (EV_DBIF_BEGIN + 72)      /* 增量批量配置相应: 主机序*/
#define AC_DB_CFG_INC_BATCHUPDATE_NET_REQ_MSG (EV_DBIF_BEGIN + 73)        /* 增量批量配置请求: 网络序*/
#define AC_DB_CFG_INC_BATCHUPDATE_NET_RSP_MSG (EV_DBIF_BEGIN + 74)        /* 增量批量配置相应: 网络序*/

/* 2011-1-12 pyy add */
#define AC_DB_RESET_APUSERSTAT_REQ_MSG			(EV_DBIF_BEGIN + 81)		/* 清除用户临时统计表请求 */

#define AC_DB_CFG_DELAP_HOST_REQ_MSG (EV_DBIF_BEGIN + 91)      /* 删除AP配置请求: 主机序*/
#define AC_DB_CFG_DELAP_HOST_RSP_MSG (EV_DBIF_BEGIN + 92)      /* 删除AP配置响应: 主机序*/
#define AC_DB_CFG_ADDAP_HOST_REQ_MSG (EV_DBIF_BEGIN + 93)      /* 新增AP请求: 主机序*/
#define AC_DB_CFG_ADDAP_HOST_RSP_MSG (EV_DBIF_BEGIN + 94)      /* 新增AP响应: 主机序*/
/* 增量配置类型定义*/
#define AC_DB_CFG_INC_ADD						0	/* 增加*/
#define AC_DB_CFG_INC_DEL						1	/* 删除*/
#define AC_DB_CFG_INC_UPDATE					2	/* 修改*/

#define AC_BYTE_ORDER_HOST					0	/* 主机序*/
#define AC_BYTE_ORDER_NET						1	/* 网络序*/
#define AC_DB_CFG_DELAP_NUM_MAX 50	/*批量删除AP 最大数目*/
#define AC_DB_CFG_ADDAP_NUM_MAX 100	/*批量新增AP 最大数目*/


/* add by gwx 2011-11-2 for 广东移动，网络验证类型*/
#define AC_DB_SECURITY_AUTHTYPE_OPENSYSTEM	1
#define AC_DB_SECURITY_AUTHTYPE_SHAREDKEY	2
#define AC_DB_SECURITY_AUTHTYPE_WPAPSK		3
#define AC_DB_SECURITY_AUTHTYPE_WPA			4
#define AC_DB_SECURITY_AUTHTYPE_MAC			5
#define AC_DB_SECURITY_AUTHTYPE_WAPIWAI		6
/* add by gwx 2014-5-28 for ruijie 故障信息一键统计*/
#define TIME_FMT        "%04d-%02d-%02d %02d:%02d:%02d"
#define TIME_ARG(x)     (1900+(x)->tm_year),(1+(x)->tm_mon),(x)->tm_mday,(x)->tm_hour,(x)->tm_min,(x)->tm_sec

extern VOID ac_db_access(UINT32 ulMsgId, UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

extern TPID    gtDbCtrlProc;
extern TPID    gtDbCmPid;
extern TPID    gtAcCwPid;
extern TPID    gtWtpCwPid;
extern TPID    gtComPid;
extern TPID    gtHostapdPid;
extern TPID    gtOamPid;
extern TPID    gtAcmPid;
//extern TPID		gtSmPid;
extern TPID		gtRrmPid;
extern TPID		gtPortalPid;
extern TPID		gtWapiPid;
extern TPID		gtSysmPid;
extern TPID		gtUsrmPid;
extern TPID		gtApOmaPid;
extern TPID		gtOssMsPid;

//5.1.1	获取指定关系表的所有记录
typedef struct
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* 关系表名 */
	UINT32		ulStartRec;		/* 查询的起始记录号 */
} AC_DB_GET_TABLE_ALLRECORD_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulFinish;		/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulRecLen;	/* 记录长度 */
	UINT32	ulRecNum;	/* 记录数 */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* 记录内容 */
} AC_DB_GET_TABLE_ALLRECORD_RSP_T;

//5.1.2	获取指定关系表的指定记录
typedef struct
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* 关系表名 */
	/* 关键字 */
	UINT32	ulMOC;				/* 对象类标识 */
	UINT8	aucMOI[AC_MOI_LEN];	/* 对象实例标识 */
} AC_DB_GET_TABLE_ONERECORD_REQ_T;


typedef struct
{
	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulRecLen;	/* 记录长度 */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* 记录内容 */
} AC_DB_GET_TABLE_ONERECORD_RSP_T;

//5.1.3	获取指定关系表指定AP设备的相关记录
typedef struct
{
    CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];      /* 关系表名 */
    UINT32      ulWtpId;                                /* WTP ID */
    UINT32      ulStartRec;     /* 查询的起始记录号 */
} AC_DB_GET_TABLE_WTPRECORD_REQ_T;

typedef struct
{
    UINT32  ulRet;      		/* 返回值，AC_OK表示成功，其它表示错误码 */
    UINT32  ulFinish;   		/* 关系表所有记录是否已读取结束
                            			AC_DB_TABLE_READ_NOTFINISH  未结束
							AC_DB_TABLE_READ_FINISH     读取结束 */
    UINT32  ulRecLen;   	/* 记录长度 */
    UINT32  ulRecNum;   	/* 记录数 */
    UINT8   aucRecord[AC_DB_PACKET_MAX_LEN];    /* 记录内容 */
} AC_DB_GET_TABLE_WTPRECORD_RSP_T;

/* 显示指定关系表所有记录*/
typedef struct 
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* 关系表名 */
} AC_DB_SHOW_TABLE_REQ_T;

typedef struct 
{
	UINT32  ulRet;      		/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_DB_SHOW_TABLE_RSP_T;

//	消息接口
//	关系表记录变更通知
 typedef struct
{
	CHAR 	acTblName[AC_DB_TBL_NAME_LEN_MAX];
} AC_DB_TABLE_CHANGE_IND_MSG_T;


/* 增量配置请求*/
typedef struct 
{
	UINT32	ulSn;		/* 序列号*/
	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];
	UINT32	ulIncType;	/* 增量配置类型：
						0 ：增加
						1：删除
						2：修改
						*/
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* 记录内容 */
} AC_DB_CFG_INC_UPDATE_REQ_T;

/* 增量配置响应*/
typedef struct 
{
	UINT32	ulSn;	/* 序列号*/
	UINT32	ulRet;	/*返回值，AC_OK表示成功，其它表示错误码 */
	CHAR      acResultDesc[128];    /* 错误描述信息 */
} AC_DB_CFG_INC_UPDATE_RSP_T;

#define AC_DB_CFG_INC_BATCHUPDATE_NUM_MAX  ((UINT32)20)
typedef struct
{
	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];
	UINT32	ulIncType;	/* 增量配置类型：
						0 ：增加
						1：删除
						2：修改
						*/
	UINT32    ulRecLen;
	UINT8	  *aucRecord;	/* 记录内容 */
}AC_DB_CFG_INC_UPDATE_T;

// 2009/11/19 fengjing add
typedef struct
{
	UINT32	ulSn;		/* 序列号*/
	UINT32   ulModNum;
	AC_DB_CFG_INC_UPDATE_T astIncUpdate[AC_DB_CFG_INC_BATCHUPDATE_NUM_MAX];
}AC_DB_CFG_INC_BATCHUPDATE_REQ_T;

typedef struct
{
	UINT32	ulSn;	/* 序列号*/
	UINT32	ulRet;	/*返回值，AC_OK表示成功，其它表示错误码 */
	CHAR      acResultDesc[128];    /* 错误描述信息 */
}AC_DB_CFG_INC_BATCHUPDATE_RSP_T;

typedef struct
{
       UINT32 	ulSn;    /* 序列号 */
       UINT32	ulDeviceType;
       UINT8    aucDeviceId[6];
       UINT8    aucRsv[2]; 
       UINT32 	ulNum;  /* 注册AP数目 */
       UINT32 	aulApId[AC_DB_CFG_ADDAP_NUM_MAX];
}AC_DB_CFG_ADDAP_REQ_T;
typedef struct
{
       UINT32 ulSn;
       UINT32 ulRet; /* 返回码 */ 
       CHAR  acResultDesc[128];    /* 错误描述信息 */
}AC_DB_CFG_ADDAP_RSP_T;
typedef struct
{
       UINT32 ulSn;    /* 序列号 */
       UINT32 ulNum;  /* 删除AP数目 */
       UINT32 aulApId[AC_DB_CFG_DELAP_NUM_MAX];
}AC_DB_CFG_DELAP_REQ_T;
typedef struct
{
       UINT32 ulSn;
       UINT32 ulRet; /* 返回码 */ 
       CHAR  acResultDesc[128];    /* 错误描述信息 */
}AC_DB_CFG_DELAP_RSP_T;

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
typedef struct
{
	CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* 关系表名 */
	UINT32		ulStartRec;		/* 查询的起始记录号 */
} AC_DB_GET_TABLE_ALLRECORD_PROBE_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulFinish;		/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulRecLen;	/* 记录长度 */
	UINT32	ulRecNum;	/* 记录数 */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN_NET];	/* 记录内容 */
} AC_DB_GET_TABLE_ALLRECORD_PROBE_RSP_T;
/* END: Added by wubin, 2012/4/25   BUG:000 */

#endif /* _AC_DB_PUBLIC_H */
/******************************* 头文件结束 **********************************/

