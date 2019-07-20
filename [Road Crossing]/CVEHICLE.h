#pragma once

#include "Window.h"

class CVEHICLE
{
public:
	//CVEHICLE();
	//CVEHICLE(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	//CVEHICLE(int speedX, int speedY);							//Đặt speed cho class con

	//virtual void draw(Point pos, bool erase = false);

	bool inContact(Point ppos);

private:
	Point pos;
	int speed;
};
class CTruck : public CVEHICLE
{
public:
	void draw(Point pos, bool erase = false);
};
class CCar : public CVEHICLE
{
public:
	void draw(Point pos, bool erase = false);
};