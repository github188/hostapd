/*
 * wpa_supplicant/hostapd / common helper functions, etc.
 * Copyright (c) 2002-2006, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef COMMON_H
#define COMMON_H

#include "os.h"

#ifdef __linux__
#include <endian.h>
#include <byteswap.h>
#endif /* __linux__ */

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
#include <sys/types.h>
#include <sys/endian.h>
#define __BYTE_ORDER	_BYTE_ORDER
#define	__LITTLE_ENDIAN	_LITTLE_ENDIAN
#define	__BIG_ENDIAN	_BIG_ENDIAN
#define bswap_16 bswap16
#define bswap_32 bswap32
#define bswap_64 bswap64
#endif /* defined(__FreeBSD__) || defined(__NetBSD__) ||
	* defined(__DragonFly__) */

#ifdef CONFIG_TI_COMPILER
#define __BIG_ENDIAN 4321
#define __LITTLE_ENDIAN 1234
#ifdef __big_endian__
#define __BYTE_ORDER __BIG_ENDIAN
#else
#define __BYTE_ORDER __LITTLE_ENDIAN
#endif
#endif /* CONFIG_TI_COMPILER */

#ifdef CONFIG_NATIVE_WINDOWS
#include <winsock.h>

typedef int socklen_t;

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0 /* not supported */
#endif

#endif /* CONFIG_NATIVE_WINDOWS */

#if defined(__CYGWIN__) || defined(CONFIG_NATIVE_WINDOWS)
#ifdef _MSC_VER
#define inline __inline
#endif /* _MSC_VER */
static inline unsigned short wpa_swap_16(unsigned short v)
{
	return (unsigned short)(((v & 0xff) << 8) | (v >> 8));
}
static inline unsigned int wpa_swap_32(unsigned int v)
{
	return ((v & 0xff) << 24) | ((v & 0xff00) << 8) |
		((v & 0xff0000) >> 8) | (v >> 24);
}
#ifdef _MSC_VER
static inline __int64 wpa_swap_64 (__int64 v)
#else
static inline long long wpa_swap_64 (long long v)
#endif
{
    return ((v & 0xff) << 56) | ((v & 0xff00) << 40) | ((v & 0xff0000) << 24) | ((v & 0xff000000) << 8)
		| ((v & 0xff00000000) >> 8) | ((v & 0xff0000000000) >> 24) | ((v & 0xff000000000000) >> 40) | (v >> 56) ;
}
#define le_to_host16(n) (n)
#define host_to_le16(n) (n)
#define be_to_host16(n) wpa_swap_16(n)
#define host_to_be16(n) wpa_swap_16(n)
#define le_to_host32(n) (n)
#define be_to_host32(n) wpa_swap_32(n)
#define host_to_be32(n) wpa_swap_32(n)
#define host_to_be64(n) wpa_swap_64(n)
#else /* __CYGWIN__ */

#ifndef __BYTE_ORDER
#ifndef __LITTLE_ENDIAN
#ifndef __BIG_ENDIAN
#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN 4321
#if defined(sparc)
#define __BYTE_ORDER __BIG_ENDIAN
#endif
#endif /* __BIG_ENDIAN */
#endif /* __LITTLE_ENDIAN */
#endif /* __BYTE_ORDER */

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define le_to_host16(n) (n)
#define host_to_le16(n) (n)
#define be_to_host16(n) bswap_16(n)
#define host_to_be16(n) bswap_16(n)
#define le_to_host32(n) (n)
#define be_to_host32(n) bswap_32(n)
#define host_to_be32(n) bswap_32(n)
#define le_to_host64(n) (n)
#define host_to_le64(n) (n)
#define be_to_host64(n) bswap_64(n)
#define host_to_be64(n) bswap_64(n)
#elif __BYTE_ORDER == __BIG_ENDIAN
#define le_to_host16(n) bswap_16(n)
#define host_to_le16(n) bswap_16(n)
#define be_to_host16(n) (n)
#define host_to_be16(n) (n)
#define le_to_host32(n) bswap_32(n)
#define be_to_host32(n) (n)
#define host_to_be32(n) (n)
#define le_to_host64(n) bswap_64(n)
#define host_to_le64(n) bswap_64(n)
#define be_to_host64(n) (n)
#define host_to_be64(n) (n)
#ifndef WORDS_BIGENDIAN
#define WORDS_BIGENDIAN
#endif
#else
#error Could not determine CPU byte order
#endif

