/*
 * wpa_supplicant/hostapd - Build time configuration defines
 * Copyright (c) 2005-2006, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 *
 * This header file can be used to define configuration defines that were
 * originally defined in Makefile. This is mainly meant for IDE use or for
 * systems that do not have suitable 'make' tool. In these cases, it may be
 * easier to have a single place for defining all the needed C pre-processor
 * defines.
 */

#ifndef BUILD_CONFIG_H
#define BUILD_CONFIG_H

/* Insert configuration defines, e.g., #define EAP_MD5, here, if needed. */

#ifdef CONFIG_WIN32_DEFAULTS
#ifdef _MSC_VER
#define CONFIG_NATIVE_WINDOWS
#endif
#define CONFIG_ANSI_C_EXTRA
#define CONFIG_WINPCAP
#define IEEE8021X_EAPOL
#if 0
#define EAP_TLS_FUNCS
#define PKCS12_FUNCS
#endif
#define PCSC_FUNCS
#define CONFIG_CTRL_IFACE
//#define CONFIG_CTRL_IFACE_NAMED_PIPE
//#define CONFIG_DRIVER_NDIS
//#define CONFIG_NDIS_EVENTS_INTEGRATED
#define CONFIG_DEBUG_FILE
#if 0
#define EAP_MD5
#define EAP_TLS
#define EAP_MSCHAPv2
#define EAP_PEAP
#define EAP_TTLS
#define EAP_GTC
#define EAP_OTP
#define EAP_LEAP
#endif
#define _CRT_SECURE_NO_DEPRECATE

#ifdef CONFIG_EAP_MD5
#define EAP_MD5
#endif

#ifdef CONFIG_EAP_TLS
#define EAP_TLS
#define TLS_FUNCS
#endif

#ifdef CONFIG_EAP_PEAP
#define EAP_PEAP
#define TLS_FUNCS
#define CONFIG_EAP_TLV
#define CONFIG_EAP_MSCHAPV2
#endif

#ifdef CONFIG_EAP_TTLS
#define EAP_TTLS
#define TLS_FUNCS
#endif

#ifdef CONFIG_EAP_MSCHAPV2
#define EAP_MSCHAPv2
#define MS_FUNCS
#endif

#ifdef CONFIG_EAP_GTC
#define EAP_GTC
#endif

#ifdef CONFIG_EAP_SIM
#define EAP_SIM
#define CONFIG_EAP_SIM_COMMON
#endif

#ifdef CONFIG_EAP_AKA
#define EAP_AKA
#define CONFIG_EAP_SIM_COMMON
#endif

#ifdef CONFIG_EAP_PAX
#define EAP_PAX
#endif

#ifdef CONFIG_EAP_PSK
#define EAP_PSK
#endif

#ifdef CONFIG_EAP_SAKE
#define EAP_SAKE
#endif

#ifdef CONFIG_EAP_GPSK
#define EAP_GPSK
#ifdef CONFIG_EAP_GPSK_SHA256
#define EAP_GPSK_SHA256
#define NEED_SHA256
#endif
#endif

#ifdef CONFIG_EAP_VENDOR_TEST
#define EAP_VENDOR_TEST
#endif

#ifdef CONFIG_EAP_TLV
#define EAP_TLV
#endif

#ifdef CONFIG_EAP
#define EAP_SERVER
#endif

#ifndef CONFIG_TLS
#define CONFIG_TLS	openssl
#endif

#ifdef TLS_FUNCS
#define EAP_TLS_FUNCS
#if (CONFIG_TLS == openssl)
#pragma message("openssl: need load some lib.\n")
#endif
#if (CONFIG_TLS == gnutls)
#pragma message("gnutls: need load som lib.\n")
#endif
#ifdef CONFIG_GNUTLS_EXTRA
#define CONFIG_GNUTLS_EXTRA
#endif
#define NEED_CRYPTO
#else
#define EAP_TLS_NONE
//#pragma message("tls_none.\n")
#endif

#ifdef CONFIG_PKCS12
#define PKCS12_FUNCS
#endif

#ifdef MS_FUNCS
#define NEED_CRYTO
#endif

#ifdef NEED_CRYPTO
#ifndef TLS_FUNCS
#if (CONFIG_TLS == openssl)
#pragma message("openssl: need load crypto.lib.\n")
#endif
#if (CONFIG_TLS == gnutls)
#pragma message("gnutls: need load gcrypto.lib.\n")
#endif
#endif

#if (CONFIG_TLS == openssl)
#pragma message("openssl: need load crypto.lib.\n")
#define CONFIG_INTERNAL_SHA256
#endif
#if (CONFIG_TLS == gnutls)
#pragma message("gnutls: need load gcrypto.lib.\n")
#define CONFIG_INTERNAL_SHA256
#endif

#else
#define CONFIG_INTERNAL_AES
#define CONFIG_INTERNAL_SHA1
#define CONFIG_INTERNAL_MD5
#define CONFIG_INTERNAL_SHA256
#endif

#ifdef CONFIG_INTERNAL_AES
#define INTERNAL_AES
#endif
#ifdef CONFIG_INTERNAL_SHA1
#define INTERNAL_SHA1
#endif
#ifdef CONFIG_INTERNAL_SHA256
#define INTERNAL_SHA256
#endif
#ifdef CONFIG_INTERNAL_MD5
#define INTERNAL_MD5
#endif

#ifdef CONFIG_INTERNAL_MD4
#define INTERNAL_MD4
#endif

#ifdef CONFIG_RADIUS_SERVER
#define RADIUS_SERVER
#endif

#ifdef CONFIG_IPV6
#define CONFIG_IPV6
#endif

#endif /* CONFIG_WIN32_DEFAULTS */

#endif /* BUILD_CONFIG_H */
