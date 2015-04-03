/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��ϵ����ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
* 2009-3-3	  ������		     ����AC2.0����
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_DB_TABLE_H
#define  _AC_DB_TABLE_H

/******************************************************************************/

/*AC ��ϵ�������궨�忪ʼ*/
/* ϵͳ����*/
#define AC_DB_ACBASICSETUP_CAPACITY				((UINT32)1)			/* AC �������ñ������*/
#define AC_DB_ACWTPASSOCIATESETUP_CAPACITY		AC_WTP_NUM_MAX	/* AC WTP�������ñ������*/
#define AC_DB_ACKEEPERSETUP_CAPACITY				((UINT32)1)		/* AC ������·������ñ������*/
#define AC_DB_ACNEIGHBORSETUP_CAPACITY			((UINT32)1024)	/* AC �ھӹ�ϵ���ñ������*/
#define AC_DB_ACSYSSNMPV2SETUP_CAPACITY			((UINT32)4)		/* AC SNMP V2���ñ������*/
#define AC_DB_ACSYSSNMPV3SETUP_CAPACITY			((UINT32)4)		/* AC SNMP V3���ñ������*/
#define AC_DB_ACSYSTRAPSVRSETUP_CAPACITY		((UINT32)4)		/* AC SNMP TRAP ���ñ������*/
#define AC_DB_ACSNTPGLOBALSETUP_CAPACITY		((UINT32)1)		/* AC SNTPȫ�����ñ������*/
#define AC_DB_ACLOGSETUP_CAPACITY				((UINT32)1)		/* AC LOG�������ñ������*/
#define AC_DB_ACLOGSERVERSETUP_CAPACITY			((UINT32)1)		/* AC LOG���������ñ������*/
#define AC_DB_ACASSOCSWVERSETUP_CAPACITY		((UINT32)1)		/* AC֧�ֵ�AP����汾�б����ñ�����*/

/* ����˿ں�IP����*/
#define AC_DB_ACIFSETUP_CAPACITY					((UINT32)16)		/* AC����˿����ñ������*/
#define AC_DB_ACIPSETUP_CAPACITY					((UINT32)1)		/* AC�˿�IP��ַ���ñ�����*/

/* 2011-5-20 pyy: ��ַ������32--->256 */
/* �û���DHCP��������*/
#define AC_DB_ACSTADHCPGLOBALSETUP_CAPACITY			((UINT32)1)		/* DHCP for STA�������ñ������*/
#define AC_DB_ACSTADHCPSTATICIPADDRSETUP_CAPACITY		((UINT32)256)	/* DHCP for STA ��̬��IP���ñ������*/
#define AC_DB_ACSTADHCPDYNAMICIPADDRSETUP_CAPACITY	((UINT32)256)		/* DHCP for STA ��̬IP��ַ�����ñ������*/

/* AP��DHCP ��������*/
#define AC_DB_ACAPDHCPGLOBALSETUP_CAPACITY				((UINT32)1)		/* DHCP for AP�������ñ������*/
#define AC_DB_ACAPDHCPSTATICIPADDRSETUP_CAPACITY		((UINT32)256)	/* DHCP for AP ��̬��IP���ñ������*/
#define AC_DB_ACAPDHCPDYNAMICIPADDRSETUP_CAPACITY		((UINT32)256)		/* DHCP for AP ��̬IP��ַ�����ñ������*/

/* VLAN����*/
#define AC_DB_ACVLANGLOBALSETUP_CAPACITY			((UINT32)1)		/* AC VLAN ȫ�����ñ�����*/
#define AC_DB_ACVLANSETUP_CAPACITY					((UINT32)1024)	/* AC VLAN���ñ������*/
#define AC_DB_ACAPIPVLANMAPPINGSETUP_CAPACITY		((UINT32)256)	/* AP IP����-VLANӳ�����ñ������*/
#define AC_DB_ACSSIDVLANMAPPINGSETUP_CAPACITY		((UINT32)16)		/* SSID-VLANӳ�����ñ������*/
/* mod by gwx 2012-5-31 change 1024 to 4096 for bug1089 */
#define AC_DB_ACIFVLANMAPPINGSETUP_CAPACITY			((UINT32)4096)	/* AC �˿�-VLANӳ�����ñ������*/
#define AC_DB_ACMACVLANMAPPINGSETUP_CAPACITY		((UINT32)1024)	/* AC MAC-VLANӳ�����ñ������*/

/* WAPI����*/
#define AC_DB_ACWAPIASSETUP_CAPACITY				((UINT32)1)		/* AC AS���������ñ������*/
#define AC_DB_ACWAPISETUP_CAPACITY				((UINT32)4)		/* AC WAPI�������ñ������*/
#define AC_DB_ACWAPICERTFILESETUP_CAPACITY		((UINT32)256)	/* AC WAPI֤�����ñ������*/

/* AAA����*/
#define AC_DB_ACAAASETUP_CAPACITY				((UINT32)1)		/* AC AAA���ñ������*/

/* ����֤����*/
#define AC_DB_ACFREEGLOBALSETUP_CAPACITY		((UINT32)1)		/*AC ����֤ȫ�����ñ������*/
#define AC_DB_ACFREEIPSETUP_CAPACITY				((UINT32)256)	/* AC����֤IP ��ַ�б������*/
#define AC_DB_ACFREEMACSETUP_CAPACITY			((UINT32)256)	/* AC����֤MAC�б������*/
#define AC_DB_ACFREESSIDSETUP_CAPACITY			((UINT32)256)	/* AC����֤SSID�б������*/
#define AC_DB_ACFREEVLANSETUP_CAPACITY			((UINT32)256)	/* AC����֤VLAN�б������*/

#define AC_DB_ACMACSERVERSETUP_CAPACITY			((UINT32)1)		/* MAC��֤ȫ�����ñ������*/

/* WEB��֤����*/
#define AC_DB_ACPORTALSETUP_CAPACITY				((UINT32)1)		/* AC ǿ��Portal���ñ������*/
#define AC_DB_ACWHILTELISTSETUP_CAPACITY			((UINT32)32)		/* AC Portal���������ñ������*/
#define AC_DB_ACWHITEURLLISTSETUP_CAPACITY		((UINT32)64)		/* AC Portal������URL���ñ������*/
#define AC_DB_ACUSERADDRBINDSETUP_CAPACITY		((UINT32)64)		/* AC �û�����ַ�����ñ������*/
#define AC_DB_ACSSIDAUTHSETUP_CAPACITY			((UINT32)128)	/* SSID ��֤���ñ�����*/

/* PPPoE��֤����*/
#define AC_DB_ACPPPOESETUP_CAPACITY				((UINT32)1)		/* AC PPPoE���ñ������*/

/* ·������*/
#if 0	/* mod by gwx 2014-4-10 for bug1024 */
#define AC_DB_ACSTATICROUTESETUP_CAPACITY		((UINT32)128)	/* ��̬·�����ñ������*/
#else
#define AC_DB_ACSTATICROUTESETUP_CAPACITY		((UINT32)1024)	/* ��̬·�����ñ������*/
#endif
#define AC_DB_ACRIPGLOBALSETUP_CAPACITY			((UINT32)1)		/* RIPȫ�����ñ������*/
#define AC_DB_ACRIPANNOUNCENETSETUP_CAPACITY	((UINT32)16)		/* RIPͨ���������ñ������*/

/* NAT����*/
#define AC_DB_ACNATGLOBALSETUP_CAPACITY			((UINT32)1)		/* NAT ȫ�����ñ������*/
#define AC_DB_ACNATSETUP_CAPACITY				((UINT32)32)		/* NAT�������ñ������*/

/* MAC��ַ��������*/
#define AC_DB_ACVLANACCESSMACPOLICYSETUP_CAPACITY	((UINT32)1024)	/* AC VLAN MAC��ַ���˲��Ա�����*/
#define AC_DB_ACVLANACCESSMACLISTSETUP_CAPACITY	((UINT32)1024)	/* AC VLAN MAC��ַ�б�����*/

/* ACL����*/
#define AC_DB_ACFIREWALLGLOBALSETUP_CAPACITY	((UINT32)1)		/* ����ǽȫ�����ñ������*/
#define AC_DB_ACFIREWALLRULEBASICSETUP_CAPACITY	((UINT32)512*4)	/* ����ǽ����������ñ������*/

/* IDS����*/
#define AC_DB_ACIDSRULESETUP_CAPACITY				((UINT32)1)		/* IDS�������ñ������*/
#define AC_DB_ACIDSSTRATEGYSETUP_CAPACITY			((UINT32)1)		/* IDS�������ñ������*/

/* P2P����*/
#define AC_DB_ACFIREWALLL7MATCHSETUP_CAPACITY		((UINT32)1)		/* ����ǽP2P�����������ñ������*/

/* QoS����*/
#define AC_DB_ACQOSGLOBALSETUP_CAPACITY				((UINT32)1)		/* QOSȫ�����ñ������*/
#define AC_DB_ACQOSUSERDEFAULTSETUP_CAPACITY		((UINT32)1)		/* �û�QOSȱʡ���ñ������*/
#define AC_DB_ACUSERQOSSETUP_CAPACITY				((UINT32)256)	/* �û�QOS���ñ������*/
#define AC_DB_ACVLANQOSSETUP_CAPACITY				((UINT32)128)	/* VLAN QOS���ñ������*/
#define AC_DB_ACSSIDQOSSETUP_CAPACITY				((UINT32)128)	/* SSID QOS���ñ������*/
#define AC_DB_ACVAPQOSSETUP_CAPACITY				((UINT32)4096*16)	/* VAP QOS���ñ������*/
#define AC_DB_ACAPQOSSETUP_CAPACITY				((UINT32)4096)	/* AP QOS���ñ������*/

/* IGMP����*/
#define AC_DB_ACIGMPSNOOPSETUP_CAPACITY			((UINT32)1)		/* AC IGMP Snooping���ñ������*/
#define AC_DB_ACIGMPPROXYSETUP_CAPACITY			((UINT32)1)		/* AC IGMP Proxy���ñ������*/

/* 2010-1-18 pyy ���� */
/* �������� */
#define AC_DB_ACMSSETUP_CAPACITY                ((UINT32)1)     /* AC�������� */

/* ���ܲ�������*/
#define AC_DB_ACALARMFILTERSETUP_CAPACITY				((UINT32)128)	/* �澯�������ñ������*/
#define AC_DB_ACALARMTHRESHOLDSETUP_CAPACITY			((UINT32)1)		/* �澯�������ñ������*/
#define AC_DB_ACPERFCOUNTERGROUPINFOSETUP_CAPACITY	((UINT32)128)	/* ���ܼ����������ñ������*/

#define AC_DB_ACAPACLSETUP_CAPACITY               		 		((UINT32)1)		/* AP���ʲ������ñ�*/
#define AC_DB_ACAPIDNASSETUP_CAPACITY					((UINT32)256)	/* AP�豸ID��-NAS IDӳ���*/
#define AC_DB_ACAPIPNASSETUP_CAPACITY					((UINT32)256)	/* AP IP����-NAS IDӳ���*/

#define AC_DB_ACNASIDSETUP_CAPACITY						((UINT32)128)		/* NASID���ñ�����*/
#define AC_DB_ACSSIDMACSERVERSETUP_CAPACITY				((UINT32)128)		/* ssidmac�������ñ�*/
/* add by gwx 2013-10-11 for task1076 ��ҵ���û�����������*/
#define AC_DB_ACUSERGROUPSETUP_CAPACITY					((UINT32)8)	/* �û����������ñ�*/

/* add by gwx 2014-6-25 for SSID���û����ƽ���begin*/
#define AC_DB_ACSSIDACCESSSETUP_CAPACITY				((UINT32)32)	/* SSID���û��������ģʽ���ñ�*/
#define AC_DB_ACSSIDACCESSSLISTETUP_CAPACITY			((UINT32)1024)	/* SSID���û���������б����ñ�*/
/* add by gwx 2014-6-25 for SSID���û����ƽ���end*/
#define AC_DB_ACLINKIPLISTETUP_CAPACITY			((UINT32)32)	/*AC����IP �б����ñ�*/

/* ����Ϊ��̬��*/
/* mod by gwx 2012-7-4 for bug1303 �û�����������16��*/
#if 1 /* mod by gwx for ��ҵ������*/
#define AC_DB_ACUSER_CAPACITY							((UINT32)4096*16)	/* �����û�������*/
#else
#define AC_DB_ACUSER_CAPACITY							((UINT32)4096*4)	/* �����û�������*/
#endif
#define AC_DB_ACUSERVLAN_CAPACITY					((UINT32)4096)	/* �û�VLAN���������*/
#define AC_DB_ACDYNEVENT_CAPACITY					((UINT32)1000)	/* �¼�������*/
#define AC_DB_ACIDSUSER_CAPACITY						((UINT32)1000)	/* IDS�������û�������*/
/* mod by gwx 2012-7-4 for bug1303 �û�Portal��֤���������4��*/
#define AC_DB_ACPORTALUSER_CAPACITY					((UINT32)4096*16)	/* �û�Portal��֤���������*/
#define AC_DB_ACUSERACCINFO_CAPACITY					((UINT32)4096)	/* ��ʷ�ն˽�����Ϣ�������*/
#define AC_DB_ACUSERIPINFO_CAPACITY					((UINT32)4096)	/* �ն�IP������Ϣ��ϵ�������*/
/* 2011-1-12 pyy add */
#define AC_DB_ACHISTORYUSER_CAPACITY					(AC_DB_ACUSER_CAPACITY*4)	/* ��ʷ�û��� */

/* add by gwx 2011-11-2 for �㶫�ƶ�*/
#define AC_DB_ACAUTHSTAT_CAPACITY					((UINT32)1)	/* AC��֤ͳ�Ʊ�����*/

/* add by gwx 2012-11-2 for�û�������׼ȷ*/
#define AC_DB_ACUSERTIMER_CAPACITY					((UINT32)4096*16)	/* �û���ʱ��������*/


/*AC ��ϵ�������궨�����*/
/******************************************************************************/

/******************************************************************************/
/* 2009-3-3 AC2.0 add */
/* AC ��ϵ��ṹ�嶨�忪ʼ*/
/* AC�������ñ�*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	CHAR	acAcNEId[32];		/* �豸��Ԫ����*/
	CHAR	acDomainName[64];	/*	AC������*/
	CHAR	acContact[64];		/* �豸ά����ϵ��*/
	CHAR	acLocation[64];		/* �豸����λ��*/
	
	UINT32	ulMaxWtpNum;		/* �����������WTP��*/
	UINT32	ulMaxStaSwitch;		/* 2010-7-20 ����: ����û������� 0:���� 1:����*/
	UINT32	ulMaxStaNum;		/* ������������û���*/
	UINT32	ulMaxPortalStaNum;	/*	�����������Portal�û���	*/
	UINT32	ulMaxPPPoEStaNum;	/*	�����������PPPoE�û���	*/

	/* 2010-4-10 pyy ����*/
	UINT32	ulHeartbeatOnOff;	/* ������⿪��0:���� 1:����*/
	
	UINT32	ulHeartbeatPeriod;	/* ��������*/
    UINT8   aucManageIpAddr[4]; /* ����IP��ַ*/
	UINT32	ulStatisticsTime;		/* ����ͳ��ͳ��ʱ��	>0	60	��λ����*/
	UINT32	ulSampleTime;		/* ����ͳ�Ƴ���ʱ��	>0	10	��λ����*/

	/* 2010-4-10 pyy ����*/
	UINT32	ulNormalCollectCycle;	/* AP����ɼ����� ��λ:�� 10~120 */
	UINT32	ulRtCollectCycle;			/* APʵʱ�ɼ����� ��λ:�� 2~5 */

	/* 2010-10-21 fengjing add */
	UINT32    ulCollectSwitch;         /* ͳ�Ʋɼ����� */

	UINT32    ulAllAPMonitorMode;      /* AP���߼���ģʽ */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
	
	UINT32	ulCfgVersion;	
} AC_DB_TBL_ACBASICSETUP_T;

