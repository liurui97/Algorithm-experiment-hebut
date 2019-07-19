// FenZhi01.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "FenZhi01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenZhi01 dialog


CFenZhi01::CFenZhi01(CWnd* pParent /*=NULL*/)
	: CDialog(CFenZhi01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenZhi01)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFenZhi01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenZhi01)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenZhi01, CDialog)
	//{{AFX_MSG_MAP(CFenZhi01)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenZhi01 message handlers
