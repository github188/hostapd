/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ���ݿ�ͳһ�ӿڹ���ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_USRM_PUBLIC_H
#define  _AC_USRM_PUBLIC_H

/******************************************************************************/
/*****************************USRMģ����Ϣ�Ŷ���*****************************/
/* ��Ϣ�Ŷ��忪ʼ*/

#define AC_USRM_IF_MAX    100        /* USRMģ�����ӿ���*/

/* ��׼�ӿ���Ϣ��*/
#define AC_USRM_ADD_USER_MSG					(EV_USRM_BEGIN+1)    /* �û����� */
#define AC_USRM_DEL_USER_MSG            			(EV_USRM_BEGIN+2)   	/* �û�ɾ��*/
#define AC_USRM_UPDATE_USER_SUBINFO_MSG 	(EV_USRM_BEGIN+3)   	/* �����û�ǩԼ��Ϣ��hostapd��radius server��ȡ�û�ǩԼ��Ϣ����ñ��ӿ�*/
#define AC_USRM_UPDATE_USER_POS_MSG     		(EV_USRM_BEGIN+4)   	/* �����û�λ����Ϣ */
#define AC_USRM_GET_ALLUSER_MSG				(EV_USRM_BEGIN+5)   	/* ��ȡ��ǰ���������û��б�*/
#define AC_USRM_GET_USERQOS_MSG				(EV_USRM_BEGIN+6)	/* �����û���ǰ�����VAP��ʶ��ȡ�û�QOS */

#define AC_USRM_GET_USERPORTALSWITCH_MSG	(EV_USRM_BEGIN+7)	/* �����û�MAC��ַ�͵�ǰ����Ķ˿��ж��û��Ƿ���ҪPortal��֤ */
#define AC_USRM_SET_USERPORTALSTATE_MSG		(EV_USRM_BEGIN+8)	/* �����û�MAC��ַ�����û���Portal��֤״̬ */
#define AC_USRM_GET_USERPORTALSTATE_MSG		(EV_USRM_BEGIN+9)	/* �����û�MAC��ַ��ȡ�û���Portal��֤״̬ */
#define AC_USRM_ADD_IDSUSER_MSG				(EV_USRM_BEGIN+10)	/* ���û�����ΪIDS�����û�*/
#define AC_USRM_SET_PPPOESTATE_MSG			(EV_USRM_BEGIN+11)	/* ����PPPoE��֤״̬*/
#define AC_USRM_SET_USERIP_MSG				(EV_USRM_BEGIN+12)	/* �����û�IP��ַ*/
#define AC_USRM_GET_USERINFO_MSG				(EV_USRM_BEGIN+13)	/* �����û�MAC��ȡ�û���Ϣ*/
#define AC_USRM_GET_USERINFOBYIP_MSG			(EV_USRM_BEGIN+14)	/* �����û�IP��ȡ�û���Ϣ*/
#define AC_USRM_GET_USERVLAN_MSG				(EV_USRM_BEGIN+15)	/* �����û�MAC��ȡ�û�����VLAN */
#define AC_USRM_GET_USERNASINFOBYMAC_MSG	(EV_USRM_BEGIN+16)	/* �����û�MAC��ȡ�û�������NAS ��Ϣ*/
#define AC_USRM_GET_USERNASINFOBYIP_MSG		(EV_USRM_BEGIN+17)	/* �����û�IP��ȡ�û�������NAS ��Ϣ*/
#define AC_USRM_GET_NASINFO_MSG				(EV_USRM_BEGIN+18)	/* ����VAP ID��MAC��ַ��ȡ�û�������NAS��Ϣ */
#define AC_USRM_GET_USERPORTAL_CONFIG_MSG	(EV_USRM_BEGIN+19)	/* �����û���ַ��ȡ�û���֤����*/
#define AC_USRM_GET_ALLIDSUSER_MSG			(EV_USRM_BEGIN+20)	/* ��ȡ����IDS�����û��б�*/
#define AC_USRM_GET_USERCERTSTATE_MSG		(EV_USRM_BEGIN+21)	/* ��ȡ�û���֤״̬*/
#define AC_USRM_GET_NASIP_MSG					(EV_USRM_BEGIN+22)	/* ��ȡNAS-IP�ӿ�*/
#define AC_USRM_SET_USERIPFROMDHCP_MSG		(EV_USRM_BEGIN+23)	/*add by gwx for bug2423,  DHCPģ������û�IP��Ϣ*/

#define AC_USRM_GET_APSTAASSONUM_MSG		(EV_USRM_BEGIN+30)	/* ��ȡ��ǰʱ����AP�������ն���*/
#define AC_USRM_GET_APSTAONLINENUM_MSG		(EV_USRM_BEGIN+31)	/* ��ȡ��ǰʱ�����ߵ��ն���: WEB��֤ͨ�����ն���*/
#define AC_USRM_GET_ALLAPSTANUM_MSG			(EV_USRM_BEGIN+32)	/* ��ȡ����AP��ǰʱ�̹������ն���
																		����AP��ǰʱ�����ߵ��ն���: WEB��֤ͨ�����ն���*/
#define AC_USRM_GET_ALLSSIDSTANUM_MSG		(EV_USRM_BEGIN+33)	/* ��ȡ����SSID��ǰʱ�̹������ն���
																		����SSID��ǰʱ�����ߵ��ն���: WEB��֤ͨ�����ն���*/
