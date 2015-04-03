/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: ���ݿ������ģ��ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/
#ifndef  _AC_DB_KERNEL_H
#define  _AC_DB_KERNEL_H

/******************************** �궨�� *************************************/
typedef UINT32  DBHANDLE;
typedef UINT32  (*DBMETHOD)(UINT8*);
typedef UINT32  (*DBHASHKEYGEN)(UINT8*);            /* HASH����ֵ���ɷ��� */
typedef UINT32  (*DBHASHKEYMERGE)(UINT8*, UINT8*);  /* HASH�ؼ��ֺϳɷ��� */
typedef UINT32  (*DBTBLCOMP)(DBHANDLE);             /* ��ϵ�������������ȽϷ��� */
typedef UINT32  (*DBTRIGGER)(UINT8);                /* ��¼�޸Ĵ��� */
typedef UINT32  (*DBDFTCFG)(UINT32);
typedef UINT32	(*DBWTPDELCFG)(UINT32);
typedef UINT32	(*DBWTPDFTCFG)(UINT32, UINT32, CHAR *);

typedef UINT32  (*DBDFTCFGBLK)(UINT32, UINT8*);
typedef UINT32  (*DBWTPDFTCFGBLK)(UINT32, UINT32, CHAR *, UINT8*);

#define AC_DB_TBL_FIELD_NUM_MAX     ((UINT32)64)    /* ÿ����ϵ���������������ֶ��� */
#define AC_DB_IDX_FIELD_NUM_MAX     ((UINT8)8)      /* ÿ�������ؼ����������������ֶ��� */
#define AC_DB_TBL_IDX_NUM_MAX       ((UINT32)16)    /* ÿ����ϵ������������������� */

#define AC_DB_FIELD_NAME_LEN_MAX    ((UINT32)32)    /* �ֶ�����󳤶� */


#define AC_DB_WORK_BUFF_LEN_MAX     ((UINT32)256*1024)  /* ������������С 256kbyte */
#define AC_DB_TBL_RECORD_LEN_MAX    ((UINT16)5120)  /* ��ϵ������¼����󳤶� */
#define AC_DB_IDX_LEN_MAX           ((UINT16)256)   /* ��������󳤶� */
#define AC_DB_FIELD_LEN_MAX         ((UINT16)5120)   /* �����ֶε���󳤶� */   

#define AC_DB_TBL_NUM_MAX           ((UINT16)256)    /* ϵͳ֧�ֵ�����ϵ���� */
#define AC_DB_IDX_NUM_MAX           ((UINT16)256)   /* ϵͳ֧�ֵ���������� */
#define AC_DB_SQUE_NUM_MAX          ((UINT16)512)   /* ϵͳ֧�ֵ����������� */

/* ��ϵ������ */
#define AC_DB_TBL_TYPE_STATIC           ((UINT8)0)  /* ��̬�� */
#define AC_DB_TBL_TYPE_DYNAMIC          ((UINT8)1)  /* ��̬�� */

/* �ֶ����� */
#define AC_DB_FIELD_TYPE_CHAR       ((CHAR)'C')     /* CHAR */
#define AC_DB_FIELD_TYPE_UINT8      ((CHAR)'N')     /* UINT8 */
#define AC_DB_FIELD_TYPE_UINT16     ((CHAR)'W')     /* UINT16 */
#define AC_DB_FIELD_TYPE_UINT32     ((CHAR)'D')     /* UINT32 */

/* �ֶδ��̱�� */
#define AC_DB_FIELD_NOT_SAVE        	((UINT8)0)      /* �ֶβ���Ҫ���� */
#define AC_DB_FIELD_SAVE            	((UINT8)1)      /* �ֶ������ */

