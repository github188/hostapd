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
/* add by gwx 2012-9-6 for bug1562 AP添加ta40型号*/
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

/* 错误码定义 */
#define AC_OMA_SW_ERRCODE_OK                    ((UINT32)0)           /* 正常 */
#define AC_OMA_SW_ERRCODE_NETYPEINVALID         ((UINT32)1)           /* NE TYPE无效 */
#define AC_OMA_SW_ERRCODE_DLTYPEINVALID         ((UINT32)2)           /* 下载类型无效 */
#define AC_OMA_SW_ERRCODE_ACTIVATIONTYPEINVALID ((UINT32)3)           /* 生效类型非法 */
#define AC_OMA_SW_ERRCODE_FTPDOWNLOADFAIL       ((UINT32)4)           /* FTP下载失败 */
#define AC_OMA_SW_ERRCODE_DOWNLOADING           ((UINT32)5)           /* 正在下载中 */
#define AC_OMA_SW_ERRCODE_NETYPENOTMATCH        ((UINT32)6)           /* 网元类型不匹配 */
#define AC_OMA_SW_ERRCODE_SWVERSIONNOTMATCH     ((UINT32)7)           /* 软件版本不一致 */
#define AC_OMA_SW_ERRCODE_SWFILEINVALID         ((UINT32)8)           /* 软件文件无效 */
#define AC_OMA_SW_ERRCODE_TIMEOUT               ((UINT32)9)           /* 超时 */
#define AC_OMA_SW_ERRCODE_MSGLENINVALID         ((UINT32)10)          /* 请求消息长度不合法 */
#define AC_OMA_SW_ERRCODE_VERSTATENOTCHECKED    ((UINT32)11)          /* 版本状态不是待生效 */
#define AC_OMA_SW_ERRCODE_STATEVERFILEFAILED    ((UINT32)12)          /* 获取版本文件信息失败 */

#define AC_OMA_SW_ERRCODE_UNZIPSWVERFILEFAILED  ((UINT32)13)          /* 解压缩软件版本文件失败 */
#define AC_OMA_SW_ERRCODE_VERCONFFILENOTEXIST   ((UINT32)14)          /* 软件包版本属性文件不存在 */
#define AC_OMA_SW_ERRCODE_READCONFFILEFAILED    ((UINT32)15)          /* 读软件包版本属性文件失败 */
#define AC_OMA_SW_ERRCODE_PARSENETYPEFAILED     ((UINT32)16)          /* 解析版本属性文件中的网元类型失败 */
#define AC_OMA_SW_ERRCODE_PARSEVERSIONFAILED    ((UINT32)17)          /* 解析版本属性文件中的软件版本号失败 */
#define AC_OMA_SW_ERRCODE_MOVESWVERFILEFAILED   ((UINT32)18)          /* 转移软件版本文件失败 */
#define AC_OMA_SW_ERRCODE_UPDATESWVERLIBFAILED  ((UINT32)19)          /* 更新软件版本库信息失败 */
#define AC_OMA_SW_ERRCODE_CREATETARGETRFAILED   ((UINT32)20)          /* 生成目标版本文件失败 */

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
/* 删除网元软件版本 */
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

/* 网元软件文件信息 */
typedef struct 
{
    UINT32          ulFileFlag;     /* file flag */
    CHAR            acFileName[64]; /* file name */
    UINT32          ulFileLen;      /* file len */
}AC_OMA_SW_VERSION_FILE_T;

/* 软件版本下载信息 */
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

/* 网元软件生效信息 */
typedef struct 
{
    UINT32          ulActivateType;    /* activation type: 0:none|cancel/1:immediate/2:timing*/
    UINT32          ulActivateTime;    /* timing activation time */
}AC_OMA_SW_ACTIVATION_T;

/*
 *	软件（取消）版本下载请求消息体
 *  软件版本文件目录规划
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
 *	软件版本下载应答消息体
 */
typedef struct 
{
    UINT32             ulSn;     /* sn */
    UINT32             ulRet;    /* return code */
}AC_OMC_SW_DOWNLOAD_RSP_MSG_T;

