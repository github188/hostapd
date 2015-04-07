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

/**************************** �궨�� ***************************/
/* OMA�ڲ���Ϣ */
#define EV_AC_OMA_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 100)    /* �ϱ��澯���� */
#define EV_AC_OMA_CLEAR_ALARM_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 101)    /* �ϱ��澯������� */

#define EV_AC_OMA_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 104)    /* �ϱ��¼����� */

#define EV_AC_OMA_REPORT_PERF_REQ_MSG 	        ((UINT16)EV_OMA_BEGIN + 110)    /* �����ϱ�����ͳ�� */
#define EV_AC_OMA_REPORT_PERF_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 111)    /* ����ͳ��Ӧ�� */

#define EV_AC_OMA_EVENT_SIMU_MSG						((UINT16)EV_OMA_BEGIN + 112)		/* �¼�ģ����Ϣ*/
#define EV_AC_OMA_ALARM_REPORT_SIMU_MSG			((UINT16)EV_OMA_BEGIN + 113)		/* �澯ģ����Ϣ*/
#define EV_AC_OMA_ALARM_CLEAR_SIMU_MSG				((UINT16)EV_OMA_BEGIN + 114)		/* �澯ģ����Ϣ*/
 
/******************************************�澯**************************************************/
/* AC��OMC֮����Ϣ */
#define EV_AC_OMC_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 200)    /* �ϱ��澯���� */
#define EV_AC_OMC_REPORT_ALARM_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 201)    /* �ϱ��澯Ӧ�� */
#define EV_AC_OMC_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 202)    /* �ϱ��¼����� */
#define EV_AC_OMC_REPORT_EVENT_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 203)    /* �ϱ��¼�Ӧ�� */

#define EV_AC_OMC_REPORT_ALARM_CLEAR_IND_MSG    ((UINT16)EV_OMA_BEGIN + 204)    /* �ϱ��澯��� */

// 2009-11-03 fengjing add
#define EV_AC_OMC_REPORT_ALARM_BATCH_REQ_MSG  ((UINT16)EV_OMA_BEGIN + 206)     /* �����ϱ��澯���� */
#define EV_AC_OMC_REPORT_ALARM_BATCH_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 207)    /* �����澯Ӧ�� */
#define EV_AC_OMC_REPORT_EVENT_BATCH_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 208)    /* �����ϱ��¼����� */
#define EV_AC_OMC_REPORT_EVENT_BATCH_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 209)    /* �����¼�Ӧ�� */

/* 2009-09-03 fengjing add AP-OMA<->AC-OMA �澯�¼���Ϣ */
#define EV_AP_OMA_REPORT_ALARM_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 210)    /* �ϱ��澯���� */
#define EV_AP_OMA_REPORT_ALARM_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 211)    /* �ϱ��澯Ӧ�� */
#define EV_AP_OMA_REPORT_EVENT_REQ_MSG          ((UINT16)EV_OMA_BEGIN + 212)    /* �ϱ��¼����� */
#define EV_AP_OMA_REPORT_EVENT_RSP_MSG          ((UINT16)EV_OMA_BEGIN + 213)    /* �ϱ��¼�Ӧ�� */

 /* 2012-04-11 ldm modify */
#define EV_AP_OMA_REPORT_TRAP_HIDE_MSG          ((UINT16)EV_OMA_BEGIN + 270)    /* ֪ͨ���θ澯��Ϣ*/

/******************************************����******************************************************/
#define EV_AC_OMC_REPORT_PERF_REQ_MSG 	        ((UINT16)EV_OMA_BEGIN + 300)    /* �ϱ�����ͳ������ */
#define EV_AC_OMC_REPORT_PERF_RSP_MSG 	        ((UINT16)EV_OMA_BEGIN + 301)    /* �ϱ�����ͳ��Ӧ�� */

#define EV_AC_OMC_SET_PERF_TASK_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 305)     /* ��������ͳ���������� */
#define EV_AC_OMC_SET_PERF_TASK_RSP_MSG         ((UINT16)EV_OMA_BEGIN + 306)     /* ��������ͳ������Ӧ�� */

/* 2009-09-03 fengjing add AP-OMA<->AC-OMA������Ϣ */
#define EV_AP_OMA_REPORT_PERF_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 310)    /* �ϱ�����ͳ������ */
#define EV_AP_OMA_REPORT_PERF_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 311)    /* �ϱ�����ͳ��Ӧ�� */

/******************************************��̬��Ϣ***********************************************/
#define EV_AC_OMC_REPORT_STATEUPDATE_IND_MSG    ((UINT16)EV_OMA_BEGIN + 400)     /* �ϱ�״̬��Ϣ */

#define EV_AC_OMC_REPORT_USERONLINE_IND_MSG     ((UINT16)EV_OMA_BEGIN + 403)     /* �ϱ��û����� */
#define EV_AC_OMC_REPORT_USEROFFLINE_IND_MSG    ((UINT16)EV_OMA_BEGIN + 404)     /* �ϱ��û����� */
#define EV_AC_OMC_REPORT_USERPOS_IND_MSG        ((UINT16)EV_OMA_BEGIN + 405)     /* �ϱ��û�λ����Ϣ */
#define EV_AC_OMC_REPORT_DYNPOWER_IND_MSG       ((UINT16)EV_OMA_BEGIN + 406)     /* �����豸��ǰ������Ϣ�ϱ� */

/* �����ϱ�AP��ǰIP��ַ��Ϣ */
#define EV_AC_OMC_REPORT_APDYNAIP_IND_MSG       ((UINT16)EV_OMA_BEGIN + 407)     /* AP��ǰIP��ַ��Ϣ�ϱ� */
#define EV_AC_OMC_REPORT_ACIP_IND_MSG           ((UINT16)EV_OMA_BEGIN + 408)     /* AC��ǰIP��ַ��Ϣ�ϱ� */
#define EV_AC_OMC_REPORT_APSN_IND_MSG           ((UINT16)EV_OMA_BEGIN + 409)     /* AP��ǰSN��Ϣ�ϱ� */
/* 2009-10-15 fengjing add */
#define EV_AC_OMC_REPORT_APSWVER_IND_MSG        ((UINT16)EV_OMA_BEGIN + 410)    /* AP��ǰ����汾��Ϣ�ϱ� */

/* 2009-09-07 fengjing add */
#define EV_AC_OMC_REPORT_MAXPOWER_IND_MSG       ((UINT16)EV_OMA_BEGIN + 415)     /* AP�����豸����书���ϱ� */
#define EV_AC_OMC_REPORT_VAPMAC_IND_MSG         ((UINT16)EV_OMA_BEGIN + 416)     /* VAP �豸MAC��ַ�ϱ� */
#define EV_AC_OMC_REPORT_ADHOCMAC_IND_MSG       ((UINT16)EV_OMA_BEGIN + 417)     /* ADHOC�豸MAC��ַ�ϱ� */

/* add master-slave switch */
#define EV_AC_OMC_REPORT_MSSTATE_IND_MSG        ((UINT16)EV_OMA_BEGIN + 418)     /* ����״̬�ϱ� */

/* 2008/09/18 �뾲 ���� ֪ͨ��Ԫ������Ϣ */
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

/* OMC/AC-WEB��ѯ��Ԫ�������ݰ汾��Ϣ */
#define EV_AC_OMC_GET_NECFGVERSION_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 450)
#define EV_AC_OMC_GET_NECFGVERSION_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 451)

/* Agent->OMA AP�ϱ�����ı仯 */
#define EV_AC_OMA_REPORT_APREPORTLEVEL_IND_MSG  ((UINT16)EV_OMA_BEGIN + 460)

/* OMC/AC-WEB��ѯAC����״̬��Ϣ */
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

/* BEGIN: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */
/* 2012-1-24 wubin add:license ��֤��Ϣ��� */
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
/* END: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */

/***************************************��־*******************************/
#define EV_AC_OMC_ADMIN_LOG_IND_MSG           ((UINT16)EV_OMA_BEGIN + 540)

/***************************************���*******************************/

/* 2008/08/30 �뾲 ������������Ϣ�ţ��Ժ�����ⲿ�ֺ궨����Ҫ�ŵ�����ģ���У����Ǿ���OMA���� */
#define EV_AC_OMC_SW_DOWNLOAD_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 600)       /* ��������汾���� */
#define EV_AC_OMC_SW_DOWNLOAD_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 601)       /* Ӧ������汾���� */
#define EV_AC_OMC_SW_ACTIVATE_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 604)       /* ��������汾��Ч */
#define EV_AC_OMC_SW_ACTIVATE_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 605)       /* Ӧ������汾��Ч */
#define EV_AC_OMC_SW_VERSION_STATE_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 607)       /* ��ѯ����汾״̬���� */
#define EV_AC_OMC_SW_VERSION_STATE_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 608)       /* ��ѯ����汾״̬Ӧ�� */

/* oma download sw version finished/failed,notify omc */
#define EV_AC_OMC_SW_DOWNLOAD_IND_MSG           ((UINT16)EV_OMA_BEGIN + 610)

/* oma send ftp download msg to oma,single processing */
#define EV_AC_OMC_SW_FTPDOWNLOAD_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 620)       /* ���ⷢ������������� */

/* oma ftp download sw verfile,and notify other app module activate this sw version */
//#define EV_AC_APP_SW_ACTIVATE_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 621)       /* ֪ͨ����Ӧ��ģ��������Ч */

/* 2009-10-20 fengjing add delete sw msg */
#define EV_AC_OMC_SW_DELETE_REQ_MSG               ((UINT16)EV_OMA_BEGIN + 621)     /* ����ɾ����Ԫ����汾 */
#define EV_AC_OMC_SW_DELETE_RSP_MSG               ((UINT16)EV_OMA_BEGIN + 622)    /* Ӧ��ɾ����Ԫ����汾 */

/**************************************͸��********************************/
/* add omc request wtp config change transfer to wtp ne */
/* including sys operations */
#define EV_AC_OMC_COMMAND_RELAY_REQ_MSG         ((UINT16)EV_OMA_BEGIN + 700)
#define EV_AC_OMC_COMMAND_RELAY_RSP_MSG         ((UINT16)EV_OMA_BEGIN + 701)
#define EV_AC_OMC_COMMAND_RELAY_IND_MSG         ((UINT16)EV_OMA_BEGIN + 702)

/* 2009-08-20 fengjing add begin */
/* ��ѯAP�ڵ���Ϣ */
#define EV_AC_OMC_GET_AP_NODEINFO_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 708)
#define EV_AC_OMC_GET_AP_NODEINFO_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 709)

/* ��ѯAP�ھ���Ϣ */
#define EV_AC_OMC_GET_AP_AODVNEIGHBOR_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 710)
#define EV_AC_OMC_GET_AP_AODVNEIGHBOR_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 711)

/* ��ѯAP·����Ϣ */
#define EV_AC_OMC_GET_AP_ROUTEPATH_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 712)
#define EV_AC_OMC_GET_AP_ROUTEPATH_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 713) 

/* ��ѯAP�����ն���Ϣ */
#define EV_AC_OMC_GET_AP_ENDUSER_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 714)
#define EV_AC_OMC_GET_AP_ENDUSER_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 715)
	 
/* ��ѯ����AP */
#define EV_AC_OMC_GET_AP_ROGUEAPINFO_REQ_MSG    ((UINT16)EV_OMA_BEGIN + 716)
#define EV_AC_OMC_GET_AP_ROGUEAPINFO_RSP_MSG    ((UINT16)EV_OMA_BEGIN + 717)
	 
/* ��ѯ���ɶ�վ�б� */
#define EV_AC_OMC_GET_AP_INVALIDSTAINFO_REQ_MSG ((UINT16)EV_OMA_BEGIN + 718)
#define EV_AC_OMC_GET_AP_INVALIDSTAINFO_RSP_MSG ((UINT16)EV_OMA_BEGIN + 719)
	 
/* AP���� */
#define EV_AC_OMC_AP_REBOOT_REQ_MSG             ((UINT16)EV_OMA_BEGIN + 720)
#define EV_AC_OMC_AP_REBOOT_RSP_MSG             ((UINT16)EV_OMA_BEGIN + 721)

/* PING���� */
#define EV_AC_OMC_AP_PINGTEST_REQ_MSG           ((UINT16)EV_OMA_BEGIN + 722)
#define EV_AC_OMC_AP_PINGTEST_RSP_MSG           ((UINT16)EV_OMA_BEGIN + 723)
#define EV_AC_OMC_AP_PINGSUMMARY_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 724)
#define EV_AC_OMC_AP_PINGSUMMARY_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 725)
	 
/* ����AP�豸ʱ�� */
#define EV_AC_OMC_AP_SETTIME_REQ_MSG            ((UINT16)EV_OMA_BEGIN + 726)
#define EV_AC_OMC_AP_SETTIME_RSP_MSG            ((UINT16)EV_OMA_BEGIN + 727)
	 
/* ����Ƿ��豸��ʷ */
#define EV_AC_OMC_AP_CLEARILLEGALDEVHISTORY_REQ_MSG ((UINT16)EV_OMA_BEGIN + 728)
#define EV_AC_OMC_AP_CLEARILLEGALDEVHISTORY_RSP_MSG ((UINT16)EV_OMA_BEGIN + 729)
	 	 
/* ������������ʷ */
#define EV_AC_OMC_AP_CLEARATTACKHISTORY_REQ_MSG ((UINT16)EV_OMA_BEGIN + 730)
#define EV_AC_OMC_AP_CLEARATTACKHISTORY_RSP_MSG ((UINT16)EV_OMA_BEGIN + 731)
	 
/* ����������ͳ�� */
#define EV_AC_OMC_AP_CLEARATTACKSTATIC_REQ_MSG  ((UINT16)EV_OMA_BEGIN + 732)
#define EV_AC_OMC_AP_CLEARATTACKSTATIC_RSP_MSG  ((UINT16)EV_OMA_BEGIN + 733)

/* �����豸�������ڣ�������*/
#define EV_AC_OMC_AP_SETHBPERIOD_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 734)
#define EV_AC_OMC_AP_SETHBPERIOD_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 735)
	
/* 2009-09-07 fengjing add */
#define EV_AC_OMC_AP_GETTOTALCFG_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 740)
#define EV_AC_OMC_AP_GETTOTALCFG_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 741)

/* ��ѯAP���豸ժҪ��Ϣ */
#define EV_AC_OMC_GET_AP_ABSTRACTINFO_REQ_MSG   ((UINT16)EV_OMA_BEGIN + 750)
#define EV_AC_OMC_GET_AP_ABSTRACTINFO_RSP_MSG   ((UINT16)EV_OMA_BEGIN + 751)
		
/* ��ѯAP Mesh�ش���·�б���Ϣ */
#define EV_AC_OMC_GET_AP_ADHOCLINKSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 752)
#define EV_AC_OMC_GET_AP_ADHOCLINKSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 753)
	
/* ��ѯAP���û�����ͳ�� */
#define EV_AC_OMC_GET_AP_TOTALSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 754)
#define EV_AC_OMC_GET_AP_TOTALSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 755)

/* ��ѯAP��տ��շ�ͳ�� */
#define EV_AC_OMC_GET_AP_WIFISTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 756)
#define EV_AC_OMC_GET_AP_WIFISTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 757)
	
/* ��ѯAP����̫���շ�ͳ�� */
#define EV_AC_OMC_GET_AP_IFSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 758)
#define EV_AC_OMC_GET_AP_IFSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 759)
			 
