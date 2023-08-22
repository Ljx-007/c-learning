#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//结构体
//struct--结构体关键字      Stu--结构体标签      struct Stu--结构体类型

typedef struct Stu
{
	char name[20];
	short age;
	char phone[12];  //电话不用int类型是因为如果用int类型电话为11位数字，是一个很大的数字，会占用很大的空间
	char sex[5];
}Stu;
void Print1(Stu s)
{
	//结构体传参
	printf("name:%s\n", s.name);  
	printf("age:%d\n", s.age);
	printf("phone:%s\n", s.phone);
	printf("sex:%s\n", s.sex);
}
void Print2(Stu* ps)
{
	//结构体指针传参
	printf("name:%s\n", ps->name);
	printf("age:%d\n", ps->age);
	printf("phone:%s\n", ps->phone);
	printf("sex:%s\n", ps->sex);
}
int main()
{
	Stu s = { "李四",20,"18918881888","男" };
	Print1(s);//打印结构体
	Print2(&s);  
	//Print1和Print2两种打印方式Print2更好，Print2占用的空间更小，因为形参是实参的临时拷贝，Print1传参时把结构体成员的内容全都拷贝了一份
	//而Print2是传址调用，传的是指针，指针就只有4或8个字节，远远小于Print1所占用的空间
	return 0;	
}


//嵌套结构体初始化
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
//	struct T t = { "hehe",{100,'s',"hello world",2.1},arr };//结构体的嵌套使用，当结构体成员中有结构体变量时，需再用一个大括号来描述这个结构体变量
//	printf("%s\n", t.ch);
//	return 0;
//}


//struct Stu
//{
//	char name[20];
//	short age;
//	char phone[12];  //电话不用int类型是因为如果用int类型电话为11位数字，是一个很大的数字，会占用很大的空间
//	char sex[5];
//}; s1, s2, s3;  //s1,s2,s3是用struct Stu结构体创建的三个全局的结构体变量，不过一般不建议使用这种写法，尽量创建局部变量

//typedef struct Stu
//{
//	char name[20];
//	short age;
//	char phone[12];  //电话不用int类型是因为如果用int类型电话为11位数字，是一个很大的数字，会占用很大的空间
//	char sex[5];
//}Stu;  //这样的创建方法可以直接把结构体名struct Stu重新定义为Stu  相当于代码typedef struct Stu Stu;
//int main()
//{
//	struct Stu s = {"张三",20,"15918608777","男"};
//	Stu s2 = {"李四",21,"17756339588","女"};
//	return 0;
//}