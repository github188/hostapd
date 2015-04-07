/******************************************************************************
ģ����      : VOS
�ļ���      : OssUtility.h
����ļ�    :
ʵ�ֹ���    : ʵ�ù��߳���,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSUTILITY_H_
#define _OSSUTILITY_H_

/* #define _FILE_LINE_   **/
#define OSS_TIME_BASE           (WORD16)2000                /* ��ʱ�ӻ�׼ */

/* 2009-10-23 pyy �޸�AC�ϵĶ��л����С*/
/* 2010-1-13 pyy ���մ������������л����С*/
/* 2010-3-8 �Ŵ�2��*/
#define MAX_QUEUE                (WORD32)100                /* ���д�С */
#ifdef APP_PROJ_AC
#ifdef BIG_AC
/* 2010-11-29 pyy�޸�: ֧��4096��AP */
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 3840 * 4)     /* ���л����С */
#else
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 3840)     /* ���л����С */
#endif
#else
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 48)     /* ���л����С */
#endif

/* ��д�����ļ��궨�� */
#define VM_CONFIG_FILE_MAXLEN       64000           /* �����ļ�����󳤶� */
#define VM_CONFIG_DIRNAME_LEN       20              /* ��ǰ�����ļ���Ŀ¼������ */
#define VM_CONFIG_FILE_NAME         "Config.ini"    /* �����ļ����ļ��� */
#define VM_CONFIG_FILENAME_MAXLEN   128              /* �����ļ����ļ�����󳤶� */
#define VM_CONFIG_SECNAME_MAXLEN    32              /* ����ģ������������ */
#define VM_CONFIG_SECNODE_MAXNUM    32              /* ����ģ��������� */
#define VM_CONFIG_VARNAME_MAXLEN    32              /* ����������󳤶� */
#if 0	/* mod by gwx 2014-4-2 for bug5236 */
#define VM_CONFIG_VARNODE_MAXNUM    64              /* һ��ģ���еı��������� */
#else
#define VM_CONFIG_VARNODE_MAXNUM    128              /* һ��ģ���еı��������� */
#endif
#define VM_CONFIG_VARVALUE_MAXLEN   32              /* һ��������������󳤶� */
#define VM_CONFIG_ADDELEMENT_MAXLEN 60              /* һ�����󳤶� */

#define _FILE_LINE_(dwModuleId, byLevel) ModulePrint(dwModuleId, byLevel, \
                                                     "%s, %d", __FILE__, __LINE__)

typedef WORD32      TQHandle;
typedef WORD32*     TQEntry;
typedef TQEntry*    LPTQEntry;

#pragma pack(1)
typedef struct
{
    BYTE    bySecond;      /* 0-59 */
    BYTE    byMinute;      /* 0-59 */
    BYTE    byHour;        /* 0-23 */
    BYTE    byDay;         /* 1-31 */
    BYTE    byMonth;       /* 1-12 */
    WORD16  wYear;         /* 2000-2099 */
    BYTE    byWeek;        /* 1-7 */
    BYTE    byCount10ms;   /* 0-99 */
} TClockStruc;
#pragma pack()

/* ���п��ƿ�ṹ */
typedef struct
{
    OSTOKEN     tCountSem;      /* �ö��м����ź��� */
    OSTOKEN     tMuxSem;        /* �ö��л����ź��� */
    BYTE        byUsed;         /* ʹ�ñ�־ */
    WORD32      dwEntry;        /* ���л����ַ */
    WORD32      dwSize;         /* �������ֵ */
    WORD32      dwHead;         /* ͷָ�� */
    WORD32      dwTail;         /* βָ�� */
    WORD32      dwCount;        /* ����ֵ */
}TQControlBlock;

typedef struct
{
    BOOL            bInit;                              /* ��ʼ����־ */
    OSTOKEN         tSemaphore;                         /* �ź��� */
    WORD32          dwFreePtr;                          /* ����������ָ�� */
    TQControlBlock  atCtrBlock[MAX_QUEUE];              /* �����п������� */
    BYTE            abyBuffer[MAX_QUEUE_BUFFER_SIZE];   /* ������ */
}TQueueStruc;

/* ��д�����ļ��ṹ���� */
/* ���ò������ݽṹ */
typedef struct TagConfigVar{
    CHAR                achVarName[VM_CONFIG_VARNAME_MAXLEN];
    BYTE                abyVarValue[VM_CONFIG_VARVALUE_MAXLEN];
    BYTE                byVarLen;
}TConfigVar;

/* ���ö����ݽṹ */
typedef struct TagConfigSection{
    CHAR        achSecName[VM_CONFIG_SECNAME_MAXLEN];
    TConfigVar  atConfigVar[VM_CONFIG_VARNODE_MAXNUM];
    BYTE        byVarNodeIndex;
}TConfigSection;


TQHandle    CreateQueue (WORD32, BOOL, BOOL);
BOOL        AppendQueue (TQHandle, TQEntry, DWORD dwTimeout);
BOOL        ServeQueue (TQHandle, WORD32, LPTQEntry);
WORD32      QueueSize (TQHandle);

VOID        NextDay (TClockStruc*);
VOID        ClockToTime (TClockStruc*, WORD32*);
VOID        TimeToClock (WORD32*, TClockStruc*);
BOOL        UtilInit (VOID); /* Util ��ʼ�� */
INT         GetBaseDiff (INT iYearA, INT iYearB);

/* �������ṩ���û��Ľӿ� */
/* �������ļ��ж�ȡ���ֲ��� */
BOOL GetConfigIntParam      (LPTSTR strSec, LPTSTR strParam, DWORD *pdwOutNum);
BOOL GetConfigIntParamEx    (LPTSTR strSec, LPTSTR strParam, DWORD dwDefaultValue, DWORD *pdwOutNum);

/* �������ļ��ж�ȡ�ַ������� */
BOOL GetConfigStrParam      (LPTSTR strSec, LPTSTR strParam, LPTSTR strOutParam);
BOOL GetConfigStrParamEx    (LPTSTR strSec, LPTSTR strParam, LPSTR strDefaultValue, LPTSTR strOutParam);

BOOL ConfigfileInit         (VOID);

/* �������ļ����������ֲ��� */
BOOL SetConfigIntParam      (LPTSTR strFile, 
                             LPTSTR strSec, 
                             LPTSTR strParam, 
                             DWORD dwInNum, 
                             BYTE byRadix
                            );
/* �������ļ��������ַ������� */
BOOL SetConfigStrParam      (LPTSTR strFile, 
                             LPTSTR strSec, 
                             LPTSTR strParam, 
                             LPTSTR strValue
                            );
/* ��ȡ�����ļ� */
BOOL ReadProfileFile        (LPTSTR strFile);
BOOL SetGlobalCfg           (BYTE *pbyGlobalCfg,  WORD32 wCfgLen);
BYTE *GetGlobalCfg          (WORD32 *pwCfgLen);


BOOL VmUnzip(CHAR *szZipFile, CHAR *szUnzipDir);

#endif /* _OSSUTILITY_H_ */
