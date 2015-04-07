#include "includes.h"
#include "hostapd.h"
#include "radius.h"
#include "radius_client.h"
#include "eloop.h"
#include "hostapd_test.h"
#include "radius_alive.h"
#include "mac_auth.h"

#include "OssApi.h"
#include "ac_public.h"
#include "ac_db_kernel.h"
#include "ac_db_table.h"
#include "ac_usrm_public.h"
#include "ac_devm_public.h"
#include "ac_db_proc.h"

#include "ac_pa_public.h"
#include "ppp.h"
#include "crypto.h"

extern struct hostapd_radius_servers g_stRadiusServers ;
extern struct hostapd_data * FindVap(u16 usWtpId, u32 ulInterfaceId, u32 ulVapId) ;

#if 0
static void hostapd_test_set_radius_servers_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_RADIUS_SERVERS_T stRadiusServersCfg ;
	UINT8 ip[4] = {10, 1, 8, 79} ;
	char * pSecret = "123456" ;
	TPID stReceiver = {0} ;
	memset(&stRadiusServersCfg,0,sizeof(stRadiusServersCfg));

	memcpy(stRadiusServersCfg.stAuthSrvMaster.aucIp, ip, sizeof(ip)) ;
	stRadiusServersCfg.stAuthSrvMaster.ulPort = 1812 ;
	memcpy(stRadiusServersCfg.stAuthSrvMaster.acSecret, pSecret, 32) ;

	VmSelfPid(& stReceiver) ;
	VmASend(AC_DEVM_RADIUS_CONFIG_UPDATE_IND_MSG, (BYTE *)& stRadiusServersCfg, sizeof(stRadiusServersCfg), stReceiver) ;
}

static unsigned int hostapd_set_radius_servers(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	eloop_register_timeout(start ++, 0, hostapd_test_set_radius_servers_timeout, NULL, NULL) ;

	return start ;
}

static void hostapd_test_wtp_add_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_WTP_ADD_IND_MSG_T stWtpAdd ;
	AC_WTPID_T * pstWtpId = NULL ;
	CHAR acWtpName[] = "WTP" ;
	UINT8 aucIp[4] = {192, 168, 4, 1} ;
	TPID stTpid ;

	if((pstWtpId = eloop_ctx) == NULL)
		return ;

	os_memcpy(& stWtpAdd.stWtpBasic.stWtpId, pstWtpId, sizeof(AC_WTPID_T)) ;
	os_memcpy(stWtpAdd.stWtpBasic.acWtpName, acWtpName, sizeof(acWtpName)) ;
	os_memcpy(stWtpAdd.stWtpIp.aucIp, aucIp, sizeof(aucIp)) ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_WTP_ADD_IND_MSG, (BYTE *)& stWtpAdd, sizeof(stWtpAdd), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_wtp_delete_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_WTP_DEL_IND_MSG_T * pstWtpDelete = NULL ;
	TPID stTpid ;

	if((pstWtpDelete = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_WTP_DEL_IND_MSG, (BYTE *)pstWtpDelete, sizeof(* pstWtpDelete), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_if_add_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_IF_ADD_IND_MSG_T stIfAdd ;
	AC_IFID_T * pstIfId = NULL ;
	TPID stTpid ;

	if((pstIfId = eloop_ctx) == NULL)
		return ;

	os_memcpy(& stIfAdd.stIfId, pstIfId, sizeof(AC_IFID_T)) ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_IF_ADD_IND_MSG, (BYTE *)& stIfAdd, sizeof(stIfAdd), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_if_delete_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_IF_DEL_IND_MSG_T * pstIfDelete = NULL ;
	TPID stTpid ;

	if((pstIfDelete = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_IF_DEL_IND_MSG, (BYTE *)pstIfDelete, sizeof(* pstIfDelete), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_vap_add_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_ADD_IND_MSG_T stVapAdd ;
	AC_VAPID_T * pstVapId = NULL ;
	TPID stTpid ;

	if((pstVapId = eloop_ctx) == NULL)
		return ;

	os_memset(& stVapAdd, 0, sizeof(stVapAdd)) ;
	os_memcpy(stVapAdd.acSsid, "ap0_yey", 8) ;
	os_memcpy(& stVapAdd.stVapId, pstVapId, sizeof(AC_VAPID_T)) ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_ADD_IND_MSG, (BYTE *)& stVapAdd, sizeof(stVapAdd), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_vap_delete_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_DEL_IND_MSG_T * pstVapDelete = NULL ;
	TPID stTpid ;

	if((pstVapDelete = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_DEL_IND_MSG, (BYTE *)pstVapDelete, sizeof(* pstVapDelete), stTpid) ;

	os_free(eloop_ctx) ;
}

/*
 功能：增加WTP设备测试
	1）增加合法WTP设备测试
	2）增加非法WTP设备测试：设备编号过小无效
	3）增加非法WTP设备测试：设备编号过大无效
	4）增加非法WTP设备测试：设备已存在
 测试程序运行条件：编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase1(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpId1 = NULL, * pstWtpId2 = NULL, * pstWtpId3 = NULL, * pstWtpId4 = NULL ;
	AC_WTPID_T * pstWtpIdTmp1 = NULL ;
	unsigned int start = sec_start ;

	/*1*/
	pstWtpId1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpId1, NULL) ;

	/*2*/
	pstWtpId2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId2->ulWtpId = AC_WTPID_MIN - 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpId2, NULL) ;

	/*3*/
	pstWtpId3 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId3->ulWtpId = AC_WTPID_MAX + 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpId3, NULL) ;

	/*4*/
	pstWtpId4 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId4->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpId4, NULL) ;

	/*恢复数据*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp1, pstWtpId1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp1, NULL) ;

	return start ;
}

/*
 功能：删除WTP设备测试
 	1）删除WTP设备测试：WTP下无任何单卡
 	2）删除WTP设备测试：WTP下任在多个单卡及VAP
 	3）删除非法WTP设备：设备编号过小无效
 	4）删除非法WTP设备：设备编号过大无效
 	5）删除非法WTP设备：设备不存在
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase2(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpId1 = NULL, * pstWtpId3 = NULL, * pstWtpId4 = NULL, * pstWtpId5 = NULL ;
	AC_WTPID_T * pstWtpIdTmp1 = NULL ;
	unsigned int start = sec_start ;

	/*创建测试数据*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*1*/
	pstWtpId1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpId1, NULL) ;

	/*2*/
	/*可在其它测试用例中测试*/

	/*3*/
	pstWtpId3 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId3->ulWtpId = AC_WTPID_MIN - 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpId3, NULL) ;

	/*4*/
	pstWtpId4 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId4->ulWtpId = AC_WTPID_MAX + 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpId4, NULL) ;

	/*5*/
	pstWtpId5= os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpId5->ulWtpId = AC_WTPID_MAX - 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpId5, NULL) ;

	return start ;
}

/*
 功能：增加IF设备测试
 	1）要增加的IF所在的WTP设备不存在；
 	2）合法增加IF测试；
 	3）要增加的IF已经存在；
 	4）IF所在的设备存储IF设备已满；
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase3(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL, * pstWtpIdTmp2 = NULL ;
	AC_IFID_T * pstIfId1 = NULL, * pstIfId2 = NULL, * pstIfId3 = NULL, * pastIfId4[MAX_INTERFACES] ;
	unsigned int start = sec_start , i ;

	/*1*/
	pstIfId1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId1->ulWtpId = AC_WTPID_MAX ;
	pstIfId1->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfId1, NULL) ;

	/*创建测试数据*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*2*/
	pstIfId2 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId2->ulWtpId = AC_WTPID_MAX ;
	pstIfId2->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfId2, NULL) ;

	/*3*/
	pstIfId3 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId3->ulWtpId = AC_WTPID_MAX ;
	pstIfId3->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfId3, NULL) ;

	/*4*/
	for(i = 0 ; i < MAX_INTERFACES ; i ++){
		pastIfId4[i] = os_zalloc(sizeof(AC_IFID_T)) ;
		pastIfId4[i]->ulWtpId = AC_WTPID_MAX ;
		pastIfId4[i]->ulIfId = i ;
		eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pastIfId4[i], NULL) ;
	}

	/*恢复数据：删除带IF设备的WTP设备*/
	pstWtpIdTmp2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp2, pstWtpIdTmp1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp2, NULL) ;

	return start ;
}

