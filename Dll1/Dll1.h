#pragma once

#include <string>
using namespace std;
#ifdef DLL1_EXPORTS
	#define DLL_API __declspec(dllexport)
#else
	#define DLL_API __declspec(dllimport)
#endif // !DLL1_EXPORTS


extern "C" DLL_API int Add(int x, int y);

extern "C" DLL_API string str();

extern "C" DLL_API bool Get_string(char *);

extern "C" DLL_API bool Put_Get_string(char*, char *);


