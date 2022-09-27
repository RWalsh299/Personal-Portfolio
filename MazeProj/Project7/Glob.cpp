#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"Glob.h"
using namespace std;

void Glob::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

Glob::Glob(int xvar,int yvar)
{
	xpos = xvar;
	ypos = yvar;
	gotoxy(xpos, ypos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	_putch('.');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

}

void Glob::check(int x, int y)
{
	

}