/*
 功能：删除IF设备测试
 	1）要删除的IF设备所在的WTP设备不存在；
 	2）要删除的IF设备不存在；
 	3）删除合法IF设备，不带VAP设备；
 	4）删除合法IF设备，带VAP设备；
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase4(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL, * pstWtpIdTmp2 = NULL ;
	AC_IFID_T * pstIfId1 = NULL, * pstIfId2 = NULL, * pstIfId3 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	unsigned int start = sec_start ;

	/*1*/
	pstIfId1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId1->ulWtpId = AC_WTPID_MAX ;
	pstIfId1->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_delete_timeout, pstIfId1, NULL) ;

	/*创建测试数据:WTP*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*2*/
	pstIfId2 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId2->ulWtpId = AC_WTPID_MAX ;
	pstIfId2->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_delete_timeout, pstIfId2, NULL) ;

	/*创建测试数据:IF*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX ;
	pstIfIdTmp1->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*3*/
	pstIfId3 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfId3->ulWtpId = AC_WTPID_MAX ;
	pstIfId3->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_delete_timeout, pstIfId3, NULL) ;

	/*4*/
	/*可在其它测试用例中测试*/

	/*恢复数据*/
	pstWtpIdTmp2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp2, pstWtpIdTmp1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp2, NULL) ;

	return start ;
}

/*
 功能：增加VAP测试
 	1）要增加的VAP设备所在的WTP设备不存在；
 	2）要增加的VAP设备所在的IF设备不存在；
 	3）增加合法VAP设备；
 	4）要增加的VAP设备已存在；
 	5）要增加的VAP设备所在的IF设备已满；
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase5(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL , * pstWtpIdTmp2 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_VAPID_T * pstVap1 = NULL, * pstVap2 = NULL, * pstVap3 = NULL, * pstVap4 = NULL, * pastVap5[MAX_BSSES] ;
	unsigned int start = sec_start, i ;

	/*1*/
	pstVap1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap1->ulWtpId = AC_WTPID_MAX ;
	pstVap1->ulIfId = 1000 ;
	pstVap1->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pstVap1, NULL) ;

	/*创建测试数据：WTP*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*2*/
	pstVap2= os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap2->ulWtpId = AC_WTPID_MAX ;
	pstVap2->ulIfId = 1000 ;
	pstVap2->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pstVap2, NULL) ;

	/*创建测试数据:IF*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX ;
	pstIfIdTmp1->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*3*/
	pstVap3= os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap3->ulWtpId = AC_WTPID_MAX ;
	pstVap3->ulIfId = 1000 ;
	pstVap3->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pstVap3, NULL) ;

	/*4*/
	pstVap4= os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap4->ulWtpId = AC_WTPID_MAX ;
	pstVap4->ulIfId = 1000 ;
	pstVap4->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pstVap4, NULL) ;

	/*5*/
	for(i = 0 ; i < MAX_BSSES ; i ++){
		pastVap5[i]= os_zalloc(sizeof(AC_VAPID_T)) ;
		pastVap5[i]->ulWtpId = AC_WTPID_MAX ;
		pastVap5[i]->ulIfId = 1000 ;
		pastVap5[i]->ulVapId = i ;
		eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pastVap5[i], NULL) ;
	}

	/*恢复数据*/
	pstWtpIdTmp2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp2, pstWtpIdTmp1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp2, NULL) ;

	return start ;
}

/*
 功能：删除VAP测试
 	1）要删除的VAP所在的WTP设备不存在；
 	2）要删除的VAP所在的IF设备不存在；
 	3）要删除的VAP设备不存在；
 	4）删除合法VAP设备；
  测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_device_testcase6(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL , * pstWtpIdTmp2 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_VAPID_T * pstVap1 = NULL, * pstVap2 = NULL, * pstVap3 = NULL, * pstVap4 = NULL ;
	AC_VAPID_T * pstVapTmp1 = NULL ;
	unsigned int start = sec_start ;

	/*1*/
	pstVap1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap1->ulWtpId = AC_WTPID_MAX ;
	pstVap1->ulIfId = 1000 ;
	pstVap1->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVap1, NULL) ;

	/*创建测试数据：WTP*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*2*/
	pstVap2 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap2->ulWtpId = AC_WTPID_MAX ;
	pstVap2->ulIfId = 1000 ;
	pstVap2->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVap2, NULL) ;

	/*创建测试数据:IF*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX ;
	pstIfIdTmp1->ulIfId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*3*/
	pstVap3 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap3->ulWtpId = AC_WTPID_MAX ;
	pstVap3->ulIfId = 1000 ;
	pstVap3->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVap3, NULL) ;

	/*创建测试数据:VAP*/
	pstVapTmp1= os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVapTmp1->ulWtpId = AC_WTPID_MAX ;
	pstVapTmp1->ulIfId = 1000 ;
	pstVapTmp1->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_add_timeout, pstVapTmp1, NULL) ;

	/*4*/
	pstVap4 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVap4->ulWtpId = AC_WTPID_MAX ;
	pstVap4->ulIfId = 1000 ;
	pstVap4->ulVapId = 1000 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVap4, NULL) ;

	/*恢复数据*/
	pstWtpIdTmp2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp2, pstWtpIdTmp1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp2, NULL) ;

	return start ;
}

/*
 功能：增删WTP/IF/VAP测试；
*/
static unsigned int hostapd_device_tests(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	//start = hostapd_device_testcase1(start) ;
	//start = hostapd_device_testcase2(start) ;
	//start = hostapd_device_testcase3(start) ;
	//start = hostapd_device_testcase4(start) ;
	//start = hostapd_device_testcase5(start) ;
	//start = hostapd_device_testcase6(start) ;

	return start ;
}

