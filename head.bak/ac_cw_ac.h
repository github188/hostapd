/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: AC CAPWAP头文件
* 修改历史: 
* 2008-5-9     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_AC_H
#define  _AC_CW_AC_H

/* 上电消息 */
#define AC_CW_AC_POWER_ON    EV_MASTER_POWERON

/* 定时器ID */
#define AC_CW_TIMERID_WAIT_JOIN_REQUEST                    	TIMER0        	/* 等待WTP join request定时器ID */
#define AC_CW_TIMERID_WAIT_ECHO_REQUEST                    TIMER1        	/* 等待WTP echo request定时器ID */
#define AC_CW_TIMERID_WAIT_CFG_UPDATE_RESPONSE		TIMER2        	/* 等待WTP configuration update response 定时器ID */
#define AC_CW_TIMERID_DELAY_SET_APFAULT				TIMER3		/* 延迟设置AP故障定时器*/

/* 定时器消息*/
#define AC_CW_TIMEOUT_WAIT_JOIN_REQUEST        		EV_TIMER0
#define AC_CW_TIMEOUT_WAIT_ECHO_REQUEST			EV_TIMER1
#define AC_CW_TIMEOUT_WAIT_CFG_UPDATE_RESPONSE		EV_TIMER2
#define AC_CW_TIMEOUT_DELAY_SET_APFAULT				EV_TIMER3

#define AC_CW_DELAY_SET_APFAULT_INTERVAL				3000		/* 延迟设置AP故障定时器时长*/


/* AC侧CAPWAP控制数据区结构体定义*/
typedef struct {
    	/* omc config */
    	UINT32  ulAcId;
    	UINT8   aucIp[4];
    	UINT32  ulMaxWtp;             /* 最大允许接入的WTP数量*/
    	UINT32  ulWaitJoinInterval;   /* 等待join request定时器时长*/
    	UINT32  ulEchoInterval;       /* echo interval，echo request发送间隔 */
    	UINT32  ulWaitCURInterval;    /* 等待configuration update response消息间隔*/
    	UINT32  ulMaxRetransmit;      /* CAPWAP消息最大重传次数 */

    	/* 需要同步的关系表数目及句柄列表*/
    	UINT32      ulTblNum;
    	DBHANDLE    ahTblList[64];

	/* 2009-10-29 pyy 新增*/
	UINT32	ulCmCfgFlag;	/* 标识当前是否正在进行网管发起的配置数据同步*/
	
    	/* 当收到的响应数目与发送的请求数目达到相同时，向CM发送配置响应 */
    	UINT32  ulSendCURNum;                /* 发送的Configuration update request数目 */
    	UINT32  ulRecvCURNum;                /* 收到的Configuration update response数目 */

    	/* state info */
    	UINT32    ulCurWtp;                /* 当前接入的WTP数量 */    
    	AC_CW_WTPINFO_T    *pstWtpList;
} AC_CW_AC_CTRL_T;

extern UINT32 ac_cw_ac_init (VOID);
extern UINT32 ac_cw_ac_recv_power_on (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_discovery_request (UINT8    *pucMsg, UINT32    ulMsgLen, UINT32 ulPrimary);
extern VOID ac_cw_ac_recv_join_request (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_echo_request (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_configuration_udpate_response (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_change_state_event_request (UINT8    *pucMsg, UINT32    ulMsgLen);
extern UINT32 ac_cw_ac_recv_ac_owncfg_update (UINT8    *pucMsg, UINT32    ulMsgLen);
extern UINT32 ac_cw_ac_recv_ac_ip_update(UINT8    *pucMsg, UINT32    ulMsgLen);
extern UINT32	ac_cw_ac_recv_wtpasso_update(UINT8    *pucMsg, UINT32    ulMsgLen);

extern VOID ac_cw_ac_recv_cm_cfg_update_req (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_usrm_macflowctr_update_req (UINT8    *pucMsg, UINT32    ulMsgLen);

extern VOID ac_cw_ac_recv_acreset_ind(UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_apcfg_refresh(UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_cfg_status(UINT8 *pucMsg, UINT32 ulMsgLen);
extern VOID ac_cw_ac_recv_cfg_udpate_response (UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_wtp_event_request (UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_ac_recv_apip_chg_ind(UINT8 *pucMsg, UINT32 ulMsgLen);

extern VOID ac_cw_ac_timeout_wait_join_request(UINT8 *pucMsg, UINT32 ulMsgLen);
extern VOID ac_cw_ac_timeout_wait_echo_request(UINT8 *pucMsg, UINT32 ulMsgLen);
extern VOID ac_cw_ac_timeout_wait_cfg_update_response(UINT8 *pucMsg, UINT32 ulMsgLen);
extern VOID  ac_cw_ac_timeout_delay_set_apfault(UINT8 *pucMsg, UINT32 ulMsgLen);

extern UINT32 ac_cw_send_discovery_response (	AC_CW_WTPINFO_T *pstWtp, 
														CHAR *pcWtpSwVer, 
														UINT32 ulPrimary, 
														UINT32 ulAssociateDegree, 
														UINT32 ulAssociatePrio);
extern UINT32 ac_cw_send_join_response (AC_CW_WTPINFO_T *pstWtp);
extern UINT32 ac_cw_send_cfg_status_response (AC_CW_WTPINFO_T *pstWtp);
extern UINT32 ac_cw_send_echo_response (AC_CW_WTPINFO_T *pstWtp, CHAR *pcWtpSwVer);
extern UINT32 ac_cw_send_cfg_update_request (AC_CW_WTPINFO_T *pstWtp);
extern UINT32 ac_cw_send_change_state_event_response(AC_CW_WTPINFO_T *pstWtp, AC_CW_AC_DYN_SYN_T *pstDynSyn);
extern VOID ac_cw_ac_check_cfg_update_state (VOID);
extern UINT32 ac_cw_ac_nat_resolve(CHAR *pcMsg, UINT32 ulMsgLen, UINT32 ulSrcIp, UINT16 wSrcPort);	/* 2012-2-9,duankaiyuan add, 企业WLAN*/
#endif /* _AC_CW_AC_H */
/******************************* 头文件结束 **********************************/
