#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//上节谈到文件随机读取，用到的是fseek函数
//int fseek(FILE* stream,long offset,int origin);
//offset是偏移量，origin是文件指针的当前位置
//对于参数origin，给出了三个值
//SEEK_CUR--文件指针当前位置
//SEEK_END--文件的末尾位置
//SEEK_SET--文件的起始位置
//fseek以当前指针位置为起点，根据偏移量调整文件指针

//ftell--返回文件指针相对于起始位置的偏移量
//long ftell(FILE* stream)
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		return 0;
//	//fputs("abcdef", pf); //创建一个文档并写入abcdef
//	//定位文件指针
//	fseek(pf, 3, SEEK_CUR); //此时指向d
//	int pos = ftell(pf);  //获取此时指针相对起始位置的偏移量
//	printf("%d", pos);
//	fclose(pf), pf = NULL;
//	return 0;
//}

//rewind--让文件指针的位置回到文件的起始位置
//void rewind(FILE* stream)
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		return 0;
//	//fputs("abcdef", pf); //创建一个文档并写入abcdef
//	//定位文件指针
//	fseek(pf, 3, SEEK_CUR); //此时指向d
//	rewind(pf);  //让文件指针指向起始位置
//	int pos = ftell(pf);  //获取此时指针相对起始位置的偏移量
//	printf("%d", pos);
//	fclose(pf), pf = NULL;
//	return 0;
//}


//文件读取结束有两种情况
//1.文件读取失败结束
//2.文件读取到文件尾结束

//假如一个文件中什么也没有，那么读取时就相当于读到文件尾了，文件以EOF结尾，EOF被定义为-1，也就是说，文件什么都没有时，读取他就会返回-1的值
//实际应用中，文本文件：我们使用fgetc或者fgets来读取文件，文件是否读取结束的标志是：用fgetc读到EOF，或者用fgets返回了一个空指针
//            二进制文件：判断读取结束的标志是fread的返回值小于一次读取的元素个数
//但当读取文件结束时，我们并不清楚文件读取结束是因为读取失败结束了还是因为读取到文件尾结束
//此时就会用到  feof 和ferror 函数来判断读取结束的原因

//int feof(FILE* stream)--判断文件是否是读到文件尾结束的
//如果文件流是以读取到文件尾形式结束的，那么返回非零值。如果不是，返回0
//int ferror(FILE* stream)--判断文件是否是因为错误结束的
//如果文件读取时遇到错误结束，那么返回非零值，如果不是，返回0
int main()
{
	int ch; //这里用ch来接收读取的字符，用int的原因是读取到文件结尾会接收到EOF，EOF是-1
	FILE* pf = fopen("test2.txt", "r"); //这里设置一个不存在的文件，目的是让文件打开失败
	if (!pf)  //!是取反，如果打开失败，那么pf=NULL，NULL值为0，取反后为1，则进入if语句，功能与pf==NULL相同，只不过更加简便
	{
		perror("open file test2.txt"); //perror的功能与strerror(errno)相似，perror也会报错误原因，并且不需要用printf和errno，相较于strerror(errno)更加简便
		//perror的参数是一个字符串，打印错误原因时会先打印字符串的内容，再加一个冒号和空格，然后打印错误原因
		//即  open file test2.txt: （错误原因）  这样在运行代码时更加人性化，给用户提示是在做什么事情的时候发生了错误，错误原因是什么
		return -1;
	}
	//读文件
	while ((ch = fgetc(pf)) != EOF)  //用ch来接收fgetc读取到的字符，如果没读到EOF，那就进入循环一直打印读出来的字符
	//如果是二进制读取文件，则while循环这样写：
	//while(fread(&ch,sizeof(char),1,pf)>=1)  一次读取到的元素个数小于规定的一次读取元素个数，则说明读取结束
	{
		putchar(ch); //打印读到的字符
	}
	if (ferror(pf)) //如果因为错误而结束读取文件，ferror返回非0值，此时进入if语句
	{
		printf("error\n");
	}
	else if (feof(pf))  //如果因为读到文件尾结束，feof返回非0值，此时进入else if语句
		printf("end of file successfully\n");
	fclose(pf), pf = NULL;
	return 0;
}