static void hostapd_test_if_config_new_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_IF_ADD_IND_MSG_T * pstIfAdd = NULL ;
	TPID stTpid ;

	if((pstIfAdd = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_IF_ADD_IND_MSG, (BYTE *)pstIfAdd, sizeof(AC_DEVM_IF_ADD_IND_MSG_T), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_if_config_change_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_IF_UPDATE_IND_MSG_T * pstIfUpdate = NULL ;
	TPID stTpid ;

	if((pstIfUpdate = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_IF_UPDATE_IND_MSG, (BYTE *)pstIfUpdate, sizeof(AC_DEVM_IF_UPDATE_IND_MSG_T), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_vap_config_new_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_ADD_IND_MSG_T * pstVapAdd = NULL ;
	TPID stTpid ;

	if((pstVapAdd = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_ADD_IND_MSG,(BYTE *) pstVapAdd, sizeof(AC_DEVM_VAP_ADD_IND_MSG_T), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_vap_config_change_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_UPDATE_IND_MSG_T * pstVapUpdate = NULL ;
	TPID stTpid ;

	if((pstVapUpdate = eloop_ctx) == NULL)
		return ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_UPDATE_IND_MSG, (BYTE *)pstVapUpdate, sizeof(AC_DEVM_VAP_UPDATE_IND_MSG_T), stTpid) ;

	os_free(eloop_ctx) ;
}

/*
 功能：新增IF设备导入配置测试
 	1）导入合法配置测试
*/
static unsigned int hostapd_config_testcase1(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	return start ;
}

/*
 功能：修改IF设备配置测试
 	1）合法修改配置测试
*/
static unsigned int hostapd_config_testcase2(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	return start ;
}

/*
 功能：新增VAP设备导入配置测试
 	1）新增配置：SSID非法
 	2）新增配置：WPA KEY非法
 	3）新增配置：8021x EAPOL版本非法
 	4）新增配置：WEP KEY ID非法
 	5）新增配置：WEP KEY 长度非法
 	6）新增配置：支持802.1x但未配置RADIUS SERVER
 	7）新增配置：
 	8）新增合法配置；
  测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_config_testcase3(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL, * pstWtpIdTmp2 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVapAdd, * pstVapAdd1, * pstVapAdd2, * pstVapAdd3, * pstVapAdd4, * pstVapAdd5, * pstVapAdd6, * pstVapAdd8;
	unsigned char mac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06} ;
	unsigned int start = sec_start ;

	os_memset(& stVapAdd, 0, sizeof(stVapAdd)) ;

	stVapAdd.stVapId.ulWtpId = AC_WTPID_MAX ;
	stVapAdd.stVapId.ulIfId = 0 ;
	stVapAdd.stVapId.ulVapId = 0 ;

	stVapAdd.ulOpMode = AC_VAP_OPMODE_AP ;

	os_memcpy(stVapAdd.acIfName, "ap0_1", 4) ;
	os_memcpy(stVapAdd.aucBssid, mac, 6) ;
	os_memcpy(stVapAdd.acSsid, "ap1_yey", 8) ;
	stVapAdd.ulSsidBroadcast = 1 ;

	stVapAdd.ulAuth = 16 ;
	stVapAdd.ulEncrypt = 0 ;
	os_memcpy(stVapAdd.acWpaKey, "www.gbcom.com.cn", 17) ;
	stVapAdd.ulWpaRekeyPeriod = 600 ;
	stVapAdd.ulWepKeyLen = 1 ;
	stVapAdd.ulInputFormat = 1 ;
	os_memcpy(stVapAdd.acWepKey, "0123456789", 11) ;
	stVapAdd.ulWepRekeyPeriod = 300 ;
	stVapAdd.ulWepKeyIndex = 1 ;
	stVapAdd.ul8021x = 1 ;
	stVapAdd.ulEapolVer = 2 ;
	stVapAdd.ulEapAuthPeriod = 150 ;

	/*创建测试数据:WTP*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*创建测试数据:IF*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX ;
	pstIfIdTmp1->ulIfId = 0 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*1*/
	pstVapAdd1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd1, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd1->acSsid[0] = '\0' ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd1, NULL) ;

	/*2*/
	pstVapAdd2 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd2, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd2->ulAuth = 8 ;
	pstVapAdd2->acWpaKey[7] = '\0' ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd2, NULL) ;

	/*3*/
	pstVapAdd3 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd3, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd3->ulEapolVer = 0 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd3, NULL) ;

	/*4*/
	pstVapAdd4 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd4, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd4->ulWepKeyIndex = 0 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd4, NULL) ;

	/*5*/
	pstVapAdd5 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd5, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd5->acWepKey[9] = '\0' ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd5, NULL) ;

	/*6*/
	pstVapAdd6 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd6, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd6->ulWepKeyLen = 13 ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd6, NULL) ;

	/*7*/

	/*8*/
	pstVapAdd8 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd8, & stVapAdd, sizeof(stVapAdd)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd8, NULL) ;

	/*恢复数据*/
	pstWtpIdTmp2 = os_zalloc(sizeof(AC_WTPID_T)) ;
	os_memcpy(pstWtpIdTmp2, pstWtpIdTmp1, sizeof(AC_WTPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_delete_timeout, pstWtpIdTmp2, NULL) ;

	return start ;
}

/*
 功能：修改VAP设备配置测试
*/
static unsigned int hostapd_config_testcase4(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	return start ;
}

/*
 功能：IF/VAP设备配置测试
*/
static unsigned int hostapd_config_tests(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	start = hostapd_config_testcase3(start) ;

	return start ;
}

static void hostapd_test_wtpopstate_normal_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_WTP_OPSTATE_CHG_IND_MSG_T stWtpOpstate ;
	TPID stTpid ;
	memset(&stWtpOpstate,0,sizeof(stWtpOpstate));

	stWtpOpstate.stWtpId.ulWtpId = (unsigned long)eloop_ctx ;
	stWtpOpstate.ulOpState = AC_OPSTATE_NORMAL ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_WTP_OPSTATE_CHG_IND_MSG, (BYTE *)& stWtpOpstate, sizeof(stWtpOpstate), stTpid) ;
}

static void hostapd_test_opstate_normal_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T stVapOpstate ;
	AC_VAPID_T * pstVapId = NULL ;
	TPID stTpid ;

	if((pstVapId = eloop_ctx) == NULL)
		return ;

	os_memcpy(& stVapOpstate.stVapId, pstVapId, sizeof(AC_VAPID_T)) ;
	stVapOpstate.ulOpState = AC_OPSTATE_NORMAL ;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_OPSTATE_CHG_IND_MSG, (BYTE *)& stVapOpstate, sizeof(stVapOpstate), stTpid) ;

	os_free(eloop_ctx) ;
}

static void hostapd_test_opstate_fault_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_OPSTATE_CHG_IND_MSG_T stVapOpstate ;
	AC_VAPID_T * pstVapId = NULL ;
	TPID stTpid ;

	if((pstVapId = eloop_ctx) == NULL)
		return ;

	os_memcpy(& stVapOpstate.stVapId, pstVapId, sizeof(AC_VAPID_T)) ;
	stVapOpstate.ulOpState = AC_OPSTATE_FAULT;

	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_OPSTATE_CHG_IND_MSG, (BYTE *)& stVapOpstate, sizeof(stVapOpstate), stTpid) ;

	os_free(eloop_ctx) ;
}

/*
 功能：VAP链路状态正常响应测试
 	1）第一次启动VAP，且该VAP为当前单卡上的第一个VAP；
 	2）第二次启动VAP；
 	3）启动不存在的VAP；
  	4）第一次启动VAP，且该VAP不是当前单卡上的第一个VAP；
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
 	2）存在编号为(1, 1, 0)的VAP设备；
 	3）不存在编号为(1, 1, 1)的VAP设备；
*/
static unsigned int hostapd_opstate_testcase1(unsigned int sec_start)
{
	AC_VAPID_T  * pstVapId4 = NULL ;
	struct hostapd_data * pstVap = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVap, * pstVap1 = NULL ;
	//AC_VAPID_T * pstVapIdTmp1 = NULL, * pstVapIdTmp2 = NULL ;
	//AC_DEVM_VAP_CONFIG_T * pstVapTmp1 = NULL ;
	unsigned char mac[6] = {0x06, 0x02, 0x6F, 0x49, 0xD1, 0xD1} ;
	unsigned int start = sec_start ;

	/*准备测试数据：VAP*/
	pstVap = FindVap(1, 1, 0) ;
	os_memcpy(pstVap->conf->iface, "ap0", 4) ;
#if 0
	/*1*/
	pstVapId1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVapId1->ulWtpId = pstVap->iface->pstWtp->usWtpId;
	pstVapId1->ulIfId = pstVap->iface->interface_id;
	pstVapId1->ulVapId = pstVap->vap_id;

	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId1, NULL) ;

	/*2*/
	pstVapId2 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVapId2->ulWtpId = pstVap->iface->pstWtp->usWtpId;
	pstVapId2->ulIfId = pstVap->iface->interface_id;
	pstVapId2->ulVapId = pstVap->vap_id;

	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId2, NULL) ;

	/*3*/
	pstVapId3 = os_zalloc(sizeof(AC_VAPID_T)) ;
	pstVapId3->ulWtpId = AC_WTPID_MAX ;
	pstVapId3->ulIfId = 0 ;
	pstVapId3->ulVapId = 0 ;

	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId3, NULL) ;
#endif
	/*VAP模板配置数据*/
	os_memset(& stVap, 0, sizeof(stVap)) ;

	stVap.stVapId.ulWtpId = pstVap->iface->pstWtp->usWtpId ;
	stVap.stVapId.ulIfId = pstVap->iface->interface_id ;
	stVap.stVapId.ulVapId = 1 ;

	os_memcpy(stVap.acIfName, "ap0_1", 6) ;
	os_memcpy(stVap.aucBssid, mac, 6) ;
	os_memcpy(stVap.acSsid, "ap1_hapd", 9) ;
	stVap.ulSsidBroadcast = 1 ;

	stVap.ulAuth = 4 ;
	stVap.ulEncrypt = 4 ;
	stVap.ulWpaRekeyPeriod = 86400 ;
#if 0
	os_memcpy(stVap.acWpaKey, "www.gbcom.com.cn", 17) ;
