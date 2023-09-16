#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//继上节所讲，memcpy函数是内存拷贝，可以拷贝不同类型的数组
//memmove是可以拷贝内存重叠的情况（在VS编译器底下，memcpy也可以做到）
//模拟实现
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	char* start = dest;
//	while(num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest, ++(char*)src;
//	}
//	return start;
//}//模拟实现的my_memcpy是不能拷贝内存重叠的情况的
////memmove可以处理内存重叠情况，这里模拟实现以下memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* start = dest;
//	if (dest < src)
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest, ++(char*)src;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return start;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int arr2[6] = { 0 };
//	my_memmove(arr+2, arr, 12);
//	return 0;
//}

//memcmp--比较任意两个同类型的数组
//int memcmp(const void* ptr1,const void* ptr2,size_t num)  num为要比较的字节数
//如果ptr1 > ptr2，返回一个大于0的数
//如果ptr1 = ptr2，返回0
//如果ptr1 < ptr2，返回一个小于0的数
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret=memcmp(arr1, arr2, 12);
//	printf("%d", ret);
//	return 0;
//}

//memset -- 内存设置
//void* memset(void* dest ,int c ,size_t num)  其中c指的是要设置的字符，num为要设置的字节数
int main()
{
	int arr[10] = { 0 };
	char ch[5] = { 0 };
	memset(ch, '*', 5);
	//memset(arr, 1, 40);//这里注意，这行代码的意思是把1放入一个字节内，一共放40个字节，并不是把10个1放入数组中
	return 0;
}