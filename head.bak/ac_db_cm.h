/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  配置流程头文件
* 修改历史:
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DB_CM_H
#define  _AC_DB_CM_H

/* 定时器ID定义 */
#define AC_DB_TIMER_WAIT_CFG_DOWNLOAD_REQ		TIMER0	     /* 等待网管cfg download req定时器 */
#define AC_DB_TIMER_WAIT_COMMIT_REQ        			TIMER1       /* 等待网管commit req定时器 */
#define AC_DB_TIMER_WAIT_CW_CFG_RSP        			TIMER2       /* 等待CAPWAP配置更新响应定时器*/
#define AC_DB_TIMER_CFG_VERSION_IND				TIMER11		 /* 周期性上报配置数据版本号定时器*/
#define AC_DB_TIMER_OMCHEARTBEAT					TIMER12		/* 与OMC之间的心跳周期*/


/* 定时器超时消息定义*/
#define AC_DB_TIMEOUT_WAIT_CFG_DOWNLOAD_REQ		EV_TIMER0
#define AC_DB_TIMEOUT_WAIT_COMMIT_REQ     			EV_TIMER1
#define AC_DB_TIMEOUT_WAIT_CW_CFG_RSP    				EV_TIMER2
#define AC_DB_TIMEOUT_CFG_VERSION_IND				EV_TIMER11
#define AC_DB_TIMEOUT_OMCHEARTBEAT					EV_TIMER12

/* 定时器时长定义*/
#define AC_DB_TIMER_WAIT_CFG_DOWNLOAD_REQ_LEN		100		/* 单位100ms */
#define AC_DB_TIMER_WAIT_COMMIT_REQ_LEN             		600     	/* 单位100ms */
#define AC_DB_TIMER_WAIT_CW_CFG_RSP_LEN             		1200    	/* 单位100ms */
#define AC_DB_TIMER_CFG_VERSION_IND_LEN				600		/* 单位100ms */	/* 2010-3-26 pyy 上报周期10s->60s */
#define AC_DB_TIMER_OMCHEARTBEAT_LEN					100		/* 单位100ms */

/*  增量操作类型 */
#define AC_DB_INC_OPR_INSERT    	'I'    		/* insert */
#define AC_DB_INC_OPR_UPDATE    	'U'    	/* update */
#define AC_DB_INC_OPR_DELETE    	'D'    	/* delete */

/* MSG ID定义，与网管之间的消息接口 */
#define AC_DB_CFG_REQ_MSG           					(EV_DB_BEGIN+1)     	/* 配置修改请求*/
#define AC_DB_CFG_RSP_MSG           					(EV_DB_BEGIN+2)     	/* 配置修改 响应*/
#define AC_DB_CFG_DOWNLOAD_REQ_MSG				(EV_DB_BEGIN+3)		/* 配置下载请求*/
#define AC_DB_CFG_DOWNLOAD_RSP_MSG				(EV_DB_BEGIN+4)		/* 配置下载响应*/
#define AC_DB_COMMIT_REQ_MSG        				(EV_DB_BEGIN+5)    	/* 事务提交请求*/
#define AC_DB_COMMIT_RSP_MSG        				(EV_DB_BEGIN+6)    	/* 事务修改响应*/
#define AC_DB_ROLLBACK_REQ_MSG      				(EV_DB_BEGIN+7)    	/* 配置回滚请求*/
#define AC_DB_DYNREPORT_REQ_MSG					(EV_DB_BEGIN+8)		/* 请求上报动态数据请求, 由OMC发起*/
#define AC_DB_AC_RESET_REQ_MSG					(EV_DB_BEGIN+9)		/* AC重启请求, 由OMC发起*/
#define AC_DB_AC_RESET_RSP_MSG					(EV_DB_BEGIN+10)		/* AC重启应答, 发给OMC */

#define AC_DB_CFG_VERSION_IND_MSG				(EV_DB_BEGIN+11)		/* 配置数据版本号通知消息*/

/* 2008-12-1 pyy add start */
#define AC_DB_PRDDYN_STATE_REPORT_MSG   			(EV_DB_BEGIN+12)  	/* 周期性状态信息上报消息 */
#define AC_DB_PRDDYN_USERINFO_REPORT_MSG  		(EV_DB_BEGIN+13)  	/* 周期性用户信息上报消息 */
/* 2008-12-1 pyy add end */

