/*******************************************************************************
* COPYRIGHT GBCOM
********************************************************************************
* 文件内容: 环境变量模块
* 修改历史: 
* 
*******************************************************************************/

#ifndef  __ENVCTL_UPLEVEL_H__
#define  __ENVCTL_UPLEVEL_H__

/* MAX_NAME_LEN已经被定义，加上DRIVER前缀 */
#define DRIVER_MAX_NAME_LEN     20
#define MAX_VALUE_LEN 100

#define DRIVER_OK_V     1
#define DRIVER_OK         0  
#define DRIVER_ERR     -1

#define BOOT_FLASH_1  1
#define BOOT_FLASH_2  2

#define VERSION_CHECK_OVER      0  
#define VERSION_CHECK_BEGIN     1

#define MAIN_ENV_FLAG           1
#define BANK_ENV_FLAG           0

#define BOOTCMD_IMAGE_FLASH_1_RAMDISK_FLASH_1   "cp.b 51600000 2000000 a00000 ; cp.b 51100000 3000000 200000 ; go 3000000"
#define BOOTCMD_IMAGE_FLASH_1_RAMDISK_FLASH_2   "cp.b 52600000 2000000 a00000 ; cp.b 51100000 3000000 200000 ; go 3000000"
#define BOOTCMD_IMAGE_FLASH_2_RAMDISK_FLASH_2   "cp.b 52600000 2000000 a00000 ; cp.b 52100000 3000000 200000 ; go 3000000"
#define BOOTCMD_IMAGE_FLASH_2_RAMDISK_FLASH_1   "cp.b 51600000 2000000 a00000 ; cp.b 52100000 3000000 200000 ; go 3000000"
#define BOOTCMD_TFTPBOOT                                              "tftpboot 2000000 ramdisk.gz ; tftpboot 3000000 zImage ; go 3000000"

#define BOOTCMD_SCRIPT_IMAGE_FLASH_1_RAMDISK_FLASH_1     "tftpboot 7FFFC00 default.img ; tftpboot 1000000 bootscript.img ; autoscr 0x1000000 ; cp.b 51600000 2000000 a00000 ; cp.b 51100000 3000000 200000 ; go 3000000"
#define BOOTCMD_SCRIPT_IMAGE_FLASH_1_RAMDISK_FLASH_2	 "tftpboot 7FFFC00 default.img ; tftpboot 1000000 bootscript.img ; autoscr 0x1000000 ; cp.b 52600000 2000000 a00000 ; cp.b 51100000 3000000 200000 ; go 3000000"
#define BOOTCMD_SCRIPT_IMAGE_FLASH_2_RAMDISK_FLASH_1     "tftpboot 7FFFC00 default.img ; tftpboot 1000000 bootscript.img ; autoscr 0x1000000 ; cp.b 52600000 2000000 a00000 ; cp.b 52100000 3000000 200000 ; go 3000000"
#define BOOTCMD_SCRIPT_IMAGE_FLASH_2_RAMDISK_FLASH_2     "tftpboot 7FFFC00 default.img ; tftpboot 1000000 bootscript.img ; autoscr 0x1000000 ; cp.b 51600000 2000000 a00000 ; cp.b 52100000 3000000 200000 ; go 3000000"

#define IMAGE_ADDR_FLASH_1                       "51100000"
#define RAMDISK_ADDR_FLASH_1                     "51600000"
#define IMAGE_ADDR_FLASH_2                       "52100000"
#define RAMDISK_ADDR_FLASH_2                     "52600000"


#define BOARD_1   0x1
#define BOARD_0   0xf

#define ENV_DEVICE_NAME_1      "/dev/mtd6"
#define ENV_DEVICE_NAME_2      "/dev/mtd7"  

#define	CFG_ENV_SIZE		(0x2000)	/* Total Size of Environment Sector	*/

#define BRD_IOCTL_GETVERSION  0

typedef struct environment_s {
	unsigned long crc;			/* CRC32 over data bytes    */
	unsigned char flags;			/* active or obsolete */
  unsigned char data[CFG_ENV_SIZE-5];
} env_t;

typedef struct 
{    
     int namelen;
     char name[DRIVER_MAX_NAME_LEN];
     int valuelen;
     char value[MAX_VALUE_LEN];
}  DRIVER_ENVCTL_ENVDATE_T;

 
void envctl_printenv(void);
int envctl_setenv(DRIVER_ENVCTL_ENVDATE_T *stUserDate);
void envctl_getenv(DRIVER_ENVCTL_ENVDATE_T *stUserDate,unsigned char ucEnvFlag);
int envctl_upbankenv(void);

int driver_envctl_setenv_image_flash(unsigned char bootflash);
int driver_envctl_setenv_ramdisk_flash(unsigned char bootflash);
int driver_envctl_get_image_flash(void);
int driver_envctl_get_ramdisk_flash(void);
int driver_envctl_setenv_versioncheck(unsigned char versioncheck,unsigned char checktime);
int driver_envctl_get_bootversion(char *pcbootver);

#endif/*  __ENVCTL_UPLEVEL_H__*/

