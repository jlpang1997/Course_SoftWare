#pragma once
#include"in_out.h"
//����������������ĺ���
#define MAX_WORD_LEN 50
#define MAX_TOTAL_WORD_NUM 100
#define MAX_CHAIN_LEN 100
#define MAX_CHAIN_COUNT 100

class In_Out
{

public:
	In_Out();

	void in(char *filepath);//���ļ��ж�����

	bool myisalpha(char &ch);//�ж��Ƿ����ַ���������д�ַ�ת��ΪСд

	void print_result();//������������ĸ�����ĵ��������

	void print_result_array();//����ض���Ŀ�ĵ�����

	~In_Out();
public:
	char *words[MAX_TOTAL_WORD_NUM];//��ŵ���
	int  word_num;//��������
	char *result[MAX_CHAIN_LEN];//��ŵ�����
	char *result_array[MAX_CHAIN_COUNT][MAX_CHAIN_LEN];//����ض������ĵ�����
	int chain_count;//������������������-n�ͣ�
};

