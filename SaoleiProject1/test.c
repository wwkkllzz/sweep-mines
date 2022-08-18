#include"game.h"

void menu() {
	printf("************************\n");
	printf("****      1.play    ****\n");
	printf("****      0.exit    ****\n");
	printf("************************\n");

}

void game() {
	char mine[ROWS][COLS]={0};
	//´òÓ¡ÆåÅÌ
	char show[ROWS][COLS]={0};
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	displayBoard(show, ROW, COL);
	//²¼ÖÃÀ×
	setMine(mine,ROW,COL);
    //displayBoard(mine, ROW, COL);

	//ÅÅ²éÀ×
	findMine(mine, show, ROW, COL);
}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("ÇëÑ¡Ôñ:>\n");
		scanf_s("%d", &input);
		switch (input) {
		case 1:game();
			break;
		case 0:printf("ÍË³ö³ÌĞò\n");
			break;
		default:printf("ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë:>\n");
			break;
		}

	} while (input);

	return 0;
}