#ifndef AC_OMA_WEB_H
#define AC_OMA_WEB_H

#define AC_WEB_RETURNCODE_OK                 ((UINT32)0)

#define AC_WEB_RETURNCODE_MOCINVALID       ((UINT32)1)   /* 参数MOC不合法 */
#define AC_WEB_RETURNCODE_WTPIDLACK        ((UINT32)2)   /* 缺少WTPID参数 */
#define AC_WEB_RETURNCODE_WTPIDINVALID     ((UINT32)3)   /* WTPID不合法，只能取值1~1024 */
#define AC_WEB_RETURNCODE_GETDBRECORDFAIL  ((UINT32)4)   /* 从数据库模块获取记录失败 */
#define AC_WEB_RETURNCODE_GETDBRECORDUPLIMIT ((UINT32)5)   /* 从数据库模块获取记录内容越界 */

#define AC_WEB_RETURNCODE_ALARMNOTEXIST    ((UINT32)10)  /* 告警不存在 */

#define AC_OMA_ACTIVEALARM_REPORT_MAXNUM ((UINT32)50)

#define AC_WEB_READ_NOTFINISH	      ((UINT32)0)/* 未结束*/
#define AC_WEB_READ_FINISH		      ((UINT32)1)/* 读取结束 */

#define AC_WEB_WTPID_MIN             	AC_WTPID_MIN
#define AC_WEB_WTPID_MAX             	AC_WTPID_MAX

#define AC_WEB_DISPVALUE_LEN          ((UINT32)64)

#define AC_WEB_INDEX_NUM              ((UINT32)100)

// 2009-10-28 fengjing add
#define AC_OMA_CFG_ECODE_OK            ((UINT32)0)
#define AC_OMA_CFG_ECODE_FTP_FAIL ((UINT32)1)


typedef struct
{
    UINT32     ulMOC;
    CHAR       acTblName[32];
}tblinfo;


/*
 *	获取具体表记录信息内容
 */
typedef struct
{
    UINT32                 ulSn;
    UINT32                 ulMOC;
    UINT8                  aucMOI[AC_MOI_LEN];
}AC_WEB_GET_TBLOBJVALUE_REQ_MSG_T;

typedef struct
{
    UINT32                  ulSn;
    UINT32                  ulRet;
    UINT32                  ulRecLen;
    UINT8	                aucRecord[AC_DB_PACKET_MAX_LEN];	/* 记录内容 */
}AC_WEB_GET_TBLOBJVALUE_RSP_MSG_T;

/*
 * 获取当前所有活跃告警列表信息
 */
typedef struct
{
    UINT32 ulSn;
	UINT32 ulMOC;
	UINT8  aucMOI[AC_MOI_LEN];
    UINT32 ulStartRec;
}AC_WEB_GET_ACTIVEALARM_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
    UINT32  ulFinish;
    UINT32  ulAlarmNum;
    AC_OMC_ALARM_INFO_T astAlarmInfos[AC_OMA_ACTIVEALARM_REPORT_MAXNUM];
}AC_WEB_GET_ACTIVEALARM_RSP_MSG_T;

/*
 *	WEB清除活跃告警
 */
typedef struct
{
    UINT32  ulSn;
    AC_OMA_ALARM_CLEAR_INFO_T stAlarmClear;
}AC_WEB_CLEAR_ALARM_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
}AC_WEB_CLEAR_ALARM_RSP_MSG_T;

/*
 * WEB请求日志文件
 */
typedef struct
{
	UINT32  ulSn;
	UINT32  neType;
	UINT32  ulBeginTime;
	UINT32  ulEndTime;
}AC_WEB_GET_LOG_REQ_MSG_T;

typedef struct
{
	CHAR   acLogFileName[128];
}AC_WEB_LOGFILE_INFO_T;

