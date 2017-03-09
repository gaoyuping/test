// input.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << "分割数据，求最大值最小值，输入格式 xx,xx,xx    q退出" << std::endl;
    std::string str;
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;

    int i1max = 0;
    int i2max = 0;
    int i3max = 0;

    int i1min = 0;
    int i2min = 0;
    int i3min = 0;

    while (true)
    {
        std::cout << "Input data" << std::endl;
        std::getline(std::cin, str);
        if (str.length() < 0 || 0 == str.compare("q"))
        {
            break;
        }
        char *p;
        const char *sep = ",";
        p = strtok((char*)str.c_str(), sep);
        if (p)
        {
            i1 = std::stoi(p);
        }
        else
        {
            std::cout << "Invalid data" << std::endl;
            continue;
        }
        p = strtok(NULL, sep);
        if (p)
        {
            i2 = std::stoi(p);
        }
        else
        {
            std::cout << "Invalid data" << std::endl;
            continue;
        }
        p = strtok(NULL, sep);
        if (p)
        {
            i3 = std::stoi(p);
        }
        else
        {
            std::cout << "Invalid data" << std::endl;
            continue;
        }
        i1max = i1max > i1 ? i1max : i1;
        i2max = i2max > i2 ? i2max : i2;
        i3max = i3max > i3 ? i3max : i3;

        i1min = i1min < i1 ? i1min : i1;
        i2min = i2min < i2 ? i2min : i2;
        i3min = i3min < i3 ? i3min : i3;
    }
    std::cout << "xMin:" << i1min << "     xMax:" << i1max << std::endl;
    std::cout << "yMin:" << i2min << "     yMax:" << i2max << std::endl;
    std::cout << "zMin:" << i3min << "     zMax:" << i3max << std::endl;
    system("pause");
	return 0;
}

