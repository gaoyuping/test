#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

class PipeCallBack
{
public:
    PipeCallBack(){};
    virtual ~PipeCallBack(){};

    // 注意 strdata 为空的时候 说明管道出异常 需要做处理(重启管道或者)
    virtual void getdata(std::string strdata);
};
class Pipeserver
{
public:
    Pipeserver();
    virtual ~Pipeserver();
    void setCallback(PipeCallBack * ptrCallback);
    bool initPipe();
    bool waitClientConnect();
    bool startReveiveThread();
    void UnInitPipe();
    bool senddata(std::string strdata);
private:
    void getdata(std::string strdata);
    void Reveivedata();
private:
    PipeCallBack *m_callback;
    HANDLE m_hPipeSend;
    HANDLE m_hPipeReceive;
};

