#include "Window.h"

void LockWinSize()
{
	HWND window = GetConsoleWindow();						//pointer to console window

	//Lock the size
	LONG style = GetWindowLong(window, GWL_STYLE);			//GWL_STYLE: flag, read all properties of console window and return a LONG
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);	//~ operator: reverse all bits of a binary -> hide maximize button and resize box
	SetWindowLong(window, GWL_STYLE, style);				//SetWindowLong(): Apply settings to console window

	//Set the size
	ShowScrollBar(window, SB_BOTH, false);
}
void ChangeCursor(bool visible, short size)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = size;
	info.bVisible = visible;
	SetConsoleCursorInfo(console, &info);
}
void HideCursor() { ChangeCursor(false); }
void ShowCursor() { ChangeCursor(true); }

COORD GotoXY(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);		//get console handle
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(console, &cbsi);
	while (x > cbsi.srWindow.Right)
	{
		x -= cbsi.srWindow.Right;							//Chuyển về phía bên kia màn hình nếu ra ngoài
		y++;
	}

	COORD coord = { x, y };
	SetConsoleCursorPosition(console, coord);				//Dời con trỏ đến toạ độ coord trên "console"
	return coord;
}

COORD GetXY()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(console, &cbsi))
		return cbsi.dwCursorPosition;
	else
	{
		COORD error = { 0, 0 };
		return error;
	}
}