// MyLog.cpp : implementation file
// Authored by liigo

#include "stdafx.h"
#include <ostream.h>
#include "mylog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//全局函数log，方便用户使用
void log(const char* lpszFormat, ...)
{
#ifdef LOG_ON
	va_list args;
	va_start(args, lpszFormat);
	CMyLog myLog; myLog.print(lpszFormat, args);
	va_end(args);
#endif
}



/////////////////////////////////////////////////////////////////////////////
// CMyLog

IMPLEMENT_DYNCREATE(CMyLog, CCmdTarget)

void CMyLog::Init()
{
	try
	{
		if(file) delete file;
		file = new CFile(filename,CFile::modeWrite | CFile::modeNoTruncate | CFile::modeCreate);
		file->SeekToEnd();
		CArchive ar(file, CArchive::store);
		CTime t=CTime::GetCurrentTime();
		CString sTime;
		sTime=t.Format("[%Y-%m-%d %H:%M:%S] ");
		ar.WriteString(sTime);
		//ar.WriteString(sTime+"Initialize the log by liigo @ "+filename+"\n");
	}
	catch(...) { ASSERT(FALSE); }
}


CMyLog::CMyLog()
{
#ifdef LOG_ON
    this->filename="c:\\__MyLog.txt";
	this->file = NULL;
    Init();
#endif
}

CMyLog::CMyLog(CString filename)
{
#ifdef LOG_ON
    this->filename=filename;
    Init();
#endif
}

CMyLog::~CMyLog()
{
#ifdef LOG_ON
    file->Close();
    delete file;
    //delete ar;
#endif
}


BEGIN_MESSAGE_MAP(CMyLog, CCmdTarget)
	//{{AFX_MSG_MAP(CMyLog)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyLog message handlers

void CMyLog::print(CString str)
{
#ifdef LOG_ON
    //CTime t=CTime::GetCurrentTime();
    //CString sTime;
    //sTime=t.Format("\n[%Y-%m-%d %H:%M:%S] ");

    CArchive ar(file, CArchive::store);
    ar.WriteString(str + "\n");
    //ar.WriteString(sTime + str + "\n");

//    char* s=(LPSTR)(LPCSTR)str;
//    cout << s << endl;
	TRACE(str + "\n");
#endif
}

CArchive* CMyLog::GetArchive()
{
    return new CArchive(file, CArchive::store);
}

void CMyLog::print(int i)
{
    CString s;
    s.Format("%d",i);
    this->print(s);
}

void CMyLog::print(double d)
{
    CString s;
    s.Format("%f",d);
    this->print(s);
}

void CMyLog::print(char *p)
{
    CString s(p);
    this->print(s);
}

void CMyLog::print(const char* lpszFormat, ...)
{
	va_list args;
	va_start(args, lpszFormat);
	CString s;
	s.FormatV(lpszFormat,args);
	this->print(s);
	va_end(args);
}

void CMyLog::print(const char* lpszFormat, va_list args)
{
	CString s;
	s.FormatV(lpszFormat,args);
	this->print(s);
}