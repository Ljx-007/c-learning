#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"add.h"   //�����Լ�������ͷ�ļ�ʱ��˫���ţ��⺯���ü�����
//������Ƕ��ʹ�ú����ӷ���
//int Add(int, int);//����������ֻ���������������������ͣ��������ͼ��ɣ�������������治���ڣ��޹ؽ�Ҫ��

//һ�㺯�����������Ƿ���ִ�е���Դ�ļ��У����Ǵ���һ��Դ�ļ���ͷ�ļ����γ�һ��ģ��
//�˴��Լӷ�����Ϊ�����ֱ𴴽�add.cԴ�ļ���add.hͷ�ļ��γ�һ���ӷ�ģ�飬�������Դ�ļ�����ӷ�ͷ�ļ�����ʹ�üӷ�����
//��add.c�ļ���д��ӷ������㷨����add.hͷ�ļ���д�뺯������
int main()
{
	int a = 10, b = 20;
	extern Add();
	int sum = Add(a, b);
	printf("%d", sum);
	return 0;
}
//int Add(int x, int y)//�����������ִ�У��������ں����ǰ��ĳ�����˵��δ����ģ�������������ǰҪ����
//{
//	return x + y;
//}


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	//�����4321����һ�δ�ӡ����������printf�����Ϊ43���ڶ��δ�ӡ��ӡ���ǵ�һ��printf�ķ���ֵ
//	//printf�ķ���ֵ�Ǵ�ӡ�ַ��ĸ���
//	//���Ե�һ��printf���ص�ֵ��2����Ϊ43��2���ַ����ڶ���printf���ص�ֵ����1�����ս����ӡ��������4321
//	return 0;
//}


//��ϰ4��дһ��������ÿһ�ε�����������ͻὫnum��ֵ+1
//void Add(int* p)
//{
//	*p+= 1;//����д��*p++��++�����ȼ���*�ߣ�++��������p�ϣ�����Ҫд��(*p)++;
//}
//int main()
//{
//	int num = 0;
//	int pa = &num;
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}



//��ϰ3��дһ������ʵ��������������Ķ��ֲ���
//int binary_search(int arr[], int x,int sz) //������arr��һ��ָ�룬ָ��Ĵ�С��8���ֽڣ�����sz������Ǵ��
//{
//	int left = 0;
//	//int sz = sizeof(arr) / sizeof(arr[0]);  //�ʴ˴���sz�ŵ�������ȥ,�ٸ����ֲ��Һ������һ��sz�Ĳ���
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (x < arr[mid])
//			right = mid - 1;
//		else if (x > arr[mid])
//			left = mid + 1;
//		else if (x = arr[mid])
//			return mid;
//	}
//	if (left > right)//�˴�if���Ҳ����ʡ��
//		return -1;
//}
//int main()
//{
//	int a;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//�ں����ڲ��������������������ģ������ں����ⲿ�����������󴫽�������
//	printf("������ҵ����֣�");
//	//�ҵõ������±꣬�Ҳ�������-1
//	scanf("%d", &a);
//	int ret = binary_search(arr,a,sz);//�˴����鴫��ʱֻ���������һ��Ԫ�صĵ�ַ
//	if (ret == -1)
//		printf("����û���������");
//	else
//		printf("�ҵ��ˣ��±�Ϊ��%d", ret);
//	return 0;
//}



//��ϰ2��дһ�������ж�һ���ǲ�������
//int leap_year(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	printf("����һ������ж��Ƿ�Ϊ���꣺");
//	scanf("%d",&year);
//	if (leap_year(year) == 1)
//		printf("����");
//	else
//		printf("������");
//	return 0;
//}



//��ϰ1��дһ�������ж�һ�����ǲ�������
//int prime(int x)
//{
//	int i = 2;
//	for (i = 2; i < sqrt(x); i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;	
//		}
//	}
//	if (i > sqrt(x))//�˴�����ʡ��if��䣬��Ϊ�ܳ�forѭ����һ���������ˣ����Կ���ֱ��return 1
//		return 1;
//}
//int main()
//{
//	int a,b;
//	printf("������һ�����ж��Ƿ�Ϊ������");
//	scanf("%d", &a);
//	b = prime(a);
//	if (b == 1)
//		printf("����");
//	else
//		printf("������");
//	return 0;
//}




//дһ������������������ֵ
//void change(int x, int y)//void������ֵ��x��yΪ�β�	
//{//ʵ�δ����β��ǣ��β���ʵ��ʵ�ε�һ����ʱ���������βε��޸��ǲ���ı�ʵ�ε�
//	int tmp = x;
//	x = y;
//	y = tmp;
//}//��ֵ���ã��������βκ�ʵ�ηֱ�ռ�в�ͬ���ڴ�飬���βε��޸Ĳ���Ӱ��ʵ��
//void change2(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}//��ַ���ã��Ѻ����ⲿ�����������ڴ��ַ���ݸ�����������һ�ֵ��ú����ķ�ʽ
////���ִ��η�ʽ�����ú����ͺ�����ߵı�����������������ϵ��Ҳ���Ǻ����ڲ�����ֱ�Ӳ��������ⲿ�ı���
//int main()
//{
//	int a = 2;
//	int b = 4;//a��bΪʵ��
//	//change(a, b);//�˴���û�н���a��b��ֵ��ԭ����a��b�ĵ�ַ�뺯������x��y�ĵ�ַ��ͬ������ֻ�ǰ�a��b��ֵ������x��y
//	//x��y�Ǻ����ڵĲ������뺯�����a��b��û�н�����ϵ����Ϊ��û�з���ֵ��
//	change2(&a, &b);//�ٴ�������������a��b�ĵ�ַ�������������н���������Ի���ͨ����ַ�ҵ�a��b
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}

//дһ���������ҳ������������ֵ
//float max(float x, float y)
//{
//	return ((x > y) ? x : y);
//}
//int main()
//{
//	float a, b, c;
//	printf("�����������֣�");
//	scanf("%f%f", &a, &b);
//	c=max(a, b);
//	printf("%f", c);
//	return 0;
//}

//memset�ڴ����ú���
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 5);//memset(ptr��int value��num)����һ�������ǵ�ַ���ڶ���������ֵ������������������
//	                       //��˼�ǰ�ֵ�滻��ַ��ָ���ֵ���滻���ǵ�ֵַ��ǰnum���ֽ�
//	//�˴��ǰ�arr��ǰ����ֽ��滻��*���滻ʱ�ַ�ת��ΪASCII��ֵ��Ҳ��int���ͣ����ǲ����滻�ַ������ַ�������int����
//	printf("%s\n", arr);
//	return 0;
//}


//strcpy���÷�
//int main()
//{
//	char arr[] = "hello";
//	char arr2[10] = "#########";
//	strcpy(arr2, arr);//��arr2ΪĿ���ַ�����arrΪԴͷ�ַ�������arr�����ݿ�����arr2�У����������ַ�\0
//	printf("%s\n", arr2);
//	return 0;
//}