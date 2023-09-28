#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
//Load函数中用到了check函数，但check函数在Load函数下方，所以要声明一下check函数
void check(struct Contact* ps);
void Load(struct Contact* ps)
{
	FILE* pfread = fopen("contact.txt", "rb");
	struct Peoinfo tmp = { 0 };  //创建一个临时变量tmp用来给新通讯录赋值用
	if (pfread == NULL)
	{
		printf("LoadError:%s\n", strerror(errno));  //为了防止与写入文件时的报错混淆，我们加上LoadError来说明是加载文件时报错
		return;
	}
	//当我们将写好的通讯录数据存入文件后，重新运行程序时，原来的通讯录数据已经被清空了，此时的通讯录需要重新初始化
	//我们将文件中的先前的通讯录数据放入新初始化好的通讯录中，有可能会出现文件中的通讯录数据比初始化的通讯录的容量要多的情况
	//此时就要对新的通讯录进行扩容，所以要使用check检查通讯录的容量是否足够存放数据，如果不够就进行扩容操作
	//已知fread的返回值小于规定的读取元素个数时，数据全部读取完毕
	while (fread(&tmp, sizeof(struct Peoinfo), 1, pfread))  //将读取到的数据放入tmp中
		//设置一个while循环，令fread的读取元素个数为1，当返回值小于1时，也就是0，说明读取完全部数据，此时跳出循环
	{
		check(ps);//检测一下ps的容量是否够存放数据，如果不够就扩容
		ps->data[ps->size] = tmp; // 把tmp中的数据放入通讯录里
		ps->size++; //往通讯录中放数据时，负责记录数据个数的size也要增加
	}
}
void InitContact(struct Contact* ps)
{
	ps->data =(struct Peoinfo*) malloc(3 * sizeof(struct Peoinfo));
	if (ps == NULL)
		return;  //如果开辟空间失败，则什么都不做
	ps->size = 0;
	ps->capacity = DEFAULT_SZ; //通讯录的默认初始容量：3
	Load(ps); //加载上一次存的通讯录
}
void check(struct Contact* ps)
{
	if (ps->size == ps->capacity)  //如果通讯录满了，进行扩容
	{
		struct Peoinfo* ptr=(struct Peoinfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct Peoinfo)); //一次扩容两个，扩容的大小为 ： 原来的容量+2
		if (ptr != NULL)
		{
			ps->data = ptr;  //如果开辟成功，那么就把新开辟出来的空间的地址赋给data
			ps->capacity += 2;//容量增加2个
			printf("扩容成功\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	//ps就是通讯录的地址
	//先检测当前通讯录的容量
	//1.如果满了，就扩容
	//2.如果没满就什么都不做
	check(ps); //将检测通讯录容量封装成一个函数
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
//给通讯录以名字排序
void SortContact_byname(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp);
	printf("排序已完成\n");
}
void Destroy(struct Contact* ps)
{
	free(ps->data), ps->data = NULL;
}
//保存文件
void save(struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.txt", "wb"); //以二进制形式写入数据，能加密通讯录，效率更高
	if (pfwrite == NULL)
	{
		//为了防止与加载文件时的报错混淆，我们加上SaveError来说明是加载文件时报错
		printf("SaveError：%s\n", strerror(errno));  //如果创建失败，则打印一下创建文件失败的原因
		return; //由于函数无返回，所以这里也不返回值
	}
	//写通讯录的数据到文件中
	fwrite(ps->data, sizeof(struct Peoinfo), ps->size, pfwrite);
	fclose(pfwrite), pfwrite = NULL;
	printf("保存成功！\n");
}