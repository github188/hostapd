/*
 * Event loop based on select() loop
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

#include "includes.h"

#include "wireless_copy.h"
#include "hostapd.h"
#include "common.h"
#include "eloop.h"
#include "HostapdSocket.h"

#include "OssUtility.h"
#include "OssVos.h"


struct eloop_sock {
	int sock;
	void *eloop_data;
	void *user_data;
	eloop_sock_handler handler;
};

struct eloop_timeout {
	struct os_time time;
	void *eloop_data;
	void *user_data;
	eloop_timeout_handler handler;
	struct eloop_timeout *next;
};

struct eloop_signal {
	int sig;
	void *user_data;
	eloop_signal_handler handler;
	int signaled;
};

struct eloop_sock_table {
	int count;
	struct eloop_sock *table;
	int changed;
	OSTOKEN mutex ;
};

struct eloop_data {
	void *user_data;

	int max_sock;

	struct eloop_sock_table readers;
	struct eloop_sock_table writers;
	struct eloop_sock_table exceptions;

	struct eloop_timeout *timeout;

	int signal_count;
	struct eloop_signal *signals;
	int signaled;
	int pending_terminate;

	int terminate;
	int reader_table_changed;
	unsigned long timer_counter;  /*counter of timeout (timer)*/
};

static struct eloop_data eloop;


