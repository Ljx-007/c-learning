#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
void menu()
{
	printf("******************************************\n");
	printf("*******  1.add           2.del   *********\n");
	printf("*******  3.search        4.modify*********\n");
	printf("*******  5.show          6.sort  *********\n");
	printf("**************   0.exit   ****************\n");
	printf("******************************************\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼���������1000�������size
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://1
			AddContact(&con);
			break;
		case DEL://2
			DelContact(&con);
			break;
		case SEARCH://3
			SearchContact(&con);
			break;
		case MODIFY://4   //����switch-case�����1��2��3��4��5��6��0���ⲻ��ȷ�����ǿ�����ö�ٵķ�ʽ���ô������һĿ��Ȼ
			ModifyContact(&con);
			break;
		case SHOW://5
			ShowContact(&con);
			break;
		case SORT://6
			SortContact_byname(&con);
			break;
		case EXIT://0
			printf("���˳�\n");
			break;
		default:
			printf("���������룺");
			break;
		}
	} while (input);
	return 0;
}