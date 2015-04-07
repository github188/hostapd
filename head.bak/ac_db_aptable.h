/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��ϵ����ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
* 2009-3-3	  ������		     ����AP2.0����
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AP_DB_TABLE_H
#define  _AP_DB_TABLE_H

/******************************************************************************/
#ifdef APP_PROJ_AC
#define AC_DB_WTP_NUM_MAX		(AC_WTP_NUM_MAX)	
#else
#define AC_DB_WTP_NUM_MAX		((UINT32)1)	
#endif


/*AP ��ϵ�������궨�忪ʼ*/
#define AC_DB_WTPSYSBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP�������ñ������*/
#define AC_DB_WTPDYNINFO_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP״̬��Ϣ��*/
#define AC_DB_WTPROGUE_CAPACITY						(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* AC��⵽��δע��AP�б�*/
#define AC_DB_WTPSYSIPSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP IP���ñ������*/
#define AC_DB_WTPSYSLOADBALANCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ���ؾ������ñ������*/
#define AC_DB_WTPSYSLOGSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ��־�������ñ������*/
#define AC_DB_WTPSYSSWSERVERSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ������������ñ������*/
#define AC_DB_WTPSYSSNTPSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP  SNTP�������ñ������*/

#ifdef BIG_AC
#define AC_DB_WTPWIFIDEVICEBASICSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸�������ñ������*/
#define AC_DB_WTPWIFIDEVICECHANNELSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸�����ŵ����ñ������*/
#define AC_DB_WTPWIFIDEVICERATESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸�����������ñ������*/
#define AC_DB_WTPWIFIDEVICEPOWERSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸���߹������ñ������*/ 
#define AC_DB_WTPWIFIDEVICEADVANCEDSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸���߸߼����ñ������*/
#define AC_DB_WTPWIFIDEVICEWIDSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸WIDS���ñ������*/
#define AC_DB_WTPWIFIDEVICERESOURCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP �����豸������Դ�������ñ������*/
#else
#define AC_DB_WTPWIFIDEVICEBASICSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸�������ñ������*/
#define AC_DB_WTPWIFIDEVICECHANNELSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸�����ŵ����ñ������*/
#define AC_DB_WTPWIFIDEVICERATESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸�����������ñ������*/
#define AC_DB_WTPWIFIDEVICEPOWERSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸���߹������ñ������*/ 
#define AC_DB_WTPWIFIDEVICEADVANCEDSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸���߸߼����ñ������*/
#define AC_DB_WTPWIFIDEVICEWIDSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸WIDS���ñ������*/
#define AC_DB_WTPWIFIDEVICERESOURCESETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP �����豸������Դ�������ñ������*/
#endif

#define AC_DB_WTPAPBASICSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP�������ñ������*/ 
#define AC_DB_WTPAPSECURITYSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP��ȫ���ñ������*/
#define AC_DB_WTPAPADVANCEDSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* WTP VAP�߼����ñ������*/

#ifdef BIG_AC
#define AC_DB_WTPADHOCBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ADHOC�������ñ������*/
#define AC_DB_WTPADHOCSECURITYSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP ADHOC��ȫ���ñ������*/
#else
#define AC_DB_WTPADHOCBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP ADHOC�������ñ������*/
#define AC_DB_WTPADHOCSECURITYSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)4)	/* WTP ADHOC��ȫ���ñ������*/
#endif

#define AC_DB_WTPENETBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)2)	/* WTP ��̫�������ñ������*/

#define AC_DB_WTPROUTEBASICSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP·�ɻ������ñ������*/
#define AC_DB_WTPROUTENEIGHBORSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP·���ھӹ������ñ������*/
#define AC_DB_WTPROUTEHANDOVERSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP·���л��������ñ������*/
#define AC_DB_WTPROUTEDEVICEMSCSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP·���豸���ӹ������ñ������*/

#define AC_DB_WTPCAPWAPSETUP_CAPACITY					(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* WTP CAPWAP���ñ������*/

#ifdef BIG_AC
#define AC_DB_WTPALARMFILTERSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)64)	/* �澯�������ñ������*/
#define AC_DB_WTPALARMTHRESHOLDSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)		/* �澯�������ñ������*/
#define AC_DB_WTPPERFCOUNTERGROUPINFOSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)16)	/* �����������ñ������*/
#else
#define AC_DB_WTPALARMFILTERSETUP_CAPACITY				(AC_DB_WTP_NUM_MAX*(UINT32)128)	/* �澯�������ñ������*/
#define AC_DB_WTPALARMTHRESHOLDSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)1)		/* �澯�������ñ������*/
#define AC_DB_WTPPERFCOUNTERGROUPINFOSETUP_CAPACITY	(AC_DB_WTP_NUM_MAX*(UINT32)128)	/* �����������ñ������*/
#endif

/* add by gwx 2012-11-29 for AP/VAP����*/
#define AC_DB_WTPAPVAPMACFLOWCTRLSETUP_CAPACITY		(4096*16)		/* VAP-MAC�û����ر������*/

/* add by gwx 2013-10-11 for task1076 ��ҵ����������*/
#define AC_DB_WTPAPUSERGROUPQOSSETUP_CAPACITY			(AC_DB_WTP_NUM_MAX*(UINT32)9)	/* WTP VAP�������ñ������*/ 
/* add by gwx 2013-11-27 for task1153 */
#define AC_DB_WTPSYSLOCATORSETUP_CAPACITY		(AC_DB_WTP_NUM_MAX*(UINT32)1)	/* AP��λ�������ñ�����*/

/*AP ��ϵ�������궨�����*/
/******************************************************************************/

/******************************************************************************/
/* AP ��ϵ��ṹ�嶨�忪ʼ*/
/* WTP�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	CHAR	acWtpNEId[32];	/* AP ��Ԫ����*/
	UINT32	ulDeviceType  ;
	UINT8	aucDeviceId[6];	/* �豸���к�*/
	UINT8	aucResv[2];

	CHAR	acContact[64];	/*	�豸ά����ϵ��*/
	CHAR	acLocation[64];	/*	�豸����λ��*/
	CHAR	acCounty[64];	/* add by gwx 2011-12-9 �豸��������*/

	UINT32	ulMaxStaNum;	/* ������������û��� */
	CHAR	acHwVersion[32];
	CHAR	acUbootVersion[32];
	CHAR	acSwVersion[32];
	CHAR	acDeviceName[64];
	UINT32	ulCountryCode;
	UINT32	ulRunMode;		/* 0:����Ӧ	1:����ת��	2:����ת��*/
	UINT32	ulApTrafficVlan;	/* 0~4094 	
								0:��ʾ����VLAN 
								����:��ʾ����Ӧ��VLAN Tag */
	
	UINT32	ulLegalId;

	/* 2010/05/12 fengjing add */	
	UINT32	ulCollectSwitch;	/* 2010-4-10 pyy ����: ʵʱ�ɼ�����*/
	/* add by gwx 2013-1-8 for task368����ת��ʱAP����Ҳ���㲥ҵ��SSID */
	UINT32 	ulDisSsidSwitch;  /* AP���߹ر�SSID����0���ã�1����Ĭ�Ͽ���*/
	/* add by gwx 2013-3-27 for bug2242 */
	UINT32 	ulLinkOffRestartTime;		/* AP��������ʱ�䣬Ĭ��3600s����Сֵ300s */
	UINT32 	ulRptUserTrafficTime; 	/* AP�ϱ��û�����ʱ��������λ��*/
	/* add by gwx 2012-11-29 for AP/VAP������*/
	UINT32	ulFlowCtrlLevel;		/*������Ƽ���,0:sta, 1:VAP, 2:AP */
	UINT32	ulTotalUpBandMax;	/* �����ܴ������(kpbs) */
	UINT32	ulTotalDownBandMax;	/* �����ܴ������(kpbs) */
	/* add by gwx 2013-11-27 for task1143 */
	UINT32	ulL2EnableIsolate;	/* �û�������뿪��*/
	/* add by gwx 2013-11-26 for task1150 */
	UINT32	ulApCapwapMode;	/* capwap����Ƭģʽ����*/
	UINT32	ulApUserEthVlan;		/* add by gwx 2014-6-5 AP�������߿�vlan*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
	UINT32	ulCurAcId;
	UINT32	ulCfgVersion;	/* �������ݰ汾��*/
}AC_DB_TBL_WTPSYSBASICSETUP_T;

