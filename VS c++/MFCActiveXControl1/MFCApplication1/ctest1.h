#pragma once
// #import "C:/Users/gyp/Desktop/NKcallctrl4.1.3.2/NKcallctrl4.1.3.2/NkCallCtrl.ocx" \
// 	named_guids
// using namespace NKCALLCTRLLib;


#import "C:/gyp/codetest/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
	named_guids
using namespace MFCActiveXControl1Lib;
// ctest1 �Ի���

class ctest1 : public CDialogEx
{
	DECLARE_DYNAMIC(ctest1)

public:
	ctest1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ctest1();

// �Ի�������
	enum { IDD = IDD_CTEST1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_EVENTSINK_MAP()

public:
	LRESULT onloadocx();
	LRESULT on_add(LONG lfun, LONG lfun1);
	void psssssMfcactivexcontroctrl1(LONG lfun);

private:
	CWnd m_actext1;
	CComQIPtr<_DMFCActiveXControl1> spDCollectDataCtl;
};
