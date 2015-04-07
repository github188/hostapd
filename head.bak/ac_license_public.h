/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��:  LICENSE �ӿڹ���ͷ�ļ�
* �޸���ʷ: 
* 2012-1-5     ���             �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_LICENSE_PUBLIC_H
#define  _AC_LICENSE_PUBLIC_H


#if defined (_LINUX_) 	
extern TPID    gtDbCtrlProc;
extern TPID    gtDbCmPid;
extern TPID    gtAcCwPid;
extern TPID    gtWtpCwPid;
extern TPID    gtComPid;
extern TPID    gtHostapdPid;
extern TPID    gtOamPid;
extern TPID    gtAcmPid;
//extern TPID		gtSmPid;
extern TPID		gtRrmPid;
extern TPID		gtPortalPid;
extern TPID		gtWapiPid;
extern TPID		gtSysmPid;
extern TPID		gtUsrmPid;
extern TPID		gtApOmaPid;
extern TPID		gtOssMsPid;
extern TPID		gtLicensePid;
#endif

/******************************************************************************/
/*****************************LICENSEģ����Ϣ�Ŷ���*****************************/
/* ��Ϣ�Ŷ��忪ʼ*/

#define AC_LICENSE_TIMER_SCAN_VERIFY				TIMER28	     	/*  	������License ��֤��ʱ��  */
#define AC_LICENSE_TIMEOUT_SCAN_VERIFY			EV_TIMER28
#define AC_LICENSE_TIMER_SCAN_VERIFY_LEN			18000		/* ��λ100ms 30���� */

#define AC_LICENSE_IF_MAX    100        /* LICENSEģ�����ӿ���*/

/* ��׼�ӿ���Ϣ��*/
#define AC_LICENSE_SET_SVIP_MSG					(EV_LICENSE_BEGIN+1)      /* ����license��������ַ */
#define AC_LICENSE_GET_TESTTIME_MSG            	(EV_LICENSE_BEGIN+2)   	  /* ��ѯac������ʱ�� */
#define AC_LICENSE_GET_SVIP_MSG					(EV_LICENSE_BEGIN+3)      /* ��ѯlicense��������ַ */
#define AC_LICENSE_GET_FILE_CHECK_MSG			(EV_LICENSE_BEGIN+4)      /* ��ѯlicense�ļ�����Ч�� */
#define AC_LICENSE_KILL_TIMER26_MSG			    (EV_LICENSE_BEGIN+5)      /* ɱ���ϱ���ʱ��ʱ�� */
#define AC_LICENSE_GET_AP_FILE_CHECK_MSG		(EV_LICENSE_BEGIN+6)      /* ��ѯAPlicense�ļ�����Ч�� */

/* ��license�����������Ϣ�� */
#define AC_LICENSE_MSG_TO_SV_REPORT_REQ			(WORD16)(0x01)      /* AC->License���������,License�ϱ���Ϣ */
#define SV_MSG_TO_AC_LICENSE_IP_CHANGE_ACK		(WORD16)(0x02)      /* AC->License���������,License������IP���ACK��Ϣ */
#define SV_MSG_TO_AC_LICENSE_TORT_ACK			(WORD16)(0x03)      /* AC->License���������,��Ȩ����ACK��Ϣ */

#define AC_LICENSE_MSG_TO_SV_REPORT_ACK			(WORD16)(0x10)      /* License���������->AC,�ϱ�ACK��Ϣ */
#define SV_MSG_TO_AC_LICENSE_IP_CHANGE_REQ		(WORD16)(0x20)      /* License���������->AC,License������IP�����Ϣ */
#define SV_MSG_TO_AC_LICENSE_TORT_REQ			(WORD16)(0x30)      /* License���������->AC,��Ȩ������Ϣ */



/* ��Ϣ�Ŷ������*/

/* ȡֵ�궨�忪ʼ*/
#define APP_MODULE_LICENSE APP_MODULE_DB

/* ȡֵ�궨�����*/
/******************************************************************************/

