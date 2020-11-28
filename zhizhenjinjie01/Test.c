#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void print(int arr[][5]) {//非常ok,可以省略3

//}
//void print(int(*p)[5]) {

//}
void fun1(int arr[10]) {//形参名字是的哈没有关系

}
void fun2(int arr[]) {//这个和上面是一样的,可以省略里面的大小

}
void fun3(int* arr) {//也没有任何问题说明就是那个惊天BUG

}
void fun4(int* arr[]) {//不行,是因为两个类型不匹配
	//两个间接级别,也就是类型不匹配,形参和实参的类型要一样
	//实参是arr,就是在传int [10],而对于形参来说,就是时int**,int arr[] 和int*arr等价,所以加上*之后就是int **,所以两个不一样
	//之所以是警告,是因为C语言是弱类型语言,越支持隐式转换越是弱类型
	//实际写代码时,不要这样写,是因为有很大的风险
}
void fun5(int** arr) {
	//和上面没有区别
}
//最后两种是不可以的
void fun6(int arr[3][4]) {

}
void fun7(int arr[][4]) {

}
//void fun8(int arr[][]) {//不可以,是因为编译不通过

//}
void fun9(int(*p)[4]) {

}
void fun10(int arr[3][5]){//这个不行,是因为转换为int(*p)[5],与实参不匹配

}
void fun11(int arr[4][4]) {//这个可以,只因为转换为了int(*p)[4],这就可以,和实参一样

}
void fun12(int** arr) {//这个不行,只一个二级指针,实参不是二级指针,是一个数组指针

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

  //一个函数实现
  //asc为1位正序排列,asc为0时降序
  //以下不好.比较大小,光用一个标记为不够,回调函数,逻辑制订了比较规则
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
  typedef int(*Cmp)(int a, int b );//指向函数就表示规则,比交规则,约定a在b之前,就返回-1,a在b之后就返回1,一样大返回0
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
  //这就是回调函数
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
	char* p2 = name;//&name也可以

	char str1[] = "hehe";
	char str2[] = "hehe";
	char* str3 = "hehe";
	char* str4 = "hehe";

	if (str1 == str2) {//此处数组本来不能比较,但是转换为了指针,就看地址是否相等
		printf("相等");
	}
	else {
		printf("不相等");//是因为是两块不一样的内存空间
	}

	if (str3 == str4) {
		printf("相等");
	}
	else {
		printf("不相等");//是因为是两块不一样的内存空间
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

	fun1(arr2);//不是int类型的数组,是一个int*数组,所以不一样
	fun2(arr2);//和上面一样
	fun4(arr2);//这个可以,形参是二级指针,这实参也是二级指针
	fun5(arr2);//一样
	*/
	/*
	int arr[3][4] = { 0 };
	fun6(arr);
	fun7(arr);
	*/

	//printf("%p\n", test);//获取了函数指针
	//函数指针的准确类型是啥
	int(*p)(int) = test;//创建了一个变量P用来存放函数的地址
	//类型就是int(*)(int),意思就是(*)说明是一个指针,还是函数类型的指针,前面的int 说明返回值是int ,后一个int说明
	//参数时int
	//也可以写成int(*)(int num),但是里面的num可以省略
	//对于test2()来说,类型就是
	//void(*)(int,int)
	//int(*p)(int) = &test;//和上面的效果一样

	void(*p2)(int, int) = test2;
	double(*p3)() = test3;
	int* (*p4)(int*, int*) = test4;
	//采用typedef来简化
	typedef int* (*FunPtr)(int*, int*);
	FunPtr p5 = test4;

	//开始展示函数调用,利用函数指针调用
	p(1);//等价于test(1);
	//(*p)(1);//和上面也是一样的

	//(*(void(*)())0)();

	//开始讲解函数指针数组
	/*
	while(1) {
		int choice = 0;
		int a = 0; 
		int b = 0;
		printf("请输入您的选择和两个操作数");
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
	Func1 arr[] = { NULL,&add,sub,mul,div };//加不加&都一样
	printf("请输入您的选择和两个操作数");
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