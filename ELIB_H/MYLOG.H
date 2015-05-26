#if !defined(AFX_MYLOG_H__B92C1C84_06B4_47ED_AAC1_54774DFC28D0__INCLUDED_)
#define AFX_MYLOG_H__B92C1C84_06B4_47ED_AAC1_54774DFC28D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyLog.h : header file
// Authored by liigo

//#define LOG_ON  //!!!ȡ���궨��LOG_ON���ɹر�log 

/*
��־ʹ��ָ�ϣ�
 1������ȫ�ֺ��� log(char*, ...), �������printf()�Ĳ�����ͬ��
    ����log("This is %s, %d", s, i); (char *s="liigo"; int i=100;)
 2�����ú귽�� LOG(x), �������Ϊ��������(CString,char*,int,double��)��
    ����LOG(s); LOG(i); (char *s="liigo"; int i=100;)
 3������ CMyLog ��ʵ��, �������䷽����
	����CMyLog mylog; mylog.print(s); mylog.print("%s",s);

��־����رգ�
	��־�Ĵ���ر��ɺ� LOG_ON �����ơ�

��־���λ�ã�
	Ĭ��������ļ� c:\__MyLog.txt ��, ͬʱ��VC���Դ��ڻ��ԡ�
	��д������ݽ�׷�ӵ����ı�ĩβ, �ļ������ڽ��Զ�������

���ߣ�liigo, 2004/2005, ������liigo@sina.com
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