#include"lab1_A.h"


void Puzzle_Solving::Init(char *filepath)
{
	FILE* fp;
	fp = fopen(filepath, "r");
	if (!fp)
	{
		printf("File open failed.");
		exit(0);
	}
	fscanf(fp, "%d", &rows);
	fscanf(fp, "%d", &cols);
	for (int i = 0; i < rows; i++)//0代表阻碍，1代表可走
	{
		for (int j = 0; j < cols; j++)
		{
			fscanf(fp, "%d", &puzzle[i][j].tag);
			puzzle[i][j].direction = -1;
		}
	}
	fclose(fp);
	for (int i = 0; i < rows; i++)//0代表阻碍，1代表可走
	{
		for (int j = 0; j < cols; j++)
		{
			cout << puzzle[i][j].tag << " ";
		}
		cout << endl;
	}
}
int Puzzle_Solving::Manhattan(Pos pos)
{
	return abs(pos.xpos - end.xpos) + abs(pos.ypos - end.ypos);
}
Puzzle_Solving::Puzzle_Solving()
{
	
}
Puzzle_Solving::~Puzzle_Solving()
{

}
void Puzzle_Solving::A_star()
{
	vector<State>open;
	State state = { {start.xpos,start.ypos,0},{0,Manhattan(start)} };//0代表起点，没有入口
	Insert(open, state);


	state = open.back();
	open.pop_back();//取出最后一个元素
	puzzle[state.pos.xpos][state.pos.ypos].direction = state.pos.direction;
	
	while (state.pos.xpos != end.xpos || state.pos.ypos != end.ypos)
	{
		int direction;
		for (int i = 1; i < 5; i++)//
		{
			Pos next_pos = get_next_pos(state.pos, i);
			if (puzzle[next_pos.xpos][next_pos.ypos].tag
					&&!In_list(open,next_pos)
					&& puzzle[next_pos.xpos][next_pos.ypos].direction==-1
				)
			{
				State state_insert = { next_pos,{state.f.g + 1,Manhattan(next_pos)} };
				Insert(open, state_insert);
			}
		}
		state = open.back();
		open.pop_back();//取出最后一个元素
		puzzle[state.pos.xpos][state.pos.ypos].direction = state.pos.direction;
	}
	print_path();
	

}
void Puzzle_Solving::Insert(vector<State> &list, State state)
{
	int i;
	for (i = 0; i < list.size() && (state.f.g+state.f.h) < (list[i].f.g+list[i].f.h); i++);//找到要插入的位置

	list.push_back(state);//强制增加一个空间
	
	for (int j = list.size()-1; j > i; j--)
	{
		list[j] = list[j - 1];
	}
	list[i] = state;
}
Pos Puzzle_Solving::get_next_pos(Pos curpos, int i)
{
	Pos next_pos;
	switch (i)
	{
	case 1:next_pos = { curpos.xpos ,curpos.ypos +1,3}; break;
	case 2:next_pos = { curpos.xpos+1 ,curpos.ypos ,4}; break;
	case 3:next_pos = { curpos.xpos ,curpos.ypos-1,1 }; break;
	case 4:next_pos = { curpos.xpos - 1,curpos.ypos,2 }; break;
	}
	return next_pos;
}
bool Puzzle_Solving::In_list(vector<State>list, Pos pos)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].pos.xpos == pos.xpos && list[i].pos.ypos == pos.ypos)
			return true;
	}
	return false;
}
void Puzzle_Solving::print_path()
{
	Pos pos = end;
	int direction = puzzle[pos.xpos][pos.ypos].direction;
	while(direction != 0)
	{
		puzzle[pos.xpos][pos.ypos].tag = 2;
		pos = get_next_pos(pos, direction);
		direction = puzzle[pos.xpos][pos.ypos].direction;
	}
	puzzle[pos.xpos][pos.ypos].tag = 2;
	for (int i = 0; i < rows; i++)
{
	for (int j = 0; j < cols; j++)
	{
		if (puzzle[i][j].tag == 0)
		{
			cout << "#";
		}
		else if (puzzle[i][j].tag == 1)
		{
			cout << " ";
		}
		if (puzzle[i][j].tag== 2)
		{
			cout << "*";//路径用*表示
		}
	}
	cout << endl;
}
}

bool Puzzle_Solving::IDA_star_recursion(int cur_deep,int max_deep)
{
	if (cur_deep >=max_deep)
		return false;
	else
	{
		return false;
	}
}