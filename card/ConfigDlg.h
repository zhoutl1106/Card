#pragma once


// CConfigDlg �Ի���

class CConfigDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigDlg();

// �Ի�������
	enum { IDD = IDD_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_renshu;
	afx_msg void OnEnChangeEdit1();

	int renshu;
	int paishu;
	int perpai;
	afx_msg void OnBnClickedOk();
	int m_wang;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CString m_perpai;
};

