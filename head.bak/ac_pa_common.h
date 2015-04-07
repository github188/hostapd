#ifndef AC_PA_COMMON_H
#define AC_PA_COMMON_H

#pragma pack(push, 1)

/* portal本地配置文件 */
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

/* 定时器 */
#define TIMER_AC_PA_SCAN_TIMER                  (TIMER0)
#define EV_AC_PA_SCAN_TIMER_MSG                 (EV_TIMER0)

#define TIMER_AC_PA_IP_SCAN_TIMER               (TIMER1)
#define EV_AC_PA_IP_SCAN_TIMER_MSG				(EV_TIMER1)

#define TIMER_AC_PA_CHECKPS_TIMER               (TIMER2)
#define EV_AC_PA_CHECKPS_TIMER_MSG              (EV_TIMER2)

#define TIMER_AC_PA_USER_TIMER			        (TIMER20)
#define EV_AC_PA_USER_TIMEROUT_MSG		        (EV_TIMER20)

/* PORTAL Server与AC之间的消息 */
#define PORTAL_MSG_REQ_CHALLENGE	0x01   	/* PS->PA	Portal Server 向AC设备发送的请求Challenge报文 */
#define PORTAL_MSG_ACK_CHALLENGE	0x02	/* PS<-PA	AC设备对Portal Server请求Challenge报文的响应报文 */
#define PORTAL_MSG_REQ_AUTH	        0x03	/* PS->PA	Portal Server向AC设备发送的请求认证报文 */
#define PORTAL_MSG_ACK_AUTH	        0x04	/* PS<-PA	AC设备对Portal Server请求认证报文的响应报文 */
#define PORTAL_MSG_REQ_LOGOUT	    0x05	/* PS->PA	若ErrCode字段值为0x00，表示此报文是Portal Server向AC设备发送的请求用户下线报文；
                                                        若ErrCode字段值为0x01，表示该报文是Portal Server发送的超时报文，
                                                        其原因是Portal Server发出的各种请求在规定时间内没有收到响应报文。*/
#define PORTAL_MSG_ACK_LOGOUT       0x06	/* PS<-PA	AC设备对Portal Server请求下线报文的响应报文 */
#define PORTAL_MSG_AFF_ACK_AUTH	    0x07	/* PS->PA	Portal Server对收到的认证成功响应报文的确认报文；*/
#define PORTAL_MSG_NTF_LOGOUT       0x08	/* PA->PS	用户被强制下线通知报文 */
#define PORTAL_MSG_REQ_INFO	        0x09	/* PS->PA	信息询问报文 */
#define PORTAL_MSG_ACK_INFO	        0x0a	/* PA->PS	信息询问的应答报文 */

#define PORTAL_MSG_ACK_NTF_LOGOUT   0x0e    /* PS->PA   用户被强制下线通知的应答报文 */

#define PORTAL_MSG_REQ_MACBINDING_INFO	0x30	/*AC向绑定中心发起的MAC绑定的查询报文*/
#define PORTAL_MSG_ACK_MACBINDING_INFO	0x31	/*绑定中心回应AC设备MAC绑定查询的应答报文*/
#define PORTAL_MSG_NTF_USER_LOGON		0x32	/*AC向绑定中心通知用户上线报文*/
#define PORTAL_MSG_NTF_USER_LOGOUT		0x34	/*AC向绑定中心通知用户下线报文*/
#define PORTAL_MSG_REQ_USER_OFFLINE		0x36	/*绑定中心向AC发起的强制用户下线*/

/* Portal属性类型 */
#define PORTAL_ATTR_USERNAME	    0x01	/* <=253 随e行用户名，具体为：“用户手机号码”；
                                                    全国/省内预付费卡用户名称：13位数字；
                                                    为满足国际漫游的需要，支持253字节的长用户名。 */
#define PORTAL_ATTR_PASSWORD	    0x02	/* <=16	用户提交的明文密码 */
#define PORTAL_ATTR_CHALLENGE	    0x03	/* 16 Chap方式加密的魔术字 */
#define PORTAL_ATTR_CHAPPASSWORD	0x04	/* 16 经过Chap方式加密后的密码 */

/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define PORTAL_ATTR_ERRID			0x05    /* 当errcode不为零时的errid */

#define PORTAL_ATTR_ERRID_LEN		0x07    /* errid定长+1+1 */
/*begin bug#1926 cmcc test fangz 2013.2.20*/

#define PORTAL_ATTR_TEXTINFO	0x05
#define PORTAL_ATTR_UPLINKFLUX	0x06
#define PORTAL_ATTR_DOWNLINKFLUX	0x07
#define PORTAL_ATTR_PORT	0x08

