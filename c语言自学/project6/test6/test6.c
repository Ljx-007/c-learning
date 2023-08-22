#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
//练习5：编写代码实现模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则提示登录成功，如果三次均输入错误，则退出程序）
int main()
{
	int i;
	char password[20] = { 0 };
	char repassword[20] = { 0 };
	printf("请设置密码：");
	scanf("%s", password);
	for (i = 0; i < 3; i++)
	{
		printf("登录请输入密码：");
		scanf("%s", repassword);
		//if (repassword== password) //==不能拿来比较两个字符串是否相等，判断两个字符串是否相等要用strcmp()--string compare这个函数
		if (strcmp(repassword, password) == 0)//如果strcmp中的两个字符串相等，则返回0值,如果第一个字符串大于第二个字符串，则返回大于0的值
		{                                     //如果第一个字符串小于第二个字符串，则返回小于0的值
			printf("登陆成功");
			break;
		}
		else
			printf("密码错误\n");
	}
	if (i >= 3)
		printf("三次均未输入正确密码，登陆失败");
	return 0;
}


//练习4：让一串字符从两边移动向中间汇聚，如 welcome to guangzhou!!
//                                          w####################!
//                                          we##################!!
//                                          .........
//                                          welcome to guangzhou!!
//int main()
//{
//	char arr1[] = "welcome to guangzhou!!";
//	char arr2[] = "######################";
//	int left = 0;
//	//char arr[]="abc"
//	//实际上数组里元素为[a b c \0]，数组元素个数为4，若右下标为数组个数-1的话那么右下标对应元素为\0
//	            //下标为 0 1 2 3
//	//数组的末尾以\0结尾，所以字符串末尾的！的下标其实是数组字符个数的倒数第二个，所以要-2
//	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2; 
//	int right = strlen(arr1) - 1;//strlen()是计算字符串的长度，不包含\0，所以-1即可，更方便
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		//休息1秒，用Sleep()函数需要引入头文件<Windows.h>
//		Sleep(1000);//意思是休息1秒继续执行程序，括号内单位是ms，1000ms=1s
//		//继续优化,system()函数是用来执行系统命令的
//		system("cls"); //cls是清空屏幕的意思，使用system函数需要引入头文件<stdlib.h>
//		//使用system()清空屏幕后，最后打印的welcome to guangzhou!!也会被清除，可以在循环结束后添一行printf代码
//		left++;
//		right--;
//	}
//	printf("welcome to guangzhou!!");
//	return 0;
//}



//练习3：从一组数中找到想要的数字
//优化算法:二分法
//int main()
//{
//	int k;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int num = sizeof(arr) / sizeof(arr[0]);//数组内数字个数
//	int left = 0;//左下标
//	int right = num - 1;//右下标
//	printf("请输入你想要查找的数字：");
//	scanf("%d", &k);                                                                     //{1，2，3，4，5，6，7，8，9，10}
//	while (left<=right)//倘若数组里没有想查找的数字，那二分法分到最后左右下标相等  //下标： 0，1，2，3，4，5，6，7，8，9
//	{             //如果左右下标相等后还是找不到数字k，则说明数组里没有这个数字，此时继续循环左下标会大于右下标
//		         //所以循环的条件是左下标小于等于右下标
//		int mid = (left + right) / 2;//取左右下标的中间值，且取整数部分
//		if (arr[mid] > k)//如果中间下标对应的中间数大于想找的数字k
//		{
//			right = mid - 1;//那么查找数字范围变成左值到中间值，此时左下标不变，右下标变为中间下标-1
//		}
//		else if (arr[mid] < k)//如果中间下标对应的中间数小于想找的数字k
//		{
//			left = mid + 1;//那么查找数字范围变成右值到中间值，此时右下标不变，左下标变为中间下标+1
//		}
//		else//如果中间下标对应的中间数刚好为想查找的数字k
//		{
//			printf("找到了，下标为：%d\n", mid);//
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("数组里没有这个数字");
//	}
//	return 0;
//}


//遍历法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k =0;
//	printf("请输入你要在数组里查找的数字:");
//	scanf("%d", &k);
//	int num = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < num; i++)
//	{
//		if (k==arr[i])
//		{
//			printf("找到了，下标为：%d", i);//遍历法的缺点是一个个遍历，速度太慢
//			break;
//		}
//	}
//	if (k > num)
//		printf("数组里没有这个数字");
//	return 0;
//}


