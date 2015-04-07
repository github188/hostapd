#ifndef ROUTER_CONFIG_COMMON_H
#define ROUTER_CONFIG_COMMON_H


#define BRCTL_MESH_ROUTE_IOCTL 30  /* be careful not to conflict with system config */

#define USER_FILE_ITEM_NUM     4
#define USER_FILE_SIZE      sizeof(rc_log_item_t) * USER_FILE_ITEM_NUM


#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

#define R_BYTE          0
#define R_PACKET        1
#define R_ERR           2
#define R_DROP          3
#define R_FIFO          4
#define R_FRAME         5
#define R_COMPRESSED    6
#define R_MULTICAST     7
#define T_BYTE          8
#define T_PACKET        9
#define T_ERR           10
#define T_DROP          11
#define T_FIFO          12
#define T_FRAME         13
#define T_COMPRESSED    14
#define T_MULTICAST     15
#define DEV_STAT_MAX    16

typedef struct 
{
	unsigned long ulL2Isolate;
}T_bridgeIsolateSetup;

typedef struct 
{
	unsigned long ulMngPortNum;
	char acMngPortName[24][32];
}T_bridgeMngPortSetup;


/*�ڵ�����*/
typedef struct meshRouteNodeSetup_s 
{
	unsigned long ulGwRunMode;								/* ���ع���*/
#define nodeGwRunMode_DISABLE				0
#define nodeGwRunMode_ENABLE				1
	unsigned long ulRelayRunMode;							/* �м̹���*/
#define nodeRelayRunMode_DISABLE			0
#define nodeRelayRunMode_ENABLE				1
	unsigned long ulMobileState;							/* �ƶ�����*/
#define mobileState_REST					0
#define mobileState_MOVE					1
	unsigned long ulMovingSpeed;							/* �ƶ��ٶ�*/
#define nodeMovingSpeed_SLOW				0
#define nodeMovingSpeed_FAST				1
	unsigned long ulMovingDirection;						/* �ƶ�����*/
#define nodeMovingDirection_MULTIPLE		0
#define nodeMovingDirection_BEFORE			1
#define nodeMovingDirection_AFTER			2
	unsigned long ulAirBandWidth;							/* ҵ�����Ҫ��*/
	char acDeviceId[6];
} T_meshRouteNodeSetup;

#define AODV_STATISLIST_SIZE		2
typedef struct PORT_FLOW_INFO_T 
{
	unsigned long ulRxFlow;							/* ��������kbps��*/
	unsigned long ulTxFlow;							/* ��������Kbps��*/
	unsigned long ulFwdFlow;						/* ת��������kbps����ADHOC�룬��ADHOC��*/
	unsigned long ulLocalFlow;                      /* ����������kbps��*/     
	unsigned long ulInputFlow;                      /* add  */ 
	unsigned long ulOutputFlow;                     /* add  */     
	unsigned long ulRxPkt;							/* ��������kbps��*/
	unsigned long ulTxPkt;							/* ��������kbps��*/
	unsigned long ulFwdPkt;							/* ת��������kbps��*/
	unsigned long ulLocalPkt;
	unsigned long ulInputPkt;                       /* add  */ 
	unsigned long ulOutputPkt;                      /* add  */     

	/* Unicast statistic */
	unsigned long ulRxUniFlow;						/* �뵥������(kbps) */
	unsigned long ulTxUniFlow;						/* ����������(kbps) */
	unsigned long ulFwdUniFlow;						/* ת������������kbps����AD */
	unsigned long ulLocalUniFlow;					/* ���ص���������*/  
	unsigned long ulInputUniFlow;                   /* add  */ 
	unsigned long ulOutputUniFlow;                  /* add  */     
    
	unsigned long ulRxUniPkt;                       /* �뵥��������*/
	unsigned long ulTxUniPkt;                       /* ������������*/
	unsigned long ulFwdUniPkt;						/* ת��������������AD */
	unsigned long ulLocalUniPkt;					/* ���ص���������*/  
	unsigned long ulInputUniPkt;                    /* add  */ 
	unsigned long ulOutputUniPkt;                   /* add  */     

	/* Broadcast statistic */
	unsigned long ulRxBrdFlow;                    	/* ��㲥����(kbps) */
	unsigned long ulTxBrdFlow;                    	/* ���㲥����(kbps) */
	unsigned long ulFwdBrdFlow;						/* ת���㲥������kbps����AD */
	unsigned long ulLocalBrdFlow;					/* ���ع㲥������*/  
	unsigned long ulInputBrdFlow;                   /* add  */ 
	unsigned long ulOutputBrdFlow;                  /* add  */     
    
	unsigned long ulRxBrdPkt;                    	/* ��㲥������*/
	unsigned long ulTxBrdPkt;                    	/* ���㲥������*/
	unsigned long ulFwdBrdPkt;						/* ת���㲥��������AD */
	unsigned long ulLocalBrdPkt;					/* ���ع㲥������*/  
	unsigned long ulInputBrdPkt;                    /* add  */ 
	unsigned long ulOutputBrdPkt;                   /* add  */     

	/* packet send failure (device driver failure )/����ͳ��ֻ������ADHOC�豸 */
	unsigned long ulDropUniFlow;                    /* ������������(kbps) */
	unsigned long ulDropBrdFlow;					/* �����㲥����*/
	unsigned long ulDropUniPkt;						/* ��������������*/
	unsigned long ulDropBrdPkt;						/* �����㲥������*/
}PORT_FLOW_INFO_T;

