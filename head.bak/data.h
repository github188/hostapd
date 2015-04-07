/******************************************************************************
* COPYRIGHT GBCOM
* 集中交换数据结构定义
*******************************************************************************
******************************************************************************/

#ifndef L2W_DATA_H
#define L2W_DATA_H

/******************************************************************************/
/*宏定义开始*/

/* 设备类型定义*/
#define L2W_DEV_TYPE_AC			0
#define L2W_DEV_TYPE_AP			1
#define L2w_DEV_TYPE_INVALID		0xFF

/* 端口类型定义*/
#define L2W_PORT_TYPE_AP_ACCESS	0	/* AP 业务口*/
#define L2W_PORT_TYPE_AP_BEAR		1	/* AP承载口*/
#define L2W_PORT_TYPE_AC_FITLAN	2	/* AC FIT-LAN口*/
#define L2W_PORT_TYPE_AC_FATLAN	3	/* AC FAT-LAN口*/
#define L2W_PORT_TYPE_AC_L2WAN	4	/* AC L2 WAN口*/
#define L2W_PORT_TYPE_AC_L3WAN	5	/* L3 WAN不会加到桥中*/
#define L2W_PORT_TYPE_VDEV		6	/* 虚设备端口*/
#define L2W_PORT_TYPE_AC_HYBRID	7	/* 混合模式端口*/	
#define L2W_PORT_TYPE_INVALID		0xFF

/* 桥类型定义*/
#define L2W_BR_TYPE_AP_ACCESS		0	/* AP接入桥*/
#define L2W_BR_TYPE_AP_BEAR		1	/* AP承载桥*/
#define L2W_BR_TYPE_AC_BEAR		2	/* AC承载桥*/
#define L2W_BR_TYPE_AC_L2WAN		3	/* AC L2-WAN桥 */		
#define L2W_BR_TYPE_AC_L3WAN		4	/* AC L3-WAN桥 */		
#define L2W_BR_TYPE_INVALID		0xFF

/* 报文类型定义*/
#define L2W_PKT_TYPE_UNICAST			1
#define L2W_PKT_TYPE_MULTICAST		2
#define L2W_PKT_TYPE_BROADCAST		3

/* 用户类型定义*/
#define L2W_USER_TYPE_WIRELESS		0	/* 无线用户*/
#define L2W_USER_TYPE_WIRE			1	/* 有线用户*/

/* MAC过滤开关取值宏定义*/
#define L2W_MAC_FILTER_SWITCH_DISABLE	0	/* 关闭*/
#define L2W_MAC_FILTER_SWITCH_ENABLE		1	/* 打开*/

/* MAC过滤类型*/
#define L2W_MAC_FILTER_TYPE_WHITE			0	/* 白名单*/
#define L2W_MAC_FILTER_TYPE_BLACK			1	/* 黑名单*/


/* HASH Size */
#define L2W_DEV_HASH_SIZE				256		/* 设备HASH桶大小 */
#define L2W_BR_HASH_SIZE				256		/* 桥HASH桶大小*/
#define L2W_PORT_HASH_SIZE			256		/* 端口HASH桶大小*/
#define L2W_USER_HASH_SIZE			256		/* 在线用户HASH桶大小*/
#define L2W_VLAN_HASH_SIZE			256		/* VLAN HASH桶大小*/
#define L2W_MAC_HASH_SIZE				256		/* MAC HASH桶大小*/

/* device id 结构*/
/*
12bit	4bit		16bit
devid	0		0
*/
#define L2W_DEVID_MIN			0
#define L2W_DEVID_MAX			0xFFF
#define L2W_DEVID_MASK			0xFFF00000
#define L2W_DEVID_MOV_BITS	20

/* bridge id 结构*/
/*
12bit	4bit		16bit
devid	brid		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0xF
#define L2W_BRID_MASK		0xF0000
#define L2W_BRID_MOV_BITS	16

/* port id 结构*/
/*
12bit	4bit		16bit		
devid	brid		portid	
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0xFFFF
#define L2W_PORTID_MASK		0xFFFF
#define L2W_PORTID_MOV_BITS	0


#if 0
/* bridge id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		0		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0x3F
#define L2W_BRID_MASK		0xFC000
#define L2W_BRID_MOV_BITS	14

/* port id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	0
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0x3F
#define L2W_PORTID_MASK		0x3F00
#define L2W_PORTID_MOV_BITS	8

/* user id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	userid
*/
#define L2W_USERID_MIN			0
#define L2W_USERID_MAX			0xFF
#define L2W_USERID_MASK		0xFF
#define L2W_USERID_MOV_BITS	0
#endif

/* vlan id 结构*/
#define L2W_VLANID_MIN		1
#define L2W_VLANID_MAX		4094

#define L2W_VLANID_INVALID	0xFFFF

#define VAP_PORTID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define REAL_DEVID(ulDevId)			(((ulDevId)&L2W_DEVID_MASK) >> L2W_DEVID_MOV_BITS)
#define FAKE_DEVID(ulDevId)			((ulDevId&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS)

