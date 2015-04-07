
#ifndef _L2WCTL_PUBLIC_H
#define _L2WCTL_PUBLIC_H

//#define DAEMON 

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif


#ifdef DAEMON
#define  L2W_P_FATAL    		3
#define  L2W_P_FAIL    		3
#define  L2W_P_ERROR    		3
#define  L2W_P_WARNING  	3
#define  L2W_P_INFO     		3
#define  L2W_P_DETAIL   		3
#else
/* define self printf : add funtion name and line */
#define  L2W_P_FATAL    		5
#define  L2W_P_FAIL    		4
#define  L2W_P_ERROR    		3
#define  L2W_P_WARNING  	3
#define  L2W_P_INFO     		3
#define  L2W_P_DETAIL   		3
#endif

#ifdef APP_PROJ_AC
#ifndef  HAVE_SYSLOG
#define HAVE_SYSLOG
#endif
#endif

#ifdef HAVE_SYSLOG
#define l2w_printf(level, format, arg...) do{\
	syslogu(LM_L2W, level,format, ##arg);	\
}while(0);
#else
#define l2w_printf(level, format, arg...) do{\
	syslog(level,format, ##arg);	\
}while(0);	
#endif

#ifdef HAVE_SYSLOG
#define l2wctl_printf(level, format, arg...) do{\
	printf(format, ##arg);            \
}while(0);
#else
#define l2wctl_printf(level, format, arg...) do{\
	printf(format, ##arg);            \
}while(0);	
#endif

#define __WAPI_AC_WPI__

#define L2W_VDEV_MAX_PER_IOCTL		4
#define L2W_DEV_MAX_PER_IOCTL			8
#define L2W_BR_MAX_PER_IOCTL			8
#define L2W_IF_MAX_PER_IOCTL			8
#define L2W_BRIF_MAX_PER_IOCTL		8
#define L2W_USER_MAX_PER_IOCTL		8
#define L2W_VLAN_MAX_PER_IOCTL		8
#define L2W_VLANIF_MAX_PER_IOCTL		8
#define L2W_VLANMAC_MAX_PER_IOCTL	8
#define L2W_VLANSSID_MAX_PER_IOCTL	8
#define L2W_VLANACCMAC_MAX_PER_IOCTL	8
#define L2W_MACIP_MAX_PER_IOCTL		32

#define L2W_BR_MAX_PER_DEV			4
#define L2W_IF_MAX_PER_DEV			8

#define L2W_IOCTL_GET_NOTFINISH	0	/* 未结束*/
#define L2W_IOCTL_GET_FINISH		1	/* 读取结束*/

#define L2W_DISABLE		0		/* 禁用*/
#define L2W_ENABLE		1		/* 启用*/

/*  与用户态交互的消息号定义*/
#define L2W_UK_UPDATE_USERIP_MSG		1			/* 更新用户IP */
#define L2W_UK_ADD_USER_MSG			2			/* 内核态通知用户态新增用户:胖AC */
#define L2W_UK_DEL_USER_MSG			3			/* 内核态通知用户态删除用户:胖AC */

/* WTP运行模式*/
#define L2W_WTP_RUNMODE_CENTFORWARD	1	/* 集中转发*/
#define L2W_WTP_RUNMODE_LOCALFORWARD	2	/* 本地转发*/

#define AC_PORTID(ulPortId,ulVlanId)	((((ulPortId)&0x000F)<<12)+((ulVlanId)&0x0FFF))
#define AC_REAL_PORTID(ulPortId)		(((ulPortId)>>12)&0x000F)
#define AC_REAL_VLANID(ulPortId)		((ulPortId)&0x0FFF)

/*******************************************************************************/
/* 引用自ac_devm_public.h的结构体定义开始*/

/* 引用自ac_devm_public.h的结构体定义结束*/
/*******************************************************************************/

/*******************************************************************************/

#ifdef __WAPI_AC_WPI__

#define WAPI_AC_WPI_KEYBUF_SIZE	16  /*wapi 加密密钥长度*/
#define WAPI_AC_WPI_MICBUF_SIZE	16  /*wapi 完整性密钥长度*/
#define WAPI_AC_WPI_PN_LEN             16  /*wapi 协议PN长度*/
#define WAPI_AC_WPI_MIC_LEN           16  /*wapi 协议MIC长度*/


struct wapi_ac_key_stats /*端口相关的统计*/
{
	unsigned int wapi_skb_adjuest_by_head;
	unsigned int wapi_skb_adjuest_by_tail;
	unsigned int wapi_skb_adjuest_fail;
	unsigned int wapi_skb_enmic_error;
	unsigned int wapi_skb_encap_error;
	unsigned int wapi_skb_recv_unenc_data;
	unsigned int wapi_skb_recv_wapiethtype;
	unsigned int wapi_skb_recv_not_wapiethtype; /*非wapi 以太网类型解密*/
	unsigned int wapi_skb_recv_not_to_ds;

	unsigned int wapi_skb_decap_error;
	unsigned int wapi_skb_demic_error;

	unsigned int wapi_skb_not_wapi_user;
	unsigned int wapi_skb_not_wapi_port;
	unsigned int wapi_skb_recv_pn_error;
	unsigned int wapi_skb_decrypt_error;
	unsigned int wapi_skb_cmp_mic_error;
};


struct wapi_ac_wpi_key /*WAPI 密钥结构*/
{
	
	unsigned short wk_keyix; /*密钥ID*/
	unsigned char  wk_flags;
		unsigned char ucKid_temp;
	
