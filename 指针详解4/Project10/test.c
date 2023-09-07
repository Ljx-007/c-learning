#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//简单使用以下qsort函数，qsort函数是一个库函数，用它时要引用头文件<stdlib.h>
int cmp_int(const void* e1, const void* e2)  //以比较整型举例，所以函数名为cmp_int，比较函数的返回值被规定为int
{
	return *(int*)e1 - *(int*)e2;  //因为e1，e2为void*类型，无法解引用访问值，所以强制类型转化为int*类型再解引用访问值
}
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)      //相比于直接返回相减的结果，采取比较的方式来判断返回0，1，-1会更好，不会被强制转换丢失数据
		return 1;
	else
		return -1;
	//return *(float*)e1 - *(float*)e2;//如果直接相减，得到的结果也是float类型，但是函数要求返回int型，所以会被转换成int型，可能丢失数据
                                	//如果将结果强制转换成int型，也可能会丢失精度
}
int cmp_stu_age(const void* e1, const void* e2)  //结构体排序要规定一个标准来排序，是用名字排序还是年龄排序
{
	//这里使用年龄来排序
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age; //先把两个参数类型强制转换成struct Stu，再用->操作符找到age成员，最后用age进行比较
}
int cmp_stu_name(const void* e1, const void* e2)
{
	//这里用名字来排序
	//字符串也不能直接比较大小，比较字符串用到strcmp这个函数
	//strcmp函数比较字符串的方法恰巧与qsort所要求的返回值相同，第一个str大于第二个str返回1，等于返回0，小于返回-1
	//注意，strcmp比较字符串时不是比较字符串的长度，而是比较字符串开头首字母的ACRII码值，如果相同就继续往后比较，直到遇到\0，跟字符串长度无关
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);  
}
struct Stu
{
	char name[10];
	int age;
};
int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 }; 
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	struct Stu s[] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int ssz = sizeof(s) / sizeof(s[0]);
	int fsz = sizeof(f) / sizeof(f[0]);
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);  //排列整型数组arr
	qsort(f, fsz, sizeof(f[0]), cmp_float);   //排列浮点型数组f
	qsort(s, ssz, sizeof(s[0]), cmp_stu_age);  //用年龄来排列结构体数组s
	qsort(s, ssz, sizeof(s[0]), cmp_stu_name);  //用名字来排列结构体数组s
	for (int i = 0; i < fsz; i++)
	{
		printf("%f ", s[i]);
	}
}




//上节讲到qsort函数，qsort函数是一个库函数，全称是quick sort--快速排序，他的主要参数类型如下
//void qsort(void* base, size_t num, size_t width, int(*compare)(const void* e1,const void* e2);
//第一个参数base是目标数组的起始位置，即要排序的数组首元素地址，类型为void*
//                                 因为qsort函数可以排序任意类型的数组，所以传址时要用一个什么都可以接受的指针类型void*
//第二个参数size_t num是数组的元素个数，即要排序的数组有几个元素
//第三个参数size_t width是一个元素的字节数，即数组内一个元素有几个字节
//第四个参数compare是一个函数指针，指向compare函数，compare指向的函数是一个比较函数
//比较函数的两个参数e1，e2是要比较的两个参数的地址，类型为void*---void*类型的指针，可以接受任意类型的地址
//void是空，无的意思，void*指针类型可以接受任意类型的指针
//但是不能通过void*类型的指针来修改指向的值且也不能进行指针的运算（加减整数的操作，如p++，p--），因为不知道要在内存中访问几个字节

//对比较函数的要求：
//因为不知道要比较什么类型的数据，所以参数类型一律是void*
//因为参数类型是void*，不能通过解引用来访问值，所以当我们比较两值，要访问两值时，要先进行强制类型转换， 要比较什么类型的数据就强制转换成什么类型
//两值比较时，如果e1<e2,返回的值要<0
//            如果e1=e2,返回的值要=0
//            如果e1>e2,返回的值要>0


//复习
//void Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组
//	int* arr[10];
//	//数组指针
//	int* (*parr)[10] = &arr;
//	//函数指针
//	int(*pAdd)(int, int) = Add;
//	//函数指针数组
//	int(*pArr[10])(int, int);
//	//指向函数指针数组的指针
//	int (*(*ppArr)[10])(int, int);
//	return 0;
//}