/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* ��    ��: AC��ͬͷ�ļ�
* �޸���ʷ:
* 2008-4-15     ������              �½�
*
******************************************************************************/

/******************************** ͷ�ļ�������ͷ *****************************/

#ifndef  _AC_PUBLIC_H
#define  _AC_PUBLIC_H

/* ����ϵͳͷ�ļ� */

/* ���Ͷ��� */
#if defined (_OSWIN32_)
#ifndef CHAR
#define CHAR char
#endif
#ifndef BOOL
#define BOOL int
#endif
#ifndef UINT64
#define UINT64 DWORD64
#endif

#elif defined (_LINUX_)
#ifndef UINT64
#define UINT64 unsigned long long
#endif
#endif

#ifndef UINT8
#define UINT8 unsigned char
#endif

#ifndef UINT16
#define UINT16 unsigned short
#endif

#ifndef UINT32
#define UINT32 unsigned int
#endif

#ifndef INT8
#define INT8 char
#endif

#ifndef INT16
#define INT16 short
#endif

#ifndef INT32
#define INT32 int
#endif

#ifndef BOOL
#define BOOL int
#endif

#ifndef STRING
#define STRING char *
#endif

#ifndef VOID
#define VOID void
#endif


/* ������������ */
typedef UINT32     AC_RET;

/* ����ֵ���� */
#define AC_OK           ((AC_RET)0)             /* �ɹ� */
#define AC_FAIL         ((AC_RET)0xFFFFFFFF)    /* ʧ�� */
#define AC_SEND_FAIL    ((AC_RET)1)             /* ������Ϣʧ�� */

#define AC_MOI_LEN    ((UINT32)16)

/******************************** ȫ�ֱ������� ********************************/
extern UINT32  gulAcPrintLevel;

/********************************** �궨�� ********************************/
/* ��ӡ������ */
#define AC_PRINT_NON        ((UINT32)0)
#define AC_PRINT_FATAL      ((UINT32)1)
#define AC_PRINT_FAIL       ((UINT32)2)
#define AC_PRINT_ERROR      ((UINT32)3)
#define AC_PRINT_WARNING    ((UINT32)4)
#define AC_PRINT_INFO       ((UINT32)5)
#define AC_PRINT_DETAIL     ((UINT32)6)
#define AC_PRINT_ALL        ((UINT32)0xFFFFFFFF)

#define AC_PRINT_NAME_FATAL     "FATAL"
#define AC_PRINT_NAME_FAIL      "FAIL "
#define AC_PRINT_NAME_ERROR     "ERROR"
#define AC_PRINT_NAME_WARNING   "WARN "
#define AC_PRINT_NAME_INFO      "INFO "
#define AC_PRINT_NAME_DETAIL    "DETAIL"

#define AC_MAX_PRINT_LEN        (1024-1)        /* ��־��󳤶� */

/* �����궨�� */
#ifndef _packed_1_
#define _packed_1_
#endif

#define AC_REPEAT_FOREVER while(1)

/* �߳�״̬����*/
#define AC_PROC_IDLE    VM_PROC_STATE_IDLE
#define AC_PROC_WORK    ((UINT16)1)
#define AC_PROC_INIT    ((UINT16)4)

#define AC_INVALID_TIMERID    ((UINT32)0xFFFF)

/* AC����ģʽ�궨��*/
#define AC_MSMODE_ALONE		0		/* ��������ģʽ*/
#define AC_MSMODE_MASTER		1		/* ����*/
#define AC_MSMODE_SLAVE		2		/* ����*/

/* ID ȡֵ��Χ���� */
#define AC_ACID_MIN				1
#define AC_ACID_MAX			32

#define AC_WTPID_MIN    			1
#ifdef BIG_AC
#define AC_WTPID_MAX    		4096	/* 2010-1-12 pyy �޸� WTPID 33~1056 */	
										/* 2010-11-29 pyy �޸�:֧��2048��AP */
										/* 2011-1-17 pyy�޸�: ֧��4096��AP */

#define AC_WTP_NUM_MAX		4096	/* 2010-11-29 pyy �޸�:֧��2048 ��AP */
										/* 2011-1-17 pyy�޸�: ֧��4096��AP */
#else
#define AC_WTPID_MAX    		1024	/* 2010-1-12 pyy �޸� WTPID 33~1024 */

#define AC_WTP_NUM_MAX		1024
#endif

