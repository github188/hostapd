#ifndef OMA_ALARM_H
#define OMA_ALARM_H

/* 事件类型 */
#define EVENTTYPE_ALARM        				0		/* 告警 */
#define EVENTTYPE_EVENT  					1		/* 事件 */
#define EVENTTYPE_NULL        				0xff	/* 告警 */

/* 告警扩展信息 */
#define ALARMINFO_CARD_RESET_FAILED_NUM     "alarmResetFailedNum"   /* 卡故障:复位失败次数 */
#define ALARMINFO_CURR_USER_NUM             "currUserNum"           /* 用户数超过门限值:当前用户数 */
#define ALARMINFO_ANTENNA_ID                "antennaID"             /* 卡不接收数据:天线接口标识 */
#define ALARMINFO_FLOW_RATE                 "flowRate"              /* 无线端口流量过载:流量值（kbps） */
#define ALARMINFO_USER_MAC                  "userMAC"               /* 用户接入失败:终端MAC */
#define ALARMINFO_USER_IP                   "userIP"                /* 用户接入失败:终端IP */
#define ALARMINFO_ILLEGAL_USER_MAC          "illegalUserMAC"	    /* mesh非法接入:非法接入MAC */
#define ALARMINFO_ILLEGAL_USER_IP           "illegalUserIP"	        /* mesh非法接入:非法接入MAC */
#define ALARMINFO_IS_GATEWAY	            "isGateway"             /* 网关状态变化:是否为网关,0:不是 1:是 */
#define ALARMINFO_AP_MODE_HANDOVER          "handoverState"         /* AP模式切换:1为FAT_TO_FIT_AP，2为FIT_TO_FAT_AP */
#define ALARMINFO_WIFI_MODULE_ID            "wifiModuleId"          /* 缺少无线网卡： WiFi 模块号 */
#define ALARMINFO_END_USER_MAC				"endUserMAC"			/* 最终用户MAC */
#define ALARMINFO_END_USER_IP				"endUserIP"				/* 最终用户IP */
/* 2010/05/28 fengjing add */
#define ALARMINFO_END_USER_TIME             "endUserTime"           /*上下线时间，单位：秒，自1970.1.1 00:00:00的秒数*/
#define ALARMINFO_END_USER_POWER            "endUserRxPower"        /*信号强度，单位：dBm*/
#define ALARmINFO_END_USER_CHANNEL          "endUserChannel"        /*频点：1~13，149，153，……*/
#define ALARMINFO_BSSID                     "bssid"                 /* BSSID */
#define ALARMINFO_CURRVER                   "currVer"               /* 当前版本 */
#define ALARMINFO_UPDATEVER                 "updateVer"             /* 升级后版本 */
/* hc add for wireless dos attack 2009-6-30 */
#define ALARMINFO_ATTACK_USER_MAC			"attackUserMAC"			/* 无线dos 攻击用户MAC */
#define ALARMINFO_WEAK_IV_MAC				"weakIvMAC"			    /* weak iv 攻击用户MAC */
#define ALARMINFO_JAM_STA_MAC				"jamStaMAc"			    /* 干扰终端MAC地址 */
#define ALARMINFO_UNAUTH_SSID				"unAuthSsid"			/* 未授权SSID */
/* hc modified for cmcc test 2009-7-20 */
#define ALARMINFO_AP_CHANNEL_CHANGE			"apChannelChange"		/* 未授权SSID */

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

/* 告警扩展信息最大字符数 */
#define MAX_ALARMEXTINFO_LEN    200
#define MAX_EVENTEXTINFO_LEN    200

#ifndef MAX_OID_LEN
#define MAX_OID_LEN     128
#endif

/* 告警主键 */
typedef struct
{
	unsigned long	    ulAlarmCode;				    /* 告警编号 */
    char                acAlarmObjectID[MAX_OID_LEN];   /* 告警对象OID */
    unsigned long	    ulAlarmStatus;					/* 告警状态 */
    unsigned long	    ulAlarmChangeTime;				/* 告警产生/清除最后发生时间（合并后时间），单位：秒 */
    unsigned long       ulAlarmSn;                      /* 告警流水号 */
} T_alarmKey;

/* alarm trap msg */
typedef struct
{
    T_alarmKey          stAlarmKey;

    unsigned long	    ulAlarmReasonID;				/* 告警原因编号 */
    unsigned long	    ulAlarmLevel;					/* 告警级别 */

    unsigned long       ulAlarmRaiseTime;				/* 告警产生/清除绝对时间(time()函数的返回值)，单位：秒 */
    unsigned long	    ulAlarmUptime;					/* 告警产生/清除相对（上电）时间，tick值，单位：秒 */

    char                acAlarmExtInfo[MAX_ALARMEXTINFO_LEN+1];
} T_alarmTrapMsg;

