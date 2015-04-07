/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ���ݿ�ͳһ�ӿڹ���ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_DEVM_PUBLIC_H
#define  _AC_DEVM_PUBLIC_H

/***************************DEVM ģ����Ϣ�Ŷ���*****************************/
#define ADHOC_IFID(ulWtpId, ulVdevId, ulAdhocId)		((ulAdhocId))
#define ENET_IFID(ulWtpId, ulEnetId)					(4 + (ulEnetId))
#define VAP_IFID(ulWtpId, ulVdevId, ulVapId)			(8 + (ulVapId))

#define VDEV_IFID(ulWtpId, ulVdevId)					(24 + (ulVdevId))

/* DEVMģ����Ϣ�Ŷ��� */
/* ��׼�ӿ���Ϣ��*/
#define AC_DEVM_IF_MAX    400        /* DEVMģ�����ӿ���*/
#define AC_DEVM_MAX_PORTALIP_NUM  	8 	/*��ȡportal ip��ַ�������Ŀ*/

#define AC_DEVM_GET_RADIUS_CONFIG_MSG                   	(EV_DEVM_BEGIN+1)	/* ��ȡAAA ����*/
#define AC_DEVM_GET_AC_OWNCONFIG_MSG                    	(EV_DEVM_BEGIN+2)	/* ��ȡAC���豸����*/
#define AC_DEVM_GET_AC_MOID_MSG						(EV_DEVM_BEGIN+3)	/* ��ȡAC MOID */
#define AC_DEVM_GET_WTPASSO_BYID_MSG				(EV_DEVM_BEGIN+4)	/* ����AP ID��ȡAP-AC��������*/
#define AC_DEVM_GET_ACKEEPERCFG_MSG					(EV_DEVM_BEGIN+5)	/* ��ȡAC������·�����Լ������*/
#define AC_DEVM_SET_ACUPLINKSTATE_MSG				(EV_DEVM_BEGIN+6)	/* ����AC������·״̬*/

#define AC_DEVM_GET_WTP_BYID_MSG                        		(EV_DEVM_BEGIN+11)	
#define AC_DEVM_GET_WTP_OWNCONFIG_MSG                   	(EV_DEVM_BEGIN+12)
#define AC_DEVM_GET_WTP_CONFIG_MSG                     	 	(EV_DEVM_BEGIN+13)
#define AC_DEVM_GET_BINDACID_MSG						(EV_DEVM_BEGIN+14)			
#define AC_DEVM_GET_CURACID_MSG						(EV_DEVM_BEGIN+15)	
#define AC_DEVM_GET_WTP_BYSN_MSG                        		(EV_DEVM_BEGIN+16)	/* ����AP�豸���кŻ�ȡAP������Ϣ*/

#define AC_DEVM_GET_IF_CONFIG_MSG                       		(EV_DEVM_BEGIN+21)
#define AC_DEVM_GET_VDEVLIST_CONFIG_MSG                 	(EV_DEVM_BEGIN+22)
#define AC_DEVM_GET_VDEVNEIGH_CONFIG_MSG                	(EV_DEVM_BEGIN+23)
#define AC_DEVM_GET_VDEV_MOID_MSG					(EV_DEVM_BEGIN+24)
#define AC_DEVM_GET_VDEV_BYID_MSG					(EV_DEVM_BEGIN+25)

#define AC_DEVM_GET_WTP_VDEVMAXTXPOWER_MSG		(EV_DEVM_BEGIN+29)	/* ��ȡ���������豸������书��*/
#define AC_DEVM_GET_WTP_ADHOCBSSID_MSG				(EV_DEVM_BEGIN+30)	/* ��ȡ���лش�ģ���BSSID */
#define AC_DEVM_GET_VAP_CONFIG_MSG                      		(EV_DEVM_BEGIN+31)
#define AC_DEVM_GET_VAP_CONFIG_BYVDEV_MSG               (EV_DEVM_BEGIN+32)
#define AC_DEVM_GET_WTP_VAPBSSID_MSG                    	(EV_DEVM_BEGIN+33)
#define AC_DEVM_GET_WTP_VAPTRAFFICSTAT_MSG              	(EV_DEVM_BEGIN+34)
#define AC_DEVM_GET_VAP_MOID_MSG                        		(EV_DEVM_BEGIN+35)
#define AC_DEVM_GET_VAPID_BYBSSID_MSG				(EV_DEVM_BEGIN+36)
#define AC_DEVM_GET_VAP_CONFIG_BYWTP_MSG               	(EV_DEVM_BEGIN+37)	/* ��ȡWTP AP������*/
#define AC_DEVM_GET_ADHOC_CONFIG_BYWTP_MSG		(EV_DEVM_BEGIN+38)	/* ��ȡWTP ADHOC������*/
#define AC_DEVM_GET_WTP_VAPWIFISTAT_MSG				(EV_DEVM_BEGIN+39)	/* ��ȡVAP����ͳ����Ϣ*/

#define AC_DEVM_ALLOCATE_WTPID_MSG					(EV_DEVM_BEGIN+40)	/* ����һ�����е�WtpId (�豸��ǰ���к�Ϊȫ0)*/
#define AC_DEVM_SET_WTP_OPSTATE_MSG                     	(EV_DEVM_BEGIN+41)
#define AC_DEVM_SET_SLAVEOBJ_OPSTATE_MSG                	(EV_DEVM_BEGIN+42)
#define AC_DEVM_SET_VDEV_OPSTATE_MSG                    	(EV_DEVM_BEGIN+43)
#define AC_DEVM_SET_VAP_OPSTATE_MSG                     	(EV_DEVM_BEGIN+44)
#define AC_DEVM_SET_WTP_ASSOSTATE_MSG				(EV_DEVM_BEGIN+45)
#define AC_DEVM_SET_VDEV_DYNPOWER_MSG				(EV_DEVM_BEGIN+46)	/* ��������ģ�鵱ǰ��̬���书��ֵ*/
#define AC_DEVM_SET_WTPIP_MSG							(EV_DEVM_BEGIN+47)	/* ����ָ��AP�豸��IP��ַ */
#define AC_DEVM_GET_WTPIP_MSG						(EV_DEVM_BEGIN+48)	/* ��ȡָ��AP�豸��IP��ַ*/
#define AC_DEVM_GET_WTPID_BYIP_MSG					(EV_DEVM_BEGIN+49)	/* ����WTP IP��ȡWTP ID */
#define AC_DEVM_SET_WTP_SN_MSG						(EV_DEVM_BEGIN+50)	/* ����AP�����к�*/

#define AC_DEVM_GET_SNMPV2_CONFIG_MSG                   	(EV_DEVM_BEGIN+51)
#define AC_DEVM_GET_SNMPV3_CONFIG_MSG                   	(EV_DEVM_BEGIN+52)
#define AC_DEVM_GET_SNMPTRAP_CONFIG_MSG                   	(EV_DEVM_BEGIN+53)
#define AC_DEVM_GET_ACSWVERSION_MSG                   		(EV_DEVM_BEGIN+54)	/* ��ȡAC��ǰ������汾��*/
#define AC_DEVM_SET_WTPSWUPDATE_MSG					(EV_DEVM_BEGIN+55)	/* AP �汾����ʱ, OMA���ñ��ӿ�*/	
#define AC_DEVM_SET_WTPCFGUPDATE_MSG				(EV_DEVM_BEGIN+56)	/* AP�����޸�ʱ, OMA���ñ��ӿ�*/
#define AC_DEVM_GET_ACASSOCSWVER_CONFIG_MSG		(EV_DEVM_BEGIN+57)	/* ��ȡAC֧�ֵ�AP����汾�б�ӿ�*/
#define AC_DEVM_GET_WTPSWVERSION_MSG				(EV_DEVM_BEGIN+58)	/* ��ȡָ��AP������汾���ýӿ�*/
#define AC_DEVM_SET_WTPCURSWVERSION_MSG			(EV_DEVM_BEGIN+59)	/* ����AP��ǰ����汾��*/
#define AC_DEVM_GET_WTPCFGVERSION_MSG				(EV_DEVM_BEGIN+60)	/* ��ȡAP��ǰ�������ݰ汾��*/


#define AC_DEVM_GET_ACSNTP_CONFIG_MSG                     	(EV_DEVM_BEGIN+61)
#define AC_DEVM_GET_WTPSNTP_CONFIG_MSG                  	(EV_DEVM_BEGIN+62)

#define AC_DEVM_GET_ACPORT_CONFIG_MSG                   	(EV_DEVM_BEGIN+71)
#define AC_DEVM_GET_ENET_CONFIG_BYWTP_MSG               	(EV_DEVM_BEGIN+72)	/* ��ȡWTP ������������*/
#define AC_DEVM_GET_ACBRIDGE_CONFIG_MSG				(EV_DEVM_BEGIN+73)	/* ��ȡAC������*/
#define AC_DEVM_GET_ACIP_CONFIG_MSG					(EV_DEVM_BEGIN+74)	/* ��ȡAC�˿�IP��ַ����*/
#define AC_DEVM_GET_L2WAN_CONFIG_MSG				(EV_DEVM_BEGIN+75)	/* ��ȡL2-WAN/FAT-LAN ������*/
#define AC_DEVM_GET_L3WAN_CONFIG_MSG				(EV_DEVM_BEGIN+76)	/* ��ȡL3-WAN ������*/
#define AC_DEVM_GET_ACPORT_BYID_MSG					(EV_DEVM_BEGIN+77)	/* ����AC����˿ںŻ�ȡָ���˿�����*/
#define AC_DEVM_GET_L2WAN_FIRSTIP_CONFIG_MSG		(EV_DEVM_BEGIN+78)	/* ��ȡFATLAN/L2WAN ��һ��IP */
#define AC_DEVM_GET_ACMSPORT_CONFIG_MSG				(EV_DEVM_BEGIN+79)	/* 2011-6-21 ����: ��ȡAC�����˿�����*/

#define AC_DEVM_GET_VLANGLOBAL_CONFIG_MSG			(EV_DEVM_BEGIN+81)	/* ��ȡVLANȫ������*/
#define AC_DEVM_GET_VLAN_CONFIG_MSG                     	(EV_DEVM_BEGIN+82)	/* ��ȡVLAN����*/
#define AC_DEVM_GET_VLANSSIDMAP_CONFIG_MSG			(EV_DEVM_BEGIN+83)	/* ��ȡSSID-VLANӳ������*/
#define AC_DEVM_GET_VLANIFMAP_CONFIG_MSG                	(EV_DEVM_BEGIN+84)	/* ��ȡ�˿�-VLANӳ������*/
#define AC_DEVM_GET_VLANMACMAP_CONFIG_MSG              	(EV_DEVM_BEGIN+85)	/* ��ȡMAC-VLANӳ������*/
#define AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_MSG	(EV_DEVM_BEGIN+86)	/* ��ȡMAC���˲�������*/
#define AC_DEVM_GET_VLANACCMAC_CONFIG_MSG              	(EV_DEVM_BEGIN+87)	/* ��ȡMAC�����б�����*/
/* 2009-11-5 pyy ����*/
#define AC_DEVM_GET_VLANFORIF_CONFIG_MSG			(EV_DEVM_BEGIN+88)	/* ��ȡVLAN�ڸ��˿��ϵ��������*/

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

#define AC_DEVM_GET_PPPOESERVER_CONFIG_MSG			(EV_DEVM_BEGIN+191)		/* ��ȡPPPoE����*/

#define AC_DEVM_GET_MACSERVER_CONFIG_MSG			(EV_DEVM_BEGIN+195)		/* ��ȡMAC Server����*/

#define AC_DEVM_GET_PORTAL_CONFIG_MSG				(EV_DEVM_BEGIN+201)		/* ��ȡWEB��֤ȫ������*/
#define AC_DEVM_GET_WHITELIST_CONFIG_MSG			(EV_DEVM_BEGIN+202)		/* ��ȡWEB��֤����������*/
#define AC_DEVM_GET_USERADDRBIND_CONFIG_MSG		(EV_DEVM_BEGIN+203)		/* ��ȡ�û�����ַ������*/
#define AC_DEVM_GET_FREEADDR_CONFIG_MSG				(EV_DEVM_BEGIN+204)		/* ��ȡ����֤��ַ�б�����*/
#define AC_DEVM_GET_FREESSID_CONFIG_MSG				(EV_DEVM_BEGIN+205)		/* ��ȡ����֤SSID�б�����*/
#define AC_DEVM_GET_FREEVLAN_CONFIG_MSG				(EV_DEVM_BEGIN+206)		/* ��ȡ����֤VLAN�б�����*/
#define AC_DEVM_GET_FREEMAC_CONFIG_MSG				(EV_DEVM_BEGIN+207)		/* ��ȡ����֤IP�б�����*/
#define AC_DEVM_GET_FREEGLOBAL_CONFIG_MSG			(EV_DEVM_BEGIN+208)		/* ��ȡȫ������֤����*/
#define AC_DEVM_GET_WHITEURLLIST_CONFIG_MSG			(EV_DEVM_BEGIN+209)		/* ��ȡ������URL ����*/

#define AC_DEVM_GET_LOG_CONFIG_MSG					(EV_DEVM_BEGIN+211)		/* ��ȡ��־����*/
#define AC_DEVM_GET_LOGSVR_CONFIG_MSG				(EV_DEVM_BEGIN+212)		/* ��ȡ��־����������*/

#define AC_DEVM_GET_WAPIAS_CONFIG_MSG				(EV_DEVM_BEGIN+231)		/* ��ȡWAPI AS����������*/
#define AC_DEVM_GET_WAPI_CONFIG_MSG					(EV_DEVM_BEGIN+232)		/* ��ȡWAPI��������*/
#define AC_DEVM_GET_WAPICERTFILE_CONFIG_MSG			(EV_DEVM_BEGIN+233)		/* ��ȡWAPI֤������*/
#define AC_DEVM_GET_VAP_OPSTATE_MSG					(EV_DEVM_BEGIN+234)		/* ��ȡVAP״̬*/

#define AC_DEVM_GET_ACDEVICE_ABSTRACT_MSG			(EV_DEVM_BEGIN+241)		/* ��ȡAC�豸ժҪ��Ϣ�ӿ� */

#define AC_DEVM_ADD_UNREGWTP_MSG					(EV_DEVM_BEGIN+251)		/* ����AC��⵽��δע��AP */
#define AC_DEVM_DEL_UNREGWTP_MSG					(EV_DEVM_BEGIN+252)		/* ɾ��AC��⵽��δע��AP */
#define AC_DEVM_GET_WTP_TARGETVERSION_MSG			(EV_DEVM_BEGIN+253)		/* ��ȡָ��AP��Ŀ������汾*/

#define AC_DEVM_GET_MSSETUP_CONFIG_MSG				(EV_DEVM_BEGIN+261)		/* ��ȡ����������ؽӿ�*/
#define AC_DEVM_SET_MSSTATE_MSG						(EV_DEVM_BEGIN+262)		/* ���ñ���AC����״̬*/

#define AC_DEVM_GET_ENET_MOID_MSG					(EV_DEVM_BEGIN+271)		/* ��ȡ��̫���ڵ�MOID */

/* 2010-6-17 pyy ����: ��ʱ�ر�VAP���� */
#define AC_DEVM_GET_VAPADMINSTATE_MSG				(EV_DEVM_BEGIN+281)		/* ��ȡָ��AP������VAP����״̬*/
#define AC_DEVM_GET_APACL_MSG						(EV_DEVM_BEGIN+282)		/* ��ȡAP���ʲ�������*/
#define AC_DEVM_GET_SSIDRADIUSSERVERS_MSG			(EV_DEVM_BEGIN+283)		/* ����VAP��ȡAAA��������Ϣ*/
#define AC_DEVM_GET_STARADIUSSERVERS_MSG			(EV_DEVM_BEGIN+284)		/* ����STA MAC ��ȡAAA��������Ϣ*/
#define AC_DEVM_GET_AUTHSERVERS_MSG					(EV_DEVM_BEGIN+285)		/* ��ȡ��Ȩ�������б�*/
#define AC_DEVM_GET_ACCTSERVERS_MSG					(EV_DEVM_BEGIN+286)		/* ��ȡ�Ʒѷ������б�*/
#define AC_DEVM_GET_ACVRRPFIRSTIP_MSG				(EV_DEVM_BEGIN+287)

/* 2010-12-28 pyy ����*/
#define AC_DEVM_SET_VAPBSSID_MSG						(EV_DEVM_BEGIN+291)		/* ����VAP BSSID */
#define AC_DEVM_SET_VAPTRAFFICSTAT_MSG				(EV_DEVM_BEGIN+292)		/* ����VAP ����ͳ��*/
#define AC_DEVM_SET_VAPWIFISTAT_MSG					(EV_DEVM_BEGIN+293)		/* ����VAP WIFIͳ��*/
#define AC_DEVM_SET_VDEVMAXPOWER_MSG				(EV_DEVM_BEGIN+294)		/* ���������豸����书��*/
#define AC_DEVM_SET_ADHOCBSSID_MSG					(EV_DEVM_BEGIN+295)		/* ����ADHOC BSSID */
/* 2011-01-25*/
#define AC_DEVM_SET_WTP_MAC_MSG						(EV_DEVM_BEGIN+301)		/* ����AP�豸MAC��ַ*/
#define AC_DEVM_GET_WTPMAC_MSG						(EV_DEVM_BEGIN+302)		/* ��ȡAP�豸MAC��ַ�б�*/

#define AC_DEVM_GET_WTPSNTP_CONFIG_BYWTP_MSG         	(EV_DEVM_BEGIN+303)
#define AC_DEVM_GET_WTP_MOID_MSG						(EV_DEVM_BEGIN+304)

/* add by gwx 2012-7-11 for bug1292 */
#define AC_DEVM_GET_MANAGEIP_MSG				(EV_DEVM_BEGIN+305)		/*��ȡtrap����ip��Ϣ*/

#define AC_DEVM_IS_ACTIVE_MSG							(EV_DEVM_BEGIN+306)		/* �����Ƿ�Active */
#define AC_DEVM_SET_WTPSRCADDR_MSG					(EV_DEVM_BEGIN+307)		/* ����AP��Ϣ��ԴIP��Դ�˿ں� add by gwx 2013-4-7 for task668*/
#define AC_DEVM_GET_WTPIDBYPORTANDIP_MSG			(EV_DEVM_BEGIN+308)		/* ����Դ�˿ںź�IP��ȡWtpId add by gwx 2013-4-7 for task668*/
/* add by gwx 2013-8-16 for ��ҵ���ȱ��غ�������*/
#define AC_DEVM_GET_PORTALIP_MSG						(EV_DEVM_BEGIN+309)	
/* add by gwx 2014-2-25 for task1265 */
#define AC_DEVM_SET_WTPPRODUCTTYPE_MSG				(EV_DEVM_BEGIN+310)		/*����AP��Ʒ����*/	

/* add by gwx 2014-8-7 */
#define AC_DEVM_SET_WTPCURCHANNELLIST_MSG			(EV_DEVM_BEGIN+311)		/* ����AP��ǰ�ŵ�*/

/* add by ght 2014-8-13 */
#define AC_DEVM_GET_ACLINKIP_MSG                  (EV_DEVM_BEGIN+312)		/* ��ȡAC LINK IP*/


#define AC_DEVM_POWERAC_OK_REQ_MSG					(EV_DEVM_BEGIN+499)
#define AC_DEVM_POWERAC_OK_RSP_MSG					(EV_DEVM_BEGIN+500)


/* ������Ϣ��*/
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
#define AC_DEVM_ALARMFILTER_UPDATE_IND_MSG               (EV_DEVM_BEGIN+763)		/* �澯�����仯ʱ֪ͨoma */

#define AC_DEVM_PERFCOUNTER_ADD_IND_MSG                 	(EV_DEVM_BEGIN+764)
#define AC_DEVM_PERFCOUNTER_DEL_IND_MSG                 	(EV_DEVM_BEGIN+765)
#define AC_DEVM_PERFCOUNTER_UPDATE_IND_MSG              (EV_DEVM_BEGIN+766)		/* *���ܱ����仯ʱ֪ͨoma */

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

/* ����֤IP�仯��Ϣ*/
#define AC_DEVM_FREEADDR_ADD_IND_MSG				(EV_DEVM_BEGIN+808)	
#define AC_DEVM_FREEADDR_DEL_IND_MSG				(EV_DEVM_BEGIN+809)	
#define AC_DEVM_FREEADDR_UPDATE_IND_MSG				(EV_DEVM_BEGIN+810)	

#define AC_DEVM_FREESSID_ADD_IND_MSG					(EV_DEVM_BEGIN+811)	
#define AC_DEVM_FREESSID_DEL_IND_MSG					(EV_DEVM_BEGIN+812)	
#define AC_DEVM_FREESSID_UPDATE_IND_MSG				(EV_DEVM_BEGIN+813)	

#define AC_DEVM_FREEVLAN_ADD_IND_MSG				(EV_DEVM_BEGIN+814)	
#define AC_DEVM_FREEVLAN_DEL_IND_MSG					(EV_DEVM_BEGIN+815)	
#define AC_DEVM_FREEVLAN_UPDATE_IND_MSG				(EV_DEVM_BEGIN+816)	

/* ����֤MAC�仯��Ϣ*/
#define AC_DEVM_FREEMAC_ADD_IND_MSG					(EV_DEVM_BEGIN+817)	
#define AC_DEVM_FREEMAC_DEL_IND_MSG					(EV_DEVM_BEGIN+818)	
#define AC_DEVM_FREEMAC_UPDATE_IND_MSG				(EV_DEVM_BEGIN+819)	

