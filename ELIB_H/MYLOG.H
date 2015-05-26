#if !defined(AFX_MYLOG_H__B92C1C84_06B4_47ED_AAC1_54774DFC28D0__INCLUDED_)
#define AFX_MYLOG_H__B92C1C84_06B4_47ED_AAC1_54774DFC28D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyLog.h : header file
// Authored by liigo

//#define LOG_ON  //!!!取消宏定义LOG_ON即可关闭log 

/*
日志使用指南：
 1、调用全局函数 log(char*, ...), 其参数与printf()的参数相同。
    例：log("This is %s, %d", s, i); (char *s="liigo"; int i=100;)
 2、调用宏方法 LOG(x), 其参数可为多种类型(CString,char*,int,double等)。
    例：LOG(s); LOG(i); (char *s="liigo"; int i=100;)
 3、定义 CMyLog 类实例, 并调用其方法。
	例：CMyLog mylog; mylog.print(s); mylog.print("%s",s);

日志打开与关闭：
	日志的打开与关闭由宏 LOG_ON 来控制。

日志输出位置：
	默认输出到文件 c:\__MyLog.txt 中, 同时在VC调试窗口回显。
	新写入的数据将追加到该文本末尾, 文件不存在将自动创建。

作者：liigo, 2004/2005, 大连。liigo@sina.com
*/


void log(const char* lpszFormat, ...);

#ifdef LOG_ON
  #define LOG(x) {CMyLog _my_log; _my_log.print(x);}
#else 
  #define LOG(x)
#endif






/////////////////////////////////////////////////////////////////////////////
// CMyLog command target

class CMyLog : public CCmdTarget
{
	DECLARE_DYNCREATE(CMyLog)

	CMyLog();           // protected constructor used by dynamic creation
    CMyLog(CString filename);
    ~CMyLog();
// Attributes
public:

// Operations
public:
	void print(double d);
	void print(int i);
	CArchive* GetArchive();
	void print(CString str);
    void print(char *p);
	void print(const char* lpszFormat, ...);
	void print(const char* lpszFormat, va_list args);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLog)
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CMyLog)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void Init();
    CString filename;
    CFile *file;
    //CArchive ar;
};

/////////////////////////////////////////////////////////////////////////////


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.




#endif // !defined(AFX_MYLOG_H__B92C1C84_06B4_47ED_AAC1_54774DFC28D0__INCLUDED_)
