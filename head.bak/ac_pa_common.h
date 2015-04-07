#ifndef AC_PA_COMMON_H
#define AC_PA_COMMON_H

#pragma pack(push, 1)

/* portal���������ļ� */
#define PORTAL_CONF             "portal.conf"

#define AC_PA_CHECKPS_USERIP    254,254,254,254

#define CHAP_FMT		"0x%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X "
#define CHAP_ARG(x)	 \
    ((UINT8*)(x))[0],  ((UINT8*)(x))[1],  ((UINT8*)(x))[2],  ((UINT8*)(x))[3], \
	((UINT8*)(x))[4],  ((UINT8*)(x))[5],  ((UINT8*)(x))[6],  ((UINT8*)(x))[7], \
	((UINT8*)(x))[8],  ((UINT8*)(x))[9],  ((UINT8*)(x))[10], ((UINT8*)(x))[11], \
	((UINT8*)(x))[12], ((UINT8*)(x))[13], ((UINT8*)(x))[14], ((UINT8*)(x))[15]

#define CHALLENGE_FMT   CHAP_FMT
#define CHALLENGE_ARG   CHAP_ARG

/* ��ʱ�� */
#define TIMER_AC_PA_SCAN_TIMER                  (TIMER0)
#define EV_AC_PA_SCAN_TIMER_MSG                 (EV_TIMER0)

#define TIMER_AC_PA_IP_SCAN_TIMER               (TIMER1)
#define EV_AC_PA_IP_SCAN_TIMER_MSG				(EV_TIMER1)

#define TIMER_AC_PA_CHECKPS_TIMER               (TIMER2)
#define EV_AC_PA_CHECKPS_TIMER_MSG              (EV_TIMER2)

#define TIMER_AC_PA_USER_TIMER			        (TIMER20)
#define EV_AC_PA_USER_TIMEROUT_MSG		        (EV_TIMER20)

/* PORTAL Server��AC֮�����Ϣ */
#define PORTAL_MSG_REQ_CHALLENGE	0x01   	/* PS->PA	Portal Server ��AC�豸���͵�����Challenge���� */
#define PORTAL_MSG_ACK_CHALLENGE	0x02	/* PS<-PA	AC�豸��Portal Server����Challenge���ĵ���Ӧ���� */
#define PORTAL_MSG_REQ_AUTH	        0x03	/* PS->PA	Portal Server��AC�豸���͵�������֤���� */
#define PORTAL_MSG_ACK_AUTH	        0x04	/* PS<-PA	AC�豸��Portal Server������֤���ĵ���Ӧ���� */
#define PORTAL_MSG_REQ_LOGOUT	    0x05	/* PS->PA	��ErrCode�ֶ�ֵΪ0x00����ʾ�˱�����Portal Server��AC�豸���͵������û����߱��ģ�
                                                        ��ErrCode�ֶ�ֵΪ0x01����ʾ�ñ�����Portal Server���͵ĳ�ʱ���ģ�
                                                        ��ԭ����Portal Server�����ĸ��������ڹ涨ʱ����û���յ���Ӧ���ġ�*/
#define PORTAL_MSG_ACK_LOGOUT       0x06	/* PS<-PA	AC�豸��Portal Server�������߱��ĵ���Ӧ���� */
#define PORTAL_MSG_AFF_ACK_AUTH	    0x07	/* PS->PA	Portal Server���յ�����֤�ɹ���Ӧ���ĵ�ȷ�ϱ��ģ�*/
#define PORTAL_MSG_NTF_LOGOUT       0x08	/* PA->PS	�û���ǿ������֪ͨ���� */
#define PORTAL_MSG_REQ_INFO	        0x09	/* PS->PA	��Ϣѯ�ʱ��� */
#define PORTAL_MSG_ACK_INFO	        0x0a	/* PA->PS	��Ϣѯ�ʵ�Ӧ���� */

#define PORTAL_MSG_ACK_NTF_LOGOUT   0x0e    /* PS->PA   �û���ǿ������֪ͨ��Ӧ���� */

