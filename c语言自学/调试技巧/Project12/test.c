#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//自己写一个strcpy函数
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		*dest++;
//		*src++;
//	}
//	//要把arr2中所有的元素全部拷贝进arr1中，循环结束时只拷贝了ljx三个元素，并没有拷贝\0
//	*dest = *src; //这一步是拷贝\0
//}
//优化代码
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)//利用后置++先使用*dest和*src在遍历字符串
//	{                      //while条件为0时才结束循环，而遍历至'\0'时对应的ACRII码值为0，在拷贝\0 后结束循环
//		;
//	}
//}
//如果给函数传NULL一个空指针，那么函数无法处理，所以要继续优化代码
//void my_strcpy(char* dest, char* src)
//{
//	if (dest != NULL && src != NULL)//新增一个条件判断dest和src不是空指针
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
//输入空指针后，上述代码规避了空指针这个错误，并不完善，要指出代码中哪里出错，所以继续优化代码
//void my_strcpy(char* dest, char* src)
//{	//发现问题偶会把问题抛出，利于我们发现问题出在哪里
//	//assert函数--断言，使用它需要引入头文件<assert.h>
//	assert(dest != NULL);//assert括号内放的表达式为真，则什么都不发生，表达式为假则报错
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//如果在写代码的过程中，将*dest++ = *src++写成*src++ =*dest++，将目的字符串拷贝到源头字符串上，不容易被发现，所以要继续优化代码
//void my_strcpy(char* dest, const char* src)//在源上加一个const，把源设置为不可修改，就可以避免发生这样的错误
//{	//const在最开始说过是给变量赋上常量属性，常量无法修改
//	assert(dest != NULL);//assert括号内放的表达式为真，则什么都不发生，表达式为假则报错
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//对于一个指针变量p来说，修饰指针时如果放在*号的左边--const int *p，修饰的是*p,也就是说无法通过*p来修改p指向的值
//如果const在*的右边--int* const p，修饰的是指针变量p，无法再将别的地址赋到p的身上
//代码还可以再优化

char* my_strcpy(char* dest, const char* src) //把这个函数的返回值改为char* 类型，返回的是目的字符串的首元素地址
{	
	char* ret = dest;//因为dest经过后续++操作后指向的是最后一个元素了，而打印字符串时需要的是首元素地址，于是先用ret存放首元素地址
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	//等到dest指向的字符串被修改完后，再返回他的首元素地址，打印出的结果就是拷贝后的字符串了
	return ret;
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "ljx";
	//my_strcpy(arr1, arr2);
	//printf("%s", arr1);
	//经过最后一步优化后，my_strcpy有返回值了，可以直接进行打印
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}