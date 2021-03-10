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
	char board[ROW][COL];//������һ����ά����
	InitBoard(board, ROW, COL);//��ʼ�����̣�������ȫ��ʼ��Ϊ�ո�
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		PlayerMove(board, ROW, COL);//��������
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);//��ӡ����

		ComputerMove(board, ROW, COL);//�����ƶ�
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (ret == 'Q')
	{
		printf("δ��ʤ����ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));//srand ������rand �������ʹ�ÿ�����һ�����ֵ
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("�����룺 1->��ʼ��Ϸ  0->�˳���Ϸ\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������.\n");
			break;
		}
	} while (input);
	return 0;
}