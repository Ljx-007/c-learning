#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;//Ϊ��board��show���������ܹ���ʼ���Ҳ����������γ�ʼ���ĺ�����ֱ�Ӱѳ�ʼ�����ַ�Ҳ�ӽ���������ʡ���������κ����Ĳ���
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
	for (int i = 1; i <= row; i++)//i��1��ʼ����ΪҪ��ӡ����������9*9�ģ���ʵ�ʵ�������11*11���������������Ǵӣ�1��1����ʼ������i=1��<=row,�˴�row=9
	{
		printf("%d ", i);//��ӡ�к�
		for (int j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void SetBoard(char board[ROWS][COLS], int row, int col)
{
	int count = BOMB;//�׵ĸ���
	for (int i = 1; i <= count; i++)//�˴�����ʹ�õ���forѭ��
	{
		int x = rand() % row + 1;//rand()%row��row��9��rand()%row�ķ�Χ����0-8���ټӸ�һ��Χ����1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//ʹ��forѭ��ʱ�и�ȱ������������ͬһ�����꣬���׻᲼��ͬһ��λ�����Σ��Ͳ�������10���׵ı�׼
		}
		else
			count++;//�˴�ʹ��count++�ķ���������ظ����ף���count+1������һ��ѭ�����ٲ��ף��ظ��������׾Ͷ༸��ѭ���ٲ���
	}
}
//void SetBoard(char board[ROWS][COLS], int row, int col)
//{
//	int count = BOMB;
//	while (count)//while�ķ����������٣���ʦ�ķ�����
//	{
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] == '0')
//		{
//			board[x][y] = '1';
//			count--;//������׳ɹ���count�ͻ�-1��֪������0Ϊֹ������0ʱѭ���ͽ����ˡ�����ظ�������ѭ��������count������
//		}x`
//	}
//}

void FindBoard(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;//�Ų鲻���׵ĸ���
	int* p = &win;//ʹ��ȡ��ַ��win��ַ���ݹ麯�����ֹ�����������޸ĺ�����
	while (win<ROW*COL-BOMB)//����ȫ���Ų������Ϸʤ��,����ȫ���Ų��꣬9*9������10���ף���win�ﵽ9*9-10=71ʱ��ȫ���Ų����ף�ѭ����������Ϸʤ����
	{
		int x, y;
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			//����Ϸ�
			if (board[x][y] == '1')//�ȵ���
			{
				printf("���ź����㱻ը���ˣ�\n");
				show[x][y] = '#';
				DisplayBoard(show, ROW, COL);
				break;
			}
			else if (show[x][y] != '*')
				printf("�����Ѿ����Ų����\n");
			else//������
			{
				//���㣨x��y����Χ�м�����
				//char count = get_bomb(board,x, y);//���ú�������ȡ��Χ�׵ĸ���������ŵ�count��
				//show[x][y] = count;
				unfold(board, show, x, y,p);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
			printf("��������Ƿ�������������\n");
	}
	if (win == (ROW * COL - BOMB))
	{
		printf("��ϲ���ҳ�ȫ�����ף�\n");
	}
}
int get_bomb(char board[ROWS][COLS], int x, int y)
{
	//������Χ�˸������ж��Ƿ���ը�����ж�ը���ĸ����ķ���Ϊ������Χ�˸����궼����һ�飬��ը��Ϊ1����ը��Ϊ0�����ȫ������һ�����ը���ĸ���
	//���������ڴ�ŵ����ַ�'0'���ַ�'1'���ַ�������ӣ��ʲ�������һ�ַ���
	//'1'-'0'=1 , '3'-'0'=0 , '0'-'0'=0. ��ǰ������ӿ�֪���ַ������ּ�ȥ�ַ�0�������ֱ����˴����ַ����ֺ��ַ�0��ASCII��ֵ���������֪
	//ը��������Ϊ�ַ�1���ʰ���Χ�˸��ַ�����������ȥ8*'0'����ը���ĸ���
	//char num = 0;
	//num = board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1];
	//int count = num - 8 * '0';//����8*'0',���ó�ը���ĸ���
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (board[i][j] == '1')
				count++;
		}
	}
	return count;
}
void unfold(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y,int* p)
{
	int ret = get_bomb(board, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		(*p)++;
		for (int i = x - 1; i <= x + 1; i++)//ʹ��forѭ��������Χ�˸�����
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*' && i <= ROW && i>=1 && j <= COL && j >= 1)
					//�˴�i��jҪ>=1����Ȼ����һȦû�д�ӡ������Ҳ����*p���ӣ�������ȫ���Ų������Ϸû��ʤ��
					unfold(board, show, i, j,p);
			}
		}
	}

	else 
	{
		show[x][y] = ret + '0';//�ټӻ��ַ�0����ԭ�����ַ�����
		(*p)++;
		//DisplayBoard(show, ROW, COL);
	}
}