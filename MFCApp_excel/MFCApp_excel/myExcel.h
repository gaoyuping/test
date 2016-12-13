#pragma once
#include "CApplication.h"  
#include "CRange.h"  
#include "CWorkbook.h"  
#include "CWorkbooks.h"  
#include "CWorksheet.h"  
#include "CWorksheets.h"  

class myExcel
{
private:
	CString openFileName;
	CWorkbook workBook;//��ǰ�����ļ�  
	CWorkbooks books;//ExcelBook���ϣ����ļ�ʱʹ��  
	CWorksheet workSheet;//��ǰʹ��sheet  
	CWorksheets sheets;//Excel��sheet����  
	CRange currentRange;//��ǰ��������  

	bool isLoad;//�Ƿ��Ѿ�������ĳ��sheet����  

	COleSafeArray safeArray;

protected:
	static CApplication application;//Excel����ʵ��  

public:
	myExcel();
	virtual ~myExcel();



	void show(bool bShow);

	//���һ��cell�Ƿ�Ϊ�ַ���  
	bool isCellString(long iRow, long iColumn);

	//���һ��cell�Ƿ�Ϊ��ֵ  
	bool isCellInt(long iRow, long iColumn);

	//�õ�һ��cell��string  
	CString getCellString(long iRow, long iColumn);

	//�õ�һ��cell������  
	int getCellInt(long iRow, long iColumn);

	//�õ�һ��cell��double����  
	double getCellDouble(long iRow, long iColumn);

	//ȡ���е�����  
	int getRowCount();

	//ȡ���е�����  
	int getColumnCount();

	//ʹ��ĳ��shell  
	bool loadSheet(long tableId, bool preLoaded = false);
	bool loadSheet(CString sheet, bool preLoaded = false);


	//ͨ�����ȡ��ĳ��shell������  
	CString getSheetName(long tableID);

	//�õ�sheel������  
	int getSheetCount();




	//��excel�ļ�  
	bool open(const char* fileName);

	//�رմ򿪵�excel�ļ�  
	void close(bool ifSave = false);

	//���Ϊһ��excel�ļ�  
	void saveAsXLSFile(const CString &xlsFile);

	//ȡ�ô��ļ�������  
	CString getOpenFileName();

	//ȡ�ô�sheel������  
	CString getOpenSheelName();

	//��cell��д��һ��intֵ  
	void setCellInt(long iRow, long iColumn, int newInt);

	//��cell��д��һ���ַ���  
	void setCellString(long iRow, long iColumn, CString newString);


public:
	//��ʼ�� Excel_OLE  
	static bool initExcel();

	//�ͷ�Excel_OLE  
	static void release();

	//ȡ���е�����  
	static char* getColumnName(long iColumn);

protected:
	void preLoadSheet();



};
