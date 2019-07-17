#pragma once

#include "Window.h"

class CVEHICLE
{
public:
	//CVEHICLE();
	//CVEHICLE(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	//CVEHICLE(int speedX, int speedY);							//Đặt speed cho class con

	//virtual void Move();

	bool inContact(Point ppos);

private:
	Point pos;
	Point speed;
};
class CTruck : public CVEHICLE
{
public:
	void draw(char s, COORD pos);
};
class CCar : public CVEHICLE
{
public:
	void draw(char s, COORD pos);
};