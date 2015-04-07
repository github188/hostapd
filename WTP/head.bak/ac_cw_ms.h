/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: WTP CAPWAP主从功能头文件
* 修改历史: 
* 2008-12-2     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_MS_H
#define  _AC_CW_MS_H
/* 定时器相关宏定义*/
#define AC_CW_MS_TIMERID_CFG_REQ			TIMER1			/* 从机上电后请求向主机请求配置信息定时器*/
#define AC_CW_MS_TIMERID_WAIT_CFG_RSP	TIMER2			/* 等待主机配置响应定时器*/
#define AC_CW_MS_TIMERID_SEND_VAPSTAT	TIMER3			/* 从机周期性向主机发送VAP流量统计信息*/
#define AC_CW_MS_TIMERID_SEND_HELLO		TIMER4			/* 主机周期性向主机发送HELLO */
#define AC_CW_MS_TIMERID_GET_DYNINFO	TIMER5

#define AC_CW_MS_TIMEOUT_CFG_REQ			EV_TIMER1
#define AC_CW_MS_TIMEOUT_WAIT_CFG_RSP	EV_TIMER2
#define AC_CW_MS_TIMEOUT_SEND_VAPSTAT	EV_TIMER3
#define AC_CW_MS_TIMEOUT_SEND_HELLO		EV_TIMER4
#define AC_CW_MS_TIMEOUT_GET_DYNINFO	EV_TIMER5

#define AC_CW_MS_TIMERLEN_CFG_REQ		30
#define AC_CW_MS_TIMERLEN_WAIT_CFG_RSP	30
#define AC_CW_MS_TIMERLEN_SEND_VAPSTAT	5400		/* 9分钟*/
#define AC_CW_MS_TIMERLEN_SEND_HELLO	30
#define AC_CW_MS_TIMERLEN_GET_DYNINFO	300			/* 30秒*/

/* 消息号定义*/
#define AC_CW_MS_CFG_REQ_MSG				(EV_CW_BEGIN+200)		/* 配置请求消息: 从机发往主机*/
#define AC_CW_MS_CFG_RSP_MSG				(EV_CW_BEGIN+201)		/* 配置响应消息: 主机发往从机*/
#define AC_CW_MS_CFG_UPDATE_IND_MSG		(EV_CW_BEGIN+202)		/* 配置更新指示消息: 主机发往从机*/
#define AC_CW_MS_STATE_UPDATE_IND_MSG	(EV_CW_BEGIN+203)		/* 状态更新指示消息: 从机发往主机*/
#define AC_CW_MS_HELLO_MSG				(EV_CW_BEGIN+204)		/* HELLO报文: 主机发往从机*/

/* 配置状态宏定义*/
#define AC_CW_MS_CFG_STATE_INIT		0	/* 初始状态*/
#define AC_CW_MS_CFG_STATE_WORK		1	/* 正在配置同步中*/
#define AC_CW_MS_CFG_STATE_FIN		2	/* 配置同步结束*/


typedef struct 
{
	UINT32	ulCfgFailNum;		
	UINT32	ulCfgState;			/* 配置状态*/
	UINT32	ulNeedCfgFlag;		/* 需要再次发起配置请求标记*/
	UINT32	ulMsSeqNum;		/* 序列号*/
	UINT32	ulTimerIdCfgReq;	
	UINT32	ulTimerIdWaitCfgRsp;
	UINT32	ulTblNum;			/* 需要主从间同步的关系表数目*/
	DBHANDLE    ahTblList[64];		/* 需要主从间同步的关系表句柄*/
} AC_CW_MS_INFO_T;

/* 消息结构体定义*/
/* 配置请求消息结构体*/
typedef struct 
{
	UINT32	ulSeqNum;
} AC_CW_MS_CFG_REQ_T;

/* 配置响应消息结构体*/
typedef struct
{
	UINT32	ulSeqNum;	
	UINT32	ulDataLen;
	UINT8	*pucData;
} AC_CW_MS_CFG_RSP_T;

