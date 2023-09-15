#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//上节课我们介绍了字符串函数，字符串函数是专门用来操作字符串的
//比如strcmp，比较两个字符串。strcpy，拷贝一个字符串。那么如果要拷贝其他类型的数组（整型，浮点型，结构体），又该怎么办？
//所以这一节我们要学习memcpy，memmove，memcmp，memset这几个函数
//memcpy是内存拷贝，可以拷贝各种类型的数组。由于要接收各种类型的参数，并且返回，所以memcpy返回的是void*类型
//void* memcpy(void* destination,const void* source,size_t num) ,其中num是要拷贝的字节数	
//struct stu
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	assert(dest && src);
//	void* start = dest;
//	//void*可以接收任意类型的指针，但是无法解引用访问。
//	//所以这里要通过指针dest访问到数组的内容，又不知道是什么类型，就要强制转化为char* 类型
//	//参数中有size_t num，给出了需要拷贝的字节，转为char*后那么就拷贝num次就可以了
//	while (num--)
//	{
//		*(char*)dest = *(char*)src; //交换完一个字节后dest和src要++了
//		//但是如果不强制类型转换的话dest和src是不能++的，所以要++的话还是要自增
//		++(char*)dest, ++(char*)src;//这里不能后置++，因为优先级：后置++ > 强制类型转换 > 前置++
//	}
//	return start;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5};
//	int arr2[5] = { 0 };
//	struct stu s[] = { {"wangwu",18},{"zhangsan",20} };
//	struct stu s2[2] = { 0 };
//	//模拟实现
//	my_memcpy(s2, s, sizeof(s));
//	//memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}
//在使用memcpy时，如果要把一个数组的一串数字拷贝到同一个数组的另一个地方，那么就会失败
//例：int arr[]={1,2,3,4,5,6,7,8,9,10}，把arr中的1，2，3，4，5拷贝到3，4，5，6，7的位置
//如果用memcpy，那么写法为memcpy(arr+2,arr,20)，如果是这样，那么会出现覆盖的情况，输出结果为1，2，1，2，1，2，1，8，9，10
//为了解决这个情况，有一个专门的库函数叫做memmove

//memmove
//char* memmove(void* dest,const char* src,size_t num)

void* my_memmove(void* dest, const char* src, size_t num)
{
	assert(dest && src);
	void* start = dest;
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest, ++(char*)src;
		}
	}
	else if (dest > src)
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return start;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//memcpy(arr + 2, arr, 20);  在vs2022编译器中，memcpy也能处理内存重叠的情况
	//memmove(arr + 2, arr, 20);//处理内存重叠的情况
	//C语言标准规定，memcpy只要处理不重叠的内存拷贝就可以。memmove处理重叠的内存拷贝
	//memmove处理重叠或者不重叠的内存拷贝都可以，但是在vs编译器中，memcpy也具有处理内存重叠的功能
	
	//模拟实现
	my_memmove(arr, arr+2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}