/******************************************************************************/
/* �ӿڽṹ�嶨�忪ʼ*/
typedef struct
{
	UINT8	aucProxyNewIp[4];	/* License�������������IP��ַ */
} AC_LICENSE_SET_SVIP_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
} AC_LICENSE_SET_SVIP_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
} AC_LICENSE_GET_SVIP_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT8	aucProxyOldIp[4];	/* License����������ľ�IP��ַ */
} AC_LICENSE_GET_SVIP_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
} AC_LICENSE_GET_TESTTIME_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
	UINT32  ulSurplusTimes;  /* License������ʣ��ʱ��(��λ��s) */
	UINT32  ulSurauthorTimes;  /* License��Ȩ����ʣ��ʱ��(��λ��s) */
} AC_LICENSE_GET_TESTTIME_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
}AC_LICENSE_GET_FILE_CHECK_REQ_T;

typedef struct
{
        UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
        UINT32  ulWebStat;             /* web��ʾ״̬
                                                        0-license��֤�ɹ�
                                                        1-licenseӲ����Ϣ����
                                                        2-license�㷨����
                                                        3-ac�����ڵ���
                                                        4-ac������״̬��
                                                        ...
                                                        11-ap���빦�ܴ���
                                                        12-ac�������ap��Ŀ���ܴ���
                                                        13-sta���빦�ܴ���
                                                        14-ac�������sta��Ŀ���ܴ���
                                                        15-license��Ȩʱ�䵽��(web��������)
                                                        ...
                                                        */
}AC_LICENSE_GET_FILE_CHECK_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
}AC_LICENSE_GET_AP_FILE_CHECK_REQ_T;

typedef struct
{
        UINT32	ulRet;	/* ����ֵ��AC_OK��ʾ�ɹ���������ʾ������ */
        UINT32  ulWebStat;             /* web��ʾ״̬
                                                        0-license��֤�ɹ�
                                                        1-licenseӲ����Ϣ����
                                                        2-license�㷨����
                                                        */
}AC_LICENSE_GET_AP_FILE_CHECK_RSP_T;


/* ��LICENSE��������������Ϣͷ����*/
typedef struct 
{
    UINT32	ulMsgId;
    UINT32	ulMsgLen;
}  LICENSE_SV_MSGHDR_T;

/* License�ϱ���Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�ķ���IP Ϊ0����License�����������д */
    UINT32 ulUDPort;                /* AC�ķ���UDP�˿�Ϊ0����License�����������д */
    CHAR   ulTimeStamp[16];   /* ʱ���20120112170000 */
    UINT32 ulRandom;              /* ����� */
}  AC_LICENSE_MSG_TO_SV_REPORT_REQ_T;

/* License������IP���ACK��Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�ķ���IP Ϊ0����License�����������д */
    UINT32 ulUDPort;                /* AC�ķ���UDP�˿�Ϊ0����License�����������д */
}  SV_MSG_TO_AC_LICENSE_IP_CHANGE_ACK_T;

/* ��Ȩ����ACK��Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�ķ���IP Ϊ0����License�����������д */
    UINT32 ulUDPort;                /* AC�ķ���UDP�˿�Ϊ0����License�����������д */
}  SV_MSG_TO_AC_LICENSE_TORT_ACK_T;




/* �ϱ�ACK��Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�Ľ���IP  */
    UINT32 ulUDPort;                /* AC�Ľ���UDP�˿� */
}  AC_LICENSE_MSG_TO_SV_REPORT_ACK_T;

/* License������IP�����Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�Ľ���IP  */
    UINT32 ulUDPort;                /* AC�Ľ���UDP�˿� */
    UINT8   aucProxyOldIp[4];      /* License����������ľ�IP��ַ */
    UINT8   aucProxyNewIp[4];    /* License�������������IP��ַ */
}  SV_MSG_TO_AC_LICENSE_IP_CHANGE_REQ_T;

/* ��Ȩ������Ϣ */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* ��Ȩ���кŴ�license�ļ�����ȡ */
    UINT8   aucIp[4];                /* AC�Ľ���IP  */
    UINT32 ulUDPort;                /* AC�Ľ���UDP�˿� */
    UINT32 ulTortType;            /* AC��Ȩ����  */
}  SV_MSG_TO_AC_LICENSE_TORT_REQ_T;