/* ��ѯAP�����ͳ�� */
#define EV_AC_OMC_GET_AP_ASSOSTATISTICS_REQ_MSG ((UINT16)EV_OMA_BEGIN + 770)
#define EV_AC_OMC_GET_AP_ASSOSTATISTICS_RSP_MSG ((UINT16)EV_OMA_BEGIN + 771)

/* 2010-4-11 pyy �����������ܲ�������: ��ȡ���ŵ�����ʧ��ͳ����Ϣ*/
#define EV_AC_OMC_GET_VDEV_ICSTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 772)
#define EV_AC_OMC_GET_VDEV_ICSTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 773)

/* 2010/05/15 fengjing add */
#define EV_AC_OMC_GET_AP_MGTSTAT_REQ_MSG      ((UINT16)EV_OMA_BEGIN + 774)
#define EV_AC_OMC_GET_AP_MGTSTAT_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 775)

/* 2010-08-26 fengjing ����:��ȡ�ھ�AP��Ϣ */
#define EV_AC_OMC_GET_AP_NEIGHBORAP_REQ_MSG     ((UINT16)EV_OMA_BEGIN + 776)
#define EV_AC_OMC_GET_AP_NEIGHBORAP_RSP_MSG     ((UINT16)EV_OMA_BEGIN + 777)

/* ��ѯAP����汾����״̬ */
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

/* ����ɼ��ϱ���Ϣ�� */
#define EV_AC_OMC_AP_DYNAINFO_IND_MSG	((UINT16)EV_OMA_BEGIN+787)
/* ʵʱ�ɼ��ϱ���Ϣ�� */
#define EV_AC_OMC_AP_RTDYNAINFO_IND_MSG	((UINT16)EV_OMA_BEGIN+788)

/* add by gwx 2014-5-18 for ruijie ������Ϣһ���ռ�*/
#define EV_AC_OMA_GET_AP_RUNINFO_REQ_MSG	((UINT16)EV_OMA_BEGIN + 791)
#define EV_AC_OMA_GET_AP_RUNINFO_RSP_MSG	((UINT16)EV_OMA_BEGIN + 792)

/*****************************************��ѯAC��̬��Ϣ******************/
/* OMC/WEB<->AC-OMA */
/* ���Ӷ�̬��Ϣ��ȡ��Ϣ */
#define EV_AC_OMC_GET_AC_DYNAINFO_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 800)
#define EV_AC_OMC_GET_AC_DYNAINFO_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 801)
#define EV_AC_OMC_GET_AC_WTPACCESS_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 811)

/* AC-OMA<->AC-APP */
/* AC-OMA<->AC-APP GET AC DYNA INFO MSG DEFINITION */
#define EV_AC_OMA_GET_AC_DEVICEABSTRACT_REQ_MSG  	((UINT16)EV_OMA_BEGIN + 900)			/* AC�豸ժҪ��Ϣ*/
#define EV_AC_OMA_GET_AC_DEVICEABSTRACT_RSP_MSG  ((UINT16)EV_OMA_BEGIN + 901)

#define EV_AC_OMA_GET_AC_WTPACCESS_REQ_MSG       	((UINT16)EV_OMA_BEGIN + 902)			/* AP��Ϣ�б�*/
#define EV_AC_OMA_GET_AC_WTPACCESS_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 903)

#define EV_AC_OMA_GET_AC_USERACCESS_REQ_MSG      	((UINT16)EV_OMA_BEGIN + 904)			/* �û���Ϣ�б�*/
#define EV_AC_OMA_GET_AC_USERACCESS_RSP_MSG      ((UINT16)EV_OMA_BEGIN + 905)

#define EV_AC_OMA_GET_AC_DHCPSTAT_REQ_MSG			((UINT16)EV_OMA_BEGIN + 906)			/* DHCPͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_DHCPSTAT_RSP_MSG			((UINT16)EV_OMA_BEGIN + 907)

#define EV_AC_OMA_GET_AC_DHCPALLOCATE_REQ_MSG    	((UINT16)EV_OMA_BEGIN + 908)			/* DHCP IP��ַ������Ϣ*/
#define EV_AC_OMA_GET_AC_DHCPALLOCATE_RSP_MSG    	((UINT16)EV_OMA_BEGIN + 909)

#define EV_AC_OMA_GET_AC_IFSTAT_REQ_MSG          		((UINT16)EV_OMA_BEGIN + 910)			/* AC�ӿ�ͳ��(����)*/
#define EV_AC_OMA_GET_AC_IFSTAT_RSP_MSG         	 	((UINT16)EV_OMA_BEGIN + 911)

#define EV_AC_OMA_GET_AC_VAPWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 912)			/* AC�ӿ�ͳ��(����): ��ȡ����VAP�Ŀտ�ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_VAPWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 913)

#define EV_AC_OMA_GET_AC_VAPUSERACCSTAT_REQ_MSG	((UINT16)EV_OMA_BEGIN + 914)			/* AC�û�����ͳ��(����):��ȡ����VAP���û�����ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_VAPUSERACCSTAT_RSP_MSG	((UINT16)EV_OMA_BEGIN + 915)

#define EV_AC_OMA_GET_AC_ACIFWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 916)			/* AC�ӿ�ͳ��(����):����AC�ӿڻ�ȡ�տ�ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_ACIFWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 917)

#define EV_AC_OMA_GET_AC_SSIDWIFISTAT_REQ_MSG		((UINT16)EV_OMA_BEGIN + 918)			/* AC�ӿ�ͳ��(����):����SSID��ȡ�տ�ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_SSIDWIFISTAT_RSP_MSG		((UINT16)EV_OMA_BEGIN + 919)

#define EV_AC_OMA_GET_AC_PORTALSTAT_REQ_MSG      	((UINT16)EV_OMA_BEGIN + 920)			/* WEB��֤ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_PORTALSTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 921)

#define EV_AC_OMA_GET_AC_PPPOESTAT_REQ_MSG      		((UINT16)EV_OMA_BEGIN + 922)			/* PPPOE ��֤ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_PPPOESTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 923)

#define EV_AC_OMA_GET_AC_ACLSTAT_REQ_MSG      		((UINT16)EV_OMA_BEGIN + 924)			/* ACLͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_ACLSTAT_RSP_MSG      		((UINT16)EV_OMA_BEGIN + 925)

#define EV_AC_OMA_GET_AC_WAPISTAT_REQ_MSG        		((UINT16)EV_OMA_BEGIN + 926)			/* WAPI ͳ����Ϣ*/
#define EV_AC_OMA_GET_AC_WAPISTAT_RSP_MSG        		((UINT16)EV_OMA_BEGIN + 927)

#define EV_AC_OMA_GET_AC_USERIPINFO_REQ_MSG		((UINT16)EV_OMA_BEGIN + 928)			/* IP��ַ�������ͳ��*/
#define EV_AC_OMA_GET_AC_USERIPINFO_RSP_MSG			((UINT16)EV_OMA_BEGIN + 929)

/* 2009-10-21 fengjing add */
/* ��ȡAC�豸��δע����������ӵ�AP��Ϣ  */
#define EV_AC_OMA_GET_AC_WTPUNREGISTER_REQ_MSG     ((UINT16)EV_OMA_BEGIN + 930)               /* δע���ҳ��Թ�����AP */
#define EV_AC_OMA_GET_AC_WTPUNREGISTER_RSP_MSG     ((UINT16)EV_OMA_BEGIN + 931)

/* 2010/05/15 fengjing add */
#define EV_AC_OMA_GET_AC_ROAMINGSTAT_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 932)
#define EV_AC_OMA_GET_AC_ROAMINGSTAT_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 933)

/* 2010/08/06 fengjing cmcc test */
/* AC-OMA<->Account �Ʒ�ͳ����Ϣ�Ŷ��� */
#define EV_AC_OMA_GET_AC_ACCOUNTSTAT_REQ_MSG        ((UINT16)EV_OMA_BEGIN + 934)
#define EV_AC_OMA_GET_AC_ACCOUNTSTAT_RSP_MSG        ((UINT16)EV_OMA_BEGIN + 935)

/* 2010-12-08 fengjing add:AP Portalͳ����Ϣ */
#define EV_AC_OMA_GET_AC_APPORTALSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 936)
#define EV_AC_OMA_GET_AC_APPORTALSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 937)

#define EV_AC_OMA_GET_AC_APTRAFFIC_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 938)
#define EV_AC_OMA_GET_AC_APTRAFFIC_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 939)

#define EV_AC_OMA_GET_AC_APUSERSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 940)
#define EV_AC_OMA_GET_AC_APUSERSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 941)

/* 2011/10/25 ldm add */
#define EV_AC_OMA_GET_AC_MSSTAT_REQ_MSG       ((UINT16)EV_OMA_BEGIN + 942)
#define EV_AC_OMA_GET_AC_MSSTAT_RSP_MSG       ((UINT16)EV_OMA_BEGIN + 943)

/* add by gwx 2014-5-18 for ruijie ������Ϣһ���ռ�*/
#define EV_AC_OMA_GET_AC_RUNINFO_REQ_MSG	((UINT16)EV_OMA_BEGIN + 944)
#define EV_AC_OMA_GET_AC_RUNINFO_RSP_MSG	((UINT16)EV_OMA_BEGIN + 945)

/************************************ �澯 ************************************/
/* �澯״̬ */
#define AC_OMA_ALARM_STATUS_CLEAR           0		/* �澯��� */
#define AC_OMA_ALARM_STATUS_RAISE	        1		/* �澯���� */

/* �澯���� */
#define AC_OMA_ALARM_LEVEL_FATAL	        1		/* �����澯 */
#define AC_OMA_ALARM_LEVEL_MAIN		        2		/* ��Ҫ�澯 */
#define AC_OMA_ALARM_LEVEL_MINOR	        3		/* ��Ҫ�澯 */
#define AC_OMA_ALARM_LEVEL_WARNING          4		/* ����澯 */

/* �澯���� */
#define AC_OMA_ALARM_TYPE_COMMUNICATION  ((UINT32)1) /* ͨѶ�澯 */
#define AC_OMA_ALARM_TYPE_ENVIRONMENT    ((UINT32)2) /* �����澯 */
#define AC_OMA_ALARM_TYPE_DEVICE         ((UINT32)3) /* �豸�澯 */
#define AC_OMA_ALARM_TYPE_HANDLEFAIL     ((UINT32)4) /* �������澯 */
#define AC_OMA_ALARM_TYPE_QOS            ((UINT32)5) /* ���������澯 */
#define AC_OMA_ALARM_TYPE_SECURITY       ((UINT32)6) /* ��ȫ�澯 */
#define AC_OMA_ALARM_TYPE_OTHER          ((UINT32)0) /* �����澯 */

/* �澯ID�궨�� */
// 2009/04/25 �뾲 �޸ĸ澯��Ŀ
#define AC_OMA_ALARM_ID_WTP_OFFLINE      ((UINT32)10001)     /* AP���߸澯 */
#define AC_OMA_ALARM_ID_WTP_USEROVERLOAD ((UINT32)10002)     /* AP�û������ɹ��ظ澯 */

/* 2008/08/26 �뾲�����澯��Ŀ */
#define AC_OMA_ALARM_ID_AC_USEROVERLOAD     ((UINT32)10003)     /* AC�û������ɹ��ظ澯 */
#define AC_OMA_ALARM_ID_AC_CPUOVERLOAD      ((UINT32)10004)     /* AC CPU���ɹ��ظ澯 */
#define AC_OMA_ALARM_ID_AC_MEMOVERLOAD      ((UINT32)10005)     /* AC�ڴ������ʹ��߸澯 */
#define AC_OMA_ALARM_ID_MAUTHSRV_OFFLINE    ((UINT32)10006)     /* AC������3A��Ȩ���������� */
#define AC_OMA_ALARM_ID_MACCTSRV_OFFLINE    ((UINT32)10007)     /* AC������3A�Ʒѷ��������� */
#define AC_OMA_ALARM_ID_SAUTHSRV_OFFLINE    ((UINT32)10008)     /* AC�뱸��3A��Ȩ���������� */
#define AC_OMA_ALARM_ID_SACCTSRV_OFFLINE    ((UINT32)10009)     /* AC�뱸��3A�Ʒѷ��������� */
#define AC_OMA_ALARM_ID_ASSRV_OFFLINE       ((UINT32)10010)     /* AC��AS��Ȩ���������� */
#define AC_OMA_ALARM_ID_PORTALSRV_OFFLINE   ((UINT32)10011)     /* AC��Portal���������� */
#define AC_OMA_ALARM_ID_ENET_FAULT          ((UINT32)10012)     /* AC�������ӹ��� */
#define AC_OMA_ALARM_ID_CHANNEL_QUALITY_LOW	((UINT32)10013)	    /* AP�豸���߸��Ÿ澯 */
#define AC_OMA_ALARM_ID_DISKUSAGETOOHIGH    ((UINT32)10014)     /* ���������ʹ��� */
#define AC_OMA_ALARM_ID_TEMPERATURETOOHIGH  ((UINT32)10015)     /* �¶ȹ��� */
#define AC_OMA_ALARM_ID_CHANNELNUMLESS      ((UINT32)10016)     /* �ɹ�ʹ�õ��ŵ������͸澯 */

#define AC_OMA_ALARM_ID_DEVICE_INTERFERENCE_DETECT  ((UINT32)10020)  /* ���ָ��ŵ�ǰ�ŵ����豸 */
#define AC_OMA_ALARM_ID_SWVER_DIFF		((UINT32)10021)	/* 2010-1-22 N+1���ݹ�������:����汾��һ�¸澯*/

/* 2010-4-10 pyy ����*/
#define AC_OMA_ALARM_ID_POWEROFF					((UINT32)10029)	/* ��Դ����澯*/
#define AC_OMA_ALARM_ID_APDHCPADDRESSEXHAUST		((UINT32)10022)	/* AP��DHCP�ɷ����ַ�ľ��澯*/
#define AC_OMA_ALARM_ID_STADHCPADDRESSEXHAUST		((UINT32)10023)	/* STA��DHCP�ɷ����ַ�ľ��澯*/
#define AC_OMA_ALARM_ID_APINTERFDETECTED			((UINT32)10024)	/* �ڽ�AP���Ÿ澯 */
#define AC_OMA_ALARM_ID_ACCOLDREBOOT				((UINT32)10025)	/* AC ������*/
#define AC_OMA_ALARM_ID_ACWARMREBOOT				((UINT32)10026)	/* AC ������*/

/* 2010-06-30 fengjing cmcc ���� */
#define AC_OMA_ALARM_ID_APCOINTERFDETECTED          ((UINT32)10030)      /* APͬƵ���Ÿ澯 */
#define AC_OMA_ALARM_ID_APNERBORINTERFDETECTED      ((UINT32)10031)      /* AP��Ƶ���Ÿ澯 */

/* �澯ԭ��ID�궨�� */
/* WTP�����澯ԭ��궨�� */
#define AC_OMA_REASON_WTP_OFFLINE_NORECVDISC   ((UINT32)1)	/* û���յ��������� */
#define AC_OMA_REASON_WTP_OFFLINE_NORECVCONN   ((UINT32)2)  /* û���յ��������� */
#define AC_OMA_REASON_WTP_OFFLINE_AUTHFAIL     ((UINT32)3)  /* ���Ӽ�Ȩʧ�� */
/*2011-11-02 ldm add  */
#define AC_OMA_REASON_WTP_OFFLINE_REBOOT         ((UINT32)4)  /* AP���� */
#define AC_OMA_REASON_WTP_OFFLINE_OTHER        ((UINT32)100)  /* ����ԭ�� */

/* WTP���ɹ���ԭ��궨�� */
#define AC_OMA_REASON_WTP_USEROVERLOAD		((UINT32)0)	/* WTP���ɹ��� */