#define AC_USRM_GET_PORTALONLINEUSER_MSG			(EV_USRM_BEGIN+34)	/* ��ȡWEB��֤ͨ�����û���*/	
#if 0
#define AC_USRM_INC_WEBUSERABNORMALOFFLINE_MSG	(EV_USRM_BEGIN+35)	/* WEB��֤�û��쳣���ߴ�������*/
#define AC_USRM_INC_WEBAUTHREQ_MSG					(EV_USRM_BEGIN+36)	/* WEB��֤�����������*/
#define AC_USRM_INC_WEBAUTHSUCCREQ_MSG				(EV_USRM_BEGIN+37)	/* WEB��֤�ɹ���������*/
#endif
/* 2011-3-7 pyy add: ��ȡ���û������Ϣ*/
#define AC_USRM_GET_WIREUSERQOS_MSG				(EV_USRM_BEGIN+38)
#define AC_USRM_GET_WIRENASINFO_MSG					(EV_USRM_BEGIN+39)

#define AC_USRM_FORCE_USEROFFLINE_REQ_MSG	(EV_USRM_BEGIN+51)	/* OMCǿ���û���������*/
#define AC_USRM_FORCE_USEROFFLINE_RSP_MSG	(EV_USRM_BEGIN+52)	/* OMCǿ���û�������Ӧ*/

/* 2010-3-4����: ǿ��PPPOE��֤�û����� */
#define AC_USRM_PPPOE_USEROFFLINE_REQ_MSG	(EV_USRM_BEGIN+53)		/* ǿ��PPPOE��֤�û���������*/
#define AC_USRM_PPPOE_USEROFFLINE_RSP_MSG	(EV_USRM_BEGIN+54)		/* ǿ��PPPOE��֤�û�������Ӧ*/

/* 2011-8-9 pyy add: MAC��֤����*/
#define AC_USRM_SET_USERAGENT_MSG			(EV_USRM_BEGIN+55)		/* ����User-Agent����*/
#define AC_USRM_GET_USERAGENT_MSG			(EV_USRM_BEGIN+56)		/* ��ȡUser-Agent����*/
#define AC_USRM_SET_MACAUTHRES_MSG			(EV_USRM_BEGIN+57)		/* ����MAC��֤���*/

#define AC_USRM_GET_USERMACSERVER_CONFIG_MSG	(EV_USRM_BEGIN+58)   	/* �����û���ַ��ȡ�û�MAC��֤����*/
/* add by gwx 2011-11-1 for �㶫�ƶ�*/
#define AC_USRM_INC_AUTHSTAT_MSG				(EV_USRM_BEGIN+59) 			/* ����AP����֤ͳ��*/
#define AC_USRM_GET_ACAUTHSTAT_MSG			(EV_USRM_BEGIN+60) 		/* ��ȡAC����֤ͳ��*/
#define AC_USRM_EAPUSEROFFLINE_REQ_MSG		(EV_USRM_BEGIN+61) 		/* ������֤�û�����������֪ͨHostapd*/

/* add by gwx 2021-10-31 for �û�������׼ȷ*/
#define AC_USRM_SET_USERTRAFFIC_MSG		(EV_USRM_BEGIN+62) 		/* AP�����û������ӿ� */
#define AC_USRM_ILLEGALUSER_MSG			(EV_USRM_BEGIN+63)		/* AC֪ͨ AP����Ƿ��û� */
#define AC_USRM_GET_USERTRAFFIC_BYMAC_MSG		(EV_USRM_BEGIN+64)		/* ��ȡ�����û�������*/
#define AC_USRM_USER_STARTTRAFFIC_MSG	(EV_USRM_BEGIN+66)		/* ֪ͨAP��ʼ���û�����ͳ��*/
#define AC_USRM_USER_STOPTRAFFIC_MSG	(EV_USRM_BEGIN+67)		/* ֪ͨAPֹͣ���û�����ͳ��*/
#define AC_USRM_USER_STARTTRAFFIC_AP_RPT_MSG	(EV_USRM_BEGIN+68)		/* AP���ؿ�ʼ�û�����ͳ�ƵĲ������*/
#define AC_USRM_USER_STOPTRAFFIC_AP_RPT_MSG	(EV_USRM_BEGIN+69)		/* AP����ֹͣ�û�����ͳ�ƵĲ������*/
/* add by gwx 2013-1-23 for bug1718 */
#define AC_USRM_GET_USERPORTAL_CONFIG_BYSSID_MSG (EV_USRM_BEGIN+70)  	/* ����SSID��ȡportal����*/
/* add by gwx 2014-5-13 for ���,AP�ϱ��û���Ϣ*/
#define AC_USRM_SET_USERPARTINFOFROMAP_MSG		(EV_USRM_BEGIN+71)
/* add by gwx 2013-6-26 for SSID�û��������*/
#define AC_USRM_GET_USERACCESSPERMIT_MSG	(EV_USRM_BEGIN+72)		/* �����û�MAC�ͽ����SSID��ȡ�û��û��Ƿ��������*/ 

