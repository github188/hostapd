/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  数据库统一接口功能头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DEVM_PUBLIC_H
#define  _AC_DEVM_PUBLIC_H

/***************************DEVM 模块消息号定义*****************************/
#define ADHOC_IFID(ulWtpId, ulVdevId, ulAdhocId)		((ulAdhocId))
#define ENET_IFID(ulWtpId, ulEnetId)					(4 + (ulEnetId))
#define VAP_IFID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define VDEV_IFID(ulWtpId, ulVdevId)					(24 + (ulVdevId))

/* DEVM模块消息号定义 */
/* 标准接口消息号*/
#define AC_DEVM_IF_MAX    400        /* DEVM模块最大接口数*/
#define AC_DEVM_MAX_PORTALIP_NUM  	8 	/*获取portal ip地址的最大数目*/

#define AC_DEVM_GET_RADIUS_CONFIG_MSG                   	(EV_DEVM_BEGIN+1)	/* 获取AAA 配置*/
#define AC_DEVM_GET_AC_OWNCONFIG_MSG                    	(EV_DEVM_BEGIN+2)	/* 获取AC本设备配置*/
#define AC_DEVM_GET_AC_MOID_MSG						(EV_DEVM_BEGIN+3)	/* 获取AC MOID */
#define AC_DEVM_GET_WTPASSO_BYID_MSG				(EV_DEVM_BEGIN+4)	/* 根据AP ID获取AP-AC关联配置*/
#define AC_DEVM_GET_ACKEEPERCFG_MSG					(EV_DEVM_BEGIN+5)	/* 获取AC上行链路完整性检查配置*/
#define AC_DEVM_SET_ACUPLINKSTATE_MSG				(EV_DEVM_BEGIN+6)	/* 设置AC上行链路状态*/

#define AC_DEVM_GET_WTP_BYID_MSG                        		(EV_DEVM_BEGIN+11)	
#define AC_DEVM_GET_WTP_OWNCONFIG_MSG                   	(EV_DEVM_BEGIN+12)
#define AC_DEVM_GET_WTP_CONFIG_MSG                     	 	(EV_DEVM_BEGIN+13)
#define AC_DEVM_GET_BINDACID_MSG						(EV_DEVM_BEGIN+14)			
#define AC_DEVM_GET_CURACID_MSG						(EV_DEVM_BEGIN+15)	
#define AC_DEVM_GET_WTP_BYSN_MSG                        		(EV_DEVM_BEGIN+16)	/* 根据AP设备序列号获取AP配置信息*/

#define AC_DEVM_GET_IF_CONFIG_MSG                       		(EV_DEVM_BEGIN+21)
#define AC_DEVM_GET_VDEVLIST_CONFIG_MSG                 	(EV_DEVM_BEGIN+22)
#define AC_DEVM_GET_VDEVNEIGH_CONFIG_MSG                	(EV_DEVM_BEGIN+23)
#define AC_DEVM_GET_VDEV_MOID_MSG					(EV_DEVM_BEGIN+24)
#define AC_DEVM_GET_VDEV_BYID_MSG					(EV_DEVM_BEGIN+25)

#define AC_DEVM_GET_WTP_VDEVMAXTXPOWER_MSG		(EV_DEVM_BEGIN+29)	/* 获取所有无线设备的最大发射功率*/
#define AC_DEVM_GET_WTP_ADHOCBSSID_MSG				(EV_DEVM_BEGIN+30)	/* 获取所有回传模块的BSSID */
#define AC_DEVM_GET_VAP_CONFIG_MSG                      		(EV_DEVM_BEGIN+31)
#define AC_DEVM_GET_VAP_CONFIG_BYVDEV_MSG               (EV_DEVM_BEGIN+32)
#define AC_DEVM_GET_WTP_VAPBSSID_MSG                    	(EV_DEVM_BEGIN+33)
#define AC_DEVM_GET_WTP_VAPTRAFFICSTAT_MSG              	(EV_DEVM_BEGIN+34)
#define AC_DEVM_GET_VAP_MOID_MSG                        		(EV_DEVM_BEGIN+35)
#define AC_DEVM_GET_VAPID_BYBSSID_MSG				(EV_DEVM_BEGIN+36)
#define AC_DEVM_GET_VAP_CONFIG_BYWTP_MSG               	(EV_DEVM_BEGIN+37)	/* 获取WTP AP口配置*/
#define AC_DEVM_GET_ADHOC_CONFIG_BYWTP_MSG		(EV_DEVM_BEGIN+38)	/* 获取WTP ADHOC口配置*/
#define AC_DEVM_GET_WTP_VAPWIFISTAT_MSG				(EV_DEVM_BEGIN+39)	/* 获取VAP无线统计信息*/

#define AC_DEVM_ALLOCATE_WTPID_MSG					(EV_DEVM_BEGIN+40)	/* 分配一个空闲的WtpId (设备当前序列号为全0)*/
#define AC_DEVM_SET_WTP_OPSTATE_MSG                     	(EV_DEVM_BEGIN+41)
#define AC_DEVM_SET_SLAVEOBJ_OPSTATE_MSG                	(EV_DEVM_BEGIN+42)
#define AC_DEVM_SET_VDEV_OPSTATE_MSG                    	(EV_DEVM_BEGIN+43)
#define AC_DEVM_SET_VAP_OPSTATE_MSG                     	(EV_DEVM_BEGIN+44)
#define AC_DEVM_SET_WTP_ASSOSTATE_MSG				(EV_DEVM_BEGIN+45)
#define AC_DEVM_SET_VDEV_DYNPOWER_MSG				(EV_DEVM_BEGIN+46)	/* 更新无线模块当前动态发射功率值*/
#define AC_DEVM_SET_WTPIP_MSG							(EV_DEVM_BEGIN+47)	/* 设置指定AP设备的IP地址 */
#define AC_DEVM_GET_WTPIP_MSG						(EV_DEVM_BEGIN+48)	/* 获取指定AP设备的IP地址*/
#define AC_DEVM_GET_WTPID_BYIP_MSG					(EV_DEVM_BEGIN+49)	/* 根据WTP IP获取WTP ID */
#define AC_DEVM_SET_WTP_SN_MSG						(EV_DEVM_BEGIN+50)	/* 设置AP的序列号*/

#define AC_DEVM_GET_SNMPV2_CONFIG_MSG                   	(EV_DEVM_BEGIN+51)
#define AC_DEVM_GET_SNMPV3_CONFIG_MSG                   	(EV_DEVM_BEGIN+52)
#define AC_DEVM_GET_SNMPTRAP_CONFIG_MSG                   	(EV_DEVM_BEGIN+53)
#define AC_DEVM_GET_ACSWVERSION_MSG                   		(EV_DEVM_BEGIN+54)	/* 获取AC当前的软件版本号*/
#define AC_DEVM_SET_WTPSWUPDATE_MSG					(EV_DEVM_BEGIN+55)	/* AP 版本升级时, OMA调用本接口*/	
#define AC_DEVM_SET_WTPCFGUPDATE_MSG				(EV_DEVM_BEGIN+56)	/* AP配置修改时, OMA调用本接口*/
#define AC_DEVM_GET_ACASSOCSWVER_CONFIG_MSG		(EV_DEVM_BEGIN+57)	/* 获取AC支持的AP软件版本列表接口*/
#define AC_DEVM_GET_WTPSWVERSION_MSG				(EV_DEVM_BEGIN+58)	/* 获取指定AP的软件版本配置接口*/
#define AC_DEVM_SET_WTPCURSWVERSION_MSG			(EV_DEVM_BEGIN+59)	/* 设置AP当前软件版本号*/
#define AC_DEVM_GET_WTPCFGVERSION_MSG				(EV_DEVM_BEGIN+60)	/* 获取AP当前配置数据版本号*/


#define AC_DEVM_GET_ACSNTP_CONFIG_MSG                     	(EV_DEVM_BEGIN+61)
#define AC_DEVM_GET_WTPSNTP_CONFIG_MSG                  	(EV_DEVM_BEGIN+62)

#define AC_DEVM_GET_ACPORT_CONFIG_MSG                   	(EV_DEVM_BEGIN+71)
#define AC_DEVM_GET_ENET_CONFIG_BYWTP_MSG               	(EV_DEVM_BEGIN+72)	/* 获取WTP 物理网口配置*/
#define AC_DEVM_GET_ACBRIDGE_CONFIG_MSG				(EV_DEVM_BEGIN+73)	/* 获取AC桥配置*/
#define AC_DEVM_GET_ACIP_CONFIG_MSG					(EV_DEVM_BEGIN+74)	/* 获取AC端口IP地址配置*/
#define AC_DEVM_GET_L2WAN_CONFIG_MSG				(EV_DEVM_BEGIN+75)	/* 获取L2-WAN/FAT-LAN 桥配置*/
#define AC_DEVM_GET_L3WAN_CONFIG_MSG				(EV_DEVM_BEGIN+76)	/* 获取L3-WAN 桥配置*/
#define AC_DEVM_GET_ACPORT_BYID_MSG					(EV_DEVM_BEGIN+77)	/* 根据AC物理端口号获取指定端口配置*/
#define AC_DEVM_GET_L2WAN_FIRSTIP_CONFIG_MSG		(EV_DEVM_BEGIN+78)	/* 获取FATLAN/L2WAN 第一组IP */
#define AC_DEVM_GET_ACMSPORT_CONFIG_MSG				(EV_DEVM_BEGIN+79)	/* 2011-6-21 新增: 获取AC主备端口配置*/

#define AC_DEVM_GET_VLANGLOBAL_CONFIG_MSG			(EV_DEVM_BEGIN+81)	/* 获取VLAN全局配置*/
#define AC_DEVM_GET_VLAN_CONFIG_MSG                     	(EV_DEVM_BEGIN+82)	/* 获取VLAN配置*/
#define AC_DEVM_GET_VLANSSIDMAP_CONFIG_MSG			(EV_DEVM_BEGIN+83)	/* 获取SSID-VLAN映射配置*/
#define AC_DEVM_GET_VLANIFMAP_CONFIG_MSG                	(EV_DEVM_BEGIN+84)	/* 获取端口-VLAN映射配置*/
#define AC_DEVM_GET_VLANMACMAP_CONFIG_MSG              	(EV_DEVM_BEGIN+85)	/* 获取MAC-VLAN映射配置*/
#define AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_MSG	(EV_DEVM_BEGIN+86)	/* 获取MAC过滤策略配置*/
#define AC_DEVM_GET_VLANACCMAC_CONFIG_MSG              	(EV_DEVM_BEGIN+87)	/* 获取MAC过滤列表配置*/
/* 2009-11-5 pyy 新增*/
#define AC_DEVM_GET_VLANFORIF_CONFIG_MSG			(EV_DEVM_BEGIN+88)	/* 获取VLAN在各端口上的启用情况*/

#define AC_DEVM_GET_IGMPSNOOP_CONFIG_MSG                	(EV_DEVM_BEGIN+91)
#define AC_DEVM_GET_IGMPPROXY_CONFIG_MSG                	(EV_DEVM_BEGIN+92)

#define AC_DEVM_GET_ROUTESTATIC_CONFIG_MSG              	(EV_DEVM_BEGIN+101)
#define AC_DEVM_GET_RIPGLOBAL_CONFIG_MSG                	(EV_DEVM_BEGIN+102)
#define AC_DEVM_GET_RIPNOTIFYIP_CONFIG_MSG              	(EV_DEVM_BEGIN+103)

#define AC_DEVM_GET_FWGLOBAL_CONFIG_MSG                 	(EV_DEVM_BEGIN+121)
#define AC_DEVM_GET_FWRULE_CONFIG_MSG                   	(EV_DEVM_BEGIN+122)
#define AC_DEVM_GET_NATGLOBAL_CONFIG_MSG                 	(EV_DEVM_BEGIN+123)
#define AC_DEVM_GET_NAT_CONFIG_MSG                      		(EV_DEVM_BEGIN+124)
#define AC_DEVM_GET_P2P_CONFIG_MSG                      		(EV_DEVM_BEGIN+125)

#define AC_DEVM_GET_IDSRULE_CONFIG_MSG                  	(EV_DEVM_BEGIN+141)
#define AC_DEVM_GET_IDSTRY_CONFIG_MSG                   	(EV_DEVM_BEGIN+142)

#define AC_DEVM_GET_STADHCPGLOBAL_CONFIG_MSG          (EV_DEVM_BEGIN+151)
#define AC_DEVM_GET_STADHCPSTATICIP_CONFIG_MSG		(EV_DEVM_BEGIN+152)
#define AC_DEVM_GET_STADHCPDYNIP_CONFIG_MSG            	(EV_DEVM_BEGIN+153)
#define AC_DEVM_GET_APDHCPGLOBAL_CONFIG_MSG          	(EV_DEVM_BEGIN+154)
#define AC_DEVM_GET_APDHCPSTATICIP_CONFIG_MSG		(EV_DEVM_BEGIN+155)
#define AC_DEVM_GET_APDHCPDYNIP_CONFIG_MSG            (EV_DEVM_BEGIN+156)

#define AC_DEVM_GET_QOSGLOBAL_CONFIG_MSG                	(EV_DEVM_BEGIN+161)
#define AC_DEVM_GET_QOSUSRDFT_CONFIG_MSG                	(EV_DEVM_BEGIN+162)
#define AC_DEVM_GET_QOSVLAN_CONFIG_MSG                  	(EV_DEVM_BEGIN+163)
#define AC_DEVM_GET_QOSSSID_CONFIG_MSG                  	(EV_DEVM_BEGIN+164)

#define AC_DEVM_GET_ALARMFILTER_CONFIG_MSG               (EV_DEVM_BEGIN+171)
#define AC_DEVM_GET_PERFCOUNTER_CONFIG_MSG              (EV_DEVM_BEGIN+172)
#define AC_DEVM_GET_SWSVR_CONFIG_MSG				(EV_DEVM_BEGIN+173)	
#define AC_DEVM_GET_CFG_VERSION_MSG					(EV_DEVM_BEGIN+174)	
#define AC_DEVM_GET_ACALARMTHRESHOLD_CONFIG_MSG	(EV_DEVM_BEGIN+175)	

#define AC_DEVM_GET_PPPOESERVER_CONFIG_MSG			(EV_DEVM_BEGIN+191)		/* 获取PPPoE配置*/

#define AC_DEVM_GET_MACSERVER_CONFIG_MSG			(EV_DEVM_BEGIN+195)		/* 获取MAC Server配置*/

#define AC_DEVM_GET_PORTAL_CONFIG_MSG				(EV_DEVM_BEGIN+201)		/* 获取WEB认证全局配置*/
#define AC_DEVM_GET_WHITELIST_CONFIG_MSG			(EV_DEVM_BEGIN+202)		/* 获取WEB认证白名单配置*/
#define AC_DEVM_GET_USERADDRBIND_CONFIG_MSG		(EV_DEVM_BEGIN+203)		/* 获取用户名地址绑定配置*/
#define AC_DEVM_GET_FREEADDR_CONFIG_MSG				(EV_DEVM_BEGIN+204)		/* 获取免认证地址列表配置*/
#define AC_DEVM_GET_FREESSID_CONFIG_MSG				(EV_DEVM_BEGIN+205)		/* 获取免认证SSID列表配置*/
#define AC_DEVM_GET_FREEVLAN_CONFIG_MSG				(EV_DEVM_BEGIN+206)		/* 获取免认证VLAN列表配置*/
#define AC_DEVM_GET_FREEMAC_CONFIG_MSG				(EV_DEVM_BEGIN+207)		/* 获取免认证IP列表配置*/
#define AC_DEVM_GET_FREEGLOBAL_CONFIG_MSG			(EV_DEVM_BEGIN+208)		/* 获取全局免认证配置*/
#define AC_DEVM_GET_WHITEURLLIST_CONFIG_MSG			(EV_DEVM_BEGIN+209)		/* 获取白名单URL 配置*/

#define AC_DEVM_GET_LOG_CONFIG_MSG					(EV_DEVM_BEGIN+211)		/* 获取日志配置*/
#define AC_DEVM_GET_LOGSVR_CONFIG_MSG				(EV_DEVM_BEGIN+212)		/* 获取日志服务器配置*/

#define AC_DEVM_GET_WAPIAS_CONFIG_MSG				(EV_DEVM_BEGIN+231)		/* 获取WAPI AS服务器配置*/
#define AC_DEVM_GET_WAPI_CONFIG_MSG					(EV_DEVM_BEGIN+232)		/* 获取WAPI参数配置*/
#define AC_DEVM_GET_WAPICERTFILE_CONFIG_MSG			(EV_DEVM_BEGIN+233)		/* 获取WAPI证书配置*/
#define AC_DEVM_GET_VAP_OPSTATE_MSG					(EV_DEVM_BEGIN+234)		/* 获取VAP状态*/

#define AC_DEVM_GET_ACDEVICE_ABSTRACT_MSG			(EV_DEVM_BEGIN+241)		/* 获取AC设备摘要信息接口 */

#define AC_DEVM_ADD_UNREGWTP_MSG					(EV_DEVM_BEGIN+251)		/* 新增AC检测到的未注册AP */
#define AC_DEVM_DEL_UNREGWTP_MSG					(EV_DEVM_BEGIN+252)		/* 删除AC检测到的未注册AP */
#define AC_DEVM_GET_WTP_TARGETVERSION_MSG			(EV_DEVM_BEGIN+253)		/* 获取指定AP的目标软件版本*/

#define AC_DEVM_GET_MSSETUP_CONFIG_MSG				(EV_DEVM_BEGIN+261)		/* 获取主备配置相关接口*/
#define AC_DEVM_SET_MSSTATE_MSG						(EV_DEVM_BEGIN+262)		/* 设置备份AC运行状态*/

#define AC_DEVM_GET_ENET_MOID_MSG					(EV_DEVM_BEGIN+271)		/* 获取以太网口的MOID */

/* 2010-6-17 pyy 新增: 定时关闭VAP功能 */
#define AC_DEVM_GET_VAPADMINSTATE_MSG				(EV_DEVM_BEGIN+281)		/* 获取指定AP的所有VAP管理状态*/
#define AC_DEVM_GET_APACL_MSG						(EV_DEVM_BEGIN+282)		/* 获取AP访问策略配置*/
#define AC_DEVM_GET_SSIDRADIUSSERVERS_MSG			(EV_DEVM_BEGIN+283)		/* 根据VAP获取AAA服务器信息*/
#define AC_DEVM_GET_STARADIUSSERVERS_MSG			(EV_DEVM_BEGIN+284)		/* 根据STA MAC 获取AAA服务器信息*/
#define AC_DEVM_GET_AUTHSERVERS_MSG					(EV_DEVM_BEGIN+285)		/* 获取鉴权服务器列表*/
#define AC_DEVM_GET_ACCTSERVERS_MSG					(EV_DEVM_BEGIN+286)		/* 获取计费服务器列表*/
#define AC_DEVM_GET_ACVRRPFIRSTIP_MSG				(EV_DEVM_BEGIN+287)

/* 2010-12-28 pyy 新增*/
#define AC_DEVM_SET_VAPBSSID_MSG						(EV_DEVM_BEGIN+291)		/* 设置VAP BSSID */
#define AC_DEVM_SET_VAPTRAFFICSTAT_MSG				(EV_DEVM_BEGIN+292)		/* 设置VAP 流量统计*/
#define AC_DEVM_SET_VAPWIFISTAT_MSG					(EV_DEVM_BEGIN+293)		/* 设置VAP WIFI统计*/
#define AC_DEVM_SET_VDEVMAXPOWER_MSG				(EV_DEVM_BEGIN+294)		/* 设置无线设备最大发射功率*/
#define AC_DEVM_SET_ADHOCBSSID_MSG					(EV_DEVM_BEGIN+295)		/* 设置ADHOC BSSID */
/* 2011-01-25*/
#define AC_DEVM_SET_WTP_MAC_MSG						(EV_DEVM_BEGIN+301)		/* 设置AP设备MAC地址*/
#define AC_DEVM_GET_WTPMAC_MSG						(EV_DEVM_BEGIN+302)		/* 获取AP设备MAC地址列表*/

#define AC_DEVM_GET_WTPSNTP_CONFIG_BYWTP_MSG         	(EV_DEVM_BEGIN+303)
#define AC_DEVM_GET_WTP_MOID_MSG						(EV_DEVM_BEGIN+304)

/* add by gwx 2012-7-11 for bug1292 */
#define AC_DEVM_GET_MANAGEIP_MSG				(EV_DEVM_BEGIN+305)		/*获取trap管理ip消息*/

#define AC_DEVM_IS_ACTIVE_MSG							(EV_DEVM_BEGIN+306)		/* 本机是否Active */
#define AC_DEVM_SET_WTPSRCADDR_MSG					(EV_DEVM_BEGIN+307)		/* 设置AP消息的源IP和源端口号 add by gwx 2013-4-7 for task668*/
#define AC_DEVM_GET_WTPIDBYPORTANDIP_MSG			(EV_DEVM_BEGIN+308)		/* 根据源端口号和IP获取WtpId add by gwx 2013-4-7 for task668*/
/* add by gwx 2013-8-16 for 企业网先本地后集中需求*/
#define AC_DEVM_GET_PORTALIP_MSG						(EV_DEVM_BEGIN+309)	
/* add by gwx 2014-2-25 for task1265 */
#define AC_DEVM_SET_WTPPRODUCTTYPE_MSG				(EV_DEVM_BEGIN+310)		/*设置AP产品类型*/	

/* add by gwx 2014-8-7 */
#define AC_DEVM_SET_WTPCURCHANNELLIST_MSG			(EV_DEVM_BEGIN+311)		/* 设置AP当前信道*/

/* add by ght 2014-8-13 */
#define AC_DEVM_GET_ACLINKIP_MSG                  (EV_DEVM_BEGIN+312)		/* 获取AC LINK IP*/


#define AC_DEVM_POWERAC_OK_REQ_MSG					(EV_DEVM_BEGIN+499)
#define AC_DEVM_POWERAC_OK_RSP_MSG					(EV_DEVM_BEGIN+500)


/* 触发消息号*/
#define AC_DEVM_AC_UPDATE_IND_MSG                         	(EV_DEVM_BEGIN+501)
#define AC_DEVM_AC_OWNCONFIG_UPDATE_IND_MSG           (EV_DEVM_BEGIN+502)
#define AC_DEVM_RADIUS_CONFIG_UPDATE_IND_MSG          	(EV_DEVM_BEGIN+503)
#define AC_DEVM_ACKEEPERCFG_UPDATE_IND_MSG			(EV_DEVM_BEGIN+504)	

#define AC_DEVM_WTP_ADD_IND_MSG                         		(EV_DEVM_BEGIN+511)
#define AC_DEVM_WTP_DEL_IND_MSG                         		(EV_DEVM_BEGIN+512)
#define AC_DEVM_WTP_UPDATE_IND_MSG                      		(EV_DEVM_BEGIN+513)
#define AC_DEVM_WTP_SETSRCADDR_MSG					(EV_DEVM_BEGIN+514) /* add by gwx 2013-4-7 for task668 */

#define AC_DEVM_VDEV_ADD_IND_MSG                        		(EV_DEVM_BEGIN+521)
#define AC_DEVM_VDEV_DEL_IND_MSG                        		(EV_DEVM_BEGIN+522)
#define AC_DEVM_VDEV_UPDATE_IND_MSG                     	(EV_DEVM_BEGIN+523)
#define AC_DEVM_VDEVWIDS_UPDATE_IND_MSG                 	(EV_DEVM_BEGIN+524)
#define AC_DEVM_VDEVRRM_UPDATE_IND_MSG                  	(EV_DEVM_BEGIN+525)
#define AC_DEVM_VDEVNEIGH_ADD_IND_MSG                   	(EV_DEVM_BEGIN+526)
#define AC_DEVM_VDEVNEIGH_DEL_IND_MSG                   	(EV_DEVM_BEGIN+527)
#define AC_DEVM_VDEVNEIGH_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+528)
#define AC_DEVM_IF_ADD_IND_MSG                          		(EV_DEVM_BEGIN+529)
#define AC_DEVM_IF_DEL_IND_MSG                          		(EV_DEVM_BEGIN+530)
#define AC_DEVM_IF_UPDATE_IND_MSG                       		(EV_DEVM_BEGIN+531)

