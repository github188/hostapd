/*
 */

#ifndef _L2WD_APP_H
#define _L2WD_APP_H

extern void l2wd_IpcRcvFunc(unsigned short wEvent, 
	unsigned char* pbyBody, 
	unsigned short wLen, 
	unsigned char* pbyOutBody, 
	unsigned short *pwOutLen);
#endif

