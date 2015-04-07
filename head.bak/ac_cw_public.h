/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: CAPWAP模块公共头文件
* 修改历史: 
* 2008-5-9     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_PUBLIC_H
#define  _AC_CW_PUBLIC_H

/* 返回值错误码定义 */
#define AC_CW_ERROR_TIMEOUT         2
#define AC_CW_ERROR_INTERRUPTED     3
#define AC_CW_ERROR_GENERAL         4

#define AC_CW_BUFFER_SIZE   65535


#define AC_CW_AC_NUM_MAX    2       /* WTP上配置的最大AC地址数 */
#define AC_CW_SEQ_NUM_MAX   255

/* CAPWAP message type */
#define AC_CW_MSG_TYPE_DISCOVERY_REQUEST                                	(EV_CW_BEGIN+1)
#define AC_CW_MSG_TYPE_DISCOVERY_RESPONSE                               	(EV_CW_BEGIN+2)
#define AC_CW_MSG_TYPE_JOIN_REQUEST                                     		(EV_CW_BEGIN+3)
#define AC_CW_MSG_TYPE_JOIN_RESPONSE                                    		(EV_CW_BEGIN+4)
#define AC_CW_MSG_TYPE_CONFIGURATION_STATUS                             	(EV_CW_BEGIN+5)
#define AC_CW_MSG_TYPE_CONFIGURATION_STATUS_RESPONSE			(EV_CW_BEGIN+6)
#define AC_CW_MSG_TYPE_CFG_UPDATE_REQUEST                               	(EV_CW_BEGIN+7)
#define AC_CW_MSG_TYPE_CFG_UPDATE_RESPONSE                              	(EV_CW_BEGIN+8)
#define AC_CW_MSG_TYPE_EVENT_REQUEST                                    		(EV_CW_BEGIN+9)
#define AC_CW_MSG_TYPE_EVENT_RESPONSE                                   		(EV_CW_BEGIN+10)
#define AC_CW_MSG_TYPE_CHANGE_STATE_EVENT_REQUEST				(EV_CW_BEGIN+11)
#define AC_CW_MSG_TYPE_CHANGE_STATE_EVENT_RESPONSE 			(EV_CW_BEGIN+12)
#define AC_CW_MSG_TYPE_ECHO_REQUEST                                     		(EV_CW_BEGIN+13)
#define AC_CW_MSG_TYPE_ECHO_RESPONSE                                    		(EV_CW_BEGIN+14)
#define AC_CW_MSG_TYPE_IMAGE_DATA_REQUEST                               	(EV_CW_BEGIN+15)
#define AC_CW_MSG_TYPE_IMAGE_DATA_RESPONSE                              	(EV_CW_BEGIN+16)
#define AC_CW_MSG_TYPE_RESET_REQUEST                                    		(EV_CW_BEGIN+17)
#define AC_CW_MSG_TYPE_RESET_RESPONSE                                   		(EV_CW_BEGIN+18)
#define AC_CW_MSG_TYPE_PRIMARY_DISCOVERY_REQUEST				(EV_CW_BEGIN+19)
#define AC_CW_MSG_TYPE_PRIMARY_DISCOVERY_RESPONSE				(EV_CW_BEGIN+20)
#define AC_CW_MSG_TYPE_TRANSFER_REQUEST                                 	(EV_CW_BEGIN+21)
#define AC_CW_MSG_TYPE_TRANSFER_RESPONSE                                	(EV_CW_BEGIN+22)
#define AC_CW_MSG_TYPE_CLEAR_CONFIGURATION_REQUEST			(EV_CW_BEGIN+23)
#define AC_CW_MSG_TYPE_CLEAR_CONFIGURATION_RESPONSE			(EV_CW_BEGIN+24)
#define AC_CW_MSG_TYPE_STATION_CONFIGURATION_REQUEST			(EV_CW_BEGIN+25)
#define AC_CW_MSG_TYPE_STATION_CONFIGURATION_RESPONSE			(EV_CW_BEGIN+26)
#define AC_CW_MSG_TYPE_ACREBOOT_IND								(EV_CW_BEGIN+27)	/* 2009-10-22 AC向AP发送AC重启指示*/
#define AC_CW_MSG_TYPE_APIPCHG_IND								(EV_CW_BEGIN+28)	/* 2009-10-28 pyy AP向AC发送AP IP变化指示*/	


/* 向本处理器内其它线程发的消息*/
#define AC_CW_AC_INFO_IND_MSG           		(EV_CW_BEGIN+101)
#define AC_CW_JOIN_SUCC_IND_MSG         		(EV_CW_BEGIN+102)
#define AC_CW_CFG_UPDATE_IND_MSG			(EV_CW_BEGIN+103)		/* 配置更新指示消息，由WTP CAPWAP线程发送给主从线程*/
#define AC_CW_AGENTDATA_UPDATE_IND_MSG	(EV_CW_BEGIN+104)		/* 向AP OMA Agent线程发送配置数据变更通知*/
#define AC_CW_AP_IP_IND_MSG				(EV_CW_BEGIN+105)		/* AP IP地址变化通知*/


/* 本处理器内其它线程发送给本线程的消息 */   
#define AC_CW_CHANGE_STATE_REQ_MSG      (EV_CW_BEGIN+151)
/* 2008-9-27 pyy add start */
/* WTP与AC间的CAPWAP链路状态发生变化时, 通知WTP上Hostapd线程 */
#define AC_CW_WTP_CAPWAP_ONLINE         (EV_CW_BEGIN+152)   /* CAPWAP建链通知 */
#define AC_CW_WTP_CAPWAP_OFFLINE        (EV_CW_BEGIN+153)   /* CAPWAP断链通知 */
/* 2008-9-27 pyy add end */


/* CAPWAP message elements type */
#define AC_CW_MSG_ELEM_TYPE_AC_DESCRIPOR                		((UINT16)1)
#define AC_CW_MSG_ELEM_TYPE_AC_IPV4_LIST               		((UINT16)2)
#define AC_CW_MSG_ELEM_TYPE_AC_IPV6_LIST                		((UINT16)3)
#define AC_CW_MSG_ELEM_TYPE_AC_NAME                     		((UINT16)4)
#define AC_CW_MSG_ELEM_TYPE_AC_NAME_WITH_INDEX		((UINT16)5)
#define AC_CW_MSG_ELEM_TYPE_AC_TIMESTAMP                		((UINT16)6)
#define AC_CW_MSG_ELEM_TYPE_ADD_MAC_ACL_ENTRY           	((UINT16)7)
#define AC_CW_MSG_ELEM_TYPE_ADD_STATION                 		((UINT16)8)
#define AC_CW_MSG_ELEM_TYPE_ADD_STATIC_MAC_ACL_ENTRY	((UINT16)9)
#define AC_CW_MSG_ELEM_TYPE_CAPWAP_CTRL_IPV4_ADDR       ((UINT16)10)
#define AC_CW_MSG_ELEM_TYPE_CAPWAP_CTRL_IPV6_ADDR       ((UINT16)11)
#define AC_CW_MSG_ELEM_TYPE_CAPWAP_TIMERS               	((UINT16)12)
#define AC_CW_MSG_ELEM_TYPE_DATA_TRANSFER_DATA          	((UINT16)13)
#define AC_CW_MSG_ELEM_TYPE_DATA_TRANSFER_MODE          	((UINT16)14)
#define AC_CW_MSG_ELEM_TYPE_DECRYPTION_ERROR_REPORT     		((UINT16)15)
#define AC_CW_MSG_ELEM_TYPE_DECRYPTION_ERROR_REPORT_PERIOD  	((UINT16)16)
#define AC_CW_MSG_ELEM_TYPE_DELETE_MAC_ACL_ENTRY            		((UINT16)17)
#define AC_CW_MSG_ELEM_TYPE_DELETE_STATION                  			((UINT16)18)
#define AC_CW_MSG_ELEM_TYPE_DELETE_STATIC_MAC_ACL_ENTRY     	((UINT16)19)
#define AC_CW_MSG_ELEM_TYPE_DISCOVERY_TYPE                  			((UINT16)20)
#define AC_CW_MSG_ELEM_TYPE_DUPLICATE_IPV4_ADDR             		((UINT16)21)
#define AC_CW_MSG_ELEM_TYPE_DUPLICATE_IPV6_ADDR             		((UINT16)22)
#define AC_CW_MSG_ELEM_TYPE_IDLE_TIMEOUT                    			((UINT16)23)
#define AC_CW_MSG_ELEM_TYPE_IMAGE_DATA                      			((UINT16)24)
#define AC_CW_MSG_ELEM_TYPE_IMAGE_IDENTIFIER                			((UINT16)25)
#define AC_CW_MSG_ELEM_TYPE_IMAGE_INFO                      			((UINT16)26)
#define AC_CW_MSG_ELEM_TYPE_INITIAGE_DOWNLOAD               		((UINT16)27)
#define AC_CW_MSG_ELEM_TYPE_LOCATION_DATA                   			((UINT16)28)
#define AC_CW_MSG_ELEM_TYPE_MAX_MSG_LEN                     			((UINT16)29)
#define AC_CW_MSG_ELEM_TYPE_RADIO_ADMIN_STATE               		((UINT16)31)
#define AC_CW_MSG_ELEM_TYPE_RADIO_OPER_STATE                			((UINT16)32)
#define AC_CW_MSG_ELEM_TYPE_RESULT_CODE                     			((UINT16)33)
#define AC_CW_MSG_ELEM_TYPE_RET_MSG_ELEM                    			((UINT16)34)
#define AC_CW_MSG_ELEM_TYPE_SESSION_ID                      				((UINT16)35)
#define AC_CW_MSG_ELEM_TYPE_STATISTICS_TIMER                			((UINT16)36)
#define AC_CW_MSG_ELEM_TYPE_VENDOR_SPECIFIC_PAYLOAD         		((UINT16)37)
#define AC_CW_MSG_ELEM_TYPE_WTP_BOARD_DATA                  			((UINT16)38)
#define AC_CW_MSG_ELEM_TYPE_WTP_DESCRIPTOR                  			((UINT16)39)
#define AC_CW_MSG_ELEM_TYPE_WTP_FALLBACK                    			((UINT16)40)
#define AC_CW_MSG_ELEM_TYPE_WTP_FRAME_TUNNEL_MODE           		((UINT16)41)
#define AC_CW_MSG_ELEM_TYPE_WTP_IPV4_ADDR                   			((UINT16)42)
#define AC_CW_MSG_ELEM_TYPE_WTP_IPV6_ADDR                   			((UINT16)43)
#define AC_CW_MSG_ELEM_TYPE_WTP_MAC_TYPE                    			((UINT16)44)
#define AC_CW_MSG_ELEM_TYPE_WTP_NAME                        			((UINT16)45)
#define AC_CW_MSG_ELEM_TYPE_WTP_OPER_STATE                  			((UINT16)46)
#define AC_CW_MSG_ELEM_TYPE_WTP_RADIO_STATISTICS            		((UINT16)47)
#define AC_CW_MSG_ELEM_TYPE_WTP_REBOOT_STATISTICS           		((UINT16)48)
#define AC_CW_MSG_ELEM_TYPE_WTP_STATIC_IP_ADDR_INFO         		((UINT16)49)