#define PORTAL_MSG_REQ_MACBINDING_INFO	0x30	/*AC������ķ����MAC�󶨵Ĳ�ѯ����*/
#define PORTAL_MSG_ACK_MACBINDING_INFO	0x31	/*�����Ļ�ӦAC�豸MAC�󶨲�ѯ��Ӧ����*/
#define PORTAL_MSG_NTF_USER_LOGON		0x32	/*AC�������֪ͨ�û����߱���*/
#define PORTAL_MSG_NTF_USER_LOGOUT		0x34	/*AC�������֪ͨ�û����߱���*/
#define PORTAL_MSG_REQ_USER_OFFLINE		0x36	/*��������AC�����ǿ���û�����*/

/* Portal�������� */
#define PORTAL_ATTR_USERNAME	    0x01	/* <=253 ��e���û���������Ϊ�����û��ֻ����롱��
                                                    ȫ��/ʡ��Ԥ���ѿ��û����ƣ�13λ���֣�
                                                    Ϊ����������ε���Ҫ��֧��253�ֽڵĳ��û����� */
#define PORTAL_ATTR_PASSWORD	    0x02	/* <=16	�û��ύ���������� */
#define PORTAL_ATTR_CHALLENGE	    0x03	/* 16 Chap��ʽ���ܵ�ħ���� */
#define PORTAL_ATTR_CHAPPASSWORD	0x04	/* 16 ����Chap��ʽ���ܺ������ */

/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define PORTAL_ATTR_ERRID			0x05    /* ��errcode��Ϊ��ʱ��errid */

#define PORTAL_ATTR_ERRID_LEN		0x07    /* errid����+1+1 */
/*begin bug#1926 cmcc test fangz 2013.2.20*/

#define PORTAL_ATTR_TEXTINFO	0x05
#define PORTAL_ATTR_UPLINKFLUX	0x06
#define PORTAL_ATTR_DOWNLINKFLUX	0x07
#define PORTAL_ATTR_PORT	0x08

#define PORTAL_ATTR_BASIP					0x0a	/*AC��IPv4��ַ��������ţ�*/
#define PORTAL_ATTR_SESSIONID				0x0b	/*�ͻ���MAC��ַ*/
#define PORTAL_ATTR_NASID					0x30	/*�ַ���*/
#define PORTAL_ATTR_SESSION_STARTTIME	0x31	/*�û�����ʱ�䣨��׼ʱ�䣩��ȡֵΪ1970������������*/
#define PORTAL_ATTR_SESSION_STOPTIME		0x32	/*�û�����ʱ�䣨��׼ʱ�䣩��ȡֵΪ1970������������*/
#define PORTAL_ATTR_SESSION_TIME			0x33	/*�û�����ʱ������λΪ��*/
#define PORTAL_ATTR_USER_AGENT			0x34	/*�ն��������User-Agent�ֶΣ�PORTAL��֤�ض���ʱ����Я�����ֶ�*/
#define PORTAL_ATTR_INPUT_OCTETS			0x35	/*�û������������ֽ���*/
#define PORTAL_ATTR_OUTPUT_OCTETS		0x36	/*�û������������ֽ���*/
#define PORTAL_ATTR_INPUT_PACKETS			0x37	/*�û����������İ�����*/
#define PORTAL_ATTR_OUTPUT_PACKETS		0x38	/*�û����������İ�����*/
#define PORTAL_ATTR_INPUT_GIGAWORDS		0x39	/*�û�����������G�ֽ���*/
#define PORTAL_ATTR_OUTPUT_GIGAWORDS	0x3a	/*�û�����������G�ֽ���*/

/* Э��İ汾�� */
#define PORTAL_VER_1                0x01

