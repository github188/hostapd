/******************************************************************************
* COPYRIGHT GBCOM
* ���н������ݽṹ����
*******************************************************************************
******************************************************************************/

#ifndef L2W_DATA_H
#define L2W_DATA_H

/******************************************************************************/
/*�궨�忪ʼ*/

/* �豸���Ͷ���*/
#define L2W_DEV_TYPE_AC			0
#define L2W_DEV_TYPE_AP			1
#define L2w_DEV_TYPE_INVALID		0xFF

/* �˿����Ͷ���*/
#define L2W_PORT_TYPE_AP_ACCESS	0	/* AP ҵ���*/
#define L2W_PORT_TYPE_AP_BEAR		1	/* AP���ؿ�*/
#define L2W_PORT_TYPE_AC_FITLAN	2	/* AC FIT-LAN��*/
#define L2W_PORT_TYPE_AC_FATLAN	3	/* AC FAT-LAN��*/
#define L2W_PORT_TYPE_AC_L2WAN	4	/* AC L2 WAN��*/
#define L2W_PORT_TYPE_AC_L3WAN	5	/* L3 WAN����ӵ�����*/
#define L2W_PORT_TYPE_VDEV		6	/* ���豸�˿�*/
#define L2W_PORT_TYPE_AC_HYBRID	7	/* ���ģʽ�˿�*/	
#define L2W_PORT_TYPE_INVALID		0xFF

/* �����Ͷ���*/
#define L2W_BR_TYPE_AP_ACCESS		0	/* AP������*/
#define L2W_BR_TYPE_AP_BEAR		1	/* AP������*/
#define L2W_BR_TYPE_AC_BEAR		2	/* AC������*/
#define L2W_BR_TYPE_AC_L2WAN		3	/* AC L2-WAN�� */		
#define L2W_BR_TYPE_AC_L3WAN		4	/* AC L3-WAN�� */		
#define L2W_BR_TYPE_INVALID		0xFF

/* �������Ͷ���*/
#define L2W_PKT_TYPE_UNICAST			1
#define L2W_PKT_TYPE_MULTICAST		2
#define L2W_PKT_TYPE_BROADCAST		3

/* �û����Ͷ���*/
#define L2W_USER_TYPE_WIRELESS		0	/* �����û�*/
#define L2W_USER_TYPE_WIRE			1	/* �����û�*/

/* MAC���˿���ȡֵ�궨��*/
#define L2W_MAC_FILTER_SWITCH_DISABLE	0	/* �ر�*/
#define L2W_MAC_FILTER_SWITCH_ENABLE		1	/* ��*/

/* MAC��������*/
#define L2W_MAC_FILTER_TYPE_WHITE			0	/* ������*/
#define L2W_MAC_FILTER_TYPE_BLACK			1	/* ������*/


/* HASH Size */
#define L2W_DEV_HASH_SIZE				256		/* �豸HASHͰ��С */
#define L2W_BR_HASH_SIZE				256		/* ��HASHͰ��С*/
#define L2W_PORT_HASH_SIZE			256		/* �˿�HASHͰ��С*/
#define L2W_USER_HASH_SIZE			256		/* �����û�HASHͰ��С*/
#define L2W_VLAN_HASH_SIZE			256		/* VLAN HASHͰ��С*/
#define L2W_MAC_HASH_SIZE				256		/* MAC HASHͰ��С*/

/* device id �ṹ*/
/*
12bit	4bit		16bit
devid	0		0
*/
#define L2W_DEVID_MIN			0
#define L2W_DEVID_MAX			0xFFF
#define L2W_DEVID_MASK			0xFFF00000
#define L2W_DEVID_MOV_BITS	20

