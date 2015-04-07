#ifndef AC_PA_PUBLIC_H
#define AC_PA_PUBLIC_H

#define PORTAL_AUTH_MODE_OFF                0   /* 不需要WEB认证 */
#define PORTAL_AUTH_MODE_ON                 1   /* 需要WEB认证 */

#ifdef APP_PROJ_AC

#define EV_AC_PA_PORTAL_MSG                 ((UINT16)EV_PA_BEGIN + 1)

#define EV_AC_PA_HOSTAPD_AUTH_REQ_MSG       ((UINT16)EV_PA_BEGIN + 100) /* PA->HOSTAPD: 鉴权请求 */
#define EV_AC_PA_HOSTAPD_AUTH_ACK_MSG       ((UINT16)EV_PA_BEGIN + 101) /* HOSTAPD->PA: 鉴权应答 */

#define EV_AC_PA_HOSTAPD_AUTH_OVER_NTF_MSG  ((UINT16)EV_PA_BEGIN + 102) /* PA->HOSTAPD: 鉴权成功通知 */

#define EV_AC_PA_HOSTAPD_LOGOUT_NTF_MSG     ((UINT16)EV_PA_BEGIN + 110) /* PA->HOSTAPD: 用户下线通知 */
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

/* portal本地侦听端口 */
#define AC_PA_DEFAULT_PORT                  2000

/* portal本地web服务器侦听UDP端口（AC-PA通知其配置数据变更） */
#define AC_PA_WEB_LISTEN_PORT               30171

/* 内部消息（ucVer、ucType、ucAuthType为0xff时）*/
#define AC_PA_WEB_GET_CFG_REQ               0x20    /* PA-WEB -> AC: 获取配置数据 */
#define AC_PA_WEB_HEART_BEAT_IND            0x30    /* PA-WEB -> AC: 心跳 */
#define AC_PA_HR_SET_IPSSID_NTF		        0x50    /* HR -> AC */

#define AC_PA_PABK_CFG_CHANGE_NTF           0x80    /* AC-PA  -> AC-PABK: 通知配置数据变更 */

#define AC_PA_CTL_MSG_BEGIN                 0xb0    /* pactl消息 */

#define AC_PA_CTL_LIST_USER_REQ             (AC_PA_CTL_MSG_BEGIN+0)     /* pactl获取用户列表 */
#define AC_PA_CTL_LIST_USER_ACK             (AC_PA_CTL_MSG_BEGIN+1)     /* pactl获取用户列表 */

#define AC_PA_CTL_GET_USER_REQ              (AC_PA_CTL_MSG_BEGIN+2)     /* pactl获取用户信息 */
#define AC_PA_CTL_GET_USER_ACK              (AC_PA_CTL_MSG_BEGIN+3)     /* pactl获取用户信息 */

#define AC_PA_CTL_DEL_USER_REQ              (AC_PA_CTL_MSG_BEGIN+4)     /* pactl删除用户 */
#define AC_PA_CTL_DEL_USER_ACK              (AC_PA_CTL_MSG_BEGIN+5)     /* pactl删除用户 */

#define AC_PA_CTL_LIST_IP_REQ               (AC_PA_CTL_MSG_BEGIN+6)     /* pactl获取用户IP列表 */
#define AC_PA_CTL_LIST_IP_ACK               (AC_PA_CTL_MSG_BEGIN+7)     /* pactl获取用户IP列表 */

/* PA发送给HOSTAPD的认证请求消息 */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];
    UINT16  usSerialNo;

    CHAR    acUserName[PORTAL_MAX_USERNAME_LEN+1];

    UINT8   ucPasswordLen;
    CHAR    acPassword[PORTAL_MAX_PASSWORD_LEN+1];   /* 对于PAP认证，为变长字符串0-253；
                                                        对于CHAP认证，为16字节定长的二进制数 */
    UINT8   ucAuthType;
