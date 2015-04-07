#ifndef IEEE80211_CONFIG_PRIVATE_H
#define IEEE80211_CONFIG_PRIVATE_H

#define CONFIG_ASSERT_INT(a, s, ...) {\
	if(!(a)){printf(s, __VA_ARGS__); printf("Line(%d)\n", __LINE__);\
		 return -1; }\
}

typedef struct tagsysParaTbl
{
	T_apBasicSetup_i     tapBscSetup;
	T_apAdvancedSetup_i  tapAdvSetup;
	T_apSecuritySetup_i  tapScuSetup;
	T_adhocBasicSetup_i  tadhBscSetup;
	T_adhocAdvancedSetup_i  tadhAdvSetup;
} T_sysParaTbl;

/* º¯ÊýÉùÃ÷ */
static int 
ieee80211_apbsc_setcfg(char *dev, T_apBasicSetup_i *ptapBscSetup);
static int 
ieee80211_apadv_setcfg(char *dev, T_apAdvancedSetup_i *ptapAdvSetup);
static int 
ieee80211_apscu_setcfg(char *dev, T_apSecuritySetup_i *ptapScuSetup);
static int 
ieee80211_adhbsc_setcfg(char * dev, T_adhocBasicSetup_i *ptadhBscSetup);
static int 
ieee80211_adhadv_setcfg(char * dev, T_adhocAdvancedSetup_i *ptadhAdvSetup);

static int
checksocket(void);
static int
set80211priv(const char *dev, int op, void *data, int len);

/* AP Basic setup */
static int
apmodeset(char *dev, long apMode);
static int
apmodebitset(char *dev, long apmode);
static int
apchannelset(char *dev, long apchannel);
static int
apssidset(char *dev, char *ptssid);
static int
apbroadcastssidset(char *dev, long apBroadcastSsid);

/* AP Advanced setup	 */
static int
apBIset(char *dev, long apBeaconInterval);
static int
apDIset(char *dev, long apDtimInterval);
static int
apFTset(char *dev, long apFragmentationThreshold);
static int
apRTset(char *dev, long apRtsThreshold);
static int
apCPMset(char *dev, long apCtsProtectionMode);
static int
apAuthset(char *dev, long apAuthenticationType);
static int
apTxRateset(char *dev, unsigned long apTxRate);

/* AP Security setup  */
static int
apSecurityset(char *dev, long apSecurity);
static int
apScuParaset(char *dev, T_apSecuritySetup_i *ptapScuSetup);
static int
apScuKeyset(char *dev, T_apSecuritySetup_i *ptapScuSetup);
static int
scuWpaset(char *dev);
static int
scuKeymgmtset(char *dev, T_apSecuritySetup_i *ptapScuSetup);


/* adhoc advanced setup */
static int
txPowset(char *dev, unsigned long txpow);
static int
maxRetryset(char *dev, unsigned long retrynum);
static int
ieee80211_get_adhmac(char *dev, u_int8_t *padhocMac);
static int
ieee80211_get_txpow(char *dev, u_int32_t *pmaxTxPower);

#endif