/* Portal��Ϣ��ErrCode���� */
/* ��TypeֵΪACK_CHALLENGE��*/
#define PORTAL_ACK_CHALLENGE_SUCCESS        0   /* ��ʾAC�豸����Portal Server����Challenge�ɹ���*/
#define PORTAL_ACK_CHALLENGE_ERR_DENY       1   /* ��ʾAC�豸����Portal Server����Challenge���ܾ���*/
#define PORTAL_ACK_CHALLENGE_ERR_AUTHED     2   /* ��ʾAC�豸����Portal Server�������ѽ�����*/
#define PORTAL_ACK_CHALLENGE_ERR_BUSY       3   /* ��ʾAC�豸����Portal Server��һ���û�������֤�����У����Ժ����ԣ�*/
#define PORTAL_ACK_CHALLENGE_ERR_FAIL       4   /* ��ʾAC�豸����Portal Server���û�����Challengeʧ�ܣ��������󣩣�*/
/*  */
#define PORTAL_ACK_CHALLENGE_ERR_TIMEOUT    5   /* ��ʾAC�豸�����û�Challenge��ʱ */
/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_VALID_ACCOLATED   "AC101"   /*�û�������֤��IP��ַ�Ǳ�AC�����ĵ�ַ���е���Ч��ַ���������ַĿǰ�Ѿ�ͨ����֤����*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_INVALID           "AC102"/*AC�����û�������֤��IP��ַ���Ǳ�AC�����ĵ�ַ���е���Ч��ַ*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_VALID_UNACCOLATED  "AC103" /*AC�����û�������֤��IP��ַ�Ǳ�AC�����ĵ�ַ���е���Ч��ַ���������ַĿǰ��δ������û�*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_OTHERS             "AC999"  /*����������Ϣ*/
/*end bug#1926 cmcc test fangz 2013.2.20*/

/* ��TypeֵΪACK_AUTH��*/
#define PORTAL_ACK_AUTH_SUCCESS             0   /* ��ʾAC�豸����Portal Server���û���֤�ɹ���*/
#define PORTAL_ACK_AUTH_ERR_DENY            1   /* ��ʾAC�豸����Portal Server���û���֤���󱻾ܾ���*/
#define PORTAL_ACK_AUTH_ERR_AUTHED      	2   /* ��ʾAC�豸����Portal Server�������ѽ�����*/
#define PORTAL_ACK_AUTH_ERR_BUSY            3   /* ��ʾAC�豸����Portal Server��һ���û�������֤�����У����Ժ����ԣ�*/
#define PORTAL_ACK_AUTH_ERR_FAIL            4   /* ��ʾAC�豸����Portal Server���û���֤ʧ�ܣ��������󣩣�*/
/* */
#define PORTAL_ACK_AUTH_ERR_TIMEOUT         5   /* ��ʾAC�豸�����û���֤��ʱ */
#define PORTAL_ACK_AUTH_ERR_DISORDER        6   /* ��ʾAC�豸����Ȩ���� */
#define PORTAL_ACK_AUTH_ERR_PWDERR          7   /* ��ʾAC�豸���û�����ȱʧ */

/* ��TypeֵΪREQ_LOGOUT��*/
#define PORTAL_REQ_LOGOUT_NORMAL            0   /* ��ʾ�˱�����Portal Server����AC�豸���������߱���*/
#define PORTAL_REQ_LOGOUT_TIMEOUT           1   /* ��ʾ�˱�������Portal Serverû���յ�AC�豸�����ĶԸ����������Ӧ���ģ�
                                                   ����ʱ��ʱ�䵽������ʱ��ʱ��Portal Server����AC�豸�ı��ģ�*/
/* ��TypeֵΪACK_LOGOUT��*/
#define PORTAL_ACK_LOGOUT_SUCCESS           0   /* ��ʾAC�豸����Portal Server���û����߳ɹ���*/
#define PORTAL_ACK_LOGOUT_ERR_DENY          1   /* ��ʾAC�豸����Portal Server���û����߱��ܾ���*/
#define PORTAL_ACK_LOGOUT_ERR_FAIL          2   /* ��ʾAC�豸����Portal Server���û�����ʧ�ܣ��������󣩣�*/

/* ��TypeֵΪNTF_LOGOUT */
#define PORTAL_NTF_LOGOUT_NORMAL            0
#define PORTAL_NTF_LOGOUT_TIMEOUT           1   /* ��ʾUSRMģ�鷢�����û���ʱ����������������� */
#define PORTAL_NTF_LOGOUT_DELUSER           2   /* ��ʾUSRMģ��ɾ���û���֪ͨ����������������� */

/* ��TypeֵΪACK_NTF_LOGOUT */

#define PORTAL_MAX_ATTR_LEN                 1024/* Ŀǰ��Ϣ��Attr����������REQ_AUTH,������512�ֽ� */

