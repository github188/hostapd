#ifndef AGENT_CGI_H
#define AGENT_CGI_H

#define sysBasicSetup_OID  	                  "sysBasicSetup"
#define sysIpSetup_OID  	                  "sysIpSetup"
#define sysKeeperSetup_OID  	              "sysKeeperSetup"
#define sysServerSetup_OID  	              "sysServerSetup"
#define sysSnmpSetup_OID  	                  "sysSnmpSetup"
#define sysRadiusSetup_OID  	              "sysRadiusSetup"
#define sysCapWapSetup_OID  	              "sysCapWapSetup"
#define sysPasswordChange_OID  	              "sysPasswordChange"
#define sysSetRtc_OID  	                      "sysSetRtc"
#define sysReboot_OID  	                      "sysReboot"
#define sysResetConfig_OID  	              "sysResetConfig"
#define sysPingTest_OID  	                  "sysPingTest"
#define sysPingSummary_OID  	              "sysPingSummary"
#define sysDownloadLog_OID  	              "sysDownloadLog"
#define sysUpdateImage_OID  	              "sysUpdateImage"
#define sysUpdateRamdisk_OID  	              "sysUpdateRamdisk"
#define sysDownloadConfig_OID  	              "sysDownloadConfig"
#define sysUploadConfig_OID  	              "sysUploadConfig"
#define sysPeriodOfValidity_OID  	          "sysPeriodOfValidity"
#define sysAppendCode_OID  					  "sysAppendCode"
#define sysModifyDeviceID_OID  				  "sysModifyDeviceID"
#define sysMaintEnregister_OID  			  "sysMaintEnregister"
#define sysInfoGet_OID  					  "sysInfoGet"
#define sysUpdateVersionProgress_OID  	      "sysUpdateVersionProgress"
#define sysLogGet_OID  						  "sysLogGet"
#define registerSetup_OID  					  "registerSetup"
#define sysDownloadSnap_OID                   "sysDownloadSnap"
#define sysModifyOemInfo_OID                  "sysModifyOemInfo"
#define wifiDeviceAdd_OID  	                  "wifiDeviceAdd"
#define wifiDeviceDelete_OID  	              "wifiDeviceDelete"
#define wifiDevice0BasicSetup_OID  	          "wifiDevice0BasicSetup"
#define wifiDevice0AdvancedSetup_OID  	      "wifiDevice0AdvancedSetup"
#define wifiDevice0ChanSetup_OID  			  "wifiDevice0ChanSetup"
#define wifiDevice0RateSetup_OID  			  "wifiDevice0RateSetup"
#define wifiDevice0PowerSetup_OID  			  "wifiDevice0PowerSetup"
#define wifiDevice1BasicSetup_OID  	          "wifiDevice1BasicSetup"
#define wifiDevice1AdvancedSetup_OID  	      "wifiDevice1AdvancedSetup"
#define wifiDevice1ChanSetup_OID  			  "wifiDevice1ChanSetup"
#define wifiDevice1RateSetup_OID  			  "wifiDevice1RateSetup"
#define wifiDevice1PowerSetup_OID  			  "wifiDevice1PowerSetup"
#define wifiDevice2BasicSetup_OID  	          "wifiDevice2BasicSetup"
#define wifiDevice2AdvancedSetup_OID  	      "wifiDevice2AdvancedSetup"
#define wifiDevice2ChanSetup_OID  			  "wifiDevice2ChanSetup"
#define wifiDevice2RateSetup_OID  			  "wifiDevice2RateSetup"
#define wifiDevice2PowerSetup_OID  			  "wifiDevice2PowerSetup"
#define wifiDevice3BasicSetup_OID  	          "wifiDevice3BasicSetup"
#define wifiDevice3AdvancedSetup_OID  	      "wifiDevice3AdvancedSetup"
#define wifiDevice3ChanSetup_OID  			  "wifiDevice3ChanSetup"
#define wifiDevice3RateSetup_OID  			  "wifiDevice3RateSetup"
#define wifiDevice3PowerSetup_OID  			  "wifiDevice3PowerSetup"
#define wifiDeviceSetupList_OID  	          "wifiDeviceSetupList"
#define wifiDeviceValidWifiList_OID  		  "wifiDeviceValidWifiList"
#define apVapAdd_OID  	                      "apVapAdd"
#define apVapDelete_OID  	                  "apVapDelete"
#define apVapIndex_OID  	                  "apVapIndex"
#define apBasicSetup_OID  	                  "apBasicSetup"
#define apSecuritySetup_OID  	              "apSecuritySetup"
#define apMacFilterSetup_OID  	              "apMacFilterSetup"
#define apMacFilterStat_OID  	              "apMacFilterStat"
#define apEndUserList_OID  	                  "apEndUserList"
#define apAccessDenyList_OID  	              "apAccessDenyList"
#define apAdvancedSetup_OID  	              "apAdvancedSetup"
#define apVapValidWifiDeviceList_OID  	      "apVapValidWifiDeviceList"
#define adhocAdd_OID  						  "adhocAdd"
#define adhocDelete_OID  					  "adhocDelete"
#define adhoc0BasicSetup_OID  				  "adhoc0BasicSetup"
#define adhoc0SecuritySetup_OID  			  "adhoc0SecuritySetup"
#define adhoc0NeighborList_OID  			  "adhoc0NeighborList"
#define adhoc1BasicSetup_OID  				  "adhoc1BasicSetup"
#define adhoc1SecuritySetup_OID  			  "adhoc1SecuritySetup"
#define adhoc1NeighborList_OID  			  "adhoc1NeighborList"
#define adhoc2BasicSetup_OID  				  "adhoc2BasicSetup"
#define adhoc2SecuritySetup_OID  			  "adhoc2SecuritySetup"
#define adhoc2NeighborList_OID  			  "adhoc2NeighborList"
#define adhoc3BasicSetup_OID  				  "adhoc3BasicSetup"
#define adhoc3SecuritySetup_OID  			  "adhoc3SecuritySetup"
#define adhoc3NeighborList_OID  			  "adhoc3NeighborList"
#define adhocSetupList_OID  	              "adhocSetupList"
#define adhocVapValidWifiDeviceList_OID  	  "adhocVapValidWifiDeviceList"
#define routeNodeSetup_OID  				  "routeNodeSetup"
#define routeNeighborSetup_OID  	          "routeNeighborSetup"
#define routeHandoverSetup_OID  	          "routeHandoverSetup"
#define routeDeviceMscSetup_OID  	          "routeDeviceMscSetup"
#define routeAodvNeighborList_OID  	          "routeAodvNeighborList"
#define routeAodvRouteList_OID  	          "routeAodvRouteList"
#define routeNodeInfo_OID  					  "routeNodeInfo"
#define routeFclSetup_OID  	                  "routeFclSetup"