/* OMC-AC恢复出厂配置消息*/
/* 恢复AC缺省配置 */
#define AC_DB_AC_RESET_DEFAULT_CFG_REQ_MSG  	(EV_DB_BEGIN+15)
#define AC_DB_AC_RESET_DEFAULT_CFG_RSP_MSG  		(EV_DB_BEGIN+16)

/* 恢复AP缺省配置 */
#define AC_DB_AP_RESET_DEFAULT_CFG_REQ_MSG  	(EV_DB_BEGIN+17)
#define AC_DB_AP_RESET_DEFAULT_CFG_RSP_MSG  		(EV_DB_BEGIN+18)

/* AP配置文件更新*/
#define AC_DB_AP_CFGUPDATE_REQ_MSG 				(EV_DB_BEGIN+19)
#define AC_DB_AP_CFGUPDATE_RSP_MSG 				(EV_DB_BEGIN+20)

/* 与CAPWAP之间的消息接口*/
#define AC_DB_CFG_UPDATE_REQ_MSG    				(EV_DB_BEGIN+21)    	/* CM向CAPWAP发送配置更新请求*/
#define AC_DB_CFG_UPDATE_RSP_MSG   				(EV_DB_BEGIN+22)    	/* CAPWAP将配置数据分发到各WTP后向CM发送配置更新响应 */
#define AC_DB_ACRESET_IND_MSG						(EV_DB_BEGIN+23)		/* AC重启指示消息*/

/* OMC请求获取指定AP的所有动态信息*/
#define AC_DB_AP_DYNAINFO_REPORT_REQ_MSG   		(EV_DB_BEGIN+24)   	/* 2010-6-28 pyy 修改: 重复 修改为10024 */
#define AC_DB_APCFG_REFRESH_REQ_MSG				(EV_DB_BEGIN+25)		/* 2010-6-28 pyy 新增: 刷新AP操作, 手动强制下发AP的配置*/
#define AC_DB_APCFG_REFRESH_RSP_MSG				(EV_DB_BEGIN+26)	

/* 2010/05/26 fengjing add */
/* AP配置文件备份 */
#define AC_DB_AP_CFGBACKUP_REQ_MSG               (EV_DB_BEGIN+27)
#define AC_DB_AP_CFGBACKUP_RSP_MSG               (EV_DB_BEGIN+28)

/* 2009-10-27 fengjing add begin */
#define AC_DB_PRDDYN_DYNPOWER_REPORT_MSG          	(EV_DB_BEGIN + 30)     /*周期性上报所有AP的卡当前功率 */
#define AC_DB_PRDDYN_MAXPOWER_REPORT_MSG          	(EV_DB_BEGIN + 31)     /* 周期性上报所有AP的卡最大功率 */
#define AC_DB_PRDDYN_VAPMAC_REPORT_MSG               	(EV_DB_BEGIN + 32)     /* 周期性上报所有AP的VAP MAC */
#define AC_DB_PRDDYN_ADHOCMAC_REPORT_MSG          	(EV_DB_BEGIN + 33)     /* 周期性上报所有AP的ADHOC MAC */
#define AC_DB_PRDDYN_APDYNIP_REPORT_MSG             		(EV_DB_BEGIN + 34)     /* 周期性上报所有AP的IP配置 */
#define AC_DB_PRDDYN_APDYNSN_REPORT_MSG            		(EV_DB_BEGIN + 35)     /* 周期性上报所有AP的SN */
#define AC_DB_PRDDYN_APDYNSWVER_REPORT_MSG      		(EV_DB_BEGIN + 36)    /* 周期性上报所有AP的当前软件版本 */
/* 2009-10-27 fengjing add end */

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
/* 探针获取关系表名和对应的属性 */
#define AC_PROBE_GETTABLES_REQ_MSG      (UINT16)(EV_DB_BEGIN + 101)
#define AC_PROBE_GETTABLES_RSP_MSG      (UINT16)(EV_DB_BEGIN + 101)
/* 探针获取选择的关系表数据内容和对应的属性 */
#define AC_PROBE_GETTUPLES_REQ_MSG      (UINT16)(EV_DB_BEGIN + 102)
#define AC_PROBE_GETTUPLES_RSP_MSG      (UINT16)(EV_DB_BEGIN + 102)
/* 探针修改前台数据请求 */
#define AC_PROBE_ACCESSRECORD_REQ_MSG   (UINT16)(EV_DB_BEGIN + 103)
#define AC_PROBE_ACCESSRECORD_RSP_MSG   (UINT16)(EV_DB_BEGIN + 103)
/* 实现探针发起的存盘功能 */
#define AC_PROBE_SAVEDATA_REQ_MSG       (UINT16)(EV_DB_BEGIN + 104)
#define AC_PROBE_SAVEDATA_RSP_MSG       (UINT16)(EV_DB_BEGIN + 104)
/* 触发各对应表项功能 */
#define AC_PROBE_NOTIFY_REQ_MSG         (UINT16)(EV_DB_BEGIN + 105)
#define AC_PROBE_NOTIFY_RSP_MSG         (UINT16)(EV_DB_BEGIN + 105)
/* 加载本地数据文件 */
#define AC_PROBE_LOADDATA_REQ_MSG       (UINT16)(EV_DB_BEGIN + 106)
#define AC_PROBE_LOADDATA_RSP_MSG       (UINT16)(EV_DB_BEGIN + 106)
/* 根据关键字检索出记录功能 */
#define AC_PROBE_GETINDEX_REQ_MSG       (UINT16)(EV_DB_BEGIN + 107)
#define AC_PROBE_GETINDEX_RSP_MSG       (UINT16)(EV_DB_BEGIN + 107)

