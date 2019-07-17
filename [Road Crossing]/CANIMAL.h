#pragma once

#include "Window.h"

class CANIMAL
{
public:
	//CANIMAL();
	//CANIMAL(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	//CANIMAL(int speedX, int speedY);							//Đặt speed cho class con

	//virtual void Move();
	//virtual void Tell();

	bool inContact(Point ppos);

private:
	Point pos;
	Point speed;
};
class CBird : CANIMAL
{
	//...
};
class CDino : CANIMAL
{
	//...
};