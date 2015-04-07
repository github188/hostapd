/*
 * =====================================================================================
 *       Filename:  ac_firewall.h
 *       Description:  
 *
 *       Version:  1.0
 *       Created:  2009.03.04
 *       Revision: v0.1
 *       Compiler: gcc
 *       Company: gbcom 
 *
 * =====================================================================================
 */

#ifndef _AC_FIREWALL_H
#define _AC_FIREWALL_H

#define PORTAL
/* use daemon mode */
#define DAEMON
//#define MSG_SIM
//#define CLEAR_RULE

//typedef unsigned char u8;
//#define MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
//#define MAC_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3], ((u8*)(x))[4], ((u8*)(x))[5]
//#define IP_FMT	"%u.%u.%u.%u"
//#define IP_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3]

#define INVALID_VALUE   0xFFFFFFFF

#define NAT_FITLAN   0

#define M_MSG_FW_UPDATE         AC_DEVM_FWGLOBAL_UPDATE_IND_MSG 
#define M_MSG_RULE_ADD          AC_DEVM_FWRULE_ADD_IND_MSG
#define M_MSG_RULE_DEL          AC_DEVM_FWRULE_DEL_IND_MSG
#define M_MSG_RULE_UPDATE       AC_DEVM_FWRULE_UPDATE_IND_MSG
#define M_MSG_NAT_GLOBAL        AC_DEVM_NATGLOBAL_UPDATE_IND_MSG
#define M_MSG_NAT_ADD           AC_DEVM_NAT_ADD_IND_MSG
#define M_MSG_NAT_DEL           AC_DEVM_NAT_DEL_IND_MSG
#define M_MSG_NAT_UPDATE        AC_DEVM_NAT_UPDATE_IND_MSG
#define M_MSG_IDSRULE_UPDATE    AC_DEVM_IDSRULE_UPDATE_IND_MSG
#define M_MSG_IDSSTRY_UPDATE    AC_DEVM_IDSSTRY_UPDATE_IND_MSG

#define M_MSG_WHITELIST_ADD     AC_DEVM_WHITELIST_ADD_IND_MSG
#define M_MSG_WHITELIST_DEL     AC_DEVM_WHITELIST_DEL_IND_MSG
#define M_MSG_WHITELIST_UPDATE  AC_DEVM_WHITELIST_UPDATE_IND_MSG
/* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
#define M_MSG_WHITEURL_ADD		AC_DEVM_WHITEURL_ADD_IND_MSG
#define M_MSG_WHITEURL_DEL		AC_DEVM_WHITEURL_DEL_IND_MSG
#define M_MSG_WHITEURL_UPDATE	AC_DEVM_WHITEURL_UPDATE_IND_MSG
/* END:   Added by wns, 2012/11/16   PN:TASK#225 */
#define M_MSG_PORTAL_UPDATE     AC_DEVM_PORTAL_UPDATE_IND_MSG
#define M_MSG_PORTAL_GLOBAL_FREEAUTH AC_DEVM_FREEGLOBAL_UPDATE_IND_MSG
#define M_MSG_DISAUTH_USER_ADD  AC_DEVM_FREEADDR_ADD_IND_MSG
#define M_MSG_DISAUTH_USER_DEL  AC_DEVM_FREEADDR_DEL_IND_MSG
#define M_MSG_DISAUTH_USER_UPDATE  AC_DEVM_FREEADDR_UPDATE_IND_MSG
#define M_MSG_DISAUTH_MAC_USER_ADD  AC_DEVM_FREEMAC_ADD_IND_MSG
#define M_MSG_DISAUTH_MAC_USER_DEL  AC_DEVM_FREEMAC_DEL_IND_MSG
#define M_MSG_DISAUTH_MAC_USER_UPDATE  AC_DEVM_FREEMAC_UPDATE_IND_MSG

#ifdef MSG_SIM
#define AC_DEVM_ACL_STS_RSP_MSG     0
#define AC_DEVM_ACL_STS_REQ_MSG     1
#else
#define AC_DEVM_ACL_STS_RSP_MSG     EV_AC_OMA_GET_AC_ACLSTAT_RSP_MSG
#define AC_DEVM_ACL_STS_REQ_MSG     EV_AC_OMA_GET_AC_ACLSTAT_REQ_MSG
#endif

