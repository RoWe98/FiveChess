// FiveChessView.cpp : implementation of the CFiveChessView class
//

#include "stdafx.h"
#include "FiveChess.h"

#include "FiveChessDoc.h"
#include "FiveChessView.h"
#include "SetupDlg.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView

IMPLEMENT_DYNCREATE(CFiveChessView, CView)

BEGIN_MESSAGE_MAP(CFiveChessView, CView)
	//{{AFX_MSG_MAP(CFiveChessView)
	ON_COMMAND(IDM_SET, OnSet)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_UNDO, OnUndo)
	ON_UPDATE_COMMAND_UI(IDM_UNDO, OnUpdateUndo)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView construction/destruction

CFiveChessView::CFiveChessView()
{
	// TODO: add construction code here

}

CFiveChessView::~CFiveChessView()
{
}

BOOL CFiveChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	PlayMySound(IDSOUND_WELCOME);

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView drawing

void CFiveChessView::OnDraw(CDC* pDC)
{
	CFiveChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    
    InitParams();
	DisplayBoard(pDC,IDB_BOARD);
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView printing

BOOL CFiveChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFiveChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFiveChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView diagnostics

#ifdef _DEBUG
void CFiveChessView::AssertValid() const
{
	CView::AssertValid();
}

void CFiveChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFiveChessDoc* CFiveChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFiveChessDoc)));
	return (CFiveChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView message handlers
void CFiveChessView::DisplayBoard(CDC* pDC,UINT IDResource)
{
	CBitmap Bitmap;
	Bitmap.LoadBitmap(IDResource);//将位图装入内存
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC); //创建内存设备环境
	CBitmap *OldBitmap=MemDC.SelectObject(&Bitmap);
	BITMAP bm;                    //创建BITMAP结构变量
	Bitmap.GetBitmap(&bm);        //获取位图信息

	CWnd *pMainFrame=AfxGetMainWnd();
	int cxScreen = ::GetSystemMetrics(SM_CXSCREEN);
	int cyScreen = ::GetSystemMetrics(SM_CYSCREEN);
	int cxDlgFrame = ::GetSystemMetrics(SM_CXDLGFRAME);
	int cyDlgFrame = ::GetSystemMetrics(SM_CYDLGFRAME);
	int cxCaption = ::GetSystemMetrics(SM_CYCAPTION); 
	int cyMenu = ::GetSystemMetrics(SM_CYMENU);
	int nWidth  = bm.bmWidth + 2*cxDlgFrame;
	int nHeight = bm.bmHeight + cxCaption + 2*cyDlgFrame + cyMenu;
	pMainFrame->MoveWindow((cxScreen-nWidth)/2, (cyScreen-nHeight)/2,nWidth, nHeight);

	xGrid=(int)(bm.bmWidth/15);
	yGrid=(int)(bm.bmHeight/15);

	pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&MemDC,0,0,SRCCOPY);//输出位图
    pDC->SelectObject(OldBitmap);//恢复设备环境
}