/* 2008/08/26 �뾲 ���������澯��Ŀ�ĸ澯ԭ���� */
/* AC�û������ɹ���ԭ��궨�� */
#define AC_OMA_REASON_AC_USEROVERLOAD       ((UINT32)0) /* AC�û������ɹ��� */

/* AC CPU���ɹ���ԭ��궨�� */
#define AC_OMA_REASON_AC_CPUOVERLOAD        ((UINT32)0) /* AC CPU���ɹ��� */

/* AC �ڴ渺�ɹ���ԭ��궨�� */
#define AC_OMA_REASON_AC_MEMOVERLOAD        ((UINT32)0) /* AC�ڴ渺�ɹ��� */

/* AC������3A��Ȩ����������ԭ��궨�� */
#define AC_OMA_REASON_MAUTHSRV_OFFLINE       ((UINT32)0) /* AC������3A��Ȩ���������� */

/* AC������3A�Ʒѷ���������ԭ��궨�� */
#define AC_OMA_REASON_MACCTSRV_OFFLINE       ((UINT32)0) /* AC������3A�Ʒѷ��������� */

/* AC�뱸��3A��Ȩ����������ԭ��궨�� */
#define AC_OMA_REASON_SAUTHSRV_OFFLINE       ((UINT32)0) /* AC�뱸��3A��Ȩ���������� */

/* AC�뱸��3A�Ʒѷ���������ԭ��궨�� */
#define AC_OMA_REASON_SACCTSRV_OFFLINE       ((UINT32)0) /* AC�뱸��3A�Ʒѷ��������� */

/* AC��AS����������ԭ��궨�� */
#define AC_OMA_REASON_ASSRV_OFFLINE         ((UINT32)0) /* AC��AS���������� */

/* AC��Portal����������ԭ��궨�� */
#define AC_OMA_REASON_PORTALSRV_OFFLINE     ((UINT32)0)  /* AC��Portal���������� */

/* AC�������ӹ���ԭ��궨�� */
#define AC_OMA_REASON_ENET_FAULT            ((UINT32)0)  /* AC�������ӹ��� */

/* AP�豸���߸��Ÿ澯ԭ��궨�� */
#define AC_OMA_REASON_CHANNEL_QUALITY_LOW_RSSI	((UINT32)0)	/* RSSI���� */

#define AC_OMA_REASON_DISKUSAGETOOHIGH      ((UINT32)0)     /* ���������ʹ��� */
#define AC_OMA_REASON_TEMPERATURETOOHIGH    ((UINT32)0)     /* �¶ȹ��� */

/* ���ָ��ŵ�ǰ�ŵ����豸�澯ԭ��궨�� */
#define AC_OMA_REASON_DEVICE_INTERFERENCE_DETECT_NOISE ((UINT32)0) /* ������� */

/* 2010-1-22 N+1���ݹ�������:����汾��һ�¸澯ԭ��궨��*/
#define AC_OMA_REASON_SWVER_DIFF	 	((UINT32)0)

#define AC_OMA_REASON_APDHCPADDRESSEXHAUST	((UINT32)0)	/* AP�� DHCP��Դ�ľ�*/
#define AC_OMA_REASON_STADHCPADDRESSEXHAUST	((UINT32)0)	/* STA�� DHCP��Դ�ľ�*/

/* AP�ϱ���AC�ĸ澯ID����:1000~5999֮�� */


/************************************ �¼� ************************************/
/* �¼�ID�궨�� */
#define AC_OMA_EVENT_ID_USER_ACCESS_DENY	       ((UINT32)20000)	/* �Ƿ��û�����ʧ���¼� */

/* 2008/08/26 �뾲 �����¼���Ŀ���� */
#define AC_OMA_EVENT_ID_WTP_ACCESS_DENY            ((UINT32)20001) /* �Ƿ�AP�����¼� */
#define AC_OMA_EVENT_ID_WTP_CURAC_CHANGE           ((UINT32)20002) /* AP��ǰѡ��AC�л��¼� */
#define AC_OMA_EVENT_ID_AC_REBOOT                  ((UINT32)20003) /* AC�����¼� */
#define AC_OMA_EVENT_ID_WTP_WIFIFREPOINT_RESELECT  ((UINT32)20004) /* ����ģ��Ƶ����ѡ�¼� */
#define AC_OMA_EVENT_ID_WTP_WIFIPOWER_ADJUST       ((UINT32)20005) /* ����ģ�鹦�ʵ����¼� */
#define AC_OMA_EVENT_ID_WTP_WIFIPOWER_COMPENSATION ((UINT32)20006) /* ����ģ�鹦�ʲ����¼� */
#define AC_OMA_EVENT_ID_DISTURB                    ((UINT32)20007) /* �豸�����¼� */

#define AC_OMA_EVENT_ID_AC_HEARTBEAT               ((UINT32)20100) /* AC�豸��OMC���������¼� */
#define AC_OMA_EVNET_ID_AC_SWITCH_MS               ((UINT32)20200) /* AC�����л� */
#define AC_OMA_EVENT_ID_AC_SNTP_FAIL               ((UINT32)20201) /* ACϵͳʱ��ͬ��ʧ���¼� */
#define AC_OMA_EVENT_ID_AC_IPCHANGE                ((UINT32)20202) /* AC�豸IP��ַ�仯�¼� */

#define AC_OMA_EVENT_ID_INVALIDCERTINBREAKNETWORK      ((UINT32)20300) /* �Ƿ�֤���û��������� */
#define AC_OMA_EVENT_ID_STATIONREPITIVE_ATTACK         ((UINT32)20301) /* �ͻ����طŹ��� */
#define AC_OMA_EVENT_ID_TAMPER_ATTACK                  ((UINT32)20302) /* �۸Ĺ��� */
#define AC_OMA_EVENT_ID_LOWSAFELEVEL_ATTACK            ((UINT32)20303) /* ��ȫ�ȼ����͹��� */
#define AC_OMA_EVENT_ID_ADDRESSREDIRECTION_ATTACK      ((UINT32)20304) /* ��ַ�ض��򹥻� */
/*2011-10-31 ldm add  */
#define AC_OMA_EVENT_ID_USERLOSTCONNECTION           ((UINT32)20350)       /* �û��쳣����ͨ�� */

/* 2010-4-10 pyy ����*/
#define AC_OMA_EVENT_ID_WTP_SECURITYMODECHANGE   		((UINT32)20400) /* AP���ܻ��Ʊ仯 */
#define AC_OMA_EVENT_ID_CONFIGURATIONERROR				((UINT32)20041)	/* ���ô����¼� */
#define AC_OMA_EVENT_ID_APACTIMESYNCFAILURE				((UINT32)20042)	/* AC��AP��ϵͳʱ��ͬ��ʧ���¼�*/
/* 2010-05-29 fengjing ���� */
#define AC_OMA_EVENT_ID_APMTWORKMODECHG  			    ((UINT32)20043)	/* AP���߼��ӹ���ģʽ����¼�*/
/* 2011-04-01 fengjing add */
#define AC_OMA_EVENT_ID_SSIDKEYCONFLICT                ((UINT32)20044) /* SSID��Կ��ͻ�¼� */

/* 2010-1-22 N+1���ݹ�������*/
#define AC_OMA_EVENT_ID_CFGDAT_GET_FAIL		((UINT32)20500)	/* ����AC������������ʧ��*/
#define AC_OMA_EVENT_ID_BAKACCHG_FAIL		((UINT32)20501)	/* �ӹ�ACʧ�� */

/* 2010-06-01 fengjing add */
#define AC_OMA_EVENT_ID_CFGUPDATE                     ((UINT32)20050) /* ��Ԫ���ø��� */
#define AC_OMA_EVENT_ID_SWDOWNLOAD                    ((UINT32)20051) /* �汾���سɹ� */
#define AC_OMA_EVENT_ID_SWUPDATE                      ((UINT32)20052) /* �汾���� */
#define AC_OMA_EVENT_ID_SWUPDATESUCCEED               ((UINT32)20053) /* �汾�ɹ����� */
#define AC_OMA_EVENT_ID_SWUPDATEFAIL                  ((UINT32)20054) /* �汾����ʧ�� */

/* �¼�ԭ��ID�궨�� */
/* �Ƿ��û�����ʧ��ԭ�� */
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

/* 2008/08/26 �뾲 �����¼���Ŀԭ��ID�궨�� */
/* �Ƿ�AP�����¼� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_INVALID_ID                	((UINT32)1)   /* AP�豸ID�Ƿ� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_INVALID_SECRET			((UINT32)2)   /* ����Ƿ� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_DIFF_DEVICETYPE          	((UINT32)3)    /* �豸���Ͳ�һ�� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_DIFF_DEVICESN             	((UINT32)4)    /* �豸SN��һ�� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_ALLOCATEID_FAIL			((UINT32)5)    /* �����豸IDʧ��*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAX_APNUM				((UINT32)6)	/* �Ѵﵽ���AP��*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_NOFREEASSO				((UINT32)7)	/* �޿��й���*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_REPEATSN				((UINT32)8)	/* SN �ظ�*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_REPEATIP				((UINT32)9)	/* IP��ַ�ظ�*/
#define AC_OMA_REASON_WTP_ACCESS_DENY_ILLEGAL_MAC_ADDR	  ((UINT32)10) /*AP MAC�Ƿ�*/

/* BEGIN: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */
#define AC_OMA_REASON_WTP_ACCESS_DENY_NOLICENSE				((UINT32)11)	/* ��license */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_APNUM		((UINT32)12)	/* �Ѵﵽlicense���AP�� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_STANUM		((UINT32)13)	/* �Ѵﵽlicense���STA�� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAXLICENSE_AUTHOR		((UINT32)14)	/* license�Ѿ����� */
#define AC_OMA_REASON_WTP_ACCESS_DENY_MAC		            ((UINT32)15)	/* ����key�е�mac��Χ�� */
/* END: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */

/* AP��ǰѡ��AC�л��¼�ԭ��ID�궨�� */
#define AC_OMA_REASON_WTP_CURAC_CHANGE                          ((UINT32)1)   /* AP��ǰѡ��AC�л� */

/* AC�����¼�ԭ��ID�궨�� */
#define AC_OMA_REASON_AC_REBOOT_HARDWARE                       ((UINT32)1)  /* Ӳ���� */
#define AC_OMA_REASON_AC_REBOOT_SOFTWARE                       ((UINT32)2)  /* ������ */
#define AC_OMA_REASON_AC_REBOOT_OHTER                          ((UINT32)3)  /* ����ԭ��*/

/* ����ģ��Ƶ����ѡ�¼�ԭ��ID�궨�� */
#define AC_OMA_REASON_WTP_WIFIFREPOINT_RESELECT                ((UINT32)1)  /* ����ģ��Ƶ����ѡ */

/* ����ģ�鹦�ʵ����¼�ԭ��ID�궨�� */
#define AC_OMA_REASON_WTP_WIFIPOWER_ADJUST                     ((UINT32)1)  /* ����ģ�鹦�ʵ��� */

/* ����ģ�鹦�ʲ����¼�ԭ��ID�궨�� */
#define AC_OMA_REASON_WTP_WIFIPOWER_COMPENSATION               ((UINT32)1)  /* ����ģ�鹦�ʲ��� */

/* �豸�����¼� ԭ��ID�궨��*/
#define AC_OMA_REASON_DISTURB_BY_NEIGHBOR                     ((UINT32)1)    /*�ھ�AP�����¼�*/
#define AC_OMA_REASON_DISTURB_BY_OTHER                        ((UINT32)2)    /*�����豸�����¼�*/

/* �����л�ԭ�� */
#define AC_OMA_REASON_AC_SWITCH_SLAVE_ACTIVE                  ((UINT32)1)    /* ����ת���� */
#define AC_OMA_REASON_AC_SWITCH_MASTER_ACTIVE                 ((UINT32)2)    /* �������� */

/* 2010-1-22 N+1���ݹ�������*/
/* ����AC������������ʧ���¼�ԭ���붨��*/
#define AC_OMA_REASON_CFGDAT_GET_FAIL	((UINT32)0)		/* ����AC������������ʧ��*/
/* �ӹ���ACʧ���¼�ԭ���붨��*/
#define AC_OMA_REASON_BAKACCHG_FAIL_NOOWNDAT 		((UINT32)1)	/* ���ݱ���Ŀ¼�²����ڱ�AC�����ļ� */
#define AC_OMA_REASON_BAKACCHG_FAIL_NOBAKACDAT 	((UINT32)2)	/* �����ļ�����Ŀ¼�²����ڱ��ӹ�AC�������ļ� */
#define AC_OMA_REASON_BAKACCHG_FAIL_DATMERGEFAIL 	((UINT32)3)	/* �����ļ��ϲ�ʧ�� */

/* AP�ϱ���AC���¼��붨��:6000~9999 */


/************************************ ���� ************************************/
/* ���ܼ������������������������ */
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

/* ����WTP���ܼ������鶨�� */
#define AC_OMA_PERF_WTP_FLOW_INDEX           ((UINT32)15)
#define AC_OMA_PERF_WTP_AP_INDEX             ((UINT32)16)
#define AC_OMA_PERF_WTP_ADHOC_INDEX          ((UINT32)17)

/* ����ͳ�Ƽ��������� */
/* VAPͳ�Ƽ������� */
#define AC_OMA_PERF_ID_BASE                  ((UINT32)30000)                       /* ���ܼ�������ID��ʼֵ */
#define AC_OMA_PERF_ID_VAP                   ((UINT32)AC_OMA_PERF_ID_BASE + 0)     /* VAP�û���ͳ�� */

/* 2008/08/26 �뾲 ��������ͳ�Ƽ��������� */
#define AC_OMA_PERF_ID_WTPUSER               ((UINT32)AC_OMA_PERF_ID_BASE + 1)     /* WTP�û���ͳ�� */

/* 2008/08/30 �뾲 ���� */
#define AC_OMA_PERF_ID_ACUSER                ((UINT32)AC_OMA_PERF_ID_BASE + 2)     /* AC�û���ͳ�� */

#define AC_OMA_PERF_ID_80211_AUTH            ((UINT32)AC_OMA_PERF_ID_BASE + 3)     /* 80211��Ȩͳ��(�ݲ�ʵ��) */
#define AC_OMA_PERF_ID_ASSOC                 ((UINT32)AC_OMA_PERF_ID_BASE + 4)     /* ����ͳ��(�ݲ�ʵ��) */
#define AC_OMA_PERF_ID_ACCESS_AC             ((UINT32)AC_OMA_PERF_ID_BASE + 5)     /* ����AC����ͳ�� */
#define AC_OMA_PERF_ID_8021X                 ((UINT32)AC_OMA_PERF_ID_BASE + 6)     /* 8021X��֤ͳ��(����ʵ��) */
#define AC_OMA_PERF_ID_PTK                   ((UINT32)AC_OMA_PERF_ID_BASE + 7)     /* WPA/PTKЭ��ͳ��(����ʵ��) */
#define AC_OMA_PERF_ID_WEB                   ((UINT32)AC_OMA_PERF_ID_BASE + 8)     /* WEB��֤�������ͳ��(�ݲ�ʵ��) */
#define AC_OMA_PERF_ID_VAPTIME               ((UINT32)AC_OMA_PERF_ID_BASE + 9)     /* VAP�û�����ʱ��ͳ�� */
#define AC_OMA_PERF_ID_WTPTIME               ((UINT32)AC_OMA_PERF_ID_BASE + 10)    /* WTP�û�����ʱ��ͳ�� */
#define AC_OMA_PERF_ID_ACTIME                ((UINT32)AC_OMA_PERF_ID_BASE + 11)    /* AC�û�����ʱ��ͳ�� */
#define AC_OMA_PERF_ID_VAPTRAFFIC            ((UINT32)AC_OMA_PERF_ID_BASE + 12)    /* VAP����ͳ�� */
#define AC_OMA_PERF_ID_WTPTRAFFIC            ((UINT32)AC_OMA_PERF_ID_BASE + 13)    /* WTP����ͳ�� */
#define AC_OMA_PERF_ID_ACTRAFFIC             ((UINT32)AC_OMA_PERF_ID_BASE + 14)    /* AC����ͳ�� */

