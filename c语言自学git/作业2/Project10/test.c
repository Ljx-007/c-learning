#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
//��ϰ�ģ���ӡһ������
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********   
//  ********* 
//   *******          
//    *****
//     ***
//      *
int main()
{
	int line = 0;
	printf("Ҫ��ӡ�����е����Σ�");
	while(1)
	{
		scanf("%d", &line);
		if (line % 2 == 0)
			printf("��ӡ����ֻ����������Ŷ\n");
		else
			break;
	}
	int blank = line/2;
	int xing = 1;
	while (blank+1)
	{
		for(int i=0;i<blank;i++)
		{
			printf("%c", ' ');
		}
		blank--;
		for (int j = 0; j < xing; j++)
		{
			printf("%c", '*');
		}
		xing+=2;
		printf("\n");
	}
	blank = 1, xing -= 2;
	while (xing>0)
	{
		for (int i = 0; i < blank; i++)
		{
			printf("%c", ' ');
		}
		blank++;
		for (int j = 0; j < xing-2; j++)
		{
			printf("%c", '*');
		}
		xing -= 2;
		printf("\n");
	}
	return 0;
}



//��ϰ�������0-100000��ˮ�ɻ�������һ��n�η������֣���λ���ֵ�n�η�֮�͵������������
//int main()
//{
//	for (int i = 1; i <= 100000;i++)
//	{
//		//�ж�ˮ�ɻ�����λ��
//		int count = 0; //�κ�һ������������һλ��
//		int num = 0;
//		int e1 = i;
//		while (e1 >0)     //���whileѭ�����Ժϲ�Ϊwhile(e1/=10)
//		{                                       //{ count+;}
//			e1 = e1 / 10;
//			count++;
//		}
//		e1 = i;
//		while(e1>0)
//		{
//			num+=pow(e1 % 10, count);  //pow(a,b)��˼��a��b�η���pow�Ǹ�������Ҫ����<math.h>���ͷ�ļ�������pow���ص���double���͵����֣���������ʱ���о���
//			e1 = e1 / 10;
//		}
//		if (num == i)
//			printf("%d ", i);
//	}
//	return 0;
//}



//��ϰ����������ͣ���Sn=a+aa+aaa+aaaa+aaaaa....ǰn��֮�ͣ�����a��һ�����֡�����2+22+222+2222+22222....
//int main()
//{
//	int a, n;
//	printf("a=");
//	scanf("%d", &a);
//	printf("n=");
//	scanf("%d", &n);
//	int Sn = 0;
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret*10 + a;
//		Sn += ret;
//	}
//	printf("%d", Sn);
//	return 0;
//}



//��ϰһ��дһ�����������������ַ���������
//void reverse(char ch[])
//{
//	char* left = ch;
//	char* right = ch;
//	while (*(right+1) != '\0')
//	{
//		right++;
//	}
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--, left++;
//	}
//}
//int main()
//{
//	char ch[12] = { 0 };//11���ַ���һ��\0
//	//scanf("%s", ch);
//	//����������hello world��ʱ��scanf��ȡ���ո�tab���س��Ȼ������ַ��ͻ��Զ��ضϣ����û��gets(ch)���д��룬��ôscanf��ȡ���ľ���hello������hello world
//	//gets����������ص�����Ϊchar* ����������ҲΪchar*���Ƕ�ȡһ���ַ�����
//	//��ȡһ�У�����������ʲô���������ᱻ��ȡ���������ո� 
//	//��VS2019��gets��������ͱ�ɾ���ˣ���Ϊ�������޶�ȡ���������
//	//��������gets_s���������棬gets_s�����ķ���������char*��������char*��Ҫ������ַ����ĳ��ȣ�������'\0'��
//	//��gets_s��ch�������ַ���ʱҪ�涨ch�ĳ��ȣ���Ȼ�ᱨ��
//	gets_s(ch,11); 
//	reverse(ch);
//	printf("%s", ch);
//	return 0;
//}