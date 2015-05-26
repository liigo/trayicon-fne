#if !defined(AFX_NEWWND_H__CD195C4A_CEAE_415E_83A3_AE063ADF0ABC__INCLUDED_)
#define AFX_NEWWND_H__CD195C4A_CEAE_415E_83A3_AE063ADF0ABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewWnd.h : header file
//
#include "stdafx.h"
#include "TrayIconPosition.h"


#define MY_TRAYINON_MSG  (WM_APP + 100) //自定义托盘消息
//注：如果消息值过大，如175199125，则不能得到消息通知。

class CTrayIconWnd_PropertyInfo : public CPropertyInfo
{
public:
	DWORD   m_Version, m_LastVersion;
	CString m_TipText;
	CFreqMem m_IconData;
	HICON    m_hIcon;    HICON m_Default_hIcon;
	BOOL     m_bShowing;

public:
	CTrayIconWnd_PropertyInfo ()  { }

	virtual void init ();
	virtual BOOL Serialize (CArchive& ar);
	HICON GetDefaultIconHandle(void);
};


/////////////////////////////////////////////////////////////////////////////
// CTrayIconWnd window


class CTrayIconWnd : public CWnd
{
// Construction
public:
	CTrayIconWnd();

// Attributes
public:
	DWORD m_dwWinFormID, m_dwUnitID;
	BOOL m_blInDesignMode;

	CTrayIconWnd_PropertyInfo m_Properties;

private:
	BOOL m_bTrayIconIsAdd;
	CTrayIconPosition m_TrayIconPosition;

// Operations
public:

	BOOL Create (HWND hParentWnd, DWORD dwStyle, UINT uID, INT x, INT y, INT cx, INT cy);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayIconWnd)
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL RecreateTrayIcon(void);
	void GetTrayIconPosition(int &x, int &y);
	BOOL ShowBalloon(LPCSTR lpCaption, LPCTSTR lpInfoText, INT iIcon=0, INT iTime=0);
	BOOL DeleteTrayIcon(void);
	BOOL AddTrayIcon(void);
	BOOL ModifyTrayIcon();
	LPTSTR MessageBox();
	virtual ~CTrayIconWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTrayIconWnd)
	afx_msg void OnPaint();

	afx_msg LRESULT onTrayIconNotify(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	NOTIFYICONDATA nid;
};

/////////////////////////////////////////////////////////////////////////////



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWWND_H__CD195C4A_CEAE_415E_83A3_AE063ADF0ABC__INCLUDED_)
