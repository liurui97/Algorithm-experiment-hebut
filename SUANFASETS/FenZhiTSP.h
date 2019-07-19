#if !defined(AFX_FENZHITSP_H__ADC27C2B_E71F_4C70_BB55_57EBBA4EE342__INCLUDED_)
#define AFX_FENZHITSP_H__ADC27C2B_E71F_4C70_BB55_57EBBA4EE342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenZhiTSP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenZhiTSP dialog

class CFenZhiTSP : public CDialog
{
// Construction
public:
	CFenZhiTSP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFenZhiTSP)
	enum { IDD = IDD_DIALOG_FenZhiTSP };
	CEdit	m_fenzhitspresult;
	CEdit	m_fenzhitspfilecontent;
	CEdit	m_fenzhitspfile;
	CString filepathname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenZhiTSP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFenZhiTSP)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENZHITSP_H__ADC27C2B_E71F_4C70_BB55_57EBBA4EE342__INCLUDED_)
