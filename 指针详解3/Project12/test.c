#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ѧϰ����ʱд��ð�����򣬵�������ð������ֻ�������������ݣ�c�����ṩ��һ����qsort�Ŀ⣬���������κ��������͵����ݣ���Ҫ�Լ�ȥ�о�
//��������Լ�дһ���������κ��������͵����ݣ���Ҫ�õ��ص������ĸ���½ڿ������о�
void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int arr[] = { 5,8,9,2,4,1,3,10,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}




//int Add(int, int);
//int Sub(int, int);
//int Mul(int, int);
//int Div(int, int);
////�ص��������ص���������ͨ������ָ����õĺ���������Ѻ�����ָ����Ϊ����������һ�������������ָ�뱻������������ָ����ʱ����ָ�����ͱ���Ϊ�ص�����
//
//
//
////ָ����ָ�������ָ��
//int main()
//{
//	int(*pf)(int, int);//����ָ��
//	int(*p[4])(int, int);//����һ������ָ������
//	int(*(*pp)[4])(int, int) = &p;//����һ��ָ����ָ�������ָ��
//	//pp����*��ϣ�˵��pp��һ��ָ�롣ָ���������Ϊint(*)[4](int,int)�ĺ���ָ�����飬˵��pp��һ������ָ��
//	//�������ĸ�Ԫ�أ�ÿ��Ԫ������Ϊ����ָ��
//	return 0;
//}
//



//�ú���ָ������дһ��������
//void menu()
//{
//	printf("**************************\n");
//	printf("**********������**********\n");
//	printf("******1.add    2.sub******\n");
//	printf("******3.mul    4.div******\n");
//	printf("*********0.�˳�***********\n");
//	printf("**************************\n");
//}
//
//int main()
//{
//	int input;
//	int(*parr[])(int, int) = { 0,Add,Sub,Mul,Div };//��Ϊ������±��0��ʼ����menu��Ҫ���˼��㷽����Ӧ�����֣��������������һ��Ԫ����0��ռ��
//	                                           //Ŀ�ľ�����Add���±�Ϊ1��Sub���±�Ϊ2���Դ�����
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			int x, y;
//			printf("������Ҫ���������:");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", parr[input](x, y)); //����ʹ�ú���ָ��������Ժܺõı����߳��Ĵ��룬�����Ҫ��ӱ�ļ��㷽�����ں���ָ�����������Ӧ�ĺ�������
//		}            
//		else if (input == 0)
//		{
//			printf("���˳�!");
//		}
//		else
//			printf("�����������������\n");
//	} while (input);
//	return 0;
//}




//��switch��case���д�����ļ���������������ӣ������������Ҫ�����ļ��㷽���簴λ�룬��λ�򣬰�λ���ȣ���Ҫ��ͣ�����case���
// ���ԣ������ú���ָ���������Ż�����㷨
//void calculator(int(*p)(int, int))
//{
//	int x,  y;
//	printf("�������������ֽ������㣺");   //�������װһ��caculator()�����Ļ�����ôÿһ��case�����涼Ҫд��printf��scanf
//	scanf("%d%d", &x, &y);            //����ÿһ��case�����Ψһ��ͬ��ֻ�ǵ��õĺ�����ͬ
//	                     //��ô�Ϳ����Ե��õĺ���Ϊ������װһ��������case���ʹ��ʱ���������������
//	printf("%d\n",p(x, y));
//}
//int main()
//{
//	int input = 0;
//	int x, y;
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calculator(Add);              //���ﱻcalculator()���õ�Add��Sub��Mul��Div�������ǻص�����
//			break;
//		case 2:
//			calculator(Sub);
//			break;
//		case 3:
//			calculator(Mul);
//			break;
//		case 4:
//			calculator(Div);
//			break;
//		case 0:
//			printf("���˳�\n");
//			break;
//		default:
//			printf("�����������������\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}