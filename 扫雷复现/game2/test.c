#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//����
	setmine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//����
	findbomb(mine, show, ROW, COL);
}
void menu()
{
	printf("------------ɨ��--------------\n");
	printf("******************************\n");
	printf("********1.play    0.exit******\n");
	printf("******************************\n");
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
			printf("��Ϸ��ʼ\n");
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