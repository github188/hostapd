/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  数据库统一接口功能头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_USRM_PUBLIC_H
#define  _AC_USRM_PUBLIC_H

/******************************************************************************/
/*****************************USRM模块消息号定义*****************************/
/* 消息号定义开始*/

#define AC_USRM_IF_MAX    100        /* USRM模块最大接口数*/

/* 标准接口消息号*/
#define AC_USRM_ADD_USER_MSG					(EV_USRM_BEGIN+1)    /* 用户新增 */
#define AC_USRM_DEL_USER_MSG            			(EV_USRM_BEGIN+2)   	/* 用户删除*/
#define AC_USRM_UPDATE_USER_SUBINFO_MSG 	(EV_USRM_BEGIN+3)   	/* 更新用户签约信息，hostapd从radius server获取用户签约信息后调用本接口*/
#define AC_USRM_UPDATE_USER_POS_MSG     		(EV_USRM_BEGIN+4)   	/* 更新用户位置信息 */
#define AC_USRM_GET_ALLUSER_MSG				(EV_USRM_BEGIN+5)   	/* 获取当前所有在线用户列表*/
#define AC_USRM_GET_USERQOS_MSG				(EV_USRM_BEGIN+6)	/* 根据用户当前接入的VAP标识获取用户QOS */

#define AC_USRM_GET_USERPORTALSWITCH_MSG	(EV_USRM_BEGIN+7)	/* 根据用户MAC地址和当前接入的端口判断用户是否需要Portal认证 */
#define AC_USRM_SET_USERPORTALSTATE_MSG		(EV_USRM_BEGIN+8)	/* 根据用户MAC地址设置用户的Portal认证状态 */
#define AC_USRM_GET_USERPORTALSTATE_MSG		(EV_USRM_BEGIN+9)	/* 根据用户MAC地址获取用户的Portal认证状态 */
#define AC_USRM_ADD_IDSUSER_MSG				(EV_USRM_BEGIN+10)	/* 将用户设置为IDS恶意用户*/
#define AC_USRM_SET_PPPOESTATE_MSG			(EV_USRM_BEGIN+11)	/* 设置PPPoE认证状态*/
#define AC_USRM_SET_USERIP_MSG				(EV_USRM_BEGIN+12)	/* 设置用户IP地址*/
#define AC_USRM_GET_USERINFO_MSG				(EV_USRM_BEGIN+13)	/* 根据用户MAC获取用户信息*/
#define AC_USRM_GET_USERINFOBYIP_MSG			(EV_USRM_BEGIN+14)	/* 根据用户IP获取用户信息*/
#define AC_USRM_GET_USERVLAN_MSG				(EV_USRM_BEGIN+15)	/* 根据用户MAC获取用户所属VLAN */
#define AC_USRM_GET_USERNASINFOBYMAC_MSG	(EV_USRM_BEGIN+16)	/* 根据用户MAC获取用户所属的NAS 信息*/
#define AC_USRM_GET_USERNASINFOBYIP_MSG		(EV_USRM_BEGIN+17)	/* 根据用户IP获取用户所属的NAS 信息*/
#define AC_USRM_GET_NASINFO_MSG				(EV_USRM_BEGIN+18)	/* 根据VAP ID或MAC地址获取用户所属的NAS信息 */
#define AC_USRM_GET_USERPORTAL_CONFIG_MSG	(EV_USRM_BEGIN+19)	/* 根据用户地址获取用户认证配置*/
#define AC_USRM_GET_ALLIDSUSER_MSG			(EV_USRM_BEGIN+20)	/* 获取所有IDS恶意用户列表*/
#define AC_USRM_GET_USERCERTSTATE_MSG		(EV_USRM_BEGIN+21)	/* 获取用户认证状态*/
#define AC_USRM_GET_NASIP_MSG					(EV_USRM_BEGIN+22)	/* 获取NAS-IP接口*/
#define AC_USRM_SET_USERIPFROMDHCP_MSG		(EV_USRM_BEGIN+23)	/*add by gwx for bug2423,  DHCP模块设计用户IP消息*/

#define AC_USRM_GET_APSTAASSONUM_MSG		(EV_USRM_BEGIN+30)	/* 获取当前时刻与AP关联的终端数*/
#define AC_USRM_GET_APSTAONLINENUM_MSG		(EV_USRM_BEGIN+31)	/* 获取当前时刻在线的终端数: WEB认证通过的终端数*/
#define AC_USRM_GET_ALLAPSTANUM_MSG			(EV_USRM_BEGIN+32)	/* 获取所有AP当前时刻关联的终端数
																		所有AP当前时刻在线的终端数: WEB认证通过的终端数*/
#define AC_USRM_GET_ALLSSIDSTANUM_MSG		(EV_USRM_BEGIN+33)	/* 获取所有SSID当前时刻关联的终端数
																		所有SSID当前时刻在线的终端数: WEB认证通过的终端数*/
#define AC_USRM_GET_PORTALONLINEUSER_MSG			(EV_USRM_BEGIN+34)	/* 获取WEB认证通过的用户数*/	
#if 0
#define AC_USRM_INC_WEBUSERABNORMALOFFLINE_MSG	(EV_USRM_BEGIN+35)	/* WEB认证用户异常下线次数递增*/
#define AC_USRM_INC_WEBAUTHREQ_MSG					(EV_USRM_BEGIN+36)	/* WEB认证请求次数递增*/
#define AC_USRM_INC_WEBAUTHSUCCREQ_MSG				(EV_USRM_BEGIN+37)	/* WEB认证成功次数递增*/
#endif
/* 2011-3-7 pyy add: 获取胖用户相关信息*/
#define AC_USRM_GET_WIREUSERQOS_MSG				(EV_USRM_BEGIN+38)
#define AC_USRM_GET_WIRENASINFO_MSG					(EV_USRM_BEGIN+39)

#define AC_USRM_FORCE_USEROFFLINE_REQ_MSG	(EV_USRM_BEGIN+51)	/* OMC强制用户下线请求*/
#define AC_USRM_FORCE_USEROFFLINE_RSP_MSG	(EV_USRM_BEGIN+52)	/* OMC强制用户下线响应*/

/* 2010-3-4新增: 强制PPPOE认证用户下线 */
#define AC_USRM_PPPOE_USEROFFLINE_REQ_MSG	(EV_USRM_BEGIN+53)		/* 强制PPPOE认证用户下线请求*/
#define AC_USRM_PPPOE_USEROFFLINE_RSP_MSG	(EV_USRM_BEGIN+54)		/* 强制PPPOE认证用户下线响应*/

