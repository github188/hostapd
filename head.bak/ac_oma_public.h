#ifndef AC_OMA_PUBLIC_H
#define AC_OMA_PUBLIC_H

/***************************************************************/

#define AC_OMA_WTPID_MIN               AC_WTPID_MIN
#define AC_OMA_WTPID_MAX              AC_WTPID_MAX

// 2009-09-30 fengjing add
#define AC_OMA_MOC_AC                            ((UINT32)0x02000001)
#define AC_OMA_MOC_ACBASICSETUP                  ((UINT32)0x02000102)

#define AC_OMA_MOC_WTP                           ((UINT32)0x01000001)
#define AC_OMA_MOC_WTPSYSBASICSETUP              ((UINT32)0x01000102)

#define AC_OMA_MOC_WTPWIFIDEVICE                 ((UINT32)0x01000202)
#define AC_OMA_MOC_WTPWIFIDEVICEBASICSETUP       ((UINT32)0x01000203)

#define AC_OMA_MOC_WTPAPVAP                      ((UINT32)0x01000303)
#define AC_OMA_MOC_WTPAPBASICSETUP               ((UINT32)0x01000304)

#define AC_OMA_MOC_WTPADHOC                      ((UINT32)0x01000402)
#define AC_OMA_MOC_WTPADHOCBASICSETUP            ((UINT32)0x01000403)

#define AC_OMA_MOC_WTPENETBASICSETUP             AC_DB_MOC_WTPENETBASICSETUP
#define AC_OMA_MOC_VLAN                          ((UINT32)0x01000802)
#define AC_OMA_MOC_WIFIMODULE                    ((UINT32)0x01000F02)

/**************************** 宏定义 ***************************/
/* OMA内部消息 */
#define EV_AC_OMA_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 100)    /* 上报告警请求 */
#define EV_AC_OMA_CLEAR_ALARM_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 101)    /* 上报告警清除请求 */

#define EV_AC_OMA_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 104)    /* 上报事件请求 */

#define EV_AC_OMA_REPORT_PERF_REQ_MSG 	        ((UINT16)EV_OMA_BEGIN + 110)    /* 请求上报性能统计 */
#define EV_AC_OMA_REPORT_PERF_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 111)    /* 性能统计应答 */

#define EV_AC_OMA_EVENT_SIMU_MSG						((UINT16)EV_OMA_BEGIN + 112)		/* 事件模拟消息*/
#define EV_AC_OMA_ALARM_REPORT_SIMU_MSG			((UINT16)EV_OMA_BEGIN + 113)		/* 告警模拟消息*/
#define EV_AC_OMA_ALARM_CLEAR_SIMU_MSG				((UINT16)EV_OMA_BEGIN + 114)		/* 告警模拟消息*/
 
/******************************************告警**************************************************/
/* AC与OMC之间消息 */
#define EV_AC_OMC_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 200)    /* 上报告警请求 */
#define EV_AC_OMC_REPORT_ALARM_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 201)    /* 上报告警应答 */
#define EV_AC_OMC_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 202)    /* 上报事件请求 */
#define EV_AC_OMC_REPORT_EVENT_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 203)    /* 上报事件应答 */

#define EV_AC_OMC_REPORT_ALARM_CLEAR_IND_MSG    ((UINT16)EV_OMA_BEGIN + 204)    /* 上报告警清除 */

// 2009-11-03 fengjing add
#define EV_AC_OMC_REPORT_ALARM_BATCH_REQ_MSG  ((UINT16)EV_OMA_BEGIN + 206)     /* 批量上报告警请求 */
#define EV_AC_OMC_REPORT_ALARM_BATCH_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 207)    /* 批量告警应答 */
#define EV_AC_OMC_REPORT_EVENT_BATCH_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 208)    /* 批量上报事件请求 */
#define EV_AC_OMC_REPORT_EVENT_BATCH_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 209)    /* 批量事件应答 */

/* 2009-09-03 fengjing add AP-OMA<->AC-OMA 告警事件消息 */
#define EV_AP_OMA_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 210)    /* 上报告警请求 */
#define EV_AP_OMA_REPORT_ALARM_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 211)    /* 上报告警应答 */
#define EV_AP_OMA_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 212)    /* 上报事件请求 */
#define EV_AP_OMA_REPORT_EVENT_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 213)    /* 上报事件应答 */

 /* 2012-04-11 ldm modify */
#define EV_AP_OMA_REPORT_TRAP_HIDE_MSG          ((UINT16)EV_OMA_BEGIN + 270)    /* 通知屏蔽告警消息*/

/******************************************性能******************************************************/
#define EV_AC_OMC_REPORT_PERF_REQ_MSG 	        ((UINT16)EV_OMA_BEGIN + 300)    /* 上报性能统计请求 */
#define EV_AC_OMC_REPORT_PERF_RSP_MSG 	        ((UINT16)EV_OMA_BEGIN + 301)    /* 上报性能统计应答 */

#define EV_AC_OMC_SET_PERF_TASK_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 305)     /* 设置性能统计任务请求 */
#define EV_AC_OMC_SET_PERF_TASK_RSP_MSG         ((UINT16)EV_OMA_BEGIN + 306)     /* 设置性能统计任务应答 */

/* 2009-09-03 fengjing add AP-OMA<->AC-OMA性能消息 */
#define EV_AP_OMA_REPORT_PERF_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 310)    /* 上报性能统计请求 */
#define EV_AP_OMA_REPORT_PERF_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 311)    /* 上报性能统计应答 */

/******************************************动态信息***********************************************/
#define EV_AC_OMC_REPORT_STATEUPDATE_IND_MSG    ((UINT16)EV_OMA_BEGIN + 400)     /* 上报状态信息 */

#define EV_AC_OMC_REPORT_USERONLINE_IND_MSG     ((UINT16)EV_OMA_BEGIN + 403)     /* 上报用户上线 */
#define EV_AC_OMC_REPORT_USEROFFLINE_IND_MSG    ((UINT16)EV_OMA_BEGIN + 404)     /* 上报用户离线 */
#define EV_AC_OMC_REPORT_USERPOS_IND_MSG        ((UINT16)EV_OMA_BEGIN + 405)     /* 上报用户位置信息 */
#define EV_AC_OMC_REPORT_DYNPOWER_IND_MSG       ((UINT16)EV_OMA_BEGIN + 406)     /* 无线设备当前功率信息上报 */

/* 增加上报AP当前IP地址信息 */
#define EV_AC_OMC_REPORT_APDYNAIP_IND_MSG       ((UINT16)EV_OMA_BEGIN + 407)     /* AP当前IP地址信息上报 */
#define EV_AC_OMC_REPORT_ACIP_IND_MSG           ((UINT16)EV_OMA_BEGIN + 408)     /* AC当前IP地址信息上报 */
#define EV_AC_OMC_REPORT_APSN_IND_MSG           ((UINT16)EV_OMA_BEGIN + 409)     /* AP当前SN信息上报 */
/* 2009-10-15 fengjing add */
#define EV_AC_OMC_REPORT_APSWVER_IND_MSG        ((UINT16)EV_OMA_BEGIN + 410)    /* AP当前软件版本信息上报 */

/* 2009-09-07 fengjing add */
#define EV_AC_OMC_REPORT_MAXPOWER_IND_MSG       ((UINT16)EV_OMA_BEGIN + 415)     /* AP无线设备最大发射功率上报 */
#define EV_AC_OMC_REPORT_VAPMAC_IND_MSG         ((UINT16)EV_OMA_BEGIN + 416)     /* VAP 设备MAC地址上报 */
#define EV_AC_OMC_REPORT_ADHOCMAC_IND_MSG       ((UINT16)EV_OMA_BEGIN + 417)     /* ADHOC设备MAC地址上报 */

/* add master-slave switch */
#define EV_AC_OMC_REPORT_MSSTATE_IND_MSG        ((UINT16)EV_OMA_BEGIN + 418)     /* 主备状态上报 */

/* 2008/09/18 冯静 增加 通知网元重启消息 */
#define EV_AC_OMC_REPORT_REBOOT_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 420)
#define EV_AC_OMC_REPORT_REBOOT_RSP_MSG         ((UINT16)EV_OMA_BEGIN + 421)

/* add file transfer */
#define EV_AC_OMC_REPORT_FILETRANSFER_IND_MSG   ((UINT16)EV_OMA_BEGIN + 422)

/* add version report */
#define EV_AC_OMC_REPORT_VERSION_IND_MSG        ((UINT16)EV_OMA_BEGIN + 425)

/* 2011-7-6 ymt add:wtp mac update*/
#define EV_AC_OMC_REPORT_APMAC_IND_MSG          ((UINT16)EV_OMA_BEGIN + 426)

/* add by gwx 2014-2-25 for task1265 */
#define EV_AC_OMC_REPORT_APPRODUCTTYPE_IND_MSG          ((UINT16)EV_OMA_BEGIN + 427)

/* add reset request/response */
#define EV_AC_OMC_RESET_REQ_MSG                 ((UINT16)EV_OMA_BEGIN + 440)
#define EV_AC_OMC_RESET_RSP_MSG                 ((UINT16)EV_OMA_BEGIN + 441)

/* OMC/AC-WEB查询网元配置数据版本信息 */
#define EV_AC_OMC_GET_NECFGVERSION_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 450)
#define EV_AC_OMC_GET_NECFGVERSION_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 451)

/* Agent->OMA AP上报级别的变化 */
#define EV_AC_OMA_REPORT_APREPORTLEVEL_IND_MSG  ((UINT16)EV_OMA_BEGIN + 460)

/* OMC/AC-WEB查询AC主备状态信息 */
#define EV_AC_OMC_GET_MSSTATUS_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 462)
#define EV_AC_OMC_GET_MSSTATUS_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 463)

/*************************************AC-WEB Request***********************/
/* add web request msg type */
#define EV_AC_WEB_GET_TBLINDEXLIST_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 501)
#define EV_AC_WEB_GET_TBLINDEXLIST_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 502)
#define EV_AC_WEB_GET_TBLOBJVALUE_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 503)
#define EV_AC_WEB_GET_TBLOBJVALUE_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 504)

#define EV_AC_WEB_GET_ACTIVEALARM_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 505)
#define EV_AC_WEB_GET_ACTIVEALARM_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 506)
#define EV_AC_WEB_CLEAR_ALARM_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 507)
#define EV_AC_WEB_CLEAR_ALARM_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 508)

#define EV_AC_WEB_GET_LOG_REQ_MSG               ((UINT16)EV_OMA_BEGIN + 510)
#define EV_AC_WEB_GET_LOG_RSP_MSG               ((UINT16)EV_OMA_BEGIN + 511)

#define EV_AC_WEB_GET_TBLRECLIST_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 512)
#define EV_AC_WEB_GET_TBLRECLIST_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 513)

#define EV_AC_WEB_EXPORT_MOS_REQ_MSG            ((UINT16)EV_OMA_BEGIN + 514)
#define EV_AC_WEB_EXPORT_MOS_RSP_MSG            ((UINT16)EV_OMA_BEGIN + 515)

#define EV_AC_WEB_GET_NEINFO_REQ_MSG            ((UINT16)EV_OMA_BEGIN + 516)
#define EV_AC_WEB_GET_NEINFO_RSP_MSG            ((UINT16)EV_OMA_BEGIN + 517)

// 2009/04/23 fengjing add web get swverlib msg
#define EV_AC_WEB_GET_SWVERLIB_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 518)
#define EV_AC_WEB_GET_SWVERLIB_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 519)

// 2009/04/23 fengjing add web ne sw version import notify msg
#define EV_AC_WEB_IMPORT_SWVER_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 520)
#define EV_AC_WEB_IMPORT_SWVER_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 521)

#define EV_AC_WEB_SW_ACTIVATE_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 522)
#define EV_AC_WEB_SW_ACTIVATE_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 523)

// 2009-10-28 fengjing add
#define EV_AC_OMC_UPLOAD_CFGDATAFILE_REQ_MSG ((UINT16)EV_OMA_BEGIN + 530)
#define EV_AC_OMC_UPLOAD_CFGDATAFILE_RSP_MSG ((UINT16)EV_OMA_BEGIN + 531)

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
/* 2012-1-24 wubin add:license 验证消息结果 */
#define EV_AC_WEB_GET_AC_LICENSE_REQ_MSG ((UINT16)EV_OMA_BEGIN + 532)
#define EV_AC_WEB_GET_AC_LICENSE_RSP_MSG ((UINT16)EV_OMA_BEGIN + 533)
#define EV_AC_WEB_SEND_AC_LICENSE_REQ_MSG ((UINT16)EV_OMA_BEGIN + 534)
#define EV_AC_WEB_SEND_AC_LICENSE_RSP_MSG ((UINT16)EV_OMA_BEGIN + 535)
#define EV_AC_WEB_CHANGE_AC_LICENSE_SVIP_REQ_MSG ((UINT16)EV_OMA_BEGIN + 536)
#define EV_AC_WEB_CHANGE_AC_LICENSE_SVIP_RSP_MSG ((UINT16)EV_OMA_BEGIN + 537)
#define EV_AC_WEB_GET_AC_LICENSE_TESTTIME_REQ_MSG ((UINT16)EV_OMA_BEGIN + 538)
#define EV_AC_WEB_GET_AC_LICENSE_TESTTIME_RSP_MSG ((UINT16)EV_OMA_BEGIN + 539)
#define EV_AC_WEB_GET_AC_LICENSE_SVIP_REQ_MSG ((UINT16)EV_OMA_BEGIN + 550)
#define EV_AC_WEB_GET_AC_LICENSE_SVIP_RSP_MSG ((UINT16)EV_OMA_BEGIN + 551)
#define EV_AC_WEB_GET_AP_LICENSE_REQ_MSG ((UINT16)EV_OMA_BEGIN + 552)
#define EV_AC_WEB_GET_AP_LICENSE_RSP_MSG ((UINT16)EV_OMA_BEGIN + 553)
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */

/***************************************日志*******************************/
#define EV_AC_OMC_ADMIN_LOG_IND_MSG           ((UINT16)EV_OMA_BEGIN + 540)

/***************************************软件*******************************/

/* 2008/08/30 冯静 增加软件相关消息号，以后可能这部分宏定义需要放到其他模块中，还是就在OMA侧做 */
#define EV_AC_OMC_SW_DOWNLOAD_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 600)       /* 请求软件版本下载 */
#define EV_AC_OMC_SW_DOWNLOAD_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 601)       /* 应答软件版本下载 */
#define EV_AC_OMC_SW_ACTIVATE_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 604)       /* 请求软件版本生效 */
#define EV_AC_OMC_SW_ACTIVATE_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 605)       /* 应答软件版本生效 */
#define EV_AC_OMC_SW_VERSION_STATE_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 607)       /* 查询软件版本状态请求 */
#define EV_AC_OMC_SW_VERSION_STATE_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 608)       /* 查询软件版本状态应答 */

/* oma download sw version finished/failed,notify omc */
#define EV_AC_OMC_SW_DOWNLOAD_IND_MSG           ((UINT16)EV_OMA_BEGIN + 610)

/* oma send ftp download msg to oma,single processing */
#define EV_AC_OMC_SW_FTPDOWNLOAD_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 620)       /* 另外发起软件下载流程 */

/* oma ftp download sw verfile,and notify other app module activate this sw version */
//#define EV_AC_APP_SW_ACTIVATE_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 621)       /* 通知其他应用模块配置生效 */

/* 2009-10-20 fengjing add delete sw msg */
#define EV_AC_OMC_SW_DELETE_REQ_MSG               ((UINT16)EV_OMA_BEGIN + 621)     /* 请求删除网元软件版本 */
#define EV_AC_OMC_SW_DELETE_RSP_MSG               ((UINT16)EV_OMA_BEGIN + 622)    /* 应答删除网元软件版本 */

/**************************************透传********************************/
/* add omc request wtp config change transfer to wtp ne */
/* including sys operations */
#define EV_AC_OMC_COMMAND_RELAY_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 700)
#define EV_AC_OMC_COMMAND_RELAY_RSP_MSG         ((UINT16)EV_OMA_BEGIN + 701)
#define EV_AC_OMC_COMMAND_RELAY_IND_MSG         ((UINT16)EV_OMA_BEGIN + 702)

/* 2009-08-20 fengjing add begin */
/* 查询AP节点信息 */
#define EV_AC_OMC_GET_AP_NODEINFO_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 708)
#define EV_AC_OMC_GET_AP_NODEINFO_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 709)

/* 查询AP邻居信息 */
#define EV_AC_OMC_GET_AP_AODVNEIGHBOR_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 710)
#define EV_AC_OMC_GET_AP_AODVNEIGHBOR_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 711)

/* 查询AP路径信息 */
#define EV_AC_OMC_GET_AP_ROUTEPATH_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 712)
#define EV_AC_OMC_GET_AP_ROUTEPATH_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 713) 

/* 查询AP接入终端信息 */
#define EV_AC_OMC_GET_AP_ENDUSER_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 714)
#define EV_AC_OMC_GET_AP_ENDUSER_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 715)
	 
