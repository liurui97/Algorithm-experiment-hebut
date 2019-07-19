#if !defined(AFX_HUISUTSP_H__A71CEA3E_D1DD_46AC_9B65_F78CA0F53592__INCLUDED_)
#define AFX_HUISUTSP_H__A71CEA3E_D1DD_46AC_9B65_F78CA0F53592__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HuiSuTSP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHuiSuTSP dialog

class CHuiSuTSP : public CDialog
{
// Construction
public:
	CHuiSuTSP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHuiSuTSP)
	enum { IDD = IDD_DIALOG_HuiSuTSP };
	CEdit	m_huisutspresult;
	CEdit	m_huisutspfilecontent;
	CEdit	m_huisutspfile;
	CString filepathname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuiSuTSP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHuiSuTSP)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONCalulate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUISUTSP_H__A71CEA3E_D1DD_46AC_9B65_F78CA0F53592__INCLUDED_)
