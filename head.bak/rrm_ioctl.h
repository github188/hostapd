/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ��Ƶ��Դ����ģ��/IOCTLͷ�ļ�
* �޸���ʷ: 
* 2009-3-17     Ҷ����            �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/
#ifndef  __RRM_IOCTL_H
#define  __RRM_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif


/******************************** �궨�� *************************************/
#ifndef IFNAMSIZ
#define IFNAMSIZ	16
#endif


/******************************** �ṹ�嶨�� *********************************/
typedef enum
{
	IOCTL_DISASSOC_OLDEST = 19,
	IOCTL_LOCALSCAN_SET = 50,
	IOCTL_LOCALSCAN_GET = 51,
	IOCTL_LOCALAP_GET = 52,
	IOCTL_CHANNEL_REELECT = 53,
	IOCTL_NEIGHBORAP_GET = 54,
	IOCTL_GET_FLOW_STATS = 55,

	IOCTL_POWERMIN_SET = 60,
	IOCTL_POWER_DOWN = 61,
	IOCTL_POWER_UPMAX = 62,
	IOCTL_POWER_UP = 65,
}IOCTL_TYPE_E;


typedef struct
{
	IOCTL_TYPE_E enIoctlType;
	union
	{
		NEIGHBOR_AP_LIST_T stNeighborApList ;
		int local_scan_on ;
		u_int32_t ulRescan ;
		u_int32_t ulPowerCur ;
		u_int32_t ulFlowStats ;		/*bps*/
		u_int32_t ulDisassocOldest ;
	}unData;
}IOCTL_DATA_T;


/******************************** ȫ�ֱ������� ********************************/

/******************************** �ⲿ����ԭ������ ****************************/

/********************************** ����ԭ������ ******************************/
int rrm_neighborap_get(const char * pcIfName, UINT32 ulNameLength, NEIGHBOR_AP_LIST_T * pstData) ;
int rrm_reelect_channel(const char * pcIfName, UINT32 ulNameLength, UINT32 * pulRescan) ;
int rrm_ioctl_power_adjust(const char * pcIfName, UINT32 ulNameLength, UINT32 ulType, UINT32 * pulPowerCur) ;
int rrm_power_upmax(const char * pcIfName, UINT32 ulNameLength) ;
int rrm_flowstats_get(const char * pcIfName, UINT32 ulNameLength, UINT32 * pulFlowStats) ;
int rrm_disassoc_cmd(const char * pcIfName, UINT32 ulNameLength, UINT32 * pulDisassoc) ;


#ifdef __cplusplus
}
#endif

#endif /* __RRM_IOCTL_H */
/******************************* ͷ�ļ����� **********************************/