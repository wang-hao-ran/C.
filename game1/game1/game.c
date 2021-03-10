#define _CRT_SECURE_NO_WARNINGS   1

#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)//������ȫ����ʼ��Ϊ�ո�
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
			if (j<col-1)//һ�������ո�ֻ��ӡ������| ������
			printf("|");
		}
		printf("\n");
		if (i < row - 1)//һ�������ո�Ҳֻ��Ҫ��ӡ���š� --- ������
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|"); //ͬ��һ�������ո�ֻ��ӡ������ | ������
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x;//������
	int y;//������
	while (1)
	{
		printf("����������->\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row  &&y > 0 && y <= col)//�ж�����ĺϷ��ԣ����������Ƿ���1��3֮��
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("���걻ռ�ã�����������\n");
			}
			else
			{
				board[x-1][y-1] = '*';
				break;//������Ӻ�ѭ������
			}	
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	while (1)
	{
		int x = rand() % row;//rand()Ϊ������ֵ�ú�������ȡ�����ֵģrow��3�Ϳ��Եõ���0��2֮���һ�����ֵ
		int y = rand() % col;//������ͬ��
		
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;//�������Ӻ�����ѭ��
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
char CheckWin(char board[ROW][COL], int row, int col)//�ж�Ӯ�����������ֵΪ�ַ�
                                       //���Ӯ����ֵΪ * //����Ӯʱ����ֵΪ # 
									   //ƽ��ʱ����ֵΪ Q //�Կ���������Ϊ��ʤ��ʱ����ֵΪ C
{
	int i = 0;
	for (i = 0; i < row; i++)//һ����ͬʱ
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[0][i] != ' ')
		{
			return board[i][0];//����ֵΪboard[i][0]���ÿ����Ƿ��� * ���� #���߶����Է���
		}
	
	}
	for (i = 0; i < col; i++)//һ����ͬʱ
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ�����ͬʱ���������
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//����ȫ��������δ��ʤ�������
	if (IsFull(board, row, col) == 1)//IsFullΪ�ж������Ƿ�ȫ��ʱ����ȫ��ʱ����ֵΪ1��δ��ʱΪ0
	{
		return 'Q';
	}
	return 'C';//����ֵΪC��Ϸ����
}