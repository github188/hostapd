/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: WTP CAPWAP头文件
* 修改历史: 
* 2008-5-9     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_WTP_H
#define  _AC_CW_WTP_H


/* 上电消息 */
#define AC_CW_WTP_POWER_ON    EV_MASTER_POWERON

/* 定时器ID */
#define AC_CW_TIMERID_SEND_DISCOVERY_REQUEST               		 	TIMER0
#define AC_CW_TIMERID_WAITING_FIRST_DISCOVERY_RESPONSE    		TIMER1
#define AC_CW_TIMERID_WAITING_OTHER_DISCOVERY_RESPONSE    		TIMER2
#define AC_CW_TIMERID_WAITING_JOIN_RESPONSE                    			TIMER3
#define AC_CW_TIMERID_ECHO                                    					TIMER4
#define AC_CW_TIMERID_SULKING                                    				TIMER5
#define AC_CW_TIMERID_WAITING_COM                            				TIMER6    	/* 等待通信模块初始化完成定时器*/
#define AC_CW_TIMERID_PRIMARY_DISCOVERY							TIMER7		/* 发送primary discovery request消息定时器*/
#define AC_CW_TIMERID_WTP_EVENT									TIMER8		/* WTP上报性能统计数据定时器 */
#define AC_CW_TIMERID_WAIT_MS_CFG_RSP							TIMER9		/* 等待主从线程配置响应定时器*/
#define AC_CW_TIMERID_CHANGE_STATE_EVENT						TIMER10		/* 周期性检查动态数据状态定时器*/
#define AC_CW_TIMERID_SEND_BSSID									TIMER11


/* 定时器消息*/
#define AC_CW_TIMEOUT_SEND_DISCOVERY_REQUEST                			EV_TIMER0    /*  WTP发送discovery request定时器超时 消息*/
#define AC_CW_TIMEOUT_WAIT_FIRST_DISCOVERY_RESPONSE            	EV_TIMER1    /* WTP等待首个discovery response定时器超时消息 */
#define AC_CW_TIMEOUT_WAIT_OTHER_DISCOVERY_RESPONSE           	EV_TIMER2    /* WTP收到第一个discovery response后，设置收集其它discovery response消息的定时器
                                                                                 									收集其它discovery response定时器超时消息 */
#define AC_CW_TIMEOUT_WAIT_JOIN_RESPONSE                				EV_TIMER3    /* WTP等待join response响应定时器超时消息*/
#define AC_CW_TIMEOUT_ECHO                                					EV_TIMER4    /* ECHO 定时器超时消息 */
#define AC_CW_TIMEOUT_SULKING                           					EV_TIMER5    /* SULKING定时器消息 */
#define AC_CW_TIMEOUT_WAIT_COM                            					EV_TIMER6    /* 等待通信模块初始化完成定时器超时消息*/
#define AC_CW_TIMEOUT_PRIMARY_DISCOVERY							EV_TIMER7	
#define AC_CW_TIMEOUT_WTP_EVENT									EV_TIMER8
#define AC_CW_TIMEOUT_WAIT_MS_CFG_RSP							EV_TIMER9
#define AC_CW_TIMEOUT_CHANGE_STATE_EVENT						EV_TIMER10
#define AC_CW_TIMEOUT_SEND_BSSID									EV_TIMER11


#if 1
#define AC_CW_PRIMARY_DISCOVERY_INTERVAL			1000			/* 发送primary discovery request消息定时器间隔*/
#else
#define AC_CW_PRIMARY_DISCOVERY_INTERVAL		100				/* 发送primary discovery request消息定时器间隔*/
#endif

/* 2009-7-22 pyy: 将定时器间隔修改为2分钟*/
/* 2010-3-18 pyy: 将周期性上报动态消息间隔从1分钟修改为5分钟
				周期性发送性能统计消息间隔从2分钟修改为5分钟
*/
#define AC_CW_WTP_EVENT_INTERVAL						3000				/* 发送性能统计消息定时器间隔 */
#define AC_CW_WAIT_MS_CFG_RSP_INTERVAL				100
#define AC_CW_CHANGE_STATE_EVENT_INTERVAL			3000				/* 周期性检查动态数据状态定时器间隔*/
#define AC_CW_SEND_BSSID_INTERVAL						3000				/* 周期性获取BSSID 上报*/


