/*
加解密模块公共函数头文件
*/
#ifndef __ENCIPHERMENT_COMMON_H
#define __ENCIPHERMENT_COMMON_H

#include "encipherment_public.h"

typedef struct 
{
    CHAR        *szKey;
    UINT32      ulType;
#define PROPERTY_INT        0
#define PROPERTY_STRING     1
#define PROPERTY_IP         2

    UINT32      ulReadTime;     /* 判断是否被读取，多次则表示重复 */
    UINT32      ulReadValue;    /* 对于STRING，对应的是一个指针，由调用者分配；
                                   对于IP地址，对应的是一个BYTE[4]数组 */

    void*       pValue;         /* 真正需要赋值的位置 */
}PROPERTY_DESC_T;

#ifdef SHARED
void (*testprint)(int len, unsigned  char *Data);
void (*testprintchar)(int len, unsigned  char *Data);
int (*write_info_file)(char *szTmpFile, unsigned char *text, int text_len);
int (*info_encipher_create)(unsigned char *cleartext, int cleartext_len, unsigned char *ciphertext, int *ciphertext_len);

#else
extern int ac_tools_get_rand();
extern void testprint(int iLogLevel, int len, unsigned  char *Data);
extern void testprintchar(int iLogLevel, int len, unsigned  char *Data);
extern void  mylicenselog(int iLogLevel, char *szFormat, ...);
extern int filter_sign(char *omcinfo_part, int omcinfo_part_len, char *out, int *out_len);
extern int getomcinfo_int(char *omcinfo_part, int omcinfo_part_len, int *out);
extern int analysis_tlv_put_struct_ap(unsigned char *cleartext, int cleartext_len, AP_LICENSE_INFO_T *pstLicenseInfo);
extern int analysis_tlv_put_struct(unsigned char *cleartext, int cleartext_len, AC_LICENSE_INFO_T *pstLicenseInfo);
extern int omcinfo_put_struct_ap(unsigned char *omcinfo, int omcinfo_len, AP_LICENSE_INFO_T *pstLicenseInfo);
extern int omcinfo_put_struct(unsigned char *omcinfo, int omcinfo_len, AC_LICENSE_INFO_T *pstLicenseInfo);
extern int licenseinfo_turn_tlv_ap(AP_LICENSE_INFO_T *pstLicenseInfo, unsigned char *licensecleartext, int *licensecleartext_len);
extern int licenseinfo_turn_tlv(AC_LICENSE_INFO_T *pstLicenseInfo, unsigned char *licensecleartext, int *licensecleartext_len);
extern int write_info_file(char *szTmpFile, unsigned char *text, int text_len);
extern int read_info_file(char *szTmpFile, unsigned char *out, int *outlen);
extern int info_encipher_create(unsigned char *cleartext, int cleartext_len, unsigned char *ciphertext, int *ciphertext_len);
extern int info_decipher_create(unsigned char *ciphertext, int ciphertext_len, unsigned char *cleartext, int *cleartext_len);
extern int ap_license_rule_reverse(AP_LICENSE_INFO_T *pstLicenseInfo, unsigned char *ruletext, int *ruletext_outlen);
extern int ac_license_rule_reverse(AC_LICENSE_INFO_T *pstLicenseInfo, unsigned char *ruletext, int *ruletext_outlen);
extern int ap_license_rule_forward(AP_LICENSE_INFO_T *pstLicenseInfo, unsigned  char *ruletext, int *ruletext_len);
extern int ac_license_rule_forward(AC_LICENSE_INFO_T *pstLicenseInfo, unsigned  char *ruletext, int *ruletext_len);
extern int ac_license_create(unsigned char *omcinfo, int omcinfo_len, unsigned char *inforpath, int inforpath_len,unsigned char *licensepath, int licensepath_len);
extern int ap_license_create(unsigned char *omcinfo, int omcinfo_len, unsigned char *inforpath, int inforpath_len,unsigned char *licensepath, int licensepath_len);
extern int FileExists(char* szFile);
extern int ReadProperty(char *szConfigFile, int ulPropertyNum, PROPERTY_DESC_T *pstPropertyDesc);


#endif


#endif

