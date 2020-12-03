#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>



size_t mystrlen(const char* str) {
	if (str == NULL)
		return 0;
	if (*str == '\0')
		return 0;
	return 1 + mystrlen(str + 1);
}
//由于无法保证用户传入参数类型,所以要保证健壮性

//针对参数的合法性检查有两种风格:
//1.if
//2.assert断言(需要宏),写一个表达式,如果表达式为真,断言没有任何效果,代码继续执行
//如果为假,程序就会直接崩溃
size_t mystrlen1(const char* str) {
	if (str == NULL)
	return 0;
	//assert(str != NULL);
	size_t len = 0;
	//str[len] 就是*(str + len)也就是解引用
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

char* mystrcpy(char* dest, const char* source) {
	if (dest == NULL || source == NULL)
		return NULL;
	char* ret = dest;
	while (*source != '\0'){
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return ret;//函数返回值就是原来的地址
}
char* mystrcpy1(char* dest, const char* source) {
	if (dest == NULL || source == NULL)
		return NULL;
	static int i = 0;
	if (*source == '\0') {
		*(dest + 1) = '\0';
		return dest - i ;
	}
	*dest = *source;
	dest++;
	source++;
	i = i + 1;
	return mystrcpy1(dest, source);

}

char* mystrcat(char* dest, const char* source) {
	if (dest == NULL || source == NULL)
		return dest;
	//strcat是拷贝到结束为止
	//先找到结束位置
	char* p = dest;
	while (*p != '\0') {
		p++;
	}
	//循环结束以后就指向了
	if (*source != '\0') {
		*p = *source;
		p++;
		source++;
	}
	*p = '\0';
	return dest;
}


int mystrcmp(const char* dest, const char* source) {
	//if (dest == NULL || source == NULL)
		//return NULL;
	assert(dest != NULL || source != NULL);//发现参数非法时进行解决,java中就会抛出异常
	while (*dest != '\0' && *source != '\0') {
		if (*dest < *source)
			return -1;
		else if (*dest > * source)
			return 1;
		else {
			dest++;
			source++;
		}
	}
	//如果已经结束,触发的就是有一个长一个短
	//如果两个都是\0那就是相等,看谁是\0另一个更大
	if (*dest < *source)
		return-1;
	else if (*dest > * source)
		return 1;
	else
		return 0;

}

int mystrcmp1(const char* dest, const char* source) {
	return *dest - *source;
}

const char* mystrstr(const char* dest, const char* source) {
	if (dest == NULL || source == NULL)
		return NULL;
	const char* blacker = dest;
	while (*blacker != '\0') {
		const char* redptr = blacker;
		const char* subptr = source;
		//当前blackptr为开始
		while(*redptr != '\0' && *subptr != '\0' && *redptr == *subptr) {
			redptr++;			
			subptr++;
		}
		//三种结束结果
		//1.*redptr != '\0'不成立,就是blackptr++,找下一个位置
		//2. *subptr != '\0',返回blackptr
		//3.*redptr == *subptr也是blackptr++
		if (*subptr == '\0') {
			return ((++blacker) - dest) ;
		}
		blacker++;
	}
	return NULL;
}


int main() {
	/*
	unsigned int a = 10;
	unsigned int b = 20;
	unsigned int c = a - b;
	//a是一个正整数,对于-20来说就是补码形式,进行运算以后就是42亿9千万
	printf("%u", c);*/

	/*
	char str[] = "caowen";
	char* str = NULL;
	if (str != NULL) {//外部保证,双重保证很保险
		printf("%d", mystrlen1(str));
	}//野指针不可以解引用
	//printf("%d", mystrlen1(0x100));//还是未定义行为,在C语言中无解,聊胜于无,没啥根本性解决*/

	//strcpy函数返回值类型是一个char*, 目的是为了实现链式调用
	//char name[1024] = "";
	//char name2[1024] = "CAOWEN";
	//strcpy(name, "CAOWEN");//这样写才可以
	//strcpy(name2, "CAOWEN");
	//等价于,以下的链式
	//strcpy(name, strcpy(name2, "CAOWEN"));
	//两行写更好看
	//mystrcpy1(name, name2);
	//char name2[5] = "hehe";
	//strcpy(name2, "lisisi");
	//printf("%s", name);


	char name5[1024] = "zhang";
	strcat(name5, "san");
	//printf("%s", name5);

	char name8[] = "hehe";
	char name9[] = "hehehe";
	int ret = strcmp(name8, name9);
	//printf("%d", ret);

	char name10[] = "hello worllol lloll";
	char name11[] = "lloll";
	printf("%d",mystrstr(name10, name11));

	return 0;
}
