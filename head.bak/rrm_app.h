/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��Ƶ��Դ����ģ��ͷ�ļ�
* �޸���ʷ: 
* 2009-3-22     Ҷ����            �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/
#ifndef  __RRM_APP_H
#define  __RRM_APP_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************** �궨�� *************************************/
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

#define NEIGHBOR_AP_MAX		128	/*�ھ�AP����*/
#define RRM_CHANQUALITYLOW_OVER_NUM	1	/*Ƶ�������ͳ����޴���*/	
#define RRM_CHANREELECT_INTVAL		15	/*����Ƶ���л���С�������λ����*/

#define RRM_COM_ACAC_TIMEOUT			2	/*AC��ͨ�ų�ʱ�䣬��λ����*/
#define RRM_COM_ACAP_TIMEOUT			2	/*AC AP��ͨ�ų�ʱ�䣬��λ����*/
#define RRM_COM_ACAC_NUM				3	/*AC�����ͨ�Ŵ���*/
#define RRM_COM_ACAP_NUM				3	/*AC AP�����ͨ�Ŵ���*/

#define RRM_WTPLINKSTATE_UNCONNECTED	0
#define RRM_WTPLINKSTATE_CONNECTED		1

#define IEEE80211_NWID_LEN		32

/******************************** �ṹ�嶨�� *********************************/
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
	UINT8 rssi ;	/*ʵ��ΪSNR*/
	int noise ;
}NEIGHBOR_AP_INFO_T ;


typedef struct{
	UINT32 ulWifiId;
	UINT8 aucMac[6];		/*��AP MAC*/
	UINT8 aucMacPad[2];
	UINT32 ulChannel;		/*��AP CHANNEL*/
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
	UINT8 ucThisBssid[6];		/*��AP MAC*/
	UINT8 ucThisBssidPad[2];	
	UINT32 ulThisChannel;	/*��AP CHANNEL*/
	UINT8 ucMac[6];			/*����AP MAC*/
	UINT8 ucReserve;	
	UINT8 ulChannel;			/*����AP CHANNEL*/
	INT32 lSignalStrength;	/*����AP�ź�ǿ��*/
	UINT32 ulCount;	/*���������*/
	struct MAC_LIST_TAG * pstNext;
}MAC_LIST_T;


#define GDEV_ALARM_CHAN_QUALITY_LOW		0x1	/*AP�豸���Ÿ澯����Ƶ�������͸澯*/
#define GDEV_ALARM_CHAN_AVAIL_LOW		0x2	/*����Ƶ�������͸澯*/
#define GDEV_ALARM_CHAN_INTERFERENCE	0x4	/*�����豸���Ÿ澯�������������豸*/
#define GDEV_ALARM_CHAN_COINTERFERENCE	0x8	/*ͬƵAP���Ÿ澯*/
#define GDEV_ALARM_CHAN_NEIGHINTERFERENCE	0x10	/*��ƵAP���Ÿ澯*/

#define MONIMODE_NORMAL	1	/*������ģʽ*/
#define MONIMODE_SCAN		2	/*��ɨ��ģʽ*/
#define MONIMODE_SEMI		3	/*����ʱɨ��ģʽ*/

/*  BugId=285, chary, 2011-11-29, begin   */
#define	NEIGHBOR_IS_NEARBY			1 	/* �ھ�AP ����Ƶ����Դ  */
#define	NEIGHBOR_IS_NOT_NEARBY		0	/* �ھ�AP ������Ƶ����Դ */
#define	CHANNEL_MARGIN_STANDARD		2	/*  ��Ƶ�ŵ����ж���׼ */
/*  BugId=285, chary, 2011-11-29, end   */


