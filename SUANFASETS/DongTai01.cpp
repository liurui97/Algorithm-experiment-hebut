// DongTai01.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "DongTai01.h"
#include <locale.h>
#include "dongtaiguihua_01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CDongTai01 dialog


CDongTai01::CDongTai01(CWnd* pParent /*=NULL*/)
	: CDialog(CDongTai01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDongTai01)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDongTai01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDongTai01)
	DDX_Control(pDX, IDC_EDIT5, m_dongtai01time);
	DDX_Control(pDX, IDC_LIST_DongTai01, m_dongtai01list);
	DDX_Control(pDX, IDC_EDIT4, m_dongtai01filecontent2);
	DDX_Control(pDX, IDC_EDIT3, m_dongtai01filecontent1);
	DDX_Control(pDX, IDC_EDIT2, m_dongtai01file2);
	DDX_Control(pDX, IDC_EDIT1, m_dongtai01file1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDongTai01, CDialog)
	//{{AFX_MSG_MAP(CDongTai01)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile1, OnBUTTONOpenFile1)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile2, OnBUTTONOpenFile2)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDongTai01 message handlers

void CDongTai01::OnBUTTONOpenFile1() 
{
	// TODO: Add your control notification handler code here
	CFileDialog opendlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), NULL);
	
	CString m_send;

	//显示对话框允许用户进行选择
	if (opendlg.DoModal()==IDOK)
	{
		//获得文件路径
		filepathname1 = opendlg.GetPathName();
		CString strData;
		m_dongtai01file1.SetWindowText(filepathname1);
		
		CStdioFile f;
		CString str;
		
		if (f.Open(filepathname1, CFile::modeRead)){
			CString s;
			setlocale(LC_CTYPE, "chs");
			while (f.ReadString(s))
			{
				str += s;
			}
			f.Close();
			m_dongtai01filecontent1.SetWindowText(str);
			return;
		}
	}
}

void CDongTai01::OnBUTTONOpenFile2() 
{
	// TODO: Add your control notification handler code here
	CFileDialog opendlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), NULL);
	
	CString m_send;

	//显示对话框允许用户进行选择
	if (opendlg.DoModal()==IDOK)
	{
		//获得文件路径
		filepathname2 = opendlg.GetPathName();
		CString strData;
		m_dongtai01file2.SetWindowText(filepathname2);
		
		CStdioFile f;
		CString str;
		
		if (f.Open(filepathname2, CFile::modeRead)){
			CString s;
			setlocale(LC_CTYPE, "chs");
			while (f.ReadString(s))
			{
				str += s;
			}
			f.Close();
			m_dongtai01filecontent2.SetWindowText(str);
			return;
		}
	}
}

BOOL CDongTai01::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_dongtai01list.GetExtendedStyle();  
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	m_dongtai01list.SetExtendedStyle(dwStyle);
	
	m_dongtai01list.InsertColumn(0,"",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(1,"1",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(2,"2",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(3,"3",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(4,"4",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(5,"5",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(6,"6",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(7,"7",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(8,"8",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(9,"9",LVCFMT_CENTER,80);
	m_dongtai01list.InsertColumn(10,"10",LVCFMT_CENTER,80);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDongTai01::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	int maxValue;
	FILE *fp;
	char *ch = filepathname1.GetBuffer(filepathname1.GetLength() + 1);
	int i,j,w[5],v[5];
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<5; i++)
		{
			fscanf(fp,"%d",&w[i]);
		}
		fclose(fp);
	}
	ch = filepathname2.GetBuffer(filepathname2.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<5; i++)
		{
			fscanf(fp,"%d",&v[i]);
		}
		fclose(fp);
	}
	start = (unsigned long)GetCyCount();
	maxValue=KnapSack(5, w, v);
	finish = (unsigned long)GetCyCount();
	char string[10];

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < C+1; j++)
		{
			if(j==0)
			{
				sprintf(string, " %d" , i);
				m_dongtai01list.InsertItem(i,_T(string)); 
			}
			else
			{
				sprintf(string, " %d" , V[i][j - 1]);
				m_dongtai01list.SetItemText(i,j,_T(string));
			}
		}
	}
	CString strtime;
	strtime+="装入的物品为:";
	for (i = 0; i < 5; i++)
	{
		sprintf(string, " %d," , x[i]);	
		strtime+=string;
	}
	strtime+="最大价值为:";
	sprintf(string, " %d," , maxValue);	
	strtime+=string;
	strtime+="运行时间为:";
	sprintf(string, " %d纳秒" , finish-start);
	strtime+=string;
	m_dongtai01time.SetWindowText( strtime);
}
