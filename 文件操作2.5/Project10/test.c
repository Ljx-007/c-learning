#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//fread--����������
//fwrite--���������

//size_t fwrite(const void* buffer , size_t size , size_t count ,FILE* stream)
//buffer��Ҫд�����ݵĿռ�ĵ�ַ
//size��Ҫд���Ԫ�صĴ�С����λ���ֽ�
//count�����Ҫ��д���Ԫ�ظ���

//size_t fread(const void* buffer , size_t size , size_t count ,FILE* stream)
//buffer�Ƕ�ȡ���ݺ��ŵ�λ��
//size�Ƕ�ȡ���ݵĴ�С
//count�����Ҫ��ȡ��Ԫ�ظ���
//fread�ķ���ֵ��size_t�����������Ԫ�ظ��� ��������55��Ԫ����Ҫ��ȡ�����涨freadһ��ֻ�ܶ�10������ô����5�κ�freadһ����ȡ��50�����ݣ��ٶ�ȡһ�ξ�ֻ��ȡ��5������
//��ô���һ�ζ�ȡfreadֻ����������5�����������5��Ԫ�أ��������fread�ķ���ֵ��countСʱ��˵�������Ѿ�ȫ����ȡ����
//typedef struct S
//{
//	char name[20];
//	int age;
//	double score;
//}S;
//int main()
//{
//	S s = { "����",20,75.2 };
//	S tmp = { 0 };
//	FILE* pf = fopen("test.txt", "rb+"); //rb+���Զ�������ʽ��д�ļ� ���������Ŀ·����û��test.txt����ļ����򷵻ؿ�ָ�룬����Ҫ��wb�ȴ���һ��test.txt�ļ�
//	//�������ṹ��������Զ�������ʽ�����ĵ����γɵ������룬��Ϊ���Զ�������ʽ�洢�ģ����ı��ļ������ֲ�����
//	if (pf == NULL)
//		return -1;
//	//�Զ�������ʽд�ļ�
//	//fwrite(&s, sizeof(S), 1, pf); //Ҫд�������Ϊs�����ݣ����Դ���s�ĵ�ַ��s�Ĵ�СΪsizeof(S),д��1��s�����ݣ�����pf��
//	//�Զ�������ʽ���ļ�
//	fread(&tmp, sizeof(S), 1, pf); //��pf�е����ݶ�ȡ������ŵ�tmp��
//	//��ӡһ�¿����Ƿ��ŵ�tmp����
//	printf("%s %d %f", tmp.name, tmp.age, tmp.score);
//	fclose(pf), pf = NULL;
//	return 0;
//}


//�ļ��������ȡ
//֮ǰ���ܵĺ����ڶ�ȡ�ļ�ʱ����˳���ȡ�����Ҫ���������ȡ����Щ������������
//��Ҫ�����ȡ�ļ����ݣ������õ�fseek�������
//�ļ���ȡʱ���ļ�ָ��ָ���ļ��еĵ�һ��Ԫ�أ�Ȼ��˳���ȡ
//fseek��ԭ���Ǹ����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ�룬Ȼ���ٶ�ȡ�ﵽ�����ȡ��Ч��

//int fseek(FILE* stream, long int offset, int origin)
//offset��ƫ������origin���ļ�ָ��ĵ�ǰλ��
//fseek�Ե�ǰָ��λ��Ϊ��㣬����ƫ���������ļ�ָ��
int main()
{
	FILE* pf = fopen("test.txt", "r");  //��֪test.txt�д���� abcdef  6���ַ� 
	if (pf == NULL)
		return 0;
		//��λ�ļ�ָ��
		//���ڲ���origin������������ֵ
		//SEEK_CUR--�ļ�ָ�뵱ǰλ��
		//SEEK_END--�ļ���ĩβλ��
		//SEEK_SET--�ļ�����ʼλ��
	//fseek(pf, 2, SEEK_CUR); //���ļ�ָ�붨λ����ǰλ�ò����ƫ��2 ����ʱָ��ָ��c
	fseek(pf, -2, SEEK_END); //���ļ�ָ�붨λ��ĩβλ�ò���ǰƫ��2����ʱָ��ָ��e
	  //��ȡ�ļ�
	printf("%c", fgetc(pf));
	return 0;
}