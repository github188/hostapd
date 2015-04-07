#ifndef AC_SORT_QUEUE_H
#define AC_SORT_QUEUE_H

#include "ac_hash.h"

typedef struct SORT_NODE_T
{
    VOID                *pData;
    struct SORT_NODE_T  *pstPrev;
    struct SORT_NODE_T  *pstNext;
}SORT_NODE_T;

typedef struct
{
    UINT32          ulMaxNodeNum;       /* 允许的最大节点数 */
    UINT32          ulCurrNodeNum;      /* 当前节点数 */

    SORT_NODE_T     stHeadNode;         /* 哑元：头 */
    SORT_NODE_T     stTailNode;         /* 哑元：尾 */

    UINT32          ulKeyFieldOffset;   /* 主键在数据记录中的偏移量（主键字段必须是连续的） */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* 主键比较函数 */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* 申请节点的函数 */    
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* 释放节点的函数 */    
}SORT_QUEUE_T;

BOOL    VmInitSortQueue     (SORT_QUEUE_T       *pstQueue, 
                             UINT32             ulMaxNodeNum, 
                             UINT32             ulKeyFieldOffset,  
                             KEY_COMP_FUNC      *pfKeyCompFunc,
                             ALLOC_NODE_FUNC    *pfAlocNodeFunc,
                             FREE_NODE_FUNC     *pfFreeNodeFunc);
VOID*   VmAddSortNode       (SORT_QUEUE_T *pstQueue, VOID* pData);
VOID*   VmGetSortNodeData   (SORT_QUEUE_T *pstQueue, VOID* pKey);
BOOL    VmRemoveSortNode    (SORT_QUEUE_T *pstQueue, VOID* pKey);
VOID    VmDeleteSortNode    (SORT_QUEUE_T *pstQueue, SORT_NODE_T *pstNode);
SORT_NODE_T* VmGetSortNode  (SORT_QUEUE_T *pstQueue, VOID* pKey);

#endif

