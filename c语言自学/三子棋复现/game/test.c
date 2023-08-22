#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	int ret;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 4)
			break;
		printf("����˼���С���\n");
		Sleep(1000);
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 4)
			break;
	}
	switch (ret)
	{
	case 1:
		printf("��ϲ���ʤ�ˣ�\n");
		break;
	case 2:
		printf("���ź�������\n");
		break;
	case 3:
		printf("ƽ��\n");
		break;
	default:
		break;
	}

}
void menu()
{
	printf("##############################\n");
	printf("##########��������Ϸ##########\n");
	printf("######1.play      0.exit######\n");
	printf("##############################\n");
}
void test()
{
	int input;
	do
	{
		srand((unsigned int)time(NULL));
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf(" ��Ϸ��ʼ!\n");
			game();
			break;
		case 0:
			printf("���˳�\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
	
}
int main()
{
	test();
	return 0;
}