#include<stdio.h>
#include<string.h>
//位段
struct A {
	int  _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;

};
//枚举类型
enum Sex {//枚举里面用逗号链接
	MALE = 100,
	FEMALE,
	UNKOWN,
};
typedef enum X {
	one = 100,
	two,
	three = 200,
}X;

//联合体,
typedef union Test {
	char a;
	short b;
	int c;
}Test;
typedef union IP {
	int date;
	 struct Point {
		 char a;
		 char b;
		 char c;
		 char d;
	}point;
}IP;

//判断大小端的问题
int isBigEnd() {
	int a = 0x11223344;
	int* p = &a;
	char* p2 = (char*)p;
	if (*p2 == 0x11)
		return 1;
	else
		return 0;
}
int isBigEnd1() {
	union test {
		char a;
		int date;
	};
	union test t1;
	t1.date = 0x11223344;
	if (t1.a == 0x11)
		return 1;
	else
		return 0;

}
int main() {
	IP ip;
	ip.date = 0x11223344;
	printf("%x.%x.%x.%x", ip.point.a, ip.point.b, ip.point.c, ip.point.d);
	/*int arr[4] = { 0 };
	memset(arr, 1, 16);//初始化为1全部
	*/
	//printf("%d\n", sizeof(struct A));
	/*printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", UNKOWN);
	X x = two;
	X x1 = three;
	printf("%d", x1 + 100);*/
	
	/*Test t;
	t.c = 0x11223344;
	printf("%x\n", t.c);
	t.a = 0x55;
	printf("%x\n", t.c);*/

	/*t.c = 0x11223344;
	printf("%d\n", t.c);
	t.c = 0x11223344;
	printf("%d\n", t.c);
	printf("%d\n", sizeof(t));*/


	return 0;
}