		unsigned char  wk_key[WAPI_AC_WPI_KEYBUF_SIZE+WAPI_AC_WPI_MICBUF_SIZE];
		#ifndef wk_txmic
	#define	wk_txmic	wk_key+WAPI_AC_WPI_KEYBUF_SIZE
		#endif
		unsigned char wk_keyrsc[WAPI_AC_WPI_PN_LEN];  /*接收PN*/
		unsigned char wk_keytsc[WAPI_AC_WPI_PN_LEN];  /*发送PN*/
		unsigned char wk_keyrsc_temp[WAPI_AC_WPI_PN_LEN];
	
		unsigned char aucBssid[6];
	unsigned short  usTxSeq;
	struct wapi_ac_key_stats stats;
};
typedef struct wapi_ac_wpi_key WAPI_AC_WPI_KEY; /*WAPI 密钥结构*/
#endif

typedef struct
{
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
}L2W_USER_MAC_ARGS_T;

typedef struct {
	char acDevName[24];
	unsigned long 	ulVdevId;
}L2W_VDEV_ARGS_T;


typedef struct
{
	unsigned long	ulCapwapFragMtu;	/* set capwap mtu	*/
} L2W_SET_CAPWAP_FRAG_MTU_ARGS_T;

typedef struct
{
	unsigned long	ulCapwapFragMtu;	/* get capwap mtu	*/
} L2W_GET_CAPWAP_FRAG_MTU_ARGS_T;

typedef struct
{
	unsigned long	ulCapwapFragSwitch;	/* 打印开关	0:关闭  1:打开	*/
} L2W_SET_CAPWAP_FRAG_SWITCH_ARGS_T;

typedef struct
{
	unsigned long	ulCapwapFragSwitch;	/* 打印开关	0:关闭  1:打开	*/
} L2W_GET_CAPWAP_FRAG_SWITCH_ARGS_T;

typedef L2W_VDEV_ARGS_T L2W_ADD_VDEV_ARGS_T;

typedef L2W_VDEV_ARGS_T L2W_DEL_VDEV_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulDevType;
	char	acDevName[IFNAMSIZ];
} L2W_DEV_ARGS_T;

typedef L2W_DEV_ARGS_T L2W_ADD_DEV_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
} L2W_DEL_DEV_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulBrId;
	unsigned long	ulBrType;
	char	acBrName[IFNAMSIZ];
	unsigned char	aucBrIp[4];
} L2W_ADD_BR_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulBrId;
} L2W_DEL_BR_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulBrId;
	unsigned char aucIp[4];
} L2W_SET_BRIP_ARGS_T;

typedef  struct {
	unsigned long	ulDevId;
	unsigned long	ulIfId;
	unsigned long	ulIfType;
	char	acIfName[IFNAMSIZ];
	char acSsid[32];
}  L2W_ADD_IF_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulIfId;
} L2W_DEL_IF_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulBrId;
	unsigned long	ulIfId;
}  L2W_BIND_IF_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulBrId;
	unsigned long	ulIfId;
} L2W_UNBIND_IF_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulIfId;
	char	acSsid[32];
} L2W_SET_IFSSID_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulIfId;
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulVlanId;
	unsigned long ulUserType;
	char			acSsid[32];
} L2W_USERBASIC_ARGS_T;


typedef struct {
	unsigned long	ulDevId;
	char	acDevName[IFNAMSIZ];
	unsigned long	ulIfId;
	char	acIfName[IFNAMSIZ];
	char			acSsid[32];
	unsigned long ulVlanId;
	unsigned char aucMac[6];
	unsigned char aucRsv[2];

	unsigned char aucIp[4];

	unsigned long ulPriority;
	unsigned long ulUpBandMin;
	unsigned long ulUpBandMax;
	unsigned long ulDownBandMin;
	unsigned long ulDownBandMax;

	unsigned long ulCertState;
	unsigned long ulUserType;
	/* 2011-1-12 ymt add:count*/
	unsigned int	ulUlPkts;			/*上行包数 */
	unsigned int	ulDlPkts;			/*下行包数 */
	unsigned int	ulUlGigaWords;		/*上行字节数：单位4GByte */
	unsigned int    ulUlBytes;			/*上行字节数：单位Byte */
	unsigned int	ulDlGigaWords;		/*下行字节数：单位4GByte */
	unsigned int	ulDlBytes;			/*上行字节数：单位Byte */
	/* 2011-1-12 ymt end*/
/*
#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
*/
} L2W_USERCOMPLETE_ARGS_T;


typedef L2W_USERBASIC_ARGS_T L2W_ADD_USER_ARGS_T;

typedef L2W_USERBASIC_ARGS_T L2W_DEL_USER_ARGS_T;

typedef struct {
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned char aucIp[4];
} L2W_SET_USERIP_ARGS_T;
typedef struct 
{
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulCertState;
} L2W_SET_USERCERTSTATE_ARGS_T;

typedef struct {
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulPriority;
	unsigned long ulUpBandMin;
	unsigned long ulUpBandMax;
	unsigned long ulDownBandMin;
	unsigned long ulDownBandMax;
} L2W_SET_USERQOS_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_VDEV_ARGS_T	astVdevList[L2W_VDEV_MAX_PER_IOCTL];
} L2W_GET_VDEVLIST_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_DEV_ARGS_T	astDevList[L2W_DEV_MAX_PER_IOCTL];
} L2W_GET_DEVLIST_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulDevType;
	char	acDevName[IFNAMSIZ];
	
	unsigned long	ulBrId;
	unsigned long	ulBrType;
	char	acBrName[IFNAMSIZ];
	unsigned char	aucBrIp[4];
}L2W_BR_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_BR_ARGS_T	astBrList[L2W_BR_MAX_PER_IOCTL];
} L2W_GET_ALLBRLIST_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulDevType;
	char	acDevName[IFNAMSIZ];
	
	unsigned long	ulIfId;
	unsigned long	ulIfType;
	char	acIfName[IFNAMSIZ];
	char acSsid[32];

