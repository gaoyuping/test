
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "mfcactivexcontroctrl1.h"
#include "nkcallctrlctrl1.h"


// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

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
	afx_msg void OnBnClickedButton3();
};
