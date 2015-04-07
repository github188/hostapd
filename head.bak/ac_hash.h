#ifndef AC_HASH_H
#define AC_HASH_H

typedef UINT32  (HASH_FUNC)(VOID* pKey);
typedef UINT32  (KEY_COMP_FUNC)(VOID* pSrcKey, VOID *pDestKey);
typedef VOID*   (ALLOC_NODE_FUNC)(VOID* pData);
typedef VOID    (FREE_NODE_FUNC)(VOID* pData);

typedef struct HASH_NODE_T
{
    VOID                *pData;
    struct HASH_NODE_T  *pstPrev;
    struct HASH_NODE_T  *pstNext;
}HASH_NODE_T;

#define INVALID_HASH_VALUE      ((UINT32)(-1))
typedef struct
{
    HASH_NODE_T     stHashNode;     /* 哑元 */
}HASH_ENTRY_T;

#define COMP_DIFF       0
#define COMP_SAME       1
#define COMP_SMALL      2
#define COMP_LARGE      3

typedef struct
{
    UINT32          ulHashEntrySize;    /* hash桶大小 */
    HASH_ENTRY_T    *pstHashEntry;      /* hash桶，必须是连续地址 */

    //UINT32          ulHashNodeSize;
    UINT32          ulCurrNodeNum;      /* 当前节点数 */       
    UINT32          ulMaxNodeNum;       /* 允许的最大节点数 */       

    //HASH_NODE_T     stHashNodeFreeHead; /* 其pstNext指向Free Head */
    //HASH_NODE_T     stHashNodeFreeTail; /* 其pstPrev指向Free Tail */
    //HASH_NODE_T     stHashNodeUsedHead; /* 其pstPrev指向Used Head */
    //HASH_NODE_T     stHashNodeUsedTail; /* 其pstPrev指向Used Tail */

    //HASH_NODE_T     *pstHashNode;

    UINT32          ulKeyFieldOffset;   /* 主键在数据记录中的偏移量（主键字段必须是连续的） */
    HASH_FUNC       *pfHashFunc;        /* Hash函数 */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* 主键比较函数 */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* 申请节点的函数 */    
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* 释放节点的函数 */    
}HASH_INFO_T;

BOOL    VmInitHashInfo      (HASH_INFO_T        *pstHashInfo, 
                             UINT32             ulHashEntrySize, 
                             UINT32             ulMaxNodeNum, 
                             UINT32             ulKeyFieldOffset,  
                             HASH_FUNC          *pfHashFunc,  
                             KEY_COMP_FUNC      *pfKeyCompFunc,
                             ALLOC_NODE_FUNC    *pfAllocNodeFunc,
                             FREE_NODE_FUNC     *pfFreeNodeFunc);
BOOL    VmSetHashMaxNodeNum (HASH_INFO_T *pstHashInfo, UINT32 ulMaxNodeNum);
BOOL    VmSetHashEntrySize(HASH_INFO_T *pstHashInfo, UINT32 ulEntrySize);
VOID*   VmAddHashNode       (HASH_INFO_T *pstHashInfo, VOID* pData);
VOID*   VmGetHashNodeData   (HASH_INFO_T *pstHashInfo, VOID* pKey);
BOOL    VmRemoveHashNode    (HASH_INFO_T *pstHashInfo, VOID* pKey/*, BOOL bFreeData*/);
BOOL	VmRandomRemoveHashNode(HASH_INFO_T *pstHashInfo);
HASH_NODE_T* VmGetHashNode  (HASH_INFO_T *pstHashInfo, VOID* pKey);

#endif
