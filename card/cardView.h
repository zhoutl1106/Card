
// cardView.h : CcardView 类的接口
//

#pragma once

class CcardView : public CView
{
protected: // 仅从序列化创建
	CcardView();
	DECLARE_DYNCREATE(CcardView)

// 特性
public:
	CcardDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CcardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	int renshu;//有多少人 
	char wang;//有没有王 
	int perpai;//每人的张数 
	int zongpai;//总共多少
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

#ifndef _DEBUG  // cardView.cpp 中的调试版本
inline CcardDoc* CcardView::GetDocument() const
   { return reinterpret_cast<CcardDoc*>(m_pDocument); }
#endif

