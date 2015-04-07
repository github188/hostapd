#ifndef OMC_CFGALL_H
#define OMC_CFGALL_H

#define NOR_GET     0       /* �򵥶����ȡ������¼ */
#define EXT_GET     1       /* ��չ������ߣ����¼ */

typedef int (*OMC_NOR_GET_HANDLE)(void* data);
typedef int (*OMC_EXT_GET_HANDLE)(void* data, unsigned long *objectIndex, unsigned long *objectNum);

typedef struct
{
    const char      *objectID;
    void            *handle;
    unsigned long   objectValueLen;
    unsigned long   getType;
} T_omcGetHandle;

int initAllConfigData(void);
int do_omc_set_all(char* req, unsigned long len);
int do_omc_get_all(unsigned char* data, unsigned long *len);

#endif /* OMC_CFGALL_H */