/* �����������������Ŀ�궨�� */
#define AC_OMA_PERF_COUNTER_NUM_VAP          ((UINT32)3)   /* �û�����������û��뿪�����������û��� */
#define AC_OMA_PERF_COUNTER_NUM_WTPUSER      ((UINT32)3)   /* �û�����������û��뿪�����������û��� */
#define AC_OMA_PERF_COUNTER_NUM_ACUSER       ((UINT32)3)   /* �û�����������û��뿪�����������û��� */
#define AC_OMA_PERF_COUNTER_NUM_80211_AUTH   ((UINT32)3)   /* 80211��Ȩ�������ͳ�ơ�80211��Ȩ�ɹ�����ͳ�ơ�80211��Ȩʧ�ܴ���ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_ASSOC        ((UINT32)3)   /* �����������ͳ�ơ������ɹ�����ͳ�ơ�����ʧ�ܴ���ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_ACCESS_AC    ((UINT32)1)   /* ����AC����ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_8021X        ((UINT32)4)   /* 8021X��֤�������ͳ�ƣ�������������֤���󣩡�8021X��������֤�������ͳ�ƣ��ݲ�ʵ�֣���8021X��֤�ɹ�����ͳ�ơ�8021X��֤ʧ�ܴ���ͳ�ƣ��ݲ�ʵ�֣�*/
#define AC_OMA_PERF_COUNTER_NUM_PTK          ((UINT32)3)   /* WPA/PTKЭ���������ͳ�ơ�WPA/PTKЭ�̳ɹ�����ͳ�ơ�WPA/PTKЭ��ʧ�ܴ���ͳ�ƣ��ݲ�ʵ�֣� */
#define AC_OMA_PERF_COUNTER_NUM_WEB          ((UINT32)3)   /* WEB��֤�������ͳ�ơ�WEB��֤�ɹ�����ͳ�ơ�WEB��֤ʧ�ܴ���ͳ�ƣ��ݲ�ʵ�֣� */
#define AC_OMA_PERF_COUNTER_NUM_VAPTIME      ((UINT32)1)   /* ����ʱ��ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_WTPTIME      ((UINT32)1)   /* ����ʱ��ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_ACTIME       ((UINT32)1)   /* ����ʱ��ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_VAPTRAFFIC   ((UINT32)2)   /* ��������ͳ�ơ���������ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_WTPTRAFFIC   ((UINT32)2)   /* ��������ͳ�ơ���������ͳ�� */
#define AC_OMA_PERF_COUNTER_NUM_ACTRAFFIC    ((UINT32)2)   /* ��������ͳ�ơ���������ͳ�� */

/* 2008/09/11 �뾲���Ӹ��������������ϱ����ڵĶ��� */
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

/* ���Ӹ��������������״��ϱ��ӳ�ʱ��Ķ��� */
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

/* WTP�ϱ���AC�����ܼ�������ID���� */
#define AC_OMA_PERF_ID_WTP_FLOW             ((UINT32)1000)
#define AC_OMA_PERF_ID_WTP_AP               ((UINT32)2000)
#define AC_OMA_PERF_ID_WTP_ADHOC            ((UINT32)2001)

#define AC_OMA_PERF_COUNTER_NUM_WTP_FLOW     ((UINT32)6)
#define AC_OMA_PERF_COUNTER_NUM_WTP_AP       ((UINT32)9)
#define AC_OMA_PERF_COUNTER_NUM_WTP_ADHOC    ((UINT32)9)

/************************************ ��̬��Ϣ ************************************/
/* �û�����󳤶� */
/*2011-11-02 ldm modify  */
#define AC_OMA_USER_NAME_LEN_MAX	256

/* AC��Ԫ�����ļ�״̬ */
#define AC_OMA_DATFILE_STATE_NORMAL   ((UINT32)0)
#define AC_OMA_DATFILE_STATE_FAULT    ((UINT32)1)


/* ��̬��Ϣ�ϱ����� */
#define AC_OMA_DYNAINFO_TYPE_STATEUPDATE	((UINT32)1)	    /* ״̬��Ϣ�ϱ� */
#define AC_OMA_DYNAINFO_TYPE_USERADD	    	((UINT32)2)		/* �û����� */
#define AC_OMA_DYNAINFO_TYPE_USERDEL	    	((UINT32)3)		/* �û��뿪 */
#define AC_OMA_DYNAINFO_TYPE_USERPOS	    	((UINT32)4)		/* �û�λ����Ϣ���� */
#define AC_OMA_DYNAINFO_TYPE_DYNPOWER	    	((UINT32)5)		/* �����豸��ǰ���� */
#define AC_OMA_DYNAINFO_TYPE_APIP           		((UINT32)6)     /* AP��ǰ��IP��ַ */
#define AC_OMA_DYNAINFO_TYPE_ACIP			((UINT32)7)		/* AC��һ��IP��ַ*/
#define AC_OMA_DYNAINFO_TYPE_APSN			((UINT32)8)		/* AP���к�*/
#define AC_OMA_DYNAINFO_TYPE_APSWVER           	((UINT32)9)        /* AP��ǰ����汾��*/

/* AC���Ӷ�̬��Ϣ���� */
#define AC_OMA_DYNAINFO_TYPE_DEVICEABSTRACT  ((UINT32)10)
#define AC_OMA_DYNAINFO_TYPE_WTPACCESS       ((UINT32)11)
#define AC_OMA_DYNAINFO_TYPE_USERACCESS      ((UINT32)12)
#define AC_OMA_DYNAINFO_TYPE_DHCPALLOCATE    ((UINT32)13)
#define AC_OMA_DYNAINFO_TYPE_PORTALSTAT      ((UINT32)14)
#define AC_OMA_DYNAINFO_TYPE_WAPISTAT        ((UINT32)15)
#define AC_OMA_DYNAINFO_TYPE_IFSTAT          ((UINT32)16)
#define AC_OMA_DYNAINFO_TYPE_USERIPINFO      ((UINT32)17)

/* ���� */
#define AC_OMA_DYNAINFO_TYPE_VAPWIFISTAT      ((UINT32)18)
#define AC_OMA_DYNAINFO_TYPE_VAPUSERACCSTAT   ((UINT32)19)
#define AC_OMA_DYNAINFO_TYPE_ACIFWIFISTAT     ((UINT32)20)
#define AC_OMA_DYNAINFO_TYPE_SSIDWIFISTAT     ((UINT32)21)
#define AC_OMA_DYNAINFO_TYPE_DHCPSTAT        ((UINT32)22)  /* DHCPͳ��*/
#define AC_OMA_DYNAINFO_TYPE_PPPOESTAT       ((UINT32)23)  /* PPPOEͳ��*/
#define AC_OMA_DYNAINFO_TYPE_ACLSTAT         ((UINT32)24)  /* ACLͳ��*/

/* 2009-10-21 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_WTPUNREGISTER 		((UINT32)25) /* δע�᳢������AP��Ϣ */
/* 2010/05/15 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_ROAMINGSTAT     ((UINT32)26) /* ����ͳ�� */
/* 2010/08/06 fengjing cmcc test */
#define AC_OMA_DYNAINFO_TYPE_ACCOUNTSTAT     ((UINT32)27) /* �Ʒ�ͳ�� */

/* 2010-12-08 fengjing add:AP Portalͳ�� */
#define AC_OMA_DYNAINFO_TYPE_APPORTALSTAT    ((UINT32)28) /* AP Portalͳ�� */

/* 2009-09-07 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_MAXPOWER        		((UINT32)30)       /* �����豸����书�� */
#define AC_OMA_DYNAINFO_TYPE_VAPMAC          		((UINT32)31)       /* VAP MAC��ַ */
#define AC_OMA_DYNAINFO_TYPE_ADHOCMAC        		((UINT32)32)       /* ADHOC MAC��ַ */

/* 2010-1-19 ����*/
#define AC_OMA_DYNAINFO_TYPE_MSSTATE			((UINT32)33)		/* �����豸״̬*/

/* 2011-01-13 fengjing add */
#define AC_OMA_DYNAINFO_TYPE_APTRAFFIC	((UINT32)34)		/* AP����������ͳ����Ϣ */
#define AC_OMA_DYNAINFO_TYPE_APUSERSTAT	((UINT32)35)		/* AP�û�ͳ����Ϣ */

/* 2011-10-25 ldm add */
#define AC_OMA_DYNAINFO_TYPE_MSSTAT	 ((UINT32)37)		/* �����л�ͳ�� */

/* 2011-07-06 ymt add*/
#define AC_OMA_DYNAINFO_TYPE_APMAC	 ((UINT32)36)

/* add by gwx 2014-2-25 for task1265 */
#define AC_OMA_DYNAINFO_TYPE_PRODUCTTYPE	((UINT32)38)	/* AP��Ʒ�ͺ��ϱ�*/
/**************************** �ṹ���� ***************************/
#define AC_MAX_MEM_LEN                  ((UINT32)60*1024)

/* �����ϱ������Ŀ */
#define AC_OMA_QUEUE_BATCHNUM_MAX     50

/*2011-11-02 ldm modify  */
/* �û�����¼��ϱ���չ��Ϣ */
typedef struct
{
    CHAR	    acUserName[AC_OMA_USER_NAME_LEN_MAX];   /* �û��� */
   	UINT8	    aucMac[6];						        /* �û�MAC��ַ */
	UINT8	    aucRsv[2];						        /* ����ֽ� */
	UINT8	    aucIp[4];						        /* �û�IP��ַ */
}AC_OMA_EXT_INFO_USER_T;


typedef struct
{
	UINT32 ulChannel ;	/*Ƶ��*/
	UINT32 ulRssi ;		/*RSSI*/
	INT32 lNoise ;		/*����*/
}AC_OMA_EXT_INFO_RRM_T ;

/* AC������/AC��������չ��Ϣ*/
typedef struct
{
	UINT8	aucMac[6];		/* AC MAC��ַ */
	UINT8	aucRsv[2];
	UINT32	ulRebootTime;	/* AC������/������ʱ��*/
} AC_OMA_EXT_INFO_REBOOT_T;

/* APͬƵ���� */
typedef struct
{
     UINT8      aucMac[6];                  /*AP MAC*/
     UINT8      aucMacRsv[2];
     UINT32     ulChannel;                  /*AP Ƶ��*/
     UINT8      aucInterfBssid[6];          /*����AP BSSID*/
     UINT8      aucInterfBssidRsv[2];
}AC_OMA_EXT_INFO_COINTERF_T;

/* AP��Ƶ���� */
typedef struct
{
     UINT8      aucMac[6];               /*AP MAC*/
     UINT8      aucMacRsv[2];
     UINT32     ulApChannel;             /*AP Ƶ��*/
     UINT8      aucInterfBssid[6];       /*����AP BSSID*/
     UINT8      aucInterfBssidRsv[2];
     UINT32     ulInterfApChannel;       /*����APƵ��*/
}AC_OMA_EXT_INFO_NEIBORINTERF_T;

/* SSID��Կ��ͻ */
typedef struct
{   
	CHAR       szMySsid[36];   /*��'\0'��ֹ*/
    CHAR       szSsid[36];     /*��'\0'��ֹ*/

    UINT32     ulKeyIndex;
}AC_OMA_EXT_INFO_SSIDKEYCONFLICT;
/*2011-10-28 zoucaihong add*/
typedef struct
{
     UINT32   ulMsMode;     /* �л�ģʽ�� 1 ����ת����   2 �������� */
     UINT8    aucIp[4];      /* ԴAC�Ĺ���IP */
} AC_OMA_EXT_INFO_ACMS_T;


/* ��չ��Ϣ */
typedef union
{
	UINT32   	ulCommonInfo;           /* ����ԭ��ͨ����Ӧ��չ��ϢΪ�����������͵���� */

    AC_OMA_EXT_INFO_USER_T stUser;      /* �û���Ϣ */
	AC_OMA_EXT_INFO_RRM_T stRrm ;	    /*�տ�����*/

	/* 2010-5-29 fengjing add */
	AC_OMA_EXT_INFO_REBOOT_T stReboot;

	/* 2010/07/01 fengjing cmcc test */
	AC_OMA_EXT_INFO_COINTERF_T stCoInterf;
    AC_OMA_EXT_INFO_NEIBORINTERF_T stNeiborInterf;

	AC_OMA_EXT_INFO_SSIDKEYCONFLICT stKeyConflict;
	/*2011-10-27 zoucaihong add*/
	AC_OMA_EXT_INFO_ACMS_T		stAcMs;/*AC������Ϣ*/
/*2011-11-29 ldm modify  */
	CHAR        acExtInfo[200];
	UINT8       aucMac[6];
}AC_OMA_ALARM_EXT_INFO_U;

typedef AC_OMA_ALARM_EXT_INFO_U 	AC_OMA_EVENT_EXT_INFO_U;

/* Ӧ��ģ��澯�ϱ���Ϣ */
typedef struct
{
	UINT32	            ulAlarmId;				/* �澯ID */
//	UINT32	            ulAlarmStatus;			/* �澯״̬ */
	UINT32	            ulAlarmReasonId;		/* �澯ԭ��ID�� */
	UINT32	            ulAlarmLevel;			/* �澯���� */
    UINT32              ulMOC;                  /* �������� */
    UINT8               aucMOI[AC_MOI_LEN];     /* ����ʵ�� */

	UINT32              ulAlarmRaiseTime;		/* �澯����ʱ��(time()�����ķ���ֵ) */
	UINT32	            ulAlarmUptime;		    /* �ϵ絽�������¼���ʱ�䣬tickֵ���� */

	AC_OMA_ALARM_EXT_INFO_U    unAlarmExtInfo;	/* ��չ��Ϣ */
}AC_OMA_ALARM_INFO_T;

typedef struct
{
	UINT32	            ulAlarmId;				/* �澯ID */
    UINT32              ulMOC;                  /* �������� */
    UINT8               aucMOI[AC_MOI_LEN];     /* ����ʵ�� */

	UINT32              ulAlarmClearTime;		/* �澯���ʱ��(time()�����ķ���ֵ) */

	/* 2010/05/31 fengjing add */
	AC_OMA_ALARM_EXT_INFO_U    unAlarmExtInfo;	/* ��չ��Ϣ */
}AC_OMA_ALARM_CLEAR_INFO_T;

typedef struct
{
	UINT32              ulAlarmId;
    UINT32              ulMOC;
    UINT8               aucMOI[AC_MOI_LEN];
    UINT32	            ulAlarmStatus;					// �澯״̬
    UINT32	            ulAlarmChangeTime;				// �澯����/��������ʱ�䣨�ϲ���ʱ�䣩����λ����
    UINT32     	        ulAlarmSn;                      // �澯��ˮ��
    UINT32              ulAlarmClearTime;

	/* 2010-11-29 fengjing add */
    CHAR                acAlarmExtInfo[100];
	
}AC_OMC_ALARM_CLEAR_INFO_T;

