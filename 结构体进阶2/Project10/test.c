#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
// 结构体内存对齐
//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//结构体内存对齐的规则：
//1.第一个成员在与结构体变量偏移量为0的地址处
//解释：这里可以类似理解成为数组地址和数组第一个元素地址的关系。数组的首元素地址其实与数组的地址相同，此时首元素与数组地址的偏移量为0
//      数组的第二个元素与数组地址的偏移量为1，以此类推。
//2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处  ，对齐数=编译器默认的一个对齐数与该成员大小的较小值（VS默认对齐数为8）
//解释：以S1为例，第一个成员类型为char，所以该成员指向位置为0的内存，S1的下一个结构体成员变量类型为int
//      那么就占4个字节，与默认对齐数8相比，4是较小值，所以该成员变量的对齐数为4，假设第一个元素地址指向位置为0的内存
//      那么类型为int的成员就要对齐到4的整数倍的地址处，所以该成员地址就要指向位置为4的内存。中间位置1，2，3的内存空间就被浪费了
//      如果是char成员在int成员后，那么占1个字节，与8相比1较小
//      所以对齐数为1，内存就要对齐1的整数倍的地址处，任何地址都是1的整数倍，所以char类型的成员地址就要指向位置为8的内存。（int占四个字节）
//3.结构体的总大小为最大对齐数（每个成员的对齐数中的最大值）的整数倍
//解释：以S1为例，三个成员变量中，对齐数最大的是int成员的对齐数，为4，所以在内存中，结构体要以4的整数倍的地址结束，此时内存已经占了9个字节的的内存了
//      但是9并不是4的整数倍，12才是4的整数倍。所以结构体变量s1的大小为12个字节，以以上条件可以判断出s2的大小为8个字节
//4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是最大对齐数（含嵌套结构体的对齐数）的整数倍。
	
//根据结构体内存对齐的规则，我们设计结构体时既要满足对齐，又要节省空间，我们的做法是：
//   尽量让占用空间小的成员集中在一起
//  例如s1和s2，s1和s2中的成员都是一样的，但是顺序不同，s2中两个较小的char类型放在一起，s2的大小就比s1的大小要小

//修改默认对齐数
//使用#pragma这个预处理指令，我们可以修改默认对齐数
//#pragma pack(4) //用#pragma pack()，可以修改默认对齐数为4
//struct S3
//{
//	char c;
//	double d;  //默认对齐数为8时，该结构体大小为16个字节
//};
//#pragma pack() // 再次使用可以还原默认对齐数
////结构在对齐方式不合适的时候，我们可以自己更改默认对齐数
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));//12
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));//8
//	struct S2 s3 = { 0 };
//	printf("%d", sizeof(s3));// 修改默认对齐数后s3结构体的大小为12
//	return 0;
//}

//当我们想知道结构体成员变量的偏移量为多少时，可以用到offsetof()这个函数,要引入头文件<stddef.h>
//offset是偏移量，offset of()就是成员相对于结构体的偏移量
//size_t offsetof (structName,memberName)  structName是结构体名，使用前要带struct 。memberName是结构体成员名
//offsetof是一个宏，宏以后会提到
#include<stddef.h>
struct S
{
	char c;
	int a;
	double d;
};
int main()
{
	printf("%zu\n", offsetof(struct S, c));
	printf("%zu\n", offsetof(struct S, a));  //%zu是输出size_t型，size_t是无符号整型
	printf("%zu\n", offsetof(struct S, d));
	return 0;
}