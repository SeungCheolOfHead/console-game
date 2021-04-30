#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "util.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

enum Information
{
	START_GAME = 0,
	HELP_GAME = 1,
	EXIT_GAME = 2,
};

enum Level
{
	EASY = 0,
	HARD = 1,
};

int keyControl();
int menuDraw();
int maplistDraw();
void titleDraw();
void infoDraw();
void drawMap(int*, int*);
void gLoop(int);
void move(int*, int*, int, int, int*, int*);
void drawUI(int*, int*, int*);