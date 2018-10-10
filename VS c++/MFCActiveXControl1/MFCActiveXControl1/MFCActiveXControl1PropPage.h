#pragma once

// MFCActiveXControl1PropPage.h : CMFCActiveXControl1PropPage 属性页类的声明。


// CMFCActiveXControl1PropPage : 有关实现的信息，请参阅 MFCActiveXControl1PropPage.cpp。

class CMFCActiveXControl1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1PropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1PropPage)

// 构造函数
public:
	CMFCActiveXControl1PropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1 };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

