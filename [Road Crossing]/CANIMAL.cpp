﻿#include "CANIMAL.h"

bool CANIMAL::inContact(Point ppos)
{
	return pos.x <= ppos.x && ppos.x <= pos.x + 2
		&& pos.y == ppos.y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của animal
}