// nkdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "nkdlg.h"
#include "afxdialogex.h"
#include <string>

// nkdlg 对话框

IMPLEMENT_DYNAMIC(nkdlg, CDialog)

nkdlg::nkdlg(CWnd* pParent /*=NULL*/)
	: CDialog(nkdlg::IDD, pParent)
{

}

nkdlg::~nkdlg()
{
}

void nkdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(nkdlg, CDialog)
END_MESSAGE_MAP()

//c33fc6d3-6bd4-4391-81f0-7ebf7d3357dc
static CLSID const nk_clsid
= { 0xC33FC6D3, 0x6BD4, 0x4391, { 0x81, 0xF0, 0x7E, 0xBF, 0x7D, 0x33, 0x57, 0xDC } };

BEGIN_EVENTSINK_MAP(nkdlg, CDialogEx)
	ON_EVENT(nkdlg, IDC_MFCACTIVEXCONTROCTRL_NK, 1, nkdlg::OnSignInSuccessNkcallctrlctrl1, VTS_I2)
END_EVENTSINK_MAP()


LRESULT nkdlg::onloadocx()
{
	BOOL bSucc = false;
	TCHAR szMsg[1024] = { 0 };

	try
	{

		// MyCtrl必须是全局的CWnd类对象
		bSucc = m_actext1.CreateControl(
			nk_clsid,
			(L"CollectData"),
			0,
			CRect(1, 1, 1, 1),
			this,
			IDC_MFCACTIVEXCONTROCTRL_NK,
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
	catch (...)
	{
		AfxMessageBox(_T("未知错误"));
		return false;
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


LRESULT nkdlg::on_add(LONG lfun, LONG lfun1)
{
	if (spDCollectDataCtl)
	{
		int i = spDCollectDataCtl->Initial();
		std::wstring m_str;
		m_str.append(L"ac_add返回值为 =");
		m_str.append(std::to_wstring(i));
		AfxMessageBox(m_str.c_str());
	}
	return false;
}

HRESULT nkdlg::cb_OnInsertSuccess()
{
	std::wstring m_str;
	m_str.append(L"签入成功 =");
	AfxMessageBox(m_str.c_str());
	return 0;
}
void nkdlg::psssssMfcactivexcontroctrl1(LONG lfun)
{
	std::wstring m_str;
	m_str.append(L"controctrl返回值为 =");
	m_str.append(std::to_wstring(lfun));
	AfxMessageBox(m_str.c_str());
}

// nkdlg 消息处理程序


void nkdlg::OnSignInSuccessNkcallctrlctrl1(short MediaType)
{
	std::wstring m_str;
	m_str.append(L"签入成功 =");
	AfxMessageBox(m_str.c_str());
	// TODO:  在此处添加消息处理程序代码
}
