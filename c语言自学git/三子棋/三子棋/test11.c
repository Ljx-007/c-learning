#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include "game.h"
//�ö�ά����ʵ�־�������Ϸ
void menu()
{
	printf("###################################\n");
	printf("########1.play      0.exit ########\n");
	printf("###################################\n");
}
//ϣ����ӡ��������
//    |    |    
//----|----|----
//    |    |    
//----|----|----
//    |    |   
void game()
{//ϣ�������������ȫ�ǿո��������Ӿ��Ͽ��ǿհ׵�����
	char board[ROW][COL] = { 0 };//�˴�3*3��������ͷ�ļ������к�����ʵ�֣����Ҫ���к��������ٴ򿪲����ļ��޸ģ�ֱ����ͷ�ļ�game.h���޸ļ���
	//��ʼ������
	InitBoard(board,ROW,COL);//0���ַ���ӡ�д�ӡ�����������ȥ�������ʼ�����̴��룬���̾ͶԲ�����
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	int ret;
	//����
	while (1)
	{
		//������壬�ٷ�װһ������
		PlayerMove(board, ROW, COL);//�������Ҫ�����������������������Բ��������̺�����
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret=IsWin(board, ROW, COL);
		Sleep(1000);
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
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
		printf("ƽ��");
		break;
	default:
		break;
	}
}
void test()
{
	int input;
	do
	{
		srand((unsigned int)time(NULL));//ȡ�������
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("���˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	
}
int main()
{
	test();
	return 0;

}