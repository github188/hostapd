/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
******************************************************************************/

#ifndef L2W_UTIL_H
#define L2W_UTIL_H

/* print level */
#define  L2W_FATAL    		5
#define  L2W_FAIL    			4
#define  L2W_ERROR    		3
#define  L2W_WARNING  		2
#define  L2W_INFO     		1
#define  L2W_DETAIL   		0

extern u32 gulL2wPrintLevel;


#ifdef AC_DEBUG_ON
#define l2w_printk(level, format, arg...) do{\
       if(level >= gulL2wPrintLevel)         \
          printk(format, ##arg);            \
}while(0);
#else
#define l2w_printk(level, format, arg...)
#endif
/* BEGIN: Added by cuiyilong, 2012/4/18 */
//extern void l2w_printcode_debug(unsigned char *p, u32 ulLen);
#ifdef AC_DEBUG_ON
extern void l2w_printcode(unsigned char *p, u32 ulLen, u32 ulLevel);
#else
#define  l2w_printcode(p, ulLen, ulLevel)
#endif
extern char *l2w_inet_ntoa(u32 ina);


#endif

/******************************* end **********************************/