#define AC_IFID_MIN     			0
#define AC_IFID_MAX     			3

#define AC_VDEVID_MIN     		0
#define AC_VDEVID_MAX     		3

#define AC_VAPID_MIN   		 	0
#define AC_VAPID_MAX    			15

#define AC_ADHOCID_MIN    		0
#define AC_ADHOCID_MAX    		3

#define AC_WTPENETID_MIN    	0
#define AC_WTPENETID_MAX    	1

#define AC_INVALID_VDEVID   0xffffffff
#define AC_INVALID_ACID		0

#define	AC_DB_TABLE_READ_NOTFINISH	0
#define	AC_DB_TABLE_READ_FINISH		1

#define AC_DB_PACKET_MAX_LEN	    8000

#define AC_DB_TBL_NAME_LEN_MAX      ((UINT32)32)    /* ��ϵ��������󳤶� */

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
#define AC_DB_PACKET_MAX_LEN_NET	    ((UINT32)4*1024)
/* END: Added by wubin, 2012/4/25   BUG:000 */

/*begin TASK #476 fangz 2013.2.25 log*/
#ifndef MAC_FMT
#define MAC_FMT "%02X:%02X:%02X:%02X:%02X:%02X"
#define MAC_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], \
     ((UINT8*)(x))[3], ((UINT8*)(x))[4], ((UINT8*)(x))[5]
#endif

#define MAC_LOG_FMT "%02X%02X-%02X%02X-%02X%02X"
/*end  TASK #476 fangz 2013.2.25 log*/


#ifndef IP_FMT
#define IP_FMT	"%u.%u.%u.%u"
#define IP_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], ((UINT8*)(x))[3]
#endif

#ifndef MASK_FMT
#define MASK_FMT	"%u.%u.%u.%u"
#define MASK_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], ((UINT8*)(x))[3]
#endif

#ifndef MOI_FMT
#define MOI_FMT		"0x%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x "
#define MOI_ARG(x)	 ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], ((UINT8*)(x))[3], \
	((UINT8*)(x))[4], ((UINT8*)(x))[5], ((UINT8*)(x))[6], ((UINT8*)(x))[7], \
	((UINT8*)(x))[8], ((UINT8*)(x))[9], ((UINT8*)(x))[10], ((UINT8*)(x))[11], \
	((UINT8*)(x))[12], ((UINT8*)(x))[13], ((UINT8*)(x))[14], ((UINT8*)(x))[15]
#endif

#define VDEVID_FMT	"WtpId:%d, VdevId:%d"
#define VDEVID_ARG(x) (x).ulWtpId, (x).ulVDevId

#define VAPID_FMT	"WtpId:%d, VdevId:%d, IfId:%d, VapId:%d"
#define VAPID_ARG(x) (x).ulWtpId, (x).ulVDevId, (x).ulIfId, (x).ulVapId

#define IFID_FMT	"WtpId:%d, VdevId:%d, IfId:%d"
#define IFID_ARG(x) (x).ulWtpId, (x).ulVDevId, (x).ulIfId

#define ADHOCID_FMT	"WtpId:%d, VdevId:%d, IfId:%d, AdhocId:%d"
#define ADHOCID_ARG(x)	(x).ulWtpId, (x).ulVDevId, (x).ulIfId, (x).AdhocId

#define ENETID_FMT	"WtpId:%d, EnetId:%d"
#define ENETID_ARG(x)	(x).ulWtpId, (x).ulEnetId


#define AC_BR_NAME_BEAR		    "br0"			/* AC����������*/
#define AC_BR_NAME_FATLAN		"br1:8"			/* AC L2-WAN ������*/
#define AC_BR_NAME_L2WAN		"br1"			/* AC L2-WAN ������*/
#define AC_BR_NAME_L3WAN		"br2"			/* AC L3-WAN ������*/
#define AC_BR_NAME_MS			"br3"			/* ����ͨ����*/ /* 2011-6-20 pyy ���������޸�*/

#define AC_MS_MODSVAE_FOR_NPUREAD_FILE      "ms-mode.conf"
#define AC_MS_CONFIG_FILE                   "ms.conf"
#define AC_MS_PROC_FILE                     "msstate"

/******************************** �ⲿ����ԭ������ ****************************/
UINT32 ac_get_current_ticks( VOID );
UINT32 ac_get_current_time(VOID);
CHAR*  ac_get_text_time(UINT32 *pulCurrTime);
VOID   ac_print_code (UINT8 *pucMsg, UINT32 ulLen, UINT32 ulLevel);
UINT32 ac_get_rand(VOID);

