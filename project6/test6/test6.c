#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
//��ϰ5����д����ʵ��ģ���û���¼�龰������ֻ�ܵ�¼���Ρ���ֻ���������������룬���������ȷ����ʾ��¼�ɹ���������ξ�����������˳�����
int main()
{
	int i;
	char password[20] = { 0 };
	char repassword[20] = { 0 };
	printf("���������룺");
	scanf("%s", password);
	for (i = 0; i < 3; i++)
	{
		printf("��¼���������룺");
		scanf("%s", repassword);
		//if (repassword== password) //==���������Ƚ������ַ����Ƿ���ȣ��ж������ַ����Ƿ����Ҫ��strcmp()--string compare�������
		if (strcmp(repassword, password) == 0)//���strcmp�е������ַ�����ȣ��򷵻�0ֵ,�����һ���ַ������ڵڶ����ַ������򷵻ش���0��ֵ
		{                                     //�����һ���ַ���С�ڵڶ����ַ������򷵻�С��0��ֵ
			printf("��½�ɹ�");
			break;
		}
		else
			printf("�������\n");
	}
	if (i >= 3)
		printf("���ξ�δ������ȷ���룬��½ʧ��");
	return 0;
}


//��ϰ4����һ���ַ��������ƶ����м��ۣ��� welcome to guangzhou!!
//                                          w####################!
//                                          we##################!!
//                                          .........
//                                          welcome to guangzhou!!
//int main()
//{
//	char arr1[] = "welcome to guangzhou!!";
//	char arr2[] = "######################";
//	int left = 0;
//	//char arr[]="abc"
//	//ʵ����������Ԫ��Ϊ[a b c \0]������Ԫ�ظ���Ϊ4�������±�Ϊ�������-1�Ļ���ô���±��ӦԪ��Ϊ\0
//	            //�±�Ϊ 0 1 2 3
//	//�����ĩβ��\0��β�������ַ���ĩβ�ģ����±���ʵ�������ַ������ĵ����ڶ���������Ҫ-2
//	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2; 
//	int right = strlen(arr1) - 1;//strlen()�Ǽ����ַ����ĳ��ȣ�������\0������-1���ɣ�������
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		//��Ϣ1�룬��Sleep()������Ҫ����ͷ�ļ�<Windows.h>
//		Sleep(1000);//��˼����Ϣ1�����ִ�г��������ڵ�λ��ms��1000ms=1s
//		//�����Ż�,system()����������ִ��ϵͳ�����
//		system("cls"); //cls�������Ļ����˼��ʹ��system������Ҫ����ͷ�ļ�<stdlib.h>
//		//ʹ��system()�����Ļ������ӡ��welcome to guangzhou!!Ҳ�ᱻ�����������ѭ����������һ��printf����
//		left++;
//		right--;
//	}
//	printf("welcome to guangzhou!!");
//	return 0;
//}



//��ϰ3����һ�������ҵ���Ҫ������
//�Ż��㷨:���ַ�
//int main()
//{
//	int k;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr) / sizeof(arr[0]);//���������ָ���
//	int left = 0;//���±�
//	int right = num - 1;//���±�
//	printf("����������Ҫ���ҵ����֣�");
//	scanf("%d", &k);                                                                     //{1��2��3��4��5��6��7��8��9��10}
//	while (left<=right)//����������û������ҵ����֣��Ƕ��ַ��ֵ���������±����  //�±꣺ 0��1��2��3��4��5��6��7��8��9
//	{             //��������±���Ⱥ����Ҳ�������k����˵��������û��������֣���ʱ����ѭ�����±��������±�
//		         //����ѭ�������������±�С�ڵ������±�
//		int mid = (left + right) / 2;//ȡ�����±���м�ֵ����ȡ��������
//		if (arr[mid] > k)//����м��±��Ӧ���м����������ҵ�����k
//		{
//			right = mid - 1;//��ô�������ַ�Χ�����ֵ���м�ֵ����ʱ���±겻�䣬���±��Ϊ�м��±�-1
//		}
//		else if (arr[mid] < k)//����м��±��Ӧ���м���С�����ҵ�����k
//		{
//			left = mid + 1;//��ô�������ַ�Χ�����ֵ���м�ֵ����ʱ���±겻�䣬���±��Ϊ�м��±�+1
//		}
//		else//����м��±��Ӧ���м����պ�Ϊ����ҵ�����k
//		{
//			printf("�ҵ��ˣ��±�Ϊ��%d\n", mid);//
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("������û���������");
//	}
//	return 0;
//}


//������
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k =0;
//	printf("��������Ҫ����������ҵ�����:");
//	scanf("%d", &k);
//	int num = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < num; i++)
//	{
//		if (k==arr[i])
//		{
//			printf("�ҵ��ˣ��±�Ϊ��%d", i);//��������ȱ����һ�����������ٶ�̫��
//			break;
//		}
//	}
//	if (k > num)
//		printf("������û���������");
//	return 0;
//}


//��ϰ2������1!+2!+3!+...+10!
//int Factorial(int n)
//{
//	int i = 1;
//	int a = 1;
//	for (i = 1; i <= n; i++)
//	{
//		a *= i;//n�Ľ׳�
//		if (x == 0)
//		{
//		printf("1");
//			break;
//		}
//	}
//	return a;
//}
//int main()
//{
//	int sum=0;
//	for (int i = 1; i <= 10; i++)
//		sum += Factorial(i);
//	printf("%d ", sum);
//}