/* END: Added by wubin, 2012/4/25   BUG:000 */

/*2011-01-06 ght add*/
/*清除关联失败AP通知消息*/
#define AC_DB_DEL_UNREGWTP_IND_MSG      		(EV_DB_BEGIN + 51)  
/*ght add end*/

/* 配置类型*/
#define AC_DB_CFG_TYPE_WHOLE        ((UINT32)1)        /* 整表配置 */
#define AC_DB_CFG_TYPE_INC          	((UINT32)2)        /* 增量配置 */

/* 配置管理状态*/
#define AC_DB_CFG_STATE_IDLE        	((UINT32)0)    /* IDLE */
#define AC_DB_CFG_STATE_WORK        ((UINT32)1)    /* WORK */
#define AC_DB_CFG_STATE_LOAD		((UINT32)2)	   /* 数据文件已加载*/
#define AC_DB_CFG_STATE_ERROR       ((UINT32)3)    /* ERROR */
#define AC_DB_CFG_STATE_LOCKED    	((UINT32)4)    /* LOCKED状态，表示AC正在将配置数据分发到各WTP */


/* 错误码定义 */
#define AC_DB_CFG_ECODE_IDLE_STATE          		((UINT32)1)    /* 配置管理当前处于IDLE 状态*/
#define AC_DB_CFG_ECODE_WORK_STATE          	((UINT32)2)    /* 配置管理当前处于WORK 状态*/
#define AC_DB_CFG_ECODE_ERROR_STATE         	((UINT32)3)    /* 配置管理当前处于ERROR 状态*/
#define AC_DB_CFG_ECODE_CFG_TYPE_INVALID    	((UINT32)4)    /* 配置类型非法*/
#define AC_DB_CFG_ECODE_TSEQNUM_INVALID     	((UINT32)5)    /* 事务号不一致*/
#define AC_DB_CFG_ECODE_FTP_FAIL            		((UINT32)6)    /* FTP 下载失败*/
#define AC_DB_CFG_ECODE_LOADFILE_FAIL       	((UINT32)7)    /* 数据文件加载失败*/
/* 2008-10-21 pyy add start */
#define AC_DB_CFG_ECODE_LOCKED_STATE       	((UINT32)8)    /* 配置管理当前处于LOCKED状态，即AC正在与AP进行配置数据同步*/
/* 2008-10-21 pyy add end */
/* 2010-1-21 新增*/
#define AC_DB_CFG_ECODE_INBAKAC				((UINT32)9)	/* 备机当前接管了一台主AC, 不允许配置*/


#define AC_DB_CFG_INVALID_VERSION		0xFFFFFFFF
/* 配置管理配置信息*/
typedef struct 
{
	UINT32	ulHeartbeatPeriod;		/*与OMC之间的 心跳周期, 单位:秒*/
} AC_DB_CMCFG_T;