/********************************** ����ԭ������ ******************************/


/********************************** ȫ�ֽṹ�嶨�� ******************************/
typedef struct
{
    UINT32    ulWtpId;
} AC_WTPID_T;

typedef struct
{
    UINT32    ulWtpId;
    UINT32    ulVDevId;
} AC_VDEVID_T;

typedef struct
{
    UINT32    ulWtpId;
    UINT32    ulVDevId;
    UINT32    ulIfId;
} AC_IFID_T;

typedef struct
{
    UINT32    ulWtpId;
    UINT32    ulVDevId;
    UINT32    ulIfId;
    UINT32    ulVapId;
} AC_VAPID_T;


typedef struct
{
    UINT32    ulWtpId;
    UINT32    ulVDevId;
    UINT32    ulIfId;
    UINT32    ulAdhocId;
} AC_ADHOCID_T;

typedef struct
{
    UINT32    	ulWtpId;
    UINT32	ulEnetId;
} AC_ENETID_T;

/* ����ʵ����ʶ�ṹ�� */
typedef struct {
    UINT32  ulMOC;
    UINT8   aucMOI[AC_MOI_LEN];
} AC_OMA_MO_T;

/* AC�豸��̫������Ϣ */
typedef enum{
	AC_ENET_STATE_NOTRUNNING 	= 0,
	AC_ENET_STATE_10MDUPLEX 		= 1,
	AC_ENET_STATE_100MDUPLEX 	= 2,
	AC_ENET_STATE_1000MDUPLEX 	= 3,
	AC_ENET_STATE_10GEDUPLEX 	= 4,
}AC_ENET_STATE_E ;

typedef enum {
	AC_ENET_OPSTATE_NOTRUNNING 	= 0,	/* δ����*/
	AC_ENET_OPSTATE_RUNNING 		= 1,	/* ����*/
} AC_ENET_OPSTATE_E;

typedef struct  
{
	UINT32 ulEnetPortId;         //��̫���˿ں�:1��4
	CHAR   acEnetPortName[16];   //��̫������:LAN1-LAN4
	CHAR   acEnetPortDesc[32];   //��̫���˿�����
	UINT32 ulEnetType;           //��̫��������
	/*
	 * 0:LAN�˿���	
	 * 1:L2-WAN�˿���
	 * 2:L3-WAN�˿���
	 */
	UINT32 ulEnetState;          //��̫����״̬
	/*
	 * 0:δ����
	 * 1:10Mȫ˫��
	 * 2:100Mȫ˫��
	 * 3:1000Mȫ˫��
	 * 4:10GEȫ˫��
	 */
	UINT32 ulEnetMtu;            //��̫����MTU
	UINT8	aucMac[6];		/* ��̫����MAC*/
	UINT8	aucRsv0[2];
	UINT32	ulEnetAdminState;	/* ��̫���ڹ���״̬*/
								/*
								 * 0:����
								 * 1:����
								 * 2:����
								 */
	UINT32 ulEnetOpState;        	/* ��̫��������״̬0/1 δ����/����*/
	
}AC_ENETPORT_INFO_T;

#define AC_ENETPORT_NUM_MAX	16

/* FTP��غ궨�� */
#define VM_FTP_AGENT_NAME           "ftp_agent"
#define VM_FTP_PROXY_NAME           "ftp_proxy"
#define VM_FTP_FILE_LIST_LEN_MAX    4096
#define VM_FTP_RECV_SIZE            (0x100)
#define VM_FTP_CMD_PUT_FILE          ((UINT32)(0x01)) /* �ϴ� */
#define VM_FTP_CMD_PUT_DIR_PACK      ((UINT32)(0x02)) /* �ϴ���ѹ��*/
#define VM_FTP_CMD_GET_FILE          ((UINT32)(0x11)) /* ���� */
#define VM_FTP_CMD_GET_DIR_PACK      ((UINT32)(0x12)) /* ����ѹ��������ѹ��Ŀ¼ */

#define VM_FS_FILE_ABSPATH_LEN   (256+5)      /* ����·�����Ƴ���*/
#define VM_FS_FILEDIR_LEN        (64)         /*�ļ����·�����Ƴ���*/
#define VM_FTP_USERNAME_LEN      (32)         /* FTP������û������� */
#define VM_FTP_PASSWORD_LEN      (32)         /* FTP����Ŀ���� */
#define VM_FS_FILENAME_LEN       (32+5)       /* �ļ������ȣ�����·���� */

