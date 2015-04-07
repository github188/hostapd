/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能: CAPWAP decoder 头文件
* 修改历史: 
* 2008-5-9     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_CW_DECODER_H
#define  _AC_CW_DECODER_H

extern UINT32 ac_cw_msg_elem_decoder_ac_descriptor (AC_CW_PROTO_MSG_T *pstMsg, 
                                             UINT32 ulLen, 
                                             AC_CW_MSG_ELEM_AC_DESCRIPTOR_T    *pstAcDescriptor);
extern UINT32 ac_cw_msg_elem_decoder_ac_ipv4_list (AC_CW_PROTO_MSG_T *pstMsg, 
                                            UINT32 ulLen, 
                                            AC_CW_MSG_ELEM_AC_IPV4_LIST_T *pstAcIpv4List);
extern UINT32 ac_cw_msg_elem_decoder_ac_name (AC_CW_PROTO_MSG_T *pstMsg, 
                                       UINT32 ulLen, 
                                       AC_CW_MSG_ELEM_AC_NAME_T *pstAcName);
extern UINT32 ac_cw_msg_elem_decoder_ac_name_with_index (AC_CW_PROTO_MSG_T *pstMsg, 
                                                         UINT32 ulLen, 
                                                         AC_CW_MSG_ELEM_AC_NAME_WITH_INDEX_T *pstAcName);
extern UINT32 ac_cw_msg_elem_decoder_capwap_ctrl_ipv4_addr (AC_CW_PROTO_MSG_T *pstMsg, 
                                                     UINT32 ulLen, 
                                                     AC_CW_MSG_ELEM_CAPWAP_CONTROL_IPV4_ADDR_T*pstCtrlIpv4Addr);
extern UINT32 ac_cw_msg_elem_decoder_discovery_type (AC_CW_PROTO_MSG_T *pstMsg, 
                                              UINT32 ulLen, 
                                              UINT8 *pucDiscoveryType);
extern UINT32 ac_cw_msg_elem_decoder_image_identifier (AC_CW_PROTO_MSG_T *pstMsg, 
                                                UINT32 ulLen, 
                                                AC_CW_MSG_ELEM_IMAGE_IDENTIFIER_T *pstImageId);
extern UINT32 ac_cw_msg_elem_decoder_location_data (AC_CW_PROTO_MSG_T *pstMsg, 
                                             UINT32 ulLen, 
                                             AC_CW_MSG_ELEM_LOCATION_T *pstLocationData);
extern UINT32 ac_cw_msg_elem_decoder_max_msg_len (AC_CW_PROTO_MSG_T *pstMsg, 
                                           UINT32 ulLen, 
                                           UINT16 *pusMaxMsgLen);
extern UINT32 ac_cw_msg_elem_decoder_radio_admin_state (AC_CW_PROTO_MSG_T *pstMsg, 
                                                        UINT32 ulLen, 
                                                        AC_CW_MSG_ELEM_RADIO_ADMIN_STATE_T *pstRAS);
extern UINT32 ac_cw_msg_elem_decoder_result_code (AC_CW_PROTO_MSG_T *pstMsg, 
                                           UINT32 ulLen, 
                                           UINT32 *pulResultCode);
extern UINT32 ac_cw_msg_elem_decoder_session_id (AC_CW_PROTO_MSG_T *pstMsg, 
                                          UINT32 ulLen, 
                                          UINT32 *pulSessionId);
extern UINT32 ac_cw_msg_elem_decoder_stat_timer (AC_CW_PROTO_MSG_T *pstMsg, 
                                                 UINT32 ulLen, 
                                                 UINT32 *pulStatTimer);
extern UINT32 ac_cw_msg_elem_decoder_wtp_board_data (AC_CW_PROTO_MSG_T *pstMsg, 
                                              UINT32 ulLen, 
                                              AC_CW_MSG_ELEM_WTP_BOARDDATA_T *pstBoardData);
extern UINT32 ac_cw_msg_elem_decoder_wtp_descriptor (AC_CW_PROTO_MSG_T *pstMsg, 
                                              UINT32 ulLen, 
                                              AC_CW_MSG_ELEM_WTP_DESCRIPTOR_T*pstWtpDescriptor,
                                              UINT32	ulFlags);
extern UINT32 ac_cw_msg_elem_decoder_wtp_frame_tunnel_mode (AC_CW_PROTO_MSG_T *pstMsg, 
                                                     UINT32 ulLen, 
                                                     UINT8 *pucTunnelMode);
extern UINT32 ac_cw_msg_elem_decoder_wtp_ipv4_addr (AC_CW_PROTO_MSG_T *pstMsg, 
                                             UINT32 ulLen, 
                                             AC_CW_MSG_ELEM_WTP_CONTROL_IPV4_ADDR_T *pstWtpIpv4Addr);
extern UINT32 ac_cw_msg_elem_decoder_wtp_mac_type (AC_CW_PROTO_MSG_T *pstMsg, 
                                            UINT32 ulLen, 
                                            UINT8 *pucMacType);
extern UINT32 ac_cw_msg_elem_decoder_wtp_name (AC_CW_PROTO_MSG_T *pstMsg, 
                                        UINT32 ulLen, 
                                        AC_CW_MSG_ELEM_WTP_NAME_T*pstWtpName);
