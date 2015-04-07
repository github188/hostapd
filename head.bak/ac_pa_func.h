#ifndef AC_PA_FUNC_H
#define AC_PA_FUNC_H

#define AC_PA_USE_DFTIP_NO          0   /* 不使用配置的PS地址 */
#define AC_PA_USE_DFTIP_REQ         1   /* 主动发起的消息才使用配置的PS地址 */
#define AC_PA_USE_DFTIP_ALL         2   /* 全部消息均使用配置的PS地址 */

#define AC_PA_USE_DFTPORT_NO        0   /* 不使用缺省端口 */
#define AC_PA_USE_DFTPORT_REQ       1   /* 主动发起的消息才使用缺省端口 */
#define AC_PA_USE_DFTPORT_ALL       2   /* 全部消息均使用缺省端口 */

/* 本地配置 */
typedef struct
{
    UINT32      ulLocalPort;        /* PA侦听端口 */
    UINT32      ulAckLogout;        /* 是否允许ACK_NTF_LOGOUT消息，缺省0 */

    UINT32      ulUseDftPSIP;       /* 主动发送给PS消息时，是否采用配置的PS地址 */
    UINT32      ulUseDftPSPort;     /* 主动发送给PS消息时，是否采用标准的PS侦听端口 */

    //UINT32      ulDftPSPort;        /* 如果为0，采用OMC配置的Portal端口，否则采用本配置值 */

    UINT32      ulPaWebListenPort;  /* PA-WEB侦听端口 */
    UINT32      ulCheckPSTime;      /* 主动检查PortalServer是否可达的周期，单位秒，0表示不检查 */

    UINT32      ulAgingTime;        /* 等待Portal服务器应答消息的超时时间，单位：秒 */
    UINT32      ulMaxUserNum;       /* 最大同时在线用户数 */
    UINT32      ulAckTimeout;       /* 认证超时后是否向Portal发送认证失败应答消息 */

    /* 私有控制参数*/
    UINT32      ulUseTimeQueue;     /* 是否采用定时器队列，缺省为1，如果为0，则ScanTime不能为0 */
    UINT32      ulScanTime;         /* 定时扫描时间，单位秒，0表示关闭该功能 */

    UINT32      ulPrintTimeQueue;   /* 是否打印定时器队列 */

    UINT32      ulMaxIPNum;			/* IP->SSID映射关系记录最大数，缺省4096 */
	UINT32      ulCheckSSID;		/* 是否强制检测用户的IP->SSID映射关系，缺省1 */
	UINT32      ulIPAgingTime;      /* IP->SSID映射关系存活时间，缺省86400，单位：秒 */
	UINT32      ulIPScanTime;		/* IP->SSID映射关系老化检查，缺省600，单位：秒 */

    /*2011-10-28 ,wangyajun add , for GUANGDONG mobile company needs */
    UINT32      ulCheckSerPort;  /*Portal Server Scan port */
    
}AC_PA_PORTAL_LOCAL_CFG_T;

typedef struct
{
    /* 服务器配置 */
    BYTE        aucPortalIP[4];                         /* Portal服务器IP地址 */
    CHAR        acPortalUrl[AC_PA_PORTAL_URL_MAX_LEN+1];  /* Portal服务器URL */
    UINT32      ulPortalPort;                           /* Portal服务器访问端口 */

    /* 业务配置 */
    CHAR        acACName[AC_PA_ACNAME_MAX_LEN+1];       /* 由运营商统一规划的AC名称 */

    UINT32      ulMaxUserNum;                           /* 最大Portal认证用户数 */
    UINT32      ulMaxConcurrentAuthNum;                 /* 最大并发认证数目 */
    UINT32      ulReauthTimeout;                        /* 重认证超时,单位:秒 */

    UINT32      ulUserAddrBindNum;

#ifdef APP_PROJ_AC
    #define AC_PS_MAX_USERADDRBIND_NUM      AC_DB_ACUSERADDRBINDSETUP_CAPACITY
    AC_DEVM_USERADDRBIND_CONFIG_T       astUserAddrBind[AC_PS_MAX_USERADDRBIND_NUM];
#endif
}AC_PA_PORTAL_CONFIG_T;

/* 全部配置 */
typedef struct
{
    UINT32                      ulCfgID;        /* 每次配置数据变更后都增加1，初始值为upTime */

    AC_PA_PORTAL_CONFIG_T       stPortalCfg;
    AC_DEVM_MACSERVER_CONFIG_T stMacAuthCfg;

    AC_PA_PORTAL_LOCAL_CFG_T    stLocalCfg;

}AC_PA_CFG_T;

BOOL    ac_pa_is_mac_valid(UINT8* pucMac);
VOID    ac_pa_init_mac(UINT8* pucMac);
VOID	ac_pa_print_portal_msg_head(CHAR *szTitle, VOID *pstMsg);
VOID    ac_pa_portal_msg_ntoh(AC_PA_PORTAL_MSG_HEAD_T *pstMsg);
VOID    ac_pa_portal_msg_hton(AC_PA_PORTAL_MSG_HEAD_T *pstMsg);
UINT16  ac_pa_gen_reqid(VOID);
VOID    ac_pa_gen_challenge(UINT8* pucChallenge);
BOOL    ac_pa_send_portal(VOID* pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
BOOL    ac_pa_send_usrm(UINT16 usEvent, VOID* pMsg, UINT32 ulMsgLen);
BOOL    ac_pa_send_hostapd(UINT16 usEvent, VOID* pMsg, UINT32 ulMsgLen);

BOOL    ac_pa_gen_hr_omc_cfg(VOID);
AC_RET  ac_pa_get_omc_cfg(AC_PA_CFG_T *pstCfg);
AC_RET  ac_pa_get_user_info(UINT8* pucMac, AC_USRM_GET_USERINFO_RSP_T *pstUserInfo);
BOOL    ac_pa_send_web(VOID* pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
BOOL    ac_pa_sendto(VOID* pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
BOOL    ac_pa_send_pabk(VOID* pstMsg, UINT32 ulMsgSize);
BOOL    ac_pa_ioctl(UINT32 ulMsg, VOID *pvData);

VOID    ac_pa_stat(UINT8 ucMsgType, UINT8 ucErrCode);
BOOL    ac_pa_is_local_ip(UINT8 *pucIP);

#endif  /* AC_PA_FUNC_H */