/* 2011-8-9 pyy add: MAC认证功能*/
#define AC_USRM_SET_USERAGENT_MSG			(EV_USRM_BEGIN+55)		/* 设置User-Agent属性*/
#define AC_USRM_GET_USERAGENT_MSG			(EV_USRM_BEGIN+56)		/* 获取User-Agent属性*/
#define AC_USRM_SET_MACAUTHRES_MSG			(EV_USRM_BEGIN+57)		/* 设置MAC认证结果*/

#define AC_USRM_GET_USERMACSERVER_CONFIG_MSG	(EV_USRM_BEGIN+58)   	/* 根据用户地址获取用户MAC认证配置*/
/* add by gwx 2011-11-1 for 广东移动*/
#define AC_USRM_INC_AUTHSTAT_MSG				(EV_USRM_BEGIN+59) 			/* 更新AP级认证统计*/
#define AC_USRM_GET_ACAUTHSTAT_MSG			(EV_USRM_BEGIN+60) 		/* 获取AC级认证统计*/
#define AC_USRM_EAPUSEROFFLINE_REQ_MSG		(EV_USRM_BEGIN+61) 		/* 关联认证用户无流量下线通知Hostapd*/

/* add by gwx 2021-10-31 for 用户流量不准确*/
#define AC_USRM_SET_USERTRAFFIC_MSG		(EV_USRM_BEGIN+62) 		/* AP设置用户流量接口 */
#define AC_USRM_ILLEGALUSER_MSG			(EV_USRM_BEGIN+63)		/* AC通知 AP清除非法用户 */
#define AC_USRM_GET_USERTRAFFIC_BYMAC_MSG		(EV_USRM_BEGIN+64)		/* 获取单个用户的流量*/
#define AC_USRM_USER_STARTTRAFFIC_MSG	(EV_USRM_BEGIN+66)		/* 通知AP开始该用户流量统计*/
#define AC_USRM_USER_STOPTRAFFIC_MSG	(EV_USRM_BEGIN+67)		/* 通知AP停止该用户流量统计*/
#define AC_USRM_USER_STARTTRAFFIC_AP_RPT_MSG	(EV_USRM_BEGIN+68)		/* AP返回开始用户流量统计的操作结果*/
#define AC_USRM_USER_STOPTRAFFIC_AP_RPT_MSG	(EV_USRM_BEGIN+69)		/* AP返回停止用户流量统计的操作结果*/
/* add by gwx 2013-1-23 for bug1718 */
#define AC_USRM_GET_USERPORTAL_CONFIG_BYSSID_MSG (EV_USRM_BEGIN+70)  	/* 根据SSID获取portal配置*/
/* add by gwx 2014-5-13 for 锐捷,AP上报用户信息*/
#define AC_USRM_SET_USERPARTINFOFROMAP_MSG		(EV_USRM_BEGIN+71)
/* add by gwx 2013-6-26 for SSID用户接入控制*/
#define AC_USRM_GET_USERACCESSPERMIT_MSG	(EV_USRM_BEGIN+72)		/* 根据用户MAC和接入的SSID获取用户用户是否允许接入*/ 

/* 触发消息号*/
#define AC_USRM_USER_ADD_IND_MSG				(EV_USRM_BEGIN+101)		/* 用户接入通知*/
#define AC_USRM_USER_DEL_IND_MSG				(EV_USRM_BEGIN+102)		/* 用户离开通知*/
#define AC_USRM_USERPORTAL_DEL_IND_MSG		(EV_USRM_BEGIN+103)		/* 用户Portal认证上下文删除通知*/
#define AC_USRM_USER_HANDOVER_IND_MSG		(EV_USRM_BEGIN+104)		/* 用户计费信息变更通知*/
#define AC_USRM_USER_TS_START_IND_MSG		(EV_USRM_BEGIN+105)		/* 通知流量统计模块开始用户流量统计*/
#define AC_USRM_USER_TS_END_IND_MSG			(EV_USRM_BEGIN+106)		/* 通知流量统计模块开始停止流量统计*/
#define AC_USRM_USER_CERTSTATE_CHANGE_IND_MSG	(EV_USRM_BEGIN+107)	/* 用户认证状态变化通知*/
#define AC_USRM_USER_QOS_CHANGE_IND_MSG		(EV_USRM_BEGIN+108)	/* 用户QOS信息变化通知*/
#define AC_USRM_USER_SESSIONTIMEOUT_IND_MSG		(EV_USRM_BEGIN+109)	/* 用户SESSION TIMEOUT通知*/
#define AC_USRM_IDSUSER_ADD_IND_MSG				(EV_USRM_BEGIN+110)	/* IDS恶意用户新增通知*/
#define AC_USRM_IDSUSER_DEL_IND_MSG				(EV_USRM_BEGIN+111)	/* IDS恶意用户删除通知*/
#define AC_USRM_NASIP_UPDATE_IND_MSG				(EV_USRM_BEGIN+112)	/* NAS-IP 变更消息*/
#define AC_USRM_MACAUTH_REQ_MSG					(EV_USRM_BEGIN+113)	/* 触发Portal模块对用户进行MAC认证*/

#define AC_USRM_TOACCOUNT_PROCWORK_MSG		(EV_USRM_BEGIN+114) /*USRM模块启动后向account 发上电通知*/
#define AC_USRM_USERIP_REQ_MSG				(EV_USRM_BEGIN+115)/* add by gwx 2012-6-4 for bug1100 添加用户成功后主动向DHCP拿地址*/
#define AC_USRM_ADD_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+120)		/* 通知AP添加用户流控消息*/
#define AC_USRM_ADD_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+121)		/* AP 收到添加用户流控消息后的返回消息*/

#define AC_USRM_DEL_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+122)		/* 通知删除用户流控消息*/
#define AC_USRM_DEL_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+123)		/* AP 收到删除用户流控消息后的返回消息*/

#define AC_USRM_UPDATE_ALL_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+124)		/* 通知AP更新所有用户流控信息消息*/
#define AC_USRM_UPDATE_ALL_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+125)		/* AP收到更新所有用户流控消息后返回消息*/
/* 消息号定义结束*/

/* 取值宏定义开始*/
// 	输出参数结构：
#define 	AC_PORTAL_SWITCH_DISABLE		0	/* 禁用强制WEB认证 */
#define	AC_PORTAL_SWITCH_ENABLE		1	/* 启用强制WEB认证*/

#define 	AC_CERT_STATE_NOTFINISH		0	/* WEB/PPP 未认证*/
#define	AC_CERT_STATE_FINISH			1	/* WEB/PPP 已认证 */