#define PORTAL_AUTH_TYPE_CHAP           0x00    /* chap方式认证 */
#define PORTAL_AUTH_TYPE_PAP            0x01    /* Pap方式认证 */

    UINT8   ucChallengeID;
    UINT8   aucChallenge[PORTAL_CHALLENGE_LEN];

    UINT8   aucNasIp[4];        /* NAS IP：填AC与认证服务器通信的地址 */
    CHAR    acNasId[256];       /* NAS ID：根据用户当前接入的VLAN获取到热点ID */

	UINT32 ulVlanId;
}AC_PA_HOSTAPD_AUTH_REQ_T;

/* HOSTAPD认证应答消息 */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];
    UINT16  usSerialNo;         /* 同请求消息的值 */

    UINT32  ulAuthResult;       /* 认证结果，0: 成功 other: 失败 */
#define PORTAL_HOSTAPD_AUTH_SUCCESS     0
#define PORTAL_HOSTAPD_AUTH_ERR         1

    UINT32  ulSessionTimeout;               /* 允许会话最大时间，单位：秒*/
    UINT32  ulAcctInterimInterval;          /* 计费上报间隔，单位：秒*/
    UINT32  ulIdleTimeOut;

#ifdef APP_PROJ_AC
    AC_USR_QOS_T        stQos;
#endif
	char acUserGroupName[128];/*add for user qos 20131015*/
}AC_PA_HOSTAPD_AUTH_ACK_T;

/* 通知HOSTAPD鉴权结束消息 */
typedef struct
{
    UINT8   aucUserIP[4];
    UINT8   aucUserMac[6];

    UINT16  usSerialNo;
}AC_PA_HOSTAPD_AUTH_OVER_NTF_T;

/* Add by majp for internal-portal-server 2013-05-21 start*/
#define INTERNAL_PORTAL_PA_MSG_AUTH_REQ                          13426         //portal server  请求认证消息
#define INTERNAL_PORTAL_PA_MSG_AUTH_RSP                          13427 //portal server 请求认证响应消息
#define INTERNAL_PORTAL_PA_MSG_USR_LOGOUT_REQ               13428 //portal server 请求下线消息
#define INTERNAL_PORTAL_PA_MSG_USR_LOGOUT_RSP               13429 //portal server 请求下线响应消息

typedef struct {
    UINT32 ulWebSn;
    UINT8 aucIp[4];  //终端ip地址
    char acUserName[PORTAL_MAX_USERNAME_LEN+1]; //用户名
    char acPassword[PORTAL_MAX_PASSWORD_LEN+1]; //密码
	UINT8 aucUserMac[6];  //终端MAC
    UINT32 ulAuthType; //认证类型 chap : 0x00 pap : 0x01
}__attribute__ ((packed))INTERNAL_PORTAL_PA_AUTH_REQ_T;

typedef struct {
    UINT32 ulWebSn;
    UINT32 ulAuthRes;  //认证结果  成功：0 ，失败：1
} INTERNAL_PORTAL_PA_AUTH_RSP_T;

typedef struct {
    UINT32 ulWebSn;
    UINT8 aucIp[4];  //终端ip地址
    UINT8 aucUserMac[6];  //终端MAC
}INTERNAL_PORTAL_PA_USR_LOGOUT_REQ_T;

typedef struct {
    UINT32 ulWebSn;
    UINT32 ulLogoutRes;  //下线结果  成功：0 ，失败：1
} INTERNAL_PORTAL_PA_USR_LOGOUT_RSP_T;

void ps_challenge_pwd(char* szPwd, UINT8 chap_id, UINT8* chap_challenge, BYTE *pucChallengedPwd);
VOID ac_pa_handle_internal_ps_req_auth_msg(INTERNAL_PORTAL_PA_AUTH_REQ_T *pstMsg, UINT32 ulMsgSize);
VOID ac_pa_handle_internal_ps_req_useroffline_msg(INTERNAL_PORTAL_PA_USR_LOGOUT_REQ_T *pstMsg, UINT32 ulMsgLen);
#endif /* AC_PA_PUBLIC_H */