/*
#ifdef __WAPI_AC_WPI__
	WAPI_AC_WPI_KEY stKey;
#endif
*/
} L2W_IF_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_IF_ARGS_T	astIfList[L2W_IF_MAX_PER_IOCTL];
} L2W_GET_ALLIFLIST_ARGS_T;

typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulDevType;
	char	acDevName[IFNAMSIZ];
	
	unsigned long	ulBrId;
	unsigned long	ulBrType;
	char	acBrName[IFNAMSIZ];
	
	unsigned long	ulIfId;
	unsigned long	ulIfType;
	char	acIfName[IFNAMSIZ];
} L2W_BRIF_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_BRIF_ARGS_T	astIfList[L2W_BRIF_MAX_PER_IOCTL];
} L2W_GET_ALLBRIFLIST_ARGS_T;


typedef struct {
	unsigned long	ulRxPktNum; /*接收报文总数*/
	unsigned long	ulRxFragNum;/* 分片报文总数 */
    unsigned long	ulEnqueueNum;/* 入队报文总数 */
    unsigned long	ulDequeueNum;/* 出队报文总数 */
	unsigned long	ulDropNum;  /* 丢包总数 */
    unsigned long	ulKmallocMem;
    unsigned long	ulHaveMem;
    unsigned long	ulFreeKmallocMem;
    unsigned long	ulFreeHaveMem;
} L2W_GET_FRAG_ARGS_T;

typedef struct {
	unsigned long	ulRxPktNum; /*接收报文总数*/
	unsigned long	ulRxFragNum;/* 分片报文总数 */
    unsigned long	ulEnqueueNum;/* 入队报文总数 */
    unsigned long	ulDequeueNum;/* 出队报文总数 */
	unsigned long	ulDropNum;  /* 丢包总数 */
    unsigned long	ulKmallocMem;
    unsigned long	ulHaveMem;
    unsigned long	ulFreeKmallocMem;
    unsigned long	ulFreeHaveMem;
} L2W_CLEAN_FRAG_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_USERCOMPLETE_ARGS_T	astUserList[L2W_USER_MAX_PER_IOCTL];
} L2W_GET_ALLUSERLIST_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_USER_MAC_ARGS_T	astIdsUserList[L2W_USER_MAX_PER_IOCTL];
} L2W_GET_ALLIDSUSERLIST_ARGS_T;

typedef struct {
	unsigned long ulDevId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_BR_ARGS_T	astBrList[L2W_BR_MAX_PER_IOCTL];
} L2W_GET_DEVBRLIST_ARGS_T;

typedef struct {
	unsigned long ulDevId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_IF_ARGS_T	astIfList[L2W_IF_MAX_PER_IOCTL];
} L2W_GET_DEVIFLIST_ARGS_T;

typedef struct {
	unsigned long ulDevId;
	unsigned long ulBrId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_BRIF_ARGS_T	astIfList[L2W_IF_MAX_PER_IOCTL];
} L2W_GET_BRIFLIST_ARGS_T;

typedef struct {
	unsigned long ulDevId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_USERCOMPLETE_ARGS_T	astUserList[L2W_USER_MAX_PER_IOCTL];
} L2W_GET_DEVUSERLIST_ARGS_T;

typedef struct {
	unsigned long ulPrintlevel;
}L2W_PRINTLEVEL_ARGS_T;

typedef L2W_PRINTLEVEL_ARGS_T	L2W_GET_PRINTLEVEL_ARGS_T;
typedef L2W_PRINTLEVEL_ARGS_T	L2W_SET_PRINTLEVEL_ARGS_T;

typedef struct {
	unsigned long ulDevId;
} L2W_MYDEVCFG_ARGS_T;

typedef L2W_MYDEVCFG_ARGS_T 	L2W_SET_MYDEVCFG_ARGS_T;
typedef struct {
	L2W_DEV_ARGS_T		stDevCfg;
	unsigned long ulBrNum;
	L2W_BR_ARGS_T		astBrList[L2W_BR_MAX_PER_DEV];
	unsigned long ulIfNum;
	L2W_BRIF_ARGS_T		astBrIfList[L2W_IF_MAX_PER_DEV];
}L2W_GET_MYDEVCFG_ARGS_T;

typedef struct 
{
	unsigned long ulRunMode;
}L2W_SET_WTPRUNMODE_ARGS_T;

typedef struct 
{
	unsigned long ulRunMode;
}L2W_GET_WTPRUNMODE_ARGS_T;

typedef struct {
	unsigned char aucAcIp[4];
} L2W_SET_ACIP_ARGS_T;

typedef struct {
	unsigned char aucAcIp[4];
} L2W_GET_ACIP_ARGS_T;

typedef struct 
{
	unsigned char 	aucMac[6];			/* MAC地址 */
	unsigned char		aucRsv[2];			/* 填充字段 */
	unsigned char 	aucIp[4];			/* IP地址 */
	char				acIfName[IFNAMSIZ];
} L2W_MACIP_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_MACIP_ARGS_T	astMacIpList[L2W_MACIP_MAX_PER_IOCTL];
} L2W_GET_MACIPLIST_ARGS_T;

