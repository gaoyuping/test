#pragma once

// MFCActiveXControl1Ctrl.h : CMFCActiveXControl1Ctrl ActiveX �ؼ����������


// CMFCActiveXControl1Ctrl : �й�ʵ�ֵ���Ϣ������� MFCActiveXControl1Ctrl.cpp��

class CMFCActiveXControl1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1Ctrl)

// ���캯��
public:
	CMFCActiveXControl1Ctrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

	BOOL IsInvokeAllowed(DISPID);
// ʵ��
protected:
	~CMFCActiveXControl1Ctrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1Ctrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMFCActiveXControl1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1Ctrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMFCActiveXControl1Ctrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
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

