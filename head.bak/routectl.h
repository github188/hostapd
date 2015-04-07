/*
 * =====================================================================================
 *       Filename:  ac_firewall.h
 *       Description:  
 *
 *       Version:  1.0
 *       Created:  2009.03.04
 *       Revision: v0.1
 *       Compiler: gcc
 *       Company: gbcom 
 *
 * =====================================================================================
 */


#ifndef _AC_FIREWALL_H
#define _AC_FIREWALL_H

 
#define INVALID_VALUE AC_FAIL
/*-----------------------------------------------------------------------------
 *  route configure message
 *-----------------------------------------------------------------------------*/
#define M_MSG_GET_ROUTE_L2WAN       AC_DEVM_GET_L2WAN_CONFIG_MSG
#define M_MSG_GET_ROUTE_L3WAN       AC_DEVM_GET_L3WAN_CONFIG_MSG
#define M_MSG_GET_ROUTE_STATIC      AC_DEVM_GET_ROUTESTATIC_CONFIG_MSG
#define M_MSG_GET_RIP_GLOBAL        AC_DEVM_GET_RIPGLOBAL_CONFIG_MSG
#define M_MSG_GET_RIP_NOTIFYNET     AC_DEVM_GET_RIPNOTIFYIP_CONFIG_MSG

#define M_MSG_ROUTE_L2WAN_UPDATE    AC_DEVM_L2WAN_UPDATE_MSG
#define M_MSG_ROUTE_L3WAN_UPDATE    AC_DEVM_L3WAN_UPDATE_MSG
#define M_MSG_ROUTE_STATIC_ADD      AC_DEVM_ROUTESTATIC_ADD_IND_MSG
#define M_MSG_ROUTE_STATIC_DEL      AC_DEVM_ROUTESTATIC_DEL_IND_MSG
#define M_MSG_ROUTE_STATIC_UPDATE   AC_DEVM_ROUTESTATIC_UPDATE_IND_MSG

#define M_MSG_RIP_UPDATE            AC_DEVM_RIPGLOBAL_UPDATE_IND_MSG
#define M_MSG_RIP_NOTIFYNET_ADD     AC_DEVM_RIPNOTIFYIP_ADD_IND_MSG
#define M_MSG_RIP_NOTIFYNET_DEL     AC_DEVM_RIPNOTIFYIP_DEL_IND_MSG
#define M_MSG_RIP_NOTIFYNET_UPDATE  AC_DEVM_RIPNOTIFYIP_UPDATE_IND_MSG



#define IS_ADD_CONFIG(type)  \
    ( (M_MSG_ROUTE_STATIC_ADD == type) || \
     (M_MSG_RIP_NOTIFYNET_ADD == type))  

#define IS_DEL_CONFIG(type)   \
    ((M_MSG_ROUTE_STATIC_DEL == type) || \
     (M_MSG_RIP_NOTIFYNET_DEL == type) )  


#define IS_MODI_CONFIG(type)   \
    ((M_MSG_ROUTE_IF_UPDATE == type) || (M_MSG_ROUTE_STATIC_UPDATE == type) || \
     (M_MSG_RIP_NOTIFYNET_UPDATE == type))  


#define M_STATIC_NUM_MAX        128
typedef struct 
{
    UINT32 ulRouteId;
    CHAR   acDestIp[16];
    UINT32 ulPrefix;
    CHAR   acGw[16];
    CHAR   acCmd[128];
} ROUTE_STATIC_T;
typedef struct 
{
    UINT32 ulNum;
    ROUTE_STATIC_T astStatic[M_STATIC_NUM_MAX];
}ROUTE_STATIC_CONFIG_T;

#define M_RIP_NOTIFY_TYPE_NET       0
#define M_RIP_NOTIFY_TYPE_IF        1
typedef struct 
{
    UINT32 ulIfId;
    CHAR   acIfName[32];
}RIP_NOTIFY_IF_T;

typedef struct 
{
    UINT32 ulValid;     /* 0 : invalid node  1: valid node */
    CHAR   acNet[16];
    UINT32 ulPrefix;
}RIP_NOTIFY_NET_T;

#define M_RIP_NOTIFY_NET_MAX        16
typedef struct 
{
    UINT32 ulNum;
    RIP_NOTIFY_NET_T  astNotify[M_RIP_NOTIFY_NET_MAX];   
}RIP_NOTIFY_NET_CONFIG_T;

typedef AC_DEVM_BRIDGE_CONFIG_T BR_IF_T;

extern ROUTE_STATIC_CONFIG_T g_stStaticRoute;
extern RIP_NOTIFY_NET_CONFIG_T g_stNotifyNet;
extern AC_DEVM_RIPGLOBAL_CONFIG_T g_stRip;


/* use daemon mode */
#define DAEMON

#ifdef DAEMON
#define M_P_ERROR   LOG_ERR
#define M_P_WARNING LOG_WARNING
#define M_P_INFO    LOG_INFO
#else
/* define self printf : add funtion name and line */
#define M_P_ERROR       ((unsigned int)2)
#define M_P_WARNING     ((unsigned int)1)
#define M_P_INFO        ((unsigned int)0)
#endif

extern unsigned int g_print_level;
extern unsigned char g_acLevel[3][8];
extern char g_print_buffer[512];

/* 2010-3.15 修改打印方式，改为syslogu
#define myprintf syslog
*/
#ifdef DAEMON
#define myprintf(level, format, arg...) do {\
    syslogu(LM_ROUTE, level, format, ##arg);  \
}while(0)/*;*///delete by lixb 2014-09-15
#else
#define myprintf(level, format, arg...) do {                                                    \
    if(level >= g_print_level){                                                                  \
        sprintf(g_print_buffer, "[FW][%d][%s][%s] : ", __LINE__, __func__, g_acLevel[level]);   \
        sprintf(g_print_buffer + strlen(g_print_buffer), format, ##arg);                        \
        printf("%s\n",g_print_buffer);                                                          \
    }                                                                                           \
}while(-1 == __LINE__)/*;*///delete by lixb 2014-09-15
#endif



#define ROUTE_STATIC_PRINT(title, index, var)   \
        printf("%s[%d].ulRouteId = %d \n", title, index, (var)->ulRouteId);            \
        printf("%s[%d].aucDestIp = %x \n", title, index,  *(UINT32*)(var)->aucDestIp); \
        printf("%s[%d].aucMask = %x \n", title, index,  *(UINT32*)(var)->aucMask);     \
        printf("%s[%d].aucGw = %x \n", title, index, *(UINT32*)(var)->aucGw);              

#define IS_INVALID_IP(ip) ((ip[0]==0 && ip[1]==0 && ip[2]==0 &&ip[3]==0) \
                          ||(ip[0]==0xff && ip[1]==0xff && ip[2]==0xff &&ip[3]==0xff))

VOID rip_get_notifynet_config(UINT32 ulUpdate);


#endif