typedef struct {
	unsigned char 	aucIp[4];			/* IP地址 */
	unsigned long 		ulRet;				/* 查找结果*/
	L2W_MACIP_ARGS_T	stMacIp;
} L2W_GET_MACIP_BYIP_ARGS_T;
typedef struct {
	unsigned char 	aucMac[6];			/* MAC地址 */
	unsigned char		aucRsv[2];			/* 填充字段*/
	unsigned long 		ulRet;				/* 查找结果*/
	L2W_MACIP_ARGS_T	stMacIp;
} L2W_GET_MACIP_BYMAC_ARGS_T;

typedef struct 
{
	unsigned long	ulRet;				/* 查找结果*/
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned char aucIp[4];
}  L2W_GET_USERIP_ARGS_T;

typedef AC_DEVM_VLAN_CONFIG_T L2W_ADD_VLAN_ARGS_T;
typedef AC_DEVM_VLAN_CONFIG_T L2W_DEL_VLAN_ARGS_T;
typedef AC_DEVM_VLAN_CONFIG_T L2W_SET_VLAN_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLAN_CONFIG_T	astVlanList[L2W_VLAN_MAX_PER_IOCTL];
} L2W_GET_VLAN_ARGS_T;

typedef struct {
	unsigned long ulVlanId;
	AC_DEVM_VLAN_CONFIG_T	stVlan;
} L2W_GET_VLAN_BYID_ARGS_T;

typedef AC_DEVM_VLANIFMAP_CONFIG_T L2W_ADD_VLANIF_ARGS_T;
typedef AC_DEVM_VLANIFMAP_CONFIG_T L2W_DEL_VLANIF_ARGS_T;
typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANIFMAP_CONFIG_T	astVlanIfList[L2W_VLANIF_MAX_PER_IOCTL];
} L2W_GET_VLANIF_ARGS_T;

typedef struct {
	unsigned long ulVlanId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANIFMAP_CONFIG_T	astVlanIfList[L2W_VLANIF_MAX_PER_IOCTL];
} L2W_GET_VLANIF_BYVLAN_ARGS_T;

typedef struct {
	unsigned long ulDevId;
	unsigned long ulIfId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANIFMAP_CONFIG_T	astVlanIfList[L2W_VLANIF_MAX_PER_IOCTL];
} L2W_GET_VLANIF_BYIF_ARGS_T;



typedef AC_DEVM_VLANMACMAP_CONFIG_T L2W_ADD_VLANMAC_ARGS_T;
typedef AC_DEVM_VLANMACMAP_CONFIG_T L2W_DEL_VLANMAC_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANMACMAP_CONFIG_T	astVlanMacList[L2W_VLANMAC_MAX_PER_IOCTL];
} L2W_GET_VLANMAC_ARGS_T;

typedef struct {
	unsigned long ulVlanId;
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANMACMAP_CONFIG_T	astVlanMacList[L2W_VLANMAC_MAX_PER_IOCTL];
} L2W_GET_VLANMAC_BYVLAN_ARGS_T;

typedef struct {
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANMACMAP_CONFIG_T	astVlanMacList[L2W_VLANMAC_MAX_PER_IOCTL];
} L2W_GET_VLANMAC_BYMAC_ARGS_T;

typedef AC_DEVM_VLANSSIDMAP_CONFIG_T L2W_ADD_VLANSSID_ARGS_T;
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T L2W_DEL_VLANSSID_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANSSIDMAP_CONFIG_T	astVlanSsidList[L2W_VLANSSID_MAX_PER_IOCTL];
} L2W_GET_VLANSSID_ARGS_T;

typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T	L2W_ADD_VLANACCMACPOLICY_ARGS_T;
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T	L2W_DEL_VLANACCMACPOLICY_ARGS_T;
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T	L2W_SET_VLANACCMACPOLICY_ARGS_T;
typedef struct
{
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANACCMACPOLICY_CONFIG_T		astVlanPolicyList[L2W_VLANACCMAC_MAX_PER_IOCTL];
} L2W_GET_VLANACCMACPOLICY_ARGS_T;

typedef AC_DEVM_VLANACCMAC_CONFIG_T L2W_ADD_VLANACCMAC_ARGS_T;
typedef AC_DEVM_VLANACCMAC_CONFIG_T L2W_DEL_VLANACCMAC_ARGS_T;
typedef struct
{
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_VLANACCMAC_CONFIG_T		astVlanAccMacList[L2W_VLANACCMAC_MAX_PER_IOCTL];
} L2W_GET_VLANACCMAC_ARGS_T;

typedef AC_DEVM_IGMPPROXY_CONFIG_T L2W_SET_IGMPPROXY_ARGS_T;
typedef AC_DEVM_IGMPPROXY_CONFIG_T	L2W_GET_IGMPPROXY_ARGS_T;

typedef AC_DEVM_IGMPSNOOP_CONFIG_T L2W_SET_IGMPSNOOP_ARGS_T;
typedef AC_DEVM_IGMPSNOOP_CONFIG_T L2W_GET_IGMPSNOOP_ARGS_T;
typedef struct 
{
	unsigned long 	ulFatAcSwitch;
} L2W_SET_FATAC_SWITCH_ARGS_T;

typedef L2W_SET_FATAC_SWITCH_ARGS_T L2W_GET_FATAC_SWITCH_ARGS_T;


typedef L2W_USER_MAC_ARGS_T L2W_ADD_IDSUSER_ARGS_T;

typedef L2W_USER_MAC_ARGS_T L2W_DEL_IDSUSER_ARGS_T;

