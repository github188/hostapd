#include "OssApi.h"
#include "ac_public.h"

#include "includes.h"
#include "hostapd.h"
#include "ap.h"
#include "hostapd_ac_stats.h"


#define HOSTAPD_PRINT_MODE_SIMPLE	0
#define HOSTAPD_PRINT_MODE_ALL		1

static UINT32 g_ulPrintPeriod = 0;
static UINT32 g_ulPrintMode = HOSTAPD_PRINT_MODE_SIMPLE;


static void print_period_read(VOID)
{
	UINT32      ulKeyNum;
    char        acFile[256];

	VM_PROPERTY_DESC_T stDesc[] = {
		{"print_period",     PROPERTY_INT, 0, (UINT32)0, &g_ulPrintPeriod},
		{"print_mode",     PROPERTY_INT, 0, (UINT32)0, &g_ulPrintMode},	
	};

	ulKeyNum = sizeof(stDesc)/sizeof(stDesc[0]);


	/* ÅäÖÃÎÄ¼þ */
    memset(acFile,0,sizeof(acFile));
    sprintf(acFile,"%s%s%s",VmGetUsrRootPath(),WLC_CONFIG_DIR,PROFILE_HOSTAPD);
	VmReadProperty(PROFILE_HOSTAPD, ulKeyNum, &stDesc[0]);

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, print_period=%d, print_mode(%d).\n", __func__, g_ulPrintPeriod, g_ulPrintMode);

	if(g_ulPrintMode != HOSTAPD_PRINT_MODE_SIMPLE
		&& g_ulPrintMode != HOSTAPD_PRINT_MODE_ALL)
		g_ulPrintMode = HOSTAPD_PRINT_MODE_SIMPLE;
	
	return;
}


void print_stats(FILE * fp, struct hostapd_data *bss)
{
	struct hostapd_acbss_stats stStatsZero = {0}, *pstStats = NULL;

	if(fp == NULL
		|| bss == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return;
	}
		
	pstStats = &bss->vap_stats;
	if(os_memcmp(pstStats, &stStatsZero, sizeof(stStatsZero)) == 0)
		return;

	fprintf(fp, "vapid = %u/%u/%u, state(%d): %s, wtp's state(%d).\n", 
		bss->iface->pstWtp->usWtpId, bss->iface->interface_id, bss->vap_id, bss->state, bss->state?"FAULT":"NORMAL", bss->iface->pstWtp->state);
	fprintf(fp, "bssid:\t"MACSTR".\n", MAC2STR(bss->conf->bssid));

	if(g_ulPrintMode == HOSTAPD_PRINT_MODE_SIMPLE){
		fprintf(fp, "ulVapStart:\t%u.\n", pstStats->ulVapStart);
		fprintf(fp, "ulRecvApVapStartAck:\t%u.\n", pstStats->ulRecvApVapStartAck);
		fprintf(fp, "ulRecvApEventLogin:\t%u.\n", pstStats->ulRecvApEventLogin);

		fprintf(fp, "\n");
		
		return ;
	}

	fprintf(fp, "ulVapStart:\t%u.\n", pstStats->ulVapStart);
	fprintf(fp, "ulVapStartMacUpdate:\t%u.\n", pstStats->ulVapStartMacUpdate);
	fprintf(fp, "ulVapStartCfgUpdate:\t%u.\n", pstStats->ulVapStartCfgUpdate);
	fprintf(fp, "ulVapStartLinkNormal:\t%u.\n", pstStats->ulVapStartLinkNormal);
	fprintf(fp, "ulVapStartTimeout:\t%u.\n", pstStats->ulVapStartTimeout);
	
	fprintf(fp, "ulIoctlTimeoutVap:\t%u.\n", pstStats->ulIoctlTimeoutVap);
	fprintf(fp, "ulIoctlTimeoutSta:\t%u.\n", pstStats->ulIoctlTimeoutSta);

	fprintf(fp, "ulRecvApVapCreateAck:\t%u.\n", pstStats->ulRecvApVapCreateAck);
	fprintf(fp, "ulRecvApVapDestroyAck:\t%u.\n", pstStats->ulRecvApVapDestroyAck);
	fprintf(fp, "ulRecvApVapStartAck:\t%u.\n", pstStats->ulRecvApVapStartAck);
	fprintf(fp, "ulRecvApVapStopAck:\t%u.\n", pstStats->ulRecvApVapStopAck);
	fprintf(fp, "ulRecvApIoctlAck:\t%u.\n", pstStats->ulRecvApIoctlAck);
	fprintf(fp, "ulRecvApEapolAck:\t%u.\n", pstStats->ulRecvApEapolAck);
	fprintf(fp, "ulRecvApPreauthAck:\t%u.\n", pstStats->ulRecvApPreauthAck);
	fprintf(fp, "ulRecvApOtherAck:\t%u.\n", pstStats->ulRecvApOtherAck);
	
	fprintf(fp, "ulRecvApVapCreateNack:\t%u.\n", pstStats->ulRecvApVapCreateNack);
	
	fprintf(fp, "ulRecvApEvent:\t%u.\n", pstStats->ulRecvApEvent);
	fprintf(fp, "ulRecvApEventLogin:\t%u.\n", pstStats->ulRecvApEventLogin);
	fprintf(fp, "ulRecvApEventLogout:\t%u.\n", pstStats->ulRecvApEventLogout);	
	fprintf(fp, "ulRecvApIoctl:\t%u.\n", pstStats->ulRecvApIoctl);	
	fprintf(fp, "ulRecvApEapol:\t%u.\n", pstStats->ulRecvApEapol);
	fprintf(fp, "ulRecvApPreauth:\t%u.\n", pstStats->ulRecvApPreauth);
	
	fprintf(fp, "ulSendApVapCreate:\t%u.\n", pstStats->ulSendApVapCreate);
	fprintf(fp, "ulSendApVapDestroy:\t%u.\n", pstStats->ulSendApVapDestroy);
	fprintf(fp, "ulSendApVapStart:\t%u.\n", pstStats->ulSendApVapStart);
	fprintf(fp, "ulSendApVapStop:\t%u.\n", pstStats->ulSendApVapStop);
	fprintf(fp, "ulSendApIoctl:\t%u.\n", pstStats->ulSendApIoctl);
	fprintf(fp, "ulSendApEapol:\t%u.\n", pstStats->ulSendApEapol);
	fprintf(fp, "ulSendApPreauth:\t%u.\n", pstStats->ulSendApPreauth);
	fprintf(fp, "ulSendApOther:\t%u.\n", pstStats->ulSendApOther);

	fprintf(fp, "ulSendApFailed:\t%u.\n", pstStats->ulSendApFailed);

	fprintf(fp, "ulStaDiffAp:\t%u.\n", pstStats->ulStaDiffAp);
	fprintf(fp, "ulStaDiffAc:\t%u.\n", pstStats->ulStaDiffAc);
	
	fprintf(fp, "\n");
	
	return;
}


