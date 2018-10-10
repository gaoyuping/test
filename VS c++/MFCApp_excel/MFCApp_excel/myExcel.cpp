#include "stdafx.h"
#include "myExcel.h"
#include "stdafx.h"  
#include <tchar.h>  


COleVariant
covTrue((short)TRUE),
covFalse((short)FALSE),
covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

CApplication myExcel::application;

myExcel::myExcel() :isLoad(false)
{
}


myExcel::~myExcel()
{
	//close();  
}


bool myExcel::initExcel()
{
	//创建Excel 2000服务器(启动Excel)     
	if (!application.CreateDispatch(_T("Excel.application"), nullptr))
	{
		MessageBox(nullptr, _T("创建Excel服务失败,你可能没有安装EXCEL，请检查!"), _T("错误"), MB_OK);
		return FALSE;
	}

	application.put_DisplayAlerts(FALSE);
	return true;
}


void myExcel::release()
{
	application.Quit();
	application.ReleaseDispatch();
	application = nullptr;
}

bool myExcel::open(const char*  fileName)
{

	//先关闭文件  
	close();

	//利用模板建立新文档  
	books.AttachDispatch(application.get_Workbooks(), true);


	LPDISPATCH lpDis = nullptr;
	lpDis = books.Add(COleVariant(CString(fileName)));

	if (lpDis)
	{
		workBook.AttachDispatch(lpDis);

		sheets.AttachDispatch(workBook.get_Worksheets());

		openFileName = fileName;
		return true;
	}

	return false;
}

void myExcel::close(bool ifSave)
{
	//如果文件已经打开，关闭文件  
	if (!openFileName.IsEmpty())
	{
		//如果保存,交给用户控制,让用户自己存，如果自己SAVE，会出现莫名的等待    
		if (ifSave)
		{
			application.Save(COleVariant(openFileName));
		}
		else
		{
			workBook.Close(COleVariant(short(FALSE)), COleVariant(openFileName), covOptional);
			books.Close();
		}

		//清空打开文件名称  
		openFileName.Empty();
	}


	sheets.ReleaseDispatch();
	workSheet.ReleaseDispatch();
	currentRange.ReleaseDispatch();
	workBook.ReleaseDispatch();
	books.ReleaseDispatch();
}

void myExcel::saveAsXLSFile(const CString &xlsFile)
{
	workBook.SaveAs(COleVariant(xlsFile),
		covOptional,
		covOptional,
		covOptional,
		covOptional,
		covOptional,
		0,
		covOptional,
		covOptional,
		covOptional,
		covOptional,
		covOptional);
	return;
}


int myExcel::getSheetCount()
{
	return sheets.get_Count();
}

CString myExcel::getSheetName(long tableID)
{
	CWorksheet sheet;
	sheet.AttachDispatch(sheets.get_Item(COleVariant((long)tableID)));
	CString name = sheet.get_Name();
	sheet.ReleaseDispatch();
	return name;
}


void myExcel::preLoadSheet()
{
	CRange used_range;

	used_range = workSheet.get_UsedRange();


	VARIANT ret_ary = used_range.get_Value2();
	if (!(ret_ary.vt & VT_ARRAY))
	{
		return;
	}
	//    
	safeArray.Clear();
	safeArray.Attach(ret_ary);
}

//按照名称加载sheet表格，也可提前加载所有表格  
bool myExcel::loadSheet(long tableId, bool preLoaded)
{
	LPDISPATCH lpDis = nullptr;
	currentRange.ReleaseDispatch();
	currentRange.ReleaseDispatch();
	lpDis = sheets.get_Item(COleVariant((long)tableId));
	if (lpDis)
	{
		workSheet.AttachDispatch(lpDis, true);
		currentRange.AttachDispatch(workSheet.get_Cells(), true);
	}
	else
	{
		return false;
	}

	isLoad = false;
	//如果进行预先加载    
	if (preLoaded)
	{
		preLoadSheet();
		isLoad = true;
	}

	return true;
}


bool myExcel::loadSheet(CString sheet, bool preLoaded)
{
	LPDISPATCH lpDis = nullptr;
	currentRange.ReleaseDispatch();
	currentRange.ReleaseDispatch();

	lpDis = sheets.get_Item(COleVariant(sheet));
	if (lpDis)
	{
		workSheet.AttachDispatch(lpDis, true);
		currentRange.AttachDispatch(workSheet.get_Cells(), true);
	}
	else
	{
		return false;
	}

	isLoad = false;
	//如果进行预先加载    
	if (preLoaded)
	{
		preLoadSheet();
		isLoad = true;
	}

	return true;
}


int myExcel::getColumnCount()
{
	CRange range;
	CRange usedRange;

	usedRange.AttachDispatch(workSheet.get_UsedRange(), true);
	range.AttachDispatch(usedRange.get_Columns(), true);
	int count = range.get_Count();

	usedRange.ReleaseDispatch();
	range.ReleaseDispatch();

	return count;
}

int myExcel::getRowCount()
{
	CRange range;
	CRange usedRange;

	usedRange.AttachDispatch(workSheet.get_UsedRange(), true);
	range.AttachDispatch(usedRange.get_Rows(), true);

	int count = range.get_Count();

	usedRange.ReleaseDispatch();
	range.ReleaseDispatch();

	return count;
}

