
// cardView.cpp : CcardView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "card.h"
#endif

#include "cardDoc.h"
#include "cardView.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcardView

IMPLEMENT_DYNCREATE(CcardView, CView)

BEGIN_MESSAGE_MAP(CcardView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_32773, &CcardView::On32773)
END_MESSAGE_MAP()

// CcardView ����/����

CcardView::CcardView()
{
	// TODO: �ڴ˴���ӹ������

}

CcardView::~CcardView()
{
}

BOOL CcardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// CcardView ����

void CcardView::OnDraw(CDC* pDC)
{
	CcardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rectClient;
	GetClientRect(&rectClient);

	CDC MemDC;
	CBitmap MemBitmap;
	MemDC.CreateCompatibleDC(NULL);
	MemBitmap.CreateCompatibleBitmap(pDC,rectClient.Width(),rectClient.Height());
	CBitmap *pOldBit=MemDC.SelectObject(&MemBitmap);
	
	CBitmap bkgbitmap;
	bkgbitmap.LoadBitmap(IDB_BKG);
	CBrush bitmapBrush(&bkgbitmap);
	MemDC.FillRect(CRect(0,0,rectClient.right,rectClient.bottom),&bitmapBrush);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(&MemDC);

	MemDC.SetBkMode(TRANSPARENT);
	
	int i,j;
	i=0,j=0;
	for(j = 0;j < renshu;j++)
	{
		while(pai[j][i] != -1)
		{
			dcCompatible.SelectObject(cards[pai[j][i]]);
			CString str;
			str.Format("���%d:",j+1);
			MemDC.SetTextColor(RGB(255,255,74));
			MemDC.TextOutA(0,j*rectClient.bottom/renshu,str);
			if((rectClient.right-50)/perpai > 71)
				MemDC.BitBlt(i*71+50,j*rectClient.bottom/renshu,71,96,&dcCompatible,0,0,SRCCOPY);
			else
				MemDC.BitBlt(i*(rectClient.right-121)/(perpai-1)+50,j*rectClient.bottom/renshu,71,96,&dcCompatible,0,0,SRCCOPY);
			i++;
		}
		i=0;
	}
	pDC->BitBlt(0,0,rectClient.right,rectClient.bottom,&MemDC,0,0,SRCCOPY);
	
	dcCompatible.DeleteDC();
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
	
}

void CcardView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
	CRect rectClient;
	GetClientRect(&rectClient);
	CClientDC dc(this);
	CBitmap bkgbitmap;
	bkgbitmap.LoadBitmap(IDB_BKG);
	CBrush bitmapBrush(&bkgbitmap);
	dc.FillRect(CRect(0,0,rectClient.right,rectClient.bottom),&bitmapBrush);

	if(IDYES == MessageBox("Again?",0,MB_YESNO))
	{
		m_fvProcCard();
		Invalidate(FALSE);
	}
	else
		Invalidate(FALSE);
}

void CcardView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcardView ���

#ifdef _DEBUG
void CcardView::AssertValid() const
{
	CView::AssertValid();
}

void CcardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcardDoc* CcardView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcardDoc)));
	return (CcardDoc*)m_pDocument;
}
#endif //_DEBUG


// CcardView ��Ϣ�������


BOOL CcardView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}


int CcardView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	ji=0; 
	huanhang=0; 
	heitao=06;
	hongtao=03;
	meihua=05;
	fangpian=04;
	 cards[0]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[1]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[2]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[3]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����5.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[4]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[5]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[6]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[7]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[8]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����10.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	 cards[9]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����J.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[10]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����Q.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[11]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����K.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[12]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[13]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[14]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[15]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[16]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����5.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[17]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[18]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[19]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[20]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[21]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����10.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[22]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����J.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[23]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����Q.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[24]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����K.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[25]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[26]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[27]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[28]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[29]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��5.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[30]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[31]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[32]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[33]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[34]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��10.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[35]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��J.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[36]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��Q.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[37]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��K.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[38]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\÷��1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[39]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ2.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[40]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ3.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[41]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ4.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[42]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ5.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[43]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ6.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[44]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ7.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[45]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ8.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[46]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ9.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[47]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ10.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[48]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��ƬJ.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[49]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��ƬQ.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[50]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��ƬK.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[51]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\��Ƭ1.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[52]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\С��.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[53]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	cards[54]=(HBITMAP)::LoadImage(NULL,_T("res\\cards\\����.bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	SetTimer(1,50,NULL);
	renshu = 4;
	paishu = 54;
	perpai = 13;
	m_fvProcCard();
	hAccel=::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	return 0;
}


void CcardView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}

void CcardView::m_fvProcCard()
{
	int temp,i,j,k,a;//��־λ

	srand(time(NULL));
	for(i=0;i<54;i++)
	{
		fen[i]=-1;
		for(j=0;j<54;j++)
			pai[i][j]=-1;//û����Ϊ-1 
	}
	for(i=0;i<paishu;i++)
	{  
		//          while(fen[i]==-1)
		//          {
		fen[i]=rand()%paishu;
		//          }
		for(j=0;j<i;j++)
		{ 
			if(fen[j]==fen[i])//�ж���û��һ����
			{   
				fen[i]=rand()%paishu;
				j=-1;
			}    
		}
		//        cout<<fen[i]<<'\n'; 
	}
	//cout<<"����ǣ�"<<'\n';
	a=0;
	for(i=0;i<renshu;i++)
	{
		for(j=0;j<perpai;j++)
		{
			pai[i][j]=fen[a];
			a++;
			for(k=0;k<j;k++)
			{
				if(pai[i][j]<pai[i][k])
				{
					temp=pai[i][k];
					pai[i][k]=pai[i][j];
					pai[i][j]=temp;  
				}      
			}  
		}
	}
}

void CcardView::On32773()
{
	// TODO: �ڴ���������������
	CConfigDlg dlg;
	dlg.m_renshu.Format("%d",renshu);
	dlg.m_perpai.Format("%d",perpai);
	if(IDOK==dlg.DoModal())
	{
		renshu = dlg.renshu;
		perpai = dlg.perpai;
		paishu = dlg.paishu;
		m_fvProcCard();
		Invalidate(FALSE);
	}
}


BOOL CcardView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(::TranslateAccelerator(GetSafeHwnd(),hAccel,pMsg))   
		return   true;
	return CView::PreTranslateMessage(pMsg);
}
