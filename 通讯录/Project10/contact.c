#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
void InitContact(struct Contact* ps)
{
	//��ʼ��ͨѶ¼ʱ��ͨѶ¼����ʼ��Ϊ0���Ϳ����õ�memset�������
	//void* memset(void* dest ,int c ,size_t num)  ����cָ����Ҫ���õ��ַ���numΪҪ���õ��ֽ���
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼�����ϢΪ0��
}
void AddContact(struct Contact* ps)
{
	//ps����ͨѶ¼�ĵ�ַ
	//���ж�ͨѶ¼��û��
	if (ps->size == MAX)
		printf("ͨѶ¼�������޷�����\n");
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name); //��ͨѶ¼���ҵ�data�ṹ�����飬�����ַ��ڽṹ������ĵ�size���ṹ���е�name��
		                                       //name��һ��char�����飬�������һ����ַ
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);   //age��int�ͣ�����һ����ַ����������ageʱҪȡ��ַ
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age)); 
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele); 
		printf("������סַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		printf("%-5s\t%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "���", "����", "�Ա�", "����", "�绰", "סַ");
	}
	else
	{
		//��ӡͨѶ¼ʱϣ����ӡ�����������  ����    �Ա�    ����    �绰    סַ
		//                             1    ����     ��      30     137...  ������
		printf("%-5s\t%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "���","����", "�Ա�", "����", "�绰", "סַ");//%20s�������ƴ�ӡ20���ַ�����˼��\t����һ������tab
		for (int i = 0; i < ps->size; i++)  //�����е���Ϣһһ��ӡ����
		{
			printf("%d\t", i + 1); //��ӡͨѶ¼�����
			printf("%-9s\t%-5s\t%-4d\t%-12s\t%-30s\n", //��Ҫ��ӡ������̫�����Ի���
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
//���Ƿ��֣��ڽ��в�����ϵ�ˣ�ɾ����ϵ�ˣ��޸���ϵ�˵Ȳ�����ʱ�򣬶�Ҫ�õ�ͬһ����ҵĴ��룬Ϊ�˷�ֹ�������࣬���԰Ѳ��ҹ��ܷ�װ�ɺ���
//����ҵ��ˣ������±꣬û�ҵ�������-1
//Find_byname�������������ͨѶ¼�Ĺ��ܣ�ֻ��Ϊ�˽���ͨѶ¼���ܺ�����ʵ�ָ��ӷ��㣬���Բ�������
//����ϣ����ֻ�����ڵ�Դ�ļ��ڷ������ã��ڲ����ļ����޷�ʹ�ã����Լ���staticʹ���ɾ�̬����
//static���ξֲ�����ʱ�������þֲ��������������ڱ䳤���ھֲ���������Ҳ����ʹ��
//static����ȫ�ֱ����ͺ���ʱ��ֻ�����������ڵ�Դ�ļ���ʹ��
static int Find_byname(const struct Contact* ps, char name[NAME_MAX])
{
	for (int i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
		printf("ͨѶ¼Ϊ�գ��޷�����ɾ������\n");
	else
	{
		//ɾ�������е�����ʱ�����ú���������ǵ�ǰ�������Ȼ�������Ԫ�ظ���-1
		//��������arr[]={1,2,3,4,5,6,7,8} �����Ҫɾ��4����ô����5�ŵ�4��λ�ã�6���ǵ�5��λ�ã��Դ����ƣ�ֱ������������8
		//����������ʵ���������ô���һ���ظ���8�ͷ��ʲ����ˣ���ʵ����ɾ������Ԫ�صĹ���
		char name[NAME_MAX];
		printf("��������Ҫɾ������ϵ������:");
		scanf("%s",name);
		//1.����Ҫɾ��������ʲôλ��
		int find = Find_byname(ps, name);
		//����ѭ�������������һ���Ǳ������������鶼û���ҵ�����ˡ�����һ�����ҵ������������ѭ��
		if (find== -1)
			printf("ͨѶ¼�޴���\n");
		else
		{  //ɾ����ϵ��
			int j = 0;
			for (j = find; j < ps->size-1; j++)  //���ps->size��-1�Ļ��ͻ�Խ�������
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("ɾ���ɹ�\n");
		}
	}
}
void SearchContact(const struct Contact* ps) 
{
	char name[NAME_MAX];
	printf("��������Ҫ���ҵ��˵����֣�");
	scanf("%s", name);
	int find = Find_byname(ps, name);
	if (find == -1)
		printf("���޴���!\n");
	else
	{
		printf("%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-9s\t%-5s\t%-4d\t%-12s\t%-30s\n", //��Ҫ��ӡ������̫�����Ի���
			ps->data[find].name,
			ps->data[find].sex,
			ps->data[find].age,
			ps->data[find].tele,
			ps->data[find].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	printf("������Ҫ�޸ĵ���ϵ�˵�������");
	char name[NAME_MAX];
	scanf("%s", name);
	int find = Find_byname(ps, name);
	if (find == -1)
		printf("ͨѶ¼�޴��ˣ�\n");
	else  //�޸ľ�������¼һ��ͨѶ¼��Ϣ
	{
		printf("���������֣�");
		scanf("%s", ps->data[find].name); //��ͨѶ¼���ҵ�data�ṹ�����飬�����ַ��ڽṹ������ĵ�size���ṹ���е�name��
		//name��һ��char�����飬�������һ����ַ
		printf("�������Ա�");
		scanf("%s", ps->data[find].sex);   //age��int�ͣ�����һ����ַ����������ageʱҪȡ��ַ
		printf("���������䣺");
		scanf("%d", &(ps->data[find].age));
		printf("������绰��");
		scanf("%s", ps->data[find].tele);
		printf("������סַ��");
		scanf("%s", ps->data[find].addr);
		printf("�޸ĳɹ�\n");
	}
}
int cmp(const void* e1, const void* e2)
{
	return strcmp((*(struct Peoinfo*)e1).name , (*(struct Peoinfo*)e2).name);
}
void SortContact_byname(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp);
	printf("���������\n");
}