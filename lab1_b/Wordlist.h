
//

// Created by wo on 2019/3/29.

//

#ifndef WORDLIST_WORDLIST_H
#define WORDLIST_WORDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "WordGraphClass.h"

class Wordlist :public WordGraphClass{
private:
    int Nword=0;
    static char start_ch;
    static char end_ch;
    bool longest_word=false;
    bool longest_letter=false;
    static char filepath[100];
    FILE * fp;
    static char *all_word[1000];
    static int all_word_num;

public:
    // 读取命令行命令, 返回值为真表示读取成功且命令合法, 否则为假
    bool read_command(int argc, char *argv[]);

    // 打开文件, 读取单词列表, 排除重复单词后, 存入all_word, 改写all_word_num, 返回值表示打开是否成功
    bool open_read_file(char file_path[] = filepath);

    // 被gen_chain_*函数调用, 用单词列表创建图, 加入判断是否有重复单词的逻辑, 返回值表示有无重复单词
    bool create_graph(char *words[]=all_word, int len=all_word_num);

    // 计算最多单词数量的最长单词链，words是输入的单词列表, len是单词列表里单词的个数, result是输出单词链的结果, head和tail分别为
    // 单词链首字母与尾字母约束（如果传入0，表示没有约束）
    int gen_chain_word(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr, char head=start_ch,
            char tail=end_ch);

    // 计算最多字母数量的单词链, 返回值是该单词链的字母数
    int gen_chain_char(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr, char head=start_ch,
            char tail=end_ch);

    // 指定单词链的单词个数要求输出所有满足要求的单词链的个数，和所有满足要求的单词链, 返回值是单词链的数目
    int gen_chain_num(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr,int word_num=0);

    // 根据longest_word, start_ch, end_ch, longest_letter, Nword的要求情况输出单词链结果到solution.txt文件
    int file_output();

    // 整合read_command, open_read_file, gen_chain_*, file_output,
    // 返回值是单词链长(longest_word==true||start_ch!=0||end_ch!=0)或
    // 字母数(longest_letter==true)或单词链数目(Nword!=0)
    int gen_chain(char* words[]=all_word, int len=all_word_num, char* result[]= nullptr, char head=start_ch,
            char tail=end_ch, int word_num=0);
};


#endif //WORDLIST_WORDLIST_H
