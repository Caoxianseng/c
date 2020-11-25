#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

//流程:
//1.创建棋盘并且初始化
//2.打印棋盘
//3.玩家和电脑轮流落子,玩家先落子(玩家输入行列坐标的方式)
//4.判断胜负
//5.电脑也落子(电脑随机落子)
//6.确认胜负关系
//回到2继续执行,打印新的棋面
int menu() {
	printf("================================\n");
	printf("========  1. 开始游戏  =========\n");
	printf("========  0. 退出游戏  =========\n");
	printf("================================\n");
	printf("请输入您的选择: \n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void init(char chessBoard[ROW][COL]) {
	//初始化,全部设为空格
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
}

void printBoard(char chessBoard[ROW][COL]) {
	//打印棋盘,循环
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
//让玩家落子,输入行列坐标的方式来实现
void playerMove(char chessBoard[ROW][COL]) {
	while (1) {
		printf("请玩家输入行列坐标(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//判断玩家输入的坐标是否正确,一定要校验玩家输入是否合法
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("您的输入不合法,请重新输入\n");
			continue;
		}
		//校验玩家落子位置是否已经有子了
		if (chessBoard[row][col] != ' ') {
			printf("这个卫位置已经有子了,请重新输入\n");
			continue;
		}
		//真正落子
		chessBoard[row][col] = 'x';
		break;
	}
}
void computerMove(char chessBoard[ROW][COL]) {
	//随机产生一组行列坐标
	srand(time(0));
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (chessBoard[row][col] != ' ') {
			//不能是已经有子的位置
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

char iswin(char chessBoard[ROW][COL]) {//返回x表示玩家获胜,返回O表示电脑获胜,' '表示继续,q表示合棋
	//p判定左右的行列斜线
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
	//判断是否合棋,看棋盘是否有剩余空间
	if (isFull(chessBoard)) {
		return 'q';
	}
	return ' ';
}
//游戏函数
 void game() {
	 char winner = ' ';
	 //1.创建棋盘并且初始化
	 char chessBoard[ROW][COL] = { 0 };
	 //棋盘一开始是空格而不是0,所以要进行初始化
	 init(chessBoard);
	 while (1) {
		 //2.打印棋盘
		 printBoard(chessBoard);
		 //3.玩家和电脑轮流落子,玩家先落子(玩家输入行列坐标的方式)
		 playerMove(chessBoard);
		 //4.判断胜负
		  winner = iswin(chessBoard);
		 if (winner != ' ') {
			 break;
		 }
		 //5.电脑也落子(电脑随机落子)
		 computerMove(chessBoard);
		 //6.确认胜负关系
		 winner= iswin(chessBoard);
		 if (winner != ' ') {
			 break;
		 }
		 //回到2继续执行,打印新的棋面
	 }
	 printBoard(chessBoard);
	 if (winner == 'x') {
		 printf("恭喜你,你赢了\n");
	 }
	 else if (winner == 'o') {
		 printf("您连人工智障下不过\n");
	 }
	 else {
		 printf("您平手\n");
	 }
}

int main() {
	//通过简单地交互菜单进行游戏
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
			printf("您的输入有误,请重新输入\n");
			continue;
		}
	}
}