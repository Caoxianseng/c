#include<stdio.h>

//дһ������,�����ַ����ĳ���,����\0���Ǹ�
int strLen(char* str) {//Ҳ����д��:char str[]
	//�󳤶ȵ�˼·����,��ǰ��������ַ�����,ÿ�ζ�ȡ��һ���ַ�,count++,ֱ������ \0 ��ѭ������
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {//�����ָ�����[]��,���������[]Ч��һ��
		count++;
	}
	return count;
}
//������ʹ����ʱ����,�����õݹ�
int strLen1(char* str) {//������,
	//abcd���Ⱦ���a�ĳ��ȼ���bcd�ĳ���
	//strLen1(abcd)=1+strLen1(bcd)
	//������һֱ��ֵ���ֹ����
	if (*str == '\0')
		return 0;
	return 1 + strLen1(str + 1);//str+1��һ��ָ������
	
}
//��쳲���������(�ݹ�ʵ��)
int fib(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

//��쳲���������(�ǵݹ�ʵ��)
int fib1(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	int first = 1;
	int second = 1;
	int sum = 0;
	for (int i = 3; i <= n; i++) {
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}
//������̨��:








//����һ��ö��
enum {
	SIZE = 10
};
//����һ����
#define  SIZE1  10
//const
const SIZE2 = 10;

int main() {
	char str[] = "hehe";
	int length = strLen1(str);
	/*
	printf("%d\n", length);
	printf("%d", fib1(10));
	*/

	//����һ������
	int arr1[10] = { 0 };
	//����һ�����鲢�ҳ�ʼ��
	int arr2[4] = { 0,1,2,3 };
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr1[i]);
	}
	//1.����ֵ 10 
	//2.const
		//3.enum
		//4.#define��

	//int arr3[SIZE2] = { 0 };
	
	char arr5[] = { 'a','b','c' };//�ַ�����,�������ַ���
	char arr6[] = "abc";//�����ַ���,������ַ�����,����\0��β
	int arr9[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		//��ӡ��ַ,%p�Ĺ��ܾ��Ǵ�ӡָ�����,Ҳ���Ǵ�ӡ��ַ,%��ӡҲ����,����ϰ����%p
		printf("%p\n", &arr9[i]);
	}

	return 0;
}