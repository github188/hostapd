/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  IOCTL功能头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DEVM_IOCTL_H
#define  _AC_DEVM_IOCTL_H

extern UINT32 ac_devm_ioctl_init (VOID);
extern UINT32 ac_devm_get_vap_bssid (VOID);

#ifdef _LINUX_

#include <sys/types.h>
#include <net/if.h>

#define __u32 __uint32_t
#define __s32  __int32_t
#define __u16 __uint16_t
#define __s16 __int16_t
#define __u8 __uint8_t
#ifndef __user
#define __user
#endif /* __user */

#define	IEEE80211_ADDR_LEN		6		/* size of 802.11 address */
#define	IEEE80211_KEYBUF_SIZE	16
#define	IEEE80211_MICBUF_SIZE	(8 + 8)		/* space for both tx+rx keys */
#define	IEEE80211_NWID_LEN			32
#define	IEEE80211_CHAN_BYTES	32
#define	IEEE80211_CHAN_MAX	255
#define	IEEE80211_RATE_MAXSIZE	15		/* max rates we'll handle */
#define	IEEE80211_AID_DEF		128

/***************************** VERSION *****************************/
/*
 * This constant is used to know the availability of the wireless
 * extensions and to know which version of wireless extensions it is
 * (there is some stuff that will be added in the future...)
 * I just plan to increment with each new version.
 */
#define WIRELESS_EXT	19

/*
 * Changes :
 *
 * V2 to V3
 * --------
 *	Alan Cox start some incompatibles changes. I've integrated a bit more.
 *	- Encryption renamed to Encode to avoid US regulation problems
 *	- Frequency changed from float to struct to avoid problems on old 386
 *
 * V3 to V4
 * --------
 *	- Add sensitivity
 *
 * V4 to V5
 * --------
 *	- Missing encoding definitions in range
 *	- Access points stuff
 *
 * V5 to V6
 * --------
 *	- 802.11 support (ESSID ioctls)
 *
 * V6 to V7
 * --------
 *	- define IW_ESSID_MAX_SIZE and IW_MAX_AP
 *
 * V7 to V8
 * --------
 *	- Changed my e-mail address
 *	- More 802.11 support (nickname, rate, rts, frag)
 *	- List index in frequencies
 *
 * V8 to V9
 * --------
 *	- Support for 'mode of operation' (ad-hoc, managed...)
 *	- Support for unicast and multicast power saving
 *	- Change encoding to support larger tokens (>64 bits)
 *	- Updated iw_params (disable, flags) and use it for NWID
 *	- Extracted iw_point from iwreq for clarity
 *
 * V9 to V10
 * ---------
 *	- Add PM capability to range structure
 *	- Add PM modifier : MAX/MIN/RELATIVE
 *	- Add encoding option : IW_ENCODE_NOKEY
 *	- Add TxPower ioctls (work like TxRate)
 *
 * V10 to V11
 * ----------
 *	- Add WE version in range (help backward/forward compatibility)
 *	- Add retry ioctls (work like PM)
 *
 * V11 to V12
 * ----------
 *	- Add SIOCSIWSTATS to get /proc/net/wireless programatically
 *	- Add DEV PRIVATE IOCTL to avoid collisions in SIOCDEVPRIVATE space
 *	- Add new statistics (frag, retry, beacon)
 *	- Add average quality (for user space calibration)
 *
 * V12 to V13
 * ----------
 *	- Document creation of new driver API.
 *	- Extract union iwreq_data from struct iwreq (for new driver API).
 *	- Rename SIOCSIWNAME as SIOCSIWCOMMIT
 *
 * V13 to V14
 * ----------
 *	- Wireless Events support : define struct iw_event
 *	- Define additional specific event numbers
 *	- Add "addr" and "param" fields in union iwreq_data
 *	- AP scanning stuff (SIOCSIWSCAN and friends)
 *
 * V14 to V15
 * ----------
 *	- Add IW_PRIV_TYPE_ADDR for struct sockaddr private arg
 *	- Make struct iw_freq signed (both m & e), add explicit padding
 *	- Add IWEVCUSTOM for driver specific event/scanning token
 *	- Add IW_MAX_GET_SPY for driver returning a lot of addresses
 *	- Add IW_TXPOW_RANGE for range of Tx Powers
 *	- Add IWEVREGISTERED & IWEVEXPIRED events for Access Points
 *	- Add IW_MODE_MONITOR for passive monitor
 *
 * V15 to V16
 * ----------
 *	- Increase the number of bitrates in iw_range to 32 (for 802.11g)
 *	- Increase the number of frequencies in iw_range to 32 (for 802.11b+a)
 *	- Reshuffle struct iw_range for increases, add filler
 *	- Increase IW_MAX_AP to 64 for driver returning a lot of addresses
 *	- Remove IW_MAX_GET_SPY because conflict with enhanced spy support
 *	- Add SIOCSIWTHRSPY/SIOCGIWTHRSPY and "struct iw_thrspy"
 *	- Add IW_ENCODE_TEMP and iw_range->encoding_login_index
 *
 * V16 to V17
 * ----------
 *	- Add flags to frequency -> auto/fixed
 *	- Document (struct iw_quality *)->updated, add new flags (INVALID)
 *	- Wireless Event capability in struct iw_range
 *	- Add support for relative TxPower (yick !)
 *
 * V17 to V18 (From Jouni Malinen <jkmaline@cc.hut.fi>)
 * ----------
 *	- Add support for WPA/WPA2
 *	- Add extended encoding configuration (SIOCSIWENCODEEXT and
 *	  SIOCGIWENCODEEXT)
 *	- Add SIOCSIWGENIE/SIOCGIWGENIE
 *	- Add SIOCSIWMLME
 *	- Add SIOCSIWPMKSA
 *	- Add struct iw_range bit field for supported encoding capabilities
 *	- Add optional scan request parameters for SIOCSIWSCAN
 *	- Add SIOCSIWAUTH/SIOCGIWAUTH for setting authentication and WPA
 *	  related parameters (extensible up to 4096 parameter values)
 *	- Add wireless events: IWEVGENIE, IWEVMICHAELMICFAILURE,
 *	  IWEVASSOCREQIE, IWEVASSOCRESPIE, IWEVPMKIDCAND
 *
 * V18 to V19
 * ----------
 *	- Remove (struct iw_point *)->pointer from events and streams
 *	- Remove header includes to help user space
 *	- Increase IW_ENCODING_TOKEN_MAX from 32 to 64
 *	- Add IW_QUAL_ALL_UPDATED and IW_QUAL_ALL_INVALID macros
 *	- Add explicit flag to tell stats are in dBm : IW_QUAL_DBM
 *	- Add IW_IOCTL_IDX() and IW_EVENT_IDX() macros
 */

/**************************** CONSTANTS ****************************/

/* -------------------------- IOCTL LIST -------------------------- */

/* bug222 */
#define IEEE80211_IOCTL_GETMAC (SIOCDEVPRIVATE+13)


/* Wireless Identification */
#define SIOCSIWCOMMIT	0x8B00		/* Commit pending changes to driver */
#define SIOCGIWNAME	0x8B01		/* get name == wireless protocol */
/* SIOCGIWNAME is used to verify the presence of Wireless Extensions.
 * Common values : "IEEE 802.11-DS", "IEEE 802.11-FH", "IEEE 802.11b"...
 * Don't put the name of your driver there, it's useless. */

/* Basic operations */
#define SIOCSIWNWID	0x8B02		/* set network id (pre-802.11) */
#define SIOCGIWNWID	0x8B03		/* get network id (the cell) */
#define SIOCSIWFREQ	0x8B04		/* set channel/frequency (Hz) */
#define SIOCGIWFREQ	0x8B05		/* get channel/frequency (Hz) */
#define SIOCSIWMODE	0x8B06		/* set operation mode */
#define SIOCGIWMODE	0x8B07		/* get operation mode */
#define SIOCSIWSENS	0x8B08		/* set sensitivity (dBm) */
#define SIOCGIWSENS	0x8B09		/* get sensitivity (dBm) */

/* Informative stuff */
#define SIOCSIWRANGE	0x8B0A		/* Unused */
#define SIOCGIWRANGE	0x8B0B		/* Get range of parameters */
#define SIOCSIWPRIV	0x8B0C		/* Unused */
#define SIOCGIWPRIV	0x8B0D		/* get private ioctl interface info */
#define SIOCSIWSTATS	0x8B0E		/* Unused */
#define SIOCGIWSTATS	0x8B0F		/* Get /proc/net/wireless stats */
/* SIOCGIWSTATS is strictly used between user space and the kernel, and
 * is never passed to the driver (i.e. the driver will never see it). */

/* Spy support (statistics per MAC address - used for Mobile IP support) */
#define SIOCSIWSPY	0x8B10		/* set spy addresses */
#define SIOCGIWSPY	0x8B11		/* get spy info (quality of link) */
#define SIOCSIWTHRSPY	0x8B12		/* set spy threshold (spy event) */
#define SIOCGIWTHRSPY	0x8B13		/* get spy threshold */

/* Access Point manipulation */
#define SIOCSIWAP	0x8B14		/* set access point MAC addresses */
#define SIOCGIWAP	0x8B15		/* get access point MAC addresses */
#define SIOCGIWAPLIST	0x8B17		/* Deprecated in favor of scanning */
#define SIOCSIWSCAN	0x8B18		/* trigger scanning (list cells) */
#define SIOCGIWSCAN	0x8B19		/* get scanning results */

/* 802.11 specific support */
#define SIOCSIWESSID	0x8B1A		/* set ESSID (network name) */
#define SIOCGIWESSID	0x8B1B		/* get ESSID */
#define SIOCSIWNICKN	0x8B1C		/* set node name/nickname */
#define SIOCGIWNICKN	0x8B1D		/* get node name/nickname */
/* As the ESSID and NICKN are strings up to 32 bytes long, it doesn't fit
 * within the 'iwreq' structure, so we need to use the 'data' member to
 * point to a string in user space, like it is done for RANGE... */

/* Other parameters useful in 802.11 and some other devices */
#define SIOCSIWRATE	0x8B20		/* set default bit rate (bps) */
#define SIOCGIWRATE	0x8B21		/* get default bit rate (bps) */
#define SIOCSIWRTS	0x8B22		/* set RTS/CTS threshold (bytes) */
#define SIOCGIWRTS	0x8B23		/* get RTS/CTS threshold (bytes) */
#define SIOCSIWFRAG	0x8B24		/* set fragmentation thr (bytes) */
#define SIOCGIWFRAG	0x8B25		/* get fragmentation thr (bytes) */
#define SIOCSIWTXPOW	0x8B26		/* set transmit power (dBm) */
#define SIOCGIWTXPOW	0x8B27		/* get transmit power (dBm) */
#define SIOCSIWRETRY	0x8B28		/* set retry limits and lifetime */
#define SIOCGIWRETRY	0x8B29		/* get retry limits and lifetime */

/* Encoding stuff (scrambling, hardware security, WEP...) */
#define SIOCSIWENCODE	0x8B2A		/* set encoding token & mode */
#define SIOCGIWENCODE	0x8B2B		/* get encoding token & mode */
/* Power saving stuff (power management, unicast and multicast) */
#define SIOCSIWPOWER	0x8B2C		/* set Power Management settings */
#define SIOCGIWPOWER	0x8B2D		/* get Power Management settings */

/* WPA : Generic IEEE 802.11 informatiom element (e.g., for WPA/RSN/WMM).
 * This ioctl uses struct iw_point and data buffer that includes IE id and len
 * fields. More than one IE may be included in the request. Setting the generic
 * IE to empty buffer (len=0) removes the generic IE from the driver. Drivers
 * are allowed to generate their own WPA/RSN IEs, but in these cases, drivers
 * are required to report the used IE as a wireless event, e.g., when
 * associating with an AP. */
#define SIOCSIWGENIE	0x8B30		/* set generic IE */
#define SIOCGIWGENIE	0x8B31		/* get generic IE */

/* WPA : IEEE 802.11 MLME requests */
#define SIOCSIWMLME	0x8B16		/* request MLME operation; uses
					 * struct iw_mlme */
/* WPA : Authentication mode parameters */
#define SIOCSIWAUTH	0x8B32		/* set authentication mode params */
#define SIOCGIWAUTH	0x8B33		/* get authentication mode params */

/* WPA : Extended version of encoding configuration */
#define SIOCSIWENCODEEXT 0x8B34		/* set encoding token & mode */
#define SIOCGIWENCODEEXT 0x8B35		/* get encoding token & mode */

/* WPA2 : PMKSA cache management */
#define SIOCSIWPMKSA	0x8B36		/* PMKSA cache operation */

/* -------------------- DEV PRIVATE IOCTL LIST -------------------- */

/* These 32 ioctl are wireless device private, for 16 commands.
 * Each driver is free to use them for whatever purpose it chooses,
 * however the driver *must* export the description of those ioctls
 * with SIOCGIWPRIV and *must* use arguments as defined below.
 * If you don't follow those rules, DaveM is going to hate you (reason :
 * it make mixed 32/64bit operation impossible).
 */
#define SIOCIWFIRSTPRIV	0x8BE0
#define SIOCIWLASTPRIV	0x8BFF
/* Previously, we were using SIOCDEVPRIVATE, but we now have our
 * separate range because of collisions with other tools such as
 * 'mii-tool'.
 * We now have 32 commands, so a bit more space ;-).
 * Also, all 'odd' commands are only usable by root and don't return the
 * content of ifr/iwr to user (but you are not obliged to use the set/get
 * convention, just use every other two command). More details in iwpriv.c.
 * And I repeat : you are not forced to use them with iwpriv, but you
 * must be compliant with it.
 */

/* ------------------------- IOCTL STUFF ------------------------- */

/* The first and the last (range) */
#define SIOCIWFIRST	0x8B00
#define SIOCIWLAST	SIOCIWLASTPRIV		/* 0x8BFF */
#define IW_IOCTL_IDX(cmd)	((cmd) - SIOCIWFIRST)

/* Even : get (world access), odd : set (root access) */
#define IW_IS_SET(cmd)	(!((cmd) & 0x1))
#define IW_IS_GET(cmd)	((cmd) & 0x1)

/* ----------------------- WIRELESS EVENTS ----------------------- */
/* Those are *NOT* ioctls, do not issue request on them !!! */
/* Most events use the same identifier as ioctl requests */

#define IWEVTXDROP	0x8C00		/* Packet dropped to excessive retry */
#define IWEVQUAL	0x8C01		/* Quality part of statistics (scan) */
#define IWEVCUSTOM	0x8C02		/* Driver specific ascii string */
#define IWEVREGISTERED	0x8C03		/* Discovered a new node (AP mode) */
#define IWEVEXPIRED	0x8C04		/* Expired a node (AP mode) */
#define IWEVGENIE	0x8C05		/* Generic IE (WPA, RSN, WMM, ..)
					 * (scan results); This includes id and
					 * length fields. One IWEVGENIE may
					 * contain more than one IE. Scan
					 * results may contain one or more
					 * IWEVGENIE events. */
#define IWEVMICHAELMICFAILURE 0x8C06	/* Michael MIC failure
					 * (struct iw_michaelmicfailure)
					 */
#define IWEVASSOCREQIE	0x8C07		/* IEs used in (Re)Association Request.
					 * The data includes id and length
					 * fields and may contain more than one
					 * IE. This event is required in
					 * Managed mode if the driver
					 * generates its own WPA/RSN IE. This
					 * should be sent just before
					 * IWEVREGISTERED event for the
					 * association. */
#define IWEVASSOCRESPIE	0x8C08		/* IEs used in (Re)Association
					 * Response. The data includes id and
					 * length fields and may contain more
					 * than one IE. This may be sent
					 * between IWEVASSOCREQIE and
					 * IWEVREGISTERED events for the
					 * association. */
#define IWEVPMKIDCAND	0x8C09		/* PMKID candidate for RSN
					 * pre-authentication
					 * (struct iw_pmkid_cand) */

#define IWEVFIRST	0x8C00
#define IW_EVENT_IDX(cmd)	((cmd) - IWEVFIRST)

/* ------------------------- PRIVATE INFO ------------------------- */
/*
 * The following is used with SIOCGIWPRIV. It allow a driver to define
 * the interface (name, type of data) for its private ioctl.
 * Privates ioctl are SIOCIWFIRSTPRIV -> SIOCIWLASTPRIV
 */

#define IW_PRIV_TYPE_MASK	0x7000	/* Type of arguments */
#define IW_PRIV_TYPE_NONE	0x0000
#define IW_PRIV_TYPE_BYTE	0x1000	/* Char as number */
#define IW_PRIV_TYPE_CHAR	0x2000	/* Char as character */
#define IW_PRIV_TYPE_INT	0x4000	/* 32 bits int */
#define IW_PRIV_TYPE_FLOAT	0x5000	/* struct iw_freq */
#define IW_PRIV_TYPE_ADDR	0x6000	/* struct sockaddr */

