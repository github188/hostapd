#ifndef AC_OMA_DYNAINFO_H
#define AC_OMA_DYNAINFO_H

/************************************************************************/
/* 函数声明                                                             */
/************************************************************************/

/* AC/WEB请求获取AC动态数据信息 */
extern AC_RET ac_omc_get_ac_dynainfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* AC-OMA接收到AC-APP返回应答 */
extern AC_RET ac_oma_get_ac_dynainfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen, UINT16 usInnerMsgId);

/* 2009-08-21 fengjing add begin*/
extern AC_RET ac_omc_get_ap_nodeinfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_nodeinfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_aodvneighbor_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_aodvneighbor_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_routepath_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_routepath_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_enduser_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_enduser_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_rogueapinfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_rogueapinfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_invalidstainfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_invalidstainfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_abstractinfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_abstractinfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_adhoclinkstat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_adhoclinkstat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_totalstat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_totalstat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_wifistat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_wifistat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_ifstat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_ifstat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_assostat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_assostat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_vdev_icstat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_vdev_icstat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_omc_get_ap_mgtstat_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_mgtstat_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* 2010-08-26 fengjing 新增:获取邻居AP */
extern AC_RET ac_omc_get_ap_neighborap_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_neighborap_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

/* 2010/07/26 fengjing cmcc test */
extern AC_RET ac_omc_get_ap_rtcollect_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_rtcollect_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);

extern AC_RET ac_omc_get_ap_statsample_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* 2009-08-21 fengjing add end */

/* 2011-06-09 fengjing add */
extern AC_RET ac_oma_ap_dynainfo_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_ap_rtdynainfo_ind_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_msstatus_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* add by gwx 2014-5-26 for ruijie 故障信息一键收集begin*/
extern AC_RET ac_omc_get_ap_runinfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ap_runinfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ac_runinfo_req_msg(UINT8 *pucMsg, UINT16 usMsgLen);
extern AC_RET ac_oma_get_ac_runinfo_rsp_msg(UINT8 *pucMsg, UINT16 usMsgLen);
/* add by gwx 2014-5-26 for ruijie 故障信息一键收集end*/
#endif /* AC_OMA_DYNAINFO_H */
