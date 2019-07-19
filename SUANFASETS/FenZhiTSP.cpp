// FenZhiTSP.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "FenZhiTSP.h"
#include <locale.h>
#include "fenzhixianjiefa_tsp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CFenZhiTSP dialog


CFenZhiTSP::CFenZhiTSP(CWnd* pParent /*=NULL*/)
	: CDialog(CFenZhiTSP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenZhiTSP)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFenZhiTSP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenZhiTSP)
	DDX_Control(pDX, IDC_EDIT3, m_fenzhitspresult);
	DDX_Control(pDX, IDC_EDIT2, m_fenzhitspfilecontent);
	DDX_Control(pDX, IDC_EDIT1, m_fenzhitspfile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenZhiTSP, CDialog)
	//{{AFX_MSG_MAP(CFenZhiTSP)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile, OnBUTTONOpenFile)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenZhiTSP message handlers

void CFenZhiTSP::OnBUTTONOpenFile() 
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
		m_fenzhitspfile.SetWindowText(filepathname);
		
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
			m_fenzhitspfilecontent.SetWindowText(str);
			return;
		}
	}
}

void CFenZhiTSP::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	fenzhitspn=5;
	int i,j;
	FILE *fp;
	char *ch = filepathname.GetBuffer(filepathname.GetLength() + 1);
	
	if((fp=fopen(ch,"r"))==NULL){
		MessageBox("文件打开失败!");
	}
	else{
		//MessageBox("文件打开成功!");
		for(i=1;i<=fenzhitspn;i++)
		{
			for(j=1;j<=fenzhitspn;j++)
			{
				fscanf(fp,"%d",&fenzhitspvalue[i][j]);
			}
		}
		
		Modify2();
	}
	fclose(fp); 
	CString strData;
	char string[20];
	strData+="最短路径为:";
	start = (unsigned long)GetCyCount();
	i=solve(strData);
	finish = (unsigned long)GetCyCount();
	strData+="最短路径长度为:";
	sprintf(string, " %d\r\n" , i);
	strData+= string;
	
	strData+="运行时间为:";
	sprintf(string, " %d纳秒。" , finish-start);
	strData+=string;
	m_fenzhitspresult.SetWindowText(strData);
}
