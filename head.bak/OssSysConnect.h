/******************************************************************************
模块名      : SYSCTL
文件名      : OssSysConnect.h
相关文件    :
实现功能    : 链路监测管理
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/
#ifndef _OSSSYSCONNECT_H_
#define _OSSSYSCONNECT_H_

BOOL    SysConnCheckInit(VOID);
VOID    UpdateCheckCpu(WORD wAcId, WORD wApId, BOOL bAddFlag);

#endif

