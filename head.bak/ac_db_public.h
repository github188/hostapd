/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: ���ݿ����ģ�鹫��ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_DB_PUBLIC_H
#define  _AC_DB_PUBLIC_H

/******************************************************************************/
/* AC��ϵ��MOC�궨�忪ʼ*/
/* ϵͳ����*/
#define AC_DB_MOC_ACBASICSETUP				((UINT32)0x02000001)		/* AC �������ñ�MOC*/
#define AC_DB_MOC_ACWTPASSOCIATESETUP		((UINT32)0x02000112)		/* AC WTP�������ñ�MOC*/
#define AC_DB_MOC_ACKEEPERSETUP				((UINT32)0x02000105)		/* AC ������·������ñ�MOC*/
#define AC_DB_MOC_ACNEIGHBORSETUP			((UINT32)0x02000118)		/* AC �ھӹ�ϵ���ñ�MOC*/
#define AC_DB_MOC_ACSYSSNMPV2SETUP			((UINT32)0x0200010A)		/* AC SNMP V2���ñ�MOC*/
#define AC_DB_MOC_ACSYSSNMPV3SETUP			((UINT32)0x0200010B)		/* AC SNMP V3���ñ�MOC*/
#define AC_DB_MOC_ACSYSTRAPSVRSETUP			((UINT32)0x0200011A)		/* AC SNMP TRAP ���ñ�MOC*/
#define AC_DB_MOC_ACSNTPGLOBALSETUP			((UINT32)0x02000110)		/* AC SNTPȫ�����ñ�MOC*/
#define AC_DB_MOC_ACLOGSETUP					((UINT32)0x02000111)		/* AC LOG�������ñ�MOC*/
#define AC_DB_MOC_ACLOGSERVERSETUP			((UINT32)0x02000113)		/* AC LOG���������ñ�MOC*/
#define AC_DB_MOC_ACASSOCSWVERSETUP		((UINT32)0x0200010F)		/* AC֧�ֵ�AP����汾�б�����MOC*/

/* ����˿ں�IP����*/
#define AC_DB_MOC_ACIFSETUP					((UINT32)0x02000202)		/* AC����˿����ñ�MOC*/
#define AC_DB_MOC_ACIPSETUP					((UINT32)0x02000203)		/* AC�˿�IP��ַ����MOC*/

/* �û���DHCP��������*/
#define AC_DB_MOC_ACSTADHCPGLOBALSETUP				((UINT32)0x0200080F)		/* DHCP for STA�������ñ�MOC*/
#define AC_DB_MOC_ACSTADHCPSTATICIPADDRSETUP		((UINT32)0x02000811)		/* DHCP for STA ��̬��IP���ñ�MOC*/
#define AC_DB_MOC_ACSTADHCPDYNAMICIPADDRSETUP		((UINT32)0x02000813)		/* DHCP for STA ��̬IP��ַ�����ñ�MOC*/

/* AP��DHCP ��������*/
#define AC_DB_MOC_ACAPDHCPGLOBALSETUP				((UINT32)0x02000802)		/* DHCP for AP�������ñ�MOC*/
#define AC_DB_MOC_ACAPDHCPSTATICIPADDRSETUP		((UINT32)0x02000805)		/* DHCP for AP ��̬��IP���ñ�MOC*/
#define AC_DB_MOC_ACAPDHCPDYNAMICIPADDRSETUP		((UINT32)0x02000807)		/* DHCP for AP ��̬IP��ַ�����ñ�MOC*/

/* VLAN����*/
#define AC_DB_MOC_ACVLANGLOBALSETUP					((UINT32)0x02000402)		/* AC VLAN ȫ������MOC*/
#define AC_DB_MOC_ACVLANSETUP						((UINT32)0x02000407)		/* AC VLAN���ñ�MOC*/
#define AC_DB_MOC_ACSSIDVLANMAPPINGSETUP			((UINT32)0x02000411)		/* SSID-VLANӳ�����ñ�MOC*/
#define AC_DB_MOC_ACIFVLANMAPPINGSETUP				((UINT32)0x02000408)		/* AC �˿�-VLANӳ�����ñ�MOC*/
#define AC_DB_MOC_ACMACVLANMAPPINGSETUP			((UINT32)0x02000409)		/* AC MAC-VLANӳ�����ñ�MOC*/

