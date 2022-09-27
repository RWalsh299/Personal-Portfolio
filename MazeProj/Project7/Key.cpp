#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include"Key.h"
using namespace std;

void Key::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

 Key::Key(int x, int y)
{
	 xpos = x;
	 ypos = y;
	 gotoxy(x, y);
	 _putch(143);

}

 void Key::cover()
 {
	 gotoxy(84, 21);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	 putchar(219);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
 }

 void Key::uncover(int x, int y)
 {
	 if (x == xpos && y == ypos)
	 {
		 gotoxy(84, 21);
		 _putch(' ');
	 }
 }
