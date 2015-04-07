#ifndef _DHCPCTL_H_
#define _DHCPCTL_H_

//#define SIM_USERM
#ifdef  SIM_USERM
#define DBG_MAX_STA_VLAN_NUM 10
#define DBG_MAX_STA_RECENT_ALLOC 10
#endif

#define AC_DHCP_MAX_INNER_ERR_NUM       10
#define AC_DHCP_MSG_TYPE_POOL_INFO_UPT  1
#define AC_DHCP_MSG_TYPE_LEASE_UPT      2

#define DHCP_STA_STATIC_IP_ADDRESS_TBL_SIZE     256
#define DHCP_STA_DYNAMIC_IP_ADDRESS_TBL_SIZE    256  /* fcgao edit from 32 to 256 */
#define DHCP_AP_STATIC_IP_ADDRESS_TBL_SIZE      256
#define DHCP_AP_DYNAMIC_IP_ADDRESS_TBL_SIZE     256  /* fcgao edit from 32 to 256 */

#define DHCP_STA_ENALBE_NONE            0
#define DHCP_STA_ENABLE_SERVER          1
#define DHCP_STA_ENABLE_RELAY           2
#define DHCP_AP_ENALBE_NONE             0
#define DHCP_AP_ENABLE_SERVER           1
#define DHCP_AP_ENABLE_RELAY            2
#define DHCP_AP_ENABLE_PRIVATE          3 /* not defined in document */

#define DHCP_ROLE_AP_SRV                1
#define DHCP_ROLE_AP_RELAY              2
#define DHCP_ROLE_AP_PRI_SRV            3
#define DHCP_ROLE_STA_SRV               4
#define DHCP_ROLE_STA_RELAY             5

#define LEASE_STATE_FREE	 1
#define LEASE_STATE_ACTIVE	 2
#define LEASE_STAT_EXPIRED	 3
#define LEASE_STAT_RELEASED	 4
#define LEASE_STAT_ABANDONED 5
#define LEASE_STAT_RESET	 6
#define LEASE_STAT_BACKUP	 7
#define LEASE_STAT_LAST LEASE_STAT_BACKUP

/*
FIT-LAN妗?                    br0
FAT-LAN/L2-WAN     br1
L3-WAN             br2
*/
#define DHCP_USE_SYSLOGU              1

/* Mapping AP-DHCP public port to private port (7100) */
//AP级DHCP服务端口修改为标准端口
//#define DHCP_NO_AP_PUBLIC_SERVER    	//pyy 2009-10-19		
#define DEV_FIT_LAN_NAME              "br0"
//#define DEV_FIT_LAN_NAME              "eth0"
//#define DEV_FIT_LAN_NAME              "pan0"

#define DEV_FAT_LAN_NAME              "br1" 
#define DEV_L2_WAN_NAME               "br1"
#define DEV_L3_WAN_NAME               "br2"

#define SYSCMD_TOUCH_NAME             "touch"
#define DHCPSERVER_CONTROL_NAME       "dhcpctl"
#define DEVM_CONTROL_NAME             "powerac" 
#define DHCPSERVER_PROGRAME_NAME      "/usr/local/sbin/dhcpd"
#define DHCPRELAY_PROGRAME_NAME       "/usr/local/sbin/dhcrelay"
/* used this macro to locate config file */



#define CONFIG_FILE                   ""

/* Modified by majp 2013-03-01 start */
//#define STA_DB_FILE_NAME              CONFIG_FILE"/var/db/dhcpd_sta.leases"
//#define AP_DB_FILE_NAME               CONFIG_FILE"/var/db/dhcpd_ap.leases"
#define DHCP_DB_FILE_NAME              CONFIG_FILE"/dev/shm/dhcpd.leases"
/* Modified by majp 2013-03-01 end */


#define DHCP_CFG_FILE_NAME             CONFIG_FILE"/etc/dhcpd.conf"


#define DHCP_PID_FILE_NAME             CONFIG_FILE"/var/run/dhcpd.pid"