/* 配置管理数据区*/
typedef struct {
    UINT32    ulState;          /* 配置管理当前状态 IDLE，WORK，ERROR */
    UINT32    ulTSeqNum;        /* 当前事务标识，空闲时为0 */
    UINT32    ulCfgType;        /* 当前配置类型，整表或增量配置 */
    UINT32	ulWCDTimerId;	/* 等待cfg download req 定时器ID */
    UINT32    ulWCRTimerId;     /* 等待commit req定时器ID */
    UINT32    ulWCCRTimerId;    /* 等待capwap cfg update rsp 定时器ID */
} AC_DB_CFG_DATA_T;

/* 结构体定义 */
typedef struct {
    UINT32    ulMsgId;      /* 消息类型 */
    UINT32    ulSerialNo;   /* 消息流水号 */
    UINT32    ulLen;        /* 消息体有效长度 */
} AC_MSG_HDR_T;

/* 配置修改请求结构体*/
typedef struct {
    UINT32    ulTSeqNum;    /* 事务号, 后续消息中都携带该事务号, 用于标识一次配置流程 */
    UINT32    ulCfgType;    /* 配置类型: 整表或增量 */
} AC_DB_CFG_REQ_MSG_T;

/* 配置修改响应结构体*/
typedef struct {
    UINT32    ulTSeqNum;    /* 事务号 */
    UINT32    ulResult;    /* 响应结果 */
    CHAR      acResultDesc[128];    /* 错误描述信息 */
} AC_DB_CFG_RSP_MSG_T;

/* 配置修改请求结构体*/
typedef struct {
    UINT32    ulTSeqNum;    /* 事务号*/
    UINT8    aucFtpSrvIp[4];    /* FTP服务器IP地址 */
    UINT32    ulFtpSrvPort;    /* FTP服务器端口号 */
    CHAR    acDirName[64];    /* 路径名*/
    CHAR    acFileName[64];    /* 数据文件名 */
    CHAR    acUserName[32];    /* 用户名 */
    CHAR    acPassword[32];    /* 密码 */
} AC_DB_CFG_DOWNLOAD_REQ_MSG_T;

/* 配置修改响应结构体*/
typedef AC_DB_CFG_RSP_MSG_T AC_DB_CFG_DOWNLOAD_RSP_MSG_T;

/* 事务提交请求结构体*/
typedef struct {
	UINT32	ulTSeqNum;	/* 事务号*/
} AC_DB_COMMIT_REQ_MSG_T;

/* 事务提交响应结构体*/
typedef AC_DB_CFG_RSP_MSG_T AC_DB_COMMIT_RSP_MSG_T;

/* 配置回滚请求结构体*/
typedef AC_DB_COMMIT_REQ_MSG_T AC_DB_ROLLBACK_REQ_MSG_T;

/* 配置数据版本号通知消息结构体*/
typedef struct {
	UINT32	ulAcId;			/* AC设备ID */
	CHAR	acSwVersion[32];	/* AC 软件版本*/
	UINT32	ulCfgVersion;	/* 配置数据文件版本号*/
	UINT32	ulOnlineTime;	/* 设备在线时间, 单位:秒 */
	UINT16  	usCfgModVer;  	/* 配置信息模型版本号 */
	UINT8    	aucRsv[2];          /* 填充字节 */
}AC_DB_CFG_VERSION_IND_MSG_T;

/* 2008-11-7 pyy add start */
/* AC重启请求消息结构体*/
typedef struct {
	UINT32    ulSeqNum;    /* 事务号*/
}AC_DB_AC_RESET_REQ_MSG_T;

/* AC重启响应消息结构体*/
typedef struct {
	UINT32    ulSeqNum;    /* 事务号*/
	UINT32    ulResult;    	/* 响应结果 */
}AC_DB_AC_RESET_RSP_MSG_T;
/* 2008-11-7 pyy add end */

#define AC_DB_CFGRESET_ECODE_WORK_STATE		((UINT32)1)	/* 当前正在进行配置数据同步, 不允许恢复缺省配置操作*/
#define AC_DB_CFGRESET_ECODE_FAIL				((UINT32)2)	/* 恢复缺省配置操作失败*/
#define AC_DB_CFGRESET_ECODE_INVALIDAP		((UINT32)3)	/* 指定AP不存在*/
#define AC_DB_CFGRESET_ECODE_INVALIDMODE	((UINT32)4)	/* 无效的恢复类型*/
#define AC_DB_CFGRESET_ECODE_INBAKAC			((UINT32)5)	/* 备机当前正接管了一台主AC */

