#ifndef SYSLOG_COMMON_H
#define SYSLOG_COMMON_H

#include "syslog_public.h"

#define TIME_FMT        "%04d-%02d-%02d %02d:%02d:%02d"
#define TIME_ARG(x)     (1900+(x)->tm_year),(1+(x)->tm_mon),(x)->tm_mday,(x)->tm_hour,(x)->tm_min,(x)->tm_sec

#ifndef IP_FMT
#define IP_FMT          "%d.%d.%d.%d"
#define IP_ARG(x)       ((unsigned char*)(x))[0],((unsigned char*)(x))[1],((unsigned char*)(x))[2],((unsigned char*)(x))[3]
#endif

#define SYSLOG_PRI(iLogModule, iLogLevel)   ((iLogModule)*8+(iLogLevel))

#define PROC_STATE_UNKNOW           -1      /* 未知 */
#define PROC_STATE_NULL             0       /* 未运行 */
#define PROC_STATE_RUNNING          1       /* 已经运行 */

#define DEVM_CONTROL_NAME           "powerac"
#define SYSLOG_CONTROL_NAME         "syslogctl"

#define KLOG_PROGRAME_NAME          "klogd"
#define SYSLOG_PROGRAME_NAME        "syslogd"

#define CONFIG_FILE                 "/etc/syslog.conf"
#define CONFIG_FILE_BAK             CONFIG_FILE".bak"

#define CONF_ROTATE_FILE            "/etc/logrotate.d/ac_syslog.conf"
#define CONF_ROTATE_FILE_BAK        CONF_ROTATE_FILE".bak"

#define LOG_ROOT                    "/var/log"
#define DFT_LOG_FILE                LOG_ROOT"/messages"
#ifdef AC_MODE
#define USER_LOG_FILE               LOG_ROOT"/ac.log"
#define KERN_LOG_FILE               LOG_ROOT"/ac_kern.log"
/* add by gwx 2012-6-20 */
#define OPERATION_LOG_FILE		LOG_ROOT"/ac_operation.log"
#define BUSNIESS_LOG_FILE		LOG_ROOT"/ac_business.log"
#define ALERT_LOG_FILE			LOG_ROOT"/ac_alert.log"
#define EVENT_LOG_FILE			LOG_ROOT"/ac_event.log"
#define SECURUTY_LOG_FILE		LOG_ROOT"/ac_security.log"
#define ADMIN_LOG_FILE              LOG_ROOT"/ac_admin.log"
#else
#define USER_LOG_FILE               LOG_ROOT"/messages"
#define KERN_LOG_FILE               LOG_ROOT"/messages"
#endif

#define ROTATE_LOGTIME              "rotate"        /* 转存天数 */
#define ROTATE_SIZE                 "size"          /* 日志大小 */
#define ROTATE_COMPRESS             "compress"      /* 压缩 */
#define ROTATE_NOCOMPRESS           "nocompress"    /* 不压缩 */

#define CONTROL_FILE_PATH           "/proc/"

#define PRINT_CONTROL_FILE          "syslogctl.dat"

#define CONFIG_CONS                 "/dev/console"

#define CONFIG_KEY_PORT             "port"
#define CONFIG_KEY_LOGSIZE          "log_size"
#define CONFIG_KEY_TRANSTYPE        "transtype"

/* Modified by majp 2012-03-13 start */
/*
#define CONFIG_KEY_REMOTE0          "local0"
#define CONFIG_KEY_REMOTE1          "local1"
#define CONFIG_KEY_REMOTE2          "local2"
#define CONFIG_KEY_REMOTE3          "local3"
*/

#define CONFIG_KEY_REMOTE0          "local1.*;local2.*;local3.*;local4.*;local5.*;"
#define CONFIG_KEY_REMOTE1          "local1.*;local2.*;local3.*;local4.*;local5.*;"
#define CONFIG_KEY_REMOTE2          "local1.*;local2.*;local3.*;local4.*;local5.*;"
#define CONFIG_KEY_REMOTE3          "local1.*;local2.*;local3.*;local4.*;local5.*;"

#define CONFIG_KEY_USER             "local4"
#define CONFIG_KEY_KERN             "kern"

