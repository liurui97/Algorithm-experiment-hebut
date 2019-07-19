#if !defined(AFX_CLOSESTPAIR_H__F7F1CE9D_26CD_44E2_8652_8CD2C4424CD3__INCLUDED_)
#define AFX_CLOSESTPAIR_H__F7F1CE9D_26CD_44E2_8652_8CD2C4424CD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClosestPair.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClosestPair dialog

class CClosestPair : public CDialog
{
// Construction
public:
	CClosestPair(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClosestPair)
	enum { IDD = IDD_DIALOG_ClosestPair };
	CEdit	m_closetpairresullt;
	CEdit	m_cycletime;
	CListCtrl	m_cyclelist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClosestPair)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClosestPair)
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONCalculate();
	afx_msg void OnBUTTONNCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOSESTPAIR_H__F7F1CE9D_26CD_44E2_8652_8CD2C4424CD3__INCLUDED_)
