/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
******************************************************************************/

#ifndef L2W_PACKET_H
#define L2W_PACKET_H

/******************************************************************************/
/* 数据结构定义*/
/* AP设备*/
typedef struct 
{
	
} L2W_AP_DEV_T;

/* 虚设备交换时的头*/
typedef struct 
{
	u8	aucDest[ETH_ALEN];
	u8	aucSrc[ETH_ALEN];
	u16	usProto;
	u8	aucRsv[2];
	/* 	端口列表位图
		上行报文，用于指示报文源端口
		下行报文，用于指示报文需要发送到哪些端口 */
	u32	ulPortmap1;	/* bit0~bit31 表示端口号0~31*/
	
} L2W_VDEVHDR_T;


typedef struct 
{
	u32		ulSAddr;
	u32		ulDAddr;						
	u32		ulId;		
	u16		usLen;		
	u16		usOffset;	
	u8		ucDf;		
	u8		ucLf;		
    u8      is_keepalive; 
    u8      capwapfrag;  
	u8		aucRsv[4];	 
     
}  L2W_CENTHDR_T;

/* BEGIN: Added by hdd, 2013/4/2   PN:200 */
typedef struct
{
    u8 aucSrc[6];
    u8 aucDst[6];
    u16 usPort;
    u32 ulApId;
}__attribute__((packed))L2W_KEEPALIVE_T;

/* END:   Added by hdd, 2013/4/2   PN:200 */


#if 0
struct  _L2W_PKT_QUEUE_T
{
	struct hlist_node	idhlist; 
	u32		ulSAddr;
	u32		ulDAddr;
	u32		ulStamp;	
	u32		ulId;
	u16		usLen;
	u8		ucLf;	/* 分片编号*/
    //u8      ucStarTime; 
    atomic_t refcnt;          /*reference count*/
	struct timer_list timer;	/* used to delete queue which one is timeout*/	
	u8		aucRsv[5];
	char 	*pcBuff;;
} ;

typedef struct _L2W_PKT_QUEUE_T L2W_PKT_QUEUE_T;

#endif

typedef struct 
{
	u32		ulSAddr;
	u32		ulDAddr;
	struct sk_buff *skb;
	u32     ulId;      
	u8 frag_id;      
    u8 used;        
    u16 flags;     
	struct hlist_node	idhlist;   
	atomic_t refcnt;          
	struct timer_list timer;	
	u32 ulArriveTime;
}L2W_PKT_QUEUE_T;


//typedef struct _L2W_PKT_QUEUE_T L2W_PKT_QUEUE_T;

typedef struct 
{
	
	u32	ulRxPktNum; /*接收报文总数*/
	u32	ulRxFragNum;/* 分片报文总数 */
    u32	ulEnqueueNum;/* 入队报文总数 */
    u32	ulDequeueNum;/* 出队报文总数 */
	u32	ulDropNum;  /* 丢包总数 */
    u32	ulKmallocMem;
    u32	ulHaveMem;
    u32	ulFreeKmallocMem;
    u32	ulFreeHaveMem;
} L2W_PKT_STATS_T;

typedef struct 
{
	u32	ulTxPktSeq;			
	u32	ulTxUniPktSeq;		
	u32	ulTxBcPktSeq;		

	u32	ulRxPktSeq;			
	u32	ulRxUniPktSeq;	
	u32	ulRxBcPktSeq;		

	u32	ulTxPktNum;
	u32	ulTxUniPktNum;
	u32	ulTxBcPktNum;

	u32	ulRxPktNum;
	u32	ulRxUniPktNum;
	u32	ulRxBcPktNum;
} L2W_PKT_STAT_T;

typedef struct
{
	u32	ulDevType;	
	u32	ulDevId;		
	u32	ulOwnIp;		
} L2W_OWN_INFO_T;


/******************************************************************************/



#define L2W_UDP_HLEN				8

#define L2W_MTU			1200
#define L2W_FRAG0_LEN	800

#define L2W_VHLEN	(sizeof(L2W_VDEVHDR_T))
#define L2W_HLEN	(sizeof(L2W_CENTHDR_T))
#define L2W_PKTQ_HASHSZ	1024
#define L2W_KLEN   (sizeof(L2W_KEEPALIVE_T))/* ADD hdd 2013-4-2 */

#ifndef AC_L2W_UDP_RCV
#define L2W_TUNNEL_LEN 54   /*L2W_UDP_HLEN+L2W_HLEN+L2W_VHLEN+FILL_LEN*/
#define L2W_UDP_CENT_LEN    32      /*L2W_UDP_HLEN+L2W_HLEN*/
#endif
#define L2W_PORT	61000	/* port used data exchange between ac and ap */

/******************************************************************************/

extern int br_apl2w_handle_frame (struct net_bridge_port *p, struct sk_buff *skb);
extern int br_acl2w_handle_frame (struct net_bridge_port *p, struct sk_buff *skb);
extern int br_l2w_should_learn_port (struct net_bridge *br, struct net_device *dev);
extern int br_acl2w_should_deliver(const struct net_bridge_port *p, const struct sk_buff *skb);
extern int br_apl2w_should_deliver(const struct net_bridge_port *p, const struct sk_buff *skb);
extern int br_l2w_handle_macip_add(u8 *pucMac, u8 *pucIp, char *pcIfName);
extern int br_l2w_handle_macip_del(u8 *pucMac);
extern int l2w_bridge_up_mac_filter(const struct  sk_buff *skb);
extern int br_apl2w_localforward_isolate(const struct net_bridge_port *p, const struct sk_buff *skb);
extern int br_acl2w_wan_dev_get(int isFwd, struct net_bridge_port *orgdst, struct sk_buff *skb, struct net_bridge_port **dst);
extern int vlan_get_nestvlanid (char *pcIfName, u32 ulUserVlanId,u8 *dest);
extern int vlan_get_uservlanid (char *pcIfName, u32 ulNestVlanId,u8 *source);
extern bool l2w_udp_rcv(struct sk_buff *skb);

#endif

/******************************* end **********************************/

