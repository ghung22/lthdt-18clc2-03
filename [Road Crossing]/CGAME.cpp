﻿#include "CGAME.h"
#include "Constants.h"

#include <fstream>
#include <string>
#include <conio.h>
#include <mmsystem.h>

Window w;
extern void UpdateGameFrame(CGAME* g); //cho biết có hàm này ở bên file khác, để đem vào thread bên dưới ko bị lỗi undefined
extern bool CheckCollision(CGAME* g);
extern bool IS_RUNNING;
bool IS_PAUSED;

CGAME::CGAME() { sound = true; }

void CGAME::reset(bool loss) { initObjects(loss); }
void CGAME::exit(thread& t)
{
	exitGame(t);
	start();
}
void CGAME::lose(int dialog)
{
	p.kill();
	prompt(dialog);
}

void CGAME::start()
{
	PlaySound(0, 0, 0); //mute sound
	settingLoad();
	w.LockWinSize();
	w.HideCursor();

	char lc = 0; // biến lựa chọn menu
	system("cls"); // xóa màn hình
	cout << endl << endl
		<< "\t\t\t\t================ ROAD CROSSING ================" << endl
		<< "\t\t\t\t\t[1] NEW GAME " << endl
		<< "\t\t\t\t\t[2] LOAD GAME " << endl
		<< "\t\t\t\t\t[3] SETTINGS " << endl
		<< "\t\t\t\t\t[0] EXIT " << endl
		<< "\t\t\t\t===============================================" << endl;
	cout << "Choose your option" << endl << endl;

	// Nhập lựa chọn
	while (lc != '0')
	{
		if (_kbhit())
		{
			lc = _getch();
			switch (lc)
			{
			case '1': game(); break;
			case '2': game(true); break;
			case '3': setting(); break;
			}
		}
	}
}
void CGAME::game(bool load)
{
	PlaySound(0, 0, 0); //mute sound
	w.HideCursor();

	initObjects();
	if (load)
		prompt(LOADGAME_DIALOG);
	//Chạy hàm song song với main()
	thread gThread(UpdateGameFrame, this);

	char pressed;
	IS_RUNNING = true;
	IS_PAUSED = false;

	while (IS_RUNNING)
	{
		if (_kbhit())
		{
			pressed = toupper(_getch());
			if (!p.isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
				switch (pressed)
				{
				case VK_ESCAPE:	//Phím ESC
					if (!IS_PAUSED)
						goto EXIT;
					else
						goto NOTPAUSED;
				case 'P':
					pause();
					prompt(PAUSED_DIALOG);
					break;
				case 'L':
					if (IS_PAUSED)
						prompt(LOADGAME_DIALOG);
					else
						goto NOTPAUSED;
					break;
				case 'S':
					if (IS_PAUSED)
						prompt(SAVEGAME_DIALOG);
					else
						goto NOTPAUSED;
					break;
				default:
					NOTPAUSED:
					resume();
					p.Move(pressed); //Các phím di chuyển người chơi
					break;
				}
			else	//Khi đã die hoặc mới bắt đầu game, ấn Y thì bắt đầu chơi
			{
				if (pressed == 'Y')
					start();
				else
					exit(gThread);
			}
		}
	}
EXIT:
	exit(gThread);
}
void CGAME::setting()
{
	w.HideCursor();
	
	char o = 0;

	REFRESH:
	system("cls");
	cout
		<< "================ SETTINGS ================" << endl
		<< "[1] Music and Sounds: " << sound << endl
		<< "[2] Player head: " << p.getIcon(0) << endl
		<< "[3] Restore default settings" << endl
		<< "[0] Quit." << endl
		<< "==========================================" << endl;
	cout << "Choose your option";

	while (o != '0')
	{
		if (_kbhit())
		{
			o = _getch();
			switch (o)
			{
			case '1': sound = !sound; break;
			case '2':
				p.setIcon(p.getIcon() + 1);
				break;
			case '3':
				sound = true;
				p.setIcon(0);
				break;
			}
			goto REFRESH;
		}
	}

	settingSave();
	if (!sound)
		PlaySound(0, 0, 0); //mute sound

	start();
}
void CGAME::settingLoad()
{
	ifstream fin("setting.ini");
	if (fin.fail())
	{
		settingSave();
		return;
	}
	string temp;
	while (!fin.eof())
	{
		getline(fin, temp);
		if (temp.length() > 0)
		{
			char c = temp[temp.length() - 1];
			if (temp.find("bSound") != string::npos)
				sound = c - '0';
			else if (temp.find("cPlayerCharacter") != string::npos)
				p.setIcon(c);
		}
	}
	fin.close();
}
void CGAME::settingSave()
{
	ofstream fout("setting.ini");
	if (fout.fail())
	{
		cout << "Failed to save settings to file" << endl;
		return;
	}
	fout << "[Setting]" << endl
		<< "bSound=" << sound << endl
		<< "cPlayerCharacter=" << p.getIcon() << endl;
	fout.close();
}
void CGAME::prompt(int dialog)
{
	ClearInfoBox();

	/*
		- 0: Time's up
		- 1: Player die
	*/
	switch (dialog)
	{
		//Người chơi thua. Phần xử lí ấn Y ở bên hàm CGAME::game()
	case 0:
		cout << "Time is up. You lose.";
		break;
	case 1:
		cout << "The player is dead. You lose.";
		break;

		//Load và Save game
	case 2:
		cout << "Enter savefile name to load";
		break;
	case 3:
		cout << "Enter savefile name to save";
		break;

		//Pause Menu
	case 4:
		cout << "Game paused. Press L or S to load or save.";
		break;
	default: break;
	}

	w.GotoXY(32, 3);
	if (dialog == 0 || dialog == 1)
		cout << "Press Y to play again.";
	else if (dialog == 2 || dialog == 3)
	{
		cout << "  > ";
		string file;
		getline(cin, file);
		file = "Data\\" + file + ".sav";
		if (dialog == 2)
			load(file);
		else
			save(file);
		prompt(PAUSED_DIALOG);
	}
}

void CGAME::load(string f)
{
	w.GotoXY(32, 4);
	ifstream fin(f, ios::binary);
	if (fin.fail())
	{
		cout << "Error loading from " << f;
		return;
	}

	//Kiểu dữ liệu lưu trong file thuộc kiểu char[2]
	char temp[2];
	fin.read(temp, 2);
	fin.close();

	string val = temp;
	p.setLevel(stoi(val) - 1);
	initObjects(false);
}
void CGAME::save(string f)
{
	w.GotoXY(32, 4);
	ofstream fout(f, ios::binary);
	if (fout.fail())
	{
		cout << "Error saving to " << f;
		return;
	}

	//Chuyển kiểu dữ liệu sang char[2] do lưu số unsigned bị lỗi :)
	string val = to_string(p.getLevel());
	char temp[2];
	strcpy_s(temp, 2, val.c_str());

	fout.write(temp, 2);
	fout.close();
	cout << "Saved to " << f;
}
void CGAME::pause() { IS_PAUSED = true; }
void CGAME::resume() { UpdateGameInfo(); IS_PAUSED = false; }

void CGAME::ClearInfoBox()
{
	w.GotoXY(32, 2);
	cout << "                                                     ";
	w.GotoXY(32, 3);
	cout << "                                                     ";
	w.GotoXY(32, 2);
}
void CGAME::UpdateGameInfo()
{
	w.GotoXY(32, 4); //Xoá thông báo lỗi (nếu có)
	cout << "                                                     ";

	ClearInfoBox();
	w.GotoXY(3, 2);
	cout << "Level: " << p.getLevel();
	w.GotoXY(32, 2);
	cout << "Press WASD to move";
	w.GotoXY(32, 3);
	cout << "ESC to exit, P to pause";
}

void CGAME::initObjects(bool resetP)
{
	clearObjects(resetP);
	UpdateGameInfo();

	//thêm một object vào làn đường mỗi 2 level
	unsigned level = p.getLevel(),
		add = level / 2;
	short x0 = w.GetConsoleSize().Right / (add + 1), //chia đều các xe trên làn
		x1 = rand() % 20,
		x2 = rand() % 20, 
		x3 = rand() % 20, 
		x4 = rand() % 20;
	for (unsigned i = 0; i <= add; i++)
	{
		CTruck t(x1);
		CCar c(x2);
		CDino d(x3);
		CBird b(x4);
		t.draw();
		c.draw();
		d.draw();
		b.draw();
		truck.push_back(t);
		car.push_back(c);
		dino.push_back(d);
		bird.push_back(b);
		x1 += x0; x2 += x0; x3 += x0; x4 += x0;
	}
}
void CGAME::clearObjects(bool resetP)
{
	w.SplitLanes();
	for (unsigned i = 0; i < truck.size(); i++)
		truck.pop_back();
	for (unsigned i = 0; i < car.size(); i++)
		car.pop_back();
	for (unsigned i = 0; i < dino.size(); i++)
		dino.pop_back();
	for (unsigned i = 0; i < bird.size(); i++)
		bird.pop_back();

	unsigned level = p.getLevel();

	p.erase();
	p.reset();
	if (!resetP) //Nếu người chơi tahwsng trước đó, thay đổi lại level
		if (level < MAX_LEVEL)
			p.setLevel(level + 1);
		else
			p.setLevel(MAX_LEVEL);
	p.draw();
}

bool CGAME::getSound() { return sound; }