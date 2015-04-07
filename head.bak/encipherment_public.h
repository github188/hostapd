/*
加解密模块公共头文件
*/
#ifndef __ENCIPHERMENT_PUBLIC_H
#define __ENCIPHERMENT_PUBLIC_H

typedef   unsigned   long   DWORD; 
typedef   unsigned   short   WORD; 
typedef   unsigned char   BYTE;
typedef   int   BOOL; 
typedef   char   CHAR;
typedef   char *PCHAR;
typedef   unsigned   int   UINT32; 
typedef   unsigned   short   UINT16; 
typedef   unsigned   char   UINT8;

typedef enum { FALSE = 0, TRUE = 1 } Boolean;

#define MODULUS "00da9dd362b962f0bf343555861d9929521597461bacf48e2ea331fafcca8eff21884e6b618112ad32249745df58032d17e7f6f109b80ad697b704b721119d93f3c42cac547126ca2aa12802d7b9330e5c01672652d307908646c2814f7d3a8e6c58668b77624269a8cd6032ffb588fa977019624ed5d83d393fc355148c72441325e9fc53e40c069dde7ea13b8fb02d2897e82a223d9034ca14482f6ed99faf47060e3b4bd5832df031d1fd1290930e594cf87f865a29ed11b5736ee2abf5ec162218e5f277b60b2cac380946143a30b681501158ca5415a90d37b72ca446aeb8ef0ba843083c49fdc51d30afb6b85e0393aba8d18017d39b819e5746c5bc4a49"
#define PUBLIC_EXPONENT 75011
#define PRIVATE_EXPONENT "00b4230bea6712627a78e4982c76d795bd3eece1c667a07c094f7209722c83aeeb26a60304230daa6d32c46ea9f6e4912de60b961e71b7d23901bfc5a5f2fcaef926ccd2e547737dc2ee985b36656e007e981b07c4474bac8a960c8028faebe15c5299fcd055015292eeefefa635247aada9487b05ed6bc4915dcfab5a7b52a0da967ba8674eb685f16f7c917652a972cc97923640af44e0b87102f1c2f2a0c0e0264e2fb7129bdbb918fb5c7c898e3218c5d25be9c129827cecbdbcdd36517839f66193f233a6cea93f061e5393ce4e7cf592228078a9165ff2e43cea256ac9c949dbad914300b576511e96890af739f46e75bc859468e2c8c8417eb066aaa0eb"

#if 0 /* test */
#define MODULUStest "00eb3aa45c788eb28011941f39561eeaee383c9b2b9b89cf6a5a068388318a3e846b5809d01d409709219accf2ba7658160af7d4184b7433d90a728375cb13e6c3bc284e4a411aedaff454575508ef8fb77a10c534c38451bcb0252ee1641b8765c5ef657fdaef0a1cbab4987a5bd58f0256ff4416bdb48a08c32df4378df36b8c575372dc5b61b9372f5297624ecb2cda4edac50def895944ef9407240d078c5ce690368f8e6513a6d047169af91c87ad66cb8c8f57e287904d8c7b0e87af23b313631fd2375cd40fa8b7aecc5372785f74beb117384c35d1157c647295581d51e100d17b32dabce16bb3c437e0d3779f0a2b274e528dfc6cc98d084efe2a1ce1"
#define PUBLIC_EXPONENTtest RSA_F4
#define PRIVATE_EXPONENTtest "02df14628c9631579edf5002432add734afc726875dd98ca938ec0cc48ce8734d69a9c840dd75c00a0886338134e9e84a65da0192bd29f4f66f13ee991310d0016abe748c0c2b3641277751974a277fea55ecf0975d987a5e6008e31f226e3e03a2a51f2dd994d664c6127fb5663a4fb42549b602bb0a87eb2e33cb7f0e3a7cc68c691e5d9a1f3de94cc87c90d25d6004e8b9b01eedba6d878868c32baf4219dfe09f2d3b46302093c8bb0dd2adbaa4a07bd7ec5ef706a5b725d63b829a790bbf47b2e4a0187ac9207874fcbbe593348dc89f9ab53d28a4c427a8bde6943fd645de2ecc37346afab9201c27fa696f9f4aea010ef323507c2338d5247ee679801"
#endif

#define BITSLEN 2048
#define PADDING RSA_NO_PADDING
#define CHARLEN 5000

#define ACTIVELEN 256

/* 硬件信息长度 */
#define HARDWARELEN 2048

/* 测试打印开关 */
#define LICENSE_MAIN        APP_DETAIL
#define LICENSE_LIB           APP_DETAIL
#define LICENSE_COM         APP_DETAIL
#define LICENSE_INFOR      APP_DETAIL
#define LICENSE_MAIN_DLL      APP_DETAIL

/* 日志级别 */
#define APP_DETAIL          (BYTE) 0
#define APP_MSG             (BYTE) 1
#define APP_WARN            (BYTE) 2
#define APP_ERROR           (BYTE) 3
#define APP_FAIL            (BYTE) 4
#define APP_FATAL           (BYTE) 5

#define APP_OFF             (BYTE) 20
#define APP_OFFTIME     (BYTE) 21
#define APP_LICENSE_MAIN     (BYTE) 22
#define APP_LICENSE_LIB     (BYTE) 23
#define APP_LICENSE_COM     (BYTE) 24
#define APP_LICENSE_INFOR     (BYTE) 25
#define APP_INFOR     (BYTE) 26
#define APP_MAIN_DLL    (BYTE) 27


