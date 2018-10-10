// test.cpp : Ctest ��ʵ��

#include "stdafx.h"
#include "test.h"
#include <string>
// #import "C:/gyp/codetest/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
// 	named_guids
// using namespace MFCActiveXControl1Lib;

static CLSID const clsid
= { 0xF1D13F33, 0xD072, 0x4DB9, { 0x85, 0xE4, 0x97, 0xF, 0x73, 0x38, 0x11, 0x16 } };
const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };

// BEGIN_SINK_MAP(Ctest)
// 	SINK_ENTRY_INFO(/*nID =*/ 1, __uuidof(MFCActiveXControl1), /*dispid =*/ 0x2, OnDocChange, &OnDocChangeInfo)
// END_SINK_MAP()
#define EVENT_psssss		3
#define EVENT_psssss1		4



DWORD WINAPI funproc(LPVOID lpparentet)
{
	Ctest *pparent = (Ctest*)lpparentet;

	if (nullptr == pparent)
	{
		return -1;
	}
	BOOL bSucc = false;
	TCHAR szMsg[1024] = { 0 };

	try
	{
		_DMFCActiveXControl1 * IkuanATL = NULL;

		HRESULT hr = CoInitialize(NULL);    //��ʼ��COM

		//ʹ��SUCCEEDED�겢��������Ƿ��ܵõ�һ���ӿ�ָ��
		if (SUCCEEDED(hr))
		{
			hr = CoCreateInstance(clsid,
				NULL,
				CLSCTX_INPROC_SERVER,
				IID_DMFCActiveXControl1,
				(void **)&IkuanATL);
			//����ɹ��������AddNumbers������������ʾ��Ӧ�ĳ�����Ϣ
			if (SUCCEEDED(hr))
			{
				pparent->setspDCollectDataCtl(IkuanATL);
				// 				long ReturnValue;
				//IkuanATL->ac_add(8, 9);
				// 				//cout << "The answer for 8+9 is:" << ReturnValue << endl;
				//IkuanATL->Release();
			}
			else
			{
				//cout << "CoCreateInstance Failed." << endl;
			}
		}
		//CoUninitialize();//�ͷ�COM

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

	// 	if (!bSucc)
	// 	{
	// 		AfxMessageBox(_T("����CollectData.ocx�ؼ�ʧ��\r\n����CollectData.ocx�ؼ��Ƿ�װ��ע��"));
	// 		return false;
	// 	}

	//IUnknown *pUnk = m_actext1.GetControlUnknown();
	pparent->setDispEventAdvise();
	pparent->on_add(6, 7);
	// 	if (spDCollectDataCtl == NULL)
	// 	{
	// 		AfxMessageBox(_T("�޷���CollectData.ocx�л�ȡ_DCollectData�ӿ�"));
	// 		return false;
	// 	}
	Sleep(10000);
	//std::cout << "���߳��̣߳�" << std::endl;
	return 0;
}


LRESULT Ctest::onloadocx()
{
	CreateThread(NULL, 0, funproc, (void*)this, 0, NULL);
	return 0;
#if 1
	BOOL bSucc = false;
	TCHAR szMsg[1024] = { 0 };

	try
	{

		// MyCtrl������ȫ�ֵ�CWnd�����
		// 		bSucc = m_actext1.CreateControl(
		// 			clsid,
		// 			(L"CollectData"),
		// 			0,
		// 			CRect(1, 1, 1, 1),
		// 			NULL,
		// 			IDC_MFCACTIVEXCONTROCTRL_TEXT1,
		// 			NULL, FALSE, NULL);

		_DMFCActiveXControl1 * IkuanATL = NULL;

		HRESULT hr = CoInitialize(NULL);    //��ʼ��COM

		//ʹ��SUCCEEDED�겢��������Ƿ��ܵõ�һ���ӿ�ָ��
		if (SUCCEEDED(hr))
		{
			hr = CoCreateInstance(clsid,
				NULL,
				CLSCTX_INPROC_SERVER,
				IID_DMFCActiveXControl1,
				(void **)&IkuanATL);
			//����ɹ��������AddNumbers������������ʾ��Ӧ�ĳ�����Ϣ
			if (SUCCEEDED(hr))
			{
				spDCollectDataCtl = IkuanATL;
				// 				long ReturnValue;
				// 				//IkuanATL->ac_add(8, 9);
				// 				//cout << "The answer for 8+9 is:" << ReturnValue << endl;
				// 				IkuanATL->Release();
			}
			else
			{
				//cout << "CoCreateInstance Failed." << endl;
			}
		}
		//CoUninitialize();//�ͷ�COM

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

	// 	if (!bSucc)
	// 	{
	// 		AfxMessageBox(_T("����CollectData.ocx�ؼ�ʧ��\r\n����CollectData.ocx�ؼ��Ƿ�װ��ע��"));
	// 		return false;
	// 	}

	//IUnknown *pUnk = m_actext1.GetControlUnknown();
	DispEventAdvise(spDCollectDataCtl);

	if (spDCollectDataCtl == NULL)
	{
		AfxMessageBox(_T("�޷���CollectData.ocx�л�ȡ_DCollectData�ӿ�"));
		return false;
	}
#endif
	
	return true;
}

void Ctest::setDispEventAdvise()
{
	if (spDCollectDataCtl)
	{
		DispEventAdvise(spDCollectDataCtl);
	}
}

LRESULT Ctest::on_add(LONG lfun, LONG lfun1)
{
	if (spDCollectDataCtl)
	{
		int i = spDCollectDataCtl->ac_add(1, 4);
		i = 100;
	}
	return false;
}



STDMETHODIMP Ctest::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
	DISPPARAMS* pDispParams, VARIANT* pVarResult,
	EXCEPINFO* pExcepInfo, UINT* puArgErr)
{

	if (IID_NULL != riid)
	{
		return DISP_E_UNKNOWNINTERFACE;
	}

	if (!pDispParams)
	{
		return DISP_E_PARAMNOTOPTIONAL;
	}

	switch (dispIdMember)
	{
	case EVENT_psssss:
	     {
			if (1 == pDispParams->cArgs)
			{
				LONG ling = pDispParams->rgvarg[0].lVal;
				ling = -1;
			}
	     }
		break;
	case EVENT_psssss1:
		{
			if (2 == pDispParams->cArgs)
			{
				LONG ling = pDispParams->rgvarg[0].lVal;;
				ling = -1;
				ling = pDispParams->rgvarg[1].lVal;
				ling = -1;
			}
		}
		break;
	default:
		return DISP_E_MEMBERNOTFOUND;
	}

	return S_OK;
}

// Ctest
