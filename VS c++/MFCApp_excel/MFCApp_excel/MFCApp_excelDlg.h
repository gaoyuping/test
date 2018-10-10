
// MFCApp_excelDlg.h : 头文件
//

#pragma once
#include <vector>

// CMFCApp_excelDlg 对话框
class CMFCApp_excelDlg : public CDialogEx
{
// 构造
public:
	CMFCApp_excelDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPP_EXCEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
