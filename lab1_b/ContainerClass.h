//
// Created by wo on 2019/3/29.
//

#ifndef WORDLIST_CONTAINERCLASS_H
#define WORDLIST_CONTAINERCLASS_H
#include<string.h>
#include<string>
#include<set>
#include<stdio.h>
using namespace std;
#define Maxlen 100

class ContainerClass {
public:
//  char *vocabu[2000];
    char *wordlist[2000];
    char *longest_wordlist[2000];
    char **wordlist_array[1000];//�;�̬�ɣ����100�����˵Ļ�����
    int wordlist_count=0;
    set<string> readinword;
    int word_count;//��ǰ���������ʸ���
    int letter_count;//��ǰ��ĸ����
    int max_wordcount;//��ǰ��󵥴���
    int max_lettercount;//��ǰ�����ĸ��
    char runit[1] = "";
    char err_msg[11][100] =
            {
                    /* 0 */"",
                    /* 1 */"the insturction does not exist.",
                    /* 2 */"-n is not allowed to be used with -c.",
                    /* 3 */"the number of words in the file is less than n.",
                    /* 4 */"there is no word in the file.",
                    /* 5 */"we failed to write to the file solution.txt.",
                    /* 6 */"solution.txt opened failed.",
                    /* 7 */"the file used is not a txt file.",
                    /* 8 */"there is not a letter after -h or -t.",
                    /* 9 */"-w is not allowed to be used with -c.",
                    /* 10*/"there is not a number after -n or the number is 0."
            };

    bool StoreWord(char **container,int &num,char *word,int len);//num�ǵ�ǰ���ʸ���

    void ReStoreWord(char **container,int &num);

    void free_wordlist(char **_list);

    void store_wordlist(char** a,char **wordlist1,int num);

    void store_wordlist1(char** &a, char **wordlist1, int num);

    void print_wordlist(char**container);

    bool myisalpha(char &ch);//�ж��Ƿ��ǵ���

    //bool isdup(char *word);//�жϸõ����Ƿ���洢���ĵ����ظ�

    void error(int n);
};


#endif //WORDLIST_CONTAINERCLASS_H