int eloop_init(void *user_data)
{
	os_memset(&eloop, 0, sizeof(eloop));
	eloop.user_data = user_data;

	if(! OsCreateSemaphore(NULL, 0, 0, SEM_MUTEX, & eloop.readers.mutex)
		|| ! OsCreateSemaphore(NULL, 0, 0, SEM_MUTEX, & eloop.writers.mutex)
		|| ! OsCreateSemaphore(NULL, 0, 0, SEM_MUTEX, & eloop.exceptions.mutex)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsCreateSemaphore failed.\n", __func__) ;
		return -1 ;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, background, init success.\n", __func__) ;

	return 0;
}

static int eloop_sock_table_add_sock(struct eloop_sock_table *table,
                                     int sock, eloop_sock_handler handler,
                                     void *eloop_data, void *user_data)
{
	struct eloop_sock *tmp;

	if (table == NULL)
		return -1;

	if(OsSemaphoreP(table->mutex, WAIT_FOREVER, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreP failed.\n", __func__) ;
		return -1 ;
	}
	tmp = (struct eloop_sock *)
		os_realloc(table->table,
			   (table->count + 1) * sizeof(struct eloop_sock));
	if (tmp == NULL){
		if(OsSemaphoreV(table->mutex, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreV failed.\n", __func__) ;
			return -1 ;
		}
		return -1;
	}

	tmp[table->count].sock = sock;
	tmp[table->count].eloop_data = eloop_data;
	tmp[table->count].user_data = user_data;
	tmp[table->count].handler = handler;
	table->count++;
	table->table = tmp;
	if (sock > eloop.max_sock)
		eloop.max_sock = sock;
	table->changed = 1;
	if(OsSemaphoreV(table->mutex, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreV failed.\n", __func__) ;
		return -1 ;
	}

	return 0;
}

static void eloop_sock_table_remove_sock(struct eloop_sock_table *table,
                                         int sock)
{
	int i;

	if (table == NULL)
		return;

	if(OsSemaphoreP(table->mutex, WAIT_FOREVER, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreP failed.\n", __func__) ;
		return ;
	}
	if(table->table == NULL || table->count == 0){
		if(OsSemaphoreV(table->mutex, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreV failed.\n", __func__) ;
			return ;
		}
		return ;
	}
	
	for (i = 0; i < table->count; i++) {
		if (table->table[i].sock == sock)
			break;
	}
	if (i == table->count){
		if(OsSemaphoreV(table->mutex, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreV failed.\n", __func__) ;
			return ;
		}
		return;
	}
	if (i != table->count - 1) {
		os_memmove(&table->table[i], &table->table[i + 1],
			   (table->count - i - 1) *
			   sizeof(struct eloop_sock));
	}
	table->count--;
	table->changed = 1;
	if(OsSemaphoreV(table->mutex, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreV failed.\n", __func__) ;
		return ;
	}
}

/*注：调用者需作PV互斥保护*/
static void eloop_sock_table_set_fds(struct eloop_sock_table *table,
				     fd_set *fds)
{
	int i;

	FD_ZERO(fds);

	if (table->table == NULL){
		return;
	}

	for (i = 0; i < table->count; i++)
		FD_SET(table->table[i].sock, fds);
}


static void eloop_sock_table_dispatch(struct eloop_sock_table *table,
				      fd_set *fds)
{
	int i;

	if (table == NULL)
		return;

	if(OsSemaphoreP(table->mutex, WAIT_FOREVER, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreP failed.\n", __func__) ;
		return ;
	}
	if(table->table == NULL){
		if(OsSemaphoreV(table->mutex, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreV failed.\n", __func__) ;
			return ;
		}
		return ;
	}
	
	table->changed = 0;
	for (i = 0; i < table->count; i++) {
		if (FD_ISSET(table->table[i].sock, fds)) {
			table->table[i].handler(table->table[i].sock,
						table->table[i].eloop_data,
						table->table[i].user_data);
			if (table->changed)
				break;
		}
	}
	if(OsSemaphoreV(table->mutex, 1) == FALSE){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
			"%s, call OsSemaphoreV failed.\n", __func__) ;
		return ;
	}
}


static void eloop_sock_table_destroy(struct eloop_sock_table *table)
{
	if (table){
		if(OsCloseSemaphore(table->mutex) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsCloseSemaphore failed.\n", __func__) ;
		}
		
		os_free(table->table);
		table->table = NULL ;
	}
}


int eloop_register_read_sock(int sock, eloop_sock_handler handler,
			     void *eloop_data, void *user_data)
{
	return eloop_register_sock(sock, EVENT_TYPE_READ, handler,
				   eloop_data, user_data);
}


void eloop_unregister_read_sock(int sock)
{
	eloop_unregister_sock(sock, EVENT_TYPE_READ);
}


static struct eloop_sock_table *eloop_get_sock_table(eloop_event_type type)
{
	switch (type) {
	case EVENT_TYPE_READ:
		return &eloop.readers;
	case EVENT_TYPE_WRITE:
		return &eloop.writers;
	case EVENT_TYPE_EXCEPTION:
		return &eloop.exceptions;
	}

	return NULL;
}


int eloop_register_sock(int sock, eloop_event_type type,
			eloop_sock_handler handler,
			void *eloop_data, void *user_data)
{
	struct eloop_sock_table *table;

	table = eloop_get_sock_table(type);
	return eloop_sock_table_add_sock(table, sock, handler,
					 eloop_data, user_data);
}


void eloop_unregister_sock(int sock, eloop_event_type type)
{
	struct eloop_sock_table *table;

	table = eloop_get_sock_table(type);
	eloop_sock_table_remove_sock(table, sock);
}

#if 1
/*立即向HOSTAPD线程发送超时消息*/
extern BOOL VmGetLocalPid (CHAR *lpbyPName, TPID *lptPid);
static int eloop_set_timer_imm(VOID)
{
	TPID tReceiver = {0} ;
	char buf[4] = {0} ;
		
	if(! VmGetLocalPid("AppHostapdProc", & tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
			"%s, get local tpid failed.\n", __func__) ;
		return  -1 ;
	}
		
	if(! VmASend(EV_HOSTAPD_TIMER, (BYTE *)buf ,sizeof(buf),  tReceiver)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
			"%s, send EV_HOSTAPD_TIMER failed.\n", __func__) ;
		return -1 ;
	}

	return 0 ;
}


static int eloop_update_timer(int bTimerOut)
{
	static int timer_set = 0 ;

	if(bTimerOut){
		timer_set = 0 ;
	}
	else if(timer_set){
		if(VmKillTimer(TIMER_HOSTAPD) == TRUE)
			timer_set = 0 ;
		else{
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
				"%s, timer_set :%d.\n", __func__,timer_set) ;
			return -1 ;
		}
	}

	if(eloop.timeout){
		struct os_time now, timeout ;
		long count_100ms ;
	
		os_get_time(& now) ;
		os_time_sub(& eloop.timeout->time, & now, & timeout) ;

		count_100ms = 10 * timeout.sec + timeout.usec/100000 ;
		if(timeout.usec % 100000)
			count_100ms ++ ;
#if 0
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL, 
			"%s, now(%u.%06u s), next timeout(%u.%06u s), count_100ms(%u).\n",
			__func__, now.sec, now.usec, eloop.timeout->time.sec, eloop.timeout->time.usec, count_100ms) ;
#endif
		if(count_100ms <= 0){
			eloop_set_timer_imm() ;
		}
		else{
			if(VmSetTimer(count_100ms, TIMER_HOSTAPD) != TID_ERROR){
				timer_set = 1 ;
			}
			else{
				ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL, 
					"%s, set HOSTAPD timer(%d*100ms) failed.\n", __func__, count_100ms) ;
				return -1 ;
			}
		}
	}

	return 0 ;
}


int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data)
{
	struct eloop_timeout *timeout, *tmp, *prev;
	int update_timer = 0 ;
	int update_ret=0;
	struct os_time now;
	timeout = os_malloc(sizeof(*timeout));
	if (timeout == NULL){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL, 
			"%s, os_malloc failed.\n", __func__) ;
		return -1 ;
	}
	os_get_time(&timeout->time);
	os_get_time(&now);
	timeout->time.sec += secs;
	timeout->time.usec += usecs;
	while (timeout->time.usec >= 1000000) {
		timeout->time.sec++;
		timeout->time.usec -= 1000000;
	}
	timeout->eloop_data = eloop_data;
	timeout->user_data = user_data;
	timeout->handler = handler;
	timeout->next = NULL;

	if (eloop.timeout == NULL) {
		eloop.timeout = timeout;
		update_timer = 1 ;
	}
	else{
		tmp = eloop.timeout;
		#if 0
		while (tmp != NULL) {
			if (! os_time_before(&now,&tmp->time )){
				eloop.timeout = tmp->next;
				tmp->handler(tmp->eloop_data, tmp->user_data);
				os_free(tmp);
				tmp = eloop.timeout; 
				update_timer = 1 ;
			} else {
				break;
			}
		}
		#else
		if (tmp != NULL) {
			if (! os_time_before(&now,&tmp->time )){
				update_timer = 1 ;
			}
		}
		#endif
		prev = NULL;
		tmp = eloop.timeout;
		while (tmp != NULL) {
			if (os_time_before(&timeout->time, &tmp->time))
				break;
			prev = tmp;
			tmp = tmp->next;
		}

		if (prev == NULL) {
			timeout->next = eloop.timeout;
			eloop.timeout = timeout;
			update_timer = 1 ;
		} else {
			timeout->next = prev->next;
			prev->next = timeout;
		}
	}
	eloop.timer_counter++;
	if(update_timer
		&& ((update_ret = eloop_update_timer(0)) != 0)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_ERROR, 
			"%s,update_timer : %d ,update_ret : %d.\n", __func__,update_timer,update_ret) ;
		return -1 ;
	}
	
	return 0;
}


int eloop_cancel_timeout(eloop_timeout_handler handler,
			 void *eloop_data, void *user_data)
{
	struct eloop_timeout *timeout, *prev, *next;
	int removed = 0;

	prev = NULL;
	timeout = eloop.timeout;
	while (timeout != NULL) {
		next = timeout->next;

		if (timeout->handler == handler &&
		    (timeout->eloop_data == eloop_data ||
		     eloop_data == ELOOP_ALL_CTX) &&
		    (timeout->user_data == user_data ||
		     user_data == ELOOP_ALL_CTX)) {
			if (prev == NULL)
				eloop.timeout = next;
			else
				prev->next = next;
			eloop.timer_counter--; /*counter decrease*/
			os_free(timeout);
			removed++;
		} else
			prev = timeout;

		timeout = next;
	}

	return removed;
}


int OnHostapdTimer(unsigned short wEvent, void * pbyData, unsigned short wLen)
{
	struct os_time now ;
	int res = 0 ;
	
	if (eloop.timeout) {
		struct eloop_timeout *tmp;

		os_get_time(& now);
		#if 1
		if (!os_time_before(& now, & eloop.timeout->time)) {
			tmp = eloop.timeout;
			eloop.timeout = eloop.timeout->next;
			eloop.timer_counter--; 
			res = eloop_update_timer(wEvent == EV_TIMER_HOSTAPD ? 1 : 0) ;
			tmp->handler(tmp->eloop_data, tmp->user_data);
			os_free(tmp);
		}
		else{
			res = eloop_update_timer(wEvent == EV_TIMER_HOSTAPD ? 1 : 0) ;
		}
		#else
		tmp = eloop.timeout;
		while (tmp != NULL) {
			if (!os_time_before(& now, & eloop.timeout->time)) {
				eloop.timeout = eloop.timeout->next;
				eloop.timer_counter--; /*counter decrease*/
				//res = eloop_update_timer(wEvent == EV_TIMER_HOSTAPD ? 1 : 0) ;
				tmp->handler(tmp->eloop_data, tmp->user_data);
				os_free(tmp);
				tmp = eloop.timeout;
			} else {
				break; 
			}
		}
		res = eloop_update_timer(wEvent == EV_TIMER_HOSTAPD ? 1 : 0) ;
		#endif
	}

	return res ;
}
#else
struct HOSTAPD_TIMER_T
{
	u16 usTid ;
	struct eloop_timeout stTimeOut ;
	struct HOSTAPD_TIMER_T * pstNext ;
} ;

/*HASH存储：HASH(HOSTAPD_TIMER_T)=(((u32)stTimerOut.handler)/4)%1000*/
#define EX_TIMERS	1000
static struct HOSTAPD_TIMER_T * g_pstTimerTable[EX_TIMERS] = {NULL} ;

void DumpTimerList()
{
	int i ;

	for(i = 0 ; i < EX_TIMERS ; i ++){
		struct HOSTAPD_TIMER_T * pstTimer = g_pstTimerTable[i] ;

		while(pstTimer){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
				"HostapdTimerList[%u](tid: %u, %u.%6u s): \n"
				"--handler(%pH), eloop_data(%pH), user_data(%pH).\n",
				i, pstTimer->usTid, pstTimer->stTimeOut.time.sec, pstTimer->stTimeOut.time.usec, pstTimer->stTimeOut.handler, pstTimer->stTimeOut.eloop_data, pstTimer->stTimeOut.user_data) ;
			pstTimer = pstTimer->pstNext ;
		}
	}
}

/*从HASH表中移出定时器，但不释放*/
static int eloop_unregister_timeout(eloop_timeout_handler handler, u16 tid)
{
	struct HOSTAPD_TIMER_T * pstTimeOut, * pstPrev, * pstNext ;
	int hash = (((u32)handler) / 4) % EX_TIMERS ;
	int removed = 0 ;

	pstPrev = NULL ;
	pstTimeOut = g_pstTimerTable[hash] ;
	while(pstTimeOut){
		pstNext = pstTimeOut->pstNext ;

		if(pstTimeOut->stTimeOut.handler == handler
			&& pstTimeOut->usTid == tid){
			if(pstPrev == NULL)
				g_pstTimerTable[hash] = pstNext ;
			else
				pstPrev->pstNext = pstNext ;

			removed ++ ;
		}
		else
			pstPrev = pstTimeOut ;

		pstTimeOut = pstNext ;
	}

	return removed ;
}

int OnHostapdTimer(unsigned short wEvent, void * pbyData, unsigned short wLen)
{
	struct HOSTAPD_TIMER_T * pstTimer = NULL ;
	unsigned long dwExtra = 0 ;

	if(pbyData == NULL
		|| wLen < sizeof(dwExtra)){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FAIL,
			"%s, point is NULL, or wLen(%d) is too short.\n", __func__, wLen) ;
		return -1 ;
	}

	os_memcpy(& dwExtra, pbyData, sizeof(dwExtra)) ;
	pstTimer = (struct HOSTAPD_TIMER_T *)dwExtra ;

#if 0
	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_DETAIL,
		"%s, process hostapd timer(tid: %u, %u.%6u s): \n"
		"--handler(%pH), eloop_data(%pH), user_data(%pH).\n",
		__func__, pstTimer->usTid, pstTimer->stTimeOut.time.sec, pstTimer->stTimeOut.time.usec, pstTimer->stTimeOut.handler, pstTimer->stTimeOut.eloop_data, pstTimer->stTimeOut.user_data) ;
