/******************************************************************************
ģ����      : VMTM
�ļ���      : OssVmtm.h
����ļ�    :
ʵ�ֹ���    : VMTM ��������,���Ͷ���
�޸ļ�¼    :
------------------------------------------------------------------------------
����        �޸���      �޸�����
2008/05/27  ����ƽ      ����
******************************************************************************/
#ifndef _OSSVMTM_H_
#define _OSSVMTM_H_

/* ��ʱ���ı�ţ���Ϊ��Ҫ�붨ʱ�¼��Ź�������ֵ�����޸� */

#define TIMER0              (BYTE)0     /* ��ʱ��0 */
#define TIMER1              (BYTE)1     /* ��ʱ��1 */
#define TIMER2              (BYTE)2     /* ��ʱ��2 */
#define TIMER3              (BYTE)3     /* ��ʱ��3 */
#define TIMER4              (BYTE)4     /* ��ʱ��4 */
#define TIMER5              (BYTE)5     /* ��ʱ��5 */
#define TIMER6              (BYTE)6     /* ��ʱ��6 */
#define TIMER7              (BYTE)7     /* ��ʱ��7 */
#define TIMER8              (BYTE)8     /* ��ʱ��8 */    
#define TIMER9              (BYTE)9     /* ��ʱ��9 */
#define TIMER10             (BYTE)10    /* ��ʱ��10 */
#define TIMER11             (BYTE)11    /* ��ʱ��11 */
#define TIMER12             (BYTE)12    /* ��ʱ��12 */
#define TIMER13             (BYTE)13    /* ��ʱ��13 */
#define TIMER14             (BYTE)14    /* ��ʱ��14 */
#define TIMER15             (BYTE)15    /* ��ʱ��15 */
#define TIMER16             (BYTE)16    /* ��ʱ��16 */
#define TIMER17             (BYTE)17    /* ��ʱ��17 */
#define TIMER18             (BYTE)18    /* ��ʱ��18 */
#define TIMER19             (BYTE)19    /* ��ʱ��19 */
#define TIMER20             (BYTE)20    /* ��ʱ��20 */
#define TIMER21             (BYTE)21    /* ��ʱ��21 */
#define TIMER22             (BYTE)22    /* ��ʱ��22 */
#define TIMER23             (BYTE)23    /* ��ʱ��23 */
#define TIMER24             (BYTE)24    /* ��ʱ��24 */
#define TIMER25             (BYTE)25    /* ��ʱ��25 */
#define TIMER26             (BYTE)26    /* ��ʱ��26 */
#define TIMER27             (BYTE)27    /* ��ʱ��27 */
#define TIMER28             (BYTE)28    /* ��ʱ��28 */
#define TIMER29             (BYTE)29    /* ��ʱ��29 */
#define TIMER30             (BYTE)30    /* ��ʱ��30 */
#define TIMER31             (BYTE)31    /* ��ʱ��31 */

#define TID_ERROR           (WORD16) 0xFFFF /* ����TIDֵ */

/****************************************
 * ��ʱ����Ϣ                           *
 ****************************************/
