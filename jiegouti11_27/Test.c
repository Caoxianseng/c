#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
struct Student {
	//������Щ������Ա,Ҳ�����ֶ�,Ҳ��������
	int id;
	char name[10];
	int age;
	double score;
};
typedef struct Student  Student;
*/

//�϶�Ϊһ,�ȼ���:
typedef struct Student {
	int id;
	char name[10];
	int age;
	double score;
}Student;
int main() {
	//�������ͻ�����,����Ҫ��������
	Student student = {1,"caowen",20,95.5};              //����ʼ��,�������ֵ
	//ʹ��:��Ա���ʲ���
	printf("%d  %s\n", student.id, student.name);
	char array[10] = "zhaoyukun";
	for (int i = 0; i < 10; i++) {
		student.name[i] = array[i];
	}
	strcpy(student.name, "lisa");
	printf("%s", student.name);


}