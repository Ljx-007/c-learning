#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//练习9：递归实现n的k次方
double power(int n, int k) //返回值中有浮点类型，所以函数类型也是浮点类型
{  //分三种情况
	if (k < 0)
		return (1.0 / power(n, -k));//k小于0，-k就大于0，由于是小数，所以为了能准确返回小数，把1改为1.0
	else if (k == 0)
		return 1;
	else
		return n * power(n, k - 1);
	
}
int main()
{
	int n, k;
	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);
	double num = power(n, k);
	printf("%lf", num);
	return 0;
}




//练习8：编写递归函数计算一个数的每一位之和
//int DigitSum(int a)
//{
//	if (a > 9)
//		return a % 10 + DigitSum(a / 10);
//	else
//		return a;
//}
//int main()
//{
//	unsigned int a ;
//	scanf("%d", &a);
//	int num=DigitSum(a);
//	printf("%d", num);
//	return 0;
//}





//练习7：编写一个函数reverse_string()（递归实现），将参数字符串中的字符反向排列，要求不能使用库中字符串操作函数
//方法二：(递归法）
//int my_stringlen(char ch[])
//{
//		if (*ch == '\0')
//		return 0;
//	else
//		return 1 + my_stringlen(ch + 1);
//}
//void reverse_string(char ch[])
//{
//	int len = my_stringlen(ch); //先获取字符串长度
//	char* start = ch;
//	char* end = ch + len - 1;   
//	char tmp = 0;
//	tmp = *start;
//	//a b c d e f \0
//	//f b c d e a \0 ->f b c d e \0 \0
//	//ch+1指向b,b与替换掉a的\0组成新的字符串 b c d e
//	//b c d e \0 ->e c d b \0 ->e c d \0 \0
//	//c和\0组成新的字符串c d \0 ->d c \0, c d中间没有字符了，递归停止，最后的*end = tmp，则是将替换成\0的字符一个个补回来，最后完成逆序
//	*start = *end;   //交换a和f的值
//	*end = '\0';    //再把交换后的a的位置变为\0，方便下面ch+1与这个\0组成新的字符串
//	if (my_stringlen(ch + 1) > 1)   //当新的字符串长度为0或者1时，都说明新的字符串里只有0个或1个字符，当还有两个及以上的字符时，仍需要交换
//		reverse_string(ch + 1);  //仍需要交换就继续递归，放入reverse函数中交换
//	*end = tmp; //当递归完后再把原先替换的\0给换回来
//}
//int main()
//{
//	char ch[] = "abcdef";
//	reverse_string(ch);
//	printf("%s", ch);
//}




//方法一：（自己写的）
//void reverse_string(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while ((*end) != '\0')
//	{
//		end++;
//	}
//	end--;   //此处end-1的作用是让end不要指到\0，如果把\0也交换到最前面，那么该字符串数组将无输出，因为\0是字符串的结束标志
//	while (start < end)
//	{
//		char tmp = 0;
//		tmp = *start;
//		*start = *end;
//		*end = tmp;
//		end--, start++;
//	}
//}
//int main()
//{	
//	char ch[] = "abcdef";
//	reverse_string(ch);
//	printf("%s", ch);
//	return 0;
//}



//练习6：用递归函数打印一个数的每一位
//void Print(int input)
//{
//	if (input > 9)
//		Print(input / 10);
//	printf("%d ", input % 10);
//	
//}
//int main()
//{
//	int input;
//	printf("输入数字打印这个数的每一位：");
//	scanf("%d", &input);
//	Print(input);
//	return 0;
//}



//练习5：输出乘法口诀表，输入9，输出9*9口诀表，输入12，输出12*12的口诀表
//void print_table(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			printf("%d*%-2d=%-3d ",j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	again:
//	printf("请输入数字选择打印n*n的口诀表：");
//	scanf("%d", &n);
//	if (n <= 0)
//	{
//		printf("输入错误！\n");
//		goto again;
//	}
//	print_table(n);
//	return 0;
//}




//练习4：打印100-200间的素数
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int j;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if(j>sqrt(i))
//			printf("%d ", i);
//	}
//	return 0;
//}




//练习3：获取一个整数二进制序列中的奇数位和偶数位，分别打印出二进制序列
//int main()
//{
//	int a = -1;
//	printf("奇数位：");
//	for (int i = 30; i>=0; i-=2)
//	{
//		int b = (a >> i) & 1; //此处让a右移比让1左移好，因为让a左移与1按位与的判断始终是在最低位，最低位只有0和1
//		printf("%d", b);      //若让1左移的话按位与位置的判断不断在变化，且得到的数字不会是0或1
//		                     //例如当按位与判断出的1在奇数第三位，得到的结果是0100，赋值到b中就是4，而我们想得到的只有1或0
//		                     //如果要让1左移并且得到正确的结果，那么打印b时可以使用逻辑反操作符！，将b逻辑反两次，即!!b即可得到正确答案
//	}
//	printf("\n偶数位：");
//	for (int i = 31; i >=1; i -= 2)
//	{
//		int b = (a >> i) & 1;
//		printf("%d", b);
//	}
//	return 0;
//}



//练习2：比较两个数中二进制不同位的个数
//int main()
//{  //异或：两个数的二进制位相同为0，相异为1，恰好符合这个题目的要求
//	int a, b,c;
//	printf("输入两个数判断二进制不同位的个数：");
//	scanf("%d%d", &a, &b);
//	c = a ^ b;//a,b异或完后不同位会变成1，所以c这个数中二进制1的个数就是a，b两个数不同位的个数，所以还要计算c中1的个数
//	int count = 0;
//	while (c)
//	{
//		c = c & (c - 1);
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}




//练习1：统计某个数字二进制中1的个数
//方法二：最精简的算法，超级牛逼
//int main()
//{
//	int a = -1,count=0;  //1111 
//	while (a)
//	{
//		//1111--15
//		//1110--14  15&14--1110--a
//		//1110--a
//		//1101--a-1  a&(a-1)--1100--a
//		//以此类推，a二进制中的1的个数一直在减少，一直按位与下去a最后会变为0
//		a = a & (a - 1); 
//		count++;//所以只需要计算出1少了几次就知道1有几个了
//	}
//	printf("%d ", count);
//	return 0;
//}



//方法一：
//int main()
//{
//	int a = -1;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (1==((a>>i) & 1))
//			count++;
//	}
//	printf("%d ", count);
//	return 0;
//}