#define _CRT_SECURE_NO_WARNINGS   1



#include"game.h"

void menu()
{
	printf("**********************\n");
	printf("******  1.PIAY  ******\n");
	printf("******  2.EXIT  ******\n");
	printf("**********************\n");
}
void game()
{
	char ret;
	char board[ROW][COL];//数据是一个二维数组
	InitBoard(board, ROW, COL);//初始化棋盘，将棋盘全初始化为空格
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		PlayerMove(board, ROW, COL);//棋手下棋
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//打印棋盘

		ComputerMove(board, ROW, COL);//电脑移动
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else if (ret == 'Q')
	{
		printf("未分胜负，平局\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));//srand 函数和rand 函数配合使用可生成一个随机值
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请输入： 1->开始游戏  0->退出游戏\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//三子棋游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入.\n");
			break;
		}
	} while (input);
	return 0;
}