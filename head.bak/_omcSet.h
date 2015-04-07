#ifndef OMC_SET_H
#define OMC_SET_H


#define MAX_OBJECTID_LEN    1024

/* OMC SET��������Ϣͷ */
#define INFORCE_MODE_SET		0
#define INFORCE_MODE_DELAY_SET	2
#define MAX_IMVERSION_LEN   (16-1)
typedef struct omcSetHead_s
{
    unsigned long   msgLen;         /* ��Ϣ����ܳ��ȣ�����n�����������ܳ��� */
    unsigned long   neType;         /* ��Ԫ���� */
    char            imVersion[MAX_IMVERSION_LEN+1]; 
                                    /* ��Ԫ��Ϣģ�Ͱ汾 */
    unsigned long   configVersion;  /* ��Ԫ�������ݰ汾 */
    unsigned long   objectNum;      /* ���������Ŀ */
    unsigned long   inforceMode;    /* ��Ԫ��Чģʽ */
    unsigned long   delayTime;      /* ��Ԫ��ʱ��Чʱ�䣬��λ���� */
    T_omaTime       inforceTime;    /* ��ʱ��Чʱ��� */
    unsigned long   inforceFlag;    /* �ֶ���Ч״̬��0-����Ч 1-��Ч */
} T_omcCfgHead;


/* ���õ������ö�������� */
typedef struct omcSetObject_s
{
    unsigned long   setType;        /* ���������� */
    unsigned long   objectIDLen;    /* ��������ʶ���� */
    char*           objectID;       /* ��������ʶ */
    unsigned long   objectValueLen; /* ����������ݳ��� */
    unsigned char*  objectValue;    /* ����������� */
} T_omcCfgObject;

typedef int (*OMC_SET_HANDLE)(unsigned long setType, void* req, unsigned long len);
typedef int (*OMC_EXT_SET_HANDLE)(unsigned long setType, void* req, unsigned long len, unsigned long subIndex);

#define NOR_SET     0       /* �򵥶������ã����±� */
#define EXT_SET     1       /* ��չ�������ã����±� */

typedef struct
{
    const char      *objectID;
    void            *handle;        /* OMC_SET_HANDLE��OMC_EXT_SET_HANDLEָ�� */
    unsigned long   setType;
} T_omcSetHandle;


int do_omc_set(unsigned long isSetAll, char* req, unsigned long len);
int omc_set_object(T_omcCfgObject *setObject);
int get_omc_set_handle_index(char *oid, int *subIndex);

#endif /* OMC_SET_H */