typedef struct
{
	UINT32  ulSn;
	UINT32  ulRet;
	UINT32  ulNum;
	AC_WEB_LOGFILE_INFO_T astLogInfos[10];
}AC_WEB_GET_LOG_RSP_MSG_T;

/*
 * WEB请求某表所有记录内容
 */
typedef struct
{
    UINT32   ulSn;         /* SN */
    UINT32   ulMOC;        /* MOC */
    UINT32   ulWtpId;      /* WTP ID */
    UINT32   ulStartRec;
}AC_WEB_GET_TBLRECLIST_REQ_MSG_T;

typedef struct
{
    UINT32                 ulSn;      /* SN */
    UINT32                 ulRet;     /* return code */
    UINT32                 ulFinish;  /* finish flag */
	UINT32                 ulRecLen;  /* record len */
    UINT32                 ulRecNum;  /* record num */
    UINT8                  aucRecord[AC_DB_PACKET_MAX_LEN];    /* 记录内容 */
}AC_WEB_GET_TBLRECLIST_RSP_MSG_T;

/*
 * 获取某网元所有配置信息
 */
typedef struct
{
	UINT32                 ulSn;
	UINT32                 ulMOC;
	UINT8                  aucMOI[AC_MOI_LEN];
	UINT32                 ulStartMOC;
	UINT32                 ulStartRec;
}AC_WEB_EXPORT_MOS_REQ_MSG_T;

typedef struct
{
	UINT32                 ulSn;
	UINT32                 ulRet;
	UINT32                 ulFinish;
	UINT32                 ulFinishMOC;
	UINT32                 ulFinishRec;
	UINT32                 ulTblNum;
	/*
	 * UINT32  ulTblMOC;
	 * UINT32  ulRecLen;
	 * UINT32  ulRecNum;
	 * UINT8   aucRecord[];
	 */
    UINT8                  aucRecord[AC_DB_PACKET_MAX_LEN];
}AC_WEB_EXPORT_MOS_RSP_MSG_T;

/*
 *
 */
typedef struct
{
	UINT32                 ulSn;
}AC_WEB_GET_NEINFO_REQ_MSG_T;

typedef struct
{
	UINT32                 ulWtpId;
	UINT32                 ulWtpCfgDataVersion;
}AC_OMA_WTP_NEINFO_T;

/*
 *
 */
typedef struct
{
	UINT32                   ulSn;
	UINT32                   ulRet;
	CHAR                     acAcSwVersion[32];
	UINT32                   ulAcCfgDataVersion;
	UINT32                   ulWtpNum;
	AC_OMA_WTP_NEINFO_T      astWtpInfo[AC_OMA_WTP_MAXNUM];
}AC_WEB_GET_NEINFO_RSP_MSG_T;

// 2009-10-28 fengjing
typedef struct
{
	UINT32    ulSn;	
	UINT8      aucFtpSrvIp[4];    /* FTP服务器IP地址 */
	UINT32    ulFtpSrvPort;    /* FTP服务器端口号 */
	CHAR      acUserName[32];    /* 用户名 */
	CHAR      acPassword[32];    /* 密码 */	
	CHAR      acDirName[64];    /* 路径名*/
	CHAR      acFileName[64];    /* 数据文件名 */
}AC_OMC_UPLOAD_CFGDATAFILE_REQ_MSG_T;

typedef struct
{
	UINT32                    ulSn;
	UINT32                    ulRet;
	CHAR                      acCfgDataFilePath[128];  /* 上传文件路径 */
}AC_OMC_UPLOAD_CFGDATAFILE_RSP_MSG_T;

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
/*
 获取AP LICENSE 验证信息
 */
typedef struct
{
    UINT32  ulSn;
}AC_WEB_GET_AP_LICENSE_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
    UINT32  ulWebStat;             /* web显示状态
                                                    0-license验证成功
                                                    1-license硬件信息错误
                                                    2-license算法错误
                                                    */
}AC_WEB_GET_AP_LICENSE_RSP_MSG_T;