void print_station_list(FILE * fp, struct hostapd_data *bss)
{
	struct sta_info *sta = NULL;
	int i = 0;

	if(fp == NULL
		|| bss == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, point is NULL.\n", __func__) ;
		return;
	}

	fprintf(fp, "vapid = %u/%u/%u.station list(%d).\n", bss->iface->pstWtp->usWtpId, bss->iface->interface_id, bss->vap_id, bss->num_sta);

	if(g_ulPrintMode == HOSTAPD_PRINT_MODE_SIMPLE){
		fprintf(fp, "\n");
		return;
	}

	for(sta = bss->sta_list; sta != NULL; sta = sta->next){
		fprintf(fp, "sta%d:"MACSTR".\n", i, MAC2STR(sta->addr));
		i++;
	}

	fprintf(fp, "\n");

	return;
}

void print_stats_all()
{
#if 0
	FILE *file_switch = NULL, * file_stats = NULL;
	static UINT32 ulPrintPeriod = 0;
	struct hostapd_data *bss = NULL;
	char buf[64] = {0};
	UINT32 i, j, k;

	print_period_read();
	if(!g_ulPrintPeriod)
		return;

	ulPrintPeriod++;
	if((ulPrintPeriod%g_ulPrintPeriod) != 0)
		return;

	if((file_switch = fopen("/usr/local/ac/config/hostapd.switch", "r")) == NULL)
		return;

	if((file_stats= fopen("/usr/local/ac/config/hostapd.stats", "w")) == NULL)
		return;

	while(! feof(file_switch)){
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), file_switch);

		if(strlen(buf) < 5)
			continue;
		
		if(sscanf(buf, "%d %d %d", &i, &j, &k) != 3)
			continue;

		bss = FindVapByIndex(i, j, k);
		if(bss == NULL)
			continue;

		print_stats(file_stats, bss);
		print_station_list(file_stats, bss);
	}

	fclose(file_switch);
	fclose(file_stats);
#endif		
	return;
}