/* ȫ������֤���ر����Ϣ*/
#define AC_DEVM_FREEGLOBAL_UPDATE_IND_MSG			(EV_DEVM_BEGIN+820)	

/* ������URL���֪ͨ��Ϣ*/
#define AC_DEVM_WHITEURL_ADD_IND_MSG				(EV_DEVM_BEGIN+821)	
#define AC_DEVM_WHITEURL_DEL_IND_MSG				(EV_DEVM_BEGIN+822)	
#define AC_DEVM_WHITEURL_UPDATE_IND_MSG				(EV_DEVM_BEGIN+823)	

#define AC_DEVM_LOG_UPDATE_IND_MSG					(EV_DEVM_BEGIN+821)		
#define AC_DEVM_LOGSVR_UPDATE_IND_MSG				(EV_DEVM_BEGIN+822)

#define AC_DEVM_WAPIAS_UPDATE_IND_MSG				(EV_DEVM_BEGIN+841)

#define AC_DEVM_WTPASSO_UPDATE_IND_MSG				(EV_DEVM_BEGIN+851)
#define AC_DEVM_WTPASSO_DEL_IND_MSG					(EV_DEVM_BEGIN+852)

/* �������ñ��֪ͨ��Ϣ*/
#define AC_DEVM_MSSETUP_UPDATE_IND_MSG				(EV_DEVM_BEGIN+861)

#define AC_DEVM_AUTHSERVERS_ADD_IND_MSG				(EV_DEVM_BEGIN+871)		/* 	��Ȩ����������֪ͨ*/
#define AC_DEVM_AUTHSERVERS_DEL_IND_MSG				(EV_DEVM_BEGIN+872)		/*	��Ȩ������ɾ��֪ͨ*/
#define AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG			(EV_DEVM_BEGIN+873)		/*	��Ȩ�������޸�֪ͨ*/
#define AC_DEVM_ACCTSERVERS_ADD_IND_MSG				(EV_DEVM_BEGIN+874)		/*	�Ʒѷ���������֪ͨ*/
#define AC_DEVM_ACCTSERVERS_DEL_IND_MSG				(EV_DEVM_BEGIN+875)		/*	�Ʒѷ�����ɾ��֪ͨ*/
#define AC_DEVM_ACCTSERVERS_UPDATE_IND_MSG			(EV_DEVM_BEGIN+876)		/*	�Ʒѷ������޸�֪ͨ*/

/* 2011-6-21 AC���������޸�*/
#define AC_DEVM_ACUPLINK_UP_IND_MSG					(EV_DEVM_BEGIN+881)		/* AC������·�ָ�֪ͨ*/
#define AC_DEVM_ACUPLINK_DOWN_IND_MSG				(EV_DEVM_BEGIN+882)		/* AC������·����֪ͨ*/

/* add by gwx 2012-7-11 for bug1292 */
#define AC_DEVM_MANAGEIP_UPDATE_IND_MSG			(EV_DEVM_BEGIN+883)		/* trap����ip�仯֪ͨ*/

/* add by gwx 2014-6-3 for ���һ�������ռ�*/
#define AC_DEVM_GEN_DHCP_ALLOCATEINFO_REQ (EV_DEVM_BEGIN + 884)
#define AC_DEVM_GEN_DHCP_ALLOCATEINFO_RSP (EV_DEVM_BEGIN + 885)


/******************************************************************************/

#define AC_IF_NUM_MAX_PER_WTP       	4           /* ÿ��WTP�ϵ����ӿ��� */
#define AC_VDEV_NUM_MAX_PER_WTP		4          /* ÿ��WTP�ϵ���������豸�� */
#define AC_VAP_NUM_MAX_PER_IF       	16          /* ÿ���ӿ��������������VAP�� */
#define AC_ADHOC_NUM_MAX_PER_IF		4		/* ÿ���ӿ��������������ADHOC�� */

#define AC_VAP_NUM_MAX_PER_WTP  		(AC_IF_NUM_MAX_PER_WTP*AC_VAP_NUM_MAX_PER_IF)       	/* ÿ��WTP�ϵ����VAP�� */
#define AC_ADHOC_NUM_MAX_PER_WTP  	(AC_IF_NUM_MAX_PER_WTP*AC_ADHOC_NUM_MAX_PER_IF)      	 /* ÿ��WTP�ϵ����ADHOC�� */
#define AC_ENET_NUM_MAX_PER_WTP		2	/* ÿ��WTP�ϵ���������˿�����*/

#define AC_BIND_AC_NUM_MAX          		8           /* ÿ��AP���󶨵�AC�� */

/* ����״̬ */
#define AC_OPSTATE_NORMAL           		0        /* ���� */
#define AC_OPSTATE_FAULT            		1        /* ���� */

/* VAP����״̬ԭ���� */
#define AC_VAPSTATE_REASON_LINK     	0       /* AC��WTP֮�����·״̬�仯����VAP״̬���� */
#define AC_VAPSTATE_REASON_ADMIN    	1       /* VAP����״̬�仯����VAP״̬���� */

#define AC_ADMINSTATE_ENABLE        		0        /* ���� */
#define AC_ADMINSTATE_DISABLE       		1        /* ���� */

#define AC_DEVM_IFNAME_LEN          		16       /* �ӿ������� */

/* ������֤���Ͷ��� */
#define AC_DEVM_AUTH_AUTO      		0
#define AC_DEVM_AUTH_OPEN       	1
#define AC_DEVM_AUTH_SHARE      	2
#define AC_DEVM_AUTH_WPAPSK     	3
#define AC_DEVM_AUTH_WPA        		4
#define AC_DEVM_AUTH_MAC        		5
#define AC_DEVM_AUTH_WAPI      		6

/* ���ݼ������Ͷ��� */
#define AC_DEVM_ENCRYPT_DISABLE 	0
#define AC_DEVM_ENCRYPT_WEP   		1
#define AC_DEVM_ENCRYPT_TKIP    	2
#define AC_DEVM_ENCRYPT_AES    	3
#define AC_DEVM_ENCRYPT_SMS4    	4

/* �Ƿ�����802.1x��֤ȡֵ���� */
#define AC_DEVM_8021X_DISABLE	0
#define AC_DEVM_8021X_ENABLE	1

/* VAP ����״̬*/
#define AC_DEVM_ADMINSTATE_ENABLE		0
#define AC_DEVM_ADMINSTATE_DISABLE		1

#define AC_DEVM_CAPWAP_LINK_STATE_UNKNOWN		0
#define AC_DEVM_CAPWAP_LINK_STATE_NORMAL		1
#define AC_DEVM_CAPWAP_LINK_STATE_FAULT			2
#define AC_DEVM_CAPWAP_LINK_KEEPSTATE_FAULT		3	/* ������·���� */

/* AC��ID�궨��*/
#define AC_BRIDGE_ID_FITLAN		0
#define AC_BRIDGE_ID_L2WAN		1
#define AC_BRIDGE_ID_L3WAN		3

/* AC�����ƺ궨��*/
#define AC_BRIDGE_NAME_FITLAN	"br0"
#define AC_BRIDGE_NAME_L2WAN	"br1"
#define AC_BRIDGE_NAME_L3WAN	"br2"

/* AC�����IP��ַ��Ŀ�궨��*/
#define AC_BRIDGE_FITLAN_IPNUM_MAX	8
#define AC_BRIDGE_FATLAN_IPNUM_MAX	32
#define AC_BRIDGE_L2WAN_IPNUM_MAX	8
#define AC_BRIDGE_L3WAN_IPNUM_MAX	8

/* AC�������˿���*/
#define AC_PORT_NUM_MAX	16
   

/******************************DEVM�ӿ���ؽṹ�嶨��******************************/
/******************************************************************************/
/* ���ݽṹ���忪ʼ*/
/* ����Ӧ�ó���ѯ��powerac��״̬*/
typedef struct 
{
	char MyPname[32];	/* ��Ӧ�ó�������*/
} AC_DEVM_POWERAC_OK_REQ_T;


/*2009-3-5 AC2.0 �޸�*/
/* ���ɾ�������ṹ��*/
typedef struct
{
	UINT32	ulLbUserNumSwitch;	/* �û������⿪�ؿ���0������	1������ */
	UINT32	ulUserNumPermitted;	/* �û��� ������������*/
	UINT32	ulUserNumOffsetThreshold;		/* �û���Ŀ��ֵ*/
	UINT32	ulUserNumDynamic;				/* �û�����̬���ɾ���*/
	UINT32	ulLbUserQosSwitch;	/* 0������	1������ */
	UINT32 	ulBandMax;          	/* ���QOS���������д��� */
	UINT32	ulUserQosOffsetThreshold;		/* �û�QOS��ֵ*/
	UINT32 	ulChaUtiSwitch ;		/*�����ŵ������ʵĸ��ɾ��⿪�أ�0��OFF��1��ON*/
	UINT32 	ulChaUtiMax ;		/*������������ŵ�������*/
} AC_DEVM_LOADBALANCE_CONFIG_T;

/* 3A����������*/
typedef struct
{
    UINT8   aucIp[4];
    UINT32  ulPort;
    CHAR    acSecret[32];
} AC_DEVM_RADIUS_SERVER_T;

typedef struct
{
    /* ��Ȩ���������� */
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;
    /* �Ʒѷ��������� */
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
    UINT32    ulRetryPrimaryInterval;   /* ���÷������������ */
    UINT32    ulAcctInterimInterval;    /* �Ʒ���Ϣ�ϱ���� */
    UINT32	ulAuthEchoInterval;		/* ����ʱ�� */
    UINT32	acIsIncludeSuffix;	/* radius�Ƿ��û����Ƿ������׺����*/
} AC_DEVM_RADIUS_SERVERS_T;

typedef struct
{
	/* ��Ȩ���������� */
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;

    UINT32    ulRetryPrimaryInterval;   /* ���÷������������ */
    UINT32    ulAcctInterimInterval;    /* �Ʒ���Ϣ�ϱ���� */
    UINT32	ulAuthEchoInterval;		/* ����ʱ�� */
}AC_DEVM_RADIUS_AUTHSERVERS_T;

typedef struct
{
	/* �Ʒѷ��������� */
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
    UINT32    ulRetryPrimaryInterval;   /* ���÷������������ */
    UINT32    ulAcctInterimInterval;    /* �Ʒ���Ϣ�ϱ���� */
    UINT32	ulAuthEchoInterval;		/* ����ʱ�� */
}AC_DEVM_RADIUS_ACCTSERVERS_T;


/* AC�豸��һ��IP��ַ����*/
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

/* AC��������*/
typedef struct 
{
    	UINT32  ulAcId;     			/* AC ID */
    	
    	CHAR	acAcNEId[32];		/* �豸��Ԫ����*/
	CHAR	acDomainName[64];	/*	AC������*/
	CHAR	acContact[64];		/* �豸ά����ϵ��*/
	CHAR	acLocation[64];		/* �豸����λ��*/
	
	UINT32	ulMaxWtpNum;		/* �����������WTP��*/
	UINT32	ulMaxStaSwitch;		/* 2010-7-20 ����: ����û������� 0:���� 1:����*/
	UINT32	ulMaxStaNum;		/* ������������û���*/
	UINT32	ulMaxPortalStaNum;	/*	�����������Portal�û���	*/
	UINT32	ulMaxPPPoEStaNum;	/*	�����������PPPoE�û���	*/
	
	UINT32	ulHeartbeatPeriod;	/* ��������*/
	UINT32	ulStatisticsTime;		/* ����ͳ��ͳ��ʱ��	>0	60	��λ����*/
	UINT32	ulSampleTime;		/* ����ͳ�Ƴ���ʱ��	>0	10	��λ����*/

	UINT32	 ulAllAPMonitorMode;		 /* AP���߼���ģʽ */
	/* AC�豸��һ��IP��ַ*/
    	AC_DEVM_ACFIRSTIP_CONFIG_T	stAcIp;
} AC_DEVM_ACBASIC_CONFIG_T;

/* AC �豸ϵͳ����*/
typedef struct 
{
    	AC_DEVM_ACBASIC_CONFIG_T	stAcBasic ;
	AC_DEVM_RADIUS_SERVERS_T	stAAAServers;
} AC_DEVM_AC_OWNCONFIG_T;

/* AC֧�ֵ�AP����汾�б�����*/
typedef struct
{
	CHAR	acDftApSwVersion[32];		/* ȱʡAP����汾*/
	
	CHAR	acSwVersion1[32];			/* AP����汾1 */
	CHAR	acSwVersion2[32];			/* AP����汾2 */
	CHAR	acSwVersion3[32];			/* AP����汾3 */
	CHAR	acSwVersion4[32];			/* AP����汾4 */
	CHAR	acSwVersion5[32];			/* AP����汾5 */
	CHAR	acSwVersion6[32];			/* AP����汾6 */
	CHAR	acSwVersion7[32];			/* AP����汾7 */
	CHAR	acSwVersion8[32];			/* AP����汾8 */
	CHAR	acSwVersion9[32];			/* AP����汾9 */
	CHAR	acSwVersion10[32];			/* AP����汾10 */
	CHAR	acSwVersion11[32];			/* AP����汾11 */
	CHAR	acSwVersion12[32];			/* AP����汾12 */
	CHAR	acSwVersion13[32];			/* AP����汾13 */
	CHAR	acSwVersion14[32];			/* AP����汾14 */
	CHAR	acSwVersion15[32];			/* AP����汾15 */
	CHAR	acSwVersion16[32];			/* AP����汾16 */
	
} AC_DEVM_ASSOCSWVERSETUP_CONFIG_T;

/* ����汾����*/
typedef struct
{
	UINT8	aucFtpServerIpAddr[4];
	UINT32	ulFtpServerPort;
	CHAR	acFtpUserName[32];
	CHAR	acFtpPassword[32];
	CHAR	acSwFileName[128];
	CHAR	acSpecificSwVersion[32];
	UINT32	ulUpgradeStrategy;
	UINT32	ulActivationPolicy;	/* ��Ч��ʽ*/
	UINT32	ulActivationTime;
} AC_DEVM_SWSVR_CONFIG_T;

/*	WEB��֤ȫ������*/
typedef struct
{
	UINT32	ulPortalEnable;		/* ǿ��WEB��֤0/1 ����/����*/
	UINT8	aucPortalIp[4];
	CHAR	acPortalURL[64];
	UINT32	ulPortalPort;
	CHAR	acDomainName[64];
	UINT32	ulConcurrentAuthMaxNum;
	UINT32	ulReauthTimeout;
} AC_DEVM_PORTAL_CONFIG_T;

/*	Portal����������AC_DEVM_WHITELIST_CONFIG_T */
typedef struct
{
	UINT32	ulWhiteId;
	UINT8	aucWhiteIp[4];
	UINT8	aucWhiteIpMask[4];
	UINT16	usWhiteProto;
	UINT16	usWhitePort;
} AC_DEVM_WHITELIST_CONFIG_T;

/* �û�����ַ������*/
typedef struct {
	CHAR	acUserName[64];		/*	�û���	*/
	UINT8	aucUserIp[4];		/*	�û�IP��ַ	*/
	UINT8	aucUserMac[6];		/*	�û�MAC��ַ	*/
	UINT8	aucRsv[2];			/*	reserve	*/
} AC_DEVM_USERADDRBIND_CONFIG_T;

/* ����֤IP��ַ�б�����*/
typedef struct {
	UINT8	aucUserIp[4];	/*	�û�IP��ַ	*/
	UINT8	aucMask[4];		/* ����*/
} AC_DEVM_FREEADDR_CONFIG_T;

/* ����֤MAC����*/
typedef struct {
	UINT8	aucMac[6];	/* MAC��ַ*/
	UINT8	aucRsv[2];
} AC_DEVM_FREEMAC_CONFIG_T;

/* ����֤SSID�б�*/
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

/* ����֤VLAN�б�*/
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

/* ������URL����*/
typedef struct
{
	UINT32	ulWhiteId;			/*	������ID */
	UINT8	aucWhiteUrl[64];		/* ������URL */
}AC_DEVM_WHITEURL_CONFIG_T;

/* AC ������·����������*/
typedef struct
{
	UINT32	ulKeepSwitch;		/*�Ƿ�����0������	1������ */
	UINT8	aucKeeperIp0[4];		/* ���IP��ַ1*/
	UINT8	aucKeeperIp1[4];		/* ���IP��ַ2*/
	UINT32	ulKeepInterval;		/* ����� */
	UINT32	ulKeepCount;			/* ��ʱ���� */
	UINT32	ulToStandby;			/* 2011-6-21 pyy: AC���������޸� �Ƿ��л���standby״̬*/
} AC_DEVM_ACKEEPER_CONFIG_T;

/* WTP �豸��������*/
typedef struct
{
    AC_WTPID_T  stWtpId;            	/* WTP�豸ID */
    CHAR        acWtpName[64];      	/* WTP�豸���� */
    UINT32	ulDeviceType;
    UINT8		aucDeviceId[6];		/* �豸ID: ���к�*/
    UINT8		aucRsv[2];			/* ����ֽ�*/
    CHAR		acWtpNEId[32];		/* AP ��Ԫ����*/
    UINT32	ulRunMode;			/* AP ҵ��ת��ģʽ: 1:����ת��/2:����ת��*/
} AC_DEVM_WTPBASIC_CONFIG_T;

/* WTP�豸IP���÷�ʽ*/
#define AC_DEVM_WTPIPORIGIN_STATIC			1	/* ��̬����*/
#define AC_DEVM_WTPIPORIGIN_DHCP				2	/* DHCP ��̬����*/
#define AC_DEVM_WTPIPORIGIN_AC				3	/* AC��̬����*/

typedef struct
{
	UINT8	aucIp[4];           		/* WTP IP */
	UINT8	aucNetMask[4];			/* ���� */
	UINT8	aucDefaultGw[4];
	UINT8	aucPrimaryDns[4];	/*	��DNS������	*/
	UINT8	aucSecondaryDns[4];	/*	��DNS������	*/
} AC_DEVM_WTPIP_CONFIG_T;

/* add by gwx 2013-4-7 for task 668 */
typedef struct
{
	BYTE	global_ip[4];           		/* WTP global IP */ 
	UINT16	global_srcport;           		/* WTP global src port */ 
	UINT16  resv;
} AC_DEVM_NAT_IP_CONFIG_T;
/* WTP CAPWAP ����*/
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

/*	WTP��������AC_DEVM_WTPASSO_CONFIG_T */
/* AP������֤��ʽ*/
enum {
	AC_WTP_AUTH_MANNER_SECRET	= 0,
	AC_WTP_AUTH_MANNER_SN		= 1,
} AC_WTP_AUTH_MANNER_E;

typedef struct
{
	AC_WTPID_T  stWtpId;            	/* WTP�豸ID */	
	UINT32		ulAssociatePrio;
	UINT32		ulWtpAuthManner;
	CHAR		acSecret[32]	;
	UINT8		aucWtpSn[6];
	UINT8		aucResv[2];
	/* add by gwx 2012-2-2 for ap������ϢΪ�豸�ͺŲ�һ�£���SN�Ƿ�*/
	UINT8   		aucWtpMac[6];
    	UINT8   		aucResv1[2];
		
	UINT32  		ulEchoInterval;
	UINT32  		ulMaxRetransmit;
} AC_DEVM_WTPASSO_CONFIG_T;

/* WTP �豸����*/
typedef struct
{
	AC_DEVM_WTPBASIC_CONFIG_T	stWtpBasic;
	AC_DEVM_WTPIP_CONFIG_T		stWtpIp ;
	AC_DEVM_WTPCAPWAP_CONFIG_T	stWtpCapwap ;
	AC_DEVM_LOADBALANCE_CONFIG_T	stLBCfg;	/* ���ɾ������ */
} AC_DEVM_WTP_CONFIG_T;

typedef struct
{
    UINT32    ulWifiModuleNum;
    UINT32    aulWifiModuleIdList[4];
} AC_DEVM_VDEV_WIFILIST_T;

/* �����豸�ṹ�嶨�� */
enum{
         AC_VDEV_TYPE_AP_ALONE,                   	/*�����Ľ����豸*/
         AC_VDEV_TYPE_AP_BIND,             		/*����Ľ����豸*/
         AC_VDEV_TYPE_ADHOC_ALONE,         	/*�����Ļش��豸*/
         AC_VDEV_TYPE_ADHOC_BIND,    			/*����Ļش��豸*/
         AC_VDEV_TYPE_AP_ADHOC,                 	/*����ӻش��豸*/
         AC_VDEV_TYPE_STA_ADHOC,               	/*�ն˼ӻش��豸*/
         AC_VDEV_TYPE_STA_ALONE,                	/*�������ն��豸*/
         AC_VDEV_TYPE_STA_BIND            		/*������ն��豸*/
} AC_VDEV_TYPE_E ;

//�����豸��������
typedef struct
{
	/* ��������*/
	UINT32	ulVdevType;
   
} AC_DEVM_VDEVBASIC_CONFIG_T;

// �����豸�ŵ�����AC_DEVM_VEDV_CHANNEL_CONFIG_T
enum{
	AC_CHANNEL_TYPE_STATIC 	= 0,
	AC_CHANNEL_TYPE_DYNAMIC  = 1
}AC_CHANNEL_TYPE_E ;

typedef struct
{ 
 /* �ŵ�����*/
	UINT32	ulAbgMode;		/* A/B/G ģʽ*/
	UINT32	ulTurboMode;	/* Truboģʽ*/
	UINT32	ulChannelMode;	/* �ŵ�ģʽ*/
	UINT32	ulChannelType;	/* �����ŵ�: ��̬/����Ӧ*/
	UINT32	ulChannel;		/* �����ŵ�*/

} AC_DEVM_VDEVCHANNEL_CONFIG_T;