void CFiveChessView::OnSet() 
{
	// TODO: Add your command handler code here
	if(p1count!=0||p2count!=0)
		MessageBox("请先选择[新局]收好棋盘上的棋子！");
	else
	{		
		CDC* pDC=GetDC();
		CPoint point;
		
		CSetupDlg setupDlg;
		if (setupDlg.DoModal()==IDOK)
		{
			UpdateData(true);
			nWithComputer=setupDlg.nWithComputer;
			nYouFirst=setupDlg.nYouFirst;

			bCheckSound=setupDlg.bCheckSound;
		}		
		if(nYouFirst)
		{
			point=PointToStonePos(7,7);//计算机先下时初始位置
			DisplayStone(pDC,IDB_MASK,point);
			DisplayStone(pDC,IDB_BLACK,point);
		}
		player1=true;
	}	
}
void CFiveChessView::InitParams()
{
	bCheckSound=true;
	nYouFirst=0;
	nWithComputer=0;
	player1=true;
	player2=false;
	over=false;
	p1win=false;
	p2win=false;
	tie=false;
	xGrid=0;
	yGrid=0;
	count=0;	
	cgrade=0;
	pgrade=0;
	p1count=0;
	p2count=0;
	mat=0;
	nat=0;
	mde=0;
	nde=0;
	bUndo=false;
	m_xCur1=0;
	m_yCur1=0;
	m_xCur2=0;
	m_yCur2=0;

	for(i=0;i<=1;i++)
		for(j=0;j<572;j++)
			win[i][j]=0;
	for(i=0;i<15;i++)         
		for(j=0;j<15;j++)
		{
			board[i][j] = 2;
			cgrades[i][j]=0;
			pgrades[i][j]=0;
		}
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
			for(k=0;k<572;k++)
			{
				p1table[i][j][k] = false;
				p2table[i][j][k] = false;
			}
	for(i=0;i<15;i++)        
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[j+k][i][count] = true;
				p2table[j+k][i][count] = true;
			}
			count++;
		}
	for(i=0;i<15;i++)       
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[i][j+k][count] = true;
				p2table[i][j+k][count] = true;
			}
			count++;
		}
	for(i=0;i<11;i++)        
		for(j=0;j<11;j++)
		{
			for(k=0;k<5;k++)
			{
				p1table[j+k][i+k][count] = true;
				p2table[j+k][i+k][count] = true;
			}
			count++;
		}
	for(i=0;i<11;i++)          
		for(j=14;j>=4;j--)
		{
			for(k=0;k<5;k++)
			{
				p1table[j-k][i+k][count] = true;
				p2table[j-k][i+k][count] = true;
			}
			count++;
		}
	count = 0;
}
BOOL CFiveChessView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if (!over && !nWithComputer)
	{
		SetCursor(AfxGetApp()->LoadCursor(nYouFirst ? IDC_WHITE_HAND:IDC_BLACK_HAND));
	    return true;
	}
	else if(!over && nWithComputer)
	{ 
		SetCursor(AfxGetApp()->LoadCursor(player1 ? IDC_BLACK_HAND:IDC_WHITE_HAND));
	    return true;
	}
   	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CFiveChessView::PlayMySound(UINT IDSoundRes)
{
         
	if (bCheckSound)
		PlaySound(MAKEINTRESOURCE(IDSoundRes),
			NULL,
			SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
}

CPoint CFiveChessView::PointToStonePos(CPoint point)
{
	int xpt=(int)(point.x/xGrid);
	int ypt=(int)(point.y/yGrid);
	CPoint pt(xpt,ypt);
	return pt;
}
CPoint CFiveChessView::PointToStonePos(int m,int n)
{
	int xpt=m*xGrid+1;
	int ypt=n*yGrid+2;
	CPoint pt(xpt,ypt);
	return pt;
}
void CFiveChessView::DisplayStone(CDC* pDC,UINT IDResource,CPoint point)
{
	CBitmap Bitmap;
	Bitmap.LoadBitmap(IDResource);//将位图装入内存
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC); //创建内存设备环境
	CBitmap *OldBitmap=MemDC.SelectObject(&Bitmap);
	BITMAP bm;                    //创建BITMAP结构变量
	Bitmap.GetBitmap(&bm);        //获取位图信息
	if(IDResource==IDB_MASK)
		pDC->BitBlt(point.x,point.y,bm.bmWidth,bm.bmHeight, &MemDC,0,0,SRCAND);//输出位图
	else
		pDC->BitBlt(point.x,point.y,bm.bmWidth,bm.bmHeight,&MemDC,0,0,SRCPAINT);//输出位图
	pDC->SelectObject(OldBitmap);//恢复设备环境
	MemDC.DeleteDC();
}