/*
 *	查询软件版本下载进度及下载状态(OMC周期查询)
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
                                      * 0: 正常;
                                      * 1: 下载中;
                                      * 2: 待生效(下载完成校验成功);
                                      * 3: 下载失败;
                                      * 4: 校验失败;
                                    */
    UINT32            ulSwLoadSize; /* sw load size */
}AC_OMC_SW_SWVERSTATE_RSP_MSG_T;

/*
 *	软件生效请求消息体
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
 *	当AC接收到OMC下发软件下载请求时，检查当前软件下载状态downloadflag是否是1；
 *  如果是1，则返回错误应答给OMC，正在下载过程中，不能再下载
 *  如果是0，则赋值netype\swversion\swdownload\swactivation;
 *           设置downloadflag为1
 *           执行FTP下载程序，从指定位置下载软件版本到AC上约定位置；
 *           如果FTP下载失败，则设置downloadflag为0，返回错误应答给OMC；设置loadState为下载失败，loadSize为0
 *           如果FTP连接成功，并开始下载，则返回正确应答给OMC；设置loadState为下载中，loadSize为0
 *           如果在FTP下载过程中，downloadflag维持为1；
 *           如果当FTP下载过程中，接收到网元查询软件版本状态时，
 *                            检查软件版本是否匹配，如果软件版本不匹配，直接返回错误给OMC；
 *                            如果匹配，查询约定位置的该版本文件的当前大小，设置loadSize；并上报loadState和loadSize给OMC；
 *           如果FTP下载完成，检查软件版本是否与全局维护的一致，如果不一致，则不处理，结束；
 *                            否则，
 *                            重新获取设置当前loadSize值；
 *                            通知OMC获取版本状态信息;
 *                            检查如果是AP网元，则设置downloadFlag为0，设置loadState为正常，返回;
 *                            如果是AC网元，则调用校验函数，
 *                                  如果校验成功，则设置loadState为待生效
 *                                  如果校验失败，则设置loadState为校验失败
 *                                  再设置downloadFlag为0;
 *                                  如果校验成功，检查软件版本是否与全局维护的一致，如果一致，则不处理，结束；
 *                                       如果是AC网元，检查activation信息：
 *                                       如果为none/cancel，则不处理；
 *                                       如果为immediate，则设置activationflag为1，发送通知消息到应用模块通知立即生效；
 *                                       如果为timing,则设置activationflag为1，发送通知消息到应用模块通知定时生效；
 *  当AC接收到OMC下发取消软件下载请求时，
 *          检查软件版本是否与全局维护的软件版本一致，如果不一致，直接返回；
 *          检查当前软件激活状态：
 *          如果是activateFlag为1，发送取消生效的请求到应用模块；activateFlag=0
 *          设置中断FTP下载，downloadFlag=0,loadState=0,loadSize=0，activationflag=0,并返回正确应答;
 *  
 *  当AC接收到OMC下发检查当前软件版本状态时
 *  检查请求软件版本是否一致，如果不一致，则返回错误应答给OMC；
 *  重新设置loadSize值，获取loadState/loadSize返回给OMC正确应答;
 * 
 *  当AC接收到OMC下发软件生效请求时，即软件生效请求中的activationType为1/2，
 *      检查当前软件downloadFlag:
 *      如果downloadFlag为1，则返回错误应答给OMC，正在下载中；
 *      如果dwonloadFlag为0,且loadStatus不等于2，则返回错误应答给OMC。
 *      如果downloadFlag为0，且loadState等于2,检查activationFlag: 
 *                          如果是1，发送取消生效的请求到应用模块;
 *                          重新设置activation配置内容；
 *                          发送新的软件生效请求到应用模块;
 *                          设置activationFlag为1;
 *                          返回正确应答给OMC;
 *
 *  当AC接收到OMC下发取消软件生效时，即软件生效请求中的activationType为0,
 *     检查当前软件activationFlag,
 *          如果为1，则发送取消生效的请求到应用模块；
 *                   重新设置activation配置内容;
 *                   返回正确应答给OMC;    
 *          如果为0，不处理，直接返回应答给AC
 */