/* 查询恶意AP */
#define EV_AC_OMC_GET_AP_ROGUEAPINFO_REQ_MSG    ((UINT16)EV_OMA_BEGIN + 716)
#define EV_AC_OMC_GET_AP_ROGUEAPINFO_RSP_MSG    ((UINT16)EV_OMA_BEGIN + 717)
	 
/* 查询可疑端站列表 */
#define EV_AC_OMC_GET_AP_INVALIDSTAINFO_REQ_MSG ((UINT16)EV_OMA_BEGIN + 718)
#define EV_AC_OMC_GET_AP_INVALIDSTAINFO_RSP_MSG ((UINT16)EV_OMA_BEGIN + 719)
	 
/* AP重启 */
#define EV_AC_OMC_AP_REBOOT_REQ_MSG             ((UINT16)EV_OMA_BEGIN + 720)
#define EV_AC_OMC_AP_REBOOT_RSP_MSG             ((UINT16)EV_OMA_BEGIN + 721)

/* PING测试 */
#define EV_AC_OMC_AP_PINGTEST_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 722)
#define EV_AC_OMC_AP_PINGTEST_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 723)
#define EV_AC_OMC_AP_PINGSUMMARY_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 724)
#define EV_AC_OMC_AP_PINGSUMMARY_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 725)
	 
/* 设置AP设备时间 */
#define EV_AC_OMC_AP_SETTIME_REQ_MSG            ((UINT16)EV_OMA_BEGIN + 726)
#define EV_AC_OMC_AP_SETTIME_RSP_MSG            ((UINT16)EV_OMA_BEGIN + 727)
	 
/* 清除非法设备历史 */
#define EV_AC_OMC_AP_CLEARILLEGALDEVHISTORY_REQ_MSG ((UINT16)EV_OMA_BEGIN + 728)
#define EV_AC_OMC_AP_CLEARILLEGALDEVHISTORY_RSP_MSG ((UINT16)EV_OMA_BEGIN + 729)
	 	 
/* 清除攻击检测历史 */
#define EV_AC_OMC_AP_CLEARATTACKHISTORY_REQ_MSG ((UINT16)EV_OMA_BEGIN + 730)
#define EV_AC_OMC_AP_CLEARATTACKHISTORY_RSP_MSG ((UINT16)EV_OMA_BEGIN + 731)
	 
/* 清除攻击检测统计 */
#define EV_AC_OMC_AP_CLEARATTACKSTATIC_REQ_MSG  ((UINT16)EV_OMA_BEGIN + 732)
#define EV_AC_OMC_AP_CLEARATTACKSTATIC_RSP_MSG  ((UINT16)EV_OMA_BEGIN + 733)

/* 设置设备心跳周期（待定）*/
#define EV_AC_OMC_AP_SETHBPERIOD_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 734)
#define EV_AC_OMC_AP_SETHBPERIOD_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 735)
	
/* 2009-09-07 fengjing add */
#define EV_AC_OMC_AP_GETTOTALCFG_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 740)
#define EV_AC_OMC_AP_GETTOTALCFG_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 741)

/* 查询AP侧设备摘要信息 */
#define EV_AC_OMC_GET_AP_ABSTRACTINFO_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 750)
#define EV_AC_OMC_GET_AP_ABSTRACTINFO_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 751)
		
/* 查询AP Mesh回传链路列表信息 */
#define EV_AC_OMC_GET_AP_ADHOCLINKSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 752)
#define EV_AC_OMC_GET_AP_ADHOCLINKSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 753)
	
/* 查询AP侧用户连接统计 */
#define EV_AC_OMC_GET_AP_TOTALSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 754)
#define EV_AC_OMC_GET_AP_TOTALSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 755)

/* 查询AP侧空口收发统计 */
#define EV_AC_OMC_GET_AP_WIFISTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 756)
#define EV_AC_OMC_GET_AP_WIFISTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 757)
	
/* 查询AP侧以太网收发统计 */
#define EV_AC_OMC_GET_AP_IFSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 758)
#define EV_AC_OMC_GET_AP_IFSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 759)
			 
/* 查询AP侧关联统计 */
#define EV_AC_OMC_GET_AP_ASSOSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 770)
#define EV_AC_OMC_GET_AP_ASSOSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 771)

/* 2010-4-11 pyy 辽宁电信网管测试新增: 获取卡信道接收失败统计信息*/
#define EV_AC_OMC_GET_VDEV_ICSTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 772)
#define EV_AC_OMC_GET_VDEV_ICSTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 773)

/* 2010/05/15 fengjing add */
#define EV_AC_OMC_GET_AP_MGTSTAT_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 774)
#define EV_AC_OMC_GET_AP_MGTSTAT_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 775)

/* 2010-08-26 fengjing 增加:获取邻居AP信息 */
#define EV_AC_OMC_GET_AP_NEIGHBORAP_REQ_MSG     ((UINT16)EV_OMA_BEGIN + 776)
#define EV_AC_OMC_GET_AP_NEIGHBORAP_RSP_MSG     ((UINT16)EV_OMA_BEGIN + 777)

/* 查询AP软件版本下载状态 */
#define EV_AC_OMC_AP_SWFILESTATE_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 760)
#define EV_AC_OMC_AP_SWFILESTATE_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 761)
#define EV_AC_OMC_AP_SWFILESTATE_IND_MSG      ((UINT16)EV_OMA_BEGIN + 762)
/* 2009-08-20 fengjing add end */

/* 2010/05/13 fengjing add */
#define EV_AC_OMC_GET_AP_STATSAMPLE_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 781)       
#define EV_AC_OMC_GET_AP_STATSAMPLE_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 782)

/* 2010/07/26 fengjing cmcc test */
#define EV_AC_OMC_GET_AP_RTCOLLECT_REQ_MSG    ((UINT16)EV_OMA_BEGIN+783)
#define EV_AC_OMC_GET_AP_RTCOLLECT_RSP_MSG    ((UINT16)EV_OMA_BEGIN+784)

#define EV_AC_OMC_AP_GET_COLLECTPARAM_REQ_MSG	((UINT16)EV_OMA_BEGIN+785)
#define EV_AC_OMC_AP_GET_COLLECTPARAM_RSP_MSG	((UINT16)EV_OMA_BEGIN+786)

/* 常规采集上报消息号 */
#define EV_AC_OMC_AP_DYNAINFO_IND_MSG	((UINT16)EV_OMA_BEGIN+787)
/* 实时采集上报消息号 */
#define EV_AC_OMC_AP_RTDYNAINFO_IND_MSG	((UINT16)EV_OMA_BEGIN+788)

/* add by gwx 2014-5-18 for ruijie 故障信息一键收集*/
#define EV_AC_OMA_GET_AP_RUNINFO_REQ_MSG	((UINT16)EV_OMA_BEGIN + 791)
#define EV_AC_OMA_GET_AP_RUNINFO_RSP_MSG	((UINT16)EV_OMA_BEGIN + 792)

/*****************************************查询AC动态信息******************/
/* OMC/WEB<->AC-OMA */
/* 增加动态信息获取消息 */
#define EV_AC_OMC_GET_AC_DYNAINFO_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 800)
#define EV_AC_OMC_GET_AC_DYNAINFO_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 801)
#define EV_AC_OMC_GET_AC_WTPACCESS_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 811)

/* AC-OMA<->AC-APP */
/* AC-OMA<->AC-APP GET AC DYNA INFO MSG DEFINITION */
#define EV_AC_OMA_GET_AC_DEVICEABSTRACT_REQ_MSG  	((UINT16)EV_OMA_BEGIN + 900)			/* AC设备摘要信息*/
#define EV_AC_OMA_GET_AC_DEVICEABSTRACT_RSP_MSG  ((UINT16)EV_OMA_BEGIN + 901)

#define EV_AC_OMA_GET_AC_WTPACCESS_REQ_MSG       	((UINT16)EV_OMA_BEGIN + 902)			/* AP信息列表*/
#define EV_AC_OMA_GET_AC_WTPACCESS_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 903)

#define EV_AC_OMA_GET_AC_USERACCESS_REQ_MSG      	((UINT16)EV_OMA_BEGIN + 904)			/* 用户信息列表*/
#define EV_AC_OMA_GET_AC_USERACCESS_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 905)

#define EV_AC_OMA_GET_AC_DHCPSTAT_REQ_MSG			((UINT16)EV_OMA_BEGIN + 906)			/* DHCP统计信息*/
#define EV_AC_OMA_GET_AC_DHCPSTAT_RSP_MSG			((UINT16)EV_OMA_BEGIN + 907)

#define EV_AC_OMA_GET_AC_DHCPALLOCATE_REQ_MSG    	((UINT16)EV_OMA_BEGIN + 908)			/* DHCP IP地址分配信息*/
#define EV_AC_OMA_GET_AC_DHCPALLOCATE_RSP_MSG    	((UINT16)EV_OMA_BEGIN + 909)

#define EV_AC_OMA_GET_AC_IFSTAT_REQ_MSG          		((UINT16)EV_OMA_BEGIN + 910)			/* AC接口统计(有线)*/
#define EV_AC_OMA_GET_AC_IFSTAT_RSP_MSG         	 	((UINT16)EV_OMA_BEGIN + 911)

#define EV_AC_OMA_GET_AC_VAPWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 912)			/* AC接口统计(无线): 获取所有VAP的空口统计信息*/
#define EV_AC_OMA_GET_AC_VAPWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 913)

#define EV_AC_OMA_GET_AC_VAPUSERACCSTAT_REQ_MSG	((UINT16)EV_OMA_BEGIN + 914)			/* AC用户连接统计(无线):获取所有VAP的用户连接统计信息*/
#define EV_AC_OMA_GET_AC_VAPUSERACCSTAT_RSP_MSG	((UINT16)EV_OMA_BEGIN + 915)

#define EV_AC_OMA_GET_AC_ACIFWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 916)			/* AC接口统计(无线):按照AC接口获取空口统计信息*/
#define EV_AC_OMA_GET_AC_ACIFWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 917)

#define EV_AC_OMA_GET_AC_SSIDWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 918)			/* AC接口统计(无线):按照SSID获取空口统计信息*/
#define EV_AC_OMA_GET_AC_SSIDWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 919)

#define EV_AC_OMA_GET_AC_PORTALSTAT_REQ_MSG      	((UINT16)EV_OMA_BEGIN + 920)			/* WEB认证统计信息*/
#define EV_AC_OMA_GET_AC_PORTALSTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 921)

#define EV_AC_OMA_GET_AC_PPPOESTAT_REQ_MSG      		((UINT16)EV_OMA_BEGIN + 922)			/* PPPOE 认证统计信息*/
#define EV_AC_OMA_GET_AC_PPPOESTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 923)

#define EV_AC_OMA_GET_AC_ACLSTAT_REQ_MSG      		((UINT16)EV_OMA_BEGIN + 924)			/* ACL统计信息*/
#define EV_AC_OMA_GET_AC_ACLSTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 925)

#define EV_AC_OMA_GET_AC_WAPISTAT_REQ_MSG        		((UINT16)EV_OMA_BEGIN + 926)			/* WAPI 统计信息*/
#define EV_AC_OMA_GET_AC_WAPISTAT_RSP_MSG        		((UINT16)EV_OMA_BEGIN + 927)

#define EV_AC_OMA_GET_AC_USERIPINFO_REQ_MSG		((UINT16)EV_OMA_BEGIN + 928)			/* IP地址分配情况统计*/
#define EV_AC_OMA_GET_AC_USERIPINFO_RSP_MSG			((UINT16)EV_OMA_BEGIN + 929)

/* 2009-10-21 fengjing add */
/* 获取AC设备上未注册而尝试连接的AP信息  */
#define EV_AC_OMA_GET_AC_WTPUNREGISTER_REQ_MSG     ((UINT16)EV_OMA_BEGIN + 930)               /* 未注册且尝试关联的AP */
#define EV_AC_OMA_GET_AC_WTPUNREGISTER_RSP_MSG     ((UINT16)EV_OMA_BEGIN + 931)

/* 2010/05/15 fengjing add */
#define EV_AC_OMA_GET_AC_ROAMINGSTAT_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 932)
#define EV_AC_OMA_GET_AC_ROAMINGSTAT_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 933)

/* 2010/08/06 fengjing cmcc test */
/* AC-OMA<->Account 计费统计消息号定义 */
#define EV_AC_OMA_GET_AC_ACCOUNTSTAT_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 934)
#define EV_AC_OMA_GET_AC_ACCOUNTSTAT_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 935)

/* 2010-12-08 fengjing add:AP Portal统计消息 */
#define EV_AC_OMA_GET_AC_APPORTALSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 936)
#define EV_AC_OMA_GET_AC_APPORTALSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 937)

#define EV_AC_OMA_GET_AC_APTRAFFIC_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 938)
#define EV_AC_OMA_GET_AC_APTRAFFIC_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 939)

#define EV_AC_OMA_GET_AC_APUSERSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 940)
#define EV_AC_OMA_GET_AC_APUSERSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 941)

/* 2011/10/25 ldm add */
#define EV_AC_OMA_GET_AC_MSSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 942)
#define EV_AC_OMA_GET_AC_MSSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 943)

/* add by gwx 2014-5-18 for ruijie 故障信息一键收集*/
#define EV_AC_OMA_GET_AC_RUNINFO_REQ_MSG	((UINT16)EV_OMA_BEGIN + 944)
#define EV_AC_OMA_GET_AC_RUNINFO_RSP_MSG	((UINT16)EV_OMA_BEGIN + 945)

/************************************ 告警 ************************************/
/* 告警状态 */
#define AC_OMA_ALARM_STATUS_CLEAR           0		/* 告警清除 */
#define AC_OMA_ALARM_STATUS_RAISE	        1		/* 告警产生 */

/* 告警级别 */
#define AC_OMA_ALARM_LEVEL_FATAL	        1		/* 致命告警 */
#define AC_OMA_ALARM_LEVEL_MAIN		        2		/* 主要告警 */
#define AC_OMA_ALARM_LEVEL_MINOR	        3		/* 次要告警 */
#define AC_OMA_ALARM_LEVEL_WARNING          4		/* 警告告警 */

/* 告警类型 */
#define AC_OMA_ALARM_TYPE_COMMUNICATION  ((UINT32)1) /* 通讯告警 */
#define AC_OMA_ALARM_TYPE_ENVIRONMENT    ((UINT32)2) /* 环境告警 */
#define AC_OMA_ALARM_TYPE_DEVICE         ((UINT32)3) /* 设备告警 */
#define AC_OMA_ALARM_TYPE_HANDLEFAIL     ((UINT32)4) /* 处理错误告警 */
#define AC_OMA_ALARM_TYPE_QOS            ((UINT32)5) /* 服务质量告警 */
#define AC_OMA_ALARM_TYPE_SECURITY       ((UINT32)6) /* 安全告警 */
#define AC_OMA_ALARM_TYPE_OTHER          ((UINT32)0) /* 其他告警 */

/* 告警ID宏定义 */
// 2009/04/25 冯静 修改告警条目
#define AC_OMA_ALARM_ID_WTP_OFFLINE      ((UINT32)10001)     /* AP离线告警 */
#define AC_OMA_ALARM_ID_WTP_USEROVERLOAD ((UINT32)10002)     /* AP用户数负荷过重告警 */

/* 2008/08/26 冯静新增告警条目 */
#define AC_OMA_ALARM_ID_AC_USEROVERLOAD     ((UINT32)10003)     /* AC用户数负荷过重告警 */
#define AC_OMA_ALARM_ID_AC_CPUOVERLOAD      ((UINT32)10004)     /* AC CPU负荷过重告警 */
#define AC_OMA_ALARM_ID_AC_MEMOVERLOAD      ((UINT32)10005)     /* AC内存利用率过高告警 */
#define AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE    ((UINT32)10006)     /* AC与主用3A鉴权服务器断链 */
#define AC_OMA_ALARM_ID_MACCTSRV_OFFLINE    ((UINT32)10007)     /* AC与主用3A计费服务器断链 */
#define AC_OMA_ALARM_ID_SAUTHSRV_OFFLINE    ((UINT32)10008)     /* AC与备用3A鉴权服务器断链 */
#define AC_OMA_ALARM_ID_SACCTSRV_OFFLINE    ((UINT32)10009)     /* AC与备用3A计费服务器断链 */
#define AC_OMA_ALARM_ID_ASSRV_OFFLINE       ((UINT32)10010)     /* AC与AS鉴权服务器断链 */
#define AC_OMA_ALARM_ID_PORTALSRV_OFFLINE   ((UINT32)10011)     /* AC与Portal服务器断链 */
#define AC_OMA_ALARM_ID_ENET_FAULT          ((UINT32)10012)     /* AC网口连接故障 */
#define AC_OMA_ALARM_ID_CHANNEL_QUALITY_LOW	((UINT32)10013)	    /* AP设备无线干扰告警 */
#define AC_OMA_ALARM_ID_DISKUSAGETOOHIGH    ((UINT32)10014)     /* 磁盘利用率过高 */
#define AC_OMA_ALARM_ID_TEMPERATURETOOHIGH  ((UINT32)10015)     /* 温度过高 */
#define AC_OMA_ALARM_ID_CHANNELNUMLESS      ((UINT32)10016)     /* 可供使用的信道数过低告警 */

