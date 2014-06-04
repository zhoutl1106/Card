// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "card.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"

// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialogEx)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CConfigDlg::IDD, pParent)
	, m_renshu(_T("4"))
	, m_wang(0)
	, m_perpai(_T("13"))
	, paishu(54)
{

}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_renshu);
	DDV_MaxChars(pDX, m_renshu, 2);
	DDX_Radio(pDX, IDC_RADIO1, m_wang);
	DDX_Text(pDX, IDC_EDIT2, m_perpai);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CConfigDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CConfigDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CConfigDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CConfigDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CConfigDlg 消息处理程序

void CConfigDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CConfigDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if((int)GetDlgItemInt(IDC_EDIT1)*(int)GetDlgItemInt(IDC_EDIT2)<=paishu && 0 != (int)GetDlgItemInt(IDC_EDIT1)*(int)GetDlgItemInt(IDC_EDIT2))
	{
		renshu=(int)GetDlgItemInt(IDC_EDIT1);
		perpai=(int)GetDlgItemInt(IDC_EDIT2);
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox("玩家数或每人牌数输入有误！");
	}
}


void CConfigDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	paishu = 54;
}


void CConfigDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	paishu = 52;
}
