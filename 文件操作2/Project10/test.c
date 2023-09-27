#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//文本行的输入和输出--fgets和fputs
//一次输入或输出一行文本
//fgets--从输入流中读取信息
//char* fgets(char* string,int n,FILE* stream)
//第一个参数是获取到的字符串存放的位置，第二个参数是最多读取多少个字符，第三个参数则是流，从什么流中读取信息

//fputs--输出一个字符串到流中
//int fputs(const char* string,FILE* stream)
//即把字符串string输出到流stream中
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");  //写入要用"w",读取要用"r"，不然就会无输出和无输入
//	char str[30] = { 0 };
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return -1;
//	}
//	fputs("无敌爆爆龙", pf);
//	fgets(str, 30, pf);  
//	puts(str);//puts函数是输出一行代码到屏幕上
//	//puts函数会自动在字符串末尾增加换行符
//	fclose(pf), pf = NULL;
//	return 0;
//}


//格式化输入和输出--fscanf和fprintf（指定格式）
//传统的scanf和printf都是针对于标准输入流和标准输出流，也就是说只能在键盘上输入和屏幕上输出
//而fscanf和fprintf与scanf和printf的区别就在于fscanf和fprintf可以指定输入流和输出流，所以要比scanf和printf多一个流的参数
//struct S
//{
//	int n;
//	float f;
//	char arr[15];
//};
//int main()
//{
//	//struct S s = { 100,3.14f,"hello world" };  //3.14后的f是保证3.14是float型，不然浮点型默认为double类型
//	struct S tmp = { 0 };  //读取文件内容时要重新创建一个结构体并置为0，因为我们希望从文件里读出来的数据放到tmp中去
//	FILE* pf = fopen("test.txt", "r+"); //"r+"是可读可写，没有文档就报错
//	if (pf == NULL)
//		return -1;
//	//输出内容到文件流pf
//	//fprintf(pf, "%d %f %s", s.n, s.f, s.arr); //以格式化形式输出到文件中
//	//从pf读取内容到tmp
//	fscanf(pf, "%d %f %s", &(tmp.n), &tmp.f, tmp.arr);  //fscanf读取数据时遇到空格就会停止读取，所以后面的world打印不出来
//	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
//	fclose(pf), pf = NULL;
//	return 0;
//}

//scanf/fscanf/sscanf的区别
//printf/fprintf/sprintf的区别

//  scanf/printf是针对标准输入流/标准输出流的 格式化输入/输出语句
//  fscanf/fprintf是针对所有输入流/所有输出流的 格式化输入/输出语句
//  sprintf：读取格式化的数据并转化成字符串输出到指定的指针中，所以sprintf参数要比printf多一个char* string的参数
//  sscanf ：读取指定的字符串并转化成格式化的数据，所以sscanf参数要比scanf多一个const char* string的参数

//例：
struct S
{
	int n;
	float f;
	char arr[15];
};
int main()
{
	struct S s = { 100,3.14f,"hello" };
	struct S tmp = { 0 };
	char str[100] = { 0 };
	//把格式化的数据转化成字符串输出到str
	sprintf(str, "%d %.2f %s", s.n, s.f, s.arr);
	printf(str);
	//从字符串str中读取数据并转化成格式化数据输入到了tmp中
	sscanf(str, "%d %f %s", &tmp.n, &tmp.f, tmp.arr);
	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
	return 0;	
}