/* vendor element ID */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_AC_ID               	 	((UINT16)1)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_ID               	((UINT16)2)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_SECRET           	((UINT16)3)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_AC_IP                		((UINT16)4)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_TBL_REC              	((UINT16)5)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_RADIO_LIST           	((UINT16)6)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_IP				((UINT16)7)
#define AC_CW_MSG_VENDOR_ELEM_TYPE_ACUPLINKSTATE		((UINT16)8)	/* AC 上行链路状态*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_SN				((UINT16)9)	/* AP 设备序列号*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_SWVER			((UINT16)10)	/* AP 软件版本号*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_SWINFO		((UINT16)11)	/* AP目标软件版本信息*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_DEVICETYPE		((UINT16)12)	/* AP设备型号*/	
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_DISTYPE		((UINT16)13)	/* AC发现方式*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_IPORIGIN		((UINT16)14)	/* AP IP配置方式*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_CFGVERSION	((UINT16)15)	/* AP 配置数据版本号*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_APACL				((UINT16)16)	/* AP访问策略*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_VAPADMINSTATE		((UINT16)17)	/* VAP管理状态*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_APMAC				((UINT16)18)  /* 2011-1-25 ymt add:AP MAC 地址*/
/* Add by majp 2012-12-13 start */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_SNOOPING                 ((UINT16)19)  /* AP dhcp snooping */
#define  AC_CW_MSG_VENDOR_ELEM_TYPE_FLOWCTRL                ((UINT16)20)  /* Ap Qos */
/* Add by majp 2012-12-13 end */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_NAT_IP			((UINT16)21)	/*2013-4-2 duankaiyuan add: used for NAT resolve */

/* add by gwx 2014-2-25 for task1265 begin*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_BOARD_VER		((UINT16)22)	/* AP上报的boardver*/
/* add by gwx 2014-2-25 for task1265 end*/

/* add by gwx 2014-4-26 for AP一键注册begin */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_MAIN_DNS		((UINT16)23)	/* AP上报的主DNS*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_SLAVE_DNS		((UINT16)24)	/* AP上报的备DNS*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_AC_URL		((UINT16)25)	/* AP上报的URL*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_IPMASK		((UINT16)27)	/* AP上报的IP掩码*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WTP_DFTGW		((UINT16)28)	/* AP默认网关*/
/* add by gwx 2014-4-26 for AP一键注册end */


/*begin add by dhsong,2013-8-16*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_PORTAL_IP        ((UINT16)26)	/*获取portal ip */
/*end   add by dhsong,2013-8-16*/

/* add by gwx 2014-6-20 */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_MODELNAME          ((UINT16)30)	/* model name  */

/* add by gwx 2014-7-31 */
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WHITELIST		((UINT16)31)	/* 白名单*/
#define AC_CW_MSG_VENDOR_ELEM_TYPE_WHITELISTURL		((UINT16)32)	/* 白名单URL */

/* 动态同步信息内部编号, WTP发往AC的消息中携带此编号, AC收到该消息后根据编号查找相应的处理函数 */
#define AC_CW_DYN_SYN_NUM_MAX				((UINT32)10)
#define AC_CW_DYN_SYN_NO_VAPBSSID       		((UINT32)0)         		/* VAP BSSID 列表 */
#define AC_CW_DYN_SYN_NO_VAPTRAFFICSTAT		((UINT32)1)			/* VAP TRAFFIC STAT列表*/
#define AC_CW_DYN_SYN_NO_MATESTATE			((UINT32)2)			/* 从机运行状态*/
#define AC_CW_DYN_SYN_NO_VAPWIFISTAT		((UINT32)3)			/* VAP无线统计列表*/
#define AC_CW_DYN_SYN_NO_VDEVMAXPOWER		((UINT32)4)			/* 无线设备最大发射功率*/
#define AC_CW_DYN_SYN_NO_ADHOCBSSID		((UINT32)5)			/* ADHOC BSSID 列表*/
/* add by gwx 2014-8-7 */
#define AC_CW_DYN_SYN_NO_APCHANNEL		((UINT32)6)			/*AP信道列表*/



/* the following msg elements type are to be defined */
/*
CAPWAP Local IPV4 Address                            TBD
CAPWAP Local IPV6 Address                            TBD
CAPWAP Transport Protocol                            TBD
*/


/* CAPWAP Preamble: 1byte (Bit0~Bit7)
*   version: Bit0~Bit3
*   type: Bit4~Bit7
* HELN: 5bit (Bit8~Bit12)
* RID: 5bit (Bit13~Bit17)
* WBID: 5bit (Bit18~Bit22)
* T: 1bit (Bit23)
* F: 1bit (Bit24)
* L: 1bit (Bit25)
* W: 1bit (Bit26)
* M: 1bit (Bit27)
* K: 1bit (Bit28)
* Flags: 3bit (Bit29~Bit31)
* 
* the second four bytes:
* Fragment ID: 2bytes (Bit0~Bit15)
* Fragment offset: 13bits (Bit16~Bit28)
* Reserved: 3bits (Bit29~Bit1)
*/

/* CAPWAP transport header */
/* the offset and len of each info */
/* the first 4bytes */
#define AC_CW_TRANSPORT_HEADER_VERSION_START           ((UINT32)0)
#define AC_CW_TRANSPORT_HEADER_TYPE_START              ((UINT32)4)
#define AC_CW_TRANSPORT_HEADER_HLEN_START              ((UINT32)8)
#define AC_CW_TRANSPORT_HEADER_RID_START               ((UINT32)13)
#define AC_CW_TRANSPORT_HEADER_WBID_START              ((UINT32)18)
#define AC_CW_TRANSPORT_HEADER_T_START                 ((UINT32)23)
#define AC_CW_TRANSPORT_HEADER_F_START                 ((UINT32)24)
#define AC_CW_TRANSPORT_HEADER_L_START                 ((UINT32)25)
#define AC_CW_TRANSPORT_HEADER_W_START                 ((UINT32)26)
#define AC_CW_TRANSPORT_HEADER_M_START                 ((UINT32)27)
#define AC_CW_TRANSPORT_HEADER_K_START                 ((UINT32)28)
#define AC_CW_TRANSPORT_HEADER_FLAGS_START             ((UINT32)29)

#define AC_CW_TRANSPORT_HEADER_VERSION_LEN              ((UINT32)4)
#define AC_CW_TRANSPORT_HEADER_TYPE_LEN                 ((UINT32)4)
#define AC_CW_TRANSPORT_HEADER_HLEN_LEN                 ((UINT32)5)
#define AC_CW_TRANSPORT_HEADER_RID_LEN                  ((UINT32)5)
#define AC_CW_TRANSPORT_HEADER_WBID_LEN                 ((UINT32)5)
#define AC_CW_TRANSPORT_HEADER_T_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_F_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_L_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_W_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_M_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_K_LEN                    ((UINT32)1)
#define AC_CW_TRANSPORT_HEADER_FLAGS_LEN                ((UINT32)3)

/* the second 4bytes */
#define AC_CW_TRANSPORT_HEADER_FRAGMENT_ID_START        ((UINT32)0)
#define AC_CW_TRANSPORT_HEADER_FRAGMENT_OFFSET_START    ((UINT32)16)
#define AC_CW_TRANSPORT_HEADER_RESERVED_START           ((UINT32)29)

#define AC_CW_TRANSPORT_HEADER_FRAGMENT_ID_LEN          ((UINT32)16)
#define AC_CW_TRANSPORT_HEADER_FRAGMENT_OFFSET_LEN      ((UINT32)13)
#define AC_CW_TRANSPORT_HEADER_RESERVED_LEN             ((UINT32)3)

/* */
#define AC_CW_ENABLED       ((UINT8)1)
#define AC_CW_DISABLED      ((UINT8)2)

/* WTP Board Data Subelement types */
#define AC_CW_WTP_BOARD_DATA_MODEL_NUMBER      ((UINT16)0)
#define AC_CW_WTP_BOARD_DATA_SERIAL_NUMBER     ((UINT16)1)
#define AC_CW_WTP_BOARD_DATA_BOARD_ID          ((UINT16)2)
#define AC_CW_WTP_BOARD_DATA_BOARD_REVISION    ((UINT16)3)
#define AC_CW_WTP_BOARD_DATA_BASE_MAC_ADDR     ((UINT16)4)

