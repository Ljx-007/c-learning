#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strcmp--�Ƚ��ַ���  int strcmp(char* str1,char* str2)
//���str1С��str2������С��0��ֵ   ��VS�����������С��0��ֵ��-1��
//���str1����str2������0					
//���str1����str2�����ش���0��ֵ   ��VS���������������0��ֵ��1��
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
//���Ҫ����һ������0����С��0�����֣�������1��-1��������ôд
//int my_strcmp(char* p1, char* p2)
//{
//	while (*p1 == *p2)  //�����Ⱦͽ���ѭ��������Ⱦ��˳�ѭ��
//	{
//		if (*p1 == '\0')  //���p1��p2��������'\0'����ʱ�Ѿ������������ַ����ˣ�while�����ж���Ƚ���ѭ����˵�����ַ������
//			return 0;          //����0
//		p1++, p2++;
//	}
//	return (*p1 - *p2);  //�����ʱ���p1>p2��*p1-*p2��Ȼ����0�����p1<p2,*p1-*p2��ȻС��0
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "qwert";      //p2>p1
//	//strcmp(p1, p2);  //strcmp�Ƚϵ��������ַ����Ķ�Ӧ�ַ���ASCII��ֵ�������һ���ַ���ͬ������Ƚϣ�ֱ���Ƚϳ����Ϊֹ
//	int ret = my_strcmp(p1, p2);
//	printf("%d", ret);
//	return 0;
//}

//���������Լ���һ�ڵ����ݽ��ܵĶ���û�г������Ƶ��ַ���������Ҳ����˵����ִ�е�\0�Ż�ֹͣ������һ����������գ����������ܳ����ܵ����Ƶ��ַ���

//strncpy--������strcpy��ͬ�����Ƕ���һ������size_t num������Ҫ�������ֽ���
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (num && (*dest++ = *src++) != '\0')  //���ﲻ��д��while(num--&&(*dest++=*src++))  �ᱨ����֪��Ϊʲô
//		                                     //����Ҫ�涨(*dest++ = *src++) != '\0'�ſ���
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
//	//strncpy(p1, p2, 4);  //�������˼��Ҫ��p2������p1�У�����ֻ����ǰ�ĸ��ֽ�
//	//����涨�������ֽ���������p2�ĳ��ȣ���ô��p2������ȥ���Զ���\0��ֱ���ﵽ�涨���ֽ���
//	//ģ��ʵ��
//	my_strncpy(p1, p2, 6);
//	return 0;
//}


//strncat--׷���ַ������г������ƣ��ܹ涨׷�ӵ��ַ�����,׷������Զ���һ��\0
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
	//strncat(arr1, arr2, 8); //����涨׷�ӵ��ַ�������Ҫ׷�ӵ��ַ������Ȼ�������ôֻ��׷�ӵ��ַ����ĳ��ȣ����������\0ֱ���ﵽ�涨��Ϊֹ
	//ģ��ʵ��
	my_strncat(arr1, arr2, 8);
	return 0;
}