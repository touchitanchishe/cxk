#include "snake.h"

int main() {
	srand((int)time(0));//�������ӣ�����unsign int��Ϊ��int
	int end = 1, result;
	while (end) {
		result = Menu(); //���˵�����
		switch (result) {
			case 1:
				InitMap();
				while (MoveSnake());
				break;
			case 2:
				Hlep();
				break;
			case 3:
				About();
				break;
			case 0;
				end = 0;
				break;
		}
	}
	return 0;
}