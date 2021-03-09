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
	printf("----------ɨ����Ϸ----------\n");
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
	printf("----------ɨ����Ϸ----------\n");
}

void SetMine(char mine[ROW][COL], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{

		//x,y�����û����
			mine[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)//ͳ����ʱ��ֻ�轫��������Χ��8��λ�������Ƿ����׼���һ�¼��ɣ��оͼ��ַ���1����û�м��ַ���0����ͬ�ڲ���
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
//���׵���������Ų�
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		int x;
		int y;
		printf("������Ҫ�Ų�����꣺");
		scanf("%d%d", &x, &y);
		// 1.���ж������Ƿ�Ƿ��������ܳ��ֵ�Խ����Ϊ
		// 2.����Ϸ����жϸô������ǲ����ף�����ǣ�����Ϸ����
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�����\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else //����Ϸ�ʱ���Ҹ����겻����ʱ��ͳ�Ƹ����괦�׵ĸ���
			{
				int count = GetMineCount(mine, x, y);//���GetMineCount������ͳ�Ƹ����괦�׵ĸ���
				show[x][y] = count + '0';
				//����������Χ�׵���Ϣ��ӡ��������
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����Ƿ�������������!!!\n");
		}
	}
	if (row*col - EASY_COUNT == win)
	{
		printf("��ϲ�㣬��Ӯ�ˣ�ɨ�׳ɹ�!!!\n");
		printf("�׵Ĳ���Ϊ��\n");
		DisplayBoard(show, row, col);
	}
}