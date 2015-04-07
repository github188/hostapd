#ifndef AC_OMA_QUEUE_H
#define AC_OMA_QUEUE_H

#define NODE_STATUS_FREE        0
#define NODE_STATUS_INUSE       1

typedef struct omaQueueNode
{
    struct omaQueueNode 	*next;
    struct omaQueueNode 	*prev;
    
    /* new add */
    struct omaQueueNode     *hashNext;
    struct omaQueueNode     *hashPrev;

    UINT32              	lastSendTime;   /* the lastest time the msg send in second */
    CHAR                	*data;          /* point to the node data */
} AC_OMA_QUEUE_NODE_T;

typedef int (*COMPARE_NODE_FUNC)(VOID* source, VOID* dest);

/* new add */
typedef UINT32 (*CALCULATE_HASHKEY_FUNC)(const CHAR *data, UINT32 nodeNum);

typedef struct
{
    AC_OMA_QUEUE_NODE_T     freeHead;   /* head of free node list */
    AC_OMA_QUEUE_NODE_T     freeTail;   /* tail of free node list */

    AC_OMA_QUEUE_NODE_T     usedHead;   /* tail of used node list */
    AC_OMA_QUEUE_NODE_T  	usedTail;   /* tail of used node list */

    UINT32       			msgType;    /* MSG_ALARM / MSG_EVENT/ MSG_PERF */
    COMPARE_NODE_FUNC   	compareNode;/* compare the node */

    UINT32       			nodeNum;
    UINT32       			dataSize;   /* size of msg */
    AC_OMA_QUEUE_NODE_T     *nodeList;  /* node list for queue */
    CHAR                	*dataList;  /* node data list for queue */

    /* new add */
    CALCULATE_HASHKEY_FUNC  calculateHashKey;  /* calculate node hash key function */
    AC_OMA_QUEUE_NODE_T     *hashNodeList;     /* node list for hash table */

	UINT32					usedNum;		/* used node number */

    UINT32                  maxSendRate;    /* 单位时间（秒）内发送的最大包个数 */
} AC_OMA_QUEUE_T;

AC_RET ac_oma_init_queue(AC_OMA_QUEUE_T *queue, UINT32 nodeNum, UINT32 dataSize,
                         UINT32 ulQueueType, UINT32 ulMaxSendRate,
                         COMPARE_NODE_FUNC compareNodeFunc,
                         CALCULATE_HASHKEY_FUNC calculateHashKeyFunc);
AC_RET ac_oma_add_node_to_queue(AC_OMA_QUEUE_T *queue, const CHAR* msg);
AC_RET ac_oma_remove_node_from_queue(AC_OMA_QUEUE_T *queue, CHAR* msg);
AC_RET ac_oma_resend_queue_msg(const AC_OMA_QUEUE_T *queue);
AC_RET ac_oma_send_queue_node_msg(UINT32 msgType, AC_OMA_QUEUE_NODE_T *node);

/* new add */
AC_RET ac_oma_send_queue_node_msg_batch(UINT32 ulMsgType, UINT32 ulNum, AC_OMA_QUEUE_NODE_T ** ppstNode);

AC_RET ac_oma_send_queue_msg(UINT32 msgType, CHAR* msg);

#endif /* AC_OMA_QUEUE_H */