/* AC��������*/
typedef struct {
	UINT32	ulAcId;				/*	�豸ID */

	UINT32	ulWtpId;				/*  WTP�豸ID */
	UINT32	ulAssociatePrio;		/*	�������ȼ�*/
	UINT32	ulWtpAuthManner;	/*	WTP������֤��ʽ*/
	CHAR	acSecret[32];		/*	WTP�豸��������*/
	UINT8	aucWtpSn[6];		/* WTP�豸���к�*/
	UINT8	aucResv[2];			/* Padding */
    UINT8   aucWtpMac[6];
    UINT8   aucResv1[2];
	UINT32  	ulEchoInterval;
	UINT32  	ulMaxRetransmit;
	UINT32 	ulWtpProductType;	/* add by gwx 2014-2-25 for task1265 AP��Ʒ����*/
	CHAR	acModelName[64];	/* add by gwx 2014-6-20 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWTPASSOCIATESETUP_T;

/* AC ������·������ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulKeepSwitch;		/*	�Ƿ�����		0=�ر�1=����*/
	UINT8	aucKeeperIp0[4];		/*	���IP��ַ1		��Ч��IP��ַ*/
	UINT8	aucKeeperIp1[4];		/*	���IP��ַ2		��Ч��IP��ַ*/
	UINT32	ulKeepInterval;		/*	�����		>=0 */
	UINT32	ulKeepCount;			/*	��ʱ����		>=0 */
	UINT32	ulToStandby;			/* 2011-6-20 pyy ����: ��⵽������·���Ϻ�Ĳ���
									�л���standby ״̬0:���� 1:����*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACKEEPERSETUP_T;


/* AC�ھӹ�ϵ���ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */
	
	UINT32	ulNeighId;			/*		�ھӹ�ϵID*/
	UINT32	ulNeighType;			/*		�ھ�����*/
	UINT32	ulWtpId;				/*		AP��ʶ*/
	UINT32	ulWifiDeviceId;		/*		AP�����豸ID*/
	UINT32	ulNeighWtpId;		/*		����AP��ʶ*/
	UINT32	ulNeighWifiDeviceId;	/*		����AP�����豸ID*/
	UINT32	ulNeighRelation;		/*		�ھӹ�ϵ*/
	UINT32	ulLoadNeigh;			/*		�Ƿ񸺺ɾ����ھ�*/
	UINT32	ulCoverageNeigh;	/*		�Ƿ񸲸ǲ����ھ�*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACNEIGHBORSETUP_T;

/* AC SNMP V2����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulCommunityId;			/* ��ͬ��ID */
	CHAR	acReadCommunity[32];	/* ����ͬ�� */
	CHAR	acWriteCommunity[32];	/* д��ͬ�� */
	UINT32	ulRfc1213Flag;			/* RFC1213��׼MIB����Ȩ�� */
	UINT32	ulRfc1573Flag;			/* RFC1573��׼MIB����Ȩ�� */
	UINT32	ulRfc1643Flag;			/* RFC1643��׼MIB����Ȩ�� */
	UINT32	ulIeee8021PAEFlag;		/* Ieee8021PAE��׼MIB����Ȩ�� */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot��׼MIB����Ȩ�� */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI��׼MIB����Ȩ�� */
	UINT32	ulPrivateFlag;			/* ˽��MIB����Ȩ�� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSYSSNMPV2SETUP_T;

/* AC SNMP V3����*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulUserId;			/* �û�ID */
	CHAR	acUserName [32];	/* �û��� */
	UINT32	ulAuthProtocol;		/* ��ȨЭ�� */
	CHAR	acAuthKey[32];		/* ��Ȩ��Կ */
	UINT32	ulPrivProtocol;		/* ����Э�� */
	CHAR	acPrivKey[32];		/* ������Կ */
	UINT32	ulRfc1213Flag;		/* RFC1213��׼MIB����Ȩ�� */
	UINT32	ulRfc1573Flag;		/* RFC1573��׼MIB����Ȩ�� */
	UINT32	ulRfc1643Flag;		/* RFC1643��׼MIB����Ȩ�� */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE��׼MIB����Ȩ�� */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot��׼MIB����Ȩ�� */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI��׼MIB����Ȩ�� */
	UINT32	ulPrivateFlag;			/* ˽��MIB����Ȩ�� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSYSSNMPV3SETUP_T;

/* AC SNMP TRAP ���ñ�*/
typedef struct {
	UINT32	ulAcId;					/*	AC�豸ID	*/

	UINT32	ulTrapSvrId;
	UINT8	aucTrapIp[4];
	UINT32	ulTrapPort;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSYSTRAPSVRSETUP_T;

/* AC SNTP���������ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulSntpSwitch;			/* ����SNTP���������� */
	UINT32	ulUpdatePeriod;			/* ʱ���������*/

	UINT8	aucUpperSntpSvr1[4];	/*	�ϼ�SNTP������1*/
	UINT8	aucUpperSntpSvr2[4];	/*	�ϼ�SNTP������2*/
	UINT8	aucUpperSntpSvr3[4];	/*	�ϼ�SNTP������3*/
	UINT8	aucUpperSntpSvr4[4];	/*	�ϼ�SNTP������4*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACSNTPGLOBALSETUP_T;

/* AC LOG�������ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */

	UINT8	aucLogModule[64];	/*	ģ�鿪��	*/
	UINT32	ulLogToStdOut;		/*	�Ƿ��ӡ����׼���	*/
	UINT32	ulLogSvrNum;		/* Զ����־��������Ŀ*/
	UINT8	aaucLogSvrIp[4][4];	/*	��־������IP��ַ	*/
	UINT32	aulLogSvrPort[4];	/*	��־�������˿ں�	*/
	UINT32	ulLogTransType;		/*	��־��������	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACLOGSETUP_T;

/* AC LOG���������ñ�*/
typedef struct {
	UINT32	ulAcId;		/* �豸ID */

	UINT32	ulLogSvrSwitch;	/*	��־����������	*/
	UINT8	aucLogSvrIp[4];	/*	��־��������IP��ַ	*/
	UINT32	ulLogSvrPort;	/*	��־�������󶨶˿�	*/
	UINT32	ulLogBakDay;	/*	��־��������	*/
	UINT32	ulLogFileSize;	/*	��־�ļ���С	*/
	UINT32	ulLogCompress;	/*	�Ƿ�ѹ��	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACLOGSERVERSETUP_T;

/* AC֧�ֵ�AP����汾�б����ñ�*/
typedef struct {
	UINT32	ulAcId;

	CHAR	acDftApSwVersion[32];		/* ȱʡAP����汾*/
	
	CHAR	acSwVersion1[32];			/* AP����汾1 */
	CHAR	acSwVersion2[32];			/* AP����汾2 */
	CHAR	acSwVersion3[32];			/* AP����汾3 */
	CHAR	acSwVersion4[32];			/* AP����汾4 */
	CHAR	acSwVersion5[32];			/* AP����汾5 */
	CHAR	acSwVersion6[32];			/* AP����汾6 */
	CHAR	acSwVersion7[32];			/* AP����汾7 */
	CHAR	acSwVersion8[32];			/* AP����汾8 */
	CHAR	acSwVersion9[32];			/* AP����汾9 */
	CHAR	acSwVersion10[32];			/* AP����汾10 */
	CHAR	acSwVersion11[32];			/* AP����汾11 */
	CHAR	acSwVersion12[32];			/* AP����汾12 */
	CHAR	acSwVersion13[32];			/* AP����汾13 */
	CHAR	acSwVersion14[32];			/* AP����汾14 */
	CHAR	acSwVersion15[32];			/* AP����汾15 */
	CHAR	acSwVersion16[32];			/* AP����汾16 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACASSOCSWVERSETUP_T;

/* AC����˿����ñ�*/
typedef struct {
	UINT32	ulAcId;		/* �豸ID */
	
	UINT32	ulIfId;	/* �˿ں� */
	CHAR	acIfName[32];	/* �˿����� */
	UINT32	ulIfType;		/* �˿�����*/
	UINT32	ulRunMode;		/* �Ƿ����� */
	UINT32	ulSpeedUplex;	/* ����/˫��ģʽ */
	UINT32	ulMtu;			/* �Ƿ�Ϊ���ζ˿� */
	UINT32	ulVlanType;		/* VLAN����: 0:VLAN�ս� 1:VLAN͸�� 2:VLAN��װ*/
	UINT32	ulCapVlanId;		/* ��װVLAN ID */
	CHAR	acDesc[64];	/* �˿�������Ϣ*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIFSETUP_T;

/*�˿�IP��ַ���ñ�*/
typedef struct {
	UINT32	ulAcId;

	UINT32	ulFitLanIpNum;				/* FIT-LAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucFitLanIp[8][4];			/* FIT-LAN IP��ַ*/
	UINT8	aaucFitLanNetMask[8][4];		/* FIT-LAN IP��������*/

	UINT32	ulFatLanIpNum;					/* FAT-LAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucFatLanIp[32][4];				/* FAT-LAN IP��ַ*/
	UINT8	aaucFatLanNetMask[32][4];		/* FAT-LAN IP��������*/

	UINT32	ulL2WanIpNum;					/* L2-WAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucL2WanIp[8][4];				/* L2-WAN IP��ַ*/
	UINT8	aaucL2WanMask[8][4];		/* L2-WAN IP��������*/

	UINT32	ulL3WanIpNum;					/* L3-WAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucL3WanIp[8][4];				/* L3-WAN IP��ַ*/
	UINT8	aaucL3WanMask[8][4];		/* L3-WAN IP��������*/

	/* 2011-6-2 pyy �����޸�*/
	UINT32	ulMsIpNum;					/* ����ͨ��IP��ַ��Ŀ*/
	UINT8	aaucMsIp[8][4];				/* ����IP��ַ*/
	UINT8	aaucMsMask[8][4];			/* ����*/

	UINT8	aucDefaultGw[4];					/* ȱʡ����*/
	UINT8	aucPrimaryDns[4];				/* ����DNS������*/
	UINT8	aucSecondaryDns[4];				/* ����DNS������*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIPSETUP_T;

/* AC DHCP for STA �������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulEnableDhcpServer;			/*	DHCP���ܽ�ɫ*/		
	UINT32	ulEnableDhcpSnooping;		/*	����DHCP Snooping����*/
	UINT32	ulEnableOption60;		/* add by gwx 2013-3-12 for task532 option 60���أ�0:�ر�1:����*/
	UINT8	aucDhcpServerMaster[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucDhcpServerSlave[4];		/*	��DHCP�м̷�������ַ*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPGLOBALSETUP_T;

/* AC DHCP for STA ��̬��IP���ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	CHAR	acDescr[32];				/* ���ڱ�ʶ����*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T;

/* AC DHCP for STA ��̬IP��ַ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulId ;						/* ��ַ�ر�� */
	CHAR    	acIpPoolNAme[32]	    	;   	/* ����                     */
	UINT8   	aucBeginIp[4]	        		;   	/* ��ʼ��ַ                 */
	UINT8   	aucEndIp[4]	            		;   	/* ������ַ                 */
	UINT8   	aucMask[4]	            		;   	/* ����                     */
	UINT8	aucReservedIp1[4];				/* ����IP��ַ1 */
	UINT8	aucReservedIp2[4];				/* ����IP��ַ2 */
	UINT8	aucReservedIp3[4];				/* ����IP��ַ3 */	
	UINT8	aucReservedIp4[4];				/* ����IP��ַ4 */	
	UINT32  	ulLease                 		;   		/* ��Լ���� ��λ����        */
	CHAR    	acDomainName[256]	    	;   		/* ������׺                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* ��������IP��ַ           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpSlave[4]    	;  		/* ��������IP��ַ           */

	CHAR	acVendorName[64];		/* add by gwx 2013-3-12 for task532 ��������Ϣ*/
	UINT32	ulVlanId1;						/* ��VLAN 1: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId2;						/* ��VLAN 2: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId3;						/* ��VLAN 3: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId4;						/* ��VLAN 4: 0~4094 0��ʾ����������VLAN */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T;

/* AC DHCP for AP �������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulEnableDhcpServer;			/*	DHCP���ܽ�ɫ*/		
	UINT32	ulEnableDhcpSnooping;		/*	����DHCP Snooping����*/
	UINT32	ulEnableOption43;			/*	����Option 43����*/
	UINT32	ulEnableOption60;		/* add by gwx 2013-3-12 for task532 option 60���أ�0:�ر�1:����*/
	UINT8	aucDhcpServerMaster[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucDhcpServerSlave[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucAcIpMaster[4];			/*	��AC��ַ*/
	UINT8	aucAcIpSlave[4];				/*	��AC��ַ*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPGLOBALSETUP_T;

/* AC DHCP for AP ��̬��IP���ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	CHAR	acDescr[32];				/* ������Ϣ*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T;

/* AC DHCP for AP ��̬IP��ַ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulId ;						/* ��ַ�ر�� */
	CHAR    	acIpPoolNAme[32]	    	;   	/* ����                     */
	UINT8   	aucBeginIp[4]	        		;   	/* ��ʼ��ַ                 */
	UINT8   	aucEndIp[4]	            		;   	/* ������ַ                 */
	UINT8   	aucMask[4]	            		;   	/* ����                     */
	UINT8	aucReservedIp1[4];				/* ����IP��ַ1 */
	UINT8	aucReservedIp2[4];				/* ����IP��ַ2 */
	UINT8	aucReservedIp3[4];				/* ����IP��ַ3 */	
	UINT8	aucReservedIp4[4];				/* ����IP��ַ4 */	
	UINT32  	ulLease                 		;   		/* ��Լ���� ��λ����        */
	CHAR    	acDomainName[256]	    	;   		/* ������׺                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* ��������IP��ַ           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* ����DNS������IP��ַ      */
	CHAR	acVendorName[64];		/* add by gwx 2013-3-12 for task532 ��������Ϣ*/

	UINT32	ulVlanId1;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId2;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId3;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId4;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	/* add by gwx 2012-9-12 ����������ͨ���ⳡ����
	ʹ��һ̨AC��ΪDHCP server��Ϊ��̨AC��AP�����ַ*/
	UINT8	aucAcIpMaster[4];			/*	��AC��ַ*/
	UINT8	aucAcIpSlave[4];				/*	��AC��ַ*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T;

/* VLAN ȫ�����ñ�*/
typedef struct 
{
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulRoamSwitch;			/* VLAN ���ο���*/
	UINT32	ulTime;					/* VLAN�����ϻ�ʱ��*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANGLOBALSETUP_T;

/* AC VLAN���ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulVlanId;				/* VLAN ID */
	CHAR	acVlanName[32];			/* VLAN����*/
	UINT32	ulVlanEnable;			/* add by gwx 2014-7-11 for dlink, vlan���ÿ��ع�*/
	UINT32	ulVlanForFitLan;			/*	FIT-LAN�˿�������	*/
	UINT32	ulVlanForFatLan;			/*	FAT-LAN�˿�������	*/
	UINT32	ulVlanForL2Wan;			/*	L2-WAN�˿�������	*/
	UINT32	ulVlanForL3Wan;			/*	L3-WAN�˿�������	*/
	UINT32	ulEnableIsolate;			/* �û����� */
	UINT32	ulVlanPrio;				/* VLAN���ȼ�*/
	CHAR	acNasId[32];				/* �ȵ�IP */
	CHAR	acDefaultSsid[32];		/* Ĭ��SSID */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANSETUP_T;

/* AP IP����-VLANӳ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT8	aucIp[4];				/*	IP��ַ*/
	UINT8	aucMask[4];				/* 	����	*/

	UINT32	ulVlanId;				/* VLAN ID */
		
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T;

/* SSID-VLANӳ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	CHAR	acSsid[32];				/* SSID */
	UINT32	ulVlanId;				/* VLAN ID */
		
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T;

/*AC  �˿�-VLANӳ�����ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulDevId;				/* �豸ID */
	UINT32	ulIfId;				/* �˿�ID */
	UINT32	ulVlanId;			/* VLAN ID */
	UINT32	ulVlanIfType;		/* VLAN�˿�����*/
	UINT32	ulNestVlanId;		/*add by gwx 2014-7-11 for dlink, ���vlan id */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIFVLANMAPPINGSETUP_T;

/* AC MAC-VLANӳ�����ñ�*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */
	
	UINT8	aucMac[6];			/* MAC��ַ */
	UINT8	aucRsv[2];			/* ����ֶ� */
	UINT32	ulVlanId;				/* VLAN ID */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACMACVLANMAPPINGSETUP_T;


/* WAPI AS����������*/
typedef struct 
{
	UINT32	ulAcId;				/* �豸ID */
	
	UINT8   acAsIp[4]; 				/*	AS������IP  */
	UINT32  ulAsPort;   				/*	AS������Port	*/
	UINT32  ulAsAuthCert;   			/*		AS֤����֤	0������ 1������*/
	UINT32  ulCertFileSize; 			/*		AS֤���ļ���С	*/
	UINT8   aucCertFileContent[4096];  /*	AS֤���ļ�����	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPIASSETUP_T;

/* WAPI ��������*/
typedef struct 
{
	UINT32	ulAcId;				/* �豸ID */
	
	UINT32  ulWapiSetupId;  				/*		WAPI����ID	0��15 */
	CHAR    acWapiSetupName[32];     		/*	    WAPI��������	*/
	UINT32  ulWapiCertAkm; 			 	/*		֤����AKM	0������ 1������ */
	UINT32  ulWapiPskAkm;   				/*		Ԥ������ԿAKM	0������ 1������ */
	UINT32  ulWapiPreAuth; 				/*		WAPIԤ��Ȩ	0������ 1������ */
	UINT32  ulUnicastCipher;    			/*		���������׼�	1��SMS4 */
	UINT32  ulUnicastKeyLen;    			/*		������Կ����	256 */
	UINT32  ulUnicastKeyUpdateManner;   	/*		������Կ���»���	1��������
						                                    2������ʱ��
						                                    3�����ڰ���
						                                    4������ʱ��Ͱ���
						                                    */
	UINT32  ulUnicastKeyValidity;       		/*		������Կ��������	>0 */
	UINT32  ulUnicastKeyPkgs;       		/*	    ������Կ���°���Ŀ	>0 */
	UINT32  ulMulticastCipher;         		 /*		�鲥�����׼�	1��SMS4 */
	UINT32  ulMulticastKeyLen;          		/*		�鲥��Կ����	256 */
	UINT32  ulMulticastKeyUpdateManner; 	/*		�鲥��Կ���»���	1��������
					                                            2������ʱ��
					                                            3�����ڰ���
					                                            4������ʱ��Ͱ���
					                                    */
	UINT32  ulMulticastKeyValidity;     		/*		�鲥��Կ��Чʱ��	>0 */
	UINT32  ulMulticastKeyPkgs;     		/*	    �鲥��Կ��Ч����	>0 */
	UINT32  ulMulticastRekeyStrict; 		/*  	STA�뿪BSS������鲥��Կ	0������ 1������ */
	UINT32  ulAuthRetryTimes;		    	/*      ��Ȩ����Э�����Դ���	>0 */
	UINT32  ulMulticastRekeyRetryTimes;	/*		�鲥��Կ����Э�����Դ���	>0 */
	UINT32  ulUnicastRekeyRetryTimes;   	/*		������Կ����Э�����Դ���	>0 */
	UINT32  ulBasicKeyValidity;     			/*	    ����Կ��Ч��	>0  */
	UINT32  ulBasicKeyReAuthThreshold;  	/*		����Կ���¼�Ȩ������ʱ��	0-100 */
	UINT32  ulSecAssociateTimeout;		/*      ��ȫ�����ĳ�ʱʱ��	>0 */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPISETUP_T;

/* WAPI ֤������*/
typedef struct 
{
	UINT32	ulAcId;						/* �豸ID */
	
	UINT32  	ulCertId;           				/*	֤��ID */
	CHAR    	acCertDesc[128];    			/*	֤������ */
	UINT32  	ulCertFileSize; 				/*	֤���ļ���С */
	UINT8   	aucCertFileContent[4096];   	/*	֤���ļ����� */
	UINT8   	aucBindMac[6];  	        		/* ֤��󶨵�MAC��ַ */
	UINT8   	aucRsv[2];                  		/* ����ֽ� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWAPICERTFILESETUP_T;


/* AC AAA���ñ�*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	UINT8   	aucAuthSrvAddrMaster[4];
    	UINT32  	ulAuthSrvPortMaster;
    	CHAR    	acAuthSrvSecretMaster[32];
    	UINT8   	aucAuthSrvAddrSlave[4];
    	UINT32    ulAuthSrvPortSlave;
    	CHAR      acAuthSrvSecretSlave[32];
    	UINT8     aucAcctSrvAddrMaster[4];
    	UINT32    ulAcctSrvPortMaster;
    	CHAR      acAcctSrvSecretMaster[32];
    	UINT8     aucAcctSrvAddrSlave[4];
    	UINT32    ulAcctSrvPortSlave;
    	CHAR      acAcctSrvSecretSlave[32];
    	UINT32    ulRetryPrimaryInterval;
    	UINT32    ulAcctInterimInterval;    
	UINT32	ulAuthEchoInterval;
	UINT8	aucNasIp[4];					/* NAS IP */
	UINT32	acIsIncludeSuffix;		/* radius�Ƿ�����û�����׺����0:����1:������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAAASETUP_T;

/* ����֤ȫ������*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulFreeSwitch;		/* ȫ������֤���� 0:���� 1:���� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACFREEGLOBALSETUP_T;

/* ����֤IP��ַ�б�����*/
typedef struct {
	UINT32	ulAcId;	/*	�豸ID	*/

	UINT8	aucIp[4];	/*	�û�IP��ַ	*/
	UINT8	aucMask[4];	/*	����*/
	
	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
}AC_DB_TBL_ACFREEIPSETUP_T;

/* ����֤MAC�б�����*/
typedef struct {
	UINT32	ulAcId;	/*	�豸ID	*/

	UINT8	aucMac[6];		/*	�û�MAC��ַ	*/
	UINT8	aucRsv[2];		/*	reserve	*/
	
	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
}AC_DB_TBL_ACFREEMACSETUP_T;

/* ����֤SSID�б�*/
typedef struct {
	UINT32	ulAcId;	/*	�豸ID	*/

	CHAR	acSsid[32];	
	
	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
}AC_DB_TBL_ACFREESSIDSETUP_T;

/* ����֤VLAN�б�*/
typedef struct {
	UINT32	ulAcId;	/*	�豸ID	*/

	UINT32	ulVlan;
		
	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
}AC_DB_TBL_ACFREEVLANSETUP_T;

/* 2011-8-8 pyy add MAC��֤ȫ������*/
typedef struct
{
	UINT32	ulAcId;				/*	�豸ID */
	UINT32	ulMacSwitch;			/*	MAC��֤����*/
	UINT8	aucMacSrvAddr[4];	/*	MAC��֤������IP */
	UINT32	ulMacSrvPort;		/*	MAC��֤�������˿�*/
	UINT32	ulTrafficTime;			/*	MAC��֤����ʱ��*/
	UINT32	ulTrafficThresh;		/*	MAC��֤��������*/
	UINT32	ulMOC;				/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	����ʵ����ʶ*/
} AC_DB_TBL_ACMACSERVERSETUP_T;

/* WEB��֤ȫ������*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulPortalEnable;		/* ǿ��WEB��֤ 0:���� 1:���� */
	UINT8	aucPortalIp[4];		/* Portal������IP */
	CHAR	acPortalURL[64];		/* Portal������URL */
	UINT32	ulPortalPort;			/* Portal����˿ں�*/
	UINT32	ulConcurrentAuthMaxNum;		/*		��󲢷���֤��Ŀ*/
	UINT32	ulReauthTimeout;				/* ����֤��ʱ ��λ:��*/
	UINT32	ulNoTrafficTime;					/* �Ự����ʱ��	��λ:��*/
	UINT32	ulTrafficMin;			/* add by gwx 2011-10-31 for �㶫�ƶ����Ự������������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACPORTALSETUP_T;

/* Portal����������*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulWhiteId;			/*	������ID */
	UINT8	aucWhiteIp[4];		/* IP��ַ*/
	UINT8	aucWhiteIpMask[4];	/*	����*/
	UINT16	usWhiteProto;		/*	Э��*/
	UINT16	usWhitePort;			/* �˿�*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWHILTELISTSETUP_T;

/* ������URL���ñ�*/
typedef struct {		
	UINT32	ulAcId;				/* �豸ID */

	UINT32	ulWhiteId;			/*	������ID */
	UINT8	aucWhiteUrl[64];		/* ������URL */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACWHITEURLLISTSETUP_T;


/* �û�����ַ������*/
typedef struct {
	UINT32	ulAcId;				/*	�豸ID	*/
	UINT32	ulIndex;				/*	������	*/
	CHAR	acUserName[64];		/*	�û���	*/
	UINT8	aucUserIp[4];		/*	�û�IP��ַ	*/
	UINT8	aucUserMac[6];		/*	�û�MAC��ַ	*/
	UINT8	aucRsv[2];			/*	reserve	*/
	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
} AC_DB_TBL_ACUSERADDRBINDSETUP_T;





/* SSID��֤����*/
typedef struct {
	UINT32	ulAcId;

	CHAR	acSsid[32];		/* SSID */
	CHAR	acUserNameSuffix[64];	/* add by gwx 2011-11-11�û�����׺*/
	UINT32	acIsIncludeSuffix;		/* radius�Ƿ�����û�����׺����0:����1:������*/
	UINT8	aucPortalIp[4];	/* Portal������IP��ַ*/
	CHAR	acPortalURL[64];	/* Portal������URL */
	UINT32	ulPortalPort;		/* Portal�������˿�*/

	UINT8   	aucAuthSrvAddrMaster[4];
    	UINT32  	ulAuthSrvPortMaster;
    	CHAR    	acAuthSrvSecretMaster[32];
    	UINT8   	aucAuthSrvAddrSlave[4];
    	UINT32    ulAuthSrvPortSlave;
    	CHAR      acAuthSrvSecretSlave[32];
    	UINT8     aucAcctSrvAddrMaster[4];
    	UINT32    ulAcctSrvPortMaster;
    	CHAR      acAcctSrvSecretMaster[32];
    	UINT8     aucAcctSrvAddrSlave[4];
    	UINT32    ulAcctSrvPortSlave;
    	CHAR      acAcctSrvSecretSlave[32];
    	UINT32    ulRetryPrimaryInterval;
    	UINT32    ulAcctInterimInterval;    
	UINT32	ulAuthEchoInterval;
	UINT8	aucNasIp[4];					/* NAS IP */
	/*add by gwx 2011-10-31 for �㶫�ƶ�begin */
	UINT32	ulNoTrafficTime;		/* �Ự����ʱ�� */
	UINT32	ulTrafficMin;			/* �Ự������������	*/
	/*add by gwx 2011-10-31 for �㶫�ƶ�end */

	UINT32	ulMOC;				/*	�������ʶ	*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	 ����ʵ����ʶ	*/
} AC_DB_TBL_ACSSIDAUTHSETUP_T;

/* AC PPPoE���ñ�*/
typedef struct {
	UINT32	ulAcId;		/* �豸ID */
	
	UINT32	ulEnablePPPoEServer;	/* 	����PPPoE����������*/
	CHAR	acPPPoEServerName[32];	/* 	PPPoE����������	*/
	UINT8	aucPPPLocalIp[4];		/*	PPP���ӵı���IP	*/
	UINT8	aucIpPoolStartIP[4];		/*	��ַ����ʼ��ַ	*/
	UINT8	aucIpPoolEndIP[4];		/*	��ַ����ʼ��ַ	*/
	UINT8	aucPrimaryDNS[4];		/*	����DNS ��������ַ	*/
	UINT8	aucSlaveDNS[4];			/*	����DNS ��������ַ	*/
	UINT32	ulAuthMode;				/*	��Ȩ��ʽ	*/
	UINT32	ulPPPMtu;				/* PPP���ӵķ��͵�Ԫ��С*/
	UINT32	ulPPPMru;				/*	PPP���ӵĽ��յ�Ԫ��С	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACPPPOESETUP_T;

/* AC��̬·�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32	ulRouteId;
	
	UINT8	aucDestIp[4];	/* Ŀ��IP���� */
	UINT8	aucNetMask[4];	/* ����*/
	UINT8	aucGw[4];		/* ���� */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSTATICROUTESETUP_T;

/* AC RIPЭ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulRipSwitch ;				/* �Ƿ�����RIPЭ�� */
	UINT32	ulIfType;				/*	����ģʽ		0����1����*/
	UINT32	ulAuthType;				/*	��Ȩģʽ		0�������ü�Ȩ
															1��text����ģʽ
															2��MD5ģʽ
															*/
	CHAR	acKey[72];				/*	��Կ*/
	UINT32	ulSendVersion;			/*	���Ͱ汾��
									0��V1/V2ģʽ����
									1��V1ģʽ����
									2��V2ģʽ����*/
	UINT32	ulRecvVersion;			/*	���հ汾��
									0��V1/V2ģʽ����
									1��V1ģʽ����
									2��V2ģʽ����
									*/

	UINT32	ulSplitHorizonOn ;		/* �Ƿ�����ˮƽ�ָ� */
	UINT32	ulRedistributeStatic ; 	/* �Ƿ��طַ���̬·�� */
	UINT32	ulRedistributeKernal ;	/* �Ƿ��طַ�����·�� */
	UINT32	ulUpdate ;				/* Update��ʱ�� */
	UINT32	ulTimeout ; 				/* Timeout��ʱ�� */
	UINT32	ulGarbage ; 				/* Garbage��ʱ�� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACRIPGLOBALSETUP_T;

/* AC RIP��ͨ������*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT8	aucNetIp[4];			/* IP���� */
	UINT8	aucNetMask[4];		/* ����*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACRIPANNOUNCENETSETUP_T;


/* AC NATȫ�����ñ�*/
typedef struct {
	UINT32	ulAcId;		/*	�豸ID	1~32*/
	UINT32	ulNatSwitch;	/*	NAT����		0������1������*/
	UINT32	ulNatDefaultRuleOn;	/*	�Ƿ�����ȱʡNAT����		0������1������*/
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNATGLOBALSETUP_T;

/* AC NAT���ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32   ulNatId;                  
	UINT32	ulNatAction;		/*	NAT����
							0-2
							0������NAT
							1���˿�NAT
							2������IP͸��*/
	/* add by gwx 2013-12-10 for task1173 */
	UINT32	ulNatOutIfType;	/*NAT���˿�����0:br0 2:br2*/
							
	UINT8	aucSrcIp[4];			/*	����IP ��ַ		��*/
	UINT8	aucSrcIpMask[4];		/*	����IP����		��*/
	UINT8	aucNatIpBegin[4];	/*	��ʼ����IP��ַ		��*/
	UINT8	aucNatIpEnd[4];		/*	��������IP��ַ		��*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNATSETUP_T;

/* AC  MAC��ַ���˲��� */
typedef struct {
	UINT32	ulAcId;				/* �豸ID */
	
	UINT32	ulVlanId;				/* VLAN ID */
	UINT32	ulMacFilterSwitch;		/* MAC���˹��ܿ���*/
	UINT32	ulMacFilterType;			/* MAC��������*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T;

/* AC  MAC��ַ�б� */
typedef struct {
	UINT32	ulAcId;				/* �豸ID */
	
	UINT32	ulVlanId;				/* VLAN ID */
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T;

/* ACLȫ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32	ulAclSwitch;				/* ACL����: 0���� 1����*/
	UINT32	ulAclDefaultAction;		/* ACLĬ�ϲ���0���� 1����*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLGLOBALSETUP_T;


/* ACL����������ñ�*/
typedef struct {
	UINT32		ulAcId;					/* �豸ID */

	/* ƥ��ԭ��*/
	UINT32		ulRuleId				;	/* �����				*/
	UINT32		ulChildRuleId;			/* ���������*/
	CHAR		acComment[32]		;	/* �Ը÷������Ľ���	*/
	UINT32		ulRuleOn;				/* �����Ƿ�����*/
	UINT32  		ulChainId			;	/* ��������0:�������ʹ��� 1:ת������ */

	UINT32  		ulSrcIpMatchType	;	/* ԴIPƥ����� 0:��ƥ�� 1:����ƥ�� 2:����ƥ��*/
	UINT8		aucSrcIp[4]			;	/* ԴIP��ַ			    */
	UINT8		aucSrcIpMask[4]		;	/* ԴIP��ַ������		*/
	UINT32  		ulDstIpMatchType	;	/* Ŀ��IPƥ����� 0:��ƥ�� 1:����ƥ�� 2:����ƥ��*/
	UINT8		aucDstIp[4]			;	/* Ŀ��IP��ַ			*/
	UINT8		aucDstIpMask[4]		;	/* Ŀ��IP��ַ������	    */

	UINT32		ulIfMatchType;			/* �ӿ�ƥ�����
										0: ��ƥ�� 1:��ӿ�ƥ�� 2:���ӿ�ƥ�� 3:ͬʱƥ��*/
	
	UINT32  		ulInIfId				;	/* ��ӿ�				*/
	UINT32  		ulOutIfId			;	/* ���ӿ�				*/



	UINT32	ulRuleProtocol;	/*	����Э��ƥ��		
								0������Э��     
								1��ICMP   
								2��IGMP  
								6��TCP    
								17��UDP  
								47��GRE  
								94��IPIP  
								115��L2TP
								132��SCTP
								*/

	UINT32	ulSrcPortMatchPolicy;	/*	Դ�˿�ƥ�����		0����ƥ��
								1������ƥ��
								2������ƥ��
								*/
	UINT32	ulSrcPortBegin;		/*	��ʼԴ�˿�		1-65535 */
	UINT32	ulSrcPortEnd;		/*	����Դ�˿�		1-65535 */
	UINT32	ulDstPortMatchPolicy;	/*	Ŀ�Ķ˿�ƥ�����		
									0����ƥ��
									1������ƥ��
									2������ƥ��
									*/
	UINT32	ulDstPortBegin;		/*��ʼĿ�Ķ˿�		1-65535*/
	UINT32	ulDstPortEnd;		/*����Ŀ�Ķ˿�		1-65535*/
	CHAR	acSsid[32];			/* ƥ��SSID */
	CHAR	acUrl[64];			/* ƥ��URL */
	UINT32	ulMarkMatch;		/*	ƥ����ֵ	*/

	/*ƥ�䶯��*/
	UINT32	ulAction;		/*	����ִ�еĶ���	
								0������
								1������
								2�����ñ��ֵ
								*/
	UINT32	ulLogSet;		/*	����ִ����־	
								0���ر�
								1����
								*/
	UINT32	ulSetMark;		/*	���ñ��*/
		
	UINT32		ulMOC;
	UINT8		aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T;

/* AC IDS�������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32  	ulIcmpFlooding	        ;   /* ICMP�������		*/   
	UINT32  	ulIcmpStatInterval	;	        /* ICMPͳ�Ƽ��	 */
	UINT32 	ulIcmpFloodingThreshold;    	/* ICMP��������	*/
	
	UINT32  	ulArpFlooding	        ;   /* ARP������� 		*/   
	UINT32  ulArpStatInterval;  	/* ARPͳ�Ƽ�� */
	UINT32  ulArpFloodingThreshold;	/* ARP�������� */

	UINT32  	ulUDPFlooding	        ;   /* Udp�������	    		*/   
	UINT32  ulUDPStatInterval;	        /* UDPͳ�Ƽ��	 */
	UINT32  ulUDPFloodingThreshold;    /* UDP��������	*/

	UINT32  	ulTcpSynFlooding	    ;   /* TCPSYN ������� 	*/	
	UINT32  ulTcpSynStatInterval;	        /* TCP SYNͳ�Ƽ��	 */
	UINT32  ulTcpSynFloodingThreshold;    /* TCP SYN ��������	*/


	UINT32  	ulDetectUdpScan	    ;   /* UDP ɨ����		*/   
	UINT32  	ulDetectTcpScan	    ;   /* TCP ɨ����		*/   
	UINT32  	ulDetectInvalidMac	    ;   /* �Ƿ�MAC���	    	*/   
	UINT32  	ulDetectInvalidProto	;   /* �Ƿ�Э����		*/   
	UINT32  	ulDetectInvalidLength	;   /* �Ƿ����ĳ��ȼ��	*/	
	UINT32  ulDetectInvalidStatInterval;	/* �Ƿ�����ͳ�Ƽ��	*/
	UINT32  ulDetectInvalidThreshold;	    /* �Ƿ����Ĺ�������	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIDSRULESETUP_T;

/* AC IDS�������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32  	ulGenEvent	        		;   /* ���ָ澯			*/   
	UINT32  	ulDisableAccess	        	;   /* ��ֹ�����߽��� 		*/
	UINT32	ulLetOffPeriod;				/*  ���ʱ��*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIDSSTRATEGYSETUP_T;

/* AC P2P�������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32	ulP2PSwitch;		/*	P2P����		0������1������*/
	UINT32	ulBtCfg;			/*	BT����		0������1������*/
	UINT32	uleDonkeyCfg;	/*	eDonkey����	0������1������*/
	UINT32	ulAresCfg;		/*	Ares����	 	0������1������*/
	UINT32	ulFasttrackCfg;	/*	Fasttrack����	0������1������*/
	UINT32	ulGnutellaCfg;	/*	Gnutella����	0������1������*/
	UINT32	ulApplejuiceCfg;	/*	Applejuice����	0������1������*/
	UINT32	ulXunleiCfg;		/*	Xunlei����	 	0������1������*/
	UINT32	ulMuteCfg;		/*	Mute����		0������1������*/
	UINT32	ulSoulseak;		/*	Soulseek����	0������1������*/
	UINT32	ulPpliveCfg;		/*	PPLive����		0������1������*/
	UINT32	ulPpstreamCfg;	/*	PPStream����	0������1������*/
	UINT32	ulFreenetCfg;	/*	Freenet����	0������1������*/
	UINT32	ul100baoCfg;	/*	100bao���� 	0������1������*/
	UINT32	ulHotLineCfg;	/*	Hotline����	0������1������*/
	UINT32	ulGoboogyCfg;	/*	Goboogy����	0������1������*/
	UINT32	ulKugooCfg;		/*	Kugoo����		0������1������*/
	UINT32	ulPocoCfg;		/*	Poco����	 	0������1������*/
	UINT32	ulTeslaCfg;		/*	Tesla����		0������1������*/
	UINT32	ulSoribadaCfg;	/*	Soribada����	0������1������*/
	UINT32	ulMsnCfg;		/*	MSN����		0������1������*/
	UINT32	ulQQCfg;		/*	QQ����	 	0������1������*/
	UINT32	ulYahooCfg;		/*	Yahoo Messager����		0������1������*/
	UINT32	ulSkypeCfg;		/*	Skype����	 	0������1������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T;

/* AC QOSȫ�����ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulQosSwitch;				/* QOS���ع��ܿ���: 0/1  ����/����*/
	/* add by gwx 2014-6-5 for ticket52 */
	UINT32	ulUserGroupSwitch;	/* �û������ؿ���0:����1����*/
	UINT32	ulQosPrioSwitch;			/* QOS���ȼ����ܿ��أ�0/1  ����/���� */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACQOSGLOBALSETUP_T;

/* AC�û�QOSȱʡ����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T;

/* �û�QOS����*/
typedef struct 
{
	UINT32	ulAcId;

	UINT8	aucMac[6];					/* �û�MAC */
	UINT8	aucRsv[2];					/* ����ֶ�*/
	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACUSERQOSSETUP_T;

/* AC VLAN QOS����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulVlanId ;
	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVLANQOSSETUP_T;

/* AC SSID QOS����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulId ;
	CHAR	acSsid[32];
	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACSSIDQOSSETUP_T;

/* AC VAP QOS����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulWtpId;
	UINT32	ulVapId;
	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACVAPQOSSETUP_T;

/* AC AP QOS����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulWtpId;
	UINT32	ulUserPri;					/* �û����ȼ� */
	UINT32	ulUpBand;					/* �û����б�֤����*/
	UINT32	ulUpBandMax;				/* �û�����������*/
	UINT32	ulDownBand;					/* �û����б�֤����*/
	UINT32	ulDownBandMax;				/* �û�����������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACAPQOSSETUP_T;
/* AC IGMP SNOOPING ����*/
typedef struct {
	UINT32	ulAcId;				/* �豸ID */
	
	UINT32	ulIgmpSnoopSwitch;			/* �Ƿ���Ч */
	UINT32	ulRtPortTimer;				/* ·�����˿��ϻ���ʱ�� */
	UINT32	ulMemberPortTimer;			/* ��Ա�˿��ϻ���ʱ�� */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIGMPSNOOPSETUP_T;

/* AC IGMP PROXY ����*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */
	
	UINT32	ulIgmpProxy;			/* �Ƿ���Ч */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACIGMPPROXYSETUP_T;

/* 2010-1-18 pyy ����: AC �������ñ�*/
typedef struct {
	UINT32	ulAcId;		/*		�豸ID	1~32*/
	UINT32	ulMsMode;	/*		����ģʽ	0�������豸
								1������
								2������
								*/
	UINT32	ulEchoInterval;	/*		������
									��λ����	1~60*/
	UINT32	ulEchoNum;		/*		���ʱ����	1~60 */
	UINT32	ulBakAcNum;	/*		����AC��Ŀ	0��3*/
	UINT32	ulPeerAcId1;		/*		�����豸1 ID	1~32*/
	UINT8	aucPeerAcIp1[4];	/*		�����豸1 IP	��*/
	UINT8	aucPeerAcGw1[4];	/* �����豸1ȱʡ����*/
	UINT8	aucPeerAcMngIp1[4];		/* add by gwx 2011-10-28 for �����ƶ��������豸1����IP */
	UINT32	ulPeerAcState1;	/*		�����豸1״̬	0:���� 1:���� */

	UINT32	ulPeerAcId2;		/*		�����豸2 ID	1~32*/
	UINT8	aucPeerAcIp2[4];	/*		�����豸2 IP	��*/
	UINT8	aucPeerAcGw2[4];	/* �����豸2ȱʡ����*/
	UINT8	aucPeerAcMngIp2[4];		/* add by gwx 2011-10-28 for �����ƶ��������豸2����IP */
	UINT32	ulPeerAcState2;	/*		�����豸2״̬	0:���� 1:���� */
	
	UINT32	ulPeerAcId3;		/*		�����豸3 ID	1~32*/
	UINT8	aucPeerAcIp3[4];	/*		�����豸3 IP	��*/
	UINT8	aucPeerAcGw3[4];	/* �����豸3ȱʡ����*/
	UINT8	aucPeerAcMngIp3[4];		/* add by gwx 2011-10-28 for �����ƶ��������豸3����IP */
	UINT32	ulPeerAcState3;	/*		�����豸3״̬	0:���� 1:���� */
	
	UINT32	ulCurBakAcId;	/*		��ǰ�ӹܵ�AC ID	0����Чֵ
									1~32 */

	UINT32	ulEnableVrrp;		/*		VRRP����*/
	UINT8	aucVrrpIp1[4];		/*	����IP1 */
	UINT8	aucVrrpIp2[4];		/*	����IP2 */
	UINT8	aucVrrpIp3[4];		/*	����IP3 */
	UINT8	aucVrrpIp4[4];		/*	����IP4 */
	UINT8	aucVrrpIp5[4];		/*	����IP1 */
	UINT8	aucVrrpIp6[4];		/*	����IP2 */
	UINT8	aucVrrpIp7[4];		/*	����IP3 */
	UINT8	aucVrrpIp8[4];		/*	����IP4 */
	UINT8	aucVrrpIp9[4];		/*	����IP1 */
	UINT8	aucVrrpIp10[4];		/*	����IP2 */
	UINT8	aucVrrpIp11[4];		/*	����IP3 */
	UINT8	aucVrrpIp12[4];		/*	����IP4 */
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACMSSETUP_T;


/* AC  �澯�������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulAlarmNo;
	CHAR	acAlarmName[32];
	UINT32	ulAlarmIsValid;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACALARMFILTERSETUP_T;

/* AC  �澯�������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32  ulAlarmResendWaitingTime;		/* �澯�ط��ȴ�ʱ�� */
	UINT32  ulCpuLoadPeriod;    	/*		CPU���ɲ������� */
	UINT32  ulCpuLoadCount;     	/*		CPU���ɳ������� */
	UINT32  ulCpuLoadHigh;		/*      CPU���ɸ澯�������� */
	UINT32  ulCpuLoadLow;       	/*      CPU���ɸ澯�������� */
			
	UINT32  ulMemLoadPeriod;    	/*  	�ڴ������ʲ������� */
	UINT32  ulMemLoadCount;     	/*  	�ڴ������ʳ������� */
	UINT32  ulMemLoadHigh;      	/*  	�ڴ������ʸ澯�������� */
	UINT32  ulMemLoadLow;       	/*      �ڴ������ʸ澯�������� */
			
	UINT32  ulTempPeriod;       	/*	�豸�¶Ȳ������� */
	UINT32  ulTempCount;        	/*	�豸�¶ȳ������� */
	UINT32  ulTempHigh;        	 	/*	�豸�¶ȸ澯�������� */
	UINT32  ulTempLow;          	/*	�豸�¶ȸ澯�������� */

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACALARMTHRESHOLDSETUP_T;


/* AC���ܼ����������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT32	ulCounterGroupId;
	UINT32	ulCounterGroupIsInvalid;
    UINT32	ulCounterGroupPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T;

/* AP���ʲ������ñ�*/
typedef struct
{
	UINT32	ulAcId;			/* �豸ID */

	UINT32	ulFtp;
	UINT32	ulTelnet;
	UINT32	ulWeb;
	CHAR	acPasswd[32];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPACLSETUP_T;

/* AP�豸ID��-NAS IDӳ�����ñ�*/
typedef struct
{
	UINT32	ulAcId;			/* �豸ID */

	UINT32	ulApIdStart;		/*	��ʼAP�豸ID	*/
	UINT32	ulApIdEnd;		/*	����AP�豸ID	*/
	CHAR	acSsid[32];		/*	SSID	*/
	CHAR	acNasId[256];	/*	�ȵ�ID	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPIDNASSETUP_T;

/* AP IP����-NAS IDӳ�����ñ�*/
typedef struct
{
	UINT32	ulAcId;			/* �豸ID */

	UINT8	aucIp[4];		/*	IP��ַ	*/
	UINT8	aucMask[4];		/*	����	*/
	CHAR	acSsid[32];		/*	SSID	*/
	CHAR	acNasId[256];	/*	�ȵ�ID	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_ACAPIPNASSETUP_T;


/* ����Ϊ��̬��*/
/* �û����ϵ��ṹ�嶨��*/	
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];
    	CHAR    	acUserName[256];
    	UINT8    	aucIp[4];
    	UINT32	ulUserType;			/* �û�����*/
    	UINT32	ulPriority;			/* �û����ȼ� */
	UINT32	ulUpBandMax;		/* �û�������д��� */
	UINT32	ulUpBandMin;		/* �û���֤���д��� */
	UINT32	ulDownBandMax;		/* �û�������д��� */
	UINT32	ulDownBandMin;		/* �û���֤���д��� */
    
    	UINT32	ulWtpId;
    	UINT32	ulVDevId;
    	UINT32	ulIfId;
	UINT32	ulVapId;
	UINT8	aucVapMac[6];		/* ��ǰ�����VAP MAC */
	UINT8	aucRsv1[2];			/* ����ֽ�*/
	CHAR	acVapSsid[32];		/* ��ǰ�����VAP SSID */

	UINT8	aucNasIp[4];				/* NAS IP */
	CHAR	acNasId[256];			/* NAS ID */
	UINT32	ulAcctInterimInterval;	/* �Ʒ���Ϣ�ϱ����*/
	UINT32	ulSessionTimeout;		/* �Ự��ʱʱ��*/
	UINT32	ulIdleTimeout;			/* add by gwx 2012-6-4 for bug1101 ����������ʱ��*/
	UINT32    ulAssocId ;  			
        
    	UINT32	ulPosX;
    	UINT32	ulPosY;

	UINT32	ulCertType;		/* ��֤����*/
    	UINT32	ulCertState;		/* ��֤״̬*/
    	UINT32	ulCertStateOkTime;	/* ��֤״̬��Ϊ����֤��ʱ���*/
    	UINT32	ulVlanId;		/* �û�������VLAN ID */

    	UINT32	ulHandover;		/* 0:δ�л�	1:�л� */

    	UINT32	ulCreateTime;   	/* ���û�����ʱ�� */
    	UINT32  	ulUpdateTime;   	/* �û�ռ��ʱ��ͳ��������ʱ�� */

    	UINT32	ulSessionStartTime;	/* �Ự��ʼʱ��: ���ڼ��session timeout */

	/* ����ͳ����Ϣ*/
    	UINT32	ulRxBytes;		/* ��ǰ��ȡ��:���հ���*/
    	UINT32	ulTxBytes;		/* ��ǰ��ȡ��:���Ͱ���*/
    	UINT32	ulCheckTime;		/* �Ự����ʱ����ʱ��׼ʱ��*/
	UINT32	ulNoTrafficTime;		/* ���û��ĻỰ����ʱ����λΪ����*/
	UINT32	ulTrafficMin;			/* �û��Ự����ʱ���ڵ���������*/
	UINT32	ulWpaOffTag;		/* 1:�������쳣����0:��ʼ��ֵadd by gwx 2012-2-2*/

    	/* 2011-8-9 pyy add: MAC��֤����*/
    	UINT32	ulMacState;			/* MAC��֤״̬: δ��֤/����֤*/
    	CHAR	acUserAgent[256];		/* User Agent */
    	UINT32	ulCurRxBytes;		/* �����ֽ���*/
    	UINT32	ulCurTxBytes;		/* �����ֽ���*/

    	UINT32	ulLastStatRxBytes;	/* ���һ��MAC��֤�������ڵĽ����ֽ���*/
    	UINT32	ulLastStatTxBytes;	/* ���һ��MAC��֤�������ڵķ����ֽ���*/
    	UINT32	ulLastStatTime;		/* ���һ��MAC��֤�������ڵ��ֽ�������ʱ��*/

	/* add by gwx 2012-10-31 for �û�������׼ȷ*/
	UINT32	ulUserRxPkts;		/* �û������а���*/
	UINT32	ulUserTxPkts;		/* �û������а���*/
	UINT32	ulUserCurRx4GB;		/* �û�������������λ*/
	UINT32	ulUserCurRxBytes;	/* �û���������*/
	UINT32	ulUserCurTx4GB;		/* �û�������������λ*/
	UINT32	ulUserCurTxBytes;	/* �û���������*/
	/* add by gwx 2011-11-2 */
	UINT32	ulAuthType;			/* �û���֤����*/
	/* add by gwx 2013-10-14 for task1076 ��ҵ���û�������*/
#if 0
	UINT32	ulUserGroupId;		/* �û���ID */
#else
	CHAR	acUserGroupName[128];	/* �û�����*/
#endif
	/* add by gwx 2014-5-13 for ��ݣ�AP�ϱ��û���Ϣ*/
	UINT32	ulUserRssi;
	/* add by gwx 2014-9-3 ����ն��豸����*/
	CHAR	acStaType[32];
    	
}AC_DB_TBL_ACUSER_T;

/* �û�VLAN ���α�*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

    	UINT32	ulWtpId;
    	UINT32	ulVDevId;
    	UINT32	ulIfId;
	UINT32	ulVapId;
	CHAR	acSsid[32];
	
    	UINT32	ulVlanId;		/* ����VLAN ID */
    	UINT32	ulCreateTime;   	/* ������ʼʱ��*/
}AC_DB_TBL_ACUSERVLAN_T;

/* �ϱ��¼���¼��ϵ��ṹ�嶨��*/
typedef struct {
	UINT32 	ulEventId;
	UINT32	ulEventReasonId;
	UINT32 	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
	UINT32 	ulCommonInfo;
	UINT32	ulEventRaiseTime;
} AC_DB_TBL_ACDYNEVENT_T;

/* IDS�������û���ϵ��ṹ�嶨��*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

    	UINT32	ulCreateTime;   	/* ���û�����ʱ�� */
    	UINT32	ulUpdateTime;	/* �û�����ʱ��*/
    	UINT32	ulReason;		/* ���û������������ԭ��*/
} AC_DB_TBL_ACIDSUSER_T;

/* �û�Portal ��֤״̬��ϵ��ṹ�嶨��*/
typedef struct {
	UINT8    	aucMac[6];
    	UINT8    	aucRsv[2];

	UINT32	ulCertType;
    	UINT32	ulPortalState;		/* Portal��֤״̬*/
    	UINT32	ulMacState;	
    	UINT32	ulCreateTime;   	/* ������ʼʱ��*/

    	CHAR    	acUserName[256];	/* 2009-11-17 pyy �����û���*/
    	CHAR	acSsid[32];
	UINT32   ulSessionTimeout;    /**  Ϊ��ʹ�û���session-timeout��Ϣ���Ա��̳У�chary��2011.6.20   **/
	UINT32 	ulIdleTimeout; 	/* add by gwx 2012-6-4 for bug1101 ����������ʱ��*/
	/* add by gwx 2011-11-16 */
	UINT32   ulWtpId;
	UINT32   ulDevId;
	UINT32   ulVapId;
	UINT32   ulCertStateOkTime;
	
	UINT32	ulAuthType;			/* add by gwx 2012-3-21 for �ƶ��Զ���֤����*/
#if 0
	UINT32	ulUserGroupId;		/* add by gwx 2013-10-18 for task1076 ��ҵ���û�������*/
#else
	CHAR	acUserGroupName[128];
#endif
	UINT8	aucUserIp[4];	/* add by gwx 2014-4-15 for bug5293 */
} AC_DB_TBL_ACPORTALUSER_T;
/* ��ʷ�ն˽�����Ϣ��ϵ��ṹ�嶨��*/
/* �ؼ���ΪMac+WtpId+VapId */
typedef struct
{
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32	ulWtpId;
	UINT32	ulVapId;
	UINT32	ulOnlineTime;
} AC_DB_TBL_ACUSERACCINFO_T;

/* �ն�IP������Ϣ��ϵ��ṹ�嶨��*/
/* �ؼ���ΪaucIp */
typedef struct
{
	UINT8	aucIp[4];	/* IP */
	UINT8	aucMac[6];	/* ���һ�η��䵽���IP��ַ���ն˵�MAC��ַ*/
	UINT8	aucRsv[2];	/* ����ֽ�*/
	UINT32	ulWtpId;		/* ���һ�η��䵽���IP��ַ���ն˽����AP�豸ID */
	UINT32	ulVapId;		/* ���һ�η��䵽���IP��ַ���ն˽����VAP ID */
	CHAR	acVapSsid[32];
	UINT32	ulTime;		/* ���һ�����IP��ַ�������ʱ���*/
	UINT32	ulAcLanId;	/* AC �˿� 0~15 ��ʾLANx >=16 ����ʾN/A*/
} AC_DB_TBL_ACUSERIPINFO_T;

/* 2011-1-12 pyy add : ��ʷ�ն˱�*/
typedef struct
{
	UINT32	ulWtpId;
	UINT8	aucMac[6];	/* ���һ�η��䵽���IP��ַ���ն˵�MAC��ַ*/
	UINT8	aucRsv[2];	/* ����ֽ�*/
} AC_DB_TBL_ACHISTORYUSER_T;

/* add by gwx  2011-9-29 end*/
typedef	struct
{
	UINT32	ulAcId;			/*�豸ID */
	CHAR	acNasId[32];		/*�ȵ�ID*/
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACNASIDSETUP_T;
/* ssidMAC�������ñ�*/
typedef struct 
{
	UINT32	ulAcId;			/*�豸ID */
	CHAR	acSsid[32];			/*SSID*/
	UINT32	ulMacSwitch;			/*	MAC��֤����*/
	UINT8	aucMacSrvAddr[4];	/*	MAC��֤������IP */
	UINT32	ulMacSrvPort;		/*	MAC��֤�������˿�*/
	UINT32	ulTrafficTime;			/*	MAC��֤����ʱ��*/
	UINT32	ulTrafficThresh;		/*	MAC��֤��������*/
	UINT32	ulMOC;				/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];	/*	����ʵ����ʶ*/
}AC_DB_TBL_ACSSIDMACSERVERSETUP_T;

/* add by gwx 2013-10-11 for task1076 ��ҵ���û�����������*/
typedef struct 
{
	UINT32	ulAcId;					/*�豸ID */
	UINT32	ulUserGroupId;			/* �û���ID */
	CHAR	acUserGroupName[128];	/* �û�����*/
	/* add by gwx 2014-6-5 for ticket52 begin */
	UINT32	ulPriority;	/*�û���������ȼ�1-3 */
	UINT32	ulUserGroupUpBandMax;		/*�û������д������*/
	UINT32	ulUserGroupDownBandMax;	/* �û������д������*/
	/* add by gwx 2014-6-5 for ticket52 end */
	
	UINT32	ulMOC;					/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	����ʵ����ʶ*/
}AC_DB_TBL_ACUSERGROUPSETUP_T;


/* add by gwx 2014-6-25 for SSID���û����ƽ���begin */
typedef struct 
{
	UINT32	ulAcId;					/*�豸ID */
	UINT32	ulId;					/* ��¼ID */
	CHAR	acSsidName[32];			/* SSID ����*/
	UINT32	ulUserAccessCtrlType;	/* �������ģʽ����,��1/��0����ģʽ*/
	
	UINT32	ulMOC;					/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	����ʵ����ʶ*/
}AC_DB_TBL_ACSSIDACCESSSETUP_T;

typedef struct 
{
	UINT32	ulAcId;					/*�豸ID */
	UINT32	ulId;					/* ��¼ID */
	UINT8	aucUserMac[6];			/* �û�MAC(OUI) */
	UINT8	aucRsv[2];				/*  �����ֶ�*/
	CHAR	acSsidName[32];			/* SSID ����*/
	UINT32	ulOuiSwitch;				/* OUIģʽ���ÿ���0����1����*/
	UINT32	ulOuiLen;				/* OUI����ƥ��*/
	
	UINT32	ulMOC;					/*	�������ʶ*/
	UINT8	aucMOI[AC_MOI_LEN];		/*	����ʵ����ʶ*/
}AC_DB_TBL_ACSSIDACCESSLISTSETUP_T;

/* add by gwx 2014-6-25 for SSID���û����ƽ���end */

/* add by gwx 2011-11-2 for �㶫�ƶ�������AC��֤ͳ�Ʊ�*/
typedef struct
{
	UINT32	ulAcId;				/* �豸ID */
	UINT32 ulPortalAuthTime;			/*Portal��֤�ն˼�Ȩ����*/
	UINT32 ulAssociateAuthTime;         	/*������֤�ն˼�Ȩ����*/
	UINT32 ulMacAuthTime;				/*MAC��֤�ն˼�Ȩ����*/
#if 0
	UINT32 ulPortalAuthFailTime;        	 /*Portal��֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulAssociateAuthFailTime;		/*������֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulMacAuthFailTime;             /*MAC��֤�ն˼�Ȩʧ�ܴ���*/
#endif
	UINT32 ulPortalAuthSuccNum;	        /*Portal��֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulAssociateAuthSuccNum;	 	/*������֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulMacAuthSuccNum;	        /*MAC��֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulPortalOfflineUserNum;          	/*Portal��֤�û��쳣���ߴ���*/
	UINT32 ulFreeOfflineUserNum;            	/*����֤�û��쳣���ߴ���*/
	UINT32 ulAssociateOfflineUserNum;   		/*������֤�û��쳣���ߴ���*/
	UINT32 ulMacOfflineUserNum; 				/*MAC��֤�û��쳣���ߴ���*/
}AC_DB_TBL_ACAUTHSTAT_T;


/* add by gwx 2012-11-2 for �û�������׼ȷ
�����û���ʱ����*/
typedef struct
{
	UINT8	aucMac[6];						/* �û�MAC */
	UINT8	aucRsv[2];
	UINT32 	ulWtpId;
	UINT32	ulDelRecTag;					/* ��¼ɾ�����*/
	UINT32	ulStartTrafficTimerId;			/* ��ʼͳ�������Ķ�ʱ��TimerId */
	UINT32 	ulStopTrafficTimerId;			/* ֹͣͳ�������Ķ�ʱ��TimerId */
	UINT32	ulStartTrafficMsgSendTimes;		/* ��ʼͳ��������Ϣ���ش����� */
	UINT32 	ulStopTrafficMsgSendTimes;		/* ֹͣͳ��������Ϣ���ش����� */
	/* add by gwx 2013-1-10 for task359 */
	UINT32	ulWaitStopGetTimerId;			/*  �ȴ�account  ��ȡstop������ʱ��*/
	UINT32	ulVlan;
	
	UINT32 	ulUserRxPkts;					/* �û����а��� */
	UINT32	ulUserTxPkts;					/* �û����а��� */
	UINT32	ulUserRx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulUserTxBytes;					/* �û���ǰ���������� */
	UINT32	ulUserTx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulUserRxBytes;					/* �û���ǰ���������� */

	UINT32 	ulUserHistoryRxPkts;					/* �û���ʷ���а��� */
	UINT32	ulUserHistoryTxPkts;					/* �û���ʷ���а��� */
	UINT32	ulUserHistoryRx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulUserHistoryTxBytes;				/* �û���ʷ�������� */
	UINT32	ulUserHistoryTx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulUserHistoryRxBytes;				/* �û���ʷ�������� */

	/* add by gwx 2013-3-27 for bug2244 begin*/
	UINT32 	ulLastUserRxPkts;					/*AP��һ���ϱ��� �û����а��� */
	UINT32	ulLastUserTxPkts;					/*AP��һ���ϱ��� �û����а��� */
	UINT32	ulLastUserRx4GB;					/*AP��һ���ϱ��� �����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulLastUserTxBytes;					/*AP��һ���ϱ��� �û���ǰ���������� */
	UINT32	ulLastUserTx4GB;					/* AP��һ���ϱ��ĳ����ֶ����ͷ�Χ�Ľ���λ */
	UINT32	ulLastUserRxBytes;					/* AP��һ���ϱ����û���ǰ���������� */

	UINT32 	ulBasicUserRxPkts;					/* �û����а���(����ֵ) */
	UINT32	ulBasicUserTxPkts;					/* �û����а���(����ֵ) */
	UINT32	ulBasicUserRx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ(����ֵ) */
	UINT32	ulBasicUserTxBytes;					/* �û���ǰ���������� (����ֵ)*/
	UINT32	ulBasicUserTx4GB;					/* �����ֶ����ͷ�Χ�Ľ���λ (����ֵ)*/
	UINT32	ulBasicUserRxBytes;					/* �û���ǰ�����������(����ֵ) */
	/* add by gwx 2013-3-27 for bug2244 end*/

}AC_DB_TBL_ACUSERTIMER_T;

/* AC  �������ñ�*/
typedef struct {
	UINT32	ulAcId;					/* �豸ID */

	UINT8	aucAcLinkIp[4];
    UINT8   aucAcMappingIp[4];
    
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_ACLINKIPLISTSETUP_T;
/* AC ��ϵ��ṹ�嶨�����*/
/******************************************************************************/


/******************************************************************************/
/* ����������ʼ*/
/* AC�������ñ�*/
extern DBHANDLE	ghAcBasicSetup;
extern DBHANDLE	gidxAcBasicSetup1;
extern DBHANDLE	gidxAcBasicSetup10;

/* AC�������ñ�*/
extern DBHANDLE	ghAcWtpAssociateSetup;
extern DBHANDLE	gidxAcWtpAssociateSetup1;
extern DBHANDLE	gidxAcWtpAssociateSetup2;
extern DBHANDLE	gidxAcWtpAssociateSetup10;

/* ������·������ñ�*/
extern DBHANDLE	ghAcKeeperSetup;
extern DBHANDLE	gidxAcKeeperSetup1;
extern DBHANDLE	gidxAcKeeperSetup10;

/* �ھӹ�ϵ���ñ�*/
extern DBHANDLE	ghAcNeighborSetup;
extern DBHANDLE	gidxAcNeighborSetup1;
extern DBHANDLE	gidxAcNeighborSetup2;
extern DBHANDLE	gidxAcNeighborSetup10;

/* SNMP V2����*/
extern DBHANDLE	ghAcSysSnmpV2Setup;
extern DBHANDLE	gidxAcSysSnmpV2Setup1;
extern DBHANDLE	gidxAcSysSnmpV2Setup10;

/* SNMP V3����*/
extern DBHANDLE	ghAcSysSnmpV3Setup;
extern DBHANDLE	gidxAcSysSnmpV3Setup1;
extern DBHANDLE	gidxAcSysSnmpV3Setup10;

/* SNMP TRAP ����*/
extern DBHANDLE	ghAcSysTrapSvrSetup;
extern DBHANDLE	gidxAcSysTrapSvrSetup1;
extern DBHANDLE	gidxAcSysTrapSvrSetup10;

/* SNTP����������*/
extern DBHANDLE	ghAcSntpGlobalSetup;
extern DBHANDLE	gidxAcSntpGlobalSetup1;
extern DBHANDLE	gidxAcSntpGlobalSetup10;

/* ��־����*/
extern DBHANDLE	ghAcLogSetup;
extern DBHANDLE	gidxAcLogSetup1;
extern DBHANDLE	gidxAcLogSetup10;

/* ��־����������*/
extern DBHANDLE	ghAcLogServerSetup;
extern DBHANDLE	gidxAcLogServerSetup1;
extern DBHANDLE	gidxAcLogServerSetup10;

/* AC֧�ֵ�AP����汾�б�����*/
extern DBHANDLE	ghAcAssocSwVerSetup;
extern DBHANDLE	gidxAcAssocSwVerSetup1;
extern DBHANDLE	gidxAcAssocSwVerSetup10;

/* ����˿�����*/
extern DBHANDLE	ghAcIfSetup;
extern DBHANDLE	gidxAcIfSetup1;
extern DBHANDLE	gidxAcIfSetup2;
extern DBHANDLE	gidxAcIfSetup10;

/* �˿�IP��ַ����*/
extern DBHANDLE	ghAcIpSetup;
extern DBHANDLE	gidxAcIpSetup1;
extern DBHANDLE	gidxAcIpSetup10;

/* �û���DHCP��������*/
extern DBHANDLE	ghAcStaDhcpGlobalSetup;
extern DBHANDLE	gidxAcStaDhcpGlobalSetup1;
extern DBHANDLE	gidxAcStaDhcpGlobalSetup10;

extern DBHANDLE	ghAcStaDhcpStaticIpAddrSetup;
extern DBHANDLE	gidxAcStaDhcpStaticIpAddrSetup1;
extern DBHANDLE	gidxAcStaDhcpStaticIpAddrSetup10;

extern DBHANDLE	ghAcStaDhcpDynamicIpAddrSetup;
extern DBHANDLE	gidxAcStaDhcpDynamicIpAddrSetup1;
extern DBHANDLE	gidxAcStaDhcpDynamicIpAddrSetup10;

/* AP��DHCP��������*/
extern DBHANDLE	ghAcApDhcpGlobalSetup;
extern DBHANDLE	gidxAcApDhcpGlobalSetup1;
extern DBHANDLE	gidxAcApDhcpGlobalSetup10;

extern DBHANDLE	ghAcApDhcpStaticIpAddrSetup;
extern DBHANDLE	gidxAcApDhcpStaticIpAddrSetup1;
extern DBHANDLE	gidxAcApDhcpStaticIpAddrSetup10;

extern DBHANDLE	ghAcApDhcpDynamicIpAddrSetup;
extern DBHANDLE	gidxAcApDhcpDynamicIpAddrSetup1;
extern DBHANDLE	gidxAcApDhcpDynamicIpAddrSetup10;

/* VLANȫ������*/
extern DBHANDLE	ghAcVlanGlobalSetup;
extern DBHANDLE	gidxAcVlanGlobalSetup1;
extern DBHANDLE	gidxAcVlanGlobalSetup10;

/* VLAN���ñ�*/
extern DBHANDLE	ghAcVlanSetup;
extern DBHANDLE	gidxAcVlanSetup1;
extern DBHANDLE	gidxAcVlanSetup10;

/* AP IP����-VLANӳ�����ñ�*/
extern DBHANDLE	ghAcApIpVlanMappingSetup;
extern DBHANDLE	gidxAcApIpVlanMappingSetup1;
extern DBHANDLE	gidxAcApIpVlanMappingSetup10;

/* SSID-VLANӳ�����ñ�*/
extern DBHANDLE	ghAcSsidVlanMappingSetup;
extern DBHANDLE	gidxAcSsidVlanMappingSetup1;
extern DBHANDLE	gidxAcSsidVlanMappingSetup10;

/* �˿�-VLANӳ�����ñ�*/
extern DBHANDLE	ghAcIfVlanMappingSetup;
extern DBHANDLE	gidxAcIfVlanMappingSetup1;
extern DBHANDLE	gidxAcIfVlanMappingSetup10;

/* MAC-VLANӳ�����ñ�*/
extern DBHANDLE	ghAcMacVlanMappingSetup;
extern DBHANDLE	gidxAcMacVlanMappingSetup1;
extern DBHANDLE	gidxAcMacVlanMappingSetup10;

/* AS���������ñ�*/
extern DBHANDLE	ghAcWapiAsSetup;
extern DBHANDLE	gidxAcWapiAsSetup1;
extern DBHANDLE	gidxAcWapiAsSetup10;

/* WAPI�������ñ�*/
extern DBHANDLE	ghAcWapiSetup;
extern DBHANDLE	gidxAcWapiSetup1;
extern DBHANDLE	gidxAcWapiSetup10;

/* WAPI֤�����ñ�*/
extern DBHANDLE	ghAcWapiCertFileSetup;
extern DBHANDLE	gidxAcWapiCertFileSetup1;
extern DBHANDLE	gidxAcWapiCertFileSetup10;

/* AAA���������ñ�*/
extern DBHANDLE	ghAcAAASetup;
extern DBHANDLE	gidxAcAAASetup1;
extern DBHANDLE	gidxAcAAASetup10;

/* ����֤ȫ������*/
extern DBHANDLE	ghAcFreeGlobalSetup;
extern DBHANDLE	gidxcFreeGlobalSetup1;
extern DBHANDLE	gidxcFreeGlobalSetup10;

/* ����֤IP����*/
extern DBHANDLE	ghAcFreeIpSetup;
extern DBHANDLE	gidxAcFreeIpSetup1;
extern DBHANDLE	gidxAcFreeIpSetup10;

/* ����֤MAC����*/
extern DBHANDLE	ghAcFreeMacSetup;
extern DBHANDLE	gidxAcFreeMacSetup1;
extern DBHANDLE	gidxAcFreeMacSetup10;

/* ����֤SSID�б�*/
extern DBHANDLE	ghAcFreeSsidSetup;
extern DBHANDLE	gidxAcFreeSsidSetup1;
extern DBHANDLE	gidxAcFreeSsidSetup10;

/* ����֤VLAN�б�*/
extern DBHANDLE	ghAcFreeVlanSetup;
extern DBHANDLE	gidxAcFreeVlanSetup1;
extern DBHANDLE	gidxAcFreeVlanSetup10;

/* WEB��֤ȫ������*/
extern DBHANDLE	ghAcPortalSetup;
extern DBHANDLE	gidxAcPortalSetup1;
extern DBHANDLE	gidxAcPortalSetup10;

/* MAC��֤ȫ������*/
extern DBHANDLE	ghAcMacServerSetup;
extern DBHANDLE	gidxAcMacServerSetup1;
extern DBHANDLE	gidxAcMacServerSetup10;

/* ����������*/
extern DBHANDLE	ghAcWhilteListSetup;
extern DBHANDLE	gidxAcWhilteListSetup1;
extern DBHANDLE	gidxAcWhilteListSetup10;

/* ������URL ����*/
extern DBHANDLE	ghAcWhiteUrlListSetup;
extern DBHANDLE	gidxAcWhiteUrlListSetup1;
extern DBHANDLE	gidxAcWhiteUrlListSetup10;

/* �û�����ַ������*/
extern DBHANDLE	ghAcUserAddrBindSetup;
extern DBHANDLE	gidxAcUserAddrBindSetup1;
extern DBHANDLE	gidxAcUserAddrBindSetup2;
extern DBHANDLE	gidxAcUserAddrBindSetup10;

/* SSID��֤����*/
extern DBHANDLE	ghAcSsidAuthSetup;
extern DBHANDLE	gidxAcSsidAuthSetup1;
extern DBHANDLE	gidxAcSsidAuthSetup10;

/* PPPoE��֤����*/
extern DBHANDLE	ghAcPPPoESetup;
extern DBHANDLE	gidxAcPPPoESetup1;
extern DBHANDLE	gidxAcPPPoESetup10;

/* ��̬·������*/
extern DBHANDLE	ghAcStaticRouteSetup;
extern DBHANDLE	gidxAcStaticRouteSetup1;
extern DBHANDLE	gidxAcStaticRouteSetup2;
extern DBHANDLE	gidxAcStaticRouteSetup10;

/* RIPЭ������*/
extern DBHANDLE	ghAcRipGlobalSetup;
extern DBHANDLE	gidxAcRipGlobalSetup1;
extern DBHANDLE	gidxAcRipGlobalSetup10;

/* RIPͨ����������*/
extern DBHANDLE	ghAcRipAnnounceNetSetup;
extern DBHANDLE	gidxAcRipAnnounceNetSetup1;
extern DBHANDLE	gidxAcRipAnnounceNetSetup10;

/* NATȫ������*/
extern DBHANDLE	ghAcNatGlobalSetup;
extern DBHANDLE	gidxAcNatGlobalSetup1;
extern DBHANDLE	gidxAcNatGlobalSetup10;

/* NAT��������*/
extern DBHANDLE	ghAcNatSetup;
extern DBHANDLE	gidxAcNatSetup1;
extern DBHANDLE	gidxAcNatSetup10;

/* MAC��ַ���˲���*/
extern DBHANDLE	ghAcVlanAccessMacPolicySetup;
extern DBHANDLE	gidxAcVlanAccessMacPolicySetup1;
extern DBHANDLE	gidxAcVlanAccessMacPolicySetup10;

/* MAC��ַ�����б�*/
extern DBHANDLE	ghAcVlanAccessMacListSetup;
extern DBHANDLE	gidxAcVlanAccessMacListSetup1;
extern DBHANDLE	gidxAcVlanAccessMacListSetup10;

/* ACLȫ������*/
extern DBHANDLE	ghAcFirewallGlobalSetup;
extern DBHANDLE	gidxAcFirewallGlobalSetup1;
extern DBHANDLE	gidxAcFirewallGlobalSetup10;

/* ACL��������*/
extern DBHANDLE	ghAcFirewallRuleBasicSetup;
extern DBHANDLE	gidxAcFirewallRuleBasicSetup1;
extern DBHANDLE	gidxAcFirewallRuleBasicSetup10;

/* IDS��������*/
extern DBHANDLE	ghAcIdsRuleSetup;
extern DBHANDLE	gidxAcIdsRuleSetup1;
extern DBHANDLE	gidxAcIdsRuleSetup10;

/* IDS��������*/
extern DBHANDLE	ghAcIdsStrategySetup;
extern DBHANDLE	gidxAcIdsStrategySetup1;
extern DBHANDLE	gidxAcIdsStrategySetup10;

/* P2P��������*/
extern DBHANDLE	ghAcFirewallL7MatchSetup;
extern DBHANDLE	gidxAcFirewallL7MatchSetup1;
extern DBHANDLE	gidxAcFirewallL7MatchSetup10;

/* QoSȫ������*/
extern DBHANDLE	ghAcQosGlobalSetup;
extern DBHANDLE	gidxAcQosGlobalSetup1;
extern DBHANDLE	gidxAcQosGlobalSetup10;

/* Ĭ�ϵ��û�QoS����*/
extern DBHANDLE	ghAcQosUserDefaultSetup;
extern DBHANDLE	gidxAcQosUserDefaultSetup1;
extern DBHANDLE	gidxAcQosUserDefaultSetup10;

/* �û�QoS����*/
extern DBHANDLE	ghAcUserQosSetup;
extern DBHANDLE	gidxAcUserQosSetup1;
extern DBHANDLE	gidxAcUserQosSetup10;

/* VLAN���û�QoS����*/
extern DBHANDLE	ghAcVlanQosSetup;
extern DBHANDLE	gidxAcVlanQosSetup1;
extern DBHANDLE	gidxAcVlanQosSetup10;

/* SSID���û�QoS���� */
extern DBHANDLE	ghAcSsidQosSetup;
extern DBHANDLE	gidxAcSsidQosSetup1;
extern DBHANDLE	gidxAcSsidQosSetup2;
extern DBHANDLE	gidxAcSsidQosSetup10;

/* VAP���û�QoS���� */
extern DBHANDLE	ghAcVapQosSetup;
extern DBHANDLE	gidxAcVapQosSetup1;
extern DBHANDLE	gidxAcVapQosSetup10;

/* AP���û�QoS���� */
extern DBHANDLE	ghAcApQosSetup;
extern DBHANDLE	gidxAcApQosSetup1;
extern DBHANDLE	gidxAcApQosSetup10;
/* IGMP Snoop����*/
extern DBHANDLE	ghAcIgmpSnoopSetup;
extern DBHANDLE	gidxAcIgmpSnoopSetup1;
extern DBHANDLE	gidxAcIgmpSnoopSetup10;

/* IGMP Proxy����*/
extern DBHANDLE	ghAcIgmpProxySetup;
extern DBHANDLE	gidxAcIgmpProxySetup1;
extern DBHANDLE	gidxAcIgmpProxySetup10;

/* 2010-1-18 pyy ����*/
/* ��������*/
extern DBHANDLE	ghAcMsSetup;
extern DBHANDLE	gidxAcMsSetup1;
extern DBHANDLE	gidxAcMsSetup10;

/* �澯��������*/
extern DBHANDLE	ghAcAlarmFilterSetup;
extern DBHANDLE	gidxAcAlarmFilterSetup1;
extern DBHANDLE	gidxAcAlarmFilterSetup10;

/* �澯��������*/
extern DBHANDLE	ghAcAlarmThresholdSetup;
extern DBHANDLE	gidxAcAlarmThresholdSetup1;
extern DBHANDLE	gidxAcAlarmThresholdSetup10;

/* ���ܼ�����������*/
extern DBHANDLE	ghAcPerfCounterGroupInfoSetup;
extern DBHANDLE	gidxAcPerfCounterGroupInfoSetup1;
extern DBHANDLE	gidxAcPerfCounterGroupInfoSetup10;

/* 2010-6-24 pyy ����*/
extern DBHANDLE	ghAcApAclSetup;
extern DBHANDLE	gidxAcApAclSetup1;
extern DBHANDLE	gidxAcApAclSetup10;

extern DBHANDLE	ghAcApIdNasSetup;
extern DBHANDLE	gidxAcApIdNasSetup1;
extern DBHANDLE	gidxAcApIdNasSetup10;

extern DBHANDLE	ghAcApIpNasSetup;
extern DBHANDLE	gidxAcApIpNasSetup1;
extern DBHANDLE	gidxAcApIpNasSetup10;

extern DBHANDLE	ghAcUser;
extern DBHANDLE	gidxAcUser1;
extern DBHANDLE	gidxAcUser2;
extern DBHANDLE	gidxAcUser3;
extern DBHANDLE	gidxAcUser4;

extern DBHANDLE	ghAcUserVlan;
extern DBHANDLE	gidxAcUserVlan1;

extern DBHANDLE	ghAcDynEvent;
extern DBHANDLE	gidxAcDynEvent1;

extern DBHANDLE	ghAcIdsUser;
extern DBHANDLE	gidxAcIdsUser1;

extern DBHANDLE	ghAcPortalUser;
extern DBHANDLE	gidxAcPortalUser1;
extern DBHANDLE	gidxAcPortalUser2;

extern DBHANDLE	ghAcUserAccInfo;
extern DBHANDLE	gidxAcUserAccInfo1;
extern DBHANDLE	gidxAcUserAccInfo2;

extern DBHANDLE	ghAcUserIpInfo;
extern DBHANDLE	gidxAcUserIpInfo1;

/* 2011-1-12 pyy add */
extern DBHANDLE	ghAcHistoryUser;
extern DBHANDLE	gidxAcHistoryUser1;

/*nasid��*/
extern DBHANDLE	ghAcNasIdSetup;
extern DBHANDLE	gidxAcNasIdSetup1;
extern DBHANDLE	gidxAcNasIdSetup10;

/* acssidmacserversetup��*/
extern DBHANDLE	ghAcSsidMacServerSetup;
extern DBHANDLE	gidxAcSsidMacServerSetup1;
extern DBHANDLE	gidxAcSsidMacServerSetup10;

/* add by gwx 2013-10-11 for task1076 ��ҵ���û�������*/
extern DBHANDLE	ghAcUserGroupSetup;
extern DBHANDLE	gidxAcUserGroupSetup1;
extern DBHANDLE	gidxAcUserGroupSetup10;

/* add by gwx 2014-6-25 for SSID���û��������begin*/
extern DBHANDLE	ghAcSsidAccessSetup;
extern DBHANDLE	gidxAcSsidAccessSetup1;
extern DBHANDLE	gidxAcSsidAccessSetup10;

extern DBHANDLE	ghAcSsidAccessListSetup;
extern DBHANDLE	gidxAcSsidAccessListSetup1;
extern DBHANDLE	gidxAcSsidAccessListSetup2;
extern DBHANDLE	gidxAcSsidAccessListSetup10;
/* add by gwx 2014-6-25 for SSID���û��������end*/

/* add by gwx 2011-11-2 */
extern DBHANDLE	ghAcAuthStat;
extern DBHANDLE	gidxAcAuthStat1;

extern DBHANDLE	ghAcUserTimer;
extern DBHANDLE	gidxAcUserTimer1;

extern DBHANDLE	ghAcLinkIpListSetup;
extern DBHANDLE	gidxAcLinkIpListSetup1;
extern DBHANDLE	gidxAcLinkIpListSetup10;
/* ������������*/
/******************************************************************************/

/******************************************************************************/
/* ����������ʼ*/
extern UINT32    ac_db_actable_init (VOID);
extern VOID ac_db_table_mergekey_mo (UINT8 *pucKey, UINT32 ulMOC, UINT8 *pucMOI);

/* �������ñ�*/
extern UINT32    ac_db_table_acbasicsetup_create (VOID);
extern UINT32    ac_db_table_acbasicsetup_check (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_preinsert (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_predelete (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acbasicsetup_preupdate (AC_DB_TBL_ACBASICSETUP_T *pstRecord);
extern VOID ac_db_table_acbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acbasicsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acbasicsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acbasicsetup_default(UINT32 ulAcId);

/* AC�������ñ�*/
extern UINT32    	ac_db_table_acwtpassociatesetup_create (VOID);
extern UINT32    	ac_db_table_acwtpassociatesetup_check (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_preinsert (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_predelete (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    	ac_db_table_acwtpassociatesetup_preupdate (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern VOID 		ac_db_table_acwtpassociatesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId);
extern VOID 		ac_db_table_acwtpassociatesetup_mergekey2 (UINT8 *pucKey, UINT8 *pucSn, UINT32 ulWtpId);
extern UINT32		ac_db_table_acwtpassociatesetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwtpassociatesetup_setdyndata (AC_DB_TBL_ACWTPASSOCIATESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwtpassociatesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwtpassociatesetup_default(UINT32 ulAcId,UINT32 ulWtpId);

/* ������·������ñ�*/
extern UINT32    ac_db_table_ackeepersetup_create (VOID);
extern UINT32    ac_db_table_ackeepersetup_check (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_preinsert (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_predelete (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern UINT32    ac_db_table_ackeepersetup_preupdate (AC_DB_TBL_ACKEEPERSETUP_T *pstRecord);
extern VOID ac_db_table_ackeepersetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_ackeepersetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_ackeepersetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_ackeepersetup_default(UINT32 ulAcId);

/* �ھӹ�ϵ����*/
extern UINT32    ac_db_table_acneighborsetup_create (VOID);
extern UINT32    ac_db_table_acneighborsetup_check (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_preinsert (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_predelete (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_acneighborsetup_preupdate (AC_DB_TBL_ACNEIGHBORSETUP_T *pstRecord);
extern VOID ac_db_table_acneighborsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulNeighId);
extern VOID ac_db_table_acneighborsetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId, UINT32 ulNeighId);
extern UINT32    ac_db_table_acneighborsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acneighborsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP V2 ���ñ�*/
extern UINT32    ac_db_table_acsyssnmpv2setup_create (VOID);
extern UINT32    ac_db_table_acsyssnmpv2setup_check (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_preinsert (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_predelete (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv2setup_preupdate (AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstRecord);
extern VOID ac_db_table_acsyssnmpv2setup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulCommunityId);
extern UINT32    ac_db_table_acsyssnmpv2setup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsyssnmpv2setup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP V3���ñ�*/
extern UINT32    ac_db_table_acsyssnmpv3setup_create (VOID);
extern UINT32    ac_db_table_acsyssnmpv3setup_check (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_preinsert (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_predelete (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern UINT32    ac_db_table_acsyssnmpv3setup_preupdate (AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstRecord);
extern VOID ac_db_table_acsyssnmpv3setup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulUserId);
extern UINT32    ac_db_table_acsyssnmpv3setup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsyssnmpv3setup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNMP TRAP ���ñ�*/
extern UINT32    ac_db_table_acsystrapsvrsetup_create (VOID);
extern UINT32    ac_db_table_acsystrapsvrsetup_check (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_preinsert (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_predelete (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsystrapsvrsetup_preupdate (AC_DB_TBL_ACSYSTRAPSVRSETUP_T *pstRecord);
extern VOID ac_db_table_acsystrapsvrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulTrapSrvId);
extern UINT32 ac_db_table_acsystrapsvrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acsystrapsvrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SNTP���������ñ�*/
extern UINT32    ac_db_table_acsntpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acsntpglobalsetup_check (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_preinsert (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_predelete (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acsntpglobalsetup_preupdate (AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acsntpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acsntpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acsntpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acsntpglobalsetup_default(UINT32 ulAcId);

/* ��־����*/
extern UINT32    ac_db_table_aclogsetup_create (VOID);
extern UINT32    ac_db_table_aclogsetup_check (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_preinsert (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_predelete (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogsetup_preupdate (AC_DB_TBL_ACLOGSETUP_T *pstRecord);
extern VOID ac_db_table_aclogsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_aclogsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_aclogsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_aclogsetup_default(UINT32 ulAcId);


/* ��־����������*/
extern UINT32    ac_db_table_aclogserversetup_create (VOID);
extern UINT32    ac_db_table_aclogserversetup_check (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_preinsert (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_predelete (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_aclogserversetup_preupdate (AC_DB_TBL_ACLOGSERVERSETUP_T *pstRecord);
extern VOID ac_db_table_aclogserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_aclogserversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_aclogserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_aclogserversetup_default(UINT32 ulAcId);

/* AC֧�ֵ�AP����汾�б�����*/
extern UINT32	ac_db_table_acassocswversetup_create(VOID);
extern UINT32    ac_db_table_acassocswversetup_check (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_preinsert (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_predelete (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acassocswversetup_preupdate (AC_DB_TBL_ACASSOCSWVERSETUP_T *pstRecord);
extern VOID ac_db_table_acassocswversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32		ac_db_table_acassocswversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acassocswversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acassocswversetup_default(UINT32 ulAcId);

/* ����˿�����*/
extern UINT32    ac_db_table_acifsetup_create (VOID);
extern UINT32    ac_db_table_acifsetup_check (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_preinsert (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_predelete (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifsetup_preupdate (AC_DB_TBL_ACIFSETUP_T *pstRecord);
extern VOID ac_db_table_acifsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulIfId);
extern VOID ac_db_table_acifsetup_mergekey2 (UINT8 *pucKey, CHAR *pacIfName);
extern UINT32    ac_db_table_acifsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acifsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acifsetup_default(UINT32 ulAcId);

/* �˿�IP��ַ���ñ�*/
extern UINT32    ac_db_table_acipsetup_create (VOID);
extern UINT32    ac_db_table_acipsetup_check (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_preinsert (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_predelete (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acipsetup_preupdate (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern VOID ac_db_table_acipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acipsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acipsetup_setdyndata (AC_DB_TBL_ACIPSETUP_T *pstRecord);
extern UINT32 ac_db_table_acipsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acipsetup_default(UINT32 ulAcId);

/* �û���DHCP��������*/
extern UINT32    ac_db_table_acstadhcpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpglobalsetup_check (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_preinsert (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_predelete (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpglobalsetup_preupdate (AC_DB_TBL_ACSTADHCPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acstadhcpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acstadhcpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acstadhcpglobalsetup_default(UINT32 ulAcId);

/* �û���DHCP MAC-IP��ַ��*/
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_check (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_preinsert (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_predelete (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_preupdate (AC_DB_TBL_ACSTADHCPSTATICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpstaticipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstadhcpstaticipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* �û���DHCP IP��ַ��*/
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_check (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_preinsert (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_predelete (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_preupdate (AC_DB_TBL_ACSTADHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acstadhcpdynamicipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstadhcpdynamicipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP��DHCP��������*/
extern UINT32    ac_db_table_acapdhcpglobalsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpglobalsetup_check (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_preinsert (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_predelete (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpglobalsetup_preupdate (AC_DB_TBL_ACAPDHCPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acapdhcpglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acapdhcpglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acapdhcpglobalsetup_default(UINT32 ulAcId);

/* AP��DHCP MAC-IP��ַ��*/
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_check (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_preinsert (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_predelete (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_preupdate (AC_DB_TBL_ACAPDHCPSTATICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpstaticipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapdhcpstaticipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP��DHCP IP��ַ��*/
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_create (VOID);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_check (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_preinsert (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_predelete (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_preupdate (AC_DB_TBL_ACAPDHCPDYNAMICIPADDRSETUP_T *pstRecord);
extern VOID ac_db_table_acapdhcpdynamicipaddrsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapdhcpdynamicipaddrsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VLANȫ������*/
extern UINT32    ac_db_table_acvlanglobalsetup_create (VOID);
extern UINT32    ac_db_table_acvlanglobalsetup_check (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_preinsert (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_predelete (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanglobalsetup_preupdate (AC_DB_TBL_ACVLANGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acvlanglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acvlanglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acvlanglobalsetup_default(UINT32 ulAcId);

/* VLAN����*/
extern UINT32    ac_db_table_acvlansetup_create (VOID);
extern UINT32    ac_db_table_acvlansetup_check (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_preinsert (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_predelete (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlansetup_preupdate (AC_DB_TBL_ACVLANSETUP_T *pstRecord);
extern VOID ac_db_table_acvlansetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlansetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acvlansetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acvlansetup_default(UINT32 ulAcId);

/* AP IP����-VLANӳ�����ñ�*/
extern UINT32    ac_db_table_acapipvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acapipvlanmappingsetup_check (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_preinsert (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_predelete (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipvlanmappingsetup_preupdate (AC_DB_TBL_ACAPIPVLANMAPPINGSETUP_T *pstRecord);
extern UINT32 ac_db_table_acapipvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern VOID ac_db_table_acapipvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucIp, UINT8 *pucMask, UINT32 ulVlanId);
extern UINT32    ac_db_table_acapipvlanmappingsetup_trigger (UINT8 ucModType);


/* SSID-VLANӳ������*/
extern UINT32    ac_db_table_acssidvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acssidvlanmappingsetup_check (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_preinsert (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_predelete (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidvlanmappingsetup_preupdate (AC_DB_TBL_ACSSIDVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acssidvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid, UINT32 ulVlanId);
extern UINT32    ac_db_table_acssidvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acssidvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* �˿�-VLANӳ������*/
extern UINT32    ac_db_table_acifvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acifvlanmappingsetup_check (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_preinsert (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_predelete (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acifvlanmappingsetup_preupdate (AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acifvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulDevId, UINT32 ulIfId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acifvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acifvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC-VLANӳ�����ñ�*/
extern UINT32    ac_db_table_acmacvlanmappingsetup_create (VOID);
extern UINT32    ac_db_table_acmacvlanmappingsetup_check (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_preinsert (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_predelete (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacvlanmappingsetup_preupdate (AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstRecord);
extern VOID ac_db_table_acmacvlanmappingsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac, UINT32 ulVlanId);
extern UINT32    ac_db_table_acmacvlanmappingsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acmacvlanmappingsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AS����������*/
extern UINT32    ac_db_table_acwapiassetup_create (VOID);
extern UINT32    ac_db_table_acwapiassetup_check (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_preinsert (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_predelete (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapiassetup_preupdate (AC_DB_TBL_ACWAPIASSETUP_T *pstRecord);
extern VOID ac_db_table_acwapiassetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acwapiassetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapiassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapiassetup_default(UINT32 ulAcId);

/* WAPI ��������*/
extern UINT32    ac_db_table_acwapisetup_create (VOID);
extern UINT32    ac_db_table_acwapisetup_check (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_preinsert (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_predelete (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapisetup_preupdate (AC_DB_TBL_ACWAPISETUP_T *pstRecord);
extern VOID ac_db_table_acwapisetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32  ulWapiSetupId);
extern UINT32    ac_db_table_acwapisetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapisetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapisetup_default(UINT32 ulAcId);

/* WAPI֤������*/
extern UINT32    ac_db_table_acwapicertfilesetup_create (VOID);
extern UINT32    ac_db_table_acwapicertfilesetup_check (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_preinsert (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_predelete (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern UINT32    ac_db_table_acwapicertfilesetup_preupdate (AC_DB_TBL_ACWAPICERTFILESETUP_T *pstRecord);
extern VOID ac_db_table_acwapicertfilesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32  ulCertId);
extern UINT32    ac_db_table_acwapicertfilesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acwapicertfilesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acwapicertfilesetup_default(UINT32 ulAcId);

/* AAA ����*/
extern UINT32    ac_db_table_acaaasetup_create (VOID);
extern UINT32    ac_db_table_acaaasetup_check (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_preinsert (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_predelete (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern UINT32    ac_db_table_acaaasetup_preupdate (AC_DB_TBL_ACAAASETUP_T *pstRecord);
extern VOID ac_db_table_acaaasetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acaaasetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acaaasetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acaaasetup_default(UINT32 ulAcId);

/* ����֤ ����*/
extern UINT32    ac_db_table_acfreeglobalsetup_create (VOID);
extern UINT32    ac_db_table_acfreeglobalsetup_check (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_preinsert (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_predelete (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeglobalsetup_preupdate (AC_DB_TBL_ACFREEGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acfreeglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfreeglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreeglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreeglobalsetup_default(UINT32 ulAcId);

/* ����֤IP����*/
extern UINT32    ac_db_table_acfreeipsetup_create (VOID);
extern UINT32    ac_db_table_acfreeipsetup_check (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_preinsert (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_predelete (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreeipsetup_preupdate (AC_DB_TBL_ACFREEIPSETUP_T *pstRecord);
extern VOID ac_db_table_acfreeipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucIp, UINT8 *pucMask);
extern UINT32    ac_db_table_acfreeipsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfreeipsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* ����֤MAC�б�����*/
extern UINT32    ac_db_table_acfreemacsetup_create (VOID);
extern UINT32    ac_db_table_acfreemacsetup_check (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_preinsert (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_predelete (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreemacsetup_preupdate (AC_DB_TBL_ACFREEMACSETUP_T *pstRecord);
extern VOID ac_db_table_acfreemacsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acfreemacsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfreemacsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* ����֤SSID�б�����*/
extern UINT32    ac_db_table_acfreessidsetup_create (VOID);
extern UINT32    ac_db_table_acfreessidsetup_check (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_preinsert (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_predelete (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreessidsetup_preupdate (AC_DB_TBL_ACFREESSIDSETUP_T *pstRecord);
extern VOID ac_db_table_acfreessidsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid);
extern UINT32    ac_db_table_acfreessidsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreessidsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreessidsetup_default(UINT32 ulAcId);

/* ����֤VLAN�б�����*/
extern UINT32    ac_db_table_acfreevlansetup_create (VOID);
extern UINT32    ac_db_table_acfreevlansetup_check (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_preinsert (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_predelete (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfreevlansetup_preupdate (AC_DB_TBL_ACFREEVLANSETUP_T *pstRecord);
extern VOID ac_db_table_acfreevlansetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acfreevlansetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfreevlansetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfreevlansetup_default(UINT32 ulAcId);

/* MAC��֤ȫ������*/
extern UINT32    ac_db_table_acmacserversetup_create(VOID);
extern UINT32    ac_db_table_acmacserversetup_check (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_preinsert (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_predelete (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmacserversetup_preupdate (AC_DB_TBL_ACMACSERVERSETUP_T *pstRecord);
extern VOID 	ac_db_table_acmacserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acmacserversetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acmacserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acmacserversetup_default(UINT32 ulAcId);

/* WEB��֤ȫ������*/
extern UINT32    ac_db_table_acportalsetup_create (VOID);
extern UINT32    ac_db_table_acportalsetup_check (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_preinsert (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_predelete (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acportalsetup_preupdate (AC_DB_TBL_ACPORTALSETUP_T *pstRecord);
extern VOID ac_db_table_acportalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acportalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acportalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acportalsetup_default(UINT32 ulAcId);

/* ����������*/
extern UINT32    ac_db_table_acwhiltelistsetup_create (VOID);
extern UINT32    ac_db_table_acwhiltelistsetup_check (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_preinsert (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_predelete (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiltelistsetup_preupdate (AC_DB_TBL_ACWHILTELISTSETUP_T *pstRecord);
extern VOID ac_db_table_acwhiltelistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWhiteId);
extern UINT32    ac_db_table_acwhiltelistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwhiltelistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* ������URL ����*/
extern UINT32    ac_db_table_acwhiteurllistsetup_create (VOID);
extern UINT32    ac_db_table_acwhiteurllistsetup_check (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_preinsert (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_predelete (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acwhiteurllistsetup_preupdate (AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstRecord);
extern VOID ac_db_table_acwhiteurllistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWhiteId);
extern UINT32    ac_db_table_acwhiteurllistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acwhiteurllistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);


/* �û�����ַ������*/
extern UINT32    ac_db_table_acuseraddrbindsetup_create (VOID);
extern UINT32    ac_db_table_acuseraddrbindsetup_check (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_preinsert (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_predelete (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuseraddrbindsetup_preupdate (AC_DB_TBL_ACUSERADDRBINDSETUP_T *pstRecord);
extern VOID ac_db_table_acuseraddrbindsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulIndex);
extern VOID ac_db_table_acuseraddrbindsetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcUserName);
extern UINT32    ac_db_table_acuseraddrbindsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acuseraddrbindsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

extern UINT32    ac_db_table_acssidauthsetup_create (VOID);
extern UINT32    ac_db_table_acssidauthsetup_check (AC_DB_TBL_ACSSIDAUTHSETUP_T	*pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_preinsert (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_predelete (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidauthsetup_preupdate (AC_DB_TBL_ACSSIDAUTHSETUP_T *pstRecord);
extern VOID ac_db_table_acssidauthsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid, CHAR *pcUserNameSuffix);
extern UINT32	 ac_db_table_acssidauthsetup_trigger(UINT8 ucModType);
extern UINT32    ac_db_table_acssidauthsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);


/* PPPoE��֤����*/
extern UINT32    ac_db_table_acpppoesetup_create (VOID);
extern UINT32    ac_db_table_acpppoesetup_check (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_preinsert (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_predelete (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_preupdate (AC_DB_TBL_ACPPPOESETUP_T *pstRecord);
extern UINT32    ac_db_table_acpppoesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acpppoesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acpppoesetup_default(UINT32 ulAcId);

/* ��̬·������*/
extern UINT32    ac_db_table_acstaticroutesetup_create (VOID);
extern UINT32    ac_db_table_acstaticroutesetup_check (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_preinsert (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_predelete (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern UINT32    ac_db_table_acstaticroutesetup_preupdate (AC_DB_TBL_ACSTATICROUTESETUP_T *pstRecord);
extern VOID ac_db_table_acstaticroutesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulRouteId);
extern VOID ac_db_table_acstaticroutesetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucDestIp, UINT8 *pucNetMask, UINT8 *pucGw);
extern UINT32    ac_db_table_acstaticroutesetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acstaticroutesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* RIPЭ������*/
extern UINT32    ac_db_table_acripglobalsetup_create (VOID);
extern UINT32    ac_db_table_acripglobalsetup_check (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_preinsert (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_predelete (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripglobalsetup_preupdate (AC_DB_TBL_ACRIPGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acripglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acripglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acripglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acripglobalsetup_default(UINT32 ulAcId);

/* RIPͨ����������*/
extern UINT32    ac_db_table_acripannouncenetsetup_create (VOID);
extern UINT32    ac_db_table_acripannouncenetsetup_check (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_preinsert (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_predelete (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern UINT32    ac_db_table_acripannouncenetsetup_preupdate (AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstRecord);
extern VOID ac_db_table_acripannouncenetsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucNetIp, UINT8 *pucNetMask);
extern UINT32    ac_db_table_acripannouncenetsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acripannouncenetsetup_dftblk(UINT32 ulAcId, UINT8* pucRecord);

/* NATȫ������*/
extern UINT32    ac_db_table_acnatglobalsetup_create (VOID);
extern UINT32    ac_db_table_acnatglobalsetup_check (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_preinsert (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_predelete (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatglobalsetup_preupdate (AC_DB_TBL_ACNATGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acnatglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acnatglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acnatglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acnatglobalsetup_default(UINT32 ulAcId);

/* NAT��������*/
extern UINT32    ac_db_table_acnatsetup_create (VOID);
extern UINT32    ac_db_table_acnatsetup_check (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_preinsert (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_predelete (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern UINT32    ac_db_table_acnatsetup_preupdate (AC_DB_TBL_ACNATSETUP_T *pstRecord);
extern VOID ac_db_table_acnatsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulNatId);
extern UINT32    ac_db_table_acnatsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acnatsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC��ַ���˲���*/
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_create (VOID);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_check (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_preinsert (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_predelete (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_preupdate (AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanaccessmacpolicysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanaccessmacpolicysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* MAC��ַ�����б�*/
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_create (VOID);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_check (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_preinsert (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_predelete (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_preupdate (AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanaccessmaclistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId, UINT8 *pucMac);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanaccessmaclistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* ACLȫ������*/
extern UINT32    ac_db_table_acfirewallglobalsetup_create (VOID);
extern UINT32    ac_db_table_acfirewallglobalsetup_check (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_preinsert (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_predelete (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallglobalsetup_preupdate (AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewallglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfirewallglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfirewallglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfirewallglobalsetup_default(UINT32 ulAcId);

/* ACL��������*/
extern UINT32    ac_db_table_acfirewallrulebasicsetup_create (VOID);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_check (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_preinsert (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_predelete (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_preupdate (AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewallrulebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulRuleId, UINT32 ulChildRuleId);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acfirewallrulebasicsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* IDS��������*/
extern UINT32    ac_db_table_acidsrulesetup_create (VOID);
extern UINT32    ac_db_table_acidsrulesetup_check (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_preinsert (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_predelete (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsrulesetup_preupdate (AC_DB_TBL_ACIDSRULESETUP_T *pstRecord);
extern VOID ac_db_table_acidsrulesetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acidsrulesetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acidsrulesetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acidsrulesetup_default(UINT32 ulAcId);

/* IDS��������*/
extern UINT32    ac_db_table_acidsstrategysetup_create (VOID);
extern UINT32    ac_db_table_acidsstrategysetup_check (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_preinsert (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_predelete (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acidsstrategysetup_preupdate (AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstRecord);
extern VOID ac_db_table_acidsstrategysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acidsstrategysetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acidsstrategysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acidsstrategysetup_default(UINT32 ulAcId);

/* P2P��������*/
extern UINT32    ac_db_table_acfirewalll7matchsetup_create (VOID);
extern UINT32    ac_db_table_acfirewalll7matchsetup_check (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_preinsert (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_predelete (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern UINT32    ac_db_table_acfirewalll7matchsetup_preupdate (AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstRecord);
extern VOID ac_db_table_acfirewalll7matchsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acfirewalll7matchsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acfirewalll7matchsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acfirewalll7matchsetup_default(UINT32 ulAcId);

/* QoSȫ������*/
extern UINT32    ac_db_table_acqosglobalsetup_create (VOID);
extern UINT32    ac_db_table_acqosglobalsetup_check (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_preinsert (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_predelete (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosglobalsetup_preupdate (AC_DB_TBL_ACQOSGLOBALSETUP_T *pstRecord);
extern VOID ac_db_table_acqosglobalsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acqosglobalsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acqosglobalsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acqosglobalsetup_default(UINT32 ulAcId);

/* Ĭ�ϵ��û�QoS����*/
extern UINT32    ac_db_table_acqosuserdefaultsetup_create (VOID);
extern UINT32    ac_db_table_acqosuserdefaultsetup_check (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_preinsert (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_predelete (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern UINT32    ac_db_table_acqosuserdefaultsetup_preupdate (AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstRecord);
extern VOID ac_db_table_acqosuserdefaultsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acqosuserdefaultsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acqosuserdefaultsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acqosuserdefaultsetup_default(UINT32 ulAcId);

extern UINT32    ac_db_table_acuserqossetup_create (VOID);
extern UINT32    ac_db_table_acuserqossetup_check (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_preinsert (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_predelete (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acuserqossetup_preupdate (AC_DB_TBL_ACUSERQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acuserqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8 *pucMac);
extern UINT32    ac_db_table_acuserqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acuserqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VLAN���û�QoS����*/
extern UINT32    ac_db_table_acvlanqossetup_create (VOID);
extern UINT32    ac_db_table_acvlanqossetup_check (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_preinsert (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_predelete (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvlanqossetup_preupdate (AC_DB_TBL_ACVLANQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acvlanqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulVlanId);
extern UINT32    ac_db_table_acvlanqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvlanqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* SSID���û�QoS����*/
extern UINT32    ac_db_table_acssidqossetup_create (VOID);
extern UINT32    ac_db_table_acssidqossetup_check (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_preinsert (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_predelete (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acssidqossetup_preupdate (AC_DB_TBL_ACSSIDQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acssidqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulId);
extern VOID ac_db_table_acssidqossetup_mergekey2 (UINT8 *pucKey, UINT32 ulAcId, CHAR *pcSsid);
extern UINT32    ac_db_table_acssidqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acssidqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* VAP���û�QoS����*/
extern UINT32    ac_db_table_acvapqossetup_create (VOID);
extern UINT32    ac_db_table_acvapqossetup_check (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_preinsert (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_predelete (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acvapqossetup_preupdate (AC_DB_TBL_ACVAPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acvapqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32    ac_db_table_acvapqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acvapqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* AP���û�QoS����*/
extern UINT32    ac_db_table_acapqossetup_create (VOID);
extern UINT32    ac_db_table_acapqossetup_check (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_preinsert (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_predelete (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapqossetup_preupdate (AC_DB_TBL_ACAPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_acapqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulWtpId);
extern UINT32    ac_db_table_acapqossetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acapqossetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
/* IGMP Snoop����*/
extern UINT32    ac_db_table_acigmpsnoopsetup_create (VOID);
extern UINT32    ac_db_table_acigmpsnoopsetup_check (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_preinsert (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_predelete (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpsnoopsetup_preupdate (AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstRecord);
extern VOID ac_db_table_acigmpsnoopsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpsnoopsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acigmpsnoopsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acigmpsnoopsetup_default(UINT32 ulAcId);

/* IGMP Proxy����*/
extern UINT32    ac_db_table_acigmpproxysetup_create (VOID);
extern UINT32    ac_db_table_acigmpproxysetup_check (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_preinsert (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_predelete (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern UINT32    ac_db_table_acigmpproxysetup_preupdate (AC_DB_TBL_ACIGMPPROXYSETUP_T *pstRecord);
extern VOID ac_db_table_acigmpproxysetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpproxysetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acigmpproxysetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acigmpproxysetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);

/* 2010-1-18 pyy ����*/
/* AC�������� */
extern UINT32    ac_db_table_acmssetup_create (VOID);
extern UINT32    ac_db_table_acmssetup_check (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_preinsert (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_predelete (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern UINT32    ac_db_table_acmssetup_preupdate (AC_DB_TBL_ACMSSETUP_T *pstRecord);
extern VOID ac_db_table_acmssetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acmssetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acmssetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acmssetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acmssetup_setdyndata (AC_DB_TBL_ACMSSETUP_T *pstRecord);


/* �澯��������*/
extern UINT32    ac_db_table_acalarmfiltersetup_create (VOID);
extern UINT32    ac_db_table_acalarmfiltersetup_check (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_preinsert (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_predelete (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_preupdate (AC_DB_TBL_ACALARMFILTERSETUP_T *pstRecord);
extern VOID ac_db_table_acalarmfiltersetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulAlarmNo);
extern UINT32    ac_db_table_acalarmfiltersetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_acalarmfiltersetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acalarmfiltersetup_default(UINT32 ulAcId);

/* �澯��������*/
extern UINT32    ac_db_table_acalarmthresholdsetup_create (VOID);
extern UINT32    ac_db_table_acalarmthresholdsetup_check (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_preinsert (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_predelete (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_acalarmthresholdsetup_preupdate (AC_DB_TBL_ACALARMTHRESHOLDSETUP_T *pstRecord);
extern VOID ac_db_table_acalarmthresholdsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32    ac_db_table_acalarmthresholdsetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acalarmthresholdsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acalarmthresholdsetup_default(UINT32 ulAcId);

/* ���ܼ�����������*/
extern UINT32    ac_db_table_acperfcountergroupinfosetup_create (VOID);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_check (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_preinsert (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_predelete (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_preupdate (AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern VOID ac_db_table_acperfcountergroupinfosetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT32 ulCounterGroupId);
extern UINT32    ac_db_table_acperfcountergroupinfosetup_trigger (UINT8 ucModType);
extern UINT32 ac_db_table_acperfcountergroupinfosetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acperfcountergroupinfosetup_default(UINT32 ulAcId);

extern UINT32    ac_db_table_acapaclsetup_create (VOID);
extern UINT32    ac_db_table_acapaclsetup_check (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_preinsert (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_predelete (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapaclsetup_preupdate (AC_DB_TBL_ACAPACLSETUP_T *pstRecord);
extern VOID ac_db_table_acapaclsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId);
extern UINT32 ac_db_table_acapaclsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 ac_db_table_acapaclsetup_default(UINT32 ulAcId);
extern UINT32    ac_db_table_acapaclsetup_trigger (UINT8 ucModType);


extern UINT32    ac_db_table_acapidnassetup_create (VOID);
extern UINT32    ac_db_table_acapidnassetup_check (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_preinsert (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_predelete (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapidnassetup_preupdate (AC_DB_TBL_ACAPIDNASSETUP_T *pstRecord);
extern VOID ac_db_table_acapidnassetup_mergekey1 (UINT8 *pucKey, 
														UINT32 ulAcId, 
														UINT32 ulApIdStart, 
														UINT32 ulApIdEnd, 
														CHAR	*pcSsid
														);
extern UINT32 ac_db_table_acapidnassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acapidnassetup_trigger (UINT8 ucModType);


extern UINT32    ac_db_table_acapipnassetup_create (VOID);
extern UINT32    ac_db_table_acapipnassetup_check (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_preinsert (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_predelete (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern UINT32    ac_db_table_acapipnassetup_preupdate (AC_DB_TBL_ACAPIPNASSETUP_T *pstRecord);
extern VOID ac_db_table_acapipnassetup_mergekey1 (UINT8 *pucKey, 
														UINT32 ulAcId, 
														UINT8 	*pucIp, 
														UINT32 	*pucMask, 
														CHAR	*pcSsid
														);
extern UINT32 ac_db_table_acapipnassetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32    ac_db_table_acapipnassetup_trigger (UINT8 ucModType);


extern UINT32		ac_db_table_acuser_create (VOID);
extern VOID    	ac_db_table_acuser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey2(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulIfId, UINT32 ulVapId, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey3(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId, UINT32 ulIfId, UINT8 *pucMac);
extern VOID    	ac_db_table_acuser_mergekey4(UINT8 *pucKey, UINT8 *pucIp, UINT8 *pucMac);

extern UINT32		ac_db_table_acuservlan_create (VOID);
extern VOID    	ac_db_table_acuservlan_mergekey1(UINT8 *pucKey, UINT8 *pucMac);


extern UINT32		ac_db_table_acdynevent_create (VOID);
extern VOID 		ac_db_table_acdynevent_mergekey1 (UINT8 *pucKey, 
											UINT32 	ulEventId, 
											UINT32	ulEventReasonId, 
											UINT32 	ulMOC, 
											UINT8	aucMOI[AC_MOI_LEN], 
											UINT32 	ulCommonInfo);

extern UINT32		ac_db_table_acidsuser_create (VOID);
extern VOID    	ac_db_table_acidsuser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);											

extern UINT32		ac_db_table_acportaluser_create (VOID);
extern VOID    	ac_db_table_acportaluser_mergekey1(UINT8 *pucKey, UINT8 *pucMac);	
extern VOID    	ac_db_table_acportaluser_mergekey2(UINT8 *pucKey, UINT32 pucWtpId, UINT32 pucDevId,UINT32 pucVapId, UINT32 puCertType,UINT8 *pucMac);	
extern UINT32		ac_db_table_acuseraccinfo_create(VOID);
extern VOID		ac_db_table_acuseraccinfo_mergekey1(UINT8 *pucKey, UINT8 *pucMac, UINT32 ulWtpId, UINT32 ulVapId);	
extern VOID    	ac_db_table_acuseraccinfo_mergekey2(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId, UINT8 *pucMac);

extern UINT32		ac_db_table_acuseripinfo_create(VOID);
extern VOID		ac_db_table_acuseripinfo_mergekey1(UINT8 *pucKey, UINT8 *pucIp);	

/* 2011-1-12 pyy add */
extern UINT32		ac_db_table_achistoryuser_create(VOID);
extern VOID		ac_db_table_achistoryuser_mergekey1(UINT8 *pucKey, UINT32 ulWtpId, UINT8 *pucMac);

extern UINT32    	ac_db_table_acnasidsetup_create(VOID);
extern UINT32    	ac_db_table_acnasidsetup_check (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acnasidsetup_preinsert (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acnasidsetup_predelete (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acnasidsetup_preupdate (AC_DB_TBL_ACNASIDSETUP_T *pstRecord);
extern VOID 		ac_db_table_acnasidsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* acNasId);
extern UINT32    	ac_db_table_acnasidsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acnasidsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acnasidsetup_default(UINT32 ulAcId);

extern UINT32    	ac_db_table_acssidmacserversetup_create(VOID);
extern UINT32    	ac_db_table_acssidmacserversetup_check (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidmacserversetup_preinsert (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidmacserversetup_predelete (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidmacserversetup_preupdate (AC_DB_TBL_ACSSIDMACSERVERSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidmacserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR*acSsid);
extern UINT32    	ac_db_table_acssidmacserversetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidmacserversetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidmacserversetup_default(UINT32 ulAcId);

/* add by gwx 2013-10-11 for task 1076 ��ҵ���û�����������begin */
extern UINT32    	ac_db_table_acusergroupsetup_create(VOID);
extern UINT32    	ac_db_table_acusergroupsetup_check (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acusergroupsetup_preinsert (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acusergroupsetup_predelete (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acusergroupsetup_preupdate (AC_DB_TBL_ACUSERGROUPSETUP_T *pstRecord);
extern VOID 		ac_db_table_acusergroupsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR*acUserGroupName);
extern UINT32    	ac_db_table_acusergroupsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acusergroupsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acusergroupsetup_default(UINT32 ulAcId);
/* add by gwx 2013-10-11 for task 1076 ��ҵ���û�����������end */

/* add by gwx 2014-6-25 for SSID���û��������begin*/
extern UINT32    	ac_db_table_acssidaccesssetup_create(VOID);
extern UINT32    	ac_db_table_acssidaccesssetup_check (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesssetup_preinsert (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesssetup_predelete (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidaccesssetup_preupdate (AC_DB_TBL_ACSSIDACCESSSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidaccesssetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* pcSsidName);
extern UINT32    	ac_db_table_acssidaccesssetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidaccesssetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidaccesssetup_default(UINT32 ulAcId);

extern UINT32    	ac_db_table_acssidaccesslistsetup_create(VOID);
extern UINT32    	ac_db_table_acssidaccesslistsetup_check (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesslistsetup_preinsert (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_acssidaccesslistsetup_predelete (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern UINT32   	ac_db_table_acssidaccesslistsetup_preupdate (AC_DB_TBL_ACSSIDACCESSLISTSETUP_T *pstRecord);
extern VOID 		ac_db_table_acssidaccesslistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, CHAR* pcSsidName, UINT8* pcUserMac);
extern VOID ac_db_table_acssidaccesslistsetup_mergekey2(UINT8 *pucKey, 
														UINT32	ulOuiSwtich,
														UINT32 ulAcId, 
														CHAR* pcSsidName,
														UINT8* pucUserMac
														);
extern UINT32    	ac_db_table_acssidaccesslistsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_acssidaccesslistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_acssidaccesslistsetup_default(UINT32 ulAcId);
/* add by gwx 2014-6-25 for SSID���û��������end*/

extern UINT32    	ac_db_table_aclinkiplistsetup_create(VOID);
extern UINT32    	ac_db_table_aclinkiplistsetup_check (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_aclinkiplistsetup_preinsert (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32    	ac_db_table_aclinkiplistsetup_predelete (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern UINT32   	ac_db_table_aclinkiplistsetup_preupdate (AC_DB_TBL_ACLINKIPLISTSETUP_T *pstRecord);
extern VOID 		ac_db_table_aclinkiplistsetup_mergekey1 (UINT8 *pucKey, UINT32 ulAcId, UINT8* pucAcLinkIp);
extern UINT32    	ac_db_table_aclinkiplistsetup_trigger (UINT8 ucModType);
extern UINT32 	ac_db_table_aclinkiplistsetup_dftblk(UINT32 ulAcId, UINT8 *pucRecord);
extern UINT32 	ac_db_table_aclinkiplistsetup_default(UINT32 ulAcId);

/* add by gwx 2011-11-2 */
extern UINT32		ac_db_table_acauthstat_create(VOID);

/* add by gwx 2012-11-2 for �û�������׼ȷ*/
extern UINT32 	ac_db_table_acusertimer_create(VOID);
extern VOID		ac_db_table_acusertimer_mergekey1( UINT8 *pucKey, UINT8 *pucMac);
/* ������������*/
/******************************************************************************/
	

#endif /* _AC_DB_TABLE_H */
/******************************* ͷ�ļ����� **********************************/

