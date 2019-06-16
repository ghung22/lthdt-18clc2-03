#pragma once

#include "CGAME.h"

class CANIMAL
{
public:
	CANIMAL();
	CANIMAL(int x, int y, int speedX = 0, int speedY = 0);		//Set position and speed of derived class
	CANIMAL(int speedX, int speedY);							//Set speed of derived class

	virtual void Move();
	virtual void Tell();

private:
	int x, y;
	Vect2D speed;
};
class CBird : CANIMAL
{
	//...
};
class CDino : CANIMAL
{
	//...
};