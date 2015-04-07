#ifndef AC_OMA_STAT_H
#define AC_OMA__STAT_H

#define AC_OMA_STAT_CACHE_NUM  ((UINT32)5)

#define AC_OMA_STAT_TYPE_SAMPLE         1 /* 统计信息采样 */
#define AC_OMA_STAT_TYPE_ABSTRACT       10 /* AP概要信息 */
#define AC_OMA_STAT_TYPE_ASSOCIATE      11 /* AP关联统计,总体 */
#define AC_OMA_STAT_TYPE_TOTAL          12 /* 用户连接统计,分SSID计算 */
#define AC_OMA_STAT_TYPE_ENDUSER        13 /* 终端统计 */
#define AC_OMA_STAT_TYPE_SSID           14 /* 空口统计 */
#define AC_OMA_STAT_TYPE_IF             15 /* 有线侧统计 */
#define AC_OMA_STAT_TYPE_ROGUEAP        16 /* 非法AP */
#define AC_OMA_STAT_TYPE_ROGUESTA       17 /* 干扰终端 */
#define AC_OMA_STAT_TYPE_IC             18 /* 无线端口统计 */
#define AC_OMA_STAT_TYPE_MGT            19 /* 管理统计 */

#define AC_OMA_SAMPLE_TYPE_SYS          1
#define AC_OMA_SAMPLE_TYPE_ASSO         2
#define AC_OMA_SAMPLE_TYPE_IF           3
#define AC_OMA_SAMPLE_TYPE_SSID         4
#define AC_OMA_SAMPLE_TYPE_WIFI         5
#define AC_OMA_SAMPLE_TYPE_ENDUSER      6

// 如果AP的实时采集开关打开，则AC对AP的以下数据以实时采集周期进行采集
// 系统性能统计
typedef struct
{
	UINT32 ulCPURTUsage;
	UINT32 ulMemRTUsage;
}AC_OMA_COLLECT_AP_SYS_T;

typedef struct
{	    
	CHAR     acSsid[32];	
    UINT32    ulAssocTimes;
    UINT32    ulAssocFailTimes;
    UINT32    ulReassocTimes;
	UINT32    ulApRspAssocTimes;
	UINT32    ulAssocSuccTimes;
}AC_OMA_COLLECT_AP_ASSOC_ENTRY_T;

