#pragma once

class moveBlock
{
public:
	char maze[30][100];
	int xpos;
	int ypos;
	int x[100];
	int y[100];
	int h = 0;

	void push(int, int);
	int popx();
	int popy();
	void gotoxy(int, int);
	moveBlock(int, int);
	void check(int,int);
	

};
