#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 20
void InitBoard(char board[ROWS][COLS],int row,int col,char str);
void displayBoard(char board[ROWS][COLS], int row,int col);
void setMine(char mine[ROWS][COLS], int row ,int col);
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