/* �û�״̬ */
#define PORTAL_USER_STATE_NULL              0
#define PORTAL_USER_STATE_REQ_MACBINDING	1		/*����REQ_MACBINDING*/
#define PORTAL_USER_STATE_ACK_MACBINDING	2		/*���յ�ACK_MACBINDING*/
#define PORTAL_USER_STATE_START_AUTH        10      /* ����ACK_CHALLENGEʱ */
#define PORTAL_USER_STATE_AAA_AUTH          20      /* ����AUTH_REQʱ */
#define PORTAL_USER_STATE_AFFIRM_AUTH       30      /* ����ACK_AUTHʱ */
#define PORTAL_USER_STATE_AUTH_OVER         40      /* �յ�AFF_ACK_AUTH */
#define PORTAL_USER_STATE_AUTH_FAIL         PORTAL_USER_STATE_NULL

/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define DHCP_USER_IP_VALID_ALLOCATED     0 /*DHCP ����PA��ip�Ѿ����䣬PA�ж��Ƿ���֤����*/
#define DHCP_USER_IP_INVALID             1 /*DHCP����PA��ip���ǵ�ַ���е�ַ*/
#define DHCP_USER_IP_VALID_UNALLOCATED   2 /*DHCP ����PA��ip����δ����*/
#define DHCP_USER_IP_ERR                 3 /*��������*/
/*end bug#1926 cmcc test fangz 2013.2.20*/

/* Portal Э����Ϣ��ʽ */
#define PORTAL_MSG_HEAD \
    UINT8   ucVer;	        /* Э��İ汾�ţ�����Ϊ1�ֽڣ�Ŀǰ�����ֵΪ0x01��*/\
    UINT8   ucType;	        /* ���ĵ����ͣ�����Ϊ1�ֽڡ�*/\
    UINT8   ucAuthType;	    /* �û�����֤��ʽ������Ϊ1�ֽڣ�ֻ��TypeֵΪ0x03����֤�����������壺chap��ʽ��֤��0x00����Pap��ʽ��֤��0x01��*/\
    UINT8   ucRsv;	        /* �����ֶΣ�����Ϊ1�ֽڣ������б�����ֵΪ0��*/\
                            \
    UINT16  usSerialNo;	    /* ���ĵ����кţ�����Ϊ2�ֽڣ���Portal Server������ɣ���Portal Server����AC�ı��ģ�\
                               ÿһ����AC�豸����Portal Server����Ӧ���ĵ�SerialNo�����Portal Server���͵���Ӧ�����ĵ�SerialNoһ����*/\
    UINT16  usReqID; 	    /* AC������� */\
                            \
    UINT8   aucUserIP[4];   /* Portal�û���IP��ַ��������4�ֽڣ���Portal Server���ݻ�õ�IP��ַ��д�������*/\
                            \
    UINT16  usUserPort;     /* Ŀǰû���õ��������б�������ֵΪ0��*/\
    UINT8   ucErrCode;	    /* ��Type�ֶ�һ���ʾһ�������壬����Ϊ1�ֽڡ�*/\
    UINT8   ucAttrNum 	    /* ��ʾ����ɱ䳤�ȵ������ֶ����Եĸ���������Ϊ1�ֽڣ���ʾ����������255�����ԣ�����ֵ�����еı����ж�Ҫ���ݾ��������ֵ��*/

typedef struct
{
    UINT8   ucVer;
    UINT8   ucType;
    UINT8   ucAuthType;
    UINT8   ucRsv;

    UINT16  usSerialNo;
    UINT16  usReqID;

    UINT8   aucUserIP[4];

    UINT16  usUserPort;
    UINT8   ucErrCode;
    UINT8   ucAttrNum ;
}AC_PA_PORTAL_MSG_HEAD_T;

/* Portal��Ϣ */
typedef struct
{
    PORTAL_MSG_HEAD;
    UINT8   aucAttr[PORTAL_MAX_ATTR_LEN];
}AC_PA_PORTAL_MSG_T;

/* ��PA�߳�ת������Ϣ */
typedef struct
{
    SOCKADDR    stPsAddr;
    INT32       iAddrLen;

    AC_PA_PORTAL_MSG_T  stPortalMsg;
}AC_PA_PORTAL_RELAY_MSG_T;


