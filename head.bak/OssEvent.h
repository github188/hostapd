/******************************************************************************
ģ����      : VM
�ļ���      : OssEvent.h
����ļ�    :     
ʵ�ֹ���    : VM�¼�����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSEVENT_H_
#define _OSSEVENT_H_


/****************************************
 * [ϵͳ����ģ��] ���¼�����            *
 ****************************************/

#define EV_SYSCTRL_BEGIN            (WORD16)100

/* �ϵ���� */
#define EV_SYSCTRL_POWERON_BEGIN    (WORD16)(EV_SYSCTRL_BEGIN + 0)
#define EV_MASTER_POWERON           (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 0)
#define EV_POWERON_ACK              (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 4)
#define EV_ONLINE_REPORT            (WORD16)(EV_SYSCTRL_POWERON_BEGIN + 5)


/* ��·��� */
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

/* ������3��ǰ��̨��·����¼��ţ����Ҫ�޸ģ������̨��ԱЭ�� */
#define EV_BK_LINK_HELLO            	(WORD16) 170             /* ��̨��ǰ̨���͵���·����¼��� */
#define EV_BK_LINK_HELLO_ACK     	(WORD16) 171             /* ǰ̨����̨���͵���·���Ӧ�� */

#define EV_WEB_LINK_HELLO			(WORD16) 172		/* AC-WEB��AC���͵���·����¼���*/
#define EV_WEB_LINK_HELLO_ACK		(WORD16) 173		/* AC��AC-WEB���͵���·���Ӧ��*/

/* 2010-1-19 ����: ��������������Ϣ*/
#define EV_AC_MS_LINK_HELLO			(WORD16)(EV_SYSCTRL_CONN_BEGIN + 50)
#define EV_AC_MS_LINK_HELLO_ACK		(WORD16)(EV_SYSCTRL_CONN_BEGIN + 51)
#define EV_BAKACID_CHG_IND				(WORD16)(EV_SYSCTRL_CONN_BEGIN + 52)	/* �ӹ�AC ID �仯֪ͨ*/

#define EV_SYSCTRL_END              (WORD16)(EV_SYSCTRL_BEGIN + 800)


/****************************************
 * [��ʱ����ģ��] ���¼�����            *
 ****************************************/

#define EV_VMTM_BEGIN               (WORD16)1000

/* ���¶�ʱ�¼��ŵĶ�����Ҫ�� TIMER0... ������ */
#define EV_TIMER0EXPIRY             (WORD16)(EV_VMTM_BEGIN + 0)  /* ��ʱ��0�¼� */
#define EV_TIMER1EXPIRY             (WORD16)(EV_VMTM_BEGIN + 1)  /* ��ʱ��1�¼� */
#define EV_TIMER2EXPIRY             (WORD16)(EV_VMTM_BEGIN + 2)  /* ��ʱ��2�¼� */
#define EV_TIMER3EXPIRY             (WORD16)(EV_VMTM_BEGIN + 3)  /* ��ʱ��3�¼� */
#define EV_TIMER4EXPIRY             (WORD16)(EV_VMTM_BEGIN + 4)  /* ��ʱ��4�¼� */
#define EV_TIMER5EXPIRY             (WORD16)(EV_VMTM_BEGIN + 5)  /* ��ʱ��5�¼� */
#define EV_TIMER6EXPIRY             (WORD16)(EV_VMTM_BEGIN + 6)  /* ��ʱ��6�¼� */
#define EV_TIMER7EXPIRY             (WORD16)(EV_VMTM_BEGIN + 7)  /* ��ʱ��7�¼� */
#define EV_TIMER8EXPIRY             (WORD16)(EV_VMTM_BEGIN + 8)  /* ��ʱ��8�¼� */
#define EV_TIMER9EXPIRY             (WORD16)(EV_VMTM_BEGIN + 9)  /* ��ʱ��9�¼� */
#define EV_TIMER10EXPIRY            (WORD16)(EV_VMTM_BEGIN + 10) /* ��ʱ��10�¼� */
#define EV_TIMER11EXPIRY            (WORD16)(EV_VMTM_BEGIN + 11) /* ��ʱ��11�¼� */
#define EV_TIMER12EXPIRY            (WORD16)(EV_VMTM_BEGIN + 12) /* ��ʱ��12�¼� */
#define EV_TIMER13EXPIRY            (WORD16)(EV_VMTM_BEGIN + 13) /* ��ʱ��13�¼� */
#define EV_TIMER14EXPIRY            (WORD16)(EV_VMTM_BEGIN + 14) /* ��ʱ��14�¼� */
#define EV_TIMER15EXPIRY            (WORD16)(EV_VMTM_BEGIN + 15) /* ��ʱ��15�¼� */
#define EV_TIMER16EXPIRY            (WORD16)(EV_VMTM_BEGIN + 16) /* ��ʱ��16�¼� */
#define EV_TIMER17EXPIRY            (WORD16)(EV_VMTM_BEGIN + 17) /* ��ʱ��17�¼� */
#define EV_TIMER18EXPIRY            (WORD16)(EV_VMTM_BEGIN + 18) /* ��ʱ��18�¼� */
#define EV_TIMER19EXPIRY            (WORD16)(EV_VMTM_BEGIN + 19) /* ��ʱ��19�¼� */
#define EV_TIMER20EXPIRY            (WORD16)(EV_VMTM_BEGIN + 20) /* ��ʱ��20�¼� */
#define EV_TIMER21EXPIRY            (WORD16)(EV_VMTM_BEGIN + 21) /* ��ʱ��21�¼� */
#define EV_TIMER22EXPIRY            (WORD16)(EV_VMTM_BEGIN + 22) /* ��ʱ��22�¼� */
#define EV_TIMER23EXPIRY            (WORD16)(EV_VMTM_BEGIN + 23) /* ��ʱ��23�¼� */
#define EV_TIMER24EXPIRY            (WORD16)(EV_VMTM_BEGIN + 24) /* ��ʱ��24�¼� */
#define EV_TIMER25EXPIRY            (WORD16)(EV_VMTM_BEGIN + 25) /* ��ʱ��25�¼� */
#define EV_TIMER26EXPIRY            (WORD16)(EV_VMTM_BEGIN + 26) /* ��ʱ��26�¼� */
#define EV_TIMER27EXPIRY            (WORD16)(EV_VMTM_BEGIN + 27) /* ��ʱ��27�¼� */
#define EV_TIMER28EXPIRY            (WORD16)(EV_VMTM_BEGIN + 28) /* ��ʱ��28�¼� */
#define EV_TIMER29EXPIRY            (WORD16)(EV_VMTM_BEGIN + 29) /* ��ʱ��29�¼� */
#define EV_TIMER30EXPIRY            (WORD16)(EV_VMTM_BEGIN + 30) /* ��ʱ��30�¼� */
#define EV_TIMER31EXPIRY            (WORD16)(EV_VMTM_BEGIN + 31) /* ��ʱ��30�¼� */

#define EV_CLOCK_ADJUST_RPT         (WORD16)(EV_VMTM_BEGIN + 100) /* ��ʱ�ӵ������� */
#define EV_VMTM_END                 (WORD16)1300    /* ��ʱ���¼�����ֵ */



/****************************************
 * �ϲ�Ӧ�õ��¼��û���                 *
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

/* BEGIN: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */
#define EV_LICENSE_BEGIN             	(WORD16)(EV_APP_BEGIN + 12000)
/* END: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */

#endif /* _OSSEVENT_H_ */
