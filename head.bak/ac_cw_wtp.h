/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: WTP CAPWAPͷ�ļ�
* �޸���ʷ: 
* 2008-5-9     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_CW_WTP_H
#define  _AC_CW_WTP_H


/* �ϵ���Ϣ */
#define AC_CW_WTP_POWER_ON    EV_MASTER_POWERON

/* ��ʱ��ID */
#define AC_CW_TIMERID_SEND_DISCOVERY_REQUEST               		 	TIMER0
#define AC_CW_TIMERID_WAITING_FIRST_DISCOVERY_RESPONSE    		TIMER1
#define AC_CW_TIMERID_WAITING_OTHER_DISCOVERY_RESPONSE    		TIMER2
#define AC_CW_TIMERID_WAITING_JOIN_RESPONSE                    			TIMER3
#define AC_CW_TIMERID_ECHO                                    					TIMER4
#define AC_CW_TIMERID_SULKING                                    				TIMER5
#define AC_CW_TIMERID_WAITING_COM                            				TIMER6    	/* �ȴ�ͨ��ģ���ʼ����ɶ�ʱ��*/
#define AC_CW_TIMERID_PRIMARY_DISCOVERY							TIMER7		/* ����primary discovery request��Ϣ��ʱ��*/
#define AC_CW_TIMERID_WTP_EVENT									TIMER8		/* WTP�ϱ�����ͳ�����ݶ�ʱ�� */
#define AC_CW_TIMERID_WAIT_MS_CFG_RSP							TIMER9		/* �ȴ������߳�������Ӧ��ʱ��*/
#define AC_CW_TIMERID_CHANGE_STATE_EVENT						TIMER10		/* �����Լ�鶯̬����״̬��ʱ��*/
#define AC_CW_TIMERID_SEND_BSSID									TIMER11


/* ��ʱ����Ϣ*/
#define AC_CW_TIMEOUT_SEND_DISCOVERY_REQUEST                			EV_TIMER0    /*  WTP����discovery request��ʱ����ʱ ��Ϣ*/
#define AC_CW_TIMEOUT_WAIT_FIRST_DISCOVERY_RESPONSE            	EV_TIMER1    /* WTP�ȴ��׸�discovery response��ʱ����ʱ��Ϣ */
#define AC_CW_TIMEOUT_WAIT_OTHER_DISCOVERY_RESPONSE           	EV_TIMER2    /* WTP�յ���һ��discovery response�������ռ�����discovery response��Ϣ�Ķ�ʱ��
                                                                                 									�ռ�����discovery response��ʱ����ʱ��Ϣ */
#define AC_CW_TIMEOUT_WAIT_JOIN_RESPONSE                				EV_TIMER3    /* WTP�ȴ�join response��Ӧ��ʱ����ʱ��Ϣ*/
#define AC_CW_TIMEOUT_ECHO                                					EV_TIMER4    /* ECHO ��ʱ����ʱ��Ϣ */
#define AC_CW_TIMEOUT_SULKING                           					EV_TIMER5    /* SULKING��ʱ����Ϣ */
#define AC_CW_TIMEOUT_WAIT_COM                            					EV_TIMER6    /* �ȴ�ͨ��ģ���ʼ����ɶ�ʱ����ʱ��Ϣ*/
#define AC_CW_TIMEOUT_PRIMARY_DISCOVERY							EV_TIMER7	
#define AC_CW_TIMEOUT_WTP_EVENT									EV_TIMER8
#define AC_CW_TIMEOUT_WAIT_MS_CFG_RSP							EV_TIMER9
#define AC_CW_TIMEOUT_CHANGE_STATE_EVENT						EV_TIMER10
#define AC_CW_TIMEOUT_SEND_BSSID									EV_TIMER11


#if 1
#define AC_CW_PRIMARY_DISCOVERY_INTERVAL			1000			/* ����primary discovery request��Ϣ��ʱ�����*/
#else
#define AC_CW_PRIMARY_DISCOVERY_INTERVAL		100				/* ����primary discovery request��Ϣ��ʱ�����*/
#endif

/* 2009-7-22 pyy: ����ʱ������޸�Ϊ2����*/
/* 2010-3-18 pyy: ���������ϱ���̬��Ϣ�����1�����޸�Ϊ5����
				�����Է�������ͳ����Ϣ�����2�����޸�Ϊ5����
*/
#define AC_CW_WTP_EVENT_INTERVAL						3000				/* ��������ͳ����Ϣ��ʱ����� */
#define AC_CW_WAIT_MS_CFG_RSP_INTERVAL				100
#define AC_CW_CHANGE_STATE_EVENT_INTERVAL			3000				/* �����Լ�鶯̬����״̬��ʱ�����*/
#define AC_CW_SEND_BSSID_INTERVAL						3000				/* �����Ի�ȡBSSID �ϱ�*/


