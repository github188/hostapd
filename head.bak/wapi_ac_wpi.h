#ifndef __WAPI_AC_WPI__
#define __WAPI_AC_WPI__

#include <linux/if_ether.h>

#define WAPI_AC_WPI_KEYBUF_SIZE	16  /*wapi ������Կ����*/
#define WAPI_AC_WPI_MICBUF_SIZE	16  /*wapi ��������Կ����*/
#define WAPI_AC_WPI_PN_LEN             16  /*wapi Э��PN����*/
#define WAPI_AC_WPI_MIC_LEN           16  /*wapi Э��MIC����*/
#define WAPI_AC_WPI_KIDLEN             1    /*wapi Э����ԿID ����*/
#define WAPI_AC_WPI_RESV                 1   /*wapi Э�鱣���ֶγ���*/

#define WAPI_AC_WPI_VALID              0x01  /*����wapi ���ܱ�־*/
#define WAPI_AC_WPI_KEY_MCAST     0x02  /*�㲥��Կ��־*/
#define WAPI_AC_WPI_KEY_UCAST      0x04   /*������Կ��־*/


#define	ETHERTYPE_WAPI	0x8F01  /*WAPI�������̫������*/

#define ETHERNET_TYPE_WAI  0x88B4
#define WAPI_NO_FREE_SKB    0xFF

#define   WAPI_AC_WPI_HEADER_LEN (WAPI_AC_WPI_PN_LEN + WAPI_AC_WPI_KIDLEN + WAPI_AC_WPI_RESV)
#define	WAPI_AC_WPI_IS_MULTICAST(_a)   (*(_a) & 0x01)

#define 	WAPI_IEEE80211_SEQ_SEQ_SHIFT	4
#define	WAPI_IEEE80211_FC0_VERSION_0	0x00
#define	WAPI_IEEE80211_FC0_TYPE_DATA	0x08
#define	WAPI_IEEE80211_FC1_DIR_TODS		0x01	/* STA->AP  */
#define	WAPI_IEEE80211_FC1_DIR_FROMDS	0x02	/* AP ->STA */
#define	WAPI_IEEE80211_FC1_PROT			0x40
#define	WAPI_IEEE80211_FC0_SUBTYPE_QOS	0x80
#define	WAPI_IEEE80211_FC1_DIR_MASK		0x03
#define	WAPI_IEEE80211_FC0_TYPE_MASK	0x0c


#define WAPI_FC0_MASK_10001111  0x8F
#define WAPI_FC1_MASK_11000111  0xC7
#define WAPI_FC1_MASK_01000000  0x40
#define WAPI_SEQ_MASK_00001111  0x0F

#define IEEE80211_ADDR_LEN  6
#define	IEEE80211_ADDR_COPY(dst,src)	memcpy(dst,src,IEEE80211_ADDR_LEN)

//#define	roundup(x, y)	((((x)+((y)-1))/(y))*(y))  /* to any y */ 


#ifndef __packed
#define	__packed	__attribute__((__packed__))
#endif

struct ieee80211_frame {
	u8 i_fc[2];
	u8 i_dur[2];
	u8 i_addr1[IEEE80211_ADDR_LEN];
	u8 i_addr2[IEEE80211_ADDR_LEN];
	u8 i_addr3[IEEE80211_ADDR_LEN];
	u8 i_seq[2];
} __packed;

struct ieee80211_qosframe {
	u8 i_fc[2];
	u8 i_dur[2];
	u8 i_addr1[IEEE80211_ADDR_LEN];
	u8 i_addr2[IEEE80211_ADDR_LEN];
	u8 i_addr3[IEEE80211_ADDR_LEN];
	u8 i_seq[2];
	u8 i_qos[2];
} __packed;

