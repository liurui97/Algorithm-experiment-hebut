// TanXinTSP.cpp : implementation file
//

#include "stdafx.h"
#include "SUANFASETS.h"
#include "TanXinTSP.h"
#include <locale.h>
#include "tanxinfa_tsp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

inline unsigned GetCyCount(){
	__asm _emit 0x0f __asm _emit 0x31
}

/////////////////////////////////////////////////////////////////////////////
// CTanXinTSP dialog


CTanXinTSP::CTanXinTSP(CWnd* pParent /*=NULL*/)
	: CDialog(CTanXinTSP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTanXinTSP)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTanXinTSP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTanXinTSP)
	DDX_Control(pDX, IDC_EDIT3, m_tanxintsptime);
	DDX_Control(pDX, IDC_LIST1, m_tanxintsplist);
	DDX_Control(pDX, IDC_EDIT2, m_tanxintspfilecontent);
	DDX_Control(pDX, IDC_EDIT1, m_tanxintspfile);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTanXinTSP, CDialog)
	//{{AFX_MSG_MAP(CTanXinTSP)
	ON_BN_CLICKED(IDC_BUTTON_OpenFile, OnBUTTONOpenFile)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, OnBUTTONCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTanXinTSP message handlers

void CTanXinTSP::OnBUTTONOpenFile() 
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
		m_tanxintspfile.SetWindowText(filepathname);
		
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
			m_tanxintspfilecontent.SetWindowText(str);
			return;
		}
	}
}

void CTanXinTSP::OnBUTTONCalculate() 
{
	// TODO: Add your control notification handler code here
	unsigned long start, finish;
	int number=0;
	int nowlength;
	int i,j,u,v,w;
	citys=5;
	char string[2];
	FILE *fp;
	char *ch = filepathname.GetBuffer(filepathname.GetLength() + 1);
	if((fp=fopen(ch,"r"))==NULL)
	{
	
	}
	else
	{
		for (i = 0; i<citys; i++)
		{
			for (j = 0; j<citys; j++)
			{
				//cin >> distance[i][j];
				fscanf(fp,"%d",&value[i][j]);
			}
		}
		Modify(value);
		fclose(fp);
	}
	start = (unsigned long)GetCyCount();
	for (i = 0; i < citys; i++){
		V[i] = i + 1;
	}

	//进行初始化
	//P为空
	TSPLength = 0;
	w = 0;
	u = 0;
	//从V中删除w
	nowlength = citys;
	for (i = 0; i < nowlength; i++)
	{
		V[i] = V[i + 1];
	}

	nowlength--;
	V[i] = 0;
	int min = 999;

	do{
		//查找与顶点邻接的最小边，并且v属于集合V
		for (i = 0; i < citys; i++)
		{
			if (FindBySeq(V, nowlength, i + 1) != -1){
				if (value[u][i]<min)
				{
					min = value[u][i];
					v = i;
				}
			}
		}
		P[number].x = u;
		P[number].y = v;
		TSPLength += value[u][v];
		//再删除一个
		i = FindBySeq(V, nowlength, v + 1);
		for (; i < nowlength; i++)
		{
			V[i] = V[i + 1];
		}
		nowlength--;
		//输出路径
		//printf("第%d次从%d到%d\n", ++number, u + 1, v + 1);
		sprintf(string, " %d" , ++number);		
		m_tanxintsplist.InsertItem(number-1,_T(string)); 
		sprintf(string, " %d" , u+1);
		m_tanxintsplist.SetItemText(number-1,1,_T(string));
		sprintf(string, " %d" , v+1);
		m_tanxintsplist.SetItemText(number-1,2,_T(string));
		u = v;
		min = 999;
	} while (number < citys - 1);
	finish = (unsigned long)GetCyCount();

	TSPLength += value[u][0];
	sprintf(string, " %d" , ++number);
	m_tanxintsplist.InsertItem(number-1,_T(string)); 
	sprintf(string, " %d" , u+1);
	m_tanxintsplist.SetItemText(number-1,1,_T(string));
	sprintf(string, " %d" , 1);
	m_tanxintsplist.SetItemText(number-1,2,_T(string));
	//printf("第%d次从%d到%d\n", ++number, u + 1, 1);

	
	CString strData2;
	strData2+="最短长度为:";
	sprintf(string, " %d," , TSPLength);
	strData2+=string;
	strData2+="运行时间为:";
	sprintf(string, " %d毫秒。" , finish-start);
	strData2+=string;
	m_tanxintsptime.SetWindowText(strData2);
}

BOOL CTanXinTSP::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle=m_tanxintsplist.GetExtendedStyle();  
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	m_tanxintsplist.SetExtendedStyle(dwStyle);

	m_tanxintsplist.InsertColumn(0,"路径",LVCFMT_CENTER,300);
	m_tanxintsplist.InsertColumn(1,"出发点",LVCFMT_CENTER,300);
	m_tanxintsplist.InsertColumn(2,"目的地",LVCFMT_CENTER,300);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
