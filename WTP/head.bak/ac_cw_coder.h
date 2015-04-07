/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: CAPWAP CODER头文件
* 修改历史: 
* 2008-5-9     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_CODER_H
#define  _AC_CW_CODER_H
extern UINT32 ac_cw_msg_elem_coder (AC_CW_PROTO_MSG_T *pstMsg, UINT16 usMsgElemType);
extern UINT32 ac_cw_msg_elem_coder_ac_descriptor (AC_CW_PROTO_MSG_T *pstMsg, 
                                           AC_CW_MSG_ELEM_AC_DESCRIPTOR_T *pstAcDescriptor,
                                           UINT32	ulVersionFlag);
extern UINT32 ac_cw_msg_elem_coder_ac_ipv4_list (AC_CW_PROTO_MSG_T *pstMsg, 
                                          AC_CW_MSG_ELEM_AC_IPV4_LIST_T*pstAcIpv4List);
extern UINT32 ac_cw_msg_elem_coder_ac_ipv6_list (AC_CW_PROTO_MSG_T *pstMsg, 
                                          AC_CW_MSG_ELEM_AC_IPV6_LIST_T*pstAcIpv6List);
extern UINT32 ac_cw_msg_elem_coder_ac_name (AC_CW_PROTO_MSG_T *pstMsg, 
                                     AC_CW_MSG_ELEM_AC_NAME_T *pstAcName);
extern UINT32 ac_cw_msg_elem_coder_capwap_ctrl_ipv4_addr (AC_CW_PROTO_MSG_T *pstMsg, 
                                                   AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T *pstIpv4Addr);
extern UINT32 ac_cw_msg_elem_coder_capwap_timers (AC_CW_PROTO_MSG_T *pstMsg, 
                                           AC_CW_MSG_ELEM_CAPWAP_TIMERS_T *pstCwTimers);
extern UINT32 ac_cw_msg_elem_coder_decr_error_report_perd (AC_CW_PROTO_MSG_T *pstMsg, AC_CW_MSG_ELEM_DECR_ERROR_REPORT_PERIOD_T *pstDecr);
extern UINT32 ac_cw_msg_elem_coder_discovery_type (AC_CW_PROTO_MSG_T *pstMsg, UINT8 ucDiscoveryType);
extern UINT32 ac_cw_msg_elem_coder_image_identifier (AC_CW_PROTO_MSG_T *pstMsg, 
                                              AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T *pstImageId);
extern UINT32 ac_cw_msg_elem_coder_location_data (AC_CW_PROTO_MSG_T *pstMsg, 
                                           AC_CW_MSG_ELEM_LOCATION_T *pstLocationData);
extern UINT32 ac_cw_msg_elem_coder_max_msg_len (AC_CW_PROTO_MSG_T *pstMsg, 
                                         UINT16    usMaxMsgLen);
extern UINT32 ac_cw_msg_elem_coder_result_code (AC_CW_PROTO_MSG_T *pstMsg, 
                                         UINT32 ulResultCode);
extern UINT32 ac_cw_msg_elem_coder_sessionid (AC_CW_PROTO_MSG_T *pstMsg, 
                                       UINT32 ulSessionId);
extern UINT32 ac_cw_msg_elem_coder_wtp_board_data (AC_CW_PROTO_MSG_T *pstMsg, 
                                            AC_CW_MSG_ELEM_WTP_BOARDDATA_T *pstBoardData);
extern UINT32 ac_cw_msg_elem_coder_wtp_descriptor (AC_CW_PROTO_MSG_T *pstMsg,
                                            AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T *pstWtpDescriptor);
extern UINT32 ac_cw_msg_elem_coder_wtp_frame_tunnel_mode (AC_CW_PROTO_MSG_T *pstMsg, UINT8 ucTunnelMode);
extern UINT32 ac_cw_msg_elem_coder_wtp_ipv4_addr (AC_CW_PROTO_MSG_T *pstMsg, 
                                           AC_CW_MSG_ELEM_WTP_CONTROL_IPV4_ADDR_T *pstWtpIpv4Addr);
