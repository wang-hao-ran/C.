#define _CRT_SECURE_NO_WARNINGS   1
#include "game.h"
void menu()
{
	printf("***************************\n");
	printf("*******   1.PLAY   ********\n");
	printf("*******   2.EXIT   ********\n");
	printf("***************************\n");
}
void game()
{
	//创建棋盘对应的数组
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	InitBoard(mine, ROWS, COLS, '0');//存放布置雷的信息
	InitBoard(show, ROWS, COLS, '*');//存放排查出雷的信息

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL, EASY_COUNT);

	//DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{

		menu();
		printf("请输入 1 开始游戏 输入 0 退出游戏> \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//扫雷游戏的实现
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");

		}
	} while (input);
	return 0;
}