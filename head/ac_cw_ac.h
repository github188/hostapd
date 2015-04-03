/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: AC CAPWAPͷ�ļ�
* �޸���ʷ: 
* 2008-5-9     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_CW_AC_H
#define  _AC_CW_AC_H

/* �ϵ���Ϣ */
#define AC_CW_AC_POWER_ON    EV_MASTER_POWERON

/* ��ʱ��ID */
#define AC_CW_TIMERID_WAIT_JOIN_REQUEST                    	TIMER0        	/* �ȴ�WTP join request��ʱ��ID */
#define AC_CW_TIMERID_WAIT_ECHO_REQUEST                    TIMER1        	/* �ȴ�WTP echo request��ʱ��ID */
#define AC_CW_TIMERID_WAIT_CFG_UPDATE_RESPONSE		TIMER2        	/* �ȴ�WTP configuration update response ��ʱ��ID */
#define AC_CW_TIMERID_DELAY_SET_APFAULT				TIMER3		/* �ӳ�����AP���϶�ʱ��*/

/* ��ʱ����Ϣ*/
#define AC_CW_TIMEOUT_WAIT_JOIN_REQUEST        		EV_TIMER0
#define AC_CW_TIMEOUT_WAIT_ECHO_REQUEST			EV_TIMER1
#define AC_CW_TIMEOUT_WAIT_CFG_UPDATE_RESPONSE		EV_TIMER2
#define AC_CW_TIMEOUT_DELAY_SET_APFAULT				EV_TIMER3

#define AC_CW_DELAY_SET_APFAULT_INTERVAL				3000		/* �ӳ�����AP���϶�ʱ��ʱ��*/


/* AC��CAPWAP�����������ṹ�嶨��*/
typedef struct {
    	/* omc config */
    	UINT32  ulAcId;
    	UINT8   aucIp[4];
    	UINT32  ulMaxWtp;             /* �����������WTP����*/
    	UINT32  ulWaitJoinInterval;   /* �ȴ�join request��ʱ��ʱ��*/
    	UINT32  ulEchoInterval;       /* echo interval��echo request���ͼ�� */
    	UINT32  ulWaitCURInterval;    /* �ȴ�configuration update response��Ϣ���*/
    	UINT32  ulMaxRetransmit;      /* CAPWAP��Ϣ����ش����� */

    	/* ��Ҫͬ���Ĺ�ϵ����Ŀ������б�*/
    	UINT32      ulTblNum;
    	DBHANDLE    ahTblList[64];

	/* 2009-10-29 pyy ����*/
	UINT32	ulCmCfgFlag;	/* ��ʶ��ǰ�Ƿ����ڽ������ܷ������������ͬ��*/
	
    	/* ���յ�����Ӧ��Ŀ�뷢�͵�������Ŀ�ﵽ��ͬʱ����CM����������Ӧ */
    	UINT32  ulSendCURNum;                /* ���͵�Configuration update request��Ŀ */
    	UINT32  ulRecvCURNum;                /* �յ���Configuration update response��Ŀ */

    	/* state info */
    	UINT32    ulCurWtp;                /* ��ǰ�����WTP���� */    
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
extern UINT32 ac_cw_ac_nat_resolve(CHAR *pcMsg, UINT32 ulMsgLen, UINT32 ulSrcIp, UINT16 wSrcPort);	/* 2012-2-9,duankaiyuan add, ��ҵWLAN*/
#endif /* _AC_CW_AC_H */
/******************************* ͷ�ļ����� **********************************/
