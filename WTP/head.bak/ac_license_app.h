/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  用户管理模块APP头文件
* 修改历史: 
* 2012-1-5     吴彬             新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_LICENSE_APP_H
#define  _AC_LICENSE_APP_H
#include "ac_license_public.h"
/*
extern int (*ac_license_verify)(int *res);
extern int (*Create_hash_encrypt)(unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int (*Create_hash_decrypt)(unsigned char *in, int inlen, unsigned char *out, int *outlen);
*/

extern UINT32 ac_license_write_file(CHAR *szTmpFile, CHAR *text, UINT32 text_len);
extern UINT32 ac_license_read_file(CHAR *szTmpFile, CHAR *out, UINT32 *outlen);
extern UINT32 ac_license_read_omcfile(CHAR *szTmpFile, AC_LICENSE_OMC_T *out);
extern UINT32 ac_license_read_authortime_second(CHAR *timestr, UINT32 timestr_len, UINT32 *out);
extern UINT32 ac_license_set_testtime (UINT32 ulTestTime);
extern UINT32 ac_license_set_authortime (UINT32 ulTestTime);
extern VOID ac_license_get_timestamp(CHAR *timestr, UINT32 timestr_len);
extern VOID ac_license_get_maxauthortime(CHAR *timestr, UINT32 timestr_len, UINT32 *out);
extern VOID ac_license_get_authortime (UINT32 *ulSurplusTimes );
extern VOID ac_license_get_testtime (UINT32 *ulSurplusTimes );
extern UINT32 ac_license_get_svip(UINT8 *svip, UINT32 svip_len);
extern UINT32 ac_license_report_convert_active_report_msg(AC_LICENSE_MSG_TO_SV_REPORT_REQ_T *pstRsp);
extern UINT32 ac_license_ip_convert_active_ip_msg(SV_MSG_TO_AC_LICENSE_IP_CHANGE_ACK_T *pstRsp);
extern UINT32 ac_license_tort_convert_active_tort_msg(SV_MSG_TO_AC_LICENSE_TORT_ACK_T *pstRsp);
extern UINT32 ac_license_web_to_struct(CHAR *pucBuf, UINT32 ulLen, AC_LICENSE_OMC_T *pstAcLicenseOmcInfo);
extern UINT32 ac_license_buf_find_name(CHAR *pucBuf, CHAR *pName, CHAR *pstLicenseOmcInfo);
extern UINT32 ac_license_comparemac(UINT8 *pucMac, UINT8 *pucBeginMac, UINT8 *pucEndMac);
extern UINT32 ac_license_get_wtpmac_enable(UINT8 *pucMac);
extern UINT32 ac_license_get_oemvendor ( void );
extern VOID ac_license_get_localfactory (UINT32 *pulFactoryApNum);
extern UINT32 ap_license_mac_to_int(CHAR *pucBufMac, UINT8 *pucMac);
extern UINT32 ac_license_wtpweb_to_struct(CHAR *pucBuf, UINT32 ulLen, AP_LICENSE_OMC_T *pstApLicenseOmcInfo);
extern UINT32 ac_license_read_wtp_omcfile(CHAR *szTmpFile, AP_LICENSE_OMC_T *pout);


#endif /* _AC_LICENSE_APP_H */
/******************************* 头文件结束 **********************************/

