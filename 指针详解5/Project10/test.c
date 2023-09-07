#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//自己写一个函数实现qsort能排序任意类型数组的功能
struct Stu
{
	char name[20];
	int age;
};
void Swap(char* num1, char* num2, int width)
{
	for (int i = 0; i < width; i++) //交换两值时一个字节一个字节交换
		//如11 22 33 44和55 66 77 88交换时，因为是char*类型，所以只能交换一个字节
 //交换一个字节后变为55 22 33 44和11 66 77 88，num1和num2两个指针往后跳一个字节访问到 22和66，在进行22和66的交换
//以此类推，直到访问完所有字节，而字节数就由width决定，所以Swap函数的参数中要传一个width
	{
		char tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
		num1++, num2++;
	}
}
//冒泡排序时不能保证所排数组的类型，所以用void*接收
//冒泡排序两个for循环避免不了，所以要知道数组的元素个数sz
//因为不知道数组元素类型，无法解引用访问，所以需要知道他们所占的字节
//比较两个元素时，需要知道两个元素的比较方法，所以要调用一个比较函数，传一个函数指针
void bubble_sort(void* arr, int sz, int width, int (*cmp)(void* e1, void* e2)) 
{
	//一趟
	for (int i = 0; i < sz - 1; i++)
	{
		//一趟的两两比较
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//因为不知道所排数组的类型，所以需要知道数组元素所占的字节数width
			//既然不知道类型，不知道该访问多少个字节，那就全部转换成char*类型，一个字节一个字节的访问
			//arr是首元素地址，要访问到下一个元素的地址则要跳过width个字节，所以转换成char*后+width就可以跳过width个字节访问到下一个元素的地址
			//成功访问到下一个元素的地址还不够，还要能够遍历整个数组，所以+j*width，这样就可以比较完数组前两个元素后继续比较下两个元素了
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0)
				//这里进行两个元素的比较，所写的比较函数返回值>0，则说明前一个元素大于后一个元素，需要交换
			{
				//这里封装一个Swap函数来交换两个元素
				Swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
			}
		}
	}
}

int cmp_int(void* e1, void* e2)
{
	return *((int*)e1) - *((int*)e2);
}
int  cmp_stu(void* e1, void* e2)
{     //这里结构体比大小用成员age来比
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	struct Stu s[3] = { {"zhangsan",25},{"lisi",32},{"wangwu",18} };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	int sz2 = sizeof(s) / sizeof(s[0]);
	bubble_sort(arr,sz1,sizeof(arr[0]),cmp_int);
	bubble_sort(s,sz2,sizeof(s[0]),cmp_stu);
	return 0;
 }




//复习
//qsort函数
//void qsort(void* base,size_t num,size_t width,int (*cmp)(const void* e1,const void* e2))
//参数1：所要排序的数组的首元素地址--也就是数组名
//参数2：数组的元素个数
//参数3：一个数组元素所占的字节大小
//参数4：比较函数cmp的指针
//比较函数cmp：e1,e2是两个要比较的参数的地址，因为类型为void*，无法解引用访问，所以要强制类型转换（该函数要使用者自己实现）
//e1>e2,该函数返回值>0
//e1=e2,该函数返回值=0
//e1<e2,该函数返回值<0