#endif
	eloop_unregister_timeout(pstTimer->stTimeOut.handler, pstTimer->usTid) ;
	pstTimer->stTimeOut.handler(pstTimer->stTimeOut.eloop_data, pstTimer->stTimeOut.user_data) ;
	os_free(pstTimer) ;

	return 0 ;
}

int eloop_register_timeout(unsigned int secs, unsigned int usecs,
			   eloop_timeout_handler handler,
			   void *eloop_data, void *user_data)
{
	struct HOSTAPD_TIMER_T * pstTimer = NULL ;
	u32 dwCount100ms , dwExtra ;
	int hash ;

	if((pstTimer = os_zalloc(sizeof(struct HOSTAPD_TIMER_T))) == NULL)
		return -1 ;

	os_get_time(&pstTimer->stTimeOut.time);
	pstTimer->stTimeOut.time.sec += secs;
	pstTimer->stTimeOut.time.usec += usecs;
	while (pstTimer->stTimeOut.time.usec >= 1000000) {
		pstTimer->stTimeOut.time.sec++;
		pstTimer->stTimeOut.time.usec -= 1000000;
	}
	pstTimer->stTimeOut.handler = handler ;
	pstTimer->stTimeOut.eloop_data = eloop_data ;
	pstTimer->stTimeOut.user_data = user_data ;

	/*插入HASH表*/
	hash = (((u32)handler) / 4) % EX_TIMERS ;
	pstTimer->pstNext = g_pstTimerTable[hash] ;
	g_pstTimerTable[hash] = pstTimer ;

	/*启动定时器*/
	dwCount100ms = 10 * secs + usecs / 100000 ;
	if(dwCount100ms == 0)
		dwCount100ms = 1 ;

	dwExtra = (u32)pstTimer ;

	pstTimer->usTid = VmSetTimerEx(dwCount100ms, TIMER_HOSTAPD, dwExtra) ;
	if(pstTimer->usTid == TID_ERROR){
		ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call VmSetTimerEx failed.\n", __func__) ;
		g_pstTimerTable[hash] = pstTimer->pstNext ;
		os_free(pstTimer) ;
		return -1 ;
	}

	return 0 ;
}

