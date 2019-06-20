#pragma once

#include "CGAME.h"

class CVEHICLE
{
public:
	CVEHICLE();
	CVEHICLE(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	CVEHICLE(int speedX, int speedY);							//Đặt speed cho class con

	virtual void Move();

	bool inContact(Vect2D ppos);

private:
	Vect2D pos;
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