#endif

#if 0
	stVap.ulWepKeyIndex = 1 ;
	stVap.ulInputFormat = 1 ;
	os_memcpy(stVap.acWepKey, "0123456789", 11) ;
#endif

	stVap.ul8021x = 1 ;
	stVap.ulEapolVer = 2 ;
	stVap.ulEapAuthPeriod = 3600 ;
#if 0
	stVap.ulWepRekeyPeriod = 300 ;
	stVap.ulWepKeyLen = 1 ;
#endif
	/*创建测试数据:VAP*/
	pstVap1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVap1, & stVap, sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVap1, NULL) ;

	/*4*/
	pstVapId4 = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId4, & pstVap1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId4, NULL) ;
#if 0
	/*恢复数据*/
	pstVapIdTmp1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapIdTmp1, & pstVap1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVapIdTmp1, NULL) ;
#endif
#if 0
	pstVapIdTmp2 = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapIdTmp2, pstVapId1, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVapIdTmp2, NULL) ;
#endif

	return start ;
}

/*
 功能：VAP链路状态故障响应测试
 	1）VAP状态故障响应测试
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
*/
static unsigned int hostapd_opstate_testcase2(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	return start ;
}

/*
 功能：VAP链路状态正常/故障响应测试
*/
static unsigned int hostapd_opstate_tests(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	start = hostapd_opstate_testcase1(start) ;

	return start ;
}

/*
 功能：IOCTL数据发送测试
 测试程序运行条件：
 	1）编号为AC_WTPID_MAX的WTP设备不存在；
 	2）存在编号为(1/1)的IF设备；
*/
static unsigned int hostapd_ioctl_testcase1(unsigned int sec_start)
{
	AC_VAPID_T * pstVapId1 = NULL ;
	AC_VAPID_T * pstVapIdTmp1 = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVap, * pstVap1 = NULL ;
	unsigned char mac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06} ;
	unsigned int start = sec_start ;

	/*VAP模板配置数据*/
	os_memset(& stVap, 0, sizeof(stVap)) ;

	stVap.stVapId.ulWtpId = 1 ;
	stVap.stVapId.ulIfId = 1 ;
	stVap.stVapId.ulVapId = 7 ;

	os_memcpy(stVap.acIfName, "ap7", 4) ;
	os_memcpy(stVap.aucBssid, mac, 6) ;
	os_memcpy(stVap.acSsid, "ap7_test", 8) ;
	stVap.ulSsidBroadcast = 1 ;

	stVap.ulAuth = 0 ;
	stVap.ulEncrypt = 0 ;
	os_memcpy(stVap.acWpaKey, "www.gbcom.com.cn", 17) ;
	stVap.ulWpaRekeyPeriod = 600 ;
	stVap.ulWepKeyLen = 1 ;
	stVap.ulInputFormat = 1 ;
	os_memcpy(stVap.acWepKey, "0123456789", 11) ;
	stVap.ulWepRekeyPeriod = 300 ;
	stVap.ulWepKeyIndex = 1 ;
	stVap.ul8021x = 1 ;
	stVap.ulEapolVer = 2 ;
	stVap.ulEapAuthPeriod = 150 ;

	/*创建测试数据:VAP*/
	pstVap1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVap1, & stVap, sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVap1, NULL) ;

	/*启动IOCTL配置*/
	pstVapId1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId1, & pstVap1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId1, NULL) ;

	/*恢复数据*/
	pstVapIdTmp1 = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapIdTmp1, pstVapId1, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_delete_timeout, pstVapIdTmp1, NULL) ;

	return 0 ;
}

/*
 功能：IOCTL测试；
*/
static unsigned int hostapd_ioctl_tests(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	//start = hostapd_ioctl_testcase1(start) ;

	return start ;
}


static void hostapd_timer_timeout(void *eloop_ctx, void *timeout_ctx)
{
	struct os_time now , * time_register,  * timeout ;

	os_get_time(& now) ;

	time_register = eloop_ctx ;
	timeout = timeout_ctx ;

	printf("timeout:\n") ;
	printf("--now:     \t%ld.%06ld s.\n", now.sec, now.usec) ;
	printf("--register:\t%ld.%06ld s.\n", time_register->sec, time_register->usec) ;
	printf("--timeout:\t%ld.%06ld s.\n", timeout->sec, timeout->usec) ;

	os_free(time_register) ;
	os_free(timeout) ;
}


/*
功能测试：
	1）增加第一个即时定时器；
	2）增加第一个10 MS定时器；
	3）增加第一个1 S定时器；
预置条件：
	当前HOSTAPD系统无任何定时器；
*/
static void hostapd_timer_testcase1(int no)
{
	struct os_time * time_register, * timeout ;
	
	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;
	
	timeout = os_zalloc(sizeof(struct os_time)) ;

	switch(no){
	case 1 :
		timeout->sec = 0 ;
		timeout->usec = 0 ;
		break ;
	case 2 :
		timeout->sec = 0 ;
		timeout->usec = 10000 ;		
		break ;
	case 3 :
		timeout->sec = 1 ;
		timeout->usec = 0 ;	
		break ;
	default :
		break ;
	}

	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;
	
	return ;
}


/*
功能测试：
	1）增加即时定时器；
	2）增加1S定时器；
预置条件：
	1）存在一个即时定时器；
*/
static void hostapd_timer_testcase2(int no)
{
	struct os_time * time_register, * timeout ;
	
	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;
	
	timeout = os_zalloc(sizeof(struct os_time)) ;
	timeout->sec = 0 ;
	timeout->usec = 0 ;

	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;

	timeout = os_zalloc(sizeof(struct os_time)) ;
	
	switch(no){
	case 1:
		timeout->sec = 0 ;
		timeout->usec = 0 ;
		break ;
	case 2:
		timeout->sec = 1 ;
		timeout->usec = 0 ;
		break ;
	default:
		break ;
	}
	
	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

	return ;
}


/*
功能测试：
	1）增加即时定时器；
	2）增加0.5S定时器；
	3）增加1S定时器；
预置条件：
	1）存在一个1S定时器；
*/
static void hostapd_timer_testcase3(int no)
{
	struct os_time * time_register, * timeout ;
	
	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;
	
	timeout = os_zalloc(sizeof(struct os_time)) ;
	timeout->sec = 1 ;
	timeout->usec = 0 ;

	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;
	

	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;

	timeout = os_zalloc(sizeof(struct os_time)) ;
	
	switch(no){
	case 1:
		timeout->sec = 0 ;
		timeout->usec = 0 ;
		break ;
	case 2:
		timeout->sec = 0 ;
		timeout->usec = 500000 ;
		break ;
	case 3:
		timeout->sec = 1 ;
		timeout->usec = 0 ;
	default:
		break ;
	}
	
	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

	return ;
}


static void hostapd_timer_testcase4_timeout(void *eloop_ctx, void *timeout_ctx)
{
	struct os_time * time_register, * timeout ;
	int no = (int)eloop_ctx ;
	
	time_register = os_zalloc(sizeof(struct os_time)) ;
	os_get_time(time_register) ;
	
	timeout = os_zalloc(sizeof(struct os_time)) ;

	switch(no){
	case 1:
		timeout->sec = 0 ;
		timeout->usec = 0 ;
		break ;
	case 2:
		timeout->sec = 1 ;
		timeout->usec = 0 ;
		break ;
	default :
		break ;
	}

	eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;
	
	return ;
}


/*
测试项：
	1）定时器超时处理中，增加即时定时器；
	2）定时器超时处理中，增加1S定时器；
*/
static void hostapd_timer_testcase4(int no)
{
	eloop_register_timeout(0, 0, hostapd_timer_testcase4_timeout, (void *)no, NULL) ;

	return ;
}