/* bridge id �ṹ*/
/*
12bit	4bit		16bit
devid	brid		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0xF
#define L2W_BRID_MASK		0xF0000
#define L2W_BRID_MOV_BITS	16

/* port id �ṹ*/
/*
12bit	4bit		16bit		
devid	brid		portid	
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0xFFFF
#define L2W_PORTID_MASK		0xFFFF
#define L2W_PORTID_MOV_BITS	0


#if 0
/* bridge id �ṹ*/
/*
12bit	6bit		6bit		8bit
devid	brid		0		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0x3F
#define L2W_BRID_MASK		0xFC000
#define L2W_BRID_MOV_BITS	14

/* port id �ṹ*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	0
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0x3F
#define L2W_PORTID_MASK		0x3F00
#define L2W_PORTID_MOV_BITS	8

/* user id �ṹ*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	userid
*/
#define L2W_USERID_MIN			0
#define L2W_USERID_MAX			0xFF
#define L2W_USERID_MASK		0xFF
#define L2W_USERID_MOV_BITS	0
#endif

/* vlan id �ṹ*/
#define L2W_VLANID_MIN		1
#define L2W_VLANID_MAX		4094

#define L2W_VLANID_INVALID	0xFFFF

#define VAP_PORTID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define REAL_DEVID(ulDevId)			(((ulDevId)&L2W_DEVID_MASK) >> L2W_DEVID_MOV_BITS)
#define FAKE_DEVID(ulDevId)			((ulDevId&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS)

#define REAL_BRID(ulBrId)				(((ulBrId)&L2W_BRID_MASK) >> L2W_BRID_MOV_BITS)
#define FAKE_BRID(ulDevId,ulBrId)		((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
									  (((ulBrId)&L2W_BRID_MAX) << L2W_BRID_MOV_BITS))

#define REAL_PORTID(ulPortId)			(((ulPortId)&L2W_PORTID_MASK) >> L2W_PORTID_MOV_BITS)
#define FAKE_PORTID(ulDevId,ulPortId)	((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
							  		  (((ulPortId)&L2W_PORTID_MAX) << L2W_PORTID_MOV_BITS))

#if 0
#define REAL_USERID(ulUserId)		(((ulUserId)&L2W_USERID_MASK) >> L2W_USERID_MOV_BITS)
#define FAKE_USERID(ulDevId,ulPortId,ulUserId)	((((ulDevId)&L2W_DEVID_MAX) << L2W_DEVID_MOV_BITS) | \
							  		  		  (((ulPortId)&L2W_PORTID_MAX) << L2W_PORTID_MOV_BITS) |\
							  		  		  (((ulUserId)&L2W_USERID_MAX) << L2W_USERID_MOV_BITS))
#endif



extern L2W_PKT_STATS_T gstFrgStat;
extern unsigned long gstCapwapMtu;
/*�궨�����*/
/******************************************************************************/


/******************************************************************************/
/* ���ݽṹ���忪ʼ*/
/* �豸*/
typedef struct 
{
	u32	ulDevId;			/* �豸���*/
	u32	ulDevType;		/* �豸���� */
	char	acDevName[IFNAMSIZ];	
	u8	aucDevIp[4];
	/* 2011-1-12 ymt add:count */
	u32	ulUlPkts;			/*���а��� */
	u32	ulDlPkts;			/*���а��� */
	u32	ulUlGigaWords;	/*�����ֽ�������λ4GByte */
	u32	ulUlBytes;		/*�����ֽ�������λByte */
	u32	ulDlGigaWords;	/*�����ֽ�������λ4GByte */
	u32	ulDlBytes;		/*�����ֽ�������λByte */
	/* 2011-1-12 ymt  end*/
	struct hlist_node	idHlist;		/* device index hash chain */
	struct hlist_node	nameHlist;	/* device name hash chain */
	struct list_head	portList;		/* �˿���*/
	struct list_head	brList;		/* ����*/
    u16 usDevSrcPort;        /*HDD WTP�豸 Դ�˿ں� 2013-4-2 */
    u8  capwapfrag;  /* �Ƿ���capwap��Ƭ���ģ�1: �ǣ� 0: ����*/
}  L2W_DEVICE_T;

