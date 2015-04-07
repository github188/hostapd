#ifndef IF_OMC_H
#define IF_OMC_H

#include "../agent_type.h"

typedef struct
{
/* hc modified for telecom test 2009-8-19 */
    unsigned long	   apVapId;
	char               acApSsid[32];
	unsigned long      ulValidNum;
	T_apEndUser        astApEndUser[MAX_ENDUSER_ENTRY_I];
} OMC_AP_END_USER_LIST;

typedef struct apVapEndUserEntry_s 
{
	unsigned long	ulValidApNum;
	OMC_AP_END_USER_LIST astApEndUserList[apVapTable_SIZE];
} OMC_AP_END_USER_ENTRY;

typedef struct{
	unsigned long	   apVapId;
	T_apEndUser     astApEndUser;
}OMC_AP_STATION_T;

typedef struct{
	unsigned long      ulValidNum;
	OMC_AP_STATION_T astApEndUser[MAX_ENDUSER_ENTRY_I];
}OMC_AP_STATION_LIST_T;

typedef struct{
	unsigned long	   apVapId;
	T_apEndUserSimple     astApEndUser;
}OMC_AP_STATION_SIMPLE_T;

typedef struct{
	unsigned long      ulValidNum;
	OMC_AP_STATION_SIMPLE_T astApEndUser[MAX_ENDUSER_ENTRY_I];
}OMC_AP_STATION_SIMPLE_LIST_T;

/* 最终用户统计 */
typedef struct 
{
	unsigned long	ulUserNum;			/* 用户数 */
	unsigned long	ulRecvPkt;			/* 接收包数 */
	unsigned long	ulRecvRetryPkt;		/* 接收重传包数 */
	unsigned long	ulSendPkt;			/* 发送包数 */
	unsigned long	ulSendLossPkt;		/* 发送丢包数 */
} OMC_AP_END_USER_STAT_T;

/* 回传链路统计 */
typedef struct  
{
	unsigned long	ulValidFlag;		/* 有效标志 */
#define INVALID_FLAG	0
#define VALID_FLAG		1
	unsigned long	ulBusinessLossPkt;	/* 业务丢包数 */
	unsigned long	ulBusinessRecvPkt;	/* 业务收包数 */
	unsigned long	ulBusinessSendPkt;	/* 业务发包数 */
	unsigned long	ulBroadcastRecvPkt;	/* 广播收包数 */
	unsigned long	ulBroadcastSendPkt;	/* 广播发包数 */
	unsigned long	ulRssi;				/* RSSI */
	long			lNoiseFloor;		/* 底噪 */
	unsigned long	ulChannel;			/* 工作信道 */
	unsigned long	ulWifiModuleId;		/* 模块号 */
	unsigned long	ulResvUCast;		/* 所有天线接收的单播包的数目 */
	unsigned long	ulSendUCast; 		/* 所有天线发送的单播包的数目 */
	char			acPeerMac[6];		/* 对端MAC */
	unsigned long	ulRateRecvPkt;		/* 速率的总收包数 */
	unsigned long	ulRateSendPkt;		/* 速率的总发包数 */
	unsigned long	ulPowerSendPkt;		/* 功率上的发送包数 */
	unsigned long	ulRssiRecvPkt;		/* RSSI的接收包数 */
	unsigned long	ulSignalLossPkt;	/* 信令丢包数 */
	unsigned long	ulSignalRecvPkt;	/* 信令收包数 */
	unsigned long	ulSignalSendPkt;	/* 信令发包数 */
} OMC_ADHOC_LINK_STAT_T;

