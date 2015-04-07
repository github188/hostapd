#ifndef OMA_DEF_H
#define OMA_DEF_H

#include <time.h>

/**************************** ϵͳ���� ****************************/
/* OMA��ǰ�Ƿ�Ϊ����ģʽ */
#define OMA_TEST_MODE   0

/* OMA��ǰ�Ƿ�ΪWINDOW�����л������� */
#define OMA_TEST_WIN    0

/**************************** ���Ͷ��� ****************************/
typedef unsigned long OID;

/* OMAͨ�ú����������� */
typedef enum
{
	OMA_FAILED = -1,
	OMA_SUCCESS = 0
}OMA_RET_E;

/**************************** ��ʼ�����ֽ���ת�� ****************************/

#define INIT_0(a)       memset(&a, 0, sizeof(a))
#define INIT_FF(a)      memset(&a, 0xff, sizeof(a))

#define OMA_FREE(mem) \
{\
    if ((mem) != NULL)\
    {\
        free(mem);\
        (mem) = NULL;\
    }\
}

#define SET_PINT(a, b)   *((unsigned long *)(a)) = (b)

/**************************** �ֽ���ת�� ****************************/
#ifndef HTONS
#define HTONS(a)        htons((a))
#endif
#ifndef HTONS_IT
#define HTONS_IT(a)     (a) = HTONS((a))
#endif
#ifndef NTOHS
#define NTOHS(a)        ntohs((a))
#endif
#ifndef NTOHS_IT
#define NTOHS_IT(a)     (a) = NTOHS((a))
#endif

#ifndef HTONL
#define HTONL(a)        htonl((a))
#endif
#ifndef HTONL_IT
#define HTONL_IT(a)     (a) = HTONL((a))
#endif
#ifndef NTOHL
#define NTOHL(a)        ntohl((a))
#endif
#ifndef NTOHL_IT
#define NTOHL_IT(a)     (a) = NTOHL((a))
#endif

/* 2011-09-03 fengjing add */
#ifndef HTONLL
#define HTONLL(a)     my_htonll((a))
#endif
#ifndef HTONLL_IT
#define HTONLL_IT(a)    (a) = my_htonll((a))
#endif

/**************************** ��־ ***************************/

#define LOG_ENABLE      1       /* ��־��ӡ���� */
#define LOG_DISABLE     0       /* ��־��ӡ������ */

#define MAX_LOG_LEN     (1024-1)        /* ��־��󳤶� */

/* ��־��ӡ���� */
#define CMD_PRINT           'p'
#define CMD_PRINT_ON        "on"
#define CMD_PRINT_OFF       "off"
#define CMD_PRINT_FATAL     "f"
#define CMD_PRINT_CRIT      "c"
#define CMD_PRINT_ERROR     "e"
#define CMD_PRINT_WARN      "w"
#define CMD_PRINT_INFO      "i"
#define CMD_PRINT_DEBUG     "d"

/* ��ӡ���� */
typedef enum
{
    OMA_LOG_LEVEL_NON   = 0,
    OMA_LOG_LEVEL_FATAL = 1,
    OMA_LOG_LEVEL_CRIT  = 2,
    OMA_LOG_LEVEL_ERROR = 3,
    OMA_LOG_LEVEL_WARN  = 4,
    OMA_LOG_LEVEL_INFO  = 5,
    OMA_LOG_LEVEL_DEBUG = 6,
    OMA_LOG_LEVEL_ALL   = 255
}LOG_LEVEL_E;

#define LOG_NAME_FATAL  "FATAL"
#define LOG_NAME_CRIT   " CRIT"
#define LOG_NAME_ERROR  "ERROR"
#define LOG_NAME_WARN   " WARN"
#define LOG_NAME_INFO   " INFO"
#define LOG_NAME_DEBUG  "DEBUG"

#ifndef OMA_PRINT_MODE
#define OMA_PRINT_MODE  1
#endif

