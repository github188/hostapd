
#ifndef __KIDS_CONFIG_H__
#define __KIDS_CONFIG_H__

#define IDS_TYPE_ID_START 0
/* IDS TYPE ID */
//#define IDS_TYPE_OPTIONS_MANAGE_OPTION_LIST         (IDS_TYPE_ID_START)             // 0
//#define IDS_TYPE_OPTIONS_RECORD_PACKET_ROUTE        (IDS_TYPE_OPTIONS_MANAGE_OPTION_LIST + 1)   // 1
//#define IDS_TYPE_OPTIONS_TIMESTAMP                  (IDS_TYPE_OPTIONS_RECORD_PACKET_ROUTE + 1)  // 2
//#define IDS_TYPE_OPTIONS_SECURITY                   (IDS_TYPE_OPTIONS_TIMESTAMP + 1)  // 3 
//#define IDS_TYPE_OPTIONS_LOOSE_SOURCE_ROUTE         (IDS_TYPE_OPTIONS_SECURITY + 1)     // 4
//#define IDS_TYPE_OPTIONS_SATNET_ID                  (IDS_TYPE_OPTIONS_LOOSE_SOURCE_ROUTE + 1)  // 5
//#define IDS_TYPE_OPTIONS_STRICT_SOURCE_ROUTE        (IDS_TYPE_OPTIONS_SATNET_ID + 1)    // 6
//#define IDS_TYPE_IP_FRAGMENT_ATTACK                 (IDS_TYPE_OPTIONS_STRICT_SOURCE_ROUTE + 1)  //7
//#define IDS_TYPE_IMPOSSIBLE_IP_HEADER               (IDS_TYPE_UNKNOWN_IP_PROTOCOL + 1)  // 9
//#define IDS_TYPE_ICMP_ECHO_REPLY                    (IDS_TYPE_IMPOSSIBLE_MAC_HEADER + 1)    // 11
//#define IDS_TYPE_ICMP_HOST_UNREACHABLE              (IDS_TYPE_ICMP_ECHO_REPLY + 1)  // 12
//#define IDS_TYPE_ICMP_SOURCE_QUENCH                 (IDS_TYPE_ICMP_HOST_UNREACHABLE + 1)    // 13
//#define IDS_TYPE_ICMP_REDIRECT                      (IDS_TYPE_ICMP_SOURCE_QUENCH + 1)   // 14
//#define IDS_TYPE_ICMP_ECHO_REQUEST                  (IDS_TYPE_ICMP_REDIRECT + 1)    // 15
//#define IDS_TYPE_ICMP_TIME_EXCEED_DATAGRAM          (IDS_TYPE_ICMP_ECHO_REQUEST + 1)    // 16
//#define IDS_TYPE_ICMP_ICMP_PARAMETER_ERR_DATAGRAM   (IDS_TYPE_ICMP_TIME_EXCEED_DATAGRAM + 1)    //17
//#define IDS_TYPE_ICMP_TIMESTAMP_REQUEST             (IDS_TYPE_ICMP_ICMP_PARAMETER_ERR_DATAGRAM + 1) // 18
//#define IDS_TYPE_ICMP_TIMESTAMP_REPLY               (IDS_TYPE_ICMP_TIMESTAMP_REQUEST + 1)   // 19
//#define IDS_TYPE_ICMP_INFORMAITON_REQUEST           (IDS_TYPE_ICMP_TIMESTAMP_REPLY + 1) // 20
//#define IDS_TYPE_ICMP_INFORMAITON_REPLY             (IDS_TYPE_ICMP_INFORMAITON_REQUEST + 1) // 21
//#define IDS_TYPE_ICMP_ADDRESS_MASK_REQUEST          (IDS_TYPE_ICMP_INFORMAITON_REPLY + 1)   // 22
//#define IDS_TYPE_ICMP_ADDRESS_MASK_REPLY            (IDS_TYPE_ICMP_ADDRESS_MASK_REQUEST + 1)    // 23
//#define IDS_TYPE_LARGE_ICMP_TRAFFIC                 (IDS_TYPE_FRAGMENTED_ICMP_TRAFFIC + 1)  // 25