#define WAPI_LLC_SNAPFRAMELEN 8
#define WAPI_LLC_SNAP_LSAP	0xaa
#define WAPI_LLC_UI		0x3
struct wapi_llc {
	u8 llc_dsap;
	u8 llc_ssap;
	union {
	    struct {
		u8 control;
		u8 format_id;
		u8 class;
		u8 window_x2;
	    } __packed type_u;
	    struct {
		u8 num_snd_x2;
		u8 num_rcv_x2;
	    } __packed type_i;
	    struct {
		u8 control;
		u8 num_rcv_x2;
	    } __packed type_s;
	    struct {
	        u8 control;
		u8 frmr_rej_pdu0;
		u8 frmr_rej_pdu1;
		u8 frmr_control;
		u8 frmr_control_ext;
		u8 frmr_cause;
	    } __packed type_frmr;
	    struct {
		u8 control;
		u8 org_code[3];
		u16 ether_type;
	    } __packed type_snap;
	    struct {
		u8 control;
		u8 control_ext;
	    } __packed type_raw;
	} llc_un;
} __packed;

#define	llc_control		llc_un.type_u.control
#define	llc_snap		llc_un.type_snap


struct wapi_ac_key_stats /*�˿���ص�ͳ��*/
{
	u32 wapi_skb_adjuest_by_head;
	u32 wapi_skb_adjuest_by_tail;
	u32 wapi_skb_adjuest_fail;
	u32 wapi_skb_enmic_error;
	u32 wapi_skb_encap_error;
	u32 wapi_skb_recv_unenc_data;
	u32 wapi_skb_recv_wapiethtype;
	u32 wapi_skb_recv_not_wapiethtype; /*��wapi ��̫�����ͽ���*/
	u32 wapi_skb_recv_not_to_ds;

	u32 wapi_skb_decap_error;
	u32 wapi_skb_demic_error;

	u32 wapi_skb_not_wapi_user;
	u32 wapi_skb_not_wapi_port;
	u32 wapi_skb_recv_pn_error;
	u32 wapi_skb_decrypt_error;
	u32 wapi_skb_cmp_mic_error;
};

struct wapi_ac_wpi_key /*WAPI ��Կ�ṹ*/
{
	
	u16 wk_keyix; /*��ԿID*/
	u8  wk_flags;
	u8 ucKid_temp;
	
	u8  wk_key[WAPI_AC_WPI_KEYBUF_SIZE+WAPI_AC_WPI_MICBUF_SIZE];
	#define	wk_txmic	wk_key+WAPI_AC_WPI_KEYBUF_SIZE
	
	u8 wk_keyrsc[WAPI_AC_WPI_PN_LEN];  /*����PN*/
	u8 wk_keytsc[WAPI_AC_WPI_PN_LEN];  /*����PN*/
	u8 wk_keyrsc_temp[WAPI_AC_WPI_PN_LEN];
	
	u8 aucBssid[6];
	u16 usTxSeq;
	struct wapi_ac_key_stats stats;
};
typedef struct wapi_ac_wpi_key WAPI_AC_WPI_KEY; /*WAPI ��Կ�ṹ*/

void wapi_ac_set_print();

/*�жϵ�ǰ�˿��Ƿ���ҪWAPI����*/
#define PORT_IS_WAPI_WPI(_port)  ((_port)->stKey.wk_flags & WAPI_AC_WPI_VALID) /*_portΪL2W_PORT_T * ���� */

/*�жϵ�ǰ�û��Ƿ���ҪWAPI ����*/
#define USER_IS_WAPI_WPI(_user)  ((_user)->stKey.wk_flags & WAPI_AC_WPI_VALID)/*_userΪL2W_USER_T * ���� */

/*�жϵ�ǰethernet���Ƿ���Ҫwapi���⴦��*/
#define ETH_PACHET_IS_WAPI(_eth)  (((struct ethhdr*)(_eth))->h_proto == __constant_htons(ETHERTYPE_WAPI)) /*_eth Ϊif_ether.h����struct ethhdr�ṹָ�� */


#define WAPI_NEED_HEAD_ROOM    (WAPI_LLC_SNAPFRAMELEN+ 32+ 18 + 8)
#define WAPI_NEED_HEAD_TAIL  (WAPI_AC_WPI_MIC_LEN +4)

#endif /*__WAPI_AC_WPI__*/
