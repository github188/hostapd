#ifndef _OSSMODULE_H_
#define _OSSMODULE_H_
#include "utils/logtrace.h"

#define OSS_MODULE_BEGIN       ((DWORD) 0)
#define OSS_MODULE_ALL         ((DWORD)(OSS_MODULE_BEGIN + 0))
#define OSS_MODULE_VOS         ((DWORD)(OSS_MODULE_BEGIN + 1))
#define OSS_MODULE_IPCDRV      ((DWORD)(OSS_MODULE_BEGIN + 2))
#define OSS_MODULE_VMMM        ((DWORD)(OSS_MODULE_BEGIN + 3))
#define OSS_MODULE_VMTM        ((DWORD)(OSS_MODULE_BEGIN + 4))
#define OSS_MODULE_VMSC        ((DWORD)(OSS_MODULE_BEGIN + 5))
#define OSS_MODULE_MISC        ((DWORD)(OSS_MODULE_BEGIN + 6))
#define OSS_MODULE_VMIPC       ((DWORD)(OSS_MODULE_BEGIN + 7))
#define OSS_MODULE_SYSCTL      ((DWORD)(OSS_MODULE_BEGIN + 8))
#define OSS_MODULE_SYSCFG      ((DWORD)(OSS_MODULE_BEGIN + 9))
#define OSS_MODULE_TEST        ((DWORD)(OSS_MODULE_BEGIN + 10))

#define APP_MODULE_BEGIN    	((DWORD) 15)
#define APP_MODULE_DB       	((DWORD)(APP_MODULE_BEGIN + 0))
#define APP_MODULE_DEVM         ((DWORD)(APP_MODULE_BEGIN + 1))
#define APP_MODULE_USRM        	((DWORD)(APP_MODULE_BEGIN + 2))
#define APP_MODULE_OMA        	((DWORD)(APP_MODULE_BEGIN + 3))
#define APP_MODULE_CW          	((DWORD)(APP_MODULE_BEGIN + 4))
#define APP_MODULE_HOSTAPD      ((DWORD)(APP_MODULE_BEGIN + 5))
#define APP_MODULE_LCS          ((DWORD)(APP_MODULE_BEGIN + 6))
#define APP_MODULE_ACM          ((DWORD)(APP_MODULE_BEGIN + 7))
#define APP_MODULE_RRM          ((DWORD)(APP_MODULE_BEGIN + 8))

#define APP_MODULE_MANAGER      ((DWORD)(APP_MODULE_BEGIN + 9))
#define APP_MODULE_AGENT        ((DWORD)(APP_MODULE_BEGIN + 10))

#define APP_MODULE_PA_BK        ((DWORD)(APP_MODULE_BEGIN + 11))
#define APP_MODULE_PA           ((DWORD)(APP_MODULE_BEGIN + 12))
#define APP_MODULE_WAPIAPD      ((DWORD)(APP_MODULE_BEGIN + 13))
#define APP_MODULE_SYSM         ((DWORD)(APP_MODULE_BEGIN + 14))


#define ModuleLogMsg(dwModuleId,byLevel,szFormat,...) \
       TRACE(dwModuleId, szFormat, ##__VA_ARGS__)

#endif