/* Ӧ��ģ���¼��ϱ���Ϣ */
typedef struct
{
	UINT32              ulEventId;			 	/* �¼�ID */
	UINT32              ulEventReasonId;		/* �¼�ԭ��ID�� */
    UINT32              ulMOC;                  /* �������� */
    UINT8               aucMOI[AC_MOI_LEN];     /* ����ʵ�� */

	UINT32              ulEventRaiseTime;		/* �¼�����ʱ��(time()�����ķ���ֵ) */

	UINT32              ulEventUptime;			/* �ϵ絽�������¼���ʱ�䣬tickֵ���� */

	AC_OMA_EVENT_EXT_INFO_U unEventExtInfo;	    /* ��չ��Ϣ */
}AC_OMA_EVENT_INFO_T;

/* OMA���͸�Ӧ��ģ���������Ϣ */
typedef struct
{
	UINT32               ulPerfCounterGroupID; /* ���ܼ��������� */
}AC_OMA_REPORT_PERF_REQ_MSG_T;

/* �ϱ��������� */
typedef struct
{
    UINT32	     ulMOC;                      /* MOC */
    UINT8	     aucMOI[AC_MOI_LEN];         /* MOI */
    UINT32*      pulPerfCounterValue;        /* ������ֵ�б� */
}AC_OMA_PERF_OBJECT_T;

/* Ӧ��ģ��Ӧ��OMA�������ϱ����� */
typedef struct
{
    UINT32                       ulPerfCounterGroupID;  /* ��������ID */
    UINT32                       ulCounterNum;          /* ���������� */
    UINT32                       ulPerfObjectNum;       /* �����ϱ�������Ŀ */
    AC_OMA_PERF_OBJECT_T*        pstPerfCounterValue;   /* �ϱ����� */
}AC_OMA_REPORT_PERF_RSP_MSG_T;

/* OMA�ϱ���OMC�ļ�������ֵ��Ϣ */
typedef struct
{
	UINT32              ulMOC;
    UINT8               aucMOI[AC_MOI_LEN];
    UINT32              ulPerfCounterGroupID;                       /* ���ܼ��������� */
	UINT32              ulPerfReportTime;                           /* ���������ϱ�ʱ�� */
	UINT32              ulPerfReportInterval;                       /* ���������ϱ��������λ���� */
	UINT32              ulPerfCounterNum;                           /* ���ܼ��������� */
    UINT32              aulPerfCounterValues[MAX_PERFCOUNTER_NUM];	/* ������ͳ��ֵ�б� */
}AC_OMC_PERF_INFO_T;


/* OMA�ϱ���OMC��ͳ�Ƽ���������Ϣ */
typedef struct
{
    UINT32              ulNum;
    AC_OMC_PERF_INFO_T  astPerfInfo[AC_OMA_QUEUE_BATCHNUM_MAX];
}AC_OMC_REPORT_PERF_REQ_MSG_T;

/* AC�ϱ���OMC���������� */
//typedef AC_OMC_PERF_INFO_T AC_OMC_REPORT_PERF_REQ_MSG_T;

/* �����ϱ�Ӧ����Ϣ */
typedef struct
{
    UINT32           ulMOC;
    UINT8            aucMOI[AC_MOI_LEN];
    UINT32           ulPerfCounterGroupID;   	/* ��������� */
    UINT32           ulPerfReportTime;      	/* �ϱ�ʱ�� */
}AC_OMC_REPORT_PERF_RSP_MSG_T;

/* ACת������ȷ����Ϣ��WTP��Ԫ */
typedef struct
{
	CHAR             acObjectId[128];
    UINT32           ulPerfCounterGroupID;   	/* ��������� */
    UINT32           ulPerfReportTime;      	/* �ϱ�ʱ�� */
}AC_WTP_PERF_RSP_MSG_T;

/* �豸״̬���� */
typedef struct
{
	UINT32          ulMOC;
	UINT8           aucMOI[AC_MOI_LEN];
	UINT32	        ulAdminState;	        /* ����״̬ */
	UINT32	        ulOpState;		        /* ����״̬ */
    UINT32          ulCurAcId;              /* ��ǰ����AC��ԪID */
}AC_OMA_STATE_UPDATE_T;

typedef AC_OMA_STATE_UPDATE_T AC_OMA_REPORT_STATEUPDATE_REQ_MSG_T;

/* AC��Ԫ�����ļ�״̬���� */
typedef struct
{
    UINT32          ulDatFileState;             /* AC��Ԫ�����ļ�״̬ */
}AC_OMA_DATAFILE_STATE_UPDATE_T;

typedef AC_OMA_DATAFILE_STATE_UPDATE_T AC_OMA_REPORT_DATAFILE_STATEUPDATE_REQ_MSG_T;

/* �û�״̬���� */
typedef struct
{
	CHAR	acUserName[AC_OMA_USER_NAME_LEN_MAX];
	UINT32	ulWtpId;						/* �û������WTP�豸ID */
	UINT32	ulVDevId;						/* �û�����������豸ID */
	UINT32	ulVapId;						/* �û������VAP ID */
	UINT8	aucMac[6];						/* �û�MAC��ַ */
	UINT8	aucRsv[2];						/* ����ֽ� */
	UINT8	aucIp[4];						/* �û�IP��ַ */
	INT32	lPosX;							/* λ�ã�X���꣬������Ϣ-180��180  *10��5�η� */
	INT32	lPosY;							/* λ�ã�Y���꣬γ����Ϣ-90��90 *10��5�η�*/
}AC_OMA_USERINFO_T;

/* ����ģ�鵱ǰ���书�ʸ���*/
typedef struct
{
     UINT32             ulWtpId;           /* AP�豸ID */
     UINT32             ulWifiDeviceId;    /* �����豸ID */
     UINT32             ulDynPower;        /* ��ǰ���书�� */
}AC_OMA_DYNPOWER_UPDATE_T;

/* �ϱ�AP��ǰIP��ַ */
typedef struct
{
    UINT32	ulWtpId;   /* AP�豸ID */
    UINT32   ulIpOrigin;            /* 1:��̬����
                                       2:DHCP��̬����
                                       3:AC��̬����*/
	UINT8	aucIp[4];  /* AP�豸��ǰIP��ַ */
    UINT8    aucNetMask[4];         /* �������� */
    UINT8    aucDefaultGw[4];       /* �������� */
    UINT8    aucPrimaryDns[4];      /*��DNS������*/
    UINT8    aucSecondaryDns[4];    /*��DNS������*/
}AC_OMA_APDYNAIP_UPDATE_T;

/* �ϱ�AC�ĵ�һ��IP��ַ*/
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

/* �ϱ�AP��SN */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT8	aucSn[6];	      /* ���к�*/
	UINT8	aucRsv[2];          /* ����ֽ�*/
} AC_OMA_APSN_UPDATE_T;

/* �ϱ�AP��MAC��ַ */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT8	aucMac[6];	/* ���к�*/
	UINT8	aucRsv[2];   	/* ����ֽ�*/
} AC_OMA_APMAC_UPDATE_T;


/* �ϱ�AP�ĵ�ǰ����汾�� */
typedef struct
{
	UINT32   ulAcId;
	UINT32   ulWtpId;                /* AP ID */
	CHAR     acSwVersion[32];   /* ����汾*/
} AC_OMA_APSWVER_UPDATE_T;

/* ��̬��Ϣ�ϱ��ṹ */
/* �����豸����书�ʸ�����Ϣ�ṹ */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* �����豸ID */
     UINT32   ulMaxPower;        /* �����豸����书�� */
} AC_OMA_WIFIDEVICE_MAXPOWER_UPDATE_T;

/* VAP MAC��ַ������Ϣ�ṹ */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* �����豸ID */
     UINT32   ulVapId;           /* VAP ID */
     UINT8    aucMac[6];         /* MAC��ַ */
     UINT8    aucRsv[2];         /* ����ֽ� */
} AC_OMA_VAP_MAC_UPDATE_T;

/* ADHOC MAC��ַ������Ϣ�ṹ */
typedef struct 
{
     UINT32   ulAcId;
     UINT32   ulWtpId;           /* AP ID */
     UINT32   ulWifiDeviceId;    /* �����豸ID */
     UINT32   ulAdhocId;         /* ADHOC ID */
     UINT8    aucMac[6];         /* MAC��ַ */
     UINT8    aucRsv[2];         /* ����ֽ� */
} AC_OMA_ADHOC_MAC_UPDATE_T;

/* 2010-1-19 ����: �����豸����״̬������Ϣ�ṹ*/
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulPeerAcState1;	/*�����豸1״̬ */
	UINT32	ulPeerAcState2;	/*�����豸2״̬ */
	UINT32	ulPeerAcState3;	/*�����豸3״̬ */
	UINT32	ulCurBakAcId;	/* ��ǰ�ӹܵ�AC��ID */
}AC_OMA_MSSTATE_UPDATE_T;

/* ��Ԫ������Ϣ */
typedef struct
{
	UINT32  ulSn; /* start time */
	UINT32  ulMOC;
	UINT8   aucMOI[AC_MOI_LEN];
}AC_OMC_NESTART_T;

/* �ļ���������Ϣ */
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
    CHAR    acImVersion[32];  /* ��Ϣģ�Ͱ汾 */
    CHAR    acSwVersion[32];  /* ����汾 */
    UINT32  ulDeviceType;     /* �豸���� */
    UINT32  ulWtpId;          /* ��ԪID */
    UINT32  ulCfgVersion;     /* �������ݰ汾�� */
	UINT32 ulSysTime;
	UINT32 ulUpTime;
	UINT32 ulConnTime;
}AC_OMC_NEVERSION_T;

/* ��̬��Ϣ�ӿ��嶨�� */
#define AC_OMA_AC_ENETPORT_NUM_MAX      AC_ENETPORT_NUM_MAX
//#define AC_OMA_AC_WTP_NUM_MAX           ((UINT32)100)
//#define AC_OMA_AC_USER_NUM_MAX          ((UINT32)100)
//#define AC_OMA_AC_DHCPALLOCATE_NUM_MAX  ((UINT32)100)

#define AC_OMA_AC_WTPSTATE_IDLE     ((UINT32)0)
#define AC_OMA_AC_WTPSTATE_INITING  ((UINT32)1)
#define AC_OMA_AC_WTPSTATE_WORK     ((UINT32)2)

/* AC�豸��̫������Ϣ */
typedef AC_ENETPORT_INFO_T AC_OMA_AC_ENETPORT_INFO_T;

/* AC�豸ժҪ��Ϣ */
typedef struct
{
	CHAR     acAcDevName[32];      //�豸����
	CHAR	acAcNEId[32];		/* �豸����*/
	CHAR	acAcHostName[64];	/* �豸������*/
    CHAR     acAcDevType[32];      //�豸�ͺ�
    CHAR     acAcDevSN[6];         //�豸���кţ�λ�� /etc/gb
	UINT8    aucResv1[2];
	CHAR	acAcSwName[64];		/* �豸�������*/
    CHAR     acAcSwVersion[32];    //�豸����汾
    CHAR     acAcHwVersion[32];    //�豸Ӳ���汾
    CHAR     acAcCpuInfo[128];	   //CPU��Ϣ:CPU�ͺţ���Ƶ
    CHAR     acAcMemInfo[128];	   //�ڴ���Ϣ:RAM���ͣ�����
    	CHAR	acAcLocation[64];		/* �豸λ��*/
    CHAR     acAcManufacturer[128]; //�豸������ λ�� AC_HOME/c.dat
    CHAR     acAcSwDeveloper[128];  //���������
    UINT32  ulActive;	 /*   2011-8-24 pyy add ��ǰ����ģʽ: TRUE: ��ǰActive 		FALSE: ��ǰStandby */


	/* FIT-LAN�˿�IP��Ϣ*/
	UINT32	ulFitLanIpNum;			/* FIT-LAN�˿�IP��ַ��Ŀ */
	UINT8	aaucFitLanIp[8][4];		/* FIT-LAN�˿�IP��ַ*/
	UINT8	aaucFitLanMask[8][4];	/* FIT-LAN�˿���������*/
	UINT8	aucFitLanMac[6];			/* FIT-LAN�˿�MAC��ַ*/
	UINT8	aucRsv1[2];				/*	����ֽ�*/

	/* FAT-LAN�˿�IP��Ϣ*/
	UINT32	ulFatLanIpNum;			/*	FAT-LAN�˿�IP��ַ��Ŀ*/
	UINT8	aaucFatLanIp[32][4];		/*	FAT-LAN�˿�IP��ַ*/
	UINT8	aaucFatLanMask[32][4];	/*	FAT-LAN�˿���������*/
	UINT8	aucFatLanMac[6];		/*	FAT-LAN�˿�MAC��ַ*/
	UINT8	aucRsv2[2];				/*	����ֽ�*/

	/*����ΪL2-WAN�˿�IP��Ϣ		*/
	UINT32	ulL2WanIpNum;			/*	L2-WAN�˿�IP��ַ��Ŀ*/
	UINT8	aaucL2WanIp[8][4];		/*	L2-WAN�˿�IP��ַ*/
	UINT8	aaucL2WanMask[8][4];	/*	L2-WAN�˿���������*/
	UINT8	aucL2WanMac[6];		/*	L2-WAN�˿�MAC��ַ*/
	UINT8	aucRsv3[2];				/*	����ֽ�*/

	/* ����ΪL3-WAN�˿�IP��Ϣ*/
	UINT32	ulL3WanIpNum;			/*	L3-WAN�˿�IP��ַ��Ŀ*/
	UINT8	aaucL3WanIp[8][4];		/*	L3-WAN�˿�IP��ַ*/
	UINT8	aaucL3WanMask[8][4];	/*	L3-WAN�˿���������*/
	UINT8	aucL3WanMac[6];		/*	L3-WAN�˿�MAC��ַ*/
	UINT8	aucRsv4[2];				/*	����ֽ�*/
	UINT8	aucWanDftGw[4];			/*	ȱʡ����*/
	UINT8	aucDnsServer1[4];		/*	����DNS������*/
	UINT8	aucDnsServer2[4];		/*	����DNS������*/

	/*����Ϊ�豸���ж�̬��Ϣ*/
	UINT32   ulAcTime;		      //�豸ʱ��
	UINT32   ulAcUpTime;	      //�豸����ʱ��
    UINT32   ulAcMemoryTotal;     //�ڴ��ܴ�С
    UINT32   ulAcMemoryUsed;      //�ڴ�ʹ����
	UINT32   ulAcCpuLoad;         //CPUʹ����
	UINT32   ulAcDiskTotal;       //�ļ�ϵͳ����
	UINT32   ulAcDiskRemain;      //�ļ�ϵͳʣ��ռ�
	UINT32   ulAcTemperature;     //�豸�����¶�

	UINT32	ulAcRegWtpNum;		/* ע���AP��Ŀ*/
	UINT32   ulAcWtpNum;          //�����AP��Ŀ
	UINT32   ulAcStaNum;          //������û���Ŀ
	UINT32	ulAcPortalStaNum;		/* �����Portal��֤�û���*/
	UINT32	ulAcPPPoEStaNum;		/* �����PPPoE��֤�û���*/

    UINT32   ulUplinkStatus;      //0:���� 1:�Ͽ�

	/*����Ϊ�˿�״̬��Ϣ*/
	UINT32   ulEnetPortNum;		 //��̫���˿���Ŀ
	AC_OMA_AC_ENETPORT_INFO_T astEnetPort[AC_OMA_AC_ENETPORT_NUM_MAX];

	/* Ԥ���ֶ� */
	//UINT8    aucResv4[32];
}AC_OMA_AC_DEVICE_ABSTRACT_T;

