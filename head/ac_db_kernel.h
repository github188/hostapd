/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: 数据库核心子模块头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/
#ifndef  _AC_DB_KERNEL_H
#define  _AC_DB_KERNEL_H

/******************************** 宏定义 *************************************/
typedef UINT32  DBHANDLE;
typedef UINT32  (*DBMETHOD)(UINT8*);
typedef UINT32  (*DBHASHKEYGEN)(UINT8*);            /* HASH索引值生成方法 */
typedef UINT32  (*DBHASHKEYMERGE)(UINT8*, UINT8*);  /* HASH关键字合成方法 */
typedef UINT32  (*DBTBLCOMP)(DBHANDLE);             /* 关系表主备数据区比较方法 */
typedef UINT32  (*DBTRIGGER)(UINT8);                /* 记录修改触发 */
typedef UINT32  (*DBDFTCFG)(UINT32);
typedef UINT32	(*DBWTPDELCFG)(UINT32);
typedef UINT32	(*DBWTPDFTCFG)(UINT32, UINT32, CHAR *);

typedef UINT32  (*DBDFTCFGBLK)(UINT32, UINT8*);
typedef UINT32  (*DBWTPDFTCFGBLK)(UINT32, UINT32, CHAR *, UINT8*);

#define AC_DB_TBL_FIELD_NUM_MAX     ((UINT32)64)    /* 每个关系表允许包含的最大字段数 */
#define AC_DB_IDX_FIELD_NUM_MAX     ((UINT8)8)      /* 每个索引关键字允许包含的最大字段数 */
#define AC_DB_TBL_IDX_NUM_MAX       ((UINT32)16)    /* 每个关系表允许创建的最大索引数 */

#define AC_DB_FIELD_NAME_LEN_MAX    ((UINT32)32)    /* 字段名最大长度 */


#define AC_DB_WORK_BUFF_LEN_MAX     ((UINT32)256*1024)  /* 工作缓冲区大小 256kbyte */
#define AC_DB_TBL_RECORD_LEN_MAX    ((UINT16)5120)  /* 关系表单条记录的最大长度 */
#define AC_DB_IDX_LEN_MAX           ((UINT16)256)   /* 索引的最大长度 */
#define AC_DB_FIELD_LEN_MAX         ((UINT16)5120)   /* 单个字段的最大长度 */   

#define AC_DB_TBL_NUM_MAX           ((UINT16)256)    /* 系统支持的最大关系表数 */
#define AC_DB_IDX_NUM_MAX           ((UINT16)256)   /* 系统支持的最大索引数 */
#define AC_DB_SQUE_NUM_MAX          ((UINT16)512)   /* 系统支持的最大单向队列数 */

/* 关系表类型 */
#define AC_DB_TBL_TYPE_STATIC           ((UINT8)0)  /* 静态表 */
#define AC_DB_TBL_TYPE_DYNAMIC          ((UINT8)1)  /* 动态表 */

/* 字段类型 */
#define AC_DB_FIELD_TYPE_CHAR       ((CHAR)'C')     /* CHAR */
#define AC_DB_FIELD_TYPE_UINT8      ((CHAR)'N')     /* UINT8 */
#define AC_DB_FIELD_TYPE_UINT16     ((CHAR)'W')     /* UINT16 */
#define AC_DB_FIELD_TYPE_UINT32     ((CHAR)'D')     /* UINT32 */

/* 字段存盘标记 */
#define AC_DB_FIELD_NOT_SAVE        	((UINT8)0)      /* 字段不需要存盘 */
#define AC_DB_FIELD_SAVE            	((UINT8)1)      /* 字段需存盘 */

/* 索引类型 */
#define AC_DB_IDX_TYPE_SEQU     ((UINT8)0)  /* 顺序索引 */
#define AC_DB_IDX_TYPE_HASH1    ((UINT8)1)  /* 一维一次HASH索引 */
#define AC_DB_IDX_TYPE_HASH2    ((UINT8)2)  /* 二维一次HASH索引 */
#define AC_DB_IDX_TYPE_HASH3    ((UINT8)3)  /* 三维一次HASH索引 */
#define AC_DB_IDX_TYPE_HASH     ((UINT8)4)  /* 散列HASH索引 */

