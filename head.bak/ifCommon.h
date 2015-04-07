#ifndef IF_COMMON_H
#define IF_COMMON_H

#ifdef WIN32

typedef unsigned __int64 u_int64_t;
typedef unsigned int   u_int32_t ;
typedef unsigned short u_int16_t ;
typedef unsigned short u_int8_t ;

typedef short int16_t ;

#ifndef HAVE_INT8_T
typedef signed char int8_t;
#endif /* !HAVE_INT8_T */


#ifdef IFNAMSIZ
#undef IFNAMSIZ
#endif
#define IFNAMSIZ 16

#ifdef __packed
#undef __packed
#endif
#define __packed

#define SIOCDEVPRIVATE  0 //��Ҫ��һ�¶���

#define __func__ ""

typedef struct ifreq
{
    char    ifr_name[100];
    char    *ifr_data;
}ifreq;

#define ioctl(a, b, c) 0

#endif

/* ��Ԫ���� */
#define NETYPE_AP   0

/* �¼�״̬ */
#define EVENTSTATUS_CLEAR   				0		/* ��� */
#define EVENTSTATUS_RAISE					1		/* ���� */
#define EVENTSTATUS_NORMAL		     		2		/* δ֪ */

/* �������� */
#define OBJECTTYPE_SYSTEM					0		/* ϵͳ */
#define OBJECTTYPE_WIFI_CARD				1		/* ����ģ�� */
#define OBJECTTYPE_ENET						2		/* ��̫���� */
#define OBJECTTYPE_WIFI_DEVICE				3		/* �����豸 */
#define OBJECTTYPE_PORT						4		/* �˿� */

#define WIFI_MODULE0				    0
#define WIFI_MODULE1				    1
#define WIFI_MODULE2				    2
#define WIFI_MODULE3				    3


/* ����ID */
#define OBJECT_ID_INVALID					0xffffffff

#define OBJECT_ID_ADHOC0					0
#define OBJECT_ID_ADHOC1					1
#define OBJECT_ID_ADHOC2					2
#define OBJECT_ID_ADHOC3					3

#define OBJECT_ID_ENET0						4
#define OBJECT_ID_ENET1						5

#define OBJECT_ID_AP0						8
#define OBJECT_ID_AP1						9
#define OBJECT_ID_AP2						10
#define OBJECT_ID_AP3						11
#define OBJECT_ID_AP4						12
#define OBJECT_ID_AP5						13
#define OBJECT_ID_AP6						14
#define OBJECT_ID_AP7						15
#define OBJECT_ID_AP8						16
#define OBJECT_ID_AP9						17
#define OBJECT_ID_AP10						18
#define OBJECT_ID_AP11						19
#define OBJECT_ID_AP12						20
#define OBJECT_ID_AP13						21
#define OBJECT_ID_AP14						22
#define OBJECT_ID_AP15						23

#define OBJECT_ID_WIFI_MODULE0				0
#define OBJECT_ID_WIFI_MODULE1				1
#define OBJECT_ID_WIFI_MODULE2				2
#define OBJECT_ID_WIFI_MODULE3				3

#define OBJECT_ID_WIFI_DEVICE0				0
#define OBJECT_ID_WIFI_DEVICE1				1
#define OBJECT_ID_WIFI_DEVICE2				2
#define OBJECT_ID_WIFI_DEVICE3				3

/* �������� */
#define OBJECT_NAME_ADHOC0					"adhoc0"
#define OBJECT_NAME_ADHOC1					"adhoc1"
#define OBJECT_NAME_ADHOC2					"adhoc2"
#define OBJECT_NAME_ADHOC3					"adhoc3"

#define OBJECT_NAME_ENET0					"ixp0"
#define OBJECT_NAME_ENET1					"ixp1"

#define OBJECT_NAME_AP						"ap"

#define OBJECT_NAME_AP0						"ap0"
#define OBJECT_NAME_AP1						"ap1"
#define OBJECT_NAME_AP2						"ap2"
#define OBJECT_NAME_AP3						"ap3"
#define OBJECT_NAME_AP4						"ap4"
#define OBJECT_NAME_AP5						"ap5"
#define OBJECT_NAME_AP6						"ap6"
#define OBJECT_NAME_AP7						"ap7"
#define OBJECT_NAME_AP8						"ap8"
#define OBJECT_NAME_AP9						"ap9"
#define OBJECT_NAME_AP10					"ap10"
#define OBJECT_NAME_AP11					"ap11"
#define OBJECT_NAME_AP12					"ap12"
#define OBJECT_NAME_AP13					"ap13"
#define OBJECT_NAME_AP14					"ap14"
#define OBJECT_NAME_AP15					"ap15"