#endif /* __CYGWIN__ */

/* Macros for handling unaligned 16-bit variables */
#define WPA_GET_BE16(a) ((u16) (((a)[0] << 8) | (a)[1]))
#define WPA_PUT_BE16(a, val)			\
	do {					\
		(a)[0] = ((u16) (val)) >> 8;	\
		(a)[1] = ((u16) (val)) & 0xff;	\
	} while (0)

#define WPA_GET_LE16(a) ((u16) (((a)[1] << 8) | (a)[0]))
#define WPA_PUT_LE16(a, val)			\
	do {					\
		(a)[1] = ((u16) (val)) >> 8;	\
		(a)[0] = ((u16) (val)) & 0xff;	\
	} while (0)

#define WPA_GET_BE24(a) ((((u32) (a)[0]) << 16) | (((u32) (a)[1]) << 8) | \
			 ((u32) (a)[2]))
#define WPA_PUT_BE24(a, val)				\
	do {						\
		(a)[0] = (u8) (((u32) (val)) >> 16);	\
		(a)[1] = (u8) (((u32) (val)) >> 8);	\
		(a)[2] = (u8) (((u32) (val)) & 0xff);	\
	} while (0)

#define WPA_GET_BE32(a) ((((u32) (a)[0]) << 24) | (((u32) (a)[1]) << 16) | \
			 (((u32) (a)[2]) << 8) | ((u32) (a)[3]))
#define WPA_PUT_BE32(a, val)				\
	do {						\
		(a)[0] = (u8) (((u32) (val)) >> 24);	\
		(a)[1] = (u8) (((u32) (val)) >> 16);	\
		(a)[2] = (u8) (((u32) (val)) >> 8);	\
		(a)[3] = (u8) (((u32) (val)) & 0xff);	\
	} while (0)

#define WPA_PUT_BE64(a, val)				\
	do {						\
		(a)[0] = (u8) (((u64) (val)) >> 56);	\
		(a)[1] = (u8) (((u64) (val)) >> 48);	\
		(a)[2] = (u8) (((u64) (val)) >> 40);	\
		(a)[3] = (u8) (((u64) (val)) >> 32);	\
		(a)[4] = (u8) (((u64) (val)) >> 24);	\
		(a)[5] = (u8) (((u64) (val)) >> 16);	\
		(a)[6] = (u8) (((u64) (val)) >> 8);	\
		(a)[7] = (u8) (((u64) (val)) & 0xff);	\
	} while (0)


#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#ifdef _MSC_VER
typedef UINT64 u64;
typedef UINT32 u32;
typedef UINT16 u16;
typedef UINT8 u8;
typedef INT64 s64;
typedef INT32 s32;
typedef INT16 s16;
typedef INT8 s8;

typedef unsigned __int32 gid_t ;

typedef UINT64  u_int64_t;
typedef UINT32  u_int32_t;
typedef UINT16  u_int16_t;
typedef UINT8   u_int8_t;
typedef INT64	int64_t ;
typedef INT32	int32_t ;
typedef INT16	int16_t ;
typedef INT8    int8_t;

#define WPA_TYPES_DEFINED
#endif /* _MSC_VER */

#ifdef __vxworks
typedef unsigned long long u64;
typedef UINT32 u32;
typedef UINT16 u16;
typedef UINT8 u8;
typedef long long s64;
typedef INT32 s32;
typedef INT16 s16;
typedef INT8 s8;
#define WPA_TYPES_DEFINED
#endif /* __vxworks */

#ifdef CONFIG_TI_COMPILER
#ifdef _LLONG_AVAILABLE
typedef unsigned long long u64;
#else
/*
 * TODO: 64-bit variable not available. Using long as a workaround to test the
 * build, but this will likely not work for all operations.
 */
typedef unsigned long u64;
#endif
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define WPA_TYPES_DEFINED
#endif /* CONFIG_TI_COMPILER */

#ifndef WPA_TYPES_DEFINED
#ifdef CONFIG_USE_INTTYPES_H
#include <inttypes.h>
#else
#include <stdint.h>
#endif
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int64_t s64;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
#define WPA_TYPES_DEFINED
#endif /* !WPA_TYPES_DEFINED */

#define hostapd_get_rand os_get_random
int hwaddr_aton(const char *txt, u8 *addr);
int hexstr2bin(const char *hex, u8 *buf, size_t len);
void inc_byte_array(u8 *counter, size_t len);
void wpa_get_ntp_timestamp(u8 *buf);


