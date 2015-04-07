/*
 */

#ifndef _L2WCTL_H
#define _L2WCTL_H


#ifdef TRUE
#undef TRUE
#define TRUE 1
#else
#define TRUE 1
#endif

#ifdef FALSE
#undef FALSE
#define FALSE 0
#else
#define FALSE 0
#endif

#define SIOCGAC		0x8984		/* 802.1Q VLAN support		*/
#define SIOCSAC		0x8985		/* 802.1Q VLAN support		*/

#define L2W_VDEV_ID_MIN		0
#define L2W_VDEV_ID_MAX 		15

/* 设备类型定义*/
#define L2W_DEV_TYPE_AC			0
#define L2W_DEV_TYPE_AP			1
#define L2w_DEV_TYPE_INVALID		0xFF

/* 端口类型定义*/
#define L2W_PORT_TYPE_AP_ACCESS	0	/* AP 业务口*/
#define L2W_PORT_TYPE_AP_BEAR		1	/* AP承载口*/
#define L2W_PORT_TYPE_AC_FITLAN	2	/* AC FIT-LAN口*/
#define L2W_PORT_TYPE_AC_FATLAN	3	/* AC FAT-LAN口*/
#define L2W_PORT_TYPE_AC_L2WAN	4	/* AC L2-WAN口*/
#define L2W_PORT_TYPE_AC_L3WAN	5	/* AC L2-WAN口*/
#define L2W_PORT_TYPE_VDEV		6	/* 虚设备端口*/
#define L2W_PORT_TYPE_AC_HYBRID	7	/* 混合模式端口*/	
#define L2W_PORT_TYPE_INVALID		0xFF

/* 桥类型定义*/
#define L2W_BR_TYPE_AP_ACCESS		0	/* AP接入桥*/
#define L2W_BR_TYPE_AP_BEAR		1	/* AP承载桥*/
#define L2W_BR_TYPE_AC_BEAR		2	/* AC承载桥*/
#define L2W_BR_TYPE_AC_L2WAN		3	/* AC L2-WAN桥 */
#define L2W_BR_TYPE_AC_L3WAN		4	/* AC L3-WAN桥 */
#define L2W_BR_TYPE_INVALID		0xFF

/* 报文类型定义*/
#define L2W_PKT_TYPE_UNICAST			1
#define L2W_PKT_TYPE_MULTICAST		2
#define L2W_PKT_TYPE_BROADCAST		3


/* HASH Size */
#define L2W_DEV_HASH_SIZE				256	/* 设备HASH桶大小 */
#define L2W_PORTUSER_HASH_SIZE		32	/* 端口下的用户HASH桶大小*/

#define L2W_BR_HASH_SIZE				256
#define L2W_PORT_HASH_SIZE			256
#define L2W_USER_HASH_SIZE			256

#if 0
/* device id 结构*/
/*
12bit	6bit		6bit		8bit
devid	0		0		0
*/
#define L2W_DEVID_MIN			0
#define L2W_DEVID_MAX			0xFFF
#define L2W_DEVID_MASK			0xFFF00000
#define L2W_DEVID_MOV_BITS	24

/* bridge id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		0		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0x3F
#define L2W_BRID_MASK		0xFC000
#define L2W_BRID_MOV_BITS	14

/* port id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	0
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0x3F
#define L2W_PORTID_MASK		0x3F00
#define L2W_PORTID_MOV_BITS	8

/* user id 结构*/
/*
12bit	6bit		6bit		8bit
devid	brid		portid	userid
*/
#define L2W_USERID_MIN			0
#define L2W_USERID_MAX			0xFF
#define L2W_USERID_MASK		0xFF
#define L2W_USERID_MOV_BITS	0
#endif

/* device id 结构*/
/*
12bit	4bit		16bit
devid	0		0
*/
#define L2W_DEVID_MIN			0
#define L2W_DEVID_MAX			0xFFF
#define L2W_DEVID_MASK			0xFFF00000
#define L2W_DEVID_MOV_BITS	20

/* bridge id 结构*/
/*
12bit	4bit		16bit
devid	brid		0
*/
#define L2W_BRID_MIN		0
#define L2W_BRID_MAX		0xF
#define L2W_BRID_MASK		0xF0000
#define L2W_BRID_MOV_BITS	16

/* port id 结构*/
/*
12bit	4bit		16bit		
devid	brid		portid	
*/
#define L2W_PORTID_MIN			0
#define L2W_PORTID_MAX			0xFFFF
#define L2W_PORTID_MASK		0xFFFF
#define L2W_PORTID_MOV_BITS	0

#define  L2W_FATAL    		5
#define  L2W_FAIL    			4
#define  L2W_ERROR    		3
#define  L2W_WARNING  		2
#define  L2W_INFO     		1
#define  L2W_DETAIL   		0

/*
#define MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ARG(x) ((unsigned char*)(x))[0], ((unsigned char*)(x))[1], ((unsigned char*)(x))[2], ((unsigned char*)(x))[3], ((unsigned char*)(x))[4], ((unsigned char*)(x))[5]

#define IP_FMT	"%u.%u.%u.%u"
#define IP_ARG(x) ((unsigned char*)(x))[0], ((unsigned char*)(x))[1], ((unsigned char*)(x))[2], ((unsigned char*)(x))[3]
*/

#endif

