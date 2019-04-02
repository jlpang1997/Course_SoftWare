#pragma once
#include"in_out.h"
//用来管理输入输出的函数
#define MAX_WORD_LEN 50
#define MAX_CHAIN_WORDS 100//单词链最长100
#define MAX_CHAIN_COUNT 10//最多单词链个数
#define MAX_TOTAL_WORD  100//单次数量上限

class In_Out
{

public:
	In_Out();

	void in(char *filepath);

	bool myisalpha(char &ch);

	void print_in();

	void print_result();

	void print_result_array();

	~In_Out();
public:
	char *words[MAX_TOTAL_WORD];//最多一万个单词
	int  word_num;
	char *result[MAX_CHAIN_WORDS];
	char *result_array[MAX_CHAIN_COUNT][MAX_CHAIN_WORDS];
	int chain_count;
};