#define AC_DEVM_VAP_ADD_IND_MSG                         		(EV_DEVM_BEGIN+541)
#define AC_DEVM_VAP_DEL_IND_MSG                         		(EV_DEVM_BEGIN+542)
#define AC_DEVM_VAP_UPDATE_IND_MSG                      		(EV_DEVM_BEGIN+543)
#define AC_DEVM_ADHOC_ADD_IND_MSG                         	(EV_DEVM_BEGIN+544)
#define AC_DEVM_ADHOC_DEL_IND_MSG                         	(EV_DEVM_BEGIN+545)
#define AC_DEVM_ADHOC_UPDATE_IND_MSG                      	(EV_DEVM_BEGIN+546)
#define AC_DEVM_VAPSSID_UPDATE_IND_MSG				(EV_DEVM_BEGIN+547)
#define AC_DEVM_L2WVAP_DEL_IND_MSG					(EV_DEVM_BEGIN+548)

#define AC_DEVM_WTP_OPSTATE_CHG_IND_MSG                 	(EV_DEVM_BEGIN+551)
#define AC_DEVM_WTP_MATE_OPSTATE_CHG_IND_MSG		(EV_DEVM_BEGIN+552)
#define AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG              (EV_DEVM_BEGIN+553)
#define AC_DEVM_VAP_OPSTATE_CHG_IND_MSG                 	(EV_DEVM_BEGIN+554)
#define AC_DEVM_VAP_BSSID_CHG_IND_MSG                   	(EV_DEVM_BEGIN+555)

#define AC_DEVM_SNMPV2_ADD_IND_MSG                      	(EV_DEVM_BEGIN+561)
#define AC_DEVM_SNMPV2_DEL_IND_MSG                      		(EV_DEVM_BEGIN+562)
#define AC_DEVM_SNMPV2_UPDATE_IND_MSG                      	(EV_DEVM_BEGIN+563)
#define AC_DEVM_SNMPV3_ADD_IND_MSG                      	(EV_DEVM_BEGIN+564)
#define AC_DEVM_SNMPV3_DEL_IND_MSG                      		(EV_DEVM_BEGIN+565)
#define AC_DEVM_SNMPV3_UPDATE_IND_MSG                      	(EV_DEVM_BEGIN+566)
#define AC_DEVM_SNMPTRAP_ADD_IND_MSG                      	(EV_DEVM_BEGIN+567)
#define AC_DEVM_SNMPTRAP_DEL_IND_MSG                      	(EV_DEVM_BEGIN+568)
#define AC_DEVM_SNMPTRAP_UPDATE_IND_MSG				(EV_DEVM_BEGIN+569)

#define AC_DEVM_ACSNTPCONFIG_UPDATE_IND_MSG		(EV_DEVM_BEGIN+571)
#define AC_DEVM_WTPSNTPCONFIG_UPDATE_IND_MSG		(EV_DEVM_BEGIN+572)

#define AC_DEVM_ACPORT_ADD_IND_MSG                      		(EV_DEVM_BEGIN+581)
#define AC_DEVM_ACPORT_DEL_IND_MSG                      		(EV_DEVM_BEGIN+582)
#define AC_DEVM_ACPORT_UPDATE_IND_MSG                   	(EV_DEVM_BEGIN+583)
#define AC_DEVM_WANIFNAME_CONFIG_UPDATE_IND_MSG	(EV_DEVM_BEGIN+584)
#define AC_DEVM_WTPENET_ADD_IND_MSG					(EV_DEVM_BEGIN+585)
#define AC_DEVM_WTPENET_DEL_IND_MSG					(EV_DEVM_BEGIN+586)
#define AC_DEVM_WTPENET_UPDATE_IND_MSG				(EV_DEVM_BEGIN+587)
#define AC_DEVM_L2WAN_UPDATE_MSG					(EV_DEVM_BEGIN+588)	
#define AC_DEVM_L3WAN_UPDATE_MSG					(EV_DEVM_BEGIN+589)	
#define AC_DEVM_ACBR1IP_UPDATE_MSG					(EV_DEVM_BEGIN+590)	

#define AC_DEVM_VLANGLOBAL_UPDATE_IND_MSG			(EV_DEVM_BEGIN+591)

#define AC_DEVM_VLAN_ADD_IND_MSG                        		(EV_DEVM_BEGIN+592)
#define AC_DEVM_VLAN_DEL_IND_MSG                        		(EV_DEVM_BEGIN+593)
#define AC_DEVM_VLAN_UPDATE_IND_MSG                     	(EV_DEVM_BEGIN+594)

#define AC_DEVM_VLANSSIDMAP_ADD_IND_MSG                   	(EV_DEVM_BEGIN+595)
#define AC_DEVM_VLANSSIDMAP_DEL_IND_MSG                   	(EV_DEVM_BEGIN+596)
#define AC_DEVM_VLANSSIDMAP_UPDATE_IND_MSG			(EV_DEVM_BEGIN+597)

#define AC_DEVM_VLANIFMAP_ADD_IND_MSG                   	(EV_DEVM_BEGIN+598)
#define AC_DEVM_VLANIFMAP_DEL_IND_MSG                   	(EV_DEVM_BEGIN+599)
#define AC_DEVM_VLANIFMAP_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+600)

#define AC_DEVM_VLANMACMAP_ADD_IND_MSG                  	(EV_DEVM_BEGIN+601)
#define AC_DEVM_VLANMACMAP_DEL_IND_MSG                 	(EV_DEVM_BEGIN+602)
#define AC_DEVM_VLANMACMAP_UPDATE_IND_MSG			(EV_DEVM_BEGIN+603)

#define AC_DEVM_VLANACCMACPOLICY_ADD_IND_MSG		(EV_DEVM_BEGIN+604)
#define AC_DEVM_VLANACCMACPOLICY_DEL_IND_MSG          (EV_DEVM_BEGIN+605)
#define AC_DEVM_VLANACCMACPOLICY_UPDATE_IND_MSG    (EV_DEVM_BEGIN+606)

#define AC_DEVM_VLANACCMAC_ADD_IND_MSG                  	(EV_DEVM_BEGIN+607)
#define AC_DEVM_VLANACCMAC_DEL_IND_MSG                  	(EV_DEVM_BEGIN+608)
#define AC_DEVM_VLANACCMAC_UPDATE_IND_MSG			(EV_DEVM_BEGIN+609)

#define AC_DEVM_IGMPSNOOP_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+621)
#define AC_DEVM_IGMPPROXY_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+622)

#define AC_DEVM_ROUTESTATIC_ADD_IND_MSG                 	(EV_DEVM_BEGIN+631)
#define AC_DEVM_ROUTESTATIC_DEL_IND_MSG                 	(EV_DEVM_BEGIN+632)
#define AC_DEVM_ROUTESTATIC_UPDATE_IND_MSG              	(EV_DEVM_BEGIN+633)
#define AC_DEVM_RIPGLOBAL_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+634)
#define AC_DEVM_RIPNOTIFYIP_ADD_IND_MSG                 	(EV_DEVM_BEGIN+635)
#define AC_DEVM_RIPNOTIFYIP_DEL_IND_MSG                 	(EV_DEVM_BEGIN+636)
#define AC_DEVM_RIPNOTIFYIP_UPDATE_IND_MSG              	(EV_DEVM_BEGIN+637)

#define AC_DEVM_FWGLOBAL_UPDATE_IND_MSG                 	(EV_DEVM_BEGIN+661)
#define AC_DEVM_FWRULE_ADD_IND_MSG                      	(EV_DEVM_BEGIN+662)
#define AC_DEVM_FWRULE_DEL_IND_MSG                      		(EV_DEVM_BEGIN+663)
#define AC_DEVM_FWRULE_UPDATE_IND_MSG                   	(EV_DEVM_BEGIN+664)
#define AC_DEVM_NATGLOBAL_UPDATE_IND_MSG                 	(EV_DEVM_BEGIN+665)
#define AC_DEVM_NAT_ADD_IND_MSG                         		(EV_DEVM_BEGIN+666)
#define AC_DEVM_NAT_DEL_IND_MSG                        		(EV_DEVM_BEGIN+667)
#define AC_DEVM_NAT_UPDATE_IND_MSG                      		(EV_DEVM_BEGIN+668)
#define AC_DEVM_P2P_UPDATE_IND_MSG                      		(EV_DEVM_BEGIN+669)

#define AC_DEVM_IDSRULE_UPDATE_IND_MSG                  	(EV_DEVM_BEGIN+691)
#define AC_DEVM_IDSSTRY_UPDATE_IND_MSG                  	(EV_DEVM_BEGIN+692)

#define AC_DEVM_STADHCPGLOBAL_UPDATE_IND_MSG               	(EV_DEVM_BEGIN+701)

#define AC_DEVM_STADHCPSTATICIP_ADD_IND_MSG                	(EV_DEVM_BEGIN+702)
#define AC_DEVM_STADHCPSTATICIP_DEL_IND_MSG                	(EV_DEVM_BEGIN+703)
#define AC_DEVM_STADHCPSTATICIP_UPDATE_IND_MSG             	(EV_DEVM_BEGIN+704)

#define AC_DEVM_STADHCPDYNIP_ADD_IND_MSG                   	(EV_DEVM_BEGIN+705)
#define AC_DEVM_STADHCPDYNIP_DEL_IND_MSG                   	(EV_DEVM_BEGIN+706)
#define AC_DEVM_STADHCPDYNIP_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+707)

#define AC_DEVM_APDHCPGLOBAL_UPDATE_IND_MSG               	(EV_DEVM_BEGIN+710)

#define AC_DEVM_APDHCPSTATICIP_ADD_IND_MSG                	(EV_DEVM_BEGIN+711)
#define AC_DEVM_APDHCPSTATICIP_DEL_IND_MSG                	(EV_DEVM_BEGIN+712)
#define AC_DEVM_APDHCPSTATICIP_UPDATE_IND_MSG             	(EV_DEVM_BEGIN+713)

#define AC_DEVM_APDHCPDYNIP_ADD_IND_MSG                   		(EV_DEVM_BEGIN+714)
#define AC_DEVM_APDHCPDYNIP_DEL_IND_MSG                   		(EV_DEVM_BEGIN+715)
#define AC_DEVM_APDHCPDYNIP_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+716)

#define AC_DEVM_QOSGLOBAL_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+731)

#define AC_DEVM_QOSUSRDFT_UPDATE_IND_MSG                	(EV_DEVM_BEGIN+732)

#define AC_DEVM_QOSVLAN_ADD_IND_MSG                     	(EV_DEVM_BEGIN+733)
#define AC_DEVM_QOSVLAN_DEL_IND_MSG                     	(EV_DEVM_BEGIN+734)
#define AC_DEVM_QOSVLAN_UPDATE_IND_MSG                  	(EV_DEVM_BEGIN+735)

#define AC_DEVM_QOSSSID_ADD_IND_MSG                    	 	(EV_DEVM_BEGIN+736)
#define AC_DEVM_QOSSSID_DEL_IND_MSG                     		(EV_DEVM_BEGIN+737)
#define AC_DEVM_QOSSSID_UPDATE_IND_MSG                  	(EV_DEVM_BEGIN+738)

#define AC_DEVM_ALARMFILTER_ADD_IND_MSG                    	(EV_DEVM_BEGIN+761)
#define AC_DEVM_ALARMFILTER_DEL_IND_MSG                     (EV_DEVM_BEGIN+762)
#define AC_DEVM_ALARMFILTER_UPDATE_IND_MSG               (EV_DEVM_BEGIN+763)		/* 告警表发生变化时通知oma */

#define AC_DEVM_PERFCOUNTER_ADD_IND_MSG                 	(EV_DEVM_BEGIN+764)
#define AC_DEVM_PERFCOUNTER_DEL_IND_MSG                 	(EV_DEVM_BEGIN+765)
#define AC_DEVM_PERFCOUNTER_UPDATE_IND_MSG              (EV_DEVM_BEGIN+766)		/* *性能表发生变化时通知oma */

#define AC_DEVM_ACALARMTHRESHOLD_UPDATE_IND_MSG    (EV_DEVM_BEGIN+768)

#define AC_DEVM_PPPOESERVER_UPDATE_IND_MSG			(EV_DEVM_BEGIN+791)

#define AC_DEVM_MACSERVER_UPDATE_IND_MSG			(EV_DEVM_BEGIN+795)

#define AC_DEVM_PORTAL_UPDATE_IND_MSG				(EV_DEVM_BEGIN+801)	

#define AC_DEVM_WHITELIST_ADD_IND_MSG				(EV_DEVM_BEGIN+802)	
#define AC_DEVM_WHITELIST_DEL_IND_MSG				(EV_DEVM_BEGIN+803)	
#define AC_DEVM_WHITELIST_UPDATE_IND_MSG			(EV_DEVM_BEGIN+804)	

#define AC_DEVM_USERADDRBIND_ADD_IND_MSG			(EV_DEVM_BEGIN+805)	
#define AC_DEVM_USERADDRBIND_DEL_IND_MSG			(EV_DEVM_BEGIN+806)	
#define AC_DEVM_USERADDRBIND_UPDATE_IND_MSG		(EV_DEVM_BEGIN+807)	

/* 免认证IP变化消息*/
#define AC_DEVM_FREEADDR_ADD_IND_MSG				(EV_DEVM_BEGIN+808)	
#define AC_DEVM_FREEADDR_DEL_IND_MSG				(EV_DEVM_BEGIN+809)	
#define AC_DEVM_FREEADDR_UPDATE_IND_MSG				(EV_DEVM_BEGIN+810)	

#define AC_DEVM_FREESSID_ADD_IND_MSG					(EV_DEVM_BEGIN+811)	
#define AC_DEVM_FREESSID_DEL_IND_MSG					(EV_DEVM_BEGIN+812)	
#define AC_DEVM_FREESSID_UPDATE_IND_MSG				(EV_DEVM_BEGIN+813)	

#define AC_DEVM_FREEVLAN_ADD_IND_MSG				(EV_DEVM_BEGIN+814)	
#define AC_DEVM_FREEVLAN_DEL_IND_MSG					(EV_DEVM_BEGIN+815)	
#define AC_DEVM_FREEVLAN_UPDATE_IND_MSG				(EV_DEVM_BEGIN+816)	

/* 免认证MAC变化消息*/
#define AC_DEVM_FREEMAC_ADD_IND_MSG					(EV_DEVM_BEGIN+817)	
#define AC_DEVM_FREEMAC_DEL_IND_MSG					(EV_DEVM_BEGIN+818)	
#define AC_DEVM_FREEMAC_UPDATE_IND_MSG				(EV_DEVM_BEGIN+819)	

/* 全局免认证开关变更消息*/
#define AC_DEVM_FREEGLOBAL_UPDATE_IND_MSG			(EV_DEVM_BEGIN+820)	

/* 白名单URL变更通知消息*/
#define AC_DEVM_WHITEURL_ADD_IND_MSG				(EV_DEVM_BEGIN+821)	
#define AC_DEVM_WHITEURL_DEL_IND_MSG				(EV_DEVM_BEGIN+822)	
#define AC_DEVM_WHITEURL_UPDATE_IND_MSG				(EV_DEVM_BEGIN+823)	

#define AC_DEVM_LOG_UPDATE_IND_MSG					(EV_DEVM_BEGIN+821)		
#define AC_DEVM_LOGSVR_UPDATE_IND_MSG				(EV_DEVM_BEGIN+822)

#define AC_DEVM_WAPIAS_UPDATE_IND_MSG				(EV_DEVM_BEGIN+841)

#define AC_DEVM_WTPASSO_UPDATE_IND_MSG				(EV_DEVM_BEGIN+851)
#define AC_DEVM_WTPASSO_DEL_IND_MSG					(EV_DEVM_BEGIN+852)

/* 主备配置变更通知消息*/
#define AC_DEVM_MSSETUP_UPDATE_IND_MSG				(EV_DEVM_BEGIN+861)

#define AC_DEVM_AUTHSERVERS_ADD_IND_MSG				(EV_DEVM_BEGIN+871)		/* 	鉴权服务器新增通知*/
#define AC_DEVM_AUTHSERVERS_DEL_IND_MSG				(EV_DEVM_BEGIN+872)		/*	鉴权服务器删除通知*/
#define AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG			(EV_DEVM_BEGIN+873)		/*	鉴权服务器修改通知*/
#define AC_DEVM_ACCTSERVERS_ADD_IND_MSG				(EV_DEVM_BEGIN+874)		/*	计费服务器新增通知*/
#define AC_DEVM_ACCTSERVERS_DEL_IND_MSG				(EV_DEVM_BEGIN+875)		/*	计费服务器删除通知*/
#define AC_DEVM_ACCTSERVERS_UPDATE_IND_MSG			(EV_DEVM_BEGIN+876)		/*	计费服务器修改通知*/

/* 2011-6-21 AC主备功能修改*/
#define AC_DEVM_ACUPLINK_UP_IND_MSG					(EV_DEVM_BEGIN+881)		/* AC上行链路恢复通知*/
#define AC_DEVM_ACUPLINK_DOWN_IND_MSG				(EV_DEVM_BEGIN+882)		/* AC上行链路故障通知*/

/* add by gwx 2012-7-11 for bug1292 */
#define AC_DEVM_MANAGEIP_UPDATE_IND_MSG			(EV_DEVM_BEGIN+883)		/* trap管理ip变化通知*/

/* add by gwx 2014-6-3 for 锐捷一键故障收集*/
#define AC_DEVM_GEN_DHCP_ALLOCATEINFO_REQ (EV_DEVM_BEGIN + 884)
#define AC_DEVM_GEN_DHCP_ALLOCATEINFO_RSP (EV_DEVM_BEGIN + 885)


/******************************************************************************/

#define AC_IF_NUM_MAX_PER_WTP       	4           /* 每个WTP上的最大接口数 */
#define AC_VDEV_NUM_MAX_PER_WTP		4          /* 每个WTP上的最大无线设备数 */
#define AC_VAP_NUM_MAX_PER_IF       	16          /* 每个接口上允许创建的最大VAP数 */
#define AC_ADHOC_NUM_MAX_PER_IF		4		/* 每个接口上允许创建的最大ADHOC数 */

#define AC_VAP_NUM_MAX_PER_WTP  		(AC_IF_NUM_MAX_PER_WTP*AC_VAP_NUM_MAX_PER_IF)       	/* 每个WTP上的最大VAP数 */
#define AC_ADHOC_NUM_MAX_PER_WTP  	(AC_IF_NUM_MAX_PER_WTP*AC_ADHOC_NUM_MAX_PER_IF)      	 /* 每个WTP上的最大ADHOC数 */
#define AC_ENET_NUM_MAX_PER_WTP		2	/* 每个WTP上的有线物理端口数量*/

#define AC_BIND_AC_NUM_MAX          		8           /* 每个AP最大绑定的AC数 */

/* 对象状态 */
#define AC_OPSTATE_NORMAL           		0        /* 正常 */
#define AC_OPSTATE_FAULT            		1        /* 故障 */

/* VAP对象状态原因码 */
#define AC_VAPSTATE_REASON_LINK     	0       /* AC与WTP之间的链路状态变化引起VAP状态更新 */
#define AC_VAPSTATE_REASON_ADMIN    	1       /* VAP管理状态变化引起VAP状态更新 */

#define AC_ADMINSTATE_ENABLE        		0        /* 启用 */
#define AC_ADMINSTATE_DISABLE       		1        /* 禁用 */

#define AC_DEVM_IFNAME_LEN          		16       /* 接口名长度 */

/* 网络验证类型定义 */
#define AC_DEVM_AUTH_AUTO      		0
#define AC_DEVM_AUTH_OPEN       	1
#define AC_DEVM_AUTH_SHARE      	2
#define AC_DEVM_AUTH_WPAPSK     	3
#define AC_DEVM_AUTH_WPA        		4
#define AC_DEVM_AUTH_MAC        		5
#define AC_DEVM_AUTH_WAPI      		6

/* 数据加密类型定义 */
#define AC_DEVM_ENCRYPT_DISABLE 	0
#define AC_DEVM_ENCRYPT_WEP   		1
#define AC_DEVM_ENCRYPT_TKIP    	2
#define AC_DEVM_ENCRYPT_AES    	3
#define AC_DEVM_ENCRYPT_SMS4    	4

/* 是否启用802.1x认证取值定义 */
#define AC_DEVM_8021X_DISABLE	0
#define AC_DEVM_8021X_ENABLE	1

/* VAP 管理状态*/
#define AC_DEVM_ADMINSTATE_ENABLE		0
#define AC_DEVM_ADMINSTATE_DISABLE		1

#define AC_DEVM_CAPWAP_LINK_STATE_UNKNOWN		0
#define AC_DEVM_CAPWAP_LINK_STATE_NORMAL		1
#define AC_DEVM_CAPWAP_LINK_STATE_FAULT			2
#define AC_DEVM_CAPWAP_LINK_KEEPSTATE_FAULT		3	/* 上行链路故障 */

/* AC桥ID宏定义*/
#define AC_BRIDGE_ID_FITLAN		0
#define AC_BRIDGE_ID_L2WAN		1
#define AC_BRIDGE_ID_L3WAN		3

/* AC桥名称宏定义*/
#define AC_BRIDGE_NAME_FITLAN	"br0"
#define AC_BRIDGE_NAME_L2WAN	"br1"
#define AC_BRIDGE_NAME_L3WAN	"br2"

/* AC桥最大IP地址数目宏定义*/
#define AC_BRIDGE_FITLAN_IPNUM_MAX	8
#define AC_BRIDGE_FATLAN_IPNUM_MAX	32
#define AC_BRIDGE_L2WAN_IPNUM_MAX	8
#define AC_BRIDGE_L3WAN_IPNUM_MAX	8

/* AC最大物理端口数*/
#define AC_PORT_NUM_MAX	16
   

/******************************DEVM接口相关结构体定义******************************/
/******************************************************************************/
/* 数据结构定义开始*/
/* 其它应用程序询问powerac的状态*/
typedef struct 
{
	char MyPname[32];	/* 本应用程序名称*/
} AC_DEVM_POWERAC_OK_REQ_T;


/*2009-3-5 AC2.0 修改*/
/* 负荷均衡参数结构体*/
typedef struct
{
	UINT32	ulLbUserNumSwitch;	/* 用户数均衡开关控制0：禁用	1：启用 */
	UINT32	ulUserNumPermitted;	/* 用户数 均衡启动门限*/
	UINT32	ulUserNumOffsetThreshold;		/* 用户数目差值*/
	UINT32	ulUserNumDynamic;				/* 用户数动态负荷均衡*/
	UINT32	ulLbUserQosSwitch;	/* 0：禁用	1：启用 */
	UINT32 	ulBandMax;          	/* 最大QOS需求上下行带宽 */
	UINT32	ulUserQosOffsetThreshold;		/* 用户QOS差值*/
	UINT32 	ulChaUtiSwitch ;		/*基于信道利用率的负荷均衡开关，0：OFF；1：ON*/
	UINT32 	ulChaUtiMax ;		/*允许接入的最大信道利用率*/
} AC_DEVM_LOADBALANCE_CONFIG_T;

/* 3A服务器配置*/
typedef struct
{
    UINT8   aucIp[4];
    UINT32  ulPort;
    CHAR    acSecret[32];
} AC_DEVM_RADIUS_SERVER_T;

typedef struct
{
    /* 鉴权服务器配置 */
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;
    /* 计费服务器配置 */
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
    UINT32    ulRetryPrimaryInterval;   /* 主用服务器重连间隔 */
    UINT32    ulAcctInterimInterval;    /* 计费信息上报间隔 */
    UINT32	ulAuthEchoInterval;		/* 保活时长 */
    UINT32	acIsIncludeSuffix;	/* radius是否用户名是否包含后缀开关*/
} AC_DEVM_RADIUS_SERVERS_T;

typedef struct
{
	/* 鉴权服务器配置 */
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;

    UINT32    ulRetryPrimaryInterval;   /* 主用服务器重连间隔 */
    UINT32    ulAcctInterimInterval;    /* 计费信息上报间隔 */
    UINT32	ulAuthEchoInterval;		/* 保活时长 */
}AC_DEVM_RADIUS_AUTHSERVERS_T;

typedef struct
{
	/* 计费服务器配置 */
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
    UINT32    ulRetryPrimaryInterval;   /* 主用服务器重连间隔 */
    UINT32    ulAcctInterimInterval;    /* 计费信息上报间隔 */
    UINT32	ulAuthEchoInterval;		/* 保活时长 */
}AC_DEVM_RADIUS_ACCTSERVERS_T;


