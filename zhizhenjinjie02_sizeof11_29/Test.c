#include<stdio.h>
#include<string.h>
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p = (struct Test*)0x100000;
int main() {
	/*
	int arr[] = { 1,2,3,4 };
	printf("%d\n", sizeof(arr));//数组全部的元素    16
	printf("%d\n", sizeof(arr + 0));//相当于在求sizeof(int *)     4
	printf("%d\n", sizeof(*arr));//相当于在求sizeof(int)          4
	printf("%d\n", sizeof(arr + 1));//同二          4
	printf("%d\n", sizeof(arr[1]));//sizeof(int)        4
	printf("%d\n", sizeof(&arr));//数组指针也是指针,也是4,sizeof(int(*)[4])    4
	printf("%d\n", sizeof(*&arr));//先求&,再解引用,先得到数组指针,再解引用就是数组,相当于一   16
	printf("%d\n", sizeof(&*arr));//相当于在求sizeof(int *),*得到1(int),在对Int取地址就是指针  4
	printf("%d\n", sizeof(&arr + 1));//依然是数组指针,所以是4,+1不影响类型     4
	printf("%d\n", sizeof(&arr[0]));//就是指针,sizeof(int*)     4
	printf("%d\n", sizeof(&arr[0] + 1));//同上         4
	*/
	
	/*char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6个字节,因为{}类型的没有\0        6
	printf("%d\n", sizeof(arr + 0));//第一个元素的地址,所以为char*,就是占4个字节在32位系统下  4
	printf("%d\n", sizeof(*arr));//解引用第一个元素,就是a,所以占了1个字节char   1
	printf("%d\n", sizeof(arr[1]));//第二个元素,也就是char,所以就是char     1
	printf("%d\n", sizeof(arr + 1));//同上     1
	printf("%d\n", sizeof(&arr));//数组指针也就是         4
	printf("%d\n", sizeof(*&arr));//解引用数组指针,也就是     6
	printf("%d\n", sizeof(&*arr));//char*     4
	printf("%d\n", sizeof(&arr[1]  + 1));//char* 也就是    4
	printf("%d\n", sizeof(&arr + 1));//数组指针,也就是      4
	*/

	/*
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//strlen,{}没有\0,是不确定的,所以这个是未定义行为
	printf("%d\n", strlen(arr + 0));//未定义行为
	printf("%d\n", strlen(*arr));//strlen参数时const char*,但是这里是char所以就是不匹配,编译时就报错
	printf("%d\n", strlen(arr[1]));//这个也是char类型,不匹配,编译就会失败
	printf("%d\n", strlen(&arr));//参数类型为char*
	printf("%d\n", strlen(&arr + 1));//参数类型为char*
	printf("%d\n", strlen(&arr[0] + 1));//
	*/

	/*
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//sizeof遇到\0结束,算\0,      7
	printf("%d\n", sizeof(arr + 0));//sizeof(char*)    4
	printf("%d\n", sizeof(*arr));//  相当于char        1
	printf("%d\n", sizeof(arr[1]));//相当于求sizeof(char)    1
	printf("%d\n", sizeof(&arr));//数组指针,任然为             4
	printf("%d\n", sizeof(&arr + 1));//还是数组指针            4
	printf("%d\n", sizeof(&arr[0] + 1));//char*                4
	printf("%d\n", sizeof(*&arr));//数组指针解引用后为         7
	printf("%d\n", sizeof(&*arr));//就是char*            4
	
	printf("%d\n", strlen(arr));//结果为     6
	printf("%d\n", strlen(arr + 1));//char*,从第二个元素开始找\0,记录一共为5
	printf("%d\n", strlen(&arr + 1));//数组指针+1跳过整个数组,跳到\0后面.未定义行为,而且类型不匹配 char(*)[7]
	printf("%d\n", strlen(&arr));//任然是类型不匹配,结果为6,数组指针指向第一个元素,看是6其实偶然,类型不匹配
	printf("%d\n", strlen(&arr[0]));//char* 结果为        6
	printf("%d\n", strlen(*&arr));//数组指针解引用,为数组      6
	printf("%d\n", strlen(&*arr));//还是char*           6
	printf("%d\n", strlen(&arr[1] + 1));//跳到c,就是       4
	*/

	
    /*
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//char*,类型为指针,所以是4
	printf("%d\n", sizeof(p + 1));//这个也是char*    4
	printf("%d\n", sizeof(*p));//这个是解引用得到a,之后就是    1
	printf("%d\n", sizeof(p[0]));//这个是a,char 所以结果就是     1
	printf("%d\n", sizeof(&p));// 这个是地char** ,大小为          4
	printf("%d\n", sizeof(&p + 1));//这个是char**,+1不影响类型    4
	printf("%d\n", sizeof(&p[1] + 1));//char*                    4
	printf("%d\n", sizeof(&*p));//结果为char*                   4
	

	printf("%d\n", strlen(p));//结果         6
	printf("%d\n", strlen(p+1));//这里就是指向了b,向后就是     5
	printf("%d\n", strlen(*p));//得到char 类型不匹配
	printf("%d\n", strlen(p[1]));//还是类型不匹配
	printf("%d\n", strlen(&p));//结果为char**,一定不是字符串,类型不匹配
	printf("%d\n", strlen(&p[1] + 1));//char*,p[1]得到b再取地址就是b的地址,为char*,在加一就是c的地址,结果为      4
	printf("%d\n", strlen(*&p));//char*,结果为          6
	printf("%d\n", strlen(&*p));//         6
	*/
	/*
	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr));//结果为:48
	printf("%d\n", sizeof(arr[0]));//结果为长度为4的一维数组,就是4*4 = 16

	//arr[0]就是int[4] 在加一就是把int[4]转换为int*
	printf("%d\n", sizeof(arr[0] + 1 ));//数组+1,转换成了指针       4数组名
	printf("%d\n", sizeof(&arr[0] + 1));//结果为一维数组的数组指针,在加一就是跳过了第一个一维数组,为 4
	printf("%d\n", sizeof(arr[0][0]));//就是         4
	printf("%d\n", sizeof(*arr[0]));//arr[0]是一维数组再Int[4],然后参与了运算就要隐式转换为指针,指向第Int[4]里面的第一个元素,转换以后在进行解引用就是元素Int   4
	printf("%d\n", sizeof(*arr));//arr[][]变成了数组指针int(*)[4],再解引用就是数字指解引用,得到16
	printf("%d\n", sizeof(*(arr + 1)));//先算+1隐式转换为数组指针以后,加一并且解引用就是  16
	printf("%d\n", sizeof(*arr + 1));//还是数组指针,数组指针解引用就是int[4],最后在加一不变就是 先隐式转换为指针int* 加1不变为         4
	printf("%d\n", sizeof(&arr[0] + 1));//先就是数组第一,再取地址就是数组指针,再加一就是数组指针所以就是          4
	printf("%d\n", sizeof(*(arr[0] + 1)));//显示第一元素,在加一就是参与运算转换成指针int*,加一指向第二元素,再解引用就是 int    4
	printf("%d", sizeof(arr[3]));//   16,不涉及后面越界,是因为sizeof为编译器求值
	*/
	
    /*
		int a[5] = { 1, 2, 3, 4, 5 };
		int* ptr = (int*)(&a + 1);
		printf("%d,%d", *(a + 1), *(ptr - 1));//第一个a+1就是转换为指针以后再+1指向2,解引用就是2,
		//第二个,&a先是数组指针,数组指针指向1,但是大小为移动20字节
		//接着加一,就会指向末尾元素的后面,
		//接着强制转换为了int*,地址指向没有改变,但是大小却变了
		//接着-1就是指向了5,再解引用就得到了5
		//所以是2    5
	*/
/*
    //100000+0x14 = 100014,指针跳过一个元素
	printf("%p\n", p + 0x1);
	//强制转换为整数,整数加一就是在末尾直接加一   100001
	printf("%p\n",(unsigned long) p + 0x1);
	//指针先转换为Int*,就是一个指针加上了1个四个字节的元素,就是100004
	printf("%p\n", (unsigned int*)p + 0x1);
	*/

    /*
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);//&a先是数组指针,再加一跳到了后面,在转换为大小改变int*的指针
	int* ptr2 = (int*)((int)a + 1);//先是把指向第一个元素的指针转换为Int,接着再加一,仅仅是加了一,在转换为指针类型
	printf("%x,%d", ptr1[-1], *ptr2);//指针-1就是指向了最后一个元素,也就是4,
	//第二个:就是图解,分析过程,包括大小端字节序等
	*/
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };// 1 3 5  0 0 0  0 0 0 
    int* p;
    p = a[0];
    printf("%d", p[0]);//p[0][0]相当于

	return 0;
}
