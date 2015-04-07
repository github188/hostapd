#ifndef OMA_COMMON_H
#define OMA_COMMON_H

#include "omaDef.h"

#if 0
#ifdef WIN32
#define SYSTEM( c )
#else
/* 2010-3-26 pyy 修改*/
/* #define SYSTEM( c ) {system( c ); OMA_INFO(( "system: %s\n", c )); printf( "system: %s\n", c);}*/
#define SYSTEM( c ) {system( c ); syslog(5,  "system: %s\n", c ); }
#endif
#endif

extern inline int	SYSTEM(char *cmd);

extern LOG_LEVEL_E g_logLevel;
extern unsigned long	gulLogToStdout;

/* 需要特殊处理的名称 */
#define OBJECT_NAME_AP      "ap"
#define OBJECT_NAME_ADHOC   "adhoc"

typedef struct
{
    char                *szObjectName;
    char                *szOid;
} T_omcObjectNameMapId;

/* functions */
void *allocBuf(void);
int omaRegisterHandler(char *oidName, void *nodeHandler);
void getOid(char* handleOid, T_omaOid *oidInfo);
//int initDefaultAction(unsigned long ulActionID, char *oidName);
int initGetHandler(unsigned long ulActionID, void *pGetInfo, unsigned long *pulGetLen, OMA_GET_HANDLER *pfGetHandler);
int initSetHandler(unsigned long ulActionID, OMA_SET_HANDLER *pfSetHandler);
int initConvertFunc(unsigned long ulActionID, ACTION_CONVERT_FUNC *pfConvertFunc);
int setInitFunc(unsigned long ulActionID, ACTION_INIT_FUNC *pfInitFunc);
int getActionID(OID *actionOid, unsigned long oidLen);

void sys_sleep(unsigned long second);

int waitCommand(char *szCommand, ...);
int nowaitCommand(char *szCommand, ...);
void reboot_system(void);
unsigned long getCurrentTime( void );
char* getTextTime(unsigned long *pulCurrTime);
unsigned long getCurrentTicks( void );
void deleteFile(char* file);
void printHexBuffer(void *buf, unsigned long len);
void printDecBuffer(void *buf, unsigned long len);
void printOID(T_omaOid *pstOid);
int setLogLevel(LOG_LEVEL_E logLevel);
int parseFile(char* fullFile, char* path, char *file);
int getFileFromPath(char* path, char *file);
int oma_init_trap(char *community, char *trapHost, unsigned short trapPort);
int oma_create_trap_session(void);
int oma_send_trap_to_omc(void *varList);

void getTextMAC(unsigned char *mac, char* textMAC);
void getTextIP(unsigned char *ip, char* textIP);

int omaLog(LOG_LEVEL_E logLevel, const char *format, ...);
unsigned long getUptime(void);
UINT32 getDeviceType(void);
UINT8 isMasterDeviceType(void);
UINT8 isSlaveDeviceType(void);
//OMA_RET_E omaSlaveNotifyMaster(OMA_SLAVE_NOTIFY_MASTER_T *pstMsg);
int omaMasterQuerySlaveEx(OID * name,
				          unsigned int name_len,
				          unsigned char val_type,
				          UINT32 *val_len,
				          void * data);
OMA_RET_E omaMasterQuerySlave(OMA_MASTER_QUERY_SLAVE_T *pstMsg);
int getVlanObjectID(int vlanId, char* szOid);
int getObjectID(char* szObjectName, char* szOid);
OMA_RET_E oma_log(int iModuleID, int iLogType, int iLogLevel, const char *szLogInfo);
void get_user_snapshot(void);
//char *itoa(int value, char *str, int radix);
void startPowerap(void);
void stopPowerap(void);
int isProcRunning(char *szProcName);
int get_current_acip(unsigned char *pucIP);
unsigned long long u32ToU64(unsigned long ulHigh, unsigned long ulLow);

#endif /* OMA_COMMON_H */



