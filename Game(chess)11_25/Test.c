#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

//����:
//1.�������̲��ҳ�ʼ��
//2.��ӡ����
//3.��Һ͵�����������,���������(���������������ķ�ʽ)
//4.�ж�ʤ��
//5.����Ҳ����(�����������)
//6.ȷ��ʤ����ϵ
//�ص�2����ִ��,��ӡ�µ�����
int menu() {
	printf("================================\n");
	printf("========  1. ��ʼ��Ϸ  =========\n");
	printf("========  0. �˳���Ϸ  =========\n");
	printf("================================\n");
	printf("����������ѡ��: \n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void init(char chessBoard[ROW][COL]) {
	//��ʼ��,ȫ����Ϊ�ո�
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
}

void printBoard(char chessBoard[ROW][COL]) {
	//��ӡ����,ѭ��
	/*
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			printf("%c ", chessBoard[row][col]);
		}
		printf("\n");
	}
	*/
	printf("+---+---+---+\n");
	for (int row = 0; row < ROW; row++) {
		printf("| %c | %c | %c |\n", chessBoard[row][0], chessBoard[row][1], chessBoard[row][2]);
	printf("+---+---+---+\n");
	}
}
//���������,������������ķ�ʽ��ʵ��
void playerMove(char chessBoard[ROW][COL]) {
	while (1) {
		printf("�����������������(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//�ж��������������Ƿ���ȷ,һ��ҪУ����������Ƿ�Ϸ�
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("�������벻�Ϸ�,����������\n");
			continue;
		}
		//У���������λ���Ƿ��Ѿ�������
		if (chessBoard[row][col] != ' ') {
			printf("�����λ���Ѿ�������,����������\n");
			continue;
		}
		//��������
		chessBoard[row][col] = 'x';
		break;
	}
}
void computerMove(char chessBoard[ROW][COL]) {
	//�������һ����������
	srand(time(0));
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (chessBoard[row][col] != ' ') {
			//�������Ѿ����ӵ�λ��
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}

}
int isFull(char chessBoard[ROW][COL]) {
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char chessBoard[ROW][COL]) {//����x��ʾ��һ�ʤ,����O��ʾ���Ի�ʤ,' '��ʾ����,q��ʾ����
	//p�ж����ҵ�����б��
	for (int row = 0; row< ROW; row++) {
		if (chessBoard[row][0] != ' ' &&
			chessBoard[row][0] == chessBoard[row][1] &&
			chessBoard[row][0] == chessBoard[row][2])
			return chessBoard[row][0];
	}
	for (int col= 0; col< COL; col++) {
		if (chessBoard[0][col] != ' ' &&
			chessBoard[0][col] == chessBoard[1][col] &&
			chessBoard[0][col] == chessBoard[2][col])
			return chessBoard[0][col];
	}
	if (chessBoard[0][0] != ' ' &&
		chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2])
		return chessBoard[0][0];

	if (chessBoard[0][2] != ' ' &&
		chessBoard[1][1] == chessBoard[0][2]
		&& chessBoard[0][2] == chessBoard[2][0])
		return chessBoard[0][2];
	//�ж��Ƿ����,�������Ƿ���ʣ��ռ�
	if (isFull(chessBoard)) {
		return 'q';
	}
	return ' ';
}
//��Ϸ����
 void game() {
	 char winner = ' ';
	 //1.�������̲��ҳ�ʼ��
	 char chessBoard[ROW][COL] = { 0 };
	 //����һ��ʼ�ǿո������0,����Ҫ���г�ʼ��
	 init(chessBoard);
	 while (1) {
		 //2.��ӡ����
		 printBoard(chessBoard);
		 //3.��Һ͵�����������,���������(���������������ķ�ʽ)
		 playerMove(chessBoard);
		 //4.�ж�ʤ��
		  winner = iswin(chessBoard);
		 if (winner != ' ') {
			 break;
		 }
		 //5.����Ҳ����(�����������)
		 computerMove(chessBoard);
		 //6.ȷ��ʤ����ϵ
		 winner= iswin(chessBoard);
		 if (winner != ' ') {
			 break;
		 }
		 //�ص�2����ִ��,��ӡ�µ�����
	 }
	 printBoard(chessBoard);
	 if (winner == 'x') {
		 printf("��ϲ��,��Ӯ��\n");
	 }
	 else if (winner == 'o') {
		 printf("�����˹������²���\n");
	 }
	 else {
		 printf("��ƽ��\n");
	 }
}

int main() {
	//ͨ���򵥵ؽ����˵�������Ϸ
	while (1) {
		int choice = menu();
		if (choice == 1) {
			game();
		}
		else if (choice == 0) {
			printf("goodbye!");
			break;
		}
		else {
			printf("������������,����������\n");
			continue;
		}
	}
}