/* globale firewall config */
#define IS_FW_ON        g_stFwConfig.ulFireWallOn

/*-----------------------------------------------------------------------------
 *  only for ac_firewall.c
 *-----------------------------------------------------------------------------*/
typedef AC_DEVM_FWGLOBAL_CONFIG_T FW_CONFIG_T;

/* rule for ip match */
struct FW_IP_T
{
    unsigned char aucIp[16];            /* ip source */
    unsigned char aucMask[16];          /* ip mask */
    unsigned int ulIpMatchType;         /* 0:exclude Ip/mask  1: include Ip/mask */
};

/* rule for port match */
#define M_PORT_NUM_MAX          8
struct FW_PORT_T
{
    UINT32  ulPortMatchPolicy;      /* port match policy 0: dont 1:positive 2:oppositive
*/
    unsigned int ulBeginPort;       /* service begin port */
    unsigned int ulEndPort;         /* service end port */
    char acIptPort[24];             /* port for iptables */
};

/* match for p2p control , Layer 7 */
#define M_L7_NUM_MAX        32
#define M_L7_PROTO_NAME_MAX 8*32 
struct FW_L7_T
{
    unsigned int ulL7Enable;                /* L7 Config type 0:off 1:on */ 
    unsigned int ulProtoNum;                /* number of protocol L7 matched{1-29}, --l7proto x for iptables */
    unsigned int aulProtoId[M_L7_NUM_MAX];  /* protocol of L7 matched {1-29} */
    char acProtocol[M_L7_PROTO_NAME_MAX];
    unsigned int ulTimeMatch;               /* L7 match depends on time 0:off 1:on, -m time for iptables */
    char acTimeStart[8];          /* Time start  {00:00 - 23:59}, --timestart x for iptables */
    char acTimeStop[8];           /* Time end  {00:00 - 23:59}, -- timestop x for iptables */
    unsigned int  ulDaysMatch;              /* L7 days match on/off */
    char aucWeekDays[32];          /* L7 match depends on days; 0:dont use this word, --day x for iptables */
                                            /* bit0 - bit7 stand for Mon. Tue. Wed. Thu. Fri. Sat. Sun.*/
};


extern unsigned char g_aucLogLevel[8][8];
struct FW_LOG_T
{
    unsigned int ulLogLevel;        /* log level set */
    unsigned int ulPrefixOn;        /* open prefix */
    unsigned char aucPrefix[32];    /* prefix of log record */ 
    unsigned int  ulLogTcpSeq;      /* record sequence of tcp */
    unsigned int  ulLogTcpOption;   /* record unchanged tcp option of tcp header */
    unsigned int  ulLogIpOption;    /* record unchaged ip option of IP header */
};
extern struct FW_LOG_T g_stLog ;
extern CHAR g_acLogCmd[64] ;

/* rule's actione, -j for iptables */
#define     M_ACTION_DROP       0
#define     M_ACTION_ACCEPT     1
#define     M_ACTION_MARK       2
#define     M_ACTION_LOG        3   /* 用于内部实现LOG功能 */
#define     M_ACTION_CONTINUE   4   /* 用于内部实现规则停止/启用功能 */
struct FW_ACTION_T
{
    unsigned int ulRuleAction;          /* range 0-7 : 0-DROP; 1-ACCEPT; 2-CONTINUE; 3-REJECT; 4-LOG; 5-MARK; 6-TOS; 7-CHAIN'S ID*/
    struct FW_LOG_T stFwLog;            /* enable if ulRuleAction == 4 */
    unsigned int ulTargetValue;         /* ulRuleAction == {3,5,6} use this value to change packet  */
                                        /* value range {0x10,0x08,0x04,0x02,0x00} enable if ulRuleAction = 6 */
                                        /* value range 1-6 if ulRuleAction = 5 */
};

