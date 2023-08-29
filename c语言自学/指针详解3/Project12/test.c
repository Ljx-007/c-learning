#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//学习数组时写的冒泡排序，但是这种冒泡排序只能排序整型数据，c语言提供了一个叫qsort的库，它能排序任何数据类型的数据，需要自己去研究
//包括如何自己写一个能排序任何数据类型的数据，这要用到回调函数的概念，下节课再来研究
void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int arr[] = { 5,8,9,2,4,1,3,10,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}




//int Add(int, int);
//int Sub(int, int);
//int Mul(int, int);
//int Div(int, int);
////回调函数：回调函数就是通过函数指针调用的函数，如果把函数的指针作为参数传给另一个函数，当这个指针被用来调用其所指函数时，所指函数就被称为回调函数
//
//
//
////指向函数指针数组的指针
//int main()
//{
//	int(*pf)(int, int);//函数指针
//	int(*p[4])(int, int);//这是一个函数指针数组
//	int(*(*pp)[4])(int, int) = &p;//这是一个指向函数指针数组的指针
//	//pp先与*结合，说明pp是一个指针。指向的是类型为int(*)[4](int,int)的函数指针数组，说明pp是一个数组指针
//	//数组有四个元素，每个元素类型为函数指针
//	return 0;
//}
//



//用函数指针数组写一个计算器
//void menu()
//{
//	printf("**************************\n");
//	printf("**********计算器**********\n");
//	printf("******1.add    2.sub******\n");
//	printf("******3.mul    4.div******\n");
//	printf("*********0.退出***********\n");
//	printf("**************************\n");
//}
//
//int main()
//{
//	int input;
//	int(*parr[])(int, int) = { 0,Add,Sub,Mul,Div };//因为数组的下标从0开始，而menu中要求了计算方法对应的数字，所以这里数组第一个元素用0来占用
//	                                           //目的就是让Add的下标为1，Sub的下标为2，以此类推
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			int x, y;
//			printf("请输入要计算的数字:");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", parr[input](x, y)); //这里使用函数指针数组可以很好的避免冗长的代码，如果需要添加别的计算方法，在函数指针数组添加相应的函数即可
//		}            
//		else if (input == 0)
//		{
//			printf("已退出!");
//		}
//		else
//			printf("输入错误，请重新输入\n");
//	} while (input);
//	return 0;
//}




//用switch，case语句写出来的计算器代码过于冗杂，假如计算器需要加入别的计算方法如按位与，按位或，按位异或等，就要不停的添加case语句
// 所以，可以用函数指针数组来优化这个算法
//void calculator(int(*p)(int, int))
//{
//	int x,  y;
//	printf("请输入两个数字进行运算：");   //如果不封装一个caculator()函数的话，那么每一个case语句后面都要写上printf和scanf
//	scanf("%d%d", &x, &y);            //并且每一个case语句下唯一不同的只是调用的函数不同
//	                     //那么就可以以调用的函数为参数封装一个函数，case语句使用时调用这个函数即可
//	printf("%d\n",p(x, y));
//}
//int main()
//{
//	int input = 0;
//	int x, y;
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calculator(Add);              //这里被calculator()调用的Add，Sub，Mul，Div函数就是回调函数
//			break;
//		case 2:
//			calculator(Sub);
//			break;
//		case 3:
//			calculator(Mul);
//			break;
//		case 4:
//			calculator(Div);
//			break;
//		case 0:
//			printf("已退出\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}