extern UINT32 ac_cw_msg_elem_coder_wtp_mac_type (AC_CW_PROTO_MSG_T *pstMsg, UINT8 ucMacType);
extern UINT32 ac_cw_msg_elem_coder_wtp_name (AC_CW_PROTO_MSG_T *pstMsg, 
                                      AC_CW_MSG_ELEM_WTP_NAME_T*pstWtpName);
extern UINT32 ac_cw_msg_elem_coder_wtp_reboot_stat (AC_CW_PROTO_MSG_T *pstMsg, 
                                             AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T *pstWtpRebootStat);
extern UINT32 ac_cw_msg_elem_coder_vendor_specific (AC_CW_PROTO_MSG_T *pstMsg,
                                            AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T *pstWtpVendorSpecific);
extern UINT32    ac_cw_coder_cfg_update_file_header (AC_CW_PROTO_MSG_T *pstMsg, 
                                                AC_CW_CFG_UPDATE_FILE_HEADER_T *pstFileHeader);
extern UINT32    ac_cw_coder_cfg_update_tbl_header(AC_CW_PROTO_MSG_T *pstMsg, 
                                                AC_CW_CFG_UPDATE_TBL_HEADER_T *pstTblHeader);
extern UINT32    ac_cw_coder_cfg_update_tbl_rec (AC_CW_PROTO_MSG_T *pstMsg, AC_CW_WTPINFO_T *pstWtp, DBHANDLE hTbl);
extern UINT32 ac_cw_msg_coder_control_header (AC_CW_CAPWAP_CONTROL_HEADER_T *pstCwControlHdr, 
                                       AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_transport_header (AC_CW_TRANSPORT_HEADER_T *pstCwTransportHdr, 
                                         AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder (AC_CW_PROTO_MSG_T *pstCompleteMsg,
                        UINT32 ulSeqNum,
                        UINT32 ulMsgType,
                        AC_CW_PROTO_MSG_T *pstMsgElems,
                        UINT32 ulMsgElemNum);
extern UINT32 ac_cw_msg_coder_discovery_request (AC_CW_MSG_DISCOVERYREQUEST_T *pstDiscoveryReq, 
                                                 AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_discovery_response (AC_CW_MSG_DISCOVERYRESPONSE_T *pstDiscoveryRep, 
														AC_CW_PROTO_MSG_T *pstMsg,
														UINT32	ulVersionFlag);
extern UINT32 ac_cw_msg_coder_cfg_update_request (AC_CW_MSG_CFGUPDATEREQUEST_T *pstCfgUpdateReq, 
                                                  AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_cfg_update_response (AC_CW_MSG_CFGUPDATERESPONSE_T *pstRsp, 
                                                   AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_change_state_event_request (AC_CW_MSG_CHANGESTATEEVENTREQUEST_T *pstReq, 
                                                          AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_change_state_event_response (AC_CW_MSG_CHANGESTATEEVENTRESPONSE_T *pstRsp, 
                                                           AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_echo_request (AC_CW_MSG_ECHOREQUEST_T *pstEchoReq, AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_echo_response (AC_CW_MSG_ECHORESPONSE_T	*pstEchoRep, AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_cfg_status (AC_CW_MSG_CFGSTATUS_T *pstCfgStatus,
                                         AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_cfg_status_response (AC_CW_MSG_CFGSTATUSRESPONSE_T *pstCfgStatusRsp,
                                                   AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_join_request (AC_CW_MSG_JOINREQUEST_T *pstJoinReq,
                                     AC_CW_PROTO_MSG_T *pstMsg);
extern UINT32 ac_cw_msg_coder_join_response (AC_CW_MSG_JOINRESPONSE_T *pstJoinRep,
                                      AC_CW_PROTO_MSG_T *pstMsg,
                                      UINT32	ulVersionFlag);
extern UINT32 ac_cw_msg_coder_wtp_event_request (AC_CW_MSG_WTPEVENTREQUEST_T *pstReq, 
                                                   AC_CW_PROTO_MSG_T *pstMsg);

#endif /* _AC_CW_CODER_H */
/******************************* 头文件结束 **********************************/