#define VM_FILE_ISDIR(mode)     ((mode & S_IFMT) == S_IFDIR)     /* directory */
#define VM_FD_INVALID           ((UINT32)(0xFFFFFFFF))
#define VM_MAX_OPENED_FILES     60                              /*ͬʱ�򿪵�����ļ�����*/

#define VM_DEFAULT_FTP_PORT     21

#if defined (_OSWIN32_)     /* WINDOWS*/
#include <Wininet.h>

#define VM_FILE_ORDONLY        (_O_RDONLY)    /* ֻ�� */
#define VM_FILE_OWRONLY        (_O_WRONLY)    /* ֻд */
#define VM_FILE_ORDWR          (_O_RDWR)      /* ��д */

#define VM_FILE_OCREATE        (_O_CREAT)     /* ���� */
#define VM_FILE_OAPPEND        (_O_APPEND)    /* ׷�� */
#define VM_FILE_OTRUNC         (_O_TRUNC)     /* ���ԭ������ */

#define VM_FILE_OTEXT          (_O_TEXT)      /* �ı���ʽ */
#define VM_FILE_OBINARY        (_O_BINARY)    /* �����Ʒ�ʽ */

typedef struct
{
    UINT32 ulCmd ;                  /*FTP��������*/
    UINT32 ulLen ;                  /*�û�������ڴ��С*/

    HINTERNET pvInternetSession ;   /*internet���*/
    HINTERNET pvConnectSession ;    /*connection���*/
    HINTERNET pvFTPSession ;        /*ftp���*/

    STRING szServerFileName ;       /*�������ļ����ƣ���������·��*/
    STRING szServerIP ;             /*������IP��ַ*/

    STRING szUserName ;             /*FTP�û�����*/
    STRING szPasswd ;               /*FTP�û�����*/
    STRING szMemBuf ;               /*TFTP�û�������ڴ�ָ��*/
}VM_FTP_CONNECT_T;
#endif  /* #if defined (_OSWIN32_) */

/*
file seek mode
*/
#define VM_SEEK_SET             (SEEK_SET)
#define VM_SEEK_CUR             (SEEK_CUR)
#define VM_SEEK_END             (SEEK_END)

typedef struct
{
    FILE    *pFtpIO;
    INT     iFtpSocket;
}VM_FTP_CMD_HANDLER_T;

/*FTP�ͻ��˴���������Ϣ*/
typedef struct
{
    UINT32  ulSerialID;                                 /* ����ʶ��ͬһ���˳̵Ķ��ftp���� */
    UINT8   aucUserName[VM_FTP_USERNAME_LEN];           /* �û�������󳤶�20���ַ�������'\0'������*/
    UINT8   aucPasswd[VM_FTP_PASSWORD_LEN];             /* ���룬��󳤶�20���ַ�������'\0'������ */
    UINT32  ulServerIP;                                 /* ftp������ip��ַ */
    UINT16  usPort;                                     /* ftp�������˿� */
    UINT16  resv1;
    UINT8   aucServerFile[VM_FS_FILE_ABSPATH_LEN];      /* ���������ļ���(���·��) */
    UINT8   aucClientFile[VM_FS_FILE_ABSPATH_LEN];      /* �ͻ����ļ���(����·��) */

    UINT32   ulFtpCmd;      /* ��������ϴ� VM_FILE_PUT������ VM_FILE_GET*/
    UINT32   ulProgessStep; /* ����ָʾ����ֵ(�ֽ�), 0��ʾ����Ҫ����ָʾ */
    UINT32   ulLen;         /* ����ռ��ֽڳߴ磬���Ϊ0����д���ļ�������д�뻺�� */
    UINT8   *pucMem;        /* ���ļ�����ֱ��д��û���ռ� */
} VM_FTP_REQ_MSG_T;

typedef struct
{
    UINT16 usYear ;      /* �� [xxxx],����2006*/
    UINT8  ucMonth ;     /* �� [1..12]*/
    UINT8  ucDay;        /* �� [1..31]*/
    UINT8  ucHour;       /* ʱ [0..23]*/
    UINT8  ucMinute;     /* �� [0..59]*/
    UINT8  ucSecond;     /* �� [0..59]*/
    UINT8  ucWeek;       /* ����[0..6],������Ϊ0��������ʱ��ʱ������������Ϣ */
} VM_TIME_T;

