#ifndef AC_OMA_SW_H
#define AC_OMA_SW_H

#define AC_OMA_SW_DIR         "version/"
#define AC_OMA_SW_AC_DIR      AC_OMA_SW_DIR"/ac/"
#define AC_OMA_SW_WTP_DIR     AC_OMA_SW_DIR"/ap/"

#define AC_OMA_SW_ZIP_DIR     AC_OMA_SW_DIR"/zip/"
#define AC_OMA_SW_UNZIP_DIR   AC_OMA_SW_DIR"/unzip/"

#define AC_OMA_DIR_SEPERATOR  "/"

#define AC_OMA_FTP_IPADDR     "127.0.0.1"
#define AC_OMA_FTP_USERNAME   "gbcom"
#define AC_OMA_FTP_PASSWORD   "gbcom"
#define AC_OMA_FTP_VERDIR     "./ver/zip"

#define AC_OMA_SWVER_CONF_FILE               "version.conf"
#define AC_OMA_SWVER_TARGET_CONF_FILE        "target_version.conf"

#define AC_OMA_SWVER_NUM_MAX                 ((UINT32)100)

#define AC_OMA_NETYPE_WTP  ((UINT32)1)
//#define AC_OMA_NETYPE_STA ((UINT32)2)
#define AC_OMA_NETYPE_AC   ((UINT32)3)

#define AC_OMA_HARDVERTYPE_IXP   ((UINT32)10)
#define AC_OMA_HARDVERTYPE_AP93  ((UINT32)1)
#define AC_OMA_HARDVERTYPE_PB44  ((UINT32)12)
//2012/3/12 zoucaihong add 9344 AP
#define AC_OMA_HARDVERTYPE_9344  ((UINT32)4)
/* add by gwx 2012-9-6 for bug1562 AP���ta40�ͺ�*/
#define AC_OMA_HARDVERTYPE_TA40  ((UINT32)5)
#define AC_OMA_HARDVERTYPE_TA33  ((UINT32)7)
#define AC_OMA_HARDVERTYPE_TA55  ((UINT32)8)

#define AC_OMA_SW_DOWNLOADTYPE_CANCEL        ((UINT32)0)
#define AC_OMA_SW_DOWNLOADTYPE_DOWNLOAD      ((UINT32)1)

#define AC_OMA_SW_ACTIVATIONTYPE_NONE        ((UINT32)0)
#define AC_OMA_SW_ACTIVATIONTYPE_IMMEDIATE   ((UINT32)1)
#define AC_OMA_SW_ACTIVATIONTYPE_TIMING      ((UINT32)2)

#define AC_OMA_SW_FILE_VALID                 ((UINT32)1)
#define AC_OMA_SW_FILE_INVALID               ((UINT32)0)

#define AC_OMA_SW_VERSTATE_NONE              ((UINT32)0)
#define AC_OMA_SW_VERSTATE_DOWNLOADING       ((UINT32)1)
#define AC_OMA_SW_VERSTATE_CHECKACTING       ((UINT32)2)
#define AC_OMA_SW_VERSTATE_DOWNLOADFAIL      ((UINT32)3)
#define AC_OMA_SW_VERSTATE_CHECKFAIL         ((UINT32)4)

