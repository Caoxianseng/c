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
	printf("%d\n", sizeof(arr));//����ȫ����Ԫ��    16
	printf("%d\n", sizeof(arr + 0));//�൱������sizeof(int *)     4
	printf("%d\n", sizeof(*arr));//�൱������sizeof(int)          4
	printf("%d\n", sizeof(arr + 1));//ͬ��          4
	printf("%d\n", sizeof(arr[1]));//sizeof(int)        4
	printf("%d\n", sizeof(&arr));//����ָ��Ҳ��ָ��,Ҳ��4,sizeof(int(*)[4])    4
	printf("%d\n", sizeof(*&arr));//����&,�ٽ�����,�ȵõ�����ָ��,�ٽ����þ�������,�൱��һ   16
	printf("%d\n", sizeof(&*arr));//�൱������sizeof(int *),*�õ�1(int),�ڶ�Intȡ��ַ����ָ��  4
	printf("%d\n", sizeof(&arr + 1));//��Ȼ������ָ��,������4,+1��Ӱ������     4
	printf("%d\n", sizeof(&arr[0]));//����ָ��,sizeof(int*)     4
	printf("%d\n", sizeof(&arr[0] + 1));//ͬ��         4
	*/
	
	/*char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));//6���ֽ�,��Ϊ{}���͵�û��\0        6
	printf("%d\n", sizeof(arr + 0));//��һ��Ԫ�صĵ�ַ,����Ϊchar*,����ռ4���ֽ���32λϵͳ��  4
	printf("%d\n", sizeof(*arr));//�����õ�һ��Ԫ��,����a,����ռ��1���ֽ�char   1
	printf("%d\n", sizeof(arr[1]));//�ڶ���Ԫ��,Ҳ����char,���Ծ���char     1
	printf("%d\n", sizeof(arr + 1));//ͬ��     1
	printf("%d\n", sizeof(&arr));//����ָ��Ҳ����         4
	printf("%d\n", sizeof(*&arr));//����������ָ��,Ҳ����     6
	printf("%d\n", sizeof(&*arr));//char*     4
	printf("%d\n", sizeof(&arr[1]  + 1));//char* Ҳ����    4
	printf("%d\n", sizeof(&arr + 1));//����ָ��,Ҳ����      4
	*/

	/*
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));//strlen,{}û��\0,�ǲ�ȷ����,���������δ������Ϊ
	printf("%d\n", strlen(arr + 0));//δ������Ϊ
	printf("%d\n", strlen(*arr));//strlen����ʱconst char*,����������char���Ծ��ǲ�ƥ��,����ʱ�ͱ���
	printf("%d\n", strlen(arr[1]));//���Ҳ��char����,��ƥ��,����ͻ�ʧ��
	printf("%d\n", strlen(&arr));//��������Ϊchar*
	printf("%d\n", strlen(&arr + 1));//��������Ϊchar*
	printf("%d\n", strlen(&arr[0] + 1));//
	*/

	/*
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));//sizeof����\0����,��\0,      7
	printf("%d\n", sizeof(arr + 0));//sizeof(char*)    4
	printf("%d\n", sizeof(*arr));//  �൱��char        1
	printf("%d\n", sizeof(arr[1]));//�൱����sizeof(char)    1
	printf("%d\n", sizeof(&arr));//����ָ��,��ȻΪ             4
	printf("%d\n", sizeof(&arr + 1));//��������ָ��            4
	printf("%d\n", sizeof(&arr[0] + 1));//char*                4
	printf("%d\n", sizeof(*&arr));//����ָ������ú�Ϊ         7
	printf("%d\n", sizeof(&*arr));//����char*            4
	
	printf("%d\n", strlen(arr));//���Ϊ     6
	printf("%d\n", strlen(arr + 1));//char*,�ӵڶ���Ԫ�ؿ�ʼ��\0,��¼һ��Ϊ5
	printf("%d\n", strlen(&arr + 1));//����ָ��+1������������,����\0����.δ������Ϊ,�������Ͳ�ƥ�� char(*)[7]
	printf("%d\n", strlen(&arr));//��Ȼ�����Ͳ�ƥ��,���Ϊ6,����ָ��ָ���һ��Ԫ��,����6��ʵżȻ,���Ͳ�ƥ��
	printf("%d\n", strlen(&arr[0]));//char* ���Ϊ        6
	printf("%d\n", strlen(*&arr));//����ָ�������,Ϊ����      6
	printf("%d\n", strlen(&*arr));//����char*           6
	printf("%d\n", strlen(&arr[1] + 1));//����c,����       4
	*/

	
    /*
	char* p = "abcdef";
	printf("%d\n", sizeof(p));//char*,����Ϊָ��,������4
	printf("%d\n", sizeof(p + 1));//���Ҳ��char*    4
	printf("%d\n", sizeof(*p));//����ǽ����õõ�a,֮�����    1
	printf("%d\n", sizeof(p[0]));//�����a,char ���Խ������     1
	printf("%d\n", sizeof(&p));// ����ǵ�char** ,��СΪ          4
	printf("%d\n", sizeof(&p + 1));//�����char**,+1��Ӱ������    4
	printf("%d\n", sizeof(&p[1] + 1));//char*                    4
	printf("%d\n", sizeof(&*p));//���Ϊchar*                   4
	

	printf("%d\n", strlen(p));//���         6
	printf("%d\n", strlen(p+1));//�������ָ����b,������     5
	printf("%d\n", strlen(*p));//�õ�char ���Ͳ�ƥ��
	printf("%d\n", strlen(p[1]));//�������Ͳ�ƥ��
	printf("%d\n", strlen(&p));//���Ϊchar**,һ�������ַ���,���Ͳ�ƥ��
	printf("%d\n", strlen(&p[1] + 1));//char*,p[1]�õ�b��ȡ��ַ����b�ĵ�ַ,Ϊchar*,�ڼ�һ����c�ĵ�ַ,���Ϊ      4
	printf("%d\n", strlen(*&p));//char*,���Ϊ          6
	printf("%d\n", strlen(&*p));//         6
	*/
	/*
	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr));//���Ϊ:48
	printf("%d\n", sizeof(arr[0]));//���Ϊ����Ϊ4��һά����,����4*4 = 16

	//arr[0]����int[4] �ڼ�һ���ǰ�int[4]ת��Ϊint*
	printf("%d\n", sizeof(arr[0] + 1 ));//����+1,ת������ָ��       4������
	printf("%d\n", sizeof(&arr[0] + 1));//���Ϊһά���������ָ��,�ڼ�һ���������˵�һ��һά����,Ϊ 4
	printf("%d\n", sizeof(arr[0][0]));//����         4
	printf("%d\n", sizeof(*arr[0]));//arr[0]��һά������Int[4],Ȼ������������Ҫ��ʽת��Ϊָ��,ָ���Int[4]����ĵ�һ��Ԫ��,ת���Ժ��ڽ��н����þ���Ԫ��Int   4
	printf("%d\n", sizeof(*arr));//arr[][]���������ָ��int(*)[4],�ٽ����þ�������ָ������,�õ�16
	printf("%d\n", sizeof(*(arr + 1)));//����+1��ʽת��Ϊ����ָ���Ժ�,��һ���ҽ����þ���  16
	printf("%d\n", sizeof(*arr + 1));//��������ָ��,����ָ������þ���int[4],����ڼ�һ������� ����ʽת��Ϊָ��int* ��1����Ϊ         4
	printf("%d\n", sizeof(&arr[0] + 1));//�Ⱦ��������һ,��ȡ��ַ��������ָ��,�ټ�һ��������ָ�����Ծ���          4
	printf("%d\n", sizeof(*(arr[0] + 1)));//��ʾ��һԪ��,�ڼ�һ���ǲ�������ת����ָ��int*,��һָ��ڶ�Ԫ��,�ٽ����þ��� int    4
	printf("%d", sizeof(arr[3]));//   16,���漰����Խ��,����ΪsizeofΪ��������ֵ
	*/
	
    /*
		int a[5] = { 1, 2, 3, 4, 5 };
		int* ptr = (int*)(&a + 1);
		printf("%d,%d", *(a + 1), *(ptr - 1));//��һ��a+1����ת��Ϊָ���Ժ���+1ָ��2,�����þ���2,
		//�ڶ���,&a��������ָ��,����ָ��ָ��1,���Ǵ�СΪ�ƶ�20�ֽ�
		//���ż�һ,�ͻ�ָ��ĩβԪ�صĺ���,
		//����ǿ��ת��Ϊ��int*,��ַָ��û�иı�,���Ǵ�Сȴ����
		//����-1����ָ����5,�ٽ����þ͵õ���5
		//������2    5
	*/
/*
    //100000+0x14 = 100014,ָ������һ��Ԫ��
	printf("%p\n", p + 0x1);
	//ǿ��ת��Ϊ����,������һ������ĩβֱ�Ӽ�һ   100001
	printf("%p\n",(unsigned long) p + 0x1);
	//ָ����ת��ΪInt*,����һ��ָ�������1���ĸ��ֽڵ�Ԫ��,����100004
	printf("%p\n", (unsigned int*)p + 0x1);
	*/

    /*
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);//&a��������ָ��,�ټ�һ�����˺���,��ת��Ϊ��С�ı�int*��ָ��
	int* ptr2 = (int*)((int)a + 1);//���ǰ�ָ���һ��Ԫ�ص�ָ��ת��ΪInt,�����ټ�һ,�����Ǽ���һ,��ת��Ϊָ������
	printf("%x,%d", ptr1[-1], *ptr2);//ָ��-1����ָ�������һ��Ԫ��,Ҳ����4,
	//�ڶ���:����ͼ��,��������,������С���ֽ����
	*/
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };// 1 3 5  0 0 0  0 0 0 
    int* p;
    p = a[0];
    printf("%d", p[0]);//p[0][0]�൱��

	return 0;
}
