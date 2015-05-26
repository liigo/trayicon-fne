/*
    版权声明：
    本文件版权为易语言作者吴涛所有，仅授权给第三方用作开发易语言支持库，禁止用于其他任何场合。
*/
#include "stdafx.h"

INT g_nLastNotifyResult;
PFN_NOTIFY_SYS g_fnNotifySys = NULL;

INT WINAPI ProcessNotifyLib (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	INT nRet = NR_OK;
	switch (nMsg)
	{
	case NL_SYS_NOTIFY_FUNCTION:
		g_fnNotifySys = (PFN_NOTIFY_SYS)dwParam1;
		break;
	default:
		nRet = NR_ERR;
		break;
	}

	return nRet;
}

INT WINAPI NotifySys (INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	ASSERT (g_fnNotifySys != NULL);
	if (g_fnNotifySys != NULL)
		return g_nLastNotifyResult = g_fnNotifySys (nMsg, dwParam1, dwParam2);
	else
		return g_nLastNotifyResult = 0;
}


// 使用指定文本数据建立易程序中使用的文本数据。
char* CloneTextData (char* ps)
{
    if (ps == NULL || *ps == '\0')
        return NULL;

    INT nTextLen = strlen (ps);
    char* pd = (char*)NotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}

// 使用指定文本数据建立易程序中使用的文本数据。
//   nTextLen用作指定文本部分的长度（不包含结束零），
// 如果为-1，则取ps的全部长度。
char* CloneTextData (char* ps, INT nTextLen)
{
    if (nTextLen <= 0)
        return NULL;

    char* pd = (char*)NotifySys (NRS_MALLOC, (DWORD)(nTextLen + 1), 0);
    memcpy (pd, ps, nTextLen);
    pd [nTextLen] = '\0';
    return pd;
}

// 使用指定数据建立易程序中使用的字节集数据。
LPBYTE CloneBinData (LPBYTE pData, INT nDataSize)
{
    if (nDataSize == 0)
        return NULL;

    LPBYTE pd = (LPBYTE)NotifySys (NRS_MALLOC, (DWORD)(sizeof (INT) * 2 + nDataSize), 0);
    *(LPINT)pd = 1;
    *(LPINT)(pd + sizeof (INT)) = nDataSize;
    memcpy (pd + sizeof (INT) * 2, pData, nDataSize);
    return pd;
}

// 报告运行时错误。
void GReportError (char* szErrText)
{
    NotifySys (NRS_RUNTIME_ERR, (DWORD)szErrText, 0);
}

void* MMalloc (INT nSize)
{
	return (void*)NotifySys (NRS_MALLOC, (DWORD)nSize, 0);
}

void MFree (void* p)
{
	NotifySys (NRS_MFREE, (DWORD)p, 0);
}

// 返回数组的数据部分首地址及成员数目。
LPBYTE GetAryElementInf (void* pAryData, LPINT pnElementCount)
{
	LPINT pnData = (LPINT)pAryData;
	INT nArys = *pnData++;  // 取得维数。
	// 计算成员数目。
	INT nElementCount = 1;
	while (nArys > 0)
	{
		nElementCount *= *pnData++;
		nArys--;
	}

	if (pnElementCount != NULL)
		*pnElementCount = nElementCount;
	return (LPBYTE)pnData;
}

#define DTT_IS_NULL_DATA_TYPE   0
#define DTT_IS_SYS_DATA_TYPE    1
#define DTT_IS_USER_DATA_TYPE   2
#define DTT_IS_LIB_DATA_TYPE    3
// 取回数据类型的类别。
INT GetDataTypeType (DATA_TYPE dtDataType)
{
	if (dtDataType == _SDT_NULL)
		return DTT_IS_NULL_DATA_TYPE;

	DWORD dw = dtDataType & 0xC0000000;
	return dw == DTM_SYS_DATA_TYPE_MASK ? DTT_IS_SYS_DATA_TYPE :
			dw == DTM_USER_DATA_TYPE_MASK ? DTT_IS_USER_DATA_TYPE :
			DTT_IS_LIB_DATA_TYPE;
}