/* ������Ϣ��*/
#define AC_USRM_USER_ADD_IND_MSG				(EV_USRM_BEGIN+101)		/* �û�����֪ͨ*/
#define AC_USRM_USER_DEL_IND_MSG				(EV_USRM_BEGIN+102)		/* �û��뿪֪ͨ*/
#define AC_USRM_USERPORTAL_DEL_IND_MSG		(EV_USRM_BEGIN+103)		/* �û�Portal��֤������ɾ��֪ͨ*/
#define AC_USRM_USER_HANDOVER_IND_MSG		(EV_USRM_BEGIN+104)		/* �û��Ʒ���Ϣ���֪ͨ*/
#define AC_USRM_USER_TS_START_IND_MSG		(EV_USRM_BEGIN+105)		/* ֪ͨ����ͳ��ģ�鿪ʼ�û�����ͳ��*/
#define AC_USRM_USER_TS_END_IND_MSG			(EV_USRM_BEGIN+106)		/* ֪ͨ����ͳ��ģ�鿪ʼֹͣ����ͳ��*/
#define AC_USRM_USER_CERTSTATE_CHANGE_IND_MSG	(EV_USRM_BEGIN+107)	/* �û���֤״̬�仯֪ͨ*/
#define AC_USRM_USER_QOS_CHANGE_IND_MSG		(EV_USRM_BEGIN+108)	/* �û�QOS��Ϣ�仯֪ͨ*/
#define AC_USRM_USER_SESSIONTIMEOUT_IND_MSG		(EV_USRM_BEGIN+109)	/* �û�SESSION TIMEOUT֪ͨ*/
#define AC_USRM_IDSUSER_ADD_IND_MSG				(EV_USRM_BEGIN+110)	/* IDS�����û�����֪ͨ*/
#define AC_USRM_IDSUSER_DEL_IND_MSG				(EV_USRM_BEGIN+111)	/* IDS�����û�ɾ��֪ͨ*/
#define AC_USRM_NASIP_UPDATE_IND_MSG				(EV_USRM_BEGIN+112)	/* NAS-IP �����Ϣ*/
#define AC_USRM_MACAUTH_REQ_MSG					(EV_USRM_BEGIN+113)	/* ����Portalģ����û�����MAC��֤*/

#define AC_USRM_TOACCOUNT_PROCWORK_MSG		(EV_USRM_BEGIN+114) /*USRMģ����������account ���ϵ�֪ͨ*/
#define AC_USRM_USERIP_REQ_MSG				(EV_USRM_BEGIN+115)/* add by gwx 2012-6-4 for bug1100 ����û��ɹ���������DHCP�õ�ַ*/
#define AC_USRM_ADD_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+120)		/* ֪ͨAP����û�������Ϣ*/
#define AC_USRM_ADD_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+121)		/* AP �յ�����û�������Ϣ��ķ�����Ϣ*/

#define AC_USRM_DEL_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+122)		/* ֪ͨɾ���û�������Ϣ*/
#define AC_USRM_DEL_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+123)		/* AP �յ�ɾ���û�������Ϣ��ķ�����Ϣ*/

#define AC_USRM_UPDATE_ALL_USER_FLOWCTRL_REQ_MSG  (EV_USRM_BEGIN+124)		/* ֪ͨAP���������û�������Ϣ��Ϣ*/
#define AC_USRM_UPDATE_ALL_USER_FLOWCTRL_RSP_MSG  (EV_USRM_BEGIN+125)		/* AP�յ����������û�������Ϣ�󷵻���Ϣ*/
/* ��Ϣ�Ŷ������*/

/* ȡֵ�궨�忪ʼ*/
// 	��������ṹ��
#define 	AC_PORTAL_SWITCH_DISABLE		0	/* ����ǿ��WEB��֤ */
#define	AC_PORTAL_SWITCH_ENABLE		1	/* ����ǿ��WEB��֤*/

#define 	AC_CERT_STATE_NOTFINISH		0	/* WEB/PPP δ��֤*/
#define	AC_CERT_STATE_FINISH			1	/* WEB/PPP ����֤ */


#define 	AC_PORTAL_STATE_NOTFINISH	0	/* WEB δ��֤*/
#define	AC_PORTAL_STATE_FINISH		1	/* WEB ����֤ */

/*ҵ�� ��֤����ȡֵ�궨��*/
#define	AC_CERT_TYPE_FREE				0	/* ����֤*/
#define	AC_CERT_TYPE_PORTAL			1	/* WEB��֤*/
#define	AC_CERT_TYPE_PPPOE			2	/* PPP��֤*/
#define 	AC_CERT_TYPE_MAC				3	/* 2011-8-9 pyy add: MAC��֤*/
#define 	AC_CERT_TYPE_WPA                	 	4   	/* ������֤add by gwx 2011-11-1 for �㶫�ƶ� */

#define 	AC_USRM_WTP_ALLVAP	1024	/* add by gwx 2012-5-31 for bug1089*/

/* add by gwx 2012-6-4 for bug1100 ����setuserIp��ģ������*/
#define     AC_USERIPREQ_TYPE_DHCPCLEAR		2
#define     AC_USERIPREQ_TYPE_DHCP				1
#define     AC_USERIPREQ_TYPE_L2W    			0
#define	  AC_USERIPREQ_TYPE_HRD				3

/* add by gwx 2011-11-1 for �㶫�ƶ���ͳ�����ͺ궨�� */
#define AC_USRM_AUTHSTATTYPE_AUTHREQ		1	/* ��֤�������*/
#define AC_USRM_AUTHSTATTYPE_AUTHSUCC		2	/* ��֤�ɹ�����*/
#define AC_USRM_AUTHSTATTYPE_AUTHFAIL		3	/* ��֤ʧ�ܴ���*/
#define AC_USRM_AUTHSTATTYPE_ABNORMALOFFLINE	4	/* �쳣���ߴ���*/

/* add by gwx 2012-11-1 for �û�������׼ȷ*/
#define 	AC_SEND_USERTRAFFIC_TIMES		3	/* ֪ͨAP��ʼ/ֹͣͳ���û�������Ϣ�ط�����*/
#define	AC_WTP_MAX_USERNUM		128
/* add by gwx 2013-1-9 for task341 */
#define AC_USRM_NASID_MAXLEN		16		/* nasid�ĺϷ���󳤶�*/

