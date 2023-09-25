#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
//在学习动态内存管理之前，我们创建通讯录的方式是一次性开辟存放1000个人的信息的内存空间，但实际上，我们并不是一次性就把1000个人的信息加上
//当只需要存放某几个联系人的信息时，开辟出来的存放1000个人的信息的内存空间就显得太过浪费
//已经学习过动态内存管理后，我们对这个通讯录加以改造，先开辟一小部分空间，当有需求添加联系人时，我们再进行扩容

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
	struct Contact con;//con就是通讯录，里面包含data指针，size和capacity ，con的内容相较之前变化了，那么初始化通讯录的方式也要改变
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://1
			AddContact(&con); //动态版的增加信息函数也要改
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