#include"main.h"
#include<iostream>
#include <stdio.h>
#include "word_graph.h"
#include <string.h>
#include<string>
using namespace std;

bool first_run = true;
char former_filepath[100];

void   Wordlist_func(
	char *filepath,
	int Nword,
	char start_ch,
	char end_ch,
	bool longest_word,
	bool longest_letter,
	char *out_meg)//����)
{



	int len = strlen(filepath);
	if (strcmp(filepath+len-3, "txt"))
	{
		strcpy(out_meg,error(7));
		return;
	}

	if (start_ch!='\0'&&myisalpha(start_ch) == false)
	{
		strcpy(out_meg, error(8));
		return;
	}

	if (end_ch!='\0'&&myisalpha(end_ch) == false)
	{
		strcpy(out_meg, error(8));
		return;
	}

	if (Nword != 0 && longest_letter )
	{
		strcpy(out_meg, error(1));
		return;
	}

	for (int i = 0; i < strlen(filepath); i++)
	{
		if(filepath[i]=='\\' )
			filepath[i]='/';
	}//Ĭ���û���'\'���ָ�

	if (first_run == true)
	{
		Create(filepath,out_meg);
		strcpy(former_filepath, filepath);
		first_run = false;
	}
	if (!first_run)
	{
		if (strcmp(filepath, former_filepath) != 0)//����ǰ��·����һ��
		{
			free_graph();//��֮ǰ���ͷŵ�
			Create(filepath,out_meg);
			strcpy(former_filepath, filepath);
		}
	}
	
	if (out_meg[0])//��ͼʱ���ļ�ʧ��
	{
		return;
	}
	DFS(Nword,start_ch,end_ch,longest_word,longest_letter,out_meg);


	if (Nword == 0&&max_wordcount == 0&&max_lettercount==0)
	{
		if (myisalpha(start_ch) && myisalpha(end_ch))
		{
			sprintf(out_meg, "there is no wordlist that starts with %c and  ends with %c at the same time.\n", start_ch, end_ch);
			//printf("there is no wordlist that starts with %c and there is no wordlist that ends with %c.\n", start_ch, end_ch);
			return;
		}
		
		if (myisalpha(start_ch))
		{
			sprintf(out_meg,"there is no wordlist that starts with %c.\n", start_ch);
			return ;
		}
		if (myisalpha(end_ch))
		{
			sprintf(out_meg,"there is no wordlist that ends with %c.\n", end_ch);
			return ;
		}
			sprintf(out_meg,"the length of the list is only 1.\n");
			return ;
	}


}
/*
	1,������ı����ȹرտ���̨���������ܣ�����
	2,ÿһ�ζ����ҼǵðѶ�̬������ڴ��ͷŵ����Բ�
	3,�õ�realloc�ĺ�������������ֵ
	4,����DFS�ĳ�ʼ������û���ã�����malloc�������һ���һЩ
    �ܵײ�Ĵ�������ÿ�ζ�Ҫ���ó�ʼ�����Լ��ڴ���չ�����
    5,������һ���ַ��ǻ��У������ͽ�����ѭ����


	GUI����������ӿ��У�
	���룺�ļ�·����Nword��start_ch,end_ch,Nword,longest_word,longest_letter
	�����������Ϣ�����������/����˵���Ǳ������ļ��У�

*/