#define OBJECT_NAME_VLAN1		            "vlan1"
#define OBJECT_NAME_VLAN2		            "vlan2"
#define OBJECT_NAME_VLAN3		            "vlan3"
#define OBJECT_NAME_VLAN4		            "vlan4"
#define OBJECT_NAME_VLAN5		            "vlan5"
#define OBJECT_NAME_VLAN6		            "vlan6"
#define OBJECT_NAME_VLAN7		            "vlan7"
#define OBJECT_NAME_VLAN8		            "vlan8"
#define OBJECT_NAME_VLAN9		            "vlan9"
#define OBJECT_NAME_VLAN10		            "vlan10"
#define OBJECT_NAME_VLAN11		            "vlan11"
#define OBJECT_NAME_VLAN12		            "vlan12"
#define OBJECT_NAME_VLAN13		            "vlan13"
#define OBJECT_NAME_VLAN14		            "vlan14"
#define OBJECT_NAME_VLAN15		            "vlan15"
#define OBJECT_NAME_VLAN16		            "vlan16"

#define OBJECT_NAME_WIFI0					"wifi0"
#define OBJECT_NAME_WIFI1					"wifi1"
#define OBJECT_NAME_WIFI2					"wifi2"
#define OBJECT_NAME_WIFI3					"wifi3"

#define OBJECT_NAME_WIFI_DEVICE0			"wifiDevice0"
#define OBJECT_NAME_WIFI_DEVICE1			"wifiDevice1"
#define OBJECT_NAME_WIFI_DEVICE2			"wifiDevice2"
#define OBJECT_NAME_WIFI_DEVICE3			"wifiDevice3"

/* �¼����� */
#define EVENTLEVEL_FATAL					1		/* ���� */
#define EVENTLEVEL_MAIN		    			2		/* ��Ҫ */
#define EVENTLEVEL_MINOR					3		/* ��Ҫ */
#define EVENTLEVEL_WARNING  				4		/* ���� */

/* �澯�� */
#define ALARM_ID_CARD_FAULT				    1000	/* AP�����豸���� */
#define ALARM_ID_WIFI_CARD_LESS		    	1001    /* AP�����豸����λ */
/* hc modified for cmcc test 2009-9-2 */
#define ALARM_ID_AP_POWEROFF				1002    /* AP�ػ��澯 */

#define ALARM_ID_CARD_BROKEN                1005    /* ���߶˿ڹ��� */

#define ALARM_ID_CPU_OVERLOAD				2000    /* AP�豸CPU���ɹ��� */
#define ALARM_ID_MEM_OVERLOAD	        	2001    /* AP�豸�ڴ渺�ɹ��� */
#define ALARM_ID_TEMPERATURE_HIGH	    	2002    /* AP�豸�¶ȹ��߸澯 */
#define ALARM_ID_TEMPERATURE_LOW	    	2003    /* AP�豸�¶ȹ��͸澯 */
#define ALARM_ID_DISK_OVERLOAD	        	2004    /* ����ʹ���ʹ��� */

/* 2010-4-10 pyy ����*/
#define ALARM_ID_APINTERFDETECTED				2005	/* �����豸���Ÿ澯*/
#define ALARM_ID_RADIODOWN  					2006	/* ������·�жϸ澯*/
#define ALARM_ID_COVERHOLE  					2007	/* ����©���澯 */
#define ALARM_ID_DFSFREECOUNTBELOWTHRESHHD  	2008	/* �ŵ��澯 */
#define ALARM_ID_STAINTERFDETECTED				2010	/* �ն˸��Ÿ澯*/
#define ALARM_ID_APCOLDREBOOT					2011    /* ������ */
#define ALARM_ID_APWARMREBOOT					2012    /* ������ */

/* hc modified for cmcc test 2009-9-2 */
//#define ALARM_ID_RADIUS_SERVER_DISCONNECTED	     3000   /* �޷�����Radius�Ʒѷ����� */

#define EVENT_ID_WTP_REBOOT				    6000    /* AP�豸���� */
#define EVNET_ID_WTP_ROGUE_AP               6001    /* ���ֶ���AP�¼� */
#define EVENT_ID_ENET_OFFLINE				6002	/* ����������� */
#define EVENT_ID_SWUPDATE_FAIL				6010	/* �������ʧ�� */
#define EVENT_ID_TIME_SYNC_FAIL				6011	/* ʱ��ͬ��ʧ�� */
#define EVENT_ID_AP_POWEROFF				6012	/* AP�ػ��¼�*/
/* hc modified for cmcc test 2009-7-20 */
#define EVENT_ID_AP_IP_CHANGE               6013    /* AP��IP��ַ�ı�澯  */
#define EVENT_ID_AP_WRITE_FLASH_FAIL        6014    /* APдFlashʧ�ܸ澯 */