#define 	AC_PORTAL_STATE_NOTFINISH	0	/* WEB 未认证*/
#define	AC_PORTAL_STATE_FINISH		1	/* WEB 已认证 */

/*业务 认证类型取值宏定义*/
#define	AC_CERT_TYPE_FREE				0	/* 免认证*/
#define	AC_CERT_TYPE_PORTAL			1	/* WEB认证*/
#define	AC_CERT_TYPE_PPPOE			2	/* PPP认证*/
#define 	AC_CERT_TYPE_MAC				3	/* 2011-8-9 pyy add: MAC认证*/
#define 	AC_CERT_TYPE_WPA                	 	4   	/* 关联认证add by gwx 2011-11-1 for 广东移动 */

#define 	AC_USRM_WTP_ALLVAP	1024	/* add by gwx 2012-5-31 for bug1089*/

/* add by gwx 2012-6-4 for bug1100 调用setuserIp的模块类型*/
#define     AC_USERIPREQ_TYPE_DHCPCLEAR		2
#define     AC_USERIPREQ_TYPE_DHCP				1
#define     AC_USERIPREQ_TYPE_L2W    			0
#define	  AC_USERIPREQ_TYPE_HRD				3

/* add by gwx 2011-11-1 for 广东移动，统计类型宏定义 */
#define AC_USRM_AUTHSTATTYPE_AUTHREQ		1	/* 认证请求次数*/
#define AC_USRM_AUTHSTATTYPE_AUTHSUCC		2	/* 认证成功次数*/
#define AC_USRM_AUTHSTATTYPE_AUTHFAIL		3	/* 认证失败次数*/
#define AC_USRM_AUTHSTATTYPE_ABNORMALOFFLINE	4	/* 异常下线次数*/

/* add by gwx 2012-11-1 for 用户流量不准确*/
#define 	AC_SEND_USERTRAFFIC_TIMES		3	/* 通知AP开始/停止统计用户流量消息重发次数*/
#define	AC_WTP_MAX_USERNUM		128
/* add by gwx 2013-1-9 for task341 */
#define AC_USRM_NASID_MAXLEN		16		/* nasid的合法最大长度*/

/* add by gwx 2014-6-26 for SSID级用户接入控制*/
#define	AC_USRM_ALLOW_USERACCESS		0
#define	AC_USRM_NOT_ALLOW_USERACCESS	1

#define	AC_USRM_WHITELIST_MODE		0
#define	AC_USRM_BLACKLIST_MODE		1

#define 	AC_USRM_USERACCESS_OUI_ON	1
#define 	AC_USRM_USERACCESS_OUI_OFF	0

/* 取值宏定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 接口结构体定义开始*/
/* 用户QOS属性结构体定义 */
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
} AC_USRM_MAC_T;

typedef struct
{
	UINT32	ulPriority;			/* 用户优先级 */
	UINT32	ulUpBandMax;		/* 用户最大上行带宽 */
	UINT32	ulUpBandMin;		/* 用户保证上行带宽 */
	UINT32	ulDownBandMax;		/* 用户最大下行带宽 */
	UINT32	ulDownBandMin;		/* 用户保证下行带宽 */
} AC_USR_QOS_T;

/* 用户计费信息结构体定义*/
typedef struct
{
	CHAR	acUserName[256];	/* 用户名 */
	UINT8	aucVapMac[6];		/* VAP BSSID */
	UINT8	aucRsv[2];			/* 填充字节 */
	CHAR	acVapSsid[32];		/* VAP SSID */
	
	UINT8	aucNasIp[4];				/* NAS IP：填AC与计费服务器通信的地址 */
	CHAR	acNasId[256];			/* NAS ID：根据用户当前接入的VLAN获取到热点ID */
	UINT32	ulAcctInterimInterval;    	/* 计费信息上报间隔：如果AAA服务器指定计费上报间隔，则采用AAA指定值，否则由PORTAL/PPPOE设置该值，如果未设置，则采用AC全局配置值 */
	UINT32  	ulSessionTimeout;       /* 会话超时时间 , 单位:秒*/
	UINT32	ulAssocId ;        /*用户认证（WEP/PPPOE）成功后，由用户管理模块通知计费进程该字段，该值即从上述数据结构中传递过来*/
	UINT32	ulAcctTermCause;		/* 2010-7-14 新增: 用户下线原因*/
} AC_USR_ACCT_T;

typedef struct
{
	UINT8   aucMac[6];
  	UINT8   aucRsv[2];
 	UINT8   aucIp[4];
 	UINT32	ulUserType;
	UINT32	ulVlanId;
	
	AC_USR_QOS_T  	stQos;      	/* 用户QOS */
	AC_VAPID_T        	stVapId;    	/* 用户当前接入的VAP标识 */   
	AC_USR_ACCT_T	stAcctInfo;	/* 用户计费相关信息*/

	UINT32	ulCertType;
	UINT32	ulCertState;
	UINT32	ulEthId;
} AC_USRM_USER_INFO_T;

#define AC_USER_TYPE_WIRELESS	0	/* 无线用户*/
#define AC_USER_TYPE_WIRE		1	/* 有线用户*/

//	用户接入
typedef struct
{
	UINT32	ulType;	/* 用户类型*/
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT8	aucIp[4];
	AC_VAPID_T	stVapId;
	UINT32	ulIfId;		/* 有线接口号*/
	UINT32	ulAssocId;	/*用户接入后，由HOSTAPD/WAPIAPD通知用户管理模块该字段值*/
	UINT32	ulVlanId;	/* 2010-3-4 新增: 有线用户VLAN ID */
} AC_USRM_ADD_USER_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_USRM_ADD_USER_RSP_T;

 #define AC_USRM_ACCTTERMCAUSE_USERREQUEST		1	/* 用户请求下线（User Request */
 #define AC_USRM_ACCTTERMCAUSE_IDLETIMEOUT		4	/* 空闲超时（Idle Timeout） */
 #define AC_USRM_ACCTTERMCAUSE_SESSIONTIMEOUT	5	/* 会话超时（Session Timeout）*/
 #define AC_USRM_ACCTTERMCAUSE_ADMINRESET		6	/* DM下线（Admin Reset）*/
 /* add by gwx 2012-3-10 */
 #define AC_USRM_WPAOFFTYPE_USERREQUEST			0	/* 用户请求下线(默认)*/
 #define AC_USRM_WPAOFFTYPE_IDLETIMEOUT			1	/* 无流量下线*/
 #define AC_USRM_WPAOFFTYPE_ADMINRESET			2	/* 强制下线*/
 
