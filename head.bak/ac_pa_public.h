#ifndef AC_PA_PUBLIC_H
#define AC_PA_PUBLIC_H

#define PORTAL_AUTH_MODE_OFF                0   /* ����ҪWEB��֤ */
#define PORTAL_AUTH_MODE_ON                 1   /* ��ҪWEB��֤ */

#ifdef APP_PROJ_AC

#define EV_AC_PA_PORTAL_MSG                 ((UINT16)EV_PA_BEGIN + 1)

#define EV_AC_PA_HOSTAPD_AUTH_REQ_MSG       ((UINT16)EV_PA_BEGIN + 100) /* PA->HOSTAPD: ��Ȩ���� */
#define EV_AC_PA_HOSTAPD_AUTH_ACK_MSG       ((UINT16)EV_PA_BEGIN + 101) /* HOSTAPD->PA: ��ȨӦ�� */

#define EV_AC_PA_HOSTAPD_AUTH_OVER_NTF_MSG  ((UINT16)EV_PA_BEGIN + 102) /* PA->HOSTAPD: ��Ȩ�ɹ�֪ͨ */

#define EV_AC_PA_HOSTAPD_LOGOUT_NTF_MSG     ((UINT16)EV_PA_BEGIN + 110) /* PA->HOSTAPD: �û�����֪ͨ */
#endif

#define PORTAL_MAX_USERNAME_LEN             253
#define PORTAL_MAX_PASSWORD_LEN             253
#define PORTAL_CHAP_PASSWORD_LEN            16
#define PORTAL_CHALLENGE_LEN                16
/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define PORTAL_ERRID_LEN					5 
/*begin bug#1926 cmcc test fangz 2013.2.20*/


#define AC_PA_PORTAL_URL_MAX_LEN            64
#define AC_PA_ACNAME_MAX_LEN                64

/* portal���������˿� */
#define AC_PA_DEFAULT_PORT                  2000

/* portal����web����������UDP�˿ڣ�AC-PA֪ͨ���������ݱ���� */
#define AC_PA_WEB_LISTEN_PORT               30171

/* �ڲ���Ϣ��ucVer��ucType��ucAuthTypeΪ0xffʱ��*/
#define AC_PA_WEB_GET_CFG_REQ               0x20    /* PA-WEB -> AC: ��ȡ�������� */
#define AC_PA_WEB_HEART_BEAT_IND            0x30    /* PA-WEB -> AC: ���� */
#define AC_PA_HR_SET_IPSSID_NTF		        0x50    /* HR -> AC */

#define AC_PA_PABK_CFG_CHANGE_NTF           0x80    /* AC-PA  -> AC-PABK: ֪ͨ�������ݱ�� */

#define AC_PA_CTL_MSG_BEGIN                 0xb0    /* pactl��Ϣ */

#define AC_PA_CTL_LIST_USER_REQ             (AC_PA_CTL_MSG_BEGIN+0)     /* pactl��ȡ�û��б� */
#define AC_PA_CTL_LIST_USER_ACK             (AC_PA_CTL_MSG_BEGIN+1)     /* pactl��ȡ�û��б� */

#define AC_PA_CTL_GET_USER_REQ              (AC_PA_CTL_MSG_BEGIN+2)     /* pactl��ȡ�û���Ϣ */
#define AC_PA_CTL_GET_USER_ACK              (AC_PA_CTL_MSG_BEGIN+3)     /* pactl��ȡ�û���Ϣ */

#define AC_PA_CTL_DEL_USER_REQ              (AC_PA_CTL_MSG_BEGIN+4)     /* pactlɾ���û� */
#define AC_PA_CTL_DEL_USER_ACK              (AC_PA_CTL_MSG_BEGIN+5)     /* pactlɾ���û� */

#define AC_PA_CTL_LIST_IP_REQ               (AC_PA_CTL_MSG_BEGIN+6)     /* pactl��ȡ�û�IP�б� */
#define AC_PA_CTL_LIST_IP_ACK               (AC_PA_CTL_MSG_BEGIN+7)     /* pactl��ȡ�û�IP�б� */

/* PA���͸�HOSTAPD����֤������Ϣ */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];
    UINT16  usSerialNo;

    CHAR    acUserName[PORTAL_MAX_USERNAME_LEN+1];

    UINT8   ucPasswordLen;
    CHAR    acPassword[PORTAL_MAX_PASSWORD_LEN+1];   /* ����PAP��֤��Ϊ�䳤�ַ���0-253��
                                                        ����CHAP��֤��Ϊ16�ֽڶ����Ķ������� */
    UINT8   ucAuthType;