/* 恢复AC缺省配置 */
typedef struct  
{
	UINT32    ulSn;
}AC_DB_AC_RESET_DEFAULT_CFG_REQ_MSG_T;

typedef struct  
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AC_RESET_DEFAULT_CFG_RSP_MSG_T;

/* 恢复AP缺省配置 */
#define AC_DB_AP_RESET_DEFAULT_MODE_TOTAL  		((UINT32)0)   	/* 全部恢复 */
#define AC_DB_AP_RESET_DEFAULT_MODE_PARTIAL 		((UINT32)1)   	/* 部分恢复 */

typedef struct  
{
	UINT32	ulSn;
	UINT32	ulWtpId;
	UINT32	ulMode;	/* 恢复模式	0:全部恢复 1:部分恢复*/
}AC_DB_AP_RESET_DEFAULT_CFG_REQ_MSG_T;

typedef struct  
{
	UINT32    ulSn;
	UINT32    ulRet;
	CHAR      acResultDesc[128];
}AC_DB_AP_RESET_DEFAULT_CFG_RSP_MSG_T;

/* 2009-09-09 fengjing add */

#define AC_DB_CFGUPDATE_ECODE_WORK_STATE    ((UINT32)1)	/* 当前正在进行配置数据同步, 不允许配置更新*/
#define AC_DB_CFGUPDATE_ECODE_FAIL          ((UINT32)2)	/* 配置更新操作失败*/
#define AC_DB_CFGUPDATE_ECODE_INVALIDAP		((UINT32)3)	/* 指定AP不存在*/

/* AP配置文件更新 */

typedef struct  
{
         UINT32    ulSn;
         UINT32    ulWtpId;
         CHAR      acFileName[128];      /* 配置文件路径 */
         UINT8     aucServerIp[4];         /* IP地址 */
         UINT32    ulServerPort;           /* 端口 */
         CHAR      acServerUserName[32]; /* 用户名 */
         CHAR      acServerPassword[32]; /* 密码 */
}AC_DB_AP_CFGUPDATE_REQ_MSG_T;

 
typedef struct  
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AP_CFGUPDATE_RSP_MSG_T;

#define AC_DB_CFGBACKUP_ECODE_WORK_STATE    ((UINT32)1)	/* 当前正在进行配置数据同步, 不允许配置备份*/
#define AC_DB_CFGBACKUP_ECODE_FAIL          ((UINT32)2)	/* 配置备份失败*/
#define AC_DB_CFGBACKUP_ECODE_INVALIDAP		((UINT32)3)	/* 指定AP不存在*/
/* 2010/05/26 fengjing add */
typedef struct
{
         UINT32    ulSn;
         UINT32    ulWtpId;
         CHAR      acFileName[128];      /* 配置文件路径 */
         UINT8     aucServerIp[4];         /* IP地址 */
         UINT32    ulServerPort;           /* 端口 */
         CHAR      acServerUserName[32]; /* 用户名 */
         CHAR      acServerPassword[32]; /* 密码 */
}AC_DB_AP_CFGBACKUP_REQ_MSG_T;

typedef struct
{
         UINT32    ulSn;
         UINT32    ulRet;
         CHAR      acResultDesc[128];
}AC_DB_AP_CFGBACKUP_RSP_MSG_T;

/* 2009-09-09 fengjing end */

/* OMC请求AC上报指定AP的所有动态数据*/
typedef struct  
{
	UINT32	ulWtpId;
}AC_DB_AP_DYNAINFO_REPORT_REQ_MSG_T;

/* 2010-6-28 pyy 新增: 刷新AP操作, 手动强制AC 下发AP的配置*/
typedef struct
{
	UINT32	ulSn;
	UINT32	ulWtpIdStart;
	UINT32	ulWtpIdEnd;
} AC_DB_APCFG_REFRESH_REQ_MSG_T;

typedef struct
{
	UINT32    ulSn;	
	UINT32    ulRet;	/* 0: 表示成功*/
} AC_DB_APCFG_REFRESH_RSP_MSG_T;

/*清除关联失败AP通知*/
typedef struct
{
	UINT8   	aucWtpSn[6]; 	/* AP设备序列号 */
	UINT8    	aucResv[2];		/* 填充字节 */
} AC_DB_WTPROUGAPSN_T;
#define AC_DB_CLEAR_UNREGWTP_MAX_NUM ((UINT32)100)
typedef struct
{
	UINT32	ulNum;
	AC_DB_WTPROUGAPSN_T astWtp[AC_DB_CLEAR_UNREGWTP_MAX_NUM];
} AC_DB_CLEAR_UNREGWTP_IND_T;


