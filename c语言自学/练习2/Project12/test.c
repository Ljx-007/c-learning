#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//��ϰ9���ݹ�ʵ��n��k�η�
double power(int n, int k) //����ֵ���и������ͣ����Ժ�������Ҳ�Ǹ�������
{  //���������
	if (k < 0)
		return (1.0 / power(n, -k));//kС��0��-k�ʹ���0��������С��������Ϊ����׼ȷ����С������1��Ϊ1.0
	else if (k == 0)
		return 1;
	else
		return n * power(n, k - 1);
	
}
int main()
{
	int n, k;
	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);
	double num = power(n, k);
	printf("%lf", num);
	return 0;
}




//��ϰ8����д�ݹ麯������һ������ÿһλ֮��
//int DigitSum(int a)
//{
//	if (a > 9)
//		return a % 10 + DigitSum(a / 10);
//	else
//		return a;
//}
//int main()
//{
//	unsigned int a ;
//	scanf("%d", &a);
//	int num=DigitSum(a);
//	printf("%d", num);
//	return 0;
//}





//��ϰ7����дһ������reverse_string()���ݹ�ʵ�֣����������ַ����е��ַ��������У�Ҫ����ʹ�ÿ����ַ�����������
//��������(�ݹ鷨��
//int my_stringlen(char ch[])
//{
//		if (*ch == '\0')
//		return 0;
//	else
//		return 1 + my_stringlen(ch + 1);
//}
//void reverse_string(char ch[])
//{
//	int len = my_stringlen(ch); //�Ȼ�ȡ�ַ�������
//	char* start = ch;
//	char* end = ch + len - 1;   
//	char tmp = 0;
//	tmp = *start;
//	//a b c d e f \0
//	//f b c d e a \0 ->f b c d e \0 \0
//	//ch+1ָ��b,b���滻��a��\0����µ��ַ��� b c d e
//	//b c d e \0 ->e c d b \0 ->e c d \0 \0
//	//c��\0����µ��ַ���c d \0 ->d c \0, c d�м�û���ַ��ˣ��ݹ�ֹͣ������*end = tmp�����ǽ��滻��\0���ַ�һ����������������������
//	*start = *end;   //����a��f��ֵ
//	*end = '\0';    //�ٰѽ������a��λ�ñ�Ϊ\0����������ch+1�����\0����µ��ַ���
//	if (my_stringlen(ch + 1) > 1)   //���µ��ַ�������Ϊ0����1ʱ����˵���µ��ַ�����ֻ��0����1���ַ������������������ϵ��ַ�ʱ������Ҫ����
//		reverse_string(ch + 1);  //����Ҫ�����ͼ����ݹ飬����reverse�����н���
//	*end = tmp; //���ݹ�����ٰ�ԭ���滻��\0��������
//}
//int main()
//{
//	char ch[] = "abcdef";
//	reverse_string(ch);
//	printf("%s", ch);
//}




//����һ�����Լ�д�ģ�
//void reverse_string(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while ((*end) != '\0')
//	{
//		end++;
//	}
//	end--;   //�˴�end-1����������end��Ҫָ��\0�������\0Ҳ��������ǰ�棬��ô���ַ������齫���������Ϊ\0���ַ����Ľ�����־
//	while (start < end)
//	{
//		char tmp = 0;
//		tmp = *start;
//		*start = *end;
//		*end = tmp;
//		end--, start++;
//	}
//}
//int main()
//{	
//	char ch[] = "abcdef";
//	reverse_string(ch);
//	printf("%s", ch);
//	return 0;
//}



//��ϰ6���õݹ麯����ӡһ������ÿһλ
//void Print(int input)
//{
//	if (input > 9)
//		Print(input / 10);
//	printf("%d ", input % 10);
//	
//}
//int main()
//{
//	int input;
//	printf("�������ִ�ӡ�������ÿһλ��");
//	scanf("%d", &input);
//	Print(input);
//	return 0;
//}



//��ϰ5������˷��ھ�������9�����9*9�ھ�������12�����12*12�Ŀھ���
//void print_table(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			printf("%d*%-2d=%-3d ",j, i, j * i);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	again:
//	printf("����������ѡ���ӡn*n�Ŀھ���");
//	scanf("%d", &n);
//	if (n <= 0)
//	{
//		printf("�������\n");
//		goto again;
//	}
//	print_table(n);
//	return 0;
//}




//��ϰ4����ӡ100-200�������
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		int j;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if(j>sqrt(i))
//			printf("%d ", i);
//	}
//	return 0;
//}




//��ϰ3����ȡһ�����������������е�����λ��ż��λ���ֱ��ӡ������������
//int main()
//{
//	int a = -1;
//	printf("����λ��");
//	for (int i = 30; i>=0; i-=2)
//	{
//		int b = (a >> i) & 1; //�˴���a���Ʊ���1���ƺã���Ϊ��a������1��λ����ж�ʼ���������λ�����λֻ��0��1
//		printf("%d", b);      //����1���ƵĻ���λ��λ�õ��жϲ����ڱ仯���ҵõ������ֲ�����0��1
//		                     //���統��λ���жϳ���1����������λ���õ��Ľ����0100����ֵ��b�о���4����������õ���ֻ��1��0
//		                     //���Ҫ��1���Ʋ��ҵõ���ȷ�Ľ������ô��ӡbʱ����ʹ���߼���������������b�߼������Σ���!!b���ɵõ���ȷ��
//	}
//	printf("\nż��λ��");
//	for (int i = 31; i >=1; i -= 2)
//	{
//		int b = (a >> i) & 1;
//		printf("%d", b);
//	}
//	return 0;
//}



//��ϰ2���Ƚ��������ж����Ʋ�ͬλ�ĸ���
//int main()
//{  //����������Ķ�����λ��ͬΪ0������Ϊ1��ǡ�÷��������Ŀ��Ҫ��
//	int a, b,c;
//	printf("�����������ж϶����Ʋ�ͬλ�ĸ�����");
//	scanf("%d%d", &a, &b);
//	c = a ^ b;//a,b������ͬλ����1������c������ж�����1�ĸ�������a��b��������ͬλ�ĸ��������Ի�Ҫ����c��1�ĸ���
//	int count = 0;
//	while (c)
//	{
//		c = c & (c - 1);
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}




//��ϰ1��ͳ��ĳ�����ֶ�������1�ĸ���
//�������������㷨������ţ��
//int main()
//{
//	int a = -1,count=0;  //1111 
//	while (a)
//	{
//		//1111--15
//		//1110--14  15&14--1110--a
//		//1110--a
//		//1101--a-1  a&(a-1)--1100--a
//		//�Դ����ƣ�a�������е�1�ĸ���һֱ�ڼ��٣�һֱ��λ����ȥa�����Ϊ0
//		a = a & (a - 1); 
//		count++;//����ֻ��Ҫ�����1���˼��ξ�֪��1�м�����
//	}
//	printf("%d ", count);
//	return 0;
//}



//����һ��
//int main()
//{
//	int a = -1;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (1==((a>>i) & 1))
//			count++;
//	}
//	printf("%d ", count);
//	return 0;
//}