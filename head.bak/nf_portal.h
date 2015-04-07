#ifndef _NF_PORTAL_H
#define _NF_PORTAL_H

/*
#define DEBUG

#ifdef DEBUG
#define paprintk printk
#else
#define paprintk(...)  
#endif
*/

#define paprintk(...)  if(g_printk_on != 0) printk(__VA_ARGS__) 
    
#define AUTHING_USER_MAX_LIEFTIME       120   /* 秒数，因为代码里面使用HZ */
//#define debug(format, ...) fprintf (stderr, format, __VA_ARGS__)

#define MAJOR_DEV_NUM 200
#define DEVICE_NAME "portaldev"

#define PORTAL_SKB_SET_MARK(skb, mark)  (skb)->nfmark = mark
#define PORTAL_NORMAL_MARK  1
#define PORTAL_SPECIAL_MARK 2

//#define TEST
extern int is_auth_passed_user(unsigned char *pucMac);
extern PORTAL_CONFIG_T g_stPortalConfig;

extern unsigned int g_ulAuthing ;
extern int g_authing_user_num;


typedef struct 
{
    WHITELIST_T stWhitelist;
    struct list_head stNode;
    
}WHITELIST_LIST_T;

typedef struct {

    char aucMac[6];
    char aucIp[4];
    unsigned int ulRefCnt;  /* 用户被添加的次数， */
    unsigned int ulTime;  /* 用户的记录创建的时间 */
    unsigned short usSrcPort;
    unsigned short usDstPort;
    unsigned int ulSrcIp;
    unsigned int ulDstIp;
    struct hlist_node  stHlistNd;    /* 以MAC为索引的地址列表 */
    struct hlist_node  stHlistIpNd;  /* 以IP为索引的地址列表 */
    struct list_head   stListNode;
    //struct timer_list  stLifeTimer;
}AUTHING_USER_NODE_T;

typedef struct {

    char aucMac[6];
    char aucIp[4];
    struct hlist_node  stHlistNd;    /* 以MAC为索引的地址列表 */
}AUTH_FINISH_USER_NODE_T;

typedef struct {
    unsigned char aucMask[4];
} MASK_T;
typedef struct {
    MASK_T stMask;
    struct list_head stNode;
} MASK_LIST_T;

/* BEGIN: Added by wns, 2012/11/16   PN:TASK#225 */
#define URL_LEN_MAX 			64
#define URL_NUM_MAX				64

#define IP_HASH_TBL_SIZE		1024
#define HASH_RSLT(ip)				ip_hash((ip), IP_HASH_TBL_SIZE)
#define HASH_LOCK(num)				(g_astIpHashTbl[num].stLock)
#define LIST_LOCK(url)				((url)->stLock)

#define LIST_READ_LOCK(lock) 		read_lock_bh(&(lock))
#define LIST_READ_UNLOCK(lock) 		read_unlock_bh(&(lock))
#define LIST_WRITE_LOCK(lock)		write_lock_bh(&(lock))
#define LIST_WRITE_UNLOCK(lock)		write_unlock_bh(&(lock))

#define URL_HTTP_STR_LEN		7
#define URL_HTTPS_STR_LEN		8

#define URL_PORT_TYPE_ALL		1
#define URL_PORT_TYPE_HTTP		80
#define URL_PORT_TYPE_HTTPS		443

#define DNS_TYPE_A				0x0001
#define DNS_CLASS_IN			0x0001

#define ONE_DAY_SECONDS			(24 * 3600)

#define URL_INDEX(id)			((id) - 1)
typedef struct
{
	unsigned short		usId;
	unsigned short		usFlags;
	unsigned short		usQuestNum;		//query个数
	unsigned short		usAnswerNum;	//answer个数
	unsigned short		usAuthorNum;
	unsigned short		usAdditionNum;
}URL_DNS_HDR_T;