#define IDS_TYPE_UNKNOWN_IP_PROTOCOL                0//(IDS_TYPE_IP_FRAGMENT_ATTACK + 1)   // 8
#define IDS_TYPE_IMPOSSIBLE_MAC_HEADER              1 // 10
#define IDS_TYPE_FRAGMENTED_ICMP_TRAFFIC            2  // 24
#define IDS_TYPE_PING_OF_DEATH_ATTACK               3   // 26
#define IDS_TYPE_UDP_BOMB                           4 // 27
#define IDS_TYPE_TCP_SYN_FIN                        5 // 28
#define IDS_TYPE_TCP_XMAS                           6  // 29
#define IDS_TYPE_TCP_XMAS_1                         7 // 30
#define IDS_TYPE_TCP_XMAS_2                         8  // 31
#define IDS_TYPE_TCP_SYN_RST                        9  // 32
#define IDS_TYPE_TCP_FIN                            10  // 33
#define IDS_TYPE_TCP_NULL                           11  // 34
#define IDS_TYPE_TCP_HALF_SYN                       12 // 35
#define IDS_TYPE_ICMP_FLOODING                      13 // 36
#define IDS_TYPE_ARP_FLOODING                       14    // 37
#define IDS_TYPE_UDP_FLOODING                       15     // 38
#define IDS_TYPE_MAX_NUM                            16     // 39


typedef struct {
    unsigned long ulMeetPeriod;   //in seconds
    unsigned long ulMeetNum;
    unsigned long ulReportPeriod;
    unsigned long ulAction; 
} AC_IDS_RULE_CFG_T;

typedef struct {
    unsigned long ulRuleId;
    unsigned long ulRuleEnable;
    AC_IDS_RULE_CFG_T stConfig;
} AC_IDS_RULE_DESC_T;

typedef struct  {
    unsigned long ulKidsEnable;
} AC_IDS_GLOBAL_CONFIG_T;;

#define AC_IDS_CTL_RULE_CFG      1
#define AC_IDS_CTL_GLOBAL_CFG    2
#define AC_IDS_CTL_DEBUG_CFG     3
#define AC_IDS_CTL_DEBUG_CLOSE   4
typedef struct {
    unsigned long ulCtlCmd;
    union {
        AC_IDS_RULE_DESC_T stRule;
        AC_IDS_GLOBAL_CONFIG_T stGlobal;
    } u;
} AC_IDS_CONFIG_T;

/* ====================================================== */
/* Event Define */
#define MAX_OBJECT_NAME_LEN                 31

/* 扩展信息 */
typedef struct 
{
	char			    acMac[6];
	char		    	acIp[4];
}USER_MAC_IP_T;

typedef union
{
	unsigned long   	ulCommonInfo;           /* 公共原因，通常对应扩展信息为单个整数类型的情况 */
	USER_MAC_IP_T       stMacIP;
}EVENT_EXT_INFO_U;

typedef struct
{
	unsigned long	    ulEventId;						/* 事件ID */
	unsigned long	    ulEventStatus;					/* 事件状态 */	
	unsigned long	    ulEventReasonId;				/* 事件原因ID号 */
	unsigned long	    ulEventLevel;					/* 事件级别 */
	unsigned long	    ulObjectType;		    		/* 对象类型 */
	char			    acObjectName[MAX_OBJECT_NAME_LEN+1];    /* 对象名称 */
	unsigned long       ulRaiseTime;					/* 事件产生时间(time()函数的返回值) */
	unsigned long	    ulUptime;						/* 上电到发生该事件的时间，tick值，毫秒 */

	EVENT_EXT_INFO_U    unExtInfo;						/* 扩展信息 */
}EVENT_TRAP_MSG_T;

#endif

