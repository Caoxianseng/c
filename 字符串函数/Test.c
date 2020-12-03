#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//模拟实现isdigit
int isDigit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

void* myMemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;//强制转换,因为void*不可以参与运算
	char* psrc = (char*)src;
	for (int i = 0; i < num; i++) {
		*(pdest + i) = *(psrc + i);
	}
	return dest;
}

void* myMovee(void* dest,void* src,size_t num){
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;//强制转换,因为void*不可以参与运算
	char* psrc = (char*)src;
	if (psrc <= pdest && psrc + num >= pdest)//说明有重叠问题,反着拷贝
	{
		for (int i = num - 1; i >= 0; i--) {
			*(pdest + i) = *(psrc + i);
         }
		return dest;
	}
	else//不需要反着拷贝
	{
		return myMemcpy(dest, src, num);
	}
}


//实现大写转小写
char toLower(char c) {
	//判定是不是大写字母
	if (c <= 'Z' && c >= 'A')
	{
		c += ('a' - 'A');
	}
	return c;
 }
int main() {
	char name[] = "i am a student";
	char* p = strtok(name, ",");
	while (p != NULL) {		
		printf("%s\n", p);
		p = strtok(NULL, ",");
	}
	char num = 'b';
	printf("%c", toLower(num));

	int  name1[5] = {1,2,3,4,5};
	int name2[5] = { 0 };
	memcpy(name2, name1, sizeof(name1) );
	for (int i = 0; i < 5; i++) {
		printf("%d ", name2[i]);
	}
	return 0;
}