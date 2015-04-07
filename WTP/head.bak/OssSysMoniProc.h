/******************************************************************************
ģ����      : SYSCTL
�ļ���      : OssSysMoniProc
����ļ�    :
ʵ�ֹ���    : ϵͳ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/10/30  ������      ����
******************************************************************************/

#ifndef _OSSSYSMONIPROC_H_
#define _OSSSYSMONIPROC_H_

/* �궨��*/
#define SYS_PROC_MONI_NUM_MAX		16		/* ����ؽ�����*/
/* 2009-11-5 pyy 12-->24 */
/* 2011-1-26 24-->48 */
/* 2011-5-20 pyy: 48-->120 �޸�Ϊ120��, ���ʱ���޸�Ϊ10����*/
#define SYS_PROC_LOST_ECHO_NUM_MAX	120		/* �������ʧ�ı�����������޸�Ϊ120��*/

/* ��ʱ��ʱ��: ��λΪ100ms*/
#define 	SYS_TIMERLEN_MONI_INIT			6000		/* �ȴ������̳߳�ʼ����ʱ��ʱ��*/
#define 	SYS_TIMERLEN_MONI_PRD			50		/* �����Լ�鶨ʱ��ʱ��*/
#define	SYS_TIMERLEN_SETMONIFLAG_PRD	50		/* ������дpowerac״̬���λ��ʱ��ʱ��*/

#define	SYS_TIMER_MONI_INIT				TIMER1
#define	SYS_TIMER_MONI_PRD				TIMER2
#define	SYS_TIMER_SETMONIFLAG_PRD		TIMER3

#define	SYS_TIMEROUT_MONI_INIT_MSG		EV_TIMER1
#define	SYS_TIMEROUT_MONI_PRD_MSG		EV_TIMER2
#define	SYS_TIMEROUT_SETMONIFLAG_MSG	EV_TIMER3


#define SYS_MONI_FILE_NAME_LEN	128				/* ����ļ�������*/

#define SYS_CPULOAD_HIGH_THRESHOLD	    		80			/* CPU������:80% */	
#define SYS_CPULOAD_THRESHOLD_RANGE	    		5			/* 5% */
#define SYS_CPULOAD_HIGH_THRESHOLD_NUM		5			/* ���CPUʹ��������5�γ������ޣ��򽵵ʹ�ӡ���� */

/* �ṹ�嶨��*/
typedef struct {
	WORD32	ulUsed;
	WORD32	ulEchoNum;							/* ����δ�ظ��ı��������*/
	WORD16  usPno;								/* ���̺�*/
	CHAR    acProcName[PROC_NAME_LENGTH];		/* ������*/
	BYTE	aucRsv[1];							/* ����ֽ�*/
	WORD32	ulLastRunNum;						/*  ǰһ�α����ȵĴ���*/
} SYS_PROC_MONI_INFO_T;


/* ��������*/
WORD32	oss_sys_moni_init(VOID);
VOID oss_sys_moni_get_cpu_usage (VOID);
VOID oss_sys_moni_check_cpu_usage (VOID);
VOID oss_sys_moni_check_proc (VOID);
VOID oss_sys_moni_set_moniflag (VOID);
WORD32	oss_sys_moni_timeout_moni_init(VOID);
WORD32	oss_sys_moni_timeout_moni_prd(VOID);
WORD32	oss_sys_moni_recv_echo_rsp(VOID);

#endif
