#pragma once
#import "C:/NKcallctrl4.1.3.2/NkCallCtrl.ocx" \
	named_guids
using namespace NKCALLCTRLLib;

// nkdlg �Ի���

class nkdlg : public CDialog
{
	DECLARE_DYNAMIC(nkdlg)

public:
	nkdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~nkdlg();

// �Ի�������
	enum { IDD = IDD_NKDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_EVENTSINK_MAP()
public:
	LRESULT onloadocx();
	LRESULT on_add(LONG lfun, LONG lfun1);
	HRESULT cb_OnInsertSuccess();
	void psssssMfcactivexcontroctrl1(LONG lfun);

private:
	CWnd m_actext1;
	CComQIPtr<_DNkCallCtrl> spDCollectDataCtl;
public:
	void OnSignInSuccessNkcallctrlctrl1(short MediaType);
};