/* 对象类型 */
#define AC_DB_OT_TABLE          ((DBHANDLE)0x10000)     /* 关系表 */
#define AC_DB_OT_INDEX          ((DBHANDLE)0x20000)     /* 索引 */
#define AC_DB_OT_SQUE           ((DBHANDLE)0x30000)     /* 单向队列 */

/* 关系表方法类型 */
#define AC_DB_TBL_METHOD_LOAD_PREPARE   	((UINT32)0)     /* 关系表装载准备方法 */
#define AC_DB_TBL_METHOD_LOAD           		((UINT32)1)     /* 关系表装载方法 */
#define AC_DB_TBL_METHOD_INSERT_PREPARE 	((UINT32)2)     /* 关系表记录插入准备方法 */
#define AC_DB_TBL_METHOD_INSERT         		((UINT32)3)     /* 关系表记录插入方法 */
#define AC_DB_TBL_METHOD_UPDATE_PREPARE ((UINT32)4)     /* 关系表记录更新准备方法 */
#define AC_DB_TBL_METHOD_UPDATE         		((UINT32)5)     /* 关系表记录更新方法 */
#define AC_DB_TBL_METHOD_DELETE_PREPARE 	((UINT32)6)     /* 关系表记录删除准备方法 */
#define AC_DB_TBL_METHOD_DELETE         		((UINT32)7)     /* 关系表记录删除方法 */
#define AC_DB_TBL_METHOD_SET_DYNDATA    	((UINT32)8)     /* 关系表记录动态数据继承方法 */
#define AC_DB_TBL_METHOD_CMP           	 	((UINT32)9)     /* 关系表主备数据区比较方法 */
#define AC_DB_TBL_METHOD_TRIGGER        		((UINT32)10)    	/* 关系表记录数据区修改后触发方法 */
#define AC_DB_TBL_METHOD_DFTCFG			((UINT32)11)		/* 构造关系表缺省配置方法*/
#define AC_DB_TBL_METHOD_WTPDELCFG		((UINT32)12)		/* 删除AP配置方法*/
#define AC_DB_TBL_METHOD_WTPDFTCFG		((UINT32)13)		/* 构造AP缺省配置方法*/
#define AC_DB_TBL_METHOD_DFTCFGBLK      ((UINT32)14)        /* 关系表缺省配置方法 */
#define AC_DB_TBL_METHOD_WTPDFTCFGBLK   ((UINT32)15)        /* AP关系表缺省配置方法 */

/* 记录有效标记 */
#define AC_DB_RECORD_INVALID    ((UINT8)0)  /* 记录无效 */
#define AC_DB_RECORD_VALID      ((UINT8)1)  /* 记录有效 */

#define AC_DB_INVALID_HANDLE    ((UINT32)0xFFFFFFFF)    /* 无效关系表句柄 */
#define AC_DB_RECORD_TAG_LEN    ((UINT8)4)              /* 记录有效标记占用的长度 */

#ifdef _OSWIN32_
#define AC_DB_OMC_DIR            "config/"    /* 临时目录名*/
#define AC_DB_WORK_DIR           "config/"   /* 工作目录名*/
#else
#ifdef APP_PROJ_AC
#define AC_DB_VERSION_DIR        "version/"
#define AC_DB_OMC_DIR            "config/"    /* 临时目录名*/
#define AC_DB_WLC_WORK_PROC           "powerac/"   /* 工作目录名*/
#define AC_DB_DEFAULT_DIR		"bin/"	/* 缺省数据文件目录名*/
#define AC_DB_ROLLBAK_DIR	    "rollbak/"		/* 回滚数据文件目录名*/
#else
#define AC_DB_OMC_DIR            "/tmp/"     /* 临时目录名*/
#define AC_DB_WORK_DIR           "/tmp/"     /* 工作目录名*/
#endif
#endif

#define AC_DB_PATH_WORK         	1
#define AC_DB_PATH_OMC			2
#define AC_DB_PATH_DEFAULT		3
#define AC_DB_PATH_BAK			4
#define AC_DB_PATH_ROLLBAK		5	/* 2011-5-20 pyy新增: 回滚数据点功能*/


