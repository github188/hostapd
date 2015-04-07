/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  射频资源管理模块头文件
* 修改历史: 
* 2009-3-22     叶恩云            新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/
#ifndef  __RRM_APP_H
#define  __RRM_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************** 宏定义 *************************************/
#ifndef ID_BETWEEN
#define ID_BETWEEN(id, min, max)		((id) >= (min) && (id) <= (max))
#endif

#define MIN(_a, _b)	((_a) <= (_b) ? (_a) : (_b))
#define MAX(_a, _b)	((_a) <= (_b) ? (_b) : (_a))

#ifndef MAC2STR
#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"
#endif

#ifndef WTPIDSTR
#define WTPIDSTR	"%d"
#define WTPID2STR(pWtpId)		(pWtpId)->ulWtpId
#endif

#ifndef GDEVIDSTR
#define GDEVIDSTR	"%d/%d"
#define GDEVID2STR(pGdevId)		(pGdevId)->ulWtpId,(pGdevId)->ulVDevId
#endif

#ifndef VAPIDSTR
#define VAPIDSTR	"%d/%d/%d"
#define VAPID2STR(pVapId)		(pVapId)->ulWtpId,(pVapId)->ulVDevId,(pVapId)->ulVapId
#endif

#ifndef DBM2RSSI
#define DBM2RSSI(_dBm)			(95+(_dBm))
#endif

#define NEIGHBOR_AP_MAX		128	/*邻居AP个数*/
#define RRM_CHANQUALITYLOW_OVER_NUM	1	/*频点质量低超门限次数*/	
#define RRM_CHANREELECT_INTVAL		15	/*允许频点切换最小间隔，单位：秒*/

#define RRM_COM_ACAC_TIMEOUT			2	/*AC间通信超时间，单位：秒*/
#define RRM_COM_ACAP_TIMEOUT			2	/*AC AP间通信超时间，单位：秒*/
#define RRM_COM_ACAC_NUM				3	/*AC间最大通信次数*/
#define RRM_COM_ACAP_NUM				3	/*AC AP间最大通信次数*/

#define RRM_WTPLINKSTATE_UNCONNECTED	0
#define RRM_WTPLINKSTATE_CONNECTED		1

#define IEEE80211_NWID_LEN		32

/******************************** 结构体定义 *********************************/
typedef struct{
	UINT32 ulRssi ;
	INT32 lNoise ;
}SCAN_COND_T ;


typedef struct {
	struct ieee80211_scan_ssid {
		UINT32 len;					/* length in bytes */
		UINT8 ssid[IEEE80211_NWID_LEN];	/* ssid contents */
	}ssid;
	UINT8 bssid[6] ;
	UINT8 channel ;
	UINT8 rssi ;	/*实际为SNR*/
	int noise ;
}NEIGHBOR_AP_INFO_T ;


typedef struct{
	UINT32 ulWifiId;
	UINT8 aucMac[6];		/*本AP MAC*/
	UINT8 aucMacPad[2];
	UINT32 ulChannel;		/*本AP CHANNEL*/
	UINT32 ulNeighborApNum ;
	NEIGHBOR_AP_INFO_T stNeighborApList[NEIGHBOR_AP_MAX] ;
}NEIGHBOR_AP_LIST_T ;


typedef struct RRM_GDEVID_LIST_TAG{
	AC_VDEVID_T stGdevId ;
	struct RRM_GDEVID_LIST_TAG * pstNext ;
}RRM_GDEVID_LIST_T ;


typedef struct{
	AC_VAPID_T stVapId ;
	CHAR acIfName[AC_DEVM_IFNAME_LEN] ;
}RRM_VAP_T ;


typedef struct MAC_LIST_TAG{
	UINT8 ucThisBssid[6];		/*本AP MAC*/
	UINT8 ucThisBssidPad[2];	
	UINT32 ulThisChannel;	/*本AP CHANNEL*/
	UINT8 ucMac[6];			/*干扰AP MAC*/
	UINT8 ucReserve;	
	UINT8 ulChannel;			/*干扰AP CHANNEL*/
	INT32 lSignalStrength;	/*干扰AP信号强度*/
	UINT32 ulCount;	/*保活计数器*/
	struct MAC_LIST_TAG * pstNext;
}MAC_LIST_T;


#define GDEV_ALARM_CHAN_QUALITY_LOW		0x1	/*AP设备干扰告警，即频点质量低告警*/
#define GDEV_ALARM_CHAN_AVAIL_LOW		0x2	/*可用频点数过低告警*/
#define GDEV_ALARM_CHAN_INTERFERENCE	0x4	/*其它设备干扰告警，如其它红外设备*/
#define GDEV_ALARM_CHAN_COINTERFERENCE	0x8	/*同频AP干扰告警*/
#define GDEV_ALARM_CHAN_NEIGHINTERFERENCE	0x10	/*邻频AP干扰告警*/

