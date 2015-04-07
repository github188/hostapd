#ifndef __TS_MODULE__
#define __TS_MODULE__


/* TSģ��ͳ�ƹ��ӵĽṹ�� */
typedef struct 
{
    unsigned int ulRxPkts;
    unsigned int ulTxPkts;
    unsigned int ulRxGigaWords;
    unsigned int ulRxBytes;
    unsigned int ulTxGigaWords;
    unsigned int ulTxBytes;
    
    unsigned int ulTxBytesLast;
    unsigned int ulRxBytesLast;
} TS_USER_STATISTIC_T;

/*2011 9.28 cuiyilong add  TS */
typedef struct {
    char     acSsid[32]; 
    unsigned int ulRxPkts;
    unsigned int ulTxPkts;
    unsigned int ulRxGigaWords;
    unsigned int ulRxBytes;
    unsigned int ulTxGigaWords;
    unsigned int ulTxBytes;
    unsigned int ulTxBytesLast;
    unsigned int ulRxBytesLast;
} TS_SSID_STATISTIC_T;
/*2011 9.28 cuiyilong add end*/
/* TSģ���û��ṹ�� */
typedef struct
{
    unsigned char   aucUserIp[4];
    unsigned char   aucUserMac[6];
	/*2011 9.28 cuiyilong add */
    char      acSsid[32];
	/*2011 9.28 cuiyilong add end*/
    /*2011.9.6cuiyilong  add  �û��������ü��� start*/
    unsigned int iRefCnt;
    /*2011.9.6cuiyilong  add  �û��������ü��� end*/
    TS_USER_STATISTIC_T stTst;
    struct hlist_node  stHlistNd;   

} TS_USER_T;
	/*2011 9.28 cuiyilong add */
typedef struct
{    
    char   acSsid[32];
    int iRefCnt;
   TS_SSID_STATISTIC_T stTst;
    struct hlist_node  stHlistNd;   

} TS_SSID_T;
/*2011 9.28 cuiyilong add end*/
/*2012 3.8 cuiyilong modify print level*/
#define TS_DATA 3
#define TS_DETAIL 2
#define TS_CMD 1
#define tsprintk(level,format,arg...)  if(g_ts_print_on >= level) printk(format,##arg)
		
#endif