#define AC_DB_TMPDATA_FILE_NAME		"actmp.dat"		/* 2011-5-19 pyy 新增*/
#define AC_DB_DATA_FILE_NAME        		"ac.dat"      		/* AC WORK 数据文件名 */
#define AC_DB_OMC_DATA_FILE_NAME		"acomc.dat"		/* AC 从OMC下载的临时数据文件名 */
#define AC_DB_DEFAULT_DATA_FILE_NAME	"acdft.dat"		/* AC缺省数据文件名*/
#define AC_DB_BAK_DATA_FILE_NAME		"acbak.dat"		/* 接管AC数据文件名*/
#define AC_DB_BAD_DATA_FILE_NAME		"acbad.dat"		/* add by gwx 2011-11-24 装载ac.dat 出错时对其进行备份*/
#define AC_DB_PROBLEM_FILE_NAME         "ac_dev_problem_file.tar.gz"

#define WTP_DB_DATA_FILE_NAME       "wtp.dat"     /* WTP数据文件名 */

#define AC_DB_IDX_CREATE_END    "\0"

#define AC_DB_TRIGGER_TYPE_INSERT        ((UINT8)0)
#define AC_DB_TRIGGER_TYPE_DELETE        ((UINT8)1)
#define AC_DB_TRIGGER_TYPE_UPDATE    ((UINT8)2)

#define AC_DB_CMP_OVER        2

#define AC_DB_TAG_UNCHANGED		0
#define AC_DB_TAG_CHANGED			1

/* 配置信息模型版本号, 每次信息模型变更时修改这个宏取值*/
#define AC_DB_CFGMOD_VERSION		((UINT16)1)		

/* 数据文件装载失败原因号*/
#define AC_DB_LOADFAIL_TBLNUM			((UINT32)1)	/* 关系表数目不对*/
#define AC_DB_LOADFAIL_CFGVERSION		((UINT32)2)	/* 信息模型版本号不一致*/

/******************************** 结构体定义(所有结构体自然4字节对齐) *********************************/
/* 记录缓存信息结构 */
typedef struct
{
    UINT32  ulRecNum;
    UINT8   aucBuff[AC_DB_WORK_BUFF_LEN_MAX];
}_packed_1_ AC_DB_WORK_BUFF_T;

/* 文件头结构 */
typedef struct
{
    	UINT32  ulVersion;  		/* 数据文件版本号 */
    	UINT16  usTblNum;   		/* 关系表数量 */
	/*    UINT8   aucRsv[2];*/  /* 填充字节 */
	UINT16	usCfgModVer;  	/* 配置信息模型版本号 */
}_packed_1_ AC_DB_FILE_HEADER_T;

/* 关系表头结构 */
typedef struct
{
    CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];  /* 关系表名 */
    UINT16  usFieldNum;                         /* 字段数 */
    UINT16  usRecordLen;                        /* 记录长度, 不包含1字节的记录有效标记 */
    UINT32  ulRecordNum;                        /* 记录数 */
}_packed_1_ AC_DB_TBL_HEADER_T;

/* 字段结构体 */
typedef struct
{
    CHAR    acFieldName[AC_DB_FIELD_NAME_LEN_MAX];  /* 字段名 */
    UINT16  usFieldLen;                             /* 字段长度 */
    UINT16  usFieldOffset;                          /* 字段偏移量 */
    UINT8   ucFieldType;                            /* 字段类型 */
    UINT8   ucFieldTag;                             /* 是否为关键字 */
    UINT8   ucSave;                                 /* 是否需存盘 */
    UINT8   aucRsv[1];                              /* 填充字节 */
}_packed_1_ AC_DB_FIELD_T;

/* 字段缓冲区结构体 */
typedef struct
{
    UINT16  usFieldNum; /* 字段数 */
    UINT8   aucRsv[2];  /* 填充字节 */
    AC_DB_FIELD_T   astField[AC_DB_TBL_FIELD_NUM_MAX];  /* 字段信息 */
}_packed_1_ AC_DB_FIELD_BUFF_T;

