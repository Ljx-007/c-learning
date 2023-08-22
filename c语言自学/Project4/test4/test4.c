#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//结构体--用于描述复杂对象（具有多种信息的对象）
//结构体是自己创造出来的类型
//.   结构体变量.成员
//->  结构体指针->成员
struct Book//创建一个结构体类型
{
	char name[20];
	short price;
};//后面要有分号
int main()
{   //创建一个结构体变量b1
	struct Book b1 = { "C语言程序设计",55 };//按定义的Book类型顺序输入
	struct Book* pb = &b1;//获取b1的地址时，pb的类型同样是b1的类型加*
	//printf("书名：%s\n价格：%d", (*pb).name, (*pb).price);//*pb一样可以代替b1来指代struct Book类型里的内容，不过要加括号
	printf("书名：%s\n价格：%d\n", pb->name, pb->price);//此处用->操作符来简化上式，pb指向b1的name和price成员
	//printf("书名：%s\n价格：%d", b1.name, b1.price);// . 操作符，用来指明结构体变量的成员
	//b1.price = 15;//修改价格
	// 若要修改书名，书名的存放是在数组里的，不能像b1.price=15一样直接改，price是一个变量，而name是一个数组
	// 修改书名时要用到strcpy--string copy这个函数，意思是字符串拷贝，这个函数在<string.h>这个头文件中，使用时要引入
	strcpy(b1.name, "C++");//此函数前一个变量是目的地（要拷贝到哪里去），后一个变量是拷贝的字符串
	//意思是将"C++"这个字符串拷贝后放到name里去
	printf("修改后的书名：%s",b1.name);
	//printf("修改后的价格：%d", b1.price);
	return 0;
}