#include "boardioctl.h"
/*******************************************************************************
* COPYRIGHT GBCOM
********************************************************************************
* 文件内容: 单板board模块
* 修改历史: 
*******************************************************************************/
#ifndef __DRIVER_BOARD_UPLEVEL_H__
#define __DRIVER_BOARD_UPLEVEL_H__

#define DRIVER_BOARD_RECDEFCOFSTA_ENABLE  1
#define DRIVER_BOARD_RECDEFCOFSTA_DISABLE 0

#define SIOCGMIIPHY (SIOCDEVPRIVATE)	/* Read from current PHY */
#define SIOCGETMACSTAT SIOCDEVPRIVATE + 11

#define GET_CPU_RATE 13

/* network interface ioctl's for MII commands */
typedef struct IxpState
{
	int gb_linkUp_0,gb_speed100_0,gb_fullDuplex_0;
	int gb_linkUp_1,gb_speed100_1,gb_fullDuplex_1; 
}IxpState;

/* added by laiyongxing at 2009-2-25 */
int user_get_script(char * buff);
//WIFI_CARD_STAT OamGetCardStat(void);
int OamGetCardStat(WIFI_CARD_STAT *pstWifiCardStat);
int driver_board_get_cpurate(unsigned char  *pucRate);
//end addition

IxpState get_macstate_flag(int skfd);

int user_get_board_version(void);
unsigned char driver_board_get_recdefcofstatus(void);
double user_get_board_temperature(void);

#endif
/* __DRIVER_BOARD_UPLEVEL_H__*/
