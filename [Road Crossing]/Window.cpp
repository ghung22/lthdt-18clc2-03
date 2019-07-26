#include "Window.h"

Window::Window()
{
	inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	window = GetConsoleWindow();
	GetConsoleScreenBufferInfo(outputHandle, &scrBufInfo);
}

void Window::LockWinSize()
{
	//Lock the size
	LONG style = GetWindowLong(window, GWL_STYLE);			//GWL_STYLE: flag, read all properties of console window and return a LONG
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);	//~ operator: reverse all bits of a binary -> hide maximize button and resize box
	SetWindowLong(window, GWL_STYLE, style);				//SetWindowLong(): Apply settings to console window

	ShowScrollBar(window, SB_BOTH, false);					//Hide scroll bar
}

void Window::ChangeCursor(bool visible, short size)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = size;
	curInfo.bVisible = visible;
	SetConsoleCursorInfo(outputHandle, &curInfo);
}
void Window::HideCursor() { ChangeCursor(false); }
void Window::ShowCursor() { ChangeCursor(true); }

Point Window::GotoXY(int x, int y)
{
	GetConsoleScreenBufferInfo(outputHandle, &scrBufInfo);
	while (x > scrBufInfo.srWindow.Right)
		x -= scrBufInfo.srWindow.Right;						//Chuyển về phía bên kia màn hình nếu ra ngoài
	while (y > scrBufInfo.srWindow.Bottom)
		y -= scrBufInfo.srWindow.Bottom;

	Point p = { x, y };
	SetConsoleCursorPosition(outputHandle, p);				//Dời con trỏ đến toạ độ coord trên "console"
	return p;
}
Point Window::GetXY()
{
	GetConsoleScreenBufferInfo(outputHandle, &scrBufInfo);
	return scrBufInfo.dwCursorPosition;
}
SMALL_RECT Window::GetConsoleSize()
{
	return scrBufInfo.srWindow;
}