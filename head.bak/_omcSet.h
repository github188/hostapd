#ifndef OMC_SET_H
#define OMC_SET_H


#define MAX_OBJECTID_LEN    1024

/* OMC SET操作的消息头 */
#define INFORCE_MODE_SET		0
#define INFORCE_MODE_DELAY_SET	2
#define MAX_IMVERSION_LEN   (16-1)
typedef struct omcSetHead_s
{
    unsigned long   msgLen;         /* 消息体的总长度，包括n个变更对象的总长度 */
    unsigned long   neType;         /* 网元类型 */
    char            imVersion[MAX_IMVERSION_LEN+1]; 
                                    /* 网元信息模型版本 */
    unsigned long   configVersion;  /* 网元配置数据版本 */
    unsigned long   objectNum;      /* 变更对象数目 */
    unsigned long   inforceMode;    /* 网元生效模式 */
    unsigned long   delayTime;      /* 网元延时生效时间，单位：秒 */
    T_omaTime       inforceTime;    /* 定时生效时间点 */
    unsigned long   inforceFlag;    /* 手动生效状态：0-不生效 1-生效 */
} T_omcCfgHead;


/* 设置单个配置对象的内容 */
typedef struct omcSetObject_s
{
    unsigned long   setType;        /* 对象变更类型 */
    unsigned long   objectIDLen;    /* 变更对象标识长度 */
    char*           objectID;       /* 变更对象标识 */
    unsigned long   objectValueLen; /* 变更对象内容长度 */
    unsigned char*  objectValue;    /* 变更对象内容 */
} T_omcCfgObject;

typedef int (*OMC_SET_HANDLE)(unsigned long setType, void* req, unsigned long len);
typedef int (*OMC_EXT_SET_HANDLE)(unsigned long setType, void* req, unsigned long len, unsigned long subIndex);

#define NOR_SET     0       /* 简单对象设置，无下标 */
#define EXT_SET     1       /* 扩展对象设置，有下标 */

typedef struct
{
    const char      *objectID;
    void            *handle;        /* OMC_SET_HANDLE或OMC_EXT_SET_HANDLE指针 */
    unsigned long   setType;
} T_omcSetHandle;


int do_omc_set(unsigned long isSetAll, char* req, unsigned long len);
int omc_set_object(T_omcCfgObject *setObject);
int get_omc_set_handle_index(char *oid, int *subIndex);

#endif /* OMC_SET_H */



