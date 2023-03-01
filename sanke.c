#include "snake.h"
Snake snake;//定义蛇结构体变量
Food food;
char now_Dir = RIGHT; //当前蛇头方向
char direction = RIGHT; //预期蛇头方向

int Menu() {
	GotoXY(38, 12); //定位光标位置
	printf("欢迎来到找你母亲的原神冒险");
	GotoXY(43, 15);
	printf("1.开始");
	GotoXY(43, 17);
	printf("2.帮助");
	GotoXY(43, 19);
	printf("3.关于");
	GotoXY(43, 21);
	printf("按其余任意键杀掉您的马结束游戏");
	Hide();//隐藏光标
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
	printf("本游戏由OP向倬仪制作");
	GotoXY(43, 15);
	printf("按任意键返回");
	Hide();
	char ch = _getch();
	system("cls");
}

void help() {
	GotoXY(23, 12);
	printf("wasd不会按是吧，没玩过贪吃蛇建议remake一下。笑嘻咯。");
	GotoXY(43, 15);
	printf("按任意键退出");
	Hide();
	char ch = _getch();
	system("cls");
}

void InitMap() {
	Hide();
	//把蛇头设计在地图中心
	snake.snakeNode[0].x = MAP_WIDTH / 2 - 1;
	snake.snakeNode[0].y = MAP_HEIGHT / 2 - 1;
	GotoXY(snake.snakeNode[0].x, snake.snakeNode[0].y); //将光标移动到蛇头处
	printf("*");
	snake.length = 3;
	snake.speed = 250; //设计蛇的长度和速度
	now_Dir = RIGHT; //确定蛇头方向
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
	PrintfFood();//生成食物
	GotoXY(2, 100);
	printf("当前得分：0");
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