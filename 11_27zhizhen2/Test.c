#include<stdio.h>

//���ַ�������
int forNum(char* str) {
	char* p = str;
	int i = 0;
	for (i = 0; p[i] != '\0'; i++) {
		
	}
	return p + i - str;
}
int main() {
	/*
	int arr[4] = { 1,2,3,4 };
	int* p3 = &arr[0];
	int* p4 = &arr[2];
	printf("%d", p4 - p3);*/

	/*
	int* p1 = 0x100;
	int* p2 = 0x110;
	if (p1 == p2 - 4)
		printf("%d", 100);
	//����ָ������õ��Ľ�����м���˼���Ԫ��
	else
		printf("%d", 5);
	*/

	char arr[] = "nihao";
	//printf("%d", forNum(arr));

	int array[4] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(array));
	//����ͻ���ʽת��Ϊָ��
	//printf("%d", sizeof(array + 0));
	//int* p = array;
	//int* p1 = &array[0];
	/*
	for (int* p = array; p < array + 4; p++) {
		printf("%d    ", *p);
	}*/
	/*
	int* p6 = array + 1;
	printf("%d", p6[-1]);
	*/
	//int* arr[4] = { 0 };
	//int(*p)[4] = &arr;
	int num = 0;
	int num2 = 10;
	const int* p = &num;
	int const* p = &num;
	int* const p = &num;
	//*p = 100;//�����ڸ�����
	//p = &num2;//�������p����

}