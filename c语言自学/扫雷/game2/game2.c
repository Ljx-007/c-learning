#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;//为了board和show两个棋盘能够初始化且不用设置两次初始化的函数，直接把初始化的字符也加进参数来，省略设置两次函数的步骤
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		printf("%d  ", i);//打印行号
	}
	printf("\n");
	for (int i = 1; i <= row; i++)//i从1开始，因为要打印出的棋盘是9*9的，但实际的棋盘是11*11，所以数组坐标是从（1，1）开始，所以i=1且<=row,此处row=9
	{
		printf("%d ", i);//打印列号
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
	int count = BOMB;//雷的个数
	for (int i = 1; i <= count; i++)//此处布雷使用的是for循环
	{
		int x = rand() % row + 1;//rand()%row，row是9，rand()%row的范围就是0-8，再加个一范围就是1-9
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//使用for循环时有个缺点是如果随机到同一个坐标，则雷会布到同一个位置两次，就不能满足10个雷的标准
		}
		else
			count++;//此处使用count++的方法，如果重复布雷，则count+1，即多一次循环来再布雷，重复布几次雷就多几次循环再布雷
	}
}
//void SetBoard(char board[ROWS][COLS], int row, int col)
//{
//	int count = BOMB;
//	while (count)//while的方法代码量少（老师的方法）
//	{
//		int x = rand() % row + 1;
//		int y = rand() % col + 1;
//		if (board[x][y] == '0')
//		{
//			board[x][y] = '1';
//			count--;//如果布雷成功就count就会-1，知道减到0为止，减到0时循环就结束了。如果重复布雷则循环继续，count不减。
//		}x`
//	}
//}

void FindBoard(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;//排查不是雷的个数
	int* p = &win;//使用取地址把win传址到递归函数里，防止变量被不明修改和销毁
	while (win<ROW*COL-BOMB)//当雷全部排查完后游戏胜利,即雷全部排查完，9*9的棋盘10个雷，即win达到9*9-10=71时，全部排查完雷，循环结束，游戏胜利。
	{
		int x, y;
		printf("请输入排查雷的坐标：");
		scanf("%d%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1)
		{
			//坐标合法
			if (board[x][y] == '1')//踩到雷
			{
				printf("很遗憾，你被炸死了！\n");
				show[x][y] = '#';
				DisplayBoard(show, ROW, COL);
				break;
			}
			else if (show[x][y] != '*')
				printf("这里已经被排查过了\n");
			else//不是雷
			{
				//计算（x，y）周围有几个雷
				//char count = get_bomb(board,x, y);//设置函数来获取周围雷的个数，并存放到count中
				//show[x][y] = count;
				unfold(board, show, x, y,p);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
			printf("输入坐标非法，请重新输入\n");
	}
	if (win == (ROW * COL - BOMB))
	{
		printf("恭喜你找出全部的雷！\n");
	}
}
int get_bomb(char board[ROWS][COLS], int x, int y)
{
	//遍历周围八个坐标判断是否有炸弹，判断炸弹的个数的方法为：把周围八个坐标都遍历一遍，有炸弹为1，无炸弹为0，最后全部加在一起就是炸弹的个数
	//由于棋盘内存放的是字符'0'和字符'1'，字符不能相加，故采用这样一种方法
	//'1'-'0'=1 , '3'-'0'=0 , '0'-'0'=0. 由前面的例子可知，字符的数字减去字符0就是数字本身，此处查字符数字和字符0的ASCII码值进行相见可知
	//炸弹我们设为字符1，故把周围八个字符都加起来减去8*'0'就是炸弹的个数
	//char num = 0;
	//num = board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1];
	//int count = num - 8 * '0';//减掉8*'0',最后得出炸弹的个数
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
		for (int i = x - 1; i <= x + 1; i++)//使用for循环遍历周围八个坐标
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*' && i <= ROW && i>=1 && j <= COL && j >= 1)
					//此处i和j要>=1，不然外面一圈没有打印的棋盘也会让*p增加，导致雷全部排查完后游戏没有胜利
					unfold(board, show, i, j,p);
			}
		}
	}

	else 
	{
		show[x][y] = ret + '0';//再加回字符0就是原来的字符数字
		(*p)++;
		//DisplayBoard(show, ROW, COL);
	}
}