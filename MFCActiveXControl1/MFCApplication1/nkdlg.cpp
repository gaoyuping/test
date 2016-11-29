// nkdlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "nkdlg.h"
#include "afxdialogex.h"
#include <string>

// nkdlg �Ի���

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

		// MyCtrl������ȫ�ֵ�CWnd�����
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
		AfxMessageBox(_T("δ֪����"));
		return false;
	}
	if (!bSucc)
	{
		AfxMessageBox(_T("����CollectData.ocx�ؼ�ʧ��\r\n����CollectData.ocx�ؼ��Ƿ�װ��ע��"));
		return false;
	}

	IUnknown *pUnk = m_actext1.GetControlUnknown();
	spDCollectDataCtl = pUnk;
	if (spDCollectDataCtl == NULL)
	{
		AfxMessageBox(_T("�޷���CollectData.ocx�л�ȡ_DCollectData�ӿ�"));
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
		m_str.append(L"ac_add����ֵΪ =");
		m_str.append(std::to_wstring(i));
		AfxMessageBox(m_str.c_str());
	}
	return false;
}

HRESULT nkdlg::cb_OnInsertSuccess()
{
	std::wstring m_str;
	m_str.append(L"ǩ��ɹ� =");
	AfxMessageBox(m_str.c_str());
	return 0;
}
void nkdlg::psssssMfcactivexcontroctrl1(LONG lfun)
{
	std::wstring m_str;
	m_str.append(L"controctrl����ֵΪ =");
	m_str.append(std::to_wstring(lfun));
	AfxMessageBox(m_str.c_str());
}

// nkdlg ��Ϣ�������


void nkdlg::OnSignInSuccessNkcallctrlctrl1(short MediaType)
{
	std::wstring m_str;
	m_str.append(L"ǩ��ɹ� =");
	AfxMessageBox(m_str.c_str());
	// TODO:  �ڴ˴������Ϣ����������
}
