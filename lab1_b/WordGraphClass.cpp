//
// Created by wo on 2019/3/29.
//

#include "WordGraphClass.h"

void WordGraphClass::random_generate_testfile()
{
    //srand((unsigned))
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
        printf("Open Failed!\n%s\n",runit);
    for (int k = 0; k < RANDOM_NUM; k++)
    {
        char tmp[100];
        int len = 5 + rand() % 5;
        for (int i = 0; i < len; i++)
        {
            tmp[i] = rand() % 26 + 'a';
        }
        tmp[len] = '\0';
        fprintf(fp, "%s\n", tmp);

    }
    fclose(fp);
}

void WordGraphClass::Create(char filepath[])
{
    int i;
    for (i = 0; i < 26; i++)	//初始化邻接表
    {
        adjlist[i].vex = i;
        adjlist[i].FirstArc = NULL;
    }
    //for (i = 0; i < 2000; i++)
    //	vocabu[i] = NULL;
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        printf("Open Failed!Perhaps non-existent file\n%s\n",runit);
        exit(0);
    }
    int j = 0;
    char ch = fgetc(fp);
    while (!feof(fp))
    {
        while (!myisalpha(ch))
        {
            if (feof(fp))
                return;
            ch = fgetc(fp);

        }
        int k = 0;
        char temp[Maxlen + 1];
        do
        {
            if (k < Maxlen)
            {
                temp[k++] = ch;
            }
            ch = fgetc(fp);
        } while (myisalpha(ch));
        temp[k] = '\0';
        //tmp1 = temp;
        if (readinword.insert(temp).second == true) //不重复
        {
            V_count++;
            j++;
            ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
            int start = temp[0] - 'a';
            int end = temp[k - 1] - 'a';
            p->lenth = k;
            p->vex = end;
            p->name = (char *)malloc(sizeof(char)*(k + 1));
            strcpy(p->name, temp);
            p->visited = false;
            p->NextArc = adjlist[start].FirstArc;
            adjlist[start].FirstArc = p;//头插法
        }
    }
    fclose(fp);
}

void WordGraphClass::print_adjlist()
{
    for (int i = 0; i < 26; i++)
    {
        struct ArcNode *p;
        printf("%c: ", 'a' + i);
        for (p = adjlist[i].FirstArc; p; p = p->NextArc)
        {
            printf("%s ", p->name);
        }
        printf("\n");
    }

}

void WordGraphClass::DFS_ArcNode(int i, int word_num, char start_ch, char end_ch, bool longest_word, bool longest_letter)
{
    struct ArcNode *p;
    struct ArcNode *tmp = pre_arc;
    for (p = adjlist[i].FirstArc; p; p = p->NextArc)
    {
        if (!p->visited)
        {
            printed = false;
            pre_arc = p;
            p->visited = true;

            letter_count += p->lenth;

            StoreWord(wordlist, word_count, p->name, p->lenth);
            if (word_num != 0 && word_count == word_num)
            {
                store_wordlist1(wordlist_array[wordlist_count++], wordlist, word_num);
                //print_wordlist(wordlist);
                ReStoreWord(wordlist, word_count);
                p->visited = false;

            }
            else
                DFS_ArcNode(p->vex, word_num, start_ch, end_ch, longest_word, longest_letter);
        }
    }
    pre_arc = tmp;
    if (pre_arc)
    {
        pre_arc->visited = false;
        if (word_num != 0)
        {
            //return;
        }
            //暂时只要一条最长链
        else if (longest_word == true && word_num == 0)//单词最多的四种情况都包含在内了
        {

            if (end_ch != 0)     //start_ch==0&& 有没有起点都是用尾巴来判断
            {
                if (word_count >= 2 &&
                    word_count > max_wordcount&&
                    wordlist[word_count - 1][strlen(wordlist[word_count - 1]) - 1] == end_ch)
                {
                    max_wordcount = word_count;
                    //if (longest_wordlist)
                    //	free_wordlist(longest_wordlist);
                    store_wordlist(longest_wordlist, wordlist, word_count);
                    printed = true; //不一定在尽头
                }
            }
            else
                //因为入口处就设置好了起点，所以有起点和没有起点都是一样保存下来
            {
                if (word_count >= 2 && word_count > max_wordcount)
                {
                    max_wordcount = word_count;
                    //if (longest_wordlist)
                    //	free_wordlist(longest_wordlist);
                    store_wordlist(longest_wordlist, wordlist, word_count);
                    printed = true;
                }
            }
        }
        else if (longest_letter == true)
        {
            if (word_count >= 2 && letter_count > max_lettercount)
            {
                max_lettercount = letter_count;
                store_wordlist(longest_wordlist, wordlist, word_count);
                printed = true;
            }
        }
        ReStoreWord(wordlist, word_count);
        letter_count -= pre_arc->lenth;
    }
}

void WordGraphClass::DFS(int word_num, char start_ch, char end_ch, bool longest_word, bool longest_letter)
{
    Init_DFS();
    for (int i = 0; i < 26; i++)//从这里进去的都是肯定存在单词的
    {
        if (adjlist[i].FirstArc)
        {
            if (start_ch != 0)
            {
                if (i + 'a' == start_ch)
                    DFS_ArcNode(i, word_num, start_ch, end_ch, longest_word);
            }

            else
            {
                DFS_ArcNode(i, word_num, start_ch, end_ch, longest_word, longest_letter);
            }
        }
    }
    if (word_num != 0)
    {
        output_certain_num();
    }
    else
    {
        output_longest();
        free_wordlist(longest_wordlist);
    }
    free_wordlist(wordlist);
    free_graph();
}

void WordGraphClass::Init_DFS()
{
    word_count = 0;//当前单词链单词个数
    letter_count = 0;//当前字母总数
    max_wordcount = 0;//当前最大单词数
    max_lettercount = 0;//当前最大字母数
}

void WordGraphClass::output_longest()
{
    FILE*fp = fopen("./solution.txt", "w");
    if (!fp)
        error(6);
    for (int i = 0; longest_wordlist[i]; i++)
    {
        fprintf(fp, "%s\n", longest_wordlist[i]);
    }
    fclose(fp);
}

void WordGraphClass::output_certain_num()
{
    FILE*fp = fopen("./solution.txt", "w");
    if (!fp)
        error(6);
    fprintf(fp, "%d\n", wordlist_count);
    for (int j = 0; j < wordlist_count; j++)
    {
        for (int i = 0; wordlist_array[j][i]; i++)
        {
            fprintf(fp, "%s\n", wordlist_array[j][i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void WordGraphClass::free_graph()
{
    ArcNode *p, *q = nullptr;
    for (int i = 0; i < 26; i++)
    {
        p = adjlist[i].FirstArc;
        if(p)
            q = p->NextArc;
        while (p)
        {
            free(p);
            p = q;
            if (q)
                q = q->NextArc;
        }
    }
}