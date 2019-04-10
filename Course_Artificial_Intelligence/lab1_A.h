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
	int direction;//用来表示入口
};
struct F {//评价函数
	int g;//已经花的代价
	int h;//估计函数
};
struct State {
	Pos pos;
	F f;
};
struct puzzle_node
{
	int tag;//表示迷宫
	int direction;//这个是用来记录方向的，省的用什么close
};

class Puzzle_Solving
{
public:
	Puzzle_Solving();
	~Puzzle_Solving();
	void Init(char*);
	int Manhattan(Pos pos);//获取曼哈顿距离
	void A_star();
	void Insert(vector<State>&, State);//按照递减的顺序插入一个元素
	Pos get_next_pos(Pos, int);//按照方向得到下一个位置
	bool In_list(vector<State>, Pos);//判断一个位置是否在队列里
	void print_path();
	bool IDA_star_recursion(Pos pos,int cur_deep,int max_deep);
	void IDA_star();


public:
	Pos start, end;
private:
	puzzle_node puzzle[MAX_ROWS][MAX_COLUMNS];
	int  rows, cols;
};

