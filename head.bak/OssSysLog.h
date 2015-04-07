/******************************************************************************
ģ����      : SYSCTL
�ļ���      : OssSysLog.h
����ļ�    :
ʵ�ֹ���    : ��־��ӡ����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSSYSLOG_H_
#define _OSSSYSLOG_H_

#include "OssModule.h"

/* ��־���� */
#define APP_DETAIL          (BYTE) 0
#define APP_MSG             (BYTE) 1
#define APP_WARN            (BYTE) 2
#define APP_ERROR           (BYTE) 3
#define APP_FAIL            (BYTE) 4
#define APP_FATAL           (BYTE) 5

#define APP_OFF             (BYTE) 20

/* ��־��¼�ȼ���Ӧ���ַ��� */
#define STR_DETAIL      ((PCHAR)"")
#define STR_MSG         ((PCHAR)"")
#define STR_WARN        ((PCHAR)"Warn :: ")
#define STR_ERROR       ((PCHAR)"Error :: ")
#define STR_FAIL        ((PCHAR)"Fail :: ")
#define STR_FATAL       ((PCHAR)"Fatal :: ")

/* ��Ԫ���� */
#if defined (APP_PROJ_AC)
#define STR_BOARD_NAME  (PCHAR)"AC"
#elif defined (APP_PROJ_AP)
#define STR_BOARD_NAME  (PCHAR)"AP"
#else
#define STR_BOARD_NAME  (PCHAR)"A?"
#endif


/* ��־���� */
#define LOG_BOTH_OFF        (BYTE) 0
#define LOG_STDOUT          (BYTE) 1
#define LOG_SERVER          (BYTE) 2
#define LOG_BOTH_ON         (BYTE) 3

/* ģ����־���� */
#define LOG_MODULE_OSS      (BYTE) 1
#define LOG_MODULE_DBS      (BYTE) 2
#define LOG_MODULE_ALL      (BYTE) 31

/* ��ϵͳID�궨�� */
#define SUB_SYSTEM_OSS      (BYTE) 0  /* should start from 1 */
#define SUB_SYSTEM_APP      (BYTE) 1
#define SUB_SYSTEM_ALL      (BYTE) 0XFF

/* ģ���ӡ���ñ��е���Ч����(��0����)������ʱ��Ҫ���� */
#define MODULE_MAX_NUM      40
#define MODULE_NAME_LEN     32   

#define LOG_MAX_TIMEOUT_COUNT 5

typedef struct tagClockInfo
{
      WORD    wYear;         /* >2000 */
      BYTE    byMonth;       /* 1-12 */
      BYTE    byDay;         /* 1-31 */
      BYTE    byHour;        /* 0-23 */
      BYTE    byMinute;      /* 0-59 */
      BYTE    bySecond;      /* 0-59 */
      BYTE    byReserve;     /* ���� */
} TClockInfo;


typedef struct tagLogInfo
{
    TClockInfo  tClock; /* ǰ̨���ɸô�ӡʱ��ʱ�� */
    DWORD       dwSequence; /* ���к� */
    WORD        wModuleId; /* ģ���ID�� */
    BYTE        byLevel; /* ��ӡ���� */
    BYTE        bySubSystemId; /* ��ϵͳ ID �� */
} TLogInfo;


typedef struct tagTLogSaveSwitch
{
    BYTE    byLogSaveLevel;    /* ��־ǰ̨���̵ȼ�������̨�ɵ��� */
    BYTE    byReserve;
    WORD    wReserve;
    DWORD   dwMaxLogNum;       /* ��־ǰ̨���̵�λʱ�䷢������ֵ������̨�ɵ��� */
    DWORD   dwLogSaveFileNum;  /* ��־ǰ̨����ʹ���ļ�������������̨�ɵ��� */
    DWORD   dwLogSaveFileSize; /* ��־ǰ̨����ʹ���ļ�����󳤶ȣ�����̨�ɵ��� */
} TLogSaveSwitch;


#ifdef _LINUX_
VOID    ModulePrint (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...)
            __attribute__ ((format (printf, 3, 4)));
/* trace */
#if 0
VOID    ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...)
            __attribute__ ((format (printf, 3, 4)));
#endif
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif

#ifdef _OSWIN32_
VOID    ModulePrint (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);
VOID    ModuleLogMsg (DWORD dwModuleId, BYTE byLevel, CHAR* szFormat, ...);
BOOL ModuleLogLevel (DWORD dwModuleId, BYTE byLevel);
#endif /* _OSWIN32_ */

VOID RosLogSaveSwitch(WORD16 wEvent, BYTE * lpbyIn, WORD16 wInLen, WORD16 wSenderPno);

VOID	SetLogCfg (BYTE	bySubSystemID,
					CHAR	*szModuleName,
					BYTE	byLevel);

#endif /* _OSSSYSLOG_H_ */
