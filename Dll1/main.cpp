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
	char *out_meg)//输入)
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
	}//默认用户用'\'来分割

	if (first_run == true)
	{
		Create(filepath,out_meg);
		strcpy(former_filepath, filepath);
		first_run = false;
	}
	if (!first_run)
	{
		if (strcmp(filepath, former_filepath) != 0)//跟先前的路径不一样
		{
			free_graph();//把之前的释放掉
			Create(filepath,out_meg);
			strcpy(former_filepath, filepath);
		}
	}
	
	if (out_meg[0])//建图时打开文件失败
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
	1,神他妈的必须先关闭控制台才能重新跑，我日
	2,每一次都给我记得把动态分配的内存释放掉，卧槽
	3,用到realloc的函数都给用引用值
	4,两次DFS的初始化工作没做好，导致malloc出错，而且还是一些
    很底层的错误，所以每次都要做好初始化，以及内存回收工作。
    5,如果最后一个字符是换行，那最后就进入死循环了


	GUI的输入输出接口有：
	输入：文件路径，Nword，start_ch,end_ch,Nword,longest_word,longest_letter
	输出：错误信息，和最长单词链/还是说还是保存在文件中？

*/
