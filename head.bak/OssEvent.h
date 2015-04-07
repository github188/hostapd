/******************************************************************************
模块名      : VM
文件名      : OssEvent.h
相关文件    :     
实现功能    : VM事件定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/

#ifndef _OSSEVENT_H_
#define _OSSEVENT_H_


/****************************************
 * [系统控制模块] 的事件定义            *
 ****************************************/

#define EV_SYSCTRL_BEGIN            (WORD16)100

/* 上电控制 */
#define EV_SYSCTRL_POWERON_BEGIN    (WORD16)(EV_SYSCTRL_BEGIN + 0)
#define EV_MASTER_POWERON           (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 0)
#define EV_POWERON_ACK              (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 4)
#define EV_ONLINE_REPORT            (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 5)


/* 链路监测 */
#define EV_SYSCTRL_CONN_BEGIN       (WORD16)(EV_SYSCTRL_BEGIN + 40)
#define EV_CONN_CHECK               (WORD16)(EV_SYSCTRL_CONN_BEGIN + 0)
#define EV_CONN_CHECK_ACK           (WORD16)(EV_SYSCTRL_CONN_BEGIN + 1)
#define EV_CPU_OFFLINE              (WORD16)(EV_SYSCTRL_CONN_BEGIN + 2)
#define EV_CPU_ONLINE               (WORD16)(EV_SYSCTRL_CONN_BEGIN + 3)
#define EV_DCPU_POWERON_RPT         (WORD16)(EV_SYSCTRL_CONN_BEGIN + 4)
#define EV_DCPU_POWERON_ACK         (WORD16)(EV_SYSCTRL_CONN_BEGIN + 5)
#define EV_UP_CONN_BREAK            (WORD16)(EV_SYSCTRL_CONN_BEGIN + 6)
#define EV_UP_CONN_RESTORE          (WORD16)(EV_SYSCTRL_CONN_BEGIN + 7)
#define EV_UCPU_POWERON_RPT         (WORD16)(EV_SYSCTRL_CONN_BEGIN + 13)
#define EV_UCPU_POWERON_ACK         (WORD16)(EV_SYSCTRL_CONN_BEGIN + 14)

/* 2008-10-31 pyy add start */
#define EV_PROC_ECHO_REQ			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 15)
#define EV_PROC_ECHO_RSP			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 16)
/* 2008-10-31 pyy add end */

/* 2008-11-27 pyy add start */
#define EV_MS_LINK_HELLO			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 17)
#define EV_MS_LINK_HELLO_ACK		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 18)
#define EV_MS_MATE_ONLINE			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 19)
#define EV_MS_MATE_OFFLINE		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 20)
/* 2008-11-27 pyy add end */

#define EV_BK_LNK_SETUP             (WORD16)(EV_SYSCTRL_CONN_BEGIN + 21)
#define EV_BK_LNK_BREAK             (WORD16)(EV_SYSCTRL_CONN_BEGIN + 22)

#define EV_WEB_LNK_SETUP		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 23)
#define EV_WEB_LNK_BREAK 		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 24)

/* 下面这3个前后台链路检测事件号，如果要修改，请与后台人员协商 */
#define EV_BK_LINK_HELLO            	(WORD16) 170             /* 后台给前台发送的链路检测事件号 */
#define EV_BK_LINK_HELLO_ACK     	(WORD16) 171             /* 前台给后台发送的链路检测应答 */

#define EV_WEB_LINK_HELLO			(WORD16) 172		/* AC-WEB给AC发送的链路检测事件号*/
#define EV_WEB_LINK_HELLO_ACK		(WORD16) 173		/* AC给AC-WEB发送的链路检测应答*/

/* 2010-1-19 新增: 主备功能新增消息*/
#define EV_AC_MS_LINK_HELLO			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 50)
#define EV_AC_MS_LINK_HELLO_ACK		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 51)
#define EV_BAKACID_CHG_IND				(WORD16)(EV_SYSCTRL_CONN_BEGIN + 52)	/* 接管AC ID 变化通知*/

#define EV_SYSCTRL_END              (WORD16)(EV_SYSCTRL_BEGIN + 800)


/****************************************
 * [定时管理模块] 的事件定义            *
 ****************************************/

#define EV_VMTM_BEGIN               (WORD16)1000

