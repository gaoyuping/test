
// MFCApp_excelDlg.h : ͷ�ļ�
//

#pragma once
#include <vector>

// CMFCApp_excelDlg �Ի���
class CMFCApp_excelDlg : public CDialogEx
{
// ����
public:
	CMFCApp_excelDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPP_EXCEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	std::vector<std::wstring> m_a;
	std::vector<std::wstring> m_b;
public:
	afx_msg void OnBnClickedButton1();

	bool findstring(std::wstring, std::wstring, int);
	int m_minlen;
	CString m_filename;
};