#define IW_PRIV_SIZE_FIXED	0x0800	/* Variable or fixed number of args */

#define IW_PRIV_SIZE_MASK	0x07FF	/* Max number of those args */

/*
 * Note : if the number of args is fixed and the size < 16 octets,
 * instead of passing a pointer we will put args in the iwreq struct...
 */

/* ----------------------- OTHER CONSTANTS ----------------------- */

/* Maximum frequencies in the range struct */
#define IW_MAX_FREQUENCIES	32
/* Note : if you have something like 80 frequencies,
 * don't increase this constant and don't fill the frequency list.
 * The user will be able to set by channel anyway... */

/* Maximum bit rates in the range struct */
#define IW_MAX_BITRATES		32

/* Maximum tx powers in the range struct */
#define IW_MAX_TXPOWER		8
/* Note : if you more than 8 TXPowers, just set the max and min or
 * a few of them in the struct iw_range. */

/* Maximum of address that you may set with SPY */
#define IW_MAX_SPY		8

/* Maximum of address that you may get in the
   list of access points in range */
#define IW_MAX_AP		64

/* Maximum size of the ESSID and NICKN strings */
#define IW_ESSID_MAX_SIZE	32

/* Modes of operation */
#define IW_MODE_AUTO	0	/* Let the driver decides */
#define IW_MODE_ADHOC	1	/* Single cell network */
#define IW_MODE_INFRA	2	/* Multi cell network, roaming, ... */
#define IW_MODE_MASTER	3	/* Synchronisation master or Access Point */
#define IW_MODE_REPEAT	4	/* Wireless Repeater (forwarder) */
#define IW_MODE_SECOND	5	/* Secondary master/repeater (backup) */
#define IW_MODE_MONITOR	6	/* Passive monitor (listen only) */

/* Statistics flags (bitmask in updated) */
#define IW_QUAL_QUAL_UPDATED	0x01	/* Value was updated since last read */
#define IW_QUAL_LEVEL_UPDATED	0x02
#define IW_QUAL_NOISE_UPDATED	0x04
#define IW_QUAL_ALL_UPDATED	0x07
#define IW_QUAL_DBM		0x08	/* Level + Noise are dBm */
#define IW_QUAL_QUAL_INVALID	0x10	/* Driver doesn't provide value */
#define IW_QUAL_LEVEL_INVALID	0x20
#define IW_QUAL_NOISE_INVALID	0x40
#define IW_QUAL_ALL_INVALID	0x70

/* Frequency flags */
#define IW_FREQ_AUTO		0x00	/* Let the driver decides */
#define IW_FREQ_FIXED		0x01	/* Force a specific value */

/* Maximum number of size of encoding token available
 * they are listed in the range structure */
#define IW_MAX_ENCODING_SIZES	8

/* Maximum size of the encoding token in bytes */
#define IW_ENCODING_TOKEN_MAX	64	/* 512 bits (for now) */

/* Flags for encoding (along with the token) */
#define IW_ENCODE_INDEX		0x00FF	/* Token index (if needed) */
#define IW_ENCODE_FLAGS		0xFF00	/* Flags defined below */
#define IW_ENCODE_MODE		0xF000	/* Modes defined below */
#define IW_ENCODE_DISABLED	0x8000	/* Encoding disabled */
#define IW_ENCODE_ENABLED	0x0000	/* Encoding enabled */
#define IW_ENCODE_RESTRICTED	0x4000	/* Refuse non-encoded packets */
#define IW_ENCODE_OPEN		0x2000	/* Accept non-encoded packets */
#define IW_ENCODE_NOKEY		0x0800  /* Key is write only, so not present */
#define IW_ENCODE_TEMP		0x0400  /* Temporary key */

/* Power management flags available (along with the value, if any) */
#define IW_POWER_ON		0x0000	/* No details... */
#define IW_POWER_TYPE		0xF000	/* Type of parameter */
#define IW_POWER_PERIOD		0x1000	/* Value is a period/duration of  */
#define IW_POWER_TIMEOUT	0x2000	/* Value is a timeout (to go asleep) */
#define IW_POWER_MODE		0x0F00	/* Power Management mode */
#define IW_POWER_UNICAST_R	0x0100	/* Receive only unicast messages */
#define IW_POWER_MULTICAST_R	0x0200	/* Receive only multicast messages */
#define IW_POWER_ALL_R		0x0300	/* Receive all messages though PM */
#define IW_POWER_FORCE_S	0x0400	/* Force PM procedure for sending unicast */
#define IW_POWER_REPEATER	0x0800	/* Repeat broadcast messages in PM period */
#define IW_POWER_MODIFIER	0x000F	/* Modify a parameter */
#define IW_POWER_MIN		0x0001	/* Value is a minimum  */
#define IW_POWER_MAX		0x0002	/* Value is a maximum */
#define IW_POWER_RELATIVE	0x0004	/* Value is not in seconds/ms/us */

/* Transmit Power flags available */
#define IW_TXPOW_TYPE		0x00FF	/* Type of value */
#define IW_TXPOW_DBM		0x0000	/* Value is in dBm */
#define IW_TXPOW_MWATT		0x0001	/* Value is in mW */
#define IW_TXPOW_RELATIVE	0x0002	/* Value is in arbitrary units */
#define IW_TXPOW_RANGE		0x1000	/* Range of value between min/max */

/* Retry limits and lifetime flags available */
#define IW_RETRY_ON		0x0000	/* No details... */
#define IW_RETRY_TYPE		0xF000	/* Type of parameter */
#define IW_RETRY_LIMIT		0x1000	/* Maximum number of retries*/
#define IW_RETRY_LIFETIME	0x2000	/* Maximum duration of retries in us */
#define IW_RETRY_MODIFIER	0x000F	/* Modify a parameter */
#define IW_RETRY_MIN		0x0001	/* Value is a minimum  */
#define IW_RETRY_MAX		0x0002	/* Value is a maximum */
#define IW_RETRY_RELATIVE	0x0004	/* Value is not in seconds/ms/us */

/* Scanning request flags */
#define IW_SCAN_DEFAULT		0x0000	/* Default scan of the driver */
#define IW_SCAN_ALL_ESSID	0x0001	/* Scan all ESSIDs */
#define IW_SCAN_THIS_ESSID	0x0002	/* Scan only this ESSID */
#define IW_SCAN_ALL_FREQ	0x0004	/* Scan all Frequencies */
#define IW_SCAN_THIS_FREQ	0x0008	/* Scan only this Frequency */
#define IW_SCAN_ALL_MODE	0x0010	/* Scan all Modes */
#define IW_SCAN_THIS_MODE	0x0020	/* Scan only this Mode */
#define IW_SCAN_ALL_RATE	0x0040	/* Scan all Bit-Rates */
#define IW_SCAN_THIS_RATE	0x0080	/* Scan only this Bit-Rate */
/* struct iw_scan_req scan_type */
#define IW_SCAN_TYPE_ACTIVE 0
#define IW_SCAN_TYPE_PASSIVE 1
/* Maximum size of returned data */
#define IW_SCAN_MAX_DATA	4096	/* In bytes */

/* Max number of char in custom event - use multiple of them if needed */
#define IW_CUSTOM_MAX		256	/* In bytes */

/* Generic information element */
#define IW_GENERIC_IE_MAX	1024

/* MLME requests (SIOCSIWMLME / struct iw_mlme) */
#define IW_MLME_DEAUTH		0
#define IW_MLME_DISASSOC	1

/* SIOCSIWAUTH/SIOCGIWAUTH struct iw_param flags */
#define IW_AUTH_INDEX		0x0FFF
#define IW_AUTH_FLAGS		0xF000
/* SIOCSIWAUTH/SIOCGIWAUTH parameters (0 .. 4095)
 * (IW_AUTH_INDEX mask in struct iw_param flags; this is the index of the
 * parameter that is being set/get to; value will be read/written to
 * struct iw_param value field) */
#define IW_AUTH_WPA_VERSION		0
#define IW_AUTH_CIPHER_PAIRWISE		1
#define IW_AUTH_CIPHER_GROUP		2
#define IW_AUTH_KEY_MGMT		3
#define IW_AUTH_TKIP_COUNTERMEASURES	4
#define IW_AUTH_DROP_UNENCRYPTED	5
#define IW_AUTH_80211_AUTH_ALG		6
#define IW_AUTH_WPA_ENABLED		7
#define IW_AUTH_RX_UNENCRYPTED_EAPOL	8
#define IW_AUTH_ROAMING_CONTROL		9
#define IW_AUTH_PRIVACY_INVOKED		10

/* IW_AUTH_WPA_VERSION values (bit field) */
#define IW_AUTH_WPA_VERSION_DISABLED	0x00000001
#define IW_AUTH_WPA_VERSION_WPA		0x00000002
#define IW_AUTH_WPA_VERSION_WPA2	0x00000004

/* IW_AUTH_PAIRWISE_CIPHER and IW_AUTH_GROUP_CIPHER values (bit field) */
#define IW_AUTH_CIPHER_NONE	0x00000001
#define IW_AUTH_CIPHER_WEP40	0x00000002
#define IW_AUTH_CIPHER_TKIP	0x00000004
#define IW_AUTH_CIPHER_CCMP	0x00000008
#define IW_AUTH_CIPHER_WEP104	0x00000010

/* IW_AUTH_KEY_MGMT values (bit field) */
#define IW_AUTH_KEY_MGMT_802_1X	1
#define IW_AUTH_KEY_MGMT_PSK	2

/* IW_AUTH_80211_AUTH_ALG values (bit field) */
#define IW_AUTH_ALG_OPEN_SYSTEM	0x00000001
#define IW_AUTH_ALG_SHARED_KEY	0x00000002
#define IW_AUTH_ALG_LEAP	0x00000004

/* IW_AUTH_ROAMING_CONTROL values */
#define IW_AUTH_ROAMING_ENABLE	0	/* driver/firmware based roaming */
#define IW_AUTH_ROAMING_DISABLE	1	/* user space program used for roaming
					 * control */

/* SIOCSIWENCODEEXT definitions */
#define IW_ENCODE_SEQ_MAX_SIZE	8
/* struct iw_encode_ext ->alg */
#define IW_ENCODE_ALG_NONE	0
#define IW_ENCODE_ALG_WEP	1
#define IW_ENCODE_ALG_TKIP	2
#define IW_ENCODE_ALG_CCMP	3
/* struct iw_encode_ext ->ext_flags */
#define IW_ENCODE_EXT_TX_SEQ_VALID	0x00000001
#define IW_ENCODE_EXT_RX_SEQ_VALID	0x00000002
#define IW_ENCODE_EXT_GROUP_KEY		0x00000004
#define IW_ENCODE_EXT_SET_TX_KEY	0x00000008

/* IWEVMICHAELMICFAILURE : struct iw_michaelmicfailure ->flags */
#define IW_MICFAILURE_KEY_ID	0x00000003 /* Key ID 0..3 */
#define IW_MICFAILURE_GROUP	0x00000004
#define IW_MICFAILURE_PAIRWISE	0x00000008
#define IW_MICFAILURE_STAKEY	0x00000010
#define IW_MICFAILURE_COUNT	0x00000060 /* 1 or 2 (0 = count not supported)
					    */

/* Bit field values for enc_capa in struct iw_range */
#define IW_ENC_CAPA_WPA		0x00000001
#define IW_ENC_CAPA_WPA2	0x00000002
#define IW_ENC_CAPA_CIPHER_TKIP	0x00000004
#define IW_ENC_CAPA_CIPHER_CCMP	0x00000008

/* Event capability macros - in (struct iw_range *)->event_capa
 * Because we have more than 32 possible events, we use an array of
 * 32 bit bitmasks. Note : 32 bits = 0x20 = 2^5. */
#define IW_EVENT_CAPA_BASE(cmd)		((cmd >= SIOCIWFIRSTPRIV) ? \
					 (cmd - SIOCIWFIRSTPRIV + 0x60) : \
					 (cmd - SIOCSIWCOMMIT))
#define IW_EVENT_CAPA_INDEX(cmd)	(IW_EVENT_CAPA_BASE(cmd) >> 5)
#define IW_EVENT_CAPA_MASK(cmd)		(1 << (IW_EVENT_CAPA_BASE(cmd) & 0x1F))
/* Event capability constants - event autogenerated by the kernel
 * This list is valid for most 802.11 devices, customise as needed... */
#define IW_EVENT_CAPA_K_0	(IW_EVENT_CAPA_MASK(0x8B04) | \
				 IW_EVENT_CAPA_MASK(0x8B06) | \
				 IW_EVENT_CAPA_MASK(0x8B1A))
#define IW_EVENT_CAPA_K_1	(IW_EVENT_CAPA_MASK(0x8B2A))
/* "Easy" macro to set events in iw_range (less efficient) */
#define IW_EVENT_CAPA_SET(event_capa, cmd) (event_capa[IW_EVENT_CAPA_INDEX(cmd)] |= IW_EVENT_CAPA_MASK(cmd))
#define IW_EVENT_CAPA_SET_KERNEL(event_capa) {event_capa[0] |= IW_EVENT_CAPA_K_0; event_capa[1] |= IW_EVENT_CAPA_K_1; }


/****************************** TYPES ******************************/

/* --------------------------- SUBTYPES --------------------------- */
/*
 *	Generic format for most parameters that fit in an int
 */
struct	iw_param
{
  __s32		value;		/* The value of the parameter itself */
  __u8		fixed;		/* Hardware should not use auto select */
  __u8		disabled;	/* Disable the feature */
  __u16		flags;		/* Various specifc flags (if any) */
};

/*
 *	For all data larger than 16 octets, we need to use a
 *	pointer to memory allocated in user space.
 */
struct	iw_point
{
  void __user	*pointer;	/* Pointer to the data  (in user space) */
  __u16		length;		/* number of fields or size in bytes */
  __u16		flags;		/* Optional params */
};

/*
 *	A frequency
 *	For numbers lower than 10^9, we encode the number in 'm' and
 *	set 'e' to 0
 *	For number greater than 10^9, we divide it by the lowest power
 *	of 10 to get 'm' lower than 10^9, with 'm'= f / (10^'e')...
 *	The power of 10 is in 'e', the result of the division is in 'm'.
 */
struct	iw_freq
{
	__s32		m;		/* Mantissa */
	__s16		e;		/* Exponent */
	__u8		i;		/* List index (when in range struct) */
	__u8		flags;		/* Flags (fixed/auto) */
};

/*
 *	Quality of the link
 */
struct	iw_quality
{
	__u8		qual;		/* link quality (%retries, SNR,
					   %missed beacons or better...) */
	__u8		level;		/* signal level (dBm) */
	__u8		noise;		/* noise level (dBm) */
	__u8		updated;	/* Flags to know if updated */
};

/*
 *	Packet discarded in the wireless adapter due to
 *	"wireless" specific problems...
 *	Note : the list of counter and statistics in net_device_stats
 *	is already pretty exhaustive, and you should use that first.
 *	This is only additional stats...
 */
struct	iw_discarded
{
	__u32		nwid;		/* Rx : Wrong nwid/essid */
	__u32		code;		/* Rx : Unable to code/decode (WEP) */
	__u32		fragment;	/* Rx : Can't perform MAC reassembly */
	__u32		retries;	/* Tx : Max MAC retries num reached */
	__u32		misc;		/* Others cases */
};

/*
 *	Packet/Time period missed in the wireless adapter due to
 *	"wireless" specific problems...
 */
struct	iw_missed
{
	__u32		beacon;		/* Missed beacons/superframe */
};

/*
 *	Quality range (for spy threshold)
 */
struct	iw_thrspy
{
	struct sockaddr		addr;		/* Source address (hw/mac) */
	struct iw_quality	qual;		/* Quality of the link */
	struct iw_quality	low;		/* Low threshold */
	struct iw_quality	high;		/* High threshold */
};

/*
 *	Optional data for scan request
 *
 *	Note: these optional parameters are controlling parameters for the
 *	scanning behavior, these do not apply to getting scan results
 *	(SIOCGIWSCAN). Drivers are expected to keep a local BSS table and
 *	provide a merged results with all BSSes even if the previous scan
 *	request limited scanning to a subset, e.g., by specifying an SSID.
 *	Especially, scan results are required to include an entry for the
 *	current BSS if the driver is in Managed mode and associated with an AP.
 */
struct	iw_scan_req
{
	__u8		scan_type; /* IW_SCAN_TYPE_{ACTIVE,PASSIVE} */
	__u8		essid_len;
	__u8		num_channels; /* num entries in channel_list;
				       * 0 = scan all allowed channels */
	__u8		flags; /* reserved as padding; use zero, this may
				* be used in the future for adding flags
				* to request different scan behavior */
	struct sockaddr	bssid; /* ff:ff:ff:ff:ff:ff for broadcast BSSID or
				* individual address of a specific BSS */

