#pragma once

#include "Window.h"

class CANIMAL
{
public:
	//CANIMAL();
	//CANIMAL(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	//CANIMAL(int speedX, int speedY);							//Đặt speed cho class con

	virtual void draw();
	virtual void speak();

	bool inContact(Point ppos);

private:
	Point pos;
	Point speed;
};
class CBird : CANIMAL
{
public:
	void draw(char s, COORD pos);
};
class CDino : CANIMAL
{
public:
	void draw(char s, COORD pos);
};