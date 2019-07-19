// TanXinDuoji.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "TanXinDuoji.h"
#include <locale.h>
#include "tanxinfa_duojidiaodu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CTanXinDuoji dialog


CTanXinDuoji::CTanXinDuoji(CWnd* pParent /*=NULL*/)
	: CDialog(CTanXinDuoji::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTanXinDuoji)
	//}}AFX_DATA_INIT
}


void CTanXinDuoji::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTanXinDuoji)
	DDX_Control(pDX, IDC_EDIT3, m_tanxinduojitime);
	DDX_Control(pDX, IDC_LIST1, m_tanxinduojilist);
	DDX_Control(pDX, IDC_EDIT8, m_tanxinduojifilecontent);
	DDX_Control(pDX, IDC_EDIT5, m_tanxinduojifile);
	DDX_Control(pDX, IDC_EDIT1, m_tanxinduojizuoyenum);
	DDX_Control(pDX, IDC_EDIT2, m_tanxinduojijiqinum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTanXinDuoji, CDialog)
	//{{AFX_MSG_MAP(CTanXinDuoji)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile, OnBUTTONOpenFile)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTanXinDuoji message handlers

void CTanXinDuoji::OnBUTTONOpenFile() 
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
		m_tanxinduojifile.SetWindowText(filepathname);
		
		CStdioFile f;
		CString str;
		
		if (f.Open(filepathname ,CFile::modeRead)){
			CString s;
			setlocale(LC_CTYPE, "chs");
			while (f.ReadString(s))
			{
				str += s;
				str +="\r\n";
			}
			f.Close();
			m_tanxinduojifilecontent.SetWindowText(str);
			return;
		}
	}
}

void CTanXinDuoji::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	//获取控件中的内容
	unsigned long start, finish;
	CString zuoyenum,jiqinum,strData;
	GetDlgItemText(IDC_EDIT1,zuoyenum);
	GetDlgItemText(IDC_EDIT2,jiqinum);

	int i,j,zuoye,jiqi;
	zuoye=atoi(zuoyenum);
	jiqi=atoi(jiqinum);

	//读文件
	char string[2];
	FILE *fp;
	char *ch = filepathname.GetBuffer(filepathname.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<zuoye; i++)
		{
			fscanf(fp,"%d",&t[i].hour);
			t[i].number = i + 1;
		}
		fclose(fp);
	}
	start = (unsigned long)GetCyCount();
	bubble_sort(t, zuoye);

	for ( i = 0; i < jiqi; i++)
	{
		d[i] = 0;
	}

	MultiMachine(t, zuoye, d, jiqi);
	finish = (unsigned long)GetCyCount();
	//输出结果
	for ( i = 0; i < jiqi; i++)
	{
		strData="";
		sprintf(string, " %d" , i+1);		
		m_tanxinduojilist.InsertItem(i,_T(string)); 
		for ( j = 0; S[i][j]>0; j++)
		{
			strData+="作业 ";
			sprintf(string, " %d" , S[i][j]);
			strData+=string;
			strData+=" ";			
		}
		m_tanxinduojilist.SetItemText(i,1,strData);

		sprintf(string, " %d" , d[i]);
		m_tanxinduojilist.SetItemText(i,2,_T(string));
	}
	
	CString strData2;
	strData2+="运行时间为:";
	sprintf(string, " %d纳秒。" , finish-start);
	strData2+=string;
	m_tanxinduojitime.SetWindowText(strData2);
}

BOOL CTanXinDuoji::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_tanxinduojilist.GetExtendedStyle();  
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	m_tanxinduojilist.SetExtendedStyle(dwStyle);

	m_tanxinduojilist.InsertColumn(0,"机器",LVCFMT_LEFT,250);
	m_tanxinduojilist.InsertColumn(1,"作业",LVCFMT_LEFT,380);
	m_tanxinduojilist.InsertColumn(2,"时间",LVCFMT_CENTER,250);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
