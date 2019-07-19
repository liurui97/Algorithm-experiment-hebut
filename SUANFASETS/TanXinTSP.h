#if !defined(AFX_TANXINTSP_H__3176E8A8_CF0A_4088_9660_66592D6BDB1A__INCLUDED_)
#define AFX_TANXINTSP_H__3176E8A8_CF0A_4088_9660_66592D6BDB1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TanXinTSP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTanXinTSP dialog

class CTanXinTSP : public CDialog
{
// Construction
public:
	CTanXinTSP(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTanXinTSP)
	enum { IDD = IDD_DIALOG_TanXinTSP };
	CEdit	m_tanxintsptime;
	CListCtrl	m_tanxintsplist;
	CEdit	m_tanxintspfilecontent;
	CEdit	m_tanxintspfile;
		CString filepathname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTanXinTSP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTanXinTSP)
	afx_msg void OnBUTTONOpenFile();
	afx_msg void OnBUTTONCalculate();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANXINTSP_H__3176E8A8_CF0A_4088_9660_66592D6BDB1A__INCLUDED_)
