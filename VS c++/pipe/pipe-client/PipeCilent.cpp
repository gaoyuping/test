#include "stdafx.h"
#include "PipeCilent.h"
#include <iostream>
using namespace std;

#define BUF_SIZE 4096
#define PIPE_REVEIVE   L"\\\\.\\pipe\\sendPipe"
#define PIPE_SEND      L"\\\\.\\pipe\\ReceivePipe"

#include <thread>
#include <functional>


void PipeCallBack::getdata(std::string strdata)
{
    cout << "callback get data = " << strdata.c_str() << endl;
};

PipeCilent::PipeCilent()
    :m_hPipeReveive(nullptr)
{
}

PipeCilent::~PipeCilent()
{
    disconnect();
}

void PipeCilent::setCallback(PipeCallBack * ptrCallback)
{
    m_callback = ptrCallback;
}

bool PipeCilent::connectServer()
{
    // �ж��Ƿ��п������õ������ܵ�  
    if (!WaitNamedPipe(PIPE_REVEIVE, NMPWAIT_USE_DEFAULT_WAIT))
    {
        cout << "No Read Pipe Accessible" << endl;
        return 0;
    }

    // �򿪿��õ������ܵ� , ����������˽��̽���ͨ��  
    m_hPipeReveive = CreateFile(PIPE_REVEIVE, GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, 0, NULL);

    if (m_hPipeReveive == INVALID_HANDLE_VALUE)
    {
        cout << "Open Read Pipe Error" << endl;
        return 0;
    }


    // �ж��Ƿ��п������õ������ܵ�  
    if (!WaitNamedPipe(PIPE_SEND, NMPWAIT_USE_DEFAULT_WAIT))
    {
        cout << "No write Pipe Accessible" << endl;
        return 0;
    }

    // �򿪿��õ������ܵ� , ����������˽��̽���ͨ��  
    m_hPipeSend = CreateFile(PIPE_SEND, GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, 0, NULL);

    if (m_hPipeSend == INVALID_HANDLE_VALUE)
    {
        cout << "Open write Pipe Error" << endl;
        return 0;
    }

}

void PipeCilent::disconnect()
{
    if (INVALID_HANDLE_VALUE != m_hPipeReveive && nullptr != m_hPipeReveive)
    {
        CloseHandle(m_hPipeReveive);
        m_hPipeReveive = nullptr;
    }

    if (INVALID_HANDLE_VALUE != m_hPipeSend && nullptr != m_hPipeSend)
    {
        CloseHandle(m_hPipeSend);
        m_hPipeSend = nullptr;
    }
}


bool PipeCilent::startReveiveThread()
{
    if (INVALID_HANDLE_VALUE != m_hPipeReveive && nullptr != m_hPipeReveive)
    {
        std::thread t(std::bind(&PipeCilent::Reveivedata, this));
        t.detach();
        return true;
    }
    return false;
}

void PipeCilent::getdata(std::string strdata)
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


void PipeCilent::Reveivedata()
{
    char  szBuffer[BUF_SIZE] = { 0 };
    DWORD dwReturn = 0;
waitnextdata:
    memset(szBuffer, 0, BUF_SIZE);
    // ��ȡ����˷���������
    if (ReadFile(m_hPipeReveive, szBuffer, BUF_SIZE, &dwReturn, NULL))
    {
        szBuffer[dwReturn] = '\0';
        std::thread t(std::bind(&PipeCilent::getdata, this, std::string(szBuffer)));
        t.detach();
        goto waitnextdata;
    }
    else
    {
        std::thread t(std::bind(&PipeCilent::getdata, this, std::string(szBuffer)));
        t.detach();
    }
}

bool PipeCilent::senddata(std::string strdata)
{
    if (strdata.length() >= BUF_SIZE)
    {
        cout << "msg to long" << endl;
        return false;
    }
    DWORD dwReturn = 0;
    //�����˷�������
    if (!WriteFile(m_hPipeSend, strdata.c_str(), strdata.length(), &dwReturn, NULL))
    {
        cout << "Write Failed" << endl;
        return false;
    }
    return true;
}