#ifndef __WAPIAPD_AC_H__
#define __WAPIAPD_AC_H__

#define EV_WAPIAPD_IOCTL_REQ			(WORD16)(EV_WAPIAPD_BEGIN + 1)
#define EV_WAPIAPD_IOCTL_RSP			(WORD16)(EV_WAPIAPD_BEGIN + 10)
#define EV_WAPIAPD_EVENT_NEWSTA		(WORD16)(EV_WAPIAPD_BEGIN + 20)
#define EV_WAPIAPD_EVENT_DELSTA		(WORD16)(EV_WAPIAPD_BEGIN + 21)

#define EV_WAPIAPD_ENCAPED_WAI		(WORD16)(EV_WAPIAPD_BEGIN + 30)
#define EV_WAPIAPD_AGENT_CONFIG		(WORD16)(EV_WAPIAPD_BEGIN + 40)

#define EV_WAPIAPD_INTER_LOOP		(WORD16)(EV_WAPIAPD_BEGIN + 50)

typedef enum {
	IOCTL_TAG_NAME = 0,
	IOCTL_TAG_ADDR,
	
	IOCTL_TAG_DELKEY,
	IOCTL_TAG_ADDKEY,
	IOCTL_TAG_DEAUTH,
	IOCTL_TAG_DISASSOC,
	IOCTL_TAG_GETSEQNO,
	IOCTL_TAG_GETWEVERSION,
	IOCTL_TAG_SETPRIVACY,
	IOCTL_TAG_SETIFACEFLAG,

	IOCTL_TAG_SETWAPIMKS,
	IOCTL_TAG_SETWAPIUKS,
	IOCTL_TAG_SETWAPIAKMS,	
	IOCTL_TAG_SETWAPICAPS,
	IOCTL_TAG_SETAUTHORIZED,
}IoctlTag;

#define IOCTL_RESULT_SUCCESS		((u_int8_t)0)
#define IOCTL_RESULT_LENERR		((u_int8_t)1)
#define IOCTL_RESULT_FAIL		((u_int8_t)2)
#define IOCTL_RESULT_UNKNOW		((u_int8_t)3)

typedef enum {
	CONFIG_TAG_CREATEVAP = 0,
	CONFIG_TAG_DELETEVAP
}ConfigTag;

#define STA_HASH_SIZE 256
#define STA_HASH(sta) (sta[5])

#define AP_HASH_SIZE 256
#define AP_HASH_MAC(_mac) ((_mac)[5] | (_mac)[0])
#define AP_HASH_ID(_id) ((((((_id).ulWtpId) & 0x1f) << 3)  | (((_id).ulVapId) & 0x7)) & 0xff)

typedef enum { Unauthorized = 2, Authorized = 1 } PortState;
typedef enum { ForceUnauthorized = 1, ForceAuthorized = 3, Auto = 2 } PortTypes;
typedef unsigned int Counter;

#define WAPI_CIPHER_SMS4		BIT(0)

#define WAPI_KEY_MGMT_WAI		BIT(0)
#define WAPI_KEY_MGMT_PSK		BIT(1)

#define	WAPI_OUI			0x721400
#define	WAPI_CURRENT_VERSION		1
#define	WAPI_SUITES_LEN	4
#define	WAPI_PMKID_LEN	16
#define	WAPI_PMK_LEN		32
struct wapi_ie_data {
	int pairwise_cipher;
	int group_cipher;
	int key_mgmt;
	int capabilities;
	size_t num_pmkid;
	const u_int8_t *pmkid;
};

struct wapi_pmksa_cache_entry {
	struct wapi_pmksa_cache_entry *next, *hnext;
	u_int8_t pmkid[WAPI_PMKID_LEN];
	u_int8_t pmk[WAPI_PMK_LEN];
	size_t pmk_len;
	long expiration;
	int akmp; /* WPA_KEY_MGMT_* */
	u_int8_t spa[ETH_ALEN];

	u_int8_t *identity;
	size_t identity_len;
};

