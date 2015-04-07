#ifndef AC_TREE_H
#define AC_TREE_H

#include "ac_hash.h"

typedef UINT8 INDEX_BYTE_FUNC(VOID* pucKey, UINT32 ulIndex);

typedef struct TREE_NODE_T
{
    VOID                *pData;

	struct TREE_NODE_T  *pstFather;
	struct TREE_NODE_T  *pstLeftSon;
	struct TREE_NODE_T  *pstRightSon;

	struct TREE_NODE_T  *pstLeft;
	struct TREE_NODE_T  *pstRight;
}TREE_NODE_T;

typedef struct
{
    DWORD			ulCurrNodeNum;      /* 当前节点数 */
    DWORD           ulMaxNodeNum;       /* 允许的最大节点数 */

	TREE_NODE_T		stRoot;				/* 哑元 */
	TREE_NODE_T		stLeft;				/* 哑元 */
	TREE_NODE_T		stRight;			/* 哑元 */

    DWORD           ulKeyFieldOffset;   /* 主键在数据记录中的偏移量（主键字段必须是连续的） */
    DWORD           ulKeyFieldLen;		/* 主键长度 */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* 主键比较函数 */
	INDEX_BYTE_FUNC	*pfIndexByteFunc;   /* 获取主键中某一个位置的函数 */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* 申请节点的函数 */
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* 释放节点的函数 */

}TREE_T;

BYTE	VmLongIndexFunc		(VOID* pKey, DWORD ulIndex);
BYTE	VmShortIndexFunc	(VOID* pKey, DWORD ulIndex);
BYTE	VmByteIndexFunc		(VOID* pKey, DWORD ulIndex);
BOOL    VmInitTree          (TREE_T				*pstTree,
                             DWORD              ulMaxNodeNum,
                             DWORD              ulKeyFieldOffset,
                             DWORD              ulKeyFieldLen,
                             KEY_COMP_FUNC      *pfKeyCompFunc,
							 INDEX_BYTE_FUNC	*pfIndexByteFunc,
                             ALLOC_NODE_FUNC    *pfAlocNodeFunc,
                             FREE_NODE_FUNC     *pfFreeNodeFunc);
VOID*   VmAddTreeNode       (TREE_T *pstTree, VOID* pData);
VOID*   VmGetTreeNodeData   (TREE_T *pstTree, VOID* pKey);
BOOL    VmRemoveTreeNode	(TREE_T *pstTree, VOID* pKey);

TREE_NODE_T* VmGetTreeNode  (TREE_T *pstTree, VOID* pKey);

#endif
