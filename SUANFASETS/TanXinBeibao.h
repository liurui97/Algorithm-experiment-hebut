#if !defined(AFX_TANXINBEIBAO_H__7098F398_949F_4995_843C_6E93928F9F11__INCLUDED_)
#define AFX_TANXINBEIBAO_H__7098F398_949F_4995_843C_6E93928F9F11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TanXinBeibao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTanXinBeibao dialog

class CTanXinBeibao : public CDialog
{
// Construction
public:
	CTanXinBeibao(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTanXinBeibao)
	enum { IDD = IDD_DIALOG_TanXinBeibao };
	CEdit	m_tanxinbeibaofilecontent1;
	CEdit	m_tanxinbeibaofilecontent2;
	CEdit	m_tanxinbeibaofile1;
	CEdit	m_tanxinbeibaofile2;
	CEdit	m_tanxinbeibaoresult;
	CString filepathname1;
	CString filepathname2;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTanXinBeibao)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTanXinBeibao)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONOpenFile2();
	afx_msg void OnBUTTONCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANXINBEIBAO_H__7098F398_949F_4995_843C_6E93928F9F11__INCLUDED_)