struct FW_BR_T {
    unsigned int ulMatchEnable;     /* match enable 0: match  1: dont match*/
    unsigned int ulBrId;            /* bridge index use for fwctl, different with devm */
    char         acBrName[32];      /* bridge name　*/
};

/* rule's content , use these values build a iptales rule */
#define M_RULE_COMMENT_MAX            32   /* rule's comment max buffer */
struct FW_RULE_T
{
    unsigned int    ulWorking;      /* rule is working */
    unsigned int    ulRuleId;       /* global Rule Index */
    unsigned int    ulChildRuleId;  /* child rule id , use it inserting rule */
    unsigned int    ulRuleOn;        /* rule work confige 0:off 1:on */  
    char            acComment[M_RULE_COMMENT_MAX]; /* rule's commnet */

    struct FW_IP_T  stSrcIp;            /* rule's Source IP, -s for iptables  */
    struct FW_IP_T  stDestIp;           /* rule's Destination IP, -d for iptables */

    unsigned int    ulIfMatchType;  /* rule's interface match */
    struct FW_BR_T  stInBr;         /* rule's Lan Interface, -i for iptables  */
    struct FW_BR_T  stOutBr;        /* rule's Wan Interface, -o for iptables */
    
    UINT32  ulProtocol;             /* protocol of rule to match -p for iptables */ 
    CHAR    acProtocol[8];          /* protocol name for iptables */
    struct FW_PORT_T stSrcPort;     /* source port configure --sport for iptables */
    struct FW_PORT_T stDstPort;     /* destination port configure --dport for iptables */
    CHAR    acSsid[32];             /* ssid for -m ssid --ssid match */
    CHAR    acUrl[64];              /* for url dorp -m string --string xxxx --algo bm */
    unsigned int    ulMarkMatch;                  /* mark match value, -m mark --mark x for iptables */

    struct FW_ACTION_T  stRuleAction;   /* rule's action . eg. ACCETP DROP ... */

    char   acIptAddCmd[256];            /* iptables command */
    unsigned int ulIptCmdDelCnt;        /* delete iptables cmd location , -A/I to -D */
    char   acIptDelCmd[256];            /* iptables del command */
    
    unsigned int        ulChainId;       /* rule's chain id;  0:input 1:forward 2:mangle prerouting */
    char                acChainName[32];
    unsigned int        ulIptAddType;       /* iptables command 0: -A(--append) 1: -I(--insert)*/
	struct list_head	stListEntry;		/* list to forward chain */
    unsigned int        ulInsertIndex;      /* insert index when use -I command */
};


#define M_RULE_NUM_MAX      512
#define M_RULE_CHILDID_MAX  4
struct FW_CONFIG_RULE_T 
{
    unsigned int ulRuleNum;     /* number of rule */
    
    struct FW_RULE_T astRule[M_RULE_NUM_MAX][M_RULE_CHILDID_MAX];

    struct list_head  stForwardList;  /* */
    struct list_head  stInputList;    /* */
    struct list_head  stManglePreList;
    
    int iForwardMaxBigId;    /* record current forward max big_index */
    int iInputMaxBigId;      /* record current input max big_index */
    int iManglePreMaxBigId;  /* record current mangle prerouting max big_index */

    /* 次大的 ID, 当删除规则时，需要用到该值进行赋值操作 */
    //int iForwardMaxBigId_s;    /* record current forward max big_index */
    //int iInputMaxBigId_s;      /* record current input max big_index */
    //int iManglePreMaxBigId_s;  /* record current mangle prerouting max big_index */

    int iForwardListNum;
    int iInputListNum;
    int iManglePreListNum;
};


typedef AC_DEVM_NATGLOBAL_CONFIG_T NAT_GLOBAL_CONFIG_T;

/* AC configure table 3 :rules */
#define NAT_CONFIG_TYPE_NORMAL          0  /* 正常(非默认NAT)的NAT规则配置 */
#define NAT_CONFIG_TYPE_DEFAULT         1  /* 默认NAT的NAT规则配置 */


