// NewWnd.cpp : implementation file
//

#include "stdafx.h"
#include "TrayIcon.h"
#include "NewWnd_wrap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

void CTrayIconWnd_PropertyInfo::init ()
{
	m_LastVersion = 1; //最新版本号
	m_IconData.Empty();
	m_hIcon = GetDefaultIconHandle();
	m_TipText = CString("");
	m_bShowing = TRUE;
}

//liigo 2010/2/3: DefaultIconData[]用于取代图标资源(DefaultIcon.ico), 这样静态支持库就不需要.res文件了
static unsigned char s_DefaultIconData[] = {0,0,1,0,1,0,16,16,16,0,0,0,0,0,40,1,0,0,22,0,0,0,40,0,0,0,16,0,0,0,32,0,0,0,1,0,4,0,0,0,0,0,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,128,0,0,0,128,128,0,128,0,0,0,128,0,128,0,128,128,0,0,192,192,192,0,128,128,128,0,0,0,255,0,0,255,0,0,0,255,255,0,255,0,0,0,255,0,255,0,255,255,0,0,255,255,255,0,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,143,255,255,255,255,255,255,255,135,119,119,119,119,119,119,127,135,119,119,119,116,68,119,127,135,7,112,119,74,170,71,127,128,119,7,116,170,170,164,127,135,7,112,119,74,170,71,127,135,119,119,119,116,68,119,127,135,119,119,119,119,119,119,127,136,136,136,136,136,136,136,136,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static HICON g_DefaultIconHandle = NULL;

HICON CTrayIconWnd_PropertyInfo::GetDefaultIconHandle()
{
	//return (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_DefaultIcon),IMAGE_ICON,16,16,LR_DEFAULTCOLOR);

	if(g_DefaultIconHandle = NULL)
		g_DefaultIconHandle = LoadIco(s_DefaultIconData, sizeof(s_DefaultIconData), FALSE); //只此一家, 无需释放
	return g_DefaultIconHandle;	
}

BOOL CTrayIconWnd_PropertyInfo::Serialize (CArchive& ar)
{
	if (ar.IsLoading()) //ar>>
	{
		ar>>m_Version;
		m_IconData.Serialize(ar); 
		if(m_IconData.GetSize() > 0)
		{
			m_hIcon = LoadIco(m_IconData.GetPtr(),m_IconData.GetSize(),FALSE);
			if(m_hIcon==0) m_hIcon = LoadIco(m_IconData.GetPtr(),m_IconData.GetSize(),TRUE);
		}
		else 
			m_hIcon = GetDefaultIconHandle();
		SerializeCString(m_TipText,ar);
		ar>>m_bShowing;
	}
	else //ar<<
	{
		ar<<m_LastVersion;
		m_IconData.Serialize(ar);
		SerializeCString(m_TipText,ar);
		ar<<m_bShowing;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTrayIconWnd
static DWORD _trayicon_wm_TaskbarCreated = NULL;
static WNDPROC _trayicon_g_OldWndProc = NULL;
static HWND _trayicon_g_hTopWindow = NULL;
//#define MY_OBJ		_T("LiigoTempObject")

CTrayIconWnd::CTrayIconWnd()
{
	m_bTrayIconIsAdd = FALSE;
	_trayicon_wm_TaskbarCreated = RegisterWindowMessage(TEXT("TaskbarCreated")); //must be "TaskbarCreated"
}

CTrayIconWnd::~CTrayIconWnd()
{
}


BEGIN_MESSAGE_MAP(CTrayIconWnd, CWnd)
	//{{AFX_MSG_MAP(CTrayIconWnd)
	ON_WM_PAINT()

	ON_MESSAGE(MY_TRAYINON_MSG,onTrayIconNotify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTrayIconWnd message handlers

#include <afxtempl.h>

static CArray<CTrayIconWnd*, CTrayIconWnd*> _trayicon_g_MyObjs;
static LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/*
	//if(uMsg == wm_TaskbarCreated)
	static CTrayIconWnd *myObj = (CTrayIconWnd*)::GetProp(hwnd, MY_OBJ);
	if(myObj!=NULL && uMsg == wm_TaskbarCreated)
	{
		myObj->RecreateTrayIcon(); //当任务栏重建时, 添加TrayIco
	}
	*/

	CTrayIconWnd *myObj = NULL;
	if(uMsg == _trayicon_wm_TaskbarCreated)
	{
		for(int i=0; i<_trayicon_g_MyObjs.GetSize(); i++)
		{
			myObj = _trayicon_g_MyObjs.GetAt(i);
			if(myObj) 
				myObj->RecreateTrayIcon(); //当任务栏重建时, 添加TrayIco
		}
	}
	return CallWindowProc(_trayicon_g_OldWndProc, hwnd,uMsg,wParam,lParam);
}


BOOL CTrayIconWnd::Create (HWND hParentWnd, DWORD dwStyle, UINT uID, INT x, INT y, INT cx, INT cy)
{
	if (!CWnd::CreateEx (WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, AfxRegisterWndClass (CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
			::LoadCursor (NULL, IDC_ARROW)),
			_T(""), dwStyle|WS_CHILD|WS_CLIPSIBLINGS,x, y, cx, cy, hParentWnd, (HMENU)uID, NULL))
		return FALSE;
	
	//钩顶层窗口, 以获取状态栏重建消息
	//一个程序中可能有多个“托盘图标”控件，但顶层窗口的WndProc只需替换一次。
	//::SetProp(g_hTopWindow, MY_OBJ, (HANDLE)this);
	_trayicon_g_MyObjs.Add(this);
	if(_trayicon_g_OldWndProc == NULL)
	{
		_trayicon_g_hTopWindow = GetTopLevelParent()->GetSafeHwnd();
		_trayicon_g_OldWndProc = (WNDPROC)::SetWindowLongA(_trayicon_g_hTopWindow, GWL_WNDPROC, (LONG)MyWindowProc);
	}
	return TRUE;
}

void CTrayIconWnd::OnPaint() 
{
	CRect r;
	GetClientRect(&r);

	//LOG("onPaint");

	CPaintDC dc(this); // device context for painting
	CBrush brush(GetSysColor(COLOR_BTNFACE));
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CBrush *oldBrush = dc.SelectObject(&brush);
	CPen *oldPen = dc.SelectObject(&pen);
	dc.Rectangle(r);
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);

	int x,y;
	if(m_Properties.m_hIcon == 0) 
		m_Properties.m_hIcon = m_Properties.GetDefaultIconHandle();
	if(m_Properties.m_hIcon)
	{
		x = (r.Width() - 16) / 2;  if(x<=0) x=2; 
		y = (r.Height() - 16) / 2; if(y<=0) y=2;
		if(!::DrawIconEx(dc.m_hDC, x,y, m_Properties.m_hIcon, 16,16, 0,NULL,DI_NORMAL))
		{
			dc.DrawIcon(10,10,m_Properties.m_hIcon);
		}
	}

}

void CTrayIconWnd::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	DeleteTrayIcon();
	if(m_Properties.m_hIcon != 0) 
		::DestroyIcon(m_Properties.m_hIcon);
	
	for(int i=0; i<_trayicon_g_MyObjs.GetSize(); i++)
	{
		if(this == _trayicon_g_MyObjs.GetAt(i))
		{
			_trayicon_g_MyObjs.RemoveAt(i);
			break;
		}
	}
	if(_trayicon_g_MyObjs.GetSize()==0 && _trayicon_g_hTopWindow && _trayicon_g_OldWndProc)
		::SetWindowLongA(_trayicon_g_hTopWindow, GWL_WNDPROC, (LONG)_trayicon_g_OldWndProc);

	CWnd::PostNcDestroy();
	NotifySys (NRS_UNIT_DESTROIED, m_dwWinFormID, m_dwUnitID);
	
	delete this;

	//LOG("PostNcDestroy");
}


LPTSTR CTrayIconWnd::MessageBox()
{
	CWnd::MessageBox(m_Properties.m_TipText);
	return (LPTSTR)(LPCTSTR)m_Properties.m_TipText;
}


///////////////////////////////////////////////////////////////////////////////

//自定义托盘消息响应
LRESULT CTrayIconWnd::onTrayIconNotify(WPARAM wParam, LPARAM lParam)
{
	log("TrayIcon event: %x", lParam);

	EVENT_NOTIFY event(m_dwWinFormID, m_dwUnitID, -1);
	switch(lParam)
	{
	case WM_LBUTTONUP:
		{
			event.m_nEventIndex = 0;
			event.m_nArgCount = 0;
			NotifySys(NRS_EVENT_NOTIFY, (DWORD)&event, 0);
			break;
		}
	case WM_LBUTTONDBLCLK:
		{
			event.m_nEventIndex = 1;
			event.m_nArgCount = 0;
			NotifySys(NRS_EVENT_NOTIFY, (DWORD)&event, 0);
			break;
		}
	case WM_RBUTTONUP:
		{
			event.m_nEventIndex = 2;
			event.m_nArgCount = 0;
			NotifySys(NRS_EVENT_NOTIFY, (DWORD)&event, 0);
			break;
		}
	case WM_MOUSEMOVE:
		{
			event.m_nEventIndex = 3;
			event.m_nArgCount = 2;
			POINT pt; ::GetCursorPos(&pt);
			event.m_nArgValue[0] = pt.x;
			event.m_nArgValue[1] = pt.y;
			NotifySys(NRS_EVENT_NOTIFY, (DWORD)&event, 0);
			break;
		}
	default: break;
	}

	return 0;
}



BOOL CTrayIconWnd::AddTrayIcon()
{
	if(m_Properties.m_IconData.GetSize() == 0) return FALSE;
	if(m_Properties.m_bShowing == FALSE) return FALSE;
	
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hIcon = m_Properties.m_hIcon; //(HICON)LoadImage(0,"c:\\x.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);
	nid.hWnd = this->m_hWnd;
	nid.uID = (UINT)(this->m_hWnd); //it's a unique ID
	strcpy(nid.szTip, (LPTSTR)(LPCTSTR)m_Properties.m_TipText);
	nid.uCallbackMessage = MY_TRAYINON_MSG; //自定义托盘消息
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;

	BOOL ret = Shell_NotifyIcon(NIM_ADD, &nid);
	if(ret)	
	{
		m_bTrayIconIsAdd = TRUE;
		m_TrayIconPosition.InitializePositionTracking(nid);
	}
	return ret;
}

BOOL CTrayIconWnd::ModifyTrayIcon()
{
	if(!m_bTrayIconIsAdd)
		return AddTrayIcon();
	
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP; 
	nid.hIcon = m_Properties.m_hIcon;
	strcpy(nid.szTip, m_Properties.m_TipText);
	m_TrayIconPosition.InitializePositionTracking(nid);
	return Shell_NotifyIcon(NIM_MODIFY, &nid);
}


BOOL CTrayIconWnd::DeleteTrayIcon()
{
	BOOL ret = Shell_NotifyIcon(NIM_DELETE, &nid);
	if(ret) m_bTrayIconIsAdd = FALSE;
	return ret;
}


BOOL CTrayIconWnd::ShowBalloon(LPCSTR lpCaption, LPCTSTR lpInfoText, INT iIcon, INT iTime)
{
	//add include path such as "C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\Include"
	//to the first include path list, to resolve the compile error, such as: 'uVersion' : is not a member of '_NOTIFYICONDATAA'
	nid.uVersion = NOTIFYICON_VERSION;
	if(Shell_NotifyIcon(NIM_SETVERSION, &nid) == FALSE)
		return FALSE; //不支持的版本,以此来判断能否弹出汽球提示框.
	
	if(iIcon<0 || iIcon>3)  iIcon = 1;
	nid.uFlags = NIF_INFO;
	strcpy(nid.szInfoTitle, lpCaption);
	strcpy(nid.szInfo, lpInfoText);
	nid.dwInfoFlags = iIcon;
	nid.uTimeout = iTime;
	BOOL ret = Shell_NotifyIcon(NIM_MODIFY, &nid); //注: 总是返回"TRUE",即使在Win98下!
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	return ret;
}


void CTrayIconWnd::GetTrayIconPosition(int &x, int &y)
{
	CPoint position(0,0);
	m_TrayIconPosition.Invalidate(); //强制重新计算
	m_TrayIconPosition.GetTrayIconPosition(position);
	x = position.x;
	y = position.y;
}

BOOL CTrayIconWnd::RecreateTrayIcon()
{
	m_bTrayIconIsAdd = FALSE;
	return AddTrayIcon();
}