/* WAPI����*/
#define AC_DB_MOC_ACWAPIASSETUP				((UINT32)0x0200011C)		/* AC AS���������ñ�MOC*/
#define AC_DB_MOC_ACWAPISETUP				((UINT32)0x0200011D)		/* AC WAPI�������ñ�MOC*/
#define AC_DB_MOC_ACWAPICERTFILESETUP		((UINT32)0x0200011E)		/* AC WAPI֤�����ñ�MOC*/

/* AAA����*/
#define AC_DB_MOC_ACAAASETUP					((UINT32)0x02000302)		/* AC AAA���ñ�MOC*/

/* ����֤����*/
#define AC_DB_MOC_ACFREEGLOBALSETUP			((UINT32)0x02000305)		/* ACȫ������֤MOC*/
#define AC_DB_MOC_ACFREEIPSETUP				((UINT32)0x02000307)		/* AC����֤IP�б�MOC*/
#define AC_DB_MOC_ACFREEMACSETUP			((UINT32)0x02000309)		/* AC����֤MAC�б�MOC*/
#define AC_DB_MOC_ACFREESSIDSETUP			((UINT32)0x02000127)		/* AC����֤SSID�б�MOC*/
#define AC_DB_MOC_ACFREEVLANSETUP			((UINT32)0x02000128)		/* AC����֤VLAN�б�MOC*/

/* MAC��֤����*/
#define AC_DB_MOC_ACMACSERVERSETUP			((UINT32)0x02000413)		/* MAC��֤���ñ�MOC */

/* WEB��֤����*/
#define AC_DB_MOC_ACPORTALSETUP				((UINT32)0x02000114)		/* AC ǿ��Portal���ñ�MOC*/
#define AC_DB_MOC_ACWHILTELISTSETUP			((UINT32)0x02000115)		/* AC Portal������IP ���ñ�MOC*/
#define AC_DB_MOC_ACWHITEURLLISTSETUP		((UINT32)0x02000A16)		/* AC Portal������URL���ñ�MOC*/
#define AC_DB_MOC_ACUSERADDRBINDSETUP		((UINT32)0x02000124)		/* AC �û�����ַ�����ñ�MOC*/
#define AC_DB_MOC_ACSSIDAUTHSETUP			((UINT32)0x0200012A)		/* SSID ��֤����MOC*/

/* PPP��֤����*/
#define AC_DB_MOC_ACPPPOESETUP				((UINT32)0x0200040A)		/* AC PPPoE���ñ�MOC*/

/* ·������*/
#define AC_DB_MOC_ACSTATICROUTESETUP		((UINT32)0x02000606)		/* ��̬·�����ñ�MOC*/
#define AC_DB_MOC_ACRIPGLOBALSETUP			((UINT32)0x02000608)		/* RIPȫ�����ñ�MOC*/
#define AC_DB_MOC_ACRIPANNOUNCENETSETUP		((UINT32)0x0200060C)		/* RIPͨ���������ñ�MOC*/

/* NAT����*/
#define AC_DB_MOC_ACNATGLOBALSETUP			((UINT32)0x0200070C)		/* NAT ȫ�����ñ�MOC*/
#define AC_DB_MOC_ACNATSETUP					((UINT32)0x0200070D)		/* NAT�������ñ�MOC*/

/* MAC��ַ��������*/
#define AC_DB_MOC_ACVLANACCESSMACPOLICYSETUP	((UINT32)0x0200040D)	/* AC VLAN MAC��ַ���˲���MOC*/
#define AC_DB_MOC_ACVLANACCESSMACLISTSETUP		((UINT32)0x0200040F)	/* AC VLAN MAC��ַ��MOC*/

/* ACL����*/
#define AC_DB_MOC_ACFIREWALLGLOBALSETUP		((UINT32)0x02000702)		/* ����ǽȫ�����ñ�MOC*/
#define AC_DB_MOC_ACFIREWALLRULEBASICSETUP	((UINT32)0x02000709)		/* ����ǽ����������ñ�MOC*/

