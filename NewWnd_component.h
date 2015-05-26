#ifndef TrayIcon_component
#define TrayIcon_component

#include "NewWnd_wrap.h"

#ifndef __E_STATIC_LIB

//PFN_INTERFACE WINAPI TrayIcon_GetInterface (INT nInterfaceNO);
//��������
#define TrayIcon_DataTypeInfo \
	{\
/*m_szName*/			_WT("����ͼ��"),\
/*m_szEgName*/			_WT("TrayIcon"),\
/*m_szExplain*/			_WT("ֻ��Ҫ�����ؼ����õ������Դ����ϣ����úá�ͼ�ꡱ���ԣ�����Ϊ�����Գ����������ͼ�깦�ܡ�"\
	"\r\n    ע�⣺���ؼ�֧������ͼ�������ڼ�ʱԤ�����ܣ����ڳ�������ھ��ܿ�������ͼ���ʵ��Ч����"\
	"���ڡ��������С��׳��������¿��������ظ�������ͼ�����������󣬵����б������׳���ֻ����һ������ͼ�ꡣ"),\
/*m_nCmdCount*/			sizeof (TrayIcon_CmdIndex) / sizeof (TrayIcon_CmdIndex [0]),\
/*m_pnCmdsIndex*/		TrayIcon_CmdIndex,\
/*m_dwState*/			DT_SUPPORT_OS|LDT_WIN_UNIT|LDT_IS_FUNCTION_PROVIDER,\
/*m_dwUnitBmpID*/		IDB_BITMAP1,\
/*m_nEventCount*/		sizeof(TrayIcon_Events) / sizeof(TrayIcon_Events[0]),\
/*m_pEventBegin*/		TrayIcon_Events,\
/*m_nPropertyCount*/	sizeof(TrayIcon_Properties) / sizeof(TrayIcon_Properties[0]),\
/*m_pPropertyBegin*/	TrayIcon_Properties,\
/*m_pfnGetInterface*/	trayicon_GetInterface_TrayIcon,\
/*m_nElementCount*/		0,\
/*m_pElementBegin*/		NULL,\
	}



///////////////////////////////////////////////////////////////////////////////
//�����������
INT TrayIcon_CmdIndex [] =
{
	20, 
};


///////////////////////////////////////////////////////////////////////////////
// �������
#define TrayIcon_All_functions \
	trayicon_TrayMessageBox,\


///////////////////////////////////////////////////////////////////////////////
// ���������Ϣ

#define TrayIcon_All_CmdInfo \
	TrayIcon_TrayMessageBox_CmdInfo,\


#endif	



///////////////////////////////////////////////////////////////////////////////
// ����������ʵ�� (ͬһ�������Ĳ�������Ϣ��ʵ�ִ������һ�𣬱��ڲ��Ҽ��ο�)

//-----------------------------------------------------------------------------
// ������������Ϣ��ʵ�ִ���

#ifndef __E_STATIC_LIB

