#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//fread--二进制输入
//fwrite--二进制输出

//size_t fwrite(const void* buffer , size_t size , size_t count ,FILE* stream)
//buffer是要写入数据的空间的地址
//size是要写入的元素的大小，单位是字节
//count是最多要被写入的元素个数

//size_t fread(const void* buffer , size_t size , size_t count ,FILE* stream)
//buffer是读取数据后存放的位置
//size是读取数据的大小
//count是最多要读取的元素个数
//fread的返回值是size_t，代表读到的元素个数 。比如有55个元素需要读取，但规定fread一次只能读10个，那么读了5次后fread一共读取了50个数据，再读取一次就只读取了5个数据
//那么最后一次读取fread只返回了数字5，代表读到了5个元素，所以如果fread的返回值比count小时，说明数据已经全部读取完了
//typedef struct S
//{
//	char name[20];
//	int age;
//	double score;
//}S;
//int main()
//{
//	S s = { "张三",20,75.2 };
//	S tmp = { 0 };
//	FILE* pf = fopen("test.txt", "rb+"); //rb+是以二进制形式读写文件 ，如果该项目路径下没有test.txt这个文件，则返回空指针，所以要用wb先创建一个test.txt文件
//	//将上述结构体的数据以二进制形式存入文档后，形成的是乱码，因为是以二进制形式存储的，在文本文件上体现不出来
//	if (pf == NULL)
//		return -1;
//	//以二进制形式写文件
//	//fwrite(&s, sizeof(S), 1, pf); //要写入的数据为s的数据，所以传入s的地址，s的大小为sizeof(S),写入1个s的数据，传到pf中
//	//以二进制形式读文件
//	fread(&tmp, sizeof(S), 1, pf); //把pf中的数据读取出来存放到tmp中
//	//打印一下看看是否存放到tmp里了
//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
//	fclose(pf), pf = NULL;
//	return 0;
//}


//文件的随机读取
//之前介绍的函数在读取文件时都是顺序读取，如果要做到随机读取，这些函数则做不到
//若要随机读取文件内容，我们用到fseek这个函数
//文件读取时，文件指针指向文件中的第一个元素，然后按顺序读取
//fseek的原理是根据文件指针的位置和偏移量来定位文件指针，然后再读取达到随机读取的效果

//int fseek(FILE* stream, long int offset, int origin)
//offset是偏移量，origin是文件指针的当前位置
//fseek以当前指针位置为起点，根据偏移量调整文件指针
int main()
{
	FILE* pf = fopen("test.txt", "r");  //已知test.txt中存放了 abcdef  6个字符 
	if (pf == NULL)
		return 0;
		//定位文件指针
		//对于参数origin，给出了三个值
		//SEEK_CUR--文件指针当前位置
		//SEEK_END--文件的末尾位置
		//SEEK_SET--文件的起始位置
	//fseek(pf, 2, SEEK_CUR); //将文件指针定位到当前位置并向后偏移2 ，此时指针指向c
	fseek(pf, -2, SEEK_END); //将文件指针定位到末尾位置并向前偏移2，此时指针指向e
	  //读取文件
	printf("%c", fgetc(pf));
	return 0;
}