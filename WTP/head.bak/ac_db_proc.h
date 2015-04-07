/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  数据库统一接口功能头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DB_PROC_H
#define  _AC_DB_PROC_H

/* 标准接口函数定义 */
typedef VOID (*DBIF)(UINT8*, UINT32, UINT8*, UINT32*);
typedef VOID (*DBPERF)(VOID);

/* AC设备生产信息*/
typedef struct
{
	CHAR	acAcDevSN[6];			/* 设备序列号*/
	CHAR	acRsv[2];				/* 填充字节*/
	CHAR	acAcDevType[32];		/* 设备型号*/
	CHAR	acAcSwVersion[32];		/* 设备软件版本号*/
	CHAR	acAcHwVersion[32];		/* 设备硬件版本号*/
	CHAR	acAcManufacturer[128];	/* 设备制造商*/
	CHAR	acAcSwDeveloper[128];	/* 设备软件制造商*/
} AC_DB_DEVICE_ACPRODUCE_T;

typedef struct
{
	UINT32   ulAcId;               		 	//AC ID
     	CHAR      acAcDevName[32];      	//AC NAME
	CHAR     acAcDevType[32];        	//设备型号
    	CHAR     acAcDevSN[6];           		//设备序列号：位于 /etc/gb
     	UINT8    aucResv1[2]; 
    	CHAR     acAcSwVersion[32];     	//设备软件版本
    	CHAR     acAcHwVersion[32];		//设备硬件版本

    	UINT8   aucFitLanIp[4];   		/* FIT-LAN IP */
	UINT8   aucFitLanMask[4];  	/* FIT-LAN MASK */
	
    	UINT8   aucFatLanIp[4];   		/* FAT-LAN IP */
	UINT8   aucFatLanMask[4];   	/* FAT-LAN MASK */

    	UINT8   aucL2WanIp[4];   		/* L2-WAN IP */
    	UINT8   aucL2WanMask[4];   	/* L2-WAN MASK */
    	
    	UINT8   aucL3WanIp[4];   		/* L3-WAN IP */
    	UINT8   aucL3WanMask[4];   	/* L3-WAN MASK */

    	UINT8    aucDefaultGw[4];			/* 缺省网关*/
	UINT8    aucPrimaryDns[4];             /* 主用DNS服务器*/
     	UINT8    aucSecondaryDns[4];         /* 备用DNS服务器*/
} AC_DB_DEVICE_ABSTRACT_T;


/******************************定时器相关宏定义start ******************************/
/* 定时器时长: 单位为100ms*/
#define AC_DB_TIMERLEN_DYN_REPORT			100		/* 上报AC启动事件定时器时长*/
#define AC_DB_TIMERLEN_CHECK_PAYLOAD			1800	/* 周期性检查负荷定时器时长*/
/* 2008-11-8 pyy: 将获取周期修改为1分钟*/
#define AC_DB_TIMERLEN_GET_VAPSTAT			600		/* AP周期性获取VAP流量统计定时器时长*/
#define AC_DB_TIMERLEN_CHECK_DYNEVENT_TBL	18000	/* 周期性检查事件记录表定时器时长*/
/* 2009-10-28 pyy 从30秒修改为1分钟*/
#define AC_DB_TIMERLEN_GET_ONLINEUSERSTAT	600		/* 在线用户数统计定时器时长
														    AC以小粒度进行统计， 统计平均后上报到OMC */
/* pyyL 2009-6-13 修改为5分钟*/														    
#define AC_DB_TIMERLEN_PRD_DYNREPORT			3000	/* 周期性上报动态数据定时器时长
														   5分钟*/   
														   
#define AC_DB_TIMERLEN_WTPASSO_ALARM		1800	/* AP关联状态告警检查定时器 时长*/
#define AC_DB_TIMERLEN_CHECK_VLANUSER_TBL	100		/* 用户VLAN状态缓存表检查定时器时长*/
#define AC_DB_TIMERLEN_CHECK_IDSUSER_TBL		1800	/* IDS恶意用户表检查定时器时长*/

#define AC_DB_TIMERLEN_CHECK_DATSAVEFLAG		3000		/* 2011-5-19 pyy新增: 周期性检查存盘标记位*/

#define AC_DB_TIMER_DYN_REPORT          			TIMER1	/* 上报AC启动事件定时器*/
#define AC_DB_TIMER_CHECK_PAYLOAD			TIMER3	/* 周期性检查负荷定时器*/
#define AC_DB_TIMER_GET_VAPSTAT				TIMER4	/* AP周期性获取VAP流量统计定时器 */
#define AC_DB_TIMER_CHECK_DYNEVNET_TBL		TIMER5	/* 周期性检查事件记录表定时器*/
#define AC_DB_TIMER_GET_ONLINEUSERSTAT		TIMER6	/* 在线用户数统计定时器 */
#define AC_DB_TIMER_PRD_DYNREPORT			TIMER7	/* 周期性上报动态数据定时器*/
#define AC_DB_TIMER_WTPASSO_ALARM			TIMER8	/* AP关联状态检查定时器*/
#define AC_DB_TIMER_CHECK_VLANUSER_TBL		TIMER9	/* 用户VLAN状态缓存表检查定时器*/
#define AC_DB_TIMER_CHECK_IDSUSER_TBL		TIMER10	/* IDS恶意用户检查定时器*/
#define AC_DB_TIMER_CHECK_DATSAVEFLAG		TIMER11	/* 2011-5-19 pyy新增: 周期性检查存盘标记位定时器*/