//	用户删除
typedef struct
{	
	UINT32	ulType;	/* 用户类型*/
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	AC_VAPID_T	stVapId;
	UINT32	ulIfId;	/* 有线接口号*/
	UINT32	ulAcctTermCause;		/* 2010-7-14 新增: 用户下线原因*/
} AC_USRM_DEL_USER_REQ_T;
typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_USRM_DEL_USER_RSP_T;

//用户签约信息更新
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	CHAR	acUserName[256];

	UINT8	aucNasIp[4];		/* NAS IP */
	CHAR	acNasId[256];	/* NAS ID */
	UINT32	ulAcctInterimInterval;	/* 计费信息上报间隔 */
	UINT32  	ulSessionTimeout;       	/* 会话超时时间 */
	UINT32      ulIdleTimeout;             /*add by gwx 2012-6-4 for bug1101 AAA下发用户无流量下线时间*/
	CHAR	acUserGroupName[128];	 /*add by gwx 2012-10-14 for task1076 radius命名的用户类别名称*/
	/* 用户的QOS信息，待扩展 */
	AC_USR_QOS_T	stQos;	/* 用户QOS */
} AC_USRM_UPDATE_USER_SUBINFO_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_USRM_UPDATE_USER_SUBINFO_RSP_T;

/*更新用户位置信息入出参结构体定义*/
typedef struct 
{
    	UINT8    aucMac[6];
	UINT8    aucRsv[2];
   	UINT32    ulPosX;
	UINT32    ulPosY;
} AC_USRM_UPDATE_USER_POS_REQ_T;

typedef struct 
{
	UINT32    ulRet;
}AC_USRM_UPDATE_USER_POS_RSP_T;

/* 获取当前所有在线用户列表*/
typedef struct {
	UINT32        ulStartRec;     /* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_USRM_GET_ALLUSER_REQ_T;

typedef struct {
	UINT32 ulRet;
	UINT32  ulFinish;   /* 关系表所有记录是否已读取结束
                          	AC_DB_TABLE_READ_NOTFINISH  未结束
					AC_DB_TABLE_READ_FINISH        读取结束 */
	UINT32  ulNum;      /* 本次调用返回的配置数 */
	AC_USRM_USER_INFO_T       astUser[4];
} AC_USRM_GET_ALLUSER_RSP_T;

/* 根据用户当前接入的VAP标识获取用户QOS */
typedef struct
{
	AC_VAPID_T	stVapId;
	UINT8    aucMac[6];
	UINT8    aucRsv[2];
}AC_USRM_GET_USERQOS_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_USR_QOS_T	stQos;		/* 用户QOS */
} AC_USRM_GET_USERQOS_RSP_T;


/* 2011-3-7 pyy add: 获取胖用户的qos信息*/
typedef struct
{
	UINT32	ulVlanId;
	UINT8    aucMac[6];
	UINT8    aucRsv[2];
}AC_USRM_GET_WIREUSERQOS_REQ_T;

typedef AC_USRM_GET_USERQOS_RSP_T  AC_USRM_GET_WIREUSERQOS_RSP_T;

// 	功能描述：根据用户MAC地址和当前接入的端口判断用户是否需要Portal认证
// 	输入参数结构：
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
	AC_VAPID_T	stVapId;	/* 用户当前接入的VAP ID */
} AC_USRM_GET_USERPORTALSWITCH_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulPortalSwitch;	/* 是否需要强制Portal */
} AC_USRM_GET_USERPORTALSWITCH_RSP_T;

// 	功能描述：根据用户MAC地址设置用户的Portal认证状态
// 	输入参数结构：

typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
	UINT32	ulCertType;	/* 认证类型*/
	UINT32	ulPortalState;
	UINT32	ulFlag;		/* 1: 标识为OMC发起的强制用户下线*/
	UINT32	ulAcctTermCause;
} AC_USRM_SET_USERPORTALSTATE_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_USRM_SET_USERPORTALSTATE_RSP_T;

// 	功能描述：根据用户MAC地址获取用户的Portal认证状态
// 	输入参数结构：
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
} AC_USRM_GET_USERPORTALSTATE_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulPortalState;
} AC_USRM_GET_USERPORTALSTATE_RSP_T;

//将用户设置为IDS恶意用户
// 	输入参数结构：
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
	UINT32	ulReason;
} AC_USRM_ADD_IDSUSER_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_USRM_ADD_IDSUSER_RSP_T;

/* 设置用户PPPoE认证状态*/
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
	UINT32	ulState;		/* 0：未认证1：已认证*/
} AC_USRM_SET_USERPPPOESTATE_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_USRM_SET_USERPPPOESTATE_RSP_T;

/* 设置用户IP地址 */
typedef struct 
{
	UINT8	aucMac[6];
	UINT8	aucType;
	UINT8	aucRsv;
	UINT8	aucIp[4];
} AC_USRM_SET_USERIP_REQ_T;

typedef struct 
{
	UINT32	ulRet;
} AC_USRM_SET_USERIP_RSP_T;

// 	功能描述：根据用户MAC地址获取用户信息
// 	输入参数结构：
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
} AC_USRM_GET_USERINFO_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_USRM_USER_INFO_T		stUserInfo;
} AC_USRM_GET_USERINFO_RSP_T;

/* 根据用户IP地址获取用户信息*/
typedef struct 
{
	UINT8	aucIp[4];	/* 用户IP地址*/
} AC_USRM_GET_USERINFOBYIP_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_USRM_USER_INFO_T		stUserInfo;
} AC_USRM_GET_USERINFOBYIP_RSP_T;

/* 根据用户MAC获取用户所属VLAN信息*/
typedef struct 
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
} AC_USRM_GET_USERVLAN_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulVlanId;
	UINT8	aucMac[6];	/* 用户MAC地址 *//*2014.1.26 add by fangz*/
} AC_USRM_GET_USERVLAN_RSP_T;


/* 根据用户MAC获取用户所属的NAS信息*/
typedef struct 
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
}AC_USRM_GET_USERNASINFOBYMAC_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP：填AC与计费服务器通信的地址 */
	CHAR	acNasId[256];	/* NAS ID：根据用户当前接入的VLAN获取到热点ID */
}AC_USRM_GET_USERNASINFOBYMAC_RSP_T;

/* 根据用户IP获取用户所属的NAS信息*/
typedef struct 
{
	UINT8	aucIp[4];	/* 用户IP地址 */
}AC_USRM_GET_USERNASINFOBYIP_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP：填AC与计费服务器通信的地址 */
	CHAR	acNasId[256];	/* NAS ID：根据用户当前接入的VLAN获取到热点ID */
}AC_USRM_GET_USERNASINFOBYIP_RSP_T;