/* ��ӡ���� */
#if OMA_PRINT_MODE
    #define OMA_FATAL(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_FATAL)\
    {\
        OMA_PRINT_LOG(LOG_NAME_FATAL, x);\
    }

    #define OMA_CRIT(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_CRIT)\
    {\
        OMA_PRINT_LOG(LOG_NAME_CRIT, x);\
    }

    #define OMA_ERROR(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_ERROR)\
    {\
        OMA_PRINT_LOG(LOG_NAME_ERROR, x);\
    }

    #define OMA_WARN(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_WARN)\
    {\
        OMA_PRINT_LOG(LOG_NAME_WARN, x);\
    }

    #define OMA_INFO(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_INFO)\
    {\
        OMA_PRINT_LOG(LOG_NAME_INFO, x);\
    }

    #define OMA_DEBUG(x)\
    if ( g_logLevel >= OMA_LOG_LEVEL_DEBUG)\
    {\
        OMA_PRINT_LOG(LOG_NAME_DEBUG, x);\
    }

    #define OMA_PRINT_LOG(level, x)\
    do{\
        printf("\n");\
        printf("[%s %s %s L%-3d] ", getTextTime(NULL), level, __FILE__, __LINE__);\
        printf x;\
    }while(0)

#else
    #define OMA_FATAL(x)
    #define OMA_CRIT(x)
    #define OMA_ERROR(x)
    #define OMA_WARN(x)
    #define OMA_INFO(x)
    #define OMA_DEBUG(x)
#endif



/**************************** �����궨�� ***************************/
#ifndef CHAR
#define CHAR char
#endif

#ifndef UINT8
#define UINT8 unsigned char
#endif

#ifndef UINT16
#define UINT16 unsigned short
#endif

#ifndef WIN32
#ifndef UINT32
#define UINT32 unsigned long
#endif
#endif

#ifndef INT8
#define INT8 char
#endif

#ifndef INT16
#define INT16 short
#endif

#ifndef INT32
#define INT32 int
#endif

#ifndef BOOL
#define BOOL int
#endif

#ifndef STRING
#define STRING char *
#endif

#ifndef VOID
#define VOID void
#endif

#if defined(TRUE)
#undef TRUE
#endif

#if defined(FALSE)
#undef FALSE
#endif

#define TRUE    1
#define FALSE   0

#define ONE_MINUTE          60
#define ONE_HOUR            3600
#define ONE_DAY             (24*3600)

#define INVALID_FLAG        0	/* ��Ч */
#define VALID_FLAG  	    1   /* ��Ч */

#define OFF_FLAG            0	/* �ر� */
#define ON_FLAG             1	/* ���� */

#define DISABLE_FLAG        0	/* ���� */
#define ENABLE_FLAG         1	/* ���� */

#define OMA_SAME            1   /* �ȽϽ����ͬ */
#define OMA_DIFF            0   /* �ȽϽ����ͬ */

#define INT_LEN             (sizeof(unsigned long))
#define ARRAY_SIZE(x)       (sizeof((x))/sizeof(((x)[0])))

#define OMA_CHECK (x) \
{\
    if ((x) != OMA_SUCCESS)\
    {\
        return OMA_FAILED;\
    }\
}

#if 0
#define INIT_DEFAULT_ACTION(ulActionID, szOidName) \
{\
    if (initDefaultAction(ulActionID, szOidName) != OMA_SUCCESS)\
    {\
        return OMA_FAILED;\
    }\
}

#define INIT_GET_HANDLER(ulActionID, pGetInfo, pulGetLen, pfGetHandler) \
{\
    if (initGetHandler(ulActionID, pGetInfo, pulGetLen, pfGetHandler) != OMA_SUCCESS)\
    {\
        return OMA_FAILED;\
    }\
}

#define INIT_SET_HANDLER(ulActionID, pfSetHandler) \
{\
    if (initSetHandler(ulActionID, pfSetHandler) != OMA_SUCCESS)\
    {\
        return OMA_FAILED;\
    }\
}

#define INIT_CONVERT_FUNC(ulActionID, pfConvertFunc) \
{\
    if (initConvertFunc(ulActionID, pfConvertFunc) != OMA_SUCCESS)\
    {\
        return OMA_FAILED;\
    }\
}
#endif

#ifndef MAX
#define MAX(a, b)   ((a)>(b)?(a):(b))
#endif

