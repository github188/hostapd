#ifndef AC_PA_IP_SSID_H
#define AC_PA_IP_SSID_H

BOOL ac_pa_init_ip_hash_table(UINT32 ulHashEntrySize, UINT32 ulMaxNum);

AC_PA_IP_DATA_T* ac_pa_add_ip(UINT8* pucIP, CHAR* szSSID);
AC_PA_IP_DATA_T* ac_pa_get_ip_data(UINT8* pucIP);

BOOL ac_pa_remove_ip(UINT8* pucIP);
BOOL ac_pa_check_ip_ssid(UINT8* pucUserIP, CHAR *szSSID);
VOID ac_pa_get_ip_list(UINT8* pucUserIP, UINT32 ulMaxNum, AC_PA_IP_DATA_T* pstIP, UINT32 *pulUserNum);

#endif  /* AC_PA_IP_SSID_H */
