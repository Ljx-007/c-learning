#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�Ͻ�̸���ļ������ȡ���õ�����fseek����
//int fseek(FILE* stream,long offset,int origin);
//offset��ƫ������origin���ļ�ָ��ĵ�ǰλ��
//���ڲ���origin������������ֵ
//SEEK_CUR--�ļ�ָ�뵱ǰλ��
//SEEK_END--�ļ���ĩβλ��
//SEEK_SET--�ļ�����ʼλ��
//fseek�Ե�ǰָ��λ��Ϊ��㣬����ƫ���������ļ�ָ��

//ftell--�����ļ�ָ���������ʼλ�õ�ƫ����
//long ftell(FILE* stream)
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		return 0;
//	//fputs("abcdef", pf); //����һ���ĵ���д��abcdef
//	//��λ�ļ�ָ��
//	fseek(pf, 3, SEEK_CUR); //��ʱָ��d
//	int pos = ftell(pf);  //��ȡ��ʱָ�������ʼλ�õ�ƫ����
//	printf("%d", pos);
//	fclose(pf), pf = NULL;
//	return 0;
//}

//rewind--���ļ�ָ���λ�ûص��ļ�����ʼλ��
//void rewind(FILE* stream)
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//		return 0;
//	//fputs("abcdef", pf); //����һ���ĵ���д��abcdef
//	//��λ�ļ�ָ��
//	fseek(pf, 3, SEEK_CUR); //��ʱָ��d
//	rewind(pf);  //���ļ�ָ��ָ����ʼλ��
//	int pos = ftell(pf);  //��ȡ��ʱָ�������ʼλ�õ�ƫ����
//	printf("%d", pos);
//	fclose(pf), pf = NULL;
//	return 0;
//}


//�ļ���ȡ�������������
//1.�ļ���ȡʧ�ܽ���
//2.�ļ���ȡ���ļ�β����

//����һ���ļ���ʲôҲû�У���ô��ȡʱ���൱�ڶ����ļ�β�ˣ��ļ���EOF��β��EOF������Ϊ-1��Ҳ����˵���ļ�ʲô��û��ʱ����ȡ���ͻ᷵��-1��ֵ
//ʵ��Ӧ���У��ı��ļ�������ʹ��fgetc����fgets����ȡ�ļ����ļ��Ƿ��ȡ�����ı�־�ǣ���fgetc����EOF��������fgets������һ����ָ��
//            �������ļ����ж϶�ȡ�����ı�־��fread�ķ���ֵС��һ�ζ�ȡ��Ԫ�ظ���
//������ȡ�ļ�����ʱ�����ǲ�������ļ���ȡ��������Ϊ��ȡʧ�ܽ����˻�����Ϊ��ȡ���ļ�β����
//��ʱ�ͻ��õ�  feof ��ferror �������ж϶�ȡ������ԭ��

//int feof(FILE* stream)--�ж��ļ��Ƿ��Ƕ����ļ�β������
//����ļ������Զ�ȡ���ļ�β��ʽ�����ģ���ô���ط���ֵ��������ǣ�����0
//int ferror(FILE* stream)--�ж��ļ��Ƿ�����Ϊ���������
//����ļ���ȡʱ���������������ô���ط���ֵ��������ǣ�����0
int main()
{
	int ch; //������ch�����ն�ȡ���ַ�����int��ԭ���Ƕ�ȡ���ļ���β����յ�EOF��EOF��-1
	FILE* pf = fopen("test2.txt", "r"); //��������һ�������ڵ��ļ���Ŀ�������ļ���ʧ��
	if (!pf)  //!��ȡ���������ʧ�ܣ���ôpf=NULL��NULLֵΪ0��ȡ����Ϊ1�������if��䣬������pf==NULL��ͬ��ֻ�������Ӽ��
	{
		perror("open file test2.txt"); //perror�Ĺ�����strerror(errno)���ƣ�perrorҲ�ᱨ����ԭ�򣬲��Ҳ���Ҫ��printf��errno�������strerror(errno)���Ӽ��
		//perror�Ĳ�����һ���ַ�������ӡ����ԭ��ʱ���ȴ�ӡ�ַ��������ݣ��ټ�һ��ð�źͿո�Ȼ���ӡ����ԭ��
		//��  open file test2.txt: ������ԭ��  ���������д���ʱ�������Ի������û���ʾ������ʲô�����ʱ�����˴��󣬴���ԭ����ʲô
		return -1;
	}
	//���ļ�
	while ((ch = fgetc(pf)) != EOF)  //��ch������fgetc��ȡ�����ַ������û����EOF���Ǿͽ���ѭ��һֱ��ӡ���������ַ�
	//����Ƕ����ƶ�ȡ�ļ�����whileѭ������д��
	//while(fread(&ch,sizeof(char),1,pf)>=1)  һ�ζ�ȡ����Ԫ�ظ���С�ڹ涨��һ�ζ�ȡԪ�ظ�������˵����ȡ����
	{
		putchar(ch); //��ӡ�������ַ�
	}
	if (ferror(pf)) //�����Ϊ�����������ȡ�ļ���ferror���ط�0ֵ����ʱ����if���
	{
		printf("error\n");
	}
	else if (feof(pf))  //�����Ϊ�����ļ�β������feof���ط�0ֵ����ʱ����else if���
		printf("end of file successfully\n");
	fclose(pf), pf = NULL;
	return 0;
}