#pragma once
#include<string.h>
#include<stdlib.h>
//对于类型的定义放在contact.h中
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
struct Peoinfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};
//创建通讯录类型
struct Contact
{
	//如果要创建1000个人的通讯录，那么只需要创建一个有1000个元素的结构体数组即可
	struct Peoinfo data[MAX];
	//当往通讯录里添加联系人时，有1000个位置，要把添加的信息放在哪个位置？
	//这需要知道通讯录里有多少信息，然后接着信息往后添加，所以需要设置一个变量size来判断通讯录里存放了多少信息
	int size;
};
//定义一个枚举，枚举出选择的所有可能性
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
//初始化通讯录
void InitContact(struct Contact* ps);
//添加联系人
void AddContact(struct Contact* ps);
//打印通讯录
void ShowContact(const struct Contact* ps); //因为这只是一个显示通讯录的函数，并不是要修改，所以可以加上const
//删除联系人
void DelContact(struct Contact* ps);
//查找联系人
void SearchContact(const struct Contact* ps);
//修改联系人
void ModifyContact(struct Contact* ps);
//排序联系人
void SortContact_byname(struct Contact* ps);