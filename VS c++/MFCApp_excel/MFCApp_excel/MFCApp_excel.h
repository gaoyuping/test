
// MFCApp_excel.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApp_excelApp: 
// �йش����ʵ�֣������ MFCApp_excel.cpp
//

class CMFCApp_excelApp : public CWinApp
{
public:
	CMFCApp_excelApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp_excelApp theApp;