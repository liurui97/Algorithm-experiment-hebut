// FenZhi01Bag.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "FenZhi01Bag.h"
#include <locale.h>
#include "fenzhixianjiefa_01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}

/////////////////////////////////////////////////////////////////////////////
// CFenZhi01Bag dialog


CFenZhi01Bag::CFenZhi01Bag(CWnd* pParent /*=NULL*/)
	: CDialog(CFenZhi01Bag::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenZhi01Bag)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFenZhi01Bag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenZhi01Bag)
	DDX_Control(pDX, IDC_EDIT5, m_fenzhi01result);
	DDX_Control(pDX, IDC_EDIT4, m_fenzhi01filecontent2);
	DDX_Control(pDX, IDC_EDIT3, m_fenzhi01filecontent1);
	DDX_Control(pDX, IDC_EDIT2, m_fenzhi01file2);
	DDX_Control(pDX, IDC_EDIT1, m_fenzhi01file1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenZhi01Bag, CDialog)
	//{{AFX_MSG_MAP(CFenZhi01Bag)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile1, OnBUTTONOpenFile1)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile2, OnBUTTONOpenFile2)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenZhi01Bag message handlers

void CFenZhi01Bag::OnBUTTONOpenFile1() 
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
		m_fenzhi01file1.SetWindowText(filepathname1);
		
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
			m_fenzhi01filecontent1.SetWindowText(str);
			return;
		}
	}
}

void CFenZhi01Bag::OnBUTTONOpenFile2() 
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
		m_fenzhi01file2.SetWindowText(filepathname2);
		
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
			m_fenzhi01filecontent2.SetWindowText(str);
			return;
		}
	}	
}

void CFenZhi01Bag::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	fenzhi01n=5;
	fenzhi01c=10;
	FILE *fp;
	char *ch = filepathname1.GetBuffer(filepathname1.GetLength() + 1);
	int i,w[5],v[5],maxValue;
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<fenzhi01n; i++)
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
		for (i = 0; i<fenzhi01n; i++)
		{
			fscanf(fp,"%d",&v[i]);
		}
		fclose(fp);
	}
	//定义物品结构体
	Item *items = new Item[fenzhi01n];
	//初始化结构体数组
	for (i = 0; i < fenzhi01n; i++)
	{
		items[i].ItemID = i;
		items[i].value = v[i];
		items[i].weight = w[i];
		items[i].ratio = 1.0*v[i] / w[i];
	}
	start = (unsigned long)GetCyCount();
	//按价值率排序
	sort(items, items + fenzhi01n, Itemcmp);
	maxValue = branchAndBound(items, fenzhi01c);
	finish = (unsigned long)GetCyCount();
	char string[10];
	CString strData;
	strData+="选取方案为:";
	for (i = 0; i < fenzhi01n; i++)
	{
		sprintf(string, " %d," , fenzhi01x[i]);
		//cout << x[i] << "  ";
		strData+=string;
	}
	strData+="最大价值为:";
	sprintf(string, " %d。\r\n" , maxValue);
	strData+=string;
	strData+="运行时间为:";
	sprintf(string, " %d纳秒。" , finish-start);
	strData+=string;
	m_fenzhi01result.SetWindowText(strData);
}