#define PORTAL_AUTH_TYPE_CHAP           0x00    /* chap��ʽ��֤ */
#define PORTAL_AUTH_TYPE_PAP            0x01    /* Pap��ʽ��֤ */

    UINT8   ucChallengeID;
    UINT8   aucChallenge[PORTAL_CHALLENGE_LEN];

    UINT8   aucNasIp[4];        /* NAS IP����AC����֤������ͨ�ŵĵ�ַ */
    CHAR    acNasId[256];       /* NAS ID�������û���ǰ�����VLAN��ȡ���ȵ�ID */

	UINT32 ulVlanId;
}AC_PA_HOSTAPD_AUTH_REQ_T;

/* HOSTAPD��֤Ӧ����Ϣ */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];
    UINT16  usSerialNo;         /* ͬ������Ϣ��ֵ */

    UINT32  ulAuthResult;       /* ��֤�����0: �ɹ� other: ʧ�� */
#define PORTAL_HOSTAPD_AUTH_SUCCESS     0
#define PORTAL_HOSTAPD_AUTH_ERR         1

    UINT32  ulSessionTimeout;               /* ����Ự���ʱ�䣬��λ����*/
    UINT32  ulAcctInterimInterval;          /* �Ʒ��ϱ��������λ����*/
    UINT32  ulIdleTimeOut;

#ifdef APP_PROJ_AC
    AC_USR_QOS_T        stQos;
#endif
	char acUserGroupName[128];/*add for user qos 20131015*/
}AC_PA_HOSTAPD_AUTH_ACK_T;

/* ֪ͨHOSTAPD��Ȩ������Ϣ */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];

    UINT16  usSerialNo;
}AC_PA_HOSTAPD_AUTH_OVER_NTF_T;

/* Add by majp for internal-portal-server 2013-05-21 start*/
#define INTERNAL_PORTAL_PA_MSG_AUTH_REQ                          13426         //portal server  ������֤��Ϣ
#define INTERNAL_PORTAL_PA_MSG_AUTH_RSP                          13427 //portal server ������֤��Ӧ��Ϣ
#define INTERNAL_PORTAL_PA_MSG_USR_LOGOUT_REQ               13428 //portal server ����������Ϣ
#define INTERNAL_PORTAL_PA_MSG_USR_LOGOUT_RSP               13429 //portal server ����������Ӧ��Ϣ

typedef struct {
    UINT32 ulWebSn;
    UINT8 aucIp[4];  //�ն�ip��ַ
    char acUserName[PORTAL_MAX_USERNAME_LEN+1]; //�û���
    char acPassword[PORTAL_MAX_PASSWORD_LEN+1]; //����
	UINT8 aucUserMac[6];  //�ն�MAC
    UINT32 ulAuthType; //��֤���� chap : 0x00 pap : 0x01
}__attribute__ ((packed))INTERNAL_PORTAL_PA_AUTH_REQ_T;

typedef struct {
    UINT32 ulWebSn;
    UINT32 ulAuthRes;  //��֤���  �ɹ���0 ��ʧ�ܣ�1
} INTERNAL_PORTAL_PA_AUTH_RSP_T;

typedef struct {
    UINT32 ulWebSn;
    UINT8 aucIp[4];  //�ն�ip��ַ
    UINT8 aucUserMac[6];  //�ն�MAC
}INTERNAL_PORTAL_PA_USR_LOGOUT_REQ_T;

typedef struct {
    UINT32 ulWebSn;
    UINT32 ulLogoutRes;  //���߽��  �ɹ���0 ��ʧ�ܣ�1
} INTERNAL_PORTAL_PA_USR_LOGOUT_RSP_T;

void ps_challenge_pwd(char* szPwd, UINT8 chap_id, UINT8* chap_challenge, BYTE *pucChallengedPwd);
VOID ac_pa_handle_internal_ps_req_auth_msg(INTERNAL_PORTAL_PA_AUTH_REQ_T *pstMsg, UINT32 ulMsgSize);
VOID ac_pa_handle_internal_ps_req_useroffline_msg(INTERNAL_PORTAL_PA_USR_LOGOUT_REQ_T *pstMsg, UINT32 ulMsgLen);
#endif /* AC_PA_PUBLIC_H */



