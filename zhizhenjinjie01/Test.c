#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void print(int arr[][5]) {//�ǳ�ok,����ʡ��3

//}
//void print(int(*p)[5]) {

//}
void fun1(int arr[10]) {//�β������ǵĹ�û�й�ϵ

}
void fun2(int arr[]) {//�����������һ����,����ʡ������Ĵ�С

}
void fun3(int* arr) {//Ҳû���κ�����˵�������Ǹ�����BUG

}
void fun4(int* arr[]) {//����,����Ϊ�������Ͳ�ƥ��
	//������Ӽ���,Ҳ�������Ͳ�ƥ��,�βκ�ʵ�ε�����Ҫһ��
	//ʵ����arr,�����ڴ�int [10],�������β���˵,����ʱint**,int arr[] ��int*arr�ȼ�,���Լ���*֮�����int **,����������һ��
	//֮�����Ǿ���,����ΪC����������������,Խ֧����ʽת��Խ��������
	//ʵ��д����ʱ,��Ҫ����д,����Ϊ�кܴ�ķ���
}
void fun5(int** arr) {
	//������û������
}
//��������ǲ����Ե�
void fun6(int arr[3][4]) {

}
void fun7(int arr[][4]) {

}
//void fun8(int arr[][]) {//������,����Ϊ���벻ͨ��

//}
void fun9(int(*p)[4]) {

}
void fun10(int arr[3][5]){//�������,����Ϊת��Ϊint(*p)[5],��ʵ�β�ƥ��

}
void fun11(int arr[4][4]) {//�������,ֻ��Ϊת��Ϊ��int(*p)[4],��Ϳ���,��ʵ��һ��

}
void fun12(int** arr) {//�������,ֻһ������ָ��,ʵ�β��Ƕ���ָ��,��һ������ָ��

}
int test(int num) {
	printf("num = %d\n", num);
	return 0;
}
  void   test2(int a, int b) {
	//return 0;
}
  double test3() {

  }
  int* test4(int* a,int* b) {

 }

  int add(int a, int b) {
	  return a + b;
  }
  int sub(int a, int b) {
	  return a - b;
  }
  int mul(int a, int b) {
	  return a * b;
  }
  int div(int a, int b) {
	  return a / b;
  }
  typedef int(*Func1)(int, int);

  //һ������ʵ��
  //ascΪ1λ��������,ascΪ0ʱ����
  //���²���.�Ƚϴ�С,����һ�����Ϊ����,�ص�����,�߼��ƶ��˱ȽϹ���
  void bubleSort(int arr[], int size,int asc) {
	  if (asc == 1) {
		  for (int i = 0; i < size; i++) {
			  for (int j = 0; j < size - i - 1; j++)
			  {
				  if (arr[j] > arr[j + 1]) {
					  int temp = arr[j];
					  arr[j] = arr[j + 1];
					  arr[j + 1] = temp;
				  }
			  }
		  }
	  }else if(asc == 0)
	  {
		  for (int i = 0; i < size; i++) {
			  for (int j = 0; j < size - i - 1; j++)
			  {
				  if (arr[j] < arr[j + 1]) {
					  int temp = arr[j];
					  arr[j] = arr[j + 1];
					  arr[j + 1] = temp;
				  }
			  }
		  }
	  }
  }
  typedef int(*Cmp)(int a, int b );//ָ�����ͱ�ʾ����,�Ƚ�����,Լ��a��b֮ǰ,�ͷ���-1,a��b֮��ͷ���1,һ���󷵻�0
  void bubbleSort2(int arr[], int size, Cmp cmp ) {//
	  for (int i = 0; i < size; i++) {
		  for (int j = 0; j < size - i - 1; j++)
		  {
			  if (cmp(arr[j],arr[j+1])==1) {
				  int temp = arr[j];
				  arr[j] = arr[j + 1];
				  arr[j + 1] = temp;
			  }
		  }
	  }
  }
  //����ǻص�����
  int less(int a, int b) {
	  if (a == b)
		  return 0;
	  if (a < b)
		  return -1;
	  if (a > b)
		  return 1;
}