typedef struct RRM_GDEV_TAG{
	AC_VDEVID_T stGdevId ;
	RRM_VAP_T * pstVapList[AC_VAP_NUM_MAX_PER_IF] ;

	/*����*/
	UINT32 ulPowerLimit ;	/*����ģ��Ӳ��֧�ֵ�����书��*/
	UINT32 ulPowerAtt ;	/*����书��˥��ֵ*/
	UINT32 ulChannelAuto ;	/*1:AUTO;0:STATIC*/
	INT32 lCoDisturbThreshold;	/*ͬƵ���Ÿ澯����*/
	INT32 lNeiborDisturbThreshold;	/*��Ƶ���Ÿ澯����*/
	AC_DEVM_VDEVRRM_CONFIG_T stConfig ;
	RRM_GDEVID_LIST_T * pstListGdevServer ;	/*�ھ������б��ھ��豸�ǹ��ʲ��������ṩ��*/
	RRM_GDEVID_LIST_T * pstListGdevRequest ;	/*�ھ������б��ھ��豸�ǹ��ʲ�������������*/

	UINT32 ulScanSame ;	/*ͬƵɨ���ʱ����ʣ��ʱ�䣬��λΪ����*/
	UINT32 ulScanDiff ;	/*��Ƶɨ���ʱ����ʣ��ʱ�䣬��λΪ����*/
	UINT32 ulTimeScanSame ;	/*ͬƵɨ��ʱ��㣬��λ����*/
	UINT32 ulTimeScanDiff ;	/*��Ƶɨ��ʱ��㣬��λ����*/
	struct RRM_GDEV_TAG * pstScanNext ;	/*ɨ���б�*/

	UINT32 bGdevAlarmMask ;
	
	/*Ƶ����Դ����*/
	UINT32 ulChanCheckNum ;	
	UINT32 ulChanRssiOver ;	/*���������RSSI��Խ���޴���*/
	UINT32 ulChanNoiseOver ;	/*�������*/
	UINT32 ulChanReelectCmdNum ;
	UINT32 ulChanReelectNum ;	/*AC�ϵ�������Ƶ����ѡ�ۼӴ���*/

	/*������Դ��������һ*/
	UINT32 ulPowerCheckNum ;
	UINT32 ulTimeLatestDown ;	/*���������ʱ�䣬��λΪ��*/
	UINT32 ulPowerAdjustCmdNum ;

	/*������Դ�������Զ�*/
	UINT32 ulPowerRepair ;		/*���ʲ����������豸����*/
	RRM_GDEVID_LIST_T * pstListGdevRequestCur ;	/*��ǰ���ʲ����������豸�б�ֻ�����豸������AC�����и�ֵ�����ø�����ʾ����״̬�����þ��屻�����豸ID�б��ʾ������Ϊ���ǿ�AC����ʱ������һAC���߻������쳣������*/
	UINT32 ulPowerRepairCmdNum ;	/*���ʲ�����Ϣ���ʹ���*/
	UINT32 ulPowerDerepairCmdNum ;	/*������ʲ�����Ϣ���ʹ���*/

	/*������Ÿ澯Դ*/
	MAC_LIST_T * pstDisturbApList;

	MAC_LIST_T	stDisturbCo;	/*ͬƵ���Ÿ澯Դ*/
	MAC_LIST_T	stDisturbNeigh;	/*��Ƶ���Ÿ澯Դ*/
}RRM_GDEV_T ;


struct RRM_DOMAIN_TAG ;

typedef struct{
	AC_WTPID_T stWtpId ;
	RRM_GDEV_T * pstGdevList[AC_VDEV_NUM_MAX_PER_WTP] ;

	UINT32 ulLoadBalance ;	/*���ɾ��⿪�أ������û��������������*/
	UINT32 bLinkState ;	/*��·״̬��0�����ϣ�1����ͨ*/
	/* struct RRM_DOMAIN_TAG stDomain ; */	/*ÿ��WTP�豸����һ���򣬱��豸�ڿտ��������е��豸Ӱ�죬�豸����Ƶɨ��ʱ�����¸����еĹ����豸*/
}RRM_WTP_T ;


/*RRM������Դ������*/
typedef struct RRM_DOMAIN_TAG{
	/*RRM_WTP_T * pstWtpList[] ;*/ 	/*���еĹ���WTP�豸*/

	UINT32 bChanReelect ;		/*1��������Ƶ����ѡ���ﴦ����*/
	UINT32 ulTimeLatestReelect ;	/*�����豸����л�Ƶ��ʱ��*/
	UINT32 ulChanReqAcId[8] ;	/*����Ƶ����ѡ�����е�AC*/
}RRM_DOMAIN_T ;


typedef struct{
	UINT32 ulAcId ;

	RRM_DOMAIN_T stDomain ;	/*AC2.0�򻯴�������ACΪһ����*/
	RRM_GDEV_T * pstScanList ;	/*��ʱ��Ϊ���豸����ÿ������5����ܷ���ͬƵ/��Ƶ������Ϣ*/
	UINT32 ulTimeLatestNeighReq ;
}RRM_AC_T ;


/******************************** ȫ�ֱ������� ********************************/


/******************************** �ⲿ����ԭ������ ****************************/
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

/********************************** ����ԭ������ ******************************/


#ifdef __cplusplus
}
#endif

#endif /* __RRM_APP_H */
/******************************* ͷ�ļ����� **********************************/
