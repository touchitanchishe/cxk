#include "snake.h"
Snake snake;//�����߽ṹ�����
Food food;
char now_Dir = RIGHT; //��ǰ��ͷ����
char direction = RIGHT; //Ԥ����ͷ����

int Menu() {
	GotoXY(38, 12); //��λ���λ��
	printf("��ӭ��������ĸ�׵�ԭ��ð��");
	GotoXY(43, 15);
	printf("1.��ʼ");
	GotoXY(43, 17);
	printf("2.����");
	GotoXY(43, 19);
	printf("3.����");
	GotoXY(43, 21);
	printf("�����������ɱ�������������Ϸ");
	Hide();//���ع��
	char ch;
	int result = 0;
	ch = _getch();
	switch (ch) {
		case '1':
			result = 1;
			break;
		case '2':
			result = 2;
			break;
		case '3':
			result = 3;
			break;
	}
	sysytem("cls");
	return result;
}

void GotoXY(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}

void Hide() {
	HANDLE hout = GetStdHandle(STD_OUTPUT - HANDLE);
	CONSOLE_CURSOR - INFO cor_info = {1, 0};
	SetConsoleCursorInfo(hout, &cor_info);
}

void About() {
	GotoXY(43, 12);
	printf("����Ϸ��OP��پ������");
	GotoXY(43, 15);
	printf("�����������");
	Hide();
	char ch = _getch();
	system("cls");
}

void help() {
	GotoXY(23, 12);
	printf("wasd���ᰴ�ǰɣ�û���̰���߽���remakeһ�¡�Ц������");
	GotoXY(43, 15);
	printf("��������˳�");
	Hide();
	char ch = _getch();
	system("cls");
}

void InitMap() {
	Hide();
	//����ͷ����ڵ�ͼ����
	snake.snakeNode[0].x = MAP_WIDTH / 2 - 1;
	snake.snakeNode[0].y = MAP_HEIGHT / 2 - 1;
	GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y); //������ƶ�����ͷ��
	printf("*");
	snake.length = 3;
	snake.speed = 250; //����ߵĳ��Ⱥ��ٶ�
	now_Dir = RIGHT; //ȷ����ͷ����
	for (int i = 1; i < snake.length; i++) {
		snake.snakeNode[i].y = snake.snakeNode[i - 1].x;
		snake.snakeNode[i].x = snake.sankeNode[i - 1].x - 1;
		GotoXY(snake.snakeNode[i].x, snake.snakeNode[i].y);
		printf("?");
	}
	for (int i = 0; i < MAP_HEIGHT; i++) {
		GotoXY(0, i);
		printf("?");
		GotoXY(MAP_HEIGHT - 1, i);
		printf("?");
	}
	for (int i = 0; i < MAP_WIDTH, i++) {
		GotoXY(i, 0);
		printf("?");
		GotoXY(i, MAP_WIDTH - 1);
		printf("?");
	}
	PrintfFood();//����ʳ��
	GotoXY(2, 100);
	printf("��ǰ�÷֣�0");
}

void PrintFood() {
	int flag = 1;
	while (flag) {
		flag = 0;
		food.x = rand() % (MAP_WIDTH - 2) + 1;
		food.y = rand() % (MAP_HEIGHT - 2) + 1;
		for (int i = 0; i <= snake.length - 1; i++) {
			if (food.x = snake.snakeNode[i].x && food.y == snake.snakeNode[i].y) {
				flag = 1;
				break;
			}

		}
	}
	GotoXY(food.x, food.y);
	printf("?");
}

int Movesnake() {
	Snakenode temp;
	int flag = 0;
}