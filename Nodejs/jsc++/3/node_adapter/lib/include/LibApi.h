#pragma once
#include <string.h>
#include <string>
#include <windows.h>
#include <process.h> 

using namespace std;
typedef void(*callBackFun)(int icode, std::string strdata);
//��ʼ��
int InitLibSdk();
//����ʼ��
int UnitLibSdk();

int SdkAdd(int a, int b);

int setCallBackFun(callBackFun ptr);