#include <stdio.h>
//getchar()���÷�
int main()
{
	int ch = getchar();//getchar()������һ���ַ���get����ȡ��char���ַ�
	while((ch=getchar())!=EOF)//EOF��end of file����˼�����ļ�������־��ֵΪ-1
		putchar(ch);//��getchar��Ӧ��������ַ�����˼����printf("%c\n", ch)��������ͬ
	//printf("%c\n", ch);
	return 0;
}


//whileѭ��   break ��continue��ʹ��
//int main() 
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
////			break;//break����ѭ��
//			continue;//continue����ֹ����ѭ��������Ĵ��붼��ִ�У�ֱ������while�����жϲ��֣�������һ��ѭ��������ж�
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//switch��䣬�ڶ�����֧������£�ʹ�ö��if��else���̫����������switch���ר�����ڶ�����֧�������
//int main()
//{
//	int day;
//	scanf_s("%d", &day);
//	switch (day)//switch����������Ǽ��ʹӵڼ���case����������ı����Ǹ�����
//	{//switchҲ����Ƕ��ʹ��
//	//������ʾ1-5�ǹ����գ�6-7����Ϣ�յĻ������򻹿�����ôд
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("������");
//			break;
//	case 6:
//	case 7:
//		printf("��Ϣ��");
//		break;  
//	default://default��Ĭ�ϵ���˼������������ֳ�����case����������Ĭ�Ͻ���default
//		printf("�������");
//		break;
	//case 1://case����������ͳ������ʽ���������Ͳ��ǳ�����������
	//	printf("����1\n");
	//	break;//���û��break����case������ִ�к����case������Ҫ����case��Ҫ��break
	//case 2:
	//	printf("����2\n");
	//	break;
	//case 3:
	//	printf("����3\n");
	//	break;
	//case 4:
	//	printf("����4\n"); 
	//	break;
	//case 5:
	//	printf("����5\n");
	//	break;
	//case 6:
	//	printf("����6\n");
	//	break;
	//case 7:
	//	printf("����7\n");
	//	break;
//	}
//	return 0;
//}


//�ж���������ӡ1-100�ڵ�����
//int main()
//{
//	/*int a;
//	scanf_s("%d", &a);
//	if (a % 2 == 1)
//		printf("����\n");
//	else
//		printf("ż��\n");*/
//	int i = 0;
//	while (i < 100)
//	{
//		if ((i + 1) % 2 == 1)
//			printf("%d ", i + 1);
//		i++;
//	}
//
//	return 0;
//}


//ѡ�����
//if �� else��ƥ������
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else//elseֻ�������δƥ���ifƥ�䣨�ͽ�ԭ�򣩡�����˴�else���һ��if���룬����Ľ����Ȼ����ڶ���ifƥ��Ľ��
//			printf("haha\n");//�����Ҫ���haha������Ҫ����һ��if����¼���{}
//	return 0;
//}


//int main()
//{
//	int age = 29;
//	if (age < 18)//ѡ���������ж���ָ��Ҫ��{}
//		printf("δ����");
//	//else if (18 <= age < 28)//������ʾ�������ִ��18<=age���ж�Ϊ����Ϊ1��Ȼ��1<28Ϊ�棬ִ�и���䡣
//	else if(age>=18&&age<28)//�����ʾage��18-28������������߼���&&��������ʾ
//		printf("����");
//	else
//		printf("����");
//
//}