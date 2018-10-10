// MFCActiveXControl1Ctrl.cpp : CMFCActiveXControl1Ctrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1Ctrl.h"
#include "MFCActiveXControl1PropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1Ctrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMFCActiveXControl1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CMFCActiveXControl1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "ac_add", dispidac_add, ac_add, VT_I4, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "setCallBack", dispidsetCallBack, setCallBack, VT_EMPTY, VTS_UNKNOWN)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "pCallback", dispidpCallback, pCallback, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "pCallBack1", dispidpCallBack1, pCallBack1, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CMFCActiveXControl1Ctrl, COleControl)
	EVENT_CUSTOM_ID("psssss", eventidpsssss, psssss, VTS_I4)
	EVENT_CUSTOM_ID("pCallBack1", dispidpCallBack1, pCallBack1, VTS_I4)
	EVENT_CUSTOM_ID("psssss1", eventidpsssss1, psssss1, VTS_I4 VTS_I4)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMFCActiveXControl1Ctrl, 1)
	PROPPAGEID(CMFCActiveXControl1PropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1Ctrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1Ctrl, "MFCACTIVEXCONTRO.MFCActiveXControCtrl.1",
	0xf1d13f33, 0xd072, 0x4db9, 0x85, 0xe4, 0x97, 0xf, 0x73, 0x38, 0x11, 0x16)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMFCActiveXControl1Ctrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };
const IID IID_DMFCActiveXControl1Events = { 0x8BB1B5A6, 0xFE1B, 0x4234, { 0x8E, 0x8A, 0x5B, 0x69, 0x45, 0x70, 0x93, 0x6D } };

// �ؼ�������Ϣ

static const DWORD _dwMFCActiveXControl1OleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1Ctrl, IDS_MFCACTIVEXCONTROL1, _dwMFCActiveXControl1OleMisc)


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMFCActiveXControl1Ctrl ��ϵͳע�����

BOOL CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL1,
			IDB_MFCACTIVEXCONTROL1,
			afxRegApartmentThreading,
			_dwMFCActiveXControl1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl - ���캯��

CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1, &IID_DMFCActiveXControl1Events);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl - ��������

CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

BOOL CMFCActiveXControl1Ctrl::IsInvokeAllowed(DISPID)
{
	// You can check to see if COleControl::m_bInitialized is FALSE
	// in your automation functions to limit access.
	return TRUE;
}
// CMFCActiveXControl1Ctrl::OnDraw - ��ͼ����

void CMFCActiveXControl1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1Ctrl::DoPropExchange - �־���֧��

void CMFCActiveXControl1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CMFCActiveXControl1Ctrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMFCActiveXControl1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CMFCActiveXControl1Ctrl ��Ϣ�������


LONG CMFCActiveXControl1Ctrl::ac_add(LONG fun1, LONG fun2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
// 	pCallback();
// 	pCallBack1(fun1 * fun2);
	psssss(fun1 * fun2);
	psssss1(fun1 - fun2, fun2 - fun1);
	return fun1 + fun2;
}


void CMFCActiveXControl1Ctrl::setCallBack(IUnknown* pCallBack)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (NULL != pCallBack)
	{
		//m_pCallBack = pCallBack;
	}
	// TODO:  �ڴ���ӵ��ȴ���������
}


LONG CMFCActiveXControl1Ctrl::pCallback()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

	return 0;
}



void CMFCActiveXControl1Ctrl::pCallBack1(LONG lfun)
{

	FireEvent(dispidpCallBack1, EVENT_PARAM(VTS_I4), lfun);
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
}
