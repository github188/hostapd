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
    DWORD			ulCurrNodeNum;      /* ��ǰ�ڵ��� */
    DWORD           ulMaxNodeNum;       /* ��������ڵ��� */

	TREE_NODE_T		stRoot;				/* ��Ԫ */
	TREE_NODE_T		stLeft;				/* ��Ԫ */
	TREE_NODE_T		stRight;			/* ��Ԫ */

    DWORD           ulKeyFieldOffset;   /* ���������ݼ�¼�е�ƫ�����������ֶα����������ģ� */
    DWORD           ulKeyFieldLen;		/* �������� */
    KEY_COMP_FUNC   *pfKeyCompFunc;     /* �����ȽϺ��� */
	INDEX_BYTE_FUNC	*pfIndexByteFunc;   /* ��ȡ������ĳһ��λ�õĺ��� */

    ALLOC_NODE_FUNC *pfAllocNodeFunc;   /* ����ڵ�ĺ��� */
    FREE_NODE_FUNC  *pfFreeNodeFunc;    /* �ͷŽڵ�ĺ��� */

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