/* 以下定时事件号的定义需要与 TIMER0... 关联上 */
#define EV_TIMER0EXPIRY             (WORD16)(EV_VMTM_BEGIN + 0)  /* 定时器0事件 */
#define EV_TIMER1EXPIRY             (WORD16)(EV_VMTM_BEGIN + 1)  /* 定时器1事件 */
#define EV_TIMER2EXPIRY             (WORD16)(EV_VMTM_BEGIN + 2)  /* 定时器2事件 */
#define EV_TIMER3EXPIRY             (WORD16)(EV_VMTM_BEGIN + 3)  /* 定时器3事件 */
#define EV_TIMER4EXPIRY             (WORD16)(EV_VMTM_BEGIN + 4)  /* 定时器4事件 */
#define EV_TIMER5EXPIRY             (WORD16)(EV_VMTM_BEGIN + 5)  /* 定时器5事件 */
#define EV_TIMER6EXPIRY             (WORD16)(EV_VMTM_BEGIN + 6)  /* 定时器6事件 */
#define EV_TIMER7EXPIRY             (WORD16)(EV_VMTM_BEGIN + 7)  /* 定时器7事件 */
#define EV_TIMER8EXPIRY             (WORD16)(EV_VMTM_BEGIN + 8)  /* 定时器8事件 */
#define EV_TIMER9EXPIRY             (WORD16)(EV_VMTM_BEGIN + 9)  /* 定时器9事件 */
#define EV_TIMER10EXPIRY            (WORD16)(EV_VMTM_BEGIN + 10) /* 定时器10事件 */
#define EV_TIMER11EXPIRY            (WORD16)(EV_VMTM_BEGIN + 11) /* 定时器11事件 */
#define EV_TIMER12EXPIRY            (WORD16)(EV_VMTM_BEGIN + 12) /* 定时器12事件 */
#define EV_TIMER13EXPIRY            (WORD16)(EV_VMTM_BEGIN + 13) /* 定时器13事件 */
#define EV_TIMER14EXPIRY            (WORD16)(EV_VMTM_BEGIN + 14) /* 定时器14事件 */
#define EV_TIMER15EXPIRY            (WORD16)(EV_VMTM_BEGIN + 15) /* 定时器15事件 */
#define EV_TIMER16EXPIRY            (WORD16)(EV_VMTM_BEGIN + 16) /* 定时器16事件 */
#define EV_TIMER17EXPIRY            (WORD16)(EV_VMTM_BEGIN + 17) /* 定时器17事件 */
#define EV_TIMER18EXPIRY            (WORD16)(EV_VMTM_BEGIN + 18) /* 定时器18事件 */
#define EV_TIMER19EXPIRY            (WORD16)(EV_VMTM_BEGIN + 19) /* 定时器19事件 */
#define EV_TIMER20EXPIRY            (WORD16)(EV_VMTM_BEGIN + 20) /* 定时器20事件 */
#define EV_TIMER21EXPIRY            (WORD16)(EV_VMTM_BEGIN + 21) /* 定时器21事件 */
#define EV_TIMER22EXPIRY            (WORD16)(EV_VMTM_BEGIN + 22) /* 定时器22事件 */
#define EV_TIMER23EXPIRY            (WORD16)(EV_VMTM_BEGIN + 23) /* 定时器23事件 */
#define EV_TIMER24EXPIRY            (WORD16)(EV_VMTM_BEGIN + 24) /* 定时器24事件 */
#define EV_TIMER25EXPIRY            (WORD16)(EV_VMTM_BEGIN + 25) /* 定时器25事件 */
#define EV_TIMER26EXPIRY            (WORD16)(EV_VMTM_BEGIN + 26) /* 定时器26事件 */
#define EV_TIMER27EXPIRY            (WORD16)(EV_VMTM_BEGIN + 27) /* 定时器27事件 */
#define EV_TIMER28EXPIRY            (WORD16)(EV_VMTM_BEGIN + 28) /* 定时器28事件 */
#define EV_TIMER29EXPIRY            (WORD16)(EV_VMTM_BEGIN + 29) /* 定时器29事件 */
#define EV_TIMER30EXPIRY            (WORD16)(EV_VMTM_BEGIN + 30) /* 定时器30事件 */
#define EV_TIMER31EXPIRY            (WORD16)(EV_VMTM_BEGIN + 31) /* 定时器30事件 */

#define EV_CLOCK_ADJUST_RPT         (WORD16)(EV_VMTM_BEGIN + 100) /* 软时钟调整报告 */
#define EV_VMTM_END                 (WORD16)1300    /* 定时器事件结束值 */



/****************************************
 * 上层应用的事件好划分                 *
 ****************************************/
#define EV_APP_BEGIN             	(WORD16)(10000)
#define EV_DB_BEGIN             	(WORD16)(EV_APP_BEGIN + 0000)
#define EV_DEVM_BEGIN             	(WORD16)(EV_APP_BEGIN + 1000)
#define EV_USRM_BEGIN             	(WORD16)(EV_APP_BEGIN + 2000)
#define EV_OMA_BEGIN             	(WORD16)(EV_APP_BEGIN + 3000)
#define EV_CW_BEGIN             	(WORD16)(EV_APP_BEGIN + 4000)
#define EV_HOSTAPD_BEGIN            (WORD16)(EV_APP_BEGIN + 5000)
#define EV_LCS_BEGIN             	(WORD16)(EV_APP_BEGIN + 6000)
#define EV_ACM_BEGIN             	(WORD16)(EV_APP_BEGIN + 7000)

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
#define EV_LICENSE_BEGIN             	(WORD16)(EV_APP_BEGIN + 12000)
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */

#endif /* _OSSEVENT_H_ */
