#include<stdio.h>
typedef struct Student {
	char name[1024];
	int age;
}Student;
struct School {
	 Student students[1024];
	 //struct School schools[];����ǲ����Ե���C������,�����Լ������Լ��Ľṹ��,����Ӳ�Թ涨
	 //sizeof(School),�ͻ�����޵ݹ�
	 struct School* school;//��Ϳ�����,��һ��ָ��,��32λ��4���ֽ�,��64λ�ھ���8���ֽ�
};
//#pragma once//������������һ��
#pragma pack(1)//����Ĭ�϶�����Ϊ1
typedef struct A {
	char one;
	short two;
	//char three;
	//int  four;
	int  five;
	/*float six;
	double seven;
	short eight;
	char nine;*/
}A;

int main() {
	A a;
	printf("%d\n", sizeof(a));
	printf("%p\n", &a);
	printf("%p\n", &a.one);
	printf("%p\n", &a.two);
	printf("%p\n", &a.five);
	/*printf("%p\n", &a.six);
	printf("%p\n", &a.seven);
	printf("%p\n", &a.eight);
	printf("%p\n", &a.nine);*/
}