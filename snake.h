#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#define MAP_HEIGHT 40
#define MAP_WIDTH 40
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct {
	int x;
	int y;
} Food, Snakenode; //定义了食物和蛇身的节点的结构体。

typedef struct {
	Snakenode snakeNode[1000];//蛇身长度数组
	int length;//蛇长
	int speed;//蛇的移动速度
} Snake;

void GotoXY(int, int);
void Hide();
void Menu();
void Help();//帮助
void About();//关于
void Initmap();//地图初始化
void PrintFood();//生成食物
void Movesnake();
int Correct();
void SpeedControl();