typedef struct
{
	unsigned long	ulPortType;		/* 端口类型*/
	unsigned long	ulForwardSwitch;	/* 转发开关	0: 禁止转发 1:允许转发	*/
} L2W_SET_FORWARD_SWITCH_ARGS_T;

typedef struct
{
	unsigned long	ulFitLanForward;		/* 0: 禁止转发 1:允许转发*/
	unsigned long	ulFatLanForward;	/* 0: 禁止转发 1:允许转发*/
	unsigned long	ulL2WanForward;	/* 0: 禁止转发 1:允许转发*/
	unsigned long	ulL3WanForward;	/* 0: 禁止转发 1:允许转发*/
} L2W_GET_FORWARD_SWITCH_ARGS_T;

/*2011-1-15 ymt add:count*/
typedef struct {
	unsigned long	ulDevId;
	unsigned long	ulDevType;
	char	acDevName[IFNAMSIZ];
	unsigned int	ulUlPkts;			/*上行包数 */
	unsigned int	ulDlPkts;			/*下行包数 */
	unsigned int	ulUlGigaWords;		/*上行字节数：单位4GByte */
	unsigned int	ulUlBytes;			/*上行字节数：单位Byte */
	unsigned int	ulDlGigaWords;		/*下行字节数：单位4GByte */
	unsigned int	ulDlBytes;			/*上行字节数：单位Byte */
} L2W_DEVSTAT_ARGS_T;

typedef struct {
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	L2W_DEVSTAT_ARGS_T	astDevStatList[L2W_DEV_MAX_PER_IOCTL];
} L2W_GET_DEVSTATLIST_ARGS_T;


typedef struct
{
	unsigned long	ulDevId;			/* 设备ID */
	unsigned long	ulIfId;			/* 端口ID */
	unsigned long	ulVlanId;		/* VLAN ID */
	unsigned long	ulNestVlanId;	/* */
} AC_DEVM_QINQ_CONFIG_T;

typedef AC_DEVM_QINQ_CONFIG_T L2W_ADD_QINQ_ARGS_T;
typedef AC_DEVM_QINQ_CONFIG_T L2W_DEL_QINQ_ARGS_T;
typedef struct
{
	unsigned long ulStartNum;	/* 获取的起始记录号*/
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;	/* 本次读取返回的有效记录数*/
	AC_DEVM_QINQ_CONFIG_T	astQinQList[8];
}L2W_GET_QINQ_ARGS_T;


typedef struct {
	unsigned long	ulDevId;
} L2W_RESET_DEVSTAT_ARGS_T;

typedef struct {
	unsigned char aucMac[6];
	unsigned char aucRsv[2];
} L2W_RESET_USERSTAT_ARGS_T;

/*2011-1-15 ymt end*/

/* 2011-1-27 pyy add : 本地转发二层隔离功能新增*/
typedef struct
{
	unsigned long	ulIsolate;	/* 0:禁用二层隔离  1:启用二层隔离*/
} L2W_SET_LOCALFORWARD_ISOLATE_ARGS_T;

typedef L2W_SET_LOCALFORWARD_ISOLATE_ARGS_T  L2W_GET_LOCALFORWARD_ISOLATE_ARGS_T;
typedef struct
{
	unsigned long ulMVlanId;
} L2W_SET_MVLAN_ARGS_T;

typedef L2W_SET_MVLAN_ARGS_T  L2W_GET_MVLAN_ARGS_T;

	
#ifdef __WAPI_AC_WPI__
typedef enum
{
	MCAST_KEY = 0, /*广播密钥*/
	UCAST_KEY, /*单播密钥*/
}WAPI_KEY_TYPE_E;


typedef struct
{
	AC_VAPID_T stAcVapId;
	unsigned char aucUserMac[6];
}WAPI_ADDR_TYPE_T;
	
typedef struct{
	WAPI_KEY_TYPE_E    enKeyType;
	WAPI_ADDR_TYPE_T stAddrType;
	unsigned short usKid; 
	unsigned char aucBssid[6]; /*设置广播密钥时携带*/
	unsigned char  aucKey[16+16];
}L2W_SET_WAPI_KEY_ARGS_T;

typedef struct{
	WAPI_KEY_TYPE_E    enKeyType;
	WAPI_ADDR_TYPE_T stAddrType;
}L2W_DEL_WAPI_KEY_ARGS_T;

typedef struct
{
	WAPI_KEY_TYPE_E    enKeyType;
	WAPI_ADDR_TYPE_T stAddrType;
	unsigned char	ucKeyId;	
	unsigned char	aucWapiRsc[16];
	unsigned char	aucWapiTsc[16];
}L2W_GET_WAPI_SEQNO_ARGS_T;

typedef struct
{
    WAPI_ADDR_TYPE_T stAddrType;
    unsigned long ulWPIReplayCounters;
    unsigned long ulWPIDecryptableErrors;
    unsigned long ulWPIMICErrors;
}L2W_GET_WAPI_STATS;


#define L2W_WAP_INFO_NUM 5
typedef struct
{
	unsigned char aucMac[6];
	unsigned char resv[2];
	WAPI_AC_WPI_KEY stKey;
}L2W_WAPI_KEY_IFNO_T;
typedef struct
{
	unsigned long	ulFinish;		/* 所有记录是否已读取结束*/
	unsigned long ulRetNum;
	L2W_WAPI_KEY_IFNO_T astWapiKeyInfo[L2W_WAP_INFO_NUM];
}L2W_GET_WAPI_IFNO_T;

