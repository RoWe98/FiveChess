// SetupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FiveChess.h"
#include "MainFrm.h"
#include "setupdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetupDlg dialog
extern BOOL bChineseMenu;

CSetupDlg::CSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(bChineseMenu ? IDD_SETUPDLG_CHINESE : IDD_SETUPDLG_ENGLISH, pParent)
{
	//{{AFX_DATA_INIT(CSetupDlg)
	bCheckSound = true;
	nYouFirst = 0;
	nWithComputer = 0;
	//}}AFX_DATA_INIT
}


void CSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetupDlg)
	DDX_Check(pDX, IDC_CHECK_SOUND, bCheckSound);
	DDX_Radio(pDX, IDC_RADIO_YOU_FIRST, nYouFirst);
	DDX_Radio(pDX, IDC_RADIO_WITHCOMPUTER, nWithComputer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetupDlg, CDialog)
	//{{AFX_MSG_MAP(CSetupDlg)
	ON_BN_CLICKED(IDC_RADIO_2PLAYER, OnRadio2player)
	ON_BN_CLICKED(IDC_RADIO_WITHCOMPUTER, OnRadioWithcomputer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetupDlg message handlers




BOOL CSetupDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetupDlg::OnRadio2player() 
{
	// TODO: Add your control notification handler code here
	if(bChineseMenu)
	{
		SetDlgItemText(IDC_RADIO_YOU_FIRST,"玩家1");
		SetDlgItemText(IDC_RADIO_COMPUTER_FIRST,"玩家2");
	}
	else
	{
		SetDlgItemText(IDC_RADIO_YOU_FIRST,"Player1");
		SetDlgItemText(IDC_RADIO_COMPUTER_FIRST,"Player2");
	}
	Invalidate();
}

void CSetupDlg::OnRadioWithcomputer() 
{
	// TODO: Add your control notification handler code here
	if(bChineseMenu)
	{
		SetDlgItemText(IDC_RADIO_YOU_FIRST,"你执黑先下");
		SetDlgItemText(IDC_RADIO_COMPUTER_FIRST,"计算机执黑先下");
	}
	else
	{
		SetDlgItemText(IDC_RADIO_YOU_FIRST,"You");
		SetDlgItemText(IDC_RADIO_COMPUTER_FIRST,"Computer");
	}
	Invalidate();
}