/*从HASH表中删除定时器，若该定时器未被停止，则停止*/
int eloop_cancel_timeout(eloop_timeout_handler handler,
			 void *eloop_data, void *user_data)
{
	struct HOSTAPD_TIMER_T * pstTimeOut, * pstPrev, * pstNext ;
	int hash = (((u32)handler) / 4) % EX_TIMERS ;
	int removed = 0 ;

	pstPrev = NULL ;
	pstTimeOut = g_pstTimerTable[hash] ;
	while(pstTimeOut){
		pstNext = pstTimeOut->pstNext ;

		if(pstTimeOut->stTimeOut.handler == handler
			&& (pstTimeOut->stTimeOut.eloop_data == eloop_data ||  eloop_data == ELOOP_ALL_CTX)
			&& (pstTimeOut->stTimeOut.user_data == user_data || user_data == ELOOP_ALL_CTX)){
			if(pstPrev == NULL)
				g_pstTimerTable[hash] = pstNext ;
			else
				pstPrev->pstNext = pstNext ;

			/*删除该定时器*/
			if(pstTimeOut->usTid != TID_ERROR)
				VmKillTimerEx(pstTimeOut->usTid) ;
			os_free(pstTimeOut) ;
			removed ++ ;
		}
		else
			pstPrev = pstTimeOut ;

		pstTimeOut = pstNext ;
	}

	return removed ;
}
#endif

