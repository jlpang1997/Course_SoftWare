//
// Created by wo on 2019/3/29.
//

#include "ContainerClass.h"

void ContainerClass::error(int n)
{
    printf("Error: %s\n%s\n", err_msg[n], runit);
    exit(0);
}

bool ContainerClass::myisalpha(char &ch)//判断ch是否是字母
{
    if (ch <= 'Z' && ch >= 'A')
    {
        ch -= 32;
        return true;
    }
    else if (ch <= 'z' && ch >= 'a')
        return true;
    else
        return false;
}

bool ContainerClass::StoreWord(char **container,int &num,char *word,int len)//num是当前单词个数
{
    container[num] = (char *)malloc(sizeof(char)*(len + 1));
    if (!container[num])
    {
        printf("OVERFLOW\n%s\n",runit);
        exit(0);
    }
    strcpy(container[num], word);
    container[num+1]=NULL;
    num++;
    return true;
}

void ContainerClass::ReStoreWord(char **container,int &num)
{

    free(container[num-1]);
    container[num-1]=NULL;
    num--;
}

void ContainerClass::print_wordlist(char**container)
{
    for (int i = 0; container[i]; i++)
    {
        printf("%s\n", container[i]);
    }
    printf("\n\n");
}

void ContainerClass::store_wordlist(char **a,char **wordlist1,int num)
{
    for(int i=0;i<num;i++)
    {
        int len=strlen(wordlist1[i]);
        a[i]=(char*)malloc(sizeof(char)*(len+1));
        strcpy(a[i],wordlist1[i]);
        a[i][len]='\0';
    }
    a[num]=NULL;//增加一个单词链结束标志

}

void ContainerClass::store_wordlist1(char **&a, char **wordlist1, int num)
{
    a=(char **)malloc(sizeof(char *)*(num+1));
    if(!a)
    {
        printf("OVERFLOW\n%s\n", runit);
        exit(0);
    }
    for (int i = 0; i<num; i++)
    {
        int len = strlen(wordlist1[i]);
        a[i] = (char*)malloc(sizeof(char)*(len + 1));
        strcpy(a[i], wordlist1[i]);
        a[i][len] = '\0';
    }
    a[num] = NULL;//增加一个单词链结束标志

}

void ContainerClass::free_wordlist(char **_list)
{
    for(int i=0;_list[i];i++)
    {
        free(_list[i]);//释放每一个单词
    }
}

