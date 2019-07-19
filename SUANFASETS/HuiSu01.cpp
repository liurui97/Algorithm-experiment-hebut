// HuiSu01.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "HuiSu01.h"
#include <locale.h>
#include "huisufa_01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CHuiSu01 dialog


CHuiSu01::CHuiSu01(CWnd* pParent /*=NULL*/)
	: CDialog(CHuiSu01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHuiSu01)
	//}}AFX_DATA_INIT
}


void CHuiSu01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHuiSu01)
	DDX_Control(pDX, IDC_EDIT5, m_huisu01filecontent2);
	DDX_Control(pDX, IDC_EDIT2, m_huisu01filecontent1);
	DDX_Control(pDX, IDC_EDIT4, m_huisu01file2);
	DDX_Control(pDX, IDC_EDIT1, m_huisu01file1);
	DDX_Control(pDX, IDC_EDIT3, m_huisu01result);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHuiSu01, CDialog)
	//{{AFX_MSG_MAP(CHuiSu01)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile1, OnBUTTONOpenFile1)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile2, OnBUTTONOpenFile2)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuiSu01 message handlers

void CHuiSu01::OnBUTTONOpenFile1() 
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
		m_huisu01file1.SetWindowText(filepathname1);
		
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
			m_huisu01filecontent1.SetWindowText(str);
			return;
		}
	}
}

void CHuiSu01::OnBUTTONOpenFile2() 
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
		m_huisu01file2.SetWindowText(filepathname2);
		
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
			m_huisu01filecontent2.SetWindowText(str);
			return;
		}
	}
}

void CHuiSu01::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	int i;
	wupinn=5;
	c=10;
	FILE *fp;
	char *ch = filepathname1.GetBuffer(filepathname1.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 1; i<=5; i++)
		{
			fscanf(fp,"%d",&weight[i]);
		}
		fclose(fp);
	}
	ch = filepathname2.GetBuffer(filepathname2.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 1; i<=5; i++)
		{
			fscanf(fp,"%d",&value[i]);
		}
		fclose(fp);
	}
	start = (unsigned long)GetCyCount();
	Backtracking(1);
	finish = (unsigned long)GetCyCount();
	char string[10];
	CString strData;
	strData+="最优的装入方式为:";
	for ( i = 1; i < wupinn; i++)
	{
		sprintf(string, " %d," , bA[i]);
		strData+=string;
	}
	sprintf(string, " %d," , bA[i]);
	strData+=string;
	strData+="最大价值为:";
	sprintf(string, " %d\r\n" ,  bp);
	strData+=string;
	
	strData+="运行时间为:";
	sprintf(string, " %d秒。" , finish-start);
	strData+=string;
	m_huisu01result.SetWindowText(strData);
}
