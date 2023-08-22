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
		printf("电脑思考中……\n");
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
		printf("恭喜你获胜了！\n");
		break;
	case 2:
		printf("很遗憾你输了\n");
		break;
	case 3:
		printf("平局\n");
		break;
	default:
		break;
	}

}
void menu()
{
	printf("##############################\n");
	printf("##########三子棋游戏##########\n");
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
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf(" 游戏开始!\n");
			game();
			break;
		case 0:
			printf("已退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	
}
int main()
{
	test();
	return 0;
}