	/*
	 * Use this ESSID if IW_SCAN_THIS_ESSID flag is used instead of using
	 * the current ESSID. This allows scan requests for specific ESSID
	 * without having to change the current ESSID and potentially breaking
	 * the current association.
	 */
	__u8		essid[IW_ESSID_MAX_SIZE];

	/*
	 * Optional parameters for changing the default scanning behavior.
	 * These are based on the MLME-SCAN.request from IEEE Std 802.11.
	 * TU is 1.024 ms. If these are set to 0, driver is expected to use
	 * reasonable default values. min_channel_time defines the time that
	 * will be used to wait for the first reply on each channel. If no
	 * replies are received, next channel will be scanned after this. If
	 * replies are received, total time waited on the channel is defined by
	 * max_channel_time.
	 */
	__u32		min_channel_time; /* in TU */
	__u32		max_channel_time; /* in TU */

	struct iw_freq	channel_list[IW_MAX_FREQUENCIES];
};

/* ------------------------- WPA SUPPORT ------------------------- */

/*
 *	Extended data structure for get/set encoding (this is used with
 *	SIOCSIWENCODEEXT/SIOCGIWENCODEEXT. struct iw_point and IW_ENCODE_*
 *	flags are used in the same way as with SIOCSIWENCODE/SIOCGIWENCODE and
 *	only the data contents changes (key data -> this structure, including
 *	key data).
 *
 *	If the new key is the first group key, it will be set as the default
 *	TX key. Otherwise, default TX key index is only changed if
 *	IW_ENCODE_EXT_SET_TX_KEY flag is set.
 *
 *	Key will be changed with SIOCSIWENCODEEXT in all cases except for
 *	special "change TX key index" operation which is indicated by setting
 *	key_len = 0 and ext_flags |= IW_ENCODE_EXT_SET_TX_KEY.
 *
 *	tx_seq/rx_seq are only used when respective
 *	IW_ENCODE_EXT_{TX,RX}_SEQ_VALID flag is set in ext_flags. Normal
 *	TKIP/CCMP operation is to set RX seq with SIOCSIWENCODEEXT and start
 *	TX seq from zero whenever key is changed. SIOCGIWENCODEEXT is normally
 *	used only by an Authenticator (AP or an IBSS station) to get the
 *	current TX sequence number. Using TX_SEQ_VALID for SIOCSIWENCODEEXT and
 *	RX_SEQ_VALID for SIOCGIWENCODEEXT are optional, but can be useful for
 *	debugging/testing.
 */
struct	iw_encode_ext
{
	__u32		ext_flags; /* IW_ENCODE_EXT_* */
	__u8		tx_seq[IW_ENCODE_SEQ_MAX_SIZE]; /* LSB first */
	__u8		rx_seq[IW_ENCODE_SEQ_MAX_SIZE]; /* LSB first */
	struct sockaddr	addr; /* ff:ff:ff:ff:ff:ff for broadcast/multicast
			       * (group) keys or unicast address for
			       * individual keys */
	__u16		alg; /* IW_ENCODE_ALG_* */
	__u16		key_len;
	__u8		key[0];
};

/* SIOCSIWMLME data */
struct	iw_mlme
{
	__u16		cmd; /* IW_MLME_* */
	__u16		reason_code;
	struct sockaddr	addr;
};

/* SIOCSIWPMKSA data */
#define IW_PMKSA_ADD		1
#define IW_PMKSA_REMOVE		2
#define IW_PMKSA_FLUSH		3

#define IW_PMKID_LEN	16

struct	iw_pmksa
{
	__u32		cmd; /* IW_PMKSA_* */
	struct sockaddr	bssid;
	__u8		pmkid[IW_PMKID_LEN];
};

/* IWEVMICHAELMICFAILURE data */
struct	iw_michaelmicfailure
{
	__u32		flags;
	struct sockaddr	src_addr;
	__u8		tsc[IW_ENCODE_SEQ_MAX_SIZE]; /* LSB first */
};

/* IWEVPMKIDCAND data */
#define IW_PMKID_CAND_PREAUTH	0x00000001 /* RNS pre-authentication enabled */
struct	iw_pmkid_cand
{
	__u32		flags; /* IW_PMKID_CAND_* */
	__u32		index; /* the smaller the index, the higher the
				* priority */
	struct sockaddr	bssid;
};

/* ------------------------ WIRELESS STATS ------------------------ */
/*
 * Wireless statistics (used for /proc/net/wireless)
 */
struct	iw_statistics
{
	__u16		status;		/* Status
					 * - device dependent for now */

	struct iw_quality	qual;		/* Quality of the link
						 * (instant/mean/max) */
	struct iw_discarded	discard;	/* Packet discarded counts */
	struct iw_missed	miss;		/* Packet missed counts */
};

/* ------------------------ IOCTL REQUEST ------------------------ */
/*
 * This structure defines the payload of an ioctl, and is used 
 * below.
 *
 * Note that this structure should fit on the memory footprint
 * of iwreq (which is the same as ifreq), which mean a max size of
 * 16 octets = 128 bits. Warning, pointers might be 64 bits wide...
 * You should check this when increasing the structures defined
 * above in this file...
 */
union	iwreq_data
{
	/* Config - generic */
	char		name[IFNAMSIZ];
	/* Name : used to verify the presence of  wireless extensions.
	 * Name of the protocol/provider... */

	struct iw_point	essid;		/* Extended network name */
	struct iw_param	nwid;		/* network id (or domain - the cell) */
	struct iw_freq	freq;		/* frequency or channel :
					 * 0-1000 = channel
					 * > 1000 = frequency in Hz */

	struct iw_param	sens;		/* signal level threshold */
	struct iw_param	bitrate;	/* default bit rate */
	struct iw_param	txpower;	/* default transmit power */
	struct iw_param	rts;		/* RTS threshold threshold */
	struct iw_param	frag;		/* Fragmentation threshold */
	__u32		mode;		/* Operation mode */
	struct iw_param	retry;		/* Retry limits & lifetime */

	struct iw_point	encoding;	/* Encoding stuff : tokens */
	struct iw_param	power;		/* PM duration/timeout */
	struct iw_quality qual;		/* Quality part of statistics */

	struct sockaddr	ap_addr;	/* Access point address */
	struct sockaddr	addr;		/* Destination address (hw/mac) */

	struct iw_param	param;		/* Other small parameters */
	struct iw_point	data;		/* Other large parameters */
};

/*
 * The structure to exchange data for ioctl.
 * This structure is the same as 'struct ifreq', but (re)defined for
 * convenience...
 * Do I need to remind you about structure size (32 octets) ?
 */
struct	iwreq 
{
	union
	{
		char	ifrn_name[IFNAMSIZ];	/* if name, e.g. "eth0" */
	} ifr_ifrn;

	/* Data part (defined just above) */
	union	iwreq_data	u;
};

/* -------------------------- IOCTL DATA -------------------------- */
/*
 *	For those ioctl which want to exchange mode data that what could
 *	fit in the above structure...
 */

/*
 *	Range of parameters
 */

struct	iw_range
{
	/* Informative stuff (to choose between different interface) */
	__u32		throughput;	/* To give an idea... */
	/* In theory this value should be the maximum benchmarked
	 * TCP/IP throughput, because with most of these devices the
	 * bit rate is meaningless (overhead an co) to estimate how
	 * fast the connection will go and pick the fastest one.
	 * I suggest people to play with Netperf or any benchmark...
	 */

	/* NWID (or domain id) */
	__u32		min_nwid;	/* Minimal NWID we are able to set */
	__u32		max_nwid;	/* Maximal NWID we are able to set */

	/* Old Frequency (backward compat - moved lower ) */
	__u16		old_num_channels;
	__u8		old_num_frequency;

	/* Wireless event capability bitmasks */
	__u32		event_capa[6];

	/* signal level threshold range */
	__s32		sensitivity;

	/* Quality of link & SNR stuff */
	/* Quality range (link, level, noise)
	 * If the quality is absolute, it will be in the range [0 ; max_qual],
	 * if the quality is dBm, it will be in the range [max_qual ; 0].
	 * Don't forget that we use 8 bit arithmetics... */
	struct iw_quality	max_qual;	/* Quality of the link */
	/* This should contain the average/typical values of the quality
	 * indicator. This should be the threshold between a "good" and
	 * a "bad" link (example : monitor going from green to orange).
	 * Currently, user space apps like quality monitors don't have any
	 * way to calibrate the measurement. With this, they can split
	 * the range between 0 and max_qual in different quality level
	 * (using a geometric subdivision centered on the average).
	 * I expect that people doing the user space apps will feedback
	 * us on which value we need to put in each driver... */
	struct iw_quality	avg_qual;	/* Quality of the link */

	/* Rates */
	__u8		num_bitrates;	/* Number of entries in the list */
	__s32		bitrate[IW_MAX_BITRATES];	/* list, in bps */

	/* RTS threshold */
	__s32		min_rts;	/* Minimal RTS threshold */
	__s32		max_rts;	/* Maximal RTS threshold */

	/* Frag threshold */
	__s32		min_frag;	/* Minimal frag threshold */
	__s32		max_frag;	/* Maximal frag threshold */

	/* Power Management duration & timeout */
	__s32		min_pmp;	/* Minimal PM period */
	__s32		max_pmp;	/* Maximal PM period */
	__s32		min_pmt;	/* Minimal PM timeout */
	__s32		max_pmt;	/* Maximal PM timeout */
	__u16		pmp_flags;	/* How to decode max/min PM period */
	__u16		pmt_flags;	/* How to decode max/min PM timeout */
	__u16		pm_capa;	/* What PM options are supported */

	/* Encoder stuff */
	__u16	encoding_size[IW_MAX_ENCODING_SIZES];	/* Different token sizes */
	__u8	num_encoding_sizes;	/* Number of entry in the list */
	__u8	max_encoding_tokens;	/* Max number of tokens */
	/* For drivers that need a "login/passwd" form */
	__u8	encoding_login_index;	/* token index for login token */

	/* Transmit power */
	__u16		txpower_capa;	/* What options are supported */
	__u8		num_txpower;	/* Number of entries in the list */
	__s32		txpower[IW_MAX_TXPOWER];	/* list, in bps */

	/* Wireless Extension version info */
	__u8		we_version_compiled;	/* Must be WIRELESS_EXT */
	__u8		we_version_source;	/* Last update of source */

	/* Retry limits and lifetime */
	__u16		retry_capa;	/* What retry options are supported */
	__u16		retry_flags;	/* How to decode max/min retry limit */
	__u16		r_time_flags;	/* How to decode max/min retry life */
	__s32		min_retry;	/* Minimal number of retries */
	__s32		max_retry;	/* Maximal number of retries */
	__s32		min_r_time;	/* Minimal retry lifetime */
	__s32		max_r_time;	/* Maximal retry lifetime */

	/* Frequency */
	__u16		num_channels;	/* Number of channels [0; num - 1] */
	__u8		num_frequency;	/* Number of entry in the list */
	struct iw_freq	freq[IW_MAX_FREQUENCIES];	/* list */
	/* Note : this frequency list doesn't need to fit channel numbers,
	 * because each entry contain its channel index */

	__u32		enc_capa; /* IW_ENC_CAPA_* bit field */
};

/*
 * Private ioctl interface information
 */
 
struct	iw_priv_args
{
	__u32		cmd;		/* Number of the ioctl to issue */
	__u16		set_args;	/* Type and number of args */
	__u16		get_args;	/* Type and number of args */
	char		name[IFNAMSIZ];	/* Name of the extension */
};

/* ----------------------- WIRELESS EVENTS ----------------------- */
/*
 * Wireless events are carried through the rtnetlink socket to user
 * space. They are encapsulated in the IFLA_WIRELESS field of
 * a RTM_NEWLINK message.
 */

/*
 * A Wireless Event. Contains basically the same data as the ioctl...
 */
struct iw_event
{
	__u16		len;			/* Real lenght of this stuff */
	__u16		cmd;			/* Wireless IOCTL */
	union iwreq_data	u;		/* IOCTL fixed payload */
};

/* Size of the Event prefix (including padding and alignement junk) */
#define IW_EV_LCP_LEN	(sizeof(struct iw_event) - sizeof(union iwreq_data))
/* Size of the various events */
#define IW_EV_CHAR_LEN	(IW_EV_LCP_LEN + IFNAMSIZ)
#define IW_EV_UINT_LEN	(IW_EV_LCP_LEN + sizeof(__u32))
#define IW_EV_FREQ_LEN	(IW_EV_LCP_LEN + sizeof(struct iw_freq))
#define IW_EV_PARAM_LEN	(IW_EV_LCP_LEN + sizeof(struct iw_param))
#define IW_EV_ADDR_LEN	(IW_EV_LCP_LEN + sizeof(struct sockaddr))
#define IW_EV_QUAL_LEN	(IW_EV_LCP_LEN + sizeof(struct iw_quality))

/* iw_point events are special. First, the payload (extra data) come at
 * the end of the event, so they are bigger than IW_EV_POINT_LEN. Second,
 * we omit the pointer, so start at an offset. */
#define IW_EV_POINT_OFF (((char *) &(((struct iw_point *) NULL)->length)) - \
			  (char *) NULL)
#define IW_EV_POINT_LEN	(IW_EV_LCP_LEN + sizeof(struct iw_point) - \
			 IW_EV_POINT_OFF)



struct ieee80211_nodestats {
	u_int32_t ns_rx_data;		/* rx data frames */
	u_int32_t ns_rx_mgmt;		/* rx management frames */
	u_int32_t ns_rx_ctrl;		/* rx control frames */
	u_int32_t ns_rx_ucast;		/* rx unicast frames */
	u_int32_t ns_rx_mcast;		/* rx multi/broadcast frames */
	u_int64_t ns_rx_bytes;		/* rx data count (bytes) */
	u_int64_t ns_rx_beacons;		/* rx beacon frames */
	u_int32_t ns_rx_proberesp;	/* rx probe response frames */

	u_int32_t ns_rx_dup;		/* rx discard because it's a dup */
	u_int32_t ns_rx_noprivacy;	/* rx w/ wep but privacy off */
	u_int32_t ns_rx_wepfail;		/* rx wep processing failed */
	u_int32_t ns_rx_demicfail;	/* rx demic failed */
	u_int32_t ns_rx_decap;		/* rx decapsulation failed */
	u_int32_t ns_rx_defrag;		/* rx defragmentation failed */
	u_int32_t ns_rx_disassoc;	/* rx disassociation */
	u_int32_t ns_rx_deauth;		/* rx deauthentication */
	u_int32_t ns_rx_decryptcrc;	/* rx decrypt failed on crc */
	u_int32_t ns_rx_unauth;		/* rx on unauthorized port */
	u_int32_t ns_rx_unencrypted;	/* rx unecrypted w/ privacy */

	u_int32_t ns_tx_data;		/* tx data frames */
	u_int32_t ns_tx_mgmt;		/* tx management frames */
	u_int32_t ns_tx_ucast;		/* tx unicast frames */
	u_int32_t ns_tx_mcast;		/* tx multi/broadcast frames */
	u_int64_t ns_tx_bytes;		/* tx data count (bytes) */
	u_int32_t ns_tx_probereq;	/* tx probe request frames */
	u_int32_t ns_tx_uapsd;		/* tx on uapsd queue */

	u_int32_t ns_tx_novlantag;	/* tx discard due to no tag */
	u_int32_t ns_tx_vlanmismatch;	/* tx discard due to of bad tag */

	u_int32_t ns_tx_eosplost;	/* uapsd EOSP retried out */

	u_int32_t ns_ps_discard;		/* ps discard due to of age */

	u_int32_t ns_uapsd_triggers;	/* uapsd triggers */

	/* MIB-related state */
	u_int32_t ns_tx_assoc;		/* [re]associations */
	u_int32_t ns_tx_assoc_fail;	/* [re]association failures */
	u_int32_t ns_tx_auth;		/* [re]authentications */
	u_int32_t ns_tx_auth_fail;	/* [re]authentication failures*/
	u_int32_t ns_tx_deauth;		/* deauthentications */
	u_int32_t ns_tx_deauth_code;	/* last deauth reason */
	u_int32_t ns_tx_disassoc;	/* disassociations */
	u_int32_t ns_tx_disassoc_code;	/* last disassociation reason */
	u_int32_t ns_psq_drops;		/* power save queue drops */
};


/*设备管理网管接口*/
#define WIFIMODULE_SIZE   	4      /*无线模块的最大数目*/
#define VAPMODULE_SIZE		8	
#define DEVICE_NAME_LEN   	32  
#define WIFI_DEVICE_NUM   	4     /*无线设备数目*/