/* �������� */
#define AC_DB_IDX_TYPE_SEQU     ((UINT8)0)  /* ˳������ */
#define AC_DB_IDX_TYPE_HASH1    ((UINT8)1)  /* һάһ��HASH���� */
#define AC_DB_IDX_TYPE_HASH2    ((UINT8)2)  /* ��άһ��HASH���� */
#define AC_DB_IDX_TYPE_HASH3    ((UINT8)3)  /* ��άһ��HASH���� */
#define AC_DB_IDX_TYPE_HASH     ((UINT8)4)  /* ɢ��HASH���� */

/* �������� */
#define AC_DB_OT_TABLE          ((DBHANDLE)0x10000)     /* ��ϵ�� */
#define AC_DB_OT_INDEX          ((DBHANDLE)0x20000)     /* ���� */
#define AC_DB_OT_SQUE           ((DBHANDLE)0x30000)     /* ������� */

/* ��ϵ�������� */
#define AC_DB_TBL_METHOD_LOAD_PREPARE   	((UINT32)0)     /* ��ϵ��װ��׼������ */
#define AC_DB_TBL_METHOD_LOAD           		((UINT32)1)     /* ��ϵ��װ�ط��� */
#define AC_DB_TBL_METHOD_INSERT_PREPARE 	((UINT32)2)     /* ��ϵ���¼����׼������ */
#define AC_DB_TBL_METHOD_INSERT         		((UINT32)3)     /* ��ϵ���¼���뷽�� */
#define AC_DB_TBL_METHOD_UPDATE_PREPARE ((UINT32)4)     /* ��ϵ���¼����׼������ */
#define AC_DB_TBL_METHOD_UPDATE         		((UINT32)5)     /* ��ϵ���¼���·��� */
#define AC_DB_TBL_METHOD_DELETE_PREPARE 	((UINT32)6)     /* ��ϵ���¼ɾ��׼������ */
#define AC_DB_TBL_METHOD_DELETE         		((UINT32)7)     /* ��ϵ���¼ɾ������ */
#define AC_DB_TBL_METHOD_SET_DYNDATA    	((UINT32)8)     /* ��ϵ���¼��̬���ݼ̳з��� */
#define AC_DB_TBL_METHOD_CMP           	 	((UINT32)9)     /* ��ϵ�������������ȽϷ��� */
#define AC_DB_TBL_METHOD_TRIGGER        		((UINT32)10)    	/* ��ϵ���¼�������޸ĺ󴥷����� */
#define AC_DB_TBL_METHOD_DFTCFG			((UINT32)11)		/* �����ϵ��ȱʡ���÷���*/
#define AC_DB_TBL_METHOD_WTPDELCFG		((UINT32)12)		/* ɾ��AP���÷���*/
#define AC_DB_TBL_METHOD_WTPDFTCFG		((UINT32)13)		/* ����APȱʡ���÷���*/
#define AC_DB_TBL_METHOD_DFTCFGBLK      ((UINT32)14)        /* ��ϵ��ȱʡ���÷��� */
#define AC_DB_TBL_METHOD_WTPDFTCFGBLK   ((UINT32)15)        /* AP��ϵ��ȱʡ���÷��� */

/* ��¼��Ч��� */
#define AC_DB_RECORD_INVALID    ((UINT8)0)  /* ��¼��Ч */
#define AC_DB_RECORD_VALID      ((UINT8)1)  /* ��¼��Ч */

#define AC_DB_INVALID_HANDLE    ((UINT32)0xFFFFFFFF)    /* ��Ч��ϵ���� */
#define AC_DB_RECORD_TAG_LEN    ((UINT8)4)              /* ��¼��Ч���ռ�õĳ��� */

