
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define EASY_COUNT 5   //����׵ĸ������˴�Ϊ5��������ı�
#define ROW 5  //��
#define COL 5  //��

#define ROWS ROW+2
#define COLS COL+2

//��ʼ�����̣�������Ƴ��ַ���1�� ��ע�ⲻ������1��û������Ƴ��ַ���0',�˴������Ϊ����ͳ���׵ĸ������̵�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//���׽��в���
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
