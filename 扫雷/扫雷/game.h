
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define EASY_COUNT 5   //存放雷的个数，此处为5，可任意改变
#define ROW 5  //行
#define COL 5  //列

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘，将雷设计成字符‘1’ ，注意不是数字1，没有雷设计成字符‘0',此处设计是为后续统计雷的个数做铺垫
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//对雷进行布置
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
