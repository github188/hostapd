#ifndef AC_SYSM_COMMON_H
#define AC_SYSM_COMMON_H


#define AC_SYSM_ALARM_STATE_ALARM           1
#define AC_SYSM_ALARM_STATE_ALARM_CLEAR     0
#define AC_SYSM_ALARM_STATE_ALARM_SAME      2

/* 定时器 */
#define TIMER_AC_SYSM_SCAN_TIMER                (TIMER0)
#define EV_AC_SYSM_SCAN_TIMER_MSG               (EV_TIMER0)

#define EV_AC_SYSM_SET_TIME_REQ_MSG             ((UINT16)EV_SYSM_BEGIN + 0)
#define EV_AC_SYSM_SET_TIME_RSP_MSG             ((UINT16)EV_SYSM_BEGIN + 1)

/* 本地配置 */
typedef struct 
{
    UINT32      ulScanTime;         /* 定时扫描时间，单位秒，0表示关闭该功能 */
}AC_SYSM_LOCAL_CFG_T;

typedef struct 
{
    UINT32  ulAlarmResendTime;  /* 告警重复发送时间：新告警产生后，更新告警内容的最小等待时间，单位：秒 */

    UINT32  ulCpuLoadPeriod;    /* CPU负荷采样周期 */
    UINT32  ulCpuLoadCount;     /* CPU负荷持续次数 */
    UINT32  ulCpuLoadHigh;      /* CPU负荷告警产生门限 */
    UINT32  ulCpuLoadLow;       /* CPU负荷告警消除门限 */

    UINT32  ulMemLoadPeriod;	/* 内存利用率采样周期 */
    UINT32  ulMemLoadCount;	    /* 内存利用率持续次数 */
    UINT32  ulMemLoadHigh;	    /* 内存利用率告警产生门限 */
    UINT32  ulMemLoadLow;       /* 内存利用率告警消除门限 */

    UINT32  ulDiskLoadPeriod;	/* 磁盘利用率采样周期 */
    UINT32  ulDiskLoadCount;	/* 磁盘利用率持续次数 */
    UINT32  ulDiskLoadHigh;	    /* 磁盘利用率告警产生门限 */
    UINT32  ulDiskLoadLow;      /* 磁盘利用率告警消除门限 */

    UINT32  ulTempPeriod;       /* 设备温度采样周期 */
    UINT32  ulTempCount;	    /* 设备温度持续次数	*/
    UINT32  ulTempHigh;	        /* 设备温度告警产生门限 */
    UINT32  ulTempLow;	        /* 设备温度告警消除门限 */

    UINT32  ulEnetPeriod;       /* 检查网口状态周期 */
    UINT32  ulEnetCount;	    /* 检查网口状态次数	*/
}AC_SYSM_ALARM_CFG_T;



#define AC_SYSM_MAX_CPU_COUNT       600
#define AC_SYSM_MAX_MEM_COUNT       60
#define AC_SYSM_MAX_DISK_COUNT      60
#define AC_SYSM_MAX_TEMP_COUNT      60
#define AC_SYSM_MAX_ENET_COUNT      60

#define AC_SYSM_ENET_STATE_ONLINE           1
#define AC_SYSM_ENET_STATE_OFFLINE          0

typedef struct 
{
    UINT32          ulCpuIndex;
    UINT32          aulCpu[AC_SYSM_MAX_CPU_COUNT];              /* 单位% */

    UINT32          ulMemIndex;
    UINT32          aulFreeMemSize[AC_SYSM_MAX_MEM_COUNT];      /* 单位M */
    UINT32          aulMemUsage[AC_SYSM_MAX_MEM_COUNT];         /* 内存使用率，单位% */

    UINT32          ulDiskIndex;
    UINT32          aulFreeDiskSize[AC_SYSM_MAX_DISK_COUNT];    /* 单位M */
    UINT32          aulDiskUsage[AC_SYSM_MAX_DISK_COUNT];       /* 内存使用率，单位% */

    UINT32          ulTempIndex;
    INT32           aiTemp[AC_SYSM_MAX_TEMP_COUNT];            /* 单位:度 */

	/* 2010-3-25 pyy 修改*/		
#if 0	
    UINT32          ulEnetIndex;
    UINT32          aulEnet[AC_ENETPORT_NUM_MAX][AC_SYSM_MAX_ENET_COUNT];  
#endif
	UINT32          aulEnet[AC_ENETPORT_NUM_MAX];
	UINT32		aulEnetLastAlarmState[AC_ENETPORT_NUM_MAX];
	UINT32		aulLastAlarmTime[AC_ENETPORT_NUM_MAX];
}AC_SYSM_ALARM_INFO_T;
    
/* 相关统计项目 */
typedef struct 
{
    UINT32      ulOfflineUserNum;  
    
}AC_SYSM_PERF_INFO_T;

/* 设置时间 */
typedef struct
{
    UINT32      ulSn;
    UINT32      ulTime;
}AC_SYSM_SET_TIME_REQ_MSG_T; 

#define AC_SYSM_SET_TIME_SUCCESS    0
#define AC_SYSM_SET_TIME_FAIL       1
typedef struct
{
    UINT32      ulSn; 
    UINT32      ulRet;          /* 应答码,0:成功 1 失败 */  
}AC_SYSM_SET_TIME_RSP_MSG_T;

typedef struct 
{
    CHAR        acAcDevType[32];
    CHAR        acAcDevSN[32];
    CHAR        acAcSwVersion[32];
    CHAR        acAcHwVersion[32];
    CHAR        acAcManufacturer[128];
    CHAR        acAcSwDeveloper[128];
}AC_SYSM_AC_CUSTOMIZE_INFO_T;


#define AC_SYSM_UPLINK_STATUS_DISCONNECT        AC_OPSTATE_FAULT
#define AC_SYSM_UPLINK_STATUS_CONNECT           AC_OPSTATE_NORMAL

/* 全部配置 */
typedef struct 
{
    //UINT32                      ulCfgID;        /* 每次配置数据变更后都增加1，初始值为upTime */

    AC_SYSM_LOCAL_CFG_T         stLocalCfg;

    AC_SYSM_ALARM_CFG_T         stAlarmCfg;
    AC_DEVM_ACKEEPER_CONFIG_T   stKeeperCfg;
    
}AC_SYSM_CFG_T;

BOOL    VmSetTime(DWORD dwSecond);
AC_RET  ac_sysm_get_acalarmthreshold_config(AC_SYSM_ALARM_CFG_T *pstAlarmCfg);
AC_RET  ac_sysm_get_ackeeper_config(AC_DEVM_ACKEEPER_CONFIG_T *pstKeeperCfg);
AC_RET  ac_sysm_get_omc_cfg(AC_SYSM_CFG_T *pstCfg);
INT32   ac_sysm_get_systemp(VOID);
BOOL    ac_sysm_get_acmoid(VOID);
CHAR*   ac_sysm_get_cpuinfo(VOID);
UINT32  ac_sysm_get_enet_state(UINT32 ulEnetIndex);
BOOL    ac_sysm_get_ac_info(AC_OMA_AC_DEVICE_ABSTRACT_T* pstDeviceInfo);
VOID    ac_sysm_get_ac_customize_info(AC_OMA_AC_DEVICE_ABSTRACT_T* pstDeviceInfo);

/* 2010-10-21 fengjing add */
UINT32 ac_sysm_get_uptime(VOID);
BOOL ac_sysm_get_msstate(AC_OMA_AC_DEVICE_ABSTRACT_T* pstDeviceInfo);

#endif /* AC_SYSM_COMMON_H */



