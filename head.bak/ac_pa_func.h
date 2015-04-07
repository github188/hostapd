#ifndef AC_PA_FUNC_H
#define AC_PA_FUNC_H

#define AC_PA_USE_DFTIP_NO          0   /* ��ʹ�����õ�PS��ַ */
#define AC_PA_USE_DFTIP_REQ         1   /* �����������Ϣ��ʹ�����õ�PS��ַ */
#define AC_PA_USE_DFTIP_ALL         2   /* ȫ����Ϣ��ʹ�����õ�PS��ַ */

#define AC_PA_USE_DFTPORT_NO        0   /* ��ʹ��ȱʡ�˿� */
#define AC_PA_USE_DFTPORT_REQ       1   /* �����������Ϣ��ʹ��ȱʡ�˿� */
#define AC_PA_USE_DFTPORT_ALL       2   /* ȫ����Ϣ��ʹ��ȱʡ�˿� */

/* �������� */
typedef struct
{
    UINT32      ulLocalPort;        /* PA�����˿� */
    UINT32      ulAckLogout;        /* �Ƿ�����ACK_NTF_LOGOUT��Ϣ��ȱʡ0 */

    UINT32      ulUseDftPSIP;       /* �������͸�PS��Ϣʱ���Ƿ�������õ�PS��ַ */
    UINT32      ulUseDftPSPort;     /* �������͸�PS��Ϣʱ���Ƿ���ñ�׼��PS�����˿� */

    //UINT32      ulDftPSPort;        /* ���Ϊ0������OMC���õ�Portal�˿ڣ�������ñ�����ֵ */

    UINT32      ulPaWebListenPort;  /* PA-WEB�����˿� */
    UINT32      ulCheckPSTime;      /* �������PortalServer�Ƿ�ɴ�����ڣ���λ�룬0��ʾ����� */

    UINT32      ulAgingTime;        /* �ȴ�Portal������Ӧ����Ϣ�ĳ�ʱʱ�䣬��λ���� */
    UINT32      ulMaxUserNum;       /* ���ͬʱ�����û��� */
    UINT32      ulAckTimeout;       /* ��֤��ʱ���Ƿ���Portal������֤ʧ��Ӧ����Ϣ */

    /* ˽�п��Ʋ���*/
    UINT32      ulUseTimeQueue;     /* �Ƿ���ö�ʱ�����У�ȱʡΪ1�����Ϊ0����ScanTime����Ϊ0 */
    UINT32      ulScanTime;         /* ��ʱɨ��ʱ�䣬��λ�룬0��ʾ�رոù��� */

    UINT32      ulPrintTimeQueue;   /* �Ƿ��ӡ��ʱ������ */

    UINT32      ulMaxIPNum;			/* IP->SSIDӳ���ϵ��¼�������ȱʡ4096 */
	UINT32      ulCheckSSID;		/* �Ƿ�ǿ�Ƽ���û���IP->SSIDӳ���ϵ��ȱʡ1 */
	UINT32      ulIPAgingTime;      /* IP->SSIDӳ���ϵ���ʱ�䣬ȱʡ86400����λ���� */
	UINT32      ulIPScanTime;		/* IP->SSIDӳ���ϵ�ϻ���飬ȱʡ600����λ���� */

    /*2011-10-28 ,wangyajun add , for GUANGDONG mobile company needs */
    UINT32      ulCheckSerPort;  /*Portal Server Scan port */
    
}AC_PA_PORTAL_LOCAL_CFG_T;

typedef struct
{
    /* ���������� */
    BYTE        aucPortalIP[4];                         /* Portal������IP��ַ */
    CHAR        acPortalUrl[AC_PA_PORTAL_URL_MAX_LEN+1];  /* Portal������URL */
    UINT32      ulPortalPort;                           /* Portal���������ʶ˿� */

    /* ҵ������ */
    CHAR        acACName[AC_PA_ACNAME_MAX_LEN+1];       /* ����Ӫ��ͳһ�滮��AC���� */

    UINT32      ulMaxUserNum;                           /* ���Portal��֤�û��� */
    UINT32      ulMaxConcurrentAuthNum;                 /* ��󲢷���֤��Ŀ */
    UINT32      ulReauthTimeout;                        /* ����֤��ʱ,��λ:�� */

    UINT32      ulUserAddrBindNum;

#ifdef APP_PROJ_AC
    #define AC_PS_MAX_USERADDRBIND_NUM      AC_DB_ACUSERADDRBINDSETUP_CAPACITY
    AC_DEVM_USERADDRBIND_CONFIG_T       astUserAddrBind[AC_PS_MAX_USERADDRBIND_NUM];
#endif
}AC_PA_PORTAL_CONFIG_T;

/* ȫ������ */
typedef struct
{
    UINT32                      ulCfgID;        /* ÿ���������ݱ��������1����ʼֵΪupTime */

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
