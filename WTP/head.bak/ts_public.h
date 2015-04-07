#ifndef __TS_PUBLIC__
#define __TS_PUBLIC__
 /*2011 11.30 cuiyilong add*/
#define TS_MODULE_USRM 2
#define TS_MODULE_ACCOUNT 0
#define TS_MODULE_PORTAL 1
 /*2011 11.30 cuiyilong add*/
#define IS_TS_CMD(cmd)  ((cmd) >= 300 && (cmd) < 400)

/* ��������ͨ��USRMģ���·� */
#define TS_USRM_ADD_USER_CMD       300
#define TS_USRM_DEL_USER_CMD       301
#define TS_USRM_RESET_USER_CMD     302
 /*2011 11.30 cuiyilong add*/
#define TS_USRM_RESET_USER_MOD_CMD  312
#define TS_USRM_DELETE_SSID_CMD     313
 /*2011 11.30 cuiyilong add*/
/* AAA�·����� */
#define TS_AAA_GET_MULTI_USER_CMD   303
#define TS_AAA_GET_USER_STAT_CMD    304
#define TS_AAA_SET_USER_STAT_CMD    310
/*2011 9.28 cuiyilong add  get flow by ssid */
#define TS_AAA_GET_SSID_STAT_CMD    311
/*2011 9.28 cuiyilong add end*/
/* ��������ͨ��L2W�·� */
#define TS_DEVM_ADD_LANBR_CMD       305
#define TS_DEVM_DEL_LANBR_CMD       306
#define TS_DEVM_ADD_WANBR_CMD       307
#define TS_DEVM_DEL_WANBR_CMD       308

/* ���Խӿ� */
#define TS_PRINT_SET                309


/* TSģ����USRM��Ľӿڣ� ֪ͨTSģ����Ҫ����ͳ�Ƶ��û�IP��ַ �� mac��ַ */
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

/* ͳ��ģ����Ʒ�ģ���ӿڽṹ��:���ͳ����Ϣ */
typedef struct 
{
    unsigned int  ulReqUserNum;
    /* ulGetType 0 : ���ݺ���ṹ���IP��ַ��ȡulUserNum����Ϣ����ֵ��Ч 
                 1 : ˳���ȡhash���д�ulReqLoc��ʼ����Ч��ulUserNum���ڵ� */
    unsigned int  ulGetType;
    unsigned int  ulReqLoc; 
    unsigned int  ulRspUserNum;
    unsigned int  ulFinished;
    TS_AAA_USER_STATISTIC_T astUserStat[16];

} TS_AAA_MULTI_USER_STATISTIC_T;


/* TSģ���USRM���ioctl�ṹ�嶨�� */
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
