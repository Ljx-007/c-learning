#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//扫雷游戏
void game()
{
	//雷的信息存储,创建两个数组，一个拿来放雷（全部初始化为0，然后加上雷），一个拿来放排查雷的信息（全部初始化为*，给玩家看的）
	//排查雷时需要遍历周围八个坐标，但是在边边的坐标排查时会越界，于是扩大一圈棋盘，创建11*11的数组，最外层一圈不放雷，只在9*9里一圈放雷
	char board[ROWS][COLS] = {0};
	char show[ROWS][COLS] = { 0 };
	InitBoard(board, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//布雷
	SetBoard(board, ROW, COL);
	//不打印整个棋盘，只打印内圈，所以是ROW,COL
	DisplayBoard(board,ROW,COL);//测试用
	DisplayBoard(show, ROW, COL);//show棋盘是展示给玩家的，board棋盘是布雷的棋盘，不展示给玩家看
	//扫雷
	FindBoard(board,show, ROW, COL);//要操作两个数组，从board里面获取信息放到show里，且在9*9棋盘操作，所以传参两个数组和ROW,COL
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
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始！\n");
			game();
			break;
		case 0:
			printf("已退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		
	} while (input);
}
int main()
{
	test();
	return 0;
}