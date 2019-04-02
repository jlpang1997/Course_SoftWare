//
// Created by wo on 2019/3/29.
//

#ifndef WORDLIST_WORDGRAPHCLASS_H
#define WORDLIST_WORDGRAPHCLASS_H

#include<string.h>
#include<stdio.h>
#include "ContainerClass.h"

class WordGraphClass : public ContainerClass{
public:
    #define RANDOM_NUM 70
    struct ArcNode
    {
        int vex;	//����;0-25��Ӧa-z
        char *name; //����
        int lenth;	//���ʳ���
        bool visited;
        ArcNode *NextArc;
    };

    struct Vnode
    {
        int vex;
        ArcNode *FirstArc;
    };
    int V_count = 0;
    struct Vnode adjlist[26];
    struct ArcNode*pre_arc = nullptr;
    bool printed;


    void Create(char filepath[]);

    void DFS_ArcNode(int i,int word_num=0,char start_ch=0,char end_ch=0,bool longest_word=false,bool longest_letter=false);//Ĭ��ȡ0

    void DFS(int word_num=0,char start_ch=0,char end_ch=0,bool longest_word=false,bool longest_letter=false);

    void print_adjlist();

    void random_generate_testfile();

    void Init_DFS();

    void output_certain_num();

    void output_longest();

    void free_graph();
};


#endif //WORDLIST_WORDGRAPHCLASS_H
