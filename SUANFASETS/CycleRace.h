#if !defined(AFX_CYCLERACE_H__8F0A75C6_DF67_4538_85B8_89FAD463D694__INCLUDED_)
#define AFX_CYCLERACE_H__8F0A75C6_DF67_4538_85B8_89FAD463D694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CycleRace.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CCycleRace dialog

class CCycleRace : public CDialog
{
// Construction
public:
	CCycleRace(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCycleRace)
	enum { IDD = IDD_DIALOG_CycleRace };
	CEdit	m_cycleresult;
	CEdit	m_fliecontent;
	CEdit	m_filepathname;
	CString filepathname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCycleRace)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCycleRace)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONCalculate();
	afx_msg void OnBUTTONCalculate1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CYCLERACE_H__8F0A75C6_DF67_4538_85B8_89FAD463D694__INCLUDED_)