typedef struct 
{	
	UINT32	ulWtpId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
	UINT32	ulCommPort;	/* ͨѶ�˿ں� add by gwx 2013-4-7 fot task668*/
	UINT8	aucCommIp[4];		/* ͨѶIP  add by gwx 2013-4-7 fot task668 */
	UINT32	ulState;			/* 0: ����1: ���ڳ�ʼ��2: ����������*/
							/* 0: ���� 1: ������ 2:���� */
	UINT32	ulAssoState;		/* AP-AC����״̬
								NORMAL				0	 ����״̬����
								NODISCOVERY			1	 û���յ���������
								NOJOIN				2	û���յ���������
								CONNAUTHFAIL		3	 ��Ȩʧ��
								OTHER				4	 ����ԭ��
								*/
	UINT32	ulAcLanId;		/* AP ���ӵ�AC�˿ں�*/
	UINT32	ulVlanId;		/* 2009-12-14 pyy ����: AP�����VLAN ID */
	UINT32	ulBeginTime;		/* ��״̬��ʼʱ��*/

	UINT32	ulRegisterTime;			/*		ע��ʱ��	���״����ӵ�AC��ʱ��*/
	UINT32	ulLastConnTime;			/*		�ϴ�����ʱ�䣬���һ�ι���AC��ʱ��*/
	UINT32	ulLastVerUpdateTime;	/*		�ϴ������汾ʱ��	Oma֪ͨdbs */
	UINT32	ulLastCfgUpdateTime;	/*		�ϴθ�������ʱ��	Oma֪ͨdbs */

	UINT32	ulOfflineNum;			/* �ۼ����ߴ���*/

	CHAR     	acSwVersion[32];		//AP ��ǰ����汾��
     	CHAR	acTargetVersion[32];   // AP�豸Ŀ������汾��

     	/* 2010-12-9 pyy ����*/
     	UINT32	ulLastOnlineTime;		/* ���һ�����ߵ�ʱ���*/
     	UINT32	ulLastOfflineTime;		/* ���һ�����ߵ�ʱ���*/
     	UINT32	ulTotalOfflineTime;		/* ��Ӫ״̬AP�˷�ʱ��(����),���ߺ����ߵ�ʱ����Ӧ��ȥ���汾����ʱ�䣩 */
     	UINT32	ulTotalOnlineTime;		/* ��Ӫ״̬AP��ʱ��(����)��������ʱ����,�ۼ�ʱ�� */   
#if 0 
		CHAR	acCurChannelList[32];	/* add by gwx 2014-8-7 AP��ǰʹ���ŵ��б�*/
#else
	CHAR	acWifi0Channel[32];
	CHAR	acWifi1Channel[32];
#endif
} AC_DB_TBL_WTPDYNINFO_T;


/* AC��⵽��δע��AP�б�*/
typedef struct
{
	UINT32  	ulWtpId;      			//AP�豸ID
     	UINT8    	aucWtpIp[4];  		/* AP �豸IP */
		UINT8	aucSrcIp[4];			/* add by gwx 2014-10-17 ͨ��IP */
		UINT32	ulSrcPort;				/* add by gwx 2014-10-17 ͨ�Ŷ˿�*/
     	UINT32   ulIpOrigin;   			// AP IP���÷�ʽ  
     	UINT8    	aucMac[6];         		/* AP �豸MAC */
     	UINT8    	aucResv0[2];  		/* ����ֽ�*/
     	UINT32  	ulWtpModel;   		//AP�豸�ͺ�
     	UINT8   	aucWtpSn[6];  		//AP�豸���к�
     	UINT8    	aucResv[2];
     	UINT32   ulDisType;    			// AC���ַ�ʽ
     	CHAR     	acSwVersion[32];		//AP ��ǰ����汾��
     	CHAR	acTargetVersion[32];   // AP�豸Ŀ������汾��
     	UINT32  	ulWtpState;   		//AP�豸״̬
     	UINT32	ulRejectReason;		/* �ܾ�����ԭ�� */
			                                 /*
			                                 1:�豸ID��һ��
			                                 2:���벻һ��
			                                 3:�豸�ͺŲ�һ��
			                                 4:�豸���кŲ�һ��
			                                 */
	UINT32   ulAcLanId;    /* AC �˿�
                       0-16����ʾLANx
                       >=16������ʾN/A*/
	UINT32	ulVlanId;		/* 2009-12-14 pyy ����: AP�����VLAN ID */
    	UINT32  ulBeginTime;        		//��״̬��ʼʱ��
    	UINT32  ulStatePeriod;      		//��״̬����ʱ��
     	UINT32  ulStaNum;           			//��ǰ�����û���
     	UINT32   ulStaAccNum;  			/* �û��������*/
    	UINT32  ulStaOnlineTime;    		/* �û�������ʱ��, ��λ���� */
     	UINT32   ulRegisterTime;			/*       ע��ʱ�� ���״����ӵ�AC��ʱ��*/
     	UINT32   ulLastConnTime;			/*       �ϴ�����ʱ�䣬���һ�ι���AC��ʱ��*/
     	UINT32   ulLastVerUpdateTime;   	/*       �ϴ������汾ʱ��   Oma֪ͨdbs*/
     	UINT32   ulLastCfgUpdateTime;   	/*       �ϴθ�������ʱ��   Oma֪ͨdbs */
	/* add by gwx 2014-3-26 for APһ��ע��begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for APһ��ע��end*/
     	
} AC_DB_TBL_WTPROGUEAP_T;