#endif
typedef struct  {
	int iCmd; /* Should be one of the vlan_ioctl_cmds enum above. */

	union {
		L2W_ADD_VDEV_ARGS_T	stAddVdev;
		L2W_DEL_VDEV_ARGS_T	stDelVdev;
		
		L2W_ADD_DEV_ARGS_T		stAddDev;
		L2W_DEL_DEV_ARGS_T		stDelDev;
		
		L2W_ADD_BR_ARGS_T		stAddBr;
		L2W_DEL_BR_ARGS_T		stDelBr;
		L2W_SET_BRIP_ARGS_T		stSetBrIp;

		L2W_ADD_IF_ARGS_T		stAddIf;
		L2W_DEL_IF_ARGS_T		stDelIf;

		L2W_BIND_IF_ARGS_T		stBindIf;
		L2W_UNBIND_IF_ARGS_T	stUnbindIf;
		L2W_SET_IFSSID_ARGS_T	stSetIfSsid;

		L2W_ADD_USER_ARGS_T	stAddUser;
		L2W_DEL_USER_ARGS_T	stDelUser;
		L2W_SET_USERIP_ARGS_T	stSetUserIp;
		L2W_SET_USERCERTSTATE_ARGS_T	stSetUserCertState;
		L2W_SET_USERQOS_ARGS_T	stSetUserQos;
		L2W_GET_USERIP_ARGS_T		stGetUserIp;

		L2W_GET_VDEVLIST_ARGS_T	stGetVdevList;
		L2W_GET_DEVLIST_ARGS_T		stGetDevList;
		L2W_GET_ALLBRLIST_ARGS_T	stGetAllBrList;
		L2W_GET_ALLIFLIST_ARGS_T	stGetAllIfList;
		L2W_GET_ALLBRIFLIST_ARGS_T	stGetAllBrIfList;
		L2W_GET_ALLUSERLIST_ARGS_T	stGetAllUserList;

		L2W_GET_DEVBRLIST_ARGS_T	stGetDevBrList;
		L2W_GET_DEVIFLIST_ARGS_T	stGetDevIfList;
		L2W_GET_BRIFLIST_ARGS_T		stGetBrIfList;
		L2W_GET_DEVUSERLIST_ARGS_T	stGetDevUserList;

		L2W_SET_PRINTLEVEL_ARGS_T	stSetPrintLevel;
		L2W_GET_PRINTLEVEL_ARGS_T	stGetPrintLevel;

		L2W_SET_MYDEVCFG_ARGS_T	stSetMyDevCfg;
		L2W_GET_MYDEVCFG_ARGS_T	stGetMyDevCfg;

		L2W_SET_WTPRUNMODE_ARGS_T	stSetWtpRunModeCfg;
		L2W_GET_WTPRUNMODE_ARGS_T	stGetWtpRunModeCfg;

		L2W_SET_ACIP_ARGS_T		stSetAcIp;
		L2W_GET_ACIP_ARGS_T		stGetAcIp;

		L2W_ADD_VLAN_ARGS_T	stAddVlan;
		L2W_DEL_VLAN_ARGS_T	stDelVlan;
		L2W_SET_VLAN_ARGS_T	stSetVlan;
		L2W_GET_VLAN_ARGS_T	stGetVlan;
		L2W_GET_VLAN_BYID_ARGS_T	stGetVlanById;
		
		L2W_ADD_VLANIF_ARGS_T	stAddVlanIf;
		L2W_DEL_VLANIF_ARGS_T	stDelVlanIf;
		L2W_GET_VLANIF_ARGS_T	stGetVlanIf;
		L2W_GET_VLANIF_BYVLAN_ARGS_T	stGetVlanIfByVlan;
		L2W_GET_VLANIF_BYIF_ARGS_T		stGetVlanIfByIf;

		L2W_ADD_VLANMAC_ARGS_T	stAddVlanMac;
		L2W_DEL_VLANMAC_ARGS_T		stDelVlanMac;
		L2W_GET_VLANMAC_ARGS_T	stGetVlanMac;
		L2W_GET_VLANMAC_BYVLAN_ARGS_T	stGetVlanMacByVlan;
		L2W_GET_VLANMAC_BYMAC_ARGS_T	stGetVlanMacByMac;

		L2W_ADD_VLANSSID_ARGS_T	stAddVlanSsid;
		L2W_DEL_VLANSSID_ARGS_T	stDelVlanSsid;
		L2W_GET_VLANSSID_ARGS_T	stGetVlanSsid;

		L2W_ADD_VLANACCMACPOLICY_ARGS_T	stAddVlanAccMacPolicy;
		L2W_ADD_VLANACCMACPOLICY_ARGS_T	stDelVlanAccMacPolicy;
		L2W_ADD_VLANACCMACPOLICY_ARGS_T	stSetVlanAccMacPolicy;
		L2W_GET_VLANACCMACPOLICY_ARGS_T	stGetVlanAccMacPolicy;
		
		L2W_ADD_VLANACCMAC_ARGS_T		stAddVlanAccMac;
		L2W_DEL_VLANACCMAC_ARGS_T		stDelVlanAccMac;
		L2W_GET_VLANACCMAC_ARGS_T		stGetVlanAccMac;

		L2W_SET_IGMPPROXY_ARGS_T	stSetIgmpProxy;
		L2W_GET_IGMPPROXY_ARGS_T	stGetIgmpProxy;
		
		L2W_SET_IGMPSNOOP_ARGS_T	stSetIgmpSnoop;
		L2W_GET_IGMPSNOOP_ARGS_T	stGetIgmpSnoop;

		L2W_SET_FATAC_SWITCH_ARGS_T	stSetFatAcSwitch;
		L2W_GET_FATAC_SWITCH_ARGS_T	stGetFatAcSwitch;
		L2W_GET_MACIPLIST_ARGS_T	stGetMacIpList;
		L2W_GET_MACIP_BYIP_ARGS_T	stGetMacIpByIp;
		L2W_GET_MACIP_BYMAC_ARGS_T	stGetMacIpByMac;

		L2W_ADD_IDSUSER_ARGS_T		stAddIdsUser;
		L2W_DEL_IDSUSER_ARGS_T		stDelIdsUser;
		L2W_GET_ALLIDSUSERLIST_ARGS_T	stGetAllIdsUserList;
        L2W_SET_CAPWAP_FRAG_SWITCH_ARGS_T stSetCapwapFragSwitch;
        L2W_GET_CAPWAP_FRAG_SWITCH_ARGS_T stGetCapwapFragSwitch;
        
		/* 2010-8-10 新增*/
		L2W_SET_FORWARD_SWITCH_ARGS_T	stSetForwardSwitch;
		L2W_GET_FORWARD_SWITCH_ARGS_T	stGetForwardSwitch;
		/*2011-1-12 ymt add:count*/
		L2W_GET_DEVSTATLIST_ARGS_T	stGetDevStatList;		/* 获取所有AP设备流量统计信息 */
		L2W_RESET_DEVSTAT_ARGS_T		stResetDevStat;	/* 清除指定AP设备流量统计信息 */
		L2W_RESET_USERSTAT_ARGS_T	stResetUserStat;	/* 清除指定用户流量统计信息 */
		/*2011-1-12 ymt end*/

		/* 2011-1-27 pyy add : 本地转发二层隔离功能新增*/
		L2W_SET_LOCALFORWARD_ISOLATE_ARGS_T	stSetLFIsolate;
		L2W_GET_LOCALFORWARD_ISOLATE_ARGS_T	stGetLFIsolate;
		/* 2011-1-25 pyy add */
		L2W_SET_MVLAN_ARGS_T		stSetMVlan;
		L2W_GET_MVLAN_ARGS_T		stGetMVlan;
        L2W_GET_FRAG_ARGS_T stGetFrag;
        L2W_CLEAN_FRAG_ARGS_T stCleanFrag;
        L2W_SET_CAPWAP_FRAG_MTU_ARGS_T stSetCapwapFragMtu;
        L2W_GET_CAPWAP_FRAG_MTU_ARGS_T stGetCapwapFragMtu;
        L2W_ADD_QINQ_ARGS_T	stAddQinq;
		L2W_DEL_QINQ_ARGS_T	stDelQinq;
		L2W_GET_QINQ_ARGS_T	stGetQinqList;
				
#ifdef __WAPI_AC_WPI__
		L2W_SET_WAPI_KEY_ARGS_T stSetWapiKey;
		L2W_DEL_WAPI_KEY_ARGS_T stDelWapiKey;
		L2W_GET_WAPI_SEQNO_ARGS_T stGetWapiSeqNo;
		L2W_GET_WAPI_STATS stGetWapiStats;
		L2W_GET_WAPI_IFNO_T stGetWapiInfo;
#endif	
        } u;
} L2W_IOCTL_ARGS_T;

