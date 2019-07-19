// DongTaiTSP.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "DongTaiTSP.h"
#include <locale.h>
#include "dongtaiguihua_tsp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}

/////////////////////////////////////////////////////////////////////////////
// CDongTaiTSP dialog


CDongTaiTSP::CDongTaiTSP(CWnd* pParent /*=NULL*/)
: CDialog(CDongTaiTSP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDongTaiTSP)
	//}}AFX_DATA_INIT
}


void CDongTaiTSP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDongTaiTSP)
	DDX_Control(pDX, IDC_EDIT3, m_dongtaitsptime);
	DDX_Control(pDX, IDC_EDIT2, m_dongtaifilecontent);
	DDX_Control(pDX, IDC_LIST_DongTaiTSP, m_dongtaitsp);
	DDX_Control(pDX, IDC_EDIT1, m_dongtaifile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDongTaiTSP, CDialog)
//{{AFX_MSG_MAP(CDongTaiTSP)
ON_BN_CLICKED(IDC_BUTTON_OpeFile, OnBUTTONOpeFile)
ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDongTaiTSP message handlers

void CDongTaiTSP::OnBUTTONOpeFile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog opendlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)_TEXT("TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||"), NULL);
	
	CString m_send;
	
	//显示对话框允许用户进行选择
	if (opendlg.DoModal()==IDOK)
	{
		//获得文件路径
		filepathname = opendlg.GetPathName();
		CString strData;
		m_dongtaifile.SetWindowText(filepathname);
		
		CStdioFile f;
		CString str;
		
		if (f.Open(filepathname, CFile::modeRead)){
			CString s;
			setlocale(LC_CTYPE, "chs");
			while (f.ReadString(s))
			{
				str += s;
				str += "\r\n";
			}
			f.Close();
			m_dongtaifilecontent.SetWindowText(str);
			return;
		}
	}
}

BOOL CDongTaiTSP::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_dongtaitsp.GetExtendedStyle();  
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	m_dongtaitsp.SetExtendedStyle(dwStyle);
	
	m_dongtaitsp.InsertColumn(0,"出发点",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(1,"{}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(2,"{1}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(3,"{2}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(4,"{3}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(5,"{1,2}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(6,"{1,3}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(7,"{2,3}",LVCFMT_CENTER,100);
	m_dongtaitsp.InsertColumn(8,"{1,2,3}",LVCFMT_CENTER,100);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDongTaiTSP::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	int city_number=4;
	int **process;			//求最短路径的过程矩阵
	int **distance;
	distance = new int*[city_number];
	int i,j;
	process = new int*[city_number];
	
	for (i = 0; i<city_number; i++)
	{
		process[i] = new int[1 << (city_number - 1)];
		distance[i] = new int[city_number];
	}
	Tsp tsp(city_number,filepathname,process,distance);		//初始化城市代价矩阵
	
	start = (unsigned long)GetCyCount();
	
	tsp.getShoretstDistance(process,distance);		//求出最短路径
	
	finish = (unsigned long)GetCyCount();
	
	tsp.printProcess(process);//将不存在的数值变为-1
	
	CString str;
	char string[10];
	for (i = 0; i<city_number; i++)
	{
		sprintf(string, " %d" , i);
		m_dongtaitsp.InsertItem(i,_T(string)); 
		for (j = 0; j<(1 << (city_number - 1)); j++)
		{
			sprintf(string, " %d" , process[i][j]);
			m_dongtaitsp.SetItemText(i,j+1,_T(string));
		}
	}
	
	CString strtime="最短路径长度为:";
	sprintf(string, " %d," , process[0][7]);
	strtime+=string;
	strtime+="运行时间为:";
	sprintf(string, " %d纳秒" , finish - start);
	strtime+=string;
	m_dongtaitsptime.SetWindowText( strtime);
}