/* 根据VAP ID或用户MAC地址获取用户的NAS信息*/
typedef struct
{
	AC_VAPID_T	stVapId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_USRM_GET_NASINFO_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP：填AC与计费服务器通信的地址 */
	CHAR	acNasId[256];	/* NAS ID：根据用户当前接入的VLAN获取到热点ID */
}AC_USRM_GET_NASINFO_RSP_T;

/* 2011-3-7 pyy add: 获取胖用户的nas 信息*/
typedef struct
{
	UINT32	ulVlanId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
} AC_USRM_GET_WIRENASINFO_REQ_T;

typedef AC_USRM_GET_NASINFO_RSP_T AC_USRM_GET_WIRENASINFO_RSP_T;

/* 根据用户地址获取用户认证配置*/
typedef struct 
{
	UINT8	aucMac[6];		/* 用户MAC */
	UINT8	aucRsv[2];
} AC_USRM_GET_USERPORTAL_CONFIG_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	CHAR     acSsid[32];
     	UINT8    aucPortalIp[4];
     	CHAR     acPortalURL[64];
     	UINT32   ulPortalPort;
} AC_USRM_GET_USERPORTAL_CONFIG_RSP_T;

/* 获取IDS恶意用户列表*/
typedef struct {
	UINT32	ulStartRec;     /* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_USRM_GET_ALLIDSUSER_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;   /* 关系表所有记录是否已读取结束
                          		AC_DB_TABLE_READ_NOTFINISH  未结束
						AC_DB_TABLE_READ_FINISH        读取结束 */
	UINT32	ulNum;      /* 本次调用返回的配置数 */
	AC_USRM_MAC_T	astIdsUser[100];
	
	/* 2010-4-10 pyy 新增*/
	UINT32	aulBlackListAddReason[100];	/* 终端加入黑名单原因 */
	UINT32	aulBlackListDuration[100];		/* 终端在黑名单中还要保持的时间，单位：秒 */
} AC_USRM_GET_ALLIDSUSER_RSP_T;

typedef struct
{
	UINT32	ulWtpId;	/* AP 设备ID */
} AC_USRM_GET_APSTAASSONUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;
} AC_USRM_GET_APSTAASSONUM_RSP_T;


typedef struct
{
	UINT32	ulWtpId;	/* AP 设备ID */
} AC_USRM_GET_APSTAONLINENUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;
} AC_USRM_GET_APSTAONLINENUM_RSP_T;

#define AC_GETAPSTA_NUM_MAX		1000
typedef struct {
	UINT32	ulStartRec;     /* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_USRM_GET_ALLAPSTANUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;   /* 关系表所有记录是否已读取结束
                          		AC_DB_TABLE_READ_NOTFINISH  未结束
						AC_DB_TABLE_READ_FINISH        读取结束 */
						
	UINT32	ulSkipNum;		/* 后续调用接口时, ulStartRec需要加上ulSkipNum */					
	UINT32	ulWtpNum;      	/* 本次调用返回的配置数 */
	
	UINT32	aulWtpId[AC_GETAPSTA_NUM_MAX];
	UINT32	aulStaAssocSum[AC_GETAPSTA_NUM_MAX];
	UINT32	aulStaOnlineSum[AC_GETAPSTA_NUM_MAX];
} AC_USRM_GET_ALLAPSTANUM_RSP_T;



#define AC_SSIDSTA_NUM_MAX  1000

typedef struct {
	UINT32	ulStartRec;     /* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_USRM_GET_ALLSSIDSTANUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;   /* 关系表所有记录是否已读取结束
                          		AC_DB_TABLE_READ_NOTFINISH  未结束
						AC_DB_TABLE_READ_FINISH        读取结束 */
	UINT32	ulSkipNum;	/* 后续调用接口时, ulStartRec需要加上ulSkipNum */							
	UINT32	ulVapNum;
	UINT32	aulWtpId[AC_SSIDSTA_NUM_MAX];
	UINT32	aulVapId[AC_SSIDSTA_NUM_MAX];
	UINT32	aulStaAssocSum[AC_SSIDSTA_NUM_MAX];
	UINT32	aulStaOnlineSum[AC_SSIDSTA_NUM_MAX];
} AC_USRM_GET_ALLSSIDSTANUM_RSP_T;

// 	功能描述：根据用户MAC地址获取用户认证状态
// 	输入参数结构：
typedef struct
{
	UINT8	aucMac[6];	/* 用户MAC地址 */
	UINT8	aucRsv[2];	/* 填充字节 */
} AC_USRM_GET_USERCERTSTATE_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;			/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulCertType;		/* 认证类型*/
    	UINT32	ulCertState;		/* 认证状态*/
} AC_USRM_GET_USERCERTSTATE_RSP_T;

typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
	UINT32	ulRet;	/* 0表示成功
						1: 强制下线失败, 失败原因用户不存在*/
} AC_USRM_MACRET_T;

typedef struct
{
	UINT32	ulSn;
	UINT32	ulUserNum;
	AC_USRM_MAC_T	astUserList[500];
} AC_USRM_FORCE_USEROFFLINE_REQ_T;

typedef struct 
{
	UINT32	ulSn;
	UINT32	ulUserNum;
	AC_USRM_MACRET_T	astUserList[500];
}AC_USRM_FORCE_USEROFFLINE_RSP_T;

/* 2010-3-4 新增: 强制PPPOE认证用户下线*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
}AC_USRM_PPPOE_USEROFFLINE_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* AC_OK表示成功 */
}AC_USRM_PPPOE_USEROFFLINE_RSP_T;


typedef struct
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];
} AC_USRM_GET_NASIP_RSP_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;
} AC_USRM_GET_PORTALONLINEUSER_RSP_T;

typedef struct
{
	UINT8	aucIp[4];
} AC_USRM_INC_WEBUSERABNORMALOFFLINE_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_USRM_INC_WEBUSERABNORMALOFFLINE_RSP_T;

typedef struct
{
	UINT8	aucIp[4];
} AC_USRM_INC_WEBAUTHREQ_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_USRM_INC_WEBAUTHREQ_RSP_T;

typedef struct
{
	UINT8	aucIp[4];
} AC_USRM_INC_WEBAUTHSUCCREQ_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_USRM_INC_WEBAUTHSUCCREQ_RSP_T;

#define AC_USRM_USERAGENT_LEN_MAX	256

