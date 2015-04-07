#ifndef KIDSD_H
#define KIDSD_H

#define AUTHOR                  "GBCOM Ltd."
#define MODULE_NAME             "kids"
#define VERSION                 "1.6"
#define DESCRIPTION             "AP Controller Embedded Intrusion Detection System module"

#define PROC_DIR_NAME		     "kids"
#define PROC_DBG_FILE_NAME		 "debug"
#define PROC_EVT_FILE_NAME		 "event"
#define PROC_CFG_FILE_NAME		 "config"

#define MAXBUFSIZE 		        2048
#define MAX_IP_PROTOCOL         136  /* refer to:  linux in.h */


/* Module definitions */

#define MAX_USER_IN_EACH_RULE   0x100
#define USER_HASH_SIZE          MAX_USER_IN_EACH_RULE

/* 首先判断是否需要进入每个规则的用户追踪状态 : 条件是满足设定的条件 */
/* 如果进入用户追踪状态， 则根据用户的统计: 是否满足条件，进行判断 */
#define RULE_STATE_IDLE       0
#define RULE_STATE_USER_TRACK 1  /* 进入用户追踪状态 */

typedef struct {
    unsigned char acUserIP[4];
    unsigned char acUserMac[6];
} AC_IDS_USER_INFO_T; 

typedef struct {
    unsigned long ulMeetNum;
    unsigned long ulLastMeetTime;
    unsigned long ulLastReportTime;
    unsigned long ulTriggeredTime;
} AC_IDS_RULE_STATE_T;


typedef struct {
    struct list_head  list;
    struct hlist_head hash[USER_HASH_SIZE];
    unsigned long ulAllocUserNum;
    /**/
    AC_IDS_RULE_STATE_T stState;
    unsigned long ulRuleState;
    unsigned long ulTrackBgnTime;
    unsigned long ulTrackEndTime;
    
    /* counter */
    unsigned long ulMatchCnt;    
    unsigned long ulTriggerCnt;
    unsigned long ulReportCnt;
    
} AC_IDS_RULE_ITEM_T;

typedef struct {
    struct list_head  list_node;
    struct hlist_node hlist_node;
    
    AC_IDS_USER_INFO_T  stUser;    
    AC_IDS_RULE_STATE_T stState;
} AC_IDS_USER_RULE_ITEM_T;


typedef struct {
    unsigned long ulNum;
    unsigned char acUserIP[4];
    unsigned char acScanResult[IDS_TYPE_MAX_NUM];
} AC_IDS_SCAN_RESULT_T;

typedef struct 
{
    EVENT_TRAP_MSG_T stEvt;
    int last_chk_time;
    struct list_head evtnode;

} omaevt_item;

/* 事件级别 */
#define EVENTLEVEL_FATAL					0		/* 致命 */
#define EVENTLEVEL_MAIN		    			1		/* 主要 */
#define EVENTLEVEL_MINOR					2		/* 次要 */
#define EVENTLEVEL_WARNING  				3		/* 警告 */

/* 事件状态 */
#define EVENTSTATUS_CLEAR   				0		/* 清除 */
#define EVENTSTATUS_RAISE					1		/* 产生 */

/* 对象类型 */
#define OBJECTTYPE_SYSTEM					0		/* 系统 */
#define OBJECTTYPE_WIFI_CARD				1		/* 无线模块 */
#define OBJECTTYPE_ENET						2		/* 以太网口 */
#define OBJECTTYPE_WIFI_DEVICE				3		/* 无线设备 */
#define OBJECTTYPE_PORT						4		/* 端口 */

#define EVENTID_IDS_EVENT                   1122

#define OMAEVT_SET_ID(f, id)    do {(f)->stEvt.ulEventId = id;} while(0);
#define OMAEVT_SET_LEVEL(f, level) do {(f)->stEvt.ulEventLevel = level;} while(0);
#define OMAEVT_SET_REASON(f, reason) do {(f)->stEvt.ulEventReasonId = reason;} while(0); 
#define OMAEVT_SET_STATUS(f, status) do {(f)->stEvt.ulEventStatus = status;} while(0);
#define OMAEVT_SET_DEVNAME(f, name) do { \
    strncpy((f)->stEvt.acObjectName, name, sizeof((f)->stEvt.acObjectName)); \
}while(0);
#define OMAEVT_SET_OBJTYPE(f, type) do {(f)->stEvt.ulObjectType = type;} while(0);
#define OMAEVT_SET_EXT1(f, value) do {(f)->stEvt.unExtInfo.ulCommonInfo = value;} while(0); 
#define OMAEVT_SET_USER(f, mac, ip) do {\
    memcpy((f)->stEvt.unExtInfo.stMacIP.acMac, mac, 6);\
    memcpy((f)->stEvt.unExtInfo.stMacIP.acIp, ip, 4);   \
    idsprintk("ids event report : MAC = %02x:%02x:%02x:%02x:%02x:%02x, ip = %02x.%02x.%02x.%02x \n", \
              mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], ip[0], ip[1], ip[2], ip[3]);} while(0); 

void omaevt_read_lock(void);
void omaevt_read_unlock(void);

omaevt_item* oma_event_fetch(void);
int oma_event_insert(omaevt_item* oma_evt);
omaevt_item* oma_event_create(void);

#endif