typedef struct
{
	u32	ulDevId;			/* real dev id */
	u32	ulIfId;			/* real if id */
	u32	ulUserVlanId;	/* �ڲ�VLAN ID */
	u32	ulNestVlanId;	/* ���VLAN ID */
	
	struct hlist_node	mapHlist;	/* vlan id hash chain */
} L2W_QINQMAP_T;
/* ��*/
typedef struct 
{
	u32	ulBrId;					/* �ű��*/
	u32	ulBrType;				/* ������*/
	char acBrName[IFNAMSIZ];	
	u8	aucBrIp[4];				/* IP */
	L2W_DEVICE_T	*pstDev;	/* ���������豸*/

	struct list_head	list;			/* ��������ͬһ�豸�µ���*/
	
	struct hlist_node	idHlist;		/* br index hash chain */
	struct hlist_node	nameHlist;	/* br name hash chain */
	struct list_head	portList;		/* �˿���*/
}  L2W_BRIDGE_T;

/* �˿�*/
typedef struct 
{
	u32	ulPortId;
	u32	ulPortType;
	char	acPortName[IFNAMSIZ];
	char	acSsid[32];

	L2W_DEVICE_T	*pstDev;
	L2W_BRIDGE_T	*pstBr;

	struct list_head	devList;			/* �û�����ͬһ�豸�µĶ˿�*/
	struct list_head	brList;			/* ��������ͬһ���µĶ˿�*/
	
	struct hlist_node	idHlist;			/* port index hash chain */
	struct hlist_node	nameHlist;		/* port name hash chain */	
	struct hlist_head	userHList[L2W_USER_HASH_SIZE];	/* �û�HASH*/

#if 0
	struct list_head	vlanIfIfList;	/* ��������ͬһ�˿��µ�VlanIfMap */
#endif

#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
}  L2W_PORT_T;

typedef struct
{
	u32	ulUserPri;					/* �û����ȼ� */
	u32	ulUpBand;					/* �û����б�֤����*/
	u32	ulUpBandMax;				/* �û�����������*/
	u32	ulDownBand;				/* �û����б�֤����*/
	u32	ulDownBandMax;				/* �û�����������*/
} L2W_USER_QOS_T;

/* �����û�*/
typedef struct 
{
	u8	aucMac[6];				/* �û�MAC */
	u8	aucRsv[2];				/* ����ֽ�*/
	u8	aucIp[4];				/* IP */
	L2W_USER_QOS_T	stQos;		/* �û�QOS */
	u32	ulVlanId;				/* �û�������VLAN */
	u32	ulCertState;				/* �û���֤״̬*/
	u32	ulUserType;				/* �û�����*/
	
	L2W_PORT_T		*pstPort;	/* �û�������port */
    u32	ulWtpId;
	u32	ulVapId;
	char	acSsid[32];				/* �û�������SSID */	

	/* 2011-1-12 ymt add:count*/
	u32	ulUlPkts;			/*���а��� */
	u32	ulDlPkts;			/*���а��� */
	u32	ulUlGigaWords;		/*�����ֽ�������λ4GByte */
	u32	ulUlBytes;			/*�����ֽ�������λByte */
	u32	ulDlGigaWords;		/*�����ֽ�������λ4GByte */
	u32	ulDlBytes;			/*�����ֽ�������λByte */
	/* 2011-1-12 ymt end*/

	struct hlist_node	macHlist;		/* user mac hash chain */
	struct hlist_node	macPortHlist;	/* user mac hash chain in the port */
	struct hlist_node	ipHlist;			/* user ip hash chain */
#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
}  L2W_USER_T;

/* IDS�����û�*/
typedef struct
{
	u8	aucMac[6];				/* �û�MAC */
	u8	aucRsv[2];				/* ����ֽ�*/

	struct hlist_node	macHlist;		/* user mac hash chain */
} L2W_IDSUSER_T;

