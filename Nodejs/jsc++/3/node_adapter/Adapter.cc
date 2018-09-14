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
struct t_asycndata
{
    string strdata;
};

struct ShareData
{
    bool binit = false;
    Isolate * isolate;
    v8::Persistent<v8::Function> callback;
    uv_async_t uv_async;
};

ShareData *CallbackInfoptr = NULL;

//全局 变量
static void node_event_process(uv_async_t *handle){
    t_asycndata* funData = (t_asycndata*)handle->data;
    Isolate* isolate = CallbackInfoptr->isolate;
    v8::HandleScope handle_scope(isolate);
    const unsigned argc = 1;
    v8::Local<v8::Value> argv[argc] = { Nan::New<String>(funData->strdata).ToLocalChecked()};
    delete funData;
    std::cout << "node_event_process callback function data 1  1..............................................................................................."<< std::endl;
    Local<Function> cb = Local<Function>::New(isolate, CallbackInfoptr->callback);
    std::cout << "node_event_process callback function data 1  2..............................................................................................."<< std::endl;
    cb->Call(Null(isolate), argc, argv);
    std::cout << "node_event_process callback function data 1  3..............................................................................................."<< std::endl;
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
    InitLibSdk();
    info.GetReturnValue().Set(Nan::New<String>("Sdk Init Ok").ToLocalChecked());
}

void SetData(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    std::cout << ("Adapter  SetData 1  ") << g_int++ << std::endl;
    if (CallbackInfoptr != nullptr) {
        if(info.Length() < 2)
        {
            //Nan::ThrowTypeError("Wrong Number of Arguments");
            v8::Local<v8::String> ret = GetCallBackJSon(-2, "Wrong Number of Arguments");
            info.GetReturnValue().Set(ret);
            return;
        }

        double arg0 = info[0]->NumberValue();
        double arg1 = info[1]->NumberValue();
        int sdkret = SdkAdd(arg0, arg1);
        std::cout << ("Adapter  SetData 2  ") << g_int++ << std::endl;
        v8::Local<v8::String> ret = GetCallBackJSon(sdkret, "OK");
        info.GetReturnValue().Set(ret);
        std::cout << ("Adapter  SetData 3  ") << g_int++ << std::endl;
        return;
	}
    else
    {
        v8::Local<v8::String> ret = GetCallBackJSon(-1, "sdk need Init");
	    info.GetReturnValue().Set(ret);
    }
}

void SetCallBackFun(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    std::cout << ("Adapter SetCallBackFun 1............") << g_int++ << std::endl;
    if (CallbackInfoptr == nullptr) {
        std::cout << ("Adapter SetCallBackFun 2............") << g_int++ << std::endl;
		Isolate* isolate = info.GetIsolate();
		v8::Local<v8::Function> callback = v8::Local<v8::Function>::Cast(info[0]);
        std::cout << ("Adapter SetCallBackFun 3............") << g_int++ << std::endl;
		CallbackInfoptr = new ShareData();
		CallbackInfoptr->isolate = isolate;
        std::cout << ("Adapter SetCallBackFun 4............") << g_int++ << std::endl;
        uv_async_init(uv_default_loop(), &(CallbackInfoptr->uv_async), node_event_process);
	    /* 存储回调函数 */
        std::cout << ("Adapter SetCallBackFun 5............") << g_int++ << std::endl;
	    CallbackInfoptr->callback.Reset(isolate, callback);
        std::cout << ("Adapter SetCallBackFun 6............") << g_int++ << std::endl;
        setCallBackFun(callbackfromc);
        v8::Local<v8::String> ret = GetCallBackJSon(-1, "setCalback Ok");
	    info.GetReturnValue().Set(ret);
        return;
    }
    std::cout << ("Adapter SetCallBackFun 7............") << g_int++ << std::endl;
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
    std::cout << ("Adapter  callback from c ") << g_int++ << std::endl;
    if (CallbackInfoptr != nullptr) {
		std::cout << ("Adapter  callback from c 11111") << g_int++ << std::endl;
        t_asycndata *data = new t_asycndata();
        data->strdata = strdata;
        CallbackInfoptr->uv_async.data = data;
        uv_async_send(&(CallbackInfoptr->uv_async));
	}
}