/* 
 * FFplay for MFC
 *
 * ������ Lei Xiaohua
 * leixiaohua1020@126.com
 * �й���ý��ѧ/���ֵ��Ӽ���
 * Communication University of China / Digital TV Technology
 *
 * http://blog.csdn.net/leixiaohua1020
 * 
 * �����̽�ffmpeg��Ŀ�е�ffplay��������ffplay.c����ֲ����VC�Ļ����¡�
 * ����ʹ��MFC����һ�׼򵥵Ľ��档
 * This software transplant ffplay to Microsoft VC++ environment. 
 * And use MFC to build a simple Graphical User Interface. 
 */

#include "stdafx.h"
#include "ffplaymfc.h"
#include "VideodecodeDlg.h"
#include "afxdialogex.h"


// VideodecodeDlg �Ի���

IMPLEMENT_DYNAMIC(VideodecodeDlg, CDialogEx)

VideodecodeDlg::VideodecodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(VideodecodeDlg::IDD, pParent)
{

}

VideodecodeDlg::~VideodecodeDlg()
{
}

void VideodecodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIDEODECODE_LIST, m_videodecodelist);
}


BEGIN_MESSAGE_MAP(VideodecodeDlg, CDialogEx)
	ON_NOTIFY ( NM_CUSTOMDRAW,IDC_VIDEODECODE_LIST, VideodecodeDlg::OnCustomdrawMyList )
END_MESSAGE_MAP()


// VideodecodeDlg ��Ϣ�������
BOOL VideodecodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//����ѡ���б���ߣ���ͷ����������
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE;
	//�����񣻵���ѡ�񣻸�����ʾѡ����

	//�������֧��
	CString resloader;
	resloader.LoadString(IDS_VIDEODECODE);
	SetWindowText(resloader);

	m_videodecodelist.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	m_videodecodelist.SetExtendedStyle(dwExStyle);
	resloader.LoadString(IDS_VIDEODECODE_NUM);
	m_videodecodelist.InsertColumn(0,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_VIDEODECODE_FRAMETYPE);
	m_videodecodelist.InsertColumn(1,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_VIDEODECODE_KEYFRAME);
	m_videodecodelist.InsertColumn(2,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_VIDEODECODE_CODENUM);
	m_videodecodelist.InsertColumn(3,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_VIDEODECODE_PTS);
	m_videodecodelist.InsertColumn(4,resloader,LVCFMT_CENTER,50,0);

	return TRUE;
}

//ListCtrl����ɫ
void VideodecodeDlg::OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult )
{
	//This code based on Michael Dunn's excellent article on
	//list control custom draw at http://www.codeproject.com/listctrl/lvcustomdraw.asp

	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );

	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;

	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.
	if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		// This is the notification message for an item.  We'll request
		// notifications before each subitem's prepaint stage.

		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if ( (CDDS_ITEMPREPAINT | CDDS_SUBITEM) == pLVCD->nmcd.dwDrawStage )
	{

		COLORREF clrNewTextColor, clrNewBkColor;

		int    nItem = static_cast<int>( pLVCD->nmcd.dwItemSpec );

		CString strTemp = m_videodecodelist.GetItemText(nItem,1);
		if(strTemp.Compare(_T("I"))==0){
			clrNewTextColor = RGB(0,0,0);		//Set the text
			clrNewBkColor = RGB(255,0,0);		//�������óɺ�ɫ
		}
		else if(strTemp.Compare(_T("P"))==0){
			clrNewTextColor = RGB(0,0,0);		
			clrNewBkColor = RGB(0,255,255);		//�������ó���ɫ
		}
		else if(strTemp.Compare(_T("B"))==0){
			clrNewTextColor = RGB(0,0,0);		
			clrNewBkColor = RGB(0,255,0);		//�������ó���ɫ
		}else{
			clrNewTextColor = RGB(0,0,0);		
			clrNewBkColor = RGB(255,255,255);
		}

		pLVCD->clrText = clrNewTextColor;
		pLVCD->clrTextBk = clrNewBkColor;


		// Tell Windows to paint the control itself.
		*pResult = CDRF_DODEFAULT;


	}
}