/* WTP Descriptor Subelement types */
#define AC_CW_WTP_DESCRIPTOR_HARDWARE_VERSION          ((UINT16)0)
#define AC_CW_WTP_DESCRIPTOR_ACTIVE_SOFTWARE_VERSION   ((UINT16)1)
#define AC_CW_WTP_DESCRIPTOR_BOOT_VERSION              ((UINT16)2)
#define AC_CW_WTP_DESCRIPTOR_OTHER_SOFTWARE_VERSION    ((UINT16)3)

/* security */
#define AC_CW_SECURITY_X509                    ((UINT8)1)
#define AC_CW_SECURITY_PRE_SHARED_SECRET    ((UINT8)2)

/* DTLS policy */
#define AC_CW_DTLS_POLICY_CLEAR_TEXT        ((UINT8)1)
#define AC_CW_DTLS_POLICY_DTLS_ENABLED    ((UINT8)2)

/* AC Descriptor Subelement types */
#define AC_CW_AC_DESCRIPTOR_HARDWARE_VERSION    ((UINT16)4)
#define AC_CW_AC_DESCRIPTOR_SOFTWARE_VERSION    ((UINT16)5)

/* MAC type */
#define AC_CW_MAC_TYPE_LOCAL_MAC    ((UINT8)0)  /* Local-MAC */
#define AC_CW_MAC_TYPE_SPLIT_MAC    ((UINT8)1)  /* Split-MAC */
#define AC_CW_MAC_TYPE_BOTH         ((UINT8)2)  /* support both Local-MAC and Split-MAC */

/* payload type */
#define AC_CW_PAYLOAD_TYPE_PLAIN    ((UINT8)0)  /* plain */
#define AC_CW_PAYLOAD_TYPE_CRYPT    ((UINT8)1)  /* crypt */

/* frame tunnel mode */
#define AC_CW_FRAME_TUNNEL_MODE_LOCAL_BRIDGING    ((UINT8)1)
#define AC_CW_FRAME_TUNNEL_MODE_8023                ((UINT8)2)
#define AC_CW_FRAME_TUNNEL_MODE_NATIVE                ((UINT8)4)
#define AC_CW_FRAME_TUNNEL_MODE_ALL                    ((UINT8)7)

/* last failure type */
#define AC_CW_LAST_FAILURE_TYPE_NOT_SUPPORTED        ((UINT8)0)
#define AC_CW_LAST_FAILURE_TYPE_AC_INITIATED        ((UINT8)1)
#define AC_CW_LAST_FAILURE_TYPE_LINK_FAILURE        ((UINT8)2)
#define AC_CW_LAST_FAILURE_TYPE_SOFTWARE_FAILURE    ((UINT8)3)
#define AC_CW_LAST_FAILURE_TYPE_HARDWARE_FAILURE    ((UINT8)4)
#define AC_CW_LAST_FAILURE_TYPE_OTHER_FAILURE        ((UINT8)5)
#define AC_CW_LAST_FAILURE_TYPE_UNKNOWN            ((UINT8)6)

/* 2010-10-6 pyy: 支持IXP/AP93/PB44 硬件平台*/
/* 2011-4-12 pyy: 支持自研PB44硬件平台*/
/* 2012-9-14 duankaiyuan add ta40 */
/* AP硬件版本类型*/
#define AC_CW_APHWTYPE_IXP			10			/* 硬件类型为IXP */
#define AC_CW_APHWTYPE_AP93			1			/* 硬件类型为AP93 */
#define AC_CW_APHWTYPE_PB44			12			/* 硬件类型为PB44 */
#define AC_CW_APHWTYPE_PB44_2		13			/* 硬件类型为自研PB44硬件平台*/
#define AC_CW_APHWTYPE_9344			4			/* 硬件类型为9344 */
#define AC_CW_APHWTYPE_TA40			5			/* 硬件类型为TA40 */
#define AC_CW_APHWTYPE_TA33			7			/* 硬件类型为TA33 */
#define AC_CW_APHWTYPE_TA55			8			/* 硬件类型为TA55 */

/* result code 
0  Success
1  Failure (AC List message element MUST be present)
2  Success (NAT detected)
3  Join Failure (unspecified)
4  Join Failure (Resource Depletion)
5  Join Failure (Unknown Source)
6  Join Failure (Incorrect Data)
7  Join Failure (Session ID already in use)
8  Join Failure (WTP Hardware not supported)
9  Join Failure (Binding Not Supported)
10 Reset Failure (Unable to Reset)
11 Reset Failure (Firmware Write Error)
12 Configuration Failure (Unable to Apply Requested Configuration- Service Provided Anyhow)
13 Configuration Failure (Unable to Apply Requested Configuration- Service Not Provided)
14 Image Data Error (Invalid Checksum)
15 Image Data Error (Invalid Data Length)
16 Image Data Error (Other Error)
17 Image Data Error (Image Already Present)
18 Message Unexpected (Invalid in current state)
19 Message Unexpected (Unrecognized Request)
20 Failure - Missing Mandatory Message Element                         
21 Failure - Unrecognized Message Element
*/
#define AC_CW_RESULT_CODE_SUCCESS                                            ((UINT32)0)
#define AC_CW_RESULT_CODE_FAILURE_MISSING_AC_LIST                            ((UINT32)1)
#define AC_CW_RESULT_CODE_SUCCESS_NAT_DETECTED                            ((UINT32)2)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_UNSPECIFIED                            ((UINT32)3)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_RESOURCE_DEPLETION                    ((UINT32)4)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_UNKNOWN_SOURCE                    ((UINT32)5)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_INCORRECT_DATA                        ((UINT32)6)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_SESSIONID_IN_USE                    ((UINT32)7)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_WTP_HARDWARE_NOT_SUPPORTED        ((UINT32)8)
#define AC_CW_RESULT_CODE_JOIN_FAILURE_BINDING_NOT_SUPPORTED                ((UINT32)9)
#define AC_CW_RESULT_CODE_RESET_FAILURE_UNABLE_TO_RESET                    ((UINT32)10)
#define AC_CW_RESULT_CODE_RESET_FAILURE_FIRMWARE_WRITE_ERROR            ((UINT32)11)
#define AC_CW_RESULT_CODE_CONF_FAILURE_SERVICE_PROVIDED_ANYHOW            ((UINT32)12)
#define AC_CW_RESULT_CODE_CONF_FAILURE_SERVICE_NOT_PROVIDED                ((UINT32)13)
#define AC_CW_RESULT_CODE_IMAGE_DATA_ERROR_INVALID_CHECKSUM                ((UINT32)14)
#define AC_CW_RESULT_CODE_IMAGE_DATA_ERROR_INVALID_DATA_LENGTH            ((UINT32)15)
#define AC_CW_RESULT_CODE_IMAGE_DATA_ERROR_OTHER_ERROR                    ((UINT32)16)
#define AC_CW_RESULT_CODE_IMAGE_DATA_ERROR_IMAGE_ALREADY_PRESENT        ((UINT32)17)
#define AC_CW_RESULT_CODE_MESSAGE_UNEXPECTED_INVALID_STATE                ((UINT32)18)
#define AC_CW_RESULT_CODE_MESSAGE_UNEXPECTED_UNRECOGNIZED_REQUEST        ((UINT32)19)
#define AC_CW_RESULT_CODE_FAILURE_MISSING_MANDATORY_ME                    ((UINT32)20)
#define AC_CW_RESULT_CODE_FAILURE_UNRECOGNIZED_ME                            ((UINT32)21)

/* header version */
#define AC_CW_VERSION   0

/* 2010-12-13 pyy修改: 兼容2.4版本的pb44 ap升级到2.2商用版本*/
#define AC_CW_HEADER_FLAGS_0		0
#define AC_CW_HEADER_FLAGS_1		1

/* CAPWAP control port */
#define AC_CW_CONTROL_PORT  4000    /* to be modified */

#define AC_CW_CAPWAP_CONTROL_HEADER_OFFSET_FOR_MSG_ELEMS    3

#define AC_CW_VENDOR_ID    ((UINT32)123456)

/* AP 软件版本信息*/
typedef struct 
{
	UINT32	ulNeedUpgrade;		/* AP版本是否需要升级	1:需要升级*/
	CHAR	acTargetSwVer[32];	/* 软件版本号*/
	UINT8	aucFtpSvrIp[4];		/* FTP服务器IP */
	UINT32	ulFtpPort;			/* FTP服务器端口*/
	CHAR	acFtpUserName[32];	/* FTP用户名*/
	CHAR	acFtpPwd[32];		/* FTP密码*/
	CHAR	acSwFileName[128];	/* 版本文件名*/
}  AC_CW_WTPSW_INFO_T;


/* CAPWAP状态机 */
typedef enum {
    CW_STATE_IDLE,
        CW_STATE_DISCOVERY,
        CW_STATE_SULKING,
        CW_STATE_DTLS_SETUP,
        CW_STATE_DTLS_CONNECT,
        CW_STATE_DTLS_TEARDOWN,
        CW_STATE_AUTHORIZE,
        CW_STATE_JOIN,
        CW_STATE_IMAGE_DATA,
        CW_STATE_CONFIGURE,
        CW_STATE_DATA_CHECK,
        CW_STATE_RUN,
        CW_STATE_RESET,
        CW_STATE_DEAD
} AC_CW_STATE;

/* WTP侧AC配置描述信息 */
typedef struct {
    UINT32  ulAcId;        /* AC Device ID */
    UINT8   aucIp[4];      /* AC IP地址 */
    UINT32  ulReceived;     /* 是否收到了AC的discovery response */
    UINT32  ulSeqNum;       /* 序列号 */
    UINT32	ulAssociateDegree;	/* 关联度: 0最高*/
    UINT32	ulAssociatePrio;		/* 关联优先级*/
    AC_CW_WTPSW_INFO_T	stTargetSwInfo;   
} AC_CW_AC_DESCRIPTOR_T;

