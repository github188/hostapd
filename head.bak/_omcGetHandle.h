#ifndef OMC_GET_HANDLE_H
#define OMC_GET_HANDLE_H

/************************************************************************/
/* system	module                                                      */
/************************************************************************/
OMA_RET_E sysBasicSetup_get_handle(void *data);

OMA_RET_E sysIpSetup_get_handle(void *data);

OMA_RET_E sysKeeperSetup_get_handle(void *data);

OMA_RET_E sysServerSetup_get_handle(void *data);

OMA_RET_E sysSnmpSetup_get_handle(void *data);

OMA_RET_E sysRadiusSetup_get_handle(void *data);

OMA_RET_E sysLoadBalanceSetup_get_handle(void *data);

OMA_RET_E sysSnmpSetup_get_handle(void *data);

OMA_RET_E sysRadiusSetup_get_handle(void *data);

OMA_RET_E sysLoadBalanceSetup_get_handle(void *data);

OMA_RET_E sysLogSetup_get_handle(void *data);

OMA_RET_E sysSntpSetup_get_handle(void *data);

OMA_RET_E sysPPPoESetup_get_handle(void *data);

OMA_RET_E sysParaSetup_get_handle(void *data);

/************************************************************************/
/* wifiDevice	module                                                  */
/************************************************************************/
OMA_RET_E wifiDeviceBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceChanSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceRateSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDevicePowerSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceAdvancedSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceAlgorithmParam_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceWidsSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E wifiDeviceResSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

/************************************************************************/
/* ap	module		                                                    */
/************************************************************************/
OMA_RET_E apBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E apSecuritySetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E apAdvancedSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E apMacFilterSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

/************************************************************************/
/* adhoc	module                                                      */
/************************************************************************/
OMA_RET_E adhocBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E adhocSecuritySetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

/************************************************************************/
/* enet	module															*/
/************************************************************************/
OMA_RET_E enetBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

/************************************************************************/
/* router	module		                                                */
/************************************************************************/
OMA_RET_E routeBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E routeNeighborSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E routeHandoverSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E routeDeviceMscSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

/************************************************************************/
/* vlan	module		                                                */
/************************************************************************/
OMA_RET_E vlan_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E vlanIpMap_get_handle(void *data);

/************************************************************************/
/* acl	module			                                                */
/************************************************************************/

OMA_RET_E aclPolicySwitch_get_handle(void *data);

OMA_RET_E aclSetupEntry_get_handle(void *data);

OMA_RET_E routefclSetup_get_handle(void *data);

OMA_RET_E capWapSetup_get_handle(void *data);

OMA_RET_E ipForwardSwitch_get_handle(void *data);

OMA_RET_E tcpOptimiSetup_get_handle(void *data);

/************************************************************************/
/* sta	module		                                                    */
/************************************************************************/
OMA_RET_E staBasicSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E staSecuritySetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E staAdvancedSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

OMA_RET_E staBssidSetup_get_handle(void *data, unsigned long *objectIndex, unsigned long *objectNum);

#endif /* OMC_GET_HANDLE_H */



