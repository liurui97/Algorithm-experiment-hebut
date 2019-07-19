// SUANFASETSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "SUANFASETSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSUANFASETSDlg dialog

CSUANFASETSDlg::CSUANFASETSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSUANFASETSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSUANFASETSDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSUANFASETSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSUANFASETSDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSUANFASETSDlg, CDialog)
	//{{AFX_MSG_MAP(CSUANFASETSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSUANFASETSDlg message handlers

BOOL CSUANFASETSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_tab.InsertItem(0, _T("分治最近点对"));
	m_tab.InsertItem(1, _T("分治循环赛"));
	m_tab.InsertItem(2,_T("动态规划TSP"));
	m_tab.InsertItem(3,_T("动态规划0/1"));
	m_tab.InsertItem(4,_T("贪心法TSP"));
	m_tab.InsertItem(5,_T("贪心多机调度"));
	m_tab.InsertItem(6,_T("贪心法背包"));
	m_tab.InsertItem(7,_T("回溯法TSP"));
	m_tab.InsertItem(8,_T("回溯法0/1"));
	m_tab.InsertItem(9,_T("分支限界TSP"));
	m_tab.InsertItem(10,_T("分支限界0/1"));

	cyclerace_page.Create(IDD_DIALOG_CycleRace, &m_tab);
	closestpair_page.Create(IDD_DIALOG_ClosestPair, &m_tab);
	dongtaitsp_page.Create(IDD_DIALOG_DongTaiTSP,&m_tab);
	dongtai01_page.Create(IDD_DIALOG_DongTai01,&m_tab);
	tanxintsp_page.Create(IDD_DIALOG_TanXinTSP,&m_tab);
	tanxinduoji_page.Create(IDD_DIALOG_TanXinDuoJi,&m_tab);
	tanxinbeibao_page.Create(IDD_DIALOG_TanXinBeibao,&m_tab);
	huisutsp_page.Create(IDD_DIALOG_HuiSuTSP,&m_tab);
	huisu01_page.Create(IDD_DIALOG_HuiSu01,&m_tab);
	fenzhitsp_page.Create(IDD_DIALOG_FenZhiTSP,&m_tab);
	fenzhi01bag_page.Create(IDD_DIALOG_FenZhi01,&m_tab);

	CRect rec;
	m_tab.GetClientRect(rec);

	//定位选项卡的位置，这里可以根据自己调节偏移量
	rec.bottom -= 2;
	rec.left += 1;
	rec.top += 27;
	rec.right -= 3;
	
	cyclerace_page.MoveWindow(&rec);
	closestpair_page.MoveWindow(&rec);
	dongtaitsp_page.MoveWindow(&rec);
	dongtai01_page.MoveWindow(&rec);
	tanxintsp_page.MoveWindow(&rec);
	tanxinduoji_page.MoveWindow(&rec);
	tanxinbeibao_page.MoveWindow(&rec);
	huisutsp_page.MoveWindow(&rec);
	huisu01_page.MoveWindow(&rec);
	fenzhitsp_page.MoveWindow(&rec);
	fenzhi01bag_page.MoveWindow(&rec);

	//显示初始界面
	cyclerace_page.ShowWindow(SW_SHOW);
	closestpair_page.ShowWindow(SW_HIDE);
	dongtaitsp_page.ShowWindow(SW_HIDE);
	dongtai01_page.ShowWindow(SW_HIDE);
	tanxintsp_page.ShowWindow(SW_HIDE);
	tanxinduoji_page.ShowWindow(SW_HIDE);
	tanxinbeibao_page.ShowWindow(SW_HIDE);
	huisutsp_page.ShowWindow(SW_HIDE);
	huisu01_page.ShowWindow(SW_HIDE);
	fenzhitsp_page.ShowWindow(SW_HIDE);
	fenzhi01bag_page.ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSUANFASETSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSUANFASETSDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSUANFASETSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSUANFASETSDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	switch (m_tab.GetCurSel())
	{
	case 0:
		cyclerace_page.ShowWindow(SW_SHOW);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 1:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_SHOW);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 2:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_SHOW);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 3:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_SHOW);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 4:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_SHOW);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 5:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_SHOW);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 6:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_SHOW);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 7:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_SHOW);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 8:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_SHOW);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 9:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_SHOW);
		fenzhi01bag_page.ShowWindow(SW_HIDE);
		break;
	case 10:
		cyclerace_page.ShowWindow(SW_HIDE);
		closestpair_page.ShowWindow(SW_HIDE);
		dongtaitsp_page.ShowWindow(SW_HIDE);
		dongtai01_page.ShowWindow(SW_HIDE);
		tanxintsp_page.ShowWindow(SW_HIDE);
		tanxinduoji_page.ShowWindow(SW_HIDE);
		tanxinbeibao_page.ShowWindow(SW_HIDE);
		huisutsp_page.ShowWindow(SW_HIDE);
		huisu01_page.ShowWindow(SW_HIDE);
		fenzhitsp_page.ShowWindow(SW_HIDE);
		fenzhi01bag_page.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
}
