/******************************************************************************
模块名      : SYSCTL
文件名      : OssSysLog.h
相关文件    :
实现功能    : 日志打印管理
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSSYSLOG_H_
#define _OSSSYSLOG_H_

#include "OssModule.h"

/* 日志级别 */
#define APP_DETAIL          (BYTE) 0
#define APP_MSG             (BYTE) 1
#define APP_WARN            (BYTE) 2
#define APP_ERROR           (BYTE) 3
#define APP_FAIL            (BYTE) 4
#define APP_FATAL           (BYTE) 5

#define APP_OFF             (BYTE) 20

/* 日志记录等级对应的字符串 */
#define STR_DETAIL      ((PCHAR)"")
#define STR_MSG         ((PCHAR)"")
#define STR_WARN        ((PCHAR)"Warn :: ")
#define STR_ERROR       ((PCHAR)"Error :: ")
#define STR_FAIL        ((PCHAR)"Fail :: ")
#define STR_FATAL       ((PCHAR)"Fatal :: ")

/* 网元名称 */
#if defined (APP_PROJ_AC)
#define STR_BOARD_NAME  (PCHAR)"AC"
#elif defined (APP_PROJ_AP)
#define STR_BOARD_NAME  (PCHAR)"AP"
#else
#define STR_BOARD_NAME  (PCHAR)"A?"
#endif


/* 日志定向 */
#define LOG_BOTH_OFF        (BYTE) 0
#define LOG_STDOUT          (BYTE) 1
#define LOG_SERVER          (BYTE) 2
#define LOG_BOTH_ON         (BYTE) 3

/* 模块日志开关 */
#define LOG_MODULE_OSS      (BYTE) 1
#define LOG_MODULE_DBS      (BYTE) 2
#define LOG_MODULE_ALL      (BYTE) 31

/* 子系统ID宏定义 */
#define SUB_SYSTEM_OSS      (BYTE) 0  /* should start from 1 */
#define SUB_SYSTEM_APP      (BYTE) 1
#define SUB_SYSTEM_ALL      (BYTE) 0XFF

/* 模块打印配置表中的有效项数(从0计数)，增减时需要调整 */
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
      BYTE    byReserve;     /* 保留 */
} TClockInfo;


typedef struct tagLogInfo
{
    TClockInfo  tClock; /* 前台生成该打印时的时间 */
    DWORD       dwSequence; /* 序列号 */
    WORD        wModuleId; /* 模块的ID号 */
    BYTE        byLevel; /* 打印级别 */
    BYTE        bySubSystemId; /* 子系统 ID 号 */
} TLogInfo;


typedef struct tagTLogSaveSwitch
{
    BYTE    byLogSaveLevel;    /* 日志前台存盘等级，控制台可调节 */
    BYTE    byReserve;
    WORD    wReserve;
    DWORD   dwMaxLogNum;       /* 日志前台存盘单位时间发送量阀值，控制台可调节 */
    DWORD   dwLogSaveFileNum;  /* 日志前台存盘使用文件最大个数，控制台可调节 */
    DWORD   dwLogSaveFileSize; /* 日志前台存盘使用文件的最大长度，控制台可调节 */
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
