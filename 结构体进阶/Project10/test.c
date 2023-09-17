#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//声明一个结构体类型
//struct Stu
//{
//	char name[20];
//	char tele[12];  //结构体成员变量
//	char sex[10];
//	int age;
//}s1,s2,s3;//分号不能丢,且这里的s1，s2，s3都是全局结构体变量

//匿名结构体创建 -- 创建的结构体变量只能创建一次
//struct 
//{
//	int a;
//	int b;     //创建的结构体没有名字，则称为匿名结构体
//	int c;   //且只能在结构体末尾创建结构体变量x，如果在创建结构体时不创建变量，那么之后就无法创建匿名结构体的变量了
//}x;
//
//struct 
//{
//	int a;
//	int b;    
//	int c;  
//}*px;  //创建一个匿名结构体指针
//int main()
//{
//	//px = &x;  //可以用这个匿名结构体指针来存放匿名结构体变量x的地址吗？不行，编译器执行的时候会把上面两个结构体声明看成是完全不同的两个类型
//	return 0;
//}

//结构体的自引用
//结构体的自引用与数据结构的链表有关
//在内存当中，假如1，2，3，4，5这五个数据不是按顺序存放的，那么通过一种方法把1-5串联起来，这样的方式叫做链表
//struct Node
//{
//	int data;
	//struct Node n;
	//如果结构体当中含有自己的类型，这样的自引用是错误的，因为我们访问结构体的时候永远会再次访问结构体变量中的结构体，陷入无限循环，类似于死递归
	//如果要实现上述串联1，2，3，4，5数据的情况，那么我们能在结构体当中设置的结构体变量不应该还是结构体，而是结构体指针
	//这样代码一行一行运行时，先访问结构体中的其他数据例如int data，再访问结构体指针，通过结构体指针指到下一个结构体，访问下一个结构体的数据
	//从而实现在数据1，2，3，4，5的内存不是按顺序存放的情况下，按顺序访问1，2，3，4，5
//	struct Node* next; //实现链表这样的功能，结构体中需要一半存放数据，一半存放结构体指针以便访问下一个数据。
	//存放数据的那一半叫数据域，存放指针的那一半叫指针域
//};

//重命名结构体变量
//当我们声明结构体时，因为有一个struct在，定义结构体变量总是要写较长类型名
//可以使用typedef重命名来简化结构体类型名
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;  //这里利用typedef把struct Node重命名为了Node ，这里的Node是类型名不是变量名

//结构体变量的初始化
struct s
{
	char c;
	int a;
	double d;
	char arr[20];
};
struct t
{
	double weight;
	int age;
	struct s s;   // 结构体中包含结构体的情况
};
int main()
{
//	struct s s = { 'c',100,3.14,"hello world" };  结构体内不包含结构体的初始化
	struct t st = { 150,20,{'c',100,3.14,"hello world"} };   //结构体内包含结构体的初始化
	//打印结构体
	//printf("%c %d %lf %s", s.c, s.a, s.d, s.arr);     结构体内不包含结构体的打印
	printf("%lf %d %c %d %lf %s", st.weight, st.age, st.s.c, st.s.a, st.s.d, st.s.arr);
	return 0;
}

