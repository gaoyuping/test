// MFCActiveXControl1Ctrl.cpp : CMFCActiveXControl1Ctrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1Ctrl.h"
#include "MFCActiveXControl1PropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1Ctrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CMFCActiveXControl1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CMFCActiveXControl1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "ac_add", dispidac_add, ac_add, VT_I4, VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "setCallBack", dispidsetCallBack, setCallBack, VT_EMPTY, VTS_UNKNOWN)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "pCallback", dispidpCallback, pCallback, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "pCallBack1", dispidpCallBack1, pCallBack1, VT_EMPTY, VTS_I4)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CMFCActiveXControl1Ctrl, COleControl)

	EVENT_CUSTOM_ID("psssss", eventidpsssss, psssss, VTS_I4)
	EVENT_CUSTOM_ID("pCallBack1", dispidpCallBack1, pCallBack1, VTS_I4)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CMFCActiveXControl1Ctrl, 1)
	PROPPAGEID(CMFCActiveXControl1PropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1Ctrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1Ctrl, "MFCACTIVEXCONTRO.MFCActiveXControCtrl.1",
	0xf1d13f33, 0xd072, 0x4db9, 0x85, 0xe4, 0x97, 0xf, 0x73, 0x38, 0x11, 0x16)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMFCActiveXControl1Ctrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };
const IID IID_DMFCActiveXControl1Events = { 0x8BB1B5A6, 0xFE1B, 0x4234, { 0x8E, 0x8A, 0x5B, 0x69, 0x45, 0x70, 0x93, 0x6D } };

// 控件类型信息

static const DWORD _dwMFCActiveXControl1OleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1Ctrl, IDS_MFCACTIVEXCONTROL1, _dwMFCActiveXControl1OleMisc)


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry -
// 添加或移除 CMFCActiveXControl1Ctrl 的系统注册表项

BOOL CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl - 构造函数

CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1, &IID_DMFCActiveXControl1Events);
	// TODO:  在此初始化控件的实例数据。
}

// CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl - 析构函数

CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CMFCActiveXControl1Ctrl::OnDraw - 绘图函数

void CMFCActiveXControl1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1Ctrl::DoPropExchange - 持久性支持

void CMFCActiveXControl1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CMFCActiveXControl1Ctrl::OnResetState - 将控件重置为默认状态

void CMFCActiveXControl1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CMFCActiveXControl1Ctrl 消息处理程序


LONG CMFCActiveXControl1Ctrl::ac_add(LONG fun1, LONG fun2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	pCallback();
	pCallBack1(fun1 * fun2);
	psssss(fun1 * fun2);
	return fun1 + fun2;
}


void CMFCActiveXControl1Ctrl::setCallBack(IUnknown* pCallBack)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (NULL != pCallBack)
	{
		//m_pCallBack = pCallBack;
	}
	// TODO:  在此添加调度处理程序代码
}


LONG CMFCActiveXControl1Ctrl::pCallback()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码

	return 0;
}



void CMFCActiveXControl1Ctrl::pCallBack1(LONG lfun)
{

	FireEvent(dispidpCallBack1, EVENT_PARAM(VTS_I4), lfun);
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
}