#define AC_OMA_ALARM_ID_DEVICE_INTERFERENCE_DETECT  ((UINT32)10020)  /* 出现干扰当前信道的设备 */
#define AC_OMA_ALARM_ID_SWVER_DIFF		((UINT32)10021)	/* 2010-1-22 N+1备份功能新增:软件版本不一致告警*/

/* 2010-4-10 pyy 新增*/
#define AC_OMA_ALARM_ID_POWEROFF					((UINT32)10029)	/* 电源掉电告警*/
#define AC_OMA_ALARM_ID_APDHCPADDRESSEXHAUST		((UINT32)10022)	/* AP级DHCP可分配地址耗尽告警*/
#define AC_OMA_ALARM_ID_STADHCPADDRESSEXHAUST		((UINT32)10023)	/* STA级DHCP可分配地址耗尽告警*/
#define AC_OMA_ALARM_ID_APINTERFDETECTED			((UINT32)10024)	/* 邻近AP干扰告警 */
#define AC_OMA_ALARM_ID_ACCOLDREBOOT				((UINT32)10025)	/* AC 冷启动*/
#define AC_OMA_ALARM_ID_ACWARMREBOOT				((UINT32)10026)	/* AC 热启动*/

/* 2010-06-30 fengjing cmcc 新增 */
#define AC_OMA_ALARM_ID_APCOINTERFDETECTED          ((UINT32)10030)      /* AP同频干扰告警 */
#define AC_OMA_ALARM_ID_APNERBORINTERFDETECTED      ((UINT32)10031)      /* AP邻频干扰告警 */

/* 告警原因ID宏定义 */
/* WTP断链告警原因宏定义 */
#define AC_OMA_REASON_WTP_OFFLINE_NORECVDISC   ((UINT32)1)	/* 没有收到发现请求 */
#define AC_OMA_REASON_WTP_OFFLINE_NORECVCONN   ((UINT32)2)  /* 没有收到连接请求 */
#define AC_OMA_REASON_WTP_OFFLINE_AUTHFAIL     ((UINT32)3)  /* 连接鉴权失败 */
/*2011-11-02 ldm add  */
#define AC_OMA_REASON_WTP_OFFLINE_REBOOT         ((UINT32)4)  /* AP重启 */
#define AC_OMA_REASON_WTP_OFFLINE_OTHER        ((UINT32)100)  /* 其他原因 */

/* WTP负荷过重原因宏定义 */
#define AC_OMA_REASON_WTP_USEROVERLOAD		((UINT32)0)	/* WTP负荷过重 */

/* 2008/08/26 冯静 增加新增告警条目的告警原因码 */
/* AC用户数负荷过重原因宏定义 */
#define AC_OMA_REASON_AC_USEROVERLOAD       ((UINT32)0) /* AC用户数负荷过重 */

/* AC CPU负荷过重原因宏定义 */
#define AC_OMA_REASON_AC_CPUOVERLOAD        ((UINT32)0) /* AC CPU负荷过重 */

/* AC 内存负荷过重原因宏定义 */
#define AC_OMA_REASON_AC_MEMOVERLOAD        ((UINT32)0) /* AC内存负荷过重 */

/* AC与主用3A鉴权服务器断链原因宏定义 */
#define AC_OMA_REASON_MAUTHSRV_OFFLINE       ((UINT32)0) /* AC与主用3A鉴权服务器断链 */

/* AC与主用3A计费服务器断链原因宏定义 */
#define AC_OMA_REASON_MACCTSRV_OFFLINE       ((UINT32)0) /* AC与主用3A计费服务器断链 */

/* AC与备用3A鉴权服务器断链原因宏定义 */
#define AC_OMA_REASON_SAUTHSRV_OFFLINE       ((UINT32)0) /* AC与备用3A鉴权服务器断链 */

/* AC与备用3A计费服务器断链原因宏定义 */
#define AC_OMA_REASON_SACCTSRV_OFFLINE       ((UINT32)0) /* AC与备用3A计费服务器断链 */

/* AC与AS服务器断链原因宏定义 */
#define AC_OMA_REASON_ASSRV_OFFLINE         ((UINT32)0) /* AC与AS服务器断链 */

/* AC与Portal服务器断链原因宏定义 */
#define AC_OMA_REASON_PORTALSRV_OFFLINE     ((UINT32)0)  /* AC与Portal服务器断链 */

/* AC网口连接故障原因宏定义 */
#define AC_OMA_REASON_ENET_FAULT            ((UINT32)0)  /* AC网络连接故障 */

/* AP设备无线干扰告警原因宏定义 */
#define AC_OMA_REASON_CHANNEL_QUALITY_LOW_RSSI	((UINT32)0)	/* RSSI过大 */

#define AC_OMA_REASON_DISKUSAGETOOHIGH      ((UINT32)0)     /* 磁盘利用率过高 */
#define AC_OMA_REASON_TEMPERATURETOOHIGH    ((UINT32)0)     /* 温度过高 */

/* 出现干扰当前信道的设备告警原因宏定义 */
#define AC_OMA_REASON_DEVICE_INTERFERENCE_DETECT_NOISE ((UINT32)0) /* 底噪过大 */

/* 2010-1-22 N+1备份功能新增:软件版本不一致告警原因宏定义*/
#define AC_OMA_REASON_SWVER_DIFF	 	((UINT32)0)

#define AC_OMA_REASON_APDHCPADDRESSEXHAUST	((UINT32)0)	/* AP级 DHCP资源耗尽*/
#define AC_OMA_REASON_STADHCPADDRESSEXHAUST	((UINT32)0)	/* STA级 DHCP资源耗尽*/

/* AP上报到AC的告警ID定义:1000~5999之间 */


/************************************ 事件 ************************************/
/* 事件ID宏定义 */
#define AC_OMA_EVENT_ID_USER_ACCESS_DENY	       ((UINT32)20000)	/* 非法用户接入失败事件 */

/* 2008/08/26 冯静 增加事件条目定义 */
#define AC_OMA_EVENT_ID_WTP_ACCESS_DENY            ((UINT32)20001) /* 非法AP接入事件 */
#define AC_OMA_EVENT_ID_WTP_CURAC_CHANGE           ((UINT32)20002) /* AP当前选用AC切换事件 */
#define AC_OMA_EVENT_ID_AC_REBOOT                  ((UINT32)20003) /* AC启动事件 */
#define AC_OMA_EVENT_ID_WTP_WIFIFREPOINT_RESELECT  ((UINT32)20004) /* 无线模块频点重选事件 */
#define AC_OMA_EVENT_ID_WTP_WIFIPOWER_ADJUST       ((UINT32)20005) /* 无线模块功率调整事件 */
#define AC_OMA_EVENT_ID_WTP_WIFIPOWER_COMPENSATION ((UINT32)20006) /* 无线模块功率补偿事件 */
#define AC_OMA_EVENT_ID_DISTURB                    ((UINT32)20007) /* 设备干扰事件 */

#define AC_OMA_EVENT_ID_AC_HEARTBEAT               ((UINT32)20100) /* AC设备与OMC周期心跳事件 */
#define AC_OMA_EVNET_ID_AC_SWITCH_MS               ((UINT32)20200) /* AC主备切换 */
#define AC_OMA_EVENT_ID_AC_SNTP_FAIL               ((UINT32)20201) /* AC系统时钟同步失败事件 */
#define AC_OMA_EVENT_ID_AC_IPCHANGE                ((UINT32)20202) /* AC设备IP地址变化事件 */

#define AC_OMA_EVENT_ID_INVALIDCERTINBREAKNETWORK      ((UINT32)20300) /* 非法证书用户侵入网络 */
#define AC_OMA_EVENT_ID_STATIONREPITIVE_ATTACK         ((UINT32)20301) /* 客户端重放攻击 */
#define AC_OMA_EVENT_ID_TAMPER_ATTACK                  ((UINT32)20302) /* 篡改攻击 */
#define AC_OMA_EVENT_ID_LOWSAFELEVEL_ATTACK            ((UINT32)20303) /* 安全等级降低攻击 */
#define AC_OMA_EVENT_ID_ADDRESSREDIRECTION_ATTACK      ((UINT32)20304) /* 地址重定向攻击 */
/*2011-10-31 ldm add  */
#define AC_OMA_EVENT_ID_USERLOSTCONNECTION           ((UINT32)20350)       /* 用户异常下线通告 */

/* 2010-4-10 pyy 新增*/
#define AC_OMA_EVENT_ID_WTP_SECURITYMODECHANGE   		((UINT32)20400) /* AP加密机制变化 */
#define AC_OMA_EVENT_ID_CONFIGURATIONERROR				((UINT32)20041)	/* 配置错误事件 */
#define AC_OMA_EVENT_ID_APACTIMESYNCFAILURE				((UINT32)20042)	/* AC与AP间系统时钟同步失败事件*/
/* 2010-05-29 fengjing 新增 */
#define AC_OMA_EVENT_ID_APMTWORKMODECHG  			    ((UINT32)20043)	/* AP无线监视工作模式变更事件*/
/* 2011-04-01 fengjing add */
#define AC_OMA_EVENT_ID_SSIDKEYCONFLICT                ((UINT32)20044) /* SSID密钥冲突事件 */

/* 2010-1-22 N+1备份功能新增*/
#define AC_OMA_EVENT_ID_CFGDAT_GET_FAIL		((UINT32)20500)	/* 从主AC下载配置数据失败*/
#define AC_OMA_EVENT_ID_BAKACCHG_FAIL		((UINT32)20501)	/* 接管AC失败 */

/* 2010-06-01 fengjing add */
#define AC_OMA_EVENT_ID_CFGUPDATE                     ((UINT32)20050) /* 网元配置更新 */
#define AC_OMA_EVENT_ID_SWDOWNLOAD                    ((UINT32)20051) /* 版本下载成功 */
#define AC_OMA_EVENT_ID_SWUPDATE                      ((UINT32)20052) /* 版本升级 */
#define AC_OMA_EVENT_ID_SWUPDATESUCCEED               ((UINT32)20053) /* 版本成功更新 */
#define AC_OMA_EVENT_ID_SWUPDATEFAIL                  ((UINT32)20054) /* 版本更新失败 */

/* 事件原因ID宏定义 */
/* 非法用户接入失败原因 */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_UNSUPPORTEDALG	    ((UINT32)0)	    /* unsupported alg */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_CHALLENGEERROR	    ((UINT32)1)     /* challenge error */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_BADSEQUENCE		((UINT32)2)	    /* bad sequence */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_DISALLOWEDBYACL	((UINT32)3)	    /* disallowed by ACL */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_WRONGBSSID		    ((UINT32)4)	    /* wrong bssid */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_NOWPARSN			((UINT32)5)	    /* no WPA/RSN IE in association */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_RNSERROR			((UINT32)6)	    /* RNS parameter error */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_CAPAMISMATCH		((UINT32)7)     /* capability mismatch */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_RATESETMISMATCH	((UINT32)8)	    /* rate set mismatch */
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_WPAPSK				((UINT32)20)	/*wpa psk mismatch*/
#define AC_OMA_EVENT_REASON_USER_ACCESS_DENY_8021X				((UINT32)21)	/*8021X access failed*/

/* 2008/08/26 冯静 增加事件条目原因ID宏定义 */
/* 非法AP接入事件 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_INVALID_ID                	((UINT32)1)   /* AP设备ID非法 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_INVALID_SECRET			((UINT32)2)   /* 密码非法 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_DIFF_DEVICETYPE          	((UINT32)3)    /* 设备类型不一致 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_DIFF_DEVICESN             	((UINT32)4)    /* 设备SN不一致 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_ALLOCATEID_FAIL			((UINT32)5)    /* 分配设备ID失败*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAX_APNUM				((UINT32)6)	/* 已达到最大AP数*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_NOFREEASSO				((UINT32)7)	/* 无空闲关联*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_REPEATSN				((UINT32)8)	/* SN 重复*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_REPEATIP				((UINT32)9)	/* IP地址重复*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_ILLEGAL_MAC_ADDR	  ((UINT32)10) /*AP MAC非法*/

/* BEGIN: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_NOLICENSE				((UINT32)11)	/* 无license */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_APNUM		((UINT32)12)	/* 已达到license最大AP数 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_STANUM		((UINT32)13)	/* 已达到license最大STA数 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_AUTHOR		((UINT32)14)	/* license已经到期 */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAC		            ((UINT32)15)	/* 不在key中的mac范围内 */
/* END: Added by wubin,2013/7/4 TASK #919 【企业网需求】新增license功能（包括ac license和ap license）---移植 */

/* AP当前选用AC切换事件原因ID宏定义 */
#define AC_OMA_REASON_WTP_CURAC_CHANGE                          ((UINT32)1)   /* AP当前选用AC切换 */

/* AC启动事件原因ID宏定义 */
#define AC_OMA_REASON_AC_REBOOT_HARDWARE                       ((UINT32)1)  /* 硬重启 */
#define AC_OMA_REASON_AC_REBOOT_SOFTWARE                       ((UINT32)2)  /* 软重启 */
#define AC_OMA_REASON_AC_REBOOT_OHTER                          ((UINT32)3)  /* 其它原因*/

/* 无线模块频点重选事件原因ID宏定义 */
#define AC_OMA_REASON_WTP_WIFIFREPOINT_RESELECT                ((UINT32)1)  /* 无线模块频点重选 */

/* 无线模块功率调整事件原因ID宏定义 */
#define AC_OMA_REASON_WTP_WIFIPOWER_ADJUST                     ((UINT32)1)  /* 无线模块功率调整 */

/* 无线模块功率补偿事件原因ID宏定义 */
#define AC_OMA_REASON_WTP_WIFIPOWER_COMPENSATION               ((UINT32)1)  /* 无线模块功率补偿 */

/* 设备干扰事件 原因ID宏定义*/
#define AC_OMA_REASON_DISTURB_BY_NEIGHBOR                     ((UINT32)1)    /*邻居AP干扰事件*/
#define AC_OMA_REASON_DISTURB_BY_OTHER                        ((UINT32)2)    /*其它设备干扰事件*/

/* 主备切换原因 */
#define AC_OMA_REASON_AC_SWITCH_SLAVE_ACTIVE                  ((UINT32)1)    /* 备机转主机 */
#define AC_OMA_REASON_AC_SWITCH_MASTER_ACTIVE                 ((UINT32)2)    /* 主机激活 */

/* 2010-1-22 N+1备份功能新增*/
/* 从主AC下载配置数据失败事件原因码定义*/
#define AC_OMA_REASON_CFGDAT_GET_FAIL	((UINT32)0)		/* 从主AC下载配置数据失败*/
/* 接管主AC失败事件原因码定义*/
#define AC_OMA_REASON_BAKACCHG_FAIL_NOOWNDAT 		((UINT32)1)	/* 数据备份目录下不存在本AC数据文件 */
#define AC_OMA_REASON_BAKACCHG_FAIL_NOBAKACDAT 	((UINT32)2)	/* 数据文件备份目录下不存在被接管AC的数据文件 */
#define AC_OMA_REASON_BAKACCHG_FAIL_DATMERGEFAIL 	((UINT32)3)	/* 数据文件合并失败 */

/* AP上报到AC的事件码定义:6000~9999 */


/************************************ 性能 ************************************/
/* 性能计数器组包含的最大计数器个数 */
#define MAX_PERFCOUNTER_NUM     20

#define AC_OMA_PERF_COUNTERGROUP_NUM         ((UINT32)18)

#define AC_OMA_PERF_VAP_INDEX                ((UINT32)0)
#define AC_OMA_PERF_WTPUSER_INDEX            ((UINT32)1)
#define AC_OMA_PERF_ACUSER_INDEX             ((UINT32)2)
#define AC_OMA_PERF_80211_AUTH_INDEX         ((UINT32)3)
#define AC_OMA_PERF_ASSOC_INDEX              ((UINT32)4)
#define AC_OMA_PERF_ACCESS_AC_INDEX          ((UINT32)5)
#define AC_OMA_PERF_8021X_INDEX              ((UINT32)6)
#define AC_OMA_PERF_PTK_INDEX                ((UINT32)7)
#define AC_OMA_PERF_WEB_INDEX                ((UINT32)8)
#define AC_OMA_PERF_VAPTIME_INDEX            ((UINT32)9)
#define AC_OMA_PERF_WTPTIME_INDEX            ((UINT32)10)
#define AC_OMA_PERF_ACTIME_INDEX             ((UINT32)11)
#define AC_OMA_PERF_VAPTRAFFIC_INDEX         ((UINT32)12)
#define AC_OMA_PERF_WTPTRAFFIC_INDEX         ((UINT32)13)
#define AC_OMA_PERF_ACTRAFFIC_INDEX          ((UINT32)14)