#define AP_SYSLOG_CONFIG_FILE       "/tmp/syslogcfg.conf"
#define AP_SYSLOG_CONFIG_DATA       "/tmp/syslogcfg.dat"

#define SYSLOG_DEFAULT_PORT         514

/* SYSLOG协议定义的日志模块 */
#define LOG_MODULE_KERN         0
#define LOG_MODULE_LOCAL0       16
#define LOG_MODULE_LOCAL1       17
#define LOG_MODULE_LOCAL2       18
#define LOG_MODULE_LOCAL3       19
#define LOG_MODULE_LOCAL4       20
#define LOG_MODULE_LOCAL5       21

#define LOG_MODULE_REMOTE0      LOG_MODULE_LOCAL0       /* 远程日志服务器0 */
#define LOG_MODULE_REMOTE1      LOG_MODULE_LOCAL1       /* 远程日志服务器1 */
#define LOG_MODULE_REMOTE2      LOG_MODULE_LOCAL2       /* 远程日志服务器2 */
#define LOG_MODULE_REMOTE3      LOG_MODULE_LOCAL3       /* 远程日志服务器3 */

//#define LOG_MODULE_USER_LOCAL   LOG_MODULE_LOCAL4       /* 本地用户态日志 */
#define LOG_MODULE_USER_LOCAL   LOG_MODULE_LOCAL0

/* Modified by majp 2012-03-20 end */

#define MAX_LOGSVR_NUM          4

typedef struct
{
	unsigned char   aucLogModule[LOG_MODULE_NUM];       /*模块开关	            */
	unsigned long   ulLogToStdout;	                    /*是否打印到标准输出	*/
	unsigned long   ulLogSvrNum;	                    /*远程日志服务器数目  */
	unsigned char   aaucLogSvrIp[MAX_LOGSVR_NUM][4];    /*远程日志服务器IP地址 */
	unsigned long   aulLogSvrPort[MAX_LOGSVR_NUM];	    /*远程日志服务器端口号 */
	unsigned long   ulLogTransType;	                    /*日志传输类型	       */
#define SYSLOG_TRANS_NOR    0   /* 标准模式 */
#define SYSLOG_TRANS_OPT    1   /* 优化模式 */
}SYSLOG_LOG_CONFIG_T;

/* 日志转存配置 */
typedef struct
{
	unsigned long   ulLogSvrSwitch;     /*  日志服务器开关	      */
	unsigned char   aucLogSvrIp[4];     /*  日志服务器绑定IP地址  */
	unsigned long   ulLogSvrPort;       /*  日志服务器绑定端口	  */
	unsigned long   ulLogBakDay;   	    /*  日志保存天数	      */
	unsigned long   ulLogFileSize;      /*  日志文件大小	      */
	unsigned long   ulLogCompress;      /*  是否压缩	          */
}SYSLOG_SVR_CONFIG_T;

/* 系统日志配置 */
typedef struct
{
    unsigned long   ulLocalOamLogSwitch;    /* 是否记录本地管理日志 0：禁用 1：启用 */
    unsigned long   ulRemoteOamLogSwitch;   /* 是否记录远程管理日志 0：禁用 1：启用 */
    unsigned long   ulSysServiceLogSwitch;  /* 是否记录系统运行日志 0：禁用 1：启用 */
    unsigned char   aucLogSvrIp[4];         /* 日志存储服务器IP地址 */
    unsigned long   ulLogSvrPort;           /* 日志存储服务器端口 */
    char            acFtpUser[64];          /* FTP用户名 */
    char            acFtpPwd[32];           /* FTP密码 */
    char            acFtpDir[64];           /* 存放日志文件的FTP路径 */
    unsigned long   ulRemoteStorePeriod;    /* 定时转储周期 0,5~60*24, 0表示不周期转储, 单位:分钟 */
}SYSLOG_STORE_CONFIG_T;

typedef struct
{
    SYSLOG_LOG_CONFIG_T     stLogConfig;
    SYSLOG_SVR_CONFIG_T     stLogSvrConfig;
    SYSLOG_STORE_CONFIG_T   stStoreConfig;
}SYSLOG_CONFIG_T;

#endif

