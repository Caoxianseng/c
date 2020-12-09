#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//设计通讯录程序
//先创建结构体表示一个联系人
typedef struct Person {
	char name[1024];
	char tel[1024];
}Person;
//表示整个通信录,就是管理这些
typedef struct AddressBook {
	Person persons[1024];
	int size;//创建出的数组里,1024,但是初始条件下为0个,每次新增才会增加
	//才会多出一个元素,用来控制就是多少个人[0,size)就是有效区间
}AddressBook;
int menu() {
	printf( "==================\n" );
	printf( "1.新增联系人\n" );
	printf( "2.查找联系人\n" );
	printf( "3.删除联系人\n" );
	printf( "4.修改联系人\n" );
	printf( "5.查看所有联系人\n");
	printf( "6.清空所有联系人\n");
	printf( "0.退出\n");
	printf("==================\n");
	int input = 0;
	scanf("%d", &input);
	return input;

}
void init(AddressBook* addressbook) {
	//针对整个通信录进行初始化
	addressbook->size = 0;//就是直接让里面的无效
	//memset(addressbook, 0, sizeof(AddressBook));
}
//新增函数
void newNum(AddressBook* addressbook){
	//新增联系人
	printf("新增联系人\n");
	//用户输入信息
	//要先进行判断,是否已经满了
	if(addressbook->size > 1023) {
		printf("通讯录已经满了,写入失败");
		return;
	}
	//创建好一个专门的变量把要修改的Person结构体变量给保存好
	Person* p = &addressbook->persons[addressbook->size];
	printf("请输入新联系人的姓名\n");
	scanf("%s", p->name);
	printf("请输入新联系人的电话\n");
	scanf("%s", p->tel);
	printf("新增联系人已建好\n");
	addressbook->size++;
	}
	//查找函数
void lookforNum(AddressBook* addressbook){
	//用过姓名查找号码
	int count = addressbook->size;
	printf("按照姓名查找联系人!\n");
	printf("请输入要查找的姓名:");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addressbook->size; i++) {
		Person* p = &addressbook->persons[i];
		if (!strcmp(name, p->name)) {
			printf("[%d]\t\t%s\t\t%s\n", i, p->name, p->tel);
		}
		count--;
	}
		if (count == 0) {
			printf("没有该联系人!\n");
			return;
		}
}
		//删除函数
void delNum(AddressBook* addressbook){
	//删除联系人
	printf("删除联系人\n");
	printf("请输入您想删除的联系人的编号:");
	int id = 0;
	scanf("%d",&id);
	if (id < 0 || id >= addressbook->size) {
		printf("您的输入有误\n");
		return;
	}
	//如果是最后一个元素,就直接删除
	if (id == addressbook->size - 1) {
		addressbook->size--;
		printf("删除成功\n");
		return;
	}//中间元素,就交换
	addressbook->persons[id] = addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("删除成功\n");
	
}
			//修改函数
void updateNum(AddressBook* addressbook){

}
//查看所有联系人函数
void printNum(AddressBook* addressbook){
	printf("打印所有联系人\n");
	for (int i = 0; i < addressbook->size; i++) {
		Person* p = &addressbook->persons[i];
		printf("[%d]\t%s\t%s\n",i,p->name,p->tel);
	}
	printf("共计 %d 条记录\n", addressbook->size);
}
//清空所有联系人函数
void delAllNum(AddressBook* addressbook){
	int choice = 0;
	printf("您确定清空所有联系人?\n");
	printf("1 or 0\n");
	scanf("%d", &choice);
	if (choice == 1) {
		addressbook->size = 0;
		printf("成功清除所有联系人\n");
	}
	else if (choice == 0) {
		printf("请重新选择选项,退出\n");
		return;
	}
	else {
		printf("您的输入有误,退出\n");
		return;
	}
}
typedef void(*Func)(AddressBook*);

AddressBook addressbook;
int main() {
	//转移表,就是函数指针数组
	Func funcs[] = {
		NULL,
		newNum,
		lookforNum,
		delNum,
		updateNum,
		printNum,
		delAllNum,
	};
	//初始化通讯录
	init(&addressbook);
	while (1) {
		int choice = menu();
		if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		if (choice < 0 || choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("您的输入有误,重新输入\n");
			continue;
		}
		funcs[choice](&addressbook);

	}
}