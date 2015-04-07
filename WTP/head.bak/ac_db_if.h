/******************************************************************************
* COPYRIGHT GBCOM
*******************************************************************************
* 功    能:  数据库统一接口功能头文件
* 修改历史: 
* 2008-4-15     潘妍艳              新建
*
******************************************************************************/

/******************************** 头文件保护开头 *****************************/

#ifndef  _AC_DB_IF_H
#define  _AC_DB_IF_H

extern VOID ac_db_get_table_allrecordhost (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_get_table_onerecordhost (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_get_table_wtprecordhost (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_get_table_allrecordnet (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_get_table_onerecordnet (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_get_table_wtprecordnet (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
extern VOID ac_db_show_table(UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );

/* BEGIN: Added by wubin, 2012/4/25   BUG:000 */
extern VOID ac_db_get_table_allrecordnet_probe (UINT8 *pucIn, UINT32 ulInLen, UINT8 *pucOut, UINT32 *pulOutLen );
/* END: Added by wubin, 2012/4/25   BUG:000 */

extern UINT32  ac_db_get_if_outlen(UINT32 ulMsgId, UINT32 *pulOutLen);
extern UINT32    ac_db_if_init (VOID);

#endif /* _AC_DB_IF_H */
/******************************* 头文件结束 **********************************/