#ifdef __GNUC__
#define PRINTF_FORMAT(a,b) __attribute__ ((format (printf, (a), (b))))
#define STRUCT_PACKED __attribute__ ((packed))
#else
#define PRINTF_FORMAT(a,b)
#define STRUCT_PACKED
#endif


/* Debugging function - conditional printf and hex dump. Driver wrappers can
 * use these for debugging purposes. */

/* 雷杰 2008/8/7 枚举成员MSG_INFO 与/usr/include/sys/msg.h中的宏定义冲突，必须定义成宏（虽然宏定义的值不同，但能编译通过）*/
/* enum { MSG_MSGDUMP, MSG_DEBUG, MSG_INFO, MSG_WARNING, MSG_ERROR }; */
#define MSG_MSGDUMP     0
#define MSG_DEBUG       1
#ifndef MSG_INFO
#define MSG_INFO        2
#endif
#define MSG_WARNING     3
#define MSG_ERROR       4

#ifdef CONFIG_NO_STDOUT_DEBUG

#define wpa_debug_print_timestamp() do { } while (0)
#define wpa_printf(args...) do { } while (0)
#define wpa_hexdump(l,t,b,le) do { } while (0)
#define wpa_hexdump_key(l,t,b,le) do { } while (0)
#define wpa_hexdump_ascii(l,t,b,le) do { } while (0)
#define wpa_hexdump_ascii_key(l,t,b,le) do { } while (0)
#define wpa_debug_open_file(p) do { } while (0)
#define wpa_debug_close_file() do { } while (0)

#else /* CONFIG_NO_STDOUT_DEBUG */

int wpa_debug_open_file(const char *path);
void wpa_debug_close_file(void);

/**
 * wpa_debug_printf_timestamp - Print timestamp for debug output
 *
 * This function prints a timestamp in <seconds from 1970>.<microsoconds>
 * format if debug output has been configured to include timestamps in debug
 * messages.
 */
void wpa_debug_print_timestamp(void);

/**
 * wpa_printf - conditional printf
 * @level: priority level (MSG_*) of the message
 * @fmt: printf format string, followed by optional arguments
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration.
 *
 * Note: New line '\n' is added to the end of the text when printing to stdout.
 */
void wpa_printf(int level, char *fmt, ...)
PRINTF_FORMAT(2, 3);

/**
 * wpa_hexdump - conditional hex dump
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump.
 */
void wpa_hexdump(int level, const char *title, const u8 *buf, size_t len);

/**
 * wpa_hexdump_key - conditional hex dump, hide keys
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump. This works
 * like wpa_hexdump(), but by default, does not include secret keys (passwords,
 * etc.) in debug output.
 */
void wpa_hexdump_key(int level, const char *title, const u8 *buf, size_t len);

/**
 * wpa_hexdump_ascii - conditional hex dump
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump with both
 * the hex numbers and ASCII characters (for printable range) are shown. 16
 * bytes per line will be shown.
 */
void wpa_hexdump_ascii(int level, const char *title, const u8 *buf,
		       size_t len);

/**
 * wpa_hexdump_ascii_key - conditional hex dump, hide keys
 * @level: priority level (MSG_*) of the message
 * @title: title of for the message
 * @buf: data buffer to be dumped
 * @len: length of the buf
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. The contents of buf is printed out has hex dump with both
 * the hex numbers and ASCII characters (for printable range) are shown. 16
 * bytes per line will be shown. This works like wpa_hexdump_ascii(), but by
 * default, does not include secret keys (passwords, etc.) in debug output.
 */
void wpa_hexdump_ascii_key(int level, const char *title, const u8 *buf,
			   size_t len);

#endif /* CONFIG_NO_STDOUT_DEBUG */


#ifdef CONFIG_NO_WPA_MSG
#define wpa_msg(args...) do { } while (0)
#define wpa_msg_register_cb(f) do { } while (0)
#else /* CONFIG_NO_WPA_MSG */
/**
 * wpa_msg - Conditional printf for default target and ctrl_iface monitors
 * @ctx: Pointer to context data; this is the ctx variable registered
 *	with struct wpa_driver_ops::init()
 * @level: priority level (MSG_*) of the message
 * @fmt: printf format string, followed by optional arguments
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration. This function is like wpa_printf(), but it also sends the
 * same message to all attached ctrl_iface monitors.
 *
 * Note: New line '\n' is added to the end of the text when printing to stdout.
 */