#ifndef MIN
#define MIN(a, b)   ((a)>(b)?(b):(a))
#endif


extern CHAR* arg2info(CHAR *szFormat, ...);
//extern OMA_RET_E oma_log(INT32 iModuleID, INT32 iLogType, LOG_LEVEL_E enLogLevel, 
//                         CHAR *szFile, UINT32 ulLine, const CHAR *szLogInfo);

#define MAC_FMT     "%02X:%02X:%02X:%02X:%02X:%02X"
#define MAC_ARG(x)  ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], \
                    ((UINT8*)(x))[3], ((UINT8*)(x))[4], ((UINT8*)(x))[5]

#define IP_FMT	    "%u.%u.%u.%u"
#define IP_ARG(x)   ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], ((UINT8*)(x))[3]


/**************************** ϵͳ��־���� ***************************/
#define SUBSYS_WIFI             1
#define SUBSYS_OMA              2
#define SUBSYS_ROUTE            3
#define SUBSYS_DRIVER           4

 
/* ��ϵͳ��ȱʡģ��� */
#define MODULE_WIFI            ( SUBSYS_WIFI << 8)
#define MODULE_OMA             ( SUBSYS_OMA << 8)
#define MODULE_ROUTE           ( SUBSYS_ROUTE << 8)
#define MODULE_DRIVER          ( SUBSYS_DRIVER << 8)


/* LOG ����*/
#define LOG_TYPE_SECURITY       1
#define LOG_TYPE_DEVICE         2
#define LOG_TYPE_OPERATION      3
#define LOG_TYPE_SERVICE        4

/* LOG���� */
#define LOG_LEVEL_FATAL       4
#define LOG_LEVEL_ERROR       3
#define LOG_LEVEL_WARNING     2 
#define LOG_LEVEL_INFO        1
#define LOG_LEVEL_DETAIL      0

#define OMA_MODULE_PLAT       (MODULE_OMA+0)

#define OMA_MODULE_SYS        (MODULE_OMA+10)
#define OMA_MODULE_BASIC      (MODULE_OMA+11)
#define OMA_MODULE_WIFI       (MODULE_OMA+12)
#define OMA_MODULE_VAP        (MODULE_OMA+13)
#define OMA_MODULE_ADHOC      (MODULE_OMA+14)
#define OMA_MODULE_ROUTE      (MODULE_OMA+15)
#define OMA_MODULE_ETH        (MODULE_OMA+16)
#define OMA_MODULE_VLAN       (MODULE_OMA+17)
#define OMA_MODULE_ACL        (MODULE_OMA+18)
#define OMA_MODULE_FLOW       (MODULE_OMA+19)

#define OMA_MODULE_ALARM      (MODULE_OMA+30)
#define OMA_MODULE_PERF       (MODULE_OMA+31)
#define OMA_MODULE_TOPO       (MODULE_OMA+32)
#define OMA_MODULE_SOFT       (MODULE_OMA+33)

/* LOG�ļ���� */
#define LOG_FILE_CUR            1    /* ��ǰ�ļ� */
#define LOG_FILE_PRE            2    /* ǰһ���ļ� */

/* �û�̬����ӿ��ö���*/
#define LOG_MAX_ITEM_MSG_LENGTH 128

//typedef struct {
//    int iSubsysId;
//    int iSubModId;
//    int iType;            /* ����*/ 
//    int iLevel;            /* ���� */ 
//    struct tm stAbsTime;   /* ����ʱ�� */
//    struct tm stXTime;     /* ���ʱ�� */ 
//    char acMessage[LOG_MAX_ITEM_MSG_LENGTH];
//} LOG_ITEM_T;


#define OMA_LOG_FATAL(iModuleID, iLogType, argLogInfo) \
do{\
    CHAR    *szLogInfo;\
    szLogInfo = arg2info argLogInfo;\
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_FATAL, __FILE__, __LINE__, szLogInfo);\
}while(0)

#define OMA_LOG_CRIT(iModuleID, iLogType, argLogInfo) \
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_CRIT, __FILE__, __LINE__, arg2info argLogInfo)

