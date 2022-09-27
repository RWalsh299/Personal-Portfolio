#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"moveBlock.h"
using namespace std;

void moveBlock::gotoxy(int x, int y)
{
	COORD pos1 = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos1);
}
int moveBlock::popx()
{
	h--;
	return x[h];

}

int moveBlock::popy()
{
	return y[h];
}

void moveBlock::push(int xvar, int yvar)
{
	if (h >= 0)
	{
		x[h] = xvar;
		y[h] = yvar;
		h++;
	}

}

moveBlock::moveBlock(int x, int y)
{
	xpos = x;
	ypos = y;
	push(x, y);
	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	_putch(35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}

void moveBlock::check(int x,int y)
{
	if (xpos == x && ypos == y)
	{
		++xpos;
		gotoxy(xpos, ypos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		_putch(35);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		push(xpos, ypos);
	}
	

}

