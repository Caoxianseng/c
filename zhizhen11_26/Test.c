#include<stdio.h>
int* fun() {
	int a = 10;
	return &a;
 }
//дһ�������ݹ����ַ�������
int myStrlen(char* str) {
	if (*str == '\0')
		return 0;
	return 1 + myStrlen(str + 1);
}
int main(){
	//int* p = 0;
	//printf("%d\n", *p);
	//ָ�������кܶ���,
	/*int* a = NULL;
	char* b = NULL;
	short* c = NULL;
	double* d = NULL;
	float* e = NULL;*/
	char* a = 'a';
	char* pa = &a;
	short b = 10;
	short* pb = &b;

	int man = 10000;
	char* manm = &man;
	printf("%d", *manm);

	int* p = fun();
	//Ұָ��,Ҳ�ǷǷ�ָ��
	int num = 10;
	int* p5 = &num;
	void* p6 = p5;
	//printf("%d", *p6);

	char* m = NULL;
	printf("%p\n", m + 1);
	short* n = NULL;
	printf("%p\n", n + 1);
	int * o = NULL;
	printf("%p\n", o + 1);
	float* q = NULL;
	printf("%p\n", q + 2);

	double* l = 0x100;
	printf("%p\n", l - 1);
	char array[] = "hello wo";

	printf("%d", myStrlen(array));
	return 0;
}