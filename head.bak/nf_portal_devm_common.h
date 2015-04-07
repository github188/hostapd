#ifndef __NF_PORTAL_COMMON_H__
#define __NF_PORTAL_COMMON_H__

/*	WEB认证全局配置*/
typedef struct
{
	unsigned int	ulPortalEnable;		/* 强制WEB认证0/1 禁用/启用*/
	unsigned char	aucPortalIp[4];
	char	        acPortalURL[64];
	unsigned int	ulPortalPort;
	char	        acDomainName[64];
	unsigned int	ulConcurrentAuthMaxNum;
	unsigned int	ulReauthTimeout;
} AC_DEVM_PORTAL_CONFIG_T;

/*	Portal白名单配置AC_DEVM_WHITELIST_CONFIG_T */
typedef struct
{
	unsigned int	ulWhiteId;
	unsigned char	aucWhiteIp[4];
	unsigned char	aucWhiteIpMask[4];
	unsigned short	usWhiteProto;
	unsigned short	usWhitePort;
} AC_DEVM_WHITELIST_CONFIG_T;

/* BEGIN: Added by wns, 2012/11/22   PN:TASK#225 */
typedef struct
{
	unsigned int ulWhiteId;				//	白名单ID 
	unsigned char aucWhiteUrl[64];		//	白名单URL 
}AC_DEVM_WHITEURL_CONFIG_T;
/* END:   Added by wns, 2012/11/22   PN:TASK#225 */

typedef struct 
{
	unsigned int		ulBridgeId;   			/* 端口组ID	        */
	unsigned int   		ulBridgeType;   			/* 端口类型	        */
	char   		        acBridgeName[32];   		/* 端口组名称	    */    
	unsigned int		ulIpNum;
	unsigned char		aaucIp[40][4];
	unsigned char		aaucMask[40][4];
} AC_DEVM_BRIDGE_CONFIG_T;


typedef struct
{
	unsigned int	ulRet;
	unsigned char		aucFatLanIp[4];
	unsigned char		aucFatLanMask[4];
	unsigned char		aucL2WanIp[4];
	unsigned char		aucL2WanMask[4];
}AC_DEVM_GET_L2WAN_FIRSTIP_CONFIG_RSP_T;


/* 端口IP地址配置*/
#define AC_BRIDGE_FITLAN_IPNUM_MAX	8
#define AC_BRIDGE_FATLAN_IPNUM_MAX	32
#define AC_BRIDGE_L2WAN_IPNUM_MAX	8
#define AC_BRIDGE_L3WAN_IPNUM_MAX	8

typedef struct 
{
	unsigned int	ulFitLanIpNum;											/* FIT-LAN端口的IP地址数目*/
	unsigned char	aaucFitLanIp[AC_BRIDGE_FITLAN_IPNUM_MAX][4];				/* FIT-LAN IP地址*/
	unsigned char	aaucFitLanNetMask[AC_BRIDGE_FITLAN_IPNUM_MAX][4];		/* FIT-LAN IP子网掩码*/

	unsigned int	ulFatLanIpNum;											/* FAT-LAN端口的IP地址数目*/
	unsigned char	aaucFatLanIp[AC_BRIDGE_FATLAN_IPNUM_MAX][4];			/* FAT-LAN IP地址*/
	unsigned char	aaucFatLanNetMask[AC_BRIDGE_FATLAN_IPNUM_MAX][4];		/* FAT-LAN IP子网掩码*/

	unsigned int	ulL2WanIpNum;											/* L2-WAN端口的IP地址数目*/
	unsigned char	aaucL2WanIp[AC_BRIDGE_L2WAN_IPNUM_MAX][4];				/* L2-WAN IP地址*/
	unsigned char	aaucL2WanNetMask[AC_BRIDGE_L2WAN_IPNUM_MAX][4];		/* L2-WAN IP子网掩码*/

	unsigned int	ulL3WanIpNum;											/* L3-WAN端口的IP地址数目*/
	unsigned char	aaucL3WanIp[AC_BRIDGE_L3WAN_IPNUM_MAX][4];				/* L3-WAN IP地址*/
	unsigned char	aaucL3WanNetMask[AC_BRIDGE_L3WAN_IPNUM_MAX][4];		/* L3-WAN IP子网掩码*/

	unsigned char	aucDefaultGw[4];					/* 缺省网关*/
	unsigned char	aucPrimaryDns[4];				/* 主用DNS服务器*/
	unsigned char	aucSecondaryDns[4];				/* 备用DNS服务器*/
} AC_DEVM_ACIP_CONFIG_T;

#endif