/*
测试项：
	1）取消即时定时器；
	2）取消1S定时器；
	3）取消当前最早定时器；
	4）取消当前非最早定时器；
*/
static void hostapd_timer_testcase5(int no)
{
	struct os_time * time_register, * timeout ;
	
	switch(no){
	case 1:
		time_register = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register) ;
	
		timeout = os_zalloc(sizeof(struct os_time)) ;
		timeout->sec = timeout->usec = 0 ;

		eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

		eloop_cancel_timeout(hostapd_timer_timeout, time_register, timeout) ;

		os_free(time_register) ;
		os_free(timeout) ;
		break ;
	case 2:
		time_register = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register) ;
	
		timeout = os_zalloc(sizeof(struct os_time)) ;
		timeout->sec = 1 ;
		timeout->usec = 0 ;

		eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

		eloop_cancel_timeout(hostapd_timer_timeout, time_register, timeout) ;

		os_free(time_register) ;
		os_free(timeout) ;
		break ;
	case 3:{
		struct os_time * time_register2, * timeout2 ;
		
		time_register = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register) ;
	
		timeout = os_zalloc(sizeof(struct os_time)) ;
		timeout->sec = 1 ;
		timeout->usec = 0 ;

		eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

		time_register2 = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register2) ;
	
		timeout2 = os_zalloc(sizeof(struct os_time)) ;
		timeout2->sec = 2 ;
		timeout2->usec = 0 ;

		eloop_register_timeout(timeout2->sec, timeout2->usec, hostapd_timer_timeout, time_register2, timeout2) ;
		
		eloop_cancel_timeout(hostapd_timer_timeout, time_register, timeout) ;

		os_free(time_register) ;
		os_free(timeout) ;
		break ;
	}
	case 4:{
		struct os_time * time_register2, * timeout2 ;
		
		time_register = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register) ;
	
		timeout = os_zalloc(sizeof(struct os_time)) ;
		timeout->sec = 1 ;
		timeout->usec = 0 ;

		eloop_register_timeout(timeout->sec, timeout->usec, hostapd_timer_timeout, time_register, timeout) ;

		time_register2 = os_zalloc(sizeof(struct os_time)) ;
		os_get_time(time_register2) ;
	
		timeout2 = os_zalloc(sizeof(struct os_time)) ;
		timeout2->sec = 2 ;
		timeout2->usec = 0 ;

		eloop_register_timeout(timeout2->sec, timeout2->usec, hostapd_timer_timeout, time_register2, timeout2) ;
		
		eloop_cancel_timeout(hostapd_timer_timeout, time_register2, timeout2) ;

		os_free(time_register2) ;
		os_free(timeout2) ;
		break ;
	}
	default:
		break ;
	}

	return ;
}


/*
功能：定时器测试
*/
static void hostapd_timer_tests(void)
{
	int testcase = 5 ;

	switch(testcase){
	case 1:
		hostapd_timer_testcase1(3) ;
		break ;
	case 2:
		hostapd_timer_testcase2(2) ;
		break ;
	case 3:
		hostapd_timer_testcase3(3) ;
		break ;
	case 4:
		hostapd_timer_testcase4(2) ;
		break ;
	case 5:
		hostapd_timer_testcase5(4) ;
	default:
		break ;
	}

	return ;
}


static void hostapd_test_set_radiusservers_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_RADIUS_SERVERS_T * pstRadiusServersCfg = NULL ;
	TPID stReceiver = {0} ;

	if((pstRadiusServersCfg = eloop_ctx) == NULL){
		printf("%s, point is NULL.\n", __func__) ;
		return ;
	}

	VmSelfPid(& stReceiver) ;
	VmASend(AC_DEVM_RADIUS_CONFIG_UPDATE_IND_MSG, (BYTE *)pstRadiusServersCfg, sizeof(AC_DEVM_RADIUS_SERVERS_T), stReceiver) ;

	VM_FREE(pstRadiusServersCfg) ;
}