/* WTP侧CAPWAP控制数据区结构体定义 */
typedef struct {
        /* omc config */
	AC_WTPID_T        stWtpId;    	/* WTP设备ID */
    	CHAR    	acWtpName[32];       	/* WTP设备名称 */
    	UINT32	ulDeviceType;		/* 设备型号*/
    	UINT8	aucDeviceId[6];		/* 设备ID: 序列号*/
    	UINT8	aucRsv0[2];			/* 填充字节*/
    	UINT32	ulIpOrigin;			/* IP地址分配方式*/
    	UINT8   	aucWtpIp[4];		/* WTP设备IP地址 */		
    	UINT8   	aucNetMask[4];		/* 掩码 */	
    	UINT8	aucDefaultGw[4];		/* 缺省网关*/
	UINT8	aucPrimaryDns[4];	/*	主DNS服务器	*/
	UINT8	aucSecondaryDns[4];	/*	从DNS服务器	*/
    	
    	CHAR    	acSecret[32];        	/* 接入密码*/
   	UINT32    ulMaxDiscoveryCount;       	/* 允许发送的最大discovery request消息数量 */
	UINT32    ulDiscoveryInterval;        	/* the time in seconds, that a WTP MUST wait after receiving a   Discovery Response message */
    	UINT32    ulMaxDiscoveryInterval;    	/* Discovery Request messages MUST be sent by a WTP in the Discovery state after waiting for a random delay less than   MaxDiscoveryInterval, after a WTP first comes up or is   (re)initialized.  */
    	UINT32    ulSilentInterval;            		/* silent interval，在这个定时器间隔内不处理任何CAPWAP消息 */
    	UINT32    ulEchoInterval;            		/* echo interval，echo request发送间隔 */
   	UINT32    ulResponseInterval;        		/* 等待响应定时器时长*/
    	UINT32    ulWaitComInterval;        		/* 等待通信模块初始化完成定时器时长*/
    	UINT32    ulMaxRetransmit;        		/* CAPWAP消息最大重传次数 */
    	UINT32	ulBindAcFlag;
    	UINT32	aulAcId[AC_BIND_AC_NUM_MAX];           /* 绑定的AC设备ID列表 */
    	UINT32	ulPreferredAcId;						/* 优选ACID */
    
	/* own config */
	UINT8   	ucDiscoveryType;
	UINT8	aucRsv[3];

	/* DHCP发现方式时, 绑定的AC IP列表*/
	UINT32	ulBindAcNum;
	UINT8	aucBindAcIp[8][4];

	/* DNS发现方式时, 绑定的AC URL */
	CHAR	acAcURL[64];		/* AC URL */
	UINT32	ulResAcNum;		/* DNS解析获取到的AC IP数量*/
	UINT8	aucResAcIp[8][4];	/* DNS解析后获取到的AC IP */
    
        /* state info */
    	UINT32  ulAcCount;                										/* 当前已发现的AC数 */
	AC_CW_AC_DESCRIPTOR_T astAcDescriptor[AC_CW_AC_NUM_MAX];    	/* 当前已发现的AC列表 */
	AC_CW_STATE eCurState;                  								/* 当前状态机状态 */
    	AC_CW_AC_INFO_T stAcInfo;            								/* 当前选用的AC信息 */    
	UINT32	ulAcLinkState;											/* 与AC间链路状态*/
	UINT32	ulAcConnectTime;										/* 最近一次与AC建链的时间点 */

	UINT32	ulSentDiscoveryCount;           	/* 当前已经发送的discovery request消息数量 */
    	UINT32	ulSentJoinCount;                	/* 当前已经发送的join request 消息数量 */
    	UINT32    ulUnconfirmedEchoCount;    	/* 当前未确认的echo request消息数量 */

    	UINT32    ulTimerIdSDR;    			/* send discovery request timer id */
    	UINT32    ulTimerIdWFDR;    		/* waiting first discovery response timer id */
    	UINT32    ulTimerIdWODR;    		/* waiting other discovery response timer id */
    	UINT32    ulTimerIdWJR;    		/* waiting join response timer id */
    	UINT32    ulTimerIdWER;    		/* waiting echo response timer id */
    	UINT32    ulTimerIdS;        		/* sulking timer id */


	/*     广东移动需求，chary，2011-11-3    */
	UINT32 ulAPHeartBeatAvgTimeDelay;		/* AP向该AC发送心跳的平均延迟时间，单位毫秒 */
	UINT32 ulEchoReqCnt;         	/* AP向该AC发送心跳请求总包数 */
	UINT32 ulEchoRespLossCnt;   		/* AP丢失该AC心跳响应总包数 */
	UINT32	ulEchoRespCnt;			/* AP收到该AC心跳响应总包数 */
	struct timeval stLastEchoSendTime;	/* 最后一次发送心跳请求的时间点 */



}AC_CW_WTP_CTRL_T;


