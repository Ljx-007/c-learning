#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//�ı��е���������--fgets��fputs
//һ����������һ���ı�
//fgets--���������ж�ȡ��Ϣ
//char* fgets(char* string,int n,FILE* stream)
//��һ�������ǻ�ȡ�����ַ�����ŵ�λ�ã��ڶ�������������ȡ���ٸ��ַ�����������������������ʲô���ж�ȡ��Ϣ

//fputs--���һ���ַ���������
//int fputs(const char* string,FILE* stream)
//�����ַ���string�������stream��
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");  //д��Ҫ��"w",��ȡҪ��"r"����Ȼ�ͻ��������������
//	char str[30] = { 0 };
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return -1;
//	}
//	fputs("�޵б�����", pf);
//	fgets(str, 30, pf);  
//	puts(str);//puts���������һ�д��뵽��Ļ��
//	//puts�������Զ����ַ���ĩβ���ӻ��з�
//	fclose(pf), pf = NULL;
//	return 0;
//}


//��ʽ����������--fscanf��fprintf��ָ����ʽ��
//��ͳ��scanf��printf��������ڱ�׼�������ͱ�׼�������Ҳ����˵ֻ���ڼ������������Ļ�����
//��fscanf��fprintf��scanf��printf�����������fscanf��fprintf����ָ���������������������Ҫ��scanf��printf��һ�����Ĳ���
//struct S
//{
//	int n;
//	float f;
//	char arr[15];
//};
//int main()
//{
//	//struct S s = { 100,3.14f,"hello world" };  //3.14���f�Ǳ�֤3.14��float�ͣ���Ȼ������Ĭ��Ϊdouble����
//	struct S tmp = { 0 };  //��ȡ�ļ�����ʱҪ���´���һ���ṹ�岢��Ϊ0����Ϊ����ϣ�����ļ�������������ݷŵ�tmp��ȥ
//	FILE* pf = fopen("test.txt", "r+"); //"r+"�ǿɶ���д��û���ĵ��ͱ���
//	if (pf == NULL)
//		return -1;
//	//������ݵ��ļ���pf
//	//fprintf(pf, "%d %f %s", s.n, s.f, s.arr); //�Ը�ʽ����ʽ������ļ���
//	//��pf��ȡ���ݵ�tmp
//	fscanf(pf, "%d %f %s", &(tmp.n), &tmp.f, tmp.arr);  //fscanf��ȡ����ʱ�����ո�ͻ�ֹͣ��ȡ�����Ժ����world��ӡ������
//	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
//	fclose(pf), pf = NULL;
//	return 0;
//}

//scanf/fscanf/sscanf������
//printf/fprintf/sprintf������

//  scanf/printf����Ա�׼������/��׼������� ��ʽ������/������
//  fscanf/fprintf���������������/����������� ��ʽ������/������
//  sprintf����ȡ��ʽ�������ݲ�ת�����ַ��������ָ����ָ���У�����sprintf����Ҫ��printf��һ��char* string�Ĳ���
//  sscanf ����ȡָ�����ַ�����ת���ɸ�ʽ�������ݣ�����sscanf����Ҫ��scanf��һ��const char* string�Ĳ���

//����
struct S
{
	int n;
	float f;
	char arr[15];
};
int main()
{
	struct S s = { 100,3.14f,"hello" };
	struct S tmp = { 0 };
	char str[100] = { 0 };
	//�Ѹ�ʽ��������ת�����ַ��������str
	sprintf(str, "%d %.2f %s", s.n, s.f, s.arr);
	printf(str);
	//���ַ���str�ж�ȡ���ݲ�ת���ɸ�ʽ���������뵽��tmp��
	sscanf(str, "%d %f %s", &tmp.n, &tmp.f, tmp.arr);
	printf("%d %f %s", tmp.n, tmp.f, tmp.arr);
	return 0;	
}