#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//��ϰ3��дһ���������ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת����ַ���
//�������s1=AABCD��s2=BCDAA������1
//s1=abcd��s2=ABCD������0
//AABCD����һ���ַ�ΪABCDA
//AABCD���������ַ�ΪBCDAA
//AABCD����һ���ַ�ΪDAABC
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




//��ϰ2��ʵ��һ�����������������ַ����е�k���ַ�
// ���磺ABCD����һ���ַ����BCDA
//       ABCD���������ַ����CDAB
//����һ������ѭ�����
//void left_move(char ch[], int k)
//{
//	assert(ch); //�������һ�£����arr�ǿ�ָ�룬��ôֵΪ0���ͻᱨ�����ǿ�ָ��ֵΪ1��������
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

//��������������ת��
//Ҫ�����ַ���ABCDEF������2���ַ���������AB
//�ǾͰ�AB����CDEF�����ٺϲ�,���������
//AB CDEF->BA FEDC->CDEFAB
//Ҫʵ���������������Ҫ��Ҫ��ת���ַ��������ַ����ֿ���Ȼ�����������õ�ַ����ʵ��
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
//	reverse(ch, ch + k - 1);//������ߵ��ַ�
//	reverse(ch + k, ch + strlen(ch) - 1);//�����ұߵ��ַ�
//	reverse(ch, ch + strlen(ch) - 1);//���������ַ���
//}
//int main()
//{
//	int k;
//	char ch[] = "ABCDEF";
//	printf("�����ַ���%s,��Ҫ���������ַ���", ch);
//	scanf("%d", &k);
//	printf("����ǰ��%s\n", ch);
//	left_move(ch,k);
//	printf("������%s", ch);;
//	return 0;
//}




//��ϰ1��ģ��qsort����ʵ��һ��ͨ�õ�ð������
//void Swap(char* p1, char* p2,int width)
//{
//	while (width)
//	{
//		char tmp = *p1;     //�˴�����д��char* tmp=p1  �����p1����ָ�����tmp��tmpָ��ĵ�ַ����p1ָ��ĵ�ַ��p1��tmp�ǵȼ۵�
//		*p1 = *p2;                 //     *p1=*p2      �˴�p1��ָ������ݱ��޸ĳ�p2��ָ������ݣ�tmpָ���������ʵҲ���޸��ˣ���Ϊp1��tmp�ǵȼ۵�
//		*p2 = tmp;                   //   *p2=*tmp    ���������ٰ�p2ָ��������޸ĳ�tmpָ���������ʵ�൱��û���޸�p2ָ�������
//		p1++, p2++,width--; // ���д��char* tmp=p1,�������Ͱ�p1��p2ָ������ݾ��޸ĳ�һ������,��ӡ�Ľ������1 1 1 1 1 1
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