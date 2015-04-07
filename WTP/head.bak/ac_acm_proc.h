/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  ���ɿ���ģ������ͷ�ļ�
* �޸���ʷ: 
* 2008-4-15     ������              �½�
*
******************************************************************************/

/*
2009-4-10
��������
1�����ɾ���ֻ��GDEV�㴦��VAP/WTP/AC�㲻�����ɾ��⴦��
2�������ɾ���ӿ����ô���WTP�㣬����WTP�ַ���GDEV�����ٴ���VAP/AC�У�
3�����ɾ���QOS���ø���Ϊ�����������׶��ݲ�ʵ�֣�
*/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_ACM_PROC_H
#define  _AC_ACM_PROC_H

/******************************** �궨�� *************************************/
#if 0
#define AC_ACM_AC_RSV_STA       2           /* ACԤ���ն��� */
#define AC_ACM_WTP_RSV_STA      2           /* WTPԤ���ն��� */
#define AC_ACM_IF_RSV_STA       2           /* �ӿ�Ԥ���ն��� */
#define AC_ACM_VAP_RSV_STA      2           /* VAPԤ���ն��� */
#endif

#define ACM_MAC_LIST_NUM	128
#define ACM_MAC_POLICY_ADD	0
#define ACM_MAC_POLICY_DEL	1
#define ACM_MAC_POLICY_MODIFY	2

/******************************** �ṹ�嶨�� *********************************/
typedef AC_DEVM_LOADBALANCE_CONFIG_T ACM_CONFIG_T ;

/*�����豸ID�б�*/
typedef struct ACM_GDEVID_LIST_TAG{
	AC_VDEVID_T stGdevId ;
	struct ACM_GDEVID_LIST_TAG * pstNext ;
}ACM_GDEVID_LIST_T ;

/* AC���ɿ��Ʋ��� */
typedef struct {
	UINT32  ulAcId;         /* AC ID */

    ACM_CONFIG_T stAcmCfg ;	/*����������ò���*/
    AC_DEVM_VLANACCMACPOLICY_CONFIG_T stMacPolicy;
	UINT32 ulMacPolicyValid;
	AC_DEVM_VLANACCMAC_CONFIG_T stMacList[ACM_MAC_LIST_NUM];
	UINT32 ulMacListNum;
	
    UINT32 ulUserMaxSwitch;
    UINT32 ulUserMax ;
	
    UINT32 lUserCurrent ;	/*��ǰ������û���Ŀ*/
    UINT32 ulQosCurrent ;	/*��ǰ��������QOS�����ܺ�,Kbps*/
} ACM_AC_T;

/* VAP���ɿ��Ʋ��� */
typedef struct {
    UINT32      ulValid;        /* ��Ч��� */
    AC_VAPID_T  stVapId;        /* VAP ID */

    ACM_CONFIG_T stAcmCfg ;	/*����������ò���*/
	
    UINT32 lUserCurrent ;	/*��ǰ������û���Ŀ*/
    UINT32 ulQosCurrent ;	/*��ǰ��������QOS�����ܺ�,Kbps*/
} ACM_VAP_T;

/*���豸���ɿ��Ʋ��� */
typedef struct {
    UINT32      		ulValid;		/* ��Ч��� */
    AC_VDEVID_T   stGdevId;	/* ���豸 ID */
	
    ACM_CONFIG_T stAcmCfg ;	/*����������ò���*/
    ACM_GDEVID_LIST_T * pstNeighborList ;
	
    UINT32 lUserCurrent ;	/*��ǰ������û���Ŀ*/
    UINT32 ulQosCurrent ;	/*��ǰ�豸��������bps*/
	
    ACM_VAP_T astVapAcmCfg[AC_VAP_NUM_MAX_PER_IF];
} ACM_GDEV_T;

/* WTP���ɿ��Ʋ��� */
typedef struct {
    UINT32      ulValid;        /* ��Ч��� */
    AC_WTPID_T  stWtpId;        /* WTP ID */
	
    ACM_CONFIG_T stAcmCfg ;	/*����������ò���*/
	
    UINT32 lUserCurrent ;	/*��ǰ������û���Ŀ*/
    UINT32 ulQosCurrent ;	/*��ǰ��������QOS�����ܺ�,Kbps*/
	
    ACM_GDEV_T  astGdevAcm[AC_VDEV_NUM_MAX_PER_WTP];
} ACM_WTP_T;

/******************************** ȫ�ֱ������� ********************************/

/******************************** �ⲿ����ԭ������ ****************************/


/********************************** ����ԭ������ ******************************/

#endif /* _AC_LCS_PROC_H */
/******************************* ͷ�ļ����� **********************************/

