#include "game.h"

char map[18][60] = {
	{"11111111111111111111111111111111111111111111111111111111111"}, // 1은 벽 0은 공백 s는 사람 q는 도착점
	{"10000000000000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"10s01000000000000000000000000000000000000000000000000q00001"},
	{"10001000000000000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111111"}
};

void drawMap() {
	system("cls");

	for (int h = 0; h < 18; h++) {
		for (int w = 0; w < 60; w++) {
			char temp = map[h][w];
			if ('0' == temp) {			//빈칸
				printf(" ");
			}
			else if ('1' == temp) {		//벽
				printf("#");
			}
			else if ('s' == temp) {		//사람
				printf("@");
			}
			else if ('q' == temp) {		//도착점
				printf("O");
			}
		}
		printf("\n");
	}
	Sleep(4000);
}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}

	return -1;
}

void titleDraw()
{
	printf("\n\n\n\n\n");
	printf("          #####  #####  #####     #     #####  ##### \n");
	printf("          #      #      #        # #    #      #     \n");
	printf("          ####   #####  #       #####   #####  ####  \n");
	printf("          #          #  #      #     #  #      #     \n");
	printf("          #####  #####  ##### #       # #      ##### \n");
}

int menuDraw() {
	int x = 24, y = 12;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작");
	gotoxy(x, y + 1);
	printf("게 임 정 보");
	gotoxy(x, y + 2);
	printf("   종 료  ");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 12;
		}
		}
	}
}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                       [조작방법] \n\n");
	printf("                     이동 : w,s,d,a \n");
	printf("                     선택 : spacebar\n\n\n\n\n\n");
	printf("                   developer : Gamjaman \n\n");
	printf("          스페이스바를 누르면 메인화면으로 이동합니다.");
	while (1) {
		if (keyControl() == SUBMIT)
			break;
	}
}

int maplistDraw() {
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                      [맵  선  택] \n\n");

	gotoxy(x - 2, y);
	printf("> 쉬  움");
	gotoxy(x, y+1);
	printf("어려움");
	gotoxy(x, y+2);
	printf("뒤  로");

	while (1) {
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y > 6) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (y < 9) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 6;
			}
		}
	}
}