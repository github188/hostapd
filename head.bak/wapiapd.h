#ifndef __WAPIAPD_H__
#define __WAPIAPD_H__

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

struct wapi_vap {
	char	iface[IFNAMSIZ + 1];
	u_int8_t ifaddr[ETH_ALEN];
	int     ifindex;
	int	l2_sock;
	int	ioctl_sock;
	int	wext_sock;
#define WAPI_VAP_RUN	0	
#define WAPI_VAP_NEW	1
#define WAPI_VAP_DEL	2
	int	state;
	struct wapi_vap *next;
};

struct wapi_vaps {
	OSTOKEN mutex;
	struct wapi_vap *firstvap;
};

struct wapi_driver {
	struct wapi_vaps vaps;
	int changed;	
	
	int max_sock;
	struct eloop_sock_table readers;
};
extern struct wapi_driver apWapiapdGrobal;

#define	IEEE80211_CIPHER_SMS4		7

#define	IEEE80211_PARAM_WAPI_MCASTCIPHER 63
#define	IEEE80211_PARAM_WAPI_UCASTCIPHERS 64
#define	IEEE80211_PARAM_WAPICAPS 65
#define	IEEE80211_PARAM_WAPI_KEYMGTALGS 66

typedef BOOL Boolean;

int wapiapd_ap_update_sock_tables(void);
struct wapi_vap * wapiapd_ap_find_vap(BYTE *name, BYTE len);
int wapiapd_get_groupkey_seqnum(struct wapi_vap *vap, u_int8_t mskid, u_int8_t *seq);
int wapiapd_get_sta_wapi_ie(struct wapi_vap *vap, u_int8_t *addr, u_int8_t *ie, u_int32_t *len);
int wapiapd_get_associd(struct wapi_vap *vap, const u_int8_t *addr, u_int8_t *seq) ;
void wapiapd_ap_proc_ioctl_req(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ap_proc_agent_config(BYTE *pbyBody, WORD16 wLen);
void wapiapd_ap_proc_encaped_wai(BYTE *pbyBody, WORD16 wLen);

#endif