/*进行TLV头定义*/
/* 硬件信息 */
#define AC_LICENSE_TYPE_CPUINFO         		(UINT32)0x1000
#define AC_LICENSE_TYPE_MACINFO        			(UINT32)0x1001
/* license服务器需要获取的信息头 */
#define AC_LICENSE_TYPE_CPUTYPE        			(UINT32)0x1002
/* 新增获取ac sn信息头 */
#define AC_LICENSE_TYPE_ACSN        			(UINT32)0x1003
/* 新增获取.factory中的产品型号信息头 */
#define AC_LICENSE_TYPE_ACTYPE        			(UINT32)0x1004
/* 新增获取oid.conf的vender信息信息头 */
#define AC_LICENSE_TYPE_OEMTYPE        			(UINT32)0x1005

#define AC_LICENSE_TYPE_ACCUSTNAME  	  		(UINT32)0x2000
#define AC_LICENSE_TYPE_ULAUTHORFUNC       	    (UINT32)0x2001
#define AC_LICENSE_TYPE_ULAUTHORAP      		(UINT32)0x2002
#define AC_LICENSE_TYPE_ULAUTHORUSER       	    (UINT32)0x2003
#define AC_LICENSE_TYPE_ULAUTHORTIME     		(UINT32)0x2004
#define AC_LICENSE_TYPE_ACAUTHORLASTUSER        (UINT32)0x2005
#define AC_LICENSE_TYPE_ACAUTHORNAME     		(UINT32)0x2006
#define AC_LICENSE_TYPE_ACAUTHORSERIALNUM       (UINT32)0x2007

#define LICENSE_OMC_CUSTNAME   (UINT32)128
#define LICENSE_OMC_AUTHORFUNC   (UINT32)16
#define LICENSE_OMC_AUTHORAPCAP   (UINT32)10
#define LICENSE_OMC_AUTHORUSERCAP   (UINT32)10
#define LICENSE_OMC_AUTHORTIME   (UINT32)16
#define LICENSE_OMC_AUTHORLASTUSER   (UINT32)128
#define LICENSE_OMC_AUTHORNAME   (UINT32)128
#define LICENSE_OMC_AUTHORSERIALNUM   (UINT32)24

#define AP_LICENSE_TYPE_APFUNC  	  		(UINT32)0x3000
#define AP_LICENSE_TYPE_APMACSUM       	    (UINT32)0x3001
#define AP_LICENSE_TYPE_APBEGINMAC     		(UINT32)0x3002
#define AP_LICENSE_TYPE_APENDMAC      	    (UINT32)0x3003
#define AP_LICENSE_TYPE_APSERIALNUM         (UINT32)0x3004

#define LICENSE_OMC_APFUNC   (UINT32)16
#define LICENSE_OMC_APMACSUM   (UINT32)10
#define LICENSE_OMC_APBEGINMAC   (UINT32)17
#define LICENSE_OMC_APENDMAC   (UINT32)17
#define LICENSE_OMC_APSERIALNUM   (UINT32)24

#define LICENSE_HARDWARE_CPUID  (UINT32)160
#define LICENSE_HARDWARE_MAC  (UINT32)32
#define LICENSE_HARDWARE_MACNUM  (UINT32)32
#define LICENSE_HARDWARE_ACSN  (UINT32)64
#define LICENSE_HARDWARE_ACTYPE  (UINT32)32
#define LICENSE_HARDWARE_OEMTYPE  (UINT32)32

#define LICENSE_HARDWARE_MAXNUM  (UINT32)255

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


 /* 硬件信息采集结构(TLV格式) */
  typedef struct
{    
	CHAR   acMac[LICENSE_HARDWARE_MAC];         /* 一个mac */
}AC_HARDWARE_MAC_T;
 typedef struct
{
	CHAR   acCpuid[LICENSE_HARDWARE_CPUID];       /* cpuid */    
	UINT32 ulmacnum;          /* 有效mac数量 */
	AC_HARDWARE_MAC_T   stMac[LICENSE_HARDWARE_MACNUM];         /* 最多32个mac */
	CHAR   acSn[LICENSE_HARDWARE_ACSN];       /* ac sn */  
	CHAR   acType[LICENSE_HARDWARE_ACTYPE];       /* 获取.factory中的产品型号 */  
	CHAR   acOemType[LICENSE_HARDWARE_OEMTYPE];       /* 获取oid.conf的vender信息 */  
	CHAR   acTmp[372];        /* 暂时保留字节数，原值为500 */
}AC_HARDWARE_INFO_T;

/*定义两个结构体*/
typedef struct
{
	UINT32 ulhardnum;          /* 有效tlv结构属性数量 */
	AC_HARDWARE_INFO_T   stLicenseHard;
	UINT32 ulomcnum;          /* 有效tlv结构属性数量 */
	AC_LICENSE_OMC_T        stLicenseOmc;
}AC_LICENSE_INFO_T;

/*定义两个结构体*/
typedef struct
{
	UINT32 ulhardnum;          /* 有效tlv结构属性数量 */
	AC_HARDWARE_INFO_T   stLicenseHard;
	UINT32 ulomcnum;          /* 有效tlv结构属性数量 */
	AP_LICENSE_OMC_T     stLicenseOmc;
}AP_LICENSE_INFO_T;


/*定义tlv头格式*/
typedef struct
{
	UINT32  ulTypeID;
	UINT32 ulTypeLen;
}LICENSE_TYPE_HDR_T;




#endif