//练习2：计算1!+2!+3!+...+10!
//int Factorial(int n)
//{
//	int i = 1;
//	int a = 1;
//	for (i = 1; i <= n; i++)
//	{
//		a *= i;//n的阶乘
//		if (x == 0)
//		{
//		printf("1");
//			break;
//		}
//	}
//	return a;
//}
//int main()
//{
//	int sum=0;
//	for (int i = 1; i <= 10; i++)
//		sum += Factorial(i);
//	printf("%d ", sum);
//}

//练习1：计算n的阶乘
//int main()
//{
//	int i = 1;
//	int a = 1;
//	int n;
//	printf("请输入数字计算其阶乘：");
//	scanf("%d",& n);
////for循环
//	for (i = 1; i <= n; i++)
//	{
//		a *= i;
//		if (n == 0)
//		{
//			printf("1");
//			break;
//		}
//	}
//	printf("%d", a);//当数字过大时会超过系统所申请的内存，就会出现其他的数字
//while循环
	//while (i<=n)
	//{
	//	if (n == 0)
	//	{
	//		printf("1");
	//		break;
	//	}
	//	a = a * i;
	//	i++;
	//}
	//printf("%d", a);
//	return 0;
//}


//do...while循环
//int main()
//{   //打印1-10 
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			//break;//直接跳出do到while判断
//			continue;//结束本次循环继续从do开始循环
//		printf("%d ", i); //先执行do代码块的内容，接着while来判断是否继续循环，判断为真，则从do开始继续循环
//		i++;
//	} while (i < 11);
//	return 0;
//}


//for循环
//for循环将代码的初始化，判断和调整部分放在了一起，相较于while更容易修改调整，因为while的初始化判断和调整部分相隔较远
//for(表达式1；表达式2；表达式3),表达式1是初始化变量，表达式2是条件判断，表达式3是循环的调整
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)//判断条件k=0为假，所以不循环	
//		printf("hehe\n");


	//for (;;)//死循环，for循环的初始化，判断和调整都可以省略，但判断如果省略了那判断条件就是恒为真
	//	printf("hehe\n");

	//10次循环
	//10个元素
	//10次打印
	//for (int i = 0; i <10; i++)//for循环语句先执行初始化部分，接着判断表达式2是否为真，为真则执行for循环内的语句
	//	                       //执行完循环内语句后在执行表达式3调整部分，接着继续判断表达式2是否为真，若为假则跳出循环。
	//{                          //for循环建议使用左闭右开的区间
	//	if (i == 5)
	//		//break;
	//		continue;
	//	printf("%d ", i);
	//}
//	return 0;
//}


//int main()
//{
//	int ch;
//	while ((ch = getchar())!=EOF)//EOF是文件结束标志，在windows里代表ctrl+z
//	{
//		if (ch < '0' || ch>'9')//ch小于字符0大于字符9
//			continue;
//		putchar(ch);//意思是输入0-9之外的数字都不能被打印
//	}
//	return 0;
//}



//getchar()的用法
//int main()
//{
//	//int ch = getchar();//getchar()是输入一个字符，get：获取，char：字符
//	//while ((ch = getchar()) != EOF)//EOF是end of file的意思，是文件结束标志，值为-1
//	//	putchar(ch);//与getchar对应，是输出字符的意思，与printf("%c\n", ch)输出结果相同
//	////printf("%c\n", ch);
//
//	//以上代码的用处
//	char password[20] = { 0 };
//	int ret = 0;
//	char ch;
//	printf("请输入密码：");
//	scanf("%s", password);//输入密码并存放在password数组中  
//	//scanf_s会进行边界检查，调用该函数时要提供一个数字以表明最多提取多少个字符
//	//报错写法：scanf_s("%s",password);
//	//正确写法： scanf_s("%s",password,sizeof(password));
//	//password被定义为一个数组，数组本身就是一个地址，故不用取地址符&
//	//输入密码后输入缓冲区还留下一个'\n'未被读取，于是被ret=getchar()读取走，并没有达到想要的效果
//	//想要把'\n'读取走，多加一步getchar()
//	//getchar();//如果在输入密码时有别的字符输入如123456 ABCD，那么123456被scanf读走，中间的空格被getchar()读走，ABCD被ret读走
//	          //那程序又会变成我们不想要的样子，直接打印“放弃确认”，要解决这个问题，需要使用一个循环让getchar()一直读取
//	          //但调试时使用监视可知，123456后的字符一直被循环的getchar读取，故即使输入123456 ABCD后，password也只有123456
//	while (ch = getchar() != '\n')//或while(ch=getchar()!=EOF)
//	{
//		;//执行一个空语句，
//	}
//	printf("请确认密码（Y/N）：");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功");
//	}
//	else
//	{
//		printf("放弃确认");
//	}
//	return 0;
//}