typedef struct 
{
	const char *pcName;
	BOOL		(*pFunc)(int argc, char *const* argv);
	const char *pcHelp;
} L2W_IOCTL_CMD_HELP_T;

enum l2w_ioctl_cmds {
	L2W_REG_VDEV_CMD,
	L2W_UNREG_VDEV_CMD,
	
	L2W_ADD_DEV_CMD,
	L2W_DEL_DEV_CMD,
	
	L2W_ADD_BR_CMD,
	L2W_DEL_BR_CMD,
	L2W_SET_BRIP_CMD,		/* 设置AP 承载桥的IP */
	
	L2W_ADD_IF_CMD,
	L2W_DEL_IF_CMD,
	
	L2W_BIND_IF_CMD,
	L2W_UNBIND_IF_CMD,

	L2W_SET_IFSSID_CMD,
	
	L2W_ADD_USER_CMD,
	L2W_DEL_USER_CMD,	
	L2W_SET_USERIP_CMD,
	L2W_SET_USERCERTSTATE_CMD,
	L2W_SET_USERQOS_CMD,
	L2W_GET_USERIP_CMD,
	
	L2W_GET_VDEVLIST_CMD,
	L2W_GET_DEVLIST_CMD,
	L2W_GET_ALLBRLIST_CMD,
	L2W_GET_ALLIFLIST_CMD,
	L2W_GET_ALLBRIFLIST_CMD,
	L2W_GET_ALLUSERLIST_CMD,
	L2W_GET_DEVBRLIST_CMD,
	L2W_GET_DEVIFLIST_CMD,
	L2W_GET_BRIFLIST_CMD,
	L2W_GET_DEVUSERLIST_CMD,

	L2W_SET_PRINTLEVEL_CMD,
	L2W_GET_PRINTLEVEL_CMD,
	
	L2W_SET_MYDEVCFG_CMD,
	L2W_GET_MYDEVCFG_CMD,

	L2W_SET_WTPRUNMODE_CMD,
	L2W_GET_WTPRUNMODE_CMD,

	L2W_SET_ACIP_CMD,
	L2W_GET_ACIP_CMD,

	L2W_ADD_VLAN_CMD,
	L2W_DEL_VLAN_CMD,	
	L2W_SET_VLAN_CMD,	
	L2W_GET_VLAN_CMD,
	L2W_GET_VLAN_BYID_CMD,
	