struct wapi_pmksa_cache {
#define WAPI_PMKID_HASH_SIZE 128
#define WAPI_PMKID_HASH(pmkid) (unsigned int) ((pmkid)[0] & 0x7f)
	struct wapi_pmksa_cache_entry *pmkid[WAPI_PMKID_HASH_SIZE];
	struct wapi_pmksa_cache_entry *pmksa;
	int pmksa_count;

	void (*free_cb)(struct wapi_pmksa_cache_entry *entry, void *ctx);
	void *ctx;
};

typedef struct {
	u_int32_t gb15629dot11wapiStatsVersion;
	Counter gb15629dot11wapiStatsWAISignatureErrors;
	Counter gb15629dot11wapiStatsWAIHMACErrors;
	Counter gb15629dot11wapiStatsWAIAuthenticationResultFailures;
	Counter gb15629dot11wapiStatsWAIDiscardCounters;
	Counter gb15629dot11wapiStatsWAITimeoutCounters;
	Counter gb15629dot11wapiStatsWAIFormatErrors;
	Counter gb15629dot11wapiStatsWAICertificateHandshakeFailures;
	Counter gb15629dot11wapiStatsWAIUnicastHandshakeFailures;
	Counter gb15629dot11wapiStatsWAIMulticastHandshakeFailures;
}Gb15629dot11wapiStatsEntry;

#define WAPI_SESSION_KEYLEN	16
struct wapi_ptk {
	u_int8_t wapi_uek[WAPI_SESSION_KEYLEN];
	u_int8_t wapi_uck[WAPI_SESSION_KEYLEN];
	u_int8_t wapi_mak[WAPI_SESSION_KEYLEN];
	u_int8_t wapi_kek[WAPI_SESSION_KEYLEN];	
};

struct wapi_gtk {
	u_int8_t wapi_gek[WAPI_SESSION_KEYLEN];
	u_int8_t wapi_gck[WAPI_SESSION_KEYLEN];
};


typedef struct waiFragment{
	u_int32_t tlen;
	u_int32_t len;
	u_int8_t fragno;
	u_int8_t *frag;
	struct waiFragment *next;
}WaiFragment;

#define DRIVER_MTU	1500
typedef struct waiFragments{
	u_int16_t seqno;
	u_int8_t fragno;
	WaiFragment *first_frag;
	WaiFragment *last_frag;
}WaiFragments;

typedef struct {
	WaiFragments send_frags;
	WaiFragments recv_frags;
	WaiFragments recv_asu_frags;
//	WaiPacket send_packet;
	WaiPacket recv_packet;
	WaiPacket recv_asu_packet;
	u_int8_t last_send_subtype;
}WaiMessage;

typedef enum {
	TIMEOUT_SECURITY_ASSOCIATE,
	TIMEOUT_WAIT_PACKET,
	TIMEOUT_BKUPDATE_PERIOD,
	TIMEOUT_UKUPDATE_PERIOD,
	TIMEOUT_MKUPDATE_PERIOD,
}TimeoutSubtype;

typedef struct{
	enum {WAPI_EVENT_NULL, WAPI_EVENT_STA_ASSOC, WAPI_EVENT_STA_DISASSOC,
		WAPI_EVENT_AA_START, WAPI_EVENT_AA_REQ, WAPI_EVENT_CA_RESP,
		WAPI_EVENT_UK_START, WAPI_EVENT_UK_RESP,
		WAPI_EVENT_MK_START, WAPI_EVENT_MK_RESP,
		WAPI_EVENT_AUTHORIZE,
		WAPI_EVENT_MSG_ERROR, WAPI_EVENT_TIMEOUT,
	}event;
	
	union {
		TimeoutSubtype timeoutSubtype;
	}param;
}WapiEvent;

#define WAPI_NONCE_LEN 32
#define WAPI_CHALLENGE_LEN 32
#define WAPI_BK_LEN	16
#define WAPI_BKID_LEN	16
#define WAPI_ECDSA192_KEYLEN	24
struct wapi_state_machine {
	u_int8_t addr[ETH_ALEN];
	
