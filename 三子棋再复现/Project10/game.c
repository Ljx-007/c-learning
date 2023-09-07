#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)         //   |   |   
                                                                  //---|---|---
	                                                              //   |   |   
	                                                              //---|---|---
	                                                              //   |   |   
{
	for (int i = 0; i < row; i++)
	{
		for(int j=0;j<col;j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");			
		}
		printf("\n");
		if(i<row-1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������\n");
	printf("���������꣺");
	while(1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������ѱ�ռ��\n");
		}
		else
			printf("����������������룺");
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] != '*'&&board[x][y]!='#')//board[x][y]==' '
		{
			board[x][y] = '#';
			break;
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col,char set) //����*����һ�ʤ������*�����Ի�ʤ������0��ƽ��;����1������
{
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == set)
			return set;
	}
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == set)
			return set;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == set)
		return set;
	if (board[1][1] == board[0][2] && board[1][1] == board[2][0] && board[1][1] == set)
		return set;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return '1'; //��������л��пո�˵��û�н���������1
		}
	}
	return 0;//����ѭ��˵���������޿ո���û��ʤ��������0��ƽ��

}