/* AC�豸AP������Ϣ */
typedef struct
{
	UINT32  ulWtpId;      //AP�豸ID
	// 2009-10-21 new add
	UINT32   ulIpOrigin;   // AP IP���÷�ʽ  1����̬����
                                         //2��DHCP��̬����
	UINT8	aucWtpLocalIp[4];	/* AP �豸IP */
	UINT8	aucWtpIp[4];		/* AP ͨ��IP */
	UINT32	aucWtpPort;		/* ��ԽNAT ���Դ�˿ں� add by gwx 2013-4-7 fot task668*/
	UINT8	aucMac[6];		/* AP �豸MAC */
	UINT8	aucResv0[2];	/* ����ֽ�*/
	UINT32  ulWtpModel;   //AP�豸�ͺ�
	UINT8   aucWtpSn[6];  //AP�豸���к�
	UINT8	aucResv[2];
	// 2009-10-21 new add
	UINT32   ulDisType;    // AC���ַ�ʽ
                                          //0���Զ�
					      // 1��DHCP
					      //2��DNS
					      // 3���鲥

	// 2009-10-15 new add
	CHAR     acSwVersion[32];   //AP ��ǰ����汾��
	CHAR     acTargetVersion[32];   // AP�豸Ŀ������汾��
	UINT32  ulWtpState;   //AP�豸״̬
	                     /*
	                      * 0: ����
	                      * 1: ������
   	                      * 2: ����
					      */
	UINT32   ulRejectReason;    /* �ܾ�����ԭ�� */
			                                 /*
			                                 1:�豸ID��һ��
			                                 2:���벻һ��
			                                 3:�豸�ͺŲ�һ��
			                                 4:�豸���кŲ�һ��
			                                 */

	UINT32	ulAcLanId;	/* AC �˿�
					0-16����ʾLANx
					>=16������ʾN/A*/
					
	UINT32	ulVlanId;		/* 2009-12-25 pyy ����: ��ǰ�����VLAN ID */
    	UINT32  ulBeginTime;    	//��״̬��ʼʱ��
    	UINT32  ulStatePeriod;  	//��״̬����ʱ��

	UINT32  ulStaNum;       	//��ǰ�����û���
	UINT32	ulStaAccNum;	/* �û��������*/
    	UINT32  ulStaOnlineTime;    /* �û�������ʱ��, ��λ���� */

	UINT32	ulRegisterTime;			/*		ע��ʱ��	���״����ӵ�AC��ʱ��*/
	UINT32	ulLastConnTime;			/*		�ϴ�����ʱ�䣬���һ�ι���AC��ʱ��*/
	UINT32	ulLastVerUpdateTime;	/*		�ϴ������汾ʱ��	Oma֪ͨdbs*/
	UINT32	ulLastCfgUpdateTime;	/*		�ϴθ�������ʱ��	Oma֪ͨdbs */

	/* 2010-6-25 pyy ����*/
    CHAR        acCounty[64];           /* �豸�������� */
	CHAR	acLocation[64];	/*	�豸����λ��*/
	CHAR	acContact[64];	/*	�豸ά����ϵ��*/

	/* 2010-12-08 fengjing add */
	UINT32  ulLastOnlineTime;   /* ��Ӫ״̬AP�˷�ʱ��(����),���ߺ����ߵ�ʱ����Ӧ��ȥ���汾����ʱ�䣩 */
  	UINT32  ulTotalOnlineTime;  /* ��Ӫ״̬AP��ʱ��(����)��������ʱ����,�ۼ�ʱ�� */   

	/* add by gwx 2013-2-25 for task1265 */
	UINT32	ulWtpProductType; 	/* ��Ʒ����ID */

	/* add by gwx 2014-3-26 for APһ��ע��begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for APһ��ע��end*/
	CHAR	acCurChannelList[32];	/* add by gwx 2014-8-7 AP��ǰʹ���ŵ��б�*/
}AC_OMA_AC_WTP_INFO_T;

typedef struct
{
	UINT32  ulAcId;       //AC�豸ID
	UINT32  ulWtpNum;     //����AP��Ŀ
	AC_OMA_AC_WTP_INFO_T *pstWtpInfo;
}AC_OMA_AC_WTP_ACCESS_T;

/* 2009-10-21 fengjing add begin */
/* AC�豸���Խ���AP��Ϣ */
typedef  AC_OMA_AC_WTP_ACCESS_T AC_OMA_AC_WTP_UNREGISTER_T;
/* 2009-10-21 fengjing add end */

/* AC�豸�û�������Ϣ */
typedef struct
{
	UINT32   ulWtpId;       //AP�豸ID
	UINT32   ulWtpModel;    //AP�豸�ͺ�
	 UINT32  ulVdevId;       //�����豸���
	UINT32   ulVapId;       //VAP ID
	UINT32	ulAcLanId;	/* AC�˿�*/
	CHAR     acApSsid[32];  //VAP SSID
	UINT32   ulVapSecurity; //VAP ��֤����
	/*
	 * 1:Open System
	 * 2:Shared Key
	 * 3:WPA-PSK
	 * 4:WPA
	 * 5:MAC��֤
	 * 6:WAPI
	 */
	CHAR     acUserName[256]; //�û���
	UINT8    aucMac[6];      //MAC��ַ
	UINT8    aucRsv[2];      //����ֽ�
	UINT8    aucIp[4];       //IP��ַ
	UINT32   ulPriority;     //�û����ȼ�
	/*
	 * 0~7
	 * 0:���
	 * 7:���
	 */
	UINT32   ulUpBandMax;      //�û�������д���	��λ��Kbps
	UINT32   ulUpBandMin;      //�û���֤���д���	��λ��Kbps
	UINT32   ulDownBandMax;	   //�û�������д���	��λ��Kbps
	UINT32   ulDownBandMin;	   //�û���֤���д���	��λ��Kbps
	UINT32   ulCreateTime;	   //����ʱ���û�����ʱ��
	UINT32    ulCertStateOkTime;         /* add by gwx 2013-3-28 for task647 */
	UINT32	ulAuthType;		/* ��֤����: 0:����֤/1:Portal/2:PPPoE */
	UINT32   ulPortalState;    /*��֤״̬*/
	/*
	 * 0:δ��֤
	 * 1:����֤
	 */
	UINT32	ulPPPoEState;	/* PPPOE��֤״̬: 0/1 δ��֤/����֤*/
	UINT32	ulVlanId;		/*		��ǰ�����VLAN ID */
	CHAR	acNasId[256];	/*		NAS ID */
	UINT8	aucNasIp[4];		/*		NAS IP */
	UINT32	ulAcctInterimInterval;	/*		�Ʒ���Ϣ�ϱ����*/

	/* 2010-12-08 fengjing add WEB��֤�û�����ʱ�� */
	UINT32   ulOnlineTime;      /* WEB��֤�û�����ʱ������λ:�� */	
	/* add by gwx 2014-4-9 for bug5259 begin */
	UINT8	aucBssid[6];
	UINT8	aucBssidRsv[2];
	/* add by gwx 2014-4-9 for bug5259 end */
	/* add by gwx 2014-5-14 for ��ݣ�RSSI*/
	UINT32	ulUserRssi;
    /* BEGIN: Added by zoucaihong, 2014/9/10 */
    CHAR    acStaType[32];   /* �B���Ñ��K��֮�O����� */
    /* END: Added by zoucaihong, 2014/9/10 */
	/* add by gwx 2014-10-17 begin */
	CHAR 	acChannelName[32];	/* �û���ǰ���ڵ��ŵ�*/
	UINT32	ulWifiType;			/* ����Ŀ�����0:2.4G 1:5G */
	/* add by gwx 2014-10-17 end */
}AC_OMA_AC_USER_INFO_T;

typedef struct
{
	UINT32  ulAcId;            //AC�豸ID
	UINT32  ulUserNum;         //�����û���Ŀ
	AC_OMA_AC_USER_INFO_T *pstUserInfo;
}AC_OMA_AC_USER_ACCESS_T;


/* �ն��û�IP������Ϣ*/
typedef struct
{
	UINT32	ulAcId;
	UINT8	aucIp[4];		/* IP��ַ*/
	UINT8	aucMac[6];		/* ���һ�η��䵽���IP��ַ���ն˵�MAC��ַ*/
	UINT8	aucRsv[2];		/* ����ֽ�*/
	UINT32	ulWtpId;			/* ���һ�η��䵽���IP��ַ���ն˽����AP�豸ID */
	UINT32	ulVapId;			/* ���һ�η��䵽���IP��ַ���ն˽����VAP ID */
	CHAR	acVapSsid[32];
	UINT32	ulTime;			/* ���һ�����IP��ַ�������ʱ���*/
	UINT32	ulAcLanId;		/* AC �˿� 0~15 ��ʾLANx >=16 ����ʾN/A*/
} AC_OMA_AC_STAIP_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulIpNum;
	AC_OMA_AC_STAIP_INFO_T		*pstStaIpInfo;
} AC_OMA_AC_STAIP_ACCESS_T;

/* 2011-09-02 fengjing modify �����ֶ���UINT32->UINT64 */
typedef struct {
	UINT32	ulIfId;						/*		��̫����ID */
	UINT64	ulRecvFrameNum;			/*		����ࣨ���߲ࣩ�����ܵ�֡��*/
	UINT64	ulRecvBytes;				/*		����ࣨ���߲ࣩ�����ܵ��ֽ���*/
	UINT64	ulRecvUnicastFrameNum;		/*		����ࣨ���߲ࣩ���յĵ���֡��*/
	UINT64	ulRecvMulticastFrameNum;	/*		����ࣨ���߲ࣩ���յĶಥ֡��*/
	UINT64  ulRecvBroadcastFrameNum;    /* ����ࣨ���߲ࣩ���յĹ㲥֡�� */
	UINT32	ulRecvFailFrameNum;		/*		����ࣨ���߲ࣩ���մ����֡��*/
	UINT32	ulRecvDiscardFrameNum	;	/*		����ࣨ���߲ࣩ���ն�����֡��*/
	UINT32  ulRecvRetryFrameNum;		/* ����ࣨ���߲ࣩ�����ش���֡��*/
	UINT64	ulSendFrameNum;			/*		����ࣨ���߲ࣩ�����ܵ�֡��*/
	UINT64	ulSendBytes;				/*		����ࣨ���߲ࣩ�����ܵ��ֽ���*/
	UINT64	ulSendUnicastFrameNum;		/*		����ࣨ���߲ࣩ���͵ĵ���֡��*/
	UINT64	ulSendMulticastFrameNum;	/*		����ࣨ���߲ࣩ���͵Ķಥ֡��*/
	UINT64  ulSendBroadcastFrameNum;    /* ����ࣨ���߲ࣩ���͵Ĺ㲥֡��*/
	UINT32	ulSendFailFrameNum;		/*		����ࣨ���߲ࣩ���ʹ����֡��*/
	UINT32	ulSendDiscardFrameNum;		/*		����ࣨ���߲ࣩ���Ͷ�����֡��*/
	UINT32  ulSendRetryFrameNum;        /* ����ࣨ���߲ࣩ�����ش���֡��*/
	UINT32  ulDownNum;                  /* ��̫���ڽ��ô��� */
	UINT32  ulUpNum;	                /* ��̫�������ô��� */
} AC_OMA_AC_IF_INFO_T;

typedef struct
{
	UINT32  ulAcId;            	//AC�豸ID
	UINT32  ulIfNum;         	//��̫������Ŀ
	AC_OMA_AC_IF_INFO_T *pstIfInfo;
}AC_OMA_AC_IFSTAT_T;

/* DHCPͳ����Ϣ*/
typedef struct
{
	UINT32	ulType;	/*		DHCP��ַ�����ͣ�
					0���û���DHCP��ַ��
					1��AP��DHCP��ַ��*/
	UINT32	ulId;			/*	��ַ�ر��*/
	UINT32	ulTotalIpNum;	/*		�ܵ�IP��Ŀ*/
	UINT32	ulFreeIpNum;	/*		����IP����Ŀ*/
	UINT32	ulUsePercent;	/*		DHCP��ַ��������*/
	UINT32	ulDhcpReqNum;	/*		DHCP�������*/
	UINT32	ulDhcpSuccNum;	/*		DHCP����ɹ�����*/    

	/* 2011-04-15 fengjing add */
	UINT32 ulDhcpDiscoverNum; /* DHCP discover ���մ��� */
	UINT32 ulDhcpOfferNum;      /* DHCP offer���ʹ���*/

	/* 2011-09-22 fengjing add */
	UINT32 ulDhcpPoolPeakUsage;  /* DHCP��ַ�ط�ֵ������ */
} AC_OMA_AC_DHCP_STAT_INFO_T;

typedef struct
{
	UINT32 	ulAcId;             //AC�豸ID
	UINT32	ulPoolNum;	/* ��ַ����Ŀ*/
	AC_OMA_AC_DHCP_STAT_INFO_T	*pstDhcpStat;
} AC_OMA_AC_DHCP_STAT_T;

/* */
typedef struct
{
	UINT8  aucIP[4];      //�����IP��ַ
	UINT8  aucMask[4];    //�������������
	UINT8  ulMacAddr[6];  //�û�MAC��ַ
	UINT8  aucResv[2];    //����ֽ�
	UINT32	ulVlanId;
	UINT32 ulHostType;    //�û�����
	/*
	 * 0:AP
	 * 1:STA
	 */
	CHAR   acHostName[32];  //Client�Ϸ����û���������,����Ϊ��
	time_t stStartTime;     //��Լ��ʼʱ��	UTCʱ��
	time_t stEndTime;       //��Լ����ʱ��	UTCʱ��
}AC_OMA_AC_DHCP_ALLOCATE_INFO_T;

/* AC�豸DHCP��ַ������Ϣ */
typedef struct
{
	UINT32 	ulAcId;             //AC�豸ID
	UINT32  ulDhcpAllocateNum;
	AC_OMA_AC_DHCP_ALLOCATE_INFO_T *pstDhcpAllocate;
}AC_OMA_AC_DHCP_ALLOCATE_T;

