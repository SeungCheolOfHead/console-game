#include "game.h"
#include "util.h"

char tempMap[18][61];

char map1[18][61] = {
	{"111111111111111111111111111111111111111111111111111111111111"}, // 1은 벽 0은 공백 s는 사람 q는 도착점
	{"1k10l010001k10001000000000000000101kkkkk0000lll0100000000001"},
	{"101010101010101010111111111111101011111111111110101111111101"},
	{"101010101010101010100000000000001000000000000000101000000001"},
	{"101010101k10101010101111111111111011111111111111101011111111"},
	{"101010101110101010100000000000000000000000000000001000000001"},
	{"1000101010l0001010111111111111111111111111111111111111111101"},
	{"101110001011111010100000000000001000000000000000000000000001"},
	{"100010000010000010101011111111100101111111111111111111111001"},
	{"111011111110111110101011111111110101000100010000100010000001"},
	{"100010000000101000101000000000000100010001000100001k1l111111"},
	{"10111011111ll01010101111111111111111111111111111111110000001"},
	{"1000100000001010101l000000000k1000000000000000000000001111l1"},
	{"1110101111101010101l11111111111l1111111111111111111111000001"},
	{"1000100000101010101000000000001l00000000000000000000k00000l1"},
	{"10s011111110101010111111111110111111111111111111111111111101"},
	{"10001kk0000l1000100k0000000000lll0000000000000000000000000q1"},
	{"111111111111111111111111111111111111111111111111111111111111"}
};

char map2[18][61] = {
	{"111111111111111111111111111111111111111111111111111111111111"}, // 1은 벽 0은 공백 s는 사람 q는 도착점
	{"100000000000000000000000000000000000000000000000000000000001"},
	{"100000000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"10s010000000000000000000000000000000000000000000000000q00001"},
	{"100010000000000000000000000000000000000000000000000000000001"},
	{"111111111111111111111111111111111111111111111111111111111111"}
};

void drawMap(int* x, int* y) {
	system("cls");

	for (int h = 0; h < 18; h++) {
		for (int w = 0; w < 61; w++) {
			char temp = tempMap[h][w];
			if ('0' == temp) {			//빈칸
				setColor(black, black);
				printf(" ");
			}
			else if ('1' == temp) {		//벽
				setColor(white, white);
				printf("#");
			}
			else if ('s' == temp) {		//사람
				*x = w;
				*y = h;
				setColor(cyan, black);
				printf("@");
			}
			else if ('q' == temp) {		//도착점
				setColor(lightgreen, black);
				printf("O");
			}
			else if ('k' == temp) {		//키
				setColor(yellow, black);
				printf("*");
			}
			else if ('l' == temp) {		//열쇠가 필요한 문
				setColor(red, black);
				printf("+");
			}
		}
		printf("\n");
	}
	setColor(white, black);
}

void gLoop(int mapCode)
{
	int key = 0;
	int x, y;
	int playing = 1;
	if (0 == mapCode) {
		memcpy(tempMap, map1, sizeof(tempMap));
	}
	else if (1 == mapCode) {
		memcpy(tempMap, map2, sizeof(tempMap));
	}

	drawMap(&x,&y);
	while (playing) {
		drawUI(&x, &y, &key);
		switch (keyControl()) {
			case UP:
				move(&x, &y, 0, -1, &key, &playing);
				break;
			case DOWN:
				move(&x, &y, 0, 1, &key, &playing);
				break;
			case LEFT:
				move(&x, &y, -1, 0, &key, &playing);
				break;
			case RIGHT:
				move(&x, &y, 1, 0, &key, &playing);
				break;
			case SUBMIT:
				playing = 0;
		}
	}
	gotoxy(25, 10);
	printf("이걸 깨?");
	Sleep(2500);
}

void move(int* x, int* y, int _x, int _y, int* key, int* playing)
{
	char mapObject = tempMap[*y + _y][*x + _x];
	setColor(white, black);
	if ('0' == mapObject) {
		gotoxy(*x, *y);
		printf(" ");
		gotoxy(*x + _x, *y + _y);
		setColor(cyan, black);
		printf("@");
		*x += _x;
		*y += _y;
	}
	else if ('k' == mapObject) {
		tempMap[*y + _y][*x + _x] = '0';
		gotoxy(*x, *y);
		printf(" ");
		gotoxy(*x + _x, *y + _y);
		setColor(cyan, black);
		printf("@");
		*key += 1;
		*x += _x;
		*y += _y;
	}
	else if ('l' == mapObject) {
		if (*key > 0) {
			*key -= 1;
			tempMap[*y + _y][*x + _x] = '0';
			gotoxy(*x + _x, *y + _y);
			setColor(white, black);
			printf(" ");
			move(x, y, _x, _y, key, playing);
		}
	}
	else if ('q' == mapObject)
		*playing = 0;
}

void drawUI(int* x, int* y, int* key)
{
	setColor(white, black);
	gotoxy(3, 19);
	printf("위치 : %02d, %02d", *x, *y);

	setColor(yellow, black);
	gotoxy(40, 19);
	printf("열쇠 : %d개", *key);
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