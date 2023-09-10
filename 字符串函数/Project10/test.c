#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串函数

//strcat--追加一个字符串
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest++)
	{
		;
	}
	while (*dest++=*src++)
	{
		;
	}
	return ret;
}
int main()
{
	//strcat(char *dest,const char* src)
	//strcat原理：源头字符串找到目标字符串中的\0，用源头字符串代替目标字符串中的\0往后追加，且源字符串必须包含\0
	char arr1[30] = "hello";  //被追加的字符串空间一定要够大，不然arr2追加到arr1会放不下，报错
	char arr2[] = "world";
	strcat(arr1, arr2);
	return 0;
}



//strcpy--拷贝字符串到另一个字符串

//strcpy的返回类型为char*，是拷贝目标字符串dest的首元素地址
//char* my_strcpy(char* dest,const char* src)
//{
// char* ret=dest;
//	assert(dest), assert(src);
//	while (*dest++=*src++)//拷贝arr2中的字符串到arr1中，包含\0
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "ljx";
//	//strcpy(arr1, arr2);  //strcpy在拷贝时会把\0也拷贝过去
//	my_strcpy(arr1, arr2);
//	return 0;
//}


//strlen--计算字符串长度（不含\0）
//int main()
//{
//	if ((strlen("abc") - strlen("abcdef")) > 0)
//		printf("hehe\n");  //这里程序打印的是hehe而不是haha，这是因为strlen函数返回的类型是size_t而不是int
//	 //size_t在c中的定义是unsigned int，unsigned int被重定义为size_t
//	//所以两个strlen相减得到的不会是负数，仍然是正数
//	else
//		printf("haha\n");
//	return 0;
//}