#define REAL_BRID(ulBrId)				(((ulBrId)&L2W_BRID_MASK) >> L2W_BRID_MOV_BITS)
#define FAKE_BRID(ulDevId,ulBrId)		((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
									  (((ulBrId)&L2W_BRID_MAX) << L2W_BRID_MOV_BITS))

#define REAL_PORTID(ulPortId)			(((ulPortId)&L2W_PORTID_MASK) >> L2W_PORTID_MOV_BITS)
#define FAKE_PORTID(ulDevId,ulPortId)	((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
							  		  (((ulPortId)&L2W_PORTID_MAX) << L2W_PORTID_MOV_BITS))

#if 0
#define REAL_USERID(ulUserId)		(((ulUserId)&L2W_USERID_MASK) >> L2W_USERID_MOV_BITS)
#define FAKE_USERID(ulDevId,ulPortId,ulUserId)	((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
							  		  		  (((ulPortId)&L2W_PORTID_MAX) << L2W_PORTID_MOV_BITS) |\
							  		  		  (((ulUserId)&L2W_USERID_MAX) << L2W_USERID_MOV_BITS))
#endif



extern L2W_PKT_STATS_T gstFrgStat;
extern unsigned long gstCapwapMtu;
/*宏定义结束*/
/******************************************************************************/


/******************************************************************************/
/* 数据结构定义开始*/
/* 设备*/
typedef struct 
{
	u32	ulDevId;			/* 设备编号*/
	u32	ulDevType;		/* 设备类型 */
	char	acDevName[IFNAMSIZ];	
	u8	aucDevIp[4];
	/* 2011-1-12 ymt add:count */
	u32	ulUlPkts;			/*上行包数 */
	u32	ulDlPkts;			/*下行包数 */
	u32	ulUlGigaWords;	/*上行字节数：单位4GByte */
	u32	ulUlBytes;		/*上行字节数：单位Byte */
	u32	ulDlGigaWords;	/*下行字节数：单位4GByte */
	u32	ulDlBytes;		/*上行字节数：单位Byte */
	/* 2011-1-12 ymt  end*/
	struct hlist_node	idHlist;		/* device index hash chain */
	struct hlist_node	nameHlist;	/* device name hash chain */
	struct list_head	portList;		/* 端口链*/
	struct list_head	brList;		/* 桥链*/
    u16 usDevSrcPort;        /*HDD WTP设备 源端口号 2013-4-2 */
    u8  capwapfrag;  /* 是否是capwap分片报文，1: 是； 0: 不是*/
}  L2W_DEVICE_T;

typedef struct
{
	u32	ulDevId;			/* real dev id */
	u32	ulIfId;			/* real if id */
	u32	ulUserVlanId;	/* 内层VLAN ID */
	u32	ulNestVlanId;	/* 外层VLAN ID */
	
	struct hlist_node	mapHlist;	/* vlan id hash chain */
} L2W_QINQMAP_T;
/* 桥*/
typedef struct 
{
	u32	ulBrId;					/* 桥编号*/
	u32	ulBrType;				/* 桥类型*/
	char acBrName[IFNAMSIZ];	
	u8	aucBrIp[4];				/* IP */
	L2W_DEVICE_T	*pstDev;	/* 桥所属的设备*/

	struct list_head	list;			/* 用于链接同一设备下的桥*/
	
	struct hlist_node	idHlist;		/* br index hash chain */
	struct hlist_node	nameHlist;	/* br name hash chain */
	struct list_head	portList;		/* 端口链*/
}  L2W_BRIDGE_T;

/* 端口*/
typedef struct 
{
	u32	ulPortId;
	u32	ulPortType;
	char	acPortName[IFNAMSIZ];
	char	acSsid[32];

	L2W_DEVICE_T	*pstDev;
	L2W_BRIDGE_T	*pstBr;

	struct list_head	devList;			/* 用户连接同一设备下的端口*/
	struct list_head	brList;			/* 用于链接同一桥下的端口*/
	
	struct hlist_node	idHlist;			/* port index hash chain */
	struct hlist_node	nameHlist;		/* port name hash chain */	
	struct hlist_head	userHList[L2W_USER_HASH_SIZE];	/* 用户HASH*/

#if 0
	struct list_head	vlanIfIfList;	/* 用于链接同一端口下的VlanIfMap */
#endif

#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
}  L2W_PORT_T;

typedef struct
{
	u32	ulUserPri;					/* 用户优先级 */
	u32	ulUpBand;					/* 用户上行保证带宽*/
	u32	ulUpBandMax;				/* 用户上行最大带宽*/
	u32	ulDownBand;				/* 用户下行保证带宽*/
	u32	ulDownBandMax;				/* 用户下行最大带宽*/
} L2W_USER_QOS_T;

