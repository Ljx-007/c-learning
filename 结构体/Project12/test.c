#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ṹ��
//struct--�ṹ��ؼ���      Stu--�ṹ���ǩ      struct Stu--�ṹ������

typedef struct Stu
{
	char name[20];
	short age;
	char phone[12];  //�绰����int��������Ϊ�����int���͵绰Ϊ11λ���֣���һ���ܴ�����֣���ռ�úܴ�Ŀռ�
	char sex[5];
}Stu;
void Print1(Stu s)
{
	//�ṹ�崫��
	printf("name:%s\n", s.name);  
	printf("age:%d\n", s.age);
	printf("phone:%s\n", s.phone);
	printf("sex:%s\n", s.sex);
}
void Print2(Stu* ps)
{
	//�ṹ��ָ�봫��
	printf("name:%s\n", ps->name);
	printf("age:%d\n", ps->age);
	printf("phone:%s\n", ps->phone);
	printf("sex:%s\n", ps->sex);
}
int main()
{
	Stu s = { "����",20,"18918881888","��" };
	Print1(s);//��ӡ�ṹ��
	Print2(&s);  
	//Print1��Print2���ִ�ӡ��ʽPrint2���ã�Print2ռ�õĿռ��С����Ϊ�β���ʵ�ε���ʱ������Print1����ʱ�ѽṹ���Ա������ȫ��������һ��
	//��Print2�Ǵ�ַ���ã�������ָ�룬ָ���ֻ��4��8���ֽڣ�ԶԶС��Print1��ռ�õĿռ�
	return 0;	
}


//Ƕ�׽ṹ���ʼ��
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;
//	char* pc;
//};
//int main()
//{
//	char arr[] = "hello ljx\n";
//	struct T t = { "hehe",{100,'s',"hello world",2.1},arr };//�ṹ���Ƕ��ʹ�ã����ṹ���Ա���нṹ�����ʱ��������һ������������������ṹ�����
//	printf("%s\n", t.ch);
//	return 0;
//}


//struct Stu
//{
//	char name[20];
//	short age;
//	char phone[12];  //�绰����int��������Ϊ�����int���͵绰Ϊ11λ���֣���һ���ܴ�����֣���ռ�úܴ�Ŀռ�
//	char sex[5];
//}; s1, s2, s3;  //s1,s2,s3����struct Stu�ṹ�崴��������ȫ�ֵĽṹ�����������һ�㲻����ʹ������д�������������ֲ�����

//typedef struct Stu
//{
//	char name[20];
//	short age;
//	char phone[12];  //�绰����int��������Ϊ�����int���͵绰Ϊ11λ���֣���һ���ܴ�����֣���ռ�úܴ�Ŀռ�
//	char sex[5];
//}Stu;  //�����Ĵ�����������ֱ�Ӱѽṹ����struct Stu���¶���ΪStu  �൱�ڴ���typedef struct Stu Stu;
//int main()
//{
//	struct Stu s = {"����",20,"15918608777","��"};
//	Stu s2 = {"����",21,"17756339588","Ů"};
//	return 0;
//}