#include <napi.h>
#include <node_api.h>
namespace SDKAPI
{

std::string GetData();
Napi::String GetDataWrapped(const Napi::CallbackInfo &info);
int Add(int , int);
Napi::Number AddWrapped(const Napi::CallbackInfo &info);

Napi::Object Init(Napi::Env env, Napi::Object exports);
} // namespace functionexample