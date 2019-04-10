#pragma once 
#define MAX_ROWS 50
#define MAX_COLUMNS 50
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
struct Pos {
	int xpos;
	int ypos;
	int direction;//������ʾ���
};
struct F {//���ۺ���
	int g;//�Ѿ����Ĵ���
	int h;//���ƺ���
};
struct State {
	Pos pos;
	F f;
};
struct puzzle_node
{
	int tag;//��ʾ�Թ�
	int direction;//�����������¼����ģ�ʡ����ʲôclose
};

class Puzzle_Solving
{
public:
	Puzzle_Solving();
	~Puzzle_Solving();
	void Init(char*);
	int Manhattan(Pos pos);//��ȡ�����پ���
	void A_star();
	void Insert(vector<State>&, State);//���յݼ���˳�����һ��Ԫ��
	Pos get_next_pos(Pos, int);//���շ���õ���һ��λ��
	bool In_list(vector<State>, Pos);//�ж�һ��λ���Ƿ��ڶ�����
	void print_path();
	bool IDA_star_recursion(Pos pos,int cur_deep,int max_deep);
	void IDA_star();


public:
	Pos start, end;
private:
	puzzle_node puzzle[MAX_ROWS][MAX_COLUMNS];
	int  rows, cols;
};

