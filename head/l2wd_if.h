/*
 */

#ifndef _L2WD_IF_H
#define _L2WD_IF_H

#define AC_IF_NUM_MAX		32		/* AC����˿���Ŀ*/

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
	unsigned char aucBearIp[4];		/* ����IP */
	unsigned char aucBearMask[4];		/* ����IP����*/
	unsigned char aucTrafficIp[4];		/* ҵ��IP */
	unsigned char aucTrafficMask[4];	/* ҵ��IP����*/
	unsigned char aucWanIp[4];		/* WAN IP */
	unsigned char aucWanMask[4];		/* WAN IP����*/
} AC_SYS_BASICCFG_T;

#define L2W_AC_CFG_FILE_NAME	"/tmp/accfg"

#define L2W_AP_BR_ID_ACCESS		0		/* AP �����ű��*/
#define L2W_AP_BR_ID_BEAR			1		/* AP�����ű��*/

#define L2W_AP_VDEV_ID				0		/* AP��˿ڱ��*/

#define L2W_AP_BR_NAME_ACCESS	"mesh1"	/* AP����������*/
#define L2W_AP_BR_NAME_BEAR		"mesh0"	/* AP����������*/

#define L2W_AP_VDEV_NAME			"vdev_0"	/* AP�����豸����*/

#define L2W_AC_BR_ID_BEAR			0		/* AC�����ű��*/
#define L2W_AC_BR_ID_L2WAN		1		/* AC L2-WAN�ű��*/
#define L2W_AC_BR_ID_L3WAN		2		/* AC L3-WAN�ű��*/

#define L2W_AC_VDEV_ID				0		/* AC��˿ڱ��*/

#define L2W_AC_BR_NAME_BEAR		"br0"			/* AC����������: FIT-LAN ��*/
#define L2W_AC_BR_NAME_L2WAN		"br1"			/* AC L2-WAN ������*/
#define L2W_AC_BR_NAME_L3WAN		"br2"			/* AC L3-WAN������*/
#define L2W_AC_BR_NAME_MS			"br3"			/* AC����ͨ��������*/

#define L2W_AC_VDEV_NAME			"vdev_0"	/* AC�����豸����*/

/* �˿�ID�滮*/
/*
AC 0~31 ��������
WTP 0~3 ADHOC
	4~7	��������
	8~23 VAP
*/

#define ADHOC_IFID(ulWtpId, ulVdevId, ulAdhocId)		((ulAdhocId))
#define ENET_IFID(ulWtpId, ulEnetId)					(4 + (ulEnetId))
#define VAP_IFID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define VDEV_IFID(ulWtpId, ulVdevId)					(24 + (ulVdevId))

int catchSigPipe(int sig);

#endif

