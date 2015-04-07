#ifndef IF_COMMON_H
#define IF_COMMON_H

#ifdef WIN32

typedef unsigned __int64 u_int64_t;
typedef unsigned int   u_int32_t ;
typedef unsigned short u_int16_t ;
typedef unsigned short u_int8_t ;

typedef short int16_t ;

#ifndef HAVE_INT8_T
typedef signed char int8_t;
#endif /* !HAVE_INT8_T */


#ifdef IFNAMSIZ
#undef IFNAMSIZ
#endif
#define IFNAMSIZ 16

#ifdef __packed
#undef __packed
#endif
#define __packed

#define SIOCDEVPRIVATE  0 //需要找一下定义

#define __func__ ""

typedef struct ifreq
{
    char    ifr_name[100];
    char    *ifr_data;
}ifreq;

#define ioctl(a, b, c) 0

#endif

/* 网元类型 */
#define NETYPE_AP   0

/* 事件状态 */
#define EVENTSTATUS_CLEAR   				0		/* 清除 */
#define EVENTSTATUS_RAISE					1		/* 产生 */
#define EVENTSTATUS_NORMAL		     		2		/* 未知 */

/* 对象类型 */
#define OBJECTTYPE_SYSTEM					0		/* 系统 */
#define OBJECTTYPE_WIFI_CARD				1		/* 无线模块 */
#define OBJECTTYPE_ENET						2		/* 以太网口 */
#define OBJECTTYPE_WIFI_DEVICE				3		/* 无线设备 */
#define OBJECTTYPE_PORT						4		/* 端口 */

#define WIFI_MODULE0				    0
#define WIFI_MODULE1				    1
#define WIFI_MODULE2				    2
#define WIFI_MODULE3				    3


/* 对象ID */
#define OBJECT_ID_INVALID					0xffffffff

#define OBJECT_ID_ADHOC0					0
#define OBJECT_ID_ADHOC1					1
#define OBJECT_ID_ADHOC2					2
#define OBJECT_ID_ADHOC3					3

#define OBJECT_ID_ENET0						4
#define OBJECT_ID_ENET1						5

#define OBJECT_ID_AP0						8
#define OBJECT_ID_AP1						9
#define OBJECT_ID_AP2						10
#define OBJECT_ID_AP3						11
#define OBJECT_ID_AP4						12
#define OBJECT_ID_AP5						13
#define OBJECT_ID_AP6						14
#define OBJECT_ID_AP7						15
#define OBJECT_ID_AP8						16
#define OBJECT_ID_AP9						17
#define OBJECT_ID_AP10						18
#define OBJECT_ID_AP11						19
#define OBJECT_ID_AP12						20
#define OBJECT_ID_AP13						21
#define OBJECT_ID_AP14						22
#define OBJECT_ID_AP15						23

#define OBJECT_ID_WIFI_MODULE0				0
#define OBJECT_ID_WIFI_MODULE1				1
#define OBJECT_ID_WIFI_MODULE2				2
#define OBJECT_ID_WIFI_MODULE3				3

#define OBJECT_ID_WIFI_DEVICE0				0
#define OBJECT_ID_WIFI_DEVICE1				1
#define OBJECT_ID_WIFI_DEVICE2				2
#define OBJECT_ID_WIFI_DEVICE3				3

/* 对象名称 */
#define OBJECT_NAME_ADHOC0					"adhoc0"
#define OBJECT_NAME_ADHOC1					"adhoc1"
#define OBJECT_NAME_ADHOC2					"adhoc2"
#define OBJECT_NAME_ADHOC3					"adhoc3"

#define OBJECT_NAME_ENET0					"ixp0"
#define OBJECT_NAME_ENET1					"ixp1"

#define OBJECT_NAME_AP						"ap"

#define OBJECT_NAME_AP0						"ap0"
#define OBJECT_NAME_AP1						"ap1"
#define OBJECT_NAME_AP2						"ap2"
#define OBJECT_NAME_AP3						"ap3"
#define OBJECT_NAME_AP4						"ap4"
#define OBJECT_NAME_AP5						"ap5"
#define OBJECT_NAME_AP6						"ap6"
#define OBJECT_NAME_AP7						"ap7"
#define OBJECT_NAME_AP8						"ap8"
#define OBJECT_NAME_AP9						"ap9"
#define OBJECT_NAME_AP10					"ap10"
#define OBJECT_NAME_AP11					"ap11"
#define OBJECT_NAME_AP12					"ap12"
#define OBJECT_NAME_AP13					"ap13"
#define OBJECT_NAME_AP14					"ap14"
#define OBJECT_NAME_AP15					"ap15"

