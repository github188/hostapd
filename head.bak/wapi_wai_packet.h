#ifndef __WAPI_WAI_PACKET_H__
#define __WAPI_WAI_PACKET_H__

#define WAI_FLAG_BK_UPDATE		BIT(0)
#define WAI_FLAG_PRE_AUTH			BIT(1)
#define WAI_FLAG_CERT_AUTH		BIT(2)
#define WAI_FLAG_OPTION_FIELD		BIT(3)
#define WAI_FLAG_USK_UPDATE		BIT(4)
#define WAI_FLAG_STAKEY_NEG		BIT(5)
#define WAI_FLAG_STAKEY_DEL		BIT(6)

typedef struct {
	u_int16_t identityType;
	u_int16_t len;
	u_int8_t *identity;
}Identity;

typedef struct {
	u_int16_t identityNum;
	Identity *identityList;
}IdentityList;

#define ECC_PARAM_1_2_156_11235_1_1_2_1	0
typedef struct {
	u_int8_t hashAlgo;
	u_int8_t signAlgo;
	u_int8_t eccParam;
}SignatureAlgo;

typedef struct {
	u_int8_t tag;
	u_int16_t len;
	u_int8_t *param;
}EcdhParam;

typedef struct {
	u_int16_t len;
	u_int8_t *signContent;
}SignatureContent;


typedef struct {
	u_int16_t certType;
	u_int16_t len;
	u_int8_t *data;
}Certificate;

typedef enum {
	CERTIFICATE_VALID	= 0,
	CERTIFICATE_UNSPEC_ISSUER,
	CERTIFICATE_UNTRUST_ROOT,
	CERTIFICATE_EXPIRT,
	CERTIFICATE_SIGN_ERROR,
	CERTIFICATE_IN_CRL,
	CERTIFICATE_OUT_SCOPE,
	CERTIFICATE_IN_CRL_UNKNOW,
	CERTIFICATE_ERROR_UNKNOW
}CertResult;

typedef struct {
	u_int8_t tag;
	u_int16_t len;
	
	u_int8_t *challengeAE;
	u_int8_t *challengeASUE;
	
	u_int8_t *resultAE;
	TLVType certAE;
	
	u_int8_t *resultASUE;
	TLVType certASUE;
}CertAuthResult;

typedef enum {
	ACCESS_SUCCESS	= 0,
	ACCESS_FAIL_UNSPEC_CERT,
	ACCESS_FAIL_ERROR_CERT,
	ACCESS_FAIL_LOCAL_FORBID
}AccessResult;


typedef struct {
	TLVType identity;
	SignatureAlgo signatureAlgo;
	SignatureContent signatureContent;
}Signature;

typedef struct {
	u_int8_t len;
	u_int8_t *key;
}KeyData;

typedef struct {
	u_int8_t *flag;
	u_int8_t *identifier;
	u_int8_t *challengeASUE;
	LVType keyASUE;
	LVType identityAE;
	LVType certificateASUE;	
	LVType eccParam;
	LVType trustASUs;
	LVType signASUE;
}__packed AccessAuthReq;

typedef struct {
	u_int8_t *addid;
	LVType certAuthResult;
	LVType signForASUE;
	LVType signForAE;
}__packed CertAuthResp;

typedef struct {
	u_int8_t *flag;
	u_int8_t *bkid;
	u_int8_t *uskid;
	u_int8_t *addid;
	u_int8_t *challengeASUE;
	u_int8_t *challengeAE;
	LVType wapiIE_ASUE;
	u_int8_t *distinguishCode;
}__packed UKNegoResp;

typedef struct {
	u_int8_t *flag;
	u_int8_t *mskid;
	u_int8_t *uskid;
	u_int8_t *addid;
	u_int8_t *notifyId;
	u_int8_t *distinguishCode;
}__packed MKNotifyResp;

#define PACKET_MORE_FRAG	BIT(0)

#define PACKET_TYPE_WAI	0x01

#define PACKET_SUBTYPE_PRE_AUTH			((u_int8_t)(1))
#define PACKET_SUBTYPE_STAKEY_REQ		((u_int8_t)(2))
#define PACKET_SUBTYPE_AUTH_ACTIVE		((u_int8_t)(3))
#define PACKET_SUBTYPE_ACCESS_AUTH_REQ	((u_int8_t)(4))
#define PACKET_SUBTYPE_ACCESS_AUTH_RESP	((u_int8_t)(5))
#define PACKET_SUBTYPE_CERT_AUTH_REQ		((u_int8_t)(6))
#define PACKET_SUBTYPE_CERT_AUTH_RESP	((u_int8_t)(7))
#define PACKET_SUBTYPE_UK_NEGO_REQ		((u_int8_t)(8))
#define PACKET_SUBTYPE_UK_NEGO_RESP		((u_int8_t)(9))
#define PACKET_SUBTYPE_UK_NEGO_CONFIRM	((u_int8_t)(10))
#define PACKET_SUBTYPE_MK_NOTIFY			((u_int8_t)(11))
#define PACKET_SUBTYPE_MK_NOTIFY_RESP	((u_int8_t)(12))

typedef struct {
	u_int16_t version;
	u_int8_t type;
	u_int8_t subtype;
	u_int8_t resv[2];
 	u_int16_t len;
	u_int16_t seqno;
	u_int8_t fragno;
	u_int8_t flag;	
}__packed WaiPacketHead;

typedef struct {
	WaiPacketHead head;
	u_int8_t macAE[ETH_ALEN];
	u_int8_t macASUE[ETH_ALEN];	
}__packed WaiPacketASUHead;


typedef enum {
	ATTRIBUTE_SIGNATURE = 1,
	ATTRIBUTE_CERTRESULT = 2,
	ATTRIBUTE_IDENITYLIST = 3,
}WaiAttributeTag;

typedef struct waiPacket{
	WaiPacketHead head;

	union {
//		AuthActive authActive;
		AccessAuthReq accessAuthReq;
//		CertAuthReq certAuthReq;
		CertAuthResp certAuthResp;
//		AccessAuthResp accessAuthResp;
//		UKNegoReq ukNegoReq;
		UKNegoResp ukNegoResp;
//		UKNegoConfirm ukNegoConfirm;
//		MKNotify mkNotify;
		MKNotifyResp mkNotifyResp;
	}__packed data;
}__packed WaiPacket;

#define L2_HEAD_LEN		(sizeof(struct l2_ethhdr))
#define ASUE_WAI_PACKET_HEADLEN	(sizeof(struct l2_ethhdr) + sizeof(WaiPacketHead))
#define ASU_WAI_PACKET_HEADLEN	(sizeof(WaiPacketHead))

struct wapi_state_machine;
struct waiFragments;


void wapi_construct_wai_packet(struct wapi_state_machine *sm, u_int8_t subtype);
void wapi_send_wai_packet(struct wapi_state_machine *sm, u_int8_t subtype);
int wapi_get_asue_certificate(struct wapi_state_machine *sm, LVType *asueCertificate);
void wapiapd_ac_proc_encaped_wai(BYTE *pbyBody, WORD16 wLen);
void wapi_receive_asu_wai_packet(int sock, void *eloop_ctx, void *sock_ctx);
void wapi_free_fragments(struct waiFragments *frags);
u_int8_t *wapi_get_asue_challenge(struct wapi_state_machine *sm);

#endif