/* AC设备第一组IP地址配置*/
typedef struct 
{
	UINT8   aucFitLanIp[4];   		/* FIT-LAN IP */
	UINT8   aucFitLanMask[4];  	/* FIT-LAN MASK */
	
    	UINT8   aucFatLanIp[4];   		/* FAT-LAN IP */
	UINT8   aucFatLanMask[4];   	/* FAT-LAN MASK */

    	UINT8   aucL2WanIp[4];   		/* L2-WAN IP */
    	UINT8   aucL2WanMask[4];   	/* L2-WAN MASK */
    	
    	UINT8   aucL3WanIp[4];   		/* L3-WAN IP */
    	UINT8   aucL3WanMask[4];   	/* L3-WAN MASK */
}AC_DEVM_ACFIRSTIP_CONFIG_T;

/* AC基本配置*/
typedef struct 
{
    	UINT32  ulAcId;     			/* AC ID */
    	
    	CHAR	acAcNEId[32];		/* 设备网元编码*/
	CHAR	acDomainName[64];	/*	AC主机名*/
	CHAR	acContact[64];		/* 设备维护联系人*/
	CHAR	acLocation[64];		/* 设备所在位置*/
	
	UINT32	ulMaxWtpNum;		/* 最大允许接入的WTP数*/
	UINT32	ulMaxStaSwitch;		/* 2010-7-20 新增: 最大用户数限制 0:禁用 1:启用*/
	UINT32	ulMaxStaNum;		/* 最大允许接入的用户数*/
	UINT32	ulMaxPortalStaNum;	/*	最大允许接入的Portal用户数	*/
	UINT32	ulMaxPPPoEStaNum;	/*	最大允许接入的PPPoE用户数	*/
	
	UINT32	ulHeartbeatPeriod;	/* 心跳周期*/
	UINT32	ulStatisticsTime;		/* 性能统计统计时长	>0	60	单位：秒*/
	UINT32	ulSampleTime;		/* 性能统计抽样时长	>0	10	单位：秒*/

	UINT32	 ulAllAPMonitorMode;		 /* AP无线监视模式 */
	/* AC设备第一组IP地址*/
    	AC_DEVM_ACFIRSTIP_CONFIG_T	stAcIp;
} AC_DEVM_ACBASIC_CONFIG_T;

/* AC 设备系统配置*/
typedef struct 
{
    	AC_DEVM_ACBASIC_CONFIG_T	stAcBasic ;
	AC_DEVM_RADIUS_SERVERS_T	stAAAServers;
} AC_DEVM_AC_OWNCONFIG_T;

/* AC支持的AP软件版本列表配置*/
typedef struct
{
	CHAR	acDftApSwVersion[32];		/* 缺省AP软件版本*/
	
	CHAR	acSwVersion1[32];			/* AP软件版本1 */
	CHAR	acSwVersion2[32];			/* AP软件版本2 */
	CHAR	acSwVersion3[32];			/* AP软件版本3 */
	CHAR	acSwVersion4[32];			/* AP软件版本4 */
	CHAR	acSwVersion5[32];			/* AP软件版本5 */
	CHAR	acSwVersion6[32];			/* AP软件版本6 */
	CHAR	acSwVersion7[32];			/* AP软件版本7 */
	CHAR	acSwVersion8[32];			/* AP软件版本8 */
	CHAR	acSwVersion9[32];			/* AP软件版本9 */
	CHAR	acSwVersion10[32];			/* AP软件版本10 */
	CHAR	acSwVersion11[32];			/* AP软件版本11 */
	CHAR	acSwVersion12[32];			/* AP软件版本12 */
	CHAR	acSwVersion13[32];			/* AP软件版本13 */
	CHAR	acSwVersion14[32];			/* AP软件版本14 */
	CHAR	acSwVersion15[32];			/* AP软件版本15 */
	CHAR	acSwVersion16[32];			/* AP软件版本16 */
	
} AC_DEVM_ASSOCSWVERSETUP_CONFIG_T;

/* 软件版本配置*/
typedef struct
{
	UINT8	aucFtpServerIpAddr[4];
	UINT32	ulFtpServerPort;
	CHAR	acFtpUserName[32];
	CHAR	acFtpPassword[32];
	CHAR	acSwFileName[128];
	CHAR	acSpecificSwVersion[32];
	UINT32	ulUpgradeStrategy;
	UINT32	ulActivationPolicy;	/* 生效方式*/
	UINT32	ulActivationTime;
} AC_DEVM_SWSVR_CONFIG_T;

/*	WEB认证全局配置*/
typedef struct
{
	UINT32	ulPortalEnable;		/* 强制WEB认证0/1 禁用/启用*/
	UINT8	aucPortalIp[4];
	CHAR	acPortalURL[64];
	UINT32	ulPortalPort;
	CHAR	acDomainName[64];
	UINT32	ulConcurrentAuthMaxNum;
	UINT32	ulReauthTimeout;
} AC_DEVM_PORTAL_CONFIG_T;

/*	Portal白名单配置AC_DEVM_WHITELIST_CONFIG_T */
typedef struct
{
	UINT32	ulWhiteId;
	UINT8	aucWhiteIp[4];
	UINT8	aucWhiteIpMask[4];
	UINT16	usWhiteProto;
	UINT16	usWhitePort;
} AC_DEVM_WHITELIST_CONFIG_T;

/* 用户名地址绑定配置*/
typedef struct {
	CHAR	acUserName[64];		/*	用户名	*/
	UINT8	aucUserIp[4];		/*	用户IP地址	*/
	UINT8	aucUserMac[6];		/*	用户MAC地址	*/
	UINT8	aucRsv[2];			/*	reserve	*/
} AC_DEVM_USERADDRBIND_CONFIG_T;

/* 免认证IP地址列表配置*/
typedef struct {
	UINT8	aucUserIp[4];	/*	用户IP地址	*/
	UINT8	aucMask[4];		/* 掩码*/
} AC_DEVM_FREEADDR_CONFIG_T;

/* 免认证MAC配置*/
typedef struct {
	UINT8	aucMac[6];	/* MAC地址*/
	UINT8	aucRsv[2];
} AC_DEVM_FREEMAC_CONFIG_T;

/* 免认证SSID列表*/
typedef struct {
	CHAR	acSsid1[32];	
	CHAR	acSsid2[32];	
	CHAR	acSsid3[32];	
	CHAR	acSsid4[32];	
	CHAR	acSsid5[32];	
	CHAR	acSsid6[32];	
	CHAR	acSsid7[32];	
	CHAR	acSsid8[32];	
}AC_DEVM_FREESSID_CONFIG_T;

/* 免认证VLAN列表*/
typedef struct {
	UINT32	ulVlan1;
	UINT32	ulVlan2;
	UINT32	ulVlan3;
	UINT32	ulVlan4;
	UINT32	ulVlan5;
	UINT32	ulVlan6;
	UINT32	ulVlan7;
	UINT32	ulVlan8;
}AC_DEVM_FREEVLAN_CONFIG_T;

/* 白名单URL配置*/
typedef struct
{
	UINT32	ulWhiteId;			/*	白名单ID */
	UINT8	aucWhiteUrl[64];		/* 白名单URL */
}AC_DEVM_WHITEURL_CONFIG_T;

/* AC 上行链路完整性配置*/
typedef struct
{
	UINT32	ulKeepSwitch;		/*是否启用0：禁用	1：启用 */
	UINT8	aucKeeperIp0[4];		/* 检查IP地址1*/
	UINT8	aucKeeperIp1[4];		/* 检查IP地址2*/
	UINT32	ulKeepInterval;		/* 检查间隔 */
	UINT32	ulKeepCount;			/* 超时次数 */
	UINT32	ulToStandby;			/* 2011-6-21 pyy: AC主备功能修改 是否切换到standby状态*/
} AC_DEVM_ACKEEPER_CONFIG_T;

/* WTP 设备基本配置*/
typedef struct
{
    AC_WTPID_T  stWtpId;            	/* WTP设备ID */
    CHAR        acWtpName[64];      	/* WTP设备名称 */
    UINT32	ulDeviceType;
    UINT8		aucDeviceId[6];		/* 设备ID: 序列号*/
    UINT8		aucRsv[2];			/* 填充字节*/
    CHAR		acWtpNEId[32];		/* AP 网元编码*/
    UINT32	ulRunMode;			/* AP 业务转发模式: 1:集中转发/2:本地转发*/
} AC_DEVM_WTPBASIC_CONFIG_T;

/* WTP设备IP配置方式*/
#define AC_DEVM_WTPIPORIGIN_STATIC			1	/* 静态配置*/
#define AC_DEVM_WTPIPORIGIN_DHCP				2	/* DHCP 动态配置*/
#define AC_DEVM_WTPIPORIGIN_AC				3	/* AC动态配置*/

typedef struct
{
	UINT8	aucIp[4];           		/* WTP IP */
	UINT8	aucNetMask[4];			/* 掩码 */
	UINT8	aucDefaultGw[4];
	UINT8	aucPrimaryDns[4];	/*	主DNS服务器	*/
	UINT8	aucSecondaryDns[4];	/*	从DNS服务器	*/
} AC_DEVM_WTPIP_CONFIG_T;

/* add by gwx 2013-4-7 for task 668 */
typedef struct
{
	BYTE	global_ip[4];           		/* WTP global IP */ 
	UINT16	global_srcport;           		/* WTP global src port */ 
	UINT16  resv;
} AC_DEVM_NAT_IP_CONFIG_T;
/* WTP CAPWAP 配置*/
typedef struct 
{
	CHAR	acSecret[32];
	/*
	UINT32	ulDiscoveryInterval;
	UINT32	ulMaxDiscoveryInterval;
	UINT32	ulMaxDiscoveries;
	UINT32	ulEchoInterval;
	UINT32	ulMaxRetransmit;
	*/
	UINT32	ulDisType;
	CHAR	acAcURL[64];
	/*
	UINT32	ulAcIdNum;
	UINT32	aulAcId[8];
	UINT32	ulPreferredAcId;
	*/
} AC_DEVM_WTPCAPWAP_CONFIG_T;

/*	WTP关联配置AC_DEVM_WTPASSO_CONFIG_T */
/* AP接入认证方式*/
enum {
	AC_WTP_AUTH_MANNER_SECRET	= 0,
	AC_WTP_AUTH_MANNER_SN		= 1,
} AC_WTP_AUTH_MANNER_E;

typedef struct
{
	AC_WTPID_T  stWtpId;            	/* WTP设备ID */	
	UINT32		ulAssociatePrio;
	UINT32		ulWtpAuthManner;
	CHAR		acSecret[32]	;
	UINT8		aucWtpSn[6];
	UINT8		aucResv[2];
	/* add by gwx 2012-2-2 for ap关联信息为设备型号不一致，而SN非法*/
	UINT8   		aucWtpMac[6];
    	UINT8   		aucResv1[2];
		
	UINT32  		ulEchoInterval;
	UINT32  		ulMaxRetransmit;
} AC_DEVM_WTPASSO_CONFIG_T;

/* WTP 设备配置*/
typedef struct
{
	AC_DEVM_WTPBASIC_CONFIG_T	stWtpBasic;
	AC_DEVM_WTPIP_CONFIG_T		stWtpIp ;
	AC_DEVM_WTPCAPWAP_CONFIG_T	stWtpCapwap ;
	AC_DEVM_LOADBALANCE_CONFIG_T	stLBCfg;	/* 负荷均衡策略 */
} AC_DEVM_WTP_CONFIG_T;

typedef struct
{
    UINT32    ulWifiModuleNum;
    UINT32    aulWifiModuleIdList[4];
} AC_DEVM_VDEV_WIFILIST_T;

/* 无线设备结构体定义 */
enum{
         AC_VDEV_TYPE_AP_ALONE,                   	/*独立的接入设备*/
         AC_VDEV_TYPE_AP_BIND,             		/*捆绑的接入设备*/
         AC_VDEV_TYPE_ADHOC_ALONE,         	/*独立的回传设备*/
         AC_VDEV_TYPE_ADHOC_BIND,    			/*捆绑的回传设备*/
         AC_VDEV_TYPE_AP_ADHOC,                 	/*接入加回传设备*/
         AC_VDEV_TYPE_STA_ADHOC,               	/*终端加回传设备*/
         AC_VDEV_TYPE_STA_ALONE,                	/*独立的终端设备*/
         AC_VDEV_TYPE_STA_BIND            		/*捆绑的终端设备*/
} AC_VDEV_TYPE_E ;

//无线设备基本配置
typedef struct
{
	/* 基本配置*/
	UINT32	ulVdevType;
   
} AC_DEVM_VDEVBASIC_CONFIG_T;

// 无线设备信道配置AC_DEVM_VEDV_CHANNEL_CONFIG_T
enum{
	AC_CHANNEL_TYPE_STATIC 	= 0,
	AC_CHANNEL_TYPE_DYNAMIC  = 1
}AC_CHANNEL_TYPE_E ;

typedef struct
{ 
 /* 信道配置*/
	UINT32	ulAbgMode;		/* A/B/G 模式*/
	UINT32	ulTurboMode;	/* Trubo模式*/
	UINT32	ulChannelMode;	/* 信道模式*/
	UINT32	ulChannelType;	/* 工作信道: 静态/自适应*/
	UINT32	ulChannel;		/* 工作信道*/

} AC_DEVM_VDEVCHANNEL_CONFIG_T;

//	无线设备速率配置AC_DEVM_VEDV_RATE_CONFIG_T
typedef struct
{
	/* 无线速率配置*/
	UINT32	ulMaxTxRate;	/* 最大发射速率*/
	UINT32	ulMgmTrate;		/* 优选管理帧发送速率*/
	UINT32	ulMcasTrate;	/*	优选广播发送速率*/
	UINT32	ulMgmtRetrys;	/* 	管理帧重传次数*/

} AC_DEVM_VDEVRATE_CONFIG_T;

//无线设备功率配置AC_DEVM_VEDV_POWER_CONFIG_T
typedef struct
{
	/* 无线功率配置*/
	UINT32	ulLimitTxPower;	/* 最大发射功率*/
	UINT32	ulMaxTxPower;	/* 发射功率上限*/
} AC_DEVM_VDEVPOWER_CONFIG_T;

//	无线设备高级配置AC_DEVM_VDEV_ADVANCED_CONFIG_T
typedef struct
{
	/* 高级配置 */
	UINT32    ulBeaconInt;			/* BEACON间隔*/
 	UINT32    ulDtimInt;			/* DTIM间隔*/
 	UINT32    ulPreamble;			/* 前导类型*/
	UINT32    ulFragmThreshold;	/* 分片门限*/
	UINT32    ulRtsThreshold;		/* RTS 门限*/
	UINT32	ulLongRtsThreshold;	/* 长帧重传门限*/
	UINT32	ulShortRtsThreshold;	/* 短帧重传门限*/
	UINT32	ulCacheTime;		/*	接收数据包生存期*/

	UINT32    ulCtsProtectionType;	/* CTS保护模式*/
	UINT32	 ulTxDistOptSwitch;	/* 最大传输距离开关*/
	UINT32	 ulMaxTxDistance;	/* 最大传输距离*/
	
} AC_DEVM_VDEVADVANCED_CONFIG_T;

/* 无线设备WIDS */
typedef struct 
{

	/* 可疑终端*/
	UINT32	ulDosAttackDetectSwitch;
	UINT32	ulDosAttackPeriod;		/*	泛洪攻击统计周期		>0	60	秒*/
	UINT32	ulDosAttackThreshold;	/*	泛洪攻击判定门限		>0	30	*/

	UINT32	ulDosAttackDefenseSwitch;
	UINT32	ulInvalidTerminalAgeingTime;

	UINT32	ulSpoofAttackDetectSwitch;	/* Spoof攻击检测开关*/
	UINT32	ulWeekIVAttackDetectSwitch;	/* Week IV检测开关*/
 	UINT32	ulStaDisturbDetectSwitch;		/* 终端干扰检测开关*/
	UINT32	ulStaDisturbLimit;			/* 终端干扰门限（包速率:pps）*/

	/* 2010-07-01 fengjing cmcc test */
    UINT32  ulAPInterfNumThreshhd;      /* AP干扰告警门限 */
	UINT32  ulStaInterfNumThreshhd;     /* 终端干扰告警门限*/
    INT32   lAPCoInterfThreshhd;        /* AP同频干扰告警门限*/
    INT32   lAPNeiborInterfThreshhd;    /* AP邻频干扰告警门限*/
	
	UINT32	ulMacNum;					/* 合法终端MAC数目*/
	UINT8 	aaucMac[16][8];				/* 合法终端MAC列表*/

	/* 恶意AP */
	UINT32	ulInvalidApDetectSwitch;		/* 可疑AP检测*/
	
	UINT32	ulSsidNum;					/* 合法AP SSID数目*/
 	UINT8	aaucSsid[16][32];				/* 合法 AP SSID列表*/ 
	UINT32	ulBssidNum;					/* 合法 AP BSSID数目*/
 	UINT8	aaucBssid[16][8];			 /*合法AP BSSID列表*/ 
	UINT32	ulListOuiNum;				/* 合法AP OUI数目*/
 	UINT8	aaucOui[16][4];				/*合法AP OUI列表*/
} AC_DEVM_VDEVWIDS_CONFIG_T;

/* 无线设备无线资源管理*/
/*新增*/

enum{
	AC_RRM_OVERSTEP_REPORTALARM = 1,
	AC_RRM_OVERSTEP_REELECTCHANNEL = 2
}AC_RRM_OVERSTEP_E ;

typedef struct 
{
	UINT32	ulMoniMode;					/* 无线环境监测模式 
										1：提供WLAN接入服务
										2：监视无线环境
										3：空闲时监视无线环境
										*/
										
	/* 异频扫描 */
	UINT32	aulDiffScanChannelList[16] ;		/*异频扫描频点列表*/
	UINT32	ulDiffScanInterval ;			/*异频扫描周期*/
	UINT32	ulDiffScanResidenceTime ;		/*异频扫描频点驻留时间*/

	/* 同频扫描 */
	UINT32	ulSameScanInterval ;			/* 同频扫描周期 */
	UINT32	ulNeighAutoScanSwitch;	/*	启用邻居自动扫描	*/
	UINT32	ulNeighRssiMin;			/*	邻居信号强度最小门限	*/
	UINT32	ulNeighRssiWave;		/*	邻居信号强度波动范围	*/
	
	/*频点监测*/
	UINT32	ulChannelPeriod ;	/*信道重选周期, 单位: 分钟*/
	UINT32	ulRssiThreshold ;				/*频点质量门限RSSI*/
	INT32	lNoiseThreshold ;			/*频点质量门限底噪*/
	/* UINT32	ulOverstepManner ;*/			/*频点质量超门限措施*/

	/* 功率动态调整策略1 */
	UINT32	ulInterfereDetectSwitch ;		/*干扰检测开关*/
	UINT32	ulInterfereDetectPeriod ;		/* 功率调整周期 */
	
	UINT32	ulMaxInterferePermitted ;		/* 功率调整目标RSSI */
	UINT32	ulRssiWaveRange ;			/* 目标RSSI波动范围 */
	/* UINT32	ulCompensatingFactor ;	*/	/*补偿因子*/

	UINT32			ulPowerCompensationSwitch ;		/* 提供功率补偿服务 */
} AC_DEVM_VDEVRRM_CONFIG_T;

typedef struct
{
	UINT32    ulWtpId;
    	UINT32    ulVDevId;
    	UINT32	ulMaxPower;	/* 最大发射功率*/
} AC_DEVM_VDEV_MAXPOWER_T;


/* 无线设备配置*/
typedef struct
{
	/* 标识信息 */
   	AC_VDEVID_T    stVdevId;

   	/* 属性信息*/
    	AC_DEVM_VDEVBASIC_CONFIG_T		stVdevBasic ;
	AC_DEVM_VDEVCHANNEL_CONFIG_T	stVdevChannel ;
	AC_DEVM_VDEVRATE_CONFIG_T		stVdevRate;
	AC_DEVM_VDEVPOWER_CONFIG_T	stVdevPower;
	AC_DEVM_VDEVADVANCED_CONFIG_T	stVdevAdvanced;

	AC_DEVM_VDEVWIDS_CONFIG_T		stVdevWidsCfg;	/* WIDS配置 */
	AC_DEVM_VDEVRRM_CONFIG_T		stVdevRrmCfg ;	/* RRM 配置 */
} AC_DEVM_VDEV_CONFIG_T;

/* 接口配置*/
typedef struct
{
    	/* 标识信息 */
	AC_IFID_T    stIfId;

   	/* 属性信息*/
	AC_DEVM_VDEVCHANNEL_CONFIG_T	stIfChannel ;
	AC_DEVM_VDEVRATE_CONFIG_T		stIfRate;
	AC_DEVM_VDEVPOWER_CONFIG_T	stIfPower;
	AC_DEVM_VDEVADVANCED_CONFIG_T	stIfAdvanced;

	
	AC_DEVM_VDEVWIDS_CONFIG_T		stIfWidsCfg;		/* WIDS配置 */
	AC_DEVM_VDEVRRM_CONFIG_T		stIfRrmCfg ;		/* RRM 配置 */
} AC_DEVM_IF_CONFIG_T;

/* VAP配置*/
enum{
AC_VAP_OPMODE_AP,
AC_VAP_OPMODE_ADHOC,
AC_VAP_OPMODE_STA
}AC_VAP_OPMODE ;

typedef struct
{
    	/* 标识信息 */
    	AC_VAPID_T        stVapId;
    	UINT32	ulOpMode;
    
    	/* 基本配置 */
    	CHAR    acIfName[AC_DEVM_IFNAME_LEN];
    	UINT8   aucBssid[6];        	/* MAC地址 */
    	UINT8   aucRsv[2];         	/* 填充字节 */
    	CHAR    acSsid[32];         	/* SSID */
    	UINT32  ulSsidBroadcast;   /* SSID广播*/
    	UINT32	ulMaxSimultUsers;	/*	最大允许接入的用户数	*/
	UINT32	ulMaxSimultTraffic;		/*	最大流量	*/
	
    	/* 安全配置 */
    	UINT32  ulAuth;             /* 网络验证类型 
                                Bit0（0/1）：不支持/支持开放式                                
                                Bit1（0/1）：不支持/支持共享式  
                                Bit2（0/1）：不支持/支持WPA    
                                Bit3（0/1）：不支持/支持WPA-PSK      
                                Bit4 （0/1）：不支持/支持MAC认证
                                Bit5（0/1）：不支持/支持WAI
    					*/
    	UINT32  ulEncrypt;          /* 数据加密类型 
                                Bit0（0/1）：不支持/支持禁用
                                Bit1（0/1）：不支持/支持WEP 
                                Bit2（0/1）：不支持/支持TKIP    
                                Bit3（0/1）：不支持/支持AES      
                                Bit4（0/1）：不支持/支持SMS4
    					*/

	UINT32  ulWapiSetupId;  	/*	WAPI协议配置	*/
	UINT32  ulCertFileId;   	/*	WAPI证书	*/
	CHAR    acWapiPsk[64];	/*  WAPI PSK口令	*/

    	CHAR    acWpaKey[64];       /* WPA密钥 */
    	UINT32  ulWpaRekeyPeriod;   /* WPA密钥更新周期 */
    	UINT32  ulWepKeyLen;        /* WEP密钥长度 */
    	UINT32  ulInputFormat;      /* WEP密钥输入格式 */
    	CHAR    acWepKey[32];       /* WEP密钥 */
    	UINT32  ulWepKeyIndex;      /* WEP密钥编号 */
    	UINT32  ul8021x;            /*是否启用网络的IEEE802.1x验证 */
    	UINT32  ulWepBroadcastKeyLen;   /* 动态WEP广播密钥长度
                                      1: 64 Bit
                                      2: 128 Bit */
    	UINT32  ulWepUnicastKeyLen;     /* 动态WEP单播密钥长度
                                      1: 64 Bit
                                      2: 128 Bit */
    	UINT32  ulWepRekeyPeriod;   /* WEP密钥更新周期 */
    	UINT32  ulEapolVer;         	/* EAP版本*/
   	UINT32  ulEapAuthPeriod;    /* EAP鉴权周期*/

   	/* 高级配置 */
	UINT32	ulPrivCap;		/* VLAN属性 */
	UINT32	ulPowerCtrl;		/* 是否开启功率控制 */
	UINT32	ulEndUserTime;	/* 用户保活时间 */
	UINT32	ulQosType;		/* QoS类型 */
	UINT32	ulAcLowLimit;	/* 用户接入下限 */
	UINT32	ulAcUpLimit;		/* 用户接入上限 */
	UINT32	ulAcInterval;		/* 接入控制时间 */
	UINT32	ulTrafficMode;	/* 2010-4-20 pyy新增: VAP业务转发模式*/
} AC_DEVM_VAP_CONFIG_T;


