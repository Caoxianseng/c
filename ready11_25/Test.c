#include<stdio.h>
#include<stdlib.h>
//ð������
void swap1(int* array, int i, int j) {
	int temp = 0;
	temp = *(array + i);
	*(array + i) = *(array + j);
	*(array + j) = temp;

}

void bubbleSort(int* str,int index) {
	//ð���������һ��һ��ð,��һ��ð�ľ�������
	//�ó����ľ���ͨ��һ����һ����,�����
	for (int i = 0; i < index - 1; i++) {
		int temp = 0;
		for (int j = 0; j < index - i - 1; j++) {
			if (*(str + j) > *(str + j + 1)) {
				/*temp = *(str + j);
				*(str + j) = *(str + j + 1);
				*(str + j + 1) = temp;*/
				swap1(str, j, j + 1);
			}
		}
	}
}



int main() {s
	/*
	int arr[3][4] = { { 1,2,3,4 }, { 5,6,7,8 }, { 9,10,11,12 } };
	//��ά�����ڷ����±�ʱ��Ҫ�����±�,һ��������һ��������
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			printf("%d " ,arr[row][col]);
		}
		printf("\n");
	}
	*/
	int arr1[10] = { 9,5,2,7,5,4,8,9,6,2 };
	bubbleSort(arr1, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d   ", arr1[i]);
	}
	return 0;
}