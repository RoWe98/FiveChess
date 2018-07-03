// FiveChessView.h : interface of the CFiveChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIVECHESSVIEW_H__4E9B284A_3F9D_4E62_890B_81B67DE91375__INCLUDED_)
#define AFX_FIVECHESSVIEW_H__4E9B284A_3F9D_4E62_890B_81B67DE91375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFiveChessView : public CView
{
protected: // create from serialization only
	CFiveChessView();
	DECLARE_DYNCREATE(CFiveChessView)

// Attributes
public:
	CFiveChessDoc* GetDocument();
	BOOL	bCheckSound;
	int		nYouFirst;
	int		nWithComputer;
	BOOL player1,player2,over;
	int xGrid,yGrid;

	int i,j,k,m,n,count;	
    int board[15][15];
	BOOL p1table[15][15][572],p2table[15][15][572];
	int cgrades[15][15],pgrades[15][15],cgrade,pgrade;
	int win[2][572];
	int p1count,p2count;
	BOOL p1win,p2win,tie;
	int mat,nat,mde,nde;
	char str[15];

	//悔棋时使用的成员变量
	BOOL bUndo;
	int m_xCur1,m_yCur1,m_xCur2,m_yCur2;
	int m_p1table[572],m_p2table[572];
	int m_win1[572],m_win2[572];


// Operations
public:
	void DisplayBoard(CDC* pDC,UINT IDSoundRes);
	void InitParams();
	void PlayMySound(UINT IDSoundRes);
	CPoint PointToStonePos(CPoint point);
	CPoint PointToStonePos(int m,int n);
	void DisplayStone(CDC* pDC,UINT IDResource,CPoint point);
	void ComputerTurn();
	void Judge();
	void TwoPlayerGame(CDC *pDC, CPoint point);

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFiveChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFiveChessView)
	afx_msg void OnSet();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUndo();
	afx_msg void OnUpdateUndo(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FiveChessView.cpp
inline CFiveChessDoc* CFiveChessView::GetDocument()
   { return (CFiveChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVECHESSVIEW_H__4E9B284A_3F9D_4E62_890B_81B67DE91375__INCLUDED_)