	Boolean machine_loop;
	Boolean pending_deinit;
	enum { WAPI_INITIALIZE, WAPI_ASSOCIATE, WAPI_SUCCESS, WAPI_TERMINATE,
		WAPI_AA_ACTIVATION, WAPI_CA_RESPONSE, WAPI_AA_SUCCESS,
		WAPI_UK_ACTIVATION, WAPI_UK_SUCCESS, 
		WAPI_MK_ACTIVATION, WAPI_MK_SUCCESS,
	} wapi_state;

	WapiEvent wapi_event;
	u_int32_t wapi_timeouts;
	AccessResult accessResult;
	u_int8_t reasonCode;
	
	WaiMessage waiMessage;
		
	PortState authPortStatus;
	u_int32_t msgTimeouts;

	Boolean validBKSA;
	Boolean validPTK;
	Boolean validGTK;

	Boolean counted;
	Boolean groupUpdate;

	u_int8_t BKey[WAPI_BK_LEN];
	u_int8_t BKID[WAPI_BKID_LEN];
#define WAPI_USKID_MASK	0x01
	u_int8_t UskId;
	u_int8_t StaKeyId;
	u_int8_t AuthChallengeAE[WAPI_CHALLENGE_LEN];
	u_int8_t AuthChallengeASUE[WAPI_CHALLENGE_LEN];

	
	u_int8_t PairwiseChallengeAE[WAPI_CHALLENGE_LEN];
	u_int8_t PairwiseChallengeASUE[WAPI_CHALLENGE_LEN];
	
	u_int8_t AuthIdentifier[32];
	u_int8_t PairwiseIdentifier[32];	

	Boolean authByASU;

	u_int8_t publicKeyASUE[1 + 1 + 2 * WAPI_ECDSA192_KEYLEN];
	u_int8_t publicKeyAE[1 + 1 + 2 * WAPI_ECDSA192_KEYLEN];
	u_int8_t privateKeyAE[2 * WAPI_ECDSA192_KEYLEN + 1];
	
	struct wapi_ptk PTK[2];

	int pairwise_cipher;
	int key_mgmt;
	struct wapi_pmksa_cache_entry *pmksa;

	u_int8_t *wapi_ie;
	u_int32_t wapi_ie_len;

	Gb15629dot11wapiStatsEntry gb15629dot11wapiStatsEntry;
	
	struct wapi_vap *vap;
	struct sta_info *sta;
};

/* STA flags */
#define BIT(x) (1 << (x))
#define WLAN_STA_AUTH BIT(0)
#define WLAN_STA_ASSOC BIT(1)
#define WLAN_STA_PS BIT(2)
#define WLAN_STA_TIM BIT(3)
#define WLAN_STA_PERM BIT(4)
#define WLAN_STA_AUTHORIZED BIT(5)
#define WLAN_STA_PENDING_POLL BIT(6)
#define WLAN_STA_SHORT_PREAMBLE BIT(7)
#define WLAN_STA_PREAUTH BIT(8)
#define WLAN_STA_WME BIT(9)
#define WLAN_STA_NONERP BIT(31)
struct sta_info {
	struct sta_info *next; /* next entry in sta list */
	struct sta_info *hnext; /* next entry in hash table list */
	u_int8_t addr[ETH_ALEN];
	u_int16_t aid ;
	u_int32_t flags;

	struct wapi_state_machine *wapi_sm;
};

typedef struct {
	u_int8_t gb15629dot11wapiAuthenticationSuiteSelected[4];
	u_int8_t gb15629dot11wapiUnicastCipherSelected[4];
	u_int8_t gb15629dot11wapiMulticastCipherSelected[4];
	u_int8_t gb15629dot11wapiBKIDUsed[WAPI_BKID_LEN];
	u_int8_t gb15629dot11wapiAuthenticationSuiteRequested[4];
	u_int8_t gb15629dot11wapiUnicastCipherRequested[4];
	u_int8_t gb15629dot11wapiMulticastCipherRequested[4];
}Gb15629dot11wapiConfigEntry_Security;

struct wapi_data {
	Gb15629dot11wapiConfigEntry_Security wapi_security;
		
	int num_sta; 
	struct sta_info *sta_list;
	struct sta_info *sta_hash[STA_HASH_SIZE];

	struct wapi_pmksa_cache pmksa;
	