/* 关系表结构体 */
typedef struct
{
    /* 关系表属性 */
    DBHANDLE    hTbl;                               			/* 关系表句柄 */
    DBHANDLE    ahIdx[AC_DB_TBL_IDX_NUM_MAX];       /* 关系表索引句柄列表 */
    UINT32      ulCapacity;                         			/* 关系表容量 */
    AC_DB_FIELD_T   *pstField;                      		/* 字段信息 */
    UINT16      usFieldNum;                         			/* 字段数 */
    UINT16      usRecordLen;                        			/* 记录标记(1byte) + 记录的有效字段长度 */
    CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];  /* 关系表名 */
    UINT8       ucTblType;                          			/* 关系表类型 */
    UINT8       aucRsv[3];                          			/* 填充字节 */
        
    UINT32      aulRecordNum[2];                  /* 主备记录数据区有效记录数 */
    UINT32      aulRecordNo[2];                     /* 主备记录数据区当前记录号 */
    DBHANDLE    ahSque[2];                          	/* 单向队列句柄, 单向队列用于管理关系表空闲记录 */
    UINT8       *apucTblAddr[2];                    /* 主备记录数据区指针 */
    UINT8       ucMainAddr;                         	/* 主用内存指示 */
    UINT8       ucSlaveAddr;                        	/* 备用内存指示 */
    UINT8       aucRsv1[2];                         	/* 填充字节 */
    UINT32	ulTag;						/* 关系表标记*/
    
    /* 关系表方法 */
    DBMETHOD    mdLoadPrepare;                      	/* 关系表装载准备方法 */
    DBMETHOD    mdLoad;                             	/* 关系表装载方法 */
    DBMETHOD    mdInsertPrepare;                    	/* 关系表记录插入准备方法 */
    DBMETHOD    mdInsert;                           	/* 关系表记录插入方法 */
    DBMETHOD    mdUpdatePrepare;                    /* 关系表记录更新准备方法 */
    DBMETHOD    mdUpdate;                           	/* 关系表记录更新方法 */
    DBMETHOD    mdDeletePrepare;                    	/* 关系表记录删除准备方法 */
    DBMETHOD    mdDelete;                           	/* 关系表记录删除方法 */
    DBMETHOD    mdSetDynData;                       	/* 设置记录动态数据 */
    DBTBLCOMP   mdTblCmp;                           	/* 关系表主备数据区比较方法 */
    DBTRIGGER   mdTrigger;                         		/* 关系表记录数据区修改后触发方法 */

    DBDFTCFG	mdDftCfg;					/* 关系表缺省配置构造方法*/

    DBWTPDFTCFG	mdWtpDftCfg;				/* AP关系表缺省配置构造方法*/
    DBWTPDELCFG	mdWtpDelCfg;				/* AP记录删除方法*/

	DBDFTCFGBLK    mdDftCfgBlk;             /* 关系表缺省配置生成方法(有且仅一条记录的表) */
	DBWTPDFTCFGBLK mdWtpDftCfgBlk;          /* AP关系表缺省配置生成方法(有且仅一条记录的表) */
}_packed_1_ AC_DB_TABLE_T;

/* 索引结构体 */
typedef struct
{
    DBHANDLE    hIdx;       /* 索引句柄 */
    DBHANDLE    hTbl;       /* 索引所属的关系表句柄 */
    UINT8       ucIdxType;  /* 索引类型 */
    UINT8       ucIdxFieldNum;                      /* 组成关键字的字段个数 */  
    UINT8       aucIdxKey[AC_DB_IDX_FIELD_NUM_MAX]; /* 索引关键字字段编号, 从1开始编号 */
    UINT8       aucRsv[2];                          /* 填充字节 */          

    UINT32      ulHashModules;                      /* 哈希索引模值 */
    UINT32      ulDimX;                             /* Hash索引x的最大值 */
    UINT32      ulDimY;                             /* Hash索引y的最大值 */
    UINT32      ulDimZ;                             /* Hash索引z的最大值 */
    UINT16      usIdxKeyLen;                        /* 索引关键字总长度 */
    UINT16      usIdxItemLen;                       /* 索引项长度：索引关键字长度+记录号长度 */
    
    UINT32      aulIdxItemNum[2];                   /* 主备索引数据区当前索引项数 */
    UINT32      aulIdxItemNo[2];                    /* 主备索引数据区当前索引项号 */
    UINT8       *apucIdxAddr[2];                    /* 主备索引数据区数据起始地址 */

    /* 散列HASH相关属性 */
    UINT8       *apucIdxHashBucketAddr[2];          /* HASH桶起始地址 */
    DBHASHKEYGEN   mdHashMethod;                    /* 重载散列Hash方法 */
    DBHASHKEYMERGE mdMergeHashKeyMethod;            /* 重载散列Hash关键字合成方法 */    
}_packed_1_ AC_DB_INDEX_T;

