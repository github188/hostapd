/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: WTP CAPWAP���ӹ���ͷ�ļ�
* �޸���ʷ: 
* 2008-12-2     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_CW_MS_H
#define  _AC_CW_MS_H
/* ��ʱ����غ궨��*/
#define AC_CW_MS_TIMERID_CFG_REQ			TIMER1			/* �ӻ��ϵ����������������������Ϣ��ʱ��*/
#define AC_CW_MS_TIMERID_WAIT_CFG_RSP	TIMER2			/* �ȴ�����������Ӧ��ʱ��*/
#define AC_CW_MS_TIMERID_SEND_VAPSTAT	TIMER3			/* �ӻ�����������������VAP����ͳ����Ϣ*/
#define AC_CW_MS_TIMERID_SEND_HELLO		TIMER4			/* ��������������������HELLO */
#define AC_CW_MS_TIMERID_GET_DYNINFO	TIMER5

#define AC_CW_MS_TIMEOUT_CFG_REQ			EV_TIMER1
#define AC_CW_MS_TIMEOUT_WAIT_CFG_RSP	EV_TIMER2
#define AC_CW_MS_TIMEOUT_SEND_VAPSTAT	EV_TIMER3
#define AC_CW_MS_TIMEOUT_SEND_HELLO		EV_TIMER4
#define AC_CW_MS_TIMEOUT_GET_DYNINFO	EV_TIMER5

#define AC_CW_MS_TIMERLEN_CFG_REQ		30
#define AC_CW_MS_TIMERLEN_WAIT_CFG_RSP	30
#define AC_CW_MS_TIMERLEN_SEND_VAPSTAT	5400		/* 9����*/
#define AC_CW_MS_TIMERLEN_SEND_HELLO	30
#define AC_CW_MS_TIMERLEN_GET_DYNINFO	300			/* 30��*/

/* ��Ϣ�Ŷ���*/
#define AC_CW_MS_CFG_REQ_MSG				(EV_CW_BEGIN+200)		/* ����������Ϣ: �ӻ���������*/
#define AC_CW_MS_CFG_RSP_MSG				(EV_CW_BEGIN+201)		/* ������Ӧ��Ϣ: ���������ӻ�*/
#define AC_CW_MS_CFG_UPDATE_IND_MSG		(EV_CW_BEGIN+202)		/* ���ø���ָʾ��Ϣ: ���������ӻ�*/
#define AC_CW_MS_STATE_UPDATE_IND_MSG	(EV_CW_BEGIN+203)		/* ״̬����ָʾ��Ϣ: �ӻ���������*/
#define AC_CW_MS_HELLO_MSG				(EV_CW_BEGIN+204)		/* HELLO����: ���������ӻ�*/

/* ����״̬�궨��*/
#define AC_CW_MS_CFG_STATE_INIT		0	/* ��ʼ״̬*/
#define AC_CW_MS_CFG_STATE_WORK		1	/* ��������ͬ����*/
#define AC_CW_MS_CFG_STATE_FIN		2	/* ����ͬ������*/


typedef struct 
{
	UINT32	ulCfgFailNum;		
	UINT32	ulCfgState;			/* ����״̬*/
	UINT32	ulNeedCfgFlag;		/* ��Ҫ�ٴη�������������*/
	UINT32	ulMsSeqNum;		/* ���к�*/
	UINT32	ulTimerIdCfgReq;	
	UINT32	ulTimerIdWaitCfgRsp;
	UINT32	ulTblNum;			/* ��Ҫ���Ӽ�ͬ���Ĺ�ϵ����Ŀ*/
	DBHANDLE    ahTblList[64];		/* ��Ҫ���Ӽ�ͬ���Ĺ�ϵ����*/
} AC_CW_MS_INFO_T;

/* ��Ϣ�ṹ�嶨��*/
/* ����������Ϣ�ṹ��*/
typedef struct 
{
	UINT32	ulSeqNum;
} AC_CW_MS_CFG_REQ_T;

/* ������Ӧ��Ϣ�ṹ��*/
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
    	CHAR    	acTblName[AC_DB_TBL_NAME_LEN_MAX];    	/* ��ϵ���� */
    	UINT16	usRecordLen;                            			/* ��¼��Ч���� */
    	UINT8    	aucRsv[2];                                			/* ����ֽ� */
    	UINT32	ulRecordNum;                            			/* ��¼�� */
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
/******************************* ͷ�ļ����� **********************************/