/*捆绑回传模块的参数*/
typedef struct 
{
	unsigned long ulScanTimerMinIntvl;   /*扫描定时器的最小时长-单位ms*/
	unsigned long ulScanTimerIntvl;      /*扫描定时器的时长-单位ms */
	unsigned long ulKeepRunMsgIntvl; /*收到保活消息的时间间隔-单位ms */
	unsigned long ulMaxSendProbeNum; /*发送的最大Probe 消息的数目*/
	unsigned long ulAcceptRssi;          /*可以接受的信号强度-单位dBm*/
	unsigned long ulMinScanPauseIntvl;   /*扫描间歇期最小时长-单位ms */
	unsigned long ulScanPauseIntvl;      /*扫描间歇期时长-单位ms */
}WIFI_DEVICE_BINDADHOC_PARA_T;


#define WIFIDEVICETYPE_NONE			0XFFFFFFFF
#define WIFIDEVICETYPE_ALONEAP		0				/* 独立的接入模块 */
#define WIFIDEVICETYPE_BINDAP		       1				/* 捆绑的接入模块 */
#define WIFIDEVICETYPE_ALONEADHOC	2				/* 独立的回传模块 */
#define WIFIDEVICETYPE_BINDADHOC	       3				/* 捆绑的回传模块 */
#define WIFIDEVICETYPE_APADHOC		4				/* 接入加回传模块 */
#define WIFIDEVICETYPE_MAX				5


typedef struct
{
     unsigned long      ulWifiDeviceId;
     unsigned long      ulWifiDeviceType;
     union
     {
         WIFI_DEVICE_BINDADHOC_PARA_T     stBindAdhocPara;             /*捆绑的回传模块*/
     }unAlgorithmPara;
}WIFI_DEVICE_ALGORITHM_PARA_T;

typedef enum  
{
	ADD_WIFI_DEVICE,   /* 增加无线设备*/
	DEL_WIFI_DEVICE,   /* 删除无线设备*/
	EDIT_WIFI_DEVICE   /* 修改无线设备*/
}WIFI_DEVICE_SET_TYPE_E;

typedef struct  
{
	unsigned long	ulWifiDeviceId;					/* 无线设备编号*/
	unsigned long	ulWifiDeviceType;				/* 设备类型*/
	unsigned long	ulWifiModuleNum;				/* 模块列表中被使用的个数*/
	char			acWifiModuleName[WIFIMODULE_SIZE][DEVICE_NAME_LEN];/* 模块名称列表*/
	unsigned long	ulWifiModuleRole[WIFIMODULE_SIZE];	/* 模块角色列表 */
	
}WIFI_DEVICE_T;

typedef struct 
{
	WIFI_DEVICE_SET_TYPE_E	enSetType;				/* 操作类型*/
	WIFI_DEVICE_T stWifiDevice;
}WIFI_DEVICE_SET_T;

typedef enum  
{
	ADD_VAP_TO_WIFI_DEVICE,			/* 从无线设备中增加VAP */
	DEL_VAP_FROM_WIFI_DEVICE		/* 从无线设备中删除VAP */
}VAP_SET_TYPE_E;

#define		INDIE_VAP	0			/* 独立的VAP */
#define		MAIN_VAP	1			/* 主VAP */
#define		SLAVE_VAP	2			/* 从VAP */
#define 		VAP_ROLE_MAX	3
typedef struct 
{
	char			acVapName[DEVICE_NAME_LEN];	/* VAP设备名*/
	unsigned long	ulWifiDeviceId; /* 无线设备编号*/
	unsigned long	ulVapRole;		/* 设备的角色*/
	char			acMainVapName[DEVICE_NAME_LEN];/* 通知无线层该从AP对应的主AP。当该VAP为从VAP时，才设置该值 */
}VAP_MANAGE_T;


typedef struct 
{
	VAP_SET_TYPE_E	enSetType;		/* 操作类型*/
	VAP_MANAGE_T stVapManage;
}VAP_SET_T;



#define	CHANNEL_LIST_MAX_NUM	16
/*----------------------------------- vap set with wifiDevice ------------------------------------------*/

typedef struct
{
	VAP_SET_TYPE_E	enSetType;								/* 操作类型*/
	VAP_MANAGE_T	stVapManage;
}VAP_ASSIGN_T;


typedef struct  
{
	unsigned long	ulWifiDeviceId;							/* 无线设备编号*/
	unsigned long	ulChannelNum;							/* 信道列表中被使用的个数 */
	unsigned long	aulChannelList[CHANNEL_LIST_MAX_NUM];	/* 信道列表*/
}AUTO_CHANNEL_LIST_SET_T;

typedef struct /*vap相关的模块信息*/
{
	u_int32_t	ulRoleState;	/* vap的角色*/
    struct ieee80211vap *vap; /*对应vap指针*/
}WIFI_DEVICE_VAP_PARA_T;

typedef struct  
{
	u_int32_t	ulWifiDeviceId;					        /* 无线设备编号*/
	u_int32_t	ulWifiDeviceType;				        /* 无线设备类型*/
	
	u_int32_t	ulChannelNum;						    /* 信道列表中被使用的个数 */
	u_int32_t	aulChannelList[CHANNEL_LIST_MAX_NUM];	/* 信道列表*/

	u_int32_t	ulWifiDeviceVapNum;				   /* 无线模块vap数目 */
	WIFI_DEVICE_VAP_PARA_T astWifiDeviceVap[VAPMODULE_SIZE];/* 无线模块vap信息*/

	u_int32_t	ulWifiModuleNum;				/* 无线模块数目 */
	char	        acWifiModuleName[WIFIMODULE_SIZE][DEVICE_NAME_LEN];/* 模块名*/

}WIFI_DEVICE_PARA_T;


/*统计信息网管接口*/

#define RATE_PKT_INFO_MAX_NUM   15 

/*各功率上的发送包数*/
#define POWER_SEND_PKT_INFO_MAX_NUM	 30
typedef struct  
{
	unsigned long	ulTxPower;					/*功率*/
	unsigned long	ulSendPkt;					/*发送包数*/
}POWER_SEND_PKT_INFO_T;
typedef POWER_SEND_PKT_INFO_T	POWER_SEND_PKT_STAT_T[POWER_SEND_PKT_INFO_MAX_NUM];

/*各RSSI的接收包数*/
#define RSSI_RECV_PKT_INFO_MAX_NUM 10
typedef struct  
{
	unsigned long	ulRssi;						/*RSSI*/
	unsigned long	ulRecvPkt;					/*接收包数*/
}RSSI_RECV_PKT_INFO_T;
typedef RSSI_RECV_PKT_INFO_T	RSSI_RECV_PKT_STAT_T[RSSI_RECV_PKT_INFO_MAX_NUM];

/*各信令丢包数、信令收/发包数*/
#define SIGNAL_PKT_INFO_MAX_NUM			20
typedef struct  
{
	unsigned long	ulSignal;					/*信令*/
	unsigned long	ulLossPkt;					/*丢包数*/
	unsigned long	ulRecvPkt;					/*接收包数*/
	unsigned long	ulSendPkt;					/*发送包数*/
}SIGNAL_PKT_INFO_T;
typedef SIGNAL_PKT_INFO_T	SIGNAL_PKT_STAT_T[SIGNAL_PKT_INFO_MAX_NUM];

#define ANTENNA_NUM ((u_int8_t)2)  /*天线的数目*/
typedef struct /*天线统计信息*/
{
	u_int32_t  aulResvMCastNum[ANTENNA_NUM]; /*每个天线接收的广播包的数目*/
	u_int32_t  aulResvUCastNum[ANTENNA_NUM];/*每个天线接收的单播包的数目*/

	u_int32_t  aulSendMCastNum[ANTENNA_NUM]; /*每个天线接收的广播包的数目*/
	u_int32_t  aulSendUCastNum[ANTENNA_NUM]; /*每个天线发送的单播包的数目*/
}SMART_ANTENNA_STAT_T;

typedef struct /*智能天线开关状态*/
{
     u_int32_t    status;
}SMART_ANTENNA_STATUS_T;

typedef struct /*天线统计信息*/
{
	u_int32_t  aulResvUCastNum[ANTENNA_NUM]; /*每个天线接收的单播包的数目*/
	u_int32_t  aulSendUCastNum[ANTENNA_NUM]; /*每个天线发送的单播包的数目*/
}ANTENNA_STAT_T;

#define RATE_PKT_INFO_MAX_NUM			15
//各速率上的收/发包数
typedef struct
{
	unsigned long	ulRate;						//速率
	unsigned long	ulRecvPkt;					//接收包数
	unsigned long	ulSendPkt;					//发送包数
}RATE_PKT_INFO_T;

typedef RATE_PKT_INFO_T		RATE_PKT_STAT_T[RATE_PKT_INFO_MAX_NUM];


typedef struct  /*单条链路统计信息*/
{
	u_int32_t			       ulBusinessLossPkt;			       /*业务丢包数*/
	u_int32_t				ulBusinessRecvPkt;				/*业务收包数*/
	u_int32_t			       ulBusinessSendPkt;				/*业务发包数*/
	u_int32_t				ulBroadcastRecvPkt;				/*广播收包数*/
	u_int32_t				ulBroadcastSendPkt;				/*广播发包数*/
	u_int32_t				ulRssi;							/*RSSI*/
	u_int32_t			       ulChannel;						/*工作信道*/
	int32_t				lNoiseFloor;						/*底噪*/
       u_int8_t                        ucWifiModuleName[32];            	/*无线模块名*/
	u_int8_t				ucPeerMac[6];					/*对端MAC*/
	RATE_PKT_STAT_T		       stRatePktStat;				/*各速率上的收/发包数*/
	ANTENNA_STAT_T                stAntennaStat;                   	/*天线信息*/
	POWER_SEND_PKT_STAT_T	stPowerSendPktStat;		       /*各功率上的发送包数*/
	RSSI_RECV_PKT_STAT_T	stRssiRecvPktStat;			/*各RSSI的接收包数*/
	SIGNAL_PKT_STAT_T		stSignalPktStat;				/*各信令丢包数、信令收/发包数*/
}ADHOC_SINGLE_LINK_STAT_T;

#define MAX_ADHOC_LINK_NUM   16
typedef struct /*所有链路统计信息*/
{
	u_int32_t ulAdhocLinkNum;
	/* ADHOC_SINGLE_LINK_STAT_T stAdhocSingleLinkStat[MAX_ADHOC_LINK_NUM]; */
	ADHOC_SINGLE_LINK_STAT_T stAdhocSingleLinkStat ;
}ADHOC_LINK_STAT_T;

typedef struct
{
	unsigned long			ulValidNum;
	ADHOC_LINK_STAT_T		stcAdhocLinkStat;
}ADHOC_LINK_STAT_LIST_T;

#ifndef RATE_LIST_MAX_NUM
#define RATE_LIST_MAX_NUM		20
#endif

typedef struct endUserEntryOmc_s_i{
 unsigned long endUserIndex;
 /* #define INVALID_INDEX_I 0 */	/* delete by yey 2008.3.27 */
 unsigned char endUserMac[6];
 unsigned char endUserIp[4] ;		/* add by yey 2007.9.5 : 显示终端用户IP地址*/
 unsigned long endUserLiveTime;
 
  unsigned long	ulApEndUserConBgMode;
 T_rateList		stRateList;
 
 /* 发送包数目 */
 unsigned long pktSendToUser;
 /* 接收包数目 */
 unsigned long pktRecvFromUser;
} T_endUserEntryOmc_i ;


typedef struct endUserEntry_s_i
{
 unsigned long endUserIndex;
 /* #define INVALID_INDEX_I 0 */	/* delete by yey 2008.3.27 */
 unsigned char endUserMac[6];
 unsigned char endUserIp[4] ;		/* add by yey 2007.9.5 : 显示终端用户IP地址*/
 unsigned long endUserLiveTime;
 unsigned long endUserCalcTime; /* 统计时长(单位: 秒)*/
 
 u_int32_t	ulApEndUserConBgMode;
 T_rateList		stRateList;
 
 /* 发送包数目 */
 unsigned long pktSendToUser;
 unsigned long pktSendToUserBYTE; /* 发送字节数UNIT: 128 BYTE */ 

 /* 接收包数目 */
 unsigned long pktRecvFromUser;
 unsigned long pktRecvFromUserBYTE;  /* 接收字节数UNIT: 128 BYTE */

 /* 单播发送平均速率 */
 unsigned long ulAvgRate; /* UNIT: kbps */

 /* 单播发送平均重传数目 */
 unsigned long ulAvgRetranNum; 

   /* 接收平均速率*/
  unsigned long ulRcvAvgRate;

  /* 队列超长警告 */
  unsigned long ulEX50Sum;
  unsigned long ulEX100Sum;
  unsigned long ulEX150Sum;	
  unsigned long ulEX200Sum; 
} T_endUserEntry_i;


#define apEndUserList_SIZE MAX_ENDUSER_ENTRY_I

/*速率*/
#define WIFI_RATE_1M          0     /*1M速率*/
#define WIFI_RATE_2M          1     /*2M速率*/
#define WIFI_RATE_5DOT5M  2     /*5.5M速率*/
#define WIFI_RATE_11M        3     /*11M速率*/
#define WIFI_RATE_6M          4     /*6M速率*/
#define WIFI_RATE_9M          5     /*9M速率*/
#define WIFI_RATE_12M        6     /*12M速率*/
#define WIFI_RATE_18M        7     /*18M速率*/
#define WIFI_RATE_24M        8     /*24M速率*/
#define WIFI_RATE_36M        9     /*36M速率*/
#define WIFI_RATE_48M        10    /*48M速率*/
#define WIFI_RATE_54M        11    /*54M速率*/

/*速率*/

#define WIFI_RATE_1M_VALUE             1000000       /*1M速率*/
#define WIFI_RATE_2M_VALUE             2000000    /*2M速率*/
#define WIFI_RATE_5DOT5M_VALUE    5500000     /*5.5M速率*/
#define WIFI_RATE_11M_VALUE           11000000    /*11M速率*/
#define WIFI_RATE_6M_VALUE             6000000   /*6M速率*/
#define WIFI_RATE_9M_VALUE             9000000   /*9M速率*/
#define WIFI_RATE_12M_VALUE           12000000  /*12M速率*/
#define WIFI_RATE_18M_VALUE           18000000   /*18M速率*/
#define WIFI_RATE_24M_VALUE           24000000 /*24M速率*/
#define WIFI_RATE_36M_VALUE           36000000 /*36M速率*/
#define WIFI_RATE_48M_VALUE           48000000  /*48M速率*/
#define WIFI_RATE_54M_VALUE           54000000 /*54M速率*/


/*终端用户模式*/
#define WIFI_END_USER_MODE_A   0   /*A模式*/
#define WIFI_END_USER_MODE_B   1   /*B模式*/
#define WIFI_END_USER_MODE_G   2   /*G模式*/
#define WIFI_END_USER_MODE_MAXED   3   /*混合模式*/

/*无线RSSI*/
#define WIFI_RSSI_0_AND_20_DBM    0   /*RSSI在0到20之间*/
#define WIFI_RSSI_21_AND_25_DBM  1   /*RSSI在21到25之间*/
#define WIFI_RSSI_26_AND_30_DBM  2   /*RSSI在26到30之间*/
#define WIFI_RSSI_31_AND_35_DBM  3   /*RSSI在31到35之间*/
#define WIFI_RSSI_36_AND_40_DBM  4   /*RSSI在36到40之间*/
#define WIFI_RSSI_41_AND_60_DBM  5   /*RSSI在41到60之间*/
#define WIFI_RSSI_BEYOND_60_DBM  6   /*RSSI在大于60*/