/* add by gwx 2014-6-26 for SSID���û��������*/
#define	AC_USRM_ALLOW_USERACCESS		0
#define	AC_USRM_NOT_ALLOW_USERACCESS	1

#define	AC_USRM_WHITELIST_MODE		0
#define	AC_USRM_BLACKLIST_MODE		1

#define 	AC_USRM_USERACCESS_OUI_ON	1
#define 	AC_USRM_USERACCESS_OUI_OFF	0

/* ȡֵ�궨�����*/
/******************************************************************************/

/******************************************************************************/
/* �ӿڽṹ�嶨�忪ʼ*/
/* �û�QOS���Խṹ�嶨�� */
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
} AC_USRM_MAC_T;

typedef struct
{
	UINT32	ulPriority;			/* �û����ȼ� */
	UINT32	ulUpBandMax;		/* �û�������д��� */
	UINT32	ulUpBandMin;		/* �û���֤���д��� */
	UINT32	ulDownBandMax;		/* �û�������д��� */
	UINT32	ulDownBandMin;		/* �û���֤���д��� */
} AC_USR_QOS_T;

/* �û��Ʒ���Ϣ�ṹ�嶨��*/
typedef struct
{
	CHAR	acUserName[256];	/* �û��� */
	UINT8	aucVapMac[6];		/* VAP BSSID */
	UINT8	aucRsv[2];			/* ����ֽ� */
	CHAR	acVapSsid[32];		/* VAP SSID */
	
	UINT8	aucNasIp[4];				/* NAS IP����AC��Ʒѷ�����ͨ�ŵĵ�ַ */
	CHAR	acNasId[256];			/* NAS ID�������û���ǰ�����VLAN��ȡ���ȵ�ID */
	UINT32	ulAcctInterimInterval;    	/* �Ʒ���Ϣ�ϱ���������AAA������ָ���Ʒ��ϱ�����������AAAָ��ֵ��������PORTAL/PPPOE���ø�ֵ�����δ���ã������ACȫ������ֵ */
	UINT32  	ulSessionTimeout;       /* �Ự��ʱʱ�� , ��λ:��*/
	UINT32	ulAssocId ;        /*�û���֤��WEP/PPPOE���ɹ������û�����ģ��֪ͨ�Ʒѽ��̸��ֶΣ���ֵ�����������ݽṹ�д��ݹ���*/
	UINT32	ulAcctTermCause;		/* 2010-7-14 ����: �û�����ԭ��*/
} AC_USR_ACCT_T;

typedef struct
{
	UINT8   aucMac[6];
  	UINT8   aucRsv[2];
 	UINT8   aucIp[4];
 	UINT32	ulUserType;
	UINT32	ulVlanId;
	
	AC_USR_QOS_T  	stQos;      	/* �û�QOS */
	AC_VAPID_T        	stVapId;    	/* �û���ǰ�����VAP��ʶ */   
	AC_USR_ACCT_T	stAcctInfo;	/* �û��Ʒ������Ϣ*/

	UINT32	ulCertType;
	UINT32	ulCertState;
	UINT32	ulEthId;
} AC_USRM_USER_INFO_T;

#define AC_USER_TYPE_WIRELESS	0	/* �����û�*/
#define AC_USER_TYPE_WIRE		1	/* �����û�*/

//	�û�����
typedef struct
{
	UINT32	ulType;	/* �û�����*/
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT8	aucIp[4];
	AC_VAPID_T	stVapId;
	UINT32	ulIfId;		/* ���߽ӿں�*/
	UINT32	ulAssocId;	/*�û��������HOSTAPD/WAPIAPD֪ͨ�û�����ģ����ֶ�ֵ*/
	UINT32	ulVlanId;	/* 2010-3-4 ����: �����û�VLAN ID */
} AC_USRM_ADD_USER_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_USRM_ADD_USER_RSP_T;

 #define AC_USRM_ACCTTERMCAUSE_USERREQUEST		1	/* �û��������ߣ�User Request */
 #define AC_USRM_ACCTTERMCAUSE_IDLETIMEOUT		4	/* ���г�ʱ��Idle Timeout�� */
 #define AC_USRM_ACCTTERMCAUSE_SESSIONTIMEOUT	5	/* �Ự��ʱ��Session Timeout��*/
 #define AC_USRM_ACCTTERMCAUSE_ADMINRESET		6	/* DM���ߣ�Admin Reset��*/
 /* add by gwx 2012-3-10 */
 #define AC_USRM_WPAOFFTYPE_USERREQUEST			0	/* �û���������(Ĭ��)*/
 #define AC_USRM_WPAOFFTYPE_IDLETIMEOUT			1	/* ����������*/
 #define AC_USRM_WPAOFFTYPE_ADMINRESET			2	/* ǿ������*/
 
//	�û�ɾ��
typedef struct
{	
	UINT32	ulType;	/* �û�����*/
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	AC_VAPID_T	stVapId;
	UINT32	ulIfId;	/* ���߽ӿں�*/
	UINT32	ulAcctTermCause;		/* 2010-7-14 ����: �û�����ԭ��*/
} AC_USRM_DEL_USER_REQ_T;
typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_USRM_DEL_USER_RSP_T;

