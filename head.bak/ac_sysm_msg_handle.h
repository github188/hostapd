#ifndef AC_SYSM_MSG_HANDLE_H
#define AC_SYSM_MSG_HANDLE_H


extern VOID ac_sysm_handle_cfg_change(VOID *pMsg);
extern VOID ac_sysm_handle_scan_timer_msg(VOID);
extern VOID ac_sysm_handle_set_time(VOID *pMsg, UINT16 usLen);
extern VOID ac_sysm_handle_get_dynainfo(VOID *pMsg, UINT16 usLen);


#endif /* AC_SYSM_MSG_HANDLE_H */