	LVType wapiIE;
	LVType identityAE;
	LVType certificateLocal;
	LVType privKeyAE;
	LVType ecdhParam;
	LVType signAlgo;

	struct wapi_vap *vap;
};

#define WAPI_ASU_PORT	3810
struct wapi_asu{
	int	sock;
	
	char *certificateFileASU;
	struct in_addr ipASU;
	
	LVType identityASU;
	LVType publicKeyASU;	
};

#define WAPI_NMK_LEN	16
struct wapi_group{
#define WAPI_MSKID_MASK	0x01
	u_int8_t Mskid;
	u_int8_t NMK[WAPI_NMK_LEN];
	u_int8_t GTK[2][32];
	u_int8_t groupCounter[16];
	u_int8_t groupIdentifier[16];
	u_int8_t groupPN[2][16];
	u_int32_t groupNoStas;
	u_int32_t groupKeyDoneStas;
};

#define WAPI_VAPID_EQ(_a, _b)	(0 == os_memcmp(&(_a), &(_b), sizeof(AC_VAPID_T)))
#define WAPI_MAC_EQ(_a, _b)	(0 == os_memcmp((_a), (_b), ETH_ALEN))

#define VAP_CONFIG_WAPI(_cfg)	((_cfg)->ulAuth & BIT(5))

typedef enum {EncryptAP = 0, EncryptAC} EncryptUnion;

struct wapi_vap {
	unsigned char own_addr[ETH_ALEN];
	char ifname[IFNAMSIZ + 1];
	char ssid[32];
	Boolean opstate;
	
	EncryptUnion encrypt; 
	
	AC_VAPID_T vapid;
	
	TAILQ_ENTRY(wapi_vap) list;
	LIST_ENTRY(wapi_vap) hash_mac;
	LIST_ENTRY(wapi_vap) hash_id;
	
	struct wapi_data data;

	struct wapi_group group;
	struct wapi_config conf;
};

struct wapi_vaps {
	OSTOKEN mutex;

	TAILQ_HEAD(, wapi_vap) vaps_list;
	LIST_HEAD(, wapi_vap) vaps_hmac[AP_HASH_SIZE];
	LIST_HEAD(, wapi_vap) vaps_hid[AP_HASH_SIZE];	
};

struct wapi_grobal {
	struct wapi_vaps vaps;

	struct wapi_asu asu;

	int ioctl_ac_sock;	
	int max_sock;
	struct eloop_sock_table readers;

	struct eloop_timeout_table timeouts;
};
extern struct wapi_grobal acWapiapdGrobal;

extern u_int8_t PN_INIT[16];

#define CERTIFICATE_TYPE_X509V3	1
#define IDENTITY_TYPE_X509V3		1

#define 	WAPI_VAP_P	OsSemaphoreP(acWapiapdGrobal.vaps.mutex, WAIT_FOREVER, 1), \
						ModuleLogMsg(APP_MODULE_WAPIAPD, APP_MSG, "%s, vap P 1 mutex\n", __func__)

#define 	WAPI_VAP_V	OsSemaphoreV(acWapiapdGrobal.vaps.mutex, 1), \
						ModuleLogMsg(APP_MODULE_WAPIAPD, APP_MSG, "%s, vap V 1 mutex\n", __func__)

#define 	WAPI_TIMEOUT_P	OsSemaphoreP(acWapiapdGrobal.timeouts.mutex, WAIT_FOREVER, 1), \
							ModuleLogMsg(APP_MODULE_WAPIAPD, APP_MSG, "%s, timer P 1 mutex\n", __func__)
						
#define 	WAPI_TIMEOUT_V	OsSemaphoreV(acWapiapdGrobal.timeouts.mutex, 1), \
							ModuleLogMsg(APP_MODULE_WAPIAPD, APP_MSG, "%s, timer V 1 mutex\n", __func__)


void wapi_apd_deinit_config(struct wapi_config *conf);
void wapi_apd_free_data(struct wapi_data *data);

void wapiapd_ac_receive_asu(void);