//	�����豸��������AC_DEVM_VEDV_RATE_CONFIG_T
typedef struct
{
	/* ������������*/
	UINT32	ulMaxTxRate;	/* ���������*/
	UINT32	ulMgmTrate;		/* ��ѡ����֡��������*/
	UINT32	ulMcasTrate;	/*	��ѡ�㲥��������*/
	UINT32	ulMgmtRetrys;	/* 	����֡�ش�����*/

} AC_DEVM_VDEVRATE_CONFIG_T;

//�����豸��������AC_DEVM_VEDV_POWER_CONFIG_T
typedef struct
{
	/* ���߹�������*/
	UINT32	ulLimitTxPower;	/* ����书��*/
	UINT32	ulMaxTxPower;	/* ���书������*/
} AC_DEVM_VDEVPOWER_CONFIG_T;

//	�����豸�߼�����AC_DEVM_VDEV_ADVANCED_CONFIG_T
typedef struct
{
	/* �߼����� */
	UINT32    ulBeaconInt;			/* BEACON���*/
 	UINT32    ulDtimInt;			/* DTIM���*/
 	UINT32    ulPreamble;			/* ǰ������*/
	UINT32    ulFragmThreshold;	/* ��Ƭ����*/
	UINT32    ulRtsThreshold;		/* RTS ����*/
	UINT32	ulLongRtsThreshold;	/* ��֡�ش�����*/
	UINT32	ulShortRtsThreshold;	/* ��֡�ش�����*/
	UINT32	ulCacheTime;		/*	�������ݰ�������*/

	UINT32    ulCtsProtectionType;	/* CTS����ģʽ*/
	UINT32	 ulTxDistOptSwitch;	/* �������뿪��*/
	UINT32	 ulMaxTxDistance;	/* ��������*/
	
} AC_DEVM_VDEVADVANCED_CONFIG_T;

/* �����豸WIDS */
typedef struct 
{

	/* �����ն�*/
	UINT32	ulDosAttackDetectSwitch;
	UINT32	ulDosAttackPeriod;		/*	���鹥��ͳ������		>0	60	��*/
	UINT32	ulDosAttackThreshold;	/*	���鹥���ж�����		>0	30	*/

	UINT32	ulDosAttackDefenseSwitch;
	UINT32	ulInvalidTerminalAgeingTime;

	UINT32	ulSpoofAttackDetectSwitch;	/* Spoof������⿪��*/
	UINT32	ulWeekIVAttackDetectSwitch;	/* Week IV��⿪��*/
 	UINT32	ulStaDisturbDetectSwitch;		/* �ն˸��ż�⿪��*/
	UINT32	ulStaDisturbLimit;			/* �ն˸������ޣ�������:pps��*/

	/* 2010-07-01 fengjing cmcc test */
    UINT32  ulAPInterfNumThreshhd;      /* AP���Ÿ澯���� */
	UINT32  ulStaInterfNumThreshhd;     /* �ն˸��Ÿ澯����*/
    INT32   lAPCoInterfThreshhd;        /* APͬƵ���Ÿ澯����*/
    INT32   lAPNeiborInterfThreshhd;    /* AP��Ƶ���Ÿ澯����*/
	
	UINT32	ulMacNum;					/* �Ϸ��ն�MAC��Ŀ*/
	UINT8 	aaucMac[16][8];				/* �Ϸ��ն�MAC�б�*/

	/* ����AP */
	UINT32	ulInvalidApDetectSwitch;		/* ����AP���*/
	
	UINT32	ulSsidNum;					/* �Ϸ�AP SSID��Ŀ*/
 	UINT8	aaucSsid[16][32];				/* �Ϸ� AP SSID�б�*/ 
	UINT32	ulBssidNum;					/* �Ϸ� AP BSSID��Ŀ*/
 	UINT8	aaucBssid[16][8];			 /*�Ϸ�AP BSSID�б�*/ 
	UINT32	ulListOuiNum;				/* �Ϸ�AP OUI��Ŀ*/
 	UINT8	aaucOui[16][4];				/*�Ϸ�AP OUI�б�*/
} AC_DEVM_VDEVWIDS_CONFIG_T;

/* �����豸������Դ����*/
/*����*/

enum{
	AC_RRM_OVERSTEP_REPORTALARM = 1,
	AC_RRM_OVERSTEP_REELECTCHANNEL = 2
}AC_RRM_OVERSTEP_E ;

typedef struct 
{
	UINT32	ulMoniMode;					/* ���߻������ģʽ 
										1���ṩWLAN�������
										2���������߻���
										3������ʱ�������߻���
										*/
										
	/* ��Ƶɨ�� */
	UINT32	aulDiffScanChannelList[16] ;		/*��Ƶɨ��Ƶ���б�*/
	UINT32	ulDiffScanInterval ;			/*��Ƶɨ������*/
	UINT32	ulDiffScanResidenceTime ;		/*��Ƶɨ��Ƶ��פ��ʱ��*/

	/* ͬƵɨ�� */
	UINT32	ulSameScanInterval ;			/* ͬƵɨ������ */
	UINT32	ulNeighAutoScanSwitch;	/*	�����ھ��Զ�ɨ��	*/
	UINT32	ulNeighRssiMin;			/*	�ھ��ź�ǿ����С����	*/
	UINT32	ulNeighRssiWave;		/*	�ھ��ź�ǿ�Ȳ�����Χ	*/
	
	/*Ƶ����*/
	UINT32	ulChannelPeriod ;	/*�ŵ���ѡ����, ��λ: ����*/
	UINT32	ulRssiThreshold ;				/*Ƶ����������RSSI*/
	INT32	lNoiseThreshold ;			/*Ƶ���������޵���*/
	/* UINT32	ulOverstepManner ;*/			/*Ƶ�����������޴�ʩ*/

	/* ���ʶ�̬��������1 */
	UINT32	ulInterfereDetectSwitch ;		/*���ż�⿪��*/
	UINT32	ulInterfereDetectPeriod ;		/* ���ʵ������� */
	
	UINT32	ulMaxInterferePermitted ;		/* ���ʵ���Ŀ��RSSI */
	UINT32	ulRssiWaveRange ;			/* Ŀ��RSSI������Χ */
	/* UINT32	ulCompensatingFactor ;	*/	/*��������*/

	UINT32			ulPowerCompensationSwitch ;		/* �ṩ���ʲ������� */
} AC_DEVM_VDEVRRM_CONFIG_T;

typedef struct
{
	UINT32    ulWtpId;
    	UINT32    ulVDevId;
    	UINT32	ulMaxPower;	/* ����书��*/
} AC_DEVM_VDEV_MAXPOWER_T;


/* �����豸����*/
typedef struct
{
	/* ��ʶ��Ϣ */
   	AC_VDEVID_T    stVdevId;

   	/* ������Ϣ*/
    	AC_DEVM_VDEVBASIC_CONFIG_T		stVdevBasic ;
	AC_DEVM_VDEVCHANNEL_CONFIG_T	stVdevChannel ;
	AC_DEVM_VDEVRATE_CONFIG_T		stVdevRate;
	AC_DEVM_VDEVPOWER_CONFIG_T	stVdevPower;
	AC_DEVM_VDEVADVANCED_CONFIG_T	stVdevAdvanced;

	AC_DEVM_VDEVWIDS_CONFIG_T		stVdevWidsCfg;	/* WIDS���� */
	AC_DEVM_VDEVRRM_CONFIG_T		stVdevRrmCfg ;	/* RRM ���� */
} AC_DEVM_VDEV_CONFIG_T;

/* �ӿ�����*/
typedef struct
{
    	/* ��ʶ��Ϣ */
	AC_IFID_T    stIfId;

   	/* ������Ϣ*/
	AC_DEVM_VDEVCHANNEL_CONFIG_T	stIfChannel ;
	AC_DEVM_VDEVRATE_CONFIG_T		stIfRate;
	AC_DEVM_VDEVPOWER_CONFIG_T	stIfPower;
	AC_DEVM_VDEVADVANCED_CONFIG_T	stIfAdvanced;

	
	AC_DEVM_VDEVWIDS_CONFIG_T		stIfWidsCfg;		/* WIDS���� */
	AC_DEVM_VDEVRRM_CONFIG_T		stIfRrmCfg ;		/* RRM ���� */
} AC_DEVM_IF_CONFIG_T;

/* VAP����*/
enum{
AC_VAP_OPMODE_AP,
AC_VAP_OPMODE_ADHOC,
AC_VAP_OPMODE_STA
}AC_VAP_OPMODE ;

typedef struct
{
    	/* ��ʶ��Ϣ */
    	AC_VAPID_T        stVapId;
    	UINT32	ulOpMode;
    
    	/* �������� */
    	CHAR    acIfName[AC_DEVM_IFNAME_LEN];
    	UINT8   aucBssid[6];        	/* MAC��ַ */
    	UINT8   aucRsv[2];         	/* ����ֽ� */
    	CHAR    acSsid[32];         	/* SSID */
    	UINT32  ulSsidBroadcast;   /* SSID�㲥*/
    	UINT32	ulMaxSimultUsers;	/*	������������û���	*/
	UINT32	ulMaxSimultTraffic;		/*	�������	*/
	
    	/* ��ȫ���� */
    	UINT32  ulAuth;             /* ������֤���� 
                                Bit0��0/1������֧��/֧�ֿ���ʽ                                
                                Bit1��0/1������֧��/֧�ֹ���ʽ  
                                Bit2��0/1������֧��/֧��WPA    
                                Bit3��0/1������֧��/֧��WPA-PSK      
                                Bit4 ��0/1������֧��/֧��MAC��֤
                                Bit5��0/1������֧��/֧��WAI
    					*/
    	UINT32  ulEncrypt;          /* ���ݼ������� 
                                Bit0��0/1������֧��/֧�ֽ���
                                Bit1��0/1������֧��/֧��WEP 
                                Bit2��0/1������֧��/֧��TKIP    
                                Bit3��0/1������֧��/֧��AES      
                                Bit4��0/1������֧��/֧��SMS4
    					*/

	UINT32  ulWapiSetupId;  	/*	WAPIЭ������	*/
	UINT32  ulCertFileId;   	/*	WAPI֤��	*/
	CHAR    acWapiPsk[64];	/*  WAPI PSK����	*/

    	CHAR    acWpaKey[64];       /* WPA��Կ */
    	UINT32  ulWpaRekeyPeriod;   /* WPA��Կ�������� */
    	UINT32  ulWepKeyLen;        /* WEP��Կ���� */
    	UINT32  ulInputFormat;      /* WEP��Կ�����ʽ */
    	CHAR    acWepKey[32];       /* WEP��Կ */
    	UINT32  ulWepKeyIndex;      /* WEP��Կ��� */
    	UINT32  ul8021x;            /*�Ƿ����������IEEE802.1x��֤ */
    	UINT32  ulWepBroadcastKeyLen;   /* ��̬WEP�㲥��Կ����
                                      1: 64 Bit
                                      2: 128 Bit */
    	UINT32  ulWepUnicastKeyLen;     /* ��̬WEP������Կ����
                                      1: 64 Bit
                                      2: 128 Bit */
    	UINT32  ulWepRekeyPeriod;   /* WEP��Կ�������� */
    	UINT32  ulEapolVer;         	/* EAP�汾*/
   	UINT32  ulEapAuthPeriod;    /* EAP��Ȩ����*/

   	/* �߼����� */
	UINT32	ulPrivCap;		/* VLAN���� */
	UINT32	ulPowerCtrl;		/* �Ƿ������ʿ��� */
	UINT32	ulEndUserTime;	/* �û�����ʱ�� */
	UINT32	ulQosType;		/* QoS���� */
	UINT32	ulAcLowLimit;	/* �û��������� */
	UINT32	ulAcUpLimit;		/* �û��������� */
	UINT32	ulAcInterval;		/* �������ʱ�� */
	UINT32	ulTrafficMode;	/* 2010-4-20 pyy����: VAPҵ��ת��ģʽ*/
} AC_DEVM_VAP_CONFIG_T;


/* ADHOC����*/
typedef struct 
{
	/* ��ʶ��Ϣ */
    	AC_ADHOCID_T        stAdhocId;
} AC_DEVM_ADHOC_CONFIG_T;

/* VAP BSSID */
typedef struct
{
    AC_VAPID_T  stVapId;        /* VAP ID */
    UINT8       aucBssid[6];    /* VAP MAC��ַ */
    UINT8       aucRsv[2];      /* ����ֽ� */
} AC_DEVM_VAP_BSSID_T;

/* ADHOC BSSID */
typedef struct 
{
	AC_ADHOCID_T	stAdhocId;
	UINT8	aucBssid[6];
	UINT8	aucRsv[2];
} AC_DEVM_ADHOC_BSSID_T;


/* VAP ����ͳ��*/
typedef struct 
{
	AC_VAPID_T  stVapId;        /* VAP ID */
	UINT32	ulUpTraffic;
	UINT32	ulDownTraffic;
} AC_DEVM_VAP_TRAFFICSTAT_T;

/* SNMP V2 ����*/
typedef struct 
{
	UINT32	ulCommunityId;		/* ��ͬ��ID */
	CHAR	acReadCommunity[32];		/* ��ͬ�� */
	CHAR	acWriteCommunity[32];		/* ��ͬ�� */
	UINT32	ulRfc1213Flag;		/* RFC1213��׼MIB����Ȩ�� */
	UINT32	ulRfc1573Flag;		/* RFC1573��׼MIB����Ȩ�� */
	UINT32	ulRfc1643Flag;		/* RFC1643��׼MIB����Ȩ�� */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE��׼MIB����Ȩ�� */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot��׼MIB����Ȩ�� */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI��׼MIB����Ȩ�� */
	UINT32	ulPrivateFlag;		/* ˽��MIB����Ȩ�� */
} AC_DEVM_SNMPV2_CONFIG_T;

/* SNMP V3���� */
typedef struct 
{
	UINT32	ulUserId;			/* �û�ID */
	CHAR	acUserName [32];	/* �û��� */
	UINT32	ulAuthProtocol;		/* ��ȨЭ�� */
	CHAR	acAuthKey[32];		/* ��Ȩ��Կ */
	UINT32	ulPrivProtocol;		/* ����Э�� */
	CHAR	acPrivKey[32];		/* ������Կ */
	UINT32	ulRfc1213Flag;		/* RFC1213��׼MIB����Ȩ�� */
	UINT32	ulRfc1573Flag;		/* RFC1573��׼MIB����Ȩ�� */
	UINT32	ulRfc1643Flag;		/* RFC1643��׼MIB����Ȩ�� */
	UINT32	ulIeee8021PAEFlag;	/* Ieee8021PAE��׼MIB����Ȩ�� */
	UINT32	ulIeee8021dot11Flag;	/* Ieee8021dot��׼MIB����Ȩ�� */
	UINT32	ulGb15629dot11WapiFlag;	/* GB15629dot11-WAPI��׼MIB����Ȩ�� */
	UINT32	ulPrivateFlag;		/* ˽��MIB����Ȩ�� */
} AC_DEVM_SNMPV3_CONFIG_T;

/* 	SNMP TRAP����AC_DEVM_SNMPTRAP_CONFIG_T */
typedef struct 
{
	UINT32	ulTrapSvrId;		/*	TRAP������ID */
	UINT8	aucTrapIp[4];	/*	TRAP��������ַ */
	UINT32	ulTrapPort;		/*  TRAP�������˿� */
} AC_DEVM_SNMPTRAP_CONFIG_T;


/* SNTP������ȫ������*/
typedef struct 
{
	UINT32	ulSntpSwitch;	/* ����SNTP���������� */
	UINT32	ulUpdatePeriod;	/* ʱ���������*/
	UINT8	aucUpperSntpSvr1[4];	/*	�ϼ�SNTP������1	*/
	UINT8	aucUpperSntpSvr2[4];	/*	�ϼ�SNTP������2	*/
	UINT8	aucUpperSntpSvr3[4];	/*	�ϼ�SNTP������3	*/
	UINT8	aucUpperSntpSvr4[4];	/*	�ϼ�SNTP������4	*/
} AC_DEVM_ACSNTP_CONFIG_T;

/*	WTP SNTP����AC_DEVM_WTPSNTP_CONFIG_T*/
typedef struct 
{
	UINT32	ulEnableSntp;		/* ����SNTP�ͻ��˹��� */
	UINT8	aucSntpServrIp[4];	/* SNTP������IP */
	UINT32	ulPeriod;			/* ʱ��ͬ������ */
} AC_DEVM_WTPSNTP_CONFIG_T;

/* add by gwx 2013-4-7 for task668 */
typedef struct{
	UINT32	ulWtpId;  
	UINT32	dwCommPort;		/* ͨ�Ŷ˿ں�*/
	UINT8	tCommAddr[4];		/* ͨ��IP��ַ*/
}AC_DEVM_WTP_SETSRCADDR_IND_MSG_T;
/* 	��־���� : MIB�Ķ���*/
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

/* 	��־���� : SYSLOG��ӡ�����ʵ��*/
enum{
	AC_LOG_LEVEL_SOFT_OFF 		= 0,
	AC_LOG_LEVEL_SOFT_FATAL 		= 1,
	AC_LOG_LEVEL_SOFT_ERROR 		= 2,
	AC_LOG_LEVEL_SOFT_WARNING	= 3,
	AC_LOG_LEVEL_SOFT_MSG 		= 4,
	AC_LOG_LEVEL_SOFT_DETAIL 		= 5,
}AC_LOG_LEVEL_SOFT_E ;

/* ��־ģ��*/
/* powerac���ģ�� */
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
#define LM_OPERATION     17     /*������־�����������������*/
#define LM_BUSINESS       18     /*ҵ��������־���������������*/
#define LM_ALERT          19     /*�澯��־���������������*/
#define LM_EVENT          20    /*�¼���־���������������*/ 
#define LM_SECURITY       21    /*��ȫ��־���������������*/ 
/* AC��Χ���̡��ں�ģ��     24 - 47 */
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

/* AP��Χ���̡��ں�ģ��     48 - 63 */
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
	UINT8	aucLogModule[64];	/*	ģ�鿪��	*/
	UINT32	ulLogToStdOut;		/*	�Ƿ��ӡ����׼���	*/
	UINT32	ulLogSvrNum;		/* Զ����־��������Ŀ*/
	UINT8	aaucLogSvrIp[4][4];	/*	��־������IP��ַ	*/
	UINT32	aulLogSvrPort[4];	/*	��־�������˿ں�	*/
	UINT32	ulLogTransType;		/*	��־��������	*/	
} AC_DEVM_LOG_CONFIG_T;

/*	��־����������AC_DEVM_LOGSVR_CONFIG_T*/
typedef struct 
{
	UINT32  ulLogSvrSwitch;   		/*  ��־����������	      */
	UINT8   aucLogSvrIp[4];   		/*  ��־��������IP��ַ    */
	UINT32  ulLogSvrPort;   		/*  ��־�������󶨶˿�	  */
	UINT32  ulLogBakDay;   		/*  ��־��������	      */
	UINT32  ulLogFileSize;   		/*  ��־�ļ���С	      */
	UINT32  ulLogCompress;   		/*  �Ƿ�ѹ��	          */
} AC_DEVM_LOGSVR_CONFIG_T;

/*AC�˿�������AC_DEVM_BRIDGE_CONFIG_T*/
enum {
	AC_BRIDGE_TYPE_FTTLAN		= 0,
	AC_BRIDGE_TYPE_FATLAN		= 1,
	AC_BRIDGE_TYPE_L2WAN		= 2,
	AC_BRIDGE_TYPE_L3WAN		= 3,
	AC_BRIDGE_TYPE_MS			= 4,
} AC_BRIDGE_TYPE_E;

typedef struct 
{
	UINT32		ulBridgeId;   			/* �˿���ID	        */
	UINT32   		ulBridgeType;   			/* �˿�����	        */
	CHAR   		acBridgeName[32];   		/* �˿�������	    */    
	UINT32		ulIpNum;
	UINT8		aaucIp[40][4];
	UINT8		aaucMask[40][4];
} AC_DEVM_BRIDGE_CONFIG_T;

/* AC LAN�˿�������AC_DEVM_LANIF_CONFIG_T*/
typedef struct 
{
	UINT32	ulIfId;
	CHAR	acIfName[32];
} AC_DEVM_LANIF_CONFIG_T;

/* AC����˿�����*/
typedef struct 
{
	UINT32	ulIfId;	/* �˿ں� */
	UINT32	ulPortType;
	CHAR	acIfName[32];	/* �˿����� */
	UINT32	ulRunMode;		/* �Ƿ����� */
	UINT32	ulSpeedUplex;	/* ����/˫��ģʽ */
	UINT32	ulMtu;
	UINT32	ulVlanType;		/* VLAN ����*/
	UINT32	ulCapVlanId;		/* ��װVLAN ID */
} AC_DEVM_ACPORT_CONFIG_T;

