/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  射频资源管理模块/IOCTL头文件
* 修改历史: 
* 2009-3-17     叶恩云            新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/
#ifndef  __RRM_IOCTL_H
#define  __RRM_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif


/******************************** 宏定义 *************************************/
#ifndef IFNAMSIZ
#define IFNAMSIZ	16
#endif


/******************************** 结构体定义 *********************************/
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


/******************************** 全局变量声明 ********************************/

/******************************** 外部函数原形声明 ****************************/

/********************************** 函数原形声明 ******************************/
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
/******************************* 头文件结束 **********************************/