#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("*******  1.add           2.del   *********\n");
	printf("*******  3.search        4.modify*********\n");
	printf("*******  5.show          6.sort  *********\n");
	printf("**************   0.exit   ****************\n");
	printf("******************************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含1000个数组和size
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://1
			AddContact(&con);
			break;
		case DEL://2
			DelContact(&con);
			break;
		case SEARCH://3
			SearchContact(&con);
			break;
		case MODIFY://4   //这里switch-case语句中1，2，3，4，5，6，0表意不明确，我们可以用枚举的方式来让代码更加一目了然
			ModifyContact(&con);
			break;
		case SHOW://5
			ShowContact(&con);
			break;
		case SORT://6
			SortContact_byname(&con);
			break;
		case EXIT://0
			printf("已退出\n");
			break;
		default:
			printf("请重新输入：");
			break;
		}
	} while (input);
	return 0;
}