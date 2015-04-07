#ifndef __NF_PORTAL_COMMON_H__
#define __NF_PORTAL_COMMON_H__

/*	WEB��֤ȫ������*/
typedef struct
{
	unsigned int	ulPortalEnable;		/* ǿ��WEB��֤0/1 ����/����*/
	unsigned char	aucPortalIp[4];
	char	        acPortalURL[64];
	unsigned int	ulPortalPort;
	char	        acDomainName[64];
	unsigned int	ulConcurrentAuthMaxNum;
	unsigned int	ulReauthTimeout;
} AC_DEVM_PORTAL_CONFIG_T;

/*	Portal����������AC_DEVM_WHITELIST_CONFIG_T */
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
	unsigned int ulWhiteId;				//	������ID 
	unsigned char aucWhiteUrl[64];		//	������URL 
}AC_DEVM_WHITEURL_CONFIG_T;
/* END:   Added by wns, 2012/11/22   PN:TASK#225 */

typedef struct 
{
	unsigned int		ulBridgeId;   			/* �˿���ID	        */
	unsigned int   		ulBridgeType;   			/* �˿�����	        */
	char   		        acBridgeName[32];   		/* �˿�������	    */    
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


/* �˿�IP��ַ����*/
#define AC_BRIDGE_FITLAN_IPNUM_MAX	8
#define AC_BRIDGE_FATLAN_IPNUM_MAX	32
#define AC_BRIDGE_L2WAN_IPNUM_MAX	8
#define AC_BRIDGE_L3WAN_IPNUM_MAX	8

typedef struct 
{
	unsigned int	ulFitLanIpNum;											/* FIT-LAN�˿ڵ�IP��ַ��Ŀ*/
	unsigned char	aaucFitLanIp[AC_BRIDGE_FITLAN_IPNUM_MAX][4];				/* FIT-LAN IP��ַ*/
	unsigned char	aaucFitLanNetMask[AC_BRIDGE_FITLAN_IPNUM_MAX][4];		/* FIT-LAN IP��������*/

	unsigned int	ulFatLanIpNum;											/* FAT-LAN�˿ڵ�IP��ַ��Ŀ*/
	unsigned char	aaucFatLanIp[AC_BRIDGE_FATLAN_IPNUM_MAX][4];			/* FAT-LAN IP��ַ*/
	unsigned char	aaucFatLanNetMask[AC_BRIDGE_FATLAN_IPNUM_MAX][4];		/* FAT-LAN IP��������*/

	unsigned int	ulL2WanIpNum;											/* L2-WAN�˿ڵ�IP��ַ��Ŀ*/
	unsigned char	aaucL2WanIp[AC_BRIDGE_L2WAN_IPNUM_MAX][4];				/* L2-WAN IP��ַ*/
	unsigned char	aaucL2WanNetMask[AC_BRIDGE_L2WAN_IPNUM_MAX][4];		/* L2-WAN IP��������*/

	unsigned int	ulL3WanIpNum;											/* L3-WAN�˿ڵ�IP��ַ��Ŀ*/
	unsigned char	aaucL3WanIp[AC_BRIDGE_L3WAN_IPNUM_MAX][4];				/* L3-WAN IP��ַ*/
	unsigned char	aaucL3WanNetMask[AC_BRIDGE_L3WAN_IPNUM_MAX][4];		/* L3-WAN IP��������*/

	unsigned char	aucDefaultGw[4];					/* ȱʡ����*/
	unsigned char	aucPrimaryDns[4];				/* ����DNS������*/
	unsigned char	aucSecondaryDns[4];				/* ����DNS������*/
} AC_DEVM_ACIP_CONFIG_T;

#endif
