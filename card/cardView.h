
// cardView.h : CcardView ��Ľӿ�
//

#pragma once

class CcardView : public CView
{
protected: // �������л�����
	CcardView();
	DECLARE_DYNCREATE(CcardView)

// ����
public:
	CcardDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CcardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	HBITMAP cards[55];
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	int renshu;//�ж����� 
	char wang;//��û���� 
	int perpai;//ÿ�˵����� 
	int zongpai;//�ܹ�����
	int paishu;
	char ji; 
	char huanhang; 
	int pai[54][54];
	int fen[54];
	char heitao;
	char hongtao;
	char meihua;
	char fangpian;
	void m_fvProcCard();
	afx_msg void On32773();
	HACCEL   hAccel;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // cardView.cpp �еĵ��԰汾
inline CcardDoc* CcardView::GetDocument() const
   { return reinterpret_cast<CcardDoc*>(m_pDocument); }
#endif

