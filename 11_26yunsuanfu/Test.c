#include<stdio.h>
#define and &&
#define or ||
//关于位运算的例子
//求一个整数中1的个数
//非递归求法
int forNum(int n) {
	int count = 0;
	while (n != 0) {
		if ((n & 1) == 1)
			count++;
		n = n>> 1;
	}
	return count;
}
//递归求法
int forNum1(int n) {
	if (n == 0)
		return;
	return (n & 1) + forNum(n>>1);
}
int main() {
	//printf("%d", forNum1(11));
	int arr[10] = { 0 };
	//printf("%d", sizeof(arr[10]));4
	printf("%d", 1 or 0);
	return 0;
}