typedef struct 
{
    UINT32                 ulNeType;         /* ne type */
    CHAR                   acSwVersion[32];  /* ne sw version */
    AC_OMA_SW_DOWNLOAD_T   stSwDownload;     /* sw download info */
    UINT32                 ulSwDownloadFlag;  /* sw download flag */
    UINT32                 ulSwDownLoadState; /** 
                                            * sw state
                                            * 0: 正常(初始态，已生效);
                                            * 1: 下载中;
                                            * 2: 待生效(下载完成校验成功);
                                            * 3: 下载失败;
                                            * 4: 校验失败;
                                            */
    UINT32                 ulSwDownLoadSize;   /* sw load size */
    AC_OMA_SW_ACTIVATION_T stSwActivation;     /* sw actication  */
    UINT32                 ulSwActivationFlag; /* sw actication flag */
}AC_OMA_SWVERSION_INFO_T;

/* WTP软件版本信息 */
typedef struct 
{
	
    UINT32                 ulNeType;         /* ne type */
    CHAR                   acSwVersion[32];  /* ne sw version */
    AC_OMA_SW_DOWNLOAD_T   stSwDownload;     /* sw download info */
    UINT32                 ulSwDownloadFlag;  /* sw download flag */
    UINT32                 ulSwDownLoadState; /** 
                                            * sw state
                                            * 0: 正常(初始态，已生效);
                                            * 1: 下载中;
                                            * 2: 待生效(下载完成校验成功);
                                            * 3: 下载失败;
                                            * 4: 校验失败;
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
                                            * 0: 正常(初始态，已生效);
                                            * 1: 下载中;
                                            * 2: 待生效(下载完成校验成功);
                                            * 3: 下载失败;
                                            * 4: 校验失败;
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
 * WEB请求导入软件版本
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
 * WEB请求获取对应网元类型的网元软件版本列表
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
 * WEB请求获取生效指定的网元软件版本
 */
typedef struct
{
	UINT32                     ulSn;
	//UINT32                     ulNeType; //只能是3
	AC_APP_SW_ACTIVATEE_INFO_T stSwActivation;
}AC_WEB_SW_ACTIVATE_REQ_MSG_T;

typedef struct
{
	UINT32                    ulSn;
	UINT32                    ulRet;
}AC_WEB_SW_ACTIVATE_RSP_MSG_T;

/************************************************************************/
/* 函数声明                                                             */
/************************************************************************/
extern AC_RET ac_oma_sw_check_validity(VOID);
extern AC_RET ac_oma_sw_ftp_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);
extern AC_RET ac_oma_sw_send_rsp_msg(UINT32 ulSn, UINT32 ulRetCode, UINT16 usRspMsgId);

/* OMC请求软件下载、生效、版本文件状态查询、版本状态查询 */
extern AC_RET ac_oma_ac_sw_ftp_download_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_oma_wtp_sw_ftp_download_req_msg(UINT8 *pReq, UINT16 usMsgLen);

extern AC_RET ac_oma_ac_sw_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);
extern AC_RET ac_oma_wtp_sw_download(AC_OMC_SW_DOWNLOAD_REQ_MSG_T *pstReq, AC_OMC_SW_DOWNLOAD_RSP_MSG_T *pstRsp);

extern AC_RET ac_omc_sw_dowload_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_omc_sw_activate_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_omc_sw_version_state_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* 初始化当前所有软件版本 */
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

/* WEB通知网元软件版本入库 */
extern AC_RET ac_web_import_swver_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB查询软件版本库信息 */
extern AC_RET ac_web_get_sw_verlib_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB请求AC网元软件生效请求 */
extern AC_RET ac_web_sw_activate_req_msg(UINT8 *pReq, UINT16 usMsgLen);

AC_RET ac_oma_get_unzip_dir_name(CHAR *szZipFileName, CHAR *szUnzipDir);
void list_dir_x(const char *path, UINT32 ulNeType);
void FindFileInDir(char* rootDir, char* strRet, UINT32 ulNeType);

AC_RET ac_oma_get_target_ver_path_name(CHAR *szFullName, CHAR *szShortName);
AC_RET ac_oma_create_target_version(AC_APP_SW_ACTIVATEE_INFO_T *pstAppSwActivation);
AC_RET ac_oma_sw_activate_do(AC_APP_SW_ACTIVATEE_INFO_T *pstAppSwActivation);

/* AC网元延时重启 */
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
