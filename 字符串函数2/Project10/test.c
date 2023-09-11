#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strcmp--比较字符串  int strcmp(char* str1,char* str2)
//如果str1小于str2，返回小于0的值   （VS编译器下这个小于0的值是-1）
//如果str1等于str2，返回0					
//如果str1大于str2，返回大于0的值   （VS编译器下这个大于0的值是1）
//int my_strcmp(const char* p1,const char* p2)
//{
//	while (*p1++ && *p2++)
//	{
//		if (*p1 > *p2)
//			return 1;
//		if (*p1 < *p2)
//			return -1;
//	}
//	return 0;
//}
//如果要返回一个大于0或者小于0的数字，而不是1或-1，可以这么写
//int my_strcmp(char* p1, char* p2)
//{
//	while (*p1 == *p2)  //如果相等就进入循环，不相等就退出循环
//	{
//		if (*p1 == '\0')  //如果p1，p2都遍历到'\0'，此时已经遍历完整个字符串了，while条件判断相等进入循环，说明两字符串相等
//			return 0;          //返回0
//		p1++, p2++;
//	}
//	return (*p1 - *p2);  //不相等时如果p1>p2，*p1-*p2自然大于0。如果p1<p2,*p1-*p2自然小于0
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "qwert";      //p2>p1
//	//strcmp(p1, p2);  //strcmp比较的是两个字符串的对应字符的ASCII码值，如果第一个字符相同就往后比较，直到比较出结果为止
//	int ret = my_strcmp(p1, p2);
//	printf("%d", ret);
//	return 0;
//}

//以上内容以及上一节的内容介绍的都是没有长度限制的字符串函数，也就是说函数执行到\0才会停止。会有一定的溢出风险，接下来介绍长度受到限制的字符串

//strncpy--作用与strcpy相同，但是多了一个参数size_t num，就是要拷贝的字节数
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (num && (*dest++ = *src++) != '\0')  //这里不能写成while(num--&&(*dest++=*src++))  会报错，不知道为什么
//		                                     //必须要规定(*dest++ = *src++) != '\0'才可以
//	{
//		num--;
//	}
//	if (num != 0)
//	{
//		while (num--)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char p1[10] = "abcdefghi";
//	char p2[] = "ljx";
//	//strncpy(p1, p2, 4);  //这里的意思是要把p2拷贝到p1中，但是只拷贝前四个字节
//	//如果规定拷贝的字节数超过了p2的长度，那么将p2拷贝过去后自动补\0，直到达到规定的字节数
//	//模拟实现
//	my_strncpy(p1, p2, 6);
//	return 0;
//}


//strncat--追加字符串，有长度限制，能规定追加的字符个数,追加完后自动加一个\0
char* my_strncat(char* dest, const char* src, size_t num)
{
	char* start = dest;
	while (*dest)
	{
		dest++;
	}
	while (num&&(*src))
	{
		*dest++ = *src++;
		num--;
	}
	return start;
}
int main()
{
	char arr1[30] = "abcdefgh";
	char arr2[] = "ljx";
	//strncat(arr1, arr2, 8); //如果规定追加的字符个数比要追加的字符串长度还长，那么只会追加到字符串的长度，不会继续补\0直到达到规定数为止
	//模拟实现
	my_strncat(arr1, arr2, 8);
	return 0;
}