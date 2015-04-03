#include "OssApi.h"
#include "ac_public.h"

#include "includes.h"
#include "hostapd_wtp.h"
#include "hostapd_wtp_stats.h"


struct hostapd_bss_stats g_stBssStats[MAX_INTERFACES][MAX_BSSES] = {0};


void print_stats(BYTE ucIfIndex, BYTE ucBssIndex)
{
	struct hostapd_bss_stats stStatsZero = {0}, *pstStats = NULL;
	char file_name[32] = {0};
	FILE *fp = NULL;

	if(ucIfIndex >= MAX_INTERFACES
		|| ucBssIndex >= MAX_BSSES){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, ucIfIndex.\n", __func__) ;
		return;
	}
		
	pstStats = &g_stBssStats[ucIfIndex][ucBssIndex];
	if(os_memcmp(pstStats, &stStatsZero, sizeof(stStatsZero)) == 0)
		return;

	sprintf(file_name, "/var/log/hostapd%d_%d.stats", ucIfIndex, ucBssIndex);
	if((fp = fopen(file_name,"w")) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, can not open file: %s.\n", __func__, file_name) ;
		return;
	}

	fprintf(fp, "RecvAcVapCreate:\t%u.\n", pstStats->ulRecvAcVapCreate);
	fprintf(fp, "RecvAcVapDestroy:\t%u.\n", pstStats->ulRecvAcVapDestroy);
	fprintf(fp, "RecvAcVapStart:\t%u.\n", pstStats->ulRecvAcVapStart);
	fprintf(fp, "RecvAcVapStop:\t%u.\n", pstStats->ulRecvAcVapStop);
	fprintf(fp, "\n");

	fprintf(fp, "RecvAcIoctl:\t%u.\n", pstStats->ulRecvAcIoctl);
	fprintf(fp, "RecvAcEapol:\t%u.\n", pstStats->ulRecvAcEapol);
	fprintf(fp, "RecvAcPreauth:\t%u.\n", pstStats->ulRecvAcPreauth);
	fprintf(fp, "\n");

	fprintf(fp, "RecvDriverEvent:\t%u.\n", pstStats->ulRecvDriverEvent);
	fprintf(fp, "RecvDriverL2:\t%u.\n", pstStats->ulRecvDriverL2);
	fprintf(fp, "\n");

	fprintf(fp, "RecvLocalEvent:\t%u.\n", pstStats->ulRecvLocalEvent);
	fprintf(fp, "RecvLocalL2:\t%u.\n", pstStats->ulRecvLocalL2);
	fprintf(fp, "\n");

	fprintf(fp, "SendAcVapCreateAck:\t%u.\n", pstStats->ulSendAcVapCreateAck);
	fprintf(fp, "SendAcVapDestroyAck:\t%u.\n", pstStats->ulSendAcVapDestroyAck);
	fprintf(fp, "SendAcVapStartAck:\t%u.\n", pstStats->ulSendAcVapStartAck);
	fprintf(fp, "SendAcVapStopAck:\t%u.\n", pstStats->ulSendAcVapStopAck);
	fprintf(fp, "SendAcIoctlAck:\t%u.\n", pstStats->ulSendAcIoctlAck);
	fprintf(fp, "SendAcEapolAck:\t%u.\n", pstStats->ulSendAcEapolAck);
	fprintf(fp, "SendAcPreauthAck:\t%u.\n", pstStats->ulSendAcPreauthAck);
	fprintf(fp, "\n");
	
	fprintf(fp, "SendAcVapCreateNack:\t%u.\n", pstStats->ulSendAcVapCreateNack);
	fprintf(fp, "\n");
	
	fprintf(fp, "SendAcEvent:\t%u.\n", pstStats->ulSendAcEvent);
	fprintf(fp, "SendAcIoctl:\t%u.\n", pstStats->ulSendAcIoctl);
	fprintf(fp, "SendAcEapol:\t%u.\n", pstStats->ulSendAcEapol);
	fprintf(fp, "SendAcPreauth:\t%u.\n", pstStats->ulSendAcPreauth);
	fprintf(fp, "\n");
	
	fprintf(fp, "SendLocalEvent:\t%u.\n", pstStats->ulSendLocalEvent);
	fprintf(fp, "SendLocalL2:\t%u.\n", pstStats->ulSendLocalL2);
	fprintf(fp, "\n");
	
	fclose(fp);
	
	return;
}


void print_stats_all()
{
	int i, j;

	for(i = 0; i < MAX_INTERFACES; i++)
		for(j = 0; j < MAX_BSSES; j++)
			print_stats(i, j);
		
	return;
}