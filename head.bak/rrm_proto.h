/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  射频资源管理模块/AP AC通信自定义收发接口协议头文件
* 修改历史: 
* 2009-3-22     叶恩云            新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/
#ifndef  __RRM_PROTO_H
#define  __RRM_PROTO_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************** 宏定义 *************************************/
/*事件号定义*/
#define EV_RRM_NEIGHBORAP_REQUEST		(EV_RRM_BEGIN+0)
#define EV_RRM_NEIGHBORAP_RESPONSE		(EV_RRM_BEGIN+1)
#define EV_RRM_CHANNEL_REELECT_REQUEST	(EV_RRM_BEGIN+2)
#define EV_RRM_CHANNEL_REELECT_ACK		(EV_RRM_BEGIN+3)
#define EV_RRM_CHANNEL_REELECT_NACK		(EV_RRM_BEGIN+4)
#define EV_RRM_CHANNEL_REELECT_CMD		(EV_RRM_BEGIN+5)
#define EV_RRM_CHANNEL_REELECT_CMD_RESP	(EV_RRM_BEGIN+6)
#define EV_RRM_POWER_ADJUST				(EV_RRM_BEGIN+7)
#define EV_RRM_POWER_ADJUST_CMD			(EV_RRM_BEGIN+8)
#define EV_RRM_POWER_ADJUST_CMD_RESP	(EV_RRM_BEGIN+9)
#define EV_RRM_POWER_REPAIR_TRAN			(EV_RRM_BEGIN+10)
#define EV_RRM_POWER_REPAIR_TRAN_RESP	(EV_RRM_BEGIN+11)
#define EV_RRM_POWER_REPAIR_CMD			(EV_RRM_BEGIN+12)
#define EV_RRM_POWER_REPAIR_CMD_RESP	(EV_RRM_BEGIN+13)
#define EV_RRM_POWER_DEREPAIR_TRAN			(EV_RRM_BEGIN+14)
#define EV_RRM_POWER_DEREPAIR_TRAN_RESP	(EV_RRM_BEGIN+15)
#define EV_RRM_POWER_DEREPAIR_CMD			(EV_RRM_BEGIN+16)
#define EV_RRM_POWER_DEREPAIR_CMD_RESP	(EV_RRM_BEGIN+17)
#define EV_RRM_GDEVNEIGHBOR_UPDATE_AUTO	(EV_RRM_BEGIN+18)
#define EV_RRM_GDEVFLOWSTATS_REQUEST	(EV_RRM_BEGIN+19)
#define EV_RRM_GDEVFLOWSTATS_RESPONSE	(EV_RRM_BEGIN+20)
#define EV_RRM_GDEVFLOWSTATS_NOTIFY		(EV_RRM_BEGIN+21)
#define EV_RRM_GDEV_DISASSOC				(EV_RRM_BEGIN+22)

#define EV_RRM_TIMER						(EV_RRM_BEGIN+100)	/*即时定时器消息*/


/*事件ELEM ID定义*/
typedef enum{
	RRM_ELEMID_NAME	= 0,		
	RRM_ELEMID_APINFO	,
	RRM_ELEMID_VAPID,	
	RRM_ELEMID_IFID,		
	RRM_ELEMID_GDEVID	,
	RRM_ELEMID_WTPID,	
	RRM_ELEMID_ACID,
	RRM_ELEMID_GDEVID_REQUEST,
	RRM_ELEMID_GDEVID_SERVER	,
	RRM_ELEMID_POWER,
	RRM_ELEMID_REQUEST_TYPE,
	RRM_ELEMID_GDEVNEIGHBOR_ADD,
	RRM_ELEMID_GDEVNEIGHBOR_DEL,
	RRM_ELEMID_GDEV_FLOWSTATS,
	RRM_ELEMID_GDEV_DISASSOC,
	RRM_ELEMID_POWER_ADJUST_TYPE,
	RRM_ELEMID_SCAN_COND,
	RRM_ELEMID_MAC,
	RRM_ELEMID_CHANNEL
} RRM_ELEMID_E;


enum{
	REQUEST_TYPE_SAME = 1,	/*同频扫描*/
	REQUEST_TYPE_ALL	= 2		/*异频扫描*/
} ;


enum{
	POWER_ADJUST_TYPE_DOWN = 0,	/*下调1dB*/
	POWER_ADJUST_TYPE_UP = 1		/*上调1dB*/
} ;


/******************************** 结构体定义 *********************************/
/*AC与AP间通信的消息头，AC与AC间通信不带该消息头*/
typedef struct{
	AC_VAPID_T stFrom ;
	AC_VAPID_T stTo ;
}RRM_EVENT_HEAD_T ;


typedef struct{
	UINT32 dwElemId ;
	UINT32 dwLength ;		/*包括本消息头*/
	/*不同的ELEMID，后面跟随不同的内容*/
}RRM_EVENT_ELEM_T ;


/******************************** 全局变量声明 ********************************/

/******************************** 外部函数原形声明 ****************************/
int rrm_proto_init(VOID) ;

BYTE * rrm_add_elem(BYTE * pbFrame, DWORD dwElemId, BYTE * pbData, DWORD dwDataLen) ;
int rrm_send(AC_VAPID_T * from, AC_VAPID_T * to, UINT16 usEvent, UINT8 * pcBuffer, UINT32 ulLength) ;


/********************************** 函数原形声明 ******************************/


#ifdef __cplusplus
}
#endif

#endif /* __RRM_PROTO_H */
/******************************* 头文件结束 **********************************/