#define EVENT_ID_WTP_SWUPDATE               6016    /* AP��������ɹ� */

#define EVENT_ID_USER_ACCESS_FAILED			7000	/* �û�����ʧ�� */
#define EVENT_ID_ADHOC_ACCESS_DENY			7001	/* mesh�Ƿ����� */
#define EVENT_ID_USER_ACCESS				7002	/* �û����� */
#define EVENT_ID_USER_ACCESS_OUT            7003    /* �û�ȥ����  */

/* hc modified for telecom test 2009-7-7 */
#define EVENT_ID_WIRELESS_DOS_ATTACK		7004    /* ����DOS  �����¼� */
#define EVENT_ID_UNAUTH_SSID				7005    /* δ��ȨSSID  �¼� */
#define EVENT_ID_JAM_STA					7006    /* �����ն��¼� */
#define EVENT_ID_AP_CHANNEL_CHANGE          7007    /* Ap  �ŵ�����¼�  */
#define EVENT_ID_WEAK_IV_ATTACK             7008    /* weak iv �����¼�  */

#define EVENT_ID_FATHER_CHANGE              8000    /* AP�豸Mesh���ڵ�仯�¼� */
#define EVENT_ID_GW_CHANGE                  8001    /* AP�豸Mesh���ر仯�¼� */
#define EVENT_ID_GW_STATUS_CHANGE			8002	/* AP�豸Mesh����״̬�仯 */
/* hc modified for cmcc test 2009-7-31 */
#define EVENT_ID_INVALIDCERTINBREAKNETWORK	9000    /* �Ƿ�֤���û��������� */
#define EVENT_ID_STATIONREPITIVE_ATTACK		9001    /* �ͻ����طŹ��� */
#define EVENT_ID_TAMPER_ATTACK              9002    /* �۸Ĺ��� */
#define EVENT_ID_LOWSAFELEVEL_ATTACK        9003    /* ��ȫ�ȼ����͹��� */
#define EVENT_ID_ADDRESSREDIRECTION_ATTACK  9004    /* ��ַ�ض��򹥻� */
#define ALARM_ID_WTP_USEROVERLOAD           9005    /* AP�û������ɹ��ظ澯 */

/* 2010-4-10 pyy ����*/
#define EVENT_ID_APMTWORKMODECHG  			9006	/* AP���߼��ӹ���ģʽ����¼�*/
#define EVENT_ID_SSIDKEYCONFLICT  			9007	/* SSID��Կ��ͻ�¼�*/
#define EVENT_ID_STASSOCIATIONFAIL  		9008	/* ��վ����ʧ���¼� */
#define EVENT_ID_TLAUTHENTICATIONFAILED  	9009	/* �����ھ�AP������·ʧ���¼�*/

/* 2010/06/01 fengjing add */
#define EVNET_ID_CFGUPDATE                  9010    /* ���ø��� */
#define EVNET_ID_SWDOWNLOAD                 9011    /* ������سɹ� */
#define EVNET_ID_SWUPDATE                   9012    /* ��ʼ������� */

#define EVENT_ID_STAEXCEPTDISASSOCIATE   9020  /* �ն��쳣�Ͽ�ͨ�� *///add by zjj

#define EVENT_REASON_WTP_REBOOT_COLD        1       /* ������ */
#define EVENT_REASON_WTP_REBOOT_WARM        2       /* ������*/
#define EVENT_REASON_WTP_REBOOT_OHTER       3       /* ����ԭ��*/


#define PERFCOUNTER_FLOW        1000    /* ����ͳ�� */
#define PERFCOUNTER_VAP         2000    /* VAPͳ�� */
#define PERFCOUNTER_ADHOC       2001    /* ADHOCͳ�� */

#define PERF_COUNT	3

#define MAX_OBJECT_NAME_LEN                 31

/* ��չ��Ϣ */
typedef struct
{
	char			    acMac[6];
	char		    	acIp[4];
	/* hc modified for telecom test 2009-7-7 */
	unsigned char       aucSsid[32] ;  
}USER_MAC_IP_T;

/* hc add 2009-11-5 */
typedef enum
{
    CC_TYPE_CONFIG,
    CC_TYPE_DYNAMIC
}FREQUENCY_TYPE_U;