/* ADHOC配置*/
typedef struct 
{
	/* 标识信息 */
    	AC_ADHOCID_T        stAdhocId;
} AC_DEVM_ADHOC_CONFIG_T;

/* VAP BSSID */
typedef struct
{
    AC_VAPID_T  stVapId;        /* VAP ID */
    UINT8       aucBssid[6];    /* VAP MAC地址 */
    UINT8       aucRsv[2];      /* 填充字节 */
} AC_DEVM_VAP_BSSID_T;

/* ADHOC BSSID */
typedef struct 
{
	AC_ADHOCID_T	stAdhocId;
	UINT8	aucBssid[6];
	UINT8	aucRsv[2];
} AC_DEVM_ADHOC_BSSID_T;


/* VAP 流量统计*/
typedef struct 
{
	AC_VAPID_T  stVapId;        /* VAP ID */
	UINT32	ulUpTraffic;
	UINT32	ulDownTraffic;
} AC_DEVM_VAP_TRAFFICSTAT_T;

/* SNMP V2 配置*/
typedef struct 
{
	UINT32	ulCommunityId;		/* 共同体ID */
	CHAR	acReadCommunity[32];		/* 共同体 */
	CHAR	acWriteCommunity[32];		/* 共同体 */
	UINT32	ulRfc1213Flag;		/* RFC1213标准MIB访问权限 */
	UINT32	ulRfc1573Flag;		/* RFC1573标准MIB访问权限 */
	UINT32	ulRfc1643Flag;		/* RFC1643标准MIB访问权限 */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE标准MIB访问权限 */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot标准MIB访问权限 */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI标准MIB访问权限 */
	UINT32	ulPrivateFlag;		/* 私有MIB访问权限 */
} AC_DEVM_SNMPV2_CONFIG_T;

/* SNMP V3配置 */
typedef struct 
{
	UINT32	ulUserId;			/* 用户ID */
	CHAR	acUserName [32];	/* 用户名 */
	UINT32	ulAuthProtocol;		/* 鉴权协议 */
	CHAR	acAuthKey[32];		/* 鉴权密钥 */
	UINT32	ulPrivProtocol;		/* 加密协议 */
	CHAR	acPrivKey[32];		/* 加密密钥 */
	UINT32	ulRfc1213Flag;		/* RFC1213标准MIB访问权限 */
	UINT32	ulRfc1573Flag;		/* RFC1573标准MIB访问权限 */
	UINT32	ulRfc1643Flag;		/* RFC1643标准MIB访问权限 */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE标准MIB访问权限 */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot标准MIB访问权限 */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI标准MIB访问权限 */
	UINT32	ulPrivateFlag;		/* 私有MIB访问权限 */
} AC_DEVM_SNMPV3_CONFIG_T;

/* 	SNMP TRAP配置AC_DEVM_SNMPTRAP_CONFIG_T */
typedef struct 
{
	UINT32	ulTrapSvrId;		/*	TRAP服务器ID */
	UINT8	aucTrapIp[4];	/*	TRAP服务器地址 */
	UINT32	ulTrapPort;		/*  TRAP服务器端口 */
} AC_DEVM_SNMPTRAP_CONFIG_T;


/* SNTP服务器全局配置*/
typedef struct 
{
	UINT32	ulSntpSwitch;	/* 启用SNTP服务器功能 */
	UINT32	ulUpdatePeriod;	/* 时间更新周期*/
	UINT8	aucUpperSntpSvr1[4];	/*	上级SNTP服务器1	*/
	UINT8	aucUpperSntpSvr2[4];	/*	上级SNTP服务器2	*/
	UINT8	aucUpperSntpSvr3[4];	/*	上级SNTP服务器3	*/
	UINT8	aucUpperSntpSvr4[4];	/*	上级SNTP服务器4	*/
} AC_DEVM_ACSNTP_CONFIG_T;

/*	WTP SNTP配置AC_DEVM_WTPSNTP_CONFIG_T*/
typedef struct 
{
	UINT32	ulEnableSntp;		/* 启用SNTP客户端功能 */
	UINT8	aucSntpServrIp[4];	/* SNTP服务器IP */
	UINT32	ulPeriod;			/* 时间同步周期 */
} AC_DEVM_WTPSNTP_CONFIG_T;

/* add by gwx 2013-4-7 for task668 */
typedef struct{
	UINT32	ulWtpId;  
	UINT32	dwCommPort;		/* 通信端口号*/
	UINT8	tCommAddr[4];		/* 通信IP地址*/
}AC_DEVM_WTP_SETSRCADDR_IND_MSG_T;
/* 	日志级别 : MIB的定义*/
enum{
	AC_LOG_LEVEL_MIB_EMERGENCY 		= 0,
	AC_LOG_LEVEL_MIB_ALERT 			= 1,
	AC_LOG_LEVEL_MIB_CRITICAL 		= 2,
	AC_LOG_LEVEL_MIB_ERROR 			= 3,
	AC_LOG_LEVEL_MIB_WARNING 		= 4,
	AC_LOG_LEVEL_MIB_NOTICE 			= 5,
	AC_LOG_LEVEL_MIB_INFORMATIONAL 	= 6,
	AC_LOG_LEVEL_MIB_DEBUG 			= 7,
	AC_LOG_LEVEL_MIB_OFF 				= 0xFFFFFFFF,
}AC_LOG_LEVEL_MIB_E ;

/* 	日志级别 : SYSLOG打印级别的实现*/
enum{
	AC_LOG_LEVEL_SOFT_OFF 		= 0,
	AC_LOG_LEVEL_SOFT_FATAL 		= 1,
	AC_LOG_LEVEL_SOFT_ERROR 		= 2,
	AC_LOG_LEVEL_SOFT_WARNING	= 3,
	AC_LOG_LEVEL_SOFT_MSG 		= 4,
	AC_LOG_LEVEL_SOFT_DETAIL 		= 5,
}AC_LOG_LEVEL_SOFT_E ;

/* 日志模块*/
/* powerac相关模块 */
#define LM_OSS          			0
#define LM_DB           				1
#define LM_DEVM         			2
#define LM_USRM         			3
#define LM_OMA          			4
#define LM_CW           			5
#define LM_HOSTAPD				6
#define LM_ACM          			7
#define LM_RRM          			8
#define LM_PORTAL       			9
#define LM_WAPIAPD       			10
#define LM_SYSM     				11
#define LM_MANAGER         		12

/* add by gwx 2012-1-9 for task252 */
#define LM_OPERATION     17     /*操作日志看，用于输出到网络*/
#define LM_BUSINESS       18     /*业务流程日志，用于输出到网络*/
#define LM_ALERT          19     /*告警日志，用于输出到网络*/
#define LM_EVENT          20    /*事件日志，用于输出到网络*/ 
#define LM_SECURITY       21    /*安全日志，用于输出到网络*/ 
/* AC外围进程、内核模块     24 - 47 */
#define LOG_MODULE_AC       24
#define LM_ACWEB            	(LOG_MODULE_AC+0)
#define LM_ACCOUNT          	(LOG_MODULE_AC+1)
#define LM_AGENT            		(LOG_MODULE_AC+2)
#define LM_DHCP             		(LOG_MODULE_AC+3)
#define LM_FW               		(LOG_MODULE_AC+4)
#define LM_HR               		(LOG_MODULE_AC+5)
#define LM_IDS              		(LOG_MODULE_AC+6)
#define LM_IGMP             		(LOG_MODULE_AC+7)
#define LM_L2W              		(LOG_MODULE_AC+8)
#define LM_NTP              		(LOG_MODULE_AC+9)
#define LM_PA               		(LOG_MODULE_AC+10)
#define LM_PPPOE            		(LOG_MODULE_AC+11)
#define LM_QOS              		(LOG_MODULE_AC+12)
#define LM_ROUTE            		(LOG_MODULE_AC+13)
#define LM_TS               		(LOG_MODULE_AC+14)
#define LM_SYSMON			(LOG_MODULE_AC+15)
#define LM_SYSLOG           	(LOG_MODULE_AC+16)
#define LM_IPC				(LOG_MODULE_AC+17)

/* AP外围进程、内核模块     48 - 63 */
#define LOG_MODULE_AP       	48
#define LM_APDRIVER         	(LOG_MODULE_AP+0)
#define LM_APWIFI           	(LOG_MODULE_AP+1)
#define LM_APROUTE          	(LOG_MODULE_AP+2)
#define LM_APWEB            	(LOG_MODULE_AP+3)
#define LM_APAGENT          	(LOG_MODULE_AP+4)
#define LM_APSYSMON         	(LOG_MODULE_AP+5)
#define LM_APSYSLOG         	(LOG_MODULE_AP+6)
#define LM_APDHCP           	(LOG_MODULE_AP+7)
#define LM_APNTP            		(LOG_MODULE_AP+8)
#define LM_APL2W            	(LOG_MODULE_AP+9)



typedef struct 
{
	UINT8	aucLogModule[64];	/*	模块开关	*/
	UINT32	ulLogToStdOut;		/*	是否打印到标准输出	*/
	UINT32	ulLogSvrNum;		/* 远程日志服务器数目*/
	UINT8	aaucLogSvrIp[4][4];	/*	日志服务器IP地址	*/
	UINT32	aulLogSvrPort[4];	/*	日志服务器端口号	*/
	UINT32	ulLogTransType;		/*	日志传输类型	*/	
} AC_DEVM_LOG_CONFIG_T;

/*	日志服务器配置AC_DEVM_LOGSVR_CONFIG_T*/
typedef struct 
{
	UINT32  ulLogSvrSwitch;   		/*  日志服务器开关	      */
	UINT8   aucLogSvrIp[4];   		/*  日志服务器绑定IP地址    */
	UINT32  ulLogSvrPort;   		/*  日志服务器绑定端口	  */
	UINT32  ulLogBakDay;   		/*  日志保存天数	      */
	UINT32  ulLogFileSize;   		/*  日志文件大小	      */
	UINT32  ulLogCompress;   		/*  是否压缩	          */
} AC_DEVM_LOGSVR_CONFIG_T;

/*AC端口组配置AC_DEVM_BRIDGE_CONFIG_T*/
enum {
	AC_BRIDGE_TYPE_FTTLAN		= 0,
	AC_BRIDGE_TYPE_FATLAN		= 1,
	AC_BRIDGE_TYPE_L2WAN		= 2,
	AC_BRIDGE_TYPE_L3WAN		= 3,
	AC_BRIDGE_TYPE_MS			= 4,
} AC_BRIDGE_TYPE_E;

typedef struct 
{
	UINT32		ulBridgeId;   			/* 端口组ID	        */
	UINT32   		ulBridgeType;   			/* 端口类型	        */
	CHAR   		acBridgeName[32];   		/* 端口组名称	    */    
	UINT32		ulIpNum;
	UINT8		aaucIp[40][4];
	UINT8		aaucMask[40][4];
} AC_DEVM_BRIDGE_CONFIG_T;

/* AC LAN端口组配置AC_DEVM_LANIF_CONFIG_T*/
typedef struct 
{
	UINT32	ulIfId;
	CHAR	acIfName[32];
} AC_DEVM_LANIF_CONFIG_T;

/* AC物理端口配置*/
typedef struct 
{
	UINT32	ulIfId;	/* 端口号 */
	UINT32	ulPortType;
	CHAR	acIfName[32];	/* 端口名称 */
	UINT32	ulRunMode;		/* 是否启用 */
	UINT32	ulSpeedUplex;	/* 速率/双工模式 */
	UINT32	ulMtu;
	UINT32	ulVlanType;		/* VLAN 属性*/
	UINT32	ulCapVlanId;		/* 封装VLAN ID */
} AC_DEVM_ACPORT_CONFIG_T;

/* 端口IP地址配置*/
typedef struct 
{
	UINT32	ulFitLanIpNum;											/* FIT-LAN端口的IP地址数目*/
	UINT8	aaucFitLanIp[AC_BRIDGE_FITLAN_IPNUM_MAX][4];				/* FIT-LAN IP地址*/
	UINT8	aaucFitLanNetMask[AC_BRIDGE_FITLAN_IPNUM_MAX][4];		/* FIT-LAN IP子网掩码*/

	UINT32	ulFatLanIpNum;											/* FAT-LAN端口的IP地址数目*/
	UINT8	aaucFatLanIp[AC_BRIDGE_FATLAN_IPNUM_MAX][4];			/* FAT-LAN IP地址*/
	UINT8	aaucFatLanNetMask[AC_BRIDGE_FATLAN_IPNUM_MAX][4];		/* FAT-LAN IP子网掩码*/

	UINT32	ulL2WanIpNum;											/* L2-WAN端口的IP地址数目*/
	UINT8	aaucL2WanIp[AC_BRIDGE_L2WAN_IPNUM_MAX][4];				/* L2-WAN IP地址*/
	UINT8	aaucL2WanNetMask[AC_BRIDGE_L2WAN_IPNUM_MAX][4];		/* L2-WAN IP子网掩码*/

	UINT32	ulL3WanIpNum;											/* L3-WAN端口的IP地址数目*/
	UINT8	aaucL3WanIp[AC_BRIDGE_L3WAN_IPNUM_MAX][4];				/* L3-WAN IP地址*/
	UINT8	aaucL3WanNetMask[AC_BRIDGE_L3WAN_IPNUM_MAX][4];		/* L3-WAN IP子网掩码*/

	UINT8	aucDefaultGw[4];					/* 缺省网关*/
	UINT8	aucPrimaryDns[4];				/* 主用DNS服务器*/
	UINT8	aucSecondaryDns[4];				/* 备用DNS服务器*/
} AC_DEVM_ACIP_CONFIG_T;

/* WTP物理端口配置*/
enum {
	AC_WTP_ENET_STATE_UPLINK= 0,			/* 上联口*/
	AC_WTP_ENET_STATE_DOWNLINK = 1,		/* 下联口*/
} AC_WTP_ENET_STATE_E;

typedef struct 
{
	AC_ENETID_T	stEnetId;	/* 有线物理端口列表*/
	UINT32	ulEnetState;		/* 有线物理端口的状态*/
} AC_DEVM_ENET_CONFIG_T;

/* VLAN全局配置*/
typedef struct 
{
	UINT32	ulRoamSwitch;			/* VLAN 漫游开关*/
	UINT32	ulTime;					/* VLAN漫游老化时间*/
}AC_DEVM_VLANGLOBAL_CONFIG_T;

/* VLAN基本配置*/
typedef struct 
{
	UINT32	ulVlanId;				/* VLAN ID */
	CHAR	acVlanName[32];			/* VLAN名称*/
	UINT32	ulVlanEnable;	/* add by gwx 2014-7-11 for dlink, vlan 开关*/
	UINT32	ulVlanForFitLan;			/*	FIT-LAN端口上启用	*/
	UINT32	ulVlanForFatLan;			/*	FAT-LAN端口上启用	*/
	UINT32	ulVlanForL2Wan;			/*	L2-WAN端口上启用	*/
	UINT32	ulVlanForL3Wan;			/*	L3-WAN端口上启用	*/
	UINT32	ulEnableIsolate;			/* 用户隔离 */
	UINT32	ulVlanPrio;				/* VLAN优先级*/
	CHAR	acNasId[32];				/* 热点NasId */
} AC_DEVM_VLAN_CONFIG_T;

/* SSID-VLAN映射配置*/
typedef struct 
{
	CHAR	acSsid[32];				/* SSID */
	UINT32	ulVlanId;				/* VLAN ID */
} AC_DEVM_VLANSSIDMAP_CONFIG_T;

/* 端口-VLAN映射配置*/
typedef struct 
{
	UINT32	ulDevId;			/* 设备ID */
	UINT32	ulIfId;			/* 端口ID */
	UINT32	ulVlanId;		/* VLAN ID */
	UINT32	ulIfType;		/* 端口类型*/	
	CHAR	acIfName[32];	/* 端口名称*/
	UINT32	ulNestVlanId;		/* add by gwx 2014-7-11 ,qinq 外层vlan  */
	UINT32	ulVlanIfType;	/* VLAN端口类型*/
} AC_DEVM_VLANIFMAP_CONFIG_T;

/* MAC-VLAN映射配置*/
typedef struct 
{
	UINT8	aucMac[6];			/* MAC地址 */
	UINT8	aucRsv[2];			/* 填充字段 */
	UINT32	ulVlanId;				/* VLAN ID */
} AC_DEVM_VLANMACMAP_CONFIG_T;

/*	VLAN MAC地址过滤策略AC_DEVM_VLANACCMACPOLICY_CONFIG_T*/
typedef struct 
{
	UINT32	ulVlanId ;
	UINT32 ulMacFilterSwitch;   /*	MAC过滤功能开关	0：关闭 1：打开 */
	UINT32 ulMacFilterType;	    	/* MAC过滤类型	0：白名单 1：黑名单 */
} AC_DEVM_VLANACCMACPOLICY_CONFIG_T;

/* VLAN MAC地址过滤列表配置*/
typedef struct 
{
	UINT32	ulVlanId;			/* VLAN ID */
	UINT8	aucMac[6];			/* MAC地址 */
	UINT8	aucRsv[2];			/* 填充字段 */
} AC_DEVM_VLANACCMAC_CONFIG_T;

/* IGMP Snooping配置*/
typedef struct 
{
	UINT32	ulIgmpSnoopSwitch;			/* 是否生效 */
	UINT32	ulRtPortTimer;				/* 路由器端口老化定时器 */
	UINT32	ulMemberPortTimer;			/* 成员端口老化定时器 */
} AC_DEVM_IGMPSNOOP_CONFIG_T;

/* IGMP Proxy配置*/
typedef struct 
{
	UINT32	ulIgmpProxy;			/* 是否生效 */
} AC_DEVM_IGMPPROXY_CONFIG_T;

/* 静态路由配置*/
typedef struct 
{
	UINT32	ulRouteId;
	
	UINT8	aucDestIp[4];	/* 目标IP网段 */
	UINT8	aucMask[4];		/* 掩码*/
	UINT8	aucGw[4];		/* 网关 */
} AC_DEVM_ROUTESTATIC_CONFIG_T;

/* RIP全局配置 */
typedef struct 
{
	UINT32	ulRipSwitch ;				/* 是否启用RIP协议 */
	UINT32	ulIfType;				/*	被动模式		0：否1：是*/
	UINT32	ulAuthType;				/*	鉴权模式		0：不采用鉴权
															1：text明文模式
															2：MD5模式
															*/
	CHAR	acKey[72];				/*	密钥*/
	UINT32	ulSendVersion;			/*	发送版本号
									0：V1/V2模式发送
									1：V1模式发送
									2：V2模式发送*/
	UINT32	ulRecvVersion;			/*	接收版本号
									0：V1/V2模式接收
									1：V1模式接收
									2：V2模式接收
									*/

	UINT32	ulSplitHorizonOn ;		/* 是否启用水平分割 */
	UINT32	ulRedistributeStatic ; 	/* 是否重分发静态路由 */
	UINT32	ulRedistributeKernal ;	/* 是否重分发本地路由 */
	UINT32	ulUpdate ;				/* Update定时器 */
	UINT32	ulTimeout ; 				/* Timeout定时器 */
	UINT32	ulGarbage ; 				/* Garbage定时器 */
} AC_DEVM_RIPGLOBAL_CONFIG_T;

/* 	RIP通告网段配置*/
typedef struct 
{
	UINT8	aucNetIp[4];		/* IP网段 */
	UINT8	aucMask[4];		/* 掩码*/
} AC_DEVM_RIPNOTIFYNET_CONFIG_T;


/* 	防火墙全局配置*/
typedef struct 
{
	UINT32	ulFwSwitch;				/* ACL开关: 0禁用 1启用*/
	UINT32	ulAclDefaultAction;		/* ACL默认策略0丢弃 1接受*/

} AC_DEVM_FWGLOBAL_CONFIG_T;

/* 	防火墙规则配置*/
typedef struct 
{
	/* 匹配原则*/
	UINT32		ulRuleId				;	/* 规则号				*/
	UINT32		ulChildRuleId;			/* 规则子序号*/
	CHAR		acComment[32]		;	/* 对该服务规则的解释	*/
	UINT32		ulRuleOn;				/* 规则是否启用*/
	UINT32  		ulChainId			;	/* 规则类型0:本机访问规则 1:转发规则 */

	UINT32  		ulSrcIpMatchType	;	/* 源IP匹配策略 0:不匹配 1:正向匹配 2:反向匹配*/
	UINT8		aucSrcIp[4]			;	/* 源IP地址			    */
	UINT8		aucSrcIpMask[4]		;	/* 源IP地址的掩码		*/
	UINT32  		ulDestIpMatchType	;	/* 目的IP匹配策略 0:不匹配 1:正向匹配 2:反向匹配*/
	UINT8		aucDestIp[4]			;	/* 目的IP地址			*/
	UINT8		aucDestIpMask[4]		;	/* 目的IP地址的掩码	    */

	UINT32		ulIfMatchType;			/* 接口匹配策略
										0: 不匹配 1:入接口匹配 2:出接口匹配 3:同时匹配*/
	
	UINT32  		ulInIfId				;	/* 入接口				*/
	UINT32  		ulOutIfId			;	/* 出接口				*/



	UINT32	ulRuleProtocol;	/*	传输协议匹配		
								0：所有协议     
								1：ICMP   
								2：IGMP  
								6：TCP    
								17：UDP  
								47：GRE  
								94：IPIP  
								115：L2TP
								132：SCTP
								*/

	UINT32	ulSrcPortMatchPolicy;	/*	源端口匹配策略		0：不匹配
								1：正向匹配
								2：反向匹配
								*/
	UINT32	ulSrcPortBegin;		/*	起始源端口		1-65535 */
	UINT32	ulSrcPortEnd;		/*	结束源端口		1-65535 */
	UINT32	ulDstPortMatchPolicy;	/*	目的端口匹配策略		
									0：不匹配
									1：正向匹配
									2：反向匹配
									*/
	UINT32	ulDstPortBegin;		/*起始目的端口		1-65535*/
	UINT32	ulDstPortEnd;		/*结束目的端口		1-65535*/
	CHAR	acSsid[32];			/* 匹配SSID */
	CHAR	acUrl[64];			/* 匹配URL */
	
	UINT32	ulMarkMatch;		/*	匹配标记值	*/

	/*匹配动作*/
	UINT32	ulAction;		/*	规则执行的动作	
								0：丢弃
								1：接受
								2：设置标记值
								*/
	UINT32	ulLogSet;		/*	规则执行日志	
								0：关闭
								1：打开
								*/
	UINT32	ulSetMark;		/*	设置标记*/
} AC_DEVM_FWRULE_CONFIG_T;

/* 	P2P过滤配置*/
typedef struct 
{
	UINT32	ulP2PSwitch;		/*	P2P限制		0：禁用1：启用*/
	UINT32	ulBtCfg;			/*	BT限制		0：禁用1：启用*/
	UINT32	uleDonkeyCfg;	/*	eDonkey限制	0：禁用1：启用*/
	UINT32	ulAresCfg;		/*	Ares限制	 	0：禁用1：启用*/
	UINT32	ulFasttrackCfg;	/*	Fasttrack限制	0：禁用1：启用*/
	UINT32	ulGnutellaCfg;	/*	Gnutella限制	0：禁用1：启用*/
	UINT32	ulApplejuiceCfg;	/*	Applejuice限制	0：禁用1：启用*/
	UINT32	ulXunleiCfg;		/*	Xunlei限制	 	0：禁用1：启用*/
	UINT32	ulMuteCfg;		/*	Mute限制		0：禁用1：启用*/
	UINT32	ulSoulseak;		/*	Soulseek限制	0：禁用1：启用*/
	UINT32	ulPpliveCfg;		/*	PPLive限制		0：禁用1：启用*/
	UINT32	ulPpstreamCfg;	/*	PPStream限制	0：禁用1：启用*/
	UINT32	ulFreenetCfg;	/*	Freenet限制	0：禁用1：启用*/
	UINT32	ul100baoCfg;	/*	100bao限制 	0：禁用1：启用*/
	UINT32	ulHotLineCfg;	/*	Hotline限制	0：禁用1：启用*/
	UINT32	ulGoboogyCfg;	/*	Goboogy限制	0：禁用1：启用*/
	UINT32	ulKugooCfg;		/*	Kugoo限制		0：禁用1：启用*/
	UINT32	ulPocoCfg;		/*	Poco限制	 	0：禁用1：启用*/
	UINT32	ulTeslaCfg;		/*	Tesla限制		0：禁用1：启用*/
	UINT32	ulSoribadaCfg;	/*	Soribada限制	0：禁用1：启用*/
	UINT32	ulMsnCfg;		/*	MSN限制		0：禁用1：启用*/
	UINT32	ulQQCfg;		/*	QQ限制	 	0：禁用1：启用*/
	UINT32	ulYahooCfg;		/*	Yahoo Messager限制		0：禁用1：启用*/
	UINT32	ulSkypeCfg;		/*	Skype限制	 	0：禁用1：启用*/
} AC_DEVM_FWL7MATCH_CONFIG_T;

