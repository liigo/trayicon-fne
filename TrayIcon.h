// NewLib.h : main header file for the NewLib DLL
//

#if !defined(AFX_NewLib_H__B872731D_4E26_4AB0_9079_7CDA094B5861__INCLUDED_)
#define AFX_NewLib_H__B872731D_4E26_4AB0_9079_7CDA094B5861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#define LIB_SUPPORT_OS		(_LIB_OS  (__OS_WIN))
#define DT_SUPPORT_OS		(_DT_OS   (__OS_WIN))
#define CMD_SUPPORT_OS		(_CMD_OS  (__OS_WIN))
#define PROP_SUPPORT_OS		(_PROP_OS (__OS_WIN))
#define EVENT_SUPPORT_OS	(_EVENT_OS(__OS_WIN))


/////////////////////////////////////////////////////////////////////////////
// CNewLibApp
// See NewLib.cpp for the implementation of this class
//

class CNewLibApp : public CWinApp
{
public:
	CNewLibApp();
	~CNewLibApp();
public:
	CWnd m_pMainWnd;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewLibApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CNewLibApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NewLib_H__B872731D_4E26_4AB0_9079_7CDA094B5861__INCLUDED_)
