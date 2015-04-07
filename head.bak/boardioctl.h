/*******************************************************************************
* COPYRIGHT GBCOM
********************************************************************************
* 文件内容: 单板board模块
* 修改历史: 
*******************************************************************************/
#ifndef __BOARD_IOCTL_H__
#define __BOARD_IOCTL_H__

#define BRD_IOCTL_GETVERSION 0
#define MEMORYDISPLY 1
#define MEMWRITE_L 2
#define MEMWRITE_B 3
#define MEM_TEST_START 4
#define MEM_TEST_END 5
#define FEEDWDTSTOP 6
#define HARD_RST_BY_CPLD 7
#define GET_REC_COF_STA 8            
#define BOARD_RESET     9
#define GET_CPLD_VERSION 10

/* added by laiyongxing at 2009-02-25 */
#define GET_WIFI_CARD_STAT 11
#define GET_DEFAULT_SCRIPT 12

typedef struct 
{         
	 int Index;	
	 int CardStat[4];	 
}  WIFI_CARD_STAT;

//end addition

typedef struct 
{
    unsigned long m_ulPhyaddress;
    unsigned long value;
}  MWLDATE_T;

typedef struct 
{
    unsigned long m_ulPhyaddress;
    unsigned char value;
} MWBDATE_T;
       
#endif
/* BOARD_IOCTL_H*/