/* AC�豸Portalͳ����Ϣ */
typedef struct
{
	UINT32 ulAcId;             //AC�豸ID
	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalAuthTime;         /*Portal��֤�ն˼�Ȩ����*/
	UINT32 ulAssociateAuthTime;         /*������֤�ն˼�Ȩ����*/
	UINT32 ulMacAuthTime;         /*MAC��֤�ն˼�Ȩ����*/
    	UINT32 ulPortalAuthFailTime;     /*Portal��֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulAssociateAuthFailTime;     /*������֤�ն˼�Ȩʧ�ܴ���*/
	UINT32 ulMacAuthFailTime;     /*MAC��֤�ն˼�Ȩʧ�ܴ���*/
    	UINT32 ulPortalAuthSuccNum;	    /*Portal��֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulAssociateAuthSuccNum;	    /*������֤�ն˼�Ȩ�ɹ�����*/
	UINT32 ulMacAuthSuccNum;	    /*MAC��֤�ն˼�Ȩ�ɹ�����*/

	UINT32 ulAuthRejectNum;     //�ն˼�Ȩ�ܾ�����
	UINT32 ulAuthTryNum;        //�ն˼�Ȩ���Դ���
	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalOnlineUserNum;    /*��ǰͨ��WEB��֤�������û���*/
	UINT32 ulFreeOnlineUserNum;    /*��ǰͨ������֤�������û���*/
	UINT32 ulAssociateOnlineUserNum;    /*��ǰͨ��������֤�������û���*/
	UINT32 ulMacOnlineUserNum;    /*��ǰͨ��MAC��֤�������û���*/
	
    	UINT32 ulLogoutUserNum;    //�û������ǳ�����
    	UINT32 ulTimeoutUserNum;   //�û�SessionTimeout���ߴ���
    	/*2011-10-28 zoucaihong modify*/
    	UINT32 ulPortalOfflineUserNum;   /*Portal��֤�û��쳣���ߴ���*/
	UINT32 ulFreeOfflineUserNum;   /*����֤�û��쳣���ߴ���*/
	UINT32 ulAssociateOfflineUserNum;   /*������֤�û��쳣���ߴ���*/
	UINT32 ulMacOfflineUserNum;   /*MAC��֤�û��쳣���ߴ���*/

    	UINT32 ulPortalServerNum;   /* AC���ӵ�Portal�������� */

	// 2010/06/29 fengjing cmcc test	
	UINT32 ulPortalAuthReqCount;       /* AC�յ�Portal�������ļ�Ȩ������ */
	UINT32 ulPortalChallengeReqCount;  /* AC�յ�Portal��������Challenge������ */
	UINT32 ulPortalAuthRespCount;      /* AC��ӦPortal��������Ȩ����Ĵ��� */
	UINT32 ulPortalChallengeRespCount; /* AC��ӦPortal������Challenge����Ĵ��� */	
	
	UINT32 ulPortalAuthRespErr0;     /* AC��portal���ظ�errcode=0�Ĵ��� */
	UINT32 ulPortalAuthRespErr1;     /* AC��portal���ظ�errcode=1�Ĵ��� */
	UINT32 ulPortalAuthRespErr2;     /* AC��portal���ظ�errcode=2�Ĵ��� */
	UINT32 ulPortalAuthRespErr3;     /* AC��portal���ظ�errcode=3�Ĵ��� */
	UINT32 ulPortalAuthRespErr4;     /* AC��portal���ظ�errcode=4�Ĵ��� */

	// 2010/07/30 fengjing cmcc KPI
	UINT32 ulChallengeTimeoutCount;    /* Challenge��ʱ���� */
	UINT32 ulChallengeBusyCount;       /* ChallengeACæµ���� */
	UINT32 ulChallengeDenyCount;       /* Challenge�ܾ����� */
	UINT32 ulUserPwdErrCount;          /* �û�������Ϣȱʧ���� */
	UINT32 ulUnknownErrCount;          /* δ֪���ʹ������ */
	UINT32 ulAuthTimeoutCount;         /* ��Ȩ��ʱ���� */
	UINT32 ulAuthBusyCount;            /* ��ȨACæµ���� */
	UINT32 ulAuthDisorderSeqCount;     /* ��Ȩ������������ */	

	/* 2010/08/06 fengjing cmcc test */
	UINT32 ulRadiusOfflineReqCount;   /* AC��⵽�û�����,���͸�Portal������������������� */
	UINT32 ulRadiusOfflineRespCount;  /* AC�յ�Portal��������������Ӧ����*/	

	/* 2010-12-08 fengjing add ������ز��� */
	UINT32 ulOfflineReqCount;   /* �û�������������: Portal���������͸�AC������֪ͨ����*/
	UINT32 ulOfflineSuccCount; /* �û�������������: Portal���������͸�AC���û����߳ɹ�֪ͨ����*/
	UINT32 ulOfflineFailCount;   /* �û�������������: Portal���������͸�AC���û�����ʧ��֪ͨ����*/
}AC_OMA_AC_PORTAL_STAT_T;

/* VAP Portalͳ����Ϣ */
typedef struct
{
   UINT32 ulAcId;          //AC ID
   UINT32 ulWtpId;         //WTP ID
   UINT32 ulVapId;         //VAP ID
   CHAR   acApSsid[32];    //VAP SSID           
	/*2011-10-28 zoucaihong modify*/
    UINT32 ulPortalOnlineUserNum;    /*��ǰͨ��WEB��֤�������û���*/
	UINT32 ulFreeOnlineUserNum;    /*��ǰ����֤�������û���*/
	UINT32 ulAssociateOnlineUserNum;    /*��ǰͨ��������֤�������û���*/
	UINT32 ulMacOnlineUserNum;    /*��ǰͨ��MAC��֤�������û���*/
    UINT32 ulPortalOfflineUserNum;   /*Portal��֤�û��쳣���ߴ���*/
	UINT32 ulFreeOfflineUserNum;   /*����֤�û��쳣���ߴ���*/
	UINT32 ulAssociateOfflineUserNum;   /*������֤�û��쳣���ߴ���*/
	UINT32 ulMacOfflineUserNum;   /*MAC��֤�û��쳣���ߴ���*/
    UINT32 ulPortalAuthReq;          /*Portal��֤������*/
	UINT32 ulAssociateAuthReq;          /*������֤������*/
	UINT32 ulMacAuthReq;          /*MAC��֤������*/
    UINT32 ulPortalAuthSucc;         /*Portal��֤�ɹ���*/
	UINT32 ulAssociateAuthSucc;         /*������֤�ɹ���*/
	UINT32 ulMacAuthSucc;         /*MAC��֤�ɹ���*/
	/*2011-10-31 zoucaihong add*/
	UINT32 ulPortalAuthFail;         /*Portal��֤ʧ����*/
	UINT32 ulAssociateAuthFail;         /*������֤ʧ����*/
	UINT32 ulMacAuthFail;         /*MAC��֤ʧ����*/
	/*2011-10-28 zoucaihong add*/
	UINT32 ulPortalTotalOnlineTime;  /*Portal��֤�û�������ʱ��*/
	UINT32 ulFreeTotalOnlineTime;  /*����֤�û�������ʱ��*/
	UINT32 ulAssociateTotalOnlineTime;  /*������֤�û�������ʱ��*/
	UINT32 ulMacTotalOnlineTime;  /*MAC��֤�û�������ʱ��*/
	
}AC_OMA_AP_VAP_PORTAL_STAT_T;
 

/* AP�豸Portalͳ����Ϣ */
typedef struct
{
   UINT32 ulValidNum;         //
   AC_OMA_AP_VAP_PORTAL_STAT_T *pstApPortalStat;
}AC_OMA_AP_PORTAL_STAT_T;

/* AC�豸PPPOE��֤ͳ����Ϣ*/
typedef struct
{
	UINT32	ulAcId;

	UINT32	ulMaxPPPoEOnlineUsers;		/*		�������ͬʱ�����û���*/
	UINT32	ulPPPoEOnlineUsers;			/*	��ǰͬʱ�����û���*/
	UINT32	ulInactivityTimeOutNum;		/*	�û����г�ʱ���ж����ӵĴ���*/
	UINT32	ulUserInitTermNum;			/*		�û������ж����ӵĴ���*/
	UINT32	ulRxEthDiscoveryNum;		/*		���յ���ETH-DISCOVERY֡��Ŀ*/
	UINT32	ulRxEthSessionNum;			/*	���յ���ETH-SESSION֡��Ŀ*/
	UINT32	ulRxErrCodeNum;			/*		���յ��ı���CODE����֡��Ŀ*/
	UINT32	ulRxErrVerNum;				/*	���յ��ı���Version����֡��Ŀ*/
	UINT32	ulRxErrLengthNum;				/*		���յ��ı��ĳ��ȴ���֡��Ŀ*/
} AC_OMA_AC_PPPOE_STAT_T;

/* ACLͳ����Ϣ*/
typedef struct
{
	UINT32	ulAcId;

	UINT32	ulAclNum;		/*		ACL������Ŀ��*/
	UINT32	ulDropPktNum;	/*		ACL������������*/
	UINT32	ulAcceptPktNum;	/*		ACLͨ����������*/
	UINT32	ulMarkPktNum;	/*		ACL��Ǳ�������*/
	UINT32	ulTcpPktNum;	/*		ACL��ʽ�����TCP��������*/
	UINT32	ulTcpDropNum;	/*		TCP���Ķ�������*/
	UINT32	ulTcpAcceptNum;	/*		TCP����ͨ������*/
	UINT32	ulTcpMarkNum;	/*		TCP����������������*/
	UINT32	ulUdpPktNum;	/*		ACL��ʽ�����UDP��������*/
	UINT32	ulUdpDropNum;	/*		UDP���Ķ�������*/
	UINT32	ulUdpAcceptNum;	/*		UDP����ͨ������*/
	UINT32	ulUdpMarkNum;		/*	UDP����������������*/
	UINT32	ulIcmpPktNum;		/*		ACL��ʽ�����ICMP��������*/
	UINT32	ulIcmpDropNum;		/*		ICMP���Ķ�������*/
	UINT32	ulIcmpAcceptNum;	/*		ICMP����ͨ������*/
	UINT32	ulIcmpMarkrNum;		/*		ICMP����������������*/
} AC_OMA_AC_ACL_STAT_T;

/*2011-11-02 ldm add  */
/* �����л�ͳ����Ϣ*/
typedef struct
{
	UINT32	ulAcId;
	
	UINT32 ulMsChgNum;  /* �����л����� */
} AC_OMA_AC_MS_STAT_T;



/* WAPI��Ϣ */
typedef struct
{
	UINT32 ulUserStatus;        //�û�״̬
    UINT8  aucUserMacAddr[6];   //�û�MAC��ַ
    UINT8  aucResv[2];	        //����ֽ�
    UINT8  aucUserIpAddr[4];    //�û�IP��ַ
    UINT32 ulUserAuthState;     //�û���Ȩ״̬
	/*
	 * 0:δ��Ȩ
	 * 1:�Ѽ�Ȩ
	 */
	UINT32 ulUserUniCipher;					//���������׼�	1��SMS4
	UINT32 ulUserReplayCounter;				//���طŻ��ƶ����ı�����
	UINT32 ulUserDecryptErrors;				//���ܴ������ı�����
	UINT32 ulUserMicErrors;					//У��������ı�����
	UINT32 ulUserWaiSignError;				//WAI��Ϣǩ���������
	UINT32 ulUserWaiMacError;				//WAI��ϢУ��������
	UINT32 ulUserWaiFailure;				//WAI����ʧ�ܴ���
	UINT32 ulUserWaiDiscard;				//WAI��Ϣ������Ŀ
	UINT32 ulUserWaiTimeout;				//WAI��ʱ����
	UINT32 ulUserWaiFormatError;			//WAI��Ϣ��ʽ�������
	UINT32 ulUserWaiCertHandshakeFailure;   //WAI֤������ʧ�ܴ���
	UINT32 ulUserWaiUniHandshakeFailure;    //WAI������ԿЭ��ʧ�ܴ���
	UINT32 ulUserWaiMultiHandshakeFailure;  //WAI�鲥��Կͨ��ʧ�ܴ���
}AC_OMA_AC_USER_WAPI_STAT_T;

typedef struct
{
	UINT32 ulAcId;          //AC ID
	UINT32 ulWtpId;         //WTP ID
	UINT32 ulVapId;         //VAP ID
	CHAR   acApSsid[32];    //VAP SSID
	UINT32 ulUniKeyNum;     //��󵥲���Կ��Ŀ
	UINT32 ulMultiKeySize;  //�ಥ���볤��
	UINT32 ulAuthCipherSel; //���һ��ѡ��ļ�Ȩ�׼�
	/*
	 * 1:֤��
	 * 2:Ԥ������Կ
	 */
	UINT32 ulUniCipherSel;   //���һ��ѡ��ĵ��������׼�	1:SMS4
	UINT32 ulMultiCipherSel; //���һ��ѡ��Ķಥ�����׼�	1:SMS4
	UINT8  aucLastBKID[16];  //���һ��ʹ�õ�BKID
	UINT32 ulAuthCipherReq;  //���һ������ļ�Ȩ�׼�
	/*
	 * 1:֤��
	 * 2:Ԥ������Կ
	 */
	UINT32 ulUniCipherReq;   //���һ������ĵ��������׼�	1:SMS4
	UINT32 ulMultiCipherReq; //���һ������Ķಥ�����׼�	1:SMS4

	UINT32 ulValidUserNum;   //��Ч�û���Ŀ	������Ҫ��ʾÿ��VAP�ϵ��û���Ŀ��
	AC_OMA_AC_USER_WAPI_STAT_T *pstUserWapiStat;
}AC_OMA_AC_VAP_WAPI_STAT_T;

/*typedef struct  
{
	UINT32 ulWtpId;            //AP�豸ID
    UINT32 ulVapNum;           //Wapi vap����Ŀ
	AC_OMA_AC_VAP_WAPI_STAT_T *pstVapWapiStat;
}AC_OMA_AC_AP_WAPI_STAT_T;
*/

/* AC�豸WAPIͳ����Ϣ */
typedef struct
{
	//UINT32 ulAcId;             //AC�豸ID
    UINT32 ulValidNum;         //
	AC_OMA_AC_VAP_WAPI_STAT_T *pstApWapiStat;
}AC_OMA_AC_WAPI_STAT_T;

typedef struct
{
	UINT32   ulWtpId;       //AP�豸ID
	UINT32   ulVapId;       //VAP ID
	CHAR     acApSsid[32];  //VAP SSID

	UINT32	ulAcLanId;		/* AP�����ӵ�AC�ӿ�*/

	UINT32	ulUpByte;				/*	����������*/
	UINT32	ulDownByte;				/*	����������*/
	UINT32	ulUpFrame;				/*	������֡��*/
	UINT32	ulUpErrFrame;			/*	���д���֡��*/
	UINT32	ulUpDiscardFrame;		/*	���ж�֡��*/
	UINT32	ulUpRetransFrame;		/*	�����ش�֡��*/
	UINT32	ulDownFrame;			/*	������֡��*/
	UINT32	ulDownErrFrame;			/*	���д���֡��*/
	UINT32	ulDownDiscardFrame;	/*	���ж�֡��*/
	UINT32	ulDownRetransFrame;	/*	�����ش�֡��*/
	UINT32	ulUpAssoFrame;			/* ���й���֡��*/
	UINT32	ulDownAssoFrame;		/* ���й���֡��*/
} AC_OMA_ACVAPWIFISTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulVapNum;
	AC_OMA_ACVAPWIFISTAT_INFO_T	*pstVapWifiStat;
} AC_OMA_ACVAPWIFISTAT_T;

typedef struct
{
	UINT32   ulWtpId;       //AP�豸ID
	UINT32   ulVapId;       //VAP ID
	CHAR     acApSsid[32];  //VAP SSID

	UINT32	ulAcLanId;		/* AP�����ӵ�AC�ӿ�*/

	UINT32	ulAccessTimes;		/*	AP�������û����Ӵ���*/
	UINT32	ulAccessFailTimes;	/*	AP�������û�����ʧ�ܴ���*/
	UINT32	ulAccessRetryTimes;	/*	AP�������û������Ӵ���*/
	UINT32	ulAccessDenyTimes;	/*	AP�������û����Ӿܾ�����*/
	UINT32	ulAccessOutTimes1;	/*	���û��뿪�����½�����Ĵ���*/
	UINT32	ulAccessOutTimes2;	/*	��AP������������½�����Ĵ���*/
	UINT32	ulAccessOutTimes3;	/*	���쳣��������½�����Ĵ���*/
	UINT32	ulAccessOutTimes4;	/*	����ԭ���½�����Ĵ���*/
} AC_OMA_ACVAPUSERACCSTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulVapNum;
	AC_OMA_ACVAPUSERACCSTAT_INFO_T	*pstVapUserAccStat;
} AC_OMA_ACVAPUSERACCSTAT_T;

