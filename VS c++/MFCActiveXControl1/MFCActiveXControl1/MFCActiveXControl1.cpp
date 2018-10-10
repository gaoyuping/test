// MFCActiveXControl1.cpp : CMFCActiveXControl1App 和 DLL 注册的实现。

#include "stdafx.h"
#include "MFCActiveXControl1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCActiveXControl1App theApp;

const GUID CDECL _tlid = { 0x104B3123, 0x52D3, 0x4E77, { 0x9E, 0x1A, 0x55, 0xF3, 0x62, 0x9F, 0x95, 0x1D } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCActiveXControl1App::InitInstance - DLL 初始化

BOOL CMFCActiveXControl1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMFCActiveXControl1App::ExitInstance - DLL 终止

int CMFCActiveXControl1App::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