#ifdef _OSWIN32_
#define AC_DB_OMC_DIR            "config/"    /* ��ʱĿ¼��*/
#define AC_DB_WORK_DIR           "config/"   /* ����Ŀ¼��*/
#else
#ifdef APP_PROJ_AC
#define AC_DB_VERSION_DIR        "version/"
#define AC_DB_OMC_DIR            "config/"    /* ��ʱĿ¼��*/
#define AC_DB_WLC_WORK_PROC           "powerac/"   /* ����Ŀ¼��*/
#define AC_DB_DEFAULT_DIR		"bin/"	/* ȱʡ�����ļ�Ŀ¼��*/
#define AC_DB_ROLLBAK_DIR	    "rollbak/"		/* �ع������ļ�Ŀ¼��*/
#else
#define AC_DB_OMC_DIR            "/tmp/"     /* ��ʱĿ¼��*/
#define AC_DB_WORK_DIR           "/tmp/"     /* ����Ŀ¼��*/
#endif
#endif

#define AC_DB_PATH_WORK         	1
#define AC_DB_PATH_OMC			2
#define AC_DB_PATH_DEFAULT		3
#define AC_DB_PATH_BAK			4
#define AC_DB_PATH_ROLLBAK		5	/* 2011-5-20 pyy����: �ع����ݵ㹦��*/


#define AC_DB_TMPDATA_FILE_NAME		"actmp.dat"		/* 2011-5-19 pyy ����*/
#define AC_DB_DATA_FILE_NAME        		"ac.dat"      		/* AC WORK �����ļ��� */
#define AC_DB_OMC_DATA_FILE_NAME		"acomc.dat"		/* AC ��OMC���ص���ʱ�����ļ��� */
#define AC_DB_DEFAULT_DATA_FILE_NAME	"acdft.dat"		/* ACȱʡ�����ļ���*/
#define AC_DB_BAK_DATA_FILE_NAME		"acbak.dat"		/* �ӹ�AC�����ļ���*/
#define AC_DB_BAD_DATA_FILE_NAME		"acbad.dat"		/* add by gwx 2011-11-24 װ��ac.dat ����ʱ������б���*/
#define AC_DB_PROBLEM_FILE_NAME         "ac_dev_problem_file.tar.gz"

#define WTP_DB_DATA_FILE_NAME       "wtp.dat"     /* WTP�����ļ��� */

#define AC_DB_IDX_CREATE_END    "\0"

#define AC_DB_TRIGGER_TYPE_INSERT        ((UINT8)0)
#define AC_DB_TRIGGER_TYPE_DELETE        ((UINT8)1)
#define AC_DB_TRIGGER_TYPE_UPDATE    ((UINT8)2)

#define AC_DB_CMP_OVER        2

#define AC_DB_TAG_UNCHANGED		0
#define AC_DB_TAG_CHANGED			1

/* ������Ϣģ�Ͱ汾��, ÿ����Ϣģ�ͱ��ʱ�޸������ȡֵ*/
#define AC_DB_CFGMOD_VERSION		((UINT16)1)		

/* �����ļ�װ��ʧ��ԭ���*/
#define AC_DB_LOADFAIL_TBLNUM			((UINT32)1)	/* ��ϵ����Ŀ����*/
#define AC_DB_LOADFAIL_CFGVERSION		((UINT32)2)	/* ��Ϣģ�Ͱ汾�Ų�һ��*/

/******************************** �ṹ�嶨��(���нṹ����Ȼ4�ֽڶ���) *********************************/
/* ��¼������Ϣ�ṹ */
typedef struct
{
    UINT32  ulRecNum;
    UINT8   aucBuff[AC_DB_WORK_BUFF_LEN_MAX];
}_packed_1_ AC_DB_WORK_BUFF_T;

/* �ļ�ͷ�ṹ */
typedef struct
{
    	UINT32  ulVersion;  		/* �����ļ��汾�� */
    	UINT16  usTblNum;   		/* ��ϵ������ */
	/*    UINT8   aucRsv[2];*/  /* ����ֽ� */
	UINT16	usCfgModVer;  	/* ������Ϣģ�Ͱ汾�� */
}_packed_1_ AC_DB_FILE_HEADER_T;

