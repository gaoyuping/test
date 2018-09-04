#include "stdafx.h"
#include "LibApi.h"
#include <windows.h>
#include <process.h> 
#include <iostream>

static int g_int = 0;
callBackFun g_callBackFun = nullptr;

static DWORD WINAPI TimerThread(LPVOID lpParameter)
{
    UINT oldTickCount, newTickCount;
    oldTickCount = GetTickCount();
    while (TRUE)
    {
        while (TRUE)
        {
            newTickCount = GetTickCount();
            if (newTickCount - oldTickCount >= 2000)
            {
                oldTickCount = newTickCount;
                break;
            }
            else
                SwitchToThread();
        }
        // 60毫秒自动调用函数
        std::cout << ("ssssssssssssssss") << std::endl;
        if (g_callBackFun)
        {
            g_callBackFun(g_int++, g_int++);
        }
        
    }
    return 1;          // the thread exit code
}

int InitLibSdk()
{
    HANDLE   hth1;
    unsigned  uiThread1ID;

    HANDLE hThread = CreateThread(NULL, 0, TimerThread, 0, 0, NULL);
    return 1;
}

int UnitLibSdk()
{
    g_callBackFun = nullptr;
    return 1;
}


int SdkAdd(int a, int b)
{
    if (g_callBackFun != nullptr)
    {
        g_callBackFun(a+b, a*b);
    }
    return a + b;
}

int setCallBackFun(callBackFun ptr)
{
    g_callBackFun = ptr;
}