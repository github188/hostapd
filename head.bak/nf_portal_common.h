#ifndef _NF_PORTAL_COMMON_H
#define _NF_PORTAL_COMMON_H

typedef AC_DEVM_WHITELIST_CONFIG_T WHITELIST_T;
typedef AC_DEVM_PORTAL_CONFIG_T PORTAL_CONFIG_T ;
typedef AC_DEVM_GET_L2WAN_FIRSTIP_CONFIG_RSP_T BR1_IP_CONFIG_T;

#define M_WHITELIST_NUM_MAX 64
typedef struct {
    
	unsigned int ulNum;
	WHITELIST_T  astWhitelist[M_WHITELIST_NUM_MAX];
	
} WHITELIST_CONFIG_T;

typedef struct  
{
    unsigned char aucIp[4];
    unsigned char aucMac[6];
    
} AUTHING_USER_T;
typedef AUTHING_USER_T AUTH_FINISH_USER_T;

typedef struct
{
    unsigned int ulId ;
    unsigned char aucUrl[64];    

} URL_WHITELIST_T;

typedef struct
{
    URL_WHITELIST_T astUrl[32];  /* 调试接口，只支持前32个的查看 */
    int ulNumber;

} URL_WHITELIST_GET_T;
typedef struct
{
    unsigned char aucIp[32][4];  /* 调试接口，只支持前32个的查看 */
    URL_WHITELIST_T astUrl[32];  /* 调试接口，只支持前32个的查看 */
    int ulNumber;

} URL_IP_GET_T;

 

/* 免认证的最大用户个数 */
#define M_DISAUTH_USER_NUM_MAX 256   /* fcgao change to 256 at 2009.10.09 */
typedef struct
{
    unsigned char aucIp[4];
    unsigned char aucMask[4];  
} DISAUTH_USER_T;
typedef struct 
{
    unsigned char aucMac[6];  
    unsigned char aucRes[2];
} DISAUTH_MAC_USER_T;
typedef DISAUTH_USER_T DISAUTH_SET_USER_T;
typedef DISAUTH_MAC_USER_T DISAUTH_SET_MAC_USER_T;

typedef struct  
{
    unsigned int ulIpNum;
	unsigned int ulMacNum;
    DISAUTH_USER_T astUser[M_DISAUTH_USER_NUM_MAX];
} DISAUTH_GET_USER_T;

typedef struct  
{
    unsigned int ulIpNum;
	unsigned int ulMacNum;
    DISAUTH_MAC_USER_T astMacUser[M_DISAUTH_USER_NUM_MAX];
} DISAUTH_GET_MAC_USER_T;


/* 最大支持64个用户 */
typedef struct
{
    unsigned int ulUserNum;
    AUTHING_USER_T astAuthingUser[64];
} ALL_AUTHING_USER_T;

/* 已经鉴权完成的用户 */
typedef struct 
{
	unsigned short usValid;
	unsigned char aucMac[6];
} TEST_AUTH_FINISH_USER_T;
typedef struct 
{
	unsigned int ulNum;
	TEST_AUTH_FINISH_USER_T stAuthedUser[64];
} TEST_ALL_AUTH_FINISH_USER_T;

typedef struct 
{
    unsigned int ulNum;
    unsigned char aaucIp[40][4];
    unsigned int ulIpType; /* 1 : Br0   2 : Br1  3: Br2 */
}LOCAL_IP_CONFIG_T;

/* BEGIN: Added by wns, 2012/11/21   PN:TASK#225 */
#define URL_NUM_PER_IOCTL			8
#define IP_NUM_PER_IOCTL			16

#define PORTAL_IOCTL_UNFINISHED		0
#define PORTAL_IOCTL_FINISHED		1

typedef struct 
{
	unsigned short usStartNum;	//	本次获取的起始记录号
	unsigned short usRetNum;	//	本次读取的有效记录数
	unsigned short usIsFinish;	//	1:finished	0:unfinished
	unsigned long ulUrlId;		//	0:ALL	1~64:ID
	AC_DEVM_WHITEURL_CONFIG_T astUrl[URL_NUM_PER_IOCTL];
}PORTAL_WHITEURL_SHOW_T;

typedef struct 
{
	unsigned short usRetNum;	//	本次读取的有效记录数
	unsigned long ulUrlId;		//	1~64:ID
	unsigned long aulIp[IP_NUM_PER_IOCTL];
}PORTAL_WHITEURL_SHOWIP_T;	

typedef struct 
{
	unsigned long ulRWFlag;		//	1:R	2:W
	unsigned long ulTtl;
}PORTAL_WHITEURL_IPTTL_T;

typedef struct 
{
	unsigned short usUrlNum;
	unsigned short usIpNum;
}PORTAL_WHITEURL_NUM_T;
/* END:   Added by wns, 2012/11/21   PN:TASK#225 */

