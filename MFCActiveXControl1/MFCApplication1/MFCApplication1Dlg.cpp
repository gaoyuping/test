
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_MFCACTIVEXCONTROCTRL1, m_actext);
	//DDX_Control(pDX, IDC_NKCALLCTRLCTRL1, m_nkc);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


static CLSID const clsid
= { 0xF1D13F33, 0xD072, 0x4DB9, { 0x85, 0xE4, 0x97, 0xF, 0x73, 0x38, 0x11, 0x16 } };

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int i = m_actext.ac_add(1, 2);
	//i = 100;
}
// #import "C:/gyp/code/github/codetest/trunk/MFCActiveXControl1/Debug/MFCActiveXControl1.ocx" \
// 	named_guids
// using namespace MFCActiveXControl1Lib;
// 


#include "ctest1.h"
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	//test1();


	ctest1 *m_test = new ctest1();
	BOOL ret = m_test->Create(IDD_CTEST1, this);
	m_test->ShowWindow(0);
	m_test->onloadocx();
	m_test->on_add(7, 5);

#if 0
	try{

		_DMFCActiveXControl1 * IkuanATL = NULL;

		HRESULT hr = CoInitialize(NULL);    //��ʼ��COM

		//ʹ��SUCCEEDED�겢��������Ƿ��ܵõ�һ���ӿ�ָ��
		if (SUCCEEDED(hr))
		{
			hr = CoCreateInstance(clsid,
				NULL,
				CLSCTX_INPROC_SERVER,
				IID_DMFCActiveXControl1,
				(void **)&IkuanATL);
			//����ɹ��������AddNumbers������������ʾ��Ӧ�ĳ�����Ϣ
			if (SUCCEEDED(hr))
			{
				long ReturnValue;
				//IkuanATL->ac_add(8, 9);
				//cout << "The answer for 8+9 is:" << ReturnValue << endl;
				IkuanATL->Release();
			}
			else
			{
				//cout << "CoCreateInstance Failed." << endl;
			}
		}
		CoUninitialize();//�ͷ�COM

		CoInitialize(0);
		{
			_DMFCActiveXControl1* pitd = 0;
			HRESULT hr = CoCreateInstance(
				clsid,//Com�����ʶ��
				0,//ָ��ӿ�IUnknownָ��
				CLSCTX_ALL,//���п�ִ�д���������
				IID_DMFCActiveXControl1,//Com����ӿڱ�ʶ��
				reinterpret_cast<void**>(&pitd)//��������ָ��Com����ӿڵ�ַָ����� 
				);

			assert(SUCCEEDED(hr));

			long version = 0;
			//��
			int i = pitd->ac_add(2,6);

			pitd->Release();
		}
		CoUninitialize();
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
#endif
}

bool CMFCApplication1Dlg::test1()
{
// 	BOOL bSucc = false;
// 	TCHAR szMsg[1024] = { 0 };
// 
// 	try
// 	{
// 		// MyCtrl������ȫ�ֵ�CWnd�����
// 		bSucc = m_actext1.CreateControl(
// 			clsid,
// 			(L"CollectData"),
// 			0,
// 			CRect(1, 1, 1, 1),
// 			this,
// 			IDC_MFCACTIVEXCONTROCTRL_TEXT1,
// 			NULL, FALSE, NULL);
// 	}
// 	catch (CMemoryException* e)
// 	{
// 		e->GetErrorMessage(szMsg, 1024);
// 		e->Delete();
// 	}
// 	catch (CFileException* e)
// 	{
// 		e->GetErrorMessage(szMsg, 1024);
// 		e->Delete();
// 	}
// 	catch (CException* e)
// 	{
// 		e->GetErrorMessage(szMsg, 1024);
// 		e->Delete();
// 	}
// 
// 	if (!bSucc)
// 	{
// 		AfxMessageBox(_T("����CollectData.ocx�ؼ�ʧ��\r\n����CollectData.ocx�ؼ��Ƿ�װ��ע��"));
// 		return false;
// 	}
// 
// 	IUnknown *pUnk = m_actext1.GetControlUnknown();
// 	CComQIPtr<_DMFCActiveXControl1> spDCollectDataCtl(pUnk);
// 	if (spDCollectDataCtl == NULL)
// 	{
// 		AfxMessageBox(_T("�޷���CollectData.ocx�л�ȡ_DCollectData�ӿ�"));
// 		return false;
// 	}
// 
// 	int i = spDCollectDataCtl->ac_add(1, 1);
// 	i = 10;
// 	return true;
}
BEGIN_EVENTSINK_MAP(CMFCApplication1Dlg, CDialogEx)
	//ON_EVENT(CMFCApplication1Dlg, IDC_NKCALLCTRLCTRL1, 1, CMFCApplication1Dlg::OnSignInSuccessNkcallctrlctrl1, VTS_I2)
	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL1, 2, CMFCApplication1Dlg::pCallBack1Mfcactivexcontroctrl1, VTS_I4)
	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL1, 3, CMFCApplication1Dlg::psssssMfcactivexcontroctrl1, VTS_I4)


	ON_EVENT(CMFCApplication1Dlg, IDC_MFCACTIVEXCONTROCTRL_TEXT1, 3, CMFCApplication1Dlg::psssssMfcactivexcontroctrl1, VTS_I4)
END_EVENTSINK_MAP()


void CMFCApplication1Dlg::OnSignInSuccessNkcallctrlctrl1(short MediaType)
{
	// TODO:  �ڴ˴������Ϣ����������
}


void CMFCApplication1Dlg::pCallBack1Mfcactivexcontroctrl1(long lfun)
{
	int i = 100;
	// TODO:  �ڴ˴������Ϣ����������
}


void CMFCApplication1Dlg::psssssMfcactivexcontroctrl1(long lsssss)
{
	// TODO:  �ڴ˴������Ϣ����������
}

#include "nkdlg.h"
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	nkdlg *m_test = new nkdlg();
	BOOL ret = m_test->Create(IDD_NKDLG, this);
	m_test->ShowWindow(0);
	m_test->onloadocx();
	m_test->on_add(7, 5);
}
