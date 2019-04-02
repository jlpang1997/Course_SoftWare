#pragma once
#include<iostream>
#include<vector>
using namespace std;
#define VNODE_SIZE 26

struct ArcNode
{
	ArcNode():NextArc(NULL){}//��ʼ��
	char alpha;	//����;0-25��Ӧa-z
	char *name; //����
	int lenth;	//���ʳ���
	bool visited;
	ArcNode *NextArc;
};

struct Vnode
{
	Vnode():FirstArc(NULL){}//��ʼ��Ϊnull
	char alpha;//��������ĸ
	ArcNode *FirstArc;
};



 class Adjlist_Graph
{
public:
	Adjlist_Graph();
	void Create_Graph(char *words[], int len);
	void Show_Graph();

	void DFS();
	
	void DFS_ArcNode(int i);

	

	~Adjlist_Graph();


public:
	vector<string>longest_word_chain;//�Ѿ��ǳ�ʼ��Ϊsize=0��
	vector<string>word_chain_array[10000];//���Ǿ�̬��10000��
	char head;
	char tail;
	bool letter_flag;
	bool word_flag;
	bool num_flag;
	int certain_num;
	int chain_count = 0;

private:
	Vnode* adjlist;
	int Vnode_num;
	int Arc_num;
	ArcNode *pre_arc;

	int cur_letter_count;
	int max_letter_count;

	vector<string> word_chain;

 };

