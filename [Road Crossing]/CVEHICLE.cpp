﻿#include "CVEHICLE.h"

bool CVEHICLE::inContact(Vect2D ppos)
{
	return pos.x <= ppos.x && ppos.x <= pos.x + 2
		&& pos.y == ppos.y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của vehicle
}