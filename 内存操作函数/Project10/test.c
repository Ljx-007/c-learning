#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//���Ͻ�������memcpy�������ڴ濽�������Կ�����ͬ���͵�����
//memmove�ǿ��Կ����ڴ��ص����������VS���������£�memcpyҲ����������
//ģ��ʵ��
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
//}//ģ��ʵ�ֵ�my_memcpy�ǲ��ܿ����ڴ��ص��������
////memmove���Դ����ڴ��ص����������ģ��ʵ������memmove
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

//memcmp--�Ƚ���������ͬ���͵�����
//int memcmp(const void* ptr1,const void* ptr2,size_t num)  numΪҪ�Ƚϵ��ֽ���
//���ptr1 > ptr2������һ������0����
//���ptr1 = ptr2������0
//���ptr1 < ptr2������һ��С��0����
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret=memcmp(arr1, arr2, 12);
//	printf("%d", ret);
//	return 0;
//}

//memset -- �ڴ�����
//void* memset(void* dest ,int c ,size_t num)  ����cָ����Ҫ���õ��ַ���numΪҪ���õ��ֽ���
int main()
{
	int arr[10] = { 0 };
	char ch[5] = { 0 };
	memset(ch, '*', 5);
	//memset(arr, 1, 40);//����ע�⣬���д������˼�ǰ�1����һ���ֽ��ڣ�һ����40���ֽڣ������ǰ�10��1����������
	return 0;
}