#define OBJECT_NAME_VLAN1		            "vlan1"
#define OBJECT_NAME_VLAN2		            "vlan2"
#define OBJECT_NAME_VLAN3		            "vlan3"
#define OBJECT_NAME_VLAN4		            "vlan4"
#define OBJECT_NAME_VLAN5		            "vlan5"
#define OBJECT_NAME_VLAN6		            "vlan6"
#define OBJECT_NAME_VLAN7		            "vlan7"
#define OBJECT_NAME_VLAN8		            "vlan8"
#define OBJECT_NAME_VLAN9		            "vlan9"
#define OBJECT_NAME_VLAN10		            "vlan10"
#define OBJECT_NAME_VLAN11		            "vlan11"
#define OBJECT_NAME_VLAN12		            "vlan12"
#define OBJECT_NAME_VLAN13		            "vlan13"
#define OBJECT_NAME_VLAN14		            "vlan14"
#define OBJECT_NAME_VLAN15		            "vlan15"
#define OBJECT_NAME_VLAN16		            "vlan16"

#define OBJECT_NAME_WIFI0					"wifi0"
#define OBJECT_NAME_WIFI1					"wifi1"
#define OBJECT_NAME_WIFI2					"wifi2"
#define OBJECT_NAME_WIFI3					"wifi3"

#define OBJECT_NAME_WIFI_DEVICE0			"wifiDevice0"
#define OBJECT_NAME_WIFI_DEVICE1			"wifiDevice1"
#define OBJECT_NAME_WIFI_DEVICE2			"wifiDevice2"
#define OBJECT_NAME_WIFI_DEVICE3			"wifiDevice3"

/* 事件级别 */
#define EVENTLEVEL_FATAL					1		/* 致命 */
#define EVENTLEVEL_MAIN		    			2		/* 主要 */
#define EVENTLEVEL_MINOR					3		/* 次要 */
#define EVENTLEVEL_WARNING  				4		/* 警告 */

/* 告警码 */
#define ALARM_ID_CARD_FAULT				    1000	/* AP无线设备故障 */
#define ALARM_ID_WIFI_CARD_LESS		    	1001    /* AP无线设备不在位 */
/* hc modified for cmcc test 2009-9-2 */
#define ALARM_ID_AP_POWEROFF				1002    /* AP关机告警 */

#define ALARM_ID_CARD_BROKEN                1005    /* 无线端口故障 */

#define ALARM_ID_CPU_OVERLOAD				2000    /* AP设备CPU负荷过高 */
#define ALARM_ID_MEM_OVERLOAD	        	2001    /* AP设备内存负荷过高 */
#define ALARM_ID_TEMPERATURE_HIGH	    	2002    /* AP设备温度过高告警 */
#define ALARM_ID_TEMPERATURE_LOW	    	2003    /* AP设备温度过低告警 */
#define ALARM_ID_DISK_OVERLOAD	        	2004    /* 磁盘使用率过高 */

/* 2010-4-10 pyy 新增*/
#define ALARM_ID_APINTERFDETECTED				2005	/* 其他设备干扰告警*/
#define ALARM_ID_RADIODOWN  					2006	/* 无线链路中断告警*/
#define ALARM_ID_COVERHOLE  					2007	/* 覆盖漏洞告警 */
#define ALARM_ID_DFSFREECOUNTBELOWTHRESHHD  	2008	/* 信道告警 */
#define ALARM_ID_STAINTERFDETECTED				2010	/* 终端干扰告警*/
#define ALARM_ID_APCOLDREBOOT					2011    /* 冷重启 */
#define ALARM_ID_APWARMREBOOT					2012    /* 热重启 */

/* hc modified for cmcc test 2009-9-2 */
//#define ALARM_ID_RADIUS_SERVER_DISCONNECTED	     3000   /* 无法连接Radius计费服务器 */

#define EVENT_ID_WTP_REBOOT				    6000    /* AP设备启动 */
#define EVNET_ID_WTP_ROGUE_AP               6001    /* 发现恶意AP事件 */
#define EVENT_ID_ENET_OFFLINE				6002	/* 网口物理断线 */
#define EVENT_ID_SWUPDATE_FAIL				6010	/* 软件升级失败 */
#define EVENT_ID_TIME_SYNC_FAIL				6011	/* 时钟同步失败 */
#define EVENT_ID_AP_POWEROFF				6012	/* AP关机事件*/
/* hc modified for cmcc test 2009-7-20 */
#define EVENT_ID_AP_IP_CHANGE               6013    /* AP的IP地址改变告警  */
#define EVENT_ID_AP_WRITE_FLASH_FAIL        6014    /* AP写Flash失败告警 */

