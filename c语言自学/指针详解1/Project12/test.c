#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//数组指针的应用
void print1(int arr[3][5], int x, int y)
{  //参数是数组的形式
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*p)[5], int x, int y)//传参传过来的arr是一维数组的地址，我们用一个数组指针来接收
{   //参数是指针的形式
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)           //因为arr用的是一个数组指针p来接收，指向的是一个数组，所以p+1跳过的不是一个整型而是一个数组
		{
			//printf("%d ", *(*(p + i) + j));//首先p+i，找到第i行的数组，*(p+i)就是再解引用找到第i行数组中的第一个元素的地址
			                            //此时的找到的第一个元素的地址再+1跳过的就是一个整型元素了，所以+j即是找到第i行数组中的第j个元素的地址
			                            //最后解引用第i行第j个元素的地址就找到了第i行第j个元素

			//printf("%d ", (*(p + i))[j]); //这样打印也是可以的，首先*(p+i)找到第i行的数组，然后第i行数组的第j个元素就用[j]来表示
			                             //等同于*(p+i)找到的是arr1/arr2/arr3，然后表示数组元素时就是arr1[j]/arr2[j]/arr3[j]

			//printf("%d ", *(p[i] + j));//p[i]相当于是二维数组中的第几行，把二维数组看成一维数组的话，p[i]就是数组里第i个元素
			                   //所以二维数组的p[i]就是第i行的数组，数组名加j就是找到该数组第j个元素的地址，最后解引用得到第j个元素

			printf("%d ", p[i][j]);//在print2函数中，我们把二维数组名传参给了一个数组指针p，p指向的是一个数组，可以说p就是arr
			                    //根据print1函数arr[i][j]的写法，一样可以写成p[i][j]

			//综合上面四种打印方式不难看出，*(p+i)==p[i]，只不过二维数组进行了一个嵌套而已
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	//print1(arr,3,5);//封装一个函数打印二维数组arr
	//传参时，arr是首元素地址，但arr是个二维数组，那么他的首元素是谁呢？要判断二维数组的首元素，就可以把二维数组看成一维数组
	//即arr[3]={arr1,arr2,arr3},可以知道，二维数组arr的首元素是一个一维数组{1，2，3，4，5}
	//这时可以用到数组指针来传参打印二维数组了，再封装一个函数print2
	print2(arr, 3, 5);
	return 0;
}




//int main()
//{
//	//数组指针打印一维数组时比较麻烦，可以说多此一举，所以，数组指针一般用在二维数组
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	//利用数组指针打印arr数组
//	for (int i = 0; i < 10; i++)
//	{
//		//printf("%d ", (*p)[i]);  //方法一,因为(*p)就是arr
//		printf("%d ", *(*p + i));  //方法二，解引用p后得到首元素地址arr，加i后再解引用就是数组的内容
//	}
//}





//数组指针：存放数组的地址的指针
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;//这是一个数组指针，存放数组的地址，因为[]的优先级高于*，所以想要表示数组指针的话要把*p括起来
//	//int *p[10]--这是一个指针数组，p首先和[]结合，说明p是一个数组，数组元素的类型是int*，说明数组里存放的是指针，所以这是一个指针数组
//	//int(*p)[10]--这是一个数组指针，p先和*结合，说明这是一个指针，且指针指向的数组有10个元素，每个元素的类型是int
//	//例题：
//	char* arr2[5];
//	char*(*pa)[5] = &arr2;//*pa表示是一个指针，指向的是&arr，arr有五个元素，所以右边加上[5]，每个元素的类型是char*，所以左边加上char*
//	return 0;
//}



//指针数组:存放指针的数组
//指针数组的作用
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//创建一个指针数组，把三个数组的首元素地址存放进去，这样可以通过一个指针数组打印出三个数组的内容
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//}
 




//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "acbdef";
//	const char* p1 = "abcdef";
//	const	char* p2 = "abcdef";//两个一模一样的常量字符串没必要存两个，所以p1，p2都指向同一块内存空间，故p1==p2 
//	if(p1==p2)                  //即p1，p2存放的都是同一个地址，但是p1，p2的地址是不同的，只是他们存放的地址相同
//		printf("hehe\n");
//	else
//		printf("haha");
//	//if (arr1 == arr2)
//	//	printf("hehe\n");
//	//else
//	//	printf("haha");
//	return 0;
//}




//int main()
//{
//	//因为"abcdef"是一个常量字符串，无法修改，所以在赋给p的时候可以加一个const在*左边，给*p赋上常量属性，这样就不能通过*p修改字符串
//	const char* p = "abcdef";//"abcdef"是一个常量字符串
//	//指针p存放的是字符串的首元素地址，即a的地址
//	*p = 'W';//利用*p将首元素修改后，代码运行不起来，原因是"abcdef"是一个常量字符串，具有常量属性，不能被修改
//	printf("%c\n", *p);//打印字符时，解引用p指向的就是a，使用%c只输出一个字符
//	printf("%s\n", p);//打印字符串时，是以p所指向的首元素开始打印直到遇到\0为止
//	return 0;
//}