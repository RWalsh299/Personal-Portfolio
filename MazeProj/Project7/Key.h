#pragma once
class Key
{
public:
	int xpos;
	int ypos;
	void gotoxy(int, int);
	Key(int,int);
	void cover();
	void uncover(int,int);
};
