; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFiveChessView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "fivechess.h"
LastPage=0

ClassCount=6
Class1=CFiveChessApp
Class2=CAboutDlg
Class3=CFiveChessDoc
Class4=CFiveChessView
Class5=CMainFrame
Class6=CSetupDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MENU_CHINESE
Resource3=IDR_MAINFRAME
Resource4=IDD_SETUPDLG_ENGLISH
Resource5=IDR_MENU_ENGLISH
Resource6=IDD_SETUPDLG_CHINESE

[CLS:CFiveChessApp]
Type=0
BaseClass=CWinApp
HeaderFile=FiveChess.h
ImplementationFile=FiveChess.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=FiveChess.cpp
ImplementationFile=FiveChess.cpp

[CLS:CFiveChessDoc]
Type=0
BaseClass=CDocument
HeaderFile=FiveChessDoc.h
ImplementationFile=FiveChessDoc.cpp

[CLS:CFiveChessView]
Type=0
BaseClass=CView
HeaderFile=FiveChessView.h
ImplementationFile=FiveChessView.cpp
LastObject=CFiveChessView
Filter=C
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CSetupDlg]
Type=0
BaseClass=CDialog
HeaderFile=SetupDlg.h
ImplementationFile=SetupDlg.cpp
LastObject=CSetupDlg
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SETUPDLG_CHINESE]
Type=1
Class=CSetupDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342308359
Control4=IDC_RADIO_WITHCOMPUTER,button,1342373897
Control5=IDC_RADIO_2PLAYER,button,1342242825
Control6=IDC_STATIC,button,1342308359
Control7=IDC_RADIO_YOU_FIRST,button,1342373897
Control8=IDC_RADIO_COMPUTER_FIRST,button,1342242825
Control9=IDC_CHECK_SOUND,button,1342242819

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_APP_ABOUT
CommandCount=14

[MNU:IDR_MENU_CHINESE]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=IDM_GRADE1
Command3=IDM_GRADE2
Command4=IDM_SET
Command5=ID_FILE_CLOSE
Command6=IDM_UNDO
Command7=IDM_SOUND
Command8=IDM_LANGUAGE
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MENU_ENGLISH]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=IDM_GRADE1
Command3=IDM_GRADE2
Command4=IDM_SET
Command5=IDM_EXIT
Command6=IDM_UNDO
Command7=IDM_SOUND
Command8=IDM_LANGUAGE
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_SETUPDLG_ENGLISH]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342308359
Control4=IDC_RADIO_WITHCOMPUTER,button,1342373897
Control5=IDC_RADIO_2PLAYER,button,1342242825
Control6=IDC_STATIC,button,1342308359
Control7=IDC_RADIO_YOU_FIRST,button,1342373897
Control8=IDC_RADIO_COMPUTER_FIRST,button,1342242825
Control9=IDC_CHECK_SOUND,button,1342242819