/* 增加WTP性能计数器组定义 */
#define AC_OMA_PERF_WTP_FLOW_INDEX           ((UINT32)15)
#define AC_OMA_PERF_WTP_AP_INDEX             ((UINT32)16)
#define AC_OMA_PERF_WTP_ADHOC_INDEX          ((UINT32)17)

/* 性能统计计数器定义 */
/* VAP统计计数器组 */
#define AC_OMA_PERF_ID_BASE                  ((UINT32)30000)                       /* 性能计数器组ID起始值 */
#define AC_OMA_PERF_ID_VAP                   ((UINT32)AC_OMA_PERF_ID_BASE + 0)     /* VAP用户数统计 */

/* 2008/08/26 冯静 新增性能统计计数器定义 */
#define AC_OMA_PERF_ID_WTPUSER               ((UINT32)AC_OMA_PERF_ID_BASE + 1)     /* WTP用户数统计 */

/* 2008/08/30 冯静 增加 */
#define AC_OMA_PERF_ID_ACUSER                ((UINT32)AC_OMA_PERF_ID_BASE + 2)     /* AC用户数统计 */

#define AC_OMA_PERF_ID_80211_AUTH            ((UINT32)AC_OMA_PERF_ID_BASE + 3)     /* 80211鉴权统计(暂不实现) */
#define AC_OMA_PERF_ID_ASSOC                 ((UINT32)AC_OMA_PERF_ID_BASE + 4)     /* 关联统计(暂不实现) */
#define AC_OMA_PERF_ID_ACCESS_AC             ((UINT32)AC_OMA_PERF_ID_BASE + 5)     /* 接入AC次数统计 */
#define AC_OMA_PERF_ID_8021X                 ((UINT32)AC_OMA_PERF_ID_BASE + 6)     /* 8021X认证统计(部分实现) */
#define AC_OMA_PERF_ID_PTK                   ((UINT32)AC_OMA_PERF_ID_BASE + 7)     /* WPA/PTK协商统计(部分实现) */
#define AC_OMA_PERF_ID_WEB                   ((UINT32)AC_OMA_PERF_ID_BASE + 8)     /* WEB认证请求次数统计(暂不实现) */
#define AC_OMA_PERF_ID_VAPTIME               ((UINT32)AC_OMA_PERF_ID_BASE + 9)     /* VAP用户在线时间统计 */
#define AC_OMA_PERF_ID_WTPTIME               ((UINT32)AC_OMA_PERF_ID_BASE + 10)    /* WTP用户在线时间统计 */
#define AC_OMA_PERF_ID_ACTIME                ((UINT32)AC_OMA_PERF_ID_BASE + 11)    /* AC用户在线时间统计 */
#define AC_OMA_PERF_ID_VAPTRAFFIC            ((UINT32)AC_OMA_PERF_ID_BASE + 12)    /* VAP流量统计 */
#define AC_OMA_PERF_ID_WTPTRAFFIC            ((UINT32)AC_OMA_PERF_ID_BASE + 13)    /* WTP流量统计 */
#define AC_OMA_PERF_ID_ACTRAFFIC             ((UINT32)AC_OMA_PERF_ID_BASE + 14)    /* AC流量统计 */

/* 各计数器组计数器数目宏定义 */
#define AC_OMA_PERF_COUNTER_NUM_VAP          ((UINT32)3)   /* 用户接入次数、用户离开次数、在线用户数 */
#define AC_OMA_PERF_COUNTER_NUM_WTPUSER      ((UINT32)3)   /* 用户接入次数、用户离开次数、在线用户数 */
#define AC_OMA_PERF_COUNTER_NUM_ACUSER       ((UINT32)3)   /* 用户接入次数、用户离开次数、在线用户数 */
#define AC_OMA_PERF_COUNTER_NUM_80211_AUTH   ((UINT32)3)   /* 80211鉴权请求次数统计、80211鉴权成功次数统计、80211鉴权失败次数统计 */
#define AC_OMA_PERF_COUNTER_NUM_ASSOC        ((UINT32)3)   /* 关联请求次数统计、关联成功次数统计、关联失败次数统计 */
#define AC_OMA_PERF_COUNTER_NUM_ACCESS_AC    ((UINT32)1)   /* 接入AC次数统计 */
#define AC_OMA_PERF_COUNTER_NUM_8021X        ((UINT32)4)   /* 8021X认证请求次数统计（包括周期性认证请求）、8021X周期性认证请求次数统计（暂不实现）、8021X认证成功次数统计、8021X认证失败次数统计（暂不实现）*/
#define AC_OMA_PERF_COUNTER_NUM_PTK          ((UINT32)3)   /* WPA/PTK协商请求次数统计、WPA/PTK协商成功次数统计、WPA/PTK协商失败次数统计（暂不实现） */
#define AC_OMA_PERF_COUNTER_NUM_WEB          ((UINT32)3)   /* WEB认证请求次数统计、WEB认证成功次数统计、WEB认证失败次数统计（暂不实现） */
#define AC_OMA_PERF_COUNTER_NUM_VAPTIME      ((UINT32)1)   /* 在线时间统计 */
#define AC_OMA_PERF_COUNTER_NUM_WTPTIME      ((UINT32)1)   /* 在线时间统计 */
#define AC_OMA_PERF_COUNTER_NUM_ACTIME       ((UINT32)1)   /* 在线时间统计 */
#define AC_OMA_PERF_COUNTER_NUM_VAPTRAFFIC   ((UINT32)2)   /* 上行流量统计、下行流量统计 */
#define AC_OMA_PERF_COUNTER_NUM_WTPTRAFFIC   ((UINT32)2)   /* 上行流量统计、下行流量统计 */
#define AC_OMA_PERF_COUNTER_NUM_ACTRAFFIC    ((UINT32)2)   /* 上行流量统计、下行流量统计 */

/* 2008/09/11 冯静增加各计数器组性能上报周期的定义 */
#define AC_OMA_PERF_REPORT_INTERVAL_VAP          ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_WTPUSER      ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_ACUSER       ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_80211_AUTH   ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_ASSOC        ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_ACCESS_AC    ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_8021X        ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_PTK          ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_WEB          ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_VAPTIME      ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_WTPTIME      ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_ACTIME       ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_VAPTRAFFIC   ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_WTPTRAFFIC   ((UINT32)900)
#define AC_OMA_PERF_REPORT_INTERVAL_ACTRAFFIC    ((UINT32)900)

/* 增加各计数器组性能首次上报延迟时间的定义 */
#define AC_OMA_PERF_REPORT_DELAY_VAP          ((UINT32)60)
#define AC_OMA_PERF_REPORT_DELAY_WTPUSER      ((UINT32)120)
#define AC_OMA_PERF_REPORT_DELAY_ACUSER       ((UINT32)180)
#define AC_OMA_PERF_REPORT_DELAY_80211_AUTH   ((UINT32)240)
#define AC_OMA_PERF_REPORT_DELAY_ASSOC        ((UINT32)60)
#define AC_OMA_PERF_REPORT_DELAY_ACCESS_AC    ((UINT32)120)
#define AC_OMA_PERF_REPORT_DELAY_8021X        ((UINT32)180)
#define AC_OMA_PERF_REPORT_DELAY_PTK          ((UINT32)240)
#define AC_OMA_PERF_REPORT_DELAY_WEB          ((UINT32)60)
#define AC_OMA_PERF_REPORT_DELAY_VAPTIME      ((UINT32)120)
#define AC_OMA_PERF_REPORT_DELAY_WTPTIME      ((UINT32)180)
#define AC_OMA_PERF_REPORT_DELAY_ACTIME       ((UINT32)240)
#define AC_OMA_PERF_REPORT_DELAY_VAPTRAFFIC   ((UINT32)60)
#define AC_OMA_PERF_REPORT_DELAY_WTPTRAFFIC   ((UINT32)120)
#define AC_OMA_PERF_REPORT_DELAY_ACTRAFFIC    ((UINT32)180)

/* WTP上报到AC的性能计数器组ID定义 */
#define AC_OMA_PERF_ID_WTP_FLOW             ((UINT32)1000)
#define AC_OMA_PERF_ID_WTP_AP               ((UINT32)2000)
#define AC_OMA_PERF_ID_WTP_ADHOC            ((UINT32)2001)

#define AC_OMA_PERF_COUNTER_NUM_WTP_FLOW     ((UINT32)6)
#define AC_OMA_PERF_COUNTER_NUM_WTP_AP       ((UINT32)9)
#define AC_OMA_PERF_COUNTER_NUM_WTP_ADHOC    ((UINT32)9)

/************************************ 动态信息 ************************************/
/* 用户名最大长度 */
/*2011-11-02 ldm modify  */
#define AC_OMA_USER_NAME_LEN_MAX	256

/* AC网元数据文件状态 */
#define AC_OMA_DATFILE_STATE_NORMAL   ((UINT32)0)
#define AC_OMA_DATFILE_STATE_FAULT    ((UINT32)1)


/* 动态信息上报类型 */
#define AC_OMA_DYNAINFO_TYPE_STATEUPDATE	((UINT32)1)	    /* 状态信息上报 */
#define AC_OMA_DYNAINFO_TYPE_USERADD	    	((UINT32)2)		/* 用户接入 */
#define AC_OMA_DYNAINFO_TYPE_USERDEL	    	((UINT32)3)		/* 用户离开 */
#define AC_OMA_DYNAINFO_TYPE_USERPOS	    	((UINT32)4)		/* 用户位置信息更新 */
#define AC_OMA_DYNAINFO_TYPE_DYNPOWER	    	((UINT32)5)		/* 无线设备当前功率 */
#define AC_OMA_DYNAINFO_TYPE_APIP           		((UINT32)6)     /* AP当前的IP地址 */
#define AC_OMA_DYNAINFO_TYPE_ACIP			((UINT32)7)		/* AC第一组IP地址*/
#define AC_OMA_DYNAINFO_TYPE_APSN			((UINT32)8)		/* AP序列号*/
#define AC_OMA_DYNAINFO_TYPE_APSWVER           	((UINT32)9)        /* AP当前软件版本号*/

/* AC增加动态信息类型 */
#define AC_OMA_DYNAINFO_TYPE_DEVICEABSTRACT  ((UINT32)10)
#define AC_OMA_DYNAINFO_TYPE_WTPACCESS       ((UINT32)11)
#define AC_OMA_DYNAINFO_TYPE_USERACCESS      ((UINT32)12)
#define AC_OMA_DYNAINFO_TYPE_DHCPALLOCATE    ((UINT32)13)
#define AC_OMA_DYNAINFO_TYPE_PORTALSTAT      ((UINT32)14)
#define AC_OMA_DYNAINFO_TYPE_WAPISTAT        ((UINT32)15)
#define AC_OMA_DYNAINFO_TYPE_IFSTAT          ((UINT32)16)
#define AC_OMA_DYNAINFO_TYPE_USERIPINFO      ((UINT32)17)

/* 新增 */
#define AC_OMA_DYNAINFO_TYPE_VAPWIFISTAT      ((UINT32)18)
#define AC_OMA_DYNAINFO_TYPE_VAPUSERACCSTAT   ((UINT32)19)
#define AC_OMA_DYNAINFO_TYPE_ACIFWIFISTAT     ((UINT32)20)
#define AC_OMA_DYNAINFO_TYPE_SSIDWIFISTAT     ((UINT32)21)
#define AC_OMA_DYNAINFO_TYPE_DHCPSTAT        ((UINT32)22)  /* DHCP统计*/
#define AC_OMA_DYNAINFO_TYPE_PPPOESTAT       ((UINT32)23)  /* PPPOE统计*/
#define AC_OMA_DYNAINFO_TYPE_ACLSTAT         ((UINT32)24)  /* ACL统计*/

/* 2009-10-21 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_WTPUNREGISTER 		((UINT32)25) /* 未注册尝试连接AP信息 */
/* 2010/05/15 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_ROAMINGSTAT     ((UINT32)26) /* 漫游统计 */
/* 2010/08/06 fengjing cmcc test */
#define AC_OMA_DYNAINFO_TYPE_ACCOUNTSTAT     ((UINT32)27) /* 计费统计 */

/* 2010-12-08 fengjing add:AP Portal统计 */
#define AC_OMA_DYNAINFO_TYPE_APPORTALSTAT    ((UINT32)28) /* AP Portal统计 */

/* 2009-09-07 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_MAXPOWER        		((UINT32)30)       /* 无线设备最大发射功率 */
#define AC_OMA_DYNAINFO_TYPE_VAPMAC          		((UINT32)31)       /* VAP MAC地址 */
#define AC_OMA_DYNAINFO_TYPE_ADHOCMAC        		((UINT32)32)       /* ADHOC MAC地址 */

/* 2010-1-19 新增*/
#define AC_OMA_DYNAINFO_TYPE_MSSTATE			((UINT32)33)		/* 备份设备状态*/

/* 2011-01-13 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_APTRAFFIC	((UINT32)34)		/* AP上下行流量统计信息 */
#define AC_OMA_DYNAINFO_TYPE_APUSERSTAT	((UINT32)35)		/* AP用户统计信息 */

/* 2011-10-25 ldm add */
#define AC_OMA_DYNAINFO_TYPE_MSSTAT	 ((UINT32)37)		/* 主备切换统计 */

/* 2011-07-06 ymt add*/
#define AC_OMA_DYNAINFO_TYPE_APMAC	 ((UINT32)36)

/* add by gwx 2014-2-25 for task1265 */
#define AC_OMA_DYNAINFO_TYPE_PRODUCTTYPE	((UINT32)38)	/* AP产品型号上报*/
/**************************** 结构定义 ***************************/
#define AC_MAX_MEM_LEN                  ((UINT32)60*1024)

/* 批量上报最大数目 */
#define AC_OMA_QUEUE_BATCHNUM_MAX     50

/*2011-11-02 ldm modify  */
/* 用户相关事件上报扩展信息 */
typedef struct
{
    CHAR	    acUserName[AC_OMA_USER_NAME_LEN_MAX];   /* 用户名 */
   	UINT8	    aucMac[6];						        /* 用户MAC地址 */
	UINT8	    aucRsv[2];						        /* 填充字节 */
	UINT8	    aucIp[4];						        /* 用户IP地址 */
}AC_OMA_EXT_INFO_USER_T;


typedef struct
{
	UINT32 ulChannel ;	/*频点*/
	UINT32 ulRssi ;		/*RSSI*/
	INT32 lNoise ;		/*底噪*/
}AC_OMA_EXT_INFO_RRM_T ;

/* AC热启动/AC冷启动扩展信息*/
typedef struct
{
	UINT8	aucMac[6];		/* AC MAC地址 */
	UINT8	aucRsv[2];
	UINT32	ulRebootTime;	/* AC冷启动/热启动时间*/
} AC_OMA_EXT_INFO_REBOOT_T;

/* AP同频干扰 */
typedef struct
{
     UINT8      aucMac[6];                  /*AP MAC*/
     UINT8      aucMacRsv[2];
     UINT32     ulChannel;                  /*AP 频点*/
     UINT8      aucInterfBssid[6];          /*干扰AP BSSID*/
     UINT8      aucInterfBssidRsv[2];
}AC_OMA_EXT_INFO_COINTERF_T;

/* AP邻频干扰 */
typedef struct
{
     UINT8      aucMac[6];               /*AP MAC*/
     UINT8      aucMacRsv[2];
     UINT32     ulApChannel;             /*AP 频点*/
     UINT8      aucInterfBssid[6];       /*干扰AP BSSID*/
     UINT8      aucInterfBssidRsv[2];
     UINT32     ulInterfApChannel;       /*干扰AP频点*/
}AC_OMA_EXT_INFO_NEIBORINTERF_T;

/* SSID密钥冲突 */
typedef struct
{   
	CHAR       szMySsid[36];   /*以'\0'截止*/
    CHAR       szSsid[36];     /*以'\0'截止*/

    UINT32     ulKeyIndex;
}AC_OMA_EXT_INFO_SSIDKEYCONFLICT;
/*2011-10-28 zoucaihong add*/
typedef struct
{
     UINT32   ulMsMode;     /* 切换模式： 1 备机转主机   2 主机激活 */
     UINT8    aucIp[4];      /* 源AC的管理IP */
} AC_OMA_EXT_INFO_ACMS_T;


/* 扩展信息 */
typedef union
{
	UINT32   	ulCommonInfo;           /* 公共原因，通常对应扩展信息为单个整数类型的情况 */

    AC_OMA_EXT_INFO_USER_T stUser;      /* 用户信息 */
	AC_OMA_EXT_INFO_RRM_T stRrm ;	    /*空口质量*/

	/* 2010-5-29 fengjing add */
	AC_OMA_EXT_INFO_REBOOT_T stReboot;

	/* 2010/07/01 fengjing cmcc test */
	AC_OMA_EXT_INFO_COINTERF_T stCoInterf;
    AC_OMA_EXT_INFO_NEIBORINTERF_T stNeiborInterf;

	AC_OMA_EXT_INFO_SSIDKEYCONFLICT stKeyConflict;
	/*2011-10-27 zoucaihong add*/
	AC_OMA_EXT_INFO_ACMS_T		stAcMs;/*AC主备信息*/
/*2011-11-29 ldm modify  */
	CHAR        acExtInfo[200];
	UINT8       aucMac[6];
}AC_OMA_ALARM_EXT_INFO_U;

