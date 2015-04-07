/*
 */

#ifndef _L2WCOMMON_H
#define _L2WCOMMON_H

extern BOOL l2w_ioctl_add_vdev(char *pcRealDevName, unsigned long ulVdevId);
extern BOOL l2w_ioctl_del_vdev(char *pcRealDevName, unsigned long ulVdevId);
extern BOOL l2w_ioctl_add_dev(unsigned long ulDevId, unsigned long ulDevType, char *pcDevName);
extern BOOL l2w_ioctl_del_dev(unsigned long	ulDevId);
extern BOOL l2w_ioctl_add_br(unsigned long	ulDevId,
							unsigned long	ulBrId,
							unsigned long	ulBrType,
							char *pcBrName,
							unsigned char	 *pcBrIp);
extern BOOL l2w_ioctl_del_br(unsigned long	ulDevId,
							unsigned long	ulBrId);
extern BOOL l2w_ioctl_add_if(unsigned long	ulDevId,
							unsigned long	ulIfId,
							unsigned long	ulIfType,
							char *pcIfName,
							char *pcSsid);
extern BOOL l2w_ioctl_del_if(unsigned long	ulDevId, 
							unsigned long	ulIfId);
extern BOOL l2w_ioctl_bind_if(unsigned long	ulDevId,
						unsigned long	ulBrId,
						unsigned long	ulIfId);
extern BOOL l2w_ioctl_unbind_if(unsigned long	ulDevId,
								unsigned long	ulBrId,
								unsigned long	ulIfId);
extern BOOL l2w_ioctl_add_user(unsigned long	ulDevId,
							unsigned long	ulIfId,
							unsigned char *pucMac,
							unsigned long ulVlanId,
							unsigned long ulUserType,
							char *pcSsid);
extern BOOL l2w_ioctl_del_user(unsigned long	ulDevId,
								unsigned long	ulIfId,
								unsigned char *pucMac);
extern BOOL l2w_ioctl_set_userip(unsigned char *pucMac,
								unsigned char *pucIp);
extern BOOL l2w_ioctl_set_userqos(unsigned char *pucMac,
								unsigned long ulPriority,
								unsigned long ulUpBandMin,
								unsigned long ulUpBandMax,
								unsigned long ulDownBandMin,
								unsigned long ulDownBandMax);
extern BOOL l2w_ioctl_get_allidsuserlist(void);								
extern BOOL l2w_ioctl_get_vdevlist(void);
extern BOOL l2w_ioctl_get_devlist(void);
extern BOOL l2w_ioctl_get_allbrlist(void);
extern BOOL l2w_ioctl_get_alliflist(void);
extern BOOL l2w_ioctl_get_allbriflist(void);
extern BOOL l2w_ioctl_get_alluserlist(void);
extern BOOL l2w_ioctl_get_devbrlist(unsigned long ulDevId);
extern BOOL l2w_ioctl_get_deviflist(unsigned long ulDevId);
extern BOOL l2w_ioctl_get_briflist(unsigned long ulDevId,
							unsigned long ulBrId);
extern BOOL l2w_ioctl_get_devuserlist(unsigned long ulDevId);
extern BOOL l2w_ioctl_set_printlevel(unsigned long ulPrintLevel);
extern BOOL l2w_ioctl_get_printlevel(void);
extern BOOL l2w_ioctl_set_mydevcfg(unsigned long ulDevId);
extern BOOL l2w_ioctl_set_wtprunmode (unsigned long ulRunMode);
extern BOOL l2w_ioctl_get_mydevcfg(void);
extern BOOL l2w_ioctl_set_acip(unsigned char *pucIp);
extern BOOL  l2w_ioctl_get_acip(void);

extern BOOL l2w_ioctl_add_vlan(L2W_ADD_VLAN_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_del_vlan(L2W_DEL_VLAN_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_add_vlanif(L2W_ADD_VLANIF_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_del_vlanif(L2W_DEL_VLANIF_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_add_vlanmac(L2W_ADD_VLANMAC_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_del_vlanmac(L2W_DEL_VLANMAC_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_add_vlanssid(L2W_ADD_VLANSSID_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_del_vlanssid(L2W_DEL_VLANSSID_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_add_vlanaccmac(L2W_ADD_VLANACCMAC_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_del_vlanaccmac(L2W_DEL_VLANACCMAC_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_set_igmpproxy(L2W_SET_IGMPPROXY_ARGS_T *pstArgs);
extern BOOL l2w_ioctl_set_igmpsnoop(L2W_SET_IGMPSNOOP_ARGS_T *pstArgs);

extern char gcSysCmd[128];

#define CLRSYSCMD	{memset(gcSysCmd, 0, 128);}
#if 0
#define SYSTEM(c) {system( c ); syslog(5,  "system: %s\n", c );}
#endif
extern int	SYSTEM(char *cmd);

/******************************* 源文件结束 **********************************/


#endif