//��ϰ1������n�Ľ׳�
//int main()
//{
//	int i = 1;
//	int a = 1;
//	int n;
//	printf("���������ּ�����׳ˣ�");
//	scanf("%d",& n);
////forѭ��
//	for (i = 1; i <= n; i++)
//	{
//		a *= i;
//		if (n == 0)
//		{
//			printf("1");
//			break;
//		}
//	}
//	printf("%d", a);//�����ֹ���ʱ�ᳬ��ϵͳ��������ڴ棬�ͻ��������������
//whileѭ��
	//while (i<=n)
	//{
	//	if (n == 0)
	//	{
	//		printf("1");
	//		break;
	//	}
	//	a = a * i;
	//	i++;
	//}
	//printf("%d", a);
//	return 0;
//}


//do...whileѭ��
//int main()
//{   //��ӡ1-10 
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			//break;//ֱ������do��while�ж�
//			continue;//��������ѭ��������do��ʼѭ��
//		printf("%d ", i); //��ִ��do���������ݣ�����while���ж��Ƿ����ѭ�����ж�Ϊ�棬���do��ʼ����ѭ��
//		i++;
//	} while (i < 11);
//	return 0;
//}


//forѭ��
//forѭ��������ĳ�ʼ�����жϺ͵������ַ�����һ�������while�������޸ĵ�������Ϊwhile�ĳ�ʼ���жϺ͵������������Զ
//for(����ʽ1������ʽ2������ʽ3),����ʽ1�ǳ�ʼ������������ʽ2�������жϣ�����ʽ3��ѭ���ĵ���
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)//�ж�����k=0Ϊ�٣����Բ�ѭ��	
//		printf("hehe\n");


	//for (;;)//��ѭ����forѭ���ĳ�ʼ�����жϺ͵���������ʡ�ԣ����ж����ʡ�������ж��������Ǻ�Ϊ��
	//	printf("hehe\n");

	//10��ѭ��
	//10��Ԫ��
	//10�δ�ӡ
	//for (int i = 0; i <10; i++)//forѭ�������ִ�г�ʼ�����֣������жϱ���ʽ2�Ƿ�Ϊ�棬Ϊ����ִ��forѭ���ڵ����
	//	                       //ִ����ѭ����������ִ�б���ʽ3�������֣����ż����жϱ���ʽ2�Ƿ�Ϊ�棬��Ϊ��������ѭ����
	//{                          //forѭ������ʹ������ҿ�������
	//	if (i == 5)
	//		//break;
	//		continue;
	//	printf("%d ", i);
	//}
//	return 0;
//}


//int main()
//{
//	int ch;
//	while ((ch = getchar())!=EOF)//EOF���ļ�������־����windows�����ctrl+z
//	{
//		if (ch < '0' || ch>'9')//chС���ַ�0�����ַ�9
//			continue;
//		putchar(ch);//��˼������0-9֮������ֶ����ܱ���ӡ
//	}
//	return 0;
//}



//getchar()���÷�
//int main()
//{
//	//int ch = getchar();//getchar()������һ���ַ���get����ȡ��char���ַ�
//	//while ((ch = getchar()) != EOF)//EOF��end of file����˼�����ļ�������־��ֵΪ-1
//	//	putchar(ch);//��getchar��Ӧ��������ַ�����˼����printf("%c\n", ch)��������ͬ
//	////printf("%c\n", ch);
//
//	//���ϴ�����ô�
//	char password[20] = { 0 };
//	int ret = 0;
//	char ch;
//	printf("���������룺");
//	scanf("%s", password);//�������벢�����password������  
//	//scanf_s����б߽��飬���øú���ʱҪ�ṩһ�������Ա��������ȡ���ٸ��ַ�
//	//����д����scanf_s("%s",password);
//	//��ȷд���� scanf_s("%s",password,sizeof(password));
//	//password������Ϊһ�����飬���鱾������һ����ַ���ʲ���ȡ��ַ��&
//	//������������뻺����������һ��'\n'δ����ȡ�����Ǳ�ret=getchar()��ȡ�ߣ���û�дﵽ��Ҫ��Ч��
//	//��Ҫ��'\n'��ȡ�ߣ����һ��getchar()
//	//getchar();//�������������ʱ�б���ַ�������123456 ABCD����ô123456��scanf���ߣ��м�Ŀո�getchar()���ߣ�ABCD��ret����
//	          //�ǳ����ֻ������ǲ���Ҫ�����ӣ�ֱ�Ӵ�ӡ������ȷ�ϡ���Ҫ���������⣬��Ҫʹ��һ��ѭ����getchar()һֱ��ȡ
//	          //������ʱʹ�ü��ӿ�֪��123456����ַ�һֱ��ѭ����getchar��ȡ���ʼ�ʹ����123456 ABCD��passwordҲֻ��123456
//	while (ch = getchar() != '\n')//��while(ch=getchar()!=EOF)
//	{
//		;//ִ��һ������䣬
//	}
//	printf("��ȷ�����루Y/N����");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�");
//	}
//	else
//	{
//		printf("����ȷ��");
//	}
//	return 0;
//}