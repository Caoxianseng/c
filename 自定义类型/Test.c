#include<stdio.h>
typedef struct Student {
	char name[1024];
	int age;
}Student;
struct School {
	 Student students[1024];
	 //struct School schools[];这个是不可以的在C语言中,不能自己包括自己的结构体,就是硬性规定
	 //sizeof(School),就会的无限递归
	 struct School* school;//这就可以了,是一个指针,在32位下4个字节,在64位在就是8个字节
};
//#pragma once//就是用来调用一次
#pragma pack(1)//设置默认对其数为1
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