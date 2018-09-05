#pragma once
#include <string.h>

#include <windows.h>
#include <process.h> 
#include <string>
using namespace std;

typedef void(*callBackFun)(int icode, std::string strdata);
//初始化
int InitLibSdk();
//反初始化
int UnitLibSdk();

int SdkAdd(int a, int b);

int setCallBackFun(callBackFun ptr);