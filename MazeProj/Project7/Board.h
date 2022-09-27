#pragma once

class Board
{
public:
	void openfile(int);
	char maze[30][100];
	void LivesNScore();
	void globCheck(int, int);
	void Fire(int, int);
	//bool checkGlob(int, int);
	//bool checkRight(int, int);
	void enemyCheck(int, int);
	void gameOver();
	void displayTitle();
	void gotoxy(int, int);
	void beatLevel(int,int);
	void Instructions();

	int x[100] = { 0 };
	int y[100] = { 0 };
	int h = 0;
	void push(int, int);
	int popx();
	int popy();
	int Oflag = 0;
	int Bflag = 0;
	int level = 0;
	int lives = 3;
	int score = 0;
	int xpos = 1;
	int ypos = 1;
};
