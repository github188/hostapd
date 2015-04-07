#ifndef IEEE80211_CONFIG_COMMON_H
#define IEEE80211_CONFIG_COMMON_H

typedef struct apBasicSetup_s_i
{
/* AP_MODE_MIXED��AP_MODE_GONLY��Ҫ��ieee80211_ioctl_setparam����
   IEEE80211_PARAM_PUREG��ʵ��, BONLY��Ҫ��ieee80211_ioctl_setmode
   ����ģʽΪ11Bģʽ, AP_MODE_DISABLE��ϵͳ����ģ��ر�ath0�豸��ʵ�� */
 long apMode;  
#define AP_MODE_DISABLE_I 1
#define AP_MODE_MIXED_I 2
#define AP_MODE_GONLY_I 3
#define AP_MODE_BONLY_I 4

/* ��ʱ��ʵ�� */
 long apStartupMode;
#define AP_STARTUP_MODE_MASTER_I 1
#define AP_STARTUP_MODE_STANDBY_I 2 

/*ieee80211_ioctl_siwessid��ieee80211_ioctl_giwessid�������úͻ�ȡESSID*/
 unsigned char apSsid[32];

/* ieee80211_ioctl_siwfreq��ieee80211_ioctl_giwfreq�������úͻ�ȡChannel, Ŀǰ
   ����������Autoģʽ */ 
 long apChannel;
#define AP_CHANNEL_CH1_I 1
#define AP_CHANNEL_CH2_I 2
#define AP_CHANNEL_CH3_I 3
#define AP_CHANNEL_CH4_I 4
#define AP_CHANNEL_CH5_I 5
#define AP_CHANNEL_CH6_I 6
#define AP_CHANNEL_CH7_I 7 
#define AP_CHANNEL_CH8_I 8
#define AP_CHANNEL_CH9_I 9
#define AP_CHANNEL_CH10_I 10
#define AP_CHANNEL_CH11_I 11
#define AP_CHANNEL_CH12_I 12
#define AP_CHANNEL_CH13_I 13
#define AP_CHANNEL_AUTO_I 14

/* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�ʹ��
  IEEE80211_F_HIDESSID���� */ 
 long apBroadcastSsid; 
#define AP_BROADCAST_SSID_DISABLE_I 1
#define AP_BROADCAST_SSID_ENABLE_I 2

 long apLogOption;
#define LOG_OPTION_OFF_I 1
#define LOG_OPTION_ON_I 2
} T_apBasicSetup_i;
 

typedef struct apAdvancedSetup_s_i
{
/* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�ʹ��
  IEEE80211_PARAM_BEACON_INTERVAL����
  ��Ч��Χ25-500(TU) ???? */
 unsigned long apBeaconInterval;

/* ͨ��ieee80211_ioctl_siwrts��ieee80211_ioctl_giwrts���úͻ�ȡRTS���� */
 unsigned long apRtsThreshold;

/* ͨ��ieee80211_ioctl_siwfrag��ieee80211_ioctl_giwfrag����Fragment���� */
 unsigned long apFragmentationThreshold;

/* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�ʹ��
   IEEE80211_PARAM_DTIM_PERIOD����
   ��Ч��Χ1-15(Beacon Period) */
 unsigned long apDtimInterval;

/* ͨ��ieee80211_ioctl_siwrate��ieee80211_ioctl_giwrate���úͻ�ȡ��ʵ�֣��������
  ʹ��Auto��������ù̶����ʣ���Ҫ��רҵ��ʿָ��
  ϵͳ����ģ�鴫���apTxRate�����ĵ�λ��bps(��������Ϊ1Mbps�������1000000)
  ���0xFFFF == apTxRate����Ϊ������Autoģʽ  */
 unsigned long apTxRate;
 #define TXRATE_AUTO_SELECTION_I  0xFFFF

/* ��֧�����úͻ�ȡ */
 long apPreambleType; 
#define AP_PREAMBLE_AUTO_I 1
#define AP_PREAMBLE_SHORT_I 2
#define AP_PREAMBLE_LONG_I 3

/* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�
   ʹ��IEEE80211_PARAM_AUTHMODE������AUTO == BOTH ???? */
 long apAuthenticationType;
#define AP_AUTHENTICATION_BOTH_I 1
#define AP_AUTHENTICATION_OPENSYSTEM_I 2
#define AP_AUTHENTICATION_SHAREDKEY_I 3
#define AP_AUTHENTICATION_WPAPRESHAREDKEY_I 4


/* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�
   ʹ��IEEE80211_PARAM_PROTMODE���� */
 long apCtsProtectionMode;
#define AP_CTSPROTECTION_MODE_DISABLE_I 1
#define AP_CTSPROTECTION_MODE_ENABLE_I 2

} T_apAdvancedSetup_i; 
 