typedef AC_OMA_ALARM_EXT_INFO_U 	AC_OMA_EVENT_EXT_INFO_U;

/* 应用模块告警上报信息 */
typedef struct
{
	UINT32	            ulAlarmId;				/* 告警ID */
//	UINT32	            ulAlarmStatus;			/* 告警状态 */
	UINT32	            ulAlarmReasonId;		/* 告警原因ID号 */
	UINT32	            ulAlarmLevel;			/* 告警级别 */
    UINT32              ulMOC;                  /* 对象类型 */
    UINT8               aucMOI[AC_MOI_LEN];     /* 对象实例 */

	UINT32              ulAlarmRaiseTime;		/* 告警产生时间(time()函数的返回值) */
	UINT32	            ulAlarmUptime;		    /* 上电到发生该事件的时间，tick值，秒 */

	AC_OMA_ALARM_EXT_INFO_U    unAlarmExtInfo;	/* 扩展信息 */
}AC_OMA_ALARM_INFO_T;

typedef struct
{
	UINT32	            ulAlarmId;				/* 告警ID */
    UINT32              ulMOC;                  /* 对象类型 */
    UINT8               aucMOI[AC_MOI_LEN];     /* 对象实例 */

	UINT32              ulAlarmClearTime;		/* 告警清除时间(time()函数的返回值) */

	/* 2010/05/31 fengjing add */
	AC_OMA_ALARM_EXT_INFO_U    unAlarmExtInfo;	/* 扩展信息 */
}AC_OMA_ALARM_CLEAR_INFO_T;

typedef struct
{
	UINT32              ulAlarmId;
    UINT32              ulMOC;
    UINT8               aucMOI[AC_MOI_LEN];
    UINT32	            ulAlarmStatus;					// 告警状态
    UINT32	            ulAlarmChangeTime;				// 告警产生/清除最后发生时间（合并后时间），单位：秒
    UINT32     	        ulAlarmSn;                      // 告警流水号
    UINT32              ulAlarmClearTime;

	/* 2010-11-29 fengjing add */
    CHAR                acAlarmExtInfo[100];
	
}AC_OMC_ALARM_CLEAR_INFO_T;

/* 应用模块事件上报信息 */
typedef struct
{
	UINT32              ulEventId;			 	/* 事件ID */
	UINT32              ulEventReasonId;		/* 事件原因ID号 */
    UINT32              ulMOC;                  /* 对象类型 */
    UINT8               aucMOI[AC_MOI_LEN];     /* 对象实例 */

	UINT32              ulEventRaiseTime;		/* 事件产生时间(time()函数的返回值) */

	UINT32              ulEventUptime;			/* 上电到发生该事件的时间，tick值，秒 */

	AC_OMA_EVENT_EXT_INFO_U unEventExtInfo;	    /* 扩展信息 */
}AC_OMA_EVENT_INFO_T;

/* OMA发送给应用模块的请求消息 */
typedef struct
{
	UINT32               ulPerfCounterGroupID; /* 性能计数器组编号 */
}AC_OMA_REPORT_PERF_REQ_MSG_T;

/* 上报对象内容 */
typedef struct
{
    UINT32	     ulMOC;                      /* MOC */
    UINT8	     aucMOI[AC_MOI_LEN];         /* MOI */
    UINT32*      pulPerfCounterValue;        /* 计数器值列表 */
}AC_OMA_PERF_OBJECT_T;

/* 应用模块应答OMA的性能上报请求 */
typedef struct
{
    UINT32                       ulPerfCounterGroupID;  /* 计数器组ID */
    UINT32                       ulCounterNum;          /* 计数器个数 */
    UINT32                       ulPerfObjectNum;       /* 性能上报对象数目 */
    AC_OMA_PERF_OBJECT_T*        pstPerfCounterValue;   /* 上报内容 */
}AC_OMA_REPORT_PERF_RSP_MSG_T;

/* OMA上报给OMC的计数器组值信息 */
typedef struct
{
	UINT32              ulMOC;
    UINT8               aucMOI[AC_MOI_LEN];
    UINT32              ulPerfCounterGroupID;                       /* 性能计数器组编号 */
	UINT32              ulPerfReportTime;                           /* 性能数据上报时间 */
	UINT32              ulPerfReportInterval;                       /* 性能数据上报间隔，单位：秒 */
	UINT32              ulPerfCounterNum;                           /* 性能计数器个数 */
    UINT32              aulPerfCounterValues[MAX_PERFCOUNTER_NUM];	/* 计数器统计值列表 */
}AC_OMC_PERF_INFO_T;


/* OMA上报给OMC的统计计数器组信息 */
typedef struct
{
    UINT32              ulNum;
    AC_OMC_PERF_INFO_T  astPerfInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_PERF_REQ_MSG_T;

/* AC上报给OMC的性能数据 */
//typedef AC_OMC_PERF_INFO_T AC_OMC_REPORT_PERF_REQ_MSG_T;

/* 性能上报应答消息 */
typedef struct
{
    UINT32           ulMOC;
    UINT8            aucMOI[AC_MOI_LEN];
    UINT32           ulPerfCounterGroupID;   	/* 计数器编号 */
    UINT32           ulPerfReportTime;      	/* 上报时间 */
}AC_OMC_REPORT_PERF_RSP_MSG_T;

/* AC转发性能确认消息给WTP网元 */
typedef struct
{
	CHAR             acObjectId[128];
    UINT32           ulPerfCounterGroupID;   	/* 计数器编号 */
    UINT32           ulPerfReportTime;      	/* 上报时间 */
}AC_WTP_PERF_RSP_MSG_T;

/* 设备状态更新 */
typedef struct
{
	UINT32          ulMOC;
	UINT8           aucMOI[AC_MOI_LEN];
	UINT32	        ulAdminState;	        /* 管理状态 */
	UINT32	        ulOpState;		        /* 运行状态 */
    UINT32          ulCurAcId;              /* 当前连接AC网元ID */
}AC_OMA_STATE_UPDATE_T;

typedef AC_OMA_STATE_UPDATE_T AC_OMA_REPORT_STATEUPDATE_REQ_MSG_T;

/* AC网元数据文件状态更新 */
typedef struct
{
    UINT32          ulDatFileState;             /* AC网元数据文件状态 */
}AC_OMA_DATAFILE_STATE_UPDATE_T;

typedef AC_OMA_DATAFILE_STATE_UPDATE_T AC_OMA_REPORT_DATAFILE_STATEUPDATE_REQ_MSG_T;

/* 用户状态更新 */
typedef struct
{
	CHAR	acUserName[AC_OMA_USER_NAME_LEN_MAX];
	UINT32	ulWtpId;						/* 用户接入的WTP设备ID */
	UINT32	ulVDevId;						/* 用户接入的无线设备ID */
	UINT32	ulVapId;						/* 用户接入的VAP ID */
	UINT8	aucMac[6];						/* 用户MAC地址 */
	UINT8	aucRsv[2];						/* 填充字节 */
	UINT8	aucIp[4];						/* 用户IP地址 */
	INT32	lPosX;							/* 位置：X坐标，经度信息-180～180  *10的5次方 */
	INT32	lPosY;							/* 位置：Y坐标，纬度信息-90～90 *10的5次方*/
}AC_OMA_USERINFO_T;

/* 无线模块当前发射功率更新*/
typedef struct
{
     UINT32             ulWtpId;           /* AP设备ID */
     UINT32             ulWifiDeviceId;    /* 无线设备ID */
     UINT32             ulDynPower;        /* 当前发射功率 */
}AC_OMA_DYNPOWER_UPDATE_T;

/* 上报AP当前IP地址 */
typedef struct
{
    UINT32	ulWtpId;   /* AP设备ID */
    UINT32   ulIpOrigin;            /* 1:静态配置
                                       2:DHCP动态配置
                                       3:AC动态配置*/
	UINT8	aucIp[4];  /* AP设备当前IP地址 */
    UINT8    aucNetMask[4];         /* 子网掩码 */
    UINT8    aucDefaultGw[4];       /* 子网掩码 */
    UINT8    aucPrimaryDns[4];      /*主DNS服务器*/
    UINT8    aucSecondaryDns[4];    /*从DNS服务器*/
}AC_OMA_APDYNAIP_UPDATE_T;

/* 上报AC的第一组IP地址*/
typedef struct
{
	UINT32	ulAcId;
	UINT8   aucFitLanIp[4];   		/* FIT-LAN IP */
	UINT8   aucFitLanMask[4];  	/* FIT-LAN MASK */

    	UINT8   aucFatLanIp[4];   		/* FAT-LAN IP */
	UINT8   aucFatLanMask[4];   	/* FAT-LAN MASK */

    	UINT8   aucL2WanIp[4];   		/* L2-WAN IP */
    	UINT8   aucL2WanMask[4];   	/* L2-WAN MASK */

    	UINT8   aucL3WanIp[4];   		/* L3-WAN IP */
    	UINT8   aucL3WanMask[4];   	/* L3-WAN MASK */
} AC_OMA_ACIP_UPDATE_T;

/* 上报AP的SN */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT8	aucSn[6];	      /* 序列号*/
	UINT8	aucRsv[2];          /* 填充字节*/
} AC_OMA_APSN_UPDATE_T;

/* 上报AP的MAC地址 */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT8	aucMac[6];	/* 序列号*/
	UINT8	aucRsv[2];   	/* 填充字节*/
} AC_OMA_APMAC_UPDATE_T;


/* 上报AP的当前软件版本号 */
typedef struct
{
	UINT32   ulAcId;
	UINT32   ulWtpId;                /* AP ID */
	CHAR     acSwVersion[32];   /* 软件版本*/
} AC_OMA_APSWVER_UPDATE_T;

/* 动态信息上报结构 */
/* 无线设备最大发射功率更新消息结构 */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* 无线设备ID */
     UINT32   ulMaxPower;        /* 无线设备最大发射功率 */
} AC_OMA_WIFIDEVICE_MAXPOWER_UPDATE_T;

/* VAP MAC地址更新消息结构 */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* 无线设备ID */
     UINT32   ulVapId;           /* VAP ID */
     UINT8    aucMac[6];         /* MAC地址 */
     UINT8    aucRsv[2];         /* 填充字节 */
} AC_OMA_VAP_MAC_UPDATE_T;

/* ADHOC MAC地址更新消息结构 */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* 无线设备ID */
     UINT32   ulAdhocId;         /* ADHOC ID */
     UINT8    aucMac[6];         /* MAC地址 */
     UINT8    aucRsv[2];         /* 填充字节 */
} AC_OMA_ADHOC_MAC_UPDATE_T;

/* 2010-1-19 新增: 备份设备运行状态更新消息结构*/
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulPeerAcState1;	/*备份设备1状态 */
	UINT32	ulPeerAcState2;	/*备份设备2状态 */
	UINT32	ulPeerAcState3;	/*备份设备3状态 */
	UINT32	ulCurBakAcId;	/* 当前接管的AC　ID */
}AC_OMA_MSSTATE_UPDATE_T;

/* 网元重启消息 */
typedef struct
{
	UINT32  ulSn; /* start time */
	UINT32  ulMOC;
	UINT8   aucMOI[AC_MOI_LEN];
}AC_OMC_NESTART_T;

/* 文件传输结果信息 */
typedef struct
{
	UINT32  ulSn;
	UINT32  ulMOC;
	UINT8   aucMOI[AC_MOI_LEN];
	UINT32  ulResult;
}AC_OMC_FILETRANSFER_T;

typedef struct
{
    UINT32  ulMOC;
    UINT8   aucMOI[AC_MOI_LEN];
    CHAR    acImVersion[32];  /* 信息模型版本 */
    CHAR    acSwVersion[32];  /* 软件版本 */
    UINT32  ulDeviceType;     /* 设备类型 */
    UINT32  ulWtpId;          /* 网元ID */
    UINT32  ulCfgVersion;     /* 配置数据版本号 */
	UINT32 ulSysTime;
	UINT32 ulUpTime;
	UINT32 ulConnTime;
}AC_OMC_NEVERSION_T;

/* 动态信息接口体定义 */
#define AC_OMA_AC_ENETPORT_NUM_MAX      AC_ENETPORT_NUM_MAX
//#define AC_OMA_AC_WTP_NUM_MAX           ((UINT32)100)
//#define AC_OMA_AC_USER_NUM_MAX          ((UINT32)100)
//#define AC_OMA_AC_DHCPALLOCATE_NUM_MAX  ((UINT32)100)

#define AC_OMA_AC_WTPSTATE_IDLE     ((UINT32)0)
#define AC_OMA_AC_WTPSTATE_INITING  ((UINT32)1)
#define AC_OMA_AC_WTPSTATE_WORK     ((UINT32)2)

/* AC设备以太网口信息 */
typedef AC_ENETPORT_INFO_T AC_OMA_AC_ENETPORT_INFO_T;

/* AC设备摘要信息 */
typedef struct
{
	CHAR     acAcDevName[32];      //设备名称
	CHAR	acAcNEId[32];		/* 设备编码*/
	CHAR	acAcHostName[64];	/* 设备域名称*/
    CHAR     acAcDevType[32];      //设备型号
    CHAR     acAcDevSN[6];         //设备序列号：位于 /etc/gb
	UINT8    aucResv1[2];
	CHAR	acAcSwName[64];		/* 设备软件名称*/
    CHAR     acAcSwVersion[32];    //设备软件版本
    CHAR     acAcHwVersion[32];    //设备硬件版本
    CHAR     acAcCpuInfo[128];	   //CPU信息:CPU型号，主频
    CHAR     acAcMemInfo[128];	   //内存信息:RAM类型，容量
    	CHAR	acAcLocation[64];		/* 设备位置*/
    CHAR     acAcManufacturer[128]; //设备制造商 位于 AC_HOME/c.dat
    CHAR     acAcSwDeveloper[128];  //软件开发商
    UINT32  ulActive;	 /*   2011-8-24 pyy add 当前工作模式: TRUE: 当前Active 		FALSE: 当前Standby */


	/* FIT-LAN端口IP信息*/
	UINT32	ulFitLanIpNum;			/* FIT-LAN端口IP地址数目 */
	UINT8	aaucFitLanIp[8][4];		/* FIT-LAN端口IP地址*/
	UINT8	aaucFitLanMask[8][4];	/* FIT-LAN端口子网掩码*/
	UINT8	aucFitLanMac[6];			/* FIT-LAN端口MAC地址*/
	UINT8	aucRsv1[2];				/*	填充字节*/

	/* FAT-LAN端口IP信息*/
	UINT32	ulFatLanIpNum;			/*	FAT-LAN端口IP地址数目*/
	UINT8	aaucFatLanIp[32][4];		/*	FAT-LAN端口IP地址*/
	UINT8	aaucFatLanMask[32][4];	/*	FAT-LAN端口子网掩码*/
	UINT8	aucFatLanMac[6];		/*	FAT-LAN端口MAC地址*/
	UINT8	aucRsv2[2];				/*	填充字节*/

	/*以下为L2-WAN端口IP信息		*/
	UINT32	ulL2WanIpNum;			/*	L2-WAN端口IP地址数目*/
	UINT8	aaucL2WanIp[8][4];		/*	L2-WAN端口IP地址*/
	UINT8	aaucL2WanMask[8][4];	/*	L2-WAN端口子网掩码*/
	UINT8	aucL2WanMac[6];		/*	L2-WAN端口MAC地址*/
	UINT8	aucRsv3[2];				/*	填充字节*/

	/* 以下为L3-WAN端口IP信息*/
	UINT32	ulL3WanIpNum;			/*	L3-WAN端口IP地址数目*/
	UINT8	aaucL3WanIp[8][4];		/*	L3-WAN端口IP地址*/
	UINT8	aaucL3WanMask[8][4];	/*	L3-WAN端口子网掩码*/
	UINT8	aucL3WanMac[6];		/*	L3-WAN端口MAC地址*/
	UINT8	aucRsv4[2];				/*	填充字节*/
	UINT8	aucWanDftGw[4];			/*	缺省网关*/
	UINT8	aucDnsServer1[4];		/*	主用DNS服务器*/
	UINT8	aucDnsServer2[4];		/*	备用DNS服务器*/

	/*以下为设备运行动态信息*/
	UINT32   ulAcTime;		      //设备时间
	UINT32   ulAcUpTime;	      //设备运行时间
    UINT32   ulAcMemoryTotal;     //内存总大小
    UINT32   ulAcMemoryUsed;      //内存使用率
	UINT32   ulAcCpuLoad;         //CPU使用率
	UINT32   ulAcDiskTotal;       //文件系统容量
	UINT32   ulAcDiskRemain;      //文件系统剩余空间
	UINT32   ulAcTemperature;     //设备工作温度

	UINT32	ulAcRegWtpNum;		/* 注册的AP数目*/
	UINT32   ulAcWtpNum;          //接入的AP数目
	UINT32   ulAcStaNum;          //接入的用户数目
	UINT32	ulAcPortalStaNum;		/* 接入的Portal认证用户数*/
	UINT32	ulAcPPPoEStaNum;		/* 接入的PPPoE认证用户数*/

    UINT32   ulUplinkStatus;      //0:正常 1:断开

	/*以下为端口状态信息*/
	UINT32   ulEnetPortNum;		 //以太网端口数目
	AC_OMA_AC_ENETPORT_INFO_T astEnetPort[AC_OMA_AC_ENETPORT_NUM_MAX];

	/* 预留字段 */
	//UINT8    aucResv4[32];
}AC_OMA_AC_DEVICE_ABSTRACT_T;

