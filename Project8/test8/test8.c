#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"add.h"   //引入自己创建的头文件时用双引号，库函数用尖括号
//函数的嵌套使用和链接访问
//int Add(int, int);//声明函数，只需声明函数名，参数类型，返回类型即可，具体这个函数存不存在，无关紧要。

//一般函数的声明不是放在执行的主源文件中，而是创造一个源文件和头文件，形成一个模块
//此处以加法函数为例，分别创建add.c源文件和add.h头文件形成一个加法模块，最后在主源文件引入加法头文件即可使用加法函数
//在add.c文件中写入加法函数算法，在add.h头文件中写入函数声明
int main()
{
	int a = 10, b = 20;
	extern Add();
	int sum = Add(a, b);
	printf("%d", sum);
	return 0;
}
//int Add(int x, int y)//程序从上往下执行，函数放在后面对前面的程序来说是未定义的，所以在主函数前要声明
//{
//	return x + y;
//}


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	//结果是4321，第一次打印的是最里层的printf，结果为43，第二次打印打印的是第一次printf的返回值
//	//printf的返回值是打印字符的个数
//	//所以第一个printf返回的值是2，因为43是2个字符，第二个printf返回的值就是1，最终结果打印出来就是4321
//	return 0;
//}


//练习4：写一个函数，每一次调用这个函数就会将num的值+1
//void Add(int* p)
//{
//	*p+= 1;//不能写成*p++，++的优先级比*高，++会作用在p上，所以要写成(*p)++;
//}
//int main()
//{
//	int num = 0;
//	int pa = &num;
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}



//练习3：写一个函数实现整型有序数组的二分查找
//int binary_search(int arr[], int x,int sz) //本质上arr是一个指针，指针的大小是8个字节，所以sz算出来是错的
//{
//	int left = 0;
//	//int sz = sizeof(arr) / sizeof(arr[0]);  //故此处的sz放到主函数去,再给二分查找函数多加一个sz的参数
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (x < arr[mid])
//			right = mid - 1;
//		else if (x > arr[mid])
//			left = mid + 1;
//		else if (x = arr[mid])
//			return mid;
//	}
//	if (left > right)//此处if语句也可以省略
//		return -1;
//}
//int main()
//{
//	int a;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//在函数内部求出数组个数是做不到的，所以在函数外部求出数组个数后传进函数里
//	printf("输入查找的数字：");
//	//找得到返回下标，找不到返回-1
//	scanf("%d", &a);
//	int ret = binary_search(arr,a,sz);//此处数组传参时只传了数组第一个元素的地址
//	if (ret == -1)
//		printf("数组没有这个数字");
//	else
//		printf("找到了，下标为：%d", ret);
//	return 0;
//}



//练习2：写一个函数判断一年是不是闰年
//int leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	printf("输入一个年份判断是否为闰年：");
//	scanf("%d",&year);
//	if (leap_year(year) == 1)
//		printf("闰年");
//	else
//		printf("非闰年");
//	return 0;
//}



//练习1：写一个函数判断一个数是不是素数
//int prime(int x)
//{
//	int i = 2;
//	for (i = 2; i < sqrt(x); i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;	
//		}
//	}
//	if (i > sqrt(x))//此处可以省略if语句，因为能出for循环的一定是素数了，所以可以直接return 1
//		return 1;
//}
//int main()
//{
//	int a,b;
//	printf("请输入一个数判断是否为素数：");
//	scanf("%d", &a);
//	b = prime(a);
//	if (b == 1)
//		printf("素数");
//	else
//		printf("非素数");
//	return 0;
//}




//写一个函数交换两个数的值
//void change(int x, int y)//void不返回值，x，y为形参	
//{//实参传给形参是，形参其实是实参的一份临时拷贝，对形参的修改是不会改变实参的
//	int tmp = x;
//	x = y;
//	y = tmp;
//}//传值调用：函数的形参和实参分别占有不同的内存块，对形参的修改不会影响实参
//void change2(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}//传址调用：把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
////这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量
//int main()
//{
//	int a = 2;
//	int b = 4;//a，b为实参
//	//change(a, b);//此处并没有交换a，b的值，原因是a，b的地址与函数参数x，y的地址不同，函数只是把a，b的值赋给了x，y
//	//x，y是函数内的参数，与函数外的a，b并没有建立联系，因为他没有返回值。
//	change2(&a, &b);//再创建个函数传入a，b的地址，这样程序运行进函数后电脑还能通过地址找到a，b
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}

//写一个函数来找出两个数的最大值
//float max(float x, float y)
//{
//	return ((x > y) ? x : y);
//}
//int main()
//{
//	float a, b, c;
//	printf("输入两个数字：");
//	scanf("%f%f", &a, &b);
//	c=max(a, b);
//	printf("%f", c);
//	return 0;
//}

//memset内存设置函数
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);//memset(ptr，int value，num)，第一个参数是地址，第二个参数是值，第三个参数是数字
//	                       //意思是把值替换地址所指向的值，替换的是地址值的前num个字节
//	//此处是把arr的前五个字节替换成*，替换时字符转换为ASCII码值，也是int类型，但是不能替换字符串，字符串不是int类型
//	printf("%s\n", arr);
//	return 0;
//}


//strcpy的用法
//int main()
//{
//	char arr[] = "hello";
//	char arr2[10] = "#########";
//	strcpy(arr2, arr);//将arr2为目标字符串，arr为源头字符串，把arr的内容拷贝进arr2中，包括结束字符\0
//	printf("%s\n", arr2);
//	return 0;
//}