/* ��ϵ��ͷ�ṹ */
typedef struct
{
    CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];  /* ��ϵ���� */
    UINT16  usFieldNum;                         /* �ֶ��� */
    UINT16  usRecordLen;                        /* ��¼����, ������1�ֽڵļ�¼��Ч��� */
    UINT32  ulRecordNum;                        /* ��¼�� */
}_packed_1_ AC_DB_TBL_HEADER_T;

/* �ֶνṹ�� */
typedef struct
{
    CHAR    acFieldName[AC_DB_FIELD_NAME_LEN_MAX];  /* �ֶ��� */
    UINT16  usFieldLen;                             /* �ֶγ��� */
    UINT16  usFieldOffset;                          /* �ֶ�ƫ���� */
    UINT8   ucFieldType;                            /* �ֶ����� */
    UINT8   ucFieldTag;                             /* �Ƿ�Ϊ�ؼ��� */
    UINT8   ucSave;                                 /* �Ƿ������ */
    UINT8   aucRsv[1];                              /* ����ֽ� */
}_packed_1_ AC_DB_FIELD_T;

/* �ֶλ������ṹ�� */
typedef struct
{
    UINT16  usFieldNum; /* �ֶ��� */
    UINT8   aucRsv[2];  /* ����ֽ� */
    AC_DB_FIELD_T   astField[AC_DB_TBL_FIELD_NUM_MAX];  /* �ֶ���Ϣ */
}_packed_1_ AC_DB_FIELD_BUFF_T;

/* ��ϵ��ṹ�� */
typedef struct
{
    /* ��ϵ������ */
    DBHANDLE    hTbl;                               			/* ��ϵ���� */
    DBHANDLE    ahIdx[AC_DB_TBL_IDX_NUM_MAX];       /* ��ϵ����������б� */
    UINT32      ulCapacity;                         			/* ��ϵ������ */
    AC_DB_FIELD_T   *pstField;                      		/* �ֶ���Ϣ */
    UINT16      usFieldNum;                         			/* �ֶ��� */
    UINT16      usRecordLen;                        			/* ��¼���(1byte) + ��¼����Ч�ֶγ��� */
    CHAR        acTblName[AC_DB_TBL_NAME_LEN_MAX];  /* ��ϵ���� */
    UINT8       ucTblType;                          			/* ��ϵ������ */
    UINT8       aucRsv[3];                          			/* ����ֽ� */
        
    UINT32      aulRecordNum[2];                  /* ������¼��������Ч��¼�� */
    UINT32      aulRecordNo[2];                     /* ������¼��������ǰ��¼�� */
    DBHANDLE    ahSque[2];                          	/* ������о��, ����������ڹ����ϵ����м�¼ */
    UINT8       *apucTblAddr[2];                    /* ������¼������ָ�� */
    UINT8       ucMainAddr;                         	/* �����ڴ�ָʾ */
    UINT8       ucSlaveAddr;                        	/* �����ڴ�ָʾ */
    UINT8       aucRsv1[2];                         	/* ����ֽ� */
    UINT32	ulTag;						/* ��ϵ����*/
    
    /* ��ϵ���� */
    DBMETHOD    mdLoadPrepare;                      	/* ��ϵ��װ��׼������ */
    DBMETHOD    mdLoad;                             	/* ��ϵ��װ�ط��� */
    DBMETHOD    mdInsertPrepare;                    	/* ��ϵ���¼����׼������ */
    DBMETHOD    mdInsert;                           	/* ��ϵ���¼���뷽�� */
    DBMETHOD    mdUpdatePrepare;                    /* ��ϵ���¼����׼������ */
    DBMETHOD    mdUpdate;                           	/* ��ϵ���¼���·��� */
    DBMETHOD    mdDeletePrepare;                    	/* ��ϵ���¼ɾ��׼������ */
    DBMETHOD    mdDelete;                           	/* ��ϵ���¼ɾ������ */
    DBMETHOD    mdSetDynData;                       	/* ���ü�¼��̬���� */
    DBTBLCOMP   mdTblCmp;                           	/* ��ϵ�������������ȽϷ��� */
    DBTRIGGER   mdTrigger;                         		/* ��ϵ���¼�������޸ĺ󴥷����� */

    DBDFTCFG	mdDftCfg;					/* ��ϵ��ȱʡ���ù��췽��*/

    DBWTPDFTCFG	mdWtpDftCfg;				/* AP��ϵ��ȱʡ���ù��췽��*/
    DBWTPDELCFG	mdWtpDelCfg;				/* AP��¼ɾ������*/

	DBDFTCFGBLK    mdDftCfgBlk;             /* ��ϵ��ȱʡ�������ɷ���(���ҽ�һ����¼�ı�) */
	DBWTPDFTCFGBLK mdWtpDftCfgBlk;          /* AP��ϵ��ȱʡ�������ɷ���(���ҽ�һ����¼�ı�) */
}_packed_1_ AC_DB_TABLE_T;

