#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
extern "C"//����һ��dll����
{

		_declspec(dllexport)
		void  Wordlist_func(
			char *filepath,
			int Nword,
			char start_ch,
			char end_ch,
			bool longest_word,
			bool longest_letter,//����
			char *out_meg
		);

}