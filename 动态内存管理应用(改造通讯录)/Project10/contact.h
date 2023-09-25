#pragma once
#include<string.h>
#include<stdlib.h>
//对于类型的定义放在contact.h中
//#define MAX 1000   实现动态版的通讯录就不需要再使用这个最大值了，这是一次性开辟的1000个人，而我们不需要一次性开辟，所以注释掉
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define DEFAULT_SZ 3  //通讯录的默认初始容量
//联系人拥有的信息
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
	struct Peoinfo *data; //动态版的通讯录需要动态开辟内存，所以不在使用数组一次性开辟，而是把data初始化成一个指针
	//当往通讯录里添加联系人时，有很多个位置，要把添加的信息放在哪个位置？
	//这需要知道通讯录里有多少信息，然后接着信息往后添加，所以需要设置一个变量size来判断通讯录里存放了多少信息
	int size;
	//动态版通讯录需要有一个初始容量，之后不断增加信息的过程中，我们需要判断是否扩容，所以需要创建一个容量指标capacity
	int capacity;//记录当前通讯录的最大容量
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