/* AC设备AP接入信息 */
typedef struct
{
	UINT32  ulWtpId;      //AP设备ID
	// 2009-10-21 new add
	UINT32   ulIpOrigin;   // AP IP配置方式  1：静态配置
                                         //2：DHCP动态配置
	UINT8	aucWtpLocalIp[4];	/* AP 设备IP */
	UINT8	aucWtpIp[4];		/* AP 通信IP */
	UINT32	aucWtpPort;		/* 穿越NAT 后的源端口号 add by gwx 2013-4-7 fot task668*/
	UINT8	aucMac[6];		/* AP 设备MAC */
	UINT8	aucResv0[2];	/* 填充字节*/
	UINT32  ulWtpModel;   //AP设备型号
	UINT8   aucWtpSn[6];  //AP设备序列号
	UINT8	aucResv[2];
	// 2009-10-21 new add
	UINT32   ulDisType;    // AC发现方式
                                          //0：自动
					      // 1：DHCP
					      //2：DNS
					      // 3：组播

	// 2009-10-15 new add
	CHAR     acSwVersion[32];   //AP 当前软件版本号
	CHAR     acTargetVersion[32];   // AP设备目标软件版本号
	UINT32  ulWtpState;   //AP设备状态
	                     /*
	                      * 0: 离线
	                      * 1: 连接中
   	                      * 2: 在线
					      */
	UINT32   ulRejectReason;    /* 拒绝接入原因 */
			                                 /*
			                                 1:设备ID不一致
			                                 2:密码不一致
			                                 3:设备型号不一致
			                                 4:设备序列号不一致
			                                 */

	UINT32	ulAcLanId;	/* AC 端口
					0-16，显示LANx
					>=16，则显示N/A*/
					
	UINT32	ulVlanId;		/* 2009-12-25 pyy 新增: 当前接入的VLAN ID */
    	UINT32  ulBeginTime;    	//该状态开始时间
    	UINT32  ulStatePeriod;  	//该状态持续时间

	UINT32  ulStaNum;       	//当前接入用户数
	UINT32	ulStaAccNum;	/* 用户接入次数*/
    	UINT32  ulStaOnlineTime;    /* 用户总在线时长, 单位：秒 */

	UINT32	ulRegisterTime;			/*		注册时间	，首次连接到AC的时间*/
	UINT32	ulLastConnTime;			/*		上次启动时间，最后一次关联AC的时间*/
	UINT32	ulLastVerUpdateTime;	/*		上次升级版本时间	Oma通知dbs*/
	UINT32	ulLastCfgUpdateTime;	/*		上次更新配置时间	Oma通知dbs */

	/* 2010-6-25 pyy 新增*/
    CHAR        acCounty[64];           /* 设备所在区县 */
	CHAR	acLocation[64];	/*	设备所在位置*/
	CHAR	acContact[64];	/*	设备维护联系人*/

	/* 2010-12-08 fengjing add */
	UINT32  ulLastOnlineTime;   /* 运营状态AP退服时长(分钟),在线后离线的时长（应该去除版本升级时间） */
  	UINT32  ulTotalOnlineTime;  /* 运营状态AP总时长(分钟)（在线总时长）,累计时长 */   

	/* add by gwx 2013-2-25 for task1265 */
	UINT32	ulWtpProductType; 	/* 产品类型ID */

	/* add by gwx 2014-3-26 for AP一键注册begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for AP一键注册end*/
	CHAR	acCurChannelList[32];	/* add by gwx 2014-8-7 AP当前使用信道列表*/
}AC_OMA_AC_WTP_INFO_T;

typedef struct
{
	UINT32  ulAcId;       //AC设备ID
	UINT32  ulWtpNum;     //接入AP数目
	AC_OMA_AC_WTP_INFO_T *pstWtpInfo;
}AC_OMA_AC_WTP_ACCESS_T;

/* 2009-10-21 fengjing add begin */
/* AC设备尝试接入AP信息 */
typedef  AC_OMA_AC_WTP_ACCESS_T AC_OMA_AC_WTP_UNREGISTER_T;
/* 2009-10-21 fengjing add end */

/* AC设备用户接入信息 */
typedef struct
{
	UINT32   ulWtpId;       //AP设备ID
	UINT32   ulWtpModel;    //AP设备型号
	 UINT32  ulVdevId;       //无线设备编号
	UINT32   ulVapId;       //VAP ID
	UINT32	ulAcLanId;	/* AC端口*/
	CHAR     acApSsid[32];  //VAP SSID
	UINT32   ulVapSecurity; //VAP 验证类型
	/*
	 * 1:Open System
	 * 2:Shared Key
	 * 3:WPA-PSK
	 * 4:WPA
	 * 5:MAC认证
	 * 6:WAPI
	 */
	CHAR     acUserName[256]; //用户名
	UINT8    aucMac[6];      //MAC地址
	UINT8    aucRsv[2];      //填充字节
	UINT8    aucIp[4];       //IP地址
	UINT32   ulPriority;     //用户优先级
	/*
	 * 0~7
	 * 0:最高
	 * 7:最低
	 */
	UINT32   ulUpBandMax;      //用户最大上行带宽	单位：Kbps
	UINT32   ulUpBandMin;      //用户保证上行带宽	单位：Kbps
	UINT32   ulDownBandMax;	   //用户最大下行带宽	单位：Kbps
	UINT32   ulDownBandMin;	   //用户保证下行带宽	单位：Kbps
	UINT32   ulCreateTime;	   //上线时间用户关联时间
	UINT32    ulCertStateOkTime;         /* add by gwx 2013-3-28 for task647 */
	UINT32	ulAuthType;		/* 认证类型: 0:免认证/1:Portal/2:PPPoE */
	UINT32   ulPortalState;    /*认证状态*/
	/*
	 * 0:未认证
	 * 1:已认证
	 */
	UINT32	ulPPPoEState;	/* PPPOE认证状态: 0/1 未认证/已认证*/
	UINT32	ulVlanId;		/*		当前接入的VLAN ID */
	CHAR	acNasId[256];	/*		NAS ID */
	UINT8	aucNasIp[4];		/*		NAS IP */
	UINT32	ulAcctInterimInterval;	/*		计费信息上报间隔*/

	/* 2010-12-08 fengjing add WEB认证用户在线时长 */
	UINT32   ulOnlineTime;      /* WEB认证用户在线时长，单位:秒 */	
	/* add by gwx 2014-4-9 for bug5259 begin */
	UINT8	aucBssid[6];
	UINT8	aucBssidRsv[2];
	/* add by gwx 2014-4-9 for bug5259 end */
	/* add by gwx 2014-5-14 for 锐捷，RSSI*/
	UINT32	ulUserRssi;
    /* BEGIN: Added by zoucaihong, 2014/9/10 */
    CHAR    acStaType[32];   /* 連線用戶終端之設備類型 */
    /* END: Added by zoucaihong, 2014/9/10 */
	/* add by gwx 2014-10-17 begin */
	CHAR 	acChannelName[32];	/* 用户当前所在的信道*/
	UINT32	ulWifiType;			/* 接入的卡类型0:2.4G 1:5G */
	/* add by gwx 2014-10-17 end */
}AC_OMA_AC_USER_INFO_T;

typedef struct
{
	UINT32  ulAcId;            //AC设备ID
	UINT32  ulUserNum;         //接入用户数目
	AC_OMA_AC_USER_INFO_T *pstUserInfo;
}AC_OMA_AC_USER_ACCESS_T;


/* 终端用户IP分配信息*/
typedef struct
{
	UINT32	ulAcId;
	UINT8	aucIp[4];		/* IP地址*/
	UINT8	aucMac[6];		/* 最近一次分配到这个IP地址的终端的MAC地址*/
	UINT8	aucRsv[2];		/* 填充字节*/
	UINT32	ulWtpId;			/* 最近一次分配到这个IP地址的终端接入的AP设备ID */
	UINT32	ulVapId;			/* 最近一次分配到这个IP地址的终端接入的VAP ID */
	CHAR	acVapSsid[32];
	UINT32	ulTime;			/* 最近一次这个IP地址被分配的时间点*/
	UINT32	ulAcLanId;		/* AC 端口 0~15 显示LANx >=16 则显示N/A*/
} AC_OMA_AC_STAIP_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulIpNum;
	AC_OMA_AC_STAIP_INFO_T		*pstStaIpInfo;
} AC_OMA_AC_STAIP_ACCESS_T;

/* 2011-09-02 fengjing modify 部分字段由UINT32->UINT64 */
typedef struct {
	UINT32	ulIfId;						/*		以太网口ID */
	UINT64	ulRecvFrameNum;			/*		网络侧（有线侧）接收总的帧数*/
	UINT64	ulRecvBytes;				/*		网络侧（有线侧）接收总的字节数*/
	UINT64	ulRecvUnicastFrameNum;		/*		网络侧（有线侧）接收的单播帧数*/
	UINT64	ulRecvMulticastFrameNum;	/*		网络侧（有线侧）接收的多播帧数*/
	UINT64  ulRecvBroadcastFrameNum;    /* 网络侧（有线侧）接收的广播帧数 */
	UINT32	ulRecvFailFrameNum;		/*		网络侧（有线侧）接收错误的帧数*/
	UINT32	ulRecvDiscardFrameNum	;	/*		网络侧（有线侧）接收丢弃的帧数*/
	UINT32  ulRecvRetryFrameNum;		/* 网络侧（有线侧）接收重传的帧数*/
	UINT64	ulSendFrameNum;			/*		网络侧（有线侧）发送总的帧数*/
	UINT64	ulSendBytes;				/*		网络侧（有线侧）发送总的字节数*/
	UINT64	ulSendUnicastFrameNum;		/*		网络侧（有线侧）发送的单播帧数*/
	UINT64	ulSendMulticastFrameNum;	/*		网络侧（有线侧）发送的多播帧数*/
	UINT64  ulSendBroadcastFrameNum;    /* 网络侧（有线侧）发送的广播帧数*/
	UINT32	ulSendFailFrameNum;		/*		网络侧（有线侧）发送错误的帧数*/
	UINT32	ulSendDiscardFrameNum;		/*		网络侧（有线侧）发送丢弃的帧数*/
	UINT32  ulSendRetryFrameNum;        /* 网络侧（有线侧）发送重传的帧数*/
	UINT32  ulDownNum;                  /* 以太网口禁用次数 */
	UINT32  ulUpNum;	                /* 以太网口启用次数 */
} AC_OMA_AC_IF_INFO_T;

typedef struct
{
	UINT32  ulAcId;            	//AC设备ID
	UINT32  ulIfNum;         	//以太网口数目
	AC_OMA_AC_IF_INFO_T *pstIfInfo;
}AC_OMA_AC_IFSTAT_T;

/* DHCP统计信息*/
typedef struct
{
	UINT32	ulType;	/*		DHCP地址池类型：
					0：用户级DHCP地址池
					1：AP级DHCP地址池*/
	UINT32	ulId;			/*	地址池编号*/
	UINT32	ulTotalIpNum;	/*		总的IP数目*/
	UINT32	ulFreeIpNum;	/*		可用IP的数目*/
	UINT32	ulUsePercent;	/*		DHCP地址池利用率*/
	UINT32	ulDhcpReqNum;	/*		DHCP请求次数*/
	UINT32	ulDhcpSuccNum;	/*		DHCP请求成功次数*/    

	/* 2011-04-15 fengjing add */
	UINT32 ulDhcpDiscoverNum; /* DHCP discover 接收次数 */
	UINT32 ulDhcpOfferNum;      /* DHCP offer发送次数*/

	/* 2011-09-22 fengjing add */
	UINT32 ulDhcpPoolPeakUsage;  /* DHCP地址池峰值利用率 */
} AC_OMA_AC_DHCP_STAT_INFO_T;

typedef struct
{
	UINT32 	ulAcId;             //AC设备ID
	UINT32	ulPoolNum;	/* 地址池数目*/
	AC_OMA_AC_DHCP_STAT_INFO_T	*pstDhcpStat;
} AC_OMA_AC_DHCP_STAT_T;

/* */
typedef struct
{
	UINT8  aucIP[4];      //分配的IP地址
	UINT8  aucMask[4];    //分配的子网掩码
	UINT8  ulMacAddr[6];  //用户MAC地址
	UINT8  aucResv[2];    //填充字节
	UINT32	ulVlanId;
	UINT32 ulHostType;    //用户类型
	/*
	 * 0:AP
	 * 1:STA
	 */
	CHAR   acHostName[32];  //Client上发的用户主机名称,可能为空
	time_t stStartTime;     //租约起始时间	UTC时间
	time_t stEndTime;       //租约到期时间	UTC时间
}AC_OMA_AC_DHCP_ALLOCATE_INFO_T;

/* AC设备DHCP地址分配信息 */
typedef struct
{
	UINT32 	ulAcId;             //AC设备ID
	UINT32  ulDhcpAllocateNum;
	AC_OMA_AC_DHCP_ALLOCATE_INFO_T *pstDhcpAllocate;
}AC_OMA_AC_DHCP_ALLOCATE_T;

/* AC设备Portal统计信息 */
typedef struct
{
	UINT32 ulAcId;             //AC设备ID
	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalAuthTime;         /*Portal认证终端鉴权次数*/
	UINT32 ulAssociateAuthTime;         /*关联认证终端鉴权次数*/
	UINT32 ulMacAuthTime;         /*MAC认证终端鉴权次数*/
    	UINT32 ulPortalAuthFailTime;     /*Portal认证终端鉴权失败次数*/
	UINT32 ulAssociateAuthFailTime;     /*关联认证终端鉴权失败次数*/
	UINT32 ulMacAuthFailTime;     /*MAC认证终端鉴权失败次数*/
    	UINT32 ulPortalAuthSuccNum;	    /*Portal认证终端鉴权成功次数*/
	UINT32 ulAssociateAuthSuccNum;	    /*关联认证终端鉴权成功次数*/
	UINT32 ulMacAuthSuccNum;	    /*MAC认证终端鉴权成功次数*/

	UINT32 ulAuthRejectNum;     //终端鉴权拒绝次数
	UINT32 ulAuthTryNum;        //终端鉴权尝试次数
	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalOnlineUserNum;    /*当前通过WEB认证的在线用户数*/
	UINT32 ulFreeOnlineUserNum;    /*当前通过免认证的在线用户数*/
	UINT32 ulAssociateOnlineUserNum;    /*当前通过关联认证的在线用户数*/
	UINT32 ulMacOnlineUserNum;    /*当前通过MAC认证的在线用户数*/
	
    	UINT32 ulLogoutUserNum;    //用户主动登出次数
    	UINT32 ulTimeoutUserNum;   //用户SessionTimeout下线次数
    	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalOfflineUserNum;   /*Portal认证用户异常下线次数*/
	UINT32 ulFreeOfflineUserNum;   /*免认证用户异常下线次数*/
	UINT32 ulAssociateOfflineUserNum;   /*关联认证用户异常下线次数*/
	UINT32 ulMacOfflineUserNum;   /*MAC认证用户异常下线次数*/

    	UINT32 ulPortalServerNum;   /* AC连接的Portal服务器数 */

	// 2010/06/29 fengjing cmcc test	
	UINT32 ulPortalAuthReqCount;       /* AC收到Portal服务器的鉴权请求数 */
	UINT32 ulPortalChallengeReqCount;  /* AC收到Portal服务器的Challenge请求数 */
	UINT32 ulPortalAuthRespCount;      /* AC响应Portal服务器鉴权请求的次数 */
	UINT32 ulPortalChallengeRespCount; /* AC响应Portal服务器Challenge请求的次数 */	
	
	UINT32 ulPortalAuthRespErr0;     /* AC给portal返回给errcode=0的次数 */
	UINT32 ulPortalAuthRespErr1;     /* AC给portal返回给errcode=1的次数 */
	UINT32 ulPortalAuthRespErr2;     /* AC给portal返回给errcode=2的次数 */
	UINT32 ulPortalAuthRespErr3;     /* AC给portal返回给errcode=3的次数 */
	UINT32 ulPortalAuthRespErr4;     /* AC给portal返回给errcode=4的次数 */

	// 2010/07/30 fengjing cmcc KPI
	UINT32 ulChallengeTimeoutCount;    /* Challenge超时次数 */
	UINT32 ulChallengeBusyCount;       /* ChallengeAC忙碌次数 */
	UINT32 ulChallengeDenyCount;       /* Challenge拒绝次数 */
	UINT32 ulUserPwdErrCount;          /* 用户密码信息缺失次数 */
	UINT32 ulUnknownErrCount;          /* 未知类型错误次数 */
	UINT32 ulAuthTimeoutCount;         /* 鉴权超时次数 */
	UINT32 ulAuthBusyCount;            /* 鉴权AC忙碌次数 */
	UINT32 ulAuthDisorderSeqCount;     /* 鉴权过程乱续次数 */	

	/* 2010/08/06 fengjing cmcc test */
	UINT32 ulRadiusOfflineReqCount;   /* AC侦测到用户下线,发送给Portal服务器的下线请求次数 */
	UINT32 ulRadiusOfflineRespCount;  /* AC收到Portal服务器的下线响应次数*/	

	/* 2010-12-08 fengjing add 下线相关参数 */
	UINT32 ulOfflineReqCount;   /* 用户正常下线流程: Portal服务器发送给AC的下线通知次数*/
	UINT32 ulOfflineSuccCount; /* 用户正常下线流程: Portal服务器发送给AC的用户下线成功通知次数*/
	UINT32 ulOfflineFailCount;   /* 用户正常下线流程: Portal服务器发送给AC的用户下线失败通知次数*/
}AC_OMA_AC_PORTAL_STAT_T;

