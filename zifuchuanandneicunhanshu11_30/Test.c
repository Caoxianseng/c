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
//�����޷���֤�û������������,����Ҫ��֤��׳��

//��Բ����ĺϷ��Լ�������ַ��:
//1.if
//2.assert����(��Ҫ��),дһ�����ʽ,������ʽΪ��,����û���κ�Ч��,�������ִ��
//���Ϊ��,����ͻ�ֱ�ӱ���
size_t mystrlen1(const char* str) {
	if (str == NULL)
	return 0;
	//assert(str != NULL);
	size_t len = 0;
	//str[len] ����*(str + len)Ҳ���ǽ�����
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
	return ret;//��������ֵ����ԭ���ĵ�ַ
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
	//strcat�ǿ���������Ϊֹ
	//���ҵ�����λ��
	char* p = dest;
	while (*p != '\0') {
		p++;
	}
	//ѭ�������Ժ��ָ����
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
	assert(dest != NULL || source != NULL);//���ֲ����Ƿ�ʱ���н��,java�оͻ��׳��쳣
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
	//����Ѿ�����,�����ľ�����һ����һ����
	//�����������\0�Ǿ������,��˭��\0��һ������
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
		//��ǰblackptrΪ��ʼ
		while(*redptr != '\0' && *subptr != '\0' && *redptr == *subptr) {
			redptr++;			
			subptr++;
		}
		//���ֽ������
		//1.*redptr != '\0'������,����blackptr++,����һ��λ��
		//2. *subptr != '\0',����blackptr
		//3.*redptr == *subptrҲ��blackptr++
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
	//a��һ��������,����-20��˵���ǲ�����ʽ,���������Ժ����42��9ǧ��
	printf("%u", c);*/

	/*
	char str[] = "caowen";
	char* str = NULL;
	if (str != NULL) {//�ⲿ��֤,˫�ر�֤�ܱ���
		printf("%d", mystrlen1(str));
	}//Ұָ�벻���Խ�����
	//printf("%d", mystrlen1(0x100));//����δ������Ϊ,��C�������޽�,��ʤ����,ûɶ�����Խ��*/

	//strcpy��������ֵ������һ��char*, Ŀ����Ϊ��ʵ����ʽ����
	//char name[1024] = "";
	//char name2[1024] = "CAOWEN";
	//strcpy(name, "CAOWEN");//����д�ſ���
	//strcpy(name2, "CAOWEN");
	//�ȼ���,���µ���ʽ
	//strcpy(name, strcpy(name2, "CAOWEN"));
	//����д���ÿ�
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
