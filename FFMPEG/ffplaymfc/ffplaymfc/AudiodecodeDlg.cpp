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
#include "AudiodecodeDlg.h"
#include "afxdialogex.h"


// AudiodecodeDlg �Ի���

IMPLEMENT_DYNAMIC(AudiodecodeDlg, CDialogEx)

AudiodecodeDlg::AudiodecodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AudiodecodeDlg::IDD, pParent)
{

}

AudiodecodeDlg::~AudiodecodeDlg()
{
}

void AudiodecodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AUDIODECODE_LIST, m_audiodecodelist);
}


BEGIN_MESSAGE_MAP(AudiodecodeDlg, CDialogEx)

END_MESSAGE_MAP()


BOOL AudiodecodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//����ѡ���б���ߣ���ͷ����������
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE;
	
	//�������֧��
	CString resloader;
	resloader.LoadString(IDS_AUDIODECODE);
	SetWindowText(resloader);
	
	m_audiodecodelist.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	m_audiodecodelist.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_AUDIODECODE_NUM);
	m_audiodecodelist.InsertColumn(0,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_AUDIODECODE_SIZE);
	m_audiodecodelist.InsertColumn(1,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_AUDIODECODE_PTS);
	m_audiodecodelist.InsertColumn(2,resloader,LVCFMT_CENTER,50,0);
	resloader.LoadString(IDS_AUDIODECODE_DTS);
	m_audiodecodelist.InsertColumn(3,resloader,LVCFMT_CENTER,50,0);

	return TRUE;
}