#define EVENT_ID_WTP_SWUPDATE               6016    /* AP软件升级成功 */

#define EVENT_ID_USER_ACCESS_FAILED			7000	/* 用户接入失败 */
#define EVENT_ID_ADHOC_ACCESS_DENY			7001	/* mesh非法接入 */
#define EVENT_ID_USER_ACCESS				7002	/* 用户关联 */
#define EVENT_ID_USER_ACCESS_OUT            7003    /* 用户去关联  */

/* hc modified for telecom test 2009-7-7 */
#define EVENT_ID_WIRELESS_DOS_ATTACK		7004    /* 无线DOS  攻击事件 */
#define EVENT_ID_UNAUTH_SSID				7005    /* 未授权SSID  事件 */
#define EVENT_ID_JAM_STA					7006    /* 干扰终端事件 */
#define EVENT_ID_AP_CHANNEL_CHANGE          7007    /* Ap  信道变更事件  */
#define EVENT_ID_WEAK_IV_ATTACK             7008    /* weak iv 攻击事件  */

#define EVENT_ID_FATHER_CHANGE              8000    /* AP设备Mesh父节点变化事件 */
#define EVENT_ID_GW_CHANGE                  8001    /* AP设备Mesh网关变化事件 */
#define EVENT_ID_GW_STATUS_CHANGE			8002	/* AP设备Mesh网关状态变化 */
/* hc modified for cmcc test 2009-7-31 */
#define EVENT_ID_INVALIDCERTINBREAKNETWORK	9000    /* 非法证书用户侵入网络 */
#define EVENT_ID_STATIONREPITIVE_ATTACK		9001    /* 客户端重放攻击 */
#define EVENT_ID_TAMPER_ATTACK              9002    /* 篡改攻击 */
#define EVENT_ID_LOWSAFELEVEL_ATTACK        9003    /* 安全等级降低攻击 */
#define EVENT_ID_ADDRESSREDIRECTION_ATTACK  9004    /* 地址重定向攻击 */
#define ALARM_ID_WTP_USEROVERLOAD           9005    /* AP用户数负荷过重告警 */

/* 2010-4-10 pyy 新增*/
#define EVENT_ID_APMTWORKMODECHG  			9006	/* AP无线监视工作模式变更事件*/
#define EVENT_ID_SSIDKEYCONFLICT  			9007	/* SSID密钥冲突事件*/
#define EVENT_ID_STASSOCIATIONFAIL  		9008	/* 端站关联失败事件 */
#define EVENT_ID_TLAUTHENTICATIONFAILED  	9009	/* 鉴别邻居AP传输链路失败事件*/

/* 2010/06/01 fengjing add */
#define EVNET_ID_CFGUPDATE                  9010    /* 配置更新 */
#define EVNET_ID_SWDOWNLOAD                 9011    /* 软件下载成功 */
#define EVNET_ID_SWUPDATE                   9012    /* 开始软件升级 */

#define EVENT_ID_STAEXCEPTDISASSOCIATE   9020  /* 终端异常断开通告 *///add by zjj

#define EVENT_REASON_WTP_REBOOT_COLD        1       /* 冷重启 */
#define EVENT_REASON_WTP_REBOOT_WARM        2       /* 热重启*/
#define EVENT_REASON_WTP_REBOOT_OHTER       3       /* 其它原因*/


#define PERFCOUNTER_FLOW        1000    /* 流量统计 */
#define PERFCOUNTER_VAP         2000    /* VAP统计 */
#define PERFCOUNTER_ADHOC       2001    /* ADHOC统计 */

#define PERF_COUNT	3

#define MAX_OBJECT_NAME_LEN                 31

/* 扩展信息 */
typedef struct
{
	char			    acMac[6];
	char		    	acIp[4];
	/* hc modified for telecom test 2009-7-7 */
	unsigned char       aucSsid[32] ;  
}USER_MAC_IP_T;

/* hc add 2009-11-5 */
typedef enum
{
    CC_TYPE_CONFIG,
    CC_TYPE_DYNAMIC
}FREQUENCY_TYPE_U;