#define MONIMODE_NORMAL	1	/*纯接入模式*/
#define MONIMODE_SCAN		2	/*纯扫描模式*/
#define MONIMODE_SEMI		3	/*空闲时扫描模式*/

/*  BugId=285, chary, 2011-11-29, begin   */
#define	NEIGHBOR_IS_NEARBY			1 	/* 邻居AP 是邻频干扰源  */
#define	NEIGHBOR_IS_NOT_NEARBY		0	/* 邻居AP 不是邻频干扰源 */
#define	CHANNEL_MARGIN_STANDARD		2	/*  邻频信道差判定标准 */
/*  BugId=285, chary, 2011-11-29, end   */


typedef struct RRM_GDEV_TAG{
	AC_VDEVID_T stGdevId ;
	RRM_VAP_T * pstVapList[AC_VAP_NUM_MAX_PER_IF] ;

	/*配置*/
	UINT32 ulPowerLimit ;	/*无线模块硬件支持的最大发射功率*/
	UINT32 ulPowerAtt ;	/*最大发射功率衰减值*/
	UINT32 ulChannelAuto ;	/*1:AUTO;0:STATIC*/
	INT32 lCoDisturbThreshold;	/*同频干扰告警门限*/
	INT32 lNeiborDisturbThreshold;	/*邻频干扰告警门限*/
	AC_DEVM_VDEVRRM_CONFIG_T stConfig ;
	RRM_GDEVID_LIST_T * pstListGdevServer ;	/*邻居配置列表，邻居设备是功率补偿服务提供者*/
	RRM_GDEVID_LIST_T * pstListGdevRequest ;	/*邻居配置列表，邻居设备是功率补偿服务请求者*/

	UINT32 ulScanSame ;	/*同频扫描计时器，剩余时间，单位为分钟*/
	UINT32 ulScanDiff ;	/*异频扫描计时器，剩余时间，单位为分钟*/
	UINT32 ulTimeScanSame ;	/*同频扫描时间点，单位：秒*/
	UINT32 ulTimeScanDiff ;	/*异频扫描时间点，单位：秒*/
	struct RRM_GDEV_TAG * pstScanNext ;	/*扫描列表*/

	UINT32 bGdevAlarmMask ;
	
	/*频点资源管理*/
	UINT32 ulChanCheckNum ;	
	UINT32 ulChanRssiOver ;	/*检测周期内RSSI超越门限次数*/
	UINT32 ulChanNoiseOver ;	/*底噪过高*/
	UINT32 ulChanReelectCmdNum ;
	UINT32 ulChanReelectNum ;	/*AC上电以来，频点重选累加次数*/

	/*功率资源管理，策略一*/
	UINT32 ulPowerCheckNum ;
	UINT32 ulTimeLatestDown ;	/*最近降功率时间，单位为秒*/
	UINT32 ulPowerAdjustCmdNum ;

	/*功率资源管理，策略二*/
	UINT32 ulPowerRepair ;		/*功率补偿请求者设备个数*/
	RRM_GDEVID_LIST_T * pstListGdevRequestCur ;	/*当前功率补偿请求者设备列表，只当本设备关联到AC，才有该值；不用个数表示补偿状态，而用具体被补偿设备ID列表表示，是因为考虑跨AC补偿时，其中一AC断线或由于异常而死机*/
	UINT32 ulPowerRepairCmdNum ;	/*功率补偿消息发送次数*/
	UINT32 ulPowerDerepairCmdNum ;	/*解除功率补偿消息发送次数*/

	/*缓存干扰告警源*/
	MAC_LIST_T * pstDisturbApList;

	MAC_LIST_T	stDisturbCo;	/*同频干扰告警源*/
	MAC_LIST_T	stDisturbNeigh;	/*邻频干扰告警源*/
}RRM_GDEV_T ;


struct RRM_DOMAIN_TAG ;

typedef struct{
	AC_WTPID_T stWtpId ;
	RRM_GDEV_T * pstGdevList[AC_VDEV_NUM_MAX_PER_WTP] ;

	UINT32 ulLoadBalance ;	/*负荷均衡开关（基于用户数或基于流量）*/
	UINT32 bLinkState ;	/*链路状态，0：链断；1：链通*/
	/* struct RRM_DOMAIN_TAG stDomain ; */	/*每个WTP设备存在一个域，本设备在空口上受域中的设备影响，设备在异频扫描时，更新该域中的关联设备*/
}RRM_WTP_T ;