#define PORTAL_ATTR_BASIP					0x0a	/*AC的IPv4地址（网络序号）*/
#define PORTAL_ATTR_SESSIONID				0x0b	/*客户端MAC地址*/
#define PORTAL_ATTR_NASID					0x30	/*字符串*/
#define PORTAL_ATTR_SESSION_STARTTIME	0x31	/*用户上线时间（标准时间），取值为1970年以来的秒数*/
#define PORTAL_ATTR_SESSION_STOPTIME		0x32	/*用户下线时间（标准时间），取值为1970年以来的秒数*/
#define PORTAL_ATTR_SESSION_TIME			0x33	/*用户上线时长，单位为秒*/
#define PORTAL_ATTR_USER_AGENT			0x34	/*终端浏览器的User-Agent字段，PORTAL认证重定向时，会携带该字段*/
#define PORTAL_ATTR_INPUT_OCTETS			0x35	/*用户上行流量的字节数*/
#define PORTAL_ATTR_OUTPUT_OCTETS		0x36	/*用户下行流量的字节数*/
#define PORTAL_ATTR_INPUT_PACKETS			0x37	/*用户上行流量的包个数*/
#define PORTAL_ATTR_OUTPUT_PACKETS		0x38	/*用户下行流量的包个数*/
#define PORTAL_ATTR_INPUT_GIGAWORDS		0x39	/*用户上行流量的G字节数*/
#define PORTAL_ATTR_OUTPUT_GIGAWORDS	0x3a	/*用户下行流量的G字节数*/

/* 协议的版本号 */
#define PORTAL_VER_1                0x01

/* Portal消息中ErrCode定义 */
/* 当Type值为ACK_CHALLENGE：*/
#define PORTAL_ACK_CHALLENGE_SUCCESS        0   /* 表示AC设备告诉Portal Server请求Challenge成功；*/
#define PORTAL_ACK_CHALLENGE_ERR_DENY       1   /* 表示AC设备告诉Portal Server请求Challenge被拒绝；*/
#define PORTAL_ACK_CHALLENGE_ERR_AUTHED     2   /* 表示AC设备告诉Portal Server此链接已建立；*/
#define PORTAL_ACK_CHALLENGE_ERR_BUSY       3   /* 表示AC设备告诉Portal Server有一个用户正在认证过程中，请稍后再试；*/
#define PORTAL_ACK_CHALLENGE_ERR_FAIL       4   /* 表示AC设备告诉Portal Server此用户请求Challenge失败（发生错误）；*/
/*  */
#define PORTAL_ACK_CHALLENGE_ERR_TIMEOUT    5   /* 表示AC设备，此用户Challenge超时 */
/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_VALID_ACCOLATED   "AC101"   /*用户请求认证的IP地址是本AC所述的地址池中的有效地址，但这个地址目前已经通过认证在线*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_INVALID           "AC102"/*AC发现用户请求认证的IP地址不是本AC所述的地址池中的有效地址*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_VALID_UNACCOLATED  "AC103" /*AC发现用户请求认证的IP地址是本AC所述的地址池中的有效地址，但这个地址目前还未分配给用户*/
#define PORTAL_ACK_CHALLENGE_ERR_IP_OTHERS             "AC999"  /*其他错误信息*/
/*end bug#1926 cmcc test fangz 2013.2.20*/

/* 当Type值为ACK_AUTH：*/
#define PORTAL_ACK_AUTH_SUCCESS             0   /* 表示AC设备告诉Portal Server此用户认证成功；*/
#define PORTAL_ACK_AUTH_ERR_DENY            1   /* 表示AC设备告诉Portal Server此用户认证请求被拒绝；*/
#define PORTAL_ACK_AUTH_ERR_AUTHED      	2   /* 表示AC设备告诉Portal Server此链接已建立；*/
#define PORTAL_ACK_AUTH_ERR_BUSY            3   /* 表示AC设备告诉Portal Server有一个用户正在认证过程中，请稍后再试；*/
#define PORTAL_ACK_AUTH_ERR_FAIL            4   /* 表示AC设备告诉Portal Server此用户认证失败（发生错误）；*/
/* */
#define PORTAL_ACK_AUTH_ERR_TIMEOUT         5   /* 表示AC设备，此用户认证超时 */
#define PORTAL_ACK_AUTH_ERR_DISORDER        6   /* 表示AC设备，鉴权乱序 */
#define PORTAL_ACK_AUTH_ERR_PWDERR          7   /* 表示AC设备，用户密码缺失 */