typedef struct 
{
	unsigned long	ulEventFlag;						/*有效标识*/
#define EVENTFLAG_INVALID					0		/*无效*/
#define EVENTFLAG_VALID						1	/*有效*/
	unsigned long	ulEventId;						/*事件ID*/
	/* wifi_alarm */
#define EVENTID_CARD_FAULT					1000		/*卡故障*/
#define EVENTID_MORE_ENDUSER				1001		/*用户数超过门限值*/
#define EVENTID_BELOW_ADHOC_NEB_THR			1002		/*ADHOC邻居数低于门限值*/
#define EVENTID_WIFI_UNRECV_PACK				1003		/*卡不接收数据*/
#define EVENTID_WIFI_PORT_MORE_FLOW			1004		/*无线端口流量过载*/
	/* wifi_event */
#define EVENTID_USER_ACCESS_FAILED			2000		/*用户接入失败*/
#define EVENTID_ILLEGAL_ACCESS				2001		/*mesh非法接入*/
	unsigned long	ulEventStatus;					/*事件状态*/
#define EVENTSTATUS_RESUMPTION				0		/*恢复*/
#define EVENTSTATUS_PRODUCE					1		/*产生*/
	unsigned long	ulEventReasonId;					/*事件原因ID号*/
	/* wifi_alarm */
#define EVENTREASONID_CARD_FAULT				1000		/*卡故障*/
#define EVENTREASONID_MORE_ENDUSER			1100		/*用户数超过门限值*/
#define EVENTREASONID_BELOW_ADHOC_NEB_THR		1200		/*ADHOC邻居数低于门限值*/
#define EVENTREASONID_WIFI_UNRECV_PACK		1300		/*卡不接收数据*/
#define EVENTREASONID_WIFI_PORT_MORE_FLOW		1400		/*无线端口流量过载*/
	/* wifi_event */
#define EVENTREASONID_USER_ACCESS_FAILED		2000		/*用户接入失败*/
#define EVENTREASONID_ILLEGAL_ACCESS			2100		/*mesh非法接入*/
	unsigned long	ulEventLevel;						/*事件级别*/
#define EVENTLEVEL_FATAL					0		/*致命*/
#define EVENTLEVEL_SERIOUS					1		/*严重*/
#define EVENTLEVEL_GENERAL					2		/*一般*/
#define EVENTLEVEL_MINOR					3		/*轻微*/
	unsigned long	ulObjType;						/*对象类型*/
#define OBJECTTYPE_WIFI_CARD				0		/*无线模块*/
#define OBJECTTYPE_ENET						1		/*以太网口*/
#define OBJECTTYPE_WIFI_DEVICE				2		/*无线设备*/
#define OBJECTTYPE_PORT						3		/*端口*/
#define OBJECTTYPE_SYSTEM					4		/*系统*/
	char			acObjName[32];					/*对象名称*/
	struct timeval		stHappenTime;						/*事件发生时间*/
	unsigned long	ulUptime;							/*上电到发生该事件的时间，tick值，毫秒*/

	union
	{
		unsigned long	ulComInfo;
		char			acMac[6];
		char			acIp[4];
	}unExtendInfo;
}EVENT_TRAP_MSG_T;

#define EVENTTRAPMSGLIST_MAX_NUM	20
typedef EVENT_TRAP_MSG_T EVENT_TRAP_MSG_LIST_T[EVENTTRAPMSGLIST_MAX_NUM];


typedef struct adhPm_s
{
#define MAX_TOTAL_RANGE  0xFFFFFF
 u_int32_t txpktnum;
 u_int32_t rxpktnum;
 /* 算出加权平均的接收速率，选择最接近的接收速率，
     上报给系统控制模块，上报后刷新接收速率统计 */     
 unsigned long  totalRecvDataRate;

 /* 算出加权平均的发送速率，选择最接近的发送速率，
     上报给系统控制模块，上报后刷新发送速率统计 */
 unsigned long totalSendDataRate;

/* 发射功率的算术平均，可能在我看来是固定的 */
 u_int32_t totalTxPower;
 /* Snr的算术平均 */ 
 unsigned long totalSnr;
} T_adhPm;

typedef struct accessDenyEntry_s
{
 u_int32_t accessDenyIndex;
 u_int8_t  accessDenyMac[6];
 u_int8_t  accessDenyReason[32];
 /* 使用jiffies作为单位 */
 u_int32_t accessDenyTime;
} T_accessDenyEntry;

typedef struct snrEntry_s
{
 long snrChannel;
 /* 使用1..11 149..153标识 */
 long snrValue;
 /* 扫描得到的信噪比 */
} T_snrEntry;

/*
 * Summary statistics.
 */
struct ieee80211_stats {
	u_int32_t is_rx_badversion;	/* rx frame with bad version */
	u_int32_t is_rx_tooshort;	/* rx frame too short */
	u_int32_t is_rx_wrongbss;	/* rx from wrong bssid */
	u_int32_t is_rx_dup;		/* rx discard due to it's a dup */
	u_int32_t is_rx_wrongdir;	/* rx w/ wrong direction */
	u_int32_t is_rx_mcastecho;	/* rx discard due to of mcast echo */
	u_int32_t is_rx_notassoc;	/* rx discard due to sta !assoc */
	u_int32_t is_rx_noprivacy;	/* rx w/ wep but privacy off */
	u_int32_t is_rx_unencrypted;	/* rx w/o wep and privacy on */
	u_int32_t is_rx_wepfail;		/* rx wep processing failed */
	u_int32_t is_rx_decap;		/* rx decapsulation failed */
	u_int32_t is_rx_mgtdiscard;	/* rx discard mgt frames */
	u_int32_t is_rx_ctl;		/* rx discard ctrl frames */
	u_int32_t is_rx_beacon;		/* rx beacon frames */
	u_int32_t is_rx_rstoobig;	/* rx rate set truncated */
	u_int32_t is_rx_elem_missing;	/* rx required element missing*/
	u_int32_t is_rx_elem_toobig;	/* rx element too big */
	u_int32_t is_rx_elem_toosmall;	/* rx element too small */
	u_int32_t is_rx_elem_unknown;	/* rx element unknown */
	u_int32_t is_rx_badchan;		/* rx frame w/ invalid chan */
	u_int32_t is_rx_chanmismatch;	/* rx frame chan mismatch */
	u_int32_t is_rx_nodealloc;	/* rx frame dropped */
	u_int32_t is_rx_ssidmismatch;	/* rx frame ssid mismatch  */
	u_int32_t is_rx_auth_unsupported;/* rx w/ unsupported auth alg */
	u_int32_t is_rx_auth_fail;	/* rx sta auth failure */
	u_int32_t is_rx_auth_countermeasures;/* rx auth discard due to CM */
	u_int32_t is_rx_assoc_bss;	/* rx assoc from wrong bssid */
	u_int32_t is_rx_assoc_notauth;	/* rx assoc w/o auth */
	u_int32_t is_rx_assoc_capmismatch;/* rx assoc w/ cap mismatch */
	u_int32_t is_rx_assoc_norate;	/* rx assoc w/ no rate match */
	u_int32_t is_rx_assoc_badwpaie;	/* rx assoc w/ bad WPA IE */
	u_int32_t is_rx_deauth;		/* rx deauthentication */
	u_int32_t is_rx_disassoc;	/* rx disassociation */
	u_int32_t is_rx_badsubtype;	/* rx frame w/ unknown subtype*/
	u_int32_t is_rx_nobuf;		/* rx failed for lack of buf */
	u_int32_t is_rx_decryptcrc;	/* rx decrypt failed on crc */
	u_int32_t is_rx_ahdemo_mgt;	/* rx discard ahdemo mgt frame*/
	u_int32_t is_rx_bad_auth;	/* rx bad auth request */
	u_int32_t is_rx_unauth;		/* rx on unauthorized port */
	u_int32_t is_rx_badkeyid;	/* rx w/ incorrect keyid */
	u_int32_t is_rx_ccmpreplay;	/* rx seq# violation (CCMP) */
	u_int32_t is_rx_ccmpformat;	/* rx format bad (CCMP) */
	u_int32_t is_rx_ccmpmic;		/* rx MIC check failed (CCMP) */
	u_int32_t is_rx_tkipreplay;	/* rx seq# violation (TKIP) */
	u_int32_t is_rx_tkipformat;	/* rx format bad (TKIP) */
	u_int32_t is_rx_tkipmic;		/* rx MIC check failed (TKIP) */
	u_int32_t is_rx_tkipicv;		/* rx ICV check failed (TKIP) */
	u_int32_t is_rx_badcipher;	/* rx failed due to of key type */
	u_int32_t is_rx_nocipherctx;	/* rx failed due to key !setup */
	u_int32_t is_rx_acl;		/* rx discard due to of acl policy */
	u_int32_t is_rx_ffcnt;		/* rx fast frames */
	u_int32_t is_rx_badathtnl;   	/* driver key alloc failed */
	u_int32_t is_tx_nobuf;		/* tx failed for lack of buf */
	u_int32_t is_tx_nonode;		/* tx failed for no node */
	u_int32_t is_tx_unknownmgt;	/* tx of unknown mgt frame */
	u_int32_t is_tx_badcipher;	/* tx failed due to of key type */
	u_int32_t is_tx_nodefkey;	/* tx failed due to no defkey */
	u_int32_t is_tx_noheadroom;	/* tx failed due to no space */
	u_int32_t is_tx_ffokcnt;		/* tx fast frames sent success */
	u_int32_t is_tx_fferrcnt;	/* tx fast frames sent success */
	u_int32_t is_scan_active;	/* active scans started */
	u_int32_t is_scan_passive;	/* passive scans started */
	u_int32_t is_node_timeout;	/* nodes timed out inactivity */
	u_int32_t is_crypto_nomem;	/* no memory for crypto ctx */
	u_int32_t is_crypto_tkip;	/* tkip crypto done in s/w */
	u_int32_t is_crypto_tkipenmic;	/* tkip en-MIC done in s/w */
	u_int32_t is_crypto_tkipdemic;	/* tkip de-MIC done in s/w */
	u_int32_t is_crypto_tkipcm;	/* tkip counter measures */
	u_int32_t is_crypto_ccmp;	/* ccmp crypto done in s/w */
	u_int32_t is_crypto_wep;		/* wep crypto done in s/w */
	u_int32_t is_crypto_setkey_cipher;/* cipher rejected key */
	u_int32_t is_crypto_setkey_nokey;/* no key index for setkey */
	u_int32_t is_crypto_delkey;	/* driver key delete failed */
	u_int32_t is_crypto_badcipher;	/* unknown cipher */
	u_int32_t is_crypto_nocipher;	/* cipher not available */
	u_int32_t is_crypto_attachfail;	/* cipher attach failed */
	u_int32_t is_crypto_swfallback;	/* cipher fallback to s/w */
	u_int32_t is_crypto_keyfail;	/* driver key alloc failed */
	u_int32_t is_crypto_enmicfail;	/* en-MIC failed */
	u_int32_t is_ibss_capmismatch;	/* merge failed-cap mismatch */
	u_int32_t is_ibss_norate;	/* merge failed-rate mismatch */
	u_int32_t is_ps_unassoc;		/* ps-poll for unassoc. sta */
	u_int32_t is_ps_badaid;		/* ps-poll w/ incorrect aid */
	u_int32_t is_ps_qempty;		/* ps-poll w/ nothing to send */

	/* ap Deny Access List */
	#define MAX_DENY_ACCESS_NUM  10
	u_int32_t         listHead;
	T_accessDenyEntry  accDenyList[MAX_DENY_ACCESS_NUM];
	
/*	#define MAX_RATE_NUM 20
	u_int32_t dataRcvRate[MAX_RATE_NUM];
	u_int32_t dataSndRate[MAX_RATE_NUM];
	u_int32_t totalRcvPkt;
	u_int32_t totalSndPkt;
	u_int32_t totalSnr;
	u_int32_t totalTxpow; */
	
	/* adhoc neighbour channel */
	#define MAX_SNR_ENTRY 4
	T_snrEntry  snrEnt[MAX_SNR_ENTRY];

	/* adhoc pm stat */
	T_adhPm   tadhocPm;
};

/*
 * Max size of optional information elements.  We artificially
 * constrain this; it's limited only by the max frame size (and
 * the max parameter size of the wireless extensions).
 */
#define	IEEE80211_MAX_OPT_IE	256

/*
 * WPA/RSN get/set key request.  Specify the key/cipher
 * type and whether the key is to be used for sending and/or
 * receiving.  The key index should be set only when working
 * with global keys (use IEEE80211_KEYIX_NONE for ``no index'').
 * Otherwise a unicast/pairwise key is specified by the bssid
 * (on a station) or mac address (on an ap).  They key length
 * must include any MIC key data; otherwise it should be no
 more than IEEE80211_KEYBUF_SIZE.
 */
struct ieee80211req_key {
	u_int8_t ik_type;		/* key/cipher type */
	u_int8_t ik_pad;
	u_int16_t ik_keyix;		/* key index */
	u_int8_t ik_keylen;		/* key length in bytes */
	u_int8_t ik_flags;
/* NB: IEEE80211_KEY_XMIT and IEEE80211_KEY_RECV defined elsewhere */
#define	IEEE80211_KEY_DEFAULT	0x80	/* default xmit key */
	u_int8_t ik_macaddr[IEEE80211_ADDR_LEN];
	u_int64_t ik_keyrsc;		/* key receive sequence counter */
	u_int64_t ik_keytsc;		/* key transmit sequence counter */
	u_int8_t ik_keydata[IEEE80211_KEYBUF_SIZE+IEEE80211_MICBUF_SIZE];
};

/*
 * Delete a key either by index or address.  Set the index
 * to IEEE80211_KEYIX_NONE when deleting a unicast key.
 */
struct ieee80211req_del_key {
	u_int8_t idk_keyix;		/* key index */
	u_int8_t idk_macaddr[IEEE80211_ADDR_LEN];
};

/*
 * MLME state manipulation request.  IEEE80211_MLME_ASSOC
 * only makes sense when operating as a station.  The other
 * requests can be used when operating as a station or an
 * ap (to effect a station).
 */
struct ieee80211req_mlme {
	u_int8_t im_op;			/* operation to perform */
#define	IEEE80211_MLME_ASSOC		1	/* associate station */
#define	IEEE80211_MLME_DISASSOC		2	/* disassociate station */
#define	IEEE80211_MLME_DEAUTH		3	/* deauthenticate station */
#define	IEEE80211_MLME_AUTHORIZE	4	/* authorize station */
#define	IEEE80211_MLME_UNAUTHORIZE	5	/* unauthorize station */
#define IEEE80211_MLME_CLEAR_STATS	6	/* clear station statistic */
	u_int8_t im_ssid_len;		/* length of optional ssid */
	u_int16_t im_reason;		/* 802.11 reason code */
	u_int8_t im_macaddr[IEEE80211_ADDR_LEN];
	u_int8_t im_ssid[IEEE80211_NWID_LEN];
};

/* 
 * MAC ACL operations.
 */
enum {
	IEEE80211_MACCMD_POLICY_OPEN	= 0,	/* set policy: no ACL's */
	IEEE80211_MACCMD_POLICY_ALLOW	= 1,	/* set policy: allow traffic */
	IEEE80211_MACCMD_POLICY_DENY	= 2,	/* set policy: deny traffic */
	IEEE80211_MACCMD_FLUSH		= 3,	/* flush ACL database */
	IEEE80211_MACCMD_DETACH		= 4,	/* detach ACL policy */
};

/*
 * Set the active channel list.  Note this list is
 * intersected with the available channel list in
 * calculating the set of channels actually used in
 * scanning.
 */
struct ieee80211req_chanlist {
	u_int8_t ic_channels[IEEE80211_CHAN_BYTES];
};

/*
 * Channels are specified by frequency and attributes.
 */
struct ieee80211_channel {
	u_int16_t ic_freq;	/* setting in Mhz */
	u_int16_t ic_flags;	/* see below */
	u_int8_t ic_ieee;	/* IEEE channel number */
	int8_t ic_maxregpower;	/* maximum regulatory tx power in dBm */
	int8_t ic_maxpower;	/* maximum tx power in dBm */
	int8_t ic_minpower;	/* minimum tx power in dBm */
};


/*
 * Get the active channel list info.
 */
struct ieee80211req_chaninfo {
	u_int8_t ic_nchans;
	struct ieee80211_channel ic_chans[IEEE80211_CHAN_MAX];
};

/*
 * Retrieve the WPA/RSN information element for an associated station.
 */
struct ieee80211req_wpaie {
	u_int8_t	wpa_macaddr[IEEE80211_ADDR_LEN];
	u_int8_t	wpa_ie[IEEE80211_MAX_OPT_IE];
	u_int8_t	rsn_ie[IEEE80211_MAX_OPT_IE];
};

/*
 * Retrieve per-node statistics.
 */
struct ieee80211req_sta_stats {
	union {
		/* NB: explicitly force 64-bit alignment */
		u_int8_t macaddr[IEEE80211_ADDR_LEN];
		u_int64_t pad;
	} is_u;
	struct ieee80211_nodestats is_stats;
};

/*
 * Station information block; the mac address is used
 * to retrieve other data like stats, unicast key, etc.
 */
struct ieee80211req_sta_info {
	u_int16_t isi_len;		/* length (mult of 4) */
	u_int16_t isi_freq;		/* MHz */
	u_int16_t isi_flags;		/* channel flags */
	u_int16_t isi_state;		/* state flags */
	u_int8_t isi_authmode;		/* authentication algorithm */
	u_int8_t isi_rssi;
	u_int16_t isi_capinfo;		/* capabilities */
	u_int8_t isi_athflags;		/* Atheros capabilities */
	u_int8_t isi_erp;		/* ERP element */
	u_int8_t isi_macaddr[IEEE80211_ADDR_LEN];
	u_int8_t isi_nrates;		/* negotiated rates */
	u_int8_t isi_rates[IEEE80211_RATE_MAXSIZE];
	u_int8_t isi_txrate;		/* index to isi_rates[] */
	u_int16_t isi_ie_len;		/* IE length */
	u_int16_t isi_associd;		/* assoc response */
	u_int16_t isi_txpower;		/* current tx power */
	u_int16_t isi_vlan;		/* vlan tag */
	u_int16_t isi_txseqs[17];	/* seq to be transmitted */
	u_int16_t isi_rxseqs[17];	/* seq previous for qos frames*/
	u_int16_t isi_inact;		/* inactivity timer */
	u_int8_t isi_uapsd;		/* UAPSD queues */
	u_int8_t isi_opmode;		/* sta operating mode */

