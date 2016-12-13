
// MFCApp_excelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApp_excel.h"
#include "MFCApp_excelDlg.h"
#include "afxdialogex.h"
#include "myExcel.h"


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


// CMFCApp_excelDlg 对话框



CMFCApp_excelDlg::CMFCApp_excelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApp_excelDlg::IDD, pParent)
	, m_minlen(0)
	, m_filename(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp_excelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_minlen);
	DDV_MinMaxInt(pDX, m_minlen, 4, 50);
	DDX_Text(pDX, IDC_EDIT2, m_filename);
}

BEGIN_MESSAGE_MAP(CMFCApp_excelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApp_excelDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApp_excelDlg 消息处理程序

BOOL CMFCApp_excelDlg::OnInitDialog()
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

void CMFCApp_excelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApp_excelDlg::OnPaint()
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
HCURSOR CMFCApp_excelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int    unicode_to_utf8(const wchar_t *src, size_t src_len, char *des, size_t des_len)
{
	if (NULL == src || NULL == des)
	{
		return -1;
	}
	int nLen = WideCharToMultiByte(CP_ACP, 0, src, -1, NULL, 0, NULL, NULL);
	if (nLen <= 0)
	{
		des[0] = 0;
		return -1;
	}
	if (des_len < nLen)
	{
		des[0] = 0;
		return -1;
	}
	int len = WideCharToMultiByte(CP_ACP, 0, src, -1, des, nLen, NULL, NULL);
	des[nLen - 1] = 0;
	return len;
};
int    unicode_to_utf8(const std::wstring& src, std::string& des)
{
	const wchar_t* _Source = src.c_str();
	size_t pdessize = 2 * src.size() + 1;
	char * pdes = new char[pdessize];
	unicode_to_utf8(_Source, src.length(), pdes, pdessize);
	des = pdes;
	delete[]pdes;
	return 0;
};
std::string unicode_to_utf8(const std::wstring& src)
{
	std::string result;
	unicode_to_utf8(src, result);
	return result;
};
void CMFCApp_excelDlg::OnBnClickedButton1()
{
// 	clock_t tmemset1;
// 	clock_t tmemset2;
// 	tmemset1 = clock();
// 	bool bret = findstring(L"为优奖刘维桢事致端方电报", L"为办理火车货捐事自开封致端方电报", 5);
// 	tmemset2 = clock();
// 	int i = tmemset2 - tmemset1;
// 	i = 100;
// 	std::string ss = "asdfa";
// 	return;
	UpdateData(TRUE);
	m_minlen;
	m_filename;
	std::wstring str = m_filename.GetBuffer(0);
	if (m_minlen < 4 || str.length() < 1)
	{
		return;
	}
	myExcel excl;
	bool bInit = excl.initExcel();
	char path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, path);//获取当前工作目录  

	strcat_s(path, "\\");
	strcat_s(path, unicode_to_utf8(m_filename.GetBuffer(0)).c_str());//设置要打开文件的完整路径  

// 	memset(path, 0x00, _countof(path));
// 	memcpy_s(path, _countof(path), "c:\\11.xls", _countof("c:\\11.xls"));
	bool bRet = excl.open(path);//打开excel文件  

	CString strSheetName = excl.getSheetName(1);//获取sheet名  
	bool bLoad = excl.loadSheet(strSheetName);//装载sheet  
	int nRow = excl.getRowCount();//获取sheet中行数  
	int nCol = excl.getColumnCount();//获取sheet中列数  

	m_a.clear();
	m_b.clear();
	CString cell;
	for (int i = 2; i <= nRow; ++i)
	{
		cell = excl.getCellString(i, 1);
		m_a.push_back(cell.GetBuffer(0));
	}

	strSheetName = excl.getSheetName(2);//获取sheet名  
	bLoad = excl.loadSheet(strSheetName);//装载sheet  
	nRow = excl.getRowCount();//获取sheet中行数  
	nCol = excl.getColumnCount();//获取sheet中列数  

	for (int i = 2; i <= nRow; ++i)
	{
		cell = excl.getCellString(i, 1);
		m_b.push_back(cell.GetBuffer(0));
	}


	strSheetName = excl.getSheetName(1);//获取sheet名  
	bLoad = excl.loadSheet(strSheetName);//装载sheet  
	for (int i = 0; i < m_a.size(); i++)
	{
		 	clock_t tmemset1;
		 	clock_t tmemset2;
		 	tmemset1 = clock();
		for (int j = 0; j < m_b.size(); j++)
		{
			bool bret = findstring(m_a[i], m_b[j], m_minlen);
			if (bret)
			{
				for (int ij = 2; ij < 100;  ij++)
				{
					if ("" == excl.getCellString(i + 1, ij))
					{
						excl.setCellString(i + 1, ij, m_b[j].c_str());
						break;
					}
				}
				
			}
		}

		tmemset2 = clock();
		int i = tmemset2 - tmemset1;
		std::string ss = "asdfa";
	}
end1:;
	excl.close(true);
	excl.release();
}


bool CMFCApp_excelDlg::findstring(std::wstring strfirst, std::wstring strend, int minlen)
{
	std::wstring str_zc;
	//从最大字符串开始查找
	for (int i = strfirst.length(); i >= minlen; i -- )
	{
		//从0位置开始查找 子串
		for (int i_zc_begin = 0; i_zc_begin <= strfirst.length() - minlen; i_zc_begin++)
		{
			str_zc = strfirst.substr(i_zc_begin, i);// (strfirst, )
			if (i != str_zc.length())
			{
				break;
			}
			int iiii = strend.find(str_zc);
			if (-1 != strend.find(str_zc))
			{
				//找到
				return true;
			}
		}
	}
	return FALSE;
}