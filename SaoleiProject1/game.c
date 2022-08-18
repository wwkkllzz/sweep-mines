#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col,char str) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = str;
		}
	}
}


void displayBoard(char board[ROWS][COLS], int row, int col) {
	printf("------------扫雷游戏------------\n");
	int i = 0; int j = 0;
	for (int k = 0; k <=col; k++) {
		printf("%d ",k);
	}
	printf("\n");
	for ( i = 1; i <=row; i++) {
		printf("%d ",i);
		for ( j = 1; j <= col; j++) {
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("------------扫雷游戏------------\n");

}

void setMine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;

	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

//int get_mine_count(char mine[ROWS][COLS], int x, int y) {
//	for (int i = -1; i <= 1; i++) {
//		for (int j = -1; j <= 1; j++) {
//			return ( mine[x][y])-(8*'0');
//		}
//	}
//}

int get_mine_count(char mine[ROWS][COLS], int x, int y) {
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

}
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x=0, y=0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("请输入排查雷的坐标:>");
		scanf_s("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("很遗憾你被炸死了\n");
				displayBoard(mine, row, col);
				break;
			}
			else {
				//统计雷的个数，并放入show数组
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				displayBoard(show,row,col);
				win++;
			}
		}
		else {
			printf("输入错误，请重新输入\n");
		}
		
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜你赢得了游戏");
	}
}
