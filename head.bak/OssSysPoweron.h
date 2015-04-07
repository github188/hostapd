/******************************************************************************
模块名      : SYSCTL
文件名      : OssSysPoweron
相关文件    :
实现功能    : 上电管理
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSSYSPOWERON_H_
#define _OSSSYSPOWERON_H_

#define BASE_PROC_NUM       (WORD16) 20    /* 基本进程的个数 */
#define LAST_PROC_NUM       (WORD16) 10    /* 末尾进程的个数 */
#define PO_CONTINUE         (BYTE) 0       /* 超时后忽略 */
#define PO_RESET            (BYTE) 1       /* 超时后重启 */
#define PO_WAIT             (BYTE) 2       /* 超时后等待 */

BOOL VmPowerOnAck (BOOL bState);

#endif
