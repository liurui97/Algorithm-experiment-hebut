// ClosestPair.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "ClosestPair.h"
#include "cycle.h"
#include <sys/timeb.h>
#include <windows.h>

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClosestPair dialog


CClosestPair::CClosestPair(CWnd* pParent /*=NULL*/)
	: CDialog(CClosestPair::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClosestPair)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CClosestPair::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClosestPair)
	DDX_Control(pDX, IDC_EDIT2, m_closetpairresullt);
	DDX_Control(pDX, IDC_LIST1, m_cyclelist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClosestPair, CDialog)
	//{{AFX_MSG_MAP(CClosestPair)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	ON_BN_CLICKED(IDC_BUTTON_NCalculate, OnBUTTONNCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClosestPair message handlers

BOOL CClosestPair::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_cyclelist.GetExtendedStyle();  
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	m_cyclelist.SetExtendedStyle(dwStyle);

	m_cyclelist.InsertColumn(0,"编号",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(1,"第1天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(2,"第2天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(3,"第3天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(4,"第4天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(5,"第5天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(6,"第6天",LVCFMT_LEFT,100);
	m_cyclelist.InsertColumn(7,"第7天",LVCFMT_LEFT,100);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClosestPair::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	CString str;
	GetDlgItemText(IDC_EDIT1,str);
	int i,j,k;
	k=atoi(str);

	start = (unsigned long)GetCyCount();
	GameTable2(1, (int)pow(2.0, k));

	finish = (unsigned long)GetCyCount();
	
	char string[10];
	sprintf(string, " %d" , finish-start);
	CString timestr="运行时间为:";
	timestr+=string;
	timestr+="纳秒";
	m_closetpairresullt.SetWindowText(timestr);
	m_cyclelist.DeleteAllItems();

	for (i = 1; i <= pow(2.0, k); i++){
		for (j = 1; j <= pow(2.0, k); j++)
		{
			sprintf(string, " %d" , a[i][j]);
			if(j==1)
				m_cyclelist.InsertItem(i-1,_T(string)); 
			else
				m_cyclelist.SetItemText(i-1, j-1, _T(string));
		}
	}
}

void CClosestPair::OnBUTTONNCalculate() 
{
	// TODO: Add your control notification handler code here
	CString str;
	unsigned long start, finish;

	GetDlgItemText(IDC_EDIT1,str);
	int i,j,k;
	k=atoi(str);
	start = (unsigned long)GetCyCount();
	GameTable(k);
	finish = (unsigned long)GetCyCount();
	char string[10];

	sprintf(string, " %d" , finish-start);
	CString timestr="运行时间为:";
	timestr+=string;
	timestr+="纳秒";
	m_closetpairresullt.SetWindowText(timestr);
	m_cyclelist.DeleteAllItems();

	for (i = 1; i <= pow(2.0, k); i++){
		for (j = 1; j <= pow(2.0, k); j++)
		{
			sprintf(string, " %d" , a[i][j]);
			if(j==1)
				m_cyclelist.InsertItem(i-1,_T(string)); 
			else
				m_cyclelist.SetItemText(i-1, j-1, _T(string));
		}
	}
}
