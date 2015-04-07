/******************************************************************************
模块名      : VMTM
文件名      : OssVmtm.h
相关文件    :
实现功能    : VMTM 基本常量,类型定义
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2008/05/27  李贤平      创建
******************************************************************************/
#ifndef _OSSVMTM_H_
#define _OSSVMTM_H_

/* 定时器的编号，因为需要与定时事件号关联，其值不能修改 */

#define TIMER0              (BYTE)0     /* 定时器0 */
#define TIMER1              (BYTE)1     /* 定时器1 */
#define TIMER2              (BYTE)2     /* 定时器2 */
#define TIMER3              (BYTE)3     /* 定时器3 */
#define TIMER4              (BYTE)4     /* 定时器4 */
#define TIMER5              (BYTE)5     /* 定时器5 */
#define TIMER6              (BYTE)6     /* 定时器6 */
#define TIMER7              (BYTE)7     /* 定时器7 */
#define TIMER8              (BYTE)8     /* 定时器8 */    
#define TIMER9              (BYTE)9     /* 定时器9 */
#define TIMER10             (BYTE)10    /* 定时器10 */
#define TIMER11             (BYTE)11    /* 定时器11 */
#define TIMER12             (BYTE)12    /* 定时器12 */
#define TIMER13             (BYTE)13    /* 定时器13 */
#define TIMER14             (BYTE)14    /* 定时器14 */
#define TIMER15             (BYTE)15    /* 定时器15 */
#define TIMER16             (BYTE)16    /* 定时器16 */
#define TIMER17             (BYTE)17    /* 定时器17 */
#define TIMER18             (BYTE)18    /* 定时器18 */
#define TIMER19             (BYTE)19    /* 定时器19 */
#define TIMER20             (BYTE)20    /* 定时器20 */
#define TIMER21             (BYTE)21    /* 定时器21 */
#define TIMER22             (BYTE)22    /* 定时器22 */
#define TIMER23             (BYTE)23    /* 定时器23 */
#define TIMER24             (BYTE)24    /* 定时器24 */
#define TIMER25             (BYTE)25    /* 定时器25 */
#define TIMER26             (BYTE)26    /* 定时器26 */
#define TIMER27             (BYTE)27    /* 定时器27 */
#define TIMER28             (BYTE)28    /* 定时器28 */
#define TIMER29             (BYTE)29    /* 定时器29 */
#define TIMER30             (BYTE)30    /* 定时器30 */
#define TIMER31             (BYTE)31    /* 定时器31 */

#define TID_ERROR           (WORD16) 0xFFFF /* 出错TID值 */

/****************************************
 * 定时器消息                           *
 ****************************************/
#define EV_VMTM_BEGIN               (WORD16)1000
/* 以下定时事件号的定义需要与 TIMER0... 关联上 */
#define EV_TIMER0             (WORD16)(EV_VMTM_BEGIN + 0)  /* 定时器0事件 */
#define EV_TIMER1             (WORD16)(EV_VMTM_BEGIN + 1)  /* 定时器1事件 */
#define EV_TIMER2             (WORD16)(EV_VMTM_BEGIN + 2)  /* 定时器2事件 */
#define EV_TIMER3             (WORD16)(EV_VMTM_BEGIN + 3)  /* 定时器3事件 */
#define EV_TIMER4             (WORD16)(EV_VMTM_BEGIN + 4)  /* 定时器4事件 */
#define EV_TIMER5             (WORD16)(EV_VMTM_BEGIN + 5)  /* 定时器5事件 */
#define EV_TIMER6             (WORD16)(EV_VMTM_BEGIN + 6)  /* 定时器6事件 */
#define EV_TIMER7             (WORD16)(EV_VMTM_BEGIN + 7)  /* 定时器7事件 */
#define EV_TIMER8             (WORD16)(EV_VMTM_BEGIN + 8)  /* 定时器8事件 */
#define EV_TIMER9             (WORD16)(EV_VMTM_BEGIN + 9)  /* 定时器9事件 */
#define EV_TIMER10            (WORD16)(EV_VMTM_BEGIN + 10) /* 定时器10事件 */
#define EV_TIMER11            (WORD16)(EV_VMTM_BEGIN + 11) /* 定时器11事件 */
#define EV_TIMER12            (WORD16)(EV_VMTM_BEGIN + 12) /* 定时器12事件 */
#define EV_TIMER13            (WORD16)(EV_VMTM_BEGIN + 13) /* 定时器13事件 */
#define EV_TIMER14            (WORD16)(EV_VMTM_BEGIN + 14) /* 定时器14事件 */
#define EV_TIMER15            (WORD16)(EV_VMTM_BEGIN + 15) /* 定时器15事件 */
#define EV_TIMER16            (WORD16)(EV_VMTM_BEGIN + 16) /* 定时器16事件 */
#define EV_TIMER17            (WORD16)(EV_VMTM_BEGIN + 17) /* 定时器17事件 */
#define EV_TIMER18            (WORD16)(EV_VMTM_BEGIN + 18) /* 定时器18事件 */
#define EV_TIMER19            (WORD16)(EV_VMTM_BEGIN + 19) /* 定时器19事件 */
#define EV_TIMER20            (WORD16)(EV_VMTM_BEGIN + 20) /* 定时器20事件 */
#define EV_TIMER21            (WORD16)(EV_VMTM_BEGIN + 21) /* 定时器21事件 */
#define EV_TIMER22            (WORD16)(EV_VMTM_BEGIN + 22) /* 定时器22事件 */
#define EV_TIMER23            (WORD16)(EV_VMTM_BEGIN + 23) /* 定时器23事件 */
#define EV_TIMER24            (WORD16)(EV_VMTM_BEGIN + 24) /* 定时器24事件 */
#define EV_TIMER25            (WORD16)(EV_VMTM_BEGIN + 25) /* 定时器25事件 */
#define EV_TIMER26            (WORD16)(EV_VMTM_BEGIN + 26) /* 定时器26事件 */
#define EV_TIMER27            (WORD16)(EV_VMTM_BEGIN + 27) /* 定时器27事件 */
#define EV_TIMER28            (WORD16)(EV_VMTM_BEGIN + 28) /* 定时器28事件 */
#define EV_TIMER29            (WORD16)(EV_VMTM_BEGIN + 29) /* 定时器29事件 */
#define EV_TIMER30            (WORD16)(EV_VMTM_BEGIN + 30) /* 定时器30事件 */
#define EV_TIMER31            (WORD16)(EV_VMTM_BEGIN + 31) /* 定时器30事件 */


typedef struct
{
    WORD32      dwExtra;        /* 附加参数 */
    BYTE        byTimerNo;      /* 定时器号 */
    WORD16      wTid;           /* 定时器ID */
    WORD16      wInst;          /* 实例号 */
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

