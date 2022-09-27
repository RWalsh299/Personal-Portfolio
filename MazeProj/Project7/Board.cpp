#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"Board.h"
using namespace std;

void Board:: gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void Board::Fire(int x, int y)
{
	gotoxy(x + 1, y);
	_putch('*');
	gotoxy(x + 2, y);
	_putch('*');
	gotoxy(x + 3, y);
	_putch('*');
	gotoxy(x + 1, y);
	_putch(' ');
	gotoxy(x + 2, y);
	_putch(' ');
	gotoxy(x + 3, y);
	_putch(' ');
}

void Board::enemyCheck(int x, int y)
{

	
	if ( x == xpos && y == ypos)
	{
		lives--;
		
		while (h != 1)
		{
			xpos = popx();
			ypos = popy();
		}
		gotoxy(xpos, ypos);
		_putch('@');
	}

}



void Board::gameOver()
{
	if (lives == 0)
	{
		system("cls");
		gotoxy(50, 15);
		cout << "GAME OVER MAN" << endl;
		gotoxy(50, 16);
		cout << "final score: " << score << endl;
		system("pause");
		Oflag++;
		system("cls");
		lives = lives + 3;
	}
	
}


int Board::popx()
{
	h--;
	return x[h];

}

int Board::popy()
{
	return y[h];
}

void Board::push(int xvar, int yvar)
{
	if (h >= 0)
	{
		x[h] = xvar;
		y[h] = yvar;
		h++;
	}

}

void Board::Instructions()
{
	
	
	gotoxy(110, 9);
	cout << "Instructions:";
	gotoxy(110, 10);
	cout << "@ = Player";
	gotoxy(110, 11);
	cout << "* = Enemy";
	gotoxy(110, 12);
	cout << ". = Globs";
	gotoxy(110, 13);
	cout << "# = Moveable blocks";
	gotoxy(110, 14);
	cout << "Objective is to reach the end and collect globs!";
	gotoxy(110, 15);
	cout << "Must collect the Key (?) to unlock the exit!";
}

void Board::globCheck(int xvar, int yvar)
{
	int flag = 0;
	/*if (maze[yvar][xvar] == '3')
	{
		for (int i = 0; i < h; i++)
		{
			if (xvar == x[i] || yvar == y[i])
				return false;
			else
				return true;
		}
	}*/
	if (xvar == xpos && yvar == ypos)
	{
		flag++;
	}
	
	for (int i = 0; i < h; i++)
	{
		if (xpos == x[i] && ypos == y[i])
		{
			flag--;
		}
	}
	if (flag == 1)
	{
		score++;
	}
	
}

void Board::displayTitle()
{
	cout << "*******************************************************************************************************************************************  " << endl;
	cout << "*                                __________          __                  ______________      _____________                                  *" << endl;
	cout << "*                               |  ________|        |  |                |   ________   |    |   _______   |                                 *" << endl;
	cout << "*                               |  |                |  |                |  |        |  |    |  |       |   |                                *" << endl;
	cout << "*                               |  |                |  |                |  |        |  |    |  |        |  |                                *" << endl;
	cout << "*                               |  |   _________    |  |                |  |        |  |    |  |________|  |                                *" << endl;
	cout << "*                               |  |  |______  |    |  |                |  |        |  |    |  |        |  |                                *" << endl;
	cout << "*                               |  |        |  |    |  |                |  |        |  |    |  |        |  |                                *" << endl;
	cout << "*                               |  |________|  |    |  |___________     |  |________|  |    |  |_______|   |                                *" << endl;
	cout << "*                               |______________|    |______________|    |______________|    |_____________|                                 *" << endl;
	cout << "*                                                                                                                                           *" << endl;
	cout << "*  __________          ______________       ______________      ______________      __                  ______________      ___________     *" << endl;
	cout << "* |  ________|        |   ________   |     |   ________   |    |   _______    |    |  |                |              |    |   _______  |   *" << endl;
	cout << "* |  |                |  |        |  |     |  |        |  |    |  |       |   |    |  |                |     _________|    |  |       |  |  *" << endl;
	cout << "* |  |                |  |        |  |     |  |        |  |    |  |        |  |    |  |                |    |_________     |  |       |  |  *" << endl;
	cout << "* |  |   _________    |  |        |  |     |  |        |  |    |  |________|  |    |  |                |              |    |  |_______|  |  *" << endl;
	cout << "* |  |  |______  |    |  |        |  |     |  |        |  |    |  |        |  |    |  |                |     _________|    |  |______   |   *" << endl;
	cout << "* |  |        |  |    |  |        |  |     |  |        |  |    |  |        |  |    |  |                |    |_________     |  |      |  |   *" << endl;
	cout << "* |  |________|  |    |  |________|  |     |  |________|  |    |  |_______|   |    |  |___________     |              |    |  |       |  |  *" << endl;
	cout << "* |______________|    |______________|     |______________|    |______________|    |______________|    |______________|    |__|        |__| *" << endl;
	cout << "*                                                                                                                                           *" << endl;
	cout << " *******************************************************************************************************************************************" << endl;
	cout << endl;
	cout << "                                                       ********************************                                                      " << endl;
	cout << "                                                      *     Enter # of Difficulty      *                                                     " << endl;
	cout << "                                                      *        1. Easy                 *                                                     " << endl;
	cout << "                                                      *        2. Medium               *                                                     " << endl;
	cout << "                                                      *        3. Hard                 *                                                     " << endl;
	cout << "                                                      *        ESC = EXIT              *                                                     " << endl;
	cout << "                                                       ********************************                                                      " << endl;
	
	cin >> level;
	system("pause");
	system("CLS");
	switch (level)
	{
	case 1: openfile(level);
		break;
	case 2: openfile(level);
		break;
	case 3: openfile(level);
		break;
	}
}


void Board::LivesNScore()
{
	gotoxy(110, 17);
	cout << "Lives: " << lives;
	gotoxy(110, 18);
	cout << "Score: " << score << endl;
}

void Board::beatLevel(int x, int y)
{
	
	char temp;
	temp = maze[y][x];
	if (temp == '5' )
	{
		system("cls");
		gotoxy(50, 15);
		cout << "CONGRATS YOU BEAT THE LEVEL" << endl;
		gotoxy(50, 16);
		cout << "final score: " << score;
		system("pause");
		Bflag++;
		system("cls");
		xpos = 1;
		ypos = 1;
	}
}

void Board::openfile(int level)
{
	ifstream fname;
	if (level == 2)
	{
		fname.open("mazefile.txt");
	}
	else if (level == 1)
	{
		fname.open("mazefilelevel2.txt");
	}
	if (fname.is_open())
	{
		for (int j = 0; j < 30; j++)
			for (int i = 0; i <= 99; i++)
			{
				fname >> maze[j][i];

			}

		for (int j = 0; j < 30; j++)
		{
			for (int i = 0; i <= 99; i++)
			{
				if (maze[j][i] == '1')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					putchar(219);
				}
				else if (maze[j][i] == '0')
					_putch(' ');
				else if (maze[j][i] == '3')
				{
					
					_putch(' ');
				}
				else if (maze[j][i] == '*')
				{
					
					_putch(' ');
				}

				else if (maze[j][i] == '2')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					_putch(64);
				}

			}
			cout << endl;
		}
		fname.close();
		
	}

}