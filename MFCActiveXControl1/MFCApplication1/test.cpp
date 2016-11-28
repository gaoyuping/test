// test.cpp : Ctest ��ʵ��

#include "stdafx.h"
#include "test.h"
// #import "C:/gyp/codetest/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
// 	named_guids
// using namespace MFCActiveXControl1Lib;

static CLSID const clsid
= { 0xF1D13F33, 0xD072, 0x4DB9, { 0x85, 0xE4, 0x97, 0xF, 0x73, 0x38, 0x11, 0x16 } };

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };




LRESULT Ctest::onloadocx()
{
	BOOL bSucc = false;
	TCHAR szMsg[1024] = { 0 };

	try
	{

		// MyCtrl������ȫ�ֵ�CWnd�����
		bSucc = m_actext1.CreateControl(
			clsid,
			(L"CollectData"),
			0,
			CRect(1, 1, 1, 1),
			(CWnd*)this,
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

	int i = spDCollectDataCtl->ac_add(1, 1);
	i = 10;
	return true;
}


LRESULT Ctest::on_add(LONG lfun, LONG lfun1)
{
	if (spDCollectDataCtl)
	{
		int i = spDCollectDataCtl->ac_add(3, 4);
		i = 100;
	}
	return false;
}
// Ctest