/* NAT全局配置*/
typedef struct {
	UINT32	ulNatSwitch;	/*	NAT开关		0：禁用1：启用*/
	UINT32	ulNatDefaultRuleOn;	/*	是否启用缺省NAT规则		0：禁用1：启用*/
}AC_DEVM_NATGLOBAL_CONFIG_T;

/* 	NAT规则配置*/
typedef struct 
{
	UINT32   ulNatId;                  
	UINT32	ulNatAction;		/*	NAT类型
							0-2
							0：基本NAT
							1：端口NAT
							2：公网IP透传*/
	/* add by gwx 2013-12-10 for task1173 */
	UINT32	ulNatOutIfType;	/*NAT出端口类型0:br0 2:br2*/
							
	UINT8	aucSrcIp[4];			/*	内网IP 地址		无*/
	UINT8	aucSrcIpMask[4];		/*	内网IP掩码		无*/
	UINT8	aucNatIpBegin[4];	/*	起始外网IP地址		无*/
	UINT8	aucNatIpEnd[4];		/*	结束外网IP地址		无*/
} AC_DEVM_NAT_CONFIG_T;

/* 	IDS规则配置*/
typedef struct 
{
	UINT32  ulIcmpFlooding	       ;   /* ICMP泛洪防护		*/   
	UINT32  ulIcmpStatInterval;	        /* ICMP统计间隔	 */
	UINT32  ulIcmpFloodingThreshold;    /* ICMP泛洪门限	*/

	UINT32  ulArpFlooding	        	;   /* ARP泛洪防护 		*/   
	UINT32  ulArpStatInterval;  	/* ARP统计间隔 */
	UINT32  ulArpFloodingThreshold;	/* ARP泛洪门限 */

	UINT32  ulUDPFlooding	        	;   /* Udp泛洪防护	    		*/   
	UINT32  ulUDPStatInterval;	        /* UDP统计间隔	 */
	UINT32  ulUDPFloodingThreshold;    /* UDP泛洪门限	*/

	UINT32  ulTcpSynFlooding	    	;   /* TCPSYN 泛洪防护 	*/	
	UINT32  ulTcpSynStatInterval;	        /* TCP SYN统计间隔	 */
	UINT32  ulTcpSynFloodingThreshold;    /* TCP SYN 泛洪门限	*/

	UINT32  ulDetectUdpScan	    	;   /* UDP 扫描检测		*/   
	UINT32  ulDetectTcpScan	    	;   /* TCP 扫描检测		*/   
	UINT32  ulDetectInvalidMac	;   /* 非法MAC检测	    	*/   
	UINT32  ulDetectInvalidProto	;   /* 非法协议检测		*/   
	UINT32  ulDetectInvalidLength	;   /* 非法报文长度检测	*/	
	UINT32  ulDetectInvalidStatInterval;	/* 非法报文统计间隔	*/
	UINT32  ulDetectInvalidThreshold;	    /* 非法报文攻击门限	*/
} AC_DEVM_IDSRULE_CONFIG_T;

/* 	IDS策略配置*/
typedef struct 
{
	UINT32  ulGenEvent	        		;   /* 入侵告警			*/   
	UINT32  ulDisableAccess	        	;   /* 禁止入侵者接入 		*/
	UINT32		ulLetOffPeriod;				/*解禁时间 */
} AC_DEVM_IDSSTRY_CONFIG_T;

/* 	DHCP for STA 全局配置 */
typedef struct 
{
	UINT32	ulEnableDhcpServer;			/*	DHCP功能角色*/		
	UINT32	ulEnableDhcpSnooping;		/*	启用DHCP Snooping功能*/
	/* add by gwx 2013-3-12 for task532 */
	UINT32   ulEnableOption60;                    /* 启用Option 60功能*/
	UINT8	aucDhcpServerMaster[4];		/*	主DHCP中继服务器地址*/
	UINT8	aucDhcpServerSlave[4];		/*	备DHCP中继服务器地址*/	
} AC_DEVM_STADHCPGLOBAL_CONFIG_T;

/* 	DHCP for STA 静态绑定IP配置 */
typedef struct 
{
	CHAR	acDescr[32];				/* 用于标识主机*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;
} AC_DEVM_STADHCPSTATICIP_CONFIG_T;

/* 	DHCP for STA 动态IP地址池配置*/
typedef struct 
{
	UINT32	ulId ;						/* 地址池编号 */
	CHAR    	acIpPoolNAme[32]	    	;   	/* 名称                     */
	UINT8   	aucBeginIp[4]	        		;   	/* 起始地址                 */
	UINT8   	aucEndIp[4]	            		;   	/* 结束地址                 */
	UINT8   	aucMask[4]	            		;   	/* 掩码                     */
	UINT8	aucReservedIp1[4];				/* 保留IP地址1 */
	UINT8	aucReservedIp2[4];				/* 保留IP地址2 */
	UINT8	aucReservedIp3[4];				/* 保留IP地址3 */	
	UINT8	aucReservedIp4[4];				/* 保留IP地址4 */	
	UINT32  	ulLease                 		;   		/* 租约期限 单位：分        */
	CHAR    	acDomainName[256]	    	;   		/* 域名后缀                 */
	UINT8   	aucDnsIpMaster[4]      	;   		/* 主用DNS服务器IP地址      */
	UINT8   	aucGatewayIpMaster[4] 	;   		/* 主用网关IP地址           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* 备用DNS服务器IP地址      */
	UINT8   	aucGatewayIpSlave[4]    	;  		/* 备用网关IP地址           */
	/* add by gwx 2013-3-12 for task532 */
	CHAR       acVendorName[64];                        /* 制造商信息，默认为空*/

	UINT32	ulVlanId1;						/* 绑定VLAN 1: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId2;						/* 绑定VLAN 2: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId3;						/* 绑定VLAN 3: 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId4;						/* 绑定VLAN 4: 0~4094 0表示适用于所有VLAN */
} AC_DEVM_STADHCPDYNIP_CONFIG_T;

/* 	DHCP for AP 全局配置 */
typedef struct 
{
	UINT32	ulEnableDhcpServer;			/*	DHCP功能角色*/		
	UINT32	ulEnableDhcpSnooping;		/*	启用DHCP Snooping功能*/
	UINT32	ulEnableOption43;			/*	启用Option 43功能*/
	/* add by gwx 2013-3-12 for task532 */
	UINT32   ulEnableOption60;                    /* 启用Option 60功能*/
	UINT8	aucDhcpServerMaster[4];		/*	主DHCP中继服务器地址*/
	UINT8	aucDhcpServerSlave[4];		/*	备DHCP中继服务器地址*/
	UINT8	aucAcIpMaster[4];			/*	主AC地址*/
	UINT8	aucAcIpSlave[4];				/*	备AC地址*/
} AC_DEVM_APDHCPGLOBAL_CONFIG_T;

/* 	DHCP for AP 静态绑定IP配置 */
typedef struct 
{
	CHAR	acDescr[32];				/* 用于标识主机*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;
} AC_DEVM_APDHCPSTATICIP_CONFIG_T;

/* 	DHCP for AP 动态IP地址池配置*/
typedef struct 
{
	UINT32	ulId ;						/* 地址池编号 */
	CHAR    	acIpPoolNAme[32]	    	;   	/* 名称                     */
	UINT8   	aucBeginIp[4]	        		;   	/* 起始地址                 */
	UINT8   	aucEndIp[4]	            		;   	/* 结束地址                 */
	UINT8   	aucMask[4]	            		;   	/* 掩码                     */
	UINT8	aucReservedIp1[4];				/* 保留IP地址1 */
	UINT8	aucReservedIp2[4];				/* 保留IP地址2 */
	UINT8	aucReservedIp3[4];				/* 保留IP地址3 */	
	UINT8	aucReservedIp4[4];				/* 保留IP地址4 */	
	UINT32  	ulLease                 		;   		/* 租约期限 单位：分        */
	CHAR    	acDomainName[256]	    	;   		/* 域名后缀                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* 主用DNS服务器IP地址      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* 主用网关IP地址           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* 备用DNS服务器IP地址      */
	/* add by gwx 2013-3-12 for task532 */
	CHAR       acVendorName[64];                        /* 制造商信息，默认为空*/

	UINT32	ulVlanId1;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId2;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId3;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	UINT32	ulVlanId4;						/* 绑定VLAN1 : 0~4094 0表示适用于所有VLAN */
	/* add by gwx 2012-9-12 汉铭辽宁联通的外场需求，
	使用一台AC作为DHCP server，为多台AC的AP分配地址*/
	UINT8	aucAcIpMaster[4];			/*	主AC地址*/
	UINT8	aucAcIpSlave[4];				/*	备AC地址*/
} AC_DEVM_APDHCPDYNIP_CONFIG_T;

/* 	QOS全局配置*/
typedef struct 
{
	UINT32	ulQosSwitch;				/* QOS流控功能开关: 0/1  禁用/启用*/
	UINT32	ulQosPrioSwitch;			/* QOS优先级功能开关：0/1  禁用/启用 */
} AC_DEVM_QOSGLOBAL_CONFIG_T;

/* 	用户QOS全局配置*/
typedef struct 
{
	UINT32		ulUserPri;					/* 用户优先级 */
	UINT32		ulUpBand;					/* 用户上行保证带宽*/
	UINT32		ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32		ulDownBand;					/* 用户下行保证带宽*/
	UINT32		ulDownBandMax;				/* 用户下行最大带宽*/
} AC_DEVM_QOSUSRDFT_CONFIG_T;

/* 	VLAN QOS配置*/
typedef struct 
{
	UINT32		ulVlanId ;
	UINT32		ulUserPri;					/* 用户优先级 */
	UINT32		ulUpBand;					/* 用户上行保证带宽*/
	UINT32		ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32		ulDownBand;					/* 用户下行保证带宽*/
	UINT32		ulDownBandMax;				/* 用户下行最大带宽*/
} AC_DEVM_QOSVLAN_CONFIG_T;

/* 	SSID QOS配置*/
typedef struct 
{
	UINT32		ulId ;
	CHAR		acSsid[32];
	UINT32		ulUserPri;					/* 用户优先级 */
	UINT32		ulUpBand;					/* 用户上行保证带宽*/
	UINT32		ulUpBandMax;				/* 用户上行最大带宽*/
	UINT32		ulDownBand;					/* 用户下行保证带宽*/
	UINT32		ulDownBandMax;				/* 用户下行最大带宽*/
} AC_DEVM_QOSSSID_CONFIG_T;

/* 	告警过滤配置 */
typedef struct 
{
	UINT32		ulAlarmNo;
	CHAR		acAlarmName[32] ;	/* 告警名称 */
	UINT32		ulAlarmIsValid;
} AC_DEVM_ALARMFILTER_CONFIG_T;

/* AC 告警门限配置*/
typedef struct 
{
	UINT32  ulAlarmResendWaitingTime;	/* 告警重发等待时间 */
	UINT32  ulCpuLoadPeriod;    	/*		CPU负荷采样周期 */
	UINT32  ulCpuLoadCount;     	/*		CPU负荷持续次数 */
	UINT32  ulCpuLoadHigh;		/*      CPU负荷告警产生门限 */
	UINT32  ulCpuLoadLow;       	/*      CPU负荷告警消除门限 */
			
	UINT32  ulMemLoadPeriod;    	/*  	内存利用率采样周期 */
	UINT32  ulMemLoadCount;     	/*  	内存利用率持续次数 */
	UINT32  ulMemLoadHigh;      	/*  	内存利用率告警产生门限 */
	UINT32  ulMemLoadLow;       	/*      内存利用率告警消除门限 */
			
	UINT32  ulTempPeriod;       	/*	设备温度采样周期 */
	UINT32  ulTempCount;        	/*	设备温度持续次数 */
	UINT32  ulTempHigh;        	 	/*	设备温度告警产生门限 */
	UINT32  ulTempLow;          	/*	设备温度告警消除门限 */
} AC_DEVM_ACALARMTHRESHOLD_CONFIG_T;

/* AP 告警门限配置*/
typedef struct 
{
	UINT32	ulWtpId;					/* 设备ID */
	
	UINT32  ulCpuLoadPeriod;    	/*		CPU负荷采样周期 */
	UINT32  ulCpuLoadCount;     	/*		CPU负荷持续次数 */
	UINT32  ulCpuLoadHigh;		/*      CPU负荷告警产生门限 */
	UINT32  ulCpuLoadLow;       	/*      CPU负荷告警消除门限 */
			
	UINT32  ulMemLoadPeriod;    	/*  	内存利用率采样周期 */
	UINT32  ulMemLoadCount;     	/*  	内存利用率持续次数 */
	UINT32  ulMemLoadHigh;      	/*  	内存利用率告警产生门限 */
	UINT32  ulMemLoadLow;       	/*      内存利用率告警消除门限 */
			
	UINT32  ulTempPeriod;       	/*	设备温度采样周期 */
	UINT32  ulTempCount;        	/*	设备温度持续次数 */
	UINT32  ulTempHigh;        	 	/*	设备温度告警产生门限 */
	UINT32  ulTempLow;          	/*	设备温度告警消除门限 */
	INT32	lLowTempHigh;		/*		设备低温告警产生门限	－50～0	－30	℃*/
	INT32	lLowTempLow;		/*		设备低温告警消除门限	－50～0	－20	℃*/
} AC_DEVM_WTPALARMTHRESHOLD_CONFIG_T;

/* 	性能计数器组配置*/
typedef struct 
{
	UINT32		ulCounterGroupId;
	UINT32		ulCounterGroupPeriod;
	UINT32		ulCounterGroupIsInvalid;
} AC_DEVM_PERFCOUNTER_CONFIG_T;

//AS服务器配置AC_DEVM_WAPIAS_CONFIG_T
typedef struct 
{
	UINT8   acAsIp[4];  		/*	AS服务器IP  */
	UINT32  ulAsPort;   		/*	AS服务器Port	*/
	UINT32  ulAsAuthCert;   	/*		AS证书验证	0：禁用 1：启用*/
	UINT32  ulCertFileSize; 	/*		AS证书文件大小	*/
	UINT8   aucCertFileContent[4096];   /*	AS证书文件内容	*/
} AC_DEVM_WAPIAS_CONFIG_T;


//	WAPI参数配置AC_DEVM_WAPI_CONFIG_T
typedef struct 
{
	UINT32  ulWapiSetupId;  		/*		WAPI配置ID	0～15 */
	CHAR    acName[32];     		/*	    WAPI配置名称	*/
	UINT32  ulWapiCertAkm;  		/*		证书型AKM	0：禁用 1：启用 */
	UINT32  ulWapiPskAkm;   		/*		预共享密钥AKM	0：禁用 1：启用 */
	UINT32  ulWapiPreAuth;  		/*		WAPI预鉴权	0：禁用 1：启用 */
	UINT32  ulUnicastCipher;   	 /*		单播加密套件	1：SMS4 */
	UINT32  ulUnicastKeyLen;    	/*		单播密钥长度	256 */
	UINT32  ulUnicastKeyUpdateManner;   /*		单播密钥更新机制	1：不更新
					                                    2：基于时间
					                                    3：基于包数
					                                    4：基于时间和包数
					                                    */
	UINT32  ulUnicastKeyValidity;       	/*		单播密钥更新周期	>0 */
	UINT32  ulUnicastKeyPkgs;       	/*	    单播密钥更新包数目	>0 */
	UINT32  ulMulticastCipher;         	/*		组播加密套件	1：SMS4 */
	UINT32  ulMulticastKeyLen;          	/*		组播密钥长度	256 */
	UINT32  ulMulticastKeyUpdateManner; /*		组播密钥更新机制	1：不更新
				                                            2：基于时间
				                                            3：基于包数
				                                            4：基于时间和包数
				                                   	 */
	UINT32  ulMulticastKeyValidity;     			/*		组播密钥有效时间	>0 */
	UINT32  ulMulticastKeyPkgs;     			/*	    组播密钥有效包数	>0 */
	UINT32  ulMulticastRekeyStrict; 			/*  	STA离开BSS后更新组播密钥	0：禁用 1：启用 */
	UINT32  ulAuthRetryTimes;		    		/*      鉴权握手协议重试次数	>0 */
	UINT32  ulMulticastRekeyRetryTimes; 		/*		组播密钥握手协议重试次数	>0 */
	UINT32  ulUnicastRekeyRetryTimes;  		 /*		单播密钥握手协议重试次数	>0 */
	UINT32  ulBasicKeyValidity;    			 	/*	    基密钥有效期	>0  */
	UINT32  ulBasicKeyReAuthThreshold;  		/*		基密钥重新鉴权的门限时间	0-100 */
	UINT32  ulSecAssociateTimeout;			/*      安全关联的超时时间	>0 */
} AC_DEVM_WAPI_CONFIG_T;

//6.1.76	WAPI证书配置AC_DEVM_WAPICERTFILE_CONFIG_T
typedef struct 
{
	UINT32  ulCertId;           			/*	证书ID */
	CHAR    acCertDesc[128];   		/*	证书描述 */
	UINT32  ulCertFileSize; 			/*	证书文件大小 */
	UINT8   aucCertFileContent[4096];  /*	证书文件内容 */
	UINT8   aucBindMac[6];  	        	/* 证书绑定的MAC地址 */
	UINT8   aucRsv[2];                  		/* 填充字节 */
} AC_DEVM_WAPICERTFILE_CONFIG_T;


/* 无线设备邻居配置*/
/* 邻居类型*/
enum {
	AC_NEIGH_TYPE_WTP,	/* 设备级*/
	AC_NEIGH_TYPE_VDEV	/* Radio级 */
} AC_NEIGH_TYPE;

enum {
	AC_NEIGH_RELATION_UNI,	/* 单向邻居*/
	AC_NEIGH_RELATION_BIO		/* 双向邻居*/
} AC_NEIGH_RELATION;

typedef struct 
{
	AC_VDEVID_T		stVdevId ;						/* 邻居无线设备 */
	UINT32	ulNeighRelation ;					/* 邻居关系 */
	UINT32	ulLoadNeigh ;					/* 是否负荷均衡邻居 */
	UINT32	ulCoverageNeigh	;				/* 是否覆盖补偿邻居 */
} AC_DEVM_VDEVNEIGH_CONFIG_T;

/* STP协议参数配置*/
typedef struct 
{
	UINT32	ulStpHello;
	UINT32	ulStpForwardDelay;
	UINT32	ulStpMaxage;
	UINT32	ulStpBrPri;
} AC_DEVM_STP_CONFIG_T;


/*	PPPoE服务器配置AC_DEVM_PPPOESERVER_CONFIG_T */
typedef struct 
{
	UINT32	ulEnablePPPoEServer;
	CHAR	acPPPoEServerName[32];
	UINT8	aucPPPLocalIp[4] ;
	UINT8	aucIpPoolStartIP[4] ;
	UINT8	aucIpPoolEndIP[4] ;
	UINT8	aucPrimaryDNS[4] ;
	UINT8	aucSlaveDNS[4] ;
	UINT32	ulAuthMode ;
	UINT32	ulPPPMtu ;
	UINT32	ulPPPMru ;

	/* 鉴权服务器配置 */
    	AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    	AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;
    
	/* 计费服务器配置 */
    	AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    	AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
} AC_DEVM_PPPOESERVER_CONFIG_T;

/* AC主备相关配置*/
typedef struct
{
	UINT32	ulMsMode;		/* 工作模式 */
	UINT32	ulEchoInterval;	/* 保活间隔 */
	UINT32	ulEchoNum;		/* 保活超时次数 */
	UINT32	ulBakAcNum;	/* 备份AC数目 */
	UINT32	ulPeerAcId1;		/* 备份设备1 ID  */
	UINT8	aucPeerAcIp1[4];	/* 备份设备1 IP  */
	UINT8	aucPeerAcGw1[4];	/* 备份设备1缺省网关*/
	UINT8	aucPeerAcMngIp1[4];	/*add by gwx 2011-10-28 for 广州移动， 备份设备1管理IP */
	UINT32	ulPeerAcId2;		/* 备份设备2 ID  */
	UINT8	aucPeerAcIp2[4];	/* 备份设备2 IP  */
	UINT8	aucPeerAcGw2[4];	/* 备份设备2缺省网关*/
	UINT8	aucPeerAcMngIp2[4];	/*add by gwx 2011-10-28 for 广州移动， 备份设备2管理IP */
	UINT32	ulPeerAcId3;		/* 备份设备3 ID  */
	UINT8	aucPeerAcIp3[4];	/* 备份设备3 IP  */
	UINT8	aucPeerAcGw3[4];	/* 备份设备3缺省网关*/
	UINT8	aucPeerAcMngIp3[4];	/*add by gwx 2011-10-28 for 广州移动， 备份设备3管理IP */

	UINT32	ulEnableVrrp;		/*		VRRP开关*/
	
	/* 备份设备1虚拟IP */
	UINT8	aucVrrpIp1[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp2[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp3[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp4[4];		/*	虚拟IP4 */

	/* 备份设备2虚拟IP */
	UINT8	aucVrrpIp5[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp6[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp7[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp8[4];		/*	虚拟IP4 */

	/* 备份设备1虚拟IP */
	UINT8	aucVrrpIp9[4];		/*	虚拟IP1 */
	UINT8	aucVrrpIp10[4];		/*	虚拟IP2 */
	UINT8	aucVrrpIp11[4];		/*	虚拟IP3 */
	UINT8	aucVrrpIp12[4];		/*	虚拟IP4 */
} AC_DEVM_MSSETUP_CONFIG_T;


/* 数据结构定义结束*/
/******************************************************************************/



/******************************************************************************/
/* 函数接口入出参结构定义开始*/
/* 获取3A服务器配置入出参结构体定义 */
typedef struct
{
    UINT32    ulRet;        /* 返回值，AC_OK表示成功，其它表示错误码 */
    AC_DEVM_RADIUS_SERVERS_T    stRadiusServers;
} AC_DEVM_GET_RADIUS_SERVERS_RSP_T;

/* 获取AC配置信息*/
typedef struct
{
    UINT32  ulRet;
    AC_DEVM_AC_OWNCONFIG_T  stAcOwnCfg;
} AC_DEVM_GET_AC_OWNCONFIG_RSP_T;

/* 获取AC MOID */
typedef struct
{
    	UINT32    ulRet;        					/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_OMA_MO_T	stAcMoid;			/* AC MOID */
} AC_DEVM_GET_AC_MOID_RSP_T;

/* 	功能描述：获取指定WTP设备的CAPWAP关联配置*/
/* 	输入参数结构：*/
typedef struct 
{
    	AC_WTPID_T    stWtpId;
}AC_DEVM_GET_WTPASSO_BYID_REQ_T;

/* 	输出参数结构：*/
typedef struct 
{
	UINT32	ulRet;
	UINT32	ulCfgDeviceType;
	AC_DEVM_WTPASSO_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTPASSO_BYID_RSP_T;

// 	功能描述：获取指定AC上行链路完整性检查配置
// 	输入参数结构：
//无。
// 	输出参数结构：
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ACKEEPER_CONFIG_T  stAcKeeperCfg;
}AC_DEVM_GET_ACKEEPERCFG_RSP_T;

// 	功能描述：设置AC上行链路状态
 //	输入参数结构：
typedef struct 
{
	UINT32	ulState;
}AC_DEVM_SET_ACUPLINKSTATE_REQ_T;

// 	输出参数结构：
typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_ACUPLINKSTATE_RSP_T;

/* 获取指定WTP设备配置*/
typedef struct 
{
    AC_WTPID_T    stWtpId;
}AC_DEVM_GET_WTP_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_WTP_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTP_BYID_RSP_T;

/* 获取WTP本设备的配置，WTP上调用*/
#define AC_CAPWAP_DISCOVERY_TYPE_AUTO		0
#define AC_CAPWAP_DISCOVERY_TYPE_DHCP		1
#define AC_CAPWAP_DISCOVERY_TYPE_DNS		2
#define AC_CAPWAP_DISCOVERY_TYPE_MULTICAST	3

#define AC_CAPWAP_PROTOCOL_DISCOVERY_TYPE_UNKNOWN	0
#define AC_CAPWAP_PROTOCOL_DISCOVERY_TYPE_STATIC		1
#define AC_CAPWAP_PROTOCOL_DISCOVERY_TYPE_DHCP		2
#define AC_CAPWAP_PROTOCOL_DISCOVERY_TYPE_DNS			3
#define AC_CAPWAP_PROTOCOL_DISCOVERY_TYPE_ACREFERRAL	4

typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_WTP_CONFIG_T 	stWtpCfg;
}AC_DEVM_GET_WTP_OWNCONFIG_RSP_T;

/*  获取WTP设备配置接口入出参结构体定义 */
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_WTP_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        	/* 返回值，AC_OK表示成功，其它表示错误码 */
    UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
    UINT32    ulWtpNum;     /* 有效WTP数量 */
    AC_DEVM_WTP_CONFIG_T    astWtp[10];
} AC_DEVM_GET_WTP_CONFIG_RSP_T;

// 	功能描述：根据WTP ID获取该WTP当前绑定的AC ID列表
// 	输入参数结构：
typedef AC_WTPID_T AC_DEVM_GET_BINDACID_REQ_T;

// 	输出参数结构：
typedef struct
{
	UINT32	ulRet;			/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulBindAcNum;	/* 绑定的AC数目 */
	UINT32	aulAcId[8];		/* 绑定的AC设备ID列表 */
} AC_DEVM_GET_BINDACID_RSP_T;

//	根据WTP ID获取该WTP当前连接的AC ID（新增）
 typedef AC_WTPID_T AC_DEVM_GET_CURACID_REQ_T;
 typedef struct
{
	UINT32	ulRet;			/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32	ulAcId;			/* 当前连接的AC ID */
} AC_DEVM_GET_CURACID_RSP_T;

/* 根据AP设备序列号获取AP设备配置*/
typedef struct 
{
	UINT8	aucDeviceId[6];	/* AP 设备序列号*/
	UINT8	aucRsv[2];		/* 填充字节*/
	UINT32	ulDeviceType;	/* 设备型号*/
} AC_DEVM_GET_WTP_BYSN_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulCfgDeviceType;		/* AC配置中的设备型号*/
	AC_DEVM_WTPASSO_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTP_BYSN_RSP_T;

typedef struct
{
	UINT32	ulDeviceType;
}AC_DEVM_ALLOCATE_WTPID_REQ_T; 

/* 2010-4-19 pyy 新增分配失败原因码*/
#define AC_DEVM_ALLOCATEFAIL_REASON_DIFFDEVICETYPE		((UINT32)1)	/* 设备类型不匹配*/
#define AC_DEVM_ALLOCATEFAIL_REASON_NOFREEASSO			((UINT32)2)	/* 无空闲关联*/

typedef struct
{
	UINT32	ulRet;
	UINT32	ulWtpId;
}AC_DEVM_ALLOCATE_WTPID_RSP_T;
 	
/* 获取接口配置入出参结构体定义 */
typedef AC_WTPID_T AC_DEVM_GET_IF_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        /* 返回值，AC_OK表示成功，其它表示错误码 */
    UINT32    ulIfNum;      /* 接口数 */
    AC_DEVM_IF_CONFIG_T        astIf[AC_IF_NUM_MAX_PER_WTP];
} AC_DEVM_GET_IF_CONFIG_RSP_T;

/* 	获取指定WTP设备的无线设备列表*/
typedef AC_WTPID_T AC_DEVM_GET_VDEVLIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulVdevNum;	/* 无线设备数 */
	AC_DEVM_VDEV_CONFIG_T		astVdevList[AC_VDEV_NUM_MAX_PER_WTP];
} AC_DEVM_GET_VDEVLIST_CONFIG_RSP_T;


//获取无线设备的邻居配置
typedef AC_VDEVID_T AC_DEVM_GET_VDEVNEIGH_CONFIG_REQ_T;
 
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_VDEVNEIGH_CONFIG_T		astVdevNeighCfg[16];
} AC_DEVM_GET_VDEVNEIGH_CONFIG_RSP_T;

 
// 	功能描述：根据无线设备标识获取无线设备的MOID
typedef AC_VDEVID_T  AC_DEVM_GET_VDEV_MOID_REQ_T;
 
typedef struct
{
    	UINT32    ulRet;        					/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_OMA_MO_T	stVdevMoid;			/* VDEV MOID */
} AC_DEVM_GET_VDEV_MOID_RSP_T;

/* 根据无线设备ID获取无线设备配置*/
typedef AC_VDEVID_T  AC_DEVM_GET_VDEV_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_VDEV_CONFIG_T	stCfg;
} AC_DEVM_GET_VDEV_BYID_RSP_T;


/* WTP 上获取所有无线设备的最大发射功率*/
typedef struct 
{
	UINT32	ulRet;
	UINT32	ulNum;
	AC_DEVM_VDEV_MAXPOWER_T	astMaxPower[4];
} AC_DEVM_GET_WTP_VDEVMAXTXPOWER_RSP_T;

/* WTP 上获取所有回传模块的BSSID */
typedef struct 
{
	UINT32	ulRet;
    	UINT32  	ulNum;  
    	AC_DEVM_ADHOC_BSSID_T astBssid[4];
} AC_DEVM_GET_WTP_ADHOCBSSID_RSP_T;


/* 获取VAP配置入出参结构体定义 */
typedef	struct
{
	AC_IFID_T	stIfId;
	UINT32		ulStartRec;		/* 查询的起始记录号 */
								/*
								第一次调用时，入参ulStartRec填0
								后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
								*/
} AC_DEVM_GET_VAP_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        		/* 返回值，AC_OK表示成功，其它表示错误码 */
    UINT32	ulFinish;			/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
    UINT32    ulVapNum;    		/* VAP数 */
    AC_DEVM_VAP_CONFIG_T        astVap[10];
} AC_DEVM_GET_VAP_CONFIG_RSP_T;

/* 获取指定无线设备上的VAP列表（新增） */
typedef	struct
{
	AC_VDEVID_T		stVdevId;
	UINT32			ulStartRec;		/* 查询的起始记录号 */
									/*
									第一次调用时，入参ulStartRec填0
									后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
									*/
} AC_DEVM_GET_VAP_CONFIG_BYVDEV_REQ_T;

typedef AC_DEVM_GET_VAP_CONFIG_RSP_T AC_DEVM_GET_VAP_CONFIG_BYVDEV_RSP_T;

/* WTP 上获取本设备所有VAP BSSID信息 */
typedef struct 
{
    UINT32  ulRet;
    UINT32  ulNum;  
    AC_DEVM_VAP_BSSID_T astVapBssid[64];    /* 每个WTP上的最大VAP数量, 待修改 */
} AC_DEVM_GET_WTP_VAPBSSID_RSP_T;

/* WTP上获取本设备所有VAP的流量统计信息*/
typedef struct 
{
	UINT32 ulRet;
	UINT32 ulNum;
	AC_DEVM_VAP_TRAFFICSTAT_T	astVapStat[64];
} AC_DEVM_GET_WTP_VAPTRAFFICSTAT_RSP_T;

/* WTP上获取本设备所有VAP无线统计信息*/
typedef struct
{
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;

    	/* 空口收发统计*/
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

	/* 用户连接统计*/
	UINT32	ulAccessTimes;		/*	AP的无线用户链接次数*/
	UINT32	ulAccessFailTimes;	/*	AP的无线用户链接失败次数*/
	UINT32	ulAccessRetryTimes;	/*	AP的无线用户重链接次数*/
	UINT32	ulAccessDenyTimes;	/*	AP的无线用户链接拒绝次数*/
	UINT32	ulAccessOutTimes1;	/*	因用户离开而导致解关联的次数*/
	UINT32	ulAccessOutTimes2;	/*	因AP能力不足而导致解关联的次数*/
	UINT32	ulAccessOutTimes3;	/*	因异常情况而导致解关联的次数*/
	UINT32	ulAccessOutTimes4;	/*	其它原因导致解关联的次数*/
}AC_DEVM_VAP_WIFISTAT_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulNum;
	AC_DEVM_VAP_WIFISTAT_T		astVapWifiStat[64];
} AC_DEVM_GET_WTP_VAPWIFISTAT_RSP_T;