/* 单向队列结构体 */
typedef struct
{
    DBHANDLE    hSque;              /* 本单向队列对象句柄 */
    DBHANDLE    hTbl;               /* 队列对象所归属的关系表句柄 */
    UINT32      ulSqueCapacity;     /* 队列项容量*/
    UINT32      ulSqueItem;         /* 队列当前元素数目 */
    UINT32      ulSqueHead;         /* 队列头 */
    UINT32      ulSqueTail;         /* 队列尾 */
    UINT32      *pulSqueAddr;       /* 队列数据区地址，存放队列元素数据区的首地址 */
}_packed_1_ AC_DB_SQUEUE_T;

/* 双向队列结构体 */
typedef struct
{
    UINT32  ulNum;
}_packed_1_ AC_DB_BQUEUE_T;

/******************************** 全局变量声明 ********************************/
extern AC_DB_TABLE_T   *gpstDbTblRT;
extern AC_DB_INDEX_T   *gpstDbIdxRT;
extern AC_DB_SQUEUE_T  *gpstDbSqueRT;

/******************************** 外部函数原形声明 ****************************/


/********************************** 函数原形声明 ******************************/
/* 函数宏定义 */
#define handle(A) ((A)&0x0FFFF)

#define isTbl(A)    ((!(((A) & 0x70000) ^ AC_DB_OT_TABLE)) && \
                     (handle(A) < AC_DB_TBL_NUM_MAX) && \
                     ((A) == gpstDbTblRT[handle(A)].hTbl))

#define isIdx(A)    ((!(((A) & 0x70000) ^ AC_DB_OT_INDEX)) && \
                     (handle(A) < AC_DB_IDX_NUM_MAX) && \
                     ((A) == gpstDbIdxRT[handle(A)].hIdx))

#define isSque(A)   ((!(((A) & 0x70000) ^ AC_DB_OT_SQUE)) && \
                     (handle(A) < AC_DB_SQUE_NUM_MAX) && \
                     ((A) == gpstDbSqueRT[handle(A)].hSque ) )

extern UINT32 ac_db_sys_init (VOID);
extern UINT32  ac_db_set_path(UINT32 ulPathNo);
extern UINT32  ac_db_make_file_name(STRING sCompleteName, STRING sFileName);
extern UINT32 ac_db_load_file (CHAR *pcCompleteName);
extern UINT32 ac_db_save_file (VOID);

extern UINT32 ac_db_sque_create (DBHANDLE hTbl, UINT32 ulCapacity);
extern UINT32  ac_db_sque_push_node (DBHANDLE hSque, UINT32 ulValue);
extern UINT32  ac_db_sque_pop_node (DBHANDLE hSque);
extern UINT32  ac_db_sque_get_head_node (DBHANDLE hSque);
extern UINT32  ac_db_sque_get_node_num (DBHANDLE hSque);

extern VOID ac_db_init_field_buff (VOID);
extern VOID ac_db_field_add (STRING szName, UINT8 ucType, UINT16 usLen, UINT8 ucSave);
extern UINT32 ac_db_field_get_value (AC_DB_FIELD_T *pstField, UINT8 *pucIdxKey, UINT32 *pulValue);

