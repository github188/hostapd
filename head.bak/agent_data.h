#ifndef AGENTDATA_H
#define AGENTDATA_H

#include "agent_type.h"
#include "./ifCommon.h"
#include "./_omaCommon.h"
#include "ifOmc/ifOmc.h"
#include "ifAc/ifAc.h"
#include "./ifRouter/router_config_common.h"

extern T_configFileData					configFileData;
extern T_configFileData					configFileDataTemp;
extern T_aclPolicySwitch				g_aclPolicySwitch;
extern T_fclBasicSetup					g_stFclBasicSetup;
extern T_routeBasicSetup				g_routerBasicSetup;
extern T_routerNeighSetup				g_routerNeighSetup;
extern T_routerHandoverSetup			g_routerHandoverSetup;
extern T_routerMscSetup					g_routerMscSetup;
extern AODV_NEIGHBOR_LIST_T				g_aodvNeighborList;
extern T_aodvRouteList					g_aodvRouteList;
extern T_sysBasicSetup					g_sysBasicSetup;
extern T_sysDownloadConfig				g_sysDownloadConfig;
extern T_sysDownloadLog					g_sysDownloadLog;
extern T_sysIpSetup						g_sysIpSetup;
extern T_sysKeeperSetup					g_sysKeeperSetup;
extern T_sysSwServerSetup				g_sysSwServerSetup;
extern T_sysLogSetup					g_sysLogSetup;
extern T_sysSntpSetup					g_sysSntpSetup;
extern T_sysPPPoESetup				g_sysPPPoESetup;
extern T_sysSnmpSetup					g_sysSnmpSetup;
extern T_radiusSerCfg					g_sysRadiusSerSetup;
extern T_sysVersionSetup			    g_sysVersionSetup;
extern T_sysPasswordChange				g_sysPasswordChange;
extern T_sysPingSummary					g_sysPingSummary;
extern T_sysPingTest					g_sysPingTest;
extern T_sysReboot						g_sysReboot;
extern T_sysResetConfig					g_sysResetConfig;
extern T_sysSetRtc						g_sysSetRtc;
extern UPDATA_SOFT_VERSION_T			g_sysUpdateImage;
extern UPDATA_SOFT_VERSION_T			g_sysUpdateRamdisk;
extern T_sysUpdateVersionProgress		g_sysUpdateVersionProgress;
extern T_sysUploadConfig				g_sysUploadConfig;
extern T_wifiDeviceAdd					g_wifiDeviceAdd;
extern T_wifiDeviceDelete				g_wifiDeviceDelete;
extern T_wifiDeviceTable				g_wifiDeviceTable;
extern T_wifiDeviceList					g_wifiDeviceList;
extern T_apVapAdd						g_apVapAdd;
extern T_apVapDelete					g_apVapDelete;
extern T_apVapTable					g_apVapTable;
extern T_apVapBasicTable				g_apVapTableOld;
extern T_apEndUserMac					g_apVapEndUserTable;
extern T_adhocVapAdd					g_adhocVapAdd;
extern T_adhocVapDelete					g_adhocVapDelete;
extern T_adhocVapTable					g_adhocVapTable;
extern T_adhocVapList					g_adhocVapList;
extern T_wifiDeviceValidWifiList		g_wifiDeviceValidWifiList;
extern T_apValidWifiDeviceList			g_apVapValidWifiDeviceList;
extern T_adhocValidWifiDeviceList		g_adhocValidWifiDeviceList;
extern T_enetInfTable					g_enetInfTable;
extern T_vlanAdd						g_vlanAdd;
extern T_vlanDelete						g_vlanDelete;
extern T_vlanModify						g_vlanModify;
extern T_vlanSwitch						g_vlanSwitch;
extern T_vlanSetupList					g_vlanSetupList;
extern T_sysPeriodOfValidity			g_sysPeriodOfValidity;
extern T_sysAppendCode					g_sysAppendCode;
//extern OMA_PERF_CFG_T					g_stPerfCfg;
extern T_capWapSetup					g_stCapWapSetup;
extern OMA_STA_VAP_TABLE				g_stStaVapTable;
extern T_ipForwardSetup					g_stIpForwardSetup;
extern T_tcpOptimizationSetup			g_stTcpOptimiSetup;
extern T_sysLoadBalanceSetup			g_stLoadBalanceSetup;


