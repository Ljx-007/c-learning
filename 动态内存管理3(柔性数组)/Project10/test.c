#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//柔性数组--C99中结构中的最后一个元素允许是未知大小的数组，这就叫做柔性数组成员
struct S
{
	int n;
	int arr[];//未知大小的
	//或者写成int arr[0]，也代表未知大小的数组，这样的数组被称为柔性数组成员
	//柔性数组的大小是可以调整的
};
int main()
{
	struct S s;
	printf("%d", sizeof(s));//这里打印结构体大小的结果为4，说明在计算结构体大小时柔性数组的大小不计算在内
	//所以只计算柔性数组之前的元素的大小：一个int的大小
	//柔性数组被称为柔性数组，是因其大小可变，那如何做到大小可变呢？
	//我们使用malloc来给结构体申请内存，已知结构体的大小是不把柔性数组计算在内的，所以我们申请完结构体大小的空间后，还可以继续申请
	//在这之后申请了多少的空间，就属于柔性数组的空间了，所以柔性数组的大小是根据我们申请了多少空间而变化的
	//这里我们给柔性数组申请了5个整型的空间，说明数组arr能存放五个整型
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	ps->n = 100;
	for (int i = 0; i < 5; i++)
	{
		ps->arr[i] = i; //把柔性数组的成员改成0，1，2，3，4
	}
	//修改柔性数组大小，用realloc即可
	struct S* ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int));//把柔性数组大小修改成10个整型
	//判断指针ptr
	if (ptr != NULL)
	{
		ps = ptr;
	}
	for (int i = 5; i < 10; i++)
	{
		ps->arr[i] = i; //把数组多出来的空间也赋值
	}
	//检验一下修改数组大小是否成功
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//释放空间
	free(ps), ps = NULL;
	return 0;
}

//相比于动态内存开辟一个结构体大小的空间，再对结构体里面的数组进行动态内存开辟，柔性数组的好处是
//1.只用free 1次，开辟了多少次空间，就要free多少次空间，柔性数组一次性开辟空间，方便了内存一次性释放，而不用多次释放
//2.访问速度快，柔性数组开辟的内存是连续的，而两次动态开辟的内存不一定是连续的，不连续就会造成访问速度慢，电脑访问连续内存的速度高于不连续的