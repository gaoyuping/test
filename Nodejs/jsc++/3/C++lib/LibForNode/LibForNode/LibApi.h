#pragma once
#include <string.h>

#include <windows.h>
#include <process.h> 

using namespace std;
typedef void(*callBackFun)(int icode, int strdata);
//��ʼ��
int InitLibSdk();
//����ʼ��
int UnitLibSdk();

int SdkAdd(int a, int b);

int setCallBackFun(callBackFun ptr);