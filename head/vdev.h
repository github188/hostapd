/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
******************************************************************************/

#ifndef L2W_VDEV_H
#define L2W_VDEV_H


typedef struct {
	u32	ulVdevId;
	struct net_device			*pstRealNetDev;
	struct net_device_stats		stDevStats;
} L2W_VDEV_INFO_T;

#define L2W_VDEV_INFO(x)	((L2W_VDEV_INFO_T *)(x->priv))
#define IFF_L2W_VDEV 		0x4             /* L2W virtual device flag */

#define L2W_VDEV_ID_MIN		0
#define L2W_VDEV_ID_MAX 		15
#define SKB_RESERVE 128

#define L2W_VDEV_THREAD 1
int l2w_vdev_xmitd_start(void);
void l2w_vdev_xmitQ_push(struct sk_buff *skb);

#if 0
#define here do { l2w_printk(L2W_FATAL, "   --> %s : [Line %d]\n", __FUNCTION__, __LINE__);} while(0)
#else
#define here do { }while(0)
#endif

extern unsigned long gstPrintSwitch;
extern L2W_PKT_STATS_T gstFrgStat;


#endif

/******************************* end **********************************/

