/******************************************************************************
模块名      : VOS
文件名      : OssUtility.h
相关文件    :
实现功能    : 实用工具常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSUTILITY_H_
#define _OSSUTILITY_H_

/* #define _FILE_LINE_   **/
#define OSS_TIME_BASE           (WORD16)2000                /* 软时钟基准 */

/* 2009-10-23 pyy 修改AC上的队列缓存大小*/
/* 2010-1-13 pyy 按照大容量调整队列缓冲大小*/
/* 2010-3-8 放大2倍*/
#define MAX_QUEUE                (WORD32)100                /* 队列大小 */
#ifdef APP_PROJ_AC
#ifdef BIG_AC
/* 2010-11-29 pyy修改: 支持4096个AP */
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 3840 * 4)     /* 队列缓冲大小 */
#else
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 3840)     /* 队列缓冲大小 */
#endif
#else
#define MAX_QUEUE_BUFFER_SIZE    (WORD32)(1024 * 48)     /* 队列缓冲大小 */
#endif

/* 读写配置文件宏定义 */
#define VM_CONFIG_FILE_MAXLEN       64000           /* 配置文件的最大长度 */
#define VM_CONFIG_DIRNAME_LEN       20              /* 当前配置文件的目录名长度 */
#define VM_CONFIG_FILE_NAME         "Config.ini"    /* 配置文件的文件名 */
#define VM_CONFIG_FILENAME_MAXLEN   128              /* 配置文件的文件名最大长度 */
#define VM_CONFIG_SECNAME_MAXLEN    32              /* 配置模块名的最大个数 */
#define VM_CONFIG_SECNODE_MAXNUM    32              /* 配置模块的最大个数 */
#define VM_CONFIG_VARNAME_MAXLEN    32              /* 变量名的最大长度 */
#if 0	/* mod by gwx 2014-4-2 for bug5236 */
#define VM_CONFIG_VARNODE_MAXNUM    64              /* 一个模块中的变量最大个数 */
#else
#define VM_CONFIG_VARNODE_MAXNUM    128              /* 一个模块中的变量最大个数 */
#endif
#define VM_CONFIG_VARVALUE_MAXLEN   32              /* 一个整数变量的最大长度 */
#define VM_CONFIG_ADDELEMENT_MAXLEN 60              /* 一项的最大长度 */

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

/* 队列控制块结构 */
typedef struct
{
    OSTOKEN     tCountSem;      /* 该队列计数信号量 */
    OSTOKEN     tMuxSem;        /* 该队列互斥信号量 */
    BYTE        byUsed;         /* 使用标志 */
    WORD32      dwEntry;        /* 队列缓冲地址 */
    WORD32      dwSize;         /* 队列最大值 */
    WORD32      dwHead;         /* 头指针 */
    WORD32      dwTail;         /* 尾指针 */
    WORD32      dwCount;        /* 队列值 */
}TQControlBlock;

typedef struct
{
    BOOL            bInit;                              /* 初始化标志 */
    OSTOKEN         tSemaphore;                         /* 信号量 */
    WORD32          dwFreePtr;                          /* 缓冲区空闲指针 */
    TQControlBlock  atCtrBlock[MAX_QUEUE];              /* 单队列控制数组 */
    BYTE            abyBuffer[MAX_QUEUE_BUFFER_SIZE];   /* 缓冲区 */
}TQueueStruc;

/* 读写配置文件结构定义 */
/* 配置参数数据结构 */
typedef struct TagConfigVar{
    CHAR                achVarName[VM_CONFIG_VARNAME_MAXLEN];
    BYTE                abyVarValue[VM_CONFIG_VARVALUE_MAXLEN];
    BYTE                byVarLen;
}TConfigVar;

/* 配置段数据结构 */
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
BOOL        UtilInit (VOID); /* Util 初始化 */
INT         GetBaseDiff (INT iYearA, INT iYearB);

/* 以下是提供给用户的接口 */
/* 从配置文件中读取数字参数 */
BOOL GetConfigIntParam      (LPTSTR strSec, LPTSTR strParam, DWORD *pdwOutNum);
BOOL GetConfigIntParamEx    (LPTSTR strSec, LPTSTR strParam, DWORD dwDefaultValue, DWORD *pdwOutNum);

/* 从配置文件中读取字符串参数 */
BOOL GetConfigStrParam      (LPTSTR strSec, LPTSTR strParam, LPTSTR strOutParam);
BOOL GetConfigStrParamEx    (LPTSTR strSec, LPTSTR strParam, LPSTR strDefaultValue, LPTSTR strOutParam);

BOOL ConfigfileInit         (VOID);

/* 在配置文件中配置数字参数 */
BOOL SetConfigIntParam      (LPTSTR strFile, 
                             LPTSTR strSec, 
                             LPTSTR strParam, 
                             DWORD dwInNum, 
                             BYTE byRadix
                            );
/* 在配置文件中配置字符串参数 */
BOOL SetConfigStrParam      (LPTSTR strFile, 
                             LPTSTR strSec, 
                             LPTSTR strParam, 
                             LPTSTR strValue
                            );
/* 读取配置文件 */
BOOL ReadProfileFile        (LPTSTR strFile);
BOOL SetGlobalCfg           (BYTE *pbyGlobalCfg,  WORD32 wCfgLen);
BYTE *GetGlobalCfg          (WORD32 *pwCfgLen);


BOOL VmUnzip(CHAR *szZipFile, CHAR *szUnzipDir);

#endif /* _OSSUTILITY_H_ */
