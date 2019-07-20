#pragma once

#include "Window.h"

class CANIMAL
{
public:
	//CANIMAL();
	//CANIMAL(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	//CANIMAL(int speedX, int speedY);							//Đặt speed cho class con

	//virtual void draw(Point pos, bool erase = false);
	virtual void speak();

	bool inContact(Point ppos);

private:
	Point pos;
	int speed;
};
class CBird : CANIMAL
{
public:
	void draw(Point pos, bool erase = false);
};
class CDino : CANIMAL
{
public:
	void draw(Point pos, bool erase = false);
};