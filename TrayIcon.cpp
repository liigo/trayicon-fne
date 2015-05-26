// NewLib.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
//#include <vector>
#include "TrayIcon.h"
#include "NewWnd_component.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//using namespace std; //note! use for vector etc.

#ifndef __E_STATIC_LIB

/////////////////////////////////////////////////////////////////////////////
// CNewLibApp

BEGIN_MESSAGE_MAP(CNewLibApp, CWinApp)
	//{{AFX_MSG_MAP(CNewLibApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewLibApp construction

CNewLibApp::CNewLibApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNewLibApp object

CNewLibApp theApp;

///////////////////////////////////////////////////////////////////////////////
INT WINAPI RunAddIn(INT nIndex)
{
    switch(nIndex) 
    {
    case 0: 
        break;
    default:
        break;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// ȫ������ִ�к����� (Ԥ��20��ȫ������ռ�)

#define Global_All_functions \
	NULL_10, NULL_10,\



///////////////////////////////////////////////////////////////////////////////
// ȫ��������Ϣ�б� (Ԥ��20��ȫ������ռ�)

#define Global_All_CmdInfo \
	CMD_INFO_MASK_10, CMD_INFO_MASK_10,\


//��������
//extern LIB_DATA_TYPE_INFO NewWnd_DataTypeInfo;

LIB_DATA_TYPE_INFO s_DataType[]=
{
	TrayIcon_DataTypeInfo,
};


///////////////////////////////////////////////////////////////////////////////
//*** ����������Ϣ:
// !!! ע�ⳣ��ֵ�����Ѿ����õ������У�����˳��ֵ���Բ��ܸĶ���

LIB_CONST_INFO s_ConstInfo [] =
{
	{_WT("֧�ֿ����"),_WT("LibAlias"),NULL,LVL_SIMPLE,CT_TEXT,_T("TrayIcon_by_liigo"),0,},

};


///////////////////////////////////////////////////////////////////////////////
// ���е���������б�

static CMD_INFO s_CmdInfo[] =
{
	Global_All_CmdInfo
	TrayIcon_All_CmdInfo
};


///////////////////////////////////////////////////////////////////////////////
// ���е��������ִ�к�����

PFN_EXECUTE_CMD s_RunFunc [] =	// ����Ӧ��s_CmdInfo�е������˳���Ӧ
{
	Global_All_functions
	TrayIcon_All_functions
};

#endif

extern "C" INT WINAPI trayicon_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	//14,15,16��Ӧ�ĺ����ƣ��Ҽǲ�����ˣ����첹��
	if(nMsg == NL_GET_CMD_FUNC_NAMES)
	{
		static char* trayicon_cmdNames[] = 
		{
			NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL, //ǰ20������������
			NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
			"trayicon_TrayMessageBox",
		};
		return (INT) trayicon_cmdNames;
	}
	else if(nMsg == NL_GET_NOTIFY_LIB_FUNC_NAME)
	{
		return (INT) "trayicon_ProcessNotifyLib";
	}
	else if(nMsg == NL_GET_DEPENDENT_LIBS)
	{
		return (INT) NULL;
	}
	return ProcessNotifyLib(nMsg, dwParam1, dwParam2);
}

///////////////////////////////////////////////////////////////////////////////
// �ⶨ�忪ʼ

#ifndef __E_STATIC_LIB

static char* s_szInfo = "This is a runtime library file for EPL applications. The EPL is a software development environment. For details please visit www.dywt.com.cn/info";

LIB_INFO s_LibInfo =
{
/*Lib Format Ver*/		LIB_FORMAT_VER,		// ����δ�á�

// ��֧�ֿ��GUID����
#define		LI_LIB_GUID_STR	"{86AB1D8A-7995-4D86-AE5F-18710759228B}"
/*guid str*/			_T (LI_LIB_GUID_STR),

/*m_nMajorVersion*/		2,
/*m_nMinorVersion*/		0,
/*m_nBuildNumber*/		1,

/*m_nRqSysMajorVer*/		3,
/*m_nRqSysMinorVer*/		7,
/*m_nRqSysKrnlLibMajorVer*/	3,
/*m_nRqSysKrnlLibMinorVer*/	7,

/*name*/				_T ("����ͼ��֧�ֿ�"),
/*lang*/				__COMPILE_LANG_VER,
/*explain*/				_WT("�ṩ������ͼ�ꡱ�ؼ���ʹ��д��������ͼ��ĳ�����Ӽ򵥣�ֻҪ��������ͼ�ꡱ�ؼ����õ������ϣ�����һ�¡�ͼ�ꡱ�͡���ʾ�ı������Լ��ɡ�"
	"�������ԣ�������������ͼ����ʾ�ı���������������ͼ�꣬����ȡ������ͼ������Ļ�е�λ�ã���Explorer��������������ͼ�겻�ᶪʧ����л���ѡ�����׷�硱�����飩��"
	"\r\n    1.1#1���޸��ˡ���ͬһ���ڷ��ö��������ͼ�ꡯ�ؼ��ᵼ�³����������BUG����л���� ljp309 ָ������������ͬһ����ͬһ������ͬʱʹ�ö��������ͼ�ꡱ�ؼ���"
	"\r\n    2.0��֧�־�̬���롣"),
/*dwState*/				LIB_SUPPORT_OS,

/*szAuthor*/	_WT("liigo"),
/*szZipCode*/	NULL,
/*szAddress*/	NULL,
/*szPhoto*/		_WT(""),
/*szFax*/		_WT(""),
/*szEmail*/		_WT("liigo@sina.com"),
/*szHomePage*/	_WT("www.liigo.com"),
/*szOther*/		_WT("ף��һ����˳�������³ɣ�"),

/*type count*/			sizeof(s_DataType) / sizeof(s_DataType[0]),
/*PLIB_DATA_TYPE_INFO*/	s_DataType,

/*CategoryCount*/ 1,	// ���������Ӵ�ֵ��
/*category*/_WT("0000API\0"	// ���˵����ÿ��Ϊһ�ַ���,ǰ��λ���ֱ�ʾͼ��������(��1��ʼ,0��).
				"\0\0"),
/*CmdCount*/				sizeof (s_CmdInfo) / sizeof (s_CmdInfo [0]),
/*BeginCmd*/				s_CmdInfo,
/*m_pCmdsFunc*/             s_RunFunc,
/*pfnRunAddInFn*/			RunAddIn,
/*szzAddInFnInfo*/			"",

/*pfnNotify*/				trayicon_ProcessNotifyLib,

/*pfnRunSuperTemplate*/		NULL,
/*szzSuperTemplateInfo*/	NULL,

/*nLibConstCount*/			0, //sizeof (s_ConstInfo) / sizeof (s_ConstInfo [0]),
/*pLibConst*/				NULL, //s_ConstInfo,

/*szzDependFiles*/			NULL,
};

/////////////////////////////////////////////////////////////////////////////
//��������

PLIB_INFO WINAPI GetNewInf ()
{
	//Init_LibDataTypeInfo();
	return &s_LibInfo;
}

/////////////////////////////////////////////////////////////////////////////
/*
void Init_LibDataTypeInfo(void)
{
	vector<LIB_DATA_TYPE_INFO> v;
	//Add_DataTypes(v); //����������Ͷ���, ���û�ʵ�ָú���.
	//s_DataType = (PLIB_DATA_TYPE_INFO)malloc(v.size()*sizeof(LIB_DATA_TYPE_INFO));
	if (s_DataType==NULL) return;
	for(int i=0; i<v.size(); i++)
	{
		s_DataType[i] = v[i];
	}
	s_LibInfo.m_nDataTypeCount = v.size();
	s_LibInfo.m_pDataType = s_DataType;
}
*/
/////////////////////////////////////////////////////////////////////////////
CNewLibApp::~CNewLibApp()
{
	//if(s_DataType != NULL) free(s_DataType);
}

#endif
