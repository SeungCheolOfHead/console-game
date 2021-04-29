#pragma once
#include<windows.h>

void init();
void gotoxy(int, int);
void setColor(int, int);

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white		
};