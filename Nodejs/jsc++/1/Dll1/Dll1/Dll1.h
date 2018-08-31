#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    __declspec(dllexport) int add(int a, int b);
    __declspec(dllexport) int addSync(int i, int j, void(*callfuct)(int a, int b));
    __declspec(dllexport) int setcallback(void(*callfuct)(int a, int b));
    int ctojs(int i, int j);
#ifdef __cplusplus
}
#endif