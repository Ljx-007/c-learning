#include <stdio.h> 
//%c��ӡ�ַ�
//%d��ӡ����
//%f��ӡ������                       ���������õ�
//%p�Ե�ַ����ʽ��ӡ
//%x��ӡ16��������
//int main()
//{
//	//int age = 20;
//	//printf("%d\n",age);
//	//char ch = 'A';
//	//printf("%c", ch);
//	/*double f = 0.2;
//	printf("%lf", f);*/
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(short));
//	return 0;
//	
//}
//int main()
//{
//	//����������֮��
//	int num1 ,num2,sum;
//	/*int num2 ;
//	int sum ;*/
//	//��������ʹ�����뺯��scanf_s
//	scanf_s("%d%d", &num1, &num2);//���������;����������ͷ���    &��ȡ��ַ���ţ�ȡnum1��num2��λ��
//	sum = num1 + num2;
//	printf("sum=%d",sum);
//	return 0;
//}
int main()
{
	extern int a;//extern �����ⲿ����
	printf("a=%d", a);
}