extern UINT32 ac_db_table_create_sque (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32 ac_db_table_create (STRING szTblName, UINT8   ucType, UINT32  ulCapacity, UINT16  usFieldNum);
extern DBHANDLE ac_db_table_get_handle_by_name (STRING szTblName);
extern UINT32 ac_db_table_get_name_by_handle(DBHANDLE	hTbl, STRING szTblName);
extern UINT32  ac_db_table_get_tbl_num (VOID);
extern UINT32  ac_db_table_get_tbl_capacity (DBHANDLE hTbl);
extern UINT32  ac_db_table_get_record_num (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_table_get_record_num_main (DBHANDLE hTbl);
extern UINT32  ac_db_table_get_record_num_slave (DBHANDLE hTbl);
extern UINT32  ac_db_table_load (FILE *pfData);
extern UINT32  ac_db_table_save (DBHANDLE hTbl, FILE *pfData);
extern UINT32  ac_db_table_overload_method (DBHANDLE hTbl, UINT32 ulType, DBMETHOD mdMethod);
extern UINT32  ac_db_table_insert (DBHANDLE hTbl, UINT8* pucRecord);
extern UINT32  ac_db_table_delete (DBHANDLE hTbl, UINT8* pucRecord);
extern UINT32  ac_db_table_update (DBHANDLE hTbl, UINT8* pucRecord);

extern UINT32  ac_db_record_append (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_append_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_append_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_set_recno (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 ucFlag);
extern UINT32  ac_db_record_set_recno_main (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT32  ac_db_record_set_recno_slave (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT32  ac_db_record_set_rec (DBHANDLE hTbl, UINT8 *pucRecord, UINT8 ucFlag);
extern UINT32  ac_db_record_set_rec_main (DBHANDLE hTbl, UINT8 *pucRecord);
extern UINT32  ac_db_record_set_rec_slave (DBHANDLE hTbl, UINT8 *pucRecord);
extern UINT32  ac_db_record_get_recno (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_get_recno_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_get_recno_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_get_rec (DBHANDLE hTbl, UINT8 ucFlag, UINT8 *pucRecord);
extern UINT32  ac_db_record_get_rec_main (DBHANDLE hTbl, UINT8 *pucRecord);
extern UINT32  ac_db_record_get_rec_slave (DBHANDLE hTbl, UINT8 *pucRecord);
extern UINT8*  ac_db_record_get_recaddr (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT8*  ac_db_record_get_recaddr_main (DBHANDLE hTbl);
extern UINT8*  ac_db_record_get_recaddr_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_get_rec_by_recno (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 ucFlag, UINT8 *pucRecord);
extern UINT32  ac_db_record_get_rec_by_recno_main (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 *pucRecord);
extern UINT32  ac_db_record_get_rec_by_recno_slave (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 *pucRecord);
extern UINT8*  ac_db_record_get_recaddr_by_recno (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 ucFlag);
extern UINT8*  ac_db_record_get_recaddr_by_recno_main (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT8*  ac_db_record_get_recaddr_by_recno_slave (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT16  ac_db_record_get_reclen (DBHANDLE hTbl);
extern UINT32  ac_db_record_del (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_del_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_del_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_del_by_recno (DBHANDLE hTbl, UINT32 ulRecNo, UINT8 ucFlag);
extern UINT32  ac_db_record_del_by_recno_main (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT32  ac_db_record_del_by_recno_slave (DBHANDLE hTbl, UINT32 ulRecNo);
extern UINT32  ac_db_record_locate (DBHANDLE hIdx, UINT8 *pucKey, UINT8 ucFlag);
extern UINT32  ac_db_record_locate_main (DBHANDLE hIdx, UINT8 *pucKey);
extern UINT32  ac_db_record_locate_slave (DBHANDLE hIdx, UINT8 *pucKey);
extern UINT32  ac_db_record_locate_by_idx (DBHANDLE hIdx, UINT8 *pucKey, UINT32 ulCmpLen, UINT8 ucFlag);
extern UINT32  ac_db_record_locate_by_idx_main (DBHANDLE hIdx, UINT8 *pucKey, UINT32 ulCmpLen);
extern UINT32  ac_db_record_locate_by_idx_slave (DBHANDLE hIdx, UINT8 *pucKey, UINT32 ulCmpLen);
extern UINT32  ac_db_record_skip_first (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_skip_first_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_first_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_next (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_skip_next_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_next_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_prev (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_skip_prev_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_prev_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_last (DBHANDLE hTbl, UINT8 ucFlag);
extern UINT32  ac_db_record_skip_last_main (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_last_slave (DBHANDLE hTbl);
extern UINT32  ac_db_record_skip_recnum_main (DBHANDLE hTbl, UINT32 ulRecNum);

extern UINT32 ac_db_index_create (DBHANDLE hTbl,
                           UINT8 ucIdxType,
                           UINT32 ulDimX,
                           UINT32 ulDimY,
                           UINT32 ulDimZ,
                           ...);
extern UINT32  ac_db_index_insert (DBHANDLE hIdx,
                            UINT8* pucKey);
extern UINT32  ac_db_index_delete (DBHANDLE hIdx,
                            UINT8* pucKey);
extern UINT32  ac_db_index_locate (DBHANDLE hIdx,
                            UINT8 *pucKey,
                            UINT32 ulCmpLen,
                            UINT8 ucFlag);
extern UINT32  ac_db_index_locate_main (DBHANDLE hIdx,
                                        UINT8 *pucKey,
                                        UINT32 ulCmpLen);
extern UINT32  ac_db_index_locate_slave (DBHANDLE hIdx,
                                         UINT8 *pucKey,
                                         UINT32 ulCmpLen); 
extern UINT32  ac_db_index_get_recno (DBHANDLE hIdx, 
                                      UINT32 ulIdxNum,
                                      UINT8 ucFlag);
extern UINT32  ac_db_index_get_recno_main (DBHANDLE hIdx, 
                                           UINT32 ulIdxNum);
extern UINT32  ac_db_index_get_recno_slave (DBHANDLE hIdx, 
                                            UINT32 ulIdxNum);
extern UINT32  ac_db_index_fetch (DBHANDLE hIdx,
                                  UINT8 *pucKey,
                                  UINT32 ulCmpLen,
                                  UINT8 ucFlag,
                                  UINT32 *pulFetchRecNo);
extern UINT32  ac_db_index_fetch_main (DBHANDLE hIdx,
                                       UINT8 *pucKey,
                                       UINT32 ulCmpLen,
                                       UINT32 *pulFetchRecNo);
extern UINT32  ac_db_index_fetch_slave (DBHANDLE hIdx,
                                        UINT8 *pucKey,
                                        UINT32 ulCmpLen,
                                        UINT32 *pulFetchRecNo);
extern UINT32  ac_db_index_merge_key_by_record (DBHANDLE hIdx,
                                                UINT8 *pucRecord,
                                                UINT8 *pucKey);
extern UINT32  ac_db_index_merge_key_by_recno (DBHANDLE hIdx,
                                               UINT32 ulRecNo,
                                               UINT8 ucFlag,
                                               UINT8 *pucKey);
extern UINT32  ac_db_index_merge_key_by_recno_main (DBHANDLE hIdx,
                                                    UINT32 ulRecNo,
                                                    UINT8 *pucKey);
extern UINT32  ac_db_index_merge_key_by_recno_slave (DBHANDLE hIdx,
                                                     UINT32 ulRecNo,
                                                     UINT8 *pucKey);

extern UINT32  ac_db_default_insert_method (DBHANDLE hTbl,
                                            UINT8* pucRecord);
extern UINT32  ac_db_default_update_method (DBHANDLE hTbl,
                                            UINT8* pucRecord);
extern UINT32  ac_db_default_delete_method (DBHANDLE hTbl,
                                            UINT8* pucRecord);
extern UINT32  ac_db_default_hash_method (DBHANDLE hIdx,
                                          UINT8* pucIdxKey);
extern UINT32    ac_db_default_cmp_method(DBHANDLE hTbl);

extern UINT32  ac_db_record_host_to_net (DBHANDLE hTbl,
                                         UINT8 *pucHostRec,
                                         UINT8 *pucNetRec);
extern UINT32  ac_db_record_net_to_host (DBHANDLE hTbl,
                                         UINT8 *pucNetRec,
                                         UINT8 *pucHostRec);
extern UINT32  ac_db_index_host_to_net (DBHANDLE hIdx,
                                        UINT8 *pucHostKey,
                                        UINT8 *pucNetKey);
extern UINT32  ac_db_index_net_to_host (DBHANDLE hIdx,
                                        UINT8 *pucNetKey,
                                        UINT8 *pucHostKey);
extern UINT32  ac_db_fh_host_to_net (AC_DB_FILE_HEADER_T *pstHostFH,
                                     AC_DB_FILE_HEADER_T *pstNetFH);
extern UINT32  ac_db_fh_net_to_host (AC_DB_FILE_HEADER_T *pstNetFH,
                                     AC_DB_FILE_HEADER_T *pstHostFH);
extern UINT32  ac_db_tblh_host_to_net (AC_DB_TBL_HEADER_T *pstHostTblH,
                                       AC_DB_TBL_HEADER_T *pstNetTblH);
extern UINT32  ac_db_tblh_net_to_host (AC_DB_TBL_HEADER_T *pstNetTblH,
                                       AC_DB_TBL_HEADER_T *pstHostTblH);
extern UINT32  ac_db_field_host_to_net (AC_DB_FIELD_T *pstHostField,
                                        AC_DB_FIELD_T *pstNetField);
extern UINT32  ac_db_field_net_to_host (AC_DB_FIELD_T *pstNetField,
                                        AC_DB_FIELD_T *pstHostField);

extern VOID ac_db_mem_clear (VOID);
extern VOID ac_db_mem_copy (VOID);
extern VOID ac_db_mem_switch (VOID);

extern UINT32 ac_db_datafull_check(VOID);

#endif /* _AC_DB_KERNEL_H */
/******************************* 头文件结束 **********************************/