/* �����붨�� */
#define AC_OMA_SW_ERRCODE_OK                    ((UINT32)0)           /* ���� */
#define AC_OMA_SW_ERRCODE_NETYPEINVALID         ((UINT32)1)           /* NE TYPE��Ч */
#define AC_OMA_SW_ERRCODE_DLTYPEINVALID         ((UINT32)2)           /* ����������Ч */
#define AC_OMA_SW_ERRCODE_ACTIVATIONTYPEINVALID ((UINT32)3)           /* ��Ч���ͷǷ� */
#define AC_OMA_SW_ERRCODE_FTPDOWNLOADFAIL       ((UINT32)4)           /* FTP����ʧ�� */
#define AC_OMA_SW_ERRCODE_DOWNLOADING           ((UINT32)5)           /* ���������� */
#define AC_OMA_SW_ERRCODE_NETYPENOTMATCH        ((UINT32)6)           /* ��Ԫ���Ͳ�ƥ�� */
#define AC_OMA_SW_ERRCODE_SWVERSIONNOTMATCH     ((UINT32)7)           /* ����汾��һ�� */
#define AC_OMA_SW_ERRCODE_SWFILEINVALID         ((UINT32)8)           /* ����ļ���Ч */
#define AC_OMA_SW_ERRCODE_TIMEOUT               ((UINT32)9)           /* ��ʱ */
#define AC_OMA_SW_ERRCODE_MSGLENINVALID         ((UINT32)10)          /* ������Ϣ���Ȳ��Ϸ� */
#define AC_OMA_SW_ERRCODE_VERSTATENOTCHECKED    ((UINT32)11)          /* �汾״̬���Ǵ���Ч */
#define AC_OMA_SW_ERRCODE_STATEVERFILEFAILED    ((UINT32)12)          /* ��ȡ�汾�ļ���Ϣʧ�� */

#define AC_OMA_SW_ERRCODE_UNZIPSWVERFILEFAILED  ((UINT32)13)          /* ��ѹ������汾�ļ�ʧ�� */
#define AC_OMA_SW_ERRCODE_VERCONFFILENOTEXIST   ((UINT32)14)          /* ������汾�����ļ������� */
#define AC_OMA_SW_ERRCODE_READCONFFILEFAILED    ((UINT32)15)          /* ��������汾�����ļ�ʧ�� */
#define AC_OMA_SW_ERRCODE_PARSENETYPEFAILED     ((UINT32)16)          /* �����汾�����ļ��е���Ԫ����ʧ�� */
#define AC_OMA_SW_ERRCODE_PARSEVERSIONFAILED    ((UINT32)17)          /* �����汾�����ļ��е�����汾��ʧ�� */
#define AC_OMA_SW_ERRCODE_MOVESWVERFILEFAILED   ((UINT32)18)          /* ת������汾�ļ�ʧ�� */
#define AC_OMA_SW_ERRCODE_UPDATESWVERLIBFAILED  ((UINT32)19)          /* ��������汾����Ϣʧ�� */
#define AC_OMA_SW_ERRCODE_CREATETARGETRFAILED   ((UINT32)20)          /* ����Ŀ��汾�ļ�ʧ�� */

#define AC_OMA_SW_SECTION                       "sw"
#define AC_OMA_SW_NETYPE_KEY                    "type"
/* 2010-10-21 fengjing add */
#define AC_OMA_SW_HARDVER_KEY                  "hardver"
#define AC_OMA_SW_VERSION_KEY                   "version"

#define AC_OMA_SW_TARGET_SECTION                "Target"
#define AC_OMA_SW_TARGET_VERSION                "version"
#define AC_OMA_SW_TARGET_PATH                   "path"
#define AC_OMA_SW_TARGET_TIME                   "time"

/* 2009-10-20 fengjing add delete ne sw */
/* ɾ����Ԫ����汾 */
typedef struct
{
	UINT32   ulSn;
	UINT32   ulNeType;/* ne type:1:ap/3:ac */
	CHAR     acSwVersion[32];
}AC_OMC_SW_DELETE_REQ_MSG_T;

