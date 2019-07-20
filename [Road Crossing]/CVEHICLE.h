#pragma once

#include "Window.h"

class CVEHICLE
{
public:
	CVEHICLE();
	CVEHICLE(int y, int s_speed);		//Đặt pos và speed cho class con
	//CVEHICLE(int speedX, int speedY);							//Đặt speed cho class con

	virtual void draw();

	bool inContact(Point ppos);

protected:
	Point pos;
	int speed;
};
class CTruck : public CVEHICLE
{
public:
	CTruck();
	void draw(char s, COORD pos);
};
class CCar : public CVEHICLE
{
public:
	CCar();
	void draw(char s, COORD pos);
};