typedef struct apSecuritySetup_s_i
{
 long apSecurity;
 /* ͨ��ieee80211_ioctl_setparam��ieee80211_ioctl_getparam���úͻ�ȡ��ʵ�֣�
   ʹ��IEEE80211_PARAM_PRIVACY������
 ˽���Ժͼ�Ȩ���ڹ�����ϵ����˽���Թر�ʱ������OPEN������ģʽ�ļ�Ȩ������Ч */
#define AP_SECURITY_DISABLE_I 1 
#define AP_SECURITY_ENABLE_I 2


 long apWpaAlgorithms;
#define AP_ALGORITHMS_WEP_I     0 /* ???? */
#define AP_WPA_ALGORITHMS_TKIP_I 1
#define AP_WPA_ALGORITHMS_AES_I  2
/* ˽�����㷨�ͼ�Ȩģʽ���ڹ�����OPEN��SHAREKEY��Ȩ��ֻ��ʹ��WEP˽���㷨��
AES�㷨ʹ��AES_CCM */
 long  keylen;
 unsigned char apWepKey[32];
/* ���ϲ���ͨ��ieee80211_ioctl_siwencodeext��ieee80211_ioctl_giwencodeext���úͻ�ȡ��ʵ�� */ 
 
 unsigned long apKeyRenewal;
 /* �ò��������ã�Key�����£�ֻ��WPA��Ȩģʽ�¸ò����Ż���Ч */
} T_apSecuritySetup_i; 

 

typedef struct endUserEntry_s_i
{
 unsigned long endUserIndex;
#define INVALID_INDEX_I 0
 unsigned char endUserMac[6];
 unsigned long endUserLiveTime;

 /* ����Ŀ */
 unsigned long pktSendToUser;

 /* ����Ŀ */
 unsigned long pktRecvFromUser;
} T_endUserEntry_i;

typedef struct accessDenyEntry_s_i
{
 unsigned long accessDenyIndex;
 unsigned char accessDenyMac[6];
 unsigned char accessDenyReason[32];

 /* ʹ��jiffies��Ϊ��λ */
 unsigned long accessDenyTime;
} T_accessDenyEntry_i; 


typedef struct adhocBasicSetup_s_i
{
 long adhocMode;
#define ADHOC_MODE_DISABLE_I 5
#define ADHOC_MODE_AONLY_I 6
 unsigned char adhocMac[6];
 unsigned char adhocSsid[32];
 
 /* ȱ��Auth���ã�Ĭ��ʹ��OPENSYSTEM  */
 
 long adhocSecurity;
#define ADHOC_SECURITY_DISABLE_I 1 
#define ADHOC_SECURITY_ENABLE_I 2

	/* ȱ��˽�����㷨���ã��̶�����ΪWEP ????wep keyΪʲô��*/
 long keylen;
 unsigned char adhocWepKey[64];
 long adhocLogOptionAth;
 long adhocLogOptionWlan;
 long adhocLogOptionSecurity;
 long adhocLogOptionScan;
} T_adhocBasicSetup_i; 

typedef struct adhocAdvancedSetup_s_i
{
 long adhocChannel;
#define ADHOC_CHANNEL_CH149_I 149 
#define ADHOC_CHANNEL_CH153_I 153
#define ADHOC_CHANNEL_CH157_I 157
#define ADHOC_CHANNEL_CH161_I 161

 unsigned long adhocMaxTxPower;
 /*
    ʹ��ieee80211_ioctl_siwtxpow���÷��͹��ʣ�ֻ���ڹ̶����ʷ�������£��Ż���������͹��ʣ�
    ��ò�Ҫ����  ???? ��Ҫ������ôʵ��
    ���ʵ�λ��dbm    
    */
  
 unsigned long adhocMinTxPower;
 /* Ŀǰ������ */ 
 
 /* ȱ��RTS/CTS��־���ã�Ĭ������Ϊ�� */
 unsigned long adhocRtsThreshold;
 
 unsigned long adhocFragmentationThreshold;
 
 unsigned long adhocMaxRetransmitCount;
} T_adhocAdvancedSetup_i;

/* ����s/n�б� */
/* ��ϵͳ����ģ�鴥�������������������ӳ�1s���ң�ֻ��adhocʹ�� */
typedef struct snrEntry_s_i
{
 long snrChannel;
 /* ʹ��1..11 149..153��ʶ,0������Ч���ŵ� */
 long snrValue;
 /* ɨ��õ�������� */
} T_snrEntry_i; 

