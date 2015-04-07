/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  配置流程头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DEVM_COMMON_H
#define  _AC_DEVM_COMMON_H
extern UINT32	ac_devm_get_ac_bearip(UINT32 ulAcId, UINT8 *pucIp);
extern UINT32	ac_devm_get_ac_manageip(UINT32 ulAcId, UINT8 *pucIp);
extern UINT32  ac_devm_get_ac_basic_rec (UINT32 ulAcId, 
										AC_DB_TBL_ACBASICSETUP_T	**ppstRec);


extern UINT32  ac_devm_get_ac_aaa_rec (UINT32 ulAcId, 
										AC_DB_TBL_ACAAASETUP_T	**ppstRec);

extern UINT32  ac_devm_get_wtp_basic_rec (UINT32 ulWtpId, 
										AC_DB_TBL_WTPSYSBASICSETUP_T	**ppstRec);

extern UINT32  ac_devm_get_wtp_ip_rec (UINT32 ulWtpId, 
										AC_DB_TBL_WTPSYSIPSETUP_T	**pstRec);

extern UINT32  ac_devm_get_wtp_capwap_rec (UINT32 ulWtpId, 
										AC_DB_TBL_WTPCAPWAPSETUP_T	**ppstRec);

extern UINT32  ac_devm_get_wtp_lb_rec (UINT32 ulWtpId, 
										AC_DB_TBL_WTPSYSLOADBALANCESETUP_T	**pstRec);

extern UINT32  ac_devm_get_vdev_basic_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T **ppstVdevBasicRec);

extern UINT32 ac_devm_get_vdev_channel_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T **ppstVdevChannelRec);

extern UINT32 ac_devm_get_vdev_rate_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICERATESETUP_T **ppstVdevRateRec);

extern UINT32 ac_devm_get_vdev_power_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T **ppstVdevPowerRec);

extern UINT32 ac_devm_get_vdev_advanced_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T **ppstVdevAdvancedRec);


extern UINT32 ac_devm_get_vdev_wids_rec (AC_VDEVID_T *pstVdevId, 
										AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T **ppstVdevWidsRec);

extern UINT32 ac_devm_get_vdev_rrm_rec (AC_VDEVID_T *pstVdevId, 
									     AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T **ppstVdevRRMRec);

extern UINT32 ac_devm_get_vap_basic_rec (AC_VAPID_T *pstVapId, 
										AC_DB_TBL_WTPAPBASICSETUP_T **ppstVapBasicRec);

extern UINT32 ac_devm_get_vap_security_rec (AC_VAPID_T *pstVapId, 
									AC_DB_TBL_WTPAPSECURITYSETUP_T **ppstVapSecurityRec);

extern UINT32 ac_devm_get_vap_advanced_rec (AC_VAPID_T *pstVapId, 
									AC_DB_TBL_WTPAPADVANCEDSETUP_T **ppstVapAdvancedRec);

extern UINT32 ac_devm_get_adhoc_security_rec(AC_ADHOCID_T *pstAdhocId, 
									AC_DB_TBL_WTPADHOCSECURITYSETUP_T	**ppstAdhocSecRec);
									
extern UINT32 ac_devm_get_fwrulebasic_rec (UINT32	ulAcId,
											UINT32	ulRuleId, 
											AC_DB_TBL_ACFIREWALLRULEBASICSETUP_T	**ppstBasicRec);

extern UINT32 ac_devm_get_fwl7match_rec (UINT32	ulAcId,
											UINT32	ulRuleId, 
											AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T	**ppstRec);

extern UINT32	ac_devm_vap_get_ifid (AC_VAPID_T *pstIn, AC_VAPID_T *pstOut);
extern UINT32	ac_devm_adhoc_get_ifid (AC_ADHOCID_T *pstIn, AC_ADHOCID_T *pstOut);

extern UINT32	ac_devm_vap_get_vdevid(AC_VAPID_T *pstIn, AC_VAPID_T *pstOut);
extern UINT32 ac_devm_vap_get_devname(int vapId, int wifiId, char *vapDevName);

