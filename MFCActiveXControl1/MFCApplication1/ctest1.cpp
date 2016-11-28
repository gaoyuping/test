// ctest1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ctest1.h"
#include "afxdialogex.h"
#include <string>


static CLSID const clsid
= { 0xF1D13F33, 0xD072, 0x4DB9, { 0x85, 0xE4, 0x97, 0xF, 0x73, 0x38, 0x11, 0x16 } };

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };

// ctest1 对话框

IMPLEMENT_DYNAMIC(ctest1, CDialogEx)

ctest1::ctest1(CWnd* pParent /*=NULL*/)
	: CDialogEx(ctest1::IDD, pParent)
{
	
}

ctest1::~ctest1()
{
}

void ctest1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ctest1, CDialogEx)
END_MESSAGE_MAP()




BEGIN_EVENTSINK_MAP(ctest1, CDialogEx)
	ON_EVENT(ctest1, IDC_MFCACTIVEXCONTROCTRL_TEXT1, 3, ctest1::psssssMfcactivexcontroctrl1, VTS_I4)
END_EVENTSINK_MAP()


LRESULT ctest1::onloadocx()
{
	BOOL bSucc = false;
	TCHAR szMsg[1024] = { 0 };

	try
	{

		// MyCtrl必须是全局的CWnd类对象
		bSucc = m_actext1.CreateControl(
			clsid,
			(L"CollectData"),
			0,
			CRect(1, 1, 1, 1),
			this,
			IDC_MFCACTIVEXCONTROCTRL_TEXT1,
			NULL, FALSE, NULL);
	}
	catch (CMemoryException* e)
	{
		e->GetErrorMessage(szMsg, 1024);
		e->Delete();
	}
	catch (CFileException* e)
	{
		e->GetErrorMessage(szMsg, 1024);
		e->Delete();
	}
	catch (CException* e)
	{
		e->GetErrorMessage(szMsg, 1024);
		e->Delete();
	}

	if (!bSucc)
	{
		AfxMessageBox(_T("创建CollectData.ocx控件失败\r\n请检查CollectData.ocx控件是否安装并注册"));
		return false;
	}

	IUnknown *pUnk = m_actext1.GetControlUnknown();
	spDCollectDataCtl = pUnk;
	if (spDCollectDataCtl == NULL)
	{
		AfxMessageBox(_T("无法从CollectData.ocx中获取_DCollectData接口"));
		return false;
	}
	int i = _MSC_VER;
	std::wstring m_str;
	m_str.append(L"load succ!");
	AfxMessageBox(m_str.c_str());
	return true;
}


LRESULT ctest1::on_add(LONG lfun, LONG lfun1)
{
	if (spDCollectDataCtl)
	{
		int i = spDCollectDataCtl->ac_add(3, 4);
		i = 100;
	}
	return false;
}

void ctest1::psssssMfcactivexcontroctrl1(LONG lfun)
{
	std::wstring m_str;
	m_str.append(L"返回值为 =");
	m_str.append(std::to_wstring(lfun));
	AfxMessageBox(m_str.c_str());
}

// ctest1 消息处理程序
