
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家走
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑走
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢 此时函数有返回值了 不能再用void了，返回值为字符要用char
char CheckWin(char board[ROW][COL], int row, int col);