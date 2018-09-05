#include <nan.h>
#include <string>
#include <iostream>
#include "LibApi.h"

using namespace v8;
using namespace std;

#pragma comment(lib,"LibForNode.lib")

void callbackfromc(int icode, std::string strdata);
static int g_int = 0;
static void node_event_process(uv_async_t *handle);
struct t_asycn
{
    string strdata;
    Local<Function> cb;
};

class CallbackImpl
{
    uv_async_t uv_async;
    Local<Function> cb;
public:
    CallbackImpl(const Nan::FunctionCallbackInfo<v8::Value>& info) {
		uv_async_init(uv_default_loop(), &uv_async, node_event_process);
        InitLibSdk();
	}

    void setCb(Local<Function> cb_)
    {
        setCallBackFun(callbackfromc);
		cb = cb_;
    }
    inline Local<Function> getCb(){return  cb;};
//调用 异步
    void async_to_js(string str)
    {
        t_asycn * tmp = new t_asycn();
        tmp->cb = cb;
        tmp->strdata = str;
        uv_async.data = tmp;
        uv_async_send(&uv_async);
    }
//调用 同步
    void sync_to_js(string str)
    {
        //uv_async.data = (char*)str.c_str();
        t_asycn * tmp = new t_asycn();
        tmp->cb = cb;
        tmp->strdata = "ssssssssfffffffffffff";
        //setfun((char*)str.c_str());
        //uv_async.data = (char*)str.c_str();
        uv_async.data = tmp;

        //node_event_to_process(&uv_async);
    }
};

// 适配器类 存储 回调函数和C++lib 指针
class AdapterImp
{
    CallbackImpl *callback = nullptr;
    
    public:
    inline CallbackImpl * getCallBack() { return callback;};
    void setCallBack(const Nan::FunctionCallbackInfo<v8::Value>& info)
    {
        callback = new CallbackImpl(info);
    };

    bool getCallBackfuncb() { return callback->getCb().IsEmpty();};
    void setCallBackfuncb(Local<Function> cb_)
    {
        callback->setCb(cb_);
    };

    void setTemp1(std::string strdata)
    {
        if (callback)
            callback->async_to_js(strdata);
        //callbakcfun->sync_to_js("sync send to js  data");
    };

};
//全局 变量
AdapterImp *g_Adapter = new AdapterImp();
static void node_event_process(uv_async_t *handle){
#if 0
        string p;
		        p = "SDK_callback(\"calltest\")";
        Isolate* isolatejs = Isolate::GetCurrent();
                Nan::MaybeLocal<Nan::BoundScript> script = Nan::CompileScript(v8::String::NewFromUtf8(isolatejs, p.c_str()));
                Nan::RunScript(script.ToLocalChecked());
                return;
#else
        std::cout << ("node_event_process ") << g_int++ << std::endl;
        t_asycn* funData = (t_asycn*)handle->data;
        //const unsigned argc = 1;
        Isolate* isolate = Isolate::GetCurrent();
        HandleScope handle_scope(isolate);
        //Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
        Handle<Value> argv[1];
        argv[0] = Nan::New<String>("sssssssssssssssssffffffffffffffffffssss").ToLocalChecked();// data
        //if (!funData->cb.IsEmpty())
        {
            try
            {
                std::cout << ("node_event_process callback ") << g_int++ << std::endl;
                funData->cb->Call(Null(isolate), 1, argv);
            }
            catch(...)
            {
                std::cout << ("node_event_process callback error ") << g_int++ << std::endl;
                 string p;
		        p = "SDK_callback(\""+funData->strdata+"\")";
                Isolate* isolatejs = Isolate::GetCurrent();
                Nan::MaybeLocal<Nan::BoundScript> script = Nan::CompileScript(v8::String::NewFromUtf8(isolatejs, p.c_str()));
                Nan::RunScript(script.ToLocalChecked());
                return;
            }
        }
#endif
};

v8::Local<v8::String> GetCallBackJSon(int iCode, string strdata)
{
    string strret = "{\"state\",";
    strret.append(to_string(iCode));
    strret.append(";\"msg\",\"");
    strret.append(strdata);
    strret.append("\"}");
    return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), strret.c_str());
}

void InitSDK(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	if (g_Adapter->getCallBack() == nullptr) {
		g_Adapter->setCallBack(info);
	}
}

void SetData(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    std::cout << ("SetData 1  ") << g_int++ << std::endl;
    if (g_Adapter->getCallBack() != nullptr) {
        if(info.Length() < 2)
        {
            //Nan::ThrowTypeError("Wrong Number of Arguments");
            v8::Local<v8::String> ret = GetCallBackJSon(-2, "Wrong Number of Arguments");
            info.GetReturnValue().Set(ret);
            return;
        }

        //g_Adapter->setTemp();

	}
    int arg0 = info[0]->NumberValue();
    int arg1 = info[1]->NumberValue();
    int sdkret = SdkAdd(arg0, arg1);
    std::cout << ("SetData 2  ") << g_int++ << std::endl;
    v8::Local<v8::String> ret = GetCallBackJSon(sdkret, "OK");
	info.GetReturnValue().Set(ret);
    std::cout << ("SetData 3  ") << g_int++ << std::endl;
}

void SetCallBackFun(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    std::cout << ("SetCallBackFun ") << g_int++ << std::endl;
    if (g_Adapter->getCallBackfuncb() == true) {
        Local<Function> cb = Local<Function>::Cast(info[0]);
        Isolate* isolate = Isolate::GetCurrent();
        //Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
        Local<Value> argv[1];
        argv[0] = Nan::New<String>("sssssssbbbbbbbbbbbbbbbsssss").ToLocalChecked();// data
        if (!cb.IsEmpty())
        {
            cb->Call(Null(isolate), 1, argv);
            cb->Call(Null(isolate), 1, argv);
            cb->Call(Null(isolate), 1, argv);
            cb->Call(Null(isolate), 1, argv);
            cb->Call(Null(isolate), 1, argv);
            cb->Call(Null(isolate), 1, argv);
        }
        v8::Local<v8::String> ret = GetCallBackJSon(0, "set callback OK");
        g_Adapter->setCallBackfuncb(cb);
	    info.GetReturnValue().Set(ret);
    return;
    }
    v8::Local<v8::String> ret = GetCallBackJSon(-1, "Failed");
	info.GetReturnValue().Set(ret);
}


void GetetData(const Nan::FunctionCallbackInfo<v8::Value>& info) {

}

void UnitSDK(const Nan::FunctionCallbackInfo<v8::Value>& info) {

}

void Init(v8::Local<v8::Object> exports) {
	exports->Set(Nan::New("InitSDK").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(InitSDK)->GetFunction());
    exports->Set(Nan::New("SetData").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(SetData)->GetFunction());
    exports->Set(Nan::New("SetCallBackFun").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(SetCallBackFun)->GetFunction());
    exports->Set(Nan::New("GetetData").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(GetetData)->GetFunction());
    exports->Set(Nan::New("UnitSDK").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(UnitSDK)->GetFunction());
}

NODE_MODULE(demo, Init)







void callbackfromc(int icode, std::string strdata)
{
    std::cout << ("callback from c ") << g_int++ << std::endl;
    if (g_Adapter->getCallBack() != nullptr) {
		std::cout << ("callback from c 11111") << g_int++ << std::endl;
        g_Adapter->setTemp1(strdata);
	}
}