//�û�ǩԼ��Ϣ����
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	CHAR	acUserName[256];

	UINT8	aucNasIp[4];		/* NAS IP */
	CHAR	acNasId[256];	/* NAS ID */
	UINT32	ulAcctInterimInterval;	/* �Ʒ���Ϣ�ϱ���� */
	UINT32  	ulSessionTimeout;       	/* �Ự��ʱʱ�� */
	UINT32      ulIdleTimeout;             /*add by gwx 2012-6-4 for bug1101 AAA�·��û�����������ʱ��*/
	CHAR	acUserGroupName[128];	 /*add by gwx 2012-10-14 for task1076 radius�������û��������*/
	/* �û���QOS��Ϣ������չ */
	AC_USR_QOS_T	stQos;	/* �û�QOS */
} AC_USRM_UPDATE_USER_SUBINFO_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_USRM_UPDATE_USER_SUBINFO_RSP_T;

/*�����û�λ����Ϣ����νṹ�嶨��*/
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

/* ��ȡ��ǰ���������û��б�*/
typedef struct {
	UINT32        ulStartRec;     /* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_USRM_GET_ALLUSER_REQ_T;

typedef struct {
	UINT32 ulRet;
	UINT32  ulFinish;   /* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
                          	AC_DB_TABLE_READ_NOTFINISH  δ����
					AC_DB_TABLE_READ_FINISH        ��ȡ���� */
	UINT32  ulNum;      /* ���ε��÷��ص������� */
	AC_USRM_USER_INFO_T       astUser[4];
} AC_USRM_GET_ALLUSER_RSP_T;

/* �����û���ǰ�����VAP��ʶ��ȡ�û�QOS */
typedef struct
{
	AC_VAPID_T	stVapId;
	UINT8    aucMac[6];
	UINT8    aucRsv[2];
}AC_USRM_GET_USERQOS_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_USR_QOS_T	stQos;		/* �û�QOS */
} AC_USRM_GET_USERQOS_RSP_T;


/* 2011-3-7 pyy add: ��ȡ���û���qos��Ϣ*/
typedef struct
{
	UINT32	ulVlanId;
	UINT8    aucMac[6];
	UINT8    aucRsv[2];
}AC_USRM_GET_WIREUSERQOS_REQ_T;

typedef AC_USRM_GET_USERQOS_RSP_T  AC_USRM_GET_WIREUSERQOS_RSP_T;

// 	���������������û�MAC��ַ�͵�ǰ����Ķ˿��ж��û��Ƿ���ҪPortal��֤
// 	��������ṹ��
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
	AC_VAPID_T	stVapId;	/* �û���ǰ�����VAP ID */
} AC_USRM_GET_USERPORTALSWITCH_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulPortalSwitch;	/* �Ƿ���Ҫǿ��Portal */
} AC_USRM_GET_USERPORTALSWITCH_RSP_T;

// 	���������������û�MAC��ַ�����û���Portal��֤״̬
// 	��������ṹ��

typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
	UINT32	ulCertType;	/* ��֤����*/
	UINT32	ulPortalState;
	UINT32	ulFlag;		/* 1: ��ʶΪOMC�����ǿ���û�����*/
	UINT32	ulAcctTermCause;
} AC_USRM_SET_USERPORTALSTATE_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_USRM_SET_USERPORTALSTATE_RSP_T;

// 	���������������û�MAC��ַ��ȡ�û���Portal��֤״̬
// 	��������ṹ��
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
} AC_USRM_GET_USERPORTALSTATE_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulPortalState;
} AC_USRM_GET_USERPORTALSTATE_RSP_T;

//���û�����ΪIDS�����û�
// 	��������ṹ��
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
	UINT32	ulReason;
} AC_USRM_ADD_IDSUSER_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_USRM_ADD_IDSUSER_RSP_T;

/* �����û�PPPoE��֤״̬*/
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
	UINT32	ulState;		/* 0��δ��֤1������֤*/
} AC_USRM_SET_USERPPPOESTATE_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_USRM_SET_USERPPPOESTATE_RSP_T;

/* �����û�IP��ַ */
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

// 	���������������û�MAC��ַ��ȡ�û���Ϣ
// 	��������ṹ��
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
} AC_USRM_GET_USERINFO_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_USRM_USER_INFO_T		stUserInfo;
} AC_USRM_GET_USERINFO_RSP_T;

/* �����û�IP��ַ��ȡ�û���Ϣ*/
typedef struct 
{
	UINT8	aucIp[4];	/* �û�IP��ַ*/
} AC_USRM_GET_USERINFOBYIP_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_USRM_USER_INFO_T		stUserInfo;
} AC_USRM_GET_USERINFOBYIP_RSP_T;

/* �����û�MAC��ȡ�û�����VLAN��Ϣ*/
typedef struct 
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
} AC_USRM_GET_USERVLAN_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulVlanId;
	UINT8	aucMac[6];	/* �û�MAC��ַ *//*2014.1.26 add by fangz*/
} AC_USRM_GET_USERVLAN_RSP_T;


/* �����û�MAC��ȡ�û�������NAS��Ϣ*/
typedef struct 
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
}AC_USRM_GET_USERNASINFOBYMAC_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP����AC��Ʒѷ�����ͨ�ŵĵ�ַ */
	CHAR	acNasId[256];	/* NAS ID�������û���ǰ�����VLAN��ȡ���ȵ�ID */
}AC_USRM_GET_USERNASINFOBYMAC_RSP_T;

