/******************************************************************************
ģ����      : VMMM
�ļ���      : OssVmmm.h
����ļ�    :
ʵ�ֹ���    : VMMM ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/
#ifndef _OSSVMMM_H_
#define _OSSVMMM_H_

#define VMMM_ERROR        (WORD32) 0xFFFFFFFF

// #define VMMM_TRACE_ON       /* MM ��غ꿪�� */

#ifdef _OSWIN32_
// #define VMMM_PROTECT_ON     /* MM�����꿪�� */
#endif
    
/*����ԭ�Ͷ���*/
#ifdef  VMMM_TRACE_ON
    #define  VmGetUB(dwSize)                TRACE_VmGetUB (dwSize, __FILE__, __LINE__)
    #define  MmGetEx(dwSize, dwTimeout)     TRACE_MmGetEx (dwSize, dwTimeout, __FILE__, __LINE__)
    #define  VmRetUB(lpbyPointer)           TRACE_VmRetUB (lpbyPointer, __FILE__, __LINE__)
    #define  VmGetUBNoWait(dwSize)          TRACE_VmGetUBNoWait (dwSize, __FILE__, __LINE__)
    #define  VmGetUBWait(dwSize, dwTimeout) TRACE_VmGetUBWait(dwSize, dwTimeout, __FILE__, __LINE__)
    BYTE*    TRACE_VmGetUB                  (WORD32 dwSize, CHAR *srcFile, INT srcLine);
    BOOL     TRACE_VmRetUB                  (LPBYTE lpbyPointer, CHAR *srcFile, INT srcLine);
    BYTE*    TRACE_MmGetEx                  (WORD32 dwSize, WORD32 dwTimeout, CHAR *srcFile, INT srcLine);
    BYTE*    TRACE_VmGetUBNoWait            (WORD32 dwSize, CHAR *srcFile, INT srcLine);
    BYTE*    TRACE_VmGetUBWait              (WORD32 dwSize, WORD32 dwTimeout, CHAR *srcFile, INT srcLine);
#else /* #ifdef  VMMM_TRACE_ON */
    #define  VmGetUB(dwSize)                TRACE_VmGetUB (dwSize)
    #define  MmGetEx(dwSize, dwTimeout)     TRACE_MmGetEx (dwSize, dwTimeout)
    #define  VmRetUB(lpbyPointer)           TRACE_VmRetUB (lpbyPointer)
    #define  VmGetUBNoWait(dwSize)          TRACE_VmGetUBNoWait (dwSize)
    #define  VmGetUBWait(dwSize, dwTimeout) TRACE_VmGetUBWait(dwSize, dwTimeout)
    BYTE*    TRACE_VmGetUB                  (WORD32 dwSize);
    BOOL     TRACE_VmRetUB                  (LPBYTE lpbyPointer);
    BYTE*    TRACE_MmGetEx                  (WORD32 dwSize, WORD32 dwTimeout);
    BYTE*    TRACE_VmGetUBNoWait            (WORD32 dwSize);
    BYTE*    TRACE_VmGetUBWait              (WORD32 dwSize, WORD32 dwTimeout);
#endif
    WORD32  VmGetUbUsage            (VOID);
    WORD32  VmGetPeakUbUsage        (VOID);
    VOID    *VmShmCreate            (WORD32 dwSize);
    BOOL    VmShmFree               (VOID *pAddr,WORD32 dwSize);
    BYTE    GetPoolCurrentPercent   (WORD16 wUBPool);
    BYTE    GetPoolHighPercent      (WORD16 wUBPool);
    WORD32  GetPoolFailNum          (WORD16 wUBPool);
    WORD16  GetMostBusyPool         (VOID);
    WORD32  MmGetAvailableUbSize    (VOID);
    WORD32  MmGetRealUbSize         (VOID);
    VOID*   MmStackMemAlloc         (WORD32 dwSize);
#endif /* end of _OSSVMMM_H_ */
