#include"lab1_A.h"
int main()
{
	char filepath[100] = "D:\\_LEARNING\\LAB_dasanxia\\Course_Artificial_Intelligence\\Course_Artificial_Intelligence\\test.txt";
	Puzzle_Solving puzzle;
	puzzle.Init(filepath);
	puzzle.start = { 1,1 };
	puzzle.end = { 2,8 };
	puzzle.A_star();
}