#include<stdio.h>

//写一个函数,来求字符串的长度,不算\0的那个
int strLen(char* str) {//也可以写成:char str[]
	//求长度的思路就是,从前往后遍历字符数组,每次读取到一个字符,count++,直到遇到 \0 就循环结束
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {//这里的指针加上[]用,和数组加上[]效果一样
		count++;
	}
	return count;
}
//不允许使用临时变量,就是用递归
int strLen1(char* str) {//问题拆分,
	//abcd长度就是a的长度加上bcd的长度
	//strLen1(abcd)=1+strLen1(bcd)
	//就这样一直拆分到终止条件
	if (*str == '\0')
		return 0;
	return 1 + strLen1(str + 1);//str+1是一个指针运算
	
}
//求斐波那锲数列(递归实现)
int fib(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

//求斐波那锲数列(非递归实现)
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
//青蛙跳台阶:








//创建一个枚举
enum {
	SIZE = 10
};
//创建一个宏
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

	//创建一个数组
	int arr1[10] = { 0 };
	//创建一个数组并且初始化
	int arr2[4] = { 0,1,2,3 };
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr1[i]);
	}
	//1.字面值 10 
	//2.const
		//3.enum
		//4.#define宏

	//int arr3[SIZE2] = { 0 };
	
	char arr5[] = { 'a','b','c' };//字符数组,但不是字符串
	char arr6[] = "abc";//才是字符串,特殊的字符数组,必须\0结尾
	int arr9[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		//打印地址,%p的功能就是打印指针变量,也就是打印地址,%打印也可以,但是习惯用%p
		printf("%p\n", &arr9[i]);
	}

	return 0;
}