typedef struct
{
	UINT8 ucAttrType;
	UINT8 ucAttrLength;	/*��ͷ*/
}AC_PA_PORTAL_ATTR_T;


typedef struct
{
	UINT8 ucAttrType;
	UINT8 ucAttrLength;	/*��ͷ*/
	UINT32 ulAttrValue;
}AC_PA_PORTAL_ATTR_UINT4_T;


typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_REQ_CHALLENGE_T;

typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrChallenge;                        /* 0x03	�������ͣ�Challege�� */
    UINT8   ucAttrChallengeLen;                     /* 18 */
    UINT8   aucAttrChallenge[PORTAL_CHALLENGE_LEN]; /* ���������ֵ��Chap��ʽ���ܵ�ħ���� */
}AC_PA_PORTAL_ACK_CHALLENGE_T;

/*begin bug#1926 cmcc test fangz 2013.2.20*/
typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrErrID;                        /* 0x05	�������ͣ�Challege�� */
    UINT8   ucAttrErrIDLen;                     /* 7 */
    UINT8   aucAttrErrID[PORTAL_ERRID_LEN]; /* ���������ֵ:0xAC101:ip��ַ��Ч��������֤����
	          							  0xAC102:IP��ַ���ǵ�ַ���е���Ч��ַ
	          							  0xAC103:IP��ַ�ǵ�ַ���е���Ч��ַ���������ַĿǰ��δ������û�
	          							  0xAC999:����������Ϣ*/
}AC_PA_PORTAL_ACK_CHALLENGE_ERR_T;/*��ERR CODE��Ϊ0 ʱ������һ��ERR ID */
/*end bug#1926 cmcc test fangz 2013.2.20*/

typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrUserName;
    UINT8   ucAttrUserNameLen;
    CHAR    acAttrUserName[PORTAL_MAX_USERNAME_LEN+1];

    /* chap��֤ʱΪchapPwd��pap��֤ʱΪpwd */
    UINT8   ucAttrPassword;
    UINT8   ucAttrPasswordLen;
    CHAR    acAttrPassword[PORTAL_MAX_PASSWORD_LEN+1];

#if 0
    UINT8   ucAttrChallenge;
    UINT8   ucAttrChallengeLen;
    UINT8   aucAttrChallenge[PORTAL_CHALLENGE_LEN];
#endif
}AC_PA_PORTAL_REQ_AUTH_T;

/*begin bug#1926 cmcc test fangz 2013.2.20*/
typedef struct
{
	 PORTAL_MSG_HEAD;

    UINT8   ucAttrErrID;                        /* 0x05	�������ͣ�Challege�� */
    UINT8   ucAttrErrIDLen;                     /* 7 */
    UINT8   aucAttrErrID[PORTAL_ERRID_LEN]; /* ���������ֵ:AC201:AC��radiusͨѶ��ʱ����ͨѶ��������
						          						    AC999:����������Ϣ
						          							RCXXX:Radius���ظ�AC��access-reject�еĴ������*/
}AC_PA_PORTAL_ACK_AUTH_T;
//typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_ACK_AUTH_T;
/*end bug#1926 cmcc test fangz 2013.2.20*/


typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_AFF_ACK_AUTH_T;
typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_REQ_LOGOUT_T;
typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_ACK_LOGOUT_T;
typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_NTF_LOGOUT_T;
typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_REQ_INFO_T;
typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_ACK_INFO_T;

typedef union
{
    AC_PA_PORTAL_ACK_CHALLENGE_T    stAckChallenge;
    AC_PA_PORTAL_ACK_AUTH_T         stAckAuth;
    AC_PA_PORTAL_ACK_LOGOUT_T       stAckLogout;
    AC_PA_PORTAL_NTF_LOGOUT_T       stNtfLogout;
	UINT8 aucMsg[1024];
}AC_PA_PORTAL_ACK_MSG_U;