/* IDS����*/
#define AC_DB_MOC_ACIDSRULESETUP				((UINT32)0x0200070F)		/* IDS�������ñ�MOC*/
#define AC_DB_MOC_ACIDSSTRATEGYSETUP			((UINT32)0x02000710)		/* IDS�������ñ�MOC*/

/* P2P����*/
#define AC_DB_MOC_ACFIREWALLL7MATCHSETUP		((UINT32)0x02000712)		/* ����ǽP2P�����������ñ�MOC*/

/* QoS����*/
#define AC_DB_MOC_ACQOSGLOBALSETUP				((UINT32)0x02000902)		/* QOSȫ�����ñ�MOC*/
#define AC_DB_MOC_ACQOSUSERDEFAULTSETUP		((UINT32)0x02000905)		/* �û�QOSȱʡ���ñ�MOC*/
#define AC_DB_MOC_ACVLANQOSSETUP				((UINT32)0x02000907)		/* VLAN QOS���ñ�MOC*/
#define AC_DB_MOC_ACSSIDQOSSETUP					((UINT32)0x02000909)		/* SSID QOS���ñ�MOC*/
#define AC_DB_MOC_ACUSERQOSSETUP				((UINT32)0x0200090B)		/* �û�QOS���ñ�MOC*/
/* add by gwx 2012-12-5 for AP/VAP����*/
#define AC_DB_MOC_ACVAPQOSSETUP			((UINT32)0x02000914)		/* VAP QOS���ñ�MOC */
#define AC_DB_MOC_ACAPQOSSETUP			((UINT32)0x02000913)		/* AP QOS���ñ�MOC */

/* IGMP����*/
#define AC_DB_MOC_ACIGMPSNOOPSETUP				((UINT32)0x02000502)		/* AC IGMP Snooping���ñ�MOC*/
#define AC_DB_MOC_ACIGMPPROXYSETUP				((UINT32)0x02000503)		/* AC IGMP Proxy���ñ�MOC*/

/* AC��������*/
#define AC_DB_MOC_ACMSSETUP						((UINT32)0x02000912)		/* AC�������ñ�MOC */

/* ���ܲ�������*/
#define AC_DB_MOC_ACALARMFILTERSETUP				((UINT32)0x02000A03)		/* �澯�������ñ�MOC*/
#define AC_DB_MOC_ACALARMTHRESHOLDSETUP		((UINT32)0x02000A06)		/* �澯�������ñ�MOC*/
#define AC_DB_MOC_ACPERFCOUNTERGROUPINFOSETUP	((UINT32)0x02000A05)		/* ���ܼ����������ñ�MOC*/

#define AC_DB_MOC_ACAPACLSETUP					((UINT32)0x02000A10)		/* AP���ʲ������ñ�MOC*/
#define AC_DB_MOC_ACAPIDNASSETUP					((UINT32)0x02000A13)		/* AP�豸ID��-NAS ID ӳ�����ñ�MOC*/
#define AC_DB_MOC_ACAPIPNASSETUP					((UINT32)0x02000A14)		/* AP �豸IP����-NAS ID ӳ�����ñ�MOC*/
#define AC_DB_MOC_ACAPIPVLANMAPPINGSETUP		((UINT32)0x02000A15)		/* AP �豸IP����-VLAN  ӳ�����ñ�MOC*/

#define AC_DB_MOC_WTPSYSBASICSETUP				((UINT32)0x01000001)	/* WTP�������ñ�MOC*/
#define AC_DB_MOC_WTPSYSIPSETUP					((UINT32)0x01000103)	/* WTP IP���ñ�MOC*/
#define AC_DB_MOC_WTPSYSLOADBALANCESETUP		((UINT32)0x0100010F)	/* WTP ���ؾ������ñ�MOC*/
#define AC_DB_MOC_WTPSYSLOGSETUP				((UINT32)0x01000112)	/* WTP ��־�������ñ�MOC*/
#define AC_DB_MOC_WTPSYSSWSERVERSETUP			((UINT32)0x01000105)	/* WTP ������������ñ�MOC*/
#define AC_DB_MOC_WTPSYSSNTPSETUP				((UINT32)0x0100010C)	/* WTP  SNTP�������ñ�MOC*/

