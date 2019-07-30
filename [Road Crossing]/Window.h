#pragma once

#include <Windows.h>

typedef COORD Point;

class Window
{
public:
	Window();

	void LockWinSize(); //Khoá thay đổi size màn hình

	void ChangeCursor(bool visible, short size = 1);
	void HideCursor();
	void ShowCursor();

	Point GotoXY(short x, short y);
	Point GetXY();
	SMALL_RECT GetConsoleSize();

	void DrawGameMenu(); //Vẽ khung thông tin trên đầu
	void SplitLanes(); //Chia làn

private:
	HANDLE inputHandle, outputHandle;
	HWND window;							//pointer to console window
	CONSOLE_SCREEN_BUFFER_INFO scrBufInfo;
};