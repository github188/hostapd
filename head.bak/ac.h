/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
******************************************************************************/

#ifndef L2W_H
#define L2W_H

#include <linux/module.h>
#include <linux/types.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/fcntl.h>
#include <linux/socket.h>
#include <linux/in.h>
#include <linux/inet.h>
#include <linux/inetdevice.h>
#include <linux/netdevice.h>
#include <linux/string.h>
#include <linux/netfilter_ipv4.h>
#include <linux/errno.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/skbuff.h>
#include <linux/init.h>
#include <linux/workqueue.h>
#include <linux/jhash.h>
#include "../br_private.h"

#include <net/snmp.h>
#include <net/ip.h>
#include <net/route.h>
#include <net/protocol.h>
#include <net/icmp.h>
#include <net/tcp.h>
#include <net/udp.h>
#include <net/raw.h>
#include <net/sock.h>
#include <net/checksum.h>
#include <net/sock.h>

#include <asm/system.h>
#include <asm/uaccess.h>

typedef unsigned long bool;
#define TRUE		1
#define FALSE	0

#include "util.h"
#include "stat.h"
#include "packet.h"
#include "module.h"
#include "vdev.h"
#include "sms4.h"
#include "wapi_ac_wpi.h"
#include "data.h"
#include "l2wctl_public.h"


#define FILL_LEN	2

#define MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3], ((u8*)(x))[4], ((u8*)(x))[5]

#define IP_FMT	"%u.%u.%u.%u"
#define IP_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3]
     
#endif

/******************************* end **********************************/

