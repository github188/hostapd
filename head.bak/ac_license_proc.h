/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  配置流程头文件
* 修改历史: 
* 2012-1-5     吴彬             新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_LICENSE_PROC_H
#define  _AC_LICENSE_PROC_H



/*****************************LICENSE模块消息号定义*****************************/

/******************************************************************************/


#define AC_LICENSE_TIMER_GET_STATE              TIMER27	     	/*  	周期性上报License的使用情况定时器 */
#define AC_LICENSE_TIMEOUT_GET_STATE			EV_TIMER27
#define AC_LICENSE_TIMER_GET_STATE_LEN			36000		/* 单位100ms 60分钟 */

#define AC_LICENSE_TIMER_REPORT_STATE			TIMER26	     	/*  	周期性上报License的使用情况定时器超时 */
#define AC_LICENSE_TIMEOUT_REPORT_STATE			EV_TIMER26
#define AC_LICENSE_TIMER_REPORT_STATE_LEN       30000		/* 单位100ms 50分钟 */
/******************************************************************************/

#define send_port			(WORD16)(7868)      /* 发送端口号 */
#define listen_port			(WORD16)(7868)      /* 监听端口号 */


#define AC_LICENSE_WTPMAC_BEGIN_END_NUM		(UINT32)(10)
typedef struct {
    CHAR    ucApSerialNum[LICENSE_OMC_APSERIALNUM];
    UINT32	ulMacSum;        /* 表示本mac段有效mac数目  */
    UINT8 	ucApBeginMac[6];
    UINT8 	ucResv1[2];
    UINT8 	ucApEndMac[6];
    UINT8 	ucResv2[2];
} AC_LICENSE_WTPMAC_T;

/* AC侧CAPWAP控制license功能数据区结构体定义*/
typedef struct {
    /* ac function option */
    UINT32  ulWebStat;            /* web显示状态 */
    UINT32  ulWtpEnable;          /* ac能够接入ap基本功能 0-否 1-是 */
    UINT32  ulMaxWtp;             /* 最大允许接入的WTP数量*/
    UINT32  ulStaEnable;          /* ac能够接入sta基本功能 0-否 1-是 */
    UINT32  ulMaxSta;             /* 最大允许接入的STA数量*/
    UINT32  ulMaxAuthorTime;      /* 最后剩余允许接入的AP和STA的时间单位S */
    UINT32	ulTrafficMode;		  /* 表示是否支持集中转发模式 0-否 1-是 */
    UINT32	ulWtpMacEnable;		  /* 表示本ac是否支持apmac检查 0-否 1-是  */
    UINT32	ulWtpMacSum;		  /* 表示本ac有效mac数目  */
    UINT32	ulWtpMacNum;		  /* 表示本ac有效mac范围段  */
    AC_LICENSE_WTPMAC_T astWtpMac[AC_LICENSE_WTPMAC_BEGIN_END_NUM]; /* 实际起始和结束mac范围段  */
} AC_CW_LICENSE_CTRL_T;


extern AC_CW_LICENSE_CTRL_T gstAcLicenseCtl;
extern AC_LICENSE_OMC_T gstAcLicenseOmcInfo;


/******************************************************************************/
extern UINT32	ac_license_init_scan_timer(VOID);
extern UINT32 ac_license_init_report_timer(VOID);
extern UINT32	ac_license_reinit_scan_timer(VOID);
extern UINT32 ac_license_reinit_report_timer(VOID);
extern UINT32 ac_license_reinit_report_timeout(VOID);
extern UINT32	ac_license_init_so(VOID);
extern UINT32	ac_license_proc_init(VOID);
extern UINT32    ac_license_init (VOID);
extern UINT32    ac_license_if_reg (UINT32    ulMsgId, DBIF pfFunc);
extern UINT32  ac_license_get_if_outlen(UINT32 ulMsgId, UINT32 *pulOutLen);
extern VOID ac_license_check_verify(VOID);
extern VOID ac_license_report_info(VOID);
extern VOID ac_license_report_info_timeout(VOID);
extern UINT32 ac_license_check_function(UINT32 ulFunctionId);
extern VOID ac_license_disenable(VOID);
extern VOID ac_license_disenable_wtpnum(UINT32 ulWtpNum);
extern VOID ac_license_disenable_wtp(UINT32 ulWtpId);

extern UINT32	ac_license_bk_init(VOID);
extern VOID ac_license_bk_run(VOID);
extern VOID ac_license_bk_destroy(VOID);
extern VOID ac_license_bk_msg_handle(UINT32 ulMsgId, UINT32 ulMsgLen, VOID *pvMsg);
extern UINT32	ac_license_msg_send_ip(UINT16 usEvent, CHAR *pcMsg, UINT32 usMsgLen, UINT16 usPno, UINT8 *pucIp);


#endif /* _AC_LICENSE_PROC_H */
/******************************* 头文件结束 **********************************/