typedef struct
{
    unsigned long ulType ;      /*Ƶ�������ͣ�CC_TYPE_CONFIG��Ƶ�����ñ仯��CC_TYPE_DYNAMIC��Ƶ�㶯̬����*/
    unsigned long ulOld ;        /*��Ƶ�㣬0����ʾAUTO*/
    unsigned long ulNew ;      /*��Ƶ��*/
    unsigned long ulNum ;     /*Ƶ�㶯̬�������������������ñ仯����*/
}CHAN_CHANGE_T ;

typedef struct{
     unsigned char aucMac[6];  /*�û�MAC*/
     unsigned char aucRsv[2];
     unsigned long ulTime;               /*������ʱ�䣬��λ���룬��1970.1.1 00:00:00������*/
     long          lRxPower;               /*�ź�ǿ�ȣ���λ��dBm*/
     unsigned long ulChannel;         /*Ƶ�㣺1~13��149��153������*/
}USER_INFO_T;

typedef struct{
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulReason;
}FAIL_REASON_T;

/* 2010/05/29 fengjing add */
typedef struct
{
     unsigned char aucMac[6];         /* AP MAC��ַ */
     unsigned char aucRsv[2];
     unsigned long ulRebootTime;      /* AP������/������ʱ��*/
} REBOOT_INFO_T;

typedef struct
{
     unsigned char bssid[6];      /*AP MAC*/
     unsigned char bssid_pad[2];
     unsigned long channel;       /*AP �ŵ�*/
     unsigned char mac[8][8];    /*��ȫ0��ֹ*/
}STA_DISTURB_T;

typedef union
{
	unsigned long   	ulCommonInfo;           /* ����ԭ��ͨ����Ӧ��չ��ϢΪ�����������͵���� */
	USER_MAC_IP_T       stMacIP;
	char                acBssid[6];
	CHAN_CHANGE_T       stChanChange ;
	FAIL_REASON_T       stReason;
	/* 2010/05/28 fengjing add */
	USER_INFO_T         stUserInfo;
	/* 2010/05/29 fengjing add */
	REBOOT_INFO_T       stReboot;
	/* 2010-07-01 fengjing cmcc test */
	STA_DISTURB_T       stStaDisturb;	
	char                acInfo[100];
}EVENT_EXT_INFO_U;

typedef struct
{
	unsigned long	    ulEventId;						/* �¼�ID */
	unsigned long	    ulEventStatus;					/* �¼�״̬ */
	unsigned long	    ulEventReasonId;				/* �¼�ԭ��ID�� */
	unsigned long	    ulEventLevel;					/* �¼����� */
	unsigned long	    ulObjectType;		    		/* �������� */
	char			    acObjectName[MAX_OBJECT_NAME_LEN+1];    /* �������� */
	unsigned long       ulRaiseTime;					/* �¼�����ʱ��(time()�����ķ���ֵ) */
	unsigned long	    ulUptime;						/* �ϵ絽�������¼���ʱ�䣬tickֵ���� */

	EVENT_EXT_INFO_U    unExtInfo;						/* ��չ��Ϣ */
}EVENT_TRAP_MSG_T;

#define MAX_EVENTTRAPMSGLIST_NUM	    20
typedef struct
{
	unsigned long		ulValidNum;
	EVENT_TRAP_MSG_T	astEventTrapMsg[MAX_EVENTTRAPMSGLIST_NUM];
}EVENT_TRAP_MSG_LIST_T;


/*------------------------------------- mesh route path info ------------------------------------------------*/

#define ROUTE_PATH_ENTRY_MAX_NUM		    16
#define ROUTE_ROUTE_PATH_ENTRY_MAX_NUM		5

typedef struct
{
	unsigned long ulMeshRoutePathFlag;                      /* ��Ч���� */
	unsigned long ulNodeNum;                                /* ·���豸ID�б���ʵ��ʹ�õ��ĸ��� */
	unsigned char acPathEntry[ROUTE_PATH_ENTRY_MAX_NUM][6]; /* ·���ϵ��豸ID�б�*/
	unsigned long ulPathId;                                 /* ·��ID */
	unsigned long ulPathQos;                                /* ·��QOS */
	unsigned long ulPathSendSpeed;                          /* ·����������*/
	unsigned long ulPathRecvSpeed;                          /* ·����������*/
	unsigned long ulPathLiveTime;                           /* ���ʱ��*/
} MESH_ROUTE_PATH_END_INFO_T;

typedef struct
{
	unsigned long				ulValidNum;
	MESH_ROUTE_PATH_END_INFO_T	astMeshRoutePathInfo[ROUTE_PATH_ENTRY_MAX_NUM];
} MESH_ROUTE_PATH_END_INFO_ENTRY;

#endif