extern UINT32 ac_cw_msg_elem_decoder_wtp_static_ip_addr (AC_CW_PROTO_MSG_T *pstMsg, 
                                                         UINT32 ulLen, 
                                                         AC_CW_MSG_ELEM_WTP_STATIC_IP_ADDR_INFO_T *pstWtpStaticIp);
extern UINT32 ac_cw_msg_elem_decoder_vendor_specific (AC_CW_PROTO_MSG_T *pstMsg, 
                                              UINT32 ulLen, 
                                              AC_CW_MSG_ELEM_VENDOR_SPECIFIC_PAYLOAD_T*pstVendorSpecific);
extern UINT32 ac_cw_msg_elem_decoder_wtp_reboot_stat (AC_CW_PROTO_MSG_T *pstMsg, 
                                           UINT32 ulLen, 
                                           AC_CW_MSG_ELEM_WTP_REBOOT_STATISTICS_T *pstWtpRebootStat);
extern UINT32 ac_cw_msg_decoder_control_header (AC_CW_PROTO_MSG_T *pstMsg,
                                         AC_CW_CAPWAP_CONTROL_HEADER_T *pstCwControlHdr);
extern UINT32 ac_cw_msg_decoder_transport_header (AC_CW_PROTO_MSG_T *pstMsg,
                                           AC_CW_TRANSPORT_HEADER_T *pstCwTransportHdr);
extern UINT32 ac_cw_msg_elem_decoder_header (AC_CW_PROTO_MSG_T *pstMsg, UINT16 *pusType, UINT16 *pusLen);

extern UINT32    ac_cw_decoder_cfg_update_file_header (AC_CW_PROTO_MSG_T *pstMsg, 
                                                AC_CW_CFG_UPDATE_FILE_HEADER_T *pstFileHeader);
extern UINT32    ac_cw_decoder_cfg_update_tbl_header(AC_CW_PROTO_MSG_T *pstMsg, 
                                                AC_CW_CFG_UPDATE_TBL_HEADER_T *pstTblHeader);
extern UINT32    ac_cw_decoder_cfg_update_tbl_rec (AC_CW_PROTO_MSG_T *pstMsg, AC_CW_CFG_UPDATE_TBL_HEADER_T *pstTblHeader);

extern UINT32	  ac_cw_msg_decoder_discovery_request(UINT32 ulLen, 
                                           UINT8* pucMsg, 
                                           AC_CW_MSG_DISCOVERYREQUEST_T *pstDiscoveryReq,
                                           UINT32	*pulVersionFlag);
extern UINT32 ac_cw_msg_decoder_discovery_response(UINT32 ulLen, 
                                               UINT8* pucMsg, 
                                               AC_CW_MSG_DISCOVERYRESPONSE_T *pstDiscoveryRep);
extern UINT32 ac_cw_msg_decoder_echo_request(UINT32 ulLen, 
                                      CHAR* pucMsg,
                                      AC_CW_MSG_ECHOREQUEST_T *pstEchoReq);
extern UINT32 ac_cw_msg_decoder_echo_response(UINT32 ulLen, 
                                       CHAR* pucMsg,
                                       AC_CW_MSG_ECHORESPONSE_T	*pstEchoRep);
extern UINT32 ac_cw_msg_decoder_join_request(UINT32 ulLen, 
                                      UINT8* pucMsg, 
                                      AC_CW_MSG_JOINREQUEST_T *pstJoinReq);
extern UINT32 ac_cw_msg_decoder_join_response(UINT32 ulLen, 
                                       UINT8* pucMsg, 
                                       AC_CW_MSG_JOINRESPONSE_T *pstJoinRep);
extern UINT32 ac_cw_msg_decoder_cfg_status (UINT32 ulLen, 
                                     UINT8* pucMsg, 
                                     AC_CW_MSG_CFGSTATUS_T *pstCfgStatus);
extern UINT32 ac_cw_msg_decoder_cfg_status_response(UINT32 ulLen, 
                                             UINT8* pucMsg, 
                                             AC_CW_MSG_CFGSTATUSRESPONSE_T *pstRsp);

extern UINT32 ac_cw_msg_decoder_cfg_update_request (UINT32 ulLen, 
                                                              UINT8* pucMsg, 
                                       AC_CW_MSG_CFGUPDATEREQUEST_T *pstReq);
extern UINT32 ac_cw_msg_decoder_cfg_update_response (UINT32 ulLen, 
                                                     UINT8* pucMsg, 
                                                     AC_CW_MSG_CFGUPDATERESPONSE_T *pstRsp);
extern UINT32 ac_cw_msg_decoder_change_state_event_request  (UINT32 ulLen, 
                                                             UINT8* pucMsg, 
                                                             AC_CW_MSG_CHANGESTATEEVENTREQUEST_T *pstReq);
extern UINT32 ac_cw_msg_decoder_change_state_event_response  (UINT32 ulLen, 
                                                              CHAR* pucMsg, 
                                                              AC_CW_MSG_CHANGESTATEEVENTRESPONSE_T *pstRsp);
extern UINT32 ac_cw_msg_decoder_wtp_event_request  (UINT32 ulLen, 
                                                      UINT8* pucMsg, 
                                                      AC_CW_MSG_WTPEVENTREQUEST_T *pstReq);


#endif /* _AC_CW_DECODER_H */
/******************************* 头文件结束 **********************************/