/*
测试点：
	1）初始化保活实体；
	……
*/
static unsigned int hostapd_radius_alive_testcase1(unsigned int sec_start)
{
	AC_DEVM_RADIUS_SERVERS_T * pstRadiusServersCfg3 = NULL, * pstRadiusServersCfg4 = NULL ;
	UINT8 ip[4] = {10, 1, 8, 79}, ip2[4] = {10, 1, 8, 80}, ip3[4] = {10, 1, 8, 79}, ip4[4] = {10, 1, 8, 80} ;
	char * pSecret = "123456", * pSecret2 = "123456", * pSecret3 = "123456", * pSecret4 = "123456" ;
	unsigned int start = sec_start ;

#if 0	/*认证服务器保活测试*/
	pstRadiusServersCfg = VM_ZALLOC(sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;
	/*主*/
	memcpy(pstRadiusServersCfg->stAuthSrvMaster.aucIp, ip2, sizeof(ip2)) ;
	pstRadiusServersCfg->stAuthSrvMaster.ulPort = 1812 ;
	memcpy(pstRadiusServersCfg->stAuthSrvMaster.acSecret, pSecret2, strlen( pSecret2)) ;
	/*备*/
	memcpy(pstRadiusServersCfg->stAuthSrvSlave.aucIp, ip, sizeof(ip)) ;
	pstRadiusServersCfg->stAuthSrvSlave.ulPort = 1812 ;
	memcpy(pstRadiusServersCfg->stAuthSrvSlave.acSecret, pSecret, strlen(pSecret)) ;
	pstRadiusServersCfg->ulAuthEchoInterval = 5 ;
	
	eloop_register_timeout(start ++, 0, hostapd_test_set_radiusservers_timeout, pstRadiusServersCfg, NULL) ;

	/*修改配置：*/
	pstRadiusServersCfg2 = VM_ZALLOC(sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;
	memcpy(pstRadiusServersCfg2->stAuthSrvMaster.aucIp, ip, sizeof(ip)) ;
	pstRadiusServersCfg2->stAuthSrvMaster.ulPort = 1812 ;
	memcpy(pstRadiusServersCfg2->stAuthSrvMaster.acSecret, pSecret, strlen(pSecret)) ;
	pstRadiusServersCfg2->ulAuthEchoInterval = 5 ;
	start += 15 ;
	eloop_register_timeout(start ++, 0, hostapd_test_set_radiusservers_timeout, pstRadiusServersCfg2, NULL) ;
#endif

	pstRadiusServersCfg3 = VM_ZALLOC(sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;
	/*主用认证服务器配置*/
	memcpy(pstRadiusServersCfg3->stAuthSrvMaster.aucIp, ip, sizeof(ip)) ;
	pstRadiusServersCfg3->stAuthSrvMaster.ulPort = 1812 ;
	memcpy(pstRadiusServersCfg3->stAuthSrvMaster.acSecret, pSecret, strlen( pSecret)) ;
	
	/*主用计费服务器配置*/
	memcpy(pstRadiusServersCfg3->stAcctSrvMaster.aucIp, ip4, sizeof(ip4)) ;
	pstRadiusServersCfg3->stAcctSrvMaster.ulPort = 1813 ;
	memcpy(pstRadiusServersCfg3->stAcctSrvMaster.acSecret, pSecret4, strlen( pSecret4)) ;
	/*备用计费服务器配置*/
	memcpy(pstRadiusServersCfg3->stAcctSrvSlave.aucIp, ip3, sizeof(ip3)) ;
	pstRadiusServersCfg3->stAcctSrvSlave.ulPort = 1813 ;
	memcpy(pstRadiusServersCfg3->stAcctSrvSlave.acSecret, pSecret3, strlen( pSecret3)) ;
	
	eloop_register_timeout(start ++, 0, hostapd_test_set_radiusservers_timeout, pstRadiusServersCfg3, NULL) ;

	/*修改配置：*/
	pstRadiusServersCfg4 = VM_ZALLOC(sizeof(AC_DEVM_RADIUS_SERVERS_T)) ;
	/*主用认证服务器配置*/
	memcpy(pstRadiusServersCfg4->stAuthSrvMaster.aucIp, ip2, sizeof(ip2)) ;
	pstRadiusServersCfg4->stAuthSrvMaster.ulPort = 1812 ;
	memcpy(pstRadiusServersCfg4->stAuthSrvMaster.acSecret, pSecret2, strlen( pSecret2)) ;
	
	/*主用计费服务器配置*/
	memcpy(pstRadiusServersCfg4->stAcctSrvMaster.aucIp, ip3, sizeof(ip3)) ;
	pstRadiusServersCfg4->stAcctSrvMaster.ulPort = 1813 ;
	memcpy(pstRadiusServersCfg4->stAcctSrvMaster.acSecret, pSecret3, strlen( pSecret3)) ;

	start += 15 ;
	eloop_register_timeout(start ++, 0, hostapd_test_set_radiusservers_timeout, pstRadiusServersCfg4, NULL) ;

	return start ;
}


/*
功能：RADIUS SERVER保活测试
*/
static unsigned int hostapd_radius_alive_tests(unsigned int sec_start)
{
	unsigned int start = sec_start ;

	start = hostapd_radius_alive_testcase1(start) ;

	return start ;
}


static void hostapd_test_user_access_timeout(void * eloop_ctx, void * usrm_data)
{
	struct hostapd_data * pstVap = NULL ;
	AC_VAPID_T * pstVapId = NULL ;
	unsigned char mac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x07} ;

	if((pstVapId = eloop_ctx) == NULL){
		printf("%s, point is NULL.\n", __func__) ;
		return ;
	}

	if((pstVap = FindVap(pstVapId->ulWtpId, pstVapId->ulIfId, pstVapId->ulVapId)) == NULL){
		printf("%s, can not find vap(%d/%d/%d).\n", __func__, pstVapId->ulWtpId, pstVapId->ulIfId, pstVapId->ulVapId) ;
		return ;
	}

	madwifi_new_sta(pstVap->driver, mac, 1) ;

	VM_FREE(pstVapId) ;
}


static void hostapd_test_user_leave_timeout(void * eloop_ctx, void * usrm_data)
{
	struct hostapd_data * pstVap = NULL ;
	AC_VAPID_T * pstVapId = NULL ;
	unsigned char mac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x07} ;

	if((pstVapId = eloop_ctx) == NULL){
		printf("%s, point is NULL.\n", __func__) ;
		return ;
	}

	if((pstVap = FindVap(pstVapId->ulWtpId, pstVapId->ulIfId, pstVapId->ulVapId)) == NULL){
		printf("%s, can not find vap(%d/%d/%d).\n", __func__, pstVapId->ulWtpId, pstVapId->ulIfId, pstVapId->ulVapId) ;
		return ;
	}

	madwifi_del_sta(pstVap->driver, mac) ;

	VM_FREE(pstVapId) ;
}


/*
功能：MAC认证测试
*/
static unsigned int hostapd_macauth_tests(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_VAPID_T * pstVapId = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVapAdd, * pstVapAdd1 = NULL ;
	unsigned char mac1[6] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01} ;
	unsigned int start = sec_start ;

	/*配置VAP*/
	os_memset(& stVapAdd, 0, sizeof(stVapAdd)) ;

	stVapAdd.stVapId.ulWtpId = AC_WTPID_MAX ;
	stVapAdd.stVapId.ulIfId = 0 ;
	stVapAdd.stVapId.ulVapId = 0 ;

	stVapAdd.ulOpMode = AC_VAP_OPMODE_AP ;

	os_memcpy(stVapAdd.acIfName, "ap0_1", 5) ;
	os_memcpy(stVapAdd.aucBssid, mac1, 6) ;
	os_memcpy(stVapAdd.acSsid, "ap1_yey", 8) ;
	stVapAdd.ulSsidBroadcast = 1 ;

	stVapAdd.ulAuth = 16 ;
	stVapAdd.ulEncrypt = 1 ;
	os_memcpy(stVapAdd.acWpaKey, "www.gbcom.com.cn", 17) ;
	stVapAdd.ulWpaRekeyPeriod = 600 ;
	stVapAdd.ulWepKeyLen = 1 ;
	stVapAdd.ulInputFormat = 1 ;
	os_memcpy(stVapAdd.acWepKey, "0123456789", 11) ;
	stVapAdd.ulWepRekeyPeriod = 300 ;
	stVapAdd.ulWepKeyIndex = 1 ;
	stVapAdd.ul8021x = 0 ;
	stVapAdd.ulEapolVer = 2 ;
	stVapAdd.ulEapAuthPeriod = 150 ;

	/*设置AAA*/
	eloop_register_timeout(start ++, 0, hostapd_test_set_radius_servers_timeout, NULL, NULL) ;

	/*创建测试数据:WTP1*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = stVapAdd.stVapId.ulWtpId ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*创建测试数据:IF1*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = stVapAdd.stVapId.ulWtpId ;
	pstIfIdTmp1->ulIfId = stVapAdd.stVapId.ulIfId ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*VAP1*/
	pstVapAdd1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd1, & stVapAdd, sizeof(stVapAdd)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd1, NULL) ;

	/*VAP1状态切换到正常*/
	eloop_register_timeout(start ++, 0, hostapd_test_wtpopstate_normal_timeout, (void *)pstVapAdd1->stVapId.ulWtpId, NULL) ;
	
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId, NULL) ;

	/*MAC认证测试/接入VAP1*/
	start += 5 ;

	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;

	/*用户离线*/
	start += 2 ;
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_leave_timeout, pstVapId, NULL) ;

	/*MAC认证测试/再次接入VAP1*/
	start += 2 ;

	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;
	
	return start ;
}


/*切换测试*/
static unsigned int hostapd_handover_tests(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_VAPID_T * pstVapId = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVapAdd, * pstVapAdd1 = NULL, * pstVapAdd2 = NULL ;
	unsigned char mac1[6] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01}, mac2[6] = {0x02, 0x02, 0x02, 0x02, 0x02, 0x02} ;
	unsigned int start = sec_start ;

	/*配置VAP*/
	os_memset(& stVapAdd, 0, sizeof(stVapAdd)) ;

	stVapAdd.stVapId.ulWtpId = AC_WTPID_MAX ;
	stVapAdd.stVapId.ulIfId = 0 ;
	stVapAdd.stVapId.ulVapId = 0 ;

	stVapAdd.ulOpMode = AC_VAP_OPMODE_AP ;

	os_memcpy(stVapAdd.acIfName, "ap0_1", 5) ;
	os_memcpy(stVapAdd.aucBssid, mac1, 6) ;
	os_memcpy(stVapAdd.acSsid, "ap1_yey", 8) ;
	stVapAdd.ulSsidBroadcast = 1 ;

	stVapAdd.ulAuth = 1 ;
	stVapAdd.ulEncrypt = 1 ;
	os_memcpy(stVapAdd.acWpaKey, "www.gbcom.com.cn", 17) ;
	stVapAdd.ulWpaRekeyPeriod = 600 ;
	stVapAdd.ulWepKeyLen = 1 ;
	stVapAdd.ulInputFormat = 1 ;
	os_memcpy(stVapAdd.acWepKey, "0123456789", 11) ;
	stVapAdd.ulWepRekeyPeriod = 300 ;
	stVapAdd.ulWepKeyIndex = 1 ;
	stVapAdd.ul8021x = 0 ;
	stVapAdd.ulEapolVer = 2 ;
	stVapAdd.ulEapAuthPeriod = 150 ;

	/*设置AAA*/
	eloop_register_timeout(start ++, 0, hostapd_test_set_radius_servers_timeout, NULL, NULL) ;

	/*创建测试数据:WTP1*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*创建测试数据:IF1*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX ;
	pstIfIdTmp1->ulIfId = 0 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*VAP1*/
	pstVapAdd1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd1, & stVapAdd, sizeof(stVapAdd)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd1, NULL) ;

	/*VAP1状态切换到正常*/
	eloop_register_timeout(start ++, 0, hostapd_test_wtpopstate_normal_timeout, (void *)pstVapAdd1->stVapId.ulWtpId, NULL) ;
	
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId, NULL) ;

	/*创建测试数据:WTP2*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = AC_WTPID_MAX - 1 ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*创建测试数据:IF2*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = AC_WTPID_MAX - 1 ;
	pstIfIdTmp1->ulIfId = 0 ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*配置VAP2*/
	pstVapAdd2 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd2, & stVapAdd, sizeof(stVapAdd)) ;
	pstVapAdd2->stVapId.ulWtpId = pstWtpIdTmp1->ulWtpId ;
	pstVapAdd2->stVapId.ulIfId = pstIfIdTmp1->ulIfId ;
	pstVapAdd2->stVapId.ulVapId = 0 ;
	os_memcpy(pstVapAdd2->aucBssid, mac2, 6) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd2, NULL) ;

	/*VAP2状态切换到正常*/
	eloop_register_timeout(start ++, 0, hostapd_test_wtpopstate_normal_timeout, (void *)pstVapAdd2->stVapId.ulWtpId, NULL) ;
	
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd2->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId, NULL) ;

	start += 5 ;
	/*终端接入VAP1*/
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;

	/*终端接入VAP2*/
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd2->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;

	return start ;
}