/* WTP IP���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulIpOrigin;
	UINT8	aucIpAddr[4];
	UINT8	aucNetMask[4];
	UINT8	aucDefaultGw[4];
	UINT8	aucPrimaryDns[4];	/*	��DNS������	*/
	UINT8	aucSecondaryDns[4];	/*	��DNS������	*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSIPSETUP_T;

/* WTP ���ؾ������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulLbUserNumSwitch;	/*	�û���������ƿ���*/
	UINT32	ulUserNumPermitted;	/*	�û���������������*/
	UINT32	ulUserNumOffsetThreshold;/*	�û���ƫ������*/
	UINT32	ulUserNumDynamic;		/* �û�����̬���ɾ���*/
	UINT32	ulLbUserQosSwitch;		/*����������ƿ���*/
	UINT32	ulUserQosPermitted;		/*	����������������*/
	UINT32	ulUserQosOffsetThreshold;	/*	����ƫ������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSLOADBALANCESETUP_T;

/* WTP LOG�������ñ�*/
typedef struct {
	UINT32	ulWtpId;		/* �豸ID */

	UINT32	ulLogLevel;		/*	���𿪹�	*/
	UINT32	ulLogModule;	/*	ģ�鿪��	*/
	UINT32	ulLogToStdOut;	/*	�Ƿ��ӡ����׼���	*/
	UINT32	ulLogToServer;	/*	�Ƿ��͵���־������	*/
	UINT8	aucLogSvrIp[4];	/*	��־������IP��ַ	*/
	UINT32	ulLogSvrPort;	/*	��־�������˿ں�	*/
	UINT32	ulLogTransType;	/*	��־��������	*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DB_TBL_WTPSYSLOGSETUP_T;

/* WTP������������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT8	aucFtpServerIpAddr[4];
	UINT32	ulFtpServerPort;
	CHAR	acFtpUserName[32];	/*	FTP�û���	*/
	CHAR	acFtpPassword[32];	/*	FTP����	*/
	CHAR	acSwFileName[128];	/*	�ļ���	*/

	CHAR	acSpecificSwVersion[32];
	UINT32	ulUpgradeStrategy;
	UINT32	ulActivationPolicy;	/* ��Ч��ʽ:
								0������������Ч
								1���ֹ�������Ч
								2���ӳ���Ч
								*/
	UINT32	ulActivationTime;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSSWSERVERSETUP_T;

/* WTP SNTP���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulEnableSntp;
	UINT8	aucSntpServerIp[4];
	UINT32	ulPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSSNTPSETUP_T;

typedef struct 
{
	UINT32	ulWtpId;
	
	UINT32	ulEnableSntp;
	UINT8	aucSntpServerIp[4];
	UINT32	ulPeriod;
	CHAR	acUserName[32];
	CHAR	acNetworkName[32];
	CHAR	acPassword[32];
	UINT32	ulDnsMode;
	CHAR	acServiceName[32];
	CHAR	acAcName[32];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPSYSPPPOESETUP_T;

/* WTP �����豸�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	CHAR	acWifiDeviceInfo[32];
	UINT32	ulWifiDeviceType;
	UINT32	ulMaxStaNum;
	
	UINT32	ulWifiDeviceRunMode;
	UINT32	ulWifiModuleNum;
	UINT32	aulWifiModuleId[4];
	UINT32	aulWifiModuleType[4];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
}AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T;

/* WTP�����豸�����ŵ����ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiAbgMode;
	UINT32	ulWifiChannelMode;
	UINT32	ulWifiTurboMode;
	UINT32	ulWifiChannelType;
	UINT32	aulWifiChannel[16];

	UINT32	ulFrequPointQualitySwitch;	/*	�ŵ���ѡ����	*/
	UINT32	ulRssiThreshold;				/*	�ŵ���ѡRSSI����	*/
	UINT32	ulNoiseThreshold;			/*	�ŵ���ѡ��������	*/

	UINT32	ulWifiAbgModeType;


	UINT32	ulBand;	/* Ƶ�� 	1��20MHz
								2��20/40MHz���Զ���
 								1��20MHz
					*/
	UINT32	ulRFNum;	/*  �ռ������� 1~4 */
	UINT32	ulShortGI;	/* SGI���ܿ���
 							0������
							1������*/
	UINT32	ulAMPDU;	/* A-MPDU���ܿ���
 							0������
							1������
						*/
	UINT32	ulAMSDU;	/* A-MSDU���ܿ���
 						 0������
						1������
						*/
 	UINT32	ulOnly11n;	/* ��11n�û����빦��
 							 0������
							1������
							 ����ʱ��ֻ��11n�ն˿��Թ�������11n�ն��޷�����
						*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T;

/* WTP�����豸�����������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	/* add by gwx 2012-12-26 for task336 ���������Ż�*/
	UINT32	ulStaUpRateMin;
	UINT32 	ulStaDownRateMin;
	
	//UINT32	ulWifiMaxTxRate;
	UINT32	ulWifiMgmTrate;
	UINT32	ulWifiMcasTrate;
	UINT32	ulWifiMgmtRetrys;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICERATESETUP_T;

/* WTP�����豸���߹������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiLimitTxPower;	/* ����书��*/
	UINT32	ulWifiMaxTxPower;	/* ����˥������ */

	UINT32	ulInterfereDetectSwitch;	/*	���书���Զ�����		0������1������*/
	UINT32	ulInterfereDetectPeriod;	/*	���ʵ�������		1~60 */
	UINT32	ulMaxInterferePermitted;	/*	���ʵ�����Ŀ��RSSI		>0 */
	UINT32	ulRssiWaveRange;		/*	Ŀ��RSSI������Χ		3��10 */
	UINT32	ulPowerCompensationSwitch;	/*	���ڸ��ǲ�������		0������1������*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulDynPower;
}AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T;


/* WTP �����豸���߸߼�����*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulWifiBeaconInterval;
	UINT32	ulWifiDtimInterval;
	UINT32	ulWifiPreambleType;
	UINT32	ulWifiFragmThreshold;
	UINT32	ulWifiRtsThreshold;
	UINT32	ulLongRtsThreshold;	/* ��֡�ش�����*/
	UINT32	ulShortRtsThreshold;	/* ��֡�ش�����*/
	UINT32	ulCacheTime;		/*	�������ݰ�������*/

	UINT32	ulWifiCtsProtectionMode;
	UINT32	ulTxDistOptSwitch;
	UINT32	ulMaxTxDistance;

	/* add by gwx 2014-7-30 */
	UINT32	ul11nHigherPri;		/* 11n�������ȿ���0�ر�1������Ĭ�Ϲر�*/
	UINT32	ul5GHigherPri;		/* 5G�������ȿ���0�ر�1������Ĭ�Ϲر�*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T;

/* WTP �����豸WIDS���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;


	/* �����ն�*/
	UINT32	ulDosAttackDetectSwitch;
	UINT32	ulDosAttackPeriod;		/*	���鹥��ͳ������		>0	60	��*/
	UINT32	ulDosAttackThreshold;	/*	���鹥���ж�����		>0	30	*/

	UINT32	ulDosAttackDefenseSwitch;
	UINT32	ulInvalidTerminalAgeingTime;

	UINT32	ulSpoofAttackDetectSwitch;	/* Spoof������⿪��*/
	UINT32	ulWeekIVAttackDetectSwitch;	/* Week IV��⿪��*/
 	UINT32	ulStaDisturbDetectSwitch;		/* �ն˸��ż�⿪��*/
	UINT32	ulStaDisturbLimit;			/* �ն˸�������,������:pps */

	/* 2010/07/01 fengjing cmcc test */
    UINT32  ulAPInterfNumThreshhd;      /* AP���Ÿ澯���� */
	UINT32  ulStaInterfNumThreshhd;     /* �ն˸��Ÿ澯���� */
	INT32   lAPCoInterfThreshhd;        /* APͬƵ���Ÿ澯���� */  
	INT32   lAPNeiborInterfThreshhd;    /* AP��Ƶ���Ÿ澯���� */
	
	UINT32	ulMacNum;					/* �Ϸ��ն�MAC��Ŀ*/
	UINT8 	aaucMac[16][8];				/* �Ϸ��ն�MAC�б�*/

	/* ����AP */
	UINT32	ulInvalidApDetectSwitch;		/* ����AP���*/
	
	UINT32	ulSsidNum;					/* �Ϸ�AP SSID��Ŀ*/
 	UINT8	aaucSsid[16][32];				/* �Ϸ� AP SSID�б�*/ 
	UINT32	ulBssidNum;					/* �Ϸ� AP BSSID��Ŀ*/
 	UINT8	aaucBssid[16][8];			 /*�Ϸ�AP BSSID�б�*/ 
	UINT32	ulListOuiNum;				/* �Ϸ�AP OUI��Ŀ*/
 	UINT8	aaucOui[16][4];				/*�Ϸ�AP OUI�б�*/
 
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T;

/* WTP �����豸������Դ�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulMoniMode;					/* ���߻������ģʽ 
										1���ṩWLAN�������
										2���������߻���
										3������ʱ�������߻���
										*/
										
	UINT32	aulDiffScanChannelList[16];
	UINT32	ulDiffScanInterval;
	UINT32	ulDiffScanResidenceTime;

	/* ͬƵɨ��*/
	UINT32	ulSameScanInterval;
	UINT32	ulNeighAutoScanSwitch;	/*	�����ھ��Զ�ɨ��	*/
	UINT32	ulNeighRssiMin;			/*	�ھ��ź�ǿ����С����	*/
	UINT32	ulNeighRssiWave;		/*	�ھ��ź�ǿ�Ȳ�����Χ	*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T;
 
/* WTP VAP�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulRunMode;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	CHAR	acSsid[32];
	UINT32	ulBroadcastSsid;
	UINT32	ulMaxSimultUsers;	/*	������������û���	*/
	UINT32	ulMaxSimultTraffic;		/*	�������	*/

	/* add by gwx 2012-11-29 for AP/VAP ������*/
	UINT32	ulTotalUpBandMax;		/* �����ܴ������(kbps) */
	UINT32	ulTotalDownBandMax;	/* �����ܴ������(kbps) */
	/* 2010-4-19 pyy ����*/
	UINT32	ulTrafficMode;		/* ҵ��ת��ģʽ	1:����ת�� 2:����ת��*/
	UINT32	ulApTrafficVlan;		/* ҵ��VLAN  0~4094 */
	UINT32	ulPrdOff;			/* �Ƿ��ڹر�*/
	UINT32	ulStartTime;			/*	��ʼʱ��*/
	UINT32	ulEndTime;			/*	����ʱ��*/
	/* add by gwx 2013-1-8 for task369��AP��ȥ������SSID��management��*/
	UINT32 	ulWifiEnable;	/* ssid becon����0:�ر�1:����,Ĭ�Ͽ���*/
	/* add by gwx 2013-12-10 for task1170 */
	UINT32	ulMacFilterType;		/* �û��������0:�޲���1:������2:������3:������OUI 4:������OUI */
	UINT32	ulUserMacNum;		/* MAC��ַ��Ŀ*/
	UINT8	aaucUserMac[32][6];	/* MAC��ַ*/
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

	UINT32	ulAdminState;
	UINT32	ulOpState;
}AC_DB_TBL_WTPAPBASICSETUP_T;


