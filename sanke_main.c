#include "snake.h"

int main() {
	srand((int)time(0));//生成种子，但把unsign int改为了int
	int end = 1, result;
	while (end) {
		result = Menu(); //主菜单函数
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