#define OMA_LOG_ERROR(iModuleID, iLogType, argLogInfo) \
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_ERROR, __FILE__, __LINE__, arg2info argLogInfo)

#define OMA_LOG_WARN(iModuleID, iLogType, argLogInfo) \
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_WARN, __FILE__, __LINE__, arg2info argLogInfo)

#define OMA_LOG_INFO(iModuleID, iLogType, argLogInfo) \
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_INFO, __FILE__, __LINE__, arg2info argLogInfo)

#define OMA_LOG_DEBUG(iModuleID, iLogType, argLogInfo) \
    oma_log(iModuleID, iLogType, OMA_LOG_LEVEL_DEBUG, __FILE__, __LINE__, arg2info argLogInfo)

/**************************** ҵ����ض��� ***************************/
#define MAX_CFG_DATA_LEN    (1024*32)       /* ����������󳤶� */

#define MAX_COMMAND_LEN     (1024-1)        /* ϵͳ������󳤶� */

#define EXTINFO_SPLIT       '&'
#define TRAP_VALUE_SPLIT    '&'

/* TRAP��Ϣ���� */
#define ALARM_TRAP          1   /* �澯�ϱ�Trap */
#define EVENT_TRAP          2   /* �¼��ϱ�Trap */
#define PERF_TRAP           3   /* �����ϱ�Trap */

/* �����Ϣ�������� */
#define MAX_ALARM_SEND_RATE 3
#define MAX_EVENT_SEND_RATE 3
#define MAX_PERF_SEND_RATE  3

/* ��Чģʽ */
#define INFORCE_INSTANT     0   /* ��ʱ��Ч */
#define INFORCE_DELAY       1   /* ��ʱ��Ч */
#define INFORCE_TIEMING     2   /* ��ʱ��Ч */
#define INFORCE_MANUAL      4   /* �ֶ���Ч */

/* ���������� */
#define SETMODE_ADD         1           /* ���� */
#define SETMODE_SET         2           /* �޸� */
#define SETMODE_DEL         3           /* ɾ�� */
#define SETMODE_RESET       SETMODE_ADD /* ���� */

/* ����ļ��� */
#define MAX_SOFTWARE_FILE_NUM   4       /* �������ʱ������ļ����� */
#define MAX_FILENAME_LEN        31      /* �������ʱ��FTP�������ļ�����󳤶� */
#define MAX_FILEPATH_LEN        127     /* �������ʱ��FTP�������ļ�·����󳤶� */


#ifdef WIN32
#define IEEE80211_ADDR_LEN          6
#define IOCTL_MAC_FILTER_MAXNUM     64
#endif

/* ����֮���SNMP��Ϣ���� */
#define SNMP_NOTIFY_ALARM   1
#define SNMP_NOTIFY_EVENT   2
#define SNMP_NOTIFY_PERF    3

#define SNMP_QUERY_TOPO         11
#define SNMP_QUERY_NEIGHBOR     12

#define ONE_MB                  (1024*1024)

#define INVALID_TEMP            (-1000)

#ifndef MAX_OID_LEN
#define MAX_OID_LEN     128
#endif

/**************************** �����ṹ���� ***************************/

/* ʱ�� */
typedef struct
{
    unsigned long   year;
    unsigned long   month;
    unsigned long   day;
    unsigned long   hour;
    unsigned long   minute;
    unsigned long   second;
}T_omaTime;

/* Trap���� */
typedef struct
{
    char            community[40];
    char            trapHost[40];
    char            sinkPort[12];

    unsigned short  trapPort;

    unsigned long   ulNeedInit;
}T_omaTrapInfo;

typedef struct
{
    char    oidName[32];
    OID     handleOid[32];
    size_t  oidLength;
}T_omaOid;

typedef enum
{
    DATA_TYPE_CHAR  = 0,
    DATA_TYPE_UINT8,
    DATA_TYPE_UINT16,
    DATA_TYPE_UINT32,
    DATA_TYPE_INT8,
    DATA_TYPE_INT16,
    DATA_TYPE_INT32,
    DATA_TYPE_STRUCT,
}DATA_TYPE_E;

