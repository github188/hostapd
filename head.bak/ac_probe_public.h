/******************************************************************************

                  ��Ȩ���� (C), 2008-2012, �Ϻ�徴�ͨ�ſƼ����޹�˾

 ******************************************************************************
  �� �� ��   : ac_probe_public.h
  �� �� ��   : ����
  ��    ��   : wubin
  ��������   : 2012��4��25�� ������
  ����޸�   :
  ��������   : ac_probe_proc.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��4��25�� ������
    ��    ��   : wubin
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __AC_PROBE_PUBLIC_H__
#define __AC_PROBE_PUBLIC_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include "ac_db_kernel.h"
#include "ac_public.h"
/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/
#if defined (_LINUX_) 	
extern TPID    gtDbCtrlProc;
extern TPID    gtDbCmPid;
extern TPID    gtAcCwPid;
extern TPID    gtWtpCwPid;
extern TPID    gtComPid;
extern TPID    gtHostapdPid;
extern TPID    gtOamPid;
extern TPID    gtAcmPid;
//extern TPID		gtSmPid;
extern TPID		gtRrmPid;
extern TPID		gtPortalPid;
extern TPID		gtWapiPid;
extern TPID		gtSysmPid;
extern TPID		gtUsrmPid;
extern TPID		gtApOmaPid;
extern TPID		gtOssMsPid;
extern TPID		gtLicensePid;
#endif
/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/
#define APP_MODULE_PROBE APP_MODULE_DB

#define AC_CLIENT_PORT			(WORD16)(7867)      /* ���Ͷ˿ں� */
#define AC_SERVER_PORT			(WORD16)(7866)      /* �����˿ں� */


/* ��̽�뽻������Ϣͷ����*/
typedef struct 
{
        UINT16  usMsgId;
        UINT16	usMsgLen;
        UINT32  ulSequence;
}AC_PROBE_MSG_HEAD_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT8    ucMasterOrSlave ;
        UINT8    aucRsv[3];
}AC_PROBE_GETTABLES_REQ_MSG_T;

/* �ļ�ͷ�ṹ */
typedef struct
{
        UINT32  ulVersion;  /* �����ļ��汾�� */
        UINT16  usTblNum;   /* ϵͳ��ǰ��ϵ�����ʵ������ */
        UINT16	usCfgModVer;  	/* ������Ϣģ�Ͱ汾�� */
        UINT16	usStaticTblNum;/* ϵͳ��ǰ��̬��ϵ�����ʵ������*/
        UINT16  usIdxNum;   /* ϵͳ��ǰ��������ʵ������ */
        UINT16  usSqueNum;    /* ϵͳ��ǰ������ж���ʵ������ */
        UINT16  usPathNo;   	/* ·���� */
} AC_PROBE_FILE_HEADER_T;

typedef struct{
        DBHANDLE  hTbl;
        CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];	/* ��ϵ���� */
        UINT8   ucTblType;         	/* ��ϵ������ */
        UINT8   aucRsv[3];
}AC_PROBE_TABLE_TYPE;

typedef struct{
        AC_PROBE_MSG_HEAD_T stHead;
        AC_PROBE_FILE_HEADER_T stFileHeader;
        AC_PROBE_TABLE_TYPE astTables[AC_DB_TBL_NUM_MAX];
} AC_PROBE_GETTABLES_RSP_MSG_T;

/* ��ȡָ����ϵ������м�¼ */
typedef struct
{
        AC_PROBE_MSG_HEAD_T     stHead;
        CHAR acTblName[AC_DB_TBL_NAME_LEN_MAX];
        DBHANDLE        hTbl;
        UINT32  ulBeginTuple;
        UINT32  ulTupleNum;
        UINT8   ucMasterOrSlave;
        UINT8   aucRsv[3];
}AC_PROBE_GETTUPLES_REQ_MSG_T;