/* WTP侧保存的AC动态信息 */
typedef struct {
        UINT32    ulAcId;
    UINT8    aucIp[4];
    UINT16      usStations;
    UINT16      usLimit;
    UINT16      usActiveWtps;
    UINT16      usMaxWtps;
    UINT8       ucSecurity;
    UINT8       ucRMacField;
    UINT8       ucRsv1;
    UINT8      ucDtlsPolicy;
    
    CHAR        *pucName;
    UINT32      ulIpv4AddrCount;
    UINT32	ulAssociateDegree;
    UINT32	ulAssociatePrio;
    AC_CW_WTPSW_INFO_T	stTargetSwInfo;   
} AC_CW_AC_INFO_T;

typedef struct {
    UINT8    *pucMsg;
    UINT32  ulOffset;
    UINT32  ulMsgLen;
} AC_CW_PROTO_MSG_T;

/* CAPWAP Transport Header */
typedef struct {
    UINT32  ulPayloadType;
    UINT32  ulType;
    UINT32  ulIsFragment;
    UINT32  ulIsLast;
    UINT32  ulFragmentId;
    UINT32  ulFragmentOffset;
    UINT32  ulFragmentKeepAlive;
     UINT32	ulFlags;
}AC_CW_TRANSPORT_HEADER_T;

/* CAPWAP Control Header */
typedef struct {
    UINT32  ulMsgType;      /* message type */
    UINT8   ucSeqNum;       /* sequence number */
    UINT8   ucFlags;        /* reserved, set to 0 */
    UINT16  usMsgElemsLen;  /* message element length: the number of bytes following the sequence number */
}AC_CW_CAPWAP_CONTROL_HEADER_T;


/* 信元结构体定义, 为了保持结构体自然4字节对齐, 可以进行填充 */
/* 子信元结构体定义(不包含Vendor Identifier) */
typedef struct {
    UINT16  usType;
    UINT16  usLen;
    UINT8   *pucValue;
} AC_CW_MSG_ELEM_SUBELEM_T;

/* 子信元结构体定义(包含Vendor Idendifier) */
typedef struct {
    UINT32  ulVendorIdentifier;
    UINT16  usType;
    UINT16  usLen;
    UINT8   *pucValue;
} AC_CW_MSG_ELEM_SUBELEMVENDOR_T;

/* AC Descriptor
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|            Stations           |             Limit             |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Active WTPs          |            Max WTPs           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|    Security   |  R-MAC Field  |   Reserved1   |  DTLS Policy  |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=4                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=5                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   1 for AC Descriptor
Length:   >= 12 
Stations:   The number of stations currently served by the AC  
Limit:   The maximum number of stations supported by the AC
Active WTPs:   The number of WTPs currently attached to the AC
Max WTPs:   The maximum number of WTPs supported by the AC
Security:   A 8 bit mask specifying the authentication credential
type supported by the AC.  The following values are supported (see
Section 2.4.4):            
1 -  X.509 Certificate Based 
2 -  Pre-Shared Secret               
R-MAC Field:   The AC supports the optional Radio MAC Address field
in the CAPWAP transport Header (see Section 4.3).
Reserved:  A set of reserved bits for future use.  All
implementations complying with this protocol MUST set to zero any
bits that are reserved in the version of the protocol supported by
that implementation.  Receivers MUST ignore all bits not defined
for the version of the protocol they support.
DTLS Policy:   The AC communicates its policy on the use of DTLS for
the CAPWAP data channel.  The AC MAY communicate more than one
supported option, represented by the bit field below.  The WTP
MUST abide by one of the options communicated by AC.  The
following bit field values are supported:                       
1 -  Clear Text Data Channel Supported
2 -  DTLS Enabled Data Channel Supported
Vendor Identifier:   A 32-bit value containing the IANA assigned "SMI
Network Management Private Enterprise Codes"
Type:   Vendor specific encoding of AC information.  The following
values are supported.  The Hardware and Software Version values
MUST be included.
4 - Hardware Version:   The AC's hardware version number.
5 - Software Version:   The AC's Software (firmware) version number.
Length:   Length of vendor specific encoding of AC information.                                                     
Value:   Vendor specific encoding of AC information.
*/
typedef struct {
	UINT32	ulAssociateDegree;	/* 关联度*/
	UINT32	ulAssociatePrio;		/* 关联优先级*/
    	UINT16   usStations;
    	UINT16   usLimit;
    	UINT16   usActiveWtps;
    	UINT16	usMaxWtps;
    	UINT8    	ucSecurity;
    	UINT8    	ucRMacField;
    	UINT8    	aucRsv[1];
    	UINT8    	ucDtlsPolicy;
    	UINT32	ulEchoInterval;       	/* 保活时长*/
    	UINT32  	ulMaxRetransmit;      	/* 保活次数*/
    	UINT32  	ulSubElemNum;
    	AC_CW_MSG_ELEM_SUBELEMVENDOR_T  *pstSubElemVendor;
} AC_CW_MSG_ELEM_AC_DESCRIPTOR_T;

/* AC IPv4 List 
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       AC IP Address[]                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   2 for AC IPv4 List
Length:   >= 4
The AC IP Address: An array of 32-bit integers containing AC IPv4 Addresses.
*/
typedef struct {
    UINT32    ulIpNum;
    UINT32    *pulIpList;
} AC_CW_MSG_ELEM_AC_IPV4_LIST_T;

/*
AC IPv6 List
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       AC IP Address[]                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       AC IP Address[]                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       AC IP Address[]                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       AC IP Address[]                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   3 for AC IPV6 List        
Length:   >= 16
The AC IP Address: An array of 128-bit integers containing AC IPv6 Addresses.
*/
typedef struct {
    UINT32  ulAddr0;
    UINT32  ulAddr1;
    UINT32  ulAddr2;
    UINT32  ulAddr3;
} AC_IPV6_ADDR_T;
typedef struct {
    UINT32    ulIpNum;
    AC_IPV6_ADDR_T  *pstIpV6;
} AC_CW_MSG_ELEM_AC_IPV6_LIST_T;

/* AC Name
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+
|   Name ...
+-+-+-+-+-+-+-+-+
Type:   4 for AC Name
Length:   > 0
Name:   A variable length UTF-8 encoded string containing the AC's name
*/
typedef struct {
    UINT32    ulNameLen;
    CHAR    *pucName;
} AC_CW_MSG_ELEM_AC_NAME_T;

/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|     Index     |   AC Name...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
AC Name wtih Index
Type:   5 for AC Name with Index
Length:   > 2  
Index:   The index of the preferred server (1=primary, 2=secondary).    
AC Name:   A variable length UTF-8 encoded string containing the AC name.
*/
typedef struct {
    UINT8	ucIndex;
    UINT8   aucRsv[3];  /* 填充字节 */
    UINT32  ulNameLen;
    CHAR	*pucName;
} AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_T;

typedef struct {
	UINT32	ulAcNameNum;
	AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_T	*pstAcNameList;
}AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_LIST_T;

/* CAPWAP Control IPv4 Address
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                           IP Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           WTP Count           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   10 for CAPWAP Control IPv4 Address
Length:   6
IP Address:   The IP Address of an interface.   
WTP Count:   The number of WTPs currently connected to the interface.
*/
typedef struct {
    UINT32    ulIpAddr;
    UINT16    usWtpCount;
    UINT8    aucRsv[2];
} AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T;

/* capwap timers */
/*
0                   1
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Discovery   | Echo Request  |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   12 for CAPWAP Timers
Length:   2    
Discovery:   The number of seconds between CAPWAP Discovery messages,
      when the WTP is in the discovery phase.
Echo Request:   The number of seconds between WTP Echo Request CAPWAP
        messages.  The default value for this message element is specified
      in Section 4.7.7.
*/
typedef struct {
    UINT8   ucDiscovery;
    UINT8   ucEchoReq;
    UINT8   aucRsv[2];  /* 填充字节 */
} AC_CW_MSG_ELEM_CAPWAP_TIMERS_T;

/* Decryption Error Report Period */
/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Radio ID    |        Report Interval        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   16 for Decryption Error Report Period
Length:   3
Radio ID:   The Radio Identifier refers to an interface index on the WTP.
Report Interval:   A 16-bit unsigned integer indicating the time, in
        seconds.  The default value for this message element can be found
      in Section 4.8.8.
*/
typedef struct {
    UINT8   ucRadioId;
    UINT8   aucRsv[1];
    UINT16  usReportInterval;
} AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_T;

typedef struct {
    UINT32  ulNum;
    AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_T   *pstList;
}AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_LIST_T;

/* discover type */
/*
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+
| Discovery Type|
+-+-+-+-+-+-+-+-+
Type:   20 for Discovery Type
Length:   1
Discovery Type:   An 8-bit value indicating how the WTP discovered the AC.  The following values are supported:
0 -  Unknown  
1 -  Static Configuration    
2 -  DHCP      
3 -  DNS
4 -  AC Referral (used when the AC was configured either through the AC IPv4 List or AC IPv6 List message element)
*/

/* 
Idle Timeout
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Timeout                            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   23 for Idle Timeout
Length:   4
Timeout:   The current idle timeout to be enforced by the WTP.  The
      default value for this message element is specified in
      Section 4.8.5.
*/

/*
Image Identifier
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   25 for Image Identifier
Length:   >= 1
Value:   A variable length UTF-8 encoded string containing the
firmware identifier to be run on the WTP.
*/
typedef struct {
    UINT32    ulVendorIdentifier;
    UINT32    ulLen;
    UINT8    *pucValue;
} AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T;

