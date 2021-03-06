// Dll1.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Dll1.h"
void(*g_callback)(int a, int b) = nullptr;
int add(int a, int b)
{
    ctojs(a, b);
    return a + b;
}

int addSync(int i, int j, void(*callfuct)(int a, int b)) {
    int sum = i + j;
    callfuct(sum, j);
    return 0;
}

int setcallback(void(*callfuct)(int a, int b))
{
    g_callback = callfuct;
    return 1;
}

int ctojs(int i, int j)
{
    if (g_callback)
        g_callback(i,j);
    return 1;
}
