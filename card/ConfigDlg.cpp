// ConfigDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "card.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"

// CConfigDlg �Ի���

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


// CConfigDlg ��Ϣ�������

void CConfigDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CConfigDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if((int)GetDlgItemInt(IDC_EDIT1)*(int)GetDlgItemInt(IDC_EDIT2)<=paishu && 0 != (int)GetDlgItemInt(IDC_EDIT1)*(int)GetDlgItemInt(IDC_EDIT2))
	{
		renshu=(int)GetDlgItemInt(IDC_EDIT1);
		perpai=(int)GetDlgItemInt(IDC_EDIT2);
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox("�������ÿ��������������");
	}
}


void CConfigDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	paishu = 54;
}


void CConfigDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	paishu = 52;
}