/* 当Type值为REQ_LOGOUT：*/
#define PORTAL_REQ_LOGOUT_NORMAL            0   /* 表示此报文是Portal Server发给AC设备的请求下线报文*/
#define PORTAL_REQ_LOGOUT_TIMEOUT           1   /* 表示此报文是在Portal Server没有收到AC设备发来的对各种请求的响应报文，
                                                   而定时器时间到（即超时）时由Portal Server发给AC设备的报文；*/
/* 当Type值为ACK_LOGOUT：*/
#define PORTAL_ACK_LOGOUT_SUCCESS           0   /* 表示AC设备告诉Portal Server此用户下线成功；*/
#define PORTAL_ACK_LOGOUT_ERR_DENY          1   /* 表示AC设备告诉Portal Server此用户下线被拒绝；*/
#define PORTAL_ACK_LOGOUT_ERR_FAIL          2   /* 表示AC设备告诉Portal Server此用户下线失败（发生错误）；*/

/* 但Type值为NTF_LOGOUT */
#define PORTAL_NTF_LOGOUT_NORMAL            0
#define PORTAL_NTF_LOGOUT_TIMEOUT           1   /* 表示USRM模块发来的用户超时，而引起的请求下线 */
#define PORTAL_NTF_LOGOUT_DELUSER           2   /* 表示USRM模块删除用户的通知，而引起的请求下线 */

/* 当Type值为ACK_NTF_LOGOUT */

#define PORTAL_MAX_ATTR_LEN                 1024/* 目前消息中Attr长度最大的是REQ_AUTH,不超过512字节 */

/* 用户状态 */
#define PORTAL_USER_STATE_NULL              0
#define PORTAL_USER_STATE_REQ_MACBINDING	1		/*发送REQ_MACBINDING*/
#define PORTAL_USER_STATE_ACK_MACBINDING	2		/*接收到ACK_MACBINDING*/
#define PORTAL_USER_STATE_START_AUTH        10      /* 发出ACK_CHALLENGE时 */
#define PORTAL_USER_STATE_AAA_AUTH          20      /* 发出AUTH_REQ时 */
#define PORTAL_USER_STATE_AFFIRM_AUTH       30      /* 发出ACK_AUTH时 */
#define PORTAL_USER_STATE_AUTH_OVER         40      /* 收到AFF_ACK_AUTH */
#define PORTAL_USER_STATE_AUTH_FAIL         PORTAL_USER_STATE_NULL

/*begin bug#1926 cmcc test fangz 2013.2.20*/
#define DHCP_USER_IP_VALID_ALLOCATED     0 /*DHCP 告诉PA此ip已经分配，PA判断是否认证在线*/
#define DHCP_USER_IP_INVALID             1 /*DHCP告诉PA此ip不是地址池中地址*/
#define DHCP_USER_IP_VALID_UNALLOCATED   2 /*DHCP 告诉PA此ip可用未分配*/
#define DHCP_USER_IP_ERR                 3 /*其他错误*/
/*end bug#1926 cmcc test fangz 2013.2.20*/

/* Portal 协议消息格式 */
#define PORTAL_MSG_HEAD \
    UINT8   ucVer;	        /* 协议的版本号，长度为1字节，目前定义的值为0x01。*/\
    UINT8   ucType;	        /* 报文的类型，长度为1字节。*/\
    UINT8   ucAuthType;	    /* 用户的认证方式，长度为1字节，只对Type值为0x03的认证请求报文有意义：chap方式认证（0x00）、Pap方式认证（0x01）*/\
    UINT8   ucRsv;	        /* 保留字段，长度为1字节，在所有报文中值为0。*/\
                            \
    UINT16  usSerialNo;	    /* 报文的序列号，长度为2字节，由Portal Server随机生成；由Portal Server发给AC的报文；\
                               每一个由AC设备发给Portal Server的响应报文的SerialNo必须和Portal Server发送的相应请求报文的SerialNo一样。*/\
    UINT16  usReqID; 	    /* AC随机生成 */\
                            \
    UINT8   aucUserIP[4];   /* Portal用户的IP地址，长度是4字节，由Portal Server根据获得的IP地址填写，必填项。*/\
                            \
    UINT16  usUserPort;     /* 目前没有用到，在所有报文中其值为0。*/\
    UINT8   ucErrCode;	    /* 和Type字段一起表示一定的意义，长度为1字节。*/\
    UINT8   ucAttrNum 	    /* 表示其后便可变长度的属性字段属性的个数，长度为1字节（表示属性最多可有255个属性），其值在所有的报文中都要根据具体情况赋值。*/

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

/* Portal消息 */
typedef struct
{
    PORTAL_MSG_HEAD;
    UINT8   aucAttr[PORTAL_MAX_ATTR_LEN];
}AC_PA_PORTAL_MSG_T;

