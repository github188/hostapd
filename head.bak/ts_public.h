#ifndef __TS_PUBLIC__
#define __TS_PUBLIC__
 /*2011 11.30 cuiyilong add*/
#define TS_MODULE_USRM 2
#define TS_MODULE_ACCOUNT 0
#define TS_MODULE_PORTAL 1
 /*2011 11.30 cuiyilong add*/
#define IS_TS_CMD(cmd)  ((cmd) >= 300 && (cmd) < 400)

/* 以下命令通过USRM模块下发 */
#define TS_USRM_ADD_USER_CMD       300
#define TS_USRM_DEL_USER_CMD       301
#define TS_USRM_RESET_USER_CMD     302
 /*2011 11.30 cuiyilong add*/
#define TS_USRM_RESET_USER_MOD_CMD  312
#define TS_USRM_DELETE_SSID_CMD     313
 /*2011 11.30 cuiyilong add*/
/* AAA下发命令 */
#define TS_AAA_GET_MULTI_USER_CMD   303
#define TS_AAA_GET_USER_STAT_CMD    304
#define TS_AAA_SET_USER_STAT_CMD    310
/*2011 9.28 cuiyilong add  get flow by ssid */
#define TS_AAA_GET_SSID_STAT_CMD    311
/*2011 9.28 cuiyilong add end*/
/* 以下命令通过L2W下发 */
#define TS_DEVM_ADD_LANBR_CMD       305
#define TS_DEVM_DEL_LANBR_CMD       306
#define TS_DEVM_ADD_WANBR_CMD       307
#define TS_DEVM_DEL_WANBR_CMD       308

/* 调试接口 */
#define TS_PRINT_SET                309


/* TS模块与USRM间的接口， 通知TS模块需要进行统计的用户IP地址 和 mac地址 */
typedef struct {
    unsigned char   aucUserIp[4];
    unsigned char   aucUserMac[6];
    unsigned char   aucPad[2];  
    /*2011 9.28 cuiyilong add*/
	char acSsid[32];
    /*2011 9.28 cuiyilong add end*/
    /*2011 11.30 cuiyilong add*/
    unsigned int iModFlag;
    /*2011 11.30 cuiyilong add*/
} TS_USRM_ADD_USER_T;
typedef  TS_USRM_ADD_USER_T TS_USRM_DEL_USER_T;
typedef  TS_USRM_ADD_USER_T TS_USRM_RESET_USER_T; 
typedef  TS_USRM_ADD_USER_T TS_USRM_RESET_MOD_T; 
typedef  TS_USRM_ADD_USER_T TS_USRM_DELETE_SSID_T;
typedef struct {
    unsigned int ulBrId;
    char         acBrName[32];
} TS_DEVM_BR_T;

typedef struct {
    unsigned char aucUserIp[4];
    
    unsigned int ulRxPkts;
    unsigned int ulTxPkts;
    unsigned int ulRxGigaWords;
    unsigned int ulRxBytes;
    unsigned int ulTxGigaWords;
    unsigned int ulTxBytes;
    
} TS_AAA_USER_STATISTIC_T;
/*2011 9.28 cuiyilong add  struct of ssid flow  */
typedef struct {
    char acSsid[32];
    unsigned int ulRxPkts;
    unsigned int ulTxPkts;
    unsigned int ulRxGigaWords;
    unsigned int ulRxBytes;
    unsigned int ulTxGigaWords;
    unsigned int ulTxBytes;
} TS_AAA_SSID_STATISTIC_T;
/*2011 9.28 cuiyilong add end */

/* 统计模块与计费模块间接口结构体:输出统计信息 */
typedef struct 
{
    unsigned int  ulReqUserNum;
    /* ulGetType 0 : 根据后面结构体的IP地址获取ulUserNum个信息，本值无效 
                 1 : 顺序读取hash表中从ulReqLoc开始的有效的ulUserNum个节点 */
    unsigned int  ulGetType;
    unsigned int  ulReqLoc; 
    unsigned int  ulRspUserNum;
    unsigned int  ulFinished;
    TS_AAA_USER_STATISTIC_T astUserStat[16];

} TS_AAA_MULTI_USER_STATISTIC_T;


/* TS模块和USRM间的ioctl结构体定义 */
typedef struct  {
	int iCmd; /* from 300-399 */

	union {
        unsigned int            ulPrintOn;
		TS_USRM_ADD_USER_T	    stAddStatUser;
		TS_USRM_DEL_USER_T	    stDelStatUser;
		TS_USRM_RESET_USER_T	stResetUserStat;
		/*2011 11.30 cuiyilong add*/
		TS_USRM_DELETE_SSID_T   stDeleteSsid;
		TS_USRM_RESET_MOD_T	stResetModUser;
		/*2011 11.30 cuiyilong add*/
		TS_AAA_USER_STATISTIC_T	st3AUserStat;
        TS_AAA_MULTI_USER_STATISTIC_T st3AMultiUserStat;
		/*2011 9.28 cuiyilong add*/
		TS_AAA_SSID_STATISTIC_T st3ASsidStat;
        /*2011 9.28 cuiyilong add end*/
              TS_DEVM_BR_T stBr;
	} u;
} TS_IOCTL_T;

//typedef unsigned char u8


#endif
