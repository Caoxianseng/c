#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<string.h>
int main() {
	//\Ϊת���ַ�
	/*char name[] = "D:\\program1\\qq\\Bin";
	printf("%s", name);*/
	//���ļ�
	//���ؽ������"�ļ�ָ��",�е�ʱ��Ҳ����"���"(handler),�������ң����
	//�ļ��򿪿��ܻ�ʧ��,�ͻ᷵��NULL
	//int count = 0;

	//while (1) {
	//	FILE* f = fopen("E:/��ɢ��ѧ/ν���߼�02��Ԥ��֪ʶ��.docx", "r");//�����FILE��һ���ṹ��
	//	if (f == NULL) {
	//		//printf("�ļ���ʧ��! errno = %d, %s\n",errno,strerror(errno));//errno��һ����
	//		perror("�ļ���ʧ��!");
	//		system("pause");
	//		return 1;
	//	}
	//	count++;
	//	printf("�ļ��򿪳ɹ�!");
	//	printf("%d\n", count);
	//}
	//�ر��ļ�
	//fclose(f);//���ǹرողŵľ��,ʹ������Ժ�,һ��Ҫ�ر��ļ�,����ͻ�й©,����:�ļ���Դй©
	//������й©
	FILE* f = fopen("E:/��ɢ��ѧ/111.txt", "w");//�����FILE��һ���ṹ��
	if (f == NULL) {
		//printf("�ļ���ʧ��! errno = %d, %s\n",errno,strerror(errno));//errno��һ����
		perror("�ļ���ʧ��!");
		system("pause");
		return 1;
	}
	printf("�ļ��򿪳ɹ�!\n");
	/*�ⶼ�Ƕ�����
	//����Ѵ����ϵ����ݶ�ȡ���ڴ���
	char buf[1024] = { 0 };
	//�ڶ��������͵�����������˾͵õ�Ҫ��ȡ��������ֽ���
	int n = fread(buf, 1, 1024, f);//��ɶ�ȡ����
	//����ֵ����ʵ�ʶ�ȡ��Ԫ�ظ���
	//Ԥ�ں�ʵ�ʵĲ�һ��,��������Ԥ�ڵ�,����n����ʵ�ʵõ���
	//���ʵ�ʶ�����Ԫ�ظ���С��Ԥ�ڵ�,������Ϊ�ļ�������,
	//�������,����û�ж���,��ѭ����,
	printf("%s\n", buf);*/
	
	//��ʼд����  fwrite()������ڴ������д��������ȥ
	//���fwriteҪ�ǳɹ���,�ͻ᷵��ʵ��д���Ԫ�ظ���,���ʧ����,�ͻ᷵��С��0�����ֽ��
	/*
	char  buf[1024] = "hahaha";
	int n = fwrite(buf, 1, strlen(buf), f);
	if (n < strlen(buf)) {
		perror("fwrite");
	}*/

	//ʹ��fprintf
	/*int num = 10;
	fprintf(f,"num = %d",num);*/
	int num = 10;
	//fprintf(stdout, "num = %d", num);//���������printf�ȼ�
	//fscanf(stdin,"",)��scanf�ȼ�
	//sprintf/sscanf����������Ҫ,�Ѹ�ʽ�����д���ַ����к�   �Ӹ�ʽ���н���
	//������ת���ַ���,Ҳ���԰��ַ���תΪ����
	/*
	char buf[1024] = { 0 };
	sprintf(buf, "num = %d", num);//�ᱻд��buf��
	printf("%s\n", buf);
	*/
	char buf[1024] = { 0 };
	//����������,ֻ��ת��
	sprintf(buf, "%d", num);//����buf�оͰ�����10�ַ���
	printf("%c\n", buf[0]);
	printf("%c\n", buf[1]);
	printf("%c\n", buf[2]);//\0

	//ͬ�����sscanf��ת��,���ַ���ת��Ϊ��������

	//��C������,������һ�������ܹ�ת��Ϊ�ַ���������֮���ת��
	//atoi   itoa,�໥ת��
;	fclose(f);
	return 0;
}