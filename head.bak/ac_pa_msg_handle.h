#ifndef AC_PA_MSG_HANDLE_H
#define AC_PA_MSG_HANDLE_H


VOID ac_pa_handle_local_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_config_change_ind_msg(VOID);
VOID ac_pa_handle_web_get_cfg_req_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_web_heart_beat_ind_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_hr_set_ipssid(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ctl_list_user_req_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ctl_get_user_req_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ctl_del_user_req_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ctl_list_ip_req_msg(UINT8* pucMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_portal_msg(AC_PA_PORTAL_RELAY_MSG_T *pstMsg, UINT32 ulMsgSize);

VOID ac_pa_handle_ps_req_challenge_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ps_chap_req_auth_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ps_pap_req_auth_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_hostapd_auth_ack_msg(AC_PA_HOSTAPD_AUTH_ACK_T *pstMsg, UINT16 usMsgLen);
VOID ac_pa_handle_ps_aff_ack_auth_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgLen, SOCKADDR *pstAddr);
VOID ac_pa_handle_ps_req_logout_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ps_ack_logout_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_ps_req_info_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgSize, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_usrm_macauth_req_msg(AC_USRM_MACAUTH_REQ_MSG_T *pstMacAuthReq, UINT16 usLength);
VOID ac_pa_handle_ps_ack_macbinding_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgLen, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_ntf_user_logon(AC_PA_PROTAL_USER_DATA_T * pstUserData);
/*begin 2013.3.4 fangz #476 cmcc log*/
VOID ac_pa_ntf_user_logout(AC_PA_PROTAL_USER_DATA_T * pstUserData, CHAR * pcLogoutReason);
/*end 2013.3.4 fangz #476 cmcc log*/
VOID ac_pa_ntf_logout(AC_PA_PROTAL_USER_DATA_T * pstUserData);
VOID ac_pa_handle_ps_req_useroffline_msg(AC_PA_PORTAL_MSG_T *pstMsg, UINT32 ulMsgLen, SOCKADDR *pstAddr, INT32 iAddrLen);
VOID ac_pa_handle_usrm_authstatechange(AC_USRM_USER_CERTSTATE_CHANGE_IND_MSG_T *pstMsg, UINT16 usMsgLen);
VOID ac_pa_handle_usrm_session_timeout_ind_msg(AC_USRM_USER_SESSIONTIMEOUT_IND_MSG_T *pstMsg, UINT16 usMsgLen);
VOID ac_pa_handle_usrm_deluser_ind_msg(AC_USRM_USER_DEL_IND_MSG_T *pstMsg, UINT16 usMsgLen);
VOID ac_pa_handle_checkps_timer_msg(VOID);

VOID ac_pa_handle_user_timerout_msg(UINT32 *pulMsg);
VOID ac_pa_handle_get_portal_stat_req_msg(AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T *pstReq, UINT16 wLen);

#endif  /* AC_PA_MSG_HANDLE_H */

