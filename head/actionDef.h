#ifndef ACTION_DEF_H
#define ACTION_DEF_H

/****************************** OID定义 ******************************************/

#define OID_NE                  "ap"         /* 网元设备，比如A210 */

#define OID_SYSVERSION          "1,3,6,1,4,1,28723,1,2,1,1,6"   /* 系统版本设置 */

#define OID_WIFI0               "wifiModule.0"     /* WIFI0 */
#define OID_WIFI1               "wifiModule.1"     /* WIFI1 */
#define OID_WIFI2               "wifiModule.2"     /* WIFI2 */
#define OID_WIFI3               "wifiModule.3"     /* WIFI3 */

#define OID_AP                  "apBasicSetup"     /* AP(0-15) */
#define OID_AP0                 OID_AP".0"   /* AP0 */
#define OID_AP1                 OID_AP".1"   /* AP1 */
#define OID_AP2                 OID_AP".2"   /* AP2 */
#define OID_AP3                 OID_AP".3"   /* AP3 */
#define OID_AP4                 OID_AP".4"   /* AP4 */
#define OID_AP5                 OID_AP".5"   /* AP5 */
#define OID_AP6                 OID_AP".6"   /* AP6 */
#define OID_AP7                 OID_AP".7"   /* AP7 */
#define OID_AP8                 OID_AP".8"   /* AP8 */
#define OID_AP9                 OID_AP".9"   /* AP9 */
#define OID_AP10                OID_AP".10"  /* AP10 */
#define OID_AP11                OID_AP".11"  /* AP11 */
#define OID_AP12                OID_AP".12"  /* AP12 */
#define OID_AP13                OID_AP".13"  /* AP13 */
#define OID_AP14                OID_AP".14"  /* AP14 */
#define OID_AP15                OID_AP".15"  /* AP15 */

#define OID_VLAN                "vlan"   

#define OID_VLAN1               OID_VLAN".1"   /* VLAN1 */
#define OID_VLAN2               OID_VLAN".2"   /* VLAN2 */
#define OID_VLAN3               OID_VLAN".3"   /* VLAN3 */
#define OID_VLAN4               OID_VLAN".4"   /* VLAN4 */
#define OID_VLAN5               OID_VLAN".5"   /* VLAN5 */
#define OID_VLAN6               OID_VLAN".6"   /* VLAN6 */
#define OID_VLAN7               OID_VLAN".7"   /* VLAN7 */
#define OID_VLAN8               OID_VLAN".8"   /* VLAN8 */
#define OID_VLAN9               OID_VLAN".9"   /* VLAN9 */
#define OID_VLAN10              OID_VLAN".10"  /* VLAN10 */
#define OID_VLAN11              OID_VLAN".11"  /* VLAN11 */
#define OID_VLAN12              OID_VLAN".12"  /* VLAN12 */
#define OID_VLAN13              OID_VLAN".13"  /* VLAN13 */
#define OID_VLAN14              OID_VLAN".14"  /* VLAN14 */
#define OID_VLAN15              OID_VLAN".15"  /* VLAN15 */
#define OID_VLAN16              OID_VLAN".16"  /* VLAN16 */

#define OID_ADHOC0              "adhocBasicSetup.0"     /* ADHOC0 */
#define OID_ADHOC1              "adhocBasicSetup.1"     /* ADHOC1 */
#define OID_ADHOC2              "adhocBasicSetup.2"     /* ADHOC2 */
#define OID_ADHOC3              "adhocBasicSetup.3"     /* ADHOC3 */

#define OID_ENET0               "enetBasicSetup.0"     /* IXP0 */
#define OID_ENET1               "enetBasicSetup.1"     /* IXP1 */

#define OID_OMCSET              "1,3,6,1,4,1,28723,1,3,1"       /* OMC整理修改 */
#define OID_OMCCFGALL           "1,3,6,1,4,1,28723,1,3,2"       /* 全部设置 */
#define OID_TOPOINFO            "1,3,6,1,4,1,28723,1,3,3"       /* 拓扑信息 */
#define OID_ROGUEAPNFO          "1,3,6,1,4,1,28723,1,3,4"       /* 非法AP信息 */
#define OID_STATOPOINFO			"1,3,6,1,4,1,28723,1,3,5"       /* 终端拓扑信息 */
#define OID_GLOBALSTATINFO		"1,3,6,1,4,1,28723,1,3,6"       /* 全局统计信息 */
#define OID_AIRSTATSINFO		"1,3,6,1,4,1,28723,1,3,7"       /* 空口统计信息 */
#define OID_ADHOCLINKSTATSINFO	"1,3,6,1,4,1,28723,1,3,8"       /* 回传链路统计信息 */
#define OID_ENETSTATSINFO		"1,3,6,1,4,1,28723,1,3,9"       /* 网络侧统计信息 */
#define OID_DEVABSTRACTINFO		"1,3,6,1,4,1,28723,1,3,11"       /* ap侧概要信息 */

#define OID_OMASTART            "1,3,6,1,4,1,28723,1,3,10"      /* OMA启动 */
/* hc modified for cmcc test 2009-7-28 */
#define OID_ASSOCSTATINFO		"1,3,6,1,4,1,28723,1,3,12"       /* 关联sta  统计信息 */


#define OID_ALARMREPORT         "1,3,6,1,4,1,28723,1,3,20"      /* 告警上报 */
#define OID_EVENTREPORT         "1,3,6,1,4,1,28723,1,3,21"      /* 事件上报 */
#define OID_PERFREPORT          "1,3,6,1,4,1,28723,1,3,30"      /* 性能上报 */
#define OID_PERFREPORT_CFG      "1,3,6,1,4,1,28723,1,3,31"      /* 性能任务下发 */

#define OID_UPDATESOFTWARE      "1,3,6,1,4,1,28723,1,3,40"      /* 软件升级 */

#define OID_TIMERHANDLE         "1,3,6,1,4,1,28723,1,100,1"     /* 定时器处理 */
#define OID_OMACTLHANDLE        "1,3,6,1,4,1,28723,1,200,1"     /* 内部控制（打印）*/

#define OID_SLAVENOTIFYMASTER   "1,3,6,1,4,1,28723,1,1000,1"

#define OID_SLAVEMACFILTER      "1,3,6,1,4,1,28723,1,2,3,3,1,5,0"
#define OID_SLAVEENDUSER        "1,3,6,1,4,1,28723,1,2,3,3,1,6,0"
#define OID_SLAVEACCESSDENY     "1,3,6,1,4,1,28723,1,2,3,3,1,7,0"

#define OID_SLAVENEIGHBOR       "1,3,6,1,4,1,28723,1,2,5,2,6,0"

#define OID_SLAVEPERFFLOW       "1,3,6,1,4,1,28723,1,1001,1"        /* 流量统计 */
#define OID_SLAVEPERFVAP        "1,3,6,1,4,1,28723,1,1001,2"        /* VAP统计 */
#define OID_SLAVEPERFADHOC      "1,3,6,1,4,1,28723,1,1001,3"        /* ADHOC统计 */

/****************************** 结构定义 ******************************************/
/* 操作ID枚举 */
typedef enum
{
    ACTION_ID_BASIC_SETUP = 0, /* 必须从0开始 */

    ACTION_ID_PERFREPORTACK,
    ACTION_ID_UPDATESOFTWARE,

    ACTION_ID_TIMERHANDLE,
    ACTION_ID_OMACTLHANDLE,

    ACTION_ID_NUM   /* 必须放在最后面，刚好表示总的Action个数 */
}ACTION_ID_E;


#endif /* ACTION_DEF_H */



