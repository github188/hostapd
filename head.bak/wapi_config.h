
#ifndef _WAPI_CONFIG_H_
#define _WAPI_CONFIG_H_

typedef enum { RekeyDisabled = 1, RekeyTimeBased = 2, RekeyPacketBased = 3,  RekeyTimePacketBased = 4} RekeyTypes;

typedef struct {
	Boolean gb15629dot11wapiEnabled;
	Boolean gb15629dot11wapiPreauthenticationEnabled;
	RekeyTypes gb15629dot11wapiConfigUnicastRekeyMethod;
	u_int32_t gb15629dot11wapiConfigUnicastRekeyTime;
	u_int32_t gb15629dot11wapiConfigUnicastRekeyPackets;

	int gb15629dot11wapiConfigMulticastCipher;
	
	RekeyTypes gb15629dot11wapiConfigMulticastRekeyMethod;
	u_int32_t gb15629dot11wapiConfigMulticastRekeyTime;
	u_int32_t gb15629dot11wapiConfigMulticastRekeyPackets;
	Boolean gb15629dot11wapiConfigMulticastRekeyStrict;
	
	u_int8_t gb15629dot11wapiConfigPSKValue[32];
	u_int8_t gb15629dot11wapiConfigPSKPassPhraseLength;
	u_int8_t gb15629dot11wapiConfigPSKPassPhrase[100];
	u_int32_t gb15629dot11wapiConfigCertificateUpdateCount;
	u_int32_t gb15629dot11wapiConfigMulticastUpdateCount;
	u_int32_t gb15629dot11wapiConfigUnicastUpdateCount;
	u_int32_t gb15629dot11wapiConfigBKLifetime;
	u_int32_t gb15629dot11wapiConfigBKReauthThreshold;
	u_int32_t gb15629dot11wapiConfigSATimeout;	
} Gb15629dot11wapiConfigEntry;

typedef struct {
//	u_int32_t gb15629dot11wapiConfigUnicastCipherIndex;
	u_int32_t gb15629dot11wapiConfigUnicastCipher;
	u_int32_t gb15629dot11wapiConfigUnicastCipherEnabled;
//	u_int32_t gb15629dot11wapiConfigUnicastCipherSize;
} Gb15629dot11wapiConfigUnicastCiphersEntry;

typedef struct {
//	u_int32_t gb15629dot11wapiConfigAuthenticationSuiteIndex;
	u_int32_t gb15629dot11wapiConfigAuthenticationSuite;
	u_int32_t gb15629dot11wapiConfigAuthenticationSuiteEnabled;
} Gb15629dot11wapiConfigAuthenticationSuitesEntry;

typedef struct {
	u_int32_t accessAuthWaitTime;
	u_int32_t certAuthWaitTime;
	u_int32_t otherWaitTime;
} WaiPacketWaitTime;

typedef struct {
	char *certificateFileAE;
}WaiCertificateConfig;

struct wapi_config {
	WaiPacketWaitTime waiPacketWaitTime;
	Gb15629dot11wapiConfigEntry gb15629dot11wapiConfigEntry;
	Gb15629dot11wapiConfigUnicastCiphersEntry gb15629dot11wapiConfigUnicastCiphersEntry;
	Gb15629dot11wapiConfigAuthenticationSuitesEntry gb15629dot11wapiConfigAuthenticationSuitesEntry;
	WaiCertificateConfig waiCertificateConfig;
};

struct wapi_vap;
int wapi_asu_init(void);
void wapiapd_ac_vap_init_wapiparam(struct wapi_vap *vap, AC_DEVM_WAPI_CONFIG_T *wapiCfg, u_int8_t *psk);
int wapi_apd_is_support_onlypsk(struct wapi_vap *vap) ;
int wapiapd_ac_vap_init_aecert(struct wapi_vap *vap, AC_DEVM_WAPICERTFILE_CONFIG_T *certCfg);
BOOL wapiapd_ac_vap_init_asu(AC_DEVM_WAPIAS_CONFIG_T *asuCfg);
void wapiapd_ac_vap_deinit_asu(void);

#endif
