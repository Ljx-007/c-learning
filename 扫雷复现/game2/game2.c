#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		printf("%d  ", i);//打印列号
	}
	printf("\n");
	for (int i = 1; i <=row; i++)
	{
		printf("%d ", i);//打印行号
		for (int j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	
}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = BOMB;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	
}
void findbomb(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int* p = &win;
	while (win < ROW * COL - BOMB)
	{
		int x, y;
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] != '*')
				printf("这里已经排查过了\n");
			else
			{
				/*int count = getbomb(mine, x, y);
				show[x][y] = count + '0';*/
				unfold(mine, show, x, y,p);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
			printf("坐标非法，请重新输入\n");
	}
	if (win ==(ROW * COL - BOMB))
		printf("恭喜你获胜了！\n");
}
int getbomb(char mine[ROWS][COLS], int x,int y)
{
	int count=0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
				count++;
		}
	}
	return count;
}
void unfold(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* p)
{
	int count = getbomb(mine, x, y);
	if (count == 0)
	{
		show[x][y] = ' ';
		(*p)++;
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 1 && i <= ROW && j >= 1 && j <= COL && show[i][j] == '*')
					//此处i和j要>=1，不然外面一圈没有打印的棋盘也会让*p增加，导致雷全部排查完后游戏没有胜利
				{
					unfold(mine, show, i, j,p);					
				}
			}
		}
	}
	else
	{
		show[x][y] = count + '0';
		(*p)++;
	}
}