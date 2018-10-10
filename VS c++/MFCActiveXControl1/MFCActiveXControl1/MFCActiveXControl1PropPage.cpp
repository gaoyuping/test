// MFCActiveXControl1PropPage.cpp : CMFCActiveXControl1PropPage 属性页类的实现。

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1PropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CMFCActiveXControl1PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1PropPage, "MFCACTIVEXCONT.MFCActiveXContPropPage.1",
	0x4a25d138, 0x784e, 0x4621, 0xaa, 0xad, 0x5a, 0x2f, 0x68, 0x90, 0x8d, 0xaa)

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry -
// 添加或移除 CMFCActiveXControl1PropPage 的系统注册表项

BOOL CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage - 构造函数

CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL1_PPG_CAPTION)
{
}

// CMFCActiveXControl1PropPage::DoDataExchange - 在页和属性间移动数据

void CMFCActiveXControl1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCActiveXControl1PropPage 消息处理程序
