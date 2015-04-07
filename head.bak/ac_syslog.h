/*
 * File Name:   ac_syslog.h
 * Description: 
 * Author: majunpeng@gbcom.com.cn
 * 
 * Created on 2012-03-29
*/

#ifndef __AC_SYSLOG_H__
#define __AC_SYSLOG_H__

extern void ac_openlog(const char *ident, int logstat, int logfac);
extern void ac_closelog();
extern void ac_syslog(int pri, const char *fmt, ...);
#endif
