#ifndef AC_PA_USER_DATA_H
#define AC_PA_USER_DATA_H

#define PORTAL_AUTH_STATE_NOTFINISH     AC_PORTAL_STATE_NOTFINISH
#define PORTAL_AUTH_STATE_FINISH        AC_PORTAL_STATE_FINISH
#define PORTAL_AUTH_STATE_UNKNOW        100

typedef struct
{
    UINT8   ucVer;
    UINT8   ucUserState;
    UINT8   ucType;
    UINT8   ucAuthType;

    UINT16  usSerialNo;
    UINT16  usReqID;

    UINT8   aucUserIP[4];

    UINT16  usUserPort;
    UINT8   aucUserMac[6];

    CHAR    acUserName[PORTAL_MAX_USERNAME_LEN+1];
    //CHAR    acPassword[PORTAL_MAX_PASSWORD_LEN+1];
    UINT8   aucChallenge[PORTAL_CHALLENGE_LEN];

    SOCKADDR    stPsAddr;
    INT32       iAddrLen;

	UINT32		ulStartTime;	/* 状态变化时间 */
    UINT32      ulAgingTime;    /* 老化时间(上电后的相对时间) */

	TIMER_ID_T	stTimerID;

	UINT8	    aucNasIp[4];	/* NAS IP */
	CHAR	    acNasId[256];	/* NAS ID */
    
    CHAR	    acVapSsid[32];		/* VAP SSID */
	UINT8	    aucBssid[6];		/* VAP BSSID */
	/*2012_1_21 add for Macserver not found*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	/*2012_1_21 add for Macserver not found*/

	UINT32 ulSessionTimeStart;	/*上线时间*/
	UINT32 ulSessionTimeStop;	/*下线时间*/
	UINT32 ulMacAuth;	/*0：PORTAL认证；1：MAC认证*/
	UINT32 ulTsAdd;

    UINT32      ulSessionTimeout;       /* 允许会话最大时间，单位：秒 */
    UINT32      ulAcctInterimInterval;  /* 计费上报间隔，单位：秒 */
    UINT32      ulIdleTimeOut;  /* 用户无流量下线时间，AAA下发单位：秒 */

	AC_USR_QOS_T	stQos;	            /* 用户QOS */
    UINT32 ulWebSn; //用于与web通信
    CHAR acUserGroupName[128];/*add for filterid */
}AC_PA_PROTAL_USER_DATA_T;

BOOL ac_pa_init_hash_table(UINT32 ulHashEntrySize, UINT32 ulMaxUserNum);
BOOL ac_pa_set_max_user(UINT32 ulMaxUserNum);

BOOL ac_pa_set_user_timer(AC_PA_PROTAL_USER_DATA_T *pstUserData);
BOOL ac_pa_remove_user_timer(AC_PA_PROTAL_USER_DATA_T *pstUserData);

AC_PA_PROTAL_USER_DATA_T* ac_pa_add_user(AC_PA_PROTAL_USER_DATA_T *pstUserData);
AC_PA_PROTAL_USER_DATA_T* ac_pa_get_user_data(UINT8* pucUserIP);
AC_PA_PROTAL_USER_DATA_T* ac_pa_get_user_data_by_mac(UINT8* pucUserMac, UINT32 ulAuthState);
AC_PA_PROTAL_USER_DATA_T* ac_pa_get_user_auth_state_by_mac(UINT8* pucUserMac);
AC_PA_PROTAL_USER_DATA_T* ac_pa_get_user_data_from_mac(UINT8* pucUserMac); //add by fangz for diff user from mac


BOOL ac_pa_remove_user(AC_PA_PROTAL_USER_DATA_T* pstUserData);
VOID ac_pa_get_user_list(UINT32 ulAuthState, UINT32 ulMaxNum, UINT8* paucUserIP, UINT32 *pulUserNum);
VOID ac_pa_scan_user_data(VOID);
BOOL ac_pa_is_user_valid(AC_PA_PROTAL_USER_DATA_T *pstUserData);
BOOL ac_pa_get_user_mac(UINT8* pucUserIP, UINT8* pucUserMac, UINT32 *pulAuthState);


VOID	ac_pa_usrm_set_auth_state_byip(UINT8 *pucUserIP, UINT32 ulAuthState);
BOOL ac_pa_usrm_set_auth_state(AC_PA_PROTAL_USER_DATA_T *pstUserData, UINT32 ulAuthState);
BOOL ac_pa_kernel_set_auth_over(UINT8* pucUserIP, UINT8* pucUserMac);

BOOL ac_pa_set_user_state(AC_PA_PROTAL_USER_DATA_T *pstUserData, UINT8 ucUserState);
BOOL ac_pa_init_timer_queue(VOID);

#ifdef PS_TEST1
BOOL ac_pa_hash_unit_test(VOID);
#endif

#endif  /* AC_PA_USER_DATA_H */