/* �û���ʱ����չ���� */
typedef struct
{
    UINT8       ucVer;
    UINT8       ucUserState;
    UINT8       ucType;
    UINT8       ucAuthType;

    UINT16      usSerialNo;

    UINT8       aucUserMac[6];
}AC_PA_USER_TIMER_EXT_DATA_T;

typedef struct
{
    UINT32      ulLinkErrCount;     /* ��Portal Server֮�����·�쳣������κη��ͳɹ������㣬�����ۼ� */
}AC_PA_ALARM_INFO_T;

#define AC_PA_MAX_PS_NUM    1024    /* AC�����������PS���� */
typedef struct
{
    UINT32      ulNum;
    UINT32      aulIP[AC_PA_MAX_PS_NUM];
}AC_PA_PS_LIST_T;

/* �ڲ���Ϣ */

typedef struct
{
    UINT32          ulMsgID;
    INT32           iCfgVersion;
}AC_PA_WEB_HEART_BEAT_IND_T;

typedef struct
{
    UINT32          ulMsgID;
}AC_PA_PABK_CFG_CHANGE_NTF_T;

#define AC_PA_MAX_SSID_LEN		    32
#define AC_PA_CHECK_SSID_NULL       0   /* ����� */
#define AC_PA_CHECK_SSID_IFEXIST    1   /* ���ּ��:���ӳ���ϵ�������� */
#define AC_PA_CHECK_SSID_FORCE      2   /* ǿ�Ƽ��:ӳ���ϵ������� */ 
typedef struct
{
    UINT8		    aucIP[4];
	CHAR		    acSSID[AC_PA_MAX_SSID_LEN+1];
	CHAR			aucResv[3];

	UINT32			ulCreateTime;		/* ӳ���ϵ���������ʱ�� */	
}AC_PA_IP_DATA_T;

typedef struct
{
    UINT8       aucHead[3];     // �ڲ���Ϣ��ǰ�����ֽڶ���0xff
    UINT8       ucMsgID;
}AC_PA_INNER_MSG_HEAD_T;

typedef struct 
{
    AC_PA_INNER_MSG_HEAD_T stMsgHead;

    UINT8		    aucIP[4];
	CHAR		    acSSID[AC_PA_MAX_SSID_LEN+1];
	CHAR			aucResv[3];
}AC_PA_HR_SET_IPSSID_NTF_T;

#define AC_PA_CTL_OK    0
#define AC_PA_CTL_ERR   1

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT32          ulAuthState;
#define AC_PA_CTL_USER_AUTHING      0x01
#define AC_PA_CTL_USER_AUTHED       0x02
#define AC_PA_CTL_USER_ALL          0xff
}AC_PA_CTL_LIST_USER_REQ_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT32          ulRetCode;      /* 0��ʾ�ɹ� */

    UINT32          ulUserNum;
    UINT8           aaucUserIP[1024][4];
}AC_PA_CTL_LIST_USER_ACK_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;
    UINT8           aucUserIP[4];
}AC_PA_CTL_GET_USER_REQ_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT32  ulRetCode;

    UINT8   ucVer;
    UINT8   ucUserState;
    UINT8   ucType;
    UINT8   ucAuthType;

    UINT16  usSerialNo;
    UINT16  usReqID;

    UINT8   aucUserIP[4];

    UINT16  usUserPort;
    UINT8   aucUserMac[6];

    CHAR    acUserName[PORTAL_MAX_USERNAME_LEN+1];
    CHAR    acPassword[PORTAL_MAX_PASSWORD_LEN+1];
    UINT8   aucChallenge[PORTAL_CHALLENGE_LEN];

}AC_PA_CTL_GET_USER_ACK_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT8           aucUserIP[4];
}AC_PA_CTL_DEL_USER_REQ_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT8           aucUserIP[4];
    UINT32          ulRetCode;      /* 0��ʾ�ɹ� */
}AC_PA_CTL_DEL_USER_ACK_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;
    UINT8           aucUserIP[4];
}AC_PA_CTL_LIST_IP_REQ_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT32          ulRetCode;      /* 0��ʾ�ɹ� */

    UINT32          ulUserNum;
    AC_PA_IP_DATA_T astIP[128];
}AC_PA_CTL_LIST_IP_ACK_T;

#pragma pack(pop)

#endif /* AC_PA_COMMON_H */



