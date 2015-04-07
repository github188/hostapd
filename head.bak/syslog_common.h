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

#define PROC_STATE_UNKNOW           -1      /* δ֪ */
#define PROC_STATE_NULL             0       /* δ���� */
#define PROC_STATE_RUNNING          1       /* �Ѿ����� */

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

#define ROTATE_LOGTIME              "rotate"        /* ת������ */
#define ROTATE_SIZE                 "size"          /* ��־��С */
#define ROTATE_COMPRESS             "compress"      /* ѹ�� */
#define ROTATE_NOCOMPRESS           "nocompress"    /* ��ѹ�� */

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

/* SYSLOGЭ�鶨�����־ģ�� */
#define LOG_MODULE_KERN         0
#define LOG_MODULE_LOCAL0       16
#define LOG_MODULE_LOCAL1       17
#define LOG_MODULE_LOCAL2       18
#define LOG_MODULE_LOCAL3       19
#define LOG_MODULE_LOCAL4       20
#define LOG_MODULE_LOCAL5       21

#define LOG_MODULE_REMOTE0      LOG_MODULE_LOCAL0       /* Զ����־������0 */
#define LOG_MODULE_REMOTE1      LOG_MODULE_LOCAL1       /* Զ����־������1 */
#define LOG_MODULE_REMOTE2      LOG_MODULE_LOCAL2       /* Զ����־������2 */
#define LOG_MODULE_REMOTE3      LOG_MODULE_LOCAL3       /* Զ����־������3 */

//#define LOG_MODULE_USER_LOCAL   LOG_MODULE_LOCAL4       /* �����û�̬��־ */
#define LOG_MODULE_USER_LOCAL   LOG_MODULE_LOCAL0

/* Modified by majp 2012-03-20 end */

#define MAX_LOGSVR_NUM          4

typedef struct
{
	unsigned char   aucLogModule[LOG_MODULE_NUM];       /*ģ�鿪��	            */
	unsigned long   ulLogToStdout;	                    /*�Ƿ��ӡ����׼���	*/
	unsigned long   ulLogSvrNum;	                    /*Զ����־��������Ŀ  */
	unsigned char   aaucLogSvrIp[MAX_LOGSVR_NUM][4];    /*Զ����־������IP��ַ */
	unsigned long   aulLogSvrPort[MAX_LOGSVR_NUM];	    /*Զ����־�������˿ں� */
	unsigned long   ulLogTransType;	                    /*��־��������	       */
#define SYSLOG_TRANS_NOR    0   /* ��׼ģʽ */
#define SYSLOG_TRANS_OPT    1   /* �Ż�ģʽ */
}SYSLOG_LOG_CONFIG_T;

/* ��־ת������ */
typedef struct
{
	unsigned long   ulLogSvrSwitch;     /*  ��־����������	      */
	unsigned char   aucLogSvrIp[4];     /*  ��־��������IP��ַ  */
	unsigned long   ulLogSvrPort;       /*  ��־�������󶨶˿�	  */
	unsigned long   ulLogBakDay;   	    /*  ��־��������	      */
	unsigned long   ulLogFileSize;      /*  ��־�ļ���С	      */
	unsigned long   ulLogCompress;      /*  �Ƿ�ѹ��	          */
}SYSLOG_SVR_CONFIG_T;

/* ϵͳ��־���� */
typedef struct
{
    unsigned long   ulLocalOamLogSwitch;    /* �Ƿ��¼���ع�����־ 0������ 1������ */
    unsigned long   ulRemoteOamLogSwitch;   /* �Ƿ��¼Զ�̹�����־ 0������ 1������ */
    unsigned long   ulSysServiceLogSwitch;  /* �Ƿ��¼ϵͳ������־ 0������ 1������ */
    unsigned char   aucLogSvrIp[4];         /* ��־�洢������IP��ַ */
    unsigned long   ulLogSvrPort;           /* ��־�洢�������˿� */
    char            acFtpUser[64];          /* FTP�û��� */
    char            acFtpPwd[32];           /* FTP���� */
    char            acFtpDir[64];           /* �����־�ļ���FTP·�� */
    unsigned long   ulRemoteStorePeriod;    /* ��ʱת������ 0,5~60*24, 0��ʾ������ת��, ��λ:���� */
}SYSLOG_STORE_CONFIG_T;

typedef struct
{
    SYSLOG_LOG_CONFIG_T     stLogConfig;
    SYSLOG_SVR_CONFIG_T     stLogSvrConfig;
    SYSLOG_STORE_CONFIG_T   stStoreConfig;
}SYSLOG_CONFIG_T;

#endif