/* VLAN */
typedef struct 
{
	u32	ulVlanId;				/* VLAN ID */
	u32	ulVlanPrio;				/* VLAN���ȼ�*/
	char	acVlanName[32];			/* VLAN����*/
	u32	ulEnableIsolate;			/* �û����� */

	u32	ulMacFilterSwitch;		/* MAC���˹��ܿ���0/1:�ر�/��*/
	u32	ulMacFilterType;			/* MAC�������� 0/1: ������/������*/

	struct hlist_node	idHlist;		/* vlan id hash chain */

#if 0
	struct list_head	vlanIfVlanList;		/* ��������ͬһVLAN�µ�VlanIfMap */
	struct list_head	vlanMacVlanList;		/* ��������ͬһVLAN�µ�VlanMacMap */
#endif	
} L2W_VLAN_T;

/* IF-VLAN ӳ���ϵ�ṹ�嶨��*/
typedef struct
{
	u32	ulVlanId;
	u32	ulDevId;	/* real dev id */
	u32	ulIfId;	/* real if id */

	struct hlist_node mapHlist;	/* vlan id hash chain */

#if 0
	struct list_head	vlanIfIfList;		/* ��������ͬһ�˿��µ�VlanIfMap */
	struct list_head	vlanIfVlanList;	/* ��������ͬһVLAN�µ�VlanIfMap */
#endif	
}L2W_VLANIFMAP_T;

/* MAC-VLANӳ���ϵ�ṹ�嶨��*/
typedef struct 
{
	u8	aucMac[6];					/* MAC��ַ */
	u8	aucRsv[2];					/* ����ֽ�*/
	u32	ulVlanId;

	struct hlist_node	mapHlist;		/* user mac-vlanid map hash chain */

#if 0
	struct list_head	vlanMacVlanList;		/* ��������ͬһVLAN�µ�VlanMacMap */
	struct list_head	vlanMacMacList;		/* ��������ͬһMAC�µ�VlanMacMap */
#endif
} L2W_VLANMACMAP_T;

typedef struct
{
	char	acSsid[32];
	u32	ulVlanId;

	struct hlist_node mapHlist;
}L2W_VLANSSIDMAP_T;

typedef struct 
{
	u8	aucMac[6];					/* MAC��ַ */
	u8	aucRsv[2];					/* ����ֽ�*/
	u32	ulVlanId;

	struct hlist_node mapHlist;					/* user mac-vlanid map hash chain */
} L2W_VLANACCMACMAP_T;


/* IGMP Proxy ���ýṹ�嶨��*/
typedef struct 
{
	u32	ulIgmpProxy;
} L2W_IGMPPROXY_T;

/* IGMP Snoop���ýṹ�嶨��*/
typedef struct 
{
	u32	ulIgmpSnoopSwitch;			/* �Ƿ���Ч */
	u32	ulRtPortTimer;				/* ·�����˿��ϻ���ʱ�� */
	u32	ulMemberPortTimer;			/* ��Ա�˿��ϻ���ʱ�� */	
}L2W_IGMPSNOOP_T;

/* MAC-IPӳ���*/
typedef struct
{
	u8	aucMac[6];				/* MAC */
	u8	aucIp[4];				/* IP */
	char	acIfName[16];

	struct hlist_node	macHlist;		/* mac hash chain */
	struct hlist_node	ipHlist;			/* ip hash chain */
} L2W_MACIPMAP_T;

/* 2010-8-10 ���� */
/* ͬһ���͵Ķ˿ڼ�ת�����ƿ���*/
typedef struct
{
	u32	ulFitLanForward;		/* 0: ��ֹת�� 1:����ת��*/
	u32	ulFatLanForward;	/* 0: ��ֹת�� 1:����ת��*/
	u32	ulL2WanForward;	/* 0: ��ֹת�� 1:����ת��*/
	u32	ulL3WanForward;	/* 0: ��ֹת�� 1:����ת��*/
} L2W_FORWARD_SWITCH_T;

/* ���ݽṹ�������*/
/******************************************************************************/

#endif

/******************************* end **********************************/

