
#ifndef __WAPI_ELOOP_H__
#define __WAPI_ELOOP_H__

#define ELOOP_ALL_CTX (void *) -1

typedef void (*eloop_sock_handler)(int sock, void *eloop_ctx, void *sock_ctx);

typedef enum {
	EVENT_TYPE_READ = 0,
	EVENT_TYPE_WRITE,
	EVENT_TYPE_EXCEPTION
} eloop_event_type;

struct eloop_sock {
	int sock;
	void *eloop_data;
	void *user_data;
	eloop_sock_handler handler;
};

struct eloop_sock_table {
	int count;
	struct eloop_sock *table;
	int changed;
};

int wapiapd_eloop_register_read_sock(int sock, eloop_sock_handler handler, void *eloop_data, void *user_data);
void wapiapd_eloop_unregister_read_sock(int sock);
void eloop_destroy(void);
void wapiapd_eloop_run(void);

#endif