extern UINT32   ac_db_cm_init (VOID);
extern UINT32 	ac_db_cm_cfg_update(UINT8 *pucMsg);
extern UINT32		ac_db_cm_cfg_init(VOID);
extern UINT32   ac_db_cm_check_msg_len(UINT32 ulMsgId, UINT32 ulMsgLen);
extern VOID     ac_db_cm_cfg_req (AC_DB_CFG_REQ_MSG_T *pstCfgReq);
extern VOID	  ac_db_cm_cfg_download_req(AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstCfgDownloadReq);
extern VOID     ac_db_cm_commit_req (AC_DB_COMMIT_REQ_MSG_T *pstCommitReq);
extern UINT32   ac_db_cm_whole_table_cfg(VOID);
extern UINT32   ac_db_cm_inc_cfg(VOID);
extern UINT32		ac_db_cm_pretrigger(VOID);
extern UINT32   ac_db_cm_trigger(VOID);
extern VOID     ac_db_cm_rollback_req (AC_DB_ROLLBACK_REQ_MSG_T *pstRollbackReq);
extern VOID     ac_db_cm_recv_cfg_update_rsp(VOID);
extern VOID 	ac_db_cm_timeout_wait_cfg_download_req (VOID);
extern VOID     ac_db_cm_timeout_wait_commit_req (VOID);
extern VOID     ac_db_cm_timeout_wait_cfg_update_rsp(VOID);

extern VOID 	ac_db_cm_report_cfg_version_ind (VOID);
extern VOID ac_db_cm_report_heartbeat(VOID);
extern VOID ac_db_cm_recv_dynreport_req (VOID);
extern VOID ac_db_cm_recv_apdynreport_req(UINT8* pucMsg);
extern VOID ac_db_cm_recv_acreset_req(AC_DB_AC_RESET_REQ_MSG_T *pstResetReq);

extern VOID	ac_db_cm_ac_reset_cfg(UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_reset_cfg(UINT8 *pucMsg);
extern VOID ac_db_cm_apcfg_refresh (UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_update_cfg(UINT8 *pucMsg);
extern VOID	ac_db_cm_ap_backup_cfg(UINT8 *pucMsg);

extern VOID ac_db_cm_ap_add_cfg(UINT8 *pucMsg);
extern VOID ac_db_cm_ap_del_cfg(UINT8 *pucMsg);
extern UINT32   ac_db_cm_cfg_req_net_to_host (AC_DB_CFG_REQ_MSG_T *pstNetCfgReq,
                                              AC_DB_CFG_REQ_MSG_T *pstHostCfgReq);
extern UINT32	   ac_db_cm_cfg_download_req_net_to_host (AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstNetCfgDownloadReq,
						AC_DB_CFG_DOWNLOAD_REQ_MSG_T *pstHostCfgDownloadReq);
extern UINT32   ac_db_cm_commit_req_net_to_host (AC_DB_COMMIT_REQ_MSG_T *pstNetCommitReq,
                                                 AC_DB_COMMIT_REQ_MSG_T *pstHostCommitReq);
extern UINT32   ac_db_cm_rollback_req_net_to_host (AC_DB_ROLLBACK_REQ_MSG_T *pstNetRollbackReq,
                                                   AC_DB_ROLLBACK_REQ_MSG_T *pstHostRollbackReq);
extern UINT32   ac_db_cm_rsp_host_to_net (AC_DB_CFG_RSP_MSG_T *pstHostRsp,
                                          AC_DB_CFG_RSP_MSG_T *pstNetRsp);

UINT32 VmFsFtp(VM_FTP_REQ_MSG_T* pstFTPReqMsg, UINT32 ulDstPid);

extern VOID ac_db_cm_recv_inc_update_req(UINT8 *pucMsg, UINT32 ulByteOrder);
extern VOID ac_db_cm_recv_inc_batchupdate_req(UINT8 *pucMsg, UINT32 ulByteOrder);

extern UINT32 ac_db_cm_bakacid_chg(UINT8 *pucMsg);

extern VOID ac_db_cm_clear_unregwtp (UINT8 *pucMsg);

#endif /* _AC_DB_CM_H */
/******************************* 头文件结束 **********************************/


