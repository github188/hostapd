/******************************************************************************
ģ����      : VM
�ļ���      : OssVm.h
����ļ�    :
ʵ�ֹ���    : VM ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSVM_H_
#define _OSSVM_H_

#define INVALID_AC_ID       (WORD) 0
#define INVALID_AP_ID       (WORD) 0xffff

/* ����ԭ�� */
#define VM_RESET_NORMAL             (INT)0              /* RESETԭ���������� */
#define VM_RESET_POWERON_FAILURE    (INT)4              /* RESETԭ��, ���������ϵ�ʧ�� */
#define VM_RESET_INVALID_VERSION    (INT)5              /* RESETԭ����Ч�汾 */
#define VM_RESET_DATA_SYNC_FAIL     (INT)6              /* RESETԭ������ͬ��ʧ�� */
#define VM_RESET_BY_OMCR            (INT)7              /* RESETԭ�򣬺�̨�������� */
#define VM_RESET_UPLINK_BREAK       (INT)8              /* RESETԭ��, ��ⲻ���ϲ�CPU */
#define VM_RESET_ADDR_MISSED        (INT)9              /* RESETԭ��, �����ַ���ڵ�ַ���� */
#define VM_RESET_UPCPU_POWERON      (INT)10             /* RESETԭ��, �ϼ�CPU���� */
#define VM_RESET_BY_CPUBLOCK        (INT)12             /* RESETԭ��, CPU������ */
#define VM_RESET_SELFOFFLINE        (INT)13             /* RESETԭ��, ����ͨѶ�� */
#define VM_RESET_PROC_CHECK_FAIL	(INT)14		/* RESETԭ��, Ӧ�ý��̱���ʧ��*/

/* ϵͳ���н׶� */
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


/* �������� */
BOOL    VmInit              (VOID);            /* VM ��ʼ�� */
BOOL    VmStart             (VOID);            /* Vm ���� */

WORD32  VmCreateLock        (VOID);
BOOL    VmDeleteLock        (WORD32);
BOOL    VmLock              (WORD32, WORD32);
BOOL    VmUnLock            (WORD32 );
VOID    VmReset             (INT iReason);
BOOL    CheckAddrTable (VOID);
#endif /* _OSSVM_H_ */
