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

/* �����û�ͳ�� */
typedef struct 
{
	unsigned long	ulUserNum;			/* �û��� */
	unsigned long	ulRecvPkt;			/* ���հ��� */
	unsigned long	ulRecvRetryPkt;		/* �����ش����� */
	unsigned long	ulSendPkt;			/* ���Ͱ��� */
	unsigned long	ulSendLossPkt;		/* ���Ͷ����� */
} OMC_AP_END_USER_STAT_T;

/* �ش���·ͳ�� */
typedef struct  
{
	unsigned long	ulValidFlag;		/* ��Ч��־ */
#define INVALID_FLAG	0
#define VALID_FLAG		1
	unsigned long	ulBusinessLossPkt;	/* ҵ�񶪰��� */
	unsigned long	ulBusinessRecvPkt;	/* ҵ���հ��� */
	unsigned long	ulBusinessSendPkt;	/* ҵ�񷢰��� */
	unsigned long	ulBroadcastRecvPkt;	/* �㲥�հ��� */
	unsigned long	ulBroadcastSendPkt;	/* �㲥������ */
	unsigned long	ulRssi;				/* RSSI */
	long			lNoiseFloor;		/* ���� */
	unsigned long	ulChannel;			/* �����ŵ� */
	unsigned long	ulWifiModuleId;		/* ģ��� */
	unsigned long	ulResvUCast;		/* �������߽��յĵ���������Ŀ */
	unsigned long	ulSendUCast; 		/* �������߷��͵ĵ���������Ŀ */
	char			acPeerMac[6];		/* �Զ�MAC */
	unsigned long	ulRateRecvPkt;		/* ���ʵ����հ��� */
	unsigned long	ulRateSendPkt;		/* ���ʵ��ܷ����� */
	unsigned long	ulPowerSendPkt;		/* �����ϵķ��Ͱ��� */
	unsigned long	ulRssiRecvPkt;		/* RSSI�Ľ��հ��� */
	unsigned long	ulSignalLossPkt;	/* ������� */
	unsigned long	ulSignalRecvPkt;	/* �����հ��� */
	unsigned long	ulSignalSendPkt;	/* ������� */
} OMC_ADHOC_LINK_STAT_T;

typedef struct
{
    UINT32                  ulVapId;	        /* VAPID */
    UINT32                  ulRxucNum;          /* ���յ㲥����Ŀ */
    UINT32                  ulRxmcNum;          /* ���չ㲥����Ŀ */
    UINT32                  ulTxucNum;          /* ���͵㲥����Ŀ */
    UINT32                  ulTxmcNum;          /* ���͹㲥����Ŀ */
    UINT32                  ulTxAirLostNum;     /* �տڶ����� */
    UINT32                  ulTxActLostNum;     /* ���������� */
    UINT32                  ulTxReNum;          /* �ش�������ֻ�㲥�����ش� */
    UINT32                  ulUserNum;          /* AP����ʱ�����û����� */
    INT32                   iNoise;             /* ���� */
}OMC_VAP_STATS_T;

typedef struct
{
	UINT32                  ulValidNum;
	OMC_VAP_STATS_T 	    astVapStats[apVapTable_SIZE];
} OMC_VAP_STATS_ENTRY_T;

typedef struct
{
    UINT32                  ulVapId;	        /* VAPID */
    UINT32                  ulRxucNum;          /* ���յ㲥����Ŀ */
    UINT32                  ulRxmcNum;          /* ���չ㲥����Ŀ */
    UINT32                  ulTxucNum;          /* ���͵㲥����Ŀ */
    UINT32                  ulTxmcNum;          /* ���͹㲥����Ŀ */
    UINT32                  ulTxAirLostNum;     /* �տڶ����� */
    UINT32                  ulTxActLostNum;     /* ���������� */
    UINT32                  ulTxReNum;          /* �ش�������ֻ�㲥�����ش� */
    UINT32                  ulNeiNum;           /* ADHOC����ʱ�ھӸ��� */
    INT32                   iNoise;             /* ���� */
}OMC_ADHOC_STATS_T ;

typedef struct
{
	UINT32                  ulValidNum;
	OMC_ADHOC_STATS_T 	    astAdhocStats[adhocVapTable_SIZE];
} OMC_ADHOC_STATS_ENTRY_T;


/* ����ͳ�� */
typedef struct  
{
    unsigned long ulVlanId;                         
    unsigned long ulDownlinkDataFlow;       /* ����ҵ������ */
    unsigned long ulUplinkDataFlow;         /* ����ҵ������ */
    unsigned long ulDownlinkMngFlow;        /* ���й������� */
    unsigned long ulUplinkMngFlow;          /* ���й������� */
    unsigned long ulDownlinkFwdFlow;        /* ����ת������ */
    unsigned long ulUplinkFwdFlow;          /* ����ת������ */

} OMC_FLOW_STAT_T;

typedef struct
{
	unsigned char   acDeviceId[6];			    /* �豸ID */
	unsigned char   acGwDeviceId[6];			/* ���ص��豸ID */
    //unsigned long ulMeshGwFlag;                    /* if it is a MESH GW */

    //OMC_FLOW_STAT_T	stTotalFlowStat;

    unsigned long 	ulValidNum;
	OMC_FLOW_STAT_T	astFlowStat[vlanSetupList_SIZE];

} OMC_FLOW_STAT_ENTRY_T;

