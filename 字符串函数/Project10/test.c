#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//�ַ�������

//strcat--׷��һ���ַ���
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
	//strcatԭ��Դͷ�ַ����ҵ�Ŀ���ַ����е�\0����Դͷ�ַ�������Ŀ���ַ����е�\0����׷�ӣ���Դ�ַ����������\0
	char arr1[30] = "hello";  //��׷�ӵ��ַ����ռ�һ��Ҫ���󣬲�Ȼarr2׷�ӵ�arr1��Ų��£�����
	char arr2[] = "world";
	strcat(arr1, arr2);
	return 0;
}



//strcpy--�����ַ�������һ���ַ���

//strcpy�ķ�������Ϊchar*���ǿ���Ŀ���ַ���dest����Ԫ�ص�ַ
//char* my_strcpy(char* dest,const char* src)
//{
// char* ret=dest;
//	assert(dest), assert(src);
//	while (*dest++=*src++)//����arr2�е��ַ�����arr1�У�����\0
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "ljx";
//	//strcpy(arr1, arr2);  //strcpy�ڿ���ʱ���\0Ҳ������ȥ
//	my_strcpy(arr1, arr2);
//	return 0;
//}


//strlen--�����ַ������ȣ�����\0��
//int main()
//{
//	if ((strlen("abc") - strlen("abcdef")) > 0)
//		printf("hehe\n");  //��������ӡ����hehe������haha��������Ϊstrlen�������ص�������size_t������int
//	 //size_t��c�еĶ�����unsigned int��unsigned int���ض���Ϊsize_t
//	//��������strlen����õ��Ĳ����Ǹ�������Ȼ������
//	else
//		printf("haha\n");
//	return 0;
//}