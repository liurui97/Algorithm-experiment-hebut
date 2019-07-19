#if !defined(AFX_FENZHI01BAG_H__0DF856B3_3F2F_408A_BE90_34D4266E254E__INCLUDED_)
#define AFX_FENZHI01BAG_H__0DF856B3_3F2F_408A_BE90_34D4266E254E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenZhi01Bag.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenZhi01Bag dialog

class CFenZhi01Bag : public CDialog
{
// Construction
public:
	CFenZhi01Bag(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFenZhi01Bag)
	enum { IDD = IDD_DIALOG_FenZhi01 };
	CEdit	m_fenzhi01result;
	CEdit	m_fenzhi01filecontent2;
	CEdit	m_fenzhi01filecontent1;
	CEdit	m_fenzhi01file2;
	CEdit	m_fenzhi01file1;
	CString filepathname1;
	CString filepathname2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenZhi01Bag)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFenZhi01Bag)
	afx_msg void OnBUTTONOpenFile1();
	afx_msg void OnBUTTONOpenFile2();
	afx_msg void OnBUTTONCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENZHI01BAG_H__0DF856B3_3F2F_408A_BE90_34D4266E254E__INCLUDED_)
