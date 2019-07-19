// SUANFASETS.h : main header file for the SUANFASETS application
//

#if !defined(AFX_SUANFASETS_H__4A3BDBEC_DF61_4633_81E9_95072C186FEE__INCLUDED_)
#define AFX_SUANFASETS_H__4A3BDBEC_DF61_4633_81E9_95072C186FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSUANFASETSApp:
// See SUANFASETS.cpp for the implementation of this class
//

class CSUANFASETSApp : public CWinApp
{
public:
	CSUANFASETSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSUANFASETSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSUANFASETSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUANFASETS_H__4A3BDBEC_DF61_4633_81E9_95072C186FEE__INCLUDED_)
