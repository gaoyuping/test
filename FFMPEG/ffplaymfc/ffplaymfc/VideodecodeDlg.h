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

#pragma once


// VideodecodeDlg �Ի���

class VideodecodeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VideodecodeDlg)

public:
	VideodecodeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~VideodecodeDlg();

// �Ի�������
	enum { IDD = IDD_VIDEODECODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_videodecodelist;

	void OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult );
};
