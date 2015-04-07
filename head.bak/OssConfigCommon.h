/******************************************************************************
ģ����      : SYSCFG
�ļ���      : OssConfigCommon.h
����ļ�    :
ʵ�ֹ���    : ���й��̵�ϵͳ����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSCONFIGCOMMON_H_
#define _OSSCONFIGCOMMON_H_

/*------------------------------------------------------------*/
/* ���ȹ��� */
#define MAX_ISR_FUNC_NUM        (BYTE) 10       /* ϵͳ����ʱ�� ISR �ص����������� */
#define MAX_REALTIME_TASK_NUM   (BYTE) 10       /* ʵʱ���������� */

#define PROC_NUM_OSS            (WORD16) 10     /* OSS ������Ŀ */
#define PROC_NUM_APP            (WORD16) 30     /* APP ������Ŀ */


/* IPC ���� */
#ifdef BIG_AC
#define OSS_CPU_NUM             (WORD16) (1050*4)
#else
#define OSS_CPU_NUM             (WORD16) 1050
#endif
#define MSG_QNODE_SIZE          (WORD16) 4      /* ��Ϣ���� */


/* �ڴ���� */
#define UB_SPAN                 (WORD16) 64     /* UB_POOL��Ĵ�С */
#define VMMM_POOL_NUM           (WORD16) 18     /* UB_POOL�Ĵ�С */    

#ifdef APP_PROJ_AC
//#ifdef BIG_AC
/* 2010-12-1 pyy ֧��4096 ap �޸� */
//#define TMCB_NUM                (WORD16) (2000*10)  /* ��ʱ����Ŀ */
//#else
#define TMCB_NUM                (WORD16) 20000  /* ��ʱ����Ŀ */
//#endif
#else
#define TMCB_NUM                (WORD16) 2000  /* ��ʱ����Ŀ */
#endif

/*-------------------------------------------------------------*/
typedef struct  TagPAT
{
    BYTE            byUse;                      /* ʹ�ñ�־ */
    BYTE            abyPName[PROC_NAME_LENGTH]; /* ������ */
    BYTE            byTno;                      /* ����� */
    ProcEntryProto  lptEntry;                   /* ������� */
    WORD16          wProcDataSize;              /* �������ݴ�С */
    WORD32          dwStackSize;                /* ˽��ջ��С */
	ProcInitProto	lptDataAreaInit;            /* ������������ʼ������ */
}TPATStruc;

typedef struct{
    BYTE    byInUse;
    CHAR    lpName[PROC_NAME_LENGTH];
    WORD32    wTimeout;
    BYTE    byOption;
} TBaseProcStruct;

typedef struct{
    BYTE    byInUse;
    CHAR    lpName[PROC_NAME_LENGTH];
} TLastProcStruct;

/* ������ʱ����ص����� */
typedef struct
{
    RtProcProto     tAuxtimeTask;               /* ʱ�Ӽ����� */
    WORD16          wTimeSpan;                  /* ʱ��(10msΪ��λ) */
}TRealtimeTaskTable;

/* UB��С���� */
typedef struct
{
    WORD32          dwSize;                     /* ��С */
    WORD32          wTotal;                     /* ���� */
}TUBSizeStruc;


/*-------------------------------------------------------------*/

extern  TPATStruc           atPAT_OSS[];
extern  TPATStruc           atPAT_APP[];
extern  TPATStruc           atPAT[];
extern  TTcbTable           aTaskTable[];

extern  TUBSizeStruc        atUBSize[];
extern  TUBSizeStruc        atOldUBSize[];
extern  TUBSizeStruc        atNewUBSize[];
extern  WORD16              awReservePool[];

extern  TRealtimeTaskTable  atRealtimeTaskTable[];
extern  TBaseProcStruct     atBaseProcTab[];
extern  TLastProcStruct     atLastProcTab[];
extern  TAddrMapTable       atAddrMapTable[];

extern  BOOL                gbGetAddrTableFromDbs;

extern  WORD                gwAcId;
extern  WORD                gwApId;

extern  CHAR                * gstrLogSvrAddr;
extern  WORD16              gwLogSvrPort;

extern  TIPAddr             gtCnIpAddr;

extern  TIPAddr             gtNodeBIpAddr;
extern  WORD16              gwNodeBUdpPort;
extern  CHAR                * gszNbMsgRecvProc;

#endif /* _OSSCONFIGCOMMON_H_ */