typedef struct
{
    char            acName[32];
    DATA_TYPE_E     enDataType;
    unsigned short  usDim1;
    unsigned short  usDim2;         /* ��Ա���� member[dim1][dim2]*/
}DATA_DESC_T;

typedef struct
{
    unsigned long       ulMemberNum;
    DATA_DESC_T         astDataDesc[32];
}ACTION_DESC_T;

typedef int (OMA_GET_HANDLER)(void* pGetInfo, unsigned long *pulGetLen);
typedef int (OMA_SET_HANDLER)(void* pSetInfo, unsigned long ulSetLen);
typedef int (ACTION_CONVERT_FUNC)(void* value);
typedef int (ACTION_INIT_FUNC)(void* value);

typedef struct
{
    unsigned long           ulActionID;
    T_omaOid                stOid;

    void                    *pGetInfo;
    unsigned long           *pulGetLen;
    OMA_GET_HANDLER         *pfGetHandler;

    unsigned long           ulSetLen;
    OMA_SET_HANDLER         *pfSetHandler;

    ACTION_DESC_T           stActionInfo;           /* ��Ӧ�����ݽṹ�����ֵ� */
    ACTION_CONVERT_FUNC     *pfActionConvertFunc;   /* ���ݽṹ�ֽ�ת������ */
    ACTION_INIT_FUNC        *pfActionInitFunc;      /* ���ݽṹ��ʼ������ */

}ACTION_INFO_T;

/* �ļ����� */
typedef enum
{
    LOAD_STATUS_WAIT = 1,
    LOAD_STATUS_DOING= 2,
    LOAD_STATUS_FAIL = 3,
    LOAD_STATUS_DONE = 4
}LOAD_STATUS_E;

typedef struct
{
    char            acFileName[MAX_FILENAME_LEN+1];
    unsigned long   ulFileVersion;
/*    unsigned long   ulFileDate;
    unsigned long   ulFileSize;
*/
    unsigned long   ulStatus;
    unsigned long   ulFileLoadSize;
}FTP_FILE_INFO_T;

typedef enum
{
    FLASH_STATUS_WAIT  = 11,
    FLASH_STATUS_ERASE = 12,  /* ���ڲ��� */
    FLASH_STATUS_WRITE = 13,  /* ����д */
    FLASH_STATUS_FAIL  = 14,
    FLASH_STATUS_DONE  = 15
}FLASH_STATUS_E;

typedef struct
{
    char            acFileName[MAX_FILENAME_LEN+1];

    unsigned long   ulFileSize;
    //unsigned long   ulBlockCount;

    unsigned long   ulStatus;
    //unsigned long   ulBlockEraseCount;
    unsigned long   ulFileEraseSize;
    unsigned long   ulFileWriteSize;
}FLASH_FILE_INFO_T;

typedef struct
{
    char            acFileName[MAX_FILENAME_LEN+1];
    unsigned long   ulFileVersion;
    unsigned long   ulFileSize;

    unsigned long   ulLoadStatus;
    unsigned long   ulFlashStatus;

    unsigned long   ulFileLoadSize;
    unsigned long   ulFileEraseSize;
    unsigned long   ulFileWriteSize;
}FILE_UPDATE_PROGRESS_T;

#define FTP_LOAD_INFO_FILE_POSTFIX      "inf"
#define FLASH_WRITE_INFO_FILE_POSTFIX   "prg"

/* OMA����̨����ṹ */
typedef struct
{
    char            command[128];
    unsigned long   type;
    char            para[64];
}OMA_COMMAND_T;

#define OMA_MAX_SNMP_SETGET_LEN	    (64*1024)
typedef struct
{
	UINT32		ulMsgType;
	UINT32		ulMsgLen;       /* aucMsgData�е�ʵ�ʳ��� */

	UINT8		aucMsgData[OMA_MAX_SNMP_SETGET_LEN];
}OMA_SNMP_SETGET_T;

typedef OMA_SNMP_SETGET_T   OMA_SLAVE_NOTIFY_MASTER_T;
typedef OMA_SNMP_SETGET_T   OMA_MASTER_QUERY_SLAVE_T;

#endif /* OMA_DEF_H */