/* WTP VAP��ȫ���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulAuthenticationType;
	UINT32	ulSecurityMode;
	UINT32	ulWapiSetupId;	/*	WAPIЭ������		����acWapiSetup��	���е�һ��	*/
	UINT32	ulCertFileId;		/*	WAPI֤��		����acWapiCertFile��	���е�һ��	*/
	CHAR	acWapiPsk[64];	/*	WAPI PSK����			wapi_psk_password	���ȣ�8 -- 64*/

	CHAR	acWpaKey[64];
	UINT32	ulWpaKeyRenewal;
	UINT32	ulWepKeyLen;
	UINT32	ulWepKeyFormat;
	CHAR	acWepKey[26];
	UINT8	aucResv[2];
	UINT32	ulWepKeyIndex;
	UINT32	ul8021xMode;
	UINT32	ulEapolVer;
	UINT32	ulEapAuthPeriod;
	UINT32	ulWepBroadcastKeyLen;
	UINT32	ulWepUnicastKeyLen;
	UINT32	ulWepRekeyPeriod;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPSECURITYSETUP_T;

/* WTP VAP�߼����ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulPrivCap;
	UINT32	ulPowerCtrl;
	UINT32	ulEndUserTime;
	UINT32	ulWmmQos;
	UINT32	ulQosType;
	UINT32	ulAcLowLimit;
	UINT32	ulAcUpLimit;
	UINT32 	ulRxRateLimit;	/* add by gwx 2012-11-27 �û�����AP������������*/
	UINT32	ulTxRateLimit;	/* add by gwx 2012-11-27 �û�����AP������������*/
	UINT32	ulAcInterval;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPADVANCEDSETUP_T;