typedef struct
{
	UINT8	aucIp[4];
	CHAR	acUserAgent[AC_USRM_USERAGENT_LEN_MAX];
}AC_USRM_SET_USERAGENT_REQ_T;

typedef struct
{
	UINT32	ulRet;
}AC_USRM_SET_USERAGENT_RSP_T;

typedef struct
{
	UINT8	aucIp[4];
}AC_USRM_GET_USERAGENT_REQ_T;

typedef struct
{
	UINT32	ulRet;
	CHAR	acUserAgent[AC_USRM_USERAGENT_LEN_MAX];	
}AC_USRM_GET_USERAGENT_RSP_T;


typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT8	aucIp[4];
}AC_USRM_SET_MACAUTHRES_REQ_T;

typedef struct
{
	UINT32	ulRet;
}AC_USRM_SET_MACAUTHRES_RSP_T;


//	用户接入通知
typedef AC_USRM_USER_INFO_T AC_USRM_USER_ADD_IND_MSG_T;

//	用户离开通知
typedef AC_USRM_USER_INFO_T AC_USRM_USER_DEL_IND_MSG_T;

//	用户Portal认证上下文删除通知
// 	功能描述：用户删除后，用户管理模块在Portal重认证时间间隔内保留Portal认证状态，在重认证间隔超时后，通知Portal模块
 //	消息体结构：
typedef struct 
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	/* 填充字节 */
} AC_USRM_USERPORTAL_DEL_IND_MSG_T;

/* 用户切换通知*/
typedef AC_USRM_USER_INFO_T AC_USRM_USER_ACCTUPDATE_IND_MSG_T;

typedef struct
{
	UINT8	aucIp[4];
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_USRM_USER_TS_START_IND_MSG_T;

typedef AC_USRM_USER_TS_START_IND_MSG_T AC_USRM_USER_TS_END_IND_MSG_T;

typedef struct
{
	UINT8	aucIp[4];
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32	ulCertType;
	UINT32	ulCertState;
	UINT32	ulAcctTermCause;
}AC_USRM_USER_CERTSTATE_CHANGE_IND_MSG_T;

/* 用户QOS信息变化通知*/
typedef AC_USRM_USER_INFO_T		AC_USRM_USER_QOS_CHANGE_IND_MSG_T;

typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT8	aucIp[4];
}AC_USRM_USER_SESSIONTIMEOUT_IND_MSG_T;

typedef AC_USRM_MAC_T AC_USRM_IDSUSER_ADD_IND_MSG_T;

typedef AC_USRM_MAC_T AC_USRM_IDSUSER_DEL_IND_MSG_T;

typedef struct
{
	UINT8	aucNasIp[4];
} AC_USRM_NASIP_UPDATE_IND_MSG_T;

typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT8	aucIp[4];
} AC_USRM_MACAUTH_REQ_MSG_T;

/* 根据用户MAC地址获取MAC认证配置*/

typedef struct
{
	UINT32	ulMacSwitch;			/*	MAC认证开关*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	UINT32	ulTrafficTime;			/*	MAC认证触发时间*/
	UINT32	ulTrafficThresh;		/*	MAC认证触发流量*/
} AC_USRM_MACSERVER_CONFIG_T;

typedef struct 
{
	
	UINT32	ulMacSwitch;			/*	MAC认证开关*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	UINT32	ulTrafficTime;			/*	MAC认证触发时间*/
	UINT32	ulTrafficThresh;		/*	MAC认证触发流量*/
	UINT32	ulMOC;				/*	对象类标识*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	对象实例标识*/
}AC_USRM_SSIDMACSERVERSETUP_CONFIG_T;

typedef	struct
{
	UINT8	aucMac[6];		/* 用户MAC */
	UINT8	aucRsv[2];		/* 填充字节 */
}AC_USRM_GET_USERMACSERVER_CONFIG_REQ_T;

typedef struct 
{
	UINT32 	ulRet;
	AC_USRM_MACSERVER_CONFIG_T		stMacServerCfg;
} AC_USRM_GET_USERMACSERVER_CONFIG_RSP_T;

/* add by gwx 2011-11-1 for 广东移动*/
typedef struct
{
	UINT32	ulAuthType;		/* 认证类型  */
	UINT8	aucIp[4];		/* 用户IP */
	UINT8	aucMac[6];		/* 用户MAC */
	UINT8	aucRsv[2];		/* 保留字节 */
	UINT32	ulStatType;		/* 统计类型 */
	UINT32	ulWtpId;		/* AP ID 号*/
	UINT32	ulVapId;			/* VAP ID号*/
} AC_USRM_INC_AUTHSTAT_REQ_T;
typedef struct
{
	UINT32	ulRet;
} AC_USRM_INC_AUTHSTAT_RSP_T;
typedef struct
{
	UINT32 ulPortalAuthTime;        		/*Portal认证终端鉴权次数*/
	UINT32 ulAssociateAuthTime;         	/*关联认证终端鉴权次数*/
	UINT32 ulMacAuthTime;				/*MAC认证终端鉴权次数*/
	UINT32 ulPortalAuthFailTime;        	 /*Portal认证终端鉴权失败次数*/
	UINT32 ulAssociateAuthFailTime;		/*关联认证终端鉴权失败次数*/
	UINT32 ulMacAuthFailTime;             /*MAC认证终端鉴权失败次数*/
	UINT32 ulPortalAuthSuccNum;	        /*Portal认证终端鉴权成功次数*/
	UINT32 ulAssociateAuthSuccNum;	 	/*关联认证终端鉴权成功次数*/
	UINT32 ulMacAuthSuccNum;	        /*MAC认证终端鉴权成功次数*/
	UINT32 ulPortalOnlineUserNum;			/*当前通过WEB认证的在线用户数*/
	UINT32 ulFreeOnlineUserNum;			/*当前通过免认证的在线用户数*/
	UINT32 ulAssociateOnlineUserNum;    	/*当前通过关联认证的在线用户数*/
	UINT32 ulMacOnlineUserNum; 			/*当前通过MAC认证的在线用户*/
	UINT32 ulPortalOfflineUserNum;          	/*Portal认证用户异常下线次数*/
	UINT32 ulFreeOfflineUserNum;            	/*免认证用户异常下线次数*/
	UINT32 ulAssociateOfflineUserNum;   		/*关联认证用户异常下线次数*/
	UINT32 ulMacOfflineUserNum;            	/*MAC认证用户异常下线次数*/
} AC_USRM_GET_ACAUTHSTAT_RSP_T;
/* add by gwx 2011-11-1 for 广东移动end*/