/* 给PA线程转发的消息 */
typedef struct
{
    SOCKADDR    stPsAddr;
    INT32       iAddrLen;

    AC_PA_PORTAL_MSG_T  stPortalMsg;
}AC_PA_PORTAL_RELAY_MSG_T;


typedef struct
{
	UINT8 ucAttrType;
	UINT8 ucAttrLength;	/*含头*/
}AC_PA_PORTAL_ATTR_T;


typedef struct
{
	UINT8 ucAttrType;
	UINT8 ucAttrLength;	/*含头*/
	UINT32 ulAttrValue;
}AC_PA_PORTAL_ATTR_UINT4_T;


typedef AC_PA_PORTAL_MSG_HEAD_T AC_PA_PORTAL_REQ_CHALLENGE_T;

typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrChallenge;                        /* 0x03	属性类型（Challege） */
    UINT8   ucAttrChallengeLen;                     /* 18 */
    UINT8   aucAttrChallenge[PORTAL_CHALLENGE_LEN]; /* 具体的属性值，Chap方式加密的魔术字 */
}AC_PA_PORTAL_ACK_CHALLENGE_T;

/*begin bug#1926 cmcc test fangz 2013.2.20*/
typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrErrID;                        /* 0x05	属性类型（Challege） */
    UINT8   ucAttrErrIDLen;                     /* 7 */
    UINT8   aucAttrErrID[PORTAL_ERRID_LEN]; /* 具体的属性值:0xAC101:ip地址有效，但已认证在线
	          							  0xAC102:IP地址不是地址池中的有效地址
	          							  0xAC103:IP地址是地址池中的有效地址，但这个地址目前还未分配给用户
	          							  0xAC999:其他错误信息*/
}AC_PA_PORTAL_ACK_CHALLENGE_ERR_T;/*当ERR CODE不为0 时，返回一个ERR ID */
/*end bug#1926 cmcc test fangz 2013.2.20*/

typedef struct
{
    PORTAL_MSG_HEAD;

    UINT8   ucAttrUserName;
    UINT8   ucAttrUserNameLen;
    CHAR    acAttrUserName[PORTAL_MAX_USERNAME_LEN+1];

    /* chap认证时为chapPwd，pap认证时为pwd */
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

    UINT8   ucAttrErrID;                        /* 0x05	属性类型（Challege） */
    UINT8   ucAttrErrIDLen;                     /* 7 */
    UINT8   aucAttrErrID[PORTAL_ERRID_LEN]; /* 具体的属性值:AC201:AC与radius通讯超时或者通讯网络问题
						          						    AC999:其他错误信息
						          							RCXXX:Radius返回给AC的access-reject中的错误代码*/
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

/* 用户定时器扩展数据 */
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
    UINT32      ulLinkErrCount;     /* 与Portal Server之间的链路异常情况，任何发送成功后清零，否则累加 */
}AC_PA_ALARM_INFO_T;

#define AC_PA_MAX_PS_NUM    1024    /* AC允许接入的最大PS个数 */
typedef struct
{
    UINT32      ulNum;
    UINT32      aulIP[AC_PA_MAX_PS_NUM];
}AC_PA_PS_LIST_T;

/* 内部消息 */

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
#define AC_PA_CHECK_SSID_NULL       0   /* 不检查 */
#define AC_PA_CHECK_SSID_IFEXIST    1   /* 部分检查:如果映射关系存在则检查 */
#define AC_PA_CHECK_SSID_FORCE      2   /* 强制检查:映射关系必须存在 */ 
typedef struct
{
    UINT8		    aucIP[4];
	CHAR		    acSSID[AC_PA_MAX_SSID_LEN+1];
	CHAR			aucResv[3];

	UINT32			ulCreateTime;		/* 映射关系创建或更新时间 */	
}AC_PA_IP_DATA_T;

typedef struct
{
    UINT8       aucHead[3];     // 内部消息的前三个字节都是0xff
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

    UINT32          ulRetCode;      /* 0表示成功 */

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
    UINT32          ulRetCode;      /* 0表示成功 */
}AC_PA_CTL_DEL_USER_ACK_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;
    UINT8           aucUserIP[4];
}AC_PA_CTL_LIST_IP_REQ_T;

typedef struct
{
    AC_PA_INNER_MSG_HEAD_T  stHead;

    UINT32          ulRetCode;      /* 0表示成功 */

    UINT32          ulUserNum;
    AC_PA_IP_DATA_T astIP[128];
}AC_PA_CTL_LIST_IP_ACK_T;

#pragma pack(pop)

#endif /* AC_PA_COMMON_H */