#define AC_DB_MOC_WTPWIFIDEVICEBASICSETUP		((UINT32)0x01000202)	/* WTP �����豸�������ñ�MOC*/
#define AC_DB_MOC_WTPWIFIDEVICECHANNELSETUP	((UINT32)0x01000204)	/* WTP �����豸�����ŵ����ñ�MOC*/
#define AC_DB_MOC_WTPWIFIDEVICERATESETUP		((UINT32)0x01000205)	/* WTP �����豸�����������ñ�MOC*/
#define AC_DB_MOC_WTPWIFIDEVICEPOWERSETUP		((UINT32)0x01000206)	/* WTP �����豸���߹������ñ�MOC*/ 
#define AC_DB_MOC_WTPWIFIDEVICEADVANCEDSETUP		((UINT32)0x01000207)	/* WTP �����豸���߸߼����ñ�MOC*/
#define AC_DB_MOC_WTPWIFIDEVICEWIDSSETUP			((UINT32)0x01000208)	/* WTP �����豸WIDS���ñ�MOC*/
#define AC_DB_MOC_WTPWIFIDEVICERESOURCESETUP		((UINT32)0x0100020A)	/* WTP �����豸������Դ�������ñ�MOC*/

#define AC_DB_MOC_WTPAPBASICSETUP					((UINT32)0x01000303)	/* WTP VAP�������ñ�MOC*/ 
#define AC_DB_MOC_WTPAPSECURITYSETUP				((UINT32)0x01000306)	/* WTP VAP��ȫ���ñ�MOC*/
#define AC_DB_MOC_WTPAPADVANCEDSETUP				((UINT32)0x01000307)	/* WTP VAP�߼����ñ�MOC*/

#define AC_DB_MOC_WTPADHOCBASICSETUP				((UINT32)0x01000402)	/* WTP ADHOC�������ñ�MOC*/
#define AC_DB_MOC_WTPADHOCSECURITYSETUP			((UINT32)0x01000404)	/* WTP ADHOC��ȫ���ñ�MOC*/

#define AC_DB_MOC_WTPENETBASICSETUP					((UINT32)0x01000602)	/* WTP ��̫�������ñ�MOC*/

#define AC_DB_MOC_WTPROUTEBASICSETUP				((UINT32)0x01000702)	/* WTP·�ɻ������ñ�MOC*/
#define AC_DB_MOC_WTPROUTENEIGHBORSETUP			((UINT32)0x01000703)	/* WTP·���ھӹ������ñ�MOC*/
#define AC_DB_MOC_WTPROUTEHANDOVERSETUP			((UINT32)0x01000704)	/* WTP·���л��������ñ�MOC*/
#define AC_DB_MOC_WTPROUTEDEVICEMSCSETUP			((UINT32)0x01000705)	/* WTP·���豸���ӹ������ñ�MOC*/

#define AC_DB_MOC_WTPCAPWAPSETUP					((UINT32)0x01000901)	/* WTP CAPWAP���ñ�MOC*/

#define AC_DB_MOC_WTPALARMFILTERSETUP				((UINT32)0x01000F03)		/* �澯�������ñ�MOC*/
#define AC_DB_MOC_WTPALARMTHRESHOLDSETUP			((UINT32)0x01000F06)		/* �澯�������ñ�MOC*/
#define AC_DB_MOC_WTPPERFCOUNTERGROUPINFOSETUP	((UINT32)0x01000F04)		/* �����������ñ�MOC*/

#define AC_DB_MOC_ACNASIDSETUP						((UINT32)0x02000A17)		/* nasid���ñ�MOC*/
#define AC_DB_MOC_ACSSIDMACSERVERSETUP				((UINT32)0x02000414)		/* ssidMAC�������ñ�MOC*/
/* add by gwx 2013-10-12 for task1076 ��ҵ���û�����������*/
#define AC_DB_MOC_ACUSERGROUPSETUP				((UINT32)0x02000A6C)	/*�û� �����ñ�*/
#define AC_DB_MOC_WTPAPUSERGROUPQOSSETUP		((UINT32)0x01000F07)	/* �û����������ñ�*/
#define AC_DB_MOC_WTPSYSLOCATORSETUP		((UINT32)0x01000F08)	/* AP��λ�������ñ�*/