typedef struct
{		   	
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_ASSOC_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_ASSOC_T;

typedef struct
{	
	UINT64    ulRecvBytes;
	UINT64    ulSendBytes;
	UINT32    ulRecvDiscardFrameNum;
}__attribute__ ((packed)) AC_OMA_COLLECT_AP_IF_ENTRY_T;

typedef struct
{		   	
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_IF_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_IF_T;

typedef struct
{
	CHAR     acSsid[32];	
	INT32 	 apSnrBSSIDAverageSignalStrength; 	 /*AP  的信号平均强度*/
	INT32	 apSnrBSSIDHighestRxSignalStrength;   /*AP  的最高信号强度*/
	INT32 	 apSnrBSSIDLowestRxSignalStrength;    /*AP  的最低信号强度*/
	UINT32   ulSendFrameNum; /* 发送的数据帧数 */
	UINT32   ulRecvFrameNum; /* 接收的数据帧数 */
	/* 2010/07/26 fengjing cmcc test */
	UINT32   ulRecvPackets;  /* 发送的数据包数 */
	UINT32   ulSendPackets;  /* 接收的数据包数 */
	UINT32   ulSendRetransFrame; /* 下行重传的数据帧数 */
	/* 2010/07/26 fengjing cmcc test */
	UINT32   ulSendRetransDataPackets;  /* 下行重传的数据包数 */
	UINT64   ulRecvBytes;
	UINT64   ulSendBytes;
}__attribute__ ((packed)) AC_OMA_COLLECT_AP_SSID_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_SSID_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_SSID_T;

typedef struct
{	
	UINT32  ulRecvErrPackets;        /* 接收的错误数据包数 */
    UINT32  ulRecvErrPhy;			/* 信道接收的物理层错包数 */
	UINT32  ulRecvErr;              /* 接收的错帧数 */
}AC_OMA_COLLECT_AP_WIFI_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_WIFI_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_WIFI_T;

typedef struct
{
	UINT8   aucEndUserMac[6];
	UINT8	acResv[2];
	UINT32  ulSendByteNum;	/* 发送字节数 */
	UINT32  ulRecvByteNum;	/* 接收字节数 */
}AC_OMA_COLLECT_AP_ENDUSER_ENTRY_T;

typedef struct
{
	UINT32    ulValidNum;
	AC_OMA_COLLECT_AP_ENDUSER_ENTRY_T *pstEntry;
}AC_OMA_COLLECT_AP_ENDUSER_T;

typedef struct
{
	UINT32                      ulApId;
	
	AC_OMA_COLLECT_AP_SYS_T     stSys;
	AC_OMA_COLLECT_AP_ASSOC_T   stAsso;
	AC_OMA_COLLECT_AP_IF_T      stIf;
	AC_OMA_COLLECT_AP_SSID_T    stSsid;
	AC_OMA_COLLECT_AP_WIFI_T    stWifi;
	AC_OMA_COLLECT_AP_ENDUSER_T stStation;

	//UINT8  aucResv[5];
}AC_OMA_COLLECT_AP_INFO_T;


typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulRet;            //返回码:0-成功
	UINT32   ulFinish;         //是否结束:0-未结束 1-结束
}AC_OMA_DYNAINFO_HEAD_T;

typedef struct
{	
	UINT32  ulApId;	

	// 2010/05/25 fengjing add
	OSTOKEN semStat;	

	BOOL  bSampleFlag;
	BOOL  bAbstractFlag;
	BOOL  bAssociateFlag;
	BOOL  bTotalFlag;
	BOOL  bEndUserFlag;
	BOOL  bSsidFlag;
	BOOL  bIfFlag;
	BOOL  bRogueApFlag;
	BOOL  bRogueStaFlag;
	BOOL  bIcFlag;
	BOOL  bMgtFlag;

	UINT32  ulSampleNum;
	
	UINT32  ulIndex; // 游标
	UINT8*  apstApSampleInfo[AC_OMA_STAT_CACHE_NUM];	

	/* 2010/08/18 fengjing modify */
	UINT32  aulMallocSize[AC_OMA_STAT_CACHE_NUM];

	AC_OMA_DYNAINFO_HEAD_T stHead1;
	// AP摘要信息
	DEVICE_ABSTRACT_INFO_T stApAbstract;

	AC_OMA_DYNAINFO_HEAD_T stHead2;
	// AP关联统计
	OMA_ASSOC_STA_STAT_ENTRY stApAssociateStat;

	AC_OMA_DYNAINFO_HEAD_T stHead3;
	// AP全局统计
	OMA_GLOBAL_STAT_ENTRY stApTotalStat;

	UINT32 ulMallocSize;
	UINT32 ulValidDataSize;
	// AP终端统计
	UINT8 *pstApEndUser;

	AC_OMA_DYNAINFO_HEAD_T stHead4;
	// AP空口统计
	OMA_AIR_STATS_ENTRY stApSsidStat;

	AC_OMA_DYNAINFO_HEAD_T stHead5;
	// AP有线侧统计
	NET_INFO_T stApIfStat;

	AC_OMA_DYNAINFO_HEAD_T stHead6;
	// AP 恶意AP
	ROGUE_AP_INFO_T stApRogueApInfo;

	AC_OMA_DYNAINFO_HEAD_T stHead7;
	// AP 恶意终端
	ROGUE_STA_LIST_T stApRogueStaInfo;

	AC_OMA_DYNAINFO_HEAD_T stHead8;
	// AP 卡级统计
	OMA_IC_STAT_ENTRY stApIcStatInfo;	

	AC_OMA_DYNAINFO_HEAD_T stHead9;
	// AP 管理统计
	OMA_MGT_STAT_ENTRY stApMgtStatInfo;
}AC_OMA_AP_STAT_INFO_T;

typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulSampleType;
}AC_OMC_GET_SAMPLE_REQ_MSG_T;

typedef struct
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulRet;             //返回码:0-成功
	UINT32   ulFinish;          //是否结束:0-未结束 1-结束
	UINT8    aucRsp[32*1024];   //网络字节序
}AC_OMC_GET_SAMPLE_RSP_MSG_T;

AC_RET  ac_oma_init_stat_report_queue(UINT32 ulNodeNum);
BOOL ac_oma_is_same_stat(const VOID *source, const VOID *dest);
UINT32  ac_oma_calc_hash_key_stat(const CHAR *msg, UINT32 ulNodeNum);

AC_RET ac_oma_add_stat_msg_to_queue(const AC_OMA_AP_STAT_INFO_T *msg);

// 当收到某个AP上报的统计信息时，添加到消息队列中
AC_RET  ac_oma_add_stat_msg(UINT32 ulApId, UINT32 ulMsgType, UINT8 *pucMsg, UINT32 ulMsgLen);

#if 0
// 当AP被删除时，需要从队列中删除该AP网元的统计信息，清零
AC_RET  ac_oma_remove_stat_msg_from_queue(UINT32 *msg);

// AC-OMA接收到AP上报的采样动态数据
AC_RET ac_oma_ap_report_statsample_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);

AC_RET ac_oma_check_ap_stat_msg(UINT32 ulApId, UINT32 ulSn, UINT32 ulMsgType);

AC_RET ac_oma_get_sample_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
#endif

AC_RET ac_oma_start_stat_report(UINT32 ulStatType);
AC_RET ac_oma_check_stat_report(VOID);

AC_RET ac_oma_config_init_acbasic_config(VOID);
AC_RET ac_db_acbasicsetup_cfg_change_ind_msg(UINT8 *pbyMsgBody, UINT32 wMsgLen);

#endif

