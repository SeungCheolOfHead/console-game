#include "game.h"

char map[18][60] = {
	{"11111111111111111111111111111111111111111111111111111111111"}, // 1�� �� 0�� ���� s�� ��� q�� ������
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
			if ('0' == temp) {			//��ĭ
				printf(" ");
			}
			else if ('1' == temp) {		//��
				printf("#");
			}
			else if ('s' == temp) {		//���
				printf("@");
			}
			else if ('q' == temp) {		//������
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
	printf("> �� �� �� ��");
	gotoxy(x, y + 1);
	printf("�� �� �� ��");
	gotoxy(x, y + 2);
	printf("   �� ��  ");
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
	printf("                       [���۹��] \n\n");
	printf("                     �̵� : w,s,d,a \n");
	printf("                     ���� : spacebar\n\n\n\n\n\n");
	printf("                   developer : Gamjaman \n\n");
	printf("          �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");
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
	printf("                      [��  ��  ��] \n\n");

	gotoxy(x - 2, y);
	printf("> ��  ��");
	gotoxy(x, y+1);
	printf("�����");
	gotoxy(x, y+2);
	printf("��  ��");

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