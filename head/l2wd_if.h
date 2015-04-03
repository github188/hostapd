/*
 */

#ifndef _L2WD_IF_H
#define _L2WD_IF_H

#define AC_IF_NUM_MAX		32		/* AC物理端口数目*/

typedef struct {
	unsigned long ulValid;
	unsigned long ulIfId;
	char	acIfName[32];
	unsigned long ulIfType;
	unsigned long ulIfState;
} AC_SYS_IFCFG_T;

typedef struct {
	unsigned long ulAcId;
	char	acName[32];
	unsigned char aucBearIp[4];		/* 承载IP */
	unsigned char aucBearMask[4];		/* 承载IP掩码*/
	unsigned char aucTrafficIp[4];		/* 业务IP */
	unsigned char aucTrafficMask[4];	/* 业务IP掩码*/
	unsigned char aucWanIp[4];		/* WAN IP */
	unsigned char aucWanMask[4];		/* WAN IP掩码*/
} AC_SYS_BASICCFG_T;

#define L2W_AC_CFG_FILE_NAME	"/tmp/accfg"

#define L2W_AP_BR_ID_ACCESS		0		/* AP 接入桥编号*/
#define L2W_AP_BR_ID_BEAR			1		/* AP承载桥编号*/

#define L2W_AP_VDEV_ID				0		/* AP虚端口编号*/

#define L2W_AP_BR_NAME_ACCESS	"mesh1"	/* AP接入桥名称*/
#define L2W_AP_BR_NAME_BEAR		"mesh0"	/* AP承载桥名称*/

#define L2W_AP_VDEV_NAME			"vdev_0"	/* AP的虚设备名称*/

#define L2W_AC_BR_ID_BEAR			0		/* AC承载桥编号*/
#define L2W_AC_BR_ID_L2WAN		1		/* AC L2-WAN桥编号*/
#define L2W_AC_BR_ID_L3WAN		2		/* AC L3-WAN桥编号*/

#define L2W_AC_VDEV_ID				0		/* AC虚端口编号*/

#define L2W_AC_BR_NAME_BEAR		"br0"			/* AC承载桥名称: FIT-LAN 桥*/
#define L2W_AC_BR_NAME_L2WAN		"br1"			/* AC L2-WAN 桥名称*/
#define L2W_AC_BR_NAME_L3WAN		"br2"			/* AC L3-WAN桥名称*/
#define L2W_AC_BR_NAME_MS			"br3"			/* AC主备通信桥名称*/

#define L2W_AC_VDEV_NAME			"vdev_0"	/* AC的虚设备名称*/

/* 端口ID规划*/
/*
AC 0~31 物理网口
WTP 0~3 ADHOC
	4~7	物理网口
	8~23 VAP
*/

#define ADHOC_IFID(ulWtpId, ulVdevId, ulAdhocId)		((ulAdhocId))
#define ENET_IFID(ulWtpId, ulEnetId)					(4 + (ulEnetId))
#define VAP_IFID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define VDEV_IFID(ulWtpId, ulVdevId)					(24 + (ulVdevId))

int catchSigPipe(int sig);

#endif

