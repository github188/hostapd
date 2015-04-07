#ifndef OMC_SET_HANDLE_H
#define OMC_SET_HANDLE_H

/************************************************************************/
/* system	module                                                      */
/************************************************************************/
OMA_RET_E sysBasicSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysIpSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysKeeperSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysServerSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysSnmpSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysRadiusSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysLoadBalanceSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysLogSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysSntpSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysPPPoESetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E sysParaSetup_handle(unsigned long setType, void *req, unsigned long len);

/************************************************************************/
/* wifiDevice	module                                                  */
/************************************************************************/
OMA_RET_E wifiDeviceBasicSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceChanSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceRateSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDevicePowerSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceAdvancedSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceAlgorithmParam_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceWidsSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E wifiDeviceResSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

/************************************************************************/
/* ap	module		                                                    */
/************************************************************************/
OMA_RET_E apBasicSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E apSecuritySetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E apAdvancedSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E apMacFilterSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

/************************************************************************/
/* adhoc	module                                                      */
/************************************************************************/
OMA_RET_E adhocBasicSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E adhocSecuritySetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

/************************************************************************/
/* enet	module															*/
/************************************************************************/
OMA_RET_E enetBasicSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

/************************************************************************/
/* router	module		                                                */
/************************************************************************/
OMA_RET_E routeNodeSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E routeNeighborSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E routeHandoverSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E routeDeviceMscSetup_handle(unsigned long setType, void *req, unsigned long len);

/************************************************************************/
/* vlan	module		                                                */
/************************************************************************/
OMA_RET_E vlan_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E vlanIpMap_handle(unsigned long setType, void *req, unsigned long len);

/************************************************************************/
/* acl	module			                                                */
/************************************************************************/

OMA_RET_E aclPolicySwitch_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E ipForwardSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E aclSetup_handle(unsigned long setType, void *req, unsigned long len);

OMA_RET_E tcpOptimiSetup_handle(unsigned long setType, void *req, unsigned long len);

/************************************************************************/
/* fcl	module			                                                */
/************************************************************************/

OMA_RET_E routefclSetup_handle(unsigned long setType, void *req, unsigned long len);

/*
*
*	capWapSetup
*
*/
OMA_RET_E capWapSetup_handle(unsigned long setType, void *req, unsigned long len);


/************************************************************************/
/*		sta	module                                                      */
/************************************************************************/
OMA_RET_E staBasicSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E staSecuritySetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E staAdvancedSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E staBssidSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);

OMA_RET_E perfSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);
OMA_RET_E alarmFilterSetup_handle(unsigned long setType, void *req, unsigned long len, unsigned long subIndex);
OMA_RET_E alarmThresholdSetup_handle(unsigned long setType, void *req, unsigned long len);

#endif /* OMC_SET_HANDLE_H */



