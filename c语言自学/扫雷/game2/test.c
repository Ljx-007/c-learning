#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//ɨ����Ϸ
void game()
{
	//�׵���Ϣ�洢,�����������飬һ���������ף�ȫ����ʼ��Ϊ0��Ȼ������ף���һ���������Ų��׵���Ϣ��ȫ����ʼ��Ϊ*������ҿ��ģ�
	//�Ų���ʱ��Ҫ������Χ�˸����꣬�����ڱ߱ߵ������Ų�ʱ��Խ�磬��������һȦ���̣�����11*11�����飬�����һȦ�����ף�ֻ��9*9��һȦ����
	char board[ROWS][COLS] = {0};
	char show[ROWS][COLS] = { 0 };
	InitBoard(board, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//����
	SetBoard(board, ROW, COL);
	//����ӡ�������̣�ֻ��ӡ��Ȧ��������ROW,COL
	DisplayBoard(board,ROW,COL);//������
	DisplayBoard(show, ROW, COL);//show������չʾ����ҵģ�board�����ǲ��׵����̣���չʾ����ҿ�
	//ɨ��
	FindBoard(board,show, ROW, COL);//Ҫ�����������飬��board�����ȡ��Ϣ�ŵ�show�����9*9���̲��������Դ������������ROW,COL
	//DisplayBoard(board, ROW, COL);
}
void menu()
{
	printf("#########################\n");
	printf("#####1.play    0.exit####\n");
	printf("#########################\n");
}
void test()
{
	int input;
	do
	{
		srand((unsigned int)time(NULL));
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("���˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
		
	} while (input);
}
int main()
{
	test();
	return 0;
}