typedef struct
{
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMC_SW_DELETE_RSP_MSG_T;

/* ��Ԫ����ļ���Ϣ */
typedef struct 
{
    UINT32          ulFileFlag;     /* file flag */
    CHAR            acFileName[64]; /* file name */
    UINT32          ulFileLen;      /* file len */
}AC_OMA_SW_VERSION_FILE_T;

/* ����汾������Ϣ */
typedef struct 
{    
    UINT32                   ulSwDownloadType;  /* 0:cancel/1:download */
    UINT8                    aucFtpSrvIp[4]; /* ftp ip addr */
    UINT32                   ulFtpSrvPort;   /* ftp port */
    CHAR                     acUserName[32]; /* user name */
    CHAR                     acPassword[32]; /* user password */
    CHAR                     acDirName[64];  /* directory name */
    AC_OMA_SW_VERSION_FILE_T stSwVerFile;    /* sw version file name */
}AC_OMA_SW_DOWNLOAD_T;

/* ��Ԫ�����Ч��Ϣ */
typedef struct 
{
    UINT32          ulActivateType;    /* activation type: 0:none|cancel/1:immediate/2:timing*/
    UINT32          ulActivateTime;    /* timing activation time */
}AC_OMA_SW_ACTIVATION_T;

/*
 *	�����ȡ�����汾����������Ϣ��
 *  ����汾�ļ�Ŀ¼�滮
 *  sw--|__
 *      |__ac
 *      |___|__acsw1
 *      |___|__|____|__acsw1.zip
 *      |___|__acsw2
 *      |__wtp
 *      |___|__wtpsw1
 *      |___|__wtpsw2
 *      |___|__....
 */
typedef struct 
{
    UINT32                 ulSn;
    UINT32                 ulNeType;        /* ne type:1:ap/3:ac */
    CHAR                   acSwVersion[32];  
    AC_OMA_SW_DOWNLOAD_T   stSwDownload;    /* sw download info */
    AC_OMA_SW_ACTIVATION_T stSwActivation;  /* sw actication  */
}AC_OMC_SW_DOWNLOAD_REQ_MSG_T;

/*
 *	����汾����Ӧ����Ϣ��
 */
typedef struct 
{
    UINT32             ulSn;     /* sn */
    UINT32             ulRet;    /* return code */
}AC_OMC_SW_DOWNLOAD_RSP_MSG_T;

/*
 *	��ѯ����汾���ؽ��ȼ�����״̬(OMC���ڲ�ѯ)
 */
typedef struct 
{
    UINT32            ulSn;       /* sn */
    UINT32            ulNeType;   /* ne type */
    CHAR              acSwVersion[32]; /* ne sw version */
}AC_OMC_SW_SWVERSTATE_REQ_MSG_T;

typedef struct
{
    UINT32            ulSn;     /* sn */
    UINT32            ulRet;    /* return code */
    UINT32            ulSwLoadState; /** 
                                      * sw state
                                      * 0: ����;
                                      * 1: ������;
                                      * 2: ����Ч(�������У��ɹ�);
                                      * 3: ����ʧ��;
                                      * 4: У��ʧ��;
                                    */
    UINT32            ulSwLoadSize; /* sw load size */
}AC_OMC_SW_SWVERSTATE_RSP_MSG_T;

/*
 *	�����Ч������Ϣ��
 */
typedef struct 
{
    UINT32                 ulSn;            /* sn */
    UINT32                 ulNeType;        /* ne type */
    CHAR                   acSwVersion[32]; /* activation sw version */
    AC_OMA_SW_ACTIVATION_T stSwActivation;  /* sw activation config */
}AC_OMC_SW_ACTIVATION_REQ_MSG_T;

typedef struct 
{
    UINT32                 ulSn;    /* sn */           
    UINT32                 ulRet;   /* return code */
}AC_OMC_SW_ACTIVATION_RSP_MSG_T;

/*
 *	��AC���յ�OMC�·������������ʱ����鵱ǰ�������״̬downloadflag�Ƿ���1��
 *  �����1���򷵻ش���Ӧ���OMC���������ع����У�����������
 *  �����0����ֵnetype\swversion\swdownload\swactivation;
 *           ����downloadflagΪ1
 *           ִ��FTP���س��򣬴�ָ��λ����������汾��AC��Լ��λ�ã�
 *           ���FTP����ʧ�ܣ�������downloadflagΪ0�����ش���Ӧ���OMC������loadStateΪ����ʧ�ܣ�loadSizeΪ0
 *           ���FTP���ӳɹ�������ʼ���أ��򷵻���ȷӦ���OMC������loadStateΪ�����У�loadSizeΪ0
 *           �����FTP���ع����У�downloadflagά��Ϊ1��
 *           �����FTP���ع����У����յ���Ԫ��ѯ����汾״̬ʱ��
 *                            �������汾�Ƿ�ƥ�䣬�������汾��ƥ�䣬ֱ�ӷ��ش����OMC��
 *                            ���ƥ�䣬��ѯԼ��λ�õĸð汾�ļ��ĵ�ǰ��С������loadSize�����ϱ�loadState��loadSize��OMC��
 *           ���FTP������ɣ��������汾�Ƿ���ȫ��ά����һ�£������һ�£��򲻴���������
 *                            ����
 *                            ���»�ȡ���õ�ǰloadSizeֵ��
 *                            ֪ͨOMC��ȡ�汾״̬��Ϣ;
 *                            ��������AP��Ԫ��������downloadFlagΪ0������loadStateΪ����������;
 *                            �����AC��Ԫ�������У�麯����
 *                                  ���У��ɹ���������loadStateΪ����Ч
 *                                  ���У��ʧ�ܣ�������loadStateΪУ��ʧ��
 *                                  ������downloadFlagΪ0;
 *                                  ���У��ɹ����������汾�Ƿ���ȫ��ά����һ�£����һ�£��򲻴���������
 *                                       �����AC��Ԫ�����activation��Ϣ��
 *                                       ���Ϊnone/cancel���򲻴���
 *                                       ���Ϊimmediate��������activationflagΪ1������֪ͨ��Ϣ��Ӧ��ģ��֪ͨ������Ч��
 *                                       ���Ϊtiming,������activationflagΪ1������֪ͨ��Ϣ��Ӧ��ģ��֪ͨ��ʱ��Ч��
 *  ��AC���յ�OMC�·�ȡ�������������ʱ��
 *          �������汾�Ƿ���ȫ��ά��������汾һ�£������һ�£�ֱ�ӷ��أ�
 *          ��鵱ǰ�������״̬��
 *          �����activateFlagΪ1������ȡ����Ч������Ӧ��ģ�飻activateFlag=0
 *          �����ж�FTP���أ�downloadFlag=0,loadState=0,loadSize=0��activationflag=0,��������ȷӦ��;
 *  
 *  ��AC���յ�OMC�·���鵱ǰ����汾״̬ʱ
 *  �����������汾�Ƿ�һ�£������һ�£��򷵻ش���Ӧ���OMC��
 *  ��������loadSizeֵ����ȡloadState/loadSize���ظ�OMC��ȷӦ��;
 * 
 *  ��AC���յ�OMC�·������Ч����ʱ���������Ч�����е�activationTypeΪ1/2��
 *      ��鵱ǰ���downloadFlag:
 *      ���downloadFlagΪ1���򷵻ش���Ӧ���OMC�����������У�
 *      ���dwonloadFlagΪ0,��loadStatus������2���򷵻ش���Ӧ���OMC��
 *      ���downloadFlagΪ0����loadState����2,���activationFlag: 
 *                          �����1������ȡ����Ч������Ӧ��ģ��;
 *                          ��������activation�������ݣ�
 *                          �����µ������Ч����Ӧ��ģ��;
 *                          ����activationFlagΪ1;
 *                          ������ȷӦ���OMC;
 *
 *  ��AC���յ�OMC�·�ȡ�������Чʱ���������Ч�����е�activationTypeΪ0,
 *     ��鵱ǰ���activationFlag,
 *          ���Ϊ1������ȡ����Ч������Ӧ��ģ�飻
 *                   ��������activation��������;
 *                   ������ȷӦ���OMC;    
 *          ���Ϊ0��������ֱ�ӷ���Ӧ���AC
 */
typedef struct 
{
    UINT32                 ulNeType;         /* ne type */
    CHAR                   acSwVersion[32];  /* ne sw version */
    AC_OMA_SW_DOWNLOAD_T   stSwDownload;     /* sw download info */
    UINT32                 ulSwDownloadFlag;  /* sw download flag */
    UINT32                 ulSwDownLoadState; /** 
                                            * sw state
                                            * 0: ����(��ʼ̬������Ч);
                                            * 1: ������;
                                            * 2: ����Ч(�������У��ɹ�);
                                            * 3: ����ʧ��;
                                            * 4: У��ʧ��;
                                            */
    UINT32                 ulSwDownLoadSize;   /* sw load size */
    AC_OMA_SW_ACTIVATION_T stSwActivation;     /* sw actication  */
    UINT32                 ulSwActivationFlag; /* sw actication flag */
}AC_OMA_SWVERSION_INFO_T;

/* WTP����汾��Ϣ */
typedef struct 
{
	
    UINT32                 ulNeType;         /* ne type */
    CHAR                   acSwVersion[32];  /* ne sw version */
    AC_OMA_SW_DOWNLOAD_T   stSwDownload;     /* sw download info */
    UINT32                 ulSwDownloadFlag;  /* sw download flag */
    UINT32                 ulSwDownLoadState; /** 
                                            * sw state
                                            * 0: ����(��ʼ̬������Ч);
                                            * 1: ������;
                                            * 2: ����Ч(�������У��ɹ�);
                                            * 3: ����ʧ��;
                                            * 4: У��ʧ��;
                                            */
    UINT32                 ulSwDownLoadSize;   /* sw load size */
    AC_OMA_SW_ACTIVATION_T stSwActivation;     /* sw actication  */
    UINT32                 ulSwActivationFlag; /* sw actication flag */
}AC_OMA_WTP_SWVERSON_INFO_T;

typedef struct 
{    
    UINT32                   ulNeType;       /* ne type */
    CHAR                     acSwVersion[32];  
    UINT8                    aucFtpSrvIp[4]; /* ftp ip addr */
    UINT32                   ulFtpSrvPort;   /* ftp port */
    CHAR                     acUserName[32]; /* user name */
    CHAR                     acPassword[32]; /* user password */
    CHAR                     acDirName[64];  /* directory name */
    AC_OMA_SW_VERSION_FILE_T stSwVerFile;    /* sw version file name */
}AC_OMA_SW_FTP_DOWNLOAD_INTO_T;

/*
 *	
 */
typedef struct 
{
    CHAR                     acSwVersion[32];  
    AC_OMA_SW_ACTIVATION_T   stSwActivation;
}AC_APP_SW_ACTIVATEE_INFO_T;

/*
 *	
 */
typedef struct 
{
	UINT32                   ulSn;     /* SN */
    UINT32                   ulMOC;
	UINT8                    aucMOI[AC_MOI_LEN];   /* */
    CHAR                     acSwVersion[32];
    UINT32                   ulSwDownLoadState; /** 
                                            * sw state
                                            * 0: ����(��ʼ̬������Ч);
                                            * 1: ������;
                                            * 2: ����Ч(�������У��ɹ�);
                                            * 3: ����ʧ��;
                                            * 4: У��ʧ��;
                                            */
    UINT32                   ulSwDownLoadSize;   /* sw load size */
}AC_OMC_SW_DOWNLOAD_NOTIFY_MSG_T;

/*
 * ne sw info
 */
typedef struct  
{
	UINT32                  ulNeType;
	CHAR                    acSwVersion[32];
	CHAR                    acFilePath[128];
}AC_OMA_SW_VER_INFO_T;

/*
 * ne sw lib
 */
typedef struct  
{
	UINT32                  ulSwVerNum;
	AC_OMA_SW_VER_INFO_T    astSwVerInfo[AC_OMA_SWVER_NUM_MAX];
}AC_OMC_SW_VERLIB_T;

/*
 * WEB����������汾
 */
typedef struct  
{
	UINT32                   ulSn;
	CHAR                     acSwFilePath[128];
}AC_WEB_IMPORT_SWVER_REQ_MSG_T;

typedef struct  
{
	UINT32                   ulSn;
	UINT32                   ulRet;
}AC_WEB_IMPORT_SWVER_RSP_MSG_T;


/*
 * WEB�����ȡ��Ӧ��Ԫ���͵���Ԫ����汾�б�
 */
typedef struct
{
	UINT32                   ulSn;
	UINT32                   ulNeType; //1:AP 3:AC
}AC_WEB_GET_SW_VERLIB_REQ_MSG_T;

typedef struct
{
	UINT32                   ulSn;
	UINT32                   ulRet;
	UINT32                   ulSwVerNum;
	CHAR                     aacSwVersion[AC_OMA_SWVER_NUM_MAX][32];
}AC_WEB_GET_SW_VERLIB_RSP_MSG_T;

/*
 * WEB�����ȡ��Чָ������Ԫ����汾
 */
typedef struct
{
	UINT32                     ulSn;
	//UINT32                     ulNeType; //ֻ����3
	AC_APP_SW_ACTIVATEE_INFO_T stSwActivation;
}AC_WEB_SW_ACTIVATE_REQ_MSG_T;

typedef struct
{
	UINT32                    ulSn;
	UINT32                    ulRet;
}AC_WEB_SW_ACTIVATE_RSP_MSG_T;

/************************************************************************/
/* ��������                                                             */
/************************************************************************/
extern AC_RET ac_oma_sw_check_validity(VOID);
extern AC_RET ac_oma_sw_ftp_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);
extern AC_RET ac_oma_sw_send_rsp_msg(UINT32 ulSn, UINT32 ulRetCode, UINT16 usRspMsgId);