typedef struct
{
	unsigned char   acDeviceId[6];			    /* �豸ID */
	unsigned char   acGwDeviceId[6];			/* ���ص��豸ID */

    unsigned long   ulDownlinkDataFlow;       /* ����ҵ������ */
    unsigned long   ulUplinkDataFlow;         /* ����ҵ������ */
    unsigned long   ulDownlinkFwdFlow;        /* ����ת������ */
    unsigned long   ulUplinkFwdFlow;          /* ����ת������ */
} OMC_NODE_INFO_T;

/* ��ȡAODV�ھ��б� */
#define AODVNEIGHBORLIST_SIZE   16 //AODV_NEIGHBORLIST_SIZE
typedef struct 
{
	unsigned char aucAodvNeighDeviceId[6];			/* �ھ��豸ID */
	unsigned char aucAodvNeighMac[6];				/* �ھ�MAC */
	unsigned char aucAodvNeighIp[4];				/* �ھӵĹ���IP */
	unsigned long ulAodvLocalCost;					/* ��������costֵ*/
	unsigned long ulAodvPeerCost;					/* �Զ�����costֵ*/	
	unsigned long ulAodvNeighStatus;				/* �ھ�����*/
#define AODVNEIGHSTATUS_FATHER			1			/* ���ڵ�*/
#define AODVNEIGHSTATUS_SON				2			/* �ӽڵ�*/
#define AODVNEIGHSTATUS_OTHER			0			/* ������ϵ*/
	unsigned long ulAodvNeighGwStatus;				/* GW����*/
#define AODVNEIGHGW_SON                 1           /* I am the gw of the neigh */
#define AODVNEIGHGW_MY_GW               2			/* �Ǳ��ڵ�������GW*/
#define AODVNEIGHGW_OTHER_GW            3			/* �Ǳ��ڵ�������GW */
#define AODVNEIGHGW_OTHER               0           /* ����GW*/
	unsigned long ulAodvNeighHelloLoss;				/* HELLO��ʧ��*/
	unsigned long ulAodvNeighSendPkt;				/* ��Ա��ڵ�ķ��Ͱ���*/
	unsigned long ulAodvNeighRecvPkt;				/* ��Ա��ڵ�Ľ��հ���*/
	unsigned long ulAodvNeighWifiDeviceId;			/* �ھ����������豸ID */
	unsigned long ulAodvNeighWifiModuleId;			/* �ھ���������ģ��ID */
	unsigned long ulNeighborChannel;				/* �����ŵ� */
} OMC_AODV_NEIGHBOR_T;

typedef struct
{
	unsigned long 	ulValidNum;
	OMC_AODV_NEIGHBOR_T	astAodvNeighborEntty[AODVNEIGHBORLIST_SIZE];
} OMC_AODV_NEIGHBOR_ENTRY_T;

typedef MESH_ROUTE_PATH_END_INFO_ENTRY OMC_MESH_ROUTE_PATH_ENTRY_T;

/* ����ͼ�ṹ��Ϣ */
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
	unsigned long ulChannel;                  /* �ŵ� */
	unsigned long ulRate;                     /* ���� */
	unsigned long ulRssi;                     /* �������� */
	int			  iSignal;                    /* �ź�ǿ�� */
	int			  iNoise;                     /* ���롣�з����� */
	unsigned long ulVapMode;                  /* VAP���� */
#define VAP_MODE_AP    0                      /* AP */
#define VAP_MODE_ADHOC 1                      /* ADHOC */
	unsigned long ulBeacons;				  /* beacons���� */
	unsigned long ulLifetime;                 /* ͳ��Beaconʱ�䣬��λs */
	unsigned long ulRelatedState;			  /* �Ƿ����VAP�����������ϲ���ʾ���ֶΡ�������Ӧ���ܿ�����STA�������ĸ�VAP�� */
#define RELATED_STATE_NO_LINK	0			  /* δ���� */
#define RELATED_STATE_LINK		1			  /* �ѹ��� */
} OMA_SCAN_INFO;

#define SCAN_LIST_MAX_SIZE  100
typedef struct 
{
	unsigned long ulValidNum;					/* ��Ч���� */
	OMA_SCAN_INFO stScanInfo[SCAN_LIST_MAX_SIZE];
} OMA_SCAN_ENTRY;

/* �ն˹���VAP��Ϣ */
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

/* �ն�������Ϣ */
typedef struct  
{
	ROAM_STAT_T				stRoamStat;
	OMA_SCAN_ENTRY			stScanEntry;
	OMC_STA_ASSOCIATE_ENTRY	stAssocEntry;
} OMC_STA_TOPO_INFO_T;

/* �ն˺�IPά���� */
typedef struct
{
	unsigned char stMac[6];
	unsigned char stAddrIp[4];
#define OMC_ALTER_MACIP	  	1 	/* ���б����޸Ĳ��� */
#define OMC_DEL_STA_MACIP 	2 	/* ���б���ɾ������ */
#define OMC_FIND_STA_MACIP  3   /* ���б���Ҳ���   */
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

/* 2010-08-26 fengjing ���� */
int omc_neighbor_ap_list_get(OMA_NEIGHBOR_AP_ENTRY *pstNeighborAp);

int omc_userMacIp_handle(char * macAddr, char * ipAddr, int cmd);

#endif
