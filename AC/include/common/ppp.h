/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  PAP/CHAP��֤ͷ�ļ�
* �޸���ʷ: 
* 2009-4-1     Ҷ����            �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/
#ifndef  __PPP_H__
#define  __PPP_H__

#ifdef __cplusplus
extern "C" {
#endif

#define RADIUS_PPP_POOLS_SIZE	AC_DEVM_AUTHSERVERS_NUM_MAX

extern struct radius_client_data * g_pstRadiusPpp ;


int hostapd_radius_ppp_init(struct radius_client_data ** ppp, struct hostapd_radius_servers * pstRadiusCfg, u32 setid) ;
void hostapd_radius_ppp_deinit(struct radius_client_data ** ppp) ;

int hostapd_radius_ppp_req(BYTE * auth_req, UINT16 len) ;
int hostapd_radius_ppp_reset(struct radius_client_data * ppp) ;
int hostapd_radius_ppp_change(struct radius_client_data * ppp, struct hostapd_radius_server *nserv, struct hostapd_radius_server *oserv, int auth) ;


#ifdef __cplusplus
}
#endif

#endif
