
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "mfcactivexcontroctrl1.h"
#include "nkcallctrlctrl1.h"


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

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
public:
	bool test1();
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CMfcactivexcontroctrl1 m_actext;
	CWnd m_actext1;
	CNkcallctrlctrl1 m_nkc;
	DECLARE_EVENTSINK_MAP()
	void OnSignInSuccessNkcallctrlctrl1(short MediaType);
	void pCallBack1Mfcactivexcontroctrl1(long lfun);
	void psssssMfcactivexcontroctrl1(long lsssss);
};
