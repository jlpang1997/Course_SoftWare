#pragma once
#include"in_out.h"
//����������������ĺ���
#define MAX_WORD_LEN 50
#define MAX_CHAIN_WORDS 100//�������100
#define MAX_CHAIN_COUNT 10//��൥��������
#define MAX_TOTAL_WORD  100//������������

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
	char *words[MAX_TOTAL_WORD];//���һ�������
	int  word_num;
	char *result[MAX_CHAIN_WORDS];
	char *result_array[MAX_CHAIN_COUNT][MAX_CHAIN_WORDS];
	int chain_count;
};

