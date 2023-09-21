#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
void InitContact(struct Contact* ps)
{
	//初始化通讯录时把通讯录都初始化为0，就可以用到memset这个函数
	//void* memset(void* dest ,int c ,size_t num)  其中c指的是要设置的字符，num为要设置的字节数
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初信息为0个
}
void AddContact(struct Contact* ps)
{
	//ps就是通讯录的地址
	//先判断通讯录满没满
	if (ps->size == MAX)
		printf("通讯录已满，无法增加\n");
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name); //在通讯录中找到data结构体数组，把名字放在结构体数组的第size个结构体中的name中
		                                       //name是一个char型数组，本身就是一个地址
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);   //age是int型，不是一个地址，所以输入age时要取地址
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age)); 
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele); 
		printf("请输入住址：");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
		printf("%-5s\t%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "序号", "姓名", "性别", "年龄", "电话", "住址");
	}
	else
	{
		//打印通讯录时希望打印成这样：序号  姓名    性别    年龄    电话    住址
		//                             1    张三     男      30     137...  广州市
		printf("%-5s\t%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "序号","姓名", "性别", "年龄", "电话", "住址");//%20s就是限制打印20个字符的意思，\t就是一个缩进tab
		for (int i = 0; i < ps->size; i++)  //把已有的信息一一打印出来
		{
			printf("%d\t", i + 1); //打印通讯录的序号
			printf("%-9s\t%-5s\t%-4d\t%-12s\t%-30s\n", //需要打印的数据太长可以换行
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
//我们发现，在进行查找联系人，删除联系人，修改联系人等操作的时候，都要用到同一块查找的代码，为了防止代码冗余，所以把查找功能封装成函数
//如果找到了，返回下标，没找到，返回-1
//Find_byname这个函数并不是通讯录的功能，只是为了进行通讯录功能函数的实现更加方便，所以不用声明
//我们希望它只在所在的源文件内发挥作用，在测试文件中无法使用，可以加上static使其变成静态函数
//static修饰局部变量时，可以让局部变量的生命周期变长，在局部作用域外也可以使用
//static修饰全局变量和函数时，只能让其在所在的源文件中使用
static int Find_byname(const struct Contact* ps, char name[NAME_MAX])
{
	for (int i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	if (ps->size == 0)
		printf("通讯录为空，无法进行删除操作\n");
	else
	{
		//删除数组中的内容时，是用后面的数覆盖掉前面的数，然后数组的元素个数-1
		//例如数组arr[]={1,2,3,4,5,6,7,8} ，如果要删除4，那么就用5放到4的位置，6覆盖掉5的位置，以此类推，直到最后出现两个8
		//控制数组访问的数量，那么最后一个重复的8就访问不到了，就实现了删除数组元素的功能
		char name[NAME_MAX];
		printf("请输入想要删除的联系人姓名:");
		scanf("%s",name);
		//1.查找要删除的人在什么位置
		int find = Find_byname(ps, name);
		//跳出循环有两种情况，一种是遍历了所有数组都没有找到这个人。另外一种是找到了这个人跳出循环
		if (find== -1)
			printf("通讯录无此人\n");
		else
		{  //删除联系人
			int j = 0;
			for (j = find; j < ps->size-1; j++)  //如果ps->size不-1的话就会越界访问了
			{
				ps->data[j] = ps->data[j + 1];
			}
			ps->size--;
			printf("删除成功\n");
		}
	}
}
void SearchContact(const struct Contact* ps) 
{
	char name[NAME_MAX];
	printf("请输入想要查找的人的名字：");
	scanf("%s", name);
	int find = Find_byname(ps, name);
	if (find == -1)
		printf("查无此人!\n");
	else
	{
		printf("%-9s\t%-5s\t%-4s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-9s\t%-5s\t%-4d\t%-12s\t%-30s\n", //需要打印的数据太长可以换行
			ps->data[find].name,
			ps->data[find].sex,
			ps->data[find].age,
			ps->data[find].tele,
			ps->data[find].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	printf("请输入要修改的联系人的姓名：");
	char name[NAME_MAX];
	scanf("%s", name);
	int find = Find_byname(ps, name);
	if (find == -1)
		printf("通讯录无此人！\n");
	else  //修改就是重新录一遍通讯录信息
	{
		printf("请输入名字：");
		scanf("%s", ps->data[find].name); //在通讯录中找到data结构体数组，把名字放在结构体数组的第size个结构体中的name中
		//name是一个char型数组，本身就是一个地址
		printf("请输入性别：");
		scanf("%s", ps->data[find].sex);   //age是int型，不是一个地址，所以输入age时要取地址
		printf("请输入年龄：");
		scanf("%d", &(ps->data[find].age));
		printf("请输入电话：");
		scanf("%s", ps->data[find].tele);
		printf("请输入住址：");
		scanf("%s", ps->data[find].addr);
		printf("修改成功\n");
	}
}
int cmp(const void* e1, const void* e2)
{
	return strcmp((*(struct Peoinfo*)e1).name , (*(struct Peoinfo*)e2).name);
}
void SortContact_byname(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp);
	printf("排序已完成\n");
}