/*#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "_omaCommon.h"
#include "tlv.h"
#include "tlv_func.h"
#include "agent_type.h"
*/
#ifndef AGENT_OID_H
#define AGENT_OID_H

/************************************** OID 宏定义****************************/

#define OID_ENTERPRISES                 1, 3, 6, 1, 4, 1
#define OID_GBCOM                       OID_ENTERPRISES, 28723
#define OID_GBCOM_AP                    OID_GBCOM, 1, 1         /* GBCOM.Bebehop.AP, 用于与OMC之间的接口 */
#define OID_GBCOM_AP_TLV                OID_GBCOM, 1, 6         /* GBCOM.Bebehop.APTLV，用于TLV存储 */
#define OID_GBCOM_AP_OPEN               OID_GBCOM, 1, 9         /* GBCOM.Bebehop.APOPEN，用于对外发布 */

#define TLV_OID_sysSetup                OID_GBCOM_AP_TLV, 1     /* 系统配置 */

#define TLV_OID_sysBasicSetup           TLV_OID_sysSetup, 1     /* 基本配置 */
#define TLV_OID_sysIpSetup              TLV_OID_sysSetup, 2     /* IP配置 */
#define TLV_OID_sysKeeperSetup          TLV_OID_sysSetup, 3     /* 守护配置 */
#define TLV_OID_sysSwServerSetup        TLV_OID_sysSetup, 4     /* 软件版本配置 */
#define TLV_OID_sysSnmpSetup            TLV_OID_sysSetup, 5     /* SNMP配置 */
#define TLV_OID_sysSnmpV2Table          TLV_OID_sysSetup, 6     /* SNMP V2配置 */
#define TLV_OID_sysSnmpV3Table          TLV_OID_sysSetup, 7     /* SNMP V3配置 */
#define TLV_OID_sysSntpSetup            TLV_OID_sysSetup, 8     /* SNTP配置 */

#define TLV_OID_sysVersionSetup         OID_GBCOM_AP_TLV, 21    /* 版本信息 */
#define TLV_OID_sysPassword             OID_GBCOM_AP_TLV, 22    /* 密码 */
#define TLV_OID_sysPeriodOfValidity     OID_GBCOM_AP_TLV, 26    /* 有效期检查 */
#define TLV_OID_cfgActivation           OID_GBCOM_AP_TLV, 27    /* 配置生效设置 */

#define TLV_OID_wifiDevice              OID_GBCOM_AP_TLV, 30    /* 无线设备配置 */
#define TLV_OID_apVap                   OID_GBCOM_AP_TLV, 31    /* apVap配置 */
#define TLV_OID_adhocVap                OID_GBCOM_AP_TLV, 32    /* adhocVap配置 */
#define TLV_OID_enet                    OID_GBCOM_AP_TLV, 33    /* ENET配置 */
#define TLV_OID_route                   OID_GBCOM_AP_TLV, 34    /* route 配置 */
#define TLV_OID_vlanSetup               OID_GBCOM_AP_TLV, 35    /* VLAN 配置 */

#define TLV_OID_acl                     OID_GBCOM_AP_TLV, 40
#define TLV_OID_fcl                     OID_GBCOM_AP_TLV, 41    /* 流控配置 */
#define TLV_OID_ipForwardSetup          OID_GBCOM_AP_TLV, 42    /* IP转发 */
#define TLV_OID_tcpOptimizationSetup    OID_GBCOM_AP_TLV, 43    /* TCP优化 */

#define TLV_OID_perf                    OID_GBCOM_AP_TLV, 50    /* 性能统计配置 */
#define TLV_OID_alarm                   OID_GBCOM_AP_TLV, 52
#define TLV_OID_dynaInfo                OID_GBCOM_AP_TLV, 54

#define TLV_OID_capwap                  OID_GBCOM_AP_TLV, 60    /* AC capwap配置 */

#define TLV_OID_staVap                  OID_GBCOM_AP_TLV, 70    /* staVap配置 */
#define TLV_OID_vlanMapSetup            OID_GBCOM_AP_TLV, 71    /* vlan Map配置 */


#define TLV_OID_sysSnmpV2                                   TLV_OID_sysSnmpV2Table, 1

#define TLV_OID_sysSnmpV3                                   TLV_OID_sysSnmpV3Table, 1

/* wifiDevice */
#define TLV_OID_wifiDeviceId                                TLV_OID_wifiDevice, 1
#define TLV_OID_wifiDeviceBasic                             TLV_OID_wifiDevice, 2
#define TLV_OID_wifiDeviceChannel                           TLV_OID_wifiDevice, 3
#define TLV_OID_wifiDeviceRate                              TLV_OID_wifiDevice, 4
#define TLV_OID_wifiDevicePower                             TLV_OID_wifiDevice, 5
#define TLV_OID_wifiDeviceAdvanced                          TLV_OID_wifiDevice, 6
#define TLV_OID_wifiDeviceWIDS                              TLV_OID_wifiDevice, 7

/* apVap */
#define TLV_OID_apVapId                                     TLV_OID_apVap, 1
#define TLV_OID_apBasicSetup                                TLV_OID_apVap, 2
#define TLV_OID_apSecuritySetup                             TLV_OID_apVap, 3
#define TLV_OID_apAdvancedSetup                             TLV_OID_apVap, 4
#define TLV_OID_apMacFilterSetup                            TLV_OID_apVap, 5

/* adhocVap */
#define TLV_OID_adhocVapId                                  TLV_OID_adhocVap, 1
#define TLV_OID_adhocBasicSetup                             TLV_OID_adhocVap, 2
#define TLV_OID_adhocSecuritySetup                          TLV_OID_adhocVap, 3

#define TLV_OID_enetInfo                                    TLV_OID_enet, 1, 1

#define TLV_OID_routeBasic                                  TLV_OID_route, 1
#define TLV_OID_routeNeigh                                  TLV_OID_route, 2
#define TLV_OID_routeHandover                               TLV_OID_route, 3
#define TLV_OID_routeMsc                                    TLV_OID_route, 4

#define TLV_OID_vlan                                        TLV_OID_vlanSetup, 1, 1

#define TLV_OID_aclBasic                                    TLV_OID_acl, 1
#define TLV_OID_aclPolicy                                   TLV_OID_acl, 2
#define TLV_OID_aclPolicyEntry                              TLV_OID_acl, 3, 1

#define TLV_OID_fclBasic                                    TLV_OID_fcl, 1

#define TLV_OID_perfCounterGroup                            TLV_OID_perf, 1, 1

/* staVap */
#define TLV_OID_staVapId                                    TLV_OID_staVap, 1
#define TLV_OID_staBasicSetup                               TLV_OID_staVap, 2
#define TLV_OID_staAdvancedSetup                            TLV_OID_staVap, 3
#define TLV_OID_staSecuritySetup                            TLV_OID_staVap, 4
#define TLV_OID_staBindBssidSetup                           TLV_OID_staVap, 5

/* vlan map */
#define TLV_OID_vlanIpMap                                   TLV_OID_vlanMapSetup, 1

/************************************** OID 变量******************************/

#endif
