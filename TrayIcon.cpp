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
// 全局命令执行函数表 (预留20个全局命令空间)

#define Global_All_functions \
	NULL_10, NULL_10,\



///////////////////////////////////////////////////////////////////////////////
// 全局命令信息列表 (预留20个全局命令空间)

#define Global_All_CmdInfo \
	CMD_INFO_MASK_10, CMD_INFO_MASK_10,\


//数据类型
//extern LIB_DATA_TYPE_INFO NewWnd_DataTypeInfo;

LIB_DATA_TYPE_INFO s_DataType[]=
{
	TrayIcon_DataTypeInfo,
};


///////////////////////////////////////////////////////////////////////////////
//*** 常量定义信息:
// !!! 注意常量值由于已经运用到程序中，所以顺序及值绝对不能改动。

LIB_CONST_INFO s_ConstInfo [] =
{
	{_WT("支持库代号"),_WT("LibAlias"),NULL,LVL_SIMPLE,CT_TEXT,_T("TrayIcon_by_liigo"),0,},

};


///////////////////////////////////////////////////////////////////////////////
// 所有的命令及方法列表

static CMD_INFO s_CmdInfo[] =
{
	Global_All_CmdInfo
	TrayIcon_All_CmdInfo
};


///////////////////////////////////////////////////////////////////////////////
// 所有的命令及方法执行函数表

PFN_EXECUTE_CMD s_RunFunc [] =	// 索引应与s_CmdInfo中的命令定义顺序对应
{
	Global_All_functions
	TrayIcon_All_functions
};

#endif

extern "C" INT WINAPI trayicon_ProcessNotifyLib(INT nMsg, DWORD dwParam1, DWORD dwParam2)
{
	//14,15,16对应的宏名称，我记不清楚了，改天补上
	if(nMsg == NL_GET_CMD_FUNC_NAMES)
	{
		static char* trayicon_cmdNames[] = 
		{
			NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL, //前20个是隐藏命令
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
// 库定义开始

#ifndef __E_STATIC_LIB

static char* s_szInfo = "This is a runtime library file for EPL applications. The EPL is a software development environment. For details please visit www.dywt.com.cn/info";

LIB_INFO s_LibInfo =
{
/*Lib Format Ver*/		LIB_FORMAT_VER,		// 保留未用。

// 本支持库的GUID串：
#define		LI_LIB_GUID_STR	"{86AB1D8A-7995-4D86-AE5F-18710759228B}"
/*guid str*/			_T (LI_LIB_GUID_STR),

/*m_nMajorVersion*/		2,
/*m_nMinorVersion*/		0,
/*m_nBuildNumber*/		1,

/*m_nRqSysMajorVer*/		3,
/*m_nRqSysMinorVer*/		7,
/*m_nRqSysKrnlLibMajorVer*/	3,
/*m_nRqSysKrnlLibMinorVer*/	7,

/*name*/				_T ("托盘图标支持库"),
/*lang*/				__COMPILE_LANG_VER,
/*explain*/				_WT("提供“托盘图标”控件，使编写带有托盘图标的程序更加简单：只要将“托盘图标”控件放置到窗口上，设置一下“图标”和“提示文本”属性即可。"
	"其它特性：允许设置托盘图标提示文本，允许隐藏托盘图标，可以取到托盘图标在屏幕中的位置，当Explorer出错重启后托盘图标不会丢失（感谢易友“碎梦追风”的提议）。"
	"\r\n    1.1#1版修改了“在同一窗口放置多个‘托盘图标’控件会导致程序崩溃”的BUG（感谢易友 ljp309 指出），允许在同一程序、同一窗口中同时使用多个“托盘图标”控件。"
	"\r\n    2.0版支持静态编译。"),
/*dwState*/				LIB_SUPPORT_OS,

/*szAuthor*/	_WT("liigo"),
/*szZipCode*/	NULL,
/*szAddress*/	NULL,
/*szPhoto*/		_WT(""),
/*szFax*/		_WT(""),
/*szEmail*/		_WT("liigo@sina.com"),
/*szHomePage*/	_WT("www.liigo.com"),
/*szOther*/		_WT("祝您一帆风顺，心想事成！"),

/*type count*/			sizeof(s_DataType) / sizeof(s_DataType[0]),
/*PLIB_DATA_TYPE_INFO*/	s_DataType,

/*CategoryCount*/ 1,	// 加了类别需加此值。
/*category*/_WT("0000API\0"	// 类别说明表每项为一字符串,前四位数字表示图象索引号(从1开始,0无).
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
//导出函数

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
	//Add_DataTypes(v); //添加数据类型定义, 需用户实现该函数.
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