	/* XXX frag state? */
	/* variable length IE data */
};

enum {
	IEEE80211_STA_OPMODE_NORMAL,
	IEEE80211_STA_OPMODE_XR
};

/*
 * Retrieve per-station information; to retrieve all
 * specify a mac address of ff:ff:ff:ff:ff:ff.
 */
struct ieee80211req_sta_req {
	union {
		/* NB: explicitly force 64-bit alignment */
		u_int8_t macaddr[IEEE80211_ADDR_LEN];
		u_int64_t pad;
	} is_u;
	struct ieee80211req_sta_info info[1];	/* variable length */
};

/*
 * Get/set per-station tx power cap.
 */
struct ieee80211req_sta_txpow {
	u_int8_t	it_macaddr[IEEE80211_ADDR_LEN];
	u_int8_t	it_txpow;
};

/*
 * WME parameters are set and return using i_val and i_len.
 * i_val holds the value itself.  i_len specifies the AC
 * and, as appropriate, then high bit specifies whether the
 * operation is to be applied to the BSS or ourself.
 */
#define	IEEE80211_WMEPARAM_SELF	0x0000		/* parameter applies to self */
#define	IEEE80211_WMEPARAM_BSS	0x8000		/* parameter applies to BSS */
#define	IEEE80211_WMEPARAM_VAL	0x7fff		/* parameter value */

/*
 * Scan result data returned for IEEE80211_IOC_SCAN_RESULTS.
 */
struct ieee80211req_scan_result {
	u_int16_t isr_len;		/* length (mult of 4) */
	u_int16_t isr_freq;		/* MHz */
	u_int16_t isr_flags;		/* channel flags */
	u_int8_t isr_noise;
	u_int8_t isr_rssi;
	u_int8_t isr_intval;		/* beacon interval */
	u_int16_t isr_capinfo;		/* capabilities */
	u_int8_t isr_erp;		/* ERP element */
	u_int8_t isr_bssid[IEEE80211_ADDR_LEN];
	u_int8_t isr_nrates;
	u_int8_t isr_rates[IEEE80211_RATE_MAXSIZE];
	u_int8_t isr_ssid_len;		/* SSID length */
	u_int8_t isr_ie_len;		/* IE length */
	u_int8_t isr_pad[5];
	/* variable length SSID followed by IE data */
};


/*
 * Wireless Extensions API, private ioctl interfaces.
 *
 * NB: Even-numbered ioctl numbers have set semantics and are privileged!
 *     (regardless of the incorrect comment in wireless.h!)
 */
#define	IEEE80211_IOCTL_SETPARAM	(SIOCIWFIRSTPRIV+0)
#define	IEEE80211_IOCTL_GETPARAM	(SIOCIWFIRSTPRIV+1)
#define	IEEE80211_IOCTL_SETMODE		(SIOCIWFIRSTPRIV+2)
#define	IEEE80211_IOCTL_GETMODE		(SIOCIWFIRSTPRIV+3)
#define	IEEE80211_IOCTL_SETWMMPARAMS	(SIOCIWFIRSTPRIV+4)
#define	IEEE80211_IOCTL_GETWMMPARAMS	(SIOCIWFIRSTPRIV+5)
#define	IEEE80211_IOCTL_SETCHANLIST	(SIOCIWFIRSTPRIV+6)
#define	IEEE80211_IOCTL_GETCHANLIST	(SIOCIWFIRSTPRIV+7)
#define	IEEE80211_IOCTL_CHANSWITCH	(SIOCIWFIRSTPRIV+8)
#define	IEEE80211_IOCTL_GETCHANINFO	(SIOCIWFIRSTPRIV+13)
#define	IEEE80211_IOCTL_SETOPTIE	(SIOCIWFIRSTPRIV+14)
#define	IEEE80211_IOCTL_GETOPTIE	(SIOCIWFIRSTPRIV+15)
#define	IEEE80211_IOCTL_SETMLME		(SIOCIWFIRSTPRIV+16)
#define	IEEE80211_IOCTL_SETKEY		(SIOCIWFIRSTPRIV+18)
#define	IEEE80211_IOCTL_DELKEY		(SIOCIWFIRSTPRIV+20)
#define	IEEE80211_IOCTL_ADDMAC		(SIOCIWFIRSTPRIV+22)
#define	IEEE80211_IOCTL_DELMAC		(SIOCIWFIRSTPRIV+24)
#define	IEEE80211_IOCTL_WDSADDMAC	(SIOCIWFIRSTPRIV+26)
#define	IEEE80211_IOCTL_WDSDELMAC	(SIOCIWFIRSTPRIV+28)
#define	IEEE80211_IOCTL_KICKMAC		(SIOCIWFIRSTPRIV+30)
enum {
	IEEE80211_WMMPARAMS_CWMIN       = 1,
	IEEE80211_WMMPARAMS_CWMAX       = 2,
	IEEE80211_WMMPARAMS_AIFS       	= 3,
	IEEE80211_WMMPARAMS_TXOPLIMIT	= 4,
	IEEE80211_WMMPARAMS_ACM		= 5,
	IEEE80211_WMMPARAMS_NOACKPOLICY	= 6,	
};
enum {
	IEEE80211_PARAM_TURBO		= 1,	/* turbo mode */
	IEEE80211_PARAM_MODE		= 2,	/* phy mode (11a, 11b, etc.) */
	IEEE80211_PARAM_AUTHMODE	= 3,	/* authentication mode */
	IEEE80211_PARAM_PROTMODE	= 4,	/* 802.11g protection */
	IEEE80211_PARAM_MCASTCIPHER	= 5,	/* multicast/default cipher */
	IEEE80211_PARAM_MCASTKEYLEN	= 6,	/* multicast key length */
	IEEE80211_PARAM_UCASTCIPHERS	= 7,	/* unicast cipher suites */
	IEEE80211_PARAM_UCASTCIPHER	= 8,	/* unicast cipher */
	IEEE80211_PARAM_UCASTKEYLEN	= 9,	/* unicast key length */
	IEEE80211_PARAM_WPA		= 10,	/* WPA mode (0,1,2) */
	IEEE80211_PARAM_ROAMING		= 12,	/* roaming mode */
	IEEE80211_PARAM_PRIVACY		= 13,	/* privacy invoked */
	IEEE80211_PARAM_COUNTERMEASURES	= 14,	/* WPA/TKIP countermeasures */
	IEEE80211_PARAM_DROPUNENCRYPTED	= 15,	/* discard unencrypted frames */
	IEEE80211_PARAM_DRIVER_CAPS	= 16,	/* driver capabilities */
	IEEE80211_PARAM_MACCMD		= 17,	/* MAC ACL operation */
	IEEE80211_PARAM_WMM		= 18,	/* WMM mode (on, off) */
	IEEE80211_PARAM_HIDESSID	= 19,	/* hide SSID mode (on, off) */
	IEEE80211_PARAM_APBRIDGE    	= 20,   /* AP inter-sta bridging */
	IEEE80211_PARAM_KEYMGTALGS	= 21,	/* key management algorithms */
	IEEE80211_PARAM_RSNCAPS		= 22,	/* RSN capabilities */
	IEEE80211_PARAM_INACT		= 23,	/* station inactivity timeout */
	IEEE80211_PARAM_INACT_AUTH	= 24,	/* station auth inact timeout */
	IEEE80211_PARAM_INACT_INIT	= 25,	/* station init inact timeout */
	IEEE80211_PARAM_ABOLT		= 26,	/* Atheros Adv. Capabilities */
	IEEE80211_PARAM_DTIM_PERIOD	= 28,	/* DTIM period (beacons) */
	IEEE80211_PARAM_BEACON_INTERVAL	= 29,	/* beacon interval (ms) */
	IEEE80211_PARAM_DOTH		= 30,	/* 11.h is on/off */
	IEEE80211_PARAM_PWRTARGET	= 31,	/* Current Channel Pwr Constraint */
	IEEE80211_PARAM_GENREASSOC	= 32,	/* Generate a reassociation request */
	IEEE80211_PARAM_COMPRESSION	= 33,	/* compression */
	IEEE80211_PARAM_FF		= 34,	/* fast frames support  */
	IEEE80211_PARAM_XR		= 35,	/* XR support */
	IEEE80211_PARAM_BURST		= 36,	/* burst mode */
	IEEE80211_PARAM_PUREG		= 37,	/* pure 11g (no 11b stations) */
	IEEE80211_PARAM_AR		= 38,	/* AR support */
	IEEE80211_PARAM_WDS		= 39,	/* Enable 4 address processing */
	IEEE80211_PARAM_BGSCAN		= 40,	/* bg scanning (on, off) */
	IEEE80211_PARAM_BGSCAN_IDLE	= 41,	/* bg scan idle threshold */
	IEEE80211_PARAM_BGSCAN_INTERVAL	= 42,	/* bg scan interval */
	IEEE80211_PARAM_MCAST_RATE	= 43,	/* Multicast Tx Rate */
	IEEE80211_PARAM_COVERAGE_CLASS	= 44,	/* coverage class */
	IEEE80211_PARAM_COUNTRY_IE	= 45,	/* enable country IE */
	IEEE80211_PARAM_SCANVALID	= 46,	/* scan cache valid threshold */
	IEEE80211_PARAM_ROAM_RSSI_11A	= 47,	/* rssi threshold in 11a */
	IEEE80211_PARAM_ROAM_RSSI_11B	= 48,	/* rssi threshold in 11b */
	IEEE80211_PARAM_ROAM_RSSI_11G	= 49,	/* rssi threshold in 11g */
	IEEE80211_PARAM_ROAM_RATE_11A	= 50,	/* tx rate threshold in 11a */
	IEEE80211_PARAM_ROAM_RATE_11B	= 51,	/* tx rate threshold in 11b */
	IEEE80211_PARAM_ROAM_RATE_11G	= 52,	/* tx rate threshold in 11g */
	IEEE80211_PARAM_UAPSDINFO	= 53,	/* value for qos info field */
	IEEE80211_PARAM_SLEEP		= 54,	/* force sleep/wake */
	IEEE80211_PARAM_QOSNULL		= 55,	/* force sleep/wake */
	IEEE80211_PARAM_PSPOLL		= 56,	/* force ps-poll generation (sta only) */
	IEEE80211_PARAM_EOSPDROP	= 57,	/* force uapsd EOSP drop (ap only) */
	IEEE80211_PARAM_MARKDFS		= 58,	/* mark a dfs interference channel when found */
	IEEE80211_PARAM_REGCLASS	= 59,	/* enable regclass ids in country IE */
	IEEE80211_PARAM_DROPUNENC_EAPOL	= 60,	/* drop unencrypted eapol frames */
};

#define	SIOCG80211STATS			(SIOCDEVPRIVATE+2)
/* NB: require in+out parameters so cannot use wireless extensions, yech */
#define	IEEE80211_IOCTL_GETKEY		(SIOCDEVPRIVATE+3)
#define	IEEE80211_IOCTL_GETWPAIE	(SIOCDEVPRIVATE+4)
#define	IEEE80211_IOCTL_STA_STATS	(SIOCDEVPRIVATE+5)
#define	IEEE80211_IOCTL_STA_INFO	(SIOCDEVPRIVATE+6)
#define	SIOC80211IFCREATE		(SIOCDEVPRIVATE+7)
#define	SIOC80211IFDESTROY	 	(SIOCDEVPRIVATE+8)
#define	IEEE80211_IOCTL_SCAN_RESULTS	(SIOCDEVPRIVATE+9)
#define	IEEE80211_IOCTL_SET_RETRYNUM	(SIOCDEVPRIVATE+10)

#define	IEEE80211_IOCTL_GET_BENESTAT 	(SIOCDEVPRIVATE+12)
#define	IEEE80211_IOCTL_GET_MACADDR        (SIOCDEVPRIVATE+13)
#define   IEEE80211_IOCTL_CLR_DENYLIST         (SIOCDEVPRIVATE+14)
#define   IEEE80211_IOCTL_ADD_DENYLIST        (SIOCDEVPRIVATE+15)
#define   IEEE80211_IOCTL_DEBUG_SET              (SIOCDEVPRIVATE+16)


/*SCW Add For IOCTL*/
#define   IEEE80211_IOCTL_COMMON      	(SIOCDEVPRIVATE + 15)


#define	IEEE80211_MSG_DEBUG	0x40000000	/* IFF_DEBUG equivalent */
#define	IEEE80211_MSG_DUMPPKTS	0x20000000	/* IFF_LINK2 equivalant */
#define	IEEE80211_MSG_CRYPTO	0x10000000	/* crypto work */
#define	IEEE80211_MSG_INPUT	0x08000000	/* input handling */
#define	IEEE80211_MSG_XRATE	0x04000000	/* rate set handling */
#define	IEEE80211_MSG_ELEMID	0x02000000	/* element id parsing */
#define	IEEE80211_MSG_NODE	0x01000000	/* node handling */
#define	IEEE80211_MSG_ASSOC	0x00800000	/* association handling */
#define	IEEE80211_MSG_AUTH	0x00400000	/* authentication handling */
#define	IEEE80211_MSG_SCAN	0x00200000	/* scanning */
#define	IEEE80211_MSG_OUTPUT	0x00100000	/* output handling */
#define	IEEE80211_MSG_STATE	0x00080000	/* state machine */
#define	IEEE80211_MSG_POWER	0x00040000	/* power save handling */
#define	IEEE80211_MSG_DOT1X	0x00020000	/* 802.1x authenticator */
#define	IEEE80211_MSG_DOT1XSM	0x00010000	/* 802.1x state machine */
#define	IEEE80211_MSG_RADIUS	0x00008000	/* 802.1x radius client */
#define	IEEE80211_MSG_RADDUMP	0x00004000	/* dump 802.1x radius packets */
#define	IEEE80211_MSG_RADKEYS	0x00002000	/* dump 802.1x keys */
#define	IEEE80211_MSG_WPA	0x00001000	/* WPA/RSN protocol */
#define	IEEE80211_MSG_ACL	0x00000800	/* ACL handling */
#define	IEEE80211_MSG_WME	0x00000400	/* WME protocol */
#define	IEEE80211_MSG_SUPG	0x00000200	/* SUPERG */
#define	IEEE80211_MSG_DOTH	0x00000100	/* 11.h */
#define	IEEE80211_MSG_INACT	0x00000080	/* inactivity handling */
#define	IEEE80211_MSG_ROAM	0x00000040	/* sta-mode roaming */

#define	IEEE80211_MSG_ANY	0xffffffff	/* anything */

typedef enum
{
	IEEE80211_MODULE_DEBUG = 0,		/* IFF_DEBUG equivalent */
	IEEE80211_MODULE_DUMPPKTS,	/* IFF_LINK2 equivalant */
	IEEE80211_MODULE_CRYPTO,		/* crypto work */
	IEEE80211_MODULE_INPUT,		/* input handling */
	IEEE80211_MODULE_XRATE	,	/* rate set handling */
	IEEE80211_MODULE_ELEMID,		/* element id parsing */
	IEEE80211_MODULE_NODE,		/* node handling */
	IEEE80211_MODULE_ASSOC,		/* association handling */
	IEEE80211_MODULE_AUTH,		/* authentication handling */
	IEEE80211_MODULE_SCAN	,	/* scanning */
	IEEE80211_MODULE_OUTPUT,	/* output handling */
	IEEE80211_MODULE_STATE,		/* state machine */
	IEEE80211_MODULE_POWER,		/* power save handling */
	IEEE80211_MODULE_DOT1X,		/* 802.1x authenticator */
	IEEE80211_MODULE_DOT1XSM,	/* 802.1x state machine */
	IEEE80211_MODULE_RADIUS,		/* 802.1x radius client */
	IEEE80211_MODULE_RADDUMP,	/* dump 802.1x radius packets */
	IEEE80211_MODULE_RADKEYS,	/* dump 802.1x keys */
	IEEE80211_MODULE_WPA,		/* WPA/RSN protocol */
	IEEE80211_MODULE_ACL	,		/* ACL handling */
	IEEE80211_MODULE_WME,		/* WME protocol */
	IEEE80211_MODULE_SUPG,		/* SUPERG */
	IEEE80211_MODULE_DOTH,		/* 11.h */
	IEEE80211_MODULE_INACT	,	/* inactivity handling */
	IEEE80211_MODULE_ROAM	,	/* sta-mode roaming */
	
	IEEE80211_MODULE_NUM,		/* module number*/
	
	IEEE80211_MODULE_ANY		       /* anything */

}IEEE80211_MODULE_E;

