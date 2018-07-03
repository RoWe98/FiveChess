// FiveChess.h : main header file for the FIVECHESS application
//

#if !defined(AFX_FIVECHESS_H__43EE63CD_D88E_4249_B3D1_338AC5E7AD8B__INCLUDED_)
#define AFX_FIVECHESS_H__43EE63CD_D88E_4249_B3D1_338AC5E7AD8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiveChessApp:
// See FiveChess.cpp for the implementation of this class
//

class CFiveChessApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CFiveChessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveChessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFiveChessApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVECHESS_H__43EE63CD_D88E_4249_B3D1_338AC5E7AD8B__INCLUDED_)
