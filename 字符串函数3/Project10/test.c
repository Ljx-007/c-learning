#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strncmp--字符串比较，限定字符长度的比较
//int strncmp(const char* str1, const char* str2, size_t count);
//count是要比较多少个字节个数
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqwer";
//	//int ret = strcmp(p1, p2);
//	int ret = strncmp(p1, p2,4);
//	printf("%d", ret);
//	return 0;
//}


//strstr--查找字符串
//char *strstr(const char *string,const char *strCharSet)
//string:被查找的字符串  strCharSet:要查找的字符串
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	if (*p2 == '\0') //如果p2是一个空字符串，那么返回p1
		return (char*)p1;
	//可能会出现p1="abbbcdef" ,p2="bbc"这样的情况，如果遍历一次就会出现p2是p1的子串却返回NULL的情况
	//这是就要从第一个b遍历，遍历找不到子串后继续往第二个b遍历，看是否能找到，这是要引入cur这个变量
	//从cur开始遍历还需要1个指针来遍历，cur作为头，往后遍历，所以要引入s1这个变量
	//p2字符串也需要遍历，所以引入s2这个变量
	char* s1=(char*) p1;
	char* s2 = (char*)p2;  //s1和s2是用来遍历p1和p2的，来查找两个字符是否相等
	char* cur = (char*)p1;  //cur是用来记录找子串后要返回的p1中p2的首地址字符的地址
	while (*cur)
	{
		s1 = cur;  //一次循环之后要重置s1，让s1重新从cur开始遍历
		s2 = (char*)p2;   //重置s2
		//以p1="abbbcdef" 
		//  p2="bbc" 为例
		while (*s1&&*s2&& (*s1 == *s2))//当s1和s2指向的都不是\0且指向的字符相等时进入循环
		{
			s1++, s2++;
		}                 //如果不相等，不进入循环，cur+1，重新从cur遍历
		if (*s2 == '\0')  //如果*s2=='\0'，说明p2在p1中已经找到了，此时cur代表了p1中p2的首地址字符的地址
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char* p1 = "abbbcdef";
	char* p2 = "bbc";
	//char* ret=strstr(p1, p2);//在p1中查找p2是否存在，如果存在，就会返回d的地址,往后打印出来就是defabcdef而不是def
	//模拟实现
	char* ret=my_strstr(p1, p2);
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s", ret);
	return 0;
}