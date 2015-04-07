#ifndef OMA_ALARM_H
#define OMA_ALARM_H

/* �¼����� */
#define EVENTTYPE_ALARM        				0		/* �澯 */
#define EVENTTYPE_EVENT  					1		/* �¼� */
#define EVENTTYPE_NULL        				0xff	/* �澯 */

/* �澯��չ��Ϣ */
#define ALARMINFO_CARD_RESET_FAILED_NUM     "alarmResetFailedNum"   /* ������:��λʧ�ܴ��� */
#define ALARMINFO_CURR_USER_NUM             "currUserNum"           /* �û�����������ֵ:��ǰ�û��� */
#define ALARMINFO_ANTENNA_ID                "antennaID"             /* ������������:���߽ӿڱ�ʶ */
#define ALARMINFO_FLOW_RATE                 "flowRate"              /* ���߶˿���������:����ֵ��kbps�� */
#define ALARMINFO_USER_MAC                  "userMAC"               /* �û�����ʧ��:�ն�MAC */
#define ALARMINFO_USER_IP                   "userIP"                /* �û�����ʧ��:�ն�IP */
#define ALARMINFO_ILLEGAL_USER_MAC          "illegalUserMAC"	    /* mesh�Ƿ�����:�Ƿ�����MAC */
#define ALARMINFO_ILLEGAL_USER_IP           "illegalUserIP"	        /* mesh�Ƿ�����:�Ƿ�����MAC */
#define ALARMINFO_IS_GATEWAY	            "isGateway"             /* ����״̬�仯:�Ƿ�Ϊ����,0:���� 1:�� */
#define ALARMINFO_AP_MODE_HANDOVER          "handoverState"         /* APģʽ�л�:1ΪFAT_TO_FIT_AP��2ΪFIT_TO_FAT_AP */
#define ALARMINFO_WIFI_MODULE_ID            "wifiModuleId"          /* ȱ������������ WiFi ģ��� */
#define ALARMINFO_END_USER_MAC				"endUserMAC"			/* �����û�MAC */
#define ALARMINFO_END_USER_IP				"endUserIP"				/* �����û�IP */
/* 2010/05/28 fengjing add */
#define ALARMINFO_END_USER_TIME             "endUserTime"           /*������ʱ�䣬��λ���룬��1970.1.1 00:00:00������*/
#define ALARMINFO_END_USER_POWER            "endUserRxPower"        /*�ź�ǿ�ȣ���λ��dBm*/
#define ALARmINFO_END_USER_CHANNEL          "endUserChannel"        /*Ƶ�㣺1~13��149��153������*/
#define ALARMINFO_BSSID                     "bssid"                 /* BSSID */
#define ALARMINFO_CURRVER                   "currVer"               /* ��ǰ�汾 */
#define ALARMINFO_UPDATEVER                 "updateVer"             /* ������汾 */
/* hc add for wireless dos attack 2009-6-30 */
#define ALARMINFO_ATTACK_USER_MAC			"attackUserMAC"			/* ����dos �����û�MAC */
#define ALARMINFO_WEAK_IV_MAC				"weakIvMAC"			    /* weak iv �����û�MAC */
#define ALARMINFO_JAM_STA_MAC				"jamStaMAc"			    /* �����ն�MAC��ַ */
#define ALARMINFO_UNAUTH_SSID				"unAuthSsid"			/* δ��ȨSSID */
/* hc modified for cmcc test 2009-7-20 */
#define ALARMINFO_AP_CHANNEL_CHANGE			"apChannelChange"		/* δ��ȨSSID */

#define ALARMINFO_CPU				        "cpu"
#define ALARMINFO_MEM				        "mem"
#define ALARMINFO_TEMP				        "temperature"
#define ALARMINFO_DISK				        "disk"

typedef struct
{
    unsigned long       alarmCode;
    unsigned long       alarmType;
}T_alarmTypeInfo;

#define MIN_ALARMTRAPMSG_NUM    32
#define MIN_EVENTTRAPMSG_NUM    64

