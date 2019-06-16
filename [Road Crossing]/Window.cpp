#include "Window.h"
#include <Windows.h>

void LockWinSize()
{
	HWND window = GetConsoleWindow();						//pointer to console window
	LONG style = GetWindowLong(window, GWL_STYLE);			//GWL_STYLE: flag, read all properties of console window and return a LONG
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);	//~ operator: reverse all bits of a binary -> hide maximize button and resize box
	SetWindowLong(window, GWL_STYLE, style);				//SetWindowLong(): Apply settings to console window
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
}