/*
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+-
| Location ...
+-+-+-+-+-+-+-+-+-
Type:   28 for Location Data
Length:   > 0
Location:   A non-zero terminated UTF-8 encoded string containing the WTP location.
*/
typedef struct {
    UINT32    ulLocationLen;
    UINT8    *pucLocation;
} AC_CW_MSG_ELEM_LOCATION_T;

/* Maximum Message Length 
0              1               2
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
|   Maximum Message Length     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
Type:   29 for Maximum Message Length
Length:   2            
Maximum Message Length  An 16-bit unsigned integer indicating the maximum message length.
*/

/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Radio ID    |  Admin State  |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   31 for Radio Administrative State
Length:   2 
Radio ID:   An 8-bit value representing the radio to configure.  The
    Radio ID field MAY also include the value of 0xff, which is used
    to identify the WTP.  If an AC wishes to change the administrative
    state of a WTP, it includes 0xff in the Radio ID field.
    
Admin State:   An 8-bit value representing the administrative state
      of the radio.  The default value for the Admin State field is
      listed in Section 4.8.1.  The following values are supported:
      1 -  Enabled  
      2 -  Disabled
*/
typedef struct {
	UINT8	ucRadioId;
	UINT8	ucAdminState;
    UINT8   aucRsv[2];      /* 填充字节 */
} AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_T;

typedef struct {
    UINT32    ulRadioNum;
    AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_T    *pstRadioAdminStateList;
} AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_LIST_T;
/*
0                   1                   2
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Radio ID    |     State     |     Cause     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   32 for Radio Operational State
Length:   3
Radio ID:   The Radio Identifier refers to an interface index on the
      WTP.  A value of 0xFF is invalid, as it is not possible to change
      the WTP's operational state.      
State:   An 8-bit boolean value representing the state of the radio.
      A value of one disables the radio, while a value of two enables
      it.        
Cause:   When a radio is inoperable, the cause field contains the
         reason the radio is out of service.  The following values are
         suppo
    0 -  Normal       
    1 -  Radio Failure          
    2 -  Software Failure            
    3 -  Administratively Set
*/
typedef struct {
    UINT8   ucRadioId;
    UINT8   ucState;
    UINT8   ucCause;
    UINT8   aucRsv[1];  /* 填充字节 */
} AC_CW_MSG_ELEM_RADIO_OP_STATE_T;

typedef struct {
    UINT32    ulRadioNum;
    AC_CW_MSG_ELEM_RADIO_OP_STATE_T    *pstRadioOpStateList;
} AC_CW_MSG_ELEM_RADIO_OP_STATE_LIST_T;

/*
Result Code
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                         Result Code                           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   33 for Result Code
Length:   4
Result Code:   The following values are defined:
0  Success
1  Failure (AC List message element MUST be present)
2  Success (NAT detected)
3  Join Failure (unspecified)
4  Join Failure (Resource Depletion)
5  Join Failure (Unknown Source)
6  Join Failure (Incorrect Data)
7  Join Failure (Session ID already in use)
8  Join Failure (WTP Hardware not supported)
9  Join Failure (Binding Not Supported)
10 Reset Failure (Unable to Reset)
11 Reset Failure (Firmware Write Error)
12 Configuration Failure (Unable to Apply Requested Configuration
- Service Provided Anyhow)
13 Configuration Failure (Unable to Apply Requested Configuration
- Service Not Provided)
14 Image Data Error (Invalid Checksum)
15 Image Data Error (Invalid Data Length)
16 Image Data Error (Other Error)
17 Image Data Error (Image Already Present)
18 Message Unexpected (Invalid in current state)
19 Message Unexpected (Unrecognized Request)
20 Failure - Missing Mandatory Message Element
21 Failure - Unrecognized Message Element
*/

/* Session ID
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                           Session ID                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   35 for Session ID
Length:   16  
Session ID:   A 32-bit unsigned integer used as a random session identifier
*/

/* Statistics Timer */
/*
0                   1
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|        Statistics Timer       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   36 for Statistics Timer  
Length:   2
Statistics Timer:   A 16-bit unsigned integer indicating the time, in
      seconds.  The default value for this timer is specified in
      Section 4.7.14.
*/

/* vendor specific payload */
/*
Type:   37 for Vendor Specific
*/
typedef struct {
    UINT32  ulSubElemNum;
    AC_CW_MSG_ELEM_SUBELEMVENDOR_T  *pstSubElemVendor;
} AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T;

/* WTP Board Data */
/*
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=0                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=1                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Optional additional vendor specific WTP board data TLVs.....
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   38 for WTP Board Data
Length:   >=14
Vendor Identifier:   A 32-bit value containing the IANA assigned "SMI
Network Management Private Enterprise Codes"

  Type:   The following values are supported:
  0 - WTP Model Number:   The WTP Model Number MUST be included in the WTP Board Data message element.
  1 - WTP Serial Number:   The WTP Serial Number MUST be included in the WTP Board Data message element.
  2 - Board ID:   A hardware identifier, which MAY be included in the WTP Board Data message element.
  3 - Board Revision   A revision number of the board, which MAY be included in the WTP Board Data message element.
  4 - Base MAC Address   The WTP's Base MAC Address, which MAY be assigned to the primary Ethernet interface.
*/
typedef struct {
    UINT32  ulVendorIdentifier;
    UINT32  ulSubElemNum;
    AC_CW_MSG_ELEM_SUBELEM_T    *pstSubElem;
} AC_CW_MSG_ELEM_WTP_BOARDDATA_T;

/* WTP Descriptor */
/*
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   Max Radios  | Radios in use |    Encryption Capabilities    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=0                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=1                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=2                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Vendor Identifier                       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Type=3                 |             Length           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Value...
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   39 for WTP Descriptor
Length:   >= 31
Max Radios:   An 8-bit value representing the number of radios (where
each radio is identified via the Radio ID field) supported by the
WTP.
Radios in use:   An 8-bit value representing the number of radios in
use in the WTP.
Encryption Capabilities:   This 16-bit field is used by the WTP to
communicate its capabilities to the AC.  A WTP that does not have
any encryption capabilities sets this field to zero (0).  Refer to
the specific wireless binding for further specification of the
Encryption Capabilities field.      
Vendor Identifier:   A 32-bit value containing the IANA assigned "SMI
Network Management Private Enterprise Codes".        
Type:   The following values are supported.  The Hardware Version,
Active Software Version, and Boot Version values MUST be included.
Zero or more Other Software Version values MAY be included.          
0 - Hardware Version:   The WTP hardware version number.
1 - Active Software Version:   The WTP running software version number.
2 - Boot Version:   The WTP boot loader version number.
3 - Other Software Version:   The WTP non-running software (firmware) version number.
Length:   Length of vendor specific encoding of WTP information.                     
Value:   Vendor specific data of WTP information encoded in the UTF-8 format.
*/
typedef struct {
    UINT8   ucMaxRadios;
    UINT8   ucRadiosInUse;
    UINT16  usEncrypCapa;
    UINT32  ulSubElemNum;
    AC_CW_MSG_ELEM_SUBELEMVENDOR_T  *pstSubElemVendor;
} AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T;

/* WTP Fallback */
/*
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+
|     Mode      |
+-+-+-+-+-+-+-+-+
Type:   40 for WTP Fallback
Length:   1
Mode:   The 8-bit value indicates the status of automatic CAPWAP
        fallback on the WTP.  When enabled, if the WTP detects that its
        primary AC is available, and that the WTP is not connected to the
        primary AC, the WTP SHOULD automatically disconnect from its
        current AC and reconnect to its primary AC.  If disabled, the WTP
        will only reconnect to its primary AC through manual intervention
        (e.g., through the Reset Request message).  The default value for
        this field is specified in Section 4.8.10.  The following values
        are supported:
        1 -  Enabled
        2 -  Disabled
*/

/* WTP Frame Tunnel Mode */
/*
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+
| Tunnel Mode   |
+-+-+-+-+-+-+-+-+
Type:   41 for WTP Frame Tunnel Mode
Length:   1
1 - Local Bridging
2 - 802.3 Frame Tunnel Mode
4 - Native Frame Tunnel Mode
7 - All
*/

/*
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                      WTP IPv4 IP Address                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   42 for WTP IPv4 IP Address 
Length:   4      
WTP IPv4 IP Address:   The IPv4 address from which the WTP is sending packets.  This field is used for NAT detection.
*/
typedef struct {
    UINT32  ulIpv4Addr;
} AC_CW_MSG_ELEM_WTP_CONTROL_IPV4_ADDR_T;

/* WTP MAC Type */
/*
0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+
|   MAC Type    |
+-+-+-+-+-+-+-+-+
Type:   44 for WTP MAC Type       
Length:   1
MAC Type:   The MAC mode of operation supported by the WTP.  The following values are supported          
0 - Local-MAC:   Local-MAC is the default mode that MUST be supported by all WTPs.
1 - Split-MAC:   Split-MAC support is optional, and allows the AC to receive and process native wireless frames.
2 - Both:   WTP is capable of supporting both Local-MAC and Split-MAC.
*/

/* WTP Radio Information message element 
to be modified
*/
typedef struct {
    UINT16  usType;
    UINT16  usLen;
    CHAR   *pucValue;
} AC_CW_MSG_ELEM_RADIOINFO_T;

/* Vendor Sepcific Payload 
same as AC_CW_MSG_ELEM_SUBELEMVENDOR_T
*/


/* WTP Name 
Type:   45 for WTP Name
Length:   variable
WTP Name:   A non-zero terminated UTF-8 encoded string containing the WTP name.
*/
typedef AC_CW_MSG_ELEM_AC_NAME_T    AC_CW_MSG_ELEM_WTP_NAME_T;