#define AC_DB_TIMEROUT_DYN_REPORT_MSG   			EV_TIMER1
#define AC_DB_TIMEROUT_CHECK_PAYLOAD_MSG		EV_TIMER3
#define AC_DB_TIMEROUT_GET_VAPSTAT_MSG			EV_TIMER4
#define AC_DB_TIMEROUT_CHECK_DYNEVENT_TBL_MSG	EV_TIMER5
#define AC_DB_TIMEROUT_GET_ONLINEUSERSTAT_MSG	EV_TIMER6
#define AC_DB_TIMEROUT_PRD_DYNREPORT				EV_TIMER7
#define AC_DB_TIMEROUT_WTPASSO_ALARM_MSG		EV_TIMER8
#define AC_DB_TIMEROUT_CHECK_VLANUSER_TBL_MSG	EV_TIMER9
#define AC_DB_TIMEROUT_CHECK_IDSUSER_TBL_MSG	EV_TIMER10
#define AC_DB_TIMEROUT_CHECK_DATSAVEFLAG_MSG	EV_TIMER11	/* 2011-5-19 pyy新增: 周期性检查存盘标记位定时器*/

/* add by gwx 2012-11-1 for 用户流量不准确*/
#define AC_USRM_TIMER_START_USERTRAFFIC		TIMER12
#define AC_USRM_TIMER_STOP_USERTRAFFIC		TIMER13
#define	AC_USRM_TIMER_WAIT_ACCOUNT_STOPGET	TIMER14

#define AC_USRM_TIMEOUT_START_USERTRAFFIC	EV_TIMER12
#define AC_USRM_TIMEOUT_STOP_USERTRAFFIC	EV_TIMER13
#define AC_USRM_TIMEOUT_WAIT_ACCOUNT_STOPGET	EV_TIMER14
#define	AC_USRM_TIMER_USERTRAFFIC_LEN	50		/* 单位100ms */
#define	AC_USRM_TIMER_WAIT_ACCOUNT_STOPGET_LEN	200	/* 单位100ms */
/* 定时器ID定义 */
#define AC_USRM_TIMER_GET_USERTRAFFIC		TIMER21		/* 获取用户流量统计信息的定时器*/
#define AC_USRM_TIMER_CHECK_USERTRAFFIC		TIMER22		/* 检查用户流量定时器: 如果在指定时间内用户无流量则AC认为用户下线*/
#define AC_USRM_TIMER_CHECK_SESSIONTIMEOUT	TIMER23		/* 检查用户session timeout 定时器*/
#define AC_USRM_TIMER_CHECK_MACUSER			TIMER24
#define AC_USRM_TIMER_CHECK_USERFLOWCTRL	TIMER25		/* 定期检查用户流控表定时器*/
#define AC_USRM_TIMER_SYNAP_USERFLOWCTRL	TIMER26		/* 定期与AP同步用户流控配置定时器*/

/* 定时器超时消息定义*/
#define AC_USRM_TIMEOUT_GET_USERTRAFFIC			EV_TIMER21
#define AC_USRM_TIMEOUT_CHECK_USERTRAFFIC		EV_TIMER22
#define AC_USRM_TIMEOUT_CHECK_SESSIONTIMEOUT	EV_TIMER23
#define AC_USRM_TIMEOUT_CHECK_MACUSER			EV_TIMER24
#define AC_USRM_TIMEOUT_CHECK_USERFLOWCTRL		EV_TIMER25
#define AC_USRM_TIMEOUT_SYNAP_USERFLOWCTRL		EV_TIMER26

/* 定时器时长定义*/
#define AC_USRM_TIMER_GET_USERTRAFFIC_LEN		300		/* 单位100ms */
#define AC_USRM_TIMER_CHECK_USERTRAFFIC_LEN		600
#define AC_USRM_TIMER_CHECK_SESSIONTIMEOUT_LEN	600
#define AC_USRM_TIMER_CHECK_MACUSER_LEN			100

#define AC_USRM_GET_USERTRAFFIC_NUM_MAX			100
#define AC_USRM_CHECK_USERTRAFFIC_NUM_MAX		100
#define AC_USRM_CHECK_SESSIONTIMEOUT_NUM_MAX	500
#define AC_USRM_CHECK_USERFLOWCTRL_NUM_MAX		100

#define AC_USRM_CHECK_USERFLOWCTRL_LEN		600
#define AC_USRM_SYNAP_USERFLOWCTRL_LEN		3000

/* AC检测到的用户下线:用户无流量时长超过门限值认为用户下线*/
#define AC_USRM_NOTRAFFIC_TIMELEN_MAX			6000	/*单位:秒*/


