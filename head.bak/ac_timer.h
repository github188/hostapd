#ifndef AC_TIMER_QUEUE_H
#define AC_TIMER_QUEUE_H

#include "ac_sort_queue.h"

#define AC_INVALID_TIMER_ID     {0xffffffff,0xffffffff}

/*
typedef union 
{
	UINT32				ulData;
	VOID*				pData;
}TIMER_EXTRA_T;
*/

typedef struct 
{
	UINT32				ulDeadTime;
	UINT32				ulSn;
}TIMER_ID_T;

//typedef VOID (TIMEROUT_FUNC)(TIMER_EXTRA_U unTimerData, UINT32 ulSize);
typedef VOID (TIMEROUT_FUNC)(VOID* pTimerData, UINT32 ulSize);

typedef struct 
{
	TIMER_ID_T			stTimerID;
	//TIMER_EXTRA_U		unTimerData;
    VOID*               pTimerData;     /* 自动申请和释放 */
    TIMEROUT_FUNC       *pfTimeroutFunc;
}TIMER_DATA_T;

typedef struct 
{
    SORT_QUEUE_T		stSortQueue;

    UINT32				ulSn;
    UINT32				ulLastTime;

	UINT8				ucTimerNo;
    UINT16              usTimerID;
    TIMEROUT_FUNC		*pfTimeroutFunc;
}TIMER_QUEUE_T;

VOID    VmInitTimerID       (TIMER_ID_T *pstTimerID);
BOOL	VmIsValidTimerID    (TIMER_ID_T stTimerID);
BOOL    VmInitTimerQueue    (TIMER_QUEUE_T *pstTimerQueue, 
                             UINT32        ulMaxNodeNum,
                             UINT8         ucTimerNo,
                             TIMEROUT_FUNC *pfTimeroutFunc);
TIMER_ID_T VmAddTimer       (TIMER_QUEUE_T *pstTimerQueue, UINT32 ul100ms, 
                             VOID* pTimeData, UINT32 ulTimeDataLen,
                             TIMEROUT_FUNC *pfTimeroutFunc);
BOOL    VmRemoveTimer       (TIMER_QUEUE_T *pstQueue, TIMER_ID_T stTimerID);
VOID*   VmGetExtTimerData   (TIMER_QUEUE_T *pstTimerQueue, TIMER_ID_T stTimerID);

#endif