#define eval(cmd, args...) ({ \
	        char *argv[] = { cmd, ## args, NULL }; \
	        my_exec_process(argv); \
	})
#define killall(pname) killProcessId(pname)

#define  DHCP_P_FATAL    		5
#define  DHCP_P_FAIL    		4
#define  DHCP_P_ERROR    		3
#define  DHCP_P_WARNING  	    3
#define  DHCP_P_INFO     		6
#define  DHCP_P_DETAIL   		3

#ifdef DHCP_USE_SYSLOGU
#define dhcp_printf(level, format, arg...) do{\
	syslogu(LM_DHCP, level,format, ##arg);	\
}while(0);
#else
#define dhcp_printf(level, format, arg...) do{\
	syslog(level,format, ##arg);	\
}while(0);	
#endif


typedef struct acDhcpLeasesList_s {
    unsigned long ulMsgLen;
    unsigned long ulCounter;
    unsigned char iabuf[4];
    unsigned char habuf[6];
    unsigned char hosttype;
    unsigned char resv;
    unsigned char imask[4];
    unsigned long ulVlanId;
    unsigned char hostname[32];
    time_t stStartTime;
    time_t stEndTime;
    time_t stCltt;
    time_t stRptTime;
    unsigned long binding_state;
    unsigned long next_binding_state;
    /* Add by majp 2012-10-26 start zentao bug 682*/
    unsigned int uiAddrType;
#define STATIC_ADDR         0
#define DYNAMIC_ADDR      1
    /* Add by majp 2012-10-26 end */
} acDhcpLeaseInfo_t;

typedef struct acDhcpPoolInfo_s {
    unsigned long ulMsgLen;
    /* 0 means for sum of all subnets */
    unsigned long ulSubnetId;
    /* ulLeaseCount = ulActiveLeases + ulFreeLeases + ulBackupLeases */
    unsigned long ulLeaseCount;
    unsigned long ulActiveLeases;
    unsigned long ulFreeLeases;
    unsigned long ulBackupLeases;
    /* ulPoolFilled = ulActiveLeases * 100 / ulLeaseCount */
    unsigned long ulPoolFilled;
    unsigned long ulType;
    unsigned long ulDhcpReqNum;
    unsigned long ulDhcpSuccNum;

    /* fcgao add for discover and offer statistics at 2011-4-15 begin */
    unsigned long ulDhcpDiscoverNum;
    unsigned long ulDhcpOfferNum;
    /* fcgao add for discover and offer statistics at 2011-4-15 end */   
} acDhcpPoolInfo_t;

typedef struct  ac_DhcpUpdateInfo_s{
    unsigned long     ulMsgLen;
    acDhcpLeaseInfo_t stLease;
    acDhcpPoolInfo_t stPool4All;
    acDhcpPoolInfo_t stPool4Net;
} ac_DhcpUpdateInfo_t;


//add by majp 2011-9-29 start

#define POOL_USAGE_ARRAY_SIZE 		512
#define STAT_WINDOW_TIME_MAX 		900
#define STAT_WINDOW_TIME_MIN 		60
#define STAT_WINDOW_TIME_DEFAULT 	300
#define SAMPLE_TIME_MAX 				60
#define SAMPLE_TIME_MIN 				2	
#define SAMPLE_TIME_DEFAULT 			10

typedef struct ac_DhcpPoolUsageInfo_s{
	unsigned long ulSubnetId;
	unsigned long ulPoolUsageArray[POOL_USAGE_ARRAY_SIZE];
	unsigned int	iPoolUsageIndex;
	unsigned long ulPoolUsage;
	struct ac_DhcpPoolUsageInfo_s *prev;
	struct ac_DhcpPoolUsageInfo_s *next;
}ac_DhcpPoolUsageInfo_t;

typedef struct ac_DhcpPoolUsageList_s{
	struct ac_DhcpPoolUsageInfo_s *head;
	struct ac_DhcpPoolUsageInfo_s *tail;
	int counter;
}ac_DhcpPoolUsageList_t;

