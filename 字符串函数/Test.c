#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//ģ��ʵ��isdigit
int isDigit(char c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

void* myMemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;//ǿ��ת��,��Ϊvoid*�����Բ�������
	char* psrc = (char*)src;
	for (int i = 0; i < num; i++) {
		*(pdest + i) = *(psrc + i);
	}
	return dest;
}

void* myMovee(void* dest,void* src,size_t num){
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;//ǿ��ת��,��Ϊvoid*�����Բ�������
	char* psrc = (char*)src;
	if (psrc <= pdest && psrc + num >= pdest)//˵�����ص�����,���ſ���
	{
		for (int i = num - 1; i >= 0; i--) {
			*(pdest + i) = *(psrc + i);
         }
		return dest;
	}
	else//����Ҫ���ſ���
	{
		return myMemcpy(dest, src, num);
	}
}


//ʵ�ִ�дתСд
char toLower(char c) {
	//�ж��ǲ��Ǵ�д��ĸ
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