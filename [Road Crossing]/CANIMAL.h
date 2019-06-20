#pragma once

#include "CGAME.h"

class CANIMAL
{
public:
	CANIMAL();
	CANIMAL(int x, int y, int speedX = 0, int speedY = 0);		//Đặt pos và speed cho class con
	CANIMAL(int speedX, int speedY);							//Đặt speed cho class con

	virtual void Move();
	virtual void Tell();

	bool inContact(Vect2D ppos);

private:
	Vect2D pos;
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