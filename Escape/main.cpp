#include "main.h"

int main() {
	init();
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (START_GAME == menuCode) {
			int n = maplistDraw();
			if (EASY == n)
			{
				drawMap();
			}
			else if (HARD == n) {
				printf("어려움 선택함");
				Sleep(1000);
			}
		}else if (HELP_GAME == menuCode) {
			infoDraw();
		}else if (EXIT_GAME == menuCode) {
			return 0;
		}
		system("cls");
	}
	return 0;
}