/* adhoc�����б� */
typedef struct adhocNeighborEntry_s_i
{
 long adhocNeighborIndex;
 unsigned char adhocNeighborMac[6];
 /* ���µĽ������� */
 unsigned long recvDataRate;
 /* ���µķ������� */
 unsigned long sendDataRate;
 /* ���µķ��͹��� */
 unsigned long txPower;
 /* ���µĽ�������� */
 unsigned long rssi;
 /* ƽ�����������*/
 unsigned long avgrssi;
} T_adhocNeighborEntry_i;

typedef struct adhocPm_s_i
{
 unsigned long totalRecvDataRate;
 /* �����Ȩƽ���Ľ������ʣ�ѡ����ӽ��Ľ������ʣ��ϱ���ϵͳ����ģ�飬�ϱ���ˢ�½�������ͳ�� */
 unsigned long totalSendDataRate;
 /* �����Ȩƽ���ķ������ʣ�ѡ����ӽ��ķ������ʣ��ϱ���ϵͳ����ģ�飬�ϱ���ˢ�·�������ͳ�� */
 unsigned long totalTxPower;
 /* ���书�ʵ�����ƽ�����������ҿ����ǹ̶��� */
 unsigned long totalSnr;
 /* Snr������ƽ�� */
 unsigned long neighborNumber;
 /* ������Ŀ */
} T_adhocPm_i; 

/* ????������power level��Ҫͨ��ap��ѯ */
/*
typedef struct meshTopology_s_r
{
	long seedNode;
#define SEED_NODE_NO_R 1
#define SEED_NODE_YES_R 2
	long powerLevel;
#define POWER_LEVEL_WEAK_R 1
#define POWER_LEVEL_MIDDLE_R 2
#define POWER_LEVEL_STRONG_R 3
	T_connEntry connEntry[MAX_CONN_ENTRY];
} T_meshTopology_r;
*/
 
typedef struct tagsysConfig
{
	enum {
		N_apBasicSetup_I = 0,
		N_apAdvancedSetup_I,
		N_apSecuritySetup_I,
		N_adhocBasicSetup_I,
		N_adhocAdvancedSetup_I
	} m;
	union {
		T_apBasicSetup_i     tapBscSetup;
		T_apAdvancedSetup_i  tapAdvSetup;
		T_apSecuritySetup_i  tapScuSetup;
		T_adhocBasicSetup_i  tadhBscSetup;
		T_adhocAdvancedSetup_i  tadhAdvSetup;
	} u;
} T_wifiConfig_i;


typedef struct wifiState_s_i
{
	enum {
		N_endUserTable_I = 0,
		N_accessDenyTable_I,
		N_snrTable_I,
		N_adhocNeighborTable_I,
		N_adhocPm_I 
	} m;
#define MAX_ENDUSER_ENTRY_I 128
#define MAX_ACCESSDENY_ENTRY_I 10
#define MAX_SNR_ENTRY_I 8
#define MAX_ADHOCNEIGHBOR_ENTRY_I 10
	union {
		T_endUserEntry_i endUserEntry[MAX_ENDUSER_ENTRY_I];
		T_accessDenyEntry_i accessDenyEntry[MAX_ACCESSDENY_ENTRY_I]; 
		T_snrEntry_i snrEntry[MAX_SNR_ENTRY_I]; 
		T_adhocNeighborEntry_i adhocNeighborEntry[MAX_ADHOCNEIGHBOR_ENTRY_I]; 
		T_adhocPm_i adhocPm; 
	} u;
} T_wifiState_i;

typedef struct{
	u_int32_t ulNum;
#define IOCTL_MAX_DENYNUM 10	
	u_int8_t   maclist[IOCTL_MAX_DENYNUM][6];
} TmacDenyList;


/* �ӿں��� */

/* ������ģ����سɹ���ϵͳ����ģ����ô˳�ʼ��������
    �����ڲ������úͲ�ѯ֮ǰ��ɸõ��� */
int ieee80211_paratbl_init(void);

/* ϵͳ�������ú���
  dev: �ַ������豸��
  ptsysConfig: ϵͳ���ò���
 */
int ieee80211_setcfg(char *dev, T_wifiConfig_i *ptConfig);

/* ϵͳ������ѯ����
  dev: �ַ������豸��
  ptsysConfig: ϵͳ��ѯ����
 */
int ieee80211_getcfg(char *dev, T_wifiConfig_i *ptConfig);

int denyListClr(char *dev);
int denyListAdd(char *dev, TmacDenyList *ptList);

/* ���ͳ����Ϣ��״̬��Ϣ */
int ieee80211_state_get(char *dev, T_wifiState_i *ptState);


#endif
