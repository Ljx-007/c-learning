#include <stdio.h>
//getchar()的用法
int main()
{
	int ch = getchar();//getchar()是输入一个字符，get：获取，char：字符
	while((ch=getchar())!=EOF)//EOF是end of file的意思，是文件结束标志，值为-1
		putchar(ch);//与getchar对应，是输出字符的意思，与printf("%c\n", ch)输出结果相同
	//printf("%c\n", ch);
	return 0;
}


//while循环   break 与continue的使用
//int main() 
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
////			break;//break跳出循环
//			continue;//continue是终止本次循环，后面的代码都不执行，直接跳到while语句的判断部分，进行下一次循环的入口判断
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//switch语句，在多语句分支的情况下，使用多个if，else语句太过繁琐，故switch语句专门用在多语句分支的情况下
//int main()
//{
//	int day;
//	scanf_s("%d", &day);
//	switch (day)//switch后输入的数是几就从第几个case进入且输入的必须是个整型
//	{//switch也可以嵌套使用
//	//如果想表示1-5是工作日，6-7是休息日的话，程序还可以这么写
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日");
//			break;
//	case 6:
//	case 7:
//		printf("休息日");
//		break;  
//	default://default是默认的意思，当输入的数字超过了case的数量，则默认进入default
//		printf("输入错误");
//		break;
	//case 1://case后必须是整型常量表达式，不是整型不是常量都不可以
	//	printf("星期1\n");
	//	break;//如果没有break进入case后会继续执行后面的case，若想要跳出case则要用break
	//case 2:
	//	printf("星期2\n");
	//	break;
	//case 3:
	//	printf("星期3\n");
	//	break;
	//case 4:
	//	printf("星期4\n"); 
	//	break;
	//case 5:
	//	printf("星期5\n");
	//	break;
	//case 6:
	//	printf("星期6\n");
	//	break;
	//case 7:
	//	printf("星期7\n");
	//	break;
//	}
//	return 0;
//}


//判断奇数及打印1-100内的奇数
//int main()
//{
//	/*int a;
//	scanf_s("%d", &a);
//	if (a % 2 == 1)
//		printf("奇数\n");
//	else
//		printf("偶数\n");*/
//	int i = 0;
//	while (i < 100)
//	{
//		if ((i + 1) % 2 == 1)
//			printf("%d ", i + 1);
//		i++;
//	}
//
//	return 0;
//}


//选择语句
//if 和 else的匹配问题
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else//else只和最近的未匹配的if匹配（就近原则）。如果此处else与第一个if对齐，输出的结果依然是与第二个if匹配的结果
//			printf("haha\n");//如果想要输出haha，则需要给第一个if语句下加上{}
//	return 0;
//}


//int main()
//{
//	int age = 29;
//	if (age < 18)//选择语句如果有多条指令要加{}
//		printf("未成年");
//	//else if (18 <= age < 28)//这样表示程序会先执行18<=age，判定为真则为1。然后1<28为真，执行该语句。
//	else if(age>=18&&age<28)//若想表示age在18-28这个区间则用逻辑与&&操作符表示
//		printf("青年");
//	else
//		printf("大人");
//
//}