/* �˿�IP��ַ����*/
typedef struct 
{
	UINT32	ulFitLanIpNum;											/* FIT-LAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucFitLanIp[AC_BRIDGE_FITLAN_IPNUM_MAX][4];				/* FIT-LAN IP��ַ*/
	UINT8	aaucFitLanNetMask[AC_BRIDGE_FITLAN_IPNUM_MAX][4];		/* FIT-LAN IP��������*/

	UINT32	ulFatLanIpNum;											/* FAT-LAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucFatLanIp[AC_BRIDGE_FATLAN_IPNUM_MAX][4];			/* FAT-LAN IP��ַ*/
	UINT8	aaucFatLanNetMask[AC_BRIDGE_FATLAN_IPNUM_MAX][4];		/* FAT-LAN IP��������*/

	UINT32	ulL2WanIpNum;											/* L2-WAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucL2WanIp[AC_BRIDGE_L2WAN_IPNUM_MAX][4];				/* L2-WAN IP��ַ*/
	UINT8	aaucL2WanNetMask[AC_BRIDGE_L2WAN_IPNUM_MAX][4];		/* L2-WAN IP��������*/

	UINT32	ulL3WanIpNum;											/* L3-WAN�˿ڵ�IP��ַ��Ŀ*/
	UINT8	aaucL3WanIp[AC_BRIDGE_L3WAN_IPNUM_MAX][4];				/* L3-WAN IP��ַ*/
	UINT8	aaucL3WanNetMask[AC_BRIDGE_L3WAN_IPNUM_MAX][4];		/* L3-WAN IP��������*/

	UINT8	aucDefaultGw[4];					/* ȱʡ����*/
	UINT8	aucPrimaryDns[4];				/* ����DNS������*/
	UINT8	aucSecondaryDns[4];				/* ����DNS������*/
} AC_DEVM_ACIP_CONFIG_T;

/* WTP����˿�����*/
enum {
	AC_WTP_ENET_STATE_UPLINK= 0,			/* ������*/
	AC_WTP_ENET_STATE_DOWNLINK = 1,		/* ������*/
} AC_WTP_ENET_STATE_E;

typedef struct 
{
	AC_ENETID_T	stEnetId;	/* ��������˿��б�*/
	UINT32	ulEnetState;		/* ��������˿ڵ�״̬*/
} AC_DEVM_ENET_CONFIG_T;

/* VLANȫ������*/
typedef struct 
{
	UINT32	ulRoamSwitch;			/* VLAN ���ο���*/
	UINT32	ulTime;					/* VLAN�����ϻ�ʱ��*/
}AC_DEVM_VLANGLOBAL_CONFIG_T;

/* VLAN��������*/
typedef struct 
{
	UINT32	ulVlanId;				/* VLAN ID */
	CHAR	acVlanName[32];			/* VLAN����*/
	UINT32	ulVlanEnable;	/* add by gwx 2014-7-11 for dlink, vlan ����*/
	UINT32	ulVlanForFitLan;			/*	FIT-LAN�˿�������	*/
	UINT32	ulVlanForFatLan;			/*	FAT-LAN�˿�������	*/
	UINT32	ulVlanForL2Wan;			/*	L2-WAN�˿�������	*/
	UINT32	ulVlanForL3Wan;			/*	L3-WAN�˿�������	*/
	UINT32	ulEnableIsolate;			/* �û����� */
	UINT32	ulVlanPrio;				/* VLAN���ȼ�*/
	CHAR	acNasId[32];				/* �ȵ�NasId */
} AC_DEVM_VLAN_CONFIG_T;

/* SSID-VLANӳ������*/
typedef struct 
{
	CHAR	acSsid[32];				/* SSID */
	UINT32	ulVlanId;				/* VLAN ID */
} AC_DEVM_VLANSSIDMAP_CONFIG_T;

/* �˿�-VLANӳ������*/
typedef struct 
{
	UINT32	ulDevId;			/* �豸ID */
	UINT32	ulIfId;			/* �˿�ID */
	UINT32	ulVlanId;		/* VLAN ID */
	UINT32	ulIfType;		/* �˿�����*/	
	CHAR	acIfName[32];	/* �˿�����*/
	UINT32	ulNestVlanId;		/* add by gwx 2014-7-11 ,qinq ���vlan  */
	UINT32	ulVlanIfType;	/* VLAN�˿�����*/
} AC_DEVM_VLANIFMAP_CONFIG_T;

/* MAC-VLANӳ������*/
typedef struct 
{
	UINT8	aucMac[6];			/* MAC��ַ */
	UINT8	aucRsv[2];			/* ����ֶ� */
	UINT32	ulVlanId;				/* VLAN ID */
} AC_DEVM_VLANMACMAP_CONFIG_T;

/*	VLAN MAC��ַ���˲���AC_DEVM_VLANACCMACPOLICY_CONFIG_T*/
typedef struct 
{
	UINT32	ulVlanId ;
	UINT32 ulMacFilterSwitch;   /*	MAC���˹��ܿ���	0���ر� 1���� */
	UINT32 ulMacFilterType;	    	/* MAC��������	0�������� 1�������� */
} AC_DEVM_VLANACCMACPOLICY_CONFIG_T;

/* VLAN MAC��ַ�����б�����*/
typedef struct 
{
	UINT32	ulVlanId;			/* VLAN ID */
	UINT8	aucMac[6];			/* MAC��ַ */
	UINT8	aucRsv[2];			/* ����ֶ� */
} AC_DEVM_VLANACCMAC_CONFIG_T;

/* IGMP Snooping����*/
typedef struct 
{
	UINT32	ulIgmpSnoopSwitch;			/* �Ƿ���Ч */
	UINT32	ulRtPortTimer;				/* ·�����˿��ϻ���ʱ�� */
	UINT32	ulMemberPortTimer;			/* ��Ա�˿��ϻ���ʱ�� */
} AC_DEVM_IGMPSNOOP_CONFIG_T;

/* IGMP Proxy����*/
typedef struct 
{
	UINT32	ulIgmpProxy;			/* �Ƿ���Ч */
} AC_DEVM_IGMPPROXY_CONFIG_T;

/* ��̬·������*/
typedef struct 
{
	UINT32	ulRouteId;
	
	UINT8	aucDestIp[4];	/* Ŀ��IP���� */
	UINT8	aucMask[4];		/* ����*/
	UINT8	aucGw[4];		/* ���� */
} AC_DEVM_ROUTESTATIC_CONFIG_T;

/* RIPȫ������ */
typedef struct 
{
	UINT32	ulRipSwitch ;				/* �Ƿ�����RIPЭ�� */
	UINT32	ulIfType;				/*	����ģʽ		0����1����*/
	UINT32	ulAuthType;				/*	��Ȩģʽ		0�������ü�Ȩ
															1��text����ģʽ
															2��MD5ģʽ
															*/
	CHAR	acKey[72];				/*	��Կ*/
	UINT32	ulSendVersion;			/*	���Ͱ汾��
									0��V1/V2ģʽ����
									1��V1ģʽ����
									2��V2ģʽ����*/
	UINT32	ulRecvVersion;			/*	���հ汾��
									0��V1/V2ģʽ����
									1��V1ģʽ����
									2��V2ģʽ����
									*/

	UINT32	ulSplitHorizonOn ;		/* �Ƿ�����ˮƽ�ָ� */
	UINT32	ulRedistributeStatic ; 	/* �Ƿ��طַ���̬·�� */
	UINT32	ulRedistributeKernal ;	/* �Ƿ��طַ�����·�� */
	UINT32	ulUpdate ;				/* Update��ʱ�� */
	UINT32	ulTimeout ; 				/* Timeout��ʱ�� */
	UINT32	ulGarbage ; 				/* Garbage��ʱ�� */
} AC_DEVM_RIPGLOBAL_CONFIG_T;

/* 	RIPͨ����������*/
typedef struct 
{
	UINT8	aucNetIp[4];		/* IP���� */
	UINT8	aucMask[4];		/* ����*/
} AC_DEVM_RIPNOTIFYNET_CONFIG_T;


/* 	����ǽȫ������*/
typedef struct 
{
	UINT32	ulFwSwitch;				/* ACL����: 0���� 1����*/
	UINT32	ulAclDefaultAction;		/* ACLĬ�ϲ���0���� 1����*/

} AC_DEVM_FWGLOBAL_CONFIG_T;

/* 	����ǽ��������*/
typedef struct 
{
	/* ƥ��ԭ��*/
	UINT32		ulRuleId				;	/* �����				*/
	UINT32		ulChildRuleId;			/* ���������*/
	CHAR		acComment[32]		;	/* �Ը÷������Ľ���	*/
	UINT32		ulRuleOn;				/* �����Ƿ�����*/
	UINT32  		ulChainId			;	/* ��������0:�������ʹ��� 1:ת������ */

	UINT32  		ulSrcIpMatchType	;	/* ԴIPƥ����� 0:��ƥ�� 1:����ƥ�� 2:����ƥ��*/
	UINT8		aucSrcIp[4]			;	/* ԴIP��ַ			    */
	UINT8		aucSrcIpMask[4]		;	/* ԴIP��ַ������		*/
	UINT32  		ulDestIpMatchType	;	/* Ŀ��IPƥ����� 0:��ƥ�� 1:����ƥ�� 2:����ƥ��*/
	UINT8		aucDestIp[4]			;	/* Ŀ��IP��ַ			*/
	UINT8		aucDestIpMask[4]		;	/* Ŀ��IP��ַ������	    */

	UINT32		ulIfMatchType;			/* �ӿ�ƥ�����
										0: ��ƥ�� 1:��ӿ�ƥ�� 2:���ӿ�ƥ�� 3:ͬʱƥ��*/
	
	UINT32  		ulInIfId				;	/* ��ӿ�				*/
	UINT32  		ulOutIfId			;	/* ���ӿ�				*/



	UINT32	ulRuleProtocol;	/*	����Э��ƥ��		
								0������Э��     
								1��ICMP   
								2��IGMP  
								6��TCP    
								17��UDP  
								47��GRE  
								94��IPIP  
								115��L2TP
								132��SCTP
								*/

	UINT32	ulSrcPortMatchPolicy;	/*	Դ�˿�ƥ�����		0����ƥ��
								1������ƥ��
								2������ƥ��
								*/
	UINT32	ulSrcPortBegin;		/*	��ʼԴ�˿�		1-65535 */
	UINT32	ulSrcPortEnd;		/*	����Դ�˿�		1-65535 */
	UINT32	ulDstPortMatchPolicy;	/*	Ŀ�Ķ˿�ƥ�����		
									0����ƥ��
									1������ƥ��
									2������ƥ��
									*/
	UINT32	ulDstPortBegin;		/*��ʼĿ�Ķ˿�		1-65535*/
	UINT32	ulDstPortEnd;		/*����Ŀ�Ķ˿�		1-65535*/
	CHAR	acSsid[32];			/* ƥ��SSID */
	CHAR	acUrl[64];			/* ƥ��URL */
	
	UINT32	ulMarkMatch;		/*	ƥ����ֵ	*/

	/*ƥ�䶯��*/
	UINT32	ulAction;		/*	����ִ�еĶ���	
								0������
								1������
								2�����ñ��ֵ
								*/
	UINT32	ulLogSet;		/*	����ִ����־	
								0���ر�
								1����
								*/
	UINT32	ulSetMark;		/*	���ñ��*/
} AC_DEVM_FWRULE_CONFIG_T;

/* 	P2P��������*/
typedef struct 
{
	UINT32	ulP2PSwitch;		/*	P2P����		0������1������*/
	UINT32	ulBtCfg;			/*	BT����		0������1������*/
	UINT32	uleDonkeyCfg;	/*	eDonkey����	0������1������*/
	UINT32	ulAresCfg;		/*	Ares����	 	0������1������*/
	UINT32	ulFasttrackCfg;	/*	Fasttrack����	0������1������*/
	UINT32	ulGnutellaCfg;	/*	Gnutella����	0������1������*/
	UINT32	ulApplejuiceCfg;	/*	Applejuice����	0������1������*/
	UINT32	ulXunleiCfg;		/*	Xunlei����	 	0������1������*/
	UINT32	ulMuteCfg;		/*	Mute����		0������1������*/
	UINT32	ulSoulseak;		/*	Soulseek����	0������1������*/
	UINT32	ulPpliveCfg;		/*	PPLive����		0������1������*/
	UINT32	ulPpstreamCfg;	/*	PPStream����	0������1������*/
	UINT32	ulFreenetCfg;	/*	Freenet����	0������1������*/
	UINT32	ul100baoCfg;	/*	100bao���� 	0������1������*/
	UINT32	ulHotLineCfg;	/*	Hotline����	0������1������*/
	UINT32	ulGoboogyCfg;	/*	Goboogy����	0������1������*/
	UINT32	ulKugooCfg;		/*	Kugoo����		0������1������*/
	UINT32	ulPocoCfg;		/*	Poco����	 	0������1������*/
	UINT32	ulTeslaCfg;		/*	Tesla����		0������1������*/
	UINT32	ulSoribadaCfg;	/*	Soribada����	0������1������*/
	UINT32	ulMsnCfg;		/*	MSN����		0������1������*/
	UINT32	ulQQCfg;		/*	QQ����	 	0������1������*/
	UINT32	ulYahooCfg;		/*	Yahoo Messager����		0������1������*/
	UINT32	ulSkypeCfg;		/*	Skype����	 	0������1������*/
} AC_DEVM_FWL7MATCH_CONFIG_T;

/* NATȫ������*/
typedef struct {
	UINT32	ulNatSwitch;	/*	NAT����		0������1������*/
	UINT32	ulNatDefaultRuleOn;	/*	�Ƿ�����ȱʡNAT����		0������1������*/
}AC_DEVM_NATGLOBAL_CONFIG_T;

/* 	NAT��������*/
typedef struct 
{
	UINT32   ulNatId;                  
	UINT32	ulNatAction;		/*	NAT����
							0-2
							0������NAT
							1���˿�NAT
							2������IP͸��*/
	/* add by gwx 2013-12-10 for task1173 */
	UINT32	ulNatOutIfType;	/*NAT���˿�����0:br0 2:br2*/
							
	UINT8	aucSrcIp[4];			/*	����IP ��ַ		��*/
	UINT8	aucSrcIpMask[4];		/*	����IP����		��*/
	UINT8	aucNatIpBegin[4];	/*	��ʼ����IP��ַ		��*/
	UINT8	aucNatIpEnd[4];		/*	��������IP��ַ		��*/
} AC_DEVM_NAT_CONFIG_T;

/* 	IDS��������*/
typedef struct 
{
	UINT32  ulIcmpFlooding	       ;   /* ICMP�������		*/   
	UINT32  ulIcmpStatInterval;	        /* ICMPͳ�Ƽ��	 */
	UINT32  ulIcmpFloodingThreshold;    /* ICMP��������	*/

	UINT32  ulArpFlooding	        	;   /* ARP������� 		*/   
	UINT32  ulArpStatInterval;  	/* ARPͳ�Ƽ�� */
	UINT32  ulArpFloodingThreshold;	/* ARP�������� */

	UINT32  ulUDPFlooding	        	;   /* Udp�������	    		*/   
	UINT32  ulUDPStatInterval;	        /* UDPͳ�Ƽ��	 */
	UINT32  ulUDPFloodingThreshold;    /* UDP��������	*/

	UINT32  ulTcpSynFlooding	    	;   /* TCPSYN ������� 	*/	
	UINT32  ulTcpSynStatInterval;	        /* TCP SYNͳ�Ƽ��	 */
	UINT32  ulTcpSynFloodingThreshold;    /* TCP SYN ��������	*/

	UINT32  ulDetectUdpScan	    	;   /* UDP ɨ����		*/   
	UINT32  ulDetectTcpScan	    	;   /* TCP ɨ����		*/   
	UINT32  ulDetectInvalidMac	;   /* �Ƿ�MAC���	    	*/   
	UINT32  ulDetectInvalidProto	;   /* �Ƿ�Э����		*/   
	UINT32  ulDetectInvalidLength	;   /* �Ƿ����ĳ��ȼ��	*/	
	UINT32  ulDetectInvalidStatInterval;	/* �Ƿ�����ͳ�Ƽ��	*/
	UINT32  ulDetectInvalidThreshold;	    /* �Ƿ����Ĺ�������	*/
} AC_DEVM_IDSRULE_CONFIG_T;

/* 	IDS��������*/
typedef struct 
{
	UINT32  ulGenEvent	        		;   /* ���ָ澯			*/   
	UINT32  ulDisableAccess	        	;   /* ��ֹ�����߽��� 		*/
	UINT32		ulLetOffPeriod;				/*���ʱ�� */
} AC_DEVM_IDSSTRY_CONFIG_T;

