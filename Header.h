#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#include <fstream>
#include <future>
#include <mmsystem.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

using namespace std;

// Game start something
bool GAME_START = false;

// Status of key stroke
enum status { UP, DOWN, LEFT, RIGHT, ENTER, ESC };

// Console and Board size
#define consoleWidth 120
#define consoleHeight 30
#define boardWidth 90
#define boardHeight 29


// Text color
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7

//------------

// Function declarations
void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int color);
void DrawBoard();
void arrow(int option, int current);
void setTextAttribute(const int& k);
void draw_border(int x, int y, int width, int height, int color, string textinbutton);
void Nocursortype();
void CROSSING(const int& color);
void HELL(const int& color);
void playGame();
int ShowMenu(const vector<string>& tit, const int& x0, const int& y0, const int& height, const int& width, const int& color1, const int& color2);

// Function implementations
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


//---------------------
//This is to draw the board
void DrawBoard()
{
	int x_coord = 1;
	int y_coord = 1;
	GotoXY(x_coord, y_coord);
	int laneWidth = 6;

	// Horizontal lines											// ==========================
	TextColor(ColorCode_Red);									// |                        |
	for (int i = 0; i < boardWidth; i++)						// |                        |
		cout << '=';											// |						|
	TextColor(default_ColorCode);								// |------------------------|
	int y_coord_lanes = y_coord;								// |                        |			
	for (int i = 0; i < 4; i++)									// |                        |
	{															// |                        |
		y_coord_lanes += laneWidth;								// |------------------------|
		GotoXY(x_coord + 1, y_coord_lanes);						// |                        |
		for (int j = 0; j < boardWidth - 1; j++)				//             ...
			cout << '-';
	}
	//y_coord_lanes increase laneWidth*4
	GotoXY(x_coord, y_coord_lanes + laneWidth - 1);
	TextColor(ColorCode_Red);
	for (int i = 0; i < boardWidth; i++)
		cout << '=';


	// Vertical lines
	TextColor(ColorCode_Red);
	for (int i = 0; i < boardHeight - 1; i++)
	{
		GotoXY(x_coord, ++y_coord);
		cout << char(219);
	}
	y_coord = 1;
	for (int i = 0; i < boardHeight - 1; i++)
	{
		GotoXY(boardWidth, ++y_coord);
		cout << char(219);
	}

	setTextAttribute(ColorCode_Grey);

	/*GotoXY(1, 1);
	std::cout << R"abcd(
	===================================================================
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|                                                                 |
	|=================================================================|
	)abcd";*/
}

//---------
//This whole shit is to draw the menu

void setTextAttribute(const int& k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void draw_border(int x, int y, int width, int height, int color, string textinbutton)
{
	setTextAttribute(color);
	GotoXY(x - width, y - width);
	cout << char(218);	//  ┌

	for (int i = 0; i < height; i++)
		cout << char(196);	//  ─
	cout << char(191);	//  ┐

	for (int i = 1 - width; i <= width - 1; i++)
	{
		GotoXY(x - width, y + i);
		cout << char(179);	//  │ 
	}

	GotoXY(x - width, y + width);
	cout << char(192);

	for (int i = 0; i < height; i++)
		cout << char(196);	//  ─
	cout << char(217);	//  ┘

	for (int i = 1 - width; i <= width - 1; i++)
	{
		GotoXY(x + height + 1 - width, y + i);
		cout << char(179);	//  │ 
	}

	int center = (height - textinbutton.length()) / 2;
	GotoXY(x + center, y);
	cout << textinbutton;
}

status key(char a)
{
	if (a == -32 || a == 224)
	{
		a = _getch();
		switch (a)
		{
		case 72:return UP;
		case 75:return LEFT;
		case 77:return RIGHT;
		case 80:return DOWN;
		}
	}
	if (a == 13)
		return ENTER;
	return ESC;
}

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void CROSSING(const int& color) {
	GotoXY(0, 0);
	setTextAttribute(color);
	cout <<
		R"(    /$$$$$$ /$$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$ /$$$$$$/$$   /$$ /$$$$$$ 
   /$$__  $| $$__  $$/$$__  $$/$$__  $$/$$__  $|_  $$_| $$$ | $$/$$__  $$
  | $$  \__| $$  \ $| $$  \ $| $$  \__| $$  \__/ | $$ | $$$$| $| $$  \__/
  | $$     | $$$$$$$| $$  | $|  $$$$$$|  $$$$$$  | $$ | $$ $$ $| $$ /$$$$
  | $$     | $$__  $| $$  | $$\____  $$\____  $$ | $$ | $$  $$$| $$|_  $$
  | $$    $| $$  \ $| $$  | $$/$$  \ $$/$$  \ $$ | $$ | $$\  $$| $$  \ $$
  |  $$$$$$| $$  | $|  $$$$$$|  $$$$$$|  $$$$$$//$$$$$| $$ \  $|  $$$$$$/
   \______/|__/  |__/\______/ \______/ \______/|______|__/  \__/\______/ )";
	setTextAttribute(ColorCode_DarkWhite);
}

