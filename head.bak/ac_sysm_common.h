#ifndef AC_SYSM_COMMON_H
#define AC_SYSM_COMMON_H


#define AC_SYSM_ALARM_STATE_ALARM           1
#define AC_SYSM_ALARM_STATE_ALARM_CLEAR     0
#define AC_SYSM_ALARM_STATE_ALARM_SAME      2

/* ��ʱ�� */
#define TIMER_AC_SYSM_SCAN_TIMER                (TIMER0)
#define EV_AC_SYSM_SCAN_TIMER_MSG               (EV_TIMER0)

#define EV_AC_SYSM_SET_TIME_REQ_MSG             ((UINT16)EV_SYSM_BEGIN + 0)
#define EV_AC_SYSM_SET_TIME_RSP_MSG             ((UINT16)EV_SYSM_BEGIN + 1)

/* �������� */
typedef struct 
{
    UINT32      ulScanTime;         /* ��ʱɨ��ʱ�䣬��λ�룬0��ʾ�رոù��� */
}AC_SYSM_LOCAL_CFG_T;

typedef struct 
{
    UINT32  ulAlarmResendTime;  /* �澯�ظ�����ʱ�䣺�¸澯�����󣬸��¸澯���ݵ���С�ȴ�ʱ�䣬��λ���� */

    UINT32  ulCpuLoadPeriod;    /* CPU���ɲ������� */
    UINT32  ulCpuLoadCount;     /* CPU���ɳ������� */
    UINT32  ulCpuLoadHigh;      /* CPU���ɸ澯�������� */
    UINT32  ulCpuLoadLow;       /* CPU���ɸ澯�������� */

    UINT32  ulMemLoadPeriod;	/* �ڴ������ʲ������� */
    UINT32  ulMemLoadCount;	    /* �ڴ������ʳ������� */
    UINT32  ulMemLoadHigh;	    /* �ڴ������ʸ澯�������� */
    UINT32  ulMemLoadLow;       /* �ڴ������ʸ澯�������� */

    UINT32  ulDiskLoadPeriod;	/* ���������ʲ������� */
    UINT32  ulDiskLoadCount;	/* ���������ʳ������� */
    UINT32  ulDiskLoadHigh;	    /* ���������ʸ澯�������� */
    UINT32  ulDiskLoadLow;      /* ���������ʸ澯�������� */

    UINT32  ulTempPeriod;       /* �豸�¶Ȳ������� */
    UINT32  ulTempCount;	    /* �豸�¶ȳ�������	*/
    UINT32  ulTempHigh;	        /* �豸�¶ȸ澯�������� */
    UINT32  ulTempLow;	        /* �豸�¶ȸ澯�������� */

    UINT32  ulEnetPeriod;       /* �������״̬���� */
    UINT32  ulEnetCount;	    /* �������״̬����	*/
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
    UINT32          aulCpu[AC_SYSM_MAX_CPU_COUNT];              /* ��λ% */

    UINT32          ulMemIndex;
    UINT32          aulFreeMemSize[AC_SYSM_MAX_MEM_COUNT];      /* ��λM */
    UINT32          aulMemUsage[AC_SYSM_MAX_MEM_COUNT];         /* �ڴ�ʹ���ʣ���λ% */

    UINT32          ulDiskIndex;
    UINT32          aulFreeDiskSize[AC_SYSM_MAX_DISK_COUNT];    /* ��λM */
    UINT32          aulDiskUsage[AC_SYSM_MAX_DISK_COUNT];       /* �ڴ�ʹ���ʣ���λ% */

    UINT32          ulTempIndex;
    INT32           aiTemp[AC_SYSM_MAX_TEMP_COUNT];            /* ��λ:�� */

	/* 2010-3-25 pyy �޸�*/		
#if 0	
    UINT32          ulEnetIndex;
    UINT32          aulEnet[AC_ENETPORT_NUM_MAX][AC_SYSM_MAX_ENET_COUNT];  
#endif
	UINT32          aulEnet[AC_ENETPORT_NUM_MAX];
	UINT32		aulEnetLastAlarmState[AC_ENETPORT_NUM_MAX];
	UINT32		aulLastAlarmTime[AC_ENETPORT_NUM_MAX];
}AC_SYSM_ALARM_INFO_T;
    
/* ���ͳ����Ŀ */
typedef struct 
{
    UINT32      ulOfflineUserNum;  
    
}AC_SYSM_PERF_INFO_T;

/* ����ʱ�� */
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
    UINT32      ulRet;          /* Ӧ����,0:�ɹ� 1 ʧ�� */  
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

/* ȫ������ */
typedef struct 
{
    //UINT32                      ulCfgID;        /* ÿ���������ݱ��������1����ʼֵΪupTime */

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