extern UINT32  ac_devm_get_vdev_wifilist(AC_VDEVID_T *pstVdevId, AC_DEVM_VDEV_WIFILIST_T *pstWifiList, UINT8 ucFlag);

extern UINT32  ac_devm_get_iftype(UINT32	ulDevId,
								UINT32 ulIfId, 
								UINT32	*pulIfType,
								UINT8 ucFlag);

extern VOID ac_devm_copy_ac_basic_cfg(AC_DEVM_ACBASIC_CONFIG_T *pstDst, 
										AC_DB_TBL_ACBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_ac_aaa_cfg(AC_DEVM_RADIUS_SERVERS_T *pstDst, 
										AC_DB_TBL_ACAAASETUP_T *pstSrc);
										
extern VOID ac_devm_copy_ssid_aaa_cfg(AC_DEVM_RADIUS_SERVERS_T *pstDst, 
										AC_DB_TBL_ACSSIDAUTHSETUP_T *pstSrc);
extern VOID	ac_devm_copy_ac_authsrv_cfg(AC_DEVM_RADIUS_AUTHSERVERS_T *pstDst, 
												AC_DB_TBL_ACAAASETUP_T *pstSrc);										
extern VOID	ac_devm_copy_ac_acctsrv_cfg(AC_DEVM_RADIUS_ACCTSERVERS_T *pstDst, 
												AC_DB_TBL_ACAAASETUP_T *pstSrc);
extern VOID	ac_devm_copy_ssid_authsrv_cfg(AC_DEVM_RADIUS_AUTHSERVERS_T *pstDst, 
												AC_DB_TBL_ACSSIDAUTHSETUP_T *pstSrc);
extern VOID	ac_devm_copy_ssid_acctsrv_cfg(AC_DEVM_RADIUS_ACCTSERVERS_T *pstDst, 
												AC_DB_TBL_ACSSIDAUTHSETUP_T *pstSrc);
												
extern VOID ac_devm_copy_ac_keeper_cfg(AC_DEVM_ACKEEPER_CONFIG_T *pstDst, 
										AC_DB_TBL_ACKEEPERSETUP_T *pstSrc);										

extern VOID ac_devm_copy_ac_snmpv2_cfg(AC_DEVM_SNMPV2_CONFIG_T *pstDst,
									AC_DB_TBL_ACSYSSNMPV2SETUP_T *pstSrc);

extern VOID ac_devm_copy_ac_snmpv3_cfg(AC_DEVM_SNMPV3_CONFIG_T *pstDst,
									AC_DB_TBL_ACSYSSNMPV3SETUP_T *pstSrc);
extern VOID ac_devm_copy_ac_snmptrap_cfg(AC_DEVM_SNMPTRAP_CONFIG_T *pstDst,
									AC_DB_TBL_ACSYSTRAPSVRSETUP_T	*pstSrc);
									
extern VOID ac_devm_copy_acassocswver_cfg(AC_DEVM_ASSOCSWVERSETUP_CONFIG_T	*pstDst,
									AC_DB_TBL_ACASSOCSWVERSETUP_T		*pstSrc);
									
extern VOID ac_devm_copy_ac_sntp_cfg(AC_DEVM_ACSNTP_CONFIG_T *pstDst,
									AC_DB_TBL_ACSNTPGLOBALSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_sntp_cfg(AC_DEVM_WTPSNTP_CONFIG_T *pstDst,
									AC_DB_TBL_WTPSYSSNTPSETUP_T	*pstSrc);

extern VOID ac_devm_copy_ac_log_cfg(AC_DEVM_LOG_CONFIG_T *pstDst,
									AC_DB_TBL_ACLOGSETUP_T	*pstSrc);

extern VOID ac_devm_copy_wtp_log_cfg(AC_DEVM_LOG_CONFIG_T *pstDst,
									AC_DB_TBL_WTPSYSLOGSETUP_T *pstSrc);

extern VOID ac_devm_copy_logsvr_cfg(AC_DEVM_LOGSVR_CONFIG_T *pstDst,
									AC_DB_TBL_ACLOGSERVERSETUP_T *pstSrc);

extern VOID ac_devm_copy_ac_port_cfg(AC_DEVM_ACPORT_CONFIG_T *pstDst,
									AC_DB_TBL_ACIFSETUP_T	*pstSrc);

extern VOID ac_devm_copy_wtp_enet_cfg(AC_DEVM_ENET_CONFIG_T 	*pstDst,
									AC_DB_TBL_WTPENETBASICSETUP_T	*pstSrc);
									
extern UINT32 ac_devm_copy_ac_port_name(UINT32 ulIfId, CHAR *pcIfName);


extern VOID ac_devm_copy_vlan_cfg(AC_DEVM_VLAN_CONFIG_T *pstDst,
								AC_DB_TBL_ACVLANSETUP_T	*pstSrc);

extern VOID ac_devm_copy_vlanifmap_cfg(AC_DEVM_VLANIFMAP_CONFIG_T *pstDst,
										AC_DB_TBL_ACIFVLANMAPPINGSETUP_T *pstSrc,
										UINT32	ulIfType,
										CHAR	*pcIfName);

extern VOID ac_devm_copy_vlanmacmap_cfg(AC_DEVM_VLANMACMAP_CONFIG_T *pstDst,
										AC_DB_TBL_ACMACVLANMAPPINGSETUP_T *pstSrc);

extern VOID ac_devm_copy_vlanaccmacpolicy_cfg(AC_DEVM_VLANACCMACPOLICY_CONFIG_T *pstDst,
										AC_DB_TBL_ACVLANACCESSMACPOLICYSETUP_T *pstSrc);

extern VOID ac_devm_copy_vlanaccmac_cfg(AC_DEVM_VLANACCMAC_CONFIG_T *pstDst,
										AC_DB_TBL_ACVLANACCESSMACLISTSETUP_T *pstSrc);

extern VOID ac_devm_copy_igmpsnoop_cfg(AC_DEVM_IGMPSNOOP_CONFIG_T *pstDst,
										AC_DB_TBL_ACIGMPSNOOPSETUP_T *pstSrc);

extern VOID ac_devm_copy_igmpproxy_cfg(AC_DEVM_IGMPPROXY_CONFIG_T *pstDst,
										AC_DB_TBL_ACIGMPPROXYSETUP_T	*pstSrc);


extern VOID ac_devm_copy_routestatic_cfg(AC_DEVM_ROUTESTATIC_CONFIG_T *pstDst,
									AC_DB_TBL_ACSTATICROUTESETUP_T	*pstSrc);

extern VOID ac_devm_copy_ripglobal_cfg(AC_DEVM_RIPGLOBAL_CONFIG_T *pstDst,
									AC_DB_TBL_ACRIPGLOBALSETUP_T *pstSrc);

extern VOID ac_devm_copy_ripnotifynet_cfg(AC_DEVM_RIPNOTIFYNET_CONFIG_T *pstDst,
										   AC_DB_TBL_ACRIPANNOUNCENETSETUP_T *pstSrc);



extern VOID ac_devm_copy_fwglobal_cfg(AC_DEVM_FWGLOBAL_CONFIG_T *pstDst,
									AC_DB_TBL_ACFIREWALLGLOBALSETUP_T *pstSrc);

extern VOID ac_devm_copy_fwl7match_cfg(AC_DEVM_FWL7MATCH_CONFIG_T *pstDst,
										AC_DB_TBL_ACFIREWALLL7MATCHSETUP_T *pstSrc);

extern VOID ac_devm_copy_nat_cfg(AC_DEVM_NAT_CONFIG_T *pstDst,
								AC_DB_TBL_ACNATSETUP_T *pstSrc);

extern VOID ac_devm_copy_idsrule_cfg(AC_DEVM_IDSRULE_CONFIG_T *pstDst,
								AC_DB_TBL_ACIDSRULESETUP_T *pstSrc);

extern VOID ac_devm_copy_idsstry_cfg(AC_DEVM_IDSSTRY_CONFIG_T *pstDst,
								AC_DB_TBL_ACIDSSTRATEGYSETUP_T *pstSrc);


extern VOID ac_devm_copy_qosglobal_cfg(AC_DEVM_QOSGLOBAL_CONFIG_T *pstDst,
										AC_DB_TBL_ACQOSGLOBALSETUP_T *pstSrc);


extern VOID ac_devm_copy_qosusrdft_cfg(AC_DEVM_QOSUSRDFT_CONFIG_T *pstDst,
									AC_DB_TBL_ACQOSUSERDEFAULTSETUP_T *pstSrc);

extern VOID ac_devm_copy_qosvlan_cfg(AC_DEVM_QOSVLAN_CONFIG_T *pstDst,
									AC_DB_TBL_ACVLANQOSSETUP_T *pstSrc);

extern VOID ac_devm_copy_qosssid_cfg(AC_DEVM_QOSSSID_CONFIG_T *pstDst,
									AC_DB_TBL_ACSSIDQOSSETUP_T *pstSrc);

extern VOID ac_devm_copy_ac_alarmfilter_cfg(AC_DEVM_ALARMFILTER_CONFIG_T *pstDst,
									AC_DB_TBL_ACALARMFILTERSETUP_T *pstSrc);


extern VOID ac_devm_copy_ac_perfcounter_cfg(AC_DEVM_PERFCOUNTER_CONFIG_T *pstDst,
									AC_DB_TBL_ACPERFCOUNTERGROUPINFOSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_alarmfilter_cfg(AC_DEVM_ALARMFILTER_CONFIG_T *pstDst,
									AC_DB_TBL_WTPALARMIFILTERSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_perfcounter_cfg(AC_DEVM_PERFCOUNTER_CONFIG_T *pstDst,
									AC_DB_TBL_WTPPERFCOUNTERGROUPINFOSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_swsvr_cfg(AC_DEVM_SWSVR_CONFIG_T *pstDst,
									AC_DB_TBL_WTPSYSSWSERVERSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_lb_cfg(AC_DEVM_LOADBALANCE_CONFIG_T *pstDst, 
									AC_DB_TBL_WTPSYSLOADBALANCESETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_basic_cfg (AC_DEVM_WTPBASIC_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPSYSBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_ip_cfg (AC_DEVM_WTPIP_CONFIG_T *pstDst, 
									AC_DB_TBL_WTPSYSIPSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_capwap_cfg (AC_DEVM_WTPCAPWAP_CONFIG_T *pstDst, 
									AC_DB_TBL_WTPCAPWAPSETUP_T *pstSrc);

extern VOID ac_devm_copy_wtp_asso_cfg (AC_DEVM_WTPASSO_CONFIG_T *pstDst, 
									AC_DB_TBL_ACWTPASSOCIATESETUP_T	*pstSrc);

extern VOID ac_devm_copy_vdev_basic_cfg (AC_DEVM_VDEVBASIC_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_channel_cfg (AC_DEVM_VDEVCHANNEL_CONFIG_T *pstDst, 
											AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_rate_cfg (AC_DEVM_VDEVRATE_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPWIFIDEVICERATESETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_power_cfg (AC_DEVM_VDEVPOWER_CONFIG_T *pstDst, 
											AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_advanced_cfg (AC_DEVM_VDEVADVANCED_CONFIG_T *pstDst, 
											AC_DB_TBL_WTPWIFIDEVICEADVANCEDSETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_wids_cfg (AC_DEVM_VDEVWIDS_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPWIFIDEVICEWIDSSETUP_T *pstSrc);

extern VOID ac_devm_copy_vdev_rrm_cfg (AC_DEVM_VDEVRRM_CONFIG_T *pstDst, 
                                AC_DB_TBL_WTPWIFIDEVICERESOURCESETUP_T *pstRrmRec,
                                AC_DB_TBL_WTPWIFIDEVICECHANNELSETUP_T *pstChannelRec,
										AC_DB_TBL_WTPWIFIDEVICEPOWERSETUP_T	*pstPowerRec);

extern VOID ac_devm_copy_vdev_neigh_cfg (AC_DEVM_VDEVNEIGH_CONFIG_T *pstDst, 
										AC_DB_TBL_ACNEIGHBORSETUP_T *pstSrc);

extern VOID ac_devm_copy_if_basic_cfg (AC_DEVM_IF_CONFIG_T *pstDst, 
									AC_DB_TBL_WTPWIFIDEVICEBASICSETUP_T*pstSrc, 
									UINT32 ulIndex);

extern VOID ac_devm_copy_vap_basic_cfg (AC_DEVM_VAP_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPAPBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_vap_security_cfg (AC_DEVM_VAP_CONFIG_T *pstDst, 
											AC_DB_TBL_WTPAPSECURITYSETUP_T *pstSrc);

extern VOID ac_devm_copy_vap_advanced_cfg (AC_DEVM_VAP_CONFIG_T *pstDst, 
											AC_DB_TBL_WTPAPADVANCEDSETUP_T *pstSrc);

extern UINT32 ac_devm_copy_vap_if_name (AC_DEVM_VAP_CONFIG_T *pstDst, 
										AC_DB_TBL_WTPAPBASICSETUP_T *pstSrc, 
										UINT32 ulIfId);

extern VOID ac_devm_copy_vap_bssid (AC_DEVM_VAP_BSSID_T *pstDst, 
									AC_DB_TBL_WTPAPBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_vap_stat (AC_DEVM_VAP_TRAFFICSTAT_T *pstDst, AC_DB_TBL_WTPAPSTAT_T *pstSrc);

extern VOID ac_devm_copy_vapstat_cfg (AC_DB_TBL_WTPAPSTAT_T *pstDst, AC_DB_TBL_WTPAPBASICSETUP_T *pstSrc);

extern VOID ac_devm_copy_adhoc_cfg (AC_DEVM_ADHOC_CONFIG_T *pstDst, AC_DB_TBL_WTPADHOCBASICSETUP_T *pstSrc);




extern VOID ac_devm_copy_pppoeserver_cfg (AC_DEVM_PPPOESERVER_CONFIG_T	*pstDst, AC_DB_TBL_ACPPPOESETUP_T *pstSrc);

extern VOID ac_devm_copy_pppoeaaa_cfg (AC_DEVM_PPPOESERVER_CONFIG_T	*pstDst, AC_DB_TBL_ACAAASETUP_T *pstSrc);


extern VOID ac_devm_copy_macserver_cfg (AC_DEVM_MACSERVER_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACMACSERVERSETUP_T	*pstSrc);
										
extern VOID ac_devm_copy_portal_cfg (AC_DEVM_PORTAL_CONFIG_T	*pstDst, 
									AC_DB_TBL_ACPORTALSETUP_T	*pstSrc);

extern VOID ac_devm_copy_whitelist_cfg (AC_DEVM_WHITELIST_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACWHILTELISTSETUP_T *pstSrc);

extern VOID ac_devm_copy_wapias_cfg (AC_DEVM_WAPIAS_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACWAPIASSETUP_T *pstSrc);
extern VOID ac_devm_copy_wapi_cfg (AC_DEVM_WAPI_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACWAPISETUP_T *pstSrc);
extern VOID ac_devm_copy_wapicertfile_cfg (AC_DEVM_WAPICERTFILE_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACWAPICERTFILESETUP_T *pstSrc);		

extern VOID ac_devm_copy_whiteurllist_cfg (AC_DEVM_WHITEURL_CONFIG_T	*pstDst, 
										AC_DB_TBL_ACWHITEURLLISTSETUP_T *pstSrc);			
extern VOID ac_devm_copy_acmssetup_cfg	(AC_DEVM_MSSETUP_CONFIG_T	*pstDst, 
											AC_DB_TBL_ACMSSETUP_T *pstSrc);
										
/******************************* 源文件结束 **********************************/



#endif /* _AC_DEVM_COMMON_H */
/******************************* 头文件结束 **********************************/