/* 获取VAP MOID 入出参结构体定义 */
typedef AC_VAPID_T  AC_DEVM_GET_VAP_MOID_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_OMA_MO_T	stVapMoid;	/* VAP MOID */
} AC_DEVM_GET_VAP_MOID_RSP_T;

//	根据VAP BSSID获取VAP标识（新增）
 typedef struct 
{
	UINT8       aucBssid[6];    /* VAP BSSID */
	UINT8       aucRsv[2];      /* 填充字节 */
} AC_DEVM_GET_VAPID_BYBSSID_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_VAPID_T	stVapId;			/* VAP ID */
} AC_DEVM_GET_VAPID_BYBSSID_RSP_T;

/* 获取指定WTP设备的VAP列表 */
typedef AC_WTPID_T	AC_DEVM_GET_VAP_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* 返回值，AC_OK表示成功，其它表示错误码 */
    	UINT32	ulNum;
	AC_VAPID_T	astVapId[AC_VAP_NUM_MAX_PER_WTP];	/* VAP ID 列表*/
	CHAR	aacSsid[AC_VAP_NUM_MAX_PER_WTP][32];	/* 对应的SSID列表*/
	UINT32	aulTrafficMode[AC_VAP_NUM_MAX_PER_WTP];	/* 2010-4-20 pyy 新增: VAP业务转发模式*/
} AC_DEVM_GET_VAP_CONFIG_BYWTP_RSP_T;


/*	获取指定WTP设备的ADHOC列表（新增）*/
typedef AC_WTPID_T	AC_DEVM_GET_ADHOC_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* 返回值，AC_OK表示成功，其它表示错误码 */
    	UINT32	ulNum;
	AC_ADHOCID_T	astAdhocId[AC_ADHOC_NUM_MAX_PER_WTP];	/* ADHOC ID 列表*/
} AC_DEVM_GET_ADHOC_CONFIG_BYWTP_RSP_T;

/* 设置WTP运行状态接口入出参结构体定义*/
typedef struct 
{
    AC_WTPID_T    stWtpId;
    UINT32    ulValue;
} AC_DEVM_SET_WTP_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_WTP_OPSTATE_RSP_T;

/* 设置从机相关对象运行状态结构体定义*/
typedef struct {
	UINT32	ulWtpId;
	UINT32    ulValue;
} AC_DEVM_SET_SLAVEOBJ_OPSTATE_REQ_T;

typedef struct {
	UINT32 	ulRet;
} AC_DEVM_SET_SLAVEOBJ_OPSTATE_RSP_T;

/* 设置VDEV运行状态接口入出参结构体定义*/
typedef struct 
{
    AC_VDEVID_T    stVdevId;
    UINT32    ulValue;
} AC_DEVM_SET_VDEV_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_VDEV_OPSTATE_RSP_T;

/* 设置VAP运行状态接口入出参结构体定义*/
typedef struct 
{
    AC_VAPID_T  stVapId;
    UINT32      ulValue;    /* NORMAL, FAULT */
    UINT32      ulReason;   /* 引起VAP运行状态变化的原因码: 
                               链路状态变化
                               管理状态变化 */
} AC_DEVM_SET_VAP_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_VAP_OPSTATE_RSP_T;

/* 设置AP设备关联状态接口入出参结构体定义*/
#define AC_DEVM_WTPASSO_NORMAL				0	/* 关联状态正常*/
#define AC_DEVM_WTPASSO_NODISCOVERY			1	/* 没有收到发现请求*/
#define AC_DEVM_WTPASSO_NOJOIN				2	/* 没有收到连接请求*/
#define AC_DEVM_WTPASSO_CONNAUTHFAIL		3	/* 鉴权失败*/
#define AC_DEVM_WTPASSO_OTHER				4	/* 其它原因*/

typedef struct 
{
	AC_WTPID_T	stWtpId;
	UINT32		ulAssoState;	
}AC_DEVM_SET_WTP_ASSOSTATE_REQ_T;

typedef struct 
{
	UINT32    ulRet;
}AC_DEVM_SET_WTP_ASSOSTATE_RSP_T;

/* 设置WTP SN */
typedef struct
{
	UINT32	ulWtpId;
	UINT8	aucSn[6];
	UINT8	aucRsv[2];
} AC_DEVM_SET_WTP_SN_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_WTP_SN_RSP_T;

/* 设置无线模块当前发射功率*/
typedef struct {
	AC_VDEVID_T		stVdevId;
	UINT32	ulDynPower;
} AC_DEVM_SET_VDEV_DYNPOWER_REQ_T;

typedef struct {
	UINT32 	ulRet;
} AC_DEVM_SET_VDEV_DYNPOWER_RSP_T;

// 	功能描述：设置指定AP设备的IP地址
// 	输入参数结构：
typedef struct 
{
	AC_WTPID_T	stWtpId;
	AC_DEVM_WTPIP_CONFIG_T	stWtpIpCfg;
}AC_DEVM_SET_WTPIP_REQ_T;

// 	输出参数结构：
typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_WTPIP_RSP_T;

// 	功能描述：根据WTPID获取指定AP的IP地址
// 	输入参数结构：
typedef struct 
{
	AC_WTPID_T	stWtpId;
}AC_DEVM_GET_WTPIP_REQ_T;
// 	输出参数结构：
typedef struct 
{
	UINT32	ulRet;
	UINT8	aucIp[4];
}AC_DEVM_GET_WTPIP_RSP_T;

/* 根据WTP IP地址获取WTP IP */
typedef struct 
{
	UINT8	aucIp[4];
}AC_DEVM_GET_WTPID_BYIP_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulWtpId;
}AC_DEVM_GET_WTPID_BYIP_RSP_T;


/* 获取SNMP-V2相关配置（新增） */
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPV2_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPV2_CONFIG_RSP_T;

/*获取SNMP-V3相关配置（新增） */
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPV3_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPV3_CONFIG_RSP_T;

/* 	功能描述：获取SNMP TRAP相关配置*/
/*	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPTRAP_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPTRAP_CONFIG_RSP_T;

/* 功能描述: 获取AC当前的软件版本号信息*/
/*	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	CHAR	acSwVersion[32];	/* AC 当前软件版本*/
} AC_DEVM_GET_ACSWVERSION_RSP_T;


/* 功能描述: AP版本升级通知*/
typedef struct {
	UINT32	ulWtpId;
} AC_DEVM_SET_WTPSWUPDATE_REQ_T;

typedef struct {
	UINT32	ulRet;
} AC_DEVM_SET_WTPSWUPDATE_RSP_T;

/* 功能描述: AP配置修改通知*/
typedef struct {
	UINT32	ulWtpId;
} AC_DEVM_SET_WTPCFGUPDATE_REQ_T;

typedef struct {
	UINT32	ulRet;
} AC_DEVM_SET_WTPCFGUPDATE_RSP_T;

/* 获取AC支持的AP软件版本列表信息*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ASSOCSWVERSETUP_CONFIG_T	stCfg;
} AC_DEVM_GET_ACASSOCSWVER_CONFIG_RSP_T;

/* 获取指定AP的软件版本配置信息*/
typedef struct 
{
	UINT32	ulWtpId;	
} AC_DEVM_GET_WTPSWVERSION_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_SWSVR_CONFIG_T	stCfg;
}AC_DEVM_GET_WTPSWVERSION_RSP_T;

/* 设置AP当前软件版本号*/
typedef struct
{
	UINT32	ulWtpId;
	CHAR	acSwVer[32];			/* AP设备当前版本*/
	CHAR	acTargetSwVer[32];		/* AP设备目标版本*/
} AC_DEVM_SET_WTPCURSWVERSION_REQ_T;

typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_WTPCURSWVERSION_RSP_T;

/*获取AP当前配置数据版本号*/
typedef struct
{
	UINT32	ulWtpId;
} AC_DEVM_GET_WTPCFGVERSION_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulCfgVersion;	/* 配置数据版本号*/
} AC_DEVM_GET_WTPCFGVERSION_RSP_T;


/*	获取AC SNTP全局配置（新增） */
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_ACSNTP_CONFIG_T	stSntpCfg;
} AC_DEVM_GET_ACSNTP_CONFIG_RSP_T;

/* 获取WTP SNTP全局配置*/
/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WTPSNTP_CONFIG_T	stSntpCfg;
} AC_DEVM_GET_WTPSNTP_CONFIG_RSP_T;

/*获取AC桥组列表配置（新增）*/
/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	/* 端口组数 */
	AC_DEVM_BRIDGE_CONFIG_T		astAcBridgeCfg[4];
} AC_DEVM_GET_ACBRIDGE_CONFIG_RSP_T;

/* 	获取AC物理端口配置（新增）*/
enum {
	AC_PORT_TYPE_INVALID	= 0,
	AC_PORT_TYPE_FITLAN	= 1,
	AC_PORT_TYPE_FATLAN	= 2,
	AC_PORT_TYPE_L2WAN	= 3,
	AC_PORT_TYPE_L3WAN	= 4,
	AC_PORT_TYPE_HYBRID	= 5,
	AC_PORT_TYPE_MS		= 6,
} AC_PORT_TYPE_E;

enum {
	AC_VLANIF_TYPE_AUTO	= 0,
	AC_VLANIF_TYPE_FITLAN	= 1,
	AC_VLANIF_TYPE_FATLAN	= 2,
	AC_VLANIF_TYPE_L2WAN	= 3,
	AC_VLANIF_TYPE_L3WAN	= 4,
} AC_VLANIF_TYPE_E;

enum {
	AC_PORT_STATE_DOWN	= 0,
	AC_PORT_STATE_UP		= 1,
} AC_PORT_STATE_E;

/* 2012.10.10 add by wns for BUG-687/688 */
enum {
	AC_SpeedUplex_Mode_Auto		=0,
	AC_SpeedUplex_Mode_10Full 	=1,
	AC_SpeedUplex_Mode_100Full	=2,
} AC_SpeedUplex_Mode_E;
/* 2012.10.10 end */
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	/* 端口数 */
	AC_DEVM_ACPORT_CONFIG_T		astAcPortCfg[AC_PORT_NUM_MAX];
} AC_DEVM_GET_ACPORT_CONFIG_RSP_T;

/*	获取指定WTP设备的物理端口列表（新增）*/
typedef AC_WTPID_T	AC_DEVM_GET_ENET_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        									/* 返回值，AC_OK表示成功，其它表示错误码 */
    	UINT32	ulNum;
    	AC_DEVM_ENET_CONFIG_T	astEnetCfg[AC_ENET_NUM_MAX_PER_WTP];/* 有线物理端口列表*/
} AC_DEVM_GET_ENET_CONFIG_BYWTP_RSP_T;

/* 获取AC IP地址配置*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ACIP_CONFIG_T	stAcIp;
} AC_DEVM_GET_ACIP_CONFIG_RSP_T;

/* 获取L2-WAN/FAT-LAN桥配置*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_BRIDGE_CONFIG_T	stBr;
} AC_DEVM_GET_L2WAN_CONFIG_RSP_T;

/* 获取L3-WAN桥配置*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_BRIDGE_CONFIG_T	stBr;
} AC_DEVM_GET_L3WAN_CONFIG_RSP_T;

/* 根据AC 物理端口号获取端口配置*/
typedef struct
{
	UINT32	ulIfId;	/* 物理端口号*/
}AC_DEVM_GET_ACPORT_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_ACPORT_CONFIG_T	stAcPort;
} AC_DEVM_GET_ACPORT_BYID_RSP_T;

/* 获取第一组IP */
typedef struct
{
	UINT32	ulRet;
	UINT8	aucFatLanIp[4];
	UINT8	aucFatLanMask[4];
	UINT8	aucL2WanIp[4];
	UINT8	aucL2WanMask[4];
}AC_DEVM_GET_L2WAN_FIRSTIP_CONFIG_RSP_T;


typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;		/* 端口数 */
	AC_DEVM_ACPORT_CONFIG_T		astAcPortCfg[AC_PORT_NUM_MAX];
} AC_DEVM_GET_ACMSPORT_CONFIG_RSP_T;

/* 获取VLAN全局配置*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_VLANGLOBAL_CONFIG_T		stVlanCfg;
} AC_DEVM_GET_VLANGLOBAL_CONFIG_RSP_T;

/* 	获取VLAN基本配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_VLAN_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLAN_CONFIG_T		astVlanCfg[32];
} AC_DEVM_GET_VLAN_CONFIG_RSP_T;

/* 获取SSID-VLAN映射配置*/
typedef struct 
{
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_VLANSSIDMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
						AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANSSIDMAP_CONFIG_T		astVlanSsidMapCfg[64];
} AC_DEVM_GET_VLANSSIDMAP_CONFIG_RSP_T;


/* 	获取端口-VLAN映射配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_VLANIFMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
						AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANIFMAP_CONFIG_T		astVlanIfMapCfg[64];
} AC_DEVM_GET_VLANIFMAP_CONFIG_RSP_T;

/* 	获取MAC-VLAN映射配置（新增）*/
typedef struct {
UINT32		ulStartRec;		/* 查询的起始记录号 */
							/*
							第一次调用时，入参ulStartRec填0
							后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
							*/
} AC_DEVM_GET_VLANMACMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANMACMAP_CONFIG_T		astVlanMacMapCfg[100];
} AC_DEVM_GET_VLANMACMAP_CONFIG_RSP_T;

/*获取VLAN MAC地址过滤策略配置（新增）*/
/* 	输入参数结构：*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_REQ_T;

/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANACCMACPOLICY_CONFIG_T	astPolicyCfg[100];
} AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_RSP_T;

/* 	获取VLAN MAC过滤列表配置（新增） */
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_VLANACCMAC_CONFIG_REQ_T;
 
typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANACCMAC_CONFIG_T		astVlanAccMacCfg[100];
} AC_DEVM_GET_VLANACCMAC_CONFIG_RSP_T;

/* 2009-11-5 pyy 新增*/
/* 获取VLAN在各端口上的启用情况*/
typedef struct
{
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_VLANFORIF_CONFIG_REQ_T;

typedef struct
{
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulVlanNum;	/* 本次调用返回的VLAN配置数*/
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_VLANIFMAP_CONFIG_T		astVlanIfMapCfg[64];
}AC_DEVM_GET_VLANFORIF_CONFIG_RSP_T;


/* 	获取IGMP Snooping配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IGMPSNOOP_CONFIG_T		stIgmpSnoopCfg;
} AC_DEVM_GET_IGMPSNOOP_CONFIG_RSP_T;
 
/* 	获取IGMP Proxy配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IGMPPROXY_CONFIG_T		stIgmpProxyCfg;
} AC_DEVM_GET_IGMPPROXY_CONFIG_RSP_T;

/* 	获取静态路由配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_ROUTESTATIC_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;	
	AC_DEVM_ROUTESTATIC_CONFIG_T		astRouteStatic[100];
} AC_DEVM_GET_ROUTESTATIC_CONFIG_RSP_T;

/*	获取RIP全局配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_RIPGLOBAL_CONFIG_T		stRipGlobalCfg;
} AC_DEVM_GET_RIPGLOBAL_CONFIG_RSP_T;

/* 	获取RIP通告网段配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	
	AC_DEVM_RIPNOTIFYNET_CONFIG_T		astRipNotifyIp[16];
} AC_DEVM_GET_RIPNOTIFYIP_CONFIG_RSP_T;

/* 	获取防火墙全局配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FWGLOBAL_CONFIG_T		stFwGlobalCfg;
} AC_DEVM_GET_FWGLOBAL_CONFIG_RSP_T;

 	
/* 	获取防火墙规则配置（新增）*/
 typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_FWRULE_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_FWRULE_CONFIG_T		astFwRule[8];
} AC_DEVM_GET_FWRULE_CONFIG_RSP_T;

/* 获取NAT全局配置*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_NATGLOBAL_CONFIG_T		stNatGlobalCfg;
} AC_DEVM_GET_NATGLOBAL_CONFIG_RSP_T;

/* 	获取NAT配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	
	AC_DEVM_NAT_CONFIG_T		astNat[32];
} AC_DEVM_GET_NAT_CONFIG_RSP_T;

/* 获取P2P限制配置*/
typedef struct {
	UINT32	ulRet;
	AC_DEVM_FWL7MATCH_CONFIG_T	stP2PCfg;
} AC_DEVM_GET_P2P_CONFIG_RSP_T;

