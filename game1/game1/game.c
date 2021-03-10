#define _CRT_SECURE_NO_WARNINGS   1

#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)//将数组全部初始化为空格
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)//一行三个空格只打印两个’| ’即可
			printf("|");
		}
		printf("\n");
		if (i < row - 1)//一列三个空格也只需要打印两排‘ --- ’即可
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|"); //同理一行三个空格只打印两个’ | ’即可
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x;//横坐标
	int y;//纵坐标
	while (1)
	{
		printf("请输入坐标->\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row  &&y > 0 && y <= col)//判断坐标的合法性，横纵坐标是否在1到3之间
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("坐标被占用，请重新输入\n");
			}
			else
			{
				board[x-1][y-1] = '*';
				break;//玩家落子后循环跳出
			}	
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % row;//rand()为获得随机值得函数，获取的随机值模row即3就可以得到在0到2之间的一个随机值
		int y = rand() % col;//纵坐标同理
		
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;//电脑落子后跳出循环
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row, int col)//判断赢得情况，返回值为字符
                                       //玩家赢返回值为 * //电脑赢时返回值为 # 
									   //平局时返回值为 Q //仍可以下棋且为分胜负时返回值为 C
{
	int i = 0;
	for (i = 0; i < row; i++)//一行相同时
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[0][i] != ' ')
		{
			return board[i][0];//返回值为board[i][0]不用考虑是返回 * 还是 #两者都可以返回
		}
	
	}
	for (i = 0; i < col; i++)//一列相同时
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线相同时的两种情况
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//棋盘全部下满仍未分胜负的情况
	if (IsFull(board, row, col) == 1)//IsFull为判断棋盘是否全满时，当全满时返回值为1，未满时为0
	{
		return 'Q';
	}
	return 'C';//返回值为C游戏继续
}