#define EV_VMTM_BEGIN               (WORD16)1000
/* ���¶�ʱ�¼��ŵĶ�����Ҫ�� TIMER0... ������ */
#define EV_TIMER0             (WORD16)(EV_VMTM_BEGIN + 0)  /* ��ʱ��0�¼� */
#define EV_TIMER1             (WORD16)(EV_VMTM_BEGIN + 1)  /* ��ʱ��1�¼� */
#define EV_TIMER2             (WORD16)(EV_VMTM_BEGIN + 2)  /* ��ʱ��2�¼� */
#define EV_TIMER3             (WORD16)(EV_VMTM_BEGIN + 3)  /* ��ʱ��3�¼� */
#define EV_TIMER4             (WORD16)(EV_VMTM_BEGIN + 4)  /* ��ʱ��4�¼� */
#define EV_TIMER5             (WORD16)(EV_VMTM_BEGIN + 5)  /* ��ʱ��5�¼� */
#define EV_TIMER6             (WORD16)(EV_VMTM_BEGIN + 6)  /* ��ʱ��6�¼� */
#define EV_TIMER7             (WORD16)(EV_VMTM_BEGIN + 7)  /* ��ʱ��7�¼� */
#define EV_TIMER8             (WORD16)(EV_VMTM_BEGIN + 8)  /* ��ʱ��8�¼� */
#define EV_TIMER9             (WORD16)(EV_VMTM_BEGIN + 9)  /* ��ʱ��9�¼� */
#define EV_TIMER10            (WORD16)(EV_VMTM_BEGIN + 10) /* ��ʱ��10�¼� */
#define EV_TIMER11            (WORD16)(EV_VMTM_BEGIN + 11) /* ��ʱ��11�¼� */
#define EV_TIMER12            (WORD16)(EV_VMTM_BEGIN + 12) /* ��ʱ��12�¼� */
#define EV_TIMER13            (WORD16)(EV_VMTM_BEGIN + 13) /* ��ʱ��13�¼� */
#define EV_TIMER14            (WORD16)(EV_VMTM_BEGIN + 14) /* ��ʱ��14�¼� */
#define EV_TIMER15            (WORD16)(EV_VMTM_BEGIN + 15) /* ��ʱ��15�¼� */
#define EV_TIMER16            (WORD16)(EV_VMTM_BEGIN + 16) /* ��ʱ��16�¼� */
#define EV_TIMER17            (WORD16)(EV_VMTM_BEGIN + 17) /* ��ʱ��17�¼� */
#define EV_TIMER18            (WORD16)(EV_VMTM_BEGIN + 18) /* ��ʱ��18�¼� */
#define EV_TIMER19            (WORD16)(EV_VMTM_BEGIN + 19) /* ��ʱ��19�¼� */
#define EV_TIMER20            (WORD16)(EV_VMTM_BEGIN + 20) /* ��ʱ��20�¼� */
#define EV_TIMER21            (WORD16)(EV_VMTM_BEGIN + 21) /* ��ʱ��21�¼� */
#define EV_TIMER22            (WORD16)(EV_VMTM_BEGIN + 22) /* ��ʱ��22�¼� */
#define EV_TIMER23            (WORD16)(EV_VMTM_BEGIN + 23) /* ��ʱ��23�¼� */
#define EV_TIMER24            (WORD16)(EV_VMTM_BEGIN + 24) /* ��ʱ��24�¼� */
#define EV_TIMER25            (WORD16)(EV_VMTM_BEGIN + 25) /* ��ʱ��25�¼� */
#define EV_TIMER26            (WORD16)(EV_VMTM_BEGIN + 26) /* ��ʱ��26�¼� */
#define EV_TIMER27            (WORD16)(EV_VMTM_BEGIN + 27) /* ��ʱ��27�¼� */
#define EV_TIMER28            (WORD16)(EV_VMTM_BEGIN + 28) /* ��ʱ��28�¼� */
#define EV_TIMER29            (WORD16)(EV_VMTM_BEGIN + 29) /* ��ʱ��29�¼� */
#define EV_TIMER30            (WORD16)(EV_VMTM_BEGIN + 30) /* ��ʱ��30�¼� */
#define EV_TIMER31            (WORD16)(EV_VMTM_BEGIN + 31) /* ��ʱ��30�¼� */


typedef struct
{
    WORD32      dwExtra;        /* ���Ӳ��� */
    BYTE        byTimerNo;      /* ��ʱ���� */
    WORD16      wTid;           /* ��ʱ��ID */
    WORD16      wInst;          /* ʵ���� */
} TTimerEventStruc;

BOOL    TmRetAsynTMCB   (TMsgStruc *lptMsg);
VOID    SetSoftClock    (TClockStruc *SoftClock);
WORD16  VmSetTimer      (WORD32 dwCount100ms, BYTE byTimerNo);

WORD16  VmSetTimerEx    (WORD32 dwCount100ms,
                         BYTE byTimerNo,
                         WORD32 dwExtra
                        );

WORD16  VmSetAbsTimer   (TClockStruc  *lptClockPtr,
                         BYTE byTimerNo
                        );

WORD16  VmSetAbsTimerEx (TClockStruc  *lptClockPtr,
                         BYTE byTimerNo,
                         WORD32 dwExtra
                        );

BOOL    VmKillTimer     (BYTE byTimerNo);
BOOL    VmKillTimerEx   (WORD16 wTid);

WORD32  VmCurrentTick   (VOID);
VOID    VmCurrentClock  (TClockStruc  *lptClockPtr);
VOID    VmNextDay       (TClockStruc *ptClock);

#endif /* _OSSVMTM_H_ */