/* �����ṹ�� */
typedef struct
{
    DBHANDLE    hIdx;       /* ������� */
    DBHANDLE    hTbl;       /* ���������Ĺ�ϵ���� */
    UINT8       ucIdxType;  /* �������� */
    UINT8       ucIdxFieldNum;                      /* ��ɹؼ��ֵ��ֶθ��� */  
    UINT8       aucIdxKey[AC_DB_IDX_FIELD_NUM_MAX]; /* �����ؼ����ֶα��, ��1��ʼ��� */
    UINT8       aucRsv[2];                          /* ����ֽ� */          

    UINT32      ulHashModules;                      /* ��ϣ����ģֵ */
    UINT32      ulDimX;                             /* Hash����x�����ֵ */
    UINT32      ulDimY;                             /* Hash����y�����ֵ */
    UINT32      ulDimZ;                             /* Hash����z�����ֵ */
    UINT16      usIdxKeyLen;                        /* �����ؼ����ܳ��� */
    UINT16      usIdxItemLen;                       /* ������ȣ������ؼ��ֳ���+��¼�ų��� */
    
    UINT32      aulIdxItemNum[2];                   /* ����������������ǰ�������� */
    UINT32      aulIdxItemNo[2];                    /* ����������������ǰ������� */
    UINT8       *apucIdxAddr[2];                    /* ��������������������ʼ��ַ */

    /* ɢ��HASH������� */
    UINT8       *apucIdxHashBucketAddr[2];          /* HASHͰ��ʼ��ַ */
    DBHASHKEYGEN   mdHashMethod;                    /* ����ɢ��Hash���� */
    DBHASHKEYMERGE mdMergeHashKeyMethod;            /* ����ɢ��Hash�ؼ��ֺϳɷ��� */    
}_packed_1_ AC_DB_INDEX_T;

/* ������нṹ�� */
typedef struct
{
    DBHANDLE    hSque;              /* ��������ж����� */
    DBHANDLE    hTbl;               /* ���ж����������Ĺ�ϵ���� */
    UINT32      ulSqueCapacity;     /* ����������*/
    UINT32      ulSqueItem;         /* ���е�ǰԪ����Ŀ */
    UINT32      ulSqueHead;         /* ����ͷ */
    UINT32      ulSqueTail;         /* ����β */
    UINT32      *pulSqueAddr;       /* ������������ַ����Ŷ���Ԫ�����������׵�ַ */
}_packed_1_ AC_DB_SQUEUE_T;

/* ˫����нṹ�� */
typedef struct
{
    UINT32  ulNum;
}_packed_1_ AC_DB_BQUEUE_T;

/******************************** ȫ�ֱ������� ********************************/
extern AC_DB_TABLE_T   *gpstDbTblRT;
extern AC_DB_INDEX_T   *gpstDbIdxRT;
extern AC_DB_SQUEUE_T  *gpstDbSqueRT;

/******************************** �ⲿ����ԭ������ ****************************/


/********************************** ����ԭ������ ******************************/
/* �����궨�� */
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
/******************************* ͷ�ļ����� **********************************/