/* OMC����������ء���Ч���汾�ļ�״̬��ѯ���汾״̬��ѯ */
extern AC_RET ac_oma_ac_sw_ftp_download_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_oma_wtp_sw_ftp_download_req_msg(UINT8 *pReq, UINT16 usMsgLen);

extern AC_RET ac_oma_ac_sw_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);
extern AC_RET ac_oma_wtp_sw_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);

extern AC_RET ac_omc_sw_dowload_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_omc_sw_activate_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_omc_sw_version_state_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* ��ʼ����ǰ��������汾 */
extern AC_RET ac_oma_init_sw_verlib(VOID);
extern AC_RET ac_oma_update_sw_verlib(UINT32 ulNeType, CHAR *acSwVersion, CHAR *acFilePath);

BOOL ac_oma_read_ver_conf_file(LPTSTR strFile);
CHAR* ac_oma_get_base_name(const CHAR *filename);
BOOL ac_oma_delete_comment (VOID);
BOOL ac_oma_recognize_section (WORD *pwLoop);
BOOL ac_oma_recongnize_value (WORD wSecStart, WORD wSecEnd);
BOOL ac_oma_check_in_char_set (CHAR chIn);
BOOL ac_oma_check_in_seperate_set (CHAR chIn);
BOOL ac_oma_check_in_number_set(CHAR chIn);
BOOL ac_oma_get_config_int_param (LPTSTR strSec, LPTSTR strParam, DWORD *pdwOutNum);
BOOL ac_oma_get_config_str_param (LPTSTR strSec, LPTSTR strParam, LPTSTR strOutParam);
BOOL ac_oma_analyse_num_param (LPTSTR strValue, BYTE byValueLen, DWORD *pdwOutNum);
BOOL ac_oma_analyse_str_param (LPTSTR strValue, BYTE byValueLen, LPTSTR strOutParam);