static void hostapd_test_bssid_notify_timeout(void *eloop_ctx, void *timeout_ctx)
{
	AC_DEVM_VAP_MAC_CHG_IND_MSG_T msg ;
	AC_VAPID_T * pstVapId = eloop_ctx ;
	TPID stTpid = {0} ;
	UINT8 bssid[6] = {0x06, 0x02, 0x6F, 0x4A, 0x54, 0x05} ;
	memset(&msg,0,sizeof(msg));

	os_memcpy(& msg.stVapId, pstVapId, sizeof(AC_VAPID_T)) ;
	os_memcpy(msg.aucBssid, bssid, sizeof(bssid)) ;
	
	VmSelfPid(& stTpid) ;
	VmASend(AC_DEVM_VAP_BSSID_CHG_IND_MSG, (BYTE *)& msg, sizeof(msg), stTpid) ;	

	/*注意：未释放eloop_ctx*/
}


static unsigned int hostapd_acm_tests(unsigned int sec_start)
{
	AC_VAPID_T stVapId = {1, 0, 0, 1}, * pstVapId = NULL ;
	unsigned int start = sec_start ;
	
	/*VAP状态切换到正常*/
	eloop_register_timeout(start ++, 0, hostapd_test_wtpopstate_normal_timeout, (void *)stVapId.ulWtpId, NULL) ;
	
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_bssid_notify_timeout, pstVapId, NULL) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId, NULL) ;

	start += 5 ;
	/*终端接入VAP*/
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;

	/*终端离开VAP*/
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_leave_timeout, pstVapId, NULL) ;

	return start ;
}

/*
功能：模拟PA向HOSTAPD发送消息，消息内容为eloop_ctx，消息号为timeout_ctx
*/
static void hostapd_test_ppp_timeout(void *eloop_ctx, void *timeout_ctx)
{
	BYTE * pstMsg = NULL ;
	UINT32 ulEvent = 0, ulLength = 0 ;
	TPID stMySelf = {0} ;
	
	if((pstMsg = eloop_ctx) == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, point is NULL.\n", __func__) ;
		return ;
	}
	
	ulEvent = (UINT32)timeout_ctx ;
	switch(ulEvent){
	case EV_AC_PA_HOSTAPD_AUTH_REQ_MSG:
		ulLength = sizeof(AC_PA_HOSTAPD_AUTH_REQ_T) ;
		break ;
	case EV_AC_PA_HOSTAPD_AUTH_OVER_NTF_MSG:
		ulLength = sizeof(AC_PA_HOSTAPD_AUTH_OVER_NTF_T) ;
		break ;
#if 0
	case EV_AC_PA_HOSTAPD_LOGOUT_NTF_MSG:
		ulLength = sizeof(AC_PA_HOSTAPD_LOGOUT_NTF_T) ;
		break ;
#endif
	default:
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_WARN,
			"%s, unknown event(%d).\n", __func__, ulEvent) ;
		break ;
	}

	VmSelfPid(& stMySelf) ;
	if(! VmASend(ulEvent, pstMsg, ulLength, stMySelf)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, send msg failed.\n", __func__) ;
	}

	VM_FREE(pstMsg) ;
}


/*
功能：PORTAL认证测试
*/
static unsigned int hostapd_portalauth_tests(unsigned int sec_start)
{
	AC_WTPID_T * pstWtpIdTmp1 = NULL ;
	AC_IFID_T * pstIfIdTmp1 = NULL ;
	AC_VAPID_T * pstVapId = NULL ;
	AC_DEVM_VAP_ADD_IND_MSG_T stVapAdd, * pstVapAdd1 = NULL ;
	AC_PA_HOSTAPD_AUTH_REQ_T * pstPortalReq = NULL ;
	AC_PA_HOSTAPD_AUTH_OVER_NTF_T * pstPortalLogon = NULL ;
	//AC_PA_HOSTAPD_LOGOUT_NTF_T * pstPortalLogoff = NULL ;
	UINT8 usrip[4] = {192, 168, 1, 1}, usrmac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x07}, usrname[] = "yeenyun", usrpwd[] = "yeenyun" ;
	unsigned char mac1[6] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01} ;
	unsigned int start = sec_start ;

	/*配置VAP*/
	os_memset(& stVapAdd, 0, sizeof(stVapAdd)) ;

	stVapAdd.stVapId.ulWtpId = AC_WTPID_MAX ;
	stVapAdd.stVapId.ulIfId = 0 ;
	stVapAdd.stVapId.ulVapId = 0 ;

	stVapAdd.ulOpMode = AC_VAP_OPMODE_AP ;

	os_memcpy(stVapAdd.acIfName, "ap0_1", 5) ;
	os_memcpy(stVapAdd.aucBssid, mac1, 6) ;
	os_memcpy(stVapAdd.acSsid, "ap1_yey", 8) ;
	stVapAdd.ulSsidBroadcast = 1 ;

	stVapAdd.ulAuth = 1 ;
	stVapAdd.ulEncrypt = 1 ;
	os_memcpy(stVapAdd.acWpaKey, "www.gbcom.com.cn", 17) ;
	stVapAdd.ulWpaRekeyPeriod = 600 ;
	stVapAdd.ulWepKeyLen = 1 ;
	stVapAdd.ulInputFormat = 1 ;
	os_memcpy(stVapAdd.acWepKey, "0123456789", 11) ;
	stVapAdd.ulWepRekeyPeriod = 300 ;
	stVapAdd.ulWepKeyIndex = 1 ;
	stVapAdd.ul8021x = 0 ;
	stVapAdd.ulEapolVer = 2 ;
	stVapAdd.ulEapAuthPeriod = 150 ;

	/*创建测试数据:WTP1*/
	pstWtpIdTmp1 = os_zalloc(sizeof(AC_WTPID_T)) ;
	pstWtpIdTmp1->ulWtpId = stVapAdd.stVapId.ulWtpId ;
	eloop_register_timeout(start ++, 0, hostapd_test_wtp_add_timeout, pstWtpIdTmp1, NULL) ;

	/*创建测试数据:IF1*/
	pstIfIdTmp1 = os_zalloc(sizeof(AC_IFID_T)) ;
	pstIfIdTmp1->ulWtpId = stVapAdd.stVapId.ulWtpId ;
	pstIfIdTmp1->ulIfId = stVapAdd.stVapId.ulIfId ;
	eloop_register_timeout(start ++, 0, hostapd_test_if_add_timeout, pstIfIdTmp1, NULL) ;

	/*VAP1*/
	pstVapAdd1 = os_zalloc(sizeof(AC_DEVM_VAP_ADD_IND_MSG_T)) ;
	os_memcpy(pstVapAdd1, & stVapAdd, sizeof(stVapAdd)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_vap_config_new_timeout, pstVapAdd1, NULL) ;

	/*VAP1状态切换到正常*/
	eloop_register_timeout(start ++, 0, hostapd_test_wtpopstate_normal_timeout, (void *)pstVapAdd1->stVapId.ulWtpId, NULL) ;
	
	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_opstate_normal_timeout, pstVapId, NULL) ;

	/*终端接入VAP1*/
	start += 5 ;

	pstVapId = os_zalloc(sizeof(AC_VAPID_T)) ;
	os_memcpy(pstVapId, & pstVapAdd1->stVapId, sizeof(AC_VAPID_T)) ;
	eloop_register_timeout(start ++, 0, hostapd_test_user_access_timeout, pstVapId, NULL) ;

	/*用户发起PORTAL认证*/
	pstPortalReq = os_zalloc(sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)) ;
	memcpy(pstPortalReq->aucUserIP, usrip, sizeof(usrip)) ;
	memcpy(pstPortalReq->aucUserMac, usrmac, sizeof(usrmac)) ;
	pstPortalReq->usSerialNo = 123 ;
	strcpy(pstPortalReq->acUserName, usrname) ;
	if(0){/*PAP*/
		pstPortalReq->ucAuthType = PORTAL_AUTH_TYPE_PAP ;
		strcpy(pstPortalReq->acPassword, usrpwd) ;
		pstPortalReq->ucPasswordLen = sizeof(usrpwd) ;
	}
	else{/*CHAP*/
		UINT8 * addr[3] = {NULL}, chap_id = 79, chap_pwd[16] = {0}, chap_challenge[16] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3} ;
		UINT32 len[3] ;

		addr[0] = & chap_id ;
		len[0] = 1 ;
		addr[1] = usrpwd ;
		len[1] = strlen(usrpwd) ;
		addr[2] = chap_challenge ;
		len[2] = 16 ;
		md5_vector(3, (u8 *)addr, len, chap_pwd) ;
		
		pstPortalReq->ucAuthType = PORTAL_AUTH_TYPE_CHAP ;
		pstPortalReq->ucChallengeID = chap_id ;
		memcpy(pstPortalReq->aucChallenge, chap_challenge, sizeof(chap_challenge)) ;
		memcpy(pstPortalReq->acPassword, chap_pwd, sizeof(chap_pwd)) ;
		pstPortalReq->ucPasswordLen = sizeof(chap_pwd) ;
	}
	eloop_register_timeout(start ++, 0, hostapd_test_ppp_timeout, pstPortalReq, (void *)EV_AC_PA_HOSTAPD_AUTH_REQ_MSG) ;

	/*用户上线*/
	start += 3 ;
	pstPortalLogon= os_zalloc(sizeof(AC_PA_HOSTAPD_AUTH_OVER_NTF_T)) ;
	memcpy(pstPortalLogon->aucUserIP, usrip, sizeof(usrip)) ;
	memcpy(pstPortalLogon->aucUserMac, usrmac, sizeof(usrmac)) ;
	pstPortalLogon->usSerialNo = 123 ;
	eloop_register_timeout(start ++, 0, hostapd_test_ppp_timeout, pstPortalLogon, (void *)EV_AC_PA_HOSTAPD_AUTH_OVER_NTF_MSG) ;

	/*用户下线*/
