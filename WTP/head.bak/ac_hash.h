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
    HASH_NODE_T     stHashNode;     /* ��Ԫ */
}HASH_ENTRY_T;

#define COMP_DIFF       0
#define COMP_SAME       1
#define COMP_SMALL      2
#define COMP_LARGE      3

typedef struct
{
    UINT32          ulHashEntrySize;    /* hashͰ��С */
    HASH_ENTRY_T    *pstHashEntry;      /* hashͰ��������������ַ */

    //UINT32          ulHashNodeSize;
    UINT32          ulCurrNodeNum;      /* ��ǰ�ڵ��� */       
    UINT32          ulMaxNodeNum;       /* ��������ڵ��� */       

    //HASH_NODE_T     stHashNodeFreeHead; /* ��pstNextָ��Free Head */
    //HASH_NODE_T     stHashNodeFreeTail; /* ��pstPrevָ��Free Tail */
    //HASH_NODE_T     stHashNodeUsedHead; /* ��pstPrevָ��Used Head */
    //HASH_NODE_T     stHashNodeUsedTail; /* ��pstPrevָ��Used Tail */

    //HASH_NODE_T     *pstHashNode;

    UINT32          ulKeyFieldOffset;   /* ���������ݼ�¼�е�ƫ�����������ֶα����������ģ� */
    HASH_FUNC       *pfHashFunc;        /* Hash���� */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* �����ȽϺ��� */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* ����ڵ�ĺ��� */    
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* �ͷŽڵ�ĺ��� */    
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
