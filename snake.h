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
} Food, Snakenode; //������ʳ�������Ľڵ�Ľṹ�塣

typedef struct {
	Snakenode snakeNode[1000];//����������
	int length;//�߳�
	int speed;//�ߵ��ƶ��ٶ�
} Snake;

void GotoXY(int, int);
void Hide();
void Menu();
void Help();//����
void About();//����
void Initmap();//��ͼ��ʼ��
void PrintFood();//����ʳ��
void Movesnake();
int Correct();
void SpeedControl();