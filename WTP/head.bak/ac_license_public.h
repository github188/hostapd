/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  LICENSE 接口功能头文件
* 修改历史: 
* 2012-1-5     吴彬             新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

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
/*****************************LICENSE模块消息号定义*****************************/
/* 消息号定义开始*/

#define AC_LICENSE_TIMER_SCAN_VERIFY				TIMER28	     	/*  	周期性License 验证定时器  */
#define AC_LICENSE_TIMEOUT_SCAN_VERIFY			EV_TIMER28
#define AC_LICENSE_TIMER_SCAN_VERIFY_LEN			18000		/* 单位100ms 30分钟 */

#define AC_LICENSE_IF_MAX    100        /* LICENSE模块最大接口数*/

/* 标准接口消息号*/
#define AC_LICENSE_SET_SVIP_MSG					(EV_LICENSE_BEGIN+1)      /* 设置license服务器地址 */
#define AC_LICENSE_GET_TESTTIME_MSG            	(EV_LICENSE_BEGIN+2)   	  /* 查询ac试用期时间 */
#define AC_LICENSE_GET_SVIP_MSG					(EV_LICENSE_BEGIN+3)      /* 查询license服务器地址 */
#define AC_LICENSE_GET_FILE_CHECK_MSG			(EV_LICENSE_BEGIN+4)      /* 查询license文件的有效性 */
#define AC_LICENSE_KILL_TIMER26_MSG			    (EV_LICENSE_BEGIN+5)      /* 杀掉上报超时定时器 */
#define AC_LICENSE_GET_AP_FILE_CHECK_MSG		(EV_LICENSE_BEGIN+6)      /* 查询APlicense文件的有效性 */

/* 与license服务器间的消息号 */
#define AC_LICENSE_MSG_TO_SV_REPORT_REQ			(WORD16)(0x01)      /* AC->License管理服务器,License上报消息 */
#define SV_MSG_TO_AC_LICENSE_IP_CHANGE_ACK		(WORD16)(0x02)      /* AC->License管理服务器,License服务器IP变更ACK消息 */
#define SV_MSG_TO_AC_LICENSE_TORT_ACK			(WORD16)(0x03)      /* AC->License管理服务器,侵权控制ACK消息 */

#define AC_LICENSE_MSG_TO_SV_REPORT_ACK			(WORD16)(0x10)      /* License管理服务器->AC,上报ACK消息 */
#define SV_MSG_TO_AC_LICENSE_IP_CHANGE_REQ		(WORD16)(0x20)      /* License管理服务器->AC,License服务器IP变更消息 */
#define SV_MSG_TO_AC_LICENSE_TORT_REQ			(WORD16)(0x30)      /* License管理服务器->AC,侵权控制消息 */



/* 消息号定义结束*/

/* 取值宏定义开始*/
#define APP_MODULE_LICENSE APP_MODULE_DB

/* 取值宏定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 接口结构体定义开始*/
typedef struct
{
	UINT8	aucProxyNewIp[4];	/* License代理服务器的新IP地址 */
} AC_LICENSE_SET_SVIP_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
} AC_LICENSE_SET_SVIP_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
} AC_LICENSE_GET_SVIP_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT8	aucProxyOldIp[4];	/* License代理服务器的旧IP地址 */
} AC_LICENSE_GET_SVIP_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
} AC_LICENSE_GET_TESTTIME_REQ_T;

typedef struct
{
	UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
	UINT32  ulSurplusTimes;  /* License试用期剩余时间(单位秒s) */
	UINT32  ulSurauthorTimes;  /* License授权期内剩余时间(单位秒s) */
} AC_LICENSE_GET_TESTTIME_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
}AC_LICENSE_GET_FILE_CHECK_REQ_T;

typedef struct
{
        UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
        UINT32  ulWebStat;             /* web显示状态
                                                        0-license验证成功
                                                        1-license硬件信息错误
                                                        2-license算法错误
                                                        3-ac试用期到期
                                                        4-ac试用期状态中
                                                        ...
                                                        11-ap接入功能错误
                                                        12-ac接入最大ap数目功能错误
                                                        13-sta接入功能错误
                                                        14-ac接入最大sta数目功能错误
                                                        15-license授权时间到期(web可以限制)
                                                        ...
                                                        */
}AC_LICENSE_GET_FILE_CHECK_RSP_T;

typedef struct
{
	CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
}AC_LICENSE_GET_AP_FILE_CHECK_REQ_T;

typedef struct
{
        UINT32	ulRet;	/* 返回值，AC_OK表示成功，其它表示错误码 */
        UINT32  ulWebStat;             /* web显示状态
                                                        0-license验证成功
                                                        1-license硬件信息错误
                                                        2-license算法错误
                                                        */
}AC_LICENSE_GET_AP_FILE_CHECK_RSP_T;


/* 与LICENSE服务器交互的消息头定义*/
typedef struct 
{
    UINT32	ulMsgId;
    UINT32	ulMsgLen;
}  LICENSE_SV_MSGHDR_T;