typedef struct
{
	char    acIfrName[IFNAMSIZ];        /* if name, e.g. "eth0" */
	PORT_FLOW_INFO_T stFlowInfo;  
} MESH_DEV_STATIS_T;

typedef struct  
{
	/* statis of each device */
	unsigned long ulNum;    /* number of valid device statis  */
	MESH_DEV_STATIS_T astStatisEntry[AODV_STATISLIST_SIZE];
} AODV_DEV_STATIS_LIST_T;

/* vlan priority */
typedef struct _MESH_VLAN_PRIORITY_T
{
	unsigned long ulCfgType;		 /* �������� */
#define ADD_PRIO_TO_BR		1
#define DEL_PRIO_FRM_BR		2
#define MOD_PRIO_WITH_BR	3
	unsigned char acName[IFNAMSIZ];  /* VLAN��Ӧ�ŵ����� */
	unsigned long ulPriority;        /* VLAN�����ȼ� */
	unsigned long ulVlanId;          /* VLAN��ID*/
} MESH_VLAN_PRIORITY_T;

typedef struct 
{
	unsigned char aucMacAddr[6];  /* user Mac address(filled by caller */   
	unsigned char aucRsv[2];
	unsigned char aucIpAddr[4];   /* user IP address */
}USER_ADDR_INFO_T;


#define    MESH_DEV_TYPE_AP       		0
#define    MESH_DEV_TYPE_ADHOC    		1
#define    MESH_DEV_TYPE_ETH      		2
#define    MESH_DEV_TYPE_GW       		3
#define    MESH_DEV_TYPE_ADHOC_ACBK     4     /* ��ͨ��adhoc�ڵ㣬������ԭ���� #define    MESH_DEV_TYPE_ADHOC_STA    1 */
#define    MESH_DEV_TYPE_ADHOC_AC       5     /* ֻ����������adhoc�ڵ� */
#define    MESH_DEV_TYPE_ADHOC_BK       6     /* ֻ�����ش����adhoc�ڵ� */
#define    MESH_DEV_TYPE_ADHOC_STA      7     /* ֻ�����ն˵Ľڵ� */


#define    MESH_ADD_DEV_TO_BR     1    /*������������豸*/
#define    MESH_DEL_DEV_FRM_BR    2    /*��������ɾ���豸*/
#define    MESH_MD_DEV_FRM_BR	  		3    /*�������޸��豸*/

typedef struct
{
	char            acIfrName[IFNAMSIZ];    /* if name, e.g. "eth0" */
    unsigned long   ulCfgType;              /* wl add .2008-03-14 */  /*��������*/
    unsigned long   ulDevType;              /* wl add .2008-03-14 */  /*�豸����*/
} MESH_DEV_CFG_T;

//typedef struct
//{
//	char    acIfrName[IFNAMSIZ];        /* if name, e.g. "eth0" */
//} MESH_DEV_STATIS_T;


/* used in oam ioctl interface */
#define ROUTE_IOCTL_SETDEVCFG       1   /* set device config*/
#define ROUTE_IOCTL_GETNEIGHLIST    2   /* get neigh list */
#define ROUTE_IOCTL_GETPATHLIST     3   /* get route list */
#define ROUTE_IOCTL_SETNETCFG       4   /* set network config */
#define ROUTE_IOCTL_SETNODECFG      5   /* set node config */
#define ROUTE_IOCTL_SETNEICFG       6   /* set neighbour config */ 
#define ROUTE_IOCTL_SETROUTECFG     7   /* set route config */ 
#define ROUTE_IOCTL_SETHANDOVERCFG  8   /* set neigh config */
#define ROUTE_IOCTL_SETMSCFG        9   /* set ms config */
#define ROUTE_IOCTL_GETNETCFG       10  /* get network config */
#define ROUTE_IOCTL_GETNODECFG      11  /* get node config */
#define ROUTE_IOCTL_GETNEICFG       12  /* get neighbour config */ 
#define ROUTE_IOCTL_GETROUTECFG     13  /* get route config */ 
#define ROUTE_IOCTL_GETHANDOVERCFG  14  /* get neigh config */
#define ROUTE_IOCTL_GETMSCFG        15  /* set ms config */ 
#define ROUTE_IOCTL_GETEVENT        16  /* get event and warning list */
#define ROUTE_IOCTL_GETNODEINFO     17  /* get node info of current node */
#define ROUTE_IOCTL_GETSTATISINFO   18  /* get statistic  info of current node */
#define ROUTE_IOCTL_SETVLANPRIO		20 /* set vlan priority */
#define ROUTE_IOCTL_SETGWHOLD       22 /* set sys keeper config */
#define ROUTE_IOCTL_GETGWHOLD       23 /* get sys keeper config */
/* add by wl for CR-694 at 09.0.13 bng*/
#define ROUTE_IOCTL_GETADDRINFO      24  /* get information of a address(user) */
/* add by wl for CR-694 at 09.0.13 end*/

