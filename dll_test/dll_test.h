#pragma once


#ifdef DLLTEST_EXPORTS
	#define DLLEXAM_API __declspec(dllexport)
#else
	#define DLLEXAM_API __declspec(dllimport)
#endif

DLLEXAM_API int add(int, int);