/*SCW Add For Print optimize 2007-06-11*/
#define IEEE80211_MSG_LEVEL_DETAIL     5  /*详细信息*/
#define IEEE80211_MSG_LEVEL_INFO         4  /*一般信息*/
#define IEEE80211_MSG_LEVEL_WARN        3   /*警告*/
#define IEEE80211_MSG_LEVEL_ERROR       2  /*错误*/
#define IEEE80211_MSG_LEVEL_FATAL       1 /*严重错误*/
#define IEEE80211_MSG_LEVEL_CLOSE       0/*打印关闭*/

enum {
	ATH_MSG_XMIT		= 0x00000001,	/* basic xmit operation */
	ATH_MSG_XMIT_DESC	= 0x00000002,	/* xmit descriptors */
	ATH_MSG_RECV		= 0x00000004,	/* basic recv operation */
	ATH_MSG_RECV_DESC	= 0x00000008,	/* recv descriptors */
	ATH_MSG_RATE		= 0x00000010,	/* rate control */
	ATH_MSG_RESET		= 0x00000020,	/* reset processing */
	/* 0x00000040 was ATH_MSG_MODE */
	ATH_MSG_BEACON 	= 0x00000080,	/* beacon handling */
	ATH_MSG_WATCHDOG 	= 0x00000100,	/* watchdog timeout */
	ATH_MSG_INTR		= 0x00001000,	/* ISR */
	ATH_MSG_TX_PROC	= 0x00002000,	/* tx ISR proc */
	ATH_MSG_RX_PROC	= 0x00004000,	/* rx ISR proc */
	ATH_MSG_BEACON_PROC	= 0x00008000,	/* beacon ISR proc */
	ATH_MSG_CALIBRATE	= 0x00010000,	/* periodic calibration */
	ATH_MSG_KEYCACHE	= 0x00020000,	/* key cache management */
	ATH_MSG_STATE		= 0x00040000,	/* 802.11 state transitions */
	ATH_MSG_NODE		= 0x00080000,	/* node management */
	ATH_MSG_LED		= 0x00100000,	/* led management */
	ATH_MSG_FF		= 0x00200000,	/* fast frames */
	ATH_MSG_TURBO		= 0x00400000,	/* turbo/dynamice turbo */
	ATH_MSG_UAPSD		= 0x00800000,	/* uapsd */
	ATH_MSG_DOTH		= 0x01000000,	/* 11.h */
	ATH_MSG_ANY		= 0xffffffff
};
typedef enum
{
	ATH_MODULE_XMIT = 0,
	ATH_MODULE_XMIT_DESC,	
	ATH_MODULE_RECV,
	ATH_MODULE_RECV_DESC,	
	ATH_MODULE_RATE,
	ATH_MODULE_RESET,
	ATH_MODULE_BEACON,
	ATH_MODULE_WATCHDOG,
	ATH_MODULE_INTR,
	ATH_MODULE_TX_PROC,
	ATH_MODULE_RX_PROC,
	ATH_MODULE_BEACON_PROC,
	ATH_MODULE_CALIBRATE,
	ATH_MODULE_KEYCACHE,
	ATH_MODULE_STATE,
	ATH_MODULE_NODE,
	ATH_MODULE_LED,
	ATH_MODULE_FF,
	ATH_MODULE_TURBO,
	ATH_MODULE_UAPSD,
	ATH_MODULE_DOTH,
	ATH_MODULE_NUM,
	ATH_MODULE_ANY
}ATH_MODULE_E;

struct ieee80211_clone_params {
	char icp_name[IFNAMSIZ];		/* device name */
	u_int16_t icp_opmode;			/* operating mode */
	u_int16_t icp_flags;			/* see below */
#define	IEEE80211_CLONE_BSSID	0x0001		/* allocate unique mac/bssid */
#define	IEEE80211_NO_STABEACONS	0x0002		/* Do not setup the station beacon timers */
};

typedef struct adhocPm_s_i
{
 unsigned long totalRecvDataRate;
 /* 算出加权平均的接收速率，选择最接近的接收速率，上报给系统控制模块，上报后刷新接收速率统计 */
 unsigned long totalSendDataRate;
 /* 算出加权平均的发送速率，选择最接近的发送速率，上报给系统控制模块，上报后刷新发送速率统计 */
 unsigned long totalTxPower;
 /* 发射功率的算术平均，可能在我看来是固定的 */
 unsigned long totalSnr;
 /* Snr的算术平均 */
 unsigned long neighborNumber;
 /* 邻区数目 */
} T_adhocPm_i;

/* adhoc邻区列表 */
typedef struct adhocNeighborEntry_s_i
{
 long adhocNeighborIndex;
 unsigned char adhocNeighborMac[6];
 unsigned char adhocNeighborIp[4];
 /* 最新的接收速率 */
 unsigned long recvDataRate;
 /* 最新的发送速率 */
 unsigned long sendDataRate;
 /* 最新的发送功率 */
 unsigned long txPower;
 /* 最新的接收信噪比 */
 unsigned long rssi;
 /* 平均接收信噪比*/
 unsigned long avgrssi;
} T_adhocNeighborEntry_i;

typedef struct snrEntry_s_i
{
 long snrChannel;
 /* 使用1..11 149..153标识,0代表无效的信道 */
 long snrValue;
 /* 扫描得到的信噪比 */
} T_snrEntry_i;

typedef struct accessDenyEntry_s_i
{
 unsigned long accessDenyIndex;
 unsigned char accessDenyMac[6];
 unsigned char accessDenyReason[32];

 /* 使用jiffies作为单位 */
 unsigned long accessDenyTime;
} T_accessDenyEntry_i;

typedef struct
{
	char			accessDenyReason[32];		//原因
	unsigned long	ulDenyNum;					//个数
	unsigned long	ulWifiIndex;				//模块号
} T_accessDenyReason_i;

typedef struct wifiState_s_i
{
	enum {
		N_endUserTable_I = 0,
		N_accessDenyTable_I,
		N_snrTable_I,
		N_adhocNeighborTable_I,
		N_adhocPm_I,
		N_accessDenyReasonTable_I,
		N_Sta_Stats_I
	} m;
/*
#define MAX_ENDUSER_ENTRY_I 128
#define MAX_ACCESSDENY_ENTRY_I 10
#define MAX_SNR_ENTRY_I 8
#define MAX_ADHOCNEIGHBOR_ENTRY_I 10
*/
	union {
		T_apEndUser				endUserEntry;
		OMA_STA_ASSOCIATE_T		stStaAssociate;
		T_accessDenyEntry_i		accessDenyEntry[MAX_ACCESSDENY_ENTRY_I];
		T_snrEntry_i			snrEntry[MAX_SNR_ENTRY_I];
		T_adhocNeighborEntry_i	adhocNeighborEntry[MAX_ADHOCNEIGHBOR_ENTRY_I];
		T_adhocPm_i				adhocPm;
		T_accessDenyReason_i	stAcceDenyReasonEntry[MAX_ACCESSDENY_ENTRY_I];
	} u;
} T_wifiState_i;

/*-------------------------------------- filter stat -----------------------------------------*/
/* mac filter 类型定义 */
typedef struct
{
	u_int8_t	aucMac[IEEE80211_ADDR_LEN];	/* MAC地址 */
	u_int32_t   ulDenyDiscards; /* 丢弃包统计 */
}DENY_FILTER_STAT_T;

typedef struct
{
	u_int32_t    ulAllowPks; /* 允许报文个数 */
#define IOCTL_MAC_FILTER_MAXNUM 64
	DENY_FILTER_STAT_T aucDenyStat[IOCTL_MAC_FILTER_MAXNUM]; /* 拒绝统计信息 */
}IEEE80211_FILTER_STAT_T;

typedef struct{
	u_int32_t ulType;
#define IOCTL_SET_MAC_FILTER_LIST     0
#define IOCTL_DEL_MAC_FILTER_LIST     1
#define IOCTL_GET_MAC_FILTER_LIST     2
#define IOCTL_SET_MAC_FILTER_MODE     3
#define IOCTL_GET_MAC_FILTER_STAT     4
	u_int32_t ulMode;
#define MAC_FILTER_DENY        0x00
#define MAC_FILTER_ALLOW       0x01
	union{
		u_int8_t aucMacList[IOCTL_MAC_FILTER_MAXNUM][IEEE80211_ADDR_LEN];
		IEEE80211_FILTER_STAT_T stFilterStat;
	}u;
#define aucList	u.aucMacList
#define stStat u.stFilterStat
} IOCTL_MAC_FILTER_T;

/*---------------------------------------- adhoc authority -----------------------------------------------*/
/* adhoc 鉴权的类型定义 */
typedef struct
{
	u_int8_t ucIbssAuthmode; /* Ad-hoc模式鉴权方式*/
#define IOCTL_IBSS_AUTH_MODE_SHARED    ((u_int8_t) 0) /*共享式*/
#define IOCTL_IBSS_AUTH_MODE_OPEN      ((u_int8_t) 1) /*开放式*/
	u_int8_t ucIbssAutTryNum; /* Ad-hoc模式鉴权失败后重新尝试的次数*/
	u_int8_t ucIbssAuthTimer; /* Ad-hoc模式鉴权定时器时长*/
	u_int8_t ucIbssAuthDataEncrypt; /* Ad-hoc模式下数据帧是否加密*/
#define IOCTL_IBSS_AUTH_DATA_NOT_ENCRYPT    ((u_int8_t) 0) /*不加密*/
#define IOCTL_IBSS_AUTH_DATA_ENCRYPT       ((u_int8_t) 1) /*加密*/
} IOCTL_IBSS_AUTH_T;

/*--------------------------------------------- wifiDevice -----------------------------------------------*/

#define WIFIMODULE_SIZE				4

/*----------------------------------- vap set with wifiDevice ------------------------------------------*/

/*---------------------------------------- auto channel list -------------------------------------------*/
#define	CHANNEL_LIST_MAX_NUM	16

/*--------------------------------------- wifi algorithm para ------------------------------------------*/

/*独立的接入模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEAP_PARA_T;

/*捆绑的接入模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_BINDAP_PARA_T;

/*独立的回传模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_ALONEADHOC_PARA_T;

/*接入加回传模块的参数*/
typedef struct
{
    int resv;
}WIFI_DEVICE_APADHOC_PARA_T;

/*------------------------------------------ adhoc link stat ---------------------------------------------*/
#define IVALID_DATA        0xFFFFFFFF



//各功率上的发送包数
#define POWER_SEND_PKT_INFO_MAX_NUM		30

//各RSSI的接收包数
#define RSSI_RECV_PKT_INFO_MAX_NUM		10

//各信令丢包数、信令收/发包数
#define SIGNAL_PKT_INFO_MAX_NUM			20

#define ANTENNA_NUM ((u_int8_t)2)				/*天线的数目*/


//链路统计
#define ADHOC_LINK_STAT_LIST_MAX_NUM	20

typedef struct
{
    UINT32                  ulRxucNum;          /*接收点播包数目*/
    UINT32                  ulRxmcNum;          /*接收广播包数目*/
    UINT32                  ulTxucNum;          /*发送点播包数目*/
    UINT32                  ulTxmcNum;          /*发送广播包数目*/
    UINT32                  ulTxAirLostNum;     /*空口丢包数*/
    UINT32                  ulTxActLostNum;     /*主动丢包数*/
    UINT32                  ulTxReNum;          /*重传次数，只点播报文重传*/
    UINT32                  ulUserNum;          /*AP：即时接入用户个数*/
    INT32                   iNoise;             /*底噪*/
}VAP_STATS_T ;

typedef struct
{
    UINT32                  ulRxucNum;          /*接收点播包数目*/
    UINT32                  ulRxmcNum;          /*接收广播包数目*/
    UINT32                  ulTxucNum;          /*发送点播包数目*/
    UINT32                  ulTxmcNum;          /*发送广播包数目*/
    UINT32                  ulTxAirLostNum;     /*空口丢包数*/
    UINT32                  ulTxActLostNum;     /*主动丢包数*/
    UINT32                  ulTxReNum;          /*重传次数，只点播报文重传*/
    UINT32                  ulNeiNum;           /*ADHOC：即时邻居个数*/
    INT32                   iNoise;             /*底噪*/
}ADHOC_STATS_T ;

typedef struct
{
	u_int32_t ulStaDelIntvl;
	u_int32_t ulHighRssi;
	u_int32_t ulLowRssi;
}AP_DEL_STA_PARA_T;

typedef enum
{
	BSS_STAT_GROBE,
	BSS_STAT_AIR,
	BSS_STAT_NEIGH_LINK,
}BSS_STAT_CMD_T;

typedef struct
{
	BSS_STAT_CMD_T enStatCmd;
	union {
		OMA_GLOBAL_STAT_INFO stGlobeStats;
		OMA_AIR_STATS_INFO stAirStates;
		OMA_ADHOC_LINK_STATS_ENTRY stNeighLinkStats;
	}unStats;
}BSS_STATS_T;

typedef struct
{
	unsigned long on;			                /* 0：禁用；1：启用；缺省为禁用*/
#define SCAN_ROGUE_SSID_OFF			0
#define SCAN_ROGUE_SSID_ON			1
	unsigned long flag;							/* flag&0x01:监听相同SSID的ROGUE AP；flag&0x02:监听隐藏
	                                             * 的SSID的ROGUE AP；flag标志位可组合使用，缺省值为0x01 */
#define MONITOR_SAME_ROGUE_SSID		0x1
#define MONITOR_HIDDEN_ROGUE_SSID	0x2
#define MONITOR_COM_ROUGE_SSID		0x1 | 0x2
	struct ieee80211_scan_ssid rogue_ssid;
	unsigned char bssid[6];						/* 指定BSSID的AP，全1无效 */
	unsigned char oui[3];						/* 指定厂商的AP，全1无效 */
	unsigned char aucRsv[3];
}WIFI_WIDS_T;

typedef struct
{
    UINT32  on;                         /* 1: 启用；0：禁用 */
    UINT32  flags;                      /* ROGUE AP定义：比特位表示法，如下宏所示 */
#define ROGUE_LOCAL_SSID    0x01        /* 本地相同SSID的AP */
#define ROGUE_HIDE_SSID     0x02        /* 隐藏SSID的AP */

    struct ieee80211_scan_ssid ssid;    /* 指定SSID的AP，允许通配符'*'，缺省为空，即全0 */
    UINT8    bssid[6];                  /* 指定BSSID的AP，全f无效 */
    UINT8    oui[3];                    /* 指定厂商的AP，全f无效 */
    UINT8    pad[3];
}ROGUE_AP_DEF_T ;


typedef struct
{
    UINT32  period;                 /* 信道扫描周期，以分钟为单位，如每15分钟扫描所有信道，最小值为5分钟 */
    UINT32  dwell;                  /* 信道停留扫描时间，以毫秒为单位，[20，1000] */
}BGSCAN_CONFIG_T;

/*-------------------------------------- 自定义ioctl接口的类型定义 -------------------------------------------*/
#define   IEEE80211_IOCTL_COMMON      	(SIOCDEVPRIVATE + 15)
typedef enum
{
	IOCTL_MAC_FILTER = 0,							/* MAC地址过滤 */
	IOCTL_IBSS_AUTH,								/* IBSS鉴权 */
	IOCTL_WIFIDEVICESET,            				/* 无线设备配置 */
	IOCTL_VAPSET,                   				/* VAP配置 */
	IOCTL_AUTOCHANNELLISTSET,       				/* 自适应信道配置 */
	IOCTL_ALGORITHM_PARA, 							/* 算法参数 */
	IOCTL_LINK_STAT,								/* 回传链路统计 */
	IOCTL_EVENT_LIST, 								/* 获取事件列表 */
	IOCTL_SET_USER_MAXNUM,							/* 设置单AP最大用户接入数 */
	IOCTL_GET_ENDUSER,   							/* TC获取用户信息 */
	IOCTL_QOSMAP_SET = 11,
	IOCTL_QOSMAP_GET = 12,
	IOCTL_GET_CHANNEL_NO = 15,						/* 获取设备当前信道号 */
	IOCTL_NETID_SET = 20 ,             				/* 设置合法标志 */
	IOCTL_NETID_GET = 21,              				/* 获取合法标志 */
	IOCTL_WIDS_SET = 22,              		        /* WIDS配置参数设置 */
	IOCTL_WIDS_GET = 23,              		        /* WIDS配置参数获取 */

	IOCTL_ROGUE_GET = 24,              				/* 上报非法AP信息 */
	IOCTL_SET_AP_DEL_STA_PARA = 25,					/* 删除终端配置 */
    IOCTL_VAP_STATS_GET = 30,                       /* 获取VAP统计信息 */
	IOCTL_WIFI_POWER_CTRL_SET = 31,					/* 功率控制设置 */
	IOCTL_BSS_STATS = 32,							/* 无线动态信息获取 */
	IOCTL_POWERMIN_SET = 60,						/* 最小功率配置 */

    IOCTL_ROGUEAP_DEF_SET = 70,                     /* 设置恶意AP定义 */
    IOCTL_ROGUEAP_DEF_GET = 71,                     /* 获取恶意AP定义 */
    IOCTL_BGSCAN_SET = 72,                          /* 设置扫描参数 */
    IOCTL_BGSCAN_GET = 73,                          /* 获取扫描参数 */

	IOCTL_GET_CHANNEL_NOSCAN_FLAG = 124,
	IOCTL_GET_DESIRED_BSSID = 128,					/* 绑定的BSSID */
	IOCTL_GET_ROAM_STAT = 129,						/* 历史关联信息 */
	IOCTL_GET_RELAY_CLIENT = 140, 					/* 代理终端信息 */
	IOCTL_SET_WMM_QOS_SWITCH = 178					/* WMM功能开关配置 */
}IOCTL_COMMON_TYPE_E;

