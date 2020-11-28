#include<stdio.h>
/*
typedef struct Student {
	int id;
	char name[1024];
}Student;
*/

//写一个函数,求大小端
//基于指针的方式
//大回1,小回0

/*
int ifBingOrSmall() {
	int num = 0x11223344;
	int* p = &num;
	char* p2 = (char* )p;
	if (*p2 == 0x11)
		return 1;
	else
		return 0;
}*/

int ifBingOrSmall01() {
	int num = 0x11223344;
	/*int* p = &num;
	char* p2 = (char*)p;
	return (*p2 == 0x11) ? 1 : 0;*/
	//return *(char*)(&num) == 0x11 ;
}
int main() {
	/*
	Student s = { 15,"caowen" };

	//地址,首地址;房间大小,类型
	Student* p = &s;

	//访问成员
	//指针用箭头
	printf("%d\n", s.id);
	printf("%d\n", p->id);
	printf("%d", (*p).id);
	//主要用箭头的方式
	*/
	//int a = 0x11223344;
	//printf("%d", ifBingOrSmall01());

	//int a = -10;
	//return 0;
	float a = 19.0;
	float b = a / 7.0;
	//float c = a + b;
	//if (b * 7.0 == a)
#define N 1e-4
	if(b * 7.0 - a < N && b * 7.0 > -N)
	{
		printf("相等,这里不是严格相等,而是允许误差");
	}
	else {
		printf("不等");
	}

}