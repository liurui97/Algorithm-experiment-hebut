; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTanXinTSP
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SUANFASETS.h"

ClassCount=14
Class1=CSUANFASETSApp
Class2=CSUANFASETSDlg
Class3=CAboutDlg

ResourceCount=14
Resource1=IDD_DIALOG_TanXinTSP
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG_TanXinDuoJi
Class4=CCycleRace
Class5=CClosestPair
Resource5=IDD_DIALOG_ClosestPair
Class6=CDongTaiTSP
Resource6=IDD_DIALOG_HuiSuTSP
Class7=CDongTai01
Resource7=IDD_DIALOG_DongTaiTSP
Class8=CTanXinTSP
Resource8=IDD_DIALOG_TanXinBeibao
Class9=CTanXinDuoji
Resource9=IDD_DIALOG_FenZhiTSP
Class10=CHuiSuTSP
Resource10=IDD_SUANFASETS_DIALOG
Class11=CTanXinBeibao
Resource11=IDD_DIALOG_DongTai01
Class12=CHuiSu01
Resource12=IDD_DIALOG_CycleRace
Class13=CFenZhiTSP
Resource13=IDD_DIALOG_HuiSu01
Class14=CFenZhi01Bag
Resource14=IDD_DIALOG_FenZhi01

[CLS:CSUANFASETSApp]
Type=0
HeaderFile=SUANFASETS.h
ImplementationFile=SUANFASETS.cpp
Filter=N
LastObject=CSUANFASETSApp

[CLS:CSUANFASETSDlg]
Type=0
HeaderFile=SUANFASETSDlg.h
ImplementationFile=SUANFASETSDlg.cpp
Filter=D
LastObject=IDC_TAB1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SUANFASETSDlg.h
ImplementationFile=SUANFASETSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUANFASETS_DIALOG]
Type=1
Class=CSUANFASETSDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_DIALOG_ClosestPair]
Type=1
Class=CClosestPair
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_Calculate,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_BUTTON_NCalculate,button,1342242816
Control5=IDC_EDIT2,edit,1350631552

[DLG:IDD_DIALOG_CycleRace]
Type=1
Class=CCycleRace
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile,button,1342242816
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT_FileContent,edit,1352732804
Control5=IDC_EDIT_Result,edit,1352732804
Control6=IDC_BUTTON_Calculate1,button,1342242816

[CLS:CCycleRace]
Type=0
HeaderFile=CycleRace.h
ImplementationFile=CycleRace.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCycleRace

[CLS:CClosestPair]
Type=0
HeaderFile=ClosestPair.h
ImplementationFile=ClosestPair.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT2

[DLG:IDD_DIALOG_DongTaiTSP]
Type=1
Class=CDongTaiTSP
ControlCount=6
Control1=IDC_BUTTON_OpeFile,button,1342242816
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_LIST_DongTaiTSP,SysListView32,1350631425
Control6=IDC_EDIT3,edit,1350631552

[CLS:CDongTaiTSP]
Type=0
HeaderFile=DongTaiTSP.h
ImplementationFile=DongTaiTSP.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_DongTaiTSP
VirtualFilter=dWC

[DLG:IDD_DIALOG_DongTai01]
Type=1
Class=CDongTai01
ControlCount=9
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile1,button,1342242816
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_BUTTON_OpenFile2,button,1342242816
Control5=IDC_EDIT3,edit,1352732804
Control6=IDC_EDIT4,edit,1352732804
Control7=IDC_LIST_DongTai01,SysListView32,1350631425
Control8=IDC_BUTTON_Calculate,button,1342242816
Control9=IDC_EDIT5,edit,1350631552

[CLS:CDongTai01]
Type=0
HeaderFile=DongTai01.h
ImplementationFile=DongTai01.cpp
BaseClass=CDialog
Filter=D
LastObject=CDongTai01
VirtualFilter=dWC

[DLG:IDD_DIALOG_TanXinTSP]
Type=1
Class=CTanXinTSP
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile,button,1342242816
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_LIST1,SysListView32,1350631425
Control6=IDC_EDIT3,edit,1350631552

[CLS:CTanXinTSP]
Type=0
HeaderFile=TanXinTSP.h
ImplementationFile=TanXinTSP.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTanXinTSP

[DLG:IDD_DIALOG_TanXinDuoJi]
Type=1
Class=CTanXinDuoji
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON_OpenFile,button,1342242816
Control6=IDC_EDIT5,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BUTTON_Calculate,button,1342242816
Control9=IDC_EDIT8,edit,1352732804
Control10=IDC_LIST1,SysListView32,1350631425
Control11=IDC_EDIT3,edit,1350631552

[CLS:CTanXinDuoji]
Type=0
HeaderFile=TanXinDuoji.h
ImplementationFile=TanXinDuoji.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[DLG:IDD_DIALOG_HuiSuTSP]
Type=1
Class=CHuiSuTSP
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile,button,1342242816
Control3=IDC_BUTTON_Calulate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_EDIT3,edit,1352732804

[CLS:CHuiSuTSP]
Type=0
HeaderFile=HuiSuTSP.h
ImplementationFile=HuiSuTSP.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CTanXinBeibao]
Type=0
HeaderFile=TanXinBeibao.h
ImplementationFile=TanXinBeibao.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_DIALOG_TanXinBeibao]
Type=1
Class=CTanXinBeibao
ControlCount=8
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile,button,1342242816
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_EDIT3,edit,1352732804
Control6=IDC_EDIT4,edit,1350631552
Control7=IDC_BUTTONOpenFile2,button,1342242816
Control8=IDC_EDIT5,edit,1352732804

[DLG:IDD_DIALOG_HuiSu01]
Type=1
Class=CHuiSu01
ControlCount=8
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile1,button,1342242816
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_EDIT3,edit,1352732804
Control6=IDC_EDIT4,edit,1350631552
Control7=IDC_BUTTON_OpenFile2,button,1342242816
Control8=IDC_EDIT5,edit,1352732804

[CLS:CHuiSu01]
Type=0
HeaderFile=HuiSu01.h
ImplementationFile=HuiSu01.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG_FenZhiTSP]
Type=1
Class=CFenZhiTSP
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile,button,1342242816
Control3=IDC_BUTTON_Calculate,button,1342242816
Control4=IDC_EDIT2,edit,1352732804
Control5=IDC_EDIT3,edit,1352732804

[CLS:CFenZhiTSP]
Type=0
HeaderFile=FenZhiTSP.h
ImplementationFile=FenZhiTSP.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG_FenZhi01]
Type=1
Class=CFenZhi01Bag
ControlCount=8
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON_OpenFile1,button,1342242816
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_BUTTON_OpenFile2,button,1342242816
Control5=IDC_BUTTON_Calculate,button,1342242816
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_EDIT4,edit,1350631552
Control8=IDC_EDIT5,edit,1352732804

[CLS:CFenZhi01Bag]
Type=0
HeaderFile=FenZhi01Bag.h
ImplementationFile=FenZhi01Bag.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