/* 	获取IDS规则配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IDSRULE_CONFIG_T		stIdsRule;
} AC_DEVM_GET_IDSRULE_CONFIG_RSP_T;

/* 	获取IDS策略配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IDSSTRY_CONFIG_T		stIdsStry;
} AC_DEVM_GET_IDSSTRY_CONFIG_RSP_T;

/*	获取DHCP for STA 全局配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_STADHCPGLOBAL_CONFIG_T		stDhcpGlobalCfg;
} AC_DEVM_GET_STADHCPGLOBAL_CONFIG_RSP_T;

/* 	获取DHCP for STA 静态绑定IP配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_STADHCPSTATICIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */

	UINT32	ulNum;
	AC_DEVM_STADHCPSTATICIP_CONFIG_T		astDhcpStaticIp[8];
} AC_DEVM_GET_STADHCPSTATICIP_CONFIG_RSP_T;
 	
/* 	获取DHCP for STA 动态IP地址池配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_STADHCPDYNIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;
	AC_DEVM_STADHCPDYNIP_CONFIG_T		astDhcpDynIp[8];
} AC_DEVM_GET_STADHCPDYNIP_CONFIG_RSP_T;

/*	获取DHCP for AP 全局配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_APDHCPGLOBAL_CONFIG_T		stDhcpGlobalCfg;
} AC_DEVM_GET_APDHCPGLOBAL_CONFIG_RSP_T;

/* 	获取DHCP for AP 静态绑定IP配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_APDHCPSTATICIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */

	UINT32	ulNum;
	AC_DEVM_APDHCPSTATICIP_CONFIG_T		astDhcpStaticIp[8];
} AC_DEVM_GET_APDHCPSTATICIP_CONFIG_RSP_T;
 	
/* 	获取DHCP for AP 动态IP地址池配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_APDHCPDYNIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;
	AC_DEVM_APDHCPDYNIP_CONFIG_T		astDhcpDynIp[8];
} AC_DEVM_GET_APDHCPDYNIP_CONFIG_RSP_T;

 	
/*	获取QOS全局配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_QOSGLOBAL_CONFIG_T		stQosGlobalCfg;
} AC_DEVM_GET_QOSGLOBAL_CONFIG_RSP_T;
	
/* 	获取用户QOS缺省配置（新增）*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_QOSUSRDFT_CONFIG_T		stQosUsrDft;
} AC_DEVM_GET_QOSUSRDFT_CONFIG_RSP_T;
 	
/* 	获取VLAN QOS配置（新增）*/

typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_QOSVLAN_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_QOSVLAN_CONFIG_T		astQosVlan[100];
} AC_DEVM_GET_QOSVLAN_CONFIG_RSP_T;
 	
/* 获取SSID QOS配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_QOSSSID_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_QOSSSID_CONFIG_T		astQosSsid[32];
} AC_DEVM_GET_QOSSSID_CONFIG_RSP_T;
 	
/* 	获取本设备告警配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_ALARMFILTER_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_ALARMFILTER_CONFIG_T		astAlarm[100];
} AC_DEVM_GET_ALARMFILTER_CONFIG_RSP_T;

/* 获取邋AC告警门限设置(新增)*/
//         功能描述：获取本设备告警门限配置
//         输入参数结构：
//无。
//      输出参数结构：
typedef struct {
    UINT32 ulRet;
    AC_DEVM_ACALARMTHRESHOLD_CONFIG_T   stCfg;
} AC_DEVM_GET_ACALARMTHRESHOLD_CONFIG_RSP_T;

/* 	获取本设备性能计数器组配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
} AC_DEVM_GET_PERFCOUNTER_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
	AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_PERFCOUNTER_CONFIG_T		astPerfCounter[100];
} AC_DEVM_GET_PERFCOUNTER_CONFIG_RSP_T;

/* 	功能描述：获取本设备的软件版本配置*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_SWSVR_CONFIG_T		stSwSvrCfg;
} AC_DEVM_GET_SWSVR_CONFIG_RSP_T;

/* 	功能描述：获取AC当前的配置数据版本号*/
// 	输出参数结构：
typedef struct {
	UINT32 	ulRet;
	UINT32	ulCfgVersion;
} AC_DEVM_GET_CFG_VERSION_RSP_T;


/* 获取STP配置接口参数结构体定义*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_STP_CONFIG_T		stStp;
} AC_DEVM_GET_STP_CONFIG_RSP_T;

/* 获取PPPoE服务器配置*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_PPPOESERVER_CONFIG_T		stPPPoECfg;
} AC_DEVM_GET_PPPOESERVER_CONFIG_RSP_T;

/* 2011-8-8 pyy MAC认证功能新增*/
typedef struct
{
	UINT32	ulMacSwitch;			/*	MAC认证开关*/
	UINT8	aucMacSrvAddr[4];	/*	MAC认证服务器IP */
	UINT32	ulMacSrvPort;		/*	MAC认证服务器端口*/
	UINT32	ulTrafficTime;			/*	MAC认证触发时间*/
	UINT32	ulTrafficThresh;		/*	MAC认证触发流量*/
} AC_DEVM_MACSERVER_CONFIG_T;

typedef struct
{
	UINT32 	ulRet;
	AC_DEVM_MACSERVER_CONFIG_T		stMacServerCfg;
} AC_DEVM_GET_MACSERVER_CONFIG_RSP_T;

/*	获取强制Portal全局配置（新增）*/
/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_PORTAL_CONFIG_T		stPortalCfg;
} AC_DEVM_GET_PORTAL_CONFIG_RSP_T;

/* 	获取Portal白名单配置（新增）*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_WHITELIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_WHITELIST_CONFIG_T	astWhiteList[8];
} AC_DEVM_GET_WHITELIST_CONFIG_RSP_T;

/* 获取用户名地址绑定列表*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_USERADDRBIND_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_USERADDRBIND_CONFIG_T	astUserAddrBind[8];
} AC_DEVM_GET_USERADDRBIND_CONFIG_RSP_T;

/* 获取免认证IP 地址列表*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_FREEADDR_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_FREEADDR_CONFIG_T	astFreeAddr[8];
} AC_DEVM_GET_FREEADDR_CONFIG_RSP_T;

/* 获取免认证MAC地址列表*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_FREEMAC_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_FREEMAC_CONFIG_T	astFreeMac[8];
} AC_DEVM_GET_FREEMAC_CONFIG_RSP_T;


/* 获取免认证SSID列表*/

typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FREESSID_CONFIG_T	stFreeSsid;
} AC_DEVM_GET_FREESSID_CONFIG_RSP_T;

/* 获取免认证VLAN列表*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FREEVLAN_CONFIG_T	stFreeVlan;
} AC_DEVM_GET_FREEVLAN_CONFIG_RSP_T;


typedef struct 
{
	UINT32	ulRet;
	UINT32	ulFreeSwitch;	/* 全局免认证开关*/
} AC_DEVM_GET_FREEGLOBAL_CONFIG_RSP_T;

/* 获取白名单URL配置*/
typedef struct {
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_WHITEURLLIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;		/* 本次调用返回的配置数 */
	AC_DEVM_WHITEURL_CONFIG_T	astWhiteUrl[8];
} AC_DEVM_GET_WHITEURLLIST_CONFIG_RSP_T;


/*	获取本设备的日志管理配置（新增）*/
/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_LOG_CONFIG_T		stLogCfg;
} AC_DEVM_GET_LOG_CONFIG_RSP_T;

/* 	获取日志服务器配置（新增）*/
/* 	输出参数结构：*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_LOGSVR_CONFIG_T		stLogSvrCfg;
} AC_DEVM_GET_LOGSVR_CONFIG_RSP_T;

// 	功能描述：获取AS服务器配置
// 	输入参数结构：
// 	输出参数结构：
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPIAS_CONFIG_T		stWapiAs;
} AC_DEVM_GET_WAPIAS_CONFIG_RSP_T;

// 	功能描述： 根据WAPI ID获取WAPI配置参数
// 	输入参数结构：
typedef struct {
	UINT32 	ulWapiSetupId;
} AC_DEVM_GET_WAPI_CONFIG_REQ_T;

// 	输出参数结构：
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPI_CONFIG_T	stWapi;
} AC_DEVM_GET_WAPI_CONFIG_RSP_T;

// 根据WAPI证书ID获取证书内容
// 	输入参数结构：
typedef struct {
	UINT32 	ulCertId;
} AC_DEVM_GET_WAPICERTFILE_CONFIG_REQ_T;

 //	输出参数结构：
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPICERTFILE_CONFIG_T	stCert;
} AC_DEVM_GET_WAPICERTFILE_CONFIG_RSP_T;

// 	功能描述：根据VAP ID获取VAP当前运行状态
// 	输入参数结构：
typedef struct 
{
	AC_VAPID_T  stVapId;
} AC_DEVM_GET_VAP_OPSTATE_REQ_T;

// 	输出参数结构：
typedef struct 
{
	UINT32    ulRet;
	UINT32      ulValue;    /* NORMAL, FAULT */
} AC_DEVM_GET_VAP_OPSTATE_RSP_T;

// 	功能描述：获取AC设备摘要信息
// 	输入参数结构：
//无。
 //	输出参数结构：
typedef struct
{
	CHAR     	acAcDevName[32];      //设备名称
	CHAR	acAcNEId[32];		/* 设备编码*/
	CHAR	acAcHostName[64];	/* 设备域名称*/
    	CHAR     	acAcDevType[32];      //设备型号    	
	CHAR     	acAcDevSN[6];         	//设备序列号：位于 /etc/gb
	UINT8    	aucResv1[2]; 	
	CHAR     	acAcSwVersion[32];    //设备软件版本
	CHAR     	acAcHwVersion[32];    //设备硬件版本
    	CHAR    	acAcCpuInfo[128];	   //CPU信息:CPU型号，主频
    	CHAR     	acAcMemInfo[128];	   //内存信息:RAM类型，容量
    	CHAR	acAcLocation[64];		/* 设备位置*/
    	CHAR    	acAcManufacturer[128]; 	//设备制造商 位于 AC_HOME/c.dat
	CHAR     	acAcSwDeveloper[128];  	//软件开发商
	
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
  	UINT32	ulAcRegWtpNum;		/* 注册的AP数目*/
	UINT32   ulAcWtpNum;          //接入的AP数目
	UINT32   ulAcStaNum;          //接入的用户数目
	UINT32	ulAcPortalStaNum;		/* 接入的Portal认证用户数*/
	UINT32	ulAcPPPoEStaNum;		/* 接入的PPPoE认证用户数*/

	/*以下为端口状态信息*/     
	UINT32   ulEnetPortNum;             //以太网端口数目
	AC_ENETPORT_INFO_T astEnetPort[AC_ENETPORT_NUM_MAX];
} AC_DEVM_ACDEVICE_ABSTRACT_T;

typedef struct 
{
	UINT32    ulRet;
	AC_DEVM_ACDEVICE_ABSTRACT_T		stAcDevice;
} AC_DEVM_GET_ACDEVICE_ABSTRACT_RSP_T;

/* 新增AC检测到的未注册AP */
typedef struct
{
	UINT32  	ulWtpId;      			//AP设备ID
     	UINT8    	aucWtpIp[4];  		/* AP 设备IP */
		UINT8		aucSrcIp[4];		/* add by gwx 2014-10-17 通信地址*/
		UINT32		ulSrcPort;			/* add by gwx 2014-10-17 通信端口*/
     	UINT32   ulIpOrigin;   			// AP IP配置方式  
     	UINT8    	aucMac[6];         		/* AP 设备MAC */
     	UINT8    	aucResv0[2];  		/* 填充字节*/
     	UINT32  	ulWtpModel;   		//AP设备型号
     	UINT8   	aucWtpSn[6];  		//AP设备序列号
     	UINT8    	aucResv[2];
     	UINT32   ulDisType;    			// AC发现方式
     	CHAR     	acSwVersion[32];		//AP 当前软件版本号
     	CHAR	acTargetVersion[32];   // AP设备目标软件版本号
     	UINT32  	ulWtpState;   		//AP设备状态
     	UINT32	ulRejectReason;		/* 拒绝接入原因 */
			                                 /*
			                                 1:设备ID不一致
			                                 2:密码不一致
			                                 3:设备型号不一致
			                                 4:设备序列号不一致
			                                 */
	UINT32   ulAcLanId;    /* AC 端口
                       0-16，显示LANx
                       >=16，则显示N/A*/
    	UINT32  ulBeginTime;        		//该状态开始时间
    	UINT32  ulStatePeriod;      		//该状态持续时间
     	UINT32  ulStaNum;           			//当前接入用户数
     	UINT32   ulStaAccNum;  			/* 用户接入次数*/
    	UINT32  ulStaOnlineTime;    		/* 用户总在线时长, 单位：秒 */
     	UINT32   ulRegisterTime;			/*       注册时间 ，首次连接到AC的时间*/
     	UINT32   ulLastConnTime;			/*       上次启动时间，最后一次关联AC的时间*/
     	UINT32   ulLastVerUpdateTime;   	/*       上次升级版本时间   Oma通知dbs*/
     	UINT32   ulLastCfgUpdateTime;   	/*       上次更新配置时间   Oma通知dbs */
	/* add by gwx 2014-3-26 for AP一键注册begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for AP一键注册end*/
}AC_DEVM_ADD_UNREGWTP_REQ_T;


typedef struct
{
	UINT32	ulRet;
}AC_DEVM_ADD_UNREGWTP_RSP_T;

/* 删除AC检测到的未注册AP */
typedef struct
{
	UINT8   	aucWtpSn[6];  		//AP设备序列号
     	UINT8    	aucResv[2];
}AC_DEVM_DEL_UNREGWTP_REQ_T;


typedef struct
{
	UINT32	ulRet;
}AC_DEVM_DEL_UNREGWTP_RSP_T;

/* 2010-1-18  新增: 获取AC主备配置 */
/* 入参：无 */
/*  出参 */
typedef struct
{
	UINT32	ulRet;
	AC_DEVM_MSSETUP_CONFIG_T	stCfg;
} AC_DEVM_GET_MSSETUP_CONFIG_RSP_T;

/* 设置备份设备运行状态*/
typedef struct
{
	UINT32	ulPeerAcState1;	/*备份设备1状态 */
	UINT32	ulPeerAcState2;	/*备份设备2状态 */
	UINT32	ulPeerAcState3;	/*备份设备3状态 */
	UINT32	ulCurBakAcId;	/* 当前接管的AC　ID */
}AC_DEVM_SET_MSSTATE_REQ_T;

typedef struct
{
	UINT32	ulRet;
}AC_DEVM_SET_MSSTATE_RSP_T;
/* 2010-4-19 pyy 新增: 获取指定AP的目标软件版本号*/
typedef struct
{
	UINT32	ulWtpId;
}AC_DEVM_GET_WTP_TARGETVERSION_REQ_T;

typedef struct
{
	UINT32	ulRet;
	CHAR	acTargetVersion[32];   /* AP设备目标软件版本号*/
}AC_DEVM_GET_WTP_TARGETVERSION_RSP_T;


/* 2010-3-1 获取以太网口的MOID */
typedef struct
{
	CHAR	acIfName[32];	/* 端口名称 */
} AC_DEVM_GET_ENET_MOID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulMOC;
	UINT8	aucMOI[AC_MOI_LEN];
} AC_DEVM_GET_ENET_MOID_RSP_T;

typedef struct
{
	UINT32	ulWtpId;
}AC_DEVM_GET_VAPADMINSTATE_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	aulVapAdminState[AC_VAPID_MAX+1];
}AC_DEVM_GET_VAPADMINSTATE_RSP_T;

typedef struct
{
	UINT32	ulFtp;
	UINT32	ulTelnet;
	UINT32	ulWeb;
	CHAR	acPasswd[32];
} AC_DEVM_APACL_CONFIG_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_APACL_CONFIG_T	stApAcl;
}  AC_DEVM_GET_APACL_RSP_T;

/* 	根据VAPID获取AAA服务器配置 */
typedef struct
{
	AC_VAPID_T	stVapId;
} AC_DEVM_GET_SSIDRADIUSSERVERS_REQ_T;


typedef struct
{
	UINT32	ulRet;
	AC_DEVM_RADIUS_SERVERS_T	stAAAServers;
} AC_DEVM_GET_SSIDRADIUSSERVERS_RSP_T;

/* 	根据终端MAC获取AAA服务器配置 */
typedef struct
{
	UINT8		aucMac[6];
	UINT8		aucRsv[2];
	UINT8		aucUserName[256]; /* add by gwx 2011-11-11*/
} AC_DEVM_GET_STARADIUSSERVERS_REQ_T;


typedef struct
{
     UINT32   ulRet;
     AC_DEVM_RADIUS_SERVERS_T    stAAAServers;
} AC_DEVM_GET_STARADIUSSERVERS_RSP_T;

#define AC_DEVM_AUTHSERVERS_NUM_MAX		32
#define AC_DEVM_ACCTSERVERS_NUM_MAX		32

/* 	获取鉴权服务器列表 */
typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;

	AC_DEVM_RADIUS_AUTHSERVERS_T	astAuthServers[AC_DEVM_AUTHSERVERS_NUM_MAX];
}AC_DEVM_GET_AUTHSERVERS_RSP_T;


/* 	获取计费服务器列表 */
typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;

	AC_DEVM_RADIUS_ACCTSERVERS_T	astAcctServers[AC_DEVM_ACCTSERVERS_NUM_MAX];
}AC_DEVM_GET_ACCTSERVERS_RSP_T;


typedef struct
{
	UINT32	ulRet;
	AC_DEVM_ACFIRSTIP_CONFIG_T	stAcVrrpFirstIp;
}AC_DEVM_GET_ACVRRPFIRSTIP_RSP_T;


/* 设置VAP BSSID */
typedef AC_DEVM_VAP_BSSID_T AC_DEVM_SET_VAPBSSID_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPBSSID_RSP_T;

/* 设置VAP 流量统计*/
typedef AC_DEVM_VAP_TRAFFICSTAT_T AC_DEVM_SET_VAPTRAFFICSTAT_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPTRAFFICSTAT_RSP_T;

/* 设置VAP WIFI统计*/
typedef AC_DEVM_VAP_WIFISTAT_T AC_DEVM_SET_VAPWIFISTAT_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPWIFISTAT_RSP_T;

/* 设置无线设备最大发射功率*/
typedef AC_DEVM_VDEV_MAXPOWER_T  AC_DEVM_SET_VDEVMAXPOWER_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VDEVMAXPOWER_RSP_T;

/* 设置ADHOC BSSID */
typedef AC_DEVM_ADHOC_BSSID_T AC_DEVM_SET_ADHOCBSSID_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_ADHOCBSSID_RSP_T;

typedef struct 
{
	UINT32	ulWtpId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];	
}AC_DEVM_SET_WTP_MAC_REQ_T;

typedef struct 
{
	UINT32	ulRet;	
}AC_DEVM_SET_WTP_MAC_RSP_T;


typedef struct
{
	UINT32	ulWtpId;
	UINT8	aucMac[6];
	UINT8	aucRsv[2];
}AC_DEVM_WTPMAC_T;

typedef struct
{
	UINT32		ulStartRec;		/* 查询的起始记录号 */
	/*
	第一次调用时，入参ulStartRec填0
	后续调用时，入参ulStartRec填当前ulStartRec值加上前一次调用返回的ulRecNum
	*/
}AC_DEVM_GET_WTPMAC_REQ_T;

#define AC_DEVM_WTPMAC_MAX	256
typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;	/* 关系表所有记录是否已读取结束
							AC_DB_TABLE_READ_NOTFINISH	未结束
							AC_DB_TABLE_READ_FINISH		读取结束 */
	UINT32	ulNum;
	AC_DEVM_WTPMAC_T	astWtpMac[AC_DEVM_WTPMAC_MAX];
} AC_DEVM_GET_WTPMAC_RSP_T;


typedef struct
{
	UINT32	ulRet;
	BOOL	bActive;	/* 	TRUE: 当前Active 
						FALSE: 当前Standby */
} AC_DEVM_IS_ACTIVE_RSP_T;

typedef struct
{
	UINT32	ulWtpId;
}AC_DEVM_GET_WTPSNTP_CONFIG_BYWTP_REQ_T;


typedef struct
{
	UINT32	ulRet;
	AC_DEVM_WTPSNTP_CONFIG_T	stSntpCfg;
}AC_DEVM_GET_WTPSNTP_CONFIG_BYWTP_RSP_T;

typedef struct
{
	UINT32	ulWtpId;
}AC_DEVM_GET_WTP_MOID_REQ_T;

typedef struct
{
	UINT32    ulRet;        					/* 返回值，AC_OK表示成功，其它表示错误码 */
	AC_OMA_MO_T	stWtpMoid;			/* WTP MOID */
}AC_DEVM_GET_WTP_MOID_RSP_T;

/* add by gwx 2013-4-7 for task668 begin */
typedef struct

{

         UINT32    ulWtpid; //AP ID

         UINT32    ulCommPort;

         UINT8       aucCommIp[4];

}AC_DEVM_SET_WTPSRCADDR_REQ;
typedef struct

{

         UINT32    ulRet;

}AC_DEVM_SET_WTPSRCADDR_RSP;
typedef struct
{
	UINT32	ulCommPort;	/* 通讯端口号*/
	UINT8	aucCommIp[4];		/* 通讯IP */
}AC_DEVM_GET_WTPIDBYPORTANDIP_REQ;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulWtpId;
}AC_DEVM_GET_WTPIDBYPORTANDIP_RSP;

typedef struct
{
	INT32			iFd;
	UINT32          ulPid;
	UINT32			ulSeq;
}AC_DEVM_RTNL_HANDEL_T;

typedef struct{
    UINT8	aucDstIp[4];
	UINT8	aucSrcIp[4];
	UINT8	aucGateWay[4];
	CHAR	acInIf[16];
	CHAR	acOutIf[16];
}AC_DEVM_ROUTE_TBL_T;

typedef struct
{
	UINT8 aucWtpIp[4];   /* AP IP */
}AC_DEVM_GET_ACLINKIP_REQ_T;

typedef struct
{
	UINT32	ulRet;
    UINT8   aucAcLinkIp[4];/*连接AC的IP*/
}AC_DEVM_GET_ACLINKIP_RSP_T;

/* 函数接口入出参结构体定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 消息接口结构定义结束*/
/* AC标识更新消息结构体定义 */
typedef struct{
    UINT32    ulAcId;    /* AC ID */
    AC_DEVM_ACFIRSTIP_CONFIG_T	stAcFirstIp;
} AC_DEVM_AC_UPDATE_IND_MSG_T;

/* AC设备系统配置更新消息结构体定义*/
typedef AC_DEVM_AC_OWNCONFIG_T AC_DEVM_AC_OWNCONFIG_UPDATE_IND_MSG_T;

/* 3A配置变更消息结构体定义*/
typedef AC_DEVM_RADIUS_SERVERS_T	AC_DEVM_RADIUS_CONFIG_UPDATE_MSG_T;

// 	功能描述：
//	AC上行链路检查配置变更时，DEVM发消息通知系统控制模块
// 	消息体结构：
typedef AC_DEVM_ACKEEPER_CONFIG_T AC_DEVM_ACKEEPERCFG_UPDATE_IND_MSG_T;


/* WTP设备新增通知消息结构体定义*/
typedef AC_DEVM_WTP_CONFIG_T    AC_DEVM_WTP_ADD_IND_MSG_T;

/* WTP设备删除通知消息结构体定义*/
typedef AC_WTPID_T    AC_DEVM_WTP_DEL_IND_MSG_T;

/* WTP设备修改通知消息结构体定义*/
typedef AC_DEVM_WTP_CONFIG_T    AC_DEVM_WTP_UPDATE_IND_MSG_T;

/* 无线设备新增通知消息结构体定义*/
typedef AC_DEVM_VDEV_CONFIG_T	AC_DEVM_VDEV_ADD_IND_MSG_T;

/* 无线设备删除通知消息结构体定义*/
typedef AC_VDEVID_T	AC_DEVM_VDEV_DEL_IND_MSG_T;

/* 无线设备修改通知消息结构体定义*/
typedef AC_DEVM_VDEV_CONFIG_T	AC_DEVM_VDEV_UPDATE_IND_MSG_T;

