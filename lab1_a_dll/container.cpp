#include"container.h"

char runit[] = "Please push the filepath again\n";
char err_msg[11][100]=
{
	/* 0 */"",
	/* 1 */"function for Searching this certain word chain is not avalible",
	/* 2 */"-n is not allowed to be used with -c.",
	/* 3 */"the number of words in the file is less than n.",
	/* 4 */"there is no word in the file.",
	/* 5 */"we failed to write to the file solution.txt.",
	/* 6 */"solution.txt opened failed.",
	/* 7 */"the file used is not a txt file.",
	/* 8 */"there is not a letter for the start or end ",
	/* 9 */"-w is not allowed to used with -c.",
	/* 10*/"there is not a number after -n or the number is 0."
};

char* error(int n)
{
	//printf("Error: %s\n%s\n", err_msg[n], runit);
	return err_msg[n];
	//exit(0);
}

bool myisalpha(char &ch)//判断ch是否是字母
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


char *wordlist[2000];
char *longest_wordlist[2000];


unsigned wordlist_count;


int word_count;//当前单词链单词个数
int letter_count;//当前字母总数
int max_wordcount;//当前最大单词数
int max_lettercount;//当前最大字母数

bool flag;
unsigned byte;
FILE*fp_out;


bool StoreWord(char **container,int &num,char *word,int len)//num是当前单词个数
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
void ReStoreWord(char **container,int &num)

{

	free(container[num-1]);
	container[num-1]=NULL;
	num--;
}
void print_wordlist(char**container)
{
	for (int i = 0; container[i]; i++)
	{
		printf("%s\n", container[i]);
	}
	printf("\n\n");
}

void store_wordlist(char **a,char **wordlist1,int num)
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

void store_wordlist1(char *out_meg,char **wordlist, int num)
{
	if (byte == 0)
	{
		strcpy(out_meg, "");
		char num[10] = "000000000";
		strcat(out_meg, num);//先占9个字节走，待会再把数字写回去
		strcat(out_meg, "\r\n");
		byte += 11;

		fp_out = fopen("./solution.txt", "w");
		if (!fp_out)
		{
			printf("error\n");
			exit(0);
		}
		fprintf(fp_out, "%d\n", 0);//先存一个数进去

	}
	if (flag==false&&byte < 100000)//拷一条链，前提是已用字节不超过100000
	{
		for (int i = 0; wordlist[i]; i++)
		{
			strcat(out_meg, wordlist[i]);
			strcat(out_meg, "\r\n");
			byte += strlen(wordlist[i]) + 2;//一个换行只是加两个字节

			
		}
		strcat(out_meg, "\r\n");//再一个换行

	}
	else 
	{
		if (flag == false)
		{
			strcat(out_meg, "........\r\nSee the entire word chain in the file solution.txt");
			flag = true;
		}
		
	}
	for (int i = 0; wordlist[i]; i++)
	{
		fprintf(fp_out, "%s\n", wordlist[i]);
	}
	fprintf(fp_out, "\n");
}
void free_wordlist(char **_list)
{
    for(int i=0;_list[i];i++)
    {
        free(_list[i]);//释放每一个单词
    }
    //free(_list);//最后释放指针列表
}
