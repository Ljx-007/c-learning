#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//����һ���������飬��������˳��ʹ����ȫ��λ��ż��ǰ��
void my_sort(int arr[],int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] % 2 == 0)
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;			
			}
		}
	}
}
int main()
{
	int arr[] = { 1,3,5,6,7,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//ģ��ʵ��strcpy����
//void my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	if (src != NULL && dest != NULL)
//	{
//		while(*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
//int main()
//{
//	char pa[] = "*********";
//	char pb[] = "ljx666";
//	//strcpy(pa, pb);
//	my_strcpy(pa, pb);
//	printf("%s", pa);
//}




//ģ��ʵ��strlen����
//����һ���ݹ�
//int my_strlen(char ch[])
//{
//	if (*ch != '\0')
//		return 1 + my_strlen(ch + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char ch[] = "abcdef";
//	printf("%d", my_strlen(ch));
//	return 0;
//}


//��������
//int my_strlen(char ch[])
//{
//	int count = 0;
//	while (*ch != '\0')
//	{
//		count++;
//		ch++;
//	}
//	return count;
//}
//int main()
//{
//	char ch[] = "abcdefg";
//	printf("%d", my_strlen(ch));
//	return 0;
//}



//����ˮ���⣺1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ���ܹ������ƿ��ˮ�������ʵ�֣�
//����һ���ݹ�ʵ��
//int cmpt(int empty)
//{
//	if (empty > 1) //��ƿ��Ҫ����1ƿ���ܻ���ˮ
//	{
//		if (empty % 2 == 1) //�����ƿ��������������Զ໻һƿ��ˮ����Ϊ3����ƿ�ܻ���ƿ��ˮ�������ƿ�ܻ�3ƿ��ˮ���Դ����ƣ�2k-1����ƿ���ܻ�(2k-1)/2+1ƿ��ˮ
//			return empty + 1 + cmpt(empty / 2);
//		else    //�����ƿ����ż������ô�͸պ��ܻ���ƿ��һ�����ˮ
//			return empty + cmpt(empty / 2);
//	}
//	else //��ƿ��С�ڵ���1���ܻ���ˮ�����Է���1
//		return 1;
//}
//int main()
//{
//	int money = 50;
//	int water = 1;
//	int empty=cmpt(money / water);
//	printf("%d", empty);
//	return 0;
//}

//��������
//int main()
//{
//	int money = 20;
//	int water = 1;
//	int empty = money / water; //��ƿ����
//	int total = empty; //�ȹ�����ˮƿ��
//	while (empty > 1)
//	{
//		total += empty / 2;//������ƿ��һƿ��ˮ���������ںȹ�����ˮƿ����
//		empty= empty / 2+empty%2; //������ټ����ƿ����������ƿ��������ʱ����һƿ������Ҫ����empty%2
//	}
//	printf("%d", total);
//  return 0;
//}

//��������
//int main()
//{
//	int money = 20;
//	int water = 1;
//	int total;
//	if (money == 0)
//		total = 0;     
//	else
//		total = 2 * money - 1; //һƿ��ˮ1��Ǯ��������ƿ��һƿ��ˮ����1��Ǯ����������ƿ����ƿֵ0.5��Ǯ����ôһƿ��ˮ�����ˮ��ֵ0.5��Ǯ
//	                        //20�������40��ƿ�������ˮ����40����ƿ��������ˮ�����뿪ƿ�Ӷ����ڣ��������һ��������һ����ƿ����װ��ˮ�������ܻ�������39ƿ
//	                   //����������򵽵���ˮ��2����Ǯ���ټ�1
//	printf("%d", total);
//	return 0;
//}