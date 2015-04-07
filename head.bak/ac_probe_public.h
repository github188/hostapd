/******************************************************************************

                  版权所有 (C), 2008-2012, 上海寰创通信科技有限公司

 ******************************************************************************
  文 件 名   : ac_probe_public.h
  版 本 号   : 初稿
  作    者   : wubin
  生成日期   : 2012年4月25日 星期三
  最近修改   :
  功能描述   : ac_probe_proc.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2012年4月25日 星期三
    作    者   : wubin
    修改内容   : 创建文件

******************************************************************************/
#ifndef __AC_PROBE_PUBLIC_H__
#define __AC_PROBE_PUBLIC_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*----------------------------------------------*
 * 包含头文件                                   *
 *----------------------------------------------*/
#include "ac_db_kernel.h"
#include "ac_public.h"
/*----------------------------------------------*
 * 外部变量说明                                 *
 *----------------------------------------------*/
#if defined (_LINUX_) 	
extern TPID    gtDbCtrlProc;
extern TPID    gtDbCmPid;
extern TPID    gtAcCwPid;
extern TPID    gtWtpCwPid;
extern TPID    gtComPid;
extern TPID    gtHostapdPid;
extern TPID    gtOamPid;
extern TPID    gtAcmPid;
//extern TPID		gtSmPid;
extern TPID		gtRrmPid;
extern TPID		gtPortalPid;
extern TPID		gtWapiPid;
extern TPID		gtSysmPid;
extern TPID		gtUsrmPid;
extern TPID		gtApOmaPid;
extern TPID		gtOssMsPid;
extern TPID		gtLicensePid;
#endif
/*----------------------------------------------*
 * 外部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 内部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 模块级变量                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 宏定义                                       *
 *----------------------------------------------*/
#define APP_MODULE_PROBE APP_MODULE_DB

#define AC_CLIENT_PORT			(WORD16)(7867)      /* 发送端口号 */
#define AC_SERVER_PORT			(WORD16)(7866)      /* 监听端口号 */


/* 与探针交互的消息头定义*/
typedef struct 
{
        UINT16  usMsgId;
        UINT16	usMsgLen;
        UINT32  ulSequence;
}AC_PROBE_MSG_HEAD_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT8    ucMasterOrSlave ;
        UINT8    aucRsv[3];
}AC_PROBE_GETTABLES_REQ_MSG_T;

/* 文件头结构 */
typedef struct
{
        UINT32  ulVersion;  /* 数据文件版本号 */
        UINT16  usTblNum;   /* 系统当前关系表对象实例数量 */
        UINT16	usCfgModVer;  	/* 配置信息模型版本号 */
        UINT16	usStaticTblNum;/* 系统当前静态关系表对象实例数量*/
        UINT16  usIdxNum;   /* 系统当前索引对象实例数量 */
        UINT16  usSqueNum;    /* 系统当前单向队列对象实例数量 */
        UINT16  usPathNo;   	/* 路径号 */
} AC_PROBE_FILE_HEADER_T;

typedef struct{
        DBHANDLE  hTbl;
        CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];	/* 关系表名 */
        UINT8   ucTblType;         	/* 关系表类型 */
        UINT8   aucRsv[3];
}AC_PROBE_TABLE_TYPE;

typedef struct{
        AC_PROBE_MSG_HEAD_T stHead;
        AC_PROBE_FILE_HEADER_T stFileHeader;
        AC_PROBE_TABLE_TYPE astTables[AC_DB_TBL_NUM_MAX];
} AC_PROBE_GETTABLES_RSP_MSG_T;

/* 获取指定关系表的所有记录 */
typedef struct
{
        AC_PROBE_MSG_HEAD_T     stHead;
        CHAR acTblName[AC_DB_TBL_NAME_LEN_MAX];
        DBHANDLE        hTbl;
        UINT32  ulBeginTuple;
        UINT32  ulTupleNum;
        UINT8   ucMasterOrSlave;
        UINT8   aucRsv[3];
}AC_PROBE_GETTUPLES_REQ_MSG_T;

