#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装器类

// 注意:  不要修改此文件的内容。  如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CNkcallctrlctrl1 包装器类

class CNkcallctrlctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CNkcallctrlctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xC33FC6D3, 0x6BD4, 0x4391, { 0x81, 0xF0, 0x7E, 0xBF, 0x7D, 0x33, 0x57, 0xDC } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:


// 操作
public:

// _DNkCallCtrl

// Functions
//

	long Initial()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Uninitial()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SignIn()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SignOut()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long ReleaseCall(long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType);
		return result;
	}
	long CallOutside(long MediaType, LPCTSTR Calling, LPCTSTR Called)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType, Calling, Called);
		return result;
	}
	long CallInside(LPCTSTR DestAgentID, long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DestAgentID, MediaType);
		return result;
	}
	CString GetPromptByErrorCode(long errcode)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, errcode);
		return result;
	}
	long GetLastErrorCode()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Answer(long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType);
		return result;
	}
	long SendDTMF(LPCTSTR DTMFDigits)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, parms, DTMFDigits);
		return result;
	}
	long SetBusy()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SetIdle()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long Hold()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long RetrieveHold(double CallID)
	{
		long result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CallID);
		return result;
	}
	CString QueryAgentStatus(long QueueID, long IDtype)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, QueueID, IDtype);
		return result;
	}
	CString GetFlowNo()
	{
		CString result;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetCallingNo()
	{
		CString result;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetCalledNo()
	{
		CString result;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long SingleStepTransfer(long MediaType, LPCTSTR TransferNum, long TransferType, LPCTSTR CallingNum)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType, TransferNum, TransferType, CallingNum);
		return result;
	}
	long Transfer(long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType);
		return result;
	}
	long Consultation(long MediaType, LPCTSTR ConsultNum, long ConsultType, long ConsultTag, LPCTSTR CallingNum)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType, ConsultNum, ConsultType, ConsultTag, CallingNum);
		return result;
	}
	long Conference(long CallID)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CallID);
		return result;
	}
	double QueryCallIDOnAgent(LPCTSTR AgentID)
	{
		double result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_R8, (void*)&result, parms, AgentID);
		return result;
	}
	long ReleaseCallByCallID(double CallID)
	{
		long result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CallID);
		return result;
	}
	long NkMessageBox(LPCTSTR TotalName, LPCTSTR MessageTxt)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, TotalName, MessageTxt);
		return result;
	}
	long SetCallData(long MediaType, LPCTSTR CallData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType, CallData);
		return result;
	}
	CString QueryQueueWaitNum(long IDtype, LPCTSTR QueueID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, IDtype, QueueID);
		return result;
	}
	long Listen(LPCTSTR AgentID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID);
		return result;
	}
	long Intercept(LPCTSTR AgentID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID);
		return result;
	}
	long ForceIdle(LPCTSTR AgentID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID);
		return result;
	}
	long ForceBusy(LPCTSTR AgentID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID);
		return result;
	}
	long ForceOut(LPCTSTR AgentID)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID);
		return result;
	}
	long Insert(LPCTSTR AgentID, long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID, MediaType);
		return result;
	}
	long StopInsert(LPCTSTR AgentID, long MediaType)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, parms, AgentID, MediaType);
		return result;
	}
	long SetPreCall()
	{
		long result;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long SingleStepConfCall(LPCTSTR PhoneNum, long CanSpeak)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, PhoneNum, CanSpeak);
		return result;
	}
	long ForceClearByTel(LPCTSTR Tel)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, Tel);
		return result;
	}
	long PandC(LPCTSTR ToneName, LPCTSTR VarPart, LPCTSTR DtmfPara)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ToneName, VarPart, DtmfPara);
		return result;
	}
	long SetPhoneMute(long IsMute)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, IsMute);
		return result;
	}
	double GetCallID(long type)
	{
		double result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, type);
		return result;
	}
	long SetAinfProperty(LPCTSTR pKey, LPCTSTR pValue, LPCTSTR Param)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, pKey, pValue, Param);
		return result;
	}
	long CallOutsideEx(long MediaType, LPCTSTR Calling, LPCTSTR Called, long flag)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, MediaType, Calling, Called, flag);
		return result;
	}
	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

// Properties
//

CString GetAgentID()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}
void SetAgentID(CString propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}
CString GetPassWord()
{
	CString result;
	GetProperty(0x2, VT_BSTR, (void*)&result);
	return result;
}
void SetPassWord(CString propVal)
{
	SetProperty(0x2, VT_BSTR, propVal);
}
CString GetAgentName()
{
	CString result;
	GetProperty(0x3, VT_BSTR, (void*)&result);
	return result;
}
void SetAgentName(CString propVal)
{
	SetProperty(0x3, VT_BSTR, propVal);
}
CString GetDN()
{
	CString result;
	GetProperty(0x4, VT_BSTR, (void*)&result);
	return result;
}
void SetDN(CString propVal)
{
	SetProperty(0x4, VT_BSTR, propVal);
}


};