/* VAP Portal统计信息 */
typedef struct
{
   UINT32 ulAcId;          //AC ID
   UINT32 ulWtpId;         //WTP ID
   UINT32 ulVapId;         //VAP ID
   CHAR   acApSsid[32];    //VAP SSID           
	/*2011-10-28 zoucaihong modify*/
    UINT32 ulPortalOnlineUserNum;    /*当前通过WEB认证的在线用户数*/
	UINT32 ulFreeOnlineUserNum;    /*当前免认证的在线用户数*/
	UINT32 ulAssociateOnlineUserNum;    /*当前通过关联认证的在线用户数*/
	UINT32 ulMacOnlineUserNum;    /*当前通过MAC认证的在线用户数*/
    UINT32 ulPortalOfflineUserNum;   /*Portal认证用户异常下线次数*/
	UINT32 ulFreeOfflineUserNum;   /*免认证用户异常下线次数*/
	UINT32 ulAssociateOfflineUserNum;   /*关联认证用户异常下线次数*/
	UINT32 ulMacOfflineUserNum;   /*MAC认证用户异常下线次数*/
    UINT32 ulPortalAuthReq;          /*Portal认证请求数*/
	UINT32 ulAssociateAuthReq;          /*关联认证请求数*/
	UINT32 ulMacAuthReq;          /*MAC认证请求数*/
    UINT32 ulPortalAuthSucc;         /*Portal认证成功数*/
	UINT32 ulAssociateAuthSucc;         /*关联认证成功数*/
	UINT32 ulMacAuthSucc;         /*MAC认证成功数*/
	/*2011-10-31 zoucaihong add*/
	UINT32 ulPortalAuthFail;         /*Portal认证失败数*/
	UINT32 ulAssociateAuthFail;         /*关联认证失败数*/
	UINT32 ulMacAuthFail;         /*MAC认证失败数*/
	/*2011-10-28 zoucaihong add*/
	UINT32 ulPortalTotalOnlineTime;  /*Portal认证用户总在线时长*/
	UINT32 ulFreeTotalOnlineTime;  /*免认证用户总在线时长*/
	UINT32 ulAssociateTotalOnlineTime;  /*关联认证用户总在线时长*/
	UINT32 ulMacTotalOnlineTime;  /*MAC认证用户总在线时长*/
	
}AC_OMA_AP_VAP_PORTAL_STAT_T;
 

/* AP设备Portal统计信息 */
typedef struct
{
   UINT32 ulValidNum;         //
   AC_OMA_AP_VAP_PORTAL_STAT_T *pstApPortalStat;
}AC_OMA_AP_PORTAL_STAT_T;

/* AC设备PPPOE认证统计信息*/
typedef struct
{
	UINT32	ulAcId;

	UINT32	ulMaxPPPoEOnlineUsers;		/*		最大允许同时在线用户数*/
	UINT32	ulPPPoEOnlineUsers;			/*	当前同时在线用户数*/
	UINT32	ulInactivityTimeOutNum;		/*	用户空闲超时被中断连接的次数*/
	UINT32	ulUserInitTermNum;			/*		用户发起中断连接的次数*/
	UINT32	ulRxEthDiscoveryNum;		/*		接收到的ETH-DISCOVERY帧数目*/
	UINT32	ulRxEthSessionNum;			/*	接收到的ETH-SESSION帧数目*/
	UINT32	ulRxErrCodeNum;			/*		接收到的报文CODE错误帧数目*/
	UINT32	ulRxErrVerNum;				/*	接收到的报文Version错误帧数目*/
	UINT32	ulRxErrLengthNum;				/*		接收到的报文长度错误帧数目*/
} AC_OMA_AC_PPPOE_STAT_T;

/* ACL统计信息*/
typedef struct
{
	UINT32	ulAcId;

	UINT32	ulAclNum;		/*		ACL的总条目数*/
	UINT32	ulDropPktNum;	/*		ACL丢弃报文总数*/
	UINT32	ulAcceptPktNum;	/*		ACL通过报文总数*/
	UINT32	ulMarkPktNum;	/*		ACL标记报文总数*/
	UINT32	ulTcpPktNum;	/*		ACL显式处理的TCP报文总数*/
	UINT32	ulTcpDropNum;	/*		TCP报文丢弃总数*/
	UINT32	ulTcpAcceptNum;	/*		TCP报文通过总数*/
	UINT32	ulTcpMarkNum;	/*		TCP报文其它处理总数*/
	UINT32	ulUdpPktNum;	/*		ACL显式处理的UDP报文总数*/
	UINT32	ulUdpDropNum;	/*		UDP报文丢弃总数*/
	UINT32	ulUdpAcceptNum;	/*		UDP报文通过总数*/
	UINT32	ulUdpMarkNum;		/*	UDP报文其它处理总数*/
	UINT32	ulIcmpPktNum;		/*		ACL显式处理的ICMP报文总数*/
	UINT32	ulIcmpDropNum;		/*		ICMP报文丢弃总数*/
	UINT32	ulIcmpAcceptNum;	/*		ICMP报文通过总数*/
	UINT32	ulIcmpMarkrNum;		/*		ICMP报文其它处理总数*/
} AC_OMA_AC_ACL_STAT_T;

/*2011-11-02 ldm add  */
/* 主备切换统计信息*/
typedef struct
{
	UINT32	ulAcId;
	
	UINT32 ulMsChgNum;  /* 主备切换次数 */
} AC_OMA_AC_MS_STAT_T;



/* WAPI信息 */
typedef struct
{
	UINT32 ulUserStatus;        //用户状态
    UINT8  aucUserMacAddr[6];   //用户MAC地址
    UINT8  aucResv[2];	        //填充字节
    UINT8  aucUserIpAddr[4];    //用户IP地址
    UINT32 ulUserAuthState;     //用户鉴权状态
	/*
	 * 0:未鉴权
	 * 1:已鉴权
	 */
	UINT32 ulUserUniCipher;					//单播密码套件	1：SMS4
	UINT32 ulUserReplayCounter;				//因重放机制丢弃的报文数
	UINT32 ulUserDecryptErrors;				//解密错误丢弃的报文数
	UINT32 ulUserMicErrors;					//校验错误丢弃的报文数
	UINT32 ulUserWaiSignError;				//WAI消息签名错误计数
	UINT32 ulUserWaiMacError;				//WAI消息校验错误计数
	UINT32 ulUserWaiFailure;				//WAI鉴别失败次数
	UINT32 ulUserWaiDiscard;				//WAI消息丢弃数目
	UINT32 ulUserWaiTimeout;				//WAI超时次数
	UINT32 ulUserWaiFormatError;			//WAI消息格式错误计数
	UINT32 ulUserWaiCertHandshakeFailure;   //WAI证书握手失败次数
	UINT32 ulUserWaiUniHandshakeFailure;    //WAI单播密钥协商失败次数
	UINT32 ulUserWaiMultiHandshakeFailure;  //WAI组播密钥通告失败次数
}AC_OMA_AC_USER_WAPI_STAT_T;

typedef struct
{
	UINT32 ulAcId;          //AC ID
	UINT32 ulWtpId;         //WTP ID
	UINT32 ulVapId;         //VAP ID
	CHAR   acApSsid[32];    //VAP SSID
	UINT32 ulUniKeyNum;     //最大单播密钥数目
	UINT32 ulMultiKeySize;  //多播密码长度
	UINT32 ulAuthCipherSel; //最近一次选择的鉴权套件
	/*
	 * 1:证书
	 * 2:预共享密钥
	 */
	UINT32 ulUniCipherSel;   //最近一次选择的单播密码套件	1:SMS4
	UINT32 ulMultiCipherSel; //最近一次选择的多播密码套件	1:SMS4
	UINT8  aucLastBKID[16];  //最近一次使用的BKID
	UINT32 ulAuthCipherReq;  //最近一次请求的鉴权套件
	/*
	 * 1:证书
	 * 2:预共享密钥
	 */
	UINT32 ulUniCipherReq;   //最近一次请求的单播密码套件	1:SMS4
	UINT32 ulMultiCipherReq; //最近一次请求的多播密码套件	1:SMS4

	UINT32 ulValidUserNum;   //有效用户数目	界面上要显示每个VAP上的用户数目。
	AC_OMA_AC_USER_WAPI_STAT_T *pstUserWapiStat;
}AC_OMA_AC_VAP_WAPI_STAT_T;

/*typedef struct  
{
	UINT32 ulWtpId;            //AP设备ID
    UINT32 ulVapNum;           //Wapi vap的数目
	AC_OMA_AC_VAP_WAPI_STAT_T *pstVapWapiStat;
}AC_OMA_AC_AP_WAPI_STAT_T;
*/

/* AC设备WAPI统计信息 */
typedef struct
{
	//UINT32 ulAcId;             //AC设备ID
    UINT32 ulValidNum;         //
	AC_OMA_AC_VAP_WAPI_STAT_T *pstApWapiStat;
}AC_OMA_AC_WAPI_STAT_T;

typedef struct
{
	UINT32   ulWtpId;       //AP设备ID
	UINT32   ulVapId;       //VAP ID
	CHAR     acApSsid[32];  //VAP SSID

	UINT32	ulAcLanId;		/* AP所连接的AC接口*/

	UINT32	ulUpByte;				/*	上行总流量*/
	UINT32	ulDownByte;				/*	下行总流量*/
	UINT32	ulUpFrame;				/*	上行总帧数*/
	UINT32	ulUpErrFrame;			/*	上行错误帧数*/
	UINT32	ulUpDiscardFrame;		/*	上行丢帧数*/
	UINT32	ulUpRetransFrame;		/*	上行重传帧数*/
	UINT32	ulDownFrame;			/*	下行总帧数*/
	UINT32	ulDownErrFrame;			/*	下行错误帧数*/
	UINT32	ulDownDiscardFrame;	/*	下行丢帧数*/
	UINT32	ulDownRetransFrame;	/*	下行重传帧数*/
	UINT32	ulUpAssoFrame;			/* 上行关联帧数*/
	UINT32	ulDownAssoFrame;		/* 下行关联帧数*/
} AC_OMA_ACVAPWIFISTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulVapNum;
	AC_OMA_ACVAPWIFISTAT_INFO_T	*pstVapWifiStat;
} AC_OMA_ACVAPWIFISTAT_T;

typedef struct
{
	UINT32   ulWtpId;       //AP设备ID
	UINT32   ulVapId;       //VAP ID
	CHAR     acApSsid[32];  //VAP SSID

	UINT32	ulAcLanId;		/* AP所连接的AC接口*/

	UINT32	ulAccessTimes;		/*	AP的无线用户链接次数*/
	UINT32	ulAccessFailTimes;	/*	AP的无线用户链接失败次数*/
	UINT32	ulAccessRetryTimes;	/*	AP的无线用户重链接次数*/
	UINT32	ulAccessDenyTimes;	/*	AP的无线用户链接拒绝次数*/
	UINT32	ulAccessOutTimes1;	/*	因用户离开而导致解关联的次数*/
	UINT32	ulAccessOutTimes2;	/*	因AP能力不足而导致解关联的次数*/
	UINT32	ulAccessOutTimes3;	/*	因异常情况而导致解关联的次数*/
	UINT32	ulAccessOutTimes4;	/*	其它原因导致解关联的次数*/
} AC_OMA_ACVAPUSERACCSTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulVapNum;
	AC_OMA_ACVAPUSERACCSTAT_INFO_T	*pstVapUserAccStat;
} AC_OMA_ACVAPUSERACCSTAT_T;

typedef struct
{
	UINT32	ulAcLanId;		/* AP所连接的AC接口*/

	UINT32	ulUpByte;				/*	上行总流量*/
	UINT32	ulDownByte;				/*	下行总流量*/
	UINT32	ulUpFrame;				/*	上行总帧数*/
	UINT32	ulUpErrFrame;			/*	上行错误帧数*/
	UINT32	ulUpDiscardFrame;		/*	上行丢帧数*/
	UINT32	ulUpRetransFrame;		/*	上行重传帧数*/
	UINT32	ulDownFrame;			/*	下行总帧数*/
	UINT32	ulDownErrFrame;			/*	下行错误帧数*/
	UINT32	ulDownDiscardFrame;	/*	下行丢帧数*/
	UINT32	ulDownRetransFrame;	/*	下行重传帧数*/
	UINT32	ulUpAssoFrame;			/* 上行关联帧数*/
	UINT32	ulDownAssoFrame;		/* 下行关联帧数*/
} AC_OMA_ACIFWIFISTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulIfNum;
	AC_OMA_ACIFWIFISTAT_INFO_T	*pstIfWifiStat;
} AC_OMA_ACIFWIFISTAT_T;

typedef struct
{
	CHAR     acApSsid[32];  //VAP SSID
	UINT64	ulUpByte;				/*	上行总流量*/
	UINT64	ulDownByte;				/*	下行总流量*/
	UINT32	ulUpFrame;				/*	上行总帧数*/
	UINT32	ulUpErrFrame;			/*	上行错误帧数*/
	UINT32	ulUpDiscardFrame;		/*	上行丢帧数*/
	UINT32	ulUpRetransFrame;		/*	上行重传帧数*/
	UINT32	ulDownFrame;			/*	下行总帧数*/
	UINT32	ulDownErrFrame;			/*	下行错误帧数*/
	UINT32	ulDownDiscardFrame;	/*	下行丢帧数*/
	UINT32	ulDownRetransFrame;	/*	下行重传帧数*/
	UINT32	ulUpAssoFrame;			/* 上行关联帧数*/
	UINT32	ulDownAssoFrame;		/* 下行关联帧数*/
} AC_OMA_ACSSIDWIFISTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulSsidNum;
	AC_OMA_ACSSIDWIFISTAT_INFO_T	*pstSsidWifiStat;
} AC_OMA_ACSSIDWIFISTAT_T;

/* 漫游统计 */
typedef struct
{
	UINT32 ulAcId;
	UINT32 ulInAcRoamingSuccTimes;  /* 同控制域内终端漫游成功的次数 */
	UINT32 ulAcRoamingIn;           /* 跨控制域终端漫游转入成功的次数 */
	UINT32 ulAcRoamingOut;          /* 跨控制域终端漫游转出成功的次数 */

	UINT32 ulRadiusAuthReq;         /* AC发往Radius的认证请求次数 */
	UINT32 ulRadiusAuthResp;        /* AC收到Radius的认证请求响应次数 */
	
	/* 2010/08/06 fengjing cmcc test */
	/* 对应认证请求数、认证成功数 */
	UINT32 ulRadiusAuthReq2;        /*AC发向RADIUS的认证次数*/
	UINT32 ulRadiusAuthSucc;        /* AC收到Radius的认证请求通过次数 */

	/* 2011-04-06 fengjing add:浙江移动测试 */
	UINT32 ulRadiusAuthReject;             /*AC收到Radius的认证拒绝次数*/
       UINT32 ulRadiusAuthReqFailed;      /*AC发送的RADIUS认证请求失败次数*/
}AC_OMA_HOSTAPDSTAT_T;

/* 计费统计 */
typedef struct
{
	UINT32 ulAcId;
	UINT32 ulAccountReq;      /* 计费请求数 */
	UINT32 ulAccountSuccRsp;  /* 计费成功数 */
}AC_OMA_ACCOUNTSTAT_T;

