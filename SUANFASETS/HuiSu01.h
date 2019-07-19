#if !defined(AFX_HUISU01_H__FABDACDE_15D2_4767_A4D8_18A85C079049__INCLUDED_)
#define AFX_HUISU01_H__FABDACDE_15D2_4767_A4D8_18A85C079049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HuiSu01.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHuiSu01 dialog

class CHuiSu01 : public CDialog
{
// Construction
public:
	CHuiSu01(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHuiSu01)
	enum { IDD = IDD_DIALOG_HuiSu01 };
	CEdit	m_huisu01filecontent2;
	CEdit	m_huisu01filecontent1;
	CEdit	m_huisu01file2;
	CEdit	m_huisu01file1;
	CEdit	m_huisu01result;
	CString filepathname1;
	CString filepathname2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuiSu01)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHuiSu01)
	afx_msg void OnBUTTONOpenFile1();
	afx_msg void OnBUTTONOpenFile2();
	afx_msg void OnBUTTONCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUISU01_H__FABDACDE_15D2_4767_A4D8_18A85C079049__INCLUDED_)