/*EAP认证用户 无流量下线，通知hostapd*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	AC_VAPID_T		stVapId;
} AC_USRM_EAPUSEROFFLINE_REQ_MSG_T;

/* add by gwx 2012-6-4 for bug 1100 添加用户成功后主动向DHCP申请地址*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_USRM_USERIP_REQ_MSG_T;

/* add by gwx 2012-10-31 for 用户流量不准确begin*/

typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32 	ulUserRxPkts;		/* 用户下行包数*/
	UINT32	ulUserTxPkts;		/* 用户上行包数*/
	UINT32	ulUserCurRx4GB;		/* 进制位*/
	UINT32	ulUserCurRxBytes;	/* 用户下行流量*/
	UINT32	ulUserCurTx4GB;		/* 进制位*/
	UINT32	ulUserCurTxBytes;	/* 用户上行流量*/
} AC_USRM_USERTRAFFIC_T;

/* AP设置用户流量请求消息体*/
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulUserNum;
	AC_USRM_USERTRAFFIC_T	astUserTraffic[AC_WTP_MAX_USERNUM];
} AC_USRM_SET_USERTRAFFIC_T;	

#if 0
/* 通知AP非法用户消息体*/

typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32	ulCertChgRsnCode;	/* 认证状态变化的原因码，针对下线*/
	UINT32	ulCertChgTime;		/* 认证状态变化的时间*/
} AC_USRM_ILLEGALUSER_T;
#endif

typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32 	ulGetForStop;  	/* 认证停止原因标记位*/
}AC_USRM_GET_USERTRAFFIC_BYMAC_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32 	ulUserRxPkts;			/* 用户下行包数*/		
	UINT32	ulUserTxPkts;			/* 用户上行包数*/
	UINT32	ulUserCurRx4GB;			/* 进制位*/
	UINT32	ulUserCurRxBytes;		/* 用户下行流量*/
	UINT32	ulUserCurTx4GB;			/* 进制位*/
	UINT32	ulUserCurTxBytes;		/* 用户上行流量*/
}AC_USRM_GET_USERTRAFFIC_BYMAC_RSP_T;


typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32	ulCertChgRsnCode;	/* 认证状态变化的原因码，针对下线*/
	UINT32	ulCertChgTime;		/* 认证状态变化的时间*/
	/* add by gwx 2014-5-30 for 广东电网*/
	UINT32	ulVlan;
	UINT32	ulMacCertTag;		/* add by gwx 2014-7-21 */
}AC_USRM_USER_CERTSTATCHG_T;

typedef AC_USRM_USER_CERTSTATCHG_T	AC_USRM_USER_STARTTRAFFIC_T;
typedef AC_USRM_USER_CERTSTATCHG_T	AC_USRM_USER_STOPTRAFFIC_T;
typedef AC_USRM_USER_CERTSTATCHG_T	AC_USRM_ILLEGALUSER_T;

typedef struct
{
	UINT32	ulIllegalUserNum;
	AC_USRM_ILLEGALUSER_T	astIllegalUser[128];
} AC_USRM_CLEAR_ILLEGALUSER_T;	


typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32	ulRet;				/* 处理结果返回,0成功,0xFFFFFFFF失败*/
}AC_USRM_USER_CERTSTATCHG_AP_RPT_T;

typedef AC_USRM_USER_CERTSTATCHG_AP_RPT_T	AC_USRM_USER_STARTTRAFFIC_AP_RTP_T;
typedef AC_USRM_USER_CERTSTATCHG_AP_RPT_T	AC_USRM_USER_STOPTRAFFIC_AP_RPT_T;

typedef struct
{
	UINT8	aucMac[6];			/* 用户MAC */
	UINT8	aucRsv[2];
	UINT32	ulWtpId;
	UINT32	ulCertChgRsnCode;	/* 认证状态变化的原因码，针对下线*/
	UINT32	ulCertChgTime;		/* 认证状态变化的时间*/
	/* add by gwx 2014-5-30 for 广东电网*/
	UINT32	ulVlan;
	UINT32	ulMacCertTag;		/* add by gwx 2014-7-21 */
}AC_USRM_USER_TRAFFIC_T;
typedef AC_USRM_USER_TRAFFIC_T		AC_USRM_STARTUSERTRAFFIC_T;
typedef AC_USRM_USER_TRAFFIC_T		AC_USRM_STOPUSERTRAFFIC_T;

/* add by gwx 2012-10-31 for 用户流量不准确end*/

/* add by gwx 2012-11-29 for AP/VAP级流控*/
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT8    	aucMac[6];
	UINT8    	aucRsv[2];
	CHAR	acSsid[32];
}AC_USRM_GET_USERQOS_CONF_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_USR_QOS_T	stQos;		/* 用户QOS */
} AC_USRM_GET_USERQOS_CONF_RSP_T;
typedef struct
{
	UINT32  ulWifiDeviceId;
	UINT32  ulVapId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32  ulUserUpBandMax;
	UINT32  ulUserDownBandMax;
} AC_USRM_MAC_FLOWCTRL_T;


typedef struct
{
	UINT32	ulSn;
	AC_USRM_MAC_FLOWCTRL_T stUserFlowCtrl;
} AC_USRM_ADD_USER_FLOWCTRL_REQ_T;

typedef struct 
{
	UINT32	ulSn;
	AC_USRM_MACRET_T stUserRet;
} AC_USRM_ADD_USER_FLOWCTRL_RSP_T;

typedef struct
{
	UINT32	ulSn;
	UINT8  aucMac[6];
	UINT8  aucResv[2];
} AC_USRM_DEL_USER_FLOWCTRL_REQ_T;

typedef struct 
{
	UINT32	ulSn; 
	AC_USRM_MACRET_T stUserRet;
} AC_USRM_DEL_USER_FLOWCTRL_RSP_T;

typedef struct
{
	UINT32	ulSn;
	UINT32 ulUserNum;	
	AC_USRM_MAC_FLOWCTRL_T	astUserFlowCtrlList[128];
} AC_USRM_UPDATE_ALL_USER_FLOWCTRL_REQ_T;

typedef struct 
{
	UINT32	ulSn; 
	UINT32	ulUserNum;
	AC_USRM_MACRET_T	astUserFlowCtrlList[128];
} AC_USRM_UPDATE_ALL_USER_FLOWCTRL_RSP_T;

typedef struct
{
	UINT32 ulWtpNum;
	UINT32 aulWtpId[4096];
}AC_USRM_WTP_UPDATE_ALLUSER_T;

