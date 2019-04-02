/** \brief 图相关数据结构和操作
 *
 * \param
 * \param
 * \return
 *
 */
#pragma once
#include"container.h"
#include<string.h>
#include<stdio.h>
struct ArcNode
{
	int vex;	//顶点;0-25对应a-z
	char *name; //单词
	int lenth;	//单词长度
	bool visited;
	ArcNode *NextArc;
};

struct Vnode
{
	int vex;
	ArcNode *FirstArc;
};

void Create(char *,char *);

void DFS_ArcNode(int i,char *out_meg,int word_num=0,char start_ch=0,char end_ch=0,bool longest_word=false,bool longest_letter=false);//默认取0

void DFS(int word_num,char start_ch,char end_ch,bool longest_word,bool longest_letter,char *out_meg);

void print_adjlist();

void random_generate_testfile();

void Init_DFS();

void output_certain_num(char*);

void output_longest(char*);

void free_graph();
