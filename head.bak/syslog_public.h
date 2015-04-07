#ifndef SYSLOG_PUBLIC_H
#define SYSLOG_PUBLIC_H


/* ��ӡ���� */
#define LOG_OFF                 0xff    /* ����ӡ */

#define LOG_EMERG               0       /* system is unusable */
#define LOG_ALERT               1       /* action must be taken immediately */
#define LOG_CRIT                2       /* critical conditions */
#define LOG_ERR                 3       /* error conditions */
#define LOG_WARNING             4       /* warning conditions */
#define LOG_NOTICE              5       /* normal but significant condition */
#define LOG_INFO                6       /* informational */
#define LOG_DEBUG               7       /* debug-level messages */

#define LOG_ERROR               LOG_ERR
#define LOG_WARN                LOG_WARNING

#define LOG_MODULE_NUM          64  /* ��־ģ����� */

/* powerac/powwerapģ��     0 - 23 */
#define LM_OSS              0
#define LM_DB               1
#define LM_DEVM             2
#define LM_USRM             3
#define LM_OMA              4
#define LM_CW               5
#define LM_HOSTAPD          6
#define LM_ACM              7
#define LM_RRM              8
#define LM_PORTAL           9
#define LM_WAPIAPD          10
#define LM_SYSM             11

/* Add by majp 2012-03-13 start */
#define LM_MODULE        16     /*�û�ģ����־, �������*/
#define LM_OPERATION     17     /*������־�����������������*/
#define LM_BUSINESS       18     /*ҵ��������־���������������*/
#define LM_ALERT          19     /*�澯��־���������������*/
#define LM_EVENT          20    /*�¼���־���������������*/ 
#define LM_SECURITY       21    /*��ȫ��־���������������*/ 
/* Add by majp 2012-03-13 end */

/* AC��Χ���̡��ں�ģ��     24 - 47 */
#define LOG_MODULE_AC       24

#define LM_ACWEB            (LOG_MODULE_AC+0)
#define LM_ACCOUNT          (LOG_MODULE_AC+1)
#define LM_AGENT            (LOG_MODULE_AC+2)
#define LM_DHCP             (LOG_MODULE_AC+3)
#define LM_FW               (LOG_MODULE_AC+4)
#define LM_HR               (LOG_MODULE_AC+5)
#define LM_IDS              (LOG_MODULE_AC+6)
#define LM_IGMP             (LOG_MODULE_AC+7)
#define LM_L2W              (LOG_MODULE_AC+8)
#define LM_NTP              (LOG_MODULE_AC+9)
#define LM_PA               (LOG_MODULE_AC+10)
#define LM_PPPOE            (LOG_MODULE_AC+11)
#define LM_QOS              (LOG_MODULE_AC+12)
#define LM_ROUTE            (LOG_MODULE_AC+13)
#define LM_TS               (LOG_MODULE_AC+14)
#define LM_SYSMON           (LOG_MODULE_AC+15)
#define LM_SYSLOG           (LOG_MODULE_AC+16)
#define LM_IPC              (LOG_MODULE_AC+17)

/* AP��Χ���̡��ں�ģ��     48 - 63 */
#define LOG_MODULE_AP       48

#define LM_APDRIVER         (LOG_MODULE_AP+0)
#define LM_APWIFI           (LOG_MODULE_AP+1)
#define LM_APROUTE          (LOG_MODULE_AP+2)
#define LM_APWEB            (LOG_MODULE_AP+3)
#define LM_APAGENT          (LOG_MODULE_AP+4)
#define LM_APSYSMON         (LOG_MODULE_AP+5)
#define LM_APSYSLOG         (LOG_MODULE_AP+6)
#define LM_APDHCP           (LOG_MODULE_AP+7)
#define LM_APNTP            (LOG_MODULE_AP+8)
#define LM_APL2W            (LOG_MODULE_AP+9)
#define LM_APMISC            LM_APAGENT

#define LM_UNKNOW           LOG_MODULE_NUM

#endif

