#pragma once

#include <Windows.h>

struct Point //2D vector
{
	int x, y;
};

void LockWinSize();
void ChangeCursor(bool visible, short size = 1);
void HideCursor();
void ShowCursor();

COORD GotoXY(int x, int y);
COORD GetXY();