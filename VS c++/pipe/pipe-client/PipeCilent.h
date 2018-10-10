#pragma once
#include <string>
class PipeCallBack
{
public:
    PipeCallBack(){};
    virtual ~PipeCallBack(){};

    virtual void getdata(std::string strdata);
};

class PipeCilent
{
public:
    PipeCilent();
    virtual ~PipeCilent();

    void setCallback(PipeCallBack * ptrCallback);
    bool connectServer();
    void disconnect();
    bool startReveiveThread();
    bool senddata(std::string strdata);
private:
    void getdata(std::string strdata);
    void Reveivedata();
private:
    PipeCallBack *m_callback;
    HANDLE m_hPipeReveive;
    HANDLE m_hPipeSend;


};