#define enet0BasicSetup_OID  	              "enet0BasicSetup"
#define enet1BasicSetup_OID  	              "enet1BasicSetup"
#define vlanAdd_OID  	                      "vlanAdd"
#define vlanDelete_OID  	                  "vlanDelete"
#define vlanModify_OID  	                  "vlanModify"
#define vlanSetupList_OID  	                  "vlanSetupList"
#define vlanMapSetup_OID  					  "vlanMapSetup"
#define staBasicSetup_OID  					  "staBasicSetup"
#define staAdvanceSetup_OID  				  "staAdvanceSetup"
#define staSecuritySetup_OID  				  "staSecuritySetup"
#define staBindSsidSetup_OID  				  "staBindSsidSetup"
#define staChanScanSetup_OID  				  "staChanScanSetup"
#define staHistoryInfo_OID  				  "staHistoryInfo"
#define staAgentClientInfo_OID  			  "staAgentClientInfo"
#define staScanInfo_OID  					  "staScanInfo"
#define staScanInterval_OID  				  "staScanInterval"
#define staHisGetInterval_OID  				  "staHisGetInterval"
#define staScanRestat_OID  				      "staScanRestat"

#define aclSetupAdd_OID                       "aclSetupAdd"
#define aclSetupModify_OID                    "aclSetupModify"
#define aclSetupMove_OID                      "aclSetupMove"
#define aclSetupDelete_OID                    "aclSetupDelete"
#define aclSetupGet_OID                       "aclSetupGet"
#define aclSetupConfig_OID                    "aclSetupConfig"
#define aclSetupSwitchPolicy_OID              "aclSetupSwitchPolicy"

#define ipForwardSwitch_OID  	              "ipForwardSwitch"
#define tcpOptimiSetup_OID  				  "tcpOptimiSetup"

#define AGENT_CGI_PORT          10601

#define SOCKET                  int
#define SOCKADDR                struct sockaddr
#define SOCKADDR_IN             struct sockaddr_in

#define INVALID_SOCKET          (SOCKET)(~0)
#define SOCKET_ERROR            (-1)
#define closesocket             close

#define CGI_MSGTYPE_GET         1
#define CGI_MSGTYPE_SET         2
#define CGI_MAX_OID_SIZE        128
#define CGI_MAX_MSG_SIZE        (63*1024)

typedef struct
{
    unsigned long   ulMsgType;
    unsigned long   ulSn;
}CGI_MSG_HEAD_T;

#define MAX_CGI_OPER_LEN    64
typedef struct
{
    CGI_MSG_HEAD_T  stHead;

    char            acOper[MAX_CGI_OPER_LEN];
}CGI_MSG_GET_REQ_T;

typedef struct
{
    CGI_MSG_HEAD_T  stHead;

    unsigned long   ulRetCode;

    unsigned long   ulMsgLen;
    unsigned char   aucMsg[CGI_MAX_MSG_SIZE];
}CGI_MSG_GET_ACK_T;

typedef struct
{
    CGI_MSG_HEAD_T  stHead;

    char            acOper[MAX_CGI_OPER_LEN];

    unsigned long   ulMsgLen;
    unsigned char   aucMsg[CGI_MAX_MSG_SIZE];
}CGI_MSG_SET_REQ_T;

typedef struct
{
    CGI_MSG_HEAD_T  stHead;

    unsigned long   ulRetCode;
}CGI_MSG_SET_ACK_T;

typedef void *(*CGI_GET_FUNC)(unsigned long ulReq, unsigned long *pulLen);
typedef struct
{
    char            *szOper;
    CGI_GET_FUNC    pFunc;
    void            *pData;
    unsigned long   ulLen;
}CGI_GET_OPER_T;

typedef int (*CGI_SET_FUNC)(void *pReq, unsigned long ulLen);
typedef struct
{
    char            *szOper;
    CGI_SET_FUNC    pFunc;
}CGI_SET_OPER_T;



#endif

