#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	Initboard(board,ROW,COL);
	Displayboard(board, ROW, COL);
	char ret='1';
	while (1)     //这里不能写ret=='1'，因为如果玩家胜利的话ret被改写为‘*’后无法立刻判断，需要执行完while循环内的语句才能进行判断
		             //但是执行完语句后ret已经被下一个IsWin函数修改了，所以每次执行IsWin函数后需要立刻进行判断
	{
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL, '*');
		if (ret != '1')
			break;
		//Sleep(1000);
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = IsWin(board, ROW, COL,'#');
		if (ret != '1')
			break;

	}
	if (ret == '*')
		printf("恭喜你，获胜了！\n");
	else if (ret == '#')
		printf("很遗憾，你输了\n");
	else 
		printf("平局\n");

}
void menu()
{
	printf("*****************************\n");
	printf("***********三子棋************\n");
	printf("*****1.play      0.exit******\n");
	printf("*****************************\n");
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出!\n");
			break;
		default:
			printf("输入错误，请重新输入:\n");
			break;
		}
	} while (input);
	return 0;
}