/* WTP Reboot Statistics
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Reboot Count          |    AC Initiated Count         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      Link Failure Count       |    SW Failure Count           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      HW Failure Count         |    Other Failure Count        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      Unknown Failure Count    |Last Failure Type|
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Type:   48 for WTP Reboot Statistics    
Length:   15
Reboot Count:   The number of reboots that have occurred due to a WTP
crash.  A value of 65535 implies that this information is not
available on the WTP.        
AC Initiated Count:   The number of reboots that have occurred at the
request of a CAPWAP protocol message, such as a change in
configuration that required a reboot or an explicit CAPWAP
protocol reset request.  A value of 65535 implies that this
information is not available on the WTP.
Link Failure Count:   The number of times that a CAPWAP protocol
connection with an AC has failed due to link failure.                            
SW Failure Count:   The number of times that a CAPWAP protocol
connection with an AC has failed due to software related reasons.                               
HW Failure Count:   The number of times that a CAPWAP protocol
connection with an AC has failed due to hardware related reasons.                                 
Other Failure Count:   The number of times that a CAPWAP protocol
connection with an AC has failed due to known reasons, other than
AC initiated, link, SW or HW failure.           
Unknown Failure Count:   The number of times that a CAPWAP protocol
connection with an AC has failed for unknown reasons.                                 
Last Failure Type:   The failure type of the most recent WTP failure.
The following values are supported:
0 -  Not Supported
1 -  AC Initiated (see Section 9.2)                                          
2 -  Link Failure
3 -  Software Failure
4 -  Hardware Failure                                                 
5 -  Other Failure         
255 -  Unknown (e.g., WTP doesn't keep track of info)
*/
typedef struct {
    UINT16    usRebootCount;
    UINT16    usAcInitiatedCount;
    UINT16    usLinkFailureCount;
    UINT16    usSWFailureCount;
    UINT16    usHWFailureCount;
    UINT16    usOtherFailureCount;
    UINT16    usUnknownFailureCount;
    UINT8    ucLastFailureType;
    UINT8    aucRsv[1];
} AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T;

/*
WTP Static IP Address Information 
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          IP Address                           |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Netmask                            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                            Gateway                            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|    Static     |
+-+-+-+-+-+-+-+-+
Type:   49 for WTP Static IP Address Information 
Length:   13
IP Address:   The IP Address to assign to the WTP.  This field is
      only valid if the static field is set to one.      
Netmask:   The IP Netmask.  This field is only valid if the static
      field is set to one.        
Gateway:   The IP address of the gateway.  This field is only valid
          if the static field is set to one.                    
Static:   An 8-bit boolean stating whether the WTP should use a
      static IP address or not.  A value of zero disables the static IP
      address, while a value of one enables it.
*/
typedef struct {
    UINT32  ulIpAddr;
    UINT32  ulNetMask;
    UINT32  ulGatewayAddr;
    UINT8   ucStatic;
    UINT8   aucRsv[3];  /* 填充字节 */
}AC_CW_MSG_ELEM_WTP_STATIC_IP_ADDR_INFO_T;

/* 消息定义, 为了保持结构体自然4字节对齐, 可以进行填充 */
/* discovery request message */
typedef struct {
    UINT8   ucDiscoveryType;        /* discovery type */
    UINT8   ucFrameTunnelMode;      /* WTP frame tunnel mode */
    UINT8   ucMacType;                  /* WTP MAC type */
    UINT8   aucRsv[1];                      /* reserved */
    AC_CW_MSG_ELEM_WTP_BOARDDATA_T               stWtpBoardData;        /* WTP Board Data*/
    AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T              stWtpDescriptor;       /* WTP Descriptor */
    AC_CW_MSG_ELEM_RADIOINFO_T                       stRadioInfo;            /* WTP Radio Information message elements */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T      stVendorSepcific;       /* Vendor Specific Payload */
}AC_CW_MSG_DISCOVERYREQUEST_T;

/* discovery response message */
typedef struct {
    AC_CW_MSG_ELEM_AC_DESCRIPTOR_T    stAcDescriptor;                                /* AC Descriptor */
    AC_CW_MSG_ELEM_AC_NAME_T    stAcName;                                        /* AC Name */
    AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T    stControlIpv4Addr;            /* CAPWAP Control IPv4 Addr */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */    
} AC_CW_MSG_DISCOVERYRESPONSE_T;

/* echo request */
typedef struct {
	AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */    
}AC_CW_MSG_ECHOREQUEST_T;

/* echo response */
typedef struct {
	AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */    
} AC_CW_MSG_ECHORESPONSE_T;

/* join request */
typedef struct {
    AC_CW_MSG_ELEM_LOCATION_T        stLocationData;
    AC_CW_MSG_ELEM_WTP_BOARDDATA_T    stWtpBoardData;
    AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T    stWtpDescriptor;
    AC_CW_MSG_ELEM_WTP_NAME_T    stWtpName;
    UINT32    ulSessionId;
    UINT8    ucFrameTunnelMode;
    UINT8    ucWtpMacType;
    UINT8    aucRsv[2];
    AC_CW_MSG_ELEM_WTP_CONTROL_IPV4_ADDR_T    stWtpIpv4Addr;
    UINT32    ulMaxMsgLen;
    AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T    stWtpRebootStat;
} AC_CW_MSG_JOINREQUEST_T;

/* join response */
typedef struct {
    /* must be included */
    UINT32    ulResultCode;
    AC_CW_MSG_ELEM_AC_DESCRIPTOR_T    stAcDescriptor;
    AC_CW_MSG_ELEM_AC_NAME_T    stAcName;
    /* WTP Radio Information message elements */
    AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T    stCapwapCtrlIpv4Addr;
    
    /* may be included */
    AC_CW_MSG_ELEM_AC_IPV4_LIST_T       stAcIpv4List;
    AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T   stImageIdentifier;
    UINT32    ulMaxMsgLen;
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T    stVendorSepcific;       /* Vendor Specific Payload */
} AC_CW_MSG_JOINRESPONSE_T;

/* configuration status */
typedef struct {
	/* must be included */
	AC_CW_MSG_ELEM_AC_NAME_T	stAcName;                               /* AC Name */
    AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_LIST_T    stAcNameWithIndexList;  /* AC Name with Index */
    AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_LIST_T     stRadioAdminStateList;  /* Radio Administrative State */
    UINT32  ulStatTimer;                                                /* Statistics Timer */
    AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T      stWtpRebootStat;        /* WTP Reboot Statistics */
	
	/* may be included */
    AC_CW_MSG_ELEM_WTP_STATIC_IP_ADDR_INFO_T    stWtpStaticIpAddr;      /* WTP Static IP Address Information */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T    stVendorSepcific;       /* Vendor Specific Payload */
}AC_CW_MSG_CFGSTATUS_T;

/* configuration status response*/
typedef struct {
	/* must be included */
    AC_CW_MSG_ELEM_AC_IPV4_LIST_T   stAcIpv4List;   /* AC IPv4 List */
    AC_CW_MSG_ELEM_AC_IPV6_LIST_T   stAcIpv6List;   /* AC IPv6 List */
    AC_CW_MSG_ELEM_CAPWAP_TIMERS_T  stCWTimers;     /* CAPWAP Timers */
    AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_LIST_T   stDecrErrorReportPerdList;  /* Decryption Error Report Period */
    UINT32  ulIdleTimeout;      /* Idle Timeout */
    UINT8   ucWtpFallback;      /* WTP Fallback */
    UINT8   aucRsv[3];          /* 填充字节 */
    
	/* may be included */
    AC_CW_MSG_ELEM_WTP_STATIC_IP_ADDR_INFO_T    stWtpStaticIpAddr;      /* WTP Static IP Address Information */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T    stVendorSepcific;       /* Vendor Specific Payload */
}AC_CW_MSG_CFGSTATUSRESPONSE_T;

/* 2009-10-22 pyy 新增*/
/* AC重启指示消息指示*/
typedef struct
{
	UINT32	ulAcId;
	UINT32	ulReason;
	UINT8	aucRsv[64];	/* 保留字节*/
} AC_CW_MSG_ACREBOOT_IND_T;

/* 2009-10-28 pyy 新增*/
/* AP IP变化指示*/
typedef struct
{
	UINT8   	aucWtpIp[4];		/* WTP设备IP地址 */		
    	UINT8   	aucNetMask[4];		/* 掩码 */	
    	UINT8	aucDefaultGw[4];		/* 缺省网关*/
	UINT8	aucPrimaryDns[4];	/*	主DNS服务器	*/
	UINT8	aucSecondaryDns[4];	/*	从DNS服务器	*/
	UINT8	aucRsv[64];			/* 保留字节*/
}AC_CW_MSG_APIPCHG_IND_T;

typedef struct {
    UINT16    usTblNum;
    UINT8    aucRsv[2];
}  AC_CW_CFG_UPDATE_FILE_HEADER_T;

typedef struct {
    CHAR    acTblName[AC_DB_TBL_NAME_LEN_MAX];    /* 关系表名 */
    UINT16    usRecordLen;                            /* 记录有效长度 */
    UINT8    aucRsv[2];                                /* 填充字节 */
    UINT32    ulRecordNum;                            /* 记录数 */
} AC_CW_CFG_UPDATE_TBL_HEADER_T;

/* configuration update request */
/* 配置信息更新时vendor specific payload的消息格式:
file header +
tbl header 1+
record +
tbl header 2+
record +
....
*/
typedef struct {
     /* may be included */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */
} AC_CW_MSG_CFGUPDATEREQUEST_T;

/* configuration update response */
typedef struct {
    /* must be included */
    UINT32    ulResultCode;
} AC_CW_MSG_CFGUPDATERESPONSE_T;