/*  广东移动需求，chary，2011-11-4   */
typedef struct
{
	  UINT32 ulAPHeartBeatAvgTimeDelay;		/* AP向该AC发送心跳的平均延迟时间，单位毫秒 */
	  UINT32 ulEchoReqCn;         	/* AP向该AC发送心跳请求总包数 */
	  UINT32 ulEchoRespLossCnt;   	/* AP丢失该AC心跳响应总包数 */
} AC_CW_WTP_ECHOSTAT_T;


/* 全局变量声明 */
extern AC_CW_WTP_CTRL_T gstWtpCtrl;


extern UINT32 ac_cw_wtp_init (UINT32	ulPowerOn);
extern UINT32 ac_cw_wtp_recv_power_on (VOID);
extern UINT32 ac_cw_wtp_recv_discovery_response(UINT8    *pucMsg, UINT32    ulMsgLen, UINT32 ulPrimary);
extern VOID ac_cw_wtp_recv_join_response(UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_recv_echo_response(UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_recv_cfg_status_response(UINT8 *pucMsg, UINT32 ulMsgLen);
extern VOID ac_cw_wtp_recv_cfg_udpate_request(UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_recv_change_state_event_response (UINT8    *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_recv_acreboot_ind(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_recv_apip_ind(UINT8 *pucMsg, UINT32    ulMsgLen);

extern VOID ac_cw_wtp_timeout_send_discovery_request(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_wait_first_discovery_response(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_wait_other_discovery_response(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_wait_join_response(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_echo(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_sulking(UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_wait_com (UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_primary_discovery_request (UINT8 *pucMsg, UINT32    ulMsgLen);
extern VOID ac_cw_wtp_timeout_change_state_event (UINT8 *pucMsg, UINT32    ulMsgLen);

extern UINT32 ac_cw_send_discovery_request (UINT32 ulPrimary);
extern UINT32 ac_cw_send_join_request (VOID);
extern UINT32 ac_cw_send_echo_request (VOID);
extern UINT32 ac_cw_send_cfg_udpate_response (UINT32  ulResultCode);
extern UINT32 ac_cw_send_change_state_event_request (UINT8 *pucMsg, UINT32 ulMsgLen);
extern UINT32 ac_cw_send_wtp_event_request_vap_trafficstat (VOID);
extern UINT32 ac_cw_send_wtp_event_request_vap_wifistat (VOID);
extern UINT32 ac_cw_send_wtp_event_request_adhoc_bssid (VOID);
extern UINT32 ac_cw_send_wtp_event_request_vdev_maxpower (VOID);

extern UINT32 ac_cw_wtp_choose_ac (AC_CW_MSG_DISCOVERYRESPONSE_T *pstDsicoveryRep, 
										UINT32 ulAcId, 
										UINT8 aucIp[4],
										UINT32 ulWtpId,
										AC_CW_WTPSW_INFO_T *pstTargetSwInfo);
extern UINT32    ac_cw_wtp_whole_table_cfg(AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  *pstVendorSepcific);
extern UINT32	ac_cw_wtp_gen_agentdat(VOID);
extern VOID ac_cw_wtp_timeout_send_bssid (VOID);


#endif /* _AC_CW_WTP_H */
/******************************* 头文件结束 **********************************/