typedef struct
{
    UINT32                  ulVapId;	        /* VAPID */
    UINT32                  ulRxucNum;          /* 接收点播包数目 */
    UINT32                  ulRxmcNum;          /* 接收广播包数目 */
    UINT32                  ulTxucNum;          /* 发送点播包数目 */
    UINT32                  ulTxmcNum;          /* 发送广播包数目 */
    UINT32                  ulTxAirLostNum;     /* 空口丢包数 */
    UINT32                  ulTxActLostNum;     /* 主动丢包数 */
    UINT32                  ulTxReNum;          /* 重传次数，只点播报文重传 */
    UINT32                  ulUserNum;          /* AP：即时接入用户个数 */
    INT32                   iNoise;             /* 底噪 */
}OMC_VAP_STATS_T;

typedef struct
{
	UINT32                  ulValidNum;
	OMC_VAP_STATS_T 	    astVapStats[apVapTable_SIZE];
} OMC_VAP_STATS_ENTRY_T;

typedef struct
{
    UINT32                  ulVapId;	        /* VAPID */
    UINT32                  ulRxucNum;          /* 接收点播包数目 */
    UINT32                  ulRxmcNum;          /* 接收广播包数目 */
    UINT32                  ulTxucNum;          /* 发送点播包数目 */
    UINT32                  ulTxmcNum;          /* 发送广播包数目 */
    UINT32                  ulTxAirLostNum;     /* 空口丢包数 */
    UINT32                  ulTxActLostNum;     /* 主动丢包数 */
    UINT32                  ulTxReNum;          /* 重传次数，只点播报文重传 */
    UINT32                  ulNeiNum;           /* ADHOC：即时邻居个数 */
    INT32                   iNoise;             /* 底噪 */
}OMC_ADHOC_STATS_T ;

typedef struct
{
	UINT32                  ulValidNum;
	OMC_ADHOC_STATS_T 	    astAdhocStats[adhocVapTable_SIZE];
} OMC_ADHOC_STATS_ENTRY_T;


/* 流量统计 */
typedef struct  
{
    unsigned long ulVlanId;                         
    unsigned long ulDownlinkDataFlow;       /* 下行业务流量 */
    unsigned long ulUplinkDataFlow;         /* 上行业务流量 */
    unsigned long ulDownlinkMngFlow;        /* 下行管理流量 */
    unsigned long ulUplinkMngFlow;          /* 上行管理流量 */
    unsigned long ulDownlinkFwdFlow;        /* 下行转发流量 */
    unsigned long ulUplinkFwdFlow;          /* 上行转发流量 */

} OMC_FLOW_STAT_T;

typedef struct
{
	unsigned char   acDeviceId[6];			    /* 设备ID */
	unsigned char   acGwDeviceId[6];			/* 网关的设备ID */
    //unsigned long ulMeshGwFlag;                    /* if it is a MESH GW */

    //OMC_FLOW_STAT_T	stTotalFlowStat;

    unsigned long 	ulValidNum;
	OMC_FLOW_STAT_T	astFlowStat[vlanSetupList_SIZE];

} OMC_FLOW_STAT_ENTRY_T;

typedef struct
{
	unsigned char   acDeviceId[6];			    /* 设备ID */
	unsigned char   acGwDeviceId[6];			/* 网关的设备ID */

    unsigned long   ulDownlinkDataFlow;       /* 下行业务流量 */
    unsigned long   ulUplinkDataFlow;         /* 上行业务流量 */
    unsigned long   ulDownlinkFwdFlow;        /* 下行转发流量 */
    unsigned long   ulUplinkFwdFlow;          /* 上行转发流量 */
} OMC_NODE_INFO_T;