/* License上报消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的发送IP 为0，由License代理服务器填写 */
    UINT32 ulUDPort;                /* AC的发送UDP端口为0，由License代理服务器填写 */
    CHAR   ulTimeStamp[16];   /* 时间戳20120112170000 */
    UINT32 ulRandom;              /* 随机数 */
}  AC_LICENSE_MSG_TO_SV_REPORT_REQ_T;

/* License服务器IP变更ACK消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的发送IP 为0，由License代理服务器填写 */
    UINT32 ulUDPort;                /* AC的发送UDP端口为0，由License代理服务器填写 */
}  SV_MSG_TO_AC_LICENSE_IP_CHANGE_ACK_T;

/* 侵权控制ACK消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的发送IP 为0，由License代理服务器填写 */
    UINT32 ulUDPort;                /* AC的发送UDP端口为0，由License代理服务器填写 */
}  SV_MSG_TO_AC_LICENSE_TORT_ACK_T;




/* 上报ACK消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的接收IP  */
    UINT32 ulUDPort;                /* AC的接收UDP端口 */
}  AC_LICENSE_MSG_TO_SV_REPORT_ACK_T;

/* License服务器IP变更消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的接收IP  */
    UINT32 ulUDPort;                /* AC的接收UDP端口 */
    UINT8   aucProxyOldIp[4];      /* License代理服务器的旧IP地址 */
    UINT8   aucProxyNewIp[4];    /* License代理服务器的新IP地址 */
}  SV_MSG_TO_AC_LICENSE_IP_CHANGE_REQ_T;

/* 侵权控制消息 */
typedef struct 
{
    LICENSE_SV_MSGHDR_T stHead;
    CHAR   ulSequence[24];     /* 授权序列号从license文件中提取 */
    UINT8   aucIp[4];                /* AC的接收IP  */
    UINT32 ulUDPort;                /* AC的接收UDP端口 */
    UINT32 ulTortType;            /* AC侵权类型  */
}  SV_MSG_TO_AC_LICENSE_TORT_REQ_T;


/* license生成时需要的信息(TLV格式) */
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

/* license生成时需要的信息(TLV格式) */
typedef struct
{
	CHAR   acCustName[LICENSE_OMC_CUSTNAME];   /* 客户名称 */ 
	CHAR   ulAuthorFunc[LICENSE_OMC_AUTHORFUNC];  /* 授权功能[16]；(
	                                                [0]=1表示接入ap基本功能 0-否 1-是
	                                                [1]=1表示接入sta基本功能 0-否 1-是
	                                                [2]=1表示是否支持集中转发模式 0-否 1-是
	                                                [3]=1 0-否 1-是
	                                                [4]=1 0-否 1-是
	                                                [5]=1 0-否 1-是
	                                                [6]=1 0-否 1-是
	                                                [7]=1 0-否 1-是
	                                                [8]=1 0-否 1-是
	                                                [9]=1 0-否 1-是
	                                                ) */
	UINT32 ulAuthorApCapacity;       /* 授权ap容量[10] */
	UINT32 ulAuthorUserCapacity;        /* 授权user容量[10] */
	CHAR   ulAuthorTime[LICENSE_OMC_AUTHORTIME];            /* 授权时间（期限）1999061820001232 */
	CHAR   acAuthorLastUser[LICENSE_OMC_AUTHORLASTUSER];     /* 最终用户 */
	CHAR   acAuthorName[LICENSE_OMC_AUTHORNAME];          /* 授权名称 */
	CHAR   ulAuthorSerialNum[LICENSE_OMC_AUTHORSERIALNUM];     /* 授权序列号 */
}AC_LICENSE_OMC_T;


/* ap license生成时需要的信息(TLV格式) */
typedef struct
{
	CHAR   ulApFunc[LICENSE_OMC_APFUNC];  /* 授权功能[16]；(
	                                                [0]=1表示本次key是否开启接入apmac检查功能 0-否 1-是
	                                                [1]=1 0-否 1-是
	                                                [2]=1 0-否 1-是
	                                                [3]=1 0-否 1-是
	                                                [4]=1 0-否 1-是
	                                                ) */
	UINT32 ulApMacSum;       /* 当前license中有效MAC数目 */
	CHAR   acApBeginMac[LICENSE_OMC_APBEGINMAC];       /* 起始MAC 80:8B:5C:00:2B:CE */
	CHAR   acApEndMac[LICENSE_OMC_APENDMAC];           /* 结束MAC 80:8B:5C:00:37:85 */
	CHAR   acApSerialNum[LICENSE_OMC_APSERIALNUM];     /* 授权序列号 */
}AP_LICENSE_OMC_T;

/* 接口结构体定义结束*/
/******************************************************************************/

/******************************************************************************/
/* 函数声明开始*/
extern VOID ac_license_set_svip (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_get_time (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_get_svip_ex (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_check_ap_file_verify (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_license_check_file_verify (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

extern int ap_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
extern int ac_license_verify(char *szreadfile, char *license_info, int info_flag, int *res);
extern int Create_hash_encrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);
extern int Create_hash_decrypt(unsigned char *in, int inlen, unsigned char *out, int *outlen);

/* 函数声明结束*/
/******************************************************************************/

#endif /* _AC_LICENSE_PUBLIC_H */
/******************************* 头文件结束 **********************************/



