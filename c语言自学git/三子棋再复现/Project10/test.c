#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	Initboard(board,ROW,COL);
	Displayboard(board, ROW, COL);
	char ret='1';
	while (1)     //���ﲻ��дret=='1'����Ϊ������ʤ���Ļ�ret����дΪ��*�����޷������жϣ���Ҫִ����whileѭ���ڵ������ܽ����ж�
		             //����ִ��������ret�Ѿ�����һ��IsWin�����޸��ˣ�����ÿ��ִ��IsWin��������Ҫ���̽����ж�
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
		printf("��ϲ�㣬��ʤ�ˣ�\n");
	else if (ret == '#')
		printf("���ź���������\n");
	else 
		printf("ƽ��\n");

}
void menu()
{
	printf("*****************************\n");
	printf("***********������************\n");
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
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("���˳�!\n");
			break;
		default:
			printf("�����������������:\n");
			break;
		}
	} while (input);
	return 0;
}