void wpa_msg(void *ctx, int level, char *fmt, ...) PRINTF_FORMAT(3, 4);

typedef void (*wpa_msg_cb_func)(void *ctx, int level, const char *txt,
				size_t len);

/**
 * wpa_msg_register_cb - Register callback function for wpa_msg() messages
 * @func: Callback function (%NULL to unregister)
 */
void wpa_msg_register_cb(wpa_msg_cb_func func);
#endif /* CONFIG_NO_WPA_MSG */


int wpa_snprintf_hex(char *buf, size_t buf_size, const u8 *data, size_t len);
int wpa_snprintf_hex_uppercase(char *buf, size_t buf_size, const u8 *data,
			       size_t len);


#ifdef EAPOL_TEST
#define WPA_ASSERT(a)						       \
	do {							       \
		if (!(a)) {					       \
			printf("WPA_ASSERT FAILED '" #a "' "	       \
			       "%s %s:%d\n",			       \
			       __FUNCTION__, __FILE__, __LINE__);      \
			exit(1);				       \
		}						       \
	} while (0)
#else
#define WPA_ASSERT(a) do { } while (0)
#endif


#ifdef _MSC_VER
#undef vsnprintf
#define vsnprintf _vsnprintf
#undef close
#define close closesocket
#endif /* _MSC_VER */


#ifdef CONFIG_ANSI_C_EXTRA

#if !defined(_MSC_VER) || _MSC_VER < 1400
/* snprintf - used in number of places; sprintf() is _not_ a good replacement
 * due to possible buffer overflow; see, e.g.,
 * http://www.ijs.si/software/snprintf/ for portable implementation of
 * snprintf. */
int snprintf(char *str, size_t size, const char *format, ...);

/* vsnprintf - only used for wpa_msg() in wpa_supplicant.c */
int vsnprintf(char *str, size_t size, const char *format, va_list ap);
#endif /* !defined(_MSC_VER) || _MSC_VER < 1400 */

/* getopt - only used in main.c */
int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optind;

#ifndef CONFIG_NO_SOCKLEN_T_TYPEDEF
#ifndef __socklen_t_defined
typedef int socklen_t;
#endif
#endif

/* inline - define as __inline or just define it to be empty, if needed */
#ifdef CONFIG_NO_INLINE
#define inline
#else
#define inline __inline
#endif

#ifndef __func__
#define __func__ "__func__ not defined"
#endif

#ifndef __LINE__
#define __LINE__	0
#endif

#ifndef bswap_16
#define bswap_16(a) ((((u16) (a) << 8) & 0xff00) | (((u16) (a) >> 8) & 0xff))
#endif

#ifndef bswap_32
#define bswap_32(a) ((((u32) (a) << 24) & 0xff000000) | \
		     (((u32) (a) << 8) & 0xff0000) | \
     		     (((u32) (a) >> 8) & 0xff00) | \
     		     (((u32) (a) >> 24) & 0xff))
#endif

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif

#ifdef _WIN32_WCE
void perror(const char *s);
#else
#define perror(s)	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, "%s, %s, error(%d: %s).\n", __func__, s, errno, strerror(errno))
#endif /* _WIN32_WCE */

#endif /* CONFIG_ANSI_C_EXTRA */

#ifdef DEBUG_MEM
#define wpa_zalloc(s)  VM_ZALLOC(s)
#else
#define wpa_zalloc(s) os_zalloc((s))
#endif

#ifdef CONFIG_NATIVE_WINDOWS
void wpa_unicode2ascii_inplace(TCHAR *str);
TCHAR * wpa_strdup_tchar(const char *str);
#else /* CONFIG_NATIVE_WINDOWS */
#define wpa_unicode2ascii_inplace(s) do { } while (0)
#define wpa_strdup_tchar(s) VM_STRDUP((s))
#endif /* CONFIG_NATIVE_WINDOWS */

const char * wpa_ssid_txt(u8 *ssid, size_t ssid_len);

typedef u32 __be32;
typedef u64 __be64;

/* Maximum number of AIDs to use for STAs; must be 2007 or lower
 * (8802.11 limitation) */
#define MAX_AID_TABLE_SIZE 128

#define STA_HASH_SIZE 256
#define STA_HASH(sta) (sta[5])

