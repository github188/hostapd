/******************************************************************************
模块名      : SYSCFG
文件名      : OssConfigProj.h
相关文件    :
实现功能    : 工程配置的头文件
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSCONFIGPROJ_H_
#define _OSSCONFIGPROJ_H_


/***************************************************************************
----------------------------------------------------------------------------
    SECTION1:    外部函数声明
----------------------------------------------------------------------------
****************************************************************************/
/*========BEGIN: OSS函数声明========*/
/* 任务入口 */
extern VOID ScheTaskEntry               (VOID*);

/* 定时任务入口 */
extern VOID LogSave_Timer               (VOID);

/* 进程入口 */
extern VOID PowerOnCtlProc              (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID IpTableProc                 (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID ConnCheckProc               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID OssTestProc1               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID OssTestProc2               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
/*========END: OSS函数声明========*/


/*========BEGIN: APP进程入口函数声明========*/



#endif /* _OSSCONFIGBOARD_H_ */