bool myExcel::isCellString(long iRow, long iColumn)
{
	CRange range;
	range.AttachDispatch(currentRange.get_Item(COleVariant((long)iRow), COleVariant((long)iColumn)).pdispVal, true);
	COleVariant vResult = range.get_Value2();
	//VT_BSTR标示字符串    
	if (vResult.vt == VT_BSTR)
	{
		return true;
	}
	return false;
}


bool myExcel::isCellInt(long iRow, long iColumn)
{

	CRange range;
	range.AttachDispatch(currentRange.get_Item(COleVariant((long)iRow), COleVariant((long)iColumn)).pdispVal, true);
	COleVariant vResult = range.get_Value2();
	//VT_BSTR标示字符串    
	if (vResult.vt == VT_INT || vResult.vt == VT_R8)
	{
		return true;
	}
	return false;
}

CString myExcel::getCellString(long iRow, long iColumn)
{
	COleVariant vResult;
	CString str;
	//字符串    
	if (isLoad == false)
	{
		CRange range;
		range.AttachDispatch(currentRange.get_Item(COleVariant((long)iRow), COleVariant((long)iColumn)).pdispVal, true);
		vResult = range.get_Value2();
		range.ReleaseDispatch();
	}
	//如果数据依据预先加载了    
	else
	{
		long read_address[2];
		VARIANT val;
		read_address[0] = iRow;
		read_address[1] = iColumn;
		safeArray.GetElement(read_address, &val);
		vResult = val;
	}

	if (vResult.vt == VT_BSTR)
	{
		str = vResult.bstrVal;
	}
	//整数    
	else if (vResult.vt == VT_INT)
	{
		str.Format(_T("%d"), vResult.pintVal);
	}
	//8字节的数字     
	else if (vResult.vt == VT_R8)
	{
		str.Format(_T("%0.0f"), vResult.dblVal);
	}
	//时间格式    
	else if (vResult.vt == VT_DATE)
	{
		SYSTEMTIME st;
		VariantTimeToSystemTime(vResult.date, &st);
		CTime tm(st);
		str = tm.Format(_T("%Y-%m-%d"));

	}
	//单元格空的    
	else if (vResult.vt == VT_EMPTY)
	{
		str = "";
	}

	return str;
}

double myExcel::getCellDouble(long iRow, long iColumn)
{
	double rtn_value = 0;
	COleVariant vresult;
	//字符串    
	if (isLoad == false)
	{
		CRange range;
		range.AttachDispatch(currentRange.get_Item(COleVariant((long)iRow), COleVariant((long)iColumn)).pdispVal, true);
		vresult = range.get_Value2();
		range.ReleaseDispatch();
	}
	//如果数据依据预先加载了    
	else
	{
		long read_address[2];
		VARIANT val;
		read_address[0] = iRow;
		read_address[1] = iColumn;
		safeArray.GetElement(read_address, &val);
		vresult = val;
	}

	if (vresult.vt == VT_R8)
	{
		rtn_value = vresult.dblVal;
	}

	return rtn_value;
}

int myExcel::getCellInt(long iRow, long iColumn)
{
	int num;
	COleVariant vresult;

	if (isLoad == FALSE)
	{
		CRange range;
		range.AttachDispatch(currentRange.get_Item(COleVariant((long)iRow), COleVariant((long)iColumn)).pdispVal, true);
		vresult = range.get_Value2();
		range.ReleaseDispatch();
	}
	else
	{
		long read_address[2];
		VARIANT val;
		read_address[0] = iRow;
		read_address[1] = iColumn;
		safeArray.GetElement(read_address, &val);
		vresult = val;
	}
	//    
	num = static_cast<int>(vresult.dblVal);

	return num;
}

void myExcel::setCellString(long iRow, long iColumn, CString newString)
{
	COleVariant new_value(newString);
	CRange start_range = workSheet.get_Range(COleVariant(_T("A1")), covOptional);
	CRange write_range = start_range.get_Offset(COleVariant((long)iRow - 1), COleVariant((long)iColumn - 1));
	write_range.put_Value2(new_value);
	start_range.ReleaseDispatch();
	write_range.ReleaseDispatch();
}

void myExcel::setCellInt(long iRow, long iColumn, int newInt)
{
	COleVariant new_value((long)newInt);
	CRange start_range = workSheet.get_Range(COleVariant(_T("A1")), covOptional);
	CRange write_range = start_range.get_Offset(COleVariant((long)iRow - 1), COleVariant((long)iColumn - 1));
	write_range.put_Value2(new_value);
	start_range.ReleaseDispatch();
	write_range.ReleaseDispatch();
}


void myExcel::show(bool bShow)
{
	application.put_Visible(bShow);
	application.put_UserControl(bShow);
}

CString myExcel::getOpenFileName()
{
	return openFileName;
}

CString myExcel::getOpenSheelName()
{
	return workSheet.get_Name();
}

char* myExcel::getColumnName(long iColumn)
{
	static char column_name[64];
	size_t str_len = 0;

	while (iColumn > 0)
	{
		int num_data = iColumn % 26;
		iColumn /= 26;
		if (num_data == 0)
		{
			num_data = 26;
			iColumn--;
		}
		column_name[str_len] = (char)((num_data - 1) + 'A');
		str_len++;
	}
	column_name[str_len] = '\0';
	//反转    
	_strrev(column_name);

	return column_name;
}