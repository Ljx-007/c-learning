#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//补充上节内容：
//int main()
//{
//	//realloc也可以实现malloc的功能
//	//realloc传空指针时等价于malloc(40)
//	int* p = realloc(NULL, 40);
//	return 0;
//}
 

//接上节常见的动态内存开辟错误
//4.使用free释放动态开辟内存的一部分
//例：
//int main()
//{
//	int* p = (int*)malloc(40);//申请十个整型的空间
//	for (int i = 0; i < 10; i++)
//	{
//		*p++ = i;  //p++，不再指向原来的位置
//	}
//	free(p), p = NULL;  //此时程序挂掉了，因为p的位置已经变了，指向的不再是动态开辟的全部内存，而是一小部分
//	return 0;
//}

//5.对同一块动态内存多次释放：如果对于一个动态开辟内存多次释放，那么程序就会挂掉
//如果不记得对于一块动态内存是否释放，养成在释放时把指针置为NULL的习惯，那么后面再进行多次释放free也不会有任何行为，因为free(NULL)不做任何动作

//6.动态开辟内存忘记释放（内存泄漏）
//如果写的代码总是在开辟空间，不释放，那么电脑的内存资源会被一直占用，造成内存泄漏，内存用尽时电脑就会卡死，所以要有借有还

//笔试题
//以下代码运行后的结果为？
char* Getmemory(void)
{
	char p[] = "hello world";  //这里p的创建是在Getmemory这个函数内部的，属于局部变量
	//且内存空间在栈区，返回栈区空间的地址容易发生错误，因为栈区内容会被销毁，如果是在静态区或者堆区则不会出现这样的情况
	return p;  //p指的是"hello world"这个字符串的首地址
}
void Test(void)
{
	char* str = NULL;
	str = Getmemory();  //这里p被赋给了str，说明p所指向的首元素地址，str也指向了,"hello world"这个常量字符串的地址并没有发生变化
	 //               只是str这个指针也和p一样指向了这个常量字符串的首元素地址
	//出了Getmemory这个函数"hello world"这个常量字符串就被销毁了，注意，不是p被销毁了，p指向的是这个常量字符串的地址，p被返回出来了，没被销毁
	//被销毁的是"hello world"这个常量字符串，p和str仍然指向其所在的地址，只不过地址的内容被销毁了，取而代之的不知道是什么
	//所以寻址str后打印出来的内容是一个随机值
	printf(str);  //相当于printf("%s",str)
}
int main()
{
	Test();  //代码运行的结果为一个随机值
	return 0;
}