#define M_NAT_NORMAL_NUM_MAX        32
#define M_NAT_DEFAULT_NUM_MAX       (32+8)
#define M_NAT_NUM_MAX               (M_NAT_NORMAL_NUM_MAX + M_NAT_DEFAULT_NUM_MAX)

extern CHAR g_acIptNatAddCmd[M_NAT_NUM_MAX][256];
/* location of nat command '-A', record it for '-D' */
extern UINT32 g_aulNatDelCnt[M_NAT_NUM_MAX];

struct FW_NAT_T
{
    UINT32 ulNatId;         /* index of nat rule */
    UINT32 ulWorking;       /* 工作状态记录 */
    UINT32 ulNatAction;     /* action : 0 masquerade 1 snat 2 dnat */;
    CHAR   acNatAction[16]; /* action by string */
    struct FW_IP_T stSrcIp;        /* source ip of nat rule to match */
    struct FW_IP_T stNatIpBegin;   /* destination begin ip of nat: only use struct member : acIp */
    struct FW_IP_T stNatIpEnd;     /* destination end ip of nat : only use strcut memeber : acIp*/
    UINT8  aucNatIptCmd[3][256];      /*2011.8.25 cuiyilong nat 规则添加端口修改为二维数组，针对不同协议进行处理*/
    UINT32 ulNatIptDelCnt;
    /* BEGIN: Added by haodongdong, 2013/7/23   task 941 */
    UINT32 ulNatOutIfType;
    /* END:   Added by haodongdong, 2013/7/23   task:941 */
};


struct FW_CONFIG_NAT_T
{
    UINT32 ulTotalNatNum;   /* 所有NAT规则的数目 */
    UINT32 ulNormalNatNum;  /* 正常NAT规则配置个数 */
    UINT32 ulDefaultNatNum; /* 默认NAT规则配置个数 , 这个数值与在g_stNat中的序号并不一定一致 */
    UINT8  aucDefaultNatIp[4];

    /* 正常NAT配置从0开始， 默认NAT规则从M_NAT_NUM_MAX开始 */
    struct FW_NAT_T  astNat[M_NAT_NUM_MAX];
};

extern struct FW_CONFIG_NAT_T g_stNat;

/* fcgao edit 2009.10.22 for whitelist update */
typedef struct _FW_WHITELIST {
    AC_DEVM_WHITELIST_CONFIG_T stWhitelistCfg;
    UINT32 ulValid; /* 该配置是否有效字段 */
}FW_WHITELIST_T;

#define M_WHITELIST_NUM_MAX         64
/* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
#define M_WHITEURL_NUM_MAX			64
/* END:   Added by wns, 2012/11/16   PN:TASK#225 */
struct PORTAL_T{
    CHAR acPortalIp[16];  
    UINT16 usPortalPort;
    char acPortalUrl[64];
    UINT32 ulWhitelistNum ;     /* 白名单个数 */
    CHAR acWhitelistCmd[1024];
    CHAR acPortalNetDevName[32]; 
	UINT32 ulAuthTimeOut;
    /* 使用白名单IP是否为0,决定是否成员被使用 */
    AC_DEVM_WHITELIST_CONFIG_T astWhitelist[M_WHITELIST_NUM_MAX]; 
	CHAR acDelIptCmd_TCP[256];
	CHAR acDelIptCmd_UDP[256];
	/* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
	UINT32 ulWhiteUrlNum;
    UINT32 auiWhiteUrlId[M_WHITEURL_NUM_MAX];//值为0即为空，为(下标+1)时不为空
    /* END:   Added by wns, 2012/11/16   PN:TASK#225 */
} ;
extern  struct PORTAL_T g_stPortal;

#ifdef DAEMON
#define M_P_ERROR   LOG_ERR
#define M_P_WARNING LOG_WARNING
#define M_P_INFO    LOG_INFO
#else
/* define self printf : add funtion name and line */
#define M_P_ERROR       ((unsigned int)2)
#define M_P_WARNING     ((unsigned int)1)
#define M_P_INFO        ((unsigned int)0)
#endif

extern unsigned int g_print_level;
extern unsigned char g_acLevel[3][8];
extern char g_print_buffer[512];

