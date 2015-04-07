/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  接纳控制模块主控头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/*
2009-4-10
需求变更：
1、负荷均衡只在GDEV层处理，VAP/WTP/AC层不作负荷均衡处理；
2、但负荷均衡接口配置存于WTP层，再由WTP分发到GDEV，不再存于VAP/AC中；
3、负荷均衡QOS配置更改为流量，但本阶段暂不实现；
*/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_ACM_PROC_H
#define  _AC_ACM_PROC_H

/******************************** 宏定义 *************************************/
#if 0
#define AC_ACM_AC_RSV_STA       2           /* AC预留终端数 */
#define AC_ACM_WTP_RSV_STA      2           /* WTP预留终端数 */
#define AC_ACM_IF_RSV_STA       2           /* 接口预留终端数 */
#define AC_ACM_VAP_RSV_STA      2           /* VAP预留终端数 */
#endif

#define ACM_MAC_LIST_NUM	128
#define ACM_MAC_POLICY_ADD	0
#define ACM_MAC_POLICY_DEL	1
#define ACM_MAC_POLICY_MODIFY	2

/******************************** 结构体定义 *********************************/
typedef AC_DEVM_LOADBALANCE_CONFIG_T ACM_CONFIG_T ;

/*无线设备ID列表*/
typedef struct ACM_GDEVID_LIST_TAG{
	AC_VDEVID_T stGdevId ;
	struct ACM_GDEVID_LIST_TAG * pstNext ;
}ACM_GDEVID_LIST_T ;

/* AC接纳控制策略 */
typedef struct {
	UINT32  ulAcId;         /* AC ID */

    ACM_CONFIG_T stAcmCfg ;	/*接入控制配置策略*/
    AC_DEVM_VLANACCMACPOLICY_CONFIG_T stMacPolicy;
	UINT32 ulMacPolicyValid;
	AC_DEVM_VLANACCMAC_CONFIG_T stMacList[ACM_MAC_LIST_NUM];
	UINT32 ulMacListNum;
	
    UINT32 ulUserMaxSwitch;
    UINT32 ulUserMax ;
	
    UINT32 lUserCurrent ;	/*当前接入的用户数目*/
    UINT32 ulQosCurrent ;	/*当前接入的最低QOS需求总和,Kbps*/
} ACM_AC_T;

/* VAP接纳控制策略 */
typedef struct {
    UINT32      ulValid;        /* 有效标记 */
    AC_VAPID_T  stVapId;        /* VAP ID */

    ACM_CONFIG_T stAcmCfg ;	/*接入控制配置策略*/
	
    UINT32 lUserCurrent ;	/*当前接入的用户数目*/
    UINT32 ulQosCurrent ;	/*当前接入的最低QOS需求总和,Kbps*/
} ACM_VAP_T;

/*组设备接纳控制策略 */
typedef struct {
    UINT32      		ulValid;		/* 有效标记 */
    AC_VDEVID_T   stGdevId;	/* 组设备 ID */
	
    ACM_CONFIG_T stAcmCfg ;	/*接入控制配置策略*/
    ACM_GDEVID_LIST_T * pstNeighborList ;
	
    UINT32 lUserCurrent ;	/*当前接入的用户数目*/
    UINT32 ulQosCurrent ;	/*当前设备的流量，bps*/
	
    ACM_VAP_T astVapAcmCfg[AC_VAP_NUM_MAX_PER_IF];
} ACM_GDEV_T;

/* WTP接纳控制策略 */
typedef struct {
    UINT32      ulValid;        /* 有效标记 */
    AC_WTPID_T  stWtpId;        /* WTP ID */
	
    ACM_CONFIG_T stAcmCfg ;	/*接入控制配置策略*/
	
    UINT32 lUserCurrent ;	/*当前接入的用户数目*/
    UINT32 ulQosCurrent ;	/*当前接入的最低QOS需求总和,Kbps*/
	
    ACM_GDEV_T  astGdevAcm[AC_VDEV_NUM_MAX_PER_WTP];
} ACM_WTP_T;

/******************************** 全局变量声明 ********************************/

/******************************** 外部函数原形声明 ****************************/


/********************************** 函数原形声明 ******************************/

#endif /* _AC_LCS_PROC_H */
/******************************* 头文件结束 **********************************/

