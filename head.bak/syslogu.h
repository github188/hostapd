#ifndef SYSLOGU_H
#define SYSLOGU_H

int  syslog_init(void);
void syslogu(int iLogModule, int iloglevel, const char *szLogFormat, ...);
void set_log_module(int iLogModule);
void logu(int iloglevel, const char *szLogFormat, ...);

#endif

