#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//�Լ�дһ��strcpy����
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		*dest++;
//		*src++;
//	}
//	//Ҫ��arr2�����е�Ԫ��ȫ��������arr1�У�ѭ������ʱֻ������ljx����Ԫ�أ���û�п���\0
//	*dest = *src; //��һ���ǿ���\0
//}
//�Ż�����
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)//���ú���++��ʹ��*dest��*src�ڱ����ַ���
//	{                      //while����Ϊ0ʱ�Ž���ѭ������������'\0'ʱ��Ӧ��ACRII��ֵΪ0���ڿ���\0 �����ѭ��
//		;
//	}
//}
//�����������NULLһ����ָ�룬��ô�����޷���������Ҫ�����Ż�����
//void my_strcpy(char* dest, char* src)
//{
//	if (dest != NULL && src != NULL)//����һ�������ж�dest��src���ǿ�ָ��
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
//�����ָ��������������˿�ָ��������󣬲������ƣ�Ҫָ������������������Լ����Ż�����
//void my_strcpy(char* dest, char* src)
//{	//��������ż��������׳����������Ƿ��������������
//	//assert����--���ԣ�ʹ������Ҫ����ͷ�ļ�<assert.h>
//	assert(dest != NULL);//assert�����ڷŵı��ʽΪ�棬��ʲô�������������ʽΪ���򱨴�
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//�����д����Ĺ����У���*dest++ = *src++д��*src++ =*dest++����Ŀ���ַ���������Դͷ�ַ����ϣ������ױ����֣�����Ҫ�����Ż�����
//void my_strcpy(char* dest, const char* src)//��Դ�ϼ�һ��const����Դ����Ϊ�����޸ģ��Ϳ��Ա��ⷢ�������Ĵ���
//{	//const���ʼ˵���Ǹ��������ϳ������ԣ������޷��޸�
//	assert(dest != NULL);//assert�����ڷŵı��ʽΪ�棬��ʲô�������������ʽΪ���򱨴�
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//����һ��ָ�����p��˵������ָ��ʱ�������*�ŵ����--const int *p�����ε���*p,Ҳ����˵�޷�ͨ��*p���޸�pָ���ֵ
//���const��*���ұ�--int* const p�����ε���ָ�����p���޷��ٽ���ĵ�ַ����p������
//���뻹�������Ż�

char* my_strcpy(char* dest, const char* src) //����������ķ���ֵ��Ϊchar* ���ͣ����ص���Ŀ���ַ�������Ԫ�ص�ַ
{	
	char* ret = dest;//��Ϊdest��������++������ָ��������һ��Ԫ���ˣ�����ӡ�ַ���ʱ��Ҫ������Ԫ�ص�ַ����������ret�����Ԫ�ص�ַ
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	//�ȵ�destָ����ַ������޸�����ٷ���������Ԫ�ص�ַ����ӡ���Ľ�����ǿ�������ַ�����
	return ret;
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "ljx";
	//my_strcpy(arr1, arr2);
	//printf("%s", arr1);
	//�������һ���Ż���my_strcpy�з���ֵ�ˣ�����ֱ�ӽ��д�ӡ
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}