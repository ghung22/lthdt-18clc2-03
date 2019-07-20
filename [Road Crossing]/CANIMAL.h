#pragma once

#include "Window.h"

class CANIMAL
{
public:
	CANIMAL();
	CANIMAL(int y, int s_speed);		//Đặt pos và speed cho class con
	//CANIMAL(int speedX, int speedY);							//Đặt speed cho class con

	virtual void draw();
	virtual void speak();

	bool inContact(Point ppos);

private:
	Point pos;
	int speed;
};
class CBird : public CANIMAL
{
public:
	CBird();
	void draw(char s, COORD pos);
};
class CDino : public CANIMAL
{
public:
	CDino();
	void draw(char s, COORD pos);
};