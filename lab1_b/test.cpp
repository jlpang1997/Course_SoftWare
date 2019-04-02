#include<iostream>
#include"Core.h"
#include"Adjlist_Graph.h"
#include"in_out.h"



using namespace std;
int main()
{
	//Adjlist_Graph a;
	//char tmp[][10] = { "apple","egg","god","dox" };
	//char *words[4] = { tmp[0],tmp[1],tmp[2],tmp[3] };
	//a.Create_Graph(words, 4);
	//a.Show_Graph();

	char filepath[1000] = "D:\\_LEARNING\\LAB_dasanxia\\Wordlist_GUI\\test.txt";
	In_Out begin;
	begin.in(filepath);
	//begin.print_in();
	Core core;
	//core.gen_chain_word(begin.words, begin.word_num, begin.result,'\0','w');
	core.gen_chain_char(begin.words, begin.word_num, begin.result,'a','e');
	//core.gen_chain_char(begin.words, begin.word_num, begin.result,'a');
	//core.gen_chain_char(begin.words, begin.word_num, begin.result,'a','b');
	//core.gen_chain_char(begin.words, begin.word_num, begin.result);
	//core.gen_chain_word_certain_num(begin.words, begin.word_num, begin.result_array, begin.chain_count,2,0,'d');
	//begin.print_result();
	begin.print_result();
	//begin.print_result_array();

	//char *test[10];
	//test[0] = new char[10];
	//strcpy(test[0], "hello");
	//cout << test[0] << endl;
	//delete test[0];

	return 0;
	
}
