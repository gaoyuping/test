// test.h : Ctest 的声明

#pragma once

#include "resource.h"       // 主符号

#include <atlhost.h>

using namespace ATL;
#include <afxwin.h>
// Ctest
#import "C:/gyp/codetest/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
	named_guids
using namespace MFCActiveXControl1Lib;
class Ctest : 
	public CAxDialogImpl<Ctest>
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
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	CHAIN_MSG_MAP(CAxDialogImpl<Ctest>)
END_MSG_MAP()


//DECLARE_EVENTSINK_MAP()
// 处理程序原型: 
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

private:
	CWnd m_actext1;
	CComQIPtr<_DMFCActiveXControl1> spDCollectDataCtl;
public:
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CAxDialogImpl<Ctest>::OnInitDialog(uMsg, wParam, lParam, bHandled);
		bHandled = TRUE;
		spDCollectDataCtl = nullptr;
		onloadocx();
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
};


