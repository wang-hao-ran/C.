#define _CRT_SECURE_NO_WARNINGS   1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 1; i <= rows - 2; i++)
	{
		int j = 0;
		for (j = 1; j <= cols - 2; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("----------扫雷游戏----------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏----------\n");
}

void SetMine(char mine[ROW][COL], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{

		//x,y坐标出没有雷
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)//统计雷时，只需将该坐标周围的8个位置坐标是否有雷计算一下即可，有就加字符‘1’，没有加字符‘0’等同于不加
{
	int i = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		int j = 0;
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
//对雷的情况进行排查
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		int x;
		int y;
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		// 1.先判断坐标是否非法，即可能出现的越界行为
		// 2.坐标合法，判断该处坐标是不是雷，如果是，则游戏结束
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！！！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else //坐标合法时，且该坐标不是雷时，统计该坐标处雷的个数
			{
				int count = GetMineCount(mine, x, y);//设计GetMineCount函数，统计该坐标处雷的个数
				show[x][y] = count + '0';
				//将该坐标周围雷的信息打印在棋盘上
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入!!!\n");
		}
	}
	if (row*col - EASY_COUNT == win)
	{
		printf("恭喜你，你赢了，扫雷成功!!!\n");
		printf("雷的布局为：\n");
		DisplayBoard(show, row, col);
	}
}