#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
struct Student {
	//下面这些叫做成员,也叫作字段,也叫作属性
	int id;
	char name[10];
	int age;
	double score;
};
typedef struct Student  Student;
*/

//合二为一,等价于:
typedef struct Student {
	int id;
	char name[10];
	int age;
	double score;
}Student;
int main() {
	//光有类型还不够,还需要创建变量
	Student student = {1,"caowen",20,95.5};              //不初始化,就是随机值
	//使用:成员访问操作
	printf("%d  %s\n", student.id, student.name);
	char array[10] = "zhaoyukun";
	for (int i = 0; i < 10; i++) {
		student.name[i] = array[i];
	}
	strcpy(student.name, "lisa");
	printf("%s", student.name);


}