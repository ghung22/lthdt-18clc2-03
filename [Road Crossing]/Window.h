#pragma once

#include <Windows.h>

typedef COORD Point;

class Window
{
public:
	Window();

	void LockWinSize();

	void ChangeCursor(bool visible, short size = 1);
	void HideCursor();
	void ShowCursor();

	Point GotoXY(int x, int y);
	Point GetXY();
	SMALL_RECT GetConsoleSize();

	void DrawGameMenu();
	void SplitLanes();

private:
	HANDLE inputHandle, outputHandle;
	HWND window;							//pointer to console window
	CONSOLE_SCREEN_BUFFER_INFO scrBufInfo;
};