//	无线设备WIDS配置变更通知（新增）
typedef struct {
	AC_VDEVID_T		stVdevId;
	AC_DEVM_VDEVWIDS_CONFIG_T 	stWidsCfg;
}AC_DEVM_VDEVWIDS_UPDATE_IND_MSG_T;

//	无线设备无线资源管理策略配置修改通知（新增）
typedef struct 
{
	AC_VDEVID_T		stVdevId;
	AC_DEVM_VDEVRRM_CONFIG_T 	stRrmCfg;
}AC_DEVM_VDEVRRM_UPDATE_IND_MSG_T;

//	无线设备邻居新增通知（新增）
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_ADD_IND_MSG_T;

//	无线设备邻居删除通知（新增）
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_DEL_IND_MSG_T;

//	无线设备邻居变更通知（新增）
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_UPDATE_IND_MSG_T;


/* 接口新增通知消息结构体定义*/
typedef AC_DEVM_IF_CONFIG_T    AC_DEVM_IF_ADD_IND_MSG_T;

/* 接口删除通知消息结构体定义*/
typedef AC_IFID_T    AC_DEVM_IF_DEL_IND_MSG_T;

/* 接口修改通知消息结构体定义*/
typedef AC_DEVM_IF_CONFIG_T    AC_DEVM_IF_UPDATE_IND_MSG_T;

/* VAP 新增通知消息结构体定义*/
typedef AC_DEVM_VAP_CONFIG_T    AC_DEVM_VAP_ADD_IND_MSG_T;

/* VAP 删除通知消息结构体定义*/
typedef AC_VAPID_T    AC_DEVM_VAP_DEL_IND_MSG_T;

typedef struct
{
	AC_VAPID_T	stVapId;
	UINT32	ulTrafficMode;
} AC_DEVM_L2WVAP_DEL_IND_MSG_T;

/* VAP 修改通知消息结构体定义*/
typedef AC_DEVM_VAP_CONFIG_T    AC_DEVM_VAP_UPDATE_IND_MSG_T;

/* ADHOC 新增通知消息结构体定义*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_ADD_IND_MSG_T;

/* ADHOC 删除通知消息结构体定义*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_DEL_IND_MSG_T;

/* VAP 修改通知消息结构体定义*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_UPDATE_IND_MSG_T;


/* VAP SSID变更通知消息结构体定义*/
typedef struct
{
	AC_VAPID_T	stVapId;
	CHAR	acSsid[32];
} AC_DEVM_VAPSSID_UPDATE_IND_MSG_T;


/* WTP运行状态变更触发消息结构体定义 */
typedef struct {
    AC_WTPID_T  stWtpId;
    UINT32  ulOpState;  /* 运行状态 */
    UINT32  ulReason;   /* 引起WTP运行状态变化的原因码: 
                           链路状态变化
                           管理状态变化*/
} AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T;

/* VAP管理状态变化通知消息结构体定义*/
typedef struct
{
    AC_VAPID_T        stVapId;
    UINT32    ulAdminState;
} AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG_T;

/* VAP运行状态变化通知消息结构体定义 */
typedef struct
{
    AC_VAPID_T  stVapId;
    UINT32  ulOpState;
    UINT32  ulReason;   /* 引起VAP运行状态变化的原因码: 
                           链路状态变化
                           管理状态变化 */
} AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T;

/* VAP BSSID(MAC地址)更新通知消息结构体定义 */
typedef AC_DEVM_VAP_BSSID_T AC_DEVM_VAP_MAC_CHG_IND_MSG_T;

// SNMPV2配置新增通知（新增）
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_ADD_IND_MSG_T;

// SNMP V2配置删除通知（新增）
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_DEL_IND_MSG_T;

// SNMP V2配置变更通知（新增）
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_UPDATE_IND_MSG_T;

// SNMPV3配置新增通知（新增）
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_ADD_IND_MSG_T;

// SNMP V3配置删除通知（新增）
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_DEL_IND_MSG_T;

// SNMP V3配置变更通知（新增）
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_UPDATE_IND_MSG_T;

/* SNMP TRAP配置新增通知(新增)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_ADD_IND_MSG_T;

/* SNMP TRAP配置删除通知(新增)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_DEL_IND_MSG_T;

/* SNMP TRAP配置变更通知(新增)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_UPDATE_IND_MSG_T;

/* 	AC SNTP全局配置变更通知（新增）*/
typedef AC_DEVM_ACSNTP_CONFIG_T AC_DEVM_ACSNTPCONFIG_UPDATE_IND_MSG_T;

/* 	WTP SNTP全局配置变更通知（新增） */
typedef AC_DEVM_WTPSNTP_CONFIG_T AC_DEVM_WTPSNTPCONFIG_UPDATE_IND_MSG_T;

/* AC端口组新增通知（新增）*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_ADD_IND_MSG_T;

/* AC端口组删除通知（新增）*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_DEL_IND_MSG_T;

/*	AC端口组配置变更通知（新增）*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_UPDATE_IND_MSG_T;

/* 	AC物理端口新增通知（新增）*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_ADD_IND_MSG_T;

/* 	AC物理端口删除通知（新增）*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_DEL_IND_MSG_T;

/* 	AC物理端口修改通知（新增）*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_UPDATE_IND_MSG_T;

/* WTP Enet端口新增通知*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_ADD_IND_MSG_T;

/* WTP Enet端口删除通知*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_DEL_IND_MSG_T;

/* WTP Enet端口修改通知*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_UPDATE_IND_MSG_T;

//WAN口端口名称修改通知(新增)
typedef struct
{
	CHAR	acIfName[32];	/* 端口名称 */
}	AC_DEVM_WANIFNAME_CONFIG_UPDATE_IND_MSG_T;

/* 	功能描述：AC LAN端口组配置新增时，发消息通知相关模块*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_ADD_IND_MSG_T;

/*	AC LAN端口组删除通知（新增）*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_DEL_IND_MSG_T;

/*	AC LAN端口组配置变更通知（新增）*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_UPDATE_IND_MSG_T;

/* L2-WAN/FAT-LAN配置变更通知*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_L2WAN_UPDATE_IND_MSG_T;

/* L3-WAN配置变更通知*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_L3WAN_UPDATE_IND_MSG_T;

/* VLAN全局配置变更通知*/
typedef AC_DEVM_VLANGLOBAL_CONFIG_T	AC_DEVM_VLANGLOBAL_UPDATE_IND_MSG_T;

/* 	VLAN新增通知（新增）*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_ADD_IND_MSG_T;

/* 	VLAN删除通知（新增）*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_DEL_IND_MSG_T;

/* 	VLAN基本配置变更通知（新增）*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_UPDATE_IND_MSG_T;

/* 	SSID -VLAN映射新增通知（新增）*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_ADD_IND_MSG_T;

/* 	SSID -VLAN映射删除通知（新增）*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_DEL_IND_MSG_T;

/* 	SSID -VLAN映射配置变更通知（新增）*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_UPDATE_IND_MSG_T;

/* 	端口-VLAN映射新增通知（新增）*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_ADD_IND_MSG_T;

/* 	端口-VLAN映射删除通知（新增）*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_DEL_IND_MSG_T;

/* 	端口-VLAN映射配置变更通知（新增）*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_UPDATE_IND_MSG_T;

/* 	MAC-VLAN映射新增通知（新增）*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_ADD_IND_MSG_T;

/* 	MAC-VLAN映射删除通知（新增）*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_DEL_IND_MSG_T;

/* 	MAC-VLAN映射配置变更通知（新增）*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_UPDATE_IND_MSG_T;

//	VLAN MAC地址过滤策略新增通知（新增）
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_ADD_IND_MSG_T;

//	VLAN MAC地址过滤策略删除通知（新增）
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_DEL_IND_MSG_T;

//	VLAN MAC地址过滤策略配置变更通知（新增）
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_UPDATE_IND_MSG_T;

//	VLAN允许访问MAC列表新增通知（新增）
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_ADD_IND_MSG_T;

//	VLAN允许访问MAC列表删除通知（新增）
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_DEL_IND_MSG_T;

//	VLAN允许访问MAC列表配置变更通知（新增）
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_UPDATE_IND_MSG_T;

//	IGMP Snooping配置变更通知（新增）
typedef AC_DEVM_IGMPSNOOP_CONFIG_T		AC_DEVM_IGMPSNOOP_UPDATE_IND_MSG_T;

//IGMP Proxy配置变更通知（新增）
typedef AC_DEVM_IGMPPROXY_CONFIG_T		AC_DEVM_IGMPPROXY_UPDATE_IND_MSG_T;

//	静态路由新增通知（新增）
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_ADD_IND_MSG_T;

//	静态路由删除通知（新增）
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_DEL_IND_MSG_T;

//	静态路由配置变更通知（新增）
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_UPDATE_IND_MSG_T;

//	RIP全局配置变更通知（新增）
typedef AC_DEVM_RIPGLOBAL_CONFIG_T		AC_DEVM_RIPGLOBAL_UPDATE_IND_MSG_T;

//	RIP通告网段新增通知（新增）
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_ADD_IND_MSG_T;

//	RIP通告网段删除通知（新增）
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_DEL_IND_MSG_T;

//	RIP通告网段配置变更通知（新增）
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_UPDATE_IND_MSG_T;

//	防火墙全局配置变更通知（新增）
typedef AC_DEVM_FWGLOBAL_CONFIG_T		AC_DEVM_FWGLOBAL_UPDATE_IND_MSG_T;

//	防火墙规则新增通知（新增）
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_ADD_IND_MSG_T;

//	防火墙规则删除通知（新增）
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_DEL_IND_MSG_T;

//	防火墙规则变更通知（新增）
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_UPDATE_IND_MSG_T;

/* NAT全局配置变更通知*/
typedef AC_DEVM_NATGLOBAL_CONFIG_T		AC_DEVM_NATGLOBAL_UPDATE_IND_MSG_T;

//	NAT配置新增通知（新增）
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_ADD_IND_MSG_T;

//	NAT配置删除通知（新增）
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_DEL_IND_MSG_T;

//	NAT配置变更通知（新增）
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_UPDATE_IND_MSG_T;

/* P2P规则限制变更通知*/
typedef AC_DEVM_FWL7MATCH_CONFIG_T	AC_DEVM_P2P_UPDATE_IND_MSG_T;

//	IDS规则配置变更通知（新增）
typedef AC_DEVM_IDSRULE_CONFIG_T		AC_DEVM_IDSRULE_UPDATE_IND_MSG_T;

//	IDS策略配置变更通知（新增）
 typedef AC_DEVM_IDSSTRY_CONFIG_T		AC_DEVM_IDSSTRY_UPDATE_IND_MSG_T;

//	DHCP for STA 功能配置变更通知（新增）
typedef AC_DEVM_STADHCPGLOBAL_CONFIG_T		AC_DEVM_STADHCPGLOBAL_UPDATE_IND_MSG_T;

//	DHCP for STA 静态绑定IP新增通知（新增）
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_ADD_IND_MSG_T;

//	DHCP for STA 静态绑定IP删除通知（新增）
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_DEL_IND_MSG_T;

//	DHCP for STA 静态绑定IP变更通知（新增）
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_UPDATE_IND_MSG_T;

//	DHCP for STA 动态IP地址池新增通知（新增）
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_ADD_IND_MSG_T;
 
//	DHCP for STA 动态IP地址池删除通知（新增）
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_DEL_IND_MSG_T;

//	DHCP for STA 动态IP地址池变更通知（新增）
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_UPDATE_IND_MSG_T;

//	DHCP for AP 功能配置变更通知（新增）
typedef AC_DEVM_APDHCPGLOBAL_CONFIG_T		AC_DEVM_APDHCPGLOBAL_UPDATE_IND_MSG_T;

//	DHCP for AP 静态绑定IP新增通知（新增）
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_ADD_IND_MSG_T;

//	DHCP for AP 静态绑定IP删除通知（新增）
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_DEL_IND_MSG_T;

//	DHCP for AP 静态绑定IP变更通知（新增）
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_UPDATE_IND_MSG_T;

//	DHCP for AP 动态IP地址池新增通知（新增）
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_ADD_IND_MSG_T;
 
//	DHCP for AP 动态IP地址池删除通知（新增）
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_DEL_IND_MSG_T;

//	DHCP for AP 动态IP地址池变更通知（新增）
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_UPDATE_IND_MSG_T;

//	QOS全局配置变更通知（新增）
typedef AC_DEVM_QOSGLOBAL_CONFIG_T		AC_DEVM_QOSGLOBAL_UPDATE_IND_MSG_T;

//	用户QOS缺省配置变更通知（新增）
typedef AC_DEVM_QOSUSRDFT_CONFIG_T		AC_DEVM_QOSUSRDFT_UPDATE_IND_MSG_T;

//	VLAN QOS配置新增通知（新增）
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_ADD_IND_MSG_T;

//	VLAN QOS配置删除通知（新增）
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_DEL_IND_MSG_T;

//	VLAN Qos配置变更通知（新增）
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_UPDATE_IND_MSG_T;

//	SSID QOS配置新增通知（新增）
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_ADD_IND_MSG_T;

//	SSID QOS配置删除通知（新增）
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_DEL_IND_MSG_T;

//	SSID QOS配置变更通知（新增）
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_UPDATE_IND_MSG_T;

//	告警配置新增通知（新增）
typedef AC_DEVM_ALARMFILTER_CONFIG_T	AC_DEVM_ALARMFILTER_ADD_IND_MSG_T;

//	告警配置删除通知（新增）
typedef AC_DEVM_ALARMFILTER_CONFIG_T	AC_DEVM_ALARMFILTER_DEL_IND_MSG_T;

//	告警配置变更通知（新增）
typedef AC_DEVM_ALARMFILTER_CONFIG_T		AC_DEVM_ALARMFILTER_UPDATE_IND_MSG_T;

// 告警门限配置变更通知(新增)
typedef AC_DEVM_ACALARMTHRESHOLD_CONFIG_T	AC_DEVM_ACALARMTHRESHOLD_UPDATE_IND_MSG_T;

//	性能计数器组新增通知（新增）
typedef AC_DEVM_PERFCOUNTER_CONFIG_T	AC_DEVM_PERFCOUNTER_ADD_IND_MSG_T;

//	性能计数器组删除通知（新增）
typedef AC_DEVM_PERFCOUNTER_CONFIG_T	AC_DEVM_PERFCOUNTER_DEL_IND_MSG_T;

//	性能计数器组配置变更通知（新增）
typedef AC_DEVM_PERFCOUNTER_CONFIG_T		AC_DEVM_PERFCOUNTER_UPDATE_IND_MSG_T;

//	软件版本配置变更通知（新增）
typedef AC_DEVM_SWSVR_CONFIG_T		AC_DEVM_SWSVR_UPDATE_IND_MSG_T;

/* STP配置变更消息结构体定义*/
 typedef AC_DEVM_STP_CONFIG_T		AC_DEVM_STP_UPDATE_IND_MSG_T;

/* PPPoE服务器配置变更通知 */
typedef AC_DEVM_PPPOESERVER_CONFIG_T		AC_DEVM_PPPOESERVER_UPDATE_IND_MSG_T;

typedef AC_DEVM_MACSERVER_CONFIG_T		AC_DEVM_MACSERVER_UPDATE_IND_MSG_T;

//	Portal全局配置变更通知（新增）
typedef AC_DEVM_PORTAL_CONFIG_T		AC_DEVM_PORTAL_UPDATE_IND_MSG_T;

//	Portal白名单新增通知（新增）
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_ADD_IND_MSG_T;

//	Portal白名单删除通知（新增）
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_DEL_IND_MSG_T;

//	Portal白名单配置变更通知（新增）
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_UPDATE_IND_MSG_T;

/* 用户名地址绑定配置新增通知*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_ADD_IND_MSG_T;

/* 用户名地址绑定配置删除通知*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_DEL_IND_MSG_T;

/* 用户名地址绑定配置变更通知*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_UPDATE_IND_MSG_T;

/* 免认证地址配置新增通知*/
typedef AC_DEVM_FREEADDR_CONFIG_T	AC_DEVM_FREEADDR_ADD_IND_MSG_T;

/* 免认证地址配置删除通知*/
typedef AC_DEVM_FREEADDR_CONFIG_T	AC_DEVM_FREEADDR_DEL_IND_MSG_T;

/* 免认证地址配置变更通知*/
typedef struct
{
	AC_DEVM_FREEADDR_CONFIG_T	stOld;	/* 原配置*/
	AC_DEVM_FREEADDR_CONFIG_T	stNew;	/* 当前配置*/
} AC_DEVM_FREEADDR_UPDATE_IND_MSG_T;

/* 免认证MAC新增通知*/
typedef AC_DEVM_FREEMAC_CONFIG_T	AC_DEVM_FREEMAC_ADD_IND_MSG_T;

/* 免认证MAC删除通知*/
typedef AC_DEVM_FREEMAC_CONFIG_T	AC_DEVM_FREEMAC_DEL_IND_MSG_T;

/* 免认证MAC变更通知*/
typedef struct
{
	AC_DEVM_FREEMAC_CONFIG_T	stOld;
	AC_DEVM_FREEMAC_CONFIG_T	stNew;
}AC_DEVM_FREEMAC_UPDATE_IND_MSG_T;


/* 免认证SSID 配置新增通知*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_ADD_IND_MSG_T;

/* 免认证SSID 配置删除通知*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_DEL_IND_MSG_T;

/* 免认证SSID 配置变更通知*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_UPDATE_IND_MSG_T;

/* 免认证VLAN 配置新增通知*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_ADD_IND_MSG_T;

/* 免认证VLAN 配置删除通知*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_DEL_IND_MSG_T;

/* 免认证VLAN 配置变更通知*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_UPDATE_IND_MSG_T;

typedef struct 
{
	UINT32	ulFreeSwitch;	/* 全局免认证开关*/
} AC_DEVM_FREEGLOBAL_UPDATE_IND_MSG_T;

/* 白名单URL新增通知*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_ADD_IND_MSG_T;

/* 白名单URL删除通知*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_DEL_IND_MSG_T;

/* 白名单URL变更通知*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_UPDATE_IND_MSG_T;


//	日志管理配置变更通知（新增）
typedef AC_DEVM_LOG_CONFIG_T		AC_DEVM_LOG_UPDATE_IND_MSG_T;

//	日志服务器配置变更通知（新增）
typedef AC_DEVM_LOGSVR_CONFIG_T		AC_DEVM_LOGSVR_UPDATE_IND_MSG_T;

// 	功能描述：AS服务器配置变更时，发消息通知相关模块
// 	消息体结构：
typedef AC_DEVM_WAPIAS_CONFIG_T		AC_DEVM_WAPIAS_UPDATE_IND_MSG_T;

/* AP-AC关联配置变更消息*/
typedef AC_DEVM_WTPASSO_CONFIG_T		AC_DEVM_WTPASSO_UPDATE_IND_MSG_T;

/* AP-AC关联删除变更消息*/
typedef AC_DEVM_WTPASSO_CONFIG_T		AC_DEVM_WTPASSO_DEL_IND_MSG_T;

/* 2010-1-18新增: 主备配置变更通知消息*/
typedef AC_DEVM_MSSETUP_CONFIG_T AC_DEVM_MSSETUP_UPDATE_IND_MSG_T;

typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_ADD_IND_MSG_T;			/* 	鉴权服务器新增通知*/
typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_DEL_IND_MSG_T;			/*	鉴权服务器删除通知*/
typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG_T;		/*	鉴权服务器修改通知*/

typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_ADD_IND_MSG_T;			/*	计费服务器新增通知*/
typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_DEL_IND_MSG_T;			/*	计费服务器删除通知*/
typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_UPDATE_IND_MSG_T;		/*	计费服务器修改通知*/

/* add by gwx 2012-7-11 for bug1292*/
typedef struct 
{ 
	UINT8	aucOldManageIp[4]; 
	UINT8	aucNewManageIp[4]; 
}AC_DEVM_MANAGEIP_UPDATE_IND_MSG_T;

typedef  struct 
{ 
	UINT32	ulRet; 
	UINT8	aucManageIp[4]; 
}AC_DEVM_GET_MANAGEIP_RSP_T; 

/* add by gwx 2013-8-16 for 企业网先集中后本地需求*/
typedef  struct
{
	UINT32	ulRet;
	UINT32	ulNumber;		//携带的portal IP个数，最多传输8个IP地址
	UINT8	aaucPortalIp[AC_DEVM_MAX_PORTALIP_NUM][4];	//存放portal IP地址
}AC_DEVM_GET_PORTALIP_RSP;

/* add by gwx 2014-2-25 for task1265 begin */
typedef struct
{
	UINT32	ulWtpId;
	UINT32 	ulWtpProductType;
	CHAR	acModelName[64];	/* add by gwx 2014-6-20 */
} AC_DEVM_SET_WTP_PRODUCTTYPE_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_WTP_PRODUCTTYPE_RSP_T;
/* add by gwx 2014-2-25 for task1265 end */

/* add by gwx 2014-8-7 begin 信道动态上报begin*/
typedef struct
{
	UINT32	ulWtpId;
	UINT32	ulWifiDeviceId;
	CHAR 	acWifiChannelList[32];
}AC_DEVM_WIFICHANNEL_T;

typedef struct
{
	UINT32	ulWtpId;
	/*CHAR	acChannelList[32];*/
	CHAR	acWifi0Channel[32];
	CHAR	acWifi1Channel[32];
}AC_DEVM_SET_WTPCHANNELLIST_REQ_T;

typedef struct
{
	UINT32	ulRet;
}AC_DEVM_SET_WTPCHANNELLIST_RSP_T;


/* add by gwx 2014-8-7 begin 信道动态上报end*/


/* 消息接口结构定义结束*/
/******************************************************************************/

/******************************************************************************/

/**************************OMA提供的接口和结构体定义*******************************/
/* 用户名最大长度 */
//#define AC_OMA_USER_NAME_LEN_MAX    32

/******************************************************************************/

#define AC_MAIN		0
#define AC_SLAVE	1

/***********************************函数extern ******************************/

extern UINT32  ac_devm_vapbssid_host_to_net (AC_DEVM_VAP_BSSID_T *pstHostVapBssid, AC_DEVM_VAP_BSSID_T *pstNetVapBssid);
extern UINT32  ac_devm_vapbssid_net_to_host (AC_DEVM_VAP_BSSID_T *pstNetVapBssid, AC_DEVM_VAP_BSSID_T *pstHostVapBssid);
extern UINT32  ac_devm_vaptrafficstat_host_to_net (AC_DEVM_VAP_TRAFFICSTAT_T *pstHostVapStat, 
												AC_DEVM_VAP_TRAFFICSTAT_T *pstNetVapStat);
extern UINT32  ac_devm_vaptrafficstat_net_to_host (AC_DEVM_VAP_TRAFFICSTAT_T *pstNetVapStat, 
												AC_DEVM_VAP_TRAFFICSTAT_T *pstHostVapStat);

/* 动态信息处理函数 */
extern UINT32 ac_devm_vap_bssid_syn_func (UINT8 *pucMsg);
extern UINT32 ac_devm_vap_trafficstat_syn_func (UINT8 *pucMsg);
extern UINT32 ac_devm_mate_state_syn_func (UINT8 *pucMsg);
/* add by gwx 2014-8-7 */
extern UINT32 ac_devm_wifi_channel_syn_func (UINT8 *pucMsg);

extern UINT32   ac_devm_init (VOID);
extern UINT32   ac_devm_get_if_outlen(UINT32 ulMsgId, UINT32 *pulOutLen);

extern AC_DEVM_ACFIRSTIP_CONFIG_T	gstAcFirstIp;
extern UINT32  ac_devm_adhocbssid_host_to_net (AC_DEVM_ADHOC_BSSID_T *pstHostAdhocBssid, 
												AC_DEVM_ADHOC_BSSID_T *pstNetAdhocBssid);
extern UINT32	ac_devm_vdevmaxpower_host_to_net(AC_DEVM_VDEV_MAXPOWER_T *pstHost, 
													AC_DEVM_VDEV_MAXPOWER_T *pstNet);
extern UINT32 ac_devm_get_vap_bssid (VOID);
extern UINT32	ac_devm_vapwifistat_host_to_net(AC_DEVM_VAP_WIFISTAT_T	*pstHost,
												AC_DEVM_VAP_WIFISTAT_T		*pstNet);

#endif /* _AC_DEVM_PUBLIC_H */
/******************************* 头文件结束 **********************************/


