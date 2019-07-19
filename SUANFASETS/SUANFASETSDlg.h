// SUANFASETSDlg.h : header file
//

#if !defined(AFX_SUANFASETSDLG_H__70495A56_13DF_40FD_BD37_D83DD91BC567__INCLUDED_)
#define AFX_SUANFASETSDLG_H__70495A56_13DF_40FD_BD37_D83DD91BC567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CycleRace.h"
#include "ClosestPair.h"
#include "DongTaiTSP.h"
#include "DongTai01.h"
#include "TanXinTSP.h"
#include "TanXinDuoji.h"
#include "TanXinBeibao.h"
#include "HuiSuTSP.h"
#include "HuiSu01.h"
#include "FenZhiTSP.h"
#include "FenZhi01Bag.h"
#include "time.h"

#ifndef _FILE_DEFINED
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

/////////////////////////////////////////////////////////////////////////////
// CSUANFASETSDlg dialog

class CSUANFASETSDlg : public CDialog
{
// Construction
public:
	CSUANFASETSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSUANFASETSDlg)
	enum { IDD = IDD_SUANFASETS_DIALOG };
	CTabCtrl	m_tab;
	CCycleRace cyclerace_page;
	CClosestPair closestpair_page;
	CDongTaiTSP dongtaitsp_page;
	CDongTai01 dongtai01_page;
	CTanXinTSP tanxintsp_page;
	CTanXinDuoji tanxinduoji_page;
	CTanXinBeibao tanxinbeibao_page;
	CHuiSuTSP huisutsp_page;
	CHuiSu01 huisu01_page;
	CFenZhiTSP fenzhitsp_page;
	CFenZhi01Bag fenzhi01bag_page;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSUANFASETSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSUANFASETSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUANFASETSDLG_H__70495A56_13DF_40FD_BD37_D83DD91BC567__INCLUDED_)
