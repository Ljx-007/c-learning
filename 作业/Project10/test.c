#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//输入一个整型数组，调整数组顺序使奇数全部位于偶数前面
void my_sort(int arr[],int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] % 2 == 0)
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;			
			}
		}
	}
}
int main()
{
	int arr[] = { 1,3,5,6,7,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


//模拟实现strcpy函数
//void my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	if (src != NULL && dest != NULL)
//	{
//		while(*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
//int main()
//{
//	char pa[] = "*********";
//	char pb[] = "ljx666";
//	//strcpy(pa, pb);
//	my_strcpy(pa, pb);
//	printf("%s", pa);
//}




//模拟实现strlen函数
//方法一：递归
//int my_strlen(char ch[])
//{
//	if (*ch != '\0')
//		return 1 + my_strlen(ch + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char ch[] = "abcdef";
//	printf("%d", my_strlen(ch));
//	return 0;
//}


//方法二：
//int my_strlen(char ch[])
//{
//	int count = 0;
//	while (*ch != '\0')
//	{
//		count++;
//		ch++;
//	}
//	return count;
//}
//int main()
//{
//	char ch[] = "abcdefg";
//	printf("%d", my_strlen(ch));
//	return 0;
//}



//喝汽水问题：1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，能够买多少瓶汽水？（编程实现）
//方法一：递归实现
//int cmpt(int empty)
//{
//	if (empty > 1) //空瓶数要大于1瓶才能换汽水
//	{
//		if (empty % 2 == 1) //假如空瓶数是奇数，则可以多换一瓶汽水，因为3个空瓶能换两瓶汽水，五个空瓶能换3瓶汽水，以此类推，2k-1个空瓶，能换(2k-1)/2+1瓶汽水
//			return empty + 1 + cmpt(empty / 2);
//		else    //如果空瓶数是偶数，那么就刚好能换空瓶数一半的汽水
//			return empty + cmpt(empty / 2);
//	}
//	else //空瓶数小于等于1不能换汽水，所以返回1
//		return 1;
//}
//int main()
//{
//	int money = 50;
//	int water = 1;
//	int empty=cmpt(money / water);
//	printf("%d", empty);
//	return 0;
//}

//方法二：
//int main()
//{
//	int money = 20;
//	int water = 1;
//	int empty = money / water; //空瓶数量
//	int total = empty; //喝过的汽水瓶数
//	while (empty > 1)
//	{
//		total += empty / 2;//两个空瓶换一瓶汽水，换完后加在喝过的汽水瓶数上
//		empty= empty / 2+empty%2; //换完后再计算空瓶的数量，空瓶数是奇数时会多出一瓶，所以要加上empty%2
//	}
//	printf("%d", total);
//  return 0;
//}

//方法三：
//int main()
//{
//	int money = 20;
//	int water = 1;
//	int total;
//	if (money == 0)
//		total = 0;     
//	else
//		total = 2 * money - 1; //一瓶汽水1块钱，两个空瓶换一瓶汽水，则1块钱能买两个空瓶，空瓶值0.5块钱，那么一瓶汽水里的汽水就值0.5块钱
//	                        //20块就能买40个瓶子里的汽水或者40个空瓶，但是汽水不能离开瓶子而存在，所以最后一定会留下一个空瓶子来装汽水，所以能换到的是39瓶
//	                   //结果就是能买到的汽水是2倍的钱数再减1
//	printf("%d", total);
//	return 0;
//}