extern ac_DhcpPoolUsageList_t *stPoolUsageList;

extern int iStatWindowTime;
extern int iSampleTime;

extern ac_DhcpPoolUsageList_t *dhcp_poolusage_init();

extern void dhcp_poolusage_destory(ac_DhcpPoolUsageList_t *poolusagelist);

extern int dhcp_add_poolusage(ac_DhcpPoolUsageList_t *poolusagelist,unsigned long subnet_id,unsigned long poolusage);

extern int dhcp_del_poolusage(ac_DhcpPoolUsageList_t *poolusagelist,unsigned long subnet_id);

extern int dhcp_modify_poolusage(ac_DhcpPoolUsageList_t *poolusagelist,unsigned long subnet_id,unsigned long poolusage);

extern ac_DhcpPoolUsageInfo_t * dhcp_find_poolusage(ac_DhcpPoolUsageList_t *poolusagelist,unsigned long subnet_id) ;

extern void dhcp_set_poolusage_list(ac_DhcpPoolUsageList_t *poolusagelist,unsigned long subnet_id,unsigned long poolusage);

extern void get_poolusage();

extern unsigned long get_poolpeakusage(unsigned long subnet_id);

extern void dhdb_ac_ownconfig_update(AC_DEVM_AC_OWNCONFIG_UPDATE_IND_MSG_T* pstReq);

//add by majp 2011-9-29 end

/***************************************************************************************
 *   DHCP get remote call to daemon
 ***************************************************************************************/
typedef struct ac_DhcpReq_Vlan_s {
    unsigned long ulMsgLen;
    unsigned char chaddr[6];
    unsigned char rsv[2];
} ac_DhcpReq_Vlan_t;

typedef struct ac_DhcpRsp_Vlan_s {
    unsigned long ulMsgLen;
    unsigned long port_type;
    unsigned long vlan_id;
    unsigned char chaddr[6];/*add by fangz for vlan is fail*/
} ac_DhcpRsp_Vlan_t;

#define DHCP_MESSAGE_GET_VLAN_REQ     1
#define DHCP_MESSAGE_GET_DADADADA_REQ 2
#define DHCP_MESSAGE_CTL_REBOOT_REQ   3

#define DHCP_MESSAGE_GET_VLAN_RSP     101
#define DHCP_MESSAGE_GET_DADADADA_RSP 102
#define DHCP_MESSAGE_CTL_REBOOT_RSP   103


typedef struct ac_DhcpReqInfo_s {
    unsigned long ulMsgLen;
    unsigned long ulMsgType;
    union {
        ac_DhcpReq_Vlan_t stVlan;
    } u;
}ac_DhcpReqInfo_t;

typedef struct ac_DhcpRspInfo_s {
    unsigned long ulMsgLen;
    unsigned long ulMsgType;
    unsigned long ulRet;
    union {
        ac_DhcpRsp_Vlan_t stVlan;
    } u;
}ac_DhcpRspInfo_t;
/***************************************************************************************/

typedef struct {
    AC_DEVM_STADHCPGLOBAL_CONFIG_T g_stStaDhcpGlobal;
    AC_DEVM_STADHCPSTATICIP_CONFIG_T g_stStaDhcpStatic[DHCP_STA_STATIC_IP_ADDRESS_TBL_SIZE];
    AC_DEVM_STADHCPDYNIP_CONFIG_T g_stStaDhcpDyn[DHCP_STA_DYNAMIC_IP_ADDRESS_TBL_SIZE];
    unsigned char g_stDhcpStatic_flg_tbl[DHCP_STA_STATIC_IP_ADDRESS_TBL_SIZE];
    unsigned char g_stDhcpDyn_flg_tbl[DHCP_STA_DYNAMIC_IP_ADDRESS_TBL_SIZE];
} sta_config_t;

