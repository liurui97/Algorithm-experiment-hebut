// TanXinBeibao.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "TanXinBeibao.h"
#include <locale.h>
#include "tanxinfa_beibao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CTanXinBeibao dialog


CTanXinBeibao::CTanXinBeibao(CWnd* pParent /*=NULL*/)
	: CDialog(CTanXinBeibao::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTanXinBeibao)
	//}}AFX_DATA_INIT
}


void CTanXinBeibao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTanXinBeibao)
	DDX_Control(pDX, IDC_EDIT2, m_tanxinbeibaofilecontent1);
	DDX_Control(pDX, IDC_EDIT5, m_tanxinbeibaofilecontent2);
	DDX_Control(pDX, IDC_EDIT1, m_tanxinbeibaofile1);
	DDX_Control(pDX, IDC_EDIT4, m_tanxinbeibaofile2);
	DDX_Control(pDX, IDC_EDIT3, m_tanxinbeibaoresult);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTanXinBeibao, CDialog)
	//{{AFX_MSG_MAP(CTanXinBeibao)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile, OnBUTTONOpenFile)
	ON_BN_CLICKED(IDC_BUTTONOpenFile2, OnBUTTONOpenFile2)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTanXinBeibao message handlers

void CTanXinBeibao::OnBUTTONOpenFile() 
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
		m_tanxinbeibaofile1.SetWindowText(filepathname1);
		
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
			m_tanxinbeibaofilecontent1.SetWindowText(str);
			return;
		}
	}
}

void CTanXinBeibao::OnBUTTONOpenFile2() 
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
		m_tanxinbeibaofile2.SetWindowText(filepathname2);
		
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
			m_tanxinbeibaofilecontent2.SetWindowText(str);
			return;
		}
	}
}

void CTanXinBeibao::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	//读文件
	unsigned long start, finish;
	tanxinn = 3;
	tanxinc = 50;
	int i;
	int *w = new int[tanxinn];
	int *v = new int[tanxinn];
	FILE *fp;
	char *ch = filepathname1.GetBuffer(filepathname1.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<tanxinn; i++)
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
		for (i = 0; i<tanxinn; i++)
		{
			fscanf(fp,"%d",&v[i]);
		}
		fclose(fp);
	}
	//定义物品结构体
	tanxinbeibao *items = new tanxinbeibao[tanxinn];
	//初始化结构体数组
	for (i = 0; i < tanxinn; i++)
	{
		items[i].id = i;
		items[i].value = v[i];
		items[i].weight = w[i];
		items[i].ratio = 1.0*v[i] / w[i];
	}
	start = (unsigned long)GetCyCount();
	//排序
	sort(items, items + tanxinn, Bagcmp);
	
	CString strData;
	double a=KnapSack(items, tanxinn, tanxinc,strData);
	finish = (unsigned long)GetCyCount();
	char string[20];
	strData+="最大价值:";
	sprintf(string, " %3.1f\r\n" , a);
	strData+=string;
	
	strData+="运行时间为:";
	sprintf(string, " %d纳秒。" , finish-start);
	strData+=string;
	m_tanxinbeibaoresult.SetWindowText(strData);
}