/* 	DHCP for STA ȫ������ */
typedef struct 
{
	UINT32	ulEnableDhcpServer;			/*	DHCP���ܽ�ɫ*/		
	UINT32	ulEnableDhcpSnooping;		/*	����DHCP Snooping����*/
	/* add by gwx 2013-3-12 for task532 */
	UINT32   ulEnableOption60;                    /* ����Option 60����*/
	UINT8	aucDhcpServerMaster[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucDhcpServerSlave[4];		/*	��DHCP�м̷�������ַ*/	
} AC_DEVM_STADHCPGLOBAL_CONFIG_T;

/* 	DHCP for STA ��̬��IP���� */
typedef struct 
{
	CHAR	acDescr[32];				/* ���ڱ�ʶ����*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;
} AC_DEVM_STADHCPSTATICIP_CONFIG_T;

/* 	DHCP for STA ��̬IP��ַ������*/
typedef struct 
{
	UINT32	ulId ;						/* ��ַ�ر�� */
	CHAR    	acIpPoolNAme[32]	    	;   	/* ����                     */
	UINT8   	aucBeginIp[4]	        		;   	/* ��ʼ��ַ                 */
	UINT8   	aucEndIp[4]	            		;   	/* ������ַ                 */
	UINT8   	aucMask[4]	            		;   	/* ����                     */
	UINT8	aucReservedIp1[4];				/* ����IP��ַ1 */
	UINT8	aucReservedIp2[4];				/* ����IP��ַ2 */
	UINT8	aucReservedIp3[4];				/* ����IP��ַ3 */	
	UINT8	aucReservedIp4[4];				/* ����IP��ַ4 */	
	UINT32  	ulLease                 		;   		/* ��Լ���� ��λ����        */
	CHAR    	acDomainName[256]	    	;   		/* ������׺                 */
	UINT8   	aucDnsIpMaster[4]      	;   		/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpMaster[4] 	;   		/* ��������IP��ַ           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpSlave[4]    	;  		/* ��������IP��ַ           */
	/* add by gwx 2013-3-12 for task532 */
	CHAR       acVendorName[64];                        /* ��������Ϣ��Ĭ��Ϊ��*/

	UINT32	ulVlanId1;						/* ��VLAN 1: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId2;						/* ��VLAN 2: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId3;						/* ��VLAN 3: 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId4;						/* ��VLAN 4: 0~4094 0��ʾ����������VLAN */
} AC_DEVM_STADHCPDYNIP_CONFIG_T;

/* 	DHCP for AP ȫ������ */
typedef struct 
{
	UINT32	ulEnableDhcpServer;			/*	DHCP���ܽ�ɫ*/		
	UINT32	ulEnableDhcpSnooping;		/*	����DHCP Snooping����*/
	UINT32	ulEnableOption43;			/*	����Option 43����*/
	/* add by gwx 2013-3-12 for task532 */
	UINT32   ulEnableOption60;                    /* ����Option 60����*/
	UINT8	aucDhcpServerMaster[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucDhcpServerSlave[4];		/*	��DHCP�м̷�������ַ*/
	UINT8	aucAcIpMaster[4];			/*	��AC��ַ*/
	UINT8	aucAcIpSlave[4];				/*	��AC��ַ*/
} AC_DEVM_APDHCPGLOBAL_CONFIG_T;

/* 	DHCP for AP ��̬��IP���� */
typedef struct 
{
	CHAR	acDescr[32];				/* ���ڱ�ʶ����*/
	UINT8	aucMac[6] ;
	UINT8	aucRsv[2] ;
	UINT8	aucIp[4] ;
} AC_DEVM_APDHCPSTATICIP_CONFIG_T;

/* 	DHCP for AP ��̬IP��ַ������*/
typedef struct 
{
	UINT32	ulId ;						/* ��ַ�ر�� */
	CHAR    	acIpPoolNAme[32]	    	;   	/* ����                     */
	UINT8   	aucBeginIp[4]	        		;   	/* ��ʼ��ַ                 */
	UINT8   	aucEndIp[4]	            		;   	/* ������ַ                 */
	UINT8   	aucMask[4]	            		;   	/* ����                     */
	UINT8	aucReservedIp1[4];				/* ����IP��ַ1 */
	UINT8	aucReservedIp2[4];				/* ����IP��ַ2 */
	UINT8	aucReservedIp3[4];				/* ����IP��ַ3 */	
	UINT8	aucReservedIp4[4];				/* ����IP��ַ4 */	
	UINT32  	ulLease                 		;   		/* ��Լ���� ��λ����        */
	CHAR    	acDomainName[256]	    	;   		/* ������׺                 */
	UINT8   	aucDnsIpMaster [4]      	;   		/* ����DNS������IP��ַ      */
	UINT8   	aucGatewayIpMaster [4] 	;   		/* ��������IP��ַ           */
	UINT8   	aucDnsIpSlave[4]       		;   	/* ����DNS������IP��ַ      */
	/* add by gwx 2013-3-12 for task532 */
	CHAR       acVendorName[64];                        /* ��������Ϣ��Ĭ��Ϊ��*/

	UINT32	ulVlanId1;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId2;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId3;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	UINT32	ulVlanId4;						/* ��VLAN1 : 0~4094 0��ʾ����������VLAN */
	/* add by gwx 2012-9-12 ����������ͨ���ⳡ����
	ʹ��һ̨AC��ΪDHCP server��Ϊ��̨AC��AP�����ַ*/
	UINT8	aucAcIpMaster[4];			/*	��AC��ַ*/
	UINT8	aucAcIpSlave[4];				/*	��AC��ַ*/
} AC_DEVM_APDHCPDYNIP_CONFIG_T;

/* 	QOSȫ������*/
typedef struct 
{
	UINT32	ulQosSwitch;				/* QOS���ع��ܿ���: 0/1  ����/����*/
	UINT32	ulQosPrioSwitch;			/* QOS���ȼ����ܿ��أ�0/1  ����/���� */
} AC_DEVM_QOSGLOBAL_CONFIG_T;

/* 	�û�QOSȫ������*/
typedef struct 
{
	UINT32		ulUserPri;					/* �û����ȼ� */
	UINT32		ulUpBand;					/* �û����б�֤����*/
	UINT32		ulUpBandMax;				/* �û�����������*/
	UINT32		ulDownBand;					/* �û����б�֤����*/
	UINT32		ulDownBandMax;				/* �û�����������*/
} AC_DEVM_QOSUSRDFT_CONFIG_T;

/* 	VLAN QOS����*/
typedef struct 
{
	UINT32		ulVlanId ;
	UINT32		ulUserPri;					/* �û����ȼ� */
	UINT32		ulUpBand;					/* �û����б�֤����*/
	UINT32		ulUpBandMax;				/* �û�����������*/
	UINT32		ulDownBand;					/* �û����б�֤����*/
	UINT32		ulDownBandMax;				/* �û�����������*/
} AC_DEVM_QOSVLAN_CONFIG_T;

/* 	SSID QOS����*/
typedef struct 
{
	UINT32		ulId ;
	CHAR		acSsid[32];
	UINT32		ulUserPri;					/* �û����ȼ� */
	UINT32		ulUpBand;					/* �û����б�֤����*/
	UINT32		ulUpBandMax;				/* �û�����������*/
	UINT32		ulDownBand;					/* �û����б�֤����*/
	UINT32		ulDownBandMax;				/* �û�����������*/
} AC_DEVM_QOSSSID_CONFIG_T;

/* 	�澯�������� */
typedef struct 
{
	UINT32		ulAlarmNo;
	CHAR		acAlarmName[32] ;	/* �澯���� */
	UINT32		ulAlarmIsValid;
} AC_DEVM_ALARMFILTER_CONFIG_T;

/* AC �澯��������*/
typedef struct 
{
	UINT32  ulAlarmResendWaitingTime;	/* �澯�ط��ȴ�ʱ�� */
	UINT32  ulCpuLoadPeriod;    	/*		CPU���ɲ������� */
	UINT32  ulCpuLoadCount;     	/*		CPU���ɳ������� */
	UINT32  ulCpuLoadHigh;		/*      CPU���ɸ澯�������� */
	UINT32  ulCpuLoadLow;       	/*      CPU���ɸ澯�������� */
			
	UINT32  ulMemLoadPeriod;    	/*  	�ڴ������ʲ������� */
	UINT32  ulMemLoadCount;     	/*  	�ڴ������ʳ������� */
	UINT32  ulMemLoadHigh;      	/*  	�ڴ������ʸ澯�������� */
	UINT32  ulMemLoadLow;       	/*      �ڴ������ʸ澯�������� */
			
	UINT32  ulTempPeriod;       	/*	�豸�¶Ȳ������� */
	UINT32  ulTempCount;        	/*	�豸�¶ȳ������� */
	UINT32  ulTempHigh;        	 	/*	�豸�¶ȸ澯�������� */
	UINT32  ulTempLow;          	/*	�豸�¶ȸ澯�������� */
} AC_DEVM_ACALARMTHRESHOLD_CONFIG_T;

/* AP �澯��������*/
typedef struct 
{
	UINT32	ulWtpId;					/* �豸ID */
	
	UINT32  ulCpuLoadPeriod;    	/*		CPU���ɲ������� */
	UINT32  ulCpuLoadCount;     	/*		CPU���ɳ������� */
	UINT32  ulCpuLoadHigh;		/*      CPU���ɸ澯�������� */
	UINT32  ulCpuLoadLow;       	/*      CPU���ɸ澯�������� */
			
	UINT32  ulMemLoadPeriod;    	/*  	�ڴ������ʲ������� */
	UINT32  ulMemLoadCount;     	/*  	�ڴ������ʳ������� */
	UINT32  ulMemLoadHigh;      	/*  	�ڴ������ʸ澯�������� */
	UINT32  ulMemLoadLow;       	/*      �ڴ������ʸ澯�������� */
			
	UINT32  ulTempPeriod;       	/*	�豸�¶Ȳ������� */
	UINT32  ulTempCount;        	/*	�豸�¶ȳ������� */
	UINT32  ulTempHigh;        	 	/*	�豸�¶ȸ澯�������� */
	UINT32  ulTempLow;          	/*	�豸�¶ȸ澯�������� */
	INT32	lLowTempHigh;		/*		�豸���¸澯��������	��50��0	��30	��*/
	INT32	lLowTempLow;		/*		�豸���¸澯��������	��50��0	��20	��*/
} AC_DEVM_WTPALARMTHRESHOLD_CONFIG_T;

/* 	���ܼ�����������*/
typedef struct 
{
	UINT32		ulCounterGroupId;
	UINT32		ulCounterGroupPeriod;
	UINT32		ulCounterGroupIsInvalid;
} AC_DEVM_PERFCOUNTER_CONFIG_T;

//AS����������AC_DEVM_WAPIAS_CONFIG_T
typedef struct 
{
	UINT8   acAsIp[4];  		/*	AS������IP  */
	UINT32  ulAsPort;   		/*	AS������Port	*/
	UINT32  ulAsAuthCert;   	/*		AS֤����֤	0������ 1������*/
	UINT32  ulCertFileSize; 	/*		AS֤���ļ���С	*/
	UINT8   aucCertFileContent[4096];   /*	AS֤���ļ�����	*/
} AC_DEVM_WAPIAS_CONFIG_T;


//	WAPI��������AC_DEVM_WAPI_CONFIG_T
typedef struct 
{
	UINT32  ulWapiSetupId;  		/*		WAPI����ID	0��15 */
	CHAR    acName[32];     		/*	    WAPI��������	*/
	UINT32  ulWapiCertAkm;  		/*		֤����AKM	0������ 1������ */
	UINT32  ulWapiPskAkm;   		/*		Ԥ������ԿAKM	0������ 1������ */
	UINT32  ulWapiPreAuth;  		/*		WAPIԤ��Ȩ	0������ 1������ */
	UINT32  ulUnicastCipher;   	 /*		���������׼�	1��SMS4 */
	UINT32  ulUnicastKeyLen;    	/*		������Կ����	256 */
	UINT32  ulUnicastKeyUpdateManner;   /*		������Կ���»���	1��������
					                                    2������ʱ��
					                                    3�����ڰ���
					                                    4������ʱ��Ͱ���
					                                    */
	UINT32  ulUnicastKeyValidity;       	/*		������Կ��������	>0 */
	UINT32  ulUnicastKeyPkgs;       	/*	    ������Կ���°���Ŀ	>0 */
	UINT32  ulMulticastCipher;         	/*		�鲥�����׼�	1��SMS4 */
	UINT32  ulMulticastKeyLen;          	/*		�鲥��Կ����	256 */
	UINT32  ulMulticastKeyUpdateManner; /*		�鲥��Կ���»���	1��������
				                                            2������ʱ��
				                                            3�����ڰ���
				                                            4������ʱ��Ͱ���
				                                   	 */
	UINT32  ulMulticastKeyValidity;     			/*		�鲥��Կ��Чʱ��	>0 */
	UINT32  ulMulticastKeyPkgs;     			/*	    �鲥��Կ��Ч����	>0 */
	UINT32  ulMulticastRekeyStrict; 			/*  	STA�뿪BSS������鲥��Կ	0������ 1������ */
	UINT32  ulAuthRetryTimes;		    		/*      ��Ȩ����Э�����Դ���	>0 */
	UINT32  ulMulticastRekeyRetryTimes; 		/*		�鲥��Կ����Э�����Դ���	>0 */
	UINT32  ulUnicastRekeyRetryTimes;  		 /*		������Կ����Э�����Դ���	>0 */
	UINT32  ulBasicKeyValidity;    			 	/*	    ����Կ��Ч��	>0  */
	UINT32  ulBasicKeyReAuthThreshold;  		/*		����Կ���¼�Ȩ������ʱ��	0-100 */
	UINT32  ulSecAssociateTimeout;			/*      ��ȫ�����ĳ�ʱʱ��	>0 */
} AC_DEVM_WAPI_CONFIG_T;

//6.1.76	WAPI֤������AC_DEVM_WAPICERTFILE_CONFIG_T
typedef struct 
{
	UINT32  ulCertId;           			/*	֤��ID */
	CHAR    acCertDesc[128];   		/*	֤������ */
	UINT32  ulCertFileSize; 			/*	֤���ļ���С */
	UINT8   aucCertFileContent[4096];  /*	֤���ļ����� */
	UINT8   aucBindMac[6];  	        	/* ֤��󶨵�MAC��ַ */
	UINT8   aucRsv[2];                  		/* ����ֽ� */
} AC_DEVM_WAPICERTFILE_CONFIG_T;


/* �����豸�ھ�����*/
/* �ھ�����*/
enum {
	AC_NEIGH_TYPE_WTP,	/* �豸��*/
	AC_NEIGH_TYPE_VDEV	/* Radio�� */
} AC_NEIGH_TYPE;

enum {
	AC_NEIGH_RELATION_UNI,	/* �����ھ�*/
	AC_NEIGH_RELATION_BIO		/* ˫���ھ�*/
} AC_NEIGH_RELATION;

typedef struct 
{
	AC_VDEVID_T		stVdevId ;						/* �ھ������豸 */
	UINT32	ulNeighRelation ;					/* �ھӹ�ϵ */
	UINT32	ulLoadNeigh ;					/* �Ƿ񸺺ɾ����ھ� */
	UINT32	ulCoverageNeigh	;				/* �Ƿ񸲸ǲ����ھ� */
} AC_DEVM_VDEVNEIGH_CONFIG_T;

/* STPЭ���������*/
typedef struct 
{
	UINT32	ulStpHello;
	UINT32	ulStpForwardDelay;
	UINT32	ulStpMaxage;
	UINT32	ulStpBrPri;
} AC_DEVM_STP_CONFIG_T;


/*	PPPoE����������AC_DEVM_PPPOESERVER_CONFIG_T */
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

	/* ��Ȩ���������� */
    	AC_DEVM_RADIUS_SERVER_T        stAuthSrvMaster;
    	AC_DEVM_RADIUS_SERVER_T        stAuthSrvSlave;
    
	/* �Ʒѷ��������� */
    	AC_DEVM_RADIUS_SERVER_T        stAcctSrvMaster;
    	AC_DEVM_RADIUS_SERVER_T        stAcctSrvSlave;
} AC_DEVM_PPPOESERVER_CONFIG_T;

/* AC�����������*/
typedef struct
{
	UINT32	ulMsMode;		/* ����ģʽ */
	UINT32	ulEchoInterval;	/* ������ */
	UINT32	ulEchoNum;		/* ���ʱ���� */
	UINT32	ulBakAcNum;	/* ����AC��Ŀ */
	UINT32	ulPeerAcId1;		/* �����豸1 ID  */
	UINT8	aucPeerAcIp1[4];	/* �����豸1 IP  */
	UINT8	aucPeerAcGw1[4];	/* �����豸1ȱʡ����*/
	UINT8	aucPeerAcMngIp1[4];	/*add by gwx 2011-10-28 for �����ƶ��� �����豸1����IP */
	UINT32	ulPeerAcId2;		/* �����豸2 ID  */
	UINT8	aucPeerAcIp2[4];	/* �����豸2 IP  */
	UINT8	aucPeerAcGw2[4];	/* �����豸2ȱʡ����*/
	UINT8	aucPeerAcMngIp2[4];	/*add by gwx 2011-10-28 for �����ƶ��� �����豸2����IP */
	UINT32	ulPeerAcId3;		/* �����豸3 ID  */
	UINT8	aucPeerAcIp3[4];	/* �����豸3 IP  */
	UINT8	aucPeerAcGw3[4];	/* �����豸3ȱʡ����*/
	UINT8	aucPeerAcMngIp3[4];	/*add by gwx 2011-10-28 for �����ƶ��� �����豸3����IP */

	UINT32	ulEnableVrrp;		/*		VRRP����*/
	
	/* �����豸1����IP */
	UINT8	aucVrrpIp1[4];		/*	����IP1 */
	UINT8	aucVrrpIp2[4];		/*	����IP2 */
	UINT8	aucVrrpIp3[4];		/*	����IP3 */
	UINT8	aucVrrpIp4[4];		/*	����IP4 */

	/* �����豸2����IP */
	UINT8	aucVrrpIp5[4];		/*	����IP1 */
	UINT8	aucVrrpIp6[4];		/*	����IP2 */
	UINT8	aucVrrpIp7[4];		/*	����IP3 */
	UINT8	aucVrrpIp8[4];		/*	����IP4 */

	/* �����豸1����IP */
	UINT8	aucVrrpIp9[4];		/*	����IP1 */
	UINT8	aucVrrpIp10[4];		/*	����IP2 */
	UINT8	aucVrrpIp11[4];		/*	����IP3 */
	UINT8	aucVrrpIp12[4];		/*	����IP4 */
} AC_DEVM_MSSETUP_CONFIG_T;


/* ���ݽṹ�������*/
/******************************************************************************/



/******************************************************************************/
/* �����ӿ�����νṹ���忪ʼ*/
/* ��ȡ3A��������������νṹ�嶨�� */
typedef struct
{
    UINT32    ulRet;        /* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    AC_DEVM_RADIUS_SERVERS_T    stRadiusServers;
} AC_DEVM_GET_RADIUS_SERVERS_RSP_T;

/* ��ȡAC������Ϣ*/
typedef struct
{
    UINT32  ulRet;
    AC_DEVM_AC_OWNCONFIG_T  stAcOwnCfg;
} AC_DEVM_GET_AC_OWNCONFIG_RSP_T;

/* ��ȡAC MOID */
typedef struct
{
    	UINT32    ulRet;        					/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_OMA_MO_T	stAcMoid;			/* AC MOID */
} AC_DEVM_GET_AC_MOID_RSP_T;

/* 	������������ȡָ��WTP�豸��CAPWAP��������*/
/* 	��������ṹ��*/
typedef struct 
{
    	AC_WTPID_T    stWtpId;
}AC_DEVM_GET_WTPASSO_BYID_REQ_T;

/* 	��������ṹ��*/
typedef struct 
{
	UINT32	ulRet;
	UINT32	ulCfgDeviceType;
	AC_DEVM_WTPASSO_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTPASSO_BYID_RSP_T;

// 	������������ȡָ��AC������·�����Լ������
// 	��������ṹ��
//�ޡ�
// 	��������ṹ��
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ACKEEPER_CONFIG_T  stAcKeeperCfg;
}AC_DEVM_GET_ACKEEPERCFG_RSP_T;

// 	��������������AC������·״̬
 //	��������ṹ��
typedef struct 
{
	UINT32	ulState;
}AC_DEVM_SET_ACUPLINKSTATE_REQ_T;

// 	��������ṹ��
typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_ACUPLINKSTATE_RSP_T;

/* ��ȡָ��WTP�豸����*/
typedef struct 
{
    AC_WTPID_T    stWtpId;
}AC_DEVM_GET_WTP_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_WTP_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTP_BYID_RSP_T;

/* ��ȡWTP���豸�����ã�WTP�ϵ���*/
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

/*  ��ȡWTP�豸���ýӿ�����νṹ�嶨�� */
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_WTP_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
    UINT32    ulWtpNum;     /* ��ЧWTP���� */
    AC_DEVM_WTP_CONFIG_T    astWtp[10];
} AC_DEVM_GET_WTP_CONFIG_RSP_T;

// 	��������������WTP ID��ȡ��WTP��ǰ�󶨵�AC ID�б�
// 	��������ṹ��
typedef AC_WTPID_T AC_DEVM_GET_BINDACID_REQ_T;

// 	��������ṹ��
typedef struct
{
	UINT32	ulRet;			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulBindAcNum;	/* �󶨵�AC��Ŀ */
	UINT32	aulAcId[8];		/* �󶨵�AC�豸ID�б� */
} AC_DEVM_GET_BINDACID_RSP_T;

//	����WTP ID��ȡ��WTP��ǰ���ӵ�AC ID��������
 typedef AC_WTPID_T AC_DEVM_GET_CURACID_REQ_T;
 typedef struct
{
	UINT32	ulRet;			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32	ulAcId;			/* ��ǰ���ӵ�AC ID */
} AC_DEVM_GET_CURACID_RSP_T;

/* ����AP�豸���кŻ�ȡAP�豸����*/
typedef struct 
{
	UINT8	aucDeviceId[6];	/* AP �豸���к�*/
	UINT8	aucRsv[2];		/* ����ֽ�*/
	UINT32	ulDeviceType;	/* �豸�ͺ�*/
} AC_DEVM_GET_WTP_BYSN_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulCfgDeviceType;		/* AC�����е��豸�ͺ�*/
	AC_DEVM_WTPASSO_CONFIG_T  stWtpCfg;
}AC_DEVM_GET_WTP_BYSN_RSP_T;

typedef struct
{
	UINT32	ulDeviceType;
}AC_DEVM_ALLOCATE_WTPID_REQ_T; 

/* 2010-4-19 pyy ��������ʧ��ԭ����*/
#define AC_DEVM_ALLOCATEFAIL_REASON_DIFFDEVICETYPE		((UINT32)1)	/* �豸���Ͳ�ƥ��*/
#define AC_DEVM_ALLOCATEFAIL_REASON_NOFREEASSO			((UINT32)2)	/* �޿��й���*/

typedef struct
{
	UINT32	ulRet;
	UINT32	ulWtpId;
}AC_DEVM_ALLOCATE_WTPID_RSP_T;
 	
/* ��ȡ�ӿ���������νṹ�嶨�� */
typedef AC_WTPID_T AC_DEVM_GET_IF_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        /* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    UINT32    ulIfNum;      /* �ӿ��� */
    AC_DEVM_IF_CONFIG_T        astIf[AC_IF_NUM_MAX_PER_WTP];
} AC_DEVM_GET_IF_CONFIG_RSP_T;

/* 	��ȡָ��WTP�豸�������豸�б�*/
typedef AC_WTPID_T AC_DEVM_GET_VDEVLIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulVdevNum;	/* �����豸�� */
	AC_DEVM_VDEV_CONFIG_T		astVdevList[AC_VDEV_NUM_MAX_PER_WTP];
} AC_DEVM_GET_VDEVLIST_CONFIG_RSP_T;


//��ȡ�����豸���ھ�����
typedef AC_VDEVID_T AC_DEVM_GET_VDEVNEIGH_CONFIG_REQ_T;
 
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_VDEVNEIGH_CONFIG_T		astVdevNeighCfg[16];
} AC_DEVM_GET_VDEVNEIGH_CONFIG_RSP_T;

 
// 	�������������������豸��ʶ��ȡ�����豸��MOID
typedef AC_VDEVID_T  AC_DEVM_GET_VDEV_MOID_REQ_T;
 
typedef struct
{
    	UINT32    ulRet;        					/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_OMA_MO_T	stVdevMoid;			/* VDEV MOID */
} AC_DEVM_GET_VDEV_MOID_RSP_T;

/* ���������豸ID��ȡ�����豸����*/
typedef AC_VDEVID_T  AC_DEVM_GET_VDEV_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_VDEV_CONFIG_T	stCfg;
} AC_DEVM_GET_VDEV_BYID_RSP_T;


/* WTP �ϻ�ȡ���������豸������书��*/
typedef struct 
{
	UINT32	ulRet;
	UINT32	ulNum;
	AC_DEVM_VDEV_MAXPOWER_T	astMaxPower[4];
} AC_DEVM_GET_WTP_VDEVMAXTXPOWER_RSP_T;

/* WTP �ϻ�ȡ���лش�ģ���BSSID */
typedef struct 
{
	UINT32	ulRet;
    	UINT32  	ulNum;  
    	AC_DEVM_ADHOC_BSSID_T astBssid[4];
} AC_DEVM_GET_WTP_ADHOCBSSID_RSP_T;


/* ��ȡVAP��������νṹ�嶨�� */
typedef	struct
{
	AC_IFID_T	stIfId;
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
								/*
								��һ�ε���ʱ�����ulStartRec��0
								��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
								*/
} AC_DEVM_GET_VAP_CONFIG_REQ_T;

typedef struct
{
    UINT32    ulRet;        		/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    UINT32	ulFinish;			/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
    UINT32    ulVapNum;    		/* VAP�� */
    AC_DEVM_VAP_CONFIG_T        astVap[10];
} AC_DEVM_GET_VAP_CONFIG_RSP_T;

/* ��ȡָ�������豸�ϵ�VAP�б������� */
typedef	struct
{
	AC_VDEVID_T		stVdevId;
	UINT32			ulStartRec;		/* ��ѯ����ʼ��¼�� */
									/*
									��һ�ε���ʱ�����ulStartRec��0
									��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
									*/
} AC_DEVM_GET_VAP_CONFIG_BYVDEV_REQ_T;

typedef AC_DEVM_GET_VAP_CONFIG_RSP_T AC_DEVM_GET_VAP_CONFIG_BYVDEV_RSP_T;

/* WTP �ϻ�ȡ���豸����VAP BSSID��Ϣ */
typedef struct 
{
    UINT32  ulRet;
    UINT32  ulNum;  
    AC_DEVM_VAP_BSSID_T astVapBssid[64];    /* ÿ��WTP�ϵ����VAP����, ���޸� */
} AC_DEVM_GET_WTP_VAPBSSID_RSP_T;