typedef struct
{
	UINT32	ulAcLanId;		/* AP�����ӵ�AC�ӿ�*/

	UINT32	ulUpByte;				/*	����������*/
	UINT32	ulDownByte;				/*	����������*/
	UINT32	ulUpFrame;				/*	������֡��*/
	UINT32	ulUpErrFrame;			/*	���д���֡��*/
	UINT32	ulUpDiscardFrame;		/*	���ж�֡��*/
	UINT32	ulUpRetransFrame;		/*	�����ش�֡��*/
	UINT32	ulDownFrame;			/*	������֡��*/
	UINT32	ulDownErrFrame;			/*	���д���֡��*/
	UINT32	ulDownDiscardFrame;	/*	���ж�֡��*/
	UINT32	ulDownRetransFrame;	/*	�����ش�֡��*/
	UINT32	ulUpAssoFrame;			/* ���й���֡��*/
	UINT32	ulDownAssoFrame;		/* ���й���֡��*/
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
	UINT64	ulUpByte;				/*	����������*/
	UINT64	ulDownByte;				/*	����������*/
	UINT32	ulUpFrame;				/*	������֡��*/
	UINT32	ulUpErrFrame;			/*	���д���֡��*/
	UINT32	ulUpDiscardFrame;		/*	���ж�֡��*/
	UINT32	ulUpRetransFrame;		/*	�����ش�֡��*/
	UINT32	ulDownFrame;			/*	������֡��*/
	UINT32	ulDownErrFrame;			/*	���д���֡��*/
	UINT32	ulDownDiscardFrame;	/*	���ж�֡��*/
	UINT32	ulDownRetransFrame;	/*	�����ش�֡��*/
	UINT32	ulUpAssoFrame;			/* ���й���֡��*/
	UINT32	ulDownAssoFrame;		/* ���й���֡��*/
} AC_OMA_ACSSIDWIFISTAT_INFO_T;

typedef struct
{
	UINT32	ulAcId;
	UINT32	ulSsidNum;
	AC_OMA_ACSSIDWIFISTAT_INFO_T	*pstSsidWifiStat;
} AC_OMA_ACSSIDWIFISTAT_T;

/* ����ͳ�� */
typedef struct
{
	UINT32 ulAcId;
	UINT32 ulInAcRoamingSuccTimes;  /* ͬ���������ն����γɹ��Ĵ��� */
	UINT32 ulAcRoamingIn;           /* ��������ն�����ת��ɹ��Ĵ��� */
	UINT32 ulAcRoamingOut;          /* ��������ն�����ת���ɹ��Ĵ��� */

	UINT32 ulRadiusAuthReq;         /* AC����Radius����֤������� */
	UINT32 ulRadiusAuthResp;        /* AC�յ�Radius����֤������Ӧ���� */
	
	/* 2010/08/06 fengjing cmcc test */
	/* ��Ӧ��֤����������֤�ɹ��� */
	UINT32 ulRadiusAuthReq2;        /*AC����RADIUS����֤����*/
	UINT32 ulRadiusAuthSucc;        /* AC�յ�Radius����֤����ͨ������ */

	/* 2011-04-06 fengjing add:�㽭�ƶ����� */
	UINT32 ulRadiusAuthReject;             /*AC�յ�Radius����֤�ܾ�����*/
       UINT32 ulRadiusAuthReqFailed;      /*AC���͵�RADIUS��֤����ʧ�ܴ���*/
}AC_OMA_HOSTAPDSTAT_T;

/* �Ʒ�ͳ�� */
typedef struct
{
	UINT32 ulAcId;
	UINT32 ulAccountReq;      /* �Ʒ������� */
	UINT32 ulAccountSuccRsp;  /* �Ʒѳɹ��� */
}AC_OMA_ACCOUNTSTAT_T;

/* AP����ͳ����Ϣ */
typedef struct
{
	UINT32 	ulWtpId;		/* AP ID */
	UINT32	ulUlPkts;			/*���а��� */
	UINT32	ulDlPkts;			/*���а��� */
	UINT32	ulUlGigaWords;	/*�����ֽ�������λ4GByte */
	UINT32	ulUlBytes;		/*�����ֽ�������λByte */
	UINT32	ulDlGigaWords;	/*�����ֽ�������λ4GByte */
	UINT32	ulDlBytes;		/*�����ֽ�������λByte */
}AC_OMA_APTRAFFIC_STAT_T;
 
/* AP�豸����ͳ����Ϣ */
typedef struct
{
	UINT32	ulProcUptime;	/* powerac�߳��ϵ�ʱ�䣬��λ���� */
	UINT32 	ulValidNum;         /* AP���� */
   	AC_OMA_APTRAFFIC_STAT_T *pstApTrafficStat;
}AC_OMA_GET_APTRAFFIC_STAT_T;

/* AP�û�ͳ����Ϣ */
typedef struct
{
	UINT32 	ulWtpId;			/* AP ID */
	UINT32	ulUserAuthReq;	/* �û���֤������� */
	UINT32	ulUserOnlineTime;	/* �û�����ʱ������λ������ */
	UINT32	ulUserNum;		/* �ۼƵ��û���Ŀ */
}AC_OMA_APUSERSTAT_STAT_T;
 
/* AP�豸�û�ͳ����Ϣ */
typedef struct
{
	UINT32	ulProcUptime;			/* powerac�߳��ϵ�ʱ�䣬��λ���� */
	UINT32 	ulValidNum;         /* AP���� */
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
	UINT32   ulRet;            //������:0-�ɹ�
	UINT32   ulFinish;         //�Ƿ����:0-δ���� 1-����
	UINT8    aucRsp[4096];     //�����ֽ���
}AC_OMA_GET_AC_DYNAINFO_RSP_MSG_T;

/* OMC/WEB->AC-OMA������Ϣ�� */
typedef struct
{
	UINT32   ulSn;
	UINT32   ulDynaInfoType;
}AC_OMC_GET_AC_DYNAINFO_REQ_MSG_T;

/* AC-OMA->OMC/WEBӦ����Ϣ�� */
typedef struct
{
	UINT32   ulSn;
	UINT32   ulRet;             //������:0-�ɹ�
	UINT32   ulFinish;          //�Ƿ����:0-δ���� 1-����
	UINT8    aucRsp[4096];      //�����ֽ���
}AC_OMC_GET_AC_DYNAINFO_RSP_MSG_T;

/* OMC/WEB->AC-OMA RESET������Ϣ�� */
typedef struct
{
    UINT32  ulSn;
}AC_OMC_RESET_REQ_MSG_T;

/* AC-OMA->OMC/WEBӦ����Ϣ�� */
typedef struct
{
    UINT32  ulSn;
    UINT32  ulRet;
}AC_OMC_RESET_RSP_MSG_T;

/* OMC/WEB->AC-OMA ��ȡ��Ԫ�������ݰ汾��������Ϣ�� */
typedef struct  
{
	UINT32  ulSn;
}AC_OMA_GET_NECFGVERSION_REQ_MSG_T;

typedef struct  
{
	UINT32  ulApId;
	UINT32  ulApCfgVersion;
}AP_CFGVER_T;

/* AC-OMA->OMC/WEBӦ����Ϣ�� */
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

/* OMC/WEB->AC-OMA��ȡ��Ԫ����״̬������Ϣ�� */
typedef struct
{
	UINT32  ulSn;
}AC_OMC_GET_MSSTATUS_REQ_MSG_T;

/* AC-OMA->OMC/WEBӦ����Ϣ�� */
typedef struct
{
	UINT32  ulSn;
	UINT32  ulRet;
	UINT32  ulActive;  /* TRUE: ��ǰActive 
	                                  FALSE: ��ǰStandby
 					*/
}AC_OMC_GET_MSSTATUS_RSP_MSG_T;


/* OMC/WEB->AC-OMA ��ȡAP��̬��Ϣ */
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
	UINT32   ulRet;            //������:0-�ɹ�
	UINT32   ulFinish;         //�Ƿ����:0-δ���� 1-����
	UINT8    aucRsp[32*1024];     //�����ֽ���
}AC_OMA_GET_AP_DYNAINFO_RSP_MSG_T;

/* AP���� */
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

/* PING���� */
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

/* �����豸ʱ�� */
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
	UINT32   ulTime; /* ��1970-01-01 00:00:00������ */
}AC_OMA_AP_SETTIME_REQ_MSG_T;

typedef struct  
{
	UINT32   ulMsgType;
	UINT32   ulSn;
	UINT32   ulRet;
}AC_OMA_AP_SETTIME_RSP_MSG_T;

/* ����Ƿ��豸��ʷ */
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

/* ������������ʷ */
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

/* ����������ͳ�� */
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

/* �����豸��������(����) */
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

/* ��ѯ����汾����״̬��Ϣ */
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
	UINT32    ulLoadFlag;        /* ������ָʾ:1-���� 2-�ϴ� */
	CHAR      acFileName[64];    /* �ļ��� */
	UINT32    ulFileType;        /* �����ļ�����:1-����汾�ļ� 2-�����ļ� 3-��־�ļ� */
	UINT32    ulTransStatus;     /* �ļ�������:1-������ 2-����ɹ���� 3-ʧ�� */
	CHAR      acFailReason[128]; /* ʧ��ԭ�� */
	UINT32    ulByteSize;        /* �Ѿ��������ֽ��� */
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

/* AP->AC��ȡ�ɼ�������Ϣ */
typedef struct
{
	UINT32 ulSn;
}AC_OMC_AP_GET_COLLECTPARAM_REQ_MSG_T;

typedef struct
{
	UINT32 ulSn;
	UINT32 ulOn;	/*����ͳ�ƿ���*/
	UINT32 ulPeriodNormal;	/* AP����ɼ����� ��λ:�� 10~120 */
	UINT32 ulPeriodRealtime;	/* APʵʱ�ɼ����� ��λ:�� 2~5 */
	UINT32 ulReportLevel;	/*�������ܲɼ����أ�����λ��ʾ��һ�ű��Ӧһ��ID*/
	UINT32 ulStatisticsTime;		/* ����ͳ��ͳ��ʱ��	>0	60	��λ����*/
	UINT32 ulSampleTime;		/* ����ͳ�Ƴ���ʱ��	>0	10	��λ����*/
	UINT32 ulAllAPMonitorMode;    /* AC��AP���߼���ģʽ:
										1���ṩWLAN�������
										2���������߻���
										3������ʱ�������߻��� */
}AC_OMC_AP_GET_COLLECTPARAM_RSP_MSG_T;

#define AP_COLLECTPARAM_LEVEL_AP			0x00000001
#define AP_COLLECTPARAM_LEVEL_ETHERNET	0x00000002
#define AP_COLLECTPARAM_LEVEL_RADIO		0x00000004
#define AP_COLLECTPARAM_LEVEL_SSID		0x00000008
#define AP_COLLECTPARAM_LEVEL_STATION      0x00000010                        //��ʾ�Ƿ��ϱ��ն�ͳ����Ϣ
#define AP_COLLECTPARAM_LEVEL_STATION_ALL        0x00000020     //��ʾ�Ƿ��ϱ��ն˼�ͳ����Ϣ��0����ͳ�ƣ�1����������ͳ�ƣ�������AP_COLLECTPARAM_LEVEL_STATION�󣬱�ֵ�����壻
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

/*AP����ͳ���ϱ���Ϣͷ*/
typedef struct  
{	
	UINT32   ulApId;                    // AP ID
	UINT32   ulSn;
	UINT32   ulTimeStamp;         //ʱ�������1970.1.1�ŵ�������
	UINT32   ulFinish;         	  //�Ƿ����:0-δ���� 1-����        
	UINT32   ulRspLength;     // aucRsp���ȣ���������Ϣͷ
	UINT8    aucRsp[32*1024];     //�����ֽ���
}AC_OMA_AP_DYNAINFO_IND_MSG_T;

typedef struct
{
	UINT32 ulType;
	UINT32 ulLength;	/*��������Ϣͷ*/
}AC_ELEM_T;

/*���ܲɼ����ͣ�һ�ű��Ӧһ��TAGID*/
enum
{
	  AP_OMA_DYNAINFO_TYPE_AP = 0,                            /*AP��ͳ��*/
         AP_OMA_DYNAINFO_TYPE_ABSTRACT = 0,         

         AP_OMA_DYNAINFO_TYPE_ETHERNET=10,  		/*����������ͳ��*/
         AP_OMA_DYNAINFO_TYPE_ETHSTATS = 10,

         AP_OMA_DYNAINFO_TYPE_RADIO=20,          		 /*����������ͳ��*/
         AP_OMA_DYNAINFO_TYPE_RADIOSTATS = 20,
         AP_OMA_DYNAINFO_TYPE_NEIGHAPSTATS = 21,
      
         AP_OMA_DYNAINFO_TYPE_SSID=30,              		/*SSID��ͳ��*/
         AP_OMA_DYNAINFO_TYPE_SSIDAIR = 30,
         AP_OMA_DYNAINFO_TYPE_SSIDMGT = 31,
         AP_OMA_DYNAINFO_TYPE_SSIDASSOC = 32,

         AP_OMA_DYNAINFO_TYPE_STATION=40,       		/*�ն˼�ͳ��*/
         AP_OMA_DYNAINFO_TYPE_STASTATS_SIMPLE = 40,
         AP_OMA_DYNAINFO_TYPE_STASTATS_ALL = 41,

         AP_OMA_DYNAINFO_TYPE_WIDS=50,             		/*WIDS��ͳ��*/
         AP_OMA_DYNAINFO_TYPE_WIDS_ROGUEAP=50,
         AP_OMA_DYNAINFO_TYPE_WIDS_ROGUESTA=51,

         AP_OMA_DYNAINFO_TYPE_RT=1000,            		 /*ʵʱͳ��*/
         AP_OMA_DYNAINFO_TYPE_RTSTATS = 1000
};

/* 2010-08-27  fengjing add:OMC/WEB ������־ */
typedef struct
{
	CHAR    acOperator[64];     /* ������ */
	CHAR    acOperName[64];     /* �������� */
	CHAR    acOperObject[128];  /* �������� */
	CHAR    acOperInfo[128];    /* �������� */
	CHAR    acOperResult[128];  /* ������� */
}AC_OMC_ADMIN_LOG_IND_MSG_T;

/* add by gwx 2014-2-25 for task1265 */
/* �ϱ�AP��SN */
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulWtpId;		/* AP ID */
	UINT32	ulWtpProductType;	/* AP��Ʒ����*/
	CHAR	acModelName[64];
} AC_OMA_APPRODUCTTYPE_UPDATE_T;

/* add by gwx 2014-5-28 for ruijie AP������Ϣһ���ռ�begin */
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
/* add by gwx 2014-5-28 for ruijie AP������Ϣһ���ռ�end */

/**************************** �������� ***************************/
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

/* Ӧ��ģ��Ӧ���������ݵ�OMA */
extern AC_RET ac_oma_report_perf(UINT8 *pucRspMsg, UINT16 usMsgLen);

/* Ӧ��ģ�������ϱ���̬��Ϣ��OMA */
extern AC_RET ac_oma_report_dyna_info(UINT32 ulDynaInfoType, VOID *pDynaInfo);

/* 2009-09-03 fengjing add */
extern AC_RET ac_oma_convert_objectid_to_moi(CHAR *szObjectId, UINT32 ulWtpId, UINT32 *pulMOC, UINT8* aucMOI);
extern AC_RET ac_oma_convert_mocmoi_to_objectid(UINT32 ulMOC, UINT8 *aucMOI, CHAR *pcObjectId);

extern VOID ac_snmp_log_error(CHAR *szLog);
extern VOID ac_snmp_log(INT32 iLogLevel, CHAR *szFormat, ...);

#define snmp_log            ac_snmp_log
#define snmp_log_perror     ac_snmp_log_error

#endif /* AC_OMA_PUBLIC_H */