/* add by gwx 2014-6-25 for SSID�û��������begin*/
#define AC_DB_MOC_ACSSIDACCESSSETUP				( (UINT32)0x02000A6D)		/* SSID ���û��������ģʽ���ñ�MOC*/
#define AC_DB_MOC_ACSSIDACCESSLISTSETUP			( (UINT32)0x02000A6E)		/* SSID ���û���������б����ñ�MOC*/
/* add by gwx 2014-6-25 for SSID�û��������end*/

#define AC_DB_MOC_ACLINKIPLISTSETUP ((UINT32)0x02000A6F)        /*AP ����IP ���ñ�*/

/******************************************************************************/

#define AC_DB_IF_MAX	50
#define EV_DBIF_BEGIN	(EV_DB_BEGIN+200)

#define AC_DB_GET_TABLE_ALLRECORDHOST_MSG	(EV_DBIF_BEGIN+1)
#define AC_DB_GET_TABLE_ONERECORDHOST_MSG	(EV_DBIF_BEGIN+2)
#define AC_DB_GET_TABLE_WTPRECORDHOST_MSG	(EV_DBIF_BEGIN+3)
#define AC_DB_GET_TABLE_ALLRECORDNET_MSG	(EV_DBIF_BEGIN+4)
#define AC_DB_GET_TABLE_ONERECORDNET_MSG	(EV_DBIF_BEGIN+5)
#define AC_DB_GET_TABLE_WTPRECORDNET_MSG	(EV_DBIF_BEGIN+6)

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
#define AC_DB_GET_TABLE_ALLRECORDNET_PROBE_MSG	(EV_DBIF_BEGIN+7)
/* END: Added by wubin, 2012/4/25   BUG:000 */

#define AC_DB_SHOW_TABLE_MSG					(EV_DBIF_BEGIN+31)

#define AC_DB_TABLE_CHANGE_IND_MSG			(EV_DBIF_BEGIN+51)

/* ������������/��Ӧ*/
#define AC_DB_CFG_INC_UPDATE_HOST_REQ_MSG		(EV_DBIF_BEGIN+61)		/* ������������: ������*/
#define AC_DB_CFG_INC_UPDATE_HOST_RSP_MSG		(EV_DBIF_BEGIN+62)		/* ����������Ӧ: ������*/
#define AC_DB_CFG_INC_UPDATE_NET_REQ_MSG		(EV_DBIF_BEGIN+63)		/* ������������: ������*/
#define AC_DB_CFG_INC_UPDATE_NET_RSP_MSG		(EV_DBIF_BEGIN+64)		/* ����������Ӧ: ������*/

//2009/11/17 fengjing add increment batch update
#define AC_DB_CFG_INC_BATCHUPDATE_HOST_REQ_MSG (EV_DBIF_BEGIN + 71)      /* ����������������: ������*/
#define AC_DB_CFG_INC_BATCHUPDATE_HOST_RSP_MSG (EV_DBIF_BEGIN + 72)      /* ��������������Ӧ: ������*/
#define AC_DB_CFG_INC_BATCHUPDATE_NET_REQ_MSG (EV_DBIF_BEGIN + 73)        /* ����������������: ������*/
#define AC_DB_CFG_INC_BATCHUPDATE_NET_RSP_MSG (EV_DBIF_BEGIN + 74)        /* ��������������Ӧ: ������*/

/* 2011-1-12 pyy add */
#define AC_DB_RESET_APUSERSTAT_REQ_MSG			(EV_DBIF_BEGIN + 81)		/* ����û���ʱͳ�Ʊ����� */

#define AC_DB_CFG_DELAP_HOST_REQ_MSG (EV_DBIF_BEGIN + 91)      /* ɾ��AP��������: ������*/
#define AC_DB_CFG_DELAP_HOST_RSP_MSG (EV_DBIF_BEGIN + 92)      /* ɾ��AP������Ӧ: ������*/
#define AC_DB_CFG_ADDAP_HOST_REQ_MSG (EV_DBIF_BEGIN + 93)      /* ����AP����: ������*/
#define AC_DB_CFG_ADDAP_HOST_RSP_MSG (EV_DBIF_BEGIN + 94)      /* ����AP��Ӧ: ������*/
/* �����������Ͷ���*/
#define AC_DB_CFG_INC_ADD						0	/* ����*/
#define AC_DB_CFG_INC_DEL						1	/* ɾ��*/
#define AC_DB_CFG_INC_UPDATE					2	/* �޸�*/

