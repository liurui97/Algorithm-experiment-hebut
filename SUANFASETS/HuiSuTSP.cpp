// HuiSuTSP.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "HuiSuTSP.h"
#include <locale.h>
#include "huisufa_tsp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}
/////////////////////////////////////////////////////////////////////////////
// CHuiSuTSP dialog


CHuiSuTSP::CHuiSuTSP(CWnd* pParent /*=NULL*/)
: CDialog(CHuiSuTSP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHuiSuTSP)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHuiSuTSP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHuiSuTSP)
	DDX_Control(pDX, IDC_EDIT3, m_huisutspresult);
	DDX_Control(pDX, IDC_EDIT2, m_huisutspfilecontent);
	DDX_Control(pDX, IDC_EDIT1, m_huisutspfile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHuiSuTSP, CDialog)
//{{AFX_MSG_MAP(CHuiSuTSP)
ON_BN_CLICKED(IDC_BUTTON_OpenFile, OnBUTTONOpenFile)
ON_BN_CLICKED(IDC_BUTTON_Calulate, OnBUTTONCalulate)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuiSuTSP message handlers

void CHuiSuTSP::OnBUTTONOpenFile() 
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
		m_huisutspfile.SetWindowText(filepathname);
		
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
			m_huisutspfilecontent.SetWindowText(str);
			return;
		}
	}
}

void CHuiSuTSP::OnBUTTONCalulate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	n=5;
	int i,j;
	FILE *fp;
	char *ch = filepathname.GetBuffer(filepathname.GetLength() + 1);
	
	if((fp=fopen(ch,"r"))==NULL){
		MessageBox("文件打开失败!");
	}
	else{
		//MessageBox("文件打开成功!");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				fscanf(fp,"%d",&value[i][j]);
			}
		}
		
		Modify();
	}
	fclose(fp); 

	for ( i = 1; i <= n; i++)
	{
		citys[i] = i;
		bestx[i] = 0;
	}
	start = (unsigned long)GetCyCount();
	Tsp(2);
	finish = (unsigned long)GetCyCount();

	CString strData;
	char string[20];
	strData+="最优路线为:";
	for ( i = 1; i <= n; i++)
	{
		sprintf(string, " %d," , bestx[i]);
		strData+= string;
	}
	strData+="最短长度为:";
	sprintf(string, " %d\r\n" , bestl);
	strData+= string;

	strData+="运行时间为:";
	sprintf(string, " %d纳秒。" , finish-start);
	strData+=string;
	m_huisutspresult.SetWindowText(strData);
}