/* �����û�IP��ȡ�û�������NAS��Ϣ*/
typedef struct 
{
	UINT8	aucIp[4];	/* �û�IP��ַ */
}AC_USRM_GET_USERNASINFOBYIP_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP����AC��Ʒѷ�����ͨ�ŵĵ�ַ */
	CHAR	acNasId[256];	/* NAS ID�������û���ǰ�����VLAN��ȡ���ȵ�ID */
}AC_USRM_GET_USERNASINFOBYIP_RSP_T;

/* ����VAP ID���û�MAC��ַ��ȡ�û���NAS��Ϣ*/
typedef struct
{
	AC_VAPID_T	stVapId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_USRM_GET_NASINFO_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT8	aucNasIp[4];		/* NAS IP����AC��Ʒѷ�����ͨ�ŵĵ�ַ */
	CHAR	acNasId[256];	/* NAS ID�������û���ǰ�����VLAN��ȡ���ȵ�ID */
}AC_USRM_GET_NASINFO_RSP_T;

/* 2011-3-7 pyy add: ��ȡ���û���nas ��Ϣ*/
typedef struct
{
	UINT32	ulVlanId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
} AC_USRM_GET_WIRENASINFO_REQ_T;

typedef AC_USRM_GET_NASINFO_RSP_T AC_USRM_GET_WIRENASINFO_RSP_T;

/* �����û���ַ��ȡ�û���֤����*/
typedef struct 
{
	UINT8	aucMac[6];		/* �û�MAC */
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

/* ��ȡIDS�����û��б�*/
typedef struct {
	UINT32	ulStartRec;     /* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_USRM_GET_ALLIDSUSER_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;   /* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
                          		AC_DB_TABLE_READ_NOTFINISH  δ����
						AC_DB_TABLE_READ_FINISH        ��ȡ���� */
	UINT32	ulNum;      /* ���ε��÷��ص������� */
	AC_USRM_MAC_T	astIdsUser[100];
	
	/* 2010-4-10 pyy ����*/
	UINT32	aulBlackListAddReason[100];	/* �ն˼��������ԭ�� */
	UINT32	aulBlackListDuration[100];		/* �ն��ں������л�Ҫ���ֵ�ʱ�䣬��λ���� */
} AC_USRM_GET_ALLIDSUSER_RSP_T;

typedef struct
{
	UINT32	ulWtpId;	/* AP �豸ID */
} AC_USRM_GET_APSTAASSONUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;
} AC_USRM_GET_APSTAASSONUM_RSP_T;


typedef struct
{
	UINT32	ulWtpId;	/* AP �豸ID */
} AC_USRM_GET_APSTAONLINENUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;
} AC_USRM_GET_APSTAONLINENUM_RSP_T;

#define AC_GETAPSTA_NUM_MAX		1000
typedef struct {
	UINT32	ulStartRec;     /* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_USRM_GET_ALLAPSTANUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;   /* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
                          		AC_DB_TABLE_READ_NOTFINISH  δ����
						AC_DB_TABLE_READ_FINISH        ��ȡ���� */
						
	UINT32	ulSkipNum;		/* �������ýӿ�ʱ, ulStartRec��Ҫ����ulSkipNum */					
	UINT32	ulWtpNum;      	/* ���ε��÷��ص������� */
	
	UINT32	aulWtpId[AC_GETAPSTA_NUM_MAX];
	UINT32	aulStaAssocSum[AC_GETAPSTA_NUM_MAX];
	UINT32	aulStaOnlineSum[AC_GETAPSTA_NUM_MAX];
} AC_USRM_GET_ALLAPSTANUM_RSP_T;



#define AC_SSIDSTA_NUM_MAX  1000

typedef struct {
	UINT32	ulStartRec;     /* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_USRM_GET_ALLSSIDSTANUM_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;   /* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
                          		AC_DB_TABLE_READ_NOTFINISH  δ����
						AC_DB_TABLE_READ_FINISH        ��ȡ���� */
	UINT32	ulSkipNum;	/* �������ýӿ�ʱ, ulStartRec��Ҫ����ulSkipNum */							
	UINT32	ulVapNum;
	UINT32	aulWtpId[AC_SSIDSTA_NUM_MAX];
	UINT32	aulVapId[AC_SSIDSTA_NUM_MAX];
	UINT32	aulStaAssocSum[AC_SSIDSTA_NUM_MAX];
	UINT32	aulStaOnlineSum[AC_SSIDSTA_NUM_MAX];
} AC_USRM_GET_ALLSSIDSTANUM_RSP_T;

// 	���������������û�MAC��ַ��ȡ�û���֤״̬
// 	��������ṹ��
typedef struct
{
	UINT8	aucMac[6];	/* �û�MAC��ַ */
	UINT8	aucRsv[2];	/* ����ֽ� */
} AC_USRM_GET_USERCERTSTATE_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulCertType;		/* ��֤����*/
    	UINT32	ulCertState;		/* ��֤״̬*/
} AC_USRM_GET_USERCERTSTATE_RSP_T;

typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
	UINT32	ulRet;	/* 0��ʾ�ɹ�
						1: ǿ������ʧ��, ʧ��ԭ���û�������*/
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

/* 2010-3-4 ����: ǿ��PPPOE��֤�û�����*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
}AC_USRM_PPPOE_USEROFFLINE_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* AC_OK��ʾ�ɹ� */
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


//	�û�����֪ͨ
typedef AC_USRM_USER_INFO_T AC_USRM_USER_ADD_IND_MSG_T;

//	�û��뿪֪ͨ
typedef AC_USRM_USER_INFO_T AC_USRM_USER_DEL_IND_MSG_T;