typedef struct {
	UINT16    usTblNum;
    	UINT8    aucRsv[2];
}  AC_CW_MS_CFG_FILE_HEADER_T;

typedef struct {
    	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];    	/* 关系表名 */
    	UINT16	usRecordLen;                            			/* 记录有效长度 */
    	UINT8    	aucRsv[2];                                			/* 填充字节 */
    	UINT32	ulRecordNum;                            			/* 记录数 */
} AC_CW_MS_CFG_TBL_HEADER_T;

typedef struct {
	UINT32	ulDynSynNo;
	UINT32	ulLen;
	UINT8	*pucData;
} AC_CW_MS_STATE_UPDATE_IND_T;

typedef struct {
	UINT32	ulAcLinkState;
} AC_CW_MS_HELLO_MSG_T;
 
extern UINT32 	ac_cw_ms_init (VOID);
extern UINT32 	ac_cw_ms_power_on (VOID);
extern UINT32	ac_cw_ms_get_fileheader(AC_CW_MS_CFG_FILE_HEADER_T *pstFileHeader);
extern UINT32	ac_cw_ms_get_tblheader(DBHANDLE hTbl, AC_CW_MS_CFG_TBL_HEADER_T *pstTblHeader);
extern UINT32	ac_cw_ms_coder_fileheader (AC_CW_MS_CFG_FILE_HEADER_T *pstFileHeader,
										AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_coder_tblheader (AC_CW_MS_CFG_TBL_HEADER_T *pstTblHeader,
										AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_coder_tblrec (DBHANDLE	hTbl,
									AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_decoder_fileheader (AC_CW_MS_CFG_FILE_HEADER_T *pstFileHeader,
										     AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_decoder_tblheader (AC_CW_MS_CFG_TBL_HEADER_T *pstTblHeader,
										    AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_decoder_tblrec (AC_CW_MS_CFG_TBL_HEADER_T *pstTblHeader,
										AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_coder_cfg (AC_CW_MS_CFG_RSP_T *pstRsp);
extern UINT32	ac_cw_ms_decoder_cfg (AC_CW_MS_CFG_RSP_T	*pstRsp);
extern VOID	ac_cw_ms_mate_online(VOID);
extern VOID	ac_cw_ms_mate_offline(VOID);
extern UINT32	ac_cw_ms_send_cfgreq(VOID);
extern VOID	ac_cw_ms_recv_wtpcfgupdateind(VOID);
extern VOID	ac_cw_ms_recv_cfgreq(UINT8 *pbyMsg);
extern VOID	ac_cw_ms_recv_cfgrsp(UINT8 *pbyMsg);
extern VOID	ac_cw_ms_recv_mscfgupdateind(VOID);
extern VOID	ac_cw_ms_recv_hello(UINT8 *pucMsg);
extern VOID	ac_cw_ms_timeout_cfgreq(VOID);
extern VOID	ac_cw_ms_timeout_waitcfgrsp(VOID);
extern VOID	ac_cw_ms_timeout_sendvapstat(VOID);
extern VOID	ac_cw_ms_timeout_sendhello(VOID);
extern VOID	ac_cw_ms_timeout_getdyninfo(VOID);
extern UINT32	ac_cw_ms_coder_vapbssid(AC_CW_MS_STATE_UPDATE_IND_T *pstMsg);
extern UINT32	ac_cw_ms_coder_vaptrafficstat(AC_CW_MS_STATE_UPDATE_IND_T *pstMsg);
extern VOID	ac_cw_ms_send_stateupdateind(UINT32 ulDynSynNo);
extern VOID	ac_cw_ms_recv_stateupdateind(UINT8 *pbyMsg);
extern UINT32	ac_cw_ms_get_vapbssid(VOID);
extern VOID	ac_cw_ms_trigger(VOID);

#endif /* _AC_CW_MS_H */
/******************************* 头文件结束 **********************************/

