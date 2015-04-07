#ifndef OMA_QUEUE_H
#define OMA_QUEUE_H

#define NODE_STATUS_FREE        0
#define NODE_STATUS_INUSE       1

typedef struct omaQueueNode
{
    struct omaQueueNode *next;
    struct omaQueueNode *prev;
    unsigned long       lastSendTime;   /* the lastest time the msg send in second */
    char                *data;          /* point to the node data */
} T_omaQueueNode;

typedef int (*COMPARE_NODE_FUNC)(void* source, void* dest);

typedef struct
{
    T_omaQueueNode      freeHead;   /* head of free node list */
    T_omaQueueNode      freeTail;   /* tail of free node list */

    T_omaQueueNode      usedHead;   /* tail of used node list */
    T_omaQueueNode      usedTail;   /* tail of used node list */

    unsigned long       msgType;    /* TRAP_MSG_ALARM / TRAP_MSG_PERF */
    COMPARE_NODE_FUNC   compareNode;/* compare the node */

    unsigned long       nodeNum;
    unsigned long       dataSize;   /* size of msg */
    T_omaQueueNode      *nodeList;  /* node list for queue */
    char                *dataList;  /* node data list for queue */

    unsigned long       maxSendRate;/* max msg send perf scan period */
} T_omaQueue;

int initQueue(T_omaQueue *queue, unsigned long nodeNum, unsigned long dataSize,
              unsigned long msgType, unsigned long maxSendRate, COMPARE_NODE_FUNC  compareNodeFunc);
int addNodeToQueue(T_omaQueue *queue, char* msg);
int removeNodeFromQueue(T_omaQueue *queue, char* msg);
int resendQueueMsg(T_omaQueue *queue);
int omaSendQueueMsg(unsigned long msgType, T_omaQueueNode *node);
int omaSendTrapMsg(unsigned long msgType, char* msg);

#endif /* OMA_QUEUE_H */



