#if !defined(AFX_TANXINDUOJI_H__B56D6A9C_D1A9_438E_B932_C89E601175E5__INCLUDED_)
#define AFX_TANXINDUOJI_H__B56D6A9C_D1A9_438E_B932_C89E601175E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TanXinDuoji.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTanXinDuoji dialog

class CTanXinDuoji : public CDialog
{
// Construction
public:
	CTanXinDuoji(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTanXinDuoji)
	enum { IDD = IDD_DIALOG_TanXinDuoJi };
	CEdit	m_tanxinduojitime;
	CListCtrl	m_tanxinduojilist;
	CEdit	m_tanxinduojifilecontent;
	CEdit	m_tanxinduojifile;
	CEdit	m_tanxinduojizuoyenum;
	CEdit	m_tanxinduojijiqinum;
	CString filepathname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTanXinDuoji)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTanXinDuoji)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONCalculate();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANXINDUOJI_H__B56D6A9C_D1A9_438E_B932_C89E601175E5__INCLUDED_)