#define AC_BYTE_ORDER_HOST					0	/* ������*/
#define AC_BYTE_ORDER_NET						1	/* ������*/
#define AC_DB_CFG_DELAP_NUM_MAX 50	/*����ɾ��AP �����Ŀ*/
#define AC_DB_CFG_ADDAP_NUM_MAX 100	/*��������AP �����Ŀ*/


/* add by gwx 2011-11-2 for �㶫�ƶ���������֤����*/
#define AC_DB_SECURITY_AUTHTYPE_OPENSYSTEM	1
#define AC_DB_SECURITY_AUTHTYPE_SHAREDKEY	2
#define AC_DB_SECURITY_AUTHTYPE_WPAPSK		3
#define AC_DB_SECURITY_AUTHTYPE_WPA			4
#define AC_DB_SECURITY_AUTHTYPE_MAC			5
#define AC_DB_SECURITY_AUTHTYPE_WAPIWAI		6
/* add by gwx 2014-5-28 for ruijie ������Ϣһ��ͳ��*/
#define TIME_FMT        "%04d-%02d-%02d %02d:%02d:%02d"
#define TIME_ARG(x)     (1900+(x)->tm_year),(1+(x)->tm_mon),(x)->tm_mday,(x)->tm_hour,(x)->tm_min,(x)->tm_sec

extern VOID ac_db_access(UINT32 ulMsgId, UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

extern TPID    gtDbCtrlProc;
extern TPID    gtDbCmPid;
extern TPID    gtAcCwPid;
extern TPID    gtWtpCwPid;
extern TPID    gtComPid;
extern TPID    gtHostapdPid;
extern TPID    gtOamPid;
extern TPID    gtAcmPid;
//extern TPID		gtSmPid;
extern TPID		gtRrmPid;
extern TPID		gtPortalPid;
extern TPID		gtWapiPid;
extern TPID		gtSysmPid;
extern TPID		gtUsrmPid;
extern TPID		gtApOmaPid;
extern TPID		gtOssMsPid;

//5.1.1	��ȡָ����ϵ������м�¼
typedef struct
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* ��ϵ���� */
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
} AC_DB_GET_TABLE_ALLRECORD_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulFinish;		/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulRecLen;	/* ��¼���� */
	UINT32	ulRecNum;	/* ��¼�� */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* ��¼���� */
} AC_DB_GET_TABLE_ALLRECORD_RSP_T;

//5.1.2	��ȡָ����ϵ���ָ����¼
typedef struct
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* ��ϵ���� */
	/* �ؼ��� */
	UINT32	ulMOC;				/* �������ʶ */
	UINT8	aucMOI[AC_MOI_LEN];	/* ����ʵ����ʶ */
} AC_DB_GET_TABLE_ONERECORD_REQ_T;


typedef struct
{
	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulRecLen;	/* ��¼���� */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* ��¼���� */
} AC_DB_GET_TABLE_ONERECORD_RSP_T;

//5.1.3	��ȡָ����ϵ��ָ��AP�豸����ؼ�¼
typedef struct
{
    CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];      /* ��ϵ���� */
    UINT32      ulWtpId;                                /* WTP ID */
    UINT32      ulStartRec;     /* ��ѯ����ʼ��¼�� */
} AC_DB_GET_TABLE_WTPRECORD_REQ_T;

typedef struct
{
    UINT32  ulRet;      		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    UINT32  ulFinish;   		/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
                            			AC_DB_TABLE_READ_NOTFINISH  δ����
							AC_DB_TABLE_READ_FINISH     ��ȡ���� */
    UINT32  ulRecLen;   	/* ��¼���� */
    UINT32  ulRecNum;   	/* ��¼�� */
    UINT8   aucRecord[AC_DB_PACKET_MAX_LEN];    /* ��¼���� */
} AC_DB_GET_TABLE_WTPRECORD_RSP_T;