typedef struct
{
	unsigned short 		usType;
	unsigned short 		usClass;
}URL_DNS_QUERY_TAIL_T;

typedef struct
{
	unsigned short		usName;
	unsigned short		usType;			//type = 0x0001 or 0x0005
	unsigned short		usClass;
	unsigned char		aucTtl[4];
	unsigned short		usLen;			//length= 4 or 6 or variable
}URL_DNS_ANSWER_T;

typedef struct
{
	unsigned long		ulUrlId;
    unsigned char		aucWhiteUrl[URL_LEN_MAX];
	unsigned short		usPort;			//解析fwctl发送来的消息时填充[0:未填充 1:all 2:http 3:https]
	struct list_head	stListHd;
	rwlock_t			stLock;
}URL_WHITEURL_NODE_T;

typedef struct
{ 
    unsigned char 		aucIp[4];
    URL_WHITEURL_NODE_T *pstUrl;
    unsigned long 		ulTtl;
	struct hlist_node  	stHlistNd;
    struct list_head	stListNd;
}URL_IP_NODE_T;

typedef struct
{
	struct hlist_head	stIpHashHd;
	rwlock_t			stLock;
}IP_HASH_TBL;
/* END:   Added by wns, 2012/11/16   PN:TASK#225 */

typedef AUTHING_USER_NODE_T DISAUTH_USER_NODE_T;

//typedef unsigned char u8;
#define MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3], ((u8*)(x))[4], ((u8*)(x))[5]
#define IP_FMT	"%u.%u.%u.%u"
#define IP_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3]

extern PORTAL_CONFIG_T g_stPortalConfig;
extern struct file_operations portaldev_fops;

#define PORTAL_USER_TBL_HASHBITS           12
#define PORTAL_USER_TBL_HASH_SIZE         (1 << PORTAL_USER_TBL_HASHBITS)
extern struct hlist_head g_astUserMacTbl[PORTAL_USER_TBL_HASH_SIZE];
#define WHITELIST_INVALID_ID  ((unsigned int)0xFFFFFFFF)

int is_authing_user(unsigned char *pucMac);
int enable_new_authuser(void);
int mac_hash(unsigned char *pcMac, int iTblSize);
void portal_user_tbl_init(void);
inline int portal_get_mac_hash(unsigned char *pucMac);
inline int portal_get_ip_hash(unsigned char *pucIp);

AUTHING_USER_NODE_T* authing_user_get_by_mac(unsigned char* pucMac);
AUTHING_USER_NODE_T* authing_user_get_by_ip(unsigned char* pucIp);
AUTHING_USER_NODE_T *authing_user_tbl_create(unsigned char *pucMac, unsigned char *pucIp);
int authing_user_tbl_delete(AUTHING_USER_NODE_T *pstUser);
AUTHING_USER_NODE_T *authing_user_fetch(void);
int authing_user_tbl_delete_by_mac(unsigned char *pucMac);

int portal_config(PORTAL_CONFIG_T *pstConfig);
int ioctl_set_auth_finish_user(PORTAL_IOCTL *pstIoctl);
int ioctl_get_authing_user(PORTAL_IOCTL *pstIoctl);
WHITELIST_LIST_T * find_whitelist(WHITELIST_T *pstConfig);
int insert_whitelist(WHITELIST_T *pstConfig);
int delete_whitelist(WHITELIST_T *pstConfig);
int update_whitelist(WHITELIST_T *pstConfig);
int whitelist_config(WHITELIST_CONFIG_T *pstConfig);
void whitelist_show(void);
int whitelist_match(unsigned int ulIp, unsigned short usPort, unsigned int ulProto);
void portal_config_init(void);
void authing_user_flush(unsigned long ulData);
void del_auth_finished_user(unsigned char *pucMac);
int authing_user_tbl_auth_finish(unsigned char *pucMac);
extern int (*ac_mng_access_ctl_hook)(const struct sk_buff *skb);

#endif