/* 在线用户*/
typedef struct 
{
	u8	aucMac[6];				/* 用户MAC */
	u8	aucRsv[2];				/* 填充字节*/
	u8	aucIp[4];				/* IP */
	L2W_USER_QOS_T	stQos;		/* 用户QOS */
	u32	ulVlanId;				/* 用户归属的VLAN */
	u32	ulCertState;				/* 用户认证状态*/
	u32	ulUserType;				/* 用户类型*/
	
	L2W_PORT_T		*pstPort;	/* 用户归属的port */
    u32	ulWtpId;
	u32	ulVapId;
	char	acSsid[32];				/* 用户归属的SSID */	

	/* 2011-1-12 ymt add:count*/
	u32	ulUlPkts;			/*上行包数 */
	u32	ulDlPkts;			/*下行包数 */
	u32	ulUlGigaWords;		/*上行字节数：单位4GByte */
	u32	ulUlBytes;			/*上行字节数：单位Byte */
	u32	ulDlGigaWords;		/*下行字节数：单位4GByte */
	u32	ulDlBytes;			/*上行字节数：单位Byte */
	/* 2011-1-12 ymt end*/

	struct hlist_node	macHlist;		/* user mac hash chain */
	struct hlist_node	macPortHlist;	/* user mac hash chain in the port */
	struct hlist_node	ipHlist;			/* user ip hash chain */
#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
}  L2W_USER_T;

/* IDS恶意用户*/
typedef struct
{
	u8	aucMac[6];				/* 用户MAC */
	u8	aucRsv[2];				/* 填充字节*/

	struct hlist_node	macHlist;		/* user mac hash chain */
} L2W_IDSUSER_T;

/* VLAN */
typedef struct 
{
	u32	ulVlanId;				/* VLAN ID */
	u32	ulVlanPrio;				/* VLAN优先级*/
	char	acVlanName[32];			/* VLAN名称*/
	u32	ulEnableIsolate;			/* 用户隔离 */

	u32	ulMacFilterSwitch;		/* MAC过滤功能开关0/1:关闭/打开*/
	u32	ulMacFilterType;			/* MAC过滤类型 0/1: 白名单/黑名单*/

	struct hlist_node	idHlist;		/* vlan id hash chain */

#if 0
	struct list_head	vlanIfVlanList;		/* 用于链接同一VLAN下的VlanIfMap */
	struct list_head	vlanMacVlanList;		/* 用于链接同一VLAN下的VlanMacMap */
#endif	
} L2W_VLAN_T;

/* IF-VLAN 映射关系结构体定义*/
typedef struct
{
	u32	ulVlanId;
	u32	ulDevId;	/* real dev id */
	u32	ulIfId;	/* real if id */

	struct hlist_node mapHlist;	/* vlan id hash chain */

#if 0
	struct list_head	vlanIfIfList;		/* 用于链接同一端口下的VlanIfMap */
	struct list_head	vlanIfVlanList;	/* 用于链接同一VLAN下的VlanIfMap */
#endif	
}L2W_VLANIFMAP_T;

/* MAC-VLAN映射关系结构体定义*/
typedef struct 
{
	u8	aucMac[6];					/* MAC地址 */
	u8	aucRsv[2];					/* 填充字节*/
	u32	ulVlanId;

	struct hlist_node	mapHlist;		/* user mac-vlanid map hash chain */

#if 0
	struct list_head	vlanMacVlanList;		/* 用于链接同一VLAN下的VlanMacMap */
	struct list_head	vlanMacMacList;		/* 用于链接同一MAC下的VlanMacMap */
#endif
} L2W_VLANMACMAP_T;

typedef struct
{
	char	acSsid[32];
	u32	ulVlanId;

	struct hlist_node mapHlist;
}L2W_VLANSSIDMAP_T;

typedef struct 
{
	u8	aucMac[6];					/* MAC地址 */
	u8	aucRsv[2];					/* 填充字节*/
	u32	ulVlanId;

	struct hlist_node mapHlist;					/* user mac-vlanid map hash chain */
} L2W_VLANACCMACMAP_T;


/* IGMP Proxy 配置结构体定义*/
typedef struct 
{
	u32	ulIgmpProxy;
} L2W_IGMPPROXY_T;

/* IGMP Snoop配置结构体定义*/
typedef struct 
{
	u32	ulIgmpSnoopSwitch;			/* 是否生效 */
	u32	ulRtPortTimer;				/* 路由器端口老化定时器 */
	u32	ulMemberPortTimer;			/* 成员端口老化定时器 */	
}L2W_IGMPSNOOP_T;

/* MAC-IP映射表*/
typedef struct
{
	u8	aucMac[6];				/* MAC */
	u8	aucIp[4];				/* IP */
	char	acIfName[16];

	struct hlist_node	macHlist;		/* mac hash chain */
	struct hlist_node	ipHlist;			/* ip hash chain */
} L2W_MACIPMAP_T;

/* 2010-8-10 新增 */
/* 同一类型的端口间转发控制开关*/
typedef struct
{
	u32	ulFitLanForward;		/* 0: 禁止转发 1:允许转发*/
	u32	ulFatLanForward;	/* 0: 禁止转发 1:允许转发*/
	u32	ulL2WanForward;	/* 0: 禁止转发 1:允许转发*/
	u32	ulL3WanForward;	/* 0: 禁止转发 1:允许转发*/
} L2W_FORWARD_SWITCH_T;

/* 数据结构定义结束*/
/******************************************************************************/

#endif

/******************************* end **********************************/