/* ��ʾָ����ϵ�����м�¼*/
typedef struct 
{
	CHAR        	acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* ��ϵ���� */
} AC_DB_SHOW_TABLE_REQ_T;

typedef struct 
{
	UINT32  ulRet;      		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_DB_SHOW_TABLE_RSP_T;

//	��Ϣ�ӿ�
//	��ϵ���¼���֪ͨ
 typedef struct
{
	CHAR 	acTblName[AC_DB_TBL_NAME_LEN_MAX];
} AC_DB_TABLE_CHANGE_IND_MSG_T;


/* ������������*/
typedef struct 
{
	UINT32	ulSn;		/* ���к�*/
	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];
	UINT32	ulIncType;	/* �����������ͣ�
						0 ������
						1��ɾ��
						2���޸�
						*/
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN];	/* ��¼���� */
} AC_DB_CFG_INC_UPDATE_REQ_T;

/* ����������Ӧ*/
typedef struct 
{
	UINT32	ulSn;	/* ���к�*/
	UINT32	ulRet;	/*����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	CHAR      acResultDesc[128];    /* ����������Ϣ */
} AC_DB_CFG_INC_UPDATE_RSP_T;

#define AC_DB_CFG_INC_BATCHUPDATE_NUM_MAX  ((UINT32)20)
typedef struct
{
	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];
	UINT32	ulIncType;	/* �����������ͣ�
						0 ������
						1��ɾ��
						2���޸�
						*/
	UINT32    ulRecLen;
	UINT8	  *aucRecord;	/* ��¼���� */
}AC_DB_CFG_INC_UPDATE_T;

// 2009/11/19 fengjing add
typedef struct
{
	UINT32	ulSn;		/* ���к�*/
	UINT32   ulModNum;
	AC_DB_CFG_INC_UPDATE_T astIncUpdate[AC_DB_CFG_INC_BATCHUPDATE_NUM_MAX];
}AC_DB_CFG_INC_BATCHUPDATE_REQ_T;

typedef struct
{
	UINT32	ulSn;	/* ���к�*/
	UINT32	ulRet;	/*����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	CHAR      acResultDesc[128];    /* ����������Ϣ */
}AC_DB_CFG_INC_BATCHUPDATE_RSP_T;

typedef struct
{
       UINT32 	ulSn;    /* ���к� */
       UINT32	ulDeviceType;
       UINT8    aucDeviceId[6];
       UINT8    aucRsv[2]; 
       UINT32 	ulNum;  /* ע��AP��Ŀ */
       UINT32 	aulApId[AC_DB_CFG_ADDAP_NUM_MAX];
}AC_DB_CFG_ADDAP_REQ_T;
typedef struct
{
       UINT32 ulSn;
       UINT32 ulRet; /* ������ */ 
       CHAR  acResultDesc[128];    /* ����������Ϣ */
}AC_DB_CFG_ADDAP_RSP_T;
typedef struct
{
       UINT32 ulSn;    /* ���к� */
       UINT32 ulNum;  /* ɾ��AP��Ŀ */
       UINT32 aulApId[AC_DB_CFG_DELAP_NUM_MAX];
}AC_DB_CFG_DELAP_REQ_T;
typedef struct
{
       UINT32 ulSn;
       UINT32 ulRet; /* ������ */ 
       CHAR  acResultDesc[128];    /* ����������Ϣ */
}AC_DB_CFG_DELAP_RSP_T;

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
typedef struct
{
	CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];		/* ��ϵ���� */
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
} AC_DB_GET_TABLE_ALLRECORD_PROBE_REQ_T;

typedef struct
{
	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulFinish;		/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulRecLen;	/* ��¼���� */
	UINT32	ulRecNum;	/* ��¼�� */
	UINT8	aucRecord[AC_DB_PACKET_MAX_LEN_NET];	/* ��¼���� */
} AC_DB_GET_TABLE_ALLRECORD_PROBE_RSP_T;
/* END: Added by wubin, 2012/4/25   BUG:000 */

#endif /* _AC_DB_PUBLIC_H */
/******************************* ͷ�ļ����� **********************************/

