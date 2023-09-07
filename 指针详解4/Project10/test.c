#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ʹ������qsort������qsort������һ���⺯��������ʱҪ����ͷ�ļ�<stdlib.h>
int cmp_int(const void* e1, const void* e2)  //�ԱȽ����;��������Ժ�����Ϊcmp_int���ȽϺ����ķ���ֵ���涨Ϊint
{
	return *(int*)e1 - *(int*)e2;  //��Ϊe1��e2Ϊvoid*���ͣ��޷������÷���ֵ������ǿ������ת��Ϊint*�����ٽ����÷���ֵ
}
int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)      //�����ֱ�ӷ�������Ľ������ȡ�Ƚϵķ�ʽ���жϷ���0��1��-1����ã����ᱻǿ��ת����ʧ����
		return 1;
	else
		return -1;
	//return *(float*)e1 - *(float*)e2;//���ֱ��������õ��Ľ��Ҳ��float���ͣ����Ǻ���Ҫ�󷵻�int�ͣ����Իᱻת����int�ͣ����ܶ�ʧ����
                                	//��������ǿ��ת����int�ͣ�Ҳ���ܻᶪʧ����
}
int cmp_stu_age(const void* e1, const void* e2)  //�ṹ������Ҫ�涨һ����׼����������������������������
{
	//����ʹ������������
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age; //�Ȱ�������������ǿ��ת����struct Stu������->�������ҵ�age��Ա�������age���бȽ�
}
int cmp_stu_name(const void* e1, const void* e2)
{
	//����������������
	//�ַ���Ҳ����ֱ�ӱȽϴ�С���Ƚ��ַ����õ�strcmp�������
	//strcmp�����Ƚ��ַ����ķ���ǡ����qsort��Ҫ��ķ���ֵ��ͬ����һ��str���ڵڶ���str����1�����ڷ���0��С�ڷ���-1
	//ע�⣬strcmp�Ƚ��ַ���ʱ���ǱȽ��ַ����ĳ��ȣ����ǱȽ��ַ�����ͷ����ĸ��ACRII��ֵ�������ͬ�ͼ�������Ƚϣ�ֱ������\0�����ַ��������޹�
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);  
}
struct Stu
{
	char name[10];
	int age;
};
int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 }; 
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	struct Stu s[] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int ssz = sizeof(s) / sizeof(s[0]);
	int fsz = sizeof(f) / sizeof(f[0]);
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);  //������������arr
	qsort(f, fsz, sizeof(f[0]), cmp_float);   //���и���������f
	qsort(s, ssz, sizeof(s[0]), cmp_stu_age);  //�����������нṹ������s
	qsort(s, ssz, sizeof(s[0]), cmp_stu_name);  //�����������нṹ������s
	for (int i = 0; i < fsz; i++)
	{
		printf("%f ", s[i]);
	}
}




//�Ͻڽ���qsort������qsort������һ���⺯����ȫ����quick sort--��������������Ҫ������������
//void qsort(void* base, size_t num, size_t width, int(*compare)(const void* e1,const void* e2);
//��һ������base��Ŀ���������ʼλ�ã���Ҫ�����������Ԫ�ص�ַ������Ϊvoid*
//                                 ��Ϊqsort�������������������͵����飬���Դ�ַʱҪ��һ��ʲô�����Խ��ܵ�ָ������void*
//�ڶ�������size_t num�������Ԫ�ظ�������Ҫ����������м���Ԫ��
//����������size_t width��һ��Ԫ�ص��ֽ�������������һ��Ԫ���м����ֽ�
//���ĸ�����compare��һ������ָ�룬ָ��compare������compareָ��ĺ�����һ���ȽϺ���
//�ȽϺ�������������e1��e2��Ҫ�Ƚϵ����������ĵ�ַ������Ϊvoid*---void*���͵�ָ�룬���Խ����������͵ĵ�ַ
//void�ǿգ��޵���˼��void*ָ�����Ϳ��Խ����������͵�ָ��
//���ǲ���ͨ��void*���͵�ָ�����޸�ָ���ֵ��Ҳ���ܽ���ָ������㣨�Ӽ������Ĳ�������p++��p--������Ϊ��֪��Ҫ���ڴ��з��ʼ����ֽ�

//�ԱȽϺ�����Ҫ��
//��Ϊ��֪��Ҫ�Ƚ�ʲô���͵����ݣ����Բ�������һ����void*
//��Ϊ����������void*������ͨ��������������ֵ�����Ե����ǱȽ���ֵ��Ҫ������ֵʱ��Ҫ�Ƚ���ǿ������ת���� Ҫ�Ƚ�ʲô���͵����ݾ�ǿ��ת����ʲô����
//��ֵ�Ƚ�ʱ�����e1<e2,���ص�ֵҪ<0
//            ���e1=e2,���ص�ֵҪ=0
//            ���e1>e2,���ص�ֵҪ>0


//��ϰ
//void Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//ָ������
//	int* arr[10];
//	//����ָ��
//	int* (*parr)[10] = &arr;
//	//����ָ��
//	int(*pAdd)(int, int) = Add;
//	//����ָ������
//	int(*pArr[10])(int, int);
//	//ָ����ָ�������ָ��
//	int (*(*ppArr)[10])(int, int);
//	return 0;
//}