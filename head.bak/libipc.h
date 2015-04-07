/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  接纳控制模块公共头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _LOC_IPC_H
#define  _LOC_IPC_H

/******************************** 宏定义 *************************************/
/*
typedef char*   	STRING;
typedef void 		VOID;

typedef unsigned short WORD16;
typedef unsigned long WORD32;

typedef int BOOL;
typedef int INT;
typedef int LONG32, *PLONG32;
typedef char CHAR;
typedef char *PSTR;
typedef char *PCHAR;
typedef char *LPSTR;
typedef char *LPTSTR;
typedef unsigned char *PBYTE;
typedef unsigned char * LPBYTE;
typedef short SHORT;
typedef unsigned short *PWORD;
typedef unsigned short  *LPWORD;
typedef long LONG;
typedef unsigned long *PDWORD;
typedef unsigned long * LPDWORD;
typedef void  *LPVOID;
typedef unsigned char BYTE;
typedef void *HANDLE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef float FLOAT;
typedef double DOUBLE;
*/

#define	MSG_TASK_RESUME_REQ	(WORD)(0xFFFF-1)	/* 同步消息接收方用于解阻塞发送方的消息*/

/******************************** 结构体定义 *********************************/
typedef struct 
{
	WORD  	wAcId; 		/* AC编号，1开始 */
    	WORD  	wApId; 		/* WTP编号，1开始 */
	WORD	wAppId;		/* 应用编号*/
    	WORD  	wInsId;		/* 应用实例编号*/
   	WORD  	wInst;
	WORD	wRsv;
} LIPC_TPID;


/* 消息号、入参消息体、入参消息长度、出参消息体、出参消息长度
只有同步调用对应的函数需要用到后两个参数
*/
typedef VOID (*LOCIPCRCV)(WORD16 wEvent, LPBYTE pbyInBody, WORD16 wInLen, LPBYTE pbyOutBody, WORD16 *pwOutLen);	
/******************************** 全局变量声明 ********************************/

/******************************** 外部函数原形声明 ****************************/


/********************************** 函数原形声明 ******************************/

DWORD	InitIpc(BYTE *pbyAppName, WORD wInsId, LOCIPCRCV pfFunc);
DWORD IpcSend(WORD wEvent, BYTE *lpbyIn, WORD wInLen, LIPC_TPID tReceiver);
DWORD IpcGetPid (CHAR *lpbyPName, WORD wInsId, LIPC_TPID *lptPid);
VOID IpcSelfPid (LIPC_TPID* ptPID);
VOID	SynAccess(LIPC_TPID tReceiver,
	DWORD dwMsgId, 
	BYTE *pbyIn, 
	DWORD dwInLen, 
	BYTE *pbyOut, 
	DWORD *pdwOutLen);


#endif /* _LOC_IPC_H */
/******************************* 头文件结束 **********************************/

