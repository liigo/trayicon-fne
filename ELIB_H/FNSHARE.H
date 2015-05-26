
/*
    版权声明：
    本文件版权为易语言作者吴涛所有，仅授权给第三方用作开发易语言支持库，禁止用于其他任何场合。
*/

#ifndef __FN_SHARE_H
#define __FN_SHARE_H

INT WINAPI ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2);
INT WINAPI NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2);

char* CloneTextData (char* ps);
char* CloneTextData (char* ps, INT nTextLen);
LPBYTE CloneBinData (LPBYTE pData, INT nDataSize);
void GReportError (char* szErrText);
void* MMalloc (INT nSize);
void MFree (void* p);
LPBYTE GetAryElementInf (void* pAryData, LPINT pnElementCount);
INT GetDataTypeType (DATA_TYPE dtDataType);

#ifdef __COMPILE_FNR	// 此宏在编译配置中设置
	#define	_WT(text)	""
#else
	#define	_WT(text)	text
#endif


//命令信息占位符
#define CMD_INFO_MASK_1 \
		{\
		/*ccname*/	NULL,\
		/*egname*/	NULL,\
		/*explain*/	NULL,\
		/*category*/-1,\
		/*state*/	CT_IS_HIDED,\
		/*ret*/		_SDT_NULL,\
		/*reserved*/0,\
		/*level*/	LVL_SIMPLE,\
		/*bmp inx*/	0,\
		/*bmp num*/	0,\
		/*ArgCount*/0,\
		/*arg lp*/	NULL,\
		}
#define CMD_INFO_MASK_2		CMD_INFO_MASK_1,CMD_INFO_MASK_1
#define CMD_INFO_MASK_3		CMD_INFO_MASK_2,CMD_INFO_MASK_1
#define CMD_INFO_MASK_4		CMD_INFO_MASK_3,CMD_INFO_MASK_1
#define CMD_INFO_MASK_5		CMD_INFO_MASK_4,CMD_INFO_MASK_1
#define CMD_INFO_MASK_6		CMD_INFO_MASK_5,CMD_INFO_MASK_1
#define CMD_INFO_MASK_7		CMD_INFO_MASK_6,CMD_INFO_MASK_1
#define CMD_INFO_MASK_8		CMD_INFO_MASK_7,CMD_INFO_MASK_1
#define CMD_INFO_MASK_9		CMD_INFO_MASK_8,CMD_INFO_MASK_1
#define CMD_INFO_MASK_10	CMD_INFO_MASK_9,CMD_INFO_MASK_1

#define MASK_CMD_INFO_1	CMD_INFO_MASK_1
#define MASK_CMD_INFO_2	CMD_INFO_MASK_2
#define MASK_CMD_INFO_3	CMD_INFO_MASK_3
#define MASK_CMD_INFO_4	CMD_INFO_MASK_4
#define MASK_CMD_INFO_5	CMD_INFO_MASK_5
#define MASK_CMD_INFO_6	CMD_INFO_MASK_6
#define MASK_CMD_INFO_7	CMD_INFO_MASK_7
#define MASK_CMD_INFO_8	CMD_INFO_MASK_8
#define MASK_CMD_INFO_9	CMD_INFO_MASK_9


//空白函数指针占位符
#define NULL_1	 NULL
#define NULL_2	 NULL,NULL
#define NULL_3	 NULL_2,NULL_1
#define NULL_4	 NULL_3,NULL_1
#define NULL_5	 NULL_4,NULL_1
#define NULL_6	 NULL_5,NULL_1
#define NULL_7	 NULL_6,NULL_1
#define NULL_8	 NULL_7,NULL_1
#define NULL_9	 NULL_8,NULL_1
#define NULL_10	 NULL_9,NULL_1


#endif