//	�û�Portal��֤������ɾ��֪ͨ
// 	�����������û�ɾ�����û�����ģ����Portal����֤ʱ�����ڱ���Portal��֤״̬��������֤�����ʱ��֪ͨPortalģ��
 //	��Ϣ��ṹ��
typedef struct 
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	/* ����ֽ� */
} AC_USRM_USERPORTAL_DEL_IND_MSG_T;

/* �û��л�֪ͨ*/
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

/* �û�QOS��Ϣ�仯֪ͨ*/
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

/* �����û�MAC��ַ��ȡMAC��֤����*/

typedef struct
{
	UINT32	ulMacSwitch;			/*	MAC��֤����*/
	UINT8	aucMacSrvAddr[4];	/*	MAC��֤������IP */
	UINT32	ulMacSrvPort;		/*	MAC��֤�������˿�*/
	UINT32	ulTrafficTime;			/*	MAC��֤����ʱ��*/
	UINT32	ulTrafficThresh;		/*	MAC��֤��������*/
} AC_USRM_MACSERVER_CONFIG_T;

typedef struct 
{
	
	UINT32	ulMacSwitch;			/*	MAC��֤����*/
	UINT8	aucMacSrvAddr[4];	/*	MAC��֤������IP */
	UINT32	ulMacSrvPort;		/*	MAC��֤�������˿�*/
	UINT32	ulTrafficTime;			/*	MAC��֤����ʱ��*/
	UINT32	ulTrafficThresh;		/*	MAC��֤��������*/
	UINT32	ulMOC;				/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	����ʵ����ʶ*/
}AC_USRM_SSIDMACSERVERSETUP_CONFIG_T;

typedef	struct
{
	UINT8	aucMac[6];		/* �û�MAC */
	UINT8	aucRsv[2];		/* ����ֽ� */
}AC_USRM_GET_USERMACSERVER_CONFIG_REQ_T;

typedef struct 
{
	UINT32 	ulRet;
	AC_USRM_MACSERVER_CONFIG_T		stMacServerCfg;
} AC_USRM_GET_USERMACSERVER_CONFIG_RSP_T;

/* add by gwx 2011-11-1 for �㶫�ƶ�*/
typedef struct
{
	UINT32	ulAuthType;		/* ��֤����  */
	UINT8	aucIp[4];		/* �û�IP */
	UINT8	aucMac[6];		/* �û�MAC */
	UINT8	aucRsv[2];		/* �����ֽ� */
	UINT32	ulStatType;		/* ͳ������ */
	UINT32	ulWtpId;		/* AP ID ��*/
	UINT32	ulVapId;			/* VAP ID��*/
} AC_USRM_INC_AUTHSTAT_REQ_T;
typedef struct
{
	UINT32	ulRet;
} AC_USRM_INC_AUTHSTAT_RSP_T;
typedef struct
{
	UINT32 ulPortalAuthTime;        		/*Portal��֤�ն˼�Ȩ����*/
	UINT32 ulAssociateAuthTime;         	/*������֤�ն˼�Ȩ����*/
	UINT32 ulMacAuthTime;				/*MAC��֤�ն˼�Ȩ����*/
	UINT32 ulPortalAuthFailTime;        	 /*Portal��֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulAssociateAuthFailTime;		/*������֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulMacAuthFailTime;             /*MAC��֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulPortalAuthSuccNum;	        /*Portal��֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulAssociateAuthSuccNum;	 	/*������֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulMacAuthSuccNum;	        /*MAC��֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulPortalOnlineUserNum;			/*��ǰͨ��WEB��֤�������û���*/
	UINT32 ulFreeOnlineUserNum;			/*��ǰͨ������֤�������û���*/
	UINT32 ulAssociateOnlineUserNum;    	/*��ǰͨ��������֤�������û���*/
	UINT32 ulMacOnlineUserNum; 			/*��ǰͨ��MAC��֤�������û�*/
	UINT32 ulPortalOfflineUserNum;          	/*Portal��֤�û��쳣���ߴ���*/
	UINT32 ulFreeOfflineUserNum;            	/*����֤�û��쳣���ߴ���*/
	UINT32 ulAssociateOfflineUserNum;   		/*������֤�û��쳣���ߴ���*/
	UINT32 ulMacOfflineUserNum;            	/*MAC��֤�û��쳣���ߴ���*/
} AC_USRM_GET_ACAUTHSTAT_RSP_T;
/* add by gwx 2011-11-1 for �㶫�ƶ�end*/

/*EAP��֤�û� ���������ߣ�֪ͨhostapd*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	AC_VAPID_T		stVapId;
} AC_USRM_EAPUSEROFFLINE_REQ_MSG_T;

/* add by gwx 2012-6-4 for bug 1100 ����û��ɹ���������DHCP�����ַ*/
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_USRM_USERIP_REQ_MSG_T;

/* add by gwx 2012-10-31 for �û�������׼ȷbegin*/

typedef struct
{
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32 	ulUserRxPkts;		/* �û����а���*/
	UINT32	ulUserTxPkts;		/* �û����а���*/
	UINT32	ulUserCurRx4GB;		/* ����λ*/
	UINT32	ulUserCurRxBytes;	/* �û���������*/
	UINT32	ulUserCurTx4GB;		/* ����λ*/
	UINT32	ulUserCurTxBytes;	/* �û���������*/
} AC_USRM_USERTRAFFIC_T;

/* AP�����û�����������Ϣ��*/
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulUserNum;
	AC_USRM_USERTRAFFIC_T	astUserTraffic[AC_WTP_MAX_USERNUM];
} AC_USRM_SET_USERTRAFFIC_T;	