#if 0
/* �ֶνṹ�� */
typedef struct
{
        CHAR acFieldName[AC_DB_FIELD_NAME_LEN_MAX];/* �ֶ��� */
        UINT16  usFieldLen;   /* �ֶγ��� */
        UINT16  usFieldOffset;  /* �ֶ�ƫ���� */
        UINT8   ucFieldType;  /* �ֶ����� */
        UINT8   ucFieldTag;    /* �Ƿ�Ϊ�ؼ��� */
        UINT8   ucSave;        /* �Ƿ������ */
        UINT8   aucRsv[1];        /* ����ֽ� */
}AC_PROBE_FIELD_T;
#endif

/* AC_DB_WORK_BUFF_LEN_MAX������������С 256kbyte */
#define AC_PROBE_WORK_BUFF_LEN_MAX     ((UINT32)AC_DB_PACKET_MAX_LEN_NET)  

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
    	UINT32	ulRet;		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    	UINT32	ulFinish;		/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
    							AC_DB_TABLE_READ_NOTFINISH	δ����
    							AC_DB_TABLE_READ_FINISH		��ȡ���� */
        CHAR acTblName[AC_DB_TBL_NAME_LEN_MAX];
        DBHANDLE  hTbl; /* ��ϵ���� */
        DBHANDLE ahIdx[AC_DB_TBL_IDX_NUM_MAX]; /* ��ϵ����������б� */
        UINT32  ulCapacity; /* ��ϵ������ */
        UINT32  ulBeginRecord;
        UINT32  ulEndRecord;
        UINT32  ulRecordNum;
        UINT16  usFieldNum;  /* �ֶ��� */
        UINT16  usRecordLen;/* ��¼���(4byte) + ��¼����Ч�ֶγ��� */
        AC_DB_FIELD_T   astField[AC_DB_TBL_FIELD_NUM_MAX];
        UINT8   aucBuff[AC_PROBE_WORK_BUFF_LEN_MAX];
        DBHANDLE        ahSque[2]; /* ������о��, ����������ڹ����ϵ����м�¼ ��2���Ǿ�̬������*/
        UINT8   ucMainSlaveAddr;     	/* �ڴ�ָʾ */
        UINT8   ucTag;			/* ��ϵ���Ǵ���ʹ��*/
        UINT8   aucRsv[2];
}AC_PROBE_GETTUPLES_RSP_MSG_T;

/* �޸ı��¼ */
typedef struct
{
        AC_PROBE_MSG_HEAD_T  stHead;
        CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];
        UINT32	ulIncType;	/* �����������ͣ�
						0 ������
						1��ɾ��
						2���޸�
						*/
        UINT8   aucRecord[AC_DB_PACKET_MAX_LEN_NET];	/* ��¼���� */
} AC_PROBE_ACCESSRECORD_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
	UINT32	ulRet;	/*����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	CHAR    acResultDesc[128];    /* ����������Ϣ */
} AC_PROBE_ACCESSRECORD_RSP_MSG_T;

/* ����ac.dat */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_SAVEDATA_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32	ulRet;/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_PROBE_SAVEDATA_RSP_MSG_T;

/* ֪ͨ������ */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_NOTIFY_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32  ulRet;/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_PROBE_NOTIFY_RSP_MSG_T;

/* ����ac.dat */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_LOADDATA_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32	ulRet;/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_PROBE_LOADDATA_RSP_MSG_T;

/* ����������ȡ���¼ */
typedef struct{
        AC_PROBE_MSG_HEAD_T     stHead;
        UINT8   ucMainSlaveAddr;     	/* ����or�����ڴ�ָʾ */
        UINT8   aucRsv[3];
        UINT32  ulCmpLen;
        UINT8   aucKey[AC_DB_IDX_LEN_MAX];
        DBHANDLE    hIdx;       /* ������� */
        DBHANDLE    hTbl;       /* ���������Ĺ�ϵ���� */
        UINT32 ulBeginTupleNo;/* ��Ψһ������ʼ�۲��¼�� */
        UINT32 ulBeginIdxItemNo;/*��ʼ�۲���������,����˳������ */
        UINT32 ulTupleNum;/* ��Ψһ�����ѹ۲��¼�� */
} AC_PROBE_GETINDEX_REQ_MSG_T;

AC_PROBE_GETTUPLES_RSP_MSG_T    AC_PROBE_GETINDEX_RSP_MSG_T;








#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __AC_PROBE_PUBLIC_H__ */
