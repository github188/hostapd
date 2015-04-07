/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��������ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_USRM_PROC_H
#define  _AC_USRM_PROC_H



/*****************************USRMģ����Ϣ�Ŷ���*****************************/

/******************************************************************************/
#define AC_USRM_TIMER_GET_FATUSER				TIMER20	     	/* �������ȡ���ں�̬��ȡ��AC�û��Ķ�ʱ�� */

#define AC_USRM_TIMEOUT_GET_FATUSER				EV_TIMER20

#define AC_USRM_TIMER_GET_FATUSER_LEN			100		/* ��λ100ms */
/******************************************************************************/



/******************************************************************************/
extern UINT32	ac_usrm_proc_init(VOID);
extern UINT32	ac_usrm_force_useroffline(UINT8 *pucMsg);
extern VOID ac_usrm_get_fatuser(VOID);
extern UINT32	ac_usrm_rcv_vlan_cfgupdate(UINT32 ulMsgLen, VOID *pvMsg);

extern VOID ac_usrm_get_usertraffic(UINT32 ulStartRec);
extern VOID ac_usrm_check_usertraffic(UINT32 ulStartRec);
extern VOID ac_usrm_check_sessiontimeout(UINT32 ulStartRec);
extern VOID ac_usrm_check_macuser (UINT32 ulStartRec);

extern UINT32    ac_usrm_if_reg (UINT32    ulMsgId, DBIF pfFunc);
extern UINT32	ac_usrm_bk_init(VOID);
extern VOID ac_usrm_bk_run(VOID);
extern VOID ac_usrm_bk_destroy(VOID);
extern VOID ac_usrm_set_userTraffic(UINT8* pucMsg);
/* add by gwx 2012-11-3 for�û�������׼ȷ*/
extern VOID ac_usrm_starttrafficsendtimerout(UINT8* pucMsg);
extern VOID ac_usrm_stoptrafficsendtimerout(UINT8* pucMsg);
extern VOID ac_usrm_ap_rpt_starttraffic(UINT8* pucMsg);
extern VOID ac_usrm_ap_rpt_stoptraffic(UINT8* pucMsg);
/* add by gwx 2013-1-11 for AP/VAP ����*/
extern VOID ac_usrm_ap_rpt_adduserflowctrl(UINT8* pucMsg);
extern VOID ac_usrm_ap_rpt_deluserflowctrl(UINT8* pucMsg);

/* add by gwx 2013-5-13 for bug2423 */
VOID ac_usrm_set_useripfromdhcp(UINT8 *pucMsg);

/* add by gwx 2014-5-13 for ��ݣ�AP�ϱ��û���Ϣ*/
VOID ac_usrm_set_userpartinfofromap(UINT8* pucMsg);
#endif /* _AC_USRM_PROC_H */
/******************************* ͷ�ļ����� **********************************/