/* WTP�ϻ�ȡ���豸����VAP������ͳ����Ϣ*/
typedef struct 
{
	UINT32 ulRet;
	UINT32 ulNum;
	AC_DEVM_VAP_TRAFFICSTAT_T	astVapStat[64];
} AC_DEVM_GET_WTP_VAPTRAFFICSTAT_RSP_T;

/* WTP�ϻ�ȡ���豸����VAP����ͳ����Ϣ*/
typedef struct
{
	UINT32  ulWtpId;
    	UINT32  ulVDevId;
    	UINT32  ulVapId;

    	/* �տ��շ�ͳ��*/
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

	/* �û�����ͳ��*/
	UINT32	ulAccessTimes;		/*	AP�������û����Ӵ���*/
	UINT32	ulAccessFailTimes;	/*	AP�������û�����ʧ�ܴ���*/
	UINT32	ulAccessRetryTimes;	/*	AP�������û������Ӵ���*/
	UINT32	ulAccessDenyTimes;	/*	AP�������û����Ӿܾ�����*/
	UINT32	ulAccessOutTimes1;	/*	���û��뿪�����½�����Ĵ���*/
	UINT32	ulAccessOutTimes2;	/*	��AP������������½�����Ĵ���*/
	UINT32	ulAccessOutTimes3;	/*	���쳣��������½�����Ĵ���*/
	UINT32	ulAccessOutTimes4;	/*	����ԭ���½�����Ĵ���*/
}AC_DEVM_VAP_WIFISTAT_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulNum;
	AC_DEVM_VAP_WIFISTAT_T		astVapWifiStat[64];
} AC_DEVM_GET_WTP_VAPWIFISTAT_RSP_T;



/* ��ȡVAP MOID ����νṹ�嶨�� */
typedef AC_VAPID_T  AC_DEVM_GET_VAP_MOID_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_OMA_MO_T	stVapMoid;	/* VAP MOID */
} AC_DEVM_GET_VAP_MOID_RSP_T;

//	����VAP BSSID��ȡVAP��ʶ��������
 typedef struct 
{
	UINT8       aucBssid[6];    /* VAP BSSID */
	UINT8       aucRsv[2];      /* ����ֽ� */
} AC_DEVM_GET_VAPID_BYBSSID_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	AC_VAPID_T	stVapId;			/* VAP ID */
} AC_DEVM_GET_VAPID_BYBSSID_RSP_T;

/* ��ȡָ��WTP�豸��VAP�б� */
typedef AC_WTPID_T	AC_DEVM_GET_VAP_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    	UINT32	ulNum;
	AC_VAPID_T	astVapId[AC_VAP_NUM_MAX_PER_WTP];	/* VAP ID �б�*/
	CHAR	aacSsid[AC_VAP_NUM_MAX_PER_WTP][32];	/* ��Ӧ��SSID�б�*/
	UINT32	aulTrafficMode[AC_VAP_NUM_MAX_PER_WTP];	/* 2010-4-20 pyy ����: VAPҵ��ת��ģʽ*/
} AC_DEVM_GET_VAP_CONFIG_BYWTP_RSP_T;


/*	��ȡָ��WTP�豸��ADHOC�б�������*/
typedef AC_WTPID_T	AC_DEVM_GET_ADHOC_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        			/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    	UINT32	ulNum;
	AC_ADHOCID_T	astAdhocId[AC_ADHOC_NUM_MAX_PER_WTP];	/* ADHOC ID �б�*/
} AC_DEVM_GET_ADHOC_CONFIG_BYWTP_RSP_T;

/* ����WTP����״̬�ӿ�����νṹ�嶨��*/
typedef struct 
{
    AC_WTPID_T    stWtpId;
    UINT32    ulValue;
} AC_DEVM_SET_WTP_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_WTP_OPSTATE_RSP_T;

/* ���ôӻ���ض�������״̬�ṹ�嶨��*/
typedef struct {
	UINT32	ulWtpId;
	UINT32    ulValue;
} AC_DEVM_SET_SLAVEOBJ_OPSTATE_REQ_T;

typedef struct {
	UINT32 	ulRet;
} AC_DEVM_SET_SLAVEOBJ_OPSTATE_RSP_T;

/* ����VDEV����״̬�ӿ�����νṹ�嶨��*/
typedef struct 
{
    AC_VDEVID_T    stVdevId;
    UINT32    ulValue;
} AC_DEVM_SET_VDEV_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_VDEV_OPSTATE_RSP_T;

/* ����VAP����״̬�ӿ�����νṹ�嶨��*/
typedef struct 
{
    AC_VAPID_T  stVapId;
    UINT32      ulValue;    /* NORMAL, FAULT */
    UINT32      ulReason;   /* ����VAP����״̬�仯��ԭ����: 
                               ��·״̬�仯
                               ����״̬�仯 */
} AC_DEVM_SET_VAP_OPSTATE_REQ_T;

typedef struct 
{
    UINT32    ulRet;
} AC_DEVM_SET_VAP_OPSTATE_RSP_T;

/* ����AP�豸����״̬�ӿ�����νṹ�嶨��*/
#define AC_DEVM_WTPASSO_NORMAL				0	/* ����״̬����*/
#define AC_DEVM_WTPASSO_NODISCOVERY			1	/* û���յ���������*/
#define AC_DEVM_WTPASSO_NOJOIN				2	/* û���յ���������*/
#define AC_DEVM_WTPASSO_CONNAUTHFAIL		3	/* ��Ȩʧ��*/
#define AC_DEVM_WTPASSO_OTHER				4	/* ����ԭ��*/

typedef struct 
{
	AC_WTPID_T	stWtpId;
	UINT32		ulAssoState;	
}AC_DEVM_SET_WTP_ASSOSTATE_REQ_T;

typedef struct 
{
	UINT32    ulRet;
}AC_DEVM_SET_WTP_ASSOSTATE_RSP_T;

/* ����WTP SN */
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

/* ��������ģ�鵱ǰ���书��*/
typedef struct {
	AC_VDEVID_T		stVdevId;
	UINT32	ulDynPower;
} AC_DEVM_SET_VDEV_DYNPOWER_REQ_T;

typedef struct {
	UINT32 	ulRet;
} AC_DEVM_SET_VDEV_DYNPOWER_RSP_T;

// 	��������������ָ��AP�豸��IP��ַ
// 	��������ṹ��
typedef struct 
{
	AC_WTPID_T	stWtpId;
	AC_DEVM_WTPIP_CONFIG_T	stWtpIpCfg;
}AC_DEVM_SET_WTPIP_REQ_T;

// 	��������ṹ��
typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_WTPIP_RSP_T;

// 	��������������WTPID��ȡָ��AP��IP��ַ
// 	��������ṹ��
typedef struct 
{
	AC_WTPID_T	stWtpId;
}AC_DEVM_GET_WTPIP_REQ_T;
// 	��������ṹ��
typedef struct 
{
	UINT32	ulRet;
	UINT8	aucIp[4];
}AC_DEVM_GET_WTPIP_RSP_T;

/* ����WTP IP��ַ��ȡWTP IP */
typedef struct 
{
	UINT8	aucIp[4];
}AC_DEVM_GET_WTPID_BYIP_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	UINT32	ulWtpId;
}AC_DEVM_GET_WTPID_BYIP_RSP_T;


/* ��ȡSNMP-V2������ã������� */
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPV2_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPV2_CONFIG_RSP_T;

/*��ȡSNMP-V3������ã������� */
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPV3_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPV3_CONFIG_RSP_T;

/* 	������������ȡSNMP TRAP�������*/
/*	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;
	AC_DEVM_SNMPTRAP_CONFIG_T		astCfg[4];
} AC_DEVM_GET_SNMPTRAP_CONFIG_RSP_T;

/* ��������: ��ȡAC��ǰ������汾����Ϣ*/
/*	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	CHAR	acSwVersion[32];	/* AC ��ǰ����汾*/
} AC_DEVM_GET_ACSWVERSION_RSP_T;


/* ��������: AP�汾����֪ͨ*/
typedef struct {
	UINT32	ulWtpId;
} AC_DEVM_SET_WTPSWUPDATE_REQ_T;

typedef struct {
	UINT32	ulRet;
} AC_DEVM_SET_WTPSWUPDATE_RSP_T;

/* ��������: AP�����޸�֪ͨ*/
typedef struct {
	UINT32	ulWtpId;
} AC_DEVM_SET_WTPCFGUPDATE_REQ_T;

typedef struct {
	UINT32	ulRet;
} AC_DEVM_SET_WTPCFGUPDATE_RSP_T;

/* ��ȡAC֧�ֵ�AP����汾�б���Ϣ*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ASSOCSWVERSETUP_CONFIG_T	stCfg;
} AC_DEVM_GET_ACASSOCSWVER_CONFIG_RSP_T;

/* ��ȡָ��AP������汾������Ϣ*/
typedef struct 
{
	UINT32	ulWtpId;	
} AC_DEVM_GET_WTPSWVERSION_REQ_T;

typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_SWSVR_CONFIG_T	stCfg;
}AC_DEVM_GET_WTPSWVERSION_RSP_T;

/* ����AP��ǰ����汾��*/
typedef struct
{
	UINT32	ulWtpId;
	CHAR	acSwVer[32];			/* AP�豸��ǰ�汾*/
	CHAR	acTargetSwVer[32];		/* AP�豸Ŀ��汾*/
} AC_DEVM_SET_WTPCURSWVERSION_REQ_T;

typedef struct 
{
	UINT32	ulRet;
}AC_DEVM_SET_WTPCURSWVERSION_RSP_T;

/*��ȡAP��ǰ�������ݰ汾��*/
typedef struct
{
	UINT32	ulWtpId;
} AC_DEVM_GET_WTPCFGVERSION_REQ_T;

typedef struct
{
	UINT32	ulRet;
	UINT32	ulCfgVersion;	/* �������ݰ汾��*/
} AC_DEVM_GET_WTPCFGVERSION_RSP_T;


/*	��ȡAC SNTPȫ�����ã������� */
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_ACSNTP_CONFIG_T	stSntpCfg;
} AC_DEVM_GET_ACSNTP_CONFIG_RSP_T;

/* ��ȡWTP SNTPȫ������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WTPSNTP_CONFIG_T	stSntpCfg;
} AC_DEVM_GET_WTPSNTP_CONFIG_RSP_T;

/*��ȡAC�����б����ã�������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	/* �˿����� */
	AC_DEVM_BRIDGE_CONFIG_T		astAcBridgeCfg[4];
} AC_DEVM_GET_ACBRIDGE_CONFIG_RSP_T;

/* 	��ȡAC����˿����ã�������*/
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
	UINT32	ulNum;	/* �˿��� */
	AC_DEVM_ACPORT_CONFIG_T		astAcPortCfg[AC_PORT_NUM_MAX];
} AC_DEVM_GET_ACPORT_CONFIG_RSP_T;

/*	��ȡָ��WTP�豸������˿��б�������*/
typedef AC_WTPID_T	AC_DEVM_GET_ENET_CONFIG_BYWTP_REQ_T;

typedef struct
{
    	UINT32    ulRet;        									/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
    	UINT32	ulNum;
    	AC_DEVM_ENET_CONFIG_T	astEnetCfg[AC_ENET_NUM_MAX_PER_WTP];/* ��������˿��б�*/
} AC_DEVM_GET_ENET_CONFIG_BYWTP_RSP_T;

/* ��ȡAC IP��ַ����*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_ACIP_CONFIG_T	stAcIp;
} AC_DEVM_GET_ACIP_CONFIG_RSP_T;

/* ��ȡL2-WAN/FAT-LAN������*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_BRIDGE_CONFIG_T	stBr;
} AC_DEVM_GET_L2WAN_CONFIG_RSP_T;

/* ��ȡL3-WAN������*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_BRIDGE_CONFIG_T	stBr;
} AC_DEVM_GET_L3WAN_CONFIG_RSP_T;

/* ����AC ����˿ںŻ�ȡ�˿�����*/
typedef struct
{
	UINT32	ulIfId;	/* ����˿ں�*/
}AC_DEVM_GET_ACPORT_BYID_REQ_T;

typedef struct
{
	UINT32	ulRet;
	AC_DEVM_ACPORT_CONFIG_T	stAcPort;
} AC_DEVM_GET_ACPORT_BYID_RSP_T;

/* ��ȡ��һ��IP */
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
	UINT32	ulNum;		/* �˿��� */
	AC_DEVM_ACPORT_CONFIG_T		astAcPortCfg[AC_PORT_NUM_MAX];
} AC_DEVM_GET_ACMSPORT_CONFIG_RSP_T;

/* ��ȡVLANȫ������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_VLANGLOBAL_CONFIG_T		stVlanCfg;
} AC_DEVM_GET_VLANGLOBAL_CONFIG_RSP_T;

/* 	��ȡVLAN�������ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_VLAN_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLAN_CONFIG_T		astVlanCfg[32];
} AC_DEVM_GET_VLAN_CONFIG_RSP_T;

/* ��ȡSSID-VLANӳ������*/
typedef struct 
{
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_VLANSSIDMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
						AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANSSIDMAP_CONFIG_T		astVlanSsidMapCfg[64];
} AC_DEVM_GET_VLANSSIDMAP_CONFIG_RSP_T;


/* 	��ȡ�˿�-VLANӳ�����ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_VLANIFMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
						AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANIFMAP_CONFIG_T		astVlanIfMapCfg[64];
} AC_DEVM_GET_VLANIFMAP_CONFIG_RSP_T;

/* 	��ȡMAC-VLANӳ�����ã�������*/
typedef struct {
UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
							/*
							��һ�ε���ʱ�����ulStartRec��0
							��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
							*/
} AC_DEVM_GET_VLANMACMAP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANMACMAP_CONFIG_T		astVlanMacMapCfg[100];
} AC_DEVM_GET_VLANMACMAP_CONFIG_RSP_T;

/*��ȡVLAN MAC��ַ���˲������ã�������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_REQ_T;

/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANACCMACPOLICY_CONFIG_T	astPolicyCfg[100];
} AC_DEVM_GET_VLANACCMACPOLICY_CONFIG_RSP_T;

/* 	��ȡVLAN MAC�����б����ã������� */
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_VLANACCMAC_CONFIG_REQ_T;
 
typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANACCMAC_CONFIG_T		astVlanAccMacCfg[100];
} AC_DEVM_GET_VLANACCMAC_CONFIG_RSP_T;

/* 2009-11-5 pyy ����*/
/* ��ȡVLAN�ڸ��˿��ϵ��������*/
typedef struct
{
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_VLANFORIF_CONFIG_REQ_T;

typedef struct
{
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulVlanNum;	/* ���ε��÷��ص�VLAN������*/
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_VLANIFMAP_CONFIG_T		astVlanIfMapCfg[64];
}AC_DEVM_GET_VLANFORIF_CONFIG_RSP_T;


/* 	��ȡIGMP Snooping���ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IGMPSNOOP_CONFIG_T		stIgmpSnoopCfg;
} AC_DEVM_GET_IGMPSNOOP_CONFIG_RSP_T;
 
/* 	��ȡIGMP Proxy���ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IGMPPROXY_CONFIG_T		stIgmpProxyCfg;
} AC_DEVM_GET_IGMPPROXY_CONFIG_RSP_T;

/* 	��ȡ��̬·�����ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_ROUTESTATIC_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;	
	AC_DEVM_ROUTESTATIC_CONFIG_T		astRouteStatic[100];
} AC_DEVM_GET_ROUTESTATIC_CONFIG_RSP_T;

/*	��ȡRIPȫ�����ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_RIPGLOBAL_CONFIG_T		stRipGlobalCfg;
} AC_DEVM_GET_RIPGLOBAL_CONFIG_RSP_T;

/* 	��ȡRIPͨ���������ã�������*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	
	AC_DEVM_RIPNOTIFYNET_CONFIG_T		astRipNotifyIp[16];
} AC_DEVM_GET_RIPNOTIFYIP_CONFIG_RSP_T;

/* 	��ȡ����ǽȫ�����ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FWGLOBAL_CONFIG_T		stFwGlobalCfg;
} AC_DEVM_GET_FWGLOBAL_CONFIG_RSP_T;

 	
/* 	��ȡ����ǽ�������ã�������*/
 typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_FWRULE_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_FWRULE_CONFIG_T		astFwRule[8];
} AC_DEVM_GET_FWRULE_CONFIG_RSP_T;

/* ��ȡNATȫ������*/
typedef struct 
{
	UINT32	ulRet;
	AC_DEVM_NATGLOBAL_CONFIG_T		stNatGlobalCfg;
} AC_DEVM_GET_NATGLOBAL_CONFIG_RSP_T;

/* 	��ȡNAT���ã�������*/
typedef struct {
	UINT32 	ulRet;
	UINT32	ulNum;	
	AC_DEVM_NAT_CONFIG_T		astNat[32];
} AC_DEVM_GET_NAT_CONFIG_RSP_T;

/* ��ȡP2P��������*/
typedef struct {
	UINT32	ulRet;
	AC_DEVM_FWL7MATCH_CONFIG_T	stP2PCfg;
} AC_DEVM_GET_P2P_CONFIG_RSP_T;

/* 	��ȡIDS�������ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IDSRULE_CONFIG_T		stIdsRule;
} AC_DEVM_GET_IDSRULE_CONFIG_RSP_T;

/* 	��ȡIDS�������ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_IDSSTRY_CONFIG_T		stIdsStry;
} AC_DEVM_GET_IDSSTRY_CONFIG_RSP_T;

/*	��ȡDHCP for STA ȫ�����ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_STADHCPGLOBAL_CONFIG_T		stDhcpGlobalCfg;
} AC_DEVM_GET_STADHCPGLOBAL_CONFIG_RSP_T;

/* 	��ȡDHCP for STA ��̬��IP���ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_STADHCPSTATICIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */

	UINT32	ulNum;
	AC_DEVM_STADHCPSTATICIP_CONFIG_T		astDhcpStaticIp[8];
} AC_DEVM_GET_STADHCPSTATICIP_CONFIG_RSP_T;
 	
/* 	��ȡDHCP for STA ��̬IP��ַ�����ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_STADHCPDYNIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;
	AC_DEVM_STADHCPDYNIP_CONFIG_T		astDhcpDynIp[8];
} AC_DEVM_GET_STADHCPDYNIP_CONFIG_RSP_T;

/*	��ȡDHCP for AP ȫ�����ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_APDHCPGLOBAL_CONFIG_T		stDhcpGlobalCfg;
} AC_DEVM_GET_APDHCPGLOBAL_CONFIG_RSP_T;

/* 	��ȡDHCP for AP ��̬��IP���ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_APDHCPSTATICIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */

	UINT32	ulNum;
	AC_DEVM_APDHCPSTATICIP_CONFIG_T		astDhcpStaticIp[8];
} AC_DEVM_GET_APDHCPSTATICIP_CONFIG_RSP_T;
 	
/* 	��ȡDHCP for AP ��̬IP��ַ�����ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_APDHCPDYNIP_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;
	AC_DEVM_APDHCPDYNIP_CONFIG_T		astDhcpDynIp[8];
} AC_DEVM_GET_APDHCPDYNIP_CONFIG_RSP_T;

 	
/*	��ȡQOSȫ�����ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_QOSGLOBAL_CONFIG_T		stQosGlobalCfg;
} AC_DEVM_GET_QOSGLOBAL_CONFIG_RSP_T;
	
/* 	��ȡ�û�QOSȱʡ���ã�������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_QOSUSRDFT_CONFIG_T		stQosUsrDft;
} AC_DEVM_GET_QOSUSRDFT_CONFIG_RSP_T;
 	
/* 	��ȡVLAN QOS���ã�������*/

typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_QOSVLAN_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_QOSVLAN_CONFIG_T		astQosVlan[100];
} AC_DEVM_GET_QOSVLAN_CONFIG_RSP_T;
 	
/* ��ȡSSID QOS���ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_QOSSSID_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_QOSSSID_CONFIG_T		astQosSsid[32];
} AC_DEVM_GET_QOSSSID_CONFIG_RSP_T;
 	
/* 	��ȡ���豸�澯���ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_ALARMFILTER_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_ALARMFILTER_CONFIG_T		astAlarm[100];
} AC_DEVM_GET_ALARMFILTER_CONFIG_RSP_T;

/* ��ȡ��AC�澯��������(����)*/
//         ������������ȡ���豸�澯��������
//         ��������ṹ��
//�ޡ�
//      ��������ṹ��
typedef struct {
    UINT32 ulRet;
    AC_DEVM_ACALARMTHRESHOLD_CONFIG_T   stCfg;
} AC_DEVM_GET_ACALARMTHRESHOLD_CONFIG_RSP_T;

/* 	��ȡ���豸���ܼ����������ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
} AC_DEVM_GET_PERFCOUNTER_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
	AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_PERFCOUNTER_CONFIG_T		astPerfCounter[100];
} AC_DEVM_GET_PERFCOUNTER_CONFIG_RSP_T;

/* 	������������ȡ���豸������汾����*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_SWSVR_CONFIG_T		stSwSvrCfg;
} AC_DEVM_GET_SWSVR_CONFIG_RSP_T;

/* 	������������ȡAC��ǰ���������ݰ汾��*/
// 	��������ṹ��
typedef struct {
	UINT32 	ulRet;
	UINT32	ulCfgVersion;
} AC_DEVM_GET_CFG_VERSION_RSP_T;