#if 0
/* 字段结构体 */
typedef struct
{
        CHAR acFieldName[AC_DB_FIELD_NAME_LEN_MAX];/* 字段名 */
        UINT16  usFieldLen;   /* 字段长度 */
        UINT16  usFieldOffset;  /* 字段偏移量 */
        UINT8   ucFieldType;  /* 字段类型 */
        UINT8   ucFieldTag;    /* 是否为关键字 */
        UINT8   ucSave;        /* 是否需存盘 */
        UINT8   aucRsv[1];        /* 填充字节 */
}AC_PROBE_FIELD_T;
#endif

/* AC_DB_WORK_BUFF_LEN_MAX工作缓冲区大小 256kbyte */
#define AC_PROBE_WORK_BUFF_LEN_MAX     ((UINT32)AC_DB_PACKET_MAX_LEN_NET)  

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
    	UINT32	ulRet;		/* 返回值，AC_OK表示成功，其它表示错误码 */
    	UINT32	ulFinish;		/* 关系表所有记录是否已读取结束
    							AC_DB_TABLE_READ_NOTFINISH	未结束
    							AC_DB_TABLE_READ_FINISH		读取结束 */
        CHAR acTblName[AC_DB_TBL_NAME_LEN_MAX];
        DBHANDLE  hTbl; /* 关系表句柄 */
        DBHANDLE ahIdx[AC_DB_TBL_IDX_NUM_MAX]; /* 关系表索引句柄列表 */
        UINT32  ulCapacity; /* 关系表容量 */
        UINT32  ulBeginRecord;
        UINT32  ulEndRecord;
        UINT32  ulRecordNum;
        UINT16  usFieldNum;  /* 字段数 */
        UINT16  usRecordLen;/* 记录标记(4byte) + 记录的有效字段长度 */
        AC_DB_FIELD_T   astField[AC_DB_TBL_FIELD_NUM_MAX];
        UINT8   aucBuff[AC_PROBE_WORK_BUFF_LEN_MAX];
        DBHANDLE        ahSque[2]; /* 单向队列句柄, 单向队列用于管理关系表空闲记录 第2个是静态表区分*/
        UINT8   ucMainSlaveAddr;     	/* 内存指示 */
        UINT8   ucTag;			/* 关系表标记触发使用*/
        UINT8   aucRsv[2];
}AC_PROBE_GETTUPLES_RSP_MSG_T;

/* 修改表记录 */
typedef struct
{
        AC_PROBE_MSG_HEAD_T  stHead;
        CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];
        UINT32	ulIncType;	/* 增量配置类型：
						0 ：增加
						1：删除
						2：修改
						*/
        UINT8   aucRecord[AC_DB_PACKET_MAX_LEN_NET];	/* 记录内容 */
} AC_PROBE_ACCESSRECORD_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
	UINT32	ulRet;	/*返回值，AC_OK表示成功，其它表示错误码 */
	CHAR    acResultDesc[128];    /* 错误描述信息 */
} AC_PROBE_ACCESSRECORD_RSP_MSG_T;

/* 存盘ac.dat */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_SAVEDATA_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32	ulRet;/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_PROBE_SAVEDATA_RSP_MSG_T;

/* 通知表触发器 */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_NOTIFY_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32  ulRet;/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_PROBE_NOTIFY_RSP_MSG_T;

/* 加载ac.dat */
typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
} AC_PROBE_LOADDATA_REQ_MSG_T;

typedef struct{
        AC_PROBE_MSG_HEAD_T  stHead;
        UINT32	ulRet;/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_PROBE_LOADDATA_RSP_MSG_T;

/* 根据索引获取表记录 */
typedef struct{
        AC_PROBE_MSG_HEAD_T     stHead;
        UINT8   ucMainSlaveAddr;     	/* 主用or备用内存指示 */
        UINT8   aucRsv[3];
        UINT32  ulCmpLen;
        UINT8   aucKey[AC_DB_IDX_LEN_MAX];
        DBHANDLE    hIdx;       /* 索引句柄 */
        DBHANDLE    hTbl;       /* 索引所属的关系表句柄 */
        UINT32 ulBeginTupleNo;/* 非唯一索引开始观察记录号 */
        UINT32 ulBeginIdxItemNo;/*开始观测的索引项号,用于顺序索引 */
        UINT32 ulTupleNum;/* 非唯一索引已观察记录数 */
} AC_PROBE_GETINDEX_REQ_MSG_T;

AC_PROBE_GETTUPLES_RSP_MSG_T    AC_PROBE_GETINDEX_RSP_MSG_T;








#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __AC_PROBE_PUBLIC_H__ */
