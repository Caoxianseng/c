#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//���ͨѶ¼����
//�ȴ����ṹ���ʾһ����ϵ��
typedef struct Person {
	char name[1024];
	char tel[1024];
}Person;
//��ʾ����ͨ��¼,���ǹ�����Щ
typedef struct AddressBook {
	Person persons[1024];
	int size;//��������������,1024,���ǳ�ʼ������Ϊ0��,ÿ�������Ż�����
	//�Ż���һ��Ԫ��,�������ƾ��Ƕ��ٸ���[0,size)������Ч����
}AddressBook;
int menu() {
	printf( "==================\n" );
	printf( "1.������ϵ��\n" );
	printf( "2.������ϵ��\n" );
	printf( "3.ɾ����ϵ��\n" );
	printf( "4.�޸���ϵ��\n" );
	printf( "5.�鿴������ϵ��\n");
	printf( "6.���������ϵ��\n");
	printf( "0.�˳�\n");
	printf("==================\n");
	int input = 0;
	scanf("%d", &input);
	return input;

}
void init(AddressBook* addressbook) {
	//�������ͨ��¼���г�ʼ��
	addressbook->size = 0;//����ֱ�����������Ч
	//memset(addressbook, 0, sizeof(AddressBook));
}
//��������
void newNum(AddressBook* addressbook){
	//������ϵ��
	printf("������ϵ��\n");
	//�û�������Ϣ
	//Ҫ�Ƚ����ж�,�Ƿ��Ѿ�����
	if(addressbook->size > 1023) {
		printf("ͨѶ¼�Ѿ�����,д��ʧ��");
		return;
	}
	//������һ��ר�ŵı�����Ҫ�޸ĵ�Person�ṹ������������
	Person* p = &addressbook->persons[addressbook->size];
	printf("����������ϵ�˵�����\n");
	scanf("%s", p->name);
	printf("����������ϵ�˵ĵ绰\n");
	scanf("%s", p->tel);
	printf("������ϵ���ѽ���\n");
	addressbook->size++;
	}
	//���Һ���
void lookforNum(AddressBook* addressbook){
	//�ù��������Һ���
	int count = addressbook->size;
	printf("��������������ϵ��!\n");
	printf("������Ҫ���ҵ�����:");
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
			printf("û�и���ϵ��!\n");
			return;
		}
}
		//ɾ������
void delNum(AddressBook* addressbook){
	//ɾ����ϵ��
	printf("ɾ����ϵ��\n");
	printf("����������ɾ������ϵ�˵ı��:");
	int id = 0;
	scanf("%d",&id);
	if (id < 0 || id >= addressbook->size) {
		printf("������������\n");
		return;
	}
	//��������һ��Ԫ��,��ֱ��ɾ��
	if (id == addressbook->size - 1) {
		addressbook->size--;
		printf("ɾ���ɹ�\n");
		return;
	}//�м�Ԫ��,�ͽ���
	addressbook->persons[id] = addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("ɾ���ɹ�\n");
	
}
			//�޸ĺ���
void updateNum(AddressBook* addressbook){

}
//�鿴������ϵ�˺���
void printNum(AddressBook* addressbook){
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < addressbook->size; i++) {
		Person* p = &addressbook->persons[i];
		printf("[%d]\t%s\t%s\n",i,p->name,p->tel);
	}
	printf("���� %d ����¼\n", addressbook->size);
}
//���������ϵ�˺���
void delAllNum(AddressBook* addressbook){
	int choice = 0;
	printf("��ȷ�����������ϵ��?\n");
	printf("1 or 0\n");
	scanf("%d", &choice);
	if (choice == 1) {
		addressbook->size = 0;
		printf("�ɹ����������ϵ��\n");
	}
	else if (choice == 0) {
		printf("������ѡ��ѡ��,�˳�\n");
		return;
	}
	else {
		printf("������������,�˳�\n");
		return;
	}
}
typedef void(*Func)(AddressBook*);

AddressBook addressbook;
int main() {
	//ת�Ʊ�,���Ǻ���ָ������
	Func funcs[] = {
		NULL,
		newNum,
		lookforNum,
		delNum,
		updateNum,
		printNum,
		delAllNum,
	};
	//��ʼ��ͨѶ¼
	init(&addressbook);
	while (1) {
		int choice = menu();
		if (choice == 0) {
			printf("goodbye!\n");
			break;
		}
		if (choice < 0 || choice >= sizeof(funcs) / sizeof(funcs[0])) {
			printf("������������,��������\n");
			continue;
		}
		funcs[choice](&addressbook);

	}
}