/*
 获取AC LICENSE 验证信息
 */
typedef struct
{
    UINT32  ulSn;
}AC_WEB_GET_AC_LICENSE_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
    UINT32  ulWebStat;             /* web显示状态
                                                    0-license验证成功
                                                    1-license硬件信息错误
                                                    2-license算法错误
                                                    3-ac试用期到期
                                                    4-ac试用期状态中
                                                    ...
                                                    11-ap接入功能错误
                                                    12-ac接入最大ap数目功能错误
                                                    ...
                                                    */
}AC_WEB_GET_AC_LICENSE_RSP_MSG_T;


/*
 设置LICENSE 服务器ip地址信息
 */
typedef struct
{
    UINT32  ulSn;
    UINT8   aucProxyNewIp[4];    /* License代理服务器的新IP地址 */
}AC_WEB_CHANGE_AC_LICENSE_SVIP_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
}AC_WEB_CHANGE_AC_LICENSE_SVIP_RSP_MSG_T;

/*
 获取LICENSE 服务器ip地址信息
 */
typedef struct
{
    UINT32  ulSn;
}AC_WEB_GET_AC_LICENSE_SVIP_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
    UINT8   aucProxyOldIp[4];    /* License代理服务器的旧IP地址 */
}AC_WEB_GET_AC_LICENSE_SVIP_RSP_MSG_T;

/*
 获取AC 试用时间信息
 */
typedef struct
{
    UINT32  ulSn;
}AC_WEB_GET_AC_LICENSE_TESTTIME_REQ_MSG_T;

typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
    UINT32  ulSurplusTimes;  /* License试用期剩余时间(单位秒s) */
    UINT32  ulSurauthorTimes;  /* License授权期内剩余时间(单位秒s) */
}AC_WEB_GET_AC_LICENSE_TESTTIME_RSP_MSG_T;
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */


/************************************************************************/
/* 函数声明                                                             */
/************************************************************************/
extern AC_RET ac_oma_web_send_rsp_msg(UINT32 ulReqNo, UINT32 ulRetCode, UINT16 usRspMsgId);
extern AC_RET ac_oma_web_convert_active_alarm_msg(AC_WEB_GET_ACTIVEALARM_RSP_MSG_T *pstRsp);

/* WEB请求配置信息 */
extern AC_RET ac_web_get_tblindexlist_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_web_get_tblobjvalue_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_web_get_tblreclist_req_msg(UINT8 *pReq, UINT16 usMsgLen);

extern AC_RET ac_web_export_ac_mos(AC_WEB_EXPORT_MOS_REQ_MSG_T *pstReq,
							       AC_WEB_EXPORT_MOS_RSP_MSG_T *pstRsp);

extern AC_RET ac_web_export_wtp_mos(AC_WEB_EXPORT_MOS_REQ_MSG_T *pstReq,
							       AC_WEB_EXPORT_MOS_RSP_MSG_T *pstRsp);

/* 导出网元信息 */
extern AC_RET ac_web_export_mos_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB请求告警信息 */
extern AC_RET ac_web_get_alarm_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB清除告警信息 */
extern AC_RET ac_web_clear_alarm_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB查询日志 */
extern AC_RET ac_web_get_log_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* WEB查询配置数据版本号 */
extern AC_RET ac_web_get_neinfo_req_msg(UINT8 *pReq, UINT16 usMsgLen);

// 2009-10-28 fengjing add
extern AC_RET ac_omc_upload_cfgdatafile_req_msg(UINT8 *pReq, UINT16 usMsgLen);

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
extern AC_RET ac_web_get_ap_license_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_web_get_ac_license_req_msg(UINT8 *pReq, UINT16 usMsgLen);
extern AC_RET ac_web_send_ac_license_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_web_change_ac_license_svip_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_web_get_ac_license_testtime_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_web_get_ac_license_svip_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */


#endif  /*AC_OMA_WEB_H*/
