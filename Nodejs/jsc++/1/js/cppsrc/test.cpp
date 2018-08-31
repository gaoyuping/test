#include "test.h"


std::string SDKAPI::GetData()
{
    return "Hello World  123";
}

Napi::String SDKAPI::GetDataWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, SDKAPI::GetData());

    return returnValue;
}

int SDKAPI::Add(int a, int b)
{
    return a + b;
}

Napi::Number SDKAPI::AddWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if( info.Length() < 2 || !info[0].IsNumber() ||!info[1].IsNumber())
    {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }
    Napi::Number fisrt = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    int returnValue = SDKAPI::Add(fisrt.Int32Value(), second.Int32Value());

    return Napi::Number::New(env, returnValue);
}




Napi::Object SDKAPI::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        "GetData", Napi::Function::New(env, SDKAPI::GetDataWrapped)
    );
    exports.Set(
        "add", Napi::Function::New(env, SDKAPI::AddWrapped)
    );

    
    return exports;
}