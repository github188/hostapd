/******************************************************************************
模块名      : SYSCTL
文件名      : OssSysMoniProc
相关文件    :
实现功能    : 系统监控
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/10/30  潘妍艳      创建
******************************************************************************/

#ifndef _OSSSYSMONIPROC_H_
#define _OSSSYSMONIPROC_H_

/* 宏定义*/
#define SYS_PROC_MONI_NUM_MAX		16		/* 最大监控进程数*/
/* 2009-11-5 pyy 12-->24 */
/* 2011-1-26 24-->48 */
/* 2011-5-20 pyy: 48-->120 修改为120次, 监控时长修改为10分钟*/
#define SYS_PROC_LOST_ECHO_NUM_MAX	120		/* 最大允许丢失的保活报文数量，修改为120次*/

/* 定时器时长: 单位为100ms*/
#define 	SYS_TIMERLEN_MONI_INIT			6000		/* 等待其它线程初始化定时器时长*/
#define 	SYS_TIMERLEN_MONI_PRD			50		/* 周期性检查定时器时长*/
#define	SYS_TIMERLEN_SETMONIFLAG_PRD	50		/* 周期性写powerac状态标记位定时器时长*/

#define	SYS_TIMER_MONI_INIT				TIMER1
#define	SYS_TIMER_MONI_PRD				TIMER2
#define	SYS_TIMER_SETMONIFLAG_PRD		TIMER3

#define	SYS_TIMEROUT_MONI_INIT_MSG		EV_TIMER1
#define	SYS_TIMEROUT_MONI_PRD_MSG		EV_TIMER2
#define	SYS_TIMEROUT_SETMONIFLAG_MSG	EV_TIMER3


#define SYS_MONI_FILE_NAME_LEN	128				/* 监控文件名长度*/

#define SYS_CPULOAD_HIGH_THRESHOLD	    		80			/* CPU高门限:80% */	
#define SYS_CPULOAD_THRESHOLD_RANGE	    		5			/* 5% */
#define SYS_CPULOAD_HIGH_THRESHOLD_NUM		5			/* 如果CPU使用率连续5次超过上限，则降低打印级别 */

/* 结构体定义*/
typedef struct {
	WORD32	ulUsed;
	WORD32	ulEchoNum;							/* 连续未回复的保活报文数量*/
	WORD16  usPno;								/* 进程号*/
	CHAR    acProcName[PROC_NAME_LENGTH];		/* 进程名*/
	BYTE	aucRsv[1];							/* 填充字节*/
	WORD32	ulLastRunNum;						/*  前一次被调度的次数*/
} SYS_PROC_MONI_INFO_T;


/* 函数声明*/
WORD32	oss_sys_moni_init(VOID);
VOID oss_sys_moni_get_cpu_usage (VOID);
VOID oss_sys_moni_check_cpu_usage (VOID);
VOID oss_sys_moni_check_proc (VOID);
VOID oss_sys_moni_set_moniflag (VOID);
WORD32	oss_sys_moni_timeout_moni_init(VOID);
WORD32	oss_sys_moni_timeout_moni_prd(VOID);
WORD32	oss_sys_moni_recv_echo_rsp(VOID);

#endif
