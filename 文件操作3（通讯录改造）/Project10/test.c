#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
//��ѧϰ��̬�ڴ����֮ǰ�����Ǵ���ͨѶ¼�ķ�ʽ��һ���Կ��ٴ��1000���˵���Ϣ���ڴ�ռ䣬��ʵ���ϣ����ǲ�����һ���ԾͰ�1000���˵���Ϣ����
//��ֻ��Ҫ���ĳ������ϵ�˵���Ϣʱ�����ٳ����Ĵ��1000���˵���Ϣ���ڴ�ռ���Ե�̫���˷�
//�Ѿ�ѧϰ����̬�ڴ��������Ƕ����ͨѶ¼���Ը��죬�ȿ���һС���ֿռ䣬�������������ϵ��ʱ�������ٽ�������

void menu()
{
	printf("******************************************\n");
	printf("*******  1.add           2.del   *********\n");
	printf("*******  3.search        4.modify*********\n");
	printf("*******  5.show          6.sort  *********\n");
	printf("*********7.save          0.exit  *********\n");   //����һ������Ĺ���ʹͨѶ¼�ܴ洢���ļ���
	printf("******************************************\n");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼���������dataָ�룬size��capacity ��con���������֮ǰ�仯�ˣ���ô��ʼ��ͨѶ¼�ķ�ʽҲҪ�ı�
	//��ʼ��ͨѶ¼
	InitContact(&con); //����ϣ����һ�δ�ͨѶ¼��ʱ����һ�������ͨѶ¼����Ϣ���ڣ����Գ�����һ������ʱ����Ҫ��ȡ���Ǳ����ڵ������ͨѶ¼�ļ�
	                   //�����ڳ�ʼ��ͨѶ¼ʱ��Ҫ����һ����һ�δ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://1
			AddContact(&con); //��̬���������Ϣ����ҲҪ��
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
		case SAVE:
			save(&con);  //��ͨѶ¼���浽�ļ���
			break;
		case EXIT://0
			//�˳�ͨѶ¼��Ҫ����ͨѶ¼--�ͷŶ�̬���ٵ��ڴ�
			save(&con);   //��ͨѶ¼���浽�ļ���
			Destroy(&con);
			printf("���˳�\n");
			break;
		default:
			printf("���������룺");
			break;
		}
	} while (input);
	return 0;
}