/* add by gwx 2013-1-23 for bug1718 */
typedef struct 
{
	CHAR acSsid[32];
} AC_USRM_GET_USERPORTAL_CONFIG_BYSSID_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT8    aucPortalIp[4];
    	UINT32  ulPortalPort;
} AC_USRM_GET_USERPORTAL_CONFIG_BYSSID_RSP_T;

/* add by gwx 2013-10-14 for task1076 企业网用户组流控，
获取用户认证信息结构*/
typedef struct
{
	UINT8 	aucUserMac[6];
	UINT8	aucRsv[2];
}AC_USRM_GET_USERGROUPQOS_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulUserGroupUpBandMax;
	UINT32	ulUserGroupDownBandMax;
}AC_USRM_GET_USERGROUPQOS_RSP_T;

/* add by gwx 2014-4-15 for bug5293 */
typedef struct
{
	UINT8 	aucUserMac[6];
	UINT8 	aucRsv[2];
	UINT32	ulCertType;
	UINT32	ulCertState;
	UINT32	ulMacState;
	CHAR	acUserName[256];
	CHAR	acVapSsid[32];
	UINT32	ulSessionTimeout;
	UINT32	ulIdleTimeout;
	UINT32	ulWtpId;
	UINT32	ulIfId;
	UINT32	ulVapId;
	UINT32	ulCertStateOkTime;
	UINT32	ulAuthType;
#if 0	/* mod by gwx 2014-6-5 */
	UINT32	ulUserGroupId;
#else
	CHAR	acUserGroupName[128];
#endif
	UINT8	aucUserIp[4];
}AC_USRM_USERPORTAL_INFO;

/* add by gwx 2014-6-25 for SSID用户控制接入begin*/
typedef struct
{
	UINT8	aucUserMac[6];
	UINT8	aucRsv[2];
	CHAR	acSsidName[32];
}AC_USRM_GET_USERACCESSPERMIT_REQ_T;
typedef struct
{
	UINT32	ulRet;
	UINT32	ulAccessPermit;
}AC_USRM_GET_USERACCESSPERMIT_RSP_T;
/* add by gwx 2014-6-25 for SSID用户控制接入end*/
/* add by gwx 2014-5-13 for 锐捷，AP上报用户信息*/
typedef struct
{
	UINT8 aucUserMac[6];
	UINT8 aucRsv[2];
	UINT8 aucUserIp[4];
	UINT32 ulUserRssi;
	CHAR  acStaType[32];/* add by gwx 2014-9-3 添加AP上报终端设备类型*/
}AC_USRM_WTPUSERPARTINFO_T;
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulRecNum;
	AC_USRM_WTPUSERPARTINFO_T	stWtpUserPartInfo[AC_WTP_MAX_USERNUM];
}AC_USRM_SET_USERPARTINFOFROMAP_T;


/* 接口结构体定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 函数声明开始*/
extern VOID ac_usrm_add_user (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_del_user (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_update_user_subinfo (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_update_user_pos (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_alluser (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userqos (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userportalswitch (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_set_userportalstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userportalstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_add_idsuser (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userinfo (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userinfobyip (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_set_userip (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_set_userpppoestate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_uservlan (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_usernasinfobymac (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_usernasinfobyip (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_nasinfo (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_userportal_config(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_allidsuser (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_usercertstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_nasip(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_usrm_get_apstaassonum (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_apstaonlinenum (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_allapstanum (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_allssidstanum (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_portalonlineuser(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_inc_webuserabnormaloffline(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_inc_webauthreq(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_inc_webauthsuccreq(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_usrm_get_wireuserqos(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_wirenasinfo(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_usrm_set_useragent(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_useragent(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_set_macauthres(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_usrm_get_usermacserverconfig(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_inc_userauthstatconfig(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_usrm_get_acuserauthstatconfig(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_usrm_perf_report_vap_user (VOID);
extern VOID ac_usrm_perf_report_wtp_user (VOID);
extern VOID ac_usrm_perf_report_ac_user(VOID);

extern VOID ac_usrm_perf_report_vap_time (VOID);
extern VOID ac_usrm_perf_report_wtp_time (VOID);
extern VOID ac_usrm_perf_report_ac_time (VOID);

extern VOID ac_usrm_perf_report_vap_traffic (VOID);
extern VOID ac_usrm_perf_report_wtp_traffic (VOID);
extern VOID ac_usrm_perf_report_ac_traffic (VOID);

extern VOID ac_usrm_perf_null (VOID);

extern VOID ac_usrm_perf_clear_user (VOID);
extern VOID ac_usrm_perf_clear_time (VOID);
extern VOID ac_usrm_perf_clear_traffic (VOID);

extern UINT32   ac_usrm_init (VOID);
extern UINT32   ac_usrm_get_if_outlen(UINT32 ulMsgId, UINT32 *pulOutLen);
extern	UINT32 ac_usrm_get_usrmacserver_config(CHAR* usrSsid, AC_USRM_SSIDMACSERVERSETUP_CONFIG_T* macServerConfig );
/* add by gwx 2012-11-2 for 用户流量不准确*/
extern VOID ac_usrm_send_startusertraffic( AC_USRM_STARTUSERTRAFFIC_T* pstStartUserTaffic );
extern VOID ac_usrm_send_stopusertraffic( AC_USRM_STOPUSERTRAFFIC_T* pstStartUserTaffic );

extern VOID ac_usrm_get_usertraffic_bymac(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern VOID ac_usrm_get_userqosconfig(AC_USRM_GET_USERQOS_CONF_REQ_T   *pstReq, AC_USRM_GET_USERQOS_CONF_RSP_T   *pstRsp);
extern VOID ac_usrm_send_wtpuserflowctrl( AC_USRM_WTP_UPDATE_ALLUSER_T* pstMsg);

extern VOID ac_usrm_send_adduserflowctrl( UINT32 ulWtpId, AC_USRM_ADD_USER_FLOWCTRL_REQ_T *pstAddUserFlowCtrl);
extern VOID ac_usrm_send_deluserflowctrl( UINT32 ulWtpId, AC_USRM_DEL_USER_FLOWCTRL_REQ_T *pstDelUserFlowCtrl);

/* add by gwx 2013-1-23 for bug1718 */
extern VOID ac_usrm_get_userportal_config_byssid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

/* add by gwx 2014-6-25 for SSID级用户接入控制*/
extern VOID ac_usrm_get_useraccesspermit(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
/* 函数声明结束*/

/******************************************************************************/

#endif /* _AC_USRM_PUBLIC_H */
/******************************* 头文件结束 **********************************/



