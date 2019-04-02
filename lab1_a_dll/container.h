/** \brief 这个主要是作为一个容器，目的是存两样东西，一个是为了
            为了检测出重复单词而把每个插入图的单词都记录下来，
            另一个是为了存单词链
 *
 * \param
 * \param
 * \return
 *
 */

#pragma once
#include<string.h>
#include<string>
#include<set>
#include<stdio.h>
using namespace std;
#define addition 20
#define Maxlen 100


extern int word_count;//单词链单词个数
extern int letter_count;
extern int max_wordcount;
extern int max_lettercount;
extern int maxletter_wordcount;

extern unsigned  byte ;
extern bool flag ;
extern FILE*fp_out;

extern set<string> readinword;
extern char *wordlist[];
extern char runit[];
extern char *longest_wordlist[];

//extern char **wordlist_array[];//就静态吧，最多100个多了的话……
extern char  ***wordlist_array;//

extern unsigned wordlist_count;
bool StoreWord(char **container,int &num,char *word,int len);//num是当前单词个数

void ReStoreWord(char **container,int &num);

void free_wordlist(char **_list);

void store_wordlist(char** a,char **wordlist1,int num);
void store_wordlist1( char *out_meg,char **wordlist1, int num);

void print_wordlist(char**container);

bool myisalpha(char &ch);//判断是否是单词

//bool isdup(char *word);//判断该单词是否与存储过的单词重复

char* error(int n);
