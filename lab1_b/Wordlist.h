
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
    // ��ȡ����������, ����ֵΪ���ʾ��ȡ�ɹ�������Ϸ�, ����Ϊ��
    bool read_command(int argc, char *argv[]);

    // ���ļ�, ��ȡ�����б�, �ų��ظ����ʺ�, ����all_word, ��дall_word_num, ����ֵ��ʾ���Ƿ�ɹ�
    bool open_read_file(char file_path[] = filepath);

    // ��gen_chain_*��������, �õ����б���ͼ, �����ж��Ƿ����ظ����ʵ��߼�, ����ֵ��ʾ�����ظ�����
    bool create_graph(char *words[]=all_word, int len=all_word_num);

    // ������൥�����������������words������ĵ����б�, len�ǵ����б��ﵥ�ʵĸ���, result������������Ľ��, head��tail�ֱ�Ϊ
    // ����������ĸ��β��ĸԼ�����������0����ʾû��Լ����
    int gen_chain_word(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr, char head=start_ch,
            char tail=end_ch);

    // ���������ĸ�����ĵ�����, ����ֵ�Ǹõ���������ĸ��
    int gen_chain_char(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr, char head=start_ch,
            char tail=end_ch);

    // ָ���������ĵ��ʸ���Ҫ�������������Ҫ��ĵ������ĸ���������������Ҫ��ĵ�����, ����ֵ�ǵ���������Ŀ
    int gen_chain_num(char* words[]=all_word, int len=all_word_num, char* result[]=nullptr,int word_num=0);

    // ����longest_word, start_ch, end_ch, longest_letter, Nword��Ҫ�������������������solution.txt�ļ�
    int file_output();

    // ����read_command, open_read_file, gen_chain_*, file_output,
    // ����ֵ�ǵ�������(longest_word==true||start_ch!=0||end_ch!=0)��
    // ��ĸ��(longest_letter==true)�򵥴�����Ŀ(Nword!=0)
    int gen_chain(char* words[]=all_word, int len=all_word_num, char* result[]= nullptr, char head=start_ch,
            char tail=end_ch, int word_num=0);
};


#endif //WORDLIST_WORDLIST_H
