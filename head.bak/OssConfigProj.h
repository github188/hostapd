/******************************************************************************
ģ����      : SYSCFG
�ļ���      : OssConfigProj.h
����ļ�    :
ʵ�ֹ���    : �������õ�ͷ�ļ�
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/

#ifndef _OSSCONFIGPROJ_H_
#define _OSSCONFIGPROJ_H_


/***************************************************************************
----------------------------------------------------------------------------
    SECTION1:    �ⲿ��������
----------------------------------------------------------------------------
****************************************************************************/
/*========BEGIN: OSS��������========*/
/* ������� */
extern VOID ScheTaskEntry               (VOID*);

/* ��ʱ������� */
extern VOID LogSave_Timer               (VOID);

/* ������� */
extern VOID PowerOnCtlProc              (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID IpTableProc                 (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID ConnCheckProc               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID OssTestProc1               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
extern VOID OssTestProc2               (WORD16, LPBYTE, WORD16, LPBYTE, WORD16, LPBYTE);
/*========END: OSS��������========*/


/*========BEGIN: APP������ں�������========*/



#endif /* _OSSCONFIGBOARD_H_ */
