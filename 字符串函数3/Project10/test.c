#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strncmp--�ַ����Ƚϣ��޶��ַ����ȵıȽ�
//int strncmp(const char* str1, const char* str2, size_t count);
//count��Ҫ�Ƚ϶��ٸ��ֽڸ���
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcqwer";
//	//int ret = strcmp(p1, p2);
//	int ret = strncmp(p1, p2,4);
//	printf("%d", ret);
//	return 0;
//}


//strstr--�����ַ���
//char *strstr(const char *string,const char *strCharSet)
//string:�����ҵ��ַ���  strCharSet:Ҫ���ҵ��ַ���
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	if (*p2 == '\0') //���p2��һ�����ַ�������ô����p1
		return (char*)p1;
	//���ܻ����p1="abbbcdef" ,p2="bbc"������������������һ�ξͻ����p2��p1���Ӵ�ȴ����NULL�����
	//���Ǿ�Ҫ�ӵ�һ��b�����������Ҳ����Ӵ���������ڶ���b���������Ƿ����ҵ�������Ҫ����cur�������
	//��cur��ʼ��������Ҫ1��ָ����������cur��Ϊͷ���������������Ҫ����s1�������
	//p2�ַ���Ҳ��Ҫ��������������s2�������
	char* s1=(char*) p1;
	char* s2 = (char*)p2;  //s1��s2����������p1��p2�ģ������������ַ��Ƿ����
	char* cur = (char*)p1;  //cur��������¼���Ӵ���Ҫ���ص�p1��p2���׵�ַ�ַ��ĵ�ַ
	while (*cur)
	{
		s1 = cur;  //һ��ѭ��֮��Ҫ����s1����s1���´�cur��ʼ����
		s2 = (char*)p2;   //����s2
		//��p1="abbbcdef" 
		//  p2="bbc" Ϊ��
		while (*s1&&*s2&& (*s1 == *s2))//��s1��s2ָ��Ķ�����\0��ָ����ַ����ʱ����ѭ��
		{
			s1++, s2++;
		}                 //�������ȣ�������ѭ����cur+1�����´�cur����
		if (*s2 == '\0')  //���*s2=='\0'��˵��p2��p1���Ѿ��ҵ��ˣ���ʱcur������p1��p2���׵�ַ�ַ��ĵ�ַ
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char* p1 = "abbbcdef";
	char* p2 = "bbc";
	//char* ret=strstr(p1, p2);//��p1�в���p2�Ƿ���ڣ�������ڣ��ͻ᷵��d�ĵ�ַ,�����ӡ��������defabcdef������def
	//ģ��ʵ��
	char* ret=my_strstr(p1, p2);
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s", ret);
	return 0;
}