/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ���ɿ���ģ�鹫��ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _LOC_IPC_H
#define  _LOC_IPC_H

/******************************** �궨�� *************************************/
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

#define	MSG_TASK_RESUME_REQ	(WORD)(0xFFFF-1)	/* ͬ����Ϣ���շ����ڽ��������ͷ�����Ϣ*/

/******************************** �ṹ�嶨�� *********************************/
typedef struct 
{
	WORD  	wAcId; 		/* AC��ţ�1��ʼ */
    	WORD  	wApId; 		/* WTP��ţ�1��ʼ */
	WORD	wAppId;		/* Ӧ�ñ��*/
    	WORD  	wInsId;		/* Ӧ��ʵ�����*/
   	WORD  	wInst;
	WORD	wRsv;
} LIPC_TPID;


/* ��Ϣ�š������Ϣ�塢�����Ϣ���ȡ�������Ϣ�塢������Ϣ����
ֻ��ͬ�����ö�Ӧ�ĺ�����Ҫ�õ�����������
*/
typedef VOID (*LOCIPCRCV)(WORD16 wEvent, LPBYTE pbyInBody, WORD16 wInLen, LPBYTE pbyOutBody, WORD16 *pwOutLen);	
/******************************** ȫ�ֱ������� ********************************/

/******************************** �ⲿ����ԭ������ ****************************/


/********************************** ����ԭ������ ******************************/

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
/******************************* ͷ�ļ����� **********************************/