/* WTP��CAPWAP�����������ṹ�嶨�� */
typedef struct {
        /* omc config */
	AC_WTPID_T        stWtpId;    	/* WTP�豸ID */
    	CHAR    	acWtpName[32];       	/* WTP�豸���� */
    	UINT32	ulDeviceType;		/* �豸�ͺ�*/
    	UINT8	aucDeviceId[6];		/* �豸ID: ���к�*/
    	UINT8	aucRsv0[2];			/* ����ֽ�*/
    	UINT32	ulIpOrigin;			/* IP��ַ���䷽ʽ*/
    	UINT8   	aucWtpIp[4];		/* WTP�豸IP��ַ */		
    	UINT8   	aucNetMask[4];		/* ���� */	
    	UINT8	aucDefaultGw[4];		/* ȱʡ����*/
	UINT8	aucPrimaryDns[4];	/*	��DNS������	*/
	UINT8	aucSecondaryDns[4];	/*	��DNS������	*/
    	
    	CHAR    	acSecret[32];        	/* ��������*/
   	UINT32    ulMaxDiscoveryCount;       	/* �����͵����discovery request��Ϣ���� */
	UINT32    ulDiscoveryInterval;        	/* the time in seconds, that a WTP MUST wait after receiving a   Discovery Response message */
    	UINT32    ulMaxDiscoveryInterval;    	/* Discovery Request messages MUST be sent by a WTP in the Discovery state after waiting for a random delay less than   MaxDiscoveryInterval, after a WTP first comes up or is   (re)initialized.  */
    	UINT32    ulSilentInterval;            		/* silent interval���������ʱ������ڲ������κ�CAPWAP��Ϣ */
    	UINT32    ulEchoInterval;            		/* echo interval��echo request���ͼ�� */
   	UINT32    ulResponseInterval;        		/* �ȴ���Ӧ��ʱ��ʱ��*/
    	UINT32    ulWaitComInterval;        		/* �ȴ�ͨ��ģ���ʼ����ɶ�ʱ��ʱ��*/
    	UINT32    ulMaxRetransmit;        		/* CAPWAP��Ϣ����ش����� */
    	UINT32	ulBindAcFlag;
    	UINT32	aulAcId[AC_BIND_AC_NUM_MAX];           /* �󶨵�AC�豸ID�б� */
    	UINT32	ulPreferredAcId;						/* ��ѡACID */
    
	/* own config */
	UINT8   	ucDiscoveryType;
	UINT8	aucRsv[3];

	/* DHCP���ַ�ʽʱ, �󶨵�AC IP�б�*/
	UINT32	ulBindAcNum;
	UINT8	aucBindAcIp[8][4];

	/* DNS���ַ�ʽʱ, �󶨵�AC URL */
	CHAR	acAcURL[64];		/* AC URL */
	UINT32	ulResAcNum;		/* DNS������ȡ����AC IP����*/
	UINT8	aucResAcIp[8][4];	/* DNS�������ȡ����AC IP */
    
        /* state info */
    	UINT32  ulAcCount;                										/* ��ǰ�ѷ��ֵ�AC�� */
	AC_CW_AC_DESCRIPTOR_T astAcDescriptor[AC_CW_AC_NUM_MAX];    	/* ��ǰ�ѷ��ֵ�AC�б� */
	AC_CW_STATE eCurState;                  								/* ��ǰ״̬��״̬ */
    	AC_CW_AC_INFO_T stAcInfo;            								/* ��ǰѡ�õ�AC��Ϣ */    
	UINT32	ulAcLinkState;											/* ��AC����·״̬*/
	UINT32	ulAcConnectTime;										/* ���һ����AC������ʱ��� */

	UINT32	ulSentDiscoveryCount;           	/* ��ǰ�Ѿ����͵�discovery request��Ϣ���� */
    	UINT32	ulSentJoinCount;                	/* ��ǰ�Ѿ����͵�join request ��Ϣ���� */
    	UINT32    ulUnconfirmedEchoCount;    	/* ��ǰδȷ�ϵ�echo request��Ϣ���� */

    	UINT32    ulTimerIdSDR;    			/* send discovery request timer id */
    	UINT32    ulTimerIdWFDR;    		/* waiting first discovery response timer id */
    	UINT32    ulTimerIdWODR;    		/* waiting other discovery response timer id */
    	UINT32    ulTimerIdWJR;    		/* waiting join response timer id */
    	UINT32    ulTimerIdWER;    		/* waiting echo response timer id */
    	UINT32    ulTimerIdS;        		/* sulking timer id */


	/*     �㶫�ƶ�����chary��2011-11-3    */
	UINT32 ulAPHeartBeatAvgTimeDelay;		/* AP���AC����������ƽ���ӳ�ʱ�䣬��λ���� */
	UINT32 ulEchoReqCnt;         	/* AP���AC�������������ܰ��� */
	UINT32 ulEchoRespLossCnt;   		/* AP��ʧ��AC������Ӧ�ܰ��� */
	UINT32	ulEchoRespCnt;			/* AP�յ���AC������Ӧ�ܰ��� */
	struct timeval stLastEchoSendTime;	/* ���һ�η������������ʱ��� */



}AC_CW_WTP_CTRL_T;


/*  �㶫�ƶ�����chary��2011-11-4   */
typedef struct
{
	  UINT32 ulAPHeartBeatAvgTimeDelay;		/* AP���AC����������ƽ���ӳ�ʱ�䣬��λ���� */
	  UINT32 ulEchoReqCn;         	/* AP���AC�������������ܰ��� */
	  UINT32 ulEchoRespLossCnt;   	/* AP��ʧ��AC������Ӧ�ܰ��� */
} AC_CW_WTP_ECHOSTAT_T;


/* ȫ�ֱ������� */
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
/******************************* ͷ�ļ����� **********************************/