/* AP流量统计信息 */
typedef struct
{
	UINT32 	ulWtpId;		/* AP ID */
	UINT32	ulUlPkts;			/*上行包数 */
	UINT32	ulDlPkts;			/*下行包数 */
	UINT32	ulUlGigaWords;	/*上行字节数：单位4GByte */
	UINT32	ulUlBytes;		/*上行字节数：单位Byte */
	UINT32	ulDlGigaWords;	/*下行字节数：单位4GByte */
	UINT32	ulDlBytes;		/*上行字节数：单位Byte */
}AC_OMA_APTRAFFIC_STAT_T;
 
/* AP设备流量统计信息 */
typedef struct
{
	UINT32	ulProcUptime;	/* powerac线程上电时间，单位：秒 */
	UINT32 	ulValidNum;         /* AP数量 */
   	AC_OMA_APTRAFFIC_STAT_T *pstApTrafficStat;
}AC_OMA_GET_APTRAFFIC_STAT_T;

/* AP用户统计信息 */
typedef struct
{
	UINT32 	ulWtpId;			/* AP ID */
	UINT32	ulUserAuthReq;	/* 用户认证请求次数 */
	UINT32	ulUserOnlineTime;	/* 用户在线时长，单位：分钟 */
	UINT32	ulUserNum;		/* 累计的用户数目 */
}AC_OMA_APUSERSTAT_STAT_T;
 
/* AP设备用户统计信息 */
typedef struct
{
	UINT32	ulProcUptime;			/* powerac线程上电时间，单位：秒 */
	UINT32 	ulValidNum;         /* AP数量 */
   	AC_OMA_APUSERSTAT_STAT_T *pstApUserStat;
}AC_OMA_GET_APUSER_STAT_T;


/*
 * OMA->APP REQ DYNA INFO
 */
typedef struct
{
	UINT32   ulMsgType;        //MSG_TYPE_OMCR
	                           //MSG_TYPE_WEB
	UINT32   ulSn;
}AC_OMA_GET_AC_DYNAINFO_REQ_MSG_T;

/*
 * APP->OMA RSP DYNA INFO
 */
typedef struct
{
	UINT32   ulMsgType;        //MSG_TYPE_OMCR
	                           //MSG_TYPE_WEB

	UINT32   ulSn;
	UINT32   ulRet;            //返回码:0-成功
	UINT32   ulFinish;         //是否结束:0-未结束 1-结束
	UINT8    aucRsp[4096];     //网络字节序
}AC_OMA_GET_AC_DYNAINFO_RSP_MSG_T;

/* OMC/WEB->AC-OMA请求消息体 */
typedef struct
{
	UINT32   ulSn;
	UINT32   ulDynaInfoType;
}AC_OMC_GET_AC_DYNAINFO_REQ_MSG_T;

/* AC-OMA->OMC/WEB应答消息体 */
typedef struct
{
	UINT32   ulSn;
	UINT32   ulRet;             //返回码:0-成功
	UINT32   ulFinish;          //是否结束:0-未结束 1-结束
	UINT8    aucRsp[4096];      //网络字节序
}AC_OMC_GET_AC_DYNAINFO_RSP_MSG_T;

/* OMC/WEB->AC-OMA RESET请求消息体 */
typedef struct
{
    UINT32  ulSn;
}AC_OMC_RESET_REQ_MSG_T;

/* AC-OMA->OMC/WEB应答消息体 */
typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
}AC_OMC_RESET_RSP_MSG_T;

/* OMC/WEB->AC-OMA 获取网元配置数据版本号请求消息体 */
typedef struct  
{
	UINT32  ulSn;
}AC_OMA_GET_NECFGVERSION_REQ_MSG_T;

typedef struct  
{
	UINT32  ulApId;
	UINT32  ulApCfgVersion;
}AP_CFGVER_T;

/* AC-OMA->OMC/WEB应答消息体 */
typedef struct  
{
	UINT32  ulSn;
	UINT32  ulRet;
	UINT32  ulCfgVersion;
	UINT32  ulAcId;
	UINT32  ulAcCfgVersion;
	UINT32  ulApNum;
	AP_CFGVER_T astApCfgVersion[AC_WTPID_MAX];
}AC_OMA_GET_NECFGVERSION_RSP_MSG_T;

/* OMC/WEB->AC-OMA获取网元主备状态请求消息体 */
typedef struct
{
	UINT32  ulSn;
}AC_OMC_GET_MSSTATUS_REQ_MSG_T;

/* AC-OMA->OMC/WEB应答消息体 */
typedef struct
{
	UINT32  ulSn;
	UINT32  ulRet;
	UINT32  ulActive;  /* TRUE: 当前Active 
	                                  FALSE: 当前Standby
 					*/
}AC_OMC_GET_MSSTATUS_RSP_MSG_T;


/* OMC/WEB->AC-OMA 获取AP动态信息 */
typedef struct  
{
	UINT32  ulApId;
	UINT32  ulSn;
}AC_OMC_GET_AP_DYNAINFO_REQ_MSG_T;

typedef struct  
{
	UINT32  ulMsgType;
	UINT32  ulSn;
}AC_OMA_GET_AP_DYNAINFO_REQ_MSG_T;

typedef struct  
{	
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;            //返回码:0-成功
	UINT32   ulFinish;         //是否结束:0-未结束 1-结束
	UINT8    aucRsp[32*1024];     //网络字节序
}AC_OMA_GET_AP_DYNAINFO_RSP_MSG_T;

/* AP重启 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
}AC_OMC_AP_REBOOT_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
}AC_OMA_AP_REBOOT_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_REBOOT_RSP_MSG_T;

/* PING测试 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT8    aucIp[4];
}AC_OMC_AP_PINGTEST_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT8    aucIp[4];
}AC_OMA_AP_PINGTEST_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_PINGTEST_RSP_MSG_T;

typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
}AC_OMC_AP_PINGSUMMARY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
}AC_OMA_AP_PINGSUMMARY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
	CHAR     acSummary[128];
}AC_OMA_AP_PINGSUMMARY_RSP_MSG_T;

/* 设置设备时间 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
	UINT32   ulTime;
}AC_OMC_AP_SETTIME_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulTime; /* 距1970-01-01 00:00:00的秒数 */
}AC_OMA_AP_SETTIME_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_SETTIME_RSP_MSG_T;

/* 清除非法设备历史 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
}AC_OMC_AP_CLEARILLEGALDEVHISTORY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
}AC_OMA_AP_CLEARILLEGALDEVHISTORY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_CLEARILLEGALDEVHISTORY_RSP_MSG_T;

/* 清除攻击检测历史 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
}AC_OMC_AP_CLEARATTACKHISTORY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
}AC_OMA_AP_CLEARATTACKHISTORY_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_CLEARATTACKHISTORY_RSP_MSG_T;

/* 清除攻击检测统计 */
typedef struct  
{
	UINT32   ulApId;
	UINT32   ulSn;
}AC_OMC_AP_CLEARATTACKSTATIC_REQ_MSG_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
}AC_OMA_AP_CLEARATTACKSTATIC_REQ_MSG_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
	UINT32    ulRet;
}AC_OMA_AP_CLEARATTACKSTATIC_RSP_MSG_T;

/* 设置设备心跳周期(待定) */
typedef struct  
{
	UINT32    ulApId;
	UINT32    ulSn;
	UINT32    ulHBPeriod;
}AC_OMC_AP_SETHBPERIOD_REQ_MSG_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
	UINT32    ulHBPeriod;
}AC_OMA_AP_SETHBPERIOD_REQ_MSG_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
	UINT32    ulRet;
}AC_OMA_AP_SETHBPERIOD_RSP_MSG_T;

/* 查询软件版本下载状态信息 */
typedef struct  
{
	UINT32    ulApId;
	UINT32    ulSn;
}AC_OMC_AP_SWFILESTATE_REQ_MSG_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
}AC_OMA_AP_SWFILESTATE_REQ_MSG_T;

typedef struct  
{
	UINT32    ulNeId;
	UINT32    ulLoadFlag;        /* 上下载指示:1-下载 2-上传 */
	CHAR      acFileName[64];    /* 文件名 */
	UINT32    ulFileType;        /* 传输文件类型:1-软件版本文件 2-配置文件 3-日志文件 */
	UINT32    ulTransStatus;     /* 文件传输结果:1-传输中 2-传输成功完成 3-失败 */
	CHAR      acFailReason[128]; /* 失败原因 */
	UINT32    ulByteSize;        /* 已经上下载字节数 */
}AC_OMA_FILETRANS_T;

typedef struct  
{
	UINT32    ulMsgType;
	UINT32    ulSn;
	UINT32    ulRet;
	AC_OMA_FILETRANS_T stFileTrans;
}AC_OMA_AP_SWFILESTATE_RSP_MSG_T;

typedef struct  
{
	AC_OMA_FILETRANS_T stFileTrans;
}AC_OMA_AP_SWFILESTATE_IND_MSG_T;

/* AP->AC获取采集参数信息 */
typedef struct
{
	UINT32 ulSn;
}AC_OMC_AP_GET_COLLECTPARAM_REQ_MSG_T;

typedef struct
{
	UINT32 ulSn;
	UINT32 ulOn;	/*性能统计开关*/
	UINT32 ulPeriodNormal;	/* AP常规采集周期 单位:秒 10~120 */
	UINT32 ulPeriodRealtime;	/* AP实时采集周期 单位:秒 2~5 */
	UINT32 ulReportLevel;	/*各级性能采集开关，比特位表示，一张表对应一个ID*/
	UINT32 ulStatisticsTime;		/* 性能统计统计时长	>0	60	单位：秒*/
	UINT32 ulSampleTime;		/* 性能统计抽样时长	>0	10	单位：秒*/
	UINT32 ulAllAPMonitorMode;    /* AC级AP无线监视模式:
										1：提供WLAN接入服务
										2：监视无线环境
										3：空闲时监视无线环境 */
}AC_OMC_AP_GET_COLLECTPARAM_RSP_MSG_T;

#define AP_COLLECTPARAM_LEVEL_AP			0x00000001
#define AP_COLLECTPARAM_LEVEL_ETHERNET	0x00000002
#define AP_COLLECTPARAM_LEVEL_RADIO		0x00000004
#define AP_COLLECTPARAM_LEVEL_SSID		0x00000008
#define AP_COLLECTPARAM_LEVEL_STATION      0x00000010                        //表示是否上报终端统计信息
#define AP_COLLECTPARAM_LEVEL_STATION_ALL        0x00000020     //表示是否上报终端简单统计信息，0：简单统计；1：含多速率统计；在启用AP_COLLECTPARAM_LEVEL_STATION后，本值有意义；
#define AP_COLLECTPARAM_LEVEL_WIDS            0x00000040
#define AP_COLLECTPARAM_LEVEL_OTHER		0x80000000

typedef struct
{
	UINT32   ulPrintApId;
	UINT32   ulReportLevelAp;
	UINT32   ulReportLevelEthIf;
	UINT32   ulReportLevelRadio;
	UINT32   ulReportLevelSsid;
	UINT32   ulReportLevelStation;
	UINT32   ulReportLevelStationAll;
	UINT32   ulReportLevelWids;
	UINT32   ulReportLevelOther;
}AC_OMA_AP_REPORT_LEVEL_T;

/*AP性能统计上报消息头*/
typedef struct  
{	
	UINT32   ulApId;                    // AP ID
	UINT32   ulSn;
	UINT32   ulTimeStamp;         //时间戳，自1970.1.1号的秒数；
	UINT32   ulFinish;         	  //是否结束:0-未结束 1-结束        
	UINT32   ulRspLength;     // aucRsp长度，不含本消息头
	UINT8    aucRsp[32*1024];     //网络字节序
}AC_OMA_AP_DYNAINFO_IND_MSG_T;

typedef struct
{
	UINT32 ulType;
	UINT32 ulLength;	/*不含本消息头*/
}AC_ELEM_T;

/*性能采集类型，一张表对应一个TAGID*/
enum
{
	  AP_OMA_DYNAINFO_TYPE_AP = 0,                            /*AP级统计*/
         AP_OMA_DYNAINFO_TYPE_ABSTRACT = 0,         

         AP_OMA_DYNAINFO_TYPE_ETHERNET=10,  		/*有线网卡级统计*/
         AP_OMA_DYNAINFO_TYPE_ETHSTATS = 10,

         AP_OMA_DYNAINFO_TYPE_RADIO=20,          		 /*无线网卡级统计*/
         AP_OMA_DYNAINFO_TYPE_RADIOSTATS = 20,
         AP_OMA_DYNAINFO_TYPE_NEIGHAPSTATS = 21,
      
         AP_OMA_DYNAINFO_TYPE_SSID=30,              		/*SSID级统计*/
         AP_OMA_DYNAINFO_TYPE_SSIDAIR = 30,
         AP_OMA_DYNAINFO_TYPE_SSIDMGT = 31,
         AP_OMA_DYNAINFO_TYPE_SSIDASSOC = 32,

         AP_OMA_DYNAINFO_TYPE_STATION=40,       		/*终端级统计*/
         AP_OMA_DYNAINFO_TYPE_STASTATS_SIMPLE = 40,
         AP_OMA_DYNAINFO_TYPE_STASTATS_ALL = 41,

         AP_OMA_DYNAINFO_TYPE_WIDS=50,             		/*WIDS级统计*/
         AP_OMA_DYNAINFO_TYPE_WIDS_ROGUEAP=50,
         AP_OMA_DYNAINFO_TYPE_WIDS_ROGUESTA=51,

         AP_OMA_DYNAINFO_TYPE_RT=1000,            		 /*实时统计*/
         AP_OMA_DYNAINFO_TYPE_RTSTATS = 1000
};

/* 2010-08-27  fengjing add:OMC/WEB 操作日志 */
typedef struct
{
	CHAR    acOperator[64];     /* 操作人 */
	CHAR    acOperName[64];     /* 操作名称 */
	CHAR    acOperObject[128];  /* 操作对象 */
	CHAR    acOperInfo[128];    /* 操作内容 */
	CHAR    acOperResult[128];  /* 操作结果 */
}AC_OMC_ADMIN_LOG_IND_MSG_T;

/* add by gwx 2014-2-25 for task1265 */
/* 上报AP的SN */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT32	ulWtpProductType;	/* AP产品类型*/
	CHAR	acModelName[64];
} AC_OMA_APPRODUCTTYPE_UPDATE_T;

/* add by gwx 2014-5-28 for ruijie AP故障信息一键收集begin */
typedef struct
{
	UINT32 ulApId;
	UINT32 ulSn;
}AC_OMC_GET_AP_RUNINFO_REQ_T;
typedef struct
{
	UINT32 ulMsgType;
	UINT32 ulSn;
}AC_OMA_GET_AP_RUNINFO_REQ_T;

typedef struct
{
	UINT32 ulSn;
}AC_OMC_GET_AC_RUNINFO_REQ_T;
typedef struct
{
	UINT32 ulSn;
}AC_OMC_GET_AC_RUNINFO_RSP_T;
/* add by gwx 2014-5-28 for ruijie AP故障信息一键收集end */

/**************************** 函数定义 ***************************/
extern AC_RET ac_send_to_app(UINT16 usEvent, VOID * pMsg, UINT32 ulMsgLen, TPID stDestPID);

extern AC_RET ac_send_to_oma(UINT16 usEvent, VOID* pMsg, UINT32 usMsgLen);
extern AC_RET ac_oma_send_to_omc(UINT16 usEvent, VOID* pMsg, UINT32 usMsgLen);
extern AC_RET ac_oma_report_alarm(AC_OMA_ALARM_INFO_T *pstMsg);
extern AC_RET ac_oma_clear_alarm(AC_OMA_ALARM_CLEAR_INFO_T *pstMsg);
extern AC_RET ac_oma_report_event(AC_OMA_EVENT_INFO_T *pstMsg);

/* add */
extern AC_RET ac_oma_send_to_web(UINT16 usEvent, VOID* pMsg, UINT32 usMsgLen);

/* add */
extern AC_RET ac_oma_send_to_ap(UINT32 ulApId, UINT16 usMsgId, UINT8 *pucMsg, UINT32 ulMsgLen);

/* 应用模块应答性能数据到OMA */
extern AC_RET ac_oma_report_perf(UINT8 *pucRspMsg, UINT16 usMsgLen);

/* 应用模块主动上报动态信息到OMA */
extern AC_RET ac_oma_report_dyna_info(UINT32 ulDynaInfoType, VOID *pDynaInfo);

/* 2009-09-03 fengjing add */
extern AC_RET ac_oma_convert_objectid_to_moi(CHAR *szObjectId, UINT32 ulWtpId, UINT32 *pulMOC, UINT8* aucMOI);
extern AC_RET ac_oma_convert_mocmoi_to_objectid(UINT32 ulMOC, UINT8 *aucMOI, CHAR *pcObjectId);

extern VOID ac_snmp_log_error(CHAR *szLog);
extern VOID ac_snmp_log(INT32 iLogLevel, CHAR *szFormat, ...);

#define snmp_log            ac_snmp_log
#define snmp_log_perror     ac_snmp_log_error

#endif /* AC_OMA_PUBLIC_H */



