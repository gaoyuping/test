#pragma once

// MFCActiveXControl1PropPage.h : CMFCActiveXControl1PropPage ����ҳ���������


// CMFCActiveXControl1PropPage : �й�ʵ�ֵ���Ϣ������� MFCActiveXControl1PropPage.cpp��

class CMFCActiveXControl1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1PropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1PropPage)

// ���캯��
public:
	CMFCActiveXControl1PropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1 };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

