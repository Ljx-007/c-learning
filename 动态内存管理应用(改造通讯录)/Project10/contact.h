#pragma once
#include<string.h>
#include<stdlib.h>
//�������͵Ķ������contact.h��
//#define MAX 1000   ʵ�ֶ�̬���ͨѶ¼�Ͳ���Ҫ��ʹ��������ֵ�ˣ�����һ���Կ��ٵ�1000���ˣ������ǲ���Ҫһ���Կ��٣�����ע�͵�
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3  //ͨѶ¼��Ĭ�ϳ�ʼ����
//��ϵ��ӵ�е���Ϣ
struct Peoinfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};
//����ͨѶ¼����
struct Contact
{
	struct Peoinfo *data; //��̬���ͨѶ¼��Ҫ��̬�����ڴ棬���Բ���ʹ������һ���Կ��٣����ǰ�data��ʼ����һ��ָ��
	//����ͨѶ¼�������ϵ��ʱ���кܶ��λ�ã�Ҫ����ӵ���Ϣ�����ĸ�λ�ã�
	//����Ҫ֪��ͨѶ¼���ж�����Ϣ��Ȼ�������Ϣ������ӣ�������Ҫ����һ������size���ж�ͨѶ¼�����˶�����Ϣ
	int size;
	//��̬��ͨѶ¼��Ҫ��һ����ʼ������֮�󲻶�������Ϣ�Ĺ����У�������Ҫ�ж��Ƿ����ݣ�������Ҫ����һ������ָ��capacity
	int capacity;//��¼��ǰͨѶ¼���������
};
//����һ��ö�٣�ö�ٳ�ѡ������п�����
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//�����ϵ��
void AddContact(struct Contact* ps);
//��ӡͨѶ¼
void ShowContact(const struct Contact* ps); //��Ϊ��ֻ��һ����ʾͨѶ¼�ĺ�����������Ҫ�޸ģ����Կ��Լ���const
//ɾ����ϵ��
void DelContact(struct Contact* ps);
//������ϵ��
void SearchContact(const struct Contact* ps);
//�޸���ϵ��
void ModifyContact(struct Contact* ps);
//������ϵ��
void SortContact_byname(struct Contact* ps);