typedef struct
{
	IOCTL_COMMON_TYPE_E  enCommIoctlType;
	union
	{
		IOCTL_MAC_FILTER_T				stFilterList;
		IOCTL_IBSS_AUTH_T				stIbssAuth;
		WIFI_DEVICE_SET_T               stWifiDeviceSet;
		VAP_ASSIGN_T                    stVapSet;
		AUTO_CHANNEL_LIST_SET_T			aulChannelListSet;
		WIFI_DEVICE_ALGORITHM_PARA_T	stAlgorithmPara; 	/* 算法参数 */
		ADHOC_LINK_STAT_LIST_T			stAdhocLinkStat;	/* 回传链路统计 */
		EVENT_TRAP_MSG_LIST_T			stEventList;		/* 获取事件列表 */
		unsigned short					usMaxUserNum;
		unsigned char					aaucEndUserMac[MAX_END_USER][IEEE80211_ADDR_LEN];
		unsigned char					aucQosmap[WME_NUM_AC];
		unsigned long                   ulNetId;            /* 用于识别非法接入IP */
		WIFI_WIDS_T                     stWids;             /* WID配置参数 */
		ROGUE_AP_INFO_T                 stRogueApInfo;
		ROGUE_AP_DEF_T                  stRogueApDef;       /* 设置恶意AP定义 */
		BGSCAN_CONFIG_T                 stBgScanConfig;     /* 设置扫描参数 */

        /* hc modified for telecom test 2009-7-6 */
		WIDS_CONFIG_T                   stWidsCfg ;
        ROGUE_STA_LIST_T                rogue_sta_list ;

        VAP_STATS_T                     stVapStats;
        ADHOC_STATS_T                   stAdhocStats;
		CHAN_SCAN_INFO_T				astGetChanScanInfo[MAX_CHAN_NUM];
		u_int8_t						aaucGetDesBssid[MAX_DES_BSSID][IEEE80211_ADDR_LEN];
		ROAM_STAT_T						stRoamStat;
		RELAY_CLIENT_T					astRelayClients[RELAY_CLIENT_MAX];
		AP_DEL_STA_PARA_T				stApDelStaPara;
		u_int32_t						ulPowerCtrlSet;		/*0:关闭,1:开启*/
		u_int32_t						ulWmmQosCtrlSet;	/*0:关闭,1:开启*/
		BSS_STATS_T						stBssStats;
		unsigned char					ucChannNo;			/* 信道 added at 3-17 */
		u_int32_t						ulPowerMin;			/* 最小发射功率 */

	}unData;
}IOCTL_COMMON_DATA_T;



#define BRCTL_MESH_ROUTE_IOCTL 30  /* be careful not to conflict with system config */


/***************************路由模块相关定义start*****************************/
/*网络属性*/
typedef struct routerNetSetup_s 
{
	unsigned long ulNetDiameter;							/*  网络直径 至少为1 */
	unsigned long ulNodeTraversalTime;						/*  相邻节点间传输时延*/
} T_routerNetSetup;

/*节点属性*/
typedef struct routerNodeSetup_s 
{
	unsigned long ulGwRunMode;								/* 网关功能*/
#define nodeGwRunMode_DISABLE				0
#define nodeGwRunMode_ENABLE				1
	unsigned long ulRelayRunMode;							/* 中继功能*/
#define nodeRelayRunMode_DISABLE			0
#define nodeRelayRunMode_ENABLE				1
	unsigned long ulMobileState;							/* 移动特性*/
#define mobileState_REST					0
#define mobileState_MOVE					1
	unsigned long ulMovingSpeed;							/* 移动速度*/
#define nodeMovingSpeed_SLOW				0
#define nodeMovingSpeed_FAST				1
	unsigned long ulMovingDirection;							/* 移动方向*/
#define nodeMovingDirection_MULTIPLE		0
#define nodeMovingDirection_BEFORE			1
#define nodeMovingDirection_AFTER			2
	unsigned long ulAirBandWidth;							/* 业务带宽要求*/
    char acDeviceId[6];
} T_routerNodeSetup;

/*动态路由*/
typedef struct routerDynamicSetup_s 
{
	unsigned long ulRouteTimeout;						/* 路由有效时长*/
	unsigned long ulRreqRateLimit;						/* RREQ频度限制*/
	unsigned long ulRreqRetries;						/* RREQ最大重发次数*/
	unsigned long ulTtlStart;							/* 启动TTL */
	unsigned long ulTtlIncrement;						/* 增加TTL步长*/
	unsigned long ulTtlThreshold;						/* TTL门限*/
	unsigned long ulVirtualRepSwitch;					/* 发送虚拟RREP控制开关*/
#define virtualRepSwitch_DISABLE				0			/* 不使用虚拟RREP */
#define virtualRepSwitch_ENABLE				1			/* 使用虚拟RREP */
	unsigned long ulSendErrSwitch;						/* 发送RERR控制开关*/
#define routeSendErrSwitch_DISABLE			0			/* 0=不发送RERR */
#define routeSendErrSwitch_ENABLE			1			/* 1=发送RERR */
	unsigned long ulRerrRateLimit;						/* RERR频度限制*/
	unsigned long ulMaxAcceptReqNumLimit;					/* RREQ接受数目限制*/
} T_routerDynamicSetup;


#define AODV_NEIGH_STATUS_FATHER    1   /* the neigh is my father */
#define AODV_NEIGH_STATUS_SON       2   /* the neigh is my son */
#define AODV_NEIGH_STATUS_OTHER     0   /* other relation */
#define AODV_NEIGHGW_SON            1   /* I am the gw of the neigh */
#define AODV_NEIGHGW_MY_GW          2   /* the neigh is my gw */
#define AODV_NEIGHGW_OTHER_GW       3   /* the neigh is gw, but it's not my gw */
#define AODV_NEIGHGW_OTHER          0   /* the neigh is not gw */
#define AODV_NEIGHBORLIST_SIZE      16  /* max neigh num */   

#define ROUTE_PATH_ENTRY_MAX_NUM		    16
#define ROUTE_ROUTE_PATH_ENTRY_MAX_NUM		5

typedef struct
{
        unsigned long ulMeshRoutePathFlag;                      /* 有效标致 */
        unsigned long ulNodeNum;          /* wl add .2008-03-14 */                        /* 路径设备ID列表中实际使用到的个数 */
        unsigned char acPathEntry[ROUTE_PATH_ENTRY_MAX_NUM][6]; /* 路径上的设备ID列表*/
        unsigned long ulPathId;                                 /* 路径ID */
        unsigned long ulPathQos;                                /* 路径QOS */
        unsigned long ulPathSendSpeed;                          /* 路径发送速率*/
        unsigned long ulPathRecvSpeed;                          /* 路径接收速率*/
        unsigned long ulPathLiveTime;                           /* 存活时间*/

} MESH_ROUTE_PATH_END_INFO_T;

//typedef struct
//{
//    unsigned long ulNum;    /* number of path */
//    unsigned char aucProxyAddr[6]; 
//    unsigned char aucDeviceId[6];
//    MESH_ROUTE_PATH_END_INFO_T  astPathEntry[ROUTE_PATH_ENTRY_MAX_NUM];
//} MESH_ROUTE_PATH_END_INFO_ENTRY;


typedef struct
{
    unsigned long ulNum;    /* number of route_path_entry */
    
    MESH_ROUTE_PATH_END_INFO_T  astPathEntry[ROUTE_PATH_ENTRY_MAX_NUM];
   // MESH_ROUTE_PATH_END_INFO_ENTRY  astRtPathEntry[ROUTE_ROUTE_PATH_ENTRY_MAX_NUM];
} MESH_ROUTE_PATH_END_INFO_LIST;

#define    MESH_DEV_TYPE_AP       0
#define    MESH_DEV_TYPE_ADHOC    1
#define    MESH_DEV_TYPE_ETH      2
#define    MESH_DEV_TYPE_GW       3

#define    MESH_ADD_DEV_TO_BR     1    /*向网桥中添加设备*/
#define    MESH_DEL_DEV_FRM_BR    2    /*从网桥中删除设备*/

typedef struct
{
    char    acIfrName[IFNAMSIZ];        /* if name, e.g. "eth0" */
    unsigned long ulCfgType;             /* wl add .2008-03-14 */  /*配置类型*/
    unsigned long ulDevType;             /* wl add .2008-03-14 */  /*设备类型*/
} MESH_DEV_CFG_T;

#define AODV_STATISLIST_SIZE      2
typedef struct PORT_FLOW_INFO_T 
{
	unsigned long ulRxFlow;							/* 入流量（kbps）*/
	unsigned long ulTxFlow;							/* 出流量（Kbps）*/
	unsigned long ulFwdFlow;						/* 转发流量（kbps）从ADHOC入，从ADHOC出*/
	unsigned long ulLocalFlow;                      /* 本地流量（kbps）*/     
	unsigned long ulInputFlow;                      /* add  */ 
	unsigned long ulOutputFlow;                     /* add  */     
	unsigned long ulRxPkt;							/* 入流量（kbps）*/
	unsigned long ulTxPkt;							/* 出流量（kbps）*/
	unsigned long ulFwdPkt;							/* 转发流量（kbps）*/
	unsigned long ulLocalPkt;
	unsigned long ulInputPkt;                       /* add  */ 
	unsigned long ulOutputPkt;                      /* add  */     

	/* Unicast statistic */
	unsigned long ulRxUniFlow;						/* 入单播流量(kbps) */
	unsigned long ulTxUniFlow;						/* 出单播流量(kbps) */
	unsigned long ulFwdUniFlow;						/* 转发单播流量（kbps）从AD */
	unsigned long ulLocalUniFlow;					/* 本地单播报文数*/  
	unsigned long ulInputUniFlow;                       /* add  */ 
	unsigned long ulOutputUniFlow;                      /* add  */     
    
	unsigned long ulRxUniPkt;                       	/* 入单播报文数*/
	unsigned long ulTxUniPkt;                       	/* 出单播报文数*/
	unsigned long ulFwdUniPkt;						/* 转发单播报文数从AD */
	unsigned long ulLocalUniPkt;					/* 本地单播报文数*/  
	unsigned long ulInputUniPkt;                       /* add  */ 
	unsigned long ulOutputUniPkt;                      /* add  */     

	/* Broadcast statistic */
	unsigned long ulRxBrdFlow;                    		/* 入广播流量(kbps) */
	unsigned long ulTxBrdFlow;                    		/* 出广播流量(kbps) */
	unsigned long ulFwdBrdFlow;						/* 转发广播流量（kbps）从AD */
	unsigned long ulLocalBrdFlow;					/* 本地广播报文数*/  
	unsigned long ulInputBrdFlow;                       /* add  */ 
	unsigned long ulOutputBrdFlow;                      /* add  */     
    
	unsigned long ulRxBrdPkt;                    		/* 入广播报文数*/
	unsigned long ulTxBrdPkt;                    		/* 出广播报文数*/
	unsigned long ulFwdBrdPkt;						/* 转发广播报文数从AD */
	unsigned long ulLocalBrdPkt;					/* 本地广播报文数*/  
	unsigned long ulInputBrdPkt;                       /* add  */ 
	unsigned long ulOutputBrdPkt;                      /* add  */     

	/* packet send failure (device driver failure )/以下统计只能用于ADHOC设备 */
	unsigned long ulDropUniFlow;                    	/* 丢弃单播流量(kbps) */
	unsigned long ulDropBrdFlow;					/* 丢弃广播流量*/
	unsigned long ulDropUniPkt;						/* 丢弃单播报文数*/
	unsigned long ulDropBrdPkt;						/* 丢弃广播报文数*/

	/* add by wl. for CR 716. at 2009-01-15 bgn */
	unsigned long ulRsv[2];
	unsigned long ulDownlinkDataFlow[2];	        /* [0] high part (B), [1] low part (KB) */						
	unsigned long ulUplinkDataFlow[2];			
	unsigned long ulDownlinkMngFlow[2];
	unsigned long ulUplinkMngFlow[2];
	unsigned long ulDownlinkFwdFlow[2];
	unsigned long ulUplinkFwdFlow[2];
	
	/* add by wl. for CR 716. at 2009-01-15 end */
}PORT_FLOW_INFO_T;

typedef struct
{
    char    acIfrName[IFNAMSIZ];        /* if name, e.g. "eth0" */
    PORT_FLOW_INFO_T stFlowInfo;  
} MESH_DEV_STATIS_T;

typedef struct  
{
    /* statis of each device */
    unsigned long ulNum;    /* number of valid device statis  */
    MESH_DEV_STATIS_T astStatisEntry[AODV_STATISLIST_SIZE];
} AODV_DEV_STATIS_LIST_T;


/* used in oam ioctl interface */
#define ROUTE_IOCTL_SETDEVCFG       1   /* set device config*/
#define ROUTE_IOCTL_GETNEIGHLIST    2   /* get neigh list */
#define ROUTE_IOCTL_GETPATHLIST     3   /* get route list */
#define ROUTE_IOCTL_SETNETCFG       4   /* set network config */
#define ROUTE_IOCTL_SETNODECFG      5   /* set node config */
#define ROUTE_IOCTL_SETNEICFG       6   /* set neighbour config */ 
#define ROUTE_IOCTL_SETROUTECFG     7   /* set route config */ 
#define ROUTE_IOCTL_SETHANDOVERCFG  8   /* set neigh config */
#define ROUTE_IOCTL_SETMSCFG        9   /* set ms config */
#define ROUTE_IOCTL_GETNETCFG       10  /* get network config */
#define ROUTE_IOCTL_GETNODECFG      11  /* get node config */
#define ROUTE_IOCTL_GETNEICFG       12  /* get neighbour config */ 
#define ROUTE_IOCTL_GETROUTECFG     13  /* get route config */ 
#define ROUTE_IOCTL_GETHANDOVERCFG  14  /* get neigh config */
#define ROUTE_IOCTL_GETMSCFG        15  /* set ms config */ 
#define ROUTE_IOCTL_GETEVENT        16  /* get event and warning list */
#define ROUTE_IOCTL_GETNODEINFO     17  /* get node info of current node */
#define ROUTE_IOCTL_GETSTATISINFO   18  /* get statistic  info of current node */
#define ROUTE_IOCTL_GETDEVSTATIS    19  /* get statistic  info of a device */

#define ROUTE_IOCTL_START           ROUTE_IOCTL_SETDEVCFG
#define ROUTE_IOCTL_END             ROUTE_IOCTL_GETDEVSTATIS

typedef struct 
{

    unsigned long ulCmd;
    long lResult;              /* wl add .2008-03-14 */
    unsigned long ulSize;
    unsigned long ulOffset; /* how many should skipped */
    unsigned long ulMaxNum;
    union
    {
        MESH_DEV_CFG_T stDevCfg;         
        AODV_NEIGHBOR_LIST_T    stNeighList;
        MESH_ROUTE_PATH_END_INFO_LIST stRtPathList;
        T_routerNetSetup stNetCfg;        
        T_routerNodeSetup stNodeCfg;
        T_routerNeighSetup stNeiCfg;
        T_routerDynamicSetup stRouteCfg;
        T_routerHandoverSetup stHandoverCfg;
        T_routerMscSetup stMsCfg;
        EVENT_TRAP_MSG_LIST_T stEvtList;
        AODV_NODEINFO_T stNodeInfo;
        AODV_DEV_STATIS_LIST_T stStatisList;   
        MESH_DEV_STATIS_T stDevStatis;
    }u;
}AODV_ROUTE_IOCTL_T;

/***************************路由模块相关定义end*****************************/

#undef __u32
#undef __s32
#undef __u16
#undef __s16
#undef __u8 

#endif
#endif /* _AC_DEVM_IOCTL_H */
/******************************* 头文件结束 **********************************/


