#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//函数的递归，递归简单来说就是函数自己调用自己，能将复杂问题简单化
//练习4：求第n个斐波那契数 
//斐波那契数列:1,1,2,3,5,8,13,21,34,55.......
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);//用递归解决此问题时，当数字较大时，斐波那契数会被重复计算很多次，导致速度慢
//}
int fib(int n)
{//迭代算法
	int a = 1, b = 1;
	int c = 1;
	for (int i = 2; i < n; i++)
	//while(n>2)    此处用while循环也可以
	{
		c = a + b;//最开始a，b=1，相加后赋值给c，接着a，b，c都往后移移位，即a赋给b，b赋给c，c得到新的值a+b
		a = b;   //节省了重复计算的次数，速度块
		b = c;
	}
	return c;
}
int main()
{
	int a;
	printf("输入一个数求第n个斐波那契数：");
	scanf("%d", &a);
	printf("%d", fib(a));
	return 0;
}


//练习3：求n的阶乘
//int fac(int x)
//{
//	if (x != 1)
//		return x * fac(x - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int a;
//	printf("输入数字求其阶乘:");
//	scanf("%d", &a);
//	fac(a);
//	printf("%d", fac(a));
//	return 0;
//}


//练习2：编写一个函数不创建临时变量，求字符串长度
// 方法一（创建临时变量法）：
//int my_strlen(char* str)
//{
//	int count = 0;//此方法创建了临时变量
//	while ((*str) != 0)
//	{
//		count++;
//		str++;//数组元素的下标从第一个元素往下加，知道遇到结束字符\0为止
//	}
//	return count;
//}

//方法二（递归法）：
//my_strlen("hello")
//1+my_strlen("ello")
//1+1+my_strlen("llo")
//.....
//1+1+1+1+1+my_strlen("")
//1+1+1+1+1+0=5
//int my_strlen(char* str)
//{
//	if ((*str) != '\0')
//		return 1 + my_strlen(str + 1);//str是地址，+1后指向的是后一个字符的地址
//	else 
//		return 0;
//}
//int main()
//{
//	char arr[] = "hello";
//	int len = my_strlen(arr);//arr是数组，数组传参传过去的不是数组，而是首元素地址
//	printf("len=%d", len);
//	return 0;
//}



//练习1：用函数递归将数1234的每一位打印出来如1 2 3 4
//void print(int x)
//{
//	if (x > 9) //递归在书写时一定要找到一个条件，不然就是无条件的死循环
//		//递归的必要条件：1、存在限制条件，当满足这个限制条件的时候，递归不再继续。 2、每次递归调用之后越来越接近这个限制条件
//		print(x /10);
//	printf("%d ", x % 10);//打印1234的每一位，1234%10就等于4，把4拿出来变为123就是1234/10=123，继续用123%10=3，再把3拿出来--123/10=12
//	                      //以此类推能得到每一位数字，当数字为个位数时无需再进行除10的操作
//}
//int main()
//{
//	int num;
//	printf("输入一个数打印它的每一位：");
//	scanf("%d", &num);
//	print(num);//创建递归函数来完成任务
//}



//int main() //一个最简单的递归
//{//递归常见的错误为栈溢出
//	printf("hehe\n");//电脑内存分为栈区，堆区，静态区。栈区主要储存局部变量、函数形参、函数调用；堆区储存动态开辟的内存（malloc，calloc）；
//	                                                 //静态区储存全局变量和static修饰的变量
//	main();    //当递归进行时，函数不断调用，在栈区不断地申请空间，直到栈区空间耗尽，于是程序停止报错
//	return 0;
//}