void HELL(const int& color) {
	setTextAttribute(color);
	int y = 8;
	GotoXY(18, y);
	cout << "   /$$   /$$ /$$$$$$ / $$      /$$      " << endl;
	y++;
	GotoXY(18, y);
	cout << "  | $$  | $$| $$     | $$     | $$  " << endl;
	y++;
	GotoXY(18, y);
	cout << "  | $$  | $$| $$     | $$     | $$  " << endl;
	y++;
	GotoXY(18, y);
	cout << "  | $$$$$$$$| $$$$$  | $$     | $$     " << endl;
	y++;
	GotoXY(18, y);
	cout << "  | $$  | $$| $$     | $$     | $$  " << endl;
	y++;
	GotoXY(18, y);
	cout << "  | $$__  $$| $$__/  | $$     | $$      ";
	y++;
	GotoXY(18, y);
	cout << "  | $$  | $$| $$$$$$ | $$$$$$ | $$$$$$";
	y++;
	GotoXY(18, y);
	cout << "  |__/  |__/|_______/|_______/|_______/";
	setTextAttribute(ColorCode_DarkWhite);
}

int ShowMenu(const vector<string>& tit, const int& x0, const int& y0, const int& height, const int& width, const int& color1, const int& color2) {
	int n = tit.size();

	int pos = y0;
	draw_border(x0, y0, height, width, color1, tit[0]);
	pos += 2;

	for (int i = 1; i < n; i++)
	{
		draw_border(x0, pos, height, width, color2, tit[i]);
		pos += 2;
	}

	pos = y0;
	int ymax = y0 + 2 * (n - 1);

	while (1) {
		char c = _getch();
		int state = key(c);
		if (state == DOWN || state == RIGHT) {
			if (pos < ymax)
			{
				draw_border(x0, pos, height, width, color2, tit[pos / 2 - y0 / 2]);
				pos += 2;
				draw_border(x0, pos, height, width, color1, tit[pos / 2 - y0 / 2]);
			}
			else {
				draw_border(x0, pos, height, width, color2, tit[n - 1]);
				pos = y0;
				draw_border(x0, pos, height, width, color1, tit[0]);
			}
		}
		else if (state == UP || state == LEFT)
		{
			if (pos > y0)
			{
				draw_border(x0, pos, height, width, color2, tit[pos / 2 - y0 / 2]);
				pos -= 2;
				draw_border(x0, pos, height, width, color1, tit[pos / 2 - y0 / 2]);
			}
			else {
				draw_border(x0, pos, height, width, color2, tit[0]);
				pos = ymax;
				draw_border(x0, pos, height, width, color1, tit[n - 1]);
			}
		}
		else if (state == ENTER)
		{
			setTextAttribute(ColorCode_Grey);
			return (pos - y0) / 2;
		}
	}
}

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}


// Shapes
//Birds
char bird_shape_forward[3][3] = { { char(187), ' ', ' ' },{ char(219), 'o', '>' },{ char(188), ' ', ' ' } };
char bird_shape_backward[3][3] = { { ' ', ' ', char(187) },{ '<', 'o', char(219) },{ ' ', ' ', char(188) } };
//Dinos

void arrow(int option, int current)
{
	if (option == current)
		printf("==========>   ");
	else
		printf("              ");
}

bool ChangeVolume(double nVolume, bool bScalar)
{
	HRESULT hr = NULL;
	bool decibels = false;
	bool scalar = false;
	double newVolume = nVolume;

	CoInitialize(NULL);
	IMMDeviceEnumerator* deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IMMDeviceEnumerator), (LPVOID*)& deviceEnumerator);
	IMMDevice* defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume* endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
		CLSCTX_INPROC_SERVER, NULL, (LPVOID*)& endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	// -------------------------
	float currentVolume = 0;
	endpointVolume->GetMasterVolumeLevel(&currentVolume);
	//printf("Current volume in dB is: %f\n", currentVolume);

	hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
	//CString strCur=L"";
	//strCur.Format(L"%f",currentVolume);
	//AfxMessageBox(strCur);

	// printf("Current volume as a scalar is: %f\n", currentVolume);
	if (bScalar == false)
	{
		hr = endpointVolume->SetMasterVolumeLevel((float)newVolume, NULL);
	}
	else if (bScalar == true)
	{
		hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
	}
	endpointVolume->Release();

	CoUninitialize();

	return FALSE;
}