/*�ļ��������Ͷ���*/
typedef struct
{
    UINT16      usMode;          /* �������ݲ�ʹ��file mode,Bit mask for file-mode information. */
    UINT16      usReserved;
    UINT32      ulSize;          /* size of file, in bytes */
    VM_TIME_T   stAccessTime;    /* time of last access */
    VM_TIME_T   stModifyTime;    /* time of last modification */
    VM_TIME_T   stChangTime;     /* time of last change of file status */
} VM_FILE_STAT_T;

typedef struct 
{
    CHAR        *szKey;
    UINT32      ulType;
#define PROPERTY_INT        0
#define PROPERTY_STRING     1
#define PROPERTY_IP         2

    UINT32      ulReadTime;     /* �ж��Ƿ񱻶�ȡ��������ʾ�ظ� */
    UINT32      ulReadValue;    /* ����STRING����Ӧ����һ��ָ�룬�ɵ����߷��䣻
                                   ����IP��ַ����Ӧ����һ��BYTE[4]���� */

    VOID*       pValue;         /* ������Ҫ��ֵ��λ�� */
}VM_PROPERTY_DESC_T;
/*2012-12-5 ldm add for task277 in chandao*/
void ac_reboot(int iLogLevel, char *szFormat, ...);
//VOID ac_reboot(VOID);
extern UINT32 VmFtpGet(VM_FTP_REQ_MSG_T* pstFTPReqMsg,
               UINT32 ulDstPid);
extern UINT32 VmFtpPut(VM_FTP_REQ_MSG_T* pstFTPReqMsg,
               UINT32 ulDstPid);
extern UINT32 VmFsFtp(VM_FTP_REQ_MSG_T* pstFTPReqMsg,
              UINT32 ulDstPid);

extern BOOL VmReadProperty(CHAR *szConfigFile, UINT32 ulPropertyNum, VM_PROPERTY_DESC_T *pstPropertyDesc);
extern BOOL VmFileIsDir(const CHAR *szFileName);

BOOL VmCode(UINT8* pucData, UINT32 ulLen);
BOOL VmDecode(UINT8* pucData, UINT32 ulLen);
BYTE VmHexCharToByte(UINT8 ucHexChar);

extern inline void	AC_SYSTEM(char *cmd);

/* BEGIN: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */
/* license��غ궨�� */
#define AC_LICENSE_WTP_ENABLE           11          /* ap���빦�� */
#define AC_LICENSE_WTP_MAXNUM           12          /* ac�������ap��Ŀ���� */
#define AC_LICENSE_STA_ENABLE           13          /* sta���빦�� */
#define AC_LICENSE_STA_MAXNUM           14          /* ac�������sta��Ŀ���� */
#define AC_LICENSE_AUTHORTIME_ENABLE    15          /* license��Ȩʱ�书�� */
#define AC_LICENSE_KEY_MAXNUM           16          /* AC-KEY��ap����������ac�ͺ�֧������ */
#define AC_LICENSE_OEM_VENDOR           17          /* AC-OEM�ĳ�����Ϣͬac-key�Ĳ�һ�� */

/* END: Added by wubin,2013/7/4 TASK #919 ����ҵ����������license���ܣ�����ac license��ap license��---��ֲ */

#ifndef ULLONG_MAX
#define ULLONG_MAX (0xffffffffffffffffull)
#endif

/* 2011-09-02 fengjing add my_strtoull */
const char * my_strtox_prelim( const char * p, char * sign, int * base );
unsigned long long my_strtox_main( const char ** p, unsigned int base, unsigned long long error, unsigned long long limval, int limdigit, char * sign );
unsigned long long my_strtoull( const char * s, char ** endptr, int base ) ;

#if 0
unsigned long long my_htonll(unsigned long long n);
unsigned long long my_ntohll(unsigned long long n);
#else
//#include <asm/byteorder.h>
#include <endian.h>
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define my_ntohll(x) (((long long)(ntohl((int)(((x) << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)((x) >> 32)))) 
#define my_htonll(x) my_ntohll(x)
#else
#define my_ntohll(x)	(x)
#define my_htonll(x)	(x)
#endif
#endif


#endif /* _AC_PUBLIC_H */
/******************************* ͷ�ļ����� **********************************/
