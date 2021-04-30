#include "main.h"
#include "util.h"

int main() {
	init();
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (START_GAME == menuCode) {
			int n = maplistDraw();
			if (EASY == n){
				gLoop(0);
			}
			else if (HARD == n) {
				gLoop(1);
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