int main() {
	/*
	char a = 'a';
	char* p = &a;
	char name[1024] = "caowen";
	char* p2 = name;//&nameҲ����

	char str1[] = "hehe";
	char str2[] = "hehe";
	char* str3 = "hehe";
	char* str4 = "hehe";

	if (str1 == str2) {//�˴����鱾�����ܱȽ�,����ת��Ϊ��ָ��,�Ϳ���ַ�Ƿ����
		printf("���");
	}
	else {
		printf("�����");//����Ϊ�����鲻һ�����ڴ�ռ�
	}

	if (str3 == str4) {
		printf("���");
	}
	else {
		printf("�����");//����Ϊ�����鲻һ�����ڴ�ռ�
	}*/
	/*
	int* arr[4] = { 0 };
	int arr2[5] = { 0 };
	int(*p)[5] = &arr2;
	printf("%p\n", arr2);
	printf("%p\n", &arr2);
	printf("%p\n", arr2 + 1);
	printf("%p\n", &arr2 + 1);


	int arr5[3][5] = {0};
	print(arr5);
	*/
	/*
	int arr[10] = { 0 };
	fun1(arr);
	int* arr2[10] = { 0 };

	fun1(arr2);//����int���͵�����,��һ��int*����,���Բ�һ��
	fun2(arr2);//������һ��
	fun4(arr2);//�������,�β��Ƕ���ָ��,��ʵ��Ҳ�Ƕ���ָ��
	fun5(arr2);//һ��
	*/
	/*
	int arr[3][4] = { 0 };
	fun6(arr);
	fun7(arr);
	*/

	//printf("%p\n", test);//��ȡ�˺���ָ��
	//����ָ���׼ȷ������ɶ
	int(*p)(int) = test;//������һ������P������ź����ĵ�ַ
	//���;���int(*)(int),��˼����(*)˵����һ��ָ��,���Ǻ������͵�ָ��,ǰ���int ˵������ֵ��int ,��һ��int˵��
	//����ʱint
	//Ҳ����д��int(*)(int num),���������num����ʡ��
	//����test2()��˵,���;���
	//void(*)(int,int)
	//int(*p)(int) = &test;//�������Ч��һ��

	void(*p2)(int, int) = test2;
	double(*p3)() = test3;
	int* (*p4)(int*, int*) = test4;
	//����typedef����
	typedef int* (*FunPtr)(int*, int*);
	FunPtr p5 = test4;

	//��ʼչʾ��������,���ú���ָ�����
	p(1);//�ȼ���test(1);
	//(*p)(1);//������Ҳ��һ����

	//(*(void(*)())0)();

	//��ʼ���⺯��ָ������
	/*
	while(1) {
		int choice = 0;
		int a = 0; 
		int b = 0;
		printf("����������ѡ�������������");
		scanf("%d", &choice);
		scanf("%d %d", &a, &b);
		if (choice == 1) {
			add(a, b);
		}
		else if (choice == 2) {
			sub(a, b);
		}
		else if (choice == 3) {
			mul(a, b);
		}
		else {
			div(a, b);
		}
	}*/
	/*
	int choice = 0;
	int a = 0;
	int b = 0;
	Func1 arr[] = { NULL,&add,sub,mul,div };//�Ӳ���&��һ��
	printf("����������ѡ�������������");
	scanf("%d", &choice);
	scanf("%d %d", &a, &b);
	int ret = arr[choice](a, b);
	printf("%d", ret);
	*/
	int arr[5] = { 4,5,6,2,5 };
	bubbleSort2(arr,5,less);
	for (int i = 0; i < 5; i++) {
		printf("%d    ", arr[i]);
	}
	return 0;
}