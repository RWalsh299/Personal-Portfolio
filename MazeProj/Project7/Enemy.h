#pragma once



class Enemy
{
public:
	char maze[30][100];
	int xpos = 0;
	int ypos = 0;
	int x[100];
	int y[100];
	int h = 0;
	int Uflag = 0;
	int Rflag = 0;
	int Lflag = 0;
	int Dflag = 0;

	
	bool checkRight();
	bool checkLeft();
	bool checkDown();
	bool checkUp();
	Enemy(int, int);
	void gotoxy(int, int);
	int popx();
	int popy();
	void push(int, int);
	void move();
	void fixMove();
	void Lvl1E();
};


