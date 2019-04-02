#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
extern "C"//声明一个dll函数
{

		_declspec(dllexport)
		void  Wordlist_func(
			char *filepath,
			int Nword,
			char start_ch,
			char end_ch,
			bool longest_word,
			bool longest_letter,//输入
			char *out_meg
		);

}