typedef struct {
    AC_DEVM_APDHCPGLOBAL_CONFIG_T g_stApDhcpGlobal;
    AC_DEVM_APDHCPSTATICIP_CONFIG_T g_stApDhcpStatic[DHCP_AP_STATIC_IP_ADDRESS_TBL_SIZE];
    AC_DEVM_APDHCPDYNIP_CONFIG_T g_stApDhcpDyn[DHCP_AP_DYNAMIC_IP_ADDRESS_TBL_SIZE];
    unsigned char g_stDhcpStatic_flg_tbl[DHCP_AP_STATIC_IP_ADDRESS_TBL_SIZE];
    unsigned char g_stDhcpDyn_flg_tbl[DHCP_AP_DYNAMIC_IP_ADDRESS_TBL_SIZE];
} ap_config_t;

extern sta_config_t g_stStaConfig;
extern ap_config_t g_stApConfig;
extern long errorCount;

extern int g_iMonitorSrv;
extern int g_iMonitorRelay;

extern int g_imsstate;
/*
   Function Interface
*/
extern AC_DEVM_GET_STADHCPGLOBAL_CONFIG_RSP_T* get_sta_global_config(void);
extern AC_DEVM_GET_STADHCPSTATICIP_CONFIG_RSP_T* get_sta_static_config(UINT32 ulStartRec);
extern AC_DEVM_GET_STADHCPDYNIP_CONFIG_RSP_T* get_sta_dyn_config(UINT32 ulStartRec);
extern AC_DEVM_GET_APDHCPGLOBAL_CONFIG_RSP_T* get_ap_global_config(void);
extern AC_DEVM_GET_APDHCPSTATICIP_CONFIG_RSP_T* get_ap_static_config(UINT32 ulStartRec);
extern AC_DEVM_GET_APDHCPDYNIP_CONFIG_RSP_T* get_ap_dyn_config(UINT32 ulStartRec);
extern AC_USRM_GET_USERVLAN_RSP_T* usrm_get_user_vlan(unsigned char *aucMac);

extern int dhcp_fetch_sta_global_cfg(void);
extern int dhcp_fetch_sta_dync_cfg(void);
extern int dhcp_fetch_sta_static_cfg(void);
extern int dhcp_fetch_ap_global_cfg(void);
extern int dhcp_fetch_ap_dync_cfg(void);
extern int dhcp_fetch_ap_static_cfg(void);

extern int  dhcp_db_init(void);
extern void dhcp_db_loop_wait(void);
extern void dhcp_db_exit(void);
extern void dhdb_get_dync_user_info(AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T* pstReq);
extern void dhdb_get_dync_pool_info(AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T* pstReq);
extern void dhcp_db_delete_pool(unsigned long * pulSubnetId);

extern void quit_process();
extern const char *print_time(time_t t);
extern int  FiFo_Read(int fd, void *buf,size_t count);
extern void ShowLeaseInfo(acDhcpLeaseInfo_t *pLease);
extern void ShowPoolInfo(acDhcpPoolInfo_t   *pPool);
extern int  GetRouteInfo(const unsigned char *csDest, char *csInf, char *csSource);

extern unsigned int socket_create_listern (WORD wSvrPort);

/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define DHCP_USER_IP_VALID_ALLOCATED 		0
#define DHCP_USER_IP_INVALID 				1
#define DHCP_USER_IP_VALID_UNALLOCATED	    2
#define DHCP_USER_IP_ERR					3
typedef struct ac_Dhcp_Ip_Range_s {
	UINT8   	aucBeginIp[4]	        		;   	/* 起始地址                 */
	UINT8   	aucEndIp[4]	            		;   	/* 结束地址                 */
	UINT8   	aucMask[4]	            		;   	/* 掩码                     */
}ac_Dhcp_Ip_Range_t;
int iRangeCount;
ac_Dhcp_Ip_Range_t g_stStaIpRange[128];
/*end bug#1926 cmcc test fangz 2013.2.20*/

#endif