/* WTP VAP MAC���˲������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT32	ulMacFilterSwitch;
	UINT32	ulMacFilterDefaultPolicy;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPMACFILTERSETUP_T;

/* WTP VAP MAC�����б����ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT8	aucMacAddr[6];
	UINT8	aucResv[2];
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPMACFILTERLISTSETUP_T;

/* WTP VAPͳ�ƹ�ϵ��ṹ�嶨�� : ��̬��*/
typedef struct {
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;
    
    	UINT32  ulOnlineTime;   /* ͳ�Ƽ����VAP�������û�������ʱ��֮��, ��λ: s */
    	UINT32  ulUpTraffic;    /* ͳ�Ƽ����VAP��������, ��λ:Kbps */
    	UINT32  ulDownTraffic;  /* ͳ�Ƽ����VAP��������, ��λKbps */

    	UINT32  ulStatCounter;      /* �����û���ͳ�ƴ��� */
    	UINT32  ulOnlineUserNum;    /* ��ǰʵʱ�����û��� */

	UINT32	ulUserNum;		/* �����û���ͳ��ֵ */
	UINT32	ulUserInNum;	/* �û��������*/
	UINT32	ulUserOutNum;	/* �û��뿪����*/
#if 0
	/* 2010-12-9 pyy: ����WEB��֤���ͳ��*/
	UINT32 	ulOfflineUserNum;   	/* WEB��֤�û��쳣���ߴ���*/
    	UINT32 	ulAuthReq;			/* WEB��֤������ */
    	UINT32 	ulAuthSucc;			/* WEB��֤�ɹ���  */
    	
    	/* 2011-1-12 pyy add */
    	UINT32	ulWebOnlineTime;	/* VAP�������û����ۼ�WEB��֤����ʱ��(�û�����ʱ��) , ��λ:�� */
#endif
#if 0
	/* �����û��� */
	UINT32 	ulPortalOnlineUserNum;    		/*��ǰͨ��WEB��֤�������û���*/
	UINT32 	ulFreeOnlineUserNum;    		/*��ǰ����֤�������û���*/
	UINT32 	ulAssociateOnlineUserNum;    	/*��ǰͨ��������֤�������û���*/
	UINT32 	ulMacOnlineUserNum;    		/*��ǰͨ��MAC��֤�������û���*/
#endif
	
	/* �쳣���ߴ��� */
	UINT32 	ulPortalOfflineUserNum;   		/*Portal��֤�û��쳣���ߴ���*/
	UINT32 	ulFreeOfflineUserNum;   		/*����֤�û��쳣���ߴ���*/
	UINT32 	ulAssociateOfflineUserNum;   	/*������֤�û��쳣���ߴ���*/
	UINT32 	ulMacOfflineUserNum;   		/*MAC��֤�û��쳣���ߴ���*/
	
	/* ��֤������ */
	UINT32 	ulPortalAuthReq;          		/*Portal��֤������*/
	UINT32 	ulAssociateAuthReq;          	/*������֤������*/
	UINT32 	ulMacAuthReq;          		/*MAC��֤������*/
	
	/* ��֤�ɹ��� */
	UINT32 	ulPortalAuthSucc;         		/*Portal��֤�ɹ���*/
	UINT32 	ulAssociateAuthSucc;         	/*������֤�ɹ���*/
	UINT32 	ulMacAuthSucc;         		/*MAC��֤�ɹ���*/
#if 0
	UINT32 	ulPortalAuthFail;         		/*Portal��֤ʧ����*/
	UINT32 	ulAssociateAuthFail;         	/*������֤ʧ����*/
	UINT32 	ulMacAuthFail;         		/*MAC��֤ʧ����*/
#endif	
	/* �û�������ʱ�� */
	UINT32 	ulPortalTotalOnlineTime;  		/*Portal��֤�û�������ʱ��*/
	UINT32	ulFreeTotalOnlineTime;  		/*����֤�û�������ʱ��*/
	UINT32 	ulAssociateTotalOnlineTime;  	/*������֤�û�������ʱ��*/
	UINT32 	ulMacTotalOnlineTime;  		/*MAC��֤�û�������ʱ��*/

	/* add by gwx 2014-6-23 */
	UINT32	ulCurUserNum;	/* ��ǰ�û�������for �û�������*/
		
    	UINT32  ulMOC;
    	UINT8   aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPAPSTAT_T;


/* VAP�û�����ͳ��/�տ��շ�ͳ����Ϣ*/
typedef struct
{	
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;

    	/* �տ��շ�ͳ��*/
	UINT32	ulUpByte;				/*	����������*/
	UINT32	ulDownByte;				/*	����������*/
	UINT32	ulUpFrame;				/*	������֡��*/
	UINT32	ulUpErrFrame;			/*	���д���֡��*/
	UINT32	ulUpDiscardFrame;		/*	���ж�֡��*/
	UINT32	ulUpRetransFrame;		/*	�����ش�֡��*/
	UINT32	ulDownFrame;			/*	������֡��*/
	UINT32	ulDownErrFrame;			/*	���д���֡��*/
	UINT32	ulDownDiscardFrame;	/*	���ж�֡��*/
	UINT32	ulDownRetransFrame;	/*	�����ش�֡��*/
	UINT32	ulUpAssoFrame;			/* ���й���֡��*/
	UINT32	ulDownAssoFrame;		/* ���й���֡��*/

	/* �û�����ͳ��*/
	UINT32	ulAccessTimes;		/*	AP�������û����Ӵ���*/
	UINT32	ulAccessFailTimes;	/*	AP�������û�����ʧ�ܴ���*/
	UINT32	ulAccessRetryTimes;	/*	AP�������û������Ӵ���*/
	UINT32	ulAccessDenyTimes;	/*	AP�������û����Ӿܾ�����*/
	UINT32	ulAccessOutTimes1;	/*	���û��뿪�����½�����Ĵ���*/
	UINT32	ulAccessOutTimes2;	/*	��AP������������½�����Ĵ���*/
	UINT32	ulAccessOutTimes3;	/*	���쳣��������½�����Ĵ���*/
	UINT32	ulAccessOutTimes4;	/*	����ԭ���½�����Ĵ���*/
} AC_DB_TBL_WTPAPWIFISTAT_T;


/* WTP ADHOC�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulAdhocId;
	UINT32	ulRunMode;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	CHAR	acSsid[32];
	UINT32	ulBroadcastSsid;
	UINT32	ulWifiArithmeticMode;
	UINT32	ulAntennaMode;
	UINT32	ulMeshType;
	UINT32	ulWmmQos;
	UINT32	ulQosType;
	UINT32	ulPrivCap;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPADHOCBASICSETUP_T;


/* WTP ADHOC��ȫ���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulWifiDeviceId;
	UINT32	ulAdhocId;
	UINT32	ulAuthenticationType;
	UINT32	ulWepKeyLen;
	CHAR	acWepKey[32];
	UINT32	ulDataEncrypt;
	UINT32	ulAuthenticationTimeout;
	UINT32	ulAuthenticationRetry;
	
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPADHOCSECURITYSETUP_T;


/* WTP ��̫�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulEnetPortId;
	UINT32	ulEnetRunMode;
	UINT32	ulSpeedUplex;
	UINT32	ulEnetState;
	UINT32	ulPrivCap;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPENETBASICSETUP_T;

/* WTP·�ɻ������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulNodeGwRunMode;
	UINT32	ulNetDiameter;
	UINT8	aucRouteFavorFatherMac[6];
	UINT8	aucResv1[2];	
	
	UINT32	ulRouteFavorMinCost;
	UINT8	aucDeviceId[6];
	UINT8	aucResv2[2];	

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEBASICSETUP_T;

/* WTP·���ھӹ������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteMinNeighborPathcost;
	UINT32	ulRouteHelloInterval;
	UINT32	ulRouteHelloCombine;
	UINT32	ulRouteNeighScanThreshold;
	UINT32	ulRouteNeighScanInterval;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTENEIGHBORSETUP_T;

/* WTP·���л��������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteHigh4father;
	UINT32	ulRouteLow4father;
	UINT32	ulRouteHoldQuality;
	UINT32	ulRouteHoldTime;
	UINT32	ulRouteDuxPathCost;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEHANDOVERSETUP_T;

/* WTP·���豸���ӹ������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulRouteMsRunMode;
	UINT32	ulRouteMsDeviceName;
	UINT32	ulRouteDataDeviceName;
	UINT32	ulRouteMsRole;
	UINT32	ulRouteForwardForbidden;
	UINT32	ulRouteMaxMsQueryLoss;
	UINT32	ulRouteMinimalAirbandQual;
	UINT32	ulRouteWifiAdhocBandWidth;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T;

/* WTP CAPWAP���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	CHAR	acSecret[32];
	UINT32	ulDisType;
	CHAR	acAcURL[64];

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];

}AC_DB_TBL_WTPCAPWAPSETUP_T;
 
/* �澯���ñ�*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulAlarmNo;
	CHAR	acAlarmName[32];
	UINT32	ulAlarmIsValid;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPALARMIFILTERSETUP_T;

typedef struct
{
	UINT32	ulAlarmNo;
	UINT32	ulAlarmIsValid;
} AC_DB_ALARMIFILTER_T;

/* AP  �澯�������ñ�*/
typedef struct {
	UINT32	ulWtpId;					/* �豸ID */
	
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
	UINT32	ulLowTempHigh;		/*		�豸���¸澯��������	��50��0	��30	��*/
	UINT32	ulLowTempLow;		/*		�豸���¸澯��������	��50��0	��20	��*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T;

/* �����������ñ��*/
typedef struct 
{
	UINT32	ulWtpId;

	UINT32	ulCounterGroupId;
	UINT32	ulCounterGroupIsInvalid	;
	UINT32	ulCounterGroupPeriod;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
}AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T;

/* add by gwx 2012-11-29 for AP/VAP������,
VAP-MAC�û����ر�*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulWifiDeviceId;
	UINT32	ulVapId;
	UINT8	aucMac[6];
	UINT8	aucResv[2];
	
	UINT32	ulUserUpBandMax;
	UINT32	ulUserDownBandMax;

	UINT32	ulAddFlag;
	UINT32	ulAddRspFlag;
	UINT32	ulDelFlag;
	UINT32	ulDelRspFlag;	
}AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T;


/* add by gwx 2013-10-11 for task1076 ��ҵ���û�������*/
/* �û����������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulUserGroupId;
	UINT32	ulUserGroupUpBandMax;
	UINT32	ulUserGroupDownBandMax;

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];	
}AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T;

/* add by gwx 2013-11-27 for task1153 */
/* AP��λ�������ñ�*/
typedef struct 
{
	UINT32	ulWtpId;
	UINT32	ulLocatorSwitch;		/* ��λ���ܿ���*/
	UINT32	ulReportInterval;	/* ���ͱ���ʱ����,��λs*/
	UINT32	ulTypeName;		/* ��Ҫɨ��������豸����*/
	UINT8	aucServerIp[4];		/*  ��λ������IP*/
	UINT32	ulServerPort;		/* ��λ�������˿ں�*/
	UINT32	ulFilterSwitch;		/* ��ȡMAC��ַ���˿���*/
	UINT32 	aulFilterMacLen[5];		/* MAC��ַƥ�䳤��*/
	UINT8	aaucFilterMac[5][6];		/* MAC��ַƥ�����*/
	UINT8	aucRsv[2];			/* �����ֶ�*/
	/* add by gwx 2014-7-21 for ��λ������չ*/
	UINT32	ulLocatorEngine;	/* ��λ���泧��*/
	UINT8	aucLocatorChannel[16];	/* ɨ���ŵ�����*/

	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];	
}AC_DB_TBL_WTPSYSLOCATORSETUP_T;

/* AP ��ϵ��ṹ�嶨�����*/
/******************************************************************************/


/******************************************************************************/
/* ����������ʼ*/
/* �������ñ�*/
extern DBHANDLE	ghWtpSysBasicSetup;
extern DBHANDLE	gidxWtpSysBasicSetup1;
extern DBHANDLE	gidxWtpSysBasicSetup10;

/* AP ��̬��Ϣ��*/
extern DBHANDLE	ghWtpDynInfo;
extern DBHANDLE	gidxWtpDynInfo1;
extern DBHANDLE	gidxWtpDynInfo2;

/* AC��⵽��δ����AP�б�*/
extern DBHANDLE	ghWtpRogueAp;
extern DBHANDLE	gidxWtpRogueAp1;

/* IP���ñ�*/
extern DBHANDLE	ghWtpSysIpSetup;
extern DBHANDLE	gidxWtpSysIpSetup1;
//extern DBHANDLE	gidxWtpSysIpSetup2;
extern DBHANDLE	gidxWtpSysIpSetup10;

/* ���ɾ������ñ�*/
extern DBHANDLE	ghWtpSysLoadBalanceSetup;
extern DBHANDLE	gidxWtpSysLoadBalanceSetup1;
extern DBHANDLE	gidxWtpSysLoadBalanceSetup10;

/* ��־���ñ�*/
extern DBHANDLE	ghWtpSysLogSetup;
extern DBHANDLE	gidxWtpSysLogSetup1;
extern DBHANDLE	gidxWtpSysLogSetup10;

/* ����汾���ñ�*/
extern DBHANDLE	ghWtpSysSwServerSetup;
extern DBHANDLE	gidxWtpSysSwServerSetup1;
extern DBHANDLE	gidxWtpSysSwServerSetup10;

/* SNTP�ͻ������ñ�*/
extern DBHANDLE	ghWtpSysSntpSetup;
extern DBHANDLE	gidxWtpSysSntpSetup1;
extern DBHANDLE	gidxWtpSysSntpSetup10;

/* �����豸�������ñ�*/
extern DBHANDLE	ghWtpWifiDeviceBasicSetup;
extern DBHANDLE	gidxWtpWifiDeviceBasicSetup1;
extern DBHANDLE	gidxWtpWifiDeviceBasicSetup10;

/* �����豸�ŵ����ñ�*/
extern DBHANDLE	ghWtpWifiDeviceChannelSetup;
extern DBHANDLE	gidxWtpWifiDeviceChannelSetup1;
extern DBHANDLE	gidxWtpWifiDeviceChannelSetup10;

/* �����豸�������ñ�*/
extern DBHANDLE	ghWtpWifiDeviceRateSetup;
extern DBHANDLE	gidxWtpWifiDeviceRateSetup1;
extern DBHANDLE	gidxWtpWifiDeviceRateSetup10;

/* �����豸�������ñ�*/
extern DBHANDLE	ghWtpWifiDevicePowerSetup;
extern DBHANDLE	gidxWtpWifiDevicePowerSetup1;
extern DBHANDLE	gidxWtpWifiDevicePowerSetup10;

/* �����豸�߼����ñ�*/
extern DBHANDLE	ghWtpWifiDeviceAdvancedSetup;
extern DBHANDLE	gidxWtpWifiDeviceAdvancedSetup1;
extern DBHANDLE	gidxWtpWifiDeviceAdvancedSetup10;

/* �����豸WIDS���ñ�*/
extern DBHANDLE	ghWtpWifiDeviceWidsSetup;
extern DBHANDLE	gidxWtpWifiDeviceWidsSetup1;
extern DBHANDLE	gidxWtpWifiDeviceWidsSetup10;

/* �����豸���߻���������ñ�*/
extern DBHANDLE	ghWtpWifiDeviceResourceSetup;
extern DBHANDLE	gidxWtpWifiDeviceResourceSetup1;
extern DBHANDLE	gidxWtpWifiDeviceResourceSetup10;

/* VAP�������ñ�*/
extern DBHANDLE	ghWtpApBasicSetup;
extern DBHANDLE	gidxWtpApBasicSetup1;
extern DBHANDLE	gidxWtpApBasicSetup2;
extern DBHANDLE	gidxWtpApBasicSetup3;
extern DBHANDLE	gidxWtpApBasicSetup4;
extern DBHANDLE	gidxWtpApBasicSetup10;

/* VAP��ȫ���ñ�*/
extern DBHANDLE	ghWtpApSecuritySetup;
extern DBHANDLE	gidxWtpApSecuritySetup1;
extern DBHANDLE	gidxWtpApSecuritySetup2;
extern DBHANDLE	gidxWtpApSecuritySetup3;
extern DBHANDLE	gidxWtpApSecuritySetup10;

/* VAP�߼����ñ�*/
extern DBHANDLE	ghWtpApAdvancedSetup;
extern DBHANDLE	gidxWtpApAdvancedSetup1;
extern DBHANDLE	gidxWtpApAdvancedSetup10;

/* VAP��̬ͳ����Ϣ��*/
extern DBHANDLE	ghWtpApStat;
extern DBHANDLE	gidxWtpApStat1;
extern DBHANDLE	gidxWtpApStat2;
extern DBHANDLE	gidxWtpApStat10;

extern DBHANDLE	ghWtpApWifiStat;
extern DBHANDLE	gidxWtpApWifiStat1;
extern DBHANDLE	gidxWtpApWifiStat2;

/* ADHOC�������ñ�*/
extern DBHANDLE	ghWtpAdhocBasicSetup;
extern DBHANDLE	gidxWtpAdhocBasicSetup1;
extern DBHANDLE	gidxWtpAdhocBasicSetup10;

/* ADHOC��ȫ���ñ�*/
extern DBHANDLE	ghWtpAdhocSecuritySetup;
extern DBHANDLE	gidxWtpAdhocSecuritySetup1;
extern DBHANDLE	gidxWtpAdhocSecuritySetup10;

/* ��̫�������ñ�*/
extern DBHANDLE	ghWtpEnetBasicSetup;
extern DBHANDLE	gidxWtpEnetBasicSetup1;
extern DBHANDLE	gidxWtpEnetBasicSetup10;

/* ·�ɻ������ñ�*/
extern DBHANDLE	ghWtpRouteBasicSetup;
extern DBHANDLE	gidxWtpRouteBasicSetup1;
extern DBHANDLE	gidxWtpRouteBasicSetup10;

/* ·���ھӹ������ñ�*/
extern DBHANDLE	ghWtpRouteNeighborSetup;
extern DBHANDLE	gidxWtpRouteNeighborSetup1;
extern DBHANDLE	gidxWtpRouteNeighborSetup10;

/* ·���л��������ñ�*/
extern DBHANDLE	ghWtpRouteHandoverSetup;
extern DBHANDLE	gidxWtpRouteHandoverSetup1;
extern DBHANDLE	gidxWtpRouteHandoverSetup10;

/* ·���豸�������ñ�*/
extern DBHANDLE	ghWtpRouteDeviceMscSetup;
extern DBHANDLE	gidxWtpRouteDeviceMscSetup1;
extern DBHANDLE	gidxWtpRouteDeviceMscSetup10;

/* AC�������ñ�*/
extern DBHANDLE	ghWtpCapWapSetup;
extern DBHANDLE	gidxWtpCapWapSetup1;
extern DBHANDLE	gidxWtpCapWapSetup10;

/* �߼��������ñ�*/
extern DBHANDLE	ghWtpAlarmFilterSetup;
extern DBHANDLE	gidxWtpAlarmFilterSetup1;
extern DBHANDLE	gidxWtpAlarmFilterSetup10;

/* �澯�������ñ�*/
extern DBHANDLE	ghWtpAlarmThresholdSetup;
extern DBHANDLE	gidxWtpAlarmThresholdSetup1;
extern DBHANDLE	gidxWtpAlarmThresholdSetup10;

/* ���ܼ����������ñ�*/
extern DBHANDLE	ghWtpPerfCounterGroupInfoSetup;
extern DBHANDLE	gidxWtpPerfCounterGroupInfoSetup1;
extern DBHANDLE	gidxWtpPerfCounterGroupInfoSetup10;

/* VAP-MAC�û����ر�*/
extern DBHANDLE	ghWtpApVapMacFlowCtrlSetup;
extern DBHANDLE	gidxWtpApVapMacFlowCtrlSetup1;

/* �û����������ñ�*/
/* add by gwx 2013-10-11 for task1076 ��ҵ���û�����������*/
extern DBHANDLE	ghWtpApUserGroupQosSetup;
extern DBHANDLE	gidxWtpApUserGroupQosSetup1;
extern DBHANDLE	gidxWtpApUserGroupQosSetup10;

/* AP ��λ�������ñ�*/
/* add by gwx 2013-11-27 for task1153 */
extern DBHANDLE	ghWtpSysLocatorSetup;
extern DBHANDLE	gidxWtpSysLocatorSetup1;
extern DBHANDLE	gidxWtpSysLocatorSetup10;

extern DBHANDLE	gahCwTblList[64];
extern UINT32		gulCwTblNum;
/* ������������*/
/******************************************************************************/

/******************************************************************************/
/* ����������ʼ*/
extern UINT32    ac_db_aptable_init (VOID);
extern UINT32	  ac_db_tbl_wtpmergekey (UINT8 *pucKey, DBHANDLE hTbl, UINT32 ulWtpId, DBHANDLE *phIdx);

extern UINT32    ac_db_table_wtpsysbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpsysbasicsetup_check (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_preinsert (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_predelete (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_preupdate (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern VOID ac_db_table_wtpsysbasicsetup_mergekey2 (UINT8 *pucKey,  UINT8 *pucDeviceId);
extern UINT32    ac_db_table_wtpsysbasicsetup_setdyndata (AC_DB_TBL_WTPSYSBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysbasicsetup_trigger (UINT8 ucModType);
extern UINT32	 ac_db_table_wtpsysbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpdyninfo_create (VOID);
extern VOID ac_db_table_wtpdyninfo_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
#if 0 /* mod by gwx 2013-4-7 for task668 */
extern VOID ac_db_table_wtpdyninfo_mergekey2 (UINT8 *pucKey, UINT32	ulAcLanId, UINT32 ulWtpId);
#else
extern VOID ac_db_table_wtpdyninfo_mergekey2 (UINT8 *pucKey, UINT32 ulCommPort, UINT8* aucCommIp, UINT32 ulWtpId);
#endif
extern UINT32	ac_db_table_wtpdyninfo_delcfg(UINT32 ulWtpId);

extern UINT32		ac_db_table_wtprogueap_create(VOID);
extern VOID		ac_db_table_wtprogueap_mergekey1(UINT8 *pucKey, UINT8 *pucDeviceId);

extern UINT32    ac_db_table_wtpsysipsetup_create (VOID);
extern UINT32    ac_db_table_wtpsysipsetup_check (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_preinsert (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_predelete (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_preupdate (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysipsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysipsetup_setdyndata (AC_DB_TBL_WTPSYSIPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysipsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysipsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysipsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysipsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsysloadbalancesetup_create (VOID);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_check (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_preinsert (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_predelete (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_preupdate (AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysloadbalancesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysloadbalancesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysloadbalancesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysloadbalancesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysloadbalancesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsyslogsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyslogsetup_check (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_preinsert (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_predelete (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslogsetup_preupdate (AC_DB_TBL_WTPSYSLOGSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyslogsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsyslogsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyslogsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyslogsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyslogsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsysswserversetup_create (VOID);
extern UINT32    ac_db_table_wtpsysswserversetup_check (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_preinsert (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_predelete (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsysswserversetup_preupdate (AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsysswserversetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsysswserversetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsysswserversetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsysswserversetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsysswserversetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpsyssntpsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyssntpsetup_check (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_preinsert (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_predelete (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyssntpsetup_preupdate (AC_DB_TBL_WTPSYSSNTPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyssntpsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpsyssntpsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyssntpsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyssntpsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyssntpsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicebasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_check (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_predelete (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_setdyndata (AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicebasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicebasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicebasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicebasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicechannelsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_check (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_predelete (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicechannelsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicechannelsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicechannelsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicechannelsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicechannelsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifideviceratesetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceratesetup_check (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_preinsert (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_predelete (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceratesetup_preupdate (AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceratesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceratesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceratesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceratesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceratesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicepowersetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_check (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_predelete (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicepowersetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_setdyndata (AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicepowersetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicepowersetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicepowersetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicepowersetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
 
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_check (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_predelete (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceadvancedsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceadvancedsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceadvancedsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceadvancedsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceadvancedsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifidevicewidssetup_create (VOID);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_check (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_preinsert (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_predelete (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_preupdate (AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifidevicewidssetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifidevicewidssetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifidevicewidssetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifidevicewidssetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifidevicewidssetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpwifideviceresourcesetup_create (VOID);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_check (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_preinsert (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_predelete (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_preupdate (AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRecord);
extern VOID ac_db_table_wtpwifideviceresourcesetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId);
extern UINT32    ac_db_table_wtpwifideviceresourcesetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpwifideviceresourcesetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpwifideviceresourcesetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpwifideviceresourcesetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpapbasicsetup_check (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_preinsert (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_predelete (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_preupdate (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapbasicsetup_mergekey2 (UINT8 *pucKey,UINT8* pucBssid);
extern VOID ac_db_table_wtpapbasicsetup_mergekey3 (UINT8 *pucKey,UINT32 ulWtpId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapbasicsetup_mergekey4 (UINT8 *pucKey,CHAR *pcSsid, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapbasicsetup_setdyndata (AC_DB_TBL_WTPAPBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapbasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
 
extern UINT32    ac_db_table_wtpapsecuritysetup_create (VOID);
extern UINT32    ac_db_table_wtpapsecuritysetup_check (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_preinsert (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_predelete (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapsecuritysetup_preupdate (AC_DB_TBL_WTPAPSECURITYSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey2 (UINT8 *pucKey, 
															UINT32 ulWapiSetupId, 
															UINT32 ulWtpId, 
															UINT32 ulVdevId, 
															UINT32 ulVapId);
extern VOID ac_db_table_wtpapsecuritysetup_mergekey3 (UINT8 *pucKey, 
															UINT32 ulCertFileId, 
															UINT32 ulWtpId, 
															UINT32 ulVdevId, 
															UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapsecuritysetup_trigger (UINT8 ucModType);	
extern UINT32	ac_db_table_wtpapsecuritysetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapsecuritysetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapsecuritysetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapadvancedsetup_create (VOID);
extern UINT32    ac_db_table_wtpapadvancedsetup_check (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_preinsert (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_predelete (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapadvancedsetup_preupdate (AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapadvancedsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulVapId);
extern UINT32    ac_db_table_wtpapadvancedsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapadvancedsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapadvancedsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapadvancedsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpapstat_create (VOID);
extern VOID ac_db_table_wtpapstat_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVDevId, UINT32 ulVapId);
extern VOID ac_db_table_wtpapstat_mergekey2 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32	ac_db_table_wtpapstat_delcfg(UINT32 ulWtpId);

extern UINT32		ac_db_table_wtpapwifistat_create(VOID);
extern VOID ac_db_table_wtpapwifistat_mergekey1(UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVapId);
extern UINT32	ac_db_table_wtpapwifistat_delcfg(UINT32 ulWtpId);

extern UINT32    ac_db_table_wtpadhocbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpadhocbasicsetup_check (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_preinsert (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_predelete (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocbasicsetup_preupdate (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpadhocbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulAdhocId);
extern UINT32    ac_db_table_wtpadhocbasicsetup_trigger (UINT8 ucModType);
extern UINT32    ac_db_table_wtpadhocbasicsetup_setdyndata (AC_DB_TBL_WTPADHOCBASICSETUP_T *pstRecord);
extern UINT32	ac_db_table_wtpadhocbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpadhocbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpadhocbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpadhocsecuritysetup_create (VOID);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_check (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_preinsert (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_predelete (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_preupdate (AC_DB_TBL_WTPADHOCSECURITYSETUP_T *pstRecord);
extern VOID ac_db_table_wtpadhocsecuritysetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulVdevId, UINT32 ulAdhocId);
extern UINT32    ac_db_table_wtpadhocsecuritysetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpadhocsecuritysetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpadhocsecuritysetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpadhocsecuritysetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpenetbasicsetup_create (VOID);
extern UINT32    ac_db_table_wtpenetbasicsetup_check (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_preinsert (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_predelete (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpenetbasicsetup_preupdate (AC_DB_TBL_WTPENETBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtpenetbasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulEnetPortId);
extern UINT32    ac_db_table_wtpenetbasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpenetbasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpenetbasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpenetbasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutebasicsetup_create (VOID);
extern UINT32    ac_db_table_wtproutebasicsetup_check (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_preinsert (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_predelete (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutebasicsetup_preupdate (AC_DB_TBL_WTPROUTEBASICSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutebasicsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutebasicsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutebasicsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutebasicsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutebasicsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtprouteneighborsetup_create (VOID);
extern UINT32    ac_db_table_wtprouteneighborsetup_check (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_preinsert (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_predelete (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtprouteneighborsetup_preupdate (AC_DB_TBL_WTPROUTENEIGHBORSETUP_T *pstRecord);
extern VOID ac_db_table_wtprouteneighborsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtprouteneighborsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtprouteneighborsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtprouteneighborsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtprouteneighborsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutehandoversetup_create (VOID);
extern UINT32    ac_db_table_wtproutehandoversetup_check (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_preinsert (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_predelete (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutehandoversetup_preupdate (AC_DB_TBL_WTPROUTEHANDOVERSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutehandoversetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutehandoversetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutehandoversetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutehandoversetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutehandoversetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtproutedevicemscsetup_create (VOID);
extern UINT32    ac_db_table_wtproutedevicemscsetup_check (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_preinsert (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_predelete (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtproutedevicemscsetup_preupdate (AC_DB_TBL_WTPROUTEDEVICEMSCSETUP_T *pstRecord);
extern VOID ac_db_table_wtproutedevicemscsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtproutedevicemscsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtproutedevicemscsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtproutedevicemscsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtproutedevicemscsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpcapwapsetup_create (VOID);
extern UINT32    ac_db_table_wtpcapwapsetup_check (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_preinsert (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_predelete (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpcapwapsetup_preupdate (AC_DB_TBL_WTPCAPWAPSETUP_T *pstRecord);
extern VOID ac_db_table_wtpcapwapsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpcapwapsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpcapwapsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpcapwapsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpcapwapsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpalarmfiltersetup_create (VOID);
extern UINT32    ac_db_table_wtpalarmfiltersetup_check (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_preinsert (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_predelete (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmfiltersetup_preupdate (AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstRecord);
extern VOID ac_db_table_wtpalarmfiltersetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulAlarmNo);
extern UINT32    ac_db_table_wtpalarmfiltersetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpalarmfiltersetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpalarmfiltersetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpalarmfiltersetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);


extern UINT32    ac_db_table_wtpalarmthresholdsetup_create (VOID);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_check (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_preinsert (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_predelete (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_preupdate (AC_DB_TBL_WTPALARMTHRESHOLDSETUP_T *pstRecord);
extern VOID ac_db_table_wtpalarmthresholdsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId);
extern UINT32    ac_db_table_wtpalarmthresholdsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpalarmthresholdsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpalarmthresholdsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpalarmthresholdsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_create (VOID);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_check (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_preinsert (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_predelete (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_preupdate (AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstRecord);
extern VOID ac_db_table_wtpperfcountergroupinfosetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulCounterGroupId);
extern UINT32    ac_db_table_wtpperfcountergroupinfosetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpperfcountergroupinfosetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpperfcountergroupinfosetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpperfcountergroupinfosetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);

/* add by gwx 2012-11-29 for AP/VAP������*/
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_create (VOID);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_check (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_preinsert (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_predelete (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapvapmacflowctrlsetup_preupdate (AC_DB_TBL_WTPAPVAPMACFLOWCTRLSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapvapmacflowctrlsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulWifiDeviceId, UINT32 ulVapId,UINT8* pucMac );


/* add by gwx 2013-10-11 for task1076 ��ҵ���û�������begin */
extern UINT32    ac_db_table_wtpapusergroupqossetup_create (VOID);
extern UINT32    ac_db_table_wtpapusergroupqossetup_check (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_preinsert (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_predelete (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpapusergroupqossetup_preupdate (AC_DB_TBL_WTPAPUSERGROUPQOSSETUP_T *pstRecord);
extern VOID ac_db_table_wtpapusergroupqossetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId, UINT32 ulUserGroupId);
extern UINT32    ac_db_table_wtpapusergroupqossetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpapusergroupqossetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpapusergroupqossetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpapusergroupqossetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
/* add by gwx 2013-10-11 for task1076 ��ҵ���û�������end */


/* add by gwx 2013-11-27 for task1153 begin*/
extern UINT32    ac_db_table_wtpsyslocatorsetup_create (VOID);
extern UINT32    ac_db_table_wtpsyslocatorsetup_check (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_preinsert (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_predelete (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern UINT32    ac_db_table_wtpsyslocatorsetup_preupdate (AC_DB_TBL_WTPSYSLOCATORSETUP_T *pstRecord);
extern VOID ac_db_table_wtpsyslocatorsetup_mergekey1 (UINT8 *pucKey, UINT32 ulWtpId );
extern UINT32    ac_db_table_wtpsyslocatorsetup_trigger (UINT8 ucModType);
extern UINT32	ac_db_table_wtpsyslocatorsetup_delcfg(UINT32 ulWtpId);
extern UINT32 ac_db_table_wtpsyslocatorsetup_dftblk(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId, UINT8 *pucRecord);
extern UINT32 ac_db_table_wtpsyslocatorsetup_default(UINT32 ulWtpId, UINT32 ulDeviceType, CHAR *pcDeviceId);
/* add by gwx 2013-11-27 for task1153 end*/
/* ������������*/
/******************************************************************************/
	

#endif /* _AP_DB_TABLE_H */
/******************************* ͷ�ļ����� **********************************/