/* WEB֪ͨ��Ԫ����汾��� */
extern AC_RET ac_web_import_swver_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB��ѯ����汾����Ϣ */
extern AC_RET ac_web_get_sw_verlib_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB����AC��Ԫ�����Ч���� */
extern AC_RET ac_web_sw_activate_req_msg(UINT8 *pReq, UINT16 usMsgLen);

AC_RET ac_oma_get_unzip_dir_name(CHAR *szZipFileName, CHAR *szUnzipDir);
void list_dir_x(const char *path, UINT32 ulNeType);
void FindFileInDir(char* rootDir, char* strRet, UINT32 ulNeType);

AC_RET ac_oma_get_target_ver_path_name(CHAR *szFullName, CHAR *szShortName);
AC_RET ac_oma_create_target_version(AC_APP_SW_ACTIVATEE_INFO_T *pstAppSwActivation);
AC_RET ac_oma_sw_activate_do(AC_APP_SW_ACTIVATEE_INFO_T *pstAppSwActivation);

/* AC��Ԫ��ʱ���� */
VOID ac_oma_ac_sw_relay_reset(VOID);

/* 2009-08-21 fengjing add begin */
extern AC_RET ac_omc_ap_swfilestate_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_swfilestate_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_ap_swfilestate_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2009-08-21 fengjing add end */

/* 2009-10-20 fengjing add begin */
extern AC_RET ac_oma_sw_delete_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* 2009-10-20 fengjing add end */
extern AC_RET ac_oma_ap_swfilestate_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);

#endif
