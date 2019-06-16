#pragma once

#include "CGAME.h"

class CVEHICLE
{
public:
	CVEHICLE();
	CVEHICLE(int x, int y, int speedX = 0, int speedY = 0);		//Set position and speed of derived class
	CVEHICLE(int speedX, int speedY);							//Set speed of derived class

	virtual void Move();

private:
	int x, y;
	Vect2D speed;
};
class CTruck : public CVEHICLE
{
	//...
};
class CCar : public CVEHICLE
{
	//...
};