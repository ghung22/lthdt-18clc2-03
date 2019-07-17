#pragma once

#include <Windows.h>

struct Point //2D vector
{
	int x, y;
};

void LockWinSize();
COORD GotoXY(int x, int y);
COORD GetXY();