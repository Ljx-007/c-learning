#include <stdio.h> 
//%c打印字符
//%d打印整型
//%f打印浮点数                       基本不会用到
//%p以地址的形式打印
//%x打印16进制数字
//int main()
//{
//	//int age = 20;
//	//printf("%d\n",age);
//	//char ch = 'A';
//	//printf("%c", ch);
//	/*double f = 0.2;
//	printf("%lf", f);*/
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(short));
//	return 0;
//	
//}
//int main()
//{
//	//计算两个数之和
//	int num1 ,num2,sum;
//	/*int num2 ;
//	int sum ;*/
//	//输入数据使用输入函数scanf_s
//	scanf_s("%d%d", &num1, &num2);//有两个整型就用两个整型符号    &是取地址符号，取num1，num2的位置
//	sum = num1 + num2;
//	printf("sum=%d",sum);
//	return 0;
//}
int main()
{
	extern int a;//extern 声明外部变量
	printf("a=%d", a);
}