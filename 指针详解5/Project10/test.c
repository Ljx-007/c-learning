#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�Լ�дһ������ʵ��qsort������������������Ĺ���
struct Stu
{
	char name[20];
	int age;
};
void Swap(char* num1, char* num2, int width)
{
	for (int i = 0; i < width; i++) //������ֵʱһ���ֽ�һ���ֽڽ���
		//��11 22 33 44��55 66 77 88����ʱ����Ϊ��char*���ͣ�����ֻ�ܽ���һ���ֽ�
 //����һ���ֽں��Ϊ55 22 33 44��11 66 77 88��num1��num2����ָ��������һ���ֽڷ��ʵ� 22��66���ڽ���22��66�Ľ���
//�Դ����ƣ�ֱ�������������ֽڣ����ֽ�������width����������Swap�����Ĳ�����Ҫ��һ��width
	{
		char tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
		num1++, num2++;
	}
}
//ð������ʱ���ܱ�֤������������ͣ�������void*����
//ð����������forѭ�����ⲻ�ˣ�����Ҫ֪�������Ԫ�ظ���sz
//��Ϊ��֪������Ԫ�����ͣ��޷������÷��ʣ�������Ҫ֪��������ռ���ֽ�
//�Ƚ�����Ԫ��ʱ����Ҫ֪������Ԫ�صıȽϷ���������Ҫ����һ���ȽϺ�������һ������ָ��
void bubble_sort(void* arr, int sz, int width, int (*cmp)(void* e1, void* e2)) 
{
	//һ��
	for (int i = 0; i < sz - 1; i++)
	{
		//һ�˵������Ƚ�
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//��Ϊ��֪��������������ͣ�������Ҫ֪������Ԫ����ռ���ֽ���width
			//��Ȼ��֪�����ͣ���֪���÷��ʶ��ٸ��ֽڣ��Ǿ�ȫ��ת����char*���ͣ�һ���ֽ�һ���ֽڵķ���
			//arr����Ԫ�ص�ַ��Ҫ���ʵ���һ��Ԫ�صĵ�ַ��Ҫ����width���ֽڣ�����ת����char*��+width�Ϳ�������width���ֽڷ��ʵ���һ��Ԫ�صĵ�ַ
			//�ɹ����ʵ���һ��Ԫ�صĵ�ַ����������Ҫ�ܹ������������飬����+j*width�������Ϳ��ԱȽ�������ǰ����Ԫ�غ�����Ƚ�������Ԫ����
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0)
				//�����������Ԫ�صıȽϣ���д�ıȽϺ�������ֵ>0����˵��ǰһ��Ԫ�ش��ں�һ��Ԫ�أ���Ҫ����
			{
				//�����װһ��Swap��������������Ԫ��
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
{     //����ṹ��ȴ�С�ó�Աage����
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




//��ϰ
//qsort����
//void qsort(void* base,size_t num,size_t width,int (*cmp)(const void* e1,const void* e2))
//����1����Ҫ������������Ԫ�ص�ַ--Ҳ����������
//����2�������Ԫ�ظ���
//����3��һ������Ԫ����ռ���ֽڴ�С
//����4���ȽϺ���cmp��ָ��
//�ȽϺ���cmp��e1,e2������Ҫ�ȽϵĲ����ĵ�ַ����Ϊ����Ϊvoid*���޷������÷��ʣ�����Ҫǿ������ת�����ú���Ҫʹ�����Լ�ʵ�֣�
//e1>e2,�ú�������ֵ>0
//e1=e2,�ú�������ֵ=0
//e1<e2,�ú�������ֵ<0