#ifndef _packed_1_
#ifdef CONFIG_WIN32_DEFAULTS
#define _packed_1_
#else
#define _packed_1_  __attribute__((packed))
#endif
#endif

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif
#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif
#ifndef ETH_P_ALL
#define ETH_P_ALL 0x0003
#endif

#define OSS_LOG	/*表示采用OSS平台的日志打印；*/

#define RADIUS_CLIENT_MAX		32
extern struct radius_client_data * g_pstRadiusClient[RADIUS_CLIENT_MAX] ;

#ifdef _MSC_VER     /* pyy temp */
#define SIOCDEVPRIVATE	0x89F0	/* to 89FF */

#define UNIX_PATH_MAX	108
typedef unsigned short	sa_family_t;

struct sockaddr_un {
    sa_family_t sun_family;	/* AF_UNIX */
    char sun_path[UNIX_PATH_MAX];	/* pathname */
};


struct ifmap
{
    unsigned long mem_start;
    unsigned long mem_end;
    unsigned short base_addr;
    unsigned char irq;
    unsigned char dma;
    unsigned char port;
    /* 3 bytes spare */
};

typedef struct {
    unsigned int clock_rate; /* bits per second */
    unsigned int clock_type; /* internal, external, TX-internal etc. */
    unsigned short loopback;
} sync_serial_settings;          /* V.35, V.24, X.21 */

typedef struct {
    unsigned int clock_rate; /* bits per second */
    unsigned int clock_type; /* internal, external, TX-internal etc. */
    unsigned short loopback;
    unsigned int slot_map;
} te1_settings;                  /* T1, E1 */

typedef struct {
    unsigned short encoding;
    unsigned short parity;
} raw_hdlc_proto;

typedef struct {
    unsigned int t391;
    unsigned int t392;
    unsigned int n391;
    unsigned int n392;
    unsigned int n393;
    unsigned short lmi;
    unsigned short dce; /* 1 for DCE (network side) operation */
} fr_proto;

typedef struct {
    unsigned int dlci;
} fr_proto_pvc;          /* for creating/deleting FR PVCs */

typedef struct {
    unsigned int dlci;
    char master[IFNAMSIZ];	/* Name of master FRAD device */
}fr_proto_pvc_info;		/* for returning PVC information only */

typedef struct {
    unsigned int interval;
    unsigned int timeout;
} cisco_proto;

#ifndef __user
#define __user
#endif

struct if_settings
{
    unsigned int type;	/* Type of physical device or protocol */
    unsigned int size;	/* Size of the data allocated by the caller */
    union {
        /* {atm/eth/dsl}_settings anyone ? */
        raw_hdlc_proto		__user *raw_hdlc;
        cisco_proto		__user *cisco;
        fr_proto		__user *fr;
        fr_proto_pvc		__user *fr_pvc;
        fr_proto_pvc_info	__user *fr_pvc_info;

        /* interface settings */
        sync_serial_settings	__user *sync;
        te1_settings		__user *te1;
    } ifs_ifsu;
};


struct ifreq
{
#define IFHWADDRLEN	6
    union
    {
        char	ifrn_name[IFNAMSIZ];		/* if name, e.g. "en0" */
    } ifr_ifrn;

    union {
        struct	sockaddr ifru_addr;
        struct	sockaddr ifru_dstaddr;
        struct	sockaddr ifru_broadaddr;
        struct	sockaddr ifru_netmask;
        struct  sockaddr ifru_hwaddr;
        short	ifru_flags;
        int	ifru_ivalue;
        int	ifru_mtu;
        struct  ifmap ifru_map;
        char	ifru_slave[IFNAMSIZ];	/* Just fits the size */
        char	ifru_newname[IFNAMSIZ];
        void __user *	ifru_data;
        struct	if_settings ifru_settings;
    } ifr_ifru;
};

extern int inet_aton(const char *cp, u_int32_t * addr);

static inline int strcasecmp(const char *a, const char *b)
{
    int ca, cb;

    do {
        ca = *a++ & 0xff;
        cb = *b++ & 0xff;
        if (ca >= 'A' && ca <= 'Z')
            ca += 'a' - 'A';
        if (cb >= 'A' && cb <= 'Z')
            cb += 'a' - 'A';
    } while (ca == cb && ca != '\0');

    return ca - cb;
}

#include "wireless_copy.h"

#define random rand

#endif  /* endif #ifdef _MSC_VER */

#endif /* COMMON_H */