/*RRM无线资源管理域*/
typedef struct RRM_DOMAIN_TAG{
	/*RRM_WTP_T * pstWtpList[] ;*/ 	/*域中的关联WTP设备*/

	UINT32 bChanReelect ;		/*1：正处于频点重选事物处理中*/
	UINT32 ulTimeLatestReelect ;	/*网络设备最近切换频点时间*/
	UINT32 ulChanReqAcId[8] ;	/*正在频点重选请求中的AC*/
}RRM_DOMAIN_T ;


typedef struct{
	UINT32 ulAcId ;

	RRM_DOMAIN_T stDomain ;	/*AC2.0简化处理：所有AC为一个域*/
	RRM_GDEV_T * pstScanList ;	/*按时间为组设备排序，每隔至少5秒才能发送同频/异频请求信息*/
	UINT32 ulTimeLatestNeighReq ;
}RRM_AC_T ;


/******************************** 全局变量声明 ********************************/


/******************************** 外部函数原形声明 ****************************/
int rrm_device_load(VOID) ;

int rrm_wtp_add(AC_DEVM_WTP_CONFIG_T * pstConfig) ;
int rrm_wtp_del(AC_WTPID_T * pstId) ;
int rrm_wtp_update(AC_DEVM_WTP_CONFIG_T* pstConfig) ;
int rrm_wtp_opstate(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T * pstOpstate) ;

int rrm_gdev_add(AC_DEVM_VDEV_CONFIG_T * pstConfig) ;
int rrm_gdev_del(AC_VDEVID_T * pstId) ;
int rrm_gdev_update(AC_DEVM_VDEV_CONFIG_T * pstConfig) ;
int rrm_gdev_isneighbor(AC_VDEVID_T * pstId, AC_VDEVID_T * pstIdServer) ;
int rrm_proc_gdevneighbor_add(AC_VDEVID_T * pstId, AC_VDEVID_T * pstNeighborId) ;
int rrm_proc_gdevneighbor_del(AC_VDEVID_T * pstId, AC_VDEVID_T * pstNeighborId) ;

int rrm_vap_add(AC_DEVM_VAP_CONFIG_T * pstConfig) ;
int rrm_vap_del(AC_VAPID_T * pstId) ;
int rrm_vap_update(AC_DEVM_VAP_CONFIG_T * pstConfig) ;

int rrm_proc_neighborap_request(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength, UINT32 ulType, SCAN_COND_T * pstScanCond) ;
int rrm_proc_neighborap_response(AC_VAPID_T * pstId, NEIGHBOR_AP_LIST_T * pstNeighborApList, UINT32 ulType) ;
int rrm_proc_channel_reelect_request(AC_VDEVID_T * pstId, UINT32 ulAcId) ;
int rrm_proc_channel_reelect_response(AC_VDEVID_T * pstGdevId, UINT32 ulAcId, UINT32 bAck) ;
int rrm_proc_channel_reelect_cmd(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength) ;
int rrm_proc_channel_reelect_cmd_resp(AC_VAPID_T * pstId) ;
int rrm_proc_power_adjust(AC_VAPID_T * pstId, UINT32 ulType) ;
int rrm_proc_power_adjust_cmd(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength, UINT32 ulType) ;
int rrm_proc_power_adjust_cmd_resp(AC_VAPID_T * pstId, UINT32 ulPowerCur) ;
int rrm_proc_power_repair_cmd(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength) ;
int rrm_proc_power_repair_cmd_resp(AC_VAPID_T * pstVapId) ;
int rrm_proc_power_repair_tran(AC_VDEVID_T * pstGdevIdRequest, AC_VDEVID_T * pstGdevIdServer) ;
int rrm_proc_power_derepair_tran(AC_VDEVID_T * pstGdevIdRequest, AC_VDEVID_T * pstGdevIdServer) ;
int rrm_proc_flowstats_request(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength) ;
int rrm_proc_flowstats_response(AC_VAPID_T * pstId, UINT32 ulFlowStats) ;
int rrm_proc_disassoc(AC_VDEVID_T * pstGdev, UINT32 ulDisassoc) ;
int rrm_proc_disassoc_cmd(AC_VAPID_T * pstId, const char * pcIfName, UINT32 ulNameLength, UINT32 ulDisassoc) ;

/********************************** 函数原形声明 ******************************/


#ifdef __cplusplus
}
#endif

#endif /* __RRM_APP_H */
/******************************* 头文件结束 **********************************/
