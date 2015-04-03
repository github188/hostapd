/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  配置流程头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DEVM_IF_H
#define  _AC_DEVM_IF_H

extern VOID ac_devm_get_radius_servers (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ac_ownconfig (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ac_moid (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ackeepercfg (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_acuplinkstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpasso_byid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_wtp_byid (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_ownconfig (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_bindacid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_curacid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_bysn (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_if_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vdevlist_config  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vdevneigh_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vdev_moid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vdev_byid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_vap_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vap_config_byvdev (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_vapbssid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_adhocbssid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_vdevmaxtxpower  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_vaptrafficstat  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_vapwifistat  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vap_moid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vapid_bybssid  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vap_config_bywtp (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_adhoc_config_bywtp (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_set_wtp_opstate  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_slaveobj_opstate  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vdev_opstate  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vap_opstate  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtp_assostate  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vdev_dynpower (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtpip  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpip  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpid_byip  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtp_sn (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_allocate_wtpid (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_snmpv2_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_snmpv3_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_snmptrap_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acswversion (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtpswupdate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtpcfgupdate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acassoswver_config  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpswversion_config  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtpcurswversion  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpcfgversion  (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
	
extern VOID ac_devm_get_acsntp_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtpsntp_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_acport_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wanifname_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_enet_config_bywtp (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acbridge_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_l2wan_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_l3wan_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acport_byid (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_l2wan_firstip_config(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
/* 2011-6-21 AC主备功能修改*/
extern VOID ac_devm_get_msport_config(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );


extern VOID ac_devm_get_vlanglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlan_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanssidmap_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanifmap_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanmacmap_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanaccmacpolicy_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanaccmac_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_vlanforif_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );


extern VOID ac_devm_get_igmpsnoop_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_igmpproxy_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_routeglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_routeif_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_routestatic_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ripglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ripnotifyip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ripnotifyif_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ripif_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_fwglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_fwrule_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_p2p_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_natglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_nat_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_idsrule_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_idsstry_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_stadhcpglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_stadhcpstaticip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_stadhcpdynip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_apdhcpglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_apdhcpstaticip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_apdhcpdynip_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_qosglobal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_qosport_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_qosusrdft_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_qosvlan_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_qosssid_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_alarmfilter_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acalarmthreshold_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_perfcounter_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_swsvr_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_cfg_version (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_pppoeserver_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_pppoeclient_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_macserver_config(UINT8 * pucIn, UINT32 ulInLen, UINT8 * pucOut, UINT32 * pulOutLen);
extern VOID ac_devm_get_portal_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_whitelist_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_useraddrbind_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_freeaddr_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_freemac_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_freessid_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_freevlan_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_freeglobal_config(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_whiteurllist_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_log_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_logsvr_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_wapias_config(UINT8 * pucIn, UINT32 ulInLen, UINT8 * pucOut, UINT32 * pulOutLen);
extern VOID ac_devm_get_wapi_config(UINT8 * pucIn, UINT32 ulInLen, UINT8 * pucOut, UINT32 * pulOutLen);
extern VOID ac_devm_get_wapicertfile_config(UINT8 * pucIn, UINT32 ulInLen, UINT8 * pucOut, UINT32 * pulOutLen);
extern VOID   ac_devm_get_vap_opstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID   ac_devm_get_acdevice_abstract (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID   ac_devm_add_unregwtp (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID   ac_devm_del_unregwtp (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID   ac_devm_get_mssetup_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID   ac_devm_set_msstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID   ac_devm_get_enet_moid (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID   ac_devm_get_wtp_targetversion (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_get_vapadminstate (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_apacl (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_ssidradiusservers (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_staradiusservers (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_authservers (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acctservers (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_acvrrpfirstip(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern VOID ac_devm_set_vapbssid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vaptrafficstat(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vapwifistat(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_vdevmaxpower(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_adhocbssid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_set_wtp_mac(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern VOID ac_devm_get_wtpmac(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

extern VOID ac_devm_is_active(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

extern VOID  ac_devm_get_wtpsntp_bywtp_config (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_wtp_moid(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_manageip(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

/* add by gwx 2013-4-7 for task668 */
extern VOID ac_devm_set_wtpsrcaddr(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);
extern VOID ac_devm_get_wtpidbyportandip(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

/* add by gwx 2013-8-16 for 企业网先集中后本地需求*/
extern VOID ac_devm_get_portalip( UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

/* add by gwx 2014-2-25 for task1265 */
extern VOID ac_devm_set_wtp_producttype (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
/* add by gwx 2014-8-7 */
extern VOID ac_devm_set_wtp_curchannellist(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_devm_get_aclinkip(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen);

#endif /* _AC_DEVM_IF_H */
/******************************* 头文件结束 **********************************/

