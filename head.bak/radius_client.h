/*
 * hostapd / RADIUS client
 * Copyright (c) 2002-2005, Jouni Malinen <j@w1.fi>
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

#ifndef RADIUS_CLIENT_H
#define RADIUS_CLIENT_H

#include "config_types.h"

struct radius_msg;

struct hostapd_radius_server {
	/* MIB prefix for shared variables:
	 * @ = radiusAuth or radiusAcc depending on the type of the server */
	struct hostapd_ip_addr addr; /* @ServerAddress */
	int port; /* @ClientServerPortNumber */
	u8 *shared_secret;
	size_t shared_secret_len;

	/* Dynamic (not from configuration file) MIB data */
	int index; /* @ServerIndex */
	int round_trip_time; /* @ClientRoundTripTime; in hundredths of a
			      * second */
	u32 requests; /* @Client{Access,}Requests */
	u32 retransmissions; /* @Client{Access,}Retransmissions */
	u32 access_accepts; /* radiusAuthClientAccessAccepts */
	u32 access_rejects; /* radiusAuthClientAccessRejects */
	u32 access_challenges; /* radiusAuthClientAccessChallenges */
	u32 responses; /* radiusAccClientResponses */
	u32 malformed_responses; /* @ClientMalformed{Access,}Responses */
	u32 bad_authenticators; /* @ClientBadAuthenticators */
	u32 timeouts; /* @ClientTimeouts */
	u32 unknown_types; /* @ClientUnknownTypes */
	u32 packets_dropped; /* @ClientPacketsDropped */
	/* @ClientPendingRequests: length of hapd->radius->msgs for matching
	 * msg_type */
};

struct hostapd_radius_servers {
	/* RADIUS Authentication and Accounting servers in priority order */
	struct hostapd_radius_server *auth_servers, *auth_server;
	int num_auth_servers;
	struct hostapd_radius_server *acct_servers, *acct_server;
	int num_acct_servers;

	int retry_primary_interval;
	int acct_interim_interval;

	int auth_alive_interval ;	/*认证服务器保活时长*/

	int msg_dumps;
	struct hostapd_radius_servers * next;
};


typedef enum {
	RADIUS_AUTH,
	RADIUS_ACCT,
	RADIUS_ACCT_INTERIM /* used only with radius_client_send(); just like
			     * RADIUS_ACCT, but removes any pending interim
			     * RADIUS Accounting packages for the same STA
			     * before sending the new interim update */
} RadiusType;

typedef enum {
	RADIUS_RX_PROCESSED,
	RADIUS_RX_QUEUED,
	RADIUS_RX_UNKNOWN,
	RADIUS_RX_INVALID_AUTHENTICATOR
} RadiusRxResult;

#if 0
struct radius_client_data;
#else

struct radius_rx_handler {
	RadiusRxResult (*handler)(struct radius_msg *msg,
				  struct radius_msg *req,
				  u8 *shared_secret, size_t shared_secret_len,
				  void *data);
	void *data;
};

/* RADIUS message retransmit list */
struct radius_msg_list {
	u8 addr[ETH_ALEN]; /* STA/client address; used to find RADIUS messages
			    * for the same STA. */
	struct radius_msg *msg;
	RadiusType msg_type;
	os_time_t first_try;
	os_time_t next_try;
	int attempts;
	int next_wait;
	struct os_time last_attempt;

	u8 *shared_secret;
	size_t shared_secret_len;

	/*由于接收RADIUS报文与处理RADIUS报文不在同一线程，故增加server_change标志位，避免同步问题*/
	u8 server_changed ;/*0：本包未切换RADIUS SERVER发送；1：已切换RADIUS SERVER*/

	/* TODO: server config with failover to backup server(s) */

	struct radius_msg_list *next;
};

enum{
	RADIUS_TYPE_FOR_VAP,
	RADIUS_TYPE_FOR_ALIVE,
	RADIUS_TYPE_FOR_PPP,
	RADIUS_TYPE_FOR_POOL,
	RADIUS_TYPE_MAX
} ;

struct radius_client_data {
	void *ctx;
	struct hostapd_radius_servers *conf;/*当conf == NULL, 本radius_client_data实例无效*/

	int auth_serv_sock; /* socket for authentication RADIUS messages */
	int acct_serv_sock; /* socket for accounting RADIUS messages */
	int auth_serv_sock6;
	int acct_serv_sock6;
	int auth_sock; /* currently used socket */
	int acct_sock; /* currently used socket */
	int auth_id ;	/*当前连接的认证服务器ID号，0为主用*/
	int acct_id ;	/*当前连接的计费服务器ID号，0为主用*/

	struct radius_rx_handler *auth_handlers;
	size_t num_auth_handlers;
	struct radius_rx_handler *acct_handlers;
	size_t num_acct_handlers;

	struct radius_msg_list *msgs;
	size_t num_msgs;

	u8 next_radius_identifier;
	u32 radius_type ;
	u32 radius_setid;
	u32 radius_poolid ;
	int auth_bind;
};
#endif

extern u8 g_aucNasIp[4];

int radius_client_register(struct radius_client_data *radius,
			   RadiusType msg_type,
			   RadiusRxResult (*handler)
			   (struct radius_msg *msg, struct radius_msg *req,
			    u8 *shared_secret, size_t shared_secret_len,
			    void *data),
			   void *data);
int radius_client_send(struct radius_client_data *radius,
		       struct radius_msg *msg,
		       RadiusType msg_type, const u8 *addr);
u8 radius_client_get_id(struct radius_client_data *radius);

void radius_client_flush(struct radius_client_data *radius, int only_auth);
struct radius_client_data *
radius_client_init(void *ctx, struct hostapd_radius_servers *conf, u32 type);
void radius_client_deinit(struct radius_client_data *radius);
void radius_client_flush_auth(struct radius_client_data *radius, u8 *addr);
int radius_client_get_mib(struct radius_client_data *radius, char *buf,
			  size_t buflen);
struct radius_client_data *
radius_client_reconfig(struct radius_client_data *old, void *ctx,
		       struct hostapd_radius_servers *oldconf,
		       struct hostapd_radius_servers *newconf);

void radius_client_receiveA(void *eloop_ctx, void *sock_ctx, u8 * pRadiusData, int iRadiusDataLen) ;
int radius_client_init_acct(struct radius_client_data *radius, int keep_old);
int radius_client_init_auth(struct radius_client_data *radius, int keep_old);
void radius_retry_primary_timer(void *eloop_ctx, void *timeout_ctx) ;

int
radius_change_server(struct radius_client_data *radius,
		     struct hostapd_radius_server *nserv,
		     struct hostapd_radius_server *oserv,
		     int sock, int sock6, int auth) ;
int radius_change_server_global(struct hostapd_radius_server *nserv,
		     struct hostapd_radius_server *oserv, int auth) ;
int radius_client_pool_reset(struct radius_client_data ** radius_client_pool) ;
int radius_client_pool_change(struct radius_client_data ** radius_client_pool, struct hostapd_radius_server *nserv, struct hostapd_radius_server *oserv,int auth) ;
struct radius_client_data * radius_client_pool_get(int setid, int index) ;

#endif /* RADIUS_CLIENT_H */