/* change state event  request */
typedef struct {
    /* must be included */
    UINT32    ulResultCode;
    AC_CW_MSG_ELEM_RADIO_OP_STATE_LIST_T    stRadioOpStateList;
    
    /* may be included */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */
} AC_CW_MSG_CHANGESTATEEVENTREQUEST_T;

/* change state event response */
typedef struct {
    /* may be included */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */
}AC_CW_MSG_CHANGESTATEEVENTRESPONSE_T;

/* WTP Event Request */
typedef struct {
	/* 暂时先包含Vendor Specific*/
	/* may be included */
    AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T  stVendorSepcific;                   /* Vendor Specific Payload */
} AC_CW_MSG_WTPEVENTREQUEST_T;


/* WTP发现AC后，发消息通知通信模块*/
typedef struct {
    	UINT32   	ulAcId;        	/* AC ID */
    	UINT32	ulWtpId;		/* AP ID */
	UINT8    	aucIp[4];    	/* AC IP */
}AC_CW_AC_INFO_IND_MSG_T;

/* AP通过DHCP获取到IP地址后, 发消息通知通信模块*/
typedef struct 
{
	UINT8	aucIp[4];	/* AP IP */
} AC_CW_AP_IP_IND_MSG_T;


/* WTP其它模块请求本模块向AC发送动态信息变化请求 */
typedef struct {
    UINT32  ulResultCode;
    UINT32  ulDynSynNo;
    UINT8   aucKeyInfo[32]; /* 关键字信息 */
}AC_CW_CHANGE_STATE_REQ_MSG_T;

typedef struct {
	UINT32	ulDynSynNo;			/* 同步号*/
	UINT32	ulSeqNum;			/* 序列号*/
} AC_CW_AC_DYN_SYN_T;

/* 动态信息同步控制数据区结构体定义*/
typedef struct
{
	UINT32	ulValid;				/* 有效标记*/
	UINT32	ulDynSynNo;			/* 同步号*/
	UINT32	ulNeedAckFlag;		/* 是否需要确认标记*/
	UINT32	ulSeqNum;			/* 序列号*/
} AC_CW_WTP_DYN_SYN_T;

typedef struct
{
	UINT8	aucIp[4];           		/* WTP IP */
	UINT8	aucNetMask[4];			/* 掩码 */
	UINT8	aucDefaultGw[4];
	UINT8	aucPrimaryDns[4];	/*	主DNS服务器	*/
	UINT8	aucSecondaryDns[4];	/*	从DNS服务器	*/
} AC_CW_WTPIP_CONFIG_T;

/*begin add by dhsong,2013-8-16*/
typedef struct
{
	UINT32	ulNumber;		//携带的portal IP个数，最多传输8个IP地址
	UINT8	aucPortalIp[AC_DEVM_MAX_PORTALIP_NUM][4];	//存放portal IP地址
}AC_CW_GET_PORTAL_IP_T; 
/*begin add by dhsong,2013-8-16*/

/* AC侧WTP描述数据结构体 */
typedef struct ac_cw_wtpinfo AC_CW_WTPINFO_T;
struct ac_cw_wtpinfo {
	UINT32			ulAssociatePrio;
    	UINT32  			ulValid;
    	UINT32  			ulWtpId;
    	CHAR    			acWtpName[32];
    	UINT8			aucDeviceId[6];
    	/*UINT8			aucRsv[2]; */	/*2011-12-26 Bug 420, duankaiyuan modified */
		UINT8			aucWtpMac[6];	/*2011-12-26 Bug 420, duankaiyuan add*/
    	UINT32			ulHwType;		/* 2010-10-6 pyy: AP支持IXP/AP93/PB44硬件平台 */
	AC_CW_WTPIP_CONFIG_T		stWtpIpCfg;
    	UINT32    		ulWtpCWAddr;                	/* WTP控制面IP地址*/
    	AC_CW_STATE    	eCurState;            		/* 当前状态 */

    	UINT32    ulTimerIdWJR;                		/* wait join request timer id */
    	UINT32    ulTimerIdWER;                		/* wait echo request timer id */
    	UINT32    ulTimerIdWCUR;                	/* wait configuration update response */

    	UINT32    ulLostEchoReqNum;            	/* lost echo request num */

    	/* 保活时长和保活次数*/
    	UINT32	ulEchoInterval;       	/* 保活时长*/
    	UINT32  	ulMaxRetransmit;      	/* 保活次数*/

    	UINT32	ulRecvEchoReqNum;

    	/* 2010-6-29 pyy 新增: VAP管理状态、AP安全策略*/
    	UINT32	aulVapAdminState[AC_VAPID_MAX+1];
    	AC_DEVM_APACL_CONFIG_T		stApAclCfg;		/* 网络序*/

	/* 2010-12-13 pyy修改: 兼容2.4版本的pb44 ap升级到2.2商用版本*/
    	UINT32	ulVersionFlag;
    	UINT32	ulNtpAlarmFlag;

      /* Add by majp 2012-12-13 start */
      UINT32 ulDhcpSnooping;
      UINT32 ulQos;
      /* Add by majp 2012-12-13 end */
	  
	/*begin add by dhsong,2013-8-16*/
	AC_CW_GET_PORTAL_IP_T stPortalIp;
	/*begin add by dhsong,2013-8-16*/
	/* add by gwx 2014-8-12 */
	AC_DEVM_NAT_IP_CONFIG_T		stNatIpCfg;
};

/* add by gwx 2014-7-31 begin 支持白名单和表名单URL配置下发AP*/
typedef struct
{
	UINT8	aucWhiteIp[4];		/* IP地址*/
	UINT8	aucWhiteIpMask[4];	/*	掩码*/
	UINT16	usWhiteProto;		/*	协议*/
	UINT16	usWhitePort;			/* 端口*/
}AC_CW_WHITLIST_INFO;

typedef struct
{
	UINT8	aucWhiteUrl[64];		/* 白名单URL */
} AC_CW_WHITLISTURL_INFO;
/* add by gwx 2014-7-31 end 支持白名单和表名单URL配置下发AP*/


#define AC_CW_SET_FIELD_32(ulDst, ulStart, ulLen, ulVal) (ulDst) |=  (((~(0xFFFFFFFF << (ulLen))) & (ulVal)) << (32 - (ulStart) - (ulLen)))
#define AC_CW_GET_FILED_32(ulDst, ulStart, ulLen) ((~(0xFFFFFFFF<<(ulLen))) & ((ulDst) >> (32 - (ulStart) - (ulLen))))

/* 全局函数声明*/
/* ac_cw_common.c 中的函数 */
extern AC_CW_PROTO_MSG_T*  ac_cw_msg_elem_array_create (UINT32 ulElemNum);
extern UINT32 ac_cw_msg_elem_create (AC_CW_PROTO_MSG_T* pstMsg, UINT32 ulSize);
extern UINT32 ac_cw_msg_elem_free (AC_CW_PROTO_MSG_T* pstMsg);
extern UINT32 ac_cw_get_ac_descriptor (AC_CW_MSG_ELEM_AC_DESCRIPTOR_T *pstAcDescriptor, AC_CW_WTPINFO_T *pstWtp);
extern UINT32  ac_cw_get_ac_ipv4_list (AC_CW_MSG_ELEM_AC_IPV4_LIST_T*pstAcIpv4List);
extern UINT32  ac_cw_get_ac_ipv6_list (AC_CW_MSG_ELEM_AC_IPV6_LIST_T*pstAcIpv6List);
extern UINT32 ac_cw_get_ac_name (AC_CW_MSG_ELEM_AC_NAME_T *pstAcName);
extern UINT32	ac_cw_get_wtp_swinfo(UINT32 ulWtpId, 
									UINT32	ulWtpHwType,
									CHAR *pcWtpSwVer, 
									AC_CW_WTPSW_INFO_T *pstWtpSwInfo);
