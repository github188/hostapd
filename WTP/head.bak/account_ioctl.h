#ifndef __ACCOUNT_IOCTL_H__
#define __ACCOUNT_IOCTL_H__


int account_ioctl_user_stats_get(u_int8_t * ip, struct account_user_stats * stats) ;
int account_ioctl_user_add(u_int8_t *ip, u_int8_t *mac, const char *szSSID);
int account_ioctl_user_del(u_int8_t * ip, u_int8_t * mac);


#endif
