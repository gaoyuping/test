#include "stdafx.h"
#include "Pipeserver.h"
#include <thread>
#include <functional>

#define BUF_SIZE 4096
#define PIPE_SEND      L"\\\\.\\pipe\\sendPipe"
#define PIPE_RECEIVE   L"\\\\.\\pipe\\ReceivePipe"




void PipeCallBack::getdata(std::string strdata)
{ 
    cout << "callback get data = "<<strdata.c_str() << endl; 
};

Pipeserver::Pipeserver()
    : m_hPipeSend(nullptr)
    , m_hPipeReceive(nullptr)
{
}

Pipeserver::~Pipeserver()
{
    UnInitPipe();
}

void Pipeserver::setCallback(PipeCallBack * ptrCallback)
{
    m_callback = ptrCallback;
}

bool Pipeserver::initPipe()
{
    UnInitPipe();

    m_hPipeSend = CreateNamedPipe(
        PIPE_SEND,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE |
        PIPE_READMODE_MESSAGE |
        PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES,
        BUF_SIZE,
        BUF_SIZE,
        0,
        NULL);

    if (m_hPipeSend == INVALID_HANDLE_VALUE)
    {
        cout << "Create write Pipe Error" << endl;
        return FALSE;
    }

    m_hPipeReceive = CreateNamedPipe(
        PIPE_RECEIVE,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE |
        PIPE_READMODE_MESSAGE |
        PIPE_WAIT,
        PIPE_UNLIMITED_INSTANCES,
        BUF_SIZE,
        BUF_SIZE,
        0,
        NULL);

    if (m_hPipeReceive == INVALID_HANDLE_VALUE)
    {
        cout << "Create Read Pipe Error" << endl;
        return FALSE;
    }
}

bool Pipeserver::waitClientConnect()
{
    // 等待客户端的连接 
    SetLastError(0);
    if (!ConnectNamedPipe(m_hPipeSend, nullptr))
    {
        if (ERROR_PIPE_CONNECTED == GetLastError())
        {
            SetLastError(0);
            goto nextwait;
        }
        cout << "Connect PipeSend Failed" << endl;
        return FALSE;
    }

nextwait:
    if (!ConnectNamedPipe(m_hPipeReceive, nullptr))
    {
        if (ERROR_PIPE_CONNECTED == GetLastError())
        {
            return true;
        }
        cout << "Connect PipeReceive Failed" << endl;
        return FALSE;
    }
    return true;
}

bool Pipeserver::startReveiveThread()
{
    if (INVALID_HANDLE_VALUE != m_hPipeReceive && nullptr != m_hPipeReceive)
    {
        std::thread t(std::bind(&Pipeserver::Reveivedata, this));
        t.detach();
        return true;
    }
    return false;
}
void Pipeserver::UnInitPipe()
{
    if (INVALID_HANDLE_VALUE != m_hPipeSend && nullptr != m_hPipeSend)
    {
        DisconnectNamedPipe(m_hPipeSend);
        CloseHandle(m_hPipeSend);
        m_hPipeSend = nullptr;
    }
    if (INVALID_HANDLE_VALUE != m_hPipeReceive && nullptr != m_hPipeReceive)
    {
        DisconnectNamedPipe(m_hPipeReceive);
        CloseHandle(m_hPipeReceive);
        m_hPipeReceive = nullptr;
    }
}

bool Pipeserver::senddata(std::string strdata)
{
    if (strdata.length() >= BUF_SIZE)
    {
        cout << "msg to long" << endl;
        return false;
    }
    if (INVALID_HANDLE_VALUE != m_hPipeSend && nullptr != m_hPipeSend)
    {
        DWORD dwReturn = 0;
        // 向客户端发送数据
        if (!WriteFile(m_hPipeSend, strdata.c_str(), strdata.length(), &dwReturn, NULL))
        {
            return false;
        }
        return true;
    }
    return false;
    
}
void Pipeserver::getdata(std::string strdata)
{
    if (m_callback)
    {
        m_callback->getdata(strdata);
    }
    else
    {
        //do nothing
    }
}

void Pipeserver::Reveivedata()
{
    // 读取客户端数据 线程中读取
    char  szBuffer[BUF_SIZE] = { 0 };
    DWORD dwReturn = 0;
waitnextdata:

    memset(szBuffer, 0, BUF_SIZE);
    if (ReadFile(m_hPipeReceive, szBuffer, BUF_SIZE, &dwReturn, NULL))
    {
        szBuffer[dwReturn] = '\0';
        cout << szBuffer << endl;
        std::thread t(std::bind(&Pipeserver::getdata, this, std::string(szBuffer)));
        t.detach();
        goto waitnextdata;
    }
    else
    {
        std::thread t(std::bind(&Pipeserver::getdata, this, std::string(szBuffer)));
        t.detach();
    }
}