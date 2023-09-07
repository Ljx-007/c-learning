#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//把棋盘里的字符都改为空格 
		}
	}
}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{//此代码只能打印3*3的棋盘，如果行和列改为10，打印出来的棋盘是十行三列，所以需要优化
//	for (int i = 0; i < row; i++)
//	{
//		//打印一行的数据
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);//board数组里的字符全部被初始化为空格了
//		//打印分割行
//		if(i<row-1)
//			printf("---|---|---\n");//打印出来的棋盘与期望的棋盘多出了一行分割行，故加上一层if语句去掉最后一行
//	}
//}

//优化算法
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)//把棋盘分为3部分，一共三行和两行分割行，一行字符行和一行分割行看成一部分
	{
		for (int j = 0; j < col; j++)//这个for循环里的代码打印的是：   |   |   ，
		{
			//打印一行的数据
			printf(" %c ", board[i][j]);               
			if (j < col - 1)//最后一个 | 不用打印，所以是col-1
		//打印一个字符打印一个 | 
				printf("|");
		}
		printf("\n");//换行
		//打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)// 这个for循环里的代码打印的是：---|---|---（分割行）
			{
				printf("---");
				if (j < col - 1)
					printf("|"); 
			}
			printf("\n");//换行
		}
			
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;//初始化数组坐标
	printf("到你了\n");
	while (1)
	{
		printf("请输入要下的坐标：");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//玩家不是程序员，看棋盘时不会认为坐标是从0开始，而是从1开始，所以输入的坐标要-1
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("这里不能下\n");//输入错误则继续循环
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	int x, y;
	while (1)
	{
		x = rand() % row;//让横纵坐标的范围取在0-2间
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		else
			continue;
	}

}
//1、玩家赢 --返回1
//2、电脑赢 --返回2
//3、平局   --返回3
//4、继续   --返回4
int IsWin(char board[ROW][COL], int row,int col)//判断输赢函数
{
	//判断横的三个相同
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '*')//横的三个相等且不等于空格，因为最开始有三个空格也相等
			return 1;//玩家赢
		else if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '#')
			return 2;//电脑赢
	}
	//判断竖的三个相同
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == '*')//横的三个相等且不等于空格，因为最开始有三个空格也相等
			return 1;//玩家赢
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '#')
			return 2;//电脑赢
	}
	//对角线
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] == '*')
		return 1;
	else if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] == '#')
		return 2;
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] == '*')
		return 1;
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] == '#')
		return 2;
	//判断平局（棋盘满了且没有人获胜）
	if (1 == isFull(board, ROW, COL))//设置判断是否平局的函数
		return 3;
	else
		return 4;
}
int isFull(char board[ROW][COL], int row, int col)//返回1表示棋盘满了，返回0表示棋盘没满
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (board[i][j] == ' ')
				return 0;//没满
		}
	}
	return 1;//满了
}