ARG_INFO TrayIcon_TrayMessageBox_ArgInfo[] =
{
	{
/*name*/	_WT("����"),
/*explain*/	_WT(""),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
	{
/*name*/	_WT("��ʾ��Ϣ"),
/*explain*/	_WT(""),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_TEXT,
/*default*/	0,
/*state*/	NULL,
	},
	{
/*name*/	_WT("ͼ������"),
/*explain*/	_WT("��Ϊ����ֵ֮һ��0����ͼ�ꣻ1����Ϣͼ�ꣻ2������ͼ�ꣻ3������ͼ�ꡣĬ��ֵΪ1����ʹ�á���Ϣͼ�ꡱ��"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	1,
/*state*/	AS_HAS_DEFAULT_VALUE,
	},
	{
/*name*/	_WT("�Զ��ر���ʱ"),
/*explain*/	_WT("ָ�����ٺ���֮����Ϣ��ʾ���Զ��رա����������Ϊ0����ʾ�����Զ��رգ����û��ֶ��رգ���"),
/*bmp inx*/	0,
/*bmp num*/	0,
/*type*/	SDT_INT,
/*default*/	0,
/*state*/	AS_HAS_DEFAULT_VALUE,
	},
};

#define TrayIcon_TrayMessageBox_CmdInfo \
	{\
/*ccname*/	_WT("������Ϣ��"),\
/*egname*/	_WT("TrayMessageBox"),\
/*explain*/	_WT("��ϵͳ�������򵯳���Ϣ��ʾ���׳ơ�������ʾ����������ֻ��Windows 2000/XP/2003 ϵͳ����Ч�������������ϵͳ����Win95/98��֧�֣������ء��١���"),\
/*category*/-1,\
/*state*/	CMD_SUPPORT_OS, \
/*ret*/		SDT_BOOL,\
/*reserved*/0,\
/*level*/	LVL_SIMPLE,\
/*bmp inx*/	0,\
/*bmp num*/	0,\
/*ArgCount*/sizeof(TrayIcon_TrayMessageBox_ArgInfo) / sizeof(TrayIcon_TrayMessageBox_ArgInfo[0]),\
/*arg lp*/	TrayIcon_TrayMessageBox_ArgInfo,\
	}

#endif

extern "C" void trayicon_TrayMessageBox (PMDATA_INF pRetData, INT nArgCount, PMDATA_INF pArgInf)
{
	pRetData->m_bool = FALSE;
	CTrayIconWnd* pUnit = (CTrayIconWnd*)GetWndPtr(pArgInf); if(pUnit==NULL) return;
	BOOL ret = pUnit->ShowBalloon(pArgInf[1].m_pText,pArgInf[2].m_pText,pArgInf[3].m_int,pArgInf[4].m_int);
	pRetData->m_bool = ret;
}

#ifndef __E_STATIC_LIB

UNIT_PROPERTY TrayIcon_Properties [] =
{
	FIXED_WIN_UNIT_PROPERTY,
	{
	/*m_szName*/	_WT("ͼ��"),
	/*m_szEgName*/	_WT("Icon"),
	/*m_szExplain*/	_WT(""),
	/*m_shtType*/	UD_ICON,
	/*m_wState*/	PROP_SUPPORT_OS,
	/*m_szzPickStr*/NULL,
	}, 
	{
	/*m_szName*/	_WT("��ʾ�ı�"),
	/*m_szEgName*/	_WT("Tip"),
	/*m_szExplain*/	_WT(""),
	/*m_shtType*/	UD_TEXT,
	/*m_wState*/	PROP_SUPPORT_OS,
	/*m_szzPickStr*/NULL,
	}, 
	{
	/*m_szName*/	_WT("��ʾ"),
	/*m_szEgName*/	_WT("Showing"),
	/*m_szExplain*/	_WT(""),
	/*m_shtType*/	UD_BOOL,
	/*m_wState*/	PROP_SUPPORT_OS,
	/*m_szzPickStr*/NULL,
	}, 
	MASK_UNIT_PROPERTY_5,
	{
	/*m_szName*/	_WT("ͼ�����λ��"),
	/*m_szEgName*/	_WT("XPosition"),
	/*m_szExplain*/	_WT("����ͼ�����������Ļ���Ͻǵĺ�������λ�á�"),
	/*m_shtType*/	UD_INT,
	/*m_wState*/	PROP_SUPPORT_OS|UW_ONLY_READ,
	/*m_szzPickStr*/NULL,
	}, 
	{
	/*m_szName*/	_WT("ͼ������λ��"),
	/*m_szEgName*/	_WT("YPosition"),
	/*m_szExplain*/	_WT("����ͼ�����������Ļ���Ͻǵ���������λ�á�"),
	/*m_shtType*/	UD_INT,
	/*m_wState*/	PROP_SUPPORT_OS|UW_ONLY_READ,
	/*m_szzPickStr*/NULL,
	},
};

//�¼�
// !!! �˴��Ķ���˳����Բ��ɸı�
static EVENT_ARG_INFO2 TrayIcon_MouseMove_Arg [] =
{
	{
	/*name*/	_WT("����λ��"),
	/*explain*/	_WT("�����Ļ��ߵ����λ��"),
	/*state*/	NULL,
	/*DataType*/SDT_INT,		
	},
	{
	/*name*/	_WT("����λ��"),
	/*explain*/	_WT("�����Ļ���ߵ����λ��"),
	/*state*/	NULL,
	/*DataType*/SDT_INT,		
	},
};

// !!! �˴��Ķ���˳����Բ��ɸı䣬��Ĭ����Ϣ������λ��
EVENT_INFO2 TrayIcon_Events [] =
{
	{
/*m_szName*/		_WT("����ͼ�걻����"),
/*m_szExplain*/		_WT(""),
/*m_dwState*/		EVENT_SUPPORT_OS | EV_IS_VER2,
/*m_nArgCount*/		0,
/*m_pBeginArgInfo*/	NULL,
/*m_dtRetDataType*/	_SDT_NULL,
	},
	{
/*m_szName*/		_WT("����ͼ�걻˫��"),
/*m_szExplain*/		_WT("���¼����ܻᱻ������ͼ�걻�������¼����ε����ʲ���ͬʱʹ���������¼���"),
/*m_dwState*/		EVENT_SUPPORT_OS | EV_IS_VER2,
/*m_nArgCount*/		0,
/*m_pBeginArgInfo*/	NULL,
/*m_dtRetDataType*/	_SDT_NULL,
	},
	{
/*m_szName*/		_WT("����ͼ�걻�һ�"),
/*m_szExplain*/		_WT(""),
/*m_dwState*/		EVENT_SUPPORT_OS | EV_IS_VER2,
/*m_nArgCount*/		0,
/*m_pBeginArgInfo*/	NULL,
/*m_dtRetDataType*/	_SDT_NULL,
	},
	{
/*m_szName*/		_WT("����ͼ�����λ�ñ��ƶ�"),
/*m_szExplain*/		_WT(""),
/*m_dwState*/		EVENT_SUPPORT_OS | EV_IS_VER2,
/*m_nArgCount*/		sizeof(TrayIcon_MouseMove_Arg) / sizeof(TrayIcon_MouseMove_Arg[0]),
/*m_pBeginArgInfo*/	TrayIcon_MouseMove_Arg,
/*m_dtRetDataType*/	_SDT_NULL,
	},
};

#endif

//////////////////////////////////////////////////////////////////////////
// �ӿ�ʵ�ִ���

static HUNIT WINAPI TrayIcon_Create (LPBYTE pAllData, INT nAllDataSize,
		DWORD dwStyle, HWND hParentWnd, UINT uID, HMENU hMenu, INT x, INT y, INT cx, INT cy,
		DWORD dwWinFormID, DWORD dwUnitID, HWND hDesignWnd, BOOL blInDesignMode)
{
	CTrayIconWnd* pUnit = new CTrayIconWnd();
	if (!pUnit) return NULL;
	pUnit->m_dwWinFormID = dwWinFormID;
	pUnit->m_dwUnitID = dwUnitID;
	pUnit->m_blInDesignMode = blInDesignMode;

	//�׳����������ʱ����load���ӻ����ʱ���õ�����
	if (pUnit->m_Properties.LoadData (pAllData, nAllDataSize) == FALSE)
	{
		delete pUnit;
		return NULL;
	}
	if (!pUnit->Create(hParentWnd, dwStyle, uID, x, y, cx, cy))
	{
		return NULL;
	}

	pUnit->ModifyTrayIcon();
	
	return (HUNIT)pUnit;
}

static BOOL WINAPI TrayIcon_GetPropertyData (HUNIT hUnit, INT nPropertyIndex,
		PUNIT_PROPERTY_VALUE pPropertyVaule)
{
	ASSERT (hUnit != NULL);
	if (hUnit == NULL)  return FALSE;
	CTrayIconWnd* pUnit = (CTrayIconWnd*)hUnit;
	ASSERT (pUnit->GetSafeHwnd () != NULL);
	
	switch(nPropertyIndex) 
	{
	case 0: 
		pPropertyVaule->m_data.m_pData = pUnit->m_Properties.m_IconData.GetPtr();
		pPropertyVaule->m_data.m_nDataSize = pUnit->m_Properties.m_IconData.GetSize();
		break;
	case 1: pPropertyVaule->m_szText = (LPTSTR)(LPCTSTR)pUnit->m_Properties.m_TipText;
		break;
	case 2: pPropertyVaule->m_bool = pUnit->m_Properties.m_bShowing;
		break;
	case 8: //x
	case 9: //y
		{
			int x=0, y=0;
			pUnit->GetTrayIconPosition(x,y);
			if(nPropertyIndex==8)
				pPropertyVaule->m_int = x;
			else if(nPropertyIndex==9)
				pPropertyVaule->m_int = y;
			break;
		}
		
	default: 
		break;
	}

	return TRUE; //�ɹ��򷵻���
}

static HGLOBAL WINAPI TrayIcon_GetAllPropertyData (HUNIT hUnit)
{
	ASSERT (hUnit != NULL);
	return ((CTrayIconWnd*)hUnit)->m_Properties.SaveData ();	
}

static BOOL WINAPI TrayIcon_NotifyPropertyChanged (HUNIT hUnit, INT nPropertyIndex,
		PUNIT_PROPERTY_VALUE pPropertyVaule, LPTSTR* ppszTipText)
{
	ASSERT (hUnit != NULL);
	if (hUnit == NULL)  return FALSE;
	CTrayIconWnd* pUnit = (CTrayIconWnd*)hUnit;
	ASSERT (pUnit->GetSafeHwnd () != NULL);

	if (ppszTipText != NULL)
		*ppszTipText = NULL;

	switch(nPropertyIndex) 
	{
	case 0: 
		{
			pUnit->m_Properties.m_IconData.Empty();
			if(pPropertyVaule->m_data.m_nDataSize == 0)
			{
				pUnit->Invalidate();
				pUnit->DeleteTrayIcon();
				if(pUnit->m_Properties.m_hIcon) ::DestroyIcon(pUnit->m_Properties.m_hIcon);
				pUnit->m_Properties.m_hIcon = 0;
				break;
			}

			pUnit->m_Properties.m_IconData.Append(pPropertyVaule->m_data.m_pData,pPropertyVaule->m_data.m_nDataSize);
			HICON hIcon = LoadIco(pPropertyVaule->m_data.m_pData,pPropertyVaule->m_data.m_nDataSize,FALSE);
			if(hIcon == 0)
				hIcon = LoadIco(pPropertyVaule->m_data.m_pData,pPropertyVaule->m_data.m_nDataSize,TRUE);
			if(hIcon != 0)
			{
				if(pUnit->m_Properties.m_hIcon != 0) DestroyIcon(pUnit->m_Properties.m_hIcon);
				pUnit->m_Properties.m_hIcon = hIcon;
				pUnit->Invalidate();
				pUnit->ModifyTrayIcon();
			}
			else 
				pUnit->DeleteTrayIcon();
			break;
		}
	case 1: 
		pUnit->m_Properties.m_TipText = pPropertyVaule->m_szText;
		pUnit->ModifyTrayIcon();
		break;
	case 2: 
		pUnit->m_Properties.m_bShowing = pPropertyVaule->m_bool;
		if(pPropertyVaule->m_bool) pUnit->ModifyTrayIcon();
		else pUnit->DeleteTrayIcon();
		break;

	default:
		break;
	}

	return FALSE; //�����Ҫ���´����ؼ��򷵻���
}


extern "C" PFN_INTERFACE WINAPI trayicon_GetInterface_TrayIcon (INT nInterfaceNO)
{
	switch(nInterfaceNO) 
	{
	case ITF_CREATE_UNIT:	return (PFN_INTERFACE)TrayIcon_Create;
	case ITF_PROPERTY_UPDATE_UI:	return NULL;
	case ITF_DLG_INIT_CUSTOMIZE_DATA:	return NULL;
	case ITF_NOTIFY_PROPERTY_CHANGED:	return (PFN_INTERFACE)TrayIcon_NotifyPropertyChanged;
	case ITF_GET_ALL_PROPERTY_DATA:	return (PFN_INTERFACE)TrayIcon_GetAllPropertyData;
	case ITF_GET_PROPERTY_DATA:	return (PFN_INTERFACE)TrayIcon_GetPropertyData;
	case ITF_GET_ICON_PROPERTY_DATA:	return NULL;
	case ITF_IS_NEED_THIS_KEY:	return NULL;
	case ITF_LANG_CNV:	return NULL;
	case ITF_MSG_FILTER:	return NULL;
	default: return NULL;
	}
}



#endif