/* 获取AODV邻居列表 */
#define AODVNEIGHBORLIST_SIZE   16 //AODV_NEIGHBORLIST_SIZE
typedef struct 
{
	unsigned char aucAodvNeighDeviceId[6];			/* 邻居设备ID */
	unsigned char aucAodvNeighMac[6];				/* 邻居MAC */
	unsigned char aucAodvNeighIp[4];				/* 邻居的管理IP */
	unsigned long ulAodvLocalCost;					/* 本端质量cost值*/
	unsigned long ulAodvPeerCost;					/* 对端质量cost值*/	
	unsigned long ulAodvNeighStatus;				/* 邻居属性*/
#define AODVNEIGHSTATUS_FATHER			1			/* 父节点*/
#define AODVNEIGHSTATUS_SON				2			/* 子节点*/
#define AODVNEIGHSTATUS_OTHER			0			/* 其它关系*/
	unsigned long ulAodvNeighGwStatus;				/* GW属性*/
#define AODVNEIGHGW_SON                 1           /* I am the gw of the neigh */
#define AODVNEIGHGW_MY_GW               2			/* 是本节点所属的GW*/
#define AODVNEIGHGW_OTHER_GW            3			/* 非本节点所属的GW */
#define AODVNEIGHGW_OTHER               0           /* 不是GW*/
	unsigned long ulAodvNeighHelloLoss;				/* HELLO丢失数*/
	unsigned long ulAodvNeighSendPkt;				/* 针对本节点的发送包数*/
	unsigned long ulAodvNeighRecvPkt;				/* 针对本节点的接收包数*/
	unsigned long ulAodvNeighWifiDeviceId;			/* 邻居所属无线设备ID */
	unsigned long ulAodvNeighWifiModuleId;			/* 邻居所属无线模块ID */
	unsigned long ulNeighborChannel;				/* 工作信道 */
} OMC_AODV_NEIGHBOR_T;

typedef struct
{
	unsigned long 	ulValidNum;
	OMC_AODV_NEIGHBOR_T	astAodvNeighborEntty[AODVNEIGHBORLIST_SIZE];
} OMC_AODV_NEIGHBOR_ENTRY_T;

typedef MESH_ROUTE_PATH_END_INFO_ENTRY OMC_MESH_ROUTE_PATH_ENTRY_T;

/* 拓扑图结构信息 */
typedef struct  
{
	OMC_NODE_INFO_T		        stNodeInfo;
	OMC_AODV_NEIGHBOR_ENTRY_T	stAodvNeighbor;
	OMC_MESH_ROUTE_PATH_ENTRY_T	stRoutePathEntry;
	OMC_AP_END_USER_ENTRY       stApEndUserEntry;
} OMC_TOPO_INFO_T;

typedef EVENT_TRAP_MSG_LIST_T OMC_EVENT_TRAP_MSG_LIST_T;

typedef struct
{
	unsigned long   ulEventId;
	unsigned long   ulObjectType;
	const char		*pcObjectName;
	unsigned long   ulObjectId;
	unsigned long   ulEventStatus;
	unsigned long   ulEventReasonId;
	unsigned long   ulEventLevel;
} T_omcEventMsgList;

typedef struct 
{
	unsigned char aucSsid[32];                /* SSID */
	unsigned char aucBssid[6];				  /* BSSID */
	unsigned char aucRsv[2];
	unsigned long ulChannel;                  /* 信道 */
	unsigned long ulRate;                     /* 速率 */
	unsigned long ulRssi;                     /* 连接质量 */
	int			  iSignal;                    /* 信号强度 */
	int			  iNoise;                     /* 底噪。有符号数 */
	unsigned long ulVapMode;                  /* VAP类型 */
#define VAP_MODE_AP    0                      /* AP */
#define VAP_MODE_ADHOC 1                      /* ADHOC */
	unsigned long ulBeacons;				  /* beacons个数 */
	unsigned long ulLifetime;                 /* 统计Beacon时间，单位s */
	unsigned long ulRelatedState;			  /* 是否与该VAP关联：界面上不显示该字段。界面上应该能看出该STA关联在哪个VAP上 */
#define RELATED_STATE_NO_LINK	0			  /* 未关联 */
#define RELATED_STATE_LINK		1			  /* 已关联 */
} OMA_SCAN_INFO;

#define SCAN_LIST_MAX_SIZE  100
typedef struct 
{
	unsigned long ulValidNum;					/* 有效个数 */
	OMA_SCAN_INFO stScanInfo[SCAN_LIST_MAX_SIZE];
} OMA_SCAN_ENTRY;