#define ROUTE_IOCTL_V2_SETBASICCFG   25
#define ROUTE_IOCTL_V2_SETNEICFG     26
#define ROUTE_IOCTL_V2_SETHOCFG      27
#define ROUTE_IOCTL_V2_SETMSCFG      28
#define ROUTE_IOCTL_V2_GETBASICCFG   39
#define ROUTE_IOCTL_V2_GETNEICFG     30
#define ROUTE_IOCTL_V2_GETHOCFG      31
#define ROUTE_IOCTL_V2_GETMSCFG      32
#define ROUTE_IOCTL_V2_SET_ISOLATE_CFG  33
#define ROUTE_IOCTL_V2_SET_MNGPORT_CFG  34



#define ROUTE_IOCTL_START           ROUTE_IOCTL_SETDEVCFG
#define ROUTE_IOCTL_END             ROUTE_IOCTL_V2_SET_MNGPORT_CFG
/* add by fcgao for CR-532 at 08.10.05 end */

typedef struct 
{
	unsigned long ulCmd;
	long iResult;
	unsigned long ulSize;
	unsigned long ulOffset; /* how many should skipped */
	unsigned long ulMaxNum;
    union
    {
        MESH_DEV_CFG_T stDevCfg;         
        AODV_NEIGHBOR_LIST_T    stNeighList;
		MESH_ROUTE_PATH_END_INFO_ENTRY stRtPathList;
		EVENT_TRAP_MSG_LIST_T stEvtList;
		AODV_NODEINFO_T stNodeInfo;
		AODV_DEV_STATIS_LIST_T stStatisList;
		MESH_VLAN_PRIORITY_T stVlanPriority;
		T_sysKeeperSetup	stKeeperSetup;
		USER_ADDR_INFO_T stUsrAddrInfo;

		T_routeBasicSetup stV2BasicCfg;
		T_routerNeighSetup stV2NeighCfg;
		T_routerHandoverSetup stV2HoCfg;
		T_routerMscSetup stV2MsCfg;
		T_bridgeIsolateSetup  stV2IsolateCfg;
		T_bridgeMngPortSetup  stV2MngPortCfg;
    }u;
}AODV_ROUTE_IOCTL_T;

/* �ӿں��� */

/* ����ģ��󡷳�ʼ�����������ò���������ģ�� */
int router_paratbl_init(void);

/* �������ú��� */
int router_set_cfg(const char *brname, AODV_ROUTE_IOCTL_T *pstCfg);

/* �������ú��� */
int router_get_cfg(const char *brname, AODV_ROUTE_IOCTL_T *pstCfg);

/* ���ͳ����Ϣ��״̬��Ϣ */
int router_state_get(const char *brname, AODV_ROUTE_IOCTL_T *pstCfg);

/* �Ų������ú��� */
int route_mesh_dev_cfg(const char *brname, const char *devname, 
					   unsigned char ucDevType, unsigned char ucAddorDel, 
					   AODV_ROUTE_IOCTL_T *pstCfg);

/* ��ȡ�ھ���Ϣ */
int mesh_getneighinfo(const char *br, AODV_NEIGHBOR_T *neigh, 
					  unsigned long offset, int num);

/* ��ȡ·����Ϣ */
int mesh_getpath(const char *br, MESH_ROUTE_PATH_END_INFO_T* path,
				 unsigned long offset, int num);

/* ��ȡ�¼��б� */
int mesh_getevent(const char *br, EVENT_TRAP_MSG_T *event, 
				  int num);

/* ��ȡ�ڵ���Ϣ */
int mesh_getnodeinfo(const char *br, AODV_NODEINFO_T *nodeInfo);


/* VLAN���ȼ����ú��� */
int route_vlan_prio_set(const char *brname, AODV_ROUTE_IOCTL_T *pstCfg);

/* ����MAC����ȡ�ն��û���IP��ַ */
int mesh_get_user_addr(const char *br, USER_ADDR_INFO_T *p_userAddr);

int get_log_item_count(int iLogFileId);
int get_log_item(int iLogFileId, LOG_ITEM_T* pstItem, int iIndex);
int write_log_item(int iLogFileId, LOG_ITEM_T* pstItem);

int tcp_configure_set(T_tcpOptimizationSetup *pstTcpSetup);

void get_free_info(STORAGE_INFO_T *pstStorage);

void get_df_info(STORAGE_INFO_T *pstStorage);

int get_storage_info(STORAGE_INFO_T *pstStorage);

/* ��ȡ��̫��ͳ����Ϣ */
int get_net_info(NET_INFO_T *pstNetInfo);

int user_file_write(void);

int user_file_read(unsigned long * p_startFlag);

#endif
