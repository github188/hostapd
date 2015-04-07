
#ifndef __WAPI_INCLUDES_H__
#define __WAPI_INCLUDES_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>

#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <linux/if_packet.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#include <sys/ioctl.h>

#include "include/compat.h"
#include "wapi_common.h"

#include "net80211/wireless_copy.h"
#include "net80211/ieee80211.h"
#include "net80211/_ieee80211.h"
#include "net80211/ieee80211_crypto.h"
#include "net80211/ieee80211_ioctl.h"

#include "OssApi.h"
#include "OssUtility.h"
#include "OssVos.h"
#include "ac_public.h"

/* #include "../../../memwatch-2.71/memwatch.h" */

#endif /* INCLUDES_H */

