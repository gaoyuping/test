// test.h : Ctest 的声明

#pragma once

#include "resource.h"       // 主符号

#include <atlhost.h>

using namespace ATL;
#include <afxwin.h>
// Ctest
#import "C:/gyp/code/github/codetest/trunk/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
	named_guids

struct __declspec(uuid("8bb1b5a6-fe1b-4234-8e8a-5b694570936d"))AAA;
using namespace MFCActiveXControl1Lib;
//_ATL_FUNC_INFO OnDocChangeInfo = { CC_STDCALL, VT_EMPTY, 0 };
class Ctest : 
 	public CAxDialogImpl<Ctest>
	//,public ATL::_IDispEventLocator
	,public ATL::IDispEventSimpleImpl<0, Ctest, &__uuidof(_DMFCActiveXControl1Events) >
	//, public IDispatchImpl<MFCActiveXControl1, &__uuidof(_DMFCActiveXControl1Events), &__uuidof(_DMFCActiveXControl1)>
	//, public IDispEventImpl<1, Ctest, &__uuidof(_DMFCActiveXControl1Events), &LIBID_MSHTML, 1, 0>


// 	,public IDispatchImpl<Ctest, &IDD_TEST, &MFCActiveXControl1Lib>,
// 	,public IDispEventImpl<1, CCGBandObj, &_DMFCActiveXControl1Events, &LIBID_MSHTML, 4, 0>,
{
public:
	Ctest()
	{
	}

	~Ctest()
	{
	}

	enum { IDD = IDD_TEST };

BEGIN_MSG_MAP(Ctest)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
// 	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
// 	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	CHAIN_MSG_MAP(CAxDialogImpl<Ctest>)
END_MSG_MAP()

BEGIN_SINK_MAP(Ctest)
	//SINK_ENTRY_INFO(0, __uuidof(MFCActiveXControl1), /*dispid =*/ 0x2, OnDocChange, &OnDocChangeInfo)
END_SINK_MAP()
// BEGIN_EVENTSINK_MAP(CMFCApplication1Dlg, CDialogEx)
// 	//ON_EVENT(CMFCApplication1Dlg, IDC_NKCALLCTRLCTRL1, 1, CMFCApplication1Dlg::OnSignInSuccessNkcallctrlctrl1, VTS_I2)
// 	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL1, 2, CMFCApplication1Dlg::pCallBack1Mfcactivexcontroctrl1, VTS_I4)
// 	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL1, 3, CMFCApplication1Dlg::psssssMfcactivexcontroctrl1, VTS_I4)
// 
// 
// 	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL_TEXT1, 3, CMFCApplication1Dlg::psssssMfcactivexcontroctrl1, VTS_I4)
// END_EVENTSINK_MAP()
// BEGIN_EVENT_MAP(Ctest, CAxDialogImpl<Ctest>)
// 	BEGIN_EVENT_MAP()
//DECLARE_EVENTSINK_MAP()
// 处理程序原型: 
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

private:
	CWnd m_actext1;
	CComQIPtr<_DMFCActiveXControl1> spDCollectDataCtl;
public:

	void __stdcall OnDocChange()
	{
	}
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CAxDialogImpl<Ctest>::OnInitDialog(uMsg, wParam, lParam, bHandled);
		bHandled = TRUE;
		spDCollectDataCtl = nullptr;
		//onloadocx();
		return 1;  // 使系统设置焦点
	}

	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT onloadocx();
	LRESULT on_add(LONG lfun, LONG lfun1);
	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		DISPPARAMS* pDispParams, VARIANT* pVarResult,
		EXCEPINFO* pExcepInfo, UINT* puArgErr);

	void setspDCollectDataCtl(_DMFCActiveXControl1*ptr){ spDCollectDataCtl = ptr; };
	void setDispEventAdvise();
};