#if 0
	pstPortalLogoff = os_zalloc(sizeof(AC_PA_HOSTAPD_LOGOUT_NTF_T)) ;
	memcpy(pstPortalLogoff->aucUserIP, usrip, sizeof(usrip)) ;
	memcpy(pstPortalLogoff->aucUserMac, usrmac, sizeof(usrmac)) ;
	pstPortalLogoff->usSerialNo = 123 ;
	eloop_register_timeout(start ++, 0, hostapd_test_ppp_timeout, pstPortalLogoff, EV_AC_PA_HOSTAPD_LOGOUT_NTF_MSG) ;
#endif

	return start ;
}


/*
功能：PORTAL与VAP分离设计后，认证测试
*/
static unsigned int hostapd_portalauth2_tests(unsigned int sec_start)
{
	AC_PA_HOSTAPD_AUTH_REQ_T * pstPortalReq = NULL ;
	UINT8 usrip[4] = {192, 168, 1, 1}, usrmac[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x07}, usrname[] = "yeenyun", usrpwd[] = "yeenyun" ;
	UINT8 nas_ip[4] = {10, 1, 1, 1}, nas_id[] = "nasid_gbcom" ;
	unsigned int start = sec_start ;

	/*用户发起PORTAL认证*/
	pstPortalReq = os_zalloc(sizeof(AC_PA_HOSTAPD_AUTH_REQ_T)) ;
	memcpy(pstPortalReq->aucUserIP, usrip, sizeof(usrip)) ;
	memcpy(pstPortalReq->aucUserMac, usrmac, sizeof(usrmac)) ;
	pstPortalReq->usSerialNo = 123 ;
	strcpy(pstPortalReq->acUserName, usrname) ;
	memcpy(pstPortalReq->aucNasIp, nas_ip, sizeof(nas_ip)) ;
	strcpy(pstPortalReq->acNasId, nas_id) ;
	if(0){/*PAP*/
		pstPortalReq->ucAuthType = PORTAL_AUTH_TYPE_PAP ;
		strcpy(pstPortalReq->acPassword, usrpwd) ;
		pstPortalReq->ucPasswordLen = sizeof(usrpwd) ;
	}
	else{/*CHAP*/
		UINT8 * addr[3] = {NULL}, chap_id = 79, chap_pwd[16] = {0}, chap_challenge[16] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3} ;
		UINT32 len[3] ;

		addr[0] = & chap_id ;
		len[0] = 1 ;
		addr[1] = usrpwd ;
		len[1] = strlen(usrpwd) ;
		addr[2] = chap_challenge ;
		len[2] = 16 ;
		md5_vector(3, (const u8 *)addr, len, chap_pwd) ;
		
		pstPortalReq->ucAuthType = PORTAL_AUTH_TYPE_CHAP ;
		pstPortalReq->ucChallengeID = chap_id ;
		memcpy(pstPortalReq->aucChallenge, chap_challenge, sizeof(chap_challenge)) ;
		memcpy(pstPortalReq->acPassword, chap_pwd, sizeof(chap_pwd)) ;
		pstPortalReq->ucPasswordLen = sizeof(chap_pwd) ;
	}
	eloop_register_timeout(start ++, 0, hostapd_test_ppp_timeout, pstPortalReq, (void *)EV_AC_PA_HOSTAPD_AUTH_REQ_MSG) ;

	return start ;
}
#endif

void HostapdTest(void)
{
	/* unsigned int start = 5 ; */

	//hostapd_timer_tests() ;
	//start = hostapd_radius_alive_tests(start) ;
	//start = hostapd_set_radius_servers(start) ;
	//start = hostapd_device_tests(start) ;
	//start = hostapd_config_tests(start) ;
	//start = hostapd_opstate_tests(start) ;
	//start = hostapd_ioctl_tests(start) ;
	//start = hostapd_handover_tests(start) ;
	//start = hostapd_macauth_tests(start) ;
	//start = hostapd_acm_tests(start) ;
	//start = hostapd_portalauth_tests(start) ;
	//start = hostapd_portalauth2_tests(start) ;
}
#if 0
static void hostapd_test_vap_opstate_timeout(void *eloop_ctx, void *timeout_ctx)
{
	unsigned long i, j, k ;
	AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG_T stVapChgInd ;
	TPID stTpid ;

	VmSelfPid(& stTpid) ;

	for(i = 0 ; i < MAX_WTPS ;i ++)
		for(j = 0 ; g_pstWtpTable[i] && j < MAX_INTERFACES ; j ++)
			for(k = 0 ; g_pstWtpTable[i]->iface[j] && k < MAX_BSSES ; k ++){
				if(g_pstWtpTable[i]->iface[j]->bss[k] == NULL)
					continue ;

				os_memcpy(g_pstWtpTable[i]->iface[j]->bss[k]->conf->iface, "ap0", 4) ;

				stVapChgInd.stVapId.ulWtpId = g_pstWtpTable[i]->usWtpId ;
				stVapChgInd.stVapId.ulIfId = g_pstWtpTable[i]->iface[j]->interface_id ;
				stVapChgInd.stVapId.ulVapId = g_pstWtpTable[i]->iface[j]->bss[k]->vap_id ;

				stVapChgInd.ulAdminState = AC_ADMINSTATE_ENABLE ;

				VmASend(AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG, (UINT8*)&stVapChgInd, sizeof(stVapChgInd), stTpid);

				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				    "send AC_DEVM_VAP_ADMINSTATE_CHG_IND_MSG_T to self: "
				    "vap(%u/%u/%u) %s.\n",
				    stVapChgInd.stVapId.ulWtpId, stVapChgInd.stVapId.ulIfId, stVapChgInd.stVapId.ulVapId,
				    stVapChgInd.ulAdminState == AC_ADMINSTATE_ENABLE ? "up" : "down");
			}
}
#endif
