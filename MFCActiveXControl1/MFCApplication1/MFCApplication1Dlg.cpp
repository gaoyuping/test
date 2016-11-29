
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



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


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


static CLSID const clsid
= { 0xF1D13F33, 0xD072, 0x4DB9, { 0x85, 0xE4, 0x97, 0xF, 0x73, 0x38, 0x11, 0x16 } };

const IID IID_DMFCActiveXControl1 = { 0x2B846E9F, 0xDF8A, 0x4D99, { 0xB8, 0x9D, 0xA5, 0x32, 0xA6, 0x27, 0x6C, 0xB7 } };
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
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

		HRESULT hr = CoInitialize(NULL);    //初始化COM

		//使用SUCCEEDED宏并检查我们是否能得到一个接口指针
		if (SUCCEEDED(hr))
		{
			hr = CoCreateInstance(clsid,
				NULL,
				CLSCTX_INPROC_SERVER,
				IID_DMFCActiveXControl1,
				(void **)&IkuanATL);
			//如果成功，则调用AddNumbers方法，否则显示相应的出错信息
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
		CoUninitialize();//释放COM

		CoInitialize(0);
		{
			_DMFCActiveXControl1* pitd = 0;
			HRESULT hr = CoCreateInstance(
				clsid,//Com对象标识符
				0,//指向接口IUnknown指针
				CLSCTX_ALL,//运行可执行代码上下文
				IID_DMFCActiveXControl1,//Com对象接口标识符
				reinterpret_cast<void**>(&pitd)//用来接收指向Com对象接口地址指针变量 
				);

			assert(SUCCEEDED(hr));

			long version = 0;
			//★
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
// 		// MyCtrl必须是全局的CWnd类对象
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
// 		AfxMessageBox(_T("创建CollectData.ocx控件失败\r\n请检查CollectData.ocx控件是否安装并注册"));
// 		return false;
// 	}
// 
// 	IUnknown *pUnk = m_actext1.GetControlUnknown();
// 	CComQIPtr<_DMFCActiveXControl1> spDCollectDataCtl(pUnk);
// 	if (spDCollectDataCtl == NULL)
// 	{
// 		AfxMessageBox(_T("无法从CollectData.ocx中获取_DCollectData接口"));
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
	// TODO:  在此处添加消息处理程序代码
}


void CMFCApplication1Dlg::pCallBack1Mfcactivexcontroctrl1(long lfun)
{
	int i = 100;
	// TODO:  在此处添加消息处理程序代码
}


void CMFCApplication1Dlg::psssssMfcactivexcontroctrl1(long lsssss)
{
	// TODO:  在此处添加消息处理程序代码
}

#include "nkdlg.h"
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	nkdlg *m_test = new nkdlg();
	BOOL ret = m_test->Create(IDD_NKDLG, this);
	m_test->ShowWindow(0);
	m_test->onloadocx();
	m_test->on_add(7, 5);
}