/* 终端关联VAP信息 */
typedef struct
{
	unsigned long		ulStaId;
	OMA_STA_ASSOCIATE_T stStaAssociate;
} OMC_STA_ASSOCIATE_LIST;

typedef struct  
{
	unsigned long	ulValidStaNum;
	OMC_STA_ASSOCIATE_LIST astStaAssociateList[STA_VAP_TABLE_SIZE];
} OMC_STA_ASSOCIATE_ENTRY;

/* 终端拓扑信息 */
typedef struct  
{
	ROAM_STAT_T				stRoamStat;
	OMA_SCAN_ENTRY			stScanEntry;
	OMC_STA_ASSOCIATE_ENTRY	stAssocEntry;
} OMC_STA_TOPO_INFO_T;

/* 终端和IP维护表 */
typedef struct
{
	unsigned char stMac[6];
	unsigned char stAddrIp[4];
#define OMC_ALTER_MACIP	  	1 	/* 对列表做修改操作 */
#define OMC_DEL_STA_MACIP 	2 	/* 对列表做删除操作 */
#define OMC_FIND_STA_MACIP  3   /* 对列表查找操作   */
} OMC_STA_MAC_IP_LIST;

int omc_end_user_list_get( OMC_AP_END_USER_ENTRY * p_endUserEntry );
//int omc_end_user_info_get( OMC_AP_END_USER_STAT_T * p_endUserInfo );
int omc_adhoc_link_info_get( OMC_ADHOC_LINK_STAT_T * p_adhocLinkInfo );
int omc_vap_stat_get(OMC_VAP_STATS_ENTRY_T *pstStat);
int omc_adhoc_stat_get(OMC_ADHOC_STATS_ENTRY_T *pstStat);
int omc_aodv_neighbor_list_get( OMC_AODV_NEIGHBOR_ENTRY_T * p_aodvNeighborInfo );
int omc_aodv_route_path_list_get( OMC_MESH_ROUTE_PATH_ENTRY_T * p_pathInfo );
int omc_flow_stat_get( OMC_FLOW_STAT_ENTRY_T * p_nodeInfo );
int omc_topo_info_get( OMC_TOPO_INFO_T * p_topoInfo );
int omc_rogue_info_get(ROGUE_AP_INFO_T *p_rogueApInfo );
int omc_event_list_get(unsigned long maxEventNum, OMC_EVENT_TRAP_MSG_LIST_T * p_eventTrapMsgInfo);
int omc_scan_list_get(OMA_SCAN_ENTRY * p_stScanEntry);
int omc_sta_topo_info_get( OMC_STA_TOPO_INFO_T * p_topoInfo );
int omc_sta_associate_get(OMC_STA_ASSOCIATE_ENTRY * p_stStaAssocEntry);
int omc_global_info_get(OMA_GLOBAL_STAT_ENTRY * p_stGlobalInfo);
int omc_air_stats_info_get(OMA_AIR_STATS_ENTRY * p_stAirStatsInfo);
int omc_mgt_stats_info_get(OMA_MGT_STAT_ENTRY *p_stMgtStatsInfo);
int omc_adhoc_link_stats_info_get(OMC_ADHOC_LINK_STATS * p_stAdhocLinkStatsInfo);
/* hc modified for telecom test 2009-7-6 */
int omc_AssocSta_info_get(OMA_ASSOC_STA_STAT_ENTRY * p_stAssocStalInfo);
int omc_rogue_sta_list_get(ROGUE_STA_LIST_T *p_rogueStaInfo );

/* 2010-08-26 fengjing 增加 */
int omc_neighbor_ap_list_get(OMA_NEIGHBOR_AP_ENTRY *pstNeighborAp);

int omc_userMacIp_handle(char * macAddr, char * ipAddr, int cmd);

#endif
