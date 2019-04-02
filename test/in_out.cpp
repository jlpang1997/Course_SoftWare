#include"in_out.h"
#include<iostream>
#include<set>

using namespace std;
bool In_Out::myisalpha(char &ch)//判断ch是否是字母
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
void In_Out::in(char *filepath)
{
	FILE *fp = fopen(filepath, "r");
	if (!fp)
	{
		printf("error\n");
		exit(0);
	}
	set<string> readin;
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
		char temp[MAX_WORD_LEN + 1];
		do
		{
			if (k < MAX_WORD_LEN)
			{
				temp[k++] = ch;
			}
			ch = fgetc(fp);
		} while (myisalpha(ch));
		temp[k] = '\0';
		if (readin.insert(temp).second == true)
		{
			words[word_num] = new char[k];
			//delete words[word_num];
			strcpy(words[word_num], temp);
			word_num++;
		}
			
	}


}
void In_Out::print_in()
{
	for (int i = 0; i < word_num; i++)
	{
		cout << words[i] << endl;
	}
	cout << endl;
}
void In_Out::print_result()
{
	for (int i = 0; result[i]; i++)
	{
		cout << result[i] << endl;
	}
	cout << endl;
}
void In_Out::print_result_array()
{
	cout << chain_count << endl;
	for (int i = 0; i < chain_count; i++)
	{
		for (int j = 0; result_array[i][j]; j++)
		{
			cout << result_array[i][j] << endl;
		}
		cout << endl;
	}
}


In_Out::In_Out()
{
	word_num = 0;
	chain_count = 0;
	memset(result, NULL, MAX_CHAIN_WORDS*sizeof(NULL));
	memset(result_array, NULL, MAX_CHAIN_COUNT*MAX_CHAIN_WORDS * sizeof(NULL));//全部为NULL
	memset(words, NULL, MAX_TOTAL_WORD * sizeof(NULL));

}


In_Out::~In_Out()
{
	//天哪为什么delete不了？
	//for (int i = 0; i < word_num; i++)
	//{
	//	delete words[i];
	//}
	//for (int i = 0; result[i]; i++)
	//{
	//	delete result[i];
	//}
	//for (int i=0; i < chain_count; i++)
	//{
	//	for (int j = 0; result_array[i][j]; j++)
	//	{
	//		delete []result_array[i][j];
	//	}
	//}

}