extern T_aclPolicySwitch				g_aclPolicySwitchOld;
extern T_SYSLOGO                        g_sysLogo;
//end addition
extern T_fclBasicSetup					g_stFclBasicSetupOld;
extern T_capWapSetup				g_stCapWapSetupOld;
extern T_routeBasicSetup				g_routerBasicSetupOld;
extern T_routerNeighSetup				g_routerNeighSetupOld;
extern T_routerHandoverSetup			g_routerHandoverSetupOld;
extern T_routerMscSetup					g_routerMscSetupOld;
extern T_sysBasicSetup					g_sysBasicSetupOld;
extern T_sysIpSetup						g_sysIpSetupOld;
extern T_sysKeeperSetup					g_sysKeeperSetupOld;
extern T_sysSwServerSetup				g_sysSwServerSetupOld;
extern	T_sysLogSetup				g_sysLogSetupOld;
extern	T_sysSntpSetup				g_sysSntpSetupOld;
extern	T_sysPPPoESetup				g_sysPPPoESetupOld;
extern T_sysSnmpSetup					g_sysSnmpSetupOld;
extern T_radiusSerCfg					g_sysRadiusSerSetupOld;
extern T_sysVersionSetup                g_sysVersionSetupOld;
extern T_sysPasswordChange				g_sysPasswordChangeOld;
extern T_wifiDeviceTable				g_wifiDeviceTableOld;
extern T_wifiDeviceList					g_wifiDeviceListOld;
extern T_apVapTableRw					g_apVapTableRwOld;
extern T_adhocVapTableRw				g_adhocVapTableRwOld;
extern T_adhocVapList					g_adhocVapListOld;
extern T_capWapSetup					g_stCapWapSetupOld;
extern T_enetInfTable					g_enetInfTableOld;
extern T_vlanSwitch						g_vlanSwitchOld;
extern T_vlanSetupList					g_vlanSetupListOld;
extern T_sysPeriodOfValidity			g_sysPeriodOfValidityOld;
extern OMA_STA_VAP_TABLE				g_stStaVapTableOld;
extern T_ipForwardSetup					g_stIpForwardSetupOld;
extern T_tcpOptimizationSetup			g_stTcpOptimiSetupOld;
/* added by laiyongxing at 2009-2-27 */
T_aclSetup                              g_tempAclProtocol;
extern T_aclSetupEntry                  g_aclSetup;
extern T_aclSetupEntry                  g_aclSetupOld;
extern T_sysLoadBalanceSetup			g_stLoadBalanceSetupOld;

extern int								my_device_type;
extern int								wifi_module_num;
extern T_deviceSign						g_deviceSign;
extern T_deviceSign						g_deviceSignOld;
extern AC_DB_FIELD_BUFF_T				*gpstDbFieldBuff;
extern LOG_ENTRY_T						g_stLogEntry;
extern int g_curMesh;
extern T_registerSetup					g_stRegisterSetup;

extern int g_slaveInitFlag;
extern int g_connectTest;

extern char g_acWifiState[4];
extern int wifi_module_num;
extern int wifi0_state;	/* 用来判断WIFI0是否插入 */
extern int wifi1_state;	/* 用来判断WIFI1是否插入 */
extern int wifi2_state;	/* 用来判断WIFI2是否插入 */
extern int wifi3_state;	/* 用来判断WIFI3是否插入 */

extern int g_acOpState;		/* 与AC的链路状态 */
extern int g_acOpStateOld;	/* 与AC的链路状态 */
extern int g_slaveGwState;	/* 从设备的GW状态 */

extern OMA_MS_CONNECT_MSG_T			g_msConnectMsg;
extern unsigned long				g_curKeeperState;

extern int g_isSetAll;

/* hc add for dhcp realloc 2009-6-26 */
extern int g_acId;			/* AC的Id */
extern int g_acIdOld;		/* AC的Id */
extern CPU_MEM_SAMPLE_T g_stCpuMemSample;
/* add by yzl 2008-12-04 */
extern MESH_ETH_VLAN_MAP_T				g_vlanMapSetup;
extern ROAM_STAT_T						g_stRoamStat;
extern RELAY_CLIENT_ENTRY_T				g_stRelayClientEntry;
extern MESH_ETH_VLAN_MAP_T				g_vlanMapSetupOld;
extern unsigned long					g_ifDevTrapStartMsg2Omc;

extern unsigned long					g_dhcpState;

#define doSetFlag_INIT					0x55555555
#define doSetFlag_RESET					0x66666666
#define doSetFlag_OMC					0x77777777
#define doSetFlag_WIFIDEVICE			0x33333333

#define doSaveTlv_timer                 0x55555555
#define doSaveTlv_reboot                0x66666666

#define doSlaveFlag_INIT				0x44444444