/* �澯��չ��Ϣ����ַ��� */
#define MAX_ALARMEXTINFO_LEN    200
#define MAX_EVENTEXTINFO_LEN    200

#ifndef MAX_OID_LEN
#define MAX_OID_LEN     128
#endif

/* �澯���� */
typedef struct
{
	unsigned long	    ulAlarmCode;				    /* �澯��� */
    char                acAlarmObjectID[MAX_OID_LEN];   /* �澯����OID */
    unsigned long	    ulAlarmStatus;					/* �澯״̬ */
    unsigned long	    ulAlarmChangeTime;				/* �澯����/��������ʱ�䣨�ϲ���ʱ�䣩����λ���� */
    unsigned long       ulAlarmSn;                      /* �澯��ˮ�� */
} T_alarmKey;

/* alarm trap msg */
typedef struct
{
    T_alarmKey          stAlarmKey;

    unsigned long	    ulAlarmReasonID;				/* �澯ԭ���� */
    unsigned long	    ulAlarmLevel;					/* �澯���� */

    unsigned long       ulAlarmRaiseTime;				/* �澯����/�������ʱ��(time()�����ķ���ֵ)����λ���� */
    unsigned long	    ulAlarmUptime;					/* �澯����/�����ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */

    char                acAlarmExtInfo[MAX_ALARMEXTINFO_LEN+1];
} T_alarmTrapMsg;

/* �¼����� */
typedef struct
{
	unsigned long	    ulEventCode;				    /* �¼���� */
    char                acEventObjectID[MAX_OID_LEN];   /* �¼�����OID */
    unsigned long       ulEventRaiseTime;				/* �¼���������ʱ��(time()�����ķ���ֵ)����λ���� */
    unsigned long       ulEventSn;                      /* �¼���ˮ�� */
} T_eventKey;

typedef struct
{
    T_eventKey          stEventKey;

    unsigned long	    ulEventReasonID;				/* �¼�ԭ���� */
    unsigned long	    ulEventUptime;					/* �¼�������ԣ��ϵ磩ʱ�䣬tickֵ����λ���� */

    char                acEventExtInfo[MAX_EVENTEXTINFO_LEN+1];
} T_eventTrapMsg;

/* OMC�ĸ澯�ϱ�Ӧ����Ϣ */
typedef T_alarmKey  T_alarmAckMsg;

/* OMC���¼��ϱ�Ӧ����Ϣ */
typedef T_eventKey  T_eventAckMsg;

/* AP OAM�澯 */
#define OMA_MAX_CPU_COUNT       600
#define OMA_MAX_MEM_COUNT       600
#define OMA_MAX_DISK_COUNT      600
#define OMA_MAX_TEMP_COUNT      600

#define HIGH_TEMP_ALARM         	1
#define LOW_TEMP_ALARM          	(-1)
#define TEMP_ALARM_CLEAR        	0
#define TEMP_ALARM_NORMAL		0xFF

typedef struct
{
	UINT32	ulCpuHighNum;	/* ��������CPU�澯���޵Ĵ���*/
    	UINT32 	ulCpuIndex;
	UINT32	aulCpu[OMA_MAX_CPU_COUNT];              /* ��λ% */

	UINT32	ulMemHighNum;	/* ���������ڴ�澯���޵Ĵ���*/
    	UINT32	ulMemIndex;
    	UINT32	aulFreeMemSize[OMA_MAX_MEM_COUNT];      /* ��λM */
    	UINT32   aulMemUsage[OMA_MAX_MEM_COUNT];         /* �ڴ�ʹ���ʣ���λ% */

	UINT32	ulDiskHighNum;	/* �����������̸澯���޵Ĵ���*/
    	UINT32	ulDiskIndex;
    	UINT32	aulFreeDiskSize[OMA_MAX_DISK_COUNT];    /* ��λM */
    	UINT32	aulDiskUsage[OMA_MAX_DISK_COUNT];       /* �ڴ�ʹ���ʣ���λ% */

	UINT32	ulTempHighNum;	/* �����������¸澯���޵Ĵ���*/
	UINT32	ulTempLowNum;	/* �������ڵ��¸澯���޵Ĵ���*/
    	UINT32   ulTempIndex;
    	INT32     aiTemp[OMA_MAX_TEMP_COUNT];             /* ��λ:�� */
}OMA_ALARM_INFO_T;