	L2W_ADD_VLANIF_CMD,
	L2W_DEL_VLANIF_CMD,
	L2W_GET_VLANIF_CMD,
	L2W_GET_VLANIF_BYVLAN_CMD,
	L2W_GET_VLANIF_BYIF_CMD,
	
	L2W_ADD_VLANMAC_CMD,
	L2W_DEL_VLANMAC_CMD,
	L2W_GET_VLANMAC_CMD,
	L2W_GET_VLANMAC_BYVLAN_CMD,
	L2W_GET_VLANMAC_BYMAC_CMD,

	L2W_ADD_VLANSSID_CMD,
	L2W_DEL_VLANSSID_CMD,
	L2W_GET_VLANSSID_CMD,
	
	L2W_ADD_VLANACCMACPOLICY_CMD,
	L2W_DEL_VLANACCMACPOLICY_CMD,
	L2W_SET_VLANACCMACPOLICY_CMD,
	L2W_GET_VLANACCMACPOLICY_CMD,
	
	L2W_ADD_VLANACCMAC_CMD,
	L2W_DEL_VLANACCMAC_CMD,
	L2W_GET_VLANACCMAC_CMD,

	L2W_SET_IGMPPROXY_CMD,
	L2W_GET_IGMPPROXY_CMD,
	
	L2W_SET_IGMPSNOOP_CMD,
	L2W_GET_IGMPSNOOP_CMD,

	L2W_SET_FATACSWITCH_CMD,
	L2W_GET_FATACSWITCH_CMD,
	
	L2W_GET_MACIPLIST_CMD,
	L2W_GET_MACIP_BYIP_CMD,
	L2W_GET_MACIP_BYMAC_CMD,

	L2W_ADD_IDSUSER_CMD,
	L2W_DEL_IDSUSER_CMD,
	L2W_GET_ALLIDSUSER_CMD,

    L2W_SET_CAPWAPFRAGSWITCH_CMD,
    L2W_GET_CAPWAPFRAGSWITCH_CMD,
	L2W_SET_FORWARDSWITCH_CMD,
	L2W_GET_FORWARDSWITCH_CMD,
	/*2011-1-12 ymt add:count*/
	L2W_GET_DEVSTATLIST_CMD,		/* 获取所有AP设备流量统计信息 */
	L2W_RESET_DEVSTAT_CMD,		/* 清除指定AP设备流量统计信息 */
	L2W_RESET_ALLDEVSTAT_CMD,	/* 清除所有AP设备流量统计信息 */
	L2W_RESET_USERSTAT_CMD,		/* 清除指定用户流量统计信息 */
	L2W_RESET_ALLUSERSTAT_CMD,	/* 清除所有用户流量统计信息 */
	/*2011-1-12 ymt end*/	

	/* 2011-1-27 pyy add : 本地转发二层隔离功能新增*/
	L2W_SET_LOCALFORWARD_ISOLATE_CMD,		/* 设置本地转发二层隔离开关*/
	L2W_GET_LOCALFORWARD_ISOLATE_CMD,		/* 获取本地转发二层隔离开关*/
	L2W_SET_MVLAN_CMD,
	L2W_GET_MVLAN_CMD,
	
	L2W_RESET_CMD,
	L2W_GET_FRAG_CMD,
	L2W_CLEAN_FRAG_CMD,
	L2W_SET_CAPWAPFRAGMTU_CMD,
    L2W_GET_CAPWAPFRAGMTU_CMD,
    L2W_ADD_QINQ_CMD,
	L2W_DEL_QINQ_CMD,
	L2W_GET_QINQ_CMD,
#ifdef __WAPI_AC_WPI__
	L2W_SET_WAPI_KEY_CMD = 200,
	L2W_DEL_WAPI_KEY_CMD = 201, 
	L2W_GET_WAPI_SEQNO_CMD = 202, 
	L2W_GET_WAPI_STATS_CMD = 203, 
	L2W_GET_WAPI_PRINT_CMD = 204,
	L2W_GET_WAPI_GET_ALL_IF_INFO = 205,
	L2W_GET_WAPI_GET_ALL_USER_INFO = 206,
#endif

    L2W_SET_TS_START_CMD = 300,
    L2W_SET_TS_END_CMD = 349,
    L2W_SET_NF_PORTAL_START_CMD = 350,
    L2W_SET_NF_PORTAL_END_CMD = 399,
};



/* 与用户态交互的消息头定义*/
typedef struct 
{
	unsigned long	ulMsgId;
	unsigned long	ulMsgLen;
}  L2W_UK_MSGHDR_T;

/* 设置用户IP消息体 */
typedef struct 
{
	unsigned char	aucMac[6];
	unsigned char	aucRsv[2];
	unsigned char	aucIp[4];
} L2W_UK_UPDATE_USERIP_T;

/* FAT-AC: 新增用户消息体*/
typedef struct
{
	unsigned char	aucMac[6];
	unsigned char	aucRsv[2];
	unsigned char	aucIp[4];
	unsigned long	ulEthId;
	unsigned long ulVlanId;	/* 2010-2-22 新增: FAT-LAN端口接入的用户 也需要VLAN-ID信息 */
} L2W_UK_ADD_FATUSER_T;

/* FAT-AC: 删除用户消息体*/
typedef struct
{
	unsigned char	aucMac[6];
	unsigned char	aucRsv[2];
	unsigned char	aucIp[4];
	unsigned long	ulEthId;
	unsigned long ulVlanId;	 /* 2010-2-22 新增: FAT-LAN端口接入的用户 也需要VLAN-ID信息 */
} L2W_UK_DEL_FATUSER_T;

/*******************************************************************************/
#endif

