#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//�Ͻڿ����ǽ������ַ����������ַ���������ר�����������ַ�����
//����strcmp���Ƚ������ַ�����strcpy������һ���ַ�������ô���Ҫ�����������͵����飨���ͣ������ͣ��ṹ�壩���ָ���ô�죿
//������һ������Ҫѧϰmemcpy��memmove��memcmp��memset�⼸������
//memcpy���ڴ濽�������Կ����������͵����顣����Ҫ���ո������͵Ĳ��������ҷ��أ�����memcpy���ص���void*����
//void* memcpy(void* destination,const void* source,size_t num) ,����num��Ҫ�������ֽ���	
//struct stu
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	assert(dest && src);
//	void* start = dest;
//	//void*���Խ����������͵�ָ�룬�����޷������÷��ʡ�
//	//��������Ҫͨ��ָ��dest���ʵ���������ݣ��ֲ�֪����ʲô���ͣ���Ҫǿ��ת��Ϊchar* ����
//	//��������size_t num����������Ҫ�������ֽڣ�תΪchar*����ô�Ϳ���num�ξͿ�����
//	while (num--)
//	{
//		*(char*)dest = *(char*)src; //������һ���ֽں�dest��srcҪ++��
//		//���������ǿ������ת���Ļ�dest��src�ǲ���++�ģ�����Ҫ++�Ļ�����Ҫ����
//		++(char*)dest, ++(char*)src;//���ﲻ�ܺ���++����Ϊ���ȼ�������++ > ǿ������ת�� > ǰ��++
//	}
//	return start;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5};
//	int arr2[5] = { 0 };
//	struct stu s[] = { {"wangwu",18},{"zhangsan",20} };
//	struct stu s2[2] = { 0 };
//	//ģ��ʵ��
//	my_memcpy(s2, s, sizeof(s));
//	//memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}
//��ʹ��memcpyʱ�����Ҫ��һ�������һ�����ֿ�����ͬһ���������һ���ط�����ô�ͻ�ʧ��
//����int arr[]={1,2,3,4,5,6,7,8,9,10}����arr�е�1��2��3��4��5������3��4��5��6��7��λ��
//�����memcpy����ôд��Ϊmemcpy(arr+2,arr,20)���������������ô����ָ��ǵ������������Ϊ1��2��1��2��1��2��1��8��9��10
//Ϊ�˽������������һ��ר�ŵĿ⺯������memmove

//memmove
//char* memmove(void* dest,const char* src,size_t num)

void* my_memmove(void* dest, const char* src, size_t num)
{
	assert(dest && src);
	void* start = dest;
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest, ++(char*)src;
		}
	}
	else if (dest > src)
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return start;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//memcpy(arr + 2, arr, 20);  ��vs2022�������У�memcpyҲ�ܴ����ڴ��ص������
	//memmove(arr + 2, arr, 20);//�����ڴ��ص������
	//C���Ա�׼�涨��memcpyֻҪ�����ص����ڴ濽���Ϳ��ԡ�memmove�����ص����ڴ濽��
	//memmove�����ص����߲��ص����ڴ濽�������ԣ�������vs�������У�memcpyҲ���д����ڴ��ص��Ĺ���
	
	//ģ��ʵ��
	my_memmove(arr, arr+2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}