/******************************************************************************
模块名      : HOSTAPD AC STATS
文件名      : hostapd_ac_stats.h
相关文件    :
实现功能    : HOSTAPD模块统计
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2011/01/25  叶恩云      创建
******************************************************************************/

#ifndef HOSTAPD_AC_STATS_H
#define HOSTAPD_AC_STATS_H

#ifdef __cplusplus
extern "C" {
#endif

struct hostapd_acbss_stats{
	u_int32_t ulVapStart;
	u_int32_t ulVapStartMacUpdate;
	u_int32_t ulVapStartCfgUpdate;
	u_int32_t ulVapStartLinkNormal;
	u_int32_t ulVapStartTimeout;

	u_int32_t ulIoctlTimeoutVap;
	u_int32_t ulIoctlTimeoutSta;

	u_int32_t ulRecvApVapCreateAck;
	u_int32_t ulRecvApVapDestroyAck;
	u_int32_t ulRecvApVapStartAck;
	u_int32_t ulRecvApVapStopAck;
	u_int32_t ulRecvApIoctlAck;
	u_int32_t ulRecvApEapolAck;
	u_int32_t ulRecvApPreauthAck;
	u_int32_t ulRecvApOtherAck;

	u_int32_t ulRecvApVapCreateNack;

	u_int32_t ulRecvApEvent;
	u_int32_t ulRecvApEventLogin;
	u_int32_t ulRecvApEventLogout;
	u_int32_t ulRecvApIoctl;
	u_int32_t ulRecvApEapol;
	u_int32_t ulRecvApPreauth;

	u_int32_t ulSendApVapCreate;
	u_int32_t ulSendApVapDestroy;
	u_int32_t ulSendApVapStart;
	u_int32_t ulSendApVapStop;
	u_int32_t ulSendApIoctl;
	u_int32_t ulSendApEapol;
	u_int32_t ulSendApPreauth;
	u_int32_t ulSendApOther;

	u_int32_t ulSendApFailed;

	u_int32_t ulStaDiffAp;
	u_int32_t ulStaDiffAc;
};



#define hostapd_acbss_stats_inc(_bss,_value)	((_bss)->vap_stats._value++)

#ifdef __cplusplus
}
#endif

#endif
