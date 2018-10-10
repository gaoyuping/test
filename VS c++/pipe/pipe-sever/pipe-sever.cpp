// pipe-sever.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "Pipeserver.h"
using namespace std;


// #define BUF_SIZE 4096
// #define PIPE_SEND   L"\\\\.\\pipe\\sendPipe"
Pipeserver pipeserver;
class callbackpipe : public PipeCallBack
{
public:
    callbackpipe(){};
    ~callbackpipe(){};

    void getdata(std::string strdata)
    {
        cout << "callbackpipe callback get data = " << strdata.c_str() << endl;
        pipeserver.senddata("getdata aaaa");
    };
};

callbackpipe callback;
int _tmain(int argc, _TCHAR* argv[])
{


    pipeserver.initPipe();
    pipeserver.setCallback(&callback);
    pipeserver.waitClientConnect();
    pipeserver.startReveiveThread();
    pipeserver.senddata("ni hao!");

    system("pause");
    pipeserver.UnInitPipe();
	return 0;
}

