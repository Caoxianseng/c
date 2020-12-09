#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<string.h>
int main() {
	//\为转义字符
	/*char name[] = "D:\\program1\\qq\\Bin";
	printf("%s", name);*/
	//打开文件
	//返回结果叫做"文件指针",有的时候也叫作"句柄"(handler),句柄就是遥控器
	//文件打开可能会失败,就会返回NULL
	//int count = 0;

	//while (1) {
	//	FILE* f = fopen("E:/离散数学/谓词逻辑02（预备知识）.docx", "r");//这里的FILE是一个结构体
	//	if (f == NULL) {
	//		//printf("文件打开失败! errno = %d, %s\n",errno,strerror(errno));//errno是一个宏
	//		perror("文件打开失败!");
	//		system("pause");
	//		return 1;
	//	}
	//	count++;
	//	printf("文件打开成功!");
	//	printf("%d\n", count);
	//}
	//关闭文件
	//fclose(f);//就是关闭刚才的句柄,使用完毕以后,一定要关闭文件,否则就会泄漏,叫做:文件资源泄漏
	//更容易泄漏
	FILE* f = fopen("E:/离散数学/111.txt", "w");//这里的FILE是一个结构体
	if (f == NULL) {
		//printf("文件打开失败! errno = %d, %s\n",errno,strerror(errno));//errno是一个宏
		perror("文件打开失败!");
		system("pause");
		return 1;
	}
	printf("文件打开成功!\n");
	/*这都是读数据
	//负责把磁盘上的数据读取到内存中
	char buf[1024] = { 0 };
	//第二个参数和第三个参数相乘就得到要读取的整体的字节数
	int n = fread(buf, 1, 1024, f);//完成读取操作
	//返回值就是实际读取的元素个数
	//预期和实际的不一样,参数就是预期的,但是n就是实际得到的
	//如果实际读到的元素个数小于预期的,可以认为文件读完了,
	//如果大于,就是没有读完,就循环读,
	printf("%s\n", buf);*/
	
	//开始写数据  fwrite()负责吧内存的数据写到磁盘中去
	//如果fwrite要是成功了,就会返回实际写入的元素个数,如果失败了,就会返回小于0的数字结果
	/*
	char  buf[1024] = "hahaha";
	int n = fwrite(buf, 1, strlen(buf), f);
	if (n < strlen(buf)) {
		perror("fwrite");
	}*/

	//使用fprintf
	/*int num = 10;
	fprintf(f,"num = %d",num);*/
	int num = 10;
	//fprintf(stdout, "num = %d", num);//这个操作和printf等价
	//fscanf(stdin,"",)和scanf等价
	//sprintf/sscanf这俩个很重要,把格式化结果写到字符串中和   从格式化中解析
	//把整数转成字符串,也可以把字符串转为整数
	/*
	char buf[1024] = { 0 };
	sprintf(buf, "num = %d", num);//会被写到buf中
	printf("%s\n", buf);
	*/
	char buf[1024] = { 0 };
	//这个不是输出,只是转换
	sprintf(buf, "%d", num);//于是buf中就包含了10字符串
	printf("%c\n", buf[0]);
	printf("%c\n", buf[1]);
	printf("%c\n", buf[2]);//\0

	//同理就用sscanf来转换,将字符串转换为整形数字

	//在C语言中,海还有一组数组能够转换为字符串与整数之间的转换
	//atoi   itoa,相互转换
;	fclose(f);
	return 0;
}