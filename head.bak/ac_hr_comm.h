#ifndef AC_HR_COMM_H
#define AC_HR_COMM_H

#if 1
typedef struct INI_KEY_T
{
    CHAR                *szName;
    CHAR                *szValue;

    struct INI_KEY_T    *pstNext;
}INI_KEY_T;

typedef struct INI_SECTION_T
{
    CHAR                    *szName;
    //UINT32                  ulKeyNum;
    INI_KEY_T               *pstKeys;   /* ÎªKeyÊý×é */
    struct INI_SECTION_T    *pstNext;
}INI_SECTION_T;

typedef struct
{
    CHAR            *szName;

    //UINT32          ulSectionNum;
    INI_SECTION_T   *pstSections;
}INI_INFO_T;
#endif

void    delay_1ms(unsigned long dwTimeout);
UINT32  VmGetUptime(VOID);
LONG    VmGetFileSize(char *szFile);
BOOL    VmFileExists(CHAR* szFile);
BOOL    VmDeleteFile(CHAR* szFile);
VOID    VmClearFile(CHAR* szFile);
LONG    VmGetFileSize(char *szFile);

INI_INFO_T *VmIniFileOpen(CHAR *szIniFile);
VOID    VmIniFileClose(INI_INFO_T *pstIniInfo);

BOOL    VmIniGetIntValue(INI_INFO_T *pstIniInfo, CHAR *szSection, CHAR *szKey,
                         UINT32 ulDftValue, UINT32 *pulValue);
BOOL	VmIniGetBoolValue(INI_INFO_T *pstIniInfo, CHAR *szSection, CHAR *szKey,
                          BOOL bDftValue, BOOL *pbValue);
BOOL	VmIniGetStringValue(INI_INFO_T *pstIniInfo, CHAR *szSection, CHAR *szKey,
                            CHAR *szDftValue, CHAR *szValue);
BOOL    VmIniGetIPValue(INI_INFO_T *pstIniInfo, CHAR *szSection, CHAR *szKey,
                        UINT8 *pucDftValue, UINT8* *pucValue);

#endif