extern UINT32 ac_cw_get_ac_name_with_index_list (AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_LIST_T *pstList);
extern UINT32  ac_cw_get_capwap_ctrl_ipv4_addr (AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T *pstIpv4Addr);
extern UINT32  ac_cw_get_capwap_timers (AC_CW_MSG_ELEM_CAPWAP_TIMERS_T *pstCwTimers);
extern UINT32  ac_cw_get_decr_error_report_perd_list (AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_LIST_T *pstPrdList);
extern VOID  ac_cw_get_discovery_type (UINT8 *pucDisoveryType);
extern VOID  ac_cw_get_idle_timeout (UINT32 *pulIdleTimeOut);
extern UINT32  ac_cw_get_image_identifier (AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T *pstImageId);
extern UINT32  ac_cw_get_location_data (AC_CW_MSG_ELEM_LOCATION_T *pstLocationData);
extern UINT32  ac_cw_get_max_msg_len (UINT16 *pusMaxMsgLen);
extern UINT32  ac_cw_get_radio_admin_state_list (AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_LIST_T *pstList);
extern UINT32  ac_cw_get_radio_op_state_list (AC_CW_MSG_ELEM_RADIO_OP_STATE_LIST_T *pstList);
extern UINT32  ac_cw_get_result_code (UINT32 *pulResultCode);
extern UINT32  ac_cw_get_stat_timer (UINT32 *pulStatTimer);
extern UINT32  ac_cw_get_sessionid (UINT32 *pulSessionId);
extern UINT32  ac_cw_get_wtp_board_data (AC_CW_MSG_ELEM_WTP_BOARDDATA_T *pstWtpBoardData);
extern VOID  ac_cw_get_wtp_max_radios (UINT8 *pucMaxRadios);
extern VOID  ac_cw_get_wtp_radios_in_use (UINT8 *pucRadiosInUse);
extern VOID  ac_cw_get_wtp_encryption_capabilities (UINT16 *pusEncrypCapa);
extern UINT32  ac_cw_get_wtp_descriptor_info (AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T *pstWtpDescriptorInfo);
extern VOID ac_cw_get_wtp_fallback (UINT8 *pucWtpFallback);
extern VOID ac_cw_get_wtp_frame_tunnel_mode (UINT8 *pucTunnelMode);
extern UINT32 ac_cw_get_wtp_ipv4_addr (AC_CW_MSG_ELEM_WTP_CONTROL_IPV4_ADDR_T *pstWtpIpv4Addr);
extern VOID ac_cw_get_wtp_mac_type (UINT8 *pucMacType);
extern UINT32 ac_cw_get_wtp_name(AC_CW_MSG_ELEM_WTP_NAME_T*pstWtpName);
extern UINT32 ac_cw_get_wtp_reboot_stat (AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T *pstWtpRebootStat);
extern UINT32 ac_cw_get_wtp_static_ip_addr_info (AC_CW_MSG_ELEM_WTP_STATIC_IP_ADDR_INFO_T *pstWtpInfo);
extern UINT32 ac_cw_get_wtp_vendor_specific (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32 ac_cw_get_wtp_cfg_status_vendor_specific (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32 ac_cw_get_change_state_event_vendor_specific (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific, 
                                                            UINT32 ulDynSynNo);
extern UINT32 ac_cw_get_change_state_event_response_vendor_specific (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific, AC_CW_AC_DYN_SYN_T *pstDynSyn);
extern UINT32 ac_cw_get_wtp_event_request_vendor_specific_vap_trafficstat (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32 ac_cw_get_ac_vendor_specific (UINT32 ulWtpId,
													AC_CW_WTPSW_INFO_T *pstWtpSwInfo,
													AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstAcVendorSpecific);
extern UINT32 ac_cw_get_echorsp_vendor_specific (AC_CW_WTPSW_INFO_T *pstSwInfo,
													UINT32	*pulVapAdminState,
													AC_DEVM_APACL_CONFIG_T	*pstApAclCfg,
													AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstEchorspVendorSpecific,
													UINT32 ulDhcpSnooping,
													UINT32 ulQos,
													AC_CW_GET_PORTAL_IP_T * pstPortalIpInfo);													
extern UINT32 ac_cw_get_cfg_update_file_header (AC_CW_CFG_UPDATE_FILE_HEADER_T *pstFileHeader);

/* extern UINT32    ac_cw_get_cfg_update_tbl_header(AC_CW_WTPINFO_T *pstWtp, DBHANDLE hTbl, AC_CW_CFG_UPDATE_TBL_HEADER_T *pstTblHeader); */
/*extern UINT32 ac_cw_get_ac_cfgupdate_vendor_specific (AC_CW_WTPINFO_T *pstWtp,     
                                               AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstAcVendorSpecific);*/
extern UINT32  ac_cw_free_ac_descriptor (AC_CW_MSG_ELEM_AC_DESCRIPTOR_T *pstAcDescriptor);
extern UINT32  ac_cw_free_ac_ipv4_list (AC_CW_MSG_ELEM_AC_IPV4_LIST_T*pstAcIpv4List);
extern UINT32  ac_cw_free_ac_ipv6_list (AC_CW_MSG_ELEM_AC_IPV6_LIST_T*pstAcIpv6List);
extern UINT32  ac_cw_free_ac_name (AC_CW_MSG_ELEM_AC_NAME_T *pstAcName);
extern UINT32  ac_cw_free_ac_name_with_index_list (AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_LIST_T *pstList);
extern UINT32  ac_cw_free_decr_error_report_perd_list (AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_LIST_T *pstPrdList);
extern UINT32  ac_cw_free_image_identifier (AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T *pstImageId);
extern UINT32  ac_cw_free_location_data (AC_CW_MSG_ELEM_LOCATION_T *pstLocationData);
extern UINT32  ac_cw_free_wtp_board_data (AC_CW_MSG_ELEM_WTP_BOARDDATA_T *pstWtpBoardData);
extern UINT32  ac_cw_free_wtp_descriptor_info (AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T *pstWtpDescriptorInfo);
extern UINT32 ac_cw_free_wtp_name(AC_CW_MSG_ELEM_WTP_NAME_T*pstWtpName);
extern UINT32 ac_cw_free_radio_info(AC_CW_MSG_ELEM_RADIOINFO_T*pstRadioInfo);
extern UINT32 ac_cw_free_radio_admin_state_list (AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_LIST_T *pstRadioAdminStateList);
extern UINT32 ac_cw_free_radio_op_state_list (AC_CW_MSG_ELEM_RADIO_OP_STATE_LIST_T *pstRadioOpStateList);
extern UINT32  ac_cw_free_vendor_specific  (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstVendorSpecific);

extern UINT32 ac_cw_free_discovery_request(AC_CW_MSG_DISCOVERYREQUEST_T *pstDiscoveryReq);
extern UINT32 ac_cw_free_discovery_response(AC_CW_MSG_DISCOVERYRESPONSE_T *pstDiscoveryRep);
extern UINT32	 ac_cw_free_echo_request(AC_CW_MSG_ECHOREQUEST_T *pstEchoReq);
extern UINT32 ac_cw_free_echo_response(AC_CW_MSG_ECHORESPONSE_T *pstEchoRep);
extern UINT32 ac_cw_free_join_request(AC_CW_MSG_JOINREQUEST_T *pstJoinReq);
extern UINT32 ac_cw_free_join_response(AC_CW_MSG_JOINRESPONSE_T *pstJoinRep);
extern UINT32 ac_cw_free_cfg_status(AC_CW_MSG_CFGSTATUS_T *pstReq);
extern UINT32 ac_cw_free_cfg_status_rsp(AC_CW_MSG_CFGSTATUSRESPONSE_T *pstRsp);
extern UINT32 ac_cw_free_cfg_update_req(AC_CW_MSG_CFGUPDATEREQUEST_T *pstReq);
extern UINT32 ac_cw_free_cfg_update_rsp(AC_CW_MSG_CFGUPDATERESPONSE_T *pstRsp);
extern UINT32 ac_cw_free_change_state_event_request(AC_CW_MSG_CHANGESTATEEVENTREQUEST_T *pstReq);
extern UINT32 ac_cw_free_change_state_event_response(AC_CW_MSG_CHANGESTATEEVENTRESPONSE_T *pstRsp);
extern UINT32 ac_cw_free_wtp_event_request(AC_CW_MSG_WTPEVENTREQUEST_T *pstReq);

extern UINT32 ac_cw_msg_elem_type_check (UINT16 usMsgElemType);
extern VOID ac_cw_msg_elem_coder_char(AC_CW_PROTO_MSG_T *pstMsg, CHAR ucVal);
extern VOID ac_cw_msg_elem_coder_short(AC_CW_PROTO_MSG_T *pstMsg, UINT16 usVal);
extern VOID ac_cw_msg_elem_coder_long(AC_CW_PROTO_MSG_T *pstMsg, UINT32 ulVal);
extern VOID ac_cw_msg_elem_coder_string(AC_CW_PROTO_MSG_T *pstMsg, CHAR *pucStr);
extern VOID ac_cw_msg_elem_coder_message(AC_CW_PROTO_MSG_T *pstMsg, AC_CW_PROTO_MSG_T *pstSrcMsg);
extern VOID ac_cw_msg_elem_coder_rawbytes (AC_CW_PROTO_MSG_T *pstMsg, UINT8 *pucBytes, UINT32 ulLen);
extern CHAR ac_cw_msg_elem_decoder_char (AC_CW_PROTO_MSG_T *pstMsg);
extern UINT16 ac_cw_msg_elem_decoder_short (AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_elem_decoder_long (AC_CW_PROTO_MSG_T *pstMsg);
extern CHAR* ac_cw_msg_elem_decoder_string (AC_CW_PROTO_MSG_T *pstMsg, UINT32 ulLen);
extern UINT8* ac_cw_msg_elem_decoder_rawbytes (AC_CW_PROTO_MSG_T *pstMsg, UINT32 ulLen);

extern INT32 ac_cw_random_int_in_range (INT32 iMin, INT32 iMax);
extern UINT32 ac_cw_get_seq_num (VOID);

extern UINT32	ac_cw_msg_broadcast(UINT16 usEvent, CHAR *pcMsg, UINT32 usMsgLen, UINT16 usPno);
extern UINT32	ac_cw_msg_send_ip(UINT16 usEvent, CHAR *pcMsg, UINT32 usMsgLen, UINT16 usPno, UINT8 *pucIp);
extern UINT32	ac_cw_msg_send(UINT16 usEvent, CHAR *pcMsg, UINT16 usMsgLen, TPID tReceiver, UINT32	ulUseOss);
extern UINT32	ac_cw_msg_recv(CHAR *pcMsg, UINT32 ulMsgLen, UINT8 *pucSrcIp);
extern UINT32 ac_cw_get_echoreq_vendor_specific (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstEchoreqVendorSpecific);
extern UINT32 ac_cw_get_wtp_event_request_vendor_specific_vap_wifistat (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32 ac_cw_get_wtp_event_request_vendor_specific_adhoc_bssid (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32 ac_cw_get_wtp_event_request_vendor_specific_vdev_maxpower (AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern int ac_cw_check_buff_ASC( char* pcBuff );	/* add by gwx 2014-4-29 for bug5326 */
extern UINT32	ac_cw_ac_set_wtpip( AC_CW_WTPINFO_T* pstWtp,
								AC_DEVM_WTPIP_CONFIG_T* pstWtpIpCfg,
								AC_DEVM_NAT_IP_CONFIG_T* pstNatIpCfg );

#endif /* _AC_CW_PUBLIC_H */
/******************************* 头文件结束 **********************************/
