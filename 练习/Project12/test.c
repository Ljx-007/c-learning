#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ҵ
int i; //ȫ�ֱ�������ʼ��Ĭ��Ϊ0
int main()
{
	i--;//i=-1
	if (i > sizeof(i))//sizeof()--�������/������ռ�ڴ��С���ص����޷�����>=0
		//����i��ת�����޷�������-1ת�����޷�������һ���ǳ�������֣������������һ����������ӡ>��
		printf(">\n");
	else
		printf("<\n");
	return 0;
}





//��ϰ3���������飬������A�е�����������B�е����ݽ���������һ����
//void change(int arr1[], int arr2[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int tmp = 0;
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	change(arr1, arr2,sz);
//	Print(arr1, sz);
//	Print(arr2, sz);
//	return 0;
//}





//��ϰ2������һ���������飬��ɶ�����Ĳ���
//1��ʵ�ֺ���init()����ʼ������Ϊȫ0
//2��ʵ��print()����ӡ����ÿ��Ԫ��
//3��ʵ��reverse()������������������
//void Init(int arr[10], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		right--, left++;
//	}
//}
//int main()
//{
//	int arr[10] = { 5,4,8,9,2,1,6,4,7,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Init(arr,sz);
//	Print(arr, sz);
//	reverse(arr, sz); //�������飬����������Ϊ{10��7��4��6��1��2��9��8��4��5}
//	Print(arr, sz);
//}



//��ϰ1��ð������
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int flag =1;
//		for (int j = 0; j < sz - i-1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//int main()
//{
//	int arr[] = { 10,7,8,6,3,5,4,2,3,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//  return 0;
//}