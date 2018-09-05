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
        std::cout << ("TimerThread  ") << g_int << std::endl;
        if (g_callBackFun)
        {
            std::cout << ("TimerThread callback time  ") << g_int << std::endl;
            g_callBackFun(g_int++, "g_int++");
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
    try
    {
        std::cout << ("SdkAdd callback ") << g_int++ << std::endl;
        if (g_callBackFun != nullptr)
        {
            std::cout << ("SdkAdd callback 1, ") << g_int++ << std::endl;
            g_callBackFun(a + b, "a + b");
            std::cout << ("SdkAdd callback 2, ") << g_int++ << std::endl;
        }
        return 1;
        //return (a + b);
        std::cout << ("SdkAdd callback 3, ") << g_int++ << std::endl;
    }
    catch (const std::exception&)
    {
        return -1;
    }
}

int setCallBackFun(callBackFun ptr)
{
    g_callBackFun = ptr;
    return 1;
}