#ifndef CONFIG_NATIVE_WINDOWS
static void eloop_handle_alarm(int sig)
{
	fprintf(stderr, "eloop: could not process SIGINT or SIGTERM in two "
		"seconds. Looks like there\n"
		"is a bug that ends up in a busy loop that "
		"prevents clean shutdown.\n"
		"Killing program forcefully.\n");
	exit(1);
}
#endif /* CONFIG_NATIVE_WINDOWS */


static void eloop_handle_signal(int sig)
{
	int i;

#ifndef CONFIG_NATIVE_WINDOWS
	if ((sig == SIGINT || sig == SIGTERM) && !eloop.pending_terminate) {
		/* Use SIGALRM to break out from potential busy loops that
		 * would not allow the program to be killed. */
		eloop.pending_terminate = 1;
		signal(SIGALRM, eloop_handle_alarm);
		alarm(2);
	}
#endif /* CONFIG_NATIVE_WINDOWS */

	eloop.signaled++;
	for (i = 0; i < eloop.signal_count; i++) {
		if (eloop.signals[i].sig == sig) {
			eloop.signals[i].signaled++;
			break;
		}
	}
}


static void eloop_process_pending_signals(void)
{
	int i;

	if (eloop.signaled == 0)
		return;
	eloop.signaled = 0;

	if (eloop.pending_terminate) {
#ifndef CONFIG_NATIVE_WINDOWS
		alarm(0);
#endif /* CONFIG_NATIVE_WINDOWS */
		eloop.pending_terminate = 0;
	}

	for (i = 0; i < eloop.signal_count; i++) {
		if (eloop.signals[i].signaled) {
			eloop.signals[i].signaled = 0;
			eloop.signals[i].handler(eloop.signals[i].sig,
						 eloop.user_data,
						 eloop.signals[i].user_data);
		}
	}
}


