/******************************************************************************
* COPYRIGHT GBCOM
* 集中交换数据结构定义
*******************************************************************************
******************************************************************************/

#ifndef L2W_THREAD_H
#define L2W_THREAD_H

/******************************************************************************/
#define L2W_DATA	1

typedef struct _task
{
	u_int32_t time;
    	int type;

    	struct sockaddr stAddr;
    	
    	unsigned int data_len;
    	void *data;

    	struct _task *next;
	struct _task *prev;
}L2W_TASK_T;

struct kthread_t
{
	struct task_struct *thread;
	int running;
};


/* 数据结构定义结束*/
/******************************************************************************/

#endif

/******************************* end **********************************/

