#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>;
#include <stdlib.h>;
////#define #define定义的标识符常量
//#define a 10//用#define将a定义为10
////枚举常量，枚举关键字是enum
//enum Sex 
//{
//	MALE,
//	FEMALE,   //MALE,FEMALE,SECRET就是枚举常量，
//	SECRET
//
//};
//int main()
//{
//	//const int num = 2;//const-常属性，把变量num变成一个无法更改的常量,但num还是一个变量，只是具有常属性
//	/*printf("%d", a);*/
//	enum Sex s = FEMALE;
//	printf("%d\n", s);
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d", SECRET);
//	return 0;
//}


//   \t是转义符号，代表缩进  \ddd--ddd代表八进制中的某三个数字，代表将这三个数字转成十进制后的数字对应ASCII码值的字符
//   \xdd--dd代表两个16进制的数字，x表示十六进制，\xdd代表2个16进制的数字转成十进制的数字后对应的ASCII码值的字符
//int main()
//{//双引号引起来的就是字符串
//	char arr[] = "abc";//字符串可存放在数组中,字符串abc后还有一个0
//	//"abc"--'a' , 'b' , 'c' , '\0'   \0是字符串的结束标志
//	char arr2[] = {'a','b','c'};
//	/*printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr2));*/
//	//printf("%s\n", arr);//打印字符串用%s
//	//printf("%s", arr2);
//	printf("%c\n",' \ 38');
//	return 0;
//}
//   选择语句if()
//int main()
//{
//	int input;
//	printf("are you ok?");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("yes,I'm fine thank you.");
//	else
//		printf("no,I'm bad");
//	return 0;
//}


//while 循环语句
//int main()
//{
//	printf("考上大学，开始学习c语言\n");
//	printf("学习c语言的同时你还想暴富，于是每天买一张彩票\n");
//	int line = 0;
//	int m = 1;
//	int a = rand() %2041;
//	printf("%d\n", a);
//	while (line < 20000)
//	{
//		if (m== a)
//		{
//			printf("第%d天中了500万彩票，不用努力了\n",m);
//			break;
//		}
//		printf("第%d天，没中彩票，开始敲代码，代码+1 彩票+1 行数=%d\n", line + 1, line + 1);
//		line++;
//		m++;
//	}
//	return 0;
//}


//自定义函数
//int Add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return z;
//}

//创建数组
//int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//float arr2[10]= { 1,2,3,4,5,6,7,8,9,10 };
//char ch[5] = { 'a','b','c','d' };
//int main()
//{
//	/*printf("%d\n", arr[1]);*/
//	//printf("%f\n", arr2[2]);
//	//printf("%c\n", ch[3]);
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d\n", arr[i]);
//		i++;
//	}
//}



//%--取余数
//  >>（右移）,<<（左移） 是移位操作符（2进制），将一个数所占的比特位整体左移或右移
//如：
//int main()
//{
//	int a = 1;
//	int b = a << 1;//一个整型占4个字节32个比特位，a=1即 00000000000000000000000000000001
//	               //左移一个单位后补0变为00000000000000000000000000000010 此时b=2
//	               //左移两个单位后补0变为00000000000000000000000000000100 此时b=4
//	printf("%d", b);
//	return 0;
//}



//(2进制)位操作符
// & 按位与(取交集）
// | 按位或（取并集）
// ^ 按位异或
//例：
int main()
{
	int a = 5;//二进制为011
	int b = 3;//二进制为101
//	int c = a & b;//&表示011和101的交集--为001，故c=1
//	int d = a | b;//|表示011和101的并集--为111，故d=7
	int f = a ^ b;//^表示对应的二进制位相同则为0，相异则为1，故011和101的异或为110，故f=6
	printf("%d", f);
	return 0;
}


//a=a+1等价于a+=1
//a=a-1等价于a-=1
//a=a&1等价于a&=1
//以此类推还有*=，/=，^=,|=,>>=,<<=
//单目操作符（只涉及一个数字）
//!   逻辑反操作符  0为假，非0就为真  如a=10 !a=0 , a=0 !a=1 
//-   负值
//+   正值
//&   取地址   
//sizeof   操作数的类型长度（以字节为单位）   注意：计算数组大小时，数组大小等于数组内数字大小*数字个数
                                            //如arr[10]={0} sizeof(arr)=40 因为一个整型的size=4，10个就是40
                                            //计算数组元素个数，个数=数组大小/每个元素的大小，如：num=sizeof(arr)/sizeof(arr[0])   
// ~  对一个数的二进制取反
//--  前置、后置--
//++  前置、后置++
//*  间接访问操作符
//(类型)  强制类型转换