typedef struct 
{
    unsigned int iRet;
    union {
        AUTHING_USER_T stTestAddUser;
        AUTH_FINISH_USER_T stAuthFinished;
        AUTHING_USER_T stAuthingUser;
        AC_DEVM_PORTAL_CONFIG_T stPortalConfig;
        AC_DEVM_WHITELIST_CONFIG_T stWhiteList;  /* 单个配置增加删除修改 */
        WHITELIST_CONFIG_T stGetWhiteList;
        unsigned int  ulPortalIp;
        AC_DEVM_BRIDGE_CONFIG_T  stLanIf;
        ALL_AUTHING_USER_T stAllAuthingUser;
		TEST_ALL_AUTH_FINISH_USER_T stTestAuthedUser;
		DISAUTH_SET_USER_T stDisauthUser;  /* 配置不需要鉴权的ip用户 */
        DISAUTH_SET_MAC_USER_T stDisauthMacUser;  /* 配置不需要鉴权的ip用户 */
		DISAUTH_GET_USER_T astGetDisAuthUser;  /* 用户获取当前的免认证用户个数 */
        DISAUTH_GET_MAC_USER_T astGetDisAuthMacUser;  /* 用户获取当前的免认证用户个数 */
        BR1_IP_CONFIG_T astBr1FirstIp;  /* 桥1上的IP地址 */
        unsigned int ulGlobalFreeAuth;  /* 全局免认证开关配置 */
        LOCAL_IP_CONFIG_T   stLocalIp;
        AC_DEVM_ACIP_CONFIG_T	stAcIp;	/* AC IP */
        /* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
        AC_DEVM_WHITEURL_CONFIG_T	stWhiteUrl;
        PORTAL_WHITEURL_SHOW_T		stShowUrl;
        PORTAL_WHITEURL_SHOWIP_T	stShowIp;
        PORTAL_WHITEURL_IPTTL_T		stIpTtl;
        PORTAL_WHITEURL_NUM_T		stNum;
        /* END:   Added by wns, 2012/11/16   PN:TASK#225 */
    } stCfg;
    
} PORTAL_IOCTL;


#define PORTAL_GET_AUTHING_USER_MAC    		1//_IO(PORTAL_IOC_MAGIC, 0)
#define PORTAL_SET_USER_AUTH_FINISHED  		2// _IO(PORTAL_IOC_MAGIC, 1)
#define PORTAL_SET_WHITELIST_ADD            3
#define PORTAL_SET_WHITELIST_DEL            4
#define PORTAL_SET_WHITELIST_UPDATE         5
#define PORTAL_SET_WHITELIST_CONFIG         6
#define PORTAL_SET_GLOBAL_UPDATE            7
#define PORTAL_PRINTK                       8
#define PORTAL_SET_RESET                    9
#define PORTAL_SET_TEST_AUTHED_USER_ADD		10
#define PORTAL_SET_PORTAL_PORT				11
#define PORTAL_SET_PORTAL_IF				12
#define PORTAL_SET_PORTAL_TIMEOUT			13
#define PORTAL_SET_TEST_AUTHED_USER_DEL		14
#define PORTAL_SET_PORTAL_SERVER_IP         15
#define PORTAL_GET_WHITELIST                16
#define PORTAL_GET_PORTAL_SERVER_IP         17
#define PORTAL_GET_ALL_AUTHING_USER         18
#define PORTAL_GET_PORTAL_IF                19
#define PROTAL_GET_ALL_AUTH_FINISHED_USER	20
#define PORTAL_DEBUG_AUTH_FINISH  			21
#define PORTAL_ADD_DISAUTH_USER_MAC  		22
#define PORTAL_DEL_DISAUTH_USER_MAC  		23
#define PORTAL_ADD_DISAUTH_USER_IP  		24
#define PORTAL_DEL_DISAUTH_USER_IP  		25
#define PORTAL_GET_DISAUTH_USER  			26
#define PORTAL_SET_PORTAL_SWITCH  			27
#define PORTAL_GET_PORTAL_SWITCH  			28
#define PORTAL_GET_DISAUTH_MAC_USER         29
#define PORTAL_GET_MASKLIST                 30
#define PORTAL_SET_BR1_FIRSTIP              31
#define PORTAL_GET_BR1_FIRSTIP              32
#define PORTAL_SET_GLOBAL_FREEAUTH          33
#define PORTAL_GET_GLOBAL_FREEAUTH          34
#define PORTAL_SET_LOCAL_IP                 38
#define PORTAL_GET_LOCAL_IP                 39
#define PORTAL_SET_ACBR1_IP					40
/* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
#define PORTAL_WHITEURL_ADD					41
#define PORTAL_WHITEURL_DEL					42
#define PORTAL_WHITEURL_UPDATE				43
#define PORTAL_WHITEURL_SHOW				44
#define PORTAL_WHITEURL_SHOWIP				45
#define PORTAL_WHITEURL_IPTTL				46
#define PORTAL_WHITEURL_NUM					47
/* END:   Added by wns, 2012/11/16   PN:TASK#225 */

#endif
