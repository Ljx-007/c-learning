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
		printf("%d  ", i);//��ӡ�к�
	}
	printf("\n");
	for (int i = 1; i <=row; i++)
	{
		printf("%d ", i);//��ӡ�к�
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
		printf("������Ҫ�Ų�����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] != '*')
				printf("�����Ѿ��Ų����\n");
			else
			{
				/*int count = getbomb(mine, x, y);
				show[x][y] = count + '0';*/
				unfold(mine, show, x, y,p);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
			printf("����Ƿ�������������\n");
	}
	if (win ==(ROW * COL - BOMB))
		printf("��ϲ���ʤ�ˣ�\n");
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
					//�˴�i��jҪ>=1����Ȼ����һȦû�д�ӡ������Ҳ����*p���ӣ�������ȫ���Ų������Ϸû��ʤ��
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