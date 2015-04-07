/******************************************************************************
模块名      : HOSTAPD WTP STATS
文件名      : hostapd_wtp_stats.h
相关文件    :
实现功能    : HOSTAPD模块统计
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2010/08/05  叶恩云      创建
******************************************************************************/

#ifndef HOSTAPD_WTP_STATS_H
#define HOSTAPD_WTP_STATS_H

#ifdef __cplusplus
extern "C" {
#endif

struct hostapd_bss_stats{
	u_int32_t ulRecvAcVapCreate;
	u_int32_t ulRecvAcVapDestroy;
	u_int32_t ulRecvAcVapStart;
	u_int32_t ulRecvAcVapStop;

	u_int32_t ulRecvAcIoctl;
	u_int32_t ulRecvAcEapol;
	u_int32_t ulRecvAcPreauth;

	u_int32_t ulRecvDriverEvent;
	u_int32_t ulRecvDriverL2;

	u_int32_t ulRecvLocalEvent;
	u_int32_t ulRecvLocalL2;

	u_int32_t ulSendAcVapCreateAck;
	u_int32_t ulSendAcVapDestroyAck;
	u_int32_t ulSendAcVapStartAck;
	u_int32_t ulSendAcVapStopAck;
	u_int32_t ulSendAcIoctlAck;
	u_int32_t ulSendAcEapolAck;
	u_int32_t ulSendAcPreauthAck;

	u_int32_t ulSendAcVapCreateNack;
	
	u_int32_t ulSendAcEvent;
	u_int32_t ulSendAcIoctl;
	u_int32_t ulSendAcEapol;
	u_int32_t ulSendAcPreauth;

	u_int32_t ulSendLocalEvent;
	u_int32_t ulSendLocalL2;
};


void print_stats_all();

extern struct hostapd_bss_stats g_stBssStats[MAX_INTERFACES][MAX_BSSES];
#define hostapd_bss_stats_inc(_ucIfIndex,_ucBssIndex,_usEvent)	(g_stBssStats[(_ucIfIndex)][(_ucBssIndex)].ul##_usEvent++)

#ifdef __cplusplus
}
#endif

#endif
