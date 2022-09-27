#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"Enemy.h"
using namespace std;

void Enemy:: gotoxy(int x, int y)
{
	COORD pos1 = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos1);
}

Enemy::Enemy(int x, int y)
{
	xpos = x;
	ypos = y;
	gotoxy(xpos, ypos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	_putch('*');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}

//void ShowConsoleCursor(bool showFlag)  // Cursor visibility
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO cursorInfo;
//	GetConsoleCursorInfo(out, &cursorInfo);
//	cursorInfo.bVisible = showFlag;
//	SetConsoleCursorInfo(out, &cursorInfo);
//}

bool Enemy::checkRight()
{

	char tempVal;
	tempVal = maze[ypos][xpos + 1];
	if (tempVal == '0')
	{
		return true;
	}
	else
	{
		Lflag = 0;
		Rflag = 1;
		return false;
	}

}

bool Enemy::checkLeft()
{

	char tempVal;
	tempVal = maze[ypos][xpos - 1];
	if (tempVal == '0')
	{
		return true;
	}
	else
	{
		Lflag = 1;
		Rflag = 0;
		return false;
		
	}

}

bool Enemy::checkDown()
{
	char tempVal = maze[ypos + 1][xpos];
	if (tempVal == '0')
	{
		return true;
	}
	else
	{
		Dflag = 1;
		Uflag = 0;
		return false;
	}
}

bool Enemy::checkUp()
{
	char tempVal = maze[ypos - 1][xpos];
	if (tempVal == '0')
	{
		return true;
	}
	else
	{
		Uflag = 1;
		Dflag = 0;
		return false;
	}
}

int Enemy::popx()
{
	h--;
	return x[h];

}

int Enemy::popy()
{
	return y[h];
}

void Enemy::push(int xvar, int yvar)
{
	if (h >= 0)
	{
		x[h] = xvar;
		y[h] = yvar;
		h++;
	}

}

void Enemy::fixMove()
{
		push(xpos, ypos);
		if (checkRight() == true && Rflag == 0)
		{
			gotoxy(xpos + 1, ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			_putch('*');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			gotoxy(xpos, ypos);
			_putch(' ');
			xpos++;
		}
		else if (checkLeft() == true && Lflag == 0)
		{
			gotoxy(xpos - 1, ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			_putch('*');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			gotoxy(xpos, ypos);
			_putch(' ');
			xpos--;
		}
	
}

void Enemy::move()
{
	push(xpos, ypos);

	
	if (checkRight() == true && Rflag == 0)
	{
		gotoxy(xpos + 1, ypos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		_putch('*');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(xpos, ypos);
		_putch(' ');
		xpos++;
	}
	else if (checkUp() == true && Uflag ==0)
	{
		gotoxy(xpos, ypos - 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		_putch('*');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(xpos, ypos);
		_putch(' ');
		ypos--;
	}
	else if (checkLeft() == true && Lflag == 0)
	{
		gotoxy(xpos - 1, ypos);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		_putch('*');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(xpos, ypos);
		_putch(' ');
		xpos--;
	}
	else if (checkDown() == true && Dflag ==0)
	{
		gotoxy(xpos, ypos + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		_putch('*');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(xpos, ypos);
		_putch(' ');
		ypos++;
	}
	


}
