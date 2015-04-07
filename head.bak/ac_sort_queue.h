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
    UINT32          ulMaxNodeNum;       /* ��������ڵ��� */
    UINT32          ulCurrNodeNum;      /* ��ǰ�ڵ��� */

    SORT_NODE_T     stHeadNode;         /* ��Ԫ��ͷ */
    SORT_NODE_T     stTailNode;         /* ��Ԫ��β */

    UINT32          ulKeyFieldOffset;   /* ���������ݼ�¼�е�ƫ�����������ֶα����������ģ� */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* �����ȽϺ��� */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* ����ڵ�ĺ��� */    
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* �ͷŽڵ�ĺ��� */    
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