void wapiapd_ac_proc_devm_addvap(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_devm_delvap(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_devm_updatevap(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_devm_updateasu(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_devm_bssidchg(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_devm_statechg(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_ioctl_rsp(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_newsta(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ac_proc_delsta(BYTE *pbyBody, WORD16 wLen);

struct wapi_vap *wapiapd_ac_findvap_byid(AC_VAPID_T vapid);
struct wapi_vap *wapiapd_ac_findvap_byaddr(u_int8_t *addr);
void wapiapd_ac_send_msg_tovap(struct wapi_vap *vap, u_int32_t type, u_int8_t *msg, u_int32_t len);
struct wapi_vap *wapiapd_ac_vap_create(AC_DEVM_VAP_CONFIG_T *vapCfg);
int wpai_apd_remove_iface(struct wapi_vap *vap);
int wapi_apd_init_iface(struct wapi_vap *vap);
void wpai_apd_deinit_iface(struct wapi_vap *vap);

void  wapiapd_ac_config_agent_vap(struct wapi_vap *vap, ConfigTag tag);
BOOL wapiapd_ac_get_vap_config(AC_DEVM_VAP_CONFIG_T *vapCfg);
BOOL wapiapd_ac_update_wapiconfig(struct wapi_vap *vap, AC_DEVM_VAP_CONFIG_T *vapCfg);
void wapi_apd_free_lvtype(LVType *lv);

void wapi_sm_step(struct wapi_state_machine *sm);
void wapi_apd_free_sta(struct wapi_data *data, struct sta_info *sta);
struct sta_info *wapi_apd_get_sta(struct wapi_vap *vap, const u_int8_t *addr);
void wapi_cancel_sm_timers(struct wapi_state_machine *sm);

int wapi_verify_signature(u_int8_t *content, u_int32_t len, u_int8_t *key, u_int32_t keylen, LVType *sign);
u_int8_t *wapi_compute_checkout_code(u_int8_t *mak, u_int8_t *content, u_int32_t len);

void wapi_group_update(struct wapi_vap *vap);

void wapi_apd_set_key(struct wapi_vap *vap, const u_int8_t *addr, int key_idx, const u_int8_t *key, size_t key_len);
void wapiapd_ac_ioctl_authorized(struct wapi_vap *vap, const u_int8_t *addr, int authorized);
int wapi_apd_sta_disconnect(struct wapi_state_machine *sm, const u_int8_t *addr, int reason_code);
void wapiapd_ac_ioctl_setkey(struct wapi_vap *vap, const u_int8_t *addr, int key_idx,
		const u_int8_t *key, size_t key_len);
int wapiapd_ac_ioctl_txseqnum(struct wapi_vap *vap, const u_int8_t *addr, int idx, u_int8_t *seq);
u_int8_t *wapiapd_ac_ioctl_head(u_int8_t *pos, u_int32_t len, struct wapi_vap *vap, Boolean rsp);
u_int8_t *wapiapd_ac_ioctl_madwifi_mks(u_int8_t *pos, u_int32_t len, int v);
u_int8_t *wapiapd_ac_ioctl_madwifi_uks(u_int8_t *pos, u_int32_t len, int v);
u_int8_t *wapiapd_ac_ioctl_madwifi_akms(u_int8_t *pos, u_int32_t len, int v);
u_int8_t *wapiapd_ac_ioctl_madwifi_caps(u_int8_t *pos, u_int32_t len, int v);
u_int8_t *wapiapd_ac_ioctl_madwifi_privacy(u_int8_t *pos, u_int32_t len, u_int8_t v);
void wapiapd_ac_send_ioctl_msg(struct wapi_vap *vap, u_int8_t *msg, u_int32_t len);
void wapiapd_ac_ioctl_delkey(struct wapi_vap *vap, const u_int8_t *addr, int key_idx);
void wapi_sm_trigger_event(struct wapi_state_machine *sm, u_int32_t event);
void wapiapd_ac_ioctl_deauth(struct wapi_vap *vap, const u_int8_t *addr, int reason_code);
void wapiapd_ac_ioctl_setiflags(struct wapi_vap *vap, int dev_up);
void wapiapd_ac_ioctl_getwapistats_2ac(struct wapi_vap *vap, u_int8_t *addr, L2W_GET_WAPI_STATS *stat);

#endif

