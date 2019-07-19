#if !defined(AFX_DONGTAI01_H__8D9D1C5C_0DB2_4508_83BC_FC79E84A41AE__INCLUDED_)
#define AFX_DONGTAI01_H__8D9D1C5C_0DB2_4508_83BC_FC79E84A41AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DongTai01.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDongTai01 dialog

class CDongTai01 : public CDialog
{
// Construction
public:
	CDongTai01(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDongTai01)
	enum { IDD = IDD_DIALOG_DongTai01 };
	CEdit	m_dongtai01time;
	CListCtrl	m_dongtai01list;
	CEdit	m_dongtai01filecontent2;
	CEdit	m_dongtai01filecontent1;
	CEdit	m_dongtai01file2;
	CEdit	m_dongtai01file1;
	CString filepathname1;
	CString filepathname2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDongTai01)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDongTai01)
	afx_msg void OnBUTTONOpenFile1();
	afx_msg void OnBUTTONOpenFile2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONGTAI01_H__8D9D1C5C_0DB2_4508_83BC_FC79E84A41AE__INCLUDED_)