/* 事件主键 */
typedef struct
{
	unsigned long	    ulEventCode;				    /* 事件编号 */
    char                acEventObjectID[MAX_OID_LEN];   /* 事件对象OID */
    unsigned long       ulEventRaiseTime;				/* 事件产生绝对时间(time()函数的返回值)，单位：秒 */
    unsigned long       ulEventSn;                      /* 事件流水号 */
} T_eventKey;

typedef struct
{
    T_eventKey          stEventKey;

    unsigned long	    ulEventReasonID;				/* 事件原因编号 */
    unsigned long	    ulEventUptime;					/* 事件产生相对（上电）时间，tick值，单位：秒 */

    char                acEventExtInfo[MAX_EVENTEXTINFO_LEN+1];
} T_eventTrapMsg;

/* OMC的告警上报应答消息 */
typedef T_alarmKey  T_alarmAckMsg;

/* OMC的事件上报应答消息 */
typedef T_eventKey  T_eventAckMsg;

/* AP OAM告警 */
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
	UINT32	ulCpuHighNum;	/* 持续超过CPU告警门限的次数*/
    	UINT32 	ulCpuIndex;
	UINT32	aulCpu[OMA_MAX_CPU_COUNT];              /* 单位% */

	UINT32	ulMemHighNum;	/* 持续超过内存告警门限的次数*/
    	UINT32	ulMemIndex;
    	UINT32	aulFreeMemSize[OMA_MAX_MEM_COUNT];      /* 单位M */
    	UINT32   aulMemUsage[OMA_MAX_MEM_COUNT];         /* 内存使用率，单位% */

	UINT32	ulDiskHighNum;	/* 持续超过磁盘告警门限的次数*/
    	UINT32	ulDiskIndex;
    	UINT32	aulFreeDiskSize[OMA_MAX_DISK_COUNT];    /* 单位M */
    	UINT32	aulDiskUsage[OMA_MAX_DISK_COUNT];       /* 内存使用率，单位% */

	UINT32	ulTempHighNum;	/* 持续超过高温告警门限的次数*/
	UINT32	ulTempLowNum;	/* 持续低于低温告警门限的次数*/
    	UINT32   ulTempIndex;
    	INT32     aiTemp[OMA_MAX_TEMP_COUNT];             /* 单位:度 */
}OMA_ALARM_INFO_T;

#if 0 //待实现，需要修改模型
typedef OMA_ALARM_THRESHOLD_CFG_T OMA_ALARM_THRESHOLD_T;
#else
typedef struct
{
    unsigned long   ulCpuLoadPeriod	;	/* CPU负荷采样周期	    5       */
    unsigned long   ulCpuLoadCount	;	/* CPU负荷持续次数	    6       */
    unsigned long   ulCpuLoadHigh	;	/* CPU负荷告警产生门限	90      */
    unsigned long   ulCpuLoadLow	;	/* CPU负荷告警消除门限	80      */

    unsigned long   ulMemLoadPeriod	;	/* 内存利用率采样周期	    5   */
    unsigned long   ulMemLoadCount	;	/* 内存利用率持续次数		6   */
    unsigned long   ulMemLoadHigh	;	/* 内存利用率告警产生门限	95  */
    unsigned long   ulMemLoadLow	;	/* 内存利用率告警消除门限	90  */

    unsigned long   ulTempPeriod	;	/* 设备温度采样周期	    5       */
    unsigned long   ulTempCount	    ;	/* 设备温度持续次数	    6       */
    unsigned long   ulTempHigh	    ;	/* 设备高温告警产生门限	55      */
    unsigned long   ulTempLow	    ;	/* 设备高温告警消除门限	50      */
    int             iTempHigh	    ;	/* 设备低温告警产生门限	-30     */
    int             iTempLow	    ;	/* 设备低温告警消除门限	-20     */

    unsigned long   ulDiskLoadPeriod;	/* 磁盘利用率采样周期	    5   */
    unsigned long   ulDiskLoadCount	;	/* 磁盘利用率持续次数		6   */
    unsigned long   ulDiskLoadHigh	;	/* 磁盘利用率告警产生门限	90  */
    unsigned long   ulDiskLoadLow	;	/* 磁盘利用率告警消除门限	80  */

}OMA_ALARM_THRESHOLD_T;

#endif

/* 函数声明 */
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