void CFiveChessView::ComputerTurn()
{
   //计算玩家分数
	for(i=0;i<=14;i++)      
		for(j=0;j<=14;j++)
		{
			pgrades[i][j]=0;
			if(board[i][j] == 2)// "board[i][j] == 2"表示位置为空
				for(k=0;k<572;k++)
					if(p1table[i][j][k])
					{
						switch(win[0][k])
						{
						case 1:
							pgrades[i][j]+=5;
							break;
						case 2:
							pgrades[i][j]+=50;
							break;
						case 3:
							pgrades[i][j]+=100;
							break;
						case 4:
							pgrades[i][j]+=400;
							break;
						}
					}
		}
       //计算计算机分数
		for(i=0;i<=14;i++)    
			for(j=0;j<=14;j++)
			{
				cgrades[i][j]=0;
				if(board[i][j] == 2)
					for(k=0;k<572;k++)
						if(p2table[i][j][k])
						{
							switch(win[1][k])
							{
							case 1:
								cgrades[i][j]+=5;
								break;
							case 2:
								cgrades[i][j]+=50;
								break;
							case 3:
								cgrades[i][j]+=100;
								break;
							case 4:
								cgrades[i][j]+=400;
								break;
							}
						}
			}
       //确定计算机落子位置(攻击或防守)
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)
				if(board[i][j] == 2)
				{
					if(cgrades[i][j]>=cgrade)
					{
						cgrade = cgrades[i][j];   
						mat = i;
						nat = j;
					}
					if(pgrades[i][j]>=pgrade)
					{
						pgrade = pgrades[i][j];   
						mde = i;
						nde = j;
					}
				}
		if(cgrade>=pgrade)  
		{
			m = mat;
			n = nat;
		}
		else               
		{
			m = mde;
			n = nde;
		}					
		cgrade = 0;		
		pgrade = 0;

		m_xCur2=m;//记录落子位置，以备悔棋时使用
		m_yCur2=n;

		board[m][n] = 1; //确定(m,n)为落子位置
		p2count++;
       //本实例设定各下80手为平局
		if((p2count == 80) && (p1count == 80))
		{
			tie = true;
			over = true;
		}
       //更新获胜组合数组状态，"win[][] == 7"表示这种组合已不可能获胜
		for(i=0;i<572;i++)
		{			
			if(p2table[m][n][i] && win[1][i] != 7)
			{
				
				(win[1][i])++;
			}
			if(p1table[m][n][i])
			{
				m_p1table[i]=p1table[m][n][i];
				m_win1[i]=win[0][i];

				p1table[m][n][i] = false;
				win[0][i]=7;
			}
		}
		player1 = true;    
		player2 = false;	
}
void CFiveChessView::Judge()
{
	if((p2count == 80) && (p1count == 80))//判断是否平手（本例设定各下80手）
	{
		tie = true;
		over = true;
	}
	for(i=0;i<=1;i++)
		for(j=0;j<572;j++)
		{

			if(win[i][j] == 5)
				if(i==0) //玩家赢     
				{
					p1win = true;
					over = true;
					break;
				}
				else    //计算机赢       
				{
					p2win = true;
					over = true;					
					break;
				}
			if(over)
				break;
		}
}

void CFiveChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDC* pDC=GetDC();
	if(nWithComputer)
	{
		CPoint point1;
		point1=PointToStonePos(point);
		if(board[point1.x][point1.y] != 2) return;
		TwoPlayerGame(pDC, point);
		player1 = !player1;
		player2 = !player2;
		return;
	}	
	CPoint yPoint;
	CPoint cPoint;
	yPoint=PointToStonePos(point);		
	if(!over && player1)
	{
		m = yPoint.x;
		n = yPoint.y;
		m_xCur1=m;
		m_yCur1=n;
		if(board[m][n] == 2) 
		{
			board[m][n] = 0;
			p1count++;
			for(i=0;i<572;i++)
			{
				if(p1table[m][n][i] && win[0][i] != 7)
					win[0][i]++;
				if(p2table[m][n][i])
				{
					m_p2table[i]=p2table[m][n][i];
					m_win2[i]=win[1][i];
					p2table[m][n][i] = false;
					win[1][i]=7;
				}
			}
			player1 = false;
			player2 = true;
		}		
		if(!over)
		{
			if(player2)
				ComputerTurn();
			Judge();//判断输赢
		}		
		for(i=0;i<=14;i++)
			for(j=0;j<=14;j++)
			{
				if(board[i][j] == 0)
				{
					yPoint=PointToStonePos(i,j);
					DisplayStone(pDC,IDB_MASK,yPoint);
					if(nYouFirst)
						DisplayStone(pDC,IDB_WHITE,yPoint);
					else
						DisplayStone(pDC,IDB_BLACK,yPoint);
					if(bCheckSound) PlayMySound(IDSOUND_PUTSTONE);					
				}				
				if(board[i][j] == 1)  
				{
					
					cPoint=PointToStonePos(i,j); 
					DisplayStone(pDC,IDB_MASK,cPoint);	
					if(nYouFirst)
						DisplayStone(pDC,IDB_BLACK,cPoint);
					else
						DisplayStone(pDC,IDB_WHITE,cPoint);
					if(bCheckSound) PlayMySound(IDSOUND_PUTSTONE);				
				}
			}			
			if(p1win)
			{
				if(bCheckSound) PlayMySound(IDSOUND_BLACKWIN);
				Sleep(100);
				MessageBox("您赢了!按下[新局]重新开始游戏..");
			}
			if(p2win)
			{
				if(bCheckSound) PlayMySound(IDSOUND_WHITEWIN);
				Sleep(100);
				MessageBox("电脑赢了!按下[新局]重新进行游戏..");
			}
			if(tie)
				MessageBox("不分胜负!按下[新局]重新进行游戏..");
	}
	if(!over)
		bUndo=true;
	else
		bUndo=false;
	CView::OnLButtonDown(nFlags, point);
}
void CFiveChessView::TwoPlayerGame(CDC *pDC, CPoint point)
{
	CPoint yPoint;
	CPoint cPoint;
	yPoint=PointToStonePos(point);	
	if(!over && player1)
	{
		m = yPoint.x;
		n = yPoint.y;
		yPoint=PointToStonePos(m,n);
		DisplayStone(pDC,IDB_MASK,yPoint);
		if(nYouFirst)
			DisplayStone(pDC,IDB_WHITE,yPoint);
		else
			DisplayStone(pDC,IDB_BLACK,yPoint);
		PlayMySound(IDSOUND_PUTSTONE);		
		if(board[m][n] == 2) 
		{
			board[m][n] = 0;
			p1count++;
			for(i=0;i<572;i++)
			{
				if(p1table[m][n][i] && win[0][i] != 7)
					win[0][i]++;
				if(p2table[m][n][i])
				{
					p2table[m][n][i] = false;
					win[1][i]=7;
				}
			}
		}
	}
	if(!over && player2)
	{
		m = yPoint.x;
		n = yPoint.y;
		cPoint=PointToStonePos(m,n); 
		DisplayStone(pDC,IDB_MASK,cPoint);	
		if(nYouFirst)
			DisplayStone(pDC,IDB_BLACK,cPoint);
		else
			DisplayStone(pDC,IDB_WHITE,cPoint);
		PlayMySound(IDSOUND_PUTSTONE);		
		if(board[m][n] == 2) 
		{
			board[m][n] = 0;
			p2count++;
			for(i=0;i<572;i++)
			{
				if(p2table[m][n][i] && win[1][i] != 7)
					win[1][i]++;
				if(p1table[m][n][i])
				{
					p1table[m][n][i] = false;
					win[0][i]=7;
				}
			}
		}
	}

	Judge();
	
	if(p1win)
	{
		PlayMySound(IDSOUND_WHITEWIN);
		Sleep(100);
		MessageBox("您赢了!按下[新局]重新开始游戏..");
	}
	if(p2win)
	{
		PlayMySound(IDSOUND_WHITEWIN);
		Sleep(100);
		MessageBox("您的对手赢了!按下[新局]重新进行游戏..");
	}
	if(tie)
		MessageBox("不分胜负!按下[新局]重新进行游戏..");
}

void CFiveChessView::OnUndo() 
{
	// TODO: Add your command handler code here
	CDC* pDC=GetDC();
	bUndo=false;
	board[m_xCur1][m_yCur1]=2;
	p1count--;	
	for(i=0;i<572;i++)
	{
		if(p1table[m_xCur1][m_yCur1][i] && win[0][i] != 7)
			win[0][i]--;		
		if(p2table[m_xCur1][m_yCur1][i])
		{
			p2table[m_xCur1][m_yCur1][i]=m_p2table[i];
			win[1][i]=m_win2[i];
		}
	}
	board[m_xCur2][m_yCur2]=2;
	p2count--;

	for(i=0;i<572;i++)
	{
		if(p2table[m_xCur2][m_yCur2][i] && win[1][i] != 7)
			win[1][i]--;
		if(p1table[m_xCur2][m_yCur2][i])
		{
			p1table[m_xCur2][m_yCur2][i]=m_p1table[i];
			win[0][i]=m_win1[i];
		}
	}	
    CPoint point;
	DisplayBoard(pDC,IDB_BOARD);
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			point=PointToStonePos(i,j);
			
			if(board[i][j]==0)
			{
				DisplayStone(pDC,IDB_MASK,point);
				DisplayStone(pDC,IDB_BLACK,point);
			}
			if(board[i][j]==1)
			{
				DisplayStone(pDC,IDB_MASK,point);
				DisplayStone(pDC,IDB_WHITE,point);
			}
		}	
}

void CFiveChessView::OnUpdateUndo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(bUndo);
}
