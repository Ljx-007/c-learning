#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//char p[]="hello world"和char* p="hello world"的区别
//char p[]="hello world"是创建了一个字符数组p，数组的内容是字符串"hello world"
//另外创建char p2[]="hello world"，p2和p1是两个不同的字符数组，他们分别代表了各自数组的首元素地址，是不相等的

//char* p1="hello world"是把"hello world"这个常量字符串的首元素地址存放到p中
//char* p2="hello world"也是一样，也是把"hello world"这个常量字符串的首元素地址存放到p2中
//"hello world"这个常量字符串的首元素地址不变，只不过分别存储到了p1，p2这两个指针变量中，所以p1=p2

//char p[]="hello world"里的hello world是数组的内容，可以随意修改。char* p="hello world"里的hello world是一个常量字符串，不能修改
//所以两种表示"hello world"的方式是不一样的




//练习1：5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三
//B选手说：我第二，E第四
//C选手说：我第一，D第二
//D选手说：C最后，我第三，
//E选手说：我第四，A第一
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次
int main()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b==2)+(a==3)==1)&&
							((b==2)+(e==4)==1)&&       //此处条件较长，可以换行来写。
							((c==1)+(d==2)==1)&&    //另外，不能用(b==2||a==3)==1这样的写法，因为看似一真一假返回1，两个假返回0符合题意
							((c==5)+(d==3)==1)&&    //但是如果其中一位选手都说对了，也返回1，这时候遍历出来会出现两种情况，不符合题意了
							((e==4)+(a==1)==1))
						{
							if(a*b*c*d*e==120) //这里还要保证abcde各不相同，所以a*b*c*d*e就一定等于120，不用再冗杂的写a!=b,a!=c这样的代码了
								printf("a=%d , b=%d , c=%d , d=%d , e=%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	return 0;
}