int eloop_register_signal(int sig, eloop_signal_handler handler,
			  void *user_data)
{
	struct eloop_signal *tmp;

	tmp = (struct eloop_signal *)
		os_realloc(eloop.signals,
			   (eloop.signal_count + 1) *
			   sizeof(struct eloop_signal));
	if (tmp == NULL)
		return -1;

	tmp[eloop.signal_count].sig = sig;
	tmp[eloop.signal_count].user_data = user_data;
	tmp[eloop.signal_count].handler = handler;
	tmp[eloop.signal_count].signaled = 0;
	eloop.signal_count++;
	eloop.signals = tmp;
	signal(sig, eloop_handle_signal);

	return 0;
}


int eloop_register_signal_terminate(eloop_signal_handler handler,
				    void *user_data)
{
	int ret = eloop_register_signal(SIGINT, handler, user_data);
	if (ret == 0)
		ret = eloop_register_signal(SIGTERM, handler, user_data);
	return ret;
}


int eloop_register_signal_reconfig(eloop_signal_handler handler,
				   void *user_data)
{
#ifdef CONFIG_NATIVE_WINDOWS
	return 0;
#else /* CONFIG_NATIVE_WINDOWS */
	return eloop_register_signal(SIGHUP, handler, user_data);
#endif /* CONFIG_NATIVE_WINDOWS */
}


