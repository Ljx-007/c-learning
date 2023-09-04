#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
//练习四：打印一个菱形
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********   
//  ********* 
//   *******          
//    *****
//     ***
//      *
int main()
{
	int line = 0;
	printf("要打印多少行的菱形：");
	while(1)
	{
		scanf("%d", &line);
		if (line % 2 == 0)
			printf("打印菱形只能输入奇数哦\n");
		else
			break;
	}
	int blank = line/2;
	int xing = 1;
	while (blank+1)
	{
		for(int i=0;i<blank;i++)
		{
			printf("%c", ' ');
		}
		blank--;
		for (int j = 0; j < xing; j++)
		{
			printf("%c", '*');
		}
		xing+=2;
		printf("\n");
	}
	blank = 1, xing -= 2;
	while (xing>0)
	{
		for (int i = 0; i < blank; i++)
		{
			printf("%c", ' ');
		}
		blank++;
		for (int j = 0; j < xing-2; j++)
		{
			printf("%c", '*');
		}
		xing -= 2;
		printf("\n");
	}
	return 0;
}



//练习三：求出0-100000的水仙花数，即一个n次方的数字，各位数字的n次方之和等于这个数本身
//int main()
//{
//	for (int i = 1; i <= 100000;i++)
//	{
//		//判断水仙花数的位数
//		int count = 0; //任何一个数字至少是一位数
//		int num = 0;
//		int e1 = i;
//		while (e1 >0)     //这个while循环可以合并为while(e1/=10)
//		{                                       //{ count+;}
//			e1 = e1 / 10;
//			count++;
//		}
//		e1 = i;
//		while(e1>0)
//		{
//			num+=pow(e1 % 10, count);  //pow(a,b)意思是a的b次方，pow是个函数，要引入<math.h>这个头文件，不过pow返回的是double类型的数字，所以运行时会有警告
//			e1 = e1 / 10;
//		}
//		if (num == i)
//			printf("%d ", i);
//	}
//	return 0;
//}



//练习二：计算求和，求Sn=a+aa+aaa+aaaa+aaaaa....前n项之和，其中a是一个数字。例如2+22+222+2222+22222....
//int main()
//{
//	int a, n;
//	printf("a=");
//	scanf("%d", &a);
//	printf("n=");
//	scanf("%d", &n);
//	int Sn = 0;
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret*10 + a;
//		Sn += ret;
//	}
//	printf("%d", Sn);
//	return 0;
//}



//练习一：写一个函数，可以逆序字符串的内容
//void reverse(char ch[])
//{
//	char* left = ch;
//	char* right = ch;
//	while (*(right+1) != '\0')
//	{
//		right++;
//	}
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--, left++;
//	}
//}
//int main()
//{
//	char ch[12] = { 0 };//11个字符和一个\0
//	//scanf("%s", ch);
//	//当我们输入hello world的时候，scanf读取到空格，tab，回车等缓冲区字符就会自动截断，如果没有gets(ch)这行代码，那么scanf读取到的就是hello而不是hello world
//	//gets这个函数返回的类型为char* ，参数类型也为char*，是读取一行字符串的
//	//读取一行，无论你输入什么东西，都会被读取到，包括空格 
//	//在VS2019后gets这个函数就被删除了，因为可以无限读取，容易溢出
//	//所以用了gets_s函数来代替，gets_s函数的返回类型是char*，参数是char*和要输出的字符串的长度（不包含'\0'）
//	//用gets_s往ch里输入字符串时要规定ch的长度，不然会报错
//	gets_s(ch,11); 
//	reverse(ch);
//	printf("%s", ch);
//	return 0;
//}