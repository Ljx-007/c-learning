#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//����������ַ�����Ϊ�ո� 
		}
	}
}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{//�˴���ֻ�ܴ�ӡ3*3�����̣�����к��и�Ϊ10����ӡ������������ʮ�����У�������Ҫ�Ż�
//	for (int i = 0; i < row; i++)
//	{
//		//��ӡһ�е�����
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);//board��������ַ�ȫ������ʼ��Ϊ�ո���
//		//��ӡ�ָ���
//		if(i<row-1)
//			printf("---|---|---\n");//��ӡ���������������������̶����һ�зָ��У��ʼ���һ��if���ȥ�����һ��
//	}
//}

//�Ż��㷨
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)//�����̷�Ϊ3���֣�һ�����к����зָ��У�һ���ַ��к�һ�зָ��п���һ����
	{
		for (int j = 0; j < col; j++)//���forѭ����Ĵ����ӡ���ǣ�   |   |   ��
		{
			//��ӡһ�е�����
			printf(" %c ", board[i][j]);               
			if (j < col - 1)//���һ�� | ���ô�ӡ��������col-1
		//��ӡһ���ַ���ӡһ�� | 
				printf("|");
		}
		printf("\n");//����
		//��ӡ�ָ���
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)// ���forѭ����Ĵ����ӡ���ǣ�---|---|---���ָ��У�
			{
				printf("---");
				if (j < col - 1)
					printf("|"); 
			}
			printf("\n");//����
		}
			
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;//��ʼ����������
	printf("������\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺");
		scanf("%d%d", &x, &y);
		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//��Ҳ��ǳ���Ա��������ʱ������Ϊ�����Ǵ�0��ʼ�����Ǵ�1��ʼ���������������Ҫ-1
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("���ﲻ����\n");//������������ѭ��
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	int x, y;
	while (1)
	{
		x = rand() % row;//�ú�������ķ�Χȡ��0-2��
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
//1�����Ӯ --����1
//2������Ӯ --����2
//3��ƽ��   --����3
//4������   --����4
int IsWin(char board[ROW][COL], int row,int col)//�ж���Ӯ����
{
	//�жϺ��������ͬ
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '*')//�����������Ҳ����ڿո���Ϊ�ʼ�������ո�Ҳ���
			return 1;//���Ӯ
		else if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == '#')
			return 2;//����Ӯ
	}
	//�ж�����������ͬ
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == '*')//�����������Ҳ����ڿո���Ϊ�ʼ�������ո�Ҳ���
			return 1;//���Ӯ
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] == '#')
			return 2;//����Ӯ
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] == '*')
		return 1;
	else if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] == '#')
		return 2;
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] == '*')
		return 1;
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] == '#')
		return 2;
	//�ж�ƽ�֣�����������û���˻�ʤ��
	if (1 == isFull(board, ROW, COL))//�����ж��Ƿ�ƽ�ֵĺ���
		return 3;
	else
		return 4;
}
int isFull(char board[ROW][COL], int row, int col)//����1��ʾ�������ˣ�����0��ʾ����û��
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (board[i][j] == ' ')
				return 0;//û��
		}
	}
	return 1;//����
}