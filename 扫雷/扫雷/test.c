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
	//�������̶�Ӧ������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	InitBoard(mine, ROWS, COLS, '0');//��Ų����׵���Ϣ
	InitBoard(show, ROWS, COLS, '*');//����Ų���׵���Ϣ

	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
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
		printf("������ 1 ��ʼ��Ϸ ���� 0 �˳���Ϸ> \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//ɨ����Ϸ��ʵ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");

		}
	} while (input);
	return 0;
}