void eloop_run(void)
{
	fd_set *rfds, *wfds, *efds;
	int res;
	struct timeval _tv_default ;
	/* struct os_time tv, now; */

	rfds = os_malloc(sizeof(*rfds));
	wfds = os_malloc(sizeof(*wfds));
	efds = os_malloc(sizeof(*efds));
	if (rfds == NULL || wfds == NULL || efds == NULL) {
		printf("eloop_run - malloc failed\n");
		goto out;
	}

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, background, enter eloop.\n", __func__) ;

	while (!eloop.terminate) {
#if 0
		if (eloop.timeout) {
			os_get_time(&now);
			if (os_time_before(&now, &eloop.timeout->time))
				os_time_sub(&eloop.timeout->time, &now, &tv);
			else
				tv.sec = tv.usec = 0;
#if 0
			printf("next timeout in %lu.%06lu sec\n",
			       tv.sec, tv.usec);
#endif
			_tv.tv_sec = tv.sec;
			_tv.tv_usec = tv.usec;
		}
#endif

		_tv_default.tv_sec = 0 ;
		_tv_default.tv_usec = 100 ;

		if(OsSemaphoreP(eloop.readers.mutex, WAIT_FOREVER, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreP failed.\n", __func__) ;
			continue ;
		}
		
		eloop_sock_table_set_fds(&eloop.readers, rfds);
		eloop_sock_table_set_fds(&eloop.writers, wfds);
		eloop_sock_table_set_fds(&eloop.exceptions, efds);

		if(OsSemaphoreV(eloop.readers.mutex, 1) == FALSE){
			ModuleLogMsg(APP_MODULE_HOSTAPD, APP_FATAL,
				"%s, call OsSemaphoreV failed.\n", __func__) ;
			continue ;
		}
#if 0
		res = select(eloop.max_sock + 1, rfds, wfds, efds,
			     eloop.timeout ? &_tv : & _tv_default);
#else
		res = select(eloop.max_sock + 1, rfds, wfds, efds, & _tv_default);
#endif

		if (res < 0 && errno != EINTR && errno != 0) {
			//perror("select");
			//goto out;
			continue ;
		}
		eloop_process_pending_signals();
#if 0
		/* check if some registered timeouts have occurred */
		if (eloop.timeout) {
			struct eloop_timeout *tmp;

			os_get_time(&now);
			if (!os_time_before(&now, &eloop.timeout->time)) {
				tmp = eloop.timeout;
				eloop.timeout = eloop.timeout->next;
				tmp->handler(tmp->eloop_data,
					     tmp->user_data);
				os_free(tmp);
			}

		}
#endif
		if (res <= 0)
			continue;

		eloop_sock_table_dispatch(&eloop.readers, rfds);
		eloop_sock_table_dispatch(&eloop.writers, wfds);
		eloop_sock_table_dispatch(&eloop.exceptions, efds);
	}

out:
	os_free(rfds);
	os_free(wfds);
	os_free(efds);
}


void eloop_terminate(void)
{
	eloop.terminate = 1;
}


void eloop_destroy(void)
{
	struct eloop_timeout *timeout, *prev;

	ModuleLogMsg(APP_MODULE_HOSTAPD, APP_MSG,
		"%s, background, exit eloop.\n", __func__) ;
	
	timeout = eloop.timeout;
	while (timeout != NULL) {
		prev = timeout;
		timeout = timeout->next;
		os_free(prev);
	}
	eloop_sock_table_destroy(&eloop.readers);
	eloop_sock_table_destroy(&eloop.writers);
	eloop_sock_table_destroy(&eloop.exceptions);
	os_free(eloop.signals);
}


int eloop_terminated(void)
{
	return eloop.terminate;
}


void eloop_wait_for_read_sock(int sock)
{
	fd_set rfds;

	if (sock < 0)
		return;

	FD_ZERO(&rfds);
	FD_SET(sock, &rfds);
	select(sock + 1, &rfds, NULL, NULL, NULL);
}


void * eloop_get_user_data(void)
{
	return eloop.user_data;
}
