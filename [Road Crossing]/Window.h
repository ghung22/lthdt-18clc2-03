#pragma once

#include <Windows.h>

typedef COORD Point;

void LockWinSize();
void ChangeCursor(bool visible, short size = 1);
void HideCursor();
void ShowCursor();
void HideInput();
void ShowInput();

Point GotoXY(int x, int y);
Point GetXY();