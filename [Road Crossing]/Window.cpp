#include "Window.h"

#include <iostream>
using namespace std;

Window::Window()
{
	inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	window = GetConsoleWindow();
	GetConsoleScreenBufferInfo(outputHandle, &scrBufInfo);
}

void Window::LockWinSize()
{
	//Set default size
	system("MODE CON LINES=50");

	//Put window in middle of screen
	RECT rectWindow;
	GetWindowRect(window, &rectWindow);
	int newX, newY;
	newX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	newY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	MoveWindow(window, newX, newY, rectWindow.right - rectWindow.left, rectWindow.bottom - rectWindow.top, true);

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

Point Window::GotoXY(short x, short y)
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

void Window::DrawGameMenu()
{
	GotoXY(0, 0);
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			cout << char(201);	//╔
		else if (i == 5)
			cout << char(200);	//╚
		else
			cout << char(186);	//║

		for (int ii = 0; ii < scrBufInfo.srWindow.Right - 2; ii++)
			if (i == 0 || i == 5)
				cout << char(205);	//═
			else
				cout << ' ';

		if (i == 0)
			cout << char(187) << endl;	//╗
		else if (i == 5)
			cout << char(188) << endl;	//╝
		else
			cout << char(186) << endl;	//║
	}
}
void Window::SplitLanes()
{
	DrawGameMenu();
	for (int i = 2; i < 10; i++)
	{
		GotoXY(0, i * 5);
		for (int ii = 0; ii < scrBufInfo.srWindow.Right; ii++)
			cout << '_';
	}
}