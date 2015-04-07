#ifndef __WAPI_COMMON_H__
#define __WAPI_COMMON_H__

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;

struct l2_ethhdr {
	u_int8_t h_dest[ETH_ALEN];
	u_int8_t h_source[ETH_ALEN];
	u_int16_t h_proto;
} __packed;

#define ETH_P_WAPI 0x88b4

#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR " [%02x:%02x:%02x:%02x:%02x:%02x] "

#define BE_READ_2(p)					\
	((u_int16_t)					\
	 ((((const u_int8_t *)(p))[1]      ) |		\
	  (((const u_int8_t *)(p))[0] <<  8)))
#define BE_READ_4(p)					\
	((u_int32_t)					\
	 ((((const u_int8_t *)(p))[3]      ) |		\
	  (((const u_int8_t *)(p))[2] <<  8) |		\
	  (((const u_int8_t *)(p))[1] << 16) |		\
	  (((const u_int8_t *)(p))[0] << 24)))

#define BE_WRITE_2(p, v)		do {	\
	((u_int8_t *)(p))[0] = (((v) >> 8) & 0xff);\
	((u_int8_t *)(p))[1] = (((v) >> 0) & 0xff);\
}while(0)

#define BE_WRITE_4(p, v)		do {	\
	((u_int8_t *)(p))[0] = (((v) >> 24) & 0xff);\
	((u_int8_t *)(p))[1] = (((v) >> 16) & 0xff);\
	((u_int8_t *)(p))[2] = (((v) >> 8) & 0xff);\
	((u_int8_t *)(p))[3] = (((v) >> 0) & 0xff);\
}while(0)

#define os_malloc(size) malloc((size))
#define os_zalloc(size)	calloc(1, (size))
#define os_realloc(ptr, size) realloc(ptr, size)
#define os_memset(s, c, n)	memset(s, c, n)
#define os_memcpy(d, s, n) memcpy((d), (s), (n))
#define os_free(ptr) do{free(ptr); (ptr) = NULL;}while(0)
#define os_strncpy(d, s, n) strncpy((d), (s), (n))
#define os_memcmp(s1, s2, n) memcmp((s1), (s2), (n))
#define os_memmove(d, s, n) memmove((d), (s), (n))

#endif