/* license����ʱ��Ҫ����Ϣ(TLV��ʽ) */
#define LICENSE_OMC_CUSTNAME   (UINT32)128
#define LICENSE_OMC_AUTHORFUNC   (UINT32)16
#define LICENSE_OMC_AUTHORAPCAP   (UINT32)10
#define LICENSE_OMC_AUTHORUSERCAP   (UINT32)10
#define LICENSE_OMC_AUTHORTIME   (UINT32)16
#define LICENSE_OMC_AUTHORLASTUSER   (UINT32)128
#define LICENSE_OMC_AUTHORNAME   (UINT32)128
#define LICENSE_OMC_AUTHORSERIALNUM   (UINT32)24

#define LICENSE_OMC_APFUNC   (UINT32)16
#define LICENSE_OMC_APMACSUM   (UINT32)10
#define LICENSE_OMC_APBEGINMAC   (UINT32)17
#define LICENSE_OMC_APENDMAC   (UINT32)17
#define LICENSE_OMC_APSERIALNUM   (UINT32)24

/* license����ʱ��Ҫ����Ϣ(TLV��ʽ) */
typedef struct
{
	CHAR   acCustName[LICENSE_OMC_CUSTNAME];   /* �ͻ����� */ 
	CHAR   ulAuthorFunc[LICENSE_OMC_AUTHORFUNC];  /* ��Ȩ����[16]��(
	                                                [0]=1��ʾ����ap�������� 0-�� 1-��
	                                                [1]=1��ʾ����sta�������� 0-�� 1-��
	                                                [2]=1��ʾ�Ƿ�֧�ּ���ת��ģʽ 0-�� 1-��
	                                                [3]=1 0-�� 1-��
	                                                [4]=1 0-�� 1-��
	                                                [5]=1 0-�� 1-��
	                                                [6]=1 0-�� 1-��
	                                                [7]=1 0-�� 1-��
	                                                [8]=1 0-�� 1-��
	                                                [9]=1 0-�� 1-��
	                                                ) */
	UINT32 ulAuthorApCapacity;       /* ��Ȩap����[10] */
	UINT32 ulAuthorUserCapacity;        /* ��Ȩuser����[10] */
	CHAR   ulAuthorTime[LICENSE_OMC_AUTHORTIME];            /* ��Ȩʱ�䣨���ޣ�1999061820001232 */
	CHAR   acAuthorLastUser[LICENSE_OMC_AUTHORLASTUSER];     /* �����û� */
	CHAR   acAuthorName[LICENSE_OMC_AUTHORNAME];          /* ��Ȩ���� */
	CHAR   ulAuthorSerialNum[LICENSE_OMC_AUTHORSERIALNUM];     /* ��Ȩ���к� */
}AC_LICENSE_OMC_T;


/* ap license����ʱ��Ҫ����Ϣ(TLV��ʽ) */
typedef struct
{
	CHAR   ulApFunc[LICENSE_OMC_APFUNC];  /* ��Ȩ����[16]��(
	                                                [0]=1��ʾ����key�Ƿ�������apmac��鹦�� 0-�� 1-��
	                                                [1]=1 0-�� 1-��
	                                                [2]=1 0-�� 1-��
	                                                [3]=1 0-�� 1-��
	                                                [4]=1 0-�� 1-��
	                                                ) */
	UINT32 ulApMacSum;       /* ��ǰlicense����ЧMAC��Ŀ */
	CHAR   acApBeginMac[LICENSE_OMC_APBEGINMAC];       /* ��ʼMAC 80:8B:5C:00:2B:CE */
	CHAR   acApEndMac[LICENSE_OMC_APENDMAC];           /* ����MAC 80:8B:5C:00:37:85 */
	CHAR   acApSerialNum[LICENSE_OMC_APSERIALNUM];     /* ��Ȩ���к� */
}AP_LICENSE_OMC_T;

/* �ӿڽṹ�嶨�����*/
/******************************************************************************/

/******************************************************************************/
/* ����������ʼ*/
extern VOID ac_license_set_svip (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_get_time (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_get_svip_ex (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_check_ap_file_verify (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_check_file_verify (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern int ap_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
extern int ac_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
extern int Create_hash_encrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int Create_hash_decrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);

/* ������������*/
/******************************************************************************/

#endif /* _AC_LICENSE_PUBLIC_H */
/******************************* ͷ�ļ����� **********************************/



