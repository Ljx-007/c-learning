#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include "game.h"
//用二维数组实现井字棋游戏
void menu()
{
	printf("###################################\n");
	printf("########1.play      0.exit ########\n");
	printf("###################################\n");
}
//希望打印出的棋盘
//    |    |    
//----|----|----
//    |    |    
//----|----|----
//    |    |   
void game()
{//希望棋盘里的内容全是空格，这样从视觉上看是空白的棋盘
	char board[ROW][COL] = { 0 };//此处3*3的棋盘用头文件定义行和列来实现，如果要改行和列无需再打开测试文件修改，直接在头文件game.h中修改即可
	//初始化棋盘
	InitBoard(board,ROW,COL);//0在字符打印中打印不出来，如果去掉这个初始化棋盘代码，棋盘就对不齐了
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	int ret;
	//下棋
	while (1)
	{
		//玩家下棋，再封装一个函数
		PlayerMove(board, ROW, COL);//下棋就是要在数组上填东西，下在哪里，所以参数是棋盘和行列
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret=IsWin(board, ROW, COL);
		Sleep(1000);
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
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
		printf("平局");
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
		srand((unsigned int)time(NULL));//取随机数用
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏开始：\n");
			game();
			break;
		case 0:
			printf("已退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	
}
int main()
{
	test();
	return 0;

}