typedef struct
{
    unsigned long ulType ;      /*频点变更类型，CC_TYPE_CONFIG：频点配置变化；CC_TYPE_DYNAMIC：频点动态调整*/
    unsigned long ulOld ;        /*旧频点，0：表示AUTO*/
    unsigned long ulNew ;      /*新频点*/
    unsigned long ulNum ;     /*频点动态调整次数，不包含配置变化调整*/
}CHAN_CHANGE_T ;

typedef struct{
     unsigned char aucMac[6];  /*用户MAC*/
     unsigned char aucRsv[2];
     unsigned long ulTime;               /*上下线时间，单位：秒，自1970.1.1 00:00:00的秒数*/
     long          lRxPower;               /*信号强度，单位：dBm*/
     unsigned long ulChannel;         /*频点：1~13，149，153，……*/
}USER_INFO_T;

typedef struct{
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulReason;
}FAIL_REASON_T;

/* 2010/05/29 fengjing add */
typedef struct
{
     unsigned char aucMac[6];         /* AP MAC地址 */
     unsigned char aucRsv[2];
     unsigned long ulRebootTime;      /* AP冷启动/热启动时间*/
} REBOOT_INFO_T;

typedef struct
{
     unsigned char bssid[6];      /*AP MAC*/
     unsigned char bssid_pad[2];
     unsigned long channel;       /*AP 信道*/
     unsigned char mac[8][8];    /*以全0截止*/
}STA_DISTURB_T;

typedef union
{
	unsigned long   	ulCommonInfo;           /* 公共原因，通常对应扩展信息为单个整数类型的情况 */
	USER_MAC_IP_T       stMacIP;
	char                acBssid[6];
	CHAN_CHANGE_T       stChanChange ;
	FAIL_REASON_T       stReason;
	/* 2010/05/28 fengjing add */
	USER_INFO_T         stUserInfo;
	/* 2010/05/29 fengjing add */
	REBOOT_INFO_T       stReboot;
	/* 2010-07-01 fengjing cmcc test */
	STA_DISTURB_T       stStaDisturb;	
	char                acInfo[100];
}EVENT_EXT_INFO_U;

typedef struct
{
	unsigned long	    ulEventId;						/* 事件ID */
	unsigned long	    ulEventStatus;					/* 事件状态 */
	unsigned long	    ulEventReasonId;				/* 事件原因ID号 */
	unsigned long	    ulEventLevel;					/* 事件级别 */
	unsigned long	    ulObjectType;		    		/* 对象类型 */
	char			    acObjectName[MAX_OBJECT_NAME_LEN+1];    /* 对象名称 */
	unsigned long       ulRaiseTime;					/* 事件产生时间(time()函数的返回值) */
	unsigned long	    ulUptime;						/* 上电到发生该事件的时间，tick值，秒 */

	EVENT_EXT_INFO_U    unExtInfo;						/* 扩展信息 */
}EVENT_TRAP_MSG_T;

#define MAX_EVENTTRAPMSGLIST_NUM	    20
typedef struct
{
	unsigned long		ulValidNum;
	EVENT_TRAP_MSG_T	astEventTrapMsg[MAX_EVENTTRAPMSGLIST_NUM];
}EVENT_TRAP_MSG_LIST_T;


/*------------------------------------- mesh route path info ------------------------------------------------*/

#define ROUTE_PATH_ENTRY_MAX_NUM		    16
#define ROUTE_ROUTE_PATH_ENTRY_MAX_NUM		5

typedef struct
{
	unsigned long ulMeshRoutePathFlag;                      /* 有效标致 */
	unsigned long ulNodeNum;                                /* 路径设备ID列表中实际使用到的个数 */
	unsigned char acPathEntry[ROUTE_PATH_ENTRY_MAX_NUM][6]; /* 路径上的设备ID列表*/
	unsigned long ulPathId;                                 /* 路径ID */
	unsigned long ulPathQos;                                /* 路径QOS */
	unsigned long ulPathSendSpeed;                          /* 路径发送速率*/
	unsigned long ulPathRecvSpeed;                          /* 路径接收速率*/
	unsigned long ulPathLiveTime;                           /* 存活时间*/
} MESH_ROUTE_PATH_END_INFO_T;

typedef struct
{
	unsigned long				ulValidNum;
	MESH_ROUTE_PATH_END_INFO_T	astMeshRoutePathInfo[ROUTE_PATH_ENTRY_MAX_NUM];
} MESH_ROUTE_PATH_END_INFO_ENTRY;

#endif