int isConfigDataValid(void);
int agent_data_init ( void );
int agent_data_reset( void );
int slave_agent_data_init( void );
//int save_tlv_cf_data(int);
int save_device_info(void);
T_deviceModel *getDeviceModel(int iDeviceType);

int do_aclPolicySwitch_set( int );
int make_fcl_setup(void);
int do_fclBasicSetup_set (int);
int do_ipForwardPolicy_set( int flag );
int do_tcpOptimiSetup_set( int flag );
int do_routerNetSetup_set( int );
int do_routerBasicSetup_set( int );
int do_routerNeighSetup_set( int );
int do_routerDynamicSetup_set( int );
int do_routerHandoverSetup_set( int );
int do_routerMobileSetup_set( int );
int do_routerMscSetup_set( int );
int do_aodvNeighborList_get( AODV_NEIGHBOR_LIST_T *pstData );
int do_NodeInfo_get(AODV_NODEINFO_T *p_stNodeInfo);
int do_aodvRouteList_get( void );
int do_apVapAdd_set( int );
int do_apVapDelete_set( int );
int do_apMacFilterStat_get( unsigned long apId );
int do_apEndUserList_get( unsigned long apId, T_apEndUserList *pstEndUserList);
int do_apAccessDenyList_get( unsigned long apId );
int do_apBasicSetup_set( unsigned long apId, T_apBasicSetup *, int );
int do_apSecuritySetup_set( unsigned long apId, T_apSecuritySetup *, int );
int do_apAdvancedSetup_set( unsigned long apId, T_apAdvancedSetup *, int );
int do_apMacFilterSetup_set( unsigned long apId, T_apMacFilterSetup *, int );
int do_adhocVapAdd_set( int );
int do_adhocVapDelete_set( int );
int do_adhocBasicSetup_set( unsigned long adhocId, T_adhocBasicSetup *, int );
int do_adhocSecuritySetup_set( unsigned long adhocId, T_adhocSecuritySetup *, int );
int do_adhocNeighborList_get( unsigned long ulAdhocId );
int do_adhocSnrList_get( void );
int do_adhocVapList_get( void );
int do_wifiDeviceValidWifiList_get( void );
int do_apValidWifiDeviceList_get( void );
int do_adhocValidWifiDeviceList_get( void );
int do_sysModifyDeviceID( int );
int do_sysBasicSetup_set( int );
int do_sysBasicSetup_get( void );
int do_sysDownloadConfig_set( int );
int do_sysDownloadLog_set( int );
int do_sysIpSetup_set( int );
int do_sysKeeperSetup_set( int );
int do_sysLoadBalanceSetup_set( int);
int do_sysServerSetup_set( int );
int do_sysLogSetup_set( int );
int do_sysSntpSetup_set( int );
int do_sysPPPoESetup_set( int );
int do_sysSnmpSetup_set( int );
int do_sysParaSetup_set(T_sysParaSetup *data, int len);
int do_sysVersionSetup_set( int );
int do_sysPasswordChange_set( int );
int do_sysPingSummary_get( void );
int do_sysPingTest_set( int );
int do_sysReboot_set( int );
int do_sysResetConfig_set( int );
int do_sysSetRtc_set( int );
int do_sysUpdateImage_set( int );
int do_sysUpdateRamdisk_set( int );
int do_sysUpdateVersionProgress_get( void );
int do_sysUploadConfig_set( int, char* );
int do_sysPeriodOfValidity_set( int );
int radio_workmode_reset_all();
int do_wifiDeviceAdd_set( int );
int do_wifiDeviceDelete_set( int );
int do_wifiDeviceBasicSetup_set( unsigned long wifiDeviceId, T_wifiDeviceBasicSetup *, int );
int do_wifiDeviceChanSetup_set( unsigned long wifiDeviceId, T_wifiDeviceChanSetup *, int );
int do_wifiDeviceRateSetup_set( unsigned long wifiDeviceId, T_wifiDeviceRateSetup *, int );
int do_wifiDevicePowerSetup_set( unsigned long wifiDeviceId, T_wifiDevicePowerSetup *, int );
int do_wifiDeviceAdvancedSetup_set( unsigned long wifiDeviceId, T_wifiDeviceAdvancedSetup *, int );
/* hc modified for telecom test 2009-7-6 */
int do_wifiDeviceWidsSetup_set( unsigned long wifiDeviceId, WIDS_CONFIG_T *, int );
int do_wifiDeviceResSetup_set( unsigned long wifiDeviceId, T_wifiDeviceResourceSetup *pstWifiRes, int flag );
int do_wifiDeviceList_get( void );
int do_apVapAdd_set( int );
int do_apVapDelete_set( int );