/* ��ȡSTP���ýӿڲ����ṹ�嶨��*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_STP_CONFIG_T		stStp;
} AC_DEVM_GET_STP_CONFIG_RSP_T;

/* ��ȡPPPoE����������*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_PPPOESERVER_CONFIG_T		stPPPoECfg;
} AC_DEVM_GET_PPPOESERVER_CONFIG_RSP_T;

/* 2011-8-8 pyy MAC��֤��������*/
typedef struct
{
	UINT32	ulMacSwitch;			/*	MAC��֤����*/
	UINT8	aucMacSrvAddr[4];	/*	MAC��֤������IP */
	UINT32	ulMacSrvPort;		/*	MAC��֤�������˿�*/
	UINT32	ulTrafficTime;			/*	MAC��֤����ʱ��*/
	UINT32	ulTrafficThresh;		/*	MAC��֤��������*/
} AC_DEVM_MACSERVER_CONFIG_T;

typedef struct
{
	UINT32 	ulRet;
	AC_DEVM_MACSERVER_CONFIG_T		stMacServerCfg;
} AC_DEVM_GET_MACSERVER_CONFIG_RSP_T;

/*	��ȡǿ��Portalȫ�����ã�������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_PORTAL_CONFIG_T		stPortalCfg;
} AC_DEVM_GET_PORTAL_CONFIG_RSP_T;

/* 	��ȡPortal���������ã�������*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_WHITELIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_WHITELIST_CONFIG_T	astWhiteList[8];
} AC_DEVM_GET_WHITELIST_CONFIG_RSP_T;

/* ��ȡ�û�����ַ���б�*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_USERADDRBIND_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_USERADDRBIND_CONFIG_T	astUserAddrBind[8];
} AC_DEVM_GET_USERADDRBIND_CONFIG_RSP_T;

/* ��ȡ����֤IP ��ַ�б�*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_FREEADDR_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_FREEADDR_CONFIG_T	astFreeAddr[8];
} AC_DEVM_GET_FREEADDR_CONFIG_RSP_T;

/* ��ȡ����֤MAC��ַ�б�*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_FREEMAC_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_FREEMAC_CONFIG_T	astFreeMac[8];
} AC_DEVM_GET_FREEMAC_CONFIG_RSP_T;


/* ��ȡ����֤SSID�б�*/

typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FREESSID_CONFIG_T	stFreeSsid;
} AC_DEVM_GET_FREESSID_CONFIG_RSP_T;

/* ��ȡ����֤VLAN�б�*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_FREEVLAN_CONFIG_T	stFreeVlan;
} AC_DEVM_GET_FREEVLAN_CONFIG_RSP_T;


typedef struct 
{
	UINT32	ulRet;
	UINT32	ulFreeSwitch;	/* ȫ������֤����*/
} AC_DEVM_GET_FREEGLOBAL_CONFIG_RSP_T;

/* ��ȡ������URL����*/
typedef struct {
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_WHITEURLLIST_CONFIG_REQ_T;

typedef struct {
	UINT32 	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;		/* ���ε��÷��ص������� */
	AC_DEVM_WHITEURL_CONFIG_T	astWhiteUrl[8];
} AC_DEVM_GET_WHITEURLLIST_CONFIG_RSP_T;


/*	��ȡ���豸����־�������ã�������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_LOG_CONFIG_T		stLogCfg;
} AC_DEVM_GET_LOG_CONFIG_RSP_T;

/* 	��ȡ��־���������ã�������*/
/* 	��������ṹ��*/
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_LOGSVR_CONFIG_T		stLogSvrCfg;
} AC_DEVM_GET_LOGSVR_CONFIG_RSP_T;

// 	������������ȡAS����������
// 	��������ṹ��
// 	��������ṹ��
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPIAS_CONFIG_T		stWapiAs;
} AC_DEVM_GET_WAPIAS_CONFIG_RSP_T;

// 	���������� ����WAPI ID��ȡWAPI���ò���
// 	��������ṹ��
typedef struct {
	UINT32 	ulWapiSetupId;
} AC_DEVM_GET_WAPI_CONFIG_REQ_T;

// 	��������ṹ��
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPI_CONFIG_T	stWapi;
} AC_DEVM_GET_WAPI_CONFIG_RSP_T;

// ����WAPI֤��ID��ȡ֤������
// 	��������ṹ��
typedef struct {
	UINT32 	ulCertId;
} AC_DEVM_GET_WAPICERTFILE_CONFIG_REQ_T;

 //	��������ṹ��
typedef struct {
	UINT32 	ulRet;
	AC_DEVM_WAPICERTFILE_CONFIG_T	stCert;
} AC_DEVM_GET_WAPICERTFILE_CONFIG_RSP_T;

// 	��������������VAP ID��ȡVAP��ǰ����״̬
// 	��������ṹ��
typedef struct 
{
	AC_VAPID_T  stVapId;
} AC_DEVM_GET_VAP_OPSTATE_REQ_T;

// 	��������ṹ��
typedef struct 
{
	UINT32    ulRet;
	UINT32      ulValue;    /* NORMAL, FAULT */
} AC_DEVM_GET_VAP_OPSTATE_RSP_T;

// 	������������ȡAC�豸ժҪ��Ϣ
// 	��������ṹ��
//�ޡ�
 //	��������ṹ��
typedef struct
{
	CHAR     	acAcDevName[32];      //�豸����
	CHAR	acAcNEId[32];		/* �豸����*/
	CHAR	acAcHostName[64];	/* �豸������*/
    	CHAR     	acAcDevType[32];      //�豸�ͺ�    	
	CHAR     	acAcDevSN[6];         	//�豸���кţ�λ�� /etc/gb
	UINT8    	aucResv1[2]; 	
	CHAR     	acAcSwVersion[32];    //�豸����汾
	CHAR     	acAcHwVersion[32];    //�豸Ӳ���汾
    	CHAR    	acAcCpuInfo[128];	   //CPU��Ϣ:CPU�ͺţ���Ƶ
    	CHAR     	acAcMemInfo[128];	   //�ڴ���Ϣ:RAM���ͣ�����
    	CHAR	acAcLocation[64];		/* �豸λ��*/
    	CHAR    	acAcManufacturer[128]; 	//�豸������ λ�� AC_HOME/c.dat
	CHAR     	acAcSwDeveloper[128];  	//���������
	
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
  	UINT32	ulAcRegWtpNum;		/* ע���AP��Ŀ*/
	UINT32   ulAcWtpNum;          //�����AP��Ŀ
	UINT32   ulAcStaNum;          //������û���Ŀ
	UINT32	ulAcPortalStaNum;		/* �����Portal��֤�û���*/
	UINT32	ulAcPPPoEStaNum;		/* �����PPPoE��֤�û���*/

	/*����Ϊ�˿�״̬��Ϣ*/     
	UINT32   ulEnetPortNum;             //��̫���˿���Ŀ
	AC_ENETPORT_INFO_T astEnetPort[AC_ENETPORT_NUM_MAX];
} AC_DEVM_ACDEVICE_ABSTRACT_T;

typedef struct 
{
	UINT32    ulRet;
	AC_DEVM_ACDEVICE_ABSTRACT_T		stAcDevice;
} AC_DEVM_GET_ACDEVICE_ABSTRACT_RSP_T;

/* ����AC��⵽��δע��AP */
typedef struct
{
	UINT32  	ulWtpId;      			//AP�豸ID
     	UINT8    	aucWtpIp[4];  		/* AP �豸IP */
		UINT8		aucSrcIp[4];		/* add by gwx 2014-10-17 ͨ�ŵ�ַ*/
		UINT32		ulSrcPort;			/* add by gwx 2014-10-17 ͨ�Ŷ˿�*/
     	UINT32   ulIpOrigin;   			// AP IP���÷�ʽ  
     	UINT8    	aucMac[6];         		/* AP �豸MAC */
     	UINT8    	aucResv0[2];  		/* ����ֽ�*/
     	UINT32  	ulWtpModel;   		//AP�豸�ͺ�
     	UINT8   	aucWtpSn[6];  		//AP�豸���к�
     	UINT8    	aucResv[2];
     	UINT32   ulDisType;    			// AC���ַ�ʽ
     	CHAR     	acSwVersion[32];		//AP ��ǰ����汾��
     	CHAR	acTargetVersion[32];   // AP�豸Ŀ������汾��
     	UINT32  	ulWtpState;   		//AP�豸״̬
     	UINT32	ulRejectReason;		/* �ܾ�����ԭ�� */
			                                 /*
			                                 1:�豸ID��һ��
			                                 2:���벻һ��
			                                 3:�豸�ͺŲ�һ��
			                                 4:�豸���кŲ�һ��
			                                 */
	UINT32   ulAcLanId;    /* AC �˿�
                       0-16����ʾLANx
                       >=16������ʾN/A*/
    	UINT32  ulBeginTime;        		//��״̬��ʼʱ��
    	UINT32  ulStatePeriod;      		//��״̬����ʱ��
     	UINT32  ulStaNum;           			//��ǰ�����û���
     	UINT32   ulStaAccNum;  			/* �û��������*/
    	UINT32  ulStaOnlineTime;    		/* �û�������ʱ��, ��λ���� */
     	UINT32   ulRegisterTime;			/*       ע��ʱ�� ���״����ӵ�AC��ʱ��*/
     	UINT32   ulLastConnTime;			/*       �ϴ�����ʱ�䣬���һ�ι���AC��ʱ��*/
     	UINT32   ulLastVerUpdateTime;   	/*       �ϴ������汾ʱ��   Oma֪ͨdbs*/
     	UINT32   ulLastCfgUpdateTime;   	/*       �ϴθ�������ʱ��   Oma֪ͨdbs */
	/* add by gwx 2014-3-26 for APһ��ע��begin*/
	UINT8	aucApMainDns[4];
	UINT8	aucApSlaveDns[4];
	CHAR	acAcURL[64];
	UINT8	aucWtpIpMask[4];
	UINT8	aucWtpDftGw[4];
	/* add by gwx 2014-3-26 for APһ��ע��end*/
}AC_DEVM_ADD_UNREGWTP_REQ_T;


typedef struct
{
	UINT32	ulRet;
}AC_DEVM_ADD_UNREGWTP_RSP_T;

/* ɾ��AC��⵽��δע��AP */
typedef struct
{
	UINT8   	aucWtpSn[6];  		//AP�豸���к�
     	UINT8    	aucResv[2];
}AC_DEVM_DEL_UNREGWTP_REQ_T;


typedef struct
{
	UINT32	ulRet;
}AC_DEVM_DEL_UNREGWTP_RSP_T;

/* 2010-1-18  ����: ��ȡAC�������� */
/* ��Σ��� */
/*  ���� */
typedef struct
{
	UINT32	ulRet;
	AC_DEVM_MSSETUP_CONFIG_T	stCfg;
} AC_DEVM_GET_MSSETUP_CONFIG_RSP_T;

/* ���ñ����豸����״̬*/
typedef struct
{
	UINT32	ulPeerAcState1;	/*�����豸1״̬ */
	UINT32	ulPeerAcState2;	/*�����豸2״̬ */
	UINT32	ulPeerAcState3;	/*�����豸3״̬ */
	UINT32	ulCurBakAcId;	/* ��ǰ�ӹܵ�AC��ID */
}AC_DEVM_SET_MSSTATE_REQ_T;

typedef struct
{
	UINT32	ulRet;
}AC_DEVM_SET_MSSTATE_RSP_T;
/* 2010-4-19 pyy ����: ��ȡָ��AP��Ŀ������汾��*/
typedef struct
{
	UINT32	ulWtpId;
}AC_DEVM_GET_WTP_TARGETVERSION_REQ_T;

typedef struct
{
	UINT32	ulRet;
	CHAR	acTargetVersion[32];   /* AP�豸Ŀ������汾��*/
}AC_DEVM_GET_WTP_TARGETVERSION_RSP_T;


/* 2010-3-1 ��ȡ��̫���ڵ�MOID */
typedef struct
{
	CHAR	acIfName[32];	/* �˿����� */
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

/* 	����VAPID��ȡAAA���������� */
typedef struct
{
	AC_VAPID_T	stVapId;
} AC_DEVM_GET_SSIDRADIUSSERVERS_REQ_T;


typedef struct
{
	UINT32	ulRet;
	AC_DEVM_RADIUS_SERVERS_T	stAAAServers;
} AC_DEVM_GET_SSIDRADIUSSERVERS_RSP_T;

/* 	�����ն�MAC��ȡAAA���������� */
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

/* 	��ȡ��Ȩ�������б� */
typedef struct
{
	UINT32	ulRet;
	UINT32	ulNum;

	AC_DEVM_RADIUS_AUTHSERVERS_T	astAuthServers[AC_DEVM_AUTHSERVERS_NUM_MAX];
}AC_DEVM_GET_AUTHSERVERS_RSP_T;


/* 	��ȡ�Ʒѷ������б� */
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


/* ����VAP BSSID */
typedef AC_DEVM_VAP_BSSID_T AC_DEVM_SET_VAPBSSID_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPBSSID_RSP_T;

/* ����VAP ����ͳ��*/
typedef AC_DEVM_VAP_TRAFFICSTAT_T AC_DEVM_SET_VAPTRAFFICSTAT_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPTRAFFICSTAT_RSP_T;

/* ����VAP WIFIͳ��*/
typedef AC_DEVM_VAP_WIFISTAT_T AC_DEVM_SET_VAPWIFISTAT_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VAPWIFISTAT_RSP_T;

/* ���������豸����书��*/
typedef AC_DEVM_VDEV_MAXPOWER_T  AC_DEVM_SET_VDEVMAXPOWER_REQ_T;

typedef struct
{
	UINT32	ulRet;
} AC_DEVM_SET_VDEVMAXPOWER_RSP_T;

/* ����ADHOC BSSID */
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
	UINT32		ulStartRec;		/* ��ѯ����ʼ��¼�� */
	/*
	��һ�ε���ʱ�����ulStartRec��0
	��������ʱ�����ulStartRec�ǰulStartRecֵ����ǰһ�ε��÷��ص�ulRecNum
	*/
}AC_DEVM_GET_WTPMAC_REQ_T;

#define AC_DEVM_WTPMAC_MAX	256
typedef struct
{
	UINT32	ulRet;
	UINT32	ulFinish;	/* ��ϵ�����м�¼�Ƿ��Ѷ�ȡ����
							AC_DB_TABLE_READ_NOTFINISH	δ����
							AC_DB_TABLE_READ_FINISH		��ȡ���� */
	UINT32	ulNum;
	AC_DEVM_WTPMAC_T	astWtpMac[AC_DEVM_WTPMAC_MAX];
} AC_DEVM_GET_WTPMAC_RSP_T;


typedef struct
{
	UINT32	ulRet;
	BOOL	bActive;	/* 	TRUE: ��ǰActive 
						FALSE: ��ǰStandby */
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
	UINT32    ulRet;        					/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
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
	UINT32	ulCommPort;	/* ͨѶ�˿ں�*/
	UINT8	aucCommIp[4];		/* ͨѶIP */
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
    UINT8   aucAcLinkIp[4];/*����AC��IP*/
}AC_DEVM_GET_ACLINKIP_RSP_T;

/* �����ӿ�����νṹ�嶨�����*/
/******************************************************************************/

/******************************************************************************/
/* ��Ϣ�ӿڽṹ�������*/
/* AC��ʶ������Ϣ�ṹ�嶨�� */
typedef struct{
    UINT32    ulAcId;    /* AC ID */
    AC_DEVM_ACFIRSTIP_CONFIG_T	stAcFirstIp;
} AC_DEVM_AC_UPDATE_IND_MSG_T;

/* AC�豸ϵͳ���ø�����Ϣ�ṹ�嶨��*/
typedef AC_DEVM_AC_OWNCONFIG_T AC_DEVM_AC_OWNCONFIG_UPDATE_IND_MSG_T;

/* 3A���ñ����Ϣ�ṹ�嶨��*/
typedef AC_DEVM_RADIUS_SERVERS_T	AC_DEVM_RADIUS_CONFIG_UPDATE_MSG_T;

// 	����������
//	AC������·������ñ��ʱ��DEVM����Ϣ֪ͨϵͳ����ģ��
// 	��Ϣ��ṹ��
typedef AC_DEVM_ACKEEPER_CONFIG_T AC_DEVM_ACKEEPERCFG_UPDATE_IND_MSG_T;


/* WTP�豸����֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_WTP_CONFIG_T    AC_DEVM_WTP_ADD_IND_MSG_T;

/* WTP�豸ɾ��֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_WTPID_T    AC_DEVM_WTP_DEL_IND_MSG_T;

/* WTP�豸�޸�֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_WTP_CONFIG_T    AC_DEVM_WTP_UPDATE_IND_MSG_T;

/* �����豸����֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_VDEV_CONFIG_T	AC_DEVM_VDEV_ADD_IND_MSG_T;

/* �����豸ɾ��֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_VDEVID_T	AC_DEVM_VDEV_DEL_IND_MSG_T;

/* �����豸�޸�֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_VDEV_CONFIG_T	AC_DEVM_VDEV_UPDATE_IND_MSG_T;

//	�����豸WIDS���ñ��֪ͨ��������
typedef struct {
	AC_VDEVID_T		stVdevId;
	AC_DEVM_VDEVWIDS_CONFIG_T 	stWidsCfg;
}AC_DEVM_VDEVWIDS_UPDATE_IND_MSG_T;

//	�����豸������Դ������������޸�֪ͨ��������
typedef struct 
{
	AC_VDEVID_T		stVdevId;
	AC_DEVM_VDEVRRM_CONFIG_T 	stRrmCfg;
}AC_DEVM_VDEVRRM_UPDATE_IND_MSG_T;

//	�����豸�ھ�����֪ͨ��������
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_ADD_IND_MSG_T;

//	�����豸�ھ�ɾ��֪ͨ��������
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_DEL_IND_MSG_T;

//	�����豸�ھӱ��֪ͨ��������
typedef struct 
{
	AC_VDEVID_T		stMyVdevId;
	AC_DEVM_VDEVNEIGH_CONFIG_T	stNeighCfg;
} AC_DEVM_VDEVNEIGH_UPDATE_IND_MSG_T;


/* �ӿ�����֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_IF_CONFIG_T    AC_DEVM_IF_ADD_IND_MSG_T;

/* �ӿ�ɾ��֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_IFID_T    AC_DEVM_IF_DEL_IND_MSG_T;

/* �ӿ��޸�֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_IF_CONFIG_T    AC_DEVM_IF_UPDATE_IND_MSG_T;

/* VAP ����֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_VAP_CONFIG_T    AC_DEVM_VAP_ADD_IND_MSG_T;

/* VAP ɾ��֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_VAPID_T    AC_DEVM_VAP_DEL_IND_MSG_T;

typedef struct
{
	AC_VAPID_T	stVapId;
	UINT32	ulTrafficMode;
} AC_DEVM_L2WVAP_DEL_IND_MSG_T;

/* VAP �޸�֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_VAP_CONFIG_T    AC_DEVM_VAP_UPDATE_IND_MSG_T;

/* ADHOC ����֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_ADD_IND_MSG_T;

/* ADHOC ɾ��֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_DEL_IND_MSG_T;

/* VAP �޸�֪ͨ��Ϣ�ṹ�嶨��*/
typedef AC_DEVM_ADHOC_CONFIG_T    AC_DEVM_ADHOC_UPDATE_IND_MSG_T;


/* VAP SSID���֪ͨ��Ϣ�ṹ�嶨��*/
typedef struct
{
	AC_VAPID_T	stVapId;
	CHAR	acSsid[32];
} AC_DEVM_VAPSSID_UPDATE_IND_MSG_T;


/* WTP����״̬���������Ϣ�ṹ�嶨�� */
typedef struct {
    AC_WTPID_T  stWtpId;
    UINT32  ulOpState;  /* ����״̬ */
    UINT32  ulReason;   /* ����WTP����״̬�仯��ԭ����: 
                           ��·״̬�仯
                           ����״̬�仯*/
} AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T;

/* VAP����״̬�仯֪ͨ��Ϣ�ṹ�嶨��*/
typedef struct
{
    AC_VAPID_T        stVapId;
    UINT32    ulAdminState;
} AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG_T;

/* VAP����״̬�仯֪ͨ��Ϣ�ṹ�嶨�� */
typedef struct
{
    AC_VAPID_T  stVapId;
    UINT32  ulOpState;
    UINT32  ulReason;   /* ����VAP����״̬�仯��ԭ����: 
                           ��·״̬�仯
                           ����״̬�仯 */
} AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T;

/* VAP BSSID(MAC��ַ)����֪ͨ��Ϣ�ṹ�嶨�� */
typedef AC_DEVM_VAP_BSSID_T AC_DEVM_VAP_MAC_CHG_IND_MSG_T;

// SNMPV2��������֪ͨ��������
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_ADD_IND_MSG_T;

// SNMP V2����ɾ��֪ͨ��������
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_DEL_IND_MSG_T;

// SNMP V2���ñ��֪ͨ��������
typedef AC_DEVM_SNMPV2_CONFIG_T AC_DEVM_SNMPV2_UPDATE_IND_MSG_T;

// SNMPV3��������֪ͨ��������
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_ADD_IND_MSG_T;

// SNMP V3����ɾ��֪ͨ��������
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_DEL_IND_MSG_T;

// SNMP V3���ñ��֪ͨ��������
typedef AC_DEVM_SNMPV3_CONFIG_T AC_DEVM_SNMPV3_UPDATE_IND_MSG_T;

/* SNMP TRAP��������֪ͨ(����)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_ADD_IND_MSG_T;

/* SNMP TRAP����ɾ��֪ͨ(����)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_DEL_IND_MSG_T;

/* SNMP TRAP���ñ��֪ͨ(����)*/
typedef AC_DEVM_SNMPTRAP_CONFIG_T	AC_DEVM_SNMPTRAP_UPDATE_IND_MSG_T;

