#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col,char str) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = str;
		}
	}
}


void displayBoard(char board[ROWS][COLS], int row, int col) {
	printf("------------ɨ����Ϸ------------\n");
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
	printf("------------ɨ����Ϸ------------\n");

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
		printf("�������Ų��׵�����:>");
		scanf_s("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("���ź��㱻ը����\n");
				displayBoard(mine, row, col);
				break;
			}
			else {
				//ͳ���׵ĸ�����������show����
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				displayBoard(show,row,col);
				win++;
			}
		}
		else {
			printf("�����������������\n");
		}
		
	}
	if (win == row * col - EASY_COUNT) {
		printf("��ϲ��Ӯ������Ϸ");
	}
}
