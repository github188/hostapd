
#ifndef __ENCIPHERMENT_INFOR_H
#define __ENCIPHERMENT_INFOR_H

#ifdef SHARED
int (*get_all_sysinfo)(unsigned char *text, int *text_len);
int (*ac_license_verify)(int *res);

#else
extern int get_Info(unsigned char *cmdtext,  int cmdtext_len, unsigned char *infotext, int *infotext_len);
extern int get_CpuInfo(unsigned char *cpuinfotext, int *couinfotext_len);
extern int get_old_CpuInfo(unsigned char *cpuinfotext, int *couinfotext_len);
extern int get_MacInfo(unsigned char *macinfotext, int *macinfotext_len, int *mac_num);
extern int get_old_MacInfo(unsigned char *macinfotext, int *macinfotext_len, int *mac_num);
extern int get_AcSnInfo(unsigned char *infotext, int *infotext_len);
extern int get_AcTypeInfo(unsigned char *infotext, int *infotext_len);
extern int get_AcOemInfo(unsigned char *infotext, int *infotext_len);
extern int get_all_sysinfo(unsigned char *text, int *text_len);
extern int get_old_all_sysinfo(unsigned char *text, int *text_len);
extern int get_sysinfo_cleartext(unsigned char *cleartext,int *cleartext_len);
extern int get_old_sysinfo_cleartext(unsigned char *cleartext,int *cleartext_len);
extern int ac_old_license_verify(AC_LICENSE_INFO_T stLicenseKeyInfo);
extern int ac_basis_license_verify(AC_LICENSE_INFO_T stLicenseKeyInfo);
extern int ac_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
extern int ac_license_verify_test(char *szreadfile, char *license_info, int info_flag, int *res);
extern int ap_basis_license_verify(AP_LICENSE_INFO_T stLicenseKeyInfo);
extern int ap_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
#endif

#endif

