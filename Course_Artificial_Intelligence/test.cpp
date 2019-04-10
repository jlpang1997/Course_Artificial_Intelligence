#include"lab1_A.h"
int main()
{
	//char filepath[100] = "D:\\_LEARNING\\LAB_dasanxia\\Course_Artificial_Intelligence\\Course_Artificial_Intelligence\\test.txt";
	char filepath[100] = "test.txt";
	Puzzle_Solving puzzle;
	puzzle.Init(filepath);
	puzzle.start = { 1,1 };
	puzzle.end = { MAX_ROWS-2,MAX_ROWS-2 };
	puzzle.IDA_star();
	//puzzle.A_star();
}