#if 0
/* ֪ͨAP�Ƿ��û���Ϣ��*/

typedef struct
{
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32	ulCertChgRsnCode;	/* ��֤״̬�仯��ԭ���룬�������*/
	UINT32	ulCertChgTime;		/* ��֤״̬�仯��ʱ��*/
} AC_USRM_ILLEGALUSER_T;
#endif

typedef struct
{
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32 	ulGetForStop;  	/* ��ֹ֤ͣԭ����λ*/
}AC_USRM_GET_USERTRAFFIC_BYMAC_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32 	ulUserRxPkts;			/* �û����а���*/		
	UINT32	ulUserTxPkts;			/* �û����а���*/
	UINT32	ulUserCurRx4GB;			/* ����λ*/
	UINT32	ulUserCurRxBytes;		/* �û���������*/
	UINT32	ulUserCurTx4GB;			/* ����λ*/
	UINT32	ulUserCurTxBytes;		/* �û���������*/
}AC_USRM_GET_USERTRAFFIC_BYMAC_RSP_T;


typedef struct
{
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32	ulCertChgRsnCode;	/* ��֤״̬�仯��ԭ���룬�������*/
	UINT32	ulCertChgTime;		/* ��֤״̬�仯��ʱ��*/
	/* add by gwx 2014-5-30 for �㶫����*/
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
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32	ulRet;				/* ����������,0�ɹ�,0xFFFFFFFFʧ��*/
}AC_USRM_USER_CERTSTATCHG_AP_RPT_T;

typedef AC_USRM_USER_CERTSTATCHG_AP_RPT_T	AC_USRM_USER_STARTTRAFFIC_AP_RTP_T;
typedef AC_USRM_USER_CERTSTATCHG_AP_RPT_T	AC_USRM_USER_STOPTRAFFIC_AP_RPT_T;

typedef struct
{
	UINT8	aucMac[6];			/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32	ulWtpId;
	UINT32	ulCertChgRsnCode;	/* ��֤״̬�仯��ԭ���룬�������*/
	UINT32	ulCertChgTime;		/* ��֤״̬�仯��ʱ��*/
	/* add by gwx 2014-5-30 for �㶫����*/
	UINT32	ulVlan;
	UINT32	ulMacCertTag;		/* add by gwx 2014-7-21 */
}AC_USRM_USER_TRAFFIC_T;
typedef AC_USRM_USER_TRAFFIC_T		AC_USRM_STARTUSERTRAFFIC_T;
typedef AC_USRM_USER_TRAFFIC_T		AC_USRM_STOPUSERTRAFFIC_T;

/* add by gwx 2012-10-31 for �û�������׼ȷend*/

/* add by gwx 2012-11-29 for AP/VAP������*/
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
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_USR_QOS_T	stQos;		/* �û�QOS */
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

/* add by gwx 2013-10-14 for task1076 ��ҵ���û������أ�
��ȡ�û���֤��Ϣ�ṹ*/
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

/* add by gwx 2014-6-25 for SSID�û����ƽ���begin*/
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
/* add by gwx 2014-6-25 for SSID�û����ƽ���end*/
/* add by gwx 2014-5-13 for ��ݣ�AP�ϱ��û���Ϣ*/
typedef struct
{
	UINT8 aucUserMac[6];
	UINT8 aucRsv[2];
	UINT8 aucUserIp[4];
	UINT32 ulUserRssi;
	CHAR  acStaType[32];/* add by gwx 2014-9-3 ���AP�ϱ��ն��豸����*/
}AC_USRM_WTPUSERPARTINFO_T;
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulRecNum;
	AC_USRM_WTPUSERPARTINFO_T	stWtpUserPartInfo[AC_WTP_MAX_USERNUM];
}AC_USRM_SET_USERPARTINFOFROMAP_T;


/* �ӿڽṹ�嶨�����*/
/******************************************************************************/

/******************************************************************************/
/* ����������ʼ*/
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
/* add by gwx 2012-11-2 for �û�������׼ȷ*/
extern VOID ac_usrm_send_startusertraffic( AC_USRM_STARTUSERTRAFFIC_T* pstStartUserTaffic );
extern VOID ac_usrm_send_stopusertraffic( AC_USRM_STOPUSERTRAFFIC_T* pstStartUserTaffic );

extern VOID ac_usrm_get_usertraffic_bymac(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern VOID ac_usrm_get_userqosconfig(AC_USRM_GET_USERQOS_CONF_REQ_T   *pstReq, AC_USRM_GET_USERQOS_CONF_RSP_T   *pstRsp);
extern VOID ac_usrm_send_wtpuserflowctrl( AC_USRM_WTP_UPDATE_ALLUSER_T* pstMsg);

extern VOID ac_usrm_send_adduserflowctrl( UINT32 ulWtpId, AC_USRM_ADD_USER_FLOWCTRL_REQ_T *pstAddUserFlowCtrl);
extern VOID ac_usrm_send_deluserflowctrl( UINT32 ulWtpId, AC_USRM_DEL_USER_FLOWCTRL_REQ_T *pstDelUserFlowCtrl);

/* add by gwx 2013-1-23 for bug1718 */
extern VOID ac_usrm_get_userportal_config_byssid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

/* add by gwx 2014-6-25 for SSID���û��������*/
extern VOID ac_usrm_get_useraccesspermit(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
/* ������������*/

/******************************************************************************/

#endif /* _AC_USRM_PUBLIC_H */
/******************************* ͷ�ļ����� **********************************/



