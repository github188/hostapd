/******************************************************************************
ģ����      : SYSCTL
�ļ���      : OssSysPoweron
����ļ�    :
ʵ�ֹ���    : �ϵ����
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSSYSPOWERON_H_
#define _OSSSYSPOWERON_H_

#define BASE_PROC_NUM       (WORD16) 20    /* �������̵ĸ��� */
#define LAST_PROC_NUM       (WORD16) 10    /* ĩβ���̵ĸ��� */
#define PO_CONTINUE         (BYTE) 0       /* ��ʱ����� */
#define PO_RESET            (BYTE) 1       /* ��ʱ������ */
#define PO_WAIT             (BYTE) 2       /* ��ʱ��ȴ� */

BOOL VmPowerOnAck (BOOL bState);

#endif