#if 0 //��ʵ�֣���Ҫ�޸�ģ��
typedef OMA_ALARM_THRESHOLD_CFG_T OMA_ALARM_THRESHOLD_T;
#else
typedef struct
{
    unsigned long   ulCpuLoadPeriod	;	/* CPU���ɲ�������	    5       */
    unsigned long   ulCpuLoadCount	;	/* CPU���ɳ�������	    6       */
    unsigned long   ulCpuLoadHigh	;	/* CPU���ɸ澯��������	90      */
    unsigned long   ulCpuLoadLow	;	/* CPU���ɸ澯��������	80      */

    unsigned long   ulMemLoadPeriod	;	/* �ڴ������ʲ�������	    5   */
    unsigned long   ulMemLoadCount	;	/* �ڴ������ʳ�������		6   */
    unsigned long   ulMemLoadHigh	;	/* �ڴ������ʸ澯��������	95  */
    unsigned long   ulMemLoadLow	;	/* �ڴ������ʸ澯��������	90  */

    unsigned long   ulTempPeriod	;	/* �豸�¶Ȳ�������	    5       */
    unsigned long   ulTempCount	    ;	/* �豸�¶ȳ�������	    6       */
    unsigned long   ulTempHigh	    ;	/* �豸���¸澯��������	55      */
    unsigned long   ulTempLow	    ;	/* �豸���¸澯��������	50      */
    int             iTempHigh	    ;	/* �豸���¸澯��������	-30     */
    int             iTempLow	    ;	/* �豸���¸澯��������	-20     */

    unsigned long   ulDiskLoadPeriod;	/* ���������ʲ�������	    5   */
    unsigned long   ulDiskLoadCount	;	/* ���������ʳ�������		6   */
    unsigned long   ulDiskLoadHigh	;	/* ���������ʸ澯��������	90  */
    unsigned long   ulDiskLoadLow	;	/* ���������ʸ澯��������	80  */

}OMA_ALARM_THRESHOLD_T;

#endif

/* �������� */
int initAlarmReportQueue(unsigned long nodeNum);
int initEventReportQueue(unsigned long nodeNum);

int compareAlarm(void *source, void *dest);
int compareEvent(void *source, void *dest);

int addAlarmTrapMsgToQueue(T_alarmTrapMsg *msg);
void* locateAlarmTrap(T_alarmTrapMsg *msg);
int addEventTrapMsgToQueue(T_eventTrapMsg *msg);

int removeAlarmTrapMsgFromQueue(T_alarmKey *msg);
int removeEventTrapMsgFromQueue(T_eventKey *msg);

int resendAlarmQueueMsg(void);
int resendEventQueueMsg(void);

int omaSendAlarmTrapMsg(char* msg);
int omaSendEventTrapMsg(char* trapMsg);

void setAlarmExtInfo(EVENT_TRAP_MSG_T *alarmMsg, char *alarmExtInfo);
unsigned long getAlarmType(unsigned long alarmCode);

int getAlarmTrap(EVENT_TRAP_MSG_T *alarmMsg, T_alarmTrapMsg *alarmTrapMsg);
int getEventTrap(EVENT_TRAP_MSG_T *eventMsg, T_eventTrapMsg *eventTrapMsg);

unsigned long getNewAlarmSn(void);
int getAlarmObjectID(char* alarmObjectName, char* szOid);

int isAlarmFiltered(UINT32 ulEventId);
void omaGetDiskInfo(UINT32 *pulTotalDisk, UINT32 *pulFreeDisk);

#endif /* OMA_ALARM_H */