/******************************定时器相关宏定义end ******************************/


/******************************操作维护功能相关宏定义start ******************************/
/* WTP用户数门限定义*/
#define AC_WTP_USERNUM_LOW_THRESHOLD	20		/* 20% */
#define AC_WTP_USERNUM_HIGH_THRESHOLD	80		/* 80% */

/* AC CPU负荷门限定义*/
#define AC_CPULOAD_LOW_THRESHOLD		20		/* 20% */
#define AC_CPULOAD_HIGH_THRESHOLD	    80		/* 80% */
#define AC_CPULOAD_THRESHOLD_RANGE	    5		/* 5% */

/* AC用户数门限定义 */
#define AC_AC_USERNUM_LOW_THRESHLOD		20		/* 20% */
#define AC_AC_USERNUM_HIGH_THRESHLOD	80		/* 80% */

/* 周期性检查AC设备的用户数，当连续5个周期内AC的用户数都超过上限时，上报告警 */
/* 周期性检查AC设备的用户数，当连续5个周期内WTP的用户数都超过上限时，上报告警 */
/* 某个周期内用户数低于上限，且之前曾经上报过告警，则上报告警清除 */
/* 周期性检查WTP设备的用户数，当连续5个周期内WTP的用户数都低于下限时，上报告警  */
#define AC_USERLOAD_RECORD_NUM		10
#define AC_USERLOAD_HIGH_THRESHOLD_NUM		5
#define AC_USERLOAD_LOW_THRESHOLD_NUM		5

#define AC_CPULOAD_RECORD_NUM		        	10
#define AC_CPULOAD_HIGH_THRESHOLD_NUM		5

/* 非法WTP接入事件上报频度*/
#define AC_EVENT_RPT_PRD_WTP_ACCESS_DENY	1800	/* 1800秒，即30分钟*/

/* add by gwx 2014-8-14 */
#ifdef BIG_AC
#define OSS_CPU_NUM             (WORD16) (1050*4)
#else
#define OSS_CPU_NUM             (WORD16) 1050
#endif




/******************************操作维护功能相关宏定义end ******************************/

/******************************操作维护功能相关结构体定义start ******************************/

/******************************操作维护功能相关结构体定义end ******************************/

/******************************函数原型start ******************************/
extern VOID ac_db_init_pid(VOID);
extern UINT32  ac_db_init (VOID);
extern VOID    ac_db_recv_join_succ (UINT8 *pucMsg);
extern VOID ac_db_report_dyninfo(UINT8 ucMsgType);
extern VOID ac_db_report_apdyninfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID    ac_db_report_dyn_data(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apip (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_acip (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_msinfo (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apsn (UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apswver(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_vdevmaxpower(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_vapmac(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_adhocmac(UINT8 ucMsgType);
extern VOID ac_db_report_dyn_apinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_vdevinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_vapinfo(UINT8 ucMsgType, UINT32 ulWtpId);
extern VOID ac_db_report_dyn_adhocinfo(UINT8 ucMsgType, UINT32 ulWtpId);

extern VOID ac_db_check_load (VOID);
extern VOID ac_db_check_dynevent_tbl(VOID);
extern VOID ac_db_report_perf (UINT8 *pucMsg);
extern VOID ac_db_recv_join_succ (UINT8 *pucMsg);
extern VOID ac_db_vapstat_init (VOID);
extern VOID ac_db_wtpdyninfo_init (VOID);
extern VOID ac_db_report_ac_reboot_event (VOID);
extern VOID ac_db_oam_init (VOID);
extern UINT32 ac_db_oam_get_acmoid (AC_OMA_MO_T *pstAcMOID);
extern VOID ac_db_oam_report_event (UINT32 ulEventId,
                                    UINT32 ulEventReasonId,
                                    UINT32 ulMOC,
                                    UINT8	aucMOI[AC_MOI_LEN],
                                    UINT32 ulCommonInfo);
extern VOID ac_db_oam_report_alarm (UINT32 ulAlarmId,
                             UINT32 ulAlarmReasonId,
                             UINT32 ulAlarmLevel,
                             UINT32 ulMOC,
                             UINT8	aucMOI[AC_MOI_LEN],
                             UINT32 ulCommonInfo);

extern VOID ac_db_get_ap_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_wtpunregister_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_user_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_acif_dyninfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_useripinfo(UINT8 *pucMsg);
extern VOID ac_db_get_ac_vapwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_vapuseraccstat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_ifwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_ssidwifistat (UINT8 *pucRcvMsg);
extern VOID ac_db_get_vap_portalinfo (UINT8 *pucRcvMsg);
extern VOID ac_db_get_ac_apuserstat (UINT8 *pucRcvMsg);

extern UINT32 ac_db_make_default_cfg(UINT32 ulAcId);
extern VOID ac_db_check_datsaveflag(VOID);

/******************************函数原型end ******************************/

#endif /* _AC_DB_PROC_H */
/******************************* 头文件结束 **********************************/



