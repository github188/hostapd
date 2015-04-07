/******************************************************************************
模块名      : RADIUS ALIVE
文件名      : radius_alive.h
相关文件    :
实现功能    : RADIUS SERVR保活，并执行主备AAA切换
修改记录    :
------------------------------------------------------------------------------
日期        修改人      修改内容
2009/02/25  叶恩云      创建
******************************************************************************/

#ifndef RADIUS_ALIVE_H
#define RADIUS_ALIVE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum{
	RADIUS_ALIVE_EVENT_SEND,
	RADIUS_ALIVE_EVENT_RECV
} RADIUS_ALIVE_EVENT_E ;

int radius_alive_global_init(struct hostapd_radius_servers * pstRadiusCfg) ;
void radius_alive_global_deinit(void) ;

void radius_alive_event(int radius_id, RadiusType msg_type, RADIUS_ALIVE_EVENT_E event) ;
struct radius_client_data * radius_alive_client_find(int auth_id, int acct_id) ;


#ifdef __cplusplus
}
#endif

#endif