#define  RULE_BIG_ID(pstRule) ((pstRule->ulRuleId) * M_RULE_CHILDID_MAX + pstRule->ulChildRuleId)


/* 2010-3.15 修改打印方式，改为syslogu
#define myprintf syslog
*/
#ifdef DAEMON
#define myprintf(level, format, arg...) do {\
    syslogu(LM_FW, level, "%s line :%d"format, __FUNCTION__,__LINE__,##arg);  \
}while(0);
#else
#define myprintf(level, format, arg...) do {                                                    \
    if(level >= g_print_level){                                                                  \
        sprintf(g_print_buffer, "[FW][%d][%s][%s] : ", __LINE__, __func__, g_acLevel[level]);   \
        sprintf(g_print_buffer + strlen(g_print_buffer), format, ##arg);                        \
        printf("%s\n",g_print_buffer);                                                          \
    }                                                                                           \
}while(-1 == __LINE__);
#endif


struct FW_STS_T
{
	UINT32	ulAcId;
	
	UINT32	ulAclNum;		/*		ACL的总条目数*/
	UINT32	ulDropPktNum;	/*		ACL丢弃报文总数*/
	UINT32	ulAcceptPktNum;	/*		ACL通过报文总数*/
	UINT32	ulMarkPktNum;	/*		ACL标记报文总数*/
	UINT32	ulTcpPktNum;	/*		ACL显式处理的TCP报文总数*/
	UINT32	ulTcpDropNum;	/*		TCP报文丢弃总数*/
	UINT32	ulTcpAcceptNum;	/*		TCP报文通过总数*/
	UINT32	ulTcpMarkNum;	/*		TCP报文其它处理总数*/
	UINT32	ulUdpPktNum;	/*		ACL显式处理的UDP报文总数*/
	UINT32	ulUdpDropNum;	/*		UDP报文丢弃总数*/
	UINT32	ulUdpAcceptNum;	/*		UDP报文通过总数*/
	UINT32	ulUdpMarkNum;		/*	UDP报文其它处理总数*/
	UINT32	ulIcmpPktNum;		/*		ACL显式处理的ICMP报文总数*/
	UINT32	ulIcmpDropNum;		/*		ICMP报文丢弃总数*/
	UINT32	ulIcmpAcceptNum;	/*		ICMP报文通过总数*/
	UINT32	ulIcmpMarkrNum;		/*		ICMP报文其它处理总数*/


};
struct FW_STS_T g_stAclSts;


#define IS_TCP_UDP(proto)   ((proto) == 6 || (proto) == 17)

void rule_all_clean(void);
void nat_all_clean(void);
void rule_all_start(void);
void nat_all_start(void);
INT32 rule_del(UINT32 ulRuleId, UINT32 ulChildRuleId);
INT32 nat_del(UINT32 ulNatId);
INT32 nat_add(struct FW_NAT_T *pstNat);
INT32 rule_add(UINT32 ulId, UINT32 ulChildId);
INT32 fw_msg_portal_handle(AC_DEVM_PORTAL_CONFIG_T * pstConfig);
INT32 fw_msg_whitelist_handle(UINT16 usMsg, AC_DEVM_WHITELIST_CONFIG_T *pstConfig);
VOID fw_get_rule_config(VOID);
VOID nat_get_config(VOID);
void fw_send_statistic_msg(AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T * pstReq);
int rule_add_type_get(struct FW_RULE_T *pstRule);
void fw_br_if_show(AC_DEVM_BRIDGE_CONFIG_T *pstIf);
INT32 fw_msg_disauth_handle(UINT16 usMsg, AC_DEVM_FREEADDR_CONFIG_T *pstConfig);

void portal_ioctl(UINT32 ulMsg, void *pvData);

#define IS_INVALID_IP(ip) ((ip[0]==0 && ip[1]==0 && ip[2]==0 &&ip[3]==0) \
                          ||(ip[0]==0xff && ip[1]==0xff && ip[2]==0xff &&ip[3]==0xff))

#define FW_INVALID_ID  ((UINT32)0xFFFFFFFF)
#endif

