#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"Board.h"
#include"Enemy.h"
#include"Glob.h"
#include"moveBlock.h"
#include"Key.h"
using namespace std;


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void ShowConsoleCursor(bool showFlag)  // Cursor visibility
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}



void main()
{
	int m = 0, z = 0;
	bool flag = 1;
	Board B;
	char Gmaze[30][100];
	ShowConsoleCursor(false);
	system("cls");
	B.displayTitle();

		Enemy E1(1, 2);
		Enemy E2(95, 17);
		Enemy E3(1, 20);
		Enemy E4(50, 9);
		Enemy E5(96, 19);
		Enemy E6(88, 5);
		Enemy E7(8, 28);
		Enemy E8(55, 27);
		Enemy E9(50, 18);
		Enemy E10(55, 14);
		Enemy E11(91, 11);
		Key K1(38, 28);
		

		for (int j = 0; j < 30; j++)
			for (int i = 0; i <= 99; i++)
			{
				E1.maze[j][i] = B.maze[j][i];
				E2.maze[j][i] = B.maze[j][i];
				E3.maze[j][i] = B.maze[j][i];
				E4.maze[j][i] = B.maze[j][i];
				E5.maze[j][i] = B.maze[j][i];
				E6.maze[j][i] = B.maze[j][i];
				E7.maze[j][i] = B.maze[j][i];
				E8.maze[j][i] = B.maze[j][i];
				E9.maze[j][i] = B.maze[j][i];
				E10.maze[j][i] = B.maze[j][i];
				E11.maze[j][i] = B.maze[j][i];

			}
	Glob G1(5, 5);
	Glob G2(6, 11);
	Glob G3(7, 11);
	Glob G4(6, 10);
	Glob G5(34, 23);
	Glob G6(45, 26);
	Glob G7(60, 11);
	Glob G8(61, 11);
	Glob G9(61, 10);
	Glob G10(10, 10);
	moveBlock M1(25, 15);
	moveBlock M2(25, 16);
	moveBlock M3(25, 17);
	moveBlock M4(36, 8);
	moveBlock M5(36, 7);
	moveBlock M6(36, 6);
	moveBlock M7(36, 5);
	moveBlock M8(36, 4);
	moveBlock M9(36, 2);
	moveBlock M10(36, 1);

	 
	gotoxy(B.xpos, B.ypos);
	B.push(B.xpos, B.ypos);
	B.Instructions();
	gotoxy(B.xpos, B.ypos);
	_putch('@');
	K1.cover();

	while (flag == 1)
	{
		if (_kbhit() != 0)
		{
			m = _getch();
		}
		Sleep(25);
		

		E1.fixMove();
		E2.fixMove();
		E3.fixMove();
		E4.fixMove();
		E5.fixMove();
		E6.move();
		E7.fixMove();
		E8.fixMove();
		E9.fixMove();
		E10.fixMove();
		E11.fixMove();

		if (B.Oflag == 1)
		{
			B.displayTitle();
			B.Oflag--;
			Glob G1(5, 5);
			Glob G2(6, 11);
			Glob G3(7, 11);
			Glob G4(6, 10);
			Glob G5(34, 23);
			Glob G6(45, 26);
			Glob G7(60, 11);
			Glob G8(61, 11);
			Glob G9(61, 10);
			Glob G10(10, 10);
			moveBlock M1(25, 15);
			moveBlock M2(25, 16);
			moveBlock M3(25, 17);
			moveBlock M4(36, 8);
			moveBlock M5(36, 7);
			moveBlock M6(36, 6);
			moveBlock M7(36, 5);
			moveBlock M8(36, 4);
			moveBlock M9(36, 2);
			moveBlock M10(36, 1);
			Key K1(38, 28);
			K1.cover();
		}

		if (B.Bflag == 1)
		{
			B.displayTitle();
			B.Bflag--;
			Glob G1(5, 5);
			Glob G2(6, 11);
			Glob G3(7, 11);
			Glob G4(6, 10);
			Glob G5(34, 23);
			Glob G6(45, 26);
			Glob G7(60, 11);
			Glob G8(61, 11);
			Glob G9(61, 10);
			Glob G10(10, 10);
			moveBlock M1(25, 15);
			moveBlock M2(25, 16);
			moveBlock M3(25, 17);
			moveBlock M4(36, 8);
			moveBlock M5(36, 7);
			moveBlock M6(36, 6);
			moveBlock M7(36, 5);
			moveBlock M8(36, 4);
			moveBlock M9(36, 2);
			moveBlock M10(36, 1);
			Key K1(38, 28);
			K1.cover();
		}
		B.LivesNScore();

		if (m == 27)
		{
			flag = 0;
		}
		else if (m == 'f')
		{
			B.Fire(B.xpos, B.ypos);
		}
		
		else if (m == 75)//72 is up 75 left 77 right 80 down
			{
				if (B.maze[B.ypos][B.xpos - 1] != '1')
				{
					B.xpos--;
					B.globCheck(G1.xpos, G1.ypos);
					B.globCheck(G2.xpos, G2.ypos);
					B.globCheck(G3.xpos, G3.ypos);
					B.globCheck(G4.xpos, G4.ypos);
					B.globCheck(G5.xpos, G5.ypos);
					B.globCheck(G6.xpos, G6.ypos);
					B.globCheck(G7.xpos, G7.ypos);
					B.globCheck(G8.xpos, G8.ypos);
					B.globCheck(G9.xpos, G9.ypos);
					B.globCheck(G10.xpos, G10.ypos);
					gotoxy(B.xpos, B.ypos);
					_putch('@');
					gotoxy(B.xpos + 1,B.ypos);
					_putch(' ');
				}
			}
			else if (m == 77)
			{
				
				if (B.maze[B.ypos][B.xpos+1] != '1')
				{
					B.xpos++;
					B.globCheck(G1.xpos, G1.ypos);
					B.globCheck(G2.xpos, G2.ypos);
					B.globCheck(G3.xpos, G3.ypos);
					B.globCheck(G4.xpos, G4.ypos);
					B.globCheck(G5.xpos, G5.ypos);
					B.globCheck(G6.xpos, G6.ypos);
					B.globCheck(G7.xpos, G7.ypos);
					B.globCheck(G8.xpos, G8.ypos);
					B.globCheck(G9.xpos, G9.ypos);
					B.globCheck(G10.xpos, G10.ypos);
					gotoxy(B.xpos, B.ypos);
					_putch('@');
					gotoxy(B.xpos-1, B.ypos);
					_putch(' ');
				}
				
			}
			else if (m == 80)
			{
				if (B.maze[B.ypos + 1][B.xpos] != '1')
				{
					B.ypos++;
					B.globCheck(G1.xpos, G1.ypos);
					B.globCheck(G2.xpos, G2.ypos);
					B.globCheck(G3.xpos, G3.ypos);
					B.globCheck(G4.xpos, G4.ypos);
					B.globCheck(G5.xpos, G5.ypos);
					B.globCheck(G6.xpos, G6.ypos);
					B.globCheck(G7.xpos, G7.ypos);
					B.globCheck(G8.xpos, G8.ypos);
					B.globCheck(G9.xpos, G9.ypos);
					B.globCheck(G10.xpos, G10.ypos);
					gotoxy(B.xpos, B.ypos);
					_putch('@');
					gotoxy(B.xpos, B.ypos - 1);
					_putch(' ');
				}
			}

			else if (m == 72)
			{
				if (B.maze[B.ypos - 1][B.xpos] != '1')
				{
					B.ypos--;
					B.globCheck(G1.xpos, G1.ypos);
					B.globCheck(G2.xpos, G2.ypos);
					B.globCheck(G3.xpos, G3.ypos);
					B.globCheck(G4.xpos, G4.ypos);
					B.globCheck(G5.xpos, G5.ypos);
					B.globCheck(G6.xpos, G6.ypos);
					B.globCheck(G7.xpos, G7.ypos);
					B.globCheck(G8.xpos, G8.ypos);
					B.globCheck(G9.xpos, G9.ypos);
					B.globCheck(G10.xpos, G10.ypos);
					gotoxy(B.xpos, B.ypos);
					_putch('@');
					gotoxy(B.xpos, B.ypos + 1);
					_putch(' ');
				}
			}
		
		gotoxy(B.xpos, B.ypos);
		B.push(B.xpos, B.ypos);
		B.enemyCheck(E1.xpos, E1.ypos);
		B.enemyCheck(E2.xpos, E2.ypos);
		B.enemyCheck(E3.xpos, E3.ypos);
		B.enemyCheck(E4.xpos, E4.ypos);
		B.enemyCheck(E5.xpos, E5.ypos);
		B.enemyCheck(E6.xpos, E6.ypos);
		B.enemyCheck(E7.xpos, E7.ypos);
		B.enemyCheck(E8.xpos, E8.ypos);
		B.enemyCheck(E9.xpos, E9.ypos);
		B.enemyCheck(E10.xpos, E10.ypos);
		B.enemyCheck(E11.xpos, E11.ypos);
		M1.check(B.xpos, B.ypos);
		M2.check(B.xpos, B.ypos);
		M3.check(B.xpos, B.ypos);
		M4.check(B.xpos, B.ypos);
		M5.check(B.xpos, B.ypos);
		M6.check(B.xpos, B.ypos);
		M7.check(B.xpos, B.ypos);
		M8.check(B.xpos, B.ypos);
		M9.check(B.xpos, B.ypos);
		M10.check(B.xpos, B.ypos);
		B.beatLevel(B.xpos, B.ypos);
		K1.uncover(B.xpos, B.ypos);
		B.gameOver();
		m = 0;
	}
	
}