/* 	AC SNTPȫ�����ñ��֪ͨ��������*/
typedef AC_DEVM_ACSNTP_CONFIG_T AC_DEVM_ACSNTPCONFIG_UPDATE_IND_MSG_T;

/* 	WTP SNTPȫ�����ñ��֪ͨ�������� */
typedef AC_DEVM_WTPSNTP_CONFIG_T AC_DEVM_WTPSNTPCONFIG_UPDATE_IND_MSG_T;

/* AC�˿�������֪ͨ��������*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_ADD_IND_MSG_T;

/* AC�˿���ɾ��֪ͨ��������*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_DEL_IND_MSG_T;

/*	AC�˿������ñ��֪ͨ��������*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_ACBRIDGE_UPDATE_IND_MSG_T;

/* 	AC����˿�����֪ͨ��������*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_ADD_IND_MSG_T;

/* 	AC����˿�ɾ��֪ͨ��������*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_DEL_IND_MSG_T;

/* 	AC����˿��޸�֪ͨ��������*/
typedef AC_DEVM_ACPORT_CONFIG_T		AC_DEVM_ACPORT_UPDATE_IND_MSG_T;

/* WTP Enet�˿�����֪ͨ*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_ADD_IND_MSG_T;

/* WTP Enet�˿�ɾ��֪ͨ*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_DEL_IND_MSG_T;

/* WTP Enet�˿��޸�֪ͨ*/
typedef AC_DEVM_ENET_CONFIG_T		AC_DEVM_WTPENET_UPDATE_IND_MSG_T;

//WAN�ڶ˿������޸�֪ͨ(����)
typedef struct
{
	CHAR	acIfName[32];	/* �˿����� */
}	AC_DEVM_WANIFNAME_CONFIG_UPDATE_IND_MSG_T;

/* 	����������AC LAN�˿�����������ʱ������Ϣ֪ͨ���ģ��*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_ADD_IND_MSG_T;

/*	AC LAN�˿���ɾ��֪ͨ��������*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_DEL_IND_MSG_T;

/*	AC LAN�˿������ñ��֪ͨ��������*/
typedef AC_DEVM_LANIF_CONFIG_T		AC_DEVM_LANIF_UPDATE_IND_MSG_T;

/* L2-WAN/FAT-LAN���ñ��֪ͨ*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_L2WAN_UPDATE_IND_MSG_T;

/* L3-WAN���ñ��֪ͨ*/
typedef AC_DEVM_BRIDGE_CONFIG_T		AC_DEVM_L3WAN_UPDATE_IND_MSG_T;

/* VLANȫ�����ñ��֪ͨ*/
typedef AC_DEVM_VLANGLOBAL_CONFIG_T	AC_DEVM_VLANGLOBAL_UPDATE_IND_MSG_T;

/* 	VLAN����֪ͨ��������*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_ADD_IND_MSG_T;

/* 	VLANɾ��֪ͨ��������*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_DEL_IND_MSG_T;

/* 	VLAN�������ñ��֪ͨ��������*/
typedef AC_DEVM_VLAN_CONFIG_T		AC_DEVM_VLAN_UPDATE_IND_MSG_T;

/* 	SSID -VLANӳ������֪ͨ��������*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_ADD_IND_MSG_T;

/* 	SSID -VLANӳ��ɾ��֪ͨ��������*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_DEL_IND_MSG_T;

/* 	SSID -VLANӳ�����ñ��֪ͨ��������*/
typedef AC_DEVM_VLANSSIDMAP_CONFIG_T		AC_DEVM_VLANSSIDMAP_UPDATE_IND_MSG_T;

/* 	�˿�-VLANӳ������֪ͨ��������*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_ADD_IND_MSG_T;

/* 	�˿�-VLANӳ��ɾ��֪ͨ��������*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_DEL_IND_MSG_T;

/* 	�˿�-VLANӳ�����ñ��֪ͨ��������*/
typedef AC_DEVM_VLANIFMAP_CONFIG_T		AC_DEVM_VLANIFMAP_UPDATE_IND_MSG_T;

/* 	MAC-VLANӳ������֪ͨ��������*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_ADD_IND_MSG_T;

/* 	MAC-VLANӳ��ɾ��֪ͨ��������*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_DEL_IND_MSG_T;

/* 	MAC-VLANӳ�����ñ��֪ͨ��������*/
typedef AC_DEVM_VLANMACMAP_CONFIG_T		AC_DEVM_VLANMACMAP_UPDATE_IND_MSG_T;

//	VLAN MAC��ַ���˲�������֪ͨ��������
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_ADD_IND_MSG_T;

//	VLAN MAC��ַ���˲���ɾ��֪ͨ��������
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_DEL_IND_MSG_T;

//	VLAN MAC��ַ���˲������ñ��֪ͨ��������
typedef AC_DEVM_VLANACCMACPOLICY_CONFIG_T		AC_DEVM_VLANACCMACPOLICY_UPDATE_IND_MSG_T;

//	VLAN�������MAC�б�����֪ͨ��������
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_ADD_IND_MSG_T;

//	VLAN�������MAC�б�ɾ��֪ͨ��������
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_DEL_IND_MSG_T;

//	VLAN�������MAC�б����ñ��֪ͨ��������
typedef AC_DEVM_VLANACCMAC_CONFIG_T		AC_DEVM_VLANACCMAC_UPDATE_IND_MSG_T;

//	IGMP Snooping���ñ��֪ͨ��������
typedef AC_DEVM_IGMPSNOOP_CONFIG_T		AC_DEVM_IGMPSNOOP_UPDATE_IND_MSG_T;

//IGMP Proxy���ñ��֪ͨ��������
typedef AC_DEVM_IGMPPROXY_CONFIG_T		AC_DEVM_IGMPPROXY_UPDATE_IND_MSG_T;

//	��̬·������֪ͨ��������
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_ADD_IND_MSG_T;

//	��̬·��ɾ��֪ͨ��������
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_DEL_IND_MSG_T;

//	��̬·�����ñ��֪ͨ��������
typedef AC_DEVM_ROUTESTATIC_CONFIG_T		AC_DEVM_ROUTESTATIC_UPDATE_IND_MSG_T;

//	RIPȫ�����ñ��֪ͨ��������
typedef AC_DEVM_RIPGLOBAL_CONFIG_T		AC_DEVM_RIPGLOBAL_UPDATE_IND_MSG_T;

//	RIPͨ����������֪ͨ��������
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_ADD_IND_MSG_T;

//	RIPͨ������ɾ��֪ͨ��������
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_DEL_IND_MSG_T;

//	RIPͨ���������ñ��֪ͨ��������
typedef AC_DEVM_RIPNOTIFYNET_CONFIG_T		AC_DEVM_RIPNOTIFYIP_UPDATE_IND_MSG_T;

//	����ǽȫ�����ñ��֪ͨ��������
typedef AC_DEVM_FWGLOBAL_CONFIG_T		AC_DEVM_FWGLOBAL_UPDATE_IND_MSG_T;

//	����ǽ��������֪ͨ��������
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_ADD_IND_MSG_T;

//	����ǽ����ɾ��֪ͨ��������
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_DEL_IND_MSG_T;

//	����ǽ������֪ͨ��������
typedef AC_DEVM_FWRULE_CONFIG_T		AC_DEVM_FWRULE_UPDATE_IND_MSG_T;

/* NATȫ�����ñ��֪ͨ*/
typedef AC_DEVM_NATGLOBAL_CONFIG_T		AC_DEVM_NATGLOBAL_UPDATE_IND_MSG_T;

//	NAT��������֪ͨ��������
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_ADD_IND_MSG_T;

//	NAT����ɾ��֪ͨ��������
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_DEL_IND_MSG_T;

//	NAT���ñ��֪ͨ��������
typedef AC_DEVM_NAT_CONFIG_T		AC_DEVM_NAT_UPDATE_IND_MSG_T;

/* P2P�������Ʊ��֪ͨ*/
typedef AC_DEVM_FWL7MATCH_CONFIG_T	AC_DEVM_P2P_UPDATE_IND_MSG_T;

//	IDS�������ñ��֪ͨ��������
typedef AC_DEVM_IDSRULE_CONFIG_T		AC_DEVM_IDSRULE_UPDATE_IND_MSG_T;

//	IDS�������ñ��֪ͨ��������
 typedef AC_DEVM_IDSSTRY_CONFIG_T		AC_DEVM_IDSSTRY_UPDATE_IND_MSG_T;

//	DHCP for STA �������ñ��֪ͨ��������
typedef AC_DEVM_STADHCPGLOBAL_CONFIG_T		AC_DEVM_STADHCPGLOBAL_UPDATE_IND_MSG_T;

//	DHCP for STA ��̬��IP����֪ͨ��������
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_ADD_IND_MSG_T;

//	DHCP for STA ��̬��IPɾ��֪ͨ��������
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_DEL_IND_MSG_T;

//	DHCP for STA ��̬��IP���֪ͨ��������
typedef AC_DEVM_STADHCPSTATICIP_CONFIG_T		AC_DEVM_STADHCPSTATICIP_UPDATE_IND_MSG_T;

//	DHCP for STA ��̬IP��ַ������֪ͨ��������
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_ADD_IND_MSG_T;
 
//	DHCP for STA ��̬IP��ַ��ɾ��֪ͨ��������
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_DEL_IND_MSG_T;

//	DHCP for STA ��̬IP��ַ�ر��֪ͨ��������
typedef AC_DEVM_STADHCPDYNIP_CONFIG_T		AC_DEVM_STADHCPDYNIP_UPDATE_IND_MSG_T;

//	DHCP for AP �������ñ��֪ͨ��������
typedef AC_DEVM_APDHCPGLOBAL_CONFIG_T		AC_DEVM_APDHCPGLOBAL_UPDATE_IND_MSG_T;

//	DHCP for AP ��̬��IP����֪ͨ��������
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_ADD_IND_MSG_T;

//	DHCP for AP ��̬��IPɾ��֪ͨ��������
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_DEL_IND_MSG_T;

//	DHCP for AP ��̬��IP���֪ͨ��������
typedef AC_DEVM_APDHCPSTATICIP_CONFIG_T		AC_DEVM_APDHCPSTATICIP_UPDATE_IND_MSG_T;

//	DHCP for AP ��̬IP��ַ������֪ͨ��������
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_ADD_IND_MSG_T;
 
//	DHCP for AP ��̬IP��ַ��ɾ��֪ͨ��������
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_DEL_IND_MSG_T;

//	DHCP for AP ��̬IP��ַ�ر��֪ͨ��������
typedef AC_DEVM_APDHCPDYNIP_CONFIG_T		AC_DEVM_APDHCPDYNIP_UPDATE_IND_MSG_T;

//	QOSȫ�����ñ��֪ͨ��������
typedef AC_DEVM_QOSGLOBAL_CONFIG_T		AC_DEVM_QOSGLOBAL_UPDATE_IND_MSG_T;

//	�û�QOSȱʡ���ñ��֪ͨ��������
typedef AC_DEVM_QOSUSRDFT_CONFIG_T		AC_DEVM_QOSUSRDFT_UPDATE_IND_MSG_T;

//	VLAN QOS��������֪ͨ��������
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_ADD_IND_MSG_T;

//	VLAN QOS����ɾ��֪ͨ��������
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_DEL_IND_MSG_T;

//	VLAN Qos���ñ��֪ͨ��������
typedef AC_DEVM_QOSVLAN_CONFIG_T		AC_DEVM_QOSVLAN_UPDATE_IND_MSG_T;

//	SSID QOS��������֪ͨ��������
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_ADD_IND_MSG_T;

//	SSID QOS����ɾ��֪ͨ��������
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_DEL_IND_MSG_T;

//	SSID QOS���ñ��֪ͨ��������
typedef AC_DEVM_QOSSSID_CONFIG_T		AC_DEVM_QOSSSID_UPDATE_IND_MSG_T;

//	�澯��������֪ͨ��������
typedef AC_DEVM_ALARMFILTER_CONFIG_T	AC_DEVM_ALARMFILTER_ADD_IND_MSG_T;

//	�澯����ɾ��֪ͨ��������
typedef AC_DEVM_ALARMFILTER_CONFIG_T	AC_DEVM_ALARMFILTER_DEL_IND_MSG_T;

//	�澯���ñ��֪ͨ��������
typedef AC_DEVM_ALARMFILTER_CONFIG_T		AC_DEVM_ALARMFILTER_UPDATE_IND_MSG_T;

// �澯�������ñ��֪ͨ(����)
typedef AC_DEVM_ACALARMTHRESHOLD_CONFIG_T	AC_DEVM_ACALARMTHRESHOLD_UPDATE_IND_MSG_T;

//	���ܼ�����������֪ͨ��������
typedef AC_DEVM_PERFCOUNTER_CONFIG_T	AC_DEVM_PERFCOUNTER_ADD_IND_MSG_T;

//	���ܼ�������ɾ��֪ͨ��������
typedef AC_DEVM_PERFCOUNTER_CONFIG_T	AC_DEVM_PERFCOUNTER_DEL_IND_MSG_T;

//	���ܼ����������ñ��֪ͨ��������
typedef AC_DEVM_PERFCOUNTER_CONFIG_T		AC_DEVM_PERFCOUNTER_UPDATE_IND_MSG_T;

//	����汾���ñ��֪ͨ��������
typedef AC_DEVM_SWSVR_CONFIG_T		AC_DEVM_SWSVR_UPDATE_IND_MSG_T;

/* STP���ñ����Ϣ�ṹ�嶨��*/
 typedef AC_DEVM_STP_CONFIG_T		AC_DEVM_STP_UPDATE_IND_MSG_T;

/* PPPoE���������ñ��֪ͨ */
typedef AC_DEVM_PPPOESERVER_CONFIG_T		AC_DEVM_PPPOESERVER_UPDATE_IND_MSG_T;

typedef AC_DEVM_MACSERVER_CONFIG_T		AC_DEVM_MACSERVER_UPDATE_IND_MSG_T;

//	Portalȫ�����ñ��֪ͨ��������
typedef AC_DEVM_PORTAL_CONFIG_T		AC_DEVM_PORTAL_UPDATE_IND_MSG_T;

//	Portal����������֪ͨ��������
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_ADD_IND_MSG_T;

//	Portal������ɾ��֪ͨ��������
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_DEL_IND_MSG_T;

//	Portal���������ñ��֪ͨ��������
typedef AC_DEVM_WHITELIST_CONFIG_T		AC_DEVM_WHITELIST_UPDATE_IND_MSG_T;

/* �û�����ַ����������֪ͨ*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_ADD_IND_MSG_T;

/* �û�����ַ������ɾ��֪ͨ*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_DEL_IND_MSG_T;

/* �û�����ַ�����ñ��֪ͨ*/
typedef AC_DEVM_USERADDRBIND_CONFIG_T	AC_DEVM_USERADDRBIND_UPDATE_IND_MSG_T;

/* ����֤��ַ��������֪ͨ*/
typedef AC_DEVM_FREEADDR_CONFIG_T	AC_DEVM_FREEADDR_ADD_IND_MSG_T;

/* ����֤��ַ����ɾ��֪ͨ*/
typedef AC_DEVM_FREEADDR_CONFIG_T	AC_DEVM_FREEADDR_DEL_IND_MSG_T;

/* ����֤��ַ���ñ��֪ͨ*/
typedef struct
{
	AC_DEVM_FREEADDR_CONFIG_T	stOld;	/* ԭ����*/
	AC_DEVM_FREEADDR_CONFIG_T	stNew;	/* ��ǰ����*/
} AC_DEVM_FREEADDR_UPDATE_IND_MSG_T;

/* ����֤MAC����֪ͨ*/
typedef AC_DEVM_FREEMAC_CONFIG_T	AC_DEVM_FREEMAC_ADD_IND_MSG_T;

/* ����֤MACɾ��֪ͨ*/
typedef AC_DEVM_FREEMAC_CONFIG_T	AC_DEVM_FREEMAC_DEL_IND_MSG_T;

/* ����֤MAC���֪ͨ*/
typedef struct
{
	AC_DEVM_FREEMAC_CONFIG_T	stOld;
	AC_DEVM_FREEMAC_CONFIG_T	stNew;
}AC_DEVM_FREEMAC_UPDATE_IND_MSG_T;


/* ����֤SSID ��������֪ͨ*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_ADD_IND_MSG_T;

/* ����֤SSID ����ɾ��֪ͨ*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_DEL_IND_MSG_T;

/* ����֤SSID ���ñ��֪ͨ*/
typedef AC_DEVM_FREESSID_CONFIG_T	AC_DEVM_FREESSID_UPDATE_IND_MSG_T;

/* ����֤VLAN ��������֪ͨ*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_ADD_IND_MSG_T;

/* ����֤VLAN ����ɾ��֪ͨ*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_DEL_IND_MSG_T;

/* ����֤VLAN ���ñ��֪ͨ*/
typedef AC_DEVM_FREEVLAN_CONFIG_T	AC_DEVM_FREEVLAN_UPDATE_IND_MSG_T;

typedef struct 
{
	UINT32	ulFreeSwitch;	/* ȫ������֤����*/
} AC_DEVM_FREEGLOBAL_UPDATE_IND_MSG_T;

/* ������URL����֪ͨ*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_ADD_IND_MSG_T;

/* ������URLɾ��֪ͨ*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_DEL_IND_MSG_T;

/* ������URL���֪ͨ*/
typedef AC_DEVM_WHITEURL_CONFIG_T	AC_DEVM_WHITEURL_UPDATE_IND_MSG_T;


//	��־�������ñ��֪ͨ��������
typedef AC_DEVM_LOG_CONFIG_T		AC_DEVM_LOG_UPDATE_IND_MSG_T;

//	��־���������ñ��֪ͨ��������
typedef AC_DEVM_LOGSVR_CONFIG_T		AC_DEVM_LOGSVR_UPDATE_IND_MSG_T;

// 	����������AS���������ñ��ʱ������Ϣ֪ͨ���ģ��
// 	��Ϣ��ṹ��
typedef AC_DEVM_WAPIAS_CONFIG_T		AC_DEVM_WAPIAS_UPDATE_IND_MSG_T;

/* AP-AC�������ñ����Ϣ*/
typedef AC_DEVM_WTPASSO_CONFIG_T		AC_DEVM_WTPASSO_UPDATE_IND_MSG_T;

/* AP-AC����ɾ�������Ϣ*/
typedef AC_DEVM_WTPASSO_CONFIG_T		AC_DEVM_WTPASSO_DEL_IND_MSG_T;

/* 2010-1-18����: �������ñ��֪ͨ��Ϣ*/
typedef AC_DEVM_MSSETUP_CONFIG_T AC_DEVM_MSSETUP_UPDATE_IND_MSG_T;

typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_ADD_IND_MSG_T;			/* 	��Ȩ����������֪ͨ*/
typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_DEL_IND_MSG_T;			/*	��Ȩ������ɾ��֪ͨ*/
typedef AC_DEVM_RADIUS_AUTHSERVERS_T	AC_DEVM_AUTHSERVERS_UPDATE_IND_MSG_T;		/*	��Ȩ�������޸�֪ͨ*/

typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_ADD_IND_MSG_T;			/*	�Ʒѷ���������֪ͨ*/
typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_DEL_IND_MSG_T;			/*	�Ʒѷ�����ɾ��֪ͨ*/
typedef AC_DEVM_RADIUS_ACCTSERVERS_T	AC_DEVM_ACCTSERVERS_UPDATE_IND_MSG_T;		/*	�Ʒѷ������޸�֪ͨ*/

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

/* add by gwx 2013-8-16 for ��ҵ���ȼ��к󱾵�����*/
typedef  struct
{
	UINT32	ulRet;
	UINT32	ulNumber;		//Я����portal IP��������ഫ��8��IP��ַ
	UINT8	aaucPortalIp[AC_DEVM_MAX_PORTALIP_NUM][4];	//���portal IP��ַ
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

/* add by gwx 2014-8-7 begin �ŵ���̬�ϱ�begin*/
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


/* add by gwx 2014-8-7 begin �ŵ���̬�ϱ�end*/


/* ��Ϣ�ӿڽṹ�������*/
/******************************************************************************/

/******************************************************************************/

/**************************OMA�ṩ�Ľӿںͽṹ�嶨��*******************************/
/* �û�����󳤶� */
//#define AC_OMA_USER_NAME_LEN_MAX    32

/******************************************************************************/

#define AC_MAIN		0
#define AC_SLAVE	1

/***********************************����extern ******************************/

extern UINT32  ac_devm_vapbssid_host_to_net (AC_DEVM_VAP_BSSID_T *pstHostVapBssid, AC_DEVM_VAP_BSSID_T *pstNetVapBssid);
extern UINT32  ac_devm_vapbssid_net_to_host (AC_DEVM_VAP_BSSID_T *pstNetVapBssid, AC_DEVM_VAP_BSSID_T *pstHostVapBssid);
extern UINT32  ac_devm_vaptrafficstat_host_to_net (AC_DEVM_VAP_TRAFFICSTAT_T *pstHostVapStat, 
												AC_DEVM_VAP_TRAFFICSTAT_T *pstNetVapStat);
extern UINT32  ac_devm_vaptrafficstat_net_to_host (AC_DEVM_VAP_TRAFFICSTAT_T *pstNetVapStat, 
												AC_DEVM_VAP_TRAFFICSTAT_T *pstHostVapStat);

/* ��̬��Ϣ������ */
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
/******************************* ͷ�ļ����� **********************************/


