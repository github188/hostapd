/******************************************************************************
模块名      : VM
文件名      : OssVm.h
相关文件    :
实现功能    : VM 基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSVM_H_
#define _OSSVM_H_

#define INVALID_AC_ID       (WORD) 0
#define INVALID_AP_ID       (WORD) 0xffff

/* 重启原因 */
#define VM_RESET_NORMAL             (INT)0              /* RESET原因，正常重起 */
#define VM_RESET_POWERON_FAILURE    (INT)4              /* RESET原因, 基本进程上电失败 */
#define VM_RESET_INVALID_VERSION    (INT)5              /* RESET原因，无效版本 */
#define VM_RESET_DATA_SYNC_FAIL     (INT)6              /* RESET原因，数据同步失败 */
#define VM_RESET_BY_OMCR            (INT)7              /* RESET原因，后台请求重起 */
#define VM_RESET_UPLINK_BREAK       (INT)8              /* RESET原因, 检测不到上层CPU */
#define VM_RESET_ADDR_MISSED        (INT)9              /* RESET原因, 自身地址不在地址表中 */
#define VM_RESET_UPCPU_POWERON      (INT)10             /* RESET原因, 上级CPU重启 */
#define VM_RESET_BY_CPUBLOCK        (INT)12             /* RESET原因, CPU被闭塞 */
#define VM_RESET_SELFOFFLINE        (INT)13             /* RESET原因, 本板通讯断 */
#define VM_RESET_PROC_CHECK_FAIL	(INT)14		/* RESET原因, 应用进程保活失败*/

/* 系统运行阶段 */
#define VM_SYSTEM_IDLE      (WORD32)0
#define VM_SYSTEM_INIT      (WORD32)1
#define VM_SYSTEM_RUNNING   (WORD32)2

typedef struct tagPID
{
    WORD16  wAcId;
    WORD16  wApId;
    WORD16  wPno;
    WORD16  wInst;
} TPID, *LPTPID;


extern WORD32   gdwSystemPhase;
extern BYTE     gbySysTaskCount;


/* 函数定义 */
BOOL    VmInit              (VOID);            /* VM 初始化 */
BOOL    VmStart             (VOID);            /* Vm 启动 */

WORD32  VmCreateLock        (VOID);
BOOL    VmDeleteLock        (WORD32);
BOOL    VmLock              (WORD32, WORD32);
BOOL    VmUnLock            (WORD32 );
VOID    VmReset             (INT iReason);
BOOL    CheckAddrTable (VOID);
#endif /* _OSSVM_H_ */