int do_apMacFilterSetup_set( unsigned long apId, T_apMacFilterSetup *, int );
int do_adhocVapAdd_set( int );
int do_adhocVapDelete_set( int );
int do_adhocBasicSetup_set( unsigned long adhocId, T_adhocBasicSetup *, int );
int do_adhocSecuritySetup_set( unsigned long adhocId, T_adhocSecuritySetup *, int );
int do_adhocNeighborList_get( unsigned long ulAdhocId );
int do_adhocSnrList_get( void );
int do_adhocVapList_get( void );
int do_enetInfBasicSetup_set( unsigned long ulEnetIndex, T_enetInfBasicSetup *, int );
int do_vlanAdd_set( int );
int do_vlanDelete_set( int );
int do_vlanModify_set( int );
int do_vlanSwitch_set( int );
int do_vlanMapSetup_set(int);
int do_sysAppendCode_set( int );
int do_gatewayMonitor( int );
int save_maintennance_enregister_data( void );

/**
int do_sysUpdateLogo_set( int flag );
int do_sysUpdateTitle_set(int flag);
int do_update_device_info_set(int flag);
int do_oem_switch_set(int flag);
*/

void make_default_setup( void );
int save_config_data( void );
int save_configTemp_data( void );
int make_period_setup( void );
void get_adhoc_mac(int);
void synSysTimeFromRtc(void);
void make_sysAppendCode_setup(void);
int save_mscfg_info(void);
void get_sys_version(void);
int do_sys_log_get(void);
int do_sysRadiusSerSetup(int flag);

void disableApConnect( void );
void disableEnetConnect( void );
void enableConnect( void );
void disableGWAdhocConnect( void );
void disable_gw(void);
void enable_gw(void);
int vap_mapped( int iApId, char *p_apDevName, int iFlag );
int do_capwap_set(int);
int do_perf_cfg_set(int, OMA_PERF_CFG_T *);
void slave_mac_get(int);
void slave_wifi_txpower_get(void);

void omcTest( void );

void decimal2binary( int iValue, int iBinary[] );

int main_monitor( void );
int slave_monitor( void );
int connect_create( void );
//void check_slave_data( void );
//int slave_dis_port_set(void);
//int slave_en_port_set(void);
void slave_connect_state_set(int);

int agent_data_get (void * name,
					unsigned int name_len,
					unsigned char val_type,
					unsigned int val_len,
					void * data,
					int flag);

int agent_data_set (void * name,
					unsigned int name_len,
					unsigned char val_type,
					unsigned int val_len,
					void * data,
					int flag);

int is_ap_type_module(int deviceType);
int GetFileLength(char * fileName);
void ReplaceString(char * source, char *S_str, char * D_str) ;
int read_to_buff(char * fileName, char * buff, int fileLen);


void get_sys_info(SYS_INFO_T *);

/***************** sta *****************/
int do_staAdd_set(int);
int do_staBasicSetup_set(int, int);
int do_staAdvancedSetup_set(int, int);
int do_staSecuritySetup_set(int, int);
int do_staBssidBind_set(int, int);
int do_staBssidBind_get(void);
int do_staChanScan_set(int, int);
int do_staChanScan_get(void);
int do_staAgentClient_get(void);
int do_staHistoryInfo_get(void);
int do_staScan_get(STA_SCAN_INFO_T *);
int do_staScanRestat_set(void);
void get_sta_mac(int);

/**************业务****************/
int acl_filterpolicy_set(unsigned long, unsigned long);
int addProtocol(void);
int deleteProtocol(unsigned long index);
int modifyProtocol(void);
int moveProtocol(unsigned long , unsigned long );
int make_acl_setup(void);

int do_registerSetup_set(void);

int generate_ip_address(char *ipStr, unsigned char ipAry[4]);

int do_sys_oem_management(int);
void auto_update_ver(void);

int do_alarm_filter_cfg_set(int flag, OMA_ALARM_FILTER_CFG_T *pstCfg);
int do_alarm_threshold_cfg_set(int flag, OMA_ALARM_THRESHOLD_CFG_T *pstCfg);
int do_ClearAttackHistory_set(void);
int do_ClearAttackStat_set(void);
int do_ClearIlegalDevHistory_set(void);

/* 2011-12-12 by zsy: 查找VAP在哪个桥下 */
void findVapMesh(char *meshName,  int wifiId, int apId);


#endif /* #ifndef AGENTDATA_H */

