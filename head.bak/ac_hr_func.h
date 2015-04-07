#ifndef AC_HR_FUNC_H
#define AC_HR_FUNC_H

#define LISTENNQ			128
#define HR_MAX_SSID_LEN		32
#define HR_MAX_URL_LEN		64

#ifdef WIN32
#define LOG_EMERG       0   /* �����¼���Ϣ */
#define LOG_ALERT       1   /* ������Ϣ */
#define LOG_CRIT        2   /* �ٽ����� */
#define LOG_ERROR       3   /* ������Ϣ */
#define LOG_WARN        4   /* ������Ϣ */
#define LOG_NOTICE      5   /* ������Ϣ */
#define LOG_INFO        6   /* ��ʾ��Ϣ */
#define LOG_DEBUG       7   /* ������Ϣ */
#endif


#define  HTTPGETURLMAXLEN   255
#define  HTTPHOSTURLMAXLEN  255
#define  HTTPURLMAXLEN      512
#define  HTTPZEROLEN        0

#define HRD_MAC_DEF_FMT "%02X-%02X-%02X-%02X-%02X-%02X"
#define HRD_MAC_OTHER_FMT  "%02X:%02X:%02X:%02X:%02X:%02X"
#define HRD_MAC_EASY_FMT "%02x%02x%02x%02x%02x%02x"

/************************************************/
typedef struct
{
    UINT32      ulHTTPMsgListenPort;    //  PortalConst.HTTP_MSG_LISTEN_PORT;
    BOOL        bCheckHttpHead;
	BOOL		bCheckLoopMsg;
	UINT32      ulPAPort;               /* pa�����˿ڣ�ȱʡ2000 */

	UINT32      ulBufferedSocketNum;

    CHAR        acOmcCfgFilePath[256+1];
    BOOL        bRunAsDaemon;
    BOOL        bWISPPara;
    BOOL        bHiddenPara;            /* ��e�Բ��� */

    CHAR        acAttrUserIP[64];
    CHAR        acAttrACName[64];
    CHAR        acAttrACIP[64];
    CHAR        acAttrSSID[64];
    CHAR        acAttrPortalURL[64];
    CHAR        acAttrMAC[64];
    CHAR        acAttrNasId[64];
	CHAR		acAttrApMac[64];   /*add for AP MAC*/

    UINT8       aucValidSSIDChar[256];

    BOOL        bUrlWithACIP;
    BOOL        bNotifySSID;
    BOOL        bNotifyUserMac;
	BOOL		bNotifyApMac;      /*add for AP MAC*/
    BOOL        bNotifyHostUrlMsg;    /*�Ƿ�Я��User��֤ǰ���ʵ�URL��ַ*/
    BOOL        bNofityGetUrlMsg;    /*�����Ƿ�Я��HTTP URL�е�GET�ֶ�*/
    UINT32        ulUserMacFormat;     /*�û�MAC��ַ��ʽ,Ĭ��XX-XX-XX-XX-XX-XX*/
    BOOL        bSequenceMode;
    BOOL        bUserSetNasId;  
}HR_LOCAL_CFG_T;

#define DEVM_CONTROL_NAME           "powerac"

typedef struct
{
    INT32   iCfgVersion;        /* �������ݰ汾�� */

    UINT32  ulPortalEnable;

    CHAR    acPortalUrl[HR_MAX_URL_LEN+4];    /* Portal��֤��URL */
    CHAR    acACName[64+4];  		/* ac������ */
    UINT8   aucACIP[4];
}HR_OMC_CFG_T;

VOID    hr_log(INT32 iLogLevel, CHAR* szFormat, ...);
BOOL    hr_init_socket(VOID);
CHAR*   hr_get_socket_err(VOID);
CHAR*   hr_get_rootpath(VOID);
BOOL    hr_is_proc_running(VOID);
BOOL    hr_run_as_daemon(VOID);
BOOL    hr_get_omc_cfg(HR_OMC_CFG_T *pstCfg);
VOID    hr_ipcmsg_handle(UINT16 wEvent,
	                     UINT8  *pbyBody,
	                     UINT16 wLen,
	                     UINT8  *pbyOutBody,
	                     UINT16  *pwOutLen);
BOOL    hr_get_portal_url(UINT8 *pucUserIP, CHAR *szPortalUrl, CHAR *szSSID);
BOOL hr_set_UA(UINT8 *pucUserIP, CHAR *pszUA, UINT32 ulUALength);

#endif

