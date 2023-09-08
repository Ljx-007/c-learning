#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//练习3：写一个函数，判断一个字符串是否为另一个字符串旋转后的字符串
//例如给定s1=AABCD和s2=BCDAA，返回1
//s1=abcd和s2=ABCD，返回0
//AABCD左旋一个字符为ABCDA
//AABCD左旋两个字符为BCDAA
//AABCD右旋一个字符为DAABC
int isRightmove(char* ch, char* arr)
{
	assert(ch),assert(arr);
	for (int j = 0; j < strlen(ch); j++)
	{
		for (int i = strlen(ch); i >0; i--)
		{
			char tmp = ch[i];
			ch[i] = ch[i - 1];
			ch[i - 1] = tmp;
		}
		if (strcmp(ch, arr) == 0)
			return 1;
	}
	return 0;
}
int isLeftmove(char* ch, char* arr)
{
	assert(ch), assert(arr);
	for (int j = 0; j < strlen(ch); j++)
	{
		for (int i = 0; i < strlen(ch) - 1; i++)
		{
			char tmp = ch[i];
			ch[i] = ch[i + 1];
			ch[i + 1] = tmp;
		}
		if (strcmp(ch, arr) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char ch[] = "AABCD";
	char arr[] = "DAABC";
	int num1 = isLeftmove(ch, arr);
	strcpy(ch, "AABCD"), strcpy(arr, "BCDAA");
	int num2= isRightmove(ch, arr);
	int ret = num1 + num2;
	if (num1 > 0)
		printf("Yes");
	else
		printf("No");
	return 0;
}




//练习2：实现一个函数，可以左旋字符串中的k个字符
// 例如：ABCD左旋一个字符变成BCDA
//       ABCD左旋两个字符变成CDAB
//方法一：暴力循环求解
//void left_move(char ch[], int k)
//{
//	assert(ch); //这里断言一下，如果arr是空指针，那么值为0，就会报错。不是空指针值为1，不报错
//	assert(k <= strlen(ch) && k >= 0);
//	for (int j = 0; j < k; j++)
//	{
//		for (int i = 0; i < strlen(ch) -1; i++)
//		{
//			char tmp = ch[i];
//			ch[i] = ch[i + 1];
//			ch[i + 1] = tmp;
//		}
//	}
//}

//方法二：三部翻转法
//要左旋字符串ABCDEF，左旋2个字符，即左旋AB
//那就把AB逆序，CDEF逆序，再合并,最后再逆序
//AB CDEF->BA FEDC->CDEFAB
//要实现这个方法，就需要把要旋转的字符与其他字符串分开，然后逆序，这里用地址可以实现
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--, left++;
//	}
//}
//void left_move(char ch[], int k)
//{
//	assert(ch);
//	reverse(ch, ch + k - 1);//逆序左边的字符
//	reverse(ch + k, ch + strlen(ch) - 1);//逆序右边的字符
//	reverse(ch, ch + strlen(ch) - 1);//逆序整个字符串
//}
//int main()
//{
//	int k;
//	char ch[] = "ABCDEF";
//	printf("对于字符串%s,想要左旋几个字符？", ch);
//	scanf("%d", &k);
//	printf("左旋前：%s\n", ch);
//	left_move(ch,k);
//	printf("左旋后：%s", ch);;
//	return 0;
//}




//练习1：模仿qsort函数实现一个通用的冒泡排序
//void Swap(char* p1, char* p2,int width)
//{
//	while (width)
//	{
//		char tmp = *p1;     //此处不能写成char* tmp=p1  这里把p1赋给指针变量tmp，tmp指向的地址就是p1指向的地址，p1和tmp是等价的
//		*p1 = *p2;                 //     *p1=*p2      此处p1所指向的内容被修改成p2所指向的内容，tmp指向的内容其实也被修改了，因为p1和tmp是等价的
//		*p2 = tmp;                   //   *p2=*tmp    所以这里再把p2指向的内容修改成tmp指向的内容其实相当于没有修改p2指向的内容
//		p1++, p2++,width--; // 如果写成char* tmp=p1,这里最后就把p1和p2指向的内容就修改成一样的了,打印的结果就是1 1 1 1 1 1
//	}
//}
//void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//		}
//	}
//}
//int int_cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), int_cmp);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}