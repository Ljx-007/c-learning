#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//strtok函数--用来取得被某一个字符或者多个字符分成的段
//例如192.168.32.115，这些数字被.分为一段一段的。strtok函数就取得192 168 32 115这样一段一段的数
//如：ljx@qq.com，则ljx qq com被@和.分成了三段，strtok函数就取得这样的三段字符
//函数参数: char* strtok(char* str,const char* sep)
//sep参数是个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中的一个或者多个分割符分割的标记
//strtok函数找到str中的下一个标记并用'\0'结尾，返回一个指向这个标记的指针

//例如"ljx@qq.com"这个字符串，调用strtok函数时，函数会先找到@，并把@改成\0，然后返回'l'的地址
// 第二次使用strtok时，第一个参数传NULL，strtok函数就会从q开始找，找到分割符'.'，把.改为\0，然后返回'q'的地址
// 第三次使用strtok时，第一个参数传NULL，strtok函数就会从c开始找，往后找不到分割符了，就返回'c'的地址
// 如果字符串中不存在更多的标记，则返回NULL指针
// 
// 如果有两个分割符连在一起，说明中间是一个空串，则什么也不输出。
// 
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改）
//所以一般在使用strtok函数的时候会先拷贝一份源字符串，尽量不要改变源字符串
//int main()
//{
//	char arr[] = "ljx@qq.com";
//	char* p = "@.";
//	char cpy[1024] = { 0 };
//	strcpy(cpy, arr); //拷贝一份源字符串，然后再修改arr
//	//一份示例，这样写太挫了
//	//char* ret=strtok(arr, p); //arr是一个被由p指向的字符切割的一个字符串
//	/*printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//
//	//换个写法,巧妙运用for循环，能很好地打印出被分割的字符
//	char* ret = NULL;
//	//for循环的初始化部分只执行一次，正好满足strtok函数第一个参数只传一次字符串，其他都传指针的用法。
//	//第一次循环下来打印了第一个被分割的字符串，然后ret= strtok(NULL, p)，即往后的循环strtok的第一个参数都会传入NULL
//	//当再也找不到分割符时，ret就变为NULL，此时结束循环
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//strerror--把错误码转换为对应的错误信息
//char* strerror(int errnum)  errnum就是错误码
//int main()
//{   //0--No error
//	//1--Operation not permitted
//	//2--No such file or directory
//	//3--No such process
//	//....
//	//char* str = strerror(3);
//	//不同的错误码对应着不同的错误信息
//	//使用strerror这个函数时，参数一般使用errno->strerror(errno)
//	//errno是一个全局的错误码变量，需要引入头文件<errno.h>
//	//当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
//	
//	//举个例子
//	FILE* pf = fopen("test.docx", "r");//fopen是打开文件，打开的是test.txt文件，形式是"r"--只读，并返回一个指针pf，类型为FILE
//	//打开的文件需要在对应项目文件夹下才能打开
//	if (pf == NULL) //如果返回的指针pf为空值，说明打开文件失败。打开文件夹失败有很多原因，如：没有此文件夹，访问权限不够等等
//		 //我们想知道打开文件夹失败到底是什么原因，代码执行失败时的错误码被赋值到了errno中
//		//使用strerror(errno)，就能知道代码执行错误的具体原因
//		printf("%s\n", strerror(errno));
//	else
//		printf("open file success");
//	return 0;
//}


//字符函数  --使用字符函数要引入头文件<ctype.h>
//字符分类函数 -- 如果它的参数符合下列条件就返回真（非0的数），不符合条件就返回0
//iscntrl  --  任何控制字符
//isspace  --  任何空白字符：空格，换页符'\f'，换行'\n' ，回车'\r',制表符'\t' 或者垂直制表符'\v'
//isdigit  --  十进制数字0-9
//isxdigit --  十六进制数字，包括所有十进制数字，小写字母a-f，大写字母A-F
//islower  --  小写字母a-z
// isupper --  大写字母A-Z
// isalpha -- 字母a-z或A-Z
// isalnum  -- 字母或数字，a-z或A-Z或0-9
// ispunct  -- 标点符号，任何不属于数字或者字母的图形字符（可打印）
// isgraph  -- 任何图形字符
// isprint -- 任何可打印字符，包括图形字符和空白字符(控制字符就不是可打印字符）
// 
//字符转换函数
//常用的有
//int tolower(int c)  --大写转小写
//int toupper(int c)  --小写转大写
#include<ctype.h>
int main()
{
	int ret = isgraph('a');
	printf("%d", ret);
	return 0;
}