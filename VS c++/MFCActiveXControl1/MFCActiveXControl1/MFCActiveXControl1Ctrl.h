#pragma once

// MFCActiveXControl1Ctrl.h : CMFCActiveXControl1Ctrl ActiveX 控件类的声明。


// CMFCActiveXControl1Ctrl : 有关实现的信息，请参阅 MFCActiveXControl1Ctrl.cpp。

class CMFCActiveXControl1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1Ctrl)

// 构造函数
public:
	CMFCActiveXControl1Ctrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

	BOOL IsInvokeAllowed(DISPID);
// 实现
protected:
	~CMFCActiveXControl1Ctrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1Ctrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMFCActiveXControl1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1Ctrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMFCActiveXControl1Ctrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		eventidpsssss1 = 4L,
		eventidpsssss = 3L,
		dispidpCallBack1 = 2L,
		dispidpCallback = 1L,
		dispidsetCallBack = 2L,
		dispidac_add = 1L
	};
public:
	LONG ac_add(LONG fun1, LONG fun2);
	void setCallBack(IUnknown* pCallBack);
	public:
	
	//ICallBack* m_pCallBack;
	LONG pCallback();
protected:
	void pCallBack1(LONG lfun);

	void psssss(LONG lsssss)
	{
		FireEvent(eventidpsssss, EVENT_PARAM(VTS_I4), lsssss);
	}


	void psssss1(LONG rlong, LONG llong)
	{
		FireEvent(eventidpsssss1, EVENT_PARAM(VTS_I4 VTS_I4), rlong, llong);
	}
};

